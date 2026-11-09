
===== Write<_tlgWrapSz<unsigned_short>_> @ 1c0001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short> >(struct _tlgProvider_t const * __ptr64,void
   const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapSz<unsigned_short>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [4];
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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,param_2,0,0,3,local_48);
  return lVar1;
}



===== Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_> @ 1c000109c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<4> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<4>
   const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5,_tlgWrapperByVal<4> *param_6)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,param_2,0,0,4,local_58);
  return lVar1;
}



===== Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_> @ 1c0001148 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<unsigned short> >(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5,_tlgWrapperByVal<4> *param_6,
          _tlgWrapperByVal<4> *param_7,_tlgWrapSz<unsigned_short> *param_8)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [4];
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar3 = -1;
  local_50 = 2;
  local_28 = *(wchar_t **)param_8;
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
  local_38 = param_7;
  local_48 = param_6;
  local_1c = 0;
  local_30 = 4;
  local_58 = *(wchar_t **)param_5;
  local_40 = 4;
  if (local_58 == (wchar_t *)0x0) {
    local_58 = L"";
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_58[lVar3] != L'\0');
    local_50 = (int)lVar3 * 2 + 2;
  }
  local_4c = 0;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,param_2,0,0,6,local_78);
  return lVar1;
}



===== Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_> @ 1c0001240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<8> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<8>
   const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5,_tlgWrapperByVal<8> *param_6)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  _tlgWrapperByVal<8> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = param_6;
  local_20 = 8;
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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,param_2,0,0,4,local_58);
  return lVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1c00012f0 =====

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



===== Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_> @ 1c0001394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<8> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<4>
   const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<unsigned short>
   const & __ptr64,struct _tlgWrapperByVal<8> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5,_tlgWrapperByVal<4> *param_6,
          _tlgWrapperByVal<4> *param_7,_tlgWrapSz<unsigned_short> *param_8,
          _tlgWrapperByVal<8> *param_9)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [4];
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  _tlgWrapperByVal<8> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_28 = param_9;
  lVar3 = -1;
  local_20 = 8;
  local_60 = 2;
  local_38 = *(wchar_t **)param_8;
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
  local_48 = param_7;
  local_58 = param_6;
  local_2c = 0;
  local_40 = 4;
  local_68 = *(wchar_t **)param_5;
  local_50 = 4;
  if (local_68 == (wchar_t *)0x0) {
    local_68 = L"";
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_68[lVar3] != L'\0');
    local_60 = (int)lVar3 * 2 + 2;
  }
  local_5c = 0;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,param_2,0,0,7,local_88);
  return lVar1;
}



===== Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>_> @ 1c0001498 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByVal<1> >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID
   const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapSz<unsigned short> const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5,_tlgWrapperByVal<8> *param_6,
          _tlgWrapperByVal<1> *param_7)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [4];
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  _tlgWrapperByVal<8> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<1> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_28 = param_7;
  local_38 = param_6;
  local_20 = 1;
  local_30 = 8;
  local_48 = *(wchar_t **)param_5;
  if (local_48 == (wchar_t *)0x0) {
    local_48 = L"";
    local_40 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_48[lVar2] != L'\0');
    local_40 = (int)lVar2 * 2 + 2;
  }
  local_3c = 0;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,param_2,0,0,5,local_68);
  return lVar1;
}



===== __report_gsfailure @ 1c0001570 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== EvtAdapterCreateRxQueue @ 1c0001580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtAdapterCreateRxQueue(struct NETADAPTER__ * __ptr64,struct _NETRXQUEUE_INIT *
   __ptr64) */

long __cdecl EvtAdapterCreateRxQueue(NETADAPTER__ *param_1,_NETRXQUEUE_INIT *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  _RT_ADAPTER *p_Var4;
  longlong lVar5;
  _tlgWrapSz<unsigned_short> *p_Var6;
  _tlgProvider_t *p_Var7;
  _GUID *in_R8;
  _GUID *p_Var8;
  _GUID *in_R9;
  _GUID *p_Var9;
  NETADAPTER__ *local_res18;
  wchar_t *local_res20;
  _tlgWrapSz<unsigned_short> *p_Var10;
  NETPACKETQUEUE__ *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  wchar_t *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  wchar_t *local_a8;
  wchar_t *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_54;
  code *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined *local_30;
  
  if (5 < DAT_1c000d1e0) {
    local_res20 = L"EvtAdapterCreateRxQueue";
    local_res18 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bebd,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<8> *)&local_res18);
  }
  p_Var4 = (_RT_ADAPTER *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  local_5c = 0;
  local_54 = 0;
  local_94 = 0;
  local_68 = 0;
  local_50 = EvtRxQueueDestroy;
  local_80 = EvtRxQueueAdvance;
  local_60 = 0x38;
  local_78 = EvtRxQueueSetNotificationEnabled;
  local_70 = EvtRxQueueCancel;
  local_90 = EvtRxQueueStart;
  local_88 = EvtRxQueueStop;
  local_30 = PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040;
  local_98 = 0x38;
  local_40 = 0;
  uStack_38 = 0;
  local_48 = 1;
  local_44 = 1;
  uVar2 = (*DAT_1c000d7c0)(NetDriverGlobals,param_2);
  local_c8 = (NETPACKETQUEUE__ *)0x0;
  p_Var9 = (_GUID *)&local_98;
  p_Var8 = (_GUID *)&local_60;
  p_Var7 = NetDriverGlobals;
  iVar3 = (*DAT_1c000d7b0)(NetDriverGlobals,param_2,p_Var8,p_Var9,&local_c8);
  if (iVar3 < 0) {
    if (DAT_1c000d1e0 < 3) goto LAB_1c00018a0;
    local_res20 = (wchar_t *)CONCAT44(local_res20._4_4_,0xed);
    local_a8 = L"NetRxQueueCreate(rxQueueInit, &rxAttributes, &rxConfig, &rxQueue)";
    p_Var10 = (_tlgWrapSz<unsigned_short> *)&local_a8;
    local_a0 = L"EvtAdapterCreateRxQueue";
    p_Var6 = (_tlgWrapSz<unsigned_short> *)&local_a0;
  }
  else {
    lVar5 = (**(code **)(WdfFunctions_01021 + 0x650))
                      (WdfDriverGlobals,local_c8,PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040);
    pcVar1 = DAT_1c000d7d0;
    p_Var7 = NetDriverGlobals;
    local_bc = 0;
    local_b0 = 1;
    local_b8 = L"ms_packet_checksum";
    local_c0 = 0x18;
    local_ac = 1;
    *(undefined4 *)(lVar5 + 0xd0) = uVar2;
    (*pcVar1)(p_Var7,local_c8,&local_c0,lVar5 + 0x30);
    local_bc = 0;
    local_b8 = L"ms_fragment_virtualaddress";
    local_c0 = 0x18;
    local_b0 = 1;
    local_ac = 2;
    (*DAT_1c000d7d0)(NetDriverGlobals,local_c8,&local_c0,lVar5 + 0x58);
    local_bc = 0;
    local_b8 = L"ms_fragment_logicaladdress";
    local_c0 = 0x18;
    local_b0 = 1;
    local_ac = 2;
    (*DAT_1c000d7d0)(NetDriverGlobals,local_c8,&local_c0,lVar5 + 0x80);
    p_Var9 = (_GUID *)(lVar5 + 0xa8);
    local_bc = 0;
    p_Var8 = (_GUID *)&local_c0;
    local_b8 = L"ms_packet_hash";
    local_c0 = 0x18;
    local_b0 = 1;
    local_ac = 1;
    (*DAT_1c000d7d0)(NetDriverGlobals,local_c8);
    p_Var7 = (_tlgProvider_t *)local_c8;
    iVar3 = RtRxQueueInitialize(local_c8,p_Var4);
    if ((-1 < iVar3) || (DAT_1c000d1e0 < 3)) goto LAB_1c00018a0;
    local_res20 = (wchar_t *)CONCAT44(local_res20._4_4_,0x114);
    local_a0 = L"RtRxQueueInitialize(rxQueue, adapter)";
    p_Var10 = (_tlgWrapSz<unsigned_short> *)&local_a0;
    local_a8 = L"EvtAdapterCreateRxQueue";
    p_Var6 = (_tlgWrapSz<unsigned_short> *)&local_a8;
  }
  local_res18 = (NETADAPTER__ *)CONCAT44(local_res18._4_4_,iVar3);
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
            (p_Var7,&DAT_1c000be46,p_Var8,p_Var9,p_Var6,(_tlgWrapperByVal<4> *)&local_res20,
             (_tlgWrapperByVal<4> *)&local_res18,p_Var10);
LAB_1c00018a0:
  if (5 < DAT_1c000d1e0) {
    local_res18 = (NETADAPTER__ *)CONCAT44(local_res18._4_4_,iVar3);
    local_res20 = L"EvtAdapterCreateRxQueue";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var7,&DAT_1c000be88,p_Var8,p_Var9,(_tlgWrapSz<unsigned_short> *)&local_res20,
               (_tlgWrapperByVal<4> *)&local_res18);
  }
  return iVar3;
}



===== EvtAdapterCreateTxQueue @ 1c0001900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtAdapterCreateTxQueue(struct NETADAPTER__ * __ptr64,struct _NETTXQUEUE_INIT *
   __ptr64) */

long __cdecl EvtAdapterCreateTxQueue(NETADAPTER__ *param_1,_NETTXQUEUE_INIT *param_2)

{
  undefined4 uVar1;
  int iVar2;
  _RT_ADAPTER *p_Var3;
  longlong lVar4;
  _tlgWrapSz<unsigned_short> *p_Var5;
  _tlgProvider_t *p_Var6;
  _GUID *in_R8;
  _GUID *p_Var7;
  _GUID *in_R9;
  _GUID *p_Var8;
  NETADAPTER__ *local_res18;
  wchar_t *local_res20;
  _tlgWrapSz<unsigned_short> *p_Var9;
  undefined4 local_c8;
  undefined4 local_c4;
  wchar_t *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  NETPACKETQUEUE__ *local_b0;
  wchar_t *local_a8;
  wchar_t *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined4 local_54;
  code *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined *local_30;
  
  if (5 < DAT_1c000d1e0) {
    local_res20 = L"EvtAdapterCreateTxQueue";
    local_res18 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bebd,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<8> *)&local_res18);
  }
  p_Var3 = (_RT_ADAPTER *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  local_5c = 0;
  local_54 = 0;
  local_94 = 0;
  local_68 = 0;
  local_50 = EvtTxQueueDestroy;
  local_80 = EvtTxQueueAdvance;
  local_60 = 0x38;
  local_78 = EvtTxQueueSetNotificationEnabled;
  local_70 = EvtTxQueueCancel;
  local_90 = EvtTxQueueStart;
  local_88 = EvtTxQueueStop;
  local_30 = PTR__WDF_RT_TXQUEUE_TYPE_INFO_1c000d090;
  local_98 = 0x38;
  local_40 = 0;
  uStack_38 = 0;
  local_48 = 1;
  local_44 = 1;
  uVar1 = (*DAT_1c000d7e8)(NetDriverGlobals,param_2);
  local_b0 = (NETPACKETQUEUE__ *)0x0;
  p_Var8 = (_GUID *)&local_98;
  p_Var7 = (_GUID *)&local_60;
  p_Var6 = NetDriverGlobals;
  iVar2 = (*DAT_1c000d7d8)(NetDriverGlobals,param_2,p_Var7,p_Var8,&local_b0);
  if (iVar2 < 0) {
    if (DAT_1c000d1e0 < 3) goto LAB_1c0001c63;
    local_res20 = (wchar_t *)CONCAT44(local_res20._4_4_,0x97);
    local_a8 = L"NetTxQueueCreate( txQueueInit, &txAttributes, &txConfig, &txQueue)";
    p_Var9 = (_tlgWrapSz<unsigned_short> *)&local_a8;
    local_a0 = L"EvtAdapterCreateTxQueue";
    p_Var5 = (_tlgWrapSz<unsigned_short> *)&local_a0;
  }
  else {
    lVar4 = (**(code **)(WdfFunctions_01021 + 0x650))
                      (WdfDriverGlobals,local_b0,PTR__WDF_RT_TXQUEUE_TYPE_INFO_1c000d090);
    p_Var6 = NetDriverGlobals;
    *(undefined4 *)(lVar4 + 0x110) = uVar1;
    *(undefined1 *)(lVar4 + 0x114) = 0x40;
    local_c4 = 0;
    local_c0 = L"ms_packet_checksum";
    local_c8 = 0x18;
    local_b8 = 1;
    local_b4 = 1;
    (*DAT_1c000d7f8)(p_Var6,local_b0,&local_c8,lVar4 + 0x48);
    local_c4 = 0;
    local_c0 = L"ms_packet_gso";
    local_c8 = 0x18;
    local_b8 = 1;
    local_b4 = 1;
    (*DAT_1c000d7f8)(NetDriverGlobals,local_b0,&local_c8,lVar4 + 0x70);
    local_c4 = 0;
    local_c0 = L"ms_packet_ieee8021q";
    local_c8 = 0x18;
    local_b8 = 1;
    local_b4 = 1;
    (*DAT_1c000d7f8)(NetDriverGlobals,local_b0,&local_c8,lVar4 + 0xe8);
    local_c4 = 0;
    local_c0 = L"ms_fragment_virtualaddress";
    local_c8 = 0x18;
    local_b8 = 1;
    local_b4 = 2;
    (*DAT_1c000d7f8)(NetDriverGlobals,local_b0,&local_c8,lVar4 + 0x98);
    p_Var8 = (_GUID *)(lVar4 + 0xc0);
    local_c4 = 0;
    p_Var7 = (_GUID *)&local_c8;
    local_c0 = L"ms_fragment_logicaladdress";
    local_c8 = 0x18;
    local_b8 = 1;
    local_b4 = 2;
    (*DAT_1c000d7f8)(NetDriverGlobals,local_b0);
    p_Var6 = (_tlgProvider_t *)local_b0;
    iVar2 = RtTxQueueInitialize(local_b0,p_Var3);
    if ((-1 < iVar2) || (DAT_1c000d1e0 < 3)) goto LAB_1c0001c63;
    local_res20 = (wchar_t *)CONCAT44(local_res20._4_4_,199);
    local_a0 = L"RtTxQueueInitialize(txQueue, adapter)";
    p_Var9 = (_tlgWrapSz<unsigned_short> *)&local_a0;
    local_a8 = L"EvtAdapterCreateTxQueue";
    p_Var5 = (_tlgWrapSz<unsigned_short> *)&local_a8;
  }
  local_res18 = (NETADAPTER__ *)CONCAT44(local_res18._4_4_,iVar2);
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
            (p_Var6,&DAT_1c000be46,p_Var7,p_Var8,p_Var5,(_tlgWrapperByVal<4> *)&local_res20,
             (_tlgWrapperByVal<4> *)&local_res18,p_Var9);
LAB_1c0001c63:
  if (5 < DAT_1c000d1e0) {
    local_res18 = (NETADAPTER__ *)CONCAT44(local_res18._4_4_,iVar2);
    local_res20 = L"EvtAdapterCreateTxQueue";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var6,&DAT_1c000be88,p_Var7,p_Var8,(_tlgWrapSz<unsigned_short> *)&local_res20,
               (_tlgWrapperByVal<4> *)&local_res18);
  }
  return iVar2;
}



===== EvtAdapterOffloadSetGso @ 1c0001cc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtAdapterOffloadSetGso(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  char cVar2;
  _RT_ADAPTER *p_Var3;
  
  p_Var3 = (_RT_ADAPTER *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  cVar2 = (*DAT_1c000d8f0)(NetDriverGlobals,param_2);
  pcVar1 = DAT_1c000d8f8;
  p_Var3[0x5b8] = (_RT_ADAPTER)(cVar2 != '\0');
  cVar2 = (*pcVar1)(NetDriverGlobals,param_2);
  p_Var3[0x5b9] = (_RT_ADAPTER)(cVar2 != '\0');
  RtAdapterUpdateHardwareChecksum(p_Var3);
  return;
}



===== EvtAdapterOffloadSetRxChecksum @ 1c0001d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtAdapterOffloadSetRxChecksum(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  _RT_ADAPTER _Var2;
  _RT_ADAPTER *p_Var3;
  
  p_Var3 = (_RT_ADAPTER *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  _Var2 = (_RT_ADAPTER)(*DAT_1c000d8d0)(NetDriverGlobals,param_2);
  uVar1 = NetDriverGlobals;
  p_Var3[0x56d] = _Var2;
  _Var2 = (_RT_ADAPTER)(*DAT_1c000d8d8)(uVar1,param_2);
  uVar1 = NetDriverGlobals;
  p_Var3[0x56e] = _Var2;
  _Var2 = (_RT_ADAPTER)(*DAT_1c000d8e0)(uVar1,param_2);
  p_Var3[0x56f] = _Var2;
  RtAdapterUpdateHardwareChecksum(p_Var3);
  return;
}



===== EvtAdapterOffloadSetTxChecksum @ 1c0001e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtAdapterOffloadSetTxChecksum(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  _RT_ADAPTER _Var2;
  _RT_ADAPTER *p_Var3;
  
  p_Var3 = (_RT_ADAPTER *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  _Var2 = (_RT_ADAPTER)(*DAT_1c000d8b0)(NetDriverGlobals,param_2);
  uVar1 = NetDriverGlobals;
  p_Var3[0x56a] = _Var2;
  _Var2 = (_RT_ADAPTER)(*DAT_1c000d8b8)(uVar1,param_2);
  uVar1 = NetDriverGlobals;
  p_Var3[0x56b] = _Var2;
  _Var2 = (_RT_ADAPTER)(*DAT_1c000d8c0)(uVar1,param_2);
  p_Var3[0x56c] = _Var2;
  RtAdapterUpdateHardwareChecksum(p_Var3);
  return;
}



===== EvtAdapterReceiveScalingDisable @ 1c0001eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtAdapterReceiveScalingDisable(undefined8 param_1)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = (**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  cVar1 = GigaMacWrite4(lVar2,0xb8,0);
  if (cVar1 == '\0') {
    (**(code **)(WdfFunctions_01021 + 0x2b8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 8),1);
  }
  *(undefined1 *)(lVar2 + 0x593) = 0;
  return;
}



===== EvtAdapterReceiveScalingEnable @ 1c0001f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
EvtAdapterReceiveScalingEnable
          (_tlgProvider_t *param_1,undefined8 param_2,_GUID *param_3,_GUID *param_4)

{
  char cVar1;
  _tlgProvider_t *p_Var2;
  _tlgProvider_t *p_Var3;
  undefined4 uVar4;
  uint uVar5;
  _GUID *p_Var6;
  undefined4 local_res18 [2];
  _tlgProvider_t *local_res20;
  wchar_t *local_28;
  wchar_t *local_20;
  
  if (5 < DAT_1c000d1e0) {
    local_28 = L"EvtAdapterReceiveScalingEnable";
    local_res20 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              (param_1,&DAT_1c000bebd,param_3,param_4,(_tlgWrapSz<unsigned_short> *)&local_28,
               (_tlgWrapperByVal<8> *)&local_res20);
  }
  p_Var2 = (_tlgProvider_t *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  p_Var6 = (_GUID *)0x10700;
  if ((((ulonglong)param_3 & 1) != 0) &&
     (p_Var6 = (_GUID *)0x10702, ((ulonglong)param_3 & 0x10) != 0)) {
    p_Var6 = (_GUID *)0x10703;
  }
  if (((ulonglong)param_3 & 4) != 0) {
    uVar5 = (uint)p_Var6;
    p_Var6 = (_GUID *)(ulonglong)(uVar5 | 8);
    if (((ulonglong)param_3 & 0x10) != 0) {
      p_Var6 = (_GUID *)(ulonglong)(uVar5 | 0xc);
    }
  }
  p_Var3 = p_Var2;
  cVar1 = GigaMacWrite4((longlong)p_Var2,0xb8,(int)p_Var6);
  uVar4 = 0;
  if (cVar1 == '\0') {
    p_Var6 = (_GUID *)0x1;
    p_Var3 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01021 + 0x2b8))(WdfDriverGlobals,*(undefined8 *)(p_Var2 + 8));
    uVar4 = 0xc0000001;
    if (2 < DAT_1c000d1e0) {
      local_res18[0] = 0xc0000001;
      local_28 = L"RtReceiveScalingEnable(adapter, protocolType)";
      local_res20 = (_tlgProvider_t *)CONCAT44(local_res20._4_4_,0x166);
      local_20 = L"EvtAdapterReceiveScalingEnable";
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
                (p_Var3,&DAT_1c000be46,p_Var6,param_4,(_tlgWrapSz<unsigned_short> *)&local_20,
                 (_tlgWrapperByVal<4> *)&local_res20,(_tlgWrapperByVal<4> *)local_res18,
                 (_tlgWrapSz<unsigned_short> *)&local_28);
    }
  }
  else {
    p_Var2[0x593] = (_tlgProvider_t)0x1;
  }
  if (5 < DAT_1c000d1e0) {
    local_res20 = (_tlgProvider_t *)0x1c000a570;
    local_res18[0] = uVar4;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var3,&DAT_1c000be88,p_Var6,param_4,(_tlgWrapSz<unsigned_short> *)&local_res20,
               (_tlgWrapperByVal<4> *)local_res18);
  }
  return uVar4;
}



===== EvtAdapterReceiveScalingSetHashSecretKey @ 1c00020b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EvtAdapterReceiveScalingSetHashSecretKey(undefined8 param_1,longlong *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  
  lVar4 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  uVar1 = param_2[1];
  lVar2 = *param_2;
  uVar6 = 0x90;
  uVar5 = 0;
  if (uVar1 >> 2 != 0) {
    do {
      cVar3 = GigaMacWrite4(lVar4,uVar6,*(undefined4 *)(lVar2 + uVar5 * 4));
      if (cVar3 == '\0') {
        (**(code **)(WdfFunctions_01021 + 0x2b8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 8),1);
        return 0xc0000001;
      }
      uVar5 = uVar5 + 1;
      uVar6 = uVar6 + 4;
    } while (uVar5 < uVar1 >> 2);
  }
  return 0;
}



===== EvtAdapterReceiveScalingSetIndirectionEntries @ 1c0002180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EvtAdapterReceiveScalingSetIndirectionEntries(undefined8 param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  
  lVar4 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  uVar6 = 0;
  if (param_2[1] != 0) {
    lVar9 = 0;
    do {
      lVar5 = (**(code **)(WdfFunctions_01021 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)(lVar9 + *param_2),
                         PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040);
      uVar1 = *(uint *)(lVar5 + 0xd0);
      uVar2 = *(uint *)(lVar9 + 0xc + *param_2);
      uVar7 = 1 << ((byte)uVar2 & 0x1f);
      uVar8 = (ulonglong)(uVar2 >> 5);
      uVar2 = *(uint *)(lVar4 + 0x594 + uVar8 * 4);
      uVar3 = uVar7 | uVar2;
      if ((uVar1 & 1) == 0) {
        uVar3 = ~uVar7 & uVar2;
      }
      *(uint *)(lVar4 + 0x594 + uVar8 * 4) = uVar3;
      uVar2 = *(uint *)(lVar4 + 0x5a4 + uVar8 * 4);
      uVar3 = uVar2 | uVar7;
      if ((uVar1 & 2) == 0) {
        uVar3 = ~uVar7 & uVar2;
      }
      uVar6 = uVar6 + 1;
      *(uint *)(lVar4 + 0x5a4 + uVar8 * 4) = uVar3;
      lVar9 = lVar9 + 0x10;
    } while (uVar6 < (ulonglong)param_2[1]);
  }
  uVar6 = 0x90;
  do {
    *(undefined4 *)(*(longlong *)(lVar4 + 0x530) + uVar6) = *(undefined4 *)(lVar4 + 0x504 + uVar6);
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0xb0);
  return 0;
}



===== EvtSetReceiveFilter @ 1c00022c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtSetReceiveFilter(struct NETADAPTER__ * __ptr64,struct NETRECEIVEFILTER__ *
   __ptr64) */

void __cdecl EvtSetReceiveFilter(NETADAPTER__ *param_1,NETRECEIVEFILTER__ *param_2)

{
  undefined4 uVar1;
  _RT_ADAPTER *p_Var2;
  void *_Src;
  uint uVar3;
  
  p_Var2 = (_RT_ADAPTER *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018);
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x98));
  uVar3 = (*DAT_1c000d848)(NetDriverGlobals,param_2);
  *(uint *)(p_Var2 + 0xa0) = uVar3;
  if ((uVar3 & 0x20) == 0) {
    uVar3 = (uVar3 * 2 | uVar3) & 4 | (uVar3 & 1) * 2 | uVar3 & 8;
  }
  else {
    uVar3 = 0x3f;
  }
  *(uint *)(*(longlong *)(p_Var2 + 0x530) + 0x44) = uVar3 | 0x700;
  uVar1 = (*DAT_1c000d850)(NetDriverGlobals);
  *(undefined4 *)(p_Var2 + 0xac) = uVar1;
  memset(p_Var2 + 0xb0,0,0x440);
  if (*(int *)(p_Var2 + 0xac) != 0) {
    _Src = (void *)(*DAT_1c000d858)(NetDriverGlobals,param_2);
    memcpy(p_Var2 + 0xb0,_Src,(ulonglong)*(uint *)(p_Var2 + 0xac) * 0x22);
  }
  RtAdapterPushMulticastList(p_Var2);
  (**(code **)(WdfFunctions_01021 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x98));
  return;
}



