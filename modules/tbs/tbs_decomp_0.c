
===== Write<_tlgWrapSz<unsigned_short>_> @ 180001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short> >(struct _tlgProvider_t const * __ptr64,void
   const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapSz<unsigned_short>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_78 [32];
  _EVENT_DATA_DESCRIPTOR local_48 [2];
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_28 = *(wchar_t **)param_5;
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
  local_1c = 0;
  lVar1 = _tlgWriteTransfer_EventWriteTransfer
                    (0x180015080,param_2,(LPCGUID)0x0,(LPCGUID)0x0,3,local_48);
  return lVar1;
}



===== Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_> @ 18000109c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<4> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<4>
   const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5,_tlgWrapperByVal<4> *param_6)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_88 [32];
  _EVENT_DATA_DESCRIPTOR local_58 [2];
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = param_6;
  local_20 = 4;
  local_38 = *(wchar_t **)param_5;
  if (local_38 == (wchar_t *)0x0) {
    local_38 = L"";
    local_30 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_38[lVar2] != L'\0');
    local_30 = (int)lVar2 * 2 + 2;
  }
  local_2c = 0;
  lVar1 = _tlgWriteTransfer_EventWriteTransfer
                    (0x180015080,param_2,(LPCGUID)0x0,(LPCGUID)0x0,4,local_58);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_> @ 180001148 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1> >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID
   const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<1> *param_7,
          _tlgWrapperByVal<1> *param_8,_tlgWrapperByVal<1> *param_9,_tlgWrapperByVal<1> *param_10)

{
  long lVar1;
  undefined1 auStackY_c8 [32];
  _EVENT_DATA_DESCRIPTOR local_98 [2];
  _tlgWrapperByVal<8> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<1> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<1> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<1> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<1> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_28 = param_10;
  local_38 = param_9;
  local_48 = param_8;
  local_58 = param_7;
  local_68 = param_6;
  local_78 = param_5;
  local_70 = 8;
  local_20 = 1;
  local_30 = 1;
  local_40 = 1;
  local_50 = 1;
  local_60 = 4;
  lVar1 = _tlgWriteTransfer_EventWriteTransfer
                    (0x180015048,param_2,(LPCGUID)0x0,(LPCGUID)0x0,8,local_98);
  return lVar1;
}



===== _tlgWriteTransfer_EventWriteTransfer @ 180001200 =====

void _tlgWriteTransfer_EventWriteTransfer
               (longlong param_1,byte *param_2,LPCGUID param_3,LPCGUID param_4,ULONG param_5,
               PEVENT_DATA_DESCRIPTOR param_6)

{
  EVENT_DESCRIPTOR local_18;
  
  local_18._0_4_ = (uint)*param_2 << 0x18;
  local_18._4_4_ = ZEXT24(*(ushort *)(param_2 + 1));
  local_18.Keyword = *(ULONGLONG *)(param_2 + 3);
  param_6->Ptr = *(ULONGLONG *)(param_1 + 8);
  param_6->Size = (uint)**(ushort **)(param_1 + 8);
  param_6[1].Ptr = (ULONGLONG)(param_2 + 0xb);
  param_6->Reserved = 2;
  param_6[1].Size = (uint)*(ushort *)(param_2 + 0xb);
  param_6[1].Reserved = 1;
  EventWriteTransfer(*(REGHANDLE *)(param_1 + 0x20),&local_18,param_3,param_4,param_5,param_6);
  return;
}



===== `dynamic_initializer_for_'g_header_init_InitializeResultHeader'' @ 1800012b0 =====

void wil::details::_dynamic_initializer_for__g_header_init_InitializeResultHeader__(void)

{
  g_pfnGetContextAndNotifyFailure = GetContextAndNotifyFailure;
  details_abi::g_pProcessLocalData =
       (ProcessLocalStorage<wil::details_abi::ProcessLocalData> *)&g_processLocalData;
  g_pThreadFailureCallbacks = &g_threadFailureCallbacks;
  return;
}



===== `dynamic_initializer_for_'g_header_init_InitializeStagingHeaderInternalApi'' @ 1800012f0 =====

void wil::details::_dynamic_initializer_for__g_header_init_InitializeStagingHeaderInternalApi__
               (void)

{
  g_wil_details_ensureSubscribedToFeatureConfigurationChanges =
       EnsureSubscribedToFeatureConfigurationChanges;
  g_wil_details_subscribeFeatureStateCacheToConfigurationChanges =
       SubscribeFeatureStateCacheToConfigurationChanges;
  g_wil_details_internalGetFeatureEnabledState = WilApiImpl_GetFeatureEnabledState;
  g_wil_details_internalRecordFeatureUsage = WilApiImpl_RecordFeatureUsage;
  g_wil_details_internalSubscribeFeatureStateChangeNotification =
       WilApiImpl_SubscribeFeatureStateChangeNotification;
  g_wil_details_internalUnsubscribeFeatureStateChangeNotification =
       WilApiImpl_UnsubscribeFeatureStateChangeNotification;
  g_wil_details_realtimeFeatureUsageHook = wil_StagingConfig_LogStagedFeatureUsage;
  return;
}



===== `dynamic_initializer_for_'g_featureStateManager'' @ 180001360 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wil::details::_dynamic_initializer_for__g_featureStateManager__(void)

{
  details_abi::SubscriptionList::SubscriptionList((SubscriptionList *)&DAT_180015110);
  DAT_180015158 = 0;
  details_abi::SubscriptionList::SubscriptionList((SubscriptionList *)&DAT_180015160);
  _DAT_1800151c8 = 0;
  g_featureStateManager = (shutdown_aware_object<wil::details::FeatureStateManager>)0x1;
  _DAT_1800151a8 = 0;
  uRam00000001800151b0 = 0;
  _DAT_1800151b8 = 0;
  uRam00000001800151c0 = 0;
  atexit(_dynamic_atexit_destructor_for__g_featureStateManager__);
  return;
}



===== `dynamic_atexit_destructor_for_'g_threadFailureCallbacks'' @ 1800013c0 =====

void wil::details::_dynamic_atexit_destructor_for__g_threadFailureCallbacks__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_threadFailureCallbacks__);
  return;
}



===== `dynamic_initializer_for_'g_processLocalData'' @ 1800013e0 =====

void wil::details::_dynamic_initializer_for__g_processLocalData__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_processLocalData__);
  return;
}



===== `dynamic_initializer_for_'g_enabledStateManager'' @ 180001400 =====

void wil::details::_dynamic_initializer_for__g_enabledStateManager__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_enabledStateManager__);
  return;
}



===== `dynamic_initializer_for_'g_header_init_WilInitialize_ResultMacros_DesktopOrSystem'' @ 180001420 =====

void wil::details::
     _dynamic_initializer_for__g_header_init_WilInitialize_ResultMacros_DesktopOrSystem__(void)

{
  g_pfnGetModuleName = GetCurrentModuleName;
  g_pfnDebugBreak = DebugBreak;
  g_pfnRaiseFailFastException = WilDynamicLoadRaiseFailFastException;
  g_pfnFormatNtStatusMsg = FormatNtStatusMsg;
  g_pfnNotifyFailure = MicrosoftInternalNotifyFailure;
  g_pfnRtlNtStatusToDosErrorNoTeb = RtlNtStatusToDosErrorNoTeb;
  g_pfnDllShutdownInProgress = RtlDllShutdownInProgress;
  return;
}



===== `dynamic_initializer_for_'g_header_init_InitializeStagingSRUMFeatureReporting'' @ 180001490 =====

void wil::details::_dynamic_initializer_for__g_header_init_InitializeStagingSRUMFeatureReporting__
               (void)

{
  g_wil_details_RecordSRUMFeatureUsage = RecordSRUMFeatureUsage;
  return;
}



===== Tbsi_Is_Tpm_Present @ 1800014b0 =====

uint Tbsi_Is_Tpm_Present(void)

{
  uint uVar1;
  void *local_res8 [4];
  
                    /* 0x14b0  13  Tbsi_Is_Tpm_Present */
  local_res8[0] = (void *)0x0;
  uVar1 = TpmOpen(local_res8);
  if (local_res8[0] != (void *)0x0) {
    TpmClose(local_res8[0]);
  }
  return ~uVar1 >> 0x1f;
}



===== Tbsi_GetDeviceInfo @ 1800014f0 =====

uint Tbsi_GetDeviceInfo(undefined4 param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res18 [2];
  void *local_res20;
  
                    /* 0x14f0  9  Tbsi_GetDeviceInfo */
  local_res20 = (void *)0x0;
  uVar1 = TpmOpen(&local_res20);
  if (uVar1 == 0x80070002) {
    uVar1 = 0x8028400f;
  }
  uVar1 = TbsRemapError(uVar1,0x33c);
  if (-1 < (int)uVar1) {
    local_res18[0] = param_1;
    uVar2 = TpmDeviceIoControl(local_res20,0x22c01c,0,0,param_2,local_res18);
    uVar1 = TbsRemapError((uint)uVar2,0x33f);
  }
  if (local_res20 != (void *)0x0) {
    TpmClose(local_res20);
  }
  return uVar1;
}



===== TpmOpen @ 1800015a0 =====

/* long __cdecl TpmOpen(void * __ptr64 * __ptr64) */

long __cdecl TpmOpen(void **param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
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
  
  if (param_1 == (void **)0x0) {
    return -0x7ff8fffa;
  }
  local_34 = 0;
  local_1c = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_58,L"\\??\\TPM");
  local_28 = &local_58;
  local_38 = 0x30;
  local_30 = 0;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = NtCreateFile(param_1,0xc0000000,&local_38,&local_48,0,0,1,1,0,0,0);
  uVar2 = RtlNtStatusToDosError(uVar1);
  if (0 < (int)uVar2) {
    uVar2 = uVar2 & 0xffff | 0x80070000;
  }
  return uVar2;
}



===== Tbsip_Submit_Command @ 1800016b0 =====

void Tbsip_Submit_Command
               (void *param_1,uint param_2,uint param_3,uchar *param_4,uint param_5,uchar *param_6,
               uint *param_7)

{
                    /* 0x16b0  20  Tbsip_Submit_Command */
  Tbsip_Submit_Command_Internal(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



===== Tbsip_Submit_Command_Internal @ 1800016f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned int __cdecl Tbsip_Submit_Command_Internal(void * __ptr64,unsigned int,unsigned
   int,unsigned char const * __ptr64,unsigned int,unsigned char * __ptr64,unsigned int *
   __ptr64,unsigned int) */

uint __cdecl
Tbsip_Submit_Command_Internal
          (void *param_1,uint param_2,uint param_3,uchar *param_4,uint param_5,uchar *param_6,
          uint *param_7,uint param_8)

{
  char cVar1;
  uint uVar2;
  HANDLE pvVar3;
  _GUID *_Dst;
  ulonglong uVar4;
  uint uVar5;
  ulonglong dwBytes;
  _GUID *p_Var6;
  _GUID *p_Var7;
  undefined4 local_res10 [2];
  _FILETIME local_38 [2];
  
  if ((param_2 != 0) || (0x80000000 < param_3)) {
    return 0x80284002;
  }
  if ((param_6 == (uchar *)0x0) || (param_7 == (uint *)0x0)) {
    return 0x80284003;
  }
  if (*param_7 < 10) {
    return 0x80284005;
  }
  if ((param_4 == (uchar *)0x0) || (dwBytes = (ulonglong)param_5, param_5 == 0)) {
    return 0x80284002;
  }
  pvVar3 = GetProcessHeap();
  _Dst = HeapAlloc(pvVar3,0,dwBytes);
  if (_Dst == (_GUID *)0x0) {
    return 0x80070008;
  }
  memcpy(_Dst,param_4,(ulonglong)param_5);
  if (param_3 < 200) {
    cVar1 = '\x01';
  }
  else if (param_3 < 300) {
    cVar1 = '\x02';
  }
  else {
    cVar1 = (399 < param_3) + '\x03';
  }
  *(char *)&_Dst->Data1 = cVar1;
  local_38[0].dwLowDateTime = 0;
  local_38[0].dwHighDateTime = 0;
  GetSystemTimeAsFileTime(local_38);
  p_Var6 = (_GUID *)(ulonglong)param_5;
  if (param_8 == 0) {
    param_8 = 0x22c00c;
  }
  p_Var7 = _Dst;
  uVar4 = TpmDeviceIoControl(param_1,param_8,_Dst,param_5,param_6,param_7);
  local_38[0].dwLowDateTime = 0;
  local_38[0].dwHighDateTime = 0;
  GetSystemTimeAsFileTime(local_38);
  uVar2 = (uint)uVar4;
  if (uVar2 == 0x80070006) {
    uVar2 = 0x80284004;
  }
  uVar2 = TbsRemapError(uVar2,0x47b);
  if (((int)uVar2 < 0) || (*param_7 < 10)) goto LAB_1800018b3;
  uVar5 = CONCAT31(CONCAT21(CONCAT11(param_6[6],param_6[7]),param_6[8]),param_6[9]);
  if ((char)param_6[9] < '\0') {
    uVar5 = uVar5 & 0xfffff0bf;
    param_6[9] = (uchar)uVar5;
    param_6[6] = (uchar)(uVar5 >> 0x18);
    param_6[7] = (uchar)(uVar5 >> 0x10);
    param_6[8] = (uchar)(uVar5 >> 8);
  }
  if (uVar5 == 0x8e) {
LAB_18000191f:
    if ((DAT_180015080 < 6) ||
       (((_DAT_180015090 & 0x400000000000) == 0 ||
        ((DAT_180015098 & 0x400000000000) != DAT_180015098)))) goto LAB_1800018b3;
    local_38[0] = (_FILETIME)0x180010c48;
  }
  else {
    if (uVar5 != 0x921) {
      if ((uVar5 == 1) || (uVar5 == 0x1d)) goto LAB_18000191f;
      if (uVar5 != 0x803) {
        if (uVar5 == 0x101) {
          if (((5 < DAT_180015080) && ((_DAT_180015090 & 0x400000000000) != 0)) &&
             ((DAT_180015098 & 0x400000000000) == DAT_180015098)) {
            local_38[0] = (_FILETIME)0x180010ca0;
            local_res10[0] =
                 CONCAT31(CONCAT21(CONCAT11((char)_Dst->Data3,
                                            *(undefined1 *)((longlong)&_Dst->Data3 + 1)),
                                   _Dst->Data4[0]),_Dst->Data4[1]);
            _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
            ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
                      ((_tlgProvider_t *)0x101,&DAT_180011ab3,p_Var7,p_Var6,
                       (_tlgWrapSz<unsigned_short> *)local_38,(_tlgWrapperByVal<4> *)local_res10);
          }
        }
        else if (((uVar5 == 0x100) && (5 < DAT_180015080)) &&
                (((_DAT_180015090 & 0x400000000000) != 0 &&
                 ((DAT_180015098 & 0x400000000000) == DAT_180015098)))) {
          local_38[0] = (_FILETIME)0x180010cc8;
          local_res10[0] =
               CONCAT31(CONCAT21(CONCAT11((char)_Dst->Data3,
                                          *(undefined1 *)((longlong)&_Dst->Data3 + 1)),
                                 _Dst->Data4[0]),_Dst->Data4[1]);
          _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
          ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
                    ((_tlgProvider_t *)0x100,&DAT_180011ab3,p_Var7,p_Var6,
                     (_tlgWrapSz<unsigned_short> *)local_38,(_tlgWrapperByVal<4> *)local_res10);
        }
        goto LAB_1800018b3;
      }
    }
    if (((DAT_180015080 < 6) || ((_DAT_180015090 & 0x400000000000) == 0)) ||
       ((DAT_180015098 & 0x400000000000) != DAT_180015098)) goto LAB_1800018b3;
    local_38[0] = (_FILETIME)0x180010c80;
  }
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::Write<_tlgWrapSz<unsigned_short>_>
            ((_tlgProvider_t *)(ulonglong)uVar5,&DAT_180011af2,p_Var7,p_Var6,
             (_tlgWrapSz<unsigned_short> *)local_38);
LAB_1800018b3:
  p_Var6 = _Dst;
  for (; dwBytes != 0; dwBytes = dwBytes - 1) {
    *(undefined1 *)&p_Var6->Data1 = 0;
    p_Var6 = (_GUID *)((longlong)&p_Var6->Data1 + 1);
  }
  pvVar3 = GetProcessHeap();
  HeapFree(pvVar3,0,_Dst);
  return uVar2;
}



===== TbsRemapError @ 180001b60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint TbsRemapError(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8;
  uint local_a4;
  uint local_a0 [2];
  undefined8 local_98;
  EVENT_DESCRIPTOR local_90;
  _EVENT_DATA_DESCRIPTOR local_78;
  undefined *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if ((int)param_1 < 0) {
    if (((param_1 & 0x1fff0000) == 0x280000) && ((param_1 & 0xffff) - 0x4000 < 0x1000)) {
      uVar1 = param_1;
    }
    else {
      if (param_1 == 0x80070057) {
        uVar1 = 0x80284002;
      }
      else if (param_1 == 0x80280909) {
        uVar1 = 0x8028400d;
      }
      else if (param_1 == 0xc0291007) {
        uVar1 = 0x80284017;
      }
      else if (param_1 == 0xc0291008) {
        uVar1 = 0x80284018;
      }
      else {
        uVar1 = 0x80284001;
      }
      if (((5 < DAT_180015080) && ((_DAT_180015090 & 0x400000000000) != 0)) &&
         ((DAT_180015098 & 0x400000000000) == DAT_180015098)) {
        local_28 = &local_a8;
        local_38 = &local_a4;
        local_90.Keyword = 0x400000000000;
        local_48 = local_a0;
        local_58 = &local_98;
        local_90.Level = '\x05';
        local_90.Opcode = '\0';
        local_90.Task = 0;
        local_78.Ptr = (ULONGLONG)PTR_DAT_180015088;
        local_98 = 0x1000000;
        local_20 = 4;
        local_30 = 4;
        local_40 = 4;
        local_50 = 8;
        local_90.Id = 0;
        local_90.Version = '\0';
        local_90.Channel = '\v';
        local_78.Size = (ULONG)*(ushort *)PTR_DAT_180015088;
        local_68 = &DAT_180011b2f;
        local_78.Reserved = 2;
        local_60 = 0x3f;
        local_5c = 1;
        local_a0[1] = 0x223;
        local_a8 = param_2;
        local_a4 = uVar1;
        local_a0[0] = param_1;
        EventWriteTransfer(DAT_1800150a0,&local_90,(LPCGUID)0x0,(LPCGUID)0x0,6,&local_78);
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== TpmDeviceIoControl @ 180001d30 =====

ulonglong TpmDeviceIoControl(undefined8 param_1,undefined4 param_2,undefined8 param_3,
                            undefined4 param_4,undefined8 param_5,undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  ulonglong in_stack_ffffffffffffff68;
  HANDLE local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_4c = 0;
  local_34 = 0;
  local_68 = (HANDLE)0x0;
  uVar4 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (param_6 != (undefined4 *)0x0) {
    uVar4 = *param_6;
  }
  local_50 = 0x30;
  local_48 = 0;
  local_38 = 0x40;
  local_40 = 0;
  local_30 = 0;
  uStack_28 = 0;
  iVar1 = NtCreateEvent(&local_68,0x10000000,&local_50,0,
                        in_stack_ffffffffffffff68 & 0xffffffffffffff00);
  if (-1 < iVar1) {
    iVar1 = NtDeviceIoControlFile
                      (param_1,local_68,0,0,&local_60,param_2,param_3,param_4,param_5,uVar4);
    if (iVar1 == 0x103) {
      iVar1 = NtWaitForSingleObject(local_68,0,0);
    }
    if (((-1 < iVar1) && (iVar1 = (int)local_60, -1 < (int)local_60)) &&
       (param_6 != (undefined4 *)0x0)) {
      *param_6 = (undefined4)uStack_58;
    }
  }
  if (local_68 != (HANDLE)0x0) {
    uVar2 = Feature_ReplaceNtCloseWithCloseHandle__private_IsEnabledDeviceUsageNoInline();
    if (uVar2 == 0) {
      NtClose(local_68);
    }
    else {
      CloseHandle(local_68);
    }
  }
  uVar3 = RtlNtStatusToDosError(iVar1);
  if (0 < (int)(uint)uVar3) {
    uVar3 = (ulonglong)((uint)uVar3 & 0xffff | 0x80070000);
  }
  return uVar3;
}



===== Tbsip_Context_Close @ 180001ec0 =====

uint Tbsip_Context_Close(void *param_1)

{
  long lVar1;
  
                    /* 0x1ec0  19  Tbsip_Context_Close */
  lVar1 = TpmClose(param_1);
  return lVar1 >> 0x1f & 0x80284004;
}



===== TpmClose @ 180001ee0 =====

/* long __cdecl TpmClose(void * __ptr64) */

long __cdecl TpmClose(void *param_1)

{
  uint uVar1;
  BOOL BVar2;
  undefined4 uVar3;
  
  uVar1 = Feature_ReplaceNtCloseWithCloseHandle__private_IsEnabledDeviceUsageNoInline();
  if (uVar1 == 0) {
    uVar3 = NtClose(param_1);
    uVar1 = RtlNtStatusToDosError(uVar3);
  }
  else {
    BVar2 = CloseHandle(param_1);
    if (BVar2 != 0) {
      return 0;
    }
    uVar1 = GetLastError();
  }
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  return uVar1;
}



===== TbsGetLog @ 180001f50 =====

/* unsigned int __cdecl TbsGetLog(int,unsigned char * __ptr64,unsigned int,unsigned int * __ptr64)
    */

uint __cdecl TbsGetLog(int param_1,uchar *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  LPVOID pvVar3;
  uchar *puVar4;
  HANDLE pvVar5;
  wchar_t *pwVar6;
  uchar *puVar7;
  uint uVar8;
  uint uVar9;
  LPVOID pvVar10;
  uint local_res20 [2];
  longlong local_98 [2];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar8 = 0;
  local_64 = 0;
  local_4c = 0;
  local_98[0] = 0;
  local_res20[0] = 0;
  pvVar10 = (LPVOID)0x0;
  puVar7 = (uchar *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((param_4 == (uint *)0x0) || ((param_3 != 0 && (param_2 == (uchar *)0x0)))) {
    return 0x80284002;
  }
  *param_4 = 0;
  RtlInitUnicodeString
            (&local_78,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\IntegrityServices"
            );
  local_58 = &local_78;
  local_68 = 0x30;
  local_60 = 0;
  local_50 = 0x40;
  local_48 = 0;
  uStack_40 = 0;
  iVar2 = NtOpenKey(local_98,0x20019,&local_68);
  puVar4 = puVar7;
  pvVar3 = pvVar10;
  if (iVar2 < 0) {
    uVar8 = 0x80284001;
    goto LAB_18000226b;
  }
  pwVar6 = L"WBCLDrtm";
  if (param_1 == 0) {
    pwVar6 = L"WBCL";
  }
  RtlInitUnicodeString(&local_88,pwVar6);
  iVar2 = NtQueryValueKey(local_98[0],&local_88,2,0,0,local_res20);
  uVar9 = local_res20[0];
  if (iVar2 == -0x3fffffcc) {
    uVar8 = 0x80284011;
    goto LAB_18000226b;
  }
  if (iVar2 != -0x3fffffdd) {
    uVar8 = 0x80284001;
    goto LAB_18000226b;
  }
  pvVar5 = GetProcessHeap();
  pvVar3 = HeapAlloc(pvVar5,0,(ulonglong)uVar9);
  if (pvVar3 == (LPVOID)0x0) {
    uVar8 = 0x80070008;
    pvVar3 = pvVar10;
    goto LAB_18000226b;
  }
  iVar2 = NtQueryValueKey(local_98[0],&local_88,2,pvVar3,local_res20[0],local_res20);
  if (iVar2 < 0) {
    uVar8 = 0x80284001;
    goto LAB_18000226b;
  }
  if (*(int *)((longlong)pvVar3 + 4) != 3) {
    uVar8 = 0x80284011;
    goto LAB_18000226b;
  }
  uVar9 = *(uint *)((longlong)pvVar3 + 8);
  RtlInitUnicodeString(&local_88,L"WBCLTrustPoint");
  iVar2 = NtQueryValueKey(local_98[0],&local_88,2,0,0,local_res20);
  if (iVar2 == -0x3fffffdd) {
    puVar4 = TpmAlloc(local_res20[0]);
    if (puVar4 == (uchar *)0x0) {
      uVar8 = 0x80070008;
      puVar4 = puVar7;
      goto LAB_18000226b;
    }
    iVar2 = NtQueryValueKey(local_98[0],&local_88,2,puVar4,local_res20[0],local_res20);
    if (iVar2 < 0) {
      uVar8 = 0x80284001;
      goto LAB_18000226b;
    }
    if (*(int *)(puVar4 + 4) == 3) {
      uVar9 = uVar9 + *(int *)(puVar4 + 8);
    }
    else {
      pvVar5 = GetProcessHeap();
      HeapFree(pvVar5,0,puVar4);
      puVar4 = (uchar *)0x0;
      local_res20[0] = 0;
    }
  }
  if ((param_2 != (uchar *)0x0) && (param_3 != 0)) {
    uVar1 = *(uint *)((longlong)pvVar3 + 8);
    puVar7 = (uchar *)((longlong)pvVar3 + 0xc);
    if (param_3 < uVar9) {
      if (param_3 < uVar1) {
        uVar9 = param_3;
LAB_18000222d:
        memcpy(param_2,puVar7,(ulonglong)uVar9);
      }
      else {
        memcpy(param_2,puVar7,(ulonglong)uVar1);
        uVar8 = *(uint *)((longlong)pvVar3 + 8);
        if ((uVar8 < param_3) && (puVar4 != (uchar *)0x0)) {
          puVar7 = puVar4 + 0xc;
          uVar9 = param_3 - uVar8;
          param_2 = param_2 + uVar8;
          goto LAB_18000222d;
        }
      }
      *param_4 = param_3;
      uVar8 = 0x80284005;
      goto LAB_18000226b;
    }
    memcpy(param_2,puVar7,(ulonglong)uVar1);
    if (puVar4 != (uchar *)0x0) {
      memcpy(param_2 + *(uint *)((longlong)pvVar3 + 8),puVar4 + 0xc,(ulonglong)*(uint *)(puVar4 + 8)
            );
    }
  }
  *param_4 = uVar9;
LAB_18000226b:
  if (local_98[0] != 0) {
    NtClose();
  }
  if (puVar4 != (uchar *)0x0) {
    pvVar5 = GetProcessHeap();
    HeapFree(pvVar5,0,puVar4);
  }
  if (pvVar3 != (LPVOID)0x0) {
    pvVar5 = GetProcessHeap();
    HeapFree(pvVar5,0,pvVar3);
  }
  return uVar8;
}



===== GetDeviceIDString @ 1800022f0 =====

uint GetDeviceIDString(undefined2 *param_1,uint param_2,uint *param_3,undefined4 *param_4)

{
  uint uVar1;
  byte bVar2;
  DWORD DVar3;
  uint extraout_EAX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 *_Dst;
  ulonglong uVar7;
  uint uVar8;
  undefined4 *puVar9;
  byte bVar10;
  byte bVar11;
  DWORD local_res8 [2];
  undefined4 local_res18 [2];
  undefined4 *local_res20;
  
                    /* 0x22f0  4  GetDeviceIDString */
  local_res8[0] = 0;
  local_res18[0] = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  if (param_1 != (undefined2 *)0x0) {
    *param_1 = 0;
  }
  local_res20 = param_4;
  _Dst = operator_new__(0x40);
  if (_Dst == (undefined8 *)0x0) {
    return 0x80070008;
  }
  *_Dst = 0;
  _Dst[1] = 0;
  puVar9 = local_res18;
  _Dst[2] = 0;
  _Dst[3] = 0;
  if (param_4 == (undefined4 *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  _Dst[4] = 0;
  _Dst[5] = 0;
  _Dst[6] = 0;
  _Dst[7] = 0;
  GetDeviceIDWithTimeout(_Dst,0x40,local_res8,0,puVar9);
  uVar4 = extraout_EAX;
  if (extraout_EAX == 0x8007007a) {
    operator_delete__(_Dst);
    DVar3 = local_res8[0];
    uVar7 = (ulonglong)local_res8[0];
    _Dst = operator_new__(uVar7);
    if (_Dst == (undefined8 *)0x0) {
      return 0x80070008;
    }
    memset(_Dst,0,uVar7);
    uVar4 = GetDeviceID(_Dst,DVar3,local_res8,puVar9);
  }
  if ((int)uVar4 < 0) goto LAB_1800025a2;
  uVar4 = 0;
  uVar5 = ((local_res8[0] + 2) / 3) * 4 + 1;
  if (param_2 < uVar5) {
    if ((param_1 != (undefined2 *)0x0) && (uVar4 = 0, param_2 != 0)) {
      uVar4 = 0xc0000023;
    }
    if (uVar4 == 0) goto LAB_180002580;
LAB_180002565:
    uVar4 = uVar4 | 0x10000000;
    if (uVar4 == 0xd0000023) {
      uVar4 = 0x8007007a;
    }
  }
  else {
    uVar4 = 0;
    if (local_res8[0] != 0) {
      uVar8 = 2;
      uVar6 = 2;
      do {
        if (param_2 - 4 < uVar4) break;
        bVar2 = *(byte *)((ulonglong)(uVar6 - 2) + (longlong)_Dst);
        if (uVar6 - 1 < local_res8[0]) {
          bVar10 = *(byte *)((ulonglong)(uVar6 - 1) + (longlong)_Dst);
        }
        else {
          bVar10 = 0;
        }
        if (uVar6 < local_res8[0]) {
          bVar11 = *(byte *)((ulonglong)uVar6 + (longlong)_Dst);
        }
        else {
          bVar11 = 0;
        }
        uVar7 = (ulonglong)uVar4;
        uVar4 = uVar4 + 4;
        param_1[uVar7] = *(undefined2 *)(&DAT_180011210 + (ulonglong)(bVar2 >> 2) * 2);
        param_1[uVar8 - 1] =
             *(undefined2 *)(&DAT_180011210 + (ulonglong)(byte)((bVar2 & 3) << 4 | bVar10 >> 4) * 2)
        ;
        param_1[uVar8] =
             *(undefined2 *)
              (&DAT_180011210 + (ulonglong)(byte)((bVar10 & 0xf) << 2 | bVar11 >> 6) * 2);
        uVar1 = uVar8 + 1;
        uVar8 = uVar8 + 4;
        param_1[uVar1] = *(undefined2 *)(&DAT_180011210 + (ulonglong)(bVar11 & 0x3f) * 2);
        uVar1 = uVar6 + 1;
        uVar6 = uVar6 + 3;
      } while (uVar1 < local_res8[0]);
      param_4 = local_res20;
    }
    if (local_res8[0] % 3 == 1) {
      param_1[uVar4 - 2] = 0x3d;
LAB_18000254e:
      param_1[uVar4 - 1] = 0x3d;
    }
    else if (local_res8[0] % 3 == 2) goto LAB_18000254e;
    if (param_2 <= uVar4) {
      uVar4 = 0xc0000023;
      goto LAB_180002565;
    }
    param_1[uVar4] = 0;
LAB_180002580:
    uVar4 = 0;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar5;
  }
  local_res8[0] = uVar5;
  if ((-1 < (int)uVar4) && (param_4 != (undefined4 *)0x0)) {
    *param_4 = local_res18[0];
  }
LAB_1800025a2:
  operator_delete__(_Dst);
  return uVar4;
}



===== GetDeviceIDWithTimeout @ 1800025d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint GetDeviceIDWithTimeout
               (void *param_1,DWORD param_2,DWORD *param_3,ulonglong param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  DWORD DVar3;
  int iVar4;
  ULONGLONG UVar5;
  ulonglong uVar6;
  int *_Dst;
  int *_Buf2;
  uint uVar7;
  ulonglong uVar8;
  uint unaff_EDI;
  undefined1 auStackY_2f8 [32];
  DWORD local_2b8;
  uint local_2b4;
  DWORD local_2b0 [2];
  HANDLE local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  longlong local_298;
  undefined4 local_290;
  undefined4 *local_288;
  DWORD local_280 [6];
  WCHAR local_268 [264];
  ulonglong local_58;
  
                    /* 0x25d0  5  GetDeviceIDWithTimeout */
  local_58 = __security_cookie ^ (ulonglong)auStackY_2f8;
  local_288 = param_5;
  local_2a0 = 0;
  local_29c = 0;
  local_2a8 = (HANDLE)0x0;
  local_298 = 0;
  local_2b8 = 0;
  local_2b0[0] = 0;
  _Buf2 = (int *)0x0;
  memset(local_268,0,0x208);
  local_290 = 0x208;
  if (param_3 == (DWORD *)0x0) {
    return unaff_EDI;
  }
  *param_3 = 0;
  uVar2 = RtlGetPersistedStateLocation
                    (L"TpmRegDriverPersistedData",0,L"System\\CurrentControlSet\\Services\\TPM\\WMI"
                     ,0);
  if (0 < (int)uVar2) {
    uVar2 = uVar2 & 0xffff | 0x80070000;
  }
  if ((int)uVar2 < 0) goto LAB_180002cc4;
  local_2b8 = param_2;
  uVar2 = RegGetValueW((HKEY)0xffffffff80000002,local_268,L"WindowsAIKHash",8,(LPDWORD)0x0,param_1,
                       &local_2b8);
  if (0 < (int)uVar2) {
    uVar2 = uVar2 & 0xffff | 0x80070000;
  }
  if (uVar2 == 0x800700ea) {
    *param_3 = local_2b8;
    goto LAB_180002cc4;
  }
  if ((int)uVar2 < 0) {
    uVar2 = RtlQueryWnfStateData(&local_29c,0x418b1e39a3bc1075,WnfDeviceIDCallback,0);
    if (uVar2 == 0) {
LAB_180002790:
      if (DAT_180015bc8 != 2) goto LAB_18000279d;
    }
    else {
      if ((uVar2 & 0xffff000) == 0x290000) {
        uVar7 = uVar2 & 0xfff | 0x80280000;
      }
      else if ((uVar2 & 0xfff0000) == 0x70000) {
        uVar7 = 0;
        if ((uVar2 & 0xffff) != 0) {
          uVar7 = uVar2 & 0xffff | 0x80070000;
        }
      }
      else {
        uVar7 = uVar2 | 0x10000000;
      }
      if (-1 < (int)uVar7) goto LAB_180002790;
LAB_18000279d:
      local_2a0 = 2;
      uVar2 = RtlPublishWnfStateData(0x418b1e39a3bc1075,0,&local_2a0,4);
      if (uVar2 != 0) {
        if ((uVar2 & 0xffff000) == 0x290000) {
          uVar7 = uVar2 & 0xfff | 0x80280000;
        }
        else if ((uVar2 & 0xfff0000) == 0x70000) {
          uVar7 = 0;
          if ((uVar2 & 0xffff) != 0) {
            uVar7 = uVar2 & 0xffff | 0x80070000;
          }
        }
        else {
          uVar7 = uVar2 | 0x10000000;
        }
        if ((int)uVar7 < 0) goto LAB_180002cc4;
      }
      McGenEventRegister_EventRegister();
      if ((Microsoft_Windows_TPM_WMIEnableBits & 1) != 0) {
        McGenEventWrite_EventWriteTransfer();
      }
      McGenEventUnregister_EventUnregister();
    }
    local_2a8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (local_2a8 == (HANDLE)0x0) goto LAB_180002cc4;
    local_2b4 = RtlSubscribeWnfStateChangeNotification
                          (&local_298,0x418b1e39a3bc1075,local_29c,WnfDeviceIDCallback);
    if (local_2b4 == 0) {
      local_2b4 = 0;
    }
    else if ((local_2b4 & 0xffff000) == 0x290000) {
      local_2b4 = local_2b4 & 0xfff | 0x80280000;
    }
    else if ((local_2b4 & 0xfff0000) == 0x70000) {
      local_2b4 = local_2b4 & 0xffff;
      if (local_2b4 != 0) {
        local_2b4 = local_2b4 | 0x80070000;
      }
    }
    else {
      local_2b4 = local_2b4 | 0x10000000;
    }
    uVar2 = local_2b4;
    UVar5 = GetTickCount64();
    uVar6 = UVar5 + (param_4 & 0xffffffff);
    while (UVar5 = GetTickCount64(), UVar5 < uVar6) {
      uVar8 = uVar6 - UVar5;
      if (((int)uVar2 < 0) && (200 < uVar8)) {
        uVar8 = 200;
      }
      DVar3 = WaitForSingleObject(local_2a8,(DWORD)uVar8);
      local_2b8 = param_2;
      uVar2 = RegGetValueW((HKEY)0xffffffff80000002,local_268,L"WindowsAIKHash",8,(LPDWORD)0x0,
                           param_1,&local_2b8);
      if (0 < (int)uVar2) {
        uVar2 = uVar2 & 0xffff | 0x80070000;
      }
      if (-1 < (int)uVar2) break;
      if (DVar3 != 0x102) {
        if (DVar3 != 0) {
          if (0 < (int)DVar3) {
            DVar3 = DVar3 & 0xffff | 0x80070000;
          }
          if ((int)DVar3 < 0) goto LAB_180002cc4;
        }
        break;
      }
      uVar2 = local_2b4;
    }
    if (local_298 != 0) {
      RtlUnsubscribeWnfStateChangeNotification();
      local_298 = 0;
    }
    CloseHandle(local_2a8);
    local_2a8 = (HANDLE)0x0;
    local_2b8 = param_2;
    uVar2 = RegGetValueW((HKEY)0xffffffff80000002,local_268,L"WindowsAIKHash",8,(LPDWORD)0x0,param_1
                         ,&local_2b8);
    if (0 < (int)uVar2) {
      uVar2 = uVar2 & 0xffff | 0x80070000;
    }
    if (uVar2 == 0x800700ea) {
      *param_3 = local_2b8;
      goto LAB_180002cc4;
    }
  }
  puVar1 = local_288;
  *param_3 = local_2b8;
  if ((((int)uVar2 < 0) || (param_1 == (void *)0x0)) || (local_288 == (undefined4 *)0x0))
  goto LAB_180002cc4;
  *local_288 = 0;
  uVar2 = RegGetValueW((HKEY)0xffffffff80000002,local_268,L"WindowsAIKPub",8,(LPDWORD)0x0,(PVOID)0x0
                       ,local_2b0);
  if (0 < (int)uVar2) {
    uVar2 = uVar2 & 0xffff | 0x80070000;
  }
  if (uVar2 == 0x80070002) {
    local_2b4 = 0;
    local_280[0] = 4;
    uVar2 = RegGetValueW((HKEY)0xffffffff80000002,local_268,L"TpmBackedDeviceID",0x10,(LPDWORD)0x0,
                         &local_2b4,local_280);
    if (0 < (int)uVar2) {
      uVar2 = uVar2 & 0xffff | 0x80070000;
    }
    if ((-1 < (int)uVar2) && (local_2b4 != 0)) {
      *puVar1 = 1;
    }
    goto LAB_180002cc4;
  }
  if (((int)uVar2 < 0) || (_Dst = operator_new__((ulonglong)local_2b0[0]), _Dst == (int *)0x0))
  goto LAB_180002cc4;
  memset(_Dst,0,(ulonglong)local_2b0[0]);
  uVar2 = RegGetValueW((HKEY)0xffffffff80000002,local_268,L"WindowsAIKPub",8,(LPDWORD)0x0,_Dst,
                       local_2b0);
  if (0 < (int)uVar2) {
    uVar2 = uVar2 & 0xffff | 0x80070000;
  }
  if ((int)uVar2 < 0) {
LAB_180002caf:
    operator_delete__(_Dst);
    _Dst = _Buf2;
    if (_Buf2 == (int *)0x0) goto LAB_180002cc4;
  }
  else if (((*_Dst == 0x31415352) && (_Dst[3] != 0)) &&
          (_Buf2 = operator_new__(0x20), _Buf2 != (int *)0x0)) {
    _Buf2[0] = 0;
    _Buf2[1] = 0;
    _Buf2[2] = 0;
    _Buf2[3] = 0;
    _Buf2[4] = 0;
    _Buf2[5] = 0;
    _Buf2[6] = 0;
    _Buf2[7] = 0;
    uVar2 = Tbsi_ShaHash(L"SHA256",(PUCHAR)0x0,0,
                         (PUCHAR)((ulonglong)(uint)_Dst[2] + 0x18 + (longlong)_Dst),_Dst[3],
                         (PUCHAR)_Buf2,0x20,local_280);
    if (uVar2 != 0) {
      if ((uVar2 & 0xffff000) == 0x290000) {
        uVar7 = uVar2 & 0xfff | 0x80280000;
      }
      else if ((uVar2 & 0xfff0000) == 0x70000) {
        uVar7 = 0;
        if ((uVar2 & 0xffff) != 0) {
          uVar7 = uVar2 & 0xffff | 0x80070000;
        }
      }
      else {
        uVar7 = uVar2 | 0x10000000;
      }
      if ((int)uVar7 < 0) goto LAB_180002caf;
    }
    if ((local_2b8 != 0x20) || (iVar4 = memcmp(param_1,_Buf2,0x20), iVar4 != 0)) goto LAB_180002caf;
    *puVar1 = 1;
    operator_delete__(_Dst);
    _Dst = _Buf2;
  }
  operator_delete__(_Dst);
LAB_180002cc4:
  if (local_298 != 0) {
    RtlUnsubscribeWnfStateChangeNotification();
  }
  if (local_2a8 != (HANDLE)0x0) {
    CloseHandle(local_2a8);
  }
  return unaff_EDI;
}



===== _tlgEnableCallback @ 180002d30 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        *(undefined8 *)(param_7 + 4) = param_4;
        *param_7 = 0x100;
        *(undefined8 *)(param_7 + 6) = param_5;
      }
      else {
        *(undefined8 *)(param_7 + 4) = param_4;
        *param_7 = param_3 + 1;
        *(undefined8 *)(param_7 + 6) = param_5;
      }
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== TraceLoggingRegisterEx_EventRegister_EventSetInformation @ 180002dd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ULONG TraceLoggingRegisterEx_EventRegister_EventSetInformation(PVOID param_1)

{
  undefined2 uVar1;
  longlong lVar2;
  undefined2 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  ULONG UVar6;
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
  lVar2 = *(longlong *)((longlong)param_1 + 8);
  local_28 = *(undefined4 *)(lVar2 + -0x10);
  uStack_24 = *(undefined4 *)(lVar2 + -0xc);
  uStack_20 = *(undefined4 *)(lVar2 + -8);
  uStack_1c = *(undefined4 *)(lVar2 + -4);
  if (*(longlong *)((longlong)param_1 + 0x20) != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)((longlong)param_1 + 0x28) = 0;
  *(undefined8 *)((longlong)param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x180002e30;
  UVar6 = EventRegister((LPCGUID)(puVar7 + 0x20),_tlgEnableCallback,param_1,
                        (PREGHANDLE)((longlong)param_1 + 0x20));
  if (UVar6 == 0) {
    puVar3 = *(undefined2 **)((longlong)param_1 + 8);
    uVar4 = *(undefined8 *)((longlong)param_1 + 0x20);
    uVar1 = *puVar3;
    *(undefined8 *)(puVar7 + -8) = 0x180002e61;
    EventSetInformation(uVar4,2,puVar3,uVar1);
  }
  else if (0 < (int)UVar6) {
    UVar6 = UVar6 & 0xffff | 0x80070000;
  }
  *(undefined8 *)(puVar7 + -8) = 0x180002e75;
  return UVar6;
}



===== TpmAlloc @ 180002e90 =====

/* unsigned char * __ptr64 __cdecl TpmAlloc(unsigned long) */

uchar * __cdecl TpmAlloc(ulong param_1)

{
  HANDLE hHeap;
  uchar *puVar1;
  
  hHeap = GetProcessHeap();
                    /* WARNING: Could not recover jumptable at 0x000180002eb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = HeapAlloc(hHeap,0,(ulonglong)param_1);
  return puVar1;
}



===== ~FeatureStateManager @ 180002ec4 =====

/* public: __cdecl wil::details::FeatureStateManager::~FeatureStateManager(void) __ptr64 */

void __thiscall wil::details::FeatureStateManager::~FeatureStateManager(FeatureStateManager *this)

{
  _TP_TIMER *p_Var1;
  void *pvVar2;
  last_error_context local_res8 [8];
  
  *this = (FeatureStateManager)0x0;
  p_Var1 = *(_TP_TIMER **)(this + 0x30);
  if (p_Var1 != (_TP_TIMER *)0x0) {
    last_error_context::last_error_context(local_res8);
    DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy(p_Var1);
    last_error_context::~last_error_context(local_res8);
  }
  *(undefined8 *)(this + 0x30) = 0;
  p_Var1 = *(_TP_TIMER **)(this + 0x38);
  if (p_Var1 != (_TP_TIMER *)0x0) {
    last_error_context::last_error_context(local_res8);
    DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy(p_Var1);
    last_error_context::~last_error_context(local_res8);
  }
  *(undefined8 *)(this + 0x38) = 0;
  pvVar2 = *(void **)(this + 0x100);
  *(undefined8 *)(this + 0x100) = 0;
  if (pvVar2 != (void *)0x0) {
    FreeProcessHeap(pvVar2);
  }
  if (*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)(this + 0xe0) !=
      (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
    UnsubscribeProcessWideUsageFlush(*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)(this + 0xe0));
  }
  details_abi::SubscriptionList::~SubscriptionList((SubscriptionList *)(this + 0x98));
  if (*(longlong *)(this + 0x90) != 0) {
    wil_details_RtlUnregisterFeatureConfigurationChangeNotification(*(longlong *)(this + 0x90));
  }
  details_abi::SubscriptionList::~SubscriptionList((SubscriptionList *)(this + 0x48));
  if (*(_TP_TIMER **)(this + 0x38) != (_TP_TIMER *)0x0) {
    DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy
              (*(_TP_TIMER **)(this + 0x38));
  }
  if (*(_TP_TIMER **)(this + 0x30) != (_TP_TIMER *)0x0) {
    DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy
              (*(_TP_TIMER **)(this + 0x30));
  }
  if (*(ProcessLocalStorageData<wil::details_abi::FeatureStateData> **)(this + 0x10) !=
      (ProcessLocalStorageData<wil::details_abi::FeatureStateData> *)0x0) {
    details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Release
              (*(ProcessLocalStorageData<wil::details_abi::FeatureStateData> **)(this + 0x10));
  }
  return;
}



===== Tbsi_Physical_Presence_Command @ 180002fc0 =====

uint Tbsi_Physical_Presence_Command
               (undefined8 param_1,longlong param_2,uint param_3,longlong param_4,uint *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  
                    /* 0x2fc0  14  Tbsi_Physical_Presence_Command */
  if (param_2 == 0) {
    return 0x80284002;
  }
  if ((param_4 == 0) || (param_5 == (uint *)0x0)) {
    uVar1 = 0x80284003;
  }
  else if ((param_3 < 0x40001) && (*param_5 < 0x40001)) {
    uVar2 = TpmDeviceIoControl(param_1,0x22c014,param_2,param_3,param_4,param_5);
    uVar1 = (uint)uVar2;
    if (uVar1 == 0x80070006) {
      uVar1 = 0x80284004;
    }
    uVar1 = TbsRemapError(uVar1,0x5a9);
  }
  else {
    uVar1 = 0x8028400e;
  }
  return uVar1;
}



===== Tbsi_Get_TCG_Log_Ex @ 180003050 =====

uint Tbsi_Get_TCG_Log_Ex(int param_1,uchar *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x3050  12  Tbsi_Get_TCG_Log_Ex */
  if (param_3 == (uint *)0x0) {
    return 0x80284002;
  }
  uVar1 = Tbsi_Is_Tpm_Present();
  if (uVar1 == 0) {
    return 0x8028400f;
  }
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    if (param_1 != 1) {
      if (param_1 == 2) {
        iVar2 = 0;
LAB_1800030bf:
        uVar1 = TbsGetLastCleanBootLog(iVar2,param_2,param_3);
        return uVar1;
      }
      if (param_1 == 3) {
        iVar2 = 0;
      }
      else {
        if (param_1 == 4) {
          iVar2 = 1;
          goto LAB_1800030bf;
        }
        if (param_1 != 5) {
          return 0x80284002;
        }
        iVar2 = 1;
      }
      uVar1 = TbsGetCurrentLogIfResumed(iVar2,param_2,*param_3,param_3);
      return uVar1;
    }
    iVar2 = 1;
  }
  uVar1 = TbsGetCurrentLog(iVar2,param_2,*param_3,param_3);
  return uVar1;
}



===== ~ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> @ 180003100 =====

/* public: __cdecl wil::details_abi::ThreadLocalStorage<class
   wil::details::ThreadFailureCallbackHolder * __ptr64>::~ThreadLocalStorage<class
   wil::details::ThreadFailureCallbackHolder * __ptr64>(void) __ptr64 */

void __thiscall
wil::details_abi::ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>::
~ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>
          (ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *this)

{
  ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *pTVar1;
  LPVOID pvVar2;
  LPVOID lpMem;
  HANDLE hHeap;
  
  pTVar1 = this + 0x50;
  for (; this != pTVar1; this = this + 8) {
    lpMem = *(LPVOID *)this;
    while (lpMem != (LPVOID)0x0) {
      pvVar2 = *(LPVOID *)((longlong)lpMem + 8);
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,lpMem);
      lpMem = pvVar2;
    }
    *(undefined8 *)this = 0;
  }
  return;
}



===== reset @ 180003180 =====

/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _TP_TIMER * __ptr64,void (__cdecl*)(struct _TP_TIMER * __ptr64),&public: static void __cdecl
   wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct _TP_TIMER * __ptr64,struct _TP_TIMER *
   __ptr64,0,std::nullptr_t> >::reset(struct _TP_TIMER * __ptr64) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
        *this,_TP_TIMER *param_1)

{
  _TP_TIMER *p_Var1;
  DWORD dwErrCode;
  
  p_Var1 = *(_TP_TIMER **)this;
  if (p_Var1 == (_TP_TIMER *)0x0) {
    *(_TP_TIMER **)this = param_1;
  }
  else {
    dwErrCode = GetLastError();
    DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy(p_Var1);
    SetLastError(dwErrCode);
    *(_TP_TIMER **)this = param_1;
  }
  return;
}



===== wil_details_GetNtDllModuleHandle @ 1800031ec =====

/* struct HINSTANCE__ * __ptr64 __cdecl wil_details_GetNtDllModuleHandle(void) */

HINSTANCE__ * __cdecl wil_details_GetNtDllModuleHandle(void)

{
  if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
      wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
    `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
    wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
  }
  return `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
         wil_details_ntdllModuleHandle;
}



===== RtlDllShutdownInProgress @ 180003230 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* unsigned char __cdecl wil::details::RtlDllShutdownInProgress(void) */

uchar __cdecl wil::details::RtlDllShutdownInProgress(void)

{
  uchar uVar1;
  
  if ((`unsigned_char___cdecl_wil::details::RtlDllShutdownInProgress(void)'::__l2::
       s_pfnRtlDllShutdownInProgress == (_func_uchar *)0x0) &&
     (`unsigned_char___cdecl_wil::details::RtlDllShutdownInProgress(void)'::__l2::
      s_pfnRtlDllShutdownInProgress =
           (_func_uchar *)wil_details_GetNtDllProcedureAddress("RtlDllShutdownInProgress"),
     (_func___int64 *)
     `unsigned_char___cdecl_wil::details::RtlDllShutdownInProgress(void)'::__l2::
     s_pfnRtlDllShutdownInProgress == (_func___int64 *)0x0)) {
    return '\0';
  }
  uVar1 = (*`unsigned_char___cdecl_wil::details::RtlDllShutdownInProgress(void)'::__l2::
            s_pfnRtlDllShutdownInProgress)();
  return uVar1;
}



===== Tbsi_Context_Create @ 180003280 =====

void Tbsi_Context_Create(tdTBS_CONTEXT_PARAMS *param_1,void **param_2)

{
                    /* 0x3280  6  Tbsi_Context_Create */
  Tbsi_Context_Create_Ex(param_1,param_2,0);
  return;
}



===== DllMain @ 180003290 =====

undefined8 DllMain(HMODULE param_1,int param_2)

{
  REGHANDLE RVar1;
  bool bVar2;
  
  RVar1 = DAT_1800150a0;
  if (param_2 == 0) {
    DAT_1800150a0 = 0;
    DAT_180015080 = 0;
    EventUnregister(RVar1);
    bVar2 = wil::details::FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa>::
            __private_IsEnabled((FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa> *)
                                &`private:_static_class_wil::details::FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa>&___ptr64___cdecl_wil::Feature<__WilFeatureTraits_Feature_TpmMissingLogsMaa>::GetImpl(void)'
                                 ::__l2::impl);
    RVar1 = DAT_180015068;
    if (bVar2) {
      DAT_180015068 = 0;
      DAT_180015048 = 0;
      EventUnregister(RVar1);
    }
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    TraceLoggingRegisterEx_EventRegister_EventSetInformation(&DAT_180015080);
    bVar2 = wil::details::FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa>::
            __private_IsEnabled((FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa> *)
                                &`private:_static_class_wil::details::FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa>&___ptr64___cdecl_wil::Feature<__WilFeatureTraits_Feature_TpmMissingLogsMaa>::GetImpl(void)'
                                 ::__l2::impl);
    if (bVar2) {
      TraceLoggingRegisterEx_EventRegister_EventSetInformation(&DAT_180015048);
    }
  }
  return 1;
}



===== ~EnabledStateManager @ 180003340 =====

/* public: __cdecl wil::details::EnabledStateManager::~EnabledStateManager(void) __ptr64 */

void __thiscall wil::details::EnabledStateManager::~EnabledStateManager(EnabledStateManager *this)

{
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  *this_00;
  _TP_TIMER *p_Var1;
  void *pvVar2;
  last_error_context local_res8 [8];
  
  this_00 = (unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
             *)(this + 0x10);
  *this = (EnabledStateManager)0x0;
  p_Var1 = *(_TP_TIMER **)this_00;
  if (p_Var1 != (_TP_TIMER *)0x0) {
    last_error_context::last_error_context(local_res8);
    DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy(p_Var1);
    last_error_context::~last_error_context(local_res8);
  }
  *(undefined8 *)this_00 = 0;
  *this = (EnabledStateManager)0x0;
  RecordCachedUsageUnderLock(this);
  pvVar2 = *(void **)(this + 0x68);
  *(undefined8 *)(this + 0x68) = 0;
  if (pvVar2 != (void *)0x0) {
    FreeProcessHeap(pvVar2);
  }
  pvVar2 = *(void **)(this + 0x48);
  *(undefined8 *)(this + 0x48) = 0;
  if (pvVar2 != (void *)0x0) {
    FreeProcessHeap(pvVar2);
  }
  unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
              *)(this + 0x28));
  unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
              *)(this + 0x20));
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
            (this_00);
  return;
}



===== RecordCachedUsageUnderLock @ 1800033e4 =====

/* private: void __cdecl wil::details::EnabledStateManager::RecordCachedUsageUnderLock(void) __ptr64
    */

void __thiscall
wil::details::EnabledStateManager::RecordCachedUsageUnderLock(EnabledStateManager *this)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char *in_R9;
  
  puVar1 = *(undefined4 **)(this + 0x38);
  puVar2 = *(undefined4 **)(this + 0x30);
  if (0xf < (ulonglong)((longlong)puVar1 - (longlong)puVar2)) {
    for (; puVar2 != puVar1; puVar2 = puVar2 + 4) {
      wil_details_RecordCachedUsage(*puVar2,*(uint **)(puVar2 + 2));
    }
    *(undefined8 *)(this + 0x38) = *(undefined8 *)(this + 0x30);
    WilApi_RecordFeatureUsage(0,0xfe,0,in_R9);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_> @ 180003450 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,void (__cdecl*)(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64),&void __cdecl
   wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,0,std::nullptr_t> >::~unique_storage<struct
   wil::details::resource_policy<struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,void
   (__cdecl*)(struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64),&void __cdecl
   wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)this != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
    WilApi_UnsubscribeFeatureStateChangeNotification(*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)this);
  }
  return;
}



===== ProcessShutdownInProgress @ 180003470 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* bool __cdecl wil::ProcessShutdownInProgress(void) */

bool __cdecl wil::ProcessShutdownInProgress(void)

{
  uchar uVar1;
  
  if (!details::g_processShutdownInProgress) {
    if (details::g_pfnDllShutdownInProgress == (_func_uchar *)0x0) {
      return false;
    }
    uVar1 = (*details::g_pfnDllShutdownInProgress)();
    if (uVar1 == '\0') {
      return false;
    }
  }
  return true;
}



===== SubscriptionList @ 1800034a8 =====

/* public: __cdecl wil::details_abi::SubscriptionList::SubscriptionList(void) __ptr64 */

SubscriptionList * __thiscall
wil::details_abi::SubscriptionList::SubscriptionList(SubscriptionList *this)

{
  InitializeCriticalSectionEx((LPCRITICAL_SECTION)this,0,0);
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  return this;
}



===== ~ProcessLocalStorage<wil::details_abi::FeatureStateData> @ 1800034e4 =====

/* public: __cdecl wil::details_abi::ProcessLocalStorage<class
   wil::details_abi::FeatureStateData>::~ProcessLocalStorage<class
   wil::details_abi::FeatureStateData>(void) __ptr64 */

void __thiscall
wil::details_abi::ProcessLocalStorage<wil::details_abi::FeatureStateData>::
~ProcessLocalStorage<wil::details_abi::FeatureStateData>
          (ProcessLocalStorage<wil::details_abi::FeatureStateData> *this)

{
  if (*(ProcessLocalStorageData<wil::details_abi::FeatureStateData> **)(this + 8) !=
      (ProcessLocalStorageData<wil::details_abi::FeatureStateData> *)0x0) {
    ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Release
              (*(ProcessLocalStorageData<wil::details_abi::FeatureStateData> **)(this + 8));
  }
  return;
}



===== GetDeviceID @ 180003510 =====

void GetDeviceID(void *param_1,DWORD param_2,DWORD *param_3,undefined4 *param_4)

{
                    /* 0x3510  3  GetDeviceID */
  GetDeviceIDWithTimeout(param_1,param_2,param_3,0,param_4);
  return;
}



===== ~SubscriptionList @ 180003530 =====

/* public: __cdecl wil::details_abi::SubscriptionList::~SubscriptionList(void) __ptr64 */

void __thiscall wil::details_abi::SubscriptionList::~SubscriptionList(SubscriptionList *this)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(this + 0x40);
  *(undefined8 *)(this + 0x40) = 0;
  if (pvVar1 != (void *)0x0) {
    details::FreeProcessHeap(pvVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x000180003554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteCriticalSection(this);
  return;
}



===== ~unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_> @ 180003568 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _TP_TIMER * __ptr64,void (__cdecl*)(struct _TP_TIMER * __ptr64),&public: static void __cdecl
   wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct _TP_TIMER * __ptr64,struct _TP_TIMER *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<struct
   _TP_TIMER * __ptr64,void (__cdecl*)(struct _TP_TIMER * __ptr64),&public: static void __cdecl
   wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct _TP_TIMER * __ptr64,struct _TP_TIMER *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(_TP_TIMER **)this != (_TP_TIMER *)0x0) {
    DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy(*(_TP_TIMER **)this);
  }
  return;
}



===== operator_new[] @ 180003588 =====

/* void * __ptr64 __cdecl operator new[](unsigned __int64) */

void * __cdecl operator_new__(__uint64 param_1)

{
  int iVar1;
  void *pvVar2;
  
  do {
    pvVar2 = (void *)malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    iVar1 = _callnewh(param_1);
  } while (iVar1 != 0);
  return (void *)0x0;
}



===== operator_delete[] @ 180003594 =====

/* void __cdecl operator delete[](void * __ptr64) */

void __cdecl operator_delete__(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_free();
  return;
}



===== operator_new @ 1800035a0 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1)

{
  int iVar1;
  void *pvVar2;
  
  do {
    pvVar2 = (void *)malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    iVar1 = _callnewh(param_1);
  } while (iVar1 != 0);
  return (void *)0x0;
}



===== operator_delete @ 1800035e0 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_free();
  return;
}



===== initialize_legacy_wide_specifiers @ 1800035f0 =====

undefined8 initialize_legacy_wide_specifiers(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 4;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return 0;
}



===== __local_stdio_printf_options @ 180003614 =====

__uint64 * __local_stdio_printf_options(void)

{
  return &`__local_stdio_printf_options'::__l2::_OptionsStorage;
}



===== __local_stdio_scanf_options @ 180003624 =====

__uint64 * __local_stdio_scanf_options(void)

{
  return &`__local_stdio_scanf_options'::__l2::_OptionsStorage;
}



===== initialize_msvcrt_compatibility @ 180003640 =====

undefined8 initialize_msvcrt_compatibility(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x18;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 4;
  return 0;
}



===== dllmain_crt_dispatch @ 180003670 =====

ulonglong dllmain_crt_dispatch(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    uVar2 = dllmain_crt_process_detach(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,uVar2);
  }
  if (param_2 == 1) {
    uVar3 = dllmain_crt_process_attach(param_1,param_3);
    return uVar3;
  }
  if (param_2 == 2) {
    bVar1 = __scrt_dllmain_crt_thread_attach();
  }
  else {
    if (param_2 != 3) {
      return 1;
    }
    bVar1 = __scrt_dllmain_crt_thread_detach();
  }
  return (ulonglong)bVar1;
}



===== dllmain_crt_process_attach @ 1800036c8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 dllmain_crt_process_attach(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  
  lVar4 = __scrt_initialize_crt(0);
  if ((char)lVar4 != '\0') {
    uVar5 = __scrt_acquire_startup_lock();
    bVar1 = true;
    if (__scrt_current_native_startup_state != 0) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(7);
    }
    __scrt_current_native_startup_state = 1;
    bVar2 = __scrt_dllmain_before_initialize_c();
    if (bVar2) {
      _RTC_Initialize();
      __scrt_initialize_type_info();
      __scrt_initialize_default_local_stdio_options();
      iVar3 = _initterm_e(&__xi_a,&__xi_z);
      if ((iVar3 == 0) && (uVar6 = __scrt_dllmain_after_initialize_c(), (char)uVar6 != '\0')) {
        _initterm(&__xc_a,&__xc_z);
        __scrt_current_native_startup_state = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar5);
    if (!bVar1) {
      plVar7 = (longlong *)__scrt_get_dyn_tls_init_callback();
      if ((*plVar7 != 0) &&
         (uVar8 = __scrt_is_nonwritable_in_current_image((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)*plVar7)(param_1,2,param_2);
      }
      DAT_180015390 = DAT_180015390 + 1;
      return 1;
    }
  }
  return 0;
}



===== dllmain_crt_process_detach @ 1800037e0 =====

undefined1 dllmain_crt_process_detach(undefined8 param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined7 uVar3;
  
  uVar1 = (undefined1)param_1;
  if (DAT_180015390 < 1) {
    uVar1 = 0;
  }
  else {
    DAT_180015390 = DAT_180015390 + -1;
    uVar2 = __scrt_acquire_startup_lock();
    if (__scrt_current_native_startup_state != 2) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(7);
    }
    __scrt_dllmain_uninitialize_c();
    __scrt_uninitialize_type_info();
    _RTC_Terminate();
    __scrt_current_native_startup_state = 0;
    uVar3 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar2);
    uVar1 = __scrt_uninitialize_crt(CONCAT71(uVar3,uVar1),'\0');
    __scrt_dllmain_uninitialize_critical();
  }
  return uVar1;
}



===== dllmain_dispatch @ 180003868 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00018000392b) */
/* WARNING: Removing unreachable block (ram,0x0001800038bb) */
/* WARNING: Removing unreachable block (ram,0x00018000396d) */

ulonglong dllmain_dispatch(HMODULE param_1,int param_2,longlong param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if ((param_2 == 0) && (DAT_180015390 < 1)) {
    return 0;
  }
  if (param_2 - 1U < 2) {
    uVar1 = dllmain_crt_dispatch(param_1,param_2,param_3);
    if ((int)uVar1 == 0) {
      return uVar1 & 0xffffffff;
    }
  }
  uVar1 = DllMain(param_1,param_2);
  uVar2 = uVar1 & 0xffffffff;
  if ((param_2 == 1) && ((int)uVar1 == 0)) {
    DllMain(param_1,0);
    dllmain_crt_dispatch(param_1,0,param_3);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    uVar1 = dllmain_crt_dispatch(param_1,param_2,param_3);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== entry @ 1800039a0 =====

void entry(HMODULE param_1,int param_2,longlong param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}



===== __security_check_cookie @ 1800039f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __scrt_acquire_startup_lock @ 180003a14 =====

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  void *pvVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  pvVar2 = (void *)CONCAT71(extraout_var,bVar1);
  if ((int)pvVar2 == 0) {
LAB_180003a42:
    uVar3 = (ulonglong)pvVar2 & 0xffffffffffffff00;
  }
  else {
    do {
      pvVar2 = (void *)0x0;
      LOCK();
      bVar1 = __scrt_native_startup_lock == (void *)0x0;
      if (bVar1) {
        __scrt_native_startup_lock = StackBase;
      }
      else {
        pvVar2 = __scrt_native_startup_lock;
      }
      UNLOCK();
      if (bVar1) goto LAB_180003a42;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



===== __scrt_dllmain_after_initialize_c @ 180003a54 =====

undefined8 __scrt_dllmain_after_initialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar3 = _get_startup_argv_mode();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _o__initialize_narrow_environment();
  }
  else {
    uVar2 = __isa_available_init();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== __scrt_dllmain_before_initialize_c @ 180003a90 =====

bool __scrt_dllmain_before_initialize_c(void)

{
  undefined8 uVar1;
  
  uVar1 = __scrt_initialize_onexit_tables(0);
  return (char)uVar1 != '\0';
}



===== __scrt_dllmain_crt_thread_attach @ 180003aac =====

undefined1 __scrt_dllmain_crt_thread_attach(void)

{
  char cVar1;
  
  cVar1 = __scrt_stub_for_acrt_thread_attach();
  if (cVar1 != '\0') {
    cVar1 = __scrt_stub_for_acrt_thread_attach();
    if (cVar1 != '\0') {
      return 1;
    }
    __scrt_stub_for_acrt_thread_attach();
  }
  return 0;
}



===== __scrt_dllmain_crt_thread_detach @ 180003adc =====

undefined1 __scrt_dllmain_crt_thread_detach(void)

{
  __scrt_stub_for_acrt_thread_attach();
  __scrt_stub_for_acrt_thread_attach();
  return 1;
}



===== __scrt_dllmain_exception_filter @ 180003af8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void __scrt_dllmain_exception_filter
               (undefined8 param_1,int param_2,undefined8 param_3,undefined *param_4,
               undefined4 param_5,undefined8 param_6)

{
  bool bVar1;
  undefined7 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if (((int)CONCAT71(extraout_var,bVar1) == 0) && (param_2 == 1)) {
    (*(code *)param_4)(param_1,0,param_3);
  }
  _o__seh_filter_dll(param_5,param_6);
  return;
}



===== __scrt_dllmain_uninitialize_c @ 180003b60 =====

void __scrt_dllmain_uninitialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    _execute_onexit_table(&DAT_1800153a0);
    return;
  }
  uVar2 = _is_c_termination_complete();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}



===== __scrt_dllmain_uninitialize_critical @ 180003b98 =====

void __scrt_dllmain_uninitialize_critical(void)

{
  __scrt_stub_for_acrt_thread_attach();
  __scrt_stub_for_acrt_thread_attach();
  return;
}



===== __scrt_initialize_crt @ 180003bb4 =====

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_1800153d1 = 1;
  }
  __isa_available_init();
  cVar1 = __scrt_stub_for_acrt_thread_attach();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = __scrt_stub_for_acrt_thread_attach();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    __scrt_stub_for_acrt_thread_attach();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



===== __scrt_initialize_onexit_tables @ 180003bf4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_1800153d0 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_1800153a0 = 0xffffffffffffffff;
      uRam00000001800153a8 = 0xffffffffffffffff;
      _DAT_1800153b0 = 0xffffffffffffffff;
      _DAT_1800153b8 = 0xffffffffffffffff;
      uRam00000001800153c0 = 0xffffffffffffffff;
      _DAT_1800153c8 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_1800153a0);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_1800153b8), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_1800153d0 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== __scrt_is_nonwritable_in_current_image @ 180003c88 =====

/* WARNING: Removing unreachable block (ram,0x000180003d15) */
/* WARNING: Enum "SectionFlags": Some values do not have unique names */

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_180000210; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_180000350;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x180000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x180000000U < uVar1)) goto LAB_180003cfe;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_180003cfe:
  if (pIVar3 == (IMAGE_SECTION_HEADER *)0x0) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = (uint7)(uVar1 >> 8);
    if ((int)pIVar3->Characteristics < 0) {
      uVar1 = (ulonglong)uVar2 << 8;
    }
    else {
      uVar1 = CONCAT71(uVar2,1);
    }
  }
  return uVar1;
}



===== __scrt_release_startup_lock @ 180003d28 =====

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    __scrt_native_startup_lock = 0;
    UNLOCK();
  }
  return;
}



===== __scrt_uninitialize_crt @ 180003d54 =====

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_1800153d1 == '\0') || (param_2 == '\0')) {
    __scrt_stub_for_acrt_thread_attach();
    __scrt_stub_for_acrt_thread_attach();
  }
  return 1;
}



===== _onexit @ 180003d84 =====

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_1800153a0 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_1800153a0);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



===== atexit @ 180003dc4 =====

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



===== __security_init_cookie @ 180003de4 =====

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  LARGE_INTEGER local_res8;
  _FILETIME local_res10;
  _FILETIME local_18 [2];
  
  if (__security_cookie == 0x2b992ddfa232) {
    local_res10.dwLowDateTime = 0;
    local_res10.dwHighDateTime = 0;
    local_res8.QuadPart = 0;
    GetSystemTimeAsFileTime(&local_res10);
    local_18[0] = local_res10;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res8);
    __security_cookie =
         (local_res8.QuadPart << 0x20 ^ local_res8.QuadPart ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (__security_cookie == 0x2b992ddfa232) {
      __security_cookie = 0x2b992ddfa233;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== __scrt_initialize_type_info @ 180003e9c =====

/* void __cdecl __scrt_initialize_type_info(void) */

void __cdecl __scrt_initialize_type_info(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180003ea3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&__type_info_root_node);
  return;
}



===== __scrt_uninitialize_type_info @ 180003eb0 =====

/* void __cdecl __scrt_uninitialize_type_info(void) */

void __cdecl __scrt_uninitialize_type_info(void)

{
  _o___std_type_info_destroy_list(&__type_info_root_node);
  return;
}



===== __scrt_initialize_default_local_stdio_options @ 180003ec4 =====

void __scrt_initialize_default_local_stdio_options(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x24;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return;
}



===== __scrt_get_dyn_tls_init_callback @ 180003ee8 =====

undefined * __scrt_get_dyn_tls_init_callback(void)

{
  return &__dyn_tls_init_callback;
}



===== __crt_debugger_hook @ 180003ef8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __crt_debugger_hook(int param_1)

{
  ___scrt_debugger_hook_flag = 0;
  return;
}



===== __scrt_fastfail @ 180003f08 =====

void __scrt_fastfail(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar4 = auStack_5c8;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x180003f3c;
  __crt_debugger_hook(3);
  *(undefined8 *)(puVar4 + -8) = 0x180003f4d;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180003f57;
  RtlCaptureContext(local_4d8);
  local_res10 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x180003f79;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    local_res18 = 0;
    local_res20 = 0;
    *(undefined8 **)(puVar4 + 0x30) = &local_res18;
    *(undefined8 **)(puVar4 + 0x28) = &local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x180003fca;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = auStack_5c8 + 0x5d0;
  *(undefined8 *)(puVar4 + -8) = 0x180003ffc;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x18000401e;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x18000403b;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x180004046;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x180004057;
    __crt_debugger_hook(3);
  }
  return;
}



===== _RTC_Initialize @ 180004070 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _RTC_Initialize(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &__rtc_izz; puVar1 < &__rtc_izz; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



===== _RTC_Terminate @ 1800040b4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _RTC_Terminate(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &__rtc_tzz; puVar1 < &__rtc_tzz; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



===== __raise_securityfailure @ 1800040f8 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000180004125. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 180004140 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar3 = auStack_38;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x18000416b;
  capture_previous_context((PCONTEXT)&DAT_1800154a0);
  _DAT_180015410 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_180015538 = puVar3 + 0x40;
  _DAT_180015520 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_180015400 = 0xc0000409;
  _DAT_180015404 = 1;
  _DAT_180015418 = 1;
  DAT_180015420 = 2;
  *(undefined8 *)(puVar3 + 0x20) = __security_cookie;
  *(undefined8 *)(puVar3 + 0x28) = __security_cookie_complement;
  *(undefined8 *)(puVar3 + -8) = 0x18000420d;
  DAT_180015598 = _DAT_180015410;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180010000);
  return;
}



===== capture_previous_context @ 180004218 =====

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  ulonglong local_res8 [2];
  PVOID local_res18 [2];
  
  local_res8[1] = 0;
  local_res8[0] = 0;
  local_res18[0] = (PVOID)0x0;
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8[0],ControlPc,FunctionEntry,param_1,local_res18,local_res8 + 1,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}



===== __isa_available_init @ 1800042a4 =====

/* WARNING: Removing unreachable block (ram,0x00018000436e) */
/* WARNING: Removing unreachable block (ram,0x0001800042de) */
/* WARNING: Removing unreachable block (ram,0x0001800042b7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __isa_available_init(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar8 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    ___memset_nt_threshold = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    ___memset_fast_string_threshold = 0x8000;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      __favor = __favor | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      __favor = __favor | 2;
    }
  }
  ___isa_available = 1;
  __isa_enabled = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    ___isa_available = 2;
    __isa_enabled = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        ___isa_available = 3;
        __isa_enabled = 0xe;
        if ((uVar8 & 0x20) != 0) {
          ___isa_available = 5;
          __isa_enabled = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            __isa_enabled = 0x6e;
            ___isa_available = 6;
          }
        }
      }
    }
  }
  return 0;
}



===== _get_startup_argv_mode @ 180004458 =====

undefined8 _get_startup_argv_mode(void)

{
  return 1;
}



===== __scrt_is_ucrt_dll_in_use @ 180004464 =====

bool __scrt_is_ucrt_dll_in_use(void)

{
  return __scrt_ucrt_dll_is_in_use != 0;
}



===== _guard_check_icall @ 180004480 =====

void _guard_check_icall(void)

{
  return;
}



===== _initterm @ 180004496 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004496. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== _initterm_e @ 1800044a2 =====

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800044a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}



===== _o___std_type_info_destroy_list @ 1800044ae =====

void _o___std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800044ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___std_type_info_destroy_list();
  return;
}



===== __stdio_common_vswprintf @ 1800044ba =====

void __stdio_common_vswprintf(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800044ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___stdio_common_vswprintf();
  return;
}



===== _callnewh @ 1800044c6 =====

void _callnewh(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800044c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__callnewh();
  return;
}



===== _cexit @ 1800044d2 =====

void _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800044d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__cexit();
  return;
}



===== _configure_narrow_argv @ 1800044de =====

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800044de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configure_narrow_argv();
  return;
}



===== _crt_atexit @ 1800044ea =====

void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800044ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__crt_atexit();
  return;
}



===== _execute_onexit_table @ 1800044f6 =====

void _execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800044f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__execute_onexit_table();
  return;
}



===== _o__initialize_narrow_environment @ 180004502 =====

void _o__initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004502. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_narrow_environment();
  return;
}



===== _initialize_onexit_table @ 18000450e =====

void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000450e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_onexit_table();
  return;
}



===== _invalid_parameter_noinfo @ 18000451a =====

void _invalid_parameter_noinfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000451a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__invalid_parameter_noinfo();
  return;
}



===== _o__purecall @ 180004530 =====

void _o__purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__purecall();
  return;
}



===== _register_onexit_function @ 18000453c =====

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000453c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__register_onexit_function();
  return;
}



===== _o__seh_filter_dll @ 180004548 =====

void _o__seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004548. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__seh_filter_dll();
  return;
}



===== free @ 180004554 =====

void free(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_free();
  return;
}



===== malloc @ 180004560 =====

void malloc(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_malloc();
  return;
}



===== __C_specific_handler @ 18000456c =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000456c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== memset @ 180004578 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180004578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== _vsnwprintf @ 180004584 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  __uint64 *p_Var2;
  
  p_Var2 = __local_stdio_printf_options();
  iVar1 = __stdio_common_vswprintf(*p_Var2 | 1,_Dest,_Count,_Format,0,_Args);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}



===== __tailMerge_bcrypt_dll @ 1800045e6 =====

void __tailMerge_bcrypt_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180012d80,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00018000465d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_BCryptOpenAlgorithmProvider @ 180004665 =====

void DelayLoad_BCryptOpenAlgorithmProvider
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptGetProperty @ 180004677 =====

void DelayLoad_BCryptGetProperty
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptCreateHash @ 180004689 =====

void DelayLoad_BCryptCreateHash
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptHashData @ 18000469b =====

void DelayLoad_BCryptHashData
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptFinishHash @ 1800046ad =====

void DelayLoad_BCryptFinishHash
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptDestroyHash @ 1800046bf =====

void DelayLoad_BCryptDestroyHash
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_BCryptCloseAlgorithmProvider @ 1800046d1 =====

void DelayLoad_BCryptCloseAlgorithmProvider
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_bcrypt_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __scrt_stub_for_acrt_thread_attach @ 1800046e4 =====

undefined1 __scrt_stub_for_acrt_thread_attach(void)

{
  return 1;
}



===== _is_c_termination_complete @ 1800046f0 =====

undefined8 _is_c_termination_complete(void)

{
  return 0;
}



===== DebugBreak @ 180004700 =====

/* void __cdecl wil::details::DebugBreak(void) */

void __cdecl wil::details::DebugBreak(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180004700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ::DebugBreak();
  return;
}



===== FormatNtStatusMsg @ 180004720 =====

/* void __cdecl wil::details::FormatNtStatusMsg(long,unsigned short * __ptr64,unsigned long) */

void __cdecl wil::details::FormatNtStatusMsg(long param_1,ushort *param_2,ulong param_3)

{
  HINSTANCE__ *lpSource;
  
  lpSource = wil_details_GetNtDllModuleHandle();
  FormatMessageW(0x1a00,lpSource,param_1,0x400,(LPWSTR)param_2,param_3,(va_list *)0x0);
  return;
}



===== GetCurrentModuleName @ 180004780 =====

/* char const * __ptr64 __cdecl wil::details::GetCurrentModuleName(void) */

char * __cdecl wil::details::GetCurrentModuleName(void)

{
  if (g_moduleFailureReportFlags._2_1_ == 0) {
    K32GetModuleInformation
              (RecordFailFast,(uint *)0x0,
               (char *)&`char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2
                        ::s_szModule,0x40);
    g_moduleFailureReportFlags._2_1_ = 1;
  }
  return (char *)&`char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2::
                  s_szModule;
}



===== K32GetModuleInformation @ 1800047c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* bool __cdecl wil::details::K32GetModuleInformation(void * __ptr64,unsigned int * __ptr64,char *
   __ptr64,unsigned __int64) */

bool __cdecl
wil::details::K32GetModuleInformation(void *param_1,uint *param_2,char *param_3,__uint64 param_4)

{
  bool bVar1;
  BOOL BVar2;
  DWORD DVar3;
  HRESULT HVar4;
  longlong lVar6;
  longlong lVar5;
  uint uVar7;
  size_t *pcchNewDestLength;
  STRSAFE_PCNZCH pszSrc;
  undefined1 auStackY_188 [32];
  size_t in_stack_fffffffffffffe98;
  HMODULE local_158 [2];
  CHAR local_148;
  char acStack_147 [271];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
  local_158[0] = (HMODULE)0x0;
  if ((param_1 == (void *)0x0) || (BVar2 = GetModuleHandleExW(6,param_1,local_158), BVar2 != 0)) {
    if (param_2 != (uint *)0x0) {
      uVar7 = 0;
      if (param_1 != (void *)0x0) {
        uVar7 = (int)param_1 - (int)local_158[0];
      }
      *param_2 = uVar7;
    }
    if (param_3 != (char *)0x0) {
      pcchNewDestLength = (size_t *)0x104;
      DVar3 = GetModuleFileNameA(local_158[0],&local_148,0x104);
      if (DVar3 == 0) goto LAB_180004853;
      lVar5 = -1;
      do {
        lVar6 = lVar5;
        lVar5 = lVar6 + 1;
      } while ((&local_148)[lVar5] != '\0');
      for (pszSrc = acStack_147 + lVar6; (&local_148 < pszSrc && (pszSrc[-1] != '\\'));
          pszSrc = pszSrc + -1) {
      }
      HVar4 = StringValidateDestA(&local_148,param_4,(size_t)pcchNewDestLength);
      if (HVar4 < 0) {
        if (param_4 != 0) {
          *param_3 = '\0';
        }
      }
      else {
        StringCopyWorkerA(param_3,param_4,pcchNewDestLength,pszSrc,in_stack_fffffffffffffe98);
      }
    }
    bVar1 = true;
  }
  else {
    if (param_2 != (uint *)0x0) {
      *param_2 = 0;
    }
LAB_180004853:
    bVar1 = false;
  }
  return bVar1;
}



===== MicrosoftInternalNotifyFailure @ 1800048d0 =====

/* void __cdecl wil::details::MicrosoftInternalNotifyFailure(struct wil::FailureInfo * __ptr64) */

void __cdecl wil::details::MicrosoftInternalNotifyFailure(FailureInfo *param_1)

{
  undefined8 local_res8;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  FailureInfo local_28;
  undefined1 local_27;
  undefined2 local_26;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_34 = 0;
  local_27 = 0;
  local_38 = *(undefined4 *)(param_1 + 8);
  local_30 = *(undefined8 *)(param_1 + 0x18);
  local_28 = *param_1;
  local_26 = (undefined2)g_moduleFailureReportFlags;
  local_20 = *(undefined2 *)(param_1 + 0x40);
  local_18 = *(undefined8 *)(param_1 + 0x38);
  local_10 = *(undefined8 *)(param_1 + 0x80);
  local_24 = 0;
  local_1e = 0;
  local_1c = 0;
  local_res8 = 0;
  WilFailureNotifyWatchers
            (0,(WilFailureReport *)&local_38,(WilFailureReportInformation *)&local_res8);
  *(undefined4 *)(param_1 + 0x10) = (undefined4)local_res8;
  if (local_res8._4_1_ == '\x01') {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
  }
  else if (local_res8._4_1_ == '\x02') {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
  }
  else if (local_res8._4_1_ == '\x03') {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
  }
  return;
}



===== RecordFailFast @ 180004980 =====

/* int __cdecl wil::details::RecordFailFast(long) */

int __cdecl wil::details::RecordFailFast(long param_1)

{
  `int___cdecl_wil::details::RecordFailFast(long)'::__l2::s_hrErrorLast = param_1;
  return 1;
}



===== RtlNtStatusToDosErrorNoTeb @ 1800049a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* unsigned long __cdecl wil::details::RtlNtStatusToDosErrorNoTeb(long) */

ulong __cdecl wil::details::RtlNtStatusToDosErrorNoTeb(long param_1)

{
  ulong uVar1;
  
  if ((`unsigned_long___cdecl_wil::details::RtlNtStatusToDosErrorNoTeb(long)'::__l2::
       s_pfnRtlNtStatusToDosErrorNoTeb == (_func_ulong_long *)0x0) &&
     (`unsigned_long___cdecl_wil::details::RtlNtStatusToDosErrorNoTeb(long)'::__l2::
      s_pfnRtlNtStatusToDosErrorNoTeb =
           (_func_ulong_long *)wil_details_GetNtDllProcedureAddress("RtlNtStatusToDosErrorNoTeb"),
     `unsigned_long___cdecl_wil::details::RtlNtStatusToDosErrorNoTeb(long)'::__l2::
     s_pfnRtlNtStatusToDosErrorNoTeb == (_func_ulong_long *)0x0)) {
    return 0;
  }
  uVar1 = (*`unsigned_long___cdecl_wil::details::RtlNtStatusToDosErrorNoTeb(long)'::__l2::
            s_pfnRtlNtStatusToDosErrorNoTeb)(param_1);
  return uVar1;
}



===== StringCopyWorkerA @ 1800049f0 =====

HRESULT __stdcall
StringCopyWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t *pcchNewDestLength,
                 STRSAFE_PCNZCH pszSrc,size_t cchToCopy)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  
  if (cchDest != 0) {
    lVar1 = 0x7ffffffe;
    lVar3 = (longlong)pszSrc - (longlong)pszDest;
    do {
      if ((lVar1 == 0) || (pszDest[lVar3] == '\0')) break;
      *pszDest = pszDest[lVar3];
      lVar1 = lVar1 + -1;
      pszDest = pszDest + 1;
      cchDest = cchDest - 1;
    } while (cchDest != 0);
  }
  pcVar2 = pszDest + -1;
  if (cchDest != 0) {
    pcVar2 = pszDest;
  }
  *pcVar2 = '\0';
  return ~-(uint)(cchDest != 0) & 0x8007007a;
}



===== StringValidateDestA @ 180004a44 =====

HRESULT __stdcall StringValidateDestA(STRSAFE_PCNZCH pszDest,size_t cchDest,size_t cchMax)

{
  HRESULT HVar1;
  
  HVar1 = 0;
  if (0x7ffffffe < cchDest - 1) {
    HVar1 = -0x7ff8ffa9;
  }
  return HVar1;
}



===== WilDynamicLoadRaiseFailFastException @ 180004a70 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilDynamicLoadRaiseFailFastException(struct _EXCEPTION_RECORD *
   __ptr64,struct _CONTEXT * __ptr64,unsigned long) */

void __cdecl
wil::details::WilDynamicLoadRaiseFailFastException
          (_EXCEPTION_RECORD *param_1,_CONTEXT *param_2,ulong param_3)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleW(L"kernelbase.dll");
  pFVar1 = GetProcAddress(hModule,"RaiseFailFastException");
  if (pFVar1 != (FARPROC)0x0) {
    (*pFVar1)(param_1,param_2,param_3);
  }
  return;
}



===== WilFailureNotifyWatchers @ 180004adc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilFailureNotifyWatchers(unsigned int,struct WilFailureReport const *
   __ptr64,struct WilFailureReportInformation * __ptr64) */

void __cdecl
wil::details::WilFailureNotifyWatchers
          (uint param_1,WilFailureReport *param_2,WilFailureReportInformation *param_3)

{
  if ((`void___cdecl_wil::details::WilFailureNotifyWatchers(unsigned_int,WilFailureReport_const*___ptr64,WilFailureReportInformation*___ptr64)'
       ::__l2::s_pfnFailureNotifyWatchers ==
       (_func_void_uint_WilFailureReport_ptr_WilFailureReportInformation_ptr *)0x0) &&
     (`void___cdecl_wil::details::WilFailureNotifyWatchers(unsigned_int,WilFailureReport_const*___ptr64,WilFailureReportInformation*___ptr64)'
      ::__l2::s_pfnFailureNotifyWatchers =
           (_func_void_uint_WilFailureReport_ptr_WilFailureReportInformation_ptr *)
           wil_details_GetKernelBaseProcAddress("WilFailureNotifyWatchers"),
     `void___cdecl_wil::details::WilFailureNotifyWatchers(unsigned_int,WilFailureReport_const*___ptr64,WilFailureReportInformation*___ptr64)'
     ::__l2::s_pfnFailureNotifyWatchers ==
     (_func_void_uint_WilFailureReport_ptr_WilFailureReportInformation_ptr *)0x0)) {
    return;
  }
  (*`void___cdecl_wil::details::WilFailureNotifyWatchers(unsigned_int,WilFailureReport_const*___ptr64,WilFailureReportInformation*___ptr64)'
    ::__l2::s_pfnFailureNotifyWatchers)(0,param_2,param_3);
  return;
}



===== wil_details_GetKernelBaseProcAddress @ 180004b30 =====

/* __int64 (__cdecl*__cdecl wil_details_GetKernelBaseProcAddress(char const * __ptr64))(void) */

_func___int64 * __cdecl wil_details_GetKernelBaseProcAddress(char *param_1)

{
  FARPROC pFVar1;
  
  if ((`__int64_(__cdecl*__cdecl_wil_details_GetKernelBaseProcAddress(char_const*___ptr64))(void)'::
       __l2::wil_details_kernelbaseModuleHandle == (HINSTANCE__ *)0x0) &&
     (`__int64_(__cdecl*__cdecl_wil_details_GetKernelBaseProcAddress(char_const*___ptr64))(void)'::
      __l2::wil_details_kernelbaseModuleHandle = GetModuleHandleW(L"kernelbase.dll"),
     `__int64_(__cdecl*__cdecl_wil_details_GetKernelBaseProcAddress(char_const*___ptr64))(void)'::
     __l2::wil_details_kernelbaseModuleHandle == (HMODULE)0x0)) {
    return (_func___int64 *)0x0;
  }
  pFVar1 = GetProcAddress(`__int64_(__cdecl*__cdecl_wil_details_GetKernelBaseProcAddress(char_const*___ptr64))(void)'
                          ::__l2::wil_details_kernelbaseModuleHandle,param_1);
  return (_func___int64 *)pFVar1;
}



===== wil_details_GetNtDllProcedureAddress @ 180004b94 =====

/* __int64 (__cdecl*__cdecl wil_details_GetNtDllProcedureAddress(char const * __ptr64))(void) */

_func___int64 * __cdecl wil_details_GetNtDllProcedureAddress(char *param_1)

{
  HINSTANCE__ *hModule;
  FARPROC pFVar1;
  
  hModule = wil_details_GetNtDllModuleHandle();
                    /* WARNING: Could not recover jumptable at 0x000180004bad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = GetProcAddress(hModule,param_1);
  return (_func___int64 *)pFVar1;
}



===== <lambda_invoker_cdecl> @ 180004bc0 =====

/* private: static __cdecl <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>(void *param_1)

{
  if (*(char *)param_1 != '\0') {
    wil::details_abi::SubscriptionList::OnSignaled
              ((SubscriptionList *)((longlong)param_1 + 0x98),(srwlock *)((longlong)param_1 + 0x20))
    ;
  }
  return;
}



===== <lambda_invoker_cdecl> @ 180004bf0 =====

/* private: static __cdecl <lambda_1ad7ecfab602a777ecf020873216a663>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_1ad7ecfab602a777ecf020873216a663>::<lambda_invoker_cdecl>(void *param_1)

{
  if (*(char *)param_1 != '\0') {
    wil::details_abi::SubscriptionList::OnSignaled
              ((SubscriptionList *)((longlong)param_1 + 0x48),(srwlock *)((longlong)param_1 + 0x20))
    ;
  }
  return;
}



===== <lambda_invoker_cdecl> @ 180004c20 =====

/* private: static __cdecl <lambda_5035b992506f4af81a770c5842624510>::<lambda_invoker_cdecl>(struct
   _TP_CALLBACK_INSTANCE * __ptr64,void * __ptr64,struct _TP_TIMER * __ptr64) */

void __cdecl
<lambda_5035b992506f4af81a770c5842624510>::<lambda_invoker_cdecl>
          (_TP_CALLBACK_INSTANCE *param_1,void *param_2,_TP_TIMER *param_3)

{
  PSRWLOCK SRWLock;
  heap_vector<wil_details_FeatureUsageSRUM> *phVar1;
  PSRWLOCK local_res10 [3];
  
  if (*(char *)param_2 != '\0') {
    SRWLock = (PSRWLOCK)((longlong)param_2 + 0x28);
    AcquireSRWLockExclusive(SRWLock);
    phVar1 = (heap_vector<wil_details_FeatureUsageSRUM> *)((longlong)param_2 + 0xe8);
    local_res10[0] = SRWLock;
    if (0xb < (ulonglong)(*(longlong *)((longlong)param_2 + 0xf0) - *(longlong *)phVar1)) {
      wil_details_WriteSRUMWnfUsageBuffer(phVar1);
      *(undefined8 *)((longlong)param_2 + 0xf0) = *(undefined8 *)phVar1;
    }
    *(undefined1 *)((longlong)param_2 + 0x40) = 0;
    wil::details::
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)local_res10);
  }
  return;
}



===== <lambda_invoker_cdecl> @ 180004c90 =====

/* private: static __cdecl <lambda_d51448ba32f8ef42e59400edd4566183>::<lambda_invoker_cdecl>(struct
   _TP_CALLBACK_INSTANCE * __ptr64,void * __ptr64,struct _TP_TIMER * __ptr64) */

void __cdecl
<lambda_d51448ba32f8ef42e59400edd4566183>::<lambda_invoker_cdecl>
          (_TP_CALLBACK_INSTANCE *param_1,void *param_2,_TP_TIMER *param_3)

{
  wil::details::FeatureStateManager::OnTimer(param_2);
  return;
}



===== <lambda_invoker_cdecl> @ 180004ca0 =====

/* private: static __cdecl <lambda_fee8cea507d2413a58be13acfb66740a>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_fee8cea507d2413a58be13acfb66740a>::<lambda_invoker_cdecl>(void *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  PSRWLOCK pRStackX_8;
  
  if (*(char *)param_1 != '\0') {
    AcquireSRWLockExclusive((PSRWLOCK)((longlong)param_1 + 8));
    piVar1 = *(int **)((longlong)param_1 + 0x58);
    for (piVar3 = *(int **)((longlong)param_1 + 0x50); piVar3 != piVar1; piVar3 = piVar3 + 4) {
      LOCK();
      **(uint **)(piVar3 + 2) = **(uint **)(piVar3 + 2) & (-(uint)(*piVar3 != 0) & 0x83a) - 0x83f;
      UNLOCK();
    }
    *(undefined8 *)((longlong)param_1 + 0x58) = *(undefined8 *)((longlong)param_1 + 0x50);
    iVar4 = *(int *)((longlong)param_1 + 0x1c) + 1;
    iVar2 = 1;
    if (iVar4 != 0) {
      iVar2 = iVar4;
    }
    *(int *)((longlong)param_1 + 0x1c) = iVar2;
    pRStackX_8 = (PSRWLOCK)((longlong)param_1 + 8);
    wil::details::
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&pRStackX_8);
  }
  return;
}



===== unique_ptr<void,wil::process_heap_deleter><1,void> @ 180004cac =====

/* public: __cdecl wistd::unique_ptr<void,struct wil::process_heap_deleter>::unique_ptr<void,struct
   wil::process_heap_deleter><1,void>(void * __ptr64) __ptr64 */

unique_ptr<void,wil::process_heap_deleter> * __thiscall
wistd::unique_ptr<void,wil::process_heap_deleter>::
unique_ptr<void,wil::process_heap_deleter><1,void>
          (unique_ptr<void,wil::process_heap_deleter> *this,void *param_1)

{
  *(void **)this = param_1;
  return this;
}



===== __compressed_pair<void*___ptr64,wil::process_heap_deleter><void*___ptr64,wil::process_heap_deleter> @ 180004cbc =====

/* public: __cdecl wistd::__compressed_pair<void * __ptr64,struct
   wil::process_heap_deleter>::__compressed_pair<void * __ptr64,struct
   wil::process_heap_deleter><void * __ptr64,struct wil::process_heap_deleter>(void * __ptr64 &&
   __ptr64,struct wil::process_heap_deleter && __ptr64) __ptr64 */

__compressed_pair<void*___ptr64,wil::process_heap_deleter> * __thiscall
wistd::__compressed_pair<void*___ptr64,wil::process_heap_deleter>::
__compressed_pair<void*___ptr64,wil::process_heap_deleter><void*___ptr64,wil::process_heap_deleter>
          (__compressed_pair<void*___ptr64,wil::process_heap_deleter> *this,void **param_1,
          process_heap_deleter *param_2)

{
  *(void **)this = *param_1;
  return this;
}



===== operator==<void,wil::process_heap_deleter> @ 180004cd0 =====

/* bool __cdecl wistd::operator==<void,struct wil::process_heap_deleter>(class
   wistd::unique_ptr<void,struct wil::process_heap_deleter> const & __ptr64,std::nullptr_t) */

bool __cdecl wistd::operator==<void,wil::process_heap_deleter>(longlong *param_1)

{
  return *param_1 == 0;
}



===== EnsureCoalescedTimer<wil::details::FeatureStateManager> @ 180004ce0 =====

/* void __cdecl wil::details::EnsureCoalescedTimer<class wil::details::FeatureStateManager>(class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<struct
   _TP_TIMER * __ptr64,void (__cdecl*)(struct _TP_TIMER * __ptr64),&public: static void __cdecl
   wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct _TP_TIMER * __ptr64,struct _TP_TIMER *
   __ptr64,0,std::nullptr_t> > > & __ptr64,bool & __ptr64,class wil::details::FeatureStateManager *
   __ptr64) */

void __cdecl
wil::details::EnsureCoalescedTimer<wil::details::FeatureStateManager>
          (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
           *param_1,bool *param_2,FeatureStateManager *param_3)

{
  PTP_TIMER p_Var1;
  last_error_context local_res10 [8];
  
  if (*param_2 == false) {
    if (*(longlong *)param_1 == 0) {
      last_error_context::last_error_context(local_res10);
      p_Var1 = CreateThreadpoolTimer
                         (<lambda_d51448ba32f8ef42e59400edd4566183>::<lambda_invoker_cdecl>,param_3,
                          (PTP_CALLBACK_ENVIRON)0x0);
      unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
      ::reset((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
               *)param_1,p_Var1);
      last_error_context::~last_error_context(local_res10);
    }
    EnsureCoalescedTimer_SetTimer(param_1,param_2,300000);
  }
  return;
}



===== EnsureCoalescedTimerSRUM<wil::details::FeatureStateManager> @ 180004d64 =====

/* void __cdecl wil::details::EnsureCoalescedTimerSRUM<class
   wil::details::FeatureStateManager>(class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<struct _TP_TIMER * __ptr64,void
   (__cdecl*)(struct _TP_TIMER * __ptr64),&public: static void __cdecl
   wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct _TP_TIMER * __ptr64,struct _TP_TIMER *
   __ptr64,0,std::nullptr_t> > > & __ptr64,bool & __ptr64,class wil::details::FeatureStateManager *
   __ptr64) */

void __cdecl
wil::details::EnsureCoalescedTimerSRUM<wil::details::FeatureStateManager>
          (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
           *param_1,bool *param_2,FeatureStateManager *param_3)

{
  PTP_TIMER p_Var1;
  last_error_context local_res10 [8];
  
  if (*param_2 == false) {
    if (*(longlong *)param_1 == 0) {
      last_error_context::last_error_context(local_res10);
      p_Var1 = CreateThreadpoolTimer
                         (<lambda_5035b992506f4af81a770c5842624510>::<lambda_invoker_cdecl>,param_3,
                          (PTP_CALLBACK_ENVIRON)0x0);
      unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
      ::reset((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
               *)param_1,p_Var1);
      last_error_context::~last_error_context(local_res10);
    }
    EnsureCoalescedTimer_SetTimer(param_1,param_2,5000);
  }
  return;
}



===== ReportFailure_Base<1,0> @ 180004de8 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details::ReportFailure_Base<1,0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Base<1,0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  undefined1 auStackY_1538 [32];
  undefined1 in_stack_ffffffffffffeb10;
  __uint64 in_stack_ffffffffffffeb20;
  __uint64 in_stack_ffffffffffffeb30;
  FailureInfo aFStack_14b8 [4];
  byte bStack_14b4;
  char acStack_1418 [1024];
  ushort auStack_1018 [2048];
  ulonglong uStack_18;
  undefined8 uStack_10;
  
  uStack_10 = 0x180005125;
  uStack_18 = __security_cookie ^ (ulonglong)auStackY_1538;
  memset(aFStack_14b8,0,0x98);
  LogFailure(param_1,param_2,"wil",(char *)0x0,(char *)0x0,param_6,1,param_7,(ushort *)0x0,
             (bool)in_stack_ffffffffffffeb10,auStack_1018,in_stack_ffffffffffffeb20,acStack_1418,
             in_stack_ffffffffffffeb30,aFStack_14b8);
  if ((bStack_14b4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast(aFStack_14b8);
  }
  return;
}



===== ReportFailure_Base<2,0> @ 180004df4 =====

/* void __cdecl wil::details::ReportFailure_Base<2,0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Base<2,0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  ReportFailureOptions in_stack_ffffffffffffffe8;
  
  ReportFailure_Return<2>
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,(ushort *)0x0,
             in_stack_ffffffffffffffe8);
  return;
}



===== ReportFailure_Base<3,0> @ 180004e38 =====

/* void __cdecl wil::details::ReportFailure_Base<3,0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Base<3,0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  code *pcVar1;
  char *in_stack_ffffffffffffffc8;
  ushort *in_stack_ffffffffffffffe0;
  ReportFailureOptions in_stack_ffffffffffffffe8;
  
  ReportFailure_NoReturn<3>
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffc8,param_6,param_7,
             in_stack_ffffffffffffffe0,in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ReportFailure_GetLastError<3> @ 180004e64 =====

/* unsigned long __cdecl wil::details::ReportFailure_GetLastError<3>(void * __ptr64,unsigned
   int,char const * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64) */

ulong __cdecl
wil::details::ReportFailure_GetLastError<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6)

{
  code *pcVar1;
  ulong uVar2;
  char *in_stack_ffffffffffffffb8;
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  ulong local_18;
  long local_14;
  undefined4 local_10;
  
  local_18 = GetLastErrorFail(param_1,param_2,
                              "onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h",param_4,
                              in_stack_ffffffffffffffb8,param_6);
  if (0 < (int)local_18) {
    local_18 = local_18 & 0xffff | 0x80070000;
  }
  local_14 = HrToNtStatus(local_18);
  local_10 = 0;
  ReportFailure_Base<3,0>
            (param_1,param_2,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h",param_4,
             in_stack_ffffffffffffffb8,param_6,(ResultStatus *)&local_18,in_stack_ffffffffffffffd0,
             in_stack_ffffffffffffffd8);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== ReportFailure_GetLastErrorHr<1> @ 180004ed8 =====

/* long __cdecl wil::details::ReportFailure_GetLastErrorHr<1>(void * __ptr64,unsigned int,char const
   * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64) */

long __cdecl
wil::details::ReportFailure_GetLastErrorHr<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6)

{
  ulong uVar1;
  char *pcVar2;
  char *in_stack_ffffffffffffffb8;
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  ulong local_18;
  long local_14;
  undefined4 local_10;
  
  pcVar2 = "wil";
  uVar1 = GetLastErrorFail(param_1,param_2,"wil",param_4,in_stack_ffffffffffffffb8,param_6);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  local_18 = uVar1;
  local_14 = HrToNtStatus(uVar1);
  local_10 = 0;
  ReportFailure_Base<1,0>
            (param_1,param_2,pcVar2,param_4,in_stack_ffffffffffffffb8,param_6,
             (ResultStatus *)&local_18,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8);
  return uVar1;
}



===== ReportFailure_Hr<1> @ 180004f64 =====

/* void __cdecl wil::details::ReportFailure_Hr<1>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  char *pcVar1;
  char *in_stack_ffffffffffffffb8;
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  long local_18;
  long local_14;
  undefined4 local_10;
  
  pcVar1 = (char *)(ulonglong)param_2;
  local_18 = param_7;
  local_14 = HrToNtStatus(param_7);
  local_10 = 0;
  ReportFailure_Base<1,0>
            (param_1,(uint)pcVar1,pcVar1,param_1,in_stack_ffffffffffffffb8,param_6,
             (ResultStatus *)&local_18,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8);
  return;
}



===== ReportFailure_Hr<2> @ 180004fb8 =====

/* void __cdecl wil::details::ReportFailure_Hr<2>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<2>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  long local_18;
  long local_14;
  undefined4 local_10;
  
  local_18 = param_7;
  local_14 = HrToNtStatus(param_7);
  local_10 = 0;
  ReportFailure_Base<2,0>
            (param_1,param_2,param_3,param_4,param_5,param_6,(ResultStatus *)&local_18,
             in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8);
  return;
}



===== ReportFailure_Hr<3> @ 180005018 =====

/* void __cdecl wil::details::ReportFailure_Hr<3>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  code *pcVar1;
  char *pcVar2;
  char *in_stack_ffffffffffffffb8;
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  undefined4 local_18;
  long local_14;
  undefined4 local_10;
  
  pcVar2 = (char *)(ulonglong)param_2;
  local_18 = 0x8000ffff;
  local_14 = HrToNtStatus(-0x7fff0001);
  local_10 = 0;
  ReportFailure_Base<3,0>
            (param_1,(uint)pcVar2,param_3,pcVar2,in_stack_ffffffffffffffb8,param_6,
             (ResultStatus *)&local_18,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ReportFailure_NoReturn<3> @ 180005064 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* void __cdecl wil::details::ReportFailure_NoReturn<3>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_NoReturn<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  undefined1 in_stack_ffffffffffffeb10;
  __uint64 in_stack_ffffffffffffeb20;
  __uint64 in_stack_ffffffffffffeb30;
  FailureInfo local_14b8 [160];
  char local_1418 [1024];
  ushort local_1018 [2044];
  undefined8 uStack_20;
  
  uStack_20 = 0x180005076;
  memset(local_14b8,0,0x98);
  LogFailure(param_1,param_2,param_3,(char *)0x0,(char *)0x0,param_6,3,param_7,(ushort *)0x0,
             (bool)in_stack_ffffffffffffeb10,local_1018,in_stack_ffffffffffffeb20,local_1418,
             in_stack_ffffffffffffeb30,local_14b8);
                    /* WARNING: Subroutine does not return */
  WilFailFast(local_14b8);
}



===== ReportFailure_Return<1> @ 180005110 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details::ReportFailure_Return<1>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Return<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  undefined1 auStackY_1538 [32];
  undefined1 in_stack_ffffffffffffeb10;
  __uint64 in_stack_ffffffffffffeb20;
  __uint64 in_stack_ffffffffffffeb30;
  FailureInfo local_14b8 [4];
  byte local_14b4;
  char local_1418 [1024];
  ushort local_1018 [2048];
  ulonglong local_18;
  undefined8 local_10;
  
  local_10 = 0x180005125;
  local_18 = __security_cookie ^ (ulonglong)auStackY_1538;
  memset(local_14b8,0,0x98);
  LogFailure(param_1,param_2,"wil",(char *)0x0,(char *)0x0,param_6,1,param_7,(ushort *)0x0,
             (bool)in_stack_ffffffffffffeb10,local_1018,in_stack_ffffffffffffeb20,local_1418,
             in_stack_ffffffffffffeb30,local_14b8);
  if ((local_14b4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast(local_14b8);
  }
  return;
}



===== ReportFailure_Return<2> @ 180005204 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details::ReportFailure_Return<2>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Return<2>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  undefined1 auStackY_1578 [32];
  FailureInfo local_14f8 [4];
  byte local_14f4;
  char local_1458 [1024];
  ushort local_1058 [2048];
  ulonglong local_58;
  undefined8 uStack_48;
  
  uStack_48 = 0x18000521b;
  local_58 = __security_cookie ^ (ulonglong)auStackY_1578;
  memset(local_14f8,0,0x98);
  LogFailure(param_1,param_2,param_3,param_4,param_5,param_6,2,param_7,param_8,false,local_1058,
             0x800,local_1458,0x400,local_14f8);
  if ((local_14f4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast(local_14f8);
  }
  return;
}



===== WriteResultString<char_const*___ptr64> @ 180005320 =====

/* unsigned char * __ptr64 __cdecl wil::details::WriteResultString<char const * __ptr64>(unsigned
   char * __ptr64,unsigned char * __ptr64,char const * __ptr64,char const * __ptr64 * __ptr64) */

uchar * __cdecl
wil::details::WriteResultString<char_const*___ptr64>
          (uchar *param_1,uchar *param_2,char *param_3,char **param_4)

{
  __uint64 _MaxCount;
  char **ppcVar1;
  
  ppcVar1 = param_4;
  if (((param_1 != param_2) && (param_3 != (char *)0x0)) && (*param_3 != '\0')) {
    _MaxCount = ResultStringSize(param_3);
    if (_MaxCount <= (ulonglong)((longlong)param_2 - (longlong)param_1)) {
      memcpy_s(param_1,(longlong)param_2 - (longlong)param_1,param_3,_MaxCount);
      if (param_4 != (char **)0x0) {
        *param_4 = (char *)param_1;
      }
      return param_1 + _MaxCount;
    }
  }
  if (param_4 != (char **)0x0) {
    *ppcVar1 = (char *)0x0;
  }
  return param_1;
}



===== unique_ptr<void,wil::process_heap_deleter> @ 180005394 =====

/* public: __cdecl wistd::unique_ptr<void,struct wil::process_heap_deleter>::unique_ptr<void,struct
   wil::process_heap_deleter>(class wistd::unique_ptr<void,struct wil::process_heap_deleter> &&
   __ptr64) __ptr64 */

unique_ptr<void,wil::process_heap_deleter> * __thiscall
wistd::unique_ptr<void,wil::process_heap_deleter>::unique_ptr<void,wil::process_heap_deleter>
          (unique_ptr<void,wil::process_heap_deleter> *this,
          unique_ptr<void,struct_wil::process_heap_deleter> *param_1)

{
  process_heap_deleter *in_R8;
  void *local_res8 [4];
  
  local_res8[0] = *(void **)param_1;
  *(undefined8 *)param_1 = 0;
  __compressed_pair<void*___ptr64,wil::process_heap_deleter>::
  __compressed_pair<void*___ptr64,wil::process_heap_deleter><void*___ptr64,wil::process_heap_deleter>
            ((__compressed_pair<void*___ptr64,wil::process_heap_deleter> *)this,local_res8,in_R8);
  return this;
}



===== RawUsageIndex @ 1800053c0 =====

/* public: __cdecl wil::details_abi::RawUsageIndex::RawUsageIndex(unsigned short,unsigned short,enum
   wil::details_abi::CountSize,unsigned short,enum wil::details_abi::CountSize) __ptr64 */

RawUsageIndex * __thiscall
wil::details_abi::RawUsageIndex::RawUsageIndex
          (RawUsageIndex *this,ushort param_1,ushort param_2,CountSize param_3,ushort param_4,
          CountSize param_5)

{
  __uint64 _Var1;
  undefined8 uVar2;
  ushort local_28;
  undefined1 local_26;
  undefined4 local_24;
  undefined2 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *(ushort *)(this + 2) = param_2;
  uVar2 = 0;
  *(ushort *)(this + 6) = param_4;
  *(ushort *)this = param_1;
  this[4] = SUB41(param_3,0);
  this[8] = (RawUsageIndex)(undefined1)param_5;
  if (param_4 == 0) {
    _Var1 = 0;
  }
  else {
    local_26 = (undefined1)param_5;
    local_28 = param_4;
    local_18 = 0;
    uStack_10 = 0;
    local_24 = 0;
    local_20 = 0;
    _Var1 = UsageIndexProperty::GetSize((UsageIndexProperty *)&local_28);
  }
  *(__uint64 *)(this + 0x10) = _Var1;
  *(undefined8 *)(this + 0x18) = uVar2;
  *(undefined8 *)(this + 0x20) = uVar2;
  *(undefined8 *)(this + 0x28) = uVar2;
  *(undefined8 *)(this + 0x30) = uVar2;
  *(short *)(this + 0x38) = (short)uVar2;
  this[0x3a] = SUB81(uVar2,0);
  return this;
}



===== UsageIndexes @ 180005444 =====

/* public: __cdecl wil::details_abi::UsageIndexes::UsageIndexes(void) __ptr64 */

UsageIndexes * __thiscall wil::details_abi::UsageIndexes::UsageIndexes(UsageIndexes *this)

{
  undefined4 in_R9D;
  CountSize CVar1;
  CountSize in_stack_fffffffffffffff0;
  CountSize CVar2;
  
  CVar2 = in_stack_fffffffffffffff0 & 0xffffff00;
  CVar1 = CONCAT31((int3)((uint)in_R9D >> 8),1);
  RawUsageIndex::RawUsageIndex((RawUsageIndex *)this,0,4,CVar1,4,CVar2);
  CVar2 = CONCAT31((int3)(CVar2 >> 8),2);
  RawUsageIndex::RawUsageIndex((RawUsageIndex *)(this + 0x40),0,4,CVar1,4,CVar2);
  RawUsageIndex::RawUsageIndex
            ((RawUsageIndex *)(this + 0x80),0,4,CVar1,0,CONCAT31((int3)(CVar2 >> 8),(char)CVar1));
  return this;
}



===== heap_buffer @ 1800054b8 =====

/* public: __cdecl wil::details_abi::heap_buffer::heap_buffer(struct wil::details_abi::heap_buffer
   && __ptr64) __ptr64 */

heap_buffer * __thiscall
wil::details_abi::heap_buffer::heap_buffer(heap_buffer *this,heap_buffer *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined8 *)(this + 8) = uVar1;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
  wistd::unique_ptr<void,wil::process_heap_deleter>::unique_ptr<void,wil::process_heap_deleter>
            ((unique_ptr<void,wil::process_heap_deleter> *)(this + 0x18),
             (unique_ptr<void,struct_wil::process_heap_deleter> *)(param_1 + 0x18));
  return this;
}



===== last_error_context @ 1800054ec =====

/* public: __cdecl wil::last_error_context::last_error_context(void) __ptr64 */

last_error_context * __thiscall
wil::last_error_context::last_error_context(last_error_context *this)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  *(DWORD *)(this + 4) = DVar1;
  *this = (last_error_context)0x0;
  return this;
}



===== ~ProcessLocalStorageData<wil::details_abi::ProcessLocalData> @ 180005518 =====

/* public: __cdecl wil::details_abi::ProcessLocalStorageData<struct
   wil::details_abi::ProcessLocalData>::~ProcessLocalStorageData<struct
   wil::details_abi::ProcessLocalData>(void) __ptr64 */

void __thiscall
wil::details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::
~ProcessLocalStorageData<wil::details_abi::ProcessLocalData>
          (ProcessLocalStorageData<wil::details_abi::ProcessLocalData> *this)

{
  ThreadLocalStorage<wil::details_abi::ThreadLocalData>::
  ~ThreadLocalStorage<wil::details_abi::ThreadLocalData>
            ((ThreadLocalStorage<wil::details_abi::ThreadLocalData> *)(this + 0x28));
  SemaphoreValue::~SemaphoreValue((SemaphoreValue *)(this + 0x10));
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)(this + 8));
  return;
}



===== ~ProcessLocalStorageData<wil::details_abi::FeatureStateData> @ 180005548 =====

/* public: __cdecl wil::details_abi::ProcessLocalStorageData<class
   wil::details_abi::FeatureStateData>::~ProcessLocalStorageData<class
   wil::details_abi::FeatureStateData>(void) __ptr64 */

void __thiscall
wil::details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::
~ProcessLocalStorageData<wil::details_abi::FeatureStateData>
          (ProcessLocalStorageData<wil::details_abi::FeatureStateData> *this)

{
  FeatureStateData::~FeatureStateData((FeatureStateData *)(this + 0x20));
  SemaphoreValue::~SemaphoreValue((SemaphoreValue *)(this + 0x10));
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)(this + 8));
  return;
}



===== ~ThreadLocalStorage<wil::details_abi::ThreadLocalData> @ 180005578 =====

/* public: __cdecl wil::details_abi::ThreadLocalStorage<struct
   wil::details_abi::ThreadLocalData>::~ThreadLocalStorage<struct
   wil::details_abi::ThreadLocalData>(void) __ptr64 */

void __thiscall
wil::details_abi::ThreadLocalStorage<wil::details_abi::ThreadLocalData>::
~ThreadLocalStorage<wil::details_abi::ThreadLocalData>
          (ThreadLocalStorage<wil::details_abi::ThreadLocalData> *this)

{
  ThreadLocalStorage<wil::details_abi::ThreadLocalData> *pTVar1;
  LPVOID pvVar2;
  HANDLE hHeap;
  LPVOID lpMem;
  
  pTVar1 = this + 0x50;
  for (; this != pTVar1; this = this + 8) {
    lpMem = *(LPVOID *)this;
    while (lpMem != (LPVOID)0x0) {
      pvVar2 = *(LPVOID *)((longlong)lpMem + 8);
      ThreadLocalData::Clear((ThreadLocalData *)((longlong)lpMem + 0x10));
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,lpMem);
      lpMem = pvVar2;
    }
    *(undefined8 *)this = 0;
  }
  return;
}



===== ~function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)> @ 1800055fc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl wistd::function<bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::~function<bool __cdecl(void * __ptr64,unsigned
   __int64,void * __ptr64,unsigned __int64,unsigned int)>(void) __ptr64 */

void __thiscall
wistd::
function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>::
~function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
          (function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
           *this)

{
  if (*(longlong **)(this + 0x70) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x70) + 0x18))();
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<HKEY__*___ptr64,long_(__cdecl*)(HKEY__*___ptr64),&long___cdecl_RegCloseKey(struct_HKEY__*___ptr64),wistd::integral_constant<unsigned___int64,0>,HKEY__*___ptr64,HKEY__*___ptr64,0,std::nullptr_t>_> @ 180005624 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct HKEY__ *
   __ptr64,long (__cdecl*)(struct HKEY__ * __ptr64),&long __cdecl RegCloseKey(struct HKEY__ *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct HKEY__ * __ptr64,struct
   HKEY__ * __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<struct
   HKEY__ * __ptr64,long (__cdecl*)(struct HKEY__ * __ptr64),&long __cdecl RegCloseKey(struct HKEY__
   * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct HKEY__ * __ptr64,struct
   HKEY__ * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<HKEY__*___ptr64,long_(__cdecl*)(HKEY__*___ptr64),&long___cdecl_RegCloseKey(struct_HKEY__*___ptr64),wistd::integral_constant<unsigned___int64,0>,HKEY__*___ptr64,HKEY__*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<HKEY__*___ptr64,long_(__cdecl*)(HKEY__*___ptr64),&long___cdecl_RegCloseKey(struct_HKEY__*___ptr64),wistd::integral_constant<unsigned___int64,0>,HKEY__*___ptr64,HKEY__*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<HKEY__*___ptr64,long_(__cdecl*)(HKEY__*___ptr64),&long___cdecl_RegCloseKey(struct_HKEY__*___ptr64),wistd::integral_constant<unsigned___int64,0>,HKEY__*___ptr64,HKEY__*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(HKEY *)this != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)this);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_> @ 180005648 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _KEY_VALUE_PARTIAL_INFORMATION * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   TpmFree(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct
   _KEY_VALUE_PARTIAL_INFORMATION * __ptr64,struct _KEY_VALUE_PARTIAL_INFORMATION *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<struct
   _KEY_VALUE_PARTIAL_INFORMATION * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   TpmFree(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct
   _KEY_VALUE_PARTIAL_INFORMATION * __ptr64,struct _KEY_VALUE_PARTIAL_INFORMATION *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(void **)this != (void *)0x0) {
    FreeProcessHeap(*(void **)this);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_> @ 180005668 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _RTL_CRITICAL_SECTION * __ptr64,void (__cdecl*)(struct _RTL_CRITICAL_SECTION * __ptr64),&void
   __cdecl LeaveCriticalSection(struct _RTL_CRITICAL_SECTION * __ptr64),struct
   wistd::integral_constant<unsigned __int64,1>,struct _RTL_CRITICAL_SECTION * __ptr64,struct
   _RTL_CRITICAL_SECTION * __ptr64,0,std::nullptr_t> >::~unique_storage<struct
   wil::details::resource_policy<struct _RTL_CRITICAL_SECTION * __ptr64,void (__cdecl*)(struct
   _RTL_CRITICAL_SECTION * __ptr64),&void __cdecl LeaveCriticalSection(struct _RTL_CRITICAL_SECTION
   * __ptr64),struct wistd::integral_constant<unsigned __int64,1>,struct _RTL_CRITICAL_SECTION *
   __ptr64,struct _RTL_CRITICAL_SECTION * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(LPCRITICAL_SECTION *)this != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)this);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_> @ 18000568c =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _RTL_SRWLOCK * __ptr64,void (__cdecl*)(struct _RTL_SRWLOCK * __ptr64),&void __cdecl
   ReleaseSRWLockExclusive(struct _RTL_SRWLOCK * __ptr64),struct wistd::integral_constant<unsigned
   __int64,1>,struct _RTL_SRWLOCK * __ptr64,struct _RTL_SRWLOCK * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<struct _RTL_SRWLOCK * __ptr64,void
   (__cdecl*)(struct _RTL_SRWLOCK * __ptr64),&void __cdecl ReleaseSRWLockExclusive(struct
   _RTL_SRWLOCK * __ptr64),struct wistd::integral_constant<unsigned __int64,1>,struct _RTL_SRWLOCK *
   __ptr64,struct _RTL_SRWLOCK * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(PSRWLOCK *)this != (PSRWLOCK)0x0) {
    ReleaseSRWLockExclusive(*(PSRWLOCK *)this);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_> @ 1800056b0 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _RTL_SRWLOCK * __ptr64,void (__cdecl*)(struct _RTL_SRWLOCK * __ptr64),&void __cdecl
   ReleaseSRWLockShared(struct _RTL_SRWLOCK * __ptr64),struct wistd::integral_constant<unsigned
   __int64,1>,struct _RTL_SRWLOCK * __ptr64,struct _RTL_SRWLOCK * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<struct _RTL_SRWLOCK * __ptr64,void
   (__cdecl*)(struct _RTL_SRWLOCK * __ptr64),&void __cdecl ReleaseSRWLockShared(struct _RTL_SRWLOCK
   * __ptr64),struct wistd::integral_constant<unsigned __int64,1>,struct _RTL_SRWLOCK *
   __ptr64,struct _RTL_SRWLOCK * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(PSRWLOCK *)this != (PSRWLOCK)0x0) {
    ReleaseSRWLockShared(*(PSRWLOCK *)this);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_> @ 1800056d4 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,long (__cdecl*)(void * __ptr64),&long __cdecl NtClose(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<void * __ptr64,long (__cdecl*)(void *
   __ptr64),&long __cdecl NtClose(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(longlong *)this != 0) {
    NtClose();
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_> @ 1800056f8 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void __cdecl wil::details::CloseHandle(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void __cdecl wil::details::CloseHandle(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(void **)this != (void *)0x0) {
    CloseHandle(*(void **)this);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_> @ 180005718 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void __cdecl wil::details::ReleaseMutex(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,2>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void __cdecl wil::details::ReleaseMutex(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,2>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(void **)this != (void *)0x0) {
    ReleaseMutex(*(void **)this);
  }
  return;
}



===== ~FeatureStateData @ 180005738 =====

/* public: __cdecl wil::details_abi::FeatureStateData::~FeatureStateData(void) __ptr64 */

void __thiscall wil::details_abi::FeatureStateData::~FeatureStateData(FeatureStateData *this)

{
  ProcessShutdown(this);
  SubscriptionList::~SubscriptionList((SubscriptionList *)(this + 200));
  UsageIndexes::~UsageIndexes((UsageIndexes *)(this + 8));
  return;
}



===== ~SemaphoreValue @ 180005768 =====

/* public: __cdecl wil::details_abi::SemaphoreValue::~SemaphoreValue(void) __ptr64 */

void __thiscall wil::details_abi::SemaphoreValue::~SemaphoreValue(SemaphoreValue *this)

{
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)(this + 8));
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)this);
  return;
}



===== ~UsageIndexes @ 180005790 =====

/* public: __cdecl wil::details_abi::UsageIndexes::~UsageIndexes(void) __ptr64 */

void __thiscall wil::details_abi::UsageIndexes::~UsageIndexes(UsageIndexes *this)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(this + 0xb0);
  *(undefined8 *)(this + 0xb0) = 0;
  if (pvVar1 != (void *)0x0) {
    details::FreeProcessHeap(pvVar1);
  }
  pvVar1 = *(void **)(this + 0x70);
  *(undefined8 *)(this + 0x70) = 0;
  if (pvVar1 != (void *)0x0) {
    details::FreeProcessHeap(pvVar1);
  }
  pvVar1 = *(void **)(this + 0x30);
  *(undefined8 *)(this + 0x30) = 0;
  if (pvVar1 != (void *)0x0) {
    details::FreeProcessHeap(pvVar1);
  }
  return;
}



===== ~last_error_context @ 1800057e8 =====

/* public: __cdecl wil::last_error_context::~last_error_context(void) __ptr64 */

void __thiscall wil::last_error_context::~last_error_context(last_error_context *this)

{
  if (*this == (last_error_context)0x0) {
    SetLastError(*(DWORD *)(this + 4));
  }
  return;
}



===== operator= @ 18000580c =====

/* public: class wistd::unique_ptr<void,struct wil::process_heap_deleter> & __ptr64 __cdecl
   wistd::unique_ptr<void,struct wil::process_heap_deleter>::operator=(class
   wistd::unique_ptr<void,struct wil::process_heap_deleter> && __ptr64) __ptr64 */

unique_ptr<void,struct_wil::process_heap_deleter> * __thiscall
wistd::unique_ptr<void,wil::process_heap_deleter>::operator=
          (unique_ptr<void,wil::process_heap_deleter> *this,
          unique_ptr<void,struct_wil::process_heap_deleter> *param_1)

{
  undefined8 uVar1;
  void *pvVar2;
  
  uVar1 = *(undefined8 *)param_1;
  *(undefined8 *)param_1 = 0;
  pvVar2 = *(void **)this;
  *(undefined8 *)this = uVar1;
  if (pvVar2 != (void *)0x0) {
    wil::details::FreeProcessHeap(pvVar2);
  }
  return (unique_ptr<void,struct_wil::process_heap_deleter> *)this;
}



===== operator() @ 180005840 =====

/* public: virtual bool __cdecl wistd::__function::__func<class
   <lambda_8db0ce862824541f40dfb767113f1e28>,bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::operator()(void * __ptr64 && __ptr64,unsigned __int64 &&
   __ptr64,void * __ptr64 && __ptr64,unsigned __int64 && __ptr64,unsigned int && __ptr64) __ptr64 */

bool __thiscall
wistd::__function::
__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
::operator()(__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
             *this,void **param_1,__uint64 *param_2,void **param_3,__uint64 *param_4,uint *param_5)

{
  bool bVar1;
  
  if ((**(ulonglong **)(this + 8) < **(ulonglong **)(this + 0x10)) ||
     (bVar1 = wil::details_abi::RawUsageIndex::RecordUsage
                        (*(RawUsageIndex **)(this + 0x18),*param_1,*param_2,*param_3,*param_4,
                         *param_5), bVar1)) {
    **(longlong **)(this + 8) = **(longlong **)(this + 8) + 1;
    return true;
  }
  return false;
}



===== `scalar_deleting_destructor' @ 1800058b0 =====

/* public: virtual void * __ptr64 __cdecl wistd::__function::__base<bool __cdecl(void *
   __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned int)>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
wistd::__function::
__base<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>::
_scalar_deleting_destructor_
          (__base<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
           *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete__(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1800058f0 =====

/* public: virtual void * __ptr64 __cdecl wistd::__function::__func<class
   <lambda_8db0ce862824541f40dfb767113f1e28>,bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::`scalar deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
wistd::__function::
__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
::_scalar_deleting_destructor_
          (__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
           *this,uint param_1)

{
  *(undefined ***)this =
       &__base<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
        ::_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete__(this);
  }
  return this;
}



===== Acquire @ 180005924 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl wil::details_abi::ProcessLocalStorageData<struct
   wil::details_abi::ProcessLocalData>::Acquire(char const * __ptr64,class
   wil::details_abi::ProcessLocalStorageData<struct wil::details_abi::ProcessLocalData> * __ptr64 *
   __ptr64) */

long __cdecl
wil::details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Acquire
          (char *param_1,
          ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **param_2)

{
  DWORD DVar1;
  long lVar2;
  HANDLE pvVar3;
  uint uVar4;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **ppPVar5;
  int iVar6;
  void *unaff_retaddr;
  undefined1 auStack_278 [32];
  undefined4 local_258;
  char *local_250;
  longlong local_248;
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  local_240 [8];
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *local_238 [2];
  WCHAR local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_278;
  *param_2 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
  DVar1 = GetCurrentProcessId();
  local_258 = 0x78;
  local_250 = param_1;
  StringCchPrintfW((ushort *)local_228,0x104,(ushort *)L"Local\\SM0:%lu:%lu:%hs",(ulonglong)DVar1);
  local_248 = 0;
  iVar6 = 0x1f0001;
  ppPVar5 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **)0x0;
  pvVar3 = CreateMutexExW((LPSECURITY_ATTRIBUTES)0x0,local_228,0,0x1f0001);
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *)&local_248,pvVar3);
  if (local_248 == 0) {
    lVar2 = details::GetLastErrorFailHr();
    goto LAB_180005a37;
  }
  mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
  ::acquire((mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
             *)&local_248,(ulong *)local_240,(ulong)ppPVar5,iVar6);
  local_238[0] = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
  lVar2 = SemaphoreValue::TryGetPointer((ushort *)local_228,local_238);
  if (lVar2 < 0) {
    uVar4 = 299;
    param_2 = ppPVar5;
LAB_1800059fa:
    details::in1diag3::Return_Hr(unaff_retaddr,uVar4,(char *)param_2,lVar2);
    details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              (local_240);
  }
  else {
    if (local_238[0] == (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0) {
      lVar2 = MakeAndInitialize((ushort *)local_228,
                                (unique_any_t<wil::mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>_>
                                 *)&local_248,param_2);
      if (lVar2 < 0) {
        uVar4 = 0x134;
        goto LAB_1800059fa;
      }
    }
    else {
      *param_2 = local_238[0];
      *(int *)*param_2 = *(int *)local_238[0] + 1;
    }
    details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              (local_240);
    lVar2 = 0;
  }
LAB_180005a37:
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)&local_248);
  return lVar2;
}



===== Acquire @ 180005a90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl wil::details_abi::ProcessLocalStorageData<class
   wil::details_abi::FeatureStateData>::Acquire(char const * __ptr64,class
   wil::details_abi::ProcessLocalStorageData<class wil::details_abi::FeatureStateData> * __ptr64 *
   __ptr64) */

long __cdecl
wil::details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Acquire
          (char *param_1,ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **param_2
          )

{
  DWORD DVar1;
  long lVar2;
  HANDLE pvVar3;
  uint uVar4;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **ppPVar5;
  int iVar6;
  void *unaff_retaddr;
  undefined1 auStack_278 [32];
  undefined4 local_258;
  char *local_250;
  longlong local_248;
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  local_240 [8];
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *local_238 [2];
  WCHAR local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_278;
  *param_2 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
  DVar1 = GetCurrentProcessId();
  local_258 = 0x130;
  local_250 = param_1;
  StringCchPrintfW((ushort *)local_228,0x104,(ushort *)L"Local\\SM0:%lu:%lu:%hs",(ulonglong)DVar1);
  local_248 = 0;
  iVar6 = 0x1f0001;
  ppPVar5 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **)0x0;
  pvVar3 = CreateMutexExW((LPSECURITY_ATTRIBUTES)0x0,local_228,0,0x1f0001);
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *)&local_248,pvVar3);
  if (local_248 == 0) {
    lVar2 = details::GetLastErrorFailHr();
    goto LAB_180005ba3;
  }
  mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
  ::acquire((mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
             *)&local_248,(ulong *)local_240,(ulong)ppPVar5,iVar6);
  local_238[0] = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
  lVar2 = SemaphoreValue::TryGetPointer((ushort *)local_228,local_238);
  if (lVar2 < 0) {
    uVar4 = 299;
    param_2 = ppPVar5;
LAB_180005b66:
    details::in1diag3::Return_Hr(unaff_retaddr,uVar4,(char *)param_2,lVar2);
    details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              (local_240);
  }
  else {
    if (local_238[0] == (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0) {
      lVar2 = MakeAndInitialize((ushort *)local_228,
                                (unique_any_t<wil::mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>_>
                                 *)&local_248,param_2);
      if (lVar2 < 0) {
        uVar4 = 0x134;
        goto LAB_180005b66;
      }
    }
    else {
      *param_2 = local_238[0];
      *(int *)*param_2 = *(int *)local_238[0] + 1;
    }
    details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              (local_240);
    lVar2 = 0;
  }
LAB_180005ba3:
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)&local_248);
  return lVar2;
}



===== Clear @ 180005bfc =====

/* public: void __cdecl wil::details_abi::ThreadLocalData::Clear(void) __ptr64 */

void __thiscall wil::details_abi::ThreadLocalData::Clear(ThreadLocalData *this)

{
  undefined8 *puVar1;
  ushort uVar2;
  undefined8 *puVar3;
  LPVOID pvVar4;
  HANDLE pvVar5;
  undefined8 *puVar6;
  
  puVar3 = *(undefined8 **)(this + 0x18);
  uVar2 = *(ushort *)(this + 0x20);
  if (puVar3 != puVar3 + (ulonglong)uVar2 * 10) {
    puVar6 = puVar3 + 8;
    do {
      pvVar4 = (LPVOID)*puVar6;
      pvVar5 = GetProcessHeap();
      HeapFree(pvVar5,0,pvVar4);
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar1 = puVar6 + 2;
      puVar6 = puVar6 + 10;
    } while (puVar1 != puVar3 + (ulonglong)uVar2 * 10);
  }
  pvVar4 = *(LPVOID *)(this + 0x18);
  pvVar5 = GetProcessHeap();
  HeapFree(pvVar5,0,pvVar4);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  return;
}



===== CloseHandle @ 180005cbc =====

/* void __cdecl wil::details::CloseHandle(void * __ptr64) */

void __cdecl wil::details::CloseHandle(void *param_1)

{
  code *pcVar1;
  BOOL BVar2;
  char *in_R8;
  void *unaff_retaddr;
  
  BVar2 = ::CloseHandle(param_1);
  if (BVar2 == 0) {
    in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,in_R8);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  return;
}



===== Compare @ 180005cec =====

/* public: int __cdecl wil::details_abi::UsageIndexProperty::Compare(void * __ptr64,unsigned
   __int64)const __ptr64 */

int __thiscall
wil::details_abi::UsageIndexProperty::Compare
          (UsageIndexProperty *this,void *param_1,__uint64 param_2)

{
  int iVar1;
  
  if (param_2 == *(ushort *)(this + 8)) {
    iVar1 = memcmp(param_1,*(void **)(this + 0x18),param_2);
  }
  else {
    iVar1 = (int)param_2 - (uint)*(ushort *)(this + 8);
  }
  return iVar1;
}



===== CreateFromValueInternal @ 180005d20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl wil::details_abi::SemaphoreValue::CreateFromValueInternal(unsigned short
   const * __ptr64,bool,unsigned __int64) __ptr64 */

long __thiscall
wil::details_abi::SemaphoreValue::CreateFromValueInternal
          (SemaphoreValue *this,ushort *param_1,bool param_2,__uint64 param_3)

{
  long lVar1;
  __uint64 _Var2;
  uint uVar3;
  uint uVar4;
  undefined7 in_register_00000081;
  char *pcVar5;
  void *unaff_retaddr;
  undefined1 auStackY_278 [32];
  ulong in_stack_fffffffffffffda8;
  undefined4 in_stack_fffffffffffffdac;
  _SECURITY_ATTRIBUTES *in_stack_fffffffffffffdb0;
  bool *in_stack_fffffffffffffdb8;
  wchar_t local_238 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_278;
  if ((param_3 & 0xc000000000000000) != 0) {
                    /* WARNING: Subroutine does not return */
    details::in1diag3::_FailFastImmediate_Unexpected();
  }
  _Var2 = 0x104;
  StringCopyWorkerW(local_238,0x104,(size_t *)CONCAT71(in_register_00000081,param_2),
                    (STRSAFE_PCNZWCH)param_1,
                    CONCAT44(in_stack_fffffffffffffdac,in_stack_fffffffffffffda8));
  StringCchCatW((ushort *)local_238,_Var2,(ushort *)L"_p0");
  uVar3 = (uint)param_3 & 0x7fffffff;
  _Var2 = (__uint64)uVar3;
  pcVar5 = (char *)0x1;
  if ((param_3 & 0x7fffffff) != 0) {
    pcVar5 = (char *)(ulonglong)uVar3;
  }
  lVar1 = semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
          ::create((semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
                    *)this,uVar3,(long)pcVar5,(ushort *)local_238,in_stack_fffffffffffffda8,
                   in_stack_fffffffffffffdb0,in_stack_fffffffffffffdb8);
  if (lVar1 < 0) {
    uVar3 = 0x88;
  }
  else {
    StringCchCatW((ushort *)local_238,_Var2,(ushort *)L"h");
    uVar4 = (uint)(param_3 >> 0x1f);
    uVar3 = 1;
    if (uVar4 != 0) {
      uVar3 = uVar4;
    }
    pcVar5 = (char *)(ulonglong)uVar3;
    lVar1 = semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
            ::create((semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
                      *)(this + 8),uVar4,uVar3,(ushort *)local_238,in_stack_fffffffffffffda8,
                     in_stack_fffffffffffffdb0,in_stack_fffffffffffffdb8);
    if (-1 < lVar1) {
      return 0;
    }
    uVar3 = 0x8d;
  }
  details::in1diag3::Return_Hr(unaff_retaddr,uVar3,pcVar5,lVar1);
  return lVar1;
}



===== Destroy @ 180005e28 =====

/* public: static void __cdecl wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64) */

void __cdecl
wil::details::DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy
          (_TP_TIMER *param_1)

{
  SetThreadpoolTimer(param_1,(PFILETIME)0x0,0,0);
  WaitForThreadpoolTimerCallbacks(param_1,1);
                    /* WARNING: Could not recover jumptable at 0x000180005e61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CloseThreadpoolTimer(param_1);
  return;
}



===== Destroy @ 180005e74 =====

/* public: void __cdecl wil::details_abi::SemaphoreValue::Destroy(void) __ptr64 */

void __thiscall wil::details_abi::SemaphoreValue::Destroy(SemaphoreValue *this)

{
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *)this,(void *)0x0);
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *)(this + 8),(void *)0x0);
  return;
}



===== EnsureCoalescedTimer_SetTimer @ 180005e9c =====

/* void __cdecl wil::details::EnsureCoalescedTimer_SetTimer(class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<struct _TP_TIMER * __ptr64,void
   (__cdecl*)(struct _TP_TIMER * __ptr64),&public: static void __cdecl
   wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct _TP_TIMER * __ptr64,struct _TP_TIMER *
   __ptr64,0,std::nullptr_t> > > & __ptr64,bool & __ptr64,__int64) */

void __cdecl
wil::details::EnsureCoalescedTimer_SetTimer
          (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
           *param_1,bool *param_2,__int64 param_3)

{
  _FILETIME local_res8 [4];
  
  if (*(PTP_TIMER *)param_1 != (PTP_TIMER)0x0) {
    local_res8[0] = (_FILETIME)(param_3 * -10000);
    SetThreadpoolTimer(*(PTP_TIMER *)param_1,local_res8,0,
                       (uint)((ulonglong)param_3 >> 2) & 0x3fffffff);
    *param_2 = true;
  }
  return;
}



===== EnsureStateData @ 180005ee4 =====

/* private: bool __cdecl wil::details::FeatureStateManager::EnsureStateData(void) __ptr64 */

bool __thiscall wil::details::FeatureStateManager::EnsureStateData(FeatureStateManager *this)

{
  long lVar1;
  ulonglong uVar2;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *local_res8;
  last_error_context local_res10 [8];
  
  if (*(longlong *)(this + 0x18) == 0) {
    last_error_context::last_error_context(local_res10);
    if (*(longlong *)(this + 0x18) == 0) {
      if (*(longlong *)(this + 0x10) == 0) {
        local_res8 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
        lVar1 = details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Acquire
                          (*(char **)(this + 8),&local_res8);
        if ((-1 < lVar1) && (*(longlong *)(this + 0x10) == 0)) {
          *(ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **)(this + 0x10) =
               local_res8;
        }
      }
      uVar2 = -(ulonglong)(*(longlong *)(this + 0x10) != 0) & *(longlong *)(this + 0x10) + 0x20U;
    }
    else {
      uVar2 = 0;
    }
    AcquireSRWLockExclusive((PSRWLOCK)(this + 0x20));
    if (*(longlong *)(this + 0x18) == 0) {
      *(ulonglong *)(this + 0x18) = uVar2;
    }
    local_res8 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)(this + 0x20);
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
    last_error_context::~last_error_context(local_res10);
  }
  return *(longlong *)(this + 0x18) != 0;
}



===== EnsureSubscribedToFeatureConfigurationChanges @ 180005fb0 =====

/* unsigned int __cdecl wil::details::EnsureSubscribedToFeatureConfigurationChanges(void) */

uint __cdecl wil::details::EnsureSubscribedToFeatureConfigurationChanges(void)

{
  uint uVar1;
  
  uVar1 = DAT_180015304;
  if (DAT_180015304 == 0) {
    uVar1 = EnabledStateManager::EnsureSubscribedToFeatureConfigurationChangesImpl
                      ((EnabledStateManager *)&g_enabledStateManager);
  }
  return uVar1;
}



===== EnsureSubscribedToFeatureConfigurationChangesImpl @ 180005fd8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: unsigned int __cdecl
   wil::details::EnabledStateManager::EnsureSubscribedToFeatureConfigurationChangesImpl(void)
   __ptr64 */

uint __thiscall
wil::details::EnabledStateManager::EnsureSubscribedToFeatureConfigurationChangesImpl
          (EnabledStateManager *this)

{
  EnabledStateManager *SRWLock;
  EnabledStateManager *pEVar1;
  code *pcVar2;
  uint uVar3;
  EnabledStateManager *local_res8;
  
  if (*this == (EnabledStateManager)0x0) {
    uVar3 = 0;
  }
  else {
    SRWLock = this + 8;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    pEVar1 = this + 0x20;
    local_res8 = SRWLock;
    if (*(longlong *)pEVar1 == 0) {
      *(longlong *)pEVar1 = 0;
      pcVar2 = g_wil_details_internalSubscribeFeatureStateChangeNotification;
      if ((g_wil_details_internalSubscribeFeatureStateChangeNotification != (code *)0x0) ||
         (pcVar2 = g_wil_details_apiSubscribeFeatureStateChangeNotification,
         g_wil_details_apiSubscribeFeatureStateChangeNotification != (code *)0x0)) {
        (*pcVar2)(pEVar1,<lambda_fee8cea507d2413a58be13acfb66740a>::<lambda_invoker_cdecl>,this);
      }
      if (*(longlong *)pEVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
        *(undefined4 *)(this + 0x1c) = 1;
      }
    }
    else {
      uVar3 = *(uint *)(this + 0x1c);
    }
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
  }
  return uVar3;
}



===== FailFast_Unexpected @ 180006078 =====

/* void __cdecl wil::details::in1diag3::FailFast_Unexpected(void * __ptr64,unsigned int,char const *
   __ptr64) */

void __cdecl wil::details::in1diag3::FailFast_Unexpected(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  long in_stack_ffffffffffffffe8;
  
  ReportFailure_Hr<3>(param_1,0xc37,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h",
                      in_R9,in_stack_ffffffffffffffd8,unaff_retaddr,in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== FindInsertionPointOrIncrement @ 1800060a0 =====

/* private: unsigned char * __ptr64 __cdecl
   wil::details_abi::RawUsageIndex::FindInsertionPointOrIncrement(struct
   wil::details_abi::UsageIndexProperty & __ptr64,unsigned char * __ptr64,void * __ptr64,unsigned
   __int64,unsigned int) __ptr64 */

uchar * __thiscall
wil::details_abi::RawUsageIndex::FindInsertionPointOrIncrement
          (RawUsageIndex *this,UsageIndexProperty *param_1,uchar *param_2,void *param_3,
          __uint64 param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  uchar *puVar5;
  RawUsageIndex RVar6;
  uchar *local_res8;
  undefined2 local_48;
  RawUsageIndex local_46;
  int local_44;
  undefined2 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_48 = *(undefined2 *)(this + 6);
  RVar6 = (RawUsageIndex)0x0;
  iVar2 = -1;
  local_46 = this[8];
  local_44 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (*(longlong *)(this + 0x10) == 0) {
    for (uVar4 = 0; uVar4 < *(uint *)(param_1 + 4); uVar4 = uVar4 + 1) {
      local_res8 = param_2;
      bVar1 = UsageIndexProperty::Read
                        ((UsageIndexProperty *)&local_48,&local_res8,*(uchar **)(this + 0x20));
      if (!bVar1) {
        UsageIndexProperty::UpdateCount(param_1,uVar4);
        break;
      }
      iVar2 = UsageIndexProperty::Compare((UsageIndexProperty *)&local_48,param_3,param_4);
      if (iVar2 < 1) break;
      param_2 = local_res8;
    }
  }
  else {
    uVar3 = (ulonglong)(*(longlong *)(this + 0x20) - (longlong)param_2) /
            *(ulonglong *)(this + 0x10);
    if (uVar3 < *(uint *)(param_1 + 4)) {
      UsageIndexProperty::UpdateCount(param_1,(uint)uVar3);
    }
    puVar5 = param_2 + (ulonglong)*(uint *)(param_1 + 4) * *(longlong *)(this + 0x10);
    param_2 = LowerBound(this,param_2,(ulonglong)*(uint *)(param_1 + 4),param_3,param_4);
    if (puVar5 <= param_2) {
      return param_2;
    }
    local_res8 = param_2;
    UsageIndexProperty::Read((UsageIndexProperty *)&local_48,&local_res8,*(uchar **)(this + 0x20));
    iVar2 = UsageIndexProperty::Compare((UsageIndexProperty *)&local_48,param_3,param_4);
  }
  if (iVar2 != 0) {
    return param_2;
  }
  if (local_46 == (RawUsageIndex)0x0) {
    if (this[0x38] == (RawUsageIndex)0x0) goto LAB_1800061e6;
  }
  else {
    UsageIndexProperty::UpdateCount((UsageIndexProperty *)&local_48,local_44 + param_5);
  }
  RVar6 = (RawUsageIndex)0x1;
LAB_1800061e6:
  this[0x38] = RVar6;
  return (uchar *)0x0;
}



===== FlushUsage @ 180006218 =====

/* public: void __cdecl wil::details::FeatureStateManager::FlushUsage(void) __ptr64 */

void __thiscall wil::details::FeatureStateManager::FlushUsage(FeatureStateManager *this)

{
  bool bVar1;
  
  bVar1 = ProcessShutdownInProgress();
  if (!bVar1) {
    bVar1 = EnsureStateData(this);
    if (bVar1) {
      details_abi::SubscriptionList::OnSignaled
                ((SubscriptionList *)(*(srwlock **)(this + 0x18) + 200),*(srwlock **)(this + 0x18));
      details_abi::FeatureStateData::RecordUsage(*(FeatureStateData **)(this + 0x18));
    }
  }
  return;
}



===== FreeProcessHeap @ 18000625c =====

/* void __cdecl wil::details::FreeProcessHeap(void * __ptr64) */

void __cdecl wil::details::FreeProcessHeap(void *param_1)

{
  HANDLE hHeap;
  
  hHeap = GetProcessHeap();
                    /* WARNING: Could not recover jumptable at 0x00018000627e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapFree(hHeap,0,param_1);
  return;
}



===== GetContextAndNotifyFailure @ 180006290 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: static void __cdecl
   wil::details::ThreadFailureCallbackHolder::GetContextAndNotifyFailure(struct wil::FailureInfo *
   __ptr64,char * __ptr64,unsigned __int64) */

void __cdecl
wil::details::ThreadFailureCallbackHolder::GetContextAndNotifyFailure
          (FailureInfo *param_1,char *param_2,__uint64 param_3)

{
  ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *pTVar1;
  bool bVar2;
  byte bVar3;
  DWORD DVar4;
  bool bVar5;
  byte bVar6;
  DWORD *pDVar7;
  longlong lVar8;
  
  bVar5 = false;
  *param_2 = '\0';
  pTVar1 = g_pThreadFailureCallbacks;
  bVar6 = 0;
  if (g_pThreadFailureCallbacks !=
      (ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *)0x0) {
    DVar4 = GetCurrentThreadId();
    for (pDVar7 = *(DWORD **)(pTVar1 + ((ulonglong)DVar4 + ((ulonglong)DVar4 / 10) * -10) * 8);
        pDVar7 != (DWORD *)0x0; pDVar7 = *(DWORD **)(pDVar7 + 2)) {
      if (*pDVar7 == DVar4) {
        pDVar7 = pDVar7 + 4;
        goto LAB_180006312;
      }
    }
    pDVar7 = (DWORD *)0x0;
LAB_180006312:
    if ((pDVar7 != (DWORD *)0x0) && (*(longlong *)pDVar7 != 0)) {
      *param_2 = '\0';
      bVar2 = GetThreadContext(param_1,*(ThreadFailureCallbackHolder **)pDVar7,param_2,param_3);
      if (bVar2) {
        *(char **)(param_1 + 0x48) = param_2;
      }
      lVar8 = *(longlong *)pDVar7;
      do {
        bVar3 = (**(code **)**(undefined8 **)(lVar8 + 8))(*(undefined8 **)(lVar8 + 8),param_1);
        lVar8 = *(longlong *)(lVar8 + 0x10);
        bVar6 = bVar6 | bVar3;
      } while (lVar8 != 0);
    }
  }
  if (g_pfnTelemetryCallback != (_func_void_bool_FailureInfo_ptr *)0x0) {
    if ((bVar6 != 0) || (((byte)param_1[4] & 2) != 0)) {
      bVar5 = true;
    }
    (*g_pfnTelemetryCallback)(bVar5,param_1);
  }
  return;
}



===== GetContextAndNotifyFailure @ 1800063a0 =====

/* void __cdecl wil::details::GetContextAndNotifyFailure(struct wil::FailureInfo * __ptr64,char *
   __ptr64,unsigned __int64) */

void __cdecl
wil::details::GetContextAndNotifyFailure(FailureInfo *param_1,char *param_2,__uint64 param_3)

{
  int iVar1;
  DWORD DVar2;
  ThreadLocalData *this;
  undefined1 uVar3;
  FailureInfo *pFVar4;
  int iVar5;
  
  pFVar4 = param_1;
  ThreadFailureCallbackHolder::GetContextAndNotifyFailure(param_1,param_2,param_3);
  uVar3 = SUB81(pFVar4,0);
  DVar2 = GetCurrentThreadId();
  if (`void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l2::lastThread != DVar2)
  {
    LOCK();
    iVar1 = `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth + 1;
    UNLOCK();
    iVar5 = `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth + 1;
    `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth = iVar1;
    if (iVar5 < 4) {
      `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l2::lastThread = DVar2;
      this = details_abi::GetThreadLocalDataCache((bool)uVar3);
      if (this != (ThreadLocalData *)0x0) {
        details_abi::ThreadLocalData::SetLastError(this,param_1);
      }
      `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l2::lastThread = 0;
    }
    LOCK();
    `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth =
         `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth + -1;
    UNLOCK();
  }
  return;
}



===== GetFailureLogString @ 180006414 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl wil::GetFailureLogString(unsigned short * __ptr64,unsigned __int64,struct
   wil::FailureInfo const & __ptr64) */

long __cdecl wil::GetFailureLogString(ushort *param_1,__uint64 param_2,FailureInfo *param_3)

{
  ushort *puVar1;
  int iVar2;
  code *pcVar3;
  char *pcVar4;
  ushort *puVar5;
  char *pcVar6;
  undefined1 auStackY_278 [32];
  WCHAR local_238 [256];
  ulonglong local_38;
  
  pcVar3 = g_pfnResultLoggingCallback;
  local_38 = __security_cookie ^ (ulonglong)auStackY_278;
  if (param_2 == 0) {
    return 0;
  }
  if (param_1 == (ushort *)0x0) {
    return 0;
  }
  *param_1 = 0;
  if (((pcVar3 != (code *)0x0) && (details::g_resultMessageCallbackSet != false)) &&
     ((*pcVar3)(param_3,param_1,param_2), *param_1 != 0)) {
    return 0;
  }
  iVar2 = *(int *)param_3;
  if (iVar2 == 0) {
    pcVar6 = "Exception";
  }
  else {
    if (iVar2 == 1) {
      pcVar4 = "ReturnHr";
      pcVar6 = "ReturnNt";
    }
    else {
      if (iVar2 != 2) {
        pcVar6 = "";
        if (iVar2 == 3) {
          pcVar6 = "FailFast";
        }
        goto LAB_1800064df;
      }
      pcVar4 = "LogHr";
      pcVar6 = "LogNt";
    }
    if (((byte)param_3[4] & 8) == 0) {
      pcVar6 = pcVar4;
    }
  }
LAB_1800064df:
  memset(local_238,0,0x200);
  if (((byte)param_3[4] & 8) == 0) {
    FormatMessageW(0x1200,(LPCVOID)0x0,*(DWORD *)(param_3 + 8),0x400,local_238,0x100,(va_list *)0x0)
    ;
  }
  else if (details::g_pfnFormatNtStatusMsg != (_func_void_long_ushort_ptr_ulong *)0x0) {
    (*details::g_pfnFormatNtStatusMsg)(*(long *)(param_3 + 0xc),(ushort *)local_238,0x100);
  }
  puVar1 = param_1 + param_2;
  if (*(longlong *)(param_3 + 0x38) == 0) {
    puVar5 = details::LogStringPrintf
                       (param_1,puVar1,(ushort *)L"%hs!%p: ",*(undefined8 *)(param_3 + 0x80));
  }
  else {
    puVar5 = details::LogStringPrintf(param_1,puVar1,(ushort *)L"%hs(%u)\\%hs!%p: ");
  }
  if (*(longlong *)(param_3 + 0x90) != 0) {
    puVar5 = details::LogStringPrintf(puVar5,puVar1,(ushort *)L"(caller: %p) ");
  }
  GetCurrentThreadId();
  puVar5 = details::LogStringPrintf(puVar5,puVar1,(ushort *)L"%hs(%d) tid(%x) %08X %ws",pcVar6);
  if (((*(longlong *)(param_3 + 0x18) != 0) || (*(longlong *)(param_3 + 0x48) != 0)) ||
     (*(longlong *)(param_3 + 0x30) != 0)) {
    puVar5 = details::LogStringPrintf(puVar5,puVar1,(ushort *)L"    ");
    if (*(longlong *)(param_3 + 0x18) != 0) {
      puVar5 = details::LogStringPrintf(puVar5,puVar1,(ushort *)L"Msg:[%ws] ");
    }
    if (*(longlong *)(param_3 + 0x48) != 0) {
      puVar5 = details::LogStringPrintf(puVar5,puVar1,(ushort *)L"CallContext:[%hs] ");
    }
    if (*(longlong *)(param_3 + 0x28) == 0) {
      if (*(longlong *)(param_3 + 0x30) == 0) {
        details::LogStringPrintf(puVar5,puVar1,(ushort *)L"\n");
      }
      else {
        details::LogStringPrintf(puVar5,puVar1,(ushort *)L"[%hs]\n");
      }
    }
    else {
      details::LogStringPrintf(puVar5,puVar1,(ushort *)L"[%hs(%hs)]\n");
    }
  }
  return 0;
}



===== GetLastErrorFail @ 1800066dc =====

/* unsigned long __cdecl wil::details::GetLastErrorFail(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64) */

ulong __cdecl
wil::details::GetLastErrorFail
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (DVar1 == 0) {
    ReportFailure_Hr<2>(param_1,param_2,param_3,(char *)0x0,(char *)0x0,param_6,-0x7ff8fd64);
    DVar1 = 0x29c;
  }
  return DVar1;
}



===== GetLastErrorFailHr @ 180006748 =====

/* long __cdecl wil::details::GetLastErrorFailHr(void) */

long __cdecl wil::details::GetLastErrorFailHr(void)

{
  ulong uVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffe8;
  
  uVar1 = GetLastErrorFail((void *)0x0,0,(char *)0x0,in_R9,in_stack_ffffffffffffffe8,unaff_retaddr);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  return uVar1;
}



===== GetSize @ 18000677c =====

/* public: unsigned __int64 __cdecl wil::details_abi::UsageIndexProperty::GetSize(void)const __ptr64
    */

__uint64 __thiscall wil::details_abi::UsageIndexProperty::GetSize(UsageIndexProperty *this)

{
  ulonglong uVar1;
  
  if (*(short *)this == 0) {
    uVar1 = (ulonglong)*(ushort *)(this + 8) + 2;
  }
  else {
    uVar1 = (ulonglong)*(ushort *)this;
  }
  if (this[2] == (UsageIndexProperty)0x1) {
    return uVar1 + 2;
  }
  if (this[2] == (UsageIndexProperty)0x2) {
    uVar1 = uVar1 + 4;
  }
  return uVar1;
}



===== GetThreadContext @ 1800067b0 =====

/* public: static bool __cdecl wil::details::ThreadFailureCallbackHolder::GetThreadContext(struct
   wil::FailureInfo * __ptr64,class wil::details::ThreadFailureCallbackHolder * __ptr64,char *
   __ptr64,unsigned __int64) */

bool __cdecl
wil::details::ThreadFailureCallbackHolder::GetThreadContext
          (FailureInfo *param_1,ThreadFailureCallbackHolder *param_2,char *param_3,__uint64 param_4)

{
  int *piVar1;
  undefined8 uVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  char *_DstSize;
  longlong lVar6;
  char *_MaxCount;
  char *pcVar7;
  
  bVar3 = false;
  *param_3 = '\0';
  if (param_2 != (ThreadFailureCallbackHolder *)0x0) {
    bVar3 = GetThreadContext(param_1,*(ThreadFailureCallbackHolder **)(param_2 + 0x10),param_3,
                             param_4);
    piVar1 = *(int **)(param_2 + 0x20);
    if (piVar1 != (int *)0x0) {
      if (*piVar1 == 0) {
        LOCK();
        UNLOCK();
        iVar4 = s_telemetryId + 1;
        s_telemetryId = s_telemetryId + 1;
        *piVar1 = iVar4;
      }
      if (*(int *)(param_1 + 0x50) == 0) {
        uVar2 = *(undefined8 *)(piVar1 + 2);
        *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)piVar1;
        *(undefined8 *)(param_1 + 0x58) = uVar2;
        *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(piVar1 + 4);
      }
      uVar2 = *(undefined8 *)(piVar1 + 2);
      *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)piVar1;
      *(undefined8 *)(param_1 + 0x70) = uVar2;
      *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(piVar1 + 4);
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (param_3[lVar5] != '\0');
      pcVar7 = param_3 + lVar5;
      if (2 < (longlong)(param_3 + (param_4 - (longlong)pcVar7))) {
        *pcVar7 = '\\';
        pcVar7 = pcVar7 + 1;
        lVar5 = -1;
        do {
          lVar6 = lVar5;
          lVar5 = lVar6 + 1;
        } while (*(char *)((longlong)*(void **)(piVar1 + 2) + lVar5) != '\0');
        _DstSize = param_3 + (param_4 - (longlong)pcVar7);
        _MaxCount = (char *)(lVar6 + 2);
        if (_DstSize <= _MaxCount) {
          _MaxCount = _DstSize;
        }
        memcpy_s(pcVar7,(rsize_t)_DstSize,*(void **)(piVar1 + 2),(rsize_t)_MaxCount);
        pcVar7[(longlong)(_MaxCount + -1)] = '\0';
      }
      bVar3 = true;
    }
  }
  return bVar3;
}



===== GetThreadLocalDataCache @ 1800068a8 =====

/* struct wil::details_abi::ThreadLocalData * __ptr64 __cdecl
   wil::details_abi::GetThreadLocalDataCache(bool) */

ThreadLocalData * __cdecl wil::details_abi::GetThreadLocalDataCache(bool param_1)

{
  ProcessLocalStorage<wil::details_abi::ProcessLocalData> *pPVar1;
  long lVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  ThreadLocalData *pTVar5;
  ulonglong uVar6;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *local_res10 [3];
  
  pPVar1 = g_pProcessLocalData;
  if (g_pProcessLocalData != (ProcessLocalStorage<wil::details_abi::ProcessLocalData> *)0x0) {
    if (*(longlong *)(g_pProcessLocalData + 8) == 0) {
      local_res10[0] = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
      lVar2 = ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Acquire
                        (*(char **)g_pProcessLocalData,local_res10);
      if ((-1 < lVar2) && (*(longlong *)(pPVar1 + 8) == 0)) {
        *(ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **)(pPVar1 + 8) =
             local_res10[0];
      }
    }
    uVar6 = -(ulonglong)(*(longlong *)(pPVar1 + 8) != 0) & *(longlong *)(pPVar1 + 8) + 0x20U;
    if (uVar6 != 0) {
      DVar3 = GetCurrentThreadId();
      for (pDVar4 = *(DWORD **)(uVar6 + 8 + ((ulonglong)DVar3 + ((ulonglong)DVar3 / 10) * -10) * 8);
          pDVar4 != (DWORD *)0x0; pDVar4 = *(DWORD **)(pDVar4 + 2)) {
        if (*pDVar4 == DVar3) {
          pTVar5 = (ThreadLocalData *)(pDVar4 + 4);
          if (pTVar5 == (ThreadLocalData *)0x0) {
            return (ThreadLocalData *)0x0;
          }
          if (*(longlong *)(pDVar4 + 6) == 0) {
            *(ulonglong *)(pDVar4 + 6) = uVar6 + 4;
            return pTVar5;
          }
          return pTVar5;
        }
      }
    }
  }
  return (ThreadLocalData *)0x0;
}



===== GetValueFromSemaphore @ 180006974 =====

/* private: static long __cdecl wil::details_abi::SemaphoreValue::GetValueFromSemaphore(void *
   __ptr64,long * __ptr64) */

long __cdecl wil::details_abi::SemaphoreValue::GetValueFromSemaphore(void *param_1,long *param_2)

{
  DWORD DVar1;
  long lVar2;
  BOOL BVar3;
  uint uVar4;
  LPLONG in_R8;
  void *unaff_retaddr;
  long local_res18 [2];
  long local_res20 [2];
  
  DVar1 = WaitForSingleObject(param_1,0);
  if (DVar1 == 0xffffffff) {
    uVar4 = 0x99;
    goto LAB_18000699c;
  }
  if ((DVar1 == 0) || (DVar1 == 0x102)) {
    local_res18[0] = 0;
    if (DVar1 == 0) {
      in_R8 = local_res18;
      BVar3 = ReleaseSemaphore(param_1,1,in_R8);
      if (BVar3 == 0) {
        uVar4 = 0xa2;
LAB_18000699c:
        lVar2 = details::in1diag3::Return_GetLastError(unaff_retaddr,uVar4,(char *)in_R8);
        return lVar2;
      }
      local_res18[0] = local_res18[0] + 1;
      in_R8 = (LPLONG)0x0;
      BVar3 = ReleaseSemaphore(param_1,1,(LPLONG)0x0);
      if ((BVar3 == 0) && (DVar1 = GetLastError(), DVar1 == 0x12a)) {
LAB_180006ab6:
        *param_2 = local_res18[0];
        return 0;
      }
      uVar4 = 0xa7;
    }
    else {
      local_res20[0] = 0;
      in_R8 = local_res20;
      BVar3 = ReleaseSemaphore(param_1,1,in_R8);
      if (BVar3 == 0) {
        uVar4 = 0xb1;
        goto LAB_18000699c;
      }
      if (local_res20[0] == 0) {
        in_R8 = (LPLONG)0x0;
        BVar3 = ReleaseSemaphore(param_1,1,(LPLONG)0x0);
        if ((BVar3 == 0) && (DVar1 = GetLastError(), DVar1 == 0x12a)) {
          DVar1 = WaitForSingleObject(param_1,0);
          if (DVar1 == 0xffffffff) {
            uVar4 = 0xb8;
            goto LAB_18000699c;
          }
          if (DVar1 == 0) goto LAB_180006ab6;
          uVar4 = 0xb9;
        }
        else {
          uVar4 = 0xb5;
        }
      }
      else {
        uVar4 = 0xb2;
      }
    }
  }
  else {
    uVar4 = 0x9a;
  }
  details::in1diag3::Return_Hr(unaff_retaddr,uVar4,(char *)in_R8,-0x7fff0001);
  return -0x7fff0001;
}



===== HrToNtStatus @ 180006aec =====

/* long __cdecl wil::details::HrToNtStatus(long) */

long __cdecl wil::details::HrToNtStatus(long param_1)

{
  if (param_1 < -0x7ff8ff15) {
    if (param_1 == -0x7ff8ff16) {
      return -0x7ffffffb;
    }
    if (param_1 < -0x7ff8ffa8) {
      if (param_1 == -0x7ff8ffa9) {
        return -0x3ffffff3;
      }
      if (param_1 == -0x7fffbffb) {
        return -0x3fffffff;
      }
      if (param_1 == -0x7ff8ffff) {
        return -0x3ffffffe;
      }
      if (param_1 == -0x7ff8fffe) {
        return -0x3fffffcc;
      }
      if (param_1 == -0x7ff8fffd) {
        return -0x3fffffc6;
      }
      if (param_1 == -0x7ff8fff2) {
        return -0x3fffffe9;
      }
    }
    else {
      if (param_1 == -0x7ff8ff90) {
        return -0x3fffff81;
      }
      if (param_1 == -0x7ff8ff86) {
        return -0x3fffffdd;
      }
      if (param_1 == -0x7ff8ff85) {
        return -0x3fffffcd;
      }
      if (param_1 == -0x7ff8ff82) {
        return -0x3ffffecb;
      }
    }
  }
  else if (param_1 < -0x7ff8fb81) {
    if (param_1 == -0x7ff8fb82) {
      return -0x3fffffa7;
    }
    if (param_1 == -0x7ff8fdea) {
      return -0x3fffff6b;
    }
    if (param_1 == -0x7ff8fdc2) {
      return -0x3fffffdb;
    }
    if (param_1 == -0x7ff8fdba) {
      return -0x3ffffe9f;
    }
    if (param_1 == -0x7ff8fdb9) {
      return -0x3ffffe9d;
    }
    if (param_1 == -0x7ff8fd8e) {
      return -0x3ffffd8d;
    }
  }
  else {
    if (param_1 == -0x7ff8faf4) {
      return -0x3ffffbd5;
    }
    if (param_1 == -0x7ff8fab1) {
      return -0x3fffff1b;
    }
    if (param_1 == -0x7ff8fa47) {
      return -0x3fff5f7d;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  if (((uint)param_1 >> 0x1c & 1) != 0) {
    return param_1 & 0xefffffff;
  }
  if ((param_1 & 0x1fff0000U) == 0x70000) {
    if ((param_1 & 0xffffU) == 0) {
      return 0;
    }
    return param_1 & 0xffffU | 0xc0070000;
  }
  if ((param_1 & 0x1fff0000U) != 0x90000) {
    return -0x3fffff1b;
  }
  if (param_1 < 1) {
    return param_1;
  }
  return param_1 & 0xffffU | 0xc0090000;
}



===== IsDrtmBoot @ 180006cbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl IsDrtmBoot(void) */

uchar __cdecl IsDrtmBoot(void)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = NtQuerySystemInformation(0x5a,&local_38,0x20);
  if (iVar2 < 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = (byte)uStack_20 >> 3 & 1;
  }
  return bVar1;
}



===== IsFeatureConfigured @ 180006d24 =====

/* bool __cdecl wil::details::IsFeatureConfigured(struct wil_FeatureState * __ptr64,unsigned
   int,bool,enum wil_FeatureStore,int * __ptr64) */

bool __cdecl
wil::details::IsFeatureConfigured
          (wil_FeatureState *param_1,uint param_2,bool param_3,wil_FeatureStore param_4,int *param_5
          )

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  wil_details_FeatureStateCache *pwVar5;
  ulonglong uVar6;
  bool bVar7;
  uint local_res20 [2];
  undefined *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  wil_details_FeatureStateCache *local_28;
  
  pwVar5 = &`bool___cdecl_wil::details::IsFeatureConfigured(wil_FeatureState*___ptr64,unsigned_int,bool,wil_FeatureStore,int*___ptr64)'
            ::__l2::machineStoreProbe;
  if (param_4 != 0) {
    pwVar5 = &`bool___cdecl_wil::details::IsFeatureConfigured(wil_FeatureState*___ptr64,unsigned_int,bool,wil_FeatureStore,int*___ptr64)'
              ::__l2::userStoreProbe;
  }
  uVar1 = *(uint *)pwVar5;
  uVar6 = (ulonglong)uVar1;
  if (((byte)uVar1 & 3) == 2) {
    return false;
  }
  if ((uVar1 & 2) != 0) {
    iVar4 = wil_QueryFeatureState((uint *)param_1,param_2,(uint)param_3,uVar6,(uint *)0x0,param_5);
    return iVar4 != 0;
  }
  local_res20[0] = 1;
  uVar3 = EnsureSubscribedToFeatureConfigurationChanges();
  iVar4 = wil_QueryFeatureState((uint *)param_1,param_2,(uint)param_3,uVar6,local_res20,param_5);
  bVar7 = iVar4 != 0;
  LOCK();
  uVar1 = *(uint *)pwVar5;
  *(uint *)pwVar5 = (local_res20[0] != 0) + 6;
  UNLOCK();
  if (local_res20[0] != 0) {
    return bVar7;
  }
  if ((uVar1 & 4) != 0) {
    return bVar7;
  }
  if (g_enabledStateManager == (shutdown_aware_object<wil::details::EnabledStateManager>)0x0) {
    return bVar7;
  }
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1800152f0);
  local_38 = &DAT_1800152f0;
  if ((uVar3 != 0) && (uVar3 == DAT_180015304)) {
    local_2c = 0;
    local_30 = 0;
    local_28 = pwVar5;
    bVar2 = details_abi::heap_buffer::push_back((heap_buffer *)&DAT_180015338,&local_30,0x10);
    if (bVar2) goto LAB_180006e34;
  }
  LOCK();
  *(uint *)pwVar5 = *(uint *)pwVar5 & 0xfffff7c1;
  UNLOCK();
LAB_180006e34:
  unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              *)&local_38);
  return bVar7;
}



===== Iterate @ 180006e80 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: bool __cdecl wil::details_abi::RawUsageIndex::Iterate(class wistd::function<bool
   __cdecl(void * __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned int)>)const
   __ptr64 */

bool __thiscall
wil::details_abi::RawUsageIndex::Iterate
          (RawUsageIndex *this,
          function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
          *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  undefined8 uVar3;
  bool bVar4;
  char cVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined4 local_res8 [2];
  uchar *local_res18;
  ulonglong local_res20;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [24];
  ulonglong *local_a8;
  undefined4 *local_a0;
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined2 local_70;
  RawUsageIndex local_6e;
  undefined4 local_6c;
  ushort local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined2 local_50;
  RawUsageIndex local_4e;
  uint local_4c;
  ushort local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  puVar6 = auStack_c8;
  local_res18 = (uchar *)(*(longlong *)(this + 0x18) + 10);
  local_50 = *(undefined2 *)(this + 2);
  local_4e = this[4];
  local_70 = *(undefined2 *)(this + 6);
  local_6e = this[8];
  local_4c = 0;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_6c = 0;
  local_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  do {
    bVar4 = UsageIndexProperty::Read
                      ((UsageIndexProperty *)&local_50,&local_res18,*(uchar **)(this + 0x20));
    uVar3 = uStack_38;
    if (!bVar4) {
LAB_180006f92:
      *(undefined8 *)(puVar6 + -8) = 0x180006f9a;
      wistd::
      function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
      ::
      ~function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
                (param_2);
      return true;
    }
    uVar7 = 0;
    while ((uVar7 < local_4c &&
           (bVar4 = UsageIndexProperty::Read
                              ((UsageIndexProperty *)&local_70,&local_res18,*(uchar **)(this + 0x20)
                              ), bVar4))) {
      plVar1 = *(longlong **)(param_2 + 0x70);
      local_res8[0] = local_6c;
      local_res20 = (ulonglong)local_68;
      local_88 = uStack_58;
      local_80 = (ulonglong)local_48;
      local_78 = uVar3;
      if (plVar1 == (longlong *)0x0) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(7);
        puVar6 = auStack_c0;
        goto LAB_180006f92;
      }
      local_a0 = local_res8;
      local_a8 = &local_res20;
      cVar5 = (**(code **)(*plVar1 + 0x20))(plVar1,&local_78,&local_80,&local_88);
      if (cVar5 == '\0') {
        wistd::
        function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
        ::
        ~function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
                  (param_2);
        return false;
      }
      uVar7 = uVar7 + 1;
    }
  } while( true );
}



===== LogFailure @ 180006fbc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::LogFailure(void * __ptr64,unsigned int,char const * __ptr64,char const
   * __ptr64,char const * __ptr64,void * __ptr64,enum wil::FailureType,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,bool,unsigned short *
   __ptr64,unsigned __int64,char * __ptr64,unsigned __int64,struct wil::FailureInfo * __ptr64) */

void __cdecl
wil::details::LogFailure
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          FailureType param_7,ResultStatus *param_8,ushort *param_9,bool param_10,ushort *param_11,
          __uint64 param_12,char *param_13,__uint64 param_14,FailureInfo *param_15)

{
  int iVar1;
  long lVar2;
  int iVar3;
  DWORD DVar4;
  long lVar5;
  BOOL BVar6;
  ushort *puVar7;
  bool bVar8;
  
  iVar1 = 0;
  *param_11 = 0;
  *param_13 = '\0';
  lVar5 = *(long *)param_8;
  *(long *)(param_15 + 8) = lVar5;
  *(undefined4 *)(param_15 + 0xc) = *(undefined4 *)(param_8 + 4);
  if (param_7 == 0) {
    iVar1 = RecordException(lVar5);
  }
  else if (param_7 == 1) {
    iVar1 = RecordReturn(lVar5);
  }
  else if (param_7 == 2) {
    if (-1 < lVar5) {
      lVar5 = -0x7ff8fd64;
      ReportFailure_Hr<2>(param_1,param_2,param_3,param_4,param_5,param_6,-0x7ff8fd64);
      *(undefined4 *)(param_15 + 8) = 0x8007029c;
      lVar2 = HrToNtStatus(-0x7ff8fd64);
      *(long *)(param_15 + 0xc) = lVar2;
    }
    iVar1 = RecordLog(lVar5);
  }
  else if (param_7 == 3) {
    iVar1 = RecordFailFast(lVar5);
  }
  puVar7 = (ushort *)0x0;
  *(FailureType *)param_15 = param_7;
  *(undefined4 *)(param_15 + 4) = 0;
  if (*(int *)(param_8 + 8) == 1) {
    *(undefined4 *)(param_15 + 4) = 8;
  }
  LOCK();
  UNLOCK();
  iVar3 = `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
          ::__l2::s_failureId + 1;
  `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
  ::__l2::s_failureId =
       `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
       ::__l2::s_failureId + 1;
  *(int *)(param_15 + 0x10) = iVar3;
  if ((param_9 == (ushort *)0x0) || (*param_9 == 0)) {
    param_9 = puVar7;
  }
  *(ushort **)(param_15 + 0x18) = param_9;
  DVar4 = GetCurrentThreadId();
  *(char **)(param_15 + 0x38) = param_3;
  *(DWORD *)(param_15 + 0x20) = DVar4;
  *(uint *)(param_15 + 0x40) = param_2;
  *(char **)(param_15 + 0x28) = param_5;
  *(void **)(param_15 + 0x88) = param_6;
  *(void **)(param_15 + 0x90) = param_1;
  *(int *)(param_15 + 0x44) = iVar1;
  *(char **)(param_15 + 0x30) = param_4;
  *(undefined8 *)(param_15 + 0x48) = 0;
  *(undefined8 *)(param_15 + 0x68) = 0;
  *(undefined8 *)(param_15 + 0x70) = 0;
  *(undefined8 *)(param_15 + 0x78) = 0;
  *(undefined8 *)(param_15 + 0x50) = 0;
  *(undefined8 *)(param_15 + 0x58) = 0;
  *(undefined8 *)(param_15 + 0x60) = 0;
  if (g_pfnGetModuleName != (_func_char_ptr *)0x0) {
    puVar7 = (ushort *)(*g_pfnGetModuleName)();
  }
  *(ushort **)(param_15 + 0x80) = puVar7;
  if (g_pfnNotifyFailure != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnNotifyFailure)(param_15);
  }
  if (g_pfnGetContextAndNotifyFailure != (_func_void_FailureInfo_ptr_char_ptr___uint64 *)0x0) {
    (*g_pfnGetContextAndNotifyFailure)(param_15,param_13,0x400);
  }
  if (g_pfnLoggingCallback != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnLoggingCallback)(param_15);
  }
  if ((g_pfnOriginateCallback != (_func_void_FailureInfo_ptr *)0x0) &&
     (((byte)param_15[4] & 2) == 0)) {
    (*g_pfnOriginateCallback)(param_15);
  }
  if (-1 < *(int *)(param_15 + 8)) {
    if (param_7 != 3) {
                    /* WARNING: Subroutine does not return */
      in1diag3::_FailFastImmediate_Unexpected();
    }
    *(undefined4 *)(param_15 + 8) = 0x8000ffff;
    lVar5 = HrToNtStatus(-0x7fff0001);
    *(long *)(param_15 + 0xc) = lVar5;
  }
  if (g_fIsDebuggerPresent == false) {
    if (g_pfnIsDebuggerPresent == (_func_bool *)0x0) {
      BVar6 = IsDebuggerPresent();
      bVar8 = BVar6 == 0;
    }
    else {
      bVar8 = (*g_pfnIsDebuggerPresent)();
      bVar8 = !bVar8;
    }
    if (!bVar8) goto LAB_180007211;
  }
  else {
LAB_180007211:
    if (((byte)param_15[4] & 2) == 0) {
      if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
        (*g_pfnResultLoggingCallback)(param_15,param_11,0x800);
      }
      if (*param_11 == 0) {
        GetFailureLogString(param_11,0x800,param_15);
      }
      OutputDebugStringW((LPCWSTR)param_11);
      goto LAB_180007286;
    }
  }
  if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
    (*g_pfnResultLoggingCallback)(param_15,0,0);
  }
LAB_180007286:
  if (((((byte)param_15[4] & 4) != 0) || (g_fBreakOnFailure != false)) &&
     (g_pfnDebugBreak != (_func_void *)0x0)) {
    (*g_pfnDebugBreak)();
  }
  return;
}



===== LogStringPrintf @ 1800072c8 =====

/* unsigned short * __ptr64 __cdecl wil::details::LogStringPrintf(unsigned short * __ptr64,unsigned
   short const * __ptr64,unsigned short const * __ptr64,...) */

ushort * __cdecl wil::details::LogStringPrintf(ushort *param_1,ushort *param_2,ushort *param_3,...)

{
  longlong lVar1;
  size_t cchDest;
  undefined8 in_R9;
  undefined8 local_res20;
  
  cchDest = (longlong)param_2 - (longlong)param_1 >> 1;
  if (cchDest != 0) {
    if (cchDest < 0x80000000) {
      local_res20 = in_R9;
      StringVPrintfWorkerW
                ((STRSAFE_LPWSTR)param_1,cchDest,(size_t *)param_3,(STRSAFE_LPCWSTR)param_3,
                 (va_list)&local_res20);
    }
    else {
      *param_1 = 0;
    }
  }
  if (param_2 != param_1) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_1[lVar1] != 0);
    param_1 = param_1 + lVar1;
  }
  return param_1;
}



===== LowerBound @ 180007330 =====

/* private: unsigned char * __ptr64 __cdecl wil::details_abi::RawUsageIndex::LowerBound(unsigned
   char * __ptr64,unsigned __int64,void * __ptr64,unsigned __int64) __ptr64 */

uchar * __thiscall
wil::details_abi::RawUsageIndex::LowerBound
          (RawUsageIndex *this,uchar *param_1,__uint64 param_2,void *param_3,__uint64 param_4)

{
  ulonglong uVar1;
  int iVar2;
  uchar *local_res8;
  undefined2 local_38;
  RawUsageIndex local_36;
  undefined4 local_34;
  undefined2 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_38 = *(undefined2 *)(this + 6);
  local_36 = this[8];
  local_34 = 0;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  while (uVar1 = param_2, uVar1 != 0) {
    param_2 = uVar1 >> 1;
    local_res8 = param_1 + param_2 * *(longlong *)(this + 0x10);
    UsageIndexProperty::Read((UsageIndexProperty *)&local_38,&local_res8,*(uchar **)(this + 0x20));
    iVar2 = UsageIndexProperty::Compare((UsageIndexProperty *)&local_38,param_3,param_4);
    if (0 < iVar2) {
      param_1 = local_res8;
      param_2 = uVar1 + (-1 - param_2);
    }
  }
  return param_1;
}



===== MakeAndInitialize @ 1800073fc =====

/* private: static long __cdecl wil::details_abi::ProcessLocalStorageData<struct
   wil::details_abi::ProcessLocalData>::MakeAndInitialize(unsigned short const * __ptr64,class
   wil::unique_any_t<class wil::mutex_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void
   __cdecl wil::details::CloseHandle(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> >,struct wil::err_returncode_policy> >
   && __ptr64,class wil::details_abi::ProcessLocalStorageData<struct
   wil::details_abi::ProcessLocalData> * __ptr64 * __ptr64) */

long __cdecl
wil::details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::MakeAndInitialize
          (ushort *param_1,
          unique_any_t<wil::mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>_>
          *param_2,ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  bool bVar3;
  long lVar4;
  void *pvVar5;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **ppPVar6;
  void *unaff_retaddr;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  *param_3 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
  ppPVar6 = param_3;
  pvVar5 = details::ProcessHeapAlloc(8,0x78);
  wistd::unique_ptr<void,wil::process_heap_deleter>::
  unique_ptr<void,wil::process_heap_deleter><1,void>
            ((unique_ptr<void,wil::process_heap_deleter> *)local_res18,pvVar5);
  bVar3 = wistd::operator==<void,wil::process_heap_deleter>(local_res18);
  if (bVar3) {
    details::in1diag3::Return_Hr(unaff_retaddr,0x148,(char *)ppPVar6,-0x7ff8fff2);
    if (local_res18[0] != (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0)
    {
      details::FreeProcessHeap(local_res18[0]);
    }
    lVar4 = -0x7ff8fff2;
  }
  else {
    local_28 = 0;
    uStack_20 = 0;
    if (((ulonglong)local_res18[0] & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFastImmediate_Unexpected();
    }
    lVar4 = SemaphoreValue::CreateFromValueInternal
                      ((SemaphoreValue *)&local_28,param_1,SUB81(ppPVar6,0),
                       (ulonglong)local_res18[0] >> 2);
    uVar2 = uStack_20;
    uVar1 = local_28;
    if (lVar4 < 0) {
      details::in1diag3::Return_Hr(unaff_retaddr,0x14b,(char *)ppPVar6,lVar4);
      SemaphoreValue::~SemaphoreValue((SemaphoreValue *)&local_28);
      if (local_res18[0] !=
          (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0) {
        details::FreeProcessHeap(local_res18[0]);
      }
    }
    else {
      *(undefined4 *)local_res18[0] = 1;
      *(undefined8 *)(local_res18[0] + 8) = *(undefined8 *)param_2;
      *(undefined8 *)param_2 = 0;
      local_28 = 0;
      *(undefined8 *)(local_res18[0] + 0x10) = uVar1;
      uStack_20 = 0;
      *(undefined8 *)(local_res18[0] + 0x18) = uVar2;
      memset(local_res18[0] + 0x20,0,0x58);
      *(undefined2 *)(local_res18[0] + 0x20) = 0x58;
      *(undefined4 *)(local_res18[0] + 0x24) = 1;
      memset(local_res18[0] + 0x28,0,0x50);
      *param_3 = local_res18[0];
      SemaphoreValue::~SemaphoreValue((SemaphoreValue *)&local_28);
      lVar4 = 0;
    }
  }
  return lVar4;
}



===== MakeAndInitialize @ 18000754c =====

/* private: static long __cdecl wil::details_abi::ProcessLocalStorageData<class
   wil::details_abi::FeatureStateData>::MakeAndInitialize(unsigned short const * __ptr64,class
   wil::unique_any_t<class wil::mutex_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void
   __cdecl wil::details::CloseHandle(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> >,struct wil::err_returncode_policy> >
   && __ptr64,class wil::details_abi::ProcessLocalStorageData<class
   wil::details_abi::FeatureStateData> * __ptr64 * __ptr64) */

long __cdecl
wil::details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::MakeAndInitialize
          (ushort *param_1,
          unique_any_t<wil::mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>_>
          *param_2,ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  bool bVar3;
  long lVar4;
  void *pvVar5;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **ppPVar6;
  void *unaff_retaddr;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  *param_3 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
  ppPVar6 = param_3;
  pvVar5 = details::ProcessHeapAlloc(8,0x130);
  wistd::unique_ptr<void,wil::process_heap_deleter>::
  unique_ptr<void,wil::process_heap_deleter><1,void>
            ((unique_ptr<void,wil::process_heap_deleter> *)local_res18,pvVar5);
  bVar3 = wistd::operator==<void,wil::process_heap_deleter>(local_res18);
  if (bVar3) {
    details::in1diag3::Return_Hr(unaff_retaddr,0x148,(char *)ppPVar6,-0x7ff8fff2);
    if (local_res18[0] != (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0)
    {
      details::FreeProcessHeap(local_res18[0]);
    }
    lVar4 = -0x7ff8fff2;
  }
  else {
    local_28 = 0;
    uStack_20 = 0;
    if (((ulonglong)local_res18[0] & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFastImmediate_Unexpected();
    }
    lVar4 = SemaphoreValue::CreateFromValueInternal
                      ((SemaphoreValue *)&local_28,param_1,SUB81(ppPVar6,0),
                       (ulonglong)local_res18[0] >> 2);
    uVar2 = uStack_20;
    uVar1 = local_28;
    if (lVar4 < 0) {
      details::in1diag3::Return_Hr(unaff_retaddr,0x14b,(char *)ppPVar6,lVar4);
      SemaphoreValue::~SemaphoreValue((SemaphoreValue *)&local_28);
      if (local_res18[0] != (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0
         ) {
        details::FreeProcessHeap(local_res18[0]);
      }
    }
    else {
      *(undefined4 *)local_res18[0] = 1;
      *(undefined8 *)(local_res18[0] + 8) = *(undefined8 *)param_2;
      *(undefined8 *)param_2 = 0;
      local_28 = 0;
      *(undefined8 *)(local_res18[0] + 0x10) = uVar1;
      uStack_20 = 0;
      *(undefined8 *)(local_res18[0] + 0x18) = uVar2;
      memset(local_res18[0] + 0x20,0,0x110);
      *(undefined8 *)(local_res18[0] + 0x20) = 0;
      UsageIndexes::UsageIndexes((UsageIndexes *)(local_res18[0] + 0x28));
      SubscriptionList::SubscriptionList((SubscriptionList *)(local_res18[0] + 0xe8));
      *param_3 = local_res18[0];
      SemaphoreValue::~SemaphoreValue((SemaphoreValue *)&local_28);
      lVar4 = 0;
    }
  }
  return lVar4;
}



===== NtStatusToHr @ 18000769c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* long __cdecl wil::details::NtStatusToHr(long) */

long __cdecl wil::details::NtStatusToHr(long param_1)

{
  ulong uVar1;
  uint uVar2;
  
  if (param_1 < 0) {
    if (param_1 == -0x3fffffe9) {
      uVar2 = 0x8007000e;
    }
    else {
      if (((g_pfnRtlNtStatusToDosErrorNoTeb != (_func_ulong_long *)0x0) &&
          (uVar1 = (*g_pfnRtlNtStatusToDosErrorNoTeb)(param_1), uVar1 != 0)) && (uVar1 != 0x13d)) {
        if ((int)uVar1 < 1) {
          return uVar1;
        }
        return uVar1 & 0xffff | 0x80070000;
      }
      uVar2 = param_1 | 0x10000000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== OnSignaled @ 1800076f8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details_abi::SubscriptionList::OnSignaled(class wil::srwlock & __ptr64)
   __ptr64 */

void __thiscall
wil::details_abi::SubscriptionList::OnSignaled(SubscriptionList *this,srwlock *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  code *pcVar6;
  undefined8 uVar7;
  srwlock *local_res8;
  SubscriptionList *local_res10;
  
  AcquireSRWLockShared((PSRWLOCK)param_1);
  uVar5 = (ulonglong)(*(longlong *)(this + 0x30) - *(longlong *)(this + 0x28)) >> 4;
  local_res8 = param_1;
  details::
  unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              *)&local_res8);
  uVar3 = 0;
  if (uVar5 != 0) {
    local_res8 = param_1;
    local_res10 = this;
    do {
      pcVar6 = (code *)0x0;
      uVar7 = 0;
      EnterCriticalSection((LPCRITICAL_SECTION)this);
      AcquireSRWLockExclusive((PSRWLOCK)param_1);
      lVar2 = uVar3 << 4;
      uVar4 = uVar3;
      while (uVar3 = uVar4, uVar4 < uVar5) {
        uVar3 = uVar4 + 1;
        if (*(longlong *)(lVar2 + *(longlong *)(this + 0x28)) != 0) {
          puVar1 = (undefined8 *)(*(longlong *)(this + 0x28) + uVar4 * 0x10);
          pcVar6 = (code *)*puVar1;
          uVar7 = puVar1[1];
          break;
        }
        lVar2 = lVar2 + 0x10;
        uVar4 = uVar3;
      }
      details::
      unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                  *)&local_res8);
      if (pcVar6 != (code *)0x0) {
        (*pcVar6)(uVar7);
      }
      details::
      unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
                  *)&local_res10);
    } while (uVar3 < uVar5);
  }
  return;
}



===== OnStateChange @ 1800077f8 =====

/* public: void __cdecl wil::details::EnabledStateManager::OnStateChange(void) __ptr64 */

void __thiscall wil::details::EnabledStateManager::OnStateChange(EnabledStateManager *this)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  EnabledStateManager *local_res8;
  
  if (*this != (EnabledStateManager)0x0) {
    AcquireSRWLockExclusive((PSRWLOCK)(this + 8));
    piVar1 = *(int **)(this + 0x58);
    for (piVar3 = *(int **)(this + 0x50); piVar3 != piVar1; piVar3 = piVar3 + 4) {
      LOCK();
      **(uint **)(piVar3 + 2) = **(uint **)(piVar3 + 2) & (-(uint)(*piVar3 != 0) & 0x83a) - 0x83f;
      UNLOCK();
    }
    *(undefined8 *)(this + 0x58) = *(undefined8 *)(this + 0x50);
    iVar2 = 1;
    if (*(int *)(this + 0x1c) + 1 != 0) {
      iVar2 = *(int *)(this + 0x1c) + 1;
    }
    *(int *)(this + 0x1c) = iVar2;
    local_res8 = this + 8;
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
  }
  return;
}



===== OnTimer @ 180007884 =====

/* public: void __cdecl wil::details::FeatureStateManager::OnTimer(void) __ptr64 */

void __thiscall wil::details::FeatureStateManager::OnTimer(FeatureStateManager *this)

{
  FeatureStateManager *local_res8;
  
  if (*this != (FeatureStateManager)0x0) {
    AcquireSRWLockExclusive((PSRWLOCK)(this + 0x20));
    this[0x41] = (FeatureStateManager)0x0;
    local_res8 = this + 0x20;
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
    FlushUsage(this);
  }
  return;
}



===== ProcessHeapAlloc @ 1800078d8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void * __ptr64 __cdecl wil::details::ProcessHeapAlloc(unsigned long,unsigned __int64) */

void * __cdecl wil::details::ProcessHeapAlloc(ulong param_1,__uint64 param_2)

{
  HANDLE hHeap;
  LPVOID pvVar1;
  HMODULE hModule;
  
  hHeap = GetProcessHeap();
  pvVar1 = HeapAlloc(hHeap,param_1,param_2);
  if (`void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2::
      pfnRtlDisownModuleHeapAllocation == (_func_long_void_ptr_void_ptr *)0x0) {
    if (`void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2
        ::fetchedRtlDisownModuleHeapAllocation != false) {
      return pvVar1;
    }
    hModule = GetModuleHandleW(L"ntdll.dll");
    if (hModule != (HMODULE)0x0) {
      `void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2::
      pfnRtlDisownModuleHeapAllocation =
           (_func_long_void_ptr_void_ptr *)GetProcAddress(hModule,"RtlDisownModuleHeapAllocation");
    }
    `void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2::
    fetchedRtlDisownModuleHeapAllocation = true;
    if (`void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2
        ::pfnRtlDisownModuleHeapAllocation == (_func_long_void_ptr_void_ptr *)0x0) {
      `void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2::
      fetchedRtlDisownModuleHeapAllocation = true;
      return pvVar1;
    }
  }
  (*`void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2::
    pfnRtlDisownModuleHeapAllocation)(hHeap,pvVar1);
  return pvVar1;
}



===== ProcessShutdown @ 180007998 =====

/* public: void __cdecl wil::details_abi::FeatureStateData::ProcessShutdown(void) __ptr64 */

void __thiscall wil::details_abi::FeatureStateData::ProcessShutdown(FeatureStateData *this)

{
  UsageIndexes local_c8 [192];
  
  UsageIndexes::UsageIndexes(local_c8);
  RetrieveUsageUnderLock(this,local_c8);
  UsageIndexes::Record(local_c8);
  UsageIndexes::~UsageIndexes(local_c8);
  return;
}



===== QueueBackgroundSRUMUsageReporting @ 1800079e0 =====

/* public: void __cdecl
   wil::details::FeatureStateManager::QueueBackgroundSRUMUsageReporting(unsigned int,unsigned
   short,unsigned int) __ptr64 */

void __thiscall
wil::details::FeatureStateManager::QueueBackgroundSRUMUsageReporting
          (FeatureStateManager *this,uint param_1,ushort param_2,uint param_3)

{
  bool bVar1;
  FeatureStateManager *local_res8;
  uint local_28;
  ushort local_24;
  undefined2 local_22;
  uint local_20;
  
  if (*this != (FeatureStateManager)0x0) {
    bVar1 = ProcessShutdownInProgress();
    if (!bVar1) {
      AcquireSRWLockExclusive((PSRWLOCK)(this + 0x28));
      local_22 = 0;
      local_res8 = this + 0x28;
      local_28 = param_1;
      local_24 = param_2;
      local_20 = param_3;
      details_abi::heap_buffer::push_back((heap_buffer *)(this + 0xe8),&local_28,0xc);
      EnsureCoalescedTimerSRUM<wil::details::FeatureStateManager>
                ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
                  *)(this + 0x38),(bool *)(this + 0x40),this);
      unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                  *)&local_res8);
    }
  }
  return;
}



===== Read @ 180007a94 =====

/* public: bool __cdecl wil::details_abi::UsageIndexProperty::Read(unsigned char * __ptr64 &
   __ptr64,unsigned char * __ptr64) __ptr64 */

bool __thiscall
wil::details_abi::UsageIndexProperty::Read(UsageIndexProperty *this,uchar **param_1,uchar *param_2)

{
  UsageIndexProperty *_Dst;
  uchar *puVar1;
  uchar *_Src;
  ushort local_res8 [4];
  
  _Src = *param_1;
  if (this[2] == (UsageIndexProperty)0x1) {
    puVar1 = _Src + 2;
    if (param_2 < puVar1) {
      return false;
    }
    *(uchar **)(this + 0x10) = _Src;
    local_res8[0] = 0;
    memcpy_s(local_res8,2,_Src,2);
    *(uint *)(this + 4) = (uint)local_res8[0];
  }
  else {
    if (this[2] != (UsageIndexProperty)0x2) goto LAB_180007b1d;
    puVar1 = _Src + 4;
    if (param_2 < puVar1) {
      return false;
    }
    *(uchar **)(this + 0x10) = _Src;
    memcpy_s(this + 4,4,_Src,4);
  }
  _Src = puVar1;
LAB_180007b1d:
  _Dst = this + 8;
  *(ushort *)_Dst = *(ushort *)this;
  puVar1 = _Src;
  if (*(ushort *)this == 0) {
    puVar1 = _Src + 2;
    if (param_2 < puVar1) {
      return false;
    }
    memcpy_s(_Dst,2,_Src,2);
  }
  if (param_2 < puVar1 + *(ushort *)_Dst) {
    return false;
  }
  *(uchar **)(this + 0x18) = puVar1;
  *param_1 = puVar1 + *(ushort *)_Dst;
  return true;
}



===== Record @ 180007b80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl wil::details_abi::UsageIndexes::Record(void) __ptr64 */

void __thiscall wil::details_abi::UsageIndexes::Record(UsageIndexes *this)

{
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (this[0x38] != (UsageIndexes)0x0) {
    local_48 = 0x418a073aa3bc1c75;
    local_40 = 0x418a073aa3bc2475;
    local_38 = 0x418a073aa3bc2c75;
    RecordWnfUsageIndex((__WIL__WNF_STATE_NAME *)&local_48,3,(RawUsageIndex *)this);
  }
  if (this[0x78] != (UsageIndexes)0x0) {
    local_48 = 0x418a073aa3bc3475;
    local_40 = 0x418a073aa3bc3c75;
    local_38 = 0x418a073aa3bc4475;
    RecordWnfUsageIndex((__WIL__WNF_STATE_NAME *)&local_48,3,(RawUsageIndex *)(this + 0x40));
  }
  if (this[0xb8] != (UsageIndexes)0x0) {
    local_48 = 0x418a073aa3bc4c75;
    local_40 = 0x418a073aa3bc5475;
    local_38 = 0x418a073aa3bc5c75;
    local_30 = 0x418a073aa3bc6475;
    local_28 = 0x418a073aa3bc6c75;
    local_20 = 0x418a073aa3bc7475;
    RecordWnfUsageIndex((__WIL__WNF_STATE_NAME *)&local_48,6,(RawUsageIndex *)(this + 0x80));
  }
  return;
}



===== RecordException @ 180007c90 =====

/* int __cdecl wil::details::RecordException(long) */

int __cdecl wil::details::RecordException(long param_1)

{
  long lVar1;
  
  lVar1 = `int___cdecl_wil::details::RecordException(long)'::__l2::s_cErrorCount;
  `int___cdecl_wil::details::RecordException(long)'::__l2::s_hrErrorLast = param_1;
  LOCK();
  `int___cdecl_wil::details::RecordException(long)'::__l2::s_cErrorCount =
       `int___cdecl_wil::details::RecordException(long)'::__l2::s_cErrorCount + 1;
  UNLOCK();
  return lVar1 + 1;
}



===== RecordFeatureUsage @ 180007cb0 =====

/* public: void __cdecl wil::details::FeatureStateManager::RecordFeatureUsage(unsigned int,enum
   wil_details_ServiceReportingKind,unsigned __int64) __ptr64 */

void __thiscall
wil::details::FeatureStateManager::RecordFeatureUsage
          (FeatureStateManager *this,uint param_1,wil_details_ServiceReportingKind param_2,
          __uint64 param_3)

{
  FeatureStateData *this_00;
  bool bVar1;
  FeatureStateData *local_res8;
  
  if (*this == (FeatureStateManager)0x0) {
    return;
  }
  bVar1 = EnsureStateData(this);
  if (!bVar1) {
    return;
  }
  this_00 = *(FeatureStateData **)(this + 0x18);
  if (param_2 == 0xfe) {
    details_abi::FeatureStateData::RecordUsage(this_00);
  }
  else {
    if (199 < param_2) {
      if ((int)param_2 < 0x100) {
        return;
      }
      if (0x1ff < param_2) {
        return;
      }
    }
    AcquireSRWLockExclusive((PSRWLOCK)this_00);
    local_res8 = this_00;
    bVar1 = details_abi::FeatureStateData::RecordFeatureUsageUnderLock
                      (this_00,param_1,param_2,param_3);
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
    if (!bVar1) {
      return;
    }
  }
  bVar1 = ProcessShutdownInProgress();
  if (!bVar1) {
    AcquireSRWLockExclusive((PSRWLOCK)(this + 0x20));
    local_res8 = (FeatureStateData *)(this + 0x20);
    EnsureCoalescedTimer<wil::details::FeatureStateManager>
              ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
                *)(this + 0x30),(bool *)(this + 0x41),this);
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
  }
  return;
}



===== RecordFeatureUsageUnderLock @ 180007da0 =====

/* public: bool __cdecl wil::details_abi::FeatureStateData::RecordFeatureUsageUnderLock(unsigned
   int,enum wil_details_ServiceReportingKind,unsigned __int64) __ptr64 */

bool __thiscall
wil::details_abi::FeatureStateData::RecordFeatureUsageUnderLock
          (FeatureStateData *this,uint param_1,wil_details_ServiceReportingKind param_2,
          __uint64 param_3)

{
  bool bVar1;
  
  if (((param_2 < 8) && ((0xccU >> (param_2 & 0x1f) & 1) != 0)) || (param_2 - 0x100 < 0x80)) {
    UsageIndex<wil_details_ServiceReportingKind,unsigned_int,0>::RecordUsage
              ((UsageIndex<wil_details_ServiceReportingKind,unsigned_int,0> *)(this + 8),param_2,
               param_1,(uint)param_3);
    return (bool)this[0x40];
  }
  bVar1 = UsageIndex<wil_details_ServiceReportingKind,unsigned_int,2>::RecordUsage
                    ((UsageIndex<wil_details_ServiceReportingKind,unsigned_int,2> *)(this + 0x48),
                     param_2,param_1,(uint)param_3);
  return bVar1;
}



===== RecordLog @ 180007dfc =====

/* int __cdecl wil::details::RecordLog(long) */

int __cdecl wil::details::RecordLog(long param_1)

{
  long lVar1;
  
  lVar1 = `int___cdecl_wil::details::RecordLog(long)'::__l2::s_cErrorCount;
  `int___cdecl_wil::details::RecordLog(long)'::__l2::s_hrErrorLast = param_1;
  LOCK();
  `int___cdecl_wil::details::RecordLog(long)'::__l2::s_cErrorCount =
       `int___cdecl_wil::details::RecordLog(long)'::__l2::s_cErrorCount + 1;
  UNLOCK();
  return lVar1 + 1;
}



===== RecordReturn @ 180007e1c =====

/* int __cdecl wil::details::RecordReturn(long) */

int __cdecl wil::details::RecordReturn(long param_1)

{
  long lVar1;
  
  lVar1 = `int___cdecl_wil::details::RecordReturn(long)'::__l2::s_cErrorCount;
  `int___cdecl_wil::details::RecordReturn(long)'::__l2::s_hrErrorLast = param_1;
  LOCK();
  `int___cdecl_wil::details::RecordReturn(long)'::__l2::s_cErrorCount =
       `int___cdecl_wil::details::RecordReturn(long)'::__l2::s_cErrorCount + 1;
  UNLOCK();
  return lVar1 + 1;
}



===== RecordSRUMFeatureUsage @ 180007e40 =====

/* void __cdecl wil::details::RecordSRUMFeatureUsage(unsigned int,unsigned int,unsigned int) */

void __cdecl wil::details::RecordSRUMFeatureUsage(uint param_1,uint param_2,uint param_3)

{
  char *in_R9;
  
  WilApi_RecordFeatureUsage(param_1,param_2 | 0x40000000,param_3,in_R9);
  return;
}



===== RecordUsage @ 180007e50 =====

/* public: bool __cdecl wil::details_abi::UsageIndex<enum wil_details_ServiceReportingKind,unsigned
   int,2>::RecordUsage(enum wil_details_ServiceReportingKind,unsigned int,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::UsageIndex<wil_details_ServiceReportingKind,unsigned_int,2>::RecordUsage
          (UsageIndex<wil_details_ServiceReportingKind,unsigned_int,2> *this,
          wil_details_ServiceReportingKind param_1,uint param_2,uint param_3)

{
  bool bVar1;
  wil_details_ServiceReportingKind local_res10 [2];
  uint local_res18 [4];
  
  local_res10[0] = param_1;
  local_res18[0] = param_2;
  bVar1 = RawUsageIndex::RecordUsage((RawUsageIndex *)this,local_res10,4,local_res18,4,param_3);
  return bVar1;
}



===== RecordUsage @ 180007e88 =====

/* public: bool __cdecl wil::details_abi::UsageIndex<enum wil_details_ServiceReportingKind,unsigned
   int,0>::RecordUsage(enum wil_details_ServiceReportingKind,unsigned int,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::UsageIndex<wil_details_ServiceReportingKind,unsigned_int,0>::RecordUsage
          (UsageIndex<wil_details_ServiceReportingKind,unsigned_int,0> *this,
          wil_details_ServiceReportingKind param_1,uint param_2,uint param_3)

{
  bool bVar1;
  wil_details_ServiceReportingKind local_res10 [2];
  uint local_res18 [4];
  
  local_res10[0] = param_1;
  local_res18[0] = param_2;
  bVar1 = RawUsageIndex::RecordUsage((RawUsageIndex *)this,local_res10,4,local_res18,4,1);
  return bVar1;
}



===== RecordUsage @ 180007ec0 =====

/* public: void __cdecl wil::details_abi::FeatureStateData::RecordUsage(void) __ptr64 */

void __thiscall wil::details_abi::FeatureStateData::RecordUsage(FeatureStateData *this)

{
  FeatureStateData *local_res8 [4];
  UsageIndexes local_c8 [192];
  
  UsageIndexes::UsageIndexes(local_c8);
  AcquireSRWLockExclusive((PSRWLOCK)this);
  local_res8[0] = this;
  RetrieveUsageUnderLock(this,local_c8);
  details::
  unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              *)local_res8);
  UsageIndexes::Record(local_c8);
  UsageIndexes::~UsageIndexes(local_c8);
  return;
}



===== RecordUsage @ 180007f2c =====

/* public: bool __cdecl wil::details_abi::RawUsageIndex::RecordUsage(void * __ptr64,unsigned
   __int64,void * __ptr64,unsigned __int64,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::RawUsageIndex::RecordUsage
          (RawUsageIndex *this,void *param_1,__uint64 param_2,void *param_3,__uint64 param_4,
          uint param_5)

{
  bool bVar1;
  __uint64 _Var2;
  void *local_38;
  undefined8 uStack_30;
  longlong local_28;
  void *pvStack_20;
  
  bVar1 = RecordUsageInternal(this,param_1,param_2,param_3,param_4,param_5);
  if (bVar1) {
    bVar1 = true;
  }
  else {
    _Var2 = param_4 + 0x20 + param_2;
    if (*(longlong *)(this + 0x18) == 0) {
      local_38 = (void *)0x0;
      uStack_30 = 0;
      local_28 = 0;
      pvStack_20 = (void *)0x0;
      bVar1 = heap_buffer::ensure((heap_buffer *)&local_38,_Var2 + 10);
      if (bVar1) {
        SetBuffer(this,local_38,0,local_28 - (longlong)local_38);
        wistd::unique_ptr<void,wil::process_heap_deleter>::operator=
                  ((unique_ptr<void,wil::process_heap_deleter> *)(this + 0x30),
                   (unique_ptr<void,struct_wil::process_heap_deleter> *)&pvStack_20);
        this[0x3a] = (RawUsageIndex)0x1;
      }
      if (pvStack_20 != (void *)0x0) {
        details::FreeProcessHeap(pvStack_20);
      }
    }
    else if (this[0x3a] != (RawUsageIndex)0x0) {
      heap_buffer::ensure((heap_buffer *)(this + 0x18),_Var2);
    }
    bVar1 = RecordUsageInternal(this,param_1,param_2,param_3,param_4,param_5);
  }
  return bVar1;
}



===== RecordUsageInternal @ 180008030 =====

/* private: bool __cdecl wil::details_abi::RawUsageIndex::RecordUsageInternal(void *
   __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::RawUsageIndex::RecordUsageInternal
          (RawUsageIndex *this,void *param_1,__uint64 param_2,void *param_3,__uint64 param_4,
          uint param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  __uint64 _Var8;
  uchar *puVar9;
  __uint64 _Var10;
  uchar *local_78;
  undefined2 local_70;
  RawUsageIndex local_6e;
  int local_6c;
  undefined2 local_68;
  undefined8 local_60;
  void *pvStack_58;
  undefined2 local_50;
  RawUsageIndex local_4e;
  uint local_4c;
  undefined2 local_48;
  undefined8 local_40;
  void *local_38;
  
  if (*(longlong *)(this + 0x18) != 0) {
    local_70 = *(undefined2 *)(this + 2);
    local_78 = (uchar *)(*(longlong *)(this + 0x18) + 10);
    local_6e = this[4];
    bVar5 = false;
    local_6c = 0;
    local_68 = 0;
    local_60 = 0;
    pvStack_58 = (void *)0x0;
    while (puVar9 = local_78,
          bVar6 = UsageIndexProperty::Read
                            ((UsageIndexProperty *)&local_70,&local_78,*(uchar **)(this + 0x20)),
          bVar6) {
      iVar7 = UsageIndexProperty::Compare((UsageIndexProperty *)&local_70,param_1,param_2);
      if (iVar7 < 0) {
        local_78 = puVar9;
LAB_180008112:
        _Var10 = 0;
        if (!bVar5) goto LAB_180008128;
        puVar9 = local_78;
        iVar7 = local_6c;
        goto LAB_18000814c;
      }
      if (iVar7 == 0) {
        local_78 = FindInsertionPointOrIncrement
                             (this,(UsageIndexProperty *)&local_70,local_78,param_3,param_4,param_5)
        ;
        if (local_78 == (uchar *)0x0) {
          return true;
        }
        bVar5 = true;
        goto LAB_180008112;
      }
      local_78 = SkipValues(this,(UsageIndexProperty *)&local_70,local_78);
    }
    *(uchar **)(this + 0x20) = local_78;
LAB_180008128:
    puVar9 = local_78;
    local_60 = 0;
    iVar7 = 1;
    local_68 = (undefined2)param_2;
    local_6c = 1;
    pvStack_58 = param_1;
    _Var10 = UsageIndexProperty::GetSize((UsageIndexProperty *)&local_70);
LAB_18000814c:
    local_50 = *(undefined2 *)(this + 6);
    local_40 = 0;
    local_4e = this[8];
    local_4c = param_5;
    local_48 = (undefined2)param_4;
    local_38 = param_3;
    _Var8 = UsageIndexProperty::GetSize((UsageIndexProperty *)&local_50);
    uVar2 = *(ulonglong *)(this + 0x28);
    uVar3 = *(ulonglong *)(this + 0x20);
    uVar1 = _Var10 + _Var8;
    if (uVar1 <= (-(ulonglong)(uVar3 < uVar2) & uVar2 - uVar3)) {
      memmove_s(puVar9 + uVar1,(uVar2 - uVar1) - (longlong)puVar9,puVar9,uVar3 - (longlong)puVar9);
      lVar4 = *(longlong *)(this + 0x20);
      *(uchar **)(this + 0x20) = (uchar *)(lVar4 + uVar1);
      if (bVar5) {
        if (local_6e != (RawUsageIndex)0x0) {
          UsageIndexProperty::UpdateCount((UsageIndexProperty *)&local_70,iVar7 + 1);
        }
      }
      else {
        UsageIndexProperty::Write
                  ((UsageIndexProperty *)&local_70,&local_78,(uchar *)(lVar4 + uVar1));
      }
      UsageIndexProperty::Write((UsageIndexProperty *)&local_50,&local_78,*(uchar **)(this + 0x20));
      this[0x38] = (RawUsageIndex)0x1;
      return true;
    }
  }
  return false;
}



===== RecordWnfUsageIndex @ 180008228 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details_abi::RecordWnfUsageIndex(struct __WIL__WNF_STATE_NAME const *
   __ptr64,unsigned __int64,class wil::details_abi::RawUsageIndex const & __ptr64) */

void __cdecl
wil::details_abi::RecordWnfUsageIndex
          (__WIL__WNF_STATE_NAME *param_1,__uint64 param_2,RawUsageIndex *param_3)

{
  __WIL__WNF_STATE_NAME *p_Var1;
  void *pvVar2;
  bool bVar3;
  __int64 _Var4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 in_R9;
  undefined1 auStackY_1178 [32];
  undefined1 *puVar8;
  uint *in_stack_ffffffffffffeeb0;
  uint local_1138;
  uint local_1134;
  undefined8 local_1130;
  undefined8 local_1128 [2];
  undefined8 *local_1118;
  undefined8 *puStack_1110;
  RawUsageIndex *local_1108;
  RawUsageIndex local_10f8 [24];
  undefined8 local_10e0;
  int local_10d8;
  void *local_10c8;
  char local_10c0;
  char local_10bf;
  undefined1 local_10b8 [8];
  undefined **local_10b0;
  undefined8 local_10a8;
  undefined8 uStack_10a0;
  RawUsageIndex *local_1098;
  undefined ***local_1048;
  undefined1 local_1038 [4096];
  ulonglong local_38;
  undefined8 uStack_30;
  
  uStack_30 = 0x180008246;
  local_38 = __security_cookie ^ (ulonglong)auStackY_1178;
  uVar6 = 0;
  p_Var1 = param_1 + param_2 * 8;
  local_1128[0] = 0;
  do {
    uVar7 = (ulonglong)*(ushort *)(param_3 + 2);
    uVar5 = (ulonglong)*(ushort *)param_3;
    RawUsageIndex::RawUsageIndex
              (local_10f8,*(ushort *)param_3,*(ushort *)(param_3 + 2),
               (CountSize)CONCAT71((int7)((ulonglong)in_R9 >> 8),param_3[4]),
               *(ushort *)(param_3 + 6),
               (CountSize)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffeeb0 >> 8),param_3[8]));
    local_1134 = 0;
    in_stack_ffffffffffffeeb0 = &local_1138;
    puVar8 = local_1038;
    local_1138 = 0x1000;
    _Var4 = wil_details_NtQueryWnfStateData
                      (param_1,uVar5,uVar7,&local_1134,puVar8,in_stack_ffffffffffffeeb0);
    details::NtStatusToHr((long)_Var4);
    if ((long)_Var4 != 0) {
      local_1134 = 0;
      local_1138 = 0;
    }
    in_R9 = 0x1000;
    RawUsageIndex::SetBuffer(local_10f8,local_1038,(ulonglong)local_1138,0x1000);
    pvVar2 = local_10c8;
    if (local_10bf != '\0') {
      local_10c8 = (void *)0x0;
      if (pvVar2 != (void *)0x0) {
        details::FreeProcessHeap(pvVar2);
      }
      return;
    }
    local_1130 = 0;
    local_1118 = &local_1130;
    puStack_1110 = local_1128;
    local_1108 = local_10f8;
    local_10b0 = &wistd::__function::
                  __func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
                  ::_vftable_;
    local_1048 = &local_10b0;
    local_1098 = local_1108;
    local_10a8 = local_1118;
    uStack_10a0 = puStack_1110;
    bVar3 = RawUsageIndex::Iterate(param_3,local_10b8);
    if (local_10c0 == '\0') {
LAB_1800083ad:
      param_1 = param_1 + 8;
      local_1128[0] = local_1130;
    }
    else {
      in_stack_ffffffffffffeeb0 = (uint *)(ulonglong)local_1134;
      _Var4 = wil_details_NtUpdateWnfStateData
                        (param_1,local_10e0,local_10d8 - (int)local_10e0,in_R9,puVar8,local_1134,1);
      if ((int)_Var4 != -0x3fffffff) {
        if ((int)_Var4 != 0) {
          in_stack_ffffffffffffeeb0 = (uint *)0x0;
          wil_details_NtUpdateWnfStateData
                    (param_1,local_10e0,local_10d8 - (int)local_10e0,in_R9,puVar8,0,0);
        }
        goto LAB_1800083ad;
      }
      uVar6 = uVar6 + 1;
      bVar3 = false;
    }
    pvVar2 = local_10c8;
    local_10c8 = (void *)0x0;
    if (pvVar2 != (void *)0x0) {
      details::FreeProcessHeap(pvVar2);
    }
    if (bVar3 != false) {
      return;
    }
    if (p_Var1 <= param_1) {
      return;
    }
    if (0x31 < uVar6) {
      return;
    }
  } while( true );
}



===== Release @ 180008424 =====

/* public: void __cdecl wil::details_abi::ProcessLocalStorageData<struct
   wil::details_abi::ProcessLocalData>::Release(void) __ptr64 */

void __thiscall
wil::details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Release
          (ProcessLocalStorageData<wil::details_abi::ProcessLocalData> *this)

{
  bool bVar1;
  HANDLE hHeap;
  ulong in_R8D;
  int in_R9D;
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  local_res10 [24];
  
  bVar1 = ProcessShutdownInProgress();
  if (bVar1) {
    *(int *)this = *(int *)this + -1;
  }
  else {
    mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
    ::acquire((mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
               *)(this + 8),(ulong *)local_res10,in_R8D,in_R9D);
    *(int *)this = *(int *)this + -1;
    if (*(int *)this == 0) {
      SemaphoreValue::Destroy((SemaphoreValue *)(this + 0x10));
      details::
      unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
      ::reset(local_res10,(void *)0x0);
      ~ProcessLocalStorageData<wil::details_abi::ProcessLocalData>(this);
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,this);
    }
    details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              (local_res10);
  }
  return;
}



===== Release @ 1800084b0 =====

/* public: void __cdecl wil::details_abi::ProcessLocalStorageData<class
   wil::details_abi::FeatureStateData>::Release(void) __ptr64 */

void __thiscall
wil::details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Release
          (ProcessLocalStorageData<wil::details_abi::FeatureStateData> *this)

{
  bool bVar1;
  HANDLE hHeap;
  ulong in_R8D;
  int in_R9D;
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  local_res10 [24];
  
  bVar1 = ProcessShutdownInProgress();
  if (bVar1) {
    *(int *)this = *(int *)this + -1;
    if (*(int *)this == 0) {
      FeatureStateData::ProcessShutdown((FeatureStateData *)(this + 0x20));
      return;
    }
  }
  else {
    mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
    ::acquire((mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
               *)(this + 8),(ulong *)local_res10,in_R8D,in_R9D);
    *(int *)this = *(int *)this + -1;
    if (*(int *)this == 0) {
      SemaphoreValue::Destroy((SemaphoreValue *)(this + 0x10));
      details::
      unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
      ::reset(local_res10,(void *)0x0);
      ~ProcessLocalStorageData<wil::details_abi::FeatureStateData>(this);
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,this);
    }
    details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              (local_res10);
  }
  return;
}



===== ReleaseMutex @ 18000854c =====

/* void __cdecl wil::details::ReleaseMutex(void * __ptr64) */

void __cdecl wil::details::ReleaseMutex(void *param_1)

{
  code *pcVar1;
  BOOL BVar2;
  char *in_R8;
  void *unaff_retaddr;
  
  BVar2 = ::ReleaseMutex(param_1);
  if (BVar2 == 0) {
    in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,in_R8);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  return;
}



===== ResultStringSize @ 18000857c =====

/* unsigned __int64 __cdecl wil::details::ResultStringSize(char const * __ptr64) */

__uint64 __cdecl wil::details::ResultStringSize(char *param_1)

{
  longlong lVar2;
  longlong lVar1;
  
  if (param_1 == (char *)0x0) {
    return 1;
  }
  lVar1 = -1;
  do {
    lVar2 = lVar1;
    lVar1 = lVar2 + 1;
  } while (param_1[lVar1] != '\0');
  return lVar2 + 2;
}



===== ResultStringSize @ 1800085a8 =====

/* unsigned __int64 __cdecl wil::details::ResultStringSize(unsigned short const * __ptr64) */

__uint64 __cdecl wil::details::ResultStringSize(ushort *param_1)

{
  longlong lVar1;
  
  if (param_1 == (ushort *)0x0) {
    return 2;
  }
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (param_1[lVar1] != 0);
  return lVar1 * 2 + 2;
}



===== RetrieveUsageUnderLock @ 1800085d4 =====

/* private: void __cdecl wil::details_abi::FeatureStateData::RetrieveUsageUnderLock(struct
   wil::details_abi::UsageIndexes & __ptr64) __ptr64 */

void __thiscall
wil::details_abi::FeatureStateData::RetrieveUsageUnderLock
          (FeatureStateData *this,UsageIndexes *param_1)

{
  if (this[0x40] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap((RawUsageIndex *)param_1,(RawUsageIndex *)(this + 8));
  }
  if (this[0x80] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap((RawUsageIndex *)(param_1 + 0x40),(RawUsageIndex *)(this + 0x48));
  }
  if (this[0xc0] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap((RawUsageIndex *)(param_1 + 0x80),(RawUsageIndex *)(this + 0x88));
  }
  return;
}



===== Return_GetLastError @ 18000863c =====

/* long __cdecl wil::details::in1diag3::Return_GetLastError(void * __ptr64,unsigned int,char const *
   __ptr64) */

long __cdecl wil::details::in1diag3::Return_GetLastError(void *param_1,uint param_2,char *param_3)

{
  long lVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffe8;
  
  lVar1 = ReportFailure_GetLastErrorHr<1>
                    (param_1,param_2,param_3,in_R9,in_stack_ffffffffffffffe8,unaff_retaddr);
  return lVar1;
}



===== Return_Hr @ 18000865c =====

/* void __cdecl wil::details::in1diag3::Return_Hr(void * __ptr64,unsigned int,char const *
   __ptr64,long) */

void __cdecl
wil::details::in1diag3::Return_Hr(void *param_1,uint param_2,char *param_3,long param_4)

{
  undefined4 in_register_0000008c;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  
  ReportFailure_Hr<1>(param_1,param_2,param_3,(char *)CONCAT44(in_register_0000008c,param_4),
                      in_stack_ffffffffffffffd8,unaff_retaddr,param_4);
  return;
}



===== RtlStringCchPrintfW @ 180008680 =====

/* long __cdecl RtlStringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  size_t _Count;
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,_Count,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = 0;
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar2;
}



===== RtlStringCopyWorkerW @ 1800086f4 =====

uint RtlStringCopyWorkerW(short *param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  longlong lVar4;
  
  if (param_2 != 0) {
    lVar2 = 0x7ffffffe;
    lVar4 = param_4 - (longlong)param_1;
    do {
      if ((lVar2 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      lVar2 = lVar2 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar3 = param_1 + -1;
  if (param_2 != 0) {
    psVar3 = param_1;
  }
  *psVar3 = 0;
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== RtlStringLengthWorkerW @ 180008750 =====

uint RtlStringLengthWorkerW(short *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  for (; (lVar2 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
    lVar2 = lVar2 + -1;
  }
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = param_2 - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== Set @ 180008798 =====

/* public: void __cdecl wil::details_abi::ThreadLocalFailureInfo::Set(struct wil::FailureInfo const
   & __ptr64,unsigned int) __ptr64 */

void __thiscall
wil::details_abi::ThreadLocalFailureInfo::Set
          (ThreadLocalFailureInfo *this,FailureInfo *param_1,uint param_2)

{
  ThreadLocalFailureInfo *pTVar1;
  ThreadLocalFailureInfo *pTVar2;
  LPVOID lpMem;
  __uint64 _Var3;
  __uint64 _Var4;
  __uint64 _Var5;
  void *pvVar6;
  HANDLE hHeap;
  uchar *puVar7;
  ushort *_Src;
  uchar *puVar8;
  ulonglong uVar9;
  
  *(uint *)(this + 4) = param_2;
  pTVar1 = this + 0x38;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x18) = *(undefined2 *)(param_1 + 0x40);
  this[0x1a] = *(ThreadLocalFailureInfo *)param_1;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x88);
  *(undefined8 *)(this + 0x30) = *(undefined8 *)(param_1 + 0x90);
  *(undefined8 *)pTVar1 = 0;
  _Var3 = details::ResultStringSize(*(ushort **)(param_1 + 0x18));
  _Var4 = details::ResultStringSize(*(char **)(param_1 + 0x38));
  _Var5 = details::ResultStringSize(*(char **)(param_1 + 0x80));
  uVar9 = _Var3 + _Var4 + _Var5;
  pTVar2 = this + 0x48;
  if (((*(longlong *)(this + 0x40) == 0) || (*(ulonglong *)pTVar2 < uVar9)) &&
     (pvVar6 = details::ProcessHeapAlloc(8,uVar9), pvVar6 != (void *)0x0)) {
    lpMem = *(LPVOID *)(this + 0x40);
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
    *(void **)(this + 0x40) = pvVar6;
    *(ulonglong *)pTVar2 = uVar9;
  }
  puVar7 = *(uchar **)(this + 0x40);
  if (puVar7 == (uchar *)0x0) {
    return;
  }
  puVar8 = puVar7 + *(ulonglong *)pTVar2;
  puVar7 = details::WriteResultString<char_const*___ptr64>
                     (puVar7,puVar8,*(char **)(param_1 + 0x38),(char **)(this + 0x10));
  puVar7 = details::WriteResultString<char_const*___ptr64>
                     (puVar7,puVar8,*(char **)(param_1 + 0x80),(char **)(this + 0x20));
  _Src = *(ushort **)(param_1 + 0x18);
  if (((puVar7 != puVar8) && (_Src != (ushort *)0x0)) && (*_Src != 0)) {
    _Var3 = details::ResultStringSize(_Src);
    if (_Var3 <= (ulonglong)((longlong)puVar8 - (longlong)puVar7)) {
      memcpy_s(puVar7,(longlong)puVar8 - (longlong)puVar7,_Src,_Var3);
      if (pTVar1 != (ThreadLocalFailureInfo *)0x0) {
        *(uchar **)pTVar1 = puVar7;
      }
      puVar7 = puVar7 + _Var3;
      goto LAB_180008903;
    }
  }
  if (pTVar1 != (ThreadLocalFailureInfo *)0x0) {
    *(undefined8 *)pTVar1 = 0;
  }
LAB_180008903:
  memset(puVar7,0,(longlong)puVar8 - (longlong)puVar7);
  return;
}



===== SetBuffer @ 180008938 =====

/* public: void __cdecl wil::details_abi::RawUsageIndex::SetBuffer(void * __ptr64,unsigned
   __int64,unsigned __int64) __ptr64 */

void __thiscall
wil::details_abi::RawUsageIndex::SetBuffer
          (RawUsageIndex *this,void *param_1,__uint64 param_2,__uint64 param_3)

{
  void *pvVar1;
  code *pcVar2;
  RawUsageIndex RVar3;
  void *unaff_retaddr;
  
  if (param_3 < 10) {
    details::in1diag3::_FailFast_Unexpected(unaff_retaddr,(uint)param_1,(char *)param_2);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pvVar1 = *(void **)(this + 0x30);
  *(undefined8 *)(this + 0x30) = 0;
  if (pvVar1 != (void *)0x0) {
    details::FreeProcessHeap(pvVar1);
  }
  *(void **)(this + 0x18) = param_1;
  *(__uint64 *)(this + 0x20) = (longlong)param_1 + param_2;
  *(__uint64 *)(this + 0x28) = (longlong)param_1 + param_3;
  this[0x39] = (RawUsageIndex)0x0;
  if (9 < param_2) {
    if ((*(short *)param_1 != 0) ||
       (RVar3 = (RawUsageIndex)0x0, *(ushort *)this < *(ushort *)((longlong)param_1 + 2))) {
      RVar3 = (RawUsageIndex)0x1;
    }
    this[0x39] = RVar3;
    if ((((*(short *)param_1 == 0) && (*(ushort *)((longlong)param_1 + 2) == *(ushort *)this)) &&
        (*(short *)((longlong)param_1 + 4) == *(short *)(this + 2))) &&
       (((*(RawUsageIndex *)((longlong)param_1 + 8) == this[4] &&
         (*(short *)((longlong)param_1 + 6) == *(short *)(this + 6))) &&
        (*(RawUsageIndex *)((longlong)param_1 + 9) == this[8])))) {
      return;
    }
  }
  *(undefined2 *)param_1 = 0;
  *(undefined2 *)((longlong)param_1 + 2) = *(undefined2 *)this;
  *(undefined2 *)((longlong)param_1 + 4) = *(undefined2 *)(this + 2);
  *(RawUsageIndex *)((longlong)param_1 + 8) = this[4];
  *(undefined2 *)((longlong)param_1 + 6) = *(undefined2 *)(this + 6);
  *(RawUsageIndex *)((longlong)param_1 + 9) = this[8];
  *(longlong *)(this + 0x20) = *(longlong *)(this + 0x18) + 10;
  return;
}



===== SetLastError @ 180008a44 =====

/* public: void __cdecl wil::details_abi::ThreadLocalData::SetLastError(struct wil::FailureInfo
   const & __ptr64) __ptr64 */

void __thiscall
wil::details_abi::ThreadLocalData::SetLastError(ThreadLocalData *this,FailureInfo *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined2 *puVar5;
  int *piVar6;
  
  iVar2 = *(int *)(this + 0x10);
  if ((*(longlong *)(this + 0x18) == 0) && (iVar2 != 0)) {
    puVar5 = details::ProcessHeapAlloc(8,400);
    *(undefined2 **)(this + 0x18) = puVar5;
    if (puVar5 != (undefined2 *)0x0) {
      *(undefined4 *)(this + 0x20) = 5;
      puVar1 = puVar5 + 200;
      for (; puVar5 != puVar1; puVar5 = puVar5 + 0x28) {
        *puVar5 = 0x50;
      }
    }
  }
  lVar3 = *(longlong *)(this + 0x18);
  if (lVar3 != 0) {
    if (iVar2 != 0) {
      for (piVar6 = (int *)(lVar3 + 8);
          piVar6 + -2 != (int *)((ulonglong)*(ushort *)(this + 0x20) * 0x50 + lVar3);
          piVar6 = piVar6 + 0x14) {
        if ((*(uint *)(this + 0x10) < (uint)piVar6[-1]) && (*piVar6 == *(int *)(param_1 + 8))) {
          return;
        }
      }
    }
    uVar4 = (ulonglong)(*(ushort *)(this + 0x22) + 1) % (ulonglong)*(ushort *)(this + 0x20);
    *(short *)(this + 0x22) = (short)uVar4;
    piVar6 = *(int **)(this + 8);
    LOCK();
    iVar2 = *piVar6;
    *piVar6 = *piVar6 + 1;
    UNLOCK();
    ThreadLocalFailureInfo::Set((ThreadLocalFailureInfo *)(uVar4 * 0x50 + lVar3),param_1,iVar2 + 1);
  }
  return;
}



===== SkipValues @ 180008b44 =====

/* private: unsigned char * __ptr64 __cdecl wil::details_abi::RawUsageIndex::SkipValues(struct
   wil::details_abi::UsageIndexProperty & __ptr64,unsigned char * __ptr64) __ptr64 */

uchar * __thiscall
wil::details_abi::RawUsageIndex::SkipValues
          (RawUsageIndex *this,UsageIndexProperty *param_1,uchar *param_2)

{
  bool bVar1;
  ulonglong uVar2;
  uchar *puVar3;
  uint uVar4;
  uchar *local_res18 [2];
  undefined2 local_38;
  RawUsageIndex local_36;
  undefined4 local_34;
  undefined2 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res18[0] = param_2;
  if (*(longlong *)(this + 0x10) == 0) {
    local_38 = *(undefined2 *)(this + 6);
    uVar4 = 0;
    local_36 = this[8];
    local_34 = 0;
    local_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      do {
        bVar1 = UsageIndexProperty::Read
                          ((UsageIndexProperty *)&local_38,local_res18,*(uchar **)(this + 0x20));
        if (!bVar1) break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(param_1 + 4));
    }
    puVar3 = local_res18[0];
    UsageIndexProperty::UpdateCount(param_1,uVar4);
  }
  else {
    uVar2 = (ulonglong)(*(longlong *)(this + 0x20) - *(longlong *)(this + 0x18)) /
            *(ulonglong *)(this + 0x10);
    if (uVar2 < *(uint *)(param_1 + 4)) {
      UsageIndexProperty::UpdateCount(param_1,(uint)uVar2);
    }
    puVar3 = param_2 + (ulonglong)*(uint *)(param_1 + 4) * *(longlong *)(this + 0x10);
  }
  return puVar3;
}



===== StringCchCatW @ 180008c14 =====

/* long __cdecl StringCchCatW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64) */

long __cdecl StringCchCatW(ushort *param_1,__uint64 param_2,ushort *param_3)

{
  uint uVar1;
  ushort *puVar2;
  size_t *pcchNewDestLength;
  longlong lVar3;
  size_t in_stack_ffffffffffffffe8;
  
  lVar3 = 0x104;
  puVar2 = param_1;
  do {
    if (*puVar2 == 0) break;
    puVar2 = puVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  pcchNewDestLength = (size_t *)(-(ulonglong)(lVar3 != 0) & 0x104U - lVar3);
  uVar1 = ~-(uint)(lVar3 != 0) & 0x80070057;
  if (lVar3 != 0) {
    uVar1 = StringCopyWorkerW((STRSAFE_LPWSTR)(param_1 + (longlong)pcchNewDestLength),
                              0x104 - (longlong)pcchNewDestLength,pcchNewDestLength,
                              (STRSAFE_PCNZWCH)param_3,in_stack_ffffffffffffffe8);
  }
  return uVar1;
}



===== StringCchPrintfW @ 180008c80 =====

/* long __cdecl StringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl StringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  HRESULT HVar1;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    local_res20 = in_R9;
    HVar1 = StringVPrintfWorkerW
                      ((STRSAFE_LPWSTR)param_1,param_2,(size_t *)param_3,(STRSAFE_LPCWSTR)param_3,
                       (va_list)&local_res20);
  }
  else {
    HVar1 = -0x7ff8ffa9;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return HVar1;
}



===== StringCopyWorkerW @ 180008ccc =====

HRESULT __stdcall
StringCopyWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t *pcchNewDestLength,
                 STRSAFE_PCNZWCH pszSrc,size_t cchToCopy)

{
  wchar_t wVar1;
  longlong lVar2;
  STRSAFE_LPWSTR pwVar3;
  longlong lVar4;
  
  if (cchDest != 0) {
    lVar2 = 0x7ffffffe;
    lVar4 = (longlong)pszSrc - (longlong)pszDest;
    do {
      if ((lVar2 == 0) || (wVar1 = *(wchar_t *)(lVar4 + (longlong)pszDest), wVar1 == L'\0')) break;
      *pszDest = wVar1;
      lVar2 = lVar2 + -1;
      pszDest = pszDest + 1;
      cchDest = cchDest - 1;
    } while (cchDest != 0);
  }
  pwVar3 = pszDest + -1;
  if (cchDest != 0) {
    pwVar3 = pszDest;
  }
  *pwVar3 = L'\0';
  return ~-(uint)(cchDest != 0) & 0x8007007a;
}



===== StringVPrintfWorkerW @ 180008d28 =====

HRESULT __stdcall
StringVPrintfWorkerW
          (STRSAFE_LPWSTR pszDest,size_t cchDest,size_t *pcchNewDestLength,STRSAFE_LPCWSTR pszFormat
          ,va_list argList)

{
  size_t _Count;
  int iVar1;
  HRESULT HVar2;
  
  _Count = cchDest - 1;
  HVar2 = 0;
  iVar1 = _vsnwprintf(pszDest,_Count,pszFormat,argList);
  if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
    pszDest[_Count] = L'\0';
    HVar2 = -0x7ff8ff86;
  }
  else if ((longlong)iVar1 == _Count) {
    pszDest[_Count] = L'\0';
  }
  return HVar2;
}



===== SubscribeFeatureStateCacheToConfigurationChanges @ 180008d88 =====

/* public: void __cdecl
   wil::details::EnabledStateManager::SubscribeFeatureStateCacheToConfigurationChanges(union
   wil_details_FeatureStateCache * __ptr64,enum wil_FeatureChangeTime,unsigned int) __ptr64 */

void __thiscall
wil::details::EnabledStateManager::SubscribeFeatureStateCacheToConfigurationChanges
          (EnabledStateManager *this,wil_details_FeatureStateCache *param_1,
          wil_FeatureChangeTime param_2,uint param_3)

{
  EnabledStateManager *SRWLock;
  bool bVar1;
  EnabledStateManager *local_res8;
  wil_FeatureChangeTime local_28 [2];
  wil_details_FeatureStateCache *local_20;
  
  if (*this == (EnabledStateManager)0x0) {
    return;
  }
  SRWLock = this + 8;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  local_res8 = SRWLock;
  if ((param_3 != 0) && (param_3 == *(uint *)(this + 0x1c))) {
    local_28[1] = 0;
    local_28[0] = param_2;
    local_20 = param_1;
    bVar1 = details_abi::heap_buffer::push_back((heap_buffer *)(this + 0x50),local_28,0x10);
    if (bVar1) goto LAB_180008e07;
  }
  LOCK();
  *(uint *)param_1 = *(uint *)param_1 & (-(uint)(param_2 != 0) & 0x83a) - 0x83f;
  UNLOCK();
LAB_180008e07:
  unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              *)&local_res8);
  return;
}



===== SubscribeFeatureStateCacheToConfigurationChanges @ 180008e30 =====

/* void __cdecl wil::details::SubscribeFeatureStateCacheToConfigurationChanges(union
   wil_details_FeatureStateCache * __ptr64,enum wil_FeatureChangeTime,unsigned int) */

void __cdecl
wil::details::SubscribeFeatureStateCacheToConfigurationChanges
          (wil_details_FeatureStateCache *param_1,wil_FeatureChangeTime param_2,uint param_3)

{
  EnabledStateManager::SubscribeFeatureStateCacheToConfigurationChanges
            ((EnabledStateManager *)&g_enabledStateManager,param_1,param_2,param_3);
  return;
}



===== SubscribeToUsageFlush @ 180008e4c =====

/* public: void __cdecl wil::details::FeatureStateManager::SubscribeToUsageFlush(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64)) __ptr64
    */

void __thiscall
wil::details::FeatureStateManager::SubscribeToUsageFlush
          (FeatureStateManager *this,FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,
          _func_void_void_ptr *param_2)

{
  FeatureStateManager *SRWLock;
  FeatureStateManager *pFVar1;
  PSRWLOCK SRWLock_00;
  bool bVar2;
  PSRWLOCK local_res8;
  FeatureStateManager *local_res10;
  
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  if (*this != (FeatureStateManager)0x0) {
    bVar2 = ProcessShutdownInProgress();
    if (!bVar2) {
      bVar2 = EnsureStateData(this);
      if (bVar2) {
        SRWLock = this + 0x20;
        AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
        pFVar1 = this + 0xe0;
        local_res10 = SRWLock;
        if ((*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)pFVar1 ==
             (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) &&
           (SRWLock_00 = *(PSRWLOCK *)(this + 0x18), SRWLock_00 != (PSRWLOCK)0x0)) {
          *(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)pFVar1 =
               (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
          AcquireSRWLockExclusive(SRWLock_00);
          local_res8 = SRWLock_00;
          details_abi::SubscriptionList::SubscribeUnderLock
                    ((SubscriptionList *)(SRWLock_00 + 0x19),
                     (FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)pFVar1,
                     <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>,this);
          unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
          ::
          ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                    ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                      *)&local_res8);
        }
        details_abi::SubscriptionList::SubscribeUnderLock
                  ((SubscriptionList *)(this + 0x98),param_1,param_2,(void *)0x0);
        if (*param_1 != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
          *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)((ulonglong)*param_1 | 0x80000000);
        }
        unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
        ::
        ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                  ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                    *)&local_res10);
      }
    }
  }
  return;
}



===== SubscribeUnderLock @ 180008f48 =====

/* public: void __cdecl wil::details_abi::SubscriptionList::SubscribeUnderLock(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64),void *
   __ptr64) __ptr64 */

void __thiscall
wil::details_abi::SubscriptionList::SubscribeUnderLock
          (SubscriptionList *this,FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,
          _func_void_void_ptr *param_2,void *param_3)

{
  heap_buffer *this_00;
  longlong lVar1;
  bool bVar2;
  FEATURE_STATE_CHANGE_SUBSCRIPTION__ *pFVar3;
  longlong lVar4;
  _func_void_void_ptr *local_18;
  void *local_10;
  
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  this_00 = (heap_buffer *)(this + 0x28);
  lVar1 = *(longlong *)this_00;
  lVar4 = 0;
  pFVar3 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  while( true ) {
    if ((FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
        ((ulonglong)(*(longlong *)(this + 0x30) - lVar1) >> 4) <= pFVar3) {
      local_18 = param_2;
      local_10 = param_3;
      bVar2 = heap_buffer::push_back(this_00,&local_18,0x10);
      if (bVar2) {
        *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
                   ((ulonglong)(*(longlong *)(this + 0x30) - *(longlong *)this_00) >> 4);
      }
      return;
    }
    if (*(longlong *)(lVar4 + lVar1) == 0) break;
    lVar4 = lVar4 + 0x10;
    pFVar3 = pFVar3 + 1;
  }
  *(_func_void_void_ptr **)(lVar1 + (longlong)pFVar3 * 0x10) = param_2;
  *(void **)(lVar1 + 8 + (longlong)pFVar3 * 0x10) = param_3;
  *param_1 = pFVar3 + 1;
  return;
}



===== Swap @ 180008fe4 =====

/* public: void __cdecl wil::details_abi::RawUsageIndex::Swap(class wil::details_abi::RawUsageIndex
   & __ptr64) __ptr64 */

void __thiscall wil::details_abi::RawUsageIndex::Swap(RawUsageIndex *this,RawUsageIndex *param_1)

{
  RawUsageIndex RVar1;
  undefined8 uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  void *local_10;
  
  heap_buffer::heap_buffer((heap_buffer *)&local_28,(heap_buffer *)(this + 0x18));
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x18) = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x20) = uVar2;
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x28);
  wistd::unique_ptr<void,wil::process_heap_deleter>::operator=
            ((unique_ptr<void,wil::process_heap_deleter> *)(this + 0x30),
             (unique_ptr<void,struct_wil::process_heap_deleter> *)(param_1 + 0x30));
  *(undefined8 *)(param_1 + 0x18) = local_28;
  *(undefined8 *)(param_1 + 0x20) = uStack_20;
  *(undefined8 *)(param_1 + 0x28) = local_18;
  wistd::unique_ptr<void,wil::process_heap_deleter>::operator=
            ((unique_ptr<void,wil::process_heap_deleter> *)(param_1 + 0x30),
             (unique_ptr<void,struct_wil::process_heap_deleter> *)&local_10);
  if (local_10 != (void *)0x0) {
    details::FreeProcessHeap(local_10);
  }
  RVar1 = this[0x38];
  this[0x38] = param_1[0x38];
  param_1[0x38] = RVar1;
  RVar1 = this[0x39];
  this[0x39] = param_1[0x39];
  param_1[0x39] = RVar1;
  return;
}



===== TbsBase64Decode @ 180009088 =====

/* long __cdecl TbsBase64Decode(unsigned short const * __ptr64,unsigned char * __ptr64,unsigned int
   * __ptr64) */

long __cdecl TbsBase64Decode(ushort *param_1,uchar *param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  char cVar11;
  ulonglong local_res8;
  
  uVar10 = 0;
  local_res8 = 0;
  if ((((param_1 != (ushort *)0x0) &&
       (uVar1 = RtlStringLengthWorkerW((short *)param_1,0x7fffffff,(longlong *)&local_res8),
       -1 < (int)uVar1)) && (local_res8 != 0)) && ((local_res8 & 3) == 0)) {
    uVar3 = ((int)local_res8 + 3U >> 2) * 3;
    if (param_1[local_res8 - 1] == 0x3d) {
      if (param_1[local_res8 - 2] == 0x3d) {
        uVar3 = uVar3 - 2;
      }
      else {
        uVar3 = uVar3 - 1;
      }
    }
    if ((param_2 == (uchar *)0x0) || (*param_3 < uVar3)) {
      *param_3 = uVar3;
      if (param_2 == (uchar *)0x0) {
        return uVar1;
      }
      return -0x3fffffdd;
    }
    *param_3 = uVar3;
    uVar8 = uVar10 & 0xffffffff;
    while( true ) {
      iVar7 = (int)uVar8;
      if (local_res8 <= uVar8) {
        return uVar1;
      }
      if (param_1[uVar8] < 0x80) {
        cVar11 = (&DAT_180011290)[param_1[uVar8]];
      }
      else {
        cVar11 = -1;
      }
      uVar8 = (ulonglong)(iVar7 + 1);
      if ((uVar8 < local_res8) && (param_1[uVar8] < 0x80)) {
        bVar6 = (&DAT_180011290)[param_1[uVar8]];
      }
      else {
        bVar6 = 0xff;
      }
      uVar8 = (ulonglong)(iVar7 + 2);
      if ((uVar8 < local_res8) && (param_1[uVar8] < 0x80)) {
        bVar4 = (&DAT_180011290)[param_1[uVar8]];
      }
      else {
        bVar4 = 0xff;
      }
      uVar8 = (ulonglong)(iVar7 + 3);
      if ((uVar8 < local_res8) && (param_1[uVar8] < 0x80)) {
        bVar5 = (&DAT_180011290)[param_1[uVar8]];
      }
      else {
        bVar5 = 0xff;
      }
      uVar8 = (ulonglong)(iVar7 + 4);
      if ((((cVar11 == -1) || (bVar6 == 0xff)) || (bVar4 == 0xff)) || (bVar5 == 0xff)) break;
      uVar9 = (uint)uVar10;
      if (uVar9 < uVar3) {
        uVar2 = uVar10 & 0xffffffff;
        uVar10 = (ulonglong)(uVar9 + 1);
        param_2[uVar2] = bVar6 >> 4 | cVar11 << 2;
        if (uVar9 + 1 < uVar3) {
          param_2[uVar10] = bVar4 >> 2 | bVar6 << 4;
          uVar10 = (ulonglong)(uVar9 + 2);
          if (uVar9 + 2 < uVar3) {
            param_2[uVar10] = bVar4 << 6 | bVar5;
            uVar10 = (ulonglong)(uVar9 + 3);
          }
        }
      }
    }
  }
  return -0x3ffffff3;
}



===== TbsGetCurrentLog @ 180009264 =====

/* unsigned int __cdecl TbsGetCurrentLog(int,unsigned char * __ptr64,unsigned int,unsigned int *
   __ptr64) */

uint __cdecl TbsGetCurrentLog(int param_1,uchar *param_2,uint param_3,uint *param_4)

{
  uchar uVar1;
  uint uVar2;
  
  if (param_4 == (uint *)0x0) {
    uVar2 = 0x80284003;
  }
  else {
    if ((param_1 != 0) && (uVar1 = IsDrtmBoot(), uVar1 == '\0')) {
      return 0x80284011;
    }
    uVar2 = Feature_TpmMissingLogsMaa__private_IsEnabledDeviceUsageNoInline();
    if (uVar2 == 0) {
      uVar2 = TbsGetLog(param_1,param_2,param_3,param_4);
    }
    else {
      uVar2 = TbsGetLogNew(param_1,0,param_2,param_3,param_4);
    }
  }
  return uVar2;
}



===== TbsGetCurrentLogIfResumed @ 1800092ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned int __cdecl TbsGetCurrentLogIfResumed(int,unsigned char * __ptr64,unsigned int,unsigned
   int * __ptr64) */

uint __cdecl TbsGetCurrentLogIfResumed(int param_1,uchar *param_2,uint param_3,uint *param_4)

{
  HKEY hKey;
  uint uVar1;
  _tlgWrapperByVal<1> _Var2;
  _GUID *p_Var3;
  _GUID *p_Var4;
  _tlgWrapperByVal<1> _Var5;
  _tlgWrapperByVal<1> local_res20 [8];
  _tlgWrapperByVal<1> local_58;
  _tlgWrapperByVal<1> local_57;
  _tlgWrapperByVal<1> local_56 [6];
  uint local_50 [2];
  HKEY local_48;
  int local_40 [2];
  undefined8 local_38 [2];
  
  _Var2 = (_tlgWrapperByVal<1>)0x0;
  local_50[0] = 0;
  if (param_4 == (uint *)0x0) {
    return 0x80284003;
  }
  uVar1 = Feature_TpmMissingLogsMaa__private_IsEnabledDeviceUsageNoInline();
  if (uVar1 == 0) {
    uVar1 = Tbsi_Get_TCG_Logs_Internal(0,1,(uint *)0x0,(uchar *)0x0,0,local_50,0);
    if (uVar1 == 0) {
      uVar1 = TbsGetCurrentLog(param_1,param_2,param_3,param_4);
      return uVar1;
    }
    return 0x80284011;
  }
  local_res20[0] = (_tlgWrapperByVal<1>)0x0;
  _Var5 = (_tlgWrapperByVal<1>)0x0;
  local_48 = (HKEY)0x0;
  local_40[0] = 0;
  local_40[1] = 4;
  uVar1 = Tbsi_Get_TCG_Logs_Internal(0,1,(uint *)0x0,(uchar *)0x0,0,local_50,0);
  hKey = local_48;
  if (uVar1 == 0) {
    _Var2 = (_tlgWrapperByVal<1>)0x1;
LAB_18000944f:
    p_Var3 = (_GUID *)(ulonglong)param_3;
    uVar1 = TbsGetCurrentLog(param_1,param_2,param_3,param_4);
  }
  else {
    if (local_48 != (HKEY)0x0) {
      wil::last_error_context::last_error_context((last_error_context *)local_50);
      RegCloseKey(hKey);
      wil::last_error_context::~last_error_context((last_error_context *)local_50);
    }
    local_48 = (HKEY)0x0;
    uVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,
                          L"System\\CurrentControlSet\\Control\\IntegrityServices",0,1,&local_48);
    if (0 < (int)uVar1) {
      uVar1 = uVar1 & 0xffff | 0x80070000;
    }
    if ((int)uVar1 < 0) goto LAB_1800093e6;
    p_Var4 = (_GUID *)0x0;
    p_Var3 = (_GUID *)0x0;
    uVar1 = RegQueryValueExW(local_48,L"OsResumeCount",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_40,
                             (LPDWORD)(local_40 + 1));
    if (0 < (int)uVar1) {
      uVar1 = uVar1 & 0xffff | 0x80070000;
    }
    if ((int)uVar1 < 0) goto LAB_1800093e6;
    if (local_40[0] != 0) {
      local_res20[0] = (_tlgWrapperByVal<1>)0x1;
      _Var2 = (_tlgWrapperByVal<1>)0x0;
      goto LAB_18000944f;
    }
    _Var5 = (_tlgWrapperByVal<1>)0x1;
    uVar1 = 0x80284011;
    param_4 = &p_Var4->Data1;
  }
  if (((5 < DAT_180015048) && ((_DAT_180015058 & 0x800000000000) != 0)) &&
     ((_tlgProvider_t *)((ulonglong)DAT_180015060 & 0x800000000000) == DAT_180015060)) {
    local_56[0] = SUB41(param_1,0);
    local_38[0] = 0x1000000;
    local_58 = _Var5;
    local_57 = _Var2;
    local_50[0] = uVar1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_>
              ((_tlgProvider_t *)((ulonglong)DAT_180015060 & 0x800000000000),&DAT_180011a30,p_Var3,
               (_GUID *)param_4,(_tlgWrapperByVal<8> *)local_38,(_tlgWrapperByVal<4> *)local_50,
               local_56,&local_57,&local_58,local_res20);
  }
LAB_1800093e6:
  wil::details::
  unique_storage<wil::details::resource_policy<HKEY__*___ptr64,long_(__cdecl*)(HKEY__*___ptr64),&long___cdecl_RegCloseKey(struct_HKEY__*___ptr64),wistd::integral_constant<unsigned___int64,0>,HKEY__*___ptr64,HKEY__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<HKEY__*___ptr64,long_(__cdecl*)(HKEY__*___ptr64),&long___cdecl_RegCloseKey(struct_HKEY__*___ptr64),wistd::integral_constant<unsigned___int64,0>,HKEY__*___ptr64,HKEY__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<HKEY__*___ptr64,long_(__cdecl*)(HKEY__*___ptr64),&long___cdecl_RegCloseKey(struct_HKEY__*___ptr64),wistd::integral_constant<unsigned___int64,0>,HKEY__*___ptr64,HKEY__*___ptr64,0,std::nullptr_t>_>
              *)&local_48);
  return uVar1;
}



===== TbsGetLastCleanBootLog @ 18000954c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned int __cdecl TbsGetLastCleanBootLog(int,unsigned char * __ptr64,unsigned int * __ptr64)
    */

uint __cdecl TbsGetLastCleanBootLog(int param_1,uchar *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStackY_e8 [32];
  undefined1 local_a8;
  undefined1 local_a7 [3];
  uint local_a4;
  undefined8 local_a0;
  _EVENT_DATA_DESCRIPTOR local_98 [2];
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar2 = Feature_TpmMissingLogsMaa__private_IsEnabledDeviceUsageNoInline();
  uVar1 = *param_3;
  if (uVar2 == 0) {
    uVar2 = Tbsi_Get_TCG_Logs_Internal(param_1,0,(uint *)0x0,param_2,uVar1,param_3,0);
  }
  else {
    uVar2 = Tbsi_Get_TCG_Logs_Internal(param_1,0,(uint *)0x0,param_2,uVar1,param_3,0);
    local_a7[0] = uVar2 == 0x80284011;
    if ((bool)local_a7[0]) {
      *param_3 = uVar1;
      uVar2 = TbsGetLogNew(param_1,1,param_2,uVar1,param_3);
    }
    if (((5 < DAT_180015048) && ((_DAT_180015058 & 0x800000000000) != 0)) &&
       ((DAT_180015060 & 0x800000000000) == DAT_180015060)) {
      local_3c = 0;
      local_48 = &local_a8;
      local_4c = 0;
      local_5c = 0;
      local_6c = 0;
      local_58 = local_a7;
      local_a8 = (undefined1)param_1;
      local_68 = &local_a4;
      local_78 = &local_a0;
      local_a0 = 0x1000000;
      local_40 = 1;
      local_50 = 1;
      local_60 = 4;
      local_70 = 8;
      local_a4 = uVar2;
      _tlgWriteTransfer_EventWriteTransfer
                (0x180015048,&DAT_1800119d1,(LPCGUID)0x0,(LPCGUID)0x0,6,local_98);
    }
  }
  return uVar2;
}



===== TbsGetLogNew @ 1800096d4 =====

/* unsigned int __cdecl TbsGetLogNew(int,int,unsigned char * __ptr64,unsigned int,unsigned int *
   __ptr64) */

uint __cdecl TbsGetLogNew(int param_1,int param_2,uchar *param_3,uint param_4,uint *param_5)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  _KEY_VALUE_PARTIAL_INFORMATION *p_Var4;
  wchar_t *pwVar5;
  void *_Src;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  ulong local_a8 [2];
  longlong local_a0;
  longlong local_98;
  longlong local_90 [3];
  last_error_context local_78 [8];
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  
  uVar7 = 0;
  local_5c = 0;
  local_44 = 0;
  *param_5 = 0;
  local_a8[0] = 0;
  local_90[0] = 0;
  local_98 = 0;
  local_70 = 0;
  uStack_68 = 0;
  lVar6 = 0;
  local_a0 = 0;
  local_90[1] = 0;
  local_90[2] = 0;
  RtlInitUnicodeString
            (&local_70,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\IntegrityServices"
            );
  lVar1 = local_a0;
  local_50 = &local_70;
  local_60 = 0x30;
  local_58 = 0;
  local_48 = 0x40;
  local_40 = 0;
  uStack_38 = 0;
  if (local_a0 != 0) {
    wil::last_error_context::last_error_context(local_78);
    NtClose(lVar1);
    wil::last_error_context::~last_error_context(local_78);
  }
  local_a0 = 0;
  uVar2 = NtOpenKey(&local_a0,0x20019,&local_60);
  if ((int)uVar2 < 0) {
LAB_1800097b6:
    wil::details::
    unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                *)&local_a0);
    wil::details::
    unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
                *)&local_98);
    wil::details::
    unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
                *)local_90);
    return uVar2 | 0x10000000;
  }
  if (param_2 == 0) {
    pwVar5 = L"WBCLDrtm";
    if (param_1 == 0) {
      pwVar5 = L"WBCL";
    }
  }
  else if (param_1 == 0) {
    pwVar5 = L"WBCLColdboot";
  }
  else {
    pwVar5 = L"WBCLDrtmColdboot";
  }
  RtlInitUnicodeString(local_90 + 1,pwVar5);
  uVar2 = NtQueryValueKey(local_a0,local_90 + 1,2,0,0,local_a8);
  if (uVar2 == 0xc0000034) {
LAB_180009a39:
    uVar7 = 0x80284011;
LAB_180009a3e:
    wil::details::
    unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                *)&local_a0);
    wil::details::
    unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
                *)&local_98);
    wil::details::
    unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
                *)local_90);
    return uVar7;
  }
  if (uVar2 != 0xc0000023) goto LAB_1800097b6;
  p_Var4 = (_KEY_VALUE_PARTIAL_INFORMATION *)TpmAlloc(local_a8[0]);
  wil::details::
  unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
           *)local_90,p_Var4);
  lVar1 = local_90[0];
  if (local_90[0] == 0) {
LAB_180009a32:
    uVar7 = 0x8007000e;
    goto LAB_180009a3e;
  }
  uVar2 = NtQueryValueKey(local_a0,local_90 + 1,2,local_90[0],local_a8[0],local_a8);
  if ((int)uVar2 < 0) {
LAB_1800098ae:
    wil::details::
    unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                *)&local_a0);
    wil::details::
    unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
                *)&local_98);
    wil::details::
    unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
                *)local_90);
    return uVar2 | 0x10000000;
  }
  if (*(int *)(lVar1 + 4) != 3) goto LAB_180009a39;
  uVar8 = *(uint *)(lVar1 + 8);
  RtlInitUnicodeString(local_90 + 1,L"WBCLTrustPoint");
  iVar3 = NtQueryValueKey(local_a0,local_90 + 1,2,0,0,local_a8);
  if (iVar3 == -0x3fffffdd) {
    p_Var4 = (_KEY_VALUE_PARTIAL_INFORMATION *)TpmAlloc(local_a8[0]);
    wil::details::
    unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
    ::reset((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
             *)&local_98,p_Var4);
    lVar6 = local_98;
    if (local_98 == 0) goto LAB_180009a32;
    uVar2 = NtQueryValueKey(local_a0,local_90 + 1,2,local_98,local_a8[0],local_a8);
    if ((int)uVar2 < 0) goto LAB_1800098ae;
    if (*(int *)(lVar6 + 4) == 3) {
      uVar8 = uVar8 + *(int *)(lVar6 + 8);
    }
    else {
      local_a8[0] = 0;
    }
  }
  if ((param_3 != (uchar *)0x0) && (param_4 != 0)) {
    _Src = (void *)(lVar1 + 0xc);
    if (param_4 < uVar8) {
      if (param_4 < *(uint *)(lVar1 + 8)) {
        uVar7 = param_4;
LAB_1800099d8:
        memcpy(param_3,_Src,(ulonglong)uVar7);
      }
      else {
        memcpy(param_3,_Src,(ulonglong)*(uint *)(lVar1 + 8));
        if ((*(uint *)(lVar1 + 8) < param_4) && (lVar6 != 0)) {
          _Src = (void *)(lVar6 + 0xc);
          uVar7 = param_4 - *(int *)(lVar1 + 8);
          param_3 = param_3 + *(uint *)(lVar1 + 8);
          goto LAB_1800099d8;
        }
      }
      uVar7 = 0x80284005;
      *param_5 = param_4;
      goto LAB_180009a13;
    }
    memcpy(param_3,_Src,(ulonglong)*(uint *)(lVar1 + 8));
    if (lVar6 != 0) {
      memcpy(param_3 + *(uint *)(lVar1 + 8),(void *)(lVar6 + 0xc),(ulonglong)*(uint *)(lVar6 + 8));
    }
  }
  *param_5 = uVar8;
LAB_180009a13:
  wil::details::
  unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_NtClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)&local_a0);
  wil::details::
  unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
              *)&local_98);
  wil::details::
  unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
              *)local_90);
  return uVar7;
}



===== Tbsi_Context_Create_Ex @ 180009a84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned int __cdecl Tbsi_Context_Create_Ex(struct tdTBS_CONTEXT_PARAMS const * __ptr64,void *
   __ptr64 * __ptr64,int) */

uint __cdecl Tbsi_Context_Create_Ex(tdTBS_CONTEXT_PARAMS *param_1,void **param_2,int param_3)

{
  void *pvVar1;
  uint uVar2;
  undefined1 auStack_58 [32];
  void *local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = (void *)0xffffffffffffffff;
  local_30 = 0;
  uStack_28 = 0;
  if (param_1 == (tdTBS_CONTEXT_PARAMS *)0x0) {
    return 0x80284002;
  }
  if (param_2 == (void **)0x0) {
    return 0x80284003;
  }
  uVar2 = Tbsi_GetDeviceInfo(0x10,&local_30);
  if ((int)uVar2 < 0) goto LAB_180009b53;
  if (*(int *)param_1 == 1) {
    if (local_30._4_4_ != 1) {
LAB_180009b87:
      uVar2 = 0x8028400f;
      goto LAB_180009b53;
    }
  }
  else {
    if (*(int *)param_1 != 2) {
      uVar2 = 0x80284007;
      goto LAB_180009b53;
    }
    if (((local_30._4_4_ == 1) && (((byte)param_1[4] & 2) == 0)) ||
       ((local_30._4_4_ == 2 && (((byte)param_1[4] & 4) == 0)))) goto LAB_180009b87;
  }
  uVar2 = TpmOpenEx(&local_38,param_3);
  if (uVar2 == 0x80070002) {
    uVar2 = 0x8028400f;
  }
  uVar2 = TbsRemapError(uVar2,0x395);
  pvVar1 = local_38;
  if (-1 < (int)uVar2) {
    local_38 = (void *)0x0;
    *param_2 = pvVar1;
  }
LAB_180009b53:
  if (local_38 != (void *)0xffffffffffffffff) {
    TpmClose(local_38);
  }
  return uVar2;
}



===== Tbsi_Get_TCG_Logs @ 180009ba0 =====

/* unsigned int __cdecl Tbsi_Get_TCG_Logs(unsigned int,unsigned int * __ptr64,unsigned char *
   __ptr64,unsigned int,unsigned int * __ptr64,unsigned int) */

uint __cdecl
Tbsi_Get_TCG_Logs(uint param_1,uint *param_2,uchar *param_3,uint param_4,uint *param_5,uint param_6)

{
  uint uVar1;
  
                    /* 0x9ba0  2  Tbsi_Get_TCG_Logs */
  uVar1 = Tbsi_Get_TCG_Logs_Internal(0,param_1,param_2,param_3,param_4,param_5,param_6);
  return uVar1;
}



===== Tbsi_Get_TCG_Logs_Internal @ 180009bd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned int __cdecl Tbsi_Get_TCG_Logs_Internal(int,unsigned int,unsigned int * __ptr64,unsigned
   char * __ptr64,unsigned int,unsigned int * __ptr64,unsigned int) */

uint __cdecl
Tbsi_Get_TCG_Logs_Internal
          (int param_1,uint param_2,uint *param_3,uchar *param_4,uint param_5,uint *param_6,
          uint param_7)

{
  int iVar1;
  LSTATUS LVar2;
  UINT UVar3;
  long lVar4;
  DWORD DVar5;
  BOOL BVar6;
  int iVar7;
  uint uVar8;
  HANDLE hFile;
  uint uVar9;
  bool bVar10;
  undefined1 auStackY_b08 [32];
  DWORD local_ac8;
  char local_ac4;
  undefined4 local_ac0;
  uint local_abc;
  undefined4 local_ab8;
  wchar_t *local_ab0;
  uint *local_aa8;
  uint *local_aa0;
  ushort local_a98 [264];
  undefined1 local_888 [528];
  WCHAR local_678 [264];
  WCHAR local_468;
  undefined1 local_466 [526];
  WCHAR local_258 [264];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b08;
  local_ab0 = (wchar_t *)CONCAT44(local_ab0._4_4_,param_1);
  local_aa8 = param_6;
  local_ac8 = 0;
  local_ac0 = 0;
  uVar8 = 0;
  local_abc = param_2;
  local_aa0 = param_3;
  memset(local_258,0,0x208);
  memset(local_a98,0,0x208);
  memset(local_888,0,0x208);
  local_468 = L'\0';
  memset(local_466,0,0x206);
  hFile = (HANDLE)0xffffffffffffffff;
  memset(local_678,0,0x208);
  local_ab8 = 0x208;
  if (param_6 == (uint *)0x0) {
    uVar8 = 0x80284003;
    goto LAB_18000a092;
  }
  *param_6 = 0;
  if ((param_7 & 0xfffffffe) != 0) {
    uVar8 = 0x80284002;
    goto LAB_18000a092;
  }
  iVar1 = RtlGetPersistedStateLocation
                    (L"TpmRegDriverTpm",0,L"System\\CurrentControlSet\\services\\TPM",0);
  if (iVar1 == 0) {
    local_ac8 = 4;
    LVar2 = RegGetValueW((HKEY)0xffffffff80000002,local_678,L"OsBootCount",0x10,(LPDWORD)0x0,
                         &local_ac0,&local_ac8);
    if ((LVar2 == 0) && (UVar3 = GetSystemWindowsDirectoryW(local_258,0x104), UVar3 - 1 < 0x104)) {
      local_ac8 = 0x208;
      LVar2 = RegGetValueW((HKEY)0xffffffff80000002,local_678,L"WBCLPath",2,(LPDWORD)0x0,local_888,
                           &local_ac8);
      if ((LVar2 == 0) && (local_ac8 != 0)) {
LAB_180009e50:
        memcpy(local_a98,local_888,(ulonglong)local_ac8);
        uVar9 = param_7 & 1;
        local_ac8 = 0;
        bVar10 = (int)local_ab0 == 0;
        local_ab0 = L"%s\\%010u-%010u-DRTM.log";
        local_ac4 = '\x01';
        if (bVar10) {
          local_ab0 = L"%s\\%010u-%010u.log";
        }
        iVar1 = uVar9 * 4;
        do {
          lVar4 = RtlStringCchPrintfW((ushort *)&local_468,0x104,(ushort *)local_ab0,local_a98);
          if (lVar4 < 0) {
LAB_18000a081:
            uVar8 = 0x80284001;
            goto LAB_18000a086;
          }
          hFile = CreateFileW(&local_468,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,4,(HANDLE)0x0);
          if (hFile == (HANDLE)0xffffffffffffffff) {
            DVar5 = GetLastError();
            if (DVar5 == 2) {
              if (param_2 != local_abc) break;
            }
            else if (DVar5 != 3) goto LAB_18000a08d;
            uVar8 = 0x80284011;
            goto LAB_18000a092;
          }
          DVar5 = GetFileSize(hFile,(LPDWORD)0x0);
          if (DVar5 == 0xffffffff) goto LAB_18000a081;
          if (local_ac4 != '\0') {
            if ((param_4 == (uchar *)0x0) || (param_5 < DVar5 + uVar9 * 8 + local_ac8)) {
              local_ac4 = '\0';
            }
            else {
              if (uVar9 != 0) {
                param_4[local_ac8 + 3] = (uchar)(DVar5 >> 0x18);
                param_4[local_ac8 + 2] = (uchar)(DVar5 >> 0x10);
                param_4[local_ac8 + 1] = (uchar)(DVar5 >> 8);
                param_4[local_ac8] = (uchar)DVar5;
              }
              BVar6 = ReadFile(hFile,param_4 + (iVar1 + local_ac8),DVar5,(LPDWORD)0x0,
                               (LPOVERLAPPED)0x0);
              if (BVar6 == 0) goto LAB_18000a081;
              if (uVar9 != 0) {
                iVar7 = iVar1 + DVar5;
                param_4[local_ac8 + 3 + iVar7] = 0xff;
                param_4[local_ac8 + 2 + iVar7] = 0xff;
                param_4[local_ac8 + 1 + iVar7] = 0xff;
                param_4[local_ac8 + iVar7] = 0xff;
              }
            }
          }
          param_2 = param_2 + 1;
          local_ac8 = local_ac8 + iVar1 + DVar5;
        } while (uVar9 != 0);
        local_ac8 = local_ac8 + iVar1;
        if ((local_ac8 == 0) && (param_4 == (uchar *)0x0)) {
          local_ac8 = 1;
        }
        *local_aa8 = local_ac8;
        if ((local_ac4 == '\0') && (param_4 != (uchar *)0x0)) {
          uVar8 = 0x80284005;
        }
        else if (local_aa0 != (uint *)0x0) {
          if (param_4 == (uchar *)0x0) {
            param_2 = local_abc;
          }
          *local_aa0 = param_2;
        }
LAB_18000a086:
        if (hFile == (HANDLE)0x0) {
          return uVar8;
        }
        goto LAB_18000a092;
      }
      lVar4 = RtlStringCchPrintfW(local_a98,0x104,(ushort *)L"%s\\Logs\\MeasuredBoot",local_258);
      if (-1 < lVar4) {
        local_ac8 = 0x208;
        iVar1 = RtlGetPersistedStateLocation(L"TpmDriverLogPath",0,local_a98,1);
        if (iVar1 == 0) goto LAB_180009e50;
      }
    }
  }
LAB_18000a08d:
  uVar8 = 0x80284001;
LAB_18000a092:
  CloseHandle(hFile);
  return uVar8;
}



===== TryGetPointer @ 18000a0d4 =====

/* public: static long __cdecl wil::details_abi::SemaphoreValue::TryGetPointer(unsigned short const
   * __ptr64,void * __ptr64 * __ptr64) */

long __cdecl wil::details_abi::SemaphoreValue::TryGetPointer(ushort *param_1,void **param_2)

{
  long lVar1;
  __uint64 *p_Var2;
  bool *in_R9;
  void *unaff_retaddr;
  __uint64 local_res10 [3];
  
  *param_2 = (void *)0x0;
  p_Var2 = local_res10;
  local_res10[0] = 0;
  lVar1 = TryGetValueInternal(param_1,SUB81(param_2,0),p_Var2,in_R9);
  if (lVar1 < 0) {
    details::in1diag3::Return_Hr(unaff_retaddr,100,(char *)p_Var2,lVar1);
    details::in1diag3::Return_Hr(unaff_retaddr,0x6d,(char *)p_Var2,lVar1);
  }
  else {
    *param_2 = (void *)(local_res10[0] << 2);
    lVar1 = 0;
  }
  return lVar1;
}



===== TryGetValueInternal @ 18000a144 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static long __cdecl wil::details_abi::SemaphoreValue::TryGetValueInternal(unsigned short
   const * __ptr64,bool,unsigned __int64 * __ptr64,bool * __ptr64) */

long __cdecl
wil::details_abi::SemaphoreValue::TryGetValueInternal
          (ushort *param_1,bool param_2,__uint64 *param_3,bool *param_4)

{
  DWORD DVar1;
  long lVar2;
  long lVar3;
  __uint64 _Var4;
  long *plVar5;
  LPCWSTR pWVar6;
  void *unaff_retaddr;
  undefined1 auStackY_278 [32];
  size_t in_stack_fffffffffffffda8;
  long local_248;
  long local_244;
  HANDLE local_240;
  HANDLE local_238 [2];
  wchar_t local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_278;
  lVar2 = 0;
  *param_3 = 0;
  _Var4 = 0x104;
  StringCopyWorkerW(local_228,0x104,param_3,(STRSAFE_PCNZWCH)param_1,in_stack_fffffffffffffda8);
  StringCchCatW((ushort *)local_228,_Var4,(ushort *)L"_p0");
  pWVar6 = local_228;
  local_238[0] = OpenSemaphoreW(0x1f0003,0,pWVar6);
  if (local_238[0] == (HANDLE)0x0) {
    DVar1 = GetLastError();
    if (DVar1 != 2) {
      lVar2 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xcd,(char *)pWVar6);
    }
  }
  else {
    plVar5 = &local_244;
    local_244 = 0;
    local_248 = 0;
    lVar3 = GetValueFromSemaphore(local_238[0],plVar5);
    if (lVar3 < 0) {
      details::in1diag3::Return_Hr(unaff_retaddr,0xd3,(char *)pWVar6,lVar3);
      lVar2 = lVar3;
    }
    else {
      StringCchCatW((ushort *)local_228,(__uint64)plVar5,(ushort *)L"h");
      pWVar6 = local_228;
      local_240 = OpenSemaphoreW(0x1f0003,0,pWVar6);
      if (local_240 == (HANDLE)0x0) {
        lVar2 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xd9,(char *)pWVar6);
        details::
        unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
        ::
        ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                  ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                    *)&local_240);
      }
      else {
        lVar3 = GetValueFromSemaphore(local_240,&local_248);
        if (lVar3 < 0) {
          details::in1diag3::Return_Hr(unaff_retaddr,0xdb,(char *)pWVar6,lVar3);
          details::
          unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
          ::
          ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                    ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                      *)&local_240);
          lVar2 = lVar3;
        }
        else {
          details::
          unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
          ::
          ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                    ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
                      *)&local_240);
          *param_3 = (longlong)local_248 << 0x1f | (longlong)local_244;
        }
      }
    }
  }
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)local_238);
  return lVar2;
}



===== Unsubscribe @ 18000a304 =====

/* public: void __cdecl wil::details_abi::SubscriptionList::Unsubscribe(class wil::srwlock &
   __ptr64,struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64) __ptr64 */

void __thiscall
wil::details_abi::SubscriptionList::Unsubscribe
          (SubscriptionList *this,srwlock *param_1,FEATURE_STATE_CHANGE_SUBSCRIPTION__ *param_2)

{
  undefined8 *puVar1;
  srwlock *local_res18;
  SubscriptionList *local_res20;
  
  if (param_2 != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)this);
    local_res20 = this;
    AcquireSRWLockExclusive((PSRWLOCK)param_1);
    if (param_2 + -1 <
        (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
        ((ulonglong)(*(longlong *)(this + 0x30) - *(longlong *)(this + 0x28)) >> 4)) {
      puVar1 = (undefined8 *)(*(longlong *)(this + 0x28) + (longlong)(param_2 + -1) * 0x10);
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    local_res18 = param_1;
    details::
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res18);
    details::
    unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_>
                *)&local_res20);
  }
  return;
}



===== UnsubscribeProcessWideUsageFlush @ 18000a398 =====

/* void __cdecl wil::details::UnsubscribeProcessWideUsageFlush(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64) */

void __cdecl
wil::details::UnsubscribeProcessWideUsageFlush(FEATURE_STATE_CHANGE_SUBSCRIPTION__ *param_1)

{
  if ((param_1 != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) && (DAT_1800150e0 != (srwlock *)0x0))
  {
    details_abi::SubscriptionList::Unsubscribe
              ((SubscriptionList *)(DAT_1800150e0 + 200),DAT_1800150e0,param_1);
  }
  return;
}



===== UpdateCount @ 18000a3c8 =====

/* public: void __cdecl wil::details_abi::UsageIndexProperty::UpdateCount(unsigned int) __ptr64 */

void __thiscall
wil::details_abi::UsageIndexProperty::UpdateCount(UsageIndexProperty *this,uint param_1)

{
  rsize_t _DstSize;
  UsageIndexProperty *_Src;
  rsize_t _MaxCount;
  undefined2 local_res10 [12];
  
  _Src = this + 4;
  if (*(uint *)_Src != param_1) {
    *(uint *)_Src = param_1;
    if (this[2] == (UsageIndexProperty)0x1) {
      _MaxCount = 2;
      local_res10[0] = (undefined2)param_1;
      _Src = (UsageIndexProperty *)local_res10;
      _DstSize = 2;
    }
    else {
      if (this[2] != (UsageIndexProperty)0x2) {
        return;
      }
      _DstSize = 4;
      _MaxCount = 4;
    }
    memcpy_s(*(void **)(this + 0x10),_DstSize,_Src,_MaxCount);
  }
  return;
}



===== WilApiImpl_GetFeatureEnabledState @ 18000a420 =====

/* enum FEATURE_ENABLED_STATE __cdecl wil::details::WilApiImpl_GetFeatureEnabledState(unsigned
   int,enum FEATURE_CHANGE_TIME,int * __ptr64) */

FEATURE_ENABLED_STATE __cdecl
wil::details::WilApiImpl_GetFeatureEnabledState
          (uint param_1,FEATURE_CHANGE_TIME param_2,int *param_3)

{
  bool bVar1;
  FEATURE_ENABLED_STATE FVar2;
  FEATURE_ENABLED_STATE local_28 [10];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  bVar1 = IsFeatureConfigured((wil_FeatureState *)local_28,param_1,(param_2 & 0xffffff7f) - 2 < 2,
                              param_2 >> 7 & 1,param_3);
  FVar2 = 0;
  if (bVar1) {
    FVar2 = local_28[0];
  }
  if (local_28[4] != 0) {
    FVar2 = FVar2 | 0x80;
  }
  if (local_28[5] != 0) {
    FVar2 = FVar2 | 0x40;
  }
  return FVar2;
}



===== WilApiImpl_RecordFeatureUsage @ 18000a490 =====

/* void __cdecl wil::details::WilApiImpl_RecordFeatureUsage(unsigned int,unsigned int,unsigned
   int,char const * __ptr64) */

void __cdecl
wil::details::WilApiImpl_RecordFeatureUsage(uint param_1,uint param_2,uint param_3,char *param_4)

{
  wil_details_ServiceReportingKind wVar1;
  
  wVar1 = param_2 & 0x7fffffff;
  if (((param_1 == 0) && (param_3 == 0)) && (wVar1 == 0)) {
    FeatureStateManager::FlushUsage((FeatureStateManager *)&g_featureStateManager);
    return;
  }
  if (wVar1 >> 0x1e != 0) {
    FeatureStateManager::QueueBackgroundSRUMUsageReporting
              ((FeatureStateManager *)&g_featureStateManager,param_1,(ushort)param_2,param_3);
    return;
  }
  if ((param_3 == 0) && (wVar1 != 0xfe)) {
    wil_RtlStagingConfig_RecordFeatureUsage(param_1,(short)wVar1,param_2 >> 0x1f);
    return;
  }
  FeatureStateManager::RecordFeatureUsage
            ((FeatureStateManager *)&g_featureStateManager,param_1,wVar1,(ulonglong)param_3);
  return;
}



===== WilApiImpl_SubscribeFeatureStateChangeNotification @ 18000a500 =====

/* void __cdecl wil::details::WilApiImpl_SubscribeFeatureStateChangeNotification(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64),void *
   __ptr64) */

void __cdecl
wil::details::WilApiImpl_SubscribeFeatureStateChangeNotification
          (FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,_func_void_void_ptr *param_2,void *param_3)

{
  __int64 _Var1;
  void *pvVar2;
  undefined *local_res18;
  
  if (param_3 == (void *)0xffffffffffffffff) {
    FeatureStateManager::SubscribeToUsageFlush
              ((FeatureStateManager *)&g_featureStateManager,param_1,param_2);
    return;
  }
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  if (g_featureStateManager == (shutdown_aware_object<wil::details::FeatureStateManager>)0x0) {
    return;
  }
  pvVar2 = param_3;
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1800150e8);
  local_res18 = &DAT_1800150e8;
  if (DAT_180015158 == 0) {
    DAT_180015158 = 0;
    _Var1 = wil_details_RtlRegisterFeatureConfigurationChangeNotification
                      (<lambda_1ad7ecfab602a777ecf020873216a663>::<lambda_invoker_cdecl>,
                       &g_featureStateManager,pvVar2,&DAT_180015158);
    if ((int)_Var1 != 0) goto LAB_18000a5a4;
  }
  details_abi::SubscriptionList::SubscribeUnderLock
            ((SubscriptionList *)&DAT_180015110,param_1,param_2,param_3);
LAB_18000a5a4:
  unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              *)&local_res18);
  return;
}



===== WilApiImpl_UnsubscribeFeatureStateChangeNotification @ 18000a5d0 =====

/* void __cdecl wil::details::WilApiImpl_UnsubscribeFeatureStateChangeNotification(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64) */

void __cdecl
wil::details::WilApiImpl_UnsubscribeFeatureStateChangeNotification
          (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *param_1)

{
  SubscriptionList *this;
  
  if (((ulonglong)param_1 >> 0x1f & 1) == 0) {
    if (g_featureStateManager == (shutdown_aware_object<wil::details::FeatureStateManager>)0x0) {
      return;
    }
    this = (SubscriptionList *)&DAT_180015110;
  }
  else {
    if (g_featureStateManager == (shutdown_aware_object<wil::details::FeatureStateManager>)0x0) {
      return;
    }
    param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)((ulonglong)param_1 & 0xffffffff7fffffff);
    this = (SubscriptionList *)&DAT_180015160;
  }
  details_abi::SubscriptionList::Unsubscribe(this,(srwlock *)&DAT_1800150e8,param_1);
  return;
}



===== WilApi_RecordFeatureUsage @ 18000a628 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilApi_RecordFeatureUsage(unsigned int,unsigned int,unsigned int,char
   const * __ptr64) */

void __cdecl
wil::details::WilApi_RecordFeatureUsage(uint param_1,uint param_2,uint param_3,char *param_4)

{
  code *pcVar1;
  
  pcVar1 = g_wil_details_internalRecordFeatureUsage;
  if ((g_wil_details_internalRecordFeatureUsage != (code *)0x0) ||
     (pcVar1 = g_wil_details_apiRecordFeatureUsage,
     g_wil_details_apiRecordFeatureUsage != (code *)0x0)) {
    (*pcVar1)();
  }
  return;
}



===== WilApi_RecordFeatureUsageReports @ 18000a658 =====

/* void __cdecl wil::details::WilApi_RecordFeatureUsageReports(struct __WIL_RTL_FEATURE_USAGE_DATA *
   __ptr64,unsigned __int64) */

void __cdecl
wil::details::WilApi_RecordFeatureUsageReports
          (__WIL_RTL_FEATURE_USAGE_DATA *param_1,__uint64 param_2)

{
  __WIL_RTL_FEATURE_USAGE_DATA *p_Var1;
  char *in_R9;
  
  if (param_2 != 0) {
    p_Var1 = param_1 + 4;
    do {
      WilApi_RecordFeatureUsage
                (*(uint *)(p_Var1 + -4),(uint)*(ushort *)p_Var1,(uint)*(ushort *)(p_Var1 + 2),in_R9)
      ;
      p_Var1 = p_Var1 + 8;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return;
}



===== WilApi_UnsubscribeFeatureStateChangeNotification @ 18000a69c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64) */

void __cdecl
wil::details::WilApi_UnsubscribeFeatureStateChangeNotification
          (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *param_1)

{
  code *pcVar1;
  
  pcVar1 = g_wil_details_internalUnsubscribeFeatureStateChangeNotification;
  if ((g_wil_details_internalUnsubscribeFeatureStateChangeNotification != (code *)0x0) ||
     (pcVar1 = g_wil_details_apiUnsubscribeFeatureStateChangeNotification,
     g_wil_details_apiUnsubscribeFeatureStateChangeNotification != (code *)0x0)) {
    (*pcVar1)();
  }
  return;
}



===== WilFailFast @ 18000a6cc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilFailFast(struct wil::FailureInfo const & __ptr64) */

void __cdecl wil::details::WilFailFast(FailureInfo *param_1)

{
  code *pcVar1;
  _CONTEXT *p_Var2;
  _EXCEPTION_RECORD local_a8;
  
  if (g_pfnWilFailFast != (_func_bool_FailureInfo_ptr *)0x0) {
    (*g_pfnWilFailFast)(param_1);
  }
  if (g_pfnFailfastWithContextCallback != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnFailfastWithContextCallback)(param_1);
  }
  p_Var2 = (_CONTEXT *)0x0;
  memset(&local_a8,0,0x98);
  local_a8.ExceptionAddress = *(PVOID *)(param_1 + 0x88);
  local_a8.NumberParameters = 1;
  local_a8.ExceptionCode = 0xc0000409;
  local_a8.ExceptionFlags = 1;
  local_a8.ExceptionInformation[0] = 7;
  if (local_a8.ExceptionAddress == (PVOID)0x0) {
    WilRaiseFailFastException(&local_a8,p_Var2,1);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  local_a8.ExceptionInformation[1] = (ULONG_PTR)*(int *)(param_1 + 8);
  local_a8.ExceptionInformation[2] = (ULONG_PTR)*(uint *)(param_1 + 0x40);
  local_a8.NumberParameters = 3;
  WilRaiseFailFastException(&local_a8,p_Var2,0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WilRaiseFailFastException @ 18000a77c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilRaiseFailFastException(struct _EXCEPTION_RECORD * __ptr64,struct
   _CONTEXT * __ptr64,unsigned long) */

void __cdecl
wil::details::WilRaiseFailFastException(_EXCEPTION_RECORD *param_1,_CONTEXT *param_2,ulong param_3)

{
  code *pcVar1;
  
  if (g_pfnRaiseFailFastException != (_func_void__EXCEPTION_RECORD_ptr__CONTEXT_ptr_ulong *)0x0) {
    (*g_pfnRaiseFailFastException)(param_1,(_CONTEXT *)0x0,param_3);
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(7);
  return;
}



===== Write @ 18000a7a8 =====

/* public: bool __cdecl wil::details_abi::UsageIndexProperty::Write(unsigned char * __ptr64 &
   __ptr64,unsigned char * __ptr64)const __ptr64 */

bool __thiscall
wil::details_abi::UsageIndexProperty::Write(UsageIndexProperty *this,uchar **param_1,uchar *param_2)

{
  rsize_t _DstSize;
  uchar *_Dst;
  UsageIndexProperty *_Src;
  rsize_t _MaxCount;
  ulonglong _MaxCount_00;
  uchar *puVar1;
  undefined2 local_res8 [4];
  
  _Dst = *param_1;
  if (this[2] == (UsageIndexProperty)0x1) {
    puVar1 = _Dst + 2;
    if (param_2 < puVar1) {
      return false;
    }
    local_res8[0] = *(undefined2 *)(this + 4);
    _Src = (UsageIndexProperty *)local_res8;
    _MaxCount = 2;
    _DstSize = 2;
  }
  else {
    if (this[2] != (UsageIndexProperty)0x2) goto LAB_18000a81a;
    puVar1 = _Dst + 4;
    if (param_2 < puVar1) {
      return false;
    }
    _DstSize = 4;
    _Src = this + 4;
    _MaxCount = 4;
  }
  memcpy_s(_Dst,_DstSize,_Src,_MaxCount);
  _Dst = puVar1;
LAB_18000a81a:
  if (*(short *)this == 0) {
    if (param_2 < _Dst + 2) {
      return false;
    }
    memcpy_s(_Dst,(longlong)param_2 - (longlong)_Dst,this + 8,2);
    _Dst = _Dst + 2;
  }
  _MaxCount_00 = (ulonglong)*(ushort *)(this + 8);
  if (param_2 < _Dst + _MaxCount_00) {
    return false;
  }
  memcpy_s(_Dst,(longlong)param_2 - (longlong)_Dst,*(void **)(this + 0x18),_MaxCount_00);
  *param_1 = _Dst + *(ushort *)(this + 8);
  return true;
}



===== _FailFastImmediate_Unexpected @ 18000a8a0 =====

/* void __cdecl wil::details::in1diag3::_FailFastImmediate_Unexpected(void) */

void __cdecl wil::details::in1diag3::_FailFastImmediate_Unexpected(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(7);
  return;
}



===== _FailFast_GetLastError @ 18000a8b0 =====

/* void __cdecl wil::details::in1diag3::_FailFast_GetLastError(void * __ptr64,unsigned int,char
   const * __ptr64) */

void __cdecl
wil::details::in1diag3::_FailFast_GetLastError(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffe8;
  
  ReportFailure_GetLastError<3>
            (param_1,param_2,param_3,in_R9,in_stack_ffffffffffffffe8,unaff_retaddr);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _FailFast_Unexpected @ 18000a8cc =====

/* void __cdecl wil::details::in1diag3::_FailFast_Unexpected(void * __ptr64,unsigned int,char const
   * __ptr64) */

void __cdecl wil::details::in1diag3::_FailFast_Unexpected(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  long in_stack_ffffffffffffffe8;
  
  ReportFailure_Hr<3>(param_1,0x137b,"onecore\\internal\\sdk\\inc\\wil\\Staging.h",in_R9,
                      in_stack_ffffffffffffffd8,unaff_retaddr,in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __clone @ 18000a900 =====

/* public: virtual void __cdecl wistd::__function::__func<class
   <lambda_8db0ce862824541f40dfb767113f1e28>,bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::__clone(class wistd::__function::__base<bool
   __cdecl(void * __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned int)> *
   __ptr64)const __ptr64 */

void __thiscall
wistd::__function::
__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
::__clone(__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
          *this,__base<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
                *param_1)

{
  undefined8 uVar1;
  
  *(undefined ***)param_1 = &_vftable_;
  uVar1 = *(undefined8 *)(this + 0x10);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(this + 8);
  *(undefined8 *)(param_1 + 0x10) = uVar1;
  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(this + 0x18);
  return;
}



===== acquire @ 18000a924 =====

/* public: class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void
   __cdecl wil::details::ReleaseMutex(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > > __cdecl wil::mutex_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<void * __ptr64,void
   (__cdecl*)(void * __ptr64) noexcept,&void __cdecl wil::details::CloseHandle(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >,struct wil::err_returncode_policy>::acquire(unsigned long *
   __ptr64,unsigned long,int)const __ptr64 */

ulong * __thiscall
wil::
mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
::acquire(mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
          *this,ulong *param_1,ulong param_2,int param_3)

{
  code *pcVar1;
  DWORD DVar2;
  ulong *puVar3;
  uint uVar4;
  HANDLE hHandle;
  char *pcVar5;
  void *unaff_retaddr;
  
  hHandle = *(HANDLE *)this;
  pcVar5 = (char *)0x0;
  uVar4 = 0xffffffff;
  DVar2 = WaitForSingleObjectEx(hHandle,0xffffffff,0);
  if (DVar2 == 0x102) {
    hHandle = (HANDLE)0x0;
  }
  else if ((DVar2 & 0xffffff7f) != 0) {
    details::in1diag3::FailFast_Unexpected(unaff_retaddr,uVar4,pcVar5);
    pcVar1 = (code *)swi(3);
    puVar3 = (ulong *)(*pcVar1)();
    return puVar3;
  }
  *(HANDLE *)param_1 = hHandle;
  return param_1;
}



===== create @ 18000a97c =====

/* public: long __cdecl wil::semaphore_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void
   __cdecl wil::details::CloseHandle(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> >,struct
   wil::err_returncode_policy>::create(long,long,unsigned short const * __ptr64,unsigned long,struct
   _SECURITY_ATTRIBUTES * __ptr64,bool * __ptr64) __ptr64 */

long __thiscall
wil::
semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
::create(semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
         *this,long param_1,long param_2,ushort *param_3,ulong param_4,_SECURITY_ATTRIBUTES *param_5
        ,bool *param_6)

{
  long lVar1;
  HANDLE pvVar2;
  
  lVar1 = 0;
  pvVar2 = CreateSemaphoreExW((LPSECURITY_ATTRIBUTES)0x0,param_1,param_2,(LPCWSTR)param_3,0,0x1f0003
                             );
  if (pvVar2 == (HANDLE)0x0) {
    lVar1 = details::GetLastErrorFailHr();
  }
  else {
    GetLastError();
    details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
             *)this,pvVar2);
  }
  return lVar1;
}



===== destroy @ 18000a9f0 =====

/* public: virtual void __cdecl wistd::__function::__func<class
   <lambda_8db0ce862824541f40dfb767113f1e28>,bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::destroy(void) __ptr64 */

void __thiscall
wistd::__function::
__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
::destroy(__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
          *this)

{
  return;
}



===== ensure @ 18000a9fc =====

/* public: bool __cdecl wil::details_abi::heap_buffer::ensure(unsigned __int64) __ptr64 */

bool __thiscall wil::details_abi::heap_buffer::ensure(heap_buffer *this,__uint64 param_1)

{
  ulonglong uVar1;
  bool bVar2;
  
  if ((*(longlong *)(this + 8) - *(longlong *)this) + param_1 <
      (ulonglong)(*(longlong *)(this + 0x10) - *(longlong *)this)) {
    return true;
  }
  uVar1 = (*(longlong *)(this + 0x10) - *(longlong *)this) * 2;
  if (param_1 < uVar1) {
    param_1 = uVar1;
  }
  bVar2 = reserve(this,param_1);
  return bVar2;
}



===== push_back @ 18000aa2c =====

/* public: bool __cdecl wil::details_abi::heap_buffer::push_back(void const * __ptr64,unsigned
   __int64) __ptr64 */

bool __thiscall
wil::details_abi::heap_buffer::push_back(heap_buffer *this,void *param_1,__uint64 param_2)

{
  void *_Dst;
  bool bVar1;
  
  bVar1 = ensure(this,param_2);
  if (bVar1) {
    _Dst = *(void **)(this + 8);
    memcpy_s(_Dst,-(ulonglong)(_Dst < *(void **)(this + 0x10)) &
                  *(longlong *)(this + 0x10) - (longlong)_Dst,param_1,param_2);
    *(__uint64 *)(this + 8) = *(longlong *)(this + 8) + param_2;
  }
  return bVar1;
}



===== reserve @ 18000aa90 =====

/* public: bool __cdecl wil::details_abi::heap_buffer::reserve(unsigned __int64) __ptr64 */

bool __thiscall wil::details_abi::heap_buffer::reserve(heap_buffer *this,__uint64 param_1)

{
  longlong lVar1;
  longlong lVar2;
  void *pvVar3;
  void *_Dst;
  __uint64 _DstSize;
  last_error_context local_res8 [8];
  
  if ((ulonglong)(*(longlong *)(this + 0x10) - *(longlong *)this) < param_1) {
    last_error_context::last_error_context(local_res8);
    _DstSize = (param_1 & 0xffffffffffffffc0) + 0x40;
    _Dst = details::ProcessHeapAlloc(0,_DstSize);
    if (_Dst == (void *)0x0) {
      last_error_context::~last_error_context(local_res8);
      return false;
    }
    lVar1 = *(longlong *)(this + 8);
    lVar2 = *(longlong *)this;
    memcpy_s(_Dst,_DstSize,*(void **)this,lVar1 - lVar2);
    pvVar3 = *(void **)(this + 0x18);
    *(void **)(this + 0x18) = _Dst;
    if (pvVar3 != (void *)0x0) {
      details::FreeProcessHeap(pvVar3);
    }
    *(void **)this = _Dst;
    *(longlong *)(this + 8) = (lVar1 - lVar2) + (longlong)_Dst;
    *(__uint64 *)(this + 0x10) = (longlong)_Dst + _DstSize;
    last_error_context::~last_error_context(local_res8);
  }
  return true;
}



===== reset @ 18000ab50 =====

/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _KEY_VALUE_PARTIAL_INFORMATION * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   TpmFree(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct
   _KEY_VALUE_PARTIAL_INFORMATION * __ptr64,struct _KEY_VALUE_PARTIAL_INFORMATION *
   __ptr64,0,std::nullptr_t> >::reset(struct _KEY_VALUE_PARTIAL_INFORMATION * __ptr64) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_TpmFree(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,_KEY_VALUE_PARTIAL_INFORMATION*___ptr64,0,std::nullptr_t>_>
        *this,_KEY_VALUE_PARTIAL_INFORMATION *param_1)

{
  void *pvVar1;
  last_error_context local_res8 [8];
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    last_error_context::last_error_context(local_res8);
    FreeProcessHeap(pvVar1);
    last_error_context::~last_error_context(local_res8);
  }
  *(_KEY_VALUE_PARTIAL_INFORMATION **)this = param_1;
  return;
}



===== reset @ 18000aba4 =====

/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void __cdecl wil::details::CloseHandle(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >::reset(void * __ptr64) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
        *this,void *param_1)

{
  void *pvVar1;
  last_error_context local_res8 [8];
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    last_error_context::last_error_context(local_res8);
    CloseHandle(pvVar1);
    last_error_context::~last_error_context(local_res8);
  }
  *(void **)this = param_1;
  return;
}



===== reset @ 18000abf8 =====

/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void __cdecl wil::details::ReleaseMutex(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,2>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >::reset(void * __ptr64) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
        *this,void *param_1)

{
  void *pvVar1;
  last_error_context local_res8 [8];
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    last_error_context::last_error_context(local_res8);
    ReleaseMutex(pvVar1);
    last_error_context::~last_error_context(local_res8);
  }
  *(void **)this = param_1;
  return;
}



===== wil_details_WriteSRUMWnfUsageBuffer @ 18000ac4c =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl wil_details_WriteSRUMWnfUsageBuffer(class wil::details_abi::heap_vector<struct
   wil_details_FeatureUsageSRUM> * __ptr64) */

long __cdecl wil_details_WriteSRUMWnfUsageBuffer(heap_vector<wil_details_FeatureUsageSRUM> *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  __int64 _Var4;
  ulonglong uVar5;
  int *piVar6;
  undefined8 uVar7;
  int iVar8;
  long lVar9;
  undefined8 uVar10;
  int *piVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined1 auStackY_1078 [32];
  int *piVar14;
  uint local_1038;
  undefined4 local_1034 [3];
  int local_1028 [1024];
  ulonglong local_28;
  undefined8 local_20;
  
  local_20 = 0x18000ac71;
  local_28 = __security_cookie ^ (ulonglong)auStackY_1078;
  iVar3 = 0;
  uVar5 = 0;
  lVar9 = 0;
  if (0xb < (ulonglong)(*(longlong *)(param_1 + 8) - *(longlong *)param_1)) {
    iVar8 = 0;
    do {
      uVar7 = 0;
      uVar10 = 0x1000;
      memset(local_1028,0,0x1000);
      local_1034[0] = 0;
      piVar14 = local_1028;
      local_1038 = 0x1000;
      _Var4 = wil_details_NtQueryWnfStateData
                        (&__WIL_WNF_WIL_FEATURE_USAGE_FOR_SRUM,uVar7,uVar10,local_1034,piVar14,
                         &local_1038);
      iVar3 = (int)_Var4;
      if (iVar3 == 0) {
        uVar5 = (ulonglong)local_1038;
        if (uVar5 != (uVar5 / 0xc) * 0xc) {
          uVar5 = 0;
          local_1038 = 0;
        }
        piVar11 = *(int **)param_1;
        piVar1 = piVar11 + ((ulonglong)(*(longlong *)(param_1 + 8) - (longlong)piVar11) / 0xc) * 3;
        uVar13 = uVar5 / 0xc;
        while( true ) {
          if (piVar11 == piVar1) break;
          piVar2 = local_1028 + uVar13 * 3;
          for (piVar6 = local_1028; uVar12 = uVar13, piVar6 != piVar2; piVar6 = piVar6 + 3) {
            if ((*piVar6 == *piVar11) && ((short)piVar6[1] == (short)piVar11[1])) {
              piVar6[2] = piVar6[2] + piVar11[2];
              uVar5 = (ulonglong)local_1038;
              goto LAB_18000adaf;
            }
          }
          if (uVar5 + 0xc < 0x1001) {
            local_1038 = (uint)uVar5 + 0xc;
            uVar5 = (ulonglong)local_1038;
            *(undefined8 *)piVar2 = *(undefined8 *)piVar11;
            uVar12 = (ulonglong)((int)uVar13 + 1);
            local_1028[uVar13 * 3 + 2] = piVar11[2];
          }
LAB_18000adaf:
          piVar11 = piVar11 + 3;
          uVar13 = uVar12;
        }
        uVar5 = wil_details_NtUpdateWnfStateData
                          (&__WIL_WNF_WIL_FEATURE_USAGE_FOR_SRUM,local_1028,(uint)uVar5,uVar5,
                           piVar14,local_1034[0],1);
        uVar5 = uVar5 & 0xffffffff;
      }
      iVar8 = iVar8 + 1;
      lVar9 = (long)uVar5;
    } while (((lVar9 == -0x3fffffff) && (iVar8 < 100)) && (iVar3 == 0));
  }
  if (iVar3 == 0) {
    iVar3 = lVar9;
  }
  return iVar3;
}



===== Feature_TpmMissingLogsMaa__private_IsEnabledDeviceUsageNoInline @ 18000ae30 =====

uint Feature_TpmMissingLogsMaa__private_IsEnabledDeviceUsageNoInline(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_TpmMissingLogsMaa__private_featureState;
  if ((Feature_TpmMissingLogsMaa__private_featureState & 0x10) == 0) {
    uVar1 = wil_details_IsEnabledFallback
                      (local_res8,3,&Feature_TpmMissingLogsMaa__private_descriptor);
    return uVar1;
  }
  return Feature_TpmMissingLogsMaa__private_featureState & 1;
}



===== Tbsi_Create_Windows_Key @ 18000ae80 =====

uint Tbsi_Create_Windows_Key(int param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  int local_res8 [2];
  void *local_res10;
  undefined4 local_res18;
  undefined4 local_res1c;
  
                    /* 0xae80  7  Tbsi_Create_Windows_Key */
  uVar2 = 0;
  local_res10 = (void *)0x0;
  if ((param_1 + 0x7effffffU & 0xfffeffff) == 0) {
    local_res18 = 2;
    local_res1c = 4;
    uVar1 = Tbsi_Context_Create((tdTBS_CONTEXT_PARAMS *)&local_res18,&local_res10);
    if (-1 < (int)uVar1) {
      local_res8[0] = param_1;
      uVar3 = TpmDeviceIoControl(local_res10,0x22c19c,local_res8,4,0,(undefined4 *)0x0);
      uVar2 = (uint)uVar3;
    }
    if (local_res10 != (void *)0x0) {
      Tbsip_Context_Close(local_res10);
    }
    if (-1 < (int)uVar2) {
      return uVar1;
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  uVar2 = TbsRemapError(uVar2,0x972);
  return uVar2;
}



===== Tbsi_Get_OwnerAuth @ 18000af30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint Tbsi_Get_OwnerAuth(undefined8 param_1,int param_2,uchar *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  short *_Dst;
  uchar *puVar6;
  size_t _Size;
  wchar_t *pwVar7;
  uint uVar8;
  ulonglong _Size_00;
  ulonglong uVar9;
  wchar_t *pwVar10;
  longlong *plVar11;
  wchar_t *pwVar12;
  undefined1 auStack_638 [32];
  undefined1 *local_618;
  uint *local_610;
  int *local_608;
  uint local_5f8;
  int local_5f4;
  int local_5f0;
  longlong local_5e8;
  undefined4 local_5e0;
  int local_5dc;
  longlong local_5d8;
  uchar *local_5d0;
  undefined8 local_5c8;
  undefined8 uStack_5c0;
  undefined8 local_5b8;
  undefined8 uStack_5b0;
  undefined8 local_5a8;
  undefined8 uStack_5a0;
  undefined8 *local_598;
  undefined8 uStack_590;
  undefined8 local_588;
  undefined8 uStack_580;
  undefined8 local_578;
  undefined8 uStack_570;
  undefined8 local_568;
  undefined8 uStack_560;
  wchar_t local_558 [16];
  wchar_t local_538 [32];
  wchar_t local_4f8 [16];
  wchar_t local_4d8 [16];
  wchar_t local_4b8 [20];
  wchar_t local_490 [24];
  wchar_t local_460 [20];
  wchar_t local_438 [40];
  wchar_t local_3e8 [32];
  wchar_t local_3a8 [48];
  wchar_t local_348 [120];
  undefined1 local_258 [528];
  ulonglong local_48;
  
                    /* 0xaf30  10  Tbsi_Get_OwnerAuth */
  pwVar7 = local_538;
  local_48 = __security_cookie ^ (ulonglong)auStack_638;
  builtin_wcsncpy(local_538,L"TpmRegDriverPersistedDataAdmin",0x1f);
  local_5a8 = 0;
  uStack_5a0 = 0;
  local_598 = (undefined8 *)0x0;
  uStack_590 = 0;
  builtin_wcsncpy(local_438 + 0x20,L"ment",5);
  local_588 = 0;
  uStack_580 = 0;
  builtin_wcsncpy(local_348 + 0x70,L"ement",6);
  builtin_wcsncpy(local_3e8,L"TpmRegDriverPersistedDataUser",0x1e);
  builtin_wcsncpy(local_348 + 0x10,L"System\\CurrentControlSet\\Services\\TPM\\WMI\\Admin",0x30);
  builtin_wcsncpy(local_438,L"TpmRegDriverPersistedDataEndorse",0x20);
  builtin_wcsncpy(local_348 + 0x40,L"System\\CurrentControlSet\\Services\\TPM\\WMI\\Endors",0x30);
  builtin_wcsncpy(local_3a8,L"System\\CurrentControlSet\\Services\\TPM\\WMI\\User",0x2f);
  puVar6 = (uchar *)0x0;
  builtin_wcsncpy(local_4b8,L"\\Registry\\Machine\\",0x13);
  local_5b8 = 0;
  uStack_5b0 = 0;
  builtin_wcsncpy(local_4d8,L"OwnerAuthFull",0xe);
  builtin_wcsncpy(local_558,L"OwnerAuthAdmin",0xf);
  builtin_wcsncpy(local_490,L"OwnerAuthEndorse",0x10);
  builtin_wcsncpy(local_490 + 0x10,L"ment",5);
  builtin_wcsncpy(local_4f8,L"OwnerAuthUser",0xe);
  builtin_wcsncpy(local_460,L"StorageOwnerAuth",0x11);
  local_5f0 = 0;
  local_5e8 = 0;
  local_5f8 = 0;
  local_5e0 = 0;
  builtin_wcsncpy(local_348,L"EndorsementAuth",0x10);
  local_5c8 = 0;
  uStack_5c0 = 0;
  local_568 = 0;
  uStack_560 = 0;
  local_578 = 0;
  uStack_570 = 0;
  local_5dc = param_2;
  local_5d0 = param_3;
  memset(local_258,0,0x208);
  local_5f4 = 0x208;
  _Dst = (short *)0x0;
  if ((param_4 == (uint *)0x0) || ((*param_4 != 0 && (param_3 == (uchar *)0x0)))) {
    uVar3 = 0x80284003;
    goto LAB_18000b6b5;
  }
  local_618 = (undefined1 *)CONCAT44(local_618._4_4_,0x10);
  iVar2 = NtQueryInformationFile(param_1,&local_578,&local_5e0,4);
  if (iVar2 < 0) {
    uVar3 = 0x80284007;
    goto LAB_18000b6b5;
  }
  uVar3 = Tbsi_GetDeviceInfo(0x10,&local_568);
  if ((int)uVar3 < 0) goto LAB_18000b6b5;
  if (param_2 != 1) {
    if (param_2 == 2) {
      if (local_568._4_4_ != 2) {
        pwVar10 = local_348 + 0x10;
        pwVar12 = local_558;
LAB_18000b410:
        iVar2 = 3;
        goto LAB_18000b428;
      }
    }
    else if (param_2 == 3) {
      if (local_568._4_4_ != 2) {
        pwVar7 = local_3e8;
        pwVar10 = local_3a8;
        pwVar12 = local_4f8;
        goto LAB_18000b410;
      }
    }
    else if (param_2 == 4) {
      if (local_568._4_4_ != 2) {
        pwVar7 = local_438;
        pwVar10 = local_348 + 0x40;
        pwVar12 = local_490;
        goto LAB_18000b410;
      }
    }
    else if (param_2 == 0xc) {
      if (local_568._4_4_ != 1) {
        pwVar7 = local_438;
        pwVar10 = local_348 + 0x40;
        pwVar12 = local_348;
        goto LAB_18000b426;
      }
    }
    else if ((param_2 == 0xd) && (local_568._4_4_ != 1)) {
      pwVar12 = local_460;
      goto LAB_18000b41b;
    }
    uVar3 = 0x80284002;
    goto LAB_18000b6b5;
  }
  pwVar12 = local_4d8;
LAB_18000b41b:
  pwVar10 = local_348 + 0x10;
LAB_18000b426:
  iVar2 = 1;
LAB_18000b428:
  local_608 = &local_5f4;
  local_610 = (uint *)CONCAT44(local_610._4_4_,local_5f4);
  local_618 = local_258;
  iVar4 = RtlGetPersistedStateLocation(pwVar7,0,pwVar10,0);
  if (iVar4 < 0) goto LAB_18000b45b;
  uVar8 = local_5f4 + 0x28;
  _Size_00 = (ulonglong)uVar8;
  _Dst = (short *)TpmAlloc(uVar8);
  if (_Dst == (short *)0x0) {
LAB_18000b47b:
    uVar3 = 0x80070008;
    goto LAB_18000b6b5;
  }
  memset(_Dst,0,_Size_00);
  uVar9 = (ulonglong)(uVar8 >> 1);
  if (uVar9 != 0) {
    RtlStringCopyWorkerW(_Dst,uVar9,_Size_00,(longlong)local_4b8);
    local_5d8 = 0;
    plVar11 = &local_5d8;
    uVar8 = RtlStringLengthWorkerW(_Dst,uVar9,plVar11);
    if (-1 < (int)uVar8) {
      RtlStringCopyWorkerW(_Dst + local_5d8,uVar9 - local_5d8,plVar11,(longlong)local_258);
    }
  }
  RtlInitUnicodeString(&local_5b8,_Dst);
  uStack_5a0 = 0;
  local_598 = &local_5b8;
  local_5a8 = CONCAT44(local_5a8._4_4_,0x30);
  uStack_590 = CONCAT44(uStack_590._4_4_,0x40);
  local_588 = 0;
  uStack_580 = 0;
  iVar4 = NtOpenKey(&local_5e8,0x20019,&local_5a8);
  if (iVar4 == -0x3fffffcc) {
LAB_18000b533:
    uVar3 = 0x80284015;
  }
  else {
    if (-1 < iVar4) {
      RtlInitUnicodeString(&local_5c8,pwVar12);
      local_610 = &local_5f8;
      local_618 = (undefined1 *)((ulonglong)local_618 & 0xffffffff00000000);
      iVar4 = NtQueryValueKey(local_5e8,&local_5c8,2,0);
      if (iVar4 == -0x3fffffcc) goto LAB_18000b533;
      if (((iVar4 + 0x80000000U & 0x80000000) != 0) || (iVar4 == -0x3fffffdd)) {
        puVar6 = TpmAlloc(local_5f8);
        if (puVar6 == (uchar *)0x0) goto LAB_18000b47b;
        local_610 = &local_5f8;
        local_618 = (undefined1 *)CONCAT44(local_618._4_4_,local_5f8);
        iVar4 = NtQueryValueKey(local_5e8,&local_5c8,2,puVar6);
        if ((-1 < iVar4) && (*(int *)(puVar6 + 4) == iVar2)) {
          _Size = (size_t)*(uint *)(puVar6 + 8);
          if (iVar2 == 1) {
            if (_Size != 0x3a) {
              if (((*(uint *)(puVar6 + 8) & 0xfffffffd) != 0) || (1 < local_5dc - 0xcU))
              goto LAB_18000b45b;
              local_5f0 = 1;
            }
            _Size = 0x14;
          }
          uVar8 = (uint)_Size;
          if (local_5d0 == (uchar *)0x0) {
            *param_4 = uVar8;
            uVar3 = 0;
            goto LAB_18000b6b5;
          }
          uVar1 = *param_4;
          *param_4 = uVar8;
          if (uVar1 < uVar8) {
            uVar3 = 0x80284005;
            goto LAB_18000b6b5;
          }
          if (iVar2 != 1) {
            memcpy(local_5d0,puVar6 + 0xc,_Size);
            goto LAB_18000b6b5;
          }
          if (local_5f0 != 0) {
            memset(local_5d0,0,_Size);
            goto LAB_18000b6b5;
          }
          local_5f8 = uVar8;
          lVar5 = TbsBase64Decode((ushort *)(puVar6 + 0xc),local_5d0,&local_5f8);
          if ((-1 < lVar5) && (local_5f8 == 0x14)) goto LAB_18000b6b5;
        }
      }
    }
LAB_18000b45b:
    uVar3 = 0x80284001;
  }
LAB_18000b6b5:
  if (local_5e8 != 0) {
    NtClose();
  }
  if (puVar6 != (uchar *)0x0) {
    wil::details::FreeProcessHeap(puVar6);
  }
  if (_Dst != (short *)0x0) {
    wil::details::FreeProcessHeap(_Dst);
  }
  return uVar3;
}



===== Tbsi_Get_TCG_Log @ 18000b720 =====

uint Tbsi_Get_TCG_Log(undefined8 param_1,uchar *param_2,uint *param_3)

{
  uint uVar1;
  
                    /* 0xb720  11  Tbsi_Get_TCG_Log */
  if (param_3 == (uint *)0x0) {
    uVar1 = 0x80284003;
  }
  else {
    uVar1 = Feature_TpmMissingLogsMaa__private_IsEnabledDeviceUsageNoInline();
    if (uVar1 == 0) {
      uVar1 = TbsGetLog(0,param_2,*param_3,param_3);
    }
    else {
      uVar1 = TbsGetLogNew(0,0,param_2,*param_3,param_3);
    }
  }
  return uVar1;
}



===== Tbsi_Revoke_Attestation @ 18000b780 =====

uint Tbsi_Revoke_Attestation(void)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  void *local_res8;
  undefined4 local_res10;
  undefined4 local_res14;
  
                    /* 0xb780  15  Tbsi_Revoke_Attestation */
  uVar3 = 0;
  local_res10 = 2;
  local_res8 = (void *)0x0;
  local_res14 = 6;
  uVar1 = Tbsi_Context_Create((tdTBS_CONTEXT_PARAMS *)&local_res10,&local_res8);
  if (-1 < (int)uVar1) {
    uVar2 = TpmDeviceIoControl(local_res8,0x22c018,0,0,0,(undefined4 *)0x0);
    uVar3 = (uint)uVar2;
  }
  if (local_res8 != (void *)0x0) {
    Tbsip_Context_Close(local_res8);
  }
  if ((int)uVar3 < 0) {
    uVar1 = TbsRemapError(uVar3,0x94c);
  }
  return uVar1;
}



===== Tbsi_Tpm_Vendor_Maintenance_Mode @ 18000b810 =====

void Tbsi_Tpm_Vendor_Maintenance_Mode(tdTBS_CONTEXT_PARAMS *param_1,void **param_2)

{
                    /* 0xb810  17  Tbsi_Tpm_Vendor_Maintenance_Mode */
  Tbsi_Context_Create_Ex(param_1,param_2,1);
  return;
}



===== Tbsip_Cancel_Commands @ 18000b830 =====

void Tbsip_Cancel_Commands(undefined8 param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
                    /* 0xb830  18  Tbsip_Cancel_Commands */
  uVar2 = TpmDeviceIoControl(param_1,0x22c004,0,0,0,(undefined4 *)0x0);
  uVar1 = (uint)uVar2;
  if (uVar1 == 0x80070006) {
    uVar1 = 0x80284004;
  }
  TbsRemapError(uVar1,0x566);
  return;
}



===== Tbsip_Submit_Command_NonBlocking @ 18000b880 =====

void Tbsip_Submit_Command_NonBlocking
               (void *param_1,uint param_2,uint param_3,uchar *param_4,uint param_5,uchar *param_6,
               uint *param_7)

{
                    /* 0xb880  21  Tbsip_Submit_Command_NonBlocking */
  Tbsip_Submit_Command_Internal(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0x22c194);
  return;
}



===== Tbsip_TestInterruptInformation @ 18000b8c0 =====

uint Tbsip_TestInterruptInformation(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined4 local_res10;
  undefined4 local_res14;
  undefined4 local_res18 [2];
  void *local_res20;
  
                    /* 0xb8c0  22  Tbsip_TestInterruptInformation */
  local_res20 = (void *)0x0;
  local_res10 = 2;
  local_res14 = 6;
  uVar2 = 0;
  uVar1 = Tbsi_Context_Create((tdTBS_CONTEXT_PARAMS *)&local_res10,&local_res20);
  uVar4 = 0xffffffff;
  if (-1 < (int)uVar1) {
    local_res10 = 0;
    local_res18[0] = 4;
    uVar3 = TpmDeviceIoControl(local_res20,0x22c1a0,0,0,&local_res10,local_res18);
    uVar2 = (uint)uVar3;
    uVar4 = 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar4 = local_res10;
    }
  }
  if (local_res20 != (void *)0x0) {
    Tbsip_Context_Close(local_res20);
  }
  if ((int)uVar2 < 0) {
    uVar1 = TbsRemapError(uVar2,0xb9b);
  }
  else {
    *param_1 = uVar4;
  }
  return uVar1;
}



===== Tbsip_TestMorBit @ 18000b980 =====

uint Tbsip_TestMorBit(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined4 local_res10;
  undefined4 local_res14;
  undefined4 local_res18 [2];
  void *local_res20;
  
                    /* 0xb980  23  Tbsip_TestMorBit */
  local_res20 = (void *)0x0;
  local_res10 = 2;
  local_res14 = 6;
  uVar2 = 0;
  uVar1 = Tbsi_Context_Create((tdTBS_CONTEXT_PARAMS *)&local_res10,&local_res20);
  uVar4 = 0xffffffff;
  if (-1 < (int)uVar1) {
    local_res10 = 0;
    local_res18[0] = 4;
    uVar3 = TpmDeviceIoControl(local_res20,0x22c198,0,0,&local_res10,local_res18);
    uVar2 = (uint)uVar3;
    uVar4 = 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar4 = local_res10;
    }
  }
  if (local_res20 != (void *)0x0) {
    Tbsip_Context_Close(local_res20);
  }
  if ((int)uVar2 < 0) {
    uVar1 = TbsRemapError(uVar2,0xb5f);
  }
  else if (param_1 != (undefined4 *)0x0) {
    *param_1 = uVar4;
  }
  return uVar1;
}



===== memcpy_s @ 18000ba4c =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t *peVar1;
  errno_t eVar2;
  
  if (_MaxCount == 0) {
LAB_18000ba69:
    eVar2 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_18000ba72:
      peVar1 = (errno_t *)_o__errno();
      eVar2 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_18000ba69;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_18000ba72;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      peVar1 = (errno_t *)_o__errno();
      eVar2 = 0x22;
    }
    *peVar1 = eVar2;
    _invalid_parameter_noinfo();
  }
  return eVar2;
}



===== memmove_s @ 18000bae8 =====

errno_t __cdecl memmove_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t *peVar1;
  errno_t eVar2;
  
  if (_MaxCount == 0) {
LAB_18000bb3f:
    eVar2 = 0;
  }
  else {
    if ((_Dst == (void *)0x0) || (_Src == (void *)0x0)) {
      peVar1 = (errno_t *)_o__errno();
      eVar2 = 0x16;
    }
    else {
      if (_MaxCount <= _DstSize) {
        memmove(_Dst,_Src,_MaxCount);
        goto LAB_18000bb3f;
      }
      peVar1 = (errno_t *)_o__errno();
      eVar2 = 0x22;
    }
    *peVar1 = eVar2;
    _invalid_parameter_noinfo();
  }
  return eVar2;
}



===== wil_QueryFeatureState @ 18000bb50 =====

void wil_QueryFeatureState
               (uint *param_1,uint param_2,int param_3,undefined8 param_4,uint *param_5,
               undefined4 *param_6)

{
  if (param_5 != (uint *)0x0) {
    *param_5 = 0;
  }
  *param_6 = 1;
  wil_RtlStagingConfig_QueryFeatureState(param_1,param_2,param_3,param_5);
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 18000bb74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined4
wil_RtlStagingConfig_QueryFeatureState(uint *param_1,uint param_2,int param_3,uint *param_4)

{
  int iVar1;
  __int64 _Var2;
  undefined4 uVar3;
  undefined1 auStack_78 [48];
  undefined8 local_48;
  undefined8 local_40;
  uint local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  uVar3 = 0;
  local_40 = 0;
  local_38 = 0;
  if ((g_wil_details_pfnRtlQueryFeatureConfiguration == (_func___int64 *)0x0) &&
     (g_wil_details_pfnRtlQueryFeatureConfiguration =
           wil_details_GetNtDllProcedureAddress("RtlQueryFeatureConfiguration"),
     g_wil_details_pfnRtlQueryFeatureConfiguration == (_func___int64 *)0x0)) {
    iVar1 = -0x3ffffec7;
  }
  else {
    _Var2 = (*g_wil_details_pfnRtlQueryFeatureConfiguration)
                      ((ulonglong)param_2,(ulonglong)(param_3 == 0),&local_48,&local_40);
    iVar1 = (int)_Var2;
    if (iVar1 == 0) {
      *param_1 = local_40._4_4_ >> 4 & 3;
      *(byte *)(param_1 + 1) = (byte)((ulonglong)local_40 >> 0x28) & 0x3f;
      param_1[3] = local_38;
      param_1[2] = local_40._4_4_ >> 0xe & 3;
      param_1[5] = local_40._4_4_ >> 6 & 1;
    }
    else if (iVar1 != 0x117) goto LAB_18000bc4f;
    uVar3 = 1;
    param_1[4] = local_40._4_4_ >> 7 & 1;
  }
LAB_18000bc4f:
  if (param_4 != (uint *)0x0) {
    *param_4 = (uint)(iVar1 != -0x7fffffde);
  }
  return uVar3;
}



===== wil_RtlStagingConfig_RecordFeatureUsage @ 18000bc8c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

__int64 wil_RtlStagingConfig_RecordFeatureUsage(undefined4 param_1,undefined2 param_2,int param_3)

{
  uint6 uVar1;
  __int64 _Var2;
  undefined8 local_res20;
  
  local_res20._0_6_ = CONCAT24(param_2,param_1);
  uVar1 = (uint6)local_res20;
  local_res20 = (ulonglong)(uint6)local_res20;
  if (param_3 != 0) {
    local_res20 = CONCAT26(1,uVar1);
  }
  if ((g_wil_details_pfnRtlNotifyFeatureUsage == (_func___int64 *)0x0) &&
     (g_wil_details_pfnRtlNotifyFeatureUsage =
           wil_details_GetNtDllProcedureAddress("RtlNotifyFeatureUsage"),
     g_wil_details_pfnRtlNotifyFeatureUsage == (_func___int64 *)0x0)) {
    return 0xc0000139;
  }
  _Var2 = (*g_wil_details_pfnRtlNotifyFeatureUsage)(&local_res20);
  return _Var2;
}



===== wil_StagingConfig_LogStagedFeatureUsage @ 18000bcf0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void wil_StagingConfig_LogStagedFeatureUsage(uint param_1,uint param_2,undefined1 param_3)

{
  if ((g_wil_details_pfnLogStagedFeatureUsage == (_func___int64 *)0x0) &&
     (g_wil_details_pfnLogStagedFeatureUsage =
           wil_details_GetKernelBaseProcAddress("LogStagedFeatureUsage"),
     g_wil_details_pfnLogStagedFeatureUsage == (_func___int64 *)0x0)) {
    return;
  }
  (*g_wil_details_pfnLogStagedFeatureUsage)((ulonglong)param_1,(ulonglong)param_2,param_3);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 18000bd50 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    param_4[1] = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar4 = uVar1 >> 0xf & 0x7f;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        uVar4 = 5;
        if (param_2 != 1) {
          uVar4 = 1;
        }
        uVar2 = uVar1 & 0xffc07fff | 1;
        param_4[2] = uVar4;
      }
      uVar4 = 0;
      if (param_2 == 5) {
        uVar4 = 0x400000;
      }
      uVar2 = uVar4 | uVar2 & 0xffbfffff;
    }
    uVar3 = uVar2 >> 0xf & 0x7f;
    uVar4 = uVar3 + 1;
    if ((0x7f < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar3;
    }
    LOCK();
    uVar3 = *param_1;
    if (uVar1 == uVar3) {
      *param_1 = uVar2 ^ (uVar4 << 0xf ^ uVar2) & 0x3f8000;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4[4] = 0;
  *param_4 = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 18000be34 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    param_4[1] = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar1 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar2 = uVar1 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar2 = uVar4 | uVar2 & 0xffffbfff;
    }
    uVar3 = uVar2 >> 5 & 0x1ff;
    uVar4 = uVar3 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar3;
    }
    LOCK();
    uVar3 = *param_1;
    if (uVar1 == uVar3) {
      *param_1 = uVar2 ^ (uVar4 << 5 ^ uVar2) & 0x3fe0;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4[4] = 0;
  *param_4 = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 18000bf24 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_18000c080:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_18000c070:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_18000c080;
      if (uVar5 == 5) goto LAB_18000c070;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 18000c0a8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 18000c12c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint *puVar1;
  undefined1 auStack_88 [48];
  uint local_58 [10];
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  puVar1 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_58,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_30 = *(undefined8 *)(puVar1 + 4);
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    wil_RtlStagingConfig_RecordFeatureUsage
              (*(undefined4 *)(param_1 + 0x18),(short)param_3,(uint)param_2 >> 0xb & 1);
  }
  return (int)local_30 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 18000c1b4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 18000c2c4 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 18000c328 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong *plVar7;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  iVar3 = wil_RtlStagingConfig_QueryFeatureState
                    (local_28,*(uint *)(param_1 + 0x18),(uint)((byte)(cVar1 - 2U) < 2),(uint *)0x0);
  uVar4 = -(uint)(iVar3 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar6 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar6 = 0;
    if (local_28[0] == 2) {
      uVar6 = 0x40;
    }
  }
  local_res8 = uVar6 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar6);
  if ((uVar6 != 0) && (plVar7 = *(longlong **)(param_1 + 0x20), plVar7 != (longlong *)0x0)) {
    do {
      puVar2 = (undefined8 *)*plVar7;
      if (puVar2 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar2 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar2 + 0x1d) == '\0')) {
        uVar6 = *(uint *)*puVar2;
        local_res10 = (ulonglong)uVar6;
        if ((uVar6 & 2) == 0) {
          uVar5 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar2,local_res10,(longlong)puVar2);
          uVar6 = (uint)uVar5;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar6 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar2 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar7 = plVar7 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 18000c488 =====

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



===== wil_details_MapReportingKind @ 18000c51c =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== wil_details_NtQueryWnfStateData @ 18000c5bc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

__int64 wil_details_NtQueryWnfStateData
                  (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6)

{
  __int64 _Var1;
  
  if ((g_wil_details_pfnNtQueryWnfStateData == (_func___int64 *)0x0) &&
     (g_wil_details_pfnNtQueryWnfStateData =
           wil_details_GetNtDllProcedureAddress("NtQueryWnfStateData"),
     g_wil_details_pfnNtQueryWnfStateData == (_func___int64 *)0x0)) {
    return 0xc0000139;
  }
  _Var1 = (*g_wil_details_pfnNtQueryWnfStateData)(param_1,0,0,param_4,param_5,param_6);
  return _Var1;
}



===== wil_details_NtUpdateWnfStateData @ 18000c634 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

__int64 wil_details_NtUpdateWnfStateData
                  (undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4,
                  undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  __int64 _Var1;
  
  if ((g_wil_details_pfnNtUpdateWnfStateData == (_func___int64 *)0x0) &&
     (g_wil_details_pfnNtUpdateWnfStateData =
           wil_details_GetNtDllProcedureAddress("NtUpdateWnfStateData"),
     g_wil_details_pfnNtUpdateWnfStateData == (_func___int64 *)0x0)) {
    return 0xc0000139;
  }
  _Var1 = (*g_wil_details_pfnNtUpdateWnfStateData)(param_1,param_2,param_3,0,0,param_6,param_7);
  return _Var1;
}



===== wil_details_RecordCachedUsage @ 18000c6c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  __uint64 _Var6;
  bool bVar7;
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
    bVar7 = uVar2 == uVar4;
    if (bVar7) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar7);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar7 = uVar4 == uVar1;
      if (bVar7) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
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
  _Var6 = (longlong)puVar5 - (longlong)&local_48 >> 3;
  if (0 < (longlong)_Var6) {
    wil::details::WilApi_RecordFeatureUsageReports((__WIL_RTL_FEATURE_USAGE_DATA *)&local_48,_Var6);
  }
  return;
}



===== wil_details_RtlRegisterFeatureConfigurationChangeNotification @ 18000c80c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

__int64 wil_details_RtlRegisterFeatureConfigurationChangeNotification
                  (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __int64 _Var1;
  
  if ((g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification == (_func___int64 *)0x0)
     && (g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification =
              wil_details_GetNtDllProcedureAddress
                        ("RtlRegisterFeatureConfigurationChangeNotification"),
        g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification == (_func___int64 *)0x0))
  {
    return 0xc0000139;
  }
  _Var1 = (*g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification)
                    (param_1,param_2,0,param_4);
  return _Var1;
}



===== wil_details_RtlUnregisterFeatureConfigurationChangeNotification @ 18000c878 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void wil_details_RtlUnregisterFeatureConfigurationChangeNotification(undefined8 param_1)

{
  if ((g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification == (_func___int64 *)0x0)
     && (g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification =
              wil_details_GetNtDllProcedureAddress
                        ("RtlUnregisterFeatureConfigurationChangeNotification"),
        g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification == (_func___int64 *)0x0
        )) {
    return;
  }
  (*g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification)(param_1);
  return;
}



===== TpmOpenEx @ 18000c8bc =====

/* long __cdecl TpmOpenEx(void * __ptr64 * __ptr64,int) */

long __cdecl TpmOpenEx(void **param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
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
  
  local_34 = 0;
  local_1c = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_58,L"\\??\\TPM");
  local_30 = 0;
  local_28 = &local_58;
  local_38 = 0x30;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = NtCreateFile(param_1,0xc0000000,&local_38,&local_48,0,0,param_2 == 0,1,0,0,0);
  uVar2 = RtlNtStatusToDosError(uVar1);
  if (0 < (int)uVar2) {
    uVar2 = uVar2 & 0xffff | 0x80070000;
  }
  return uVar2;
}



===== Feature_ReplaceNtCloseWithCloseHandle__private_IsEnabledDeviceUsageNoInline @ 18000c9a8 =====

uint Feature_ReplaceNtCloseWithCloseHandle__private_IsEnabledDeviceUsageNoInline(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_ReplaceNtCloseWithCloseHandle__private_featureState;
  if ((Feature_ReplaceNtCloseWithCloseHandle__private_featureState & 0x10) == 0) {
    uVar1 = wil_details_IsEnabledFallback
                      (local_res8,3,&Feature_ReplaceNtCloseWithCloseHandle__private_descriptor);
    return uVar1;
  }
  return Feature_ReplaceNtCloseWithCloseHandle__private_featureState & 1;
}



===== <lambda_invoker_cdecl> @ 18000c9f0 =====

/* private: static __cdecl <lambda_0374aa0a5d1201b2358c6bce99369c58>::<lambda_invoker_cdecl>(struct
   _TP_CALLBACK_INSTANCE * __ptr64,void * __ptr64,struct _TP_TIMER * __ptr64) */

void __cdecl
<lambda_0374aa0a5d1201b2358c6bce99369c58>::<lambda_invoker_cdecl>
          (_TP_CALLBACK_INSTANCE *param_1,void *param_2,_TP_TIMER *param_3)

{
  wil::details::EnabledStateManager::OnTimer(param_2);
  return;
}



===== <lambda_invoker_cdecl> @ 18000ca00 =====

/* private: static __cdecl <lambda_aa194dc0bf891154933407eb98fb868a>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_aa194dc0bf891154933407eb98fb868a>::<lambda_invoker_cdecl>(void *param_1)

{
  wil::details::EnabledStateManager::OnTimer
            ((EnabledStateManager *)&wil::details::g_enabledStateManager);
  return;
}



===== EnsureSubscribedToUsageFlush @ 18000ca14 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details::EnabledStateManager::EnsureSubscribedToUsageFlush(void
   (__cdecl*)(void * __ptr64)) __ptr64 */

void __thiscall
wil::details::EnabledStateManager::EnsureSubscribedToUsageFlush
          (EnabledStateManager *this,_func_void_void_ptr *param_1)

{
  EnabledStateManager *SRWLock;
  EnabledStateManager *pEVar1;
  code *pcVar2;
  EnabledStateManager *local_res8;
  
  if (*this != (EnabledStateManager)0x0) {
    SRWLock = this + 8;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    pEVar1 = this + 0x28;
    local_res8 = SRWLock;
    if (*(longlong *)pEVar1 == 0) {
      *(longlong *)pEVar1 = 0;
      pcVar2 = g_wil_details_internalSubscribeFeatureStateChangeNotification;
      if ((g_wil_details_internalSubscribeFeatureStateChangeNotification != (code *)0x0) ||
         (pcVar2 = g_wil_details_apiSubscribeFeatureStateChangeNotification,
         g_wil_details_apiSubscribeFeatureStateChangeNotification != (code *)0x0)) {
        (*pcVar2)(pEVar1,param_1,0xffffffffffffffff);
      }
    }
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
  }
  return;
}



===== GetCachedFeatureEnabledState @ 18000ca9c =====

/* WARNING: Removing unreachable block (ram,0x00018000caee) */
/* WARNING: Removing unreachable block (ram,0x00018000caf4) */
/* private: union wil_details_FeatureStateCache __cdecl wil::details::FeatureImpl<struct
   __WilFeatureTraits_Feature_TpmMissingLogsMaa>::GetCachedFeatureEnabledState(void) __ptr64 */

void __thiscall
wil::details::FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa>::
GetCachedFeatureEnabledState(FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa> *this)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa> *this_00;
  uint uVar4;
  uint *in_RDX;
  uint uVar5;
  uint local_res10 [2];
  undefined *local_res18 [2];
  undefined4 local_38;
  undefined4 local_34;
  FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa> *local_30;
  
  in_RDX[0] = 0;
  in_RDX[1] = 0;
  uVar5 = *(uint *)this;
  *in_RDX = uVar5;
  if (((byte)uVar5 & 6) == 6) {
    return;
  }
  this_00 = this;
  uVar3 = EnsureSubscribedToFeatureConfigurationChanges();
  GetCurrentFeatureEnabledState(this_00,(int *)local_res10);
  uVar5 = *in_RDX;
  while( true ) {
    *in_RDX = uVar5;
    uVar4 = uVar5;
    if ((uVar5 & 4) == 0) {
      uVar4 = uVar5 & 0xfffffbff | local_res10[0] & 0x400 | 4;
      *in_RDX = uVar4;
    }
    LOCK();
    uVar1 = *(uint *)this;
    if (uVar5 == uVar1) {
      *(uint *)this = uVar4;
      uVar4 = uVar5;
    }
    else {
      uVar4 = uVar1;
    }
    UNLOCK();
    if (uVar5 == uVar1) break;
    uVar5 = uVar4;
  }
  if (((uVar5 & 4) != 0) ||
     (g_enabledStateManager == (shutdown_aware_object<wil::details::EnabledStateManager>)0x0))
  goto LAB_18000cb9a;
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1800152f0);
  local_res18[0] = &DAT_1800152f0;
  if ((uVar3 == 0) || (uVar3 != DAT_180015304)) {
LAB_18000cb8d:
    LOCK();
    *(uint *)this = *(uint *)this & 0xfffffffb;
    UNLOCK();
  }
  else {
    local_34 = 0;
    local_38 = 1;
    local_30 = this;
    bVar2 = details_abi::heap_buffer::push_back((heap_buffer *)&DAT_180015338,&local_38,0x10);
    if (!bVar2) goto LAB_18000cb8d;
  }
  unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              *)local_res18);
LAB_18000cb9a:
  if ((*in_RDX & 2) == 0) {
    *in_RDX = *in_RDX & 0xfffff63e | local_res10[0] & 0x9c1;
  }
  return;
}



===== GetCurrentFeatureEnabledState @ 18000cbc8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: union wil_details_FeatureStateCache __cdecl wil::details::FeatureImpl<struct
   __WilFeatureTraits_Feature_TpmMissingLogsMaa>::GetCurrentFeatureEnabledState(int * __ptr64)
   __ptr64 */

int * __thiscall
wil::details::FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa>::
GetCurrentFeatureEnabledState
          (FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa> *this,int *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  pcVar4 = g_wil_details_internalGetFeatureEnabledState;
  if ((g_wil_details_internalGetFeatureEnabledState == (code *)0x0) &&
     (pcVar4 = g_wil_details_apiGetFeatureEnabledState,
     g_wil_details_apiGetFeatureEnabledState == (code *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*pcVar4)(0x2e52ee6,1);
  }
  param_1[0] = 0;
  param_1[1] = 0;
  uVar5 = (((uVar2 & 3) << 2 | uVar2 & 0x40) << 2 | uVar2 & 0x80) << 3;
  if ((uVar2 & 0xffffff3f) != 0) {
    uVar3 = 0;
    if ((uVar2 & 0xffffff3f) == 2) {
      uVar3 = 0x40;
    }
    uVar5 = uVar5 | uVar3;
  }
  bVar1 = false;
  if ((uVar5 & 0xc00) == 0xc00) {
    bVar1 = true;
LAB_18000cc61:
    if (((uVar5 & 0x40) == 0) || (!bVar1)) goto LAB_18000cc6f;
  }
  else if ((uVar5 & 0x40) == 0) goto LAB_18000cc61;
  uVar6 = 1;
LAB_18000cc6f:
  *param_1 = uVar5 | uVar6;
  return param_1;
}



===== OnTimer @ 18000cc88 =====

/* public: void __cdecl wil::details::EnabledStateManager::OnTimer(void) __ptr64 */

void __thiscall wil::details::EnabledStateManager::OnTimer(EnabledStateManager *this)

{
  EnabledStateManager *local_res8;
  
  if (*this != (EnabledStateManager)0x0) {
    AcquireSRWLockExclusive((PSRWLOCK)(this + 8));
    local_res8 = this + 8;
    RecordCachedUsageUnderLock(this);
    this[0x18] = (EnabledStateManager)0x0;
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
  }
  return;
}



===== QueueBackgroundUsageReporting @ 18000ccdc =====

/* public: void __cdecl wil::details::EnabledStateManager::QueueBackgroundUsageReporting(unsigned
   int,struct wil_details_FeatureReportingCache * __ptr64) __ptr64 */

void __thiscall
wil::details::EnabledStateManager::QueueBackgroundUsageReporting
          (EnabledStateManager *this,uint param_1,wil_details_FeatureReportingCache *param_2)

{
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  *this_00;
  bool bVar1;
  PTP_TIMER p_Var2;
  last_error_context local_res8 [8];
  EnabledStateManager *local_res20;
  undefined8 local_18;
  wil_details_FeatureReportingCache *local_10;
  
  if (*this != (EnabledStateManager)0x0) {
    bVar1 = ProcessShutdownInProgress();
    if (!bVar1) {
      AcquireSRWLockExclusive((PSRWLOCK)(this + 8));
      local_18 = 0x2e52ee6;
      local_res20 = this + 8;
      local_10 = param_2;
      details_abi::heap_buffer::push_back((heap_buffer *)(this + 0x30),&local_18,0x10);
      this_00 = (unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
                 *)(this + 0x10);
      if (this[0x18] == (EnabledStateManager)0x0) {
        if (*(longlong *)this_00 == 0) {
          last_error_context::last_error_context(local_res8);
          p_Var2 = CreateThreadpoolTimer
                             (<lambda_0374aa0a5d1201b2358c6bce99369c58>::<lambda_invoker_cdecl>,this
                              ,(PTP_CALLBACK_ENVIRON)0x0);
          unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
          ::reset(this_00,p_Var2);
          last_error_context::~last_error_context(local_res8);
        }
        EnsureCoalescedTimer_SetTimer
                  ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
                    *)this_00,(bool *)(this + 0x18),300000);
      }
      unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                  *)&local_res20);
    }
  }
  return;
}



===== ReportUsage @ 18000cdbc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details::FeatureImpl<struct
   __WilFeatureTraits_Feature_TpmMissingLogsMaa>::ReportUsage(bool,enum wil::ReportingKind,unsigned
   __int64) __ptr64 */

void __thiscall
wil::details::FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa>::ReportUsage
          (FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa> *this,bool param_1,
          ReportingKind param_2,__uint64 param_3)

{
  wil_details_ServiceReportingKind wVar1;
  int iVar2;
  ulonglong *puVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 local_res8;
  undefined2 local_resc;
  undefined4 local_res18 [2];
  __uint64 local_res20;
  uint in_stack_ffffffffffffffb0;
  undefined1 in_stack_ffffffffffffffb8;
  undefined7 in_stack_ffffffffffffffb9;
  
  local_res18[0] = CONCAT31(local_res18[0]._1_3_,(char)param_2);
  uVar5 = (ulonglong)*(uint *)this;
  uVar4 = (uint)param_1;
  local_res20 = param_3;
  if ((*(uint *)this & 4) == 0) {
    puVar3 = (ulonglong *)GetCachedFeatureEnabledState(this);
    local_res20 = *puVar3;
    uVar5 = local_res20 & 0xffffffff;
  }
  local_resc = 1;
  local_res8 = 0;
  local_res18[0] = 3;
  wVar1 = wil_details_MapReportingKind(3,(uint)param_1);
  iVar2 = ReportUsageToServiceDirect
                    ((wil_details_FeatureReportingCache *)(this + 8),uVar4,(uint)uVar5 >> 10 & 1,
                     (uint)(uVar5 >> 0xb) & 1,wVar1,in_stack_ffffffffffffffb0,
                     CONCAT71(in_stack_ffffffffffffffb9,in_stack_ffffffffffffffb8),'\x01');
  if ((iVar2 != 0) && (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)(0x2e52ee6,&local_res8,0,param_1,local_res18,0,0,1);
  }
  return;
}



===== ReportUsageToServiceDirect @ 18000ce98 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* int __cdecl wil::details::ReportUsageToServiceDirect(struct wil_details_FeatureReportingCache *
   __ptr64,unsigned int,int,int,enum wil_details_ServiceReportingKind,unsigned int,unsigned
   __int64,unsigned char) */

int __cdecl
wil::details::ReportUsageToServiceDirect
          (wil_details_FeatureReportingCache *param_1,uint param_2,int param_3,int param_4,
          wil_details_ServiceReportingKind param_5,uint param_6,__uint64 param_7,uchar param_8)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  wil_details_ServiceReportingKind wVar6;
  wil_details_FeatureReportingCache *pwVar7;
  int iVar8;
  char *pcVar9;
  int local_28;
  uint local_20 [6];
  
  pcVar9 = (char *)0x0;
  pwVar7 = param_1;
  puVar5 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_20,(uint *)param_1,(ulonglong)param_5,0);
  wVar6 = (wil_details_ServiceReportingKind)pwVar7;
  iVar8 = 1;
  uVar2 = *puVar5;
  uVar3 = puVar5[1];
  uVar4 = puVar5[2];
  uVar1 = *(undefined8 *)(puVar5 + 4);
  if ((g_wil_details_RecordSRUMFeatureUsage != (code *)0x0) &&
     ((param_5 == 0 || (param_5 - 100 < 0x32)))) {
    wVar6 = param_5;
    (*g_wil_details_RecordSRUMFeatureUsage)(0x2e52ee6,param_5,1);
  }
  if (uVar2 != 0) {
    EnabledStateManager::QueueBackgroundUsageReporting
              ((EnabledStateManager *)&g_enabledStateManager,wVar6,param_1);
  }
  if (uVar3 != 0) {
    WilApi_RecordFeatureUsage(0x2e52ee6,uVar4,uVar3,pcVar9);
  }
  local_28 = (int)uVar1;
  if (local_28 == 0) {
    EnabledStateManager::EnsureSubscribedToUsageFlush
              ((EnabledStateManager *)&g_enabledStateManager,
               <lambda_aa194dc0bf891154933407eb98fb868a>::<lambda_invoker_cdecl>);
  }
  if (param_3 != 0) {
    wVar6 = param_5 | 0x80000000;
    if (param_4 == 0) {
      wVar6 = param_5;
    }
    WilApi_RecordFeatureUsage(0x2e52ee6,wVar6,0,pcVar9);
  }
  if (local_28 == 0) {
    if (g_wil_details_realtimeFeatureUsageHook != (code *)0x0) {
      (*g_wil_details_realtimeFeatureUsageHook)(0x2e52ee6,param_5,param_8);
    }
  }
  else {
    iVar8 = 0;
  }
  return iVar8;
}



===== __private_IsEnabled @ 18000cfe0 =====

/* public: bool __cdecl wil::details::FeatureImpl<struct
   __WilFeatureTraits_Feature_TpmMissingLogsMaa>::__private_IsEnabled(void) __ptr64 */

bool __thiscall
wil::details::FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa>::__private_IsEnabled
          (FeatureImpl<__WilFeatureTraits_Feature_TpmMissingLogsMaa> *this)

{
  ReportingKind in_R8D;
  __uint64 in_R9;
  byte local_res10;
  
  GetCachedFeatureEnabledState(this);
  ReportUsage(this,(bool)(local_res10 & 1),in_R8D,in_R9);
  return (bool)(local_res10 & 1);
}



===== Tbsi_ComputeSoftPCRs @ 18000d01c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Tbsi_ComputeSoftPCRs(unsigned char * __ptr64,unsigned int,unsigned short,unsigned
   char * __ptr64,unsigned int,unsigned int * __ptr64) */

long __cdecl
Tbsi_ComputeSoftPCRs
          (uchar *param_1,uint param_2,ushort param_3,uchar *param_4,uint param_5,uint *param_6)

{
  byte bVar1;
  longlong *plVar2;
  PUCHAR pUVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  NTSTATUS NVar7;
  longlong lVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  wchar_t *pwVar12;
  undefined1 auStackY_128 [32];
  int local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  longlong *local_d8;
  void *local_d0;
  PUCHAR local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined4 local_98;
  ushort local_94;
  undefined1 local_88 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_a0 = 0;
  local_98 = 0;
  local_94 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  if (param_1 == (uchar *)0x0) {
    return -0x3ffffff3;
  }
  if (param_2 == 0) {
    return -0x3ffffff3;
  }
  if (param_4 == (uchar *)0x0) {
    return -0x3ffffff3;
  }
  if (param_5 == 0) {
    return -0x3ffffff3;
  }
  if (param_3 == 4) {
    pwVar12 = L"SHA1";
    uVar11 = 0x14;
  }
  else {
    if (param_3 != 0xb) {
      return -0x3ffffff3;
    }
    pwVar12 = L"SHA256";
    uVar11 = 0x20;
  }
  if (param_5 < uVar11 * 0x18) {
    return -0x3ffffff3;
  }
  local_dc = uVar11;
  memset(param_4,0,(ulonglong)param_5);
  memset(param_4 + uVar11 * 0x11,0xff,(ulonglong)(uVar11 * 6));
  local_c8 = operator_new__((ulonglong)(uVar11 * 2));
  if (local_c8 == (PUCHAR)0x0) {
    return -0x3fffff66;
  }
  uVar4 = WbclApiInitIterator(param_1,param_2,(_WBCL_Iterator *)&local_c0);
  if ((uVar4 >> 0x1c & 1) == 0) {
    if ((uVar4 & 0xfff0000) == 0x70000) {
      uVar5 = 0;
      if ((uVar4 & 0xffff) != 0) {
        uVar5 = uVar4 & 0xffff | 0xc0070000;
      }
    }
    else {
      if ((uVar4 & 0xfff0000) != 0x280000) {
        if ((int)uVar4 < 0) {
          return -0x3fffffff;
        }
        uVar5 = 0;
        goto LAB_18000d167;
      }
      uVar5 = uVar4 & 0xffff | 0xc0290000;
    }
  }
  else {
    uVar5 = uVar4 & 0xefffffff;
  }
  if ((int)uVar5 < 0) {
    return uVar5;
  }
LAB_18000d167:
  if (((ushort)uStack_a8 != uVar11) || (local_94 != param_3)) {
    return -0x3ffffff3;
  }
  do {
    if (uVar5 != 0) {
      return 0;
    }
    local_d0 = (void *)0x0;
    local_e0 = 0;
    local_d8 = (longlong *)0x0;
    local_e4 = 0;
    local_e8 = 0;
    memset(local_88,0,0x40);
    uVar5 = WbclApiGetCurrentElement
                      ((_WBCL_Iterator *)&local_c0,&local_e4,&local_e8,&local_d0,&local_e0,&local_d8
                      );
    plVar2 = local_d8;
    uVar4 = local_e4;
    if ((uVar5 >> 0x1c & 1) == 0) {
      if ((uVar5 & 0xfff0000) == 0x70000) {
        uVar10 = 0;
        if ((uVar5 & 0xffff) != 0) {
          uVar10 = uVar5 & 0xffff | 0xc0070000;
        }
        goto LAB_18000d21f;
      }
      if ((uVar5 & 0xfff0000) == 0x280000) {
        uVar10 = uVar5 & 0xffff | 0xc0290000;
        goto LAB_18000d21f;
      }
      if ((int)uVar5 < 0) {
        return -0x3fffffff;
      }
    }
    else {
      uVar10 = uVar5 & 0xefffffff;
LAB_18000d21f:
      if ((int)uVar10 < 0) {
        return uVar10;
      }
    }
    if (local_e4 < 0x18) {
      if (local_e8 == 3) {
        if ((local_e4 == 0) && (local_e0 == 0x11)) {
          lVar8 = *local_d8 + -0x4c70757472617453;
          if (lVar8 == 0) {
            lVar8 = local_d8[1] + -0x7974696c61636f;
          }
          if (lVar8 == 0) {
            iVar6 = memcmp(param_4,local_88,(ulonglong)uVar11);
            if (iVar6 != 0) {
              return -0x3fffffff;
            }
            bVar1 = *(byte *)(plVar2 + 2);
            if (8 < bVar1) {
              return -0x3fffffff;
            }
            if ((0x109U >> (bVar1 & 0x1f) & 1) == 0) {
              return -0x3fffffff;
            }
            param_4[uVar11 - 1] = bVar1;
          }
        }
      }
      else {
        if ((local_e8 == -0x7ffffff0) && (local_e4 == 0)) {
          iVar6 = memcmp(param_4,local_88,(ulonglong)uVar11);
          if (iVar6 != 0) {
            return -0x3fffffff;
          }
          param_4[uVar11 - 1] = '\x04';
        }
        pUVar3 = local_c8;
        memcpy(local_c8,param_4 + uVar4 * uVar11,(ulonglong)uVar11);
        memcpy(pUVar3 + uVar11,local_d0,(ulonglong)uVar11);
        NVar7 = Tbsi_ShaHash(pwVar12,(PUCHAR)0x0,0,pUVar3,uVar11 * 2,param_4 + uVar4 * uVar11,uVar11
                             ,&local_dc);
        uVar11 = local_dc;
        if (NVar7 < 0) {
          return NVar7;
        }
      }
    }
    uVar9 = WbclApiMoveToNextElement((_WBCL_Iterator *)&local_c0);
    uVar5 = (uint)uVar9;
  } while( true );
}



===== Tbsi_Create_Attestation_From_Log @ 18000d3a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Tbsi_Create_Attestation_From_Log(unsigned char * __ptr64,unsigned int,unsigned short
   * __ptr64,unsigned short * __ptr64 * __ptr64,unsigned char * __ptr64,unsigned char *
   __ptr64,unsigned int,unsigned int * __ptr64,unsigned int) */

long __cdecl
Tbsi_Create_Attestation_From_Log
          (uchar *param_1,uint param_2,ushort *param_3,ushort **param_4,uchar *param_5,
          uchar *param_6,uint param_7,uint *param_8,uint param_9)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  long lVar7;
  short *psVar8;
  undefined8 uVar9;
  longlong lVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  void *pvVar14;
  ulonglong uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined1 auStackY_358 [32];
  uint *puVar19;
  uint local_324;
  uint local_320;
  uint local_31c;
  uint local_318;
  ushort *local_310;
  int local_308;
  int local_304;
  uint local_300;
  void *local_2f8;
  void *local_2f0;
  int local_2e8 [2];
  uint local_2e0;
  int local_2dc;
  void *local_2d8;
  uint *local_2d0;
  int *local_2c8;
  uchar *local_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined4 local_290;
  ushort local_28c;
  ushort *local_288;
  ushort **local_280;
  uchar *local_278;
  undefined4 local_270;
  undefined2 local_26c;
  undefined4 local_268;
  undefined2 local_264;
  short local_258 [264];
  ulonglong local_48;
  
                    /* 0xd3a0  1  Tbsi_Create_Attestation_From_Log */
  local_48 = __security_cookie ^ (ulonglong)auStackY_358;
  local_278 = param_5;
  bVar4 = false;
  pvVar14 = (void *)0x0;
  local_2d0 = param_8;
  local_310 = (ushort *)0x0;
  bVar3 = false;
  bVar5 = false;
  local_2d8 = (void *)0x0;
  local_318 = 0;
  local_2f8 = (void *)0x0;
  local_31c = 0;
  local_2f0 = (void *)0x0;
  local_324 = 0;
  local_320 = 0;
  local_270 = 0x55513600;
  local_26c = 0x3254;
  local_268 = 0x474354ff;
  local_264 = 0x1880;
  local_2e0 = 0;
  local_2c8 = (int *)0x0;
  local_298 = 0;
  local_290 = 0;
  local_28c = 0;
  local_308 = 0;
  local_304 = 0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  local_2a8 = 0;
  uStack_2a0 = 0;
  if ((((param_1 == (uchar *)0x0) || (param_2 == 0)) || (param_8 == (uint *)0x0)) ||
     ((param_9 & 0xfffffffe) != 0)) {
LAB_18000da13:
    lVar7 = -0x3ffffff3;
  }
  else {
    local_300 = param_2;
    local_2c0 = param_1;
    local_288 = param_3;
    local_280 = param_4;
    uVar6 = WbclApiInitIterator(param_1,param_2,(_WBCL_Iterator *)&local_2b8);
    if ((uVar6 >> 0x1c & 1) == 0) {
      if ((uVar6 & 0xfff0000) == 0x70000) {
        uVar16 = 0;
        if ((uVar6 & 0xffff) != 0) {
          uVar16 = uVar6 & 0xffff | 0xc0070000;
        }
        goto LAB_18000d4e9;
      }
      if ((uVar6 & 0xfff0000) == 0x280000) {
        uVar16 = uVar6 & 0xffff | 0xc0290000;
        goto LAB_18000d4e9;
      }
      if (-1 < (int)uVar6) {
        uVar16 = 0;
        goto LAB_18000d4fd;
      }
    }
    else {
      uVar16 = uVar6 & 0xefffffff;
LAB_18000d4e9:
      if ((int)uVar16 < 0) {
        return uVar16;
      }
LAB_18000d4fd:
      local_2dc = 0x14;
      if (local_28c == 0xb) {
        local_2dc = 0x20;
      }
      while (uVar16 == 0) {
        uVar6 = WbclApiGetCurrentElement
                          ((_WBCL_Iterator *)&local_2b8,&local_308,&local_304,
                           (undefined8 *)local_2e8,&local_2e0,&local_2c8);
        if ((uVar6 >> 0x1c & 1) == 0) {
          if ((uVar6 & 0xfff0000) == 0x70000) {
            uVar16 = 0;
            if ((uVar6 & 0xffff) != 0) {
              uVar16 = uVar6 & 0xffff | 0xc0070000;
            }
            goto LAB_18000d57f;
          }
          if ((uVar6 & 0xfff0000) == 0x280000) {
            uVar16 = uVar6 & 0xffff | 0xc0290000;
            goto LAB_18000d57f;
          }
          if ((int)uVar6 < 0) goto LAB_18000da04;
        }
        else {
          uVar16 = uVar6 & 0xefffffff;
LAB_18000d57f:
          if ((int)uVar16 < 0) {
            return uVar16;
          }
        }
        if (local_308 == -1) {
          if (local_304 == 3) {
            if (*local_2c8 == -0x3ffefffc) {
              uVar6 = local_2c8[1];
              if (7 < uVar6) {
                iVar12 = 0;
                piVar13 = local_2c8 + 2;
                uVar16 = 0;
                local_2e8[0] = 0;
                if (*piVar13 == -0x3ffefffc) {
                  iVar12 = 8;
                  local_2e8[0] = 8;
                  for (uVar15 = 0; (uint)uVar15 < uVar6;
                      uVar15 = (ulonglong)
                               ((uint)uVar15 + 8 + *(int *)(uVar15 + 0xc + (longlong)local_2c8))) {
                    if (((ulonglong)uVar6 < uVar15 + 8) ||
                       (*(int *)(uVar15 + 8 + (longlong)local_2c8) != -0x3ffefffc))
                    goto LAB_18000da13;
                    uVar16 = uVar16 + 1;
                    bVar3 = true;
                  }
                  if (!bVar3) goto LAB_18000da13;
                }
                else {
                  bVar3 = true;
                  uVar16 = 1;
                  piVar13 = local_2c8;
                }
                for (uVar17 = 0; bVar4 = bVar5, uVar17 < uVar16; uVar17 = uVar17 + 1) {
                  memset(local_258,0,0x208);
                  local_310 = (ushort *)0x0;
                  for (uVar15 = 0; (uint)uVar15 < (uint)piVar13[1];
                      uVar15 = (ulonglong)((uint)uVar15 + uVar11 + 8)) {
                    if (((ulonglong)(uVar6 - iVar12) < uVar15 + 8) ||
                       (uVar11 = *(uint *)(uVar15 + 0xc + (longlong)piVar13),
                       (ulonglong)(uVar6 - iVar12) < (ulonglong)uVar11 + 8 + uVar15))
                    goto LAB_18000da13;
                    iVar12 = *(int *)(uVar15 + 8 + (longlong)piVar13);
                    if (iVar12 == -0x7ff7fffd) {
                      if (0x206 < uVar11) goto LAB_18000da13;
                      local_310 = (ushort *)(uVar15 + 0x10 + (longlong)piVar13);
                      memcpy(local_258,local_310,(ulonglong)uVar11);
                    }
                    else if ((iVar12 == -0x7ff7fffc) && (uVar11 == 0x14)) {
                      local_2d8 = (void *)((longlong)piVar13 + uVar15 + 0x10);
                      local_318 = 0x14;
                    }
                    else if (iVar12 == -0x7ff7ffff) {
                      local_2f8 = (void *)((longlong)piVar13 + uVar15 + 0x10);
                      local_31c = uVar11;
                    }
                    else if (iVar12 == -0x7ff7fffe) {
                      local_2f0 = (void *)((longlong)piVar13 + uVar15 + 0x10);
                      local_324 = uVar11;
                    }
                    iVar12 = local_2e8[0];
                  }
                  if (local_288 == (ushort *)0x0) {
                    if (local_310 != (ushort *)0x0) {
LAB_18000d784:
                      if ((local_2f8 != (void *)0x0) && (local_2f0 != (void *)0x0)) {
                        bVar5 = true;
                        pvVar14 = local_2f8;
                        bVar4 = true;
                        break;
                      }
                    }
                  }
                  else {
                    if (local_310 != (ushort *)0x0) {
                      psVar8 = local_258;
                      do {
                        sVar1 = *psVar8;
                        sVar2 = *(short *)((longlong)psVar8 +
                                          ((longlong)local_288 - (longlong)local_258));
                        if (sVar1 != sVar2) break;
                        psVar8 = psVar8 + 1;
                      } while (sVar2 != 0);
                      if (sVar1 == sVar2) goto LAB_18000d784;
                    }
                    local_310 = (ushort *)0x0;
                    local_2f0 = (void *)0x0;
                    local_324 = 0;
                    local_2d8 = (void *)0x0;
                    local_318 = 0;
                    local_31c = 0;
                    piVar13 = (int *)((longlong)piVar13 + (ulonglong)(uint)piVar13[1] + 8);
                    local_2f8 = (void *)0x0;
                  }
                  pvVar14 = local_2f8;
                }
              }
            }
          }
        }
        uVar9 = WbclApiMoveToNextElement((_WBCL_Iterator *)&local_2b8);
        uVar16 = (uint)uVar9;
      }
      if ((!bVar4) ||
         ((lVar10 = RtlCompareMemory(pvVar14,&local_270,6), lVar10 != 6 &&
          (lVar10 = RtlCompareMemory(pvVar14,&local_268,6), lVar10 != 6)))) goto LAB_18000da13;
      uVar17 = Tbsi_FilterLog(local_2c0,local_300,0xf77f,0,0,&local_320);
      uVar16 = local_31c;
      uVar6 = local_320;
      if ((int)uVar17 < 0) {
        return uVar17;
      }
      uVar15 = (ulonglong)local_31c;
      uVar18 = local_2dc * 0x18;
      uVar11 = local_31c + 0x1c + uVar18 + local_320 + local_324;
      if ((param_6 == (uchar *)0x0) || (param_7 == 0)) {
        *local_2d0 = uVar11;
        return uVar17;
      }
      if (param_7 < uVar11) {
        *local_2d0 = uVar11;
        return -0x3fffffdd;
      }
      builtin_memcpy(param_6,"PADS",4);
      param_6[8] = '\x1c';
      param_6[9] = '\0';
      param_6[10] = '\0';
      param_6[0xb] = '\0';
      lVar10 = RtlCompareMemory(pvVar14,&local_270,6);
      if (lVar10 == 6) {
        param_6[4] = '\x01';
        param_6[5] = '\0';
        param_6[6] = '\0';
        param_6[7] = '\0';
      }
      else {
        lVar10 = RtlCompareMemory(pvVar14,&local_268,6);
        if (lVar10 == 6) {
          param_6[4] = '\x02';
          param_6[5] = '\0';
          param_6[6] = '\0';
          param_6[7] = '\0';
          if (uStack_2a0._2_2_ == 2) {
            *(uint *)(param_6 + 0x1c) = (uint)local_28c;
            param_6[8] = ' ';
            param_6[9] = '\0';
            param_6[10] = '\0';
            param_6[0xb] = '\0';
          }
        }
      }
      *(uint *)(param_6 + 0x14) = local_324;
      *(uint *)(param_6 + 0xc) = uVar18;
      *(uint *)(param_6 + 0x10) = uVar16;
      *(uint *)(param_6 + 0x18) = uVar6;
      if ((pvVar14 != (void *)0x0) &&
         (uVar17 = *(int *)(param_6 + 8) + uVar18, uVar16 <= param_7 - uVar17)) {
        memcpy(param_6 + uVar17,local_2f8,uVar15);
        uVar17 = uVar17 + uVar16;
        if ((local_2f0 != (void *)0x0) && (local_324 <= param_7 - uVar17)) {
          memcpy(param_6 + uVar17,local_2f0,(ulonglong)local_324);
          puVar19 = &local_320;
          uVar16 = Tbsi_FilterLog(local_2c0,local_300,0xf77f,
                                  (longlong)(param_6 + (uVar17 + local_324)),uVar6,puVar19);
          uVar6 = local_320;
          if ((int)uVar16 < 0) {
            return uVar16;
          }
          lVar7 = Tbsi_ComputeSoftPCRs
                            (param_6 + (uVar17 + local_324),local_320,local_28c,
                             param_6 + *(uint *)(param_6 + 8),uVar18,puVar19);
          if (lVar7 < 0) {
            return lVar7;
          }
          *local_2d0 = uVar17 + local_324 + uVar6;
          if (local_280 != (ushort **)0x0) {
            *local_280 = local_310;
          }
          if (local_278 == (uchar *)0x0) {
            return lVar7;
          }
          uVar6 = local_318;
          if (0x14 < local_318) {
            uVar6 = 0x14;
          }
          memcpy(local_278,local_2d8,(ulonglong)uVar6);
          return lVar7;
        }
      }
    }
LAB_18000da04:
    lVar7 = -0x3fffffff;
  }
  return lVar7;
}



===== WnfDeviceIDCallback @ 18000da50 =====

/* long __cdecl WnfDeviceIDCallback(struct _WNF_STATE_NAME,unsigned long,struct _WNF_TYPE_ID *
   __ptr64,void * __ptr64,void const * __ptr64,unsigned long) */

long __cdecl WnfDeviceIDCallback(void)

{
  undefined8 *in_R9;
  int *in_stack_00000028;
  int in_stack_00000030;
  
  if (in_R9 == (undefined8 *)0x0) {
    if (in_stack_00000028 == (int *)0x0) {
      return -0x3fffffff;
    }
    if (in_stack_00000030 != 4) {
      return -0x3fffffff;
    }
    DAT_180015bc8 = *in_stack_00000028;
  }
  else if (((in_stack_00000028 != (int *)0x0) && (in_stack_00000030 == 4)) &&
          (*in_stack_00000028 == 1)) {
    SetEvent((HANDLE)*in_R9);
  }
  return 0;
}



===== McGenControlCallbackV2 @ 18000dab0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(short *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar5 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar5 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar5 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar5 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
          if (bVar3) {
            uVar4 = uVar4 | *puVar1;
          }
          else {
            uVar4 = ~uVar4 & *puVar1;
          }
          *puVar1 = uVar4;
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(ushort *)(param_7 + 0x2a));
        return;
      }
    }
  }
  return;
}



===== McGenEventRegister_EventRegister @ 18000dbc4 =====

void McGenEventRegister_EventRegister(void)

{
  if (WIN32TPM_Provider_Context == 0) {
    EventRegister((LPCGUID)&WIN32TPM_Provider,McGenControlCallbackV2,&WIN32TPM_Provider_Context,
                  (PREGHANDLE)&WIN32TPM_Provider_Context);
  }
  return;
}



===== McGenEventUnregister_EventUnregister @ 18000dc04 =====

ULONG McGenEventUnregister_EventUnregister(void)

{
  ULONG UVar1;
  
  if (WIN32TPM_Provider_Context == 0) {
    UVar1 = 0;
  }
  else {
    UVar1 = EventUnregister(WIN32TPM_Provider_Context);
    WIN32TPM_Provider_Context = 0;
  }
  return UVar1;
}



===== McGenEventWrite_EventWriteTransfer @ 18000dc38 =====

void McGenEventWrite_EventWriteTransfer(void)

{
  ushort *puVar1;
  ULONG UVar2;
  uint uVar3;
  PEVENT_DATA_DESCRIPTOR in_stack_00000028;
  
  puVar1 = DAT_180015008;
  UVar2 = 0;
  if (DAT_180015008 == (ushort *)0x0) {
    in_stack_00000028->Ptr = 0;
    uVar3 = 0;
  }
  else {
    in_stack_00000028->Ptr = (ULONGLONG)DAT_180015008;
    UVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  in_stack_00000028->Size = uVar3;
  in_stack_00000028->Reserved = UVar2;
  EventWriteTransfer(WIN32TPM_Provider_Context,
                     (PCEVENT_DESCRIPTOR)&TPMCOREEVENT_TBS_PROVISION_DEVICEID,(LPCGUID)0x0,
                     (LPCGUID)0x0,1,in_stack_00000028);
  return;
}



===== Tbsi_FilterLog @ 18000dca0 =====

uint Tbsi_FilterLog(uchar *param_1,uint param_2,uint param_3,longlong param_4,uint param_5,
                   uint *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_res8 [2];
  uint local_88 [2];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined2 local_44;
  
                    /* 0xdca0  8  Tbsi_FilterLog */
  local_50 = 0;
  local_48 = 0;
  local_44 = 0;
  local_88[0] = 0;
  local_res8[0] = 0;
  local_88[1] = 0;
  uVar4 = 0;
  uVar5 = 0;
  local_70 = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  if ((((param_1 == (uchar *)0x0) || (param_2 == 0)) || (param_3 == 0)) || (param_6 == (uint *)0x0))
  {
    return 0xc000000d;
  }
  *param_6 = 0;
  uVar1 = WbclApiInitIterator(param_1,param_2,(_WBCL_Iterator *)&local_70);
  if ((uVar1 >> 0x1c & 1) == 0) {
    if ((uVar1 & 0xfff0000) == 0x70000) {
      uVar3 = 0;
      if ((uVar1 & 0xffff) != 0) {
        uVar3 = uVar1 & 0xffff | 0xc0070000;
      }
      goto LAB_18000dd64;
    }
    if ((uVar1 & 0xfff0000) == 0x280000) {
      uVar3 = uVar1 & 0xffff | 0xc0290000;
      goto LAB_18000dd64;
    }
    if ((int)uVar1 < 0) {
      return 0xc0000001;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = uVar1 & 0xefffffff;
LAB_18000dd64:
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  while (uVar3 == 0) {
    uVar1 = WbclApiGetCurrentElement
                      ((_WBCL_Iterator *)&local_70,local_res8,local_88 + 1,&local_78,local_88,
                       &local_80);
    if ((uVar1 >> 0x1c & 1) == 0) {
      if ((uVar1 & 0xfff0000) == 0x70000) {
        uVar3 = 0;
        if ((uVar1 & 0xffff) != 0) {
          uVar3 = uVar1 & 0xffff | 0xc0070000;
        }
        goto LAB_18000dde2;
      }
      if ((uVar1 & 0xfff0000) == 0x280000) {
        uVar3 = uVar1 & 0xffff | 0xc0290000;
        goto LAB_18000dde2;
      }
      if ((int)uVar1 < 0) {
        return 0xc0000001;
      }
    }
    else {
      uVar3 = uVar1 & 0xefffffff;
LAB_18000dde2:
      if ((int)uVar3 < 0) {
        return uVar3;
      }
    }
    if ((local_res8[0] < 0x18) && ((param_3 >> (local_res8[0] & 0x1f) & 1) != 0)) {
      uVar4 = uVar4 + uStack_5c;
    }
    uVar2 = WbclApiMoveToNextElement((_WBCL_Iterator *)&local_70);
    uVar3 = (uint)uVar2;
  }
  if ((param_4 == 0) || (param_5 == 0)) goto LAB_18000df56;
  if (param_5 < uVar4) {
    *param_6 = uVar4;
    return 0xc0000023;
  }
  uVar1 = WbclApiInitIterator(param_1,param_2,(_WBCL_Iterator *)&local_70);
  if ((uVar1 >> 0x1c & 1) == 0) {
    if ((uVar1 & 0xfff0000) == 0x70000) {
      uVar3 = 0;
      if ((uVar1 & 0xffff) != 0) {
        uVar3 = uVar1 & 0xffff | 0xc0070000;
      }
      goto LAB_18000de89;
    }
    if ((uVar1 & 0xfff0000) == 0x280000) {
      uVar3 = uVar1 & 0xffff | 0xc0290000;
      goto LAB_18000de89;
    }
    if ((int)uVar1 < 0) {
      return 0xc0000001;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = uVar1 & 0xefffffff;
LAB_18000de89:
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  while (uVar3 == 0) {
    uVar1 = WbclApiGetCurrentElement
                      ((_WBCL_Iterator *)&local_70,local_res8,local_88 + 1,&local_78,local_88,
                       &local_80);
    if ((uVar1 >> 0x1c & 1) == 0) {
      if ((uVar1 & 0xfff0000) == 0x70000) {
        uVar3 = 0;
        if ((uVar1 & 0xffff) != 0) {
          uVar3 = uVar1 & 0xffff | 0xc0070000;
        }
        goto LAB_18000df0b;
      }
      if ((uVar1 & 0xfff0000) == 0x280000) {
        uVar3 = uVar1 & 0xffff | 0xc0290000;
        goto LAB_18000df0b;
      }
      if ((int)uVar1 < 0) {
        return 0xc0000001;
      }
    }
    else {
      uVar3 = uVar1 & 0xefffffff;
LAB_18000df0b:
      if ((int)uVar3 < 0) {
        return uVar3;
      }
    }
    if ((local_res8[0] < 0x19) && ((param_3 >> (local_res8[0] & 0x1f) & 1) != 0)) {
      uVar1 = uStack_5c + uVar5;
      if (param_5 < uVar1) {
        return 0xc000000d;
      }
      memcpy((void *)((ulonglong)uVar5 + param_4),(void *)CONCAT44(uStack_60,uStack_64),
             (ulonglong)uStack_5c);
      uVar5 = uVar1;
    }
    uVar2 = WbclApiMoveToNextElement((_WBCL_Iterator *)&local_70);
    uVar3 = (uint)uVar2;
  }
LAB_18000df56:
  *param_6 = uVar4;
  return 0;
}



===== Tbsi_ShaHash @ 18000df90 =====

NTSTATUS Tbsi_ShaHash(wchar_t *param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,ULONG param_5,
                     PUCHAR param_6,uint param_7,uint *param_8)

{
  int iVar1;
  NTSTATUS NVar2;
  ULONG dwFlags;
  uint local_38;
  ULONG local_34;
  BCRYPT_HASH_HANDLE local_30;
  BCRYPT_ALG_HANDLE local_28 [2];
  
                    /* 0xdf90  16  Tbsi_ShaHash */
  local_28[0] = (BCRYPT_HANDLE)0x0;
  local_30 = (BCRYPT_HASH_HANDLE)0x0;
  dwFlags = 0;
  local_38 = 0;
  local_34 = 0;
  iVar1 = wcscmp(param_1,L"SHA1");
  if (((iVar1 != 0) && (iVar1 = wcscmp(param_1,L"SHA256"), iVar1 != 0)) &&
     (iVar1 = wcscmp(param_1,L"SHA384"), iVar1 != 0)) {
    return -0x3ffffff3;
  }
  if ((param_3 != 0) && (dwFlags = 0, param_2 != (PUCHAR)0x0)) {
    dwFlags = 8;
  }
  NVar2 = BCryptOpenAlgorithmProvider(local_28,param_1,L"Microsoft Primitive Provider",dwFlags);
  if ((NVar2 < 0) ||
     (NVar2 = BCryptGetProperty(local_28[0],L"HashDigestLength",(PUCHAR)&local_38,4,&local_34,0),
     NVar2 < 0)) goto LAB_18000e11b;
  if ((param_6 != (PUCHAR)0x0) && (param_7 != 0)) {
    if (param_7 < local_38) {
      NVar2 = -0x3fffffdd;
      *param_8 = local_38;
      goto LAB_18000e11b;
    }
    NVar2 = BCryptCreateHash(local_28[0],&local_30,(PUCHAR)0x0,0,param_2,param_3,0);
    if (((NVar2 < 0) || (NVar2 = BCryptHashData(local_30,param_4,param_5,0), NVar2 < 0)) ||
       (NVar2 = BCryptFinishHash(local_30,param_6,param_7,0), NVar2 < 0)) goto LAB_18000e11b;
  }
  *param_8 = local_38;
LAB_18000e11b:
  if (local_30 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_30);
    local_30 = (BCRYPT_HASH_HANDLE)0x0;
  }
  if (local_28[0] != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(local_28[0],0);
  }
  return NVar2;
}



===== WbclGetCurrentElementData @ 18000e170 =====

/* unsigned char * __ptr64 __cdecl WbclGetCurrentElementData(struct _WBCL_Iterator * __ptr64) */

uchar * __cdecl WbclGetCurrentElementData(_WBCL_Iterator *param_1)

{
  long lVar1;
  uchar *puVar2;
  uint local_res10 [2];
  uint local_res18 [4];
  
  puVar2 = (uchar *)0x0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  lVar1 = WbclGetCurrentElementDataSize(param_1,local_res18);
  if (-1 < lVar1) {
    lVar1 = WbclGetCurrentElementDigestSize(param_1,local_res10);
    if (lVar1 == 0) {
      puVar2 = (uchar *)((ulonglong)local_res10[0] + 0xc + *(longlong *)(param_1 + 0xc));
    }
  }
  return puVar2;
}



===== WbclGetCurrentElementDataSize @ 18000e1c8 =====

/* long __cdecl WbclGetCurrentElementDataSize(struct _WBCL_Iterator * __ptr64,unsigned int *
   __ptr64) */

long __cdecl WbclGetCurrentElementDataSize(_WBCL_Iterator *param_1,uint *param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint local_res10 [6];
  
  local_res10[0] = 0;
  if (param_2 == (uint *)0x0) {
    uVar4 = 0xc000000d;
  }
  else {
    uVar4 = WbclGetCurrentElementDigestSize(param_1,local_res10);
    if (uVar4 == 0) {
      lVar2 = *(longlong *)(param_1 + 0xc);
      uVar1 = *(uint *)(lVar2 + 8 + (ulonglong)local_res10[0]);
      uVar3 = *(ulonglong *)param_1;
      uVar5 = *(uint *)(param_1 + 8) + uVar3;
      *param_2 = uVar1;
      uVar6 = 0xffffffffffffffff;
      if (uVar5 >= uVar3) {
        uVar6 = uVar5;
      }
      uVar4 = -(uint)(uVar5 < uVar3) & 0xc0000095;
      if ((uVar3 <= uVar5) && (uVar6 < (ulonglong)local_res10[0] + 0xc + lVar2 + (ulonglong)uVar1))
      {
        uVar4 = 0x80000005;
      }
    }
  }
  return uVar4;
}



===== WbclGetCurrentElementDigest @ 18000e24c =====

/* unsigned char * __ptr64 __cdecl WbclGetCurrentElementDigest(struct _WBCL_Iterator * __ptr64) */

uchar * __cdecl WbclGetCurrentElementDigest(_WBCL_Iterator *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  
  puVar6 = (uint *)(*(longlong *)(param_1 + 0xc) + 8);
  uVar2 = 0;
  if (*(short *)(param_1 + 0x1a) == 1) goto LAB_18000e316;
  if (*(short *)(param_1 + 0x1a) == 2) {
    puVar7 = *(uint **)param_1;
    puVar3 = (uint *)((ulonglong)*(uint *)(param_1 + 8) + (longlong)puVar7);
    puVar8 = (uint *)0xffffffffffffffff;
    if (puVar3 >= puVar7) {
      puVar8 = puVar3;
    }
    uVar2 = -(uint)(puVar3 < puVar7) & 0xc0000095;
    if (puVar3 < puVar7) goto LAB_18000e316;
    uVar1 = *puVar6;
    puVar7 = (uint *)(*(longlong *)(param_1 + 0xc) + 0xc);
    if (5 < uVar1) {
LAB_18000e2be:
      uVar2 = 0xc0000095;
      puVar6 = puVar7;
      goto LAB_18000e316;
    }
    for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
      puVar6 = (uint *)((longlong)puVar7 + 2);
      if ((ushort)*puVar7 == *(ushort *)(param_1 + 0x2c)) goto LAB_18000e316;
      puVar3 = puVar6;
      uVar2 = WbclGetDigestSizeUnchecked(param_1,(ushort)*puVar7);
      puVar4 = (uint *)((ulonglong)uVar2 + (longlong)puVar3);
      puVar7 = (uint *)0xffffffffffffffff;
      if (puVar3 <= puVar4) {
        puVar7 = puVar4;
      }
      uVar2 = -(uint)(puVar4 < puVar6) & 0xc0000095;
      if ((puVar4 < puVar6) || (puVar8 < puVar7)) goto LAB_18000e2be;
    }
  }
  puVar6 = (uint *)0x0;
LAB_18000e316:
  puVar7 = (uint *)0x0;
  if (uVar2 == 0) {
    puVar7 = puVar6;
  }
  return (uchar *)puVar7;
}



===== WbclGetCurrentElementDigestSize @ 18000e348 =====

/* long __cdecl WbclGetCurrentElementDigestSize(struct _WBCL_Iterator * __ptr64,unsigned int *
   __ptr64) */

long __cdecl WbclGetCurrentElementDigestSize(_WBCL_Iterator *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar9 = 0;
  uVar8 = 0;
  uVar3 = 0;
  uVar4 = 0;
  uVar2 = 0;
  if (*(short *)(param_1 + 0x1a) == 1) {
    uVar4 = 0x14;
  }
  else if (*(short *)(param_1 + 0x1a) == 2) {
    puVar6 = *(ushort **)param_1;
    puVar5 = (ushort *)((ulonglong)*(uint *)(param_1 + 8) + (longlong)puVar6);
    puVar7 = (ushort *)0xffffffffffffffff;
    if (puVar5 >= puVar6) {
      puVar7 = puVar5;
    }
    uVar2 = -(uint)(puVar5 < puVar6) & 0xc0000095;
    if (puVar6 <= puVar5) {
      puVar6 = (ushort *)(*(longlong *)(param_1 + 0xc) + 0xc);
      uVar4 = 0;
      if (puVar7 < puVar6) {
LAB_18000e428:
        uVar2 = 0x80000005;
        uVar3 = uVar8;
      }
      else {
        uVar1 = *(uint *)(*(longlong *)(param_1 + 0xc) + 8);
        uVar4 = 4;
        uVar10 = 4;
        if (uVar1 < 6) {
          uVar11 = 0;
          uVar8 = 4;
          if (uVar1 != 0) {
            do {
              uVar4 = uVar8;
              uVar8 = (uint)uVar9;
              if (puVar7 < puVar6 + 1) goto LAB_18000e428;
              uVar10 = uVar4;
              uVar3 = WbclGetDigestSizeUnchecked(param_1,*puVar6);
              uVar2 = (uint)uVar9;
              uVar4 = uVar3 + 2;
              uVar8 = uVar2;
              if (((uVar4 < uVar3) ||
                  (puVar5 = (ushort *)((ulonglong)uVar4 + (longlong)puVar6), puVar5 < puVar6)) ||
                 (puVar7 < puVar5)) goto LAB_18000e3d1;
              uVar4 = uVar4 + uVar10;
              if (uVar4 < uVar10) {
                uVar10 = 0xffffffff;
                goto LAB_18000e3d1;
              }
              uVar11 = uVar11 + 1;
              puVar6 = puVar5;
              uVar3 = uVar2;
              uVar8 = uVar4;
            } while (uVar11 < uVar1);
          }
        }
        else {
LAB_18000e3d1:
          uVar4 = uVar10;
          uVar2 = 0xc0000095;
          uVar3 = uVar8;
        }
      }
    }
  }
  if (param_2 != (uint *)0x0) {
    if (uVar2 == 0) {
      uVar3 = uVar4;
    }
    *param_2 = uVar3;
  }
  return uVar2;
}



===== WbclGetCurrentElementSize @ 18000e460 =====

/* long __cdecl WbclGetCurrentElementSize(struct _WBCL_Iterator * __ptr64,unsigned int * __ptr64) */

long __cdecl WbclGetCurrentElementSize(_WBCL_Iterator *param_1,uint *param_2)

{
  long lVar1;
  uint local_res18 [2];
  uint local_res20 [2];
  
  local_res18[0] = 0;
  local_res20[0] = 0;
  lVar1 = WbclGetCurrentElementDigestSize(param_1,local_res20);
  if ((lVar1 == 0) && (param_2 != (uint *)0x0)) {
    lVar1 = WbclGetCurrentElementDataSize(param_1,local_res18);
    if (-1 < lVar1) {
      *param_2 = local_res18[0] + 0xc + local_res20[0];
    }
  }
  return lVar1;
}



===== WbclGetDigestSizeUnchecked @ 18000e4c8 =====

/* unsigned int __cdecl WbclGetDigestSizeUnchecked(struct _WBCL_Iterator * __ptr64,unsigned short)
    */

uint __cdecl WbclGetDigestSizeUnchecked(_WBCL_Iterator *param_1,ushort param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  
  uVar1 = 0;
  uVar2 = 0x14;
  do {
    if (*(uint *)(param_1 + 0x1c) <= (uint)uVar1) {
LAB_18000e4ec:
      return (uint)uVar2;
    }
    if (*(ushort *)(*(longlong *)(param_1 + 0x20) + uVar1 * 4) == param_2) {
      uVar2 = *(ushort *)(*(longlong *)(param_1 + 0x20) + 2 + uVar1 * 4);
      goto LAB_18000e4ec;
    }
    uVar1 = (ulonglong)((uint)uVar1 + 1);
  } while( true );
}



===== WbclApiGetCurrentElement @ 18000e4f8 =====

uint WbclApiGetCurrentElement
               (_WBCL_Iterator *param_1,undefined4 *param_2,undefined4 *param_3,undefined8 *param_4,
               uint *param_5,undefined8 *param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  uchar *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if ((((puVar1 == (undefined4 *)0x0) || (*(int *)(param_1 + 0x14) == 0)) ||
      (param_2 == (undefined4 *)0x0)) || (param_3 == (undefined4 *)0x0)) {
    uVar4 = 0x80070057;
  }
  else {
    *param_2 = *puVar1;
    *param_3 = puVar1[1];
    if (param_4 != (undefined8 *)0x0) {
      puVar3 = WbclGetCurrentElementDigest(param_1);
      *param_4 = puVar3;
    }
    if ((param_5 != (uint *)0x0) &&
       (uVar2 = WbclGetCurrentElementDataSize(param_1,param_5), (int)uVar2 < 0)) {
      return uVar2 | 0x10000000;
    }
    if (param_6 != (undefined8 *)0x0) {
      puVar3 = WbclGetCurrentElementData(param_1);
      *param_6 = puVar3;
    }
  }
  return uVar4;
}



===== WbclApiInitIterator @ 18000e594 =====

undefined4 WbclApiInitIterator(uchar *param_1,uint param_2,_WBCL_Iterator *param_3)

{
  ushort *puVar1;
  ulonglong uVar2;
  uchar uVar3;
  uchar uVar4;
  short sVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  uchar *puVar9;
  uchar *puVar10;
  undefined8 uVar11;
  short *psVar12;
  uint uVar13;
  ulonglong uVar14;
  bool bVar15;
  uint local_res8 [2];
  int local_res20 [2];
  int local_38;
  uint local_34 [3];
  
  local_34[0] = 0;
  uVar13 = 0;
  local_res8[0] = 0;
  local_res20[0] = 0;
  local_38 = 0;
  if (((param_1 == (uchar *)0x0) || (param_2 < 0x20)) || (param_3 == (_WBCL_Iterator *)0x0)) {
    return 0x80070057;
  }
  *(undefined4 *)(param_3 + 0x1c) = 0;
  *(undefined8 *)(param_3 + 0x20) = 0;
  *(uchar **)param_3 = param_1;
  *(uchar **)(param_3 + 0xc) = param_1;
  *(undefined4 *)(param_3 + 0x28) = 1;
  *(uint *)(param_3 + 8) = param_2;
  *(undefined4 *)(param_3 + 0x18) = 0x10014;
  *(undefined2 *)(param_3 + 0x2c) = 4;
  lVar7 = WbclGetCurrentElementSize(param_3,local_res8);
  if ((lVar7 == 0) && (local_res8[0] <= param_2)) {
    *(uint *)(param_3 + 0x14) = local_res8[0];
    uVar8 = WbclApiGetCurrentElement
                      (param_3,local_res20,&local_38,(undefined8 *)0x0,local_34,(undefined8 *)0x0);
    uVar6 = local_34[0];
    if (uVar8 == 0) {
      if (local_res20[0] != 0) {
        return 0;
      }
      if (local_38 != 3) {
        return 0;
      }
      uVar14 = (ulonglong)local_34[0];
      if (local_34[0] < 0x21) {
        return 0;
      }
      puVar9 = WbclGetCurrentElementData(param_3);
      if (((puVar9 != (uchar *)0x0) && (param_1 <= puVar9)) && (puVar9 + uVar14 < param_1 + param_2)
         ) {
        puVar10 = puVar9;
        do {
          uVar3 = *puVar10;
          uVar4 = puVar10[(longlong)TCG_EfiSpecIdEventStruct_Signature_03 - (longlong)puVar9];
          if (uVar3 != uVar4) break;
          puVar10 = puVar10 + 1;
        } while (uVar4 != '\0');
        if (uVar3 != uVar4) {
          puVar10 = puVar9;
          do {
            uVar3 = *puVar10;
            uVar4 = puVar10[(longlong)TCG_EfiSpecIdEventStruct_Signature_02 - (longlong)puVar9];
            if (uVar3 != uVar4) break;
            puVar10 = puVar10 + 1;
          } while (uVar4 != '\0');
          if (uVar3 != uVar4) {
            return 0;
          }
        }
        if ((puVar9[0x15] != '\0') &&
           (((puVar9[0x15] != '\x01' || (1 < puVar9[0x14])) && (0x1b < uVar6)))) {
          uVar6 = *(uint *)(puVar9 + 0x18);
          if (uVar6 < 6) {
            uVar2 = (ulonglong)uVar6 * 4 + 0x1c;
            if (uVar14 < uVar2) {
              return 0x8007000d;
            }
            if (puVar9 + uVar14 <= puVar9 + uVar2) {
              return 0x8007000d;
            }
            if (param_1 + param_2 <= puVar9 + uVar2) {
              return 0x8007000d;
            }
            uVar8 = 0;
            if (uVar6 != 0) {
              psVar12 = (short *)(puVar9 + 0x1e);
              do {
                if (0x29 < (ushort)psVar12[-1]) {
                  return 0x8007000d;
                }
                sVar5 = psVar12[-1];
                if (sVar5 == 4) {
                  bVar15 = *psVar12 == 0x14;
LAB_18000e7bf:
                  if (!bVar15) {
                    return 0x8007000d;
                  }
                }
                else {
                  if (sVar5 == 0xb) {
LAB_18000e7b0:
                    bVar15 = *psVar12 == 0x20;
                    goto LAB_18000e7bf;
                  }
                  if (sVar5 == 0xc) {
LAB_18000e7aa:
                    bVar15 = *psVar12 == 0x30;
                    goto LAB_18000e7bf;
                  }
                  if (sVar5 == 0xd) {
LAB_18000e7a4:
                    bVar15 = *psVar12 == 0x40;
                    goto LAB_18000e7bf;
                  }
                  if ((sVar5 == 0x12) || (sVar5 == 0x27)) goto LAB_18000e7b0;
                  if (sVar5 == 0x28) goto LAB_18000e7aa;
                  if (sVar5 == 0x29) goto LAB_18000e7a4;
                }
                puVar1 = (ushort *)(psVar12 + -1);
                uVar8 = uVar8 + 1;
                psVar12 = psVar12 + 2;
                uVar13 = uVar13 | *(uint *)(&DAT_180011660 + (ulonglong)*puVar1 * 4);
              } while (uVar8 < uVar6);
            }
            *(uint *)(param_3 + 0x28) = uVar13;
            *(uchar **)(param_3 + 0x20) = puVar9 + 0x1c;
            *(undefined2 *)(param_3 + 0x1a) = 2;
            *(uint *)(param_3 + 0x1c) = uVar6;
            if ((uVar13 & 2) == 0) {
              if ((uVar13 & 1) == 0) {
                if ((uVar13 & 4) == 0) {
                  if ((uVar13 & 8) == 0) {
                    return 0x80070032;
                  }
                  *(undefined2 *)(param_3 + 0x2c) = 0xd;
                  *(undefined2 *)(param_3 + 0x18) = 0x40;
                }
                else {
                  *(undefined2 *)(param_3 + 0x2c) = 0xc;
                  *(undefined2 *)(param_3 + 0x18) = 0x30;
                }
              }
              else {
                *(undefined2 *)(param_3 + 0x2c) = 4;
                *(undefined2 *)(param_3 + 0x18) = 0x14;
              }
            }
            else {
              *(undefined2 *)(param_3 + 0x2c) = 0xb;
              *(undefined2 *)(param_3 + 0x18) = 0x20;
            }
            uVar11 = WbclApiMoveToNextElement(param_3);
            if ((int)uVar11 == 0) {
              return 0;
            }
            return 0x8007000d;
          }
        }
        return 0x80070032;
      }
    }
  }
  return 0x8007000d;
}



===== WbclApiMoveToNextElement @ 18000e880 =====

undefined8 WbclApiMoveToNextElement(_WBCL_Iterator *param_1)

{
  long lVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint local_res8 [2];
  
  uVar3 = 0;
  uVar4 = *(ulonglong *)(param_1 + 0xc);
  local_res8[0] = 0;
  if ((uVar4 != 0) && (*(int *)(param_1 + 0x14) != 0)) {
    uVar5 = *(uint *)(param_1 + 0x14) + uVar4;
    if ((uVar4 <= uVar5) &&
       (uVar4 = (ulonglong)*(uint *)(param_1 + 8) + *(longlong *)param_1,
       *(ulonglong *)param_1 <= uVar4)) {
      lVar2 = 0x20;
      if (*(short *)(param_1 + 0x1a) == 2) {
        lVar2 = (ulonglong)*(ushort *)(param_1 + 0x18) + 0x12;
      }
      if ((uVar5 <= uVar5 + lVar2) && (uVar5 + lVar2 <= uVar4)) {
        *(ulonglong *)(param_1 + 0xc) = uVar5;
        lVar1 = WbclGetCurrentElementSize(param_1,local_res8);
        if (lVar1 == 0) {
          *(uint *)(param_1 + 0x14) = local_res8[0];
          if ((uVar5 <= uVar5 + local_res8[0]) && (uVar5 + local_res8[0] <= uVar4)) {
            return 0;
          }
        }
      }
    }
    *(undefined8 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    uVar3 = 1;
  }
  return uVar3;
}



===== __delayLoadHelper2 @ 18000e940 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(0x180000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== __GSHandlerCheck @ 18000e984 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 18000e9a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}



===== __chkstk @ 18000ea20 =====

/* WARNING: This is an inlined function */

void __chkstk(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 < StackLimit) {
    puVar2 = StackLimit;
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined1 *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}



===== wcscmp @ 18000ea74 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ea74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== memcmp @ 18000ea80 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ea80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}



===== memcpy @ 18000ea8c =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ea8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memmove @ 18000ea98 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000ea98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



===== _guard_dispatch_icall @ 18000eac0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 18000eae0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018000eae0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 18000eb00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== fin$0 @ 18000eb0c =====

void `dllmain_crt_process_attach'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}



===== fin$0 @ 18000eb29 =====

void `dllmain_crt_process_detach'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}



===== fin$1 @ 18000eb42 =====

void `dllmain_crt_process_detach'::__l1::fin_1(void)

{
  __scrt_dllmain_uninitialize_critical();
  return;
}



===== filt$0 @ 18000eb5c =====

void `dllmain_dispatch'::__l1::filt_0(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),dllmain_crt_dispatch,*(undefined4 *)*param_1,param_1);
  return;
}



===== __scrt_is_nonwritable_in_current_image$filt$0 @ 18000eb98 =====

bool __scrt_is_nonwritable_in_current_image_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== `dynamic_atexit_destructor_for_'g_featureStateManager'' @ 18000ebc0 =====

void wil::details::_dynamic_atexit_destructor_for__g_featureStateManager__(void)

{
  bool bVar1;
  
  bVar1 = ProcessShutdownInProgress();
  if (bVar1) {
    g_featureStateManager = (shutdown_aware_object<wil::details::FeatureStateManager>)0x0;
    details_abi::ProcessLocalStorage<wil::details_abi::FeatureStateData>::
    ~ProcessLocalStorage<wil::details_abi::FeatureStateData>
              ((ProcessLocalStorage<wil::details_abi::FeatureStateData> *)
               &PTR_s_WilStaging_02_1800150d0);
    return;
  }
  FeatureStateManager::~FeatureStateManager((FeatureStateManager *)&g_featureStateManager);
  return;
}



===== `dynamic_atexit_destructor_for_'g_enabledStateManager'' @ 18000ec00 =====

void wil::details::_dynamic_atexit_destructor_for__g_enabledStateManager__(void)

{
  bool bVar1;
  
  bVar1 = ProcessShutdownInProgress();
  if (bVar1) {
    g_enabledStateManager = (shutdown_aware_object<wil::details::EnabledStateManager>)0x0;
    EnabledStateManager::RecordCachedUsageUnderLock((EnabledStateManager *)&g_enabledStateManager);
    return;
  }
  EnabledStateManager::~EnabledStateManager((EnabledStateManager *)&g_enabledStateManager);
  return;
}



===== `dynamic_atexit_destructor_for_'g_processLocalData'' @ 18000ec40 =====

void wil::details::_dynamic_atexit_destructor_for__g_processLocalData__(void)

{
  if (DAT_1800150c0 != (ProcessLocalStorageData<wil::details_abi::ProcessLocalData> *)0x0) {
    details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Release(DAT_1800150c0)
    ;
  }
  return;
}



===== `dynamic_atexit_destructor_for_'g_threadFailureCallbacks'' @ 18000ec70 =====

void wil::details::_dynamic_atexit_destructor_for__g_threadFailureCallbacks__(void)

{
  details_abi::ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>::
  ~ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>(&g_threadFailureCallbacks)
  ;
  return;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 18000f010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


