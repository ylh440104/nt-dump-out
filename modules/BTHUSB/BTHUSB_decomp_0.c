
===== Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>_> @ 140001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapSz<unsigned short> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapSz<unsigned short>
   const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapSz<unsigned_short> *param_6)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
  _tlgWrapperByVal<8> *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = param_6->Psz;
  if (local_28 == (wchar_t *)0x0) {
    local_28 = L"";
    local_20 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_28[lVar2] != L'\0');
    local_20 = (int)lVar2 * 2 + 2;
  }
  local_38 = param_5;
  local_1c = 0;
  local_30 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140014000,param_2,0,0,4,local_58);
  return lVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1400010b8 =====

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



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_> @ 14000115c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<2>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<2>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByRef<16> const &
   __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<2> const &
   __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<2> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<2> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByRef<16> *param_6,_tlgWrapperByVal<2> *param_7,
          _tlgWrapperByVal<2> *param_8,_tlgWrapperByVal<2> *param_9,_tlgWrapperByVal<2> *param_10,
          _tlgWrapperByVal<4> *param_11,_tlgWrapperByVal<2> *param_12,_tlgWrapperByVal<4> *param_13,
          _tlgWrapperByVal<4> *param_14,_tlgWrapperByVal<4> *param_15,_tlgWrapperByVal<4> *param_16,
          _tlgWrapperByVal<4> *param_17,_tlgWrapperByVal<4> *param_18,_tlgWrapperByVal<2> *param_19,
          _tlgWrapperByVal<4> *param_20,_tlgWrapperByVal<4> *param_21)

{
  long lVar1;
  undefined1 auStackY_178 [32];
  undefined8 local_148 [4];
  _tlgWrapperByVal<8> *local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  _tlgWrapperByVal<2> *local_108;
  undefined8 local_100;
  _tlgWrapperByVal<2> *local_f8;
  undefined8 local_f0;
  _tlgWrapperByVal<2> *local_e8;
  undefined8 local_e0;
  _tlgWrapperByVal<2> *local_d8;
  undefined8 local_d0;
  _tlgWrapperByVal<4> *local_c8;
  undefined8 local_c0;
  _tlgWrapperByVal<2> *local_b8;
  undefined8 local_b0;
  _tlgWrapperByVal<4> *local_a8;
  undefined8 local_a0;
  _tlgWrapperByVal<4> *local_98;
  undefined8 local_90;
  _tlgWrapperByVal<4> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<4> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<2> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_178;
  local_28 = param_21;
  local_38 = param_20;
  local_48 = param_19;
  local_58 = param_18;
  local_68 = param_17;
  local_78 = param_16;
  local_88 = param_15;
  local_98 = param_14;
  local_a8 = param_13;
  local_b8 = param_12;
  local_c8 = param_11;
  local_d8 = param_10;
  local_e8 = param_9;
  local_f8 = param_8;
  local_108 = param_7;
  local_20 = 4;
  local_30 = 4;
  local_40 = 2;
  local_118 = *(undefined8 *)param_6;
  local_128 = param_5;
  local_50 = 4;
  local_60 = 4;
  local_70 = 4;
  local_80 = 4;
  local_90 = 4;
  local_a0 = 4;
  local_b0 = 2;
  local_c0 = 4;
  local_d0 = 2;
  local_e0 = 2;
  local_f0 = 2;
  local_100 = 2;
  local_110 = 0x10;
  local_120 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140014000,param_2,0,0,0x13,local_148);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>_> @ 140001304 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<2>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<2>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID
   const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct
   _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct
   _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByRef<16> *param_6,_tlgWrapperByVal<2> *param_7,
          _tlgWrapperByVal<2> *param_8,_tlgWrapperByVal<2> *param_9,_tlgWrapperByVal<2> *param_10,
          _tlgWrapperByVal<4> *param_11,_tlgWrapperByVal<2> *param_12,_tlgWrapperByVal<4> *param_13,
          _tlgWrapperByVal<4> *param_14,_tlgWrapperByVal<4> *param_15,_tlgWrapperByVal<4> *param_16,
          _tlgWrapperByVal<4> *param_17,_tlgWrapperByVal<4> *param_18,_tlgWrapperByVal<2> *param_19,
          _tlgWrapperByVal<4> *param_20,_tlgWrapperByVal<1> *param_21,_tlgWrapperByVal<4> *param_22)

{
  long lVar1;
  undefined1 auStackY_188 [32];
  undefined8 local_158 [4];
  _tlgWrapperByVal<8> *local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  _tlgWrapperByVal<2> *local_118;
  undefined8 local_110;
  _tlgWrapperByVal<2> *local_108;
  undefined8 local_100;
  _tlgWrapperByVal<2> *local_f8;
  undefined8 local_f0;
  _tlgWrapperByVal<2> *local_e8;
  undefined8 local_e0;
  _tlgWrapperByVal<4> *local_d8;
  undefined8 local_d0;
  _tlgWrapperByVal<2> *local_c8;
  undefined8 local_c0;
  _tlgWrapperByVal<4> *local_b8;
  undefined8 local_b0;
  _tlgWrapperByVal<4> *local_a8;
  undefined8 local_a0;
  _tlgWrapperByVal<4> *local_98;
  undefined8 local_90;
  _tlgWrapperByVal<4> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<4> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<2> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<1> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_188;
  local_28 = param_22;
  local_38 = param_21;
  local_48 = param_20;
  local_58 = param_19;
  local_68 = param_18;
  local_78 = param_17;
  local_88 = param_16;
  local_98 = param_15;
  local_a8 = param_14;
  local_b8 = param_13;
  local_c8 = param_12;
  local_d8 = param_11;
  local_e8 = param_10;
  local_f8 = param_9;
  local_108 = param_8;
  local_118 = param_7;
  local_20 = 4;
  local_30 = 1;
  local_40 = 4;
  local_128 = *(undefined8 *)param_6;
  local_138 = param_5;
  local_50 = 2;
  local_60 = 4;
  local_70 = 4;
  local_80 = 4;
  local_90 = 4;
  local_a0 = 4;
  local_b0 = 4;
  local_c0 = 2;
  local_d0 = 4;
  local_e0 = 2;
  local_f0 = 2;
  local_100 = 2;
  local_110 = 2;
  local_120 = 0x10;
  local_130 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140014000,param_2,0,0,0x14,local_158);
  return lVar1;
}



===== __report_gsfailure @ 1400014d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400014dd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400014dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== ~lambda_call<<lambda_ab0b21a5b1f80815114ac5907429201e>_> @ 1400014f0 =====

void wil::details::lambda_call<<lambda_ab0b21a5b1f80815114ac5907429201e>_>::
     ~lambda_call<<lambda_ab0b21a5b1f80815114ac5907429201e>_>(undefined8 *param_1)

{
  if ((*(char *)(param_1 + 1) != '\0') && (*(undefined1 *)(param_1 + 1) = 0, *(int *)*param_1 < 0))
  {
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
  return;
}



===== BthUsb_EtwEnableCallback @ 140001560 =====

/* void __cdecl BthUsb_EtwEnableCallback(struct _GUID const * __ptr64,unsigned long,unsigned
   char,unsigned __int64,unsigned __int64,struct _EVENT_FILTER_DESCRIPTOR * __ptr64,void * __ptr64)
    */

void __cdecl
BthUsb_EtwEnableCallback
          (_GUID *param_1,ulong param_2,uchar param_3,__uint64 param_4,__uint64 param_5,
          _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  undefined1 uVar1;
  uchar uVar2;
  _LOCKED_LIST *p_Var3;
  
  if (param_2 != 0) {
    uVar1 = KeAcquireSpinLockRaiseToDpc();
    for (p_Var3 = (_LOCKED_LIST *)g_PdoLockedList.ListHead.Flink; p_Var3 != &g_PdoLockedList;
        p_Var3 = (_LOCKED_LIST *)(p_Var3->ListHead).Flink) {
      uVar2 = BthUsb_ProcessPdoEtwRundown((void *)0x0,&p_Var3->ListHead);
      if (uVar2 == '\0') break;
    }
    KeReleaseSpinLock(g_PdoLockedList.ListLock,uVar1);
  }
  return;
}



===== BthUsb_ProcessPdoEtwRundown @ 1400015dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl BthUsb_ProcessPdoEtwRundown(void * __ptr64,struct _LIST_ENTRY * __ptr64) */

uchar __cdecl BthUsb_ProcessPdoEtwRundown(void *param_1,_LIST_ENTRY *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined1 auStack_98 [32];
  undefined2 **local_78;
  undefined2 local_68;
  undefined2 local_66;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined4 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  uint *puStack_38;
  undefined8 local_30;
  _LIST_ENTRY *p_Stack_28;
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  bVar1 = *(byte *)((longlong)&param_2[1].Flink + 1);
  bVar2 = *(byte *)((longlong)&param_2[1].Flink + 2);
  uVar4 = 0;
  local_68 = *(undefined2 *)&(param_2[-0x42].Flink)->Blink;
  local_66 = *(undefined2 *)((longlong)&(param_2[-0x42].Flink)->Blink + 2);
  bVar3 = *(byte *)((longlong)&param_2[1].Flink + 3);
  local_48 = &local_68;
  local_40 = 4;
  local_60 = (uint)*(byte *)&param_2[1].Flink;
  local_5c = (uint)bVar1;
  local_58 = (uint)bVar2;
  local_54 = (uint)bVar3;
  if ((((*(byte *)&param_2[1].Flink == 0) || (bVar1 == 0)) || (bVar2 == 0)) ||
     (local_50 = 1, bVar3 != 0)) {
    local_50 = 0;
  }
  puStack_38 = &local_60;
  local_30 = 0x14;
  p_Stack_28 = (_LIST_ENTRY *)0x0;
  if ((param_2[-0x46].Flink != (_LIST_ENTRY *)0x0) && (*(ushort *)&param_2[-0x47].Blink != 0)) {
    uVar4 = *(ushort *)&param_2[-0x47].Blink + 2;
    p_Stack_28 = param_2[-0x46].Flink;
  }
  local_78 = &local_48;
  local_20 = (ulonglong)uVar4;
  EtwWrite(g_EtwRegHandle,&BTHUSB_ETW_EVENT_HC_INFORMATION,0,3);
  return '\x01';
}



===== g_BthUsb_GetUsbCtrlString @ 140001704 =====

/* unsigned short * __ptr64 __cdecl g_BthUsb_GetUsbCtrlString(unsigned char) */

ushort * __cdecl g_BthUsb_GetUsbCtrlString(uchar param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 == '\0') {
    return (ushort *)L"BTH_USB_UHCI";
  }
  if (param_1 == '\x10') {
    return (ushort *)L"BTH_USB_OHCI";
  }
  pwVar1 = L"BTH_USB_EHCI";
  if (param_1 != ' ') {
    pwVar1 = L"unknown USB_CTRL_TYPE";
  }
  return (ushort *)pwVar1;
}



===== WPP_RECORDER_AND_TRACE_SF_ @ 14000173c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,0);
  }
  WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_d @ 1400017ac =====

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



===== WPP_RECORDER_AND_TRACE_SF_q @ 14000184c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_q
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,0);
  }
  WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qD @ 1400018ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,4,0);
  }
  WppAutoLogTrace(param_4,4,param_6,param_8,param_7,&param_9,8,&param_10,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400019c0 =====

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



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 140001a1c =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 140001a28 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001b80 =====

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



===== EvtObjectContextCleanupThunk @ 140001c10 =====

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



===== FromWdfDevice @ 140001c34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class Fdo & __ptr64 __cdecl Fdo::FromWdfDevice(struct WDFDEVICE__ * __ptr64) */

Fdo * __cdecl Fdo::FromWdfDevice(WDFDEVICE__ *param_1)

{
  Fdo *pFVar1;
  
  pFVar1 = (Fdo *)(**(code **)(WdfFunctions_01031 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_Fdo_TYPE_INFO_140014060);
  return pFVar1;
}



===== GetRecorderLog @ 140001c68 =====

/* public: struct RECORDER_LOG__ * __ptr64 __cdecl Fdo::GetRecorderLog(void)const __ptr64 */

RECORDER_LOG__ * __thiscall Fdo::GetRecorderLog(Fdo *this)

{
  return *(RECORDER_LOG__ **)(this + 8);
}



===== WPP_RECORDER_AND_TRACE_SF_qLL @ 140001c74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,param_7,&param_9,8,
               &param_10,4,&param_11,4,0);
  }
  WppAutoLogTrace(param_4,4,1,&WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,param_7,&param_9,8,
                  &param_10,4,&param_11,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qd @ 140001d58 =====

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



===== make_unique<_URB,0> @ 140001e24 =====

/* class utl::unique_ptr<struct _URB,struct utl::default_delete<struct _URB> > __cdecl
   utl::make_unique<struct _URB,0>(void) */

void __cdecl utl::make_unique<_URB,0>(void)

{
  void *_Dst;
  undefined8 *in_RCX;
  
  _Dst = (void *)ExAllocatePool2(0x40,0x98,0x42425355);
  if (_Dst == (void *)0x0) {
    _Dst = (void *)0x0;
  }
  else {
    memset(_Dst,0,0x98);
  }
  *in_RCX = _Dst;
  return;
}



===== ~vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_> @ 140001e80 =====

/* public: __cdecl utl::vector<class utl::unique_ptr<struct _URB,struct utl::default_delete<struct
   _URB> >,class utl::allocator<class utl::unique_ptr<struct _URB,struct utl::default_delete<struct
   _URB> > > >::~vector<class utl::unique_ptr<struct _URB,struct utl::default_delete<struct _URB>
   >,class utl::allocator<class utl::unique_ptr<struct _URB,struct utl::default_delete<struct _URB>
   > > >(void) __ptr64 */

void __thiscall
utl::
vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
::
~vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
          (vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
           *this)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)this;
  if (lVar1 != -1) {
    lVar2 = *(longlong *)(this + 8);
    *(longlong *)(this + 8) = lVar1;
    lVar2 = lVar2 - lVar1 >> 3;
    while (lVar2 != 0) {
      lVar2 = lVar2 + -1;
      if (*(longlong *)(lVar1 + lVar2 * 8) != 0) {
        ExFreePool();
      }
    }
    if (*(longlong *)this != 0) {
      ExFreePool();
    }
  }
  return;
}



===== EvtIoQueueIoDefault @ 140001ef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl ReceiveQueue::EvtIoQueueIoDefault(struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall ReceiveQueue::EvtIoQueueIoDefault(ReceiveQueue *this,WDFREQUEST__ *param_1)

{
  _URB *p_Var1;
  char cVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  char cVar5;
  code *pcVar6;
  undefined1 auStackY_108 [32];
  _URB *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 local_78 [8];
  _URB *local_70;
  undefined4 local_60;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_108;
  cVar5 = '\0';
  local_a8 = (_URB *)0x0;
  local_a0 = 0;
  (*DAT_1400142a8)(BthDriverGlobals,param_1,&local_a8,&local_a0);
  local_98 = local_a8;
  p_Var1 = local_98;
  uStack_90 = local_a0;
  uVar4 = uStack_90;
  local_98._0_4_ = SUB84(local_a8,0);
  local_98._4_4_ = (undefined4)((ulonglong)local_a8 >> 0x20);
  uStack_90._0_4_ = (undefined4)local_a0;
  uStack_90._4_4_ = (undefined4)((ulonglong)local_a0 >> 0x20);
  local_88 = (undefined4)local_98;
  uStack_84 = local_98._4_4_;
  uStack_80 = (undefined4)uStack_90;
  uStack_7c = uStack_90._4_4_;
  local_98 = p_Var1;
  uStack_90 = uVar4;
  TryGetFormattedUrbFromPool(this,&local_98,&local_88);
  p_Var1 = local_98;
  if (local_98 == (_URB *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    memset(local_78,0,0x48);
    local_70 = p_Var1;
    local_60 = 0x220003;
    local_78[0] = 0xf;
    (**(code **)(WdfFunctions_01031 + 0x7e0))(WdfDriverGlobals,param_1,local_78);
    pcVar6 = EvtRequestCompletionRoutineThunk;
    (**(code **)(WdfFunctions_01031 + 0x820))
              (WdfDriverGlobals,param_1,EvtRequestCompletionRoutineThunk,p_Var1);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
       (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar2 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_qLq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,pcVar6,
               *(undefined8 *)(*(longlong *)(this + 8) + 8));
    uVar4 = (**(code **)(WdfFunctions_01031 + 0x150))(WdfDriverGlobals,**(undefined8 **)(this + 8));
    cVar2 = (**(code **)(WdfFunctions_01031 + 0x7e8))(WdfDriverGlobals,param_1,uVar4,0);
    if (cVar2 != '\0') {
      return;
    }
    uVar3 = (**(code **)(WdfFunctions_01031 + 0x7f0))(WdfDriverGlobals,param_1);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar5 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,WPP_GLOBAL_Control,
               (*(undefined8 **)(this + 8))[1],2,1,0xe,
               &WPP_86e0affdec483798a987f478d619ae67_Traceguids,(char)**(undefined8 **)(this + 8),
               (char)uVar3);
    ReturnUrbToPool(this,p_Var1);
  }
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,uVar3);
  return;
}



===== EvtIoQueueIoDefaultThunk @ 140002160 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl ReceiveQueue::EvtIoQueueIoDefaultThunk(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl ReceiveQueue::EvtIoQueueIoDefaultThunk(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  ReceiveQueue *this;
  
  this = (ReceiveQueue *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_ReceiveQueue_TYPE_INFO_140014088);
  EvtIoQueueIoDefault(this,param_2);
  return;
}



===== EvtObjectContextCleanupThunk @ 1400021b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFQUEUE__ * __ptr64,class
   ReceiveQueue,1>::EvtObjectContextCleanupThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<WDFQUEUE__*___ptr64,ReceiveQueue,1>::EvtObjectContextCleanupThunk
          (void *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01031 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ReceiveQueue_TYPE_INFO_140014088);
  if (lVar1 != 0) {
    utl::
    vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
    ::
    ~vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
              ((vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
                *)(lVar1 + 0x30));
  }
  return;
}



===== EvtRequestCompletionRoutine @ 1400021f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl ReceiveQueue::EvtRequestCompletionRoutine(struct WDFREQUEST__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void * __ptr64) __ptr64 */

void __thiscall
ReceiveQueue::EvtRequestCompletionRoutine
          (ReceiveQueue *this,WDFREQUEST__ *param_1,_WDF_REQUEST_COMPLETION_PARAMS *param_2,
          void *param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined1 in_stack_ffffffffffffff88;
  undefined1 uVar7;
  undefined7 in_stack_ffffffffffffff89;
  undefined4 in_stack_ffffffffffffff90;
  undefined4 in_stack_ffffffffffffff94;
  undefined2 uVar8;
  undefined8 in_stack_ffffffffffffffa0;
  undefined1 uVar9;
  
  iVar5 = (param_2->IoStatus).field0_0x0.Status;
  iVar1 = *(int *)((longlong)param_3 + 4);
  iVar2 = *(int *)((longlong)param_3 + 0x24);
  if (iVar5 == -0x3ffffee0) {
    cVar3 = (**(code **)(WdfFunctions_01031 + 0x808))(WdfDriverGlobals);
    if (cVar3 == '\0') {
LAB_1400022a8:
      cVar3 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar3 = '\0';
      }
      puVar6 = *(undefined8 **)(this + 8);
      uVar9 = (undefined1)*puVar6;
      uVar8 = 0x10;
      uVar7 = 2;
    }
    else {
      cVar3 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
      {
        cVar3 = '\0';
      }
      puVar6 = *(undefined8 **)(this + 8);
      uVar9 = (undefined1)*puVar6;
      uVar8 = 0xf;
      uVar7 = 4;
    }
    WPP_RECORDER_AND_TRACE_SF_qqdDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,param_2,puVar6[1],uVar7,
               CONCAT44(in_stack_ffffffffffffff94,in_stack_ffffffffffffff90),uVar8,
               in_stack_ffffffffffffffa0,uVar9,(char)param_1,(char)iVar5,(char)iVar1,(char)iVar2);
  }
  else {
    cVar3 = '\0';
    if (iVar5 < 0) goto LAB_1400022a8;
    if (iVar1 != 0) {
      cVar3 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar3 = '\0';
      }
      uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      WPP_RECORDER_AND_TRACE_SF_qqDD
                (uVar4,cVar3,param_2,*(undefined8 *)(*(longlong *)(this + 8) + 8));
      MicrosoftTelemetryAssertTriggeredArgsMsgKM(uVar4,iVar1,iVar2);
      ReturnUrbToPool(this,param_3);
      iVar5 = -0x3fffffff;
      goto LAB_140002470;
    }
    if (iVar2 == 0) {
      cVar3 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar3 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,param_2,
                 *(undefined8 *)(*(longlong *)(this + 8) + 8));
      (*DAT_1400142b0)(BthDriverGlobals,param_1);
    }
    else {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        cVar3 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_qqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,param_2,
                 (*(undefined8 **)(this + 8))[1],
                 CONCAT71(in_stack_ffffffffffffff89,in_stack_ffffffffffffff88),1,0x13,
                 &WPP_86e0affdec483798a987f478d619ae67_Traceguids,(char)**(undefined8 **)(this + 8),
                 (char)param_1,(char)iVar2);
      if (*(longlong *)((longlong)param_3 + 0x18) == *(longlong *)(this + 0x18)) {
        uVar4 = 0;
      }
      else {
        if (*(longlong *)((longlong)param_3 + 0x18) != *(longlong *)(this + 0x20)) {
          MicrosoftTelemetryAssertTriggeredMsgKM("Unknown pipe handle in URB.");
        }
        uVar4 = 1;
      }
      (*DAT_140014298)(BthDriverGlobals,param_1,uVar4);
      (*DAT_1400142a0)(BthDriverGlobals,param_1,0,*(undefined4 *)((longlong)param_3 + 0x24));
    }
  }
  ReturnUrbToPool(this,param_3);
LAB_140002470:
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,iVar5);
  return;
}



===== EvtRequestCompletionRoutineThunk @ 1400024b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl ReceiveQueue::EvtRequestCompletionRoutineThunk(struct WDFREQUEST__ *
   __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void *
   __ptr64) */

void __cdecl
ReceiveQueue::EvtRequestCompletionRoutineThunk
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  undefined8 uVar1;
  ReceiveQueue *this;
  
  uVar1 = (**(code **)(WdfFunctions_01031 + 0x8d0))(WdfDriverGlobals,param_1);
  this = (ReceiveQueue *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_ReceiveQueue_TYPE_INFO_140014088);
  EvtRequestCompletionRoutine(this,param_1,param_3,param_4);
  return;
}



===== GetContextFromObject @ 140002534 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static class ReceiveQueue * __ptr64 __cdecl ReceiveQueue::GetContextFromObject(struct
   WDFQUEUE__ * __ptr64) */

ReceiveQueue * __cdecl ReceiveQueue::GetContextFromObject(WDFQUEUE__ *param_1)

{
  ReceiveQueue *pRVar1;
  
  pRVar1 = (ReceiveQueue *)
           (**(code **)(WdfFunctions_01031 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_ReceiveQueue_TYPE_INFO_140014088);
  return pRVar1;
}



===== GetDesiredBufferLength @ 140002568 =====

/* public: unsigned __int64 __cdecl ReceiveQueue::GetDesiredBufferLength(void)const __ptr64 */

__uint64 __thiscall ReceiveQueue::GetDesiredBufferLength(ReceiveQueue *this)

{
  uint uVar1;
  
  uVar1 = 0x101;
  if (0x101 < *(uint *)(this + 0x10)) {
    uVar1 = *(uint *)(this + 0x10);
  }
  return (ulonglong)uVar1;
}



===== GetDesiredNumberOfPendingPackets @ 140002580 =====

/* public: unsigned int __cdecl ReceiveQueue::GetDesiredNumberOfPendingPackets(void)const __ptr64 */

uint __thiscall ReceiveQueue::GetDesiredNumberOfPendingPackets(ReceiveQueue *this)

{
  return 6;
}



===== Release @ 140002590 =====

/* public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64) */

void __cdecl wil::details::kspin_lock_saved_irql::Release(kspin_lock_saved_irql *param_1)

{
  KeReleaseSpinLock(param_1->spinLock,param_1->savedIrql);
  return;
}



===== ReturnUrbToPool @ 1400025b4 =====

/* private: void __cdecl ReceiveQueue::ReturnUrbToPool(struct _URB * __ptr64) __ptr64 */

void __thiscall ReceiveQueue::ReturnUrbToPool(ReceiveQueue *this,_URB *param_1)

{
  ReceiveQueue *pRVar1;
  void *pvVar2;
  undefined8 uVar3;
  uchar uVar4;
  bool bVar5;
  char cVar6;
  undefined8 in_R8;
  _URB *local_res8;
  kspin_lock_saved_irql local_18;
  
  pRVar1 = this + 0x28;
  uVar4 = KeAcquireSpinLockRaiseToDpc(pRVar1);
  uVar3 = local_18._8_8_;
  local_18.savedIrql = uVar4;
  local_18._13_2_ = SUB82(uVar3,5);
  local_18._15_1_ = SUB81(uVar3,7);
  pvVar2 = (param_1->field0_0x0).UrbSelectInterface.ConfigurationHandle;
  local_res8 = param_1;
  local_18.spinLock = (ulong64 *)pRVar1;
  if (pvVar2 == *(void **)(this + 0x18)) {
    if (*(int *)(this + 0x48) == 0) {
      MicrosoftTelemetryAssertTriggeredMsgKM("Pending interrupt transfer count underrun.");
    }
    else {
      *(int *)(this + 0x48) = *(int *)(this + 0x48) + -1;
    }
  }
  else {
    if (pvVar2 != *(void **)(this + 0x20)) {
      MicrosoftTelemetryAssertTriggeredMsgKM("Unknown pipe handle in URB.");
    }
    if (*(int *)(this + 0x4c) == 0) {
      MicrosoftTelemetryAssertTriggeredMsgKM("Pending bulk transfer count underrun.");
    }
    else {
      *(int *)(this + 0x4c) = *(int *)(this + 0x4c) + -1;
    }
  }
  bVar5 = utl::
          vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
          ::push_back((vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
                       *)(this + 0x30),(unique_ptr<_URB,utl::default_delete<_URB>_> *)&local_res8);
  if (!bVar5) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,in_R8,
               (*(undefined8 **)(this + 8))[1],2,1,0x16,
               &WPP_86e0affdec483798a987f478d619ae67_Traceguids,(char)**(undefined8 **)(this + 8));
    MicrosoftTelemetryAssertTriggeredMsgKM("Failed to return URB to pool.");
  }
  if (local_res8 != (_URB *)0x0) {
    ExFreePool();
  }
  if (pRVar1 != (ReceiveQueue *)0x0) {
    wil::details::kspin_lock_saved_irql::Release(&local_18);
  }
  return;
}



===== TryGetFormattedUrbFromPool @ 140002710 =====

/* private: struct utl::pair<struct _URB * __ptr64,enum _BTH_RECEIVE_PACKET_TYPE> __cdecl
   ReceiveQueue::TryGetFormattedUrbFromPool(class utl::span<enum utl::byte,-1>) __ptr64 */

undefined8 * __thiscall
ReceiveQueue::TryGetFormattedUrbFromPool(ReceiveQueue *this,undefined8 *param_2,undefined8 *param_3)

{
  ReceiveQueue *pRVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *_Dst;
  uchar uVar4;
  char cVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  kspin_lock_saved_irql local_38;
  
  pRVar1 = this + 0x28;
  puVar6 = param_3;
  uVar4 = KeAcquireSpinLockRaiseToDpc(pRVar1);
  uVar7 = local_38._8_8_;
  local_38.savedIrql = uVar4;
  local_38._13_2_ = SUB82(uVar7,5);
  local_38._15_1_ = SUB81(uVar7,7);
  local_38.spinLock = (ulong64 *)pRVar1;
  if (*(longlong *)(this + 0x30) == *(longlong *)(this + 0x38)) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
       (puVar6 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar6 >> 8),1),
       (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      puVar6 = (undefined8 *)((ulonglong)puVar6 & 0xffffffffffffff00);
    }
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)puVar6,puVar6,
               (*(undefined8 **)(this + 8))[1],2,1,0x14,
               &WPP_86e0affdec483798a987f478d619ae67_Traceguids,(char)**(undefined8 **)(this + 8));
    MicrosoftTelemetryAssertTriggeredMsgKM
              ("Count of URBs and pending receive packets don\'t match.");
  }
  else {
    uVar2 = *(uint *)(this + 0x48);
    uVar3 = *(uint *)(this + 0x4c);
    cVar5 = '\x01';
    if (uVar3 < uVar2) {
      uVar7 = *(undefined8 *)(this + 0x20);
      uVar8 = *(uint *)(this + 0x10);
      *(uint *)(this + 0x4c) = uVar3 + 1;
    }
    else {
      uVar7 = *(undefined8 *)(this + 0x18);
      *(uint *)(this + 0x48) = uVar2 + 1;
      uVar8 = 0x101;
    }
    if ((ulonglong)uVar8 <= (ulonglong)param_3[1]) {
      _Dst = *(undefined4 **)(*(longlong *)(this + 0x38) + -8);
      *(undefined8 *)(*(longlong *)(this + 0x38) + -8) = 0;
      *(longlong *)(this + 0x38) = *(longlong *)(this + 0x38) + -8;
      if (**(longlong **)(this + 0x38) != 0) {
        ExFreePool();
      }
      memset(_Dst,0,0x98);
      *_Dst = 0x90080;
      *(undefined8 *)(_Dst + 6) = uVar7;
      _Dst[9] = uVar8;
      uVar7 = *param_3;
      *(undefined8 *)(_Dst + 0xc) = 0;
      *(undefined8 *)(_Dst + 10) = uVar7;
      _Dst[8] = 3;
      *(undefined8 *)(_Dst + 0xe) = 0;
      *param_2 = _Dst;
      *(uint *)(param_2 + 1) = (uint)(uVar3 < uVar2);
      goto LAB_1400028e2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_qDP
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,param_3[1],
               *(undefined8 *)(*(longlong *)(this + 8) + 8));
    MicrosoftTelemetryAssertTriggeredMsgKM("Receive packet buffer smaller than expected.");
  }
  *param_2 = 0;
  *(undefined4 *)(param_2 + 1) = 0;
LAB_1400028e2:
  if (this != (ReceiveQueue *)0xffffffffffffffd8) {
    wil::details::kspin_lock_saved_irql::Release(&local_38);
  }
  return param_2;
}



===== _SetCapacity @ 140002920 =====

/* private: bool __cdecl utl::vector<class utl::unique_ptr<struct _URB,struct
   utl::default_delete<struct _URB> >,class utl::allocator<class utl::unique_ptr<struct _URB,struct
   utl::default_delete<struct _URB> > > >::_SetCapacity(unsigned __int64) __ptr64 */

bool __thiscall
utl::
vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
::_SetCapacity(vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
               *this,__uint64 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  bool bVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong lVar7;
  bool bVar8;
  longlong lVar9;
  longlong local_38;
  longlong lStack_30;
  longlong local_28;
  
  bVar8 = false;
  if (param_1 < 0x2000000000000000) {
    local_38 = ExAllocatePool2(0x40,param_1 * 8,0x42425355);
  }
  else {
    local_38 = 0;
  }
  lVar3 = local_38;
  bVar4 = false;
  if (local_38 != 0) {
    lVar1 = param_1 * 8 + local_38;
    lStack_30 = local_38;
    local_28 = lVar1;
    if (local_38 == -1) goto LAB_140002a42;
    puVar5 = *(undefined8 **)this;
    lVar6 = *(longlong *)(this + 8) - (longlong)puVar5 >> 3;
    if (lVar6 != 0) {
      lVar9 = local_38 - (longlong)puVar5;
      do {
        uVar2 = *puVar5;
        *puVar5 = 0;
        *(undefined8 *)(lVar9 + (longlong)puVar5) = uVar2;
        puVar5 = puVar5 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    lVar9 = *(longlong *)this;
    lVar7 = *(longlong *)(this + 8) - lVar9 >> 3;
    lVar6 = local_38 + lVar7 * 8;
    if (lVar9 != -1) {
      *(longlong *)(this + 8) = lVar9;
      while (lVar7 != 0) {
        lVar7 = lVar7 + -1;
        if (*(longlong *)(lVar9 + lVar7 * 8) != 0) {
          ExFreePool();
        }
      }
      if (*(longlong *)this != 0) {
        ExFreePool();
      }
    }
    *(longlong *)this = lVar3;
    *(longlong *)(this + 8) = lVar6;
    *(longlong *)(this + 0x10) = lVar1;
    bVar4 = true;
  }
  bVar8 = bVar4;
  local_28 = -1;
  lStack_30 = -1;
LAB_140002a42:
  local_38 = lStack_30;
  ~vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
            ((vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
              *)&local_38);
  return bVar8;
}



===== push_back @ 140002a78 =====

/* public: bool __cdecl utl::vector<class utl::unique_ptr<struct _URB,struct
   utl::default_delete<struct _URB> >,class utl::allocator<class utl::unique_ptr<struct _URB,struct
   utl::default_delete<struct _URB> > > >::push_back(class utl::unique_ptr<struct _URB,struct
   utl::default_delete<struct _URB> > && __ptr64) __ptr64 */

bool __thiscall
utl::
vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
::push_back(vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
            *this,unique_ptr<_URB,utl::default_delete<_URB>_> *param_1)

{
  undefined8 uVar1;
  bool bVar2;
  ulonglong uVar3;
  __uint64 _Var4;
  undefined8 *puVar5;
  ulonglong uVar6;
  
  puVar5 = *(undefined8 **)(this + 8);
  if (puVar5 == *(undefined8 **)(this + 0x10)) {
    uVar6 = (longlong)param_1 - *(longlong *)this;
    uVar3 = (longlong)*(undefined8 **)(this + 0x10) - *(longlong *)this >> 3;
    _Var4 = (uVar3 >> 2) * 7 + 8;
    if (0xfffffffffffffff < _Var4) {
      _Var4 = 0xfffffffffffffff;
    }
    if (_Var4 <= uVar3) {
      return false;
    }
    bVar2 = _SetCapacity(this,_Var4);
    if (!bVar2) {
      return false;
    }
    puVar5 = *(undefined8 **)(this + 8);
    if (uVar6 < (ulonglong)((longlong)puVar5 - *(longlong *)this)) {
      param_1 = (unique_ptr<_URB,utl::default_delete<_URB>_> *)(*(longlong *)this + uVar6);
    }
  }
  uVar1 = *(undefined8 *)param_1;
  *(undefined8 *)param_1 = 0;
  *puVar5 = uVar1;
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 8;
  return true;
}



===== WPP_RECORDER_AND_TRACE_SF_qDP @ 140002b2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDP
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_86e0affdec483798a987f478d619ae67_Traceguids,0x15,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_86e0affdec483798a987f478d619ae67_Traceguids,0x15,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLq @ 140002c0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLq
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_stack_00000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,in_stack_00000040,0xd,&uStack0000000000000048,8,&uStack0000000000000050,
               4,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_4,4,1,in_stack_00000040,0xd,&uStack0000000000000048,8,
                  &uStack0000000000000050,4,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qq @ 140002cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qq
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_86e0affdec483798a987f478d619ae67_Traceguids,0x12,
               &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_86e0affdec483798a987f478d619ae67_Traceguids,0x12,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqd @ 140002dac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,8,&param_11,4,0);
  }
  WppAutoLogTrace(param_4,4,param_6,param_8,param_7,&param_9,8,&param_10,8,&param_11,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqDD @ 140002e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqDD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_86e0affdec483798a987f478d619ae67_Traceguids,0x11,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_86e0affdec483798a987f478d619ae67_Traceguids,0x11,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqdDD @ 140002f9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqdDD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_86e0affdec483798a987f478d619ae67_Traceguids,param_7,&param_9,8,
               &param_10,8,&param_11,4,&param_12,4,&param_13,4,0);
  }
  WppAutoLogTrace(param_4,param_5,1,&WPP_86e0affdec483798a987f478d619ae67_Traceguids,param_7,
                  &param_9,8,&param_10,8,&param_11,4,&param_12,4,&param_13,4,0);
  return;
}



===== BthUsb_ScoAddChannel @ 1400030d0 =====

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl BthUsb_ScoAddChannel(struct _BTDEVICE * __ptr64,struct _BTH_SCO_ADD_CHANNEL_ARG *
   __ptr64) */

long __cdecl BthUsb_ScoAddChannel(_BTDEVICE *param_1,_BTH_SCO_ADD_CHANNEL_ARG *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  _tlgProvider_t *p_Var2;
  ulong uVar3;
  _USB_INTERFACE_DESCRIPTOR *p_Var4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined1 auVar8 [4];
  ulong *puVar9;
  ScoUsbAltSetting *pSVar10;
  char cVar11;
  ushort uVar12;
  ulonglong uVar13;
  push_lock *ppVar14;
  uint uVar15;
  char cVar16;
  undefined8 uVar17;
  char *pcVar18;
  undefined *puVar19;
  _GUID *p_Var20;
  _GUID *p_Var21;
  _tlgWrapperByVal<2> _Var22;
  longlong lVar23;
  _SCO_USB_CHANNEL *p_Var24;
  _tlgWrapperByVal<2> _Var25;
  bool bVar26;
  undefined2 local_res8;
  undefined2 local_res10;
  _GUID local_res18;
  undefined8 in_stack_fffffffffffffe38;
  _tlgWrapperByVal<8> *p_Var27;
  undefined7 uVar28;
  undefined8 in_stack_fffffffffffffe40;
  undefined4 uVar31;
  undefined8 uVar29;
  _DEVICE_EXTENSION *p_Var30;
  undefined2 uVar32;
  undefined *puVar33;
  uint local_138;
  undefined1 local_134 [4];
  ulong local_130;
  ulong local_12c;
  ushort local_128;
  ushort local_126;
  ushort local_124 [2];
  ulong local_120;
  ulong local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  uint local_10c;
  uint local_108;
  ulong local_104;
  _USB_INTERFACE_DESCRIPTOR *local_100;
  _DEVICE_EXTENSION *local_f8;
  _DEVICE_EXTENSION *local_f0;
  _SCO_USB_CHANNEL local_e8;
  
  uVar31 = (undefined4)((ulonglong)in_stack_fffffffffffffe40 >> 0x20);
  uVar17 = 0x98;
  memset(&local_e8,0,0x98);
  cVar11 = '\0';
  local_res10 = (ushort)local_res10._1_1_ << 8;
  ppVar14 = (push_lock *)0x0;
  local_res8 = (ushort)local_res8._1_1_ << 8;
  cVar16 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    cVar11 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_qD
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar17,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffe38,4,0x38,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_1,
             (char)*(undefined2 *)(param_2 + 4));
  p_Var1 = param_1->MiniportContext;
  bVar5 = IsAlignDataCapable((longlong)p_Var1);
  cVar11 = '\0';
  if ((param_2[0x28] == (_BTH_SCO_ADD_CHANNEL_ARG)0x0) || (bVar5 == 0)) {
    local_res18.Data1 = (uint)local_res18.Data1._1_3_ << 8;
  }
  else {
    local_res18.Data1 = CONCAT31(local_res18.Data1._1_3_,1);
    *(undefined4 *)(param_2 + 8) = 62000;
    *(undefined4 *)(param_2 + 0xc) = 62000;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    cVar11 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_DDLLLL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,(ulonglong)bVar5,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  pcVar18 = (char *)0x30;
  iVar6 = BthUsb_ScoBasicValidation(param_1,param_2,0x30);
  if (-1 < iVar6) {
    if (*(int *)(param_2 + 0x10) == 0) {
      if (*(longlong *)(param_2 + 0x18) == 0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
           (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar11 = '\0';
        }
        uVar32 = 0x3b;
      }
      else {
        if (*(short *)(param_2 + 4) != -1) {
          ppVar14 = &(p_Var1->Sco).ChannelMutex;
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(ppVar14,0);
          local_res18.Data4._0_2_ = (p_Var1->Sco).NumChannels + 1;
          pcVar18 = (char *)(ulonglong)(ushort)local_res18.Data4._0_2_;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
             (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar11 = '\0';
          }
          uVar17 = CONCAT71((int7)((ulonglong)in_stack_fffffffffffffe38 >> 8),4);
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x3d,
                     &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)local_res18.Data4._0_2_)
          ;
          uVar13 = 0;
          lVar23 = 3;
          do {
            p_Var24 = (p_Var1->Sco).Channel + uVar13;
            if (p_Var24->ConnectionHandle == 0xffff) {
              if (p_Var24 != (_SCO_USB_CHANNEL *)0x0) {
                local_138 = *(uint *)(param_2 + 8);
                pcVar18 = local_134;
                local_134 = *(undefined1 (*) [4])(param_2 + 0xc);
                iVar6 = BthUsb_ScoValidateChnInfo(p_Var1,&local_138,(ulong *)pcVar18);
                cVar11 = '\0';
                if (-1 < iVar6) {
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
                     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    cVar11 = '\x01';
                  }
                  puVar33 = &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids;
                  uVar29 = CONCAT44(uVar31,4);
                  WPP_RECORDER_AND_TRACE_SF_LL
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar17,4,0x3f,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)local_138,
                             local_134[0]);
                  puVar9 = &(p_Var1->Sco).Channel[0].TxBandwidth;
                  uVar15 = 0;
                  do {
                    if (((_SCO_USB_CHANNEL *)(puVar9 + -5))->ConnectionHandle != 0xffff) {
                      uVar7 = puVar9[1];
                      if (puVar9[1] <= uVar15) {
                        uVar7 = uVar15;
                      }
                      uVar15 = *puVar9;
                      if (*puVar9 <= uVar7) {
                        uVar15 = uVar7;
                      }
                    }
                    puVar9 = puVar9 + 0x26;
                    lVar23 = lVar23 + -1;
                  } while (lVar23 != 0);
                  auVar8 = (undefined1  [4])uVar15;
                  if (uVar15 < local_138) {
                    auVar8 = (undefined1  [4])local_138;
                  }
                  if ((uint)auVar8 < (uint)local_134) {
                    auVar8 = local_134;
                  }
                  local_130 = ((uint)auVar8 / 1000) * (uint)(ushort)local_res18.Data4._0_2_ + 1;
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  puVar19 = WPP_GLOBAL_Control;
                  WPP_RECORDER_AND_TRACE_SF_LLLL
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,WPP_GLOBAL_Control,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar17,uVar29,0x40,puVar33,
                             (char)uVar15,(char)local_138,local_134[0],(char)local_130);
                  cVar11 = '\0';
                  if ((char)local_res18.Data1 == '\0') {
                    bVar26 = false;
                    if (uVar15 == 1) {
                      bVar26 = true;
                    }
                  }
                  else {
                    bVar26 = uVar15 != 0;
                  }
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
                     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    cVar11 = '\x01';
                  }
                  local_12c = (ulong)bVar26;
                  WPP_RECORDER_AND_TRACE_SF_lL
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,puVar19,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                  pcVar18 = (char *)&local_res18;
                  local_res18.Data1 = 0;
                  local_100 = BthUsb_ScoFindInterfaceByFrame(p_Var1,local_130,(ulong *)pcVar18);
                  cVar11 = '\0';
                  uVar28 = (undefined7)((ulonglong)uVar17 >> 8);
                  if ((local_100 == (_USB_INTERFACE_DESCRIPTOR *)0x0) || (bVar26 != false)) {
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      cVar11 = '\x01';
                    }
                    p_Var21 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
                    WPP_RECORDER_AND_TRACE_SF_
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,p_Var21,2,4
                               ,0x42,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
                    if (((2 < DAT_140014000) && ((_DAT_140014010 & 0x400000000000) != 0)) &&
                       ((DAT_140014018 & 0x400000000000) == DAT_140014018)) {
                      local_104 = local_130;
                      local_res8._0_1_ = (_tlgWrapperByVal<2>)local_res18.Data4[0];
                      local_res8._1_1_ = local_res18.Data4[1];
                      local_114 = *(uint *)(param_2 + 0xc);
                      local_118 = *(uint *)(param_2 + 8);
                      local_11c = (p_Var1->Sco).MaxFrameSize;
                      local_10c = (uint)local_134;
                      local_110 = local_138;
                      local_120 = (p_Var1->Sco).RealMaxFrameSize;
                      local_res10 = (ushort)((p_Var1->Sco).MaxInterface)->bAlternateSetting;
                      local_res18.Data1 =
                           CONCAT22(local_res18.Data1._2_2_,
                                    (ushort)((p_Var1->Sco).RealMaxInterface)->bAlternateSetting);
                      p_Var2 = (_tlgProvider_t *)p_Var1->DeviceDescriptor;
                      local_res18.Data4._0_2_ =
                           *(ushort *)((longlong)&p_Var2->ProviderMetadataPtr + 2);
                      local_134._0_2_ = *(undefined2 *)&p_Var2->ProviderMetadataPtr;
                      local_138 = CONCAT22(local_138._2_2_,
                                           *(undefined2 *)((longlong)&p_Var2->LevelPlus1 + 2));
                      local_f8 = (_DEVICE_EXTENSION *)0x2000800;
                      local_108 = uVar15;
                      local_f0 = p_Var1;
                      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
                      ::
                      Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
                                (p_Var2,&DAT_140011f40,(_GUID *)pcVar18,p_Var21,
                                 (_tlgWrapperByVal<8> *)&local_f8,(_tlgWrapperByRef<16> *)&local_f0,
                                 (_tlgWrapperByVal<2> *)&local_138,(_tlgWrapperByVal<2> *)local_134,
                                 (_tlgWrapperByVal<2> *)local_res18.Data4,
                                 (_tlgWrapperByVal<2> *)&local_res18,
                                 (_tlgWrapperByVal<4> *)&local_120,
                                 (_tlgWrapperByVal<2> *)&local_res10,
                                 (_tlgWrapperByVal<4> *)&local_11c,(_tlgWrapperByVal<4> *)&local_118
                                 ,(_tlgWrapperByVal<4> *)&local_114,
                                 (_tlgWrapperByVal<4> *)&local_110,(_tlgWrapperByVal<4> *)&local_10c
                                 ,(_tlgWrapperByVal<4> *)&local_108,
                                 (_tlgWrapperByVal<2> *)&local_res8,
                                 (_tlgWrapperByVal<4> *)&local_104,(_tlgWrapperByVal<4> *)&local_12c
                                );
                    }
                    iVar6 = -0x3fffff66;
                    goto LAB_14000401e;
                  }
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
                     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    cVar11 = '\x01';
                  }
                  puVar33 = WPP_GLOBAL_Control;
                  WPP_RECORDER_AND_TRACE_SF_d
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,WPP_GLOBAL_Control,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x43,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
                             local_100->bAlternateSetting);
                  uVar3 = local_res18.Data1;
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  else {
                    cVar11 = '\x01';
                  }
                  p_Var20 = (_GUID *)CONCAT71((int7)((ulonglong)puVar33 >> 8),1);
                  p_Var21 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
                  p_Var27 = (_tlgWrapperByVal<8> *)CONCAT71(uVar28,4);
                  WPP_RECORDER_AND_TRACE_SF_L
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,'\x01',p_Var21,4,4,
                             0x44,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
                             (char)local_res18.Data1);
                  local_e8.RxBandwidth = (ulong)local_134;
                  local_e8.TxBandwidth = local_138;
                  if (((4 < DAT_140014000) && ((_DAT_140014010 & 0x400000000000) != 0)) &&
                     ((DAT_140014018 & 0x400000000000) == DAT_140014018)) {
                    local_120 = uVar3;
                    local_res18.Data1 =
                         CONCAT31(local_res18.Data1._1_3_,local_100->bAlternateSetting);
                    local_11c = local_130;
                    local_128._0_1_ = local_res18.Data4[0];
                    local_128._1_1_ = local_res18.Data4[1];
                    local_10c = *(uint *)(param_2 + 0xc);
                    local_108 = *(uint *)(param_2 + 8);
                    local_104 = (p_Var1->Sco).MaxFrameSize;
                    local_114 = (uint)local_134;
                    local_110 = local_138;
                    local_12c = (p_Var1->Sco).RealMaxFrameSize;
                    local_126 = (ushort)((p_Var1->Sco).MaxInterface)->bAlternateSetting;
                    local_124[0] = (ushort)((p_Var1->Sco).RealMaxInterface)->bAlternateSetting;
                    p_Var2 = (_tlgProvider_t *)p_Var1->DeviceDescriptor;
                    local_130 = CONCAT22(local_130._2_2_,
                                         *(undefined2 *)((longlong)&p_Var2->ProviderMetadataPtr + 2)
                                        );
                    local_138 = CONCAT22(local_138._2_2_,*(undefined2 *)&p_Var2->ProviderMetadataPtr
                                        );
                    local_134._0_2_ = *(undefined2 *)((longlong)&p_Var2->LevelPlus1 + 2);
                    p_Var27 = (_tlgWrapperByVal<8> *)&local_f0;
                    local_f0 = (_DEVICE_EXTENSION *)0x2000800;
                    local_118 = uVar15;
                    local_f8 = p_Var1;
                    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
                    ::
                    Write<_tlgWrapperByVal<8>,_tlgWrapperByRef<16>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<4>_>
                              (p_Var2,&DAT_140011d8b,p_Var20,p_Var21,p_Var27,
                               (_tlgWrapperByRef<16> *)&local_f8,(_tlgWrapperByVal<2> *)local_134,
                               (_tlgWrapperByVal<2> *)&local_138,(_tlgWrapperByVal<2> *)&local_130,
                               (_tlgWrapperByVal<2> *)local_124,(_tlgWrapperByVal<4> *)&local_12c,
                               (_tlgWrapperByVal<2> *)&local_126,(_tlgWrapperByVal<4> *)&local_104,
                               (_tlgWrapperByVal<4> *)&local_108,(_tlgWrapperByVal<4> *)&local_10c,
                               (_tlgWrapperByVal<4> *)&local_110,(_tlgWrapperByVal<4> *)&local_114,
                               (_tlgWrapperByVal<4> *)&local_118,(_tlgWrapperByVal<2> *)&local_128,
                               (_tlgWrapperByVal<4> *)&local_11c,(_tlgWrapperByVal<1> *)&local_res18
                               ,(_tlgWrapperByVal<4> *)&local_120);
                  }
                  pSVar10 = (ScoUsbAltSetting *)&DAT_140011000;
                  if (local_100->bAlternateSetting != '\x06') {
                    pSVar10 = (ScoUsbAltSetting *)&DAT_140011050;
                  }
                  (p_Var1->Sco).UsbAltSetting = pSVar10;
                  local_e8.Callback =
                       *(_func___cdecl_long_void_ptr__BTH_SCO_MP_INDICATION_CODE__BTH_SCO_MP_INDICATION_PARAMETERS_ptr
                         **)(param_2 + 0x18);
                  uVar13 = (ulonglong)(ushort)local_res18.Data4._0_2_;
                  local_e8.CallbackContext = *(void **)(param_2 + 0x20);
                  local_e8.ConnectionHandle = *(ushort *)(param_2 + 4) & 0xfff;
                  BthUsb_ScoComputeChannelInfo(p_Var1,&local_e8,local_res18.Data4._0_2_);
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  else {
                    cVar11 = '\x01';
                  }
                  uVar28 = (undefined7)((ulonglong)p_Var27 >> 8);
                  WPP_RECORDER_AND_TRACE_SF_q
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar13,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x45,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)&local_e8);
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  WPP_RECORDER_AND_TRACE_SF_d
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar13,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x46,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
                             (char)local_e8.ConnectionHandle);
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  WPP_RECORDER_AND_TRACE_SF_d
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar13,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x47,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)local_e8.Flags);
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  pcVar18 = (char *)CONCAT71((int7)(uVar13 >> 8),1);
                  uVar17 = CONCAT71(uVar28,4);
                  WPP_RECORDER_AND_TRACE_SF_L
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,'\x01',
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x48,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
                             (char)local_e8.WriteDataSizePerReq);
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  WPP_RECORDER_AND_TRACE_SF_LLL
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar17,4,0x49,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
                             (char)local_e8.TxBandwidth,(char)local_e8.TxPacketSize,
                             (char)local_e8.TxFragmentSize);
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  WPP_RECORDER_AND_TRACE_SF_LLL
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar17,4,0x4a,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
                             (char)local_e8.RxBandwidth,(char)local_e8.RxPacketSize,
                             (char)local_e8.RxFragmentSize);
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar11 = '\0';
                  }
                  WPP_RECORDER_AND_TRACE_SF_
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4b,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
                  if ((p_Var1->Sco).NumChannels == 0) {
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                       (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                      cVar11 = '\0';
                    }
                    WPP_RECORDER_AND_TRACE_SF_
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4c,
                               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
                    iVar6 = BthUsb_ScoGetUsbBusInterface(p_Var1);
                    if (iVar6 < 0) {
                      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                         (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                        cVar11 = '\0';
                      }
                      WPP_RECORDER_AND_TRACE_SF_
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x4d,
                                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
                      goto LAB_14000401e;
                    }
                    _Var25 = (_tlgWrapperByVal<2>)0x1;
                    p_Var30 = p_Var1;
                    iVar6 = ResourceQueue_Initialize
                                      (&(p_Var1->Sco).WriteCtxQueue.AbortStatus,
                                       ((p_Var1->Sco).UsbAltSetting)->AllocWriteTransferCtxImpl);
                    if (-1 < iVar6) {
                      iVar6 = BthUsb_ScoInitReadResources(p_Var1);
                      if (-1 < iVar6) {
                        pcVar18 = "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousb.cpp";
                        iVar6 = IoAcquireRemoveLockEx
                                          (&p_Var1->RemoveLock,BthUsb_ScoAddChannel,
                                           "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousb.cpp"
                                           ,0x8f9,0x20,p_Var30);
                        if (-1 < iVar6) {
                          _Var25 = (_tlgWrapperByVal<2>)0x1;
                          goto LAB_140003cb3;
                        }
                        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                           (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                          cVar11 = '\0';
                        }
                        WPP_RECORDER_AND_TRACE_SF_
                                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x50,
                                   &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
                        _Var25 = (_tlgWrapperByVal<2>)0x1;
                        _Var22 = local_res8._0_1_;
                        goto LAB_140003d3c;
                      }
                      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                         (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                        cVar11 = '\0';
                      }
                      WPP_RECORDER_AND_TRACE_SF_
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x4f,
                                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
                      _Var22 = local_res8._0_1_;
                      goto LAB_140003d4a;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                       (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                      cVar11 = '\0';
                    }
                    WPP_RECORDER_AND_TRACE_SF_
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xc,
                               &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
                    BthUsb_ScoFreeWriteResources(p_Var1);
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                       (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                      cVar11 = '\0';
                    }
                    WPP_RECORDER_AND_TRACE_SF_
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x4e,
                               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
                    _Var22 = local_res8._0_1_;
LAB_140003d57:
                    BthUsb_ScoReleaseUsbBusInterface(p_Var1);
                  }
                  else {
                    _Var25 = local_res10._0_1_;
LAB_140003cb3:
                    BthUsb_ScoStopUsbTraffic(p_Var1);
                    p_Var4 = local_100;
                    iVar6 = BthUsb_ScoSelectInterface(p_Var1,local_100);
                    if (-1 < iVar6) {
                      *(ulonglong *)p_Var24 = CONCAT62(local_e8._2_6_,local_e8.ConnectionHandle);
                      p_Var24->Lock = local_e8.Lock;
                      p_Var24->Flags = local_e8.Flags;
                      p_Var24->TxBandwidth = local_e8.TxBandwidth;
                      p_Var24->RxBandwidth = local_e8.RxBandwidth;
                      p_Var24->TxPacketSize = local_e8.TxPacketSize;
                      p_Var24->RxPacketSize = local_e8.RxPacketSize;
                      p_Var24->TxFragmentSize = local_e8.TxFragmentSize;
                      *(ulonglong *)&p_Var24->RxFragmentSize =
                           CONCAT44(local_e8._44_4_,local_e8.RxFragmentSize);
                      p_Var24->Callback = local_e8.Callback;
                      p_Var24->CallbackContext = local_e8.CallbackContext;
                      (p_Var24->WritePipeObj).FnSendUrb = local_e8.WritePipeObj.FnSendUrb;
                      (p_Var24->WritePipeObj).FnCompleteUrb = local_e8.WritePipeObj.FnCompleteUrb;
                      (p_Var24->WritePipeObj).FnAlignFrame = local_e8.WritePipeObj.FnAlignFrame;
                      (p_Var24->WritePipeObj).FnGetNextFrame = local_e8.WritePipeObj.FnGetNextFrame;
                      (p_Var24->WritePipeObj).PipeType = local_e8.WritePipeObj.PipeType;
                      (p_Var24->WritePipeObj).Id = local_e8.WritePipeObj.Id;
                      *(undefined2 *)&(p_Var24->WritePipeObj).field_0x26 =
                           local_e8.WritePipeObj._38_2_;
                      (p_Var24->WritePipeObj).Lock = local_e8.WritePipeObj.Lock;
                      (p_Var24->WritePipeObj).Flags = local_e8.WritePipeObj.Flags;
                      (p_Var24->WritePipeObj).InProgressUrbs = local_e8.WritePipeObj.InProgressUrbs;
                      (p_Var24->WritePipeObj).InProgressUrbsHead.Flink =
                           local_e8.WritePipeObj.InProgressUrbsHead.Flink;
                      (p_Var24->WritePipeObj).InProgressUrbsHead.Blink =
                           local_e8.WritePipeObj.InProgressUrbsHead.Blink;
                      (p_Var24->WritePipeObj).NextStartFrame = local_e8.WritePipeObj.NextStartFrame;
                      (p_Var24->WritePipeObj).fNextStartFrame =
                           local_e8.WritePipeObj.fNextStartFrame;
                      *(undefined3 *)&(p_Var24->WritePipeObj).field_0x4d =
                           local_e8.WritePipeObj._77_3_;
                      p_Var24->WriteDataSizePerReq = local_e8.WriteDataSizePerReq;
                      p_Var24->WriteFrameInterval = local_e8.WriteFrameInterval;
                      (p_Var1->Sco).NumChannels = local_res18.Data4._0_2_;
                      BthUsb_ScoUpdateChannelsInfo(p_Var1);
                      BthUsb_ScoUpdateWriteResources(p_Var1);
                      BthUsb_ScoStartUsbTraffic(p_Var1);
                      iVar6 = 0;
                      goto LAB_14000401e;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                      cVar11 = '\0';
                    }
                    else {
                      cVar11 = '\x01';
                    }
                    WPP_RECORDER_AND_TRACE_SF_q
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x51,
                               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)p_Var4);
                    local_res10 = CONCAT11(local_res10._1_1_,_Var25);
                    _Var22 = (_tlgWrapperByVal<2>)0x1;
                    if (_Var25 != (_tlgWrapperByVal<2>)0x0) {
LAB_140003d3c:
                      BthUsb_ScoFreeReadResources(p_Var1);
LAB_140003d4a:
                      BthUsb_ScoFreeWriteResources(p_Var1);
                    }
                    if (_Var25 != (_tlgWrapperByVal<2>)0x0) goto LAB_140003d57;
                  }
                  if (_Var22 != (_tlgWrapperByVal<2>)0x0) {
                    BthUsb_ScoStartUsbTraffic(p_Var1);
                  }
                  if (local_res10._0_1_ != (_tlgWrapperByVal<2>)0x0) {
                    pcVar18 = (char *)0x20;
                    IoReleaseRemoveLockEx(&p_Var1->RemoveLock,BthUsb_ScoAddChannel);
                  }
                }
                goto LAB_14000401e;
              }
              break;
            }
            uVar12 = (short)uVar13 + 1;
            uVar13 = (ulonglong)uVar12;
          } while (uVar12 < 3);
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar11 = '\0';
          }
          else {
            cVar11 = '\x01';
          }
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x3e,
                     &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
          iVar6 = -0x3ffffd9b;
          goto LAB_14000401e;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
           (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar11 = '\0';
        }
        uVar32 = 0x3c;
      }
    }
    else {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
         (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar11 = '\0';
      }
      uVar32 = 0x3a;
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,pcVar18,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar32,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
    iVar6 = -0x3ffffff3;
  }
LAB_14000401e:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar16 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,pcVar18,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x52,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)iVar6);
  if (ppVar14 != (push_lock *)0x0) {
    ExReleasePushLockExclusiveEx(ppVar14,0);
    KeLeaveCriticalRegion();
  }
  return iVar6;
}



===== BthUsb_ScoAllocTransferContextImpl @ 1400040a4 =====

/* struct _SCO_USB_TRANSFER_CTX * __ptr64 __cdecl BthUsb_ScoAllocTransferContextImpl(struct
   _DEVICE_EXTENSION * __ptr64,unsigned long,unsigned long,struct _RESOURCE_QUEUE * __ptr64) */

_SCO_USB_TRANSFER_CTX * __cdecl
BthUsb_ScoAllocTransferContextImpl
          (_DEVICE_EXTENSION *param_1,ulong param_2,ulong param_3,_RESOURCE_QUEUE *param_4)

{
  uint uVar1;
  _URB *p_Var2;
  _IRP *p_Var3;
  _SCO_USB_TRANSFER_CTX *p_Var4;
  ulonglong uVar5;
  uchar *puVar6;
  _MDL *p_Var7;
  void *pvVar8;
  uint uVar9;
  undefined1 uVar10;
  char cVar11;
  undefined4 in_register_00000084;
  undefined *puVar12;
  undefined2 uVar13;
  
  puVar12 = (undefined *)CONCAT44(in_register_00000084,param_3);
  if ((ulonglong)param_2 * 0xc < 0x100000000) {
    uVar1 = (uint)((ulonglong)param_2 * 0xc);
    uVar9 = uVar1 + 0x98;
    if (uVar9 < uVar1) {
      uVar10 = 0x95;
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
         (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar11 = '\0';
      }
      uVar13 = 0x10;
    }
    else {
      puVar12 = (undefined *)0x42425355;
      p_Var2 = (_URB *)ExAllocatePool2(0x40,uVar9);
      if (p_Var2 != (_URB *)0x0) {
        p_Var3 = (_IRP *)IoAllocateIrp(param_1->TopOfStack->StackSize + '\x01',0);
        if (p_Var3 == (_IRP *)0x0) {
          uVar10 = 0x9a;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar11 = '\0';
          }
          else {
            cVar11 = '\x01';
          }
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,puVar12,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x12,
                     &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
        }
        else {
          puVar12 = (undefined *)0x42425355;
          p_Var4 = (_SCO_USB_TRANSFER_CTX *)ExAllocatePool2(0x40);
          if (p_Var4 == (_SCO_USB_TRANSFER_CTX *)0x0) {
            uVar10 = 0x9a;
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar11 = '\0';
            }
            else {
              cVar11 = '\x01';
            }
            puVar12 = WPP_GLOBAL_Control;
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,WPP_GLOBAL_Control,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x13,
                       &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
          }
          else {
            p_Var4->CtxQueue = param_4;
            p_Var4->Irp = p_Var3;
            p_Var4->Signature = 0x43545553;
            p_Var4->Urb = p_Var2;
            uVar5 = (ulonglong)(param_1->Sco).MaxFrameSize * (ulonglong)param_2;
            p_Var4->UrbSize = uVar9;
            p_Var4->UrbFrames = param_2;
            if (uVar5 < 0x100000000) {
              puVar12 = (undefined *)0x42425355;
              puVar6 = (uchar *)ExAllocatePool2(0x40,uVar5 & 0xffffffff);
              if (puVar6 == (uchar *)0x0) {
                uVar10 = 0x9a;
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                   (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar11 = '\0';
                }
                uVar13 = 0x15;
                goto LAB_1400044bc;
              }
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                 (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
                cVar11 = '\0';
              }
              if ((cVar11 != '\0') || (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
                WPP_RECORDER_AND_TRACE_SF_L
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                           *(short *)(WPP_GLOBAL_Control + 0x48) != 0,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x16,
                           &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)uVar5);
              }
              puVar12 = (undefined *)0x0;
              p_Var7 = (_MDL *)IoAllocateMdl(puVar6,uVar5 & 0xffffffff,0,0,0);
              cVar11 = '\0';
              if (p_Var7 == (_MDL *)0x0) {
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  cVar11 = '\x01';
                }
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,puVar12,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x17,
                           &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
              }
              else {
                MmBuildMdlForNonPagedPool(p_Var7);
                p_Var4->TransferBuffer = puVar6;
                p_Var4->TransferMdl = p_Var7;
                p_Var4->BufferLen = (ulong)uVar5;
                if (param_3 == 0) {
                  return p_Var4;
                }
                puVar12 = (undefined *)0x42425355;
                pvVar8 = (void *)ExAllocatePool2(0x40);
                cVar11 = '\0';
                if (pvVar8 != (void *)0x0) {
                  p_Var4->AuxiliaryBuffer = pvVar8;
                  p_Var4->AuxBufferLen = param_3;
                  return p_Var4;
                }
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  cVar11 = '\x01';
                }
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,puVar12,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x18,
                           &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
                IoFreeMdl(p_Var7);
              }
              uVar10 = 0x9a;
              ExFreePoolWithTag(puVar6,0);
            }
            else {
              uVar10 = 0x95;
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                cVar11 = '\0';
              }
              else {
                cVar11 = '\x01';
              }
              uVar13 = 0x14;
LAB_1400044bc:
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,puVar12,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar13,
                         &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
            }
            ExFreePoolWithTag(p_Var4,0);
          }
          IoFreeIrp(p_Var3);
        }
        ExFreePoolWithTag(p_Var2,0);
        goto LAB_140004597;
      }
      uVar10 = 0x9a;
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar11 = '\0';
      }
      else {
        cVar11 = '\x01';
      }
      uVar13 = 0x11;
    }
  }
  else {
    uVar10 = 0x95;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
       (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar11 = '\0';
    }
    uVar13 = 0xf;
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,puVar12,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar13,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
LAB_140004597:
  cVar11 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar11 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,puVar12,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x19,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,uVar10);
  return (_SCO_USB_TRANSFER_CTX *)0x0;
}



===== BthUsb_ScoAllocTransferContextsImpl @ 140004604 =====

/* long __cdecl BthUsb_ScoAllocTransferContextsImpl(struct _DEVICE_EXTENSION * __ptr64,unsigned
   long,unsigned long,unsigned long,struct _RESOURCE_QUEUE * __ptr64,struct _LIST_ENTRY * __ptr64)
    */

long __cdecl
BthUsb_ScoAllocTransferContextsImpl
          (_DEVICE_EXTENSION *param_1,ulong param_2,ulong param_3,ulong param_4,
          _RESOURCE_QUEUE *param_5,_LIST_ENTRY *param_6)

{
  _SCO_USB_TRANSFER_CTX *p_Var1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      p_Var1 = BthUsb_ScoAllocTransferContextImpl(param_1,param_3,param_4,param_5);
      if (p_Var1 == (_SCO_USB_TRANSFER_CTX *)0x0) {
        BthUsb_ScoDestroyTransferContextsImpl(param_1,param_6);
        return -0x3fffff66;
      }
      BthUsb_ScoFreeTransferContextImpl(param_1,param_6,p_Var1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return 0;
}



===== BthUsb_ScoAnyTransfer @ 14000468c =====

/* unsigned char __cdecl BthUsb_ScoAnyTransfer(struct _DEVICE_EXTENSION * __ptr64,unsigned char) */

uchar __cdecl BthUsb_ScoAnyTransfer(_DEVICE_EXTENSION *param_1,uchar param_2)

{
  ulong uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  do {
    if ((param_1->Sco).Channel[uVar2].ConnectionHandle != 0xffff) {
      if (param_2 == '\0') {
        uVar1 = (param_1->Sco).Channel[uVar2].TxBandwidth;
      }
      else {
        uVar1 = (param_1->Sco).Channel[uVar2].RxBandwidth;
      }
      if (uVar1 != 0) {
        return '\x01';
      }
    }
    uVar2 = uVar2 + 1;
    if (2 < uVar2) {
      return '\0';
    }
  } while( true );
}



===== BthUsb_ScoBasicValidation @ 1400046e4 =====

/* long __cdecl BthUsb_ScoBasicValidation(struct _BTDEVICE * __ptr64,void * __ptr64,unsigned long)
    */

long __cdecl BthUsb_ScoBasicValidation(_BTDEVICE *param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  
  cVar2 = '\0';
  lVar3 = -0x3ffffff3;
  if (((param_1 != (_BTDEVICE *)0x0) && (param_1->MiniportContext != (void *)0x0)) &&
     (param_2 != (void *)0x0)) {
    uVar1 = *(uint *)param_2;
    if (uVar1 == param_3) {
      if (*(int *)((longlong)param_1->MiniportContext + 0xe8) < 0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          cVar2 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,(ulonglong)uVar1,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x23,
                   &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
        lVar3 = -0x3fffff45;
      }
      else {
        lVar3 = 0;
      }
    }
    else {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        cVar2 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_dd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,(ulonglong)uVar1,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x22,
                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_3,(char)uVar1);
    }
  }
  return lVar3;
}



===== BthUsb_ScoComputeChannelInfo @ 1400047d0 =====

/* void __cdecl BthUsb_ScoComputeChannelInfo(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_CHANNEL * __ptr64,unsigned short) */

void __cdecl
BthUsb_ScoComputeChannelInfo(_DEVICE_EXTENSION *param_1,_SCO_USB_CHANNEL *param_2,ushort param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  uVar2 = 0;
  uVar1 = 0;
  if (param_2->TxBandwidth != 0) {
    uVar4 = (param_2->TxBandwidth / 1000) * (uint)param_3 + 1;
    uVar2 = uVar4 * ((param_1->Sco).UsbAltSetting)->FRAMES_X_HCIPACKET;
  }
  if (param_2->RxBandwidth != 0) {
    uVar3 = (param_2->RxBandwidth / 1000) * (uint)param_3 + 1;
    uVar1 = uVar3 * ((param_1->Sco).UsbAltSetting)->FRAMES_X_HCIPACKET;
  }
  param_2->TxPacketSize = uVar2;
  param_2->RxPacketSize = uVar1;
  param_2->TxFragmentSize = uVar4;
  param_2->RxFragmentSize = uVar3;
  return;
}



===== BthUsb_ScoControlChannel @ 140004880 =====

/* long __cdecl BthUsb_ScoControlChannel(struct _BTDEVICE * __ptr64,struct
   _BTH_SCO_CONTROL_CHANNEL_ARG * __ptr64) */

long __cdecl BthUsb_ScoControlChannel(_BTDEVICE *param_1,_BTH_SCO_CONTROL_CHANNEL_ARG *param_2)

{
  push_lock *ppVar1;
  _DEVICE_EXTENSION *p_Var2;
  undefined1 uVar3;
  long lVar4;
  ushort uVar5;
  ulonglong uVar6;
  char cVar7;
  undefined8 uVar8;
  _SCO_USB_CHANNEL *p_Var9;
  
  uVar8 = 0x10;
  lVar4 = BthUsb_ScoBasicValidation(param_1,param_2,0x10);
  if (-1 < lVar4) {
    if (*(short *)(param_2 + 4) == -1) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,uVar8,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x5b,
                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
      lVar4 = -0x3ffffff3;
    }
    else {
      p_Var2 = param_1->MiniportContext;
      ppVar1 = &(p_Var2->Sco).ChannelMutex;
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(ppVar1,0);
      uVar6 = 0;
      cVar7 = '\x01';
      do {
        p_Var9 = (p_Var2->Sco).Channel + uVar6;
        if (p_Var9->ConnectionHandle == *(ushort *)(param_2 + 4)) {
          if (p_Var9 != (_SCO_USB_CHANNEL *)0x0) {
            if (*(int *)(param_2 + 8) == 0) {
              uVar3 = KfRaiseIrql(2);
              BthUsb_ScoWriteData(p_Var2,p_Var9,'\x01');
              KeLowerIrql(uVar3);
              lVar4 = 0;
            }
            else {
              lVar4 = -0x3fffff45;
            }
            goto LAB_140004a07;
          }
          break;
        }
        uVar5 = (short)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < 3);
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar7 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (ulonglong)*(ushort *)(param_2 + 4),*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,
                 0x5c,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
      lVar4 = -0x3ffffff3;
LAB_140004a07:
      if (ppVar1 != (push_lock *)0x0) {
        ExReleasePushLockExclusiveEx(ppVar1,0);
        KeLeaveCriticalRegion();
      }
    }
  }
  return lVar4;
}



===== BthUsb_ScoDestroyTransferContextsImpl @ 140004a60 =====

/* void __cdecl BthUsb_ScoDestroyTransferContextsImpl(void * __ptr64,struct _LIST_ENTRY * __ptr64)
    */

void __cdecl BthUsb_ScoDestroyTransferContextsImpl(void *param_1,_LIST_ENTRY *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined8 in_R8;
  
  while( true ) {
    puVar1 = BthUsb_ScoGetTransferContextImpl(param_1,param_2);
    if (puVar1 == (undefined4 *)0x0) break;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1a,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)puVar1);
    if (*(longlong *)(puVar1 + 0x1c) != 0) {
      IoFreeMdl();
      *(undefined8 *)(puVar1 + 0x1c) = 0;
    }
    if (*(longlong *)(puVar1 + 0x1a) != 0) {
      ExFreePoolWithTag(*(longlong *)(puVar1 + 0x1a),0);
      *(undefined8 *)(puVar1 + 0x1a) = 0;
    }
    if (*(longlong *)(puVar1 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(puVar1 + 0x20),0);
      *(undefined8 *)(puVar1 + 0x20) = 0;
    }
    if (*(longlong *)(puVar1 + 0x10) != 0) {
      IoFreeIrp();
      *(undefined8 *)(puVar1 + 0x10) = 0;
    }
    if (*(longlong *)(puVar1 + 0x12) != 0) {
      ExFreePoolWithTag(*(longlong *)(puVar1 + 0x12),0);
      *(undefined8 *)(puVar1 + 0x12) = 0;
    }
    *puVar1 = 0xdeadbeef;
    ExFreePoolWithTag(puVar1,0);
  }
  return;
}



===== BthUsb_ScoFindInterfaceByFrame @ 140004b9c =====

/* struct _USB_INTERFACE_DESCRIPTOR * __ptr64 __cdecl BthUsb_ScoFindInterfaceByFrame(struct
   _DEVICE_EXTENSION * __ptr64,unsigned long,unsigned long * __ptr64) */

_USB_INTERFACE_DESCRIPTOR * __cdecl
BthUsb_ScoFindInterfaceByFrame(_DEVICE_EXTENSION *param_1,ulong param_2,ulong *param_3)

{
  long lVar1;
  undefined1 *puVar2;
  char cVar3;
  _USB_INTERFACE_DESCRIPTOR *p_Var4;
  undefined8 unaff_RSI;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  ulonglong uVar8;
  _USB_INTERFACE_DESCRIPTOR *local_res8;
  
  local_res8 = (_USB_INTERFACE_DESCRIPTOR *)0x0;
  if (param_3 != (ulong *)0x0) {
    *param_3 = 0;
  }
  uVar5 = CONCAT71((int7)((ulonglong)unaff_RSI >> 8),1);
  puVar2 = (undefined1 *)register0x00000020;
  do {
    uVar7 = (int)uVar5 + (int)puVar2;
    uVar8 = (ulonglong)uVar7;
    bVar6 = (byte)uVar7;
    if ((&DAT_140011720)[(char)puVar2] == param_2) {
      lVar1 = BthUsb_GetIsoInterface
                        (param_1,(param_1->Sco).InterfaceNumber,bVar6,&local_res8,param_3);
      p_Var4 = local_res8;
      if (lVar1 < 0) {
        p_Var4 = (_USB_INTERFACE_DESCRIPTOR *)0x0;
      }
      if (p_Var4 != (_USB_INTERFACE_DESCRIPTOR *)0x0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          uVar5 = 0;
        }
        WPP_RECORDER_AND_TRACE_SF_DL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)uVar5,uVar8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return p_Var4;
      }
      break;
    }
    puVar2 = (undefined1 *)CONCAT71((int7)((ulonglong)(longlong)(char)puVar2 >> 8),bVar6);
  } while (bVar6 < 6);
  p_Var4 = (_USB_INTERFACE_DESCRIPTOR *)0x0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
     (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar3 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_L
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,'\x01',
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xc,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_2);
  uVar7 = (param_1->Sco).MaxFrameSize;
  if ((param_2 <= uVar7) && (p_Var4 = (param_1->Sco).MaxInterface, param_3 != (ulong *)0x0)) {
    *param_3 = uVar7;
  }
  return p_Var4;
}



===== BthUsb_ScoFreeTransferContextImpl @ 140004cf0 =====

/* void __cdecl BthUsb_ScoFreeTransferContextImpl(void * __ptr64,struct _LIST_ENTRY * __ptr64,void *
   __ptr64) */

void __cdecl BthUsb_ScoFreeTransferContextImpl(void *param_1,_LIST_ENTRY *param_2,void *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  void *_Dst;
  undefined8 uVar6;
  void *_Dst_00;
  void *_Dst_01;
  undefined8 uVar7;
  code *pcVar8;
  _LIST_ENTRY *p_Var9;
  _LIST_ENTRY *p_Var10;
  
  uVar5 = *(undefined8 *)((longlong)param_3 + 0x20);
  _Dst = *(void **)((longlong)param_3 + 0x48);
  uVar1 = *(uint *)((longlong)param_3 + 0x54);
  uVar6 = *(undefined8 *)((longlong)param_3 + 0x40);
  _Dst_00 = *(void **)((longlong)param_3 + 0x68);
  _Dst_01 = *(void **)((longlong)param_3 + 0x80);
  uVar2 = *(uint *)((longlong)param_3 + 0x88);
  uVar3 = *(undefined4 *)((longlong)param_3 + 0x50);
  uVar7 = *(undefined8 *)((longlong)param_3 + 0x70);
  uVar4 = *(uint *)((longlong)param_3 + 0x78);
  memset(_Dst,0,(ulonglong)uVar1);
  IoReuseIrp(uVar6);
  memset(_Dst_00,0,(ulonglong)uVar4);
  if (_Dst_01 != (void *)0x0) {
    memset(_Dst_01,0,(ulonglong)uVar2);
  }
  memset(param_3,0,0xa8);
  *(undefined8 *)((longlong)param_3 + 0x20) = uVar5;
  *(undefined4 *)((longlong)param_3 + 0x50) = uVar3;
  *(undefined8 *)((longlong)param_3 + 0x70) = uVar7;
  *(uint *)((longlong)param_3 + 0x78) = uVar4;
  *(undefined4 *)param_3 = 0x43545553;
  *(undefined8 *)((longlong)param_3 + 0x40) = uVar6;
  *(void **)((longlong)param_3 + 0x48) = _Dst;
  *(uint *)((longlong)param_3 + 0x54) = uVar1;
  *(void **)((longlong)param_3 + 0x68) = _Dst_00;
  if (_Dst_01 != (void *)0x0) {
    *(void **)((longlong)param_3 + 0x80) = _Dst_01;
    *(uint *)((longlong)param_3 + 0x88) = uVar2;
  }
  *(undefined8 *)((longlong)param_3 + 0x18) = 0;
  *(code **)((longlong)param_3 + 0x10) = BthUsb_ScoReuseTransferCtxImpl;
  *(undefined4 *)((longlong)param_3 + 8) = 1;
  p_Var10 = (_LIST_ENTRY *)((longlong)param_3 + 0x28);
  *(_LIST_ENTRY **)((longlong)param_3 + 0x30) = p_Var10;
  p_Var10->Flink = p_Var10;
  p_Var9 = param_2->Flink;
  if (p_Var9->Blink != param_2) {
    pcVar8 = (code *)swi(0x29);
    p_Var9 = (_LIST_ENTRY *)(*pcVar8)(3);
  }
  p_Var10->Flink = p_Var9;
  *(_LIST_ENTRY **)((longlong)param_3 + 0x30) = param_2;
  p_Var9->Blink = p_Var10;
  param_2->Flink = p_Var10;
  return;
}



===== BthUsb_ScoGetTransferContextImpl @ 140004e50 =====

/* void * __ptr64 __cdecl BthUsb_ScoGetTransferContextImpl(void * __ptr64,struct _LIST_ENTRY *
   __ptr64) */

void * __cdecl BthUsb_ScoGetTransferContextImpl(void *param_1,_LIST_ENTRY *param_2)

{
  _LIST_ENTRY *p_Var1;
  _LIST_ENTRY *p_Var2;
  code *pcVar3;
  void *pvVar4;
  _LIST_ENTRY **pp_Var5;
  
  p_Var1 = param_2->Flink;
  pp_Var5 = (_LIST_ENTRY **)0x0;
  if (p_Var1 != param_2) {
    if ((p_Var1->Blink != param_2) || (p_Var2 = p_Var1->Flink, p_Var2->Blink != p_Var1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      pvVar4 = (void *)(*pcVar3)();
      return pvVar4;
    }
    param_2->Flink = p_Var2;
    p_Var2->Blink = param_2;
    pp_Var5 = &p_Var1[-3].Blink;
  }
  return pp_Var5;
}



===== BthUsb_ScoGetUsbBusInterface @ 140004e88 =====

/* long __cdecl BthUsb_ScoGetUsbBusInterface(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthUsb_ScoGetUsbBusInterface(_DEVICE_EXTENSION *param_1)

{
  long lVar1;
  char cVar2;
  undefined8 local_48;
  void *pvStack_40;
  _func___cdecl_void_void_ptr *local_38;
  _func___cdecl_void_void_ptr *p_Stack_30;
  _func___cdecl_void_void_ptr__USBD_VERSION_INFORMATION_ptr_ulong_ptr *local_28;
  _func___cdecl_long_void_ptr_ulong_ptr *p_Stack_20;
  _func___cdecl_long_void_ptr__URB_ptr *local_18;
  _func___cdecl_long_void_ptr_ulong_void_ptr_ulong_ptr_ulong_ptr *p_Stack_10;
  
  memset(&local_48,0,0x40);
  lVar1 = BthUsb_GetUsbBusInterface(param_1,&local_48,0x40,0);
  cVar2 = '\0';
  if (-1 < lVar1) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar2 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1f,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
    (param_1->Sco).UsbBusInterface.Size = (undefined2)local_48;
    (param_1->Sco).UsbBusInterface.Version = local_48._2_2_;
    *(undefined4 *)&(param_1->Sco).UsbBusInterface.field_0x4 = local_48._4_4_;
    (param_1->Sco).UsbBusInterface.BusContext = pvStack_40;
    (param_1->Sco).UsbBusInterface.InterfaceReference = local_38;
    (param_1->Sco).UsbBusInterface.InterfaceDereference = p_Stack_30;
    (param_1->Sco).UsbBusInterface.GetUSBDIVersion = local_28;
    (param_1->Sco).UsbBusInterface.QueryBusTime = p_Stack_20;
    (param_1->Sco).UsbBusInterface.SubmitIsoOutUrb = local_18;
    (param_1->Sco).UsbBusInterface.QueryBusInformation = p_Stack_10;
  }
  return lVar1;
}



===== BthUsb_ScoPipeObjInit @ 140004f58 =====

/* void __cdecl BthUsb_ScoPipeObjInit(struct _DEVICE_EXTENSION * __ptr64,struct _SCO_USB_PIPE_OBJ *
   __ptr64,enum _BTH_PIPE_TYPE,unsigned short,long (__cdecl*)(struct _DEVICE_EXTENSION *
   __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64),long (__cdecl*)(struct _DEVICE_EXTENSION *
   __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64),unsigned long (__cdecl*)(struct _DEVICE_EXTENSION
   * __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64,unsigned short,unsigned long),unsigned long
   (__cdecl*)(struct _DEVICE_EXTENSION * __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64,unsigned
   short,unsigned long)) */

void __cdecl
BthUsb_ScoPipeObjInit
          (_DEVICE_EXTENSION *param_1,_SCO_USB_PIPE_OBJ *param_2,_BTH_PIPE_TYPE param_3,
          ushort param_4,_func_long__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr *param_5,
          _func_long__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr *param_6,
          _func_ulong__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr_ushort_ulong *param_7,
          _func_ulong__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr_ushort_ulong *param_8)

{
  _LIST_ENTRY *p_Var1;
  char cVar2;
  undefined4 in_register_00000084;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,CONCAT44(in_register_00000084,param_3)
             ,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x5f,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_2);
  memset(param_2,0,0x50);
  param_2->FnCompleteUrb =
       (_func___cdecl_long__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr *)param_6;
  param_2->FnSendUrb = (_func___cdecl_long__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr *)param_5
  ;
  param_2->FnAlignFrame =
       (_func___cdecl_ulong__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr_ushort_ulong *)param_7;
  param_2->FnGetNextFrame =
       (_func___cdecl_ulong__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr_ushort_ulong *)param_8;
  param_2->PipeType = param_3;
  param_2->Id = param_4;
  KeInitializeSpinLock(&param_2->Lock);
  p_Var1 = &param_2->InProgressUrbsHead;
  (param_2->InProgressUrbsHead).Blink = p_Var1;
  p_Var1->Flink = p_Var1;
  return;
}



===== BthUsb_ScoRemoveChannel @ 140005040 =====

/* long __cdecl BthUsb_ScoRemoveChannel(struct _BTDEVICE * __ptr64,struct
   _BTH_SCO_REMOVE_CHANNEL_ARG * __ptr64) */

long __cdecl BthUsb_ScoRemoveChannel(_BTDEVICE *param_1,_BTH_SCO_REMOVE_CHANNEL_ARG *param_2)

{
  ushort *puVar1;
  _DEVICE_EXTENSION *p_Var2;
  long lVar3;
  uint uVar4;
  _USB_INTERFACE_DESCRIPTOR *p_Var5;
  ulong *puVar6;
  char cVar7;
  ushort uVar8;
  uint uVar9;
  ulonglong uVar10;
  push_lock *ppVar11;
  longlong lVar12;
  char cVar13;
  undefined8 in_R8;
  ulonglong uVar14;
  _SCO_USB_CHANNEL *p_Var15;
  undefined1 in_stack_ffffffffffffffb8;
  undefined7 in_stack_ffffffffffffffb9;
  undefined2 uVar16;
  
  ppVar11 = (push_lock *)0x0;
  cVar13 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_qH
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffffb9,in_stack_ffffffffffffffb8),4,0x53,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_1,
             (char)*(undefined2 *)(param_2 + 4));
  uVar14 = 8;
  lVar3 = BthUsb_ScoBasicValidation(param_1,param_2,8);
  if (-1 < lVar3) {
    if (*(short *)(param_2 + 4) == -1) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar7 = '\0';
      }
      uVar16 = 0x54;
    }
    else {
      p_Var2 = param_1->MiniportContext;
      ppVar11 = &(p_Var2->Sco).ChannelMutex;
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(ppVar11,0);
      uVar14 = (ulonglong)*(ushort *)(param_2 + 4);
      uVar10 = 0;
      lVar12 = 3;
      do {
        p_Var15 = (p_Var2->Sco).Channel + uVar10;
        if (p_Var15->ConnectionHandle == *(ushort *)(param_2 + 4)) {
          if (p_Var15 != (_SCO_USB_CHANNEL *)0x0) {
            BthUsb_ScoStopUsbTraffic(p_Var2);
            p_Var15->ConnectionHandle = 0xffff;
            puVar1 = &(p_Var2->Sco).NumChannels;
            *puVar1 = *puVar1 - 1;
            BthUsb_ScoUpdateChannelsInfo(p_Var2);
            BthUsb_ScoUpdateWriteResources(p_Var2);
            uVar8 = (p_Var2->Sco).NumChannels;
            uVar14 = (ulonglong)uVar8;
            if (uVar8 == 0) {
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                 (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                cVar7 = '\0';
              }
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,0,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x56,
                         &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
              lVar3 = BthUsb_ScoSelectInterface(p_Var2,(_USB_INTERFACE_DESCRIPTOR *)0x0);
              if (lVar3 < 0) {
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                   (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar7 = '\0';
                }
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,uVar14,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x57,
                           &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
              }
              BthUsb_ScoFreeReadResources(p_Var2);
              BthUsb_ScoFreeWriteResources(p_Var2);
              BthUsb_ScoReleaseUsbBusInterface(p_Var2);
              uVar14 = 0x20;
              IoReleaseRemoveLockEx(&p_Var2->RemoveLock,BthUsb_ScoAddChannel);
            }
            else {
              uVar9 = 0;
              puVar6 = &(p_Var2->Sco).Channel[0].TxBandwidth;
              do {
                if (((_SCO_USB_CHANNEL *)(puVar6 + -5))->ConnectionHandle != 0xffff) {
                  uVar4 = puVar6[1];
                  if (puVar6[1] <= uVar9) {
                    uVar4 = uVar9;
                  }
                  uVar9 = *puVar6;
                  if (*puVar6 <= uVar4) {
                    uVar9 = uVar4;
                  }
                }
                puVar6 = puVar6 + 0x26;
                lVar12 = lVar12 + -1;
              } while (lVar12 != 0);
              uVar14 = 0;
              p_Var5 = BthUsb_ScoFindInterfaceByFrame
                                 (p_Var2,(uVar9 / 1000) * (uint)uVar8 + 1,(ulong *)0x0);
              if (p_Var5 == (_USB_INTERFACE_DESCRIPTOR *)0x0) {
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                   (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar7 = '\0';
                }
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,uVar14,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x59,
                           &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
              }
              else {
                lVar3 = BthUsb_ScoSelectInterface(p_Var2,p_Var5);
                if (lVar3 < 0) {
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    cVar7 = '\0';
                  }
                  WPP_RECORDER_AND_TRACE_SF_q
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,uVar14,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x58,
                             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)p_Var5);
                }
                else {
                  BthUsb_ScoStartUsbTraffic(p_Var2);
                }
              }
            }
            lVar3 = 0;
            goto LAB_1400053d8;
          }
          break;
        }
        uVar8 = (short)uVar10 + 1;
        uVar10 = (ulonglong)uVar8;
      } while (uVar8 < 3);
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar7 = '\0';
      }
      uVar16 = 0x55;
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,uVar14,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar16,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
    lVar3 = -0x3ffffff3;
  }
LAB_1400053d8:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar13 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,uVar14,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x5a,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)lVar3);
  if (ppVar11 != (push_lock *)0x0) {
    ExReleasePushLockExclusiveEx(ppVar11,0);
    KeLeaveCriticalRegion();
  }
  return lVar3;
}



===== BthUsb_ScoReuseTransferCtxImpl @ 140005470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthUsb_ScoReuseTransferCtxImpl(struct _REF_OBJ * __ptr64) */

void __cdecl BthUsb_ScoReuseTransferCtxImpl(_REF_OBJ *param_1)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  undefined1 uVar4;
  
  piVar2 = *(int **)(param_1 + 1);
  uVar4 = KeAcquireSpinLockRaiseToDpc(piVar2 + 2);
  (**(code **)(piVar2 + 0x12))(*(undefined8 *)(piVar2 + 0x16),piVar2 + 4,&param_1[-1].DebugInfo);
  piVar1 = piVar2 + 8;
  *piVar1 = *piVar1 + -1;
  bVar3 = false;
  if (*piVar1 == 0) {
    bVar3 = false;
    if (*piVar2 < 0) {
      bVar3 = true;
    }
  }
  KeReleaseSpinLock(piVar2 + 2,uVar4);
  if (bVar3) {
    KeSetEvent(piVar2 + 10,0,0);
  }
  return;
}



===== BthUsb_ScoSelectInterface @ 140005520 =====

/* long __cdecl BthUsb_ScoSelectInterface(struct _DEVICE_EXTENSION * __ptr64,struct
   _USB_INTERFACE_DESCRIPTOR * __ptr64) */

long __cdecl
BthUsb_ScoSelectInterface(_DEVICE_EXTENSION *param_1,_USB_INTERFACE_DESCRIPTOR *param_2)

{
  long lVar1;
  char cVar2;
  char cVar3;
  ulong in_R8D;
  undefined4 in_register_00000084;
  undefined1 in_stack_ffffffffffffffb8;
  undefined7 in_stack_ffffffffffffffb9;
  
  if (param_2 == (_USB_INTERFACE_DESCRIPTOR *)0x0) {
    param_2 = (param_1->Sco).OffInterface;
  }
  cVar3 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_qqd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,CONCAT44(in_register_00000084,in_R8D),
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffffb9,in_stack_ffffffffffffffb8),4,0x5d,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_1,(char)param_2,
             param_2->bAlternateSetting);
  lVar1 = BthUsb_SelectIsoInterface(param_1,param_2,in_R8D);
  if (-1 < lVar1) {
    (param_1->Sco).CurInterface = param_2;
    lVar1 = 0;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,CONCAT44(in_register_00000084,in_R8D),
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x5e,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)lVar1);
  return lVar1;
}



===== BthUsb_ScoSendTransferUrb @ 140005628 =====

/* long __cdecl BthUsb_ScoSendTransferUrb(struct _DEVICE_EXTENSION * __ptr64,struct
   _USBD_PIPE_INFORMATION * __ptr64,long (__cdecl*)(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64),struct _SCO_USB_TRANSFER_CTX * __ptr64) */

long __cdecl
BthUsb_ScoSendTransferUrb
          (_DEVICE_EXTENSION *param_1,_USBD_PIPE_INFORMATION *param_2,
          _func_long__DEVICE_OBJECT_ptr__IRP_ptr_void_ptr *param_3,_SCO_USB_TRANSFER_CTX *param_4)

{
  void **ppvVar1;
  _IRP *p_Var2;
  _DEVICE_OBJECT *p_Var3;
  _URB *p_Var4;
  void *pvVar5;
  int iVar6;
  char cVar7;
  
  p_Var2 = param_4->Irp;
  p_Var3 = param_1->TopOfStack;
  p_Var4 = param_4->Urb;
  *(_DEVICE_EXTENSION **)((longlong)(p_Var2->Tail).Apc.SystemArgument1 + -0x40) = param_1;
  ppvVar1 = &(p_Var2->Tail).Apc.SystemArgument1;
  *ppvVar1 = (void *)((longlong)*ppvVar1 + -0x48);
  pvVar5 = (p_Var2->Tail).Apc.SystemArgument1;
  p_Var2->CurrentLocation = p_Var2->CurrentLocation + -1;
  *(_URB **)((longlong)pvVar5 + -0x40) = p_Var4;
  *(undefined4 *)((longlong)pvVar5 + -0x30) = 0x220003;
  *(undefined1 *)((longlong)pvVar5 + -0x48) = 0xf;
  pvVar5 = (p_Var2->Tail).Apc.SystemArgument1;
  *(_func_long__DEVICE_OBJECT_ptr__IRP_ptr_void_ptr **)((longlong)pvVar5 + -0x10) = param_3;
  *(_SCO_USB_TRANSFER_CTX **)((longlong)pvVar5 + -8) = param_4;
  *(undefined1 *)((longlong)pvVar5 + -0x45) = 0xe0;
  iVar6 = IofCallDriver(p_Var3);
  if (iVar6 != 0x103) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
               &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)iVar6);
  }
  return 0x103;
}



===== BthUsb_ScoStartUsbTraffic @ 1400056ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthUsb_ScoStartUsbTraffic(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoStartUsbTraffic(_DEVICE_EXTENSION *param_1)

{
  undefined1 uVar1;
  uchar uVar2;
  _DEVICE_EXTENSION *p_Var3;
  
  uVar1 = KfRaiseIrql(2);
  p_Var3 = param_1;
  uVar2 = BthUsb_ScoAnyTransfer(param_1,'\0');
  if (uVar2 != '\0') {
    (*((param_1->Sco).UsbAltSetting)->WriteStart)(p_Var3);
  }
  uVar2 = BthUsb_ScoAnyTransfer(param_1,'\x01');
  if (uVar2 != '\0') {
    BthUsb_ScoReadStart(param_1);
  }
  KeLowerIrql(uVar1);
  return;
}



===== BthUsb_ScoStopUsbTraffic @ 14000575c =====

/* void __cdecl BthUsb_ScoStopUsbTraffic(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoStopUsbTraffic(_DEVICE_EXTENSION *param_1)

{
  uchar uVar1;
  _DEVICE_EXTENSION *p_Var2;
  
  p_Var2 = param_1;
  uVar1 = BthUsb_ScoAnyTransfer(param_1,'\x01');
  if (uVar1 != '\0') {
    BthUsb_ScoReadStopWait(p_Var2);
  }
  uVar1 = BthUsb_ScoAnyTransfer(param_1,'\0');
  if (uVar1 != '\0') {
    BthUsb_ScoWriteStopWait(param_1);
  }
  return;
}



===== BthUsb_ScoUpdateChannelsInfo @ 140005798 =====

/* void __cdecl BthUsb_ScoUpdateChannelsInfo(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoUpdateChannelsInfo(_DEVICE_EXTENSION *param_1)

{
  ushort uVar1;
  _SCO_USB_CHANNEL *p_Var2;
  longlong lVar3;
  
  uVar1 = (param_1->Sco).NumChannels;
  p_Var2 = (param_1->Sco).Channel;
  lVar3 = 3;
  do {
    if (p_Var2->ConnectionHandle != 0xffff) {
      BthUsb_ScoComputeChannelInfo(param_1,p_Var2,uVar1);
    }
    p_Var2 = p_Var2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== BthUsb_ScoUrbComplete @ 140005804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthUsb_ScoUrbComplete(struct _DEVICE_EXTENSION * __ptr64,struct _SCO_USB_PIPE_OBJ *
   __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64) */

void __cdecl
BthUsb_ScoUrbComplete
          (_DEVICE_EXTENSION *param_1,_SCO_USB_PIPE_OBJ *param_2,_SCO_USB_TRANSFER_CTX *param_3)

{
  _LIST_ENTRY *p_Var1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  _URB *p_Var5;
  _LIST_ENTRY *p_Var6;
  _LIST_ENTRY *p_Var7;
  code *pcVar8;
  uchar uVar9;
  char cVar10;
  longlong lVar11;
  _SCO_USB_TRANSFER_CTX *p_Var12;
  _SCO_USB_TRANSFER_CTX *p_Var13;
  undefined1 local_res10;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffa0;
  byte bVar14;
  undefined1 uVar15;
  
  p_Var5 = param_3->Urb;
  bVar14 = (byte)(p_Var5->field0_0x0).UrbPipeRequest.Reserved & 1;
  p_Var13 = param_3;
  local_res10 = KeAcquireSpinLockRaiseToDpc(&param_2->Lock);
  param_3->Flags = param_3->Flags & 0xfffffffe;
  uVar3 = param_2->Flags;
  if ((uVar3 & 1) != 0) {
    KeReleaseSpinLock(&param_2->Lock,CONCAT31((int3)(uVar3 >> 8),local_res10));
    return;
  }
  p_Var1 = &param_2->InProgressUrbsHead;
  param_2->Flags = uVar3 | 1;
  lVar11 = 0;
  do {
    p_Var6 = p_Var1->Flink;
    p_Var12 = (_SCO_USB_TRANSFER_CTX *)0x0;
    if (p_Var6 == p_Var1) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar10 = '\0';
      }
      else {
        cVar10 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_LP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,p_Var13,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      goto LAB_140005ab2;
    }
    if ((p_Var6->Blink != p_Var1) || (p_Var7 = p_Var6->Flink, p_Var7->Blink != p_Var6)) {
LAB_140005b0d:
      pcVar8 = (code *)swi(0x29);
      (*pcVar8)(3);
      pcVar8 = (code *)swi(3);
      (*pcVar8)();
      return;
    }
    p_Var1->Flink = p_Var7;
    p_Var12 = (_SCO_USB_TRANSFER_CTX *)&p_Var6[-3].Blink;
    p_Var7->Blink = p_Var1;
    p_Var7 = p_Var6[2].Flink;
    uVar15 = (undefined1)lVar11;
    if (((ulonglong)p_Var6[3].Flink & 0x100000000) == 0) {
      uVar3 = *(uint *)&p_Var7[8].Flink;
      p_Var13 = (_SCO_USB_TRANSFER_CTX *)(ulonglong)uVar3;
      uVar4 = (p_Var5->field0_0x0).UrbIsochronousTransfer.StartFrame;
      if (uVar4 < uVar3) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar10 = '\0';
        }
        else {
          cVar10 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_LPLL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,p_Var13,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffff90,100,
                   in_stack_ffffffffffffffa0,bVar14,uVar15,(char)uVar3,(char)uVar4);
      }
      plVar2 = &param_2->InProgressUrbs;
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar10 = '\0';
        }
        else {
          cVar10 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_LPLL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,p_Var13,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffff90,0x65,
                   in_stack_ffffffffffffffa0,bVar14,uVar15,(char)*(undefined4 *)&p_Var7[8].Flink,
                   (char)(p_Var5->field0_0x0).UrbIsochronousTransfer.StartFrame);
        param_2->fNextStartFrame = '\0';
      }
      uVar9 = BthUsb_ScoUrbError(p_Var12,param_2->PipeType);
      if ((uVar9 != '\0') && (param_2->fNextStartFrame != '\0')) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar10 = '\0';
        }
        else {
          cVar10 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_LPLL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,p_Var13,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffff90,0x66,
                   in_stack_ffffffffffffffa0,bVar14,uVar15,(char)*(undefined4 *)&p_Var7[8].Flink,
                   (char)(p_Var5->field0_0x0).UrbIsochronousTransfer.StartFrame);
        param_2->fNextStartFrame = '\0';
      }
      if (p_Var12 == (_SCO_USB_TRANSFER_CTX *)0x0) goto LAB_140005ab2;
    }
    else {
      if ((lVar11 == 0) ||
         (*(uint *)&p_Var7[8].Flink <= (p_Var5->field0_0x0).UrbIsochronousTransfer.StartFrame)) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar10 = '\0';
        }
        else {
          cVar10 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_LPLL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,p_Var13,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffff90,99,
                   in_stack_ffffffffffffffa0,bVar14,uVar15,(char)*(undefined4 *)&p_Var7[8].Flink,
                   (char)(p_Var5->field0_0x0).UrbIsochronousTransfer.StartFrame);
      }
      p_Var7 = p_Var1->Flink;
      if (p_Var7->Blink != p_Var1) goto LAB_140005b0d;
      p_Var6->Flink = p_Var7;
      p_Var12 = (_SCO_USB_TRANSFER_CTX *)0x0;
      p_Var6->Blink = p_Var1;
      p_Var7->Blink = p_Var6;
      p_Var1->Flink = p_Var6;
LAB_140005ab2:
      param_2->Flags = param_2->Flags & 0xfffffffe;
    }
    KeReleaseSpinLock(&param_2->Lock,local_res10);
    if (p_Var12 == (_SCO_USB_TRANSFER_CTX *)0x0) {
      return;
    }
    (*param_2->FnCompleteUrb)(param_1,p_Var12);
    local_res10 = KeAcquireSpinLockRaiseToDpc(&param_2->Lock);
    lVar11 = lVar11 + 1;
  } while( true );
}



===== BthUsb_ScoUrbError @ 140005b1c =====

/* unsigned char __cdecl BthUsb_ScoUrbError(struct _SCO_USB_TRANSFER_CTX * __ptr64,enum
   _BTH_PIPE_TYPE) */

uchar __cdecl BthUsb_ScoUrbError(_SCO_USB_TRANSFER_CTX *param_1,_BTH_PIPE_TYPE param_2)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = '\0';
  uVar1 = (param_1->Irp->IoStatus).field0_0x0.Status;
  if ((int)uVar1 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar2 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_sd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,(ulonglong)uVar1,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  else {
    uVar1 = (param_1->Urb->field0_0x0).UrbHeader.Status;
    if (-1 < (int)uVar1) {
      return '\0';
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar2 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_sD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,(ulonglong)uVar1,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return '\x01';
}



===== BthUsb_ScoUrbStart @ 140005bb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl BthUsb_ScoUrbStart(struct _DEVICE_EXTENSION * __ptr64,struct _SCO_USB_PIPE_OBJ *
   __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64) */

long __cdecl
BthUsb_ScoUrbStart(_DEVICE_EXTENSION *param_1,_SCO_USB_PIPE_OBJ *param_2,
                  _SCO_USB_TRANSFER_CTX *param_3)

{
  ushort uVar1;
  ScoUsbAltSetting *pSVar2;
  _func___cdecl_long__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr *p_Var3;
  code *pcVar4;
  undefined1 uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ScoUsbAltSetting *pSVar9;
  _LIST_ENTRY *p_Var10;
  _LIST_ENTRY *p_Var11;
  char cVar12;
  _LIST_ENTRY *p_Var13;
  char cVar14;
  undefined1 *puVar15;
  ulonglong uVar16;
  uint uVar17;
  ulong local_res10 [2];
  ulong local_res18;
  uint local_res20;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined1 in_stack_ffffffffffffff68;
  undefined7 in_stack_ffffffffffffff69;
  undefined4 in_stack_ffffffffffffff70;
  undefined4 in_stack_ffffffffffffff74;
  undefined *in_stack_ffffffffffffff80;
  
  uVar17 = (param_3->Urb->field0_0x0).UrbPipeRequest.Reserved & 1;
  local_res20 = uVar17;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&param_2->Lock);
  cVar14 = '\0';
  uVar7 = param_2->NextStartFrame;
  local_res18 = uVar7;
  if (param_2->fNextStartFrame == '\0') {
    KeReleaseSpinLock(&param_2->Lock,uVar5);
    uVar8 = 0;
    local_res10[0] = 0;
    lVar6 = (*(param_1->Sco).UsbBusInterface.QueryBusTime)
                      ((param_1->Sco).UsbBusInterface.BusContext,local_res10);
    if (lVar6 < 0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
         (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar12 = '\0';
      }
      in_stack_ffffffffffffff80 = &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids;
      in_stack_ffffffffffffff70 = 5;
      in_stack_ffffffffffffff68 = 2;
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x21,
                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)lVar6);
    }
    else {
      uVar8 = local_res10[0];
    }
    uVar1 = param_2->Id;
    uVar16 = (ulonglong)uVar1;
    uVar7 = (*param_2->FnAlignFrame)(param_1,param_3,uVar1,uVar8 + 4);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
       (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar12 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_LLLL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,uVar16,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT71(in_stack_ffffffffffffff69,in_stack_ffffffffffffff68),
               CONCAT44(in_stack_ffffffffffffff74,in_stack_ffffffffffffff70),0x60,
               in_stack_ffffffffffffff80,(char)uVar17,(char)uVar8,(char)uVar8 + '\x04',(char)uVar7);
    uVar5 = KeAcquireSpinLockRaiseToDpc(&param_2->Lock);
    local_res10[0] = CONCAT31(local_res10[0]._1_3_,uVar5);
    if (0 < param_2->InProgressUrbs) {
      pSVar2 = (param_1->Sco).UsbAltSetting;
      pSVar9 = (ScoUsbAltSetting *)&pSVar2->MAX_PENDING_READ_REQS_SPAN;
      if (local_res20 == 0) {
        pSVar9 = pSVar2;
      }
      if ((local_res18 - uVar7) * 1000 <= pSVar9->MAX_PENDING_WRITE_REQS_SPAN) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
           (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar12 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_LdLLL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,&param_2->Id,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        uVar7 = local_res18;
      }
    }
    uVar5 = (undefined1)local_res10[0];
  }
  else {
  }
  uVar8 = (*param_2->FnGetNextFrame)(param_1,param_3,param_2->Id,uVar7);
  param_2->NextStartFrame = uVar8;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    cVar14 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_LL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar14,WPP_GLOBAL_Control,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffff69,in_stack_ffffffffffffff68),5,0x62,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)uVar7,(char)uVar8);
  puVar15 = auStackY_b8;
  param_2->fNextStartFrame = '\x01';
  p_Var11 = &param_2->InProgressUrbsHead;
  param_3->Flags = param_3->Flags | 1;
  p_Var10 = &param_3->ListEntry;
  p_Var13 = (param_2->InProgressUrbsHead).Blink;
  if (p_Var13->Flink != p_Var11) {
    p_Var11 = (_LIST_ENTRY *)0x3;
    pcVar4 = (code *)swi(0x29);
    p_Var10 = (_LIST_ENTRY *)(*pcVar4)();
    puVar15 = auStackY_b0;
  }
  p_Var10->Flink = p_Var11;
  p_Var10->Blink = p_Var13;
  p_Var13->Flink = p_Var10;
  p_Var11->Blink = p_Var10;
  param_2->InProgressUrbs = param_2->InProgressUrbs + 1;
  *(undefined8 *)(puVar15 + -8) = 0x140005e65;
  KeReleaseSpinLock(&param_2->Lock,uVar5);
  (param_3->Urb->field0_0x0).UrbIsochronousTransfer.StartFrame = uVar7;
  p_Var3 = param_2->FnSendUrb;
  *(undefined8 *)(puVar15 + -8) = 0x140005e82;
  (*p_Var3)(param_1,param_3);
  return 0x103;
}



===== BthUsb_ScoValidateAndAdjustBandwidth @ 140005eac =====

/* long __cdecl BthUsb_ScoValidateAndAdjustBandwidth(struct _DEVICE_EXTENSION * __ptr64,unsigned
   long * __ptr64) */

long __cdecl BthUsb_ScoValidateAndAdjustBandwidth(_DEVICE_EXTENSION *param_1,ulong *param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  long lVar4;
  uint uVar5;
  undefined8 in_R8;
  ulonglong uVar6;
  
  lVar4 = -0x3ffffff3;
  cVar3 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_qd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x24,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_1,(char)*param_2);
  uVar1 = *param_2;
  uVar6 = (ulonglong)uVar1;
  if ((uVar1 == 0) ||
     (uVar5 = ((uVar1 + 999) / 1000) * 1000, uVar6 = (ulonglong)uVar5, uVar1 <= uVar5)) {
    uVar5 = (uint)uVar6;
    if (((param_1->Sco).MaxBandwidth < uVar5) || (uVar5 != (int)(uVar6 / 1000) * 1000)) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar2 = '\0';
      }
      else {
        cVar2 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_dd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,uVar6,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x26,
                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)uVar1,(char)uVar6);
    }
    else {
      *param_2 = uVar5;
      lVar4 = 0;
    }
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,uVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x25,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)uVar1);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,uVar6,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x27,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)lVar4);
  return lVar4;
}



===== BthUsb_ScoValidateChnInfo @ 14000606c =====

/* long __cdecl BthUsb_ScoValidateChnInfo(struct _DEVICE_EXTENSION * __ptr64,unsigned long *
   __ptr64,unsigned long * __ptr64) */

long __cdecl BthUsb_ScoValidateChnInfo(_DEVICE_EXTENSION *param_1,ulong *param_2,ulong *param_3)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  char cVar4;
  ulong *puVar5;
  undefined8 uVar6;
  ulong local_res10 [2];
  ulong local_res18 [2];
  undefined1 in_stack_ffffffffffffff98;
  undefined7 in_stack_ffffffffffffff99;
  undefined2 uVar7;
  undefined1 uVar8;
  ulong uVar9;
  
  cVar4 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  puVar5 = param_3;
  WPP_RECORDER_AND_TRACE_SF_qdd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,param_3,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffff99,in_stack_ffffffffffffff98),4,0x28,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_1,(char)*param_2,
             (char)*param_3);
  local_res10[0] = *param_2;
  local_res18[0] = *param_3;
  lVar1 = BthUsb_ScoValidateAndAdjustBandwidth(param_1,local_res10);
  if (lVar1 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar8 = (undefined1)*param_2;
    uVar7 = 0x29;
    puVar5 = (ulong *)WPP_GLOBAL_Control;
    uVar9 = local_res10[0];
  }
  else {
    lVar1 = BthUsb_ScoValidateAndAdjustBandwidth(param_1,local_res18);
    if (-1 < lVar1) {
      if ((local_res18[0] == 0) && (local_res10[0] == 0)) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar3 = '\0';
        }
        else {
          cVar3 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,puVar5,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x2b,
                   &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
        lVar1 = -0x3ffffff3;
      }
      else {
        *param_2 = local_res10[0];
        lVar1 = 0;
        *param_3 = local_res18[0];
      }
      goto LAB_14000621d;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar8 = (undefined1)*param_3;
    uVar7 = 0x2a;
    uVar9 = local_res18[0];
  }
  WPP_RECORDER_AND_TRACE_SF_dd
            (uVar2,cVar3,puVar5,uVar6,2,4,uVar7,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
             uVar8,(char)uVar9);
LAB_14000621d:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,puVar5,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x2c,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)lVar1);
  return lVar1;
}



===== IsAlignDataCapable @ 140006280 =====

byte IsAlignDataCapable(longlong param_1)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = '\x01';
  if ((*(int *)(param_1 + 0x2a0) == 0x3f) && (*(char *)(param_1 + 0x495) == '\0')) {
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_Lll
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,(ulonglong)bVar2,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  return bVar2;
}



===== WPP_RECORDER_AND_TRACE_SF_DDLLLL @ 1400062f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DDLLLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x39,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,0);
  }
  WppAutoLogTrace(param_4,4,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x39,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_DL @ 140006424 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0xb,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_4,4,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0xb,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_L @ 1400064dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_L
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LL @ 140006590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_4,4,param_6,param_8,param_7,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LLL @ 140006654 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,&param_10,4,&param_11,4,0);
  }
  WppAutoLogTrace(param_4,4,param_6,param_8,param_7,&param_9,4,&param_10,4,&param_11,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LLLL @ 140006734 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LLLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,param_7,&param_9,4,
               &param_10,4,&param_11,4,&param_12,4,0);
  }
  WppAutoLogTrace(param_4,4,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,param_7,&param_9,4,
                  &param_10,4,&param_11,4,&param_12,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LP @ 140006830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LP
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x67,
               &uStack0000000000000048,4,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_4,4,5,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x67,
                  &uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LPLL @ 1400068f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LPLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,param_7,&param_9,4,
               &param_10,8,&param_11,4,&param_12,4,0);
  }
  WppAutoLogTrace(param_4,param_5,5,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,param_7,
                  &param_9,4,&param_10,8,&param_11,4,&param_12,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LdLLL @ 1400069fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LdLLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x61,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  WppAutoLogTrace(param_4,4,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x61,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_Lll @ 140006b14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_Lll
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,10,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,4,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,10,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_S @ 140006be8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_S
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000048;
  
  lVar4 = -1;
  lVar3 = 10;
  if (param_2 != '\0') {
    if (in_stack_00000048 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000048[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000048;
    if (in_stack_00000048 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x2e,pwVar2,lVar1,0);
  }
  if (in_stack_00000048 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000048[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000048 == (wchar_t *)0x0) {
    in_stack_00000048 = L"NULL";
  }
  WppAutoLogTrace(param_4,4,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x2e,
                  in_stack_00000048,lVar3,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_dd @ 140006cfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_dd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_lL @ 140006dc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_lL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x41,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_4,4,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x41,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qH @ 140006e7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qH
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,2,0);
  }
  WppAutoLogTrace(param_4,4,param_6,param_8,param_7,&param_9,8,&param_10,2,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qdd @ 140006f48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qdd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,4,&param_11,4,0);
  }
  WppAutoLogTrace(param_4,4,param_6,param_8,param_7,&param_9,8,&param_10,4,&param_11,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_sD @ 140007030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_sD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *in_stack_00000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    if (in_stack_00000048 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000048[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x1c,pcVar3,lVar2,
               &uStack0000000000000050,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000048 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000048[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = "NULL";
  }
  WppAutoLogTrace(param_4,2,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x1c,
                  in_stack_00000048,lVar1,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_sd @ 140007164 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_sd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *in_stack_00000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    if (in_stack_00000048 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000048[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x1b,pcVar3,lVar2,
               &uStack0000000000000050,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000048 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000048[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = "NULL";
  }
  WppAutoLogTrace(param_4,2,4,&WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,0x1b,
                  in_stack_00000048,lVar1,&uStack0000000000000050,4,0);
  return;
}



===== AllocReadTransferCtxImpl @ 140007298 =====

void AllocReadTransferCtxImpl(_DEVICE_EXTENSION *param_1,ulong param_2,_LIST_ENTRY *param_3)

{
  ulong uVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffb8;
  
  uVar1 = ((param_1->Sco).UsbAltSetting)->READ_FRAMES_X_REQ;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_LLL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,param_3,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,0xb,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,(char)param_2,(char)uVar1,2);
  BthUsb_ScoAllocTransferContextsImpl
            (param_1,param_2,uVar1,0x102,&(param_1->Sco).ReadCtxQueue,param_3);
  return;
}



===== BthUsbAltSetting6_ScoAllocReadTransferCtxImpl @ 140007360 =====

/* long __cdecl BthUsbAltSetting6_ScoAllocReadTransferCtxImpl(void * __ptr64,struct _LIST_ENTRY *
   __ptr64) */

long __cdecl BthUsbAltSetting6_ScoAllocReadTransferCtxImpl(void *param_1,_LIST_ENTRY *param_2)

{
  long lVar1;
  
  lVar1 = AllocReadTransferCtxImpl
                    (param_1,*(ulong *)(*(longlong *)((longlong)param_1 + 0x478) + 0x4c),param_2);
  return lVar1;
}



===== BthUsbAltSetting6_ScoProcessReadUrb @ 140007390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthUsbAltSetting6_ScoProcessReadUrb(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64,unsigned char * __ptr64)
    */

void __cdecl
BthUsbAltSetting6_ScoProcessReadUrb
          (_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2,_SCO_USB_TRANSFER_CTX *param_3,
          uchar *param_4)

{
  ulong uVar1;
  _URB *p_Var2;
  ushort *puVar3;
  void *pvVar4;
  ulong64 uVar5;
  _LIST_ENTRY *p_Var6;
  uint uVar7;
  uchar *puVar8;
  _SCO_USB_CHANNEL *p_Var9;
  undefined1 uVar10;
  char cVar11;
  ushort uVar12;
  ulonglong uVar13;
  uint uVar14;
  ushort uVar15;
  _SCO_USB_TRANSFER_CTX *p_Var16;
  undefined8 in_stack_ffffffffffffff68;
  undefined8 in_stack_ffffffffffffff70;
  undefined2 uVar17;
  undefined8 in_stack_ffffffffffffff80;
  undefined1 uVar18;
  ulonglong local_48;
  longlong lStack_40;
  _func___cdecl_void__REF_OBJ_ptr *local_38;
  _REF_OBJ_DEBUG_INFO *p_Stack_30;
  _RESOURCE_QUEUE *local_28;
  _LIST_ENTRY *p_Stack_20;
  
  *param_4 = '\0';
  p_Var2 = param_3->Urb;
  uVar14 = 0;
  uVar7 = (p_Var2->field0_0x0).UrbIsochronousTransfer.NumberOfPackets;
  p_Var16 = param_3;
  if (uVar7 != 0) {
    do {
      uVar10 = (undefined1)uVar7;
      uVar1 = (p_Var2->field0_0x0).UrbIsochronousTransfer.StartFrame;
      uVar7 = (p_Var2->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar14].Status;
      if ((int)uVar7 < 0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
           (p_Var16 = (_SCO_USB_TRANSFER_CTX *)CONCAT71((int7)((ulonglong)p_Var16 >> 8),1),
           (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          p_Var16 = (_SCO_USB_TRANSFER_CTX *)((ulonglong)p_Var16 & 0xffffffffffffff00);
        }
        uVar18 = (undefined1)(p_Var2->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar14].Length;
        cVar11 = (char)p_Var16;
        uVar17 = 0x25;
LAB_140007434:
        WPP_RECORDER_AND_TRACE_SF_LLLLD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,p_Var16,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,
                   in_stack_ffffffffffffff70,uVar17,in_stack_ffffffffffffff80,(char)uVar14,uVar10,
                   (char)uVar1 + (char)uVar14,uVar18,(char)uVar7);
      }
      else {
        puVar8 = param_3->TransferBuffer +
                 (p_Var2->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar14].Offset;
        uVar7 = (p_Var2->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar14].Length;
        p_Var16 = (_SCO_USB_TRANSFER_CTX *)(ulonglong)uVar7;
        if (uVar7 != 0) {
          if (uVar7 == 0x3f) {
            p_Var16 = param_3->AuxiliaryBuffer;
            if ((p_Var16 != (_SCO_USB_TRANSFER_CTX *)0x0) && (0x3e < param_3->AuxBufferLen)) {
              pvVar4 = *(void **)(puVar8 + 8);
              uVar13 = 0;
              *(undefined8 *)p_Var16 = *(undefined8 *)puVar8;
              (((_BTH_SCO_MP_INDICATION_PARAMETERS_u_8 *)&p_Var16->RefObj)->Read).BufferData =
                   pvVar4;
              uVar5 = *(ulong64 *)(puVar8 + 0x18);
              *(undefined8 *)
               &(((_BTH_SCO_MP_INDICATION_PARAMETERS_u_8 *)&p_Var16->RefObj)->Read).DataLen =
                   *(undefined8 *)(puVar8 + 0x10);
              (((_BTH_SCO_MP_INDICATION_PARAMETERS_u_8 *)&p_Var16->RefObj)->Read).DataTag = uVar5;
              p_Var6 = *(_LIST_ENTRY **)(puVar8 + 0x28);
              p_Var16->CtxQueue = *(_RESOURCE_QUEUE **)(puVar8 + 0x20);
              (p_Var16->ListEntry).Flink = p_Var6;
              (p_Var16->ListEntry).Blink = *(_LIST_ENTRY **)(puVar8 + 0x30);
              *(undefined4 *)&p_Var16->DevExt = *(undefined4 *)(puVar8 + 0x38);
              *(undefined2 *)((longlong)&p_Var16->DevExt + 4) = *(undefined2 *)(puVar8 + 0x3c);
              *(uchar *)((longlong)&p_Var16->DevExt + 6) = puVar8[0x3e];
              puVar3 = param_3->AuxiliaryBuffer;
              uVar15 = *puVar3 & 0xfff;
              p_Var16 = (_SCO_USB_TRANSFER_CTX *)(ulonglong)uVar15;
              do {
                p_Var9 = (param_1->Sco).Channel + uVar13;
                if (p_Var9->ConnectionHandle == uVar15) {
                  if (p_Var9 != (_SCO_USB_CHANNEL *)0x0) {
                    p_Var16 = (_SCO_USB_TRANSFER_CTX *)&local_48;
                    local_48 = (ulonglong)p_Var9->ConnectionHandle;
                    lStack_40 = (longlong)puVar3 + 3;
                    local_38 = (_func___cdecl_void__REF_OBJ_ptr *)(ulonglong)(byte)puVar3[1];
                    local_28 = (_RESOURCE_QUEUE *)0x0;
                    p_Stack_20 = (_LIST_ENTRY *)0x0;
                    p_Stack_30 = (_REF_OBJ_DEBUG_INFO *)0x0;
                    (*p_Var9->Callback)(p_Var9->CallbackContext,ScoMpIndicationRead,
                                        (_BTH_SCO_MP_INDICATION_PARAMETERS *)p_Var16);
                    goto LAB_140007632;
                  }
                  break;
                }
                uVar12 = (short)uVar13 + 1;
                uVar13 = (ulonglong)uVar12;
              } while (uVar12 < 3);
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                 (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                cVar11 = '\0';
              }
              uVar7 = (uint)uVar15;
              uVar18 = (undefined1)
                       (p_Var2->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar14].Length;
              uVar10 = (undefined1)(p_Var2->field0_0x0).UrbIsochronousTransfer.NumberOfPackets;
              uVar17 = 0x28;
              goto LAB_140007434;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
               (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar11 = '\0';
            }
            WPP_RECORDER_AND_TRACE_SF_LLLLqL
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,p_Var16,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          else {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
               (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar11 = '\0';
            }
            WPP_RECORDER_AND_TRACE_SF_LLLLL
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,p_Var16,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
      }
LAB_140007632:
      uVar7 = (p_Var2->field0_0x0).UrbIsochronousTransfer.NumberOfPackets;
      uVar14 = uVar14 + 1;
    } while (uVar14 < uVar7);
  }
  return;
}



===== BthUsb_ScoAllocReadTransferCtxImpl @ 140007670 =====

/* long __cdecl BthUsb_ScoAllocReadTransferCtxImpl(void * __ptr64,struct _LIST_ENTRY * __ptr64) */

long __cdecl BthUsb_ScoAllocReadTransferCtxImpl(void *param_1,_LIST_ENTRY *param_2)

{
  long lVar1;
  
  lVar1 = AllocReadTransferCtxImpl
                    (param_1,*(int *)(*(longlong *)((longlong)param_1 + 0x478) + 0x4c) + 2,param_2);
  return lVar1;
}



===== BthUsb_ScoFreePartialUsbCtx @ 140007698 =====

/* void __cdecl BthUsb_ScoFreePartialUsbCtx(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoFreePartialUsbCtx(_DEVICE_EXTENSION *param_1)

{
  ulong64 *puVar1;
  _SCO_USB_TRANSFER_CTX *p_Var2;
  undefined1 uVar3;
  char cVar4;
  undefined8 in_R8;
  
  puVar1 = &(param_1->Sco).ReadLock;
  uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1);
  p_Var2 = (param_1->Sco).PartialReadCtx;
  cVar4 = '\0';
  (param_1->Sco).PartialReadCtx = (_SCO_USB_TRANSFER_CTX *)0x0;
  KeReleaseSpinLock(puVar1,uVar3);
  if (p_Var2 != (_SCO_USB_TRANSFER_CTX *)0x0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      cVar4 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,in_R8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,10,
               &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,(char)p_Var2);
    RefObj_ReleaseEx((int *)&p_Var2->RefObj,(longlong)p_Var2,0x6d,
                     "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbread.cpp");
    BthUsb_ScoReadData(param_1,1);
  }
  return;
}



===== BthUsb_ScoFreeReadResources @ 14000777c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthUsb_ScoFreeReadResources(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoFreeReadResources(_DEVICE_EXTENSION *param_1)

{
  char cVar1;
  char cVar2;
  undefined8 in_R8;
  
  BthUsb_ScoFreePartialUsbCtx(param_1);
  cVar2 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xd,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  ResourceQueue_StopAndWait(&(param_1->Sco).ReadCtxQueue.AbortStatus);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xe,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  (*(param_1->Sco).ReadCtxQueue.FnDestroyItems)
            ((param_1->Sco).ReadCtxQueue.ContextFn,&(param_1->Sco).ReadCtxQueue.ListEntry);
  return;
}



===== BthUsb_ScoInitReadResources @ 140007858 =====

/* long __cdecl BthUsb_ScoInitReadResources(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthUsb_ScoInitReadResources(_DEVICE_EXTENSION *param_1)

{
  int iVar1;
  _DEVICE_EXTENSION *p_Var2;
  char cVar3;
  undefined8 in_R8;
  
  cVar3 = '\0';
  (param_1->Sco).ReadsEnabled = '\0';
  p_Var2 = (_DEVICE_EXTENSION *)&(param_1->Sco).ReadCtxQueue;
  iVar1 = ResourceQueue_Initialize
                    ((undefined4 *)p_Var2,((param_1->Sco).UsbAltSetting)->AllocReadTransferCtxImpl);
  if (iVar1 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar3 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,in_R8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xc,
               &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
    BthUsb_ScoFreeReadResources(param_1);
  }
  else {
    BthUsb_ScoPipeObjInit
              (p_Var2,&(param_1->Sco).ReadPipeObj,READ_SCO_PIPE,0,BthUsb_ScoReadUrbSend,
               BthUsb_ScoReadUrbDone,BthUsb_ScoReadAlignFrame,BthUsb_ScoReadNextFrame);
    iVar1 = 0;
  }
  return iVar1;
}



===== BthUsb_ScoIsPacketInFrames @ 140007944 =====

/* unsigned char __cdecl BthUsb_ScoIsPacketInFrames(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_HCIPACKET_FRAME * __ptr64) */

uchar __cdecl BthUsb_ScoIsPacketInFrames(_DEVICE_EXTENSION *param_1,_SCO_HCIPACKET_FRAME *param_2)

{
  uint uVar1;
  uint uVar2;
  _SCO_HCIPACKET_FRAME *p_Var3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  _SCO_USB_CHANNEL *p_Var7;
  undefined2 uVar8;
  
  uVar1 = *(uint *)(param_2 + 8);
  uVar2 = ((param_1->Sco).UsbAltSetting)->FRAMES_X_HCIPACKET;
  cVar4 = '\x01';
  uVar6 = 1;
  if (1 < uVar2) {
    p_Var3 = param_2 + 0x18;
    do {
      if ((*(uint *)p_Var3 == 0) || (uVar1 != *(uint *)p_Var3)) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar4 = '\0';
        }
        uVar8 = 0x21;
        goto LAB_1400079f1;
      }
      uVar6 = uVar6 + 1;
      p_Var3 = p_Var3 + 0x10;
    } while (uVar6 < uVar2);
  }
  if (uVar2 * uVar1 < 3) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
       ) {
      cVar4 = '\0';
    }
    uVar8 = 0x22;
  }
  else if (uVar1 < 3) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
       ) {
      cVar4 = '\0';
    }
    uVar8 = 0x23;
  }
  else {
    if (uVar2 * uVar1 - 3 == (uint)(byte)(*(ushort **)param_2)[1]) {
      uVar5 = 0;
      do {
        p_Var7 = (param_1->Sco).Channel + uVar5;
        if (p_Var7->ConnectionHandle == (**(ushort **)param_2 & 0xfff)) {
          if (p_Var7 == (_SCO_USB_CHANNEL *)0x0) {
            return '\0';
          }
          return '\x01';
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 3);
      return '\0';
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
       ) {
      cVar4 = '\0';
    }
    uVar8 = 0x24;
  }
LAB_1400079f1:
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,(ulonglong)uVar1,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,uVar8,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  return '\0';
}



===== BthUsb_ScoProcessReadUrb @ 140007ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthUsb_ScoProcessReadUrb(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64,unsigned char * __ptr64)
    */

void __cdecl
BthUsb_ScoProcessReadUrb
          (_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2,_SCO_USB_TRANSFER_CTX *param_3,
          uchar *param_4)

{
  _SCO_DATA_PACKET *p_Var1;
  _SCO_USB_CHANNEL *p_Var2;
  ushort uVar3;
  ulong local_48 [2];
  _BTH_SCO_MP_INDICATION_PARAMETERS local_40;
  
  local_48[0] = 0;
  do {
    p_Var1 = BthUsb_ScoReconstructReadPackets(param_1,param_2,param_3,local_48,param_4);
    if (p_Var1 == (_SCO_DATA_PACKET *)0x0) {
      return;
    }
    uVar3 = 0;
    do {
      p_Var2 = (param_1->Sco).Channel + uVar3;
      if (p_Var2->ConnectionHandle == (*(ushort *)p_Var1 & 0xfff)) {
        if (p_Var2 != (_SCO_USB_CHANNEL *)0x0) {
          local_40._2_6_ = 0;
          local_40.ConnectionHandle = p_Var2->ConnectionHandle;
          local_40.field1_0x8.Read.BufferData = p_Var1 + 3;
          local_40.field1_0x8._9_7_ = 0;
          local_40.field1_0x8.Read.DataLen._0_1_ = p_Var1[2];
          local_40.field1_0x8._24_8_ = 0;
          local_40.field1_0x8.WriteComplete.DataTag = 0;
          local_40.field1_0x8.Read.DataTag = 0;
          (*p_Var2->Callback)(p_Var2->CallbackContext,ScoMpIndicationRead,&local_40);
        }
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 3);
  } while( true );
}



===== BthUsb_ScoReadAlignFrame @ 140007be0 =====

/* unsigned long __cdecl BthUsb_ScoReadAlignFrame(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64,unsigned short,unsigned long) */

ulong __cdecl
BthUsb_ScoReadAlignFrame
          (_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2,ushort param_3,ulong param_4)

{
  ulong64 *puVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = &(param_1->Sco).ReadLock;
  KeAcquireSpinLockRaiseToDpc(puVar1);
  uVar2 = (param_1->Sco).ReadLastFrame;
  KeReleaseSpinLock(puVar1);
  uVar3 = ((param_1->Sco).UsbAltSetting)->READ_FRAMES_X_REQ;
  uVar4 = (param_4 - uVar2) % uVar3;
  if (uVar4 != 0) {
    param_4 = param_4 + (uVar3 - uVar4);
  }
  return param_4;
}



===== BthUsb_ScoReadData @ 140007c60 =====

/* long __cdecl BthUsb_ScoReadData(struct _DEVICE_EXTENSION * __ptr64,unsigned long) */

long __cdecl BthUsb_ScoReadData(_DEVICE_EXTENSION *param_1,ulong param_2)

{
  ushort uVar1;
  uint uVar2;
  _URB *p_Var3;
  _MDL *p_Var4;
  uint uVar5;
  _SCO_USB_TRANSFER_CTX *p_Var6;
  _USBD_ISO_PACKET_DESCRIPTOR *p_Var7;
  uint uVar8;
  ulong uVar9;
  ulonglong uVar10;
  
  uVar8 = 0;
  if (param_2 != 0) {
    do {
      p_Var6 = (_SCO_USB_TRANSFER_CTX *)
               ResourceQueue_GetItem(&(param_1->Sco).ReadCtxQueue.AbortStatus);
      if (p_Var6 == (_SCO_USB_TRANSFER_CTX *)0x0) {
        return 0x103;
      }
      p_Var3 = p_Var6->Urb;
      uVar9 = 0;
      uVar2 = p_Var6->UrbFrames;
      p_Var6->DevExt = param_1;
      p_Var6->IndexPipe = READ_SCO_PIPE;
      if (uVar2 != 0) {
        uVar10 = (ulonglong)uVar2;
        p_Var7 = (p_Var3->field0_0x0).UrbIsochronousTransfer.IsoPacket;
        do {
          p_Var7->Offset = uVar9;
          uVar1 = param_1->Pipes[3].MaximumPacketSize;
          p_Var7->Status = 0;
          uVar5 = (uint)uVar1;
          uVar9 = uVar9 + uVar5;
          p_Var7->Length = uVar5;
          uVar10 = uVar10 - 1;
          p_Var7 = p_Var7 + 1;
        } while (uVar10 != 0);
      }
      (p_Var3->field0_0x0).UrbHeader.Status = 0;
      (p_Var3->field0_0x0).UrbHeader.UsbdDeviceHandle = (void *)0x0;
      (p_Var3->field0_0x0).UrbHeader.UsbdFlags = 0;
      (p_Var3->field0_0x0).UrbHeader.Function = 10;
      (p_Var3->field0_0x0).UrbHeader.Length = (short)uVar2 * 0xc + 0x98;
      (p_Var3->field0_0x0).UrbSelectInterface.ConfigurationHandle = param_1->Pipes[3].PipeHandle;
      (p_Var3->field0_0x0).UrbPipeRequest.Reserved = 3;
      (p_Var3->field0_0x0).UrbControlTransfer.TransferBufferLength = uVar9;
      (p_Var3->field0_0x0).UrbSelectInterface.Interface.InterfaceHandle = p_Var6->TransferBuffer;
      p_Var4 = p_Var6->TransferMdl;
      (p_Var3->field0_0x0).UrbControlTransfer.UrbLink = (_URB *)0x0;
      (p_Var3->field0_0x0).UrbIsochronousTransfer.StartFrame = 0;
      (p_Var3->field0_0x0).UrbIsochronousTransfer.ErrorCount = 0;
      (p_Var3->field0_0x0).UrbSelectConfiguration.Interface.InterfaceHandle = p_Var4;
      (p_Var3->field0_0x0).UrbIsochronousTransfer.NumberOfPackets = uVar2;
      BthUsb_ScoUrbStart(param_1,&(param_1->Sco).ReadPipeObj,p_Var6);
      uVar8 = uVar8 + 1;
    } while (uVar8 < param_2);
  }
  return 0x103;
}



===== BthUsb_ScoReadNextFrame @ 140007d90 =====

/* unsigned long __cdecl BthUsb_ScoReadNextFrame(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64,unsigned short,unsigned long) */

ulong __cdecl
BthUsb_ScoReadNextFrame
          (_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2,ushort param_3,ulong param_4)

{
  return ((param_1->Sco).UsbAltSetting)->READ_FRAMES_X_REQ + param_4;
}



===== BthUsb_ScoReadStart @ 140007da8 =====

/* long __cdecl BthUsb_ScoReadStart(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthUsb_ScoReadStart(_DEVICE_EXTENSION *param_1)

{
  ulong64 *puVar1;
  undefined1 uVar2;
  char cVar3;
  undefined8 in_RDX;
  undefined7 uVar4;
  char cVar5;
  undefined8 in_R8;
  
  cVar5 = '\x01';
  uVar4 = (undefined7)((ulonglong)in_RDX >> 8);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xf,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  puVar1 = &(param_1->Sco).ReadLock;
  uVar2 = KeAcquireSpinLockRaiseToDpc(puVar1);
  (param_1->Sco).ReadsEnabled = '\x01';
  KeReleaseSpinLock(puVar1,CONCAT71(uVar4,uVar2));
  ResourceQueue_Start(&(param_1->Sco).ReadCtxQueue.AbortStatus);
  BthUsb_ScoReadData(param_1,((param_1->Sco).UsbAltSetting)->MAX_PENDING_READS);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x10,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  return 0;
}



===== BthUsb_ScoReadStop @ 140007eb8 =====

/* void __cdecl BthUsb_ScoReadStop(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoReadStop(_DEVICE_EXTENSION *param_1)

{
  ulong64 *puVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  undefined8 in_R8;
  
  cVar4 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x11,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  puVar1 = &(param_1->Sco).ReadLock;
  uVar2 = KeAcquireSpinLockRaiseToDpc(puVar1);
  (param_1->Sco).ReadsEnabled = '\0';
  KeReleaseSpinLock(puVar1,uVar2);
  ResourceQueue_Stop(&(param_1->Sco).ReadCtxQueue.AbortStatus);
  BthUsb_ScoFreePartialUsbCtx(param_1);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x12,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  return;
}



===== BthUsb_ScoReadStopWait @ 140007fbc =====

/* void __cdecl BthUsb_ScoReadStopWait(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoReadStopWait(_DEVICE_EXTENSION *param_1)

{
  ulong64 *puVar1;
  _RESOURCE_QUEUE *p_Var2;
  undefined1 uVar3;
  long lVar4;
  char cVar5;
  undefined2 in_DX;
  undefined1 uVar7;
  ushort uVar6;
  char cVar8;
  undefined8 in_R8;
  undefined *puVar9;
  undefined8 uVar10;
  
  cVar8 = '\x01';
  uVar7 = (undefined1)((ushort)in_DX >> 8);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,in_R8,uVar10,4,4,0x13,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  lVar4 = (long)uVar10;
  puVar1 = &(param_1->Sco).ReadLock;
  uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1);
  (param_1->Sco).ReadsEnabled = '\0';
  uVar6 = CONCAT11(uVar7,uVar3);
  KeReleaseSpinLock(puVar1);
  p_Var2 = &(param_1->Sco).ReadCtxQueue;
  ResourceQueue_Stop(&p_Var2->AbortStatus);
  puVar9 = param_1->Pipes[3].PipeHandle;
  lVar4 = BthUsb_PipeRequest(param_1,uVar6,puVar9,lVar4);
  if (lVar4 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    puVar9 = WPP_GLOBAL_Control;
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x14,
               &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,(char)lVar4);
  }
  BthUsb_ScoFreePartialUsbCtx(param_1);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,puVar9,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x15,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  ResourceQueue_StopAndWait(&p_Var2->AbortStatus);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar8 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,puVar9,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x16,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
  return;
}



===== BthUsb_ScoReadTransferCallback @ 140008170 =====

/* long __cdecl BthUsb_ScoReadTransferCallback(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl BthUsb_ScoReadTransferCallback(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int *piVar1;
  _DEVICE_EXTENSION *p_Var2;
  
  p_Var2 = *(_DEVICE_EXTENSION **)((longlong)param_3 + 0x38);
  piVar1 = (int *)((longlong)param_3 + 8);
  LOCK();
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (*(longlong *)((longlong)param_3 + 0x18) != 0) {
    RefObj_AddTrackingBlock
              ((longlong)piVar1,0x330,
               "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbread.cpp",
               BthUsb_ScoReadTransferCallback);
  }
  BthUsb_ScoUrbComplete(p_Var2,&(p_Var2->Sco).ReadPipeObj,param_3);
  RefObj_ReleaseEx(piVar1,0x140008170,0x332,
                   "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbread.cpp");
  return -0x3fffffea;
}



===== BthUsb_ScoReadUrbDone @ 140008200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl BthUsb_ScoReadUrbDone(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64) */

long __cdecl BthUsb_ScoReadUrbDone(_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2)

{
  ulong64 *puVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  _SCO_USB_TRANSFER_CTX *p_Var5;
  undefined1 uVar6;
  uchar uVar7;
  char cVar8;
  char cVar9;
  undefined8 in_R8;
  _SCO_USB_TRANSFER_CTX *p_Var10;
  _IRP *p_Var11;
  uchar local_res8 [8];
  _BTH_PIPE_TYPE local_res10;
  _IRP *local_res18;
  _SCO_USB_TRANSFER_CTX *local_res20;
  undefined1 in_stack_ffffffffffffff78;
  undefined7 in_stack_ffffffffffffff79;
  undefined1 uVar12;
  
  cVar9 = '\0';
  local_res8[0] = '\0';
  local_res10 = param_2->IndexPipe;
  local_res18 = param_2->Irp;
  uVar2 = (param_2->Urb->field0_0x0).UrbControlTransfer.TransferBufferLength;
  uVar3 = (param_2->Urb->field0_0x0).UrbIsochronousTransfer.StartFrame;
  local_res20 = (_SCO_USB_TRANSFER_CTX *)0x0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
     (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar8 = '\0';
  }
  uVar12 = (undefined1)uVar3;
  WPP_RECORDER_AND_TRACE_SF_LLL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),5,0x18,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,uVar12,(char)uVar2,
             (char)param_2->BufferLen);
  puVar1 = &(param_1->Sco).ReadLock;
  uVar6 = KeAcquireSpinLockRaiseToDpc(puVar1);
  p_Var5 = (param_1->Sco).PartialReadCtx;
  (param_1->Sco).PartialReadCtx = (_SCO_USB_TRANSFER_CTX *)0x0;
  KeReleaseSpinLock(puVar1,uVar6);
  uVar7 = BthUsb_ScoUrbError(param_2,local_res10);
  p_Var11 = local_res18;
  if (uVar7 == '\0') {
    if (uVar2 != 0) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(puVar1);
      (param_1->Sco).ReadLastFrame = uVar3;
      (param_1->Sco).ReadLastPipeId = 0;
      KeReleaseSpinLock(puVar1,uVar6);
      p_Var10 = local_res20;
      if (p_Var5 != (_SCO_USB_TRANSFER_CTX *)0x0) {
        uVar4 = (p_Var5->Urb->field0_0x0).UrbIsochronousTransfer.StartFrame;
        p_Var10 = p_Var5;
        if (uVar3 != ((param_1->Sco).UsbAltSetting)->READ_FRAMES_X_REQ + uVar4) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
             (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar8 = '\0';
          }
          WPP_RECORDER_AND_TRACE_SF_dd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,(ulonglong)uVar4,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1a,
                     &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,(char)uVar4,uVar12);
          p_Var10 = local_res20;
        }
      }
      local_res20 = p_Var10;
      p_Var10 = param_2;
      (*((param_1->Sco).UsbAltSetting)->ProcessReadUrb)(param_1,local_res20,param_2,local_res8);
      if (local_res8[0] != '\0') {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
           (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar8 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,p_Var10,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1b,
                   &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,(char)param_2);
        uVar6 = KeAcquireSpinLockRaiseToDpc(puVar1);
        if (((param_1->Sco).ReadsEnabled != '\0') &&
           ((param_1->Sco).PartialReadCtx == (_SCO_USB_TRANSFER_CTX *)0x0)) {
          (param_1->Sco).PartialReadCtx = param_2;
          param_2 = (_SCO_USB_TRANSFER_CTX *)0x0;
        }
        KeReleaseSpinLock(puVar1,uVar6);
      }
    }
    p_Var11 = local_res18;
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
       (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar8 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_DDd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,in_R8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if ((p_Var11->IoStatus).field0_0x0.Status == -0x3ffffff2) {
    BthUsb_ScoReadStop(param_1);
  }
  else {
    BthUsb_ScoReadData(param_1,1);
  }
  if (param_2 != (_SCO_USB_TRANSFER_CTX *)0x0) {
    RefObj_ReleaseEx((int *)&param_2->RefObj,(longlong)param_2,0x3c2,
                     "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbread.cpp");
  }
  if (p_Var5 != (_SCO_USB_TRANSFER_CTX *)0x0) {
    RefObj_ReleaseEx((int *)&p_Var5->RefObj,(longlong)p_Var5,0x3c6,
                     "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbread.cpp");
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    cVar9 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_L
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,'\x01',
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1c,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,uVar12);
  return 0;
}



===== BthUsb_ScoReadUrbSend @ 140008570 =====

/* long __cdecl BthUsb_ScoReadUrbSend(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64) */

long __cdecl BthUsb_ScoReadUrbSend(_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2)

{
  long lVar1;
  char cVar2;
  undefined7 uVar3;
  undefined8 in_stack_ffffffffffffffb8;
  
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_LLL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,param_2->Urb,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,0x17,
             &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,
             (char)(param_2->Urb->field0_0x0).UrbIsochronousTransfer.StartFrame,
             (char)param_2->UrbFrames,(char)param_2->BufferLen);
  lVar1 = BthUsb_ScoSendTransferUrb
                    (param_1,(_USBD_PIPE_INFORMATION *)CONCAT71(uVar3,cVar2),
                     BthUsb_ScoReadTransferCallback,param_2);
  return lVar1;
}



===== BthUsb_ScoReconstructReadPackets @ 140008604 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* struct _SCO_DATA_PACKET * __ptr64 __cdecl BthUsb_ScoReconstructReadPackets(struct
   _DEVICE_EXTENSION * __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64,struct _SCO_USB_TRANSFER_CTX *
   __ptr64,unsigned long * __ptr64,unsigned char * __ptr64) */

_SCO_DATA_PACKET * __cdecl
BthUsb_ScoReconstructReadPackets
          (_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2,_SCO_USB_TRANSFER_CTX *param_3,
          ulong *param_4,uchar *param_5)

{
  uint uVar1;
  uint uVar2;
  _URB *p_Var3;
  uchar *puVar4;
  uchar uVar5;
  ulonglong uVar6;
  char cVar7;
  ulonglong uVar8;
  uint uVar9;
  char cVar10;
  uchar uVar11;
  uint uVar12;
  _URB *p_Var13;
  _SCO_DATA_PACKET *p_Var14;
  _URB *_Size;
  ulong uVar15;
  longlong *plVar16;
  undefined1 auStackY_f8 [32];
  uint local_b4;
  void *local_a8;
  _SCO_DATA_PACKET *local_98;
  longlong local_80;
  ulong local_78 [2];
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar11 = '\0';
  *param_4 = 0;
  local_98 = (_SCO_DATA_PACKET *)0x0;
  local_80 = 0;
  uVar9 = 0;
  local_58 = 0;
  p_Var14 = (_SCO_DATA_PACKET *)0x0;
  uVar1 = ((param_1->Sco).UsbAltSetting)->FRAMES_X_HCIPACKET;
  cVar10 = '\x01';
  local_78[0] = 0;
  local_78[1] = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (param_2 != (_SCO_USB_TRANSFER_CTX *)0x0) {
    uVar12 = param_2->UrbFrameIndex;
    if ((uVar12 < param_2->UrbFrames) && (param_2->UrbFrames - uVar12 < uVar1)) {
      p_Var3 = param_2->Urb;
      *param_4 = uVar12 + (p_Var3->field0_0x0).UrbIsochronousTransfer.StartFrame;
      uVar12 = param_2->UrbFrameIndex;
      uVar2 = param_2->UrbFrames;
      if (uVar12 < uVar2) {
        puVar4 = param_2->TransferBuffer;
        do {
          uVar8 = (ulonglong)uVar9;
          uVar9 = uVar9 + 1;
          local_78[uVar8 * 4] = (p_Var3->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar12].Length
          ;
          uVar6 = (ulonglong)uVar12;
          uVar12 = uVar12 + 1;
          *(uchar **)(local_78 + uVar8 * 4 + -2) =
               puVar4 + (p_Var3->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar6].Offset;
          param_2->UrbFrameIndex = uVar12;
        } while (uVar12 < uVar2);
      }
    }
  }
  p_Var3 = param_3->Urb;
  do {
    uVar12 = param_3->UrbFrameIndex;
    if (param_3->UrbFrames <= uVar12) {
      if (uVar9 != 0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar11 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,p_Var3,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x20,
                   &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
        uVar11 = '\x01';
        param_3->UrbFrameIndex = param_3->UrbFrames - uVar9;
      }
      break;
    }
    if ((p_Var3->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar12].Status < 0) {
      uVar12 = 0;
    }
    else {
      if (uVar9 == 0) {
        *param_4 = uVar12 + (p_Var3->field0_0x0).UrbIsochronousTransfer.StartFrame;
      }
      local_78[(ulonglong)uVar9 * 4] =
           (p_Var3->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar12].Length;
      *(uchar **)(local_78 + (ulonglong)uVar9 * 4 + -2) =
           param_3->TransferBuffer +
           (p_Var3->field0_0x0).UrbIsochronousTransfer.IsoPacket[uVar12].Offset;
      uVar12 = uVar9 + 1;
      if (uVar1 <= uVar9 + 1) {
        p_Var13 = p_Var3;
        uVar5 = BthUsb_ScoIsPacketInFrames(param_1,(_SCO_HCIPACKET_FRAME *)&local_80);
        if (uVar5 == '\0') {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
             (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar7 = '\0';
          }
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                     &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1d,
                     &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
          memmove(&local_80,&uStack_70,0x20);
        }
        else {
          local_a8 = param_3->AuxiliaryBuffer;
          uVar15 = param_3->AuxBufferLen;
          local_b4 = 0;
          if (uVar1 != 0) {
            plVar16 = &local_80;
            do {
              uVar9 = *(uint *)(plVar16 + 1);
              _Size = (_URB *)(ulonglong)uVar9;
              if (uVar15 < uVar9) {
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar10 = '\0';
                }
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,p_Var13,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1e,
                           &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
                p_Var14 = local_98;
                goto LAB_14000893a;
              }
              p_Var13 = _Size;
              memmove(local_a8,(void *)*plVar16,(size_t)_Size);
              uVar15 = uVar15 - uVar9;
              local_a8 = (void *)((longlong)local_a8 + (longlong)_Size);
              local_b4 = local_b4 + 1;
              plVar16 = plVar16 + 2;
            } while (local_b4 < uVar1);
          }
          p_Var14 = param_3->AuxiliaryBuffer;
          uVar9 = 0;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
             (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar7 = '\0';
          }
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                     &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1f,
                     &WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids);
          local_98 = p_Var14;
        }
        uVar12 = uVar9;
      }
    }
    uVar9 = uVar12;
    param_3->UrbFrameIndex = param_3->UrbFrameIndex + 1;
  } while (p_Var14 == (_SCO_DATA_PACKET *)0x0);
LAB_14000893a:
  *param_5 = uVar11;
  return p_Var14;
}



===== WPP_RECORDER_AND_TRACE_SF_DDd @ 14000896c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DDd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,0x19,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,2,5,&WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,0x19,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LLLLD @ 140008a44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LLLLD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,param_7,&param_9,4,
               &param_10,4,&param_11,4,&param_12,4,&param_13,4,0);
  }
  WppAutoLogTrace(param_4,2,4,&WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,param_7,&param_9,4,
                  &param_10,4,&param_11,4,&param_12,4,&param_13,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LLLLL @ 140008b64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LLLLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined4 local_18 [4];
  
  local_18[0] = 0x3f;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,0x26,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,local_18,4,0);
  }
  WppAutoLogTrace(param_4,2,4,&WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,0x26,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LLLLqL @ 140008c88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LLLLqL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,0x27,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,8,&uStack0000000000000070,4,0);
  }
  WppAutoLogTrace(param_4,2,4,&WPP_bdb2f4b08e1e350eed49ca0df045c47e_Traceguids,0x27,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,8,&uStack0000000000000070,4,0);
  return;
}



===== AllocWriteTransferCtxImpl @ 140008dc8 =====

void AllocWriteTransferCtxImpl(_DEVICE_EXTENSION *param_1,ulong param_2,_LIST_ENTRY *param_3)

{
  ulong uVar1;
  ScoUsbAltSetting *pSVar2;
  char cVar3;
  ulong uVar4;
  undefined8 in_stack_ffffffffffffffb8;
  
  pSVar2 = (param_1->Sco).UsbAltSetting;
  uVar1 = pSVar2->WRITE_FRAMES_X_REQ;
  uVar4 = pSVar2->MAX_WRITE_HCIPKTS_X_REQ << 5;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_LLL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,param_3,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,0xb,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids,(char)param_2,(char)uVar1,(char)uVar4)
  ;
  BthUsb_ScoAllocTransferContextsImpl
            (param_1,param_2,uVar1,uVar4,&(param_1->Sco).WriteCtxQueue,param_3);
  return;
}



===== BthUsbAltSetting6_ScoAllocWriteTransferCtxImpl @ 140008e90 =====

/* long __cdecl BthUsbAltSetting6_ScoAllocWriteTransferCtxImpl(void * __ptr64,struct _LIST_ENTRY *
   __ptr64) */

long __cdecl BthUsbAltSetting6_ScoAllocWriteTransferCtxImpl(void *param_1,_LIST_ENTRY *param_2)

{
  long lVar1;
  
  lVar1 = AllocWriteTransferCtxImpl
                    (param_1,*(int *)(*(longlong *)((longlong)param_1 + 0x478) + 0x40) * 3,param_2);
  return lVar1;
}



===== BthUsbAltSetting6_ScoWriteNextFrame @ 140008ec0 =====

/* unsigned long __cdecl BthUsbAltSetting6_ScoWriteNextFrame(struct _DEVICE_EXTENSION *
   __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64,unsigned short,unsigned long) */

ulong __cdecl
BthUsbAltSetting6_ScoWriteNextFrame
          (_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2,ushort param_3,ulong param_4)

{
  uint uVar1;
  undefined1 uVar2;
  ulong uVar3;
  ushort uVar4;
  undefined6 in_register_00000082;
  char cVar5;
  undefined8 in_stack_ffffffffffffffb8;
  
  uVar4 = param_3;
  uVar2 = KeAcquireSpinLockRaiseToDpc(&(param_1->Sco).Channel[param_3].Lock);
  uVar1 = (param_1->Sco).Channel[param_3].WriteFrameInterval;
  cVar5 = '\x01';
  (param_1->Sco).Channel[param_3].WriteFrameInterval = (uVar1 & 1) + 7;
  KeReleaseSpinLock(&(param_1->Sco).Channel[param_3].Lock,uVar2);
  uVar3 = uVar1 + param_4;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar5 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_LL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,CONCAT62(in_register_00000082,uVar4),
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,5,10,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids,(char)param_4,(char)uVar3);
  return uVar3;
}



===== BthUsbAltSetting6_ScoWriteStart @ 140008fb0 =====

/* long __cdecl BthUsbAltSetting6_ScoWriteStart(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthUsbAltSetting6_ScoWriteStart(_DEVICE_EXTENSION *param_1)

{
  ulong64 *puVar1;
  undefined1 uVar2;
  long lVar3;
  ulonglong uVar4;
  
  puVar1 = &(param_1->Sco).Channel[0].Lock;
  uVar2 = KeAcquireSpinLockRaiseToDpc(puVar1);
  for (uVar4 = 0; (ushort)uVar4 < (param_1->Sco).NumChannels;
      uVar4 = (ulonglong)(ushort)((ushort)uVar4 + 1)) {
    (param_1->Sco).Channel[uVar4].WriteFrameInterval = 7;
  }
  KeReleaseSpinLock(puVar1,uVar2);
  lVar3 = BthUsb_ScoWriteStart(param_1);
  return lVar3;
}



===== BthUsb_ScoAllocWriteTransferCtxImpl @ 140009030 =====

/* long __cdecl BthUsb_ScoAllocWriteTransferCtxImpl(void * __ptr64,struct _LIST_ENTRY * __ptr64) */

long __cdecl BthUsb_ScoAllocWriteTransferCtxImpl(void *param_1,_LIST_ENTRY *param_2)

{
  long lVar1;
  
  lVar1 = AllocWriteTransferCtxImpl
                    (param_1,(*(int *)(*(longlong *)((longlong)param_1 + 0x478) + 0x40) + 1) * 3,
                     param_2);
  return lVar1;
}



===== BthUsb_ScoFreeWriteResources @ 140009060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthUsb_ScoFreeWriteResources(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoFreeWriteResources(_DEVICE_EXTENSION *param_1)

{
  char cVar1;
  char cVar2;
  undefined8 in_R8;
  
  cVar2 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xd,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  ResourceQueue_StopAndWait(&(param_1->Sco).WriteCtxQueue.AbortStatus);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xe,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  (*(param_1->Sco).WriteCtxQueue.FnDestroyItems)
            ((param_1->Sco).WriteCtxQueue.ContextFn,&(param_1->Sco).WriteCtxQueue.ListEntry);
  return;
}



===== BthUsb_ScoInitWriteTransferUrb @ 140009138 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl BthUsb_ScoInitWriteTransferUrb(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_CHANNEL * __ptr64,struct _SCO_USB_TRANSFER_CTX * __ptr64) */

long __cdecl
BthUsb_ScoInitWriteTransferUrb
          (_DEVICE_EXTENSION *param_1,_SCO_USB_CHANNEL *param_2,_SCO_USB_TRANSFER_CTX *param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  _URB *p_Var4;
  uint uVar5;
  ulong uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  _USBD_ISO_PACKET_DESCRIPTOR *p_Var9;
  uint local_res18;
  ulong local_res20;
  _BTH_SCO_MP_INDICATION_PARAMETERS local_90;
  ushort *local_60;
  ulong *local_58;
  _URB *local_50;
  longlong local_48;
  
  p_Var4 = param_3->Urb;
  local_res18 = 0;
  local_48 = (longlong)(int)param_3->IndexPipe * 3;
  p_Var9 = (p_Var4->field0_0x0).UrbIsochronousTransfer.IsoPacket;
  local_res20 = param_3->UrbFrames;
  uVar7 = 0;
  local_50 = p_Var4;
  if (1 < (param_1->Sco).WriteHciPacketsPerReq) {
    local_90._2_6_ = 0;
    local_90.ConnectionHandle = param_2->ConnectionHandle;
    local_90.field1_0x8._8_8_ = 0;
    local_90.field1_0x8.Read.DataTag = 0;
    local_90.field1_0x8.Read.BufferData = (void *)0x0;
    local_90.field1_0x8._24_8_ = 0;
    local_90.field1_0x8.WriteComplete.DataTag = 0;
    lVar1 = (*param_2->Callback)(param_2->CallbackContext,ScoMpIndicationGetSize,&local_90);
    if (lVar1 < 0) {
      return -0x7fffffde;
    }
    if (local_90.field1_0x8.GetSize.DataLen < param_2->WriteDataSizePerReq) {
      return -0x7fffffde;
    }
  }
  local_58 = &((param_1->Sco).UsbAltSetting)->FRAMES_X_HCIPACKET;
  uVar6 = 0;
  if ((param_1->Sco).WriteHciPacketsPerReq != 0) {
    uVar3 = 0;
    do {
      uVar5 = param_2->TxPacketSize - 3;
      local_60 = (ushort *)(param_3->TransferBuffer + uVar7);
      local_90.field1_0x8._12_4_ = 0;
      local_90.field1_0x8.Read.DataLen = uVar5;
      puVar8 = (undefined8 *)((ulonglong)uVar3 * 0x20 + (longlong)param_3->AuxiliaryBuffer);
      local_90.field1_0x8._24_8_ = 0;
      local_90.field1_0x8.WriteComplete.DataTag = 0;
      local_90.field1_0x8.Read.DataTag = 0;
      puVar8[2] = 0;
      local_90._2_6_ = 0;
      local_90.ConnectionHandle = param_2->ConnectionHandle;
      local_90.field1_0x8.Read.BufferData = (void *)((longlong)local_60 + 3);
      lVar1 = (*param_2->Callback)(param_2->CallbackContext,ScoMpIndicationWrite,&local_90);
      if (lVar1 < 0) break;
      uVar2 = 0;
      puVar8[2] = local_90.field1_0x8.Read.DataTag;
      *local_60 = param_2->ConnectionHandle;
      *(char *)(local_60 + 1) = (char)uVar5;
      *puVar8 = local_60;
      *(ulong *)(puVar8 + 1) = param_2->TxPacketSize;
      puVar8[3] = p_Var9;
      uVar7 = (ulonglong)local_res18;
      if (*local_58 != 0) {
        do {
          p_Var9->Offset = (ulong)uVar7;
          local_res20 = local_res20 - 1;
          uVar6 = param_2->TxFragmentSize;
          uVar2 = uVar2 + 1;
          p_Var9->Length = uVar6;
          local_res18 = (ulong)uVar7 + uVar6;
          uVar7 = (ulonglong)local_res18;
          p_Var9->Status = 0;
          p_Var9 = p_Var9 + 1;
        } while (uVar2 < *local_58);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (param_1->Sco).WriteHciPacketsPerReq);
    p_Var4 = local_50;
    uVar6 = local_res18;
  }
  param_3->Chx = param_2;
  local_res20 = param_3->UrbFrames - local_res20;
  if (local_res20 == 0) {
    return -0x7fffffde;
  }
  (p_Var4->field0_0x0).UrbHeader.Function = 10;
  (p_Var4->field0_0x0).UrbHeader.Status = 0;
  (p_Var4->field0_0x0).UrbHeader.UsbdDeviceHandle = (void *)0x0;
  (p_Var4->field0_0x0).UrbHeader.UsbdFlags = 0;
  (p_Var4->field0_0x0).UrbHeader.Length = (short)local_res20 * 0xc + 0x98;
  (p_Var4->field0_0x0).UrbSelectInterface.ConfigurationHandle =
       (&param_1->Pipes[0].PipeHandle)[local_48];
  (p_Var4->field0_0x0).UrbPipeRequest.Reserved = 0;
  (p_Var4->field0_0x0).UrbControlTransfer.TransferBufferLength = uVar6;
  (p_Var4->field0_0x0).UrbSelectInterface.Interface.InterfaceHandle = param_3->TransferBuffer;
  (p_Var4->field0_0x0).UrbSelectConfiguration.Interface.InterfaceHandle = param_3->TransferMdl;
  (p_Var4->field0_0x0).UrbControlTransfer.UrbLink = (_URB *)0x0;
  (p_Var4->field0_0x0).UrbIsochronousTransfer.StartFrame = 0;
  (p_Var4->field0_0x0).UrbIsochronousTransfer.NumberOfPackets = local_res20;
  (p_Var4->field0_0x0).UrbIsochronousTransfer.ErrorCount = 0;
  return 0;
}



===== BthUsb_ScoUpdateWriteResources @ 1400093a4 =====

/* void __cdecl BthUsb_ScoUpdateWriteResources(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoUpdateWriteResources(_DEVICE_EXTENSION *param_1)

{
  ushort uVar1;
  ScoUsbAltSetting *pSVar2;
  _DEVICE_EXTENSION *p_Var3;
  longlong lVar4;
  ushort uVar5;
  ulong *puVar6;
  
  uVar1 = (param_1->Sco).NumChannels;
  uVar5 = 0;
  if (((uVar1 == 1) || (uVar1 == 2)) || (uVar1 == 3)) {
    pSVar2 = (param_1->Sco).UsbAltSetting;
    (param_1->Sco).WriteFramesPerReq = pSVar2->FRAMES_X_HCIPACKET;
    (param_1->Sco).WriteHciPacketsPerReq = 1;
    p_Var3 = (_DEVICE_EXTENSION *)
             ((ulonglong)pSVar2->MAX_PENDING_WRITE_REQS_SPAN /
             (ulonglong)((uint)uVar1 * pSVar2->WRITE_USEC_X_HCIPACKET));
  }
  else {
    (param_1->Sco).WriteFramesPerReq = 0;
    (param_1->Sco).WriteHciPacketsPerReq = 0;
    p_Var3 = (_DEVICE_EXTENSION *)0x0;
  }
  puVar6 = &(param_1->Sco).Channel[0].WriteDataSizePerReq;
  lVar4 = 3;
  (param_1->Sco).WriteMaxPendingReq = (long)p_Var3;
  do {
    if (((_SCO_USB_CHANNEL *)(puVar6 + -0x24))->ConnectionHandle != 0xffff) {
      *puVar6 = (puVar6[-0x1d] - 3) * (param_1->Sco).WriteHciPacketsPerReq;
      BthUsb_ScoPipeObjInit
                (p_Var3,(_SCO_USB_PIPE_OBJ *)(puVar6 + -0x14),WRITE_SCO_PIPE,uVar5,
                 BthUsb_ScoWriteUrbSend,BthUsb_ScoWriteUrbDone,BthUsb_ScoWriteAlignFrame,
                 (_func_ulong__DEVICE_EXTENSION_ptr__SCO_USB_TRANSFER_CTX_ptr_ushort_ulong *)
                 ((param_1->Sco).UsbAltSetting)->WriteGetNextFrame);
      uVar5 = uVar5 + 1;
    }
    puVar6 = puVar6 + 0x26;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



===== BthUsb_ScoWriteAlignFrame @ 1400094c0 =====

/* unsigned long __cdecl BthUsb_ScoWriteAlignFrame(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64,unsigned short,unsigned long) */

ulong __cdecl
BthUsb_ScoWriteAlignFrame
          (_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2,ushort param_3,ulong param_4)

{
  ulong64 *puVar1;
  ushort *puVar2;
  ushort uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  
  puVar1 = &(param_1->Sco).WriteLock;
  uVar7 = (uint)param_3;
  uVar6 = KeAcquireSpinLockRaiseToDpc(puVar1);
  uVar4 = (param_1->Sco).WriteLastFrame;
  uVar3 = (param_1->Sco).WriteLastPipeId;
  KeReleaseSpinLock(puVar1,uVar6);
  puVar2 = &(param_1->Sco).NumChannels;
  if (param_3 < uVar3) {
    uVar7 = uVar7 + *puVar2;
  }
  uVar5 = (param_1->Sco).WriteFramesPerReq;
  uVar8 = *puVar2 * uVar5;
  uVar7 = (param_4 - (uVar4 + (uVar7 - uVar3) * uVar5)) % uVar8;
  if (uVar7 != 0) {
    param_4 = param_4 + (uVar8 - uVar7);
  }
  return param_4;
}



===== BthUsb_ScoWriteData @ 14000957c =====

/* long __cdecl BthUsb_ScoWriteData(struct _DEVICE_EXTENSION * __ptr64,struct _SCO_USB_CHANNEL *
   __ptr64,unsigned char) */

long __cdecl BthUsb_ScoWriteData(_DEVICE_EXTENSION *param_1,_SCO_USB_CHANNEL *param_2,uchar param_3)

{
  ulong64 *puVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  long lVar5;
  _SCO_USB_TRANSFER_CTX *p_Var6;
  char cVar7;
  uint uVar8;
  char cVar9;
  undefined7 in_register_00000081;
  ulonglong uVar10;
  uint uVar11;
  int iVar12;
  
  uVar10 = CONCAT71(in_register_00000081,param_3);
  lVar5 = 0;
  puVar1 = &param_2->Lock;
  bVar4 = false;
  uVar11 = 2;
  KeAcquireSpinLockRaiseToDpc(puVar1);
  cVar9 = '\x01';
  uVar2 = param_2->Flags;
  if ((uVar2 & 1) == 0) {
    param_2->Flags = uVar2 | 1;
  }
  else {
    if (param_3 != '\0') {
      param_2->Flags = uVar2 | 2;
    }
    bVar4 = true;
  }
  KeReleaseSpinLock(puVar1);
  if (!bVar4) {
    do {
      iVar12 = 0;
      if (uVar11 != 0) {
        do {
          KeAcquireSpinLockRaiseToDpc(&(param_2->WritePipeObj).Lock);
          iVar3 = (param_2->WritePipeObj).InProgressUrbs;
          KeReleaseSpinLock(&(param_2->WritePipeObj).Lock);
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar7 = '\0';
          }
          else {
            cVar7 = '\x01';
          }
          WPP_RECORDER_AND_TRACE_SF_llls
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                     (ulonglong)(uint)(param_1->Sco).WriteMaxPendingReq,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          if (((param_1->Sco).WriteMaxPendingReq <= iVar3) ||
             (p_Var6 = (_SCO_USB_TRANSFER_CTX *)
                       ResourceQueue_GetItem(&(param_1->Sco).WriteCtxQueue.AbortStatus),
             p_Var6 == (_SCO_USB_TRANSFER_CTX *)0x0)) break;
          p_Var6->DevExt = param_1;
          p_Var6->IndexPipe = WRITE_SCO_PIPE;
          lVar5 = BthUsb_ScoInitWriteTransferUrb(param_1,param_2,p_Var6);
          if (lVar5 < 0) {
            RefObj_ReleaseEx((int *)&p_Var6->RefObj,(longlong)p_Var6,800,
                             "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbwrite.cpp");
            break;
          }
          lVar5 = BthUsb_ScoUrbStart(param_1,&param_2->WritePipeObj,p_Var6);
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)uVar11);
      }
      KeAcquireSpinLockRaiseToDpc(puVar1);
      uVar2 = param_2->Flags;
      uVar10 = (ulonglong)uVar2;
      uVar8 = uVar2 & 2;
      param_2->Flags = 0xfffffffe - (uVar8 != 0) & uVar2;
      KeReleaseSpinLock(puVar1);
      uVar11 = -(uint)(uVar8 != 0) & 2;
    } while (uVar8 != 0);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar9 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_qLd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,uVar10,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  return lVar5;
}



===== BthUsb_ScoWriteNextFrame @ 1400097c0 =====

/* unsigned long __cdecl BthUsb_ScoWriteNextFrame(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64,unsigned short,unsigned long) */

ulong __cdecl
BthUsb_ScoWriteNextFrame
          (_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2,ushort param_3,ulong param_4)

{
  return (uint)(param_1->Sco).NumChannels * (param_1->Sco).WriteFramesPerReq + param_4;
}



===== BthUsb_ScoWriteStart @ 1400097e0 =====

/* long __cdecl BthUsb_ScoWriteStart(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthUsb_ScoWriteStart(_DEVICE_EXTENSION *param_1)

{
  char cVar1;
  char cVar2;
  undefined8 in_R8;
  
  cVar2 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xf,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  ResourceQueue_Start(&(param_1->Sco).WriteCtxQueue.AbortStatus);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x10,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  return 0;
}



===== BthUsb_ScoWriteStop @ 1400098a0 =====

/* void __cdecl BthUsb_ScoWriteStop(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoWriteStop(_DEVICE_EXTENSION *param_1)

{
  char cVar1;
  char cVar2;
  undefined8 in_R8;
  
  cVar2 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x11,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  ResourceQueue_Stop(&(param_1->Sco).WriteCtxQueue.AbortStatus);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x12,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  return;
}



===== BthUsb_ScoWriteStopWait @ 14000995c =====

/* void __cdecl BthUsb_ScoWriteStopWait(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoWriteStopWait(_DEVICE_EXTENSION *param_1)

{
  _RESOURCE_QUEUE *p_Var1;
  long lVar2;
  char cVar3;
  undefined2 in_DX;
  byte bVar5;
  ushort uVar4;
  char cVar6;
  undefined8 in_R8;
  undefined *puVar7;
  undefined8 uVar8;
  
  cVar6 = '\x01';
  bVar5 = (byte)((ushort)in_DX >> 8);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    uVar4 = (ushort)bVar5 << 8;
  }
  else {
    uVar4 = CONCAT11(bVar5,1);
  }
  uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)uVar4,in_R8,uVar8,4,4,0x13,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  lVar2 = (long)uVar8;
  p_Var1 = &(param_1->Sco).WriteCtxQueue;
  ResourceQueue_Stop(&p_Var1->AbortStatus);
  puVar7 = param_1->Pipes[4].PipeHandle;
  lVar2 = BthUsb_PipeRequest(param_1,uVar4,puVar7,lVar2);
  if (lVar2 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    puVar7 = WPP_GLOBAL_Control;
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x14,
               &WPP_5fbab361c58e305795b7101c701f7776_Traceguids,(char)lVar2);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,puVar7,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x15,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  ResourceQueue_StopAndWait(&p_Var1->AbortStatus);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,puVar7,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x16,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids);
  return;
}



===== BthUsb_ScoWriteTransferCallback @ 140009ad0 =====

/* long __cdecl BthUsb_ScoWriteTransferCallback(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl BthUsb_ScoWriteTransferCallback(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int *piVar1;
  _DEVICE_EXTENSION *p_Var2;
  longlong lVar3;
  
  p_Var2 = *(_DEVICE_EXTENSION **)((longlong)param_3 + 0x38);
  piVar1 = (int *)((longlong)param_3 + 8);
  lVar3 = *(longlong *)((longlong)param_3 + 0x90);
  LOCK();
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (*(longlong *)((longlong)param_3 + 0x18) != 0) {
    RefObj_AddTrackingBlock
              ((longlong)piVar1,0x3ad,
               "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbwrite.cpp",
               BthUsb_ScoWriteTransferCallback);
  }
  BthUsb_ScoUrbComplete(p_Var2,(_SCO_USB_PIPE_OBJ *)(lVar3 + 0x40),param_3);
  RefObj_ReleaseEx(piVar1,0x140009ad0,0x3af,
                   "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbwrite.cpp");
  return -0x3fffffea;
}



===== BthUsb_ScoWriteUrbDone @ 140009b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl BthUsb_ScoWriteUrbDone(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64) */

long __cdecl BthUsb_ScoWriteUrbDone(_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2)

{
  ushort uVar1;
  _BTH_PIPE_TYPE _Var2;
  ulong uVar3;
  int iVar4;
  _URB *p_Var5;
  _SCO_USB_CHANNEL *p_Var6;
  _IRP *p_Var7;
  _IRP *p_Var8;
  _SCO_USB_CHANNEL *p_Var9;
  uchar uVar10;
  undefined1 uVar11;
  int *piVar12;
  uint uVar13;
  char cVar14;
  ulong64 *puVar15;
  char cVar16;
  uint uVar17;
  ulonglong uVar18;
  undefined4 uVar19;
  undefined1 in_stack_ffffffffffffff58;
  undefined7 in_stack_ffffffffffffff59;
  undefined1 uVar20;
  _BTH_SCO_MP_INDICATION_PARAMETERS local_68;
  
  p_Var5 = param_2->Urb;
  p_Var6 = param_2->Chx;
  _Var2 = param_2->IndexPipe;
  p_Var7 = param_2->Irp;
  uVar17 = (p_Var5->field0_0x0).UrbIsochronousTransfer.StartFrame;
  uVar3 = (p_Var5->field0_0x0).UrbControlTransfer.TransferBufferLength;
  cVar16 = '\0';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
     (cVar14 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar14 = '\0';
  }
  uVar20 = (undefined1)uVar17;
  WPP_RECORDER_AND_TRACE_SF_LLL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar14,(ulonglong)uVar17,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffff59,in_stack_ffffffffffffff58),5,0x1a,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids,uVar20,(char)uVar3,
             (char)param_2->BufferLen);
  uVar10 = BthUsb_ScoUrbError(param_2,_Var2);
  if ((uVar10 == '\0') && (uVar3 != 0)) {
    uVar3 = (p_Var5->field0_0x0).UrbIsochronousTransfer.StartFrame;
    puVar15 = &(param_1->Sco).WriteLock;
    uVar1 = (p_Var6->WritePipeObj).Id;
    uVar11 = KeAcquireSpinLockRaiseToDpc(puVar15);
    (param_1->Sco).WriteLastFrame = uVar3;
    (param_1->Sco).WriteLastPipeId = uVar1;
    KeReleaseSpinLock(puVar15,uVar11);
  }
  else if ((-1 < (p_Var7->IoStatus).field0_0x0.Status) &&
          (iVar4 = (p_Var5->field0_0x0).UrbHeader.Status,
          (p_Var7->IoStatus).field0_0x0.Status = iVar4, -1 < iVar4)) {
    (p_Var7->IoStatus).field0_0x0.Status = -0x3fffffff;
  }
  uVar18 = 0;
  p_Var8 = param_2->Irp;
  p_Var9 = param_2->Chx;
  if ((param_1->Sco).WriteHciPacketsPerReq != 0) {
    do {
      puVar15 = (ulong64 *)(uVar18 * 0x20 + (longlong)param_2->AuxiliaryBuffer);
      if (*puVar15 != 0) {
        uVar19 = (p_Var8->IoStatus).field0_0x0.Status;
        if (-1 < (int)uVar19) {
          uVar13 = 0;
          uVar17 = ((param_1->Sco).UsbAltSetting)->FRAMES_X_HCIPACKET;
          if (uVar17 != 0) {
            piVar12 = (int *)(puVar15[3] + 8);
            do {
              if (*piVar12 < 0) {
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                   (cVar14 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar14 = '\0';
                }
                WPP_RECORDER_AND_TRACE_SF_d
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar14,(ulonglong)(uint)uVar19
                           ,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x1e,
                           &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)*piVar12);
                uVar19 = 0xc0000001;
                break;
              }
              piVar12 = piVar12 + 3;
              uVar13 = uVar13 + 1;
            } while (uVar13 < uVar17);
          }
        }
        local_68.ConnectionHandle = p_Var9->ConnectionHandle;
        local_68.field1_0x8.Read.BufferData = (void *)puVar15[2];
        local_68.field1_0x8.Read.DataTag = *puVar15;
        local_68.field1_0x8.WriteComplete.DataLen = (ulong)puVar15[1];
        local_68._2_4_ = 0;
        local_68._6_2_ = 0;
        local_68.field1_0x8._12_4_ = 0;
        local_68.field1_0x8._28_4_ = 0;
        local_68.field1_0x8.WriteComplete.DataTag = 0;
        local_68.field1_0x8.Read.DataLen = uVar19;
        (*p_Var9->Callback)(p_Var9->CallbackContext,ScoMpIndicationWriteComplete,&local_68);
      }
      uVar17 = (int)uVar18 + 1;
      uVar18 = (ulonglong)uVar17;
    } while (uVar17 < (param_1->Sco).WriteHciPacketsPerReq);
  }
  if ((p_Var7->IoStatus).field0_0x0.Status == -0x3ffffff2) {
    BthUsb_ScoWriteStop(param_1);
  }
  else {
    BthUsb_ScoWriteData(param_1,p_Var6,'\0');
  }
  RefObj_ReleaseEx((int *)&param_2->RefObj,(longlong)param_2,0x415,
                   "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\scousbwrite.cpp");
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    cVar16 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_L
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,'\x01',
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1b,
             &WPP_5fbab361c58e305795b7101c701f7776_Traceguids,uVar20);
  return 0;
}



===== BthUsb_ScoWriteUrbSend @ 140009e60 =====

/* long __cdecl BthUsb_ScoWriteUrbSend(struct _DEVICE_EXTENSION * __ptr64,struct
   _SCO_USB_TRANSFER_CTX * __ptr64) */

long __cdecl BthUsb_ScoWriteUrbSend(_DEVICE_EXTENSION *param_1,_SCO_USB_TRANSFER_CTX *param_2)

{
  long lVar1;
  char cVar2;
  undefined7 uVar3;
  
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_qqLqLLLLLL
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,param_2->Chx,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  lVar1 = BthUsb_ScoSendTransferUrb
                    (param_1,(_USBD_PIPE_INFORMATION *)CONCAT71(uVar3,cVar2),
                     BthUsb_ScoWriteTransferCallback,param_2);
  return lVar1;
}



===== WPP_RECORDER_AND_TRACE_SF_llls @ 140009f24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_llls
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  char *in_stack_00000060;
  
  if (param_2 != '\0') {
    if (in_stack_00000060 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000060[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000060;
    if (in_stack_00000060 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_5fbab361c58e305795b7101c701f7776_Traceguids,0x17,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,pcVar3,
               lVar2,0);
  }
  lVar2 = -1;
  if (in_stack_00000060 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000060[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000060 == (char *)0x0) {
    in_stack_00000060 = "NULL";
  }
  WppAutoLogTrace(param_4,4,5,&WPP_5fbab361c58e305795b7101c701f7776_Traceguids,0x17,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  in_stack_00000060,lVar1,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLd @ 14000a0a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_5fbab361c58e305795b7101c701f7776_Traceguids,0x18,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,4,5,&WPP_5fbab361c58e305795b7101c701f7776_Traceguids,0x18,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqLqLLLLLL @ 14000a180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqLqLLLLLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

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
              (param_1,0x2b,&WPP_5fbab361c58e305795b7101c701f7776_Traceguids,0x19,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,8,&uStack0000000000000068,4,&uStack0000000000000070,4,
               &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
               &uStack0000000000000090,4,0);
  }
  WppAutoLogTrace(param_4,4,5,&WPP_5fbab361c58e305795b7101c701f7776_Traceguids,0x19,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,8,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
                  &uStack0000000000000090,4,0);
  return;
}



===== EvtIoQueueIoDefault @ 14000a364 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000a491) */
/* private: void __cdecl TransmitQueue::EvtIoQueueIoDefault(struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall TransmitQueue::EvtIoQueueIoDefault(TransmitQueue *this,WDFREQUEST__ *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  char cVar5;
  undefined8 *puVar6;
  code *pcVar7;
  undefined1 auStackY_108 [32];
  undefined8 local_a8;
  undefined8 local_a0 [2];
  undefined4 *local_90;
  undefined1 local_88 [8];
  undefined4 *local_80;
  undefined4 local_70;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar2 = (*DAT_1400142b8)(BthDriverGlobals);
  puVar6 = local_a0;
  cVar5 = '\0';
  local_a0[0] = 0;
  local_a8 = 0;
  (*DAT_1400142c0)(BthDriverGlobals,param_1,puVar6,&local_a8);
  cVar1 = '\x01';
  if (uVar2 < 2) {
    utl::make_unique<_URB,0>();
    if (local_90 == (undefined4 *)0x0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
         (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar1 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,puVar6,
                 (*(undefined8 **)(this + 8))[1],2,1,0xc,
                 &WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,(char)**(undefined8 **)(this + 8))
      ;
      uVar3 = 0xc000009a;
    }
    else {
      memset(local_90,0,0x98);
      if (uVar2 == 0) {
        *local_90 = 0x1a0088;
        local_90[9] = (undefined4)local_a8;
        *(undefined8 *)(local_90 + 0xc) = 0;
        *(undefined8 *)(local_90 + 10) = local_a0[0];
        local_90[0x20] = 0;
        *(undefined2 *)(local_90 + 0x21) = 0;
      }
      else {
        *local_90 = 0x90080;
        *(undefined8 *)(local_90 + 6) = *(undefined8 *)(this + 0x10);
        local_90[9] = (undefined4)local_a8;
        *(undefined8 *)(local_90 + 0xc) = 0;
        *(undefined8 *)(local_90 + 10) = local_a0[0];
      }
      local_90[8] = 0;
      *(undefined8 *)(local_90 + 0xe) = 0;
      memset(local_88,0,0x48);
      local_80 = local_90;
      local_70 = 0x220003;
      local_88[0] = 0xf;
      (**(code **)(WdfFunctions_01031 + 0x7e0))(WdfDriverGlobals,param_1,local_88);
      pcVar7 = EvtRequestCompletionRoutineThunk;
      (**(code **)(WdfFunctions_01031 + 0x820))
                (WdfDriverGlobals,param_1,EvtRequestCompletionRoutineThunk,local_90);
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
         (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar1 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qLq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,pcVar7,
                 *(undefined8 *)(*(longlong *)(this + 8) + 8));
      uVar4 = (**(code **)(WdfFunctions_01031 + 0x150))
                        (WdfDriverGlobals,**(undefined8 **)(this + 8));
      cVar1 = (**(code **)(WdfFunctions_01031 + 0x7e8))(WdfDriverGlobals,param_1,uVar4,0);
      if (cVar1 != '\0') {
        return;
      }
      uVar3 = (**(code **)(WdfFunctions_01031 + 0x7f0))(WdfDriverGlobals,param_1);
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        cVar5 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,WPP_GLOBAL_Control,
                 (*(undefined8 **)(this + 8))[1],2,1,0xe,
                 &WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,(char)**(undefined8 **)(this + 8),
                 (char)uVar3);
      ExFreePool(local_90);
    }
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar1 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_qL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,puVar6,
               *(undefined8 *)(*(longlong *)(this + 8) + 8));
    MicrosoftTelemetryAssertTriggeredMsgKM("Unknown packet type.");
    uVar3 = 0xc00000bb;
  }
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,uVar3);
  return;
}



===== EvtIoQueueIoDefaultThunk @ 14000a6e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl TransmitQueue::EvtIoQueueIoDefaultThunk(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl TransmitQueue::EvtIoQueueIoDefaultThunk(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  TransmitQueue *this;
  
  this = (TransmitQueue *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_TransmitQueue_TYPE_INFO_1400140b0);
  EvtIoQueueIoDefault(this,param_2);
  return;
}



===== EvtObjectContextCleanupThunk @ 14000a730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFQUEUE__ * __ptr64,class
   TransmitQueue,1>::EvtObjectContextCleanupThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<WDFQUEUE__*___ptr64,TransmitQueue,1>::EvtObjectContextCleanupThunk
          (void *param_1)

{
  (**(code **)(WdfFunctions_01031 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_TransmitQueue_TYPE_INFO_1400140b0);
  return;
}



===== EvtRequestCompletionRoutineThunk @ 14000a770 =====

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
  longlong lVar2;
  char cVar3;
  int iVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong local_res18 [2];
  
  uVar1 = (**(code **)(WdfFunctions_01031 + 0x8d0))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01031 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_TransmitQueue_TYPE_INFO_1400140b0);
  iVar4 = (param_3->IoStatus).field0_0x0.Status;
  (*DAT_1400142b8)(BthDriverGlobals,param_1);
  local_res18[1] = 0;
  puVar5 = local_res18 + 1;
  local_res18[0] = 0;
  (*DAT_1400142c0)(BthDriverGlobals,param_1,puVar5,local_res18);
  if (iVar4 < 0) {
    cVar3 = '\x01';
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_qqLdD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,puVar5,
               *(undefined8 *)(*(longlong *)(lVar2 + 8) + 8));
  }
  else {
    uVar6 = (ulonglong)*(uint *)((longlong)param_4 + 0x24);
    if (local_res18[0] == uVar6) {
      cVar3 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
      {
        cVar3 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qqL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,uVar6,
                 *(undefined8 *)(*(longlong *)(lVar2 + 8) + 8));
    }
    else {
      cVar3 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar3 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qqLD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,uVar6,
                 *(undefined8 *)(*(longlong *)(lVar2 + 8) + 8));
      iVar4 = -0x3fffffc2;
    }
  }
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,iVar4);
  if (param_4 != (void *)0x0) {
    ExFreePool(param_4);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qL @ 14000a95c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,0xb,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,0xb,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqL @ 14000aa1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,0x10,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,4,1,&WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,0x10,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqLD @ 14000aafc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqLD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,0xf,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,0xf,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqLdD @ 14000ac00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqLdD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,0x11,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,0x11,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  return;
}



===== BthUsb_GetIsoInterface @ 14000ad28 =====

/* long __cdecl BthUsb_GetIsoInterface(struct _DEVICE_EXTENSION * __ptr64,char,char,struct
   _USB_INTERFACE_DESCRIPTOR * __ptr64 * __ptr64,unsigned long * __ptr64) */

long __cdecl
BthUsb_GetIsoInterface
          (_DEVICE_EXTENSION *param_1,char param_2,char param_3,_USB_INTERFACE_DESCRIPTOR **param_4,
          ulong *param_5)

{
  ushort uVar1;
  ulong *puVar2;
  _USB_INTERFACE_DESCRIPTOR *p_Var3;
  _USB_ENDPOINT_DESCRIPTOR *p_Var4;
  _USB_ENDPOINT_DESCRIPTOR *p_Var5;
  char cVar6;
  long lVar7;
  char cVar8;
  undefined7 in_register_00000081;
  ulonglong uVar9;
  uint uVar10;
  uchar local_res10 [8];
  int local_res18;
  uchar *in_stack_ffffffffffffff88;
  long lVar11;
  undefined4 in_stack_ffffffffffffff98;
  long lVar12;
  
  uVar10 = (uint)param_2;
  lVar7 = -0x3ffffd8e;
  cVar8 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  lVar12 = CONCAT22((short)((uint)in_stack_ffffffffffffff98 >> 0x10),0x48);
  lVar11 = 3;
  local_res18 = (int)param_3;
  WPP_RECORDER_AND_TRACE_SF_qdd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,CONCAT71(in_register_00000081,param_3)
             ,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,3,0x48,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)param_1,param_2,param_3);
  puVar2 = param_5;
  *param_4 = (_USB_INTERFACE_DESCRIPTOR *)0x0;
  if (param_5 != (ulong *)0x0) {
    *param_5 = 0;
  }
  param_5 = (ulong *)param_1->ConfigDescriptor;
  uVar9 = (ulonglong)uVar10;
  p_Var3 = BthUsb_GetInterfaceDescriptor
                     (param_1,&param_5,uVar10,(int)param_3,(long)in_stack_ffffffffffffff88,lVar11,
                      lVar12);
  if (p_Var3 != (_USB_INTERFACE_DESCRIPTOR *)0x0) {
    do {
      if (p_Var3->bNumEndpoints == '\x02') {
        in_stack_ffffffffffffff88 = local_res10;
        local_res10[0] = '\0';
        p_Var4 = BthUsb_FindUsbdPipeDescriptor
                           (param_1,p_Var3,(uchar)uVar9,'\x01',in_stack_ffffffffffffff88);
        if ((p_Var4 != (_USB_ENDPOINT_DESCRIPTOR *)0x0) && (local_res10[0] == '\0')) {
          in_stack_ffffffffffffff88 = local_res10;
          local_res10[0] = '\0';
          p_Var5 = BthUsb_FindUsbdPipeDescriptor
                             (param_1,p_Var3,(uchar)uVar9,'\0',in_stack_ffffffffffffff88);
          if ((p_Var5 != (_USB_ENDPOINT_DESCRIPTOR *)0x0) &&
             ((local_res10[0] == '\0' &&
              (uVar1 = *(ushort *)(p_Var4 + 4), uVar1 == *(ushort *)(p_Var5 + 4))))) {
            *param_4 = p_Var3;
            if (puVar2 != (ulong *)0x0) {
              *puVar2 = (uint)uVar1;
            }
            lVar7 = 0;
            break;
          }
        }
      }
      uVar9 = (ulonglong)uVar10;
      p_Var3 = BthUsb_GetInterfaceDescriptor
                         (param_1,&param_5,uVar10,local_res18,(long)in_stack_ffffffffffffff88,lVar11
                          ,lVar12);
      lVar7 = -0x3ffffd8e;
    } while (p_Var3 != (_USB_INTERFACE_DESCRIPTOR *)0x0);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar8 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,uVar9,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x49,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)lVar7);
  return lVar7;
}



===== BthUsb_GetUsbBusInterface @ 14000af0c =====

/* long __cdecl BthUsb_GetUsbBusInterface(struct _DEVICE_EXTENSION * __ptr64,void * __ptr64,unsigned
   short,unsigned short) */

long __cdecl
BthUsb_GetUsbBusInterface(_DEVICE_EXTENSION *param_1,void *param_2,ushort param_3,ushort param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  char cVar5;
  ulonglong _Size;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  _Size = (ulonglong)param_3;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  memset(param_2,0,_Size);
  cVar5 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_qqdd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,_Size,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)param_1->TopOfStack >> 8),
                                 param_1->TopOfStack->StackSize));
  if (lVar3 == 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,_Size,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x51,
               &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
    iVar2 = -0x3fffff66;
  }
  else {
    _Size = 0;
    KeInitializeEvent(&local_38,1);
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined **)(lVar1 + -0x40) = &USB_BUS_INTERFACE_USBDI_GUID;
    *(undefined2 *)(lVar1 + -0x48) = 0x81b;
    *(void **)(lVar1 + -0x30) = param_2;
    *(ushort *)(lVar1 + -0x38) = param_3;
    *(ushort *)(lVar1 + -0x36) = param_4;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = BthUsb_SyncCompletionRoutine;
    *(undefined8 **)(lVar1 + -8) = &local_38;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    iVar2 = IofCallDriver(param_1->TopOfStack,lVar3);
    if (iVar2 == 0x103) {
      _Size = 0;
      KeWaitForSingleObject(&local_38,0,0,0,0);
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    IoFreeIrp(lVar3);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,_Size,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x52,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)iVar2);
  return iVar2;
}



===== BthUsb_SelectIsoInterface @ 14000b124 =====

/* long __cdecl BthUsb_SelectIsoInterface(struct _DEVICE_EXTENSION * __ptr64,struct
   _USB_INTERFACE_DESCRIPTOR * __ptr64,unsigned long) */

long __cdecl
BthUsb_SelectIsoInterface
          (_DEVICE_EXTENSION *param_1,_USB_INTERFACE_DESCRIPTOR *param_2,ulong param_3)

{
  byte bVar1;
  long lVar2;
  short *psVar3;
  short *psVar4;
  ulonglong uVar5;
  char cVar6;
  char cVar7;
  undefined *puVar8;
  undefined1 in_stack_ffffffffffffffa8;
  undefined7 in_stack_ffffffffffffffa9;
  
  cVar7 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_qqd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffffa9,in_stack_ffffffffffffffa8),3,0x4a,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)param_1,(char)param_2,0);
  bVar1 = param_2->bNumEndpoints;
  puVar8 = (undefined *)0x42425355;
  uVar5 = (ulonglong)(uint)bVar1;
  psVar3 = (short *)ExAllocatePool2(0x40);
  if (psVar3 == (short *)0x0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,puVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x4c,
               &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
    lVar2 = -0x3fffff66;
  }
  else {
    psVar3[1] = 1;
    *psVar3 = (ushort)bVar1 * 0x18 + 0x38;
    *(uchar *)((longlong)psVar3 + 0x23) = param_2->bAlternateSetting;
    *(uchar *)(psVar3 + 0x11) = param_2->bInterfaceNumber;
    *(void **)(psVar3 + 0xc) = param_1->ConfigHandle;
    psVar3[0x10] = (bVar1 + 1) * 0x18;
    if (bVar1 != 0) {
      psVar4 = psVar3 + 0x24;
      do {
        psVar4[0] = 0x1000;
        psVar4[1] = 0;
        psVar4 = psVar4 + 0xc;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    puVar8 = (undefined *)0x1f4;
    lVar2 = USBCallSyncEx((longlong)param_1->TopOfStack,(longlong)psVar3,500,&param_1->RemoveLock);
    if (lVar2 < 0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      puVar8 = WPP_GLOBAL_Control;
      WPP_RECORDER_AND_TRACE_SF_DD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,WPP_GLOBAL_Control,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    else {
      lVar2 = BthUsb_InitializeIsochPipes(param_1,(_USBD_INTERFACE_INFORMATION *)(psVar3 + 0x10));
      if (lVar2 < 0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar6 = '\0';
        }
        else {
          cVar6 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,puVar8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x4e,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)lVar2);
      }
      else {
        lVar2 = 0;
      }
    }
    ExFreePoolWithTag(psVar3,0);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,puVar8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x4f,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)lVar2);
  return lVar2;
}



===== BthUsb_SyncCompletionRoutine @ 14000b3b0 =====

/* long __cdecl BthUsb_SyncCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl BthUsb_SyncCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffb8;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_qqd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,param_1,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,2,0xb,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)param_1,(char)param_2,
             (char)(param_2->IoStatus).field0_0x0.Status);
  KeSetEvent(param_3,0,0);
  return -0x3fffffea;
}



===== LogMaxIsoInterface @ 14000b43c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LogMaxIsoInterface(longlong param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
                       undefined4 param_5,undefined8 *param_6)

{
  longlong lVar1;
  undefined1 auStackY_158 [32];
  undefined1 local_128 [4];
  ushort local_124 [2];
  undefined2 local_120;
  undefined2 local_11e;
  undefined2 local_11c;
  undefined2 local_11a;
  undefined2 local_118 [2];
  undefined4 local_114;
  undefined4 local_110 [2];
  undefined8 local_108 [2];
  undefined8 local_f8 [4];
  undefined8 *local_d8;
  undefined8 local_d0;
  longlong local_c8;
  undefined8 local_c0;
  undefined2 *local_b8;
  undefined8 local_b0;
  undefined2 *local_a8;
  undefined8 local_a0;
  undefined2 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined2 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined2 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_158;
  local_28 = *param_6;
  local_124[0] = ((short)param_6[1] - (short)local_28) * -0x745d;
  if (((4 < DAT_140014000) && ((_DAT_140014010 & 0x400000000000) != 0)) &&
     ((DAT_140014018 & 0x400000000000) == DAT_140014018)) {
    lVar1 = *(longlong *)(param_1 + 0x60);
    local_110[0] = param_5;
    local_128[0] = *(undefined1 *)(lVar1 + 0x11);
    local_11c = *(undefined2 *)(lVar1 + 10);
    local_11a = *(undefined2 *)(lVar1 + 8);
    local_118[0] = *(undefined2 *)(lVar1 + 2);
    local_20 = (uint)local_124[0] * 0xb;
    local_38 = local_124;
    local_48 = &local_114;
    local_58 = &local_120;
    local_68 = local_110;
    local_78 = &local_11e;
    local_88 = local_128;
    local_98 = &local_11c;
    local_a8 = &local_11a;
    local_b8 = local_118;
    local_d8 = local_108;
    local_1c = 0;
    local_108[0] = 0x2000800;
    local_30 = 2;
    local_40 = 4;
    local_50 = 2;
    local_60 = 4;
    local_70 = 2;
    local_80 = 1;
    local_90 = 2;
    local_a0 = 2;
    local_b0 = 2;
    local_c0 = 0x10;
    local_d0 = 8;
    local_120 = param_2;
    local_11e = param_4;
    local_114 = param_3;
    local_c8 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x140014000,&DAT_140012172,0,0,0xe,local_f8);
  }
  return;
}



===== _SetCapacity @ 14000b62c =====

/* private: bool __cdecl utl::vector<struct USB_ALT_SETTING,class utl::allocator<struct
   USB_ALT_SETTING> >::_SetCapacity(unsigned __int64) __ptr64 */

bool __thiscall
utl::vector<USB_ALT_SETTING,utl::allocator<USB_ALT_SETTING>_>::_SetCapacity
          (vector<USB_ALT_SETTING,utl::allocator<USB_ALT_SETTING>_> *this,__uint64 param_1)

{
  longlong lVar1;
  longlong lVar2;
  void *_Dst;
  bool bVar3;
  
  bVar3 = false;
  if (param_1 < 0x1745d1745d1745d2) {
    _Dst = (void *)ExAllocatePool2(0x40,param_1 * 0xb,0x42425355);
    if ((_Dst != (void *)0x0) && (_Dst != (void *)0xffffffffffffffff)) {
      memmove(_Dst,*(void **)this,*(longlong *)(this + 8) - (longlong)*(void **)this);
      lVar1 = *(longlong *)this;
      lVar2 = *(longlong *)(this + 8);
      if ((lVar1 != -1) && (*(longlong *)(this + 8) = lVar1, lVar1 != 0)) {
        ExFreePool();
      }
      *(void **)this = _Dst;
      bVar3 = true;
      *(longlong *)(this + 8) = (lVar2 - lVar1) + (longlong)_Dst;
      *(void **)(this + 0x10) = (void *)(param_1 * 0xb + (longlong)_Dst);
    }
  }
  return bVar3;
}



===== Feature_4206787896__private_IsEnabledDeviceUsageNoInline @ 14000b714 =====

ulonglong Feature_4206787896__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_4206787896__private_featureState;
  if ((Feature_4206787896__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4206787896__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4206787896__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4206787896__private_IsEnabledFallback @ 14000b74c =====

void Feature_4206787896__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_DD @ 14000b764 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x4d,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_4,2,3,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x4d,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_DDll @ 14000b820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DDll
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x45,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_4,3,3,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x45,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_Dd @ 14000b918 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_Dd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x47,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_4,4,3,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x47,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_cdd @ 14000b9d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_cdd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined8 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined1 local_18 [16];
  
  local_18[0] = 7;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,param_7,local_18,1,
               &param_10,4,&param_11,4,0);
  }
  WppAutoLogTrace(param_4,2,2,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,param_7,local_18,1,
                  &param_10,4,&param_11,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_cddd @ 14000babc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_cddd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 local_18 [16];
  
  local_18[0] = 7;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x34,local_18,1,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_4,4,2,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x34,local_18,1,
                  &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_ddd @ 14000bbc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_ddd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x2d,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,4,2,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x2d,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_i @ 14000bc9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_i
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x3b,
               &uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_4,2,2,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x3b,
                  &uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_iDD @ 14000bd34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_iDD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 7;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x3d,
               &uStack0000000000000048,8,&uStack0000000000000050,4,local_18,4,0);
  }
  WppAutoLogTrace(param_4,2,2,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x3d,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_iDi @ 14000be1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_iDi
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x3c,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_4,2,2,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x3c,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqdd @ 14000befc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqdd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x50,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_4,4,2,&WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0x50,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000c000 =====

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
LAB_14000c203:
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
LAB_14000c0db:
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
      if (param_3 == 4) goto LAB_14000c203;
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
        goto LAB_14000c0db;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000c2ec =====

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
      goto LAB_14000c3af;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_14000c3af;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_14000c3af;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_14000c3af;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_14000c3af;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_14000c3af;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_14000c3af;
    }
  }
  uVar2 = 0xff;
LAB_14000c3af:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3c3f160,&Feature_4206787896_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000c408 =====

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
                     (local_50,&Feature_4206787896__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3c3f160,param_3,1,&Feature_4206787896__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3c3f160);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000c4f4 =====

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
LAB_14000c5a7:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_14000c5d5;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14000c5a7;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_14000c5d5:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000c760 =====

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
  if ((Feature_4206787896__private_featureState & 2) != 0) {
    uVar1 = Feature_4206787896__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_4206787896__private_featureState;
      if (bVar3) {
        Feature_4206787896__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_4206787896__private_featureState;
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



===== wil_details_IsEnabledFallback @ 14000c7b4 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_4206787896__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_4206787896__private_featureState,(ulonglong)param_1,
                             0x1400137a0);
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



===== WppRecorderLogCloseFunction @ 14000c844 =====

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



===== FxStubDriverUnloadCommon @ 14000c888 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = &_BthCoreCx_BIND_INFO;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140014228 != &__KMDF_CLASS_BIND_START) {
    puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_140014228 + 0x50);
    if (*(int *)PTR___KMDF_CLASS_BIND_START_140014228 == 0x78) {
      puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_140014228 + 0x78);
    }
    while( true ) {
      for (; (puVar1 + 2 <= puVar2 && (*(longlong *)puVar1 == 0)); puVar1 = puVar1 + 2) {
      }
      if (puVar1 < puVar2) break;
      puVar1 = puVar2;
LAB_14000c8f8:
      if (puVar1 == (uint *)0x0) goto LAB_14000c951;
      if (puVar2 <= puVar1) goto LAB_14000c969;
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&DAT_1400140c0,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))
                  (WdfVersionUnbindClass_exref,&DAT_1400140c0,WdfDriverGlobals,puVar1);
      }
      puVar1 = (uint *)((longlong)puVar1 + (ulonglong)*puVar1);
    }
    if (((puVar1 + 0x14 <= puVar2) && (*puVar1 == 0x50)) ||
       ((puVar1 + 0x1e <= puVar2 && (*puVar1 == 0x78)))) goto LAB_14000c8f8;
LAB_14000c951:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000c969:
  WdfVersionUnbind(&DAT_140014360,&DAT_1400140c0,WdfDriverGlobals);
  return;
}



===== entry @ 14000c9a0 =====

void entry(_DRIVER_OBJECT *param_1,undefined8 param_2,undefined8 param_3)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3);
  return;
}



===== FxDriverEntryWorker @ 14000c9d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_DRIVER_OBJECT *param_1,undefined8 param_2,undefined8 param_3)

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
    _DAT_140014360 = 0x2080000;
    _DAT_140014368 = &DAT_140014400;
    RtlCopyUnicodeString(&DAT_140014360);
    puVar4 = &DAT_1400140c0;
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_140014360,&DAT_1400140c0,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2,puVar4);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (param_1->DriverUnload != (_func___cdecl_void__DRIVER_OBJECT_ptr *)0x0) {
              DAT_140014608 = param_1->DriverUnload;
            }
            param_1->DriverUnload = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_140014360);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140014228 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&DAT_1400140c0,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 14000cb60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_140014608 != (code *)0x0) && (DAT_140014608 != FxStubDriverUnload)) {
    (*DAT_140014608)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 14000cb94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000cbb9) */
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
    if ((uint *)0x14001421f < puVar2) break;
    if ((((&__KMDF_CLASS_BIND_END < puVar2 + 0x14) || (*puVar2 != 0x50)) &&
        ((&__KMDF_CLASS_BIND_END < puVar2 + 0x1e || (*puVar2 != 0x78)))) || (puVar2 == (uint *)0x0))
    {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_140014228 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&DAT_1400140c0,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&DAT_1400140c0,WdfDriverGlobals,puVar2);
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



===== FxStubInitTypes @ 14000cd28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000cd45) */
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
    if ((void **)0x14001423f < ppvVar2) break;
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



===== USBCallSyncCompletionRoutine @ 14000cdf0 =====

undefined8 USBCallSyncCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0xf);
  }
  uVar1 = 0;
  KeSetEvent(param_3,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,7,0x10);
  }
  return 0xc0000016;
}



===== USBResetPort @ 14000ce84 =====

ulonglong USBResetPort(ulonglong param_1,ulonglong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint local_res10 [2];
  undefined8 uVar5;
  ulonglong in_stack_ffffffffffffff90;
  ulonglong local_48 [6];
  
  uVar4 = 0;
  while( true ) {
    local_res10[0] = 0;
    local_48[2] = 0;
    local_48[3] = 0;
    local_48[4] = 0;
    local_48[0] = 0;
    local_48[1] = 0;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x16);
    }
    KeInitializeEvent(local_48 + 2,1);
    in_stack_ffffffffffffff90 = in_stack_ffffffffffffff90 & 0xffffffff00000000;
    lVar1 = IoBuildDeviceIoControlRequest
                      (0x220013,param_1,0,0,0,in_stack_ffffffffffffff90,1,local_48 + 2,local_48);
    if (lVar1 == 0) {
      return 0xc000009a;
    }
    *(uint **)(*(longlong *)(lVar1 + 0xb8) + -0x40) = local_res10;
    uVar2 = IofCallDriver(param_1);
    if ((int)uVar2 == 0x103) {
      lVar1 = 0;
      KeWaitForSingleObject(local_48 + 2);
      uVar2 = local_48[0];
    }
    uVar3 = uVar2 & 0xffffffff;
    if ((-1 < (int)uVar2) && ((local_res10[0] & 2) == 0)) {
      uVar3 = 0xc00000c0;
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      in_stack_ffffffffffffff90 = CONCAT44((int)(in_stack_ffffffffffffff90 >> 0x20),(int)uVar3);
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if ((int)uVar3 < 0) break;
    local_48[2] = 0;
    local_48[3] = 0;
    local_48[4] = 0;
    local_48[0] = 0;
    local_48[1] = 0;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar1,7,0x12);
    }
    KeInitializeEvent(local_48 + 2,0);
    in_stack_ffffffffffffff90 = in_stack_ffffffffffffff90 & 0xffffffff00000000;
    uVar5 = 0;
    param_2 = param_1;
    uVar2 = IoBuildDeviceIoControlRequest(0x220007);
    if (uVar2 == 0) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        in_stack_ffffffffffffff90 = in_stack_ffffffffffffff90 & 0xffffffff00000000;
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x13,uVar5,
                          (char)local_48[0]);
      }
      uVar2 = 0xc000009a;
    }
    else {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        in_stack_ffffffffffffff90 = uVar2;
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      uVar3 = IofCallDriver(param_1);
      param_2 = uVar2;
      if ((int)uVar3 == 0x103) {
        uVar5 = 0;
        param_2 = 0;
        KeWaitForSingleObject(local_48 + 2);
        uVar3 = local_48[0];
      }
      uVar2 = uVar3 & 0xffffffff;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        in_stack_ffffffffffffff90 = CONCAT44((int)(in_stack_ffffffffffffff90 >> 0x20),(int)uVar3);
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x15,uVar5,
                          (char)uVar3);
      }
      if (-1 < (int)uVar3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar2;
        }
        if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
          return uVar2;
        }
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,0x11);
        return uVar2;
      }
    }
    uVar4 = uVar4 + 1;
    if (2 < uVar4) {
      return uVar2;
    }
  }
  return uVar3;
}



===== WPP_RECORDER_SF_ @ 14000d190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,&WPP_a133576297673b8c8ce34a9383ada487_Traceguids,param_4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,&WPP_a133576297673b8c8ce34a9383ada487_Traceguids,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 14000d24c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a133576297673b8c8ce34a9383ada487_Traceguids,0x17,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,0,7,&WPP_a133576297673b8c8ce34a9383ada487_Traceguids,0x17,
                  &uStack0000000000000030,4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 14000d2ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,&WPP_a133576297673b8c8ce34a9383ada487_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,&WPP_a133576297673b8c8ce34a9383ada487_Traceguids,param_4,
                  &param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 14000d3d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a133576297673b8c8ce34a9383ada487_Traceguids,0x14,&uStack0000000000000030,8,0);
  }
  WppAutoLogTrace(param_1,0,6,&WPP_a133576297673b8c8ce34a9383ada487_Traceguids,0x14,
                  &uStack0000000000000030,8,0);
  return;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 14000d470 =====

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
    _DAT_140014648 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140017040);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140017008);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140017078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 14000d524 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker
            (unaff_retaddr,1,"bthusb.sys",param_2,param_3,
             "NTSTATUS indicates success but USBD_STATUS indicates failure.");
  return;
}



===== MicrosoftTelemetryAssertTriggeredMsgKM @ 14000d560 =====

void MicrosoftTelemetryAssertTriggeredMsgKM(char *param_1)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,0,(char *)0x0,0xffffffff,0xffffffff,param_1)
  ;
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 14000d590 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000d765) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined4 param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,char *param_6)

{
  code *pcVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  char *pcVar11;
  undefined8 *puVar12;
  byte *pbVar13;
  longlong lVar14;
  undefined1 *puVar15;
  int iVar16;
  undefined1 auStack_288 [8];
  undefined1 auStack_280 [116];
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  char *local_200;
  IMAGE_DOS_HEADER *local_1f8;
  undefined1 local_1e8 [32];
  undefined4 *local_1c8;
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
  int local_140;
  undefined4 local_13c;
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
  int local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  puVar15 = auStack_288;
  local_38 = __security_cookie ^ (ulonglong)auStack_288;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_14000df27;
  local_20c = param_2;
  local_208 = param_4;
  local_200 = param_3;
  local_1f8 = param_1;
  uVar2 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar15 = auStack_288;
  for (plVar8 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar8 != &g_MicrosoftTelemetryAssertsTriggeredList; plVar8 = (longlong *)*plVar8
      ) {
    plVar7 = plVar8 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar7 == param_1) goto LAB_14000d6ec;
  }
  plVar7 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar14 = _DAT_fffff78000000320;
  puVar15 = auStack_288;
  if (plVar7 != (longlong *)0x0) {
    *plVar7 = (longlong)param_1;
    uVar5 = KeQueryTimeIncrement();
    puVar15 = auStack_288;
    plVar7[2] = 0;
    *(undefined4 *)(plVar7 + 3) = 0;
    puVar12 = &g_MicrosoftTelemetryAssertsTriggeredList;
    plVar7[1] = (longlong)((ulonglong)uVar5 * lVar14) / 10000 + -0xea61;
    plVar8 = plVar7 + 4;
    plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar10 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar8 = (longlong *)(*pcVar1)();
      puVar15 = auStack_280;
    }
    *plVar8 = (longlong)plVar10;
    plVar8[1] = (longlong)puVar12;
    plVar10[1] = (longlong)plVar8;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar8;
LAB_14000d6ec:
    *(int *)(plVar7 + 2) = (int)plVar7[2] + 1;
    *(int *)((longlong)plVar7 + 0x14) = *(int *)((longlong)plVar7 + 0x14) + 1;
    lVar14 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar15 + -8) = 0x14000d6fc;
    uVar5 = KeQueryTimeIncrement();
    lVar14 = (longlong)((ulonglong)uVar5 * lVar14) / 10000;
    if (60000 < (ulonglong)(lVar14 - plVar7[1])) {
      if ((param_1 < &IMAGE_DOS_HEADER_140000000) || ((IMAGE_DOS_HEADER *)0x140023000 < param_1)) {
        iVar16 = 0;
      }
      else {
        iVar16 = (int)param_1 + -0x40000000;
      }
      *(int *)(puVar15 + 0x70) = (int)plVar7[2];
      *(undefined4 *)(puVar15 + 0x74) = *(undefined4 *)((longlong)plVar7 + 0x14);
      plVar7[1] = lVar14;
      *(int *)(puVar15 + 0x6c) = (int)plVar7[3];
      *(undefined8 *)(puVar15 + -8) = 0x14000d7b2;
      KeReleaseSpinLock(&g_AssertSpinLock,CONCAT71((int7)((ulonglong)lVar14 >> 8),uVar2));
      pcVar11 = local_200;
      if (local_200 == (char *)0x0) {
        pcVar11 = g_ModuleName;
      }
      lVar14 = -1;
      local_200 = pcVar11;
      if (*(int *)(puVar15 + 0x7c) == 0) {
        if (((5 < DAT_140017040) && ((_DAT_140017050 & 0x400000000000) != 0)) &&
           ((DAT_140017058 & 0x400000000000) == DAT_140017058)) {
          *(undefined4 *)(puVar15 + 100) = 10;
          local_1c8 = (undefined4 *)(puVar15 + 100);
          local_1b8 = puVar15 + 0x60;
          local_1a8 = puVar15 + 0x5c;
          local_198 = puVar15 + 0x58;
          local_1c0 = 4;
          *(int *)(puVar15 + 0x60) = iVar16;
          local_1b0 = 4;
          *(dword *)(puVar15 + 0x5c) = 0x3b351c20;
          local_1a0 = 4;
          *(dword *)(puVar15 + 0x58) = 0x23000;
          local_190 = 4;
          local_188 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_188 = "<unknown>";
          }
          lVar9 = -1;
          do {
            lVar9 = lVar9 + 1;
          } while (local_188[lVar9] != '\0');
          local_180 = (int)lVar9 + 1;
          *(undefined4 *)(puVar15 + 0x54) = *(undefined4 *)(puVar15 + 0x70);
          local_178 = puVar15 + 0x54;
          *(undefined4 *)(puVar15 + 0x50) = *(undefined4 *)(puVar15 + 0x74);
          local_168 = puVar15 + 0x50;
          local_17c = 0;
          local_170 = 4;
          local_160 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x14000daa4;
          bVar3 = KeGetCurrentIrql();
          *(uint *)(puVar15 + 0x68) = (uint)bVar3;
          local_158 = puVar15 + 0x68;
          if (param_6 == (char *)0x0) {
            param_6 = "<unknown>";
          }
          if (param_6 == (char *)0x0) {
            param_6 = "";
            local_140 = 1;
          }
          else {
            lVar9 = -1;
            do {
              lVar9 = lVar9 + 1;
            } while (param_6[lVar9] != '\0');
            local_140 = (int)lVar9 + 1;
          }
          pbVar13 = &DAT_140012470;
          *(undefined1 **)(puVar15 + 0x28) = local_1e8;
          *(undefined4 *)(puVar15 + 0x20) = 0xb;
          local_148 = param_6;
          goto LAB_14000d9aa;
        }
      }
      else if (((5 < DAT_140017040) && ((_DAT_140017050 & 0x400000000000) != 0)) &&
              ((DAT_140017058 & 0x400000000000) == DAT_140017058)) {
        local_204 = 10;
        local_1c8 = &local_204;
        local_1b8 = puVar15 + 0x78;
        local_1a8 = puVar15 + 0x68;
        local_198 = puVar15 + 0x50;
        local_1c0 = 4;
        *(int *)(puVar15 + 0x78) = iVar16;
        local_1b0 = 4;
        *(dword *)(puVar15 + 0x68) = 0x3b351c20;
        local_1a0 = 4;
        *(dword *)(puVar15 + 0x50) = 0x23000;
        local_190 = 4;
        local_188 = g_ModuleName;
        if (g_ModuleName == (char *)0x0) {
          local_188 = "<unknown>";
        }
        lVar9 = -1;
        do {
          lVar9 = lVar9 + 1;
        } while (local_188[lVar9] != '\0');
        local_180 = (int)lVar9 + 1;
        *(undefined4 *)(puVar15 + 0x54) = *(undefined4 *)(puVar15 + 0x70);
        local_178 = puVar15 + 0x54;
        *(undefined4 *)(puVar15 + 0x58) = *(undefined4 *)(puVar15 + 0x74);
        local_168 = puVar15 + 0x58;
        local_17c = 0;
        local_170 = 4;
        local_160 = 4;
        *(undefined8 *)(puVar15 + -8) = 0x14000d8db;
        bVar3 = KeGetCurrentIrql();
        *(uint *)(puVar15 + 0x5c) = (uint)bVar3;
        local_158 = puVar15 + 0x5c;
        if (pcVar11 == (char *)0x0) {
          pcVar11 = "";
          local_140 = 1;
        }
        else {
          lVar9 = -1;
          do {
            lVar9 = lVar9 + 1;
          } while (pcVar11[lVar9] != '\0');
          local_140 = (int)lVar9 + 1;
        }
        *(undefined4 *)(puVar15 + 0x60) = local_208;
        local_138 = puVar15 + 0x60;
        *(undefined4 *)(puVar15 + 100) = param_5;
        local_128 = puVar15 + 100;
        if (param_6 == (char *)0x0) {
          param_6 = "<unknown>";
        }
        local_130 = 4;
        local_120 = 4;
        if (param_6 == (char *)0x0) {
          param_6 = "";
          local_110 = 1;
        }
        else {
          lVar9 = -1;
          do {
            lVar9 = lVar9 + 1;
          } while (param_6[lVar9] != '\0');
          local_110 = (int)lVar9 + 1;
        }
        pbVar13 = &DAT_140012320;
        *(undefined1 **)(puVar15 + 0x28) = local_1e8;
        *(undefined4 *)(puVar15 + 0x20) = 0xe;
        local_10c = 0;
        local_148 = pcVar11;
        local_118 = param_6;
LAB_14000d9aa:
        local_150 = 4;
        local_13c = 0;
        *(undefined8 *)(puVar15 + -8) = 0x14000d9b9;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x140017040,pbVar13,0,0,*(undefined4 *)(puVar15 + 0x20),
                   *(undefined8 **)(puVar15 + 0x28));
      }
      if ((DAT_140017078 == 0) || (*(int *)(puVar15 + 0x6c) != 0)) goto LAB_14000df27;
      *(undefined8 *)(puVar15 + -8) = 0x14000db3c;
      cVar4 = KeGetCurrentIrql();
      if (cVar4 != '\0') goto LAB_14000df27;
      *(undefined4 *)(puVar15 + 0x40) = 0;
      *(undefined8 *)(puVar15 + 0x38) = 0;
      *(undefined8 *)(puVar15 + 0x30) = 0;
      *(undefined8 *)(puVar15 + 0x28) = 0x23000;
      *(undefined8 *)(puVar15 + 0x20) = 0x3b351c20;
      *(undefined8 *)(puVar15 + -8) = 0x14000db85;
      iVar6 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1,iVar16);
      if (*(int *)(puVar15 + 0x7c) == 0) {
        if (((5 < DAT_140017040) && ((_DAT_140017050 & 0x400000000000) != 0)) &&
           ((DAT_140017058 & 0x400000000000) == DAT_140017058)) {
          *(undefined4 *)(puVar15 + 0x6c) = 10;
          *(int *)(puVar15 + 100) = iVar16;
          *(dword *)(puVar15 + 0x60) = 0x3b351c20;
          *(dword *)(puVar15 + 0x5c) = 0x23000;
          local_a8 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_a8 = "<unknown>";
          }
          do {
            lVar14 = lVar14 + 1;
          } while (local_a8[lVar14] != '\0');
          local_a0 = (int)lVar14;
          *(undefined4 *)(puVar15 + 0x58) = *(undefined4 *)(puVar15 + 0x70);
          *(undefined4 *)(puVar15 + 0x54) = *(undefined4 *)(puVar15 + 0x74);
          *(undefined1 **)(puVar15 + 0x28) = local_108;
          *(undefined4 *)(puVar15 + 0x20) = 10;
          pbVar13 = &DAT_1400124dd;
          *(int *)(puVar15 + 0x50) = iVar6;
          goto LAB_14000deb8;
        }
      }
      else if (((5 < DAT_140017040) && ((_DAT_140017050 & 0x400000000000) != 0)) &&
              ((DAT_140017058 & 0x400000000000) == DAT_140017058)) {
        *(undefined4 *)(puVar15 + 0x6c) = 10;
        *(int *)(puVar15 + 100) = iVar16;
        *(dword *)(puVar15 + 0x60) = 0x3b351c20;
        *(dword *)(puVar15 + 0x5c) = 0x23000;
        local_a8 = g_ModuleName;
        if (g_ModuleName == (char *)0x0) {
          local_a8 = "<unknown>";
        }
        lVar9 = -1;
        do {
          lVar9 = lVar9 + 1;
        } while (local_a8[lVar9] != '\0');
        local_a0 = (int)lVar9;
        *(undefined4 *)(puVar15 + 0x58) = *(undefined4 *)(puVar15 + 0x70);
        *(undefined4 *)(puVar15 + 0x54) = *(undefined4 *)(puVar15 + 0x74);
        *(int *)(puVar15 + 0x50) = iVar6;
        if (local_200 == (char *)0x0) {
          local_68 = "";
          local_60 = 1;
        }
        else {
          do {
            lVar14 = lVar14 + 1;
          } while (local_200[lVar14] != '\0');
          local_60 = (int)lVar14 + 1;
          local_68 = local_200;
        }
        pbVar13 = &DAT_1400123ca;
        *(undefined4 *)(puVar15 + 0x68) = local_208;
        local_58 = puVar15 + 0x68;
        *(undefined4 *)(puVar15 + 0x78) = param_5;
        local_48 = puVar15 + 0x78;
        *(undefined1 **)(puVar15 + 0x28) = local_108;
        *(undefined4 *)(puVar15 + 0x20) = 0xd;
        local_5c = 0;
        local_50 = 4;
        local_40 = 4;
LAB_14000deb8:
        local_a0 = local_a0 + 1;
        local_70 = 4;
        local_78 = puVar15 + 0x50;
        local_80 = 4;
        local_88 = puVar15 + 0x54;
        local_90 = 4;
        local_98 = puVar15 + 0x58;
        local_9c = 0;
        local_b0 = 4;
        local_b8 = puVar15 + 0x5c;
        local_c0 = 4;
        local_c8 = puVar15 + 0x60;
        local_d0 = 4;
        local_d8 = puVar15 + 100;
        local_e0 = 4;
        local_e8 = puVar15 + 0x6c;
        *(undefined8 *)(puVar15 + -8) = 0x14000deca;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x140017040,pbVar13,0,0,*(undefined4 *)(puVar15 + 0x20),
                   *(undefined8 **)(puVar15 + 0x28));
      }
      if (iVar6 != 0) goto LAB_14000df27;
      *(undefined8 *)(puVar15 + -8) = 0x14000dedc;
      uVar2 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar8 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar8[-4] == local_1f8) {
            *(int *)(plVar8 + -1) = (int)plVar8[-1] + 1;
            break;
          }
          plVar8 = (longlong *)*plVar8;
        } while ((longlong **)plVar8 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x14000df22;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar2);
LAB_14000df27:
  *(undefined8 *)(puVar15 + -8) = 0x14000df36;
  return;
}



===== UninitializeTelemetryAssertsKM @ 14000df60 =====

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
    *(undefined8 *)(puVar6 + -8) = 0x14000dff3;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x14000e010;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_140017098;
    DAT_140017098 = 0;
    DAT_140017078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14000e03a;
    EtwUnregister(uVar3);
    uVar3 = DAT_140017028;
    DAT_140017028 = 0;
    _DAT_140017008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14000e05c;
    EtwUnregister(uVar3);
    uVar3 = DAT_140017060;
    DAT_140017060 = 0;
    DAT_140017040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14000e07e;
    EtwUnregister(uVar3);
  }
  return;
}



===== operator_delete @ 14000e098 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePool();
  }
  return;
}



===== LockedList_EnqueueTail @ 14000e0bc =====

void LockedList_EnqueueTail(undefined8 param_1,_LIST_ENTRY *param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  _LIST_ENTRY *p_Var3;
  _LOCKED_LIST *p_Var4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(g_PdoLockedList.ListLock);
  puVar5 = auStack_28;
  p_Var4 = &g_PdoLockedList;
  p_Var3 = g_PdoLockedList.ListHead.Blink;
  if ((_LOCKED_LIST *)(g_PdoLockedList.ListHead.Blink)->Flink != &g_PdoLockedList) {
    p_Var3 = (_LIST_ENTRY *)0x3;
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)();
    puVar5 = auStack_20;
  }
  param_2->Flink = &p_Var4->ListHead;
  param_2->Blink = p_Var3;
  p_Var3->Flink = param_2;
  g_PdoLockedList.Count = g_PdoLockedList.Count + 1;
  *(undefined8 *)(puVar5 + -8) = 0x14000e119;
  g_PdoLockedList.ListHead.Blink = param_2;
  KeReleaseSpinLock(g_PdoLockedList.ListLock,uVar2);
  return;
}



===== LockedList_RemoveEntry @ 14000e12c =====

longlong * LockedList_RemoveEntry(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *plVar4;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(g_PdoLockedList.ListLock);
  lVar1 = *param_2;
  if ((*(longlong **)(lVar1 + 8) == param_2) &&
     (plVar4 = (longlong *)param_2[1], (longlong *)*plVar4 == param_2)) {
    *plVar4 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar4;
    g_PdoLockedList.Count = g_PdoLockedList.Count + -1;
    KeReleaseSpinLock(g_PdoLockedList.ListLock,CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar3));
    return param_2;
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  plVar4 = (longlong *)(*pcVar2)();
  return plVar4;
}



===== BthLib_Unload @ 14000e194 =====

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
  while (pppplVar2 = DAT_140014628, (longlong *****)DAT_140014628 != &DAT_140014628) {
    if ((((longlong *****)DAT_140014628[1] != &DAT_140014628) ||
        (pppplVar1 = (longlong ****)*DAT_140014628, (longlong ****)pppplVar1[1] != DAT_140014628))
       || (DAT_140014628 = pppplVar1, pppplVar1[1] = (longlong ***)&DAT_140014628,
          (longlong *****)*local_10 != &local_18)) goto LAB_14000e271;
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
LAB_14000e271:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== RtlStringCchPrintfW @ 14000e288 =====

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



===== RefObj_AddTrackingBlock @ 14000e304 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RefObj_AddTrackingBlock
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x10) + 0x404);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  lVar3 = *(longlong *)(param_1 + 0x10);
  lVar5 = (longlong)(iVar2 % 0x19);
  *(undefined4 *)(lVar3 + 0x18 + lVar5 * 0x28) = 0;
  *(undefined8 *)(lVar3 + 0x20 + lVar5 * 0x28) = param_3;
  *(undefined4 *)(lVar3 + 0x28 + lVar5 * 0x28) = param_2;
  *(undefined8 *)(lVar3 + 0x30 + lVar5 * 0x28) = param_4;
  *(undefined8 *)(lVar3 + 0x38 + lVar5 * 0x28) = _DAT_fffff78000000320;
  puVar6 = (undefined8 *)ExAllocatePool2(0x40,0x28,0x54666552);
  if (puVar6 == (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x10) + 4);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  else {
    puVar6[3] = param_3;
    puVar6[1] = param_4;
    *(undefined4 *)(puVar6 + 4) = param_2;
    lVar3 = *(longlong *)(param_1 + 0x10);
    puVar6[2] = _DAT_fffff78000000320;
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 8);
    lVar3 = *(longlong *)(param_1 + 0x10);
    *puVar6 = *(undefined8 *)(lVar3 + 0x10);
    *(undefined8 **)(lVar3 + 0x10) = puVar6;
    KeReleaseSpinLock(*(longlong *)(param_1 + 0x10) + 8,
                      CONCAT71((int7)((ulonglong)lVar3 >> 8),uVar4));
  }
  return;
}



===== RefObj_GlobalsInit @ 14000e430 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RefObj_GlobalsInit(void)

{
  _DAT_140014630 = &DAT_140014628;
  DAT_140014628 = &DAT_140014628;
  KeInitializeSpinLock(&BthLib_RefObjGlobals);
  MmIsDriverVerifyingByAddress(RefObj_GlobalsInit);
  return;
}



===== RefObj_ReleaseEx @ 14000e47c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RefObj_ReleaseEx(int *param_1,longlong param_2,undefined4 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 uVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 uStack_40;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar11 = (undefined8 *)auStack_38;
  if (*(longlong *)(param_1 + 4) != 0) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 4) + 0x404);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    lVar3 = *(longlong *)(param_1 + 4);
    lVar9 = (longlong)(iVar2 % 0x19);
    *(undefined4 *)(lVar3 + 0x18 + lVar9 * 0x28) = 1;
    *(undefined4 *)(lVar3 + 0x28 + lVar9 * 0x28) = param_3;
    *(longlong *)(lVar3 + 0x30 + lVar9 * 0x28) = param_2;
    *(undefined8 *)(lVar3 + 0x20 + lVar9 * 0x28) = param_4;
    *(undefined8 *)(lVar3 + 0x38 + lVar9 * 0x28) = _DAT_fffff78000000320;
    uVar8 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 4) + 8);
    puVar12 = (undefined8 *)(*(longlong *)(param_1 + 4) + 0x10);
    puVar7 = *(undefined8 **)(*(longlong *)(param_1 + 4) + 0x10);
    do {
      puVar6 = puVar7;
      puVar5 = puVar12;
      if (puVar6 == (undefined8 *)0x0) goto LAB_14000e540;
      puVar12 = puVar6;
      puVar7 = (undefined8 *)*puVar6;
    } while (puVar6[1] != param_2);
    *puVar5 = (undefined8 *)*puVar6;
LAB_14000e540:
    KeReleaseSpinLock(*(longlong *)(param_1 + 4) + 8,CONCAT71((int7)((ulonglong)puVar5 >> 8),uVar8))
    ;
    puVar11 = (undefined8 *)auStack_38;
    if (puVar6 == (undefined8 *)0x0) {
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 4) + 4);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 + -1 < 0) {
        LOCK();
        *(int *)(*(longlong *)(param_1 + 4) + 4) = *(int *)(*(longlong *)(param_1 + 4) + 4) + 1;
        UNLOCK();
        pcVar4 = (code *)swi(0x2c);
        (*pcVar4)();
        puVar11 = (undefined8 *)auStack_30;
      }
    }
    else {
      ExFreePool(puVar6);
      puVar11 = (undefined8 *)auStack_38;
    }
  }
  LOCK();
  iVar2 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    lVar3 = *(longlong *)(param_1 + 4);
    puVar12 = puVar11;
    if (lVar3 != 0) {
      puVar11[-1] = 0x14000e5a4;
      uVar8 = KeAcquireSpinLockRaiseToDpc(lVar3 + 8);
      plVar10 = *(longlong **)(lVar3 + 0x10);
      if (plVar10 != (longlong *)0x0) {
        pcVar4 = (code *)swi(0x2c);
        (*pcVar4)();
        puVar12 = puVar11 + 1;
        do {
          plVar10 = (longlong *)*plVar10;
          *puVar11 = 0x14000e5c1;
          ExFreePool();
        } while (plVar10 != (longlong *)0x0);
      }
      *(undefined8 *)((longlong)puVar12 + -8) = 0x14000e5dc;
      KeReleaseSpinLock(lVar3 + 8,uVar8);
    }
    pcVar4 = *(code **)(param_1 + 2);
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    *(undefined8 *)((longlong)puVar12 + -8) = 0x14000e5f7;
    (*pcVar4)(param_1);
    if (lVar3 != 0) {
      *(undefined8 *)((longlong)puVar12 + -8) = 0x14000e606;
      ExFreePool(lVar3);
    }
  }
  return iVar2 + -1;
}



===== ResourceQueue_GetItem @ 14000e630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong ResourceQueue_GetItem(int *param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  
  lVar2 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 2);
  if (-1 < *param_1) {
    lVar2 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x16),param_1 + 4);
    if (lVar2 != 0) {
      param_1[8] = param_1[8] + 1;
    }
  }
  KeReleaseSpinLock(param_1 + 2,uVar1);
  return lVar2;
}



===== ResourceQueue_Initialize @ 14000e6b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ResourceQueue_Initialize(undefined4 *param_1,undefined *param_2)

{
  undefined4 *puVar1;
  undefined8 in_stack_00000030;
  
  memset(param_1 + 1,0,0x5c);
  *param_1 = 0;
  KeInitializeSpinLock(param_1 + 2);
  puVar1 = param_1 + 4;
  *(undefined4 **)(param_1 + 6) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  KeInitializeEvent(param_1 + 10,0,0);
  param_1[8] = 0;
  *(code **)(param_1 + 0x10) = BthUsb_ScoGetTransferContextImpl;
  *(code **)(param_1 + 0x12) = BthUsb_ScoFreeTransferContextImpl;
  *(code **)(param_1 + 0x14) = BthUsb_ScoDestroyTransferContextsImpl;
  *(undefined8 *)(param_1 + 0x16) = in_stack_00000030;
  (*(code *)param_2)(in_stack_00000030,puVar1);
  return;
}



===== ResourceQueue_Start @ 14000e758 =====

void ResourceQueue_Start(undefined4 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 2);
  *param_1 = 0;
  KeClearEvent(param_1 + 10);
  KeReleaseSpinLock(param_1 + 2,uVar1);
  return;
}



===== ResourceQueue_Stop @ 14000e7b8 =====

void ResourceQueue_Stop(undefined4 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 2);
  *param_1 = 0xc0000022;
  KeReleaseSpinLock(param_1 + 2,uVar1);
  return;
}



===== ResourceQueue_StopAndWait @ 14000e800 =====

void ResourceQueue_StopAndWait(undefined4 *param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 2);
  iVar1 = param_1[8];
  *param_1 = 0xc0000022;
  KeReleaseSpinLock(param_1 + 2,uVar2);
  if (iVar1 != 0) {
    KeWaitForSingleObject(param_1 + 10,0,0,0,0);
  }
  return;
}



===== _guard_check_icall @ 14000e880 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 14000e898 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000e8bc =====

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



===== __cpu_features_init @ 14000e930 =====

/* WARNING: Removing unreachable block (ram,0x00014000e99a) */
/* WARNING: Removing unreachable block (ram,0x00014000e949) */
/* WARNING: Removing unreachable block (ram,0x00014000e93a) */

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



===== __security_check_cookie @ 14000ea00 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000ea40 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000ea70 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ea70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000eaa0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000eb00 =====

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



===== memset @ 14000ee00 =====

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



===== __memset_repmovs @ 14000ef40 =====

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



===== __memset_query @ 14000efc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000f040 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000f180 =====

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



===== __memset_spec_plain @ 14000f200 =====

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



===== BthUsb_DriverUnload @ 140018008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl BthUsb_DriverUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl BthUsb_DriverUnload(_DRIVER_OBJECT *param_1)

{
  undefined8 uVar1;
  _tlgProvider_t *p_Var2;
  char cVar3;
  undefined *puVar4;
  _GUID *in_R8;
  _GUID *p_Var5;
  _tlgWrapSz<unsigned_short> local_res10;
  undefined8 local_res18;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  p_Var5 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
  p_Var2 = *(_tlgProvider_t **)(WPP_GLOBAL_Control + 0x18);
  WPP_RECORDER_AND_TRACE_SF_
            (p_Var2,cVar3,in_R8,p_Var5,4,2,0x10,&WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids);
  if (((5 < DAT_140014000) && ((_DAT_140014010 & 0x400000000000) != 0)) &&
     ((DAT_140014018 & 0x400000000000) == DAT_140014018)) {
    local_res18 = 0x2000800;
    local_res10.Psz = L"BthUsb.sys";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>_>
              (p_Var2,&DAT_140011d11,in_R8,p_Var5,(_tlgWrapperByVal<8> *)&local_res18,&local_res10);
  }
  uVar1 = DAT_140014020;
  DAT_140014020 = 0;
  DAT_140014000 = 0;
  EtwUnregister(uVar1);
  UninitializeTelemetryAssertsKM();
  if (g_EtwRegHandle != 0) {
    EtwUnregister();
    g_EtwRegHandle = 0;
  }
  BthLib_Unload();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar4 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar4 != (undefined *)0x0; puVar4 = *(undefined **)(puVar4 + 0x10)) {
        if (*(longlong *)(puVar4 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar4 + 0x38) = 0;
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



===== BthUsb_GetPhysicalDeviceObjectName @ 1400181f8 =====

/* long __cdecl BthUsb_GetPhysicalDeviceObjectName(struct _DEVICE_OBJECT * __ptr64,struct
   _UNICODE_STRING * __ptr64) */

long __cdecl BthUsb_GetPhysicalDeviceObjectName(_DEVICE_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  char cVar3;
  char cVar4;
  undefined8 in_R8;
  ulonglong uVar5;
  uint local_res10 [2];
  uint *puVar6;
  
  local_res10[0] = 0;
  cVar4 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
     (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x11,
             &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)param_1);
  param_2->Length = 0;
  param_2->MaximumLength = 0;
  puVar6 = local_res10;
  param_2->Buffer = (wchar_t *)0x0;
  uVar5 = 0;
  iVar1 = IoGetDeviceProperty(param_1,0xb);
  if (iVar1 == -0x3fffffdd) {
    uVar5 = 0x42425355;
    pwVar2 = (wchar_t *)ExAllocatePool2(0x40,local_res10[0]);
    if (pwVar2 == (wchar_t *)0x0) {
      iVar1 = -0x3fffff66;
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
         (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar3 = '\0';
      }
      puVar6 = (uint *)CONCAT71((int7)((ulonglong)puVar6 >> 8),2);
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,uVar5,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x12,
                 &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids);
    }
    else {
      uVar5 = (ulonglong)local_res10[0];
      puVar6 = local_res10;
      iVar1 = IoGetDeviceProperty(param_1,0xb,uVar5,pwVar2);
      if (iVar1 < 0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar3 = '\0';
        }
        puVar6 = (uint *)CONCAT71((int7)((ulonglong)puVar6 >> 8),2);
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,uVar5,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x13,
                   &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)iVar1);
        ExFreePoolWithTag(pwVar2,0);
      }
      else {
        if (2 < local_res10[0]) {
          param_2->Length = (ushort)local_res10[0] - 2;
        }
        param_2->MaximumLength = (ushort)local_res10[0];
        param_2->Buffer = pwVar2;
      }
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_qD
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,uVar5,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,2,0x14,
             &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)param_1,(char)iVar1);
  return iVar1;
}



===== BthUsb_InitDeviceExtension @ 14001842c =====

/* long __cdecl BthUsb_InitDeviceExtension(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthUsb_InitDeviceExtension(_DEVICE_EXTENSION *param_1)

{
  _USB_DEVICE_DESCRIPTOR *p_Var1;
  ulong uVar2;
  int iVar3;
  undefined8 uVar4;
  char cVar5;
  char cVar6;
  undefined8 in_R8;
  ulong *puVar7;
  ulong local_res8 [2];
  undefined8 local_res10;
  undefined1 uVar8;
  undefined2 uVar9;
  
  local_res10 = 0;
  cVar6 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x17,
             &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)param_1);
  iVar3 = ExUuidCreate(param_1);
  if (iVar3 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x18,
               &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)iVar3);
    (param_1->DeviceExtensionSessionId).Data1 = 0;
    (param_1->DeviceExtensionSessionId).Data2 = 0;
    (param_1->DeviceExtensionSessionId).Data3 = 0;
    (param_1->DeviceExtensionSessionId).Data4[0] = '\0';
    (param_1->DeviceExtensionSessionId).Data4[1] = '\0';
    (param_1->DeviceExtensionSessionId).Data4[2] = '\0';
    (param_1->DeviceExtensionSessionId).Data4[3] = '\0';
    (param_1->DeviceExtensionSessionId).Data4[4] = '\0';
    (param_1->DeviceExtensionSessionId).Data4[5] = '\0';
    (param_1->DeviceExtensionSessionId).Data4[6] = '\0';
    (param_1->DeviceExtensionSessionId).Data4[7] = '\0';
  }
  BthUsb_ScoInitExtension(param_1);
  p_Var1 = param_1->DeviceDescriptor;
  puVar7 = (ulong *)0x20000;
  param_1->BulkInSize = 0x1000;
  iVar3 = IoOpenDeviceRegistryKey(param_1->BtDevice->PhysicalDeviceObject,1,0x20000,&local_res10);
  if (-1 < iVar3) {
    puVar7 = local_res8;
    local_res8[0] = 0;
    iVar3 = BthQueryKeyValue(local_res10,L"BulkInSize",puVar7);
    uVar2 = local_res8[0];
    if ((-1 < iVar3) && (local_res8[0] - 0x400 < 0xfc01)) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
      {
        cVar5 = '\0';
      }
      else {
        cVar5 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,puVar7,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x19,
                 &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)local_res8[0]);
      param_1->BulkInSize = uVar2;
    }
    ZwClose(local_res10);
    local_res10 = 0;
  }
  if (((p_Var1->bDeviceClass == 0xe0) && (p_Var1->bDeviceSubClass == '\x01')) &&
     (p_Var1->bDeviceProtocol == '\x01')) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    uVar9 = 0x1a;
    uVar8 = 4;
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    uVar9 = 0x1b;
    uVar8 = 3;
  }
  uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  WPP_RECORDER_AND_TRACE_SF_
            (uVar4,cVar5,puVar7,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,2,uVar9,
             &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids);
  LockedList_EnqueueTail(uVar4,&param_1->DevExtListEntry);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,puVar7,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1c,
             &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,0);
  return 0;
}



===== BthUsb_PnpCreateDevice @ 1400186c0 =====

/* long __cdecl BthUsb_PnpCreateDevice(struct _BTDEVICE * __ptr64) */

long __cdecl BthUsb_PnpCreateDevice(_BTDEVICE *param_1)

{
  longlong lVar1;
  void *_Dst;
  ulonglong uVar2;
  _DEVICE_OBJECT *p_Var3;
  char cVar4;
  char cVar5;
  long lVar6;
  undefined8 in_R8;
  undefined8 uVar7;
  undefined4 in_stack_ffffffffffffffc8;
  undefined4 uVar8;
  undefined4 in_stack_ffffffffffffffcc;
  
  cVar5 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  uVar8 = CONCAT31((int3)((uint)in_stack_ffffffffffffffc8 >> 8),4);
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x15,
             &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)param_1);
  uVar7 = 0x42425355;
  _Dst = (void *)ExAllocatePool2(0x40);
  if (_Dst == (void *)0x0) {
    lVar6 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0x498);
    uVar8 = 0x20;
    uVar7 = 0;
    IoInitializeRemoveLockEx((longlong)_Dst + 0x30,0x42425355,0,0);
    lVar1 = (longlong)_Dst + 0x480;
    param_1->MiniportContext = _Dst;
    *(longlong *)((longlong)_Dst + 0x488) = lVar1;
    *(longlong *)lVar1 = lVar1;
    p_Var3 = param_1->PhysicalDeviceObject;
    *(_BTDEVICE **)((longlong)_Dst + 0x10) = param_1;
    *(_DEVICE_OBJECT **)((longlong)_Dst + 0x28) = param_1->NextDeviceObject;
    BthUsb_GetPhysicalDeviceObjectName(p_Var3,(_UNICODE_STRING *)((longlong)_Dst + 0x18));
    uVar2 = BthQueryRadioCompatFlags(p_Var3,*(longlong *)(*(longlong *)((longlong)_Dst + 0x10) + 8))
    ;
    *(byte *)((longlong)_Dst + 0x495) = (byte)(uVar2 >> 0xd) & 1;
    lVar6 = 0;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_qD
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,uVar7,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_stack_ffffffffffffffcc,uVar8),2,
             0x16,&WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)param_1,(char)lVar6);
  return lVar6;
}



===== BthUsb_QuerySelectiveSuspend @ 14001882c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl BthUsb_QuerySelectiveSuspend(struct _BTDEVICE * __ptr64) */

uchar __cdecl BthUsb_QuerySelectiveSuspend(_BTDEVICE *param_1)

{
  byte *pbVar1;
  void *pvVar2;
  longlong lVar3;
  int iVar4;
  byte bVar5;
  char cVar6;
  undefined1 auStackY_138 [32];
  ushort local_e8 [2];
  int local_e4 [3];
  undefined8 local_d8 [2];
  undefined4 local_c8 [9];
  undefined4 local_a4;
  ushort *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined2 local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  pvVar2 = param_1->MiniportContext;
  cVar6 = '\0';
  local_d8[0] = 0;
  bVar5 = 0;
  local_e8[0] = 0;
  local_e4[0] = 1;
  memset(local_c8,0,0x88);
  iVar4 = IoOpenDeviceRegistryKey(param_1->PhysicalDeviceObject,1,0x20000,local_d8);
  if (iVar4 < 0) {
LAB_14001891c:
    local_a0 = local_e8;
    local_c8[0] = 0x130088;
    local_a4 = 2;
    local_98 = 0;
    local_44 = 0;
    local_90 = 0;
    iVar4 = USBCallSyncEx(*(longlong *)((longlong)pvVar2 + 0x28),(longlong)local_c8,500,
                          (longlong)pvVar2 + 0x30);
    if (iVar4 < 0) goto LAB_140018a12;
    lVar3 = *(longlong *)((longlong)pvVar2 + 0x68);
    *(byte *)((longlong)pvVar2 + 0x492) = (byte)local_e8[0] & 1;
    *(byte *)((longlong)pvVar2 + 0x490) = *(byte *)(lVar3 + 7) >> 5 & 1;
    *(byte *)((longlong)pvVar2 + 0x491) = *(byte *)(lVar3 + 7) >> 6 & 1;
    if (((local_e8[0] & 1) == 0) || ((*(byte *)(lVar3 + 7) & 0x60) != 0x60)) goto LAB_140018a12;
    *(undefined1 *)((longlong)pvVar2 + 0x493) = 0;
    bVar5 = 1;
    iVar4 = IoOpenDeviceRegistryKey(param_1->PhysicalDeviceObject,1,0x20000,local_d8);
    if (-1 < iVar4) {
      iVar4 = BthQueryKeyValue(local_d8[0],L"SelectiveSuspendSupported",local_e4);
      if ((-1 < iVar4) && (local_e4[0] == 0)) {
        *(undefined1 *)((longlong)pvVar2 + 0x493) = 1;
        bVar5 = 0;
      }
      ZwClose(local_d8[0]);
      if (bVar5 == 0) goto LAB_140018a12;
    }
  }
  else {
    iVar4 = BthQueryKeyValue(local_d8[0],L"ForceSelectiveSuspend",local_e4);
    if ((-1 < iVar4) && (local_e4[0] == 1)) {
      bVar5 = 1;
    }
    ZwClose(local_d8[0]);
    if (bVar5 == 0) goto LAB_14001891c;
    pbVar1 = (byte *)(*(longlong *)((longlong)pvVar2 + 0x68) + 7);
    *pbVar1 = *pbVar1 | 0x60;
    *(undefined1 *)((longlong)pvVar2 + 0x492) = 1;
    *(byte *)((longlong)pvVar2 + 0x490) =
         *(byte *)(*(longlong *)((longlong)pvVar2 + 0x68) + 7) >> 5 & 1;
    *(byte *)((longlong)pvVar2 + 0x491) =
         *(byte *)(*(longlong *)((longlong)pvVar2 + 0x68) + 7) >> 6 & 1;
  }
  *(undefined1 *)((longlong)pvVar2 + 0x494) = 1;
LAB_140018a12:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    cVar6 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,(ulonglong)bVar5,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1d,
             &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,bVar5);
  return bVar5;
}



===== BthUsb_WdfDeviceAdd @ 140018aa0 =====

/* long __cdecl BthUsb_WdfDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl BthUsb_WdfDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  long lVar1;
  
  lVar1 = Fdo::Make(param_2);
  return lVar1;
}



===== BthUsb_WdfDriverUnload @ 140018ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthUsb_WdfDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl BthUsb_WdfDriverUnload(WDFDRIVER__ *param_1)

{
  _DRIVER_OBJECT *p_Var1;
  
  p_Var1 = (_DRIVER_OBJECT *)(**(code **)(WdfFunctions_01031 + 0x3b0))(WdfDriverGlobals,param_1);
  BthUsb_DriverUnload(p_Var1);
  return;
}



===== TraceLoggingRegister_EtwRegister_EtwSetInformation @ 140018af8 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x140018b5b;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140018b7b;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140018b8f;
  return iVar6;
}



===== WppInitKm @ 140018ba8 =====

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



===== WppLoadTracingSupport @ 140018c84 =====

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



===== WppTraceCallback @ 140018dd0 =====

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



===== _tlgEnableCallback @ 140019060 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1400190dc =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140019117;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140019191:
  while( true ) {
    if (&UNK_1400137d7 < ppuVar3) {
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
      if (&UNK_1400137d7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140019117:
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
      if (&UNK_1400137d7 < ppuVar2) goto LAB_140019191;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140019191;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400191cc =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140019268;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140019268;
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
LAB_140019268:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400192d0 =====

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
              if (&UNK_1400137d7 < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 140019350 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140019370 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001946d;
  }
LAB_140019476:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001946d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140019476;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001943e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001943e;
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
    if (&UNK_1400137d7 < ppuVar3) goto LAB_140019476;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001946d;
}



===== Fdo @ 14001949c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: __cdecl Fdo::Fdo(class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct RECORDER_LOG__ * __ptr64,void (__cdecl*)(struct
   RECORDER_LOG__ * __ptr64),&void __cdecl WppRecorderLogCloseFunction(struct RECORDER_LOG__ *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct RECORDER_LOG__ *
   __ptr64,struct RECORDER_LOG__ * __ptr64,0,std::nullptr_t> > >) __ptr64 */

Fdo * __thiscall Fdo::Fdo(Fdo *this,undefined8 *param_2)

{
  undefined8 uVar1;
  RECORDER_LOG__ *pRVar2;
  char cVar3;
  undefined *puVar4;
  
  uVar1 = (**(code **)(WdfFunctions_01031 + 0x660))(WdfDriverGlobals);
  *(undefined8 *)this = uVar1;
  *(undefined8 *)(this + 8) = *param_2;
  *param_2 = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  puVar4 = WPP_GLOBAL_Control;
  pRVar2 = GetRecorderLog(this);
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(puVar4 + 0x18),cVar3,*(undefined8 *)this,pRVar2,4,1,10,
             &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)*(undefined8 *)this);
  if ((RECORDER_LOG__ *)*param_2 != (RECORDER_LOG__ *)0x0) {
    WppRecorderLogCloseFunction((RECORDER_LOG__ *)*param_2);
  }
  return this;
}



===== ~Fdo @ 140019568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: __cdecl Fdo::~Fdo(void) __ptr64 */

void __thiscall Fdo::~Fdo(Fdo *this)

{
  longlong lVar1;
  RECORDER_LOG__ *pRVar2;
  Fdo *pFVar3;
  char cVar4;
  undefined *puVar5;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  pFVar3 = this;
  puVar5 = WPP_GLOBAL_Control;
  pRVar2 = GetRecorderLog(this);
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(puVar5 + 0x18),cVar4,*(undefined8 *)pFVar3,pRVar2,4,1,0xb,
             &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)*(undefined8 *)pFVar3);
  if (*(longlong *)(this + 0x18) != 0) {
    IoAcquireRemoveLockEx
              (*(longlong *)(this + 0x18) + 0x30,*(undefined8 *)(this + 0x10),
               "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusb\\fdo.cpp",0x2b,0x20);
    IoReleaseRemoveLockAndWaitEx
              (*(longlong *)(this + 0x18) + 0x30,*(undefined8 *)(this + 0x10),0x20);
    lVar1 = *(longlong *)(this + 0x18);
    if (*(longlong *)(lVar1 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x20),0);
      *(undefined8 *)(lVar1 + 0x20) = 0;
      *(undefined4 *)(lVar1 + 0x18) = 0;
    }
    if (*(longlong *)(lVar1 + 0x60) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x60),0);
      *(undefined8 *)(lVar1 + 0x60) = 0;
    }
    if (*(longlong *)(lVar1 + 0x68) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x68),0);
      *(undefined8 *)(lVar1 + 0x68) = 0;
    }
    ExFreePoolWithTag(lVar1,0);
    **(undefined8 **)(this + 0x10) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  if (*(undefined8 **)(this + 0x28) != (undefined8 *)0x0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,**(undefined8 **)(this + 0x28));
  }
  if (*(undefined8 **)(this + 0x20) != (undefined8 *)0x0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,**(undefined8 **)(this + 0x20));
  }
  if (*(RECORDER_LOG__ **)(this + 8) != (RECORDER_LOG__ *)0x0) {
    WppRecorderLogCloseFunction(*(RECORDER_LOG__ **)(this + 8));
  }
  return;
}



===== EvtControllerTransportResetThunk @ 140019710 =====

/* private: static long __cdecl Fdo::EvtControllerTransportResetThunk(struct WDFDEVICE__ * __ptr64)
    */

long __cdecl Fdo::EvtControllerTransportResetThunk(WDFDEVICE__ *param_1)

{
  Fdo *this;
  ulonglong uVar1;
  RECORDER_LOG__ *pRVar2;
  char cVar3;
  longlong lVar4;
  undefined *puVar5;
  
  this = FromWdfDevice(param_1);
  lVar4 = *(longlong *)(this + 0x18) + 0x130;
  KeEnterCriticalRegion();
  uVar1 = 0;
  ExAcquirePushLockExclusiveEx(lVar4);
  BthUsb_ScoStopUsbTraffic(*(_DEVICE_EXTENSION **)(this + 0x18));
  uVar1 = USBResetPort(*(ulonglong *)(*(longlong *)(this + 0x18) + 0x28),uVar1);
  if ((int)uVar1 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    puVar5 = WPP_GLOBAL_Control;
    pRVar2 = GetRecorderLog(this);
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(puVar5 + 0x18),cVar3,*(undefined8 *)this,pRVar2,2,1,0x16,
               &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)*(undefined8 *)this,
               (char)uVar1);
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    puVar5 = WPP_GLOBAL_Control;
    pRVar2 = GetRecorderLog(this);
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(puVar5 + 0x18),cVar3,*(undefined8 *)this,pRVar2,4,1,0x17,
               &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)*(undefined8 *)this);
    BthUsb_ScoStartUsbTraffic(*(_DEVICE_EXTENSION **)(this + 0x18));
  }
  if (lVar4 != 0) {
    ExReleasePushLockExclusiveEx(lVar4,0);
    KeLeaveCriticalRegion();
  }
  return (int)uVar1;
}



===== EvtDeviceD0EntryThunk @ 140019870 =====

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
             in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x14,in_stack_ffffffffffffffd0,
             (char)*(undefined8 *)this,(char)param_2,uVar1);
  return 0;
}



===== EvtDeviceD0ExitThunk @ 140019900 =====

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
             in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x15,in_stack_ffffffffffffffd0,
             (char)*(undefined8 *)this,(char)param_2,uVar1);
  return 0;
}



===== EvtDevicePrepareHardware @ 140019990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl Fdo::EvtDevicePrepareHardware(void) __ptr64 */

long __thiscall Fdo::EvtDevicePrepareHardware(Fdo *this)

{
  _DEVICE_EXTENSION *p_Var1;
  longlong lVar2;
  uchar uVar3;
  long lVar4;
  RECORDER_LOG__ *pRVar5;
  Fdo *pFVar6;
  undefined8 uVar7;
  ReceiveQueue *this_00;
  char cVar8;
  undefined *puVar9;
  char cVar10;
  undefined *puVar11;
  undefined4 local_res8;
  uint local_resc;
  undefined2 uVar12;
  undefined8 local_48;
  ReceiveQueue *local_40;
  __uint64 local_38;
  uint local_30;
  undefined4 local_2c;
  undefined8 local_28;
  code *local_20;
  
  cVar8 = '\0';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
     (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar10 = '\0';
  }
  pFVar6 = this;
  puVar9 = WPP_GLOBAL_Control;
  pRVar5 = GetRecorderLog(this);
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(puVar9 + 0x18),cVar10,puVar9,pRVar5,4,1,0x10,
             &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)*(undefined8 *)pFVar6);
  p_Var1 = *(_DEVICE_EXTENSION **)(this + 0x18);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
     (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar10 = '\0';
  }
  puVar9 = &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids;
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x3e,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
  lVar4 = BthUsb_GetDeviceDescriptor(p_Var1);
  if (lVar4 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    uVar12 = 0x40;
  }
  else {
    lVar4 = BthUsb_GetConfigDescriptor(p_Var1);
    if (-1 < lVar4) {
      lVar4 = BthUsb_SelectConfigAndInitialize(p_Var1);
      goto LAB_140019af8;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    uVar12 = 0x3f;
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,puVar9,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar12,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
LAB_140019af8:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
     (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar10 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,puVar9,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x41,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)lVar4);
  if (-1 < lVar4) {
    lVar4 = BthUsb_InitDeviceExtension(*(_DEVICE_EXTENSION **)(this + 0x18));
    if (lVar4 < 0) {
      return lVar4;
    }
    uVar3 = BthUsb_QuerySelectiveSuspend(*(_BTDEVICE **)(this + 0x10));
    local_res8 = 8;
    local_resc = -(uint)(uVar3 != '\0') & 2;
    lVar4 = (*DAT_140014278)(BthDriverGlobals,*(undefined8 *)this,&local_res8);
    if (lVar4 < 0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        cVar8 = '\x01';
      }
      puVar11 = WPP_GLOBAL_Control;
      pRVar5 = GetRecorderLog(this);
      puVar9 = *(undefined **)this;
      uVar7 = *(undefined8 *)(puVar11 + 0x18);
      uVar12 = 0x11;
      puVar11 = puVar9;
    }
    else {
      lVar2 = *(longlong *)(this + 0x18);
      lVar4 = ReceiveQueue::Make(this,*(uint *)(lVar2 + 0x50),*(void **)(lVar2 + 0xa8),
                                 *(void **)(lVar2 + 0x78),
                                 (unique_ptr<ReceiveQueue,WdfCpp::Details::ObjectContextDeleter<ReceiveQueue>_>
                                  *)(this + 0x20));
      if (lVar4 < 0) {
        return lVar4;
      }
      lVar4 = TransmitQueue::Make(this,*(void **)(*(longlong *)(this + 0x18) + 0x90),
                                  (unique_ptr<TransmitQueue,WdfCpp::Details::ObjectContextDeleter<TransmitQueue>_>
                                   *)(this + 0x28));
      if (lVar4 < 0) {
        return lVar4;
      }
      this_00 = *(ReceiveQueue **)(this + 0x20);
      uVar7 = **(undefined8 **)(this + 0x28);
      local_38 = ReceiveQueue::GetDesiredBufferLength(this_00);
      local_40 = *(ReceiveQueue **)this_00;
      local_48 = 0x30;
      local_2c = 0;
      local_28 = uVar7;
      local_30 = ReceiveQueue::GetDesiredNumberOfPendingPackets(local_40);
      local_20 = EvtControllerTransportResetThunk;
      lVar4 = (*DAT_140014268)(BthDriverGlobals,*(undefined8 *)this,&local_48);
      if (-1 < lVar4) {
        return 0;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        cVar8 = '\x01';
      }
      puVar9 = WPP_GLOBAL_Control;
      pRVar5 = GetRecorderLog(this);
      puVar11 = *(undefined **)this;
      uVar7 = *(undefined8 *)(puVar9 + 0x18);
      uVar12 = 0x12;
    }
    WPP_RECORDER_AND_TRACE_SF_qd
              (uVar7,cVar8,puVar9,pRVar5,2,1,uVar12,&WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids
               ,(char)puVar11,(char)lVar4);
  }
  return lVar4;
}



===== EvtDevicePrepareHardwareThunk @ 140019d10 =====

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



===== EvtDeviceReleaseHardwareThunk @ 140019d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl Fdo::EvtDeviceReleaseHardwareThunk(struct WDFDEVICE__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl Fdo::EvtDeviceReleaseHardwareThunk(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  undefined8 *puVar1;
  Fdo *this;
  RECORDER_LOG__ *pRVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  longlong *plVar6;
  undefined *puVar7;
  
  this = FromWdfDevice(param_1);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  puVar7 = WPP_GLOBAL_Control;
  pRVar2 = GetRecorderLog(this);
  uVar4 = *(undefined8 *)(puVar7 + 0x18);
  WPP_RECORDER_AND_TRACE_SF_q
            (uVar4,cVar5,*(undefined8 *)this,pRVar2,4,1,0x13,
             &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)*(undefined8 *)this);
  puVar1 = *(undefined8 **)(this + 0x28);
  *(undefined8 *)(this + 0x28) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    uVar4 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*puVar1);
  }
  puVar1 = *(undefined8 **)(this + 0x20);
  *(undefined8 *)(this + 0x20) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    uVar4 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*puVar1);
  }
  plVar6 = (longlong *)(*(longlong *)(this + 0x18) + 0x480);
  if ((longlong *)*plVar6 != plVar6) {
    LockedList_RemoveEntry(uVar4,plVar6);
    lVar3 = *(longlong *)(this + 0x18) + 0x480;
    *(longlong *)(*(longlong *)(this + 0x18) + 0x488) = lVar3;
    *(longlong *)lVar3 = lVar3;
  }
  return 0;
}



===== Make @ 140019e24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl Fdo::Make(struct WDFDEVICE_INIT * __ptr64) */

long __cdecl Fdo::Make(WDFDEVICE_INIT *param_1)

{
  Fdo *pFVar1;
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
  WDFDEVICE__ *local_f8;
  WDFDEVICE_INIT *local_f0;
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
  local_f0 = param_1;
  iVar2 = (*DAT_140014270)(BthDriverGlobals,param_1);
  cVar9 = '\0';
  if (iVar2 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar9 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc,
               &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)iVar2);
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
    local_58 = 0x4242535500000038;
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
      (**(code **)(WdfFunctions_01031 + 0x1b8))(WdfDriverGlobals,local_f0,local_e8);
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
      local_f8 = (WDFDEVICE__ *)0x0;
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
      local_28 = PTR__WDF_Fdo_TYPE_INFO_140014060;
      pcStack_50 = WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,Fdo,1>::EvtObjectContextCleanupThunk;
      uStack_40 = 0x100000001;
      iVar2 = (**(code **)(WdfFunctions_01031 + 600))
                        (WdfDriverGlobals,&local_f0,&local_58,&local_f8);
      cVar9 = '\x01';
      if (-1 < iVar2) {
        pFVar5 = FromWdfDevice(local_f8);
        if (pFVar5 == (Fdo *)0x0) {
          pFVar5 = (Fdo *)0x0;
        }
        else {
          local_100 = local_108;
          local_108 = (RECORDER_LOG__ *)0x0;
          pFVar5 = (Fdo *)Fdo(pFVar5,&local_100);
        }
        pFVar1 = pFVar5 + 0x10;
        local_100 = (RECORDER_LOG__ *)CONCAT44(local_100._4_4_,4);
        iVar2 = (*BthFunctions)(BthDriverGlobals,local_f8,&local_100,pFVar1);
        if (iVar2 < 0) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          puVar10 = WPP_GLOBAL_Control;
          pRVar6 = GetRecorderLog(pFVar5);
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(puVar10 + 0x18),cVar9,*(undefined8 *)pFVar5,pRVar6,2,1,0xf,
                     &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)*(undefined8 *)pFVar5,
                     (char)iVar2);
          if (local_108 != (RECORDER_LOG__ *)0x0) {
            WppRecorderLogCloseFunction(local_108);
          }
          return iVar2;
        }
        lVar3 = BthUsb_PnpCreateDevice(*(_BTDEVICE **)pFVar1);
        if (lVar3 < 0) {
          if (local_108 != (RECORDER_LOG__ *)0x0) {
            WppRecorderLogCloseFunction(local_108);
          }
          return lVar3;
        }
        *(undefined8 *)(pFVar5 + 0x18) = **(undefined8 **)pFVar1;
        RegisterPLDRCapability(pFVar5);
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
               &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,(char)iVar2);
    if (local_108 != (RECORDER_LOG__ *)0x0) {
      WppRecorderLogCloseFunction(local_108);
    }
  }
  return iVar2;
}



===== RegisterPLDRCapability @ 14001a280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl Fdo::RegisterPLDRCapability(void) __ptr64 */

void __thiscall Fdo::RegisterPLDRCapability(Fdo *this)

{
  int iVar1;
  int iVar2;
  RECORDER_LOG__ *pRVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  char cVar9;
  undefined *puVar10;
  undefined1 uVar11;
  undefined2 uVar12;
  undefined1 uVar13;
  undefined1 local_58 [8];
  undefined8 local_50;
  code *local_40;
  uint local_30;
  
  uVar6 = *(undefined8 *)this;
  memset(local_58,0,0x50);
  cVar9 = '\0';
  iVar1 = (**(code **)(WdfFunctions_01031 + 0x418))
                    (WdfDriverGlobals,uVar6,&GUID_DEVICE_RESET_INTERFACE_STANDARD,local_58,0x50,1,0)
  ;
  if (iVar1 < 0) {
    if (iVar1 == -0x3fffff45) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar9 = '\x01';
    }
    puVar10 = WPP_GLOBAL_Control;
    pRVar3 = GetRecorderLog(this);
    uVar8 = (undefined1)iVar1;
    uVar13 = (undefined1)*(undefined8 *)this;
    uVar12 = 0x18;
    uVar11 = 4;
  }
  else {
    if (local_40 != (code *)0x0) {
      (*local_40)(local_50);
    }
    uVar7 = WdfDriverGlobals;
    lVar4 = (**(code **)(WdfFunctions_01031 + 0xf8))(WdfDriverGlobals,uVar6);
    uVar5 = BthQueryRadioCompatFlags(uVar7,lVar4);
    if (((local_30 >> 1 & 1) == 0) || (iVar1 = 0x491807, (uVar5 >> 0xc & 1) != 0)) {
      iVar1 = 0x49180b;
    }
    uVar6 = (**(code **)(WdfFunctions_01031 + 0x150))(WdfDriverGlobals,uVar6);
    iVar2 = (**(code **)(WdfFunctions_01031 + 0x5e0))(WdfDriverGlobals,uVar6,0,iVar1,0,0,0,0);
    if (-1 < iVar2) {
      puVar10 = WPP_GLOBAL_Control;
      if (iVar1 == 0x491807) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          cVar9 = '\x01';
        }
        pRVar3 = GetRecorderLog(this);
        uVar13 = (undefined1)*(undefined8 *)this;
        uVar12 = 0x1b;
      }
      else {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          cVar9 = '\x01';
        }
        pRVar3 = GetRecorderLog(this);
        uVar13 = (undefined1)*(undefined8 *)this;
        uVar12 = 0x1c;
      }
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(puVar10 + 0x18),cVar9,puVar10,pRVar3,4,1,uVar12,
                 &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,uVar13);
      return;
    }
    puVar10 = WPP_GLOBAL_Control;
    if (iVar1 == 0x491807) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        cVar9 = '\x01';
      }
      pRVar3 = GetRecorderLog(this);
      uVar8 = (undefined1)iVar2;
      uVar13 = (undefined1)*(undefined8 *)this;
      uVar12 = 0x19;
    }
    else {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        cVar9 = '\x01';
      }
      pRVar3 = GetRecorderLog(this);
      uVar8 = (undefined1)iVar2;
      uVar13 = (undefined1)*(undefined8 *)this;
      uVar12 = 0x1a;
    }
    uVar11 = 3;
  }
  WPP_RECORDER_AND_TRACE_SF_qd
            (*(undefined8 *)(puVar10 + 0x18),cVar9,puVar10,pRVar3,uVar11,1,uVar12,
             &WPP_f9ea356a715c3570a55843a4975aeeb6_Traceguids,uVar13,uVar8);
  return;
}



===== Initialize @ 14001a578 =====

/* private: long __cdecl ReceiveQueue::Initialize(void) __ptr64 */

long __thiscall ReceiveQueue::Initialize(ReceiveQueue *this)

{
  bool bVar1;
  RECORDER_LOG__ *pRVar2;
  Fdo *pFVar3;
  char cVar4;
  uint uVar5;
  undefined *puVar6;
  void *local_res10 [3];
  
  uVar5 = 0;
  do {
    utl::make_unique<_URB,0>();
    if (local_res10[0] == (void *)0x0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      pFVar3 = *(Fdo **)(this + 8);
      puVar6 = WPP_GLOBAL_Control;
      pRVar2 = Fdo::GetRecorderLog(pFVar3);
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(puVar6 + 0x18),cVar4,*(undefined8 *)pFVar3,pRVar2,2,1,0xb,
                 &WPP_86e0affdec483798a987f478d619ae67_Traceguids,(char)*(undefined8 *)pFVar3);
      if (local_res10[0] == (void *)0x0) {
        return -0x3fffff66;
      }
LAB_14001a697:
      operator_delete(local_res10[0]);
      return -0x3fffff66;
    }
    bVar1 = utl::
            vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
            ::push_back((vector<utl::unique_ptr<_URB,utl::default_delete<_URB>_>,utl::allocator<utl::unique_ptr<_URB,utl::default_delete<_URB>_>_>_>
                         *)(this + 0x30),(unique_ptr<_URB,utl::default_delete<_URB>_> *)local_res10)
    ;
    if (!bVar1) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      pFVar3 = *(Fdo **)(this + 8);
      puVar6 = WPP_GLOBAL_Control;
      pRVar2 = Fdo::GetRecorderLog(pFVar3);
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(puVar6 + 0x18),cVar4,*(undefined8 *)pFVar3,pRVar2,2,1,0xc,
                 &WPP_86e0affdec483798a987f478d619ae67_Traceguids,(char)*(undefined8 *)pFVar3);
      if (local_res10[0] == (void *)0x0) {
        return -0x3fffff66;
      }
      goto LAB_14001a697;
    }
    if (local_res10[0] != (void *)0x0) {
      operator_delete(local_res10[0]);
    }
    uVar5 = uVar5 + 1;
    if (5 < uVar5) {
      return 0;
    }
  } while( true );
}



===== Make @ 14001a6b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl ReceiveQueue::Make(class Fdo & __ptr64,unsigned int,void *
   __ptr64,void * __ptr64,class utl::unique_ptr<class ReceiveQueue,struct
   WdfCpp::Details::ObjectContextDeleter<class ReceiveQueue> > & __ptr64) */

long __cdecl
ReceiveQueue::Make(Fdo *param_1,uint param_2,void *param_3,void *param_4,
                  unique_ptr<ReceiveQueue,WdfCpp::Details::ObjectContextDeleter<ReceiveQueue>_>
                  *param_5)

{
  undefined8 *puVar1;
  int iVar2;
  RECORDER_LOG__ *pRVar3;
  ReceiveQueue *this;
  undefined8 uVar4;
  char cVar5;
  undefined *puVar6;
  WDFQUEUE__ *local_res8;
  undefined4 local_c8;
  undefined4 local_c4;
  code *local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined *local_98;
  undefined4 local_88;
  undefined8 local_84;
  code *local_78;
  undefined4 local_38;
  
  memset(&local_88,0,0x60);
  cVar5 = '\0';
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_88 = 0x60;
  }
  else if (WdfStructureCount < 0x22) {
    local_88 = 0xffffffff;
  }
  else {
    local_88 = *(undefined4 *)(WdfStructures + 0x108);
  }
  local_84 = 2;
  local_78 = EvtIoQueueIoDefaultThunk;
  local_38 = 0xffffffff;
  local_c4 = 0;
  local_b8 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_c8 = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_c8 = 0xffffffff;
  }
  else {
    local_c8 = *(undefined4 *)(WdfStructures + 0x130);
  }
  local_98 = PTR__WDF_ReceiveQueue_TYPE_INFO_140014088;
  local_b0 = 1;
  local_c0 = WdfCpp::ObjectContext<WDFQUEUE__*___ptr64,ReceiveQueue,1>::EvtObjectContextCleanupThunk
  ;
  local_ac = 1;
  local_res8 = (WDFQUEUE__ *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                    (WdfDriverGlobals,*(undefined8 *)param_1,&local_88,&local_c8,&local_res8);
  if (iVar2 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar5 = '\x01';
    }
    puVar6 = WPP_GLOBAL_Control;
    pRVar3 = Fdo::GetRecorderLog(param_1);
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(puVar6 + 0x18),cVar5,*(undefined8 *)param_1,pRVar3,2,1,10,
               &WPP_86e0affdec483798a987f478d619ae67_Traceguids,(char)*(undefined8 *)param_1,
               (char)iVar2);
  }
  else {
    this = GetContextFromObject(local_res8);
    if (this == (ReceiveQueue *)0x0) {
      this = (ReceiveQueue *)0x0;
    }
    else {
      uVar4 = (**(code **)(WdfFunctions_01031 + 0x660))(WdfDriverGlobals,this);
      *(undefined8 *)this = uVar4;
      *(Fdo **)(this + 8) = param_1;
      *(uint *)(this + 0x10) = param_2;
      *(void **)(this + 0x18) = param_3;
      *(void **)(this + 0x20) = param_4;
      KeInitializeSpinLock(this + 0x28);
      *(undefined8 *)(this + 0x48) = 0;
      *(undefined8 *)(this + 0x30) = 0xffffffffffffffff;
      *(undefined8 *)(this + 0x38) = 0xffffffffffffffff;
      *(undefined8 *)(this + 0x40) = 0xffffffffffffffff;
    }
    iVar2 = Initialize(this);
    if (iVar2 < 0) {
      if (this != (ReceiveQueue *)0x0) {
        (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*(undefined8 *)this);
      }
    }
    else {
      puVar1 = *(undefined8 **)param_5;
      *(ReceiveQueue **)param_5 = this;
      if (puVar1 != (undefined8 *)0x0) {
        (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*puVar1);
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}



===== BthUsb_GetCapabilities @ 14001a930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl BthUsb_GetCapabilities(struct _BTDEVICE * __ptr64,struct _BTH_GET_CAPABILITIES_ARG *
   __ptr64) */

long __cdecl BthUsb_GetCapabilities(_BTDEVICE *param_1,_BTH_GET_CAPABILITIES_ARG *param_2)

{
  _DEVICE_EXTENSION *p_Var1;
  _BTH_GET_CAPABILITIES_ARG _Var2;
  long lVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined7 uVar9;
  undefined8 uVar8;
  char cVar10;
  uchar local_res18 [8];
  undefined1 local_78 [8];
  undefined8 local_70;
  code *local_60;
  code *local_20;
  
  cVar5 = '\x01';
  local_res18[0] = '\0';
  uVar6 = 1;
  memset(local_78,0,0x60);
  uVar8 = 0x24;
  lVar3 = BthUsb_ScoBasicValidation(param_1,param_2,0x24);
  if (-1 < lVar3) {
    p_Var1 = param_1->MiniportContext;
    puVar7 = (undefined *)0x60;
    lVar3 = BthUsb_GetUsbBusInterface(p_Var1,local_78,0x60,3);
    if (-1 < lVar3) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
      {
        cVar10 = '\0';
      }
      else {
        cVar10 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,puVar7,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x2d,
                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
      if (local_20 != (code *)0x0) {
        puVar7 = (undefined *)0x0;
        iVar4 = (*local_20)(local_70,0,0,0,0,0,0,local_res18);
        if (-1 < iVar4) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar10 = '\0';
          }
          else {
            cVar10 = '\x01';
          }
          puVar7 = WPP_GLOBAL_Control;
          g_BthUsb_GetUsbCtrlString(local_res18[0]);
          WPP_RECORDER_AND_TRACE_SF_S
                    (*(undefined8 *)(puVar7 + 0x18),cVar10,puVar7,*(undefined8 *)(puVar7 + 0x40));
          uVar6 = 1;
          if (local_res18[0] != '\x10') {
            uVar6 = 3;
          }
        }
      }
      (*local_60)(local_70);
    }
    *(ulong *)(param_2 + 0xc) = p_Var1->BulkInSize;
    *(undefined4 *)(param_2 + 8) = 1;
    *(undefined4 *)(param_2 + 0x10) = 0x102;
    *(undefined4 *)(param_2 + 0x14) = uVar6;
    *(undefined4 *)(param_2 + 0x18) = 0xf;
    *(undefined4 *)(param_2 + 0x1c) = 9;
    _Var2 = (_BTH_GET_CAPABILITIES_ARG)IsAlignDataCapable((longlong)p_Var1);
    param_2[0x20] = _Var2;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar10 = '\0';
    }
    else {
      cVar10 = '\x01';
    }
    uVar9 = (undefined7)((ulonglong)puVar7 >> 8);
    WPP_RECORDER_AND_TRACE_SF_L
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,'\x01',
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x2f,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)*(undefined4 *)(param_2 + 0xc)
              );
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar10 = '\0';
    }
    else {
      cVar10 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_L
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,'\x01',
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x30,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
               (char)*(undefined4 *)(param_2 + 0x10));
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar10 = '\0';
    }
    else {
      cVar10 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_L
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,'\x01',
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x31,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
               (char)*(undefined4 *)(param_2 + 0x14));
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar10 = '\0';
    }
    else {
      cVar10 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_L
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,'\x01',
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x32,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
               (char)*(undefined4 *)(param_2 + 0x18));
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar10 = '\0';
    }
    else {
      cVar10 = '\x01';
    }
    uVar8 = CONCAT71(uVar9,1);
    WPP_RECORDER_AND_TRACE_SF_L
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,'\x01',
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x33,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,
               (char)*(undefined4 *)(param_2 + 0x1c));
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar10 = '\0';
    }
    else {
      cVar10 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,uVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x34,
               &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,param_2[0x20]);
    lVar3 = 0;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,uVar8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x35,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)lVar3);
  return lVar3;
}



===== BthUsb_ScoInitExtension @ 14001acdc =====

/* void __cdecl BthUsb_ScoInitExtension(struct _DEVICE_EXTENSION * __ptr64) */

void __cdecl BthUsb_ScoInitExtension(_DEVICE_EXTENSION *param_1)

{
  uchar uVar1;
  _USB_INTERFACE_DESCRIPTOR *p_Var2;
  long lVar3;
  uint uVar4;
  ulong *puVar5;
  longlong lVar6;
  char cVar7;
  char cVar8;
  _USB_INTERFACE_DESCRIPTOR **in_R8;
  
  p_Var2 = (param_1->Sco).OffInterface;
  lVar3 = -0x3fffff45;
  cVar8 = '\x01';
  if (p_Var2 != (_USB_INTERFACE_DESCRIPTOR *)0x0) {
    (param_1->Sco).CurInterface = p_Var2;
    puVar5 = &(param_1->Sco).MaxFrameSize;
    uVar1 = p_Var2->bInterfaceNumber;
    (param_1->Sco).InterfaceNumber = uVar1;
    in_R8 = &(param_1->Sco).MaxInterface;
    lVar3 = BthUsb_GetMaxIsoInterface
                      (param_1,uVar1,in_R8,puVar5,&(param_1->Sco).RealMaxInterface,
                       &(param_1->Sco).RealMaxFrameSize);
    if (lVar3 < 0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      in_R8 = (_USB_INTERFACE_DESCRIPTOR **)WPP_GLOBAL_Control;
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,WPP_GLOBAL_Control,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xd,
                 &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
    }
    else {
      uVar4 = *puVar5;
      if (0x56 < uVar4) {
        uVar4 = 0x56;
      }
      *puVar5 = uVar4;
      (param_1->Sco).MaxBandwidth = uVar4 * 1000 - 1000;
      KeInitializeSpinLock(&(param_1->Sco).ReadLock);
      KeInitializeSpinLock(&(param_1->Sco).WriteLock);
      puVar5 = &(param_1->Sco).Channel[0].WriteFrameInterval;
      lVar6 = 3;
      do {
        ((_SCO_USB_CHANNEL *)(puVar5 + -0x25))->ConnectionHandle = 0xffff;
        *puVar5 = 0xffffffff;
        puVar5 = puVar5 + 0x26;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      lVar3 = 0;
      (param_1->Sco).UsbAltSetting = (ScoUsbAltSetting *)&DAT_140011050;
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar8 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xe,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)lVar3);
  (param_1->Sco).InitStatus = lVar3;
  return;
}



===== BthUsb_ScoReleaseUsbBusInterface @ 14001ae8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl __based(PAGE) BthUsb_ScoReleaseUsbBusInterface(struct _DEVICE_EXTENSION * __ptr64)
    */

void __cdecl BthUsb_ScoReleaseUsbBusInterface(_DEVICE_EXTENSION *param_1)

{
  char cVar1;
  undefined8 in_R8;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x20,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids);
  (*(param_1->Sco).UsbBusInterface.InterfaceDereference)((param_1->Sco).UsbBusInterface.BusContext);
  memset(&(param_1->Sco).UsbBusInterface,0,0x40);
  return;
}



===== BthUsb_ScoValidateChannel @ 14001af10 =====

/* long __cdecl BthUsb_ScoValidateChannel(struct _BTDEVICE * __ptr64,struct
   _BTH_SCO_VALIDATE_CHANNEL_ARG * __ptr64) */

long __cdecl BthUsb_ScoValidateChannel(_BTDEVICE *param_1,_BTH_SCO_VALIDATE_CHANNEL_ARG *param_2)

{
  long lVar1;
  char cVar2;
  char cVar3;
  undefined8 in_R8;
  ulong *puVar4;
  ulong local_res18 [2];
  ulong local_res20 [2];
  undefined1 in_stack_ffffffffffffff98;
  undefined7 in_stack_ffffffffffffff99;
  
  cVar3 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
     (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_qdd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffff99,in_stack_ffffffffffffff98),4,0x36,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)param_1,
             (char)*(undefined4 *)(param_2 + 4),(char)*(undefined4 *)(param_2 + 8));
  puVar4 = (ulong *)0xc;
  lVar1 = BthUsb_ScoBasicValidation(param_1,param_2,0xc);
  if (-1 < lVar1) {
    local_res20[0] = *(ulong *)(param_2 + 4);
    puVar4 = local_res18;
    local_res18[0] = *(ulong *)(param_2 + 8);
    lVar1 = BthUsb_ScoValidateChnInfo(param_1->MiniportContext,local_res20,puVar4);
    if (-1 < lVar1) {
      lVar1 = 0;
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,puVar4,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x37,
             &WPP_89eaa7be148f36a90e353489c15db76f_Traceguids,(char)lVar1);
  return lVar1;
}



===== Make @ 14001b030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl TransmitQueue::Make(class Fdo & __ptr64,void * __ptr64,class
   utl::unique_ptr<class TransmitQueue,struct WdfCpp::Details::ObjectContextDeleter<class
   TransmitQueue> > & __ptr64) */

long __cdecl
TransmitQueue::Make(Fdo *param_1,void *param_2,
                   unique_ptr<TransmitQueue,WdfCpp::Details::ObjectContextDeleter<TransmitQueue>_>
                   *param_3)

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
  local_88 = PTR__WDF_TransmitQueue_TYPE_INFO_1400140b0;
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
               &WPP_fa6aac3b369b3a7320c30fd5f31db9d3_Traceguids,(char)*(undefined8 *)param_1,
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
      extraout_RAX[2] = param_2;
      puVar6 = extraout_RAX;
    }
    puVar1 = *(undefined8 **)param_3;
    *(undefined8 **)param_3 = puVar6;
    if (puVar1 != (undefined8 *)0x0) {
      (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*puVar1);
    }
    iVar2 = 0;
  }
  return iVar2;
}



===== BthUsb_FindUsbdPipeDescriptor @ 14001b238 =====

/* WARNING: Type propagation algorithm not settling */
/* struct _USB_ENDPOINT_DESCRIPTOR * __ptr64 __cdecl __based(PAGE)
   BthUsb_FindUsbdPipeDescriptor(struct _DEVICE_EXTENSION * __ptr64,struct _USB_INTERFACE_DESCRIPTOR
   * __ptr64,unsigned char,unsigned char,unsigned char * __ptr64) */

_USB_ENDPOINT_DESCRIPTOR * __cdecl
BthUsb_FindUsbdPipeDescriptor
          (_DEVICE_EXTENSION *param_1,_USB_INTERFACE_DESCRIPTOR *param_2,uchar param_3,uchar param_4
          ,uchar *param_5)

{
  longlong lVar1;
  _USB_ENDPOINT_DESCRIPTOR *p_Var2;
  ulonglong uVar3;
  char cVar4;
  _USB_ENDPOINT_DESCRIPTOR *p_Var5;
  _USB_INTERFACE_DESCRIPTOR *p_Var6;
  _USB_INTERFACE_DESCRIPTOR *p_Var7;
  char cVar8;
  undefined7 in_register_00000081;
  ulonglong uVar9;
  uint uVar10;
  _USB_ENDPOINT_DESCRIPTOR *p_Var11;
  undefined2 uVar12;
  
  uVar9 = CONCAT71(in_register_00000081,param_3);
  *param_5 = '\0';
  p_Var11 = (_USB_ENDPOINT_DESCRIPTOR *)
            (&param_1->ConfigDescriptor->bLength + param_1->ConfigDescriptor->wTotalLength);
  if (param_1->DeviceDescriptor->bcdUSB < 0x201) {
    cVar8 = '\x01';
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,uVar9,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x37,
               &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
    uVar10 = 0;
    p_Var6 = param_2 + 1;
    if (param_2->bNumEndpoints != '\0') {
      p_Var7 = param_2 + 1;
      do {
        p_Var7 = (_USB_INTERFACE_DESCRIPTOR *)&p_Var7->bInterfaceProtocol;
        uVar3 = Feature_4206787896__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 != 0) {
          if (p_Var7 < p_Var6) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar8 = '\0';
            }
            uVar12 = 0x38;
LAB_14001b35a:
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,uVar9,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar12,
                       &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
            return (_USB_ENDPOINT_DESCRIPTOR *)0x0;
          }
          if (p_Var11 < p_Var7) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar8 = '\0';
            }
            uVar12 = 0x39;
            goto LAB_14001b35a;
          }
        }
        if (((*(uchar *)((longlong)p_Var7 + -4) & 3) == 1) &&
           ((param_4 != '\0') == (bool)-((char)*(uchar *)((longlong)p_Var7 + -5) >> 7))) {
          return (_USB_ENDPOINT_DESCRIPTOR *)p_Var6;
        }
        uVar10 = uVar10 + 1;
        p_Var6 = (_USB_INTERFACE_DESCRIPTOR *)&p_Var6->bInterfaceProtocol;
      } while (uVar10 < param_2->bNumEndpoints);
    }
  }
  else {
    cVar8 = '\x01';
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,uVar9,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x3a,
               &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
    uVar10 = 0;
    p_Var5 = (_USB_ENDPOINT_DESCRIPTOR *)(&param_2->bLength + param_2->bLength);
    if (param_2->bNumEndpoints != 0) {
      do {
        lVar1 = (longlong)p_Var5 + 2;
        if (((ulonglong)lVar1 < p_Var5) || (p_Var11 < (ulonglong)lVar1)) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar8 = '\0';
          }
          WPP_RECORDER_AND_TRACE_SF_i
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,uVar9,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          return (_USB_ENDPOINT_DESCRIPTOR *)0x0;
        }
        uVar9 = (ulonglong)(byte)p_Var5->field_0x0;
        p_Var2 = p_Var5 + uVar9;
        if ((p_Var2 <= p_Var5) || (p_Var11 < p_Var2)) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar8 = '\0';
          }
          WPP_RECORDER_AND_TRACE_SF_iDi
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,uVar9,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          return (_USB_ENDPOINT_DESCRIPTOR *)0x0;
        }
        if (*(char *)((longlong)p_Var5 + 1) == '\x05') {
          if (p_Var5->field_0x0 != 7) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar8 = '\0';
            }
            WPP_RECORDER_AND_TRACE_SF_iDD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,uVar9,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            return (_USB_ENDPOINT_DESCRIPTOR *)0x0;
          }
          uVar10 = uVar10 + 1;
          if (((*(byte *)((longlong)p_Var5 + 3) & 3) == 1) &&
             ((param_4 != '\0') == (bool)-(*(char *)lVar1 >> 7))) {
            return p_Var5;
          }
        }
        p_Var5 = p_Var2;
      } while (uVar10 < param_2->bNumEndpoints);
    }
  }
  return (_USB_ENDPOINT_DESCRIPTOR *)0x0;
}



===== BthUsb_GetConfigDescriptor @ 14001b538 =====

/* long __cdecl __based(PAGE) BthUsb_GetConfigDescriptor(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthUsb_GetConfigDescriptor(_DEVICE_EXTENSION *param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  char cVar5;
  uint uVar6;
  char cVar7;
  undefined8 uVar8;
  undefined4 local_b8 [9];
  uint local_94;
  _USB_CONFIGURATION_DESCRIPTOR *local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_36;
  
  memset(local_b8,0,0x98);
  cVar7 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1d,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
  if (param_1->ConfigDescriptor == (_USB_CONFIGURATION_DESCRIPTOR *)0x0) {
    uVar6 = 9;
    while( true ) {
      local_90 = (_USB_CONFIGURATION_DESCRIPTOR *)ExAllocatePool2(0x40,uVar6,0x42425355);
      param_1->ConfigDescriptor = local_90;
      if (local_90 == (_USB_CONFIGURATION_DESCRIPTOR *)0x0) break;
      uVar8 = 500;
      local_b8[0] = 0xb0088;
      local_88 = 0;
      local_36 = 0x200;
      local_80 = 0;
      local_94 = uVar6;
      iVar3 = USBCallSyncEx((longlong)param_1->TopOfStack,(longlong)local_b8,500,
                            &param_1->RemoveLock);
      if (iVar3 < 0) {
        ExFreePoolWithTag(param_1->ConfigDescriptor,0);
        param_1->ConfigDescriptor = (_USB_CONFIGURATION_DESCRIPTOR *)0x0;
        return iVar3;
      }
      if (local_94 == 0) {
LAB_14001b660:
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,uVar8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1e,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,uVar8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1f,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar7 = '\0';
        }
        bVar1 = param_1->ConfigDescriptor->bNumInterfaces;
        WPP_RECORDER_AND_TRACE_SF_dd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,(ulonglong)bVar1,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x20,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,
                   (char)param_1->ConfigDescriptor->wTotalLength,bVar1);
        return iVar3;
      }
      uVar2 = param_1->ConfigDescriptor->wTotalLength;
      if (uVar2 <= uVar6) goto LAB_14001b660;
      uVar6 = (uint)uVar2;
      ExFreePoolWithTag(param_1->ConfigDescriptor,0);
      param_1->ConfigDescriptor = (_USB_CONFIGURATION_DESCRIPTOR *)0x0;
    }
    lVar4 = -0x3fffff66;
  }
  else {
    lVar4 = 0;
  }
  return lVar4;
}



===== BthUsb_GetDeviceDescriptor @ 14001b784 =====

/* long __cdecl __based(PAGE) BthUsb_GetDeviceDescriptor(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthUsb_GetDeviceDescriptor(_DEVICE_EXTENSION *param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  _USB_DEVICE_DESCRIPTOR *p_Var4;
  char cVar5;
  char cVar6;
  ulonglong in_R8;
  undefined *puVar7;
  undefined1 uVar8;
  undefined7 in_stack_ffffffffffffff09;
  undefined4 local_c8 [9];
  undefined4 local_a4;
  _USB_DEVICE_DESCRIPTOR *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_46;
  
  cVar6 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  uVar8 = 4;
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xc,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
  iVar3 = 0;
  if (param_1->DeviceDescriptor == (_USB_DEVICE_DESCRIPTOR *)0x0) {
    in_R8 = 0x42425355;
    p_Var4 = (_USB_DEVICE_DESCRIPTOR *)ExAllocatePool2(0x40);
    param_1->DeviceDescriptor = p_Var4;
    if (p_Var4 == (_USB_DEVICE_DESCRIPTOR *)0x0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
         (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar5 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,in_R8,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xd,
                 &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
      iVar3 = -0x3fffff66;
    }
    else {
      memset(local_c8,0,0x98);
      in_R8 = 500;
      local_c8[0] = 0xb0088;
      local_a4 = 0x12;
      local_98 = 0;
      local_46 = 0x100;
      local_90 = 0;
      local_a0 = p_Var4;
      iVar3 = USBCallSyncEx((longlong)param_1->TopOfStack,(longlong)local_c8,500,
                            &param_1->RemoveLock);
      if (-1 < iVar3) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        puVar7 = WPP_GLOBAL_Control;
        WPP_RECORDER_AND_TRACE_SF_qD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,WPP_GLOBAL_Control,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT71(in_stack_ffffffffffffff09,uVar8),2,0xe,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)param_1->DeviceDescriptor,
                   (char)local_a4);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,puVar7,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xf,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,puVar7,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x10,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        bVar1 = param_1->DeviceDescriptor->bLength;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)bVar1,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x11,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,bVar1);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        uVar2 = param_1->DeviceDescriptor->bcdUSB;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)uVar2,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x12,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)uVar2);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        bVar1 = param_1->DeviceDescriptor->bDeviceClass;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)bVar1,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x13,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,bVar1);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        bVar1 = param_1->DeviceDescriptor->bDeviceSubClass;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)bVar1,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x14,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,bVar1);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        bVar1 = param_1->DeviceDescriptor->bDeviceProtocol;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)bVar1,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x15,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,bVar1);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        uVar2 = param_1->DeviceDescriptor->idVendor;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)uVar2,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x16,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)uVar2);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        uVar2 = param_1->DeviceDescriptor->idProduct;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)uVar2,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x17,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)uVar2);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        bVar1 = param_1->DeviceDescriptor->iManufacturer;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)bVar1,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x18,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,bVar1);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        bVar1 = param_1->DeviceDescriptor->iProduct;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,(ulonglong)bVar1,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x19,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,bVar1);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        bVar1 = param_1->DeviceDescriptor->bNumConfigurations;
        in_R8 = (ulonglong)bVar1;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,in_R8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1a,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,bVar1);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,in_R8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1b,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
      }
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1c,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)iVar3);
  return iVar3;
}



===== BthUsb_GetInterfaceDescriptor @ 14001bd20 =====

/* struct _USB_INTERFACE_DESCRIPTOR * __ptr64 __cdecl __based(PAGE)
   BthUsb_GetInterfaceDescriptor(struct _DEVICE_EXTENSION * __ptr64,void * __ptr64 *
   __ptr64,long,long,long,long,long) */

_USB_INTERFACE_DESCRIPTOR * __cdecl
BthUsb_GetInterfaceDescriptor
          (_DEVICE_EXTENSION *param_1,void **param_2,long param_3,long param_4,long param_5,
          long param_6,long param_7)

{
  _USB_INTERFACE_DESCRIPTOR *p_Var1;
  
  if (*param_2 == (void *)0x0) {
    *param_2 = param_1->ConfigDescriptor;
  }
  p_Var1 = (_USB_INTERFACE_DESCRIPTOR *)
           USBD_ParseConfigurationDescriptorEx(param_1->ConfigDescriptor);
  if (p_Var1 != (_USB_INTERFACE_DESCRIPTOR *)0x0) {
    *param_2 = p_Var1 + 1;
  }
  return p_Var1;
}



===== BthUsb_GetMaxIsoInterface @ 14001bd70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl BthUsb_GetMaxIsoInterface(struct _DEVICE_EXTENSION * __ptr64,unsigned char,struct
   _USB_INTERFACE_DESCRIPTOR * __ptr64 * __ptr64,unsigned long * __ptr64,struct
   _USB_INTERFACE_DESCRIPTOR * __ptr64 * __ptr64,unsigned long * __ptr64) */

long __cdecl
BthUsb_GetMaxIsoInterface
          (_DEVICE_EXTENSION *param_1,uchar param_2,_USB_INTERFACE_DESCRIPTOR **param_3,
          ulong *param_4,_USB_INTERFACE_DESCRIPTOR **param_5,ulong *param_6)

{
  uchar uVar1;
  _DEVICE_EXTENSION *p_Var2;
  bool bVar3;
  _USB_ENDPOINT_DESCRIPTOR _Var4;
  uint uVar5;
  _USB_INTERFACE_DESCRIPTOR *p_Var6;
  _USB_ENDPOINT_DESCRIPTOR *p_Var7;
  _USB_ENDPOINT_DESCRIPTOR *p_Var8;
  ulonglong uVar9;
  ushort uVar10;
  __uint64 _Var11;
  undefined8 *puVar12;
  _USB_INTERFACE_DESCRIPTOR **pp_Var13;
  void *pvVar14;
  uint *puVar15;
  uchar uVar16;
  uint uVar17;
  ulonglong uVar18;
  ushort uVar19;
  char cVar20;
  ushort uVar21;
  ulonglong uVar22;
  _DEVICE_EXTENSION *p_Var23;
  int iVar24;
  uchar *puVar25;
  char cVar26;
  undefined1 auStackY_1c8 [32];
  undefined8 in_stack_fffffffffffffe58;
  uchar *puVar27;
  undefined8 *puVar28;
  undefined4 in_stack_fffffffffffffe68;
  long lVar29;
  uchar local_168;
  uchar local_167;
  ushort local_166;
  int local_164;
  uchar local_160 [2];
  ushort local_15e;
  _DEVICE_EXTENSION *local_158;
  undefined2 local_150 [4];
  void *local_148;
  undefined8 *puStack_140;
  undefined8 *local_138;
  uint *local_130;
  uint local_128;
  _USB_INTERFACE_DESCRIPTOR **local_120;
  _USB_CONFIGURATION_DESCRIPTOR *local_118;
  _USB_INTERFACE_DESCRIPTOR *local_110;
  _USB_INTERFACE_DESCRIPTOR *local_108;
  uint *local_100;
  undefined8 local_f8;
  _USB_INTERFACE_DESCRIPTOR **local_f0;
  uchar local_e8;
  _USB_ENDPOINT_DESCRIPTOR _Stack_e7;
  _USB_ENDPOINT_DESCRIPTOR _Stack_e6;
  ushort uStack_e5;
  _USB_ENDPOINT_DESCRIPTOR _Stack_e3;
  _USB_ENDPOINT_DESCRIPTOR _Stack_e2;
  _USB_ENDPOINT_DESCRIPTOR _Stack_e1;
  ushort local_e0;
  _USB_ENDPOINT_DESCRIPTOR local_de;
  undefined8 local_d8 [4];
  undefined8 *local_b8;
  undefined8 local_b0;
  _DEVICE_EXTENSION *local_a8;
  undefined8 local_a0;
  uchar *local_98;
  undefined8 local_90;
  undefined2 *local_88;
  undefined8 local_80;
  uchar *local_78;
  undefined8 local_70;
  uchar *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1c8;
  iVar24 = -0x3fffffff;
  cVar20 = '\0';
  uVar21 = 0;
  local_166 = 0;
  local_110 = (_USB_INTERFACE_DESCRIPTOR *)0x0;
  local_15e = 0;
  local_108 = (_USB_INTERFACE_DESCRIPTOR *)0x0;
  local_f0 = param_5;
  local_100 = param_6;
  local_164 = -0x3fffffff;
  cVar26 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    cVar20 = '\x01';
  }
  lVar29 = CONCAT22((short)((uint)in_stack_fffffffffffffe68 >> 0x10),0x44);
  puVar28 = (undefined8 *)0x3;
  puVar27 = (uchar *)CONCAT71((int7)((ulonglong)in_stack_fffffffffffffe58 >> 8),4);
  local_158 = param_1;
  local_130 = param_4;
  local_120 = param_3;
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar20,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x44,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
  *param_3 = (_USB_INTERFACE_DESCRIPTOR *)0x0;
  local_148 = (void *)0xffffffffffffffff;
  puStack_140 = (undefined8 *)0xffffffffffffffff;
  *local_130 = 0;
  *param_5 = (_USB_INTERFACE_DESCRIPTOR *)0x0;
  local_138 = (undefined8 *)0xffffffffffffffff;
  *local_100 = 0;
  utl::vector<USB_ALT_SETTING,utl::allocator<USB_ALT_SETTING>_>::_SetCapacity
            ((vector<USB_ALT_SETTING,utl::allocator<USB_ALT_SETTING>_> *)&local_148,8);
  local_118 = param_1->ConfigDescriptor;
  local_128 = (uint)param_2;
  uVar18 = (ulonglong)local_128;
  p_Var6 = BthUsb_GetInterfaceDescriptor
                     (param_1,&local_118,local_128,-1,(long)puVar27,(long)puVar28,lVar29);
  p_Var23 = local_158;
  pvVar14 = local_148;
  if (p_Var6 == (_USB_INTERFACE_DESCRIPTOR *)0x0) {
    pp_Var13 = local_120;
    puVar15 = local_130;
  }
  else {
    puVar12 = puStack_140;
    do {
      p_Var2 = local_158;
      uVar16 = (uchar)uVar18;
      if (p_Var6->bNumEndpoints == '\x02') {
        puVar27 = &local_167;
        local_167 = '\0';
        p_Var7 = BthUsb_FindUsbdPipeDescriptor(local_158,p_Var6,uVar16,'\x01',puVar27);
        if (p_Var7 != (_USB_ENDPOINT_DESCRIPTOR *)0x0) {
          puVar27 = &local_168;
          local_168 = '\0';
          p_Var8 = BthUsb_FindUsbdPipeDescriptor(p_Var2,p_Var6,uVar16,'\0',puVar27);
          if (p_Var8 != (_USB_ENDPOINT_DESCRIPTOR *)0x0) {
            uVar19 = *(ushort *)(p_Var7 + 4);
            uVar10 = *(ushort *)(p_Var8 + 4);
            uVar18 = (ulonglong)uVar10;
            if ((uVar19 == uVar10) && (8 < uVar19)) {
              local_e8 = p_Var6->bAlternateSetting;
              _Stack_e7 = p_Var8[2];
              _Stack_e6 = p_Var8[3];
              _Stack_e3 = p_Var8[6];
              _Stack_e2 = p_Var7[2];
              _Stack_e1 = p_Var7[3];
              _Var4 = p_Var7[6];
              uStack_e5 = uVar10;
              local_e0 = uVar19;
              local_de = _Var4;
              if (puVar12 == local_138) {
                puVar25 = &local_e8;
                uVar22 = (longlong)local_d8 + (-0x10 - (longlong)pvVar14);
                uVar9 = ((longlong)local_138 - (longlong)pvVar14) * 0x2e8ba2e8ba2e8ba3;
                _Var11 = (uVar9 >> 2) * 7 + 8;
                if (0xba2e8ba2e8ba2e8 < _Var11) {
                  _Var11 = 0xba2e8ba2e8ba2e8;
                }
                if (uVar9 < _Var11) {
                  bVar3 = utl::vector<USB_ALT_SETTING,utl::allocator<USB_ALT_SETTING>_>::
                          _SetCapacity((vector<USB_ALT_SETTING,utl::allocator<USB_ALT_SETTING>_> *)
                                       &local_148,_Var11);
                  puVar12 = puStack_140;
                  pvVar14 = local_148;
                  if (bVar3) {
                    if (uVar22 < (ulonglong)((longlong)puStack_140 - (longlong)local_148)) {
                      puVar25 = (uchar *)((longlong)local_148 + uVar22);
                    }
                    *puStack_140 = *(undefined8 *)puVar25;
                    *(undefined2 *)(puStack_140 + 1) = *(undefined2 *)(puVar25 + 8);
                    _Var4 = *(_USB_ENDPOINT_DESCRIPTOR *)(puVar25 + 10);
                    goto LAB_14001bfe6;
                  }
                }
              }
              else {
                *puVar12 = CONCAT17(_Stack_e1,
                                    CONCAT16(_Stack_e2,
                                             CONCAT15(_Stack_e3,
                                                      CONCAT23(uVar10,CONCAT12(_Stack_e6,
                                                                               CONCAT11(_Stack_e7,
                                                                                        local_e8))))
                                            ));
                *(ushort *)(puVar12 + 1) = uVar19;
                puStack_140 = puVar12;
LAB_14001bfe6:
                *(_USB_ENDPOINT_DESCRIPTOR *)((longlong)puStack_140 + 10) = _Var4;
                puStack_140 = (undefined8 *)((longlong)puStack_140 + 0xb);
                puVar12 = puStack_140;
              }
              uVar1 = local_167;
              uVar16 = local_168;
              uVar19 = *(ushort *)(p_Var7 + 4);
              if (local_15e < uVar19) {
                local_15e = uVar19;
                local_108 = p_Var6;
              }
              if (((p_Var6->bAlternateSetting < 7) && (local_167 == '\0')) && (local_168 == '\0')) {
                p_Var23 = local_158;
                uVar21 = local_166;
                if (local_166 < uVar19) {
                  local_164 = 0;
                  uVar21 = uVar19;
                  local_166 = uVar19;
                  local_110 = p_Var6;
                }
              }
              else {
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
                  cVar20 = '\0';
                }
                else {
                  cVar20 = '\x01';
                }
                WPP_RECORDER_AND_TRACE_SF_DDll
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar20,uVar18,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                p_Var23 = local_158;
                if (((3 < DAT_140014000) && ((_DAT_140014010 & 0x400000000000) != 0)) &&
                   ((DAT_140014018 & 0x400000000000) == DAT_140014018)) {
                  local_150[0] = *(undefined2 *)(p_Var7 + 4);
                  local_160[0] = p_Var6->bAlternateSetting;
                  local_68 = &local_167;
                  local_78 = &local_168;
                  local_88 = local_150;
                  local_98 = local_160;
                  local_b8 = &local_f8;
                  puVar28 = local_d8;
                  puVar27 = (uchar *)0x8;
                  local_167 = uVar16;
                  local_168 = uVar1;
                  local_f8 = 0x2000800;
                  local_60 = 1;
                  local_70 = 1;
                  local_80 = 2;
                  local_90 = 1;
                  local_a8 = local_158;
                  local_a0 = 0x10;
                  local_b0 = 8;
                  _tlgWriteTransfer_EtwWriteTransfer(0x140014000,&DAT_1400120d5,0,0,8,puVar28);
                }
                uVar21 = local_166;
              }
              goto LAB_14001c191;
            }
          }
        }
        p_Var23 = local_158;
      }
LAB_14001c191:
      iVar24 = local_164;
      uVar18 = (ulonglong)local_128;
      p_Var6 = BthUsb_GetInterfaceDescriptor
                         (p_Var23,&local_118,local_128,-1,(long)puVar27,(long)puVar28,lVar29);
      pp_Var13 = local_120;
      puVar15 = local_130;
    } while (p_Var6 != (_USB_INTERFACE_DESCRIPTOR *)0x0);
    if (-1 < iVar24) {
      *local_120 = local_110;
      *local_130 = (uint)uVar21;
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
      {
        cVar20 = '\0';
      }
      else {
        cVar20 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar20,
                 &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x46,
                 &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)local_110,(char)uVar21);
    }
  }
  uVar17 = 0xffffffff;
  *local_f0 = local_108;
  uVar5 = (uint)local_15e;
  *local_100 = (uint)local_15e;
  if (*local_f0 == (_USB_INTERFACE_DESCRIPTOR *)0x0) {
    uVar5 = 0xffffffff;
    uVar19 = 0xffff;
  }
  else {
    uVar19 = (ushort)(*local_f0)->bAlternateSetting;
  }
  if (*pp_Var13 == (_USB_INTERFACE_DESCRIPTOR *)0x0) {
    uVar10 = 0xffff;
  }
  else {
    uVar10 = (ushort)(*pp_Var13)->bAlternateSetting;
    uVar17 = *puVar15;
  }
  LogMaxIsoInterface((longlong)p_Var23,uVar10,uVar17,uVar19,uVar5,&local_148);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar26 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_Dd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar26,(ulonglong)uVar21,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  if (pvVar14 != (void *)0xffffffffffffffff) {
    operator_delete(pvVar14);
  }
  return iVar24;
}



===== BthUsb_InitializeIsochPipes @ 14001c2f0 =====

/* long __cdecl __based(PAGE) BthUsb_InitializeIsochPipes(struct _DEVICE_EXTENSION * __ptr64,struct
   _USBD_INTERFACE_INFORMATION * __ptr64) */

long __cdecl
BthUsb_InitializeIsochPipes(_DEVICE_EXTENSION *param_1,_USBD_INTERFACE_INFORMATION *param_2)

{
  void *pvVar1;
  uchar uVar2;
  uchar uVar3;
  _USBD_PIPE_TYPE _Var4;
  ulong uVar5;
  _USBD_PIPE_INFORMATION *p_Var6;
  _USBD_PIPE_INFORMATION *p_Var7;
  uint uVar8;
  
  p_Var6 = param_2->Pipes;
  uVar8 = 0;
  p_Var7 = p_Var6;
  if (param_2->NumberOfPipes == 0) {
    return -0x3ffffff3;
  }
  while ((p_Var7->PipeType != UsbdPipeTypeIsochronous || (-1 < (char)p_Var7->EndpointAddress))) {
    uVar8 = uVar8 + 1;
    p_Var7 = p_Var7 + 1;
    if (param_2->NumberOfPipes <= uVar8) {
      return -0x3ffffff3;
    }
  }
  if (p_Var7 == (_USBD_PIPE_INFORMATION *)0x0) {
    return -0x3ffffff3;
  }
  uVar2 = p_Var7->EndpointAddress;
  uVar3 = p_Var7->Interval;
  _Var4 = p_Var7->PipeType;
  pvVar1 = p_Var7->PipeHandle;
  uVar8 = 0;
  param_1->Pipes[3].MaximumPacketSize = p_Var7->MaximumPacketSize;
  param_1->Pipes[3].EndpointAddress = uVar2;
  param_1->Pipes[3].Interval = uVar3;
  param_1->Pipes[3].PipeType = _Var4;
  param_1->Pipes[3].PipeHandle = pvVar1;
  uVar5 = p_Var7->PipeFlags;
  param_1->Pipes[3].MaximumTransferSize = p_Var7->MaximumTransferSize;
  param_1->Pipes[3].PipeFlags = uVar5;
  if (param_2->NumberOfPipes == 0) {
    return -0x3ffffff3;
  }
  while ((p_Var6->PipeType != UsbdPipeTypeIsochronous || ((char)p_Var6->EndpointAddress < '\0'))) {
    uVar8 = uVar8 + 1;
    p_Var6 = p_Var6 + 1;
    if (param_2->NumberOfPipes <= uVar8) {
      return -0x3ffffff3;
    }
  }
  if (p_Var6 == (_USBD_PIPE_INFORMATION *)0x0) {
    return -0x3ffffff3;
  }
  uVar2 = p_Var6->EndpointAddress;
  uVar3 = p_Var6->Interval;
  _Var4 = p_Var6->PipeType;
  pvVar1 = p_Var6->PipeHandle;
  param_1->Pipes[4].MaximumPacketSize = p_Var6->MaximumPacketSize;
  param_1->Pipes[4].EndpointAddress = uVar2;
  param_1->Pipes[4].Interval = uVar3;
  param_1->Pipes[4].PipeType = _Var4;
  param_1->Pipes[4].PipeHandle = pvVar1;
  uVar5 = p_Var6->PipeFlags;
  param_1->Pipes[4].MaximumTransferSize = p_Var6->MaximumTransferSize;
  param_1->Pipes[4].PipeFlags = uVar5;
  return 0;
}



===== BthUsb_InitializeNonIsochPipes @ 14001c394 =====

/* long __cdecl __based(PAGE) BthUsb_InitializeNonIsochPipes(struct _DEVICE_EXTENSION *
   __ptr64,struct _USBD_INTERFACE_INFORMATION * __ptr64) */

long __cdecl
BthUsb_InitializeNonIsochPipes(_DEVICE_EXTENSION *param_1,_USBD_INTERFACE_INFORMATION *param_2)

{
  void *pvVar1;
  uchar uVar2;
  uchar uVar3;
  _USBD_PIPE_TYPE _Var4;
  ulong uVar5;
  _USBD_PIPE_INFORMATION *p_Var6;
  _USBD_PIPE_INFORMATION *p_Var7;
  uint uVar8;
  
  p_Var6 = param_2->Pipes;
  uVar8 = 0;
  p_Var7 = p_Var6;
  if (param_2->NumberOfPipes == 0) {
    return -0x3ffffff3;
  }
  while ((p_Var7->PipeType != UsbdPipeTypeBulk || (-1 < (char)p_Var7->EndpointAddress))) {
    uVar8 = uVar8 + 1;
    p_Var7 = p_Var7 + 1;
    if (param_2->NumberOfPipes <= uVar8) {
      return -0x3ffffff3;
    }
  }
  if (p_Var7 == (_USBD_PIPE_INFORMATION *)0x0) {
    return -0x3ffffff3;
  }
  uVar2 = p_Var7->EndpointAddress;
  uVar3 = p_Var7->Interval;
  _Var4 = p_Var7->PipeType;
  pvVar1 = p_Var7->PipeHandle;
  uVar8 = 0;
  param_1->Pipes[0].MaximumPacketSize = p_Var7->MaximumPacketSize;
  param_1->Pipes[0].EndpointAddress = uVar2;
  param_1->Pipes[0].Interval = uVar3;
  param_1->Pipes[0].PipeType = _Var4;
  param_1->Pipes[0].PipeHandle = pvVar1;
  uVar5 = p_Var7->PipeFlags;
  param_1->Pipes[0].MaximumTransferSize = p_Var7->MaximumTransferSize;
  param_1->Pipes[0].PipeFlags = uVar5;
  p_Var7 = p_Var6;
  if (param_2->NumberOfPipes == 0) {
    return -0x3ffffff3;
  }
  while ((p_Var7->PipeType != UsbdPipeTypeBulk || ((char)p_Var7->EndpointAddress < '\0'))) {
    uVar8 = uVar8 + 1;
    p_Var7 = p_Var7 + 1;
    if (param_2->NumberOfPipes <= uVar8) {
      return -0x3ffffff3;
    }
  }
  if (p_Var7 == (_USBD_PIPE_INFORMATION *)0x0) {
    return -0x3ffffff3;
  }
  uVar2 = p_Var7->EndpointAddress;
  uVar3 = p_Var7->Interval;
  _Var4 = p_Var7->PipeType;
  pvVar1 = p_Var7->PipeHandle;
  param_1->Pipes[1].MaximumPacketSize = p_Var7->MaximumPacketSize;
  param_1->Pipes[1].EndpointAddress = uVar2;
  param_1->Pipes[1].Interval = uVar3;
  param_1->Pipes[1].PipeType = _Var4;
  param_1->Pipes[1].PipeHandle = pvVar1;
  uVar5 = p_Var7->PipeFlags;
  uVar8 = 0;
  param_1->Pipes[1].MaximumTransferSize = p_Var7->MaximumTransferSize;
  param_1->Pipes[1].PipeFlags = uVar5;
  if (param_2->NumberOfPipes == 0) {
    return -0x3ffffff3;
  }
  while ((p_Var6->PipeType != UsbdPipeTypeInterrupt || (-1 < (char)p_Var6->EndpointAddress))) {
    uVar8 = uVar8 + 1;
    p_Var6 = p_Var6 + 1;
    if (param_2->NumberOfPipes <= uVar8) {
      return -0x3ffffff3;
    }
  }
  if (p_Var6 == (_USBD_PIPE_INFORMATION *)0x0) {
    return -0x3ffffff3;
  }
  uVar2 = p_Var6->EndpointAddress;
  uVar3 = p_Var6->Interval;
  _Var4 = p_Var6->PipeType;
  pvVar1 = p_Var6->PipeHandle;
  param_1->Pipes[2].MaximumPacketSize = p_Var6->MaximumPacketSize;
  param_1->Pipes[2].EndpointAddress = uVar2;
  param_1->Pipes[2].Interval = uVar3;
  param_1->Pipes[2].PipeType = _Var4;
  param_1->Pipes[2].PipeHandle = pvVar1;
  uVar5 = p_Var6->PipeFlags;
  param_1->Pipes[2].MaximumTransferSize = p_Var6->MaximumTransferSize;
  param_1->Pipes[2].PipeFlags = uVar5;
  return 0;
}



===== BthUsb_IsIsochInterface @ 14001c490 =====

/* WARNING: Type propagation algorithm not settling */
/* unsigned char __cdecl __based(PAGE) BthUsb_IsIsochInterface(struct _USBD_INTERFACE_INFORMATION *
   __ptr64) */

uchar __cdecl BthUsb_IsIsochInterface(_USBD_INTERFACE_INFORMATION *param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uchar *puVar4;
  uint uVar5;
  char cVar6;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar1 = param_1->NumberOfPipes;
  if (2 < uVar1) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_cddd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,(ulonglong)param_1->InterfaceNumber,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    return '\0';
  }
  bVar3 = false;
  bVar2 = false;
  uVar5 = 0;
  if (uVar1 != 0) {
    puVar4 = &param_1->Pipes[0].EndpointAddress;
    cVar6 = '\x01';
    do {
      if (*(_USBD_PIPE_TYPE *)(puVar4 + 2) != UsbdPipeTypeIsochronous) {
        return '\0';
      }
      if ((char)*puVar4 < '\0') {
        if (bVar2) {
          bVar2 = false;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar6 = '\0';
          }
          else {
            cVar6 = '\x01';
          }
          WPP_RECORDER_AND_TRACE_SF_cdd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                     (ulonglong)param_1->InterfaceNumber,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x35,
                     in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,param_1->InterfaceNumber,
                     param_1->AlternateSetting);
          break;
        }
        bVar2 = true;
      }
      else {
        if (bVar3) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar6 = '\0';
          }
          WPP_RECORDER_AND_TRACE_SF_cdd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,2,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,
                     in_stack_ffffffffffffffc0,0x36,in_stack_ffffffffffffffd0,
                     in_stack_ffffffffffffffd8,param_1->InterfaceNumber,param_1->AlternateSetting);
          return '\0';
        }
        bVar3 = true;
      }
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 0x18;
    } while (uVar5 < uVar1);
    if ((bVar3) && (bVar2)) {
      return '\x01';
    }
  }
  return '\0';
}



===== BthUsb_IsNonIsochInterface @ 14001c5f0 =====

/* WARNING: Type propagation algorithm not settling */
/* unsigned char __cdecl __based(PAGE) BthUsb_IsNonIsochInterface(struct _USBD_INTERFACE_INFORMATION
   * __ptr64) */

uchar __cdecl BthUsb_IsNonIsochInterface(_USBD_INTERFACE_INFORMATION *param_1)

{
  uchar uVar1;
  byte bVar2;
  uchar uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uchar *puVar8;
  char cVar9;
  uint uVar10;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined2 uVar11;
  undefined8 in_stack_ffffffffffffffd0;
  undefined4 in_stack_ffffffffffffffd8;
  undefined4 in_stack_ffffffffffffffdc;
  
  uVar4 = param_1->NumberOfPipes;
  if (3 < uVar4) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar9 = '\0';
    }
    else {
      cVar9 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_ddd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,(ulonglong)param_1->InterfaceNumber,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    return '\0';
  }
  bVar7 = false;
  bVar6 = false;
  bVar5 = false;
  uVar10 = 0;
  if (uVar4 != 0) {
    puVar8 = &param_1->Pipes[0].EndpointAddress;
    cVar9 = '\x01';
    do {
      if (*(_USBD_PIPE_TYPE *)(puVar8 + 2) == UsbdPipeTypeBulk) {
        if ((char)*puVar8 < '\0') {
          if (bVar5) {
            bVar5 = false;
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar9 = '\0';
            }
            else {
              cVar9 = '\x01';
            }
            uVar1 = param_1->AlternateSetting;
            bVar2 = param_1->InterfaceNumber;
            uVar11 = 0x2e;
LAB_14001c735:
            WPP_RECORDER_AND_TRACE_SF_cdd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,(ulonglong)bVar2,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,
                       in_stack_ffffffffffffffc0,uVar11,in_stack_ffffffffffffffd0,
                       CONCAT44(in_stack_ffffffffffffffdc,in_stack_ffffffffffffffd8),bVar2,uVar1);
            break;
          }
          bVar5 = true;
        }
        else {
          if (bVar6) {
            bVar6 = false;
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar9 = '\0';
            }
            else {
              cVar9 = '\x01';
            }
            uVar1 = param_1->AlternateSetting;
            bVar2 = param_1->InterfaceNumber;
            uVar11 = 0x2f;
            goto LAB_14001c735;
          }
          bVar6 = true;
        }
      }
      else {
        if (*(_USBD_PIPE_TYPE *)(puVar8 + 2) != UsbdPipeTypeInterrupt) {
          return '\0';
        }
        if (-1 < (char)*puVar8) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          uVar1 = param_1->AlternateSetting;
          uVar3 = param_1->InterfaceNumber;
          uVar11 = 0x31;
LAB_14001c7b3:
          WPP_RECORDER_AND_TRACE_SF_cdd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,WPP_GLOBAL_Control,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,
                     in_stack_ffffffffffffffc0,uVar11,in_stack_ffffffffffffffd0,
                     CONCAT44(in_stack_ffffffffffffffdc,in_stack_ffffffffffffffd8),uVar3,uVar1);
          return '\0';
        }
        if (bVar7) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          uVar1 = param_1->AlternateSetting;
          uVar3 = param_1->InterfaceNumber;
          uVar11 = 0x30;
          goto LAB_14001c7b3;
        }
        bVar7 = true;
      }
      uVar10 = uVar10 + 1;
      puVar8 = puVar8 + 0x18;
    } while (uVar10 < uVar4);
    if (((bVar7) && (bVar5)) && (bVar6)) {
      return '\x01';
    }
  }
  return '\0';
}



===== BthUsb_PipeRequest @ 14001c7e4 =====

/* long __cdecl BthUsb_PipeRequest(struct _DEVICE_EXTENSION * __ptr64,unsigned short,void *
   __ptr64,long) */

long __cdecl
BthUsb_PipeRequest(_DEVICE_EXTENSION *param_1,ushort param_2,void *param_3,long param_4)

{
  int iVar1;
  char cVar2;
  char cVar3;
  undefined8 uVar4;
  undefined8 in_stack_ffffffffffffff28;
  undefined4 local_a8;
  void *local_90;
  
  uVar4 = 0x96;
  memset((void *)((longlong)&local_a8 + 2),0,0x96);
  cVar3 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_qH
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,uVar4,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,3,0x42,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)param_3,2);
  local_a8 = 0x20028;
  local_90 = param_3;
  iVar1 = USBCallSyncEx((longlong)param_1->TopOfStack,(longlong)&local_a8,100,&param_1->RemoveLock);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_qD
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,WPP_GLOBAL_Control,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,3,0x43,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)param_3,(char)iVar1);
  return iVar1;
}



===== BthUsb_SelectConfigAndInitialize @ 14001c8fc =====

/* long __cdecl __based(PAGE) BthUsb_SelectConfigAndInitialize(struct _DEVICE_EXTENSION * __ptr64)
    */

long __cdecl BthUsb_SelectConfigAndInitialize(_DEVICE_EXTENSION *param_1)

{
  byte bVar1;
  _USB_CONFIGURATION_DESCRIPTOR *p_Var2;
  _USBD_INTERFACE_INFORMATION *p_Var3;
  bool bVar4;
  bool bVar5;
  uchar uVar6;
  long lVar7;
  undefined8 *puVar8;
  _USB_INTERFACE_DESCRIPTOR *p_Var9;
  longlong lVar10;
  char cVar11;
  undefined8 *puVar12;
  uint uVar13;
  char cVar14;
  undefined8 in_R8;
  ulonglong uVar15;
  _USB_CONFIGURATION_DESCRIPTOR *local_res20;
  undefined4 in_stack_ffffffffffffff88;
  long lVar16;
  undefined4 in_stack_ffffffffffffff98;
  long lVar17;
  
  cVar14 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar11 = '\0';
  }
  else {
    cVar11 = '\x01';
  }
  lVar17 = CONCAT22((short)((uint)in_stack_ffffffffffffff98 >> 0x10),0x21);
  lVar16 = 2;
  lVar7 = CONCAT31((int3)((uint)in_stack_ffffffffffffff88 >> 8),4);
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x21,
             &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
  p_Var2 = param_1->ConfigDescriptor;
  bVar4 = false;
  uVar15 = 0x42425355;
  bVar5 = false;
  bVar1 = p_Var2->bNumInterfaces;
  puVar8 = (undefined8 *)ExAllocatePool2(0x40,(bVar1 + 1) * 0x10);
  if (puVar8 == (undefined8 *)0x0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar14 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar14,uVar15,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x22,
               &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
    lVar7 = -0x3fffff66;
  }
  else {
    uVar13 = 0;
    local_res20 = p_Var2;
    if (bVar1 != 0) {
      puVar12 = puVar8;
      do {
        uVar15 = 0xffffffff;
        p_Var9 = BthUsb_GetInterfaceDescriptor(param_1,&local_res20,-1,0,lVar7,lVar16,lVar17);
        if (p_Var9 == (_USB_INTERFACE_DESCRIPTOR *)0x0) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar11 = '\0';
          }
          else {
            cVar11 = '\x01';
          }
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar15,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x23,
                     &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids);
          lVar7 = -0x3ffffff3;
          bVar4 = false;
          goto LAB_14001cda9;
        }
        *puVar12 = p_Var9;
        uVar13 = uVar13 + 1;
        puVar12 = puVar12 + 2;
      } while (uVar13 < bVar1);
    }
    lVar10 = USBD_CreateConfigurationRequestEx(p_Var2);
    if (lVar10 == 0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar11 = '\0';
      }
      else {
        cVar11 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar15,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x24,
                 &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,0);
      lVar7 = -0x3fffff66;
    }
    else {
      uVar15 = 500;
      lVar7 = USBCallSyncEx((longlong)param_1->TopOfStack,lVar10,500,&param_1->RemoveLock);
      if (lVar7 < 0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar11 = '\0';
        }
        else {
          cVar11 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar15,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x25,
                   &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)lVar7);
      }
      else {
        uVar13 = 0;
        param_1->ConfigHandle = *(void **)(lVar10 + 0x20);
        if (bVar1 != 0) {
          puVar12 = puVar8;
          do {
            p_Var3 = (_USBD_INTERFACE_INFORMATION *)puVar12[1];
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
              cVar11 = '\0';
            }
            else {
              cVar11 = '\x01';
            }
            uVar15 = (ulonglong)p_Var3->InterfaceNumber;
            WPP_RECORDER_AND_TRACE_SF_dd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar15,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x26,
                       &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,p_Var3->InterfaceNumber,
                       p_Var3->AlternateSetting);
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
              cVar11 = '\0';
            }
            else {
              cVar11 = '\x01';
            }
            WPP_RECORDER_AND_TRACE_SF_d
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar15,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x27,
                       &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)p_Var3->NumberOfPipes)
            ;
            if (p_Var3->NumberOfPipes == 0) {
LAB_14001ccf5:
              if (lVar7 < 0) break;
LAB_14001ccfd:
              if (bVar5) {
LAB_14001cd07:
                if (bVar4) break;
              }
            }
            else {
              if ((!bVar4) && (uVar6 = BthUsb_IsNonIsochInterface(p_Var3), uVar6 != '\0')) {
                lVar7 = BthUsb_InitializeNonIsochPipes(param_1,p_Var3);
                if (-1 < lVar7) {
                  bVar4 = true;
                  goto LAB_14001ccfd;
                }
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar11 = '\0';
                }
                else {
                  cVar11 = '\x01';
                }
                WPP_RECORDER_AND_TRACE_SF_d
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar15,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x2a,
                           &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)lVar7);
                break;
              }
              if ((bVar5) || (uVar6 = BthUsb_IsIsochInterface(p_Var3), uVar6 == '\0'))
              goto LAB_14001ccf5;
              lVar7 = BthUsb_InitializeIsochPipes(param_1,p_Var3);
              if (-1 < lVar7) {
                (param_1->Sco).OffInterface = (_USB_INTERFACE_DESCRIPTOR *)*puVar12;
                bVar5 = true;
                goto LAB_14001cd07;
              }
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                cVar11 = '\0';
              }
              else {
                cVar11 = '\x01';
              }
              WPP_RECORDER_AND_TRACE_SF_d
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,uVar15,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x2b,
                         &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)lVar7);
              lVar7 = 0;
            }
            uVar13 = uVar13 + 1;
            puVar12 = puVar12 + 2;
          } while (uVar13 < bVar1);
        }
      }
      ExFreePoolWithTag(lVar10,0);
    }
LAB_14001cda9:
    ExFreePoolWithTag(puVar8,0);
    if ((-1 < lVar7) && (!bVar4)) {
      lVar7 = -0x3fffffff;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar14 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar14,uVar15,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x2c,
               &WPP_d8535a00fd343f841f0c7c5dde609d87_Traceguids,(char)lVar7);
  }
  return lVar7;
}



===== USBCallSyncEx @ 14001ce28 =====

int USBCallSyncEx(longlong param_1,longlong param_2,int param_3,undefined8 param_4)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar5;
  longlong local_50;
  longlong local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  lVar3 = 0;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  bVar1 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,7,10);
  }
  lVar4 = param_1;
  iVar2 = IoAcquireRemoveLockEx
                    (param_4,param_1,
                     "onecore\\drivers\\wdm\\bluetooth\\drivers\\bthusbutil\\usbutil.c",100,
                     CONCAT44(uVar5,0x20));
  if (iVar2 < 0) {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,4,0xb);
    }
  }
  else {
    bVar1 = true;
    if ((param_1 == 0) || (param_2 == 0)) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,4,0xc);
      }
      iVar2 = -0x3ffffff3;
    }
    else {
      KeInitializeEvent(&local_40,1,0);
      lVar4 = 0;
      lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c));
      local_48 = lVar3;
      if (lVar3 == 0) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,4,0xd);
        }
        iVar2 = -0x3fffff66;
      }
      else {
        lVar4 = *(longlong *)(lVar3 + 0xb8);
        *(undefined1 *)(lVar4 + -0x48) = 0xf;
        *(undefined4 *)(lVar4 + -0x30) = 0x220003;
        *(longlong *)(lVar4 + -0x40) = param_2;
        lVar4 = *(longlong *)(lVar3 + 0xb8);
        *(code **)(lVar4 + -0x10) = USBCallSyncCompletionRoutine;
        *(undefined8 **)(lVar4 + -8) = &local_40;
        *(undefined1 *)(lVar4 + -0x45) = 0;
        *(undefined1 *)(lVar4 + -0x45) = 0x40;
        *(undefined1 *)(lVar4 + -0x45) = 0xc0;
        *(undefined1 *)(lVar4 + -0x45) = 0xe0;
        lVar4 = lVar3;
        iVar2 = IofCallDriver(param_1);
        if (iVar2 == 0x103) {
          local_50 = (longlong)param_3 * -10000;
          lVar4 = 0;
          iVar2 = KeWaitForSingleObject(&local_40,0,0,0,&local_50);
          if (iVar2 == 0x102) {
            iVar2 = -0x3fffff4b;
            IoCancelIrp(lVar3);
            lVar4 = 0;
            KeWaitForSingleObject(&local_40,0,0,0,0);
          }
          else {
            iVar2 = *(int *)(lVar3 + 0x30);
          }
        }
      }
    }
  }
  if (bVar1) {
    IoReleaseRemoveLockEx(param_4,param_1,0x20);
    lVar4 = param_1;
  }
  if (lVar3 != 0) {
    IoFreeIrp(lVar3);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,7,0xe);
  }
  return iVar2;
}



===== BthQueryKeyValue @ 14001d13c =====

void BthQueryKeyValue(undefined8 param_1,undefined8 param_2,void *param_3)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  BthQueryKeyValueEx(param_1,(longlong)&local_18,param_3);
  return;
}



===== BthQueryKeyValueEx @ 14001d188 =====

int BthQueryKeyValueEx(undefined8 param_1,longlong param_2,void *param_3)

{
  int iVar1;
  longlong lVar2;
  uint local_res20 [2];
  
  local_res20[0] = *(ushort *)(param_2 + 2) + 0x1c;
  if (local_res20[0] < *(ushort *)(param_2 + 2) + 0x18) {
    iVar1 = -0x3fffff6b;
  }
  else {
    lVar2 = ExAllocatePool2(0x100,local_res20[0],0x6c687442);
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = ZwQueryValueKey(param_1,param_2,1,lVar2,local_res20[0],local_res20);
      if (-1 < iVar1) {
        if (*(uint *)(lVar2 + 0xc) < 5) {
          memmove(param_3,(void *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2),
                  (ulonglong)*(uint *)(lVar2 + 0xc));
        }
        else {
          iVar1 = -0x3fffffdd;
        }
      }
      ExFreePoolWithTag(lVar2,0);
    }
  }
  return iVar1;
}



===== BthQueryRadioCompatFlags @ 14001d274 =====

undefined8 BthQueryRadioCompatFlags(undefined8 param_1,longlong param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  longlong local_res10;
  longlong local_res18;
  undefined8 local_res20;
  
  local_res18 = 0;
  local_res20 = 0;
  local_res10 = param_2;
  if (param_2 == 0) {
    iVar1 = GetBthportDeviceObject(&local_res18,&local_res10);
    if (iVar1 < 0) goto LAB_14001d30b;
  }
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0x228,0x43445442);
  if (pwVar2 != (wchar_t *)0x0) {
    uVar3 = GetRadioFingerprintString(pwVar2,0x140011c10,local_res10);
    if (-1 < (int)uVar3) {
      KseQueryDeviceFlags(pwVar2,L"BthRadioHci",&local_res20);
    }
    ExFreePoolWithTag(pwVar2,0x43445442);
  }
LAB_14001d30b:
  if (local_res18 != 0) {
    ObfDereferenceObject();
  }
  return local_res20;
}



===== GetBthportDeviceObject @ 14001d334 =====

int GetBthportDeviceObject(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_2 = 0;
  local_res10 = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = IoGetDeviceInterfaces(&GUID_BTHPORT_DEVICE_INTERFACE,0,0,&local_res10);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_18,local_res10);
    iVar1 = IoGetDeviceObjectPointer(&local_18,0x1f01ff,param_1,param_2);
    ExFreePool(local_res10);
  }
  return iVar1;
}



===== GetRadioFingerprintInfo @ 14001d3dc =====

int GetRadioFingerprintInfo(longlong *param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  *param_1 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar2 = ExAllocatePool2(0x40,0x1ba,0x43445442);
  if (lVar2 == 0) {
    return -0x3fffff66;
  }
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoBuildDeviceIoControlRequest(0x411148,param_2,0,0,lVar2,0x1ba,0,&local_28,&local_38);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(param_2,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
    }
    else if (iVar1 < 0) goto LAB_14001d494;
    iVar1 = (int)local_38;
    if (-1 < (int)local_38) {
      *param_1 = lVar2;
      return (int)local_38;
    }
  }
LAB_14001d494:
  ExFreePoolWithTag(lVar2,0x43445442);
  return iVar1;
}



===== GetRadioFingerprintString @ 14001d514 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetRadioFingerprintString(wchar_t *param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  ulonglong uVar4;
  short *psVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 auStack_2a8 [32];
  short *local_288;
  uint local_280;
  uint local_278;
  uint local_270;
  uint local_268;
  uint local_260;
  undefined8 local_258;
  uint local_250;
  undefined8 local_248;
  longlong local_238;
  longlong local_230;
  longlong local_228 [2];
  undefined4 local_218;
  short local_214 [202];
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  undefined8 local_68;
  uint local_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2a8;
  memset(&local_218,0,0x1c8);
  local_238 = 0;
  local_230 = 0;
  local_228[0] = param_3;
  if (param_3 == 0) {
    uVar2 = GetBthportDeviceObject(&local_230,local_228);
    lVar7 = 0;
    if ((int)uVar2 < 0) goto LAB_14001d667;
  }
  uVar2 = GetRadioFingerprintInfo(&local_238,local_228[0]);
  lVar7 = local_238;
  if (-1 < (int)uVar2) {
    local_218 = 1;
    psVar5 = local_214;
    local_80 = *(uint *)(local_238 + 0x192);
    lVar6 = 0xc9;
    local_7c = *(uint *)(local_238 + 0x196);
    local_78 = *(uint *)(local_238 + 0x19a);
    local_74 = *(uint *)(local_238 + 0x19e);
    local_70 = *(uint *)(local_238 + 0x1a2);
    local_68 = *(undefined8 *)(local_238 + 0x1a6);
    local_60 = *(uint *)(local_238 + 0x1ae);
    local_58 = *(undefined8 *)(local_238 + 0x1b2);
    do {
      if ((lVar6 == -0x7fffff35) ||
         (sVar1 = *(short *)((local_238 - (longlong)local_214) + (longlong)psVar5), sVar1 == 0))
      break;
      *psVar5 = sVar1;
      psVar5 = psVar5 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    psVar3 = psVar5 + -1;
    if (lVar6 != 0) {
      psVar3 = psVar5;
    }
    uVar2 = ~-(uint)(lVar6 != 0) & 0x80000005;
    *psVar3 = 0;
  }
LAB_14001d667:
  if (local_230 != 0) {
    ObfDereferenceObject();
    local_230 = 0;
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7);
  }
  if ((int)uVar2 < 0) {
    uVar4 = (ulonglong)uVar2;
  }
  else {
    local_250 = local_60 & 0xffffff;
    lVar7 = -1;
    do {
      lVar6 = lVar7;
      lVar7 = lVar6 + 1;
    } while (*(short *)(param_2 + lVar7 * 2) != 0);
    local_248 = local_58;
    local_258 = local_68;
    local_288 = local_214;
    local_260 = local_70 & 0xffff;
    local_268 = local_74 & 0xff;
    local_270 = local_78 & 0xffff;
    local_278 = local_7c & 0xffff;
    local_280 = local_80 & 0xff;
    uVar4 = RtlStringCchPrintfW(param_1,lVar6 + 0x10a,
                                L"%s:%s;%02X;%04X;%04X;%02X;%04X;%016I64X;%06X;%016I64X;",param_2);
  }
  return uVar4;
}



===== USBCallSyncEx$fin$0 @ 14001d764 =====

void USBCallSyncEx_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = param_2;
  if (*(char *)(param_2 + 0x30) != '\0') {
    lVar1 = *(longlong *)(param_2 + 0x90);
    IoReleaseRemoveLockEx(*(undefined8 *)(param_2 + 0xa8),lVar1,0x20);
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    IoFreeIrp();
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar1,7,0xe);
  }
  return;
}



===== __security_init_cookie @ 14001e008 =====

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



===== DriverEntry @ 14001e03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(_DRIVER_OBJECT *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  _tlgProvider_t *p_Var5;
  char cVar6;
  char cVar7;
  _GUID *p_Var8;
  __uint64 *p_Var9;
  int local_res18 [2];
  _tlgWrapSz<unsigned_short> local_res20;
  undefined4 uVar11;
  undefined4 *puVar10;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  _GUID *p_Stack_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  code *local_a0;
  code *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  int *local_78;
  undefined1 local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  
  _DAT_140014338 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140014318 = &WPP_ThisDir_CTLGUID_bthusb;
  DAT_140014320 = 0;
  _DAT_140014330 = 0;
  cVar7 = '\x01';
  _DAT_140014350 = 0;
  _DAT_140014358 = 0;
  WppLoadTracingSupport();
  _DAT_140014330 = 0;
  WppInitKm(param_1,param_2);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
     (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,param_3,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,10,
             &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids);
  local_res18[0] = wil_InitializeFeatureStaging();
  local_78 = local_res18;
  local_70 = 1;
  if (local_res18[0] < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar6 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0xb,
               &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)local_res18[0]);
    local_res18[0] = 0;
  }
  g_PdoLockedList.ListHead.Blink = &g_PdoLockedList.ListHead;
  g_PdoLockedList.ListHead.Flink = &g_PdoLockedList.ListHead;
  KeInitializeSpinLock(0x1400142e8);
  g_PdoLockedList.ListLock = &g_PdoLockedList.SpinLock;
  g_PdoLockedList.Count = 0;
  RefObj_GlobalsInit();
  p_Var9 = &g_EtwRegHandle;
  p_Var8 = (_GUID *)0x0;
  local_res18[0] = EtwRegister(&BTHUSB_ETW_PROVIDER,BthUsb_EtwEnableCallback);
  if (local_res18[0] < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar6 = '\0';
    }
    p_Var9 = *(__uint64 **)(WPP_GLOBAL_Control + 0x40);
    p_Var8 = (_GUID *)WPP_GLOBAL_Control;
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,WPP_GLOBAL_Control,p_Var9,3,2,0xc,
               &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)local_res18[0]);
    local_res18[0] = 0;
  }
  local_b8 = 0;
  p_Stack_b0 = (_GUID *)0x0;
  local_c8 = 0;
  uStack_c0 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_c8,0);
    iVar3 = IoQueryFullDriverPath(param_1,&local_c8);
    if (iVar3 < 0) {
      local_res18[0] = iVar3;
    }
    else {
      p_Var8 = (_GUID *)CONCAT71((int7)((ulonglong)p_Var8 >> 8),1);
      iVar3 = RtlUnicodeStringToAnsiString(&local_b8,&local_c8);
      ExFreePoolWithTag(uStack_c0,0);
      if (iVar3 < 0) {
        local_res18[0] = iVar3;
      }
      else {
        uVar1 = (uint)(ushort)local_b8;
        do {
          uVar2 = uVar1;
          uVar1 = uVar2 - 1;
          if (uVar1 == 0) goto LAB_14001e3e8;
          p_Var8 = p_Stack_b0;
        } while (p_Stack_b0->Data4[(ulonglong)uVar1 - 8] != '\\');
        if (uVar1 != (ushort)local_b8) {
          local_88 = 0;
          uStack_80 = 0;
          RtlInitAnsiString(&local_88,p_Stack_b0->Data4 + ((ulonglong)uVar2 - 8));
          local_38 = local_88;
          uStack_30 = uStack_80;
          uVar4 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_38);
          iVar3 = (int)uVar4;
        }
LAB_14001e3e8:
        RtlFreeAnsiString(&local_b8);
        local_res18[0] = iVar3;
        if (-1 < iVar3) goto LAB_14001e246;
      }
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar6 = '\0';
    }
    p_Var9 = *(__uint64 **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,p_Var8,p_Var9,3,2,0xd,
               &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)local_res18[0]);
    local_res18[0] = 0;
  }
  else {
    local_res18[0] = 0;
  }
LAB_14001e246:
  p_Var5 = (_tlgProvider_t *)&DAT_140014000;
  local_res18[0] = TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140014000);
  if (local_res18[0] < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar6 = '\0';
    }
    p_Var9 = *(__uint64 **)(WPP_GLOBAL_Control + 0x40);
    p_Var5 = *(_tlgProvider_t **)(WPP_GLOBAL_Control + 0x18);
    p_Var8 = (_GUID *)WPP_GLOBAL_Control;
    WPP_RECORDER_AND_TRACE_SF_d
              (p_Var5,cVar6,WPP_GLOBAL_Control,p_Var9,3,2,0xe,
               &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)local_res18[0]);
    local_res18[0] = 0;
  }
  if (((5 < DAT_140014000) && ((_DAT_140014010 & 0x400000000000) != 0)) &&
     ((DAT_140014018 & 0x400000000000) == DAT_140014018)) {
    local_c8 = 0x2000800;
    local_res20.Psz = L"BthUsb.sys";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>_>
              (p_Var5,&DAT_140011d4f,p_Var8,(_GUID *)p_Var9,(_tlgWrapperByVal<8> *)&local_c8,
               &local_res20);
  }
  local_a4 = 0;
  local_90 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_a8 = 0x20;
  }
  else if (WdfStructureCount < 0x19) {
    local_a8 = 0xffffffff;
  }
  else {
    local_a8 = *(undefined4 *)(WdfStructures + 0xc0);
  }
  local_8c = 0x42425355;
  local_a0 = BthUsb_WdfDeviceAdd;
  puVar10 = &local_a8;
  local_98 = BthUsb_WdfDriverUnload;
  local_res18[0] =
       (**(code **)(WdfFunctions_01031 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,puVar10,0);
  uVar11 = (undefined4)((ulonglong)puVar10 >> 0x20);
  if (local_res18[0] < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar7 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xf,
               &WPP_1f9a50d1de1b36addda1af3e8dc29e49_Traceguids,(char)local_res18[0]);
    if (-1 < local_res18[0]) goto LAB_14001e50b;
  }
  else {
LAB_14001e50b:
    local_68 = BthUsb_GetCapabilities;
    local_60 = BthUsb_ScoValidateChannel;
    local_58 = BthUsb_ScoAddChannel;
    local_50 = BthUsb_ScoRemoveChannel;
    local_48 = BthUsb_ScoControlChannel;
    local_res18[0] =
         (*DAT_140014280)(BthDriverGlobals,param_1,param_2,&local_68,CONCAT44(uVar11,0x28));
    if (-1 < local_res18[0]) goto LAB_14001e57b;
  }
  BthUsb_DriverUnload(param_1);
LAB_14001e57b:
  iVar3 = local_res18[0];
  wil::details::lambda_call<<lambda_ab0b21a5b1f80815114ac5907429201e>_>::
  ~lambda_call<<lambda_ab0b21a5b1f80815114ac5907429201e>_>(&local_78);
  return iVar3;
}



===== wil_InitializeFeatureStaging @ 14001e5ac =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001e633;
    }
LAB_14001e66d:
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
LAB_14001e633:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001e66d;
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
    goto LAB_14001e66d;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400137d7 < ppuVar3) goto LAB_14001e66d;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001e633;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001e6c0 =====

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
            if (&UNK_1400137d7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001e7aa;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001e7aa;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001e7aa:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400137d7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