===== RtAdapterIssueFullReset @ 1c0002410 =====

/* void __cdecl RtAdapterIssueFullReset(struct _RT_ADAPTER * __ptr64) */

void __cdecl RtAdapterIssueFullReset(_RT_ADAPTER *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined1 *)(*(longlong *)(param_1 + 0x530) + 0x37) = 0x10;
  do {
    KeStallExecutionProcessor(0x14);
    if ((*(byte *)(*(longlong *)(param_1 + 0x530) + 0x37) & 0x10) == 0) {
      return;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x14);
  return;
}



===== RtAdapterPushMulticastList @ 1c0002464 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl RtAdapterPushMulticastList(struct _RT_ADAPTER * __ptr64) */

void __cdecl RtAdapterPushMulticastList(_RT_ADAPTER *param_1)

{
  uint uVar1;
  _RT_ADAPTER *p_Var2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  _RT_ADAPTER _Var6;
  _RT_ADAPTER *p_Var7;
  uint uVar8;
  ulonglong uVar9;
  undefined4 local_38;
  undefined4 local_34;
  byte local_30 [24];
  
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  if ((*(uint *)(param_1 + 0xa0) & 0x24) == 0) {
    if (*(uint *)(param_1 + 0xac) != 0) {
      p_Var7 = param_1 + 0xb0;
      uVar5 = (ulonglong)*(uint *)(param_1 + 0xac);
      do {
        uVar3 = 0xffffffff;
        if (*(ushort *)p_Var7 != 0) {
          p_Var2 = p_Var7 + 2;
          uVar9 = (ulonglong)*(ushort *)p_Var7;
          do {
            _Var6 = *p_Var2;
            lVar4 = 8;
            do {
              uVar8 = (uint)(byte)_Var6;
              uVar1 = uVar3 >> 0x1f;
              uVar3 = uVar3 * 2;
              _Var6 = (_RT_ADAPTER)((byte)_Var6 >> 1);
              uVar1 = uVar8 & 1 ^ uVar1;
              if (uVar1 != 0) {
                uVar3 = uVar3 ^ 0x4c11db6 | uVar1;
              }
              lVar4 = lVar4 + -1;
            } while (lVar4 != 0);
            p_Var2 = p_Var2 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        p_Var7 = p_Var7 + 0x22;
        local_30[uVar3 >> 0x1d] = local_30[uVar3 >> 0x1d] | (byte)(1 << (uVar3 >> 0x1a & 7));
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  else {
    local_30[0] = 0xff;
    local_30[1] = 0xff;
    local_30[2] = 0xff;
    local_30[3] = 0xff;
    local_30[4] = 0xff;
    local_30[5] = 0xff;
    local_30[6] = 0xff;
    local_30[7] = 0xff;
  }
  local_38 = CONCAT13(local_30[4],CONCAT12(local_30[5],CONCAT11(local_30[6],local_30[7])));
  *(undefined4 *)(*(longlong *)(param_1 + 0x530) + 8) = local_38;
  local_34 = CONCAT13(local_30[0],CONCAT12(local_30[1],CONCAT11(local_30[2],local_30[3])));
  *(undefined4 *)(*(longlong *)(param_1 + 0x530) + 0xc) = local_34;
  return;
}



===== RtAdapterQueryChipType @ 1c0002598 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* bool __cdecl RtAdapterQueryChipType(struct _RT_ADAPTER * __ptr64,enum _RT_CHIP_TYPE * __ptr64) */

bool __cdecl RtAdapterQueryChipType(_RT_ADAPTER *param_1,_RT_CHIP_TYPE *param_2)

{
  _RT_CHIP_TYPE _Var1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  undefined1 auStackY_b8 [32];
  uint local_88;
  uint local_84;
  uint local_80 [2];
  undefined8 local_78 [4];
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar3 = *(uint *)(*(longlong *)(param_1 + 0x530) + 0x40) & 0x7c800000;
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0x530) + 0x40) & 0x700000;
  uVar4 = *(uint *)(*(longlong *)(param_1 + 0x530) + 0x44) & 0x40;
  if (5 < DAT_1c000d1e0) {
    local_2c = 0;
    local_38 = &local_88;
    local_3c = 0;
    local_4c = 0;
    local_48 = &local_84;
    local_30 = 4;
    local_58 = local_80;
    local_40 = 4;
    local_50 = 4;
    local_88 = uVar4;
    local_84 = uVar2;
    local_80[0] = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000be11,0,0,5,local_78);
  }
  *param_2 = 0;
  if (uVar3 == 0x28000000) {
    _Var1 = 2;
    if (uVar2 == 0) {
      _Var1 = 1;
    }
    bVar5 = uVar4 == 0;
    *param_2 = _Var1;
  }
  else if (uVar3 == 0x2c000000) {
    *param_2 = 3;
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  return bVar5;
}



===== RtAdapterReadAddress @ 1c00026c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl RtAdapterReadAddress(struct _RT_ADAPTER * __ptr64) */

long __cdecl RtAdapterReadAddress(_RT_ADAPTER *param_1)

{
  undefined1 uVar1;
  _RT_ADAPTER _Var2;
  ushort uVar3;
  _RT_ADAPTER *p_Var4;
  _tlgProvider_t *p_Var5;
  longlong lVar6;
  ushort uVar7;
  long lVar8;
  _GUID *in_R8;
  _GUID *in_R9;
  _RT_ADAPTER *p_Var9;
  longlong lVar10;
  undefined1 auStackY_e8 [32];
  undefined8 local_a0;
  wchar_t *local_98;
  wchar_t *local_90;
  wchar_t *local_88 [2];
  undefined8 local_78 [4];
  uint *local_58;
  undefined8 local_50;
  _RT_ADAPTER *local_48;
  uint local_40 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (5 < DAT_1c000d1e0) {
    local_a0 = *(undefined8 *)param_1;
    local_98 = L"RtAdapterReadAddress";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bebd,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_98,(_tlgWrapperByVal<8> *)&local_a0);
  }
  lVar8 = 0;
  lVar10 = 3;
  if (param_1[0x591] == (_RT_ADAPTER)0x0) {
    lVar6 = 0;
    do {
      p_Var5 = (_tlgProvider_t *)(ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x530) + lVar6);
      *(ushort *)(param_1 + lVar6 + 0x4a) = *(ushort *)(*(longlong *)(param_1 + 0x530) + lVar6);
      lVar6 = lVar6 + 2;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    *(undefined2 *)(param_1 + 0x48) = 6;
  }
  else {
    p_Var9 = param_1 + 0x4b;
    param_1[0x592] = (_RT_ADAPTER)0x1;
    uVar7 = 0;
    uVar1 = *(undefined1 *)(*(longlong *)(param_1 + 0x530) + 0x50);
    do {
      p_Var4 = param_1;
      uVar3 = ReadEEPROM((longlong)param_1,uVar7 + 7);
      p_Var9[-1] = SUB21(uVar3,0);
      uVar7 = uVar7 + 1;
      *p_Var9 = SUB21(uVar3 >> 8,0);
      p_Var9 = p_Var9 + 2;
    } while (uVar7 < 3);
    p_Var5 = (_tlgProvider_t *)CONCAT71((int7)((ulonglong)p_Var4 >> 8),uVar1);
    *(undefined2 *)(param_1 + 0x48) = 6;
    *(undefined1 *)(*(longlong *)(param_1 + 0x530) + 0x50) = uVar1;
    param_1[0x592] = (_RT_ADAPTER)0x0;
  }
  if (5 < DAT_1c000d1e0) {
    local_58 = local_40;
    local_50 = 2;
    p_Var5 = (_tlgProvider_t *)&DAT_1c000d1e0;
    local_40[0] = (uint)*(ushort *)(param_1 + 0x48);
    in_R9 = (_GUID *)0x0;
    in_R8 = (_GUID *)0x0;
    local_40[1] = 0;
    local_48 = param_1 + 0x4a;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000bf17,0,0,4,local_78);
  }
  _Var2 = param_1[0x4a];
  if (((byte)_Var2 & 1) == 0) {
    p_Var5 = (_tlgProvider_t *)CONCAT71((int7)((ulonglong)p_Var5 >> 8),0xff);
    if (_Var2 == (_RT_ADAPTER)0xff) {
      if ((((param_1[0x4b] == (_RT_ADAPTER)0xff) && (param_1[0x4c] == (_RT_ADAPTER)0xff)) &&
          (param_1[0x4d] == (_RT_ADAPTER)0xff)) && (param_1[0x4e] == (_RT_ADAPTER)0xff)) {
        if (param_1[0x4f] == (_RT_ADAPTER)0xff) goto LAB_1c0002893;
        goto LAB_1c000284b;
      }
    }
    else {
LAB_1c000284b:
      if ((((_Var2 == (_RT_ADAPTER)0x0) && (param_1[0x4b] == (_RT_ADAPTER)0x0)) &&
          ((param_1[0x4c] == (_RT_ADAPTER)0x0 &&
           ((param_1[0x4d] == (_RT_ADAPTER)0x0 && (param_1[0x4e] == (_RT_ADAPTER)0x0)))))) &&
         (param_1[0x4f] == (_RT_ADAPTER)0x0)) goto LAB_1c0002893;
    }
    if (param_1[0x8c] == (_RT_ADAPTER)0x0) {
      *(undefined8 *)(param_1 + 0x6a) = *(undefined8 *)(param_1 + 0x48);
      *(undefined8 *)(param_1 + 0x72) = *(undefined8 *)(param_1 + 0x50);
      *(undefined8 *)(param_1 + 0x7a) = *(undefined8 *)(param_1 + 0x58);
      *(undefined8 *)(param_1 + 0x82) = *(undefined8 *)(param_1 + 0x60);
      *(undefined2 *)(param_1 + 0x8a) = *(undefined2 *)(param_1 + 0x68);
    }
  }
  else {
LAB_1c0002893:
    lVar8 = -0x3fdcffde;
    if (2 < DAT_1c000d1e0) {
      local_98 = (wchar_t *)CONCAT44(local_98._4_4_,0xc0230022);
      local_88[0] = L"STATUS_NDIS_INVALID_ADDRESS";
      local_a0 = CONCAT44(local_a0._4_4_,0x1de);
      local_90 = L"RtAdapterReadAddress";
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
                (p_Var5,&DAT_1c000be46,in_R8,in_R9,(_tlgWrapSz<unsigned_short> *)&local_90,
                 (_tlgWrapperByVal<4> *)&local_a0,(_tlgWrapperByVal<4> *)&local_98,
                 (_tlgWrapSz<unsigned_short> *)local_88);
    }
  }
  if (5 < DAT_1c000d1e0) {
    local_a0 = CONCAT44(local_a0._4_4_,lVar8);
    local_90 = L"RtAdapterReadAddress";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var5,&DAT_1c000be88,in_R8,in_R9,(_tlgWrapSz<unsigned_short> *)&local_90,
               (_tlgWrapperByVal<4> *)&local_a0);
  }
  return lVar8;
}



===== RtAdapterSetupCurrentAddress @ 1c0002954 =====

/* void __cdecl RtAdapterSetupCurrentAddress(struct _RT_ADAPTER * __ptr64) */

void __cdecl RtAdapterSetupCurrentAddress(_RT_ADAPTER *param_1)

{
  _RT_ADAPTER _Var1;
  longlong lVar2;
  _RT_ADAPTER *p_Var3;
  longlong lVar4;
  
  p_Var3 = param_1 + 0x6c;
  *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) =
       *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) | 0xc0;
  lVar2 = 0;
  lVar4 = 6;
  do {
    _Var1 = *p_Var3;
    p_Var3 = p_Var3 + 1;
    *(_RT_ADAPTER *)(*(longlong *)(param_1 + 0x530) + lVar2) = _Var1;
    lVar2 = lVar2 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) =
       *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) & 0x3f;
  return;
}



===== RtAdapterStart @ 1c00029b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl RtAdapterStart(struct _RT_ADAPTER * __ptr64) */

long __cdecl RtAdapterStart(_RT_ADAPTER *param_1)

{
  int iVar1;
  _tlgProvider_t *p_Var2;
  _GUID *in_R8;
  _GUID *p_Var3;
  _GUID *in_R9;
  _GUID *p_Var4;
  undefined1 auStackY_1a8 [32];
  undefined8 local_168;
  wchar_t *local_160;
  code *local_158;
  code *local_150;
  wchar_t *local_148 [2];
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  int local_118;
  undefined4 local_114;
  undefined8 local_110;
  undefined8 *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  wchar_t *local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  code *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined4 local_60;
  uint local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  code *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1a8;
  if (5 < DAT_1c000d1e0) {
    local_168 = *(undefined8 *)param_1;
    local_148[0] = L"RtAdapterStart";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)L"RtAdapterStart",&DAT_1c000bebd,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)local_148,(_tlgWrapperByVal<8> *)&local_168);
  }
  local_28 = 1000000000;
  local_20 = (code *)0x3b9aca00;
  local_30 = 0x18;
  (*DAT_1c000d610)(NetDriverGlobals,*(undefined8 *)param_1,&local_30);
  (*DAT_1c000d618)(NetDriverGlobals,*(undefined8 *)param_1,0x5dc);
  (*DAT_1c000d670)(NetDriverGlobals,*(undefined8 *)param_1,param_1 + 0x48);
  (*DAT_1c000d678)(NetDriverGlobals,*(undefined8 *)param_1,param_1 + 0x6a);
  local_150 = EvtSetReceiveFilter;
  local_160 = (wchar_t *)0x2f00000018;
  local_158 = (code *)0x20;
  (*DAT_1c000d840)(NetDriverGlobals,*(undefined8 *)param_1,&local_160);
  local_120 = 0;
  local_138 = 0x58;
  local_130 = 4;
  local_100 = EvtAdapterReceiveScalingEnable;
  local_f8 = EvtAdapterReceiveScalingDisable;
  local_f0 = EvtAdapterReceiveScalingSetHashSecretKey;
  local_e8 = EvtAdapterReceiveScalingSetIndirectionEntries;
  local_118 = 1;
  local_128 = 0x80;
  local_114 = 1;
  local_110 = 0x15;
  local_108 = (undefined8 *)0x100000000;
  (*DAT_1c000d7a8)(NetDriverGlobals,*(undefined8 *)param_1,&local_138);
  local_168 = 0x100000008;
  (*DAT_1c000d640)(NetDriverGlobals,*(undefined8 *)param_1,&local_168);
  local_a0 = *(undefined8 *)(param_1 + 0x540);
  local_8c = 0x80000000;
  local_a8 = 0x20;
  local_98 = 0;
  local_90 = 2;
  local_130 = 0;
  local_114 = 0;
  local_120 = 1;
  p_Var4 = (_GUID *)&local_68;
  local_118 = *(int *)(param_1 + 0x90) << 4;
  local_38 = &local_88;
  local_5c = (uint)*(ushort *)(param_1 + 0x566);
  local_6c = 0x80000000;
  local_68 = 0x38;
  local_110 = 1;
  local_138 = 0x100000038;
  local_128 = 0x10;
  local_88 = 0x20;
  local_78 = 0;
  local_70 = 2;
  local_48 = 1;
  local_58 = 0x5f6;
  local_50 = 1;
  local_60 = 0;
  local_40 = 0x40;
  local_108 = &local_a8;
  local_80 = local_a0;
  (*DAT_1c000d650)(NetDriverGlobals,*(undefined8 *)param_1,&local_138);
  local_20 = EvtAdapterOffloadSetTxChecksum;
  local_30 = 0xf00000018;
  local_28 = 0x3ff000000000007;
  (*DAT_1c000d8a8)(NetDriverGlobals,*(undefined8 *)param_1,&local_30);
  local_158 = EvtAdapterOffloadSetRxChecksum;
  local_160 = (wchar_t *)0x10;
  (*DAT_1c000d8c8)(NetDriverGlobals,*(undefined8 *)param_1,&local_160);
  local_cc = 0xf;
  local_b0 = EvtAdapterOffloadSetGso;
  local_c4 = 0x7f;
  local_d0 = 0x28;
  local_c8 = 3;
  local_c0 = 64000;
  local_b8 = 2;
  (*DAT_1c000d8e8)(NetDriverGlobals,*(undefined8 *)param_1,&local_d0);
  p_Var3 = (_GUID *)&local_168;
  local_168 = 0x300000008;
  (*DAT_1c000d930)(NetDriverGlobals,*(undefined8 *)param_1);
  iVar1 = (*DAT_1c000d600)(NetDriverGlobals,*(undefined8 *)param_1);
  if (iVar1 < 0) {
    p_Var2 = (_tlgProvider_t *)(ulonglong)DAT_1c000d1e0;
    if (DAT_1c000d1e0 < 3) goto LAB_1c0002dea;
    local_148[0] = (wchar_t *)CONCAT44(local_148[0]._4_4_,iVar1);
    local_d8 = L"NetAdapterStart(adapter->NetAdapter)";
    local_168 = CONCAT44(local_168._4_4_,0x45b);
    local_160 = L"RtAdapterStart";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
              (p_Var2,&DAT_1c000be46,p_Var3,p_Var4,(_tlgWrapSz<unsigned_short> *)&local_160,
               (_tlgWrapperByVal<4> *)&local_168,(_tlgWrapperByVal<4> *)local_148,
               (_tlgWrapSz<unsigned_short> *)&local_d8);
  }
  p_Var2 = (_tlgProvider_t *)(ulonglong)DAT_1c000d1e0;
LAB_1c0002dea:
  if (5 < (uint)p_Var2) {
    local_168 = CONCAT44(local_168._4_4_,iVar1);
    local_160 = L"RtAdapterStart";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var2,&DAT_1c000be88,p_Var3,p_Var4,(_tlgWrapSz<unsigned_short> *)&local_160,
               (_tlgWrapperByVal<4> *)&local_168);
  }
  return iVar1;
}



===== RtAdapterUpdateHardwareChecksum @ 1c0002e4c =====

/* void __cdecl RtAdapterUpdateHardwareChecksum(struct _RT_ADAPTER * __ptr64) */

void __cdecl RtAdapterUpdateHardwareChecksum(_RT_ADAPTER *param_1)

{
  ushort uVar1;
  
  if (((((param_1[0x56a] == (_RT_ADAPTER)0x0) && (param_1[0x56b] == (_RT_ADAPTER)0x0)) &&
       (param_1[0x56c] == (_RT_ADAPTER)0x0)) &&
      ((param_1[0x56d] == (_RT_ADAPTER)0x0 && (param_1[0x56e] == (_RT_ADAPTER)0x0)))) &&
     ((param_1[0x56f] == (_RT_ADAPTER)0x0 &&
      ((param_1[0x5b8] != (_RT_ADAPTER)0x1 && (param_1[0x5b9] != (_RT_ADAPTER)0x1)))))) {
    uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x530) + 0xe0) & 0xffdf;
  }
  else {
    uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x530) + 0xe0) | 0x20;
  }
  *(ushort *)(*(longlong *)(param_1 + 0x530) + 0xe0) = uVar1;
  return;
}



===== RtInitializeAdapterContext @ 1c0002ec4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RtInitializeAdapterContext(struct _RT_ADAPTER * __ptr64,struct WDFDEVICE__ *
   __ptr64,struct NETADAPTER__ * __ptr64) */

long __cdecl
RtInitializeAdapterContext(_RT_ADAPTER *param_1,WDFDEVICE__ *param_2,NETADAPTER__ *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  _tlgProvider_t *p_Var3;
  _RT_ADAPTER *p_Var4;
  _GUID *in_R9;
  wchar_t *local_res8;
  wchar_t *local_res10;
  wchar_t *local_res18;
  wchar_t *local_res20;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if (5 < DAT_1c000d1e0) {
    local_res8 = L"RtInitializeAdapterContext";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bef0,(_GUID *)param_3,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res8);
  }
  *(NETADAPTER__ **)param_1 = param_3;
  *(WDFDEVICE__ **)(param_1 + 8) = param_2;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068);
  p_Var4 = param_1 + 0x98;
  *puVar2 = param_1;
  *(undefined8 *)(param_1 + 0x594) = 0;
  *(undefined8 *)(param_1 + 0x59c) = 0;
  local_38 = 0;
  *(undefined8 *)(param_1 + 0x5a4) = 0;
  *(undefined8 *)(param_1 + 0x5ac) = 0;
  param_1[0x592] = (_RT_ADAPTER)0x0;
  local_58 = 0;
  uStack_50 = 0x100000001;
  local_48 = *(undefined8 *)(param_1 + 8);
  uStack_40 = 0;
  uStack_60 = 0;
  local_68 = 0x38;
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x9d8))(WdfDriverGlobals,&local_68);
  if (iVar1 < 0) {
    p_Var3 = (_tlgProvider_t *)(ulonglong)DAT_1c000d1e0;
    if (DAT_1c000d1e0 < 3) goto LAB_1c0002ffe;
    local_res8 = (wchar_t *)CONCAT44(local_res8._4_4_,iVar1);
    local_res18 = L"WdfSpinLockCreate(&attributes, &adapter->Lock)";
    local_res10 = (wchar_t *)CONCAT44(local_res10._4_4_,0x4e);
    local_res20 = L"RtInitializeAdapterContext";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
              (p_Var3,&DAT_1c000be46,(_GUID *)p_Var4,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<4> *)&local_res10,
               (_tlgWrapperByVal<4> *)&local_res8,(_tlgWrapSz<unsigned_short> *)&local_res18);
  }
  p_Var3 = (_tlgProvider_t *)(ulonglong)DAT_1c000d1e0;
