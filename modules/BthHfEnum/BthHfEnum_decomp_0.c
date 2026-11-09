
===== Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>_> @ 140001010 =====

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
  longlong lVar1;
  long lVar2;
  longlong lVar3;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
  _tlgWrapperByVal<8> *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = *(wchar_t **)param_6;
  if (local_28 == (wchar_t *)0x0) {
    local_28 = L"";
    local_20 = 2;
  }
  else {
    lVar3 = -1;
    do {
      lVar1 = lVar3 + 1;
      lVar3 = lVar3 + 1;
    } while (local_28[lVar1] != L'\0');
    local_20 = (int)lVar3 * 2 + 2;
  }
  local_38 = param_5;
  local_1c = 0;
  local_30 = 8;
  lVar2 = _tlgWriteTransfer_EtwWriteTransfer(0x140022000,param_2,0,0,4,local_58);
  return lVar2;
}



===== _tlgKeywordOn @ 1400010c4 =====

undefined1 _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      ((*(ulonglong *)(param_1 + 0x18) & param_2) == *(ulonglong *)(param_1 + 0x18))))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1400010f0 =====

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



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_> @ 140001194 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<8> >(struct _tlgProvider_t const * __ptr64,void const
   * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8>
   const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperByVal<8> *param_8)

{
  long lVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [4];
  _tlgWrapperByVal<8> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<8> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_28 = param_8;
  local_38 = param_7;
  local_48 = param_6;
  local_58 = param_5;
  local_20 = 8;
  local_30 = 4;
  local_40 = 4;
  local_50 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140022000,param_2,0,0,6,local_78);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_> @ 140001230 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<8> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<8> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperByVal<4> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapperByVal<4> *param_10,
          _tlgWrapperByVal<4> *param_11,_tlgWrapperByVal<8> *param_12)

{
  long lVar1;
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [4];
  _tlgWrapperByVal<8> *local_98;
  undefined8 local_90;
  _tlgWrapperByVal<4> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<4> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<8> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_28 = param_12;
  local_38 = param_11;
  local_48 = param_10;
  local_58 = param_9;
  local_68 = param_8;
  local_78 = param_7;
  local_88 = param_6;
  local_98 = param_5;
  local_20 = 8;
  local_30 = 4;
  local_40 = 4;
  local_50 = 4;
  local_60 = 4;
  local_70 = 4;
  local_80 = 4;
  local_90 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140022000,param_2,0,0,10,local_b8);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_> @ 14000130c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<8> >(struct _tlgProvider_t const * __ptr64,void const
   * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8>
   const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperByVal<4> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapperByVal<4> *param_10,
          _tlgWrapperByVal<4> *param_11,_tlgWrapperByVal<4> *param_12,_tlgWrapperByVal<4> *param_13,
          _tlgWrapperByVal<8> *param_14)

{
  long lVar1;
  undefined1 auStackY_108 [32];
  undefined8 local_d8 [4];
  _tlgWrapperByVal<8> *local_b8;
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
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<8> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  local_28 = param_14;
  local_38 = param_13;
  local_48 = param_12;
  local_58 = param_11;
  local_68 = param_10;
  local_78 = param_9;
  local_88 = param_8;
  local_98 = param_7;
  local_a8 = param_6;
  local_b8 = param_5;
  local_20 = 8;
  local_30 = 4;
  local_40 = 4;
  local_50 = 4;
  local_60 = 4;
  local_70 = 4;
  local_80 = 4;
  local_90 = 4;
  local_a0 = 4;
  local_b0 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140022000,param_2,0,0,0xc,local_d8);
  return lVar1;
}



===== ScoChannelRemoteConnect @ 140001410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoChannelRemoteConnect(struct WDFDEVICE__ * __ptr64,void * __ptr64,enum
   _SCO_LINK_TYPE) */

void __cdecl ScoChannelRemoteConnect(WDFDEVICE__ *param_1,void *param_2,_SCO_LINK_TYPE param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  longlong lVar8;
  undefined4 *puVar9;
  char cVar10;
  undefined4 local_88;
  undefined4 local_84;
  undefined **local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined **ppuStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined **local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar10 = '\0';
  }
  else {
    cVar10 = '\x01';
  }
  if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x38,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_2);
  }
  if (*(int *)(lVar8 + 0x178) == 0) {
    local_84 = 1;
    local_88 = 0xc0000010;
    local_80 = &c_scoConfigs_RemoteEsco;
    local_68 = 0xc0000010;
    local_70 = 0;
    ppuStack_60 = &c_scoConfigs_RemoteEscoWbs;
    uStack_50 = 0;
    puVar9 = &local_88;
    if (*(int *)(lVar8 + 0x68) == 2) {
      puVar9 = &local_68;
    }
    local_78 = 1;
    uStack_64 = 2;
    local_58 = 2;
    local_28 = *puVar9;
    uStack_24 = puVar9[1];
    uStack_20 = puVar9[2];
    uStack_1c = puVar9[3];
    local_48 = 0xc0000010;
    local_18 = puVar9[4];
    uStack_14 = puVar9[5];
    uStack_10 = puVar9[6];
    uStack_c = puVar9[7];
    local_40 = &c_scoConfigs_RemoteSco;
    local_30 = 0;
    local_44 = 1;
    local_38 = 1;
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar8 + 0x170));
    *(undefined4 *)(lVar8 + 0x1a4) = 0;
    *(void **)(lVar8 + 400) = param_2;
    *(undefined4 *)(lVar8 + 0x1a0) = 1;
    puVar9 = &local_48;
    if (param_3 == 2) {
      puVar9 = &local_28;
    }
    *(undefined8 *)(lVar8 + 0x198) = 0;
    uVar1 = puVar9[1];
    uVar2 = puVar9[2];
    uVar3 = puVar9[3];
    uVar4 = puVar9[4];
    uVar5 = puVar9[5];
    uVar6 = puVar9[6];
    uVar7 = puVar9[7];
    *(undefined4 *)(lVar8 + 0x1a8) = *puVar9;
    *(undefined4 *)(lVar8 + 0x1ac) = uVar1;
    *(undefined4 *)(lVar8 + 0x1b0) = uVar2;
    *(undefined4 *)(lVar8 + 0x1b4) = uVar3;
    *(undefined4 *)(lVar8 + 0x1b8) = uVar4;
    *(undefined4 *)(lVar8 + 0x1bc) = uVar5;
    *(undefined4 *)(lVar8 + 0x1c0) = uVar6;
    *(undefined4 *)(lVar8 + 0x1c4) = uVar7;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar8 + 0x170));
    SetScoState(lVar8,3);
  }
  return;
}



===== ScoChannelRemoteDisconnect @ 140001618 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoChannelRemoteDisconnect(struct WDFDEVICE__ * __ptr64) */

void __cdecl ScoChannelRemoteDisconnect(WDFDEVICE__ *param_1)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  iVar1 = *(int *)(lVar2 + 0x178);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_SCOSTATE
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffffd0,0x39,
               in_stack_ffffffffffffffe0,(char)iVar1);
  }
  if (iVar1 - 6U < 2) {
    ScoChannelClose(param_1,1);
  }
  return;
}



===== ScoHandleAudioDisconnected @ 1400016d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoHandleAudioDisconnected(WDFDEVICE__ *param_1)

{
  SCOSTATE SVar1;
  _SCOCONTEXT *p_Var2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  p_Var2 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  SVar1 = GetScoState(p_Var2);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_SCOSTATEd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,
               in_stack_ffffffffffffffd0,0x3a,in_stack_ffffffffffffffe0,(char)SVar1,
               (char)*(undefined4 *)(p_Var2 + 0x6c));
  }
  if (SVar1 - 6 < 2) {
    ScoChannelClose(param_1,1);
  }
  if (*(int *)(p_Var2 + 0x6c) != 0) {
    ScoHandleStreamFailure(-0x3fffff63,param_1);
  }
  return;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_> @ 1400017bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6)

{
  long lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
  _tlgWrapperByVal<8> *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  _tlgWrapperByVal<4> *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = param_6;
  local_1c = 0;
  local_20 = 4;
  local_38 = param_5;
  local_2c = 0;
  local_30 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140022000,param_2,0,0,4,local_58);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_> @ 140001844 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>
   >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct
   _GUID const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const
   & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<4> *param_7)

{
  long lVar1;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [4];
  _tlgWrapperByVal<8> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_28 = param_7;
  local_38 = param_6;
  local_48 = param_5;
  local_20 = 4;
  local_30 = 4;
  local_40 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140022000,param_2,0,0,5,local_68);
  return lVar1;
}



===== _tlgCreate1Sz_char @ 1400018e0 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== __report_gsfailure @ 140001920 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000192d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000192d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== out_param<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_> @ 140001940 =====

/* struct wil::details::out_param_t<class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<struct WDFKEY__ * __ptr64,void
   (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct WDFKEY__ * __ptr64,struct WDFKEY__ *
   __ptr64,0,std::nullptr_t> > > > __cdecl wil::out_param<class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<struct WDFKEY__ * __ptr64,void
   (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct WDFKEY__ * __ptr64,struct WDFKEY__ *
   __ptr64,0,std::nullptr_t> > > >(class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct WDFKEY__ * __ptr64,void (__cdecl*)(void * __ptr64),&void
   __cdecl WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,struct WDFKEY__ * __ptr64,struct WDFKEY__ * __ptr64,0,std::nullptr_t> > > & __ptr64)
    */

unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>
* __cdecl wil::
          out_param<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
                    (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>
                     *param_1)

{
  undefined8 in_RDX;
  
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)param_1 = in_RDX;
  param_1[0x10] =
       (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>
        )0x1;
  return param_1;
}



===== ~out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_> @ 140001958 =====

/* public: __cdecl wil::details::out_param_t<class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<struct WDFKEY__ * __ptr64,void
   (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct WDFKEY__ * __ptr64,struct WDFKEY__ *
   __ptr64,0,std::nullptr_t> > > >::~out_param_t<class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<struct WDFKEY__ * __ptr64,void
   (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct WDFKEY__ * __ptr64,struct WDFKEY__ *
   __ptr64,0,std::nullptr_t> > > >(void) __ptr64 */

void __thiscall
wil::details::
out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
::
~out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
          (out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
           *this)

{
  if (this[0x10] !=
      (out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
       )0x0) {
    unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
    ::reset(*(unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
              **)this,*(WDFKEY__ **)(this + 8));
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_> @ 14000197c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct WDFKEY__
   * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct WDFKEY__ * __ptr64,struct WDFKEY__ *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<struct WDFKEY__
   * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct WDFKEY__ * __ptr64,struct WDFKEY__ *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_> @ 1400019b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   WDFWAITLOCK__ * __ptr64,void (__cdecl*)(struct WDFWAITLOCK__ * __ptr64),&void __cdecl
   WdfWaitLockRelease(struct WDFWAITLOCK__ * __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,struct WDFWAITLOCK__ * __ptr64,struct WDFWAITLOCK__ * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<struct WDFWAITLOCK__ * __ptr64,void
   (__cdecl*)(struct WDFWAITLOCK__ * __ptr64),&void __cdecl WdfWaitLockRelease(struct WDFWAITLOCK__
   * __ptr64),struct wistd::integral_constant<unsigned __int64,2>,struct WDFWAITLOCK__ *
   __ptr64,struct WDFWAITLOCK__ * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  return;
}



===== Bus_EvtTimerFuncAudioDisableEnable @ 1400019f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Bus_EvtTimerFuncAudioDisableEnable(struct WDFTIMER__ * __ptr64) */

void __cdecl Bus_EvtTimerFuncAudioDisableEnable(WDFTIMER__ *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  RtlInitUnicodeString(&local_18,*(longlong *)(lVar2 + 0x130) + 2);
  (**(code **)(WdfFunctions_01015 + 0x270))
            (WdfDriverGlobals,uVar1,lVar2 + 0x120,&local_18,*(int *)(lVar2 + 0xf8) == 0);
  if (*(int *)(lVar2 + 0xf8) != 0) {
    *(undefined4 *)(lVar2 + 0xf8) = 0;
    (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,param_1,25000000000);
  }
  return;
}



===== Bus_EvtTimerFuncGainChange @ 140001b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Bus_EvtTimerFuncGainChange(struct WDFTIMER__ * __ptr64) */

void __cdecl Bus_EvtTimerFuncGainChange(WDFTIMER__ *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 local_58;
  undefined4 local_50;
  int local_4c;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  LOCK();
  iVar1 = *(int *)(lVar4 + 0x10c);
  *(int *)(lVar4 + 0x10c) = 0x7fffffff;
  UNLOCK();
  LOCK();
  iVar2 = *(int *)(lVar4 + 0x110);
  *(int *)(lVar4 + 0x110) = 0x7fffffff;
  UNLOCK();
  memset(&local_58,0,0x40);
  LOCK();
  *(undefined4 *)(lVar4 + 0x108) = 0;
  UNLOCK();
  if (iVar1 != 0x7fffffff) {
    local_50 = 5;
    local_4c = iVar1;
    BthRfcommQueueAtResponse(uVar3,&local_58);
  }
  if (iVar2 != 0x7fffffff) {
    local_50 = 6;
    local_4c = iVar2;
    BthRfcommQueueAtResponse(uVar3,&local_58);
  }
  if ((iVar1 != 0x7fffffff) || (iVar2 != 0x7fffffff)) {
    LOCK();
    iVar1 = *(int *)(lVar4 + 0x108);
    *(int *)(lVar4 + 0x108) = 1;
    UNLOCK();
    if (iVar1 == 0) {
      (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,param_1,0xffffffffffd9da60);
    }
  }
  return;
}



===== HfSetEventsIoctlData_EvtCleanupCallback @ 140001c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HfSetEventsIoctlData_EvtCleanupCallback(void * __ptr64) */

void __cdecl HfSetEventsIoctlData_EvtCleanupCallback(void *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_HF_SET_EVENTS_IOCTL_DATA_TYPE_INFO_140022088
                     );
  if (*plVar1 != 0) {
    ObfDereferenceObject();
    *plVar1 = 0;
  }
  if (plVar1[1] != 0) {
    ObfDereferenceObject();
    plVar1[1] = 0;
  }
  return;
}



===== InitializeDisabledRole @ 140001c9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl InitializeDisabledRole(struct WDFDEVICE__ * __ptr64) */

void __cdecl InitializeDisabledRole(WDFDEVICE__ *param_1)

{
  char cVar1;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x20,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  local_34 = 2;
  local_30 = 2;
  local_2c = 2;
  local_20 = 0xffffffff;
  local_1c = 0xffffffff;
  local_48 = 0x30;
  local_44 = 0x200000002;
  uStack_3c = 0x200000002;
  local_28 = 1;
  local_24 = 1;
  (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,param_1,&local_48);
  return;
}



===== InitializeEnabledRole @ 140001da8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl InitializeEnabledRole(struct WDFDEVICE__ * __ptr64) */

long __cdecl InitializeEnabledRole(WDFDEVICE__ *param_1)

{
  _GUID *p_Var1;
  undefined1 uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  char cVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auStackY_188 [32];
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  WDFDEVICE__ *local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 local_100;
  code *pcStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  byte *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 local_8b;
  code *local_70;
  code *local_68;
  undefined4 local_48;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_188;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x21,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  local_128 = 0;
  local_108 = 0;
  uStack_130 = 0;
  local_138 = 0x38;
  uStack_110 = 0;
  uStack_120 = 0x100000001;
  local_118 = param_1;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_ac = 0;
  local_9c = 0;
  local_b0 = 1;
  local_a0 = 0x18;
  local_a8 = (byte *)(lVar4 + 0x2c);
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x20),0,0x410220);
  if (-1 < iVar3) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_138,lVar4 + 0x10);
    if (-1 < iVar3) {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_138,lVar4 + 0x148);
      if (-1 < iVar3) {
        memset(&local_98,0,0x60);
        local_48 = 0xffffffff;
        local_90 = 0;
        local_b8 = 0;
        local_70 = Bus_EvtIoDeviceControl;
        local_98 = 0x60;
        local_68 = Bus_EvtInternalIoDeviceControl;
        local_8b = 1;
        local_94 = 2;
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_1,&local_98,0);
        if (-1 < iVar3) {
          local_e0 = 0;
          uStack_e8 = 0;
          local_100 = 0x28;
          pcStack_f8 = Bus_EvtTimerFuncGainChange;
          local_128 = 0;
          local_108 = 0;
          uStack_130 = 0;
          local_f0 = 0x100000000;
          uStack_110 = 0;
          local_138 = 0x38;
          uStack_120 = 0x100000002;
          local_118 = param_1;
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                            (WdfDriverGlobals,&local_100,&local_138,lVar4 + 0x100);
          if (-1 < iVar3) {
            *(undefined4 *)(lVar4 + 0x10c) = 0x7fffffff;
            *(undefined4 *)(lVar4 + 0x110) = 0x7fffffff;
            local_e0 = 0;
            uStack_e8 = 0;
            pcStack_f8 = Bus_EvtTimerFuncAudioDisableEnable;
            local_128 = 0;
            local_108 = 0;
            uStack_130 = 0;
            local_100 = 0x28;
            uStack_110 = 0;
            local_f0 = 0x100000000;
            local_138 = 0x38;
            uStack_120 = 0x100000002;
            local_118 = param_1;
            iVar3 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                              (WdfDriverGlobals,&local_100,&local_138,lVar4 + 0xf0);
            if (-1 < iVar3) {
              p_Var1 = (_GUID *)(lVar4 + 0x120);
              if ((*(byte *)(lVar4 + 0x2c) & 0x10) == 0) {
                uVar7 = 0x1b97cbf8;
                uVar8 = 0x490e9c1e;
                uVar9 = 0x5fa9a1b7;
                uVar10 = 0xee231eb;
                *(undefined **)(lVar4 + 0x130) = &u__scohci;
              }
              else {
                *(wchar_t **)(lVar4 + 0x130) = L"\\scohcibypass";
                uVar7 = 0xbe446647;
                uVar8 = 0x4919f655;
                uVar9 = 0x5b12d08b;
                uVar10 = 0x65ced4a5;
              }
              *(undefined4 *)p_Var1 = uVar7;
              *(undefined4 *)(lVar4 + 0x124) = uVar8;
              *(undefined4 *)(lVar4 + 0x128) = uVar9;
              *(undefined4 *)(lVar4 + 300) = uVar10;
              local_d8 = 0;
              uStack_d0 = 0;
              RtlInitUnicodeString(&local_d8,*(longlong *)(lVar4 + 0x130) + 2);
              iVar3 = (**(code **)(WdfFunctions_01015 + 0x268))
                                (WdfDriverGlobals,param_1,p_Var1,&local_d8);
              if (-1 < iVar3) {
                iVar3 = WdfHelpers::WdfDeviceCopyDevicePropertyToInterface
                                  (param_1,(_DEVPROPKEY *)&DEVPKEY_Bluetooth_DeviceAddress,p_Var1,
                                   (_UNICODE_STRING *)&local_d8);
                if (-1 < iVar3) {
                  iVar3 = WdfHelpers::WdfDeviceCopyDevicePropertyToInterface
                                    (param_1,(_DEVPROPKEY *)&DEVPKEY_Bluetooth_ServiceGUID,p_Var1,
                                     (_UNICODE_STRING *)&local_d8);
                  if (-1 < iVar3) {
                    local_c8 = 0;
                    uStack_c0 = 0;
                    RtlInitUnicodeString(&local_c8,L"service");
                    iVar3 = (**(code **)(WdfFunctions_01015 + 0x268))
                                      (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_HF_ENUMERATOR,
                                       &local_c8);
                    if (-1 < iVar3) {
                      iVar3 = WdfHelpers::WdfDeviceCopyDevicePropertyToInterface
                                        (param_1,(_DEVPROPKEY *)&DEVPKEY_Bluetooth_ServiceGUID,
                                         (_GUID *)&GUID_DEVINTERFACE_HF_ENUMERATOR,
                                         (_UNICODE_STRING *)&local_c8);
                      if (-1 < iVar3) {
                        iVar3 = WdfHelpers::WdfDeviceCopyDevicePropertyToInterface
                                          (param_1,(_DEVPROPKEY *)&DEVPKEY_Bluetooth_DeviceAddress,
                                           (_GUID *)&GUID_DEVINTERFACE_HF_ENUMERATOR,
                                           (_UNICODE_STRING *)&local_c8);
                        if (-1 < iVar3) {
                          Bus_SetIsConnectedProperty(param_1,0);
                          local_28 = 0xf;
                          local_38 = 0x4e72db9b;
                          uStack_34 = 0x4f6dd9a3;
                          uStack_30 = 0xb4b39d9f;
                          uStack_2c = 0x3f1a94ed;
                          uVar2 = KeAcquireSpinLockRaiseToDpc(&GlobalContext);
                          uVar7 = DAT_140022618;
                          KeReleaseSpinLock(&GlobalContext,uVar2);
                          local_24 = uVar7;
                          (**(code **)(WdfFunctions_01015 + 0x2a8))
                                    (WdfDriverGlobals,param_1,&local_38);
                          iVar3 = Bus_WmiRegistration(param_1);
                          if (-1 < iVar3) {
                            local_108 = 0;
                            local_128 = 0;
                            uStack_130 = 0;
                            local_138 = 0x38;
                            uStack_110 = 0;
                            uStack_120 = 0x100000001;
                            local_118 = param_1;
                            iVar3 = (**(code **)(WdfFunctions_01015 + 0x68))
                                              (WdfDriverGlobals,&local_138,lVar4 + 200);
                            if (-1 < iVar3) {
                              uVar5 = Bus_DoStaticEnumeration(param_1);
                              iVar3 = (int)uVar5;
                              KeInitializeEvent(lVar4 + 0x180,0,0);
                              KeInitializeEvent(lVar4 + 0xd8,0,1);
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
      }
    }
  }
  return iVar3;
}



===== InitializeGlobalContext @ 14000239c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl InitializeGlobalContext(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl InitializeGlobalContext(_DRIVER_OBJECT *param_1)

{
  GlobalContext = 0;
  _DAT_140022618 = 0;
  DAT_140022628 = 0;
  _DAT_140022620 = param_1;
  KeInitializeSpinLock(&GlobalContext);
  _DAT_140022618 = _DAT_140022618 & 0xffffffff00000000;
  DAT_140022628 = 0;
  return;
}



===== reset @ 1400023f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   WDFKEY__ * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct WDFKEY__ * __ptr64,struct
   WDFKEY__ * __ptr64,0,std::nullptr_t> >::reset(struct WDFKEY__ * __ptr64) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
        *this,WDFKEY__ *param_1)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  *(WDFKEY__ **)this = param_1;
  return;
}



===== reset @ 140002438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl wil::wdf_request_completer::reset(struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall wil::wdf_request_completer::reset(wdf_request_completer *this,WDFREQUEST__ *param_1)

{
  longlong lVar1;
  byte bVar2;
  
  lVar1 = *(longlong *)this;
  if (lVar1 != 0) {
    bVar2 = (byte)this[0x15] & 1;
    if (((byte)this[0x15] & 2) == 0) {
      if (bVar2 == 0) {
        (**(code **)(WdfFunctions_01015 + 0x838))
                  (WdfDriverGlobals,lVar1,*(undefined4 *)(this + 0x10));
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x848))();
      }
    }
    else {
      if (bVar2 != 0) {
        (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,lVar1,*(undefined8 *)(this + 8));
      }
      (**(code **)(WdfFunctions_01015 + 0x840))
                (WdfDriverGlobals,*(undefined8 *)this,*(undefined4 *)(this + 0x10),this[0x14]);
    }
  }
  *(undefined8 *)(this + 8) = 0;
  *(undefined2 *)(this + 0x14) = 0;
  *(WDFREQUEST__ **)this = param_1;
  *(undefined4 *)(this + 0x10) = 0xc0000001;
  return;
}



===== Bus_DoStaticEnumeration @ 140002504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Bus_DoStaticEnumeration(undefined8 param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (((*(byte *)(lVar1 + 0x2c) & 0x10) == 0) && ((*(uint *)(lVar1 + 0x28) & 1) == 0)) {
    uVar2 = Bus_PlugInDevice(param_1);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== Bus_EvtDeviceAdd @ 140002570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Bus_EvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  long lVar2;
  ulonglong uVar3;
  void *_Dst;
  undefined8 uVar4;
  char cVar5;
  undefined8 local_res10;
  WDFDEVICE__ *local_res18;
  undefined4 local_108;
  undefined4 local_104;
  code *local_100;
  code *local_f8;
  code *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  code *pcStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined *local_b0;
  undefined4 local_a8 [2];
  code *local_a0;
  code *local_90;
  code *local_80;
  code *local_78;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  local_res10 = param_2;
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x29,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_res10,0x2a);
  local_104 = 0;
  local_d0 = 0;
  local_b0 = (undefined *)0x0;
  pcStack_d8 = (code *)0x0;
  local_e0 = 0x38;
  local_c0 = 0;
  uStack_b8 = 0;
  uStack_c8 = 0x100000001;
  uVar3 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  local_108 = 0x28;
  local_e8 = 2;
  local_100 = Bus_EvtDeviceFileCreate;
  local_f8 = Bus_EvtFileClose;
  if ((int)uVar3 == 0) {
    local_f0 = (code *)0x0;
  }
  else {
    local_f0 = Bus_EvtFileCleanup;
  }
  local_e4 = 0x80000004;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_res10,&local_108,&local_e0);
  memset(local_a8,0,0x90);
  local_a8[0] = 0x90;
  uVar3 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    local_a0 = Bus_EvtDeviceD0Entry;
    local_90 = Bus_EvtDeviceD0Exit;
    local_80 = Bus_EvtDevicePrepareHardware;
    local_78 = Bus_EvtDeviceReleaseHardware;
    local_40 = Bus_EvtDeviceQueryRemove;
  }
  else {
    local_60 = Bus_EvtDeviceSelfManagedIoInit;
    local_58 = Bus_EvtDeviceSelfManagedIoSuspend;
    local_50 = Bus_EvtDeviceSelfManagedIoRestart;
    local_68 = Bus_EvtDeviceSelfManagedIoFlush;
  }
  local_48 = Bus_EvtDeviceSurpriseRemoval;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_res10,local_a8);
  uVar3 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x250))(WdfDriverGlobals,local_res10,Bus_EvtIoInCallerContext)
    ;
  }
  local_d0 = 0;
  local_res18 = (WDFDEVICE__ *)0x0;
  local_b0 = PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0;
  pcStack_d8 = Bus_EvtDeviceCleanup;
  local_c0 = 0;
  uStack_b8 = 0;
  local_e0 = 0x38;
  uStack_c8 = 0x200000002;
  lVar2 = (**(code **)(WdfFunctions_01015 + 600))
                    (WdfDriverGlobals,&local_res10,&local_e0,&local_res18);
  if (-1 < lVar2) {
    _Dst = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,local_res18,
                              PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
    memset(_Dst,0,0x2c0);
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,local_res18);
    *(undefined8 *)((longlong)_Dst + 0x20) = uVar4;
    uVar3 = BthHwGetEnumeratorDeviceInfo(local_res18,(byte *)((longlong)_Dst + 0x1a8));
    lVar2 = (long)uVar3;
    if (-1 < lVar2) {
      lVar2 = DetermineRoleEnablement(local_res18);
      InitializeDeviceFriendlyName(local_res18);
      if ((-1 < lVar2) && (*(int *)((longlong)_Dst + 700) != 0)) {
        lVar2 = InitializeEnabledRole(local_res18);
        goto LAB_1400028c3;
      }
    }
  }
  InitializeDisabledRole(local_res18);
LAB_1400028c3:
  if (lVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x2a,
                 &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)lVar2);
    }
  }
  return lVar2;
}



===== Bus_EvtDeviceCleanup @ 140002960 =====

void Bus_EvtDeviceCleanup(void)

{
  char cVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1e,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  return;
}



===== Bus_EvtDeviceD0Entry @ 1400029e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Bus_EvtDeviceD0Entry(undefined8 param_1,undefined1 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_WDF_POWER_DEVICE_STATEl
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,
               in_stack_ffffffffffffffd0,0x2e,in_stack_ffffffffffffffe0,param_2,
               (char)*(undefined4 *)(lVar1 + 700));
  }
  if (*(int *)(lVar1 + 700) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = BthHwEnterD0(param_1);
  }
  return uVar2;
}



===== Bus_EvtDeviceFileCreate @ 140002ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_EvtDeviceFileCreate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  char cVar8;
  ulonglong uVar9;
  undefined *puVar10;
  undefined7 uVar11;
  longlong local_res8;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  local_38 = (undefined *)0x0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  puVar10 = PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x448))(WdfDriverGlobals,param_3);
  RtlInitUnicodeString(&local_88,L"\\service");
  RtlInitUnicodeString(&local_78);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  uVar11 = (undefined7)((ulonglong)puVar10 >> 8);
  if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_S
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  iVar3 = RtlCompareUnicodeString(uVar6,&local_88,CONCAT71(uVar11,1));
  if (iVar3 == 0) {
    if (*(longlong *)(lVar5 + 0x138) == 0) {
      local_res8 = 0;
      local_38 = PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128;
      local_68 = CONCAT44(local_68._4_4_,0x38);
      uStack_50 = 0x100000001;
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,param_3,&local_68,&local_res8);
      uVar9 = (ulonglong)uVar4;
      if (-1 < (int)uVar4) {
        *(undefined4 *)(lVar5 + 0x158) = 1;
        uVar7 = BthRfcommCreateQueue(param_1,(undefined8 *)(local_res8 + 0x10));
        lVar2 = local_res8;
        uVar9 = uVar7 & 0xffffffff;
        if (-1 < (int)uVar7) {
          uVar4 = BthScoRegisterServer(param_1);
          uVar9 = (ulonglong)uVar4;
        }
        if ((int)uVar9 < 0) {
          BthScoUnRegisterServer(param_1);
          if (*(longlong *)(lVar2 + 0x10) != 0) {
            (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
          }
        }
        else {
          *(undefined8 *)(lVar5 + 0x138) = param_3;
          uVar9 = 0;
        }
      }
      goto LAB_140002c84;
    }
  }
  else {
    iVar3 = RtlCompareUnicodeString(uVar6,&local_78,1);
    if (iVar3 != 0) {
      uVar9 = 0xc000000f;
      goto LAB_140002c84;
    }
    if (*(longlong *)(lVar5 + 0x140) == 0) {
      local_res8 = 0;
      local_38 = DAT_140022100;
      local_68 = CONCAT44(local_68._4_4_,0x38);
      uStack_50 = 0x100000001;
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,param_3,&local_68,&local_res8);
      uVar9 = (ulonglong)uVar4;
      if (-1 < (int)uVar4) {
        *(undefined8 *)(lVar5 + 0x140) = param_3;
      }
      *(undefined4 *)(local_res8 + 0x14) = 1;
      goto LAB_140002c84;
    }
  }
  uVar9 = 0xc0000022;
LAB_140002c84:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x15,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)uVar9);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar9);
  return;
}



===== Bus_EvtDeviceQueryRemove @ 140002e00 =====

void Bus_EvtDeviceQueryRemove(undefined8 param_1)

{
  char cVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x33,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  BthHwUnInitialize(param_1);
  return;
}



===== Bus_EvtDeviceSelfManagedIoFlush @ 140002e90 =====

void Bus_EvtDeviceSelfManagedIoFlush(undefined8 param_1)

{
  char cVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x37,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  BthHwUnInitialize(param_1);
  return;
}



===== Bus_EvtDeviceSelfManagedIoInit @ 140002f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Bus_EvtDeviceSelfManagedIoInit(undefined8 param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  char cVar4;
  uint uVar5;
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_ll
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0x34,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)*(undefined4 *)(lVar1 + 0x1a0)
               ,(char)*(undefined4 *)(lVar1 + 700));
  }
  if (*(int *)(lVar1 + 700) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = BthHwInitialize(param_1);
    if (-1 < (int)uVar2) {
      uVar3 = BthHwEnterD0(param_1);
      uVar5 = 0;
      if ((int)(uint)uVar3 < 0) {
        uVar5 = (uint)uVar3;
      }
      uVar2 = (ulonglong)uVar5;
    }
  }
  return uVar2;
}



===== Bus_EvtDeviceSelfManagedIoRestart @ 140003020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Bus_EvtDeviceSelfManagedIoRestart(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x36,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)*(undefined4 *)(lVar2 + 700));
  }
  if (*(int *)(lVar2 + 700) == 0) {
    iVar1 = 0;
  }
  else {
    uVar3 = BthHwEnterD0(param_1);
    iVar1 = 0;
    if ((int)uVar3 < 0) {
      iVar1 = (int)uVar3;
    }
  }
  return iVar1;
}



===== Bus_EvtDeviceSelfManagedIoSuspend @ 140003110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Bus_EvtDeviceSelfManagedIoSuspend(undefined8 param_1)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x35,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)*(undefined4 *)(lVar1 + 700));
  }
  if (*(int *)(lVar1 + 700) != 0) {
    BthHwExitD0(param_1);
  }
  return 0;
}



===== Bus_EvtDeviceSurpriseRemoval @ 1400031f0 =====

void Bus_EvtDeviceSurpriseRemoval(void)

{
  char cVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x30,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  return;
}



===== Bus_EvtFileCleanup @ 140003270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_EvtFileCleanup(longlong param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  bool bVar7;
  undefined8 local_res10;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined2 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined2 local_2c;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128);
  if (lVar5 != 0) {
    bVar1 = true;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar6 != '\0') || (bVar7)) {
      (**(code **)(WdfFunctions_01015 + 0x460))(WdfDriverGlobals,param_1);
      WPP_RECORDER_AND_TRACE_SF_qqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar3 = *(undefined8 *)(lVar4 + 0x148);
    local_40 = 0;
    local_38 = 0;
    local_2c = 0;
    local_58 = 0;
    local_50 = 0;
    local_44 = 0;
    local_30 = 0xc0000001;
    local_48 = 0xc0000001;
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,uVar3,0);
    local_res10 = uVar3;
    if (*(longlong *)(lVar4 + 0x150) != 0) {
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals);
      if (lVar5 == param_1) {
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
        if (-1 < iVar2) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar6 = '\0';
          }
          else {
            cVar6 = '\x01';
          }
          if ((cVar6 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_q
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x17,
                       &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,
                       (char)*(undefined8 *)(lVar4 + 0x150));
          }
          wil::wdf_request_completer::reset
                    ((wdf_request_completer *)&local_40,*(WDFREQUEST__ **)(lVar4 + 0x150));
          *(undefined8 *)(lVar4 + 0x150) = 0;
          local_30 = 0xc0000120;
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar6 = '\0';
        }
        else {
          cVar6 = '\x01';
        }
        if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_qq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x18,
                     &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)param_1,(char)lVar5);
        }
      }
    }
    if (*(longlong *)(lVar4 + 0x160) != 0) {
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals);
      if (lVar5 == param_1) {
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
        if (-1 < iVar2) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            bVar1 = false;
          }
          if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_q
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x19,
                       &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,
                       (char)*(undefined8 *)(lVar4 + 0x160));
          }
          wil::wdf_request_completer::reset
                    ((wdf_request_completer *)&local_58,*(WDFREQUEST__ **)(lVar4 + 0x160));
          *(undefined8 *)(lVar4 + 0x160) = 0;
          local_48 = 0xc0000120;
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          bVar1 = false;
        }
        if ((bVar1 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_qq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x1a,
                     &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)param_1,(char)lVar5);
        }
      }
    }
    wil::details::
    unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
                *)&local_res10);
    wil::wdf_request_completer::reset((wdf_request_completer *)&local_58,(WDFREQUEST__ *)0x0);
    wil::wdf_request_completer::reset((wdf_request_completer *)&local_40,(WDFREQUEST__ *)0x0);
  }
  return;
}



===== Bus_EvtFileClose @ 1400036f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_EvtFileClose(undefined8 param_1)

{
  bool bVar1;
  WDFDEVICE__ *pWVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  char cVar6;
  
  pWVar2 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,pWVar2,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_140022100);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1b,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  if (plVar4 != (longlong *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1c,
                 &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
    }
    Bus_OnHfConnectionUpdate(pWVar2,0);
    BthScoUnRegisterServer(pWVar2);
    (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,plVar4[2],0,0);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,plVar4[2]);
    if (*plVar4 != 0) {
      ObfDereferenceObject();
    }
    if (plVar4[1] != 0) {
      ObfDereferenceObject();
    }
    *(undefined4 *)(lVar3 + 0xd0) = 0;
    *(undefined8 *)(lVar3 + 0x138) = 0;
  }
  if (lVar5 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1d,
                 &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
    }
    *(undefined8 *)(lVar3 + 0x140) = 0;
  }
  return;
}



===== Bus_EvtIoInCallerContext @ 1400039b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Bus_EvtIoInCallerContext(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined1 auStackY_f8 [32];
  undefined2 uVar7;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  code *local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  longlong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_f8;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_48 = 0x28;
  local_90 = param_1;
  local_88 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_48);
  if ((local_48._4_4_ != 0xe) || ((int)uStack_30 != 0x2a0000)) goto LAB_140003f34;
  local_98 = (undefined8 *)0x0;
  if (local_38 != 0x10) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_PP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    iVar3 = -0x3ffffdfa;
    goto LAB_140003aca;
  }
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x10,&local_98);
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar1 == false) && (!bVar6)) goto LAB_140003aca;
    uVar7 = 0x23;
  }
  else {
    local_7c = 0;
    local_70 = 0;
    local_60 = 0;
    uStack_58 = 0;
    local_80 = 0x38;
    bVar1 = true;
    local_68 = 1;
    local_64 = 1;
    local_50 = PTR__WDF_HF_SET_EVENTS_IOCTL_DATA_TYPE_INFO_140022088;
    local_78 = HfSetEventsIoctlData_EvtCleanupCallback;
    local_a0 = 0;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_2,&local_80,&local_a0);
    if (-1 < iVar3) {
      cVar2 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
      if (cVar2 != '\x01') {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar1 = false;
        }
        if ((bVar1 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x25,
                     &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
        }
        iVar3 = -0x3fffff45;
        goto LAB_140003aca;
      }
      iVar3 = ObReferenceObjectByHandle(*local_98,2,*(undefined8 *)ExEventObjectType_exref,1);
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar1 = false;
        }
        bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar1 != false) || (bVar6)) {
          uVar7 = 0x26;
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
LAB_140003e6c:
          WPP_RECORDER_AND_TRACE_SF_l
                    (uVar4,bVar1,bVar6,uVar5,2,4,uVar7,
                     &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)iVar3);
        }
      }
      else {
        iVar3 = ObReferenceObjectByHandle(local_98[1],2,*(undefined8 *)ExEventObjectType_exref,1);
        if (iVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            bVar1 = false;
          }
          bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((bVar1 != false) || (bVar6)) {
            uVar7 = 0x27;
            uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
            goto LAB_140003e6c;
          }
        }
      }
      if (-1 < iVar3) {
LAB_140003f34:
        (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
        return;
      }
      goto LAB_140003aca;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((!bVar1) && (!bVar6)) goto LAB_140003aca;
    uVar7 = 0x24;
  }
  WPP_RECORDER_AND_TRACE_SF_l
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,bVar6,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar7,
             &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)iVar3);
LAB_140003aca:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
  return;
}



===== Bus_MpmAvdtpSuspendRequest @ 140003f74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Bus_MpmAvdtpSuspendRequest(undefined8 param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (*(longlong *)(lVar1 + 0xb8) == 0) {
    uVar2 = 0xc00000c0;
  }
  else {
    uVar2 = BtaMpmSuspendRequest(*(longlong *)(lVar1 + 0xb8),2,param_2);
  }
  return uVar2;
}



===== Bus_MpmConnectionRequestCallback @ 140003fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Bus_MpmConnectionRequestCallback(undefined8 param_1,int param_2)

{
  longlong lVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,param_1);
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  LOCK();
  *(int *)(lVar1 + 0xb4) = *(int *)(lVar1 + 0xb4) + 1;
  UNLOCK();
  if (param_2 == 0) {
    RfcommDisconnect(param_1);
  }
  else {
    RfcommStartConnect(param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,param_1);
  return 0;
}



===== Bus_MpmSuspendRequestCallback @ 140004080 =====

undefined8 Bus_MpmSuspendRequestCallback(void)

{
  return 0;
}



===== Bus_MpmSuspendStatusCallback @ 140004090 =====

undefined8 Bus_MpmSuspendStatusCallback(undefined8 param_1,int param_2)

{
  ScoMpmSuspendStatusCallback(param_1,param_2);
  return 0;
}



===== Feature_53100197__private_IsEnabledDeviceUsageNoInline @ 1400040a8 =====

ulonglong Feature_53100197__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_53100197__private_featureState;
  if ((Feature_53100197__private_featureState & 0x10) == 0) {
    uVar1 = Feature_53100197__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_53100197__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_53100197__private_IsEnabledFallback @ 1400040e0 =====

void Feature_53100197__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_53100197__private_descriptor);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_ @ 1400040fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_PP @ 140004180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_PP(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000050;
  undefined8 local_18 [2];
  
  local_18[0] = 0x10;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0x22,local_18,8,
               &uStack0000000000000050,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,4,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0x22,local_18,8,
                    &uStack0000000000000050,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_S @ 140004250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_S(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

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
              (param_1,0x2b,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0x14,pwVar2,lVar1,0);
  }
  if (param_3 != '\0') {
    if (in_stack_00000048 != (wchar_t *)0x0) {
      do {
        lVar4 = lVar4 + 1;
      } while (in_stack_00000048[lVar4] != L'\0');
      lVar3 = lVar4 * 2 + 2;
    }
    if (in_stack_00000048 == (wchar_t *)0x0) {
      in_stack_00000048 = L"NULL";
    }
    WppAutoLogTrace(param_4,4,4,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0x14,
                    in_stack_00000048,lVar3,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_WDF_POWER_DEVICE_STATEl @ 14000436c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_WDF_POWER_DEVICE_STATEl
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,param_7,&param_9,4,
               &param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,4,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,param_7,&param_9,4,
                    &param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF__guid_ @ 140004438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF__guid_
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined8 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,param_9,0x10,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,param_9,0x10,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF__guid_d @ 1400044f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF__guid_d
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0xb);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,4,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0xb);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF__guid_ld @ 1400045c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF__guid_ld
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0x10);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,5,4,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0x10);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF__guid_ll @ 1400046b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF__guid_ll
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0xd);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,5,4,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0xd);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_l @ 1400047b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_l
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



===== WPP_RECORDER_AND_TRACE_SF_ll @ 140004864 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_ll
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,param_6,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_q @ 140004938 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_q
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qIOCTL_BTHHFP @ 1400049ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qIOCTL_BTHHFP
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,param_7,&param_9,8,
               &param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,4,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,param_7,
                    &param_9,8,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qq @ 140004ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,8,&param_10,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqq @ 140004ba4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqq(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0x16,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,4,&WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,0x16,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,8,0)
    ;
  }
  return;
}



===== WppClassicProviderCallback @ 140004c90 =====

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



===== _tlgDefineProvider_annotation__Tlgg_hHfEnumProviderProv @ 140004cec =====

void _tlgDefineProvider_annotation__Tlgg_hHfEnumProviderProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140004cf8 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140021397 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140004d20 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140004e04 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140004ef4 =====

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
LAB_140005050:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140005040:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140005050;
      if (uVar5 == 5) goto LAB_140005040;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140005078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400050fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400051ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400052fc =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140005360 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 1400054c0 =====

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



===== wil_details_MapReportingKind @ 140005554 =====

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



===== wil_details_RecordCachedUsage @ 1400055f4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005740 =====

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



===== BusPdo_InterfaceDereference @ 1400057d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BusPdo_InterfaceDereference(void * __ptr64) */

void __cdecl BusPdo_InterfaceDereference(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  LOCK();
  piVar1 = (int *)(lVar5 + 0xc0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    RfcommDisconnect(uVar3);
  }
  LOCK();
  piVar1 = (int *)(lVar4 + 0x38);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *(undefined8 *)(lVar4 + 0x40) = 0;
    *(undefined8 *)(lVar4 + 0x48) = 0;
    *(undefined8 *)(lVar4 + 0x50) = 0;
    *(undefined8 *)(lVar4 + 0x58) = 0;
    *(undefined8 *)(lVar4 + 0x60) = 0;
    *(undefined8 *)(lVar4 + 0x68) = 0;
  }
  return;
}



===== BusPdo_InterfaceReference @ 1400058a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BusPdo_InterfaceReference(void * __ptr64) */

void __cdecl BusPdo_InterfaceReference(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
  LOCK();
  *(int *)(lVar4 + 0x38) = *(int *)(lVar4 + 0x38) + 1;
  UNLOCK();
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  LOCK();
  piVar1 = (int *)(lVar4 + 0xc0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 == 0) {
    RfcommStartConnect(uVar3);
  }
  return;
}



===== BusPdo_EvtDeviceProcessQueryInterfaceRequest @ 140005950 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
BusPdo_EvtDeviceProcessQueryInterfaceRequest
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  *(code **)(param_3 + 4) = BusPdo_InterfaceReference;
  *(code **)(param_3 + 6) = BusPdo_InterfaceDereference;
  *(undefined8 *)(param_3 + 2) = param_1;
  *param_3 = 0x10098;
  *(undefined8 *)(lVar2 + 0x40) = *(undefined8 *)(param_3 + 8);
  *(undefined8 *)(lVar2 + 0x48) = *(undefined8 *)(param_3 + 10);
  *(undefined8 *)(lVar2 + 0x50) = *(undefined8 *)(param_3 + 0xc);
  *(undefined8 *)(lVar2 + 0x58) = *(undefined8 *)(param_3 + 0xe);
  *(undefined8 *)(lVar2 + 0x60) = *(undefined8 *)(param_3 + 0x10);
  *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(param_3 + 0x12);
  *(undefined8 *)(param_3 + 0x14) = *(undefined8 *)(lVar3 + 0xd0);
  *(code **)(param_3 + 0x16) = BusPdo_AtResponse;
  *(code **)(param_3 + 0x18) = BusRfcommAttemptSlcReconnect;
  *(code **)(param_3 + 0x1a) = BusRfcommAttemptSlcDisconnect;
  *(undefined8 *)(param_3 + 0x1c) = *(undefined8 *)(lVar3 + 0x68);
  *(undefined8 *)(param_3 + 0x1e) = *(undefined8 *)(lVar3 + 0x70);
  *(undefined8 *)(param_3 + 0x20) = *(undefined8 *)(lVar3 + 0x78);
  *(undefined8 *)(param_3 + 0x22) = *(undefined8 *)(lVar3 + 0x80);
  *(undefined8 *)(param_3 + 0x24) = *(undefined8 *)(lVar3 + 0x88);
  return 0;
}



===== RtlUnicodeStringPrintf @ 140005aac =====

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



===== BrbRequest_EvtCleanupCallback @ 140005b50 =====

/* void __cdecl BrbRequest_EvtCleanupCallback(void * __ptr64) */

void __cdecl BrbRequest_EvtCleanupCallback(void *param_1)

{
  return;
}



===== Bus_AudioPDOInternalIoDeviceControl @ 140005b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Bus_AudioPDOInternalIoDeviceControl(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__
   * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
Bus_AudioPDOInternalIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStack_58 [48];
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
  local_20 = 0;
  local_28 = 0x10;
  local_24 = 8;
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(lVar4 + 8),&local_28);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2);
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  }
  return;
}



===== Bus_AudioPDOIoDeviceControl @ 140005c60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Bus_AudioPDOIoDeviceControl(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
Bus_AudioPDOIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = 8;
  local_14 = 1;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,uVar2);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,uVar2);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xc58))(WdfDriverGlobals,param_2,uVar2,&local_18);
  if (iVar1 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  }
  return;
}



===== BrbMemory_EvtCleanupCallback @ 140005d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BrbMemory_EvtCleanupCallback(void * __ptr64) */

void __cdecl BrbMemory_EvtCleanupCallback(void *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BRB_MEMORY_CONTEXT_TYPE_INFO_140022378);
  if (plVar1[1] != 0) {
    (**(code **)(*plVar1 + 0x28))();
  }
  return;
}



===== BypassIoctlSetXxxVolume @ 140005d7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl BypassIoctlSetXxxVolume(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,long * __ptr64,long * __ptr64,long * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
BypassIoctlSetXxxVolume
          (WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,long *param_3,long *param_4,long *param_5,
          __uint64 *param_6)

{
  longlong lVar1;
  int iVar2;
  char cVar3;
  int *local_18 [2];
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_18[0] = (int *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_18,0);
  if (-1 < iVar2) {
    iVar2 = *local_18[0];
    if (iVar2 < -0x3f7fff) {
      iVar2 = -0x3f8000;
    }
    else if (-1 < iVar2) {
      iVar2 = 0;
    }
    *param_3 = iVar2;
    *param_4 = iVar2;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x28,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)*param_3);
    }
    LOCK();
    *param_5 = *param_3;
    UNLOCK();
    LOCK();
    iVar2 = *(int *)(lVar1 + 0x108);
    *(int *)(lVar1 + 0x108) = 1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x100),0);
    }
    *param_6 = 0;
    iVar2 = 0;
  }
  return iVar2;
}



===== CompleteAudioDeviceGetCodecIdRequest @ 140005ef8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CompleteAudioDeviceGetCodecIdRequest(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  undefined1 *local_res18;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3a,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)param_2);
  }
  local_res18 = (undefined1 *)0x0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1,1,&local_res18,0);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x3b,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc000000d);
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_140022100);
    *local_res18 = (char)param_2;
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,0,1);
    *(undefined4 *)(lVar3 + 0x14) = param_2;
  }
  return;
}



===== CompleteServiceAGCapabilitiesRequest @ 1400060d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CompleteServiceAGCapabilitiesRequest(undefined8 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined4 *local_res18;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3c,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)param_2);
  }
  local_res18 = (undefined4 *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1,4,&local_res18,0);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x3d,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar2);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc000000d);
  }
  else {
    *local_res18 = param_2;
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,0,4);
  }
  return;
}



===== EvtAudioDriverRequestCancel @ 140006280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtAudioDriverRequestCancel(struct WDFREQUEST__ * __ptr64) */

void __cdecl EvtAudioDriverRequestCancel(WDFREQUEST__ *param_1)

{
  bool bVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x43,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,uVar2);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148),0);
  if (param_1 == *(WDFREQUEST__ **)(lVar3 + 0x170)) {
    *(undefined8 *)(lVar3 + 0x170) = 0;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x44,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148));
  return;
}



===== EvtServiceRequestCancel @ 140006460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtServiceRequestCancel(struct WDFREQUEST__ * __ptr64) */

void __cdecl EvtServiceRequestCancel(WDFREQUEST__ *param_1)

{
  bool bVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x45,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,uVar2);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148),0);
  if (param_1 == *(WDFREQUEST__ **)(lVar3 + 0x150)) {
    *(undefined8 *)(lVar3 + 0x150) = 0;
  }
  else if (param_1 == *(WDFREQUEST__ **)(lVar3 + 0x160)) {
    *(undefined8 *)(lVar3 + 0x160) = 0;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x46,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148));
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
  return;
}



===== GetKsNodeTypesForRoleAndCOD @ 140006654 =====

/* void __cdecl GetKsNodeTypesForRoleAndCOD(int,unsigned long,struct _GUID * __ptr64,struct _GUID *
   __ptr64) */

void __cdecl GetKsNodeTypesForRoleAndCOD(int param_1,ulong param_2,_GUID *param_3,_GUID *param_4)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined **ppuVar4;
  char cVar5;
  uint uVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  if (param_1 == 0) {
    uVar8 = _GUID_4770e2da_b374_410b_aaec_98e6f8d345d9._0_4_;
    uVar9 = _GUID_4770e2da_b374_410b_aaec_98e6f8d345d9._4_4_;
    uVar10 = _GUID_4770e2da_b374_410b_aaec_98e6f8d345d9._8_4_;
    uVar11 = _GUID_4770e2da_b374_410b_aaec_98e6f8d345d9._12_4_;
    *(GUID *)param_3 = _GUID_33e19f10_a8c0_40a9_9351_0e0b752787dd;
  }
  else {
    uVar3 = param_2 >> 8 & 0x1f;
    uVar6 = param_2 >> 2 & 0x3f;
    if (8 < uVar3) {
      uVar3 = 9;
    }
    lVar7 = (ulonglong)uVar3 * 0x20;
    if (uVar6 < *(uint *)(&DAT_14001d1d8 + lVar7)) {
      ppuVar4 = (undefined **)((ulonglong)uVar6 * 0x10 + *(longlong *)(&DAT_14001d1d0 + lVar7));
    }
    else {
      ppuVar4 = &PTR__GUID_dff21de2_f70f_11d0_b917_00a0c9223196_14001d1e0 + (ulonglong)uVar3 * 4;
    }
    uVar2 = *(undefined8 *)((longlong)ppuVar4[1] + 8);
    *(undefined8 *)param_3 = *(undefined8 *)ppuVar4[1];
    *(undefined8 *)(param_3 + 8) = uVar2;
    puVar1 = (undefined4 *)*ppuVar4;
    uVar8 = *puVar1;
    uVar9 = puVar1[1];
    uVar10 = puVar1[2];
    uVar11 = puVar1[3];
  }
  *(undefined4 *)param_4 = uVar8;
  *(undefined4 *)(param_4 + 4) = uVar9;
  *(undefined4 *)(param_4 + 8) = uVar10;
  *(undefined4 *)(param_4 + 0xc) = uVar11;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar5 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l_guid__guid_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== WdfIoTargetFormatRequestForBrb @ 140006734 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl WdfIoTargetFormatRequestForBrb(struct WDFIOTARGET__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,struct _BTH_PROFILE_DRIVER_INTERFACE * __ptr64,struct _BRB * __ptr64) */

long __cdecl
WdfIoTargetFormatRequestForBrb
          (WDFIOTARGET__ *param_1,WDFREQUEST__ *param_2,_BTH_PROFILE_DRIVER_INTERFACE *param_3,
          _BRB *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  longlong local_res10;
  undefined4 local_68;
  undefined4 local_64;
  code *local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  WDFREQUEST__ *local_48;
  undefined8 local_40;
  undefined *local_38;
  
  local_res10 = 0;
  local_64 = 0;
  local_58 = 0;
  local_40 = 0;
  local_50 = 1;
  local_4c = 1;
  local_38 = PTR__WDF_BRB_MEMORY_CONTEXT_TYPE_INFO_140022378;
  local_60 = BrbMemory_EvtCleanupCallback;
  local_68 = 0x38;
  local_48 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x608))
                    (WdfDriverGlobals,&local_68,param_4,*(undefined4 *)(param_4 + 0x10),&local_res10
                    );
  if (-1 < iVar1) {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res10,PTR__WDF_BRB_MEMORY_CONTEXT_TYPE_INFO_140022378
                       );
    puVar2[1] = 0;
    *puVar2 = param_3;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,param_1,param_2,0x410003,local_res10,0,0,0,0,0);
    if (-1 < iVar1) {
      puVar2[1] = param_4;
      local_res10 = 0;
    }
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== BthIntIoctlGetDeviceInformation @ 1400068ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthIntIoctlGetDeviceInformation(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined8 *local_res20;
  undefined8 local_18 [2];
  
  local_res20 = (undefined8 *)0x0;
  local_18[0] = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_2,0x118,&local_res20,local_18);
  if (-1 < iVar5) {
    lVar9 = 2;
    puVar2 = local_res20;
    puVar3 = (undefined8 *)(lVar6 + 0x1a8);
    do {
      puVar8 = puVar3;
      puVar7 = puVar2;
      uVar1 = puVar8[1];
      *puVar7 = *puVar8;
      puVar7[1] = uVar1;
      uVar1 = puVar8[3];
      puVar7[2] = puVar8[2];
      puVar7[3] = uVar1;
      uVar1 = puVar8[5];
      puVar7[4] = puVar8[4];
      puVar7[5] = uVar1;
      uVar1 = puVar8[7];
      puVar7[6] = puVar8[6];
      puVar7[7] = uVar1;
      uVar1 = puVar8[9];
      puVar7[8] = puVar8[8];
      puVar7[9] = uVar1;
      uVar1 = puVar8[0xb];
      puVar7[10] = puVar8[10];
      puVar7[0xb] = uVar1;
      uVar1 = puVar8[0xd];
      puVar7[0xc] = puVar8[0xc];
      puVar7[0xd] = uVar1;
      uVar1 = puVar8[0xf];
      puVar7[0xe] = puVar8[0xe];
      puVar7[0xf] = uVar1;
      lVar9 = lVar9 + -1;
      puVar2 = puVar7 + 0x10;
      puVar3 = puVar8 + 0x10;
    } while (lVar9 != 0);
    uVar1 = puVar8[0x11];
    puVar7[0x10] = puVar8[0x10];
    puVar7[0x11] = uVar1;
    if (*(int *)(lVar6 + 0x1a0) == 0) {
      uVar4 = *(undefined2 *)(lVar6 + 0x2b8);
    }
    else {
      uVar4 = *(undefined2 *)(lVar6 + 0x2ba);
    }
    *(undefined2 *)(local_res20 + 0x22) = uVar4;
    *param_3 = 0x118;
  }
  return iVar5;
}



===== BthIoctlAtCommand @ 1400069dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthIoctlAtCommand(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong lVar5;
  int iVar6;
  int local_res18 [2];
  int *local_res20;
  undefined8 in_stack_ffffffffffffff80;
  undefined8 local_78;
  int local_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  undefined8 local_60;
  undefined8 uStack_58;
  int local_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined8 local_40;
  
  local_res20 = (int *)0x0;
  local_78 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,0x38,&local_res20,&local_78);
  if (iVar1 < 0) goto LAB_140006c6a;
  lVar5 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  iVar6 = *local_res20;
  iStack_6c = local_res20[1];
  iStack_68 = local_res20[2];
  iStack_64 = local_res20[3];
  local_60 = *(undefined8 *)(local_res20 + 4);
  uStack_58 = *(undefined8 *)(local_res20 + 6);
  local_50 = local_res20[8];
  iStack_4c = local_res20[9];
  iStack_48 = local_res20[10];
  iStack_44 = local_res20[0xb];
  local_40 = *(undefined8 *)(local_res20 + 0xc);
  local_70 = iVar6;
  if (iVar6 == 0xb) {
    local_res18[0] = (int)((ulonglong)*(undefined8 *)local_res20 >> 0x20);
    LOCK();
    *(undefined4 *)(lVar2 + 0x10c) = 0x7fffffff;
    UNLOCK();
    *(int *)(lVar2 + 0x114) = local_res18[0];
    if (*(longlong *)(lVar2 + 0x140) != 0) {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*(longlong *)(lVar2 + 0x140),DAT_140022100);
      puVar4 = (undefined4 *)(lVar3 + 8);
      iVar6 = 0x22001f;
LAB_140006b45:
      WdfIoQueueFindAndCompleteStatusIoctlRequest
                (*(undefined8 *)(lVar2 + 0x98),*(undefined8 *)(lVar2 + 0x140),iVar6,local_res18,
                 puVar4,in_stack_ffffffffffffff80);
    }
LAB_140006b61:
    iVar6 = local_70;
  }
  else {
    if (iVar6 == 10) {
      LOCK();
      *(undefined4 *)(lVar2 + 0x110) = 0x7fffffff;
      UNLOCK();
      *(int *)(lVar2 + 0x118) = iStack_6c;
      local_res18[0] = iStack_6c;
      if (*(longlong *)(lVar2 + 0x140) != 0) {
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*(longlong *)(lVar2 + 0x140),DAT_140022100);
        puVar4 = (undefined4 *)(lVar3 + 0xc);
        iVar6 = 0x220027;
        goto LAB_140006b45;
      }
      goto LAB_140006b61;
    }
    if (iVar6 == 7) {
      *(undefined4 *)(lVar2 + 0x11c) = 1;
      if (*(longlong *)(lVar2 + 0x140) != 0) {
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*(longlong *)(lVar2 + 0x140),DAT_140022100);
        WdfIoQueueFindAndCompleteStatusIoctlRequest
                  (*(undefined8 *)(lVar2 + 0x98),*(undefined8 *)(lVar2 + 0x140),0x22003b,
                   (undefined4 *)(lVar2 + 0x11c),(undefined4 *)(lVar3 + 4),in_stack_ffffffffffffff80
                  );
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
  while( true ) {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,lVar5,1);
    if (lVar5 == 0) break;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar5,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
    if (*(code **)(lVar2 + 0x58) != (code *)0x0) {
      (**(code **)(lVar2 + 0x58))(*(undefined8 *)(lVar2 + 0x40),iVar6,local_res20,local_78);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
LAB_140006c6a:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return iVar1;
}



===== BthIoctlAtResponse @ 140006cac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthIoctlAtResponse(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  char cVar5;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x12,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(lVar4 + 0x10));
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x13,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar2);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  }
  else {
    Bus_ProcessAtResponses(param_1);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      bVar1 = false;
    }
    if ((bVar1 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x14,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar2);
    }
  }
  return iVar2;
}



===== BthIoctlCloseSco @ 140006ebc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BthIoctlCloseSco(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(lVar2 + 0x60));
  if (iVar1 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  }
  else {
    uVar3 = 0;
    iVar1 = ScoChannelClose(param_1,0);
    if (iVar1 < 0) {
      WdfIoQueueFindAndCompleteIoctlRequest(*(undefined8 *)(lVar2 + 0x60),uVar3,0x2a002c,iVar1);
    }
  }
  return;
}



===== BthIoctlOpenSco @ 140006f78 =====

void BthIoctlOpenSco(undefined8 param_1,undefined8 param_2)

{
  ScoConnectionRequest(param_1,param_2);
  return;
}



===== BthIoctlSetCodec @ 140006f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BthIoctlSetCodec(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  int *local_res18;
  
  local_res18 = (int *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1c,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,&local_res18,0);
  if (-1 < iVar1) {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
    iVar2 = *local_res18;
    if ((iVar2 < 3) && (iVar2 != 0)) {
      ScoSetCodecId(param_1,iVar2);
    }
    else {
      iVar1 = -0x3ffffff3;
    }
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148),0);
    *(undefined4 *)(lVar3 + 0x178) = 0;
    if ((-1 < iVar1) && (*(longlong *)(lVar3 + 0x170) != 0)) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
      if (iVar2 != -0x3ffffee0) {
        CompleteAudioDeviceGetCodecIdRequest(*(undefined8 *)(lVar3 + 0x170),*local_res18);
      }
      *(undefined8 *)(lVar3 + 0x170) = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148));
    KeSetEvent(lVar3 + 0x180,0,0);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== BthIoctlSetServiceEvents @ 140007184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BthIoctlSetServiceEvents(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong *plVar4;
  undefined7 extraout_var;
  longlong lVar5;
  char cVar6;
  
  plVar2 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_HF_SET_EVENTS_IOCTL_DATA_TYPE_INFO_140022088
                     );
  if (plVar2 == (longlong *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x15,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
    MicrosoftTelemetryAssertTriggeredMsgKM
              ("IOCTL_BUSENUM_SET_EVENT_HANDLES does not have request context set.");
    uVar3 = 0xc0000010;
  }
  else if ((*plVar2 == 0) || (plVar2[1] == 0)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2))))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x16,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
    MicrosoftTelemetryAssertTriggeredMsgKM
              ("IOCTL_BUSENUM_SET_EVENT_HANDLES handles were not referenced.");
    uVar3 = 0xc000000d;
  }
  else {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    plVar4 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,uVar3,PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128);
    if (*plVar4 != 0) {
      ObfDereferenceObject();
      *plVar4 = 0;
    }
    if (plVar4[1] != 0) {
      ObfDereferenceObject();
      plVar4[1] = 0;
    }
    *plVar4 = *plVar2;
    *plVar2 = 0;
    plVar4[1] = plVar2[1];
    plVar2[1] = 0;
    bVar1 = Bus_IsAutoConnectionDisabled();
    if ((int)CONCAT71(extraout_var,bVar1) == 0) {
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x148),0);
      if (*(longlong *)(lVar5 + 0xb8) != 0) {
        BtaMpmConnectionRequest(*(longlong *)(lVar5 + 0xb8),1,1);
      }
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x148));
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x17,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== BthIoctlSetServiceEventsOld @ 140007498 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthIoctlSetServiceEventsOld(undefined8 param_1,undefined8 param_2)

{
  longlong *plVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined7 extraout_var;
  char cVar7;
  undefined8 *local_res18;
  undefined8 local_res20;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals);
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar4,PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128);
  local_res20 = 0;
  local_res18 = (undefined8 *)0x0;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,0x10,&local_res18,&local_res20);
  if (-1 < iVar3) {
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    if (*plVar5 != 0) {
      ObfDereferenceObject();
      *plVar5 = 0;
    }
    plVar1 = plVar5 + 1;
    if (*plVar1 != 0) {
      ObfDereferenceObject();
      *plVar1 = 0;
    }
    iVar3 = ObReferenceObjectByHandle
                      (*local_res18,2,*(undefined8 *)ExEventObjectType_exref,
                       *(undefined1 *)(lVar6 + 0x40),plVar5,0);
    if (-1 < iVar3) {
      iVar3 = ObReferenceObjectByHandle
                        (local_res18[1],2,*(undefined8 *)ExEventObjectType_exref,
                         *(undefined1 *)(lVar6 + 0x40),plVar1,0);
      if ((iVar3 < 0) && (*plVar5 != 0)) {
        ObfDereferenceObject();
        *plVar5 = 0;
      }
    }
    if (-1 < iVar3) {
      bVar2 = Bus_IsAutoConnectionDisabled();
      if ((int)CONCAT71(extraout_var,bVar2) == 0) {
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x148),0)
        ;
        if (*(longlong *)(lVar6 + 0xb8) != 0) {
          BtaMpmConnectionRequest(*(longlong *)(lVar6 + 0xb8),1,1);
        }
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x148));
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar7 = '\0';
        }
        else {
          cVar7 = '\x01';
        }
        if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x18,
                     &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
        }
      }
    }
  }
  return iVar3;
}



===== BthIoctlSlcStatus @ 140007778 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthIoctlSlcStatus(WDFDEVICE__ *param_1,undefined8 param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  undefined7 extraout_var;
  longlong lVar6;
  longlong lVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  char local_res18 [8];
  uint *local_res20;
  undefined8 *puVar13;
  undefined4 uVar14;
  undefined4 in_stack_ffffffffffffff80;
  undefined4 in_stack_ffffffffffffff84;
  undefined8 local_48 [2];
  
  local_res20 = (uint *)0x0;
  local_48[0] = 0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  puVar13 = local_48;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_res20,puVar13)
  ;
  if (iVar4 < 0) goto LAB_140007af8;
  iVar11 = 2;
  lVar6 = 0;
  if ((2 < *local_res20) && (*local_res20 != 5)) {
    iVar4 = -0x3fffff45;
    goto LAB_140007af8;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar12 = '\0';
  }
  if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qRFCOMM_CONNECTION_STATUSq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  *(undefined8 *)(lVar5 + 0xd0) = *(undefined8 *)local_res20;
  uVar1 = *local_res20;
  if ((uVar1 == 0) || ((uVar1 != 1 && (uVar1 != 2)))) {
    bVar2 = false;
LAB_1400078d4:
    iVar10 = 0;
  }
  else {
    bVar2 = true;
    if (*(longlong *)(lVar5 + 0x160) == 0) goto LAB_1400078d4;
    iVar10 = 1;
  }
  Bus_OnHfConnectionUpdate(param_1,iVar10);
  (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
  bVar3 = Bus_IsDeviceConnected(param_1);
  while( true ) {
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,lVar6,1);
    uVar14 = (undefined4)((ulonglong)puVar13 >> 0x20);
    iVar10 = (int)CONCAT71(extraout_var,bVar3);
    if (lVar6 == 0) break;
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar6,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
    if (iVar10 == 0) {
      if (*(code **)(lVar7 + 0x50) != (code *)0x0) {
        (**(code **)(lVar7 + 0x50))(*(undefined8 *)(lVar7 + 0x40));
      }
    }
    else if (*(code **)(lVar7 + 0x48) != (code *)0x0) {
      (**(code **)(lVar7 + 0x48))(*(undefined8 *)(lVar7 + 0x40),local_res20[1]);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
  if (iVar10 != 0) {
    *(undefined4 *)(lVar5 + 0x11c) = 0;
    if (*(longlong *)(lVar5 + 0x140) != 0) {
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*(longlong *)(lVar5 + 0x140),DAT_140022100);
      puVar8 = (undefined4 *)(lVar6 + 4);
      WdfIoQueueFindAndCompleteStatusIoctlRequest
                (*(undefined8 *)(lVar5 + 0x98),*(undefined8 *)(lVar5 + 0x140),0x22003b,
                 (undefined4 *)(lVar5 + 0x11c),puVar8,
                 CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80));
      uVar14 = (undefined4)((ulonglong)puVar8 >> 0x20);
    }
    if (*(int *)(lVar5 + 0xb0) != 0) {
      if ((*(int *)(lVar5 + 0x1a0) == 0) || ((local_res20[1] & 0x10) != 0)) {
        iVar11 = 1;
      }
      if (iVar11 != *(int *)(lVar5 + 0xb0)) {
        *(int *)(lVar5 + 0xb0) = iVar11;
        local_res18[0] = (iVar11 != 1) + -1;
        uVar9 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        IoSetDevicePropertyData
                  (uVar9,&DEVPKEY_Bthhfenum_SupportsRemoteVolume,0,1,CONCAT44(uVar14,0x11),1,
                   local_res18);
        *(undefined4 *)(lVar5 + 0xf8) = 1;
        (**(code **)(WdfFunctions_01015 + 0x9f8))
                  (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0xf0),0xffffffffffd9da60);
      }
    }
  }
  if (!bVar2) {
    ScoHandleAudioDisconnected(param_1);
  }
LAB_140007af8:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar4);
  return iVar4;
}



===== BypassIoctlGetConnectionStatusUpdate @ 140007b3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BypassIoctlGetConnectionStatusUpdate(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  char cVar4;
  uint local_res18 [2];
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  puVar3 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_140022100);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x26,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  local_res18[0] = (uint)(*(int *)(lVar1 + 0xd0) - 1U < 2);
  WdfRequestCompleteOrForwardStatusIoctlRequest
            (param_2,*(undefined8 *)(lVar1 + 0x98),0x220017,local_res18,puVar3);
  return;
}



===== BypassIoctlGetContainerId @ 140007c7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BypassIoctlGetContainerId(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 local_res20 [2];
  undefined4 uVar3;
  undefined4 local_18 [2];
  undefined8 local_10;
  
  local_10 = 0;
  local_res20[0] = 0;
  local_18[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1e,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  uVar3 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x10,&local_10,0);
  if (-1 < (int)uVar1) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
    uVar1 = IoGetDevicePropertyData
                      (uVar1,&DEVPKEY_Device_ContainerId,0,0,CONCAT44(uVar3,0x10),local_10,local_18,
                       local_res20);
    if (-1 < (int)uVar1) {
      *param_3 = 0x10;
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== BypassIoctlGetDescriptor @ 140007dc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BypassIoctlGetDescriptor(WDFDEVICE__ *param_1,undefined8 param_2,ulonglong *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  char cVar7;
  uint uVar8;
  undefined1 auStackY_f8 [32];
  ushort local_a8 [2];
  undefined4 local_a4;
  undefined4 local_a0;
  ulonglong local_98;
  longlong local_90;
  longlong local_88;
  undefined4 *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_a4 = 0;
  local_a0 = 0;
  local_80 = (undefined4 *)0x0;
  local_98 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_88 = 0;
  local_90 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x21,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0,&local_80);
  uVar8 = 0xc0000023;
  if ((((int)uVar5 + 0x80000000U & 0x80000000) != 0) || ((int)uVar5 == -0x3fffffdd)) {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
    uVar5 = IoGetDevicePropertyData(uVar4,&DEVPKEY_Device_ContainerId,0,0);
    if (-1 < (int)uVar5) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar7 = '\0';
      }
      if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF__guid_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x22,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,&local_78);
      }
      GetKsNodeTypesForRoleAndCOD
                (*(int *)(lVar3 + 0x1a0),*(ulong *)(lVar3 + 0x1b8),(_GUID *)&local_68,
                 (_GUID *)&local_58);
      if ((*(uint *)(lVar3 + 0x1a8) & 4) != 0) {
        iVar1 = *(int *)(lVar3 + 0x1a0);
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
        BtaMpmBuildIndirectStringFromMessageWithSingleUTF8Arg
                  (*(undefined8 *)(lVar6 + 0x18),(-(uint)(iVar1 != 0) & 0xfffffffe) + 4,
                   L"@System32\\drivers\\bthhfenum.sys",lVar3 + 0x1bc);
      }
      puVar2 = local_80;
      uVar5 = local_90 + 0x52;
      if (uVar5 <= local_98) {
        local_a8[0] = 0;
        *(undefined8 *)(local_80 + 8) = local_78;
        *(undefined8 *)(local_80 + 10) = uStack_70;
        *local_80 = (undefined4)local_68;
        local_80[1] = local_68._4_4_;
        local_80[2] = (undefined4)uStack_60;
        local_80[3] = uStack_60._4_4_;
        local_80[4] = (undefined4)local_58;
        local_80[5] = local_58._4_4_;
        local_80[6] = (undefined4)uStack_50;
        local_80[7] = uStack_50._4_4_;
        iVar1 = *(int *)(lVar3 + 0xb0);
        local_80[0xd] = 0x50;
        local_80[0xc] = (uint)(iVar1 == 1);
        RtlInitUnicodeString(local_80 + 0xe,0);
        if (local_88 != 0) {
          RtlStringCbCopyW((short *)(puVar2 + 0x14),local_98 - 0x50,local_88);
          RtlInitUnicodeString(puVar2 + 0xe,puVar2 + 0x14);
        }
        ScoStreamGetSDPRecordSupportedFeatures(param_1,local_a8);
        uVar8 = 0;
        puVar2[0x12] = local_a8[0] & 1;
        uVar5 = local_90 + 0x52;
      }
      *param_3 = uVar5;
      if (local_88 != 0) {
        ExFreePoolWithTag(local_88,0x46485442);
      }
      uVar5 = (ulonglong)uVar8;
    }
  }
  return uVar5;
}



===== BypassIoctlGetKsNodeTypes @ 14000815c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BypassIoctlGetKsNodeTypes(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  _GUID *local_res20;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_res20 = (_GUID *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x20,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x20,&local_res20,0);
  if (-1 < (int)uVar2) {
    GetKsNodeTypesForRoleAndCOD
              (*(int *)(lVar1 + 0x1a0),*(ulong *)(lVar1 + 0x1b8),local_res20 + 0x10,local_res20);
    uVar2 = 0;
    *param_3 = 0x20;
  }
  return uVar2;
}



===== BypassIoctlGetMicVolumeStatusUpdate @ 140008284 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BypassIoctlGetMicVolumeStatusUpdate(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_140022100);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2c,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  WdfRequestCompleteOrForwardStatusIoctlRequest
            (param_2,*(undefined8 *)(lVar1 + 0x98),0x220027,(undefined4 *)(lVar1 + 0x118),
             (undefined4 *)(lVar3 + 0xc));
  return;
}



===== BypassIoctlGetNrecDisableStatusUpdate @ 1400083b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BypassIoctlGetNrecDisableStatusUpdate(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_140022100);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x27,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  WdfRequestCompleteOrForwardStatusIoctlRequest
            (param_2,*(undefined8 *)(lVar1 + 0x98),0x22003b,(undefined4 *)(lVar1 + 0x11c),
             (undefined4 *)(lVar3 + 4));
  return;
}



===== BypassIoctlGetSpeakerVolumeStatusUpdate @ 1400084dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BypassIoctlGetSpeakerVolumeStatusUpdate(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2,DAT_140022100);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_dd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2b,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)*(undefined4 *)(lVar3 + 8),
               (char)*(undefined4 *)(lVar1 + 0x114));
  }
  WdfRequestCompleteOrForwardStatusIoctlRequest
            (param_2,*(undefined8 *)(lVar1 + 0x98),0x22001f,(undefined4 *)(lVar1 + 0x114),
             (undefined4 *)(lVar3 + 8));
  return;
}



===== BypassIoctlGetVolumePropertyValues @ 140008618 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
BypassIoctlGetVolumePropertyValues(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x23,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x50,&local_res8,0);
  uVar2 = uRam0000000140022318;
  uVar1 = _VolumeValuesBlock;
  if (-1 < (int)uVar3) {
    *param_3 = 0x50;
    *local_res8 = uVar1;
    local_res8[1] = uVar2;
    uVar1 = uRam0000000140022328;
    local_res8[2] = _DAT_140022320;
    local_res8[3] = uVar1;
    uVar1 = _DAT_140022338;
    local_res8[4] = PTR_DAT_140022330;
    local_res8[5] = uVar1;
    uVar1 = uRam0000000140022348;
    local_res8[6] = _DAT_140022340;
    local_res8[7] = uVar1;
    uVar1 = uRam0000000140022358;
    local_res8[8] = _DAT_140022350;
    local_res8[9] = uVar1;
    local_res8[4] = local_res8 + 5;
    local_res8[7] = local_res8 + 8;
    uVar3 = 0;
  }
  return uVar3;
}



===== BypassIoctlRequestConnect @ 140008744 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BypassIoctlRequestConnect(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x24,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x148),0);
  if (*(longlong *)(lVar1 + 0xb8) != 0) {
    BtaMpmConnectionRequest(*(longlong *)(lVar1 + 0xb8),1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x148));
  *param_3 = 0;
  return 0;
}



===== BypassIoctlRequestDisconnect @ 140008878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BypassIoctlRequestDisconnect(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x25,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x148),0);
  if (*(longlong *)(lVar1 + 0xb8) != 0) {
    BtaMpmConnectionRequest(*(longlong *)(lVar1 + 0xb8),0,0);
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x148));
  *param_3 = 0;
  return 0;
}



===== BypassIoctlSetMicVolume @ 1400089ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BypassIoctlSetMicVolume(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x140),DAT_140022100);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2a,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  BypassIoctlSetXxxVolume
            (param_1,param_2,(long *)(lVar1 + 0x118),(long *)(lVar2 + 0xc),(long *)(lVar1 + 0x110),
             param_3);
  return;
}



===== BypassIoctlSetSpeakerVolume @ 140008adc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BypassIoctlSetSpeakerVolume(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x140),DAT_140022100);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x29,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  BypassIoctlSetXxxVolume
            (param_1,param_2,(long *)(lVar1 + 0x114),(long *)(lVar2 + 8),(long *)(lVar1 + 0x10c),
             param_3);
  return;
}



===== HandleAudioDeviceCapabilitiesIndication @ 140008c0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleAudioDeviceCapabilitiesIndication(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  char cVar7;
  undefined4 uVar8;
  int *local_res18;
  longlong local_res20;
  
  local_res18 = (int *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,&local_res18,0);
  uVar8 = 1;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2d,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2e,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar2);
    }
  }
  else if (*local_res18 == 1) {
    local_res20 = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_res20,0);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2f,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar2);
      }
    }
    else {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar4,DAT_140022100);
      uVar1 = *(undefined4 *)(local_res20 + 4);
      *(undefined4 *)(lVar5 + 0x18) = uVar1;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x30,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)uVar1);
      }
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x148),0);
      if (*(longlong *)(lVar6 + 0x150) != 0) {
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
        if (iVar3 != -0x3ffffee0) {
          if (((*(int *)(lVar6 + 0x168) == 0) || (*(int *)(lVar5 + 0x18) == 0)) ||
             (*(int *)(lVar6 + 0x16c) != 0)) {
            uVar8 = 0;
          }
          CompleteServiceAGCapabilitiesRequest(*(undefined8 *)(lVar6 + 0x150),uVar8);
          uVar8 = 0;
        }
        *(undefined8 *)(lVar6 + 0x150) = 0;
      }
      *(undefined4 *)(lVar6 + 0x158) = uVar8;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x148));
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x31,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  return;
}



===== HandleAudioDeviceGetCodecId @ 140009020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleAudioDeviceGetCodecId(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  undefined7 extraout_var;
  longlong lVar4;
  char cVar5;
  char cVar6;
  bool bVar7;
  int *local_res18 [2];
  undefined2 uVar8;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_res18[0] = (int *)0x0;
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x32,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_res18,0);
  if ((iVar2 < 0) || (*local_res18[0] != 1)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 ||
        (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)))) {
      cVar5 = '\0';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x33,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
    goto LAB_140009507;
  }
  iVar2 = -0x3ffffff0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148),0);
  if (*(longlong *)(lVar3 + 0x170) == 0) {
    bVar7 = Bus_IsDeviceConnected(param_1);
    if ((int)CONCAT71(extraout_var,bVar7) == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
         (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
        cVar5 = '\0';
      }
      bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar5 != '\0') || (bVar7)) {
        uVar8 = 0x35;
        goto LAB_140009218;
      }
    }
    else {
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
      if (*(int *)(lVar4 + 0x68) == 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x36,
                     &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
        }
        *(undefined8 *)(lVar3 + 0x170) = param_2;
        (**(code **)(WdfFunctions_01015 + 0xc48))
                  (WdfDriverGlobals,param_2,EvtAudioDriverRequestCancel);
        if (*(longlong *)(lVar3 + 0x160) == 0) {
LAB_14000940b:
          if (*(int *)(lVar3 + 0x178) == 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
               (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar5 = '\0';
            }
            if ((cVar5 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_l
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x38,
                         &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0);
            }
          }
        }
        else if (*(int *)(lVar3 + 0x178) == 0) {
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
          if (iVar2 != -0x3ffffee0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
               (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
              cVar5 = '\0';
            }
            if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
               (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
              cVar6 = '\0';
            }
            if ((cVar5 != '\0') || (cVar6 != '\0')) {
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x37,
                         &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
            }
            (**(code **)(WdfFunctions_01015 + 0x838))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x160),0);
            *(undefined8 *)(lVar3 + 0x160) = 0;
            *(undefined4 *)(lVar3 + 0x178) = 1;
          }
          goto LAB_14000940b;
        }
        iVar2 = 0x103;
      }
      else {
        lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
        CompleteAudioDeviceGetCodecIdRequest(param_2,*(undefined4 *)(lVar4 + 0x68));
        iVar2 = 0;
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar5 = '\0';
    }
    bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 != '\0') || (bVar7)) {
      uVar8 = 0x34;
LAB_140009218:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar7,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,uVar8,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148));
LAB_140009507:
  if (iVar2 < 0) {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x140),DAT_140022100);
    *(undefined4 *)(lVar3 + 0x14) = 1;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x39,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar2);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  }
  return;
}



===== HandleAudioDriverScoClose @ 1400095e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleAudioDriverScoClose(undefined8 param_1,ulonglong param_2)

{
  bool bVar1;
  undefined4 uVar2;
  longlong lVar3;
  char cVar4;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4d,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  if (*(int *)(lVar3 + 0x1a0) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4e,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
    uVar2 = ScoSetStreamingModeForHf(param_1,0);
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  }
  else {
    ScoStreamCloseRequest(param_1,param_2);
  }
  return;
}



===== HandleAudioDriverScoOpen @ 14000978c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleAudioDriverScoOpen(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  char cVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4b,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (*(int *)(lVar2 + 0x1a0) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4c,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
    uVar1 = ScoSetStreamingModeForHf(param_1,1);
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar1);
  }
  else {
    ScoStreamOpenRequest(param_1,param_2);
  }
  return;
}



===== HandleServiceAGCapabilitiesIndicationRequest @ 140009904 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleServiceAGCapabilitiesIndicationRequest(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  
  cVar5 = '\x01';
  uVar6 = 1;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3e,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x148),0);
  if (*(int *)(lVar2 + 0x158) == 0) {
    if (*(longlong *)(lVar2 + 0x150) == 0) {
      *(undefined8 *)(lVar2 + 0x150) = param_2;
      (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_2,EvtServiceRequestCancel);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)
         ) {
        cVar5 = '\0';
      }
      if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x3f,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
    }
    goto LAB_140009afe;
  }
  if (*(longlong *)(lVar2 + 0x140) == 0) {
LAB_140009a1d:
    bVar1 = false;
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(lVar2 + 0x140),DAT_140022100);
    if (*(int *)(lVar3 + 0x18) == 0) goto LAB_140009a1d;
    bVar1 = true;
  }
  if (((*(int *)(lVar2 + 0x168) == 0) || (!bVar1)) || (*(int *)(lVar2 + 0x16c) != 0)) {
    uVar6 = 0;
  }
  CompleteServiceAGCapabilitiesRequest(param_2,uVar6);
  *(undefined4 *)(lVar2 + 0x158) = 0;
LAB_140009afe:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x148));
  return;
}



===== HandleServiceCodecNegotiationIndicationRequest @ 140009b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleServiceCodecNegotiationIndicationRequest(WDFDEVICE__ *param_1,undefined8 param_2)

{
  int iVar1;
  bool bVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  char cVar6;
  
  bVar2 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x40,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  iVar5 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148),0);
  if (*(longlong *)(lVar3 + 0x160) == 0) {
    iVar1 = *(int *)(lVar3 + 0xd0);
    if ((iVar1 != 0) && ((iVar1 == 1 || (iVar1 == 2)))) {
      iVar5 = 1;
    }
    if ((*(longlong *)(lVar3 + 0x170) == 0) || (*(int *)(lVar3 + 0x178) != 0)) {
      *(undefined8 *)(lVar3 + 0x160) = param_2;
      (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_2,EvtServiceRequestCancel);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar4 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar6 = '\0';
      }
      if ((cVar4 != '\0') || (cVar6 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar6,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x42,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
      *(undefined4 *)(lVar3 + 0x178) = 1;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      bVar2 = false;
    }
    if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x41,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148));
  Bus_OnHfConnectionUpdate(param_1,iVar5);
  return;
}



===== HandleSetDevPKey @ 140009e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleSetDevPKey(WDFDEVICE__ *param_1,undefined8 param_2)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *local_res18;
  ulonglong local_res20;
  undefined8 local_38;
  int *piStack_30;
  undefined8 local_28;
  
  local_res18 = (int *)0x0;
  local_res20 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,0x28,&local_res18,&local_res20);
  if (-1 < iVar1) {
    if (local_res20 < *(longlong *)(local_res18 + 8) + 0x28U) {
      iVar1 = -0x3fffffdd;
    }
    else {
      if (*(longlong *)(local_res18 + 8) == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = local_res18 + 10;
      }
      if (*local_res18 == 0) {
        piStack_30 = local_res18 + 1;
        local_28 = 0;
        local_38 = 0x18;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0xd98))
                          (WdfDriverGlobals,param_1,&local_38,local_res18[6],local_res18[8],piVar3);
      }
      else {
        local_38 = 0;
        piStack_30 = (int *)0x0;
        RtlInitUnicodeString(&local_38,L"service");
        iVar1 = WdfHelpers::WdfDeviceSetPropertyToDeviceInterface
                          (param_1,(_GUID *)&GUID_DEVINTERFACE_HF_ENUMERATOR,
                           (_UNICODE_STRING *)&local_38,(_DEVPROPKEY *)(local_res18 + 1),
                           local_res18[6],*(__uint64 *)(local_res18 + 8),piVar3);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x4f,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== IoctlGetDeviceObject @ 140009fcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 IoctlGetDeviceObject(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  char cVar2;
  undefined8 *local_res20;
  
  local_res20 = (undefined8 *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1d,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,8,&local_res20,0);
  if (-1 < (int)uVar1) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
    *local_res20 = uVar1;
    ObfReferenceObject(uVar1);
    uVar1 = 0;
    *param_3 = 8;
  }
  return uVar1;
}



===== NegotiateAndValidateCodec @ 14000a0e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool NegotiateAndValidateCodec(undefined8 param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  char cVar7;
  char cVar8;
  bool bVar9;
  undefined8 local_res10;
  
  bVar9 = false;
  bVar2 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x47,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  KeResetEvent(lVar4 + 0x180);
  local_res10 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x148),0);
  if (*(longlong *)(lVar4 + 0x160) != 0) {
    if (*(int *)(lVar4 + 0x178) != 0) goto LAB_14000a32c;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
    if (iVar3 != -0x3ffffee0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar7 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar8 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar8 = '\0';
      }
      if ((cVar7 != '\0') || (cVar8 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x48,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x160),0);
      local_res10 = 0xfffffffffe8287c0;
      *(undefined8 *)(lVar4 + 0x160) = 0;
      *(undefined4 *)(lVar4 + 0x178) = 1;
    }
  }
  if (*(int *)(lVar4 + 0x178) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar7 = '\0';
    }
    if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x49,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
  }
LAB_14000a32c:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x148));
  iVar3 = KeWaitForSingleObject(lVar4 + 0x180,0,0,0,&local_res10);
  if ((-1 < iVar3) && (*(longlong *)(lVar4 + 0x140) != 0)) {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(lVar4 + 0x140),DAT_140022100);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x148),0);
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 4))))
    {
      bVar2 = false;
    }
    bVar9 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar2) || (bVar9)) {
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
      WPP_RECORDER_AND_TRACE_SF_dd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,bVar9,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4a,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,
                 (char)*(undefined4 *)(lVar5 + 0x14),(char)*(undefined4 *)(lVar6 + 0x68));
    }
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
    iVar3 = *(int *)(lVar5 + 0x14);
    iVar1 = *(int *)(lVar6 + 0x68);
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x148));
    bVar9 = iVar3 == iVar1;
  }
  return bVar9;
}



===== RtlStringCbCopyW @ 14000a4f0 =====

uint RtlStringCbCopyW(short *param_1,ulonglong param_2,longlong param_3)

{
  short sVar1;
  short *psVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  
  uVar3 = param_2 >> 1;
  if (0x7ffffffe < uVar3 - 1) {
    if (uVar3 != 0) {
      *param_1 = 0;
    }
    return 0xc000000d;
  }
  lVar4 = 0x7ffffffe - uVar3;
  lVar5 = param_3 - (longlong)param_1;
  do {
    if ((lVar4 + uVar3 == 0) || (sVar1 = *(short *)(lVar5 + (longlong)param_1), sVar1 == 0)) break;
    *param_1 = sVar1;
    param_1 = param_1 + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  psVar2 = param_1 + -1;
  if (uVar3 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(uVar3 != 0) & 0x80000005;
}



===== WPP_RECORDER_AND_TRACE_SF_DD @ 14000a564 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DD(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0x19,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,3,&WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0x19,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_dd @ 14000a630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_dd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_l_guid__guid_ @ 14000a70c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_l_guid__guid_
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0x1f,
               &uStack0000000000000048,4);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0x1f,
                    &uStack0000000000000048,4);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qIOCTL_BTHHFPd @ 14000a804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qIOCTL_BTHHFPd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0x11,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,4,&WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0x11,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qRFCOMM_CONNECTION_STATUSq @ 14000a8f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qRFCOMM_CONNECTION_STATUSq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0x1b,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,3,&WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,0x1b,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0)
    ;
  }
  return;
}



===== WdfIoQueueFindAndCompleteIoctlRequest @ 14000a9f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WdfIoQueueFindAndCompleteIoctlRequest
              (undefined8 param_1,undefined8 param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined8 local_res10;
  
  local_res10 = 0;
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xf,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
  }
  iVar2 = WdfIoQueueFindIoctlRequest(param_1,0,param_3,&local_res10);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x10,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)param_3);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      bVar1 = false;
    }
    if ((bVar1 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qIOCTL_BTHHFPd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,local_res10,param_4,0);
    iVar2 = 0;
  }
  return iVar2;
}



===== WdfIoQueueFindAndCompleteStatusIoctlRequest @ 14000abac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WdfIoQueueFindAndCompleteStatusIoctlRequest
              (undefined8 param_1,undefined8 param_2,int param_3,undefined4 *param_4,
              undefined4 *param_5,undefined8 param_6)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  char cVar4;
  undefined4 *local_38 [2];
  
  param_6 = 0;
  local_38[0] = (undefined4 *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,10,
               &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)param_3);
  }
  lVar2 = RtlCompareMemory(param_4,param_5,4);
  if (lVar2 == 4) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)param_3);
    }
  }
  else {
    iVar1 = WdfIoQueueFindIoctlRequest(param_1,param_2,param_3,&param_6);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar3 = '\0';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar1);
      }
      goto LAB_14000af0a;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar3 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (cVar4 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar4 = '\0';
    }
    if ((cVar3 != '\0') || (cVar4 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xd,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)param_6);
    }
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_6,4,local_38,0);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar3 = '\0';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xe,
                   &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids,(char)iVar1);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_6,iVar1);
      goto LAB_14000af0a;
    }
    *param_5 = *param_4;
    *local_38[0] = *param_4;
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_6,0,4);
  }
  iVar1 = 0;
LAB_14000af0a:
  return iVar1;
}



===== WdfIoQueueFindIoctlRequest @ 14000af30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
WdfIoQueueFindIoctlRequest(undefined8 param_1,undefined8 param_2,int param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_b8 [32];
  longlong *local_98;
  longlong *local_90;
  longlong local_78 [4];
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
LAB_14000af6e:
  do {
    local_78[0] = 0;
    do {
      lVar1 = local_78[0];
      local_90 = local_78;
      local_50 = 0;
      local_78[2] = 0;
      local_78[1] = 0x28;
      local_98 = local_78 + 1;
      local_78[3] = 0;
      uStack_58 = 0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x500))
                        (WdfDriverGlobals,param_1,local_78[0],param_2);
      if (lVar1 != 0) {
        local_98 = (longlong *)0x14001dbd0;
        (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,lVar1,0,0xdc);
      }
      if (iVar2 == -0x7fffffe6) {
        return 0xc0000001;
      }
      if (iVar2 == -0x3ffffddb) goto LAB_14000af6e;
      if (iVar2 < 0) {
        return 0xc0000001;
      }
    } while (param_3 != (int)uStack_58);
    if (param_4 == (undefined8 *)0x0) {
      local_98 = (longlong *)0x14001dbd0;
      (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,local_78[0],0,0xfa);
      return 0;
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x508))(WdfDriverGlobals,param_1,local_78[0],param_4);
    local_98 = (longlong *)0x14001dbd0;
    (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,local_78[0],0,0x106);
    if (iVar2 != -0x3ffffddb) {
      uVar3 = 0;
      if (iVar2 < 0) {
        uVar3 = 0xc0000001;
      }
      return uVar3;
    }
  } while( true );
}



===== WdfIoTargetCreateAndFormatRequestForBrb @ 14000b10c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WdfIoTargetCreateAndFormatRequestForBrb
              (undefined8 param_1,WDFIOTARGET__ *param_2,_BTH_PROFILE_DRIVER_INTERFACE *param_3,
              _BRB *param_4,undefined8 *param_5)

{
  WDFREQUEST__ *pWVar1;
  long lVar2;
  WDFREQUEST__ *local_18 [2];
  
  local_18[0] = (WDFREQUEST__ *)0x0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,param_1,param_2,local_18);
  if (-1 < lVar2) {
    lVar2 = WdfIoTargetFormatRequestForBrb(param_2,local_18[0],param_3,param_4);
    pWVar1 = local_18[0];
    if (-1 < lVar2) {
      local_18[0] = (WDFREQUEST__ *)0x0;
      *param_5 = pWVar1;
    }
  }
  if (local_18[0] != (WDFREQUEST__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return lVar2;
}



===== WdfRequestCompleteOrForwardStatusIoctlRequest @ 14000b1cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdfRequestCompleteOrForwardStatusIoctlRequest
               (undefined8 param_1,undefined8 param_2,int param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  longlong lVar4;
  int *local_28;
  undefined4 *local_20;
  
  local_28 = (int *)0x0;
  local_20 = (undefined4 *)0x0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_1,4,&local_28,0);
  if (iVar1 < 0) {
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1,4,&local_20,0);
    if (-1 < iVar1) {
      if (*local_28 != 0) {
LAB_14000b348:
        *param_5 = *param_4;
        *local_20 = *param_4;
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,0,4);
        return;
      }
      iVar1 = WdfIoQueueFindIoctlRequest(param_2,uVar2,param_3,(undefined8 *)0x0);
      if (-1 < iVar1) {
        iVar1 = -0x7fffffef;
        pcVar3 = *(code **)(WdfFunctions_01015 + 0x838);
        goto LAB_14000b268;
      }
      if ((*local_28 != 0) || (lVar4 = RtlCompareMemory(param_4,param_5,4), lVar4 != 4))
      goto LAB_14000b348;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_1,param_2);
      if (-1 < iVar1) {
        return;
      }
    }
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x838);
  }
LAB_14000b268:
  (*pcVar3)(WdfDriverGlobals,param_1,iVar1);
  return;
}



===== BthHwEnterActiveMode @ 14000b3a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BthHwEnterActiveMode(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  _BRB *p_Var3;
  char cVar4;
  undefined1 auStackY_78 [32];
  longlong local_28 [4];
  
  local_28[3] = __security_cookie ^ (ulonglong)auStackY_78;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  p_Var3 = (_BRB *)(**(code **)(lVar2 + 0x68))(0x301,0x46485442);
  if (p_Var3 != (_BRB *)0x0) {
    *(undefined8 *)(p_Var3 + 0x70) = *(undefined8 *)(lVar2 + 0x1b0);
    iVar1 = WdfIoTargetCreateAndFormatRequestForBrb
                      (0,*(WDFIOTARGET__ **)(lVar2 + 0x20),
                       (_BTH_PROFILE_DRIVER_INTERFACE *)(lVar2 + 0x48),p_Var3,local_28);
    if (-1 < iVar1) {
      p_Var3 = (_BRB *)0x0;
      local_28[1] = 0x300000010;
      local_28[2] = 0xfffffffffd050f80;
      (**(code **)(WdfFunctions_01015 + 0x7e8))
                (WdfDriverGlobals,local_28[0],*(undefined8 *)(lVar2 + 0x20),local_28 + 1);
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals);
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar4 = '\0';
        }
        else {
          cVar4 = '\x01';
        }
        if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_l
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xb,
                     &WPP_a5a394aa8e7a34ed6d5d67bd4b27ab0e_Traceguids,(char)iVar1);
        }
      }
    }
    if (local_28[0] != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_28[0]);
    }
    if (p_Var3 != (_BRB *)0x0) {
      (**(code **)(lVar2 + 0x70))(p_Var3);
    }
  }
  return;
}



===== BthHwEnterD0 @ 14000b574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BthHwEnterD0(undefined8 param_1)

{
  bool bVar1;
  undefined7 extraout_var;
  longlong lVar2;
  char cVar3;
  
  bVar1 = Bus_IsAutoConnectionDisabled();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x148),0);
    if ((*(longlong *)(lVar2 + 0x138) != 0) && (*(longlong *)(lVar2 + 0xb8) != 0)) {
      BtaMpmConnectionRequest(*(longlong *)(lVar2 + 0xb8),1,1);
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x148));
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xe,
                 &WPP_a5a394aa8e7a34ed6d5d67bd4b27ab0e_Traceguids);
    }
  }
  return 0;
}



===== BthHwExitD0 @ 14000b6a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BthHwExitD0(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  undefined8 local_res10 [3];
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  Bus_MpmConnectionRequestCallback(param_1,0);
  local_res10[0] = 0xffffffffff676980;
  iVar1 = KeWaitForSingleObject(lVar2 + 0xd8,0,0,0,local_res10);
  if (iVar1 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0xf,
                 &WPP_a5a394aa8e7a34ed6d5d67bd4b27ab0e_Traceguids,(char)iVar1);
    }
  }
  return;
}



===== BthHwSendBrbSync @ 14000b7a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void BthHwSendBrbSync(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  longlong lVar1;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 *local_50;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  local_38 = 1;
  local_48 = 0;
  local_24 = 0;
  local_1c = 1;
  local_50 = &local_20;
  local_68 = &local_38;
  local_58 = 0;
  local_60 = 0;
  local_20 = 0x10;
  local_18 = 0xfffffffffd050f80;
  local_30 = param_2;
  local_28 = param_3;
  (**(code **)(WdfFunctions_01015 + 0x5f0))
            (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20),0,0x410003);
  return;
}



===== BthHwSleepstudyRegister @ 14000b888 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BthHwSleepstudyRegister
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined1 auStackY_c8 [32];
  ushort local_98 [4];
  longlong local_90;
  ushort local_88 [4];
  longlong local_80;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_48 = 0;
  uStack_40 = 0;
  lVar3 = ExAllocatePool2(0x40,0x100,0x46485442);
  lVar4 = ExAllocatePool2(0x40,0x200,0x46485442);
  local_98[0] = 0;
  local_98[1] = 0x100;
  local_98[2] = 0;
  local_98[3] = 0;
  local_88[0] = 0;
  local_88[1] = 0x200;
  local_88[2] = 0;
  local_88[3] = 0;
  local_90 = lVar3;
  local_80 = lVar4;
  if ((lVar3 == 0) || (lVar4 == 0)) {
    uVar8 = 0xc000009a;
    if (lVar3 == 0) goto LAB_14000ba3d;
  }
  else if (DAT_140022628 == (undefined *)0x0) {
    uVar8 = 0xc000000d;
  }
  else {
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
    uVar6 = SleepstudyHelper_GetPdoFriendlyName(uVar5,local_98);
    uVar8 = uVar6 & 0xffffffff;
    if (-1 < (int)uVar6) {
      uVar6 = RtlUnicodeStringPrintf(local_88,L"%wZ (HFP Hands Free)",local_98,param_4);
      uVar8 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        uVar5 = WdfDriverGlobals;
        uVar7 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        uVar1 = SleepstudyHelper_GenerateGuid(uVar5,uVar7,&local_48);
        uVar8 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_68 = local_48;
          uStack_60 = uStack_40;
          local_58 = 0x447a730f703feb1b;
          uStack_50 = 0xfa9d1cba3a3e91ae;
          uVar8 = SleepstudyHelper_RegisterComponentEx
                            (DAT_140022628,(undefined4 *)&local_58,(undefined4 *)&local_68,local_88,
                             (undefined8 *)(lVar2 + 0x198));
          uVar8 = uVar8 & 0xffffffff;
        }
      }
    }
  }
  ExFreePoolWithTag(lVar3,0x46485442);
LAB_14000ba3d:
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x46485442);
  }
  return uVar8;
}



===== BthHwUnInitialize @ 14000ba8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 BthHwUnInitialize(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  uVar2 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (*(undefined **)(lVar4 + 0x198) != (undefined *)0x0) {
    SleepstudyHelper_UnregisterComponent(*(undefined **)(lVar4 + 0x198));
    *(undefined8 *)(lVar4 + 0x198) = 0;
  }
  if (*(longlong *)(lVar3 + 0x148) != 0) {
    lVar4 = 0;
    lVar5 = 0;
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(longlong *)(lVar3 + 0x148),0);
    if (*(longlong *)(lVar3 + 0x150) != 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
      if (iVar1 != -0x3ffffee0) {
        lVar4 = *(longlong *)(lVar3 + 0x150);
        *(undefined8 *)(lVar3 + 0x150) = 0;
      }
    }
    if (*(longlong *)(lVar3 + 0x160) != 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
      if (iVar1 != -0x3ffffee0) {
        lVar5 = *(longlong *)(lVar3 + 0x160);
        *(undefined8 *)(lVar3 + 0x160) = 0;
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148));
    if (lVar4 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar4,0xc0000120);
    }
    if (lVar5 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar5,0xc0000120);
    }
  }
  ScoCleanup(param_1);
  if (*(longlong *)(lVar3 + 0x148) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(longlong *)(lVar3 + 0x148),0);
    uVar2 = 0;
    if (*(longlong *)(lVar3 + 0xb8) != 0) {
      *(undefined8 *)(lVar3 + 0xb8) = 0;
      uVar2 = BtaMpmUnregister();
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148));
  }
  return uVar2;
}



===== WPP_RECORDER_AND_TRACE_SF_iLll @ 14000bcc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_iLll(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_a5a394aa8e7a34ed6d5d67bd4b27ab0e_Traceguids,0xc,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,4,&WPP_a5a394aa8e7a34ed6d5d67bd4b27ab0e_Traceguids,0xc,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_lIil @ 14000bdd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_lIil(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_a5a394aa8e7a34ed6d5d67bd4b27ab0e_Traceguids,0xd,
               &uStack0000000000000048,4,&uStack0000000000000050,8,&uStack0000000000000058,8,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,4,&WPP_a5a394aa8e7a34ed6d5d67bd4b27ab0e_Traceguids,0xd,
                    &uStack0000000000000048,4,&uStack0000000000000050,8,&uStack0000000000000058,8,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== BthRfcommCreateQueue @ 14000bee8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BthRfcommCreateQueue(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 local_res10 [3];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c [84];
  
  *param_2 = 0;
  local_res10[0] = 0;
  memset(local_5c,0,0x54);
  local_60 = 0;
  local_68 = 0x60;
  local_64 = 3;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,param_1,&local_68,0,local_res10);
  if (-1 < (int)uVar1) {
    *param_2 = local_res10[0];
    uVar1 = 0;
  }
  return uVar1;
}



===== BthRfcommQueueAtResponse @ 14000bf88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthRfcommQueueAtResponse(undefined8 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 *local_res18;
  undefined8 local_res20;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res20 = 0;
  local_res18 = (undefined8 *)0x0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_28 = 0;
  local_48 = 0;
  uStack_50 = 0;
  uStack_40 = 0x100000001;
  uStack_30 = 0;
  local_58 = 0x38;
  local_38 = *(undefined8 *)(lVar5 + 200);
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_58,0x200,0,0x40,&local_res20,&local_res18);
  if (-1 < iVar4) {
    uVar6 = param_2[1];
    *local_res18 = *param_2;
    local_res18[1] = uVar6;
    uVar6 = param_2[3];
    local_res18[2] = param_2[2];
    local_res18[3] = uVar6;
    uVar1 = *(undefined4 *)((longlong)param_2 + 0x24);
    uVar2 = *(undefined4 *)(param_2 + 5);
    uVar3 = *(undefined4 *)((longlong)param_2 + 0x2c);
    *(undefined4 *)(local_res18 + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)((longlong)local_res18 + 0x24) = uVar1;
    *(undefined4 *)(local_res18 + 5) = uVar2;
    *(undefined4 *)((longlong)local_res18 + 0x2c) = uVar3;
    uVar1 = *(undefined4 *)((longlong)param_2 + 0x34);
    uVar2 = *(undefined4 *)(param_2 + 7);
    uVar3 = *(undefined4 *)((longlong)param_2 + 0x3c);
    *(undefined4 *)(local_res18 + 6) = *(undefined4 *)(param_2 + 6);
    *(undefined4 *)((longlong)local_res18 + 0x34) = uVar1;
    *(undefined4 *)(local_res18 + 7) = uVar2;
    *(undefined4 *)((longlong)local_res18 + 0x3c) = uVar3;
    uVar6 = KeQueryPerformanceCounter(0);
    *local_res18 = uVar6;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x78))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 200),local_res20);
    if (iVar4 < 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res20);
    }
    else {
      Bus_ProcessAtResponses(param_1);
    }
  }
  return iVar4;
}



===== BusPdo_AtResponse @ 14000c100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BusPdo_AtResponse(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar2);
  iVar1 = BthRfcommQueueAtResponse(uVar2,param_2);
  (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar2);
  return iVar1;
}



===== BusRfcommAttemptSlcDisconnect @ 14000c190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BusRfcommAttemptSlcDisconnect(void)

{
  undefined8 uVar1;
  char cVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0xb,
               &WPP_7c449b44c0323832605238337e7a72e5_Traceguids);
  }
  RfcommDisconnect(uVar1);
  return 0;
}



===== BusRfcommAttemptSlcReconnect @ 14000c240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BusRfcommAttemptSlcReconnect(void)

{
  undefined8 uVar1;
  char cVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,10,
               &WPP_7c449b44c0323832605238337e7a72e5_Traceguids);
  }
  RfcommStartConnect(uVar1);
  return 0;
}



===== Bus_ProcessAtResponses @ 14000c2f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_ProcessAtResponses(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *_Src;
  size_t local_res10;
  undefined8 local_res18;
  longlong local_res20;
  void *local_38 [2];
  
  _Src = (longlong *)0x0;
  local_res10 = 0;
  local_res20 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  lVar3 = KeQueryPerformanceCounter(&local_res20);
  lVar4 = local_res20 / -2;
  while ((lVar5 = (**(code **)(WdfFunctions_01015 + 0x98))
                            (WdfDriverGlobals,*(undefined8 *)(lVar2 + 200)), lVar5 != 0 &&
         (_Src = (longlong *)
                 (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,lVar5,&local_res10),
         *_Src < lVar3 + lVar4))) {
    (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 200),0);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar5);
  }
  if (*(longlong *)(lVar2 + 0x138) != 0) {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(lVar2 + 0x138),
                       PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128);
    while (lVar5 != 0) {
      local_res18 = 0;
      local_38[0] = (void *)0x0;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                        (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10),&local_res18);
      if (iVar1 < 0) {
        return;
      }
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,local_res18,local_res10,local_38,0);
      if (iVar1 < 0) {
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res18,iVar1);
        return;
      }
      memcpy(local_38[0],_Src,local_res10);
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,local_res18,0,local_res10);
      (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 200),0);
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar5);
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x98))
                        (WdfDriverGlobals,*(undefined8 *)(lVar2 + 200));
      if (lVar5 != 0) {
        _Src = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,lVar5,&local_res10);
      }
    }
  }
  return;
}



===== RfcommDisconnect @ 14000c590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RfcommDisconnect(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (*(longlong *)(lVar1 + 0x138) != 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(lVar1 + 0x138),
                       PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128);
    if (*(longlong *)(lVar2 + 8) != 0) {
      ScoUserDisconnectRequest(param_1,*(longlong *)(lVar2 + 8));
      return;
    }
  }
  KeSetEvent(lVar1 + 0xd8,0,0);
  return;
}



===== RfcommStartConnect @ 14000c630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RfcommStartConnect(undefined8 param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (*(longlong *)(lVar1 + 0x138) != 0) {
    plVar2 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(lVar1 + 0x138),
                        PTR__WDF_SERVICE_DATA_TYPE_INFO_140022128);
    if (*plVar2 != 0) {
      BthHwEnterActiveMode(param_1);
      KeSetEvent(*plVar2,0,0);
    }
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_> @ 14000c6c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   WDFSPINLOCK__ * __ptr64,void (__cdecl*)(struct WDFSPINLOCK__ * __ptr64),&void __cdecl
   WdfSpinLockRelease(struct WDFSPINLOCK__ * __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,struct WDFSPINLOCK__ * __ptr64,struct WDFSPINLOCK__ * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<struct WDFSPINLOCK__ * __ptr64,void
   (__cdecl*)(struct WDFSPINLOCK__ * __ptr64),&void __cdecl WdfSpinLockRelease(struct WDFSPINLOCK__
   * __ptr64),struct wistd::integral_constant<unsigned __int64,2>,struct WDFSPINLOCK__ *
   __ptr64,struct WDFSPINLOCK__ * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  }
  return;
}



===== BthScoRemoteConnect @ 14000c700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthScoRemoteConnect(struct WDFDEVICE__ * __ptr64,struct _SCO_INDICATION_PARAMETERS *
   __ptr64) */

void __cdecl BthScoRemoteConnect(WDFDEVICE__ *param_1,_SCO_INDICATION_PARAMETERS *param_2)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  WDFDEVICE__ *pWVar6;
  char cVar7;
  
  lVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x81,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar7 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  if ((cVar5 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x82,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)*(undefined8 *)param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar7 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  if ((cVar5 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x83,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,
               (char)*(undefined4 *)(param_2 + 0x10));
  }
  ScoChannelRemoteConnect(param_1,*(void **)param_2,*(_SCO_LINK_TYPE *)(param_2 + 0x10));
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x430);
  uVar4 = WdfDriverGlobals;
  pWVar6 = param_1;
  do {
    (*pcVar1)(uVar4,pWVar6);
    do {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,lVar2,1);
      if (lVar2 == 0) {
        (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
        return;
      }
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar2,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
      pcVar1 = *(code **)(lVar3 + 0x60);
    } while (pcVar1 == (code *)0x0);
    uVar4 = *(undefined8 *)(lVar3 + 0x40);
    pWVar6 = *(WDFDEVICE__ **)param_2;
  } while( true );
}



===== BthScoRemoteDisconnect @ 14000c940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthScoRemoteDisconnect(struct WDFDEVICE__ * __ptr64,struct
   _SCO_INDICATION_PARAMETERS * __ptr64) */

void __cdecl BthScoRemoteDisconnect(WDFDEVICE__ *param_1,_SCO_INDICATION_PARAMETERS *param_2)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  WDFDEVICE__ *pWVar6;
  
  lVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x84,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  param_2[0x14] = (_SCO_INDICATION_PARAMETERS)0x1;
  ScoChannelRemoteDisconnect(param_1);
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x430);
  uVar4 = WdfDriverGlobals;
  pWVar6 = param_1;
  do {
    (*pcVar1)(uVar4,pWVar6);
    do {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,lVar2,1);
      if (lVar2 == 0) {
        (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
        return;
      }
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar2,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
      pcVar1 = *(code **)(lVar3 + 0x68);
    } while (pcVar1 == (code *)0x0);
    uVar4 = *(undefined8 *)(lVar3 + 0x40);
    pWVar6 = *(WDFDEVICE__ **)param_2;
  } while( true );
}



===== BthScoServerAddReference @ 14000ca80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthScoServerAddReference(struct WDFDEVICE__ * __ptr64,struct
   _SCO_INDICATION_PARAMETERS * __ptr64) */

void __cdecl BthScoServerAddReference(WDFDEVICE__ *param_1,_SCO_INDICATION_PARAMETERS *param_2)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x7f,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x668))
            (WdfDriverGlobals,param_1,0x46485442,0xe5a,
             "onecoreuap\\drivers\\wdm\\audio\\drivers\\bluetooth\\bthhfenum\\bthscoserver.cpp");
  LOCK();
  *(int *)(lVar1 + 0xa8) = *(int *)(lVar1 + 0xa8) + 1;
  UNLOCK();
  return;
}



===== BthScoServerRemoveReference @ 14000cb80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthScoServerRemoveReference(struct WDFDEVICE__ * __ptr64,struct
   _SCO_INDICATION_PARAMETERS * __ptr64) */

void __cdecl BthScoServerRemoveReference(WDFDEVICE__ *param_1,_SCO_INDICATION_PARAMETERS *param_2)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x80,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  LOCK();
  *(int *)(lVar1 + 0xa8) = *(int *)(lVar1 + 0xa8) + -1;
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,param_1,0x46485442,0xe6a,
             "onecoreuap\\drivers\\wdm\\audio\\drivers\\bluetooth\\bthhfenum\\bthscoserver.cpp");
  return;
}



===== GetScoState @ 14000cc74 =====

/* enum SCOSTATE __cdecl GetScoState(struct _SCOCONTEXT * __ptr64) */

SCOSTATE __cdecl GetScoState(_SCOCONTEXT *param_1)

{
  SCOSTATE SVar1;
  WDFSPINLOCK__ local_res8 [32];
  
  wil::acquire_wdf_spin_lock(local_res8);
  SVar1 = *(SCOSTATE *)(param_1 + 0x178);
  wil::details::
  unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
              *)local_res8);
  return SVar1;
}



===== LogScoConnection @ 14000ccb0 =====

/* void __cdecl LogScoConnection(struct _SCOCONTEXT * __ptr64,long) */

void __cdecl LogScoConnection(_SCOCONTEXT *param_1,long param_2)

{
  char cVar1;
  _tlgProvider_t *p_Var2;
  _GUID *in_R8;
  long local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 local_18;
  undefined8 local_10 [2];
  
  if (5 < DAT_140022000) {
    p_Var2 = (_tlgProvider_t *)&DAT_140022000;
    cVar1 = _tlgKeywordOn(0x140022000,0x400000000000);
    if (cVar1 != '\0') {
      local_18 = *(undefined8 *)(param_1 + 0x10);
      local_res20[0] = *(undefined4 *)(param_1 + 0x68);
      local_10[0] = 0x3000800;
      local_res18[0] = param_2;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_>
                (p_Var2,&DAT_14001f156,in_R8,(_GUID *)param_1,(_tlgWrapperByVal<8> *)local_10,
                 (_tlgWrapperByVal<4> *)local_res20,(_tlgWrapperByVal<4> *)local_res18,
                 (_tlgWrapperByVal<8> *)&local_18);
    }
  }
  return;
}



===== LogScoDisconnection @ 14000cd3c =====

/* void __cdecl LogScoDisconnection(struct _SCOCONTEXT * __ptr64,long) */

void __cdecl LogScoDisconnection(_SCOCONTEXT *param_1,long param_2)

{
  char cVar1;
  _tlgProvider_t *p_Var2;
  _GUID *in_R8;
  long local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 local_18;
  undefined8 local_10 [2];
  
  if (5 < DAT_140022000) {
    p_Var2 = (_tlgProvider_t *)&DAT_140022000;
    cVar1 = _tlgKeywordOn(0x140022000,0x400000000000);
    if (cVar1 != '\0') {
      local_18 = *(undefined8 *)(param_1 + 0x10);
      local_res20[0] = *(undefined4 *)(param_1 + 0x68);
      local_10[0] = 0x3000800;
      local_res18[0] = param_2;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_>
                (p_Var2,&DAT_14001f0f4,in_R8,(_GUID *)param_1,(_tlgWrapperByVal<8> *)local_10,
                 (_tlgWrapperByVal<4> *)local_res20,(_tlgWrapperByVal<4> *)local_res18,
                 (_tlgWrapperByVal<8> *)&local_18);
    }
  }
  return;
}



===== LogScoInStreamStats @ 14000cdc8 =====

/* void __cdecl LogScoInStreamStats(struct _SCOCONTEXT const & __ptr64,struct AudioQueueStreamStats
   const & __ptr64) */

void __cdecl LogScoInStreamStats(_SCOCONTEXT *param_1,AudioQueueStreamStats *param_2)

{
  char cVar1;
  _tlgProvider_t *p_Var2;
  _GUID *in_R8;
  int iVar3;
  undefined4 local_res10 [2];
  int local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18 [2];
  
  iVar3 = *(int *)(param_2 + 0x14);
  if ((0 < iVar3) && (5 < DAT_140022000)) {
    p_Var2 = (_tlgProvider_t *)&DAT_140022000;
    cVar1 = _tlgKeywordOn(0x140022000,0x400000000000);
    if (cVar1 != '\0') {
      local_20 = *(undefined8 *)(param_1 + 0x10);
      local_res10[0] = *(undefined4 *)(param_2 + 0x18);
      local_res20[0] = *(undefined4 *)(param_2 + 8);
      local_38 = *(undefined4 *)(param_2 + 4);
      local_34 = *(undefined4 *)(param_2 + 0x10);
      local_30 = *(undefined4 *)(param_2 + 0xc);
      local_2c = *(undefined4 *)param_2;
      local_28[0] = *(undefined4 *)(param_1 + 0x68);
      local_18[0] = 0x3000800;
      local_res18[0] = iVar3;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_>
                (p_Var2,&DAT_14001efea,in_R8,(_GUID *)param_2,(_tlgWrapperByVal<8> *)local_18,
                 (_tlgWrapperByVal<4> *)local_28,(_tlgWrapperByVal<4> *)&local_2c,
                 (_tlgWrapperByVal<4> *)&local_30,(_tlgWrapperByVal<4> *)&local_34,
                 (_tlgWrapperByVal<4> *)&local_38,(_tlgWrapperByVal<4> *)local_res20,
                 (_tlgWrapperByVal<4> *)local_res18,(_tlgWrapperByVal<4> *)local_res10,
                 (_tlgWrapperByVal<8> *)&local_20);
    }
  }
  return;
}



===== LogScoOutStreamStats @ 14000ced0 =====

/* void __cdecl LogScoOutStreamStats(struct _SCOCONTEXT const & __ptr64,struct AudioQueueStreamStats
   const & __ptr64) */

void __cdecl LogScoOutStreamStats(_SCOCONTEXT *param_1,AudioQueueStreamStats *param_2)

{
  char cVar1;
  _tlgProvider_t *p_Var2;
  _GUID *in_R8;
  int iVar3;
  undefined4 local_res10 [2];
  int local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [2];
  undefined8 local_18;
  undefined8 local_10;
  
  iVar3 = *(int *)(param_2 + 0x14);
  if ((0 < iVar3) && (5 < DAT_140022000)) {
    p_Var2 = (_tlgProvider_t *)&DAT_140022000;
    cVar1 = _tlgKeywordOn(0x140022000,0x400000000000);
    if (cVar1 != '\0') {
      local_18 = *(undefined8 *)(param_1 + 0x10);
      local_res10[0] = *(undefined4 *)(param_2 + 0x18);
      local_res20[0] = *(undefined4 *)(param_2 + 0x10);
      local_28 = *(undefined4 *)(param_2 + 0xc);
      local_24 = *(undefined4 *)param_2;
      local_20[0] = *(undefined4 *)(param_1 + 0x68);
      local_10 = 0x3000800;
      local_res18[0] = iVar3;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>_>
                (p_Var2,&DAT_14001ef17,in_R8,(_GUID *)param_2,(_tlgWrapperByVal<8> *)&local_10,
                 (_tlgWrapperByVal<4> *)local_20,(_tlgWrapperByVal<4> *)&local_24,
                 (_tlgWrapperByVal<4> *)&local_28,(_tlgWrapperByVal<4> *)local_res20,
                 (_tlgWrapperByVal<4> *)local_res18,(_tlgWrapperByVal<4> *)local_res10,
                 (_tlgWrapperByVal<8> *)&local_18);
    }
  }
  return;
}



===== RetrieveServiceScoStatusRequestForIndication @ 14000cfb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct utl::pair<long,struct WDFREQUEST__ * __ptr64> __cdecl
   RetrieveServiceScoStatusRequestForIndication(struct _SCOCONTEXT * __ptr64,enum
   _BTHHF_SCO_STATUS_INDICATION) */

_SCOCONTEXT * __cdecl
RetrieveServiceScoStatusRequestForIndication
          (_SCOCONTEXT *param_1,_BTHHF_SCO_STATUS_INDICATION param_2)

{
  _SCOCONTEXT *p_Var1;
  bool bVar2;
  int iVar3;
  char cVar4;
  undefined4 in_register_00000014;
  longlong lVar5;
  undefined4 in_R8D;
  undefined4 *local_res8;
  undefined8 uVar6;
  undefined4 in_stack_ffffffffffffffc0;
  undefined4 in_stack_ffffffffffffffc4;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar5 = CONCAT44(in_register_00000014,param_2);
  *(undefined4 *)param_1 = 0;
  p_Var1 = param_1 + 8;
  *(undefined8 *)p_Var1 = 0;
  bVar2 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATION
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  *(undefined4 *)(lVar5 + 0x188) = in_R8D;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                    (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x180),p_Var1);
  if (iVar3 < 0) {
    *(undefined4 *)(lVar5 + 0x18c) = 1;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      bVar2 = false;
    }
    if ((bVar2 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x77,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
    *(undefined4 *)param_1 = 0xc0000010;
  }
  else {
    *(undefined4 *)(lVar5 + 0x18c) = 0;
    local_res8 = (undefined4 *)0x0;
    uVar6 = 0;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,*(undefined8 *)p_Var1,4,&local_res8);
    *(int *)param_1 = iVar3;
    if (-1 < iVar3) {
      *local_res8 = in_R8D;
      if (*(int *)(lVar5 + 0x178) - 2U < 2) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          bVar2 = false;
        }
        if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_SCOSTATEd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,
                     CONCAT44(in_stack_ffffffffffffffc4,in_stack_ffffffffffffffc0),0x76,
                     in_stack_ffffffffffffffd0,(char)*(int *)(lVar5 + 0x178),5);
        }
        *(undefined4 *)(lVar5 + 0x178) = 5;
      }
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,*(undefined8 *)p_Var1,4);
    }
  }
  return param_1;
}



===== ScoAudioDataQueueReady @ 14000d1f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ScoAudioDataQueueReady(struct WDFQUEUE__ * __ptr64,void * __ptr64) */

void __cdecl ScoAudioDataQueueReady(WDFQUEUE__ *param_1,void *param_2)

{
  undefined8 *puVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  puVar1 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (5 < DAT_140022000) {
    local_14 = 0;
    local_20 = local_48;
    local_18 = 4;
    local_48[0] = *(undefined4 *)*puVar1;
    _tlgWriteTransfer_EtwWriteTransfer(0x140022000,&DAT_14001eee6,0,0,3,local_40);
  }
  ScoStreamProcessDataQueue(param_1);
  return;
}



===== ScoAvdtpUnsuspendDelayTimer @ 14000d2b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoAvdtpUnsuspendDelayTimer(struct WDFTIMER__ * __ptr64) */

void __cdecl ScoAvdtpUnsuspendDelayTimer(WDFTIMER__ *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  char cVar3;
  WDFSPINLOCK__ local_res10 [24];
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1d,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  wil::acquire_wdf_spin_lock(local_res10);
  *(undefined4 *)(lVar2 + 0x1c8) = 0;
  wil::details::
  unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
              *)local_res10);
  ScoUpdateAvdtpSuspension(lVar2);
  return;
}



===== ScoBuildOpenChannelBrb @ 14000d3a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoBuildOpenChannelBrb(struct _BRB * __ptr64,unsigned short,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,struct ScoConfigurationOptions const * __ptr64,struct _SCOCONTEXT *
   __ptr64) */

void __cdecl
ScoBuildOpenChannelBrb
          (_BRB *param_1,ushort param_2,WDFDEVICE__ *param_3,void *param_4,
          ScoConfigurationOptions *param_5,_SCOCONTEXT *param_6)

{
  undefined8 uVar1;
  longlong lVar2;
  char cVar3;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_3);
  *(void **)(param_1 + 0xb0) = param_4;
  *(undefined8 *)(param_1 + 0xa8) = uVar1;
  *(ushort *)(param_1 + 0x82) = param_2;
  *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(param_6 + 0x10);
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_5 + 4);
  *(undefined2 *)(param_1 + 0x84) = *(undefined2 *)(param_5 + 8);
  *(undefined2 *)(param_1 + 0x80) = *(undefined2 *)(param_5 + 10);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_5 + 0xc);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_3,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((*(int *)(param_6 + 0x68) == 2) && (*(int *)(lVar2 + 0x16c) == 0)) {
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x20;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_DLLDCODECIDDDl
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  *(WDFDEVICE__ **)(param_1 + 0xa0) = param_3;
  *(code **)(param_1 + 0x98) = BthScoIndicationCallback;
  *(undefined4 *)(param_1 + 0x90) = 1;
  param_1[0xb8] = (_BRB)0x0;
  return;
}



===== ScoBuildOpenEnchancedChannelBrb @ 14000d560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoBuildOpenEnchancedChannelBrb(struct _BRB * __ptr64,unsigned short,struct
   WDFDEVICE__ * __ptr64,void * __ptr64,struct ScoConfigurationOptions const * __ptr64,struct
   _SCOCONTEXT * __ptr64) */

void __cdecl
ScoBuildOpenEnchancedChannelBrb
          (_BRB *param_1,ushort param_2,WDFDEVICE__ *param_3,void *param_4,
          ScoConfigurationOptions *param_5,_SCOCONTEXT *param_6)

{
  undefined8 uVar1;
  char cVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_ddddd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_3);
  *(undefined8 *)(param_1 + 0xd8) = uVar1;
  *(ushort *)(param_1 + 0xae) = param_2;
  *(void **)(param_1 + 0xe0) = param_4;
  *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(param_6 + 0x10);
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_5 + 4);
  *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_5 + 8);
  *(undefined2 *)(param_1 + 0xac) = *(undefined2 *)(param_5 + 10);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_5 + 0xc);
  *(undefined2 *)(param_1 + 0x8a) = *(undefined2 *)(param_6 + 0x2a);
  *(undefined2 *)(param_1 + 0x8c) = *(undefined2 *)(param_6 + 0x2a);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_6 + 0x24);
  param_1[0x84] = *(_BRB *)(param_6 + 0x28);
  *(undefined4 *)(param_1 + 0x85) = *(undefined4 *)(param_6 + 0x24);
  param_1[0x89] = *(_BRB *)(param_6 + 0x28);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_6 + 0x30);
  param_1[0x9c] = *(_BRB *)(param_6 + 0x34);
  *(undefined4 *)(param_1 + 0x9d) = *(undefined4 *)(param_6 + 0x30);
  param_1[0xa1] = *(_BRB *)(param_6 + 0x34);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_6 + 0x2c);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_6 + 0x2c);
  *(undefined2 *)(param_1 + 0xa2) = *(undefined2 *)(param_6 + 0x36);
  *(undefined2 *)(param_1 + 0xa4) = *(undefined2 *)(param_6 + 0x36);
  param_1[0xa6] = *(_BRB *)(param_6 + 0x38);
  param_1[0xa7] = *(_BRB *)(param_6 + 0x38);
  param_1[0xa8] = *(_BRB *)(param_6 + 0x39);
  param_1[0xa9] = *(_BRB *)(param_6 + 0x39);
  param_1[0xd0] = *(_BRB *)(param_6 + 0x3a);
  param_1[0xaa] = *(_BRB *)(param_6 + 0x3b);
  param_1[0xab] = *(_BRB *)(param_6 + 0x3b);
  *(code **)(param_1 + 0xc0) = BthScoIndicationCallback;
  *(undefined4 *)(param_1 + 0xbc) = 1;
  *(WDFDEVICE__ **)(param_1 + 200) = param_3;
  param_1[0xe8] = (_BRB)0x0;
  return;
}



===== ScoCancelWaitingDataRequests @ 14000d778 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoCancelWaitingDataRequests(struct _SCO_TRANSFER_CONTEXT * __ptr64) */

void __cdecl ScoCancelWaitingDataRequests(_SCO_TRANSFER_CONTEXT *param_1)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  ulonglong uVar4;
  
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30))
  ;
  uVar4 = (ulonglong)uVar1;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x28,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)uVar1);
  }
  if (0 < (int)uVar1) {
    do {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x98))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
      if (lVar2 != 0) {
        AudioQueue_CancelRequest(*(WDFQUEUE__ **)(param_1 + 0x18),lVar2);
      }
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}



===== ScoChannelOpen @ 14000d8e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ScoChannelOpen(struct WDFDEVICE__ * __ptr64,void * __ptr64,struct _SCO_OPEN_CONTEXT
   const * __ptr64,void (__cdecl*)(long,struct WDFDEVICE__ * __ptr64)) */

long __cdecl
ScoChannelOpen(WDFDEVICE__ *param_1,void *param_2,_SCO_OPEN_CONTEXT *param_3,
              _func_void_long_WDFDEVICE___ptr *param_4)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined7 extraout_var;
  _BRB *p_Var7;
  WDFREQUEST__ *pWVar8;
  undefined4 uVar9;
  _SCO_OPEN_CONTEXT *local_res18;
  WDFREQUEST__ *local_res20;
  
  local_res18 = param_3;
  local_res20 = (WDFREQUEST__ *)param_4;
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qSCOSTATECODECID
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  local_res20 = (WDFREQUEST__ *)0x0;
  if (param_2 == (void *)0x0) {
    uVar9 = *(undefined4 *)((longlong)puVar6 + 0x1c);
  }
  else {
    uVar9 = *(undefined4 *)(puVar6 + 4);
  }
  if (*(int *)(puVar6 + 0xd) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2f,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
    bVar2 = NegotiateAndValidateCodec(param_1);
    if ((int)CONCAT71(extraout_var,bVar2) == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x30,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
      return -0x3ffffe7c;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qCODECIDCODECID
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if ((param_3 == (_SCO_OPEN_CONTEXT *)0x0) || (*(int *)(param_3 + 4) != *(int *)(puVar6 + 0xd))) {
    lVar4 = ScoSelectChannelConfigsFromCodecId(*(_CODECID *)(puVar6 + 0xd),&local_res18);
    if (lVar4 < 0) {
      return lVar4;
    }
    param_3 = local_res18;
  }
  iVar5 = AudioQueue_SetCodecId((WDFQUEUE__ *)puVar6[0x14],*(undefined4 *)(puVar6 + 0xd));
  if ((-1 < iVar5) &&
     (iVar5 = AudioQueue_SetCodecId((WDFQUEUE__ *)puVar6[0x1e],*(undefined4 *)(puVar6 + 0xd)),
     -1 < iVar5)) {
    p_Var7 = (_BRB *)(**(code **)(puVar6[1] + 0x20))(uVar9,*(undefined4 *)(puVar6 + 3));
    if (p_Var7 == (_BRB *)0x0) {
      iVar5 = -0x3fffff66;
    }
    else {
      iVar5 = WdfIoTargetCreateAndFormatRequestForBrb
                        (0,(WDFIOTARGET__ *)*puVar6,(_BTH_PROFILE_DRIVER_INTERFACE *)puVar6[1],
                         p_Var7,&local_res20);
      pWVar8 = local_res20;
      if (-1 < iVar5) {
        iVar5 = ScoChannelOpenBrbBuild(local_res20,param_1,param_2,param_3,p_Var7);
        p_Var7 = (_BRB *)0x0;
        if (-1 < iVar5) {
          SetScoState((longlong)puVar6,4);
          (**(code **)(WdfFunctions_01015 + 0x820))
                    (WdfDriverGlobals,pWVar8,ScoOpenCompletionRoutine,param_1);
          wil::acquire_wdf_spin_lock((WDFSPINLOCK__ *)&local_res20);
          puVar6[0x3a] = pWVar8;
          (**(code **)(WdfFunctions_01015 + 0x668))
                    (WdfDriverGlobals,pWVar8,0,0x769,
                     "onecoreuap\\drivers\\wdm\\audio\\drivers\\bluetooth\\bthhfenum\\bthscoserver.cpp"
                    );
          wil::details::
          unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
          ::
          ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
                    ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
                      *)&local_res20);
          (**(code **)(WdfFunctions_01015 + 0x9f8))
                    (WdfDriverGlobals,puVar6[0x3c],0xfffffffffd050f80);
          cVar3 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,pWVar8,*puVar6,0);
          if (cVar3 == '\0') {
            (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,puVar6[0x3c],1);
            wil::acquire_wdf_spin_lock((WDFSPINLOCK__ *)&local_res20);
            (**(code **)(WdfFunctions_01015 + 0x670))
                      (WdfDriverGlobals,puVar6[0x3a],0,0x773,
                       "onecoreuap\\drivers\\wdm\\audio\\drivers\\bluetooth\\bthhfenum\\bthscoserver.cpp"
                      );
            puVar6[0x3a] = 0;
            wil::details::
            unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
            ::
            ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
                      ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
                        *)&local_res20);
            iVar5 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals);
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar1 = false;
            }
            if ((bVar1 != false) ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_l
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x32,
                         &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar5);
            }
            SetScoState((longlong)puVar6,0);
          }
          else {
            pWVar8 = (WDFREQUEST__ *)0x0;
            iVar5 = 0;
          }
        }
      }
      if (pWVar8 != (WDFREQUEST__ *)0x0) {
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,pWVar8);
      }
      if (p_Var7 != (_BRB *)0x0) {
        (**(code **)(puVar6[1] + 0x28))(p_Var7);
      }
    }
  }
  return iVar5;
}



===== ScoChannelOpenAsync @ 14000de4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ScoChannelOpenAsync(struct WDFDEVICE__ * __ptr64) */

long __cdecl ScoChannelOpenAsync(WDFDEVICE__ *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 *puVar7;
  char cVar8;
  undefined8 local_res8;
  undefined8 local_68;
  code *pcStack_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_4c;
  undefined8 uStack_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  WDFDEVICE__ *local_30;
  undefined8 local_28;
  undefined *local_20;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x6f,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  local_3c = 0;
  local_28 = 0;
  local_res8 = 0;
  local_50 = 0x38;
  local_68 = 0x18;
  pcStack_60 = ScoChannelOpenWorkItem;
  local_20 = PTR__WDF_SCO_CHANNEL_OPEN_WORKITEM_CONTEXT_TYPE_INFO_1400223a0;
  local_58 = 0;
  local_4c = 0;
  uStack_44 = 0;
  local_38 = 1;
  local_34 = 1;
  local_30 = param_1;
  iVar5 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                    (WdfDriverGlobals,&local_68,&local_50,&local_res8);
  if (iVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    {
      cVar8 = '\0';
    }
    else {
      cVar8 = '\x01';
    }
    if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,5,0x70,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar5);
    }
  }
  else {
    puVar7 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res8,
                        PTR__WDF_SCO_CHANNEL_OPEN_WORKITEM_CONTEXT_TYPE_INFO_1400223a0);
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x170));
    uVar4 = *(undefined8 *)(lVar6 + 0x198);
    *puVar7 = *(undefined8 *)(lVar6 + 400);
    puVar7[1] = uVar4;
    uVar4 = *(undefined8 *)(lVar6 + 0x1a8);
    puVar7[2] = *(undefined8 *)(lVar6 + 0x1a0);
    puVar7[3] = uVar4;
    uVar1 = *(undefined4 *)(lVar6 + 0x1b4);
    uVar2 = *(undefined4 *)(lVar6 + 0x1b8);
    uVar3 = *(undefined4 *)(lVar6 + 0x1bc);
    *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(lVar6 + 0x1b0);
    *(undefined4 *)((longlong)puVar7 + 0x24) = uVar1;
    *(undefined4 *)(puVar7 + 5) = uVar2;
    *(undefined4 *)((longlong)puVar7 + 0x2c) = uVar3;
    puVar7[6] = *(undefined8 *)(lVar6 + 0x1c0);
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x170));
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res8);
  }
  return iVar5;
}



===== ScoChannelOpenBrbBuild @ 14000e0d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ScoChannelOpenBrbBuild(struct WDFREQUEST__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,struct _SCO_OPEN_CONTEXT const * __ptr64,struct _BRB * __ptr64) */

long __cdecl
ScoChannelOpenBrbBuild
          (WDFREQUEST__ *param_1,WDFDEVICE__ *param_2,void *param_3,_SCO_OPEN_CONTEXT *param_4,
          _BRB *param_5)

{
  int iVar1;
  ScoConfigurationOptions *pSVar2;
  undefined8 uVar3;
  bool bVar4;
  int iVar5;
  _SCOCONTEXT *p_Var6;
  ushort uVar7;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined *local_20;
  
  p_Var6 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  local_20 = PTR__WDF_SCO_OPEN_CONTEXT_TYPE_INFO_140022178;
  local_58 = (undefined8 *)0x0;
  local_40 = 0;
  bVar4 = true;
  uStack_48 = 0;
  local_50 = 0x38;
  local_30 = 0;
  uStack_28 = 0;
  uStack_38 = 0x100000001;
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,&local_50,&local_58);
  if (-1 < iVar5) {
    uVar3 = *(undefined8 *)(param_4 + 8);
    *local_58 = *(undefined8 *)param_4;
    local_58[1] = uVar3;
    uVar3 = *(undefined8 *)(param_4 + 0x18);
    local_58[2] = *(undefined8 *)(param_4 + 0x10);
    local_58[3] = uVar3;
    iVar5 = ScoGetRemotePacketTypes(p_Var6);
    if (iVar5 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        bVar4 = false;
      }
      if ((bVar4) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2d,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar5);
      }
    }
    else {
      iVar1 = *(int *)(local_58 + 2);
      while (0 < iVar1) {
        pSVar2 = *(ScoConfigurationOptions **)local_58[1];
        local_58[1] = (undefined8 *)local_58[1] + 1;
        *(int *)(local_58 + 2) = *(int *)(local_58 + 2) + -1;
        uVar7 = (*(ushort *)pSVar2 | 0x3c0) & *(ushort *)(p_Var6 + 0x3c);
        uVar7 = (uVar7 & 0x3f | 0x3c0) & *(ushort *)(p_Var6 + 0x44) |
                uVar7 & 0x3c0 | *(ushort *)pSVar2 & 0x3c0;
        if (uVar7 != 0x3c0) {
          iVar1 = *(int *)(p_Var6 + 0x1c);
          if ((iVar1 == 0x202) || (iVar1 == 0x210)) {
            ScoBuildOpenChannelBrb(param_5,uVar7,param_2,param_3,pSVar2,p_Var6);
            return iVar5;
          }
          if (iVar1 == 0x8201) {
            ScoBuildOpenEnchancedChannelBrb(param_5,uVar7,param_2,param_3,pSVar2,p_Var6);
            return iVar5;
          }
          return iVar5;
        }
        iVar1 = *(int *)(local_58 + 2);
      }
      iVar5 = *(int *)param_4;
    }
  }
  return iVar5;
}



===== ScoChannelOpenWorkItem @ 14000e300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoChannelOpenWorkItem(struct WDFWORKITEM__ * __ptr64) */

void __cdecl ScoChannelOpenWorkItem(WDFWORKITEM__ *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  WDFDEVICE__ *pWVar3;
  _SCO_OPEN_CONTEXT *p_Var4;
  _func_void_long_WDFDEVICE___ptr *in_R9;
  
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_SCO_CHANNEL_OPEN_WORKITEM_CONTEXT_TYPE_INFO_1400223a0);
  if (puVar2 != (undefined8 *)0x0) {
    pWVar3 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
    if (pWVar3 != (WDFDEVICE__ *)0x0) {
      p_Var4 = (_SCO_OPEN_CONTEXT *)(puVar2 + 3);
      if (*(int *)(puVar2 + 2) != 1) {
        p_Var4 = (_SCO_OPEN_CONTEXT *)0x0;
      }
      lVar1 = ScoChannelOpen(pWVar3,(void *)*puVar2,p_Var4,in_R9);
      if ((lVar1 < 0) && ((code *)puVar2[1] != (code *)0x0)) {
        (*(code *)puVar2[1])(lVar1,pWVar3);
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== ScoChannelTransfer @ 14000e3d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ScoChannelTransfer(struct _SCO_TRANSFER_CONTEXT * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl ScoChannelTransfer(_SCO_TRANSFER_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  char cVar2;
  undefined1 auStackY_138 [32];
  undefined8 *local_e8;
  undefined4 local_e0 [2];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  WDFREQUEST__ *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined *local_88;
  undefined8 local_78 [4];
  WDFREQUEST__ **local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_138;
  local_e8 = (undefined8 *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x36,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_1,(char)param_2);
  }
  local_d0 = 0;
  local_d8 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0);
  if (-1 < iVar1) {
    if (5 < DAT_140022000) {
      local_2c = 0;
      local_3c = 0;
      local_4c = 0;
      local_c8 = local_d8;
      local_e0[0] = *(undefined4 *)param_1;
      local_38 = &local_c8;
      local_48 = local_e0;
      local_58 = &local_c0;
      local_30 = 8;
      local_50 = 8;
      local_40 = 4;
      local_c0 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x140022000,&DAT_14001eddc,0,0,5,local_78);
    }
    local_88 = PTR__WDF_STREAMTRANSFER_REQUEST_CONTEXT_TYPE_INFO_1400223c8;
    local_a8 = 0;
    uStack_b0 = 0;
    local_b8 = 0x38;
    local_98 = 0;
    uStack_90 = 0;
    uStack_a0 = 0x100000001;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_2,&local_b8,&local_e8);
    if (-1 < iVar1) {
      *local_e8 = param_1;
      local_e8[1] = *(undefined8 *)(param_1 + 0x20);
      *(undefined4 *)(local_e8 + 2) = (undefined4)local_d8;
      (**(code **)(WdfFunctions_01015 + 0x9e0))
                (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28),iVar1);
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x78))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30),param_2);
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
      if (-1 < iVar1) {
        *(ulonglong *)(param_1 + 0x20) =
             *(longlong *)(param_1 + 0x20) + (ulonglong)*(uint *)(local_e8 + 2);
        AudioQueue_ProcessRequest(*(WDFQUEUE__ **)(param_1 + 0x18),param_2);
        return;
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== ScoCloseCompletionRoutine @ 14000e690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoCloseCompletionRoutine(struct WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void * __ptr64) */

void __cdecl
ScoCloseCompletionRoutine
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  undefined4 uVar1;
  bool bVar2;
  uint uVar3;
  SCOSTATE SVar4;
  _SCOCONTEXT *p_Var5;
  longlong lVar6;
  char cVar7;
  ulonglong uVar8;
  int iVar9;
  long lVar10;
  bool bVar11;
  WDFSPINLOCK__ local_res18 [8];
  undefined1 in_stack_ffffffffffffffa8;
  undefined7 in_stack_ffffffffffffffa9;
  undefined4 in_stack_ffffffffffffffb0;
  undefined4 in_stack_ffffffffffffffb4;
  undefined2 uVar12;
  undefined *in_stack_ffffffffffffffc0;
  undefined1 uVar13;
  
  p_Var5 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_4,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x610))
                    (WdfDriverGlobals,*(undefined8 *)(param_3 + 0x18),0);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
  uVar8 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar7 = '\0';
    }
    if ((cVar7 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_14000e810;
    uVar13 = (undefined1)*(undefined4 *)(p_Var5 + 0x6c);
    uVar12 = 0x14;
  }
  else {
    uVar3 = *(uint *)(lVar6 + 0x1c);
    uVar8 = (ulonglong)uVar3;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar7 = '\0';
    }
    if ((cVar7 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_14000e810;
    uVar13 = (undefined1)*(undefined4 *)(p_Var5 + 0x6c);
    uVar12 = 0x13;
  }
  in_stack_ffffffffffffffc0 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
  in_stack_ffffffffffffffb0 = 5;
  in_stack_ffffffffffffffa8 = 4;
  WPP_RECORDER_AND_TRACE_SF_dd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,uVar12,
             &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)uVar3,uVar13);
LAB_14000e810:
  bVar2 = true;
  wil::acquire_wdf_spin_lock(local_res18);
  *(undefined4 *)(p_Var5 + 0x1c8) = 1;
  (**(code **)(WdfFunctions_01015 + 0x9f8))
            (WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x128),0xfffffffffff85ee0);
  wil::details::
  unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
              *)local_res18);
  iVar9 = (int)uVar8;
  if (((iVar9 < 0) && (iVar9 != -0x3fffff63)) && (iVar9 != -0x3fffff4b)) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      bVar2 = false;
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar2) || (bVar11)) {
      uVar1 = *(undefined4 *)(p_Var5 + 0x6c);
      SVar4 = GetScoState(p_Var5);
      WPP_RECORDER_AND_TRACE_SF_SCOSTATEd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,bVar11,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT71(in_stack_ffffffffffffffa9,in_stack_ffffffffffffffa8),
                 CONCAT44(in_stack_ffffffffffffffb4,in_stack_ffffffffffffffb0),0x15,
                 in_stack_ffffffffffffffc0,(char)SVar4,(char)uVar1);
    }
  }
  else {
    *(undefined8 *)(p_Var5 + 0x80) = 0;
    SetScoState((longlong)p_Var5,0);
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_4,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
    SleepstudyHelper_ComponentInactive(*(undefined **)(lVar6 + 0x198));
    LOCK();
    lVar6 = *(longlong *)(p_Var5 + 0x70);
    *(longlong *)(p_Var5 + 0x70) = 0;
    UNLOCK();
    if (lVar6 == 0) {
      if (*(int *)(p_Var5 + 0x6c) != 0) {
        (**(code **)(WdfFunctions_01015 + 0x9f8))
                  (WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x148),0xfffffffffd050f80);
      }
    }
    else {
      KeSetEvent(lVar6,0,0);
      ObfDereferenceObject(lVar6);
    }
    uVar8 = 0;
  }
  lVar10 = (long)uVar8;
  LogScoDisconnection(p_Var5,lVar10);
  WdfIoQueueFindAndCompleteIoctlRequest(*(undefined8 *)(p_Var5 + 0x60),uVar8,0x22002f,lVar10);
  WdfIoQueueFindAndCompleteIoctlRequest(*(undefined8 *)(p_Var5 + 0x60),uVar8,0x2a002c,lVar10);
  LOCK();
  *(undefined4 *)(p_Var5 + 0x1d8) = 0;
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== ScoConnectionRequest_Bug53390280 @ 14000e9fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ScoConnectionRequest_Bug53390280(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  SCOSTATE SVar3;
  _SCOCONTEXT *p_Var4;
  undefined7 extraout_var;
  code *pcVar5;
  char cVar6;
  undefined8 uVar7;
  char cVar8;
  char cVar9;
  undefined8 local_res18 [2];
  undefined4 in_stack_ffffffffffffffb0;
  undefined4 in_stack_ffffffffffffffb4;
  undefined *in_stack_ffffffffffffffc0;
  
  p_Var4 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  cVar8 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
     (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffffc0 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
    in_stack_ffffffffffffffb0 = 5;
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3b,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  bVar1 = Bus_IsDeviceConnected(param_1);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar8 = '\0';
    }
    if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x3c,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
    iVar2 = -0x3fffff63;
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  else {
    bVar1 = ScoUpdateAvdtpSuspension((longlong)p_Var4);
    if (bVar1) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar6 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar9 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar9 = '\0';
      }
      if ((cVar6 != '\0') || (cVar9 != '\0')) {
        in_stack_ffffffffffffffc0 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
        in_stack_ffffffffffffffb0 = 5;
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar9,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x3d,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
      local_res18[0] = 0xfffffffffd050f80;
      KeWaitForSingleObject(p_Var4 + 0x130,0,0,0,local_res18);
    }
    if (*(int *)(p_Var4 + 0x178) == 7) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar6 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar8 = '\0';
      }
      if ((cVar6 != '\0') || (cVar8 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x3e,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
      iVar2 = 0;
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x838);
    }
    else {
      uVar7 = param_2;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(p_Var4 + 0x60));
      if (-1 < iVar2) {
        SVar3 = GetScoState(p_Var4);
        if (SVar3 == 0) {
          *(undefined8 *)(p_Var4 + 400) = 0;
          *(undefined8 *)(p_Var4 + 0x198) = 0;
          *(undefined8 *)(p_Var4 + 0x1a0) = 0;
          *(undefined8 *)(p_Var4 + 0x1a8) = 0;
          *(undefined8 *)(p_Var4 + 0x1b0) = 0;
          *(undefined8 *)(p_Var4 + 0x1b8) = 0;
          *(undefined8 *)(p_Var4 + 0x1c0) = 0;
          *(code **)(p_Var4 + 0x198) = ScoHandleStreamFailure;
          SetScoState((longlong)p_Var4,2);
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
            cVar6 = '\0';
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
             (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
            cVar8 = '\0';
          }
          if ((cVar6 != '\0') || (cVar8 != '\0')) {
            WPP_RECORDER_AND_TRACE_SF_l
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar8,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x3f,
                       &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar2);
          }
        }
        else if (((SVar3 - 3 & 0xfffffffc) != 0) || (SVar3 == 5)) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0 ||
              ((byte)WPP_GLOBAL_Control[0x29] < 3)))) {
            cVar8 = '\0';
          }
          if ((cVar8 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),cVar8);
            WPP_RECORDER_AND_TRACE_SF_SCOSTATE
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,
                       CONCAT44(in_stack_ffffffffffffffb4,in_stack_ffffffffffffffb0),0x40,
                       in_stack_ffffffffffffffc0,(char)*(undefined4 *)(p_Var4 + 0x178));
          }
          WdfIoQueueFindAndCompleteIoctlRequest
                    (*(undefined8 *)(p_Var4 + 0x60),uVar7,0x22002b,0xc0000184);
        }
        iVar2 = 0;
        goto LAB_14000ee18;
      }
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x838);
    }
  }
  (*pcVar5)(WdfDriverGlobals,param_2,iVar2);
LAB_14000ee18:
  ScoUpdateAvdtpSuspension((longlong)p_Var4);
  return iVar2;
}



===== ScoConnectionRequest_FixBug53390280 @ 14000ee44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ScoConnectionRequest_FixBug53390280(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  bool bVar2;
  SCOSTATE SVar3;
  int iVar4;
  _SCOCONTEXT *p_Var5;
  undefined7 extraout_var;
  char cVar6;
  undefined8 uVar7;
  uint7 uVar9;
  longlong lVar8;
  undefined1 uVar10;
  undefined1 auStackY_c8 [32];
  undefined4 in_stack_ffffffffffffff60;
  undefined4 in_stack_ffffffffffffff64;
  undefined *in_stack_ffffffffffffff70;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_60 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_60);
  uVar10 = 0;
  if (local_60._4_4_ == 0xe) {
    uVar10 = (undefined1)uStack_48;
  }
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffff70 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
    in_stack_ffffffffffffff60 = 5;
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x41,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,uVar10);
  }
  uVar7 = param_1;
  p_Var5 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar2 = Bus_IsDeviceConnected(param_1);
  if ((int)CONCAT71(extraout_var,bVar2) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x42,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,uVar10);
    }
    iVar4 = -0x3fffff63;
  }
  else {
    bVar2 = ScoUpdateAvdtpSuspension((longlong)p_Var5);
    if (bVar2) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        in_stack_ffffffffffffff70 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
        in_stack_ffffffffffffff60 = 5;
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x43,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,uVar10);
      }
      uVar7 = 0;
      KeWaitForSingleObject(p_Var5 + 0x130,0,0,0);
    }
    SVar3 = GetScoState(p_Var5);
    if (SVar3 == 7) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x44,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,uVar10);
      }
      iVar4 = 0;
    }
    else if (SVar3 - 8 < 2) {
      uVar9 = (uint7)((ulonglong)uVar7 >> 8);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        lVar8 = (ulonglong)uVar9 << 8;
      }
      else {
        lVar8 = CONCAT71(uVar9,1);
      }
      if (((char)lVar8 != '\0') ||
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPSCOSTATE
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)lVar8,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,
                   CONCAT44(in_stack_ffffffffffffff64,in_stack_ffffffffffffff60),0x45,
                   in_stack_ffffffffffffff70,uVar10,(char)SVar3);
      }
      iVar4 = -0x3ffffe7c;
      WdfIoQueueFindAndCompleteIoctlRequest
                (*(undefined8 *)(p_Var5 + 0x60),lVar8,0x22002b,0xc0000184);
      WdfIoQueueFindAndCompleteIoctlRequest
                (*(undefined8 *)(p_Var5 + 0x60),lVar8,0x2a0018,0xc0000184);
    }
    else {
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(p_Var5 + 0x60));
      if (-1 < iVar4) {
        if (SVar3 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar6 = '\0';
          }
          else {
            cVar6 = '\x01';
          }
          if ((cVar6 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_l
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x47,
                       &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,uVar10);
          }
          *(undefined8 *)(p_Var5 + 400) = 0;
          *(undefined8 *)(p_Var5 + 0x198) = 0;
          *(undefined8 *)(p_Var5 + 0x1a0) = 0;
          *(undefined8 *)(p_Var5 + 0x1a8) = 0;
          *(undefined8 *)(p_Var5 + 0x1b0) = 0;
          *(undefined8 *)(p_Var5 + 0x1b8) = 0;
          *(undefined8 *)(p_Var5 + 0x1c0) = 0;
          *(code **)(p_Var5 + 0x198) = ScoHandleStreamFailure;
          SetScoState((longlong)p_Var5,2);
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar6 = '\0';
          }
          else {
            cVar6 = '\x01';
          }
          if ((cVar6 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPSCOSTATE
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,
                       CONCAT44(in_stack_ffffffffffffff64,in_stack_ffffffffffffff60),0x48,
                       in_stack_ffffffffffffff70,uVar10,(char)SVar3);
          }
          ScoUpdateAvdtpSuspension((longlong)p_Var5);
        }
        iVar4 = 0x103;
        goto LAB_14000f38e;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPdSCOSTATE
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar4);
  ScoUpdateAvdtpSuspension((longlong)p_Var5);
LAB_14000f38e:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return iVar4;
}



===== ScoDataCompletionTimer @ 14000f420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoDataCompletionTimer(struct WDFTIMER__ * __ptr64) */

void __cdecl ScoDataCompletionTimer(WDFTIMER__ *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  char cVar5;
  
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PSCO_TRANSFER_CONTEXT_TYPE_INFO_1400221a0);
  lVar1 = *plVar4;
  uVar2 = *(undefined8 *)(lVar1 + 0x38);
  uVar3 = *(undefined8 *)(lVar1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1f,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  *(undefined8 *)(lVar1 + 0x38) = 0;
  *(undefined8 *)(lVar1 + 0x40) = 0;
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,uVar2,0,uVar3);
  ScoStreamProcessDataQueue(*(WDFQUEUE__ **)(lVar1 + 0x18));
  return;
}



===== ScoDataQueue_EvtIoStop @ 14000f520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoDataQueue_EvtIoStop(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned long) */

void __cdecl ScoDataQueue_EvtIoStop(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,ulong param_3)

{
  (**(code **)(WdfFunctions_01015 + 0x8e0))(WdfDriverGlobals,param_2,0);
  return;
}



===== ScoGetControllerSupportedCodecs @ 14000f550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ScoGetControllerSupportedCodecs(struct _SCOCONTEXT * __ptr64) */

void __cdecl ScoGetControllerSupportedCodecs(_SCOCONTEXT *param_1)

{
  byte *_Src;
  int iVar1;
  ulonglong uVar2;
  byte *pbVar3;
  size_t sVar4;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 *local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_68;
  undefined8 *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  byte local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_20 = 0;
  local_1c = 0;
  local_1a = 0;
  local_80 = 0;
  local_60 = &local_50;
  local_90 = &local_68;
  uStack_48 = 0;
  local_88 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_68 = 1;
  local_30 = 0;
  uStack_28 = 0;
  local_58 = 0x37;
  local_50 = 0x33;
  local_98 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,*(undefined8 *)param_1,0,0x4111a4);
  if (-1 < iVar1) {
    uVar2 = (ulonglong)local_50._4_1_;
    pbVar3 = (byte *)((longlong)&local_50 + uVar2 + 5);
    if (pbVar3 <= &local_19) {
      sVar4 = 4;
      if (local_50._4_1_ < 4) {
        sVar4 = (size_t)local_50._4_1_;
      }
      memcpy(param_1 + 0x48,(void *)((longlong)&local_50 + 5),sVar4);
      _Src = (byte *)((longlong)&local_50 + uVar2 + 6);
      if ((_Src <= &local_19) && (uVar2 = (ulonglong)*pbVar3 * 4, _Src + uVar2 <= &local_19)) {
        sVar4 = 0x10;
        if (uVar2 < 0x10) {
          sVar4 = uVar2;
        }
        memcpy(param_1 + 0x4c,_Src,sVar4);
      }
    }
  }
  return;
}



===== ScoGetRemotePacketTypes @ 14000f688 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ScoGetRemotePacketTypes(struct _SCOCONTEXT * __ptr64) */

long __cdecl ScoGetRemotePacketTypes(_SCOCONTEXT *param_1)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*(short *)(param_1 + 0x3c) == 0) {
    bVar1 = true;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,*(undefined8 *)param_1,0,0x410004);
    if (iVar3 < 0) {
      if (iVar3 == -0x3fffff63) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar1 = false;
        }
        if ((bVar1 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_l
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x23,
                     &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x9d);
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar1 = false;
        }
        if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_l
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x22,
                     &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar3);
        }
        *(undefined2 *)(param_1 + 0x3c) = 0x3f;
        iVar3 = 0;
      }
    }
    else {
      uVar2 = ScoPacketTypesFromLmpFeatures(0);
      *(ushort *)(param_1 + 0x3c) = uVar2;
    }
  }
  return iVar3;
}



===== ScoHandleStreamFailure @ 14000f880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoHandleStreamFailure(long,struct WDFDEVICE__ * __ptr64) */

void __cdecl ScoHandleStreamFailure(long param_1,WDFDEVICE__ *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  char cVar5;
  undefined8 uVar6;
  undefined4 in_stack_ffffffffffffffc0;
  undefined4 in_stack_ffffffffffffffc4;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
  {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffffc0 = 5;
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xc,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_1);
  }
  uVar6 = 0;
  SetScoState(lVar4,0);
  if (*(int *)(lVar4 + 0x6c) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      in_stack_ffffffffffffffc0 = 5;
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xd,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
    *(long *)(lVar4 + 0x78) = param_1;
    uVar6 = 0;
    WdfIoQueueFindAndCompleteStatusIoctlRequest
              (*(undefined8 *)(lVar4 + 0x60),0,0x220033,(long *)(lVar4 + 0x78),
               (undefined4 *)(lVar4 + 0x7c),
               CONCAT44(in_stack_ffffffffffffffc4,in_stack_ffffffffffffffc0));
  }
  iVar2 = WdfIoQueueFindAndCompleteIoctlRequest
                    (*(undefined8 *)(lVar4 + 0x60),uVar6,0x22002b,param_1);
  iVar3 = WdfIoQueueFindAndCompleteIoctlRequest
                    (*(undefined8 *)(lVar4 + 0x60),uVar6,0x2a0018,param_1);
  if ((-1 < iVar2) || (-1 < iVar3)) {
    *(undefined4 *)(lVar4 + 0x6c) = 0;
    ScoUpdateAvdtpSuspension(lVar4);
  }
  return;
}



===== ScoIdleTimer @ 14000fa20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoIdleTimer(struct WDFTIMER__ * __ptr64) */

void __cdecl ScoIdleTimer(WDFTIMER__ *param_1)

{
  bool bVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1b,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  if (*(int *)(lVar3 + 0x178) == 7) {
    if (*(int *)(lVar3 + 0x6c) == 1) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x1c,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
    }
    else {
      ScoChannelClose(uVar2,0);
    }
  }
  return;
}



===== ScoOpenCompletionGetChannelHandle @ 14000fb88 =====

/* long __cdecl ScoOpenCompletionGetChannelHandle(struct _SCOCONTEXT * __ptr64,struct _BRB *
   __ptr64) */

long __cdecl ScoOpenCompletionGetChannelHandle(_SCOCONTEXT *param_1,_BRB *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar2 = 0;
  if (iVar1 == 0x8201) {
    iVar2 = *(int *)(param_2 + 0x1c);
    if (-1 < iVar2) {
      *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_2 + 0xe0);
    }
  }
  else if (((iVar1 == 0x202) || (iVar1 == 0x210)) && (iVar2 = *(int *)(param_2 + 0x1c), -1 < iVar2))
  {
    *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_2 + 0xb0);
  }
  return iVar2;
}



===== ScoOpenCompletionRoutine @ 14000fbf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoOpenCompletionRoutine(struct WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void * __ptr64) */

void __cdecl
ScoOpenCompletionRoutine
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  char cVar7;
  long lVar8;
  _SCOCONTEXT *p_Var9;
  int *piVar10;
  _BRB *p_Var11;
  longlong lVar12;
  WDFSPINLOCK__ local_res18 [8];
  
  p_Var9 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_4,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  piVar10 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,PTR__WDF_SCO_OPEN_CONTEXT_TYPE_INFO_140022178
                             );
  p_Var11 = (_BRB *)(**(code **)(WdfFunctions_01015 + 0x610))
                              (WdfDriverGlobals,*(undefined8 *)(param_3 + 0x18),0);
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xe,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)lVar8);
  }
  cVar7 = (**(code **)(WdfFunctions_01015 + 0xa00))
                    (WdfDriverGlobals,*(undefined8 *)(p_Var9 + 0x1e0),0);
  if (cVar7 == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xf,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
  }
  wil::acquire_wdf_spin_lock(local_res18);
  if (*(longlong *)(p_Var9 + 0x1d0) == 0) {
    bVar6 = false;
    if (*(int *)(p_Var9 + 0x6c) == 0) {
      bVar6 = true;
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(longlong *)(p_Var9 + 0x1d0),0,0x1fc,
               "onecoreuap\\drivers\\wdm\\audio\\drivers\\bluetooth\\bthhfenum\\bthscoserver.cpp");
    *(undefined8 *)(p_Var9 + 0x1d0) = 0;
    bVar6 = false;
  }
  if (-1 < lVar8) {
    lVar8 = ScoOpenCompletionGetChannelHandle(p_Var9,p_Var11);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x10,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,
                 (char)*(undefined8 *)(p_Var9 + 0x80));
    }
  }
  wil::details::
  unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
              *)local_res18);
  LogScoConnection(p_Var9,lVar8);
  if (lVar8 < 0) {
    *piVar10 = lVar8;
    if (piVar10[4] < 1) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x12,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x11,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)piVar10[4]);
      }
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(p_Var9 + 0x170));
      iVar2 = piVar10[1];
      iVar3 = piVar10[2];
      iVar4 = piVar10[3];
      *(int *)(p_Var9 + 0x1a8) = *piVar10;
      *(int *)(p_Var9 + 0x1ac) = iVar2;
      *(int *)(p_Var9 + 0x1b0) = iVar3;
      *(int *)(p_Var9 + 0x1b4) = iVar4;
      iVar2 = piVar10[4];
      iVar3 = piVar10[5];
      iVar4 = piVar10[6];
      iVar5 = piVar10[7];
      *(undefined4 *)(p_Var9 + 0x1a0) = 1;
      *(int *)(p_Var9 + 0x1b8) = iVar2;
      *(int *)(p_Var9 + 0x1bc) = iVar3;
      *(int *)(p_Var9 + 0x1c0) = iVar4;
      *(int *)(p_Var9 + 0x1c4) = iVar5;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var9 + 0x170));
      lVar8 = ScoChannelOpenAsync(param_4);
      if (-1 < lVar8) goto LAB_1400100a8;
    }
    ScoHandleStreamFailure(lVar8,param_4);
  }
  else if (bVar6) {
    ScoChannelClose(param_4,0);
  }
  else {
    lVar12 = (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_4,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
    SleepstudyHelper_ComponentActive(*(undefined **)(lVar12 + 0x198));
    AudioQueue_StreamStart(*(WDFQUEUE__ **)(p_Var9 + 0xa0));
    AudioQueue_StreamStart(*(WDFQUEUE__ **)(p_Var9 + 0xf0));
    SetScoState((longlong)p_Var9,6);
  }
LAB_1400100a8:
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== ScoPacketTypesFromLmpFeatures @ 1400100ec =====

/* unsigned short __cdecl ScoPacketTypesFromLmpFeatures(unsigned __int64) */

ushort __cdecl ScoPacketTypesFromLmpFeatures(__uint64 param_1)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar3 = 0;
  if ((param_1 >> 0xb & 1) != 0) {
    uVar2 = (ushort)(param_1 >> 0xb) & 2;
    uVar3 = uVar2 | 0x3c1;
    if ((param_1 >> 0xd & 1) != 0) {
      uVar3 = uVar2 | 0x3c5;
    }
  }
  if ((param_1 >> 0x1f & 1) != 0) {
    uVar2 = uVar3 | 0x3d8;
    if ((param_1 & 0x100000000) == 0) {
      uVar2 = uVar3 | 0x3c8;
    }
    uVar3 = uVar2 | 0x3e0;
    if ((param_1 & 0x200000000) == 0) {
      uVar3 = uVar2;
    }
    if ((param_1 >> 0x2d & 1) != 0) {
      uVar1 = (uint)(param_1 >> 0x2e) & 1;
      uVar2 = uVar3 & 0xff3f;
      if (uVar1 == 0) {
        uVar2 = uVar3 & 0xffbf;
      }
      uVar3 = uVar2;
      if (((param_1 >> 0x2f & 1) != 0) && (uVar3 = uVar2 & 0xfeff, uVar1 != 0)) {
        uVar3 = uVar2 & 0xfcff;
      }
    }
  }
  return uVar3;
}



===== ScoReopenTimer @ 1400101e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoReopenTimer(struct WDFTIMER__ * __ptr64) */

void __cdecl ScoReopenTimer(WDFTIMER__ *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_SCOSTATEd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,
               in_stack_ffffffffffffffd0,0x1a,in_stack_ffffffffffffffe0,
               (char)*(undefined4 *)(lVar2 + 0x178),(char)*(undefined4 *)(lVar2 + 0x6c));
  }
  if ((*(int *)(lVar2 + 0x178) == 0) && (*(int *)(lVar2 + 0x6c) != 0)) {
    SetScoState(lVar2,2);
  }
  return;
}



===== ScoRetrieveSDPRecord @ 1400102bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ScoRetrieveSDPRecord(struct WDFDEVICE__ * __ptr64,struct _BTH_SDP_STREAM_RESPONSE *
   __ptr64 * __ptr64) */

long __cdecl ScoRetrieveSDPRecord(WDFDEVICE__ *param_1,_BTH_SDP_STREAM_RESPONSE **param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  undefined8 *puVar4;
  _BTH_SDP_STREAM_RESPONSE *p_Var5;
  undefined8 uVar6;
  char cVar7;
  bool bVar8;
  undefined1 auStackY_248 [32];
  undefined1 uVar9;
  undefined8 *in_stack_fffffffffffffde0;
  undefined8 *puVar10;
  undefined2 uVar11;
  undefined *in_stack_fffffffffffffdf0;
  undefined8 uVar12;
  int iVar13;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 *puStack_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  _BTH_SDP_STREAM_RESPONSE *p_Stack_1d0;
  ulonglong local_1c8;
  undefined8 local_1c0;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined8 local_1a8;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined1 local_194;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 local_148;
  undefined4 local_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined2 local_12c;
  undefined4 local_4c;
  uint local_48 [2];
  undefined1 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_248;
  local_1e0 = 0;
  local_1c8 = 0;
  uStack_1b0 = 0;
  uStack_1ac = 0;
  uStack_198 = 0;
  local_194 = 0;
  local_190 = 0;
  local_1f0 = 0;
  puStack_1e8 = (undefined8 *)0x0;
  local_1d8 = 0;
  p_Stack_1d0 = (_BTH_SDP_STREAM_RESPONSE *)0x0;
  local_1c0 = 0;
  uStack_1b8 = 0;
  uStack_1b4 = 0;
  local_1a8 = 0;
  uStack_1a0 = 0;
  uStack_19c = 0;
  memset(&local_148,0,0x100);
  local_48[0] = 0;
  local_48[1] = 0;
  local_40 = 0;
  local_1f8 = 0;
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar2 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_fffffffffffffdf0 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
    in_stack_fffffffffffffde0 =
         (undefined8 *)CONCAT44((int)((ulonglong)in_stack_fffffffffffffde0 >> 0x20),5);
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5c,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  local_158 = 0;
  local_178 = 0;
  uStack_180 = 0;
  local_188 = 0x38;
  local_168 = 0;
  uStack_160 = 0;
  uStack_170 = 0x100000001;
  iVar13 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_188,*puVar4,&local_1f8)
  ;
  if (iVar13 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar7 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
      cVar7 = '\0';
    }
    if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_SCOSTATE
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,in_stack_fffffffffffffde0,0x5d,
                 in_stack_fffffffffffffdf0,(char)iVar13);
    }
    goto LAB_140010983;
  }
  local_1a8 = puVar4[2];
  in_stack_fffffffffffffde0 = &local_1d8;
  puStack_1e8 = &local_1a8;
  p_Stack_1d0 = (_BTH_SDP_STREAM_RESPONSE *)&local_1a8;
  in_stack_fffffffffffffdf0 = (undefined *)0x0;
  local_194 = 0;
  uStack_1a0 = 1;
  local_1f0 = 1;
  local_1e0 = 0x15;
  local_1d8 = 1;
  local_1c8 = 0x15;
  iVar13 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*puVar4,local_1f8,0x410200);
  if (iVar13 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar7 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
      cVar7 = '\0';
    }
    bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar7 != '\0') || (bVar8)) {
      uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar11 = 0x5e;
      uVar9 = 1;
      iVar3 = iVar13;
LAB_14001095f:
      WPP_RECORDER_AND_TRACE_SF_SCOSTATE
                (uVar6,cVar7,bVar8,uVar12,uVar9,in_stack_fffffffffffffde0,uVar11,
                 in_stack_fffffffffffffdf0,(char)iVar3);
    }
  }
  else {
    local_148 = CONCAT44(uStack_198,uStack_19c);
    local_12c = 0x430;
    local_13c = 0x111e;
    uStack_138 = 0x10000000;
    uStack_134 = 0x80000080;
    uStack_130 = 0xfb349b5f;
    local_4c = 0xffff0000;
    uStack_1b4 = 0;
    uStack_1b0 = 0;
    uStack_1ac = 0;
    local_1c0 = 0x18;
    uStack_1b8 = 0xc00000bb;
    (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,local_1f8,&local_1c0);
    puVar10 = &local_1d8;
    uVar12 = 0;
    p_Stack_1d0 = (_BTH_SDP_STREAM_RESPONSE *)local_48;
    local_1f0 = 1;
    local_1e0 = 0x100;
    local_1d8 = 1;
    local_1c8 = 9;
    puStack_1e8 = &local_148;
    iVar13 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*puVar4,local_1f8,0x410210);
    if (iVar13 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         (cVar7 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
        cVar7 = '\0';
      }
      bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar7 != '\0') || (bVar8)) {
        uVar11 = 0x5f;
LAB_140010698:
        WPP_RECORDER_AND_TRACE_SF_SCOSTATE
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,puVar10,uVar11,uVar12,(char)iVar13);
      }
    }
    else {
      uVar1 = local_48[0] + 9;
      if (uVar1 < local_48[0]) {
        iVar13 = -0x3fffff6b;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           (cVar7 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
          cVar7 = '\0';
        }
        bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar7 != '\0') || (bVar8)) {
          iVar13 = -0x3fffff6b;
          uVar11 = 0x60;
          goto LAB_140010698;
        }
      }
      else {
        if (*param_2 != (_BTH_SDP_STREAM_RESPONSE *)0x0) {
          ExFreePoolWithTag(*param_2,0x46485442);
          *param_2 = (_BTH_SDP_STREAM_RESPONSE *)0x0;
        }
        p_Var5 = (_BTH_SDP_STREAM_RESPONSE *)ExAllocatePool2(0x40,uVar1,0x46485442);
        *param_2 = p_Var5;
        if (p_Var5 == (_BTH_SDP_STREAM_RESPONSE *)0x0) {
          iVar13 = -0x3fffff66;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             (cVar7 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
            cVar7 = '\0';
          }
          bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar7 != '\0') || (bVar8)) {
            iVar13 = -0x3fffff66;
            uVar11 = 0x61;
            goto LAB_140010698;
          }
        }
        else {
          uStack_1b4 = 0;
          uStack_1b0 = 0;
          uStack_1ac = 0;
          local_1c0 = 0x18;
          uStack_1b8 = 0xc00000bb;
          (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,local_1f8,&local_1c0);
          puVar10 = &local_1d8;
          p_Stack_1d0 = *param_2;
          uVar12 = 0;
          local_1f0 = 1;
          local_1e0 = 0x100;
          local_1d8 = 1;
          local_1c8 = (ulonglong)uVar1;
          puStack_1e8 = &local_148;
          iVar13 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                             (WdfDriverGlobals,*puVar4,local_1f8,0x410210);
          if (iVar13 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
               (cVar7 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
              cVar7 = '\0';
            }
            if ((cVar7 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_SCOSTATE
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,puVar10,0x62,uVar12,
                         (char)iVar13);
            }
            ExFreePoolWithTag(*param_2,0x46485442);
            *param_2 = (_BTH_SDP_STREAM_RESPONSE *)0x0;
          }
        }
      }
    }
    uStack_1b4 = 0;
    uStack_1b0 = 0;
    uStack_1ac = 0;
    local_1c0 = 0x18;
    uStack_1b8 = 0xc00000bb;
    (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,local_1f8,&local_1c0);
    local_190 = CONCAT44(uStack_198,uStack_19c);
    puStack_1e8 = &local_190;
    in_stack_fffffffffffffdf0 = (undefined *)0x0;
    local_1f0 = 1;
    local_1e0 = 8;
    in_stack_fffffffffffffde0 = (undefined8 *)0x0;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*puVar4,local_1f8,0x410204);
    if (iVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar7 = '\0';
      }
      bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar7 != '\0') || (bVar8)) {
        uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        uVar11 = 99;
        uVar9 = 4;
        goto LAB_14001095f;
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_1f8);
LAB_140010983:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    bVar2 = false;
  }
  if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_SCOSTATE
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_fffffffffffffde0,100,
               in_stack_fffffffffffffdf0,(char)iVar13);
  }
  return iVar13;
}



===== ScoRetrieveSupportedFeaturesFromSDPRecord @ 140010a58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ScoRetrieveSupportedFeaturesFromSDPRecord(struct _BTHDDI_SDP_PARSE_INTERFACE *
   __ptr64,struct WDFDEVICE__ * __ptr64,unsigned short * __ptr64,struct _BTH_SDP_STREAM_RESPONSE *
   __ptr64) */

long __cdecl
ScoRetrieveSupportedFeaturesFromSDPRecord
          (_BTHDDI_SDP_PARSE_INTERFACE *param_1,WDFDEVICE__ *param_2,ushort *param_3,
          _BTH_SDP_STREAM_RESPONSE *param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  undefined8 local_res8;
  ulonglong local_res10;
  undefined8 local_res18;
  longlong local_res20;
  undefined1 uVar7;
  undefined4 in_stack_ffffffffffffffb0;
  undefined4 in_stack_ffffffffffffffb4;
  undefined2 uVar8;
  undefined8 in_stack_ffffffffffffffc0;
  
  *param_3 = 0;
  local_res18 = 0;
  local_res10 = (ulonglong)param_2 & 0xffffffff00000000;
  local_res8 = 0;
  local_res20 = 0;
  (**(code **)(param_1 + 0x78))
            (param_4 + 8,*(undefined4 *)(param_4 + 4),0,&local_res18,&local_res10);
  if ((int)local_res10 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar5 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
      cVar5 = '\0';
    }
    if ((cVar5 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) {
      return -0x3fffff64;
    }
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,5,0x65,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0);
    return -0x3fffff64;
  }
  iVar2 = (**(code **)(param_1 + 0x28))(local_res18,local_res10 & 0xffffffff,&local_res8,0x484650);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar5 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
      cVar5 = '\0';
    }
    if ((cVar5 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) {
      return iVar2;
    }
    WPP_RECORDER_AND_TRACE_SF_SCOSTATE
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,
               CONCAT44(in_stack_ffffffffffffffb4,in_stack_ffffffffffffffb0),0x66,
               in_stack_ffffffffffffffc0,(char)iVar2);
    return iVar2;
  }
  uVar3 = (**(code **)(param_1 + 0x70))(local_res8,0x311,&local_res20);
  if ((int)uVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar5 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
      cVar5 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 == '\0') && (!bVar6)) goto LAB_140010d92;
    uVar8 = 0x67;
    uVar7 = 1;
    uVar4 = uVar3;
LAB_140010d85:
    WPP_RECORDER_AND_TRACE_SF_SCOSTATE
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,
               CONCAT44(in_stack_ffffffffffffffb4,in_stack_ffffffffffffffb0),uVar8,
               in_stack_ffffffffffffffc0,(char)uVar4);
  }
  else {
    cVar5 = '\x01';
    if (*(short *)(local_res20 + 0x10) == 1) {
      if (*(short *)(local_res20 + 0x12) == 0x110) {
        uVar1 = *(ushort *)(local_res20 + 0x20);
        *param_3 = uVar1;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar5 = '\0';
        }
        bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar5 == '\0') && (!bVar6)) goto LAB_140010d92;
        uVar4 = (uint)uVar1;
        uVar8 = 0x6a;
        uVar7 = 4;
        goto LAB_140010d85;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         (cVar5 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
        cVar5 = '\0';
      }
      if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar8 = 0x69;
        goto LAB_140010d0a;
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         (cVar5 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
        cVar5 = '\0';
      }
      if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar8 = 0x68;
LAB_140010d0a:
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,5,uVar8,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
    }
    uVar3 = 0xc000009c;
  }
LAB_140010d92:
  (**(code **)(param_1 + 0x38))(local_res8);
  return uVar3;
}



===== ScoSelectChannelConfigsFromCodecId @ 140010db4 =====

/* long __cdecl ScoSelectChannelConfigsFromCodecId(enum _CODECID,struct _SCO_OPEN_CONTEXT const *
   __ptr64 * __ptr64) */

long __cdecl ScoSelectChannelConfigsFromCodecId(_CODECID param_1,_SCO_OPEN_CONTEXT **param_2)

{
  _SCO_OPEN_CONTEXT *p_Var1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if (param_1 == 1) {
    p_Var1 = (_SCO_OPEN_CONTEXT *)&DAT_14001d330;
  }
  else {
    if (param_1 != 2) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar2 = '\0';
      }
      else {
        cVar2 = '\x01';
      }
      if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_CODECID
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,
                   in_stack_ffffffffffffffd0,10,in_stack_ffffffffffffffe0,(char)param_1);
      }
      return -0x3ffffff3;
    }
    p_Var1 = (_SCO_OPEN_CONTEXT *)&DAT_14001d310;
  }
  *param_2 = p_Var1;
  return 0;
}



===== ScoSimulatedTransfer @ 140010e4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ScoSimulatedTransfer(struct _SCO_TRANSFER_CONTEXT * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

long __cdecl ScoSimulatedTransfer(_SCO_TRANSFER_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  char cVar2;
  longlong lVar3;
  char cVar4;
  longlong lVar5;
  char cVar6;
  longlong local_res18;
  longlong local_res20;
  undefined4 in_stack_ffffffffffffffa0;
  undefined4 in_stack_ffffffffffffffa4;
  undefined *in_stack_ffffffffffffffb0;
  undefined8 local_38 [2];
  
  local_38[0] = 0;
  local_res18 = 0;
  local_res20 = 0;
  cVar4 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
     (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffffb0 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
    in_stack_ffffffffffffffa0 = 5;
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x16,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_2,0,local_38,&local_res18);
  if (-1 < iVar1) {
    lVar3 = (*(longlong *)(param_1 + 0x20) - *(longlong *)(param_1 + 8)) + local_res18;
    lVar5 = lVar3 * 0x271;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar2 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar6 = '\0';
    }
    if ((cVar2 != '\0') || (cVar6 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_ii
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar6,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,
                 CONCAT44(in_stack_ffffffffffffffa4,in_stack_ffffffffffffffa0),0x17,
                 in_stack_ffffffffffffffb0,(char)lVar3,(char)lVar5);
    }
    lVar3 = KeQueryPerformanceCounter(&local_res20);
    lVar5 = lVar5 - (lVar3 - *(longlong *)(param_1 + 0x10)) / local_res20;
    if (lVar5 < 2) {
      lVar5 = 1;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar2 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar4 = '\0';
    }
    if ((cVar2 != '\0') || (cVar4 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_i
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar4,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,
                 CONCAT44(in_stack_ffffffffffffffa4,in_stack_ffffffffffffffa0),0x18,
                 in_stack_ffffffffffffffb0,(char)lVar5);
    }
    *(longlong *)(param_1 + 0x20) = *(longlong *)(param_1 + 0x20) + local_res18;
    *(longlong *)(param_1 + 0x40) = local_res18;
    *(WDFREQUEST__ **)(param_1 + 0x38) = param_2;
    (**(code **)(WdfFunctions_01015 + 0x9f8))
              (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x48),-lVar5);
    iVar1 = 0;
  }
  return iVar1;
}



===== ScoStreamProcessDataQueue @ 140011080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoStreamProcessDataQueue(struct WDFQUEUE__ * __ptr64) */

void __cdecl ScoStreamProcessDataQueue(WDFQUEUE__ *param_1)

{
  _SCO_TRANSFER_CONTEXT *p_Var1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  bool bVar7;
  WDFREQUEST__ *local_res10;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PSCO_TRANSFER_CONTEXT_TYPE_INFO_1400221a0);
  p_Var1 = (_SCO_TRANSFER_CONTEXT *)*puVar6;
  local_res10 = (WDFREQUEST__ *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar2 != '\0') || (bVar7)) {
    (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(p_Var1 + 0x30));
    WPP_RECORDER_AND_TRACE_SF_SCOSTATEdq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  while (((*(int *)(lVar5 + 0x178) == 7 && (*(longlong *)(p_Var1 + 0x38) == 0)) &&
         ((cVar2 = AudioQueue_IsReadyToProcessNextRequest(param_1), cVar2 != '\0' &&
          ((iVar3 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,param_1,&local_res10)
           , -1 < iVar3 && (local_res10 != (WDFREQUEST__ *)0x0))))))) {
    ScoChannelTransfer(p_Var1,local_res10);
  }
  while ((((*(int *)(lVar5 + 0x178) != 7 &&
           (iVar3 = (**(code **)(WdfFunctions_01015 + 0x70))
                              (WdfDriverGlobals,*(undefined8 *)(p_Var1 + 0x30)), iVar3 == 0)) &&
          (*(longlong *)(p_Var1 + 0x38) == 0)) &&
         ((iVar3 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,param_1,&local_res10),
          -1 < iVar3 && (local_res10 != (WDFREQUEST__ *)0x0))))) {
    ScoSimulatedTransfer(p_Var1,local_res10);
  }
  return;
}



===== ScoTransitionWatchdogTimer @ 1400112a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ScoTransitionWatchdogTimer(struct WDFTIMER__ * __ptr64) */

void __cdecl ScoTransitionWatchdogTimer(WDFTIMER__ *param_1)

{
  WDFDEVICE__ *pWVar1;
  char cVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1e,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  MicrosoftTelemetryAssertTriggeredMsgKM("SCO stream setup transition timed out");
  pWVar1 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  ScoHandleStreamFailure(-0x3fffff4b,pWVar1);
  return;
}



===== ScoUpdateAvdtpSuspension @ 14001135c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool ScoUpdateAvdtpSuspension(longlong param_1)

{
  bool bVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  WDFSPINLOCK__ local_res8 [8];
  undefined8 in_stack_ffffffffffffffc8;
  
  wil::acquire_wdf_spin_lock(local_res8);
  cVar3 = '\x01';
  bVar4 = *(int *)(param_1 + 0x1cc) != 0;
  if (((*(int *)(param_1 + 0x178) != 0) || (*(int *)(param_1 + 0x6c) != 0)) ||
     (bVar1 = false, *(int *)(param_1 + 0x1c8) != 0)) {
    bVar1 = true;
  }
  if (bVar1 == bVar4) {
    wil::details::
    unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
                *)local_res8);
    bVar4 = false;
  }
  else {
    *(uint *)(param_1 + 0x1cc) = (uint)bVar1;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ll
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,5,0xb,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,bVar4,bVar1);
    }
    wil::details::
    unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
                *)local_res8);
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
    KeClearEvent(param_1 + 0x130);
    uVar2 = Bus_MpmAvdtpSuspendRequest(uVar2,(uint)bVar1);
    bVar4 = (int)uVar2 == 0x103;
  }
  return bVar4;
}



===== SetScoState @ 1400114a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 SetScoState(longlong param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  _SCOCONTEXT local_18 [16];
  
  bVar1 = false;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_SCOSTATEd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,
               in_stack_ffffffffffffffc0,0x72,in_stack_ffffffffffffffd0,
               (char)*(undefined4 *)(param_1 + 0x178),(char)param_2);
  }
  *(int *)(param_1 + 0x178) = param_2;
  if (param_2 == 0) {
    KeSetEvent(param_1 + 0x150,0,0);
  }
  else {
    if ((param_2 != 2) && (param_2 != 3)) {
      if (param_2 != 6) {
        if (((param_2 != 7) && (param_2 != 8)) && (param_2 != 9)) {
          uVar4 = 0;
          lVar5 = 0;
          goto LAB_14001160d;
        }
        goto LAB_1400115ca;
      }
      KeClearEvent(param_1 + 0x150);
    }
    bVar1 = true;
  }
LAB_1400115ca:
  puVar2 = (undefined4 *)
           RetrieveServiceScoStatusRequestForIndication
                     (local_18,(_BTHHF_SCO_STATUS_INDICATION)param_1);
  uVar4 = *puVar2;
  lVar5 = *(longlong *)(puVar2 + 2);
  if (bVar1) {
    (**(code **)(WdfFunctions_01015 + 0x9f8))
              (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x1e0),0xfffffffffd050f80);
  }
LAB_14001160d:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x170));
  if (lVar5 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar5,uVar4);
  }
  ScoUpdateAvdtpSuspension(param_1);
  return uVar4;
}



===== acquire_wdf_spin_lock @ 14001167c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct WDFSPINLOCK__ * __ptr64,void (__cdecl*)(struct WDFSPINLOCK__
   * __ptr64),&void __cdecl WdfSpinLockRelease(struct WDFSPINLOCK__ * __ptr64),struct
   wistd::integral_constant<unsigned __int64,2>,struct WDFSPINLOCK__ * __ptr64,struct WDFSPINLOCK__
   * __ptr64,0,std::nullptr_t> > > __cdecl wil::acquire_wdf_spin_lock(struct WDFSPINLOCK__ *
   __ptr64) */

WDFSPINLOCK__ * __cdecl wil::acquire_wdf_spin_lock(WDFSPINLOCK__ *param_1)

{
  undefined8 in_RDX;
  
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
  *(undefined8 *)param_1 = in_RDX;
  return param_1;
}



===== AudioQueueClient_AttemptProcessing @ 1400116c0 =====

void AudioQueueClient_AttemptProcessing(WDFQUEUE__ *param_1)

{
  ScoStreamProcessDataQueue(param_1);
  return;
}



===== AudioQueueClient_CompleteStreamTransferRequest @ 1400116d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool AudioQueueClient_CompleteStreamTransferRequest
               (undefined8 param_1,int param_2,undefined8 param_3,char param_4,longlong param_5)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  longlong *plVar5;
  undefined1 auStackY_128 [32];
  int local_f0;
  int local_ec;
  undefined4 local_e8 [2];
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8 [4];
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  int *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  bVar3 = true;
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_STREAMTRANSFER_REQUEST_CONTEXT_TYPE_INFO_1400223c8);
  puVar2 = (undefined4 *)*plVar5;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(puVar2 + 10));
  cVar1 = *(char *)((longlong)plVar5 + 0x14);
  if (cVar1 == '\0') {
    if (((param_4 == '\0') ||
        (iVar4 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,param_1), -1 < iVar4))
       || ((iVar4 == -0x3ffffee0 && (param_2 == -0x3ffffee0)))) {
      if ((-1 < param_2) && (param_5 != 0)) {
        *(longlong *)(puVar2 + 4) = param_5;
        *(ulonglong *)(puVar2 + 2) = (ulonglong)*(uint *)(plVar5 + 2) + plVar5[1];
      }
      (**(code **)(WdfFunctions_01015 + 0x80))
                (WdfDriverGlobals,*(undefined8 *)(*plVar5 + 0x30),param_1);
      *(undefined1 *)((longlong)plVar5 + 0x14) = 1;
    }
    else {
      bVar3 = false;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(*plVar5 + 0x28));
  (**(code **)(WdfFunctions_01015 + 0x4c8))(WdfDriverGlobals,*(undefined8 *)(puVar2 + 6));
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(*plVar5 + 0x30))
  ;
  if ((cVar1 == '\0') && (bVar3)) {
    if (5 < DAT_140022000) {
      local_e0 = *(undefined8 *)(puVar2 + 2);
      local_d8 = *(undefined8 *)(puVar2 + 4);
      local_e8[0] = *puVar2;
      local_58 = &local_f0;
      local_68 = &local_ec;
      local_78 = &local_e0;
      local_88 = &local_d8;
      local_98 = local_e8;
      local_a8 = &local_d0;
      local_70 = 8;
      local_80 = 8;
      local_a0 = 8;
      local_50 = 4;
      local_60 = 4;
      local_90 = 4;
      local_f0 = param_2;
      local_ec = iVar4;
      local_d0 = param_1;
      _tlgWriteTransfer_EtwWriteTransfer(0x140022000,&DAT_14001ee5c,0,0,8,local_c8);
    }
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,param_2,param_3);
  }
  return iVar4 != 0;
}



===== AudioQueueClient_CreateTransferBrb @ 140011988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AudioQueueClient_CreateTransferBrb
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,longlong *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  _BRB *p_Var6;
  undefined8 *puVar7;
  char cVar8;
  longlong lVar9;
  char cVar10;
  longlong local_68 [2];
  code *local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined *local_30;
  
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PSCO_TRANSFER_CONTEXT_TYPE_INFO_1400221a0);
  puVar2 = (undefined4 *)*puVar4;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar5,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  local_68[0] = 0;
  p_Var6 = (_BRB *)(**(code **)(puVar4[1] + 0x20))(0x205,*(undefined4 *)(puVar4 + 3));
  if (p_Var6 == (_BRB *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(p_Var6 + 0x70) = puVar4[2];
    *(undefined8 *)(p_Var6 + 0x78) = puVar4[0x10];
    uVar1 = *puVar2;
    *(undefined8 *)(p_Var6 + 0x88) = param_2;
    cVar10 = '\x01';
    *(undefined4 *)(p_Var6 + 0x80) = uVar1;
    *(undefined4 *)(p_Var6 + 0x84) = param_3;
    *(undefined8 *)(p_Var6 + 0x90) = 0;
    local_30 = PTR__WDF_BRB_REQUEST_CONTEXT_TYPE_INFO_1400223f0;
    local_50 = 0;
    local_38 = 0;
    local_68[1] = 0x38;
    local_48 = 1;
    local_44 = 1;
    local_40 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
    local_58 = BrbRequest_EvtCleanupCallback;
    iVar3 = WdfIoTargetCreateAndFormatRequestForBrb
                      (local_68 + 1,(WDFIOTARGET__ *)*puVar4,
                       (_BTH_PROFILE_DRIVER_INTERFACE *)puVar4[1],p_Var6,local_68);
    lVar9 = local_68[0];
    if (iVar3 < 0) {
    }
    else {
      p_Var6 = (_BRB *)0x0;
      puVar7 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_68[0],
                          PTR__WDF_BRB_REQUEST_CONTEXT_TYPE_INFO_1400223f0);
      *puVar7 = puVar2;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar8 = '\0';
      }
      else {
        cVar8 = '\x01';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar10 = '\0';
      }
      if ((cVar8 != '\0') || (cVar10 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,cVar10,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      *param_4 = lVar9;
      iVar3 = 0;
      lVar9 = 0;
    }
    if (lVar9 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    if (p_Var6 != (_BRB *)0x0) {
      (**(code **)(puVar4[1] + 0x28))(p_Var6);
    }
  }
  return iVar3;
}



===== AudioQueueClient_FlushChannel @ 140011c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AudioQueueClient_FlushChannel(undefined8 param_1)

{
  WDFDEVICE__ *pWVar1;
  undefined8 *puVar2;
  
  pWVar1 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PSCO_TRANSFER_CONTEXT_TYPE_INFO_1400221a0);
  ScoStreamFlush(pWVar1,(*(int *)*puVar2 != 0) + 1);
  return;
}



===== AudioQueueClient_SendTransferBrb @ 140011c78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
AudioQueueClient_SendTransferBrb
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined8 local_78 [4];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,uVar2,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,param_4,param_2);
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_4);
  if (cVar1 == '\0') {
    local_88[0] = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_4);
  }
  else {
    local_88[0] = 0;
  }
  uVar3 = local_88[0];
  if (5 < DAT_140022000) {
    local_3c = 0;
    local_48 = &local_80;
    local_4c = 0;
    local_58 = local_88;
    local_50 = 4;
    local_40 = 8;
    local_80 = param_4;
    _tlgWriteTransfer_EtwWriteTransfer(0x140022000,&DAT_14001ee1a,0,0,4,local_78);
  }
  return uVar3;
}



===== BthScoIndicationCallback @ 140011de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BthScoIndicationCallback(undefined8 param_1,uint param_2,undefined8 param_3)

{
  char cVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x85,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_2);
  }
  if (param_2 < 4) {
    (*(code *)(&ScoIndicationCallbackMap)[(int)param_2])(param_1,param_3);
  }
  return;
}



===== BthScoRegisterServer @ 140011e9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthScoRegisterServer(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x90),PTR__WDF_BRB_TYPE_INFO_1400221c8
                    );
  (**(code **)(lVar2 + 0x80))(lVar3,0x200);
  *(undefined8 *)(lVar3 + 0x88) = param_1;
  *(code **)(lVar3 + 0x80) = BthScoIndicationCallback;
  *(undefined4 *)(lVar3 + 0x7c) = 3;
  *(undefined8 *)(lVar3 + 0x70) = *(undefined8 *)(lVar2 + 0x1b0);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  *(undefined8 *)(lVar3 + 0x90) = uVar4;
  iVar1 = BthHwSendBrbSync(param_1,lVar3,0xa0);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_id
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_iq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    *(undefined8 *)(lVar2 + 0xa0) = *(undefined8 *)(lVar3 + 0x98);
  }
  return iVar1;
}



===== BthScoServerInitialization @ 140012060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BthScoServerInitialization(undefined8 param_1)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x8b,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  *(undefined8 *)(lVar1 + 0xa0) = 0;
  *(undefined8 *)(lVar1 + 0xa8) = 0;
  return 0;
}



===== BthScoUnRegisterServer @ 140012118 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthScoUnRegisterServer(undefined8 param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  undefined4 in_stack_ffffffffffffffc0;
  undefined4 in_stack_ffffffffffffffc4;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (*(longlong *)(lVar3 + 0xa0) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_i
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,
                 CONCAT44(in_stack_ffffffffffffffc4,in_stack_ffffffffffffffc0),0x88,
                 in_stack_ffffffffffffffd0,(char)*(undefined8 *)(lVar3 + 0x1b0));
    }
    iVar2 = 0;
  }
  else {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x90),
                       PTR__WDF_BRB_TYPE_INFO_1400221c8);
    (**(code **)(lVar3 + 0x80))(lVar4);
    *(undefined8 *)(lVar4 + 0x70) = *(undefined8 *)(lVar3 + 0x1b0);
    *(undefined8 *)(lVar4 + 0x78) = *(undefined8 *)(lVar3 + 0xa0);
    bVar1 = true;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qi
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    iVar2 = BthHwSendBrbSync(param_1,lVar4,0x80);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_l
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x8a,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar2);
      }
    }
    *(undefined8 *)(lVar3 + 0xa0) = 0;
  }
  return iVar2;
}



===== ScoChannelClose @ 14001232c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ScoChannelClose(undefined8 param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  SCOSTATE SVar3;
  int iVar4;
  _SCOCONTEXT *p_Var5;
  _BRB *p_Var6;
  longlong lVar7;
  longlong local_res18;
  
  p_Var5 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  local_res18 = 0;
  SVar3 = GetScoState(p_Var5);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qSCOSTATE
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (((SVar3 - 4 & 0xfffffffc) == 0) && (SVar3 != 5)) {
    p_Var6 = (_BRB *)(**(code **)(*(longlong *)(p_Var5 + 8) + 0x20))
                               (0x204,*(undefined4 *)(p_Var5 + 0x18));
    if (p_Var6 == (_BRB *)0x0) {
      iVar4 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(p_Var6 + 0x78) = *(undefined8 *)(p_Var5 + 0x80);
      *(undefined8 *)(p_Var6 + 0x70) = *(undefined8 *)(p_Var5 + 0x10);
      iVar4 = WdfIoTargetCreateAndFormatRequestForBrb
                        (0,*(WDFIOTARGET__ **)p_Var5,*(_BTH_PROFILE_DRIVER_INTERFACE **)(p_Var5 + 8)
                         ,p_Var6,&local_res18);
      if (iVar4 < 0) {
        lVar7 = local_res18;
      }
      else {
        p_Var6 = (_BRB *)0x0;
        SetScoState((longlong)p_Var5,(param_2 != 0) + 8);
        lVar7 = local_res18;
        (**(code **)(WdfFunctions_01015 + 0x820))
                  (WdfDriverGlobals,local_res18,ScoCloseCompletionRoutine,param_1);
        cVar2 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                          (WdfDriverGlobals,lVar7,*(undefined8 *)p_Var5,0);
        if (cVar2 == '\0') {
          SetScoState((longlong)p_Var5,0);
          iVar4 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals);
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            bVar1 = false;
          }
          if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_l
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x34,
                       &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar4);
          }
        }
        else {
          iVar4 = 0;
          lVar7 = 0;
        }
      }
      if (lVar7 != 0) {
        SetScoState((longlong)p_Var5,0);
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar7);
      }
      if (p_Var6 != (_BRB *)0x0) {
        (**(code **)(*(longlong *)(p_Var5 + 8) + 0x28))(p_Var6);
      }
    }
  }
  else {
    iVar4 = -0x3ffffff0;
  }
  return iVar4;
}



===== ScoCleanup @ 1400125e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoCleanup(undefined8 param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined *puVar8;
  undefined7 uVar9;
  undefined8 local_res10;
  
  puVar8 = PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  uVar9 = (undefined7)((ulonglong)puVar8 >> 8);
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x29,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  if (lVar3 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x520))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x180));
    (**(code **)(WdfFunctions_01015 + 0xa00))
              (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x148),CONCAT71(uVar9,1));
    (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x168),1);
    (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x1e0),1);
    *(undefined4 *)(lVar3 + 0x6c) = 0;
    ScoChannelClose(param_1,0);
    (**(code **)(WdfFunctions_01015 + 0x520))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x60));
    puVar7 = (undefined8 *)(lVar3 + 0xa0);
    lVar6 = 2;
    do {
      AudioQueue_Stop((WDFQUEUE__ *)*puVar7);
      (**(code **)(WdfFunctions_01015 + 0x520))(WdfDriverGlobals,*puVar7);
      ScoCancelWaitingDataRequests((_SCO_TRANSFER_CONTEXT *)(puVar7 + -3));
      (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,puVar7[6],1);
      if (puVar7[4] != 0) {
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,puVar7[4],0xc0000240);
        puVar7[4] = 0;
      }
      puVar7 = puVar7 + 10;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    local_res10 = 0xfffffffffeced300;
    uVar4 = lVar3 + 0x150;
    iVar2 = KeWaitForSingleObject(uVar4,0,0,0,&local_res10);
    if (iVar2 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (uVar4 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
          (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar4 = *(ulonglong *)(WPP_GLOBAL_Control + 0x18);
        WPP_RECORDER_AND_TRACE_SF_l
                  (uVar4,bVar1,(undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2a,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar2);
      }
      MicrosoftTelemetryAssertTriggeredArgsMsgKM(uVar4,iVar2);
    }
    ScoUpdateAvdtpSuspension(lVar3);
  }
  return;
}



===== ScoConnectionRequest @ 1400128bc =====

void ScoConnectionRequest(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  
  uVar1 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    ScoConnectionRequest_Bug53390280(param_1,param_2);
  }
  else {
    ScoConnectionRequest_FixBug53390280(param_1,param_2);
  }
  return;
}



===== ScoCreate @ 1400128fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ScoCreate(undefined8 param_1,WDFIOTARGET__ *param_2,_BTH_PROFILE_DRIVER_INTERFACE *param_3,
             undefined8 param_4,undefined4 param_5,undefined4 param_6)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  _BRB *p_Var4;
  longlong *plVar5;
  _SCOCONTEXT *p_Var6;
  _BRB *p_Var7;
  longlong lVar8;
  longlong lVar9;
  ulong uVar10;
  undefined1 auStackY_1f8 [32];
  _SCOCONTEXT *local_198;
  undefined4 local_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 local_180;
  undefined4 uStack_17c;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined *local_160;
  _BTH_PROFILE_DRIVER_INTERFACE *local_158;
  undefined8 local_150;
  code *pcStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  longlong local_128;
  longlong local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined1 local_10c [44];
  code *local_e0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 local_ac [84];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_198 = (_SCOCONTEXT *)0x0;
  local_128 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_158 = param_3;
  local_120 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x24,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  local_160 = PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150;
  local_180 = 0;
  uStack_17c = 0;
  uStack_18c = 0;
  uStack_188 = 0;
  uStack_184 = 0;
  local_190 = 0x38;
  local_170 = 0;
  uStack_168 = 0;
  uStack_178 = 0x100000001;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,&local_190,&local_198);
  if (-1 < iVar3) {
    *(WDFIOTARGET__ **)local_198 = param_2;
    *(_BTH_PROFILE_DRIVER_INTERFACE **)(local_198 + 8) = param_3;
    *(undefined8 *)(local_198 + 0x10) = param_4;
    *(undefined4 *)(local_198 + 0x18) = 0x46485442;
    *(undefined4 *)(local_198 + 0x1c) = param_5;
    *(undefined4 *)(local_198 + 0x20) = param_6;
    *(undefined4 *)(local_198 + 0x68) = 0;
    memset(local_10c,0,0x54);
    local_110 = 0;
    local_118 = 0x60;
    local_114 = 3;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_1,&local_118,0);
    if (-1 < iVar3) {
      memset(local_ac,0,0x54);
      local_b0 = 0;
      local_b8 = 0x60;
      local_b4 = 3;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_1,&local_b8,0);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                          (WdfDriverGlobals,&local_190,local_198 + 0x170);
        if (-1 < iVar3) {
          local_130 = 0;
          uStack_138 = 0;
          pcStack_148 = ScoReopenTimer;
          local_180 = 0;
          uStack_17c = 0;
          local_160 = (undefined *)0x0;
          uStack_18c = 0;
          uStack_188 = 0;
          uStack_184 = 0;
          local_150 = 0x28;
          uStack_168 = 0;
          local_140 = 0x100000000;
          local_190 = 0x38;
          uStack_178 = 0x100000002;
          local_170 = param_1;
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                            (WdfDriverGlobals,&local_150,&local_190,local_198 + 0x148);
          if (-1 < iVar3) {
            local_130 = 0;
            uStack_138 = 0;
            pcStack_148 = ScoIdleTimer;
            local_180 = 0;
            uStack_17c = 0;
            local_160 = (undefined *)0x0;
            uStack_18c = 0;
            uStack_188 = 0;
            uStack_184 = 0;
            local_150 = 0x28;
            uStack_168 = 0;
            local_140 = 0x100000000;
            local_190 = 0x38;
            uStack_178 = 0x100000002;
            local_170 = param_1;
            iVar3 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                              (WdfDriverGlobals,&local_150,&local_190,local_198 + 0x168);
            if (-1 < iVar3) {
              local_130 = 0;
              uStack_138 = 0;
              pcStack_148 = ScoAvdtpUnsuspendDelayTimer;
              local_180 = 0;
              uStack_17c = 0;
              local_160 = (undefined *)0x0;
              uStack_18c = 0;
              uStack_188 = 0;
              uStack_184 = 0;
              local_150 = 0x28;
              uStack_168 = 0;
              local_140 = 0x100000000;
              local_190 = 0x38;
              uStack_178 = 0x100000002;
              local_170 = param_1;
              iVar3 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                                (WdfDriverGlobals,&local_150,&local_190,local_198 + 0x128);
              if (-1 < iVar3) {
                local_130 = 0;
                uStack_138 = 0;
                pcStack_148 = ScoTransitionWatchdogTimer;
                local_180 = 0;
                uStack_17c = 0;
                local_160 = (undefined *)0x0;
                uStack_18c = 0;
                uStack_188 = 0;
                uStack_184 = 0;
                local_150 = 0x28;
                uStack_168 = 0;
                local_140 = 0x100000000;
                local_190 = 0x38;
                uStack_178 = 0x100000002;
                local_170 = param_1;
                iVar3 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                                  (WdfDriverGlobals,&local_150,&local_190,local_198 + 0x1e0);
                if (-1 < iVar3) {
                  p_Var4 = (_BRB *)(**(code **)(param_3 + 0x20))(0x209,0x46485442);
                  if (p_Var4 == (_BRB *)0x0) {
                    iVar3 = -0x3fffff66;
                  }
                  else {
                    iVar3 = WdfIoTargetCreateAndFormatRequestForBrb
                                      (0,param_2,param_3,p_Var4,&local_128);
                    lVar1 = local_128;
                    p_Var7 = p_Var4;
                    if (-1 < iVar3) {
                      p_Var7 = (_BRB *)0x0;
                      uStack_50 = 0;
                      local_58 = 0x200000010;
                      cVar2 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                                        (WdfDriverGlobals,local_128,param_2,&local_58);
                      if (cVar2 == '\0') {
                        iVar3 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,lVar1);
                      }
                      else {
                        *(undefined4 *)(local_198 + 0x40) = *(undefined4 *)(p_Var4 + 0x70);
                        *(undefined2 *)(local_198 + 0x44) = *(undefined2 *)(p_Var4 + 0x7c);
                        *(undefined2 *)(local_198 + 0x46) = *(undefined2 *)(p_Var4 + 0x7e);
                        ScoGetControllerSupportedCodecs(local_198);
                        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
                           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
                          cVar2 = '\0';
                        }
                        else {
                          cVar2 = '\x01';
                        }
                        if ((cVar2 != '\0') ||
                           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                          WPP_RECORDER_AND_TRACE_SF_LHH
                                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                                     (undefined **)WPP_RECORDER_INITIALIZED !=
                                     &WPP_RECORDER_INITIALIZED,
                                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                        }
                        KeInitializeEvent(local_198 + 0x130,0,0);
                        KeInitializeEvent(local_198 + 0x150,0,1);
                        uVar10 = 0;
                        lVar9 = 0xa0;
                        do {
                          *(ulong *)(local_198 + lVar9 + -0x18) = uVar10;
                          local_160 = (undefined *)0x0;
                          local_180 = 0;
                          uStack_17c = 0;
                          uStack_178 = 0x100000001;
                          uStack_18c = 0;
                          uStack_188 = 0;
                          uStack_184 = 0;
                          uStack_168 = 0;
                          local_190 = 0x38;
                          lVar8 = (longlong)(int)uVar10 * 0x50;
                          local_170 = param_1;
                          iVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                                            (WdfDriverGlobals,&local_190,local_198 + lVar8 + 0xb0);
                          if (iVar3 < 0) goto LAB_1400132a7;
                          local_160 = (undefined *)0x0;
                          local_180 = 0;
                          uStack_17c = 0;
                          uStack_178 = 0x100000001;
                          uStack_18c = 0;
                          uStack_188 = 0;
                          uStack_184 = 0;
                          local_190 = 0x38;
                          uStack_168 = 0;
                          local_170 = param_1;
                          iVar3 = (**(code **)(WdfFunctions_01015 + 0x68))
                                            (WdfDriverGlobals,&local_190,local_198 + lVar8 + 0xb8);
                          if (iVar3 < 0) goto LAB_1400132a7;
                          memset(&local_118,0,0x60);
                          local_110 = 0;
                          local_e0 = ScoDataQueue_EvtIoStop;
                          local_118 = 0x60;
                          local_180 = 0;
                          uStack_17c = 0;
                          local_114 = 3;
                          uStack_178 = 0x100000001;
                          local_160 = PTR__WDF_PSCO_TRANSFER_CONTEXT_TYPE_INFO_1400221a0;
                          uStack_18c = 0;
                          uStack_188 = 0;
                          uStack_184 = 0;
                          local_190 = 0x38;
                          local_170 = 0;
                          uStack_168 = 0;
                          iVar3 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                            (WdfDriverGlobals,param_1,&local_118,&local_190);
                          if (iVar3 < 0) goto LAB_1400132a7;
                          p_Var6 = local_198 + lVar8 + 0x88;
                          plVar5 = (longlong *)
                                   (**(code **)(WdfFunctions_01015 + 0x650))
                                             (WdfDriverGlobals,*(undefined8 *)(local_198 + lVar9),
                                              PTR__WDF_PSCO_TRANSFER_CONTEXT_TYPE_INFO_1400221a0);
                          *plVar5 = (longlong)p_Var6;
                          iVar3 = (**(code **)(WdfFunctions_01015 + 0x530))
                                            (WdfDriverGlobals,*(undefined8 *)(local_198 + lVar9),
                                             ScoAudioDataQueueReady,0);
                          if (iVar3 < 0) goto LAB_1400132a7;
                          uStack_17c = 0;
                          local_130 = 0;
                          uStack_168 = 0;
                          pcStack_148 = ScoDataCompletionTimer;
                          local_160 = PTR__WDF_PSCO_TRANSFER_CONTEXT_TYPE_INFO_1400221a0;
                          uStack_138 = 0;
                          local_150 = 0x28;
                          local_140 = 0x100000000;
                          uStack_18c = 0;
                          uStack_188 = 0;
                          uStack_184 = 0;
                          local_180 = 0;
                          local_190 = 0x38;
                          uStack_178 = 0x100000002;
                          local_170 = param_1;
                          iVar3 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                                            (WdfDriverGlobals,&local_150,&local_190,
                                             local_198 + lVar8 + 0xd0);
                          if (iVar3 < 0) goto LAB_1400132a7;
                          iVar3 = AudioQueue_MakeAndInitialize
                                            (*(WDFQUEUE__ **)(local_198 + lVar9),uVar10);
                          if (iVar3 < 0) goto LAB_1400132a7;
                          p_Var6 = local_198 + lVar8 + 0x88;
                          plVar5 = (longlong *)
                                   (**(code **)(WdfFunctions_01015 + 0x650))
                                             (WdfDriverGlobals,
                                              *(undefined8 *)(local_198 + lVar9 + 0x30),
                                              PTR__WDF_PSCO_TRANSFER_CONTEXT_TYPE_INFO_1400221a0);
                          lVar9 = lVar9 + 0x50;
                          uVar10 = uVar10 + 1;
                          *plVar5 = (longlong)p_Var6;
                        } while (uVar10 < 2);
                        iVar3 = 0;
                        *(undefined4 *)(local_198 + 0x24) = 0;
                        local_198[0x28] = (_SCOCONTEXT)0x0;
                        *(undefined4 *)(local_198 + 0x30) = 0;
                        local_198[0x34] = (_SCOCONTEXT)0x0;
                        if ((*(longlong *)(local_120 + 0x120) == 0x4919f655be446647) &&
                           (*(longlong *)(local_120 + 0x128) == 0x65ced4a55b12d08b)) {
                          local_198[0x3a] = (_SCOCONTEXT)0x1;
                          local_198[0x3b] = (_SCOCONTEXT)0x10;
                        }
                        else {
                          local_198[0x3a] = (_SCOCONTEXT)0x0;
                          local_198[0x3b] = (_SCOCONTEXT)0x0;
                        }
LAB_1400132a7:
                        param_3 = local_158;
                      }
                    }
                    if (lVar1 != 0) {
                      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar1);
                    }
                    if (p_Var7 != (_BRB *)0x0) {
                      (**(code **)(param_3 + 0x28))(p_Var7);
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
  return iVar3;
}



===== ScoHandleServiceScoRequestAcknowledgementRequest @ 140013314 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoHandleServiceScoRequestAcknowledgementRequest(WDFDEVICE__ *param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  SCOSTATE SVar3;
  long lVar4;
  _SCOCONTEXT *p_Var5;
  char cVar6;
  undefined8 uVar7;
  bool bVar8;
  int *local_58 [3];
  
  p_Var5 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  local_58[0] = (int *)0x0;
  lVar4 = 0;
  bVar8 = true;
  cVar1 = (**(code **)(WdfFunctions_01015 + 0xa00))
                    (WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x1e0),1);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,local_58,0);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      bVar8 = false;
    }
    if ((bVar8 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar8,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x7e,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar2);
    }
    goto LAB_14001384c;
  }
  SVar3 = GetScoState(p_Var5);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATIONlSCOSTATEl
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (*local_58[0] - 4U < 2) {
    if ((char)local_58[0][1] == '\0') {
      lVar4 = -0x3fffffde;
    }
    else if (SVar3 == 5) {
      if (cVar1 != '\0') {
        lVar4 = ScoChannelOpenAsync(param_1);
        iVar2 = lVar4;
        goto LAB_1400137a3;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
        bVar8 = false;
      }
      if ((bVar8 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar8,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x7a,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
      lVar4 = -0x3fffff4b;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
        bVar8 = false;
      }
      if ((bVar8) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATIONSCOSTATEd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar8,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      lVar4 = -0x3ffffe7c;
    }
  }
  else {
    if (*local_58[0] != 6) goto LAB_14001384c;
    if (SVar3 == 6) {
      if (((char)local_58[0][1] == '\0') || (cVar1 == '\0')) {
        bVar8 = true;
        lVar4 = -0x3fffffde;
      }
      else {
        uVar7 = 7;
        SetScoState((longlong)p_Var5,7);
        WdfIoQueueFindAndCompleteIoctlRequest(*(undefined8 *)(p_Var5 + 0x60),uVar7,0x22002b,0);
        WdfIoQueueFindAndCompleteIoctlRequest(*(undefined8 *)(p_Var5 + 0x60),uVar7,0x2a0018,iVar2);
        if (*(longlong *)(p_Var5 + 0x70) == 0) {
          if (*(int *)(p_Var5 + 0x6c) != 0) goto LAB_14001356e;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
            cVar1 = '\0';
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
             (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
            bVar8 = false;
          }
          if ((cVar1 != '\0') || (bVar8 != false)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,bVar8,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x7c,
                       &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
          }
          uVar7 = 0xfffffffffd050f80;
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
            cVar1 = '\0';
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
             (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
            bVar8 = false;
          }
          if ((cVar1 != '\0') || (bVar8 != false)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,bVar8,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x7b,
                       &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
          }
          uVar7 = 0xfffffffffa0a1f00;
        }
        (**(code **)(WdfFunctions_01015 + 0x9f8))
                  (WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x168),uVar7);
LAB_14001356e:
        bVar8 = false;
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
        bVar8 = false;
      }
      if ((bVar8 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar8,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x7d,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
      if (*(int *)(p_Var5 + 0x6c) == 0) goto LAB_14001356e;
      ScoHandleStreamFailure(-0x3fffff63,param_1);
      bVar8 = false;
    }
    iVar2 = 0;
    if (bVar8) {
      ScoChannelClose(param_1,0);
      iVar2 = 0;
    }
LAB_1400137a3:
    if (-1 < lVar4) goto LAB_14001384c;
  }
  if (*(code **)(p_Var5 + 0x198) != (code *)0x0) {
    (**(code **)(p_Var5 + 0x198))(lVar4,param_1);
  }
LAB_14001384c:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  return;
}



===== ScoHandleServiceScoStatusIndicationRequest @ 14001388c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoHandleServiceScoStatusIndicationRequest(undefined8 param_1,longlong param_2)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  char cVar5;
  undefined4 uVar6;
  int local_res18 [2];
  undefined8 local_res20;
  _SCOCONTEXT local_38 [16];
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x73,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  local_res18[0] = 0;
  (**(code **)(WdfFunctions_01015 + 0x4c8))
            (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x180),local_res18,0);
  if (local_res18[0] == 0) {
    local_res20 = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,4,&local_res20,0);
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                          (WdfDriverGlobals,param_2,*(undefined8 *)(lVar3 + 0x180)), -1 < iVar2)) {
      uVar6 = 0;
      param_2 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x170));
      if (*(int *)(lVar3 + 0x18c) != 0) {
        puVar4 = (undefined4 *)
                 RetrieveServiceScoStatusRequestForIndication
                           (local_38,(_BTHHF_SCO_STATUS_INDICATION)lVar3);
        uVar6 = *puVar4;
        param_2 = *(longlong *)(puVar4 + 2);
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x170));
      if (param_2 == 0) {
        return;
      }
      goto LAB_1400139e4;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x74,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)local_res18[0]);
    }
  }
  uVar6 = 0xc0000010;
LAB_1400139e4:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar6);
  return;
}



===== ScoIsMsbcSupported @ 140013b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ScoIsMsbcSupported(undefined8 param_1)

{
  bool bVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar1 = true;
  if ((((*(uint *)(lVar2 + 0x40) & 2) == 0) || ((*(byte *)(lVar2 + 0x46) & 8) == 0)) ||
     ((*(byte *)(lVar2 + 0x44) & 0x48) != 8)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_il
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return uVar3;
}



===== ScoMpmSuspendStatusCallback @ 140013bb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoMpmSuspendStatusCallback(undefined8 param_1,int param_2)

{
  longlong lVar1;
  char cVar2;
  WDFSPINLOCK__ local_res18 [16];
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x37,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_2);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  wil::acquire_wdf_spin_lock(local_res18);
  *(int *)(lVar1 + 0x1cc) = param_2;
  wil::details::
  unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
              *)local_res18);
  if (param_2 != 0) {
    KeSetEvent(lVar1 + 0x130,0,0);
  }
  return;
}



===== ScoSetCodecId @ 140013cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoSetCodecId(undefined8 param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  bool bVar5;
  undefined1 in_stack_ffffffffffffffb8;
  undefined7 in_stack_ffffffffffffffb9;
  undefined4 in_stack_ffffffffffffffc0;
  undefined4 in_stack_ffffffffffffffc4;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  bVar5 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_CODECID
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT71(in_stack_ffffffffffffffb9,in_stack_ffffffffffffffb8),
               CONCAT44(in_stack_ffffffffffffffc4,in_stack_ffffffffffffffc0),0x20,
               in_stack_ffffffffffffffd0,(char)param_2);
  }
  *(int *)(lVar1 + 0x68) = param_2;
  *(undefined2 *)(lVar1 + 0x2a) = 0x3c;
  *(undefined2 *)(lVar1 + 0x38) = 2;
  if (param_2 == 1) {
    *(undefined1 *)(lVar1 + 0x30) = 4;
    *(undefined2 *)(lVar1 + 0x36) = 0x10;
    *(undefined4 *)(lVar1 + 0x2c) = 16000;
    *(undefined1 *)(lVar1 + 0x24) = 2;
  }
  else if (param_2 == 2) {
    lVar3 = *(longlong *)(lVar2 + 0x120) + -0x4919f655be446647;
    if (lVar3 == 0) {
      lVar3 = *(longlong *)(lVar2 + 0x128) + -0x65ced4a55b12d08b;
    }
    bVar5 = lVar3 == 0;
    *(char *)(lVar1 + 0x30) = !bVar5 + '\x04';
    *(ushort *)(lVar1 + 0x36) = (-(ushort)bVar5 & 0xfe30) + 0x1e0;
    *(uint *)(lVar1 + 0x2c) = (-(uint)bVar5 & 24000) + 8000;
    *(undefined1 *)(lVar1 + 0x24) = 5;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      bVar5 = false;
    }
    if ((bVar5) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x21,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_2);
    }
  }
  return;
}



===== ScoSetStreamingModeForHf @ 140013ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ScoSetStreamingModeForHf(undefined8 param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined4 uVar4;
  char cVar5;
  
  uVar4 = 0xc0000010;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  if (param_2 == 0) {
    uVar4 = 0;
    LOCK();
    *(undefined4 *)(lVar1 + 0x6c) = 0;
    UNLOCK();
    cVar5 = '\x01';
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar3 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar5 = '\0';
    }
    if ((cVar3 != '\0') || (cVar5 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar5,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x71,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x9f8))
              (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x168),0xfffffffffd050f80);
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
    if (*(longlong *)(lVar2 + 0x80) != 0) {
      uVar4 = 0;
      LOCK();
      *(undefined4 *)(lVar1 + 0x6c) = 1;
      UNLOCK();
    }
  }
  ScoUpdateAvdtpSuspension(lVar1);
  return uVar4;
}



===== ScoStreamCloseRequest @ 14001400c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoStreamCloseRequest(undefined8 param_1,ulonglong param_2)

{
  bool bVar1;
  bool bVar2;
  SCOSTATE SVar3;
  int iVar4;
  _SCOCONTEXT *p_Var5;
  undefined8 *puVar6;
  longlong lVar7;
  char cVar8;
  undefined8 uVar9;
  uint7 uVar10;
  WDFSPINLOCK__ local_res18 [8];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68 [4];
  undefined8 local_48 [4];
  
  uVar9 = param_1;
  p_Var5 = (_SCOCONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar1 = false;
  bVar2 = false;
  LOCK();
  iVar4 = *(int *)(p_Var5 + 0x6c);
  *(int *)(p_Var5 + 0x6c) = 0;
  UNLOCK();
  cVar8 = '\x01';
  uVar10 = (uint7)((ulonglong)uVar9 >> 8);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    lVar7 = (ulonglong)uVar10 << 8;
  }
  else {
    lVar7 = CONCAT71(uVar10,1);
  }
  if (((char)lVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
     ) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)lVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x4c,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  if (iVar4 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar8 = '\0';
    }
    if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x4d,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
    goto LAB_140014463;
  }
  WdfIoQueueFindAndCompleteIoctlRequest(*(undefined8 *)(p_Var5 + 0x60),lVar7,0x220033,0xc0000240);
  puVar6 = AudioQueue_StreamStop(local_68,*(WDFQUEUE__ **)(p_Var5 + 0xa0));
  local_88 = *puVar6;
  uStack_80 = puVar6[1];
  local_78 = puVar6[2];
  local_70 = *(undefined4 *)(puVar6 + 3);
  puVar6 = AudioQueue_StreamStop(local_48,*(WDFQUEUE__ **)(p_Var5 + 0xf0));
  local_a8 = *puVar6;
  uStack_a0 = puVar6[1];
  local_98 = puVar6[2];
  local_90 = *(undefined4 *)(puVar6 + 3);
  LogScoInStreamStats(p_Var5,(AudioQueueStreamStats *)&local_a8);
  LogScoOutStreamStats(p_Var5,(AudioQueueStreamStats *)&local_88);
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                    (WdfDriverGlobals,param_2,*(undefined8 *)(p_Var5 + 0x60));
  if (-1 < iVar4) {
    SVar3 = GetScoState(p_Var5);
    iVar4 = 0;
    if (SVar3 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
        cVar8 = '\0';
      }
      if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        param_2 = CONCAT71(0x14001df,cVar8);
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x4e,
                   &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
      }
    }
    else if (SVar3 == 7) {
LAB_1400143bf:
      param_2 = 0;
      iVar4 = ScoChannelClose(param_1,0);
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           (param_2 = CONCAT71((int7)(param_2 >> 8),1), (byte)WPP_GLOBAL_Control[0x29] < 3)) {
          param_2 = param_2 & 0xffffffffffffff00;
        }
        if (((char)param_2 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_l
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)param_2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x50,
                     &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar4);
        }
        LOCK();
        *(undefined4 *)(p_Var5 + 0x6c) = 1;
        UNLOCK();
      }
      else {
LAB_14001444c:
        if (!bVar2) goto LAB_140014463;
      }
    }
    else {
      if (SVar3 == 4) {
        param_2 = *(ulonglong *)(p_Var5 + 0x170);
        wil::acquire_wdf_spin_lock(local_res18);
        if (*(longlong *)(p_Var5 + 0x1d0) == 0) {
          bVar1 = true;
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar8 = '\0';
          }
          if ((cVar8 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x4f,
                       &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
          }
          lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x1d0),
                             PTR__WDF_SCO_OPEN_CONTEXT_TYPE_INFO_140022178);
          bVar2 = true;
          *(undefined4 *)(lVar7 + 0x10) = 0;
          param_2 = *(ulonglong *)(p_Var5 + 0x1d0);
          (**(code **)(WdfFunctions_01015 + 0x670))
                    (WdfDriverGlobals,param_2,0,0xa5e,
                     "onecoreuap\\drivers\\wdm\\audio\\drivers\\bluetooth\\bthhfenum\\bthscoserver.cpp"
                    );
          *(undefined8 *)(p_Var5 + 0x1d0) = 0;
        }
        wil::details::
        unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
        ::
        ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
                  ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
                    *)local_res18);
        iVar4 = 0;
        if (bVar1) goto LAB_1400143bf;
        goto LAB_14001444c;
      }
      iVar4 = -0x3ffffff0;
    }
  }
  WdfIoQueueFindAndCompleteIoctlRequest(*(undefined8 *)(p_Var5 + 0x60),param_2,0x22002f,iVar4);
LAB_140014463:
  ScoUpdateAvdtpSuspension((longlong)p_Var5);
  return;
}



===== ScoUserDisconnectRequest @ 140014494 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong ScoUserDisconnectRequest(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  longlong lVar5;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x27,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  ObfReferenceObject(param_2);
  LOCK();
  lVar1 = *(longlong *)(lVar3 + 0x70);
  *(longlong *)(lVar3 + 0x70) = param_2;
  UNLOCK();
  lVar5 = 0;
  if (*(int *)(lVar3 + 0x178) != 0) {
    iVar2 = ScoChannelClose(param_1,0);
    if (-1 < iVar2) goto LAB_140014573;
  }
  LOCK();
  lVar5 = *(longlong *)(lVar3 + 0x70);
  *(longlong *)(lVar3 + 0x70) = 0;
  UNLOCK();
LAB_140014573:
  ScoSetCodecId(param_1,0);
  if (lVar5 != 0) {
    KeSetEvent(lVar5,0,0);
    ObfDereferenceObject(lVar5);
  }
  if (lVar1 != 0) {
    ObfDereferenceObject(lVar1);
  }
  return lVar1;
}



===== WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATION @ 1400145d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATION
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x75,
               &uStack0000000000000048,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x75,
                    &uStack0000000000000048,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATIONSCOSTATEd @ 140014680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATIONSCOSTATEd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x79,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x79,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATIONlSCOSTATEl @ 140014768 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_BTHHF_SCO_STATUS_INDICATIONlSCOSTATEl
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x78,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x78,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_CODECID @ 140014870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_CODECID
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,&param_9,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,&param_9,4,
                    0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_SCOSTATE @ 140014920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_SCOSTATE
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,&param_9,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,
                    &param_9,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_DLLDCODECIDDDl @ 1400149d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DLLDCODECIDDDl
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
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x2b,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
               &uStack0000000000000078,4,&uStack0000000000000080,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x2b,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                    &uStack0000000000000078,4,&uStack0000000000000080,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPSCOSTATE @ 140014b6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPSCOSTATE
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,&param_9,4,
               &param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,
                    &param_9,4,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPd @ 140014c44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x49,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x49,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPdSCOSTATE @ 140014d10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_IOCTL_BTHHFPdSCOSTATE
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x46,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x46,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LHH @ 140014dfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LHH(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x25,
               &uStack0000000000000048,4,&uStack0000000000000050,2,&uStack0000000000000058,2,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x25,
                    &uStack0000000000000048,4,&uStack0000000000000050,2,&uStack0000000000000058,2,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_SCOSTATEd @ 140014ef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_SCOSTATEd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,&param_9,4,
               &param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,&param_9,4,
                    &param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_SCOSTATEdq @ 140014fc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_SCOSTATEdq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x19,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x19,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,8,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_ddddd @ 1400150b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_ddddd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x2c,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x2c,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_i @ 1400151e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_i
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,&param_9,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,
                    &param_9,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_id @ 140015298 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_id(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x87,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x87,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_ii @ 14001536c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_ii
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,&param_9,8,
               &param_10,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,param_7,
                    &param_9,8,&param_10,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_il @ 140015444 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_il(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x26,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x26,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_iq @ 140015518 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_iq(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x86,
               &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x86,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qCODECIDCODECID @ 1400155e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qCODECIDCODECID
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x31,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x31,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qSCOSTATE @ 1400156d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qSCOSTATE
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x33,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x33,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qSCOSTATECODECID @ 1400157ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qSCOSTATECODECID
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x2e,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x2e,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qd @ 1400158a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x35,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,5,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x35,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qi @ 140015974 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qi(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x89,
               &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,5,&WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,0x89,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  return;
}



===== FxStubDriverUnloadCommon @ 140015a40 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_140022680,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140015a80 =====

void entry(_DRIVER_OBJECT *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140015ab4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_DRIVER_OBJECT *param_1,undefined8 param_2)

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
    _DAT_140022680 = 0x2080000;
    _DAT_140022688 = &DAT_140022730;
    RtlCopyUnicodeString(&DAT_140022680);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_140022680,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_140022938 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_140022680);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400225d8 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 140015c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_140022938 != (code *)0x0) && (DAT_140022938 != FxStubDriverUnload)) {
    (*DAT_140022938)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140015c74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140015c99) */
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
    if ((uint *)0x1400225cf < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_1400225d8 = (undefined *)puVar2;
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



===== FxStubUnbindClasses @ 140015dd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400225d8 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_1400225d8 + 0x50);
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



===== FxGetNextClassBindInfo @ 140015e90 =====

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



===== FxStubInitTypes @ 140015ed8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140015ef5) */
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
    if ((void **)0x1400225ef < ppvVar2) break;
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



===== ~SentRequestCollection @ 140015fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl
   Microsoft::Bluetooth::Foundation::SentRequestCollection::~SentRequestCollection(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Foundation::SentRequestCollection::~SentRequestCollection
          (SentRequestCollection *this)

{
  if (*(longlong *)(this + 8) != 0) {
    Stop(this);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(this + 8));
  }
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return;
}



===== operator_delete @ 140016004 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0x646d4370);
  }
  return;
}



===== `scalar_deleting_destructor' @ 140016030 =====

/* public: virtual void * __ptr64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::_scalar_deleting_destructor_
          (AudioInputQueue *this,uint param_1)

{
  ~AudioInputQueue(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140016070 =====

/* public: virtual void * __ptr64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::_scalar_deleting_destructor_
          (AudioOutputQueue *this,uint param_1)

{
  ~AudioOutputQueue(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1400160b0 =====

/* public: virtual void * __ptr64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::_scalar_deleting_destructor_
          (ByteBuffer *this,uint param_1)

{
  ~ByteBuffer(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1400160e8 =====

/* public: void * __ptr64 __cdecl Microsoft::Bluetooth::Foundation::SentRequestCollection::`scalar
   deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
Microsoft::Bluetooth::Foundation::SentRequestCollection::_scalar_deleting_destructor_
          (SentRequestCollection *this,uint param_1)

{
  ~SentRequestCollection(this);
  operator_delete(this);
  return this;
}



===== Add @ 140016110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl Microsoft::Bluetooth::Foundation::SentRequestCollection::Add(struct
   WDFREQUEST__ * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Foundation::SentRequestCollection::Add
          (SentRequestCollection *this,WDFREQUEST__ *param_1)

{
  long lVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)this);
  if (this[0x10] == (SentRequestCollection)0x0) {
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x78))
                      (WdfDriverGlobals,*(undefined8 *)(this + 8),param_1);
  }
  else {
    lVar1 = -0x3ffffe7c;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)this);
  return lVar1;
}



===== EmptyCompletedScoRequests @ 14001619c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::EmptyCompletedScoRequests(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::EmptyCompletedScoRequests
          (AudioInputQueue *this)

{
  int iVar1;
  undefined8 uVar2;
  WDFSPINLOCK__ local_res8 [32];
  
  wil::acquire_wdf_spin_lock(local_res8);
  while( true ) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(this + 0xf0));
    if (iVar1 == 0) break;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x98))(WdfDriverGlobals,*(undefined8 *)(this + 0xf0));
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,uVar2);
    (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,*(undefined8 *)(this + 0xf0),0);
  }
  wil::details::
  unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFSPINLOCK__*___ptr64,void_(__cdecl*)(WDFSPINLOCK__*___ptr64),&void___cdecl_WdfSpinLockRelease(struct_WDFSPINLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFSPINLOCK__*___ptr64,WDFSPINLOCK__*___ptr64,0,std::nullptr_t>_>
              *)local_res8);
  return;
}



===== EvtObjectContextDestroyThunk @ 140016260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFQUEUE__ * __ptr64,class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy,0>::EvtObjectContextDestroyThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<WDFQUEUE__*___ptr64,Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy,0>
::EvtObjectContextDestroyThunk(void *param_1)

{
  AudioQueueProxy *this;
  
  this = (AudioQueueProxy *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_AudioQueueProxy_TYPE_INFO_1400224a8);
  if (this != (AudioQueueProxy *)0x0) {
    Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::~AudioQueueProxy(this);
  }
  return;
}



===== EvtObjectContextDestroyThunk @ 1400162b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFREQUEST__ * __ptr64,class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueRequestContext,0>::EvtObjectContextDestroyThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<WDFREQUEST__*___ptr64,Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueRequestContext,0>
::EvtObjectContextDestroyThunk(void *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_AudioQueueRequestContext_TYPE_INFO_1400224d0);
  return;
}



===== EvtRequestCancel @ 1400162f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueRequestContext::EvtRequestCancel(struct
   WDFREQUEST__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueRequestContext::EvtRequestCancel
          (WDFREQUEST__ *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_AudioQueueRequestContext_TYPE_INFO_1400224d0)
  ;
  (**(code **)(**(longlong **)(lVar1 + 8) + 0x18))(*(longlong **)(lVar1 + 8),param_1);
  return;
}



===== EvtScoRequestCompletionRoutine @ 140016340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::EvtScoRequestCompletionRoutine(struct
   WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS *
   __ptr64,void * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::EvtScoRequestCompletionRoutine
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  RequestContext *pRVar1;
  WDFIOTARGET__ *pWVar2;
  
  pWVar2 = (WDFIOTARGET__ *)PTR__WDF_RequestContext_TYPE_INFO_1400224f8;
  pRVar1 = (RequestContext *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  ScoRequestCompletionRoutine(param_4,pRVar1,pWVar2,param_3);
  return;
}



===== GetCompletedScoRequestCount @ 140016394 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: unsigned long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::GetCompletedScoRequestCount(void)
   __ptr64 */

ulong __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::GetCompletedScoRequestCount
          (AudioInputQueue *this)

{
  ulong uVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(this + 0xe8));
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(this + 0xf0));
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(this + 0xe8));
  return uVar1;
}



===== GetContextFromObject @ 140016418 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy * __ptr64
   __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject(struct
   WDFQUEUE__ * __ptr64) */

AudioQueueProxy * __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject
          (WDFQUEUE__ *param_1)

{
  AudioQueueProxy *pAVar1;
  
  pAVar1 = (AudioQueueProxy *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_AudioQueueProxy_TYPE_INFO_1400224a8);
  return pAVar1;
}



===== GetFirstCompletedScoRequest @ 14001644c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: class Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext * __ptr64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::GetFirstCompletedScoRequest(void)
   __ptr64 */

RequestContext * __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::GetFirstCompletedScoRequest
          (AudioInputQueue *this)

{
  undefined8 uVar1;
  RequestContext *pRVar2;
  
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(this + 0xe8));
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x98))(WdfDriverGlobals,*(undefined8 *)(this + 0xf0));
  pRVar2 = (RequestContext *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar1,PTR__WDF_RequestContext_TYPE_INFO_1400224f8);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(this + 0xe8));
  return pRVar2;
}



===== GetNumSentScoRequests @ 1400164f8 =====

/* private: int __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::GetNumSentScoRequests(void)const
   __ptr64 */

int __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::GetNumSentScoRequests
          (AudioOutputQueue *this)

{
  uint uVar1;
  
  uVar1 = Foundation::SentRequestCollection::Size(*(SentRequestCollection **)(this + 0xa0));
  return uVar1;
}



===== Remove @ 140016514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl Microsoft::Bluetooth::Foundation::SentRequestCollection::Remove(struct
   WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Foundation::SentRequestCollection::Remove
          (SentRequestCollection *this,WDFREQUEST__ *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)this);
  (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)(this + 8),param_1);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)this);
  return;
}



===== RemoveCompletedScoRequest @ 140016594 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::RemoveCompletedScoRequest(class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::RemoveCompletedScoRequest
          (AudioInputQueue *this,RequestContext *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(this + 0xe8));
  (**(code **)(WdfFunctions_01015 + 0x80))
            (WdfDriverGlobals,*(undefined8 *)(this + 0xf0),*(undefined8 *)param_1);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(this + 0xe8));
  return;
}



===== ScoRequestCompletionRoutine @ 140016620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::ScoRequestCompletionRoutine(struct
   WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS *
   __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::ScoRequestCompletionRoutine
          (AudioInputQueue *this,WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,
          _WDF_REQUEST_COMPLETION_PARAMS *param_3)

{
  uint uVar1;
  int iVar2;
  _GUID *p_Var3;
  _tlgProvider_t *p_Var4;
  SentRequestCollection *this_00;
  _GUID *p_Var5;
  _WDF_REQUEST_COMPLETION_PARAMS *p_Var6;
  undefined4 local_res8 [2];
  undefined4 local_res20 [2];
  WDFREQUEST__ *local_28 [2];
  
  p_Var5 = (_GUID *)PTR__WDF_RequestContext_TYPE_INFO_1400224f8;
  p_Var6 = param_3;
  p_Var3 = (_GUID *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  p_Var4 = (_tlgProvider_t *)WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (p_Var5 = (_GUID *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
      (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    p_Var4 = *(_tlgProvider_t **)(WPP_GLOBAL_Control + 0x18);
    p_Var6 = (_WDF_REQUEST_COMPLETION_PARAMS *)p_Var3;
    WPP_SF_qdq(p_Var4,0x20,p_Var5,p_Var3,(char)*(undefined4 *)(param_3 + 8),(char)this + -0x10);
  }
  if (5 < DAT_140022000) {
    local_res8[0] = *(undefined4 *)(param_3 + 8);
    local_res20[0] = 1;
    local_28[0] = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
              (p_Var4,&DAT_14001f26c,p_Var5,(_GUID *)p_Var6,(_tlgWrapperByVal<8> *)local_28,
               (_tlgWrapperByVal<4> *)local_res20,(_tlgWrapperByVal<4> *)local_res8);
  }
  LOCK();
  *(undefined4 *)(p_Var3 + 0x40) = *(undefined4 *)(param_3 + 8);
  UNLOCK();
  Foundation::SentRequestCollection::Remove(*(SentRequestCollection **)(this + 0xe8),param_1);
  this_00 = *(SentRequestCollection **)(this + 0xe8);
  uVar1 = Foundation::SentRequestCollection::Size(this_00);
  if (uVar1 == 0) {
    *(int *)(this + 0x100) = *(int *)(this + 0x100) + 1;
    if (3 < DAT_140022000) {
      local_res20[0] = 1;
      local_res8[0] = *(undefined4 *)(this + 0x100);
      local_28[0] = param_1;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
                ((_tlgProvider_t *)this_00,&DAT_14001f1b5,p_Var5,(_GUID *)p_Var6,
                 (_tlgWrapperByVal<8> *)local_28,(_tlgWrapperByVal<4> *)local_res20,
                 (_tlgWrapperByVal<4> *)local_res8);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(this + 0xd8));
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x78))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0xe0),*(undefined8 *)p_Var3);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(this + 0xd8));
  (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(this + 0xd0));
  if (iVar2 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  }
  return;
}



===== ScoRequestCompletionRoutine @ 14001681c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::ScoRequestCompletionRoutine(class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext * __ptr64,struct WDFIOTARGET__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::ScoRequestCompletionRoutine
          (AudioOutputQueue *this,RequestContext *param_1,WDFIOTARGET__ *param_2,
          _WDF_REQUEST_COMPLETION_PARAMS *param_3)

{
  WDFREQUEST__ *pWVar1;
  uint uVar2;
  _tlgProvider_t *p_Var3;
  SentRequestCollection *this_00;
  RequestContext *pRVar4;
  undefined4 local_res8 [2];
  WDFREQUEST__ *local_res10;
  WDFIOTARGET__ *local_res18 [2];
  
  pWVar1 = *(WDFREQUEST__ **)param_1;
  p_Var3 = (_tlgProvider_t *)WPP_GLOBAL_Control;
  pRVar4 = (RequestContext *)param_3;
  local_res18[0] = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    p_Var3 = *(_tlgProvider_t **)(WPP_GLOBAL_Control + 0x18);
    pRVar4 = param_1;
    WPP_SF_qdq(p_Var3,0xb,param_2,param_1,(char)*(undefined4 *)(param_3 + 8),(char)this);
  }
  if (5 < DAT_140022000) {
    local_res8[0] = 0;
    local_res18[0] = (WDFIOTARGET__ *)CONCAT44(local_res18[0]._4_4_,*(undefined4 *)(param_3 + 8));
    local_res10 = pWVar1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
              (p_Var3,&DAT_14001f4f8,(_GUID *)param_2,(_GUID *)pRVar4,
               (_tlgWrapperByVal<8> *)&local_res10,(_tlgWrapperByVal<4> *)local_res8,
               (_tlgWrapperByVal<4> *)local_res18);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_3 + 8);
  UNLOCK();
  Foundation::SentRequestCollection::Remove(*(SentRequestCollection **)(this + 0xa0),pWVar1);
  this_00 = *(SentRequestCollection **)(this + 0xa0);
  uVar2 = Foundation::SentRequestCollection::Size(this_00);
  if (uVar2 == 0) {
    *(int *)(this + 0xb8) = *(int *)(this + 0xb8) + 1;
    if (3 < DAT_140022000) {
      local_res8[0] = 0;
      local_res18[0] = (WDFIOTARGET__ *)CONCAT44(local_res18[0]._4_4_,*(undefined4 *)(this + 0xb8));
      local_res10 = pWVar1;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
                ((_tlgProvider_t *)this_00,&DAT_14001f440,(_GUID *)param_2,(_GUID *)pRVar4,
                 (_tlgWrapperByVal<8> *)&local_res10,(_tlgWrapperByVal<4> *)local_res8,
                 (_tlgWrapperByVal<4> *)local_res18);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(this + 0x98));
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)param_1);
  return;
}



===== ScoRequestSend @ 140016980 =====

/* private: virtual long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::ScoRequestSend(struct WDFQUEUE__
   * __ptr64,void (__cdecl*)(struct WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ * __ptr64,struct
   _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void * __ptr64),void * __ptr64,struct WDFREQUEST__ *
   __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::ScoRequestSend
          (AudioInputQueue *this,WDFQUEUE__ *param_1,
          _func_void_WDFREQUEST___ptr_WDFIOTARGET___ptr__WDF_REQUEST_COMPLETION_PARAMS_ptr_void_ptr
          *param_2,void *param_3,WDFREQUEST__ *param_4)

{
  long lVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,param_2,param_4,(char)this + -0x10);
  }
  lVar1 = Foundation::SentRequestCollection::Add(*(SentRequestCollection **)(this + 0xe8),param_4);
  if (-1 < lVar1) {
    lVar1 = AudioQueueClient_SendTransferBrb(param_1,param_2,param_3,param_4);
    if (lVar1 < 0) {
      Foundation::SentRequestCollection::Remove(*(SentRequestCollection **)(this + 0xe8),param_4);
    }
    else {
      *(int *)(this + 0xfc) = *(int *)(this + 0xfc) + 1;
    }
  }
  return lVar1;
}



===== Size @ 140016a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: unsigned int __cdecl Microsoft::Bluetooth::Foundation::SentRequestCollection::Size(void)
   __ptr64 */

uint __thiscall
Microsoft::Bluetooth::Foundation::SentRequestCollection::Size(SentRequestCollection *this)

{
  uint uVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)this);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(this + 8));
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)this);
  return uVar1;
}



===== Stop @ 140016ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl Microsoft::Bluetooth::Foundation::SentRequestCollection::Stop(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Foundation::SentRequestCollection::Stop(SentRequestCollection *this)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)this);
  uVar3 = 0;
  while( true ) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(this + 8));
    if (uVar1 <= uVar3) break;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x90))
                      (WdfDriverGlobals,*(undefined8 *)(this + 8),uVar3);
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,uVar2,0,0x72,
               "onecore\\drivers\\bluetooth\\foundation\\lib\\SentRequestCollection.h");
    (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals,uVar2);
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,uVar2,0,0x74,
               "onecore\\drivers\\bluetooth\\foundation\\lib\\SentRequestCollection.h");
    uVar3 = uVar3 + 1;
  }
  this[0x10] = (SentRequestCollection)0x1;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)this);
  return;
}



===== WPP_SF_Dqddq @ 140016c04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqddq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined8 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  undefined4 local_18 [6];
  
  local_18[0] = 2;
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4de776f173d133e87e80f57736d58590_Traceguids,0xc,local_res20,4,
             &param_5,8,&param_6,4,local_18,4,&param_8,8,0);
  return;
}



===== WPP_SF_Dqq @ 140016c94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4de776f173d133e87e80f57736d58590_Traceguids,0x17,local_res20,4,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_PPq @ 140016cfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_PPq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4de776f173d133e87e80f57736d58590_Traceguids,0x15,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_dq @ 140016d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_q @ 140016db4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qDdq @ 140016df8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDdq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4de776f173d133e87e80f57736d58590_Traceguids,0x1d,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_qd @ 140016e6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4de776f173d133e87e80f57736d58590_Traceguids,0x16,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qdq @ 140016ec8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4de776f173d133e87e80f57736d58590_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_qq @ 140016f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4de776f173d133e87e80f57736d58590_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== ByteBuffer @ 140016f88 =====

/* public: __cdecl Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ByteBuffer(char *
   __ptr64,unsigned __int64,bool) __ptr64 */

ByteBuffer * __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ByteBuffer
          (ByteBuffer *this,char *param_1,__uint64 param_2,bool param_3)

{
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)this =
       &_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteWriter__;
  *(undefined ***)(this + 8) =
       &_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteReader__;
  *(char **)(this + 0x10) = param_1;
  *(__uint64 *)(this + 0x18) = param_2;
  this[0x30] = (ByteBuffer)param_3;
  return this;
}



===== ~ByteBuffer @ 140016fc0 =====

/* public: virtual __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::~ByteBuffer(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::~ByteBuffer(ByteBuffer *this)

{
  *(undefined ***)this =
       &_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteWriter__;
  *(undefined ***)(this + 8) =
       &_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteReader__;
  if ((this[0x30] != (ByteBuffer)0x0) && (*(longlong *)(this + 0x10) != 0)) {
    ExFreePoolWithTag(*(longlong *)(this + 0x10),0);
  }
  return;
}



===== AdvanceOutputOffset @ 140017004 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::AdvanceOutputOffset(unsigned __int64)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::AdvanceOutputOffset
          (ByteBuffer *this,__uint64 param_1)

{
  ulonglong uVar1;
  
  uVar1 = *(longlong *)(this + 0x18) - *(longlong *)(this + 0x28);
  if (uVar1 <= param_1) {
    param_1 = uVar1;
  }
  *(__uint64 *)(this + 0x28) = *(longlong *)(this + 0x28) + param_1;
  return;
}



===== GetTransportPacketStride @ 140017028 =====

/* public: unsigned __int64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::GetTransportPacketStride(void)const
   __ptr64 */

__uint64 __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::GetTransportPacketStride
          (TransportFormatter *this)

{
  return *(__uint64 *)(this + 0x18);
}



===== GetUnconsumedBufferLength @ 140017040 =====

/* public: virtual unsigned __int64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::GetUnconsumedBufferLength(void)const
   __ptr64 */

__uint64 __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::GetUnconsumedBufferLength
          (ByteBuffer *this)

{
  return *(longlong *)(this + 0x10) - *(longlong *)(this + 0x20);
}



===== GetUnstoredBufferLength @ 140017050 =====

/* public: virtual unsigned __int64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::GetUnstoredBufferLength(void)const
   __ptr64 */

__uint64 __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::GetUnstoredBufferLength
          (ByteBuffer *this)

{
  return *(longlong *)(this + 0x18) - *(longlong *)(this + 0x20);
}



===== IsEmpty @ 140017060 =====

/* public: virtual bool __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::IsEmpty(void)const __ptr64 */

bool __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::IsEmpty(ByteBuffer *this)

{
  return *(longlong *)(this + 0x10) == *(longlong *)(this + 0x20);
}



===== IsFull @ 140017080 =====

/* public: virtual bool __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::IsFull(void)const __ptr64 */

bool __thiscall Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::IsFull(ByteBuffer *this)

{
  return *(longlong *)(this + 0x18) == *(longlong *)(this + 0x20);
}



===== ReadBytes @ 1400170a0 =====

/* public: virtual unsigned __int64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ReadBytes(char * __ptr64,unsigned
   __int64) __ptr64 */

__uint64 __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ReadBytes
          (ByteBuffer *this,char *param_1,__uint64 param_2)

{
  ulonglong uVar1;
  ulonglong _Size;
  
  _Size = *(longlong *)(this + 0x10) - *(longlong *)(this + 0x20);
  if (param_2 < _Size) {
    _Size = param_2;
  }
  memcpy(param_1,(void *)(*(longlong *)(this + 8) + *(longlong *)(this + 0x20)),_Size);
  uVar1 = *(longlong *)(this + 0x10) - *(longlong *)(this + 0x20);
  if (_Size < uVar1) {
    uVar1 = _Size;
  }
  *(ulonglong *)(this + 0x20) = uVar1 + *(longlong *)(this + 0x20);
  return _Size;
}



===== ReadBytes @ 140017110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned __int64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ReadBytes(class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteWriter * __ptr64) __ptr64 */

__uint64 __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ReadBytes
          (ByteBuffer *this,ByteWriter *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = (*(code *)**(undefined8 **)param_1)
                    (param_1,*(longlong *)(this + 8) + *(longlong *)(this + 0x20),
                     *(longlong *)(this + 0x10) - *(longlong *)(this + 0x20));
  uVar2 = *(longlong *)(this + 0x10) - *(longlong *)(this + 0x20);
  if (uVar1 < uVar2) {
    uVar2 = uVar1;
  }
  *(ulonglong *)(this + 0x20) = uVar2 + *(longlong *)(this + 0x20);
  return uVar1;
}



===== ResetInputOffset @ 140017164 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ResetInputOffset(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ResetInputOffset(ByteBuffer *this)

{
  *(undefined8 *)(this + 0x20) = 0;
  return;
}



===== ResetOutputOffset @ 140017174 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ResetOutputOffset(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ResetOutputOffset(ByteBuffer *this)

{
  *(undefined8 *)(this + 0x28) = 0;
  return;
}



===== SetBuffer @ 140017184 =====

/* public: void __cdecl Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::SetBuffer(char *
   __ptr64,unsigned __int64,bool) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::SetBuffer
          (ByteBuffer *this,char *param_1,__uint64 param_2,bool param_3)

{
  if ((this[0x30] != (ByteBuffer)0x0) && (*(longlong *)(this + 0x10) != 0)) {
    ExFreePoolWithTag(*(longlong *)(this + 0x10),0);
  }
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(char **)(this + 0x10) = param_1;
  *(__uint64 *)(this + 0x18) = param_2;
  this[0x30] = (ByteBuffer)0x0;
  return;
}



===== WriteBytes @ 1400171f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned __int64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::WriteBytes(class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteReader * __ptr64) __ptr64 */

__uint64 __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::WriteBytes
          (ByteBuffer *this,ByteReader *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = (*(code *)**(undefined8 **)param_1)
                    (param_1,*(longlong *)(this + 0x10) + *(longlong *)(this + 0x20),
                     *(longlong *)(this + 0x18) - *(longlong *)(this + 0x20));
  uVar2 = *(longlong *)(this + 0x18) - *(longlong *)(this + 0x20);
  if (uVar1 < uVar2) {
    uVar2 = uVar1;
  }
  *(ulonglong *)(this + 0x20) = uVar2 + *(longlong *)(this + 0x20);
  return uVar1;
}



===== WriteBytes @ 140017250 =====

/* public: virtual unsigned __int64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::WriteBytes(char const *
   __ptr64,unsigned __int64) __ptr64 */

__uint64 __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::WriteBytes
          (ByteBuffer *this,char *param_1,__uint64 param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong _Size;
  
  _Size = *(longlong *)(this + 0x18) - *(longlong *)(this + 0x20);
  if (param_2 < _Size) {
    _Size = param_2;
  }
  memcpy((void *)(*(longlong *)(this + 0x10) + *(longlong *)(this + 0x20)),param_1,_Size);
  uVar1 = *(longlong *)(this + 0x18) - *(longlong *)(this + 0x20);
  uVar2 = _Size;
  if (uVar1 <= _Size) {
    uVar2 = uVar1;
  }
  *(ulonglong *)(this + 0x20) = uVar2 + *(longlong *)(this + 0x20);
  return _Size;
}



===== ~TransportFormatter @ 1400172b0 =====

/* public: __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::~TransportFormatter(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::~TransportFormatter
          (TransportFormatter *this)

{
  if (*(longlong *)(this + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x20),0x46485442);
  }
  ByteBuffer::~ByteBuffer((ByteBuffer *)(this + 0x28));
  return;
}



===== ~TransportParser @ 1400172ec =====

/* public: __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::~TransportParser(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::~TransportParser
          (TransportParser *this)

{
  if (*(longlong *)(this + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x20),0x46485442);
  }
  ByteBuffer::~ByteBuffer((ByteBuffer *)(this + 0x30));
  return;
}



===== Configure @ 140017328 =====

/* public: long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::Configure(enum
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportPacketHeaderType,unsigned __int64)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::Configure
          (TransportFormatter *this,TransportPacketHeaderType param_1,__uint64 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  long lVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  lVar4 = 0;
  lVar7 = 2;
  if (param_1 != 1) {
    lVar7 = 0;
  }
  uVar6 = (ulonglong)(param_1 == 1) + 1;
  uVar2 = (param_2 - 1) + uVar6 + lVar7;
  lVar3 = uVar2 - uVar2 % uVar6;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    uVar6 = param_2 & 0xffffffff;
    WPP_SF_ddq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,param_2,(int)param_2,(char)lVar3,
               (char)this);
  }
  uVar5 = (undefined1)uVar6;
  lVar1 = ExAllocatePool2(0x40,lVar3,0x46485442);
  if (lVar1 == 0) {
    lVar4 = -0x3fffff66;
  }
  else {
    if (*(longlong *)(this + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(this + 0x20),0x46485442);
    }
    *(TransportPacketHeaderType *)(this + 4) = param_1;
    *(longlong *)(this + 8) = lVar7;
    *(__uint64 *)(this + 0x10) = param_2;
    *(longlong *)(this + 0x18) = lVar3;
    *(longlong *)(this + 0x20) = lVar1;
    *(undefined4 *)(this + 0x60) = 0;
    ByteBuffer::SetBuffer((ByteBuffer *)(this + 0x28),(char *)(lVar1 + lVar7),param_2,(bool)uVar5);
    *(undefined4 *)this = 0;
  }
  return lVar4;
}



===== Configure @ 140017448 =====

/* public: long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::Configure(enum
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportPacketHeaderType,unsigned __int64)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::Configure
          (TransportParser *this,TransportPacketHeaderType param_1,__uint64 param_2)

{
  longlong lVar1;
  long lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar2 = 0;
  lVar6 = 2;
  if (param_1 != 1) {
    lVar6 = 0;
  }
  uVar3 = (ulonglong)(param_1 == 1) + 1;
  uVar4 = (param_2 - 1) + uVar3 + lVar6;
  lVar5 = uVar4 - uVar4 % uVar3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_ddq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,param_2,(int)param_2,(char)lVar5,
               (char)this);
  }
  lVar1 = ExAllocatePool2(0x40,lVar6 + param_2 * 2,0x46485442);
  if (lVar1 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    if (*(longlong *)(this + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(this + 0x20),0x46485442);
    }
    *(TransportPacketHeaderType *)this = param_1;
    *(longlong *)(this + 8) = lVar6;
    *(__uint64 *)(this + 0x10) = param_2;
    *(longlong *)(this + 0x18) = lVar5;
    *(longlong *)(this + 0x20) = lVar1;
    ResetParserState(this);
  }
  return lVar2;
}



===== ReadFrameBytes @ 14001755c =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::ReadFrameBytes(class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteWriter * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::ReadFrameBytes
          (TransportParser *this,ByteWriter *param_1)

{
  undefined1 in_R9B;
  TransportParser *pTVar1;
  
  if (*(int *)(this + 0x28) == 2) {
    ByteBuffer::ReadBytes((ByteBuffer *)(this + 0x38),param_1);
    if (*(longlong *)(this + 0x48) == *(longlong *)(this + 0x58)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        pTVar1 = this;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_5d4f71b1d9a339e3dd758c0f0921e1f4_Traceguids,this);
        in_R9B = SUB81(pTVar1,0);
      }
      *(char **)(this + 0x68) = *(char **)(this + 0x20);
      ByteBuffer::SetBuffer
                ((ByteBuffer *)(this + 0x30),*(char **)(this + 0x20),*(__uint64 *)(this + 0x18),
                 (bool)in_R9B);
      *(undefined4 *)(this + 0x28) = 0;
    }
  }
  return;
}



===== ReadTransportStreamBytes @ 1400175dc =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::ReadTransportStreamBytes(class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteWriter * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::ReadTransportStreamBytes
          (TransportFormatter *this,ByteWriter *param_1)

{
  undefined1 in_R9B;
  TransportFormatter *pTVar1;
  
  if (*(int *)this == 1) {
    ByteBuffer::ReadBytes((ByteBuffer *)(this + 0x30),param_1);
    if (*(longlong *)(this + 0x40) == *(longlong *)(this + 0x50)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        pTVar1 = this;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_5d4f71b1d9a339e3dd758c0f0921e1f4_Traceguids,this);
        in_R9B = SUB81(pTVar1,0);
      }
      ByteBuffer::SetBuffer
                ((ByteBuffer *)(this + 0x28),
                 (char *)(*(longlong *)(this + 0x20) + *(longlong *)(this + 8)),
                 *(__uint64 *)(this + 0x10),(bool)in_R9B);
      *(undefined4 *)this = 0;
    }
  }
  return;
}



===== ResetBuffers @ 14001765c =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::ResetBuffers(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::ResetBuffers
          (TransportFormatter *this)

{
  bool in_R9B;
  
  ByteBuffer::SetBuffer
            ((ByteBuffer *)(this + 0x28),
             (char *)(*(longlong *)(this + 0x20) + *(longlong *)(this + 8)),
             *(__uint64 *)(this + 0x10),in_R9B);
  *(undefined4 *)this = 0;
  return;
}



===== ResetParserState @ 14001768c =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::ResetParserState(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::ResetParserState
          (TransportParser *this)

{
  bool in_R9B;
  
  *(char **)(this + 0x68) = *(char **)(this + 0x20);
  ByteBuffer::SetBuffer
            ((ByteBuffer *)(this + 0x30),*(char **)(this + 0x20),*(__uint64 *)(this + 0x18),in_R9B);
  *(undefined8 *)(this + 0x70) = 0;
  if (this[0x7c] != (TransportParser)0x0) {
    this[0x7c] = (TransportParser)0x0;
  }
  *(undefined4 *)(this + 0x28) = 0;
  return;
}



===== WriteBytesFromTransportStream @ 1400176c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: struct Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::ParseStats
   __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::WriteBytesFromTransportStream(class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteReader * __ptr64) __ptr64 */

ByteReader * __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportParser::WriteBytesFromTransportStream
          (TransportParser *this,ByteReader *param_1)

{
  TransportParser *pTVar1;
  TransportParser TVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  void *_Dst;
  __uint64 _Var6;
  char *pcVar7;
  TransportParser *pTVar8;
  longlong lVar9;
  ByteReader *pBVar10;
  ulonglong uVar11;
  int iVar12;
  TransportParser *pTVar13;
  ByteReader *_Size;
  undefined1 *puVar14;
  longlong lVar15;
  ByteReader *in_R8;
  ByteReader *pBVar16;
  uint uVar17;
  TransportParser *in_R9;
  int iVar18;
  TransportParser *pTVar19;
  undefined8 uStack_f0;
  undefined1 auStack_e8 [32];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  int iStack_b4;
  int local_b0;
  undefined4 uStack_ac;
  undefined8 local_a8 [2];
  undefined1 local_98 [32];
  int *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  puVar14 = auStack_e8;
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  *(undefined8 *)param_1 = 0;
  iVar18 = *(int *)(this + 0x28);
  pBVar16 = in_R8;
  while (iVar18 != 2) {
    iVar18 = 0;
    pcVar4 = *(code **)(*(longlong *)in_R8 + 0x10);
    *(undefined8 *)(puVar14 + -8) = 0x140017722;
    lVar9 = (*pcVar4)();
    if (lVar9 == 0) break;
    if (*(int *)(this + 0x28) == 0) {
      *(undefined8 *)(puVar14 + -8) = 0x140017741;
      ByteBuffer::WriteBytes((ByteBuffer *)(this + 0x30),in_R8);
      in_R9 = *(TransportParser **)(this + 0x68);
      pTVar1 = (TransportParser *)(*(longlong *)(this + 0x40) + *(longlong *)(this + 0x50));
      pTVar19 = in_R9;
      if (*(int *)this == 1) {
        pTVar8 = in_R9;
        pTVar13 = in_R9;
        iVar12 = iVar18;
        while (pTVar19 = pTVar8, pTVar19 < pTVar1) {
          if (*pTVar19 == (TransportParser)0x1) {
            iVar12 = 1;
            if (pTVar19 + 1 < pTVar1) {
              TVar2 = pTVar19[1];
              pBVar16 = (ByteReader *)(ulonglong)(byte)TVar2;
              iVar12 = iVar18;
              if ((((byte)TVar2 & 0xf) == 8) &&
                 (pBVar16 = (ByteReader *)&DAT_14001e340,
                 -1 < *(int *)(&DAT_14001e340 + (ulonglong)((byte)TVar2 >> 4) * 4)))
              goto LAB_1400177a3;
            }
          }
          pTVar13 = pTVar19;
          pTVar8 = pTVar19 + 1;
        }
      }
      else {
LAB_1400177a3:
        iVar12 = 2;
        pTVar13 = pTVar19;
      }
      lVar9 = *(longlong *)(this + 0x80);
      if (iVar12 == 2) {
        lVar15 = (longlong)pTVar13 - (longlong)in_R9;
        *(longlong *)(this + 0x80) = lVar9 + lVar15;
        pTVar19 = pTVar13 + *(longlong *)(this + 8);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar17 = *(uint *)(this + 0x80);
          in_R9 = (TransportParser *)(ulonglong)uVar17;
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(TransportParser **)(puVar14 + 0x20) = this;
          *(undefined8 *)(puVar14 + -8) = 0x140017810;
          WPP_SF_dq(uVar5,0xe,&WPP_5d4f71b1d9a339e3dd758c0f0921e1f4_Traceguids,uVar17,puVar14[0x20])
          ;
        }
        if (*(int *)this == 1) {
          iVar18 = *(int *)(&DAT_14001e340 + (ulonglong)((byte)pTVar13[1] >> 4) * 4);
          if (((this[0x7c] != (TransportParser)0x0) && (iVar18 != *(int *)(this + 0x78))) &&
             (*(int *)param_1 = *(int *)param_1 + 1, 3 < DAT_140022000)) {
            local_a8[0] = *(undefined8 *)(this + 0x80);
            if (this[0x7c] == (TransportParser)0x0) {
              pcVar4 = (code *)swi(0x2c);
              (*pcVar4)();
              puVar14 = puVar14 + 8;
            }
            local_b8 = *(undefined4 *)(this + 0x78);
            iStack_b4 = iVar18;
            local_58 = local_a8;
            in_R9 = (TransportParser *)0x0;
            local_50 = 8;
            local_68 = &local_b8;
            local_60 = 4;
            local_78 = &iStack_b4;
            *(undefined1 **)(puVar14 + 0x28) = local_98;
            *(undefined4 *)(puVar14 + 0x20) = 5;
            local_70 = 4;
            *(undefined8 *)(puVar14 + -8) = 0x1400178c0;
            _tlgWriteTransfer_EtwWriteTransfer
                      (0x140022000,&DAT_14001f582,0,0,*(undefined4 *)(puVar14 + 0x20),
                       *(undefined8 **)(puVar14 + 0x28));
          }
          uStack_ac = CONCAT31(uStack_ac._1_3_,1);
          local_b0 = (iVar18 + 1) % 4;
          *(ulonglong *)(this + 0x78) = CONCAT44(uStack_ac,local_b0);
        }
        pBVar16 = (ByteReader *)(*(longlong *)(this + 0x18) - *(longlong *)(this + 8));
        *(undefined8 *)(this + 0x80) = 0;
        *(TransportParser **)(this + 0x70) = pTVar19;
        *(undefined8 *)(puVar14 + -8) = 0x1400178fa;
        ByteBuffer::SetBuffer
                  ((ByteBuffer *)(this + 0x30),(char *)pTVar19,(__uint64)pBVar16,SUB81(in_R9,0));
        uVar11 = *(longlong *)(this + 0x48) - *(longlong *)(this + 0x50);
        if ((ulonglong)((longlong)pTVar1 - (longlong)pTVar19) < uVar11) {
          uVar11 = (longlong)pTVar1 - (longlong)pTVar19;
        }
        *(ulonglong *)(this + 0x50) = uVar11 + *(longlong *)(this + 0x50);
        *(undefined4 *)(this + 0x28) = 1;
      }
      else if (iVar12 == 1) {
        lVar15 = (longlong)pTVar13 - (longlong)in_R9;
        *(longlong *)(this + 0x80) = lVar9 + lVar15;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar17 = *(uint *)(this + 0x80);
          in_R9 = (TransportParser *)(ulonglong)uVar17;
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(TransportParser **)(puVar14 + 0x20) = this;
          *(undefined8 *)(puVar14 + -8) = 0x140017982;
          WPP_SF_dq(uVar5,0xf,&WPP_5d4f71b1d9a339e3dd758c0f0921e1f4_Traceguids,uVar17,puVar14[0x20])
          ;
        }
        uVar11 = *(longlong *)(this + 0x48) - *(longlong *)(this + 0x58);
        if ((ulonglong)((longlong)pTVar13 - *(longlong *)(this + 0x68)) < uVar11) {
          uVar11 = (longlong)pTVar13 - *(longlong *)(this + 0x68);
        }
        lVar9 = uVar11 + *(longlong *)(this + 0x58);
        *(longlong *)(this + 0x58) = lVar9;
        _Dst = *(void **)(this + 0x40);
        _Size = (ByteReader *)(*(longlong *)(this + 0x48) - lVar9);
        *(undefined8 *)(puVar14 + -8) = 0x1400179b6;
        pBVar16 = _Size;
        memcpy(_Dst,(void *)(lVar9 + (longlong)_Dst),(size_t)_Size);
        *(undefined8 *)(this + 0x58) = 0;
        pBVar10 = *(ByteReader **)(this + 0x48);
        if (_Size < *(ByteReader **)(this + 0x48)) {
          pBVar10 = _Size;
        }
        *(ByteReader **)(this + 0x50) = pBVar10;
        *(undefined8 *)(this + 0x68) = *(undefined8 *)(this + 0x20);
      }
      else {
        lVar15 = (*(longlong *)(this + 0x40) - (longlong)in_R9) + *(longlong *)(this + 0x50);
        *(longlong *)(this + 0x80) = lVar9 + lVar15;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar3 = *(undefined4 *)(this + 0x80);
          uVar17 = (*(int *)(this + 0x50) - *(int *)(this + 0x68)) + *(int *)(this + 0x40);
          in_R9 = (TransportParser *)(ulonglong)uVar17;
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(TransportParser **)(puVar14 + 0x28) = this;
          *(undefined4 *)(puVar14 + 0x20) = uVar3;
          *(undefined8 *)(puVar14 + -8) = 0x140017a2c;
          WPP_SF_ddq(uVar5,0x10,pBVar16,uVar17,puVar14[0x20],puVar14[0x28]);
        }
        *(undefined8 *)(this + 0x50) = 0;
      }
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (int)lVar15;
    }
    if (*(int *)(this + 0x28) == 1) {
      *(undefined8 *)(puVar14 + -8) = 0x140017a4d;
      ByteBuffer::WriteBytes((ByteBuffer *)(this + 0x30),in_R8);
      if (*(longlong *)(this + 0x48) == *(longlong *)(this + 0x50)) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar14 + -8) = 0x140017a88;
          in_R9 = this;
          WPP_SF_q(uVar5,0x11,&WPP_5d4f71b1d9a339e3dd758c0f0921e1f4_Traceguids,this);
        }
        _Var6 = *(__uint64 *)(this + 0x10);
        pcVar7 = *(char **)(this + 0x70);
        *(undefined8 *)(puVar14 + -8) = 0x140017a99;
        ByteBuffer::SetBuffer((ByteBuffer *)(this + 0x30),pcVar7,_Var6,SUB81(in_R9,0));
        uVar11 = *(longlong *)(this + 0x48) - *(longlong *)(this + 0x50);
        if (*(ulonglong *)(this + 0x10) < uVar11) {
          uVar11 = *(ulonglong *)(this + 0x10);
        }
        pBVar16 = (ByteReader *)(uVar11 + *(longlong *)(this + 0x50));
        *(ByteReader **)(this + 0x50) = pBVar16;
        *(undefined4 *)(this + 0x28) = 2;
      }
    }
    iVar18 = *(int *)(this + 0x28);
  }
  *(undefined8 *)(puVar14 + -8) = 0x140017ad6;
  return param_1;
}



===== WriteFrameBytes @ 140017af8 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::WriteFrameBytes(class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteReader * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::WriteFrameBytes
          (TransportFormatter *this,ByteReader *param_1)

{
  undefined2 *puVar1;
  undefined1 in_R9B;
  TransportFormatter *pTVar2;
  
  if (*(int *)this == 0) {
    ByteBuffer::WriteBytes((ByteBuffer *)(this + 0x28),param_1);
    if (*(longlong *)(this + 0x40) == *(longlong *)(this + 0x48)) {
      puVar1 = *(undefined2 **)(this + 0x20);
      if (*(int *)(this + 4) == 0) {
        *(int *)(this + 0x60) = *(int *)(this + 0x60) + 1;
      }
      else if (*(int *)(this + 4) == 1) {
        *puVar1 = 0x801;
        *(byte *)((longlong)puVar1 + 1) = (&DAT_14001e338)[*(int *)(this + 0x60)] << 4 | 8;
        *(int *)(this + 0x60) = (*(int *)(this + 0x60) + 1) % 4;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        pTVar2 = this;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_5d4f71b1d9a339e3dd758c0f0921e1f4_Traceguids,this);
        in_R9B = SUB81(pTVar2,0);
      }
      ByteBuffer::SetBuffer
                ((ByteBuffer *)(this + 0x28),*(char **)(this + 0x20),*(__uint64 *)(this + 0x18),
                 (bool)in_R9B);
      *(undefined4 *)this = 1;
    }
  }
  return;
}



===== WPP_SF_ddq @ 140017bc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5d4f71b1d9a339e3dd758c0f0921e1f4_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,8,0);
  return;
}



===== `scalar_deleting_destructor' @ 140017c30 =====

/* private: virtual void * __ptr64 __cdecl NullCodec::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall NullCodec::_scalar_deleting_destructor_(NullCodec *this,uint param_1)

{
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::~ByteBuffer
            ((ByteBuffer *)(this + 0x10));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140017c70 =====

/* private: virtual void * __ptr64 __cdecl SbcWbsCodec::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall SbcWbsCodec::_scalar_deleting_destructor_(SbcWbsCodec *this,uint param_1)

{
  ~SbcWbsCodec(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== MakeAndInitialize @ 140017ca8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl SbcWbsCodec::MakeAndInitialize(enum
   SbcWbsCodec::SbcWbsCodecType,class SbcWbsCodec * __ptr64 * __ptr64) */

long __cdecl SbcWbsCodec::MakeAndInitialize(SbcWbsCodecType param_1,SbcWbsCodec **param_2)

{
  long lVar1;
  SbcWbsCodec *this;
  SBC *pSVar2;
  SBC *local_res18;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res18 = (SBC *)0x0;
  local_38 = 0xf00000000;
  uStack_30 = 8;
  local_28 = 1;
  uStack_20 = 0x10000001a;
  if (param_1 == 0) {
    lVar1 = SBC::MakeAndInitializeSbcEncoder((SBC_CONFIG *)&local_38,&local_res18);
  }
  else {
    lVar1 = SBC::MakeAndInitializeSbcDecoder((SBC_CONFIG *)&local_38,&local_res18);
  }
  if (-1 < lVar1) {
    this = (SbcWbsCodec *)ExAllocatePool2(0x40,0xa0,0x646d4370);
    if (this != (SbcWbsCodec *)0x0) {
      *(SBC **)(this + 8) = local_res18;
      *(undefined ***)this = &_vftable_;
      *(SbcWbsCodecType *)(this + 0x10) = param_1;
      *(undefined8 *)(this + 0x18) = 0;
      *(undefined ***)(this + 0x20) =
           &Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::
            _vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteWriter__;
      *(undefined ***)(this + 0x28) =
           &Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::
            _vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteReader__;
      *(undefined8 *)(this + 0x30) = 0;
      *(undefined8 *)(this + 0x38) = 0;
      *(undefined8 *)(this + 0x40) = 0;
      *(undefined8 *)(this + 0x48) = 0;
      this[0x50] = (SbcWbsCodec)0x0;
      *(undefined8 *)(this + 0x58) = 0;
      *(undefined ***)(this + 0x60) =
           &Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::
            _vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteWriter__;
      *(undefined ***)(this + 0x68) =
           &Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::
            _vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteReader__;
      *(undefined8 *)(this + 0x70) = 0;
      *(undefined8 *)(this + 0x78) = 0;
      *(undefined8 *)(this + 0x80) = 0;
      *(undefined8 *)(this + 0x88) = 0;
      this[0x90] = (SbcWbsCodec)0x0;
      *(undefined8 *)(this + 0x98) = 0;
      lVar1 = Initialize(this);
      pSVar2 = (SBC *)0x0;
      if (lVar1 < 0) {
        (**(code **)(*(longlong *)this + 0x40))(this,1);
      }
      else {
        *param_2 = this;
      }
      goto LAB_140017df7;
    }
    lVar1 = -0x3fffff66;
  }
  pSVar2 = local_res18;
LAB_140017df7:
  operator_delete(pSVar2);
  return lVar1;
}



===== EvtObjectContextDestroyThunk @ 140017e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFREQUEST__ * __ptr64,class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext,0>::EvtObjectContextDestroyThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<WDFREQUEST__*___ptr64,Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext,0>
::EvtObjectContextDestroyThunk(void *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RequestContext_TYPE_INFO_1400224f8);
  if (lVar1 != 0) {
    Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::~ByteBuffer
              ((ByteBuffer *)(lVar1 + 8));
  }
  return;
}



===== GetContextFromObject @ 140017e74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext * __ptr64
   __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::GetContextFromObject(struct
   WDFREQUEST__ * __ptr64) */

RequestContext * __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::GetContextFromObject
          (WDFREQUEST__ *param_1)

{
  RequestContext *pRVar1;
  
  pRVar1 = (RequestContext *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RequestContext_TYPE_INFO_1400224f8);
  return pRVar1;
}



===== ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_> @ 140017ea8 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<unsigned
   __int64 * __ptr64,void __cdecl(struct wil::details::kspin_lock_saved_irql const &
   __ptr64),&public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,struct wil::details::kspin_lock_saved_irql,unsigned __int64 *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<unsigned
   __int64 * __ptr64,void __cdecl(struct wil::details::kspin_lock_saved_irql const &
   __ptr64),&public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,struct wil::details::kspin_lock_saved_irql,unsigned __int64 *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
           *this)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (*(longlong *)this != 0) {
    local_18 = *(undefined8 *)this;
    uStack_10 = *(undefined8 *)(this + 8);
    kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  return;
}



===== DecrementPendingRequestCounter @ 140017ed4 =====

/* private: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::DecrementPendingRequestCounter(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::DecrementPendingRequestCounter
          (ScoReader *this)

{
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  local_18 [16];
  
  wil::acquire_kspin_lock((__uint64 *)local_18);
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + -1;
  wil::details::
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
            (local_18);
  return;
}



===== GetPendingRequestCounter @ 140017f08 =====

/* private: int __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::GetPendingRequestCounter(void)const
   __ptr64 */

int __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::GetPendingRequestCounter(ScoReader *this)

{
  int iVar1;
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  local_18 [16];
  
  wil::acquire_kspin_lock((__uint64 *)local_18);
  iVar1 = *(int *)(this + 0x20);
  wil::details::
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
            (local_18);
  return iVar1;
}



===== IncrementPendingRequestCounter @ 140017f3c =====

/* private: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::IncrementPendingRequestCounter(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::IncrementPendingRequestCounter
          (ScoReader *this)

{
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  local_18 [16];
  
  wil::acquire_kspin_lock((__uint64 *)local_18);
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
  wil::details::
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
            (local_18);
  return;
}



===== Release @ 140017f70 =====

/* public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64) */

void __cdecl wil::details::kspin_lock_saved_irql::Release(kspin_lock_saved_irql *param_1)

{
  KeReleaseSpinLock(*(undefined8 *)param_1,param_1[8]);
  return;
}



===== RequestCompletionRoutine @ 140017fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::RequestCompletionRoutine(struct
   WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS *
   __ptr64,void * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::RequestCompletionRoutine
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  DecrementPendingRequestCounter(param_4);
  (**(code **)**(undefined8 **)((longlong)param_4 + 8))
            (*(undefined8 **)((longlong)param_4 + 8),param_1,param_2,param_3);
  return;
}



===== ReturnRequestToPool @ 140017ffc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::ReturnRequestToPool(struct
   WDFREQUEST__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::ReturnRequestToPool
          (WDFREQUEST__ *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== acquire_kspin_lock @ 14001802c =====

/* class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<unsigned __int64 * __ptr64,void __cdecl(struct
   wil::details::kspin_lock_saved_irql const & __ptr64),&public: static void __cdecl
   wil::details::kspin_lock_saved_irql::Release(struct wil::details::kspin_lock_saved_irql const &
   __ptr64),struct wistd::integral_constant<unsigned __int64,2>,struct
   wil::details::kspin_lock_saved_irql,unsigned __int64 * __ptr64,0,std::nullptr_t> > > __cdecl
   wil::acquire_kspin_lock(unsigned __int64 * __ptr64) */

__uint64 * __cdecl wil::acquire_kspin_lock(__uint64 *param_1)

{
  undefined1 uVar1;
  __uint64 in_RDX;
  undefined7 uStack_f;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  *param_1 = in_RDX;
  param_1[1] = CONCAT71(uStack_f,uVar1);
  return param_1;
}



===== BitAllocate @ 140018074 =====

/* public: void __cdecl SBC::SbcControl::BitAllocate(short (* __ptr64 const)[8],int (* __ptr64
   const)[8])const __ptr64 */

void __thiscall SBC::SbcControl::BitAllocate(SbcControl *this,short *param_1,int *param_2)

{
  int iVar1;
  
  if (*(int *)(this + 8) < 2) {
    iVar1 = 0;
    if (0 < *(int *)(this + 0x14)) {
      do {
        distributeBits(this,iVar1,iVar1,param_1,param_2);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(this + 0x14));
    }
  }
  else {
    distributeBits(this,0,1,param_1,param_2);
  }
  return;
}



===== BuildSbcFrame @ 1400180ec =====

/* public: unsigned short __cdecl SBC::SbcControl::BuildSbcFrame(short const (* __ptr64
   const)[8],int const (* __ptr64 const)[8],unsigned short const (* __ptr64 const)[2][8],unsigned
   char * __ptr64) __ptr64 */

ushort __thiscall
SBC::SbcControl::BuildSbcFrame
          (SbcControl *this,short *param_1,int *param_2,ushort *param_3,uchar *param_4)

{
  uchar *puVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  longlong lVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  longlong lVar9;
  int iVar10;
  longlong lVar11;
  
  *(uchar **)(this + 0x28) = param_4;
  *(uchar **)(this + 0x30) = param_4;
  puVar1 = param_4 + 3;
  *puVar1 = '\x0f';
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined2 *)(this + 0x3c) = 0x20;
  putbits(this,8,*(uint *)this);
  if (*(int *)(this + 0x18) % 4 == 0) {
    putbits_with_crc(this,2,*(uint *)(this + 4),puVar1);
    putbits_with_crc(this,2,*(int *)(this + 0x18) + -4 >> 2,puVar1);
    putbits_with_crc(this,2,*(uint *)(this + 8),puVar1);
    putbits_with_crc(this,1,*(uint *)(this + 0xc),puVar1);
    putbits_with_crc(this,1,(uint)(*(int *)(this + 0x1c) == 8),puVar1);
    uVar7 = *(uint *)(this + 0x20);
  }
  else {
    putbits_with_crc(this,8,0,puVar1);
    uVar7 = 0;
  }
  putbits_with_crc(this,8,uVar7,puVar1);
  flush_putbits(this);
  *(longlong *)(this + 0x30) = *(longlong *)(this + 0x30) + 1;
  if (*(int *)(this + 8) == 3) {
    putbits_with_crc(this,*(uint *)(this + 0x1c),(uint)(byte)this[0x10],puVar1);
  }
  iVar10 = *(int *)(this + 0x14);
  iVar4 = 0;
  if (0 < iVar10) {
    do {
      iVar10 = 0;
      if (0 < *(int *)(this + 0x1c)) {
        psVar3 = param_1;
        do {
          putbits_with_crc(this,4,(int)*psVar3,puVar1);
          iVar10 = iVar10 + 1;
          psVar3 = psVar3 + 1;
        } while (iVar10 < *(int *)(this + 0x1c));
      }
      iVar10 = *(int *)(this + 0x14);
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 8;
    } while (iVar4 < iVar10);
  }
  iVar4 = 0;
  if (0 < *(int *)(this + 0x18)) {
    lVar9 = 0;
    do {
      iVar2 = 0;
      lVar11 = 0;
      if (0 < iVar10) {
        puVar6 = (uint *)param_2;
        do {
          iVar10 = 0;
          lVar5 = 0;
          if (0 < *(int *)(this + 0x1c)) {
            puVar8 = puVar6;
            do {
              if (*puVar8 != 0) {
                putbits(this,*puVar8,(uint)param_3[lVar5 + (lVar9 + lVar11) * 8]);
              }
              iVar10 = iVar10 + 1;
              lVar5 = lVar5 + 1;
              puVar8 = puVar8 + 1;
            } while (iVar10 < *(int *)(this + 0x1c));
          }
          iVar10 = *(int *)(this + 0x14);
          iVar2 = iVar2 + 1;
          lVar11 = lVar11 + 1;
          puVar6 = puVar6 + 8;
        } while (iVar2 < iVar10);
      }
      iVar4 = iVar4 + 1;
      lVar9 = lVar9 + 2;
    } while (iVar4 < *(int *)(this + 0x18));
  }
  flush_putbits(this);
  return *(short *)(this + 0x30) - *(short *)(this + 0x28);
}



===== CalculateSbcFrameLength @ 1400182e8 =====

/* public: int __cdecl SBC::SbcControl::CalculateSbcFrameLength(void)const __ptr64 */

int __thiscall SBC::SbcControl::CalculateSbcFrameLength(SbcControl *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 1;
  if (*(int *)(this + 8) < 2) {
    iVar1 = *(int *)(this + 0x14);
  }
  else {
    iVar2 = 0;
    if (*(int *)(this + 8) == 3) {
      iVar2 = 1;
    }
  }
  return (*(int *)(this + 0x1c) * *(int *)(this + 0x14)) / 2 + 4 +
         (*(int *)(this + 0x1c) * iVar2 + *(int *)(this + 0x20) * *(int *)(this + 0x18) * iVar1 + 7)
         / 8;
}



===== ConfigDecode @ 140018348 =====

/* public: long __cdecl SBC::ConfigDecode(struct SBC_CONFIG const & __ptr64) __ptr64 */

long __thiscall SBC::ConfigDecode(SBC *this,SBC_CONFIG *param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = 0;
  memset(this + 0x1028,0,0x500);
  *(undefined8 *)(this + 0x40) = 0;
  bVar1 = IsConfigValid(param_1);
  if (bVar1) {
    *(undefined4 *)(this + 4) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x18);
    *(uint *)(this + 0x14) = (*(int *)(param_1 + 0xc) != 0) + 1;
    *(uint *)this = (-(uint)(param_1[0x1c] != (SBC_CONFIG)0x0) & 0x11) + 0x9c;
    iVar2 = SbcControl::CalculateSbcFrameLength((SbcControl *)this);
    *(int *)(this + 0x40) = iVar2;
    *(undefined4 *)(this + 0x44) = 0x200;
  }
  else {
    lVar3 = -0x3ffffff3;
  }
  return lVar3;
}



===== ConfigEncode @ 1400183f8 =====

/* public: long __cdecl SBC::ConfigEncode(struct SBC_CONFIG const & __ptr64,bool) __ptr64 */

long __thiscall SBC::ConfigEncode(SBC *this,SBC_CONFIG *param_1,bool param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = 0;
  *(undefined8 *)(this + 0x40) = 0;
  bVar3 = IsConfigValid(param_1);
  if (bVar3) {
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x18);
    iVar4 = *(int *)(param_1 + 4);
    *(int *)(this + 0x18) = iVar4;
    *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 0xc);
    iVar1 = *(int *)(param_1 + 0x10);
    *(int *)(this + 0x14) = iVar1;
    *(undefined4 *)(this + 4) = *(undefined4 *)param_1;
    iVar2 = *(int *)(param_1 + 8);
    *(int *)(this + 0x1c) = iVar2;
    *(uint *)this = (-(uint)(param_1[0x1c] != (SBC_CONFIG)0x0) & 0x11) + 0x9c;
    *(int *)(this + 0x40) = iVar2 * iVar1 * iVar4 * 2;
    iVar4 = SbcControl::CalculateSbcFrameLength((SbcControl *)this);
    *(int *)(this + 0x44) = iVar4;
    memset((SbcControl *)(this + 0xce8),0,0x140);
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== Decode @ 1400184ac =====

/* public: long __cdecl SBC::Decode(unsigned char * __ptr64,short (* __ptr64 const)[8][2]) __ptr64
    */

long __thiscall SBC::Decode(SBC *this,uchar *param_1,short *param_2)

{
  longlong lVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  long lVar5;
  int iVar6;
  SBC *pSVar7;
  longlong lVar8;
  int iVar9;
  SBC *pSVar10;
  uint uVar11;
  SBC *pSVar12;
  SBC *pSVar13;
  SBC SVar14;
  int iVar15;
  SBC *pSVar16;
  longlong lVar17;
  int local_res8;
  SBC *local_40;
  
  lVar5 = SbcControl::SetSbcFrame((SbcControl *)this,param_1,(short *)(this + 0x88));
  iVar6 = SbcControl::CalculateSbcFrameLength((SbcControl *)this);
  *(int *)(this + 0x40) = iVar6;
  if (-1 < lVar5) {
    SbcControl::BitAllocate((SbcControl *)this,(short *)(this + 0x88),(int *)(this + 0x48));
    calcLevels(this);
    pSVar10 = this + 0xe28;
    SbcControl::ReadSbcFrameData((SbcControl *)this,(int *)(this + 0x48),(ushort *)pSVar10);
    memset(this + 0xe8,0,0x400);
    local_res8 = 0;
    if (*(int *)(this + 0x14) < 1) {
      iVar6 = *(int *)(this + 0x1c);
    }
    else {
      local_40 = this + 0xa8;
      do {
        iVar9 = 0;
        iVar6 = *(int *)(this + 0x1c);
        if (0 < iVar6) {
          pSVar13 = local_40;
          pSVar16 = pSVar10;
          do {
            iVar15 = 0;
            iVar6 = *(int *)(pSVar13 + -0x60);
            if (((iVar6 != 0) && (*(int *)pSVar13 != 0)) &&
               (sVar2 = *(short *)(&DAT_14001e3cc + (longlong)iVar6 * 2), 0 < *(int *)(this + 0x18))
               ) {
              uVar3 = *(ushort *)(pSVar16 + -0xda0);
              pSVar12 = pSVar16;
              pSVar7 = pSVar13;
              do {
                pSVar7 = pSVar7 + 0x40;
                uVar4 = *(ushort *)pSVar12;
                pSVar12 = pSVar12 + 0x20;
                iVar15 = iVar15 + 1;
                *(int *)pSVar7 =
                     ((((int)((uint)uVar4 * (sVar2 + 0x4000) + (sVar2 + 0x4000) / 2) >>
                       (((char)iVar6 - (char)uVar3) + 0xbU & 0x1f)) + 1 >> 1) -
                     (1 << ((char)uVar3 + 2U & 0x1f))) + 1 >> 1;
              } while (iVar15 < *(int *)(this + 0x18));
            }
            iVar6 = *(int *)(this + 0x1c);
            iVar9 = iVar9 + 1;
            pSVar13 = pSVar13 + 4;
            pSVar16 = pSVar16 + 2;
          } while (iVar9 < iVar6);
        }
        local_res8 = local_res8 + 1;
        local_40 = local_40 + 0x20;
        pSVar10 = pSVar10 + 0x10;
      } while (local_res8 < *(int *)(this + 0x14));
    }
    uVar11 = 0;
    if ((*(int *)(this + 8) == 3) && (iVar9 = 0, 0 < *(int *)(this + 0x18))) {
      lVar17 = 0;
      do {
        SVar14 = this[0x10];
        lVar8 = (longlong)iVar6;
        if (iVar6 != 0) {
          do {
            lVar8 = lVar8 + -1;
            if (((byte)SVar14 & 1) != 0) {
              lVar1 = lVar17 + lVar8;
              iVar6 = *(int *)(this + lVar1 * 4 + 0x108);
              *(int *)(this + lVar1 * 4 + 0x108) = *(int *)(this + lVar1 * 4 + 0xe8) - iVar6;
              *(int *)(this + lVar1 * 4 + 0xe8) = iVar6 + *(int *)(this + lVar1 * 4 + 0xe8);
            }
            SVar14 = (SBC)((byte)SVar14 >> 1);
          } while (lVar8 != 0);
          iVar6 = *(int *)(this + 0x1c);
        }
        iVar9 = iVar9 + 1;
        lVar17 = lVar17 + 0x10;
      } while (iVar9 < *(int *)(this + 0x18));
    }
    if (iVar6 == 4) {
      if (0 < *(int *)(this + 0x18)) {
        do {
          polyPhaseSynthesisSB4(this,uVar11,param_2,(int *)(this + 0x1028));
          uVar11 = uVar11 + 1;
        } while ((int)uVar11 < *(int *)(this + 0x18));
      }
    }
    else if (0 < *(int *)(this + 0x18)) {
      do {
        polyPhaseSynthesisSB8(this,uVar11,param_2,(int *)(this + 0x1028));
        uVar11 = uVar11 + 1;
      } while ((int)uVar11 < *(int *)(this + 0x18));
    }
  }
  return lVar5;
}



===== Encode @ 140018738 =====

/* public: int __cdecl SBC::Encode(short const * __ptr64,unsigned char * __ptr64,unsigned
   char,unsigned char) __ptr64 */

int __thiscall SBC::Encode(SBC *this,short *param_1,uchar *param_2,uchar param_3,uchar param_4)

{
  SBC *pSVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  longlong lVar6;
  SBC *pSVar7;
  int iVar8;
  SBC *pSVar9;
  short *psVar10;
  SBC *pSVar11;
  int iVar12;
  SBC *pSVar13;
  SBC *pSVar14;
  SBC *pSVar15;
  int iVar16;
  SBC *pSVar17;
  int local_res20;
  SBC *local_48;
  
  iVar8 = 0;
  pSVar1 = this + 0x1c;
  if (0 < *(int *)(this + 0x18)) {
    iVar5 = *(int *)pSVar1;
    do {
      iVar12 = *(int *)(this + 0x14);
      iVar16 = 0;
      if (0 < iVar12) {
        do {
          lVar6 = (longlong)iVar16;
          pSVar17 = this + lVar6 * 0xa0 + 0xce8;
          memcpy(this + (lVar6 * 0x50 + (longlong)iVar5 + 0x674) * 2,pSVar17,
                 (longlong)(iVar5 * 9) * 2);
          iVar5 = *(int *)pSVar1;
          iVar12 = *(int *)(this + 0x14);
          psVar10 = param_1 + (iVar5 + -1) * iVar12 + lVar6;
          if (0 < iVar5) {
            do {
              iVar5 = iVar5 + -1;
              *(short *)pSVar17 = *psVar10;
              pSVar17 = pSVar17 + 2;
              iVar12 = *(int *)(this + 0x14);
              psVar10 = psVar10 + -(longlong)iVar12;
            } while (0 < iVar5);
            iVar5 = *(int *)pSVar1;
          }
          iVar16 = iVar16 + 1;
        } while (iVar16 < iVar12);
      }
      if (iVar5 == 4) {
        polyPhaseAnalysisSB4(this,iVar12,iVar8,(short *)(this + 0xce8));
      }
      else {
        polyPhaseAnalysisSB8(this,iVar12,iVar8,(short *)(this + 0xce8));
      }
      iVar5 = *(int *)pSVar1;
      iVar8 = iVar8 + 1;
      param_1 = param_1 + iVar5 * *(int *)(this + 0x14);
    } while (iVar8 < *(int *)(this + 0x18));
  }
  pSVar17 = this + 0x4e8;
  calcScaleFactors(this,*(int *)(this + 0x14),*(int *)pSVar1,(__int64 *)pSVar17,
                   (short *)(this + 0x88));
  if (*(int *)(this + 8) == 3) {
    jointEncode(this);
  }
  SbcControl::BitAllocate((SbcControl *)this,(short *)(this + 0x88),(int *)(this + 0x48));
  calcLevels(this);
  local_res20 = 0;
  if (0 < *(int *)(this + 0x14)) {
    local_48 = this + 0xa8;
    pSVar7 = this + 0xe28;
    do {
      iVar8 = 0;
      if (0 < *(int *)pSVar1) {
        pSVar11 = local_48;
        pSVar13 = pSVar7;
        pSVar14 = pSVar17;
        do {
          if (*(uint *)(pSVar11 + -0x60) != 0) {
            uVar3 = *(uint *)pSVar11;
            iVar5 = 0;
            uVar2 = *(undefined2 *)(pSVar13 + -0xda0);
            if (0 < *(int *)(this + 0x18)) {
              pSVar9 = pSVar14;
              pSVar15 = pSVar13;
              do {
                lVar6 = *(longlong *)pSVar9;
                iVar5 = iVar5 + 1;
                pSVar9 = pSVar9 + 0x80;
                *(short *)pSVar15 =
                     (short)((longlong)
                             ((lVar6 + (1L << ((char)uVar2 + 1U & 0x3f)) * 0x4000) *
                             (ulonglong)uVar3) >> ((char)uVar2 + 0x10U & 0x3f));
                pSVar15 = pSVar15 + 0x20;
              } while (iVar5 < *(int *)(this + 0x18));
            }
          }
          iVar8 = iVar8 + 1;
          pSVar11 = pSVar11 + 4;
          pSVar13 = pSVar13 + 2;
          pSVar14 = pSVar14 + 8;
        } while (iVar8 < *(int *)pSVar1);
      }
      local_res20 = local_res20 + 1;
      local_48 = local_48 + 0x20;
      pSVar17 = pSVar17 + 0x40;
      pSVar7 = pSVar7 + 0x10;
    } while (local_res20 < *(int *)(this + 0x14));
  }
  uVar4 = SbcControl::BuildSbcFrame
                    ((SbcControl *)this,(short *)(this + 0x88),(int *)(this + 0x48),
                     (ushort *)(this + 0xe28),param_2);
  return (int)uVar4;
}



===== GetInputFrameLength @ 1400189e8 =====

/* public: int __cdecl SBC::GetInputFrameLength(void)const __ptr64 */

int __thiscall SBC::GetInputFrameLength(SBC *this)

{
  return *(int *)(this + 0x40);
}



===== GetOutputFrameLength @ 1400189f4 =====

/* public: int __cdecl SBC::GetOutputFrameLength(void)const __ptr64 */

int __thiscall SBC::GetOutputFrameLength(SBC *this)

{
  return *(int *)(this + 0x44);
}



===== IsConfigValid @ 140018a00 =====

/* public: static bool __cdecl SBC::IsConfigValid(struct SBC_CONFIG const & __ptr64) */

bool __cdecl SBC::IsConfigValid(SBC_CONFIG *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = true;
  if (((((*(int *)param_1 == 4) || (*(int *)(param_1 + 0x14) == 2)) ||
       (iVar1 = *(int *)(param_1 + 0xc), iVar1 == 4)) ||
      ((((iVar1 < 2 && (*(int *)(param_1 + 0x10) != 1)) ||
        ((0x10 < (int)*(uint *)(param_1 + 4) ||
         ((param_1[0x1c] == (SBC_CONFIG)0x0 && ((*(uint *)(param_1 + 4) & 3) != 0)))))) ||
       (iVar2 = *(int *)(param_1 + 8), (iVar2 - 4U & 0xfffffffb) != 0)))) ||
     ((iVar3 = *(int *)(param_1 + 0x18), 0x33 < iVar3 - 2U ||
      (((iVar1 < 2 && (iVar2 * 0x10 < iVar3)) || (iVar2 * 0x20 < iVar3)))))) {
    bVar4 = false;
  }
  return bVar4;
}



===== MakeAndInitializeSbcDecoder @ 140018a7c =====

/* public: static long __cdecl SBC::MakeAndInitializeSbcDecoder(struct SBC_CONFIG const &
   __ptr64,class SBC * __ptr64 * __ptr64) */

long __cdecl SBC::MakeAndInitializeSbcDecoder(SBC_CONFIG *param_1,SBC **param_2)

{
  long lVar1;
  SBC *this;
  
  *param_2 = (SBC *)0x0;
  this = (SBC *)ExAllocatePool2(0x40,0x1528,0x646d4370);
  if (this == (SBC *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    memset(this,0,0x1528);
    lVar1 = ConfigDecode(this,param_1);
    if (lVar1 < 0) {
      operator_delete(this);
    }
    else {
      *param_2 = this;
    }
  }
  return lVar1;
}



===== MakeAndInitializeSbcEncoder @ 140018b08 =====

/* public: static long __cdecl SBC::MakeAndInitializeSbcEncoder(struct SBC_CONFIG const &
   __ptr64,class SBC * __ptr64 * __ptr64) */

long __cdecl SBC::MakeAndInitializeSbcEncoder(SBC_CONFIG *param_1,SBC **param_2)

{
  long lVar1;
  SBC *this;
  undefined1 uVar2;
  
  *param_2 = (SBC *)0x0;
  this = (SBC *)ExAllocatePool2(0x40,0x1528,0x646d4370);
  if (this == (SBC *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    uVar2 = 0x28;
    memset(this,0,0x1528);
    lVar1 = ConfigEncode(this,param_1,(bool)uVar2);
    if (lVar1 < 0) {
      operator_delete(this);
    }
    else {
      *param_2 = this;
    }
  }
  return lVar1;
}



===== ReadSbcFrameData @ 140018b94 =====

/* public: void __cdecl SBC::SbcControl::ReadSbcFrameData(int const (* __ptr64 const)[8],unsigned
   short (* __ptr64 const)[2][8]) __ptr64 */

void __thiscall SBC::SbcControl::ReadSbcFrameData(SbcControl *this,int *param_1,ushort *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  ushort *puVar4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  uint *puVar8;
  int local_res8;
  
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined2 *)(this + 0x3c) = 0;
  uVar1 = *(int *)(this + 0x14) * *(int *)(this + 0x1c) * 4 + 0x20;
  *(ulonglong *)(this + 0x30) = (ulonglong)(uVar1 >> 3) + *(longlong *)(this + 0x28);
  getbits(this,uVar1 & 7);
  if (*(int *)(this + 8) == 3) {
    getbits(this,*(uint *)(this + 0x1c));
  }
  local_res8 = 0;
  if (0 < *(int *)(this + 0x18)) {
    lVar7 = 0;
    do {
      iVar2 = 0;
      lVar5 = 0;
      if (0 < *(int *)(this + 0x14)) {
        puVar8 = (uint *)param_1;
        do {
          iVar6 = 0;
          if (0 < *(int *)(this + 0x1c)) {
            puVar4 = param_2 + (lVar7 + lVar5) * 8;
            puVar3 = puVar8;
            do {
              uVar1 = getbits(this,*puVar3);
              *puVar4 = (ushort)uVar1;
              puVar3 = puVar3 + 1;
              iVar6 = iVar6 + 1;
              puVar4 = puVar4 + 1;
            } while (iVar6 < *(int *)(this + 0x1c));
          }
          iVar2 = iVar2 + 1;
          lVar5 = lVar5 + 1;
          puVar8 = puVar8 + 8;
        } while (iVar2 < *(int *)(this + 0x14));
      }
      local_res8 = local_res8 + 1;
      lVar7 = lVar7 + 2;
    } while (local_res8 < *(int *)(this + 0x18));
  }
  return;
}



===== SetSbcFrame @ 140018c98 =====

/* public: long __cdecl SBC::SbcControl::SetSbcFrame(unsigned char * __ptr64,short (* __ptr64
   const)[8]) __ptr64 */

long __thiscall SBC::SbcControl::SetSbcFrame(SbcControl *this,uchar *param_1,short *param_2)

{
  SbcControl *pSVar1;
  SbcControl *pSVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  ushort *puVar7;
  uchar local_res8 [8];
  uint local_res10;
  
  *(uchar **)(this + 0x28) = param_1;
  *(uchar **)(this + 0x30) = param_1;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined2 *)(this + 0x3c) = 0;
  uVar3 = getbits(this,8);
  if (uVar3 == *(uint *)this) {
    local_res8[0] = '\x0f';
    pSVar1 = this + 0x14;
    pSVar2 = this + 0x1c;
    if (uVar3 == 0xad) {
      uVar3 = getbits(this,0x10);
      calcCRC(0x10,uVar3,local_res8);
    }
    else {
      uVar3 = getbits_with_crc(this,2,local_res8);
      *(uint *)(this + 4) = uVar3;
      uVar3 = getbits_with_crc(this,2,local_res8);
      *(uint *)(this + 0x18) = uVar3 * 4 + 4;
      uVar3 = getbits_with_crc(this,2,local_res8);
      *(uint *)(this + 8) = uVar3;
      *(uint *)pSVar1 = (uVar3 != 0) + 1;
      uVar3 = getbits_with_crc(this,1,local_res8);
      *(uint *)(this + 0xc) = uVar3;
      uVar3 = getbits_with_crc(this,1,local_res8);
      *(uint *)pSVar2 = (-(uint)(uVar3 != 0) & 4) + 4;
      uVar3 = getbits_with_crc(this,8,local_res8);
      *(uint *)(this + 0x20) = uVar3;
    }
    local_res10 = getbits(this,8);
    if (*(int *)(this + 8) == 3) {
      uVar3 = getbits_with_crc(this,*(uint *)pSVar2,local_res8);
      this[0x10] = SUB41(uVar3,0);
    }
    iVar5 = 0;
    if (0 < *(int *)pSVar1) {
      do {
        iVar4 = 0;
        if (0 < (int)*(uint *)pSVar2) {
          puVar7 = (ushort *)param_2;
          do {
            uVar3 = getbits_with_crc(this,4,local_res8);
            iVar4 = iVar4 + 1;
            *puVar7 = (ushort)uVar3 & 0xff;
            puVar7 = puVar7 + 1;
          } while (iVar4 < (int)*(uint *)pSVar2);
        }
        iVar5 = iVar5 + 1;
        param_2 = param_2 + 8;
      } while (iVar5 < *(int *)pSVar1);
    }
    lVar6 = 0;
    if ((uchar)local_res10 != local_res8[0]) {
      lVar6 = -0x3ffffff3;
    }
  }
  else {
    lVar6 = -0x3ffffff3;
  }
  return lVar6;
}



===== calcCRC @ 140018e40 =====

/* private: static void __cdecl SBC::SbcControl::calcCRC(int,unsigned int,unsigned char * __ptr64)
    */

void __cdecl SBC::SbcControl::calcCRC(int param_1,uint param_2,uchar *param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(uint)param_1;
  iVar3 = param_2 << (8U - (char)param_1 & 0x1f);
  if (0 < param_1) {
    do {
      bVar1 = *param_3;
      bVar2 = bVar1 * '\x02';
      *param_3 = bVar2;
      if ((char)(bVar1 ^ (byte)iVar3) < '\0') {
        *param_3 = bVar2 ^ 0x1d;
      }
      iVar3 = iVar3 * 2;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}



===== calcLevels @ 140018e7c =====

/* private: void __cdecl SBC::calcLevels(void) __ptr64 */

void __thiscall SBC::calcLevels(SBC *this)

{
  int iVar1;
  int iVar2;
  SBC *pSVar3;
  SBC *pSVar4;
  int iVar5;
  
  iVar2 = 0;
  if (0 < *(int *)(this + 0x14)) {
    iVar1 = *(int *)(this + 0x1c);
    pSVar3 = this + 0xa8;
    do {
      iVar5 = 0;
      if (0 < iVar1) {
        pSVar4 = pSVar3;
        do {
          iVar5 = iVar5 + 1;
          *(int *)pSVar4 = (1 << ((byte)*(int *)(pSVar4 + -0x60) & 0x1f)) + -1;
          pSVar4 = pSVar4 + 4;
          iVar1 = *(int *)(this + 0x1c);
        } while (iVar5 < iVar1);
      }
      iVar2 = iVar2 + 1;
      pSVar3 = pSVar3 + 0x20;
    } while (iVar2 < *(int *)(this + 0x14));
  }
  return;
}



===== calcScaleFactors @ 140018ed0 =====

/* private: void __cdecl SBC::calcScaleFactors(int,int,__int64 const (* __ptr64 const)[2][8],short
   (* __ptr64 const)[8]) __ptr64 */

void __thiscall
SBC::calcScaleFactors(SBC *this,int param_1,int param_2,__int64 *param_3,short *param_4)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  ushort *puVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong lVar10;
  
  if ((param_1 < 3) && (param_2 < 9)) {
    lVar8 = (longlong)param_1;
    if (0 < param_1) {
      lVar5 = (longlong)param_2;
      do {
        lVar10 = lVar5;
        if (0 < lVar5) {
          puVar4 = (ushort *)param_4;
          plVar9 = param_3;
          do {
            lVar7 = (longlong)*(int *)(this + 0x18);
            lVar2 = 0;
            if (0 < lVar7) {
              lVar3 = lVar2;
              plVar6 = plVar9;
              do {
                lVar2 = *plVar6;
                if (lVar2 < 0) {
                  lVar2 = -lVar2;
                }
                if (lVar2 <= lVar3) {
                  lVar2 = lVar3;
                }
                plVar6 = plVar6 + 0x10;
                lVar7 = lVar7 + -1;
                lVar3 = lVar2;
              } while (lVar7 != 0);
            }
            bVar1 = getScaleFactor(lVar2);
            plVar9 = plVar9 + 1;
            *puVar4 = (ushort)bVar1;
            puVar4 = puVar4 + 1;
            lVar5 = lVar5 + -1;
          } while (lVar5 != 0);
        }
        param_4 = param_4 + 8;
        param_3 = param_3 + 8;
        lVar8 = lVar8 + -1;
        lVar5 = lVar10;
      } while (lVar8 != 0);
    }
  }
  return;
}



===== distributeBits @ 140018f90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl SBC::SbcControl::distributeBits(int,int,short (* __ptr64 const)[8],int (*
   __ptr64 const)[8])const __ptr64 */

void __thiscall
SBC::SbcControl::distributeBits
          (SbcControl *this,int param_1,int param_2,short *param_3,int *param_4)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  short *psVar6;
  int *piVar7;
  int iVar8;
  longlong lVar9;
  int iVar10;
  ulonglong uVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  ulonglong uVar15;
  longlong lVar16;
  int iVar17;
  undefined1 auStack_a8 [32];
  int local_88;
  int local_84;
  int *local_80;
  int local_78 [16];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar8 = 0;
  lVar9 = (longlong)param_1;
  local_80 = param_4;
  local_88 = 0;
  iVar17 = 0;
  local_84 = param_2;
  memset(local_78,0,0x40);
  if (*(int *)(this + 0xc) == 1) {
    if (lVar9 <= param_2) {
      iVar12 = *(int *)(this + 0x1c);
      psVar6 = param_3 + lVar9 * 8;
      piVar5 = local_78 + lVar9 * 8;
      lVar4 = (param_2 - lVar9) + 1;
      do {
        if (0 < (longlong)iVar12) {
          piVar7 = piVar5;
          psVar14 = psVar6;
          lVar16 = (longlong)iVar12;
          do {
            sVar1 = *psVar14;
            psVar14 = psVar14 + 1;
            *piVar7 = (int)sVar1;
            piVar7 = piVar7 + 1;
            lVar16 = lVar16 + -1;
          } while (lVar16 != 0);
        }
        piVar5 = piVar5 + 8;
        psVar6 = psVar6 + 8;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    if (param_2 < param_1) goto LAB_1400190af;
  }
  else {
    if (param_2 < param_1) goto LAB_1400190af;
    psVar6 = param_3 + lVar9 * 8;
    piVar5 = local_78 + lVar9 * 8;
    uVar15 = (ulonglong)((param_2 - param_1) + 1);
    do {
      uVar2 = *(uint *)(this + 0x1c);
      lVar4 = 0;
      if (0 < (int)uVar2) {
        uVar11 = (ulonglong)uVar2;
        psVar14 = psVar6;
        piVar7 = piVar5;
        if (uVar2 == 4) {
          do {
            if (*psVar14 == 0) {
              iVar17 = -5;
            }
            else {
              iVar17 = (int)*psVar14 -
                       (int)*(char *)((longlong)&SBC_OFFSET4 +
                                     lVar4 + (longlong)*(int *)(this + 4) * 4);
              if (0 < iVar17) {
                iVar17 = iVar17 / 2;
              }
            }
            *piVar7 = iVar17;
            lVar4 = lVar4 + 1;
            piVar7 = piVar7 + 1;
            psVar14 = psVar14 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        else {
          do {
            if (*psVar14 == 0) {
              iVar17 = -5;
            }
            else {
              iVar17 = (int)*psVar14 -
                       (int)*(char *)((longlong)&SBC_OFFSET8 +
                                     lVar4 + (longlong)*(int *)(this + 4) * 8);
              if (0 < iVar17) {
                iVar17 = iVar17 / 2;
              }
            }
            *piVar7 = iVar17;
            lVar4 = lVar4 + 1;
            piVar7 = piVar7 + 1;
            psVar14 = psVar14 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
      }
      piVar5 = piVar5 + 8;
      psVar6 = psVar6 + 8;
      uVar15 = uVar15 - 1;
    } while (uVar15 != 0);
    param_2 = local_84;
  }
  iVar17 = 0;
  piVar5 = local_78 + lVar9 * 8;
  uVar15 = (ulonglong)((param_2 - param_1) + 1);
  do {
    if (0 < (int)*(uint *)(this + 0x1c)) {
      piVar7 = piVar5;
      uVar11 = (ulonglong)*(uint *)(this + 0x1c);
      do {
        iVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        if (iVar12 <= iVar17) {
          iVar12 = iVar17;
        }
        iVar17 = iVar12;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    piVar5 = piVar5 + 8;
    uVar15 = uVar15 - 1;
  } while (uVar15 != 0);
  local_88 = iVar17;
LAB_1400190af:
  iVar12 = iVar17 + 1;
  iVar3 = 0;
  do {
    iVar10 = 0;
    if (param_1 <= param_2) {
      piVar5 = local_78 + lVar9 * 8;
      uVar15 = (ulonglong)((param_2 - param_1) + 1);
      do {
        if (0 < (int)*(uint *)(this + 0x1c)) {
          uVar11 = (ulonglong)*(uint *)(this + 0x1c);
          piVar7 = piVar5;
          do {
            iVar17 = *piVar7;
            if (iVar12 < iVar17) {
              if (iVar17 < iVar12 + 0xf) {
                iVar10 = iVar10 + 1;
              }
            }
            else if (iVar17 == iVar12) {
              iVar10 = iVar10 + 2;
            }
            piVar7 = piVar7 + 1;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        piVar5 = piVar5 + 8;
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
      iVar17 = local_88;
    }
    iVar10 = iVar10 + iVar3;
    if (*(int *)(this + 0x20) < iVar10) break;
    iVar17 = iVar17 + -1;
    iVar12 = iVar12 + -1;
    iVar3 = iVar10;
    local_88 = iVar17;
  } while (iVar10 != *(int *)(this + 0x20));
  if (param_1 <= param_2) {
    iVar12 = *(int *)(this + 0x1c);
    lVar4 = lVar9 << 5;
    uVar15 = (ulonglong)((param_2 - param_1) + 1);
    do {
      iVar10 = 0;
      if (0 < iVar12) {
        piVar5 = (int *)(lVar4 + (longlong)local_80);
        do {
          iVar12 = *(int *)(((longlong)local_78 - (longlong)local_80) + (longlong)piVar5);
          if (iVar12 < iVar17 + 2) {
            iVar13 = 0;
          }
          else {
            iVar12 = iVar12 - iVar17;
            iVar13 = 0x10;
            if (iVar12 < 0x10) {
              iVar13 = iVar12;
            }
          }
          *piVar5 = iVar13;
          iVar10 = iVar10 + 1;
          iVar12 = *(int *)(this + 0x1c);
          piVar5 = piVar5 + 1;
        } while (iVar10 < iVar12);
      }
      lVar4 = lVar4 + 0x20;
      uVar15 = uVar15 - 1;
    } while (uVar15 != 0);
    param_2 = local_84;
  }
  iVar17 = *(int *)(this + 0x1c);
  iVar12 = 0;
  if (0 < iVar17) {
    lVar4 = 0;
    do {
      if (*(int *)(this + 0x20) <= iVar3) break;
      if (param_1 <= param_2) {
        iVar17 = iVar3 + 1;
        piVar5 = local_80 + lVar4 + lVar9 * 8;
        iVar10 = param_1;
        do {
          if (*(int *)(this + 0x20) <= iVar3) break;
          if (*piVar5 - 2U < 0xe) {
            iVar3 = iVar3 + 1;
            *piVar5 = *piVar5 + 1;
            iVar17 = iVar17 + 1;
          }
          else if ((*(int *)(((longlong)local_78 - (longlong)local_80) + (longlong)piVar5) ==
                    local_88 + 1) && (iVar17 < *(int *)(this + 0x20))) {
            iVar3 = iVar3 + 2;
            *piVar5 = 2;
            iVar17 = iVar17 + 2;
          }
          iVar10 = iVar10 + 1;
          piVar5 = piVar5 + 8;
        } while (iVar10 <= param_2);
      }
      iVar17 = *(int *)(this + 0x1c);
      iVar12 = iVar12 + 1;
      lVar4 = lVar4 + 1;
    } while (iVar12 < iVar17);
    if (0 < iVar17) {
      iVar17 = *(int *)(this + 0x20);
      lVar4 = 0;
      do {
        if (iVar17 <= iVar3) {
          return;
        }
        if (param_1 <= param_2) {
          piVar5 = local_80 + lVar4 + lVar9 * 8;
          iVar12 = param_1;
          iVar10 = iVar17;
          do {
            if (iVar10 <= iVar3) break;
            if (*piVar5 < 0x10) {
              *piVar5 = *piVar5 + 1;
              iVar3 = iVar3 + 1;
              iVar17 = *(int *)(this + 0x20);
              iVar10 = iVar17;
            }
            iVar12 = iVar12 + 1;
            piVar5 = piVar5 + 8;
          } while (iVar12 <= param_2);
        }
        iVar8 = iVar8 + 1;
        lVar4 = lVar4 + 1;
      } while (iVar8 < *(int *)(this + 0x1c));
    }
  }
  return;
}



===== flush_putbits @ 1400193e0 =====

/* private: void __cdecl SBC::SbcControl::flush_putbits(void) __ptr64 */

void __thiscall SBC::SbcControl::flush_putbits(SbcControl *this)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(this + 0x3c);
  while (uVar1 < 0x20) {
    **(SbcControl **)(this + 0x30) = this[0x3b];
    *(longlong *)(this + 0x30) = *(longlong *)(this + 0x30) + 1;
    *(int *)(this + 0x38) = *(int *)(this + 0x38) << 8;
    *(short *)(this + 0x3c) = *(short *)(this + 0x3c) + 8;
    uVar1 = *(ushort *)(this + 0x3c);
  }
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined2 *)(this + 0x3c) = 0x20;
  return;
}



===== getScaleFactor @ 140019420 =====

/* private: static unsigned char __cdecl SBC::getScaleFactor(__int64) */

uchar __cdecl SBC::getScaleFactor(__int64 param_1)

{
  longlong lVar1;
  
  lVar1 = -param_1;
  if (-param_1 < 0) {
    lVar1 = param_1;
  }
  if (0x1fffffff < lVar1) {
    return '\x0f';
  }
  if (0xfffffff < lVar1) {
    return '\x0e';
  }
  if (0x7ffffff < lVar1) {
    return '\r';
  }
  if (0x3ffffff < lVar1) {
    return '\f';
  }
  if (0x1ffffff < lVar1) {
    return '\v';
  }
  if (0xffffff < lVar1) {
    return '\n';
  }
  if (0x7fffff < lVar1) {
    return '\t';
  }
  if (0x3fffff < lVar1) {
    return '\b';
  }
  if (0x1fffff < lVar1) {
    return '\a';
  }
  if (0xfffff < lVar1) {
    return '\x06';
  }
  if (0x7ffff < lVar1) {
    return '\x05';
  }
  if (0x3ffff < lVar1) {
    return '\x04';
  }
  if (0x1ffff < lVar1) {
    return '\x03';
  }
  if (lVar1 < 0x10000) {
    return 0x7fff < lVar1;
  }
  return '\x02';
}



===== getbits @ 1400194e4 =====

/* private: unsigned int __cdecl SBC::SbcControl::getbits(unsigned int) __ptr64 */

uint __thiscall SBC::SbcControl::getbits(SbcControl *this,uint param_1)

{
  SbcControl *pSVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  byte *pbVar6;
  
  pSVar1 = this + 0x38;
  uVar4 = *(ushort *)(this + 0x3c);
  if (uVar4 < param_1) {
    pbVar6 = *(byte **)(this + 0x30);
    uVar5 = *(uint *)pSVar1;
    do {
      bVar3 = *pbVar6;
      cVar2 = (char)uVar4;
      pbVar6 = pbVar6 + 1;
      uVar4 = uVar4 + 8;
      uVar5 = uVar5 | (uint)bVar3 << (0x18U - cVar2 & 0x1f);
      *(byte **)(this + 0x30) = pbVar6;
      *(uint *)pSVar1 = uVar5;
      *(ushort *)(this + 0x3c) = uVar4;
    } while (uVar4 < param_1);
  }
  uVar5 = *(uint *)pSVar1;
  *(ushort *)(this + 0x3c) = uVar4 - (short)param_1;
  bVar3 = (byte)param_1;
  *(uint *)pSVar1 = uVar5 << (bVar3 & 0x1f);
  return uVar5 >> (0x20 - bVar3 & 0x1f) & (1 << (bVar3 & 0x1f)) - 1U;
}



===== getbits_with_crc @ 140019568 =====

/* private: unsigned int __cdecl SBC::SbcControl::getbits_with_crc(unsigned int,unsigned char *
   __ptr64) __ptr64 */

uint __thiscall SBC::SbcControl::getbits_with_crc(SbcControl *this,uint param_1,uchar *param_2)

{
  uint uVar1;
  
  uVar1 = getbits(this,param_1);
  calcCRC(param_1,uVar1,param_2);
  return uVar1;
}



===== jointEncode @ 1400195a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl SBC::jointEncode(void) __ptr64 */

void __thiscall SBC::jointEncode(SBC *this)

{
  SBC *pSVar1;
  SBC SVar2;
  short sVar3;
  short sVar4;
  longlong lVar5;
  __int64 *p_Var6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  int iVar10;
  SBC *pSVar11;
  SBC *pSVar12;
  __int64 *p_Var13;
  __int64 *p_Var14;
  ulonglong uVar15;
  SBC aSStackY_d40 [64];
  SBC aSStackY_d00 [1136];
  undefined8 uStackY_890;
  undefined1 auStackY_888 [32];
  __int64 local_858 [237];
  SBC aSStack_f0 [16];
  SBC aSStack_e0 [136];
  short local_58 [16];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_888;
  pSVar1 = this + 0x1c;
  if (0 < (int)*(uint *)(this + 0x18)) {
    iVar7 = *(int *)pSVar1;
    pSVar12 = this + 0x4e8;
    uVar8 = (ulonglong)*(uint *)(this + 0x18);
    do {
      if (0 < (int)(iVar7 - 1U)) {
        uVar15 = (ulonglong)(iVar7 - 1U);
        pSVar11 = pSVar12;
        do {
          lVar9 = *(longlong *)(pSVar11 + 0x40);
          lVar5 = *(longlong *)pSVar11;
          pSVar11 = pSVar11 + 8;
          lVar5 = lVar5 + lVar9 >> 1;
          *(longlong *)(pSVar11 + (longlong)(aSStackY_d40 + (-8 - (longlong)this))) = lVar5;
          *(longlong *)(pSVar11 + (longlong)(aSStackY_d40 + (0x38 - (longlong)this))) =
               lVar5 - lVar9;
          uVar15 = uVar15 - 1;
        } while (uVar15 != 0);
      }
      pSVar12 = pSVar12 + 0x80;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  iVar7 = *(int *)pSVar1;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  local_58[8] = 0;
  local_58[9] = 0;
  local_58[10] = 0;
  local_58[0xb] = 0;
  local_58[0xc] = 0;
  local_58[0xd] = 0;
  local_58[0xe] = 0;
  local_58[0xf] = 0;
  uStackY_890 = 0x140019673;
  calcScaleFactors(this,2,iVar7 + -1,local_858,local_58);
  iVar10 = 0;
  this[0x10] = (SBC)0x0;
  if (0 < iVar7 + -1) {
    p_Var14 = local_858;
    pSVar12 = this + 0x98;
    do {
      SVar2 = this[0x10];
      sVar3 = *(short *)(pSVar12 + (longlong)(aSStack_e0 + -(longlong)this));
      sVar4 = *(short *)(pSVar12 + (longlong)(aSStack_f0 + -(longlong)this));
      this[0x10] = (SBC)((char)SVar2 * '\x02');
      if ((int)sVar3 + (int)sVar4 < (int)*(short *)(pSVar12 + -0x10) + (int)*(short *)pSVar12) {
        lVar9 = 2;
        this[0x10] = (SBC)((char)SVar2 * '\x02' | 2);
        p_Var13 = p_Var14;
        do {
          iVar7 = 0;
          if (0 < *(int *)(this + 0x18)) {
            p_Var6 = p_Var13;
            do {
              iVar7 = iVar7 + 1;
              *(__int64 *)(this + (0x4e8 - (longlong)local_858) + (longlong)p_Var6) = *p_Var6;
              p_Var6 = p_Var6 + 0x10;
            } while (iVar7 < *(int *)(this + 0x18));
          }
          p_Var13 = p_Var13 + 8;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        *(short *)(pSVar12 + -0x10) = sVar4;
        *(short *)pSVar12 = sVar3;
      }
      iVar10 = iVar10 + 1;
      pSVar12 = pSVar12 + 2;
      p_Var14 = p_Var14 + 1;
    } while (iVar10 < *(int *)pSVar1 + -1);
  }
  return;
}



===== putbits @ 140019774 =====

/* private: void __cdecl SBC::SbcControl::putbits(unsigned int,unsigned int) __ptr64 */

void __thiscall SBC::SbcControl::putbits(SbcControl *this,uint param_1,uint param_2)

{
  ushort uVar1;
  
  uVar1 = *(short *)(this + 0x3c) - (short)param_1;
  *(uint *)(this + 0x38) = *(uint *)(this + 0x38) | param_2 << ((byte)uVar1 & 0x1f);
  *(ushort *)(this + 0x3c) = uVar1;
  if (uVar1 < 0x11) {
    **(SbcControl **)(this + 0x30) = this[0x3b];
    *(longlong *)(this + 0x30) = *(longlong *)(this + 0x30) + 1;
    **(SbcControl **)(this + 0x30) = this[0x3a];
    *(longlong *)(this + 0x30) = *(longlong *)(this + 0x30) + 1;
    *(int *)(this + 0x38) = *(int *)(this + 0x38) << 0x10;
    *(short *)(this + 0x3c) = *(short *)(this + 0x3c) + 0x10;
  }
  return;
}



===== putbits_with_crc @ 1400197c4 =====

/* private: void __cdecl SBC::SbcControl::putbits_with_crc(unsigned int,unsigned int,unsigned char *
   __ptr64) __ptr64 */

void __thiscall
SBC::SbcControl::putbits_with_crc(SbcControl *this,uint param_1,uint param_2,uchar *param_3)

{
  putbits(this,param_1,param_2);
  calcCRC(param_1,param_2,param_3);
  return;
}



===== polyPhaseAnalysisSB4 @ 1400197f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl SBC::polyPhaseAnalysisSB4(int,int,short (* __ptr64 const)[80]) __ptr64 */

void __thiscall SBC::polyPhaseAnalysisSB4(SBC *this,int param_1,int param_2,short *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int **ppiVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong *plVar9;
  short *psVar10;
  longlong lVar11;
  SBC *pSVar12;
  int *piVar13;
  SBC *pSVar14;
  longlong local_58 [10];
  
  if (0 < param_1) {
    uVar7 = (ulonglong)(uint)param_1;
    pSVar12 = this + (longlong)param_2 * 0x80 + 0x4e8;
    do {
      piVar13 = &DAT_14001e9f0;
      lVar8 = 8;
      plVar9 = local_58;
      psVar10 = param_3;
      do {
        piVar1 = piVar13 + 8;
        piVar2 = piVar13 + -8;
        piVar3 = piVar13 + -0x10;
        piVar4 = piVar13 + -0x18;
        iVar5 = *piVar13;
        piVar13 = piVar13 + 1;
        *plVar9 = (longlong)*piVar1 * (longlong)psVar10[0x20] +
                  (longlong)*piVar2 * (longlong)psVar10[0x10] +
                  (longlong)*piVar3 * (longlong)psVar10[8] + (longlong)*piVar4 * (longlong)*psVar10
                  + (longlong)psVar10[0x18] * (longlong)iVar5 >> 10;
        plVar9 = plVar9 + 1;
        lVar8 = lVar8 + -1;
        psVar10 = psVar10 + 1;
      } while (lVar8 != 0);
      ppiVar6 = &M4SUBBAND;
      pSVar14 = pSVar12;
      do {
        lVar8 = 0;
        lVar11 = 0;
        do {
          iVar5 = *(int *)ppiVar6;
          ppiVar6 = (int **)((longlong)ppiVar6 + 4);
          plVar9 = local_58 + lVar11;
          lVar11 = lVar11 + 1;
          lVar8 = lVar8 + (longlong)iVar5 * *plVar9;
        } while (lVar11 < 8);
        *(longlong *)pSVar14 = lVar8 >> 0x1f;
        pSVar14 = pSVar14 + 8;
      } while ((longlong)ppiVar6 < 0x14001e670);
      param_3 = param_3 + 0x50;
      pSVar12 = pSVar12 + 0x40;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return;
}



===== polyPhaseAnalysisSB8 @ 140019920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl SBC::polyPhaseAnalysisSB8(int,int,short (* __ptr64 const)[80]) __ptr64 */

void __thiscall SBC::polyPhaseAnalysisSB8(SBC *this,int param_1,int param_2,short *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int **ppiVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong *plVar9;
  SBC *pSVar10;
  short *psVar11;
  longlong lVar12;
  int *piVar13;
  longlong local_98 [18];
  
  if (0 < param_1) {
    uVar7 = (ulonglong)(uint)param_1;
    pSVar10 = this + (longlong)param_2 * 0x80 + 0x4e8;
    do {
      piVar13 = &DAT_14001e910;
      lVar8 = 0x10;
      plVar9 = local_98;
      psVar11 = param_3;
      do {
        piVar1 = piVar13 + 0x10;
        piVar2 = piVar13 + -0x10;
        piVar3 = piVar13 + -0x20;
        piVar4 = piVar13 + -0x30;
        iVar5 = *piVar13;
        piVar13 = piVar13 + 1;
        *plVar9 = (longlong)*piVar1 * (longlong)psVar11[0x40] +
                  (longlong)*piVar2 * (longlong)psVar11[0x20] +
                  (longlong)*piVar3 * (longlong)psVar11[0x10] +
                  (longlong)*piVar4 * (longlong)*psVar11 + (longlong)psVar11[0x30] * (longlong)iVar5
                  >> 10;
        plVar9 = plVar9 + 1;
        lVar8 = lVar8 + -1;
        psVar11 = psVar11 + 1;
      } while (lVar8 != 0);
      ppiVar6 = &M8SUBBAND;
      do {
        lVar8 = 0;
        lVar12 = 0;
        do {
          iVar5 = *(int *)ppiVar6;
          ppiVar6 = (int **)((longlong)ppiVar6 + 4);
          plVar9 = local_98 + lVar12;
          lVar12 = lVar12 + 1;
          lVar8 = lVar8 + (longlong)iVar5 * *plVar9;
        } while (lVar12 < 0x10);
        *(longlong *)pSVar10 = lVar8 >> 0x20;
        pSVar10 = pSVar10 + 8;
      } while ((longlong)ppiVar6 < 0x14001e5f0);
      param_3 = param_3 + 0x50;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return;
}



===== polyPhaseSynthesisSB4 @ 140019a58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl SBC::polyPhaseSynthesisSB4(unsigned int,short (* __ptr64 const)[8][2],int
   (* __ptr64 const)[160]) __ptr64 */

void __thiscall SBC::polyPhaseSynthesisSB4(SBC *this,uint param_1,short *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  short *psVar11;
  int iVar12;
  int *piVar13;
  ulonglong uVar14;
  longlong lVar15;
  longlong lVar16;
  int iVar17;
  int *piVar18;
  undefined8 auStack_108 [4];
  int local_e8 [2];
  undefined8 auStack_e0 [19];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  iVar12 = 0;
  if (0 < *(int *)(this + 0x14)) {
    lVar15 = 0;
    piVar18 = param_3 + 2;
    do {
      if (1 < iVar12) {
        return;
      }
      piVar13 = param_3 + (longlong)iVar12 * 0xa0;
      memcpy(piVar13 + 8,piVar13,0x120);
      lVar16 = (lVar15 + (ulonglong)param_1 * 2) * 0x20;
      piVar18[-2] = ((((*(int *)(this + lVar16 + 0xf4) - *(int *)(this + lVar16 + 0xf0)) -
                      *(int *)(this + lVar16 + 0xec)) + *(int *)(this + lVar16 + 0xe8)) * 0x5a82 >>
                    3) + 0x800 >> 0xc;
      iVar9 = *(int *)(this + lVar16 + 0xf0);
      iVar17 = *(int *)(this + lVar16 + 0xec);
      iVar1 = *(int *)(this + lVar16 + 0xe8);
      iVar2 = *(int *)(this + lVar16 + 0xf4);
      *piVar18 = 0;
      piVar18[-1] = ((iVar1 - iVar2) * 0x30fc >> 3) + ((iVar9 - iVar17) * 0x7642 >> 3) + 0x800 >>
                    0xc;
      piVar18[1] = ((*(int *)(this + lVar16 + 0xec) - *(int *)(this + lVar16 + 0xf0)) * 0x7642 >> 3)
                   + ((*(int *)(this + lVar16 + 0xf4) - *(int *)(this + lVar16 + 0xe8)) * 0x30fc >>
                     3) + 0x800 >> 0xc;
      piVar18[2] = ((((*(int *)(this + lVar16 + 0xf0) - *(int *)(this + lVar16 + 0xf4)) -
                     *(int *)(this + lVar16 + 0xe8)) + *(int *)(this + lVar16 + 0xec)) * 0x5a82 >> 3
                   ) + 0x800 >> 0xc;
      piVar10 = piVar13 + 0xc;
      iVar8 = ((*(int *)(this + lVar16 + 0xf4) - *(int *)(this + lVar16 + 0xe8)) * 0x7642 >> 3) +
              ((*(int *)(this + lVar16 + 0xf0) - *(int *)(this + lVar16 + 0xec)) * 0x30fc >> 3) +
              0x800 >> 0xc;
      piVar18[3] = iVar8;
      iVar9 = *(int *)(this + lVar16 + 0xf4);
      iVar17 = *(int *)(this + lVar16 + 0xf0);
      iVar1 = *(int *)(this + lVar16 + 0xe8);
      iVar2 = *(int *)(this + lVar16 + 0xec);
      piVar18[5] = iVar8;
      piVar18[4] = -(iVar9 + iVar17 + iVar1 + iVar2);
      iVar9 = 5;
      puVar3 = auStack_108;
      do {
        iVar17 = iVar9;
        uVar4 = *(undefined8 *)piVar13;
        uVar5 = *(undefined8 *)(piVar13 + 2);
        piVar13 = piVar13 + 0x10;
        uVar6 = *(undefined8 *)piVar10;
        uVar7 = *(undefined8 *)(piVar10 + 2);
        piVar10 = piVar10 + 0x10;
        puVar3[4] = uVar4;
        puVar3[5] = uVar5;
        puVar3[6] = uVar6;
        puVar3[7] = uVar7;
        iVar9 = iVar17 + -1;
        puVar3 = puVar3 + 4;
      } while (iVar9 != 0);
      uVar14 = (ulonglong)(iVar17 + 3);
      lVar16 = 0;
      psVar11 = param_2 + (ulonglong)param_1 * 0x10 + lVar15;
      do {
        iVar9 = 0;
        piVar10 = (int *)((longlong)local_e8 + lVar16);
        iVar17 = 10;
        do {
          piVar13 = (int *)(((longlong)&C_SB4_DECODE - (longlong)local_e8) + (longlong)piVar10);
          iVar1 = *piVar10;
          piVar10 = piVar10 + 4;
          iVar9 = iVar9 - (*piVar13 * iVar1 >> 1);
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
        lVar16 = lVar16 + 4;
        *psVar11 = (short)(iVar9 + 0x1000 >> 0xd);
        psVar11 = psVar11 + 2;
        uVar14 = uVar14 - 1;
      } while (uVar14 != 0);
      iVar12 = iVar12 + 1;
      lVar15 = lVar15 + 1;
      piVar18 = piVar18 + 0xa0;
    } while (iVar12 < *(int *)(this + 0x14));
  }
  return;
}



===== polyPhaseSynthesisSB8 @ 140019cfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl SBC::polyPhaseSynthesisSB8(unsigned int,short (* __ptr64 const)[8][2],int
   (* __ptr64 const)[160]) __ptr64 */

void __thiscall SBC::polyPhaseSynthesisSB8(SBC *this,uint param_1,short *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  ulonglong uVar13;
  int *_Src;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  short *psVar19;
  int iVar20;
  longlong lVar21;
  longlong lVar22;
  int *piVar23;
  undefined1 auStack_1b8 [32];
  uint local_198;
  int *local_190;
  int local_188 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1b8;
  iVar14 = 0;
  if (0 < *(int *)(this + 0x14)) {
    lVar22 = 0;
    piVar23 = param_3 + 2;
    local_198 = param_1;
    local_190 = param_3;
    do {
      uVar13 = (ulonglong)local_198;
      if (1 < iVar14) {
        return;
      }
      _Src = local_190 + (longlong)iVar14 * 0xa0;
      memcpy(_Src + 0x10,_Src,0x240);
      lVar21 = (lVar22 + uVar13 * 2) * 0x20;
      iVar20 = ((((((*(int *)(this + lVar21 + 0x104) - *(int *)(this + lVar21 + 0x100)) -
                   *(int *)(this + lVar21 + 0xfc)) - *(int *)(this + lVar21 + 0xf0)) -
                 *(int *)(this + lVar21 + 0xec)) + *(int *)(this + lVar21 + 0xf8) +
                 *(int *)(this + lVar21 + 0xf4) + *(int *)(this + lVar21 + 0xe8)) * 0x5a82 >> 3) +
               0x400 >> 0xb;
      piVar23[-2] = iVar20;
      iVar17 = ((*(int *)(this + lVar21 + 0xf0) - *(int *)(this + lVar21 + 0xfc)) * 0x18f9 >> 3) +
               ((*(int *)(this + lVar21 + 0xe8) - *(int *)(this + lVar21 + 0x104)) * 0x471d >> 3) +
               ((*(int *)(this + lVar21 + 0xf4) - *(int *)(this + lVar21 + 0xf8)) * 0x6a6e >> 3) +
               ((*(int *)(this + lVar21 + 0x100) - *(int *)(this + lVar21 + 0xec)) * 0x7d8a >> 3) +
               0x400 >> 0xb;
      piVar23[-1] = iVar17;
      iVar15 = ((((*(int *)(this + lVar21 + 0xe8) - *(int *)(this + lVar21 + 0xf4)) -
                 *(int *)(this + lVar21 + 0xf8)) + *(int *)(this + lVar21 + 0x104)) * 0x30fc >> 3) +
               ((((*(int *)(this + lVar21 + 0xf0) - *(int *)(this + lVar21 + 0xec)) -
                 *(int *)(this + lVar21 + 0x100)) + *(int *)(this + lVar21 + 0xfc)) * 0x7642 >> 3) +
               0x400 >> 0xb;
      *piVar23 = iVar15;
      iVar11 = *(int *)(this + lVar21 + 0xf8);
      iVar16 = *(int *)(this + lVar21 + 0xf4);
      iVar18 = *(int *)(this + lVar21 + 0xe8);
      iVar1 = *(int *)(this + lVar21 + 0x104);
      iVar2 = *(int *)(this + lVar21 + 0xf0);
      iVar3 = *(int *)(this + lVar21 + 0xfc);
      iVar4 = *(int *)(this + lVar21 + 0x100);
      iVar5 = *(int *)(this + lVar21 + 0xec);
      piVar23[2] = 0;
      piVar23[4] = -iVar15;
      piVar23[5] = -iVar17;
      piVar23[6] = -iVar20;
      iVar11 = ((iVar4 - iVar5) * 0x471d >> 3) +
               ((iVar11 - iVar16) * 0x7d8a >> 3) + ((iVar18 - iVar1) * 0x18f9 >> 3) +
               ((iVar2 - iVar3) * 0x6a6e >> 3) + 0x400 >> 0xb;
      piVar23[1] = iVar11;
      piVar23[3] = -iVar11;
      iVar18 = ((*(int *)(this + lVar21 + 0x104) - *(int *)(this + lVar21 + 0xe8)) * 0x6a6e >> 3) +
               ((*(int *)(this + lVar21 + 0xec) - *(int *)(this + lVar21 + 0x100)) * 0x18f9 >> 3) +
               ((*(int *)(this + lVar21 + 0xf4) - *(int *)(this + lVar21 + 0xf8)) * 0x471d >> 3) +
               ((*(int *)(this + lVar21 + 0xf0) - *(int *)(this + lVar21 + 0xfc)) * 0x7d8a >> 3) +
               0x400 >> 0xb;
      piVar23[7] = iVar18;
      iVar16 = ((((*(int *)(this + lVar21 + 0xf0) - *(int *)(this + lVar21 + 0xec)) -
                 *(int *)(this + lVar21 + 0x100)) + *(int *)(this + lVar21 + 0xfc)) * 0x30fc >> 3) +
               ((((*(int *)(this + lVar21 + 0xf4) - *(int *)(this + lVar21 + 0xe8)) -
                 *(int *)(this + lVar21 + 0x104)) + *(int *)(this + lVar21 + 0xf8)) * 0x7642 >> 3) +
               0x400 >> 0xb;
      piVar23[8] = iVar16;
      iVar11 = ((*(int *)(this + lVar21 + 0xfc) - *(int *)(this + lVar21 + 0xf0)) * 0x471d >> 3) +
               ((*(int *)(this + lVar21 + 0x100) - *(int *)(this + lVar21 + 0xec)) * 0x6a6e >> 3) +
               ((*(int *)(this + lVar21 + 0x104) - *(int *)(this + lVar21 + 0xe8)) * 0x7d8a >> 3) +
               ((*(int *)(this + lVar21 + 0xf8) - *(int *)(this + lVar21 + 0xf4)) * 0x18f9 >> 3) +
               0x400 >> 0xb;
      piVar23[9] = iVar11;
      piVar23[10] = (*(int *)(this + lVar21 + 0xf4) + *(int *)(this + lVar21 + 0xec) +
                     *(int *)(this + lVar21 + 0xf8) + *(int *)(this + lVar21 + 0xf0) +
                     *(int *)(this + lVar21 + 0xe8) + *(int *)(this + lVar21 + 0x104) +
                     *(int *)(this + lVar21 + 0x100) + *(int *)(this + lVar21 + 0xfc)) * -2;
      piVar23[0xb] = iVar11;
      piVar10 = local_188;
      piVar23[0xc] = iVar16;
      piVar12 = _Src + 0x18;
      piVar23[0xd] = iVar18;
      iVar11 = 5;
      do {
        iVar16 = iVar11;
        uVar6 = *(undefined8 *)_Src;
        uVar7 = *(undefined8 *)(_Src + 2);
        uVar8 = *(undefined8 *)(_Src + 4);
        uVar9 = *(undefined8 *)(_Src + 6);
        _Src = _Src + 0x20;
        *(undefined8 *)piVar10 = uVar6;
        *(undefined8 *)(piVar10 + 2) = uVar7;
        uVar6 = *(undefined8 *)piVar12;
        uVar7 = *(undefined8 *)(piVar12 + 2);
        *(undefined8 *)(piVar10 + 4) = uVar8;
        *(undefined8 *)(piVar10 + 6) = uVar9;
        uVar8 = *(undefined8 *)(piVar12 + 4);
        uVar9 = *(undefined8 *)(piVar12 + 6);
        piVar12 = piVar12 + 0x20;
        *(undefined8 *)(piVar10 + 8) = uVar6;
        *(undefined8 *)(piVar10 + 10) = uVar7;
        *(undefined8 *)(piVar10 + 0xc) = uVar8;
        *(undefined8 *)(piVar10 + 0xe) = uVar9;
        piVar10 = piVar10 + 0x10;
        iVar11 = iVar16 + -1;
      } while (iVar11 != 0);
      lVar21 = 0;
      psVar19 = param_2 + uVar13 * 0x10 + lVar22;
      uVar13 = (ulonglong)(iVar16 + 7);
      do {
        iVar11 = 0;
        piVar12 = (int *)((longlong)local_188 + lVar21);
        iVar16 = 10;
        do {
          piVar10 = (int *)(((longlong)&C_SB8_DECODE - (longlong)local_188) + (longlong)piVar12);
          iVar18 = *piVar12;
          piVar12 = piVar12 + 8;
          iVar11 = iVar11 - (*piVar10 * iVar18 >> 2);
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        if (iVar11 < -0x10001000) {
          iVar11 = -0x10001000;
        }
        else if (0xfffefff < iVar11) {
          iVar11 = 0xfffefff;
        }
        lVar21 = lVar21 + 4;
        *psVar19 = (short)(iVar11 + 0x1000 >> 0xd);
        psVar19 = psVar19 + 2;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
      iVar14 = iVar14 + 1;
      lVar22 = lVar22 + 1;
      piVar23 = piVar23 + 0xa0;
    } while (iVar14 < *(int *)(this + 0x14));
  }
  return;
}



===== Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline @ 14001a200 =====

ulonglong Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SPR_HardenInClient__private_featureState;
  if ((Feature_SPR_HardenInClient__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SPR_HardenInClient__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SPR_HardenInClient__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SPR_HardenInClient__private_IsEnabledFallback @ 14001a238 =====

void Feature_SPR_HardenInClient__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_SPR_HardenInClient__private_descriptor);
  return;
}



===== RtlUnicodeStringCopy @ 14001a254 =====

ulonglong RtlUnicodeStringCopy(ushort *param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ushort *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  wchar_t *pwVar8;
  ulonglong uVar9;
  
  puVar3 = param_1;
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  uVar5 = 0;
  uVar9 = uVar1 & 0xffffffff;
  if (((int)uVar1 < 0) || (puVar3 == (ushort *)0x0)) {
    lVar7 = 0;
    uVar6 = 0;
    if ((int)uVar1 < 0) goto LAB_14001a2fd;
  }
  else {
    lVar7 = *(longlong *)(puVar3 + 4);
    uVar6 = (ulonglong)(puVar3[1] >> 1);
  }
  uVar2 = RtlUnicodeStringValidateWorker((ushort *)&SleepstudyHelperUnsupportedFriendlyName);
  uVar9 = (ulonglong)(int)uVar2;
  if (-1 < (int)uVar2) {
    pwVar8 = L"Sleepstudy Unsupported";
    uVar1 = (longlong)uVar9 >> 0x3f;
    uVar9 = uVar5 & 0xffffffff;
    lVar4 = (uVar1 & 0xffffffffffffffea) + 0x16;
    if (uVar6 != 0) {
      do {
        if (lVar4 == 0) goto LAB_14001a2f5;
        lVar4 = lVar4 + -1;
        *(wchar_t *)(lVar7 + -0x14001ea30 + (longlong)pwVar8) = *pwVar8;
        uVar5 = uVar5 + 1;
        pwVar8 = pwVar8 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if (lVar4 != 0) {
      uVar9 = 0x80000005;
    }
  }
LAB_14001a2f5:
  *param_1 = (short)uVar5 * 2;
LAB_14001a2fd:
  return uVar9 & 0xffffffff;
}



===== RtlUnicodeStringValidateWorker @ 14001a318 =====

undefined8 RtlUnicodeStringValidateWorker(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  uVar1 = *param_1;
  uVar3 = 0;
  if ((((((uVar1 & 1) != 0) || (uVar2 = param_1[1], (uVar2 & 1) != 0)) || (uVar2 < uVar1)) ||
      (uVar2 == 0xffff)) || ((*(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== SleepstudyHelper_ComponentActive @ 14001a360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_ComponentActive(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_140022a20 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_140022a20)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_140022a20 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_140022a20)(param_1);
  }
  return iVar1;
}



===== SleepstudyHelper_ComponentInactive @ 14001a3e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_ComponentInactive(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_140022a28 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_140022a28)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_140022a28 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_140022a28)(param_1);
  }
  return iVar1;
}



===== SleepstudyHelper_GenerateGuid @ 14001a470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_GenerateGuid(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  ulonglong uVar2;
  
  if (DAT_1400229f0 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_1400229f0)(0);
  }
  uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 == 0) && (iVar1 == -0x3fffff45)) {
    iVar1 = 0;
    *param_3 = 0x4e604b5554e1f64d;
    param_3[1] = 0x3d7645417f83979a;
  }
  return iVar1;
}



===== SleepstudyHelper_UnregisterComponent @ 14001a4cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_UnregisterComponent(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_140022a18 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_140022a18)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_140022a18 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_140022a18)(param_1);
  }
  return iVar1;
}



===== RtlStringCchPrintfW @ 14001a554 =====

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



===== BtGenerateDWORD64Hash @ 14001a5d0 =====

NTSTATUS BtGenerateDWORD64Hash(PUCHAR param_1,ULONG param_2,undefined8 *param_3)

{
  NTSTATUS NVar1;
  BCRYPT_ALG_HANDLE local_res20;
  
  local_res20 = (BCRYPT_HANDLE)0x0;
  NVar1 = BCryptOpenAlgorithmProvider(&local_res20,L"SHA256",L"Microsoft Primitive Provider",0);
  if (-1 < NVar1) {
    NVar1 = BtGenerateDWORD64HashWithHandle(param_1,param_2,local_res20,param_3);
  }
  if (local_res20 != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(local_res20,0);
  }
  return NVar1;
}



===== BtGenerateDWORD64HashWithHandle @ 14001a664 =====

NTSTATUS BtGenerateDWORD64HashWithHandle
                   (PUCHAR param_1,ULONG param_2,BCRYPT_HANDLE param_3,undefined8 *param_4)

{
  NTSTATUS NVar1;
  PUCHAR pbHashObject;
  PUCHAR pbOutput;
  BCRYPT_HANDLE pvVar2;
  uint local_res20 [2];
  uint local_48;
  ULONG local_44;
  BCRYPT_HASH_HANDLE local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  
  pbOutput = (PUCHAR)0x0;
  *param_4 = 0;
  local_40 = (BCRYPT_HASH_HANDLE)0x0;
  pbHashObject = (PUCHAR)0x0;
  local_res20[0] = 0;
  local_48 = 0;
  local_44 = 0;
  pvVar2 = param_3;
  NVar1 = BCryptGetProperty(param_3,L"ObjectLength",(PUCHAR)local_res20,4,&local_44,0);
  if (NVar1 < 0) goto LAB_14001a7b9;
  pbHashObject = (PUCHAR)BthHashingLibAllocatePoolEx(pvVar2,(ulonglong)local_res20[0]);
  if (pbHashObject != (PUCHAR)0x0) {
    NVar1 = BCryptCreateHash(param_3,&local_40,pbHashObject,local_res20[0],(PUCHAR)0x0,0,0);
    if (NVar1 < 0) goto LAB_14001a7b9;
    NVar1 = BCryptHashData(local_40,param_1,param_2,0);
    if (NVar1 < 0) goto LAB_14001a7b9;
    NVar1 = BCryptGetProperty(param_3,L"HashDigestLength",(PUCHAR)&local_48,4,&local_44,0);
    if (NVar1 < 0) goto LAB_14001a7b9;
    pbOutput = (PUCHAR)BthHashingLibAllocatePoolEx(param_3,(ulonglong)local_48);
    if (pbOutput != (PUCHAR)0x0) {
      NVar1 = BCryptFinishHash(local_40,pbOutput,local_48,0);
      if (-1 < NVar1) {
        local_38 = *(undefined4 *)(pbOutput + 4);
        uStack_34 = *(undefined4 *)pbOutput;
        *param_4 = CONCAT44(uStack_34,local_38);
      }
      goto LAB_14001a7b9;
    }
  }
  NVar1 = -0x3fffff66;
LAB_14001a7b9:
  if (local_40 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_40);
    local_40 = (BCRYPT_HASH_HANDLE)0x0;
  }
  if (pbHashObject != (PUCHAR)0x0) {
    ExFreePool(pbHashObject);
  }
  if (pbOutput != (PUCHAR)0x0) {
    ExFreePool(pbOutput);
  }
  return NVar1;
}



===== BthHashingLibAllocatePoolEx @ 14001a824 =====

void BthHashingLibAllocatePoolEx(undefined8 param_1,undefined8 param_2)

{
  ExAllocatePool2(0x40,param_2,0x53485442);
  return;
}



===== GetImageTuple @ 14001a84c =====

/* WARNING: Removing unreachable block (ram,0x00014001a882) */

undefined8 GetImageTuple(undefined8 param_1,dword *param_2,dword *param_3)

{
  *param_2 = 0xbd2a9dfb;
  *param_3 = 0x34000;
  return 1;
}



===== InitializeTelemetryAssertsKMByDriverObject @ 14001a89c =====

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
          if (uVar2 == 0) goto LAB_14001a97a;
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
LAB_14001a97a:
        RtlFreeAnsiString(&local_38);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 14001a9a0 =====

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
    _DAT_140022a88 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140026040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140026008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140026078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 14001aa54 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM(undefined8 param_1,undefined4 param_2)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker
            (unaff_retaddr,1,"bthhfenum.sys",param_2,0,"Wait for ScoClosedEvent failed");
  return;
}



===== MicrosoftTelemetryAssertTriggeredMsgKM @ 14001aa90 =====

void MicrosoftTelemetryAssertTriggeredMsgKM(char *param_1)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,0,(char *)0x0,0xffffffff,0xffffffff,param_1)
  ;
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 14001aac0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,int param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,char *param_6)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  char *pcVar13;
  longlong *plVar14;
  byte *pbVar15;
  char *pcVar16;
  int iVar17;
  undefined1 *puVar18;
  longlong lVar19;
  undefined4 uVar20;
  undefined1 auStack_1c8 [8];
  undefined1 auStack_1c0 [120];
  int local_148;
  undefined4 local_144;
  char *local_140;
  char *local_138;
  undefined1 local_128 [32];
  undefined1 *local_108;
  undefined8 local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  longlong local_c8 [2];
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  longlong local_88 [2];
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  longlong local_58 [2];
  ulonglong local_48;
  
  puVar18 = auStack_1c8;
  local_48 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_140 = param_6;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_14001b2eb;
  local_148 = param_2;
  local_144 = param_4;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar18 = auStack_1c8;
  for (plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar11 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar11 = (longlong *)*plVar11) {
    plVar10 = plVar11 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar10 == param_1) goto LAB_14001ac08;
  }
  plVar10 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar19 = _DAT_fffff78000000320;
  puVar18 = auStack_1c8;
  if (plVar10 != (longlong *)0x0) {
    *plVar10 = (longlong)param_1;
    uVar7 = KeQueryTimeIncrement();
    puVar18 = auStack_1c8;
    plVar10[2] = 0;
    *(undefined4 *)(plVar10 + 3) = 0;
    plVar10[1] = (longlong)((ulonglong)uVar7 * lVar19) / 10000 + -0xea61;
    plVar11 = plVar10 + 4;
    plVar14 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar14 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar11 = (longlong *)(*pcVar2)();
      puVar18 = auStack_1c0;
    }
    *plVar11 = (longlong)plVar14;
    plVar11[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
    plVar14[1] = (longlong)plVar11;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar11;
LAB_14001ac08:
    *(int *)(plVar10 + 2) = (int)plVar10[2] + 1;
    *(int *)((longlong)plVar10 + 0x14) = *(int *)((longlong)plVar10 + 0x14) + 1;
    lVar3 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar18 + -8) = 0x14001ac18;
    uVar7 = KeQueryTimeIncrement();
    *(undefined4 *)(puVar18 + 0x78) = 0;
    *(undefined4 *)(puVar18 + 0x50) = 0;
    lVar19 = (longlong)((ulonglong)uVar7 * lVar3) / 10000;
    if (60000 < (ulonglong)(lVar19 - plVar10[1])) {
      *(undefined8 *)(puVar18 + -8) = 0x14001ac6d;
      uVar12 = GetImageTuple((ulonglong)uVar7 * lVar3,(dword *)(puVar18 + 0x78),
                             (dword *)(puVar18 + 0x50));
      uVar7 = *(uint *)(puVar18 + 0x50);
      iVar8 = (int)uVar12;
      if ((((iVar8 == 0) || (param_1 < &IMAGE_DOS_HEADER_140000000)) ||
          ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar7) <
           (IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + 1))) ||
         ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar7) < param_1)) {
        iVar17 = 0;
      }
      else {
        iVar17 = (int)param_1 + -0x40000000;
      }
      *(int *)(puVar18 + 0x74) = (int)plVar10[2];
      *(undefined4 *)(puVar18 + 0x50) = *(undefined4 *)((longlong)plVar10 + 0x14);
      *(int *)(puVar18 + 0x70) = (int)plVar10[3];
      plVar10[1] = lVar19;
      *(undefined8 *)(puVar18 + -8) = 0x14001acc5;
      KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
      if (param_3 == (char *)0x0) {
        param_3 = g_ModuleName;
      }
      uVar20 = 10;
      uVar1 = *(uint *)(puVar18 + 0x78);
      local_138 = param_3;
      if (local_148 == 0) {
        if (5 < DAT_140026040) {
          *(undefined8 *)(puVar18 + -8) = 0x14001ae8d;
          pcVar13 = g_ModuleName;
          cVar5 = _tlgKeywordOn(0x140026040,0x400000000000);
          if (cVar5 != '\0') {
            local_108 = puVar18 + 0x68;
            *(undefined4 *)(puVar18 + 0x68) = uVar20;
            local_f8 = puVar18 + 100;
            local_100 = 4;
            *(int *)(puVar18 + 100) = iVar17;
            local_e8 = puVar18 + 0x60;
            local_f0 = 4;
            local_e0 = 4;
            *(uint *)(puVar18 + 0x60) = -(uint)(iVar8 != 0) & uVar1;
            local_d0 = 4;
            local_d8 = puVar18 + 0x5c;
            *(uint *)(puVar18 + 0x5c) = -(uint)(iVar8 != 0) & uVar7;
            pcVar16 = "<unknown>";
            if (pcVar13 != (char *)0x0) {
              pcVar16 = pcVar13;
            }
            *(undefined8 *)(puVar18 + -8) = 0x14001af11;
            _tlgCreate1Sz_char(local_c8,pcVar16);
            local_b8 = puVar18 + 0x58;
            *(undefined4 *)(puVar18 + 0x54) = *(undefined4 *)(puVar18 + 0x50);
            local_a8 = puVar18 + 0x54;
            *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x74);
            local_b0 = 4;
            local_a0 = 4;
            *(undefined8 *)(puVar18 + -8) = 0x14001af4a;
            bVar6 = KeGetCurrentIrql();
            local_90 = 4;
            *(uint *)(puVar18 + 0x6c) = (uint)bVar6;
            local_98 = puVar18 + 0x6c;
            pcVar13 = local_140;
            if (local_140 == (char *)0x0) {
              pcVar13 = "<unknown>";
            }
            *(undefined8 *)(puVar18 + -8) = 0x14001af7e;
            _tlgCreate1Sz_char(local_88,pcVar13);
            *(undefined1 **)(puVar18 + 0x28) = local_128;
            pbVar15 = &DAT_14001f798;
            *(undefined4 *)(puVar18 + 0x20) = 0xb;
            goto LAB_14001af96;
          }
        }
      }
      else if (5 < DAT_140026040) {
        *(undefined8 *)(puVar18 + -8) = 0x14001ad1c;
        pcVar13 = g_ModuleName;
        cVar5 = _tlgKeywordOn(0x140026040,0x400000000000);
        if (cVar5 != '\0') {
          local_108 = puVar18 + 0x78;
          *(undefined4 *)(puVar18 + 0x78) = uVar20;
          local_f8 = puVar18 + 0x7c;
          local_100 = 4;
          *(int *)(puVar18 + 0x7c) = iVar17;
          local_e8 = puVar18 + 0x6c;
          local_f0 = 4;
          local_e0 = 4;
          *(uint *)(puVar18 + 0x6c) = -(uint)(iVar8 != 0) & uVar1;
          local_d0 = 4;
          local_d8 = puVar18 + 0x54;
          *(uint *)(puVar18 + 0x54) = -(uint)(iVar8 != 0) & uVar7;
          pcVar16 = "<unknown>";
          if (pcVar13 != (char *)0x0) {
            pcVar16 = pcVar13;
          }
          *(undefined8 *)(puVar18 + -8) = 0x14001ada0;
          _tlgCreate1Sz_char(local_c8,pcVar16);
          local_b8 = puVar18 + 0x58;
          *(undefined4 *)(puVar18 + 0x5c) = *(undefined4 *)(puVar18 + 0x50);
          local_a8 = puVar18 + 0x5c;
          *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x74);
          local_b0 = 4;
          local_a0 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x14001add9;
          bVar6 = KeGetCurrentIrql();
          *(uint *)(puVar18 + 0x60) = (uint)bVar6;
          local_98 = puVar18 + 0x60;
          local_90 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x14001ae03;
          _tlgCreate1Sz_char(local_88,local_138);
          local_78 = puVar18 + 100;
          *(undefined4 *)(puVar18 + 0x68) = param_5;
          local_68 = puVar18 + 0x68;
          *(undefined4 *)(puVar18 + 100) = local_144;
          local_70 = 4;
          pcVar13 = local_140;
          if (local_140 == (char *)0x0) {
            pcVar13 = "<unknown>";
          }
          local_60 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x14001ae4d;
          _tlgCreate1Sz_char(local_58,pcVar13);
          *(undefined1 **)(puVar18 + 0x28) = local_128;
          pbVar15 = &DAT_14001f648;
          *(undefined4 *)(puVar18 + 0x20) = 0xe;
LAB_14001af96:
          *(undefined8 *)(puVar18 + -8) = 0x14001afa8;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x140026040,pbVar15,0,0,*(undefined4 *)(puVar18 + 0x20),
                     *(undefined8 **)(puVar18 + 0x28));
        }
      }
      if ((DAT_140026078 == 0) || (*(int *)(puVar18 + 0x70) != 0)) goto LAB_14001b2eb;
      *(undefined8 *)(puVar18 + -8) = 0x14001afc7;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_14001b2eb;
      *(undefined4 *)(puVar18 + 0x40) = 0;
      *(undefined8 *)(puVar18 + 0x38) = 0;
      *(undefined8 *)(puVar18 + 0x30) = 0;
      *(ulonglong *)(puVar18 + 0x28) = (ulonglong)uVar7;
      *(ulonglong *)(puVar18 + 0x20) = (ulonglong)uVar1;
      *(undefined8 *)(puVar18 + -8) = 0x14001b00a;
      iVar9 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      uVar12 = 0;
      if (local_148 == 0) {
        if (5 < DAT_140026040) {
          *(undefined8 *)(puVar18 + -8) = 0x14001b196;
          cVar5 = _tlgKeywordOn(0x140026040,0x400000000000);
          if (cVar5 != '\0') {
            local_108 = puVar18 + 0x70;
            *(undefined4 *)(puVar18 + 0x70) = 10;
            local_f8 = puVar18 + 0x68;
            local_100 = 4;
            local_e8 = puVar18 + 100;
            *(int *)(puVar18 + 0x68) = iVar17;
            local_f0 = 4;
            *(uint *)(puVar18 + 100) = -(uint)(iVar8 != 0) & uVar1;
            local_e0 = 4;
            local_d0 = 4;
            *(uint *)(puVar18 + 0x60) = -(uint)(iVar8 != 0) & uVar7;
            local_d8 = puVar18 + 0x60;
            pcVar13 = "<unknown>";
            if (g_ModuleName != (char *)0x0) {
              pcVar13 = g_ModuleName;
            }
            *(undefined8 *)(puVar18 + -8) = 0x14001b222;
            _tlgCreate1Sz_char(local_c8,pcVar13);
            pbVar15 = &DAT_14001f805;
            *(undefined4 *)(puVar18 + 0x5c) = *(undefined4 *)(puVar18 + 0x74);
            local_b8 = puVar18 + 0x5c;
            *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x50);
            local_a8 = puVar18 + 0x58;
            local_98 = puVar18 + 0x54;
            *(undefined1 **)(puVar18 + 0x28) = local_128;
            *(undefined4 *)(puVar18 + 0x20) = 10;
            local_b0 = 4;
            local_a0 = 4;
            *(int *)(puVar18 + 0x54) = iVar9;
            local_90 = 4;
            goto LAB_14001b282;
          }
        }
      }
      else if (5 < DAT_140026040) {
        *(undefined8 *)(puVar18 + -8) = 0x14001b042;
        cVar5 = _tlgKeywordOn(0x140026040,0x400000000000);
        if (cVar5 != '\0') {
          local_108 = puVar18 + 0x70;
          *(undefined4 *)(puVar18 + 0x70) = 10;
          local_f8 = puVar18 + 0x68;
          local_100 = 4;
          local_e8 = puVar18 + 100;
          *(int *)(puVar18 + 0x68) = iVar17;
          local_f0 = 4;
          *(uint *)(puVar18 + 100) = -(uint)(iVar8 != 0) & uVar1;
          local_e0 = 4;
          local_d0 = 4;
          *(uint *)(puVar18 + 0x60) = -(uint)(iVar8 != 0) & uVar7;
          local_d8 = puVar18 + 0x60;
          pcVar13 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar13 = g_ModuleName;
          }
          *(undefined8 *)(puVar18 + -8) = 0x14001b0ce;
          _tlgCreate1Sz_char(local_c8,pcVar13);
          *(undefined4 *)(puVar18 + 0x5c) = *(undefined4 *)(puVar18 + 0x74);
          local_b8 = puVar18 + 0x5c;
          *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x50);
          local_a8 = puVar18 + 0x58;
          local_98 = puVar18 + 0x54;
          local_b0 = 4;
          local_a0 = 4;
          *(int *)(puVar18 + 0x54) = iVar9;
          local_90 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x14001b123;
          _tlgCreate1Sz_char(local_88,local_138);
          pbVar15 = &DAT_14001f6f2;
          *(undefined4 *)(puVar18 + 0x6c) = local_144;
          local_78 = puVar18 + 0x6c;
          *(undefined4 *)(puVar18 + 0x7c) = param_5;
          local_68 = puVar18 + 0x7c;
          *(undefined1 **)(puVar18 + 0x28) = local_128;
          *(undefined4 *)(puVar18 + 0x20) = 0xd;
          local_70 = 4;
          local_60 = 4;
LAB_14001b282:
          *(undefined8 *)(puVar18 + -8) = 0x14001b291;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x140026040,pbVar15,0,uVar12,*(undefined4 *)(puVar18 + 0x20),
                     *(undefined8 **)(puVar18 + 0x28));
        }
      }
      if (iVar9 != 0) goto LAB_14001b2eb;
      *(undefined8 *)(puVar18 + -8) = 0x14001b2a4;
      uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar11[-4] == param_1) {
            *(int *)(plVar11 + -1) = (int)plVar11[-1] + 1;
            break;
          }
          plVar11 = (longlong *)*plVar11;
        } while ((longlong **)plVar11 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar18 + -8) = 0x14001b2e6;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
LAB_14001b2eb:
  *(undefined8 *)(puVar18 + -8) = 0x14001b2fa;
  return;
}



===== UninitializeTelemetryAssertsKM @ 14001b31c =====

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
    *(undefined8 *)(puVar6 + -8) = 0x14001b3af;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x14001b3cc;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_140026098;
    DAT_140026098 = 0;
    DAT_140026078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001b3f6;
    EtwUnregister(uVar3);
    uVar3 = DAT_140026028;
    DAT_140026028 = 0;
    _DAT_140026008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001b418;
    EtwUnregister(uVar3);
    uVar3 = DAT_140026060;
    DAT_140026060 = 0;
    DAT_140026040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001b43a;
    EtwUnregister(uVar3);
  }
  return;
}



===== __GSHandlerCheck @ 14001b458 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001b47c =====

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



===== __GSHandlerCheck_SEH @ 14001b4e4 =====

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



===== __cpu_features_init @ 14001b580 =====

/* WARNING: Removing unreachable block (ram,0x00014001b5ea) */
/* WARNING: Removing unreachable block (ram,0x00014001b599) */
/* WARNING: Removing unreachable block (ram,0x00014001b58a) */

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



===== __security_check_cookie @ 14001b650 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14001b690 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14001b6c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001b6c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14001b6f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 14001b740 =====

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



===== memset @ 14001ba40 =====

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



===== __memset_repmovs @ 14001bb80 =====

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



===== __memset_query @ 14001bc00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14001bc80 =====

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



===== __memset_spec_ermsb_repmovsb @ 14001bdc0 =====

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



===== __memset_spec_plain @ 14001be40 =====

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



===== DetermineRoleEnablement @ 140027008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl DetermineRoleEnablement(struct WDFDEVICE__ * __ptr64) */

long __cdecl DetermineRoleEnablement(WDFDEVICE__ *param_1)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  char cVar5;
  longlong lVar6;
  char cVar7;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 *local_90;
  undefined4 *local_88;
  longlong *local_78;
  undefined4 local_70;
  uint local_68;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined *local_40;
  undefined8 local_38;
  longlong local_30;
  longlong lStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_48 = 0x18;
  local_40 = &DEVPKEY_Bluetooth_ServiceGUID;
  local_88 = local_58;
  local_90 = &local_50;
  local_38 = 0;
  local_58[0] = 0;
  local_50 = 0;
  local_98 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xd90))(WdfDriverGlobals,param_1,&local_48,0x200);
  if (-1 < iVar1) {
    plVar2 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_50,0);
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
    lVar6 = *plVar2 + -0x100000000000111e;
    if (lVar6 == 0) {
      lVar6 = plVar2[1] + 0x4cb64a07fffff80;
    }
    *(uint *)(lVar3 + 0x1a0) = (uint)(lVar6 == 0);
    plVar4 = (longlong *)GetEnabledRemoteService((WDFDEVICE__ *)&local_30);
    local_30 = *plVar4;
    lStack_28 = plVar4[1];
    lVar6 = *plVar2 - local_30;
    if (lVar6 == 0) {
      lVar6 = plVar2[1] - lStack_28;
    }
    *(uint *)(lVar3 + 700) = (uint)(lVar6 == 0);
    cVar7 = '\x01';
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar5 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar7 = '\0';
    }
    if ((cVar5 != '\0') || (cVar7 != '\0')) {
      local_70 = *(undefined4 *)(lVar3 + 0x1a0);
      local_78 = plVar2;
      local_68 = (uint)(lVar6 == 0);
      WPP_RECORDER_AND_TRACE_SF__guid_ll
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar7,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  wil::details::
  unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
              *)&local_50);
  return iVar1;
}



===== GetEnabledRemoteService @ 1400271f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct _GUID __cdecl GetEnabledRemoteService(struct WDFDEVICE__ * __ptr64) */

WDFDEVICE__ * __cdecl GetEnabledRemoteService(WDFDEVICE__ *param_1)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong *plVar10;
  undefined2 uVar11;
  char cVar12;
  undefined8 in_RDX;
  longlong *plVar13;
  char cVar14;
  bool bVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined2 local_58 [2];
  undefined2 local_54 [10];
  
  *(GUID *)param_1 = _GUID_00000000_0000_0000_0000_000000000000;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,in_RDX,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  bVar5 = false;
  bVar6 = false;
  bVar2 = false;
  bVar4 = false;
  uVar9 = (**(code **)(WdfFunctions_01015 + 0x138))(WdfDriverGlobals);
  plVar10 = (longlong *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar9,PTR__WDF_HfpRoleConfigurationSet_TYPE_INFO_140022050);
  cVar14 = '\x01';
  plVar1 = plVar10 + 6;
  plVar13 = plVar10;
  if (plVar10 != plVar1) {
    do {
      bVar3 = false;
      uVar11 = 0;
      bVar15 = false;
      local_58[0] = 0;
      if (*(char *)((longlong)plVar13 + 0x14) != '\0') {
        local_54[0] = 0;
        uVar9 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,in_RDX);
        iVar7 = BtaMpmGetRemoteDeviceProfileVersionAndAttribute
                          (uVar9,lVar8 + 0x1b0,plVar13,&HandsfreeServiceClass_UUID,0x311,local_54,
                           local_58);
        if (iVar7 < 0) {
          if (iVar7 != -0x3ffffaf4) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
               (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
              cVar12 = '\0';
            }
            if ((cVar12 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF__guid_d
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
            goto LAB_140027442;
          }
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
            cVar12 = '\0';
          }
          if ((cVar12 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF__guid_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,10,
                       &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,plVar13);
          }
          bVar3 = true;
          uVar11 = 0;
        }
        else {
          bVar3 = true;
LAB_140027442:
          uVar11 = local_58[0];
        }
        bVar15 = *(uint *)(plVar13 + 2) == (*(uint *)(lVar8 + 0x1b8) >> 8 & 0x1f);
      }
      if ((*plVar13 == 0x100000000000111e) && (plVar13[1] == -0x4cb64a07fffff80)) {
        if (!bVar3) {
          uVar11 = 0;
        }
        *(undefined2 *)(lVar8 + 0x2ba) = uVar11;
        bVar4 = bVar3;
        bVar5 = bVar15;
      }
      else if ((*plVar13 == 0x100000000000111f) && (plVar13[1] == -0x4cb64a07fffff80)) {
        if (!bVar3) {
          uVar11 = 0;
        }
        *(undefined2 *)(lVar8 + 0x2b8) = uVar11;
        bVar2 = bVar3;
        bVar6 = bVar15;
      }
      plVar13 = plVar13 + 3;
    } while (plVar13 != plVar1);
    if (bVar4) {
      if ((!bVar2) || (bVar5)) {
        uVar16 = 0x111e;
        uVar17 = 0x10000000;
        uVar18 = 0x80000080;
        uVar19 = 0xfb349b5f;
        goto LAB_140027565;
      }
      if (!bVar6) {
        uVar16 = (undefined4)*plVar1;
        uVar17 = *(undefined4 *)((longlong)plVar10 + 0x34);
        uVar18 = (undefined4)plVar10[7];
        uVar19 = *(undefined4 *)((longlong)plVar10 + 0x3c);
        goto LAB_140027565;
      }
    }
  }
  uVar16 = 0x111f;
  uVar17 = 0x10000000;
  uVar18 = 0x80000080;
  uVar19 = 0xfb349b5f;
LAB_140027565:
  *(undefined4 *)param_1 = uVar16;
  *(undefined4 *)(param_1 + 4) = uVar17;
  *(undefined4 *)(param_1 + 8) = uVar18;
  *(undefined4 *)(param_1 + 0xc) = uVar19;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar12 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar14 = '\0';
  }
  if ((cVar12 != '\0') || (cVar14 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF__guid_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,cVar14,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xc,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,param_1);
  }
  return param_1;
}



===== GetRoleConfigurationState @ 140027604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetRoleConfigurationState(struct HfpRoleConfigurationSet * __ptr64) */

long __cdecl GetRoleConfigurationState(HfpRoleConfigurationSet *param_1)

{
  HfpRoleConfigurationSet *pHVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  undefined8 *puVar8;
  longlong lVar9;
  char cVar10;
  longlong *plVar11;
  char cVar12;
  uint uVar13;
  undefined1 auStackY_158 [32];
  int local_f8;
  int local_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>
  local_b8 [24];
  unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>
  local_a0 [16];
  undefined4 local_90;
  uint uStack_8c;
  longlong local_88 [2];
  wchar_t *local_78;
  longlong local_70 [3];
  wchar_t *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  local_78 = L"HandsFree";
  local_88[0] = 0x100000000000111f;
  local_88[1] = 0xfb349b5f80000080;
  local_70[0] = 0;
  local_58 = L"AudioGateway";
  local_70[1] = 0x100000000000111e;
  local_70[2] = 0xfb349b5f80000080;
  local_50 = 0;
  memset(param_1,0,0x40);
  pHVar1 = param_1 + 0x30;
  *(undefined8 *)pHVar1 = 0x100000000000111e;
  *(undefined8 *)(param_1 + 0x38) = 0xfb349b5f80000080;
  local_c8 = 0;
  uStack_c0 = 0;
  RtlInitUnicodeString
            (&local_c8,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Bluetooth\\Audio\\Hfp");
  local_f0 = 0;
  wil::
  out_param<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
            (local_a0);
  iVar6 = (**(code **)(WdfFunctions_01015 + 0x728))(WdfDriverGlobals,0,&local_c8,0x20019);
  wil::details::
  out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
  ::
  ~out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
            ((out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
              *)local_a0);
  local_f8 = 0;
  bVar5 = true;
  if (iVar6 < 0) {
LAB_140027800:
    if (iVar6 == -0x3fffffcc) {
      iVar6 = 0;
      goto LAB_14002780f;
    }
  }
  else {
    local_e8 = 0;
    uStack_e0 = 0;
    RtlInitUnicodeString(&local_e8,L"RolePreference");
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_f0,&local_e8,&local_f8)
    ;
    if (iVar6 < 0) goto LAB_140027800;
    puVar8 = &HandsfreeAudioGatewayServiceClass_UUID;
    if (local_f8 != 1) {
      puVar8 = &HandsfreeServiceClass_UUID;
    }
    uVar4 = puVar8[1];
    *(undefined8 *)pHVar1 = *puVar8;
    *(undefined8 *)(param_1 + 0x38) = uVar4;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar10 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (cVar12 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar12 = '\0';
    }
    if ((cVar10 != '\0') || (cVar12 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF__guid_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,cVar12,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xe,
                 &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,pHVar1);
    }
LAB_14002780f:
    uVar13 = 0;
    plVar11 = local_88;
    do {
      lVar2 = *plVar11;
      lVar3 = plVar11[1];
      uStack_8c = uStack_8c & 0xffffff00;
      if ((lVar2 == 0x100000000000111e) && (lVar3 == -0x4cb64a07fffff80)) {
        local_90 = 4;
      }
      else {
        lVar9 = lVar2 + -0x100000000000111f;
        if (lVar9 == 0) {
          lVar9 = lVar3 + 0x4cb64a07fffff80;
        }
        if (lVar9 == 0) {
          local_90 = 2;
        }
      }
      if (((code *)plVar11[3] == (code *)0x0) || (iVar7 = (*(code *)plVar11[3])(), iVar7 != 0)) {
        local_e8 = 0;
        if (-1 < iVar6) {
          local_d8 = 0;
          uStack_d0 = 0;
          RtlInitUnicodeString(&local_d8,plVar11[2]);
          wil::
          out_param<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
                    (local_b8);
          iVar6 = (**(code **)(WdfFunctions_01015 + 0x728))
                            (WdfDriverGlobals,local_f0,&local_d8,0x20019);
          wil::details::
          out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
          ::
          ~out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
                    ((out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
                      *)local_b8);
        }
        local_f4 = 0;
        if (iVar6 < 0) {
LAB_140027a65:
          if (iVar6 != -0x3fffffcc) {
            wil::details::
            unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
            ::
            ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
                      ((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
                        *)&local_e8);
            break;
          }
          uStack_8c = uStack_8c & 0xffffff00;
        }
        else {
          local_d8 = 0;
          uStack_d0 = 0;
          RtlInitUnicodeString(&local_d8,L"Enabled");
          iVar6 = (**(code **)(WdfFunctions_01015 + 0x780))
                            (WdfDriverGlobals,local_e8,&local_d8,&local_f4);
          if (iVar6 < 0) goto LAB_140027a65;
          if (local_f4 == 0) {
            uStack_8c = (uint)uStack_8c._1_3_ << 8;
          }
          else {
            uStack_8c = CONCAT31(uStack_8c._1_3_,1);
          }
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
            cVar10 = '\0';
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
             (cVar12 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
            cVar12 = '\0';
          }
          if ((cVar10 != '\0') || (cVar12 != '\0')) {
            WPP_RECORDER_AND_TRACE_SF__guid_ld
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,cVar12,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
        iVar6 = 0;
        wil::details::
        unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
        ::
        ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
                  ((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
                    *)&local_e8);
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
          cVar10 = '\0';
        }
        if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
           (cVar12 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
          cVar12 = '\0';
        }
        if ((cVar10 != '\0') || (cVar12 != '\0')) {
          WPP_RECORDER_AND_TRACE_SF__guid_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,cVar12,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xf,
                     &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,plVar11);
        }
        uStack_8c = uStack_8c & 0xffffff00;
      }
      uVar13 = uVar13 + 1;
      *(longlong *)param_1 = lVar2;
      *(longlong *)(param_1 + 8) = lVar3;
      plVar11 = plVar11 + 4;
      *(longlong *)(param_1 + 0x10) = CONCAT44(uStack_8c,local_90);
      param_1 = param_1 + 0x18;
    } while (uVar13 < 2);
    if (-1 < iVar6) goto LAB_140027b2c;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar5 = false;
  }
  if ((bVar5) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x11,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)iVar6);
  }
LAB_140027b2c:
  wil::details::
  unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
              *)&local_f0);
  return iVar6;
}



===== InitializeDeviceFriendlyName @ 140027b6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl InitializeDeviceFriendlyName(struct WDFDEVICE__ * __ptr64) */

void __cdecl InitializeDeviceFriendlyName(WDFDEVICE__ *param_1)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined4 uVar7;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((*(uint *)(lVar4 + 0x1a8) & 4) != 0) {
    local_res10 = 0;
    local_res18 = 0;
    iVar3 = *(int *)(lVar4 + 0x1a0);
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
    uVar7 = 0;
    iVar3 = BtaMpmBuildIndirectStringFromMessageWithSingleUTF8Arg
                      (*(undefined8 *)(lVar5 + 0x18),(-(uint)(iVar3 != 0) & 0xfffffffe) + 3,
                       L"@System32\\drivers\\bthhfenum.sys",lVar4 + 0x1bc,0xf8,0x46485442,
                       &local_res10,&local_res18);
    uVar2 = local_res10;
    if (-1 < iVar3) {
      iVar3 = (int)local_res18 + 2;
      uVar6 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
      bVar1 = true;
      iVar3 = IoSetDevicePropertyData
                        (uVar6,&DEVPKEY_Device_FriendlyName,0,1,CONCAT44(uVar7,0x19),iVar3,uVar2);
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar1 = false;
        }
        if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_l
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x12,
                     &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)iVar3);
        }
      }
      ExFreePoolWithTag(local_res10,0x46485442);
    }
  }
  return;
}



===== Bus_EvtDeviceD0Exit @ 140027d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Bus_EvtDeviceD0Exit(undefined8 param_1,undefined1 param_2)

{
  longlong lVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_WDF_POWER_DEVICE_STATEl
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,
               in_stack_ffffffffffffffd0,0x2f,in_stack_ffffffffffffffe0,param_2,
               (char)*(undefined4 *)(lVar1 + 700));
  }
  if (*(int *)(lVar1 + 700) != 0) {
    BthHwExitD0(param_1);
  }
  return 0;
}



===== Bus_EvtDevicePrepareHardware @ 140027e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Bus_EvtDevicePrepareHardware(undefined8 param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_ll
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0x31,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)*(undefined4 *)(lVar1 + 0x1a0)
               ,(char)*(undefined4 *)(lVar1 + 700));
  }
  if (*(int *)(lVar1 + 700) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = BthHwInitialize(param_1);
  }
  return uVar2;
}



===== Bus_EvtDeviceReleaseHardware @ 140027ef0 =====

void Bus_EvtDeviceReleaseHardware(undefined8 param_1)

{
  char cVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x32,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  BthHwUnInitialize(param_1);
  return;
}



===== Bus_EvtDriverCleanup @ 140027f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_EvtDriverCleanup(undefined8 param_1,undefined8 param_2,undefined8 param_3,_GUID *param_4)

{
  undefined *puVar1;
  char cVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  _tlgProvider_t *p_Var5;
  undefined7 uVar6;
  undefined1 uVar7;
  wchar_t *local_res10;
  undefined8 local_res18 [2];
  
  uVar6 = (undefined7)((ulonglong)param_3 >> 8);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  uVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar2 != '\0') || ((bool)uVar7)) {
    param_4 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,uVar7,param_4,4,4,0x13,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids);
  }
  if (5 < DAT_140022000) {
    p_Var5 = (_tlgProvider_t *)&DAT_140022000;
    cVar2 = _tlgKeywordOn(0x140022000,0x400000000000);
    if (cVar2 != '\0') {
      local_res18[0] = 0x2000800;
      local_res10 = L"BthHfEnum.sys";
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>_>
                (p_Var5,&DAT_14001ed11,(_GUID *)CONCAT71(uVar6,uVar7),param_4,
                 (_tlgWrapperByVal<8> *)local_res18,(_tlgWrapSz<unsigned_short> *)&local_res10);
    }
  }
  uVar4 = DAT_140022020;
  DAT_140022020 = 0;
  DAT_140022000 = 0;
  EtwUnregister(uVar4);
  puVar1 = DAT_140022628;
  if (DAT_140022628 != (undefined *)0x0) {
    uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar3 != 0) ||
       ((puVar1 != &SleepstudyHelperUnsupportedHandle && (DAT_1400229e8 != (code *)0x0)))) {
      (*DAT_1400229e8)(puVar1);
    }
    DAT_140022628 = (undefined *)0x0;
  }
  UninitializeTelemetryAssertsKM();
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar4);
  wil_UninitializeFeatureStaging();
  return;
}



===== Bus_EvtInternalIoDeviceControl @ 140028100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_EvtInternalIoDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined1 uVar1;
  char cVar2;
  bool bVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar2 != '\0') || (bVar3)) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
    WPP_RECORDER_AND_TRACE_SF_qIOCTL_BTHHFP
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffffd0,0x2d,
               in_stack_ffffffffffffffe0,uVar1,param_5);
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0xc0000010,0);
  return;
}



===== Bus_EvtIoDeviceControl @ 1400281f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_EvtIoDeviceControl
               (ulonglong param_1,WDFREQUEST__ *param_2,undefined8 param_3,undefined8 param_4,
               uint param_5)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  WDFDEVICE__ *pWVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  code *pcVar7;
  undefined **ppuVar8;
  uint uVar9;
  ulong uVar10;
  char cVar11;
  char cVar12;
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  ulonglong local_38 [2];
  
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar5,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_38[0] = 0;
  pWVar4 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  cVar12 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (param_1 = CONCAT71((int7)(param_1 >> 8),1), (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    param_1 = param_1 & 0xffffffffffffff00;
  }
  ppuVar8 = &WPP_RECORDER_INITIALIZED;
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar11 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar11 = '\0';
  }
  if (((char)param_1 != '\0') || (cVar11 != '\0')) {
    ppuVar8 = *(undefined ***)(WPP_GLOBAL_Control + 0x18);
    WPP_RECORDER_AND_TRACE_SF_qIOCTL_BTHHFP
              (ppuVar8,(char)param_1,cVar11,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,
               in_stack_ffffffffffffffa0,0x2b,in_stack_ffffffffffffffb0,(char)pWVar4,(char)param_5);
  }
  if (param_5 == 0x220003) {
    uVar5 = IoctlGetDeviceObject(pWVar4,param_2,local_38);
    iVar1 = (int)uVar5;
LAB_140028380:
    pcVar7 = *(code **)(WdfFunctions_01015 + 0x848);
    uVar6 = local_38[0];
  }
  else {
    if (param_5 == 0x220007) {
      uVar5 = BypassIoctlGetKsNodeTypes(pWVar4,param_2,local_38);
      iVar1 = (int)uVar5;
      goto LAB_140028380;
    }
    if ((param_5 == 0x220193) || (param_5 == 0x220037)) {
      uVar6 = BypassIoctlGetDescriptor(pWVar4,param_2,local_38);
      iVar1 = (int)uVar6;
      goto LAB_140028380;
    }
    if (param_5 == 0x220197) {
      uVar5 = BypassIoctlGetVolumePropertyValues(ppuVar8,param_2,local_38);
      iVar1 = (int)uVar5;
      goto LAB_140028380;
    }
    if (lVar2 != *(longlong *)(lVar3 + 0x138)) {
      if (lVar2 != *(longlong *)(lVar3 + 0x140)) goto LAB_1400286d9;
      if (0x220033 < param_5) {
        if (param_5 == 0x22003b) {
          BypassIoctlGetNrecDisableStatusUpdate(pWVar4,param_2);
          goto LAB_1400286fc;
        }
        if (param_5 == 0x22003f) {
          HandleAudioDeviceGetCodecId(pWVar4,param_2);
          goto LAB_1400286fc;
        }
        if (param_5 == 0x220043) {
          HandleAudioDeviceCapabilitiesIndication(pWVar4,param_2);
          goto LAB_1400286fc;
        }
        if (param_5 == 0x2207d3) {
          uVar9 = 0;
        }
        else {
          if (param_5 != 0x2207d7) {
            if (param_5 == 0x2207db) {
              uVar10 = 1;
            }
            else {
              if (param_5 != 0x2207df) {
                if (param_5 == 0x2207e3) {
                  uVar9 = 0;
                }
                else {
                  if (param_5 != 0x2207e7) goto LAB_1400286d9;
                  uVar9 = 1;
                }
                ScoStreamGetLastCorrelatedPosition(pWVar4,uVar9,param_2);
                goto LAB_1400286fc;
              }
              uVar10 = 2;
            }
            ScoStreamFlushRequest(pWVar4,uVar10,param_2);
            goto LAB_1400286fc;
          }
          uVar9 = 1;
        }
        ScoStreamTransferRequest(pWVar4,uVar9,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x220033) {
        ScoStreamGetStatusUpdate(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 < 0x220020) {
        if (param_5 == 0x22001f) {
          BypassIoctlGetSpeakerVolumeStatusUpdate(pWVar4,param_2);
          goto LAB_1400286fc;
        }
        if (param_5 == 0x22000b) {
          uVar5 = BypassIoctlGetContainerId(pWVar4,param_2,local_38);
          iVar1 = (int)uVar5;
        }
        else if (param_5 == 0x22000f) {
          uVar5 = BypassIoctlRequestConnect(pWVar4,param_1,local_38);
          iVar1 = (int)uVar5;
        }
        else if (param_5 == 0x220013) {
          uVar5 = BypassIoctlRequestDisconnect(pWVar4,param_1,local_38);
          iVar1 = (int)uVar5;
        }
        else {
          if (param_5 == 0x220017) {
            BypassIoctlGetConnectionStatusUpdate(pWVar4,param_2);
            goto LAB_1400286fc;
          }
          if (param_5 != 0x22001b) goto LAB_1400286d9;
          iVar1 = BypassIoctlSetSpeakerVolume(pWVar4,param_2,local_38);
        }
      }
      else {
        if (param_5 != 0x220023) {
          if (param_5 == 0x220027) {
            BypassIoctlGetMicVolumeStatusUpdate(pWVar4,param_2);
            goto LAB_1400286fc;
          }
          if (param_5 == 0x22002b) {
            HandleAudioDriverScoOpen(pWVar4,param_2);
            goto LAB_1400286fc;
          }
          if (param_5 == 0x22002f) {
            HandleAudioDriverScoClose(pWVar4,(ulonglong)param_2);
            goto LAB_1400286fc;
          }
          goto LAB_1400286d9;
        }
        iVar1 = BypassIoctlSetMicVolume(pWVar4,param_2,local_38);
      }
      goto LAB_140028380;
    }
    if (0x2a0018 < param_5) {
      if (param_5 == 0x2a001c) {
        HandleServiceAGCapabilitiesIndicationRequest(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x2a0020) {
        HandleServiceCodecNegotiationIndicationRequest(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x2a0024) {
        ScoHandleServiceScoStatusIndicationRequest(pWVar4,(longlong)param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x2a0028) {
        ScoHandleServiceScoRequestAcknowledgementRequest(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x2a002c) {
        BthIoctlCloseSco(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x2a0030) {
        HandleSetDevPKey(pWVar4,param_2);
        goto LAB_1400286fc;
      }
LAB_1400286d9:
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
      goto LAB_1400286fc;
    }
    if (param_5 == 0x2a0018) {
      BthIoctlOpenSco(pWVar4,param_2);
      goto LAB_1400286fc;
    }
    if (param_5 != 0x2a0000) {
      if (param_5 == 0x2a0004) {
        BthIoctlSlcStatus(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x2a0008) {
        BthIoctlAtResponse(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x2a000c) {
        BthIoctlAtCommand(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      if (param_5 == 0x2a0010) {
        iVar1 = BthIntIoctlGetDeviceInformation(pWVar4,param_2,local_38);
        goto LAB_140028380;
      }
      if (param_5 == 0x2a0014) {
        BthIoctlSetCodec(pWVar4,param_2);
        goto LAB_1400286fc;
      }
      goto LAB_1400286d9;
    }
    uVar6 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      iVar1 = BthIoctlSetServiceEventsOld(pWVar4,param_2);
    }
    else {
      uVar5 = BthIoctlSetServiceEvents(pWVar4,param_2);
      iVar1 = (int)uVar5;
    }
    uVar6 = 0;
    pcVar7 = *(code **)(WdfFunctions_01015 + 0x848);
  }
  (*pcVar7)(WdfDriverGlobals,param_2,iVar1,uVar6);
LAB_1400286fc:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar11 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar12 = '\0';
  }
  if ((cVar11 != '\0') || (cVar12 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qIOCTL_BTHHFP
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,cVar12,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x2c,
               in_stack_ffffffffffffffb0,(char)pWVar4,(char)param_5);
  }
  return;
}



===== Bus_PlugInDevice @ 140028790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Bus_PlugInDevice(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  lVar2 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x10),0);
  (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
  while( true ) {
    uVar6 = 5;
    uVar4 = param_1;
    lVar5 = lVar2;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals);
    if (lVar2 == 0) break;
    (**(code **)(WdfFunctions_01015 + 0x650))
              (WdfDriverGlobals,lVar2,PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
  }
  uVar3 = Bus_CreatePdo(param_1,uVar4,lVar5,uVar6);
  (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x10));
  return uVar3 & 0xffffffff;
}



===== Bus_SetIsConnectedProperty @ 1400288bc =====

void Bus_SetIsConnectedProperty(WDFDEVICE__ *param_1,int param_2)

{
  char cVar1;
  char local_res10 [24];
  undefined8 local_18;
  undefined8 uStack_10;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1f,
               &WPP_9739fd3d85a33a980818697074cd9c28_Traceguids,(char)param_2);
  }
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"service");
  local_res10[0] = -(param_2 != 0);
  WdfHelpers::WdfDeviceSetPropertyToDeviceInterface
            (param_1,(_GUID *)&GUID_DEVINTERFACE_HF_ENUMERATOR,(_UNICODE_STRING *)&local_18,
             (_DEVPROPKEY *)&DEVPKEY_PhoneLineTransportDevice_IsConnected,0x11,1,local_res10);
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1400289b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(longlong param_1)

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
  *(undefined8 *)(puVar7 + -8) = 0x140028a13;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140028a33;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140028a47;
  return iVar6;
}



===== WppCleanupKm @ 140028a60 =====

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



===== WppInitKm @ 140028b10 =====

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



===== WppLoadTracingSupport @ 140028bec =====

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



===== WppTraceCallback @ 140028d30 =====

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



===== _tlgEnableCallback @ 140028fc0 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 14002903c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

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
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== wil_UninitializeFeatureStaging @ 140029108 =====

void wil_UninitializeFeatureStaging(void)

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
  return;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140029160 =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_1400291bd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400291bd;
    }
  }
  uVar1 = 0x206;
LAB_1400291bd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400291c8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_53100197__private_descriptor);
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &Feature_53100197__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140029280 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1400292b8 =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_14002933a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14002933a;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_14002933a:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140029390 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &Feature_53100197__private_descriptor;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_RecordFeatureUsageCallback @ 1400293e4 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140029400 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14002941c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_53100197__private_descriptor;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== Bus_CreatePdo @ 1400294d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Bus_CreatePdo(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined1 auStack_328 [32];
  undefined4 local_308;
  longlong local_2f8;
  longlong local_2f0;
  ushort local_2e8 [4];
  undefined1 *local_2e0;
  undefined8 local_2d8;
  wchar_t *local_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined4 *puStack_2b0;
  undefined *local_2a8;
  undefined8 uStack_2a0;
  code *local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined *local_258;
  undefined4 local_248 [4];
  code *local_238;
  undefined4 local_208 [2];
  longlong local_200;
  code *local_1f8;
  code *local_1f0;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined8 local_11c;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined8 uStack_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  wchar_t local_e8 [16];
  undefined1 local_c8 [160];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_328;
  local_2f0 = 0;
  local_258 = (undefined *)0x0;
  local_2b8 = 0;
  puStack_2b0 = (undefined4 *)0x0;
  local_2a8 = (undefined *)0x0;
  uStack_2a0 = 0;
  local_298 = (code *)0x0;
  uStack_290 = 0;
  local_288 = 0;
  uStack_280 = 0;
  local_278 = 0;
  uStack_270 = 0;
  local_268 = 0;
  uStack_260 = 0;
  memset(local_248,0,0x40);
  local_168 = 0;
  uStack_164 = 0;
  uStack_160 = 0;
  uStack_15c = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  memset(&local_138,0,0x50);
  memset(local_208,0,0x98);
  builtin_wcsncpy(local_e8,L"HFP Bus 0",10);
  local_2d0 = local_e8;
  local_2e0 = local_c8;
  local_2d8 = 0x140012;
  local_2e8[0] = 0;
  local_2e8[1] = 0xa0;
  local_2e8[2] = 0;
  local_2e8[3] = 0;
  local_2c8 = 0;
  uStack_2c0 = 0;
  local_2f8 = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals,param_1);
  if (local_2f8 == 0) {
    uVar7 = 0xc000009a;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_2f8,0x2a);
    (**(code **)(WdfFunctions_01015 + 0xc40))(WdfDriverGlobals,local_2f8);
    RtlInitUnicodeString(&local_2c8,L"BTHHFENUM\\BthHFPAudio");
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_2f8,&local_2c8);
    uVar7 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_2f8,&local_2c8);
      uVar7 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        uVar3 = RtlUnicodeStringPrintf(local_2e8,L"%02d",0x61,param_4);
        uVar7 = uVar3 & 0xffffffff;
        if (-1 < (int)uVar3) {
          uVar2 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_2f8,local_2e8);
          uVar7 = (ulonglong)uVar2;
          if (-1 < (int)uVar2) {
            uVar3 = RtlUnicodeStringPrintf
                              (local_2e8,L"Microsoft_HFP_Audio_Device_%02d",0x61,param_4);
            uVar7 = uVar3 & 0xffffffff;
            if (-1 < (int)uVar3) {
              local_308 = 0x800;
              uVar2 = (**(code **)(WdfFunctions_01015 + 0x6c0))
                                (WdfDriverGlobals,local_2f8,local_2e8,&local_2d8);
              uVar7 = (ulonglong)uVar2;
              if (-1 < (int)uVar2) {
                (**(code **)(WdfFunctions_01015 + 0x6c8))(WdfDriverGlobals,local_2f8,0x800);
                local_238 = Bus_EvtDeviceResourceRequirementsQuery;
                local_248[0] = 0x40;
                (**(code **)(WdfFunctions_01015 + 0x698))(WdfDriverGlobals,local_2f8,local_248);
                local_258 = PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8;
                local_288 = CONCAT44(local_288._4_4_,0x38);
                uStack_270 = 0x100000001;
                uVar2 = (**(code **)(WdfFunctions_01015 + 600))
                                  (WdfDriverGlobals,&local_2f8,&local_288,&local_2f0);
                uVar7 = (ulonglong)uVar2;
                if (-1 < (int)uVar2) {
                  lVar4 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
                  cVar1 = *(char *)(lVar4 + 0x4c);
                  lVar4 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,local_2f0);
                  *(char *)(lVar4 + 0x4c) = cVar1 + '\x01';
                  puVar5 = (undefined4 *)
                           (**(code **)(WdfFunctions_01015 + 0x650))
                                     (WdfDriverGlobals,local_2f0,
                                      PTR__WDF_PDO_DEVICE_DATA_TYPE_INFO_1400220d8);
                  memset(puVar5 + 2,0,0x68);
                  *puVar5 = 0x61;
                  puVar5[1] = 1;
                  uVar6 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
                  *(undefined8 *)(puVar5 + 2) = uVar6;
                  uVar2 = Bus_SetupAudioPDOQueues(local_2f0);
                  uVar7 = (ulonglong)uVar2;
                  if (-1 < (int)uVar2) {
                    local_168 = 0x30;
                    uStack_164 = 2;
                    uStack_160 = 0;
                    local_158 = 0x200000002;
                    local_148 = 0x200000002;
                    uStack_15c = 0;
                    uStack_150 = 0x100000002;
                    uStack_140 = 0x6100000061;
                    (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_2f0,&local_168)
                    ;
                    local_f8 = 0xffffffff;
                    local_f4 = 0xffffffff;
                    local_f0 = 0xffffffff;
                    local_138 = 0x50;
                    local_130 = 2;
                    local_12c = 2;
                    local_124 = 2;
                    local_120 = 2;
                    local_fc = 7;
                    local_ec = 5;
                    local_134 = 1;
                    local_128 = 1;
                    local_100 = 2;
                    local_11c = 0x100000005;
                    uStack_114 = 2;
                    uStack_110 = 4;
                    uStack_10c = 4;
                    uStack_108 = 0x400000004;
                    (**(code **)(WdfFunctions_01015 + 0x2a0))(WdfDriverGlobals,local_2f0,&local_138)
                    ;
                    local_1f8 = BrbRequest_EvtCleanupCallback;
                    local_1f0 = BrbRequest_EvtCleanupCallback;
                    puStack_2b0 = local_208;
                    local_2a8 = &GUID_HFP_INTERFACE_STANDARD;
                    local_298 = BusPdo_EvtDeviceProcessQueryInterfaceRequest;
                    local_208[0] = 0x10098;
                    local_200 = local_2f0;
                    local_2b8 = CONCAT44(local_2b8._4_4_,0x30);
                    uStack_290 = CONCAT71(uStack_290._1_7_,1);
                    uVar2 = (**(code **)(WdfFunctions_01015 + 0x720))
                                      (WdfDriverGlobals,local_2f0,&local_2b8);
                    uVar7 = (ulonglong)uVar2;
                    if (-1 < (int)uVar2) {
                      uVar3 = (**(code **)(WdfFunctions_01015 + 0x428))
                                        (WdfDriverGlobals,param_1,local_2f0);
                      uVar7 = uVar3 & 0xffffffff;
                      if (-1 < (int)uVar3) {
                        return uVar3;
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
  if (local_2f8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  if (local_2f0 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return uVar7;
}



===== Bus_EvtDeviceResourceRequirementsQuery @ 140029b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 Bus_EvtDeviceResourceRequirementsQuery(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined **ppuVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined4 *local_70;
  undefined4 *local_68;
  undefined4 *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined *local_48 [3];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_48[0] = &DEVPKEY_Bluetooth_DeviceAddress;
  local_48[1] = &DEVPKEY_Bluetooth_ServiceGUID;
  local_48[2] = &DEVPKEY_Device_PresenceNotForDevice;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  local_50 = uVar3;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,param_1);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,uVar4);
  uVar9 = 100;
  puVar5 = (undefined4 *)ExAllocatePool2(0x100,100,0x46485442);
  if (puVar5 != (undefined4 *)0x0) {
    uVar8 = 0;
    ppuVar7 = local_48;
    do {
      puVar1 = *ppuVar7;
      local_60 = &local_54;
      local_54 = 0;
      local_58 = 0;
      local_68 = &local_58;
      local_78 = uVar9;
      local_70 = puVar5;
      iVar2 = IoGetDevicePropertyData(uVar4,puVar1,0,0);
      puVar6 = puVar5;
      if (iVar2 == -0x3fffffdd) {
        puVar6 = (undefined4 *)ExAllocatePool2(0x100,local_58);
        if (puVar6 != (undefined4 *)0x0) {
          ExFreePoolWithTag(puVar5,0x46485442);
          uVar9 = local_58;
          local_60 = &local_54;
          local_68 = &local_58;
          local_78 = local_58;
          local_70 = puVar6;
          iVar2 = IoGetDevicePropertyData(uVar4,puVar1);
          uVar3 = local_50;
          goto LAB_140029ca7;
        }
      }
      else {
LAB_140029ca7:
        puVar5 = puVar6;
        if (-1 < iVar2) {
          local_70 = (undefined4 *)CONCAT44(local_70._4_4_,local_58);
          local_78 = local_54;
          local_68 = puVar6;
          IoSetDevicePropertyData(uVar3,puVar1);
        }
      }
      uVar8 = uVar8 + 1;
      ppuVar7 = ppuVar7 + 1;
      uVar3 = local_50;
    } while (uVar8 < 3);
    if (puVar5 != (undefined4 *)0x0) {
      ExFreePoolWithTag(puVar5,0x46485442);
    }
  }
  return 0;
}



===== Bus_SetupAudioPDOQueues @ 140029d38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_SetupAudioPDOQueues(undefined8 param_1)

{
  undefined8 local_res10 [3];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5b;
  code *local_40;
  code *local_38;
  
  local_res10[0] = 0;
  memset(&local_68,0,0x60);
  local_60 = 0;
  local_40 = Bus_AudioPDOIoDeviceControl;
  local_68 = 0x60;
  local_38 = Bus_AudioPDOInternalIoDeviceControl;
  local_5b = 1;
  local_64 = 1;
  (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_1,&local_68,0,local_res10);
  return;
}



===== Bus_IsAutoConnectionDisabled @ 140029dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool Bus_IsAutoConnectionDisabled(void)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_148 [32];
  undefined8 local_128;
  undefined8 *local_120;
  int local_108 [2];
  undefined8 local_100;
  undefined8 local_f8;
  wchar_t *local_f0;
  undefined8 local_e8;
  wchar_t *local_e0;
  wchar_t local_d8 [24];
  wchar_t local_a8 [72];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  local_f8 = 0x8e008c;
  bVar2 = false;
  builtin_wcsncpy(local_a8,
                  L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Bluetooth\\Audio\\Hfp",
                  0x47);
  local_100 = 0;
  local_f0 = local_a8;
  wil::details::
  unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
           *)&local_100,(WDFKEY__ *)0x0);
  local_120 = &local_100;
  local_128 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))(WdfDriverGlobals,0,&local_f8,0x20019);
  local_108[0] = 0;
  if (-1 < iVar1) {
    builtin_wcsncpy(local_d8,L"DisableAutoConnect",0x13);
    local_e0 = local_d8;
    local_e8 = 0x260024;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_100,&local_e8,local_108);
    if (-1 < iVar1) {
      bVar2 = local_108[0] != 0;
    }
  }
  wil::details::
  unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
              *)&local_100);
  return bVar2;
}



===== Bus_IsRemoteVolumeControlDisabled @ 140029f60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool Bus_IsRemoteVolumeControlDisabled(void)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  longlong local_150;
  int local_138 [2];
  undefined8 local_130;
  undefined8 local_128;
  wchar_t *local_120;
  undefined8 local_118;
  wchar_t *local_110;
  wchar_t local_100 [28];
  wchar_t local_c8 [88];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_178;
  local_128 = 0xa800a6;
  bVar2 = false;
  builtin_wcsncpy(local_c8,
                  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Bluetooth\\Audio\\Hfp\\AudioGateway"
                  ,0x54);
  local_130 = 0;
  local_120 = local_c8;
  local_150 = wil::
              out_param<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
                        ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>
                          *)&local_118);
  local_150 = local_150 + 8;
  local_158 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))(WdfDriverGlobals,0,&local_128,0x20019);
  wil::details::
  out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
  ::
  ~out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
            ((out_param_t<wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>_>_>
              *)&local_118);
  local_138[0] = 0;
  if (-1 < iVar1) {
    builtin_wcsncpy(local_100,L"DisableRemoteVolumeControl",0x1b);
    local_110 = local_100;
    local_118 = 0x360034;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_130,&local_118,local_138);
    if (-1 < iVar1) {
      bVar2 = local_138[0] != 0;
    }
  }
  wil::details::
  unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
              *)&local_130);
  return bVar2;
}



===== Bus_IsDeviceConnected @ 14002a114 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool Bus_IsDeviceConnected(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_res10 [3];
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_res10[0] = 0;
  iVar1 = KeWaitForSingleObject(lVar2 + 0xd8,0,0,0,local_res10);
  return iVar1 == 0x102;
}



===== Bus_OnHfConnectionUpdate @ 14002a184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_OnHfConnectionUpdate(WDFDEVICE__ *param_1,int param_2)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  undefined4 *puVar5;
  undefined7 extraout_var;
  char cVar6;
  char cVar7;
  int local_res10 [2];
  undefined4 in_stack_ffffffffffffffd0;
  undefined4 in_stack_ffffffffffffffd4;
  
  local_res10[0] = param_2;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  Bus_SetIsConnectedProperty(param_1,local_res10[0]);
  if (*(longlong *)(lVar4 + 0x140) == 0) {
    cVar6 = '\x01';
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
       (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar7 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar6 = '\0';
    }
    if ((cVar7 != '\0') || (cVar6 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar6,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1a,
                 &WPP_2421956a1eaf3f28bf0c34f972a8cf79_Traceguids);
    }
  }
  else {
    puVar5 = (undefined4 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(lVar4 + 0x140),DAT_140022100);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar6 = '\0';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_DD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    WdfIoQueueFindAndCompleteStatusIoctlRequest
              (*(undefined8 *)(lVar4 + 0x98),*(undefined8 *)(lVar4 + 0x140),0x220017,local_res10,
               puVar5,CONCAT44(in_stack_ffffffffffffffd4,in_stack_ffffffffffffffd0));
  }
  bVar2 = Bus_IsDeviceConnected(param_1);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x148),0);
  if ((local_res10[0] != (int)CONCAT71(extraout_var,bVar2)) && (*(longlong *)(lVar4 + 0xb8) != 0)) {
    LOCK();
    uVar1 = *(undefined4 *)(lVar4 + 0xb4);
    *(undefined4 *)(lVar4 + 0xb4) = 0;
    UNLOCK();
    BtaMpmUpdateConnectionStatus(*(undefined8 *)(lVar4 + 0xb8),local_res10[0],uVar1);
  }
  if (local_res10[0] == 0) {
    KeSetEvent(lVar4 + 0xd8,0,0);
    if (*(longlong *)(lVar4 + 0x170) != 0) {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
      if (iVar3 != -0x3ffffee0) {
        (**(code **)(WdfFunctions_01015 + 0x838))
                  (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x170),0xc0000184);
      }
      *(undefined8 *)(lVar4 + 0x170) = 0;
    }
    ScoSetCodecId(param_1,0);
    *(undefined4 *)(lVar4 + 0x178) = 0;
  }
  else {
    KeClearEvent();
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x148));
  return;
}



===== BthHwGetEnumeratorDeviceInfo @ 14002a440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong BthHwGetEnumeratorDeviceInfo(undefined8 param_1,byte *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 local_res10 [3];
  undefined4 local_28;
  undefined4 local_24;
  byte *local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_res10[0] = 0;
  local_24 = 0;
  local_14 = 0;
  local_28 = 1;
  local_18 = 0x110;
  local_20 = param_2;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x5e0))
                    (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20),0,0x41000b,0,&local_28,0,
                     local_res10);
  if ((-1 < (int)uVar2) && (uVar2 = uVar2 & 0xffffffff, (*param_2 & 1) == 0)) {
    uVar2 = 0xc0000184;
  }
  return uVar2;
}



===== BthHwInitialize @ 14002a4fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong BthHwInitialize(undefined8 param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined7 extraout_var;
  undefined8 uVar7;
  ulonglong uVar8;
  char cVar9;
  byte bVar10;
  ulonglong uVar11;
  _BTH_PROFILE_DRIVER_INTERFACE *p_Var12;
  undefined8 uVar13;
  undefined4 uVar14;
  byte local_res8 [8];
  int local_res10 [2];
  undefined4 local_res18 [2];
  undefined8 in_stack_fffffffffffffee8;
  undefined4 uVar16;
  byte *pbVar15;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined8 uStack_cc;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined *local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 local_8c [84];
  
  uVar4 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  local_c4 = 0;
  local_b0 = 0;
  local_a8 = PTR__WDF_BRB_TYPE_INFO_1400221c8;
  local_d4 = 0;
  uStack_cc = 0;
  local_d8 = 0x38;
  local_c0 = 1;
  local_bc = 1;
  local_b8 = param_1;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                    (WdfDriverGlobals,&local_d8,*(undefined8 *)(lVar5 + 0x20),lVar5 + 0x90);
  uVar11 = (ulonglong)uVar3;
  uVar6 = BthQueryDeviceCompatFlags(*(longlong *)(lVar5 + 0x1b0));
  if (-1 < (int)uVar3) {
    uVar14 = 2;
    *(undefined4 *)(lVar5 + 0xb0) = 2;
    bVar1 = Bus_IsRemoteVolumeControlDisabled();
    bVar10 = (byte)uVar6 >> 2 & 1;
    if ((bVar10 == 0) && ((int)CONCAT71(extraout_var,bVar1) == 0)) {
      local_res10[0] = 0;
      local_res18[0] = 0;
      local_res8[0] = bVar10;
      uVar7 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
      pbVar15 = local_res8;
      uVar13 = CONCAT44(uVar4,1);
      iVar2 = IoGetDevicePropertyData
                        (uVar7,&DEVPKEY_Bthhfenum_SupportsRemoteVolume,0,0,uVar13,pbVar15,
                         local_res18,local_res10);
      uVar4 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar16 = (undefined4)((ulonglong)pbVar15 >> 0x20);
      if ((iVar2 < 0) || (local_res10[0] != 0x11)) {
        if ((*(int *)(lVar5 + 0x1a0) == 0) || ((*(byte *)(lVar5 + 0x2ba) & 0x10) != 0)) {
          local_res8[0] = 0xff;
          uVar14 = 1;
        }
        else {
          local_res8[0] = 0;
        }
        *(undefined4 *)(lVar5 + 0xb0) = uVar14;
        uVar7 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        IoSetDevicePropertyData
                  (uVar7,&DEVPKEY_Bthhfenum_SupportsRemoteVolume,0,1,CONCAT44(uVar4,0x11),
                   CONCAT44(uVar16,1),local_res8);
      }
      else {
        *(uint *)(lVar5 + 0xb0) = 2 - (uint)(local_res8[0] != 0);
      }
    }
    else {
      *(undefined4 *)(lVar5 + 0xb0) = 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar9 = '\0';
    }
    else {
      cVar9 = '\x01';
    }
    if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_iLll
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar3 = BtaMpmRegister(*(undefined8 *)(lVar5 + 0x1b0),0,Bus_MpmConnectionRequestCallback,
                           Bus_MpmSuspendRequestCallback,Bus_MpmSuspendStatusCallback,0,param_1,
                           lVar5 + 0xb8);
    uVar11 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      uVar3 = BthHwQueryInterfaces(param_1);
      uVar11 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        memset(local_8c,0,0x54);
        local_90 = 0;
        local_98 = 0x60;
        local_94 = 3;
        uVar3 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                          (WdfDriverGlobals,param_1,&local_98,0,lVar5 + 0x98);
        uVar11 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          uVar8 = BthScoServerInitialization(param_1);
          uVar11 = uVar8 & 0xffffffff;
          if (-1 < (int)uVar8) {
            uVar8 = *(ulonglong *)(lVar5 + 0x2c);
            uVar4 = 0x202;
            uVar14 = 0x203;
            if ((uVar8 & 0x20) == 0) {
              if ((uVar8 & 0x10) != 0) {
                uVar4 = 0x210;
                uVar14 = 0x211;
              }
            }
            else {
              uVar4 = 0x8201;
              uVar14 = 0x8202;
            }
            uVar7 = *(undefined8 *)(lVar5 + 0x1b0);
            p_Var12 = (_BTH_PROFILE_DRIVER_INTERFACE *)(lVar5 + 0x48);
            uVar3 = ScoCreate(param_1,*(WDFIOTARGET__ **)(lVar5 + 0x20),p_Var12,uVar7,uVar4,uVar14);
            uVar11 = (ulonglong)uVar3;
            uVar4 = ScoIsMsbcSupported(param_1);
            *(undefined4 *)(lVar5 + 0x168) = uVar4;
            if ((((uVar8 & 0x10) == 0) && ((uVar6 & 1) != 0)) &&
               ((*(byte *)(lVar5 + 0x2c) & 0x40) == 0)) {
              uVar6 = (ulonglong)(((uint)uVar8 & 0x10) + 1);
            }
            else {
              uVar6 = 0;
            }
            *(int *)(lVar5 + 0x16c) = (int)uVar6;
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
              bVar10 = 0;
            }
            else {
              bVar10 = 1;
            }
            bVar1 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            uVar13 = CONCAT71((int7)((ulonglong)p_Var12 >> 8),bVar1);
            if ((bVar10 != 0) || (bVar1)) {
              uVar6 = (ulonglong)bVar10;
              uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
              WPP_RECORDER_AND_TRACE_SF_lIil
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar10,bVar1,uVar7);
            }
            if (-1 < (int)uVar3) {
              BthHwSleepstudyRegister(param_1,uVar6,uVar13,uVar7);
            }
          }
        }
      }
    }
  }
  return uVar11;
}



===== BthHwQueryInterfaces @ 14002a968 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BthHwQueryInterfaces(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  undefined4 in_stack_ffffffffffffffd0;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffffffffffd0 >> 0x10);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x418))
                    (WdfDriverGlobals,param_1,&GUID_BTHDDI_PROFILE_DRIVER_INTERFACE,lVar2 + 0x48,
                     0x48,CONCAT22(uVar4,0x200),0);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_dd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,10,
                 &WPP_a5a394aa8e7a34ed6d5d67bd4b27ab0e_Traceguids,0,(char)iVar1);
    }
  }
  return iVar1;
}



===== ScoStreamFlush @ 14002aa70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ScoStreamFlush(struct WDFDEVICE__ * __ptr64,unsigned long) */

long __cdecl ScoStreamFlush(WDFDEVICE__ *param_1,ulong param_2)

{
  bool bVar1;
  undefined8 *puVar2;
  _BRB *p_Var3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  _SCO_TRANSFER_CONTEXT *p_Var7;
  undefined1 auStackY_88 [32];
  undefined4 in_stack_ffffffffffffffa0;
  undefined4 in_stack_ffffffffffffffa4;
  undefined *in_stack_ffffffffffffffb0;
  longlong local_38 [4];
  
  local_38[3] = __security_cookie ^ (ulonglong)auStackY_88;
  local_38[1] = 0;
  local_38[2] = 0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  local_38[0] = 0;
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffffb0 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
    in_stack_ffffffffffffffa0 = 5;
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x53,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_2);
  }
  if (*(int *)((longlong)puVar2 + 0x6c) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x54,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
    iVar5 = -0x3ffffff0;
  }
  else if (*(int *)(puVar2 + 0x2f) == 7) {
    lVar6 = 0x88;
    if (param_2 != 1) {
      lVar6 = 0xd8;
    }
    p_Var7 = (_SCO_TRANSFER_CONTEXT *)(lVar6 + (longlong)puVar2);
    (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,*(undefined8 *)(p_Var7 + 0x18),0,0);
    ScoCancelWaitingDataRequests(p_Var7);
    p_Var3 = (_BRB *)(**(code **)(puVar2[1] + 0x20))(0x20a,*(undefined4 *)(puVar2 + 3));
    if (p_Var3 == (_BRB *)0x0) {
      iVar5 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(p_Var3 + 0x70) = puVar2[2];
      *(undefined8 *)(p_Var3 + 0x78) = puVar2[0x10];
      *(ulong *)(p_Var3 + 0x80) = param_2;
      iVar5 = WdfIoTargetCreateAndFormatRequestForBrb
                        (0,(WDFIOTARGET__ *)*puVar2,(_BTH_PROFILE_DRIVER_INTERFACE *)puVar2[1],
                         p_Var3,local_38);
      if (-1 < iVar5) {
        p_Var3 = (_BRB *)0x0;
        local_38[2] = 0;
        local_38[1] = 0x200000010;
        (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,local_38[0],*puVar2,local_38 + 1)
        ;
        iVar5 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,local_38[0]);
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          bVar1 = false;
        }
        if ((bVar1 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_l
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x56,
                     &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar5);
        }
        (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(p_Var7 + 0x18));
      }
      if (local_38[0] != 0) {
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_38[0]);
      }
      if (p_Var3 != (_BRB *)0x0) {
        (**(code **)(puVar2[1] + 0x28))(p_Var3);
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      bVar1 = false;
    }
    if ((bVar1 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_SCOSTATE
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,
                 CONCAT44(in_stack_ffffffffffffffa4,in_stack_ffffffffffffffa0),0x55,
                 in_stack_ffffffffffffffb0,(char)*(int *)(puVar2 + 0x2f));
    }
    iVar5 = 0;
  }
  return iVar5;
}



===== ScoStreamFlushRequest @ 14002ae14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoStreamFlushRequest(WDFDEVICE__ *param_1,ulong param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x57,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_2);
  }
  lVar1 = ScoStreamFlush(param_1,param_2);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,lVar1);
  return;
}



===== ScoStreamGetLastCorrelatedPosition @ 14002aee4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoStreamGetLastCorrelatedPosition(undefined8 param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  undefined8 *local_res20;
  undefined4 in_stack_ffffffffffffffd0;
  undefined4 in_stack_ffffffffffffffd4;
  undefined8 in_stack_ffffffffffffffe0;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  local_res20 = (undefined8 *)0x0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_3,0x10,&local_res20,0);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_l
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x5a,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)iVar1);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,iVar1);
  }
  else {
    *local_res20 = *(undefined8 *)(lVar2 + 0x90 + (ulonglong)param_2 * 0x50);
    local_res20[1] = *(undefined8 *)(lVar2 + 0x98 + (ulonglong)param_2 * 0x50);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ii
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,
                 CONCAT44(in_stack_ffffffffffffffd4,in_stack_ffffffffffffffd0),0x5b,
                 in_stack_ffffffffffffffe0,(char)*local_res20,(char)local_res20[1]);
    }
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_3,0,0x10);
  }
  return;
}



===== ScoStreamGetSDPRecordSupportedFeatures @ 14002b0d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoStreamGetSDPRecordSupportedFeatures(WDFDEVICE__ *param_1,ushort *param_2)

{
  long lVar1;
  char cVar2;
  bool bVar3;
  ushort local_res10 [4];
  _BTH_SDP_STREAM_RESPONSE *local_res18 [2];
  undefined1 uVar4;
  undefined2 in_stack_ffffffffffffff20;
  undefined6 in_stack_ffffffffffffff22;
  undefined2 uVar5;
  undefined8 in_stack_ffffffffffffff30;
  undefined1 uVar6;
  _BTHDDI_SDP_PARSE_INTERFACE local_b8 [160];
  
  memset(local_b8,0,0xa0);
  local_res10[0] = 0;
  local_res18[0] = (_BTH_SDP_STREAM_RESPONSE *)0x0;
  lVar1 = ScoRetrieveSDPRecord(param_1,local_res18);
  if (lVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar2 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
      cVar2 = '\0';
    }
    bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar2 == '\0') && (!bVar3)) goto LAB_14002b300;
    uVar5 = 0x6b;
LAB_14002b17e:
    uVar6 = (undefined1)lVar1;
    uVar4 = 1;
  }
  else {
    in_stack_ffffffffffffff20 = 0x100;
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x418))
                      (WdfDriverGlobals,param_1,&GUID_BTHDDI_SDP_PARSE_INTERFACE,local_b8,0xa0,0x100
                       ,0);
    if (lVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         (cVar2 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
        cVar2 = '\0';
      }
      bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar2 == '\0') && (!bVar3)) goto LAB_14002b300;
      uVar5 = 0x6c;
      goto LAB_14002b17e;
    }
    lVar1 = ScoRetrieveSupportedFeaturesFromSDPRecord(local_b8,param_1,local_res10,local_res18[0]);
    if (lVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         (cVar2 = '\x01', WPP_GLOBAL_Control[0x29] == '\0')) {
        cVar2 = '\0';
      }
      bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar2 == '\0') && (!bVar3)) goto LAB_14002b300;
      uVar5 = 0x6d;
      goto LAB_14002b17e;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar2 = '\0';
    }
    bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar2 == '\0') && (!bVar3)) goto LAB_14002b300;
    uVar6 = (undefined1)local_res10[0];
    uVar5 = 0x6e;
    uVar4 = 4;
  }
  WPP_RECORDER_AND_TRACE_SF_SCOSTATE
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar3,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,
             CONCAT62(in_stack_ffffffffffffff22,in_stack_ffffffffffffff20),uVar5,
             in_stack_ffffffffffffff30,uVar6);
LAB_14002b300:
  *param_2 = local_res10[0];
  if (local_res18[0] != (_BTH_SDP_STREAM_RESPONSE *)0x0) {
    ExFreePoolWithTag(local_res18[0],0x46485442);
  }
  return;
}



===== ScoStreamGetStatusUpdate @ 14002b344 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoStreamGetStatusUpdate(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x51,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  iVar2 = WdfIoQueueFindIoctlRequest(*(undefined8 *)(lVar3 + 0x60),0,0x22002b,(undefined8 *)0x0);
  if ((iVar2 < 0) &&
     (iVar2 = WdfIoQueueFindIoctlRequest(*(undefined8 *)(lVar3 + 0x60),0,0x22002f,(undefined8 *)0x0)
     , iVar2 < 0)) {
    if (*(int *)(lVar3 + 0x6c) != 0) {
      WdfRequestCompleteOrForwardStatusIoctlRequest
                (param_2,*(undefined8 *)(lVar3 + 0x60),0x220033,(undefined4 *)(lVar3 + 0x78),
                 (undefined4 *)(lVar3 + 0x7c));
      return;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x52,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
  return;
}



===== ScoStreamOpenRequest @ 14002b4f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScoStreamOpenRequest(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  cVar6 = '\x01';
  LOCK();
  iVar1 = *(int *)(lVar2 + 0x6c);
  *(int *)(lVar2 + 0x6c) = 1;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x4a,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
  }
  if (iVar1 == 0) {
    uVar4 = 0;
    puVar3 = (undefined8 *)(lVar2 + 0x98);
    do {
      uVar4 = uVar4 + 1;
      puVar3[-1] = 0;
      *puVar3 = 0;
      puVar3[2] = 0;
      puVar3 = puVar3 + 10;
    } while (uVar4 < 2);
    *(undefined8 *)(lVar2 + 0x78) = 0;
    iVar1 = ScoConnectionRequest(param_1,param_2);
    if (iVar1 < 0) {
      *(undefined4 *)(lVar2 + 0x6c) = 0;
      ScoUpdateAvdtpSuspension(lVar2);
    }
  }
  else {
    MicrosoftTelemetryAssertTriggeredMsgKM
              ("Received Sco stream open request while already streaming");
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar5 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar6 = '\0';
    }
    if ((cVar5 != '\0') || (cVar6 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4b,
                 &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
  }
  return;
}



===== ScoStreamTransferRequest @ 14002b6d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ScoStreamTransferRequest(undefined8 param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  char cVar5;
  ulonglong uVar6;
  undefined1 auStackY_118 [32];
  undefined8 in_stack_ffffffffffffff10;
  undefined *in_stack_ffffffffffffff20;
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8 [4];
  undefined8 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar6 = (ulonglong)param_2;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SCOCONTEXT_TYPE_INFO_140022150);
  cVar5 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffff20 = &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids;
    in_stack_ffffffffffffff10 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffff10 >> 0x20),5);
    WPP_RECORDER_AND_TRACE_SF_l
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x58,
               &WPP_129d591dc59c38d07ce4ec1a8ea6b04b_Traceguids,(char)param_2);
  }
  if (*(longlong *)(lVar2 + 0x98 + uVar6 * 0x50) == 0) {
    uVar3 = KeQueryPerformanceCounter(0);
    *(undefined8 *)(lVar2 + 0x98 + uVar6 * 0x50) = uVar3;
    *(undefined8 *)(lVar2 + 0x90 + uVar6 * 0x50) = 0;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar4 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar5 = '\0';
    }
    if ((cVar4 != '\0') || (cVar5 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_i
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff10,0x59,
                 in_stack_ffffffffffffff20,(char)uVar3);
    }
  }
  if (5 < DAT_140022000) {
    local_c0 = *(undefined8 *)(lVar2 + 0x90 + uVar6 * 0x50);
    local_b8 = *(undefined8 *)(lVar2 + 0x98 + uVar6 * 0x50);
    local_c8[0] = *(undefined4 *)(lVar2 + 0x88 + uVar6 * 0x50);
    local_58 = &local_c0;
    local_68 = &local_b8;
    local_78 = local_c8;
    local_88 = &local_b0;
    local_50 = 8;
    local_60 = 8;
    local_70 = 4;
    local_80 = 8;
    local_b0 = param_3;
    _tlgWriteTransfer_EtwWriteTransfer(0x140022000,&DAT_14001ed8b,0,0,6,local_a8);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                    (WdfDriverGlobals,param_3,*(undefined8 *)(lVar2 + 0xa0 + uVar6 * 0x50));
  if (iVar1 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,iVar1);
  }
  return;
}



===== Bus_EvtStdDataQueryInstance @ 14002b950 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
Bus_EvtStdDataQueryInstance(undefined8 param_1,uint param_2,undefined8 *param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  
  *param_4 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xbc0))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (7 < param_2) {
    *param_3 = *(undefined8 *)(lVar2 + 0x18);
    *param_4 = 8;
  }
  return 0;
}



===== Bus_EvtStdDataSetInstance @ 14002b9e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Bus_EvtStdDataSetInstance(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xbc0))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_3 + 4);
  return 0;
}



===== Bus_EvtStdDataSetItem @ 14002ba40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Bus_EvtStdDataSetItem(undefined8 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xbc0))(WdfDriverGlobals,param_1);
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  if (param_2 == 2) {
    if (param_3 < 4) {
      uVar2 = 0xc0000023;
    }
    else {
      *(undefined4 *)(lVar1 + 0x1c) = *param_4;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xc00002c6;
  }
  return uVar2;
}



===== Bus_WmiRegistration @ 14002bad4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Bus_WmiRegistration(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined8 local_a8;
  wchar_t *local_a0;
  undefined4 local_98 [4];
  undefined4 *local_88;
  undefined1 local_7f;
  code *local_78;
  code *local_70;
  code *local_68;
  undefined4 local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_34;
  wchar_t local_30 [16];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_d8;
  local_44 = 0;
  local_a0 = local_30;
  local_3c = 0;
  local_34 = 0;
  builtin_wcsncpy(local_30,L"MofResourceName",0x10);
  local_a8 = 0x20001e;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DEVICE_DATA_TYPE_INFO_1400220b0);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x148))(WdfDriverGlobals,param_1,&local_a8);
  if (-1 < iVar1) {
    local_44 = 0;
    local_3c = 0;
    local_34 = 0;
    local_58 = 0x28;
    local_54 = 0x4ffc8b2d1acb22fd;
    uStack_4c = 0xe1690f355811e9a2;
    local_40 = 8;
    memset(local_98,0,0x40);
    local_88 = &local_58;
    local_b8 = 0;
    local_98[0] = 0x40;
    local_78 = Bus_EvtStdDataQueryInstance;
    local_7f = 1;
    local_70 = Bus_EvtStdDataSetInstance;
    local_68 = Bus_EvtStdDataSetItem;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xba8))(WdfDriverGlobals,param_1,local_98,0);
    if (-1 < iVar1) {
      *(undefined4 *)(lVar2 + 0x18) = 0;
    }
  }
  return;
}



===== WdfDeviceCopyDevicePropertyToInterface @ 14002bc44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl WdfHelpers::WdfDeviceCopyDevicePropertyToInterface(struct WDFDEVICE__ *
   __ptr64,struct _DEVPROPKEY const & __ptr64,struct _GUID const & __ptr64,struct _UNICODE_STRING
   const & __ptr64) */

long __cdecl
WdfHelpers::WdfDeviceCopyDevicePropertyToInterface
          (WDFDEVICE__ *param_1,_DEVPROPKEY *param_2,_GUID *param_3,_UNICODE_STRING *param_4)

{
  int iVar1;
  void *pvVar2;
  ulong local_res10 [2];
  undefined8 local_48;
  __uint64 local_40;
  undefined4 local_38;
  undefined4 local_34;
  _DEVPROPKEY *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_34 = 0;
  local_24 = 0;
  local_28 = 0;
  local_res10[0] = 0;
  local_48 = 0;
  local_38 = 0x18;
  local_30 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,&local_38,0x200,0,&local_48,local_res10);
  if (-1 < iVar1) {
    local_40 = 0;
    pvVar2 = (void *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_48,&local_40);
    iVar1 = WdfDeviceSetPropertyToDeviceInterface
                      (param_1,param_3,param_4,param_2,local_res10[0],local_40,pvVar2);
  }
  wil::details::
  unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
              *)&local_48);
  return iVar1;
}



===== WdfDeviceSetPropertyToDeviceInterface @ 14002bd48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl WdfHelpers::WdfDeviceSetPropertyToDeviceInterface(struct WDFDEVICE__ *
   __ptr64,struct _GUID const & __ptr64,struct _UNICODE_STRING const & __ptr64,struct _DEVPROPKEY
   const & __ptr64,unsigned long,unsigned __int64,void * __ptr64) */

long __cdecl
WdfHelpers::WdfDeviceSetPropertyToDeviceInterface
          (WDFDEVICE__ *param_1,_GUID *param_2,_UNICODE_STRING *param_3,_DEVPROPKEY *param_4,
          ulong param_5,__uint64 param_6,void *param_7)

{
  int iVar1;
  undefined4 uVar3;
  undefined8 uVar2;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_28 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,0,&local_28);
  if (-1 < iVar1) {
    uVar2 = local_28;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x278))
                      (WdfDriverGlobals,param_1,param_2,param_3,local_28);
    uVar3 = (undefined4)((ulonglong)uVar2 >> 0x20);
    if (-1 < iVar1) {
      local_20 = 0;
      uStack_18 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,local_28,&local_20);
      iVar1 = IoSetDeviceInterfacePropertyData
                        (&local_20,param_4,0,0,CONCAT44(uVar3,param_5),(undefined4)param_6,param_7);
    }
  }
  wil::details::
  unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFKEY__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFKEY__*___ptr64,WDFKEY__*___ptr64,0,std::nullptr_t>_>
              *)&local_28);
  return iVar1;
}



===== AudioInputQueue @ 14002be6c =====

/* private: __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::AudioInputQueue(struct
   WDFQUEUE__ * __ptr64) __ptr64 */

AudioInputQueue * __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::AudioInputQueue
          (AudioInputQueue *this,WDFQUEUE__ *param_1)

{
  *(WDFQUEUE__ **)(this + 8) = param_1;
  *(undefined ***)this =
       &_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__AudioQueue__;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined ***)(this + 0x10) =
       &_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ScoReaderCallbacks__;
  *(WDFQUEUE__ **)(this + 0x20) = param_1;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(ulonglong *)(this + 0x28) =
       -(ulonglong)(this != (AudioInputQueue *)0x0) & (ulonglong)(this + 0x10);
  *(undefined8 *)(this + 0x38) = 0;
  KeInitializeSpinLock();
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined ***)(this + 0x78) =
       &ByteBuffer::_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteWriter__;
  *(undefined ***)(this + 0x80) =
       &ByteBuffer::_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteReader__;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  this[0xa8] = (AudioInputQueue)0x0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  this[0xc4] = (AudioInputQueue)0x0;
  *(undefined8 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  return this;
}



===== ~AudioInputQueue @ 14002bf9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::~AudioInputQueue(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::~AudioInputQueue
          (AudioInputQueue *this)

{
  longlong *plVar1;
  uint in_EDX;
  
  *(undefined ***)this =
       &_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__AudioQueue__;
  *(undefined ***)(this + 0x10) =
       &_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ScoReaderCallbacks__;
  if (*(SentRequestCollection **)(this + 0xf8) != (SentRequestCollection *)0x0) {
    Foundation::SentRequestCollection::_scalar_deleting_destructor_
              (*(SentRequestCollection **)(this + 0xf8),in_EDX);
  }
  if (*(longlong *)(this + 0xf0) != 0) {
    EmptyCompletedScoRequests(this);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(this + 0xf0));
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(this + 0xe8));
  }
  plVar1 = *(longlong **)(this + 0xd0);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x40))(plVar1,1);
  }
  TransportParser::~TransportParser((TransportParser *)(this + 0x48));
  return;
}



===== ~AudioOutputQueue @ 14002c054 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::~AudioOutputQueue(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::~AudioOutputQueue
          (AudioOutputQueue *this)

{
  longlong *plVar1;
  uint in_EDX;
  
  *(undefined ***)this = &_vftable_;
  if (*(SentRequestCollection **)(this + 0xa0) != (SentRequestCollection *)0x0) {
    Foundation::SentRequestCollection::_scalar_deleting_destructor_
              (*(SentRequestCollection **)(this + 0xa0),in_EDX);
  }
  if (*(undefined8 **)(this + 0x90) != (undefined8 *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,**(undefined8 **)(this + 0x90));
  }
  plVar1 = *(longlong **)(this + 0x20);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x40))(plVar1,1);
  }
  TransportFormatter::~TransportFormatter((TransportFormatter *)(this + 0x28));
  return;
}



===== ~AudioQueueProxy @ 14002c0d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::~AudioQueueProxy(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::~AudioQueueProxy
          (AudioQueueProxy *this)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(this + 8);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x38))(plVar1,1);
  }
  return;
}



===== CancelRequest @ 14002c100 =====

/* public: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::CancelRequest(struct
   WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::CancelRequest
          (AudioInputQueue *this,WDFREQUEST__ *param_1)

{
  RequestContext *pRVar1;
  longlong lVar2;
  
  pRVar1 = RequestContext::GetContextFromObject(param_1);
  if (pRVar1 == *(RequestContext **)(this + 0xd8)) {
    *(undefined8 *)(this + 0xd8) = 0;
    lVar2 = KeQueryPerformanceCounter(0);
    AudioQueueClient_CompleteStreamTransferRequest(param_1,-0x3ffffee0,0,'\x01',lVar2);
  }
  return;
}



===== CancelRequest @ 14002c170 =====

/* public: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::CancelRequest(struct
   WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::CancelRequest
          (AudioOutputQueue *this,WDFREQUEST__ *param_1)

{
  RequestContext *pRVar1;
  longlong lVar2;
  
  pRVar1 = RequestContext::GetContextFromObject(param_1);
  if (pRVar1 == *(RequestContext **)(this + 0x18)) {
    *(undefined8 *)(this + 0x18) = 0;
  }
  lVar2 = KeQueryPerformanceCounter(0);
  AudioQueueClient_CompleteStreamTransferRequest(param_1,-0x3ffffee0,0,'\x01',lVar2);
  return;
}



===== EvtAttemptProcessingWorkItem @ 14002c1d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::EvtAttemptProcessingWorkItem(struct
   WDFWORKITEM__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::EvtAttemptProcessingWorkItem
          (WDFWORKITEM__ *param_1)

{
  AudioOutputQueue *this;
  char cVar1;
  WDFQUEUE__ *pWVar2;
  AudioQueueProxy *pAVar3;
  
  pWVar2 = (WDFQUEUE__ *)(**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  pAVar3 = AudioQueueProxy::GetContextFromObject(pWVar2);
  this = *(AudioOutputQueue **)(pAVar3 + 8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_4de776f173d133e87e80f57736d58590_Traceguids,this);
  }
  Process(this);
  cVar1 = (**(code **)(*(longlong *)this + 8))(this);
  if (cVar1 != '\0') {
    AudioQueueClient_AttemptProcessing(*(WDFQUEUE__ **)(this + 8));
  }
  return;
}



===== EvtScoRequestCompletionWorkItem @ 14002c270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::EvtScoRequestCompletionWorkItem(struct
   WDFWORKITEM__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::EvtScoRequestCompletionWorkItem
          (WDFWORKITEM__ *param_1)

{
  AudioInputQueue *this;
  char cVar1;
  bool bVar2;
  WDFQUEUE__ *pWVar3;
  AudioQueueProxy *pAVar4;
  
  pWVar3 = (WDFQUEUE__ *)(**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  pAVar4 = AudioQueueProxy::GetContextFromObject(pWVar3);
  this = *(AudioInputQueue **)(pAVar4 + 8);
  Process(this);
  cVar1 = (**(code **)(*(longlong *)this + 8))(this);
  if (cVar1 != '\0') {
    AudioQueueClient_AttemptProcessing(*(WDFQUEUE__ **)(this + 8));
  }
  bVar2 = IsRunning(this);
  if (bVar2) {
    ScoReader::ContinueReading((ScoReader *)(this + 0x20));
  }
  return;
}



===== IsReadyToProcessNextRequest @ 14002c2f0 =====

/* public: virtual bool __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::IsReadyToProcessNextRequest(void)const
   __ptr64 */

bool __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::IsReadyToProcessNextRequest
          (AudioInputQueue *this)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 0xd8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
               (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),lVar1,(uint)(lVar1 == 0),(char)lVar1,
               (char)this);
  }
  return lVar1 == 0;
}



===== IsReadyToProcessNextRequest @ 14002c350 =====

/* public: virtual bool __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::IsReadyToProcessNextRequest(void)const
   __ptr64 */

bool __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::IsReadyToProcessNextRequest
          (AudioOutputQueue *this)

{
  int iVar1;
  bool bVar2;
  undefined8 in_R8;
  
  iVar1 = GetNumSentScoRequests(this);
  bVar2 = false;
  if ((*(longlong *)(this + 0x18) == 0) && (iVar1 < 2)) {
    bVar2 = true;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,in_R8,*(longlong *)(this + 0x18),
               (char)iVar1,(char)this);
  }
  return bVar2;
}



===== IsRunning @ 14002c3c0 =====

/* private: bool __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::IsRunning(void)const __ptr64 */

bool __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::IsRunning(AudioInputQueue *this)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(longlong *)(this + 0x18) != 0) && (*(longlong *)(this + 0xd8) != 0)) {
    bVar1 = true;
  }
  return bVar1;
}



===== MakeAndAttachToRequest @ 14002c3dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueRequestContext::MakeAndAttachToRequest(struct
   WDFREQUEST__ * __ptr64,class Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueue *
   __ptr64) */

long __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueRequestContext::MakeAndAttachToRequest
          (WDFREQUEST__ *param_1,AudioQueue *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *local_res18;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_3c;
  code *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined *local_18;
  
  local_res18 = (undefined8 *)0x0;
  local_44 = 0;
  local_3c = 0;
  local_30 = 1;
  local_2c = 1;
  local_18 = PTR__WDF_AudioQueueRequestContext_TYPE_INFO_1400224d0;
  local_38 = WdfCpp::
             ObjectContext<WDFREQUEST__*___ptr64,Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueRequestContext,0>
             ::EvtObjectContextDestroyThunk;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0x38;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,&local_48,&local_res18)
  ;
  puVar1 = local_res18;
  if ((-1 < iVar2) && (local_res18 != (undefined8 *)0x0)) {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,local_res18);
    *puVar1 = uVar3;
    puVar1[1] = param_2;
  }
  return iVar2;
}



===== MakeAndInitialize @ 14002c4ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::MakeAndInitialize(struct
   WDFQUEUE__ * __ptr64,class Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue *
   __ptr64 * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::MakeAndInitialize
          (WDFQUEUE__ *param_1,AudioInputQueue **param_2)

{
  int iVar1;
  AudioInputQueue *pAVar2;
  void *pvVar3;
  AudioInputQueue *pAVar4;
  undefined8 local_78;
  code *pcStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  WDFQUEUE__ *local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  *param_2 = (AudioInputQueue *)0x0;
  local_30 = 0;
  local_50 = 0;
  uStack_48 = 0x100000001;
  uStack_58 = 0;
  local_60 = 0x38;
  local_40 = (WDFQUEUE__ *)0x0;
  uStack_38 = 0;
  pAVar2 = (AudioInputQueue *)ExAllocatePool2(0x40,0x120,0x646d4370);
  if (pAVar2 == (AudioInputQueue *)0x0) {
    pAVar2 = (AudioInputQueue *)0x0;
  }
  else {
    pAVar2 = (AudioInputQueue *)AudioInputQueue(pAVar2,param_1);
    if (pAVar2 != (AudioInputQueue *)0x0) {
      pAVar4 = pAVar2 + 0xe8;
      local_30 = 0;
      local_50 = 0;
      uStack_58 = 0;
      local_60 = 0x38;
      local_40 = (WDFQUEUE__ *)0x0;
      uStack_38 = 0;
      uStack_48 = 0x100000001;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_60,pAVar4);
      if (-1 < iVar1) {
        local_30 = 0;
        local_50 = 0;
        uStack_48 = 0x100000001;
        uStack_58 = 0;
        local_60 = 0x38;
        local_40 = (WDFQUEUE__ *)0x0;
        uStack_38 = 0;
        pvVar3 = WdfDriverGlobals;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_60,pAVar2 + 0xf0);
        if ((-1 < iVar1) &&
           (iVar1 = Foundation::SentRequestCollection::MakeAndInitialize
                              (pvVar3,(SentRequestCollection **)(pAVar2 + 0xf8)), -1 < iVar1)) {
          pcStack_70 = EvtScoRequestCompletionWorkItem;
          local_78 = 0x18;
          local_30 = 0;
          local_50 = 0;
          local_68 = 1;
          uStack_58 = 0;
          uStack_38 = 0;
          uStack_48 = 0x100000001;
          local_60 = 0x38;
          local_40 = param_1;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                            (WdfDriverGlobals,&local_78,&local_60,pAVar2 + 0xe0);
          if (-1 < iVar1) {
            *param_2 = pAVar2;
            return 0;
          }
        }
      }
      goto LAB_14002c693;
    }
  }
  iVar1 = -0x3fffff66;
  pAVar4 = pAVar2 + 0xe8;
LAB_14002c693:
  if (*(longlong *)pAVar4 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(longlong *)pAVar4 = 0;
  }
  if (*(longlong *)(pAVar2 + 0xf0) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(longlong *)(pAVar2 + 0xf0) = 0;
  }
  if (pAVar2 != (AudioInputQueue *)0x0) {
    (**(code **)(*(longlong *)pAVar2 + 0x38))(pAVar2,1);
  }
  return iVar1;
}



===== MakeAndInitialize @ 14002c72c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::MakeAndInitialize(struct
   WDFQUEUE__ * __ptr64,class Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue *
   __ptr64 * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::MakeAndInitialize
          (WDFQUEUE__ *param_1,AudioOutputQueue **param_2)

{
  long lVar1;
  AudioOutputQueue *pAVar2;
  void *pvVar3;
  undefined8 local_68;
  code *pcStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  WDFQUEUE__ *local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_40 = 0;
  local_20 = 0;
  *param_2 = (AudioOutputQueue *)0x0;
  uStack_48 = 0;
  local_50 = 0x38;
  pvVar3 = (void *)0x40;
  uStack_38 = 0x100000001;
  local_30 = (WDFQUEUE__ *)0x0;
  uStack_28 = 0;
  pAVar2 = (AudioOutputQueue *)ExAllocatePool2(0x40,200,0x646d4370);
  if (pAVar2 == (AudioOutputQueue *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    *(WDFQUEUE__ **)(pAVar2 + 8) = param_1;
    *(longlong *)(pAVar2 + 0x10) = 0;
    *(undefined ***)pAVar2 = &_vftable_;
    *(longlong *)(pAVar2 + 0x18) = 0;
    *(longlong *)(pAVar2 + 0x20) = 0;
    *(longlong *)(pAVar2 + 0x28) = 0;
    *(longlong *)(pAVar2 + 0x30) = 0;
    *(longlong *)(pAVar2 + 0x38) = 0;
    *(longlong *)(pAVar2 + 0x40) = 0;
    *(longlong *)(pAVar2 + 0x48) = 0;
    *(undefined ***)(pAVar2 + 0x50) =
         &ByteBuffer::_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteWriter__;
    *(undefined ***)(pAVar2 + 0x58) =
         &ByteBuffer::_vftable__for__Microsoft__Bluetooth__Profiles__Hfp__Streaming__ByteReader__;
    *(longlong *)(pAVar2 + 0x60) = 0;
    *(longlong *)(pAVar2 + 0x68) = 0;
    *(longlong *)(pAVar2 + 0x70) = 0;
    *(longlong *)(pAVar2 + 0x78) = 0;
    pAVar2[0x80] = (AudioOutputQueue)0x0;
    *(undefined4 *)(pAVar2 + 0x88) = 0;
    *(longlong *)(pAVar2 + 0x90) = 0;
    *(longlong *)(pAVar2 + 0x98) = 0;
    *(longlong *)(pAVar2 + 0xa0) = 0;
    *(longlong *)(pAVar2 + 0xa8) = 0;
    *(longlong *)(pAVar2 + 0xb0) = 0;
    *(longlong *)(pAVar2 + 0xb8) = 0;
    *(undefined4 *)(pAVar2 + 0xc0) = 0;
    lVar1 = Foundation::SentRequestCollection::MakeAndInitialize
                      (pvVar3,(SentRequestCollection **)(pAVar2 + 0xa0));
    if (-1 < lVar1) {
      local_58 = 1;
      local_68 = 0x18;
      pcStack_60 = EvtAttemptProcessingWorkItem;
      local_40 = 0;
      local_20 = 0;
      uStack_48 = 0;
      local_50 = 0x38;
      uStack_28 = 0;
      uStack_38 = 0x100000001;
      local_30 = param_1;
      lVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                        (WdfDriverGlobals,&local_68,&local_50,pAVar2 + 0x98);
      if (-1 < lVar1) {
        *param_2 = pAVar2;
        return 0;
      }
    }
    (**(code **)(*(longlong *)pAVar2 + 0x38))(pAVar2,1);
  }
  return lVar1;
}



===== MakeAndInitialize @ 14002c918 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::MakeAndInitialize(struct
   WDFQUEUE__ * __ptr64,unsigned long) */

long __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::MakeAndInitialize
          (WDFQUEUE__ *param_1,ulong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *local_res18;
  AudioInputQueue *local_res20;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_4c;
  code *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined *local_28;
  
  local_res18 = (undefined8 *)0x0;
  local_54 = 0;
  local_4c = 0;
  local_40 = 1;
  local_3c = 1;
  local_28 = PTR__WDF_AudioQueueProxy_TYPE_INFO_1400224a8;
  local_48 = WdfCpp::
             ObjectContext<WDFQUEUE__*___ptr64,Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy,0>
             ::EvtObjectContextDestroyThunk;
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0x38;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,&local_58,&local_res18)
  ;
  puVar1 = local_res18;
  if (-1 < iVar2) {
    if (local_res18 != (undefined8 *)0x0) {
      *local_res18 = 0;
      local_res18[1] = 0;
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,local_res18);
      puVar1[1] = 0;
      *puVar1 = uVar3;
    }
    local_res18 = puVar1;
    if (param_2 == 0) {
      local_res20 = (AudioInputQueue *)0x0;
      iVar2 = AudioOutputQueue::MakeAndInitialize(param_1,(AudioOutputQueue **)&local_res20);
    }
    else {
      if (param_2 != 1) {
        return iVar2;
      }
      local_res20 = (AudioInputQueue *)0x0;
      iVar2 = AudioInputQueue::MakeAndInitialize(param_1,&local_res20);
    }
    local_res18[1] = local_res20;
  }
  return iVar2;
}



===== MakeAndInitialize @ 14002ca2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Foundation::SentRequestCollection::MakeAndInitialize(void * __ptr64,class
   Microsoft::Bluetooth::Foundation::SentRequestCollection * __ptr64 * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Foundation::SentRequestCollection::MakeAndInitialize
          (void *param_1,SentRequestCollection **param_2)

{
  int iVar1;
  SentRequestCollection *pSVar2;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  *param_2 = (SentRequestCollection *)0x0;
  local_18 = 0;
  local_38 = 0;
  uStack_40 = 0;
  local_48 = 0x38;
  uStack_20 = 0;
  local_28 = 0;
  uStack_30 = 0x100000001;
  pSVar2 = (SentRequestCollection *)ExAllocatePool2(0x40,0x18,0x646d4370);
  if (pSVar2 == (SentRequestCollection *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *(undefined8 *)pSVar2 = 0;
    *(undefined8 *)(pSVar2 + 8) = 0;
    *(undefined8 *)(pSVar2 + 0x10) = 0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_48,pSVar2);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_48,pSVar2 + 8);
      if (-1 < iVar1) {
        *param_2 = pSVar2;
      }
    }
  }
  return iVar1;
}



===== Process @ 14002cb04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::Process(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::Process(AudioInputQueue *this)

{
  int iVar1;
  code *pcVar2;
  AudioInputQueue *pAVar3;
  char cVar4;
  bool bVar5;
  ulong uVar6;
  longlong lVar7;
  RequestContext *pRVar8;
  ByteWriter *pBVar9;
  undefined8 uVar10;
  __uint64 _Var11;
  longlong lVar12;
  RequestContext *pRVar13;
  AudioInputQueue *pAVar14;
  RequestContext *pRVar15;
  RequestContext *in_R8;
  AudioInputQueue *in_R9;
  undefined4 local_res8 [2];
  int local_res10;
  int local_res14;
  AudioInputQueue *local_res18;
  
  lVar7 = KeQueryPerformanceCounter(0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_R8 = (RequestContext *)&WPP_4de776f173d133e87e80f57736d58590_Traceguids;
    in_R9 = this;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_4de776f173d133e87e80f57736d58590_Traceguids,this);
  }
  lVar12 = *(longlong *)(this + 0xd8);
  do {
    if ((lVar12 == 0) || (uVar6 = GetCompletedScoRequestCount(this), uVar6 == 0)) {
      if (*(longlong *)(this + 0x18) == 0) {
        while (uVar6 = GetCompletedScoRequestCount(this), uVar6 != 0) {
          pRVar13 = GetFirstCompletedScoRequest(this);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,in_R8,pRVar13,(char)this);
          }
          RemoveCompletedScoRequest(this,pRVar13);
          ScoReader::ReturnRequestToPool(*(WDFREQUEST__ **)pRVar13);
        }
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_4de776f173d133e87e80f57736d58590_Traceguids,this);
      }
      return;
    }
    pRVar8 = GetFirstCompletedScoRequest(this);
    in_R8 = pRVar8 + 0x10;
    LOCK();
    iVar1 = *(int *)(pRVar8 + 0x40);
    *(int *)(pRVar8 + 0x40) = *(int *)(pRVar8 + 0x40);
    UNLOCK();
    TransportParser::WriteBytesFromTransportStream
              ((TransportParser *)(this + 0x48),(ByteReader *)&local_res10);
    pBVar9 = (ByteWriter *)(**(code **)(**(longlong **)(this + 0xd0) + 0x28))();
    TransportParser::ReadFrameBytes((TransportParser *)(this + 0x48),pBVar9);
    (**(code **)(**(longlong **)(this + 0xd0) + 0x38))();
    lVar12 = *(longlong *)(this + 0xd8);
    pcVar2 = *(code **)(*(longlong *)(lVar12 + 8) + 8);
    uVar10 = (**(code **)(**(longlong **)(this + 0xd0) + 0x30))();
    (*pcVar2)(lVar12 + 8,uVar10);
    *(int *)(this + 0x104) = *(int *)(this + 0x104) + local_res14;
    *(int *)(this + 0x108) = *(int *)(this + 0x108) + local_res10;
    pRVar13 = in_R8;
    if ((iVar1 < 0) ||
       (cVar4 = (**(code **)(*(longlong *)(*(longlong *)(this + 0xd8) + 8) + 0x18))(),
       pRVar13 = in_R8, cVar4 != '\0')) {
      pRVar15 = *(RequestContext **)(this + 0xd8) + 8;
      _Var11 = RequestContext::GetSize(*(RequestContext **)(this + 0xd8));
      lVar12 = (**(code **)(*(longlong *)pRVar15 + 0x10))(pRVar15);
      in_R8 = (RequestContext *)(_Var11 - lVar12);
      pAVar3 = (AudioInputQueue *)**(undefined8 **)(this + 0xd8);
      *(undefined8 *)(this + 0xd8) = 0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        in_R9 = pAVar3;
        WPP_SF_qDdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pRVar15,pRVar13,pAVar3,(char)in_R8,
                    (char)iVar1,(char)this);
      }
      in_R9 = (AudioInputQueue *)CONCAT71((int7)((ulonglong)in_R9 >> 8),1);
      pAVar14 = pAVar3;
      bVar5 = AudioQueueClient_CompleteStreamTransferRequest(pAVar3,0,in_R8,'\x01',lVar7);
      if (!bVar5) {
        *(int *)(this + 0x118) = *(int *)(this + 0x118) + 1;
        if (3 < DAT_140022000) {
          local_res8[0] = *(undefined4 *)(this + 0x118);
          local_res18 = pAVar3;
          _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
          ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
                    ((_tlgProvider_t *)pAVar14,&DAT_14001f2f5,(_GUID *)in_R8,(_GUID *)in_R9,
                     (_tlgWrapperByVal<8> *)&local_res18,(_tlgWrapperByVal<4> *)local_res8);
        }
      }
      if (-1 < iVar1) goto LAB_14002cd11;
LAB_14002cd25:
      RemoveCompletedScoRequest(this,pRVar8);
      ScoReader::ReturnRequestToPool(*(WDFREQUEST__ **)pRVar8);
    }
    else {
LAB_14002cd11:
      cVar4 = (**(code **)(*(longlong *)(pRVar8 + 0x10) + 0x18))();
      if (cVar4 != '\0') goto LAB_14002cd25;
    }
    lVar12 = *(longlong *)(this + 0xd8);
  } while( true );
}



===== Process @ 14002cdfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::Process(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::Process(AudioOutputQueue *this)

{
  TransportFormatter *this_00;
  AudioOutputQueue *pAVar1;
  WDFREQUEST__ *pWVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  __uint64 _Var8;
  AudioOutputQueue *pAVar9;
  ByteReader *pBVar10;
  longlong lVar11;
  _GUID *p_Var12;
  RequestContext *pRVar13;
  RequestContext *pRVar14;
  RequestContext *in_R9;
  undefined4 local_res8 [2];
  RequestContext *local_res10;
  undefined8 in_stack_ffffffffffffffd8;
  undefined1 uVar15;
  
  while( true ) {
    uVar5 = GetNumSentScoRequests(this);
    pAVar9 = *(AudioOutputQueue **)(this + 0x18);
    if ((pAVar9 == (AudioOutputQueue *)0x0) || (1 < (int)uVar5)) {
      pRVar14 = (RequestContext *)0x0;
    }
    else {
      pRVar14 = (RequestContext *)0x1;
    }
    cVar3 = (char)pRVar14;
    uVar15 = SUB81(this,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Dqddq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar5,pAVar9,(int)pRVar14,
                   (char)pAVar9,(char)uVar5,in_stack_ffffffffffffffd8,uVar15);
      in_R9 = pRVar14;
    }
    if (cVar3 == '\0') break;
    pAVar1 = this + 0x90;
    if (*(longlong *)(this + 0x10) != 0) {
      this_00 = (TransportFormatter *)(this + 0x28);
      if (*(RequestContext **)pAVar1 == (RequestContext *)0x0) {
        _Var8 = TransportFormatter::GetTransportPacketStride(this_00);
        lVar6 = RequestContext::MakeAndAttachToNewBrb
                          (*(WDFQUEUE__ **)(this + 8),_Var8,(RequestContext **)pAVar1);
        if (lVar6 < 0) {
          return;
        }
      }
      pAVar9 = (AudioOutputQueue *)(**(code **)(**(longlong **)(this + 0x20) + 0x28))();
      (**(code **)(*(longlong *)pAVar9 + 8))(pAVar9,*(longlong *)(this + 0x18) + 0x10);
      (**(code **)(**(longlong **)(this + 0x20) + 0x38))();
      pBVar10 = (ByteReader *)(**(code **)(**(longlong **)(this + 0x20) + 0x30))();
      TransportFormatter::WriteFrameBytes(this_00,pBVar10);
      TransportFormatter::ReadTransportStreamBytes
                (this_00,(ByteWriter *)(*(RequestContext **)pAVar1 + 8));
    }
    if ((*(RequestContext **)pAVar1 != (RequestContext *)0x0) &&
       (cVar3 = (**(code **)(*(longlong *)(*(RequestContext **)pAVar1 + 8) + 0x18))(), cVar3 != '\0'
       )) {
      in_R9 = *(RequestContext **)pAVar1;
      pWVar2 = *(WDFREQUEST__ **)in_R9;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])))) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,pAVar9,in_R9,uVar15);
      }
      lVar6 = Foundation::SentRequestCollection::Add
                        (*(SentRequestCollection **)(this + 0xa0),pWVar2);
      if (-1 < lVar6) {
        pAVar9 = this;
        in_R9 = (RequestContext *)pWVar2;
        iVar7 = AudioQueueClient_SendTransferBrb
                          (*(undefined8 *)(this + 8),EvtScoRequestCompletionRoutine,this,pWVar2);
        if (iVar7 < 0) {
          Foundation::SentRequestCollection::Remove(*(SentRequestCollection **)(this + 0xa0),pWVar2)
          ;
        }
        else {
          *(int *)(this + 0xb4) = *(int *)(this + 0xb4) + 1;
          *(undefined8 *)(this + 0x90) = 0;
        }
      }
    }
    cVar3 = (**(code **)(*(longlong *)(*(longlong *)(this + 0x18) + 0x10) + 0x18))();
    if (cVar3 == '\0') {
      if (*(longlong *)(this + 0x10) == 0) {
        lVar11 = KeQueryPerformanceCounter(0);
        pRVar14 = (RequestContext *)**(undefined8 **)(this + 0x18);
        *(undefined8 *)(this + 0x18) = 0;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          in_R9 = pRVar14;
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,pAVar9,pRVar14,uVar15);
        }
        in_R9 = (RequestContext *)CONCAT71((int7)((ulonglong)in_R9 >> 8),1);
        AudioQueueClient_CompleteStreamTransferRequest(pRVar14,-0x3ffffdc0,0,'\x01',lVar11);
      }
    }
    else {
      lVar11 = KeQueryPerformanceCounter(0);
      pRVar14 = *(RequestContext **)*(RequestContext **)(this + 0x18);
      p_Var12 = (_GUID *)RequestContext::GetSize(*(RequestContext **)(this + 0x18));
      *(undefined8 *)(this + 0x18) = 0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        in_R9 = pRVar14;
        WPP_SF_qdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,pAVar9,pRVar14,(char)p_Var12,
                   uVar15);
      }
      in_R9 = (RequestContext *)CONCAT71((int7)((ulonglong)in_R9 >> 8),1);
      pRVar13 = pRVar14;
      bVar4 = AudioQueueClient_CompleteStreamTransferRequest(pRVar14,0,p_Var12,'\x01',lVar11);
      if (!bVar4) {
        *(int *)(this + 0xc0) = *(int *)(this + 0xc0) + 1;
        if (3 < DAT_140022000) {
          local_res8[0] = *(undefined4 *)(this + 0xc0);
          local_res10 = pRVar14;
          _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
          ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
                    ((_tlgProvider_t *)pRVar13,&DAT_14001f39a,p_Var12,(_GUID *)in_R9,
                     (_tlgWrapperByVal<8> *)&local_res10,(_tlgWrapperByVal<4> *)local_res8);
        }
      }
    }
  }
  return;
}



===== ProcessRequest @ 14002d120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::ProcessRequest(struct
   WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::ProcessRequest
          (AudioInputQueue *this,WDFREQUEST__ *param_1)

{
  RequestContext *pRVar1;
  bool bVar2;
  long lVar3;
  longlong lVar4;
  undefined8 in_R8;
  char cVar5;
  RequestContext *local_res8;
  
  cVar5 = '\0';
  lVar4 = KeQueryPerformanceCounter(0);
  local_res8 = (RequestContext *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,in_R8,param_1,(char)this);
  }
  *(int *)(this + 0x114) = *(int *)(this + 0x114) + 1;
  lVar3 = RequestContext::MakeAndAttachToClientRequest(param_1,&local_res8);
  if (-1 < lVar3) {
    lVar3 = AudioQueueRequestContext::MakeAndAttachToRequest(param_1,(AudioQueue *)this);
    if (-1 < lVar3) {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_1);
      pRVar1 = local_res8;
      if (-1 < lVar3) {
        local_res8 = (RequestContext *)0x0;
        cVar5 = '\x01';
        *(RequestContext **)(this + 0xd8) = pRVar1;
        Process(this);
      }
    }
  }
  bVar2 = IsRunning(this);
  if (bVar2) {
    ScoReader::ContinueReading((ScoReader *)(this + 0x20));
  }
  if (local_res8 != (RequestContext *)0x0) {
    AudioQueueClient_CompleteStreamTransferRequest(param_1,lVar3,0,cVar5,lVar4);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_4de776f173d133e87e80f57736d58590_Traceguids,this);
  }
  return;
}



===== ProcessRequest @ 14002d290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::ProcessRequest(struct
   WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::ProcessRequest
          (AudioOutputQueue *this,WDFREQUEST__ *param_1)

{
  RequestContext *pRVar1;
  long lVar2;
  longlong lVar3;
  undefined8 in_R8;
  char cVar4;
  RequestContext *local_res8;
  
  cVar4 = '\0';
  lVar3 = KeQueryPerformanceCounter(0);
  local_res8 = (RequestContext *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,in_R8,param_1,(char)this);
  }
  *(int *)(this + 0xbc) = *(int *)(this + 0xbc) + 1;
  lVar2 = RequestContext::MakeAndAttachToClientRequest(param_1,&local_res8);
  if (-1 < lVar2) {
    lVar2 = AudioQueueRequestContext::MakeAndAttachToRequest(param_1,(AudioQueue *)this);
    if (-1 < lVar2) {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_1);
      pRVar1 = local_res8;
      if (-1 < lVar2) {
        local_res8 = (RequestContext *)0x0;
        cVar4 = '\x01';
        *(RequestContext **)(this + 0x18) = pRVar1;
        Process(this);
      }
    }
  }
  if (local_res8 != (RequestContext *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_4de776f173d133e87e80f57736d58590_Traceguids,lVar2,(char)this);
    }
    AudioQueueClient_CompleteStreamTransferRequest(param_1,lVar2,0,cVar4,lVar3);
  }
  return;
}



===== SetCodecId @ 14002d3e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::SetCodecId(enum _CODECID)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::SetCodecId
          (AudioInputQueue *this,_CODECID param_1)

{
  AudioInputQueue *pAVar1;
  longlong *plVar2;
  bool bVar3;
  _CODECID _Var4;
  long lVar5;
  int iVar6;
  TransportPacketHeaderType TVar7;
  __uint64 _Var8;
  NullCodec *pNVar9;
  __uint64 _Var10;
  __uint64 in_R8;
  NullCodec *local_res18;
  
  if (param_1 == 0) {
    return 0;
  }
  pAVar1 = this + 0xd0;
  if ((*(longlong **)pAVar1 != (longlong *)0x0) &&
     (_Var4 = (**(code **)(**(longlong **)pAVar1 + 0x18))(), _Var4 == param_1)) {
    return 0;
  }
  plVar2 = *(longlong **)pAVar1;
  bVar3 = true;
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x40))(plVar2,1);
  }
  *(longlong *)pAVar1 = 0;
  lVar5 = -0x3fffff45;
  if (param_1 == 1) {
    local_res18 = (NullCodec *)0x0;
    lVar5 = NullCodec::MakeAndInitialize(&local_res18);
  }
  else {
    pNVar9 = (NullCodec *)0x0;
    if (param_1 != 2) goto LAB_14002d494;
    local_res18 = (NullCodec *)0x0;
    lVar5 = SbcWbsCodec::MakeAndInitialize(1,(SbcWbsCodec **)&local_res18);
  }
  *(NullCodec **)pAVar1 = local_res18;
  pNVar9 = local_res18;
LAB_14002d494:
  if (-1 < lVar5) {
    iVar6 = (**(code **)(*(longlong *)pNVar9 + 8))();
    _Var10 = (__uint64)iVar6;
    TVar7 = (**(code **)**(undefined8 **)(this + 0xd0))();
    in_R8 = _Var10;
    lVar5 = TransportParser::Configure((TransportParser *)(this + 0x48),TVar7,_Var10);
    if (-1 < lVar5) {
      _Var8 = TransportFormatter::GetTransportPacketStride((TransportFormatter *)(this + 0x48));
      *(__uint64 *)(this + 0x30) = _Var8;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return lVar5;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
        return lVar5;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return lVar5;
      }
      WPP_SF_PPq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                 (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),in_R8,_Var10,(char)_Var8,(char)this
                );
      return lVar5;
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
  {
    bVar3 = false;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) && (bVar3)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,in_R8,this,(char)lVar5)
    ;
  }
  return lVar5;
}



===== SetCodecId @ 14002d570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::SetCodecId(enum _CODECID)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::SetCodecId
          (AudioOutputQueue *this,_CODECID param_1)

{
  longlong *plVar1;
  _CODECID _Var2;
  long lVar3;
  int iVar4;
  TransportPacketHeaderType TVar5;
  NullCodec *pNVar6;
  AudioOutputQueue *pAVar7;
  NullCodec *local_res18 [2];
  
  if (param_1 == 0) {
    return 0;
  }
  pAVar7 = this + 0x20;
  if ((*(longlong **)pAVar7 != (longlong *)0x0) &&
     (_Var2 = (**(code **)(**(longlong **)pAVar7 + 0x18))(), _Var2 == param_1)) {
    return 0;
  }
  plVar1 = *(longlong **)pAVar7;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x40))(plVar1,1);
  }
  *(longlong *)pAVar7 = 0;
  if (*(undefined8 **)(this + 0x90) != (undefined8 *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,**(undefined8 **)(this + 0x90));
    *(undefined8 *)(this + 0x90) = 0;
  }
  pAVar7 = this + 0x20;
  *(undefined8 *)pAVar7 = 0;
  lVar3 = -0x3fffff45;
  if (param_1 == 1) {
    local_res18[0] = (NullCodec *)0x0;
    lVar3 = NullCodec::MakeAndInitialize(local_res18);
  }
  else {
    pNVar6 = (NullCodec *)0x0;
    if (param_1 != 2) goto LAB_14002d64f;
    local_res18[0] = (NullCodec *)0x0;
    lVar3 = SbcWbsCodec::MakeAndInitialize(0,(SbcWbsCodec **)local_res18);
  }
  *(NullCodec **)pAVar7 = local_res18[0];
  pNVar6 = local_res18[0];
LAB_14002d64f:
  if (-1 < lVar3) {
    iVar4 = (**(code **)(*(longlong *)pNVar6 + 0x10))();
    TVar5 = (**(code **)**(undefined8 **)pAVar7)();
    lVar3 = TransportFormatter::Configure((TransportFormatter *)(this + 0x28),TVar5,(longlong)iVar4)
    ;
  }
  return lVar3;
}



===== Stop @ 14002d6a0 =====

/* public: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::Stop(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::Stop(AudioInputQueue *this)

{
  Foundation::SentRequestCollection::Stop(*(SentRequestCollection **)(this + 0xf8));
  return;
}



===== Stop @ 14002d6c0 =====

/* public: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::Stop(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::Stop(AudioOutputQueue *this)

{
  Foundation::SentRequestCollection::Stop(*(SentRequestCollection **)(this + 0xa0));
  return;
}



===== StreamStart @ 14002d6e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::StreamStart(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::StreamStart(AudioInputQueue *this)

{
  undefined8 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_4de776f173d133e87e80f57736d58590_Traceguids,this);
  }
  (**(code **)(**(longlong **)(this + 0xd0) + 0x20))();
  TransportParser::ResetParserState((TransportParser *)(this + 0x48));
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  uVar1 = KeQueryPerformanceCounter(0);
  *(undefined8 *)(this + 0x18) = uVar1;
  return;
}



===== StreamStart @ 14002d780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::StreamStart(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::StreamStart
          (AudioOutputQueue *this)

{
  undefined8 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_4de776f173d133e87e80f57736d58590_Traceguids,this);
  }
  (**(code **)(**(longlong **)(this + 0x20) + 0x20))();
  TransportFormatter::ResetBuffers((TransportFormatter *)(this + 0x28));
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  uVar1 = KeQueryPerformanceCounter(0);
  *(undefined8 *)(this + 0x10) = uVar1;
  return;
}



===== StreamStop @ 14002d820 =====

/* public: virtual struct AudioQueueStreamStats __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::StreamStop(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioInputQueue::StreamStop(AudioInputQueue *this)

{
  undefined8 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *in_RDX;
  longlong local_res8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_4de776f173d133e87e80f57736d58590_Traceguids,this);
  }
  local_res8 = 0;
  lVar5 = KeQueryPerformanceCounter(&local_res8);
  lVar3 = *(longlong *)(this + 0x18);
  *(undefined8 *)(this + 0x18) = 0;
  *(int *)(this + 0x100) = (int)(((lVar5 - lVar3) * 1000) / local_res8);
  AudioQueueClient_FlushChannel(*(undefined8 *)(this + 8));
  EmptyCompletedScoRequests(this);
  uVar2 = *(undefined4 *)(this + 0x118);
  uVar4 = *(undefined8 *)(this + 0x108);
  uVar1 = *(undefined8 *)(this + 0x110);
  *in_RDX = *(undefined8 *)(this + 0x100);
  in_RDX[1] = uVar4;
  in_RDX[2] = uVar1;
  *(undefined4 *)(in_RDX + 3) = uVar2;
  return;
}



===== StreamStop @ 14002d8f0 =====

/* public: virtual struct AudioQueueStreamStats __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::StreamStop(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioOutputQueue::StreamStop(AudioOutputQueue *this)

{
  undefined8 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *in_RDX;
  longlong local_res8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_4de776f173d133e87e80f57736d58590_Traceguids,this);
  }
  local_res8 = 0;
  lVar5 = KeQueryPerformanceCounter(&local_res8);
  lVar3 = *(longlong *)(this + 0x10);
  *(undefined8 *)(this + 0x10) = 0;
  *(int *)(this + 0xa8) = (int)(((lVar5 - lVar3) * 1000) / local_res8);
  AudioQueueClient_FlushChannel(*(undefined8 *)(this + 8));
  uVar2 = *(undefined4 *)(this + 0xc0);
  uVar4 = *(undefined8 *)(this + 0xb0);
  uVar1 = *(undefined8 *)(this + 0xb8);
  *in_RDX = *(undefined8 *)(this + 0xa8);
  in_RDX[1] = uVar4;
  in_RDX[2] = uVar1;
  *(undefined4 *)(in_RDX + 3) = uVar2;
  return;
}



===== AudioQueue_CancelRequest @ 14002d9ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AudioQueue_CancelRequest(WDFQUEUE__ *param_1,undefined8 param_2)

{
  AudioQueueProxy *pAVar1;
  
  pAVar1 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject
                     (param_1);
  (**(code **)(**(longlong **)(pAVar1 + 8) + 0x18))(*(longlong **)(pAVar1 + 8),param_2);
  return;
}



===== AudioQueue_IsReadyToProcessNextRequest @ 14002d9dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AudioQueue_IsReadyToProcessNextRequest(WDFQUEUE__ *param_1)

{
  AudioQueueProxy *pAVar1;
  
  pAVar1 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject
                     (param_1);
  (**(code **)(**(longlong **)(pAVar1 + 8) + 8))();
  return;
}



===== AudioQueue_MakeAndInitialize @ 14002da04 =====

void AudioQueue_MakeAndInitialize(WDFQUEUE__ *param_1,ulong param_2)

{
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::MakeAndInitialize
            (param_1,param_2);
  return;
}



===== AudioQueue_ProcessRequest @ 14002da1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AudioQueue_ProcessRequest(WDFQUEUE__ *param_1,undefined8 param_2)

{
  AudioQueueProxy *pAVar1;
  
  pAVar1 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject
                     (param_1);
  (**(code **)(**(longlong **)(pAVar1 + 8) + 0x10))(*(longlong **)(pAVar1 + 8),param_2);
  return;
}



===== AudioQueue_SetCodecId @ 14002da4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AudioQueue_SetCodecId(WDFQUEUE__ *param_1,undefined4 param_2)

{
  AudioQueueProxy *pAVar1;
  
  pAVar1 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject
                     (param_1);
  (**(code **)**(undefined8 **)(pAVar1 + 8))(*(undefined8 **)(pAVar1 + 8),param_2);
  return;
}



===== AudioQueue_Stop @ 14002da78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AudioQueue_Stop(WDFQUEUE__ *param_1)

{
  AudioQueueProxy *pAVar1;
  
  pAVar1 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject
                     (param_1);
  (**(code **)(**(longlong **)(pAVar1 + 8) + 0x30))();
  return;
}



===== AudioQueue_StreamStart @ 14002daa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AudioQueue_StreamStart(WDFQUEUE__ *param_1)

{
  AudioQueueProxy *pAVar1;
  
  pAVar1 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject
                     (param_1);
  (**(code **)(**(longlong **)(pAVar1 + 8) + 0x20))();
  return;
}



===== AudioQueue_StreamStop @ 14002dac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 * AudioQueue_StreamStop(undefined8 *param_1,WDFQUEUE__ *param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  AudioQueueProxy *pAVar4;
  undefined8 *puVar5;
  undefined1 local_28 [32];
  
  pAVar4 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::AudioQueueProxy::GetContextFromObject
                     (param_2);
  puVar5 = (undefined8 *)
           (**(code **)(**(longlong **)(pAVar4 + 8) + 0x28))(*(longlong **)(pAVar4 + 8),local_28);
  uVar3 = puVar5[1];
  uVar1 = puVar5[2];
  uVar2 = *(undefined4 *)(puVar5 + 3);
  *param_1 = *puVar5;
  param_1[1] = uVar3;
  param_1[2] = uVar1;
  *(undefined4 *)(param_1 + 3) = uVar2;
  return param_1;
}



===== ~SbcWbsCodec @ 14002db14 =====

/* private: virtual __cdecl SbcWbsCodec::~SbcWbsCodec(void) __ptr64 */

void __thiscall SbcWbsCodec::~SbcWbsCodec(SbcWbsCodec *this)

{
  *(undefined ***)this = &_vftable_;
  operator_delete(*(void **)(this + 0x18));
  operator_delete(*(void **)(this + 0x58));
  operator_delete(*(void **)(this + 0x98));
  operator_delete(*(void **)(this + 8));
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::~ByteBuffer
            ((ByteBuffer *)(this + 0x60));
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::~ByteBuffer
            ((ByteBuffer *)(this + 0x20));
  return;
}



===== GetTransportPacketHeaderType @ 14002db70 =====

/* public: virtual enum Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportPacketHeaderType
   __cdecl SbcWbsCodec::GetTransportPacketHeaderType(void)const __ptr64 */

TransportPacketHeaderType __thiscall SbcWbsCodec::GetTransportPacketHeaderType(SbcWbsCodec *this)

{
  return 1;
}



===== GetCodecId @ 14002db80 =====

/* public: virtual enum _CODECID __cdecl SbcWbsCodec::GetCodecId(void)const __ptr64 */

_CODECID __thiscall SbcWbsCodec::GetCodecId(SbcWbsCodec *this)

{
  return 2;
}



===== GetInputBuffer @ 14002db90 =====

/* public: virtual class Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteWriter & __ptr64
   __cdecl NullCodec::GetInputBuffer(void) __ptr64 */

ByteWriter * __thiscall NullCodec::GetInputBuffer(NullCodec *this)

{
  return (ByteWriter *)(this + 0x10);
}



===== GetInputBuffer @ 14002dba0 =====

/* public: virtual class Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteWriter & __ptr64
   __cdecl SbcWbsCodec::GetInputBuffer(void) __ptr64 */

ByteWriter * __thiscall SbcWbsCodec::GetInputBuffer(SbcWbsCodec *this)

{
  return (ByteWriter *)(this + 0x20);
}



===== GetInputFrameSize @ 14002dbb0 =====

/* public: virtual int __cdecl NullCodec::GetInputFrameSize(void)const __ptr64 */

int __thiscall NullCodec::GetInputFrameSize(NullCodec *this)

{
  return 0xa0;
}



===== GetInputFrameSize @ 14002dbc0 =====

/* public: virtual int __cdecl SbcWbsCodec::GetInputFrameSize(void)const __ptr64 */

int __thiscall SbcWbsCodec::GetInputFrameSize(SbcWbsCodec *this)

{
  int iVar1;
  
  iVar1 = SBC::GetInputFrameLength(*(SBC **)(this + 8));
  return iVar1;
}



===== GetOutputBuffer @ 14002dbe0 =====

/* public: virtual class Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteReader & __ptr64
   __cdecl NullCodec::GetOutputBuffer(void) __ptr64 */

ByteReader * __thiscall NullCodec::GetOutputBuffer(NullCodec *this)

{
  return (ByteReader *)(this + 0x18);
}



===== GetOutputBuffer @ 14002dbf0 =====

/* public: virtual class Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteReader & __ptr64
   __cdecl SbcWbsCodec::GetOutputBuffer(void) __ptr64 */

ByteReader * __thiscall SbcWbsCodec::GetOutputBuffer(SbcWbsCodec *this)

{
  return (ByteReader *)(this + 0x68);
}



===== GetOutputFrameSize @ 14002dc00 =====

/* public: virtual int __cdecl SbcWbsCodec::GetOutputFrameSize(void)const __ptr64 */

int __thiscall SbcWbsCodec::GetOutputFrameSize(SbcWbsCodec *this)

{
  int iVar1;
  
  if (*(int *)(this + 0x10) == 0) {
    iVar1 = SBC::GetOutputFrameLength(*(SBC **)(this + 8));
  }
  else {
    iVar1 = 0xf0;
  }
  return iVar1;
}



===== GetTransportPacketHeaderType @ 14002dc30 =====

/* public: virtual enum Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportPacketHeaderType
   __cdecl NullCodec::GetTransportPacketHeaderType(void)const __ptr64 */

TransportPacketHeaderType __thiscall NullCodec::GetTransportPacketHeaderType(NullCodec *this)

{
  return 0;
}



===== Initialize @ 14002dc3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl SbcWbsCodec::Initialize(void) __ptr64 */

long __thiscall SbcWbsCodec::Initialize(SbcWbsCodec *this)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  iVar1 = (**(code **)(*(longlong *)this + 8))();
  iVar2 = (**(code **)(*(longlong *)this + 0x10))(this);
  uVar4 = ExAllocatePool2(0x40,(longlong)iVar1,0x646d4370);
  *(undefined8 *)(this + 0x18) = uVar4;
  uVar4 = ExAllocatePool2(0x40,(longlong)iVar2,0x646d4370);
  *(undefined8 *)(this + 0x58) = uVar4;
  if (*(int *)(this + 0x10) == 1) {
    lVar5 = ExAllocatePool2(0x40,(longlong)(iVar2 * 2),0x646d4370);
    *(longlong *)(this + 0x98) = lVar5;
  }
  if (((*(longlong *)(this + 0x18) == 0) || (*(longlong *)(this + 0x58) == 0)) ||
     ((*(longlong *)(this + 0x98) == 0 && (*(int *)(this + 0x10) == 1)))) {
    lVar3 = -0x3fffff66;
  }
  else {
    (**(code **)(*(longlong *)this + 0x20))(this);
    lVar3 = 0;
  }
  return lVar3;
}



===== MakeAndInitialize @ 14002dd2c =====

/* public: static long __cdecl NullCodec::MakeAndInitialize(class NullCodec * __ptr64 * __ptr64) */

long __cdecl NullCodec::MakeAndInitialize(NullCodec **param_1)

{
  char *pcVar1;
  NullCodec *pNVar2;
  __uint64 _Var3;
  long lVar4;
  
  lVar4 = 0;
  *param_1 = (NullCodec *)0x0;
  pcVar1 = (char *)ExAllocatePool2(0x40,0xa0,0x46485442);
  if (pcVar1 == (char *)0x0) {
    lVar4 = -0x3fffff66;
  }
  else {
    pNVar2 = (NullCodec *)ExAllocatePool2(0x40,0x48,0x646d4370);
    if (pNVar2 == (NullCodec *)0x0) {
      ExFreePoolWithTag(pcVar1,0);
    }
    else {
      pNVar2[8] = (NullCodec)0x1;
      *(undefined ***)pNVar2 = &_vftable_;
      Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ByteBuffer
                ((ByteBuffer *)(pNVar2 + 0x10),pcVar1,0xa0,true);
      _Var3 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::GetUnconsumedBufferLength
                        ((ByteBuffer *)(pNVar2 + 0x18));
      Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::AdvanceOutputOffset
                ((ByteBuffer *)(pNVar2 + 0x10),_Var3);
      *param_1 = pNVar2;
    }
  }
  return lVar4;
}



===== Process @ 14002de10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl NullCodec::Process(void) __ptr64 */

void __thiscall NullCodec::Process(NullCodec *this)

{
  char cVar1;
  longlong *plVar2;
  
  if (this[8] != (NullCodec)0x0) {
    plVar2 = (longlong *)(**(code **)(*(longlong *)this + 0x28))();
    cVar1 = (**(code **)(*plVar2 + 0x18))(plVar2);
    if (cVar1 != '\0') {
      this[8] = (NullCodec)0x0;
      Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ResetOutputOffset
                ((ByteBuffer *)(this + 0x10));
      return;
    }
  }
  if (this[8] == (NullCodec)0x0) {
    plVar2 = (longlong *)(**(code **)(*(longlong *)this + 0x30))(this);
    cVar1 = (**(code **)(*plVar2 + 0x18))(plVar2);
    if (cVar1 != '\0') {
      this[8] = (NullCodec)0x1;
      Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ResetInputOffset
                ((ByteBuffer *)(this + 0x10));
    }
  }
  return;
}



===== Process @ 14002dea0 =====

/* public: virtual void __cdecl SbcWbsCodec::Process(void) __ptr64 */

void __thiscall SbcWbsCodec::Process(SbcWbsCodec *this)

{
  ByteBuffer *this_00;
  undefined2 uVar1;
  bool bVar2;
  __uint64 _Var3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  uchar in_R9B;
  undefined2 *puVar6;
  uchar in_stack_ffffffffffffffe8;
  
  this_00 = (ByteBuffer *)(this + 0x20);
  if (*(int *)(this + 0x10) == 0) {
    bVar2 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::IsFull(this_00);
    if (!bVar2) {
      return;
    }
    bVar2 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::IsEmpty
                      ((ByteBuffer *)(this + 0x68));
    if (!bVar2) {
      return;
    }
    SBC::Encode(*(SBC **)(this + 8),*(short **)(this + 0x18),*(uchar **)(this + 0x58),in_R9B,
                in_stack_ffffffffffffffe8);
  }
  else {
    bVar2 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::IsFull(this_00);
    if (!bVar2) {
      return;
    }
    bVar2 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::IsEmpty
                      ((ByteBuffer *)(this + 0x68));
    if (!bVar2) {
      return;
    }
    SBC::Decode(*(SBC **)(this + 8),*(uchar **)(this + 0x18),*(short **)(this + 0x98));
    puVar6 = *(undefined2 **)(this + 0x98);
    puVar5 = *(undefined2 **)(this + 0x58);
    _Var3 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::TransportFormatter::
            GetTransportPacketStride((TransportFormatter *)(this + 0x60));
    puVar4 = (undefined2 *)(_Var3 + (longlong)puVar5);
    for (; puVar5 < puVar4; puVar5 = puVar5 + 1) {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 2;
      *puVar5 = uVar1;
    }
  }
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ResetInputOffset(this_00);
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::ResetOutputOffset
            ((ByteBuffer *)(this + 0x60));
  return;
}



===== ResetBuffers @ 14002df70 =====

/* public: virtual void __cdecl NullCodec::ResetBuffers(void) __ptr64 */

void __thiscall NullCodec::ResetBuffers(NullCodec *this)

{
  return;
}



===== ResetBuffers @ 14002df80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl SbcWbsCodec::ResetBuffers(void) __ptr64 */

void __thiscall SbcWbsCodec::ResetBuffers(SbcWbsCodec *this)

{
  int iVar1;
  __uint64 _Var2;
  undefined1 in_R9B;
  
  iVar1 = (**(code **)(*(longlong *)this + 8))();
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::SetBuffer
            ((ByteBuffer *)(this + 0x20),*(char **)(this + 0x18),(longlong)iVar1,(bool)in_R9B);
  iVar1 = (**(code **)(*(longlong *)this + 0x10))(this);
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::SetBuffer
            ((ByteBuffer *)(this + 0x60),*(char **)(this + 0x58),(longlong)iVar1,(bool)in_R9B);
  _Var2 = Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::GetUnconsumedBufferLength
                    ((ByteBuffer *)(this + 0x68));
  Microsoft::Bluetooth::Profiles::Hfp::Streaming::ByteBuffer::AdvanceOutputOffset
            ((ByteBuffer *)(this + 0x60),_Var2);
  return;
}



===== GetSize @ 14002dff0 =====

/* public: unsigned __int64 __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::GetSize(void)const __ptr64 */

__uint64 __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::GetSize(RequestContext *this)

{
  __uint64 _Var1;
  
  _Var1 = TransportFormatter::GetTransportPacketStride((TransportFormatter *)(this + 8));
  return _Var1;
}



===== MakeAndAttachToClientRequest @ 14002e00c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::MakeAndAttachToClientRequest(struct
   WDFREQUEST__ * __ptr64,class Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext *
   __ptr64 * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::MakeAndAttachToClientRequest
          (WDFREQUEST__ *param_1,RequestContext **param_2)

{
  int iVar1;
  __uint64 local_res18;
  char *local_res20;
  
  local_res20 = (char *)0x0;
  local_res18 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_1,0,&local_res20,&local_res18);
  if (-1 < iVar1) {
    iVar1 = MakeAndAttachToRequest(param_1,local_res20,local_res18,false,param_2);
  }
  return iVar1;
}



===== MakeAndAttachToNewBrb @ 14002e084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::MakeAndAttachToNewBrb(struct
   WDFQUEUE__ * __ptr64,unsigned __int64,class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext * __ptr64 * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::MakeAndAttachToNewBrb
          (WDFQUEUE__ *param_1,__uint64 param_2,RequestContext **param_3)

{
  long lVar1;
  char *pcVar2;
  WDFREQUEST__ *pWVar3;
  WDFREQUEST__ *local_res18;
  
  *param_3 = (RequestContext *)0x0;
  local_res18 = (WDFREQUEST__ *)0x0;
  pcVar2 = (char *)ExAllocatePool2(0x40,param_2,0x46485442);
  if (pcVar2 == (char *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    lVar1 = AudioQueueClient_CreateTransferBrb(param_1,pcVar2,(int)param_2,(longlong *)&local_res18)
    ;
    pWVar3 = local_res18;
    if ((-1 < lVar1) &&
       (lVar1 = MakeAndAttachToRequest(local_res18,pcVar2,param_2,true,param_3), -1 < lVar1)) {
      pWVar3 = (WDFREQUEST__ *)0x0;
      pcVar2 = (char *)0x0;
      lVar1 = 0;
    }
    if (pWVar3 != (WDFREQUEST__ *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,pWVar3);
    }
    if (pcVar2 != (char *)0x0) {
      ExFreePoolWithTag(pcVar2,0x46485442);
    }
  }
  return lVar1;
}



===== MakeAndAttachToRequest @ 14002e178 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static long __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::MakeAndAttachToRequest(struct
   WDFREQUEST__ * __ptr64,char * __ptr64,unsigned __int64,bool,class
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext * __ptr64 * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext::MakeAndAttachToRequest
          (WDFREQUEST__ *param_1,char *param_2,__uint64 param_3,bool param_4,
          RequestContext **param_5)

{
  RequestContext *pRVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_3c;
  code *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined *local_18;
  
  local_44 = 0;
  local_3c = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0x38;
  *param_5 = (RequestContext *)0x0;
  local_30 = 1;
  local_2c = 1;
  local_18 = PTR__WDF_RequestContext_TYPE_INFO_1400224f8;
  local_38 = WdfCpp::
             ObjectContext<WDFREQUEST__*___ptr64,Microsoft::Bluetooth::Profiles::Hfp::Streaming::RequestContext,0>
             ::EvtObjectContextDestroyThunk;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,&local_48,param_5);
  if (-1 < iVar2) {
    pRVar1 = *param_5;
    if (pRVar1 != (RequestContext *)0x0) {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,pRVar1);
      *(undefined8 *)pRVar1 = uVar3;
      ByteBuffer::ByteBuffer((ByteBuffer *)(pRVar1 + 8),param_2,param_3,param_4);
      *(undefined4 *)(pRVar1 + 0x40) = 0x103;
    }
    *param_5 = pRVar1;
  }
  return 0;
}



===== ContinueReading @ 14002e274 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::ContinueReading(void) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::ContinueReading(ScoReader *this)

{
  bool bVar1;
  int iVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_b61ba7c6c7ba3c52b18b4774502f69e2_Traceguids,this);
  }
  do {
    iVar2 = GetPendingRequestCounter(this);
    if (2 < iVar2) break;
    bVar1 = SendRequest(this);
  } while (bVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_b61ba7c6c7ba3c52b18b4774502f69e2_Traceguids,this);
  }
  return;
}



===== SendRequest @ 14002e318 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: bool __cdecl
   Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::SendRequest(void) __ptr64 */

bool __thiscall
Microsoft::Bluetooth::Profiles::Hfp::Streaming::ScoReader::SendRequest(ScoReader *this)

{
  long lVar1;
  int iVar2;
  RequestContext *pRVar3;
  WDFREQUEST__ *pWVar4;
  RequestContext *local_res8;
  
  pWVar4 = (WDFREQUEST__ *)0x0;
  local_res8 = (RequestContext *)0x0;
  lVar1 = RequestContext::MakeAndAttachToNewBrb
                    (*(WDFQUEUE__ **)this,*(__uint64 *)(this + 0x10),&local_res8);
  if (-1 < lVar1) {
    pWVar4 = *(WDFREQUEST__ **)local_res8;
  }
  iVar2 = 0;
  if (lVar1 < 0) {
    iVar2 = lVar1;
  }
  if (-1 < iVar2) {
    IncrementPendingRequestCounter(this);
    iVar2 = (**(code **)(**(longlong **)(this + 8) + 8))
                      (*(longlong **)(this + 8),*(undefined8 *)this,RequestCompletionRoutine,this,
                       pWVar4);
    if (-1 < iVar2) {
      pRVar3 = RequestContext::GetContextFromObject(pWVar4);
      LOCK();
      iVar2 = *(int *)(pRVar3 + 0x40);
      *(int *)(pRVar3 + 0x40) = *(int *)(pRVar3 + 0x40);
      UNLOCK();
      if (iVar2 == 0x103) {
        return true;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return false;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return false;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return false;
      }
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_b61ba7c6c7ba3c52b18b4774502f69e2_Traceguids,iVar2,(char)this);
      return false;
    }
    DecrementPendingRequestCounter(this);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_b61ba7c6c7ba3c52b18b4774502f69e2_Traceguids,iVar2,(char)this);
    }
  }
  if (pWVar4 != (WDFREQUEST__ *)0x0) {
    ReturnRequestToPool(pWVar4);
  }
  return false;
}



===== SleepstudyHelperInitializeOnce @ 14002e460 =====

undefined8 SleepstudyHelperInitializeOnce(void)

{
  int iVar1;
  size_t _Size;
  undefined8 local_res20;
  int *local_18 [2];
  
  _Size = 0x110;
  local_18[0] = (int *)0x0;
  memset(&SleepstudyHelperRoutineBlock,0,0x110);
  local_res20 = 0x3f;
  iVar1 = ZwPowerInformation(0x57,&local_res20,8,local_18,8);
  if (iVar1 != -0x3fffff45) {
    if (iVar1 < 0) {
      return 0;
    }
    if (*local_18[0] == 1) {
      _Size = 0x108;
    }
    memcpy(&SleepstudyHelperRoutineBlock,local_18[0],_Size);
  }
  return 1;
}



===== SleepstudyHelper_GetPdoFriendlyName @ 14002e4f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SleepstudyHelper_GetPdoFriendlyName(undefined8 param_1,ushort *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if (DAT_140022a50 == (code *)0x0) {
    uVar3 = 0xc00000bb;
  }
  else {
    uVar1 = (*DAT_140022a50)();
    uVar3 = (ulonglong)uVar1;
  }
  uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 == 0) && ((int)uVar3 == -0x3fffff45)) {
    if (param_2 == (ushort *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      uVar3 = RtlUnicodeStringCopy(param_2);
      uVar3 = uVar3 & 0xffffffff;
    }
  }
  return uVar3;
}



===== SleepstudyHelper_Initialize @ 14002e55c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_Initialize(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  iVar1 = RtlRunOnceExecuteOnce
                    (&SleepstudyHelperInitializeRunOnce,SleepstudyHelperInitializeOnce,0,0);
  uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if ((iVar1 < 0) || (DAT_1400229e0 == (code *)0x0)) {
      *param_1 = &SleepstudyHelperUnsupportedHandle;
      return 0;
    }
  }
  else {
    if (iVar1 < 0) {
      return iVar1;
    }
    if (DAT_1400229e0 == (code *)0x0) {
      return -0x3fffff45;
    }
  }
  iVar1 = (*DAT_1400229e0)(param_1,param_2);
  return iVar1;
}



===== SleepstudyHelper_RegisterComponentEx @ 14002e5f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SleepstudyHelper_RegisterComponentEx
          (undefined *param_1,undefined4 *param_2,undefined4 *param_3,undefined8 param_4,
          undefined8 *param_5)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uVar1 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_140022a10 == (code *)0x0) {
        uVar2 = 0xc00000bb;
      }
      else {
        local_28 = *param_3;
        uStack_24 = param_3[1];
        uStack_20 = param_3[2];
        uStack_1c = param_3[3];
        local_38 = *param_2;
        uStack_34 = param_2[1];
        uStack_30 = param_2[2];
        uStack_2c = param_2[3];
        uVar2 = (*DAT_140022a10)(param_1,&local_38,&local_28,param_4,param_5);
      }
      if ((int)uVar2 != -0x3fffff45) {
        return uVar2;
      }
    }
    *param_5 = &SleepstudyHelperUnsupportedHandle;
    uVar2 = 0;
  }
  else if (DAT_140022a10 == (code *)0x0) {
    uVar2 = 0xc00000bb;
  }
  else {
    local_38 = *param_3;
    uStack_34 = param_3[1];
    uStack_30 = param_3[2];
    uStack_2c = param_3[3];
    local_28 = *param_2;
    uStack_24 = param_2[1];
    uStack_20 = param_2[2];
    uStack_1c = param_2[3];
    uVar2 = (*DAT_140022a10)(param_1,&local_28,&local_38,param_4,param_5);
  }
  return uVar2;
}



===== BthGetDeviceFingerprint @ 14002e6f4 =====

int BthGetDeviceFingerprint(longlong param_1,undefined4 *param_2,longlong param_3)

{
  PUCHAR _Str;
  undefined8 uVar1;
  int iVar2;
  ULONG UVar3;
  size_t sVar4;
  undefined8 *puVar5;
  undefined8 *local_res10;
  longlong local_res18;
  longlong local_res20;
  
  puVar5 = (undefined8 *)0x0;
  local_res20 = 0;
  local_res10 = (undefined8 *)0x0;
  if ((param_2 == (undefined4 *)0x0) || (param_1 == 0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    local_res18 = param_3;
    if ((param_3 != 0) || (iVar2 = GetBthportDeviceObject(&local_res20,&local_res18), -1 < iVar2)) {
      iVar2 = GetDeviceFingerprintInfo(param_1,(longlong *)&local_res10,local_res18);
      puVar5 = local_res10;
      if (-1 < iVar2) {
        if (local_res10 == (undefined8 *)0x0) {
          iVar2 = -0x3fffffff;
        }
        else {
          memset(param_2,0,0x570);
          _Str = (PUCHAR)((longlong)puVar5 + 0x21);
          if (_Str == (PUCHAR)0x0) {
            UVar3 = 0;
          }
          else {
            sVar4 = strnlen((char *)_Str,0xf8);
            UVar3 = (ULONG)sVar4;
          }
          BtGenerateDWORD64Hash(_Str,UVar3,(undefined8 *)(param_2 + 0x46));
          *param_2 = 3;
          param_2[1] = (uint)*(byte *)((longlong)puVar5 + 0xc);
          param_2[2] = (uint)*(ushort *)(puVar5 + 1);
          param_2[3] = (uint)*(ushort *)((longlong)puVar5 + 10);
          *(undefined8 *)(param_2 + 4) = *puVar5;
          param_2[6] = *(undefined4 *)((longlong)puVar5 + 0xd);
          param_2[7] = *(undefined4 *)((longlong)puVar5 + 0x1d);
          *(undefined2 *)(param_2 + 0x14c) = *(undefined2 *)((longlong)puVar5 + 0x345);
          param_2[0x14d] = (uint)*(ushort *)((longlong)puVar5 + 0x347);
          param_2[0x14e] = (uint)*(ushort *)((longlong)puVar5 + 0x349);
          param_2[0x14f] = (uint)*(ushort *)((longlong)puVar5 + 0x34b);
          param_2[0x150] = (uint)*(byte *)((longlong)puVar5 + 0x365);
          param_2[0x151] = (uint)*(ushort *)((longlong)puVar5 + 0x366);
          param_2[0x152] = (uint)*(ushort *)((longlong)puVar5 + 0x23b);
          param_2[0x153] = (uint)*(byte *)(puVar5 + 0x6d);
          *(undefined8 *)(param_2 + 0x154) = *(undefined8 *)((longlong)puVar5 + 0x379);
          *(undefined8 *)(param_2 + 0x158) = *(undefined8 *)((longlong)puVar5 + 0x355);
          *(undefined1 *)(param_2 + 0x15a) = *(undefined1 *)((longlong)puVar5 + 0x35d);
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x29);
          *(undefined8 *)(param_2 + 8) = *(undefined8 *)_Str;
          *(undefined8 *)(param_2 + 10) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x39);
          *(undefined8 *)(param_2 + 0xc) = *(undefined8 *)((longlong)puVar5 + 0x31);
          *(undefined8 *)(param_2 + 0xe) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x49);
          *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)((longlong)puVar5 + 0x41);
          *(undefined8 *)(param_2 + 0x12) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x59);
          *(undefined8 *)(param_2 + 0x14) = *(undefined8 *)((longlong)puVar5 + 0x51);
          *(undefined8 *)(param_2 + 0x16) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x69);
          *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)((longlong)puVar5 + 0x61);
          *(undefined8 *)(param_2 + 0x1a) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x79);
          *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)((longlong)puVar5 + 0x71);
          *(undefined8 *)(param_2 + 0x1e) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x89);
          *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)((longlong)puVar5 + 0x81);
          *(undefined8 *)(param_2 + 0x22) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x99);
          *(undefined8 *)(param_2 + 0x24) = *(undefined8 *)((longlong)puVar5 + 0x91);
          *(undefined8 *)(param_2 + 0x26) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0xa9);
          *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)((longlong)puVar5 + 0xa1);
          *(undefined8 *)(param_2 + 0x2a) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0xb9);
          *(undefined8 *)(param_2 + 0x2c) = *(undefined8 *)((longlong)puVar5 + 0xb1);
          *(undefined8 *)(param_2 + 0x2e) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0xc9);
          *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)((longlong)puVar5 + 0xc1);
          *(undefined8 *)(param_2 + 0x32) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0xd9);
          *(undefined8 *)(param_2 + 0x34) = *(undefined8 *)((longlong)puVar5 + 0xd1);
          *(undefined8 *)(param_2 + 0x36) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0xe9);
          *(undefined8 *)(param_2 + 0x38) = *(undefined8 *)((longlong)puVar5 + 0xe1);
          *(undefined8 *)(param_2 + 0x3a) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0xf9);
          *(undefined8 *)(param_2 + 0x3c) = *(undefined8 *)((longlong)puVar5 + 0xf1);
          *(undefined8 *)(param_2 + 0x3e) = uVar1;
          uVar1 = *(undefined8 *)((longlong)puVar5 + 0x109);
          *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)((longlong)puVar5 + 0x101);
          *(undefined8 *)(param_2 + 0x42) = uVar1;
          *(undefined8 *)(param_2 + 0x44) = *(undefined8 *)((longlong)puVar5 + 0x111);
          BtGenerateDWORD64Hash
                    ((PUCHAR)((longlong)puVar5 + 0x369),0x10,(undefined8 *)(param_2 + 0x156));
        }
      }
    }
    if (local_res20 != 0) {
      ObfDereferenceObject();
      local_res20 = 0;
    }
    if (puVar5 != (undefined8 *)0x0) {
      ExFreePoolWithTag(puVar5,0x43445442);
    }
  }
  return iVar2;
}



===== BthQueryDeviceCompatFlags @ 14002e96c =====

undefined8 BthQueryDeviceCompatFlags(longlong param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined8 local_res8;
  longlong local_res18 [2];
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res18[0] = 0;
  local_res8 = 0;
  if (param_1 != 0) {
    iVar1 = GetBthportDeviceObject(local_res18,local_18);
    if (-1 < iVar1) {
      pwVar2 = (wchar_t *)ExAllocatePool2(0x100,300,0x43445442);
      if (pwVar2 != (wchar_t *)0x0) {
        iVar1 = GetDeviceFingerprintString(param_1,pwVar2,0x14001eb40,local_18[0]);
        if (-1 < iVar1) {
          KseQueryDeviceFlags(pwVar2,L"BthDeviceHfp",&local_res8);
        }
        ExFreePoolWithTag(pwVar2,0x43445442);
      }
    }
    if (local_res18[0] != 0) {
      ObfDereferenceObject();
    }
  }
  return local_res8;
}



===== GetBthportDeviceObject @ 14002ea44 =====

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



===== GetDeviceFingerprintInfo @ 14002eaec =====

int GetDeviceFingerprintInfo(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  *param_2 = 0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_res8 = param_1;
  lVar2 = ExAllocatePool2(0x40,0x38a,0x43445442);
  if (lVar2 == 0) {
    return -0x3fffff66;
  }
  KeInitializeEvent(&local_38,0,0);
  lVar3 = IoBuildDeviceIoControlRequest
                    (0x411144,param_3,&local_res8,8,lVar2,0x38a,0,&local_38,&local_48);
  if (lVar3 != 0) {
    iVar1 = IofCallDriver(param_3,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
    }
    else if (iVar1 < 0) goto LAB_14002ebab;
    iVar1 = (int)local_48;
    if ((int)local_48 < 0) goto LAB_14002ebab;
    if (*(int *)(lVar2 + 0x381) == 0) {
LAB_14002ed1d:
      *param_2 = lVar2;
      return (int)local_48;
    }
    KeClearEvent(&local_38);
    iVar1 = *(int *)(lVar2 + 0x381) + 0x389;
    ExFreePoolWithTag(lVar2,0x43445442);
    lVar2 = ExAllocatePool2(0x40,iVar1,0x43445442);
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
    lVar3 = IoBuildDeviceIoControlRequest
                      (0x411144,param_3,&local_res8,8,lVar2,iVar1,0,&local_38,&local_48);
    if (lVar3 != 0) {
      iVar1 = IofCallDriver(param_3,lVar3);
      if (iVar1 == 0x103) {
        KeWaitForSingleObject(&local_38,0,0,0,0);
      }
      else if (iVar1 < 0) goto LAB_14002ebab;
      iVar1 = (int)local_48;
      if ((int)local_48 < 0) goto LAB_14002ebab;
      goto LAB_14002ed1d;
    }
  }
  iVar1 = -0x3fffff66;
LAB_14002ebab:
  ExFreePoolWithTag(lVar2,0x43445442);
  return iVar1;
}



===== GetDeviceFingerprintString @ 14002ed2c =====

int GetDeviceFingerprintString(longlong param_1,wchar_t *param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  longlong lVar5;
  longlong lVar4;
  
  if ((((param_1 == 0) || (param_2 == (wchar_t *)0x0)) || (param_3 == 0)) || (param_4 == 0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x570,0x43445442);
    if (puVar2 == (undefined4 *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = BthGetDeviceFingerprint(param_1,puVar2,param_4);
      if (-1 < iVar1) {
        lVar4 = -1;
        do {
          lVar5 = lVar4;
          lVar4 = lVar5 + 1;
        } while (*(short *)(param_3 + lVar4 * 2) != 0);
        uVar3 = RtlStringCchPrintfW(param_2,lVar5 + 0x8b,
                                    L"%s:%02X;%04X;%04X;%016I64X;%06X;%016I64X;%016I64X;%04X;%04X;%04X;%02X;%04X;%04X;%02X;%016I64X;%016I64X;"
                                    ,param_3);
        iVar1 = (int)uVar3;
      }
      ExFreePool(puVar2);
    }
  }
  return iVar1;
}



===== __security_init_cookie @ 14002f008 =====

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



===== DriverEntry @ 14002f03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(_DRIVER_OBJECT *param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  _tlgProvider_t *p_Var3;
  _GUID *p_Var4;
  _GUID *p_Var5;
  undefined8 local_res18;
  HfpRoleConfigurationSet *local_res20;
  undefined8 local_b8;
  code *pcStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  wchar_t *local_98;
  undefined8 local_90;
  undefined8 local_88;
  code *pcStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined *local_20;
  
  local_58 = 0;
  local_b8 = 0;
  pcStack_b0 = (code *)0x0;
  local_res18 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_88 = 0;
  pcStack_80 = (code *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  iVar2 = wil_InitializeFeatureStaging();
  if (-1 < iVar2) {
    _WPP_MAIN_CB = 0;
    DAT_140022638 = &WPP_ThisDir_CTLGUID_CtlGuid;
    DAT_140022640 = 0;
    _DAT_140022650 = 0;
    _DAT_140022658 = 1;
    _DAT_140022670 = 0;
    _DAT_140022678 = 0;
    WppLoadTracingSupport();
    _DAT_140022650 = 0;
    WppInitKm(param_1,param_2);
    InitializeTelemetryAssertsKMByDriverObject(param_1);
    InitializeGlobalContext(param_1);
    local_b8 = 0x20;
    pcStack_b0 = Bus_EvtDeviceAdd;
    pcStack_80 = Bus_EvtDriverCleanup;
    local_a8 = 0;
    uStack_a0 = 0x4648544200000000;
    local_88 = CONCAT44(local_88._4_4_,0x38);
    uStack_70 = 0x100000001;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                      (WdfDriverGlobals,param_1,param_2,&local_88,&local_b8,&local_res18);
    if (iVar2 < 0) {
      UninitializeTelemetryAssertsKM();
      WppCleanupKm(param_1);
      wil_UninitializeFeatureStaging();
    }
  }
  local_res20 = (HfpRoleConfigurationSet *)0x0;
  if (-1 < iVar2) {
    p_Var5 = (_GUID *)&local_res20;
    p_Var4 = (_GUID *)&local_50;
    local_40 = 0;
    local_20 = PTR__WDF_HfpRoleConfigurationSet_TYPE_INFO_140022050;
    uStack_48 = 0;
    local_50 = 0x38;
    local_30 = 0;
    uStack_28 = 0;
    uStack_38 = 0x100000001;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_res18);
    if (-1 < iVar2) {
      iVar2 = GetRoleConfigurationState(local_res20);
      if (-1 < iVar2) {
        SleepstudyHelper_Initialize(&DAT_140022628,param_1);
        TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140022000);
        if (5 < DAT_140022000) {
          p_Var3 = (_tlgProvider_t *)&DAT_140022000;
          cVar1 = _tlgKeywordOn(0x140022000,0x400000000000);
          if (cVar1 != '\0') {
            local_90 = 0x2000800;
            local_98 = L"BthHfEnum.sys";
            _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
            ::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>_>
                      (p_Var3,&DAT_14001ed4f,p_Var4,p_Var5,(_tlgWrapperByVal<8> *)&local_90,
                       (_tlgWrapSz<unsigned_short> *)&local_98);
          }
        }
      }
    }
  }
  return iVar2;
}



===== wil_InitializeFeatureStaging @ 14002f288 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &Feature_53100197__private_descriptor;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
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
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002f378 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_53100197__private_descriptor;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


