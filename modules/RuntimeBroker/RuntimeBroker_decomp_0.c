
===== Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>_> @ 140001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<unsigned short>,struct _tlgWrapSz<unsigned short>,struct
   _tlgWrapSz<unsigned short> >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct
   _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapSz<unsigned short> const &
   __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapSz<unsigned short> const
   & __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5,_tlgWrapperByRef<16> *param_6,
          _tlgWrapperByVal<4> *param_7,_tlgWrapSz<unsigned_short> *param_8,
          _tlgWrapSz<unsigned_short> *param_9,_tlgWrapSz<unsigned_short> *param_10)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_c8 [32];
  _EVENT_DATA_DESCRIPTOR local_98 [2];
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar3 = -1;
  local_70 = 2;
  local_28 = *(wchar_t **)param_10;
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
  local_38 = *(wchar_t **)param_9;
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
  local_48 = *(wchar_t **)param_8;
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
  local_58 = param_7;
  local_3c = 0;
  local_50 = 4;
  local_68 = *(undefined8 *)param_6;
  local_60 = 0x10;
  local_78 = *(wchar_t **)param_5;
  if (local_78 == (wchar_t *)0x0) {
    local_78 = L"";
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_78[lVar3] != L'\0');
    local_70 = (int)lVar3 * 2 + 2;
  }
  local_6c = 0;
  lVar1 = _tlgWriteTransfer_EventWriteTransfer
                    (0x140019008,param_2,(LPCGUID)0x0,(LPCGUID)0x0,8,local_98);
  return lVar1;
}



===== Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>_> @ 140001168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<unsigned short>,struct _tlgWrapSz<unsigned short>,struct
   _tlgWrapSz<unsigned short>,struct _tlgWrapSz<unsigned short> >(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapSz<unsigned short> const &
   __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<unsigned_short> *param_5,_tlgWrapperByRef<16> *param_6,
          _tlgWrapperByVal<4> *param_7,_tlgWrapSz<unsigned_short> *param_8,
          _tlgWrapSz<unsigned_short> *param_9,_tlgWrapSz<unsigned_short> *param_10,
          _tlgWrapSz<unsigned_short> *param_11)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_d8 [32];
  _EVENT_DATA_DESCRIPTOR local_a8 [2];
  wchar_t *local_88;
  int local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar3 = -1;
  local_80 = 2;
  local_28 = *(wchar_t **)param_11;
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
  local_38 = *(wchar_t **)param_10;
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
  local_48 = *(wchar_t **)param_9;
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
  local_58 = *(wchar_t **)param_8;
  if (local_58 == (wchar_t *)0x0) {
    local_58 = L"";
    local_50 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_68 = param_7;
  local_4c = 0;
  local_60 = 4;
  local_78 = *(undefined8 *)param_6;
  local_70 = 0x10;
  local_88 = *(wchar_t **)param_5;
  if (local_88 == (wchar_t *)0x0) {
    local_88 = L"";
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_88[lVar3] != L'\0');
    local_80 = (int)lVar3 * 2 + 2;
  }
  local_7c = 0;
  lVar1 = _tlgWriteTransfer_EventWriteTransfer
                    (0x140019008,param_2,(LPCGUID)0x0,(LPCGUID)0x0,9,local_a8);
  return lVar1;
}



===== Write<_tlgWrapperByVal<4>_> @ 1400012fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<4>
   const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<4> *param_5)

{
  long lVar1;
  undefined1 auStackY_78 [32];
  _EVENT_DATA_DESCRIPTOR local_48 [2];
  _tlgWrapperByVal<4> *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_1c = 0;
  local_28 = param_5;
  local_20 = 4;
  lVar1 = _tlgWriteTransfer_EventWriteTransfer
                    (0x140019008,param_2,(LPCGUID)0x0,(LPCGUID)0x0,3,local_48);
  return lVar1;
}



===== _tlgEnableCallback @ 140001370 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

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



===== _tlgKeywordOn @ 1400013ec =====

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



===== _tlgWriteTransfer_EventWriteTransfer @ 140001418 =====

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



===== Write<_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<2>_> @ 1400014bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwEventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapSz<unsigned
   short>,struct _tlgWrapSz<char>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<2> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const &
   __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapSz<char> const &
   __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<2> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwEventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<2>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<4> *param_5,_tlgWrapSz<char> *param_6,_tlgWrapSz<unsigned_short> *param_7
          ,_tlgWrapSz<char> *param_8,_tlgWrapSz<char> *param_9,_tlgWrapperByVal<2> *param_10)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [4];
  _tlgWrapperByVal<4> *local_78;
  undefined8 local_70;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  _tlgWrapperByVal<2> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_28 = param_10;
  lVar3 = -1;
  local_50 = 2;
  local_20 = 2;
  local_38 = *(char **)param_9;
  if (local_38 == (char *)0x0) {
    local_38 = "";
    local_30 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_38[lVar2] != '\0');
    local_30 = (int)lVar2 + 1;
  }
  local_2c = 0;
  local_48 = *(char **)param_8;
  if (local_48 == (char *)0x0) {
    local_48 = "";
    local_40 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_48[lVar2] != '\0');
    local_40 = (int)lVar2 + 1;
  }
  local_3c = 0;
  local_58 = *(wchar_t **)param_7;
  if (local_58 == (wchar_t *)0x0) {
    local_58 = L"";
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_4c = 0;
  local_68 = *(char **)param_6;
  if (local_68 == (char *)0x0) {
    local_68 = "";
    local_60 = 1;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_68[lVar3] != '\0');
    local_60 = (int)lVar3 + 1;
  }
  local_78 = param_5;
  local_5c = 0;
  local_70 = 4;
  lVar1 = _tlgWriteTransfer_EtwEventWriteTransfer((longlong)param_1,param_2,0,0,8,local_98);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>_> @ 14000161c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwEventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<8>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct _tlgWrapSz<unsigned short>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<char>,struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<char>,struct _tlgWrapSz<unsigned short> >(struct _tlgProvider_t const * __ptr64,void
   const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwEventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<8> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapSz<char> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapSz<char> *param_10,
          _tlgWrapperByVal<4> *param_11,_tlgWrapSz<unsigned_short> *param_12,
          _tlgWrapperByVal<4> *param_13,_tlgWrapSz<char> *param_14,_tlgWrapperByVal<4> *param_15,
          _tlgWrapSz<char> *param_16,_tlgWrapSz<unsigned_short> *param_17,
          _tlgWrapperByVal<4> *param_18,_tlgWrapSz<char> *param_19,
          _tlgWrapSz<unsigned_short> *param_20)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_178 [32];
  undefined8 local_148 [4];
  _tlgWrapperByVal<8> *local_128;
  undefined8 local_120;
  _tlgWrapperByVal<8> *local_118;
  undefined8 local_110;
  _tlgWrapperByVal<4> *local_108;
  undefined8 local_100;
  char *local_f8;
  int local_f0;
  undefined4 local_ec;
  _tlgWrapperByVal<4> *local_e8;
  undefined8 local_e0;
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  _tlgWrapperByVal<4> *local_c8;
  undefined8 local_c0;
  wchar_t *local_b8;
  int local_b0;
  undefined4 local_ac;
  _tlgWrapperByVal<4> *local_a8;
  undefined8 local_a0;
  char *local_98;
  int local_90;
  undefined4 local_8c;
  _tlgWrapperByVal<4> *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_178;
  lVar3 = -1;
  local_b0 = 2;
  local_38 = *(wchar_t **)param_20;
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
  local_48 = *(char **)param_19;
  if (local_48 == (char *)0x0) {
    local_48 = "";
    local_40 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_48[lVar2] != '\0');
    local_40 = (int)lVar2 + 1;
  }
  local_58 = param_18;
  local_3c = 0;
  local_50 = 4;
  local_68 = *(wchar_t **)param_17;
  if (local_68 == (wchar_t *)0x0) {
    local_68 = L"";
    local_60 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_68[lVar2] != L'\0');
    local_60 = (int)lVar2 * 2 + 2;
  }
  local_5c = 0;
  local_78 = *(char **)param_16;
  if (local_78 == (char *)0x0) {
    local_78 = "";
    local_70 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_78[lVar2] != '\0');
    local_70 = (int)lVar2 + 1;
  }
  local_88 = param_15;
  local_6c = 0;
  local_80 = 4;
  local_98 = *(char **)param_14;
  if (local_98 == (char *)0x0) {
    local_98 = "";
    local_90 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_98[lVar2] != '\0');
    local_90 = (int)lVar2 + 1;
  }
  local_a8 = param_13;
  local_8c = 0;
  local_a0 = 4;
  local_b8 = *(wchar_t **)param_12;
  if (local_b8 == (wchar_t *)0x0) {
    local_b8 = L"";
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_b8[lVar2] != L'\0');
    local_b0 = (int)lVar2 * 2 + 2;
  }
  local_c8 = param_11;
  local_ac = 0;
  local_d8 = *(char **)param_10;
  local_c0 = 4;
  if (local_d8 == (char *)0x0) {
    local_d8 = "";
    local_d0 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_d8[lVar2] != '\0');
    local_d0 = (int)lVar2 + 1;
  }
  local_e8 = param_9;
  local_cc = 0;
  local_e0 = 4;
  local_f8 = *(char **)param_8;
  if (local_f8 == (char *)0x0) {
    local_f8 = "";
    local_f0 = 1;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_f8[lVar3] != '\0');
    local_f0 = (int)lVar3 + 1;
  }
  local_108 = param_7;
  local_118 = param_6;
  local_128 = param_5;
  local_ec = 0;
  local_100 = 4;
  local_110 = 8;
  local_120 = 8;
  lVar1 = _tlgWriteTransfer_EtwEventWriteTransfer((longlong)param_1,param_2,0,0,0x12,local_148);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>_> @ 1400018d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwEventWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapSz<unsigned short>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapSz<unsigned
   short>,struct _tlgWrapperByVal<4>,struct _tlgWrapSz<char>,struct _tlgWrapSz<unsigned
   short>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapSz<char> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapSz<char> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwEventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapSz<char> *param_7,
          _tlgWrapperByVal<4> *param_8,_tlgWrapSz<char> *param_9,_tlgWrapperByVal<4> *param_10,
          _tlgWrapSz<unsigned_short> *param_11,_tlgWrapperByVal<4> *param_12,
          _tlgWrapSz<char> *param_13,_tlgWrapperByVal<4> *param_14,_tlgWrapSz<char> *param_15,
          _tlgWrapSz<unsigned_short> *param_16,_tlgWrapperByVal<4> *param_17,
          _tlgWrapSz<char> *param_18,_tlgWrapSz<unsigned_short> *param_19,
          _tlgWrapperByVal<4> *param_20,_tlgWrapperByVal<4> *param_21,_tlgWrapSz<char> *param_22)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_198 [32];
  undefined8 local_168 [4];
  _tlgWrapperByVal<8> *local_148;
  undefined8 local_140;
  _tlgWrapperByVal<4> *local_138;
  undefined8 local_130;
  char *local_128;
  int local_120;
  undefined4 local_11c;
  _tlgWrapperByVal<4> *local_118;
  undefined8 local_110;
  char *local_108;
  int local_100;
  undefined4 local_fc;
  _tlgWrapperByVal<4> *local_f8;
  undefined8 local_f0;
  wchar_t *local_e8;
  int local_e0;
  undefined4 local_dc;
  _tlgWrapperByVal<4> *local_d8;
  undefined8 local_d0;
  char *local_c8;
  int local_c0;
  undefined4 local_bc;
  _tlgWrapperByVal<4> *local_b8;
  undefined8 local_b0;
  char *local_a8;
  int local_a0;
  undefined4 local_9c;
  wchar_t *local_98;
  int local_90;
  undefined4 local_8c;
  _tlgWrapperByVal<4> *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_198;
  lVar3 = -1;
  local_38 = *(char **)param_22;
  if (local_38 == (char *)0x0) {
    local_38 = "";
    local_30 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_38[lVar2] != '\0');
    local_30 = (int)lVar2 + 1;
  }
  local_e0 = 2;
  local_48 = param_21;
  local_58 = param_20;
  local_2c = 0;
  local_40 = 4;
  local_68 = *(wchar_t **)param_19;
  local_50 = 4;
  if (local_68 == (wchar_t *)0x0) {
    local_68 = L"";
    local_60 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_68[lVar2] != L'\0');
    local_60 = (int)lVar2 * 2 + 2;
  }
  local_5c = 0;
  local_78 = *(char **)param_18;
  if (local_78 == (char *)0x0) {
    local_78 = "";
    local_70 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_78[lVar2] != '\0');
    local_70 = (int)lVar2 + 1;
  }
  local_88 = param_17;
  local_6c = 0;
  local_80 = 4;
  local_98 = *(wchar_t **)param_16;
  if (local_98 == (wchar_t *)0x0) {
    local_98 = L"";
    local_90 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_98[lVar2] != L'\0');
    local_90 = (int)lVar2 * 2 + 2;
  }
  local_8c = 0;
  local_a8 = *(char **)param_15;
  if (local_a8 == (char *)0x0) {
    local_a8 = "";
    local_a0 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_a8[lVar2] != '\0');
    local_a0 = (int)lVar2 + 1;
  }
  local_b8 = param_14;
  local_9c = 0;
  local_b0 = 4;
  local_c8 = *(char **)param_13;
  if (local_c8 == (char *)0x0) {
    local_c8 = "";
    local_c0 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_c8[lVar2] != '\0');
    local_c0 = (int)lVar2 + 1;
  }
  local_d8 = param_12;
  local_bc = 0;
  local_d0 = 4;
  local_e8 = *(wchar_t **)param_11;
  if (local_e8 == (wchar_t *)0x0) {
    local_e8 = L"";
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_e8[lVar2] != L'\0');
    local_e0 = (int)lVar2 * 2 + 2;
  }
  local_f8 = param_10;
  local_dc = 0;
  local_108 = *(char **)param_9;
  local_f0 = 4;
  if (local_108 == (char *)0x0) {
    local_108 = "";
    local_100 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_108[lVar2] != '\0');
    local_100 = (int)lVar2 + 1;
  }
  local_118 = param_8;
  local_fc = 0;
  local_110 = 4;
  local_128 = *(char **)param_7;
  if (local_128 == (char *)0x0) {
    local_128 = "";
    local_120 = 1;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_128[lVar3] != '\0');
    local_120 = (int)lVar3 + 1;
  }
  local_138 = param_6;
  local_148 = param_5;
  local_11c = 0;
  local_130 = 4;
  local_140 = 8;
  lVar1 = _tlgWriteTransfer_EtwEventWriteTransfer((longlong)param_1,param_2,0,0,0x14,local_168);
  return lVar1;
}



===== TraceLoggingRegisterEx_EtwEventRegister_EtwEventSetInformation @ 140001bd4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TraceLoggingRegisterEx_EtwEventRegister_EtwEventSetInformation(longlong param_1)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  uint uVar6;
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
  *(undefined8 *)(puVar7 + -8) = 0x140001c37;
  uVar6 = EtwEventRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (uVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140001c66;
    EtwEventSetInformation(lVar3,2,puVar4,uVar2);
  }
  else if (0 < (int)uVar6) {
    uVar6 = uVar6 & 0xffff | 0x80070000;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140001c7a;
  return uVar6;
}



===== _tlgWriteTransfer_EtwEventWriteTransfer @ 140001c94 =====

void _tlgWriteTransfer_EtwEventWriteTransfer
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
  EtwEventWriteTransfer(*(undefined8 *)(param_1 + 0x20),&local_18,param_3,param_4,param_5,param_6);
  return;
}



===== `dynamic_initializer_for_'g_header_init_InitializeStagingSRUMFeatureReporting'' @ 140001d40 =====

void wil::details::_dynamic_initializer_for__g_header_init_InitializeStagingSRUMFeatureReporting__
               (void)

{
  g_wil_details_RecordSRUMFeatureUsage = RecordSRUMFeatureUsage;
  return;
}



===== CreateInstance @ 140001d60 =====

/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::CreateInstance(struct
   IUnknown * __ptr64,struct _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::CreateInstance
          (CRuntimeBrokerLifetimeExtensionFactory *this,IUnknown *param_1,_GUID *param_2,
          void **param_3)

{
  long lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  void *unaff_retaddr;
  
  if (param_1 == (IUnknown *)0x0) {
    lVar2._0_4_ = param_2->Data1;
    lVar2._4_2_ = param_2->Data2;
    lVar2._6_2_ = param_2->Data3;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)param_2->Data4 + -0x46000000000000c0;
    }
    if (lVar2 == 0) {
      puVar3 = operator_new(0x18,&std::nothrow);
      if (puVar3 == (undefined8 *)0x0) {
        *param_3 = (void *)0x0;
        wil::details::in1diag3::Return_Hr
                  (unaff_retaddr,0xd4,
                   "onecore\\com\\combase\\runtimebroker\\exe\\LifetimeExtension.hpp",-0x7ff8fff2);
        lVar1 = -0x7ff8fff2;
      }
      else {
        *(undefined4 *)(puVar3 + 1) = 1;
        *puVar3 = &CLifetimeExtension::_vftable_;
        puVar3[2] = this;
        if (this != (CRuntimeBrokerLifetimeExtensionFactory *)0x0) {
          LOCK();
          *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
          UNLOCK();
        }
        CoAddRefServerProcess();
        lVar1 = 0;
        *param_3 = puVar3;
      }
    }
    else {
      lVar1 = -0x7fffbffe;
    }
  }
  else {
    lVar1 = -0x7fffbfff;
  }
  return lVar1;
}



===== TryGetPointer @ 140001e34 =====

/* public: static long __cdecl wil::details_abi::SemaphoreValue::TryGetPointer(unsigned short const
   * __ptr64,void * __ptr64 * __ptr64) */

long __cdecl wil::details_abi::SemaphoreValue::TryGetPointer(ushort *param_1,void **param_2)

{
  long lVar1;
  bool *in_R9;
  void *unaff_retaddr;
  __uint64 local_res10 [3];
  
  *param_2 = (void *)0x0;
  local_res10[0] = 0;
  lVar1 = TryGetValueInternal(param_1,SUB81(param_2,0),local_res10,in_R9);
  if (lVar1 < 0) {
    details::in1diag3::Return_Hr(unaff_retaddr,100,"wil",lVar1);
    details::in1diag3::Return_Hr(unaff_retaddr,0x6d,"wil",lVar1);
  }
  else {
    *param_2 = (void *)(local_res10[0] << 2);
    lVar1 = 0;
  }
  return lVar1;
}



===== Acquire @ 140001ec0 =====

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
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *pPVar1;
  code *pcVar2;
  DWORD DVar3;
  long lVar4;
  HANDLE hHandle;
  uint uVar5;
  HANDLE pvVar6;
  char *pcVar7;
  bool *pbVar8;
  void *unaff_retaddr;
  undefined1 auStack_278 [32];
  undefined4 local_258;
  char *local_250;
  HANDLE local_248;
  __uint64 local_240;
  WCHAR local_238 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_278;
  *param_2 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
  DVar3 = GetCurrentProcessId();
  local_258 = 0x130;
  local_250 = param_1;
  StringCchPrintfW((ushort *)local_238,0x104,(ushort *)L"Local\\SM0:%lu:%lu:%hs",(ulonglong)DVar3);
  pbVar8 = (bool *)0x1f0001;
  hHandle = CreateMutexExW((LPSECURITY_ATTRIBUTES)0x0,local_238,0,0x1f0001);
  local_248 = hHandle;
  if (hHandle == (HANDLE)0x0) {
    lVar4 = details::GetLastErrorFailHr();
    return lVar4;
  }
  pcVar7 = (char *)0x0;
  uVar5 = 0xffffffff;
  DVar3 = WaitForSingleObjectEx(hHandle,0xffffffff,0);
  if (DVar3 == 0x102) {
    pvVar6 = (void *)0x0;
  }
  else {
    if ((DVar3 & 0xffffff7f) != 0) {
      details::in1diag3::FailFast_Unexpected(unaff_retaddr,uVar5,pcVar7);
      pcVar2 = (code *)swi(3);
      lVar4 = (*pcVar2)();
      return lVar4;
    }
    pvVar6 = hHandle;
  }
  local_240 = 0;
  lVar4 = SemaphoreValue::TryGetValueInternal((ushort *)local_238,SUB41(uVar5,0),&local_240,pbVar8);
  if (lVar4 < 0) {
    details::in1diag3::Return_Hr(unaff_retaddr,100,"wil",lVar4);
    details::in1diag3::Return_Hr(unaff_retaddr,0x6d,"wil",lVar4);
    details::in1diag3::Return_Hr(unaff_retaddr,299,"wil",lVar4);
    if (pvVar6 != (void *)0x0) {
      details::ReleaseMutex(pvVar6);
    }
    details::CloseHandle(hHandle);
  }
  else {
    pPVar1 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)(local_240 * 4);
    if (pPVar1 == (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0) {
      lVar4 = MakeAndInitialize((ushort *)local_238,
                                (unique_any_t<wil::mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>_>
                                 *)&local_248,param_2);
      if (lVar4 < 0) {
        details::in1diag3::Return_Hr(unaff_retaddr,0x134,"wil",lVar4);
        if (pvVar6 != (void *)0x0) {
          details::ReleaseMutex(pvVar6);
        }
        if (local_248 != (void *)0x0) {
          details::CloseHandle(local_248);
        }
        return lVar4;
      }
    }
    else {
      *param_2 = pPVar1;
      *(int *)*param_2 = *(int *)pPVar1 + 1;
    }
    if (pvVar6 != (void *)0x0) {
      details::ReleaseMutex(pvVar6);
    }
    if (local_248 != (void *)0x0) {
      details::CloseHandle(local_248);
    }
    lVar4 = 0;
  }
  return lVar4;
}



===== StringCchPrintfW @ 1400020f4 =====

/* long __cdecl StringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl StringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

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
      lVar2 = -0x7ff8ff86;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = 0;
  }
  else {
    lVar2 = -0x7ff8ffa9;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar2;
}



===== TryGetValueInternal @ 140002170 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static long __cdecl wil::details_abi::SemaphoreValue::TryGetValueInternal(unsigned short
   const * __ptr64,bool,unsigned __int64 * __ptr64,bool * __ptr64) */

long __cdecl
wil::details_abi::SemaphoreValue::TryGetValueInternal
          (ushort *param_1,bool param_2,__uint64 *param_3,bool *param_4)

{
  WCHAR WVar1;
  DWORD DVar2;
  long lVar3;
  longlong lVar4;
  HANDLE pvVar5;
  WCHAR *pWVar6;
  WCHAR *pWVar7;
  HANDLE pvVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  void *unaff_retaddr;
  undefined1 auStack_268 [32];
  long local_248;
  long local_244 [3];
  WCHAR local_238 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_268;
  pWVar6 = local_238;
  *param_3 = 0;
  lVar9 = 0x104;
  do {
    if ((lVar9 == -0x7ffffefa) ||
       (WVar1 = *(WCHAR *)(((longlong)param_1 - (longlong)local_238) + (longlong)pWVar6),
       WVar1 == L'\0')) break;
    *pWVar6 = WVar1;
    pWVar6 = pWVar6 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  pWVar7 = pWVar6 + -1;
  if (lVar9 != 0) {
    pWVar7 = pWVar6;
  }
  pWVar6 = local_238;
  *pWVar7 = L'\0';
  lVar9 = 0x104;
  do {
    if (*pWVar6 == L'\0') break;
    pWVar6 = pWVar6 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  lVar10 = 0x7ffffffe;
  if (lVar9 != 0) {
    pWVar6 = local_238 + (0x104 - lVar9);
    lVar4 = 0x7ffffffe;
    lVar11 = (longlong)L"_p0" - (longlong)pWVar6;
    do {
      if ((lVar4 == 0) || (WVar1 = *(WCHAR *)(lVar11 + (longlong)pWVar6), WVar1 == L'\0')) break;
      *pWVar6 = WVar1;
      lVar4 = lVar4 + -1;
      pWVar6 = pWVar6 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    pWVar7 = pWVar6 + -1;
    if (lVar9 != 0) {
      pWVar7 = pWVar6;
    }
    *pWVar7 = L'\0';
  }
  pvVar5 = OpenSemaphoreW(0x1f0003,0,local_238);
  if (pvVar5 == (HANDLE)0x0) {
    DVar2 = GetLastError();
    if (DVar2 == 2) {
      lVar3 = 0;
    }
    else {
      lVar3 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xcd,"wil");
    }
  }
  else {
    local_244[0] = 0;
    local_248 = 0;
    lVar3 = GetValueFromSemaphore(pvVar5,local_244);
    if (lVar3 < 0) {
      details::in1diag3::Return_Hr(unaff_retaddr,0xd3,"wil",lVar3);
      details::CloseHandle(pvVar5);
    }
    else {
      lVar9 = 0x104;
      pWVar6 = local_238;
      do {
        if (*pWVar6 == L'\0') break;
        pWVar6 = pWVar6 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      if (lVar9 != 0) {
        pWVar6 = local_238 + (0x104 - lVar9);
        lVar4 = (longlong)L"h" - (longlong)pWVar6;
        do {
          if ((lVar10 == 0) || (WVar1 = *(WCHAR *)(lVar4 + (longlong)pWVar6), WVar1 == L'\0'))
          break;
          *pWVar6 = WVar1;
          lVar10 = lVar10 + -1;
          pWVar6 = pWVar6 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        pWVar7 = pWVar6 + -1;
        if (lVar9 != 0) {
          pWVar7 = pWVar6;
        }
        *pWVar7 = L'\0';
      }
      pvVar8 = OpenSemaphoreW(0x1f0003,0,local_238);
      if (pvVar8 == (HANDLE)0x0) {
        lVar3 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xd9,"wil");
        details::CloseHandle(pvVar5);
      }
      else {
        lVar3 = GetValueFromSemaphore(pvVar8,&local_248);
        if (lVar3 < 0) {
          details::in1diag3::Return_Hr(unaff_retaddr,0xdb,"wil",lVar3);
          details::CloseHandle(pvVar8);
          details::CloseHandle(pvVar5);
        }
        else {
          details::CloseHandle(pvVar8);
          *param_3 = (longlong)local_248 << 0x1f | (longlong)local_244[0];
          details::CloseHandle(pvVar5);
          lVar3 = 0;
        }
      }
    }
  }
  return lVar3;
}



===== CloseHandle @ 140002480 =====

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



===== GetValueFromSemaphore @ 1400024b0 =====

/* private: static long __cdecl wil::details_abi::SemaphoreValue::GetValueFromSemaphore(void *
   __ptr64,long * __ptr64) */

long __cdecl wil::details_abi::SemaphoreValue::GetValueFromSemaphore(void *param_1,long *param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  long lVar3;
  uint uVar4;
  void *unaff_retaddr;
  long local_res18 [2];
  long local_res20 [2];
  
  DVar1 = WaitForSingleObject(param_1,0);
  if (DVar1 == 0xffffffff) {
    lVar3 = details::in1diag3::Return_GetLastError(unaff_retaddr,0x99,"wil");
    return lVar3;
  }
  if ((DVar1 == 0) || (DVar1 == 0x102)) {
    local_res18[0] = 0;
    if (DVar1 == 0) {
      BVar2 = ReleaseSemaphore(param_1,1,local_res18);
      if (BVar2 == 0) {
        lVar3 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xa2,"wil");
        return lVar3;
      }
      local_res18[0] = local_res18[0] + 1;
      BVar2 = ReleaseSemaphore(param_1,1,(LPLONG)0x0);
      if ((BVar2 == 0) && (DVar1 = GetLastError(), DVar1 == 0x12a)) {
LAB_140002539:
        *param_2 = local_res18[0];
        return 0;
      }
      uVar4 = 0xa7;
    }
    else {
      local_res20[0] = 0;
      BVar2 = ReleaseSemaphore(param_1,1,local_res20);
      if (BVar2 == 0) {
        lVar3 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xb1,"wil");
        return lVar3;
      }
      if (local_res20[0] == 0) {
        BVar2 = ReleaseSemaphore(param_1,1,(LPLONG)0x0);
        if ((BVar2 == 0) && (DVar1 = GetLastError(), DVar1 == 0x12a)) {
          DVar1 = WaitForSingleObject(param_1,0);
          if (DVar1 == 0xffffffff) {
            lVar3 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xb8,"wil");
            return lVar3;
          }
          if (DVar1 == 0) goto LAB_140002539;
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
  details::in1diag3::Return_Hr(unaff_retaddr,uVar4,"wil",-0x7fff0001);
  return -0x7fff0001;
}



===== GetActivationFactory @ 140002690 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl CRuntimeBroker::GetActivationFactory(unsigned short const *
   __ptr64,struct _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBroker::GetActivationFactory
          (CRuntimeBroker *this,ushort *param_1,_GUID *param_2,void **param_3)

{
  long lVar1;
  ulonglong uVar2;
  void *unaff_retaddr;
  undefined1 auStack_98 [32];
  undefined1 in_stack_ffffffffffffff88;
  HSTRING__ *local_68;
  ThreadingType local_60 [2];
  wchar_t local_58 [20];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_60[0] = 0;
  *param_3 = (void *)0x0;
  if (param_1 == (ushort *)0x0) {
    builtin_wcsncpy(local_58,L"activatableClassId",0x13);
    RoOriginateErrorW(0x80070057,0x12,local_58);
    wil::details::in1diag3::Return_Hr
              (unaff_retaddr,0x2bd,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
               -0x7ff8ffa9);
    lVar1 = -0x7ff8ffa9;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (param_1[uVar2] != 0);
    if (uVar2 < 0x100000000) {
      WindowsDeleteString(0);
      local_68 = (HSTRING__ *)0x0;
      lVar1 = WindowsCreateString(param_1,uVar2 & 0xffffffff,&local_68);
      if (lVar1 < 0) {
        wil::details::in1diag3::Return_Hr
                  (unaff_retaddr,0x2ca,
                   "onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",lVar1);
      }
      else {
        lVar1 = ValidateBrokeredActivationRequest(param_1,local_60);
        if (lVar1 < 0) {
          wil::details::in1diag3::Return_Hr
                    (unaff_retaddr,0x2cb,
                     "onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",lVar1);
        }
        else {
          lVar1 = RoGetActivationFactory(local_68,param_2,param_3);
          if (lVar1 < 0) {
            wil::details::in1diag3::_Log_Hr
                      (unaff_retaddr,0x2ce,
                       "onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",lVar1);
          }
          LogActivation(local_68,param_2,lVar1,false,(bool)in_stack_ffffffffffffff88);
        }
      }
      WindowsDeleteString(local_68);
    }
    else {
      builtin_wcsncpy(local_58,L"activatableClassId",0x13);
      RoOriginateErrorW(0x80070057,0x12,local_58);
      wil::details::in1diag3::Return_Hr
                (unaff_retaddr,0x2c5,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
                 -0x7ff8ffa9);
      lVar1 = -0x7ff8ffa9;
    }
  }
  return lVar1;
}



===== ActivateInstance @ 1400028e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBroker::ActivateInstance(unsigned short const *
   __ptr64,struct IInspectable * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBroker::ActivateInstance(CRuntimeBroker *this,ushort *param_1,IInspectable **param_2)

{
  longlong *plVar1;
  long lVar2;
  uint uVar3;
  IIndirectCallTarget *pIVar4;
  ulonglong uVar5;
  void *unaff_retaddr;
  undefined1 auStack_a8 [32];
  undefined1 in_stack_ffffffffffffff78;
  IIndirectCallTarget *local_78;
  HSTRING__ *local_70;
  longlong *local_68;
  wchar_t local_60 [20];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  pIVar4 = (IIndirectCallTarget *)0x0;
  local_78 = (IIndirectCallTarget *)((ulonglong)local_78 & 0xffffffff00000000);
  *param_2 = (IInspectable *)0x0;
  if (param_1 == (ushort *)0x0) {
    builtin_wcsncpy(local_60,L"activatableClassId",0x13);
    RoOriginateErrorW(0x80070057,0x12,local_60);
    wil::details::in1diag3::Return_Hr
              (unaff_retaddr,0x283,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
               -0x7ff8ffa9);
    return -0x7ff8ffa9;
  }
  uVar5 = 0xffffffffffffffff;
  do {
    uVar5 = uVar5 + 1;
  } while (param_1[uVar5] != 0);
  if (0xffffffff < uVar5) {
    builtin_wcsncpy(local_60,L"activatableClassId",0x13);
    RoOriginateErrorW(0x80070057,0x12,local_60);
    wil::details::in1diag3::Return_Hr
              (unaff_retaddr,0x28b,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
               -0x7ff8ffa9);
    return -0x7ff8ffa9;
  }
  WindowsDeleteString(0);
  local_70 = (HSTRING__ *)0x0;
  lVar2 = WindowsCreateString(param_1,uVar5 & 0xffffffff,&local_70);
  if (lVar2 < 0) {
    wil::details::in1diag3::Return_Hr
              (unaff_retaddr,0x290,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
               lVar2);
    goto LAB_14000298c;
  }
  lVar2 = ValidateBrokeredActivationRequest(param_1,(ThreadingType *)&local_78);
  if (lVar2 < 0) {
    wil::details::in1diag3::Return_Hr
              (unaff_retaddr,0x291,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
               lVar2);
    goto LAB_14000298c;
  }
  local_68 = (longlong *)0x0;
  lVar2 = RoGetActivationFactory(local_70,&_GUID_00000035_0000_0000_c000_000000000046,&local_68);
  plVar1 = local_68;
  if (lVar2 < 0) {
    wil::details::in1diag3::_Log_Hr
              (unaff_retaddr,0x29d,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
               lVar2);
  }
  else {
    local_78 = (IIndirectCallTarget *)0x0;
    lVar2 = Ordinal_167(this,&_GUID_9937b752_3636_4546_8b25_319e71ce7cbd,&local_78);
    if (lVar2 < 0) {
      uVar3 = 0x17;
LAB_140002bcc:
      wil::details::in1diag3::Return_Hr
                (unaff_retaddr,uVar3,"onecore\\com\\combase\\inc\\IndirectCallTarget.hpp",lVar2);
      wil::com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy>::
      ~com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy>
                ((com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy> *)&local_78);
      wil::details::in1diag3::Return_Hr
                (unaff_retaddr,0x2a0,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
                 lVar2);
      wil::com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy>::
      ~com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy>
                ((com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy> *)&local_68);
      goto LAB_14000298c;
    }
    if (local_78 != (IIndirectCallTarget *)0x0) {
      lVar2 = (**(code **)(*(longlong *)local_78 + 0x20))(local_78,plVar1);
      pIVar4 = local_78;
      if (lVar2 < 0) {
        uVar3 = 0x1c;
        goto LAB_140002bcc;
      }
      local_78 = (IIndirectCallTarget *)0x0;
    }
    lVar2 = (**(code **)(*local_68 + 0x30))(local_68,param_2);
    if (lVar2 < 0) {
      wil::details::in1diag3::_Log_Hr
                (unaff_retaddr,0x2a2,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
                 lVar2);
    }
    if (pIVar4 != (IIndirectCallTarget *)0x0) {
      ClearIndirectCallTarget(pIVar4);
    }
  }
  LogActivation(local_70,(_GUID *)&GUID_NULL,lVar2,true,(bool)in_stack_ffffffffffffff78);
  if (local_68 != (longlong *)0x0) {
    (**(code **)(*local_68 + 0x10))();
  }
LAB_14000298c:
  WindowsDeleteString(local_70);
  return lVar2;
}



===== ValidateBrokeredActivationRequest @ 140002c40 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140002cde) */
/* WARNING: Removing unreachable block (ram,0x000140003096) */
/* private: static long __cdecl CRuntimeBroker::ValidateBrokeredActivationRequest(unsigned short
   const * __ptr64,enum Windows::Foundation::ThreadingType & __ptr64) */

long __cdecl
CRuntimeBroker::ValidateBrokeredActivationRequest(ushort *param_1,ThreadingType *param_2)

{
  code *pcVar1;
  longlong *plVar2;
  bool bVar3;
  char cVar4;
  DWORD DVar5;
  HRESULT HVar6;
  BOOL BVar7;
  long lVar8;
  HANDLE ThreadHandle;
  uchar **PrincipalSelfSid;
  ulonglong uVar9;
  uchar **pSecurityDescriptor;
  undefined1 auStackY_198 [32];
  undefined8 local_130;
  BOOL local_128 [2];
  longlong local_120;
  DWORD local_118 [2];
  undefined **local_110;
  HANDLE local_108;
  ulonglong local_100;
  ulonglong local_f8;
  int local_e8 [2];
  undefined1 local_e0;
  undefined8 local_d8;
  undefined1 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  char local_b8;
  ThreadingType local_b4;
  char local_b0;
  int local_ac;
  longlong *local_a8;
  undefined1 local_a0;
  undefined8 local_98;
  undefined1 local_90;
  undefined8 local_8c;
  undefined1 local_80;
  uchar **local_78;
  ulonglong uStack_70;
  undefined1 local_68;
  undefined4 local_64;
  _PRIVILEGE_SET local_58;
  GENERIC_MAPPING local_40;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_198;
  local_130 = 0;
  local_120 = 0;
  if (param_1 == (ushort *)0x0) {
    DVar5 = Microsoft::WRL::Wrappers::HString::Set((HString *)&local_130,(ushort *)L"",0);
LAB_140002cce:
    if ((-1 < (int)DVar5) &&
       (DVar5 = Ordinal_153(0,0,0,&_GUID_0fe5a50b_6ca2_47ed_8560_aa7920f978f2), -1 < (int)DVar5)) {
      DVar5 = (**(code **)(lRam0000000000000000 + 0x50))(0,local_130,&local_120);
    }
    if (DVar5 == 0x80070002) {
      DVar5 = 0x80070005;
      goto LAB_140003065;
    }
  }
  else {
    uVar9 = 0xffffffffffffffff;
    do {
      uVar9 = uVar9 + 1;
    } while (param_1[uVar9] != 0);
    if (uVar9 < 0x100000000) {
      WindowsDeleteString();
      local_130 = 0;
      DVar5 = WindowsCreateString(param_1,uVar9 & 0xffffffff,&local_130);
      goto LAB_140002cce;
    }
    DVar5 = 0x80070216;
  }
  if ((int)DVar5 < 0) goto LAB_140003065;
  local_e0 = 0;
  local_d0 = 0;
  local_b8 = '\0';
  uStack_c0 = 0;
  local_b0 = '\0';
  local_a0 = 0;
  local_90 = 0;
  local_80 = 0;
  local_68 = 0;
  local_c8 = 0;
  local_78 = (uchar **)0x0;
  uStack_70 = 0;
  local_d8 = 0;
  local_b4 = 0;
  local_ac = 0;
  local_a8 = (longlong *)0x0;
  local_98 = 0;
  local_8c = 0;
  local_64 = 0;
  local_100 = 0;
  local_f8 = 0;
  DVar5 = (**(code **)(lRam0000000000000000 + 0x78))(0,local_120,local_e8,&local_100);
  if (local_b0 == '\0') {
LAB_1400030ed:
    DVar5 = 0x80070005;
  }
  else {
    if ((int)DVar5 < 0) {
      if (DVar5 != 0x80070002) goto LAB_140002fec;
      goto LAB_1400030ed;
    }
    if ((local_100 & 0x10) != 0) goto LAB_1400030ed;
    if ((local_f8 & 0x10) == 0) {
      if (local_ac != 1) goto LAB_1400030ed;
      if ((local_100 & 1) == 0) {
        if ((local_f8 & 1) == 0) {
          if (local_e8[0] != 0) goto LAB_1400030ed;
          if (local_b8 == '\0') {
            DVar5 = 0x80070002;
          }
          else {
            *param_2 = local_b4;
          }
          if ((local_100 & 8) == 0) {
            if ((local_f8 & 8) == 0) {
              if (-1 < (int)DVar5) {
                if (DAT_140019bc0 == '\0') {
LAB_140002e52:
                  if ((local_100 >> 10 & 1) == 0) {
                    if ((local_f8 >> 10 & 1) == 0) {
                      pSecurityDescriptor =
                           &`private:_static_long___cdecl_CRuntimeBroker::CheckActivationPermissions(void*___ptr64)'
                            ::__l2::defaultActivationPermission;
                      if (local_78 != (uchar **)0x0) {
                        pSecurityDescriptor = local_78;
                      }
                      HVar6 = CoImpersonateClient();
                      if (HVar6 < 0) {
                        if (HVar6 != -0x7ffefee9) goto LAB_140003218;
                        DVar5 = 0;
                      }
                      else {
                        local_110 = &Microsoft::WRL::Wrappers::
                                     HandleT<Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits>
                                     ::_vftable_;
                        local_108 = (HANDLE)0x0;
                        ThreadHandle = GetCurrentThread();
                        BVar7 = OpenThreadToken(ThreadHandle,8,1,&local_108);
                        if (BVar7 == 0) {
                          DVar5 = GetLastError();
                          if (0 < (int)DVar5) {
                            DVar5 = DVar5 & 0xffff | 0x80070000;
                          }
                        }
                        else {
                          DVar5 = 0;
                        }
                        CoRevertToSelf();
                        if (-1 < (int)DVar5) {
                          BVar7 = InitOnceExecuteOnce(&
                                                  `public:_static_void*___ptr64___cdecl_CRuntimeBroker::GetSelfSid(void)'
                                                  ::__l2::rtbSelfSidInitOnce,QueryProcessTokenSid,
                                                  (PVOID)0x0,(LPVOID *)0x0);
                          PrincipalSelfSid = &s_rtbSelfSid;
                          local_58.PrivilegeCount = 1;
                          local_58.Control = 0;
                          local_58.Privilege[0].Luid.LowPart = 0;
                          local_58.Privilege[0].Luid.HighPart = 0;
                          local_58.Privilege[0].Attributes = 0;
                          local_118[1] = 0x14;
                          local_118[0] = 0;
                          if (BVar7 == 0) {
                            PrincipalSelfSid = (uchar **)0x0;
                          }
                          local_128[0] = 0;
                          local_40.GenericRead = 0;
                          local_40.GenericWrite = 0;
                          local_40.GenericExecute = 0;
                          local_40.GenericAll = 0;
                          BVar7 = AccessCheckByType(pSecurityDescriptor,PrincipalSelfSid,local_108,8
                                                    ,(POBJECT_TYPE_LIST)0x0,0,&local_40,&local_58,
                                                    local_118 + 1,local_118,local_128);
                          if (BVar7 == 0) {
                            DVar5 = GetLastError();
                            if (0 < (int)DVar5) {
                              DVar5 = DVar5 & 0xffff | 0x80070000;
                            }
                            if ((int)DVar5 < 0) goto LAB_140002fa8;
                          }
                          DVar5 = 0x80070005;
                          if (local_128[0] != 0) {
                            DVar5 = 0;
                          }
                        }
LAB_140002fa8:
                        local_110 = &Microsoft::WRL::Wrappers::
                                     HandleT<Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits>
                                     ::_vftable_;
                        if ((local_108 != (HANDLE)0x0) &&
                           (bVar3 = Microsoft::WRL::Wrappers::
                                    HandleT<Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits>
                                    ::InternalClose((
                                                  HandleT<Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits>
                                                  *)&local_110), !bVar3)) {
                          DVar5 = GetLastError();
                          if (0 < (int)DVar5) {
                            DVar5 = DVar5 & 0xffff | 0x80070000;
                          }
                          RaiseException(DVar5,1,0,(ULONG_PTR *)0x0);
                          pcVar1 = (code *)swi(3);
                          lVar8 = (*pcVar1)();
                          return lVar8;
                        }
                        if ((int)DVar5 < 0) {
LAB_140003218:
                          DVar5 = 0x80070005;
                        }
                      }
                    }
                    else {
                      DVar5 = 0x8007000d;
                    }
                  }
                  else {
                    DVar5 = 0x80070002;
                  }
                }
                else {
                  cVar4 = '\0';
                  if (local_8c._4_1_ != '\0') {
                    cVar4 = local_8c._5_1_;
                  }
                  if ((local_100 >> 8 & 1) == 0) {
                    if ((local_f8 >> 8 & 1) == 0) {
                      if (cVar4 != '\0') goto LAB_1400030ed;
                      goto LAB_140002e52;
                    }
                    DVar5 = 0x8007000d;
                  }
                  else {
                    DVar5 = 0x80070002;
                  }
                }
              }
            }
            else {
              DVar5 = 0x8007000d;
            }
          }
          else {
            DVar5 = 0x80070002;
          }
        }
        else {
          DVar5 = 0x8007000d;
        }
      }
      else {
        DVar5 = 0x80070002;
      }
    }
    else {
      DVar5 = 0x8007000d;
    }
  }
LAB_140002fec:
  if (local_78 != (uchar **)0x0) {
    LocalFree(local_78);
    local_78 = (uchar **)0x0;
    uStack_70 = uStack_70 & 0xffffffffffff0000;
  }
  WindowsDeleteString(local_98);
  plVar2 = local_a8;
  local_98 = 0;
  if (local_a8 != (longlong *)0x0) {
    local_a8 = (longlong *)0x0;
    (**(code **)(*plVar2 + 0x10))();
  }
  WindowsDeleteString(local_c8);
  local_c8 = 0;
  WindowsDeleteString(local_d8);
LAB_140003065:
  if (local_120 != 0) {
    (**(code **)(lRam0000000000000000 + 0x20))();
  }
  WindowsDeleteString(local_130);
  return DVar5;
}



===== InternalClose @ 140003230 =====

/* protected: virtual bool __cdecl Microsoft::WRL::Wrappers::HandleT<struct
   Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits>::InternalClose(void) __ptr64 */

bool __thiscall
Microsoft::WRL::Wrappers::HandleT<Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits>::
InternalClose(HandleT<Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits> *this)

{
  BOOL BVar1;
  
  BVar1 = CloseHandle(*(HANDLE *)(this + 8));
  return BVar1 != 0;
}



===== LogActivation @ 140003260 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: static void __cdecl CRuntimeBroker::LogActivation(struct HSTRING__ * __ptr64,struct _GUID
   const & __ptr64,long,bool,bool) */

void __cdecl
CRuntimeBroker::LogActivation
          (HSTRING__ *param_1,_GUID *param_2,long param_3,bool param_4,bool param_5)

{
  code *pcVar1;
  bool bVar2;
  uchar hObject [8];
  _tlgProvider_t *p_Var3;
  char cVar4;
  BOOL BVar5;
  uint uVar6;
  DWORD dwErrCode;
  wchar_t *pwVar7;
  HSTRING__ *pHVar8;
  _RTL_RUN_ONCE *p_Var9;
  GUID *pGVar10;
  ComPtr<ICallingProcessInfo> aCVar11 [8];
  _GUID *lpExeName;
  _GUID *p_Var12;
  wchar_t *pwVar13;
  wchar_t *pwVar14;
  undefined1 auStackY_408 [32];
  DWORD local_3a8;
  char local_3a4;
  HSTRING__ *local_3a0;
  uint local_398;
  uchar local_390 [8];
  ComPtr<ICallingProcessInfo> local_388 [8];
  _GUID *local_380;
  _GUID *local_378;
  _GUID *local_370;
  _GUID *local_368;
  _GUID *local_360;
  _GUID local_358 [17];
  _GUID local_248 [33];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_408;
  p_Var12 = (_GUID *)0x0;
  lpExeName = (_GUID *)0x0;
  p_Var9 = &`public:_static_unsigned_short_const*___ptr64___cdecl_CRuntimeBroker::GetBrokerAumid(void)'
            ::__l2::brokerAumidInitOnce;
  local_3a4 = param_4;
  local_3a0 = param_1;
  local_398 = param_3;
  local_380 = param_2;
  BVar5 = InitOnceExecuteOnce(&`public:_static_unsigned_short_const*___ptr64___cdecl_CRuntimeBroker::GetBrokerAumid(void)'
                               ::__l2::brokerAumidInitOnce,ReadBrokerAumid,(PVOID)0x0,(LPVOID *)0x0)
  ;
  if ((BVar5 == 0) ||
     (p_Var9 = _s_brokerAumid, pwVar7 = (wchar_t *)WindowsGetStringRawBuffer(_s_brokerAumid,0),
     (_GUID *)pwVar7 == (_GUID *)0x0)) {
    pwVar7 = L"ERROR";
  }
  uVar6 = CoImpersonateClient();
  if ((int)uVar6 < 0) {
    bVar2 = false;
LAB_1400035e0:
    if (2 < DAT_140019008) {
      local_3a8 = uVar6;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::Write<_tlgWrapperByVal<4>_>
                ((_tlgProvider_t *)p_Var9,&DAT_1400152e2,lpExeName,p_Var12,
                 (_tlgWrapperByVal<4> *)&local_3a8);
    }
    pwVar14 = L"ERROR";
    if (bVar2) goto LAB_14000334b;
  }
  else {
    local_3a8 = 0x82;
    lpExeName = local_358;
    bVar2 = true;
    p_Var9 = (_RTL_RUN_ONCE *)0xfffffffffffffffb;
    uVar6 = GetApplicationUserModelIdFromToken(0xfffffffffffffffb,&local_3a8);
    if (uVar6 == 0) {
      pwVar14 = (wchar_t *)local_358;
    }
    else if (uVar6 == 0x3d57) {
      pwVar14 = L"";
    }
    else {
      pwVar14 = (wchar_t *)0x0;
      if (0 < (int)uVar6) {
        uVar6 = uVar6 & 0xffff | 0x80070000;
      }
      if ((int)uVar6 < 0) goto LAB_1400035e0;
    }
LAB_14000334b:
    CoRevertToSelf();
  }
  pwVar13 = (wchar_t *)0x0;
  local_388[0] = (ComPtr<ICallingProcessInfo>)0x0;
  local_388[1] = (ComPtr<ICallingProcessInfo>)0x0;
  local_388[2] = (ComPtr<ICallingProcessInfo>)0x0;
  local_388[3] = (ComPtr<ICallingProcessInfo>)0x0;
  local_388[4] = (ComPtr<ICallingProcessInfo>)0x0;
  local_388[5] = (ComPtr<ICallingProcessInfo>)0x0;
  local_388[6] = (ComPtr<ICallingProcessInfo>)0x0;
  local_388[7] = (ComPtr<ICallingProcessInfo>)0x0;
  local_390[0] = '\0';
  local_390[1] = '\0';
  local_390[2] = '\0';
  local_390[3] = '\0';
  local_390[4] = '\0';
  local_390[5] = '\0';
  local_390[6] = '\0';
  local_390[7] = '\0';
  Microsoft::WRL::ComPtr<ICallingProcessInfo>::InternalRelease(local_388);
  pGVar10 = &_GUID_68c6a1b9_de39_42c3_8d28_bf40a5126541;
  uVar6 = CoGetCallContext((IID *)&_GUID_68c6a1b9_de39_42c3_8d28_bf40a5126541,(void **)local_388);
  aCVar11 = local_388;
  hObject = local_390;
  if (-1 < (int)uVar6) {
    pcVar1 = *(code **)(*(longlong *)local_388 + 0x18);
    if ((undefined1 *)((longlong)local_390 - 1U) < (undefined1 *)0xfffffffffffffffe) {
      dwErrCode = GetLastError();
      CloseHandle((HANDLE)hObject);
      SetLastError(dwErrCode);
      param_4 = (bool)local_3a4;
    }
    lpExeName = (_GUID *)local_390;
    local_390[0] = '\0';
    local_390[1] = '\0';
    local_390[2] = '\0';
    local_390[3] = '\0';
    local_390[4] = '\0';
    local_390[5] = '\0';
    local_390[6] = '\0';
    local_390[7] = '\0';
    uVar6 = (*pcVar1)(aCVar11,0x1000);
    pGVar10 = (GUID *)aCVar11;
    if (-1 < (int)uVar6) {
      lpExeName = local_248;
      local_3a8 = 0x104;
      pGVar10 = (GUID *)local_390;
      BVar5 = QueryFullProcessImageNameW((HANDLE)local_390,0,(LPWSTR)lpExeName,&local_3a8);
      if (BVar5 != 0) {
        pwVar13 = (wchar_t *)local_248;
        goto LAB_14000341e;
      }
      uVar6 = GetLastError();
      if (0 < (int)uVar6) {
        uVar6 = uVar6 & 0xffff | 0x80070000;
      }
      p_Var12 = (_GUID *)pwVar13;
      if (-1 < (int)uVar6) goto LAB_14000341e;
    }
  }
  if (2 < DAT_140019008) {
    local_3a8 = uVar6;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)pGVar10,&DAT_1400152b7,lpExeName,p_Var12,
               (_tlgWrapperByVal<4> *)&local_3a8);
  }
  pwVar13 = L"ERROR";
LAB_14000341e:
  if (DAT_140019bc0 == '\0') {
    if ((4 < DAT_140019008) && (cVar4 = _tlgKeywordOn(0x140019008,0x200000000000), cVar4 != '\0')) {
      local_370 = (_GUID *)0x140014a90;
      if (param_4 == false) {
        local_370 = (_GUID *)0x140014ab8;
      }
      local_3a8 = local_398;
      local_378 = local_380;
      local_368 = (_GUID *)pwVar14;
      local_360 = (_GUID *)pwVar13;
      pHVar8 = (HSTRING__ *)WindowsGetStringRawBuffer(local_3a0,0);
      p_Var3 = (_tlgProvider_t *)local_3a0;
      local_3a0 = pHVar8;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>_>
                (p_Var3,&DAT_1400153c6,lpExeName,(_GUID *)pwVar13,
                 (_tlgWrapSz<unsigned_short> *)&local_3a0,(_tlgWrapperByRef<16> *)&local_378,
                 (_tlgWrapperByVal<4> *)&local_3a8,(_tlgWrapSz<unsigned_short> *)&local_370,
                 (_tlgWrapSz<unsigned_short> *)&local_368,(_tlgWrapSz<unsigned_short> *)&local_360);
    }
  }
  else if (4 < DAT_140019008) {
    local_360 = (_GUID *)0x140014a90;
    if (param_4 == false) {
      local_360 = (_GUID *)0x140014ab8;
    }
    local_3a8 = local_398;
    local_378 = (_GUID *)pwVar7;
    local_370 = (_GUID *)pwVar13;
    local_368 = (_GUID *)pwVar14;
    pHVar8 = (HSTRING__ *)WindowsGetStringRawBuffer(local_3a0,0);
    p_Var3 = (_tlgProvider_t *)local_3a0;
    local_3a0 = pHVar8;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapSz<unsigned_short>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>_>
              (p_Var3,&DAT_140015310,lpExeName,(_GUID *)pwVar13,
               (_tlgWrapSz<unsigned_short> *)&local_3a0,(_tlgWrapperByRef<16> *)&local_380,
               (_tlgWrapperByVal<4> *)&local_3a8,(_tlgWrapSz<unsigned_short> *)&local_360,
               (_tlgWrapSz<unsigned_short> *)&local_368,(_tlgWrapSz<unsigned_short> *)&local_370,
               (_tlgWrapSz<unsigned_short> *)&local_378);
  }
  if ((undefined1 *)((longlong)local_390 - 1U) < (undefined1 *)0xfffffffffffffffe) {
    CloseHandle((HANDLE)local_390);
  }
  aCVar11 = local_388;
  if (local_388 != (ComPtr<ICallingProcessInfo>  [8])0x0) {
    local_388[0] = (ComPtr<ICallingProcessInfo>)0x0;
    local_388[1] = (ComPtr<ICallingProcessInfo>)0x0;
    local_388[2] = (ComPtr<ICallingProcessInfo>)0x0;
    local_388[3] = (ComPtr<ICallingProcessInfo>)0x0;
    local_388[4] = (ComPtr<ICallingProcessInfo>)0x0;
    local_388[5] = (ComPtr<ICallingProcessInfo>)0x0;
    local_388[6] = (ComPtr<ICallingProcessInfo>)0x0;
    local_388[7] = (ComPtr<ICallingProcessInfo>)0x0;
    (**(code **)(*(longlong *)aCVar11 + 0x10))();
  }
  return;
}



===== InternalRelease @ 140003720 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* protected: unsigned long __cdecl Microsoft::WRL::ComPtr<struct
   ICallingProcessInfo>::InternalRelease(void) __ptr64 */

ulong __thiscall
Microsoft::WRL::ComPtr<ICallingProcessInfo>::InternalRelease(ComPtr<ICallingProcessInfo> *this)

{
  longlong *plVar1;
  ulong uVar2;
  
  plVar1 = *(longlong **)this;
  if (plVar1 == (longlong *)0x0) {
    return 0;
  }
  *(undefined8 *)this = 0;
  uVar2 = (**(code **)(*plVar1 + 0x10))();
  return uVar2;
}



===== Return_Hr @ 14000374c =====

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



===== ReportFailure_Hr<1> @ 140003770 =====

/* void __cdecl wil::details::ReportFailure_Hr<1>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  char *in_stack_ffffffffffffffb8;
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  long local_18;
  long local_14;
  undefined4 local_10;
  
  local_18 = param_7;
  local_14 = HrToNtStatus(param_7);
  local_10 = 0;
  ReportFailure_Base<1,0>
            (param_1,param_2,param_3,param_3,in_stack_ffffffffffffffb8,param_6,
             (ResultStatus *)&local_18,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8);
  return;
}



===== ReportFailure_Base<1,0> @ 1400037c8 =====

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
  undefined1 auStackY_1548 [32];
  undefined1 in_stack_ffffffffffffeb00;
  __uint64 in_stack_ffffffffffffeb10;
  __uint64 in_stack_ffffffffffffeb20;
  FailureInfo aFStack_14c8 [4];
  byte bStack_14c4;
  char acStack_1428 [1024];
  ushort auStack_1028 [2048];
  ulonglong uStack_28;
  undefined8 uStack_20;
  
  uStack_20 = 0x1400076e2;
  uStack_28 = __security_cookie ^ (ulonglong)auStackY_1548;
  memset(aFStack_14c8,0,0x98);
  LogFailure(param_1,param_2,param_3,(char *)0x0,(char *)0x0,param_6,1,param_7,(ushort *)0x0,
             (bool)in_stack_ffffffffffffeb00,auStack_1028,in_stack_ffffffffffffeb10,acStack_1428,
             in_stack_ffffffffffffeb20,aFStack_14c8);
  if ((bStack_14c4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast(aFStack_14c8);
  }
  return;
}



===== HrToNtStatus @ 1400037e0 =====

/* long __cdecl wil::details::HrToNtStatus(long) */

long __cdecl wil::details::HrToNtStatus(long param_1)

{
  if (param_1 < -0x7ff8fffe) {
    if (param_1 == -0x7ff8ffff) {
      return -0x3ffffffe;
    }
    if (param_1 == -0x7fffbffb) {
      return -0x3fffffff;
    }
  }
  else if (param_1 < -0x7ff8fde9) {
    if (param_1 == -0x7ff8fdea) {
      return -0x3fffff6b;
    }
    switch(param_1) {
    case -0x7ff8fffe:
      return -0x3fffffcc;
    case -0x7ff8fffd:
      return -0x3fffffc6;
    case -0x7ff8fff2:
      return -0x3fffffe9;
    case -0x7ff8ffa9:
      return -0x3ffffff3;
    case -0x7ff8ff90:
      return -0x3fffff81;
    case -0x7ff8ff86:
      return -0x3fffffdd;
    case -0x7ff8ff85:
      return -0x3fffffcd;
    case -0x7ff8ff82:
      return -0x3ffffecb;
    case -0x7ff8ff16:
      return -0x7ffffffb;
    }
  }
  else if (param_1 < -0x7ff8fb81) {
    if (param_1 == -0x7ff8fb82) {
      return -0x3fffffa7;
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



===== QueryInterface @ 140003ad0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBroker::QueryInterface(struct _GUID const & __ptr64,void *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall CRuntimeBroker::QueryInterface(CRuntimeBroker *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  *param_2 = (void *)0x0;
  lVar1._0_4_ = param_1->Data1;
  lVar1._4_2_ = param_1->Data2;
  lVar1._6_2_ = param_1->Data3;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)param_1->Data4 + -0x46000000000000c0;
  }
  if (lVar1 != 0) {
    lVar1 = *(longlong *)param_1 + -0x4c6ab12daf86e2e0;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)param_1->Data4 + 0x6fe1ef9a5528a564;
    }
    if (lVar1 != 0) {
      lVar1 = *(longlong *)param_1 + -0x41f965576040ec14;
      if (lVar1 == 0) {
        lVar1 = *(longlong *)param_1->Data4 + -0x2021b4b7cab1f7a3;
      }
      if (lVar1 != 0) {
        return -0x7fffbffe;
      }
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== RecordFeatureUsage @ 140003b60 =====

/* public: void __cdecl wil::details::FeatureStateManager::RecordFeatureUsage(unsigned int,enum
   wil_details_ServiceReportingKind,unsigned __int64) __ptr64 */

void __thiscall
wil::details::FeatureStateManager::RecordFeatureUsage
          (FeatureStateManager *this,uint param_1,wil_details_ServiceReportingKind param_2,
          __uint64 param_3)

{
  FeatureStateManager *SRWLock;
  bool bVar1;
  
  if (*this != (FeatureStateManager)0x0) {
    bVar1 = EnsureStateData(this);
    if (bVar1) {
      bVar1 = details_abi::FeatureStateData::RecordFeatureUsage
                        (*(FeatureStateData **)(this + 0x18),param_1,param_2,param_3);
      if (bVar1) {
        bVar1 = ProcessShutdownInProgress();
        if (!bVar1) {
          SRWLock = this + 0x20;
          AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
          EnsureCoalescedTimer<wil::details::FeatureStateManager>
                    ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
                      *)(this + 0x30),(bool *)(this + 0x41),this);
          if (SRWLock != (FeatureStateManager *)0x0) {
            ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
          }
        }
      }
    }
  }
  return;
}



===== WilApiImpl_SubscribeFeatureStateChangeNotification @ 140003c00 =====

/* void __cdecl wil::details::WilApiImpl_SubscribeFeatureStateChangeNotification(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64),void *
   __ptr64) */

void __cdecl
wil::details::WilApiImpl_SubscribeFeatureStateChangeNotification
          (FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,_func_void_void_ptr *param_2,void *param_3)

{
  __int64 _Var1;
  void *pvVar2;
  
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
  AcquireSRWLockExclusive((PSRWLOCK)&DAT_1400190d8);
  if (DAT_140019148 == 0) {
    DAT_140019148 = 0;
    _Var1 = wil_details_RtlRegisterFeatureConfigurationChangeNotification
                      (<lambda_1ad7ecfab602a777ecf020873216a663>::<lambda_invoker_cdecl>,
                       &g_featureStateManager,pvVar2,&DAT_140019148);
    if ((int)_Var1 != 0) goto LAB_140003c72;
  }
  details_abi::SubscriptionList::SubscribeUnderLock
            ((SubscriptionList *)&DAT_140019100,param_1,param_2,param_3);
LAB_140003c72:
  ReleaseSRWLockExclusive((PSRWLOCK)&DAT_1400190d8);
  return;
}



===== QueueBackgroundUsageReporting @ 140003cc8 =====

/* public: void __cdecl wil::details::EnabledStateManager::QueueBackgroundUsageReporting(unsigned
   int,struct wil_details_FeatureReportingCache * __ptr64) __ptr64 */

void __thiscall
wil::details::EnabledStateManager::QueueBackgroundUsageReporting
          (EnabledStateManager *this,uint param_1,wil_details_FeatureReportingCache *param_2)

{
  EnabledStateManager *SRWLock;
  heap_buffer *this_00;
  undefined8 *_Dst;
  bool bVar1;
  undefined4 *puVar2;
  __uint64 _Var3;
  ulonglong uVar4;
  
  if (*this == (EnabledStateManager)0x0) {
    return;
  }
  bVar1 = ProcessShutdownInProgress();
  if (bVar1) {
    return;
  }
  SRWLock = this + 8;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  this_00 = (heap_buffer *)(this + 0x30);
  if ((ulonglong)(*(longlong *)(this + 0x40) - *(longlong *)this_00) <=
      (*(longlong *)(this + 0x38) - *(longlong *)this_00) + 0x10U) {
    uVar4 = (*(longlong *)(this + 0x40) - *(longlong *)this_00) * 2;
    _Var3 = 0x10;
    if (0x10 < uVar4) {
      _Var3 = uVar4;
    }
    bVar1 = details_abi::heap_buffer::reserve(this_00,_Var3);
    if (!bVar1) goto LAB_140003d79;
  }
  _Dst = *(undefined8 **)(this + 0x38);
  uVar4 = -(ulonglong)(_Dst < *(undefined8 **)(this + 0x40)) &
          *(longlong *)(this + 0x40) - (longlong)_Dst;
  if (_Dst == (undefined8 *)0x0) {
    puVar2 = (undefined4 *)_o__errno();
    *puVar2 = 0x16;
LAB_140003db1:
    _o__invalid_parameter_noinfo();
  }
  else {
    if (uVar4 < 0x10) {
      memset(_Dst,0,uVar4);
      puVar2 = (undefined4 *)_o__errno();
      *puVar2 = 0x22;
      goto LAB_140003db1;
    }
    *_Dst = 0x816dc3;
    _Dst[1] = param_2;
  }
  *(longlong *)(this + 0x38) = *(longlong *)(this + 0x38) + 0x10;
LAB_140003d79:
  EnsureCoalescedTimer<wil::details::EnabledStateManager>
            ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
              *)(this + 0x10),(bool *)(this + 0x18),this);
  if (SRWLock != (EnabledStateManager *)0x0) {
    ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
  }
  return;
}



===== EnsureCoalescedTimer<wil::details::EnabledStateManager> @ 140003dec =====

/* void __cdecl wil::details::EnsureCoalescedTimer<class wil::details::EnabledStateManager>(class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<struct
   _TP_TIMER * __ptr64,void (__cdecl*)(struct _TP_TIMER * __ptr64),&public: static void __cdecl
   wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct _TP_TIMER * __ptr64,struct _TP_TIMER *
   __ptr64,0,std::nullptr_t> > > & __ptr64,bool & __ptr64,class wil::details::EnabledStateManager *
   __ptr64) */

void __cdecl
wil::details::EnsureCoalescedTimer<wil::details::EnabledStateManager>
          (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>_>
           *param_1,bool *param_2,EnabledStateManager *param_3)

{
  PTP_TIMER p_Var1;
  last_error_context local_res10 [8];
  
  if (*param_2 == false) {
    if (*(longlong *)param_1 == 0) {
      last_error_context::last_error_context(local_res10);
      p_Var1 = CreateThreadpoolTimer
                         (<lambda_0374aa0a5d1201b2358c6bce99369c58>::<lambda_invoker_cdecl>,param_3,
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



===== SubscribeToUsageFlush @ 140003e70 =====

/* public: void __cdecl wil::details::FeatureStateManager::SubscribeToUsageFlush(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64)) __ptr64
    */

void __thiscall
wil::details::FeatureStateManager::SubscribeToUsageFlush
          (FeatureStateManager *this,FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,
          _func_void_void_ptr *param_2)

{
  FeatureStateManager *SRWLock;
  longlong *plVar1;
  undefined8 *_Dst;
  longlong lVar2;
  bool bVar3;
  FEATURE_STATE_CHANGE_SUBSCRIPTION__ *pFVar4;
  undefined4 *puVar5;
  longlong *plVar6;
  __uint64 _Var7;
  ulonglong uVar8;
  
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  if (*this == (FeatureStateManager)0x0) {
    return;
  }
  bVar3 = ProcessShutdownInProgress();
  if (bVar3) {
    return;
  }
  bVar3 = EnsureStateData(this);
  if (!bVar3) {
    return;
  }
  SRWLock = this + 0x20;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  EnsureSubscribedToProcessWideUsageFlushUnderLock(this);
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  plVar1 = *(longlong **)(this + 0xc0);
  pFVar4 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  plVar6 = plVar1;
  while (pFVar4 < (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
                  ((ulonglong)(*(longlong *)(this + 200) - (longlong)plVar1) >> 4)) {
    if (*plVar6 == 0) {
      plVar1[(longlong)pFVar4 * 2] = (longlong)param_2;
      plVar1[(longlong)pFVar4 * 2 + 1] = 0;
      *param_1 = pFVar4 + 1;
      goto LAB_140003f79;
    }
    plVar6 = plVar6 + 2;
    pFVar4 = pFVar4 + 1;
  }
  if ((ulonglong)(*(longlong *)(this + 0xd0) - (longlong)plVar1) <=
      (*(longlong *)(this + 200) - (longlong)plVar1) + 0x10U) {
    uVar8 = (*(longlong *)(this + 0xd0) - (longlong)plVar1) * 2;
    _Var7 = 0x10;
    if (0x10 < uVar8) {
      _Var7 = uVar8;
    }
    bVar3 = details_abi::heap_buffer::reserve((heap_buffer *)(this + 0xc0),_Var7);
    if (!bVar3) goto LAB_140003f79;
  }
  _Dst = *(undefined8 **)(this + 200);
  uVar8 = 0;
  if (_Dst < *(undefined8 **)(this + 0xd0)) {
    uVar8 = *(longlong *)(this + 0xd0) - (longlong)_Dst;
  }
  if (_Dst == (undefined8 *)0x0) {
    puVar5 = (undefined4 *)_o__errno();
    *puVar5 = 0x16;
LAB_140003fbb:
    _o__invalid_parameter_noinfo();
  }
  else {
    if (uVar8 < 0x10) {
      memset(_Dst,0,uVar8);
      puVar5 = (undefined4 *)_o__errno();
      *puVar5 = 0x22;
      goto LAB_140003fbb;
    }
    *_Dst = param_2;
    _Dst[1] = 0;
  }
  lVar2 = *(longlong *)(this + 200);
  *(longlong *)(this + 200) = lVar2 + 0x10;
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
             ((ulonglong)((lVar2 + 0x10) - *(longlong *)(this + 0xc0)) >> 4);
LAB_140003f79:
  if (*param_1 != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
    *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)((ulonglong)*param_1 | 0x80000000);
  }
  if (SRWLock != (FeatureStateManager *)0x0) {
    ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
  }
  return;
}



===== EnsureStateData @ 140004030 =====

/* private: bool __cdecl wil::details::FeatureStateManager::EnsureStateData(void) __ptr64 */

bool __thiscall wil::details::FeatureStateManager::EnsureStateData(FeatureStateManager *this)

{
  FeatureStateManager *SRWLock;
  DWORD dwErrCode;
  long lVar1;
  longlong lVar2;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *local_res8;
  
  if (*(longlong *)(this + 0x18) == 0) {
    dwErrCode = GetLastError();
    lVar2 = 0;
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
      lVar2 = *(longlong *)(this + 0x10) + 0x20;
      if (*(longlong *)(this + 0x10) == 0) {
        lVar2 = 0;
      }
    }
    SRWLock = this + 0x20;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    if (*(longlong *)(this + 0x18) == 0) {
      *(longlong *)(this + 0x18) = lVar2;
    }
    if (SRWLock != (FeatureStateManager *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
    ::SetLastError(dwErrCode);
  }
  return *(longlong *)(this + 0x18) != 0;
}



===== ProcessShutdownInProgress @ 14000410c =====

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



===== EnsureSubscribedToProcessWideUsageFlushUnderLock @ 140004144 =====

/* private: void __cdecl
   wil::details::FeatureStateManager::EnsureSubscribedToProcessWideUsageFlushUnderLock(void) __ptr64
    */

void __thiscall
wil::details::FeatureStateManager::EnsureSubscribedToProcessWideUsageFlushUnderLock
          (FeatureStateManager *this)

{
  PSRWLOCK SRWLock;
  longlong *plVar1;
  undefined8 *_Dst;
  bool bVar2;
  PVOID pvVar3;
  undefined4 *puVar4;
  longlong *plVar5;
  ulonglong uVar6;
  __uint64 _Var7;
  ulonglong uVar8;
  
  if (*(longlong *)(this + 0xe0) != 0) {
    return;
  }
  SRWLock = *(PSRWLOCK *)(this + 0x18);
  if (SRWLock == (PSRWLOCK)0x0) {
    return;
  }
  *(undefined8 *)(this + 0xe0) = 0;
  AcquireSRWLockExclusive(SRWLock);
  *(undefined8 *)(this + 0xe0) = 0;
  plVar1 = *(longlong **)(SRWLock + 0x1e);
  uVar8 = (longlong)SRWLock[0x1f].Ptr - (longlong)plVar1;
  uVar6 = 0;
  plVar5 = plVar1;
  while (uVar6 < uVar8 >> 4) {
    if (*plVar5 == 0) {
      plVar1[uVar6 * 2] =
           (longlong)<lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>;
      plVar1[uVar6 * 2 + 1] = (longlong)this;
      *(ulonglong *)(this + 0xe0) = uVar6 + 1;
      goto LAB_14000423e;
    }
    plVar5 = plVar5 + 2;
    uVar6 = uVar6 + 1;
  }
  uVar6 = (longlong)SRWLock[0x20].Ptr - (longlong)plVar1;
  if (uVar6 <= uVar8 + 0x10) {
    uVar6 = uVar6 * 2;
    _Var7 = 0x10;
    if (0x10 < uVar6) {
      _Var7 = uVar6;
    }
    bVar2 = details_abi::heap_buffer::reserve((heap_buffer *)(SRWLock + 0x1e),_Var7);
    if (!bVar2) goto LAB_14000423e;
  }
  _Dst = SRWLock[0x1f].Ptr;
  uVar6 = -(ulonglong)(_Dst < SRWLock[0x20].Ptr) & (longlong)SRWLock[0x20].Ptr - (longlong)_Dst;
  if (_Dst == (undefined8 *)0x0) {
    puVar4 = (undefined4 *)_o__errno();
    *puVar4 = 0x16;
LAB_140004270:
    _o__invalid_parameter_noinfo();
  }
  else {
    if (uVar6 < 0x10) {
      memset(_Dst,0,uVar6);
      puVar4 = (undefined4 *)_o__errno();
      *puVar4 = 0x22;
      goto LAB_140004270;
    }
    *_Dst = <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>;
    _Dst[1] = this;
  }
  pvVar3 = (PVOID)((longlong)SRWLock[0x1f].Ptr + 0x10);
  SRWLock[0x1f].Ptr = pvVar3;
  *(ulonglong *)(this + 0xe0) = (ulonglong)((longlong)pvVar3 - (longlong)SRWLock[0x1e].Ptr) >> 4;
LAB_14000423e:
  ReleaseSRWLockExclusive(SRWLock);
  return;
}



===== SubscribeUnderLock @ 1400042d0 =====

/* public: void __cdecl wil::details_abi::SubscriptionList::SubscribeUnderLock(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64),void *
   __ptr64) __ptr64 */

void __thiscall
wil::details_abi::SubscriptionList::SubscribeUnderLock
          (SubscriptionList *this,FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,
          _func_void_void_ptr *param_2,void *param_3)

{
  longlong lVar1;
  undefined8 *_Dst;
  bool bVar2;
  FEATURE_STATE_CHANGE_SUBSCRIPTION__ *pFVar3;
  undefined4 *puVar4;
  longlong lVar5;
  __uint64 _Var6;
  ulonglong uVar7;
  
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  lVar1 = *(longlong *)(this + 0x28);
  lVar5 = 0;
  pFVar3 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  while (pFVar3 < (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
                  ((ulonglong)(*(longlong *)(this + 0x30) - lVar1) >> 4)) {
    if (*(longlong *)(lVar5 + lVar1) == 0) {
      *(_func_void_void_ptr **)(lVar1 + (longlong)pFVar3 * 0x10) = param_2;
      *(void **)(lVar1 + 8 + (longlong)pFVar3 * 0x10) = param_3;
      *param_1 = pFVar3 + 1;
      return;
    }
    lVar5 = lVar5 + 0x10;
    pFVar3 = pFVar3 + 1;
  }
  if ((ulonglong)(*(longlong *)(this + 0x38) - lVar1) <=
      (*(longlong *)(this + 0x30) - lVar1) + 0x10U) {
    uVar7 = (*(longlong *)(this + 0x38) - lVar1) * 2;
    _Var6 = 0x10;
    if (0x10 < uVar7) {
      _Var6 = uVar7;
    }
    bVar2 = heap_buffer::reserve((heap_buffer *)(this + 0x28),_Var6);
    if (!bVar2) {
      return;
    }
  }
  _Dst = *(undefined8 **)(this + 0x30);
  uVar7 = 0;
  if (_Dst < *(undefined8 **)(this + 0x38)) {
    uVar7 = *(longlong *)(this + 0x38) - (longlong)_Dst;
  }
  if (_Dst == (undefined8 *)0x0) {
    puVar4 = (undefined4 *)_o__errno();
    *puVar4 = 0x16;
  }
  else {
    if (0xf < uVar7) {
      *_Dst = param_2;
      _Dst[1] = param_3;
      goto LAB_140004375;
    }
    memset(_Dst,0,uVar7);
    puVar4 = (undefined4 *)_o__errno();
    *puVar4 = 0x22;
  }
  _o__invalid_parameter_noinfo();
LAB_140004375:
  lVar1 = *(longlong *)(this + 0x30);
  *(longlong *)(this + 0x30) = lVar1 + 0x10;
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
             ((ulonglong)((lVar1 + 0x10) - *(longlong *)(this + 0x28)) >> 4);
  return;
}



===== push_back @ 140004410 =====

/* public: bool __cdecl wil::details_abi::heap_buffer::push_back(void const * __ptr64,unsigned
   __int64) __ptr64 */

bool __thiscall
wil::details_abi::heap_buffer::push_back(heap_buffer *this,void *param_1,__uint64 param_2)

{
  void *_Dst;
  bool bVar1;
  undefined4 *puVar2;
  __uint64 _Var3;
  ulonglong uVar4;
  
  if ((ulonglong)(*(longlong *)(this + 0x10) - *(longlong *)this) <=
      (*(longlong *)(this + 8) - *(longlong *)this) + param_2) {
    uVar4 = (*(longlong *)(this + 0x10) - *(longlong *)this) * 2;
    _Var3 = param_2;
    if (param_2 < uVar4) {
      _Var3 = uVar4;
    }
    bVar1 = reserve(this,_Var3);
    if (!bVar1) {
      return false;
    }
  }
  _Dst = *(void **)(this + 8);
  uVar4 = 0;
  if (_Dst < *(void **)(this + 0x10)) {
    uVar4 = *(longlong *)(this + 0x10) - (longlong)_Dst;
  }
  if (param_2 == 0) goto LAB_140004491;
  if (_Dst == (void *)0x0) {
LAB_1400044ad:
    puVar2 = (undefined4 *)_o__errno();
    *puVar2 = 0x16;
  }
  else {
    if ((param_1 != (void *)0x0) && (param_2 <= uVar4)) {
      memcpy(_Dst,param_1,param_2);
      goto LAB_140004491;
    }
    memset(_Dst,0,uVar4);
    if (param_1 == (void *)0x0) goto LAB_1400044ad;
    if (param_2 <= uVar4) goto LAB_140004491;
    puVar2 = (undefined4 *)_o__errno();
    *puVar2 = 0x22;
  }
  _o__invalid_parameter_noinfo();
LAB_140004491:
  *(__uint64 *)(this + 8) = *(longlong *)(this + 8) + param_2;
  return true;
}



===== reserve @ 140004500 =====

/* public: bool __cdecl wil::details_abi::heap_buffer::reserve(unsigned __int64) __ptr64 */

bool __thiscall wil::details_abi::heap_buffer::reserve(heap_buffer *this,__uint64 param_1)

{
  LPVOID lpMem;
  DWORD dwErrCode;
  void *_Dst;
  HANDLE hHeap;
  __uint64 _DstSize;
  rsize_t _MaxCount;
  
  if ((ulonglong)(*(longlong *)(this + 0x10) - *(longlong *)this) < param_1) {
    dwErrCode = GetLastError();
    _DstSize = (param_1 & 0xffffffffffffffc0) + 0x40;
    _Dst = details::ProcessHeapAlloc(0,_DstSize);
    if (_Dst == (void *)0x0) {
      ::SetLastError(dwErrCode);
      return false;
    }
    _MaxCount = *(longlong *)(this + 8) - (longlong)*(void **)this;
    memcpy_s(_Dst,_DstSize,*(void **)this,_MaxCount);
    lpMem = *(LPVOID *)(this + 0x18);
    *(void **)(this + 0x18) = _Dst;
    if (lpMem != (LPVOID)0x0) {
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,lpMem);
    }
    *(void **)this = _Dst;
    *(rsize_t *)(this + 8) = _MaxCount + (longlong)_Dst;
    *(__uint64 *)(this + 0x10) = (longlong)_Dst + _DstSize;
    ::SetLastError(dwErrCode);
  }
  return true;
}



===== RecordFeatureUsage @ 1400045f8 =====

/* public: bool __cdecl wil::details_abi::FeatureStateData::RecordFeatureUsage(unsigned int,enum
   wil_details_ServiceReportingKind,unsigned __int64) __ptr64 */

bool __thiscall
wil::details_abi::FeatureStateData::RecordFeatureUsage
          (FeatureStateData *this,uint param_1,wil_details_ServiceReportingKind param_2,
          __uint64 param_3)

{
  bool bVar1;
  FeatureStateData *local_18 [2];
  
  if (param_2 == 0xfe) {
    RecordUsage(this);
    bVar1 = true;
  }
  else if ((param_2 < 200) || ((0xff < (int)param_2 && (param_2 < 0x200)))) {
    AcquireSRWLockExclusive((PSRWLOCK)this);
    local_18[0] = this;
    bVar1 = RecordFeatureUsageUnderLock(this,param_1,param_2,param_3);
    details::
    unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
                *)local_18);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}



===== RecordUsage @ 140004690 =====

/* public: void __cdecl wil::details_abi::FeatureStateData::RecordUsage(void) __ptr64 */

void __thiscall wil::details_abi::FeatureStateData::RecordUsage(FeatureStateData *this)

{
  UsageIndexes local_c8 [192];
  
  UsageIndexes::UsageIndexes(local_c8);
  AcquireSRWLockExclusive((PSRWLOCK)this);
  RetrieveUsageUnderLock(this,local_c8);
  if (this != (FeatureStateData *)0x0) {
    ReleaseSRWLockExclusive((PSRWLOCK)this);
  }
  UsageIndexes::Record(local_c8);
  UsageIndexes::~UsageIndexes(local_c8);
  return;
}



===== ~UsageIndexes @ 1400046fc =====

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
  if (pvVar1 == (void *)0x0) {
    return;
  }
  details::FreeProcessHeap(pvVar1);
  return;
}



===== UsageIndexes @ 14000475c =====

/* public: __cdecl wil::details_abi::UsageIndexes::UsageIndexes(void) __ptr64 */

UsageIndexes * __thiscall wil::details_abi::UsageIndexes::UsageIndexes(UsageIndexes *this)

{
  *(undefined4 *)this = 0x40000;
  this[4] = (UsageIndexes)0x1;
  this[8] = (UsageIndexes)0x0;
  *(undefined2 *)(this + 6) = 4;
  *(undefined8 *)(this + 0x10) = 4;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x38) = 0;
  this[0x3a] = (UsageIndexes)0x0;
  *(undefined2 *)(this + 0x46) = 4;
  *(undefined4 *)(this + 0x40) = 0x40000;
  this[0x44] = (UsageIndexes)0x1;
  this[0x48] = (UsageIndexes)0x2;
  *(undefined8 *)(this + 0x50) = 8;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined2 *)(this + 0x78) = 0;
  this[0x7a] = (UsageIndexes)0x0;
  *(undefined4 *)(this + 0x80) = 0x40000;
  this[0x84] = (UsageIndexes)0x1;
  *(undefined2 *)(this + 0x86) = 0;
  this[0x88] = (UsageIndexes)0x1;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined2 *)(this + 0xb8) = 0;
  this[0xba] = (UsageIndexes)0x0;
  return this;
}



===== Record @ 14000481c =====

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



===== RecordWnfUsageIndex @ 14000492c =====

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
  RawUsageIndex *pRVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined1 auStackY_1178 [32];
  undefined1 *puVar9;
  uint local_1138;
  undefined4 local_1134 [3];
  undefined2 local_1128;
  undefined2 local_1126;
  RawUsageIndex local_1124;
  ushort local_1122;
  RawUsageIndex local_1120;
  ulonglong local_1118;
  undefined8 local_1110;
  undefined8 local_1108;
  undefined8 uStack_1100;
  void *local_10f8;
  undefined2 local_10f0;
  undefined1 local_10ee;
  undefined8 local_10e8;
  undefined8 local_10e0;
  undefined8 *local_10d8;
  undefined8 *puStack_10d0;
  undefined2 *local_10c8;
  undefined1 local_10b8 [8];
  undefined **local_10b0;
  undefined8 local_10a8;
  undefined8 uStack_10a0;
  undefined2 *local_1098;
  undefined ***local_1048;
  undefined1 local_1038 [4096];
  ulonglong local_38;
  undefined8 local_30;
  
  local_30 = 0x140004950;
  local_38 = __security_cookie ^ (ulonglong)auStackY_1178;
  p_Var1 = param_1 + param_2 * 8;
  uVar8 = 0;
  local_10e0 = 0;
  pRVar6 = param_3;
  do {
    local_1128 = *(undefined2 *)param_3;
    local_1122 = *(ushort *)(param_3 + 6);
    uVar5 = (ulonglong)local_1122;
    local_1120 = param_3[8];
    local_1126 = *(undefined2 *)(param_3 + 2);
    local_1124 = param_3[4];
    if (local_1122 == 0) {
      local_1118 = 0;
    }
    else if (local_1120 == (RawUsageIndex)0x1) {
      local_1118 = uVar5 + 2;
    }
    else {
      local_1118 = uVar5;
      if (local_1120 == (RawUsageIndex)0x2) {
        local_1118 = uVar5 + 4;
      }
    }
    local_1110 = 0;
    puVar9 = local_1038;
    local_10f8 = (void *)0x0;
    local_1108 = 0;
    uStack_1100 = 0;
    local_10f0 = 0;
    local_10ee = 0;
    local_1134[0] = 0;
    local_1138 = 0x1000;
    _Var4 = wil_details_NtQueryWnfStateData(param_1,uVar5,pRVar6,local_1134,puVar9,&local_1138);
    details::NtStatusToHr((long)_Var4);
    if ((long)_Var4 != 0) {
      local_1134[0] = 0;
      local_1138 = 0;
    }
    pRVar6 = (RawUsageIndex *)(ulonglong)local_1138;
    uVar7 = 0x1000;
    RawUsageIndex::SetBuffer((RawUsageIndex *)&local_1128,local_1038,(__uint64)pRVar6,0x1000);
    pvVar2 = local_10f8;
    if (local_10f0._1_1_ != '\0') {
      local_10f8 = (void *)0x0;
      if (pvVar2 != (void *)0x0) {
        details::FreeProcessHeap(pvVar2);
      }
      return;
    }
    local_10d8 = &local_10e8;
    local_10e8 = 0;
    puStack_10d0 = &local_10e0;
    local_10c8 = &local_1128;
    local_10b0 = &wistd::__function::
                  __func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
                  ::_vftable_;
    local_1048 = &local_10b0;
    local_1098 = local_10c8;
    local_10a8 = local_10d8;
    uStack_10a0 = puStack_10d0;
    bVar3 = RawUsageIndex::Iterate(param_3,local_10b8);
    if ((char)local_10f0 == '\0') {
LAB_140004b00:
      param_1 = param_1 + 8;
      local_10e0 = local_10e8;
    }
    else {
      pRVar6 = (RawUsageIndex *)(ulonglong)(uint)((int)local_1108 - (int)local_1110);
      _Var4 = wil_details_NtUpdateWnfStateData
                        (param_1,local_1110,(int)local_1108 - (int)local_1110,uVar7,puVar9,
                         local_1134[0],1);
      if ((int)_Var4 != -0x3fffffff) {
        if ((int)_Var4 != 0) {
          pRVar6 = (RawUsageIndex *)(ulonglong)(uint)((int)local_1108 - (int)local_1110);
          wil_details_NtUpdateWnfStateData
                    (param_1,local_1110,(int)local_1108 - (int)local_1110,uVar7,puVar9,0,0);
        }
        goto LAB_140004b00;
      }
      uVar8 = uVar8 + 1;
      bVar3 = false;
    }
    pvVar2 = local_10f8;
    local_10f8 = (void *)0x0;
    if (pvVar2 != (void *)0x0) {
      details::FreeProcessHeap(pvVar2);
    }
    if (bVar3 != false) {
      return;
    }
    if (p_Var1 <= param_1) {
      return;
    }
    if (0x31 < uVar8) {
      return;
    }
  } while( true );
}



===== RetrieveUsageUnderLock @ 140004b78 =====

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



===== NtStatusToHr @ 140004be0 =====

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



===== SetBuffer @ 140004c3c =====

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



===== FindInsertionPointOrIncrement @ 140004d48 =====

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
    if (this[0x38] == (RawUsageIndex)0x0) goto LAB_140004e8e;
  }
  else {
    UsageIndexProperty::UpdateCount((UsageIndexProperty *)&local_48,local_44 + param_5);
  }
  RVar6 = (RawUsageIndex)0x1;
LAB_140004e8e:
  this[0x38] = RVar6;
  return (uchar *)0x0;
}



===== LowerBound @ 140004ec0 =====

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
  ushort local_30;
  undefined8 local_28;
  void *pvStack_20;
  
  local_38 = *(undefined2 *)(this + 6);
  local_36 = this[8];
  local_34 = 0;
  local_30 = 0;
  local_28 = 0;
  pvStack_20 = (void *)0x0;
  while (uVar1 = param_2, uVar1 != 0) {
    param_2 = uVar1 >> 1;
    local_res8 = param_1 + param_2 * *(longlong *)(this + 0x10);
    UsageIndexProperty::Read((UsageIndexProperty *)&local_38,&local_res8,*(uchar **)(this + 0x20));
    if (param_4 == local_30) {
      iVar2 = memcmp(param_3,pvStack_20,param_4);
    }
    else {
      iVar2 = (int)param_4 - (uint)local_30;
    }
    if (0 < iVar2) {
      param_1 = local_res8;
      param_2 = uVar1 + (-1 - param_2);
    }
  }
  return param_1;
}



===== operator() @ 140004fb0 =====

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



===== RecordUsage @ 140005018 =====

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



===== RecordUsageInternal @ 14000511c =====

/* private: bool __cdecl wil::details_abi::RawUsageIndex::RecordUsageInternal(void *
   __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::RawUsageIndex::RecordUsageInternal
          (RawUsageIndex *this,void *param_1,__uint64 param_2,void *param_3,__uint64 param_4,
          uint param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  __uint64 _Var7;
  ulonglong uVar8;
  uchar *puVar9;
  __uint64 _Var10;
  uchar *local_88;
  undefined2 local_80;
  RawUsageIndex local_7e;
  int local_7c;
  undefined2 local_78;
  undefined8 local_70;
  void *pvStack_68;
  ushort local_60;
  RawUsageIndex local_5e;
  uint local_5c;
  undefined2 local_58;
  __uint64 local_50;
  void *local_48;
  
  if (*(longlong *)(this + 0x18) != 0) {
    local_80 = *(undefined2 *)(this + 2);
    local_88 = (uchar *)(*(longlong *)(this + 0x18) + 10);
    local_7e = this[4];
    bVar4 = false;
    local_7c = 0;
    local_78 = 0;
    local_70 = 0;
    pvStack_68 = (void *)0x0;
    while( true ) {
      puVar9 = local_88;
      bVar5 = UsageIndexProperty::Read
                        ((UsageIndexProperty *)&local_80,&local_88,*(uchar **)(this + 0x20));
      if (!bVar5) break;
      iVar6 = UsageIndexProperty::Compare((UsageIndexProperty *)&local_80,param_1,param_2);
      if (iVar6 < 0) {
        local_88 = puVar9;
LAB_140005201:
        _Var7 = 0;
        if (!bVar4) goto LAB_140005217;
        puVar9 = local_88;
        _Var10 = _Var7;
        iVar6 = local_7c;
        goto LAB_14000523a;
      }
      if (iVar6 == 0) {
        local_88 = FindInsertionPointOrIncrement
                             (this,(UsageIndexProperty *)&local_80,local_88,param_3,param_4,param_5)
        ;
        if (local_88 == (uchar *)0x0) {
          return true;
        }
        bVar4 = true;
        goto LAB_140005201;
      }
      local_88 = SkipValues(this,(UsageIndexProperty *)&local_80,local_88);
    }
    *(uchar **)(this + 0x20) = local_88;
LAB_140005217:
    puVar9 = local_88;
    _Var10 = 0;
    iVar6 = 1;
    local_78 = (undefined2)param_2;
    local_7c = 1;
    local_70 = 0;
    pvStack_68 = param_1;
    _Var7 = UsageIndexProperty::GetSize((UsageIndexProperty *)&local_80);
LAB_14000523a:
    local_60 = *(ushort *)(this + 6);
    uVar8 = (ulonglong)local_60;
    local_5e = this[8];
    local_5c = param_5;
    local_58 = (undefined2)param_4;
    if (local_60 == 0) {
      uVar8 = (param_4 & 0xffff) + 2;
    }
    if (local_5e == (RawUsageIndex)0x1) {
      uVar8 = uVar8 + 2;
    }
    else if (local_5e == (RawUsageIndex)0x2) {
      uVar8 = uVar8 + 4;
    }
    uVar1 = *(ulonglong *)(this + 0x28);
    uVar8 = uVar8 + _Var7;
    uVar2 = *(ulonglong *)(this + 0x20);
    if (uVar8 <= (-(ulonglong)(uVar2 < uVar1) & uVar1 - uVar2)) {
      local_50 = _Var10;
      local_48 = param_3;
      memmove_s(puVar9 + uVar8,(uVar1 - uVar8) - (longlong)puVar9,puVar9,uVar2 - (longlong)puVar9);
      lVar3 = *(longlong *)(this + 0x20);
      *(uchar **)(this + 0x20) = (uchar *)(lVar3 + uVar8);
      if (bVar4) {
        if (local_7e != (RawUsageIndex)0x0) {
          UsageIndexProperty::UpdateCount((UsageIndexProperty *)&local_80,iVar6 + 1);
        }
      }
      else {
        UsageIndexProperty::Write
                  ((UsageIndexProperty *)&local_80,&local_88,(uchar *)(lVar3 + uVar8));
      }
      UsageIndexProperty::Write((UsageIndexProperty *)&local_60,&local_88,*(uchar **)(this + 0x20));
      this[0x38] = (RawUsageIndex)0x1;
      return true;
    }
  }
  return false;
}



===== Iterate @ 14000532c =====

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
LAB_14000543e:
      *(undefined8 *)(puVar6 + -8) = 0x140005446;
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
        goto LAB_14000543e;
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



===== Read @ 140005468 =====

/* public: bool __cdecl wil::details_abi::UsageIndexProperty::Read(unsigned char * __ptr64 &
   __ptr64,unsigned char * __ptr64) __ptr64 */

bool __thiscall
wil::details_abi::UsageIndexProperty::Read(UsageIndexProperty *this,uchar **param_1,uchar *param_2)

{
  UsageIndexProperty *_Dst;
  ushort uVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  ushort *_Src;
  
  _Src = (ushort *)*param_1;
  if (this[2] == (UsageIndexProperty)0x1) {
    puVar3 = _Src + 1;
    if (param_2 < puVar3) {
      return false;
    }
    *(ushort **)(this + 0x10) = _Src;
    if (_Src == (ushort *)0x0) {
      puVar2 = (undefined4 *)_o__errno();
      *puVar2 = 0x16;
      _o__invalid_parameter_noinfo();
      uVar1 = 0;
    }
    else {
      uVar1 = *_Src;
    }
    *(uint *)(this + 4) = (uint)uVar1;
  }
  else {
    if (this[2] != (UsageIndexProperty)0x2) goto LAB_1400054f1;
    puVar3 = _Src + 2;
    if (param_2 < puVar3) {
      return false;
    }
    *(ushort **)(this + 0x10) = _Src;
    memcpy_s(this + 4,4,_Src,4);
  }
  _Src = puVar3;
LAB_1400054f1:
  _Dst = this + 8;
  *(ushort *)_Dst = *(ushort *)this;
  puVar3 = _Src;
  if (*(ushort *)this == 0) {
    puVar3 = _Src + 1;
    if (param_2 < puVar3) {
      return false;
    }
    memcpy_s(_Dst,2,_Src,2);
  }
  if (param_2 < (uchar *)((ulonglong)*(ushort *)_Dst + (longlong)puVar3)) {
    return false;
  }
  *(ushort **)(this + 0x18) = puVar3;
  *param_1 = (uchar *)((ulonglong)*(ushort *)_Dst + (longlong)puVar3);
  return true;
}



===== GetSize @ 140005550 =====

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



===== Write @ 140005584 =====

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
    if (this[2] != (UsageIndexProperty)0x2) goto LAB_1400055f6;
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
LAB_1400055f6:
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



===== memmove_s @ 14000567c =====

errno_t __cdecl memmove_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t *peVar1;
  errno_t eVar2;
  
  if (_MaxCount == 0) {
LAB_1400056d3:
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
        goto LAB_1400056d3;
      }
      peVar1 = (errno_t *)_o__errno();
      eVar2 = 0x22;
    }
    *peVar1 = eVar2;
    _o__invalid_parameter_noinfo();
  }
  return eVar2;
}



===== ~function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)> @ 1400056e4 =====

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



===== Set @ 140005710 =====

/* public: long __cdecl Microsoft::WRL::Wrappers::HString::Set(unsigned short const *
   __ptr64,unsigned int) __ptr64 */

long __thiscall Microsoft::WRL::Wrappers::HString::Set(HString *this,ushort *param_1,uint param_2)

{
  long lVar1;
  
  WindowsDeleteString(*(undefined8 *)this);
  *(undefined8 *)this = 0;
                    /* WARNING: Could not recover jumptable at 0x000140005755. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = WindowsCreateString(param_1,param_2,this);
  return lVar1;
}



===== DoPerAppBrokerInstancingDefaultForActivationConfigurationCheck @ 140005770 =====

/* int __cdecl DoPerAppBrokerInstancingDefaultForActivationConfigurationCheck(union _RTL_RUN_ONCE *
   __ptr64,void * __ptr64,void * __ptr64 * __ptr64) */

int __cdecl
DoPerAppBrokerInstancingDefaultForActivationConfigurationCheck
          (_RTL_RUN_ONCE *param_1,void *param_2,void **param_3)

{
  bool bVar1;
  ReportingKind RVar2;
  LSTATUS LVar3;
  ulonglong uVar4;
  ReportingKind RVar5;
  bool bVar6;
  ReportingKind local_res20 [2];
  int local_18 [2];
  HKEY local_10;
  
  local_10 = (HKEY)0x0;
  local_res20[0] = 0;
  local_18[0] = 0;
  local_18[1] = 4;
  bVar6 = false;
  bVar1 = false;
  RVar2 = RegOpenKeyExW((HKEY)0xffffffff80000002,L"SOFTWARE\\Microsoft\\OLE\\Diagnosis",0,0x20019,
                        &local_10);
  if (RVar2 != 0) {
    if ((RVar2 != 2) &&
       ((DAT_140019080 != 0 ||
        ((gfEnableTracing != 0 && (uVar4 = IsWppLevelEnabled(0), (char)uVar4 != '\0')))))) {
      RVar5 = 0x40014bf8;
      ComTraceMessage(-1,"onecore\\com\\combase\\common\\core\\perappruntimebroker.cpp",
                      "CheckPerAppBrokerInstancingRegistryValue",0x3c,0,(ushort *)L"%!WINERROR!",
                      RVar2);
      RVar2 = RVar5;
    }
    goto LAB_1400057da;
  }
  LVar3 = RegQueryValueExW(local_10,L"EnablePerStoreApplicationBrokerInstance",(LPDWORD)0x0,
                           local_res20,(LPBYTE)local_18,(LPDWORD)(local_18 + 1));
  RVar2 = local_res20[0];
  if (LVar3 == 0) {
    if (local_res20[0] == 4) {
      bVar6 = local_18[0] != 0;
      bVar1 = true;
    }
    else {
LAB_140005872:
      if ((DAT_140019080 != 0) ||
         ((gfEnableTracing != 0 && (uVar4 = IsWppLevelEnabled(0), (char)uVar4 != '\0')))) {
        RVar5 = 0x40014bf8;
        ComTraceMessage(-1,"onecore\\com\\combase\\common\\core\\perappruntimebroker.cpp",
                        "CheckPerAppBrokerInstancingRegistryValue",0x36,0,
                        (ushort *)L"error %!WINERROR! type %d",LVar3,RVar2);
        RVar2 = RVar5;
      }
    }
  }
  else if (LVar3 != 2) goto LAB_140005872;
  RegCloseKey(local_10);
  if ((LVar3 == 0) && (bVar1)) {
    DAT_140019d18 = bVar6;
    return 1;
  }
LAB_1400057da:
  wil::details::FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker>::
  __private_IsEnabledPreCheck
            ((FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker> *)
             &`private:_static_class_wil::details::FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker>&___ptr64___cdecl_wil::Feature<__WilFeatureTraits_Feature_PerAppRuntimeBroker>::GetImpl(void)'
              ::__l2::impl,RVar2);
  DAT_140019d18 = 1;
  return 1;
}



===== __private_IsEnabledPreCheck @ 140005930 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: bool __cdecl wil::details::FeatureImpl<struct
   __WilFeatureTraits_Feature_PerAppRuntimeBroker>::__private_IsEnabledPreCheck(enum
   wil::ReportingKind) __ptr64 */

bool __thiscall
wil::details::FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker>::
__private_IsEnabledPreCheck
          (FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker> *this,ReportingKind param_1)

{
  wil_details_ServiceReportingKind wVar1;
  int iVar2;
  ulonglong *puVar3;
  uint uVar4;
  ulonglong uVar5;
  uchar uVar6;
  undefined4 local_res8;
  undefined2 local_resc;
  undefined4 local_res10 [2];
  ulonglong local_res18;
  uint in_stack_ffffffffffffffd0;
  undefined1 in_stack_ffffffffffffffd8;
  undefined7 in_stack_ffffffffffffffd9;
  
  local_res10[0] = CONCAT31(local_res10[0]._1_3_,(char)param_1);
  uVar5 = (ulonglong)*(uint *)this;
  if ((*(uint *)this & 4) == 0) {
    puVar3 = (ulonglong *)GetCachedFeatureEnabledState(this);
    local_res18 = *puVar3;
    uVar5 = local_res18 & 0xffffffff;
  }
  local_res8 = 0;
  uVar6 = '\x03';
  local_resc = 3;
  uVar4 = 1;
  local_res10[0] = 3;
  wVar1 = wil_details_MapReportingKind(3,1);
  iVar2 = ReportUsageToServiceDirect
                    ((wil_details_FeatureReportingCache *)(this + 8),uVar4,(uint)uVar5 >> 10 & 1,
                     (uint)(uVar5 >> 0xb) & 1,wVar1,in_stack_ffffffffffffffd0,
                     CONCAT71(in_stack_ffffffffffffffd9,in_stack_ffffffffffffffd8),uVar6);
  if ((iVar2 != 0) && (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)(0x816dc3,&local_res8,0,1,local_res10,0,0,1);
  }
  return true;
}



===== ReportUsageToServiceDirect @ 140005a04 =====

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
  int iVar9;
  undefined4 in_register_0000008c;
  int local_28;
  uint local_20 [6];
  
  pwVar7 = param_1;
  iVar9 = param_4;
  puVar5 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_20,(uint *)param_1,(ulonglong)param_5);
  wVar6 = (wil_details_ServiceReportingKind)pwVar7;
  iVar8 = 1;
  uVar2 = *puVar5;
  uVar3 = puVar5[1];
  uVar4 = puVar5[2];
  uVar1 = *(undefined8 *)(puVar5 + 4);
  if ((g_wil_details_RecordSRUMFeatureUsage != (code *)0x0) &&
     ((param_5 == 0 || (param_5 - 100 < 0x32)))) {
    wVar6 = param_5;
    (*g_wil_details_RecordSRUMFeatureUsage)(0x816dc3,param_5,1);
  }
  if (uVar2 != 0) {
    EnabledStateManager::QueueBackgroundUsageReporting
              ((EnabledStateManager *)&g_enabledStateManager,wVar6,param_1);
  }
  if (uVar3 != 0) {
    WilApi_RecordFeatureUsage(0x816dc3,uVar4,uVar3,(char *)CONCAT44(in_register_0000008c,iVar9));
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
    WilApi_RecordFeatureUsage(0x816dc3,wVar6,0,(char *)CONCAT44(in_register_0000008c,iVar9));
  }
  if (local_28 == 0) {
    if (g_wil_details_realtimeFeatureUsageHook != (code *)0x0) {
      (*g_wil_details_realtimeFeatureUsageHook)(0x816dc3,param_5,param_8);
    }
  }
  else {
    iVar8 = 0;
  }
  return iVar8;
}



===== WilApiImpl_GetFeatureEnabledState @ 140005b50 =====

/* enum FEATURE_ENABLED_STATE __cdecl wil::details::WilApiImpl_GetFeatureEnabledState(unsigned
   int,enum FEATURE_CHANGE_TIME,int * __ptr64) */

FEATURE_ENABLED_STATE __cdecl
wil::details::WilApiImpl_GetFeatureEnabledState
          (uint param_1,FEATURE_CHANGE_TIME param_2,int *param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  FEATURE_ENABLED_STATE FVar5;
  wil_details_FeatureStateCache *pwVar6;
  ulonglong uVar7;
  uint local_res10 [2];
  FEATURE_ENABLED_STATE local_38 [8];
  
  uVar7 = (ulonglong)(param_2 & 0x80);
  bVar2 = (param_2 & 0xffffff7f) - 2 < 2;
  pwVar6 = &`bool___cdecl_wil::details::IsFeatureConfigured(wil_FeatureState*___ptr64,unsigned_int,bool,wil_FeatureStore,int*___ptr64)'
            ::__l2::machineStoreProbe;
  local_38[4] = 0;
  local_38[5] = 0;
  if ((param_2 & 0x80) != 0) {
    pwVar6 = &`bool___cdecl_wil::details::IsFeatureConfigured(wil_FeatureState*___ptr64,unsigned_int,bool,wil_FeatureStore,int*___ptr64)'
              ::__l2::userStoreProbe;
  }
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  FVar5 = 0;
  if (((byte)*(uint *)pwVar6 & 3) != 2) {
    if ((*(uint *)pwVar6 & 2) == 0) {
      local_res10[0] = 1;
      uVar4 = EnsureSubscribedToFeatureConfigurationChanges();
      iVar3 = wil_QueryFeatureState(local_38,param_1,(uint)bVar2,uVar7,local_res10,param_3);
      LOCK();
      uVar1 = *(uint *)pwVar6;
      *(uint *)pwVar6 = (local_res10[0] != 0) + 6;
      UNLOCK();
      if ((local_res10[0] == 0) && ((uVar1 & 4) == 0)) {
        EnabledStateManager::SubscribeFeatureStateCacheToConfigurationChanges
                  ((EnabledStateManager *)&g_enabledStateManager,pwVar6,0,uVar4);
      }
    }
    else {
      iVar3 = wil_QueryFeatureState(local_38,param_1,(uint)bVar2,uVar7,(uint *)0x0,param_3);
    }
    if (iVar3 != 0) {
      FVar5 = local_38[0];
    }
  }
  if (local_38[4] != 0) {
    FVar5 = FVar5 | 0x80;
  }
  if (local_38[5] != 0) {
    FVar5 = FVar5 | 0x40;
  }
  return FVar5;
}



===== GetCachedFeatureEnabledState @ 140005c8c =====

/* WARNING: Removing unreachable block (ram,0x000140005d15) */
/* WARNING: Removing unreachable block (ram,0x000140005d1b) */
/* private: union wil_details_FeatureStateCache __cdecl wil::details::FeatureImpl<struct
   __WilFeatureTraits_Feature_PerAppRuntimeBroker>::GetCachedFeatureEnabledState(void) __ptr64 */

void __thiscall
wil::details::FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker>::
GetCachedFeatureEnabledState(FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker> *this)

{
  uint uVar1;
  uint uVar2;
  FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker> *this_00;
  uint uVar3;
  uint *in_RDX;
  uint uVar4;
  uint local_res10 [2];
  
  in_RDX[0] = 0;
  in_RDX[1] = 0;
  uVar4 = *(uint *)this;
  *in_RDX = uVar4;
  if (((byte)uVar4 & 6) != 6) {
    this_00 = this;
    uVar2 = EnsureSubscribedToFeatureConfigurationChanges();
    GetCurrentFeatureEnabledState(this_00,(int *)local_res10);
    uVar4 = *in_RDX;
    while( true ) {
      *in_RDX = uVar4;
      uVar3 = uVar4;
      if ((uVar4 & 4) == 0) {
        uVar3 = uVar4 & 0xfffffbff | local_res10[0] & 0x400 | 4;
        *in_RDX = uVar3;
      }
      LOCK();
      uVar1 = *(uint *)this;
      if (uVar4 == uVar1) {
        *(uint *)this = uVar3;
        uVar3 = uVar4;
      }
      else {
        uVar3 = uVar1;
      }
      UNLOCK();
      if (uVar4 == uVar1) break;
      uVar4 = uVar3;
    }
    if ((uVar4 & 4) == 0) {
      EnabledStateManager::SubscribeFeatureStateCacheToConfigurationChanges
                ((EnabledStateManager *)&g_enabledStateManager,(wil_details_FeatureStateCache *)this
                 ,3,uVar2);
    }
    if ((*in_RDX & 2) == 0) {
      *in_RDX = *in_RDX & 0xfffff63e | local_res10[0] & 0x9c1;
    }
  }
  return;
}



===== EnsureSubscribedToFeatureConfigurationChanges @ 140005d7c =====

/* unsigned int __cdecl wil::details::EnsureSubscribedToFeatureConfigurationChanges(void) */

uint __cdecl wil::details::EnsureSubscribedToFeatureConfigurationChanges(void)

{
  uint uVar1;
  
  uVar1 = DAT_1400192f4;
  if (DAT_1400192f4 == 0) {
    uVar1 = EnabledStateManager::EnsureSubscribedToFeatureConfigurationChangesImpl
                      ((EnabledStateManager *)&g_enabledStateManager);
  }
  return uVar1;
}



===== GetCurrentFeatureEnabledState @ 140005da4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: union wil_details_FeatureStateCache __cdecl wil::details::FeatureImpl<struct
   __WilFeatureTraits_Feature_PerAppRuntimeBroker>::GetCurrentFeatureEnabledState(int * __ptr64)
   __ptr64 */

int * __thiscall
wil::details::FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker>::
GetCurrentFeatureEnabledState
          (FeatureImpl<__WilFeatureTraits_Feature_PerAppRuntimeBroker> *this,int *param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  
  pcVar2 = g_wil_details_internalGetFeatureEnabledState;
  if ((g_wil_details_internalGetFeatureEnabledState == (code *)0x0) &&
     (pcVar2 = g_wil_details_apiGetFeatureEnabledState,
     g_wil_details_apiGetFeatureEnabledState == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*pcVar2)(0x816dc3,3);
  }
  param_1[0] = 0;
  param_1[1] = 0;
  uVar4 = 0x40;
  uVar3 = (((uVar1 & 3) << 2 | uVar1 & 0x40) << 2 | uVar1 & 0x80) << 3;
  *param_1 = uVar3;
  if (((uVar1 & 0xffffff3f) != 0) && (uVar4 = 0, (uVar1 & 0xffffff3f) == 2)) {
    uVar4 = 0x40;
  }
  *param_1 = uVar3 | uVar4 | 1;
  return param_1;
}



===== EnsureSubscribedToFeatureConfigurationChangesImpl @ 140005e40 =====

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
  uint uVar2;
  code *pcVar3;
  
  if (*this != (EnabledStateManager)0x0) {
    SRWLock = this + 8;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    pEVar1 = this + 0x20;
    if (*(longlong *)pEVar1 != 0) {
      uVar2 = *(uint *)(this + 0x1c);
      if (SRWLock != (EnabledStateManager *)0x0) {
        ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
      }
      return uVar2;
    }
    *(longlong *)pEVar1 = 0;
    pcVar3 = g_wil_details_internalSubscribeFeatureStateChangeNotification;
    if ((g_wil_details_internalSubscribeFeatureStateChangeNotification != (code *)0x0) ||
       (pcVar3 = g_wil_details_apiSubscribeFeatureStateChangeNotification,
       g_wil_details_apiSubscribeFeatureStateChangeNotification != (code *)0x0)) {
      (*pcVar3)(pEVar1,<lambda_fee8cea507d2413a58be13acfb66740a>::<lambda_invoker_cdecl>,this);
    }
    if (*(longlong *)pEVar1 != 0) {
      *(undefined4 *)(this + 0x1c) = 1;
      if (SRWLock != (EnabledStateManager *)0x0) {
        ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
      }
      return 1;
    }
    if (SRWLock != (EnabledStateManager *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
  }
  return 0;
}



===== SubscribeFeatureStateCacheToConfigurationChanges @ 140005f1c =====

/* public: void __cdecl
   wil::details::EnabledStateManager::SubscribeFeatureStateCacheToConfigurationChanges(union
   wil_details_FeatureStateCache * __ptr64,enum wil_FeatureChangeTime,unsigned int) __ptr64 */

void __thiscall
wil::details::EnabledStateManager::SubscribeFeatureStateCacheToConfigurationChanges
          (EnabledStateManager *this,wil_details_FeatureStateCache *param_1,
          wil_FeatureChangeTime param_2,uint param_3)

{
  EnabledStateManager *SRWLock;
  ulonglong *_Dst;
  bool bVar1;
  undefined4 *puVar2;
  ulonglong _Size;
  
  if (*this == (EnabledStateManager)0x0) {
    return;
  }
  SRWLock = this + 8;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  if (((param_3 == 0) || (param_3 != *(uint *)(this + 0x1c))) ||
     (bVar1 = details_abi::heap_buffer::ensure((heap_buffer *)(this + 0x50),0x10), !bVar1)) {
    LOCK();
    *(uint *)param_1 = *(uint *)param_1 & (-(uint)(param_2 != 0) & 0x83a) - 0x83f;
    UNLOCK();
    goto LAB_140006007;
  }
  _Dst = *(ulonglong **)(this + 0x58);
  _Size = -(ulonglong)(_Dst < *(ulonglong **)(this + 0x60)) &
          *(longlong *)(this + 0x60) - (longlong)_Dst;
  if (_Dst == (ulonglong *)0x0) {
    puVar2 = (undefined4 *)_o__errno();
    *puVar2 = 0x16;
LAB_140005fea:
    _o__invalid_parameter_noinfo();
  }
  else {
    if (_Size < 0x10) {
      memset(_Dst,0,_Size);
      puVar2 = (undefined4 *)_o__errno();
      *puVar2 = 0x22;
      goto LAB_140005fea;
    }
    *_Dst = (ulonglong)param_2;
    _Dst[1] = (ulonglong)param_1;
  }
  *(longlong *)(this + 0x58) = *(longlong *)(this + 0x58) + 0x10;
LAB_140006007:
  if (SRWLock != (EnabledStateManager *)0x0) {
    ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
  }
  return;
}



===== ensure @ 140006040 =====

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



===== GetSelfSid @ 140006070 =====

/* public: static void * __ptr64 __cdecl CRuntimeBroker::GetSelfSid(void) */

void * __cdecl CRuntimeBroker::GetSelfSid(void)

{
  BOOL BVar1;
  uchar **ppuVar2;
  
  BVar1 = InitOnceExecuteOnce(&`public:_static_void*___ptr64___cdecl_CRuntimeBroker::GetSelfSid(void)'
                               ::__l2::rtbSelfSidInitOnce,QueryProcessTokenSid,(PVOID)0x0,
                              (LPVOID *)0x0);
  ppuVar2 = (uchar **)0x0;
  if (BVar1 != 0) {
    ppuVar2 = &s_rtbSelfSid;
  }
  return ppuVar2;
}



===== Release @ 1400060c0 =====

/* public: virtual unsigned long __cdecl CRuntimeBroker::Release(void) __ptr64 */

ulong __thiscall CRuntimeBroker::Release(CRuntimeBroker *this)

{
  CRuntimeBroker *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 8;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if ((iVar2 - 1U == 0) && (this != (CRuntimeBroker *)0x0)) {
    *(undefined ***)this = &_vftable_;
    CoReleaseServerProcess();
    operator_delete(this,0x10);
  }
  return iVar2 - 1U;
}



===== OnUsageFlushed @ 140006120 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details::FeatureStateManager::OnUsageFlushed(void) __ptr64 */

void __thiscall wil::details::FeatureStateManager::OnUsageFlushed(FeatureStateManager *this)

{
  FeatureStateManager *SRWLock;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  code *pcVar6;
  undefined8 uVar7;
  
  if (*this != (FeatureStateManager)0x0) {
    SRWLock = this + 0x20;
    lpCriticalSection = (LPCRITICAL_SECTION)(this + 0x98);
    AcquireSRWLockShared((PSRWLOCK)SRWLock);
    uVar3 = (ulonglong)(*(longlong *)(this + 200) - *(longlong *)(this + 0xc0)) >> 4;
    if (SRWLock != (FeatureStateManager *)0x0) {
      ReleaseSRWLockShared((PSRWLOCK)SRWLock);
    }
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        pcVar6 = (code *)0x0;
        uVar7 = 0;
        EnterCriticalSection(lpCriticalSection);
        AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
        lVar2 = uVar4 << 4;
        uVar5 = uVar4;
        while (uVar4 = uVar5, uVar5 < uVar3) {
          uVar4 = uVar5 + 1;
          if (*(longlong *)(lVar2 + *(longlong *)(this + 0xc0)) != 0) {
            puVar1 = (undefined8 *)(*(longlong *)(this + 0xc0) + uVar5 * 0x10);
            pcVar6 = (code *)*puVar1;
            uVar7 = puVar1[1];
            break;
          }
          lVar2 = lVar2 + 0x10;
          uVar5 = uVar4;
        }
        if (SRWLock != (FeatureStateManager *)0x0) {
          ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
        }
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)(uVar7);
        }
        if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
          LeaveCriticalSection(lpCriticalSection);
        }
      } while (uVar4 < uVar3);
    }
  }
  return;
}



===== ClearIndirectCallTarget @ 140006270 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl ClearIndirectCallTarget(struct IIndirectCallTarget * __ptr64) */

void __cdecl ClearIndirectCallTarget(IIndirectCallTarget *param_1)

{
  int iVar1;
  void *unaff_retaddr;
  
  if (param_1 == (IIndirectCallTarget *)0x0) {
    return;
  }
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x28))();
  if (iVar1 < 0) {
    wil::details::in1diag3::_Log_Hr
              (unaff_retaddr,10,"onecore\\com\\combase\\inc\\IndirectCallTarget.hpp",iVar1);
  }
  (**(code **)(*(longlong *)param_1 + 0x10))(param_1);
  return;
}



===== StringCchCopyW @ 1400062d0 =====

/* long __cdecl StringCchCopyW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64) */

long __cdecl StringCchCopyW(ushort *param_1,__uint64 param_2,ushort *param_3)

{
  ushort uVar1;
  long lVar2;
  ushort *puVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar4 = 0x104;
  lVar5 = (longlong)param_3 - (longlong)param_1;
  do {
    if ((lVar4 == -0x7ffffefa) || (uVar1 = *(ushort *)(lVar5 + (longlong)param_1), uVar1 == 0))
    break;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  puVar3 = param_1 + -1;
  if (lVar4 != 0) {
    puVar3 = param_1;
  }
  *puVar3 = 0;
  lVar2 = -0x7ff8ff86;
  if (lVar4 != 0) {
    lVar2 = 0;
  }
  return lVar2;
}



===== wWinMain @ 140006328 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __stdcall wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd)

{
  REGHANDLE RegHandle;
  ulong uExitCode;
  HANDLE hProcess;
  bool *pbVar1;
  undefined *pSecDesc;
  bool *local_18;
  undefined8 local_10;
  
  EnableProcessMitigations();
  SetErrorMode(0x8001);
  SetProcessShutdownParameters(2,0);
  TraceLoggingRegisterEx_EventRegister_EventSetInformation();
  uExitCode = CoInitializeEx((LPVOID)0x0,0);
  if (-1 < (int)uExitCode) {
    uExitCode = SubscribeForLowPowerEpochNotifications();
    if (0 < (int)uExitCode) {
      uExitCode = uExitCode & 0xffff | 0x80070000;
    }
    if (-1 < (int)uExitCode) {
      local_10 = 0;
      uExitCode = CoIncrementMTAUsage(&local_10);
      if (-1 < (int)uExitCode) {
        local_18 = (bool *)0x0;
        uExitCode = CoCreateInstance((IID *)&CLSID_GlobalOptions,(LPUNKNOWN)0x0,1,
                                     (IID *)&_GUID_0000015b_0000_0000_c000_000000000046,&local_18);
        if (-1 < (int)uExitCode) {
          (**(code **)(*(longlong *)local_18 + 0x18))(local_18,1,2);
          (**(code **)(*(longlong *)local_18 + 0x18))(local_18,4,0x338);
          (**(code **)(*(longlong *)local_18 + 0x18))(local_18,5,1);
          pbVar1 = local_18;
          (**(code **)(*(longlong *)local_18 + 0x10))();
          local_18 = (bool *)0x0;
          Ordinal_99();
          uExitCode = IsPerAppRuntimeBroker(pbVar1);
          if (-1 < (int)uExitCode) {
            pSecDesc = &APPID_PerAppRuntimeBroker;
            if (DAT_140019bc0 == '\0') {
              pSecDesc = &APPID_RuntimeBroker;
            }
            uExitCode = CoInitializeSecurity
                                  (pSecDesc,-1,(SOLE_AUTHENTICATION_SERVICE *)0x0,(void *)0x0,6,2,
                                   (void *)0x0,0x48,(void *)0x0);
            if (-1 < (int)uExitCode) {
              uExitCode = CRuntimeBroker::Run();
            }
          }
        }
        if (g_lifetimeExtensionFactory != (CRuntimeBrokerLifetimeExtensionFactory *)0x0) {
          CRuntimeBrokerLifetimeExtensionFactory::Release(g_lifetimeExtensionFactory);
        }
        CoDecrementMTAUsage(local_10);
      }
    }
  }
  RegHandle = DAT_140019028;
  DAT_140019028 = 0;
  DAT_140019008 = 0;
  EventUnregister(RegHandle);
  if (g_hPowerEpochStateNotification != (void *)0x0) {
    PowerSettingUnregisterNotification();
    g_hPowerEpochStateNotification = (void *)0x0;
  }
  if (g_hLowPowerEpoch != (void *)0x0) {
    CloseHandle(g_hLowPowerEpoch);
    g_hLowPowerEpoch = (void *)0x0;
  }
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return uExitCode;
}



===== EnableProcessMitigations @ 140006578 =====

/* void __cdecl EnableProcessMitigations(void) */

void __cdecl EnableProcessMitigations(void)

{
  int iVar1;
  HANDLE pvVar2;
  uint local_res8 [2];
  undefined4 local_res10 [6];
  
  local_res8[0] = 0;
  HeapSetInformation(g_hHeap,HeapEnableTerminationOnCorruption,(PVOID)0x0,0);
  pvVar2 = GetCurrentProcess();
  iVar1 = GetProcessMitigationPolicy(pvVar2,1,local_res8,4);
  if (iVar1 != 0) {
    local_res8[0] = local_res8[0] | 2;
    SetProcessMitigationPolicy(1,local_res8,4);
  }
  local_res10[0] = 3;
  SetProcessMitigationPolicy(3,local_res10,4);
  return;
}



===== TraceLoggingRegisterEx_EventRegister_EventSetInformation @ 140006620 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ULONG TraceLoggingRegisterEx_EventRegister_EventSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  ULONG UVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_140019010 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_140019010 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_140019010 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_140019010 + -4);
  if (DAT_140019028 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_140019030 = 0;
  uRam0000000140019038 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14000667b;
  UVar3 = EventRegister((LPCGUID)(puVar4 + 0x20),_tlgEnableCallback,&DAT_140019008,
                        (PREGHANDLE)&DAT_140019028);
  if (UVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140019010;
    *(undefined8 *)(puVar4 + -8) = 0x1400066a2;
    EventSetInformation(DAT_140019028,2,PTR_DAT_140019010,uVar1);
  }
  else if (0 < (int)UVar3) {
    UVar3 = UVar3 & 0xffff | 0x80070000;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1400066b6;
  return UVar3;
}



===== SubscribeForLowPowerEpochNotifications @ 1400066dc =====

/* unsigned long __cdecl SubscribeForLowPowerEpochNotifications(void) */

ulong __cdecl SubscribeForLowPowerEpochNotifications(void)

{
  ulong uVar1;
  code *local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_18 = RtbPowerEpochChangedCallback;
  g_hLowPowerEpoch = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,1,(LPCWSTR)0x0);
  if (g_hLowPowerEpoch == (HANDLE)0x0) {
    uVar1 = GetLastError();
  }
  else {
    uVar1 = PowerSettingRegisterNotification
                      (&GUID_LOW_POWER_EPOCH,2,&local_18,&g_hPowerEpochStateNotification);
  }
  return uVar1;
}



===== IsPerAppRuntimeBroker @ 140006754 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl IsPerAppRuntimeBroker(bool * __ptr64) */

long __cdecl IsPerAppRuntimeBroker(bool *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_158 [32];
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128 [2];
  undefined1 local_118 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  local_130 = 0;
  local_138 = 0;
  DAT_140019bc0 = 0;
  local_128[0] = 0x100;
  iVar1 = RtlQueryPackageIdentity(0xfffffffffffffffc,local_118,local_128);
  if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3ffffddb)) {
    uVar2 = RtlNtStatusToDosError();
    if (0 < (int)uVar2) {
      uVar2 = uVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    DAT_140019bc0 = (byte)((uint)iVar1 >> 0x1f) ^ 1;
    uVar2 = 0;
  }
  return uVar2;
}



===== OnTimer @ 140006804 =====

/* public: void __cdecl wil::details::EnabledStateManager::OnTimer(void) __ptr64 */

void __thiscall wil::details::EnabledStateManager::OnTimer(EnabledStateManager *this)

{
  EnabledStateManager *SRWLock;
  
  if (*this != (EnabledStateManager)0x0) {
    SRWLock = this + 8;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    RecordCachedUsageUnderLock(this);
    this[0x18] = (EnabledStateManager)0x0;
    if (SRWLock != (EnabledStateManager *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
  }
  return;
}



===== <lambda_invoker_cdecl> @ 140006860 =====

/* private: static __cdecl <lambda_aa194dc0bf891154933407eb98fb868a>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_aa194dc0bf891154933407eb98fb868a>::<lambda_invoker_cdecl>(void *param_1)

{
  if (wil::details::g_enabledStateManager !=
      (shutdown_aware_object<wil::details::EnabledStateManager>)0x0) {
    AcquireSRWLockExclusive((PSRWLOCK)&DAT_1400192e0);
    wil::details::EnabledStateManager::RecordCachedUsageUnderLock
              ((EnabledStateManager *)&wil::details::g_enabledStateManager);
    DAT_1400192f0 = 0;
    ReleaseSRWLockExclusive((PSRWLOCK)&DAT_1400192e0);
  }
  return;
}



===== RecordCachedUsageUnderLock @ 1400068c0 =====

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



===== WilApi_RecordFeatureUsage @ 14000692c =====

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



===== StringCchCatW @ 140006960 =====

/* long __cdecl StringCchCatW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64) */

long __cdecl StringCchCatW(ushort *param_1,__uint64 param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  longlong lVar4;
  ushort *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  lVar7 = 0x104;
  puVar3 = param_1;
  do {
    if (*puVar3 == 0) break;
    puVar3 = puVar3 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar6 = -(ulonglong)(lVar7 != 0) & 0x104U - lVar7;
  uVar2 = ~-(uint)(lVar7 != 0) & 0x80070057;
  if (lVar7 != 0) {
    puVar3 = param_1 + uVar6;
    lVar7 = 0x104 - uVar6;
    if (lVar7 != 0) {
      lVar4 = 0x7ffffffe;
      lVar8 = (longlong)param_3 - (longlong)puVar3;
      do {
        if ((lVar4 == 0) || (uVar1 = *(ushort *)(lVar8 + (longlong)puVar3), uVar1 == 0)) break;
        *puVar3 = uVar1;
        lVar4 = lVar4 + -1;
        puVar3 = puVar3 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    puVar5 = puVar3 + -1;
    if (lVar7 != 0) {
      puVar5 = puVar3;
    }
    *puVar5 = 0;
    uVar2 = ~-(uint)(lVar7 != 0) & 0x8007007a;
  }
  return uVar2;
}



===== QueryInterface @ 140006a10 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBroker::CFactory::QueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBroker::CFactory::QueryInterface(CFactory *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  *param_2 = (void *)0x0;
  lVar1._0_4_ = param_1->Data1;
  lVar1._4_2_ = param_1->Data2;
  lVar1._6_2_ = param_1->Data3;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)param_1->Data4 + -0x46000000000000c0;
  }
  if (lVar1 != 0) {
    lVar1 = *(longlong *)param_1 + -1;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)param_1->Data4 + -0x46000000000000c0;
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== memcpy_s @ 140006a80 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  undefined4 *puVar2;
  
  if (_MaxCount == 0) {
LAB_140006ab7:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_140006aca:
      puVar2 = (undefined4 *)_o__errno();
      *puVar2 = 0x16;
      _o__invalid_parameter_noinfo();
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_140006ab7;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_140006aca;
      if (_DstSize < _MaxCount) {
        puVar2 = (undefined4 *)_o__errno();
        *puVar2 = 0x22;
        _o__invalid_parameter_noinfo();
        return 0x22;
      }
    }
    eVar1 = 0x16;
  }
  return eVar1;
}



===== Run @ 140006b20 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: static long __cdecl CRuntimeBroker::Run(void) */

long __cdecl CRuntimeBroker::Run(void)

{
  IUserWatcher *pIVar1;
  char cVar2;
  DWORD DVar3;
  LSTATUS LVar4;
  int iVar5;
  CRuntimeBrokerLifetimeExtensionFactory *this;
  CRuntimeBrokerLifetimeExtensionFactory *pUnk;
  IUserWatcher *local_res8;
  longlong local_res10;
  DWORD local_res18 [2];
  HKEY local_res20;
  void *local_28;
  void *local_20;
  
  s_hEventShutdown = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  if (s_hEventShutdown == (HANDLE)0x0) {
    DVar3 = GetLastError();
    if ((int)DVar3 < 1) {
      return DVar3;
    }
    return DVar3 & 0xffff | 0x80070000;
  }
  cVar2 = IsRemoteWinRTActivationPresent();
  if (cVar2 != '\0') {
    `public:_static_long___cdecl_CRuntimeBroker::Run(void)'::__l7::dwIdleShutdownTimeout = 5000;
  }
  local_res20 = (HKEY)0x0;
  LVar4 = RegOpenKeyExW((HKEY)0xffffffff80000002,L"SOFTWARE\\Microsoft\\Ole\\Extensions\\AppCompat",
                        0,1,&local_res20);
  if (LVar4 == 0) {
    local_res18[0] = 0;
    local_res8 = (IUserWatcher *)((ulonglong)local_res8 & 0xffffffff00000000);
    local_res10 = CONCAT44(local_res10._4_4_,4);
    LVar4 = RegQueryValueExW(local_res20,L"RuntimeBrokerIdleExitTimeout",(LPDWORD)0x0,local_res18,
                             (LPBYTE)&local_res8,(LPDWORD)&local_res10);
    if (LVar4 == 0) {
      `public:_static_long___cdecl_CRuntimeBroker::Run(void)'::__l7::dwIdleShutdownTimeout =
           (int)local_res8 * 1000;
    }
    RegCloseKey(local_res20);
  }
  iVar5 = Ordinal_69(s_hEventShutdown,
                     `public:_static_long___cdecl_CRuntimeBroker::Run(void)'::__l7::
                     dwIdleShutdownTimeout);
  if (iVar5 < 0) goto LAB_140006e54;
  local_res8 = (IUserWatcher *)0x0;
  local_res10 = 0;
  iVar5 = CreateLogoffWatcher(&local_res8,(EventRegistrationToken *)&local_res10);
  if (-1 < iVar5) {
    InitOnceExecuteOnce((PINIT_ONCE)&DAT_140019d20,
                        DoPerAppBrokerInstancingDefaultForActivationConfigurationCheck,(PVOID)0x0,
                        (LPVOID *)0x0);
    if (DAT_140019d18 == '\0') {
LAB_140006d1f:
      if (((DAT_140019bc0 != '\0') ||
          (iVar5 = CoRegisterClassObject
                             ((IID *)&CLSID_RuntimeBroker,(LPUNKNOWN)&s_factory,4,5,
                              &s_registrationCookieSharedRtb), -1 < iVar5)) &&
         (iVar5 = CoResumeClassObjects(), -1 < iVar5)) {
        local_28 = s_hEventShutdown;
        local_20 = g_hLowPowerEpoch;
        do {
          do {
            DVar3 = WaitForMultipleObjects(2,&local_28,0,DAT_14001926c);
            CoFreeUnusedLibrariesEx(60000,0);
          } while (DVar3 == 0x102);
        } while (DVar3 == 1);
        if (s_registrationCookieSharedRtb != 0) {
          CoRevokeClassObject(s_registrationCookieSharedRtb);
        }
        if (s_registrationCookiePerAppRtb != 0) {
          CoRevokeClassObject(s_registrationCookiePerAppRtb);
        }
        if (s_registrationCookieLifetimeExtension != 0) {
          CoRevokeClassObject(s_registrationCookieLifetimeExtension);
        }
      }
    }
    else {
      iVar5 = CoRegisterClassObject
                        ((IID *)&CLSID_PerAppRuntimeBroker,(LPUNKNOWN)&s_factory,4,5,
                         &s_registrationCookiePerAppRtb);
      if (-1 < iVar5) {
        this = operator_new(0x20,&std::nothrow);
        pUnk = (CRuntimeBrokerLifetimeExtensionFactory *)0x0;
        if (this != (CRuntimeBrokerLifetimeExtensionFactory *)0x0) {
          pUnk = (CRuntimeBrokerLifetimeExtensionFactory *)
                 CRuntimeBrokerLifetimeExtensionFactory::CRuntimeBrokerLifetimeExtensionFactory
                           (this);
        }
        g_lifetimeExtensionFactory = pUnk;
        iVar5 = CoRegisterClassObject
                          (&CLSID_RuntimeBrokerLifetimeExtension,(LPUNKNOWN)pUnk,1,0x11,
                           &s_registrationCookieLifetimeExtension);
        if (-1 < iVar5) goto LAB_140006d1f;
      }
    }
  }
  pIVar1 = local_res8;
  if ((local_res8 != (IUserWatcher *)0x0) && (local_res10 != 0)) {
    (**(code **)(*(longlong *)local_res8 + 0x60))(local_res8);
  }
  Ordinal_69(0,0);
  if (pIVar1 != (IUserWatcher *)0x0) {
    (**(code **)(*(longlong *)pIVar1 + 0x10))(pIVar1);
  }
LAB_140006e54:
  AcquireSRWLockExclusive((PSRWLOCK)&s_ShutdownEventLock);
  CloseHandle(s_hEventShutdown);
  s_hEventShutdown = (void *)0x0;
  ReleaseSRWLockExclusive((PSRWLOCK)&s_ShutdownEventLock);
  return iVar5;
}



===== CreateLogoffWatcher @ 140006eb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: static long __cdecl CRuntimeBroker::CreateLogoffWatcher(struct
   Windows::System::IUserWatcher * __ptr64 * __ptr64,struct EventRegistrationToken * __ptr64) */

long __cdecl
CRuntimeBroker::CreateLogoffWatcher(IUserWatcher **param_1,EventRegistrationToken *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
  *this;
  char cVar3;
  long lVar4;
  DWORD dwExceptionCode;
  longlong *plVar5;
  void *unaff_retaddr;
  undefined1 auStack_98 [32];
  bool local_78 [8];
  longlong *local_70;
  IUserWatcher *local_68;
  RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
  *local_60;
  undefined8 local_58;
  undefined1 local_50 [24];
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  *param_1 = (IUserWatcher *)0x0;
  *(undefined8 *)param_2 = 0;
  cVar3 = RtlIsMultiSessionSku();
  if (cVar3 == '\0') {
    local_78[0] = false;
    lVar4 = IsDefaultUserProcess(local_78);
    if (lVar4 < 0) {
      wil::details::in1diag3::Return_Hr
                (unaff_retaddr,0x428,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",
                 lVar4);
      return lVar4;
    }
    if (local_78[0] == false) {
      local_68 = (IUserWatcher *)0x0;
      local_58 = 0;
      local_70 = (longlong *)0x0;
      local_38 = 0;
      dwExceptionCode = WindowsCreateStringReference(L"Windows.System.User",0x13,local_50,&local_38)
      ;
      if ((int)dwExceptionCode < 0) {
        RaiseException(dwExceptionCode,1,0,(ULONG_PTR *)0x0);
        pcVar2 = (code *)swi(3);
        lVar4 = (*pcVar2)();
        return lVar4;
      }
      lVar4 = RoGetActivationFactory(local_38,&_GUID_155eb23b_242a_45e0_a2e9_3171fc6a7fdd,&local_70)
      ;
      plVar1 = local_70;
      if (lVar4 < 0) {
        wil::details::in1diag3::Return_Hr
                  (unaff_retaddr,0x42f,
                   "onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",lVar4);
        plVar1 = local_70;
        if (local_70 != (longlong *)0x0) {
          local_70 = (longlong *)0x0;
          (**(code **)(*plVar1 + 0x10))();
        }
        Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease
                  ((ComPtr<Windows::System::IUserWatcher> *)&local_68);
        return lVar4;
      }
      pcVar2 = *(code **)(*local_70 + 0x30);
      Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease
                ((ComPtr<Windows::System::IUserWatcher> *)&local_68);
      lVar4 = (*pcVar2)(plVar1,&local_68);
      if (lVar4 < 0) {
        wil::details::in1diag3::Return_Hr
                  (unaff_retaddr,0x430,
                   "onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",lVar4);
        plVar1 = local_70;
        if (local_70 != (longlong *)0x0) {
          local_70 = (longlong *)0x0;
          (**(code **)(*plVar1 + 0x10))();
        }
        Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease
                  ((ComPtr<Windows::System::IUserWatcher> *)&local_68);
        return lVar4;
      }
      plVar5 = (longlong *)
               Microsoft::WRL::Details::
               Make<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,_1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>_>
                         ((<lambda_ff67e1dbbd64ec80e0b69245dd48b71a> *)&local_60);
      this = local_60;
      plVar1 = (longlong *)*plVar5;
      *plVar5 = 0;
      if (local_60 !=
          (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
           *)0x0) {
        local_60 = (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
                    *)0x0;
        Microsoft::WRL::Details::
        RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
        ::Release(this);
      }
      if (plVar1 == (longlong *)0x0) {
        wil::details::in1diag3::Return_Hr
                  (unaff_retaddr,0x446,
                   "onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",-0x7ff8fff2);
        plVar1 = local_70;
        if (local_70 != (longlong *)0x0) {
          local_70 = (longlong *)0x0;
          (**(code **)(*plVar1 + 0x10))();
        }
        Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease
                  ((ComPtr<Windows::System::IUserWatcher> *)&local_68);
        return -0x7ff8fff2;
      }
      lVar4 = (**(code **)(*(longlong *)local_68 + 0x58))(local_68,plVar1,&local_58);
      if (lVar4 < 0) {
        wil::details::in1diag3::Return_Hr
                  (unaff_retaddr,0x44a,
                   "onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",lVar4);
        (**(code **)(*plVar1 + 0x10))(plVar1);
        plVar1 = local_70;
        if (local_70 != (longlong *)0x0) {
          local_70 = (longlong *)0x0;
          (**(code **)(*plVar1 + 0x10))();
        }
        Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease
                  ((ComPtr<Windows::System::IUserWatcher> *)&local_68);
        return lVar4;
      }
      *param_1 = local_68;
      *(undefined8 *)param_2 = local_58;
      local_68 = (IUserWatcher *)0x0;
      (**(code **)(*plVar1 + 0x10))(plVar1);
      plVar1 = local_70;
      if (local_70 != (longlong *)0x0) {
        local_70 = (longlong *)0x0;
        (**(code **)(*plVar1 + 0x10))();
      }
      Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease
                ((ComPtr<Windows::System::IUserWatcher> *)&local_68);
    }
  }
  return 0;
}



===== CRuntimeBrokerLifetimeExtensionFactory @ 14000718c =====

/* public: __cdecl
   CRuntimeBrokerLifetimeExtensionFactory::CRuntimeBrokerLifetimeExtensionFactory(void) __ptr64 */

CRuntimeBrokerLifetimeExtensionFactory * __thiscall
CRuntimeBrokerLifetimeExtensionFactory::CRuntimeBrokerLifetimeExtensionFactory
          (CRuntimeBrokerLifetimeExtensionFactory *this)

{
  ComPtr<Windows::System::IUserWatcher> *this_00;
  
  this_00 = (ComPtr<Windows::System::IUserWatcher> *)(this + 0x18);
  *(undefined4 *)(this + 0x10) = 1;
  *(undefined ***)this = &_vftable__for__IClassFactory__;
  *(undefined ***)(this + 8) = &_vftable__for__IMarshal__;
  *(undefined8 *)this_00 = 0;
  Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease(this_00);
  CoCreateFreeThreadedMarshaler((LPUNKNOWN)0x0,(LPUNKNOWN *)this_00);
  return this;
}



===== Release @ 1400071f0 =====

/* public: virtual unsigned long __cdecl CRuntimeBrokerLifetimeExtensionFactory::Release(void)
   __ptr64 */

ulong __thiscall
CRuntimeBrokerLifetimeExtensionFactory::Release(CRuntimeBrokerLifetimeExtensionFactory *this)

{
  CRuntimeBrokerLifetimeExtensionFactory *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0x10;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if ((uVar3 == 0) && (this != (CRuntimeBrokerLifetimeExtensionFactory *)0x0)) {
    Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease
              ((ComPtr<Windows::System::IUserWatcher> *)(this + 0x18));
    operator_delete(this,(ulonglong)(iVar2 + 0x1f));
  }
  return uVar3;
}



===== InternalRelease @ 140007238 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* protected: unsigned long __cdecl Microsoft::WRL::ComPtr<struct
   Windows::System::IUserWatcher>::InternalRelease(void) __ptr64 */

ulong __thiscall
Microsoft::WRL::ComPtr<Windows::System::IUserWatcher>::InternalRelease
          (ComPtr<Windows::System::IUserWatcher> *this)

{
  longlong *plVar1;
  ulong uVar2;
  
  uVar2 = 0;
  plVar1 = *(longlong **)this;
  if (plVar1 != (longlong *)0x0) {
    *(undefined8 *)this = 0;
    uVar2 = (**(code **)(*plVar1 + 0x10))();
  }
  return uVar2;
}



===== <lambda_invoker_cdecl> @ 140007270 =====

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



===== OnSignaled @ 1400072a0 =====

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
  
  AcquireSRWLockShared((PSRWLOCK)param_1);
  uVar3 = (ulonglong)(*(longlong *)(this + 0x30) - *(longlong *)(this + 0x28)) >> 4;
  if (param_1 != (srwlock *)0x0) {
    ReleaseSRWLockShared((PSRWLOCK)param_1);
  }
  uVar4 = 0;
  if (uVar3 != 0) {
    do {
      pcVar6 = (code *)0x0;
      uVar7 = 0;
      EnterCriticalSection((LPCRITICAL_SECTION)this);
      AcquireSRWLockExclusive((PSRWLOCK)param_1);
      lVar2 = uVar4 << 4;
      uVar5 = uVar4;
      while (uVar4 = uVar5, uVar5 < uVar3) {
        uVar4 = uVar5 + 1;
        if (*(longlong *)(lVar2 + *(longlong *)(this + 0x28)) != 0) {
          puVar1 = (undefined8 *)(*(longlong *)(this + 0x28) + uVar5 * 0x10);
          pcVar6 = (code *)*puVar1;
          uVar7 = puVar1[1];
          break;
        }
        lVar2 = lVar2 + 0x10;
        uVar5 = uVar4;
      }
      if (param_1 != (srwlock *)0x0) {
        ReleaseSRWLockExclusive((PSRWLOCK)param_1);
      }
      if (pcVar6 != (code *)0x0) {
        (*pcVar6)(uVar7);
      }
      if (this != (SubscriptionList *)0x0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)this);
      }
    } while (uVar4 < uVar3);
  }
  return;
}



===== CreateInstance @ 1400073d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBroker::CFactory::CreateInstance(struct IUnknown *
   __ptr64,struct _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBroker::CFactory::CreateInstance
          (CFactory *this,IUnknown *param_1,_GUID *param_2,void **param_3)

{
  long lVar1;
  longlong *plVar2;
  
  *param_3 = (void *)0x0;
  if (param_1 != (IUnknown *)0x0) {
    return -0x7ffbfef0;
  }
  plVar2 = CoTaskMemAlloc(0x10);
  if (plVar2 == (longlong *)0x0) {
    lVar1 = -0x7ff8fff2;
  }
  else {
    *(undefined4 *)(plVar2 + 1) = 1;
    *plVar2 = (longlong)&CRuntimeBroker::_vftable_;
    CoAddRefServerProcess();
    lVar1 = (**(code **)*plVar2)(plVar2,param_2,param_3);
    (**(code **)(*plVar2 + 0x10))(plVar2);
  }
  return lVar1;
}



===== __delayLoadHelper2 @ 140007480 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(&IMAGE_DOS_HEADER_140000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== ~com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy> @ 1400074d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl wil::com_ptr_t<struct IIndirectCallTarget,struct
   wil::err_returncode_policy>::~com_ptr_t<struct IIndirectCallTarget,struct
   wil::err_returncode_policy>(void) __ptr64 */

void __thiscall
wil::com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy>::
~com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy>
          (com_ptr_t<IIndirectCallTarget,wil::err_returncode_policy> *this)

{
  if (*(longlong **)this == (longlong *)0x0) {
    return;
  }
  (**(code **)(**(longlong **)this + 0x10))();
  return;
}



===== ReadBrokerAumid @ 1400074f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: static int __cdecl CRuntimeBroker::ReadBrokerAumid(union _RTL_RUN_ONCE * __ptr64,void *
   __ptr64,void * __ptr64 * __ptr64) */

int __cdecl CRuntimeBroker::ReadBrokerAumid(_RTL_RUN_ONCE *param_1,void *param_2,void **param_3)

{
  longlong lVar1;
  _GUID *p_Var2;
  ulonglong uVar4;
  ulonglong uVar3;
  HString *pHVar5;
  _GUID *in_R9;
  undefined1 auStackY_168 [32];
  undefined4 local_138;
  uint local_134 [3];
  _GUID local_128 [17];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_168;
  pHVar5 = (HString *)local_128;
  local_138 = 0x82;
  p_Var2 = (_GUID *)0xfffffffffffffffc;
  local_134[0] = GetApplicationUserModelIdFromToken(0xfffffffffffffffc,&local_138);
  if (local_134[0] == 0) {
    uVar4 = 0xffffffffffffffff;
    do {
      uVar3 = uVar4 + 1;
      lVar1 = uVar4 * 2;
      uVar4 = uVar3;
    } while (*(short *)(local_128[0].Data4 + lVar1 + -6) != 0);
    if (uVar3 < 0x100000000) {
      WindowsDeleteString(_s_brokerAumid);
      pHVar5 = &s_brokerAumid;
      _s_brokerAumid = 0;
      p_Var2 = local_128;
      local_134[0] = WindowsCreateString(p_Var2,uVar3 & 0xffffffff);
    }
    else {
      local_134[0] = 0x80070216;
    }
  }
  else {
    if (local_134[0] == 0x3d57) {
      return 1;
    }
    if (0 < (int)local_134[0]) {
      local_134[0] = local_134[0] & 0xffff | 0x80070000;
    }
  }
  if (-1 < (int)local_134[0]) {
    return 1;
  }
  if (2 < DAT_140019008) {
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)p_Var2,&DAT_140015289,(_GUID *)pHVar5,in_R9,
               (_tlgWrapperByVal<4> *)local_134);
  }
  return 0;
}



===== QueryInterface @ 140007610 =====

/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::QueryInterface(struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::QueryInterface
          (CRuntimeBrokerLifetimeExtensionFactory *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  CRuntimeBrokerLifetimeExtensionFactory *pCVar2;
  
  *param_2 = (void *)0x0;
  lVar1._0_4_ = param_1->Data1;
  lVar1._4_2_ = param_1->Data2;
  lVar1._6_2_ = param_1->Data3;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)param_1->Data4 + -0x46000000000000c0;
  }
  if (lVar1 != 0) {
    lVar1 = *(longlong *)param_1 + -1;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)param_1->Data4 + -0x46000000000000c0;
    }
    if (lVar1 != 0) {
      lVar1 = *(longlong *)param_1 + -3;
      if (lVar1 == 0) {
        lVar1 = *(longlong *)param_1->Data4 + -0x46000000000000c0;
      }
      if (lVar1 == 0) {
        if (this == (CRuntimeBrokerLifetimeExtensionFactory *)0x0) {
          pCVar2 = (CRuntimeBrokerLifetimeExtensionFactory *)0x0;
        }
        else {
          pCVar2 = this + 8;
        }
        *param_2 = pCVar2;
        LOCK();
        *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
        UNLOCK();
        return 0;
      }
      lVar1 = *(longlong *)param_1 + -0x49e0e9cc94ea2b94;
      if (lVar1 == 0) {
        lVar1 = *(longlong *)param_1->Data4 + 0x6fa470359b110040;
      }
      if (lVar1 != 0) {
        return -0x7fffbffe;
      }
      pCVar2 = this + 8;
      if (this == (CRuntimeBrokerLifetimeExtensionFactory *)0x0) {
        pCVar2 = (CRuntimeBrokerLifetimeExtensionFactory *)0x0;
      }
      *param_2 = pCVar2;
      goto LAB_140007635;
    }
  }
  *param_2 = this;
LAB_140007635:
  LOCK();
  *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
  UNLOCK();
  return 0;
}



===== ReportFailure_Return<1> @ 1400076d0 =====

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
  undefined1 auStackY_1548 [32];
  undefined1 in_stack_ffffffffffffeb00;
  __uint64 in_stack_ffffffffffffeb10;
  __uint64 in_stack_ffffffffffffeb20;
  FailureInfo local_14c8 [4];
  byte local_14c4;
  char local_1428 [1024];
  ushort local_1028 [2048];
  ulonglong local_28;
  undefined8 uStack_20;
  
  uStack_20 = 0x1400076e2;
  local_28 = __security_cookie ^ (ulonglong)auStackY_1548;
  memset(local_14c8,0,0x98);
  LogFailure(param_1,param_2,param_3,(char *)0x0,(char *)0x0,param_6,1,param_7,(ushort *)0x0,
             (bool)in_stack_ffffffffffffeb00,local_1028,in_stack_ffffffffffffeb10,local_1428,
             in_stack_ffffffffffffeb20,local_14c8);
  if ((local_14c4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast(local_14c8);
  }
  return;
}



===== LogFailure @ 1400077bc =====

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
    if (!bVar8) goto LAB_140007a11;
  }
  else {
LAB_140007a11:
    if (((byte)param_15[4] & 2) == 0) {
      if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
        (*g_pfnResultLoggingCallback)(param_15,param_11,0x800);
      }
      if (*param_11 == 0) {
        GetFailureLogString(param_11,0x800,param_15);
      }
      OutputDebugStringW((LPCWSTR)param_11);
      goto LAB_140007a86;
    }
  }
  if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
    (*g_pfnResultLoggingCallback)(param_15,0,0);
  }
LAB_140007a86:
  if (((((byte)param_15[4] & 4) != 0) || (g_fBreakOnFailure != false)) &&
     (g_pfnDebugBreak != (_func_void *)0x0)) {
    (*g_pfnDebugBreak)();
  }
  return;
}



===== RtbPowerEpochChangedCallback @ 140007ad0 =====

/* unsigned long __cdecl RtbPowerEpochChangedCallback(void * __ptr64,unsigned long,void * __ptr64)
    */

ulong __cdecl RtbPowerEpochChangedCallback(void *param_1,ulong param_2,void *param_3)

{
  int iVar1;
  RPC_STATUS local_res10 [6];
  
  local_res10[0] = 0;
  if (((param_2 != 0x8013) ||
      (iVar1 = UuidEqual(param_3,(UUID *)&GUID_LOW_POWER_EPOCH,local_res10), iVar1 == 0)) ||
     (*(int *)((longlong)param_3 + 0x10) != 4)) {
    return 0x57;
  }
  if (*(int *)((longlong)param_3 + 0x14) == 1) {
    DAT_14001926c = 0xffffffff;
  }
  else {
    DAT_14001926c = 60000;
  }
  LOCK();
  UNLOCK();
  if (g_hLowPowerEpoch != (void *)0x0) {
    SetEvent(g_hLowPowerEpoch);
  }
  return 0;
}



===== `dynamic_initializer_for_'g_featureStateManager'' @ 140007b60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wil::details::_dynamic_initializer_for__g_featureStateManager__(void)

{
  details_abi::SubscriptionList::SubscriptionList((SubscriptionList *)&DAT_140019100);
  DAT_140019148 = 0;
  details_abi::SubscriptionList::SubscriptionList((SubscriptionList *)&DAT_140019150);
  _DAT_1400191b8 = 0;
  g_featureStateManager = (shutdown_aware_object<wil::details::FeatureStateManager>)0x1;
  _DAT_140019198 = 0;
  uRam00000001400191a0 = 0;
  _DAT_1400191a8 = 0;
  uRam00000001400191b0 = 0;
  atexit(_dynamic_atexit_destructor_for__g_featureStateManager__);
  return;
}



===== SubscriptionList @ 140007bc0 =====

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



===== AddRef @ 140007c00 =====

/* private: virtual unsigned long __cdecl
   CRuntimeBrokerLifetimeExtensionFactory::CLifetimeExtension::AddRef(void) __ptr64 */

ulong __thiscall
CRuntimeBrokerLifetimeExtensionFactory::CLifetimeExtension::AddRef(CLifetimeExtension *this)

{
  CLifetimeExtension *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 8;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}



===== MicrosoftInternalNotifyFailure @ 140007c20 =====

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



===== WilFailureNotifyWatchers @ 140007cd0 =====

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



===== QueryProcessTokenSid @ 140007d30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static int __cdecl CRuntimeBroker::QueryProcessTokenSid(union _RTL_RUN_ONCE *
   __ptr64,void * __ptr64,void * __ptr64 * __ptr64) */

int __cdecl
CRuntimeBroker::QueryProcessTokenSid(_RTL_RUN_ONCE *param_1,void *param_2,void **param_3)

{
  BOOL BVar1;
  DWORD nDestinationSidLength;
  undefined1 auStackY_b8 [32];
  DWORD local_88 [4];
  PSID local_78 [12];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_88[0] = 0;
  BVar1 = GetTokenInformation((HANDLE)0xfffffffffffffffc,TokenUser,local_78,0x54,local_88);
  if (BVar1 != 0) {
    nDestinationSidLength = GetLengthSid(local_78[0]);
    CopySid(nDestinationSidLength,&s_rtbSelfSid,local_78[0]);
  }
  return BVar1;
}



===== GetContextAndNotifyFailure @ 140007df0 =====

/* void __cdecl wil::details::GetContextAndNotifyFailure(struct wil::FailureInfo * __ptr64,char *
   __ptr64,unsigned __int64) */

void __cdecl
wil::details::GetContextAndNotifyFailure(FailureInfo *param_1,char *param_2,__uint64 param_3)

{
  ThreadFailureCallbackHolder::GetContextAndNotifyFailure(param_1,param_2,param_3);
  SetLastError(param_1);
  return;
}



===== GetContextAndNotifyFailure @ 140007e14 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: static void __cdecl
   wil::details::ThreadFailureCallbackHolder::GetContextAndNotifyFailure(struct wil::FailureInfo *
   __ptr64,char * __ptr64,unsigned __int64) */

void __cdecl
wil::details::ThreadFailureCallbackHolder::GetContextAndNotifyFailure
          (FailureInfo *param_1,char *param_2,__uint64 param_3)

{
  bool bVar1;
  byte bVar2;
  ThreadFailureCallbackHolder **ppTVar3;
  bool bVar4;
  byte bVar5;
  ThreadFailureCallbackHolder *pTVar6;
  
  bVar4 = false;
  *param_2 = '\0';
  bVar5 = 0;
  if (((g_pThreadFailureCallbacks !=
        (ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *)0x0) &&
      (ppTVar3 = details_abi::ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>
                 ::GetLocal((ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>
                             *)param_1,SUB81(param_2,0)),
      ppTVar3 != (ThreadFailureCallbackHolder **)0x0)) &&
     (*ppTVar3 != (ThreadFailureCallbackHolder *)0x0)) {
    *param_2 = '\0';
    bVar1 = GetThreadContext(param_1,*ppTVar3,param_2,param_3);
    if (bVar1) {
      *(char **)(param_1 + 0x48) = param_2;
    }
    pTVar6 = *ppTVar3;
    do {
      bVar2 = (**(code **)**(undefined8 **)(pTVar6 + 8))(*(undefined8 **)(pTVar6 + 8),param_1);
      pTVar6 = *(ThreadFailureCallbackHolder **)(pTVar6 + 0x10);
      bVar5 = bVar5 | bVar2;
    } while (pTVar6 != (ThreadFailureCallbackHolder *)0x0);
  }
  if (g_pfnTelemetryCallback != (_func_void_bool_FailureInfo_ptr *)0x0) {
    if ((bVar5 != 0) || (((byte)param_1[4] & 2) != 0)) {
      bVar4 = true;
    }
    (*g_pfnTelemetryCallback)(bVar4,param_1);
  }
  return;
}



===== GetLocal @ 140007edc =====

/* public: class wil::details::ThreadFailureCallbackHolder * __ptr64 * __ptr64 __cdecl
   wil::details_abi::ThreadLocalStorage<class wil::details::ThreadFailureCallbackHolder *
   __ptr64>::GetLocal(bool) __ptr64 */

ThreadFailureCallbackHolder ** __thiscall
wil::details_abi::ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>::GetLocal
          (ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *this,bool param_1
          )

{
  ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *pTVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  
  pTVar1 = details::g_pThreadFailureCallbacks;
  DVar2 = GetCurrentThreadId();
  pDVar3 = *(DWORD **)(pTVar1 + ((ulonglong)DVar2 + ((ulonglong)DVar2 / 10) * -10) * 8);
  while( true ) {
    if (pDVar3 == (DWORD *)0x0) {
      return (ThreadFailureCallbackHolder **)0x0;
    }
    if (*pDVar3 == DVar2) break;
    pDVar3 = *(DWORD **)(pDVar3 + 2);
  }
  return (ThreadFailureCallbackHolder **)(pDVar3 + 4);
}



===== `dynamic_initializer_for_'g_header_init_WilInitialize_ResultMacros_DesktopOrSystem'' @ 140007f40 =====

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



===== reset @ 140007fac =====

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



===== Release @ 140008010 =====

/* private: virtual unsigned long __cdecl
   CRuntimeBrokerLifetimeExtensionFactory::CLifetimeExtension::Release(void) __ptr64 */

ulong __thiscall
CRuntimeBrokerLifetimeExtensionFactory::CLifetimeExtension::Release(CLifetimeExtension *this)

{
  CLifetimeExtension *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 8;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if ((iVar2 - 1U == 0) && (this != (CLifetimeExtension *)0x0)) {
    ~CLifetimeExtension(this);
    operator_delete(this,0x18);
  }
  return iVar2 - 1U;
}



===== GetUnmarshalClass @ 140008060 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::GetUnmarshalClass(struct
   _GUID const & __ptr64,void * __ptr64,unsigned long,void * __ptr64,unsigned long,struct _GUID *
   __ptr64) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::GetUnmarshalClass
          (CRuntimeBrokerLifetimeExtensionFactory *this,_GUID *param_1,void *param_2,ulong param_3,
          void *param_4,ulong param_5,_GUID *param_6)

{
  longlong *plVar1;
  long lVar2;
  
  plVar1 = *(longlong **)(this + 0x10);
  if (plVar1 == (longlong *)0x0) {
    lVar2 = -0x7ff8fff2;
  }
  else {
    lVar2 = (**(code **)(*plVar1 + 0x18))(plVar1,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return lVar2;
}



===== AddRef @ 1400080c0 =====

/* public: virtual unsigned long __cdecl CRuntimeBroker::CFactory::AddRef(void) __ptr64 */

ulong __thiscall CRuntimeBroker::CFactory::AddRef(CFactory *this)

{
  return 2;
}



===== StringVPrintfWorkerW @ 1400080d0 =====

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



===== SetLastError @ 140008130 =====

/* void __cdecl wil::SetLastError(struct wil::FailureInfo const & __ptr64) */

void __cdecl wil::SetLastError(FailureInfo *param_1)

{
  int iVar1;
  DWORD DVar2;
  ThreadLocalData *this;
  FailureInfo *pFVar3;
  int iVar4;
  
  pFVar3 = param_1;
  DVar2 = GetCurrentThreadId();
  if (`void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l2::lastThread != DVar2)
  {
    LOCK();
    iVar1 = `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth + 1;
    UNLOCK();
    iVar4 = `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth + 1;
    `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth = iVar1;
    if (iVar4 < 4) {
      `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l2::lastThread = DVar2;
      this = details_abi::GetThreadLocalDataCache(SUB81(pFVar3,0));
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



===== GetThreadLocalDataCache @ 14000819c =====

/* struct wil::details_abi::ThreadLocalData * __ptr64 __cdecl
   wil::details_abi::GetThreadLocalDataCache(bool) */

ThreadLocalData * __cdecl wil::details_abi::GetThreadLocalDataCache(bool param_1)

{
  ProcessLocalData *pPVar1;
  ThreadLocalData *pTVar2;
  undefined7 in_register_00000009;
  undefined1 in_DL;
  
  pTVar2 = (ThreadLocalData *)0x0;
  if (g_pProcessLocalData != (ProcessLocalStorage<wil::details_abi::ProcessLocalData> *)0x0) {
    pPVar1 = ProcessLocalStorage<wil::details_abi::ProcessLocalData>::GetShared
                       ((ProcessLocalStorage<wil::details_abi::ProcessLocalData> *)
                        CONCAT71(in_register_00000009,param_1));
    if (pPVar1 != (ProcessLocalData *)0x0) {
      pTVar2 = ThreadLocalStorage<wil::details_abi::ThreadLocalData>::GetLocal
                         ((ThreadLocalStorage<wil::details_abi::ThreadLocalData> *)(pPVar1 + 8),
                          (bool)in_DL);
      if ((pTVar2 != (ThreadLocalData *)0x0) && (*(longlong *)(pTVar2 + 8) == 0)) {
        *(ProcessLocalData **)(pTVar2 + 8) = pPVar1 + 4;
      }
    }
  }
  return pTVar2;
}



===== GetLocal @ 1400081f4 =====

/* public: struct wil::details_abi::ThreadLocalData * __ptr64 __cdecl
   wil::details_abi::ThreadLocalStorage<struct wil::details_abi::ThreadLocalData>::GetLocal(bool)
   __ptr64 */

ThreadLocalData * __thiscall
wil::details_abi::ThreadLocalStorage<wil::details_abi::ThreadLocalData>::GetLocal
          (ThreadLocalStorage<wil::details_abi::ThreadLocalData> *this,bool param_1)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  DVar1 = GetCurrentThreadId();
  pDVar2 = *(DWORD **)(this + ((ulonglong)DVar1 + ((ulonglong)DVar1 / 10) * -10) * 8);
  while( true ) {
    if (pDVar2 == (DWORD *)0x0) {
      return (ThreadLocalData *)0x0;
    }
    if (*pDVar2 == DVar1) break;
    pDVar2 = *(DWORD **)(pDVar2 + 2);
  }
  return (ThreadLocalData *)(pDVar2 + 4);
}



===== Release @ 140008250 =====

/* public: virtual unsigned long __cdecl CRuntimeBroker::CFactory::Release(void) __ptr64 */

ulong __thiscall CRuntimeBroker::CFactory::Release(CFactory *this)

{
  return 1;
}



===== acquire @ 140008260 =====

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



===== GetCurrentModuleName @ 1400082c0 =====

/* char const * __ptr64 __cdecl wil::details::GetCurrentModuleName(void) */

char * __cdecl wil::details::GetCurrentModuleName(void)

{
  if (!`char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2::s_fModuleValid)
  {
    GetModuleInformation
              (RecordFailFast,(uint *)0x0,
               (char *)&`char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2
                        ::s_szModule,0x40);
    `char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2::s_fModuleValid =
         true;
  }
  return (char *)&`char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2::
                  s_szModule;
}



===== `dynamic_initializer_for_'g_header_init_InitializeResultHeader'' @ 140008310 =====

void wil::details::_dynamic_initializer_for__g_header_init_InitializeResultHeader__(void)

{
  g_pfnGetContextAndNotifyFailure = GetContextAndNotifyFailure;
  details_abi::g_pProcessLocalData =
       (ProcessLocalStorage<wil::details_abi::ProcessLocalData> *)&g_processLocalData;
  g_pThreadFailureCallbacks = &g_threadFailureCallbacks;
  return;
}



===== DisconnectObject @ 140008350 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::DisconnectObject(unsigned
   long) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::DisconnectObject
          (CRuntimeBrokerLifetimeExtensionFactory *this,ulong param_1)

{
  long lVar1;
  
  if (*(longlong **)(this + 0x10) == (longlong *)0x0) {
    return -0x7ff8fff2;
  }
  lVar1 = (**(code **)(**(longlong **)(this + 0x10) + 0x40))();
  return lVar1;
}



===== wil_details_GetNtDllModuleHandle @ 140008374 =====

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



===== EnsureSubscribedToUsageFlush @ 1400083ac =====

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
  
  if (*this != (EnabledStateManager)0x0) {
    SRWLock = this + 8;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    pEVar1 = this + 0x28;
    if (*(longlong *)pEVar1 == 0) {
      *(longlong *)pEVar1 = 0;
      pcVar2 = g_wil_details_internalSubscribeFeatureStateChangeNotification;
      if ((g_wil_details_internalSubscribeFeatureStateChangeNotification != (code *)0x0) ||
         (pcVar2 = g_wil_details_apiSubscribeFeatureStateChangeNotification,
         g_wil_details_apiSubscribeFeatureStateChangeNotification != (code *)0x0)) {
        (*pcVar2)(pEVar1,param_1,0xffffffffffffffff);
      }
    }
    if (SRWLock != (EnabledStateManager *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
  }
  return;
}



===== `dynamic_initializer_for_'g_header_init_InitializeStagingHeaderInternalApi'' @ 140008440 =====

void wil::details::_dynamic_initializer_for__g_header_init_InitializeStagingHeaderInternalApi__
               (void)

{
  g_wil_details_internalGetFeatureEnabledState = WilApiImpl_GetFeatureEnabledState;
  g_wil_details_internalRecordFeatureUsage = WilApiImpl_RecordFeatureUsage;
  g_wil_details_internalSubscribeFeatureStateChangeNotification =
       WilApiImpl_SubscribeFeatureStateChangeNotification;
  g_wil_details_internalUnsubscribeFeatureStateChangeNotification =
       WilApiImpl_UnsubscribeFeatureStateChangeNotification;
  g_wil_details_realtimeFeatureUsageHook = wil_StagingConfig_LogStagedFeatureUsage;
  return;
}



===== <lambda_invoker_cdecl> @ 140008490 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: static __cdecl <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>(void *param_1)

{
  PSRWLOCK SRWLock;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  code *pcVar6;
  undefined8 uVar7;
  
  if (*(char *)param_1 != '\0') {
    SRWLock = (PSRWLOCK)((longlong)param_1 + 0x20);
    lpCriticalSection = (LPCRITICAL_SECTION)((longlong)param_1 + 0x98);
    AcquireSRWLockShared(SRWLock);
    uVar3 = (ulonglong)
            (*(longlong *)((longlong)param_1 + 200) - *(longlong *)((longlong)param_1 + 0xc0)) >> 4;
    if (SRWLock != (PSRWLOCK)0x0) {
      ReleaseSRWLockShared(SRWLock);
    }
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        pcVar6 = (code *)0x0;
        uVar7 = 0;
        EnterCriticalSection(lpCriticalSection);
        AcquireSRWLockExclusive(SRWLock);
        lVar2 = uVar4 << 4;
        uVar5 = uVar4;
        while (uVar4 = uVar5, uVar5 < uVar3) {
          uVar4 = uVar5 + 1;
          if (*(longlong *)(lVar2 + *(longlong *)((longlong)param_1 + 0xc0)) != 0) {
            puVar1 = (undefined8 *)(*(longlong *)((longlong)param_1 + 0xc0) + uVar5 * 0x10);
            pcVar6 = (code *)*puVar1;
            uVar7 = puVar1[1];
            break;
          }
          lVar2 = lVar2 + 0x10;
          uVar5 = uVar4;
        }
        if (SRWLock != (PSRWLOCK)0x0) {
          ReleaseSRWLockExclusive(SRWLock);
        }
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)(uVar7);
        }
        if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
          LeaveCriticalSection(lpCriticalSection);
        }
      } while (uVar4 < uVar3);
    }
  }
  return;
}



===== AddRef @ 1400084a0 =====

/* public: virtual unsigned long __cdecl CRuntimeBrokerLifetimeExtensionFactory::AddRef(void)
   __ptr64 */

ulong __thiscall
CRuntimeBrokerLifetimeExtensionFactory::AddRef(CRuntimeBrokerLifetimeExtensionFactory *this)

{
  CRuntimeBrokerLifetimeExtensionFactory *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 0x10;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}



===== operator_delete @ 1400084b4 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001400084b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CoTaskMemFree(param_1);
  return;
}



===== RecordReturn @ 1400084c8 =====

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



===== ReleaseMutex @ 1400084e8 =====

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



===== `dynamic_initializer_for_'g_hHeap'' @ 140008520 =====

void _dynamic_initializer_for__g_hHeap__(void)

{
  g_hHeap = *(void **)((longlong)ProcessEnvironmentBlock + 0x30);
  return;
}



===== Compare @ 14000853c =====

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



===== `dynamic_initializer_for_'g_enabledStateManager'' @ 140008570 =====

void wil::details::_dynamic_initializer_for__g_enabledStateManager__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_enabledStateManager__);
  return;
}



===== `dynamic_atexit_destructor_for_'g_threadFailureCallbacks'' @ 140008590 =====

void wil::details::_dynamic_atexit_destructor_for__g_threadFailureCallbacks__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_threadFailureCallbacks__);
  return;
}



===== OnStateChange @ 1400085a4 =====

/* public: void __cdecl wil::details::EnabledStateManager::OnStateChange(void) __ptr64 */

void __thiscall wil::details::EnabledStateManager::OnStateChange(EnabledStateManager *this)

{
  EnabledStateManager *SRWLock;
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (*this != (EnabledStateManager)0x0) {
    SRWLock = this + 8;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
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
    if (SRWLock != (EnabledStateManager *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
  }
  return;
}



===== operator_new @ 140008634 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1)

{
  LPVOID pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140008634. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = CoTaskMemAlloc(param_1);
  return pvVar1;
}



===== `dynamic_initializer_for_'g_processLocalData'' @ 140008650 =====

void wil::details::_dynamic_initializer_for__g_processLocalData__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_processLocalData__);
  return;
}



===== <lambda_invoker_cdecl> @ 140008670 =====

/* private: static __cdecl <lambda_0374aa0a5d1201b2358c6bce99369c58>::<lambda_invoker_cdecl>(struct
   _TP_CALLBACK_INSTANCE * __ptr64,void * __ptr64,struct _TP_TIMER * __ptr64) */

void __cdecl
<lambda_0374aa0a5d1201b2358c6bce99369c58>::<lambda_invoker_cdecl>
          (_TP_CALLBACK_INSTANCE *param_1,void *param_2,_TP_TIMER *param_3)

{
  wil::details::EnabledStateManager::OnTimer(param_2);
  return;
}



===== EnsureCoalescedTimer_SetTimer @ 140008680 =====

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



===== ~CLifetimeExtension @ 1400086c8 =====

/* private: __cdecl
   CRuntimeBrokerLifetimeExtensionFactory::CLifetimeExtension::~CLifetimeExtension(void) __ptr64 */

void __thiscall
CRuntimeBrokerLifetimeExtensionFactory::CLifetimeExtension::~CLifetimeExtension
          (CLifetimeExtension *this)

{
  CRuntimeBrokerLifetimeExtensionFactory *this_00;
  
  *(undefined ***)this = &_vftable_;
  CoReleaseServerProcess();
  this_00 = *(CRuntimeBrokerLifetimeExtensionFactory **)(this + 0x10);
  if (this_00 != (CRuntimeBrokerLifetimeExtensionFactory *)0x0) {
    *(undefined8 *)(this + 0x10) = 0;
    CRuntimeBrokerLifetimeExtensionFactory::Release(this_00);
  }
  return;
}



===== s_brokerAumid'' @ 140008710 =====

void `dynamic_initializer_for_'CRuntimeBroker::s_brokerAumid__(void)

{
  atexit(`dynamic_atexit_destructor_for_'CRuntimeBroker::s_brokerAumid__);
  return;
}



===== WilApiImpl_RecordFeatureUsage @ 140008730 =====

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



===== ~FeatureStateManager @ 14000879c =====

/* public: __cdecl wil::details::FeatureStateManager::~FeatureStateManager(void) __ptr64 */

void __thiscall wil::details::FeatureStateManager::~FeatureStateManager(FeatureStateManager *this)

{
  void *pvVar1;
  
  *this = (FeatureStateManager)0x0;
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
           *)(this + 0x30),(_TP_TIMER *)0x0);
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
           *)(this + 0x38),(_TP_TIMER *)0x0);
  pvVar1 = *(void **)(this + 0x100);
  *(undefined8 *)(this + 0x100) = 0;
  if (pvVar1 != (void *)0x0) {
    FreeProcessHeap(pvVar1);
  }
  unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::UnsubscribeProcessWideUsageFlush(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::UnsubscribeProcessWideUsageFlush(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::UnsubscribeProcessWideUsageFlush(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
              *)(this + 0xe0));
  details_abi::SubscriptionList::~SubscriptionList((SubscriptionList *)(this + 0x98));
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_wil::details::UnregisterWilFeatureConfigurationChange(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_wil::details::UnregisterWilFeatureConfigurationChange(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_wil::details::UnregisterWilFeatureConfigurationChange(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)(this + 0x90));
  details_abi::SubscriptionList::~SubscriptionList((SubscriptionList *)(this + 0x48));
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
              *)(this + 0x38));
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
              *)(this + 0x30));
  details_abi::ProcessLocalStorage<wil::details_abi::FeatureStateData>::
  ~ProcessLocalStorage<wil::details_abi::FeatureStateData>
            ((ProcessLocalStorage<wil::details_abi::FeatureStateData> *)(this + 8));
  return;
}



===== FreeProcessHeap @ 140008840 =====

/* void __cdecl wil::details::FreeProcessHeap(void * __ptr64) */

void __cdecl wil::details::FreeProcessHeap(void *param_1)

{
  HANDLE hHeap;
  
  hHeap = GetProcessHeap();
                    /* WARNING: Could not recover jumptable at 0x000140008862. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapFree(hHeap,0,param_1);
  return;
}



===== <lambda_invoker_cdecl> @ 140008880 =====

/* private: static __cdecl <lambda_d51448ba32f8ef42e59400edd4566183>::<lambda_invoker_cdecl>(struct
   _TP_CALLBACK_INSTANCE * __ptr64,void * __ptr64,struct _TP_TIMER * __ptr64) */

void __cdecl
<lambda_d51448ba32f8ef42e59400edd4566183>::<lambda_invoker_cdecl>
          (_TP_CALLBACK_INSTANCE *param_1,void *param_2,_TP_TIMER *param_3)

{
  wil::details::FeatureStateManager::OnTimer(param_2);
  return;
}



===== `dynamic_atexit_destructor_for_'g_threadFailureCallbacks'' @ 140008890 =====

void wil::details::_dynamic_atexit_destructor_for__g_threadFailureCallbacks__(void)

{
  details_abi::ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>::
  ~ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>(&g_threadFailureCallbacks)
  ;
  return;
}



===== FlushUsage @ 1400088a4 =====

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



===== OnTimer @ 1400088e8 =====

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



===== RtlDllShutdownInProgress @ 140008940 =====

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



===== Swap @ 140008984 =====

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



===== heap_buffer @ 140008a28 =====

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



===== unique_ptr<void,wil::process_heap_deleter> @ 140008a5c =====

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



===== __compressed_pair<void*___ptr64,wil::process_heap_deleter><void*___ptr64,wil::process_heap_deleter> @ 140008a88 =====

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



===== operator= @ 140008a9c =====

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



===== ~EnabledStateManager @ 140008acc =====

/* public: __cdecl wil::details::EnabledStateManager::~EnabledStateManager(void) __ptr64 */

void __thiscall wil::details::EnabledStateManager::~EnabledStateManager(EnabledStateManager *this)

{
  void *pvVar1;
  
  *this = (EnabledStateManager)0x0;
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
           *)(this + 0x10),(_TP_TIMER *)0x0);
  *this = (EnabledStateManager)0x0;
  RecordCachedUsageUnderLock(this);
  pvVar1 = *(void **)(this + 0x68);
  *(undefined8 *)(this + 0x68) = 0;
  if (pvVar1 != (void *)0x0) {
    FreeProcessHeap(pvVar1);
  }
  pvVar1 = *(void **)(this + 0x48);
  *(undefined8 *)(this + 0x48) = 0;
  if (pvVar1 != (void *)0x0) {
    FreeProcessHeap(pvVar1);
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
            ((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
              *)(this + 0x10));
  return;
}



===== reset @ 140008b44 =====

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
  last_error_context local_res8 [8];
  
  p_Var1 = *(_TP_TIMER **)this;
  if (p_Var1 != (_TP_TIMER *)0x0) {
    last_error_context::last_error_context(local_res8);
    DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy(p_Var1);
    last_error_context::~last_error_context(local_res8);
  }
  *(_TP_TIMER **)this = param_1;
  return;
}



===== ~unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::WilApi_UnsubscribeFeatureStateChangeNotification(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_> @ 140008b98 =====

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



===== Return_GetLastError @ 140008bb8 =====

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



===== GetLastErrorFailHr @ 140008bd8 =====

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



===== ReportFailure_GetLastErrorHr<1> @ 140008c0c =====

/* long __cdecl wil::details::ReportFailure_GetLastErrorHr<1>(void * __ptr64,unsigned int,char const
   * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64) */

long __cdecl
wil::details::ReportFailure_GetLastErrorHr<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6)

{
  ulong uVar1;
  char *in_stack_ffffffffffffffb8;
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  ulong local_18;
  long local_14;
  undefined4 local_10;
  
  uVar1 = GetLastErrorFail(param_1,param_2,param_3,param_4,in_stack_ffffffffffffffb8,param_6);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  local_18 = uVar1;
  local_14 = HrToNtStatus(uVar1);
  local_10 = 0;
  ReportFailure_Base<1,0>
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffb8,param_6,
             (ResultStatus *)&local_18,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8);
  return uVar1;
}



===== GetLastErrorFail @ 140008ca4 =====

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



===== ~ProcessLocalStorage<wil::details_abi::FeatureStateData> @ 140008d10 =====

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



===== Initialize @ 140008d30 =====

/* protected: virtual void __cdecl wil::TraceLoggingProvider::Initialize(void) __ptr64 */

void __thiscall wil::TraceLoggingProvider::Initialize(TraceLoggingProvider *this)

{
  return;
}



===== ~SubscriptionList @ 140008d3c =====

/* public: __cdecl wil::details_abi::SubscriptionList::~SubscriptionList(void) __ptr64 */

void __thiscall wil::details_abi::SubscriptionList::~SubscriptionList(SubscriptionList *this)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(this + 0x40);
  *(undefined8 *)(this + 0x40) = 0;
  if (pvVar1 != (void *)0x0) {
    details::FreeProcessHeap(pvVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x000140008d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteCriticalSection((LPCRITICAL_SECTION)this);
  return;
}



===== ProcessHeapAlloc @ 140008d74 =====

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



===== <lambda_invoker_cdecl> @ 140008e40 =====

/* private: static __cdecl <lambda_fee8cea507d2413a58be13acfb66740a>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_fee8cea507d2413a58be13acfb66740a>::<lambda_invoker_cdecl>(void *param_1)

{
  PSRWLOCK SRWLock;
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*(char *)param_1 != '\0') {
    SRWLock = (PSRWLOCK)((longlong)param_1 + 8);
    AcquireSRWLockExclusive(SRWLock);
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
    if (SRWLock != (PSRWLOCK)0x0) {
      ReleaseSRWLockExclusive(SRWLock);
    }
  }
  return;
}



===== GetShared @ 140008e4c =====

/* public: struct wil::details_abi::ProcessLocalData * __ptr64 __cdecl
   wil::details_abi::ProcessLocalStorage<struct wil::details_abi::ProcessLocalData>::GetShared(void)
   __ptr64 */

ProcessLocalData * __thiscall
wil::details_abi::ProcessLocalStorage<wil::details_abi::ProcessLocalData>::GetShared
          (ProcessLocalStorage<wil::details_abi::ProcessLocalData> *this)

{
  ProcessLocalStorage<wil::details_abi::ProcessLocalData> *pPVar1;
  long lVar2;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *local_res8 [4];
  
  pPVar1 = g_pProcessLocalData;
  if (*(longlong *)(g_pProcessLocalData + 8) == 0) {
    local_res8[0] = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
    lVar2 = ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Acquire
                      (*(char **)g_pProcessLocalData,local_res8);
    if ((-1 < lVar2) && (*(longlong *)(pPVar1 + 8) == 0)) {
      *(ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **)(pPVar1 + 8) =
           local_res8[0];
    }
  }
  return (ProcessLocalData *)
         (-(ulonglong)(*(longlong *)(pPVar1 + 8) != 0) & *(longlong *)(pPVar1 + 8) + 0x20U);
}



===== ~unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION*___ptr64,void_(__cdecl*)(_RTL_CRITICAL_SECTION*___ptr64),&void___cdecl_LeaveCriticalSection(struct__RTL_CRITICAL_SECTION*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_CRITICAL_SECTION*___ptr64,_RTL_CRITICAL_SECTION*___ptr64,0,std::nullptr_t>_> @ 140008eac =====

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



===== ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_> @ 140008ed0 =====

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



===== ~unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_> @ 140008ef4 =====

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



===== ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockExclusive(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_> @ 140008f14 =====

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



===== ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::ReleaseMutex(void*___ptr64),wistd::integral_constant<unsigned___int64,2>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_> @ 140008f38 =====

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



===== ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_> @ 140008f58 =====

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



===== ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_wil::details::UnregisterWilFeatureConfigurationChange(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_> @ 140008f78 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   wil::details::UnregisterWilFeatureConfigurationChange(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void *
   __ptr64),&void __cdecl wil::details::UnregisterWilFeatureConfigurationChange(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_wil::details::UnregisterWilFeatureConfigurationChange(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_wil::details::UnregisterWilFeatureConfigurationChange(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_wil::details::UnregisterWilFeatureConfigurationChange(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(longlong *)this != 0) {
    wil_details_RtlUnregisterFeatureConfigurationChangeNotification(*(longlong *)this);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::UnsubscribeProcessWideUsageFlush(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_> @ 140008f98 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,void (__cdecl*)(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64),&void __cdecl
   wil::details::UnsubscribeProcessWideUsageFlush(struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,void (__cdecl*)(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64),&void __cdecl
   wil::details::UnsubscribeProcessWideUsageFlush(struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64,struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::UnsubscribeProcessWideUsageFlush(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::UnsubscribeProcessWideUsageFlush(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,void_(__cdecl*)(FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),&void___cdecl_wil::details::UnsubscribeProcessWideUsageFlush(struct_FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64),wistd::integral_constant<unsigned___int64,0>,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,FEATURE_STATE_CHANGE_SUBSCRIPTION__*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)this != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
    UnsubscribeProcessWideUsageFlush(*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)this);
  }
  return;
}



===== initialize_legacy_wide_specifiers @ 140008fc0 =====

undefined8 initialize_legacy_wide_specifiers(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 4;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return 0;
}



===== __local_stdio_printf_options @ 140008fe4 =====

__uint64 * __local_stdio_printf_options(void)

{
  return &`__local_stdio_printf_options'::__l2::_OptionsStorage;
}



===== __local_stdio_scanf_options @ 140008ff4 =====

__uint64 * __local_stdio_scanf_options(void)

{
  return &`__local_stdio_scanf_options'::__l2::_OptionsStorage;
}



===== initialize_msvcrt_compatibility @ 140009010 =====

undefined8 initialize_msvcrt_compatibility(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x18;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 4;
  return 0;
}



===== pre_c_initialization @ 140009040 =====

void pre_c_initialization(void)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  
  _o__set_app_type(2);
  uVar3 = _get_startup_file_mode();
  _set_fmode(uVar3 & 0xffffffff);
  uVar4 = _get_startup_commit_mode();
  puVar5 = (undefined4 *)_o___p__commode();
  *puVar5 = (int)uVar4;
  uVar4 = __scrt_initialize_onexit_tables(1);
  if ((char)uVar4 != '\0') {
    _RTC_Initialize();
    atexit(_RTC_Terminate);
    uVar3 = _get_startup_argv_mode();
    iVar2 = _configure_wide_argv(uVar3 & 0xffffffff);
    if (iVar2 == 0) {
      __scrt_initialize_type_info();
      _guard_check_icall();
      _guard_check_icall();
      uVar3 = _get_startup_commit_mode();
      _o__configthreadlocale(uVar3 & 0xffffffff);
      cVar1 = __vcrt_initialize();
      if (cVar1 != '\0') {
        _initialize_wide_environment();
      }
      _get_startup_commit_mode();
      uVar4 = __scrt_initialize_mta();
      if ((int)uVar4 == 0) {
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  __scrt_fastfail(7);
}



===== post_pgo_initialization @ 1400090f0 =====

undefined8 post_pgo_initialization(void)

{
  __scrt_initialize_default_local_stdio_options();
  return 0;
}



===== pre_cpp_initialization @ 140009110 =====

void pre_cpp_initialization(void)

{
  ulonglong uVar1;
  
  __scrt_set_unhandled_exception_filter();
  uVar1 = _get_startup_commit_mode();
  _set_new_mode(uVar1 & 0xffffffff);
  return;
}



===== __scrt_common_main_seh @ 140009130 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong __scrt_common_main_seh(void)

{
  code *pcVar1;
  bool bVar2;
  WORD WVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  LPWSTR lpCmdLine;
  IMAGE_DOS_HEADER *pIVar10;
  
  lVar6 = __scrt_initialize_crt(1);
  if ((char)lVar6 == '\0') {
                    /* WARNING: Subroutine does not return */
    __scrt_fastfail(7);
  }
  bVar2 = false;
  uVar7 = __scrt_acquire_startup_lock();
  if (__scrt_current_native_startup_state == 1) {
                    /* WARNING: Subroutine does not return */
    __scrt_fastfail(7);
  }
  if (__scrt_current_native_startup_state == 0) {
    __scrt_current_native_startup_state = 1;
    iVar4 = _initterm_e(&__xi_a,&__xi_z);
    if (iVar4 != 0) {
      return 0xff;
    }
    _initterm(&__xc_a);
    __scrt_current_native_startup_state = 2;
  }
  else {
    bVar2 = true;
  }
  __scrt_release_startup_lock((char)uVar7);
  plVar8 = (longlong *)__scrt_get_dyn_tls_init_callback();
  if ((*plVar8 != 0) &&
     (uVar9 = __scrt_is_nonwritable_in_current_image((longlong)plVar8), (char)uVar9 != '\0')) {
    (*(code *)*plVar8)(0);
  }
  plVar8 = (longlong *)__scrt_get_dyn_tls_dtor_callback();
  if ((*plVar8 != 0) &&
     (uVar9 = __scrt_is_nonwritable_in_current_image((longlong)plVar8), (char)uVar9 != '\0')) {
    _register_thread_local_exe_atexit_callback(*plVar8);
  }
  WVar3 = __scrt_get_show_window_mode();
  lpCmdLine = (LPWSTR)_get_wide_winmain_command_line();
  pIVar10 = &IMAGE_DOS_HEADER_140000000;
  uVar5 = wWinMain((HINSTANCE)&IMAGE_DOS_HEADER_140000000,(HINSTANCE)0x0,lpCmdLine,(uint)WVar3);
  uVar9 = __scrt_is_managed_app();
  if ((char)uVar9 == '\0') {
    exit(uVar5);
    _exit(uVar5);
    pcVar1 = (code *)swi(3);
    uVar9 = (*pcVar1)();
    return uVar9;
  }
  if (!bVar2) {
    _cexit();
  }
  __scrt_uninitialize_crt(CONCAT71((int7)((ulonglong)pIVar10 >> 8),1),'\0');
  return (ulonglong)uVar5;
}



===== entry @ 1400092b0 =====

void entry(void)

{
  __security_init_cookie();
  __scrt_common_main_seh();
  return;
}



===== __security_check_cookie @ 1400092e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== operator_new @ 140009304 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64,struct std::nothrow_t const & __ptr64) */

void * __cdecl operator_new(__uint64 param_1,nothrow_t *param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



===== __scrt_acquire_startup_lock @ 140009328 =====

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  void *pvVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  pvVar2 = (void *)CONCAT71(extraout_var,bVar1);
  if ((int)pvVar2 == 0) {
LAB_140009356:
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
      if (bVar1) goto LAB_140009356;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



===== __scrt_initialize_crt @ 140009368 =====

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_140019411 = 1;
  }
  __isa_available_init();
  cVar1 = __vcrt_initialize();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = __vcrt_initialize();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    __vcrt_initialize();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



===== __scrt_initialize_onexit_tables @ 1400093a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_140019410 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_1400193e0 = 0xffffffffffffffff;
      uRam00000001400193e8 = 0xffffffffffffffff;
      _DAT_1400193f0 = 0xffffffffffffffff;
      _DAT_1400193f8 = 0xffffffffffffffff;
      uRam0000000140019400 = 0xffffffffffffffff;
      _DAT_140019408 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _o__initialize_onexit_table(&DAT_1400193e0);
      if (((int)in_RAX != 0) ||
         (in_RAX = _o__initialize_onexit_table(&DAT_1400193f8), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_140019410 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== __scrt_is_nonwritable_in_current_image @ 14000943c =====

/* WARNING: Removing unreachable block (ram,0x0001400094c9) */
/* WARNING: Enum "SectionFlags": Some values do not have unique names */

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_140000208; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_140000370;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x140000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x140000000U < uVar1)) goto LAB_1400094b2;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_1400094b2:
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



===== __scrt_release_startup_lock @ 1400094dc =====

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



===== __scrt_uninitialize_crt @ 140009508 =====

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_140019411 == '\0') || (param_2 == '\0')) {
    __vcrt_initialize();
    __vcrt_initialize();
  }
  return 1;
}



===== _onexit @ 140009538 =====

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_1400193e0 == -1) {
    iVar1 = _o__crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_1400193e0);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



===== atexit @ 140009578 =====

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



===== operator_delete @ 140009598 =====

/* void __cdecl operator delete(void * __ptr64,unsigned __int64) */

void __cdecl operator_delete(void *param_1,__uint64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001400084b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CoTaskMemFree(param_1);
  return;
}



===== __security_init_cookie @ 1400095a4 =====

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



===== _get_startup_argv_mode @ 14000965c =====

undefined8 _get_startup_argv_mode(void)

{
  return 1;
}



===== _get_startup_commit_mode @ 140009668 =====

undefined8 _get_startup_commit_mode(void)

{
  return 0;
}



===== _get_startup_file_mode @ 140009674 =====

undefined8 _get_startup_file_mode(void)

{
  return 0x4000;
}



===== __scrt_initialize_type_info @ 140009680 =====

/* void __cdecl __scrt_initialize_type_info(void) */

void __cdecl __scrt_initialize_type_info(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&__type_info_root_node);
  return;
}



===== __vcrt_initialize @ 140009694 =====

undefined1 __vcrt_initialize(void)

{
  return 1;
}



===== _guard_check_icall @ 1400096a0 =====

void _guard_check_icall(void)

{
  return;
}



===== __scrt_initialize_default_local_stdio_options @ 1400096ac =====

void __scrt_initialize_default_local_stdio_options(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x24;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return;
}



===== __scrt_get_dyn_tls_init_callback @ 1400096d0 =====

undefined * __scrt_get_dyn_tls_init_callback(void)

{
  return &__dyn_tls_init_callback;
}



===== __scrt_get_dyn_tls_dtor_callback @ 1400096e0 =====

undefined * __scrt_get_dyn_tls_dtor_callback(void)

{
  return &__dyn_tls_dtor_callback;
}



===== __crt_debugger_hook @ 1400096f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __crt_debugger_hook(int param_1)

{
  ___scrt_debugger_hook_flag = 0;
  return;
}



===== __scrt_fastfail @ 140009700 =====

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
  *(undefined8 *)(puVar4 + -8) = 0x140009734;
  __crt_debugger_hook(3);
  *(undefined8 *)(puVar4 + -8) = 0x140009745;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x14000974f;
  RtlCaptureContext(local_4d8);
  local_res10 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x140009771;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    local_res18 = 0;
    local_res20 = 0;
    *(undefined8 **)(puVar4 + 0x30) = &local_res18;
    *(undefined8 **)(puVar4 + 0x28) = &local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x1400097c2;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = auStack_5c8 + 0x5d0;
  *(undefined8 *)(puVar4 + -8) = 0x1400097f4;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x140009816;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x140009833;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x14000983e;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x14000984f;
    __crt_debugger_hook(3);
  }
  return;
}



===== __scrt_get_show_window_mode @ 140009868 =====

WORD __scrt_get_show_window_mode(void)

{
  WORD WVar1;
  _STARTUPINFOW local_78;
  
  memset(&local_78,0,0x68);
  GetStartupInfoW(&local_78);
  WVar1 = 10;
  if (((byte)local_78.dwFlags & 1) != 0) {
    WVar1 = local_78.wShowWindow;
  }
  return WVar1;
}



===== __scrt_initialize_mta @ 1400098a8 =====

undefined8 __scrt_initialize_mta(void)

{
  return 0;
}



===== __scrt_is_managed_app @ 1400098b4 =====

ulonglong __scrt_is_managed_app(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || ((pHVar1 = (HMODULE)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71(2,piVar3[0x3e] != 0);
  }
  return uVar2;
}



===== __scrt_set_unhandled_exception_filter @ 14000990c =====

void __scrt_set_unhandled_exception_filter(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009913. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(__scrt_unhandled_exception_filter);
  return;
}



===== __scrt_unhandled_exception_filter @ 140009920 =====

undefined8 __scrt_unhandled_exception_filter(undefined8 *param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) {
    if ((piVar1[8] + 0xe66cfae0U < 3) || (piVar1[8] == 0x1994000)) {
      puVar3 = (undefined8 *)__current_exception();
      *puVar3 = piVar1;
      uVar4 = param_1[1];
      puVar3 = (undefined8 *)__current_exception_context();
      *puVar3 = uVar4;
      terminate();
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
  }
  return 0;
}



===== _RTC_Initialize @ 140009984 =====

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



===== _RTC_Terminate @ 1400099d0 =====

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



===== __raise_securityfailure @ 140009a18 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE hProcess;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  hProcess = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000140009a45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(hProcess,0xc0000409);
  return;
}



===== __report_gsfailure @ 140009a60 =====

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
  *(undefined8 *)(puVar3 + -8) = 0x140009a8b;
  capture_previous_context((PCONTEXT)&DAT_1400194e0);
  _DAT_140019450 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_140019578 = puVar3 + 0x40;
  _DAT_140019560 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_140019440 = 0xc0000409;
  _DAT_140019444 = 1;
  _DAT_140019458 = 1;
  DAT_140019460 = 2;
  *(undefined8 *)(puVar3 + 0x20) = __security_cookie;
  *(undefined8 *)(puVar3 + 0x28) = __security_cookie_complement;
  *(undefined8 *)(puVar3 + -8) = 0x140009b2d;
  DAT_1400195d8 = _DAT_140019450;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_140013118);
  return;
}



===== capture_previous_context @ 140009b38 =====

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



===== __isa_available_init @ 140009bc4 =====

/* WARNING: Removing unreachable block (ram,0x000140009c8e) */
/* WARNING: Removing unreachable block (ram,0x000140009bfe) */
/* WARNING: Removing unreachable block (ram,0x000140009bd7) */
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



===== __scrt_is_ucrt_dll_in_use @ 140009d78 =====

bool __scrt_is_ucrt_dll_in_use(void)

{
  return __scrt_ucrt_dll_is_in_use != 0;
}



===== _initterm @ 140009d96 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009d96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== _initterm_e @ 140009da2 =====

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009da2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}



===== _c_exit @ 140009dae =====

void __cdecl _c_exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009dae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _c_exit();
  return;
}



===== _register_thread_local_exe_atexit_callback @ 140009dba =====

void _register_thread_local_exe_atexit_callback(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009dba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_thread_local_exe_atexit_callback();
  return;
}



===== _o___p__commode @ 140009dc6 =====

void _o___p__commode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009dc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___p__commode();
  return;
}



===== __stdio_common_vswprintf @ 140009dd2 =====

void __stdio_common_vswprintf(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009dd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___stdio_common_vswprintf();
  return;
}



===== _cexit @ 140009dde =====

void _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009dde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__cexit();
  return;
}



===== _o__configthreadlocale @ 140009dea =====

void _o__configthreadlocale(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009dea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configthreadlocale();
  return;
}



===== _configure_wide_argv @ 140009df6 =====

void _configure_wide_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009df6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configure_wide_argv();
  return;
}



===== _o__crt_atexit @ 140009e02 =====

void _o__crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__crt_atexit();
  return;
}



===== _exit @ 140009e0e =====

void _exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__exit();
  return;
}



===== _get_wide_winmain_command_line @ 140009e1a =====

void _get_wide_winmain_command_line(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__get_wide_winmain_command_line();
  return;
}



===== _o__initialize_onexit_table @ 140009e26 =====

void _o__initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_onexit_table();
  return;
}



===== _initialize_wide_environment @ 140009e32 =====

void _initialize_wide_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_wide_environment();
  return;
}



===== _o__invalid_parameter_noinfo @ 140009e3e =====

void _o__invalid_parameter_noinfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__invalid_parameter_noinfo();
  return;
}



===== _o__purecall @ 140009e50 =====

void _o__purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__purecall();
  return;
}



===== _register_onexit_function @ 140009e5c =====

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__register_onexit_function();
  return;
}



===== _o__seh_filter_exe @ 140009e68 =====

void _o__seh_filter_exe(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__seh_filter_exe();
  return;
}



===== _o__set_app_type @ 140009e74 =====

void _o__set_app_type(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_app_type();
  return;
}



===== _set_fmode @ 140009e80 =====

void _set_fmode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_fmode();
  return;
}



===== _set_new_mode @ 140009e8c =====

void _set_new_mode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_new_mode();
  return;
}



===== exit @ 140009e98 =====

void exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_exit();
  return;
}



===== terminate @ 140009ea4 =====

void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009ea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_terminate();
  return;
}



===== __C_specific_handler @ 140009eb0 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140009eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __current_exception @ 140009ec8 =====

void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009ec8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}



===== __current_exception_context @ 140009ed4 =====

void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009ed4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}



===== memset @ 140009ee0 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140009ee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== _vsnwprintf @ 140009eec =====

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



===== __tailMerge_api_ms_win_core_com_l1_1_0_dll @ 140009f4e =====

void __tailMerge_api_ms_win_core_com_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_XMM1_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016e20,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140009fc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_XMM1_Qa,param_3,param_4);
  return;
}



===== DelayLoad_CoAddRefServerProcess @ 140009fcd =====

void DelayLoad_CoAddRefServerProcess
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_power_setting_l1_1_0_dll @ 140009fd9 =====

void __tailMerge_api_ms_win_power_setting_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_XMM1_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016e40,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000a050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_XMM1_Qa,param_3,param_4);
  return;
}



===== DelayLoad_PowerSettingRegisterNotification @ 14000a058 =====

void DelayLoad_PowerSettingRegisterNotification
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_power_setting_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoReleaseServerProcess @ 14000a06a =====

void DelayLoad_CoReleaseServerProcess
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_core_winrt_error_l1_1_0_dll @ 14000a076 =====

void __tailMerge_api_ms_win_core_winrt_error_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 in_XMM1_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016e60,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000a0ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_XMM1_Qa,in_R8,in_R9);
  return;
}



===== DelayLoad_RoSetErrorReportingFlags @ 14000a0f5 =====

void DelayLoad_RoSetErrorReportingFlags
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_error_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll @ 14000a101 =====

void __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016e80,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000a178. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,in_R9);
  return;
}



===== DelayLoad_WindowsCreateString @ 14000a180 =====

void DelayLoad_WindowsCreateString
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoTaskMemAlloc @ 14000a192 =====

void DelayLoad_CoTaskMemAlloc
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_rpcrt4_dll @ 14000a19e =====

void __tailMerge_rpcrt4_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 in_XMM0_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016ea0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000a215. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_XMM0_Qa,param_2,in_R8,in_R9);
  return;
}



===== DelayLoad_UuidEqual @ 14000a21d =====

void DelayLoad_UuidEqual(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoCreateInstance @ 14000a22f =====

void DelayLoad_CoCreateInstance
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoCreateFreeThreadedMarshaler @ 14000a241 =====

void DelayLoad_CoCreateFreeThreadedMarshaler
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoFreeUnusedLibrariesEx @ 14000a253 =====

void DelayLoad_CoFreeUnusedLibrariesEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_WindowsCreateStringReference @ 14000a265 =====

void DelayLoad_WindowsCreateStringReference
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoTaskMemFree @ 14000a277 =====

void DelayLoad_CoTaskMemFree
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoImpersonateClient @ 14000a289 =====

void DelayLoad_CoImpersonateClient
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_core_winrt_l1_1_0_dll @ 14000a295 =====

void __tailMerge_api_ms_win_core_winrt_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 in_XMM0_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016ec0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000a30c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_XMM0_Qa,param_2,in_R8,in_R9);
  return;
}



===== DelayLoad_RoGetActivationFactory @ 14000a314 =====

void DelayLoad_RoGetActivationFactory
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoRegisterClassObject @ 14000a326 =====

void DelayLoad_CoRegisterClassObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoGetCallContext @ 14000a338 =====

void DelayLoad_CoGetCallContext
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RoOriginateErrorW @ 14000a34a =====

void DelayLoad_RoOriginateErrorW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_error_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoResumeClassObjects @ 14000a35c =====

void DelayLoad_CoResumeClassObjects
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoDecrementMTAUsage @ 14000a36e =====

void DelayLoad_CoDecrementMTAUsage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoRevertToSelf @ 14000a380 =====

void DelayLoad_CoRevertToSelf
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoInitializeSecurity @ 14000a392 =====

void DelayLoad_CoInitializeSecurity
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RoGetErrorReportingFlags @ 14000a3a4 =====

void DelayLoad_RoGetErrorReportingFlags
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_error_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoIncrementMTAUsage @ 14000a3b6 =====

void DelayLoad_CoIncrementMTAUsage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_WindowsDeleteString @ 14000a3c8 =====

void DelayLoad_WindowsDeleteString
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RoOriginateError @ 14000a3da =====

void DelayLoad_RoOriginateError
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_error_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_WindowsGetStringRawBuffer @ 14000a3ec =====

void DelayLoad_WindowsGetStringRawBuffer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PowerSettingUnregisterNotification @ 14000a3fe =====

void DelayLoad_PowerSettingUnregisterNotification
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_power_setting_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoInitializeEx @ 14000a410 =====

void DelayLoad_CoInitializeEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoRevokeClassObject @ 14000a422 =====

void DelayLoad_CoRevokeClassObject
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_combase_dll @ 14000a42e =====

void __tailMerge_combase_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016ee0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000a4a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,in_R9);
  return;
}



===== DelayLoad_Ordinal_167 @ 14000a4ad =====

void DelayLoad_Ordinal_167
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_combase_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_99 @ 14000a4bf =====

void DelayLoad_Ordinal_99
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_combase_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_69 @ 14000a4d1 =====

void DelayLoad_Ordinal_69
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_combase_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_153 @ 14000a4e3 =====

void DelayLoad_Ordinal_153
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_combase_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_security_lsalookup_l1_1_0_dll @ 14000a4ef =====

void __tailMerge_api_ms_win_security_lsalookup_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 in_XMM1_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016f00,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000a566. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_XMM1_Qa,in_R8,in_R9);
  return;
}



===== DelayLoad_LsaLookupClose @ 14000a56e =====

void DelayLoad_LsaLookupClose
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_security_lsalookup_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_LsaLookupGetDomainInfo @ 14000a580 =====

void DelayLoad_LsaLookupGetDomainInfo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_security_lsalookup_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_appmodel_runtime_l1_1_1_dll @ 14000a58c =====

void __tailMerge_api_ms_win_appmodel_runtime_l1_1_1_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140016f20,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000a603. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,in_R9);
  return;
}



===== DelayLoad_GetApplicationUserModelIdFromToken @ 14000a60b =====

void DelayLoad_GetApplicationUserModelIdFromToken
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_appmodel_runtime_l1_1_1_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_LsaLookupOpenLocalPolicy @ 14000a61d =====

void DelayLoad_LsaLookupOpenLocalPolicy
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_security_lsalookup_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_LsaLookupFreeMemory @ 14000a62f =====

void DelayLoad_LsaLookupFreeMemory
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_security_lsalookup_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsRemoteWinRTActivationPresent @ 14000a644 =====

undefined1 IsRemoteWinRTActivationPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_140019a00 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_140019a00 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_140013128), -1 < iVar2)) {
      DAT_140019a00 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== ApiSetQueryApiSetPresence @ 14000a698 =====

void ApiSetQueryApiSetPresence(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000a698. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ApiSetQueryApiSetPresence();
  return;
}



===== __scrt_initialize_thread_safe_statics @ 14000a6b0 =====

undefined8 __scrt_initialize_thread_safe_statics(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  FARPROC pFVar2;
  undefined8 uVar3;
  
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_140019a18,4000);
  hModule = GetModuleHandleW(L"api-ms-win-core-synch-l1-2-0.dll");
  if (hModule == (HMODULE)0x0) {
    hModule = GetModuleHandleW(L"kernel32.dll");
    if (hModule == (HMODULE)0x0) goto LAB_14000a775;
  }
  pFVar1 = GetProcAddress(hModule,"SleepConditionVariableCS");
  pFVar2 = GetProcAddress(hModule,"WakeAllConditionVariable");
  if ((pFVar1 == (FARPROC)0x0) || (pFVar2 == (FARPROC)0x0)) {
    DAT_140019a10 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    if (DAT_140019a10 == (HANDLE)0x0) goto LAB_14000a775;
  }
  else {
    DAT_140019a40 = pFVar1;
    DAT_140019a48 = pFVar2;
  }
  uVar3 = __scrt_initialize_onexit_tables(0);
  if ((char)uVar3 != '\0') {
    atexit(__scrt_uninitialize_thread_safe_statics);
    return 0;
  }
LAB_14000a775:
                    /* WARNING: Subroutine does not return */
  __scrt_fastfail(7);
}



===== __scrt_uninitialize_thread_safe_statics @ 14000a790 =====

void __scrt_uninitialize_thread_safe_statics(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_140019a18);
  if (DAT_140019a10 != (HANDLE)0x0) {
    CloseHandle(DAT_140019a10);
  }
  return;
}



===== _Init_thread_footer @ 14000a7c0 =====

void _Init_thread_footer(int *param_1)

{
  ulonglong uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_140019a18);
  uVar1 = (ulonglong)_tls_index;
  _Init_global_epoch = _Init_global_epoch + 1;
  *param_1 = _Init_global_epoch;
  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = _Init_global_epoch;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_140019a18);
  _Init_thread_notify();
  return;
}



===== _Init_thread_header @ 14000a828 =====

void _Init_thread_header(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_140019a18);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_14000a877:
                    /* WARNING: Could not recover jumptable at 0x00014000a883. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_140019a18);
      return;
    }
    if (*param_1 != -1) {
      *(undefined4 *)
       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           _Init_global_epoch;
      goto LAB_14000a877;
    }
    _Init_thread_wait_v2();
  } while( true );
}



===== _Init_thread_notify @ 14000a890 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _Init_thread_notify(void)

{
  if (DAT_140019a48 == (code *)0x0) {
    SetEvent(DAT_140019a10);
                    /* WARNING: Could not recover jumptable at 0x00014000a8c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ResetEvent(DAT_140019a10);
    return;
  }
  (*DAT_140019a48)(&DAT_140019a08);
  return;
}



===== _Init_thread_wait_v2 @ 14000a8d8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _Init_thread_wait_v2(void)

{
  if (DAT_140019a40 == (code *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_140019a18);
    WaitForSingleObjectEx(DAT_140019a10,100,0);
                    /* WARNING: Could not recover jumptable at 0x00014000a92f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_140019a18);
    return;
  }
  (*DAT_140019a40)(&DAT_140019a08,&DAT_140019a18,0xffffffff);
  return;
}



===== <lambda_invoker_cdecl> @ 14000a940 =====

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



===== unique_ptr<void,wil::process_heap_deleter><1,void> @ 14000a9b0 =====

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



===== operator==<void,wil::process_heap_deleter> @ 14000a9c0 =====

/* bool __cdecl wistd::operator==<void,struct wil::process_heap_deleter>(class
   wistd::unique_ptr<void,struct wil::process_heap_deleter> const & __ptr64,std::nullptr_t) */

bool __cdecl wistd::operator==<void,wil::process_heap_deleter>(longlong *param_1)

{
  return *param_1 == 0;
}



===== AsIID<Microsoft::WRL::Details::RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>_> @ 14000a9d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* protected: static long __cdecl Microsoft::WRL::Details::RuntimeClassBaseT<2>::AsIID<class
   Microsoft::WRL::Details::RuntimeClassImpl<struct
   Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> > >(class
   Microsoft::WRL::Details::RuntimeClassImpl<struct
   Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> > * __ptr64,struct _GUID const & __ptr64,void * __ptr64 *
   __ptr64) */

long __cdecl
Microsoft::WRL::Details::RuntimeClassBaseT<2>::
AsIID<Microsoft::WRL::Details::RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>_>
          (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
           *param_1,_GUID *param_2,void **param_3)

{
  int iVar1;
  
  *param_3 = (void *)0x0;
  iVar1 = InlineIsEqualGUID(param_2,(_GUID *)&_GUID_00000000_0000_0000_c000_000000000046);
  if (iVar1 != 0) {
    *param_3 = param_1;
    (**(code **)(*(longlong *)param_1 + 8))(param_1);
    return 0;
  }
  iVar1 = InlineIsEqualGUID(param_2,(_GUID *)&_GUID_eb9d0454_25db_5620_98b8_be4c5d0dbc67);
  if (iVar1 == 0) {
    param_1 = param_1 + 8;
    iVar1 = InlineIsEqualGUID(param_2,(_GUID *)&_GUID_94ea2b94_e9cc_49e0_c0ff_ee64ca8f5b90);
    if ((iVar1 == 0) &&
       (iVar1 = InlineIsEqualGUID(param_2,(_GUID *)&_GUID_00000003_0000_0000_c000_000000000046),
       iVar1 == 0)) {
      iVar1 = -0x7fffbffe;
      param_1 = (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
                 *)0x0;
    }
    else {
      *param_3 = param_1;
      iVar1 = 0;
    }
    if (iVar1 == -0x7fffbffe) {
      return -0x7fffbffe;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    *param_3 = param_1;
    iVar1 = 0;
  }
  (**(code **)(*(longlong *)param_1 + 8))(param_1);
  return iVar1;
}



===== EnsureCoalescedTimer<wil::details::FeatureStateManager> @ 14000aa80 =====

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



===== EnsureCoalescedTimerSRUM<wil::details::FeatureStateManager> @ 14000ab04 =====

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



===== Make<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>_> @ 14000ab88 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* class Microsoft::WRL::ComPtr<struct Microsoft::WRL::Details::DelegateArgTraits<long (__cdecl
   Windows::Foundation::ITypedEventHandler_impl<struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserWatcher * __ptr64,struct
   Windows::System::IUserWatcher * __ptr64>,struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserChangedEventArgs *
   __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64> >::*)(struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64)
   __ptr64>::DelegateInvokeHelper<struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase>,class <lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64>
   > __cdecl Microsoft::WRL::Details::Make<struct Microsoft::WRL::Details::DelegateArgTraits<long
   (__cdecl Windows::Foundation::ITypedEventHandler_impl<struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserWatcher * __ptr64,struct
   Windows::System::IUserWatcher * __ptr64>,struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserChangedEventArgs *
   __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64> >::*)(struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64)
   __ptr64>::DelegateInvokeHelper<struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase>,class <lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs *
   __ptr64>,class <lambda_ff67e1dbbd64ec80e0b69245dd48b71a> >(class
   <lambda_ff67e1dbbd64ec80e0b69245dd48b71a> && __ptr64) */

<lambda_ff67e1dbbd64ec80e0b69245dd48b71a> * __cdecl
Microsoft::WRL::Details::
Make<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,_1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>_>
          (<lambda_ff67e1dbbd64ec80e0b69245dd48b71a> *param_1)

{
  FtmBase *this;
  ModuleBase *pMVar1;
  undefined8 *puVar2;
  undefined8 *local_res10;
  
  *(undefined8 *)param_1 = 0;
  puVar2 = operator_new(0x48,&std::nothrow);
  local_res10 = puVar2;
  if (puVar2 != (undefined8 *)0x0) {
    this = (FtmBase *)(puVar2 + 1);
    *puVar2 = &Windows::Foundation::
               ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>
               ::_vftable_;
    FtmBase::FtmBase(this);
    pMVar1 = ModuleBase::module_;
    *puVar2 = &RuntimeClass<Microsoft::WRL::RuntimeClassFlags<2>,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
               ::
               _vftable__for__Windows__Foundation__ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>__
    ;
    *(undefined ***)this =
         &DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>
          ::
          DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>
          ::
          _vftable__for__Microsoft__WRL__Details__ImplementsHelper<Microsoft::WRL::RuntimeClassFlags<2>,1,Microsoft::WRL::Details::ImplementsMarker<Microsoft::WRL::FtmBase>_>__
    ;
    *(undefined4 *)((longlong)puVar2 + 0x3c) = 1;
    if (pMVar1 != (ModuleBase *)0x0) {
      (**(code **)(*(longlong *)pMVar1 + 8))();
    }
    *puVar2 = &DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>
               ::
               DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>
               ::
               _vftable__for__Windows__Foundation__ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>__
    ;
    *(undefined ***)this =
         &DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>
          ::
          DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>
          ::
          _vftable__for__Microsoft__WRL__Details__ImplementsHelper<Microsoft::WRL::RuntimeClassFlags<2>,1,Microsoft::WRL::Details::ImplementsMarker<Microsoft::WRL::FtmBase>_>__
    ;
    if (*(RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
          **)param_1 !=
        (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
         *)0x0) {
      RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
      ::Release(*(RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
                  **)param_1);
    }
    local_res10 = (undefined8 *)0x0;
    *(undefined8 **)param_1 = puVar2;
  }
  MakeAllocator<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>
  ::
  ~MakeAllocator<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,_1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>
            ((MakeAllocator<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,_1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>
              *)&local_res10);
  return param_1;
}



===== ReportFailure_Base<2,0> @ 14000ac58 =====

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



===== ReportFailure_Base<3,0> @ 14000ac9c =====

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



===== ReportFailure_GetLastError<3> @ 14000acc8 =====

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
                              "onecore\\internal\\sdk\\inc\\wil\\opensource\\wil\\resource.h",
                              param_4,in_stack_ffffffffffffffb8,param_6);
  if (0 < (int)local_18) {
    local_18 = local_18 & 0xffff | 0x80070000;
  }
  local_14 = HrToNtStatus(local_18);
  local_10 = 0;
  ReportFailure_Base<3,0>
            (param_1,param_2,"onecore\\internal\\sdk\\inc\\wil\\opensource\\wil\\resource.h",param_4
             ,in_stack_ffffffffffffffb8,param_6,(ResultStatus *)&local_18,in_stack_ffffffffffffffd0,
             in_stack_ffffffffffffffd8);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== ReportFailure_Hr<2> @ 14000ad3c =====

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



===== ReportFailure_Hr<3> @ 14000ada4 =====

/* void __cdecl wil::details::ReportFailure_Hr<3>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  code *pcVar1;
  char *in_stack_ffffffffffffffb8;
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  undefined4 local_18;
  long local_14;
  undefined4 local_10;
  
  local_18 = 0x8000ffff;
  local_14 = HrToNtStatus(-0x7fff0001);
  local_10 = 0;
  ReportFailure_Base<3,0>
            (param_1,param_2,param_3,param_3,in_stack_ffffffffffffffb8,param_6,
             (ResultStatus *)&local_18,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ReportFailure_NoReturn<3> @ 14000adf4 =====

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
  
  uStack_20 = 0x14000ae06;
  memset(local_14b8,0,0x98);
  LogFailure(param_1,param_2,param_3,(char *)0x0,(char *)0x0,param_6,3,param_7,(ushort *)0x0,
             (bool)in_stack_ffffffffffffeb10,local_1018,in_stack_ffffffffffffeb20,local_1418,
             in_stack_ffffffffffffeb30,local_14b8);
                    /* WARNING: Subroutine does not return */
  WilFailFast(local_14b8);
}



===== ReportFailure_NtStatus<1> @ 14000aea0 =====

/* long __cdecl wil::details::ReportFailure_NtStatus<1>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

long __cdecl
wil::details::ReportFailure_NtStatus<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  long lVar1;
  char *in_stack_ffffffffffffffb8;
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  long local_18;
  long local_14;
  undefined4 local_10;
  
  lVar1 = NtStatusToHr(param_7);
  local_14 = param_7;
  local_10 = 1;
  local_18 = lVar1;
  ReportFailure_Base<1,0>
            (param_1,param_2,"onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp",param_4,
             in_stack_ffffffffffffffb8,param_6,(ResultStatus *)&local_18,in_stack_ffffffffffffffd0,
             in_stack_ffffffffffffffd8);
  return lVar1;
}



===== ReportFailure_Return<2> @ 14000af20 =====

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
  
  uStack_48 = 0x14000af37;
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



===== WriteResultString<char_const*___ptr64> @ 14000b03c =====

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



===== FtmBase @ 14000b0b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl Microsoft::WRL::FtmBase::FtmBase(void) __ptr64 */

FtmBase * __thiscall Microsoft::WRL::FtmBase::FtmBase(FtmBase *this)

{
  ComPtr<Windows::System::IUserWatcher> *this_00;
  _func_5156 *p_Var1;
  LPUNKNOWN This;
  HRESULT HVar2;
  LPUNKNOWN local_res8;
  
  local_res8 = (IUnknown *)0x0;
  this_00 = (ComPtr<Windows::System::IUserWatcher> *)(this + 0x18);
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)this_00 = 0;
  ComPtr<Windows::System::IUserWatcher>::InternalRelease
            ((ComPtr<Windows::System::IUserWatcher> *)&local_res8);
  HVar2 = CoCreateFreeThreadedMarshaler((LPUNKNOWN)0x0,&local_res8);
  This = local_res8;
  if (-1 < HVar2) {
    p_Var1 = local_res8->lpVtbl->QueryInterface;
    ComPtr<Windows::System::IUserWatcher>::InternalRelease(this_00);
    (*p_Var1)(This,(IID *)&_GUID_00000003_0000_0000_c000_000000000046,(void **)this_00);
  }
  ComPtr<Windows::System::IUserWatcher>::InternalRelease
            ((ComPtr<Windows::System::IUserWatcher> *)&local_res8);
  return this;
}



===== last_error_context @ 14000b154 =====

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



===== ~MakeAllocator<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_> @ 14000b180 =====

/* public: __cdecl Microsoft::WRL::Details::MakeAllocator<struct
   Microsoft::WRL::Details::DelegateArgTraits<long (__cdecl
   Windows::Foundation::ITypedEventHandler_impl<struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserWatcher * __ptr64,struct
   Windows::System::IUserWatcher * __ptr64>,struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserChangedEventArgs *
   __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64> >::*)(struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64)
   __ptr64>::DelegateInvokeHelper<struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase>,class <lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64>
   >::~MakeAllocator<struct Microsoft::WRL::Details::DelegateArgTraits<long (__cdecl
   Windows::Foundation::ITypedEventHandler_impl<struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserWatcher * __ptr64,struct
   Windows::System::IUserWatcher * __ptr64>,struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserChangedEventArgs *
   __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64> >::*)(struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64)
   __ptr64>::DelegateInvokeHelper<struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase>,class <lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64>
   >(void) __ptr64 */

void __thiscall
Microsoft::WRL::Details::
MakeAllocator<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>
::
~MakeAllocator<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,_1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>
          (MakeAllocator<Microsoft::WRL::Details::DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>::DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,_1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>
           *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this,1);
  }
  return;
}



===== ~ProcessLocalStorageData<wil::details_abi::ProcessLocalData> @ 14000b1a4 =====

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



===== ~ProcessLocalStorageData<wil::details_abi::FeatureStateData> @ 14000b1d4 =====

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



===== ~ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> @ 14000b204 =====

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
  HANDLE hHeap;
  LPVOID lpMem;
  
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



===== ~ThreadLocalStorage<wil::details_abi::ThreadLocalData> @ 14000b280 =====

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



===== ~unique_storage<wil::details::resource_policy<_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupFreeMemory(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,0,std::nullptr_t>_> @ 14000b304 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _POLICY_ACCOUNT_DOMAIN_INFO * __ptr64,long (__cdecl*)(void * __ptr64),&long __cdecl
   LsaLookupFreeMemory(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct
   _POLICY_ACCOUNT_DOMAIN_INFO * __ptr64,struct _POLICY_ACCOUNT_DOMAIN_INFO *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<struct
   _POLICY_ACCOUNT_DOMAIN_INFO * __ptr64,long (__cdecl*)(void * __ptr64),&long __cdecl
   LsaLookupFreeMemory(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct
   _POLICY_ACCOUNT_DOMAIN_INFO * __ptr64,struct _POLICY_ACCOUNT_DOMAIN_INFO *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupFreeMemory(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupFreeMemory(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupFreeMemory(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(PVOID *)this != (PVOID)0x0) {
    LsaLookupFreeMemory(*(PVOID *)this);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_> @ 14000b328 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,long (__cdecl*)(void * __ptr64),&long __cdecl LsaLookupClose(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<void * __ptr64,long (__cdecl*)(void *
   __ptr64),&long __cdecl LsaLookupClose(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(LSA_LOOKUP_HANDLE *)this != (LSA_LOOKUP_HANDLE)0x0) {
    LsaLookupClose(*(LSA_LOOKUP_HANDLE *)this);
  }
  return;
}



===== ~FeatureStateData @ 14000b34c =====

/* public: __cdecl wil::details_abi::FeatureStateData::~FeatureStateData(void) __ptr64 */

void __thiscall wil::details_abi::FeatureStateData::~FeatureStateData(FeatureStateData *this)

{
  ProcessShutdown(this);
  SubscriptionList::~SubscriptionList((SubscriptionList *)(this + 200));
  UsageIndexes::~UsageIndexes((UsageIndexes *)(this + 8));
  return;
}



===== ~SemaphoreValue @ 14000b37c =====

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



===== ~last_error_context @ 14000b3a4 =====

/* public: __cdecl wil::last_error_context::~last_error_context(void) __ptr64 */

void __thiscall wil::last_error_context::~last_error_context(last_error_context *this)

{
  if (*this == (last_error_context)0x0) {
    ::SetLastError(*(DWORD *)(this + 4));
  }
  return;
}



===== `vector_deleting_destructor' @ 14000b3d0 =====

/* public: virtual void * __ptr64 __cdecl Microsoft::WRL::Details::DelegateArgTraits<long (__cdecl
   Windows::Foundation::ITypedEventHandler_impl<struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserWatcher * __ptr64,struct
   Windows::System::IUserWatcher * __ptr64>,struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserChangedEventArgs *
   __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64> >::*)(struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64)
   __ptr64>::DelegateInvokeHelper<struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase>,class <lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs *
   __ptr64>::`vector deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
Microsoft::WRL::Details::
DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>
::
DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>
::_vector_deleting_destructor_
          (DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,_1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>
           *this,uint param_1)

{
  *(undefined4 *)(this + 0x3c) = 0xc0000001;
  ComPtr<Windows::System::IUserWatcher>::InternalRelease
            ((ComPtr<Windows::System::IUserWatcher> *)(this + 0x20));
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x48);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000b420 =====

/* public: virtual void * __ptr64 __cdecl Microsoft::WRL::RuntimeClass<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> >::`scalar deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
Microsoft::WRL::
RuntimeClass<Microsoft::WRL::RuntimeClassFlags<2>,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
::_scalar_deleting_destructor_
          (RuntimeClass<Microsoft::WRL::RuntimeClassFlags<2>,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
           *this,uint param_1)

{
  *(undefined4 *)(this + 0x3c) = 0xc0000001;
  ComPtr<Windows::System::IUserWatcher>::InternalRelease
            ((ComPtr<Windows::System::IUserWatcher> *)(this + 0x20));
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x40);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000b470 =====

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
    operator_delete(this,8);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000b4b0 =====

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
    operator_delete(this,0x20);
  }
  return this;
}



===== Acquire @ 14000b4e4 =====

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
  ulong uVar5;
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
  uVar5 = 0;
  pvVar3 = CreateMutexExW((LPSECURITY_ATTRIBUTES)0x0,local_228,0,0x1f0001);
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *)&local_248,pvVar3);
  if (local_248 == 0) {
    lVar2 = details::GetLastErrorFailHr();
    goto LAB_14000b5fe;
  }
  mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
  ::acquire((mutex_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
             *)&local_248,(ulong *)local_240,uVar5,iVar6);
  local_238[0] = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
  lVar2 = SemaphoreValue::TryGetPointer((ushort *)local_228,local_238);
  if (lVar2 < 0) {
    uVar4 = 299;
LAB_14000b5ba:
    details::in1diag3::Return_Hr(unaff_retaddr,uVar4,"wil",lVar2);
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
        goto LAB_14000b5ba;
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
LAB_14000b5fe:
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)&local_248);
  return lVar2;
}



===== AddRef @ 14000b660 =====

/* public: virtual unsigned long __cdecl Microsoft::WRL::Details::RuntimeClassImpl<struct
   Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> >::AddRef(void) __ptr64 */

ulong __thiscall
Microsoft::WRL::Details::
RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
::AddRef(RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
         *this)

{
  int iVar1;
  bool bVar2;
  
  do {
    iVar1 = *(int *)(this + 0x3c);
    if (iVar1 == 0x7fffffff) {
      return 0x7fffffff;
    }
    LOCK();
    bVar2 = iVar1 == *(int *)(this + 0x3c);
    if (bVar2) {
      *(int *)(this + 0x3c) = iVar1 + 1;
    }
    UNLOCK();
  } while (!bVar2);
  return iVar1 + 1;
}



===== AddRef`adjustor{8}' @ 14000b690 =====

/* [thunk]:public: virtual unsigned long __cdecl Microsoft::WRL::Details::RuntimeClassImpl<struct
   Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> >::AddRef`adjustor{8}' (void) __ptr64 */

ulong __thiscall
Microsoft::WRL::Details::
RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
::AddRef_adjustor_8__
          (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
           *this)

{
  ulong uVar1;
  
  uVar1 = AddRef(this + -8);
  return uVar1;
}



===== AddRef`adjustor{8}' @ 14000b6a0 =====

/* [thunk]:public: virtual unsigned long __cdecl
   CRuntimeBrokerLifetimeExtensionFactory::AddRef`adjustor{8}' (void) __ptr64 */

ulong __thiscall
CRuntimeBrokerLifetimeExtensionFactory::AddRef_adjustor_8__
          (CRuntimeBrokerLifetimeExtensionFactory *this)

{
  ulong uVar1;
  
  uVar1 = AddRef(this + -8);
  return uVar1;
}



===== CheckClient @ 14000b6b0 =====

/* private: long __cdecl CRuntimeBroker::CheckClient(bool * __ptr64) __ptr64 */

long __thiscall CRuntimeBroker::CheckClient(CRuntimeBroker *this,bool *param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  CRuntimeBroker *this_00;
  HANDLE local_res8;
  
  local_res8 = (void *)0x0;
  *param_1 = false;
  DVar1 = CoImpersonateClient();
  if (-1 < (int)DVar1) {
    this_00 = GetCurrentThread();
    BVar2 = OpenThreadToken(this_00,8,1,&local_res8);
    if (BVar2 == 0) {
      DVar1 = GetLastError();
      if (0 < (int)DVar1) {
        DVar1 = DVar1 & 0xffff | 0x80070000;
      }
    }
    CoRevertToSelf();
    if (-1 < (int)DVar1) {
      DVar1 = CheckClientPrivilege(this_00,param_1,local_res8);
      if ((-1 < (int)DVar1) && (*param_1 == false)) {
        DVar1 = CheckClientAccess(this_00,param_1,local_res8);
      }
    }
  }
  if (local_res8 != (HANDLE)0x0) {
    CloseHandle(local_res8);
  }
  return DVar1;
}



===== CheckClientAccess @ 14000b788 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl CRuntimeBroker::CheckClientAccess(bool * __ptr64,void * __ptr64) __ptr64 */

long __thiscall CRuntimeBroker::CheckClientAccess(CRuntimeBroker *this,bool *param_1,void *param_2)

{
  DWORD nLength;
  BOOL BVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  LPVOID pSecurityDescriptor;
  undefined1 auStackY_b8 [32];
  DWORD local_78;
  DWORD local_74;
  BOOL local_70 [4];
  GENERIC_MAPPING local_60;
  _PRIVILEGE_SET local_50;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70[2] = 0x14;
  local_74 = 0x1fffff;
  DVar2 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_60.GenericRead = 0;
  local_60.GenericWrite = 0;
  local_60.GenericExecute = 0;
  local_60.GenericAll = 0;
  local_50.Privilege[0].Attributes = 0;
  local_50.PrivilegeCount = 0;
  local_50.Control = 0;
  local_50.Privilege[0].Luid.LowPart = 0;
  local_50.Privilege[0].Luid.HighPart = 0;
  MapGenericMask(&local_74,&local_60);
  local_78 = 0;
  *param_1 = false;
  pvVar3 = GetCurrentProcess();
  GetKernelObjectSecurity(pvVar3,7,(PSECURITY_DESCRIPTOR)0x0,0,&local_78);
  pSecurityDescriptor = CoTaskMemAlloc((ulonglong)local_78);
  nLength = local_78;
  if (pSecurityDescriptor == (LPVOID)0x0) {
    RoOriginateError(0x8007000e,0);
    return -0x7ff8fff2;
  }
  pvVar3 = GetCurrentProcess();
  BVar1 = GetKernelObjectSecurity(pvVar3,7,pSecurityDescriptor,nLength,&local_78);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) goto LAB_14000b8f5;
  }
  BVar1 = AccessCheck(pSecurityDescriptor,param_2,local_74,&local_60,&local_50,
                      (LPDWORD)(local_70 + 2),(LPDWORD)(local_70 + 1),local_70);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    *param_1 = local_70[0] != 0;
  }
LAB_14000b8f5:
  CoTaskMemFree(pSecurityDescriptor);
  return DVar2;
}



===== CheckClientPrivilege @ 14000b948 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl CRuntimeBroker::CheckClientPrivilege(bool * __ptr64,void * __ptr64) __ptr64
    */

long __thiscall
CRuntimeBroker::CheckClientPrivilege(CRuntimeBroker *this,bool *param_1,void *param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined1 auStack_58 [32];
  BOOL local_38 [2];
  undefined8 local_30;
  _PRIVILEGE_SET local_28;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  DVar2 = 0;
  local_30 = 0x14;
  *param_1 = false;
  local_28.Privilege[0].Attributes = 0;
  local_38[0] = 0;
  local_28.PrivilegeCount = 1;
  local_28.Control = 1;
  local_28.Privilege[0].Luid.LowPart = 0x14;
  local_28.Privilege[0].Luid.HighPart = 0;
  BVar1 = PrivilegeCheck(param_2,&local_28,local_38);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    *param_1 = local_38[0] != 0;
  }
  return DVar2;
}



===== Clear @ 14000b9f4 =====

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



===== CreateFromValueInternal @ 14000bab4 =====

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
  int iVar4;
  uint uVar5;
  void *unaff_retaddr;
  undefined1 auStackY_278 [32];
  ulong in_stack_fffffffffffffda8;
  _SECURITY_ATTRIBUTES *in_stack_fffffffffffffdb0;
  bool *in_stack_fffffffffffffdb8;
  ushort local_238 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_278;
  if ((param_3 & 0xc000000000000000) != 0) {
                    /* WARNING: Subroutine does not return */
    details::in1diag3::_FailFastImmediate_Unexpected();
  }
  StringCchCopyW(local_238,(__uint64)param_1,param_1);
  StringCchCatW(local_238,(__uint64)param_1,(ushort *)L"_p0");
  uVar3 = (uint)param_3 & 0x7fffffff;
  _Var2 = (__uint64)uVar3;
  uVar5 = 1;
  if ((param_3 & 0x7fffffff) != 0) {
    uVar5 = uVar3;
  }
  lVar1 = semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
          ::create((semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
                    *)this,uVar3,uVar5,local_238,in_stack_fffffffffffffda8,in_stack_fffffffffffffdb0
                   ,in_stack_fffffffffffffdb8);
  if (lVar1 < 0) {
    uVar5 = 0x88;
  }
  else {
    StringCchCatW(local_238,_Var2,(ushort *)L"h");
    iVar4 = (int)(param_3 >> 0x1f);
    lVar1 = 1;
    if (iVar4 != 0) {
      lVar1 = iVar4;
    }
    lVar1 = semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
            ::create((semaphore_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>,wil::err_returncode_policy>
                      *)(this + 8),iVar4,lVar1,local_238,in_stack_fffffffffffffda8,
                     in_stack_fffffffffffffdb0,in_stack_fffffffffffffdb8);
    if (-1 < lVar1) {
      return 0;
    }
    uVar5 = 0x8d;
  }
  details::in1diag3::Return_Hr(unaff_retaddr,uVar5,"wil",lVar1);
  return lVar1;
}



===== DebugBreak @ 14000bbc0 =====

/* void __cdecl wil::details::DebugBreak(void) */

void __cdecl wil::details::DebugBreak(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000bbc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ::DebugBreak();
  return;
}



===== DebuggerAddRef @ 14000bbe0 =====

/* public: virtual long __cdecl CRuntimeBroker::DebuggerAddRef(void) __ptr64 */

long __thiscall CRuntimeBroker::DebuggerAddRef(CRuntimeBroker *this)

{
  long lVar1;
  bool local_res10 [24];
  
  local_res10[0] = false;
  lVar1 = CheckClient(this,local_res10);
  if (-1 < lVar1) {
    if (local_res10[0] == false) {
      lVar1 = -0x7ff8fffb;
    }
    else {
      LOCK();
      s_cRefDebugger = s_cRefDebugger + 1;
      UNLOCK();
    }
  }
  return lVar1;
}



===== DebuggerRelease @ 14000bc20 =====

/* public: virtual long __cdecl CRuntimeBroker::DebuggerRelease(void) __ptr64 */

long __thiscall CRuntimeBroker::DebuggerRelease(CRuntimeBroker *this)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  bool local_res10 [24];
  
  local_res10[0] = false;
  lVar2 = CheckClient(this,local_res10);
  if (-1 < lVar2) {
    if (local_res10[0] == false) {
      lVar2 = -0x7ff8fffb;
    }
    else {
      LOCK();
      uVar1 = s_cRefDebugger - 1;
      UNLOCK();
      bVar3 = s_cRefDebugger == 1;
      s_cRefDebugger = uVar1;
      if (bVar3) {
        lVar2 = RoSetErrorReportingFlags(4);
      }
    }
  }
  return lVar2;
}



===== Destroy @ 14000bc78 =====

/* public: static void __cdecl wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64) */

void __cdecl
wil::details::DestroyThreadPoolTimer<wil::details::SystemThreadPoolMethods,0>::Destroy
          (_TP_TIMER *param_1)

{
  SetThreadpoolTimer(param_1,(PFILETIME)0x0,0,0);
  WaitForThreadpoolTimerCallbacks(param_1,1);
                    /* WARNING: Could not recover jumptable at 0x00014000bcb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CloseThreadpoolTimer(param_1);
  return;
}



===== Destroy @ 14000bcc4 =====

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



===== DisconnectObject @ 14000bcf0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl Microsoft::WRL::FtmBase::DisconnectObject(unsigned long) __ptr64 */

long __thiscall Microsoft::WRL::FtmBase::DisconnectObject(FtmBase *this,ulong param_1)

{
  long lVar1;
  
  if (*(longlong **)(this + 0x18) == (longlong *)0x0) {
    return -0x7ff8fff2;
  }
  lVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x40))();
  return lVar1;
}



===== FailFast_Unexpected @ 14000bd14 =====

/* void __cdecl wil::details::in1diag3::FailFast_Unexpected(void * __ptr64,unsigned int,char const *
   __ptr64) */

void __cdecl wil::details::in1diag3::FailFast_Unexpected(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  long in_stack_ffffffffffffffe8;
  
  ReportFailure_Hr<3>(param_1,0xc37,"onecore\\internal\\sdk\\inc\\wil\\opensource\\wil\\resource.h",
                      in_R9,in_stack_ffffffffffffffd8,unaff_retaddr,in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== FormatNtStatusMsg @ 14000bd40 =====

/* void __cdecl wil::details::FormatNtStatusMsg(long,unsigned short * __ptr64,unsigned long) */

void __cdecl wil::details::FormatNtStatusMsg(long param_1,ushort *param_2,ulong param_3)

{
  HINSTANCE__ *lpSource;
  
  lpSource = wil_details_GetNtDllModuleHandle();
  FormatMessageW(0x1a00,lpSource,param_1,0x400,(LPWSTR)param_2,param_3,(va_list *)0x0);
  return;
}



===== GetErrorFlags @ 14000bda0 =====

/* public: virtual long __cdecl CRuntimeBroker::GetErrorFlags(unsigned int * __ptr64) __ptr64 */

long __thiscall CRuntimeBroker::GetErrorFlags(CRuntimeBroker *this,uint *param_1)

{
  long lVar1;
  bool local_res18 [16];
  
  local_res18[0] = false;
  lVar1 = CheckClient(this,local_res18);
  if (-1 < lVar1) {
    if (local_res18[0] == false) {
      return -0x7ff8fffb;
    }
    lVar1 = RoGetErrorReportingFlags(param_1);
  }
  return lVar1;
}



===== GetFailureLogString @ 14000bdec =====

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
        goto LAB_14000beb7;
      }
      pcVar4 = "LogHr";
      pcVar6 = "LogNt";
    }
    if (((byte)param_3[4] & 8) == 0) {
      pcVar6 = pcVar4;
    }
  }
LAB_14000beb7:
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



===== GetIids @ 14000c0c0 =====

/* public: virtual long __cdecl CRuntimeBroker::GetIids(unsigned long * __ptr64,struct _GUID *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall CRuntimeBroker::GetIids(CRuntimeBroker *this,ulong *param_1,_GUID **param_2)

{
  *param_1 = 0;
  *param_2 = (_GUID *)0x0;
  RoOriginateError(0x80004001,0);
  return -0x7fffbfff;
}



===== GetMarshalSizeMax @ 14000c0f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::GetMarshalSizeMax(struct
   _GUID const & __ptr64,void * __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned long *
   __ptr64) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::GetMarshalSizeMax
          (CRuntimeBrokerLifetimeExtensionFactory *this,_GUID *param_1,void *param_2,ulong param_3,
          void *param_4,ulong param_5,ulong *param_6)

{
  longlong *plVar1;
  long lVar2;
  
  plVar1 = *(longlong **)(this + 0x10);
  if (plVar1 == (longlong *)0x0) {
    lVar2 = -0x7ff8fff2;
  }
  else {
    lVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return lVar2;
}



===== GetMarshalSizeMax @ 14000c150 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl Microsoft::WRL::FtmBase::GetMarshalSizeMax(struct _GUID const &
   __ptr64,void * __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned long * __ptr64)
   __ptr64 */

long __thiscall
Microsoft::WRL::FtmBase::GetMarshalSizeMax
          (FtmBase *this,_GUID *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
          ulong *param_6)

{
  longlong *plVar1;
  long lVar2;
  
  plVar1 = *(longlong **)(this + 0x18);
  if (plVar1 == (longlong *)0x0) {
    lVar2 = -0x7ff8fff2;
  }
  else {
    lVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return lVar2;
}



===== GetModuleInformation @ 14000c1ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* bool __cdecl wil::details::GetModuleInformation(void * __ptr64,unsigned int * __ptr64,char *
   __ptr64,unsigned __int64) */

bool __cdecl
wil::details::GetModuleInformation(void *param_1,uint *param_2,char *param_3,__uint64 param_4)

{
  bool bVar1;
  BOOL BVar2;
  DWORD DVar3;
  char *pcVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 auStack_168 [32];
  HMODULE local_148 [2];
  CHAR local_138;
  char acStack_137 [271];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_168;
  local_148[0] = (HMODULE)0x0;
  if ((param_1 == (void *)0x0) || (BVar2 = GetModuleHandleExW(6,param_1,local_148), BVar2 != 0)) {
    if (param_2 != (uint *)0x0) {
      uVar6 = 0;
      if (param_1 != (void *)0x0) {
        uVar6 = (int)param_1 - (int)local_148[0];
      }
      *param_2 = uVar6;
    }
    if (param_3 != (char *)0x0) {
      DVar3 = GetModuleFileNameA(local_148[0],&local_138,0x104);
      if (DVar3 == 0) goto LAB_14000c245;
      lVar5 = -1;
      do {
        lVar7 = lVar5;
        lVar5 = lVar7 + 1;
      } while (acStack_137[lVar7] != '\0');
      for (pcVar4 = acStack_137 + lVar7; (&local_138 < pcVar4 && (pcVar4[-1] != '\\'));
          pcVar4 = pcVar4 + -1) {
      }
      if (param_4 != 0) {
        if (param_4 < 0x80000000) {
          lVar7 = 0x7ffffffe - param_4;
          lVar5 = (longlong)pcVar4 - (longlong)param_3;
          do {
            if ((lVar7 + param_4 == 0) || (param_3[lVar5] == '\0')) break;
            *param_3 = param_3[lVar5];
            param_3 = param_3 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
          pcVar4 = param_3 + -1;
          if (param_4 != 0) {
            pcVar4 = param_3;
          }
          *pcVar4 = '\0';
        }
        else {
          *param_3 = '\0';
        }
      }
    }
    bVar1 = true;
  }
  else {
    if (param_2 != (uint *)0x0) {
      *param_2 = 0;
    }
LAB_14000c245:
    bVar1 = false;
  }
  return bVar1;
}



===== GetRuntimeClassName @ 14000c2f0 =====

/* public: virtual long __cdecl CRuntimeBroker::GetRuntimeClassName(struct HSTRING__ * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall CRuntimeBroker::GetRuntimeClassName(CRuntimeBroker *this,HSTRING__ **param_1)

{
  *param_1 = (HSTRING__ *)0x0;
  RoOriginateError(0x80004001,0);
  return -0x7fffbfff;
}



===== GetThreadContext @ 14000c31c =====

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



===== GetTrustLevel @ 14000c420 =====

/* public: virtual long __cdecl CRuntimeBroker::GetTrustLevel(enum TrustLevel * __ptr64) __ptr64 */

long __thiscall CRuntimeBroker::GetTrustLevel(CRuntimeBroker *this,TrustLevel *param_1)

{
  *param_1 = 1;
  return 0;
}



===== GetUnmarshalClass @ 14000c430 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl Microsoft::WRL::FtmBase::GetUnmarshalClass(struct _GUID const &
   __ptr64,void * __ptr64,unsigned long,void * __ptr64,unsigned long,struct _GUID * __ptr64) __ptr64
    */

long __thiscall
Microsoft::WRL::FtmBase::GetUnmarshalClass
          (FtmBase *this,_GUID *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
          _GUID *param_6)

{
  longlong *plVar1;
  long lVar2;
  
  plVar1 = *(longlong **)(this + 0x18);
  if (plVar1 == (longlong *)0x0) {
    lVar2 = -0x7ff8fff2;
  }
  else {
    lVar2 = (**(code **)(*plVar1 + 0x18))(plVar1,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return lVar2;
}



===== InlineIsEqualGUID @ 14000c48c =====

/* int __cdecl InlineIsEqualGUID(struct _GUID const & __ptr64,struct _GUID const & __ptr64) */

int __cdecl InlineIsEqualGUID(_GUID *param_1,_GUID *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((((param_1->Data1 == param_2->Data1) &&
       (iVar1._0_2_ = param_2->Data2, iVar1._2_2_ = param_2->Data3, iVar2._0_2_ = param_1->Data2,
       iVar2._2_2_ = param_1->Data3, iVar2 == iVar1)) &&
      (*(int *)param_1->Data4 == *(int *)param_2->Data4)) &&
     (*(int *)(param_1->Data4 + 4) == *(int *)(param_2->Data4 + 4))) {
    return 1;
  }
  return 0;
}



===== Invoke @ 14000c4c0 =====

/* public: virtual long __cdecl Microsoft::WRL::Details::DelegateArgTraits<long (__cdecl
   Windows::Foundation::ITypedEventHandler_impl<struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserWatcher * __ptr64,struct
   Windows::System::IUserWatcher * __ptr64>,struct
   Windows::Foundation::Internal::AggregateType<class Windows::System::UserChangedEventArgs *
   __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64> >::*)(struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs * __ptr64)
   __ptr64>::DelegateInvokeHelper<struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase>,class <lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,struct
   Windows::System::IUserWatcher * __ptr64,struct Windows::System::IUserChangedEventArgs *
   __ptr64>::Invoke(struct Windows::System::IUserWatcher * __ptr64,struct
   Windows::System::IUserChangedEventArgs * __ptr64) __ptr64 */

long __thiscall
Microsoft::WRL::Details::
DelegateArgTraits<long_(__cdecl_Windows::Foundation::ITypedEventHandler_impl<Windows::Foundation::Internal::AggregateType<Windows::System::UserWatcher*___ptr64,Windows::System::IUserWatcher*___ptr64>,Windows::Foundation::Internal::AggregateType<Windows::System::UserChangedEventArgs*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>_>::*)(Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64)___ptr64>
::
DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,-1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>
::Invoke(DelegateInvokeHelper<Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>,<lambda_ff67e1dbbd64ec80e0b69245dd48b71a>,_1,Windows::System::IUserWatcher*___ptr64,Windows::System::IUserChangedEventArgs*___ptr64>
         *this,IUserWatcher *param_1,IUserChangedEventArgs *param_2)

{
  IUserChangedEventArgs *local_res18 [2];
  
  local_res18[0] = param_2;
  AcquireSRWLockShared((PSRWLOCK)&CRuntimeBroker::s_ShutdownEventLock);
  local_res18[0] = (IUserChangedEventArgs *)&CRuntimeBroker::s_ShutdownEventLock;
  if (CRuntimeBroker::s_hEventShutdown != (void *)0x0) {
    SetEvent(CRuntimeBroker::s_hEventShutdown);
  }
  wil::details::
  unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_RTL_SRWLOCK*___ptr64,void_(__cdecl*)(_RTL_SRWLOCK*___ptr64),&void___cdecl_ReleaseSRWLockShared(struct__RTL_SRWLOCK*___ptr64),wistd::integral_constant<unsigned___int64,1>,_RTL_SRWLOCK*___ptr64,_RTL_SRWLOCK*___ptr64,0,std::nullptr_t>_>
              *)local_res18);
  return 0;
}



===== IsDefaultUserProcess @ 14000c518 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl CRuntimeBroker::IsDefaultUserProcess(bool * __ptr64) */

long __cdecl CRuntimeBroker::IsDefaultUserProcess(bool *param_1)

{
  PVOID Buffer;
  char cVar1;
  long lVar2;
  BOOL BVar3;
  void *pvVar4;
  uint uVar5;
  PLSA_LOOKUP_HANDLE PolicyHandle;
  void *unaff_retaddr;
  undefined1 auStack_d8 [32];
  PVOID local_b8;
  DWORD local_b0 [2];
  PVOID local_a8;
  last_error_context local_a0 [8];
  _LSA_OBJECT_ATTRIBUTES local_98;
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  *param_1 = false;
  pvVar4 = GetSelfSid();
  local_b8 = (PVOID)0x0;
  PolicyHandle = &local_a8;
  local_a8 = (LSA_LOOKUP_HANDLE)0x0;
  local_b0[0] = 0x44;
  local_98.Length = 0;
  local_98._4_4_ = 0;
  local_98.RootDirectory = (HANDLE)0x0;
  local_98.ObjectName = (PLSA_UNICODE_STRING)0x0;
  local_98.Attributes = 0;
  local_98._28_4_ = 0;
  local_98.SecurityDescriptor = (PVOID)0x0;
  local_98.SecurityQualityOfService = (PVOID)0x0;
  lVar2 = LsaLookupOpenLocalPolicy(&local_98,1,PolicyHandle);
  Buffer = local_b8;
  if (lVar2 < 0) {
    uVar5 = 0x52c;
  }
  else {
    if (local_b8 != (PVOID)0x0) {
      wil::last_error_context::last_error_context(local_a0);
      LsaLookupFreeMemory(Buffer);
      wil::last_error_context::~last_error_context(local_a0);
    }
    PolicyHandle = &local_b8;
    local_b8 = (PVOID)0x0;
    lVar2 = LsaLookupGetDomainInfo(local_a8,AccountDomainInformation,PolicyHandle);
    if (-1 < lVar2) {
      BVar3 = CreateWellKnownSid(WinBuiltinCryptoOperatorsSid|WinAccountCertAdminsSid,
                                 *(PSID *)((longlong)local_b8 + 0x10),local_68,local_b0);
      if (BVar3 == 0) {
        lVar2 = wil::details::in1diag3::Return_GetLastError
                          (unaff_retaddr,0x52e,
                           "onecore\\com\\combase\\runtimebroker\\exe\\runtimebroker.cpp");
      }
      else {
        cVar1 = RtlEqualSid(pvVar4,local_68);
        if (cVar1 != '\0') {
          *param_1 = true;
        }
        lVar2 = 0;
      }
      goto LAB_14000c64c;
    }
    uVar5 = 0x52d;
  }
  lVar2 = wil::details::in1diag3::Return_NtStatus(unaff_retaddr,uVar5,(char *)PolicyHandle,lVar2);
LAB_14000c64c:
  wil::details::
  unique_storage<wil::details::resource_policy<_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupFreeMemory(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupFreeMemory(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupFreeMemory(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,_POLICY_ACCOUNT_DOMAIN_INFO*___ptr64,0,std::nullptr_t>_>
              *)&local_b8);
  wil::details::
  unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_LsaLookupClose(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)&local_a8);
  return lVar2;
}



===== LockServer @ 14000c690 =====

/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::LockServer(int) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::LockServer
          (CRuntimeBrokerLifetimeExtensionFactory *this,int param_1)

{
  return 0;
}



===== LogStringPrintf @ 14000c69c =====

/* unsigned short * __ptr64 __cdecl wil::details::LogStringPrintf(unsigned short * __ptr64,unsigned
   short const * __ptr64,unsigned short const * __ptr64,...) */

ushort * __cdecl wil::details::LogStringPrintf(ushort *param_1,ushort *param_2,ushort *param_3,...)

{
  longlong lVar1;
  undefined8 in_R9;
  undefined8 local_res20;
  
  local_res20 = in_R9;
  StringCchVPrintfW(param_1,(longlong)param_2 - (longlong)param_1 >> 1,param_3,(char *)&local_res20)
  ;
  if (param_2 != param_1) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_1[lVar1] != 0);
    param_1 = param_1 + lVar1;
  }
  return param_1;
}



===== MakeAndInitialize @ 14000c6f0 =====

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
  undefined1 uVar6;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **ppPVar7;
  void *unaff_retaddr;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  *param_3 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
  ppPVar7 = param_3;
  pvVar5 = details::ProcessHeapAlloc(8,0x78);
  uVar6 = SUB81(ppPVar7,0);
  wistd::unique_ptr<void,wil::process_heap_deleter>::
  unique_ptr<void,wil::process_heap_deleter><1,void>
            ((unique_ptr<void,wil::process_heap_deleter> *)local_res18,pvVar5);
  bVar3 = wistd::operator==<void,wil::process_heap_deleter>(local_res18);
  if (bVar3) {
    details::in1diag3::Return_Hr(unaff_retaddr,0x148,"wil",-0x7ff8fff2);
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
                      ((SemaphoreValue *)&local_28,param_1,(bool)uVar6,
                       (ulonglong)local_res18[0] >> 2);
    uVar2 = uStack_20;
    uVar1 = local_28;
    if (lVar4 < 0) {
      details::in1diag3::Return_Hr(unaff_retaddr,0x14b,"wil",lVar4);
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



===== MakeAndInitialize @ 14000c850 =====

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
  undefined1 uVar6;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **ppPVar7;
  void *unaff_retaddr;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  *param_3 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
  ppPVar7 = param_3;
  pvVar5 = details::ProcessHeapAlloc(8,0x130);
  uVar6 = SUB81(ppPVar7,0);
  wistd::unique_ptr<void,wil::process_heap_deleter>::
  unique_ptr<void,wil::process_heap_deleter><1,void>
            ((unique_ptr<void,wil::process_heap_deleter> *)local_res18,pvVar5);
  bVar3 = wistd::operator==<void,wil::process_heap_deleter>(local_res18);
  if (bVar3) {
    details::in1diag3::Return_Hr(unaff_retaddr,0x148,"wil",-0x7ff8fff2);
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
                      ((SemaphoreValue *)&local_28,param_1,(bool)uVar6,
                       (ulonglong)local_res18[0] >> 2);
    uVar2 = uStack_20;
    uVar1 = local_28;
    if (lVar4 < 0) {
      details::in1diag3::Return_Hr(unaff_retaddr,0x14b,"wil",lVar4);
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



===== MarshalInterface @ 14000c9b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::MarshalInterface(struct
   IStream * __ptr64,struct _GUID const & __ptr64,void * __ptr64,unsigned long,void *
   __ptr64,unsigned long) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::MarshalInterface
          (CRuntimeBrokerLifetimeExtensionFactory *this,IStream *param_1,_GUID *param_2,
          void *param_3,ulong param_4,void *param_5,ulong param_6)

{
  longlong *plVar1;
  long lVar2;
  
  plVar1 = *(longlong **)(this + 0x10);
  if (plVar1 == (longlong *)0x0) {
    lVar2 = -0x7ff8fff2;
  }
  else {
    lVar2 = (**(code **)(*plVar1 + 0x28))(plVar1,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return lVar2;
}



===== MarshalInterface @ 14000ca10 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl Microsoft::WRL::FtmBase::MarshalInterface(struct IStream *
   __ptr64,struct _GUID const & __ptr64,void * __ptr64,unsigned long,void * __ptr64,unsigned long)
   __ptr64 */

long __thiscall
Microsoft::WRL::FtmBase::MarshalInterface
          (FtmBase *this,IStream *param_1,_GUID *param_2,void *param_3,ulong param_4,void *param_5,
          ulong param_6)

{
  longlong *plVar1;
  long lVar2;
  
  plVar1 = *(longlong **)(this + 0x18);
  if (plVar1 == (longlong *)0x0) {
    lVar2 = -0x7ff8fff2;
  }
  else {
    lVar2 = (**(code **)(*plVar1 + 0x28))(plVar1,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return lVar2;
}



===== ProcessShutdown @ 14000ca6c =====

/* public: void __cdecl wil::details_abi::FeatureStateData::ProcessShutdown(void) __ptr64 */

void __thiscall wil::details_abi::FeatureStateData::ProcessShutdown(FeatureStateData *this)

{
  UsageIndexes local_c8 [200];
  
  UsageIndexes::UsageIndexes(local_c8);
  RetrieveUsageUnderLock(this,local_c8);
  UsageIndexes::Record(local_c8);
  UsageIndexes::~UsageIndexes(local_c8);
  return;
}



===== QueryInterface @ 14000cab0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl Microsoft::WRL::Details::RuntimeClassImpl<struct
   Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> >::QueryInterface(struct _GUID const & __ptr64,void *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall
Microsoft::WRL::Details::
RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
::QueryInterface(RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
                 *this,_GUID *param_1,void **param_2)

{
  int iVar1;
  
  *param_2 = (void *)0x0;
  iVar1 = InlineIsEqualGUID(param_1,(_GUID *)&_GUID_00000000_0000_0000_c000_000000000046);
  if (iVar1 != 0) {
    *param_2 = this;
    (**(code **)(*(longlong *)this + 8))(this);
    return 0;
  }
  iVar1 = InlineIsEqualGUID(param_1,(_GUID *)&_GUID_eb9d0454_25db_5620_98b8_be4c5d0dbc67);
  if (iVar1 == 0) {
    this = this + 8;
    iVar1 = InlineIsEqualGUID(param_1,(_GUID *)&_GUID_94ea2b94_e9cc_49e0_c0ff_ee64ca8f5b90);
    if ((iVar1 == 0) &&
       (iVar1 = InlineIsEqualGUID(param_1,(_GUID *)&_GUID_00000003_0000_0000_c000_000000000046),
       iVar1 == 0)) {
      iVar1 = -0x7fffbffe;
      this = (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
              *)0x0;
    }
    else {
      *param_2 = this;
      iVar1 = 0;
    }
    if (iVar1 == -0x7fffbffe) {
      return -0x7fffbffe;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    *param_2 = this;
    iVar1 = 0;
  }
  (**(code **)(*(longlong *)this + 8))(this);
  return iVar1;
}



===== QueryInterface`adjustor{8}' @ 14000cac0 =====

/* [thunk]:public: virtual long __cdecl Microsoft::WRL::Details::RuntimeClassImpl<struct
   Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> >::QueryInterface`adjustor{8}' (struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
Microsoft::WRL::Details::
RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
::QueryInterface_adjustor_8__
          (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
           *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = QueryInterface(this + -8,param_1,param_2);
  return lVar1;
}



===== QueryInterface @ 14000cad0 =====

/* private: virtual long __cdecl
   CRuntimeBrokerLifetimeExtensionFactory::CLifetimeExtension::QueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::CLifetimeExtension::QueryInterface
          (CLifetimeExtension *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  *param_2 = (void *)0x0;
  lVar1._0_4_ = param_1->Data1;
  lVar1._4_2_ = param_1->Data2;
  lVar1._6_2_ = param_1->Data3;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)param_1->Data4 + -0x46000000000000c0;
  }
  if (lVar1 != 0) {
    lVar1 = *(longlong *)param_1 + -0x4dc0c1dbecc8691b;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)param_1->Data4 + -0x49af51c5f6655e85;
    }
    if (lVar1 != 0) {
      lVar1 = *(longlong *)param_1 + -0x49e0e9cc94ea2b94;
      if (lVar1 == 0) {
        lVar1 = *(longlong *)param_1->Data4 + 0x6fa470359b110040;
      }
      if (lVar1 != 0) {
        return -0x7fffbffe;
      }
    }
  }
  *param_2 = this;
  LOCK();
  *(int *)(this + 8) = *(int *)(this + 8) + 1;
  UNLOCK();
  return 0;
}



===== QueryInterface`adjustor{8}' @ 14000cb50 =====

/* [thunk]:public: virtual long __cdecl
   CRuntimeBrokerLifetimeExtensionFactory::QueryInterface`adjustor{8}' (struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::QueryInterface_adjustor_8__
          (CRuntimeBrokerLifetimeExtensionFactory *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = QueryInterface(this + -8,param_1,param_2);
  return lVar1;
}



===== QueueBackgroundSRUMUsageReporting @ 14000cb60 =====

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



===== RecordException @ 14000cc14 =====

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



===== RecordFailFast @ 14000cc40 =====

/* int __cdecl wil::details::RecordFailFast(long) */

int __cdecl wil::details::RecordFailFast(long param_1)

{
  `int___cdecl_wil::details::RecordFailFast(long)'::__l2::s_hrErrorLast = param_1;
  return 1;
}



===== RecordFeatureUsageUnderLock @ 14000cc54 =====

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



===== RecordLog @ 14000ccb0 =====

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



===== RecordSRUMFeatureUsage @ 14000ccd0 =====

/* void __cdecl wil::details::RecordSRUMFeatureUsage(unsigned int,unsigned int,unsigned int) */

void __cdecl wil::details::RecordSRUMFeatureUsage(uint param_1,uint param_2,uint param_3)

{
  char *in_R9;
  
  WilApi_RecordFeatureUsage(param_1,param_2 | 0x40000000,param_3,in_R9);
  return;
}



===== RecordUsage @ 14000cce0 =====

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



===== RecordUsage @ 14000cd18 =====

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



===== Release @ 14000cd50 =====

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



===== Release @ 14000cddc =====

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



===== Release @ 14000ce80 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual unsigned long __cdecl Microsoft::WRL::Details::RuntimeClassImpl<struct
   Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> >::Release(void) __ptr64 */

ulong __thiscall
Microsoft::WRL::Details::
RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
::Release(RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
          *this)

{
  int iVar1;
  bool bVar2;
  
  do {
    iVar1 = *(int *)(this + 0x3c);
    if (iVar1 == 0x7fffffff) break;
    LOCK();
    bVar2 = iVar1 == *(int *)(this + 0x3c);
    if (bVar2) {
      *(int *)(this + 0x3c) = iVar1 + -1;
    }
    UNLOCK();
  } while (!bVar2);
  if (iVar1 - 1U == 0) {
    if (this != (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
                 *)0x0) {
      (**(code **)(*(longlong *)this + 0x20))(this,iVar1);
    }
    if (ModuleBase::module_ != (ModuleBase *)0x0) {
      (**(code **)(*(longlong *)ModuleBase::module_ + 0x10))();
    }
  }
  return iVar1 - 1U;
}



===== Release`adjustor{8}' @ 14000cef0 =====

/* [thunk]:public: virtual unsigned long __cdecl Microsoft::WRL::Details::RuntimeClassImpl<struct
   Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,struct Microsoft::WRL::Implements<struct
   Microsoft::WRL::RuntimeClassFlags<2>,struct Windows::Foundation::ITypedEventHandler<class
   Windows::System::UserWatcher * __ptr64,class Windows::System::UserChangedEventArgs *
   __ptr64>,class Microsoft::WRL::FtmBase> >::Release`adjustor{8}' (void) __ptr64 */

ulong __thiscall
Microsoft::WRL::Details::
RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
::Release_adjustor_8__
          (RuntimeClassImpl<Microsoft::WRL::RuntimeClassFlags<2>,1,0,0,Microsoft::WRL::Implements<Microsoft::WRL::RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::UserWatcher*___ptr64,Windows::System::UserChangedEventArgs*___ptr64>,Microsoft::WRL::FtmBase>_>
           *this)

{
  ulong uVar1;
  
  uVar1 = Release(this + -8);
  return uVar1;
}



===== Release`adjustor{8}' @ 14000cf00 =====

/* [thunk]:public: virtual unsigned long __cdecl
   CRuntimeBrokerLifetimeExtensionFactory::Release`adjustor{8}' (void) __ptr64 */

ulong __thiscall
CRuntimeBrokerLifetimeExtensionFactory::Release_adjustor_8__
          (CRuntimeBrokerLifetimeExtensionFactory *this)

{
  ulong uVar1;
  
  uVar1 = Release(this + -8);
  return uVar1;
}



===== ReleaseMarshalData @ 14000cf10 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::ReleaseMarshalData(struct
   IStream * __ptr64) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::ReleaseMarshalData
          (CRuntimeBrokerLifetimeExtensionFactory *this,IStream *param_1)

{
  long lVar1;
  
  if (*(longlong **)(this + 0x10) == (longlong *)0x0) {
    return -0x7ff8fff2;
  }
  lVar1 = (**(code **)(**(longlong **)(this + 0x10) + 0x38))();
  return lVar1;
}



===== ReleaseMarshalData @ 14000cf40 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl Microsoft::WRL::FtmBase::ReleaseMarshalData(struct IStream *
   __ptr64) __ptr64 */

long __thiscall Microsoft::WRL::FtmBase::ReleaseMarshalData(FtmBase *this,IStream *param_1)

{
  long lVar1;
  
  if (*(longlong **)(this + 0x18) == (longlong *)0x0) {
    return -0x7ff8fff2;
  }
  lVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x38))();
  return lVar1;
}



===== ResultStringSize @ 14000cf64 =====

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



===== ResultStringSize @ 14000cf90 =====

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



===== Return_NtStatus @ 14000cfbc =====

/* long __cdecl wil::details::in1diag3::Return_NtStatus(void * __ptr64,unsigned int,char const *
   __ptr64,long) */

long __cdecl
wil::details::in1diag3::Return_NtStatus(void *param_1,uint param_2,char *param_3,long param_4)

{
  long lVar1;
  undefined4 in_register_0000008c;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  
  lVar1 = ReportFailure_NtStatus<1>
                    (param_1,param_2,param_3,(char *)CONCAT44(in_register_0000008c,param_4),
                     in_stack_ffffffffffffffd8,unaff_retaddr,param_4);
  return lVar1;
}



===== RtlNtStatusToDosErrorNoTeb @ 14000cfe0 =====

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



===== Set @ 14000d030 =====

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
      goto LAB_14000d19b;
    }
  }
  if (pTVar1 != (ThreadLocalFailureInfo *)0x0) {
    *(undefined8 *)pTVar1 = 0;
  }
LAB_14000d19b:
  memset(puVar7,0,(longlong)puVar8 - (longlong)puVar7);
  return;
}



===== SetErrorFlags @ 14000d1d0 =====

/* public: virtual long __cdecl CRuntimeBroker::SetErrorFlags(unsigned int) __ptr64 */

long __thiscall CRuntimeBroker::SetErrorFlags(CRuntimeBroker *this,uint param_1)

{
  long lVar1;
  bool local_res18 [16];
  
  local_res18[0] = false;
  lVar1 = CheckClient(this,local_res18);
  if (-1 < lVar1) {
    if (local_res18[0] == false) {
      return -0x7ff8fffb;
    }
    lVar1 = RoSetErrorReportingFlags(param_1);
  }
  return lVar1;
}



===== SetLastError @ 14000d21c =====

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



===== SkipValues @ 14000d31c =====

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



===== StringCchVPrintfW @ 14000d3ec =====

/* long __cdecl StringCchVPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,char * __ptr64) */

long __cdecl StringCchVPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,char *param_4)

{
  HRESULT HVar1;
  
  if (param_2 - 1 < 0x7fffffff) {
    HVar1 = StringVPrintfWorkerW
                      ((STRSAFE_LPWSTR)param_1,param_2,(size_t *)param_3,(STRSAFE_LPCWSTR)param_3,
                       param_4);
  }
  else {
    HVar1 = -0x7ff8ffa9;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return HVar1;
}



===== UnmarshalInterface @ 14000d430 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl CRuntimeBrokerLifetimeExtensionFactory::UnmarshalInterface(struct
   IStream * __ptr64,struct _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRuntimeBrokerLifetimeExtensionFactory::UnmarshalInterface
          (CRuntimeBrokerLifetimeExtensionFactory *this,IStream *param_1,_GUID *param_2,
          void **param_3)

{
  long lVar1;
  
  if (*(longlong **)(this + 0x10) == (longlong *)0x0) {
    lVar1 = -0x7ff8fff2;
  }
  else {
    lVar1 = (**(code **)(**(longlong **)(this + 0x10) + 0x30))();
  }
  return lVar1;
}



===== UnmarshalInterface @ 14000d460 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl Microsoft::WRL::FtmBase::UnmarshalInterface(struct IStream *
   __ptr64,struct _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
Microsoft::WRL::FtmBase::UnmarshalInterface
          (FtmBase *this,IStream *param_1,_GUID *param_2,void **param_3)

{
  long lVar1;
  
  if (*(longlong **)(this + 0x18) == (longlong *)0x0) {
    lVar1 = -0x7ff8fff2;
  }
  else {
    lVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x30))();
  }
  return lVar1;
}



===== Unsubscribe @ 14000d48c =====

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



===== UnsubscribeProcessWideUsageFlush @ 14000d520 =====

/* void __cdecl wil::details::UnsubscribeProcessWideUsageFlush(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64) */

void __cdecl
wil::details::UnsubscribeProcessWideUsageFlush(FEATURE_STATE_CHANGE_SUBSCRIPTION__ *param_1)

{
  if ((param_1 != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) && (DAT_1400190d0 != (srwlock *)0x0))
  {
    details_abi::SubscriptionList::Unsubscribe
              ((SubscriptionList *)(DAT_1400190d0 + 200),DAT_1400190d0,param_1);
  }
  return;
}



===== UpdateCount @ 14000d550 =====

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



===== WilApiImpl_UnsubscribeFeatureStateChangeNotification @ 14000d5a0 =====

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
    this = (SubscriptionList *)&DAT_140019100;
  }
  else {
    if (g_featureStateManager == (shutdown_aware_object<wil::details::FeatureStateManager>)0x0) {
      return;
    }
    param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)((ulonglong)param_1 & 0xffffffff7fffffff);
    this = (SubscriptionList *)&DAT_140019150;
  }
  details_abi::SubscriptionList::Unsubscribe(this,(srwlock *)&DAT_1400190d8,param_1);
  return;
}



===== WilApi_RecordFeatureUsageReports @ 14000d5f8 =====

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



===== WilApi_UnsubscribeFeatureStateChangeNotification @ 14000d63c =====

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



===== WilDynamicLoadRaiseFailFastException @ 14000d670 =====

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



===== WilFailFast @ 14000d6dc =====

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



===== WilRaiseFailFastException @ 14000d78c =====

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



===== _FailFastImmediate_Unexpected @ 14000d7b8 =====

/* void __cdecl wil::details::in1diag3::_FailFastImmediate_Unexpected(void) */

void __cdecl wil::details::in1diag3::_FailFastImmediate_Unexpected(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(7);
  return;
}



===== _FailFast_GetLastError @ 14000d7c8 =====

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



===== _FailFast_Unexpected @ 14000d7e4 =====

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



===== _Log_Hr @ 14000d80c =====

/* void __cdecl wil::details::in1diag3::_Log_Hr(void * __ptr64,unsigned int,char const *
   __ptr64,long) */

void __cdecl wil::details::in1diag3::_Log_Hr(void *param_1,uint param_2,char *param_3,long param_4)

{
  void *unaff_retaddr;
  
  ReportFailure_Hr<2>(param_1,param_2,param_3,(char *)0x0,(char *)0x0,unaff_retaddr,param_4);
  return;
}



===== __clone @ 14000d840 =====

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



===== create @ 14000d864 =====

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



===== reset @ 14000d8d4 =====

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



===== wil_details_GetKernelBaseProcAddress @ 14000d928 =====

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



===== wil_details_GetNtDllProcedureAddress @ 14000d98c =====

/* __int64 (__cdecl*__cdecl wil_details_GetNtDllProcedureAddress(char const * __ptr64))(void) */

_func___int64 * __cdecl wil_details_GetNtDllProcedureAddress(char *param_1)

{
  HINSTANCE__ *hModule;
  FARPROC pFVar1;
  
  hModule = wil_details_GetNtDllModuleHandle();
                    /* WARNING: Could not recover jumptable at 0x00014000d9a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = GetProcAddress(hModule,param_1);
  return (_func___int64 *)pFVar1;
}



===== wil_details_WriteSRUMWnfUsageBuffer @ 14000d9b8 =====

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
  
  local_20 = 0x14000d9dd;
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
              goto LAB_14000db1b;
            }
          }
          if (uVar5 + 0xc < 0x1001) {
            local_1038 = (uint)uVar5 + 0xc;
            uVar5 = (ulonglong)local_1038;
            *(undefined8 *)piVar2 = *(undefined8 *)piVar11;
            uVar12 = (ulonglong)((int)uVar13 + 1);
            local_1028[uVar13 * 3 + 2] = piVar11[2];
          }
LAB_14000db1b:
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



===== wil_QueryFeatureState @ 14000dba8 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 14000dbcc =====

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
    else if (iVar1 != 0x117) goto LAB_14000dca7;
    uVar3 = 1;
    param_1[4] = local_40._4_4_ >> 7 & 1;
  }
LAB_14000dca7:
  if (param_4 != (uint *)0x0) {
    *param_4 = (uint)(iVar1 != -0x7fffffde);
  }
  return uVar3;
}



===== wil_RtlStagingConfig_RecordFeatureUsage @ 14000dce4 =====

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



===== wil_StagingConfig_LogStagedFeatureUsage @ 14000dd50 =====

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



===== wil_details_NtQueryWnfStateData @ 14000ddb0 =====

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



===== wil_details_NtUpdateWnfStateData @ 14000de28 =====

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



===== wil_details_RecordCachedUsage @ 14000deb4 =====

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



===== wil_details_RtlRegisterFeatureConfigurationChangeNotification @ 14000e000 =====

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



===== wil_details_RtlUnregisterFeatureConfigurationChangeNotification @ 14000e06c =====

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



===== ComTraceMessage @ 14000e0b0 =====

/* void __cdecl ComTraceMessage(long,char const * __ptr64,char const * __ptr64,int,enum
   TraceLevel,unsigned short const * __ptr64,...) */

void __cdecl
ComTraceMessage(long param_1,char *param_2,char *param_3,int param_4,TraceLevel param_5,
               ushort *param_6,...)

{
  char cStack0000000000000038;
  
  ComTraceMessageWorker(param_1,param_2,param_3,param_4,param_5,param_6,&cStack0000000000000038);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000e0e4 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000e1c8 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000e2b8 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3)

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
LAB_14000e40d:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000e3fd:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14000e40d;
      if (uVar5 == 5) goto LAB_14000e3fd;
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
        param_1[3] = 0;
        param_1[2] = uVar5;
        param_1[1] = 1;
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



===== wil_details_MapReportingKind @ 14000e430 =====

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



===== <lambda_invoker_cdecl> @ 14000e4d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: static __cdecl <lambda_f8a79a44bba2ee3470b25df359f31864>::<lambda_invoker_cdecl>(void)
    */

void __cdecl <lambda_f8a79a44bba2ee3470b25df359f31864>::<lambda_invoker_cdecl>(void)

{
  BOOL BVar1;
  BOOL local_res8 [2];
  longlong *local_res10 [3];
  
  local_res10[0] = (longlong *)0x0;
  local_res8[0] = 0;
  BVar1 = InitOnceBeginInitialize
                    ((LPINIT_ONCE)
                     &`protected:_static_class_ComTrace*___ptr64___cdecl_ComTrace::Instance(void)'::
                      __l2::wrapper,1,local_res8,local_res10);
  if ((BVar1 != 0) && (local_res8[0] == 0)) {
    (**(code **)(*local_res10[0] + 0x18))(local_res10[0],0);
  }
  return;
}



===== duration<__int64,std::ratio<1,1000000000>_><__int64,std::ratio<1,1>,0> @ 14000e52c =====

/* public: __cdecl std::chrono::duration<__int64,struct std::ratio<1,1000000000>
   >::duration<__int64,struct std::ratio<1,1000000000> ><__int64,struct std::ratio<1,1>,0>(class
   std::chrono::duration<__int64,struct std::ratio<1,1> > const & __ptr64) __ptr64 */

duration<__int64,std::ratio<1,1000000000>_> * __thiscall
std::chrono::duration<__int64,std::ratio<1,1000000000>_>::
duration<__int64,std::ratio<1,1000000000>_><__int64,std::ratio<1,1>,0>
          (duration<__int64,std::ratio<1,1000000000>_> *this,
          duration<__int64,std::ratio<1,1>_> *param_1)

{
  undefined8 *puVar1;
  duration<__int64,std::ratio<1,1>_> local_res8 [32];
  
  puVar1 = (undefined8 *)
           duration_cast<std::chrono::duration<__int64,std::ratio<1,1000000000>_>,__int64,std::ratio<1,1>,0>
                     (local_res8);
  *(undefined8 *)this = *puVar1;
  return this;
}



===== operator+<std::chrono::steady_clock,std::chrono::duration<__int64,std::ratio<1,1000000000>_>,__int64,std::ratio<1,1>_> @ 14000e554 =====

/* class std::chrono::time_point<struct std::chrono::steady_clock,class
   std::chrono::duration<__int64,struct std::ratio<1,1000000000> > > __cdecl
   std::chrono::operator+<struct std::chrono::steady_clock,class
   std::chrono::duration<__int64,struct std::ratio<1,1000000000> >,__int64,struct std::ratio<1,1>
   >(class std::chrono::time_point<struct std::chrono::steady_clock,class
   std::chrono::duration<__int64,struct std::ratio<1,1000000000> > > const & __ptr64,class
   std::chrono::duration<__int64,struct std::ratio<1,1> > const & __ptr64) */

time_point<struct_std::chrono::steady_clock,class_std::chrono::duration<__int64,struct_std::ratio<1,1000000000>_>_>
* __cdecl std::chrono::
          operator+<std::chrono::steady_clock,std::chrono::duration<__int64,std::ratio<1,1000000000>_>,__int64,std::ratio<1,1>_>
                    (time_point<struct_std::chrono::steady_clock,class_std::chrono::duration<__int64,struct_std::ratio<1,1000000000>_>_>
                     *param_1,duration<__int64,std::ratio<1,1>_> *param_2)

{
  undefined8 *puVar1;
  undefined8 local_res8;
  duration<__int64,struct_std::ratio<1,1000000000>_> local_res10 [24];
  
  local_res8 = *(undefined8 *)param_2;
  puVar1 = (undefined8 *)
           operator+<__int64,std::ratio<1,1000000000>,__int64,std::ratio<1,1>_>
                     (local_res10,(duration<__int64,std::ratio<1,1>_> *)&local_res8);
  *(undefined8 *)param_1 = *puVar1;
  return param_1;
}



===== operator+<__int64,std::ratio<1,1000000000>,__int64,std::ratio<1,1>_> @ 14000e588 =====

/* class std::chrono::duration<__int64,struct std::ratio<1,1000000000> > __cdecl
   std::chrono::operator+<__int64,struct std::ratio<1,1000000000>,__int64,struct std::ratio<1,1>
   >(class std::chrono::duration<__int64,struct std::ratio<1,1000000000> > const & __ptr64,class
   std::chrono::duration<__int64,struct std::ratio<1,1> > const & __ptr64) */

duration<__int64,struct_std::ratio<1,1000000000>_> * __cdecl
std::chrono::operator+<__int64,std::ratio<1,1000000000>,__int64,std::ratio<1,1>_>
          (duration<__int64,struct_std::ratio<1,1000000000>_> *param_1,
          duration<__int64,std::ratio<1,1>_> *param_2)

{
  longlong *plVar1;
  duration<__int64,std::ratio<1,1>_> *in_R8;
  duration<__int64,std::ratio<1,1000000000>_> local_res8 [32];
  
  plVar1 = (longlong *)
           duration<__int64,std::ratio<1,1000000000>_>::
           duration<__int64,std::ratio<1,1000000000>_><__int64,std::ratio<1,1>,0>(local_res8,in_R8);
  *(longlong *)param_1 = *(longlong *)param_2 + *plVar1;
  return param_1;
}



===== duration_cast<std::chrono::duration<__int64,std::ratio<1,1000000000>_>,__int64,std::ratio<1,1>,0> @ 14000e5b8 =====

/* class std::chrono::duration<__int64,struct std::ratio<1,1000000000> > __cdecl
   std::chrono::duration_cast<class std::chrono::duration<__int64,struct std::ratio<1,1000000000>
   >,__int64,struct std::ratio<1,1>,0>(class std::chrono::duration<__int64,struct std::ratio<1,1> >
   const & __ptr64) */

duration<__int64,std::ratio<1,1>_> * __cdecl
std::chrono::
duration_cast<std::chrono::duration<__int64,std::ratio<1,1000000000>_>,__int64,std::ratio<1,1>,0>
          (duration<__int64,std::ratio<1,1>_> *param_1)

{
  longlong *in_RDX;
  
  *(longlong *)param_1 = *in_RDX * 1000000000;
  return param_1;
}



===== ~Completer @ 14000e5d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl wil::details::static_lazy<class ComTrace>::Completer::~Completer(void) __ptr64 */

void __thiscall wil::details::static_lazy<ComTrace>::Completer::~Completer(Completer *this)

{
  longlong lVar1;
  
  if (*(int *)(this + 8) == 0) {
    lVar1 = *(longlong *)this;
    *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x20);
    *(undefined1 *)(lVar1 + 0x18) = 1;
    TraceLoggingRegisterEx_EtwEventRegister_EtwEventSetInformation(*(longlong *)(lVar1 + 0x20));
    *(undefined4 *)(lVar1 + 0x1c) = 1;
    (**(code **)(*(longlong *)(lVar1 + 8) + 8))(lVar1 + 8);
  }
                    /* WARNING: Could not recover jumptable at 0x00014000e623. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitOnceComplete(*(longlong *)this,*(undefined4 *)(this + 8),*(longlong *)this + 8);
  return;
}



===== ~TraceLoggingProvider @ 14000e638 =====

/* protected: virtual __cdecl wil::TraceLoggingProvider::~TraceLoggingProvider(void) __ptr64 */

void __thiscall wil::TraceLoggingProvider::~TraceLoggingProvider(TraceLoggingProvider *this)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  *(undefined ***)this = &_vftable_;
  if (this[0x10] != (TraceLoggingProvider)0x0) {
    puVar1 = *(undefined4 **)(this + 8);
    uVar2 = *(undefined8 *)(puVar1 + 8);
    *(undefined8 *)(puVar1 + 8) = 0;
    *puVar1 = 0;
    EtwEventUnregister(uVar2);
  }
  return;
}



===== `scalar_deleting_destructor' @ 14000e680 =====

/* public: virtual void * __ptr64 __cdecl ComTrace::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall ComTrace::_scalar_deleting_destructor_(ComTrace *this,uint param_1)

{
  wil::TraceLoggingProvider::~TraceLoggingProvider((TraceLoggingProvider *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x20);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000e6c0 =====

/* protected: virtual void * __ptr64 __cdecl wil::TraceLoggingProvider::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
wil::TraceLoggingProvider::_scalar_deleting_destructor_(TraceLoggingProvider *this,uint param_1)

{
  ~TraceLoggingProvider(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x18);
  }
  return this;
}



===== BreakIntoDebugger @ 14000e6fc =====

/* void __cdecl BreakIntoDebugger(void) */

void __cdecl BreakIntoDebugger(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== Error_ @ 14000e724 =====

/* public: void __cdecl ComTrace::Error_(long,unsigned short const * __ptr64,struct
   wil::DiagnosticsInfo const & __ptr64) __ptr64 */

void __thiscall
ComTrace::Error_(ComTrace *this,long param_1,ushort *param_2,DiagnosticsInfo *param_3)

{
  _tlgProvider_t *p_Var1;
  _GUID *p_Var2;
  _GUID *p_Var3;
  ComTrace *local_res8;
  long local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  ushort *local_20;
  undefined8 local_18 [2];
  
  p_Var2 = (_GUID *)param_2;
  p_Var3 = (_GUID *)param_3;
  local_res8 = this;
  p_Var1 = Provider();
  if (2 < *(uint *)p_Var1) {
    local_18[0] = 0;
    local_res8 = (ComTrace *)CONCAT62(local_res8._2_6_,*(undefined2 *)(param_3 + 0x18));
    local_30 = *(undefined8 *)(param_3 + 8);
    local_28 = *(undefined8 *)(param_3 + 0x10);
    local_38[0] = param_1;
    local_20 = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwEventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<2>_>
              (p_Var1,&DAT_14001577d,p_Var2,p_Var3,(_tlgWrapperByVal<4> *)local_38,
               (_tlgWrapSz<char> *)local_18,(_tlgWrapSz<unsigned_short> *)&local_20,
               (_tlgWrapSz<char> *)&local_28,(_tlgWrapSz<char> *)&local_30,
               (_tlgWrapperByVal<2> *)&local_res8);
  }
  return;
}



===== FormatTraceMessage @ 14000e7e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl FormatTraceMessage(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,char * __ptr64) */

void __cdecl FormatTraceMessage(ushort *param_1,__uint64 param_2,ushort *param_3,char *param_4)

{
  ushort *puVar1;
  wchar_t wVar2;
  int iVar3;
  long lVar4;
  longlong lVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  ulonglong uVar8;
  size_t _MaxCount;
  undefined **ppuVar9;
  undefined1 auStackY_2b8 [32];
  ulong in_stack_fffffffffffffd70;
  wchar_t *local_288;
  ulonglong local_280;
  ushort *local_278;
  char *local_270;
  wchar_t local_268 [256];
  ulonglong local_68;
  
  local_68 = __security_cookie ^ (ulonglong)auStackY_2b8;
  local_278 = param_3;
  local_270 = param_4;
  memset(local_268,0,0x200);
  local_288 = local_268;
  local_280 = 0x100;
LAB_14000e84d:
  while( true ) {
    wVar2 = *param_3;
    if (wVar2 == L'\0') {
      *local_288 = L'\0';
      StringCchVPrintfW(param_1,param_2,(ushort *)local_268,local_270);
      return;
    }
    if (local_280 < 2) goto LAB_14000e956;
    pwVar7 = (wchar_t *)(param_3 + 1);
    if (wVar2 != L'%') break;
    if (*pwVar7 == L'%') {
      if (local_280 < 3) goto LAB_14000e956;
      *local_288 = L'%';
      param_3 = param_3 + 2;
      local_288[1] = *pwVar7;
      local_288 = local_288 + 2;
      local_280 = local_280 - 2;
    }
    uVar8 = local_280;
    pwVar6 = local_288;
    ppuVar9 = &`void___cdecl_FormatTraceMessage(unsigned_short*___ptr64,unsigned___int64,unsigned_short_const*___ptr64,char*___ptr64)'
               ::__l2::specifierReplacements;
    while( true ) {
      if ((IMAGE_LOAD_CONFIG_DIRECTORY64 *)ppuVar9 == &_load_config_used) goto LAB_14000e943;
      pwVar7 = (wchar_t *)*ppuVar9;
      puVar1 = *(ushort **)&((IMAGE_LOAD_CONFIG_DIRECTORY64 *)ppuVar9)->MajorVersion;
      _MaxCount = 0xffffffffffffffff;
      do {
        _MaxCount = _MaxCount + 1;
      } while (pwVar7[_MaxCount] != L'\0');
      iVar3 = wcsncmp((wchar_t *)param_3,pwVar7,_MaxCount);
      if (iVar3 == 0) break;
      ppuVar9 = (undefined **)&((IMAGE_LOAD_CONFIG_DIRECTORY64 *)ppuVar9)->GlobalFlagsSet;
    }
    lVar4 = StringCchCopyExW((ushort *)pwVar6,uVar8,puVar1,(ushort **)&local_288,&local_280,
                             in_stack_fffffffffffffd70);
    if (lVar4 < 0) goto LAB_14000e956;
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (pwVar7[lVar5] != L'\0');
    param_3 = param_3 + lVar5;
  }
  pwVar6 = local_288;
  uVar8 = local_280;
  goto LAB_14000e870;
LAB_14000e943:
  if (param_3[1] == L'!') {
LAB_14000e956:
    StringCchPrintfW(param_1,param_2,(ushort *)L"Failed to handle format string %s",local_278);
    return;
  }
  wVar2 = *param_3;
  pwVar7 = (wchar_t *)(param_3 + 1);
LAB_14000e870:
  *pwVar6 = wVar2;
  local_288 = pwVar6 + 1;
  local_280 = uVar8 - 1;
  param_3 = (ushort *)pwVar7;
  goto LAB_14000e84d;
}



===== IsEnabled @ 14000e9bc =====

/* public: static bool __cdecl ComTrace::IsEnabled(unsigned char,unsigned __int64) */

bool __cdecl ComTrace::IsEnabled(uchar param_1,__uint64 param_2)

{
  int *piVar1;
  char cVar2;
  ComTrace *pCVar3;
  undefined7 in_register_00000009;
  undefined1 uVar4;
  
  pCVar3 = wil::details::static_lazy<ComTrace>::get
                     ((static_lazy<ComTrace> *)CONCAT71(in_register_00000009,param_1),
                      <lambda_f8a79a44bba2ee3470b25df359f31864>::<lambda_invoker_cdecl>);
  uVar4 = 0;
  piVar1 = *(int **)(pCVar3 + 8);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    uVar4 = 0;
    cVar2 = _tlgKeywordOn((longlong)piVar1,0);
    if (cVar2 != '\0') {
      uVar4 = 1;
    }
  }
  return (bool)uVar4;
}



===== NoisyError_ @ 14000e9fc =====

/* public: void __cdecl ComTrace::NoisyError_(long,unsigned short const * __ptr64,struct
   wil::DiagnosticsInfo const & __ptr64) __ptr64 */

void __thiscall
ComTrace::NoisyError_(ComTrace *this,long param_1,ushort *param_2,DiagnosticsInfo *param_3)

{
  _tlgProvider_t *p_Var1;
  _GUID *p_Var2;
  _GUID *p_Var3;
  ComTrace *local_res8;
  long local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  ushort *local_20;
  undefined8 local_18 [2];
  
  p_Var2 = (_GUID *)param_2;
  p_Var3 = (_GUID *)param_3;
  local_res8 = this;
  p_Var1 = Provider();
  if (0x65 < *(uint *)p_Var1) {
    local_18[0] = 0;
    local_res8 = (ComTrace *)CONCAT62(local_res8._2_6_,*(undefined2 *)(param_3 + 0x18));
    local_30 = *(undefined8 *)(param_3 + 8);
    local_28 = *(undefined8 *)(param_3 + 0x10);
    local_38[0] = param_1;
    local_20 = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwEventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<2>_>
              (p_Var1,&DAT_140015597,p_Var2,p_Var3,(_tlgWrapperByVal<4> *)local_38,
               (_tlgWrapSz<char> *)local_18,(_tlgWrapSz<unsigned_short> *)&local_20,
               (_tlgWrapSz<char> *)&local_28,(_tlgWrapSz<char> *)&local_30,
               (_tlgWrapperByVal<2> *)&local_res8);
  }
  return;
}



===== NotifyFailure @ 14000eac0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: virtual bool __cdecl wil::TraceLoggingProvider::NotifyFailure(struct wil::FailureInfo
   const & __ptr64) __ptr64 */

bool __thiscall
wil::TraceLoggingProvider::NotifyFailure(TraceLoggingProvider *this,FailureInfo *param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  bVar2 = `protected:_static_bool___cdecl_wil::TraceLoggingProvider::WasAlreadyReportedToTelemetry(long)'
          ::__l2::s_lastFailureSeen != iVar1;
  `protected:_static_bool___cdecl_wil::TraceLoggingProvider::WasAlreadyReportedToTelemetry(long)'::
  __l2::s_lastFailureSeen = iVar1;
  if (bVar2) {
    (**(code **)(*(longlong *)this + 0x10))(this,0,param_1);
  }
  return true;
}



===== OnErrorReported @ 14000eb00 =====

/* protected: virtual void __cdecl wil::TraceLoggingProvider::OnErrorReported(bool,struct
   wil::FailureInfo const & __ptr64) __ptr64 */

void __thiscall
wil::TraceLoggingProvider::OnErrorReported
          (TraceLoggingProvider *this,bool param_1,FailureInfo *param_2)

{
  if ((!param_1) && (((byte)param_2[4] & 2) == 0)) {
    if (*(int *)(this + 0x14) == 1) {
      ReportTelemetryFailure(this,param_2);
      return;
    }
    if (*(int *)(this + 0x14) == 2) {
      ReportTraceLoggingFailure(this,param_2);
    }
  }
  return;
}



===== Provider @ 14000eb3c =====

/* public: static struct _tlgProvider_t const * __ptr64 __cdecl ComTrace::Provider(void) */

_tlgProvider_t * __cdecl ComTrace::Provider(void)

{
  ComTrace *pCVar1;
  static_lazy<ComTrace> *in_RCX;
  
  pCVar1 = wil::details::static_lazy<ComTrace>::get
                     (in_RCX,<lambda_f8a79a44bba2ee3470b25df359f31864>::<lambda_invoker_cdecl>);
  return *(_tlgProvider_t **)(pCVar1 + 8);
}



===== ReportTelemetryFailure @ 14000eb5c =====

/* protected: void __cdecl wil::TraceLoggingProvider::ReportTelemetryFailure(struct wil::FailureInfo
   const & __ptr64) __ptr64 */

void __thiscall
wil::TraceLoggingProvider::ReportTelemetryFailure(TraceLoggingProvider *this,FailureInfo *param_1)

{
  char cVar1;
  _tlgProvider_t *p_Var2;
  _GUID *in_R8;
  undefined4 local_res8 [4];
  ulong local_res18 [2];
  ulong local_res20 [2];
  ulong local_68;
  ulong local_64;
  undefined4 local_60 [2];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  p_Var2 = *(_tlgProvider_t **)(this + 8);
  if (2 < *(uint *)p_Var2) {
    cVar1 = _tlgKeywordOn((longlong)p_Var2,0x200000000000);
    if (cVar1 != '\0') {
      local_58 = *(undefined8 *)((_GUID *)((longlong)param_1 + 0x70))->Data4;
      local_50._0_4_ = ((_GUID *)((longlong)param_1 + 0x70))->Data1;
      local_50._4_2_ = ((_GUID *)((longlong)param_1 + 0x70))->Data2;
      local_50._6_2_ = ((_GUID *)((longlong)param_1 + 0x70))->Data3;
      local_res8[0] = *(undefined4 *)((_GUID *)((longlong)param_1 + 0x60))->Data4;
      local_48._0_4_ = ((_GUID *)((longlong)param_1 + 0x60))->Data1;
      local_48._4_2_ = ((_GUID *)((longlong)param_1 + 0x60))->Data2;
      local_48._6_2_ = ((_GUID *)((longlong)param_1 + 0x60))->Data3;
      local_40 = *(undefined8 *)((_GUID *)((longlong)param_1 + 0x50))->Data4;
      local_res18[0] = ((_GUID *)((longlong)param_1 + 0x50))->Data1;
      local_38 = *(undefined8 *)((_GUID *)((longlong)param_1 + 0x40))->Data4;
      local_res20[0] = ((_GUID *)((longlong)param_1 + 0x20))->Data1;
      local_30 = *(undefined8 *)((_GUID *)((longlong)param_1 + 0x10))->Data4;
      local_68 = ((_GUID *)param_1)->Data1;
      local_28._0_4_ = ((_GUID *)((longlong)param_1 + 0x80))->Data1;
      local_28._4_2_ = ((_GUID *)((longlong)param_1 + 0x80))->Data2;
      local_28._6_2_ = ((_GUID *)((longlong)param_1 + 0x80))->Data3;
      local_64 = ((_GUID *)((longlong)param_1 + 0x40))->Data1;
      local_20 = *(undefined8 *)((_GUID *)((longlong)param_1 + 0x30))->Data4;
      local_60[0] = *(undefined4 *)((_GUID *)param_1)->Data4;
      local_18 = 0x1000000;
      local_10 = 0x1000000;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwEventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>_>
                (p_Var2,&DAT_1400155e8,in_R8,(_GUID *)param_1,(_tlgWrapperByVal<8> *)&local_10,
                 (_tlgWrapperByVal<8> *)&local_18,(_tlgWrapperByVal<4> *)local_60,
                 (_tlgWrapSz<char> *)&local_20,(_tlgWrapperByVal<4> *)&local_64,
                 (_tlgWrapSz<char> *)&local_28,(_tlgWrapperByVal<4> *)&local_68,
                 (_tlgWrapSz<unsigned_short> *)&local_30,(_tlgWrapperByVal<4> *)local_res20,
                 (_tlgWrapSz<char> *)&local_38,(_tlgWrapperByVal<4> *)local_res18,
                 (_tlgWrapSz<char> *)&local_40,(_tlgWrapSz<unsigned_short> *)&local_48,
                 (_tlgWrapperByVal<4> *)local_res8,(_tlgWrapSz<char> *)&local_50,
                 (_tlgWrapSz<unsigned_short> *)&local_58);
    }
  }
  return;
}



===== ReportTraceLoggingFailure @ 14000ecc4 =====

/* protected: void __cdecl wil::TraceLoggingProvider::ReportTraceLoggingFailure(struct
   wil::FailureInfo const & __ptr64) __ptr64 */

void __thiscall
wil::TraceLoggingProvider::ReportTraceLoggingFailure
          (TraceLoggingProvider *this,FailureInfo *param_1)

{
  _GUID *in_R8;
  _GUID *in_R9;
  undefined4 local_res8 [4];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18 [2];
  
  if (2 < *(uint *)*(_tlgProvider_t **)(this + 8)) {
    local_60 = *(undefined8 *)(param_1 + 0x30);
    local_res8[0] = *(undefined4 *)(param_1 + 0x44);
    local_res18[0] = *(undefined4 *)(param_1 + 0x10);
    local_58 = *(undefined8 *)(param_1 + 0x78);
    local_50 = *(undefined8 *)(param_1 + 0x70);
    local_res20[0] = *(undefined4 *)(param_1 + 0x68);
    local_48 = *(undefined8 *)(param_1 + 0x60);
    local_40 = *(undefined8 *)(param_1 + 0x58);
    local_78 = *(undefined4 *)(param_1 + 0x50);
    local_38 = *(undefined8 *)(param_1 + 0x48);
    local_74 = *(undefined4 *)(param_1 + 0x20);
    local_30 = *(undefined8 *)(param_1 + 0x18);
    local_70 = *(undefined4 *)param_1;
    local_28 = *(undefined8 *)(param_1 + 0x80);
    local_6c = *(undefined4 *)(param_1 + 0x40);
    local_20 = *(undefined8 *)(param_1 + 0x38);
    local_68[0] = *(undefined4 *)(param_1 + 8);
    local_18[0] = 0x1000000;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwEventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapSz<char>_>
              (*(_tlgProvider_t **)(this + 8),&DAT_140015461,in_R8,in_R9,
               (_tlgWrapperByVal<8> *)local_18,(_tlgWrapperByVal<4> *)local_68,
               (_tlgWrapSz<char> *)&local_20,(_tlgWrapperByVal<4> *)&local_6c,
               (_tlgWrapSz<char> *)&local_28,(_tlgWrapperByVal<4> *)&local_70,
               (_tlgWrapSz<unsigned_short> *)&local_30,(_tlgWrapperByVal<4> *)&local_74,
               (_tlgWrapSz<char> *)&local_38,(_tlgWrapperByVal<4> *)&local_78,
               (_tlgWrapSz<char> *)&local_40,(_tlgWrapSz<unsigned_short> *)&local_48,
               (_tlgWrapperByVal<4> *)local_res20,(_tlgWrapSz<char> *)&local_50,
               (_tlgWrapSz<unsigned_short> *)&local_58,(_tlgWrapperByVal<4> *)local_res18,
               (_tlgWrapperByVal<4> *)local_res8,(_tlgWrapSz<char> *)&local_60);
  }
  return;
}



===== Request @ 14000ee2c =====

/* public: enum RateLimiter::RequestResult __cdecl RateLimiter::Request(void) __ptr64 */

RequestResult __thiscall RateLimiter::Request(RateLimiter *this)

{
  longlong *plVar1;
  duration<__int64,std::ratio<1,1>_> *pdVar2;
  RequestResult RVar3;
  time_point<struct_std::chrono::steady_clock,class_std::chrono::duration<__int64,struct_std::ratio<1,1000000000>_>_>
  local_res10 [24];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_140019380);
  plVar1 = (longlong *)std::chrono::steady_clock::now();
  if (*plVar1 < DAT_140019378) {
    RVar3 = 1;
  }
  else {
    plVar1 = (longlong *)std::chrono::steady_clock::now();
    if (*plVar1 < DAT_140019368) {
      DAT_140019370 = DAT_140019370 + 1;
      if (DAT_140019350 < DAT_140019370) {
        pdVar2 = (duration<__int64,std::ratio<1,1>_> *)std::chrono::steady_clock::now();
        plVar1 = (longlong *)
                 std::chrono::
                 operator+<std::chrono::steady_clock,std::chrono::duration<__int64,std::ratio<1,1000000000>_>,__int64,std::ratio<1,1>_>
                           (local_res10,pdVar2);
        RVar3 = 2;
        DAT_140019378 = *plVar1;
        goto LAB_14000eef9;
      }
    }
    else {
      DAT_140019370 = 1;
      pdVar2 = (duration<__int64,std::ratio<1,1>_> *)std::chrono::steady_clock::now();
      plVar1 = (longlong *)
               std::chrono::
               operator+<std::chrono::steady_clock,std::chrono::duration<__int64,std::ratio<1,1000000000>_>,__int64,std::ratio<1,1>_>
                         (local_res10,pdVar2);
      DAT_140019368 = *plVar1;
    }
    RVar3 = 0;
  }
LAB_14000eef9:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_140019380);
  return RVar3;
}



===== StringCchCopyExW @ 14000ef1c =====

/* long __cdecl StringCchCopyExW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,unsigned short * __ptr64 * __ptr64,unsigned __int64 * __ptr64,unsigned long) */

long __cdecl
StringCchCopyExW(ushort *param_1,__uint64 param_2,ushort *param_3,ushort **param_4,__uint64 *param_5
                ,ulong param_6)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  longlong lVar5;
  __uint64 _Var6;
  longlong lVar7;
  
  lVar7 = 0;
  puVar4 = param_3;
  uVar3 = StringExValidateDestW((STRSAFE_PCNZWCH)param_1,param_2,(size_t)param_3,0);
  if ((int)uVar3 < 0) {
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  else {
    uVar3 = 0;
    if (param_2 == 0) {
      _Var6 = 0;
      if (*puVar4 != 0) {
        if (param_1 == (ushort *)0x0) {
          return -0x7ff8ffa9;
        }
        uVar3 = 0x8007007a;
      }
    }
    else {
      puVar4 = param_1;
      _Var6 = param_2;
      do {
        if (((0x7ffffffe - param_2) + _Var6 == 0) ||
           (uVar1 = *(ushort *)(((longlong)param_3 - (longlong)param_1) + (longlong)puVar4),
           uVar1 == 0)) break;
        *puVar4 = uVar1;
        lVar7 = lVar7 + 1;
        puVar4 = puVar4 + 1;
        _Var6 = _Var6 - 1;
      } while (_Var6 != 0);
      lVar5 = lVar7 + -1;
      puVar2 = puVar4 + -1;
      if (_Var6 != 0) {
        lVar5 = lVar7;
        puVar2 = puVar4;
      }
      *puVar2 = 0;
      param_1 = param_1 + lVar5;
      uVar3 = ~-(uint)(_Var6 != 0) & 0x8007007a;
      _Var6 = param_2 - lVar5;
    }
    if (param_4 != (ushort **)0x0) {
      *param_4 = param_1;
    }
    if (param_5 != (__uint64 *)0x0) {
      *param_5 = _Var6;
    }
  }
  return uVar3;
}



===== StringCchPrintfExW @ 14000f004 =====

/* long __cdecl StringCchPrintfExW(unsigned short * __ptr64,unsigned __int64,unsigned short *
   __ptr64 * __ptr64,unsigned __int64 * __ptr64,unsigned long,unsigned short const * __ptr64,...) */

long __cdecl
StringCchPrintfExW(ushort *param_1,__uint64 param_2,ushort **param_3,__uint64 *param_4,ulong param_5
                  ,ushort *param_6,...)

{
  HRESULT HVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  size_t _Count;
  __uint64 *p_Var5;
  STRSAFE_LPWSTR pszDestEnd;
  size_t sVar6;
  char cStack0000000000000038;
  STRSAFE_LPWSTR local_58;
  size_t local_50 [2];
  
  p_Var5 = param_4;
  HVar1 = StringExValidateDestW((STRSAFE_PCNZWCH)param_1,param_2,(size_t)param_3,param_5);
  if (HVar1 < 0) {
    if (param_2 == 0) {
      return HVar1;
    }
    *param_1 = 0;
    return HVar1;
  }
  if (((param_5 >> 8 & 1) != 0) && (param_6 == (ushort *)0x0)) {
    param_6 = (ushort *)L"";
  }
  iVar4 = 0;
  if ((param_5 & 0xffffe000) == 0) {
    if (param_2 == 0) {
      if (*param_6 == L'\0') goto LAB_14000f0d3;
      iVar4 = (-(uint)(param_1 != (ushort *)0x0) & 0x23) + 0x80070057;
      local_58 = (STRSAFE_LPWSTR)param_1;
      local_50[0] = param_2;
      goto LAB_14000f083;
    }
    local_50[0] = 0;
    _Count = param_2 - 1;
    local_58 = (STRSAFE_LPWSTR)param_1;
    iVar2 = _vsnwprintf((wchar_t *)param_1,_Count,(wchar_t *)param_6,&cStack0000000000000038);
    if (iVar2 < 0) {
LAB_14000f13d:
      iVar4 = -0x7ff8ff86;
LAB_14000f142:
      param_1[_Count] = 0;
    }
    else {
      uVar3 = (ulonglong)iVar2;
      if (_Count < uVar3) goto LAB_14000f13d;
      if (uVar3 == _Count) goto LAB_14000f142;
      _Count = uVar3;
    }
    sVar6 = param_2 - _Count;
    pszDestEnd = (STRSAFE_LPWSTR)(param_1 + _Count);
    local_58 = pszDestEnd;
    local_50[0] = sVar6;
    if (iVar4 < 0) goto LAB_14000f083;
    if (((param_5 >> 9 & 1) != 0) && (1 < sVar6)) {
      StringExHandleFillBehindNullW(pszDestEnd,sVar6 * 2,param_5);
    }
  }
  else {
    iVar4 = -0x7ff8ffa9;
    local_58 = (STRSAFE_LPWSTR)param_1;
    local_50[0] = param_2;
    if (param_2 != 0) {
      *param_1 = 0;
      local_58 = (STRSAFE_LPWSTR)param_1;
      local_50[0] = param_2;
    }
LAB_14000f083:
    pszDestEnd = local_58;
    sVar6 = local_50[0];
    if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
      StringExHandleOtherFlagsW
                ((STRSAFE_LPWSTR)param_1,param_2 * 2,(size_t)param_6,&local_58,local_50,param_5);
      pszDestEnd = local_58;
      sVar6 = local_50[0];
    }
    if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x7ff8ff86)) {
      return iVar4;
    }
  }
  p_Var5 = param_4;
  param_1 = (ushort *)pszDestEnd;
  param_2 = sVar6;
LAB_14000f0d3:
  if (param_3 != (ushort **)0x0) {
    *param_3 = param_1;
  }
  if (p_Var5 != (__uint64 *)0x0) {
    *p_Var5 = param_2;
  }
  return iVar4;
}



===== StringExHandleFillBehindNullW @ 14000f1a8 =====

HRESULT __stdcall
StringExHandleFillBehindNullW(STRSAFE_LPWSTR pszDestEnd,size_t cbRemaining,DWORD dwFlags)

{
  if (2 < cbRemaining) {
    memset(pszDestEnd + 1,dwFlags & 0xff,cbRemaining - 2);
  }
  return 0;
}



===== StringExHandleOtherFlagsW @ 14000f1d4 =====

HRESULT __stdcall
StringExHandleOtherFlagsW
          (STRSAFE_LPWSTR pszDest,size_t cbDest,size_t cchOriginalDestLength,
          STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,DWORD dwFlags)

{
  ulonglong uVar1;
  
  uVar1 = cbDest >> 1;
  if ((uVar1 != 0) && ((dwFlags & 0x1000) != 0)) {
    *ppszDestEnd = pszDest;
    *pcchRemaining = uVar1;
    *pszDest = L'\0';
  }
  if ((dwFlags & 0x400) != 0) {
    memset(pszDest,dwFlags & 0xff,cbDest);
    if ((char)dwFlags != '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      *pcchRemaining = 1;
      *ppszDestEnd = pszDest + (uVar1 - 1);
      pszDest[uVar1 - 1] = L'\0';
      goto LAB_14000f23f;
    }
    *ppszDestEnd = pszDest;
    *pcchRemaining = uVar1;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_14000f23f:
  if ((dwFlags & 0x800) != 0) {
    *ppszDestEnd = pszDest;
    *pcchRemaining = uVar1;
    *pszDest = L'\0';
  }
  return 0;
}



===== StringExValidateDestW @ 14000f294 =====

HRESULT __stdcall
StringExValidateDestW(STRSAFE_PCNZWCH pszDest,size_t cchDest,size_t cchMax,DWORD dwFlags)

{
  HRESULT HVar1;
  
  HVar1 = 0;
  if ((dwFlags >> 8 & 1) == 0) {
    HVar1 = 0;
    if (0x7ffffffe < cchDest - 1) {
      HVar1 = -0x7ff8ffa9;
    }
  }
  else if (((pszDest == (STRSAFE_PCNZWCH)0x0) && (cchDest != 0)) || (0x7fffffff < cchDest)) {
    return -0x7ff8ffa9;
  }
  return HVar1;
}



===== TraceAllowedByRateLimiter @ 14000f2d4 =====

/* bool __cdecl TraceAllowedByRateLimiter(void) */

bool __cdecl TraceAllowedByRateLimiter(void)

{
  bool bVar1;
  RequestResult RVar2;
  ComTrace *this;
  __uint64 in_RDX;
  
  this = (ComTrace *)0x4;
  if (*(int *)(*(longlong *)ThreadLocalStoragePointer + 4) < DAT_140019d80) {
    this = (ComTrace *)&DAT_140019d80;
    _Init_thread_header(&DAT_140019d80);
    if (DAT_140019d80 == -1) {
      std::chrono::steady_clock::now();
      DAT_140019370 = 0;
      std::chrono::steady_clock::now();
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_140019380);
      atexit(`TraceAllowedByRateLimiter'::__l2::
             _dynamic_atexit_destructor_for__s_comtraceRateLimiter__);
      this = (ComTrace *)&DAT_140019d80;
      _Init_thread_footer(&DAT_140019d80);
    }
  }
  RVar2 = RateLimiter::Request((RateLimiter *)this);
  if (RVar2 == 2) {
    bVar1 = ComTrace::IsEnabled((uchar)this,in_RDX);
    if (bVar1) {
      wil::details::static_lazy<ComTrace>::get
                ((static_lazy<ComTrace> *)this,
                 <lambda_f8a79a44bba2ee3470b25df359f31864>::<lambda_invoker_cdecl>);
      ComTrace::TracesRateLimited_(this);
    }
  }
  return RVar2 == 0;
}



===== TracesRateLimited_ @ 14000f390 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl ComTrace::TracesRateLimited_(void) __ptr64 */

void __thiscall ComTrace::TracesRateLimited_(ComTrace *this)

{
  _tlgProvider_t *p_Var1;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  p_Var1 = Provider();
  if (2 < *(uint *)p_Var1) {
    _tlgWriteTransfer_EtwEventWriteTransfer((longlong)p_Var1,&DAT_14001570b,0,0,2,local_38);
  }
  return;
}



===== Warning_ @ 14000f3f0 =====

/* public: void __cdecl ComTrace::Warning_(long,unsigned short const * __ptr64,struct
   wil::DiagnosticsInfo const & __ptr64) __ptr64 */

void __thiscall
ComTrace::Warning_(ComTrace *this,long param_1,ushort *param_2,DiagnosticsInfo *param_3)

{
  _tlgProvider_t *p_Var1;
  _GUID *p_Var2;
  _GUID *p_Var3;
  ComTrace *local_res8;
  long local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  ushort *local_20;
  undefined8 local_18 [2];
  
  p_Var2 = (_GUID *)param_2;
  p_Var3 = (_GUID *)param_3;
  local_res8 = this;
  p_Var1 = Provider();
  if (3 < *(uint *)p_Var1) {
    local_18[0] = 0;
    local_res8 = (ComTrace *)CONCAT62(local_res8._2_6_,*(undefined2 *)(param_3 + 0x18));
    local_30 = *(undefined8 *)(param_3 + 8);
    local_28 = *(undefined8 *)(param_3 + 0x10);
    local_38[0] = param_1;
    local_20 = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwEventWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<4>,_tlgWrapSz<char>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<2>_>
              (p_Var1,&DAT_14001572c,p_Var2,p_Var3,(_tlgWrapperByVal<4> *)local_38,
               (_tlgWrapSz<char> *)local_18,(_tlgWrapSz<unsigned_short> *)&local_20,
               (_tlgWrapSz<char> *)&local_28,(_tlgWrapSz<char> *)&local_30,
               (_tlgWrapperByVal<2> *)&local_res8);
  }
  return;
}



===== get @ 14000f4ac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class ComTrace * __ptr64 __cdecl wil::details::static_lazy<class ComTrace>::get(void
   (__cdecl*)(void)) __ptr64 */

ComTrace * __thiscall
wil::details::static_lazy<ComTrace>::get(static_lazy<ComTrace> *this,_func_void *param_1)

{
  BOOL BVar1;
  ulonglong local_res8;
  ComTrace *local_res18 [2];
  static_lazy<ComTrace> *local_18;
  undefined4 local_10;
  
  local_res18[0] = (ComTrace *)0x0;
  local_res8 = (ulonglong)this & 0xffffffff00000000;
  BVar1 = InitOnceBeginInitialize
                    ((LPINIT_ONCE)
                     &`protected:_static_class_ComTrace*___ptr64___cdecl_ComTrace::Instance(void)'::
                      __l2::wrapper,0,(PBOOL)&local_res8,local_res18);
  if ((BVar1 != 0) && ((int)local_res8 != 0)) {
    _DAT_140019d58 = 0;
    _DAT_140019d64 = 0;
    local_res18[0] = (ComTrace *)&DAT_140019d50;
    _DAT_140019d50 = &ComTrace::_vftable_;
    local_18 = &`protected:_static_class_ComTrace*___ptr64___cdecl_ComTrace::Instance(void)'::__l2::
                wrapper;
    DAT_140019d60 = 0;
    _DAT_140019d68 =
         &`public:___cdecl_ComTrace::StaticHandle::StaticHandle(void)___ptr64'::__l2::__hInner;
    atexit((_func_5014 *)param_1);
    local_10 = 0;
    Completer::~Completer((Completer *)&local_18);
  }
  return local_res18[0];
}



===== now @ 14000f564 =====

/* public: static class std::chrono::time_point<struct std::chrono::steady_clock,class
   std::chrono::duration<__int64,struct std::ratio<1,1000000000> > > __cdecl
   std::chrono::steady_clock::now(void) */

void __cdecl std::chrono::steady_clock::now(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong *in_RCX;
  longlong lVar3;
  
  lVar1 = _Query_perf_frequency();
  lVar2 = _Query_perf_counter();
  if (lVar1 == 10000000) {
    lVar2 = lVar2 * 100;
  }
  else {
    if (lVar1 == 24000000) {
      lVar1 = lVar2 + SUB168(SEXT816(-0x4d0b03f86b6f730d) * SEXT816(lVar2),8);
      lVar3 = (lVar1 >> 0x18) - (lVar1 >> 0x3f);
      lVar1 = (lVar2 + lVar3 * -24000000) * 1000000000;
      lVar1 = SUB168(SEXT816(-0x4d0b03f86b6f730d) * SEXT816(lVar1),8) + lVar1;
      *in_RCX = ((lVar1 >> 0x18) - (lVar1 >> 0x3f)) + lVar3 * 1000000000;
      return;
    }
    lVar2 = ((lVar2 % lVar1) * 1000000000) / lVar1 + (lVar2 / lVar1) * 1000000000;
  }
  *in_RCX = lVar2;
  return;
}



===== ComTraceMessageWorker @ 14000f63c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ComTraceMessageWorker
               (int param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,uint param_5,
               ushort *param_6,char *param_7)

{
  bool bVar1;
  BOOL BVar2;
  undefined8 uVar3;
  wchar_t *pwVar4;
  ulonglong uVar5;
  uint uVar6;
  static_lazy<ComTrace> *psVar7;
  undefined2 uVar8;
  __uint64 _Var9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  wchar_t *pwVar12;
  undefined1 uStack0000000000000000;
  undefined1 auStack_8c8 [80];
  undefined4 local_878;
  wchar_t awStack_870 [984];
  undefined8 uStack_c0;
  undefined1 local_b8 [80];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined2 local_50;
  __uint64 local_48;
  wchar_t *local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)&local_68;
  if ((g_hrToDebug != 0) && (param_1 == g_hrToDebug)) {
    uStack_c0 = 0x14000f696;
    BVar2 = IsDebuggerPresent();
    if ((BVar2 != 0) || (DAT_7ffe02d4 != '\0')) {
      uStack_c0 = 0x14000f6ad;
      BreakIntoDebugger();
    }
  }
  puVar11 = local_b8;
  if (((gfEnableTracing == 0) && (1 < param_5)) && (param_5 != 7)) goto LAB_14000fa18;
  local_48 = 0x400;
  puVar10 = local_b8;
  if ((g_ulMaxStackAllocSize < 0x800) ||
     (puVar10 = local_b8, g_ulAdditionalProbeSize + 0x808U < 0x800)) {
LAB_14000f71a:
    *(undefined8 *)(puVar10 + -8) = 0x14000f72b;
    pwVar4 = (wchar_t *)(*g_pfnAllocate)(0x808);
    puVar11 = puVar10;
    if (pwVar4 != (wchar_t *)0x0) {
      pwVar4[0] = L'效';
      pwVar4[1] = L'灡';
      pwVar4 = pwVar4 + 4;
    }
  }
  else {
    uStack_c0 = 0x14000f6f3;
    uVar3 = VerifyStackAvailable(g_ulAdditionalProbeSize + 0x808U);
    puVar10 = local_b8;
    if ((int)uVar3 == 0) goto LAB_14000f71a;
    puVar10 = auStack_8c8;
    if (&uStack0000000000000000 == (undefined1 *)0x878) goto LAB_14000f71a;
    local_878 = 0x6b637453;
    pwVar4 = awStack_870;
    puVar10 = auStack_8c8;
    puVar11 = auStack_8c8;
    if (pwVar4 == (wchar_t *)0x0) goto LAB_14000f71a;
  }
  if (pwVar4 == (wchar_t *)0x0) goto LAB_14000fa18;
  *(undefined8 *)(puVar11 + -8) = 0x14000f754;
  pwVar12 = pwVar4;
  local_40 = pwVar4;
  uVar5 = IsWppLevelEnabled(param_5);
  _Var9 = 0x400;
  if ((char)uVar5 != '\0') {
    *(undefined4 *)(puVar11 + 0x40) = param_4;
    *(undefined8 *)(puVar11 + 0x38) = param_3;
    *(undefined8 *)(puVar11 + 0x30) = param_2;
    *(wchar_t **)(puVar11 + 0x28) = L"(%S):(%S):(%d) ";
    *(undefined8 *)(puVar11 + 0x20) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x14000f78c;
    StringCchPrintfExW((ushort *)pwVar4,0x400,(ushort **)&local_40,&local_48,
                       *(ulong *)(puVar11 + 0x20),*(ushort **)(puVar11 + 0x28));
    _Var9 = local_48;
    pwVar12 = local_40;
  }
  *(undefined8 *)(puVar11 + -8) = 0x14000f7ad;
  FormatTraceMessage((ushort *)pwVar12,_Var9,param_6,param_7);
  uVar8 = (undefined2)param_4;
  psVar7 = (static_lazy<ComTrace> *)WPP_GLOBAL_Control;
  if (param_5 == 0) {
LAB_14000f7f0:
    psVar7 = (static_lazy<ComTrace> *)WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      psVar7 = *(static_lazy<ComTrace> **)(WPP_GLOBAL_Control + 0x10);
      _Var9 = 10;
      *(undefined8 *)(puVar11 + -8) = 0x14000f81a;
      WPP_SF_S(psVar7,10,param_6,pwVar4);
    }
LAB_14000f81a:
    if (param_5 < 2) {
LAB_14000f81f:
      *(undefined8 *)(puVar11 + -8) = 0x14000f824;
      bVar1 = TraceAllowedByRateLimiter();
      if (bVar1) goto LAB_14000f828;
LAB_14000f842:
      local_68 = 0;
      *(undefined8 *)(puVar11 + -8) = 0x14000f858;
      local_60 = param_2;
      local_58 = param_3;
      local_50 = uVar8;
      bVar1 = ComTrace::IsEnabled((uchar)psVar7,_Var9);
      if (bVar1) {
        *(undefined8 *)(puVar11 + -8) = 0x14000f86c;
        wil::details::static_lazy<ComTrace>::get
                  (psVar7,<lambda_f8a79a44bba2ee3470b25df359f31864>::<lambda_invoker_cdecl>);
        *(undefined8 *)(puVar11 + -8) = 0x14000f87b;
        ComTrace::NoisyError_
                  ((ComTrace *)psVar7,param_1,(ushort *)pwVar4,(DiagnosticsInfo *)&local_68);
      }
    }
    else {
LAB_14000f828:
      if (param_5 == 0) {
        local_68 = 0;
        *(undefined8 *)(puVar11 + -8) = 0x14000f9e1;
        local_60 = param_2;
        local_58 = param_3;
        local_50 = uVar8;
        bVar1 = ComTrace::IsEnabled((uchar)psVar7,_Var9);
        if (bVar1) {
          *(undefined8 *)(puVar11 + -8) = 0x14000f9f1;
          wil::details::static_lazy<ComTrace>::get
                    (psVar7,<lambda_f8a79a44bba2ee3470b25df359f31864>::<lambda_invoker_cdecl>);
          *(undefined8 *)(puVar11 + -8) = 0x14000fa00;
          ComTrace::Error_((ComTrace *)psVar7,param_1,(ushort *)pwVar4,(DiagnosticsInfo *)&local_68)
          ;
        }
      }
      else if (param_5 == 1) {
        local_68 = 0;
        *(undefined8 *)(puVar11 + -8) = 0x14000f9aa;
        local_60 = param_2;
        local_58 = param_3;
        local_50 = uVar8;
        bVar1 = ComTrace::IsEnabled((uchar)psVar7,_Var9);
        if (bVar1) {
          *(undefined8 *)(puVar11 + -8) = 0x14000f9ba;
          wil::details::static_lazy<ComTrace>::get
                    (psVar7,<lambda_f8a79a44bba2ee3470b25df359f31864>::<lambda_invoker_cdecl>);
          *(undefined8 *)(puVar11 + -8) = 0x14000f9c9;
          ComTrace::Warning_((ComTrace *)psVar7,param_1,(ushort *)pwVar4,
                             (DiagnosticsInfo *)&local_68);
        }
      }
      else if (param_5 == 7) goto LAB_14000f842;
    }
  }
  else {
    if (param_5 == 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 2) != 0)) {
        psVar7 = *(static_lazy<ComTrace> **)(WPP_GLOBAL_Control + 0x10);
        _Var9 = 0xb;
        *(undefined8 *)(puVar11 + -8) = 0x14000f98f;
        WPP_SF_S(psVar7,0xb,param_6,pwVar4);
      }
      goto LAB_14000f81f;
    }
    if (param_5 == 2) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
        uVar8 = 0xc;
LAB_14000f8a6:
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x10);
        *(undefined8 *)(puVar11 + -8) = 0x14000f8b2;
        WPP_SF_S(uVar3,uVar8,param_6,pwVar4);
      }
    }
    else if (param_5 == 3) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 8) != 0)) {
        uVar8 = 0xd;
        goto LAB_14000f8a6;
      }
    }
    else if (param_5 == 4) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 0x10) != 0)) {
        uVar8 = 0xe;
        goto LAB_14000f8a6;
      }
    }
    else if (param_5 == 5) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 0x20) != 0)) {
        uVar8 = 0xf;
        goto LAB_14000f8a6;
      }
    }
    else {
      uVar6 = param_5 - 6;
      if (uVar6 != 0) {
        psVar7 = (static_lazy<ComTrace> *)(ulonglong)uVar6;
        if (uVar6 == 1) goto LAB_14000f7f0;
        goto LAB_14000f81a;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 0x40) != 0)) {
        uVar8 = 0x10;
        goto LAB_14000f8a6;
      }
    }
  }
  if (*(int *)(pwVar4 + -4) == 0x70616548) {
    *(undefined8 *)(puVar11 + -8) = 0x14000fa18;
    (*g_pfnFree)();
  }
LAB_14000fa18:
  *(undefined8 *)(puVar11 + -8) = 0x14000fa24;
  return;
}



===== IsWppLevelEnabled @ 14000fa48 =====

ulonglong IsWppLevelEnabled(int param_1)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      uVar1 = (ulonglong)(*(uint *)(WPP_GLOBAL_Control + 0x1c) >> 1);
      goto LAB_14000fada;
    }
    if (param_1 == 2) {
      uVar1 = (ulonglong)(*(uint *)(WPP_GLOBAL_Control + 0x1c) >> 2);
      goto LAB_14000fada;
    }
    if (param_1 == 3) {
      uVar1 = (ulonglong)(*(uint *)(WPP_GLOBAL_Control + 0x1c) >> 3);
      goto LAB_14000fada;
    }
    if (param_1 == 4) {
      uVar1 = (ulonglong)(*(uint *)(WPP_GLOBAL_Control + 0x1c) >> 4);
      goto LAB_14000fada;
    }
    if (param_1 == 5) {
      uVar1 = (ulonglong)(*(uint *)(WPP_GLOBAL_Control + 0x1c) >> 5);
      goto LAB_14000fada;
    }
    if (param_1 == 6) {
      uVar1 = (ulonglong)(*(uint *)(WPP_GLOBAL_Control + 0x1c) >> 6);
      goto LAB_14000fada;
    }
    if (param_1 != 7) {
      return in_RAX & 0xffffffffffffff00;
    }
  }
  uVar1 = CONCAT71((int7)((ulonglong)WPP_GLOBAL_Control >> 8),WPP_GLOBAL_Control[0x1c]);
LAB_14000fada:
  return uVar1 & 0xffffffffffffff01;
}



===== WPP_SF_S @ 14000fae4 =====

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  EtwTraceMessage(param_1,0x2b,&WPP_daf89ec1dff2305560ab63d4c11b3d9c_Traceguids,param_2,param_4,
                  lVar1,0);
  return;
}



===== InternalVerifyStackAvailable @ 14000fb54 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InternalVerifyStackAvailable(ulonglong param_1)

{
  ulonglong uVar1;
  undefined8 auStack_40 [7];
  
  uVar1 = param_1 + 0xf;
  if (uVar1 <= param_1) {
    uVar1 = 0xffffffffffffff0;
  }
  *(undefined8 *)((longlong)auStack_40 - (uVar1 & 0xfffffffffffffff0)) = 0x14000fb98;
  return;
}



===== VerifyStackAvailable @ 14000fba8 =====

undefined8 VerifyStackAvailable(ulonglong param_1)

{
  InternalVerifyStackAvailable(param_1);
  return 1;
}



===== _resetstkoflw_static @ 14000fbd4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool _resetstkoflw_static(void)

{
  PVOID pvVar1;
  DWORD DVar2;
  BOOL BVar3;
  uint uVar4;
  SIZE_T SVar5;
  LPVOID pvVar6;
  uint uVar7;
  ulonglong uVar8;
  LPVOID lpAddress;
  undefined1 local_98 [16];
  ULONG local_88;
  DWORD local_84;
  _MEMORY_BASIC_INFORMATION local_80;
  _SYSTEM_INFO local_50;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)&local_88;
  local_80.BaseAddress = (PVOID)0x0;
  local_80.AllocationBase = (PVOID)0x0;
  local_84 = 0;
  local_80.AllocationProtect = 0;
  local_80._20_4_ = 0;
  local_80.RegionSize = 0;
  local_88 = 0;
  local_80.State = 0;
  local_80.Protect = 0;
  local_80.Type = 0;
  local_80._44_4_ = 0;
  local_50.u.dwOemId = 0;
  local_50.dwPageSize = 0;
  local_50.lpMinimumApplicationAddress = (LPVOID)0x0;
  local_50.lpMaximumApplicationAddress = (LPVOID)0x0;
  local_50.dwActiveProcessorMask = 0;
  local_50.dwNumberOfProcessors = 0;
  local_50.dwProcessorType = 0;
  local_50.dwAllocationGranularity = 0;
  local_50.wProcessorLevel = 0;
  local_50.wProcessorRevision = 0;
  SVar5 = VirtualQuery(local_98,&local_80,0x30);
  pvVar1 = local_80.AllocationBase;
  if (SVar5 != 0) {
    GetSystemInfo(&local_50);
    DVar2 = local_50.dwPageSize;
    uVar8 = (ulonglong)local_50.dwPageSize;
    BVar3 = SetThreadStackGuarantee(&local_88);
    uVar4 = 0;
    if ((BVar3 == 1) && (uVar4 = 0, local_88 != 0)) {
      uVar4 = local_88;
    }
    uVar7 = (DVar2 - 1) + uVar4;
    if (uVar4 <= uVar7) {
      uVar7 = uVar7 & ~(DVar2 - 1);
      uVar4 = uVar7;
      if ((uVar7 != 0) && (uVar4 = uVar7 + DVar2, uVar4 < uVar7)) {
        return false;
      }
      uVar7 = DVar2 * 3;
      if (DVar2 * 3 <= uVar4) {
        uVar7 = uVar4;
      }
      lpAddress = (LPVOID)((~(ulonglong)(DVar2 - 1) & (ulonglong)local_98) - (ulonglong)uVar7);
      if (((LPVOID)((longlong)pvVar1 + uVar8) <= lpAddress) &&
         (pvVar6 = VirtualAlloc(lpAddress,(ulonglong)uVar7,0x1000,4), pvVar6 != (LPVOID)0x0)) {
        BVar3 = VirtualProtect(lpAddress,(ulonglong)uVar7,0x104,&local_84);
        return BVar3 != 0;
      }
    }
  }
  return false;
}



===== __GSHandlerCheck @ 14000fd5c =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000fd80 =====

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



===== __chkstk @ 14000fdf0 =====

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



===== memcmp @ 14000fe44 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000fe44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}



===== memcpy @ 14000fe50 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000fe50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memmove @ 14000fe5c =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000fe5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



===== _guard_dispatch_icall @ 14000fe90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000feb0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000feb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000fed0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== filt$0 @ 14000fedc =====

void `__scrt_common_main_seh'::__l1::filt_0(undefined8 *param_1)

{
  _o__seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}



===== catch$0 @ 14000ff00 =====

undefined * `operator_new'::__l1::catch_0(void)

{
  return &DAT_140009318;
}



===== __scrt_is_nonwritable_in_current_image$filt$0 @ 14000ff21 =====

bool __scrt_is_nonwritable_in_current_image_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== VerifyStackAvailable$filt$0 @ 14000ff3f =====

bool VerifyStackAvailable_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff03;
}



===== `dynamic_atexit_destructor_for_'g_featureStateManager'' @ 14000ff70 =====

void wil::details::_dynamic_atexit_destructor_for__g_featureStateManager__(void)

{
  bool bVar1;
  
  bVar1 = ProcessShutdownInProgress();
  if (bVar1) {
    g_featureStateManager = (shutdown_aware_object<wil::details::FeatureStateManager>)0x0;
    details_abi::ProcessLocalStorage<wil::details_abi::FeatureStateData>::
    ~ProcessLocalStorage<wil::details_abi::FeatureStateData>
              ((ProcessLocalStorage<wil::details_abi::FeatureStateData> *)
               &PTR_s_WilStaging_02_1400190c0);
    return;
  }
  FeatureStateManager::~FeatureStateManager((FeatureStateManager *)&g_featureStateManager);
  return;
}



===== `dynamic_atexit_destructor_for_'g_enabledStateManager'' @ 14000ffb0 =====

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



===== `dynamic_atexit_destructor_for_'g_processLocalData'' @ 14000fff0 =====

void wil::details::_dynamic_atexit_destructor_for__g_processLocalData__(void)

{
  if (DAT_1400191c8 != (ProcessLocalStorageData<wil::details_abi::ProcessLocalData> *)0x0) {
    details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Release(DAT_1400191c8)
    ;
  }
  return;
}



===== s_brokerAumid'' @ 140010020 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void `dynamic_atexit_destructor_for_'CRuntimeBroker::s_brokerAumid__(void)

{
  WindowsDeleteString(_s_brokerAumid);
  _s_brokerAumid = 0;
  return;
}



===== `dynamic_atexit_destructor_for_'s_comtraceRateLimiter'' @ 140010050 =====

void `TraceAllowedByRateLimiter'::__l2::_dynamic_atexit_destructor_for__s_comtraceRateLimiter__
               (void)

{
                    /* WARNING: Could not recover jumptable at 0x000140010057. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_140019380);
  return;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 140011010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