LAB_1c0002ffe:
  if (5 < (uint)p_Var3) {
    local_res8 = (wchar_t *)CONCAT44(local_res8._4_4_,iVar1);
    local_res10 = L"RtInitializeAdapterContext";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var3,&DAT_1c000be88,(_GUID *)p_Var4,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res10,(_tlgWrapperByVal<4> *)&local_res8);
  }
  return iVar1;
}



===== RtAdapterReadConfiguration @ 1c0003040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl RtAdapterReadConfiguration(struct _RT_ADAPTER * __ptr64) */

long __cdecl RtAdapterReadConfiguration(_RT_ADAPTER *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  _tlgProvider_t *p_Var5;
  uint *puVar6;
  _GUID *in_R8;
  _RT_ADAPTER *p_Var7;
  _GUID *in_R9;
  _GUID *p_Var8;
  longlong lVar9;
  longlong lVar10;
  undefined1 auStackY_178 [32];
  uint local_138;
  uint local_134;
  wchar_t *local_130;
  wchar_t *local_128;
  longlong local_120;
  wchar_t *local_118;
  ulonglong local_110;
  undefined8 local_108 [4];
  ulonglong *local_e8;
  undefined8 local_e0;
  _RT_ADAPTER *local_d8;
  ulonglong local_d0;
  undefined8 local_c8;
  uint local_c0 [2];
  uint *local_b8;
  undefined8 local_b0;
  undefined8 local_a8 [4];
  wchar_t **local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  undefined8 local_68;
  uint local_60 [2];
  wchar_t **local_58;
  undefined8 local_50;
  wchar_t **local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_178;
  if (5 < DAT_1c000d1e0) {
    local_130 = *(wchar_t **)param_1;
    local_128 = L"RtAdapterReadConfiguration";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bebd,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_128,(_tlgWrapperByVal<8> *)&local_130);
  }
  p_Var8 = (_GUID *)&local_120;
  p_Var7 = (_RT_ADAPTER *)0x0;
  local_120 = 0;
  p_Var5 = NetDriverGlobals;
  uVar3 = (*DAT_1c000d668)(NetDriverGlobals,*(undefined8 *)param_1);
  if ((int)uVar3 < 0) {
    if (2 < DAT_1c000d1e0) {
      local_130 = 
      L"NetAdapterOpenConfiguration(adapter->NetAdapter, WDF_NO_OBJECT_ATTRIBUTES, &configuration)";
      local_134 = 0x4a;
      local_128 = L"RtAdapterReadConfiguration";
      local_138 = uVar3;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
                (p_Var5,&DAT_1c000be46,(_GUID *)p_Var7,p_Var8,
                 (_tlgWrapSz<unsigned_short> *)&local_128,(_tlgWrapperByVal<4> *)&local_134,
                 (_tlgWrapperByVal<4> *)&local_138,(_tlgWrapSz<unsigned_short> *)&local_130);
    }
  }
  else {
    puVar6 = &DAT_1c000d0bc;
    lVar10 = 7;
    do {
      lVar9 = lVar10;
      p_Var8 = (_GUID *)(puVar6 + -7);
      uVar3 = puVar6[-3];
      local_138 = 0;
      iVar4 = (*DAT_1c000d708)(NetDriverGlobals,local_120);
      if (((iVar4 < 0) || (local_138 < *puVar6)) || (puVar6[1] < local_138)) {
        local_138 = puVar6[-1];
      }
      if (5 < DAT_1c000d1e0) {
        local_110 = *(ulonglong *)param_1;
        p_Var8 = (_GUID *)0x0;
        local_b0 = 4;
        local_b8 = &local_134;
        local_d8 = (_RT_ADAPTER *)local_c0;
        local_d0 = 2;
        local_c8 = *(undefined8 *)(puVar6 + -5);
        local_e8 = &local_110;
        local_c0[0] = (uint)(ushort)puVar6[-7];
        local_c0[1] = 0;
        local_e0 = 8;
        local_134 = local_138;
        _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000bf4d,0,0,6,local_108);
      }
      uVar2 = puVar6[-2];
      if (uVar2 == 1) {
        param_1[uVar3] = SUB41(local_138,0);
      }
      else if (uVar2 == 2) {
        *(short *)(param_1 + uVar3) = (short)local_138;
      }
      else if (uVar2 == 4) {
        *(uint *)(param_1 + uVar3) = local_138;
      }
      else if (2 < DAT_1c000d1e0) {
        local_130 = (wchar_t *)CONCAT44(local_130._4_4_,local_138);
        local_118 = *(wchar_t **)param_1;
        p_Var8 = (_GUID *)0x0;
        local_48 = &local_128;
        local_58 = &local_130;
        local_78 = local_60;
        local_128 = (wchar_t *)CONCAT44(local_128._4_4_,uVar2);
        local_40 = 4;
        local_50 = 4;
        local_70 = 2;
        local_68 = *(undefined8 *)(puVar6 + -5);
        local_88 = &local_118;
        local_60[0] = (uint)(ushort)puVar6[-7];
        local_60[1] = 0;
        local_80 = 8;
        _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000bf86,0,0,7,local_a8);
      }
      puVar6 = puVar6 + 10;
      lVar10 = lVar9 + -1;
    } while (lVar10 != 0);
    p_Var7 = param_1 + 0x6a;
    p_Var5 = NetDriverGlobals;
    iVar4 = (*DAT_1c000d728)(NetDriverGlobals,local_120);
    if (iVar4 == 0) {
      uVar1 = *(ushort *)(param_1 + 0x6a);
      p_Var5 = (_tlgProvider_t *)(ulonglong)uVar1;
      if (((uVar1 == (ushort)((short)lVar9 + 5U)) && (((byte)param_1[0x6c] & 1) == 0)) &&
         ((((param_1[0x6c] != (_RT_ADAPTER)0xff ||
            ((param_1[0x6d] != (_RT_ADAPTER)0xff || (param_1[0x6e] != (_RT_ADAPTER)0xff)))) ||
           (param_1[0x6f] != (_RT_ADAPTER)0xff)) ||
          ((param_1[0x70] != (_RT_ADAPTER)0xff || (param_1[0x71] != (_RT_ADAPTER)0xff)))))) {
        param_1[0x8c] = (_RT_ADAPTER)0x1;
      }
      else if (5 < DAT_1c000d1e0) {
        local_e8 = &local_d0;
        local_d8 = param_1 + 0x6c;
        local_e0 = 2;
        p_Var5 = (_tlgProvider_t *)&DAT_1c000d1e0;
        local_d0 = (ulonglong)uVar1;
        p_Var8 = (_GUID *)0x0;
        p_Var7 = (_RT_ADAPTER *)0x0;
        _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000bfc9,0,0,4,local_108);
      }
    }
    uVar3 = 0;
    *(uint *)(param_1 + 0x90) = (uint)*(ushort *)(param_1 + 0x568);
  }
  if (local_120 != 0) {
    p_Var5 = NetDriverGlobals;
    (*DAT_1c000d6f8)();
  }
  if (5 < DAT_1c000d1e0) {
    local_130 = (wchar_t *)CONCAT44(local_130._4_4_,uVar3);
    local_118 = L"RtAdapterReadConfiguration";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var5,&DAT_1c000be88,(_GUID *)p_Var7,p_Var8,(_tlgWrapSz<unsigned_short> *)&local_118
               ,(_tlgWrapperByVal<4> *)&local_130);
  }
  return 0;
}



===== EvtDevicePrepareHardware @ 1c0003450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtDevicePrepareHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
EvtDevicePrepareHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  long lVar1;
  undefined8 *puVar2;
  _tlgProvider_t *p_Var3;
  _RT_ADAPTER *p_Var4;
  _GUID *p_Var5;
  _GUID *in_R9;
  undefined8 local_res20;
  wchar_t *local_38;
  wchar_t *local_30;
  wchar_t *local_28 [2];
  
  p_Var3 = WdfDriverGlobals;
  p_Var5 = (_GUID *)PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068;
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  p_Var4 = (_RT_ADAPTER *)*puVar2;
  if (5 < DAT_1c000d1e0) {
    local_res20 = *(undefined8 *)p_Var4;
    local_38 = L"EvtDevicePrepareHardware";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              (p_Var3,&DAT_1c000bebd,p_Var5,in_R9,(_tlgWrapSz<unsigned_short> *)&local_38,
               (_tlgWrapperByVal<8> *)&local_res20);
  }
  lVar1 = RtInitializeHardware(p_Var4,param_2,param_3);
  if ((lVar1 < 0) && (2 < DAT_1c000d1e0)) {
    local_res20 = CONCAT44(local_res20._4_4_,lVar1);
    local_30 = L"RtInitializeHardware(adapter, resourcesRaw, resourcesTranslated)";
    local_38 = (wchar_t *)CONCAT44(local_38._4_4_,0x11d);
    local_28[0] = L"EvtDevicePrepareHardware";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)p_Var4,&DAT_1c000be46,(_GUID *)param_3,in_R9,
               (_tlgWrapSz<unsigned_short> *)local_28,(_tlgWrapperByVal<4> *)&local_38,
               (_tlgWrapperByVal<4> *)&local_res20,(_tlgWrapSz<unsigned_short> *)&local_30);
  }
  if (5 < DAT_1c000d1e0) {
    local_res20 = CONCAT44(local_res20._4_4_,lVar1);
    local_28[0] = L"EvtDevicePrepareHardware";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)p_Var4,&DAT_1c000be88,(_GUID *)param_3,in_R9,
               (_tlgWrapSz<unsigned_short> *)local_28,(_tlgWrapperByVal<4> *)&local_res20);
  }
  return lVar1;
}



===== EvtDeviceReleaseHardware @ 1c0003590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtDeviceReleaseHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64) */

long __cdecl EvtDeviceReleaseHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  ulonglong *puVar1;
  longlong *plVar2;
  _tlgProvider_t *p_Var3;
  _GUID *p_Var4;
  _GUID *in_R9;
  ulonglong local_res18;
  wchar_t *local_res20;
  
  p_Var3 = WdfDriverGlobals;
  p_Var4 = (_GUID *)PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068;
  plVar2 = (longlong *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  puVar1 = (ulonglong *)*plVar2;
  if (5 < DAT_1c000d1e0) {
    local_res18 = *puVar1;
    local_res20 = L"EvtDeviceReleaseHardware";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              (p_Var3,&DAT_1c000bebd,p_Var4,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res20,
               (_tlgWrapperByVal<8> *)&local_res18);
  }
  if (puVar1[0xa9] != 0) {
    p_Var3 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01021 + 0x680))();
    puVar1[0xa9] = 0;
  }
  if (puVar1[0xa6] != 0) {
    p_Var3 = (_tlgProvider_t *)puVar1[0xa6];
    MmUnmapIoSpace(p_Var3,0x100);
    puVar1[0xa6] = 0;
  }
  if (5 < DAT_1c000d1e0) {
    local_res18 = local_res18 & 0xffffffff00000000;
    local_res20 = L"EvtDeviceReleaseHardware";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var3,&DAT_1c000be88,p_Var4,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res20,
               (_tlgWrapperByVal<4> *)&local_res18);
  }
  return 0;
}



===== RtGetResources @ 1c00036a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RtGetResources(struct _RT_ADAPTER * __ptr64,struct WDFCMRESLIST__ * __ptr64,struct
   WDFCMRESLIST__ * __ptr64) */

long __cdecl RtGetResources(_RT_ADAPTER *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  bool bVar1;
  WDFCMRESLIST__ *pWVar2;
  uint uVar3;
  char *pcVar4;
  longlong lVar5;
  _tlgWrapSz<unsigned_short> *p_Var6;
  _tlgProvider_t *p_Var7;
  undefined8 uVar8;
  long lVar9;
  WDFCMRESLIST__ *pWVar10;
  _GUID *in_R9;
  int iVar11;
  uint uVar12;
  int iVar13;
  wchar_t *local_res20;
  _tlgWrapSz<unsigned_short> *p_Var14;
  undefined4 local_68 [2];
  wchar_t *local_60;
  wchar_t *local_58 [3];
  
  pWVar10 = param_3;
  if (5 < DAT_1c000d1e0) {
    local_res20 = L"RtGetResources";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bef0,(_GUID *)param_3,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20);
  }
  lVar9 = 0;
  bVar1 = false;
  iVar13 = 0;
  p_Var7 = WdfDriverGlobals;
  uVar3 = (**(code **)(WdfFunctions_01021 + 0x980))(WdfDriverGlobals,param_2);
  uVar8 = 0;
  pWVar2 = (WDFCMRESLIST__ *)0x0;
  if (uVar3 == 0) {
LAB_1c0003820:
    param_1 = (_RT_ADAPTER *)p_Var7;
    lVar9 = -0x3fdcffe2;
    if (DAT_1c000d1e0 < 3) goto LAB_1c000388b;
    local_res20 = (wchar_t *)CONCAT44(local_res20._4_4_,0xc023001e);
    local_58[0] = L"STATUS_NDIS_RESOURCE_CONFLICT";
    p_Var14 = (_tlgWrapSz<unsigned_short> *)local_58;
    local_68[0] = 0x49;
    local_60 = L"RtGetResources";
    p_Var6 = (_tlgWrapSz<unsigned_short> *)&local_60;
  }
  else {
    do {
      pWVar10 = pWVar2;
      iVar11 = (int)pWVar10;
      pcVar4 = (char *)(**(code **)(WdfFunctions_01021 + 0x988))(WdfDriverGlobals,param_2,pWVar10);
      p_Var7 = WdfDriverGlobals;
      lVar5 = (**(code **)(WdfFunctions_01021 + 0x988))(WdfDriverGlobals,param_3);
      if (*pcVar4 == '\x03') {
        if (iVar13 == 0) {
          uVar8 = *(undefined8 *)(lVar5 + 4);
          bVar1 = true;
        }
        iVar13 = iVar13 + 1;
      }
      uVar12 = iVar11 + 1;
      pWVar2 = (WDFCMRESLIST__ *)(ulonglong)uVar12;
    } while (uVar12 < uVar3);
    if (!bVar1) goto LAB_1c0003820;
    pWVar10 = (WDFCMRESLIST__ *)0x204;
    lVar5 = MmMapIoSpaceEx(uVar8,0x100);
    *(longlong *)(param_1 + 0x530) = lVar5;
    if ((lVar5 != 0) || (lVar9 = -0x3fffff66, DAT_1c000d1e0 < 3)) goto LAB_1c000388b;
    local_res20 = (wchar_t *)CONCAT44(local_res20._4_4_,0xc000009a);
    local_60 = 
    L"(((adapter->CSRAddress = static_cast<RT_MAC*>( MmMapIoSpaceEx( memAddressTranslated, sizeof(RT_MAC), 0x04 | 0x200))) == NULL) ? STATUS_INSUFFICIENT_RESOURCES : STATUS_SUCCESS)"
    ;
    p_Var14 = (_tlgWrapSz<unsigned_short> *)&local_60;
    local_68[0] = 0x52;
    local_58[0] = L"RtGetResources";
    p_Var6 = (_tlgWrapSz<unsigned_short> *)local_58;
  }
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
            ((_tlgProvider_t *)param_1,&DAT_1c000be46,(_GUID *)pWVar10,in_R9,p_Var6,
             (_tlgWrapperByVal<4> *)local_68,(_tlgWrapperByVal<4> *)&local_res20,p_Var14);
LAB_1c000388b:
  if (5 < DAT_1c000d1e0) {
    local_res20 = (wchar_t *)CONCAT44(local_res20._4_4_,lVar9);
    local_58[0] = L"RtGetResources";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000be88,(_GUID *)pWVar10,in_R9,
               (_tlgWrapSz<unsigned_short> *)local_58,(_tlgWrapperByVal<4> *)&local_res20);
  }
  return lVar9;
}



===== RtInitializeChipType @ 1c00038d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RtInitializeChipType(_RT_ADAPTER *param_1)

{
  bool bVar1;
  undefined8 uVar2;
  undefined1 auStackY_78 [32];
  _RT_CHIP_TYPE local_48 [2];
  undefined8 local_40 [4];
  _RT_CHIP_TYPE *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  bVar1 = RtAdapterQueryChipType(param_1,(_RT_CHIP_TYPE *)(param_1 + 0x560));
  if (bVar1) {
    if (5 < DAT_1c000d1e0) {
      local_48[0] = *(_RT_CHIP_TYPE *)(param_1 + 0x560);
      local_14 = 0;
      local_20 = local_48;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000c038,0,0,3,local_40);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000225;
  }
  return uVar2;
}



===== RtInitializeEeprom @ 1c0003970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RtInitializeEeprom(longlong param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  undefined1 auStackY_a8 [32];
  uint local_78;
  uint local_74 [3];
  undefined8 local_68 [4];
  uint *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  cVar4 = '\x01';
  *(undefined1 *)(param_1 + 0x592) = 1;
  uVar1 = *(undefined1 *)(*(longlong *)(param_1 + 0x530) + 0x50);
  uVar2 = ReadEEPROM(param_1,0);
  uVar3 = ReadEEPROM(param_1,1);
  *(undefined1 *)(*(longlong *)(param_1 + 0x530) + 0x50) = uVar1;
  KeStallExecutionProcessor(0x10);
  if ((uVar2 == 0) && (uVar3 == 0)) {
    *(undefined1 *)(param_1 + 0x592) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x592) = 0;
    if (4 < DAT_1c000d1e0) {
      local_38 = &local_78;
      local_30 = 4;
      local_48 = local_74;
      local_40 = 4;
      local_78 = (uint)uVar3;
      local_74[0] = (uint)uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000c00f,0,0,4,local_68);
    }
    if ((uVar2 == 0x8129) && (uVar3 == 0x10ec)) goto LAB_1c0003a70;
  }
  cVar4 = '\0';
LAB_1c0003a70:
  *(char *)(param_1 + 0x591) = cVar4;
  if ((cVar4 == '\0') && (3 < DAT_1c000d1e0)) {
    _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000c0b1,0,0,2,local_68);
  }
  return;
}



===== RtInitializeHardware @ 1c0003ae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RtInitializeHardware(struct _RT_ADAPTER * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
RtInitializeHardware(_RT_ADAPTER *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  long lVar1;
  undefined8 uVar2;
  _tlgWrapperByVal<4> *p_Var3;
  _tlgWrapSz<unsigned_short> *p_Var4;
  _RT_ADAPTER *p_Var5;
  WDFCMRESLIST__ *pWVar6;
  _GUID *in_R9;
  undefined1 auStackY_e8 [32];
  _tlgWrapperByVal<4> *p_Var7;
  _tlgWrapSz<unsigned_short> *p_Var8;
  undefined8 local_98;
  wchar_t *local_90;
  wchar_t *local_88;
  wchar_t *local_80;
  wchar_t *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  pWVar6 = param_3;
  if (5 < DAT_1c000d1e0) {
    local_98 = *(undefined8 *)param_1;
    local_90 = L"RtInitializeHardware";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bebd,(_GUID *)param_3,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_90,(_tlgWrapperByVal<8> *)&local_98);
  }
  p_Var5 = param_1;
  lVar1 = RtAdapterReadConfiguration(param_1);
  if (lVar1 < 0) {
    param_3 = pWVar6;
    if (DAT_1c000d1e0 < 3) goto LAB_1c0003f46;
    local_90 = (wchar_t *)CONCAT44(local_90._4_4_,lVar1);
    local_80 = L"RtAdapterReadConfiguration(adapter)";
    p_Var8 = (_tlgWrapSz<unsigned_short> *)&local_80;
    local_98 = CONCAT44(local_98._4_4_,0xc2);
    p_Var7 = (_tlgWrapperByVal<4> *)&local_90;
    p_Var3 = (_tlgWrapperByVal<4> *)&local_98;
    param_1 = p_Var5;
LAB_1c0003f2f:
    p_Var4 = (_tlgWrapSz<unsigned_short> *)&local_88;
    local_88 = L"RtInitializeHardware";
    p_Var5 = param_1;
  }
  else {
    p_Var5 = param_1;
    lVar1 = RtGetResources(param_1,param_2,param_3);
    if (lVar1 < 0) {
      if (DAT_1c000d1e0 < 3) goto LAB_1c0003f46;
      local_98 = CONCAT44(local_98._4_4_,lVar1);
      local_88 = L"RtGetResources(adapter, resourcesRaw, resourcesTranslated)";
      p_Var8 = (_tlgWrapSz<unsigned_short> *)&local_88;
      local_90 = (wchar_t *)CONCAT44(local_90._4_4_,0xc6);
      p_Var7 = (_tlgWrapperByVal<4> *)&local_98;
      p_Var3 = (_tlgWrapperByVal<4> *)&local_90;
      p_Var4 = (_tlgWrapSz<unsigned_short> *)&local_80;
      local_80 = L"RtInitializeHardware";
    }
    else {
      *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x48) = *(longlong *)(param_1 + 0x530) + 0x3c;
      *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x50) = *(longlong *)(param_1 + 0x530) + 0x84;
      *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58) = *(longlong *)(param_1 + 0x530) + 0x85;
      *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) = *(longlong *)(param_1 + 0x530) + 0xc0;
      *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x28) = *(longlong *)(param_1 + 0x530) + 0x3e;
      *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x30) = *(longlong *)(param_1 + 0x530) + 0x86;
      *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x38) = *(longlong *)(param_1 + 0x530) + 0x87;
      *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x40) = *(longlong *)(param_1 + 0x530) + 0xc1;
      p_Var5 = param_1;
      uVar2 = RtInitializeChipType(param_1);
      lVar1 = (long)uVar2;
      if (lVar1 < 0) {
        if (DAT_1c000d1e0 < 3) goto LAB_1c0003f46;
        local_98 = CONCAT44(local_98._4_4_,lVar1);
        local_88 = L"RtInitializeChipType(adapter)";
        p_Var8 = (_tlgWrapSz<unsigned_short> *)&local_88;
        local_90 = (wchar_t *)CONCAT44(local_90._4_4_,0xd3);
        p_Var7 = (_tlgWrapperByVal<4> *)&local_98;
        p_Var3 = (_tlgWrapperByVal<4> *)&local_90;
        p_Var4 = (_tlgWrapSz<unsigned_short> *)&local_80;
        local_80 = L"RtInitializeHardware";
      }
      else {
        RtInitializeEeprom((longlong)param_1);
        *(byte *)(*(longlong *)(param_1 + 0x530) + 0xf3) =
             *(byte *)(*(longlong *)(param_1 + 0x530) + 0xf3) | 4;
        *(byte *)(*(longlong *)(param_1 + 0x530) + 0xd1) =
             *(byte *)(*(longlong *)(param_1 + 0x530) + 0xd1) | 0x82;
        RtAdapterPushPhySettings(param_1);
        RtAdapterIssueFullReset(param_1);
        RtAdapterWritePhyUint16(param_1,'\x1f',0);
        RtAdapterWritePhyUint16(param_1,'\x0e',0);
        param_3 = (WDFCMRESLIST__ *)0x1000;
        RtAdapterWritePhyUint16(param_1,'\0',0x1000);
        RtAdapterIssueFullReset(param_1);
        p_Var5 = param_1;
        lVar1 = RtAdapterReadAddress(param_1);
        if (-1 < lVar1) {
          p_Var5 = param_1;
          lVar1 = RtRegisterScatterGatherDma(param_1);
          if (lVar1 < 0) {
            if (2 < DAT_1c000d1e0) {
              local_88 = *(wchar_t **)param_1;
              local_80 = L"RtRegisterScatterGatherDma(adapter)";
              local_98 = CONCAT44(local_98._4_4_,lVar1);
              local_90 = (wchar_t *)CONCAT44(local_90._4_4_,0xea);
              local_78 = L"RtInitializeHardware";
              _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
              ::
              Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
                        ((_tlgProvider_t *)p_Var5,&DAT_1c000c063,(_GUID *)param_3,in_R9,
                         (_tlgWrapSz<unsigned_short> *)&local_78,(_tlgWrapperByVal<4> *)&local_90,
                         (_tlgWrapperByVal<4> *)&local_98,(_tlgWrapSz<unsigned_short> *)&local_80,
                         (_tlgWrapperByVal<8> *)&local_88);
            }
            goto LAB_1c0003f46;
          }
          *(byte *)(*(longlong *)(param_1 + 0x530) + 0xf3) =
               *(byte *)(*(longlong *)(param_1 + 0x530) + 0xf3) | 4;
          RtAdapterIssueFullReset(param_1);
          RtAdapterSetupCurrentAddress(param_1);
          RtAdapterWritePhyUint16(param_1,'\x1f',0);
          local_70 = 0;
          uStack_68 = 0;
          *(undefined2 *)(*(longlong *)(param_1 + 0x530) + 0xe0) = 0;
          local_50 = 0;
          local_60 = 0;
          uStack_58 = 0;
          RtAdapterQueryLinkState(param_1,(_NET_ADAPTER_LINK_STATE *)&local_70);
          param_3 = (WDFCMRESLIST__ *)&local_70;
          (*DAT_1c000d658)(NetDriverGlobals,*(undefined8 *)param_1);
          lVar1 = RtAdapterStart(param_1);
          p_Var5 = param_1;
          if ((-1 < lVar1) || (DAT_1c000d1e0 < 3)) goto LAB_1c0003f46;
          local_98 = CONCAT44(local_98._4_4_,lVar1);
          local_78 = L"RtAdapterStart(adapter)";
          p_Var8 = (_tlgWrapSz<unsigned_short> *)&local_78;
          local_90 = (wchar_t *)CONCAT44(local_90._4_4_,0xf7);
          p_Var7 = (_tlgWrapperByVal<4> *)&local_98;
          p_Var3 = (_tlgWrapperByVal<4> *)&local_90;
          goto LAB_1c0003f2f;
        }
        if (DAT_1c000d1e0 < 3) goto LAB_1c0003f46;
        local_98 = CONCAT44(local_98._4_4_,lVar1);
        local_88 = L"RtAdapterReadAddress(adapter)";
        p_Var8 = (_tlgWrapSz<unsigned_short> *)&local_88;
        local_90 = (wchar_t *)CONCAT44(local_90._4_4_,0xe6);
        p_Var7 = (_tlgWrapperByVal<4> *)&local_98;
        p_Var3 = (_tlgWrapperByVal<4> *)&local_90;
        p_Var4 = (_tlgWrapSz<unsigned_short> *)&local_80;
        local_80 = L"RtInitializeHardware";
      }
    }
  }
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
            ((_tlgProvider_t *)p_Var5,&DAT_1c000be46,(_GUID *)param_3,in_R9,p_Var4,p_Var3,p_Var7,
             p_Var8);
LAB_1c0003f46:
  if (5 < DAT_1c000d1e0) {
    local_98 = CONCAT44(local_98._4_4_,lVar1);
    local_78 = L"RtInitializeHardware";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)p_Var5,&DAT_1c000be88,(_GUID *)param_3,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_78,(_tlgWrapperByVal<4> *)&local_98);
  }
  return lVar1;
}



===== RtRegisterScatterGatherDma @ 1c0003f9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RtRegisterScatterGatherDma(struct _RT_ADAPTER * __ptr64) */

long __cdecl RtRegisterScatterGatherDma(_RT_ADAPTER *param_1)

{
  int iVar1;
  _GUID *in_R8;
  _GUID *p_Var2;
  _GUID *in_R9;
  _GUID *p_Var3;
  undefined8 local_res8;
  wchar_t *local_res10;
  _tlgProvider_t *local_res18;
  wchar_t *local_res20;
  wchar_t *local_88 [2];
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined4 local_34;
  uint local_30;
  
  if (5 < DAT_1c000d1e0) {
    local_res8 = *(undefined8 *)param_1;
    local_res10 = L"RtRegisterScatterGatherDma";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bebd,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res10,(_tlgWrapperByVal<8> *)&local_res8);
  }
  memset(&local_78,0,0x50);
  local_30 = local_30 | 2;
  p_Var2 = (_GUID *)&local_78;
  p_Var3 = (_GUID *)0x0;
  local_78 = 0x50;
  local_74 = 4;
  local_70 = 0x5ea;
  local_34 = 3;
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x2f0))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 8),p_Var2,0,param_1 + 0x540);
  if ((iVar1 < 0) && (2 < DAT_1c000d1e0)) {
    local_res18 = *(_tlgProvider_t **)param_1;
    local_res20 = 
    L"WdfDmaEnablerCreate( adapter->WdfDevice, &dmaEnablerConfig, WDF_NO_OBJECT_ATTRIBUTES, &adapter->DmaEnabler)"
    ;
    local_res8 = CONCAT44(local_res8._4_4_,iVar1);
    local_res10 = (wchar_t *)CONCAT44(local_res10._4_4_,0x6c);
    local_88[0] = L"RtRegisterScatterGatherDma";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              (local_res18,&DAT_1c000c063,p_Var2,p_Var3,(_tlgWrapSz<unsigned_short> *)local_88,
               (_tlgWrapperByVal<4> *)&local_res10,(_tlgWrapperByVal<4> *)&local_res8,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<8> *)&local_res18);
  }
  if (5 < DAT_1c000d1e0) {
    local_res8 = CONCAT44(local_res8._4_4_,iVar1);
    local_res10 = L"RtRegisterScatterGatherDma";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)(ulonglong)DAT_1c000d1e0,&DAT_1c000be88,p_Var2,p_Var3,
               (_tlgWrapSz<unsigned_short> *)&local_res10,(_tlgWrapperByVal<4> *)&local_res8);
  }
  return iVar1;
}



===== EvtDriverDeviceAdd @ 1c0004100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl EvtDriverDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl EvtDriverDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  int iVar1;
  _tlgWrapperByVal<4> *p_Var2;
  longlong lVar3;
  _RT_ADAPTER *p_Var4;
  undefined8 *puVar5;
  _tlgWrapSz<unsigned_short> *p_Var6;
  _tlgProvider_t *p_Var7;
  _GUID *in_R8;
  _GUID *in_R9;
  undefined1 auStackY_268 [32];
  _tlgWrapperByVal<4> *p_Var8;
  _tlgWrapSz<unsigned_short> *p_Var9;
  wchar_t *local_228;
  wchar_t *local_220;
  WDFDEVICE__ *local_218;
  WDFDEVICE_INIT *local_210;
  int local_208;
  undefined4 local_204;
  int local_200;
  undefined4 local_1fc;
  int local_1f8;
  undefined4 local_1f4;
  int local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  int local_1e0;
  undefined4 local_1dc;
  wchar_t *local_1d8;
  wchar_t *local_1d0;
  NETADAPTER__ *local_1c8;
  undefined4 local_1c0;
  undefined4 local_1bc;
  code *local_1b8;
  code *local_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined *local_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined *local_140;
  undefined4 local_138 [8];
  code *local_118;
  code *local_110;
  undefined4 local_f8 [2];
  code *local_f0;
  code *local_e0;
  code *local_d0;
  code *local_c8;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_268;
  local_210 = param_2;
  if (5 < DAT_1c000d1e0) {
    local_228 = L"EvtDriverDeviceAdd";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bef0,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_228);
  }
  p_Var7 = NetDriverGlobals;
  iVar1 = (*DAT_1c000d750)();
  if (iVar1 < 0) {
    if (DAT_1c000d1e0 < 3) goto LAB_1c0004753;
    local_228 = L"NetDeviceInitConfig(deviceInit)";
    local_204 = 0x57;
    p_Var8 = (_tlgWrapperByVal<4> *)&local_208;
    p_Var2 = (_tlgWrapperByVal<4> *)&local_204;
    local_208 = iVar1;
  }
  else {
    local_178 = PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068;
    local_198 = 0;
    uStack_1a0 = 0;
    local_1a8 = 0x38;
    uStack_190 = 0x100000001;
    local_188 = 0;
    uStack_180 = 0;
    memset(local_f8,0,0x90);
    local_d0 = EvtDevicePrepareHardware;
    local_c8 = EvtDeviceReleaseHardware;
    local_f0 = EvtDeviceD0Entry;
    local_e0 = EvtDeviceD0Exit;
    local_f8[0] = 0x90;
    (**(code **)(WdfFunctions_01021 + 0x1b8))(WdfDriverGlobals,local_210,local_f8);
    memset(local_138,0,0x40);
    local_118 = EvtDeviceArmWakeFromSx;
    local_110 = EvtDeviceDisarmWakeFromSx;
    local_138[0] = 0x40;
    (**(code **)(WdfFunctions_01021 + 0x1c0))(WdfDriverGlobals,local_210,local_138);
    in_R9 = (_GUID *)&local_218;
    local_218 = (WDFDEVICE__ *)0x0;
    in_R8 = (_GUID *)&local_1a8;
    p_Var7 = WdfDriverGlobals;
    iVar1 = (**(code **)(WdfFunctions_01021 + 600))(WdfDriverGlobals,&local_210);
    if (iVar1 < 0) {
      if (DAT_1c000d1e0 < 3) goto LAB_1c0004753;
      local_228 = L"WdfDeviceCreate(&deviceInit, &deviceAttributes, &wdfDevice)";
      local_1fc = 0x73;
      p_Var8 = (_tlgWrapperByVal<4> *)&local_200;
      p_Var2 = (_tlgWrapperByVal<4> *)&local_1fc;
      local_200 = iVar1;
    }
    else {
      (**(code **)(WdfFunctions_01021 + 0x1a8))(WdfDriverGlobals,local_218,0xff);
      in_R8 = (_GUID *)&local_50;
      local_44 = 0;
      local_50 = 0x24;
      local_3c = 0x200000002;
      uStack_34 = 0x200000000;
      local_4c = 1;
      local_48 = 4;
      local_40 = 2;
      p_Var7 = WdfDriverGlobals;
      iVar1 = (**(code **)(WdfFunctions_01021 + 0x170))(WdfDriverGlobals,local_218);
      if (iVar1 < 0) {
        if (DAT_1c000d1e0 < 3) goto LAB_1c0004753;
        local_228 = L"WdfDeviceAssignS0IdleSettings(wdfDevice, &idleSettings)";
        local_1f4 = 0x7c;
        p_Var8 = (_tlgWrapperByVal<4> *)&local_1f8;
        p_Var2 = (_tlgWrapperByVal<4> *)&local_1f4;
        local_1f8 = iVar1;
      }
      else {
        in_R8 = (_GUID *)&local_68;
        local_58 = 0;
        local_68 = 0x14;
        local_5c = 2;
        local_64 = 5;
        local_60 = 2;
        p_Var7 = WdfDriverGlobals;
        iVar1 = (**(code **)(WdfFunctions_01021 + 0x178))(WdfDriverGlobals,local_218);
        if (iVar1 < 0) {
          if (DAT_1c000d1e0 < 3) goto LAB_1c0004753;
          local_228 = L"WdfDeviceAssignSxWakeSettings(wdfDevice, &wakeSettings)";
          local_1ec = 0x83;
          p_Var8 = (_tlgWrapperByVal<4> *)&local_1f0;
          p_Var2 = (_tlgWrapperByVal<4> *)&local_1ec;
          local_1f0 = iVar1;
        }
        else {
          p_Var7 = NetDriverGlobals;
          lVar3 = (*NetFunctions)(NetDriverGlobals,local_218);
          if (lVar3 != 0) {
            local_1bc = 0;
            local_1b8 = EvtAdapterCreateTxQueue;
            local_1c0 = 0x18;
            local_1b0 = EvtAdapterCreateRxQueue;
            (*DAT_1c000d5f0)(NetDriverGlobals,lVar3,&local_1c0);
            in_R9 = (_GUID *)&local_1c8;
            in_R8 = (_GUID *)&local_170;
            local_1c8 = (NETADAPTER__ *)0x0;
            local_160 = 0;
            local_140 = PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018;
            uStack_168 = 0;
            local_170 = 0x38;
            local_150 = 0;
            uStack_148 = 0;
            uStack_158 = 0x100000001;
            p_Var7 = NetDriverGlobals;
            iVar1 = (*DAT_1c000d5f8)(NetDriverGlobals,lVar3);
            if (iVar1 < 0) {
              if (2 < DAT_1c000d1e0) {
                local_228 = L"NetAdapterCreate(adapterInit, &adapterAttributes, &netAdapter)";
                p_Var9 = (_tlgWrapSz<unsigned_short> *)&local_228;
                local_1dc = 0x98;
                p_Var8 = (_tlgWrapperByVal<4> *)&local_1e0;
                p_Var2 = (_tlgWrapperByVal<4> *)&local_1dc;
                p_Var6 = (_tlgWrapSz<unsigned_short> *)&local_220;
                local_220 = L"EvtDriverDeviceAdd";
                local_1e0 = iVar1;
                goto LAB_1c0004733;
              }
            }
            else {
              p_Var4 = (_RT_ADAPTER *)
                       (**(code **)(WdfFunctions_01021 + 0x650))
                                 (WdfDriverGlobals,local_1c8,PTR__WDF_RT_ADAPTER_TYPE_INFO_1c000d018
                                 );
              puVar5 = (undefined8 *)
                       (**(code **)(WdfFunctions_01021 + 0x650))
                                 (WdfDriverGlobals,local_218,PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068)
              ;
              *puVar5 = p_Var4;
              p_Var7 = (_tlgProvider_t *)p_Var4;
              in_R8 = (_GUID *)local_1c8;
              iVar1 = RtInitializeAdapterContext(p_Var4,local_218,local_1c8);
              if (iVar1 < 0) {
                if (2 < DAT_1c000d1e0) {
                  local_1d8 = (wchar_t *)CONCAT44(local_1d8._4_4_,iVar1);
                  local_228 = L"RtInitializeAdapterContext(adapter, wdfDevice, netAdapter)";
                  p_Var9 = (_tlgWrapSz<unsigned_short> *)&local_228;
                  local_1d0 = (wchar_t *)CONCAT44(local_1d0._4_4_,0xa0);
                  p_Var8 = (_tlgWrapperByVal<4> *)&local_1d8;
                  p_Var2 = (_tlgWrapperByVal<4> *)&local_1d0;
                  p_Var6 = (_tlgWrapSz<unsigned_short> *)&local_220;
                  local_220 = L"EvtDriverDeviceAdd";
LAB_1c0004733:
                  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
                  ::
                  Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
                            (p_Var7,&DAT_1c000be46,in_R8,in_R9,p_Var6,p_Var2,p_Var8,p_Var9);
                }
              }
              else {
                in_R8 = (_GUID *)(p_Var4 + 0x40);
                p_Var7 = (_tlgProvider_t *)local_218;
                iVar1 = RtInterruptCreate(local_218,p_Var4,(_RT_INTERRUPT **)in_R8);
                if ((iVar1 < 0) && (2 < DAT_1c000d1e0)) {
                  local_220 = (wchar_t *)CONCAT44(local_220._4_4_,iVar1);
                  local_1d0 = L"RtInterruptCreate(wdfDevice, adapter, &adapter->Interrupt)";
                  p_Var9 = (_tlgWrapSz<unsigned_short> *)&local_1d0;
                  local_228 = (wchar_t *)CONCAT44(local_228._4_4_,0xa3);
                  p_Var8 = (_tlgWrapperByVal<4> *)&local_220;
                  p_Var2 = (_tlgWrapperByVal<4> *)&local_228;
                  p_Var6 = (_tlgWrapSz<unsigned_short> *)&local_1d8;
                  local_1d8 = L"EvtDriverDeviceAdd";
                  goto LAB_1c0004733;
                }
              }
            }
            p_Var7 = NetDriverGlobals;
            (*DAT_1c000d5e8)(NetDriverGlobals,lVar3);
            goto LAB_1c0004753;
          }
          iVar1 = -0x3fffff66;
          if (DAT_1c000d1e0 < 3) goto LAB_1c0004753;
          local_1e8 = 0xc000009a;
          local_228 = L"(((adapterInit) == NULL) ? STATUS_INSUFFICIENT_RESOURCES : STATUS_SUCCESS)";
          local_1e4 = 0x87;
          p_Var8 = (_tlgWrapperByVal<4> *)&local_1e8;
          p_Var2 = (_tlgWrapperByVal<4> *)&local_1e4;
          iVar1 = -0x3fffff66;
        }
      }
    }
  }
  local_220 = L"EvtDriverDeviceAdd";
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
            (p_Var7,&DAT_1c000be46,in_R8,in_R9,(_tlgWrapSz<unsigned_short> *)&local_220,p_Var2,
             p_Var8,(_tlgWrapSz<unsigned_short> *)&local_228);
LAB_1c0004753:
  if (5 < DAT_1c000d1e0) {
    local_228 = (wchar_t *)CONCAT44(local_228._4_4_,iVar1);
    local_220 = L"EvtDriverDeviceAdd";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var7,&DAT_1c000be88,in_R8,in_R9,(_tlgWrapSz<unsigned_short> *)&local_220,
               (_tlgWrapperByVal<4> *)&local_228);
  }
  return iVar1;
}



===== EvtDriverUnload @ 1c00047c0 =====

/* void __cdecl EvtDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl EvtDriverUnload(WDFDRIVER__ *param_1)

{
  undefined8 uVar1;
  _GUID *in_R8;
  _GUID *in_R9;
  wchar_t *local_res10 [3];
  
  if (5 < DAT_1c000d1e0) {
    local_res10[0] = L"EvtDriverUnload";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bef0,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)local_res10);
  }
  uVar1 = DAT_1c000d200;
  DAT_1c000d200 = 0;
  DAT_1c000d1e0 = 0;
  EtwUnregister(uVar1);
  return;
}



===== _tlgDefineProvider_annotation__TlgRealtekTraceProviderProv @ 1c0004820 =====

void _tlgDefineProvider_annotation__TlgRealtekTraceProviderProv(void)

{
  return;
}



===== ClockLower @ 1c000482c =====

void ClockLower(longlong param_1)

{
  *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) =
       *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) & 0xfb;
  KeStallExecutionProcessor(0x10);
  return;
}



===== ClockRaise @ 1c0004864 =====

void ClockRaise(longlong param_1)

{
  *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) =
       *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) | 4;
  KeStallExecutionProcessor(0x10);
  return;
}



===== ReadEEPROM @ 1c000489c =====

ushort ReadEEPROM(longlong param_1,ushort param_2)

{
  ushort uVar1;
  longlong lVar2;
  ushort uVar3;
  
  *(undefined1 *)(*(longlong *)(param_1 + 0x530) + 0x50) = 0x80;
  ClockRaise(param_1);
  ClockLower(param_1);
  *(undefined1 *)(*(longlong *)(param_1 + 0x530) + 0x50) = 0x88;
  ShiftBitsOut(param_1,6,'\x03');
  ShiftBitsOut(param_1,param_2,'\x06');
  uVar3 = 0;
  lVar2 = 0x10;
  do {
    uVar1 = uVar3 * 2;
    ClockRaise(param_1);
    uVar3 = uVar1 | 1;
    if ((*(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) & 1) == 0) {
      uVar3 = uVar1;
    }
    ClockLower(param_1);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  ClockRaise(param_1);
  ClockLower(param_1);
  return uVar3;
}



===== ShiftBitsOut @ 1c0004978 =====

void ShiftBitsOut(longlong param_1,ushort param_2,char param_3)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = 1 << (param_3 - 1U & 0x1f);
  do {
    bVar3 = *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) & 0xfd;
    bVar1 = bVar3 | 2;
    if ((param_2 & uVar2) == 0) {
      bVar1 = bVar3;
    }
    *(byte *)(*(longlong *)(param_1 + 0x530) + 0x50) = bVar1;
    ClockRaise(param_1);
    ClockLower(param_1);
    uVar2 = uVar2 >> 1;
  } while (uVar2 != 0);
  return;
}



===== GigaMacWrite4 @ 1c00049f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 GigaMacWrite4(longlong param_1,ushort param_2,undefined4 param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x98));
  *(undefined4 *)(*(longlong *)(param_1 + 0x530) + 0x70) = param_3;
  uVar1 = 0;
  *(uint *)(*(longlong *)(param_1 + 0x530) + 0x74) = param_2 | 0x8000f000;
  uVar2 = 0;
  do {
    KeStallExecutionProcessor(100);
    if (-1 < *(int *)(*(longlong *)(param_1 + 0x530) + 0x74)) {
      KeStallExecutionProcessor(0x14);
      uVar1 = 1;
      break;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 10);
  (**(code **)(WdfFunctions_01021 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x98));
  return uVar1;
}



===== EvtInterruptDisable @ 1c0004ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtInterruptDisable(struct WDFINTERRUPT__ * __ptr64,struct WDFDEVICE__ * __ptr64) */

long __cdecl EvtInterruptDisable(WDFINTERRUPT__ *param_1,WDFDEVICE__ *param_2)

{
  _tlgProvider_t *p_Var1;
  longlong lVar2;
  _GUID *in_R8;
  _GUID *p_Var3;
  _GUID *in_R9;
  WDFINTERRUPT__ *local_res18;
  wchar_t *local_res20;
  
  if (5 < DAT_1c000d1e0) {
    local_res20 = L"EvtInterruptDisable";
    local_res18 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000c107,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<8> *)&local_res18);
  }
  p_Var3 = (_GUID *)PTR__WDF_RT_INTERRUPT_TYPE_INFO_1c000d1d0;
  lVar2 = (**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals);
  **(undefined2 **)(lVar2 + 0x48) = 0;
  **(undefined1 **)(lVar2 + 0x50) = 0;
  p_Var1 = *(_tlgProvider_t **)(lVar2 + 0x58);
  *p_Var1 = (_tlgProvider_t)0x0;
  **(undefined1 **)(lVar2 + 0x60) = 0;
  if (5 < DAT_1c000d1e0) {
    local_res18 = (WDFINTERRUPT__ *)0x1c000b4e0;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var1,&DAT_1c000c13c,p_Var3,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res18);
  }
  return 0;
}



===== EvtInterruptDpc @ 1c0004b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtInterruptDpc(struct WDFINTERRUPT__ * __ptr64,void * __ptr64) */

void __cdecl EvtInterruptDpc(WDFINTERRUPT__ *param_1,void *param_2)

{
  uint uVar1;
  int iVar2;
  _RT_ADAPTER *p_Var3;
  longlong lVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_INTERRUPT_TYPE_INFO_1c000d1d0);
  p_Var3 = (_RT_ADAPTER *)*plVar5;
  LOCK();
  uVar1 = *(uint *)(plVar5 + 0xd);
  *(uint *)(plVar5 + 0xd) = 0;
  UNLOCK();
  if ((uVar1 & 0x13) != 0) {
    LOCK();
    lVar4 = plVar5[2];
    *(int *)(plVar5 + 2) = 0;
    UNLOCK();
    if ((int)lVar4 != 0) {
      (*DAT_1c000d7b8)(NetDriverGlobals,*(undefined8 *)(*plVar5 + 0x20));
    }
  }
  if ((uVar1 >> 0x10 & 3) != 0) {
    LOCK();
    iVar2 = *(int *)((longlong)plVar5 + 0x14);
    *(int *)((longlong)plVar5 + 0x14) = 0;
    UNLOCK();
    if (iVar2 != 0) {
      (*DAT_1c000d7b8)(NetDriverGlobals,*(undefined8 *)(*plVar5 + 0x28));
    }
  }
  if ((uVar1 >> 0x12 & 3) != 0) {
    LOCK();
    lVar4 = plVar5[3];
    *(int *)(plVar5 + 3) = 0;
    UNLOCK();
    if ((int)lVar4 != 0) {
      (*DAT_1c000d7b8)(NetDriverGlobals,*(undefined8 *)(*plVar5 + 0x30));
    }
  }
  if ((uVar1 >> 0x14 & 3) != 0) {
    LOCK();
    iVar2 = *(int *)((longlong)plVar5 + 0x1c);
    *(int *)((longlong)plVar5 + 0x1c) = 0;
    UNLOCK();
    if (iVar2 != 0) {
      (*DAT_1c000d7b8)(NetDriverGlobals,*(undefined8 *)(*plVar5 + 0x38));
    }
  }
  if ((uVar1 & 0xc) != 0) {
    LOCK();
    lVar4 = plVar5[4];
    *(int *)(plVar5 + 4) = 0;
    UNLOCK();
    if ((int)lVar4 != 0) {
      (*DAT_1c000d7e0)(NetDriverGlobals,*(undefined8 *)(p_Var3 + 0x10));
    }
  }
  if ((uVar1 & 0x20) != 0) {
    RtAdapterNotifyLinkChange(p_Var3);
  }
  return;
}



===== EvtInterruptEnable @ 1c0004ce0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtInterruptEnable(struct WDFINTERRUPT__ * __ptr64,struct WDFDEVICE__ * __ptr64) */

long __cdecl EvtInterruptEnable(WDFINTERRUPT__ *param_1,WDFDEVICE__ *param_2)

{
  int iVar1;
  ushort *puVar2;
  _GUID *p_Var3;
  ushort uVar4;
  ushort uVar5;
  _GUID *in_R8;
  undefined *puVar6;
  ulonglong uVar7;
  _GUID *in_R9;
  WDFINTERRUPT__ *local_res18;
  wchar_t *local_res20;
  
  if (5 < DAT_1c000d1e0) {
    local_res20 = L"EvtInterruptEnable";
    local_res18 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000c107,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<8> *)&local_res18);
  }
  puVar6 = PTR__WDF_RT_INTERRUPT_TYPE_INFO_1c000d1d0;
  p_Var3 = (_GUID *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  puVar2 = *(ushort **)(p_Var3 + 0x48);
  uVar7 = CONCAT62((int6)((ulonglong)puVar6 >> 0x10),-(ushort)(*(int *)(p_Var3 + 0x20) != 0)) &
          0xffffffffffff000c;
  uVar5 = (short)uVar7 + 0x20;
  uVar4 = uVar5 | 0x13;
  if (*(int *)(p_Var3 + 0x10) == 0) {
    uVar4 = uVar5;
  }
  *puVar2 = uVar4;
  **(byte **)(p_Var3 + 0x50) = -(*(int *)(p_Var3 + 0x14) != 0) & 3;
  **(byte **)(p_Var3 + 0x58) = -(*(int *)(p_Var3 + 0x18) != 0) & 3;
  iVar1 = *(int *)(p_Var3 + 0x1c);
  **(byte **)(p_Var3 + 0x60) = -(iVar1 != 0) & 3;
  if (5 < DAT_1c000d1e0) {
    local_res18 = (WDFINTERRUPT__ *)0x1c000b4b8;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)
               (CONCAT71((int7)((ulonglong)puVar2 >> 8),-(iVar1 != 0)) & 0xffffffffffffff03),
               &DAT_1c000c13c,(_GUID *)CONCAT62((int6)(uVar7 >> 0x10),uVar5),p_Var3,
               (_tlgWrapSz<unsigned_short> *)&local_res18);
  }
  return 0;
}



===== EvtInterruptIsr @ 1c0004de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl EvtInterruptIsr(struct WDFINTERRUPT__ * __ptr64,unsigned long) */

uchar __cdecl EvtInterruptIsr(WDFINTERRUPT__ *param_1,ulong param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  plVar5 = (longlong *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  plVar5[0xe] = plVar5[0xe] + 1;
  uVar1 = *(ushort *)plVar5[5];
  if (uVar1 == 0xffff) {
    plVar5[0x10] = plVar5[0x10] + 1;
  }
  else {
    uVar10 = 0;
    if (*(longlong *)(*plVar5 + 0x28) != 0) {
      uVar10 = (uint)*(byte *)plVar5[6];
    }
    uVar9 = 0;
    if (*(longlong *)(*plVar5 + 0x30) != 0) {
      uVar9 = (uint)*(byte *)plVar5[7];
    }
    uVar8 = 0;
    if (*(longlong *)(*plVar5 + 0x38) != 0) {
      uVar8 = (uint)*(byte *)plVar5[8];
    }
    if (uVar1 != 0) {
      *(ushort *)plVar5[5] = uVar1;
    }
    if (uVar10 != 0) {
      *(char *)plVar5[6] = (char)uVar10;
    }
    if (uVar9 != 0) {
      *(char *)plVar5[7] = (char)uVar9;
    }
    if (uVar8 != 0) {
      *(char *)plVar5[8] = (char)uVar8;
    }
    uVar8 = uVar8 & 3;
    uVar9 = uVar9 & 3;
    uVar10 = uVar10 & 3;
    uVar6 = ((uVar8 * 4 | uVar9) << 2 | uVar10) << 0x10 | (uint)(uVar1 & 0x7f);
    if (uVar6 != 0) {
      LOCK();
      *(uint *)(plVar5 + 0xd) = *(uint *)(plVar5 + 0xd) | uVar6;
      UNLOCK();
      uVar7 = (-(ushort)((int)plVar5[4] != 0) & 0xc) + 0x20;
      if ((int)plVar5[2] != 0) {
        uVar7 = (-(ushort)((int)plVar5[4] != 0) & 0xc) + 0x33;
      }
      iVar2 = *(int *)((longlong)plVar5 + 0x14);
      lVar4 = plVar5[3];
      iVar3 = *(int *)((longlong)plVar5 + 0x1c);
      *(ushort *)plVar5[9] = ~(uVar1 & 0x7f) & uVar7 | 0x20;
      if ((*(longlong *)(*plVar5 + 0x28) != 0) &&
         (*(byte *)plVar5[10] = -(iVar2 != 0) & 3U & ~(byte)uVar10, uVar10 != 0)) {
        plVar5[0x12] = plVar5[0x12] + 1;
      }
      if ((*(longlong *)(*plVar5 + 0x30) != 0) &&
         (*(byte *)plVar5[0xb] = -((int)lVar4 != 0) & 3U & ~(byte)uVar9, uVar9 != 0)) {
        plVar5[0x13] = plVar5[0x13] + 1;
      }
      if ((*(longlong *)(*plVar5 + 0x38) != 0) &&
         (*(byte *)plVar5[0xc] = -(iVar3 != 0) & 3U & ~(byte)uVar8, uVar8 != 0)) {
        plVar5[0x14] = plVar5[0x14] + 1;
      }
      if ((uVar1 & 0xc) != 0) {
        plVar5[0x15] = plVar5[0x15] + 1;
      }
      if ((uVar1 & 0x13) != 0) {
        plVar5[0x11] = plVar5[0x11] + 1;
      }
      (**(code **)(WdfFunctions_01021 + 0x470))(WdfDriverGlobals,param_1);
      return '\x01';
    }
    plVar5[0xf] = plVar5[0xf] + 1;
  }
  return '\0';
}



===== RtCalculateImr @ 1c0005008 =====

byte RtCalculateImr(longlong param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = 0;
  if (param_2 == 0) {
    bVar1 = (-(*(int *)(param_1 + 0x20) != 0) & 0xcU) + 0x20;
    bVar2 = bVar1 | 0x13;
    if (*(int *)(param_1 + 0x10) == 0) {
      bVar2 = bVar1;
    }
  }
  else if (*(int *)(param_1 + 0x10 + (ulonglong)param_2 * 4) != 0) {
    bVar2 = 3;
  }
  return bVar2;
}



===== RtInterruptCreate @ 1c0005050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RtInterruptCreate(struct WDFDEVICE__ * __ptr64,struct _RT_ADAPTER * __ptr64,struct
   _RT_INTERRUPT * __ptr64 * __ptr64) */

long __cdecl RtInterruptCreate(WDFDEVICE__ *param_1,_RT_ADAPTER *param_2,_RT_INTERRUPT **param_3)

{
  int iVar1;
  _RT_INTERRUPT *p_Var2;
  _tlgProvider_t *p_Var3;
  _GUID *p_Var4;
  _GUID *in_R9;
  _GUID *p_Var5;
  undefined8 local_res18;
  wchar_t *local_res20;
  undefined8 local_d8;
  wchar_t *local_d0;
  wchar_t *local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined *local_90;
  undefined4 local_88 [4];
  undefined4 local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  undefined4 local_2c;
  
  if (5 < DAT_1c000d1e0) {
    local_res18 = *(undefined8 *)param_2;
    local_res20 = L"RtInterruptCreate";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bebd,(_GUID *)param_3,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<8> *)&local_res18);
  }
  *param_3 = (_RT_INTERRUPT *)0x0;
  local_b0 = 0;
  uStack_a8 = 0x100000001;
  uStack_b8 = 0;
  local_90 = PTR__WDF_RT_INTERRUPT_TYPE_INFO_1c000d1d0;
  local_a0 = 0;
  uStack_98 = 0;
  local_c0 = 0x38;
  memset(local_88,0,0x68);
  local_d8 = 0;
  local_70 = EvtInterruptIsr;
  local_88[0] = 0x68;
  local_68 = EvtInterruptDpc;
  p_Var5 = (_GUID *)&local_c0;
  local_78 = 2;
  local_60 = EvtInterruptEnable;
  p_Var4 = (_GUID *)local_88;
  local_2c = 2;
  local_58 = EvtInterruptDisable;
  p_Var3 = WdfDriverGlobals;
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x468))
                    (WdfDriverGlobals,param_1,p_Var4,p_Var5,&local_d8);
  if (iVar1 < 0) {
    if (2 < DAT_1c000d1e0) {
      local_res18 = CONCAT44(local_res18._4_4_,iVar1);
      local_d0 = L"WdfInterruptCreate(wdfDevice, &config, &attributes, &wdfInterrupt)";
      local_res20 = (wchar_t *)CONCAT44(local_res20._4_4_,0x7e);
      local_c8 = L"RtInterruptCreate";
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
                (p_Var3,&DAT_1c000be46,p_Var4,p_Var5,(_tlgWrapSz<unsigned_short> *)&local_c8,
                 (_tlgWrapperByVal<4> *)&local_res20,(_tlgWrapperByVal<4> *)&local_res18,
                 (_tlgWrapSz<unsigned_short> *)&local_d0);
    }
  }
  else {
    p_Var4 = (_GUID *)PTR__WDF_RT_INTERRUPT_TYPE_INFO_1c000d1d0;
    p_Var2 = (_RT_INTERRUPT *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,local_d8);
    *param_3 = p_Var2;
    *(_RT_ADAPTER **)p_Var2 = param_2;
    p_Var3 = (_tlgProvider_t *)*param_3;
    *(undefined8 *)(p_Var3 + 8) = local_d8;
  }
  if (5 < DAT_1c000d1e0) {
    local_res18 = CONCAT44(local_res18._4_4_,iVar1);
    local_res20 = L"RtInterruptCreate";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var3,&DAT_1c000be88,p_Var4,p_Var5,(_tlgWrapSz<unsigned_short> *)&local_res20,
               (_tlgWrapperByVal<4> *)&local_res18);
  }
  return iVar1;
}



===== RtUpdateImr @ 1c0005244 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RtUpdateImr(struct _RT_INTERRUPT * __ptr64,unsigned long) */

void __cdecl RtUpdateImr(_RT_INTERRUPT *param_1,ulong param_2)

{
  byte bVar1;
  undefined7 extraout_var;
  
  (**(code **)(WdfFunctions_01021 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
  bVar1 = RtCalculateImr((longlong)param_1,param_2);
  if (param_2 == 0) {
    **(undefined2 **)(param_1 + 0x48) = (short)CONCAT71(extraout_var,bVar1);
  }
  else {
    **(byte **)(param_1 + (ulonglong)param_2 * 8 + 0x48) = bVar1;
  }
  (**(code **)(WdfFunctions_01021 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
  return;
}



===== RtAdapterNotifyLinkChange @ 1c00052c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl RtAdapterNotifyLinkChange(struct _RT_ADAPTER * __ptr64) */

void __cdecl RtAdapterNotifyLinkChange(_RT_ADAPTER *param_1)

{
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x98));
  RtAdapterQueryLinkState(param_1,(_NET_ADAPTER_LINK_STATE *)&local_38);
  (**(code **)(WdfFunctions_01021 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x98));
  (*DAT_1c000d658)(NetDriverGlobals,*(undefined8 *)param_1,&local_38);
  return;
}



===== RtAdapterPushPhySettings @ 1c0005378 =====

/* void __cdecl RtAdapterPushPhySettings(struct _RT_ADAPTER * __ptr64) */

void __cdecl RtAdapterPushPhySettings(_RT_ADAPTER *param_1)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  RtAdapterWritePhyUint16(param_1,'\x1f',0);
  uVar2 = RtAdapterReadPhyUint16(param_1,'\t');
  uVar2 = uVar2 & 0xfcff;
  uVar3 = RtAdapterReadPhyUint16(param_1,'\x04');
  iVar1 = *(int *)(param_1 + 0x538);
  uVar3 = uVar3 & 0xf21f;
  if (iVar1 == 0) {
    uVar3 = uVar3 | 0x1e0;
    uVar4 = 0x300;
LAB_1c0005413:
    uVar2 = uVar2 | uVar4;
  }
  else if (iVar1 == 1) {
    uVar3 = uVar3 | 0x20;
  }
  else if (iVar1 == 2) {
    uVar3 = uVar3 | 0x40;
  }
  else {
    if (iVar1 == 3) {
      uVar4 = 0x80;
    }
    else {
      if (iVar1 != 4) {
        if (iVar1 == 6) {
          uVar4 = 0x200;
          goto LAB_1c0005413;
        }
        goto LAB_1c0005416;
      }
      uVar4 = 0x100;
    }
    uVar3 = uVar3 | uVar4;
  }
LAB_1c0005416:
  iVar1 = *(int *)(param_1 + 0x5b4);
  if (iVar1 == 1) {
    uVar4 = 0x800;
  }
  else if (iVar1 == 2) {
    uVar4 = 0x400;
  }
  else {
    if (iVar1 != 3) goto LAB_1c0005442;
    uVar4 = 0xc00;
  }
  uVar3 = uVar3 | uVar4;
LAB_1c0005442:
  RtAdapterWritePhyUint16(param_1,'\x04',uVar3);
  RtAdapterWritePhyUint16(param_1,'\t',uVar2);
  return;
}



===== RtAdapterQueryLinkState @ 1c000546c =====

/* void __cdecl RtAdapterQueryLinkState(struct _RT_ADAPTER * __ptr64,struct _NET_ADAPTER_LINK_STATE
   * __ptr64) */

void __cdecl RtAdapterQueryLinkState(_RT_ADAPTER *param_1,_NET_ADAPTER_LINK_STATE *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  ushort uVar5;
  _RT_ADAPTER *p_Var6;
  undefined4 uVar7;
  uint uVar8;
  _GUID *in_R8;
  _GUID *p_Var9;
  _GUID *in_R9;
  _RT_ADAPTER _Var10;
  wchar_t *local_res8;
  wchar_t *local_res10;
  
  if (5 < DAT_1c000d1e0) {
    local_res8 = *(wchar_t **)param_1;
    local_res10 = L"RtAdapterQueryLinkState";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000bebd,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res10,(_tlgWrapperByVal<8> *)&local_res8);
  }
  iVar2 = *(int *)(param_1 + 0x5b4);
  uVar8 = -(uint)(param_1[0x564] != (_RT_ADAPTER)0x0) & 7;
  if (iVar2 != 0) {
    uVar8 = uVar8 | 8;
  }
  uVar7 = 4;
  _Var10 = (_RT_ADAPTER)0x1;
  if (iVar2 == 0) {
    uVar7 = 0;
  }
  else if (iVar2 == 1) {
    uVar7 = 1;
  }
  else if (iVar2 == 2) {
    uVar7 = 2;
  }
  else if (iVar2 == 3) {
    uVar7 = 3;
  }
  uVar3 = *(undefined4 *)(param_1 + 0xa8);
  p_Var9 = (_GUID *)0x0;
  p_Var6 = param_1;
  RtAdapterWritePhyUint16(param_1,'\x1f',0);
  if ((*(byte *)(*(longlong *)(param_1 + 0x530) + 0x6c) & 2) == 0) {
    param_1[0x564] = (_RT_ADAPTER)0x0;
  }
  else {
    uVar4 = RtAdapterReadPhyUint16(param_1,'\x06');
    uVar5 = RtAdapterReadPhyUint16(param_1,'\x01');
    if (((uVar4 & 1) == 0) || ((uVar5 & 0x20) == 0)) {
      _Var10 = (_RT_ADAPTER)0x0;
    }
    param_1[0x564] = _Var10;
    p_Var6 = param_1;
    RtAdapterUpdateLinkStatus(param_1);
  }
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x530) + 0x6c);
  uVar4 = *(ushort *)(param_1 + 0xa4);
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0x28;
  *(undefined4 *)(param_2 + 0x1c) = uVar3;
  *(undefined4 *)(param_2 + 0x20) = uVar7;
  *(uint *)(param_2 + 0x24) = uVar8;
  *(longlong *)(param_2 + 8) = (longlong)(int)((uint)uVar4 * 1000000);
  *(longlong *)(param_2 + 0x10) = (longlong)(int)((uint)uVar4 * 1000000);
  *(uint *)(param_2 + 0x18) = 2 - (uint)((bVar1 & 2) != 0);
  if (5 < DAT_1c000d1e0) {
    local_res8 = L"RtAdapterQueryLinkState";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)p_Var6,&DAT_1c000c13c,p_Var9,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res8);
  }
  return;
}



===== RtAdapterUpdateLinkStatus @ 1c00055f8 =====

/* void __cdecl RtAdapterUpdateLinkStatus(struct _RT_ADAPTER * __ptr64) */

void __cdecl RtAdapterUpdateLinkStatus(_RT_ADAPTER *param_1)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x538);
  uVar4 = 0;
  if ((iVar2 == 1) || (iVar2 == 2)) {
    uVar3 = 10;
  }
  else if ((iVar2 == 3) || (iVar2 == 4)) {
    uVar3 = 100;
  }
  else if (iVar2 == 6) {
    uVar3 = 1000;
  }
  else {
    uVar3 = 0;
  }
  *(undefined2 *)(param_1 + 0xa4) = uVar3;
  if (iVar2 == 1) {
LAB_1c0005672:
    uVar4 = 1;
  }
  else {
    if (iVar2 != 2) {
      if (iVar2 == 3) goto LAB_1c0005672;
      if ((iVar2 != 4) && (iVar2 != 6)) goto LAB_1c0005677;
    }
    uVar4 = 2;
  }
LAB_1c0005677:
  *(undefined4 *)(param_1 + 0xa8) = uVar4;
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x530) + 0x6c);
  if ((bVar1 & 0x10) == 0) {
    if ((bVar1 & 8) == 0) {
      if ((bVar1 & 4) != 0) {
        *(undefined2 *)(param_1 + 0xa4) = 10;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0xa4) = 100;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0xa4) = 1000;
  }
  *(uint *)(param_1 + 0xa8) = (bVar1 & 1) + 1;
  return;
}



===== RtAdapterReadPhyUint16 @ 1c00056d0 =====

/* unsigned short __cdecl RtAdapterReadPhyUint16(struct _RT_ADAPTER * __ptr64,unsigned char) */

ushort __cdecl RtAdapterReadPhyUint16(_RT_ADAPTER *param_1,uchar param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 0xffff;
  uVar3 = 0;
  *(uint *)(*(longlong *)(param_1 + 0x530) + 0x60) = (uint)param_2 << 0x10;
  iVar2 = *(int *)(*(longlong *)(param_1 + 0x530) + 0x60);
  do {
    if (iVar2 < 0) {
      uVar1 = (ushort)iVar2;
      break;
    }
    KeStallExecutionProcessor(0x32);
    uVar3 = uVar3 + 1;
    iVar2 = *(int *)(*(longlong *)(param_1 + 0x530) + 0x60);
  } while (uVar3 < 0x14);
  KeStallExecutionProcessor(0x14);
  return uVar1;
}



===== RtAdapterWritePhyUint16 @ 1c000575c =====

/* void __cdecl RtAdapterWritePhyUint16(struct _RT_ADAPTER * __ptr64,unsigned char,unsigned short)
    */

void __cdecl RtAdapterWritePhyUint16(_RT_ADAPTER *param_1,uchar param_2,ushort param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  *(uint *)(*(longlong *)(param_1 + 0x530) + 0x60) = (param_2 | 0xffff8000) << 0x10 | (uint)param_3;
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x530) + 0x60);
  do {
    if (-1 < iVar1) break;
    KeStallExecutionProcessor(0x32);
    uVar2 = uVar2 + 1;
    iVar1 = *(int *)(*(longlong *)(param_1 + 0x530) + 0x60);
  } while (uVar2 < 0x14);
  KeStallExecutionProcessor(0x14);
  return;
}



===== EvtDeviceArmWakeFromSx @ 1c00057e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtDeviceArmWakeFromSx(struct WDFDEVICE__ * __ptr64) */

long __cdecl EvtDeviceArmWakeFromSx(WDFDEVICE__ *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong *plVar3;
  _GUID *p_Var4;
  undefined8 uVar5;
  _tlgProvider_t *p_Var6;
  _GUID *p_Var7;
  _GUID *p_Var8;
  _GUID *in_R9;
  wchar_t *local_res10;
  wchar_t *local_res18 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  p_Var6 = WdfDriverGlobals;
  p_Var8 = (_GUID *)PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068;
  plVar3 = (longlong *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  puVar1 = (undefined8 *)*plVar3;
  if (5 < DAT_1c000d1e0) {
    local_res10 = (wchar_t *)*puVar1;
    local_res18[0] = L"EvtDeviceArmWakeFromSx";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              (p_Var6,&DAT_1c000bebd,p_Var8,in_R9,(_tlgWrapSz<unsigned_short> *)local_res18,
               (_tlgWrapperByVal<8> *)&local_res10);
  }
  p_Var8 = (_GUID *)&local_48;
  local_28 = 0;
  uStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (*DAT_1c000d820)(NetDriverGlobals,param_1);
  p_Var7 = (_GUID *)0x0;
  while( true ) {
    p_Var6 = NetDriverGlobals;
    p_Var4 = (_GUID *)(*DAT_1c000d828)(NetDriverGlobals,&local_48);
    if (p_Var4 <= p_Var7) break;
    p_Var8 = p_Var7;
    uVar5 = (*DAT_1c000d830)(NetDriverGlobals,&local_48);
    iVar2 = (*DAT_1c000d800)(NetDriverGlobals,uVar5);
    if (iVar2 == 2) {
      *(byte *)(puVar1[0xa6] + 0x50) = *(byte *)(puVar1[0xa6] + 0x50) | 0xc0;
      *(byte *)(puVar1[0xa6] + 0x54) = *(byte *)(puVar1[0xa6] + 0x54) | 0x20;
      *(byte *)(puVar1[0xa6] + 0x50) = *(byte *)(puVar1[0xa6] + 0x50) & 0x3f;
    }
    p_Var7 = p_Var7 + 1;
  }
  if (5 < DAT_1c000d1e0) {
    local_res10 = L"EvtDeviceArmWakeFromSx";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var6,&DAT_1c000c13c,p_Var8,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res10);
  }
  return 0;
}



===== EvtDeviceD0Entry @ 1c0005960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl EvtDeviceD0Entry(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl EvtDeviceD0Entry(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  _RT_ADAPTER *p_Var1;
  longlong lVar2;
  undefined8 *puVar3;
  ushort uVar4;
  _GUID *p_Var5;
  _GUID *in_R9;
  undefined1 auStackY_b8 [32];
  _WDF_POWER_DEVICE_STATE local_88 [2];
  wchar_t *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  wchar_t *local_58;
  undefined8 local_50;
  wchar_t **local_48;
  undefined8 local_40;
  _WDF_POWER_DEVICE_STATE *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  p_Var5 = (_GUID *)PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068;
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  uVar4 = 0;
  p_Var1 = (_RT_ADAPTER *)*puVar3;
  if (5 < DAT_1c000d1e0) {
    local_80 = *(wchar_t **)p_Var1;
    local_38 = local_88;
    in_R9 = (_GUID *)0x0;
    local_48 = &local_80;
    local_30 = 4;
    p_Var5 = (_GUID *)0x0;
    local_40 = 8;
    local_58 = L"EvtDeviceD0Entry";
    local_50 = 0x22;
    local_88[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c000d1e0,&DAT_1c000c162,0,0,5,&local_78);
  }
  lVar2 = *(longlong *)(p_Var1 + 0x40);
  **(undefined2 **)(lVar2 + 0x48) = 0;
  **(undefined1 **)(lVar2 + 0x50) = 0;
  **(undefined1 **)(lVar2 + 0x58) = 0;
  **(undefined1 **)(lVar2 + 0x60) = 0;
  RtAdapterUpdateHardwareChecksum(p_Var1);
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(p_Var1 + 0x98));
  if ((p_Var1[0x590] == (_RT_ADAPTER)0x0) && (*(int *)(p_Var1 + 0x588) != 0)) {
    if (*(int *)(p_Var1 + 0x58c) == 0) {
      uVar4 = 3;
      *(undefined1 *)(*(longlong *)(p_Var1 + 0x530) + 0xe2) = 0x30;
      *(undefined1 *)(*(longlong *)(p_Var1 + 0x530) + 0xe3) = 0x50;
    }
    else if (*(int *)(p_Var1 + 0x58c) == 1) {
      uVar4 = 3;
      *(undefined1 *)(*(longlong *)(p_Var1 + 0x530) + 0xe2) = 0xf0;
      *(undefined1 *)(*(longlong *)(p_Var1 + 0x530) + 0xe3) = 0xf0;
    }
  }
  else {
    *(undefined1 *)(*(longlong *)(p_Var1 + 0x530) + 0xe2) = 0;
    *(undefined1 *)(*(longlong *)(p_Var1 + 0x530) + 0xe3) = 0;
  }
  uVar4 = *(ushort *)(*(longlong *)(p_Var1 + 0x530) + 0xe0) & 0xfffc | uVar4;
  if (*(ushort *)(*(longlong *)(p_Var1 + 0x530) + 0xe0) != uVar4) {
    *(ushort *)(*(longlong *)(p_Var1 + 0x530) + 0xe0) = uVar4;
  }
  (**(code **)(WdfFunctions_01021 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var1 + 0x98));
  if (param_2 != 5) {
    RtAdapterRaiseToD0(p_Var1);
    RtAdapterPushMulticastList(p_Var1);
    local_58 = (wchar_t *)0x0;
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    uStack_60 = 0;
    RtAdapterQueryLinkState(p_Var1,(_NET_ADAPTER_LINK_STATE *)&local_78);
    p_Var5 = (_GUID *)&local_78;
    (*DAT_1c000d658)(NetDriverGlobals,*(undefined8 *)p_Var1);
  }
  *(undefined2 *)(*(longlong *)(p_Var1 + 0x530) + 0xda) = 0x5f2;
  if (5 < DAT_1c000d1e0) {
    local_80 = L"EvtDeviceD0Entry";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)0x5f2,&DAT_1c000c13c,p_Var5,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_80);
  }
  return 0;
}



===== EvtDeviceD0Exit @ 1c0005bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl EvtDeviceD0Exit(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl EvtDeviceD0Exit(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  _tlgProvider_t *p_Var3;
  _GUID *p_Var4;
  _GUID *in_R9;
  undefined1 auStackY_78 [32];
  wchar_t *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  p_Var3 = WdfDriverGlobals;
  p_Var4 = (_GUID *)PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068;
  plVar2 = (longlong *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  puVar1 = (undefined8 *)*plVar2;
  if (5 < DAT_1c000d1e0) {
    local_48 = L"EvtDeviceD0Exit";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var3,&DAT_1c000bef0,p_Var4,in_R9,(_tlgWrapSz<unsigned_short> *)&local_48);
  }
  if (param_2 != 5) {
    p_Var4 = (_GUID *)&local_40;
    local_3c = 0;
    local_38 = 0xffffffffffffffff;
    local_30 = 0xffffffffffffffff;
    local_40 = 0x28;
    local_28 = 0;
    uStack_20 = 4;
    (*DAT_1c000d658)(NetDriverGlobals,*puVar1);
    p_Var3 = (_tlgProvider_t *)(ulonglong)*(ushort *)(puVar1[0xa6] + 0x3e);
    *(ushort *)(puVar1[0xa6] + 0x3e) = *(ushort *)(puVar1[0xa6] + 0x3e);
  }
  if (5 < DAT_1c000d1e0) {
    local_48 = L"EvtDeviceD0Exit";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var3,&DAT_1c000c13c,p_Var4,in_R9,(_tlgWrapSz<unsigned_short> *)&local_48);
  }
  return 0;
}



===== EvtDeviceDisarmWakeFromSx @ 1c0005d10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtDeviceDisarmWakeFromSx(struct WDFDEVICE__ * __ptr64) */

void __cdecl EvtDeviceDisarmWakeFromSx(WDFDEVICE__ *param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  _tlgProvider_t *p_Var3;
  _GUID *p_Var4;
  _GUID *in_R9;
  wchar_t *local_res10;
  wchar_t *local_res18 [2];
  
  p_Var3 = WdfDriverGlobals;
  p_Var4 = (_GUID *)PTR__WDF_RT_DEVICE_TYPE_INFO_1c000d068;
  plVar2 = (longlong *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  puVar1 = (undefined8 *)*plVar2;
  if (5 < DAT_1c000d1e0) {
    local_res10 = (wchar_t *)*puVar1;
    local_res18[0] = L"EvtDeviceDisarmWakeFromSx";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              (p_Var3,&DAT_1c000bebd,p_Var4,in_R9,(_tlgWrapSz<unsigned_short> *)local_res18,
               (_tlgWrapperByVal<8> *)&local_res10);
  }
  *(byte *)(puVar1[0xa6] + 0x50) = *(byte *)(puVar1[0xa6] + 0x50) | 0xc0;
  *(byte *)(puVar1[0xa6] + 0x54) = *(byte *)(puVar1[0xa6] + 0x54) & 0xdf;
  p_Var3 = (_tlgProvider_t *)
           (CONCAT71((int7)((ulonglong)p_Var3 >> 8),*(undefined1 *)(puVar1[0xa6] + 0x50)) &
           0xffffffffffffff3f);
  *(char *)(puVar1[0xa6] + 0x50) = (char)p_Var3;
  if (5 < DAT_1c000d1e0) {
    local_res10 = L"EvtDeviceDisarmWakeFromSx";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var3,&DAT_1c000c13c,p_Var4,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res10);
  }
  return;
}



===== RtAdapterRaiseToD0 @ 1c0005df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RtAdapterRaiseToD0(struct _RT_ADAPTER * __ptr64) */

void __cdecl RtAdapterRaiseToD0(_RT_ADAPTER *param_1)

{
  ushort uVar1;
  int iVar2;
  
  *(byte *)(*(longlong *)(param_1 + 0x530) + 0xf3) =
       *(byte *)(*(longlong *)(param_1 + 0x530) + 0xf3) | 4;
  *(byte *)(*(longlong *)(param_1 + 0x530) + 0xd1) =
       *(byte *)(*(longlong *)(param_1 + 0x530) + 0xd1) | 0x82;
  RtAdapterIssueFullReset(param_1);
  RtAdapterWritePhyUint16(param_1,'\x1f',0);
  RtAdapterWritePhyUint16(param_1,'\x0e',0);
  RtAdapterWritePhyUint16(param_1,'\0',0x1000);
  RtAdapterWritePhyUint16(param_1,'\x1f',0);
  RtAdapterWritePhyUint16(param_1,'\0',0x9000);
  iVar2 = 5000;
  do {
    uVar1 = RtAdapterReadPhyUint16(param_1,'\0');
    if (-1 < (short)uVar1) break;
    KeStallExecutionProcessor(0x14);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  RtAdapterIssueFullReset(param_1);
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x98));
  RtAdapterSetupCurrentAddress(param_1);
  (**(code **)(WdfFunctions_01021 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x98));
  RtAdapterPushPhySettings(param_1);
  RtAdapterWritePhyUint16(param_1,'\x1f',0);
  RtAdapterWritePhyUint16(param_1,'\0',0x1200);
  return;
}



===== EvtRxQueueAdvance @ 1c0005f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtRxQueueAdvance(struct NETPACKETQUEUE__ * __ptr64) */

void __cdecl EvtRxQueueAdvance(NETPACKETQUEUE__ *param_1)

{
  _GUID *p_Var1;
  ushort uVar2;
  RT_RXQUEUE *pRVar3;
  _tlgProvider_t *p_Var4;
  undefined2 *puVar5;
  _GUID *in_R8;
  uint uVar6;
  _GUID *in_R9;
  _GUID *p_Var7;
  uint uVar8;
  NETPACKETQUEUE__ *local_res10;
  wchar_t *local_res18 [2];
  
  if (5 < DAT_1c000d1e0) {
    local_res18[0] = L"EvtRxQueueAdvance";
    local_res10 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000c1ea,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)local_res18,(_tlgWrapperByVal<8> *)&local_res10);
  }
  pRVar3 = (RT_RXQUEUE *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040);
  RxIndicateReceives(pRVar3);
  p_Var4 = *(_tlgProvider_t **)(pRVar3 + 0x10);
  p_Var1 = *(_GUID **)(p_Var4 + 8);
  p_Var7 = (_GUID *)(ulonglong)*(uint *)(p_Var1 + 0x34);
  if (*(uint *)(p_Var1 + 0x34) != *(uint *)(p_Var1 + 0xc)) {
    uVar8 = *(uint *)(p_Var1 + 8);
    do {
      puVar5 = (undefined2 *)((longlong)p_Var7 * 0x10 + *(longlong *)(pRVar3 + 0x20));
      *(undefined8 *)(puVar5 + 4) =
           *(undefined8 *)
            ((longlong)p_Var7 * *(longlong *)(pRVar3 + 0x88) + *(longlong *)(pRVar3 + 0x80));
      *puVar5 = 0x5f2;
      puVar5[2] = 0;
      LOCK();
      UNLOCK();
      uVar2 = 0x4000;
      p_Var4 = (_tlgProvider_t *)0x8000;
      if (uVar8 != (uint)p_Var7) {
        uVar2 = 0;
      }
      puVar5[1] = uVar2 | 0x8000;
      uVar8 = *(uint *)(p_Var1 + 8);
      uVar6 = *(int *)(p_Var1 + 0x34) + 1U & uVar8;
      p_Var7 = (_GUID *)(ulonglong)uVar6;
      *(uint *)(p_Var1 + 0x34) = uVar6;
    } while (uVar6 != *(uint *)(p_Var1 + 0xc));
  }
  if (5 < DAT_1c000d1e0) {
    local_res10 = (NETPACKETQUEUE__ *)0x1c000b758;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var4,&DAT_1c000c13c,p_Var1,p_Var7,(_tlgWrapSz<unsigned_short> *)&local_res10);
  }
  return;
}



===== EvtRxQueueCancel @ 1c0006070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtRxQueueCancel(struct NETPACKETQUEUE__ * __ptr64) */

void __cdecl EvtRxQueueCancel(NETPACKETQUEUE__ *param_1)

{
  byte *pbVar1;
  longlong lVar2;
  _tlgProvider_t *p_Var3;
  uint uVar4;
  RT_RXQUEUE *pRVar5;
  _GUID *in_R8;
  _GUID *p_Var6;
  _GUID *in_R9;
  NETPACKETQUEUE__ *local_res10;
  wchar_t *local_res18;
  
  if (5 < DAT_1c000d1e0) {
    local_res18 = L"EvtRxQueueCancel";
    local_res10 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000c1ea,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res18,(_tlgWrapperByVal<8> *)&local_res10);
  }
  p_Var6 = (_GUID *)PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040;
  pRVar5 = (RT_RXQUEUE *)(**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  lVar2 = *(longlong *)pRVar5;
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x98));
  *(undefined4 *)(*(longlong *)(lVar2 + 0x530) + 0x44) = 0x700;
  pbVar1 = (byte *)(*(longlong *)(lVar2 + 0x530) + 0x37);
  *pbVar1 = *pbVar1 & 0xf7;
  (**(code **)(WdfFunctions_01021 + 0x9e8))
            (WdfDriverGlobals,*(undefined8 *)(*(longlong *)pRVar5 + 0x98));
  RxIndicateReceives(pRVar5);
  lVar2 = **(longlong **)(pRVar5 + 0x10);
  uVar4 = *(uint *)(lVar2 + 0x30);
  while (uVar4 != *(uint *)(lVar2 + 0xc)) {
    pbVar1 = (byte *)((ulonglong)*(ushort *)(lVar2 + 2) * (ulonglong)uVar4 + 0x4b + lVar2);
    *pbVar1 = *pbVar1 | 1;
    uVar4 = *(int *)(lVar2 + 0x30) + 1U & *(uint *)(lVar2 + 8);
    *(uint *)(lVar2 + 0x30) = uVar4;
  }
  p_Var3 = *(_tlgProvider_t **)(*(longlong *)(pRVar5 + 0x10) + 8);
  *(undefined4 *)(p_Var3 + 0x30) = *(undefined4 *)(p_Var3 + 0xc);
  if (5 < DAT_1c000d1e0) {
    local_res10 = (NETPACKETQUEUE__ *)0x1c000b780;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var3,&DAT_1c000c13c,p_Var6,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res10);
  }
  return;
}



===== EvtRxQueueDestroy @ 1c00061c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtRxQueueDestroy(void * __ptr64) */

void __cdecl EvtRxQueueDestroy(void *param_1)

{
  longlong lVar1;
  _tlgProvider_t *p_Var2;
  _GUID *in_R8;
  _GUID *p_Var3;
  _GUID *in_R9;
  wchar_t *local_res8;
  wchar_t *local_res10;
  
  if (5 < DAT_1c000d1e0) {
    local_res10 = L"EvtRxQueueDestroy";
    local_res8 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              (param_1,&DAT_1c000c1ea,in_R8,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res10,
               (_tlgWrapperByVal<8> *)&local_res8);
  }
  p_Var3 = (_GUID *)PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040;
  lVar1 = (**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  p_Var2 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x18));
  *(undefined8 *)(lVar1 + 0x18) = 0;
  if (5 < DAT_1c000d1e0) {
    local_res8 = L"EvtRxQueueDestroy";
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var2,&DAT_1c000c13c,p_Var3,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res8);
  }
  return;
}



===== EvtRxQueueSetNotificationEnabled @ 1c0006290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtRxQueueSetNotificationEnabled(struct NETPACKETQUEUE__ * __ptr64,unsigned char) */

void __cdecl EvtRxQueueSetNotificationEnabled(NETPACKETQUEUE__ *param_1,uchar param_2)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  _RT_INTERRUPT *p_Var4;
  _GUID *in_R8;
  _GUID *p_Var5;
  _GUID *in_R9;
  _tlgWrapperByVal<1> local_res10 [8];
  NETPACKETQUEUE__ *local_res18;
  wchar_t *local_res20;
  
  if (5 < DAT_1c000d1e0) {
    local_res20 = L"EvtRxQueueSetNotificationEnabled";
    local_res10[0] = (_tlgWrapperByVal<1>)param_2;
    local_res18 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000c1a4,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<8> *)&local_res18,
               local_res10);
  }
  lVar3 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040);
  LOCK();
  puVar1 = (uint *)(*(longlong *)(lVar3 + 8) + 0x10 + (ulonglong)*(uint *)(lVar3 + 0xd0) * 4);
  uVar2 = *puVar1;
  *puVar1 = (uint)param_2;
  p_Var5 = (_GUID *)(ulonglong)uVar2;
  UNLOCK();
  p_Var4 = *(_RT_INTERRUPT **)(lVar3 + 8);
  RtUpdateImr(p_Var4,*(ulong *)(lVar3 + 0xd0));
  if (param_2 == '\0') {
    KeFlushQueuedDpcs();
  }
  if (5 < DAT_1c000d1e0) {
    local_res18 = (NETPACKETQUEUE__ *)0x1c000b710;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)p_Var4,&DAT_1c000c13c,p_Var5,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res18);
  }
  return;
}



===== EvtRxQueueStart @ 1c0006370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtRxQueueStart(struct NETPACKETQUEUE__ * __ptr64) */

void __cdecl EvtRxQueueStart(NETPACKETQUEUE__ *param_1)

{
  byte *pbVar1;
  longlong lVar2;
  code *pcVar3;
  char cVar4;
  longlong *plVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined1 *puVar8;
  ushort uVar9;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040);
  lVar2 = *plVar5;
  memset((void *)plVar5[4],0,plVar5[5]);
  uVar6 = (**(code **)(WdfFunctions_01021 + 0xb8))(WdfDriverGlobals,plVar5[3]);
  puVar8 = auStack_38;
  uVar7 = *(uint *)(plVar5 + 0x1a);
  if (uVar7 == 0) {
    *(int *)(*(longlong *)(lVar2 + 0x530) + 0xe4) = (int)uVar6;
    *(int *)(*(longlong *)(lVar2 + 0x530) + 0xe8) = (int)((ulonglong)uVar6 >> 0x20);
  }
  else {
    if (uVar7 == 0) {
      pcVar3 = (code *)swi(0x2c);
      uVar6 = (*pcVar3)();
      puVar8 = auStack_30;
    }
    else {
      puVar8 = auStack_38;
      if (3 < uVar7) {
        pcVar3 = (code *)swi(0x2c);
        uVar6 = (*pcVar3)();
        puVar8 = auStack_30;
      }
    }
    uVar9 = 0;
    if (uVar7 == 1) {
      uVar9 = 0xd0;
    }
    else if (uVar7 == 2) {
      uVar9 = 0xd8;
    }
    else if (uVar7 == 3) {
      uVar9 = 0xe0;
    }
    *(undefined8 *)(puVar8 + -8) = 0x1c000645e;
    cVar4 = GigaMacWrite4(lVar2,uVar9,(int)uVar6);
    if (cVar4 != '\0') {
      *(undefined8 *)(puVar8 + -8) = 0x1c0006473;
      GigaMacWrite4(lVar2,uVar9 + 4,*(undefined4 *)(puVar8 + 0x44));
    }
  }
  uVar6 = *(undefined8 *)(lVar2 + 0x98);
  pcVar3 = *(code **)(WdfFunctions_01021 + 0x9e0);
  *(undefined8 *)(puVar8 + -8) = 0x1c0006494;
  (*pcVar3)(WdfDriverGlobals,uVar6);
  if ((*(byte *)(*(longlong *)(lVar2 + 0x530) + 0x37) & 8) == 0) {
    pbVar1 = (byte *)(*(longlong *)(lVar2 + 0x530) + 0x37);
    *pbVar1 = *pbVar1 | 8;
  }
  *(NETPACKETQUEUE__ **)(lVar2 + 0x20 + (ulonglong)*(uint *)(plVar5 + 0x1a) * 8) = param_1;
  uVar7 = *(uint *)(lVar2 + 0xa0);
  if ((uVar7 & 0x20) == 0) {
    uVar7 = (uVar7 * 2 | uVar7) & 4 | (uVar7 & 1) * 2 | uVar7 & 8;
  }
  else {
    uVar7 = 0x3f;
  }
  *(uint *)(*(longlong *)(lVar2 + 0x530) + 0x44) = uVar7 | 0x700;
  uVar6 = *(undefined8 *)(lVar2 + 0x98);
  pcVar3 = *(code **)(WdfFunctions_01021 + 0x9e8);
  *(undefined8 *)(puVar8 + -8) = 0x1c0006510;
  (*pcVar3)(WdfDriverGlobals,uVar6);
  return;
}



===== EvtRxQueueStop @ 1c0006530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtRxQueueStop(struct NETPACKETQUEUE__ * __ptr64) */

void __cdecl EvtRxQueueStop(NETPACKETQUEUE__ *param_1)

{
  byte *pbVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  
  plVar3 = (longlong *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040);
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals);
  plVar6 = (longlong *)(*plVar3 + 0x20);
  lVar7 = 4;
  lVar5 = 0;
  do {
    lVar2 = *plVar6;
    plVar6 = plVar6 + 1;
    lVar4 = lVar5 + 1;
    if (lVar2 == 0) {
      lVar4 = lVar5;
    }
    lVar7 = lVar7 + -1;
    lVar5 = lVar4;
  } while (lVar7 != 0);
  if (lVar4 == 1) {
    pbVar1 = (byte *)(*(longlong *)(*plVar3 + 0x530) + 0x37);
    *pbVar1 = *pbVar1 & 0xf7;
  }
  LOCK();
  *(undefined4 *)(plVar3[1] + 0x10 + (ulonglong)*(uint *)(plVar3 + 0x1a) * 4) = 0;
  UNLOCK();
  RtUpdateImr((_RT_INTERRUPT *)plVar3[1],*(ulong *)(plVar3 + 0x1a));
  KeFlushQueuedDpcs();
  *(undefined8 *)(*plVar3 + 0x20 + (ulonglong)*(uint *)(plVar3 + 0x1a) * 8) = 0;
  (**(code **)(WdfFunctions_01021 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(*plVar3 + 0x98));
  return;
}



===== RtRxQueueInitialize @ 1c0006624 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RtRxQueueInitialize(struct NETPACKETQUEUE__ * __ptr64,struct _RT_ADAPTER * __ptr64)
    */

long __cdecl RtRxQueueInitialize(NETPACKETQUEUE__ *param_1,_RT_ADAPTER *param_2)

{
  undefined8 uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  _tlgProvider_t *p_Var5;
  long lVar6;
  _GUID *p_Var7;
  _GUID *p_Var8;
  _GUID *p_Var9;
  int local_res10 [2];
  undefined4 local_res18 [2];
  wchar_t *local_res20;
  wchar_t *local_28 [2];
  
  plVar2 = (longlong *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_RXQUEUE_TYPE_INFO_1c000d040);
  uVar1 = NetDriverGlobals;
  *plVar2 = (longlong)param_2;
  plVar2[1] = *(longlong *)(param_2 + 0x40);
  plVar3 = (longlong *)(*DAT_1c000d7c8)(uVar1,param_1);
  plVar2[2] = (longlong)plVar3;
  p_Var9 = (_GUID *)0x0;
  p_Var7 = (_GUID *)(ulonglong)(uint)(*(int *)(*plVar3 + 4) << 4);
  p_Var5 = WdfDriverGlobals;
  p_Var8 = p_Var7;
  local_res10[0] =
       (**(code **)(WdfFunctions_01021 + 0xa8))
                 (WdfDriverGlobals,*(undefined8 *)(*plVar2 + 0x540),p_Var7,0,plVar2 + 3);
  lVar6 = local_res10[0];
  if (local_res10[0] < 0) {
    if (2 < DAT_1c000d1e0) {
      local_res20 = 
      L"WdfCommonBufferCreate( rx->Adapter->DmaEnabler, rxdSize, WDF_NO_OBJECT_ATTRIBUTES, &rx->RxdArray)"
      ;
      local_res18[0] = 0x16c;
      local_28[0] = L"RtRxQueueInitialize";
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
                (p_Var5,&DAT_1c000be46,p_Var8,p_Var9,(_tlgWrapSz<unsigned_short> *)local_28,
                 (_tlgWrapperByVal<4> *)local_res18,(_tlgWrapperByVal<4> *)local_res10,
                 (_tlgWrapSz<unsigned_short> *)&local_res20);
    }
  }
  else {
    lVar4 = (**(code **)(WdfFunctions_01021 + 0xb0))(WdfDriverGlobals,plVar2[3]);
    plVar2[4] = lVar4;
    plVar2[5] = (longlong)p_Var7;
  }
  return lVar6;
}



===== RxFillRtl8111DChecksumInfo @ 1c0006778 =====

void RxFillRtl8111DChecksumInfo(longlong *param_1,longlong param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  ushort uVar2;
  ushort uVar3;
  byte *pbVar4;
  
  lVar1 = *param_1;
  pbVar4 = (byte *)((ulonglong)param_3 * param_1[7] + param_1[6]);
  *pbVar4 = ((*(byte *)(param_2 + 2) & 8) != 0) + 1U | *pbVar4 & 0xfc;
  uVar2 = *(ushort *)(param_2 + 6);
  if ((uVar2 >> 0xe & 1) == 0) {
    if (-1 < (short)uVar2) {
      return;
    }
    *(byte *)(param_4 + 9) = *(byte *)(param_4 + 9) & 0xf | 0x40;
  }
  else {
    *(byte *)(param_4 + 9) = *(byte *)(param_4 + 9) & 0xf | 0x10;
    if (*(char *)(lVar1 + 0x56d) != '\0') {
      *pbVar4 = ((*(byte *)(param_2 + 2) & 1) + 1) * '\x04' | *pbVar4 & 0xf3;
    }
  }
  if ((*(ushort *)(param_2 + 2) & 2) == 0) {
    if ((*(ushort *)(param_2 + 2) & 4) == 0) {
      return;
    }
    *(byte *)(param_4 + 10) = *(byte *)(param_4 + 10) & 0xf2 | 2;
    if (*(char *)(lVar1 + 0x56f) == '\0') {
      return;
    }
    uVar2 = *(ushort *)(param_2 + 6);
    uVar3 = 0x400;
  }
  else {
    *(byte *)(param_4 + 10) = *(byte *)(param_4 + 10) & 0xf1 | 1;
    if (*(char *)(lVar1 + 0x56e) == '\0') {
      return;
    }
    uVar2 = *(ushort *)(param_2 + 6);
    uVar3 = 0x200;
  }
  *pbVar4 = (-((uVar2 & uVar3) != 0) & 0x10U) + 0x10 | *pbVar4 & 0xcf;
  return;
}



===== RxFillRtl8111EChecksumInfo @ 1c000686c =====

void RxFillRtl8111EChecksumInfo(longlong *param_1,ushort *param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  byte bVar2;
  byte *pbVar3;
  
  lVar1 = *param_1;
  pbVar3 = (byte *)((ulonglong)param_3 * param_1[7] + param_1[6]);
  *pbVar3 = ((param_2[1] & 8) != 0) + 1U | *pbVar3 & 0xfc;
  if ((param_2[3] & 0x4000) == 0) {
    if (-1 < (short)param_2[3]) {
      return;
    }
    *(byte *)(param_4 + 9) = *(byte *)(param_4 + 9) & 0xf | 0x40;
  }
  else {
    *(byte *)(param_4 + 9) = *(byte *)(param_4 + 9) & 0xf | 0x10;
    if (*(char *)(lVar1 + 0x56d) != '\0') {
      *pbVar3 = (((byte)param_2[1] & 1) + 1) * '\x04' | *pbVar3 & 0xf3;
    }
  }
  if ((param_2[1] & 2) == 0) {
    if ((param_2[1] & 4) == 0) {
      return;
    }
    *(byte *)(param_4 + 10) = *(byte *)(param_4 + 10) & 0xf2 | 2;
    if (*(char *)(lVar1 + 0x56f) == '\0') {
      return;
    }
    bVar2 = (((byte)((short)*param_2 >> 0xf) & 1) + 1) * '\x10';
  }
  else {
    *(byte *)(param_4 + 10) = *(byte *)(param_4 + 10) & 0xf1 | 1;
    if (*(char *)(lVar1 + 0x56e) == '\0') {
      return;
    }
    bVar2 = (-((*param_2 & 0x4000) != 0) & 0x10U) + 0x10;
  }
  *pbVar3 = bVar2 | *pbVar3 & 0xcf;
  return;
}



===== RxIndicateReceives @ 1c0006960 =====

/* void __cdecl RxIndicateReceives(struct RT_RXQUEUE * __ptr64) */

void __cdecl RxIndicateReceives(RT_RXQUEUE *param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  ushort uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  ushort *puVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  longlong lVar13;
  uint uVar14;
  ulonglong uVar15;
  ushort uVar16;
  undefined8 uVar17;
  undefined1 auStack_48 [32];
  
  puVar11 = auStack_48;
  lVar3 = (*(longlong **)(param_1 + 0x10))[1];
  lVar4 = **(longlong **)(param_1 + 0x10);
  uVar14 = *(uint *)(lVar3 + 0x30);
  if (uVar14 != *(uint *)(lVar3 + 0x34)) {
    uVar17 = 0x11;
    do {
      uVar8 = (ulonglong)uVar14;
      puVar10 = (ushort *)(uVar8 * 0x10 + *(longlong *)(param_1 + 0x20));
      if ((short)puVar10[1] < 0) {
        return;
      }
      if (*(int *)(lVar4 + 0x30) == *(int *)(lVar4 + 0xc)) {
        return;
      }
      if (uVar14 == *(uint *)(lVar3 + 0xc)) {
        pcVar6 = (code *)swi(0x2c);
        uVar15 = uVar8;
        (*pcVar6)();
        uVar14 = (uint)uVar15;
        puVar11 = puVar11 + 8;
      }
      lVar13 = *(ushort *)(lVar3 + 2) * uVar8;
      uVar8 = (ulonglong)(*puVar10 & 0x3fff) - 4;
      *(ulonglong *)(lVar13 + 0x40 + lVar3) =
           (uVar8 ^ *(ulonglong *)(lVar13 + 0x40 + lVar3)) & 0xc000000000000000 ^
           uVar8 * 0x4000000 & 0xffffffc000000 ^ uVar8 & 0xc000000003ffffff;
      uVar1 = *(uint *)(lVar4 + 0x30);
      lVar13 = (ulonglong)*(ushort *)(lVar4 + 2) * (ulonglong)uVar1 + lVar4;
      *(uint *)(lVar13 + 0x40) = uVar14;
      *(undefined2 *)(lVar13 + 0x44) = 1;
      if (param_1[0x50] != (RT_RXQUEUE)0x0) {
        *(undefined4 *)(lVar13 + 0x46) = 0;
        *(undefined1 *)(lVar13 + 0x4a) = 0;
        iVar2 = *(int *)(*(longlong *)param_1 + 0x560);
        if (iVar2 == 1) {
          *(undefined8 *)(puVar11 + -8) = 0x1c0006a8f;
          RxFillRtl8111DChecksumInfo((longlong *)param_1,(longlong)puVar10,uVar1,lVar13 + 0x40);
        }
        else {
          if ((iVar2 != 2) && (iVar2 != 3)) goto LAB_1c0006a95;
          *(undefined8 *)(puVar11 + -8) = 0x1c0006a7e;
          RxFillRtl8111EChecksumInfo((longlong *)param_1,puVar10,uVar1,lVar13 + 0x40);
        }
        uVar17 = 0x11;
      }
LAB_1c0006a95:
      if ((param_1[200] != (RT_RXQUEUE)0x0) && (*(char *)(*(longlong *)param_1 + 0x593) != '\0')) {
        uVar16 = 0;
        puVar12 = (undefined4 *)
                  ((ulonglong)uVar1 * *(longlong *)(param_1 + 0xb0) + *(longlong *)(param_1 + 0xa8))
        ;
        *(undefined2 *)(puVar12 + 1) = 0;
        *puVar12 = 0;
        if ((puVar10[3] & 2) != 0) {
          *(undefined2 *)(puVar12 + 1) = 1;
          uVar16 = 1;
          if ((puVar10[3] & 8) != 0) {
            uVar16 = (ushort)uVar17;
            *(ushort *)(puVar12 + 1) = uVar16;
          }
        }
        uVar7 = uVar16;
        if ((puVar10[3] & 4) != 0) {
          uVar7 = uVar16 | 4;
          *(ushort *)(puVar12 + 1) = uVar7;
          if ((puVar10[3] & 8) != 0) {
            uVar7 = uVar16 | 0x14;
            *(ushort *)(puVar12 + 1) = uVar7;
          }
        }
        if (uVar7 != 0) {
          uVar16 = *puVar10;
          lVar5 = *(longlong *)
                   ((ulonglong)*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 0x30) *
                    *(longlong *)(param_1 + 0x60) + *(longlong *)(param_1 + 0x58));
          puVar9 = (undefined1 *)(lVar5 + 3 + (ulonglong)(uVar16 & 0x3fff));
          *(undefined1 *)puVar12 = *puVar9;
          *(undefined1 *)((longlong)puVar12 + 1) = puVar9[-1];
          *(undefined1 *)((longlong)puVar12 + 2) = puVar9[-2];
          *(undefined1 *)((longlong)puVar12 + 3) =
               *(undefined1 *)(lVar5 + (ulonglong)(uVar16 & 0x3fff));
        }
      }
      *(byte *)(lVar13 + 0x49) = *(byte *)(lVar13 + 0x49) & 0xf2 | 2;
      *(uint *)(lVar4 + 0x30) = *(int *)(lVar4 + 0x30) + 1U & *(uint *)(lVar4 + 8);
      uVar14 = *(int *)(lVar3 + 0x30) + 1U & *(uint *)(lVar3 + 8);
      *(uint *)(lVar3 + 0x30) = uVar14;
    } while (uVar14 != *(uint *)(lVar3 + 0x34));
  }
  return;
}



===== EvtTxQueueAdvance @ 1c0006bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtTxQueueAdvance(struct NETPACKETQUEUE__ * __ptr64) */

void __cdecl EvtTxQueueAdvance(NETPACKETQUEUE__ *param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  _tlgProvider_t *p_Var5;
  ulonglong uVar6;
  _tlgProvider_t *p_Var7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  _GUID *in_R8;
  _GUID *p_Var11;
  _GUID *in_R9;
  NETPACKETQUEUE__ *local_res10;
  wchar_t *local_res18;
  
  if (5 < DAT_1c000d1e0) {
    local_res18 = L"EvtTxQueueAdvance";
    local_res10 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000c260,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res18,(_tlgWrapperByVal<8> *)&local_res10);
  }
  p_Var5 = (_tlgProvider_t *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_TXQUEUE_TYPE_INFO_1c000d090);
  p_Var7 = p_Var5;
  RtTransmitPackets((longlong *)p_Var5);
  plVar3 = *(longlong **)(p_Var5 + 0x10);
  lVar8 = *plVar3;
  uVar2 = *(uint *)(lVar8 + 0x34);
  puVar1 = (uint *)(lVar8 + 0x30);
  for (uVar10 = *puVar1; p_Var11 = (_GUID *)(ulonglong)uVar10, uVar10 != uVar2;
      uVar10 = *(uint *)(lVar8 + 8) & uVar10 + 1) {
    in_R9 = (_GUID *)((ulonglong)*(ushort *)(lVar8 + 2) * (longlong)p_Var11);
    if (((byte)in_R9[lVar8 + 0x4b] & 1) == 0) {
      lVar4 = *(longlong *)(p_Var5 + 0x18);
      uVar9 = (ulonglong)*(ushort *)(lVar4 + (longlong)p_Var11 * 8);
      p_Var7 = (_tlgProvider_t *)(uVar9 * 2);
      if (*(short *)(*(longlong *)(p_Var5 + 0x28) + 2 + uVar9 * 0x10) < 0) break;
      uVar9 = 0;
      in_R9 = (_GUID *)(ulonglong)*(uint *)(in_R9 + lVar8 + 0x40);
      p_Var7 = (_tlgProvider_t *)plVar3[1];
      if (*(int *)(lVar4 + 4 + (longlong)p_Var11 * 8) != 0) {
        do {
          uVar6 = *(ushort *)(lVar4 + (longlong)p_Var11 * 8) + uVar9;
          uVar9 = uVar9 + 1;
          *(undefined2 *)
           (*(longlong *)(p_Var5 + 0x28) + 2 +
           (uVar6 % (ulonglong)*(ushort *)(p_Var5 + 0x38)) * 0x10) = 0;
          p_Var7 = (_tlgProvider_t *)plVar3[1];
          in_R9 = (_GUID *)(ulonglong)(*(uint *)(p_Var7 + 8) & (int)in_R9 + 1U);
        } while (uVar9 < *(uint *)(lVar4 + 4 + (longlong)p_Var11 * 8));
      }
      *(int *)(p_Var7 + 0x30) = (int)in_R9;
    }
    lVar8 = *plVar3;
  }
  *puVar1 = uVar10;
  if (5 < DAT_1c000d1e0) {
    local_res10 = (NETPACKETQUEUE__ *)0x1c000b7a8;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              (p_Var7,&DAT_1c000c13c,p_Var11,in_R9,(_tlgWrapSz<unsigned_short> *)&local_res10);
  }
  return;
}



===== EvtTxQueueCancel @ 1c0006d30 =====

/* void __cdecl EvtTxQueueCancel(struct NETPACKETQUEUE__ * __ptr64) */

void __cdecl EvtTxQueueCancel(NETPACKETQUEUE__ *param_1)

{
  _GUID *in_R8;
  _GUID *in_R9;
  NETPACKETQUEUE__ *local_res10;
  wchar_t *local_res18 [2];
  
  if (5 < DAT_1c000d1e0) {
    local_res18[0] = L"EvtTxQueueCancel";
    local_res10 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000c260,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)local_res18,(_tlgWrapperByVal<8> *)&local_res10);
    if (5 < DAT_1c000d1e0) {
      local_res10 = (NETPACKETQUEUE__ *)0x1c000ba18;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::Write<_tlgWrapSz<unsigned_short>_>
                ((_tlgProvider_t *)param_1,&DAT_1c000c13c,in_R8,in_R9,
                 (_tlgWrapSz<unsigned_short> *)&local_res10);
    }
  }
  return;
}



===== EvtTxQueueDestroy @ 1c0006da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtTxQueueDestroy(void * __ptr64) */

void __cdecl EvtTxQueueDestroy(void *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RT_TXQUEUE_TYPE_INFO_1c000d090);
  (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20));
  *(undefined8 *)(lVar1 + 0x20) = 0;
  return;
}



===== EvtTxQueueSetNotificationEnabled @ 1c0006e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtTxQueueSetNotificationEnabled(struct NETPACKETQUEUE__ * __ptr64,unsigned char) */

void __cdecl EvtTxQueueSetNotificationEnabled(NETPACKETQUEUE__ *param_1,uchar param_2)

{
  longlong lVar1;
  _RT_INTERRUPT *p_Var2;
  _GUID *in_R8;
  _GUID *p_Var3;
  _GUID *in_R9;
  _tlgWrapperByVal<1> local_res10 [8];
  NETPACKETQUEUE__ *local_res18;
  wchar_t *local_res20;
  
  if (5 < DAT_1c000d1e0) {
    local_res20 = L"EvtTxQueueSetNotificationEnabled";
    local_res10[0] = (_tlgWrapperByVal<1>)param_2;
    local_res18 = param_1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>_>
              ((_tlgProvider_t *)param_1,&DAT_1c000c21a,in_R8,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res20,(_tlgWrapperByVal<8> *)&local_res18,
               local_res10);
  }
  p_Var3 = (_GUID *)PTR__WDF_RT_TXQUEUE_TYPE_INFO_1c000d090;
  lVar1 = (**(code **)(WdfFunctions_01021 + 0x650))(WdfDriverGlobals,param_1);
  LOCK();
  *(uint *)(*(longlong *)(lVar1 + 8) + 0x20) = (uint)param_2;
  UNLOCK();
  p_Var2 = *(_RT_INTERRUPT **)(lVar1 + 8);
  RtUpdateImr(p_Var2,0);
  if (param_2 == '\0') {
    KeFlushQueuedDpcs();
  }
  if (5 < DAT_1c000d1e0) {
    local_res18 = (NETPACKETQUEUE__ *)0x1c000b9d0;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>_>
              ((_tlgProvider_t *)p_Var2,&DAT_1c000c13c,p_Var3,in_R9,
               (_tlgWrapSz<unsigned_short> *)&local_res18);
  }
  return;
}



===== EvtTxQueueStart @ 1c0006ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtTxQueueStart(struct NETPACKETQUEUE__ * __ptr64) */

void __cdecl EvtTxQueueStart(NETPACKETQUEUE__ *param_1)

{
  byte *pbVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_TXQUEUE_TYPE_INFO_1c000d090);
  lVar2 = *plVar4;
  memset((void *)plVar4[5],0,plVar4[6]);
  *(undefined2 *)((longlong)plVar4 + 0x3a) = 0;
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x98));
  *(undefined1 *)(*(longlong *)(lVar2 + 0x530) + 0x57) = 8;
  *(undefined1 *)(*(longlong *)(lVar2 + 0x530) + 0xec) = 0xc;
  uVar5 = (**(code **)(WdfFunctions_01021 + 0xb8))(WdfDriverGlobals,plVar4[4]);
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  if (*(char *)((longlong)plVar4 + 0x114) == '@') {
    *(int *)(*(longlong *)(lVar2 + 0x530) + 0x20) = (int)uVar5;
    *(undefined4 *)(*(longlong *)(lVar2 + 0x530) + 0x24) = uVar3;
  }
  else if (*(char *)((longlong)plVar4 + 0x114) == -0x80) {
    *(int *)(*(longlong *)(lVar2 + 0x530) + 0x28) = (int)uVar5;
    *(undefined4 *)(*(longlong *)(lVar2 + 0x530) + 0x2c) = uVar3;
  }
  pbVar1 = (byte *)(*(longlong *)(lVar2 + 0x530) + 0x37);
  *pbVar1 = *pbVar1 | 4;
  *(undefined4 *)(*(longlong *)(lVar2 + 0x530) + 0x40) = 0x3000701;
  *(NETPACKETQUEUE__ **)(lVar2 + 0x10 + (ulonglong)*(uint *)(plVar4 + 0x22) * 8) = param_1;
  (**(code **)(WdfFunctions_01021 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x98));
  return;
}



===== EvtTxQueueStop @ 1c0007020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtTxQueueStop(struct NETPACKETQUEUE__ * __ptr64) */

void __cdecl EvtTxQueueStop(NETPACKETQUEUE__ *param_1)

{
  byte *pbVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  
  plVar3 = (longlong *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_TXQUEUE_TYPE_INFO_1c000d090);
  (**(code **)(WdfFunctions_01021 + 0x9e0))(WdfDriverGlobals);
  plVar6 = (longlong *)(*plVar3 + 0x10);
  lVar7 = 2;
  lVar5 = 0;
  do {
    lVar2 = *plVar6;
    plVar6 = plVar6 + 1;
    lVar4 = lVar5 + 1;
    if (lVar2 == 0) {
      lVar4 = lVar5;
    }
    lVar7 = lVar7 + -1;
    lVar5 = lVar4;
  } while (lVar7 != 0);
  if (lVar4 == 1) {
    pbVar1 = (byte *)(*(longlong *)(*plVar3 + 0x530) + 0x37);
    *pbVar1 = *pbVar1 & 0xfb;
    LOCK();
    *(undefined4 *)(plVar3[1] + 0x20) = 0;
    UNLOCK();
    RtUpdateImr((_RT_INTERRUPT *)plVar3[1],0);
    KeFlushQueuedDpcs();
  }
  *(undefined8 *)(*plVar3 + 0x10 + (ulonglong)*(uint *)(plVar3 + 0x22) * 8) = 0;
  (**(code **)(WdfFunctions_01021 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(*plVar3 + 0x98));
  return;
}



===== RtProgramOffloadDescriptor @ 1c0007108 =====

short RtProgramOffloadDescriptor(longlong *param_1,longlong param_2,longlong param_3,uint param_4)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  byte *pbVar7;
  byte bVar8;
  ushort *puVar9;
  ulonglong uVar10;
  byte bVar11;
  
  uVar10 = (ulonglong)param_4;
  *(undefined2 *)(param_3 + 6) = 0;
  lVar1 = *param_1;
  if (((char)param_1[0x12] == '\0') ||
     ((*(char *)(lVar1 + 0x5b8) != '\x01' && (*(char *)(lVar1 + 0x5b9) != '\x01')))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (((char)param_1[0xd] == '\0') ||
     (((*(char *)(lVar1 + 0x56b) == '\0' && (*(char *)(lVar1 + 0x56a) == '\0')) &&
      (*(char *)(lVar1 + 0x56c) == '\0')))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if ((char)param_1[0x21] != '\0') {
    *(undefined2 *)(param_3 + 6) = 2;
    puVar9 = (ushort *)(uVar10 * param_1[0x1e] + param_1[0x1d]);
    if ((puVar9[1] & 1) != 0) {
      *(ushort *)(param_3 + 4) =
           (*puVar9 << 5 ^ *(ushort *)(param_3 + 4)) & 0xe0 ^ *(ushort *)(param_3 + 4);
    }
    if ((puVar9[1] & 2) != 0) {
      uVar4 = *puVar9;
      *(char *)(param_3 + 5) = (char)(uVar4 >> 3);
      *(ushort *)(param_3 + 4) =
           (uVar4 >> 0xb ^ *(ushort *)(param_3 + 4)) & 0xf ^ *(ushort *)(param_3 + 4);
    }
  }
  bVar8 = *(byte *)(param_2 + 10);
  if ((((bVar8 & 0xf) == 1) && (bVar2)) &&
     (sVar6 = *(short *)(uVar10 * param_1[0xf] + param_1[0xe]), sVar6 != 0)) {
    bVar8 = *(byte *)(param_2 + 9) >> 4;
    if ((byte)(bVar8 - 1) < 3) {
      uVar4 = 0x100;
    }
    else {
      if (((bVar8 - 4 & 0xfd) != 0) && (bVar8 != 5)) {
        sVar5 = 0;
        goto LAB_1c000725d;
      }
      uVar4 = 0x80;
    }
    sVar5 = ((*(ushort *)(param_2 + 6) & 0x7f) + (*(ushort *)(param_2 + 6) >> 7) | uVar4) << 2;
LAB_1c000725d:
    *(short *)(param_3 + 6) = sVar6 << 2;
    return sVar5;
  }
  if (!bVar3) {
    return 0;
  }
  bVar11 = *(byte *)(param_2 + 9) >> 4;
  pbVar7 = (byte *)(uVar10 * param_1[10] + param_1[9]);
  if ((byte)(bVar11 - 1) < 3) {
    bVar11 = *pbVar7;
    if ((bVar11 & 0x30) == 0x20) {
      if ((bVar8 & 0xf) == 1) {
        sVar6 = 0x6000;
        goto LAB_1c000731c;
      }
      if ((bVar8 & 0xf) == 2) {
        sVar6 = -0x6000;
        goto LAB_1c000731c;
      }
    }
    if ((bVar11 & 0xc) == 8) {
      sVar6 = 0x2000;
      goto LAB_1c000731c;
    }
  }
  else if ((((bVar11 - 4 & 0xfd) == 0) || (bVar11 == 5)) && ((*pbVar7 & 0x30) == 0x20)) {
    if ((bVar8 & 0xf) == 1) {
      uVar4 = 0x1400;
    }
    else {
      if ((bVar8 & 0xf) != 2) goto LAB_1c0007319;
      uVar4 = 0xe400;
    }
    sVar6 = ((*(ushort *)(param_2 + 6) & 0x7f) + (*(ushort *)(param_2 + 6) >> 7) | uVar4) << 2;
    goto LAB_1c000731c;
  }
LAB_1c0007319:
  sVar6 = 0;
LAB_1c000731c:
  *(short *)(param_3 + 6) = sVar6;
  return 0;
}



===== RtTransmitPackets @ 1c0007344 =====

void RtTransmitPackets(longlong *param_1)

{
  uint *puVar1;
  int *piVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  longlong *plVar6;
  longlong lVar7;
  bool bVar8;
  ushort uVar9;
  longlong lVar10;
  ushort uVar11;
  uint uVar12;
  longlong lVar13;
  uint uVar14;
  undefined2 *puVar15;
  ushort uVar16;
  int iVar17;
  ulonglong uVar18;
  int *piVar19;
  uint uVar20;
  ulonglong uVar21;
  
  bVar8 = false;
  plVar6 = (longlong *)param_1[2];
  lVar13 = *plVar6;
  puVar1 = (uint *)(lVar13 + 0x34);
  uVar4 = *(uint *)(lVar13 + 0xc);
  for (uVar14 = *puVar1; iVar17 = 0, uVar14 != uVar4; uVar14 = *(uint *)(lVar13 + 8) & uVar14 + 1) {
    uVar21 = (ulonglong)uVar14;
    piVar19 = (int *)(*(ushort *)(lVar13 + 2) * uVar21 + 0x40 + lVar13);
    if ((*(byte *)((longlong)piVar19 + 0xb) & 1) == 0) {
      lVar13 = param_1[3];
      *(undefined2 *)(lVar13 + uVar21 * 8) = *(undefined2 *)((longlong)param_1 + 0x3a);
      lVar7 = *plVar6;
      lVar10 = *(ushort *)(lVar7 + 2) * uVar21;
      uVar12 = *(uint *)(lVar10 + 0x40 + lVar7);
      uVar20 = *(ushort *)(lVar10 + 0x44 + lVar7) + uVar12;
      uVar5 = *(uint *)(plVar6[1] + 8);
      *(undefined4 *)(lVar13 + 4 + uVar21 * 8) = 0;
      while( true ) {
        if (uVar12 == (uVar20 & uVar5)) break;
        uVar11 = 0xc000;
        uVar3 = *(ushort *)(piVar19 + 1);
        lVar7 = *(longlong *)(param_1[2] + 8);
        puVar15 = (undefined2 *)
                  ((ulonglong)(uint)*(ushort *)((longlong)param_1 + 0x3a) * 0x10 + param_1[5]);
        if ((uint)*(ushort *)((longlong)param_1 + 0x3a) != *(ushort *)(param_1 + 7) - 1) {
          uVar11 = 0x8000;
        }
        uVar16 = uVar11 | 0x2000;
        if (iVar17 != 0) {
          uVar16 = uVar11;
        }
        uVar18 = (ulonglong)(iVar17 + *piVar19 & *(uint *)(lVar7 + 8));
        lVar10 = *(ushort *)(lVar7 + 2) * uVar18;
        *(ulonglong *)(puVar15 + 4) =
             (ulonglong)((uint)((ulonglong)*(undefined8 *)(lVar10 + 0x40 + lVar7) >> 0x34) & 0x3ff)
             + *(longlong *)(uVar18 * param_1[0x19] + param_1[0x18]);
        *puVar15 = *(undefined2 *)(lVar10 + 0x40 + lVar7);
        puVar15[2] = 0;
        uVar9 = RtProgramOffloadDescriptor(param_1,(longlong)piVar19,(longlong)puVar15,uVar14);
        uVar11 = uVar16 | 0x1000;
        if (iVar17 + 1U != (uint)uVar3) {
          uVar11 = uVar16;
        }
        LOCK();
        UNLOCK();
        puVar15[1] = uVar9 | uVar11;
        *(short *)((longlong)param_1 + 0x3a) =
             (short)((*(ushort *)((longlong)param_1 + 0x3a) + 1) % (uint)*(ushort *)(param_1 + 7));
        uVar12 = *(uint *)(plVar6[1] + 8) & uVar12 + 1;
        piVar2 = (int *)(lVar13 + 4 + uVar21 * 8);
        *piVar2 = *piVar2 + 1;
        iVar17 = *(int *)(lVar13 + 4 + uVar21 * 8);
      }
      bVar8 = true;
      *(uint *)(plVar6[1] + 0x34) = uVar12;
    }
    lVar13 = *plVar6;
  }
  *puVar1 = uVar14;
  if (bVar8) {
    LOCK();
    UNLOCK();
    *(undefined1 *)param_1[8] = *(undefined1 *)((longlong)param_1 + 0x114);
  }
  return;
}



===== RtTxQueueInitialize @ 1c000755c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RtTxQueueInitialize(struct NETPACKETQUEUE__ * __ptr64,struct _RT_ADAPTER * __ptr64)
    */

long __cdecl RtTxQueueInitialize(NETPACKETQUEUE__ *param_1,_RT_ADAPTER *param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  uint uVar5;
  _tlgProvider_t *p_Var6;
  _GUID *p_Var7;
  _GUID *p_Var8;
  _GUID *p_Var9;
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined8 local_res18;
  wchar_t *local_res20;
  wchar_t *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  NETPACKETQUEUE__ *local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  plVar2 = (longlong *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RT_TXQUEUE_TYPE_INFO_1c000d090);
  *plVar2 = (longlong)param_2;
  plVar2[8] = *(longlong *)(param_2 + 0x530) + 0x38;
  plVar2[1] = *(longlong *)(param_2 + 0x40);
  plVar3 = (longlong *)(*DAT_1c000d7f0)(NetDriverGlobals,param_1);
  plVar2[2] = (longlong)plVar3;
  p_Var8 = (_GUID *)0x200;
  lVar4 = *plVar3;
  uVar5 = *(uint *)(plVar3[1] + 4);
  if (0xffff < uVar5) {
    uVar5 = 0xffff;
  }
  *(short *)(plVar2 + 7) = (short)uVar5;
  p_Var9 = (_GUID *)0x0;
  local_res18 = 0;
  local_30 = 0;
  local_50 = 0;
  uStack_58 = 0;
  uStack_38 = 0;
  uStack_48 = 0x100000001;
  local_60 = 0x38;
  p_Var6 = WdfDriverGlobals;
  local_40 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x600))
                    (WdfDriverGlobals,&local_60,0x200,0,(ulonglong)*(uint *)(lVar4 + 4) << 3,
                     &local_res18,plVar2 + 3);
  if (iVar1 < 0) {
    if (DAT_1c000d1e0 < 3) {
      return iVar1;
    }
    local_res20 = 
    L"WdfMemoryCreate( &tcbAttributes, NonPagedPoolNx, 0, sizeof(RT_TCB) * pr->NumberOfElements, &memory, (void**)&tx->PacketContext )"
    ;
    local_res10[0] = 0x199;
  }
  else {
    p_Var9 = (_GUID *)0x0;
    p_Var7 = (_GUID *)((ulonglong)*(ushort *)(plVar2 + 7) << 4);
    p_Var6 = WdfDriverGlobals;
    p_Var8 = p_Var7;
    iVar1 = (**(code **)(WdfFunctions_01021 + 0xa8))
                      (WdfDriverGlobals,*(undefined8 *)(*plVar2 + 0x540),p_Var7,0,plVar2 + 4);
    if (-1 < iVar1) {
      lVar4 = (**(code **)(WdfFunctions_01021 + 0xb0))(WdfDriverGlobals,plVar2[4]);
      plVar2[5] = lVar4;
      plVar2[6] = (longlong)p_Var7;
      return iVar1;
    }
    if (DAT_1c000d1e0 < 3) {
      return iVar1;
    }
    local_res20 = 
    L"WdfCommonBufferCreate( tx->Adapter->DmaEnabler, txSize, WDF_NO_OBJECT_ATTRIBUTES, &tx->TxdArray)"
    ;
    local_res10[0] = 0x1a4;
  }
  local_68 = L"RtTxQueueInitialize";
  local_res8[0] = iVar1;
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
            (p_Var6,&DAT_1c000be46,p_Var8,p_Var9,(_tlgWrapSz<unsigned_short> *)&local_68,
             (_tlgWrapperByVal<4> *)local_res10,(_tlgWrapperByVal<4> *)local_res8,
             (_tlgWrapSz<unsigned_short> *)&local_res20);
  return iVar1;
}



===== FxStubDriverUnloadCommon @ 1c0007764 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = &_NetAdapterCx_BIND_INFO;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c000d368 != &__KMDF_CLASS_BIND_START) {
    puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_1c000d368 + 0x50);
    while( true ) {
      for (; (puVar1 + 2 <= puVar2 && (*(longlong *)puVar1 == 0)); puVar1 = puVar1 + 2) {
      }
      if (puVar1 < puVar2) break;
      puVar1 = puVar2;
LAB_1c00077bd:
      if (puVar1 == (uint *)0x0) goto LAB_1c0007813;
      if (puVar2 <= puVar1) goto LAB_1c000782b;
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      puVar1 = (uint *)((longlong)puVar1 + (ulonglong)*puVar1);
    }
    if ((puVar1 + 0x14 <= puVar2) && (*puVar1 == 0x50)) goto LAB_1c00077bd;
LAB_1c0007813:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c000782b:
  WdfVersionUnbind(&DAT_1c000d5d0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0007860 =====

void entry(_WDF_BIND_INFO *param_1,_GUID *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0007894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FxDriverEntryWorker(_WDF_BIND_INFO *param_1,_GUID *param_2)

{
  uint uVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    uVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1c000d5d0 = 0x2080000;
    _DAT_1c000d5d8 = &DAT_1c000d3c0;
    RtlCopyUnicodeString(&DAT_1c000d5d0);
    p_Var3 = param_1;
    uVar1 = WdfVersionBind(param_1,&DAT_1c000d5d0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < (int)uVar1) {
      uVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar1 = DriverEntry(param_1,param_2);
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c000d5c8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar1,&DAT_1c000d5d0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c000d368 != &__KMDF_CLASS_BIND_START) {
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
  return uVar1;
}



===== FxStubDriverUnload @ 1c0007a20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c000d5c8 != (code *)0x0) && (DAT_1c000d5c8 != FxStubDriverUnload)) {
    (*DAT_1c000d5c8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0007a54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0007a79) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  puVar2 = &_NetAdapterCx_BIND_INFO;
  while( true ) {
    for (; (puVar2 + 2 < (uint *)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*(longlong *)puVar2 == 0)); puVar2 = puVar2 + 2) {
    }
    if ((uint *)0x1c000d35f < puVar2) break;
    if (((&__KMDF_CLASS_BIND_END < puVar2 + 0x14) || (*puVar2 != 0x50)) || (puVar2 == (uint *)0x0))
    {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c000d368 = (undefined *)puVar2;
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



===== FxStubInitTypes @ 1c0007bdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0007bf9) */
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
    if ((void **)0x1c000d37f < ppvVar2) break;
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



===== _guard_check_icall @ 1c0007cb0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0007cc8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0007cec =====

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



===== __cpu_features_init @ 1c0007d60 =====

/* WARNING: Removing unreachable block (ram,0x0001c0007dca) */
/* WARNING: Removing unreachable block (ram,0x0001c0007d79) */
/* WARNING: Removing unreachable block (ram,0x0001c0007d6a) */

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



===== __security_check_cookie @ 1c0007e30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0007e70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0007ea0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0007ea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0007ed0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0007f40 =====

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



===== memset @ 1c0008240 =====

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



===== __memset_repmovs @ 1c0008380 =====

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



===== __memset_query @ 1c0008400 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0008480 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00085c0 =====

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



===== __memset_spec_plain @ 1c0008640 =====

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



===== _tlgEnableCallback @ 1c0010010 =====

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



===== __security_init_cookie @ 1c0011008 =====

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



===== DriverEntry @ 1c001103c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint DriverEntry(undefined8 param_1,_GUID *param_2)

{
  code *pcVar1;
  longlong lVar2;
  uint uVar3;
  _tlgProvider_t *p_Var4;
  undefined1 *puVar5;
  _GUID *p_Var6;
  _GUID *p_Var7;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [56];
  uint local_b8;
  uint uStack_b4;
  wchar_t *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  code *local_a0;
  code *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  wchar_t *local_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 local_78 [32];
  wchar_t *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  uint local_30 [2];
  ulonglong local_28;
  
  puVar5 = auStack_f8;
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_88 = *(wchar_t **)(PTR_DAT_1c000d1e8 + -0x10);
  uStack_80 = *(undefined4 *)(PTR_DAT_1c000d1e8 + -8);
  uStack_7c = *(undefined4 *)(PTR_DAT_1c000d1e8 + -4);
  if (DAT_1c000d200 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar5 = auStack_f0;
  }
  p_Var7 = (_GUID *)&DAT_1c000d200;
  p_Var6 = (_GUID *)&DAT_1c000d1e0;
  p_Var4 = (_tlgProvider_t *)&local_88;
  _DAT_1c000d208 = 0;
  uRam00000001c000d210 = 0;
  *(undefined8 *)(puVar5 + -8) = 0x1c00110b6;
  uVar3 = EtwRegister(p_Var4,_tlgEnableCallback);
  if (uVar3 == 0) {
    *(undefined8 *)(puVar5 + -8) = 0x1c00110e1;
    EtwSetInformation(DAT_1c000d200,2);
  }
  else if ((int)uVar3 < 0) {
    if (2 < DAT_1c000d1e0) {
      uStack_b4 = uVar3;
      local_b0 = L"TraceLoggingRegister(RealtekTraceProvider)";
      local_b8 = 0x29;
      *(wchar_t ***)(puVar5 + 0x38) = &local_b0;
      local_88 = L"DriverEntry";
      *(uint **)(puVar5 + 0x30) = &uStack_b4;
      *(uint **)(puVar5 + 0x28) = &local_b8;
      *(wchar_t ***)(puVar5 + 0x20) = &local_88;
      *(undefined8 *)(puVar5 + -8) = 0x1c00112e6;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
                (p_Var4,&DAT_1c000be46,p_Var6,p_Var7,*(_tlgWrapSz<unsigned_short> **)(puVar5 + 0x20)
                 ,*(_tlgWrapperByVal<4> **)(puVar5 + 0x28),*(_tlgWrapperByVal<4> **)(puVar5 + 0x30),
                 *(_tlgWrapSz<unsigned_short> **)(puVar5 + 0x38));
    }
    goto LAB_1c001125e;
  }
  if (5 < DAT_1c000d1e0) {
    local_3c = 0;
    local_48 = local_30;
    local_40 = 2;
    local_38 = *(undefined8 *)(param_2 + 8);
    local_30[1] = 0;
    local_4c = 0;
    local_30[0] = (uint)*(ushort *)param_2;
    *(undefined1 **)(puVar5 + 0x28) = local_78;
    *(undefined4 *)(puVar5 + 0x20) = 5;
    local_58 = L"DriverEntry";
    local_50 = 0x18;
    *(undefined8 *)(puVar5 + -8) = 0x1c0011154;
    _tlgWriteTransfer_EtwWriteTransfer
              (0x1c000d1e0,&DAT_1c000c0d2,0,0,*(undefined4 *)(puVar5 + 0x20),
               *(undefined8 **)(puVar5 + 0x28));
  }
  local_a4 = 0;
  local_90 = 0;
  *(undefined8 *)(puVar5 + 0x28) = 0;
  p_Var6 = (_GUID *)0x0;
  local_a0 = EvtDriverDeviceAdd;
  local_a8 = 0x20;
  local_98 = EvtDriverUnload;
  local_8c = 0x5254454b;
  *(undefined4 **)(puVar5 + 0x20) = &local_a8;
  pcVar1 = *(code **)(WdfFunctions_01021 + 0x3a0);
  *(undefined8 *)(puVar5 + -8) = 0x1c00111b2;
  p_Var4 = WdfDriverGlobals;
  uVar3 = (*pcVar1)(WdfDriverGlobals,param_1);
  if (((int)uVar3 < 0) && (2 < DAT_1c000d1e0)) {
    local_b8 = uVar3;
    local_88 = 
    L"WdfDriverCreate(driverObject, registryPath, WDF_NO_OBJECT_ATTRIBUTES, &driverConfig, NULL)";
    uStack_b4 = 0x37;
    *(wchar_t ***)(puVar5 + 0x38) = &local_88;
    *(uint **)(puVar5 + 0x30) = &local_b8;
    *(uint **)(puVar5 + 0x28) = &uStack_b4;
    *(wchar_t ***)(puVar5 + 0x20) = &local_b0;
    local_b0 = L"DriverEntry";
    *(undefined8 *)(puVar5 + -8) = 0x1c001120a;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>_>
              (p_Var4,&DAT_1c000be46,param_2,p_Var6,*(_tlgWrapSz<unsigned_short> **)(puVar5 + 0x20),
               *(_tlgWrapperByVal<4> **)(puVar5 + 0x28),*(_tlgWrapperByVal<4> **)(puVar5 + 0x30),
               *(_tlgWrapSz<unsigned_short> **)(puVar5 + 0x38));
  }
  if (5 < DAT_1c000d1e0) {
    local_b8 = uVar3;
    *(uint **)(puVar5 + 0x28) = &local_b8;
    local_88 = L"DriverEntry";
    *(wchar_t ***)(puVar5 + 0x20) = &local_88;
    *(undefined8 *)(puVar5 + -8) = 0x1c0011238;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
              (p_Var4,&DAT_1c000be88,param_2,p_Var6,*(_tlgWrapSz<unsigned_short> **)(puVar5 + 0x20),
               *(_tlgWrapperByVal<4> **)(puVar5 + 0x28));
  }
  lVar2 = DAT_1c000d200;
  if ((int)uVar3 < 0) {
    DAT_1c000d200 = 0;
    DAT_1c000d1e0 = 0;
    *(undefined8 *)(puVar5 + -8) = 0x1c0011259;
    EtwUnregister(lVar2);
  }
LAB_1c001125e:
  *(undefined8 *)(puVar5 + -8) = 0x1c001126c;
  return uVar3;
}


