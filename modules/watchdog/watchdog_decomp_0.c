
===== Write<_tlgWrapSz<char>,_tlgWrapperByVal<4>_> @ 140001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t const
   * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapSz<char>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<char> *param_5,_tlgWrapperByVal<4> *param_6)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
  char *local_38;
  int local_30;
  undefined4 local_2c;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = param_6;
  local_20 = 4;
  local_38 = *(char **)param_5;
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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,param_2,param_3,&DAT_14000ea00,4,local_58);
  return lVar1;
}



===== Write<_tlgWrapperByVal<4>_> @ 1400010b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<4>
   const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<4> *param_5)

{
  long lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [4];
  _tlgWrapperByVal<4> *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_1c = 0;
  local_28 = param_5;
  local_20 = 4;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,param_2,param_3,0,3,local_48);
  return lVar1;
}



===== Write<_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>_> @ 14000111c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<4>,struct _tlgWrapperBinary,struct _tlgWrapperByVal<4>
   >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct
   _GUID const * __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<4> *param_5,_tlgWrapperBinary *param_6,_tlgWrapperByVal<4> *param_7)

{
  long lVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [4];
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30 [2];
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_28 = param_7;
  local_48 = local_30;
  local_38 = *(undefined8 *)param_6;
  local_30[0] = (uint)*(ushort *)(param_6 + 8);
  local_58 = param_5;
  local_20 = 4;
  local_40 = 2;
  local_30[1] = 0;
  local_50 = 4;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,param_2,param_3,0,6,local_78);
  return lVar1;
}



===== WdLogSingleEntry5 @ 1400011c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogSingleEntry5(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                           undefined8 param_5,undefined8 param_6)

{
  uint *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  undefined1 uVar6;
  char cVar7;
  ulonglong uVar8;
  __uint64 **pp_Var9;
  uint uVar10;
  _WD_LOGENTRY *p_Var11;
  __uint64 *p_Var12;
  bool bVar13;
  undefined8 unaff_retaddr;
  short local_res8 [4];
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  
                    /* 0x11c0  116  WdLogSingleEntry5 */
  p_Var12 = (__uint64 *)(longlong)param_1;
  if ((&WdLogRoot)[(longlong)p_Var12 * 3] == (_WD_LOGROOT *)0x0) {
    p_Var11 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    puVar1 = &DAT_14000e09c + (longlong)p_Var12 * 6;
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + 1;
    UNLOCK();
    p_Var11 = (_WD_LOGENTRY *)
              ((&WdLogRoot)[(longlong)p_Var12 * 3] +
              (ulonglong)((&DAT_14000e098)[(longlong)p_Var12 * 6] - 1 & uVar10) * 0x40);
    LOCK();
    UNLOCK();
    uVar5 = WdEventOrder + 1;
    *(ulong *)p_Var11 = WdEventOrder;
    WdEventOrder = uVar5;
    *(void **)(p_Var11 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var11 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var11 + 0x30) = param_5;
  bVar13 = param_1 < 2;
  *(undefined8 *)(p_Var11 + 0x38) = param_6;
  *(undefined8 *)(p_Var11 + 0x18) = param_2;
  *(undefined8 *)(p_Var11 + 0x20) = param_3;
  *(undefined8 *)(p_Var11 + 0x28) = param_4;
  if (Microsoft_Windows_Watchdog_EventsEnableBits == 0) {
LAB_140001293:
    if (param_1 != 0) goto LAB_14000129b;
  }
  else {
    uVar6 = (undefined1)param_1;
    uVar14 = (undefined1)param_2;
    uVar15 = (undefined1)param_3;
    uVar16 = (undefined1)param_4;
    uVar17 = (undefined1)param_5;
    uVar18 = (undefined1)param_6;
    switch(param_1 + -1) {
    case 0:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 1) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogAssert,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    case 1:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 2) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogError,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    case 2:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 4) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogWarning,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    case 3:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 8) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    case 4:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x10) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogTrace,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    case 5:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x20) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogLowResource,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    case 6:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x40) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDmmEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    case 7:
      if ((char)Microsoft_Windows_Watchdog_EventsEnableBits < '\0') {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPresentTokenEvent,0,
                   *(undefined8 *)(p_Var11 + 0x10),(char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16
                   ,uVar17,uVar18);
      }
      break;
    case 8:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x100) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPower,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    case 9:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x200) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDebug,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      break;
    default:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x400) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogUnknown,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
      }
      goto LAB_140001293;
    }
LAB_14000129b:
    if (((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] == '\0') &&
       ((&DAT_14000e0a1)[(longlong)p_Var12 * 0x18] == '\0')) goto LAB_1400012bc;
  }
  uVar6 = KfRaiseIrql(0xf);
  do {
    lVar4 = WdLogLiveDumpInProgress;
    LOCK();
    WdLogLiveDumpInProgress = 1;
    UNLOCK();
  } while (lVar4 != 0);
  _DAT_14000e888 = (ulonglong)*(uint *)p_Var11;
  _DAT_14000e890 = *(undefined8 *)(p_Var11 + 8);
  _DAT_14000e898 = *(undefined8 *)(p_Var11 + 0x10);
  _DAT_14000e8a0 = *(undefined8 *)(p_Var11 + 0x18);
  _DAT_14000e8a8 = *(undefined8 *)(p_Var11 + 0x20);
  _DAT_14000e8b0 = *(undefined8 *)(p_Var11 + 0x28);
  _DAT_14000e8b8 = *(undefined8 *)(p_Var11 + 0x30);
  _DAT_14000e8c0 = *(undefined8 *)(p_Var11 + 0x38);
  WdLogLiveDumpInfo = p_Var12;
  WdLogLiveDumpBreakpoint();
  memset(&WdLogLiveDumpInfo,0,0x48);
  LOCK();
  WdLogLiveDumpInProgress = 0;
  UNLOCK();
  KeLowerIrql(uVar6);
LAB_1400012bc:
  uVar10 = 0;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(*(uint *)(p_Var11 + 0x18),*(undefined8 *)(p_Var11 + 0x20),
                 *(undefined8 *)(p_Var11 + 0x28),*(undefined8 *)(p_Var11 + 0x30),
                 *(undefined8 *)(p_Var11 + 0x38));
  }
  if ((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] != '\0') {
    cVar7 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                ::__l20::bDebuggerPresenceInitialized == '\0');
    `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
    bDebuggerPresenceInitialized = '\x01';
    DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
               (&`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::
                 __l19::Description)[(longlong)p_Var12],*(undefined8 *)(p_Var11 + 0x10));
    if (cVar7 != '\0') {
      bVar13 = false;
      pp_Var9 = &WdLogIgnore;
      do {
        if (*pp_Var9 == *(__uint64 **)(p_Var11 + 0x10)) goto LAB_1400012d3;
        uVar10 = uVar10 + 1;
        pp_Var9 = pp_Var9 + 1;
      } while (uVar10 < 0x10);
      while( true ) {
        local_res8[0] = 0;
        DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                  local_res8,2);
        if ((local_res8[0] - 0x42U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x52U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x49U & 0xdf) == 0) break;
        if (((char)local_res8[0] + 0xbfU & 0xdf) == 0) {
          pp_Var9 = &WdLogIgnore;
          uVar8 = 0;
          do {
            uVar10 = (int)uVar8 + 1;
            if (*pp_Var9 == (__uint64 *)0x0) {
              uVar2 = *(undefined8 *)(p_Var11 + 0x10);
              (&WdLogIgnore)[uVar8] = *(__uint64 **)(p_Var11 + 0x10);
              DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar2,uVar10,0x10
                        );
              goto LAB_1400012d3;
            }
            pp_Var9 = pp_Var9 + 1;
            uVar8 = (ulonglong)uVar10;
          } while (uVar10 < 0x10);
          DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                     *(undefined8 *)(p_Var11 + 0x10),uVar10);
        }
        else {
          DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
        }
      }
    }
  }
LAB_1400012d3:
  return (ulonglong)bVar13;
}



===== WdLogSingleEntry3 @ 1400018b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogSingleEntry3(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  undefined1 uVar6;
  char cVar7;
  ulonglong uVar8;
  __uint64 **pp_Var9;
  uint uVar10;
  _WD_LOGENTRY *p_Var11;
  __uint64 *p_Var12;
  bool bVar13;
  undefined8 unaff_retaddr;
  short local_res8 [4];
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  
                    /* 0x18b0  114  WdLogSingleEntry3 */
  p_Var12 = (__uint64 *)(longlong)param_1;
  if ((&WdLogRoot)[(longlong)p_Var12 * 3] == (_WD_LOGROOT *)0x0) {
    p_Var11 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    puVar1 = &DAT_14000e09c + (longlong)p_Var12 * 6;
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + 1;
    UNLOCK();
    p_Var11 = (_WD_LOGENTRY *)
              ((&WdLogRoot)[(longlong)p_Var12 * 3] +
              (ulonglong)((&DAT_14000e098)[(longlong)p_Var12 * 6] - 1 & uVar10) * 0x40);
    LOCK();
    UNLOCK();
    uVar5 = WdEventOrder + 1;
    *(ulong *)p_Var11 = WdEventOrder;
    WdEventOrder = uVar5;
    *(void **)(p_Var11 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var11 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var11 + 0x18) = param_2;
  *(undefined8 *)(p_Var11 + 0x20) = param_3;
  *(undefined8 *)(p_Var11 + 0x28) = param_4;
  *(undefined8 *)(p_Var11 + 0x30) = 0;
  bVar13 = param_1 < 2;
  *(undefined8 *)(p_Var11 + 0x38) = 0;
  if (Microsoft_Windows_Watchdog_EventsEnableBits == 0) {
LAB_140001970:
    if (param_1 != 0) goto LAB_140001978;
  }
  else {
    uVar6 = (undefined1)param_1;
    uVar14 = (undefined1)param_2;
    uVar15 = (undefined1)param_3;
    uVar16 = (undefined1)param_4;
    switch(param_1 + -1) {
    case 0:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 1) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogAssert,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    case 1:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 2) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogError,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    case 2:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 4) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogWarning,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    case 3:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 8) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    case 4:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x10) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogTrace,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    case 5:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x20) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogLowResource,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    case 6:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x40) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDmmEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    case 7:
      if ((char)Microsoft_Windows_Watchdog_EventsEnableBits < '\0') {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPresentTokenEvent,0,
                   *(undefined8 *)(p_Var11 + 0x10),(char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16
                   ,0,0);
      }
      break;
    case 8:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x100) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPower,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    case 9:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x200) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDebug,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      break;
    default:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x400) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogUnknown,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,0,0);
      }
      goto LAB_140001970;
    }
LAB_140001978:
    if (((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] == '\0') &&
       ((&DAT_14000e0a1)[(longlong)p_Var12 * 0x18] == '\0')) goto LAB_140001994;
  }
  uVar6 = KfRaiseIrql(0xf);
  do {
    lVar4 = WdLogLiveDumpInProgress;
    LOCK();
    WdLogLiveDumpInProgress = 1;
    UNLOCK();
  } while (lVar4 != 0);
  _DAT_14000e888 = (ulonglong)*(uint *)p_Var11;
  _DAT_14000e890 = *(undefined8 *)(p_Var11 + 8);
  _DAT_14000e898 = *(undefined8 *)(p_Var11 + 0x10);
  _DAT_14000e8a0 = *(undefined8 *)(p_Var11 + 0x18);
  _DAT_14000e8a8 = *(undefined8 *)(p_Var11 + 0x20);
  _DAT_14000e8b0 = *(undefined8 *)(p_Var11 + 0x28);
  _DAT_14000e8b8 = *(undefined8 *)(p_Var11 + 0x30);
  _DAT_14000e8c0 = *(undefined8 *)(p_Var11 + 0x38);
  WdLogLiveDumpInfo = p_Var12;
  WdLogLiveDumpBreakpoint();
  memset(&WdLogLiveDumpInfo,0,0x48);
  LOCK();
  WdLogLiveDumpInProgress = 0;
  UNLOCK();
  KeLowerIrql(uVar6);
LAB_140001994:
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(*(uint *)(p_Var11 + 0x18),*(undefined8 *)(p_Var11 + 0x20),
                 *(undefined8 *)(p_Var11 + 0x28),*(undefined8 *)(p_Var11 + 0x30),
                 *(undefined8 *)(p_Var11 + 0x38));
  }
  if ((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] != '\0') {
    cVar7 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                ::__l20::bDebuggerPresenceInitialized == '\0');
    `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
    bDebuggerPresenceInitialized = '\x01';
    DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
               (&`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::
                 __l19::Description)[(longlong)p_Var12],*(undefined8 *)(p_Var11 + 0x10));
    if (cVar7 != '\0') {
      bVar13 = false;
      pp_Var9 = &WdLogIgnore;
      uVar10 = 0;
      do {
        if (*pp_Var9 == *(__uint64 **)(p_Var11 + 0x10)) goto LAB_1400019aa;
        uVar10 = uVar10 + 1;
        pp_Var9 = pp_Var9 + 1;
      } while (uVar10 < 0x10);
      while( true ) {
        local_res8[0] = 0;
        DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                  local_res8,2);
        if ((local_res8[0] - 0x42U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x52U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x49U & 0xdf) == 0) break;
        if (((char)local_res8[0] + 0xbfU & 0xdf) == 0) {
          uVar10 = 0;
          pp_Var9 = &WdLogIgnore;
          do {
            uVar8 = (ulonglong)uVar10;
            uVar10 = uVar10 + 1;
            if (*pp_Var9 == (__uint64 *)0x0) {
              uVar2 = *(undefined8 *)(p_Var11 + 0x10);
              (&WdLogIgnore)[uVar8] = *(__uint64 **)(p_Var11 + 0x10);
              DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar2,uVar10,0x10
                        );
              goto LAB_1400019aa;
            }
            pp_Var9 = pp_Var9 + 1;
          } while (uVar10 < 0x10);
          DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                     *(undefined8 *)(p_Var11 + 0x10),uVar10);
        }
        else {
          DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
        }
      }
    }
  }
LAB_1400019aa:
  return (ulonglong)bVar13;
}



===== WdLogSingleEntry2 @ 140001f80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogSingleEntry2(int param_1,undefined8 param_2,undefined8 param_3)

{
  uint *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  undefined1 uVar6;
  char cVar7;
  ulonglong uVar8;
  __uint64 **pp_Var9;
  uint uVar10;
  _WD_LOGENTRY *p_Var11;
  __uint64 *p_Var12;
  bool bVar13;
  undefined8 unaff_retaddr;
  short local_res8 [4];
  undefined1 uVar14;
  undefined1 uVar15;
  
                    /* 0x1f80  113  WdLogSingleEntry2 */
  p_Var12 = (__uint64 *)(longlong)param_1;
  if ((&WdLogRoot)[(longlong)p_Var12 * 3] == (_WD_LOGROOT *)0x0) {
    p_Var11 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    puVar1 = &DAT_14000e09c + (longlong)p_Var12 * 6;
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + 1;
    UNLOCK();
    p_Var11 = (_WD_LOGENTRY *)
              ((&WdLogRoot)[(longlong)p_Var12 * 3] +
              (ulonglong)((&DAT_14000e098)[(longlong)p_Var12 * 6] - 1 & uVar10) * 0x40);
    LOCK();
    UNLOCK();
    uVar5 = WdEventOrder + 1;
    *(ulong *)p_Var11 = WdEventOrder;
    WdEventOrder = uVar5;
    *(void **)(p_Var11 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var11 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var11 + 0x18) = param_2;
  *(undefined8 *)(p_Var11 + 0x20) = param_3;
  *(undefined8 *)(p_Var11 + 0x28) = 0;
  *(undefined8 *)(p_Var11 + 0x30) = 0;
  bVar13 = param_1 < 2;
  *(undefined8 *)(p_Var11 + 0x38) = 0;
  if (Microsoft_Windows_Watchdog_EventsEnableBits == 0) {
LAB_140002040:
    if (param_1 != 0) goto LAB_140002048;
  }
  else {
    uVar6 = (undefined1)param_1;
    uVar14 = (undefined1)param_2;
    uVar15 = (undefined1)param_3;
    switch(param_1 + -1) {
    case 0:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 1) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogAssert,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    case 1:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 2) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogError,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    case 2:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 4) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogWarning,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    case 3:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 8) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    case 4:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x10) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogTrace,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    case 5:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x20) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogLowResource,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    case 6:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x40) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDmmEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    case 7:
      if ((char)Microsoft_Windows_Watchdog_EventsEnableBits < '\0') {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPresentTokenEvent,0,
                   *(undefined8 *)(p_Var11 + 0x10),(char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0)
        ;
      }
      break;
    case 8:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x100) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPower,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    case 9:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x200) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDebug,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      break;
    default:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x400) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogUnknown,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,0,0,0);
      }
      goto LAB_140002040;
    }
LAB_140002048:
    if (((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] == '\0') &&
       ((&DAT_14000e0a1)[(longlong)p_Var12 * 0x18] == '\0')) goto LAB_140002064;
  }
  uVar6 = KfRaiseIrql(0xf);
  do {
    lVar4 = WdLogLiveDumpInProgress;
    LOCK();
    WdLogLiveDumpInProgress = 1;
    UNLOCK();
  } while (lVar4 != 0);
  _DAT_14000e888 = (ulonglong)*(uint *)p_Var11;
  _DAT_14000e890 = *(undefined8 *)(p_Var11 + 8);
  _DAT_14000e898 = *(undefined8 *)(p_Var11 + 0x10);
  _DAT_14000e8a0 = *(undefined8 *)(p_Var11 + 0x18);
  _DAT_14000e8a8 = *(undefined8 *)(p_Var11 + 0x20);
  _DAT_14000e8b0 = *(undefined8 *)(p_Var11 + 0x28);
  _DAT_14000e8b8 = *(undefined8 *)(p_Var11 + 0x30);
  _DAT_14000e8c0 = *(undefined8 *)(p_Var11 + 0x38);
  WdLogLiveDumpInfo = p_Var12;
  WdLogLiveDumpBreakpoint();
  memset(&WdLogLiveDumpInfo,0,0x48);
  LOCK();
  WdLogLiveDumpInProgress = 0;
  UNLOCK();
  KeLowerIrql(uVar6);
LAB_140002064:
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(*(uint *)(p_Var11 + 0x18),*(undefined8 *)(p_Var11 + 0x20),
                 *(undefined8 *)(p_Var11 + 0x28),*(undefined8 *)(p_Var11 + 0x30),
                 *(undefined8 *)(p_Var11 + 0x38));
  }
  if ((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] != '\0') {
    cVar7 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                ::__l20::bDebuggerPresenceInitialized == '\0');
    `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
    bDebuggerPresenceInitialized = '\x01';
    DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
               (&`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::
                 __l19::Description)[(longlong)p_Var12],*(undefined8 *)(p_Var11 + 0x10));
    if (cVar7 != '\0') {
      bVar13 = false;
      pp_Var9 = &WdLogIgnore;
      uVar10 = 0;
      do {
        if (*pp_Var9 == *(__uint64 **)(p_Var11 + 0x10)) goto LAB_14000207a;
        uVar10 = uVar10 + 1;
        pp_Var9 = pp_Var9 + 1;
      } while (uVar10 < 0x10);
      while( true ) {
        local_res8[0] = 0;
        DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                  local_res8,2);
        if ((local_res8[0] - 0x42U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x52U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x49U & 0xdf) == 0) break;
        if (((char)local_res8[0] + 0xbfU & 0xdf) == 0) {
          uVar10 = 0;
          pp_Var9 = &WdLogIgnore;
          do {
            uVar8 = (ulonglong)uVar10;
            uVar10 = uVar10 + 1;
            if (*pp_Var9 == (__uint64 *)0x0) {
              uVar2 = *(undefined8 *)(p_Var11 + 0x10);
              (&WdLogIgnore)[uVar8] = *(__uint64 **)(p_Var11 + 0x10);
              DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar2,uVar10,0x10
                        );
              goto LAB_14000207a;
            }
            pp_Var9 = pp_Var9 + 1;
          } while (uVar10 < 0x10);
          DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                     *(undefined8 *)(p_Var11 + 0x10),uVar10);
        }
        else {
          DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
        }
      }
    }
  }
LAB_14000207a:
  return (ulonglong)bVar13;
}



===== WdLogSingleEntry4 @ 140002650 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogSingleEntry4(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                           undefined8 param_5)

{
  uint *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  undefined1 uVar6;
  char cVar7;
  ulonglong uVar8;
  __uint64 **pp_Var9;
  uint uVar10;
  _WD_LOGENTRY *p_Var11;
  __uint64 *p_Var12;
  bool bVar13;
  undefined8 unaff_retaddr;
  short local_res8 [4];
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  
                    /* 0x2650  115  WdLogSingleEntry4 */
  p_Var12 = (__uint64 *)(longlong)param_1;
  if ((&WdLogRoot)[(longlong)p_Var12 * 3] == (_WD_LOGROOT *)0x0) {
    p_Var11 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    puVar1 = &DAT_14000e09c + (longlong)p_Var12 * 6;
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + 1;
    UNLOCK();
    p_Var11 = (_WD_LOGENTRY *)
              ((&WdLogRoot)[(longlong)p_Var12 * 3] +
              (ulonglong)((&DAT_14000e098)[(longlong)p_Var12 * 6] - 1 & uVar10) * 0x40);
    LOCK();
    UNLOCK();
    uVar5 = WdEventOrder + 1;
    *(ulong *)p_Var11 = WdEventOrder;
    WdEventOrder = uVar5;
    *(void **)(p_Var11 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var11 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var11 + 0x18) = param_2;
  *(undefined8 *)(p_Var11 + 0x20) = param_3;
  *(undefined8 *)(p_Var11 + 0x28) = param_4;
  bVar13 = param_1 < 2;
  *(undefined8 *)(p_Var11 + 0x30) = param_5;
  *(undefined8 *)(p_Var11 + 0x38) = 0;
  if (Microsoft_Windows_Watchdog_EventsEnableBits == 0) {
LAB_14000271b:
    if (param_1 != 0) goto LAB_140002723;
  }
  else {
    uVar6 = (undefined1)param_1;
    uVar14 = (undefined1)param_2;
    uVar15 = (undefined1)param_3;
    uVar16 = (undefined1)param_4;
    uVar17 = (undefined1)param_5;
    switch(param_1 + -1) {
    case 0:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 1) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogAssert,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    case 1:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 2) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogError,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    case 2:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 4) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogWarning,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    case 3:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 8) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    case 4:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x10) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogTrace,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    case 5:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x20) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogLowResource,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    case 6:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x40) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDmmEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    case 7:
      if ((char)Microsoft_Windows_Watchdog_EventsEnableBits < '\0') {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPresentTokenEvent,0,
                   *(undefined8 *)(p_Var11 + 0x10),(char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16
                   ,uVar17,0);
      }
      break;
    case 8:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x100) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPower,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    case 9:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x200) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDebug,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      break;
    default:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x400) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogUnknown,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,uVar15,uVar16,uVar17,0);
      }
      goto LAB_14000271b;
    }
LAB_140002723:
    if (((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] == '\0') &&
       ((&DAT_14000e0a1)[(longlong)p_Var12 * 0x18] == '\0')) goto LAB_14000273f;
  }
  uVar6 = KfRaiseIrql(0xf);
  do {
    lVar4 = WdLogLiveDumpInProgress;
    LOCK();
    WdLogLiveDumpInProgress = 1;
    UNLOCK();
  } while (lVar4 != 0);
  _DAT_14000e888 = (ulonglong)*(uint *)p_Var11;
  _DAT_14000e890 = *(undefined8 *)(p_Var11 + 8);
  _DAT_14000e898 = *(undefined8 *)(p_Var11 + 0x10);
  _DAT_14000e8a0 = *(undefined8 *)(p_Var11 + 0x18);
  _DAT_14000e8a8 = *(undefined8 *)(p_Var11 + 0x20);
  _DAT_14000e8b0 = *(undefined8 *)(p_Var11 + 0x28);
  _DAT_14000e8b8 = *(undefined8 *)(p_Var11 + 0x30);
  _DAT_14000e8c0 = *(undefined8 *)(p_Var11 + 0x38);
  WdLogLiveDumpInfo = p_Var12;
  WdLogLiveDumpBreakpoint();
  memset(&WdLogLiveDumpInfo,0,0x48);
  LOCK();
  WdLogLiveDumpInProgress = 0;
  UNLOCK();
  KeLowerIrql(uVar6);
LAB_14000273f:
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(*(uint *)(p_Var11 + 0x18),*(undefined8 *)(p_Var11 + 0x20),
                 *(undefined8 *)(p_Var11 + 0x28),*(undefined8 *)(p_Var11 + 0x30),
                 *(undefined8 *)(p_Var11 + 0x38));
  }
  if ((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] != '\0') {
    cVar7 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                ::__l20::bDebuggerPresenceInitialized == '\0');
    `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
    bDebuggerPresenceInitialized = '\x01';
    DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
               (&`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::
                 __l19::Description)[(longlong)p_Var12],*(undefined8 *)(p_Var11 + 0x10));
    if (cVar7 != '\0') {
      bVar13 = false;
      pp_Var9 = &WdLogIgnore;
      uVar10 = 0;
      do {
        if (*pp_Var9 == *(__uint64 **)(p_Var11 + 0x10)) goto LAB_140002755;
        uVar10 = uVar10 + 1;
        pp_Var9 = pp_Var9 + 1;
      } while (uVar10 < 0x10);
      while( true ) {
        local_res8[0] = 0;
        DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                  local_res8,2);
        if ((local_res8[0] - 0x42U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x52U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x49U & 0xdf) == 0) break;
        if (((char)local_res8[0] + 0xbfU & 0xdf) == 0) {
          uVar10 = 0;
          pp_Var9 = &WdLogIgnore;
          do {
            uVar8 = (ulonglong)uVar10;
            uVar10 = uVar10 + 1;
            if (*pp_Var9 == (__uint64 *)0x0) {
              uVar2 = *(undefined8 *)(p_Var11 + 0x10);
              (&WdLogIgnore)[uVar8] = *(__uint64 **)(p_Var11 + 0x10);
              DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar2,uVar10,0x10
                        );
              goto LAB_140002755;
            }
            pp_Var9 = pp_Var9 + 1;
          } while (uVar10 < 0x10);
          DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                     *(undefined8 *)(p_Var11 + 0x10),uVar10);
        }
        else {
          DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
        }
      }
    }
  }
LAB_140002755:
  return (ulonglong)bVar13;
}



===== WdpDbgCaptureTriageDump @ 140002d24 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl WdpDbgCaptureTriageDump(struct _WD_DEBUG_REPORT * __ptr64) */

long __cdecl WdpDbgCaptureTriageDump(_WD_DEBUG_REPORT *param_1)

{
  void *pvVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  pvVar1 = SystemReserved1[0xf];
  local_18 = 0;
  uStack_10 = 0;
  lVar3 = ExAllocatePool2(0x40,0x40000,0x676f6457);
  if (lVar3 == 0) {
    WdLogSingleEntry0(6);
    _WdLogGlobalForLineNumber = 0x41b;
    iVar2 = -0x3fffffe9;
  }
  else {
    lVar4 = ExAllocatePool2(0x100,0x4d0,0x676f6457);
    if (lVar4 == 0) {
      WdLogSingleEntry0(6);
      _WdLogGlobalForLineNumber = 0x427;
      iVar2 = -0x3fffffe9;
    }
    else {
      RtlCaptureContext(lVar4);
      iVar2 = KeCapturePersistentThreadState
                        (lVar4,pvVar1,*(undefined4 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x10),
                         *(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20),
                         *(undefined8 *)(param_1 + 0x28),lVar3);
      if (iVar2 == 0) {
        WdLogSingleEntry0(2);
        _WdLogGlobalForLineNumber = 0x43d;
        iVar2 = -0x3fffffff;
      }
      else {
        local_res10 = 0;
        iVar2 = ZwWriteFile(*(undefined8 *)(param_1 + 0x2b0),0,0,0,&local_18,lVar3,iVar2,
                            &local_res10,0);
        if (iVar2 < 0) {
          WdLogSingleEntry1(2,(longlong)iVar2);
          _WdLogGlobalForLineNumber = 0x455;
        }
        else {
          iVar2 = ZwFlushBuffersFileEx(*(undefined8 *)(param_1 + 0x2b0),0,0,0,&local_18);
          if (iVar2 < 0) {
            WdLogSingleEntry1(2,(longlong)iVar2);
            _WdLogGlobalForLineNumber = 0x466;
          }
        }
      }
    }
    ExFreePoolWithTag(lVar3,0x676f6457);
    if (lVar4 != 0) {
      ExFreePoolWithTag(lVar4,0x676f6457);
    }
  }
  return iVar2;
}



===== WdLogSingleEntry0 @ 140002f40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool WdLogSingleEntry0(int param_1)

{
  uint *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  char cVar6;
  undefined1 uVar7;
  char *pcVar8;
  __uint64 **pp_Var9;
  uint uVar10;
  undefined *puVar11;
  __uint64 *p_Var12;
  _WD_LOGENTRY *p_Var13;
  ulonglong uVar14;
  bool bVar15;
  undefined8 unaff_retaddr;
  short local_res8 [4];
  
                    /* 0x2f40  111  WdLogSingleEntry0 */
  p_Var12 = (__uint64 *)(longlong)param_1;
  if ((&WdLogRoot)[(longlong)p_Var12 * 3] == (_WD_LOGROOT *)0x0) {
    p_Var13 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    puVar1 = &DAT_14000e09c + (longlong)p_Var12 * 6;
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + 1;
    UNLOCK();
    p_Var13 = (_WD_LOGENTRY *)
              ((&WdLogRoot)[(longlong)p_Var12 * 3] +
              (ulonglong)((&DAT_14000e098)[(longlong)p_Var12 * 6] - 1 & uVar10) * 0x40);
    LOCK();
    UNLOCK();
    uVar5 = WdEventOrder + 1;
    *(ulong *)p_Var13 = WdEventOrder;
    WdEventOrder = uVar5;
    *(void **)(p_Var13 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var13 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var13 + 0x18) = 0;
  *(undefined8 *)(p_Var13 + 0x20) = 0;
  *(undefined8 *)(p_Var13 + 0x28) = 0;
  bVar15 = param_1 < 2;
  *(undefined8 *)(p_Var13 + 0x30) = 0;
  *(undefined8 *)(p_Var13 + 0x38) = 0;
  if (Microsoft_Windows_Watchdog_EventsEnableBits == 0) {
LAB_140002ff2:
    if (param_1 != 0) goto LAB_140002ffa;
  }
  else {
    if (param_1 < 7) {
      if (param_1 == 6) {
        if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x20) != 0) {
          puVar11 = &WdLogLowResource;
LAB_140003102:
          McTemplateK0pqqxxxxx_EtwWriteTransfer
                    (&WatchDogEtwProvider_Context,puVar11,0,*(undefined8 *)(p_Var13 + 0x10),
                     (char)*(uint *)p_Var13,(char)param_1,0,0,0,0,0);
        }
      }
      else if (param_1 == 1) {
        if ((Microsoft_Windows_Watchdog_EventsEnableBits & 1) != 0) {
          puVar11 = &WdLogAssert;
          goto LAB_140003102;
        }
      }
      else if (param_1 == 2) {
        if ((Microsoft_Windows_Watchdog_EventsEnableBits & 2) != 0) {
          puVar11 = &WdLogError;
          goto LAB_140003102;
        }
      }
      else if (param_1 == 3) {
        if ((Microsoft_Windows_Watchdog_EventsEnableBits & 4) != 0) {
          puVar11 = &WdLogWarning;
          goto LAB_140003102;
        }
      }
      else if (param_1 == 4) {
        if ((Microsoft_Windows_Watchdog_EventsEnableBits & 8) != 0) {
          puVar11 = &WdLogEvent;
          goto LAB_140003102;
        }
      }
      else {
        if (param_1 != 5) goto LAB_140003182;
        if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x10) != 0) {
          puVar11 = &WdLogTrace;
          goto LAB_140003102;
        }
      }
    }
    else if (param_1 == 7) {
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x40) != 0) {
        puVar11 = &WdLogDmmEvent;
        goto LAB_140003102;
      }
    }
    else if (param_1 == 8) {
      if ((char)Microsoft_Windows_Watchdog_EventsEnableBits < '\0') {
        puVar11 = &WdLogPresentTokenEvent;
        goto LAB_140003102;
      }
    }
    else if (param_1 == 9) {
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x100) != 0) {
        puVar11 = &WdLogPower;
        goto LAB_140003102;
      }
    }
    else {
      if (param_1 != 10) {
LAB_140003182:
        if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x400) != 0) {
          McTemplateK0pqqxxxxx_EtwWriteTransfer
                    (&WatchDogEtwProvider_Context,&WdLogUnknown,0,*(undefined8 *)(p_Var13 + 0x10),
                     (char)*(uint *)p_Var13,(char)param_1,0,0,0,0,0);
        }
        goto LAB_140002ff2;
      }
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x200) != 0) {
        puVar11 = &WdLogDebug;
        goto LAB_140003102;
      }
    }
LAB_140002ffa:
    pcVar8 = &DAT_14000e0a0 + (longlong)p_Var12 * 0x18;
    if ((*pcVar8 == '\0') && ((&DAT_14000e0a1)[(longlong)p_Var12 * 0x18] == '\0'))
    goto LAB_14000301c;
  }
  uVar7 = KfRaiseIrql(0xf);
  do {
    lVar4 = WdLogLiveDumpInProgress;
    LOCK();
    WdLogLiveDumpInProgress = 1;
    UNLOCK();
  } while (lVar4 != 0);
  _DAT_14000e888 = (ulonglong)*(uint *)p_Var13;
  _DAT_14000e890 = *(undefined8 *)(p_Var13 + 8);
  _DAT_14000e898 = *(undefined8 *)(p_Var13 + 0x10);
  _DAT_14000e8a0 = *(undefined8 *)(p_Var13 + 0x18);
  _DAT_14000e8a8 = *(undefined8 *)(p_Var13 + 0x20);
  _DAT_14000e8b0 = *(undefined8 *)(p_Var13 + 0x28);
  _DAT_14000e8b8 = *(undefined8 *)(p_Var13 + 0x30);
  _DAT_14000e8c0 = *(undefined8 *)(p_Var13 + 0x38);
  WdLogLiveDumpInfo = p_Var12;
  WdLogLiveDumpBreakpoint();
  memset(&WdLogLiveDumpInfo,0,0x48);
  LOCK();
  WdLogLiveDumpInProgress = 0;
  UNLOCK();
  KeLowerIrql(uVar7);
  pcVar8 = &DAT_14000e0a0 + (longlong)p_Var12 * 0x18;
LAB_14000301c:
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(*(uint *)(p_Var13 + 0x18),*(undefined8 *)(p_Var13 + 0x20),
                 *(undefined8 *)(p_Var13 + 0x28),*(undefined8 *)(p_Var13 + 0x30),
                 *(undefined8 *)(p_Var13 + 0x38));
  }
  if (*pcVar8 != '\0') {
    cVar6 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                ::__l20::bDebuggerPresenceInitialized == '\0');
    `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
    bDebuggerPresenceInitialized = '\x01';
    DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
               (&`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::
                 __l19::Description)[(longlong)p_Var12],*(undefined8 *)(p_Var13 + 0x10));
    if (cVar6 != '\0') {
      bVar15 = false;
      pp_Var9 = &WdLogIgnore;
      uVar10 = 0;
      do {
        if (*pp_Var9 == *(__uint64 **)(p_Var13 + 0x10)) {
          return false;
        }
        uVar10 = uVar10 + 1;
        pp_Var9 = pp_Var9 + 1;
      } while (uVar10 < 0x10);
      while( true ) {
        local_res8[0] = 0;
        DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                  local_res8,2);
        if ((local_res8[0] - 0x42U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar7 = (*pcVar3)();
          return (bool)uVar7;
        }
        if ((local_res8[0] - 0x52U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar7 = (*pcVar3)();
          return (bool)uVar7;
        }
        if ((local_res8[0] - 0x49U & 0xdf) == 0) break;
        if (((char)local_res8[0] + 0xbfU & 0xdf) == 0) {
          uVar10 = 0;
          pp_Var9 = &WdLogIgnore;
          do {
            uVar14 = (ulonglong)uVar10;
            uVar10 = uVar10 + 1;
            if (*pp_Var9 == (__uint64 *)0x0) {
              uVar2 = *(undefined8 *)(p_Var13 + 0x10);
              (&WdLogIgnore)[uVar14] = *(__uint64 **)(p_Var13 + 0x10);
              DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar2,uVar10,0x10
                        );
              return false;
            }
            pp_Var9 = pp_Var9 + 1;
          } while (uVar10 < 0x10);
          DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                     *(undefined8 *)(p_Var13 + 0x10),uVar10);
        }
        else {
          DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
        }
      }
    }
  }
  return bVar15;
}



===== WdLogSingleEntry1 @ 140003440 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogSingleEntry1(int param_1,undefined8 param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  undefined1 uVar6;
  char cVar7;
  ulonglong uVar8;
  __uint64 **pp_Var9;
  uint uVar10;
  _WD_LOGENTRY *p_Var11;
  __uint64 *p_Var12;
  bool bVar13;
  undefined8 unaff_retaddr;
  short local_res8 [4];
  undefined1 uVar14;
  
                    /* 0x3440  112  WdLogSingleEntry1 */
  p_Var12 = (__uint64 *)(longlong)param_1;
  if ((&WdLogRoot)[(longlong)p_Var12 * 3] == (_WD_LOGROOT *)0x0) {
    p_Var11 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    puVar1 = &DAT_14000e09c + (longlong)p_Var12 * 6;
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + 1;
    UNLOCK();
    p_Var11 = (_WD_LOGENTRY *)
              ((&WdLogRoot)[(longlong)p_Var12 * 3] +
              (ulonglong)((&DAT_14000e098)[(longlong)p_Var12 * 6] - 1 & uVar10) * 0x40);
    LOCK();
    UNLOCK();
    uVar5 = WdEventOrder + 1;
    *(ulong *)p_Var11 = WdEventOrder;
    WdEventOrder = uVar5;
    *(void **)(p_Var11 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var11 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var11 + 0x18) = param_2;
  *(undefined8 *)(p_Var11 + 0x20) = 0;
  *(undefined8 *)(p_Var11 + 0x28) = 0;
  *(undefined8 *)(p_Var11 + 0x30) = 0;
  bVar13 = param_1 < 2;
  *(undefined8 *)(p_Var11 + 0x38) = 0;
  if (Microsoft_Windows_Watchdog_EventsEnableBits == 0) {
LAB_140003500:
    if (param_1 != 0) goto LAB_140003508;
  }
  else {
    uVar6 = (undefined1)param_1;
    uVar14 = (undefined1)param_2;
    switch(param_1 + -1) {
    case 0:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 1) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogAssert,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 1:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 2) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogError,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 2:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 4) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogWarning,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 3:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 8) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 4:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x10) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogTrace,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 5:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x20) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogLowResource,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 6:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x40) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDmmEvent,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 7:
      if ((char)Microsoft_Windows_Watchdog_EventsEnableBits < '\0') {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPresentTokenEvent,0,
                   *(undefined8 *)(p_Var11 + 0x10),(char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 8:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x100) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogPower,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    case 9:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x200) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogDebug,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      break;
    default:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x400) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (&WatchDogEtwProvider_Context,&WdLogUnknown,0,*(undefined8 *)(p_Var11 + 0x10),
                   (char)*(uint *)p_Var11,uVar6,uVar14,0,0,0,0);
      }
      goto LAB_140003500;
    }
LAB_140003508:
    if (((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] == '\0') &&
       ((&DAT_14000e0a1)[(longlong)p_Var12 * 0x18] == '\0')) goto LAB_140003524;
  }
  uVar6 = KfRaiseIrql(0xf);
  do {
    lVar4 = WdLogLiveDumpInProgress;
    LOCK();
    WdLogLiveDumpInProgress = 1;
    UNLOCK();
  } while (lVar4 != 0);
  _DAT_14000e888 = (ulonglong)*(uint *)p_Var11;
  _DAT_14000e890 = *(undefined8 *)(p_Var11 + 8);
  _DAT_14000e898 = *(undefined8 *)(p_Var11 + 0x10);
  _DAT_14000e8a0 = *(undefined8 *)(p_Var11 + 0x18);
  _DAT_14000e8a8 = *(undefined8 *)(p_Var11 + 0x20);
  _DAT_14000e8b0 = *(undefined8 *)(p_Var11 + 0x28);
  _DAT_14000e8b8 = *(undefined8 *)(p_Var11 + 0x30);
  _DAT_14000e8c0 = *(undefined8 *)(p_Var11 + 0x38);
  WdLogLiveDumpInfo = p_Var12;
  WdLogLiveDumpBreakpoint();
  memset(&WdLogLiveDumpInfo,0,0x48);
  LOCK();
  WdLogLiveDumpInProgress = 0;
  UNLOCK();
  KeLowerIrql(uVar6);
LAB_140003524:
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(*(uint *)(p_Var11 + 0x18),*(undefined8 *)(p_Var11 + 0x20),
                 *(undefined8 *)(p_Var11 + 0x28),*(undefined8 *)(p_Var11 + 0x30),
                 *(undefined8 *)(p_Var11 + 0x38));
  }
  if ((&DAT_14000e0a0)[(longlong)p_Var12 * 0x18] != '\0') {
    cVar7 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                ::__l20::bDebuggerPresenceInitialized == '\0');
    `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
    bDebuggerPresenceInitialized = '\x01';
    DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
               (&`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::
                 __l19::Description)[(longlong)p_Var12],*(undefined8 *)(p_Var11 + 0x10));
    if (cVar7 != '\0') {
      bVar13 = false;
      pp_Var9 = &WdLogIgnore;
      uVar10 = 0;
      do {
        if (*pp_Var9 == *(__uint64 **)(p_Var11 + 0x10)) goto LAB_14000353a;
        uVar10 = uVar10 + 1;
        pp_Var9 = pp_Var9 + 1;
      } while (uVar10 < 0x10);
      while( true ) {
        local_res8[0] = 0;
        DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                  local_res8,2);
        if ((local_res8[0] - 0x42U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x52U & 0xdf) == 0) {
          pcVar3 = (code *)swi(3);
          uVar8 = (*pcVar3)();
          return uVar8;
        }
        if ((local_res8[0] - 0x49U & 0xdf) == 0) break;
        if (((char)local_res8[0] + 0xbfU & 0xdf) == 0) {
          uVar10 = 0;
          pp_Var9 = &WdLogIgnore;
          do {
            uVar8 = (ulonglong)uVar10;
            uVar10 = uVar10 + 1;
            if (*pp_Var9 == (__uint64 *)0x0) {
              uVar2 = *(undefined8 *)(p_Var11 + 0x10);
              (&WdLogIgnore)[uVar8] = *(__uint64 **)(p_Var11 + 0x10);
              DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar2,uVar10,0x10
                        );
              goto LAB_14000353a;
            }
            pp_Var9 = pp_Var9 + 1;
          } while (uVar10 < 0x10);
          DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                     *(undefined8 *)(p_Var11 + 0x10),uVar10);
        }
        else {
          DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
        }
      }
    }
  }
LAB_14000353a:
  return (ulonglong)bVar13;
}



===== WdLogEvent5 @ 140003b10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned char __cdecl WdLogEvent5(enum _WD_LOGEVENT_LEVEL,struct _WD_LOGENTRY * __ptr64) */

uchar __cdecl WdLogEvent5(_WD_LOGEVENT_LEVEL param_1,_WD_LOGENTRY *param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  uchar uVar6;
  longlong lVar7;
  __uint64 **pp_Var8;
  uint uVar9;
  __uint64 *p_Var10;
  undefined8 in_R8;
  ulonglong uVar11;
  bool bVar12;
  short local_res8 [4];
  
  p_Var10 = (__uint64 *)(longlong)(int)param_1;
  bVar12 = (int)param_1 < 2;
  if (Microsoft_Windows_Watchdog_EventsEnableBits == 0) {
LAB_140003b4c:
    if (param_1 != 0) goto LAB_140003b54;
  }
  else {
    uVar9 = param_1 - 1;
    uVar4 = (undefined1)param_1;
    if (9 < uVar9) {
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x400) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  ((ulonglong)uVar9,&WdLogUnknown,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      goto LAB_140003b4c;
    }
    lVar7 = (longlong)(int)uVar9;
    switch(uVar9) {
    case 0:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 1) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogAssert,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 1:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 2) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogError,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 2:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 4) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogWarning,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 3:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 8) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogEvent,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 4:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x10) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogTrace,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 5:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x20) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogLowResource,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 6:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x40) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogDmmEvent,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 7:
      if ((char)Microsoft_Windows_Watchdog_EventsEnableBits < '\0') {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogPresentTokenEvent,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 8:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x100) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogPower,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
      break;
    case 9:
      if ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x200) != 0) {
        McTemplateK0pqqxxxxx_EtwWriteTransfer
                  (lVar7,&WdLogDebug,in_R8,*(undefined8 *)(param_2 + 0x10),
                   (char)*(undefined4 *)param_2,uVar4,(char)*(undefined8 *)(param_2 + 0x18),
                   (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x28),
                   (char)*(undefined8 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
      }
    }
LAB_140003b54:
    if (((&DAT_14000e0a0)[(longlong)p_Var10 * 0x18] == '\0') &&
       ((&DAT_14000e0a1)[(longlong)p_Var10 * 0x18] == '\0')) goto LAB_140003b77;
  }
  uVar4 = KfRaiseIrql(0xf);
  do {
    lVar3 = WdLogLiveDumpInProgress;
    LOCK();
    WdLogLiveDumpInProgress = 1;
    UNLOCK();
  } while (lVar3 != 0);
  _DAT_14000e888 = (ulonglong)*(uint *)param_2;
  _DAT_14000e890 = *(undefined8 *)(param_2 + 8);
  _DAT_14000e898 = *(undefined8 *)(param_2 + 0x10);
  _DAT_14000e8a0 = *(undefined8 *)(param_2 + 0x18);
  _DAT_14000e8a8 = *(undefined8 *)(param_2 + 0x20);
  _DAT_14000e8b0 = *(undefined8 *)(param_2 + 0x28);
  _DAT_14000e8b8 = *(undefined8 *)(param_2 + 0x30);
  _DAT_14000e8c0 = *(undefined8 *)(param_2 + 0x38);
  WdLogLiveDumpInfo = p_Var10;
  WdLogLiveDumpBreakpoint();
  memset(&WdLogLiveDumpInfo,0,0x48);
  LOCK();
  WdLogLiveDumpInProgress = 0;
  UNLOCK();
  KeLowerIrql(uVar4);
LAB_140003b77:
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(*(undefined4 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                 *(undefined8 *)(param_2 + 0x28),*(undefined8 *)(param_2 + 0x30),
                 *(undefined8 *)(param_2 + 0x38));
  }
  if ((&DAT_14000e0a0)[(longlong)p_Var10 * 0x18] != '\0') {
    cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                ::__l20::bDebuggerPresenceInitialized == '\0');
    `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
    bDebuggerPresenceInitialized = '\x01';
    DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
               (&`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::
                 __l19::Description)[(longlong)p_Var10],*(longlong *)(param_2 + 0x10));
    if (cVar5 != '\0') {
      bVar12 = false;
      pp_Var8 = &WdLogIgnore;
      uVar9 = 0;
      do {
        if (*pp_Var8 == *(__uint64 **)(param_2 + 0x10)) {
          return '\0';
        }
        uVar9 = uVar9 + 1;
        pp_Var8 = pp_Var8 + 1;
      } while (uVar9 < 0x10);
      while( true ) {
        local_res8[0] = 0;
        DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                  local_res8,2);
        if ((local_res8[0] - 0x42U & 0xdf) == 0) {
          pcVar2 = (code *)swi(3);
          uVar6 = (*pcVar2)();
          return uVar6;
        }
        if ((local_res8[0] - 0x52U & 0xdf) == 0) {
          pcVar2 = (code *)swi(3);
          uVar6 = (*pcVar2)();
          return uVar6;
        }
        if ((local_res8[0] - 0x49U & 0xdf) == 0) break;
        if (((char)local_res8[0] + 0xbfU & 0xdf) == 0) {
          uVar9 = 0;
          pp_Var8 = &WdLogIgnore;
          do {
            uVar11 = (ulonglong)uVar9;
            uVar9 = uVar9 + 1;
            if (*pp_Var8 == (__uint64 *)0x0) {
              uVar1 = *(undefined8 *)(param_2 + 0x10);
              (&WdLogIgnore)[uVar11] = *(__uint64 **)(param_2 + 0x10);
              DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,uVar9,0x10)
              ;
              return '\0';
            }
            pp_Var8 = pp_Var8 + 1;
          } while (uVar9 < 0x10);
          DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                     *(undefined8 *)(param_2 + 0x10),uVar9);
        }
        else {
          DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
        }
      }
    }
  }
  return bVar12;
}



===== WdLogNewEntry5_WdTrace @ 1400041e0 =====

void WdLogNewEntry5_WdTrace(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x41e0  109  WdLogNewEntry5_WdTrace */
  if (DAT_14000e108 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e110 - 1U & DAT_14000e114) * 0x40 + DAT_14000e108);
    LOCK();
    UNLOCK();
    DAT_14000e114 = DAT_14000e114 + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return;
}



===== WdSetEventAndWaitForSingleObject @ 140004260 =====

void WdSetEventAndWaitForSingleObject
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,
               uint *param_5)

{
  uint uVar1;
  undefined4 in_register_00000084;
  uint **ppuVar2;
  
                    /* 0x4260  128  WdSetEventAndWaitForSingleObject */
  if (param_5 == (uint *)0x0) {
    KeSetEvent(param_1,1,CONCAT71((int7)(CONCAT44(in_register_00000084,param_3) >> 8),1));
    ppuVar2 = (uint **)0x0;
  }
  else {
    uVar1 = *param_5;
    KeSetEvent();
    param_5 = (uint *)((ulonglong)uVar1 * -10000);
    ppuVar2 = &param_5;
  }
  KeWaitForSingleObject(param_2,param_3,param_4,0,ppuVar2);
  return;
}



===== _tlgKeywordOn @ 140004310 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _tlgKeywordOn(undefined8 param_1,ulonglong param_2)

{
  if (((_DAT_14000e058 & param_2) == 0) || ((DAT_14000e060 & param_2) != DAT_14000e060)) {
    return 0;
  }
  return CONCAT71((int7)((DAT_14000e060 & param_2) >> 8),1);
}



===== AutoMutex @ 14000433c =====

/* public: __cdecl AutoMutex::AutoMutex(struct _WD_MUTEX & __ptr64) __ptr64 */

AutoMutex * __thiscall AutoMutex::AutoMutex(AutoMutex *this,_WD_MUTEX *param_1)

{
  this[8] = (AutoMutex)0x0;
  *(_WD_MUTEX **)this = &g_displayScenarioMutex;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(*(longlong *)this + 8,0);
  **(undefined8 **)this = SystemReserved1[0xf];
  this[8] = (AutoMutex)0x1;
  return this;
}



===== WatchdogTimeoutReport @ 1400043a0 =====

/* public: __cdecl WatchdogTimeoutReport::WatchdogTimeoutReport(unsigned long,unsigned
   __int64,unsigned __int64,unsigned __int64,unsigned __int64,union _WD_LIVEREPORT_FLAGS,void
   (__cdecl*)(class WatchdogTimeoutReport * __ptr64),bool (__cdecl*)(class WatchdogTimeoutReport *
   __ptr64),bool,unsigned int) __ptr64 */

WatchdogTimeoutReport * __thiscall
WatchdogTimeoutReport::WatchdogTimeoutReport
          (WatchdogTimeoutReport *this,undefined4 param_1,undefined8 param_2,undefined8 param_3,
          undefined8 param_4,undefined8 param_5,WatchdogTimeoutReport param_7,undefined8 param_8,
          undefined8 param_9,char param_10,undefined4 param_11)

{
                    /* 0x43a0  1
                       ??0WatchdogTimeoutReport@@QEAA@K_K000T_WD_LIVEREPORT_FLAGS@@P6AXPEAV0@@ZP6A_N2@Z_NI@Z
                        */
  *(undefined4 *)(this + 0xc0) = param_11;
  *(undefined8 *)(this + 0xd8) = param_4;
  *(undefined8 *)(this + 0xe0) = param_5;
  this[0xe8] = param_7;
  *(undefined8 *)(this + 0xf0) = param_8;
  *(undefined8 *)(this + 0xf8) = param_9;
  *this = (WatchdogTimeoutReport)0x1;
  *(undefined4 *)(this + 0xc4) = param_1;
  *(undefined8 *)(this + 200) = param_2;
  *(undefined8 *)(this + 0xd0) = param_3;
  KeInitializeTimer(this + 8);
  KeInitializeDpc(this + 0x48,WdpWatchdogTimeoutReportDpcCallback,this);
  *(undefined8 *)(this + 0x88) = 0;
  *(code **)(this + 0x98) = WdpProcessWatchdogTimeoutReportThread;
  *(WatchdogTimeoutReport **)(this + 0xa0) = this;
  KeInitializeEvent(this + 0xa8,0,1);
  if (param_10 != '\0') {
    StartTimer(this);
  }
  return this;
}



===== StartTimer @ 140004490 =====

/* public: void __cdecl WatchdogTimeoutReport::StartTimer(void) __ptr64 */

void __thiscall WatchdogTimeoutReport::StartTimer(WatchdogTimeoutReport *this)

{
                    /* 0x4490  23  ?StartTimer@WatchdogTimeoutReport@@QEAAXXZ */
  KeSetTimer(this + 8,(ulonglong)*(uint *)(this + 0xc0) * -10000,this + 0x48);
  return;
}



===== ~WatchdogTimeoutReport @ 1400044d0 =====

/* public: __cdecl WatchdogTimeoutReport::~WatchdogTimeoutReport(void) __ptr64 */

void __thiscall WatchdogTimeoutReport::~WatchdogTimeoutReport(WatchdogTimeoutReport *this)

{
                    /* 0x44d0  2  ??1WatchdogTimeoutReport@@QEAA@XZ */
  Cancel(this);
  return;
}



===== Cancel @ 1400044f0 =====

/* public: void __cdecl WatchdogTimeoutReport::Cancel(void) __ptr64 */

void __thiscall WatchdogTimeoutReport::Cancel(WatchdogTimeoutReport *this)

{
  char cVar1;
  
                    /* 0x44f0  4  ?Cancel@WatchdogTimeoutReport@@QEAAXXZ */
  if (*this != (WatchdogTimeoutReport)0x0) {
    *this = (WatchdogTimeoutReport)0x0;
    cVar1 = KeCancelTimer(this + 8);
    if (cVar1 == '\0') {
      KeFlushQueuedDpcs();
      KeWaitForSingleObject(this + 0xa8,0,0,0,0);
    }
  }
  return;
}



===== WdLogNewEntry5_WdWarning @ 140004560 =====

_WD_LOGENTRY * WdLogNewEntry5_WdWarning(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x4560  110  WdLogNewEntry5_WdWarning */
  if (DAT_14000e0d8 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e0e0 - 1U & DAT_14000e0e4) * 0x40 + DAT_14000e0d8);
    LOCK();
    UNLOCK();
    DAT_14000e0e4 = DAT_14000e0e4 + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== WdLogNewEntry5_WdEvent @ 1400045e0 =====

_WD_LOGENTRY * WdLogNewEntry5_WdEvent(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x45e0  105  WdLogNewEntry5_WdEvent */
  if (DAT_14000e0f0 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e0f8 - 1U & DAT_14000e0fc) * 0x40 + DAT_14000e0f0);
    LOCK();
    UNLOCK();
    DAT_14000e0fc = DAT_14000e0fc + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== WdLogGetEventOrder @ 140004660 =====

ulong WdLogGetEventOrder(void)

{
                    /* 0x4660  98  WdLogGetEventOrder */
  return WdEventOrder;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_> @ 140004670 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void const
   * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8>
   const & __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<2> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperByVal<4> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapperByVal<4> *param_10,
          _tlgWrapperByVal<4> *param_11)

{
  long lVar1;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [4];
  _tlgWrapperByVal<8> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<2> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_28 = param_11;
  local_38 = param_10;
  local_48 = param_9;
  local_58 = param_8;
  local_68 = param_7;
  local_78 = param_6;
  local_88 = param_5;
  local_20 = 4;
  local_30 = 4;
  local_40 = 4;
  local_50 = 4;
  local_60 = 4;
  local_70 = 2;
  local_80 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,param_2,param_3,0,9,local_a8);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<1>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_> @ 14000473c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4>,struct _tlgWrapperBinary,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperPtrSize,struct _tlgWrapperPtrSize,struct
   _tlgWrapperPtrSize,struct _tlgWrapperPtrSize,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByRef<16>,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<4> >(struct
   _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID
   const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<2> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperPtrSize const & __ptr64,struct _tlgWrapperPtrSize const &
   __ptr64,struct _tlgWrapperPtrSize const & __ptr64,struct _tlgWrapperPtrSize const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByRef<16> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<1>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<2> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperByVal<4> *param_8,_tlgWrapperBinary *param_9,_tlgWrapperByVal<1> *param_10,
          _tlgWrapperPtrSize *param_11,_tlgWrapperPtrSize *param_12,_tlgWrapperPtrSize *param_13,
          _tlgWrapperPtrSize *param_14,_tlgWrapperByVal<4> *param_15,_tlgWrapperByRef<16> *param_16,
          _tlgWrapperByVal<4> *param_17,_tlgWrapperByVal<4> *param_18)

{
  long lVar1;
  undefined1 auStackY_158 [32];
  undefined8 local_128 [4];
  _tlgWrapperByVal<8> *local_108;
  undefined8 local_100;
  _tlgWrapperByVal<2> *local_f8;
  undefined8 local_f0;
  _tlgWrapperByVal<4> *local_e8;
  undefined8 local_e0;
  _tlgWrapperByVal<4> *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  uint local_b0 [2];
  _tlgWrapperByVal<1> *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_158;
  local_28 = param_18;
  local_38 = param_17;
  local_20 = 4;
  local_30 = 4;
  local_40 = 0x10;
  local_48 = *(undefined8 *)param_16;
  local_58 = param_15;
  local_50 = 4;
  local_5c = 0;
  local_6c = 0;
  local_68 = *(undefined8 *)param_14;
  local_60 = *(undefined4 *)(param_14 + 8);
  local_7c = 0;
  local_8c = 0;
  local_78 = *(undefined8 *)param_13;
  local_70 = *(undefined4 *)(param_13 + 8);
  local_a0 = 1;
  local_c0 = 2;
  local_88 = *(undefined8 *)param_12;
  local_80 = *(undefined4 *)(param_12 + 8);
  local_b0[1] = 0;
  local_d0 = 4;
  local_98 = *(undefined8 *)param_11;
  local_90 = *(undefined4 *)(param_11 + 8);
  local_a8 = param_10;
  local_c8 = local_b0;
  local_b8 = *(undefined8 *)param_9;
  local_b0[0] = (uint)*(ushort *)(param_9 + 8);
  local_d8 = param_8;
  local_e8 = param_7;
  local_f8 = param_6;
  local_108 = param_5;
  local_e0 = 4;
  local_f0 = 2;
  local_100 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,param_2,param_3,0,0x11,local_128);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize> @ 1400048d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperPtrSize,struct _tlgWrapperPtrSize,struct
   _tlgWrapperPtrSize>(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const
   * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct
   _tlgWrapperPtrSize const & __ptr64,struct _tlgWrapperPtrSize const & __ptr64,struct
   _tlgWrapperPtrSize const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<2> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperPtrSize *param_8,_tlgWrapperPtrSize *param_9,_tlgWrapperPtrSize *param_10)

{
  long lVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [4];
  _tlgWrapperByVal<8> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<2> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_1c = 0;
  local_2c = 0;
  local_3c = 0;
  local_28 = *(undefined8 *)param_10;
  local_20 = *(undefined4 *)(param_10 + 8);
  local_50 = 4;
  local_60 = 2;
  local_38 = *(undefined8 *)param_9;
  local_30 = *(undefined4 *)(param_9 + 8);
  local_48 = *(undefined8 *)param_8;
  local_40 = *(undefined4 *)(param_8 + 8);
  local_58 = param_7;
  local_68 = param_6;
  local_78 = param_5;
  local_70 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,param_2,param_3,0,8,local_98);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize> @ 14000499c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<2>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperPtrSize,struct _tlgWrapperPtrSize>(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<2> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperPtrSize const &
   __ptr64,struct _tlgWrapperPtrSize const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<2> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperPtrSize *param_8,_tlgWrapperPtrSize *param_9)

{
  long lVar1;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [4];
  _tlgWrapperByVal<8> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<2> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_1c = 0;
  local_2c = 0;
  local_40 = 4;
  local_28 = *(undefined8 *)param_9;
  local_20 = *(undefined4 *)(param_9 + 8);
  local_50 = 2;
  local_60 = 8;
  local_38 = *(undefined8 *)param_8;
  local_30 = *(undefined4 *)(param_8 + 8);
  local_48 = param_7;
  local_58 = param_6;
  local_68 = param_5;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,param_2,param_3,0,7,local_88);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize> @ 140004a50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperPtrSize,struct _tlgWrapperPtrSize,struct _tlgWrapperPtrSize,struct
   _tlgWrapperPtrSize,struct _tlgWrapperPtrSize>(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8>
   const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperPtrSize const & __ptr64,struct _tlgWrapperPtrSize const &
   __ptr64,struct _tlgWrapperPtrSize const & __ptr64,struct _tlgWrapperPtrSize const &
   __ptr64,struct _tlgWrapperPtrSize const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperBinary *param_7,
          _tlgWrapperByVal<2> *param_8,_tlgWrapperByVal<4> *param_9,_tlgWrapperPtrSize *param_10,
          _tlgWrapperPtrSize *param_11,_tlgWrapperPtrSize *param_12,_tlgWrapperPtrSize *param_13,
          _tlgWrapperPtrSize *param_14)

{
  long lVar1;
  undefined1 auStackY_118 [32];
  undefined8 local_e8 [4];
  _tlgWrapperByVal<8> *local_c8;
  undefined8 local_c0;
  _tlgWrapperByVal<4> *local_b8;
  undefined8 local_b0;
  uint *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  uint local_90 [2];
  _tlgWrapperByVal<2> *local_88;
  undefined8 local_80;
  _tlgWrapperByVal<4> *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  local_1c = 0;
  local_2c = 0;
  local_3c = 0;
  local_28 = *(undefined8 *)param_14;
  local_20 = *(undefined4 *)(param_14 + 8);
  local_4c = 0;
  local_5c = 0;
  local_38 = *(undefined8 *)param_13;
  local_30 = *(undefined4 *)(param_13 + 8);
  local_70 = 4;
  local_80 = 2;
  local_48 = *(undefined8 *)param_12;
  local_40 = *(undefined4 *)(param_12 + 8);
  local_a0 = 2;
  local_90[1] = 0;
  local_58 = *(undefined8 *)param_11;
  local_50 = *(undefined4 *)(param_11 + 8);
  local_b0 = 4;
  local_c0 = 8;
  local_68 = *(undefined8 *)param_10;
  local_60 = *(undefined4 *)(param_10 + 8);
  local_78 = param_9;
  local_88 = param_8;
  local_a8 = local_90;
  local_98 = *(undefined8 *)param_7;
  local_90[0] = (uint)*(ushort *)(param_7 + 8);
  local_b8 = param_6;
  local_c8 = param_5;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,param_2,param_3,0,0xd,local_e8);
  return lVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140004b88 =====

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



===== WdLogGetRecentEvents @ 140004c30 =====

ulonglong WdLogGetRecentEvents(uint param_1,uint param_2,longlong param_3,ulonglong param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  _WD_LOGROOT *p_Var6;
  uint uVar7;
  
                    /* 0x4c30  99  WdLogGetRecentEvents */
  uVar4 = 0;
  uVar7 = 0;
  if ((param_1 < 0xb) &&
     (lVar3 = (longlong)(int)param_1, (&WdLogRoot)[lVar3 * 3] != (_WD_LOGROOT *)0x0)) {
    if ((uint)(&DAT_14000e098)[lVar3 * 6] < param_2) {
      param_2 = (&DAT_14000e098)[lVar3 * 6];
    }
    if (param_3 == 0) {
      param_4 = (ulonglong)(param_2 << 6);
    }
    uVar5 = (ulonglong)((&DAT_14000e09c)[lVar3 * 6] - 1) %
            (ulonglong)(uint)(&DAT_14000e098)[lVar3 * 6];
    while( true ) {
      if ((((uVar4 + 0x40 < 0x40) || ((param_4 & 0xffffffff) < uVar4 + 0x40)) || (param_2 <= uVar7))
         || ((p_Var6 = (&WdLogRoot)[lVar3 * 3] + uVar5 * 0x40, p_Var6 == (_WD_LOGROOT *)0x0 ||
             (0xfffffffffffffffd < *(longlong *)(p_Var6 + 0x10) - 1U)))) break;
      if (param_3 != 0) {
        uVar2 = *(undefined8 *)(p_Var6 + 8);
        *(undefined8 *)(uVar4 + param_3) = *(undefined8 *)p_Var6;
        ((undefined8 *)(uVar4 + param_3))[1] = uVar2;
        uVar2 = *(undefined8 *)(p_Var6 + 0x18);
        puVar1 = (undefined8 *)(uVar4 + 0x10 + param_3);
        *puVar1 = *(undefined8 *)(p_Var6 + 0x10);
        puVar1[1] = uVar2;
        uVar2 = *(undefined8 *)(p_Var6 + 0x28);
        puVar1 = (undefined8 *)(uVar4 + 0x20 + param_3);
        *puVar1 = *(undefined8 *)(p_Var6 + 0x20);
        puVar1[1] = uVar2;
        uVar2 = *(undefined8 *)(p_Var6 + 0x38);
        puVar1 = (undefined8 *)(uVar4 + 0x30 + param_3);
        *puVar1 = *(undefined8 *)(p_Var6 + 0x30);
        puVar1[1] = uVar2;
      }
      uVar5 = (ulonglong)((int)uVar5 - 1) % (ulonglong)(uint)(&DAT_14000e098)[lVar3 * 6];
      uVar7 = uVar7 + 1;
      uVar4 = (ulonglong)((int)uVar4 + 0x40);
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



===== Release @ 140004d3c =====

/* public: void __cdecl CDisplayScenarioContextCarrier::Release(void) __ptr64 */

void __thiscall CDisplayScenarioContextCarrier::Release(CDisplayScenarioContextCarrier *this)

{
  if (*this != (CDisplayScenarioContextCarrier)0x0) {
    DisplayScenarioContextRelease((_DXGK_DISPLAY_SCENARIO_CONTEXT **)(this + 8));
  }
  *(undefined8 *)(this + 8) = 0;
  *this = (CDisplayScenarioContextCarrier)0x0;
  return;
}



===== operator_new @ 140004d74 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64,unsigned long,unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1,ulong param_2,__uint64 param_3)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x100,param_1,0x7774656c);
  return pvVar1;
}



===== operator_delete[] @ 140004da0 =====

/* void __cdecl operator delete[](void * __ptr64) */

void __cdecl operator_delete__(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== RtlStringCopyWorkerW @ 140004dc4 =====

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



===== McGenEventRegister_EtwRegister @ 140004e20 =====

void McGenEventRegister_EtwRegister(void)

{
  if (WatchDogEtwProvider_Context == 0) {
    EtwRegister(&WatchDogEtwProvider,McGenControlCallbackV2,&WatchDogEtwProvider_Context,
                &WatchDogEtwProvider_Context);
  }
  return;
}



===== WdDiagIsTracingEnabled @ 140004e60 =====

undefined1 WdDiagIsTracingEnabled(undefined8 param_1)

{
  char cVar1;
  undefined1 uVar2;
  
                    /* 0x4e60  75  WdDiagIsTracingEnabled */
  uVar2 = 0;
  if (DAT_14000ea90 != 0) {
    cVar1 = EtwEventEnabled(DAT_14000ea90,param_1);
    if (cVar1 != '\0') {
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== `vector_deleting_destructor' @ 140004ea0 =====

/* public: virtual void * __ptr64 __cdecl CDisplayScenarioContext::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CDisplayScenarioContext::_vector_deleting_destructor_(CDisplayScenarioContext *this,uint param_1)

{
  ~CDisplayScenarioContext(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140004ee0 =====

/* public: virtual void * __ptr64 __cdecl CDisplayScenarioJournal::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CDisplayScenarioJournal::_scalar_deleting_destructor_(CDisplayScenarioJournal *this,uint param_1)

{
  ~CDisplayScenarioJournal(this);
  if ((param_1 & 1) != 0) {
    operator_delete__(this);
  }
  return this;
}



===== WdLogNewEntry5_WdError @ 140004f20 =====

_WD_LOGENTRY * WdLogNewEntry5_WdError(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x4f20  104  WdLogNewEntry5_WdError */
  if (DAT_14000e0c0 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e0c8 - 1U & DAT_14000e0cc) * 0x40 + DAT_14000e0c0);
    LOCK();
    UNLOCK();
    DAT_14000e0cc = DAT_14000e0cc + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== RtlStringCbCatW @ 140004fa0 =====

/* long __cdecl RtlStringCbCatW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64) */

long __cdecl RtlStringCbCatW(ushort *param_1,__uint64 param_2,ushort *param_3)

{
  uint uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar4 = 0x104;
  puVar2 = param_1;
  do {
    if (*puVar2 == 0) break;
    puVar2 = puVar2 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  uVar3 = -(ulonglong)(lVar4 != 0) & 0x104U - lVar4;
  uVar1 = ~-(uint)(lVar4 != 0) & 0xc000000d;
  if (lVar4 != 0) {
    uVar1 = RtlStringCopyWorkerW((short *)(param_1 + uVar3),0x104 - uVar3,uVar3,(longlong)param_3);
  }
  return uVar1;
}



===== RtlStringCbCopyW @ 14000500c =====

/* long __cdecl RtlStringCbCopyW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64) */

long __cdecl RtlStringCbCopyW(ushort *param_1,__uint64 param_2,ushort *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar1 = RtlStringCopyWorkerW((short *)param_1,uVar2,param_3,(longlong)param_3);
  }
  else {
    uVar1 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = 0;
    }
  }
  return uVar1;
}



===== __report_gsfailure @ 140005050 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ext_ms_win_ntos_werkernel_l1_1_0_WerLiveKernelCreateReport @ 140005060 =====

undefined8 ext_ms_win_ntos_werkernel_l1_1_0_WerLiveKernelCreateReport(void)

{
  return 0xc00000bb;
}



===== GetArg1 @ 140005070 =====

/* public: unsigned __int64 __cdecl WatchdogTimeoutReport::GetArg1(void) __ptr64 */

__uint64 __thiscall WatchdogTimeoutReport::GetArg1(WatchdogTimeoutReport *this)

{
                    /* 0x5070  13  ?GetArg1@WatchdogTimeoutReport@@QEAA_KXZ */
  return *(__uint64 *)(this + 200);
}



===== GetArg2 @ 140005080 =====

/* public: unsigned __int64 __cdecl WatchdogTimeoutReport::GetArg2(void) __ptr64 */

__uint64 __thiscall WatchdogTimeoutReport::GetArg2(WatchdogTimeoutReport *this)

{
                    /* 0x5080  14  ?GetArg2@WatchdogTimeoutReport@@QEAA_KXZ */
  return *(__uint64 *)(this + 0xd0);
}



===== GetArg3 @ 140005090 =====

/* public: unsigned __int64 __cdecl WatchdogTimeoutReport::GetArg3(void) __ptr64 */

__uint64 __thiscall WatchdogTimeoutReport::GetArg3(WatchdogTimeoutReport *this)

{
                    /* 0x5090  15  ?GetArg3@WatchdogTimeoutReport@@QEAA_KXZ */
  return *(__uint64 *)(this + 0xd8);
}



===== GetArg4 @ 1400050a0 =====

/* public: unsigned __int64 __cdecl WatchdogTimeoutReport::GetArg4(void) __ptr64 */

__uint64 __thiscall WatchdogTimeoutReport::GetArg4(WatchdogTimeoutReport *this)

{
                    /* 0x50a0  16  ?GetArg4@WatchdogTimeoutReport@@QEAA_KXZ */
  return *(__uint64 *)(this + 0xe0);
}



===== GetCode @ 1400050b0 =====

/* public: unsigned long __cdecl WatchdogTimeoutReport::GetCode(void) __ptr64 */

ulong __thiscall WatchdogTimeoutReport::GetCode(WatchdogTimeoutReport *this)

{
                    /* 0x50b0  17  ?GetCode@WatchdogTimeoutReport@@QEAAKXZ */
  return *(ulong *)(this + 0xc4);
}



===== GetIsActive @ 1400050c0 =====

/* public: bool volatile __cdecl WatchdogTimeoutReport::GetIsActive(void) __ptr64 */

bool __thiscall WatchdogTimeoutReport::GetIsActive(WatchdogTimeoutReport *this)

{
                    /* 0x50c0  18  ?GetIsActive@WatchdogTimeoutReport@@QEAA?C_NXZ */
  return (bool)*this;
}



===== GetLiveDumpFlags @ 1400050d0 =====

/* public: union _WD_LIVEREPORT_FLAGS __cdecl WatchdogTimeoutReport::GetLiveDumpFlags(void) __ptr64
    */

void __thiscall WatchdogTimeoutReport::GetLiveDumpFlags(WatchdogTimeoutReport *this)

{
  WatchdogTimeoutReport *in_RDX;
  
                    /* 0x50d0  19
                       ?GetLiveDumpFlags@WatchdogTimeoutReport@@QEAA?AT_WD_LIVEREPORT_FLAGS@@XZ */
  *in_RDX = this[0xe8];
  return;
}



===== GetLiveDumpWorkItem @ 1400050f0 =====

/* public: struct _WORK_QUEUE_ITEM * __ptr64 __cdecl
   WatchdogTimeoutReport::GetLiveDumpWorkItem(void) __ptr64 */

_WORK_QUEUE_ITEM * __thiscall
WatchdogTimeoutReport::GetLiveDumpWorkItem(WatchdogTimeoutReport *this)

{
                    /* 0x50f0  20
                       ?GetLiveDumpWorkItem@WatchdogTimeoutReport@@QEAAPEAU_WORK_QUEUE_ITEM@@XZ */
  return (_WORK_QUEUE_ITEM *)(this + 0x88);
}



===== GetLiveDumpWorkItemEvent @ 140005100 =====

/* public: struct _KEVENT * __ptr64 __cdecl WatchdogTimeoutReport::GetLiveDumpWorkItemEvent(void)
   __ptr64 */

_KEVENT * __thiscall WatchdogTimeoutReport::GetLiveDumpWorkItemEvent(WatchdogTimeoutReport *this)

{
                    /* 0x5100  21
                       ?GetLiveDumpWorkItemEvent@WatchdogTimeoutReport@@QEAAPEAU_KEVENT@@XZ */
  return (_KEVENT *)(this + 0xa8);
}



===== RtlStringCbPrintfA @ 140005110 =====

/* long __cdecl RtlStringCbPrintfA(char * __ptr64,unsigned __int64,char const * __ptr64,...) */

long __cdecl RtlStringCbPrintfA(char *param_1,__uint64 param_2,char *param_3,...)

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



===== WdLogLiveDumpBreakpoint @ 140005184 =====

/* void __cdecl WdLogLiveDumpBreakpoint(void) */

void __cdecl WdLogLiveDumpBreakpoint(void)

{
  return;
}



===== McGenControlCallbackV2 @ 1400051a0 =====

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



===== McGenEventWrite_EtwWriteTransfer @ 1400052b0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000e008;
  uVar2 = 0;
  if (DAT_14000e008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000e008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(WatchDogEtwProvider_Context,param_2,0,0,9,param_5);
  return;
}



===== McTemplateK0pqqxxxxx_EtwWriteTransfer @ 140005314 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pqqxxxxx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined8 local_res20;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined8 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = &local_res20;
  local_90 = 8;
  local_88 = &param_5;
  local_78 = &param_6;
  local_68 = &param_7;
  local_58 = &param_8;
  local_48 = &param_9;
  local_38 = &param_10;
  local_28 = &param_11;
  local_80 = 4;
  local_70 = 4;
  local_60 = 8;
  local_50 = 8;
  local_40 = 8;
  local_30 = 8;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,param_4,local_a8);
  return;
}



===== WdIsDebuggerPresent @ 1400053e0 =====

undefined1 WdIsDebuggerPresent(char param_1)

{
  undefined1 uVar1;
  
                    /* 0x53e0  86  WdIsDebuggerPresent */
  uVar1 = 0;
  if (param_1 != '\0') {
    KdRefreshDebuggerNotPresent();
  }
  if ((*KdDebuggerEnabled_exref != (code)0x0) && (*KdDebuggerNotPresent_exref == (code)0x0)) {
    uVar1 = 1;
  }
  return uVar1;
}



===== WdLogEvent5_WdAssertion @ 140005420 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 WdLogEvent5_WdAssertion(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  undefined1 uVar6;
  __uint64 **pp_Var7;
  uint uVar8;
  ulonglong uVar9;
  short local_res10 [4];
  
                    /* 0x5420  87  WdLogEvent5_WdAssertion */
  uVar6 = 1;
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 1) != 0)) {
    McTemplateK0pqqxxxxx_EtwWriteTransfer
              (&WatchDogEtwProvider_Context,&WdLogAssert,0,*(undefined8 *)(param_1 + 4),
               (char)*param_1,1,(char)*(undefined8 *)(param_1 + 6),
               (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
               (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e0b8 != '\0') || (DAT_14000e0b9 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x1;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    KeLowerIrql(uVar4);
    if (DAT_14000e0b8 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n","assertion failure",
                 *(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar6 = 0;
        pp_Var7 = &WdLogIgnore;
        uVar8 = 0;
        do {
          if (*pp_Var7 == *(__uint64 **)(param_1 + 4)) {
            return 0;
          }
          uVar8 = uVar8 + 1;
          pp_Var7 = pp_Var7 + 1;
        } while (uVar8 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          if ((local_res10[0] - 0x42U & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          if ((local_res10[0] - 0x52U & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          if ((local_res10[0] - 0x49U & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar8 = 0;
            pp_Var7 = &WdLogIgnore;
            do {
              uVar9 = (ulonglong)uVar8;
              uVar8 = uVar8 + 1;
              if (*pp_Var7 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar9] = *(__uint64 **)(param_1 + 4);
                DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,uVar8,
                           0x10);
                return 0;
              }
              pp_Var7 = pp_Var7 + 1;
            } while (uVar8 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar8);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
  return uVar6;
}



===== WdLogEvent5_WdCriticalError @ 1400056f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WdLogEvent5_WdCriticalError(uint *param_1)

{
  long lVar1;
  undefined1 uVar2;
  
                    /* 0x56f0  88  WdLogEvent5_WdCriticalError */
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x400) != 0)) {
    McTemplateK0pqqxxxxx_EtwWriteTransfer
              (&WatchDogEtwProvider_Context,&WdLogUnknown,0,*(undefined8 *)(param_1 + 4),
               (char)*param_1,0,(char)*(undefined8 *)(param_1 + 6),
               (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
               (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  uVar2 = KfRaiseIrql(0xf);
  do {
    lVar1 = WdLogLiveDumpInProgress;
    LOCK();
    WdLogLiveDumpInProgress = 1;
    UNLOCK();
  } while (lVar1 != 0);
  WdLogLiveDumpInfo = (__uint64 *)0x0;
  _DAT_14000e888 = (ulonglong)*param_1;
  _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
  _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
  _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
  _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
  _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
  _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
  _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
  WdLogLiveDumpBreakpoint();
  memset(&WdLogLiveDumpInfo,0,0x48);
  LOCK();
  WdLogLiveDumpInProgress = 0;
  UNLOCK();
  KeLowerIrql(uVar2);
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(param_1[6],*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 10),
               *(undefined8 *)(param_1 + 0xc),*(undefined8 *)(param_1 + 0xe));
}



===== WdLogEvent5_WdDebug @ 140005840 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdDebug(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *in_RAX;
  ulonglong uVar6;
  __uint64 **pp_Var7;
  uint uVar8;
  ushort local_res10 [4];
  
                    /* 0x5840  89  WdLogEvent5_WdDebug */
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x200) != 0)) {
    in_RAX = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogDebug,0,*(undefined8 *)(param_1 + 4),
                        (char)*param_1,10,(char)*(undefined8 *)(param_1 + 6),
                        (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
                        (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e190 != '\0') || (DAT_14000e191 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0xa;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    in_RAX = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e190 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      in_RAX = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
                          "Private debug event",*(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar8 = 0;
        pp_Var7 = &WdLogIgnore;
        do {
          in_RAX = *pp_Var7;
          if (in_RAX == *(__uint64 **)(param_1 + 4)) goto LAB_140005ad9;
          uVar8 = uVar8 + 1;
          pp_Var7 = pp_Var7 + 1;
        } while (uVar8 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          in_RAX = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar8 = 0;
            pp_Var7 = &WdLogIgnore;
            do {
              uVar6 = (ulonglong)uVar8;
              uVar8 = uVar8 + 1;
              if (*pp_Var7 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar6] = *(__uint64 **)(param_1 + 4);
                in_RAX = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar8,0x10);
                goto LAB_140005ad9;
              }
              pp_Var7 = pp_Var7 + 1;
            } while (uVar8 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar8);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_140005ad9:
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== WdLogEvent5_WdDmmEvent @ 140005b00 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdDmmEvent(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *p_Var6;
  ulonglong uVar7;
  __uint64 **pp_Var8;
  uint uVar9;
  ushort local_res10 [4];
  
                    /* 0x5b00  90  WdLogEvent5_WdDmmEvent */
  p_Var6 = (__uint64 *)(ulonglong)Microsoft_Windows_Watchdog_EventsEnableBits;
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x40) != 0)) {
    p_Var6 = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogDmmEvent,0,*(undefined8 *)(param_1 + 4),
                        (char)*param_1,7,(char)*(undefined8 *)(param_1 + 6),
                        (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
                        (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e148 != '\0') || (DAT_14000e149 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x7;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    p_Var6 = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e148 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      p_Var6 = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
                          "DMM specific event",*(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar9 = 0;
        pp_Var8 = &WdLogIgnore;
        do {
          p_Var6 = *pp_Var8;
          if (p_Var6 == *(__uint64 **)(param_1 + 4)) goto LAB_140005d96;
          uVar9 = uVar9 + 1;
          pp_Var8 = pp_Var8 + 1;
        } while (uVar9 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          p_Var6 = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar9 = 0;
            pp_Var8 = &WdLogIgnore;
            do {
              uVar7 = (ulonglong)uVar9;
              uVar9 = uVar9 + 1;
              if (*pp_Var8 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar7] = *(__uint64 **)(param_1 + 4);
                p_Var6 = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar9,0x10);
                goto LAB_140005d96;
              }
              pp_Var8 = pp_Var8 + 1;
            } while (uVar9 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar9);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_140005d96:
  return (ulonglong)p_Var6 & 0xffffffffffffff00;
}



===== WdLogEvent5_WdError @ 140005dc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdError(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *p_Var6;
  ulonglong uVar7;
  __uint64 **pp_Var8;
  uint uVar9;
  ushort local_res10 [4];
  
                    /* 0x5dc0  91  WdLogEvent5_WdError */
  p_Var6 = (__uint64 *)(ulonglong)Microsoft_Windows_Watchdog_EventsEnableBits;
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 2) != 0)) {
    p_Var6 = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogError,0,*(undefined8 *)(param_1 + 4),
                        (char)*param_1,2,(char)*(undefined8 *)(param_1 + 6),
                        (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
                        (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e0d0 != '\0') || (DAT_14000e0d1 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x2;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    p_Var6 = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e0d0 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      p_Var6 = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
                          "noncritical error",*(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar9 = 0;
        pp_Var8 = &WdLogIgnore;
        do {
          p_Var6 = *pp_Var8;
          if (p_Var6 == *(__uint64 **)(param_1 + 4)) goto LAB_140006056;
          uVar9 = uVar9 + 1;
          pp_Var8 = pp_Var8 + 1;
        } while (uVar9 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          p_Var6 = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar9 = 0;
            pp_Var8 = &WdLogIgnore;
            do {
              uVar7 = (ulonglong)uVar9;
              uVar9 = uVar9 + 1;
              if (*pp_Var8 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar7] = *(__uint64 **)(param_1 + 4);
                p_Var6 = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar9,0x10);
                goto LAB_140006056;
              }
              pp_Var8 = pp_Var8 + 1;
            } while (uVar9 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar9);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_140006056:
  return (ulonglong)p_Var6 & 0xffffffffffffff00;
}



===== WdLogEvent5_WdEvent @ 140006080 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdEvent(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *p_Var6;
  ulonglong uVar7;
  __uint64 **pp_Var8;
  uint uVar9;
  ushort local_res10 [4];
  
                    /* 0x6080  92  WdLogEvent5_WdEvent */
  p_Var6 = (__uint64 *)(ulonglong)Microsoft_Windows_Watchdog_EventsEnableBits;
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 8) != 0)) {
    p_Var6 = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogEvent,0,*(undefined8 *)(param_1 + 4),
                        (char)*param_1,4,(char)*(undefined8 *)(param_1 + 6),
                        (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
                        (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e100 != '\0') || (DAT_14000e101 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x4;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    p_Var6 = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e100 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      p_Var6 = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n","event message",
                          *(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar9 = 0;
        pp_Var8 = &WdLogIgnore;
        do {
          p_Var6 = *pp_Var8;
          if (p_Var6 == *(__uint64 **)(param_1 + 4)) goto LAB_140006314;
          uVar9 = uVar9 + 1;
          pp_Var8 = pp_Var8 + 1;
        } while (uVar9 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          p_Var6 = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar9 = 0;
            pp_Var8 = &WdLogIgnore;
            do {
              uVar7 = (ulonglong)uVar9;
              uVar9 = uVar9 + 1;
              if (*pp_Var8 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar7] = *(__uint64 **)(param_1 + 4);
                p_Var6 = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar9,0x10);
                goto LAB_140006314;
              }
              pp_Var8 = pp_Var8 + 1;
            } while (uVar9 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar9);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_140006314:
  return (ulonglong)p_Var6 & 0xffffffffffffff00;
}



===== WdLogEvent5_WdLowResource @ 140006340 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdLowResource(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *p_Var6;
  ulonglong uVar7;
  __uint64 **pp_Var8;
  uint uVar9;
  ushort local_res10 [4];
  
                    /* 0x6340  93  WdLogEvent5_WdLowResource */
  p_Var6 = (__uint64 *)(ulonglong)Microsoft_Windows_Watchdog_EventsEnableBits;
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x20) != 0)) {
    p_Var6 = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogLowResource,0,
                        *(undefined8 *)(param_1 + 4),(char)*param_1,6,
                        (char)*(undefined8 *)(param_1 + 6),(char)*(undefined8 *)(param_1 + 8),
                        (char)*(undefined8 *)(param_1 + 10),(char)*(undefined8 *)(param_1 + 0xc),
                        (char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e130 != '\0') || (DAT_14000e131 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x6;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    p_Var6 = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e130 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      p_Var6 = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
                          "low resource condition",*(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar9 = 0;
        pp_Var8 = &WdLogIgnore;
        do {
          p_Var6 = *pp_Var8;
          if (p_Var6 == *(__uint64 **)(param_1 + 4)) goto LAB_1400065d6;
          uVar9 = uVar9 + 1;
          pp_Var8 = pp_Var8 + 1;
        } while (uVar9 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          p_Var6 = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar9 = 0;
            pp_Var8 = &WdLogIgnore;
            do {
              uVar7 = (ulonglong)uVar9;
              uVar9 = uVar9 + 1;
              if (*pp_Var8 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar7] = *(__uint64 **)(param_1 + 4);
                p_Var6 = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar9,0x10);
                goto LAB_1400065d6;
              }
              pp_Var8 = pp_Var8 + 1;
            } while (uVar9 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar9);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_1400065d6:
  return (ulonglong)p_Var6 & 0xffffffffffffff00;
}



===== WdLogEvent5_WdPower @ 140006600 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdPower(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *in_RAX;
  ulonglong uVar6;
  __uint64 **pp_Var7;
  uint uVar8;
  ushort local_res10 [4];
  
                    /* 0x6600  94  WdLogEvent5_WdPower */
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x100) != 0)) {
    in_RAX = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogPower,0,*(undefined8 *)(param_1 + 4),
                        (char)*param_1,9,(char)*(undefined8 *)(param_1 + 6),
                        (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
                        (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e178 != '\0') || (DAT_14000e179 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x9;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    in_RAX = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e178 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      in_RAX = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
                          "Power transition event",*(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar8 = 0;
        pp_Var7 = &WdLogIgnore;
        do {
          in_RAX = *pp_Var7;
          if (in_RAX == *(__uint64 **)(param_1 + 4)) goto LAB_140006899;
          uVar8 = uVar8 + 1;
          pp_Var7 = pp_Var7 + 1;
        } while (uVar8 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          in_RAX = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar6 = (*pcVar2)();
            return uVar6;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar8 = 0;
            pp_Var7 = &WdLogIgnore;
            do {
              uVar6 = (ulonglong)uVar8;
              uVar8 = uVar8 + 1;
              if (*pp_Var7 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar6] = *(__uint64 **)(param_1 + 4);
                in_RAX = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar8,0x10);
                goto LAB_140006899;
              }
              pp_Var7 = pp_Var7 + 1;
            } while (uVar8 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar8);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_140006899:
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== WdLogEvent5_WdPresentTokenEvent @ 1400068c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdPresentTokenEvent(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *p_Var6;
  ulonglong uVar7;
  __uint64 **pp_Var8;
  uint uVar9;
  ushort local_res10 [4];
  
                    /* 0x68c0  95  WdLogEvent5_WdPresentTokenEvent */
  p_Var6 = (__uint64 *)(ulonglong)Microsoft_Windows_Watchdog_EventsEnableBits;
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((char)Microsoft_Windows_Watchdog_EventsEnableBits < '\0')) {
    p_Var6 = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogPresentTokenEvent,0,
                        *(undefined8 *)(param_1 + 4),(char)*param_1,8,
                        (char)*(undefined8 *)(param_1 + 6),(char)*(undefined8 *)(param_1 + 8),
                        (char)*(undefined8 *)(param_1 + 10),(char)*(undefined8 *)(param_1 + 0xc),
                        (char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e160 != '\0') || (DAT_14000e161 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x8;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    p_Var6 = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e160 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      p_Var6 = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
                          "Present token event",*(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar9 = 0;
        pp_Var8 = &WdLogIgnore;
        do {
          p_Var6 = *pp_Var8;
          if (p_Var6 == *(__uint64 **)(param_1 + 4)) goto LAB_140006b56;
          uVar9 = uVar9 + 1;
          pp_Var8 = pp_Var8 + 1;
        } while (uVar9 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          p_Var6 = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar9 = 0;
            pp_Var8 = &WdLogIgnore;
            do {
              uVar7 = (ulonglong)uVar9;
              uVar9 = uVar9 + 1;
              if (*pp_Var8 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar7] = *(__uint64 **)(param_1 + 4);
                p_Var6 = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar9,0x10);
                goto LAB_140006b56;
              }
              pp_Var8 = pp_Var8 + 1;
            } while (uVar9 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar9);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_140006b56:
  return (ulonglong)p_Var6 & 0xffffffffffffff00;
}



===== WdLogEvent5_WdTrace @ 140006b80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdTrace(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *p_Var6;
  ulonglong uVar7;
  __uint64 **pp_Var8;
  uint uVar9;
  ushort local_res10 [4];
  
                    /* 0x6b80  96  WdLogEvent5_WdTrace */
  p_Var6 = (__uint64 *)(ulonglong)Microsoft_Windows_Watchdog_EventsEnableBits;
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 0x10) != 0)) {
    p_Var6 = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogTrace,0,*(undefined8 *)(param_1 + 4),
                        (char)*param_1,5,(char)*(undefined8 *)(param_1 + 6),
                        (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
                        (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e118 != '\0') || (DAT_14000e119 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x5;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    p_Var6 = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e118 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      p_Var6 = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n",
                          "execution trace message",*(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar9 = 0;
        pp_Var8 = &WdLogIgnore;
        do {
          p_Var6 = *pp_Var8;
          if (p_Var6 == *(__uint64 **)(param_1 + 4)) goto LAB_140006e14;
          uVar9 = uVar9 + 1;
          pp_Var8 = pp_Var8 + 1;
        } while (uVar9 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          p_Var6 = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar9 = 0;
            pp_Var8 = &WdLogIgnore;
            do {
              uVar7 = (ulonglong)uVar9;
              uVar9 = uVar9 + 1;
              if (*pp_Var8 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar7] = *(__uint64 **)(param_1 + 4);
                p_Var6 = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar9,0x10);
                goto LAB_140006e14;
              }
              pp_Var8 = pp_Var8 + 1;
            } while (uVar9 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar9);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_140006e14:
  return (ulonglong)p_Var6 & 0xffffffffffffff00;
}



===== WdLogEvent5_WdWarning @ 140006e40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdLogEvent5_WdWarning(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  undefined1 uVar4;
  char cVar5;
  __uint64 *p_Var6;
  ulonglong uVar7;
  __uint64 **pp_Var8;
  uint uVar9;
  ushort local_res10 [4];
  
                    /* 0x6e40  97  WdLogEvent5_WdWarning */
  p_Var6 = (__uint64 *)(ulonglong)Microsoft_Windows_Watchdog_EventsEnableBits;
  if ((Microsoft_Windows_Watchdog_EventsEnableBits != 0) &&
     ((Microsoft_Windows_Watchdog_EventsEnableBits & 4) != 0)) {
    p_Var6 = (__uint64 *)
             McTemplateK0pqqxxxxx_EtwWriteTransfer
                       (&WatchDogEtwProvider_Context,&WdLogWarning,0,*(undefined8 *)(param_1 + 4),
                        (char)*param_1,3,(char)*(undefined8 *)(param_1 + 6),
                        (char)*(undefined8 *)(param_1 + 8),(char)*(undefined8 *)(param_1 + 10),
                        (char)*(undefined8 *)(param_1 + 0xc),(char)*(undefined8 *)(param_1 + 0xe));
  }
  if ((DAT_14000e0e8 != '\0') || (DAT_14000e0e9 != '\0')) {
    uVar4 = KfRaiseIrql(0xf);
    do {
      lVar3 = WdLogLiveDumpInProgress;
      LOCK();
      WdLogLiveDumpInProgress = 1;
      UNLOCK();
    } while (lVar3 != 0);
    WdLogLiveDumpInfo = (__uint64 *)0x3;
    _DAT_14000e888 = (ulonglong)*param_1;
    _DAT_14000e890 = *(undefined8 *)(param_1 + 2);
    _DAT_14000e898 = *(undefined8 *)(param_1 + 4);
    _DAT_14000e8a0 = *(undefined8 *)(param_1 + 6);
    _DAT_14000e8a8 = *(undefined8 *)(param_1 + 8);
    _DAT_14000e8b0 = *(undefined8 *)(param_1 + 10);
    _DAT_14000e8b8 = *(undefined8 *)(param_1 + 0xc);
    _DAT_14000e8c0 = *(undefined8 *)(param_1 + 0xe);
    WdLogLiveDumpBreakpoint();
    memset(&WdLogLiveDumpInfo,0,0x48);
    LOCK();
    WdLogLiveDumpInProgress = 0;
    UNLOCK();
    p_Var6 = (__uint64 *)KeLowerIrql(uVar4);
    if (DAT_14000e0e8 != '\0') {
      cVar5 = WdIsDebuggerPresent(`unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'
                                  ::__l20::bDebuggerPresenceInitialized == '\0');
      `unsigned_char___cdecl_WdLogEvent5(_WD_LOGEVENT_LEVEL,_WD_LOGENTRY*___ptr64)'::__l20::
      bDebuggerPresenceInitialized = '\x01';
      p_Var6 = (__uint64 *)
               DbgPrintEx(0x65,0,"\n*** Display Driver Model %s detected @%Ix.\n","warning message",
                          *(undefined8 *)(param_1 + 4));
      if (cVar5 != '\0') {
        uVar9 = 0;
        pp_Var8 = &WdLogIgnore;
        do {
          p_Var6 = *pp_Var8;
          if (p_Var6 == *(__uint64 **)(param_1 + 4)) goto LAB_1400070d6;
          uVar9 = uVar9 + 1;
          pp_Var8 = pp_Var8 + 1;
        } while (uVar9 < 0x10);
        while( true ) {
          local_res10[0] = 0;
          DbgPrompt("Break to debug, break then Repeat message, Ignore, ignore All (bria)? ",
                    local_res10,2);
          p_Var6 = (__uint64 *)(ulonglong)local_res10[0];
          if ((local_res10[0] - 0x42 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x52 & 0xdf) == 0) {
            pcVar2 = (code *)swi(3);
            uVar7 = (*pcVar2)();
            return uVar7;
          }
          if ((local_res10[0] - 0x49 & 0xdf) == 0) break;
          if (((char)local_res10[0] + 0xbfU & 0xdf) == 0) {
            uVar9 = 0;
            pp_Var8 = &WdLogIgnore;
            do {
              uVar7 = (ulonglong)uVar9;
              uVar9 = uVar9 + 1;
              if (*pp_Var8 == (__uint64 *)0x0) {
                uVar1 = *(undefined8 *)(param_1 + 4);
                (&WdLogIgnore)[uVar7] = *(__uint64 **)(param_1 + 4);
                p_Var6 = (__uint64 *)
                         DbgPrintEx(0x65,0,"*** Added %Ix to ignore list - entry %u of %u...",uVar1,
                                    uVar9,0x10);
                goto LAB_1400070d6;
              }
              pp_Var8 = pp_Var8 + 1;
            } while (uVar9 < 0x10);
            DbgPrintEx(0x65,0,"*** Can\'t add %Ix to ignore list - list is full at %u entries.",
                       *(undefined8 *)(param_1 + 4),uVar9);
          }
          else {
            DbgPrintEx(0x65,0,"*** Invalid response, please try again...");
          }
        }
      }
    }
  }
LAB_1400070d6:
  return (ulonglong)p_Var6 & 0xffffffffffffff00;
}



===== WdLogNewEntry5_WdAssertion @ 140007100 =====

_WD_LOGENTRY * WdLogNewEntry5_WdAssertion(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x7100  100  WdLogNewEntry5_WdAssertion */
  if (DAT_14000e0a8 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e0b0 - 1U & DAT_14000e0b4) * 0x40 + DAT_14000e0a8);
    LOCK();
    UNLOCK();
    DAT_14000e0b4 = DAT_14000e0b4 + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== WdLogNewEntry5_WdCriticalError @ 140007180 =====

_WD_LOGROOT * WdLogNewEntry5_WdCriticalError(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x7180  101  WdLogNewEntry5_WdCriticalError */
  if (WdLogRoot == (_WD_LOGROOT *)0x0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)(WdLogRoot + (ulonglong)(DAT_14000e098 - 1U & DAT_14000e09c) * 0x40);
    LOCK();
    UNLOCK();
    DAT_14000e09c = DAT_14000e09c + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return (_WD_LOGROOT *)p_Var2;
}



===== WdLogNewEntry5_WdDebug @ 140007200 =====

_WD_LOGENTRY * WdLogNewEntry5_WdDebug(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x7200  102  WdLogNewEntry5_WdDebug */
  if (DAT_14000e180 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e188 - 1U & DAT_14000e18c) * 0x40 + DAT_14000e180);
    LOCK();
    UNLOCK();
    DAT_14000e18c = DAT_14000e18c + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== WdLogNewEntry5_WdDmmEvent @ 140007280 =====

_WD_LOGENTRY * WdLogNewEntry5_WdDmmEvent(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x7280  103  WdLogNewEntry5_WdDmmEvent */
  if (DAT_14000e138 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e140 - 1U & DAT_14000e144) * 0x40 + DAT_14000e138);
    LOCK();
    UNLOCK();
    DAT_14000e144 = DAT_14000e144 + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== WdLogNewEntry5_WdLowResource @ 140007300 =====

_WD_LOGENTRY * WdLogNewEntry5_WdLowResource(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x7300  106  WdLogNewEntry5_WdLowResource */
  if (DAT_14000e120 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e128 - 1U & DAT_14000e12c) * 0x40 + DAT_14000e120);
    LOCK();
    UNLOCK();
    DAT_14000e12c = DAT_14000e12c + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== WdLogNewEntry5_WdPower @ 140007380 =====

_WD_LOGENTRY * WdLogNewEntry5_WdPower(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x7380  107  WdLogNewEntry5_WdPower */
  if (DAT_14000e168 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e170 - 1U & DAT_14000e174) * 0x40 + DAT_14000e168);
    LOCK();
    UNLOCK();
    DAT_14000e174 = DAT_14000e174 + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== WdLogNewEntry5_WdPresentTokenEvent @ 140007400 =====

_WD_LOGENTRY * WdLogNewEntry5_WdPresentTokenEvent(void)

{
  ulong uVar1;
  _WD_LOGENTRY *p_Var2;
  undefined8 unaff_retaddr;
  
                    /* 0x7400  108  WdLogNewEntry5_WdPresentTokenEvent */
  if (DAT_14000e150 == 0) {
    p_Var2 = &WdLogDummyEntry;
  }
  else {
    LOCK();
    UNLOCK();
    p_Var2 = (_WD_LOGENTRY *)
             ((ulonglong)(DAT_14000e158 - 1U & DAT_14000e15c) * 0x40 + DAT_14000e150);
    LOCK();
    UNLOCK();
    DAT_14000e15c = DAT_14000e15c + 1;
    uVar1 = WdEventOrder + 1;
    *(ulong *)p_Var2 = WdEventOrder;
    WdEventOrder = uVar1;
    *(void **)(p_Var2 + 8) = SystemReserved1[0xf];
    *(undefined8 *)(p_Var2 + 0x10) = unaff_retaddr;
  }
  *(undefined8 *)(p_Var2 + 0x38) = 0;
  *(undefined8 *)(p_Var2 + 0x30) = 0;
  *(undefined8 *)(p_Var2 + 0x28) = 0;
  *(undefined8 *)(p_Var2 + 0x20) = 0;
  *(undefined8 *)(p_Var2 + 0x18) = 0;
  return p_Var2;
}



===== WdQueryDebugFlag @ 140007480 =====

bool WdQueryDebugFlag(int param_1)

{
  char cVar1;
  
                    /* 0x7480  118  WdQueryDebugFlag */
  if (param_1 == 0) {
    cVar1 = DAT_14000e0b8;
  }
  else {
    if (param_1 != 1) {
      return false;
    }
    cVar1 = DAT_14000e0d0;
  }
  return cVar1 != '\0';
}



===== `scalar_deleting_destructor' @ 1400074b0 =====

/* public: virtual void * __ptr64 __cdecl CDisplayContextBase<class
   CDisplayScenarioContext>::`scalar deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CDisplayContextBase<CDisplayScenarioContext>::_scalar_deleting_destructor_
          (CDisplayContextBase<CDisplayScenarioContext> *this,uint param_1)

{
  ~CDisplayContextBase<CDisplayScenarioContext>(this);
  if ((param_1 & 1) != 0) {
    operator_delete__(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1400074f0 =====

/* protected: virtual void * __ptr64 __cdecl CDisplayJournalBase::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CDisplayJournalBase::_scalar_deleting_destructor_(CDisplayJournalBase *this,uint param_1)

{
  ~CDisplayJournalBase(this);
  if ((param_1 & 1) != 0) {
    operator_delete__(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140007530 =====

/* public: virtual void * __ptr64 __cdecl CDisplayRestoreVidPnJournal::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CDisplayRestoreVidPnJournal::_vector_deleting_destructor_
          (CDisplayRestoreVidPnJournal *this,uint param_1)

{
  ~CDisplayRestoreVidPnJournal(this);
  if ((param_1 & 1) != 0) {
    operator_delete__(this);
  }
  return this;
}



===== Callback @ 140007570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl WatchdogTimeoutReport::Callback(void) __ptr64 */

void __thiscall WatchdogTimeoutReport::Callback(WatchdogTimeoutReport *this)

{
                    /* 0x7570  3  ?Callback@WatchdogTimeoutReport@@QEAAXXZ */
  if (*(code **)(this + 0xf0) != (code *)0x0) {
    (**(code **)(this + 0xf0))();
  }
  return;
}



===== Filter @ 1400075a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: bool __cdecl WatchdogTimeoutReport::Filter(void) __ptr64 */

bool __thiscall WatchdogTimeoutReport::Filter(WatchdogTimeoutReport *this)

{
  undefined1 uVar1;
  
                    /* 0x75a0  12  ?Filter@WatchdogTimeoutReport@@QEAA_NXZ */
  if (*(code **)(this + 0xf8) == (code *)0x0) {
    uVar1 = 1;
  }
  else {
    uVar1 = (**(code **)(this + 0xf8))();
  }
  return (bool)uVar1;
}



===== WdpProcessWatchdogTimeoutReportThread @ 1400075d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl WdpProcessWatchdogTimeoutReportThread(void * __ptr64) */

void __cdecl WdpProcessWatchdogTimeoutReportThread(void *param_1)

{
  uint uVar1;
  longlong lVar2;
  
  if (param_1 != (void *)0x0) {
    lVar2 = WdDbgReportCreate(0,*(uint *)((longlong)param_1 + 0xc4),
                              *(longlong *)((longlong)param_1 + 200),
                              *(longlong *)((longlong)param_1 + 0xd0),
                              *(longlong *)((longlong)param_1 + 0xd8),
                              *(longlong *)((longlong)param_1 + 0xe0),
                              *(byte *)((longlong)param_1 + 0xe8));
    if (lVar2 == 0) {
      WdLogSingleEntry1(2,0);
      _WdLogGlobalForLineNumber = 0x3bf;
    }
    else {
      uVar1 = WdDbgReportComplete(lVar2);
      if ((int)uVar1 < 0) {
        WdLogSingleEntry1(2,(longlong)(int)uVar1);
        _WdLogGlobalForLineNumber = 0x3b6;
      }
    }
    WatchdogTimeoutReport::Callback(param_1);
    KeSetEvent((longlong)param_1 + 0xa8,0,0);
  }
  return;
}



===== WdpWatchdogTimeoutReportDpcCallback @ 140007690 =====

/* void __cdecl WdpWatchdogTimeoutReportDpcCallback(struct _KDPC * __ptr64,void * __ptr64,void *
   __ptr64,void * __ptr64) */

void __cdecl
WdpWatchdogTimeoutReportDpcCallback(_KDPC *param_1,void *param_2,void *param_3,void *param_4)

{
  bool bVar1;
  
  if (((param_2 != (void *)0x0) && (*(char *)param_2 != '\0')) &&
     (bVar1 = WatchdogTimeoutReport::Filter(param_2), bVar1)) {
    LOCK();
    bVar1 = WatchdogTimeoutReport::ReportCount == 0;
    if (bVar1) {
      WatchdogTimeoutReport::ReportCount = 1;
    }
    UNLOCK();
    if (bVar1) {
      KeClearEvent((longlong)param_2 + 0xa8);
      ExQueueWorkItem((longlong)param_2 + 0x88,0);
    }
  }
  return;
}



===== WdResetWatch @ 140007700 =====

void WdResetWatch(longlong param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  
                    /* 0x7700  125  WdResetWatch */
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  if (*(int *)(param_1 + 0x38) != 0) {
    *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(param_1 + 0x58);
    uVar2 = KeQueryRuntimeThread(*(undefined8 *)(param_1 + 0x60),param_1 + 0x44);
    lVar3 = *(longlong *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    if (lVar3 < -0x3fffffff) {
      lVar3 = -0x3fffffff;
    }
    if (*(int *)(param_1 + 0x3c) == 0) {
      KeSetTimerEx(param_1 + 0x68,lVar3,0,param_1 + 0xa8);
    }
  }
  KeReleaseSpinLock(param_1 + 0x28,uVar1);
  return;
}



===== WdResumeWatch @ 1400077b0 =====

void WdResumeWatch(longlong param_1,char param_2)

{
  bool bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  longlong lVar5;
  
                    /* 0x77b0  127  WdResumeWatch */
  bVar1 = false;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  if (*(int *)(param_1 + 0x3c) != 0) {
    if (param_2 == '\x01') {
      iVar4 = *(int *)(param_1 + 0x3c) + -1;
      *(int *)(param_1 + 0x3c) = iVar4;
      if (iVar4 != 0) goto LAB_140007803;
    }
    else {
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    bVar1 = true;
  }
LAB_140007803:
  if (((*(int *)(param_1 + 0x38) != 0) && (bVar1)) && (*(longlong *)(param_1 + 0x50) != 0)) {
    uVar3 = KeQueryRuntimeThread(*(undefined8 *)(param_1 + 0x60),param_1 + 0x44);
    lVar5 = *(longlong *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x40) = uVar3;
    if (lVar5 < -0x3fffffff) {
      lVar5 = -0x3fffffff;
    }
    KeSetTimerEx(param_1 + 0x68,lVar5,0,param_1 + 0xa8);
  }
  KeReleaseSpinLock(param_1 + 0x28,uVar2);
  return;
}



===== WdStartWatch @ 140007890 =====

void WdStartWatch(longlong param_1,longlong param_2,undefined8 param_3)

{
  void *pvVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
                    /* 0x7890  130  WdStartWatch */
  if (0 < param_2) {
    param_2 = -param_2;
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  if (*(int *)(param_1 + 0x38) != -1) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  }
  pvVar1 = SystemReserved1[0xf];
  *(void **)(param_1 + 0x60) = SystemReserved1[0xf];
  *(undefined8 *)(param_1 + 0xe8) = param_3;
  *(longlong *)(param_1 + 0x50) = param_2;
  *(longlong *)(param_1 + 0x58) = param_2;
  uVar3 = KeQueryRuntimeThread(pvVar1,param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x40) = uVar3;
  if (param_2 < -0x3fffffff) {
    param_2 = -0x3fffffff;
  }
  if (*(int *)(param_1 + 0x3c) == 0) {
    KeSetTimerEx(param_1 + 0x68,param_2,0,param_1 + 0xa8);
  }
  KeReleaseSpinLock(param_1 + 0x28,uVar2);
  return;
}



===== WdStopWatch @ 140007970 =====

void WdStopWatch(int *param_1,char param_2)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  
                    /* 0x7970  132  WdStopWatch */
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 10);
  if (param_1[0xe] != 0) {
    iVar3 = param_1[0xe] + -1;
    if (param_2 != '\x01') {
      iVar3 = 0;
    }
    param_1[0xe] = iVar3;
    if (iVar3 == 0) {
      KeCancelTimer(param_1 + 0x1a);
      if (*(longlong *)(param_1 + 0x3a) != 0) {
        cVar2 = KeRemoveQueueDpc();
        if (cVar2 == '\x01') {
          WdCompleteEvent(param_1,*(longlong *)(param_1 + 8));
        }
      }
      param_1[0x10] = 0;
      param_1[0x11] = 0;
      param_1[0x14] = 0;
      param_1[0x15] = 0;
      param_1[0x16] = 0;
      param_1[0x17] = 0;
      param_1[0x18] = 0;
      param_1[0x19] = 0;
      param_1[0x3a] = 0;
      param_1[0x3b] = 0;
      param_1[8] = 0;
      param_1[9] = 0;
    }
  }
  KeReleaseSpinLock(param_1 + 10,uVar1);
  return;
}



===== WdSuspendWatch @ 140007a50 =====

void WdSuspendWatch(longlong param_1)

{
  undefined1 uVar1;
  
                    /* 0x7a50  134  WdSuspendWatch */
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  if ((*(int *)(param_1 + 0x3c) == 0) && (*(int *)(param_1 + 0x38) != 0)) {
    KeCancelTimer(param_1 + 0x68);
  }
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  KeReleaseSpinLock(param_1 + 0x28,uVar1);
  return;
}



===== WdpWatchdogDpcCallback @ 140007ac0 =====

void WdpWatchdogDpcCallback(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  bool bVar9;
  uint local_res10 [6];
  
  local_res10[0] = 0;
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x28);
  uVar5 = KeQueryRuntimeThread(*(undefined8 *)(param_2 + 0x60),local_res10);
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == 1) {
    uVar2 = *(uint *)(param_2 + 0x40);
    bVar9 = uVar5 < uVar2;
    uVar3 = uVar5;
LAB_140007b52:
    uVar6 = (ulonglong)uVar3;
    uVar7 = (ulonglong)uVar2;
    if (bVar9) {
      uVar6 = uVar6 + -uVar2;
    }
  }
  else {
    if (iVar1 == 2) {
      uVar2 = *(uint *)(param_2 + 0x44);
      bVar9 = local_res10[0] < uVar2;
      uVar3 = local_res10[0];
      goto LAB_140007b52;
    }
    if (iVar1 != 3) {
      lVar8 = 0;
      goto LAB_140007b5e;
    }
    uVar2 = *(uint *)(param_2 + 0x40);
    uVar6 = (ulonglong)(local_res10[0] + uVar5);
    if (uVar5 < uVar2) {
      uVar6 = uVar6 + -uVar2;
    }
    uVar3 = *(uint *)(param_2 + 0x44);
    if (local_res10[0] < uVar3) {
      uVar6 = uVar6 + -uVar3;
    }
    uVar7 = (ulonglong)(uVar3 + uVar2);
  }
  lVar8 = uVar6 - uVar7;
LAB_140007b5e:
  *(uint *)(param_2 + 0x40) = uVar5;
  lVar8 = (ulonglong)*(uint *)(param_2 + 0x48) * lVar8 + *(longlong *)(param_2 + 0x50);
  *(longlong *)(param_2 + 0x50) = lVar8;
  *(uint *)(param_2 + 0x44) = local_res10[0];
  if (lVar8 < 0) {
    if (lVar8 < -0x3fffffff) {
      lVar8 = -0x3fffffff;
    }
    KeSetTimerEx(param_2 + 0x68,lVar8,0,param_2 + 0xa8);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 2;
    if (*(longlong *)(param_2 + 0xe8) != 0) {
      ObfReferenceObject(*(undefined8 *)(param_2 + 0x60));
      LOCK();
      *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
      UNLOCK();
      cVar4 = KeInsertQueueDpc(*(undefined8 *)(param_2 + 0xe8),*(undefined8 *)(param_2 + 0x60),
                               param_2);
      if (cVar4 == '\0') {
        ObfDereferenceObject();
        WdDereferenceObject(param_2);
      }
      else {
        *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(param_2 + 0x60);
      }
    }
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  KeReleaseSpinLockFromDpcLevel(param_2 + 0x28);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140007c2c =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000dd1f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140007c54 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140007da0 =====

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



===== WdEnterMonitoredSection @ 140007e30 =====

void WdEnterMonitoredSection(longlong param_1)

{
  void *pvVar1;
  void *pvVar2;
  undefined1 uVar3;
  int iVar4;
  bool bVar5;
  
                    /* 0x7e30  78  WdEnterMonitoredSection */
  pvVar2 = SystemReserved1[0xf];
  LOCK();
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  UNLOCK();
  LOCK();
  pvVar1 = *(void **)(param_1 + 0x68);
  *(void **)(param_1 + 0x68) = pvVar2;
  UNLOCK();
  if (pvVar1 != pvVar2) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
    LOCK();
    *(void **)(param_1 + 0x68) = pvVar2;
    UNLOCK();
    iVar4 = *(int *)(param_1 + 0x48) + 1;
    bVar5 = *(int *)(param_1 + 0x40) != iVar4;
    if (!bVar5) {
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
    *(bool *)(param_1 + 0xf8) = bVar5;
    KeReleaseSpinLock(param_1 + 0x28,CONCAT31((int3)((uint)iVar4 >> 8),uVar3));
  }
  LOCK();
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
  UNLOCK();
  return;
}



===== WdExitMonitoredSection @ 140007ec0 =====

void WdExitMonitoredSection(longlong param_1)

{
  undefined1 uVar1;
  
                    /* 0x7ec0  79  WdExitMonitoredSection */
  LOCK();
  *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
  UNLOCK();
  if (*(char *)(param_1 + 0xf8) != '\0') {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
    if (*(int *)(param_1 + 0x40) == *(int *)(param_1 + 0x48)) {
      *(undefined1 *)(param_1 + 0xf8) = 0;
    }
    KeReleaseSpinLock(param_1 + 0x28,CONCAT31((int3)((uint)*(int *)(param_1 + 0x40) >> 8),uVar1));
  }
  return;
}



===== WdMadeAnyProgress @ 140007f20 =====

undefined8 WdMadeAnyProgress(longlong param_1)

{
  ulonglong uVar1;
  
                    /* 0x7f20  117  WdMadeAnyProgress */
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x40);
  if ((((*(uint *)(param_1 + 0x40) == *(uint *)(param_1 + 0x44)) &&
       (uVar1 = (ulonglong)*(uint *)(param_1 + 0x40),
       *(uint *)(param_1 + 0x40) == *(uint *)(param_1 + 0x4c))) &&
      (uVar1 = (ulonglong)*(uint *)(param_1 + 0x50),
      *(uint *)(param_1 + 0x48) == *(uint *)(param_1 + 0x50))) &&
     (uVar1 = (ulonglong)*(uint *)(param_1 + 0x40),
     *(uint *)(param_1 + 0x40) != *(uint *)(param_1 + 0x48))) {
    return 0;
  }
  return CONCAT71((int7)(uVar1 >> 8),1);
}



===== WdResetDeferredWatch @ 140007f50 =====

void WdResetDeferredWatch(longlong param_1)

{
  undefined1 uVar1;
  
                    /* 0x7f50  124  WdResetDeferredWatch */
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined1 *)(param_1 + 0xf8) = 0;
  KeReleaseSpinLock(param_1 + 0x28,uVar1);
  return;
}



===== WdResumeDeferredWatch @ 140007fb0 =====

int WdResumeDeferredWatch(longlong param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  
                    /* 0x7fb0  126  WdResumeDeferredWatch */
  if (param_2 == '\x01') {
    LOCK();
    piVar1 = (int *)(param_1 + 0x3c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    iVar2 = iVar2 + -1;
    if (iVar2 == -1) {
      LOCK();
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      UNLOCK();
      return -1;
    }
  }
  else {
    LOCK();
    iVar2 = *(int *)(param_1 + 0x3c);
    *(int *)(param_1 + 0x3c) = 0;
    UNLOCK();
  }
  return iVar2;
}



===== WdStartDeferredWatch @ 140007fe0 =====

void WdStartDeferredWatch(longlong param_1,undefined8 param_2,int param_3)

{
  undefined1 uVar1;
  
                    /* 0x7fe0  129  WdStartDeferredWatch */
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  *(int *)(param_1 + 0x38) = param_3;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined1 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 100) = 2;
  *(undefined8 *)(param_1 + 0xf0) = param_2;
  KeReleaseSpinLock(param_1 + 0x28,uVar1);
  KeSetTimerEx(param_1 + 0x70,(longlong)(param_3 * -5000),param_3,param_1 + 0xb0);
  return;
}



===== WdStopDeferredWatch @ 140008090 =====

void WdStopDeferredWatch(int *param_1)

{
  undefined1 uVar1;
  char cVar2;
  
                    /* 0x8090  131  WdStopDeferredWatch */
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 10);
  if (param_1[0x19] == 2) {
    KeCancelTimer(param_1 + 0x1c);
    if (*(longlong *)(param_1 + 0x3c) != 0) {
      if (param_1[7] == 2) {
        KeRemoveQueueDpc();
        WdpQueueDeferredEvent((longlong)param_1,3);
      }
      else {
        cVar2 = KeRemoveQueueDpc();
        if (cVar2 == '\x01') {
          WdCompleteEvent(param_1,*(longlong *)(param_1 + 8));
        }
      }
    }
    param_1[0xe] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 1;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
    param_1[0x3c] = 0;
    param_1[0x3d] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    *(undefined1 *)(param_1 + 0x3e) = 0;
  }
  KeReleaseSpinLock(param_1 + 10,uVar1);
  return;
}



===== WdSuspendDeferredWatch @ 140008180 =====

void WdSuspendDeferredWatch(longlong param_1)

{
                    /* 0x8180  133  WdSuspendDeferredWatch */
  LOCK();
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  UNLOCK();
  return;
}



===== WdpDeferredWatchdogDpcCallback @ 140008190 =====

void WdpDeferredWatchdogDpcCallback(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  bool bVar8;
  uint local_res10 [6];
  
  local_res10[0] = 0;
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x28);
  if ((*(char *)(param_2 + 0xf8) != '\0') && (*(int *)(param_2 + 0x44) == *(int *)(param_2 + 0x48)))
  {
    *(undefined1 *)(param_2 + 0xf8) = 0;
  }
  if (((*(int *)(param_2 + 100) != 2) || (*(int *)(param_2 + 0x40) != *(int *)(param_2 + 0x44))) ||
     (*(longlong *)(param_2 + 0x68) == 0)) goto LAB_140008359;
  iVar1 = *(int *)(param_2 + 0x60);
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 0x3c) != 0) goto LAB_140008359;
    if ((*(int *)(param_2 + 0x1c) == 2) &&
       (((*(int *)(param_2 + 0x40) != *(int *)(param_2 + 0x4c) ||
         (*(int *)(param_2 + 0x48) != *(int *)(param_2 + 0x50))) ||
        (*(int *)(param_2 + 0x40) == *(int *)(param_2 + 0x48))))) {
      WdpQueueDeferredEvent(param_2,3);
    }
    if (*(int *)(param_2 + 0x40) == *(int *)(param_2 + 0x48)) goto LAB_140008359;
LAB_14000832f:
    *(undefined4 *)(param_2 + 0x4c) = *(undefined4 *)(param_2 + 0x40);
    *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(param_2 + 0x60) = 1;
    uVar4 = KeQueryRuntimeThread(*(undefined8 *)(param_2 + 0x68),param_2 + 0x58);
    *(undefined4 *)(param_2 + 0x54) = uVar4;
    goto LAB_140008359;
  }
  if (iVar1 == 1) {
    if ((*(int *)(param_2 + 0x40) != *(int *)(param_2 + 0x48)) && (*(int *)(param_2 + 0x3c) == 0)) {
      if ((*(int *)(param_2 + 0x40) != *(int *)(param_2 + 0x4c)) ||
         (*(int *)(param_2 + 0x48) != *(int *)(param_2 + 0x50))) goto LAB_14000832f;
      uVar3 = KeQueryRuntimeThread(*(undefined8 *)(param_2 + 0x68),local_res10);
      iVar1 = *(int *)(param_2 + 0x18);
      if (iVar1 == 1) {
        uVar2 = *(uint *)(param_2 + 0x54);
        bVar8 = uVar3 < uVar2;
LAB_1400082a3:
        uVar7 = (ulonglong)uVar2;
        uVar5 = (ulonglong)uVar3;
        if (bVar8) {
          uVar5 = uVar5 + -uVar2;
        }
LAB_1400082ac:
        lVar6 = uVar5 - uVar7;
      }
      else {
        if (iVar1 == 2) {
          uVar2 = *(uint *)(param_2 + 0x58);
          bVar8 = local_res10[0] < uVar2;
          uVar3 = local_res10[0];
          goto LAB_1400082a3;
        }
        if (iVar1 == 3) {
          uVar2 = *(uint *)(param_2 + 0x54);
          uVar5 = (ulonglong)(local_res10[0] + uVar3);
          if (uVar3 < uVar2) {
            uVar5 = uVar5 + -uVar2;
          }
          uVar3 = *(uint *)(param_2 + 0x58);
          if (local_res10[0] < uVar3) {
            uVar5 = uVar5 + -uVar3;
          }
          uVar7 = (ulonglong)(uVar3 + uVar2);
          goto LAB_1400082ac;
        }
        lVar6 = 0;
      }
      if ((*(char *)(param_2 + 0xf8) == '\0') &&
         ((longlong)*(int *)(param_2 + 0x38) <=
          (longlong)((ulonglong)*(uint *)(param_2 + 0x5c) * lVar6) / 10000)) {
        WdpQueueDeferredEvent(param_2,2);
      }
      goto LAB_140008359;
    }
  }
  else if (iVar1 == 2) goto LAB_140008359;
  *(undefined4 *)(param_2 + 0x60) = 0;
LAB_140008359:
  KeReleaseSpinLockFromDpcLevel(param_2 + 0x28);
  return;
}



===== WdpQueueDeferredEvent @ 140008378 =====

undefined1 WdpQueueDeferredEvent(longlong param_1,int param_2)

{
  char cVar1;
  
  if (*(longlong *)(param_1 + 0xf0) == 0) {
    return 0;
  }
  if (param_2 == 2) {
    *(undefined4 *)(param_1 + 0x1c) = 2;
    ObfReferenceObject(*(undefined8 *)(param_1 + 0x68));
    LOCK();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    UNLOCK();
    cVar1 = KeInsertQueueDpc(*(undefined8 *)(param_1 + 0xf0),*(undefined8 *)(param_1 + 0x68),param_1
                            );
    if (cVar1 != '\x01') {
      ObfDereferenceObject();
      goto LAB_140008428;
    }
    *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(param_1 + 0x68);
  }
  else {
    if (param_2 != 3) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x1c) = 3;
    LOCK();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    UNLOCK();
    cVar1 = KeInsertQueueDpc(*(undefined8 *)(param_1 + 0xf0),0,param_1);
    if (cVar1 != '\x01') {
LAB_140008428:
      WdDereferenceObject(param_1);
      return 0;
    }
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  *(undefined4 *)(param_1 + 0x60) = 2;
  return 1;
}



===== WdAttachContext @ 140008450 =====

void WdAttachContext(longlong param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
                    /* 0x8450  60  WdAttachContext */
  uVar1 = ExAllocatePool2(0x40,param_2,*(undefined4 *)(param_1 + 8));
  *(undefined8 *)(param_1 + 0x30) = uVar1;
  return;
}



===== WdCompleteEvent @ 140008490 =====

void WdCompleteEvent(int *param_1,longlong param_2)

{
                    /* 0x8490  61  WdCompleteEvent */
  if (*param_1 == 0x57446457) {
    LOCK();
    param_1[0x18] = 0;
    UNLOCK();
  }
  if (param_2 != 0) {
    ObfDereferenceObject(param_2);
  }
  WdDereferenceObject((longlong)param_1);
  return;
}



===== WdDereferenceObject @ 1400084d0 =====

void WdDereferenceObject(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* 0x84d0  71  WdDereferenceObject */
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    WdpDestroyObject(param_1);
  }
  return;
}



===== WdDetachContext @ 140008500 =====

void WdDetachContext(longlong param_1)

{
                    /* 0x8500  72  WdDetachContext */
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0);
  *(undefined8 *)(param_1 + 0x30) = 0;
  return;
}



===== WdGetDeviceObject @ 140008530 =====

undefined8 WdGetDeviceObject(longlong param_1)

{
  undefined8 uVar1;
  
                    /* 0x8530  82  WdGetDeviceObject */
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  ObfReferenceObject(uVar1);
  return uVar1;
}



===== WdGetLastEvent @ 140008560 =====

undefined4 WdGetLastEvent(longlong param_1)

{
                    /* 0x8560  83  WdGetLastEvent */
  return *(undefined4 *)(param_1 + 0x1c);
}



===== WdGetLowestDeviceObject @ 140008570 =====

void WdGetLowestDeviceObject(longlong param_1)

{
                    /* 0x8570  84  WdGetLowestDeviceObject */
  IoGetDeviceAttachmentBaseRef(*(undefined8 *)(param_1 + 0x10));
  return;
}



===== WdReferenceObject @ 140008590 =====

void WdReferenceObject(longlong param_1)

{
                    /* 0x8590  119  WdReferenceObject */
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  UNLOCK();
  return;
}



===== WdpDestroyObject @ 14000859c =====

void WdpDestroyObject(longlong param_1)

{
  ObfDereferenceObject(*(undefined8 *)(param_1 + 0x10));
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WdpDbgCaptureKernelDump @ 1400085ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl WdpDbgCaptureKernelDump(struct _WD_DEBUG_REPORT * __ptr64) */

long __cdecl WdpDbgCaptureKernelDump(_WD_DEBUG_REPORT *param_1)

{
  int iVar1;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a0 = 0;
  local_38 = 0;
  local_a8 = 0;
  local_18 = 0;
  local_74 = *(undefined4 *)(param_1 + 8);
  local_70 = *(undefined8 *)(param_1 + 0x10);
  local_68 = *(undefined8 *)(param_1 + 0x18);
  local_60 = *(undefined8 *)(param_1 + 0x20);
  local_58 = *(undefined8 *)(param_1 + 0x28);
  local_50 = *(undefined8 *)(param_1 + 0x2b0);
  local_48 = 0;
  local_78 = 1;
  local_90 = 0;
  uStack_88 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uStack_40 = (ulonglong)(((byte)param_1[0x2b8] & 2) * 2 | (byte)param_1[0x2b8] & 8);
  iVar1 = ZwSystemDebugControl(0x25,&local_78,0x48);
  if (iVar1 < 0) {
    WdLogSingleEntry1(2,(longlong)iVar1);
    _WdLogGlobalForLineNumber = 0x49e;
  }
  else {
    local_a8 = 5;
    iVar1 = ZwQueryInformationFile(*(undefined8 *)(param_1 + 0x2b0),&local_90,&local_28,0x18);
    if (iVar1 < 0) {
      WdLogSingleEntry1(2,(longlong)iVar1);
      _WdLogGlobalForLineNumber = 0x4b4;
    }
    else {
      local_98 = uStack_20;
      local_a8 = 0xe;
      iVar1 = ZwSetInformationFile(*(undefined8 *)(param_1 + 0x2b0),&local_90,&local_98,8);
      if (iVar1 < 0) {
        WdLogSingleEntry1(2,(longlong)iVar1);
        _WdLogGlobalForLineNumber = 0x4c8;
      }
    }
  }
  return iVar1;
}



===== Feature_TVSDumpBugFix__private_IsEnabledDeviceUsageNoInline @ 140008798 =====

ulonglong Feature_TVSDumpBugFix__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_TVSDumpBugFix__private_featureState;
  if ((Feature_TVSDumpBugFix__private_featureState & 0x10) == 0) {
    uVar1 = Feature_TVSDumpBugFix__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_TVSDumpBugFix__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_TVSDumpBugFix__private_IsEnabledFallback @ 1400087d0 =====

void Feature_TVSDumpBugFix__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== WdpAppendSecondaryMinidumpData @ 1400087e8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
WdpAppendSecondaryMinidumpData
          (undefined8 *param_1,void *param_2,uint param_3,longlong param_4,uint param_5)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = param_3 + 0x40030;
  uVar3 = WdpDbgReportGetExtSizeByGuid((undefined *)param_1);
  uVar5 = (int)uVar3 + 0xc0000;
  uVar7 = (int)uVar3 + 0x7ffd0;
  if (uVar5 < param_5) {
    WdLogSingleEntry2(1,(ulonglong)param_5,(ulonglong)uVar5);
    _WdLogGlobalForLineNumber = 0xb9;
    param_5 = uVar5;
  }
  if (((((param_4 == 0) || (param_2 == (void *)0x0)) || (param_3 == 0)) || (param_5 < uVar6)) ||
     ((uVar4 = Feature_TVSDumpBugFix__private_IsEnabledDeviceUsageNoInline(), (int)uVar4 != 0 &&
      ((ulonglong)param_5 + param_4 < (ulonglong)param_3 + 0x40030 + param_4)))) {
    uVar2 = 0;
  }
  else {
    while( true ) {
      uVar5 = param_3 - 1;
      if ((uVar5 == 0) || (*(char *)((ulonglong)uVar5 + (longlong)param_2) != '\0')) break;
      param_3 = uVar5;
    }
    if (uVar7 < param_3) {
      WdLogSingleEntry2(1,(ulonglong)param_3,(ulonglong)uVar7);
      _WdLogGlobalForLineNumber = 0xe3;
      param_3 = uVar7;
    }
    *(ulonglong *)(param_4 + 4000) = (ulonglong)uVar6;
    *(undefined4 *)(param_4 + 0x40000) = 0x706d7544;
    *(undefined4 *)(param_4 + 0x40004) = 0x626f6c42;
    *(undefined4 *)(param_4 + 0x40008) = 0x10;
    uVar2 = WdpGetBuildNumber();
    *(undefined4 *)(param_4 + 0x4000c) = uVar2;
    *(undefined4 *)(param_4 + 0x40010) = 0x20;
    uVar3 = *param_1;
    uVar1 = param_1[1];
    *(undefined8 *)(param_4 + 0x40028) = 0;
    *(undefined8 *)(param_4 + 0x40014) = uVar3;
    *(undefined8 *)(param_4 + 0x4001c) = uVar1;
    *(uint *)(param_4 + 0x40024) = param_3;
    memcpy((void *)(param_4 + 0x40030),param_2,(ulonglong)param_3);
    uVar2 = *(undefined4 *)(param_4 + 4000);
  }
  return uVar2;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140008960 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140008a44 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140008b34 =====

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
LAB_140008c90:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140008c80:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140008c90;
      if (uVar5 == 5) goto LAB_140008c80;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140008cb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x2fb4627,&Feature_DisplayBugBundle_2506_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140008d34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

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
                     (local_50,(uint *)&Feature_TVSDumpBugFix__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x2fb4627,param_3 & 0xffffffff,1,&Feature_TVSDumpBugFix__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x2fb4627);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140008e20 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140008f30 =====

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
  if ((Feature_TVSDumpBugFix__private_featureState & 2) != 0) {
    uVar1 = Feature_TVSDumpBugFix__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_TVSDumpBugFix__private_featureState;
      if (bVar3) {
        Feature_TVSDumpBugFix__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_TVSDumpBugFix__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 140008f84 =====

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



===== wil_details_IsEnabledFallback @ 1400090e4 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_TVSDumpBugFix__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_TVSDumpBugFix__private_featureState,(ulonglong)param_1,
                             0x14000db98);
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



===== wil_details_MapReportingKind @ 140009174 =====

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



===== WdDiagGetEtwHandle @ 140009220 =====

undefined8 WdDiagGetEtwHandle(void)

{
                    /* 0x9220  73  WdDiagGetEtwHandle */
  return DAT_14000ea90;
}



===== RtlStringCchPrintfW @ 140009230 =====

/* long __cdecl RtlStringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

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



===== _guard_check_icall @ 1400092c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400092d8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400092fc =====

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



===== __cpu_features_init @ 140009370 =====

/* WARNING: Removing unreachable block (ram,0x0001400093da) */
/* WARNING: Removing unreachable block (ram,0x000140009389) */
/* WARNING: Removing unreachable block (ram,0x00014000937a) */

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



===== __security_check_cookie @ 140009440 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140009480 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400094b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400094b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400094e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140009540 =====

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



===== memset @ 140009840 =====

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



===== __memset_repmovs @ 140009980 =====

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



===== __memset_query @ 140009a00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140009a80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140009bc0 =====

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



===== __memset_spec_plain @ 140009c40 =====

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



===== ~CDisplayContextBase<CDisplayScenarioContext> @ 140012008 =====

/* public: virtual __cdecl CDisplayContextBase<class
   CDisplayScenarioContext>::~CDisplayContextBase<class CDisplayScenarioContext>(void) __ptr64 */

void __thiscall
CDisplayContextBase<CDisplayScenarioContext>::~CDisplayContextBase<CDisplayScenarioContext>
          (CDisplayContextBase<CDisplayScenarioContext> *this)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  CDisplayContextBase<CDisplayScenarioContext> *pCVar4;
  
  *(undefined ***)this = &_vftable_;
  pCVar4 = this + 8;
  lVar1 = *(longlong *)pCVar4;
  if ((*(CDisplayContextBase<CDisplayScenarioContext> **)(lVar1 + 8) == pCVar4) &&
     (plVar2 = *(longlong **)(this + 0x10),
     (CDisplayContextBase<CDisplayScenarioContext> *)*plVar2 == pCVar4)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== ~CDisplayRestoreVidPnJournal @ 140012040 =====

/* public: virtual __cdecl CDisplayRestoreVidPnJournal::~CDisplayRestoreVidPnJournal(void) __ptr64
    */

void __thiscall
CDisplayRestoreVidPnJournal::~CDisplayRestoreVidPnJournal(CDisplayRestoreVidPnJournal *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(void **)(this + 0x58) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x58));
  }
  CDisplayJournalBase::~CDisplayJournalBase((CDisplayJournalBase *)this);
  return;
}



===== ~CDisplayJournalBase @ 140012078 =====

/* protected: virtual __cdecl CDisplayJournalBase::~CDisplayJournalBase(void) __ptr64 */

void __thiscall CDisplayJournalBase::~CDisplayJournalBase(CDisplayJournalBase *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(void **)(this + 0x18) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x18));
  }
  return;
}



===== WdDiagNotifyUser @ 1400120a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 WdDiagNotifyUser(undefined4 param_1,int param_2,ushort param_3,longlong param_4)

{
  longlong lVar1;
  short *psVar2;
  undefined4 uVar3;
  longlong *plVar4;
  short *psVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  ulonglong uVar8;
  undefined1 auStack_78 [32];
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_48 [2];
  undefined4 local_40;
  int local_3c;
  ushort local_38;
  undefined2 local_36;
  undefined4 local_34;
  ulonglong local_30;
  
                    /* 0x120a0  76  WdDiagNotifyUser */
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_36 = 0;
  local_34 = 0;
  local_40 = param_1;
  local_3c = param_2;
  local_38 = param_3;
  if ((param_2 - 1U & 0xfffffffd) == 0) {
    local_48[0] = 1;
    pwVar7 = (wchar_t *)0x0;
    if (param_2 == 1) {
      pwVar7 = L"TDR_RECOVERY";
    }
    else if (param_2 == 3) {
      pwVar7 = L"SDC_FORCE_MODE_ENUMERATION";
    }
    local_58 = (longlong *)local_48;
    local_50 = 4;
    RtlWriteRegistryValue(2,L"GraphicsDrivers\\TdrWatch",pwVar7);
  }
  if (DAT_14000ea90 == 0) {
    uVar3 = 0xc0000001;
  }
  else if (param_3 < 100) {
    plVar4 = (longlong *)ExAllocatePool2(0x100,((ulonglong)param_3 + 1) * 0x10,0x676f6457);
    if (plVar4 == (longlong *)0x0) {
      uVar3 = 0xc0000017;
    }
    else {
      plVar4[1] = 0x10;
      *plVar4 = (longlong)&local_40;
      for (uVar8 = 0; (ushort)uVar8 < param_3; uVar8 = (ulonglong)(ushort)((ushort)uVar8 + 1)) {
        psVar2 = *(short **)(param_4 + uVar8 * 8);
        if (psVar2 == (short *)0x0) {
LAB_140012203:
          uVar3 = 0xc000000d;
          goto LAB_140012232;
        }
        lVar6 = 0x7fff;
        psVar5 = psVar2;
        do {
          if (*psVar5 == 0) break;
          psVar5 = psVar5 + 1;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
        if (lVar6 == 0) goto LAB_140012203;
        lVar1 = uVar8 + 1;
        plVar4[lVar1 * 2] = (longlong)psVar2;
        *(uint *)(plVar4 + lVar1 * 2 + 1) = ((0x7fff - (int)lVar6) * 2 & -(uint)(lVar6 != 0)) + 2;
        *(undefined4 *)((longlong)plVar4 + lVar1 * 0x10 + 0xc) = 0;
      }
      local_58 = plVar4;
      uVar3 = EtwWrite(DAT_14000ea90,&DAT_14000e1a8,0,param_3 + 1);
LAB_140012232:
      ExFreePoolWithTag(plVar4,0x676f6457);
    }
  }
  else {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== WdDbgGetSecondaryDataMaxSize @ 140012270 =====

undefined8 WdDbgGetSecondaryDataMaxSize(int param_1)

{
  undefined8 uVar1;
  
                    /* 0x12270  64  WdDbgGetSecondaryDataMaxSize */
  if ((((((param_1 == 0x116) || (param_1 == 0x117)) || (param_1 == 0x141)) ||
       ((param_1 == 0x142 || (param_1 == 0x187)))) ||
      ((param_1 == 0x193 || ((param_1 == 0x1a8 || (param_1 == 0x1b0)))))) ||
     (uVar1 = 0x7ffd0, param_1 == 0x1b8)) {
    uVar1 = 0x105ffd0;
  }
  return uVar1;
}



===== WdpDbgReportGetExtSizeByGuid @ 1400122b4 =====

undefined8 WdpDbgReportGetExtSizeByGuid(undefined *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0xfe0000;
  if ((param_1 != &WdDxgkSecondaryDataGUID) &&
     (uVar1 = 0xfe0000, param_1 != &WdDxgkBlackScreenBlobGUID)) {
    uVar1 = 0;
  }
  return uVar1;
}



===== ReportLeaked @ 1400122dc =====

/* public: void __cdecl CDisplayScenarioContext::ReportLeaked(void) __ptr64 */

void __thiscall CDisplayScenarioContext::ReportLeaked(CDisplayScenarioContext *this)

{
  undefined8 uVar1;
  int iVar2;
  _GUID *in_R9;
  int local_res8 [2];
  undefined4 local_res10 [6];
  _tlgProvider_t *local_18;
  undefined2 local_10;
  
  if (((*(int *)(this + 0x80) != 0x34) && (this[0x1c] == (CDisplayScenarioContext)0x0)) &&
     (DAT_14000e19c != 0)) {
    iVar2 = DAT_14000e19c + -1;
    DAT_14000e19c = iVar2;
    if (5 < DAT_14000e048) {
      uVar1 = _tlgKeywordOn(this,0x400000000002);
      if ((char)uVar1 != '\0') {
        local_18 = (_tlgProvider_t *)(this + 0x84);
        local_10 = 4;
        local_res10[0] = *(undefined4 *)(this + 0x80);
        local_res8[0] = iVar2;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::Write<_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<4>_>
                  ((_tlgProvider_t *)this,&DAT_14000bb11,(_GUID *)(this + 0x20),in_R9,
                   (_tlgWrapperByVal<4> *)local_res10,(_tlgWrapperBinary *)&local_18,
                   (_tlgWrapperByVal<4> *)local_res8);
      }
    }
  }
  return;
}



===== ~CDisplayScenarioJournal @ 140012388 =====

/* public: virtual __cdecl CDisplayScenarioJournal::~CDisplayScenarioJournal(void) __ptr64 */

void __thiscall CDisplayScenarioJournal::~CDisplayScenarioJournal(CDisplayScenarioJournal *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(void **)(this + 0x90) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x90));
  }
  if (*(void **)(this + 0xa0) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xa0));
  }
  if (*(void **)(this + 0xb0) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xb0));
  }
  if (*(void **)(this + 0xc0) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xc0));
  }
  if (*(void **)(this + 0xd0) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xd0));
  }
  CDisplayJournalBase::~CDisplayJournalBase((CDisplayJournalBase *)this);
  return;
}



===== ~CDisplayScenarioContext @ 140012408 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl CDisplayScenarioContext::~CDisplayScenarioContext(void) __ptr64 */

void __thiscall CDisplayScenarioContext::~CDisplayScenarioContext(CDisplayScenarioContext *this)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  CDisplayScenarioContext *pCVar5;
  
  *(undefined ***)this = &_vftable_;
  puVar1 = *(undefined8 **)(this + 0xa8);
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  puVar1 = *(undefined8 **)(this + 0xb0);
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  *(undefined ***)this = &CDisplayContextBase<CDisplayScenarioContext>::_vftable_;
  pCVar5 = this + 8;
  lVar2 = *(longlong *)pCVar5;
  if ((*(CDisplayScenarioContext **)(lVar2 + 8) == pCVar5) &&
     (plVar3 = *(longlong **)(this + 0x10), (CDisplayScenarioContext *)*plVar3 == pCVar5)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== DMgrAcquireGdiViewId @ 140012490 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DMgrAcquireGdiViewId(ulong *param_1)

{
  ulonglong uVar1;
  
                    /* 0x12490  24  DMgrAcquireGdiViewId */
  uVar1 = DMgrInitialize();
  if (-1 < (int)uVar1) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&DAT_14000e688,0);
    if ((NumUsedGdiViews < 0x100) && (NextGdiViewId != 0xffffffff)) {
      *(ulong *)((longlong)&UsedGdiViewList + (ulonglong)NumUsedGdiViews * 4) = NextGdiViewId;
      NumUsedGdiViews = NumUsedGdiViews + 1;
      *param_1 = NextGdiViewId;
      NextGdiViewId = NextGdiViewId + 1;
      uVar1 = uVar1 & 0xffffffff;
    }
    else {
      uVar1 = 0xc0000044;
    }
    _GdiViewIdDataMutex = 0;
    ExReleasePushLockExclusiveEx(&DAT_14000e688,0);
    KeLeaveCriticalRegion();
  }
  return uVar1;
}



===== DMgrGetSmbiosInfo @ 140012580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DMgrGetSmbiosInfo(void *param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  ulonglong uVar4;
  short *psVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  short *psVar11;
  short *psVar12;
  undefined1 auStack_98 [32];
  int local_78;
  uint local_68;
  uint local_64;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48 [4];
  ulonglong local_38;
  
                    /* 0x12580  25  DMgrGetSmbiosInfo */
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  uVar7 = 0;
  local_60 = 0;
  local_68 = 0;
  local_58 = 0x8f680850;
  local_54 = 0x11d1a584;
  local_50 = 0xa00038bf;
  local_4c = 0x102906c9;
  memset(param_1,0,(ulonglong)param_2);
  iVar2 = IoWMIOpenBlock(&local_58,1,&local_60);
  if (-1 < iVar2) {
    iVar2 = IoWMIQueryAllData(local_60,&local_68,0);
    if ((iVar2 == -0x3fffffdd) && (0x43 < local_68)) {
      psVar3 = (short *)ExAllocatePool2(0x40,(ulonglong)local_68 + 8,0x676f6457);
      if (psVar3 == (short *)0x0) {
        iVar2 = -0x3fffff66;
      }
      else {
        local_64 = local_68;
        iVar2 = IoWMIQueryAllData(local_60,&local_64,psVar3);
        if (-1 < iVar2) {
          if (local_64 < local_68) {
            local_68 = local_64;
          }
          if ((0x43 < local_68) &&
             (psVar12 = (short *)((ulonglong)*(uint *)(psVar3 + 0x1e) + (longlong)psVar3),
             psVar3 <= psVar12)) {
            uVar4 = (ulonglong)local_68;
            psVar5 = (short *)(uVar4 + (longlong)psVar3);
            if ((psVar12 < psVar5) &&
               ((char *)0x7 < (char *)((uVar4 - (longlong)psVar12) + (longlong)psVar3))) {
              psVar6 = psVar12 + 4;
              psVar11 = psVar5;
              if ((short *)((ulonglong)*(uint *)(psVar12 + 2) + (longlong)psVar6) < psVar5) {
                psVar11 = (short *)((ulonglong)*(uint *)(psVar12 + 2) + (longlong)psVar6);
              }
LAB_1400126e6:
              if ((psVar6 < psVar11) && (param_2 != 0)) {
                if ((psVar3 <= psVar6) &&
                   ((psVar6 < psVar5 &&
                    ((char *)0x3 < (char *)((uVar4 - (longlong)psVar6) + (longlong)psVar3))))) {
                  if ((char)*psVar6 != '\0') goto code_r0x000140012725;
                  if ((char *)0x17 <
                      (char *)(((ulonglong)local_68 - (longlong)psVar6) + (longlong)psVar3)) {
                    local_48[0] = (uint)*(byte *)(psVar6 + 2);
                    local_48[1] = (uint)*(byte *)((longlong)psVar6 + 5);
                    local_48[2] = (uint)*(byte *)(psVar6 + 4);
                    for (uVar10 = 0; uVar10 < 3; uVar10 = uVar10 + 1) {
                      psVar5 = (short *)((ulonglong)*(byte *)((longlong)psVar6 + 1) +
                                        (longlong)psVar6);
                      for (uVar8 = 1; uVar8 < local_48[uVar10]; uVar8 = uVar8 + 1) {
                        do {
                          if (psVar11 <= psVar5) goto LAB_1400127a2;
                          sVar1 = *psVar5;
                          psVar5 = (short *)((longlong)psVar5 + 1);
                        } while ((char)sVar1 != '\0');
                      }
                      if (uVar7 < param_2) {
                        pcVar9 = (char *)((ulonglong)uVar7 + (longlong)param_1);
                        do {
                          if (psVar11 <= psVar5) goto LAB_1400127f0;
                          if ((char)*psVar5 == '\0') break;
                          *pcVar9 = (char)*psVar5;
                          psVar5 = (short *)((longlong)psVar5 + 1);
                          pcVar9 = pcVar9 + 1;
                          uVar7 = uVar7 + 1;
                        } while (uVar7 < param_2);
                        if (uVar7 < param_2) {
LAB_1400127f0:
                          uVar4 = (ulonglong)uVar7;
                          uVar7 = uVar7 + 1;
                          *(undefined1 *)(uVar4 + (longlong)param_1) = 0x2c;
                        }
                      }
                    }
                    if (uVar7 < param_2) {
                      local_78 = *(byte *)(psVar12 + 1) + 0x30;
                      iVar2 = RtlStringCbPrintfA((char *)((ulonglong)uVar7 + (longlong)param_1),
                                                 (ulonglong)(param_2 - uVar7),"%c.%c",
                                                 (ulonglong)
                                                 (*(byte *)((longlong)psVar12 + 1) + 0x30));
                    }
                    else {
                      iVar2 = -0x7ffffffb;
                    }
                    goto LAB_1400127a7;
                  }
                }
                goto LAB_1400127a2;
              }
              goto LAB_1400127a7;
            }
          }
LAB_1400127a2:
          iVar2 = -0x3fffffff;
        }
LAB_1400127a7:
        ExFreePoolWithTag(psVar3,0x676f6457);
      }
    }
    else {
      iVar2 = -0x3fffffff;
    }
  }
  return iVar2;
code_r0x000140012725:
  for (psVar6 = (short *)((longlong)psVar6 + (ulonglong)*(byte *)((longlong)psVar6 + 1));
      (psVar6 < psVar11 && (*psVar6 != 0)); psVar6 = (short *)((longlong)psVar6 + 1)) {
  }
  psVar6 = psVar6 + 1;
  goto LAB_1400126e6;
}



===== DMgrReleaseGdiViewId @ 140012880 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DMgrReleaseGdiViewId(ulong param_1,char param_2)

{
  ulong *_Dst;
  uint uVar1;
  ulonglong uVar2;
  
                    /* 0x12880  27  DMgrReleaseGdiViewId */
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_14000e688,0);
  _GdiViewIdDataMutex = SystemReserved1[0xf];
  uVar2 = 0;
  do {
    uVar1 = (uint)uVar2;
    if (NumUsedGdiViews <= uVar1) {
LAB_140012942:
      _GdiViewIdDataMutex = (void *)0x0;
      ExReleasePushLockExclusiveEx(&DAT_14000e688,0);
      KeLeaveCriticalRegion();
      return;
    }
    _Dst = (ulong *)((longlong)&UsedGdiViewList + uVar2 * 4);
    if (*_Dst == param_1) {
      NumUsedGdiViews = NumUsedGdiViews - 1;
      if (uVar1 < NumUsedGdiViews) {
        memcpy(_Dst,(void *)((longlong)&UsedGdiViewList + (ulonglong)(uVar1 + 1) * 4),
               (ulonglong)(NumUsedGdiViews - uVar1) << 2);
      }
      *(undefined4 *)((longlong)&UsedGdiViewList + (ulonglong)NumUsedGdiViews * 4) = 0xffffffff;
      if ((NextGdiViewId == param_1 + 1) && (param_2 != '\0')) {
        NextGdiViewId = param_1;
      }
      goto LAB_140012942;
    }
    uVar2 = (ulonglong)(uVar1 + 1);
  } while( true );
}



===== SMgrGetActiveSessionProcess @ 140012990 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong SMgrGetActiveSessionProcess(void)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  
                    /* 0x12990  52  SMgrGetActiveSessionProcess */
  lVar2 = 0;
  iVar1 = SMgrInitialize();
  if (iVar1 < 0) {
    lVar2 = 0;
  }
  else {
    iVar1 = RtlGetActiveConsoleId();
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(&SessionDataListLock,0);
    plVar3 = _CsrProcessList;
    while ((longlong *)*plVar3 != _CsrProcessList) {
      if ((int)plVar3[7] == iVar1) {
        lVar2 = plVar3[5];
        break;
      }
      plVar3 = (longlong *)*plVar3;
    }
    ExReleasePushLockSharedEx(&SessionDataListLock,0);
    KeLeaveCriticalRegion();
  }
  return lVar2;
}



===== SMgrGetNumberOfSessions @ 140012a30 =====

ulong SMgrGetNumberOfSessions(void)

{
                    /* 0x12a30  53  SMgrGetNumberOfSessions */
  return CsrProcessCount;
}



===== SMgrRegisterSessionChangeCallout @ 140012a40 =====

int SMgrRegisterSessionChangeCallout(_func_long_ulong *param_1)

{
  int iVar1;
  
                    /* 0x12a40  55  SMgrRegisterSessionChangeCallout */
  iVar1 = SMgrInitialize();
  if (-1 < iVar1) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&SessionDataListLock,0);
    if (SessionChangeCallout == (_func_long_ulong *)0x0) {
      SessionChangeCallout = param_1;
    }
    else if (SessionChangeCallout != param_1) {
      iVar1 = -0x3ffffff3;
    }
    ExReleasePushLockExclusiveEx(&SessionDataListLock,0);
    KeLeaveCriticalRegion();
  }
  return iVar1;
}



===== SMgrUnregisterSessionChangeCallout @ 140012ad0 =====

undefined8 SMgrUnregisterSessionChangeCallout(_func_long_ulong *param_1)

{
  undefined8 uVar1;
  
                    /* 0x12ad0  56  SMgrUnregisterSessionChangeCallout */
  uVar1 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&SessionDataListLock,0);
  if (SessionChangeCallout == param_1) {
    SessionChangeCallout = (_func_long_ulong *)0x0;
  }
  else {
    uVar1 = 0xc000000d;
  }
  ExReleasePushLockExclusiveEx(&SessionDataListLock,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== WdDbgDestroySnapshot @ 140012b50 =====

void WdDbgDestroySnapshot(longlong param_1)

{
                    /* 0x12b50  63  WdDbgDestroySnapshot
                       0x12b50  120  WdRegFreeInfo */
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0x676f6457);
  }
  return;
}



===== WdRegOpenSubkey @ 140012b80 =====

void WdRegOpenSubkey(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x12b80  121  WdRegOpenSubkey */
  local_34 = 0;
  local_1c = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_38 = 0x30;
  local_20 = 0x240;
  local_30 = param_3;
  local_28 = param_4;
  ZwOpenKey(0,param_2,&local_38);
  return;
}



===== WdRegRetrieveSubkeyInfo @ 140012bd0 =====

int WdRegRetrieveSubkeyInfo(undefined8 param_1,undefined4 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 local_res18 [2];
  
                    /* 0x12bd0  122  WdRegRetrieveSubkeyInfo */
  lVar2 = 0;
  *param_3 = 0;
  uVar3 = 0x400;
  do {
    WdDbgDestroySnapshot(lVar2);
    lVar2 = ExAllocatePool2(0x100,uVar3,0x676f6457);
    if (lVar2 == 0) {
      iVar1 = -0x3fffffe9;
      break;
    }
    local_res18[0] = 0;
    iVar1 = ZwEnumerateKey(param_1,param_2,0,lVar2,uVar3,local_res18);
    uVar3 = local_res18[0];
  } while ((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd));
  if (iVar1 < 0) {
    WdDbgDestroySnapshot(lVar2);
    lVar2 = 0;
  }
  *param_3 = lVar2;
  return iVar1;
}



===== WdRegRetrieveValueInfo @ 140012ca0 =====

int WdRegRetrieveValueInfo(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 local_res18 [2];
  
                    /* 0x12ca0  123  WdRegRetrieveValueInfo */
  lVar2 = 0;
  *param_3 = 0;
  uVar3 = 0x400;
  do {
    WdDbgDestroySnapshot(lVar2);
    lVar2 = ExAllocatePool2(0x100,uVar3,0x676f6457);
    if (lVar2 == 0) {
      iVar1 = -0x3fffffe9;
      break;
    }
    local_res18[0] = 0;
    iVar1 = ZwQueryValueKey(param_1,param_2,2,lVar2,uVar3,local_res18);
    uVar3 = local_res18[0];
  } while ((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd));
  if (iVar1 < 0) {
    WdDbgDestroySnapshot(lVar2);
    lVar2 = 0;
  }
  *param_3 = lVar2;
  return iVar1;
}



===== DisplayScenarioContextFindAndAssociate @ 140012d70 =====

/* void __cdecl DisplayScenarioContextFindAndAssociate(struct _GUID const & __ptr64,struct
   _DXGK_DISPLAY_SCENARIO_CONTEXT * __ptr64 & __ptr64,unsigned char & __ptr64) */

void __cdecl
DisplayScenarioContextFindAndAssociate
          (_GUID *param_1,_DXGK_DISPLAY_SCENARIO_CONTEXT **param_2,uchar *param_3)

{
  bool bVar1;
  undefined8 uVar2;
  CDisplayScenarioContext *this;
  _WD_MUTEX *p_Var3;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x12d70  8  DisplayScenarioContextFindAndAssociate */
  *param_3 = '\0';
  *param_2 = (_DXGK_DISPLAY_SCENARIO_CONTEXT *)0x0;
  if (DAT_14000e048 != 0) {
    p_Var3 = (_WD_MUTEX *)0x400000000001;
    uVar2 = _tlgKeywordOn(param_1,0x400000000001);
    if ((char)uVar2 != '\0') {
      AutoMutex::AutoMutex((AutoMutex *)&local_18,p_Var3);
      this = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId(param_1);
      if (this != (CDisplayScenarioContext *)0x0) {
        *param_2 = (_DXGK_DISPLAY_SCENARIO_CONTEXT *)(this + 0x70);
        bVar1 = CDisplayContextBase<CDisplayScenarioContext>::IsCurrentThreadAssociated
                          ((CDisplayContextBase<CDisplayScenarioContext> *)this);
        if (!bVar1) {
          CDisplayContextBase<CDisplayScenarioContext>::AssociateCurrentThread
                    ((CDisplayContextBase<CDisplayScenarioContext> *)this);
          *param_3 = '\x01';
        }
      }
      if (local_10 != '\0') {
        *local_18 = 0;
        ExReleasePushLockExclusiveEx(local_18 + 1,0);
        KeLeaveCriticalRegion();
      }
    }
  }
  return;
}



===== DisplayScenarioContextGetCurrentActivityId @ 140012e30 =====

/* unsigned char __cdecl DisplayScenarioContextGetCurrentActivityId(struct _GUID & __ptr64) */

uchar __cdecl DisplayScenarioContextGetCurrentActivityId(_GUID *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uchar uVar4;
  CDisplayScenarioContext *pCVar5;
  _WD_MUTEX *in_RDX;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x12e30  9  DisplayScenarioContextGetCurrentActivityId */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,in_RDX);
  pCVar5 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if (pCVar5 == (CDisplayScenarioContext *)0x0) {
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1);
      KeLeaveCriticalRegion();
    }
    uVar4 = '\0';
  }
  else {
    uVar1 = *(undefined4 *)(pCVar5 + 0x24);
    uVar2 = *(undefined4 *)(pCVar5 + 0x28);
    uVar3 = *(undefined4 *)(pCVar5 + 0x2c);
    *(undefined4 *)param_1 = *(undefined4 *)(pCVar5 + 0x20);
    *(undefined4 *)(param_1 + 4) = uVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(undefined4 *)(param_1 + 0xc) = uVar3;
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1);
      KeLeaveCriticalRegion();
    }
    uVar4 = '\x01';
  }
  return uVar4;
}



===== SetSpecializedData @ 140012ec0 =====

/* public: void __cdecl CDisplayScenarioJournal::SetSpecializedData(struct
   _DISPLAY_SCENARIO_SPECIALIZED_DATA_HEADER * __ptr64) __ptr64 */

void __thiscall
CDisplayScenarioJournal::SetSpecializedData
          (CDisplayScenarioJournal *this,_DISPLAY_SCENARIO_SPECIALIZED_DATA_HEADER *param_1)

{
  void *_Dst;
  __uint64 in_R8;
  
  if (*(longlong *)(this + 0x90) == 0) {
    _Dst = operator_new((ulonglong)*(uint *)(param_1 + 4),(ulong)param_1,in_R8);
    *(void **)(this + 0x90) = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,(ulonglong)*(uint *)(param_1 + 4));
    }
  }
  return;
}



===== VidPnRestoreJournalBegin @ 140012f10 =====

/* public: void __cdecl CDisplayScenarioContext::VidPnRestoreJournalBegin(enum
   POWER_MONITOR_REQUEST_REASON) __ptr64 */

void __thiscall
CDisplayScenarioContext::VidPnRestoreJournalBegin
          (CDisplayScenarioContext *this,POWER_MONITOR_REQUEST_REASON param_1)

{
  undefined8 *puVar1;
  __uint64 in_R8;
  
  *(int *)(this + 0xb8) = *(int *)(this + 0xb8) + 1;
  puVar1 = operator_new(0x60,param_1,in_R8);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    puVar1[1] = this;
    *puVar1 = &CDisplayRestoreVidPnJournal::_vftable_;
    *(undefined2 *)(puVar1 + 2) = 0;
    puVar1[3] = 0;
    puVar1[9] = 0;
    *(undefined2 *)(puVar1 + 10) = 0;
    puVar1[0xb] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
  }
  *(undefined8 **)(this + 0xb0) = puVar1;
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined2 *)(puVar1 + 10) = 0;
    *(POWER_MONITOR_REQUEST_REASON *)(puVar1 + 9) = param_1;
  }
  return;
}



===== DisplayScenarioJournalMissingActualPathModality @ 140012fa0 =====

bool DisplayScenarioJournalMissingActualPathModality(undefined8 param_1,_WD_MUTEX *param_2)

{
  CDisplayScenarioContext *pCVar1;
  bool bVar2;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x12fa0  39  DisplayScenarioJournalMissingActualPathModality */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if ((pCVar1 == (CDisplayScenarioContext *)0x0) || (*(longlong *)(pCVar1 + 0xa8) == 0)) {
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1);
      KeLeaveCriticalRegion();
    }
    bVar2 = false;
  }
  else {
    bVar2 = *(longlong *)(*(longlong *)(pCVar1 + 0xa8) + 0xc0) == 0;
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1);
      KeLeaveCriticalRegion();
    }
  }
  return bVar2;
}



===== DisplayScenarioJournalRetry @ 140013040 =====

void DisplayScenarioJournalRetry(undefined4 param_1,_WD_MUTEX *param_2)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x13040  40  DisplayScenarioJournalRetry */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if ((pCVar1 != (CDisplayScenarioContext *)0x0) && (*(longlong *)(pCVar1 + 0xa8) != 0)) {
    *(undefined4 *)(*(longlong *)(pCVar1 + 0xa8) + 0x6c) = param_1;
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioSetCCDRetrievalForActivity @ 1400130b0 =====

void DisplayScenarioSetCCDRetrievalForActivity(longlong *param_1,_WD_MUTEX *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x130b0  50  DisplayScenarioSetCCDRetrievalForActivity */
  if (((param_1 != (longlong *)0x0) && ((int)param_2 != 0)) &&
     ((*param_1 != 0 || (param_1[1] != 0)))) {
    AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
    lVar4 = *param_1;
    uVar2 = *(undefined4 *)((longlong)param_1 + 4);
    lVar5 = param_1[1];
    uVar3 = *(undefined4 *)((longlong)param_1 + 0xc);
    uVar6 = (ulonglong)(g_ccdDbRetrievalCacheIndex & 3);
    g_ccdDbRetrievalCacheIndex = g_ccdDbRetrievalCacheIndex + 1;
    *(int *)((longlong)&g_ccdDbRetrievalCacheResult + uVar6 * 4) = (int)param_2;
    lVar1 = uVar6 * 0x10;
    *(int *)(&g_ccdDbRetrievalCacheId + uVar6 * 2) = (int)lVar4;
    *(undefined4 *)((longlong)&g_ccdDbRetrievalCacheId + lVar1 + 4) = uVar2;
    *(int *)(&DAT_14000e828 + lVar1) = (int)lVar5;
    *(undefined4 *)(lVar1 + 0x14000e82c) = uVar3;
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== InitDisplayTelemetry @ 140013168 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitDisplayTelemetry(void)

{
  _DAT_14000e868 = 0;
  _g_displayScenarioMutex = 0;
  g_ccdDbRetrievalCacheIndex = 0;
  memset(&g_ccdDbRetrievalCacheId,0,0x40);
  DAT_14000e808 = &CDisplayScenarioContext::s_contextLinkList;
  _s_contextLinkList = &CDisplayScenarioContext::s_contextLinkList;
  g_ccdDbRetrievalCacheResult = (_CCD_RETRIEVAL *)0x0;
  uRam000000014000e818 = 0;
  ExInitializeLookasideListEx
            (&CDisplayScenarioContext::s_contextLookasideList,0,0,1,0,0xc0,0x7774656c,0);
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  return;
}



===== _tlgDefineProvider_annotation__TlggDisplayTelemetryProviderProv @ 140013200 =====

void _tlgDefineProvider_annotation__TlggDisplayTelemetryProviderProv(void)

{
  return;
}



===== WdAllocateWatchdog @ 140013210 =====

undefined4 * WdAllocateWatchdog(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
                    /* 0x13210  59  WdAllocateWatchdog */
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0xf0);
  if (puVar2 != (undefined4 *)0x0) {
    WdpInitializeObject(puVar2,param_1,0x57536457,param_2,param_3);
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    uVar1 = KeQueryTimeIncrement();
    *(undefined8 *)(puVar2 + 0x14) = 0;
    *(undefined8 *)(puVar2 + 0x16) = 0;
    *(undefined8 *)(puVar2 + 0x18) = 0;
    *(undefined8 *)(puVar2 + 0x3a) = 0;
    puVar2[0x12] = uVar1;
    KeInitializeTimerEx(puVar2 + 0x1a,0);
    KeInitializeDpc(puVar2 + 0x2a,WdpWatchdogDpcCallback,puVar2);
  }
  return puVar2;
}



===== WdFreeWatchdog @ 1400132f0 =====

void WdFreeWatchdog(int *param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* 0x132f0  81  WdFreeWatchdog */
  WdStopWatch(param_1,'\0');
  KeFlushQueuedDpcs();
  LOCK();
  piVar1 = param_1 + 1;
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    WdpDestroyObject((longlong)param_1);
  }
  return;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140013330 =====

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
      goto LAB_14001338d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001338d;
    }
  }
  uVar1 = 0x206;
LAB_14001338d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140013398 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_TVSDumpBugFix__private_descriptor);
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
  ppuVar2 = &Feature_TVSDumpBugFix__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140013450 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140013488 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001350a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001350a;
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
LAB_14001350a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140013560 =====

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
      ppuVar3 = &Feature_TVSDumpBugFix__private_descriptor;
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



===== wil_details_RecordFeatureUsageCallback @ 1400135b4 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400135d0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1400135ec =====

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
  ppuVar3 = &Feature_TVSDumpBugFix__private_descriptor;
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



===== WdAllocateDeferredWatchdog @ 1400136a0 =====

undefined4 * WdAllocateDeferredWatchdog(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
                    /* 0x136a0  58  WdAllocateDeferredWatchdog */
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x100);
  if (puVar2 != (undefined4 *)0x0) {
    WdpInitializeObject(puVar2,param_1,0x57446457,param_2,param_3);
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    *(undefined8 *)(puVar2 + 0xe) = 0;
    *(undefined8 *)(puVar2 + 0x12) = 0;
    *(undefined8 *)(puVar2 + 0x14) = 0;
    puVar2[0x16] = 0;
    uVar1 = KeQueryTimeIncrement();
    puVar2[0x18] = 0;
    puVar2[0x17] = uVar1;
    puVar2[0x19] = 1;
    *(undefined8 *)(puVar2 + 0x1a) = 0;
    *(undefined8 *)(puVar2 + 0x3c) = 0;
    *(undefined1 *)(puVar2 + 0x3e) = 0;
    KeInitializeDpc(puVar2 + 0x2c,WdpDeferredWatchdogDpcCallback,puVar2);
    KeInitializeTimerEx(puVar2 + 0x1c,0);
  }
  return puVar2;
}



===== WdFreeDeferredWatchdog @ 1400137a0 =====

void WdFreeDeferredWatchdog(int *param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* 0x137a0  80  WdFreeDeferredWatchdog */
  WdStopDeferredWatch(param_1);
  KeFlushQueuedDpcs();
  LOCK();
  piVar1 = param_1 + 1;
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    WdpDestroyObject((longlong)param_1);
  }
  return;
}



===== WdpInitializeObject @ 1400137dc =====

void WdpInitializeObject(undefined4 *param_1,undefined8 param_2,undefined4 param_3,
                        undefined4 param_4,undefined4 param_5)

{
  *param_1 = param_3;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0xc) = 0;
  param_1[1] = 1;
  param_1[7] = 1;
  param_1[2] = param_5;
  *(undefined8 *)(param_1 + 4) = param_2;
  param_1[6] = param_4;
  ObfReferenceObject(param_2);
  KeInitializeSpinLock(param_1 + 10);
  return;
}



===== WdDbgCreateSnapshot @ 140013840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
WdDbgCreateSnapshot(undefined8 *param_1,void *param_2,uint param_3,longlong *param_4,int *param_5)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 auStackY_558 [32];
  undefined1 local_518 [1232];
  ulonglong local_48;
  
                    /* 0x13840  62  WdDbgCreateSnapshot */
  local_48 = __security_cookie ^ (ulonglong)auStackY_558;
  if (param_5 == (int *)0x0) {
    return 0xc000000d;
  }
  uVar2 = WdpDbgReportGetExtSizeByGuid((undefined *)param_1);
  uVar4 = (int)uVar2 + 0xc0000;
  lVar3 = ExAllocatePool2(0x40,uVar4,0x676f6457);
  if (lVar3 == 0) {
    return 0xc0000017;
  }
  memset(local_518,0,0x4d0);
  RtlCaptureContext(local_518);
  iVar1 = KeCapturePersistentThreadState(local_518,SystemReserved1[0xf],0,0);
  *param_5 = iVar1;
  if (iVar1 == 0) {
LAB_14001391f:
    ExFreePoolWithTag(lVar3,0x676f6457);
    uVar2 = 0xc0000001;
  }
  else {
    if ((param_2 != (void *)0x0) && (param_3 != 0)) {
      iVar1 = WdpAppendSecondaryMinidumpData(param_1,param_2,param_3,lVar3,uVar4);
      *param_5 = iVar1;
      if (iVar1 == 0) goto LAB_14001391f;
    }
    *param_4 = lVar3;
    uVar2 = 0;
  }
  return uVar2;
}



===== WdDbgReportCancel @ 140013990 =====

void WdDbgReportCancel(longlong param_1)

{
  char cVar1;
  
                    /* 0x13990  65  WdDbgReportCancel */
  cVar1 = KeGetCurrentIrql();
  if ((cVar1 == '\0') && (param_1 != 0)) {
    if (*(longlong *)(param_1 + 0x280) != 0) {
      WerLiveKernelCancelReport();
      if (*(longlong *)(param_1 + 0x2b0) != 0) {
        ZwClose();
        *(undefined8 *)(param_1 + 0x2b0) = 0;
      }
      *(undefined8 *)(param_1 + 0x280) = 0;
    }
    WdpDbgReportFree(param_1);
  }
  return;
}



===== WdDbgReportComplete @ 140013a10 =====

uint WdDbgReportComplete(longlong param_1)

{
  char cVar1;
  uint uVar2;
  
                    /* 0x13a10  66  WdDbgReportComplete */
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    return 0xc0000001;
  }
  if (param_1 == 0) {
    return 0xc0000001;
  }
  if (*(longlong *)(param_1 + 0x280) == 0) goto LAB_140013aab;
  if (*(longlong *)(param_1 + 0x2b0) == 0) {
LAB_140013a6f:
    uVar2 = WerLiveKernelSubmitReport(*(undefined8 *)(param_1 + 0x280),0);
  }
  else {
    uVar2 = ZwClose();
    *(undefined8 *)(param_1 + 0x2b0) = 0;
    if (-1 < (int)uVar2) goto LAB_140013a6f;
  }
  if ((int)uVar2 < 0) {
    WerLiveKernelCloseHandle(*(undefined8 *)(param_1 + 0x280));
    *(undefined8 *)(param_1 + 0x280) = 0;
    return uVar2;
  }
  uVar2 = WerLiveKernelCloseHandle();
  *(undefined8 *)(param_1 + 0x280) = 0;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
LAB_140013aab:
  uVar2 = WdpDbgNotifyAboutReport(param_1);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  WdpDbgReportFree(param_1);
  return uVar2;
}



===== WdDbgReportCreate @ 140013af0 =====

void WdDbgReportCreate(longlong param_1,uint param_2,longlong param_3,longlong param_4,
                      longlong param_5,longlong param_6,byte param_7)

{
  _WD_DEBUG_REPORT *p_Var1;
  
                    /* 0x13af0  67  WdDbgReportCreate */
  p_Var1 = WdDbgReportRecreate(param_1,param_2,param_3,param_4,param_5,param_6,0,
                               (_WD_DEBUG_REPORT *)0x0,param_7);
  if (((p_Var1 == (_WD_DEBUG_REPORT *)0x0) && ((param_7 & 1) != 0)) && ((param_7 & 4) != 0)) {
    WdDbgReportRecreate(param_1,param_2,param_3,param_4,param_5,param_6,0,(_WD_DEBUG_REPORT *)0x0,
                        param_7 & 0xf0);
  }
  return;
}



===== WdpDbgGetApplicationName @ 140013ba8 =====

ulonglong WdpDbgGetApplicationName(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res8 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (param_1 == 0) {
    uVar2 = 0xc000000d;
  }
  else {
    uVar2 = PsLookupProcessByProcessId(0,local_res8);
    if (-1 < (int)uVar2) {
      uVar3 = PsGetProcessImageFileName(local_res8[0]);
      RtlInitAnsiString(&local_18,uVar3);
      uVar1 = RtlAnsiStringToUnicodeString(param_2,&local_18,1);
      uVar2 = (ulonglong)uVar1;
      ObfDereferenceObject(local_res8[0]);
    }
  }
  return uVar2;
}



===== WdpDbgNotifyAboutReport @ 140013c40 =====

uint WdpDbgNotifyAboutReport(longlong param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  undefined8 local_28;
  longlong lStack_20;
  longlong local_18;
  longlong lStack_10;
  
  cVar1 = KeGetCurrentIrql();
  if ((cVar1 != '\0') || (param_1 == 0)) {
    return 0xc0000001;
  }
  iVar3 = *(int *)(param_1 + 8);
  uVar6 = 4;
  if ((iVar3 == 0x117) || (iVar3 == 0x141)) {
    uVar6 = 0x24;
    iVar3 = (-(uint)(*(char *)(param_1 + 0x30) != '\0') & 5) + 1;
LAB_140013cc2:
    iVar2 = WdDiagInit((longlong *)0x0);
    if (-1 < iVar2) {
      if (iVar3 == 4) {
        local_28 = 0;
        lStack_20 = 0;
        uVar5 = WdpDbgGetApplicationName(*(longlong *)(param_1 + 0x28),&local_28);
        iVar3 = (int)uVar5;
        if (-1 < iVar3) {
          local_18 = lStack_20;
          lStack_10 = lStack_20;
          iVar3 = WdDiagNotifyUser(uVar6,4,2,(longlong)&local_18);
        }
        RtlFreeUnicodeString(&local_28);
      }
      else {
        local_18 = param_1 + 0x78;
        lStack_10 = param_1 + 0x38;
        iVar3 = WdDiagNotifyUser(uVar6,iVar3,2,(longlong)&local_18);
      }
      WdDiagShutdown();
      if (-1 < iVar3) goto LAB_140013d53;
    }
    local_18 = 0;
    lStack_10 = 0;
    RtlInitUnicodeString(&local_18,param_1 + 0x38);
    cVar1 = IoRaiseInformationalHardError(0x401b00ec,&local_18,0);
    uVar4 = ~-(uint)(cVar1 != '\0') & 0xc0000001;
  }
  else {
    if (iVar3 == 0x142) {
      iVar3 = 4;
      goto LAB_140013cc2;
    }
    if (iVar3 == 0x187) {
      iVar3 = 7;
      goto LAB_140013cc2;
    }
    if (iVar3 == 0x400000ad) {
      iVar3 = 0;
      goto LAB_140013cc2;
    }
LAB_140013d53:
    uVar4 = 0;
  }
  return uVar4;
}



===== WdpDbgReportCreateFromDump @ 140013dc0 =====

longlong * WdpDbgReportCreateFromDump(longlong param_1,longlong param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  longlong *plVar3;
  uint uVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x13dc0  135  WdpDbgReportCreateFromDump */
  cVar1 = KeGetCurrentIrql();
  if (((cVar1 == '\0') && (param_2 != 0)) && (param_3 != 0)) {
    plVar3 = WdpDbgReportRealloc(param_1,0xffffffff,-1,-1,-1,-1,0,(longlong *)0x0,0);
    if (plVar3 == (longlong *)0x0) goto LAB_140013e89;
    local_18 = 0;
    uStack_10 = 0;
    uVar4 = 0xc0000;
    if (param_3 < 0xc0001) {
      uVar4 = param_3;
    }
    iVar2 = ZwWriteFile(plVar3[0x56],0,0,0,&local_18,param_2,uVar4,0,0);
    if (-1 < iVar2) goto LAB_140013e89;
    WdpDbgReportFree((longlong)plVar3);
  }
  plVar3 = (longlong *)0x0;
LAB_140013e89:
  return plVar3;
}



===== WdpDbgReportFree @ 140013ea8 =====

void WdpDbgReportFree(longlong param_1)

{
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x2b0) != 0) {
      ZwClose();
      *(undefined8 *)(param_1 + 0x2b0) = 0;
    }
    ExFreePoolWithTag(param_1,0x676f6457);
  }
  return;
}



===== WdpInterfaceReferenceNop @ 140013f00 =====

void WdpInterfaceReferenceNop(void)

{
                    /* 0x13f00  136  WdpInterfaceReferenceNop */
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140013f0c =====

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



===== WdDiagShutdown @ 140013fe0 =====

undefined4 WdDiagShutdown(void)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
                    /* 0x13fe0  77  WdDiagShutdown */
  uVar2 = 0;
  LOCK();
  iVar1 = DAT_14000ea8c + -1;
  UNLOCK();
  bVar3 = DAT_14000ea8c == 1;
  DAT_14000ea8c = iVar1;
  if ((bVar3) && (DAT_14000ea90 != 0)) {
    uVar2 = EtwUnregister();
    DAT_14000ea90 = 0;
  }
  return uVar2;
}



===== WdpWerInitContext @ 140014028 =====

undefined8 WdpWerInitContext(undefined8 *param_1,int param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  if (param_2 == 0x1b8) {
    RtlStringCchPrintfW((ushort *)((longlong)param_1 + 0xc),0x10,(ushort *)L"%s%d%d",L"WATCHDOG",
                        0x1b8,DAT_14000ea9c);
    DAT_14000ea9c = DAT_14000ea9c + 1 & 3;
  }
  else {
    builtin_wcsncpy((wchar_t *)((longlong)param_1 + 0xc),L"WATC",4);
    builtin_wcsncpy((wchar_t *)((longlong)param_1 + 0x14),L"HDOG",4);
    *(undefined2 *)((longlong)param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[6] = 0;
  return 0;
}



===== DisplayScenarioJounralSetTSDDDState @ 1400140c0 =====

void DisplayScenarioJounralSetTSDDDState(char param_1,_WD_MUTEX *param_2)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x140c0  33  DisplayScenarioJounralSetTSDDDState */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if ((pCVar1 != (CDisplayScenarioContext *)0x0) && (*(longlong *)(pCVar1 + 0xa8) != 0)) {
    *(uint *)(*(longlong *)(pCVar1 + 0xa8) + 0x60) = 2 - (uint)(param_1 != '\0');
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalSetExpectedPathModality @ 140014130 =====

void DisplayScenarioJournalSetExpectedPathModality
               (int param_1,_WD_MUTEX *param_2,D3DKMT_PATHMODALITY_DESCRIPTOR *param_3,uint param_4)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x14130  43  DisplayScenarioJournalSetExpectedPathModality */
  if ((param_1 != 0) && (param_3 != (D3DKMT_PATHMODALITY_DESCRIPTOR *)0x0)) {
    AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
    pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
    if ((pCVar1 != (CDisplayScenarioContext *)0x0) &&
       (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8) != (CDisplayScenarioJournal *)0x0)) {
      CDisplayScenarioJournal::SetExpectedPathModality
                (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8),(uint)param_2,param_3,param_4);
    }
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== SMgrSessionRundown @ 1400141c8 =====

undefined8 SMgrSessionRundown(void)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  iVar1 = PsGetCurrentProcessSessionId();
  uVar2 = SMgrAcquireCsrProcessData(iVar1);
  uVar3 = 0;
  if (uVar2 == 0) {
    uVar3 = 0xc0000225;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(uVar2 + 0x20,0);
    *(undefined1 *)(uVar2 + 0x3c) = 1;
    *(undefined8 *)(uVar2 + 0x18) = 0;
    ExReleasePushLockExclusiveEx(uVar2 + 0x20,0);
    KeLeaveCriticalRegion();
    SMgrReleaseCsrProcessData(uVar2);
  }
  return uVar3;
}



===== SMgrAcquireCsrProcessData @ 140014260 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SMgrAcquireCsrProcessData(int param_1)

{
  byte bVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  bVar1 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&SessionDataListLock,0);
  plVar2 = _CsrProcessList;
  plVar3 = (longlong *)0x0;
  do {
    if ((longlong *)*plVar2 == _CsrProcessList) {
LAB_1400142ba:
      ExReleasePushLockSharedEx(&SessionDataListLock,0);
      KeLeaveCriticalRegion();
      return -(ulonglong)bVar1 & (ulonglong)plVar3;
    }
    plVar3 = plVar2;
    if ((int)plVar2[7] == param_1) {
      bVar1 = 1;
      LOCK();
      *(int *)(plVar2 + 2) = (int)plVar2[2] + 1;
      UNLOCK();
      goto LAB_1400142ba;
    }
    plVar2 = (longlong *)*plVar2;
  } while( true );
}



===== SMgrGdiCallout @ 140014300 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SMgrGdiCallout(int *param_1,ulonglong param_2,char param_3,undefined *param_4,longlong param_5,
                  _GUID *param_6)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong *plVar7;
  
                    /* 0x14300  51  SMgrGdiCallout */
  if ((param_1 != (int *)0x0) && (param_2 != 0x300000000)) {
    iVar6 = SMgrInitialize();
    if (iVar6 < 0) goto LAB_140014446;
    if (param_3 == '\x01') {
      SMgrGdiCalloutInternal(param_1,param_2,param_4,param_5,param_6);
      goto LAB_140014446;
    }
    plVar7 = (longlong *)ExAllocateFromPagedLookasideList(&GdiCalloutPacketPool);
    if (plVar7 == (longlong *)0x0) {
      return -0x3fffffe9;
    }
    if (param_6 == (_GUID *)0x0) {
      plVar7[9] = 0;
    }
    else {
      DisplayScenarioContextFindAndAddRef(param_6,(_DXGK_DISPLAY_SCENARIO_CONTEXT **)(plVar7 + 9));
    }
    iVar2 = param_1[1];
    iVar3 = param_1[2];
    iVar4 = param_1[3];
    *(int *)(plVar7 + 2) = *param_1;
    *(int *)((longlong)plVar7 + 0x14) = iVar2;
    *(int *)(plVar7 + 3) = iVar3;
    *(int *)((longlong)plVar7 + 0x1c) = iVar4;
    iVar2 = param_1[4];
    iVar3 = param_1[5];
    iVar4 = param_1[6];
    iVar5 = param_1[7];
    plVar7[6] = param_2;
    plVar7[7] = (longlong)param_4;
    *(int *)(plVar7 + 4) = iVar2;
    *(int *)((longlong)plVar7 + 0x24) = iVar3;
    *(int *)(plVar7 + 5) = iVar4;
    *(int *)((longlong)plVar7 + 0x2c) = iVar5;
    plVar7[8] = param_5;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&DAT_14000e6a0,0);
    _GdiQueueMutex = SystemReserved1[0xf];
    if ((_LIST_ENTRY *)*DAT_14000e6c8 == &GdiCalloutQueue) {
      *plVar7 = (longlong)&GdiCalloutQueue;
      plVar7[1] = (longlong)DAT_14000e6c8;
      *DAT_14000e6c8 = (longlong)plVar7;
      DAT_14000e6c8 = plVar7;
      KeSetEvent(&GdiQueueEvent,0,0);
      _GdiQueueMutex = (void *)0x0;
      ExReleasePushLockExclusiveEx(&DAT_14000e6a0,0);
      KeLeaveCriticalRegion();
      goto LAB_140014446;
    }
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(3);
  }
  iVar6 = -0x3ffffff3;
LAB_140014446:
  return iVar6;
}



===== SMgrNotifySessionChange @ 1400144b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SMgrNotifySessionChange(uint param_1,longlong param_2)

{
  int iVar1;
  long lVar2;
  undefined4 extraout_var;
  ulonglong uVar3;
  undefined4 extraout_var_00;
  
                    /* 0x144b0  54  SMgrNotifySessionChange */
  iVar1 = SMgrInitialize();
  uVar3 = CONCAT44(extraout_var,iVar1);
  if (-1 < iVar1) {
    if (param_1 == 0) {
      uVar3 = SMgrSessionOpen(param_2);
    }
    else if (param_1 == 1) {
      uVar3 = SMgrSessionClose();
    }
    else if (param_1 == 2) {
      uVar3 = SMgrSessionRundown();
    }
    else if (param_1 == 3) {
      InSwitchConsoleSessionId = PsGetCurrentProcessSessionId();
      LOCK();
      UNLOCK();
      uVar3 = 0;
    }
    else {
      if (param_1 != 4) {
        WdLogSingleEntry1(2,(ulonglong)param_1);
        _WdLogGlobalForLineNumber = 0x47d;
        return 0xc00000ef;
      }
      uVar3 = SMgrSetConsoleSessionInSwitch('\0');
    }
    if (SessionChangeCallout != (_func_long_ulong *)0x0) {
      lVar2 = (*SessionChangeCallout)(param_1);
      uVar3 = CONCAT44(extraout_var_00,lVar2);
    }
  }
  return uVar3;
}



===== SMgrInitialize @ 140014560 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SMgrInitialize(void)

{
  int iVar1;
  bool bVar2;
  undefined8 local_res8;
  void *local_res10;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar3;
  ulonglong in_stack_ffffffffffffffe8;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  local_res8 = 0;
  if (IsSMgrInitialized != '\0') {
    return 0;
  }
  do {
    LOCK();
    bVar2 = SMgrCriticalSectionLock == (void *)0x0;
    if (bVar2) {
      SMgrCriticalSectionLock = SystemReserved1[0xf];
    }
    UNLOCK();
  } while (!bVar2);
  InitDisplayTelemetry();
  _DAT_14000e788 = &CsrProcessList;
  _CsrProcessList = &CsrProcessList;
  _SessionDataListLock = 0;
  _DAT_14000e6a0 = 0;
  _GdiQueueMutex = 0;
  ExInitializePagedLookasideList
            (&GdiCalloutPacketPool,0,0,0,0x50,CONCAT44(uVar3,0x676f6457),
             in_stack_ffffffffffffffe8 & 0xffffffffffff0000);
  KeInitializeEvent(&GdiQueueEvent,1);
  DAT_14000e6c8 = &GdiCalloutQueue;
  _GdiCalloutQueue = &GdiCalloutQueue;
  CalloutThreadState = 1;
  iVar1 = PsCreateSystemThread(&local_res8,0x1fffff,0,0,0,SMgrGdiCalloutThread,0);
  if (-1 < iVar1) {
    local_res10 = (void *)0x0;
    iVar1 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,&local_res10,0);
    GdiQueueThread = local_res10;
    ZwClose(local_res8);
    if (-1 < iVar1) {
      IsSMgrInitialized = '\x01';
      goto LAB_140014754;
    }
  }
  if (GdiQueueThread != (void *)0x0) {
    CalloutThreadState = 2;
    KeSetEvent(&GdiQueueEvent,0,0);
    KeWaitForSingleObject(GdiQueueThread,0,0,0,0);
    ObfDereferenceObject(GdiQueueThread);
    GdiQueueThread = (void *)0x0;
  }
  ExDeletePagedLookasideList(&GdiCalloutPacketPool);
LAB_140014754:
  LOCK();
  UNLOCK();
  SMgrCriticalSectionLock = (void *)0x0;
  return iVar1;
}



===== SMgrSessionClose @ 140014768 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SMgrSessionClose(void)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  
  uVar8 = 0;
  bVar4 = false;
  iVar5 = PsGetCurrentProcessSessionId();
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&SessionDataListLock,0);
  plVar1 = _CsrProcessList;
  plVar7 = (longlong *)0x0;
  do {
    plVar6 = plVar1;
    plVar1 = (longlong *)*plVar6;
    if (plVar1 == _CsrProcessList) {
LAB_1400147f7:
      ExReleasePushLockExclusiveEx(&SessionDataListLock,0);
      KeLeaveCriticalRegion();
      if (bVar4) {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(plVar7 + 4,0);
        *(undefined1 *)((longlong)plVar7 + 0x3c) = 1;
        plVar7[3] = 0;
        ExReleasePushLockExclusiveEx(plVar7 + 4,0);
        KeLeaveCriticalRegion();
        SMgrReleaseCsrProcessData((longlong)plVar7);
      }
      else {
        uVar8 = 0xc0000225;
      }
      return uVar8;
    }
    plVar7 = plVar6;
    if ((int)plVar6[7] == iVar5) {
      if (((longlong *)plVar1[1] != plVar6) ||
         (plVar2 = (longlong *)plVar6[1], (longlong *)*plVar2 != plVar6)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar8 = (*pcVar3)();
        return uVar8;
      }
      *plVar2 = (longlong)plVar1;
      bVar4 = true;
      plVar1[1] = (longlong)plVar2;
      LOCK();
      CsrProcessCount = CsrProcessCount - 1;
      UNLOCK();
      goto LAB_1400147f7;
    }
  } while( true );
}



===== SMgrGdiCalloutThread @ 1400148a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SMgrGdiCalloutThread(void)

{
  _LIST_ENTRY *p_Var1;
  code *pcVar2;
  _LIST_ENTRY *p_Var3;
  int iVar4;
  
  iVar4 = -0x3ffffddb;
  do {
    do {
      if (CalloutThreadState != 1) {
        PsTerminateSystemThread(iVar4);
        return;
      }
      iVar4 = KeWaitForSingleObject(&GdiQueueEvent,0,0,0,0);
    } while (iVar4 != 0);
    while( true ) {
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(&DAT_14000e6a0);
      _GdiQueueMutex = SystemReserved1[0xf];
      if (_GdiCalloutQueue == &GdiCalloutQueue) break;
      KeResetEvent(&GdiQueueEvent);
      p_Var3 = _GdiCalloutQueue;
      if ((*(_LIST_ENTRY **)(_GdiCalloutQueue + 8) != &GdiCalloutQueue) ||
         (p_Var1 = *(_LIST_ENTRY **)_GdiCalloutQueue,
         *(_LIST_ENTRY **)(p_Var1 + 8) != _GdiCalloutQueue)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _GdiCalloutQueue = p_Var1;
      *(_LIST_ENTRY **)(p_Var1 + 8) = &GdiCalloutQueue;
      _GdiQueueMutex = (void *)0x0;
      ExReleasePushLockExclusiveEx(&DAT_14000e6a0,0);
      KeLeaveCriticalRegion();
      p_Var1 = p_Var3 + 0x48;
      SMgrGdiCalloutInternal
                ((int *)(p_Var3 + 0x10),*(ulonglong *)(p_Var3 + 0x30),*(undefined **)(p_Var3 + 0x38)
                 ,*(longlong *)(p_Var3 + 0x40),*(_GUID **)p_Var1);
      if (*(_DXGK_DISPLAY_SCENARIO_CONTEXT **)p_Var1 != (_DXGK_DISPLAY_SCENARIO_CONTEXT *)0x0) {
        DisplayScenarioContextRelease((_DXGK_DISPLAY_SCENARIO_CONTEXT **)p_Var1);
      }
      ExFreeToPagedLookasideList(&GdiCalloutPacketPool);
    }
    _GdiQueueMutex = (void *)0x0;
    ExReleasePushLockExclusiveEx(&DAT_14000e6a0);
    KeLeaveCriticalRegion();
  } while( true );
}



===== SMgrGdiCalloutInternal @ 140014a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SMgrGdiCalloutInternal
               (int *param_1,ulonglong param_2,undefined *param_3,undefined8 param_4,_GUID *param_5)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  longlong *plVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  bool bVar11;
  undefined1 auStackY_f8 [32];
  longlong *local_c0;
  undefined8 local_b0;
  CDisplayScenarioContextCarrier local_a8 [8];
  _DXGK_DISPLAY_SCENARIO_CONTEXT *local_a0;
  code *local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  longlong local_60 [5];
  
  local_60[4] = __security_cookie ^ (ulonglong)auStackY_f8;
  local_c0 = local_60;
  local_60[0] = 0;
  local_60[1] = 0;
  bVar4 = false;
  local_60[2] = 0;
  local_60[3] = 0;
  local_90 = 0;
  uStack_88 = 0;
  uVar10 = 0;
  uVar8 = 0;
  local_80 = 0;
  uStack_78 = 0;
  bVar3 = false;
  local_70 = 0;
  uStack_68 = 0;
  local_98 = (code *)param_3;
  uVar6 = RtlGetActiveConsoleId();
  uVar2 = InSwitchConsoleSessionId;
  if (uVar6 != 0xffffffff) {
    uVar2 = uVar6;
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&SessionDataListLock,0);
  if (((param_2 == 0x100000000) && (4 < CsrProcessCount)) &&
     (local_c0 = (longlong *)ExAllocatePool2(0x100,(ulonglong)CsrProcessCount << 3,0x676f6457),
     local_c0 == (longlong *)0x0)) {
    param_1[6] = -0x3fffffe9;
    WdLogSingleEntry0(6);
    _WdLogGlobalForLineNumber = 0x28f;
    ExReleasePushLockSharedEx(&SessionDataListLock,0);
    KeLeaveCriticalRegion();
    goto LAB_140014cc6;
  }
  plVar7 = _CsrProcessList;
  if ((longlong *)*_CsrProcessList != _CsrProcessList) {
    do {
      if (bVar3) break;
      if (param_2 == 0x100000000) {
LAB_140014b2f:
        LOCK();
        *(int *)(plVar7 + 2) = (int)plVar7[2] + 1;
        UNLOCK();
        local_c0[uVar10] = (longlong)plVar7;
        uVar10 = (ulonglong)((int)uVar10 + 1);
      }
      else {
        if (param_2 == 0x200000000) {
          bVar11 = *(uint *)(plVar7 + 7) == uVar2;
        }
        else {
          bVar11 = *(uint *)(plVar7 + 7) == param_2;
        }
        if (bVar11) {
          bVar3 = true;
          goto LAB_140014b2f;
        }
      }
      plVar7 = (longlong *)*plVar7;
    } while ((longlong *)*plVar7 != _CsrProcessList);
    uVar8 = (uint)uVar10;
    param_3 = local_98;
  }
  ExReleasePushLockSharedEx(&SessionDataListLock,0);
  KeLeaveCriticalRegion();
  if (uVar8 == 0) {
LAB_140014e8d:
    if (*param_1 == 8) {
      param_1[6] = -0x3ffffbab;
    }
  }
  else {
    uVar10 = (ulonglong)uVar8;
    plVar7 = local_c0;
    do {
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(*plVar7 + 0x20,0);
      *(void **)(*plVar7 + 0x18) = SystemReserved1[0xf];
      lVar1 = *plVar7;
      if (*(char *)(lVar1 + 0x3c) == '\0') {
        if (*(longlong *)(lVar1 + 0x30) == 0) {
          WdLogSingleEntry1(4,(ulonglong)*(uint *)(lVar1 + 0x38));
          _WdLogGlobalForLineNumber = 0x2f3;
        }
        else if (((code *)param_3 == (code *)0x0) ||
                (cVar5 = (*(code *)param_3)(param_4,0,*(undefined4 *)(lVar1 + 0x38)), cVar5 != '\0')
                ) {
          iVar9 = 5;
          KeStackAttachProcess(*(undefined8 *)(*plVar7 + 0x28));
          bVar4 = true;
          do {
            if (param_5 != (_GUID *)0x0) {
              *(int *)(param_5 + 0x30) = *param_1;
            }
            local_a0 = (_DXGK_DISPLAY_SCENARIO_CONTEXT *)0x0;
            local_a8[0] = (CDisplayScenarioContextCarrier)0x0;
            if (param_5 != (_GUID *)0x0) {
              local_a8[0] = (CDisplayScenarioContextCarrier)
                            DisplayScenarioContextFindAndAddRef(param_5,&local_a0);
            }
            local_b0 = *(undefined8 *)(param_1 + 4);
            *(undefined8 **)(param_1 + 4) = &local_b0;
            (**(code **)(*plVar7 + 0x30))(param_1);
            if (param_5 != (_GUID *)0x0) {
              *(undefined4 *)(param_5 + 0x30) = 0;
            }
            if ((param_1[6] == 0) || (*(int *)(*plVar7 + 0x38) == 0)) {
LAB_140014c41:
              CDisplayScenarioContextCarrier::Release(local_a8);
              break;
            }
            WdLogSingleEntry4(2,(longlong)*param_1,*(undefined8 *)(param_1 + 2),
                              *(undefined8 *)(param_1 + 4),(longlong)param_1[6]);
            _WdLogGlobalForLineNumber = 0x325;
            if (*param_1 != 7) goto LAB_140014c41;
            CDisplayScenarioContextCarrier::Release(local_a8);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          if ((code *)param_3 != (code *)0x0) {
            (*(code *)param_3)(param_4,1,*(undefined4 *)(*plVar7 + 0x38));
          }
          KeUnstackDetachProcess(&local_90);
        }
      }
      else {
        WdLogSingleEntry1(4,(ulonglong)*(uint *)(lVar1 + 0x38));
        _WdLogGlobalForLineNumber = 0x2e9;
      }
      *(undefined8 *)(*plVar7 + 0x18) = 0;
      ExReleasePushLockExclusiveEx(*plVar7 + 0x20);
      KeLeaveCriticalRegion();
      SMgrReleaseCsrProcessData(*plVar7);
      *plVar7 = 0;
      plVar7 = plVar7 + 1;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
    if (!bVar4) goto LAB_140014e8d;
  }
  if ((local_c0 != (longlong *)0x0) && (local_c0 != local_60)) {
    ExFreePoolWithTag(local_c0,0);
  }
LAB_140014cc6:
  if ((code *)param_3 != (code *)0x0) {
    (*(code *)param_3)(param_4,2,0xffffffff);
  }
  return;
}



===== SMgrReleaseCsrProcessData @ 140014ed8 =====

void SMgrReleaseCsrProcessData(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== DisplayScenarioJournalSetSDCPathsAndModes @ 140014f10 =====

void DisplayScenarioJournalSetSDCPathsAndModes
               (int param_1,_WD_MUTEX *param_2,DISPLAYCONFIG_PATH_INFO_INTERNAL *param_3)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x14f10  45  DisplayScenarioJournalSetSDCPathsAndModes */
  if ((param_1 != 0) && (param_3 != (DISPLAYCONFIG_PATH_INFO_INTERNAL *)0x0)) {
    AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
    pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
    if ((pCVar1 != (CDisplayScenarioContext *)0x0) &&
       (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8) != (CDisplayScenarioJournal *)0x0)) {
      CDisplayScenarioJournal::SetSDCPathsAndModes
                (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8),(uint)param_2,param_3);
    }
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== SetSDCPathsAndModes @ 140014f94 =====

/* public: void __cdecl CDisplayScenarioJournal::SetSDCPathsAndModes(unsigned int,struct
   DISPLAYCONFIG_PATH_INFO_INTERNAL * __ptr64) __ptr64 */

void __thiscall
CDisplayScenarioJournal::SetSDCPathsAndModes
          (CDisplayScenarioJournal *this,uint param_1,DISPLAYCONFIG_PATH_INFO_INTERNAL *param_2)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  void *pvVar3;
  
  if (*(longlong *)(this + 0xa0) == 0) {
    auVar1 = ZEXT816(200) * ZEXT416(param_1);
    _Var2 = auVar1._0_8_;
    if (auVar1._8_8_ != 0) {
      _Var2 = 0xffffffffffffffff;
    }
    pvVar3 = operator_new(_Var2,auVar1._8_4_,(__uint64)param_2);
    *(void **)(this + 0xa0) = pvVar3;
    if (pvVar3 != (void *)0x0) {
      CopyDisplayScenarioPathInfo((longlong)param_2,param_1,(longlong)pvVar3);
      *(short *)(this + 0x98) = (short)param_1;
    }
  }
  return;
}



===== DisplayScenarioContextHolding @ 140015010 =====

/* void __cdecl DisplayScenarioContextHolding(struct _DXGK_DISPLAY_SCENARIO_CONTEXT * __ptr64 const
   & __ptr64) */

void __cdecl DisplayScenarioContextHolding(_DXGK_DISPLAY_SCENARIO_CONTEXT **param_1)

{
  CDisplayScenarioContext *pCVar1;
  _WD_MUTEX *in_RDX;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15010  10  DisplayScenarioContextHolding */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,in_RDX);
  pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId
                     ((_GUID *)*param_1);
  if (pCVar1 != (CDisplayScenarioContext *)0x0) {
    pCVar1[0x1c] = (CDisplayScenarioContext)0x1;
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalDPIInfo @ 140015070 =====

void DisplayScenarioJournalDPIInfo
               (_LUID *param_1,_WD_MUTEX *param_2,_DPI_INFORMATION *param_3,uint param_4)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15070  36  DisplayScenarioJournalDPIInfo */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if ((pCVar1 != (CDisplayScenarioContext *)0x0) &&
     (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8) != (CDisplayScenarioJournal *)0x0)) {
    CDisplayScenarioJournal::SetDPIInfo
              (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8),param_1,(uint)param_2,param_3,param_4);
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalBegin @ 140015110 =====

void DisplayScenarioJournalBegin(uint param_1,_WD_MUTEX *param_2,ushort param_3)

{
  CDisplayScenarioContext *this;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15110  34  DisplayScenarioJournalBegin */
  if ((param_1 & 0x40) == 0) {
    AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
    this = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
    if (this != (CDisplayScenarioContext *)0x0) {
      CDisplayScenarioContext::DisplayScenraioJournalBegin(this,param_1,(uint)param_2,param_3);
    }
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== DisplayScenarioJournalFinalize @ 1400151a0 =====

void DisplayScenarioJournalFinalize(_GUID *param_1,_WD_MUTEX *param_2)

{
  CDisplayScenarioContext *this;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x151a0  38  DisplayScenarioJournalFinalize */
  if (param_1 == (_GUID *)0x0) {
    return;
  }
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  this = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId(param_1);
  if (this != (CDisplayScenarioContext *)0x0) {
    if (*(longlong *)(this + 0xa8) != 0) {
      *(int *)(*(longlong *)(this + 0xa8) + 0x54) = (int)param_2;
    }
    CDisplayScenarioContext::JournalFinalize(this);
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalSetSetTimingPathInfo @ 140015230 =====

void DisplayScenarioJournalSetSetTimingPathInfo
               (undefined8 param_1,_WD_MUTEX *param_2,int param_3,undefined4 param_4,
               longlong param_5)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15230  46  DisplayScenarioJournalSetSetTimingPathInfo */
  if ((param_3 != 0) && (param_5 != 0)) {
    AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
    pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
    if (pCVar1 != (CDisplayScenarioContext *)0x0) {
      if (*(CDisplayJournalBase **)(pCVar1 + 0xa8) != (CDisplayJournalBase *)0x0) {
        CDisplayJournalBase::AppendSetTimingsPathInfo
                  (*(CDisplayJournalBase **)(pCVar1 + 0xa8),param_1,(ulonglong)param_2 & 0xffffffff,
                   param_4,param_5);
      }
      if (*(CDisplayJournalBase **)(pCVar1 + 0xb0) != (CDisplayJournalBase *)0x0) {
        CDisplayJournalBase::AppendSetTimingsPathInfo
                  (*(CDisplayJournalBase **)(pCVar1 + 0xb0),param_1,(ulonglong)param_2 & 0xffffffff,
                   param_4,param_5);
      }
    }
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== DisplayRestoreVidPnJournalBegin @ 140015310 =====

void DisplayRestoreVidPnJournalBegin(POWER_MONITOR_REQUEST_REASON param_1,_WD_MUTEX *param_2)

{
  CDisplayScenarioContext *this;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15310  30  DisplayRestoreVidPnJournalBegin */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  this = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if (this != (CDisplayScenarioContext *)0x0) {
    CDisplayScenarioContext::VidPnRestoreJournalBegin(this,param_1);
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalSetUniqueness @ 140015380 =====

void DisplayScenarioJournalSetUniqueness(undefined4 param_1,_WD_MUTEX *param_2)

{
  longlong lVar1;
  CDisplayScenarioContext *pCVar2;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15380  48  DisplayScenarioJournalSetUniqueness */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar2 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if ((pCVar2 != (CDisplayScenarioContext *)0x0) &&
     (lVar1 = *(longlong *)(pCVar2 + 0xa8), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 0x74) = param_1;
    *(int *)(lVar1 + 0x70) = (int)param_2;
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalCCDRetrieval @ 140015400 =====

void DisplayScenarioJournalCCDRetrieval(undefined4 param_1,_WD_MUTEX *param_2)

{
  longlong lVar1;
  CDisplayScenarioContext *pCVar2;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15400  35  DisplayScenarioJournalCCDRetrieval */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar2 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if (((pCVar2 != (CDisplayScenarioContext *)0x0) &&
      (lVar1 = *(longlong *)(pCVar2 + 0xa8), lVar1 != 0)) && (*(int *)(lVar1 + 100) == 0)) {
    *(undefined4 *)(lVar1 + 100) = param_1;
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioContextRelease @ 140015470 =====

/* void __cdecl DisplayScenarioContextRelease(struct _DXGK_DISPLAY_SCENARIO_CONTEXT * __ptr64 const
   & __ptr64) */

void __cdecl DisplayScenarioContextRelease(_DXGK_DISPLAY_SCENARIO_CONTEXT **param_1)

{
  CDisplayScenarioContext *this;
  _WD_MUTEX *in_RDX;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15470  11  DisplayScenarioContextRelease */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,in_RDX);
  this = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId((_GUID *)*param_1);
  if (this != (CDisplayScenarioContext *)0x0) {
    CDisplayContextBase<CDisplayScenarioContext>::Release
              ((CDisplayContextBase<CDisplayScenarioContext> *)this);
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioContextFindAndAddRef @ 1400154e0 =====

/* unsigned char __cdecl DisplayScenarioContextFindAndAddRef(struct _GUID const & __ptr64,struct
   _DXGK_DISPLAY_SCENARIO_CONTEXT * __ptr64 & __ptr64) */

uchar __cdecl
DisplayScenarioContextFindAndAddRef(_GUID *param_1,_DXGK_DISPLAY_SCENARIO_CONTEXT **param_2)

{
  uchar uVar1;
  CDisplayScenarioContext *pCVar2;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x154e0  7  DisplayScenarioContextFindAndAddRef */
  *param_2 = (_DXGK_DISPLAY_SCENARIO_CONTEXT *)0x0;
  AutoMutex::AutoMutex((AutoMutex *)&local_18,(_WD_MUTEX *)param_2);
  pCVar2 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId(param_1);
  if (pCVar2 == (CDisplayScenarioContext *)0x0) {
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
    uVar1 = '\0';
  }
  else {
    *param_2 = (_DXGK_DISPLAY_SCENARIO_CONTEXT *)(pCVar2 + 0x70);
    *(int *)(pCVar2 + 0x18) = *(int *)(pCVar2 + 0x18) + 1;
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
    uVar1 = '\x01';
  }
  return uVar1;
}



===== DisplayScenarioContextDissociate @ 140015590 =====

/* void __cdecl DisplayScenarioContextDissociate(struct _DXGK_DISPLAY_SCENARIO_CONTEXT * __ptr64
   const & __ptr64) */

void __cdecl DisplayScenarioContextDissociate(_DXGK_DISPLAY_SCENARIO_CONTEXT **param_1)

{
  CDisplayScenarioContext *this;
  _WD_MUTEX *in_RDX;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15590  5  DisplayScenarioContextDissociate */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,in_RDX);
  this = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId((_GUID *)*param_1);
  if (this != (CDisplayScenarioContext *)0x0) {
    CDisplayContextBase<CDisplayScenarioContext>::DissociateCurrentThread
              ((CDisplayContextBase<CDisplayScenarioContext> *)this);
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DissociateCurrentThread @ 1400155f4 =====

/* public: void __cdecl CDisplayContextBase<class
   CDisplayScenarioContext>::DissociateCurrentThread(void) __ptr64 */

void __thiscall
CDisplayContextBase<CDisplayScenarioContext>::DissociateCurrentThread
          (CDisplayContextBase<CDisplayScenarioContext> *this)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = PsGetCurrentThreadId();
  uVar1 = 0;
  do {
    if (*(uint *)(this + 0x38) <= uVar1) {
LAB_14001562d:
      Release(this);
      return;
    }
    if (*(longlong *)(this + ((ulonglong)uVar1 + 8) * 8) == lVar2) {
      uVar3 = *(uint *)(this + 0x38) - 1;
      *(uint *)(this + 0x38) = uVar3;
      if (uVar1 < uVar3) {
        memcpy(this + ((ulonglong)uVar1 + 8) * 8,this + ((ulonglong)(uVar1 + 1) + 8) * 8,
               (ulonglong)(uVar3 - uVar1) << 3);
      }
      goto LAB_14001562d;
    }
    uVar1 = uVar1 + 1;
  } while( true );
}



===== DisplayScenarioContextEnsureAndAssociate @ 140015670 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl DisplayScenarioContextEnsureAndAssociate(struct _GUID const & __ptr64,unsigned
   int,unsigned int,struct _DXGK_DISPLAY_SCENARIO_CONTEXT * __ptr64 & __ptr64,unsigned char &
   __ptr64) */

void __cdecl
DisplayScenarioContextEnsureAndAssociate
          (_GUID *param_1,uint param_2,uint param_3,_DXGK_DISPLAY_SCENARIO_CONTEXT **param_4,
          uchar *param_5)

{
  CDisplayContextBase<CDisplayScenarioContext> *pCVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined8 uVar8;
  CDisplayContextBase<CDisplayScenarioContext> *this;
  undefined *puVar9;
  
                    /* 0x15670  6  DisplayScenarioContextEnsureAndAssociate */
  *param_5 = '\0';
  KeEnterCriticalRegion();
  puVar9 = &DAT_14000e868;
  ExAcquirePushLockExclusiveEx(&DAT_14000e868,0);
  _g_displayScenarioMutex = SystemReserved1[0xf];
  if (DAT_14000e048 != 0) {
    uVar8 = _tlgKeywordOn(puVar9,0x400000000001);
    if ((char)uVar8 != '\0') {
      this = (CDisplayContextBase<CDisplayScenarioContext> *)
             CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId(param_1);
      if (this == (CDisplayContextBase<CDisplayScenarioContext> *)0x0) {
        this = (CDisplayContextBase<CDisplayScenarioContext> *)
               ExAllocateFromLookasideListEx(&CDisplayScenarioContext::s_contextLookasideList);
        if (this == (CDisplayContextBase<CDisplayScenarioContext> *)0x0) goto LAB_1400156f0;
        *(undefined4 *)(this + 0x18) = 1;
        *(undefined ***)this = &CDisplayContextBase<CDisplayScenarioContext>::_vftable_;
        this[0x1c] = (CDisplayContextBase<CDisplayScenarioContext>)0x0;
        uVar3 = *(undefined4 *)(param_1 + 4);
        uVar4 = *(undefined4 *)(param_1 + 8);
        uVar5 = *(undefined4 *)(param_1 + 0xc);
        *(undefined4 *)(this + 0x20) = *(undefined4 *)param_1;
        *(undefined4 *)(this + 0x24) = uVar3;
        *(undefined4 *)(this + 0x28) = uVar4;
        *(undefined4 *)(this + 0x2c) = uVar5;
        *(undefined8 *)(this + 0x30) = 0;
        *(undefined4 *)(this + 0x38) = 0;
        *(undefined8 *)(this + 0x30) = _DAT_fffff78000000014;
        pCVar1 = this + 8;
        if (*(_LIST_ENTRY **)DAT_14000e808 != &CDisplayScenarioContext::s_contextLinkList) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(3);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        *(_LIST_ENTRY **)pCVar1 = &CDisplayScenarioContext::s_contextLinkList;
        *(CDisplayContextBase<CDisplayScenarioContext> **)(this + 0x10) = DAT_14000e808;
        *(CDisplayContextBase<CDisplayScenarioContext> **)DAT_14000e808 = pCVar1;
        DAT_14000e808 = pCVar1;
        *(undefined ***)this = &CDisplayScenarioContext::_vftable_;
        *(undefined8 *)(this + 0xa8) = 0;
        *(undefined8 *)(this + 0xb0) = 0;
        *(undefined4 *)(this + 0xb8) = 0;
        uVar8 = *(undefined8 *)param_1;
        uVar6 = *(undefined8 *)(param_1 + 8);
        *(uint *)(this + 0x80) = param_2;
        *(uint *)(this + 0x84) = param_3;
        *(undefined8 *)(this + 0x70) = uVar8;
        *(undefined8 *)(this + 0x78) = uVar6;
        *param_4 = (_DXGK_DISPLAY_SCENARIO_CONTEXT *)(this + 0x70);
      }
      else {
        *param_4 = (_DXGK_DISPLAY_SCENARIO_CONTEXT *)(this + 0x70);
        bVar7 = CDisplayContextBase<CDisplayScenarioContext>::IsCurrentThreadAssociated(this);
        if (bVar7) goto LAB_14001571c;
        *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
      }
      CDisplayContextBase<CDisplayScenarioContext>::AssociateCurrentThread(this);
      *param_5 = '\x01';
      CDisplayContextBase<CDisplayScenarioContext>::Release(this);
      goto LAB_14001571c;
    }
  }
LAB_1400156f0:
  _DAT_14000e9f8 = 0;
  _s_contingencyContext = 0;
  uRam000000014000e9d0 = 0;
  _DAT_14000e9d8 = 0;
  uRam000000014000e9e0 = 0;
  _DAT_14000e9e8 = 0;
  uRam000000014000e9f0 = 0;
  *param_4 = &CDisplayScenarioContext::s_contingencyContext;
LAB_14001571c:
  _g_displayScenarioMutex = (void *)0x0;
  ExReleasePushLockExclusiveEx(&DAT_14000e868,0);
  KeLeaveCriticalRegion();
  return;
}



===== FindContextFromActivityId @ 140015870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: static class CDisplayScenarioContext * __ptr64 __cdecl CDisplayContextBase<class
   CDisplayScenarioContext>::FindContextFromActivityId(struct _GUID const & __ptr64) */

CDisplayScenarioContext * __cdecl
CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId(_GUID *param_1)

{
  CDisplayScenarioContext *this;
  _LIST_ENTRY *p_Var1;
  longlong lVar2;
  longlong lVar3;
  CDisplayScenarioContext *pCVar4;
  _LIST_ENTRY *p_Var5;
  
  lVar2 = _DAT_fffff78000000014;
  lVar3 = *(longlong *)param_1;
  pCVar4 = (CDisplayScenarioContext *)0x0;
  if (lVar3 == 0) {
    lVar3 = *(longlong *)(param_1 + 8);
  }
  if (lVar3 == 0) {
    return (CDisplayScenarioContext *)0x0;
  }
  p_Var5 = _s_contextLinkList;
  if (_s_contextLinkList != &CDisplayScenarioContext::s_contextLinkList) {
    do {
      this = (CDisplayScenarioContext *)(p_Var5 + -8);
      p_Var1 = *(_LIST_ENTRY **)p_Var5;
      lVar3 = *(longlong *)(p_Var5 + 0x18) - *(longlong *)param_1;
      if (lVar3 == 0) {
        lVar3 = *(longlong *)(p_Var5 + 0x20) - *(longlong *)(param_1 + 8);
      }
      if (lVar3 == 0) {
        pCVar4 = this;
      }
      else if (((*(int *)(p_Var5 + 0x10) == 0) && (*(longlong *)(p_Var5 + 0x28) <= lVar2)) &&
              (8999999999 < lVar2 - *(longlong *)(p_Var5 + 0x28))) {
        CDisplayScenarioContext::ReportLeaked(this);
        (*(code *)**(undefined8 **)this)(this,1);
      }
      p_Var5 = p_Var1;
    } while (p_Var1 != &CDisplayScenarioContext::s_contextLinkList);
  }
  return pCVar4;
}



===== Release @ 140015970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CDisplayContextBase<class CDisplayScenarioContext>::Release(void) __ptr64 */

void __thiscall
CDisplayContextBase<CDisplayScenarioContext>::Release
          (CDisplayContextBase<CDisplayScenarioContext> *this)

{
  CDisplayContextBase<CDisplayScenarioContext> *pCVar1;
  
  pCVar1 = this + 0x18;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  if ((*(int *)pCVar1 == 0) && (this[0x1c] == (CDisplayContextBase<CDisplayScenarioContext>)0x0)) {
    (*(code *)**(undefined8 **)this)(this,1);
  }
  return;
}



===== AssociateCurrentThread @ 14001599c =====

/* public: void __cdecl CDisplayContextBase<class
   CDisplayScenarioContext>::AssociateCurrentThread(void) __ptr64 */

void __thiscall
CDisplayContextBase<CDisplayScenarioContext>::AssociateCurrentThread
          (CDisplayContextBase<CDisplayScenarioContext> *this)

{
  CDisplayContextBase<CDisplayScenarioContext> *pCVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
  if (6 < *(int *)(this + 0x38) + 1U) {
    return;
  }
  uVar5 = PsGetCurrentThreadId();
  *(undefined8 *)(this + (ulonglong)*(uint *)(this + 0x38) * 8 + 0x40) = uVar5;
  pCVar1 = this + 8;
  *(int *)(this + 0x38) = *(int *)(this + 0x38) + 1;
  lVar2 = *(longlong *)pCVar1;
  if ((*(CDisplayContextBase<CDisplayScenarioContext> **)(lVar2 + 8) == pCVar1) &&
     (plVar3 = *(longlong **)(this + 0x10),
     (CDisplayContextBase<CDisplayScenarioContext> *)*plVar3 == pCVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    if (*(_LIST_ENTRY **)DAT_14000e808 == &CDisplayScenarioContext::s_contextLinkList) {
      *(_LIST_ENTRY **)pCVar1 = &CDisplayScenarioContext::s_contextLinkList;
      *(CDisplayContextBase<CDisplayScenarioContext> **)(this + 0x10) = DAT_14000e808;
      *(CDisplayContextBase<CDisplayScenarioContext> **)DAT_14000e808 = pCVar1;
      DAT_14000e808 = pCVar1;
      return;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== DisplayScenarioJournalSetActualPathModality @ 140015a20 =====

void DisplayScenarioJournalSetActualPathModality
               (int param_1,_WD_MUTEX *param_2,D3DKMT_PATHMODALITY_DESCRIPTOR *param_3)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15a20  41  DisplayScenarioJournalSetActualPathModality */
  if ((param_1 != 0) && (param_3 != (D3DKMT_PATHMODALITY_DESCRIPTOR *)0x0)) {
    AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
    pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
    if ((pCVar1 != (CDisplayScenarioContext *)0x0) &&
       (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8) != (CDisplayScenarioJournal *)0x0)) {
      CDisplayScenarioJournal::SetActualPathModality
                (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8),(uint)param_2,param_3);
    }
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== DisplayRestoreVidPnResult @ 140015ab0 =====

void DisplayRestoreVidPnResult
               (undefined8 param_1,_WD_MUTEX *param_2,undefined4 param_3,undefined4 param_4)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15ab0  32  DisplayRestoreVidPnResult */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if ((pCVar1 != (CDisplayScenarioContext *)0x0) &&
     (*(CDisplayRestoreVidPnJournal **)(pCVar1 + 0xb0) != (CDisplayRestoreVidPnJournal *)0x0)) {
    CDisplayRestoreVidPnJournal::JournalSetResult
              (*(CDisplayRestoreVidPnJournal **)(pCVar1 + 0xb0),param_1,
               (ulonglong)param_2 & 0xffffffff,param_3,param_4);
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalSetCommitVidPnStatus @ 140015b50 =====

void DisplayScenarioJournalSetCommitVidPnStatus(ulong *param_1,_WD_MUTEX *param_2)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15b50  42  DisplayScenarioJournalSetCommitVidPnStatus */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if ((pCVar1 != (CDisplayScenarioContext *)0x0) &&
     (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8) != (CDisplayScenarioJournal *)0x0)) {
    CDisplayScenarioJournal::SetCommitVidPnStatus
              (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8),param_1,(long *)param_2);
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalSetResult @ 140015bd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DisplayScenarioJournalSetResult
               (undefined4 param_1,_WD_MUTEX *param_2,byte param_3,undefined8 param_4,byte param_5,
               undefined4 param_6,undefined8 *param_7)

{
  longlong lVar1;
  CDisplayScenarioContext *pCVar2;
  undefined8 uVar3;
  AutoMutex *this;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined7 uVar6;
  undefined1 auStackY_98 [32];
  uint local_68 [2];
  undefined8 *local_60;
  char local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
                    /* 0x15bd0  44  DisplayScenarioJournalSetResult */
  uVar5 = (undefined1)param_4;
  uVar6 = (undefined7)((ulonglong)param_4 >> 8);
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  this = (AutoMutex *)&local_60;
  puVar4 = &local_50;
  if (param_7 != (undefined8 *)0x0) {
    puVar4 = param_7;
  }
  AutoMutex::AutoMutex(this,param_2);
  pCVar2 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if (pCVar2 != (CDisplayScenarioContext *)0x0) {
    if (((DAT_14000e1a0 != '\0') || (param_5 != DAT_14000ea10)) && (5 < DAT_14000e048)) {
      uVar3 = _tlgKeywordOn(this,0x40);
      if ((char)uVar3 != '\0') {
        local_68[0] = (uint)param_5;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::Write<_tlgWrapperByVal<4>_>
                  ((_tlgProvider_t *)this,&DAT_14000cc81,(_GUID *)(pCVar2 + 0x20),
                   (_GUID *)CONCAT71(uVar6,uVar5),(_tlgWrapperByVal<4> *)local_68);
      }
    }
    lVar1 = *(longlong *)(pCVar2 + 0xa8);
    DAT_14000ea10 = param_5;
    DAT_14000e1a0 = '\0';
    if (lVar1 != 0) {
      *(undefined4 *)(lVar1 + 0x88) = param_6;
      *(undefined4 *)(lVar1 + 0x58) = param_1;
      *(int *)(lVar1 + 0x68) = (int)param_2;
      *(uint *)(lVar1 + 0x80) = (uint)param_3;
      *(uint *)(lVar1 + 0x84) = (uint)param_4 & 0xff;
      uVar3 = puVar4[1];
      *(undefined8 *)(lVar1 + 0xd8) = *puVar4;
      *(undefined8 *)(lVar1 + 0xe0) = uVar3;
      uVar3 = puVar4[3];
      *(undefined8 *)(lVar1 + 0xe8) = puVar4[2];
      *(undefined8 *)(lVar1 + 0xf0) = uVar3;
      *(undefined8 *)(lVar1 + 0xf8) = puVar4[4];
    }
  }
  if (local_58 != '\0') {
    *local_60 = 0;
    ExReleasePushLockExclusiveEx(local_60 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalVidPnSourceVisibility @ 140015d70 =====

void DisplayScenarioJournalVidPnSourceVisibility
               (undefined8 param_1,_WD_MUTEX *param_2,undefined8 param_3,byte param_4,uint param_5)

{
  CDisplayScenarioJournal *pCVar1;
  int iVar2;
  CDisplayScenarioContext *pCVar3;
  longlong lVar4;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15d70  49  DisplayScenarioJournalVidPnSourceVisibility */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar3 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if (((pCVar3 != (CDisplayScenarioContext *)0x0) &&
      (pCVar1 = *(CDisplayScenarioJournal **)(pCVar3 + 0xa8),
      pCVar1 != (CDisplayScenarioJournal *)0x0)) && (*(longlong *)(pCVar1 + 0xd0) != 0)) {
    iVar2 = CDisplayScenarioJournal::GetOrAssignDisplayStateIndex
                      (pCVar1,param_1,(ulonglong)param_2 & 0xffffffff);
    if (-1 < iVar2) {
      lVar4 = (longlong)iVar2 * 0x4c + *(longlong *)(pCVar1 + 0xd0);
      *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
      *(uint *)(lVar4 + 0xc) = (uint)param_4;
      if (param_4 == 0) {
        *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) | param_5;
      }
      else {
        *(uint *)(lVar4 + 0x14) = *(uint *)(lVar4 + 0x14) | param_5;
      }
    }
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DisplayScenarioJournalDisplayUniquenessIncremented @ 140015e40 =====

void DisplayScenarioJournalDisplayUniquenessIncremented(undefined8 param_1,_WD_MUTEX *param_2)

{
  int *piVar1;
  CDisplayScenarioContext *pCVar2;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x15e40  37  DisplayScenarioJournalDisplayUniquenessIncremented */
  AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
  pCVar2 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
  if ((pCVar2 != (CDisplayScenarioContext *)0x0) && (*(longlong *)(pCVar2 + 0xa8) != 0)) {
    piVar1 = (int *)(*(longlong *)(pCVar2 + 0xa8) + 0x78);
    *piVar1 = *piVar1 + 1;
  }
  if (local_10 != '\0') {
    *local_18 = 0;
    ExReleasePushLockExclusiveEx(local_18 + 1);
    KeLeaveCriticalRegion();
  }
  return;
}



===== FindContextFromCurrrentThread @ 140015ea4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: static class CDisplayScenarioContext * __ptr64 __cdecl CDisplayContextBase<class
   CDisplayScenarioContext>::FindContextFromCurrrentThread(void) */

CDisplayScenarioContext * __cdecl
CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread(void)

{
  CDisplayContextBase<CDisplayScenarioContext> *this;
  _LIST_ENTRY *p_Var1;
  longlong lVar2;
  bool bVar3;
  CDisplayContextBase<CDisplayScenarioContext> *pCVar4;
  _LIST_ENTRY *p_Var5;
  
  lVar2 = _DAT_fffff78000000014;
  PsGetCurrentThreadId();
  pCVar4 = (CDisplayContextBase<CDisplayScenarioContext> *)0x0;
  p_Var1 = _s_contextLinkList;
  while (p_Var5 = p_Var1, p_Var5 != &CDisplayScenarioContext::s_contextLinkList) {
    this = (CDisplayContextBase<CDisplayScenarioContext> *)(p_Var5 + -8);
    p_Var1 = *(_LIST_ENTRY **)p_Var5;
    bVar3 = IsCurrentThreadAssociated(this);
    if (bVar3) {
      pCVar4 = this;
    }
    else if (((*(int *)(p_Var5 + 0x10) == 0) && (*(longlong *)(p_Var5 + 0x28) <= lVar2)) &&
            (8999999999 < lVar2 - *(longlong *)(p_Var5 + 0x28))) {
      CDisplayScenarioContext::ReportLeaked((CDisplayScenarioContext *)this);
      (*(code *)**(undefined8 **)this)(this,1);
    }
  }
  return (CDisplayScenarioContext *)pCVar4;
}



===== IsCurrentThreadAssociated @ 140015f6c =====

/* public: bool __cdecl CDisplayContextBase<class
   CDisplayScenarioContext>::IsCurrentThreadAssociated(void)const __ptr64 */

bool __thiscall
CDisplayContextBase<CDisplayScenarioContext>::IsCurrentThreadAssociated
          (CDisplayContextBase<CDisplayScenarioContext> *this)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = PsGetCurrentThreadId();
  uVar2 = 0;
  while( true ) {
    if (*(uint *)(this + 0x38) <= (uint)uVar2) {
      return false;
    }
    if (*(longlong *)(this + uVar2 * 8 + 0x40) == lVar1) break;
    uVar2 = (ulonglong)((uint)uVar2 + 1);
  }
  return true;
}



===== SetActualPathModality @ 140015fac =====

/* public: void __cdecl CDisplayScenarioJournal::SetActualPathModality(unsigned int,struct
   D3DKMT_PATHMODALITY_DESCRIPTOR * __ptr64) __ptr64 */

void __thiscall
CDisplayScenarioJournal::SetActualPathModality
          (CDisplayScenarioJournal *this,uint param_1,D3DKMT_PATHMODALITY_DESCRIPTOR *param_2)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  void *pvVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  D3DKMT_PATHMODALITY_DESCRIPTOR *pDVar7;
  uint uVar8;
  
  if (*(longlong *)(this + 0xc0) == 0) {
    uVar6 = 0;
    uVar8 = 0;
    if (param_1 != 0) {
      pDVar7 = param_2 + 0x1c;
      do {
        if ((*(ulonglong *)(pDVar7 + -0x1c) >> 0x38 & 1) != 0) {
          for (uVar4 = 0; (uint)uVar4 < uVar8; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
            lVar5 = uVar4 * 0x128;
            if (((*(int *)pDVar7 == *(int *)(param_2 + lVar5 + 0x1c)) &&
                (*(int *)(pDVar7 + -0xc) == *(int *)(param_2 + lVar5 + 0x10))) &&
               (*(int *)(pDVar7 + -8) == *(int *)(param_2 + lVar5 + 0x14))) goto LAB_140015ff0;
          }
          uVar6 = uVar6 + 1;
        }
LAB_140015ff0:
        uVar8 = uVar8 + 1;
        pDVar7 = pDVar7 + 0x128;
      } while (uVar8 < param_1);
      if (uVar6 != 0) {
        auVar1 = ZEXT816(0xd8) * ZEXT416(uVar6);
        _Var2 = auVar1._0_8_;
        if (auVar1._8_8_ != 0) {
          _Var2 = 0xffffffffffffffff;
        }
        pvVar3 = operator_new(_Var2,auVar1._8_4_,(__uint64)pDVar7);
        *(void **)(this + 0xc0) = pvVar3;
        if (pvVar3 != (void *)0x0) {
          *(uint *)(this + 0xb8) = uVar6;
          TrimLowPriorityPaths(param_1,(longlong)param_2,(uint *)(this + 0xb8),(longlong)pvVar3);
        }
      }
    }
  }
  return;
}



===== AppendSetTimingsPathInfo @ 140016090 =====

/* public: void __cdecl CDisplayJournalBase::AppendSetTimingsPathInfo(struct _LUID,long,unsigned
   int,struct _DXGK_SET_TIMING_PATH_INFO * __ptr64) __ptr64 */

void __thiscall
CDisplayJournalBase::AppendSetTimingsPathInfo
          (CDisplayJournalBase *this,undefined8 param_2,__uint64 param_3,uint param_4,
          longlong param_5)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  void *_Dst;
  ushort uVar3;
  
  uVar3 = (short)param_4 + *(short *)(this + 0x10);
  auVar1 = ZEXT816(0x3c) * ZEXT216(uVar3);
  _Var2 = auVar1._0_8_;
  if (auVar1._8_8_ != 0) {
    _Var2 = 0xffffffffffffffff;
  }
  _Dst = operator_new(_Var2,auVar1._8_4_,param_3);
  if (_Dst != (void *)0x0) {
    if (*(void **)(this + 0x18) != (void *)0x0) {
      memcpy(_Dst,*(void **)(this + 0x18),(ulonglong)*(ushort *)(this + 0x10) * 0x3c);
      operator_delete__(*(void **)(this + 0x18));
    }
    CopyDisplayScenarioSetTimingPathInfo
              (param_2,(int)param_3,param_5,param_4,
               (longlong)((ulonglong)*(ushort *)(this + 0x10) * 0x3c + (longlong)_Dst));
    *(ushort *)(this + 0x10) = uVar3;
    *(void **)(this + 0x18) = _Dst;
  }
  return;
}



===== DisplayScenraioJournalBegin @ 140016150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl CDisplayScenarioContext::DisplayScenraioJournalBegin(unsigned int,unsigned
   int,unsigned short) __ptr64 */

void __thiscall
CDisplayScenarioContext::DisplayScenraioJournalBegin
          (CDisplayScenarioContext *this,uint param_1,uint param_2,ushort param_3)

{
  CDisplayScenarioJournal *this_00;
  longlong lVar1;
  undefined4 in_register_00000084;
  
  *(int *)(this + 0xb8) = *(int *)(this + 0xb8) + 1;
  if (*(longlong *)(this + 0xa8) == 0) {
    this_00 = operator_new(0x100,param_1,CONCAT44(in_register_00000084,param_2));
    if (this_00 == (CDisplayScenarioJournal *)0x0) {
      *(undefined8 *)(this + 0xa8) = 0;
    }
    else {
      lVar1 = CDisplayScenarioJournal::CDisplayScenarioJournal(this_00,this);
      *(longlong *)(this + 0xa8) = lVar1;
      if (lVar1 != 0) {
        *(undefined8 *)(lVar1 + 0x3c) = _DAT_fffff78000000014;
        *(uint *)(lVar1 + 0x4c) = param_1;
        *(uint *)(lVar1 + 0x50) = param_2;
        *(uint *)(lVar1 + 0x5c) = (uint)param_3;
      }
    }
  }
  return;
}



===== CDisplayScenarioJournal @ 1400161e8 =====

/* public: __cdecl CDisplayScenarioJournal::CDisplayScenarioJournal(class CDisplayScenarioContext &
   __ptr64) __ptr64 */

CDisplayScenarioJournal * __thiscall
CDisplayScenarioJournal::CDisplayScenarioJournal
          (CDisplayScenarioJournal *this,CDisplayScenarioContext *param_1)

{
  *(CDisplayScenarioContext **)(this + 8) = param_1;
  *(undefined ***)this = &_vftable_;
  *(undefined2 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined2 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 200) = 0;
  *(undefined2 *)(this + 0xcc) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  memset(this + 0x20,0,0x6c);
  return this;
}



===== operator_delete @ 140016288 =====

/* public: static void __cdecl CDisplayScenarioContext::operator delete(void * __ptr64) */

void __cdecl CDisplayScenarioContext::operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreeToLookasideListEx(&s_contextLookasideList,param_1);
  }
  return;
}



===== DisplayLogSetMonitorPowerStage @ 1400162c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DisplayLogSetMonitorPowerStage
               (undefined4 *param_1,uint param_2,undefined4 param_3,_GUID *param_4)

{
  undefined8 uVar1;
  uint uVar2;
  _tlgProvider_t *p_Var3;
  undefined *puVar4;
  char *pcVar5;
  _GUID *p_Var6;
  char *local_res8;
  undefined4 local_res10 [2];
  
                    /* 0x162c0  29  DisplayLogSetMonitorPowerStage */
  if (param_1 != (undefined4 *)0x0) {
    _DAT_14000ea00 = *(undefined8 *)param_1;
    uRam000000014000ea08 = *(undefined8 *)(param_1 + 2);
  }
  uVar2 = param_2 & 0x7fffffff;
  if (uVar2 == 1) {
    pcVar5 = "PowerOffDisplay";
    p_Var3 = (_tlgProvider_t *)0x0;
  }
  else if (uVar2 == 2) {
    pcVar5 = "ChildInvalidation";
    p_Var3 = (_tlgProvider_t *)0x0;
  }
  else if (uVar2 == 4) {
    pcVar5 = "SetMonitorPower";
    p_Var3 = (_tlgProvider_t *)0x0;
  }
  else if (uVar2 == 8) {
    pcVar5 = "PowerOnDisplay";
    p_Var3 = (_tlgProvider_t *)0x0;
  }
  else {
    uVar2 = uVar2 - 0x10;
    p_Var3 = (_tlgProvider_t *)(ulonglong)uVar2;
    if (uVar2 == 0) {
      pcVar5 = "SetTimings";
    }
    else if (uVar2 == 0x10) {
      pcVar5 = "CommitVidPn";
    }
    else {
      pcVar5 = "Unknown";
    }
  }
  p_Var6 = param_4;
  if ((int)param_2 < 0) {
    if (DAT_14000e048 < 6) {
      return;
    }
    uVar1 = _tlgKeywordOn(p_Var3,0x80);
    if ((char)uVar1 == '\0') {
      return;
    }
    puVar4 = &DAT_14000cc3f;
  }
  else {
    p_Var3 = (_tlgProvider_t *)0x3;
    EtwActivityIdControl(3,param_4);
    if (DAT_14000e048 < 6) {
      return;
    }
    uVar1 = _tlgKeywordOn(p_Var3,0x80);
    if ((char)uVar1 == '\0') {
      return;
    }
    puVar4 = &DAT_14000cbfd;
  }
  local_res8 = pcVar5;
  local_res10[0] = param_3;
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::Write<_tlgWrapSz<char>,_tlgWrapperByVal<4>_>
            (p_Var3,puVar4,param_4,p_Var6,(_tlgWrapSz<char> *)&local_res8,
             (_tlgWrapperByVal<4> *)local_res10);
  return;
}



===== WdpAppendSecondaryDumpData @ 1400163f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
WdpAppendSecondaryDumpData(longlong param_1,undefined4 *param_2,undefined8 *param_3,uint param_4)

{
  longlong *plVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  uint uVar12;
  uint uVar13;
  undefined1 auStack_f8 [32];
  undefined8 *local_d8;
  undefined8 *local_d0;
  uint local_c8;
  undefined8 *local_c0;
  undefined8 local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 uStack_98;
  longlong local_90 [3];
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_f8;
  uVar12 = param_4;
  local_78 = param_2;
  uVar8 = WdpDbgReportGetExtSizeByGuid((undefined *)param_2);
  local_90[2] = 0;
  uVar13 = (int)uVar8 + 0x7ffd0;
  if (((param_3 != (undefined8 *)0x0) && (uVar12 != 0)) && (param_1 != 0)) {
    local_a4 = 0xffffffff;
    plVar1 = (longlong *)(param_1 + 0x280);
    local_a8 = 0xfffffffe;
    local_a0 = 0;
    uStack_98 = 0;
    local_58 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_90[1] = 0;
    local_90[0] = 0;
    if (((*plVar1 != 0) || (iVar6 = WdpWerCreateReport(plVar1), -1 < iVar6)) &&
       (uVar9 = WdpWerCreateDumpFile(plVar1,local_90), lVar5 = local_90[0], -1 < (int)uVar9)) {
      local_d8 = (undefined8 *)CONCAT44(local_d8._4_4_,0xe);
      iVar6 = ZwQueryInformationFile(local_90[0],&local_a0,local_90 + 1,8);
      if (iVar6 < 0) {
        WdLogSingleEntry1(2,(longlong)iVar6);
        _WdLogGlobalForLineNumber = 0x14b;
      }
      else {
        puVar10 = (undefined8 *)ExAllocatePool2(0x42,0x10,0x676f6457);
        if (puVar10 == (undefined8 *)0x0) {
          WdLogSingleEntry0(6);
          _WdLogGlobalForLineNumber = 0x15a;
        }
        else {
          puVar11 = (undefined8 *)ExAllocatePool2(0x42,0x20,0x676f6457);
          if (puVar11 == (undefined8 *)0x0) {
            WdLogSingleEntry0(6);
            _WdLogGlobalForLineNumber = 0x169;
          }
          else {
            while( true ) {
              uVar12 = param_4 - 1;
              if ((uVar12 == 0) || (*(char *)((ulonglong)uVar12 + (longlong)param_3) != '\0'))
              break;
              param_4 = uVar12;
            }
            if (uVar13 < param_4) {
              WdLogSingleEntry2(1,(ulonglong)param_4,(ulonglong)uVar13);
              _WdLogGlobalForLineNumber = 0x183;
              param_4 = uVar13;
            }
            *(undefined4 *)puVar10 = 0x706d7544;
            *(undefined4 *)((longlong)puVar10 + 4) = 0x626f6c42;
            *(undefined4 *)(puVar10 + 1) = 0x10;
            uVar7 = WdpGetBuildNumber();
            *(undefined4 *)((longlong)puVar10 + 0xc) = uVar7;
            local_b8 = 0;
            local_c0 = (undefined8 *)&local_a8;
            local_c8 = *(uint *)(puVar10 + 1);
            local_d8 = &local_a0;
            local_d0 = puVar10;
            iVar6 = ZwWriteFile(lVar5,0,0,0);
            if (iVar6 < 0) {
              WdLogSingleEntry1(2,(longlong)iVar6);
              _WdLogGlobalForLineNumber = 0x19d;
            }
            else {
              local_b8 = 0;
              *(undefined4 *)puVar11 = 0x20;
              puVar11[3] = 0;
              uVar7 = *local_78;
              uVar2 = local_78[1];
              uVar3 = local_78[2];
              uVar4 = local_78[3];
              local_c0 = (undefined8 *)&local_a8;
              *(uint *)((longlong)puVar11 + 0x14) = param_4;
              local_d8 = &local_a0;
              local_c8 = 0x20;
              *(undefined4 *)((longlong)puVar11 + 4) = uVar7;
              *(undefined4 *)(puVar11 + 1) = uVar2;
              *(undefined4 *)((longlong)puVar11 + 0xc) = uVar3;
              *(undefined4 *)(puVar11 + 2) = uVar4;
              local_d0 = puVar11;
              iVar6 = ZwWriteFile(lVar5,0,0,0);
              if (iVar6 < 0) {
                WdLogSingleEntry1(2,(longlong)iVar6);
                _WdLogGlobalForLineNumber = 0x1b8;
              }
              else {
                local_b8 = 0;
                local_c0 = (undefined8 *)&local_a8;
                local_d8 = &local_a0;
                local_d0 = param_3;
                local_c8 = param_4;
                iVar6 = ZwWriteFile(lVar5,0,0,0);
                if (iVar6 < 0) {
                  WdLogSingleEntry1(2,(longlong)iVar6);
                  _WdLogGlobalForLineNumber = 0x1cd;
                }
                else {
                  local_d8 = (undefined8 *)CONCAT44(local_d8._4_4_,5);
                  iVar6 = ZwQueryInformationFile(lVar5,&local_a0,&local_68,0x18);
                  if (iVar6 < 0) {
                    WdLogSingleEntry1(2,(longlong)iVar6);
                    _WdLogGlobalForLineNumber = 0x1dd;
                  }
                  else {
                    local_b8 = 0;
                    local_c0 = &local_70;
                    local_d0 = &uStack_60;
                    local_c8 = 8;
                    local_d8 = &local_a0;
                    local_70 = 4000;
                    iVar6 = ZwWriteFile(lVar5,0,0,0);
                    if (iVar6 < 0) {
                      WdLogSingleEntry1(2,(longlong)iVar6);
                      _WdLogGlobalForLineNumber = 499;
                    }
                    else {
                      local_d8 = (undefined8 *)CONCAT44(local_d8._4_4_,0xe);
                      iVar6 = ZwSetInformationFile(lVar5,&local_a0,local_90 + 1,8);
                      if (iVar6 < 0) {
                        WdLogSingleEntry1(2,(longlong)iVar6);
                        _WdLogGlobalForLineNumber = 0x205;
                      }
                      else {
                        local_d8 = &local_a0;
                        iVar6 = ZwFlushBuffersFileEx(*(undefined8 *)(param_1 + 0x2b0),0,0,0);
                        if (iVar6 < 0) {
                          WdLogSingleEntry1(2,(longlong)iVar6);
                          _WdLogGlobalForLineNumber = 0x216;
                        }
                        else {
                          local_90[2] = uStack_60;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          ExFreePoolWithTag(puVar10,0x676f6457);
          if (puVar11 != (undefined8 *)0x0) {
            ExFreePoolWithTag(puVar11,0x676f6457);
          }
        }
      }
    }
  }
  return local_90[2];
}



===== WdpWerCreateDumpFile @ 1400168cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WdpWerCreateDumpFile(undefined8 *param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  
  *param_2 = 0;
  plVar1 = param_1 + 6;
  if (*plVar1 == 0) {
    iVar2 = WerLiveKernelOpenDumpFile(*param_1,plVar1);
    uVar3 = (ulonglong)iVar2;
    if (iVar2 < 0) {
      *plVar1 = 0;
      WdLogSingleEntry1(1,uVar3);
      _WdLogGlobalForLineNumber = 0x71;
      goto LAB_14001692a;
    }
  }
  else {
    uVar3 = 0;
  }
  *param_2 = *plVar1;
LAB_14001692a:
  return uVar3 & 0xffffffff;
}



===== WdpGetBuildNumber @ 140016944 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 WdpGetBuildNumber(void)

{
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined1 local_134 [8];
  undefined4 local_12c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(local_134,0,0x110);
  local_138 = 0x114;
  RtlGetVersion(&local_138);
  return local_12c;
}



===== _tlgEnableCallback @ 1400169b0 =====

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



===== SetExpectedPathModality @ 140016a2c =====

/* public: void __cdecl CDisplayScenarioJournal::SetExpectedPathModality(unsigned int,struct
   D3DKMT_PATHMODALITY_DESCRIPTOR * __ptr64,unsigned int) __ptr64 */

void __thiscall
CDisplayScenarioJournal::SetExpectedPathModality
          (CDisplayScenarioJournal *this,uint param_1,D3DKMT_PATHMODALITY_DESCRIPTOR *param_2,
          uint param_3)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  D3DKMT_PATHMODALITY_DESCRIPTOR *pDVar3;
  void *_Dst;
  uint uVar4;
  D3DKMT_PATHMODALITY_DESCRIPTOR *pDVar5;
  
  if (*(longlong *)(this + 0xb0) == 0) {
    auVar1 = ZEXT816(0xd8) * ZEXT416(param_1);
    _Var2 = auVar1._0_8_;
    if (auVar1._8_8_ != 0) {
      _Var2 = 0xffffffffffffffff;
    }
    pDVar5 = param_2;
    pDVar3 = operator_new(_Var2,auVar1._8_4_,(__uint64)param_2);
    *(D3DKMT_PATHMODALITY_DESCRIPTOR **)(this + 0xb0) = pDVar3;
    if (pDVar3 != (D3DKMT_PATHMODALITY_DESCRIPTOR *)0x0) {
      CopyDisplayScenarioPathModalityDescriptor((longlong)param_2,param_1,(longlong)pDVar3);
      *(uint *)(this + 0xa8) = param_1;
      pDVar5 = pDVar3;
    }
    uVar4 = 8;
    *(short *)(this + 0xca) = (short)param_3;
    if (param_3 < 9) {
      uVar4 = param_3 & 0xffff;
    }
    auVar1._8_8_ = 0;
    auVar1._0_8_ = CONCAT44(0,uVar4);
    auVar1 = ZEXT816(0x4c) * auVar1;
    _Var2 = auVar1._0_8_;
    *(undefined2 *)(this + 0xcc) = 0;
    *(undefined2 *)(this + 200) = 0;
    if (auVar1._8_8_ != 0) {
      _Var2 = 0xffffffffffffffff;
    }
    _Dst = operator_new(_Var2,auVar1._8_4_,(__uint64)pDVar5);
    *(void **)(this + 0xd0) = _Dst;
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,CONCAT44(0,uVar4) * 0x4c);
      *(short *)(this + 200) = (short)uVar4;
    }
  }
  return;
}



===== CopyDisplayScenarioPathModalityDescriptor @ 140016b14 =====

void CopyDisplayScenarioPathModalityDescriptor(longlong param_1,uint param_2,longlong param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  if (param_2 != 0) {
    uVar4 = (ulonglong)param_2;
    puVar2 = (undefined8 *)(param_1 + 0x10);
    puVar3 = (undefined8 *)(param_3 + 0x10);
    do {
      puVar3[-2] = puVar2[-2];
      puVar3[-1] = puVar2[-1];
      *puVar3 = *puVar2;
      *(undefined4 *)(puVar3 + 1) = *(undefined4 *)(puVar2 + 1);
      *(undefined4 *)((longlong)puVar3 + 0xc) = *(undefined4 *)((longlong)puVar2 + 0xc);
      *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(puVar2 + 2);
      *(undefined8 *)((longlong)puVar3 + 0x14) = *(undefined8 *)((longlong)puVar2 + 0x14);
      *(undefined8 *)((longlong)puVar3 + 0x1c) = *(undefined8 *)((longlong)puVar2 + 0x1c);
      *(undefined8 *)((longlong)puVar3 + 0x24) = *(undefined8 *)((longlong)puVar2 + 0x24);
      *(undefined8 *)((longlong)puVar3 + 0x2c) = puVar2[0x1a];
      *(undefined8 *)((longlong)puVar3 + 0x34) = puVar2[0x1b];
      *(undefined4 *)((longlong)puVar3 + 0x44) = *(undefined4 *)(puVar2 + 7);
      *(undefined4 *)(puVar3 + 9) = *(undefined4 *)(puVar2 + 0x1c);
      *(undefined4 *)((longlong)puVar3 + 0x4c) = *(undefined4 *)(puVar2 + 8);
      *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(puVar2 + 9);
      *(undefined4 *)((longlong)puVar3 + 0x54) = *(undefined4 *)((longlong)puVar2 + 0x4c);
      uVar1 = puVar2[0xb];
      puVar3[0xb] = puVar2[10];
      puVar3[0xc] = uVar1;
      uVar1 = puVar2[0xd];
      puVar3[0xd] = puVar2[0xc];
      puVar3[0xe] = uVar1;
      *(uint *)(puVar3 + 0xf) = (uint)*(byte *)(puVar2 + 0xe);
      *(uint *)((longlong)puVar3 + 0x7c) = (uint)*(byte *)((longlong)puVar2 + 0x71);
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)((longlong)puVar2 + 0x74);
      *(undefined4 *)((longlong)puVar3 + 0x84) = *(undefined4 *)(puVar2 + 0xf);
      *(undefined4 *)(puVar3 + 0x11) = *(undefined4 *)((longlong)puVar2 + 0x7c);
      *(undefined8 *)((longlong)puVar3 + 0x8c) = puVar2[0x10];
      *(undefined8 *)((longlong)puVar3 + 0x94) = puVar2[0x11];
      uVar1 = puVar2[0x14];
      *(undefined8 *)((longlong)puVar3 + 0x9c) = puVar2[0x13];
      *(undefined8 *)((longlong)puVar3 + 0xa4) = uVar1;
      *(undefined4 *)((longlong)puVar3 + 0xac) = *(undefined4 *)(puVar2 + 0x15);
      *(undefined4 *)(puVar3 + 0x16) = *(undefined4 *)((longlong)puVar2 + 0xac);
      *(undefined4 *)((longlong)puVar3 + 0xb4) = *(undefined4 *)(puVar2 + 0x16);
      *(undefined4 *)(puVar3 + 0x17) = *(undefined4 *)((longlong)puVar2 + 0xbc);
      *(undefined4 *)((longlong)puVar3 + 0xbc) = *(undefined4 *)(puVar2 + 0x18);
      *(undefined4 *)(puVar3 + 0x18) = *(undefined4 *)(puVar2 + 0x19);
      *(undefined4 *)((longlong)puVar3 + 0xc4) = *(undefined4 *)((longlong)puVar2 + 0xc4);
      uVar4 = uVar4 - 1;
      puVar2 = puVar2 + 0x25;
      puVar3 = puVar3 + 0x1b;
    } while (uVar4 != 0);
  }
  return;
}



===== SetCommitVidPnStatus @ 140016ca4 =====

/* public: void __cdecl CDisplayScenarioJournal::SetCommitVidPnStatus(unsigned long * __ptr64,long *
   __ptr64) __ptr64 */

void __thiscall
CDisplayScenarioJournal::SetCommitVidPnStatus
          (CDisplayScenarioJournal *this,ulong *param_1,long *param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  if ((*(longlong *)(this + 0xd0) != 0) && (*(longlong *)(this + 0xb0) != 0)) {
    lVar5 = (longlong)param_1 - (longlong)param_2;
    lVar4 = 0x10;
    do {
      uVar1 = *(uint *)(lVar5 + (longlong)param_2);
      if ((uVar1 < *(uint *)(this + 0xa8)) &&
         (lVar3 = (ulonglong)uVar1 * 0xd8 + *(longlong *)(this + 0xb0),
         iVar2 = GetOrAssignDisplayStateIndex
                           (this,*(undefined8 *)(lVar3 + 0x10),*(undefined4 *)(lVar3 + 0x18)),
         -1 < iVar2)) {
        *(long *)((longlong)iVar2 * 0x4c + 0x48 + *(longlong *)(this + 0xd0)) = *param_2;
      }
      param_2 = param_2 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  return;
}



===== GetOrAssignDisplayStateIndex @ 140016d48 =====

/* private: int __cdecl CDisplayScenarioJournal::GetOrAssignDisplayStateIndex(struct _LUID,unsigned
   int) __ptr64 */

int __thiscall
CDisplayScenarioJournal::GetOrAssignDisplayStateIndex
          (CDisplayScenarioJournal *this,undefined8 param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = (int)((ulonglong)param_2 >> 0x20);
  lVar3 = *(longlong *)(this + 0xd0);
  uVar6 = 0;
  if (lVar3 != 0) {
    uVar1 = *(ushort *)(this + 200);
    uVar2 = *(ushort *)(this + 0xcc);
    if (uVar1 <= *(ushort *)(this + 0xcc)) {
      uVar2 = uVar1;
    }
    for (; uVar6 < uVar2; uVar6 = uVar6 + 1) {
      lVar4 = (ulonglong)uVar6 * 0x4c;
      if (((*(int *)(lVar4 + lVar3) == (int)param_2) && (*(int *)(lVar4 + 4 + lVar3) == iVar5)) &&
         (*(int *)(lVar4 + 8 + lVar3) == param_3)) {
        return uVar6;
      }
    }
    if (uVar6 < uVar1) {
      lVar4 = (ulonglong)uVar6 * 0x4c;
      *(int *)(lVar4 + lVar3) = (int)param_2;
      *(int *)(lVar4 + 4 + lVar3) = iVar5;
      *(int *)(lVar4 + 8 + lVar3) = param_3;
      *(short *)(this + 0xcc) = *(short *)(this + 0xcc) + 1;
      return uVar6;
    }
  }
  return -1;
}



===== VpInitialize @ 140016e00 =====

void VpInitialize(void)

{
                    /* 0x16e00  57  VpInitialize */
  WdInitialize();
  return;
}



===== WdInitialize @ 140016e20 =====

void WdInitialize(void)

{
  bool bVar1;
  undefined8 local_res8 [4];
  
                    /* 0x16e20  85  WdInitialize */
  LOCK();
  bVar1 = WdLogState == 0;
  if (bVar1) {
    WdLogState = 1;
  }
  UNLOCK();
  if (bVar1) {
    __security_init_cookie();
    McGenEventRegister_EtwRegister();
    WdpInitLogging();
    LOCK();
    WdLogState = 2;
    UNLOCK();
  }
  else {
    while (WdLogState != 2) {
      local_res8[0] = 0xfffffffffffe7960;
      KeDelayExecutionThread(0,0,local_res8);
    }
  }
  return;
}



===== WdpInitLogging @ 140016e90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl WdpInitLogging(void) */

void __cdecl WdpInitLogging(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint *puVar6;
  ushort uVar7;
  undefined1 auStack_128 [32];
  undefined8 local_108;
  uint local_f8;
  uint local_f4 [3];
  undefined8 local_e8;
  undefined4 local_e0;
  wchar_t *local_d8;
  uint *local_d0;
  undefined4 local_c8;
  uint *local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  wchar_t *local_a0;
  uint *local_98;
  undefined8 uStack_90;
  uint *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  short local_38;
  undefined6 uStack_36;
  wchar_t awStack_30 [12];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_128;
  puVar6 = &DAT_14000e098;
  uVar7 = 0;
  do {
    builtin_wcsncpy(awStack_30,L"velSizeLg2",0xb);
    local_d8 = &local_38;
    local_d0 = &local_f8;
    local_c0 = local_f4;
    sVar1 = uVar7 + 0x37;
    local_f4[0] = 0;
    local_f8 = 0;
    local_e8 = 0;
    local_e0 = 0x120;
    local_c8 = 0x4000004;
    local_b8 = 4;
    local_b0 = 0;
    local_a8 = 0;
    local_a0 = (wchar_t *)0x0;
    local_98 = (uint *)0x0;
    uStack_90 = 0;
    local_88 = (uint *)0x0;
    uStack_80 = 0;
    if (uVar7 < 10) {
      sVar1 = uVar7 + 0x30;
    }
    _local_38 = CONCAT62(0x65004c002d,sVar1);
    local_108 = 0;
    iVar2 = RtlQueryRegistryValuesEx
                      (0,
                       L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Watchdog\\Logging"
                       ,&local_e8,0);
    if (iVar2 < 0) {
      local_f8 = local_f4[0];
    }
    if (0xc < local_f8) {
      local_f8 = 0xc;
    }
    uVar3 = 1 << ((byte)local_f8 & 0x1f);
    uVar5 = *puVar6;
    if (*puVar6 < uVar3) {
      *puVar6 = uVar3;
      uVar5 = uVar3;
    }
    uVar4 = ExAllocatePool2(0x40,(ulonglong)uVar5 << 6,0x676f6457);
    *(undefined8 *)(puVar6 + -2) = uVar4;
    uVar7 = uVar7 + 1;
    puVar6 = puVar6 + 6;
  } while (uVar7 < 0xb);
  local_f4[1] = 0;
  local_f4[2] = 0;
  local_d8 = L"BreakOnAssertion";
  local_d0 = local_f4;
  local_f4[0] = 0;
  local_c0 = local_f4 + 1;
  local_f8 = 0;
  local_e8 = 0;
  local_a0 = L"BreakOnError";
  local_98 = &local_f8;
  local_e0 = 0x120;
  local_88 = local_f4 + 2;
  local_c8 = 0x4000004;
  local_b8 = 4;
  local_b0 = 0;
  local_a8 = 0x120;
  uStack_90 = CONCAT44(uStack_90._4_4_,0x4000004);
  uStack_80 = CONCAT44(uStack_80._4_4_,4);
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_108 = 0;
  local_50 = 0;
  uStack_48 = 0;
  RtlQueryRegistryValuesEx
            (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Watchdog\\Logging",
             &local_e8,0);
  DAT_14000e0b8 = local_f4[0] != 0;
  DAT_14000e0d0 = local_f8 != 0;
  return;
}



===== WdDbgReportRecreate @ 1400170f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_WD_DEBUG_REPORT *
WdDbgReportRecreate(longlong param_1,uint param_2,longlong param_3,longlong param_4,longlong param_5
                   ,longlong param_6,undefined1 param_7,_WD_DEBUG_REPORT *param_8,byte param_9)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
                    /* 0x170f0  69  WdDbgReportRecreate */
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    if (param_2 < 0x188) {
      if ((((param_2 != 0x187) && (param_2 != 0xea)) && (param_2 != 0x116)) &&
         ((param_2 != 0x117 && (param_2 != 0x141)))) {
        bVar3 = param_2 == 0x142;
        goto LAB_140017149;
      }
    }
    else if (((param_2 != 0x193) && (param_2 != 0x1a8)) &&
            ((param_2 != 0x1b0 && (param_2 != 0x1b8)))) {
      bVar3 = param_2 == 0x400000ad;
LAB_140017149:
      if (!bVar3) goto LAB_140017156;
    }
    param_8 = (_WD_DEBUG_REPORT *)
              WdpDbgReportRealloc(param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                                  (longlong *)param_8,param_9);
    if (param_8 == (_WD_DEBUG_REPORT *)0x0) goto LAB_140017156;
    iVar2 = *(int *)(param_8 + 0x288);
    if (iVar2 == 1) {
      iVar2 = WdpDbgCaptureTriageDump(param_8);
LAB_14001720b:
      if (-1 < iVar2) goto LAB_140017156;
    }
    else {
      if (iVar2 == 2) {
        iVar2 = WdpDbgCaptureKernelDump(param_8);
        goto LAB_14001720b;
      }
      if (iVar2 == 0) {
        WdLogSingleEntry0(3);
        _WdLogGlobalForLineNumber = 0x513;
      }
      else {
        WdLogSingleEntry1(2,(longlong)iVar2);
        _WdLogGlobalForLineNumber = 0x51d;
      }
    }
    WdpDbgReportFree((longlong)param_8);
  }
  param_8 = (_WD_DEBUG_REPORT *)0x0;
LAB_140017156:
  return param_8;
}



===== WdpDbgReportRealloc @ 140017254 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong *
WdpDbgReportRealloc(longlong param_1,uint param_2,longlong param_3,longlong param_4,longlong param_5
                   ,longlong param_6,undefined1 param_7,longlong *param_8,byte param_9)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  longlong *plVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  plVar4 = param_8;
  if (param_8 != (longlong *)0x0) {
    uVar2 = *(uint *)(param_8 + 1);
    uVar7 = 0x116;
    if ((((((uVar2 == 0x116) || (uVar2 == 0x117)) || (uVar2 == 0x141)) ||
         ((uVar2 == 0x142 || (uVar2 == 0x187)))) ||
        ((uVar2 == 0x193 || ((uVar2 == 0x1a8 || (uVar2 == 0x1b0)))))) || (uVar2 == 0x1b8)) {
      uVar6 = 0xfe0000;
    }
    else {
      uVar6 = 0;
    }
    if ((((((param_2 != 0x116) && (param_2 != 0x117)) && (param_2 != 0x141)) &&
         (((param_2 != 0x142 && (param_2 != 0x187)) &&
          ((param_2 != 0x193 && ((param_2 != 0x1a8 && (param_2 != 0x1b0)))))))) &&
        (param_2 != 0x1b8)) || (0xfdffff < uVar6)) goto LAB_140017389;
    WdLogSingleEntry3(1,(ulonglong)*(uint *)((longlong)param_8 + 0x34),(ulonglong)uVar2,
                      (ulonglong)param_2);
    _WdLogGlobalForLineNumber = 0x2e7;
    WdpDbgReportFree((longlong)plVar4);
  }
  uVar7 = 0x676f6457;
  plVar4 = (longlong *)ExAllocatePool2(0x40,0x2c0);
  if (plVar4 == (longlong *)0x0) {
    WdLogSingleEntry0(6);
    _WdLogGlobalForLineNumber = 0x2f8;
    return (longlong *)0x0;
  }
  LOCK();
  UNLOCK();
  iVar3 = DAT_14000ea88 + 1;
  DAT_14000ea88 = DAT_14000ea88 + 1;
  *(int *)((longlong)plVar4 + 0x34) = iVar3;
  WdpWerInitContext(plVar4 + 0x50,param_2);
LAB_140017389:
  *(uint *)(plVar4 + 0x51) = (param_9 & 1) + 1;
  *plVar4 = param_1;
  plVar4[4] = param_5;
  plVar4[5] = param_6;
  plVar4[2] = param_3;
  plVar4[3] = param_4;
  *(undefined1 *)(plVar4 + 6) = param_7;
  *(uint *)(plVar4 + 1) = param_2;
  *(byte *)(plVar4 + 0x57) = param_9;
  if (param_1 != 0) {
    WdpDbgGetDriverFileName(param_1,(ushort *)(plVar4 + 0xf),uVar7,(ushort *)(plVar4 + 7));
  }
  plVar1 = plVar4 + 0x50;
  if (*plVar1 != 0) {
    return plVar4;
  }
  param_8 = (longlong *)0x0;
  iVar3 = WdpWerCreateReport(plVar1);
  if (iVar3 < 0) {
    WdLogSingleEntry1(2,(longlong)iVar3);
    _WdLogGlobalForLineNumber = 0x32b;
  }
  else {
    uVar5 = WdpWerCreateDumpFile(plVar1,(longlong *)&param_8);
    if (-1 < (int)uVar5) {
      return plVar4;
    }
    WdLogSingleEntry1(2,(longlong)(int)uVar5);
    _WdLogGlobalForLineNumber = 0x337;
  }
  WdpDbgReportFree((longlong)plVar4);
  return (longlong *)0x0;
}



===== SMgrSetConsoleSessionInSwitch @ 140017474 =====

undefined8 SMgrSetConsoleSessionInSwitch(char param_1)

{
  if (param_1 == '\0') {
    InSwitchConsoleSessionId = 0xffffffff;
  }
  else {
    InSwitchConsoleSessionId = PsGetCurrentProcessSessionId();
  }
  LOCK();
  UNLOCK();
  return 0;
}



===== JournalFinalize @ 1400174a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CDisplayScenarioContext::JournalFinalize(void) __ptr64 */

void __thiscall CDisplayScenarioContext::JournalFinalize(CDisplayScenarioContext *this)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *puVar2;
  
  pCVar1 = this + 0xb8;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  if (*(int *)pCVar1 == 0) {
    if (*(CDisplayScenarioJournal **)(this + 0xa8) != (CDisplayScenarioJournal *)0x0) {
      CDisplayScenarioJournal::JournalSendReport(*(CDisplayScenarioJournal **)(this + 0xa8));
      puVar2 = *(undefined8 **)(this + 0xa8);
      if (puVar2 != (undefined8 *)0x0) {
        (**(code **)*puVar2)(puVar2,1);
      }
      *(undefined8 *)(this + 0xa8) = 0;
    }
    if (*(CDisplayRestoreVidPnJournal **)(this + 0xb0) != (CDisplayRestoreVidPnJournal *)0x0) {
      CDisplayRestoreVidPnJournal::JournalSendReport(*(CDisplayRestoreVidPnJournal **)(this + 0xb0))
      ;
      puVar2 = *(undefined8 **)(this + 0xb0);
      if (puVar2 != (undefined8 *)0x0) {
        (**(code **)*puVar2)(puVar2,1);
      }
      *(undefined8 *)(this + 0xb0) = 0;
    }
  }
  return;
}



===== JournalSendReport @ 140017530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl CDisplayScenarioJournal::JournalSendReport(void) __ptr64 */

void __thiscall CDisplayScenarioJournal::JournalSendReport(CDisplayScenarioJournal *this)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  _tlgProvider_t *p_Var4;
  uint uVar5;
  uint uVar6;
  _GUID *p_Var7;
  uint *puVar8;
  longlong lVar9;
  CDisplayScenarioJournal *pCVar10;
  undefined4 uVar11;
  undefined2 uVar12;
  undefined1 auStackY_228 [32];
  uint local_198;
  undefined2 local_194 [2];
  ushort local_190 [2];
  uint local_18c;
  uint local_188;
  uint local_184;
  uint local_180 [2];
  ushort local_178 [2];
  uint local_174;
  undefined8 local_170;
  uint local_168;
  CDisplayScenarioJournal *local_160;
  undefined4 local_158;
  _GUID *local_150;
  undefined4 local_148;
  undefined8 local_140;
  int local_138;
  CDisplayScenarioJournal *local_130;
  undefined4 local_128;
  undefined8 local_120;
  uint local_118;
  CDisplayScenarioJournal *local_110;
  undefined4 local_108;
  longlong local_100;
  undefined2 local_f8;
  undefined8 local_f0;
  uint local_e8;
  ushort *local_e0;
  undefined4 local_d8;
  longlong local_d0;
  uint local_c8;
  CDisplayScenarioJournal *local_c0;
  undefined4 local_b8;
  undefined8 local_a8 [4];
  undefined8 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  uint *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
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
  
  lVar1 = _DAT_fffff78000000014;
  local_28 = __security_cookie ^ (ulonglong)auStackY_228;
  lVar9 = *(longlong *)(this + 8);
  pCVar10 = this + 0x20;
  p_Var7 = (_GUID *)(lVar9 + 0x70);
  uVar6 = 0;
  gSDCSeqId = gSDCSeqId + 1;
  *(undefined4 *)pCVar10 = *(undefined4 *)(lVar9 + 0x88);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(lVar9 + 0x8c);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(lVar9 + 0xa0);
  *(undefined8 *)(this + 0x2c) = *(undefined8 *)(lVar9 + 0x94);
  *(undefined8 *)(this + 0x34) = *(undefined8 *)(*(longlong *)(this + 8) + 0x30);
  *(longlong *)(this + 0x44) = lVar1;
  if (*(longlong *)(this + 0xf8) != 0) {
    uVar6 = (uint)((ulonglong)(lVar1 - *(longlong *)(this + 0xf8)) / 10000);
  }
  uVar12 = 4;
  if (*(int *)(this + 100) == 0) {
    uVar3 = 1;
    do {
      if (g_ccdDbRetrievalCacheIndex < uVar3) break;
      uVar5 = g_ccdDbRetrievalCacheIndex - uVar3 & 3;
      if ((*(_GUID **)p_Var7 == (&g_ccdDbRetrievalCacheId)[(ulonglong)uVar5 * 2]) &&
         (*(longlong *)(lVar9 + 0x78) == *(longlong *)(&DAT_14000e828 + (ulonglong)uVar5 * 0x10))) {
        *(undefined4 *)(this + 100) =
             *(undefined4 *)((longlong)&g_ccdDbRetrievalCacheResult + (ulonglong)uVar5 * 4);
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 5);
  }
  local_178[0] = *(ushort *)(this + 0xb8);
  uVar3 = (uint)local_178[0];
  local_190[0] = *(ushort *)(this + 0xa8);
  uVar11 = 2;
  p_Var4 = (_tlgProvider_t *)(ulonglong)DAT_14000e048;
  if (5 < DAT_14000e048) {
    uVar2 = _tlgKeywordOn(p_Var4,0x400000000001);
    if ((char)uVar2 != '\0') {
      local_170 = *(undefined8 *)(this + 0xc0);
      local_160 = (CDisplayScenarioJournal *)local_178;
      local_198 = gSDCSeqId;
      local_168 = uVar3 * 0xd8;
      local_148 = 0x6c;
      local_194[0] = (undefined2)uVar11;
      local_180[0] = 0x3000800;
      local_180[1] = 0;
      local_158 = uVar11;
      local_150 = (_GUID *)pCVar10;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize>
                ((_tlgProvider_t *)(ulonglong)local_168,&DAT_14000c757,p_Var7,(_GUID *)pCVar10,
                 (_tlgWrapperByVal<8> *)local_180,(_tlgWrapperByVal<2> *)local_194,
                 (_tlgWrapperByVal<4> *)&local_198,(_tlgWrapperPtrSize *)&local_150,
                 (_tlgWrapperPtrSize *)&local_160,(_tlgWrapperPtrSize *)&local_170);
      p_Var4 = (_tlgProvider_t *)(ulonglong)DAT_14000e048;
      uVar11 = 2;
      uVar12 = 4;
    }
    if (5 < (uint)p_Var4) {
      uVar2 = _tlgKeywordOn(p_Var4,0x400000000001);
      if ((char)uVar2 != '\0') {
        local_18c = *(uint *)(this + 0xf0);
        local_130 = this + 0x10;
        local_160 = this + 0xdc;
        local_188 = *(uint *)(this + 0xd8);
        local_140 = *(undefined8 *)(this + 0x18);
        local_110 = this + 0xcc;
        local_138 = (uint)*(ushort *)local_130 * 0x3c;
        local_120 = *(undefined8 *)(this + 0xd0);
        local_118 = (uint)*(ushort *)local_110 * 0x4c;
        local_194[0] = CONCAT11(local_194[0]._1_1_,*(undefined1 *)(lVar9 + 0x9d));
        local_100 = lVar9 + 0x84;
        local_184 = *(uint *)(lVar9 + 0x80);
        local_180[0] = gSDCSeqId;
        local_198 = CONCAT22(local_198._2_2_,1);
        local_170 = 0x3000800;
        local_174 = uVar6;
        local_128 = uVar11;
        local_108 = uVar11;
        local_f8 = uVar12;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<1>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperByVal<4>,_tlgWrapperByRef<16>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
                  ((_tlgProvider_t *)(ulonglong)local_118,&DAT_14000c490,p_Var7,(_GUID *)pCVar10,
                   (_tlgWrapperByVal<8> *)&local_170,(_tlgWrapperByVal<2> *)&local_198,
                   (_tlgWrapperByVal<4> *)local_180,(_tlgWrapperByVal<4> *)&local_184,
                   (_tlgWrapperBinary *)&local_100,(_tlgWrapperByVal<1> *)local_194,
                   (_tlgWrapperPtrSize *)&local_110,(_tlgWrapperPtrSize *)&local_120,
                   (_tlgWrapperPtrSize *)&local_130,(_tlgWrapperPtrSize *)&local_140,
                   (_tlgWrapperByVal<4> *)&local_188,(_tlgWrapperByRef<16> *)&local_160,
                   (_tlgWrapperByVal<4> *)&local_18c,(_tlgWrapperByVal<4> *)&local_174);
        p_Var4 = (_tlgProvider_t *)(ulonglong)DAT_14000e048;
      }
      if ((5 < (uint)p_Var4) && (uVar2 = _tlgKeywordOn(p_Var4,0x400000000001), (char)uVar2 != '\0'))
      {
        local_f0 = *(undefined8 *)(this + 0xb0);
        local_e8 = (uint)local_190[0] * 0xd8;
        local_e0 = local_190;
        local_180[0] = gSDCSeqId;
        local_d8 = 2;
        local_198 = CONCAT22(local_198._2_2_,1);
        local_170 = 0x3000800;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize>
                  ((_tlgProvider_t *)(ulonglong)local_e8,&DAT_14000c146,p_Var7,(_GUID *)pCVar10,
                   (_tlgWrapperByVal<8> *)&local_170,(_tlgWrapperByVal<2> *)&local_198,
                   (_tlgWrapperByVal<4> *)local_180,(_tlgWrapperPtrSize *)&local_e0,
                   (_tlgWrapperPtrSize *)&local_f0);
        p_Var4 = (_tlgProvider_t *)(ulonglong)DAT_14000e048;
      }
    }
  }
  puVar8 = *(uint **)(this + 0x90);
  if (puVar8 != (uint *)0x0) {
    uVar6 = *puVar8;
    pCVar10 = (CDisplayScenarioJournal *)(ulonglong)uVar6;
    if (uVar6 == 0) {
      if (((uint)p_Var4 < 6) || (uVar2 = _tlgKeywordOn(p_Var4,0x400000000001), (char)uVar2 == '\0'))
      goto LAB_140017abd;
      local_180[0] = puVar8[4];
      local_184 = puVar8[3];
      local_188 = puVar8[2];
      local_174 = gSDCSeqId;
      local_18c = (uint)pCVar10;
      local_198 = CONCAT22(local_198._2_2_,2);
      local_170 = 0x3000800;
      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
      ::
      Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
                (p_Var4,&DAT_14000c0d6,p_Var7,(_GUID *)pCVar10,(_tlgWrapperByVal<8> *)&local_170,
                 (_tlgWrapperByVal<2> *)&local_198,(_tlgWrapperByVal<4> *)&local_174,
                 (_tlgWrapperByVal<4> *)&local_18c,(_tlgWrapperByVal<4> *)&local_188,
                 (_tlgWrapperByVal<4> *)&local_184,(_tlgWrapperByVal<4> *)local_180);
    }
    else {
      if (((uVar6 != 1) || ((uint)p_Var4 < 6)) ||
         (uVar2 = _tlgKeywordOn(p_Var4,0x400000000001), (char)uVar2 == '\0')) goto LAB_140017abd;
      local_2c = 0;
      local_3c = 0;
      local_4c = 0;
      local_5c = 0;
      local_6c = 0;
      local_7c = 0;
      local_180[0] = puVar8[3];
      local_184 = puVar8[2];
      local_18c = gSDCSeqId;
      local_38 = local_180;
      local_48 = &local_184;
      local_58 = &local_188;
      local_68 = &local_18c;
      local_78 = &local_198;
      local_88 = &local_170;
      local_30 = 4;
      local_40 = 4;
      local_50 = 4;
      local_60 = 4;
      local_188 = (uint)pCVar10;
      pCVar10 = (CDisplayScenarioJournal *)0x0;
      local_80 = 8;
      local_198 = CONCAT22(local_198._2_2_,1);
      local_170 = 0x3000800;
      local_70 = 2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14000e048,&DAT_14000c070,p_Var7,0,8,local_a8);
    }
    p_Var4 = (_tlgProvider_t *)(ulonglong)DAT_14000e048;
  }
LAB_140017abd:
  lVar9 = *(longlong *)(this + 0xa0);
  if (((lVar9 != 0) && (5 < (uint)p_Var4)) &&
     (uVar2 = _tlgKeywordOn(p_Var4,0x400000000001), (char)uVar2 != '\0')) {
    local_c0 = this + 0x98;
    local_c8 = (uint)*(ushort *)local_c0 * 200;
    local_180[0] = gSDCSeqId;
    local_b8 = 2;
    local_198 = CONCAT22(local_198._2_2_,1);
    local_170 = 0x3000800;
    local_d0 = lVar9;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize>
              ((_tlgProvider_t *)(ulonglong)local_c8,&DAT_14000bd3c,p_Var7,(_GUID *)pCVar10,
               (_tlgWrapperByVal<8> *)&local_170,(_tlgWrapperByVal<2> *)&local_198,
               (_tlgWrapperByVal<4> *)local_180,(_tlgWrapperPtrSize *)&local_c0,
               (_tlgWrapperPtrSize *)&local_d0);
  }
  return;
}



===== JournalSendReport @ 140017b84 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl CDisplayRestoreVidPnJournal::JournalSendReport(void) __ptr64 */

void __thiscall CDisplayRestoreVidPnJournal::JournalSendReport(CDisplayRestoreVidPnJournal *this)

{
  undefined8 uVar1;
  uint uVar2;
  _GUID *p_Var3;
  CDisplayRestoreVidPnJournal *pCVar4;
  undefined2 local_res8 [4];
  uint local_res10 [2];
  undefined4 local_res18 [2];
  undefined8 local_res20;
  undefined8 local_68;
  int local_60;
  CDisplayRestoreVidPnJournal *local_58;
  undefined4 local_50;
  undefined8 local_48;
  int local_40;
  CDisplayRestoreVidPnJournal *local_38;
  undefined4 local_30;
  CDisplayRestoreVidPnJournal *local_28;
  undefined4 local_20;
  _GUID *local_18;
  undefined2 local_10;
  
  p_Var3 = *(_GUID **)(this + 8);
  pCVar4 = this + 0x50;
  uVar2 = 0;
  while( true ) {
    if (*(ushort *)pCVar4 <= uVar2) {
      gSDCSeqId = gSDCSeqId + 1;
      *(undefined4 *)(this + 0x2c) = *(undefined4 *)(p_Var3 + 0xa0);
      uVar1 = *(undefined8 *)(*(longlong *)(this + 8) + 0x30);
      *(undefined8 *)(this + 0x38) = uVar1;
      *(undefined8 *)(this + 0x40) = _DAT_fffff78000000014;
      if ((5 < DAT_14000e048) && (uVar1 = _tlgKeywordOn(uVar1,0x400000000002), (char)uVar1 != '\0'))
      {
        local_68 = *(undefined8 *)(this + 0x18);
        local_58 = this + 0x10;
        local_60 = (uint)*(ushort *)local_58 * 0x3c;
        local_48 = *(undefined8 *)(this + 0x58);
        local_40 = (uint)*(ushort *)pCVar4 << 4;
        local_28 = this + 0x20;
        local_res10[0] = gSDCSeqId;
        local_50 = 2;
        local_30 = 2;
        local_res8[0] = 8;
        local_18 = p_Var3 + 0x84;
        local_10 = 4;
        local_res18[0] = *(undefined4 *)(p_Var3 + 0x80);
        local_20 = 0x2c;
        local_res20 = 0x3000800;
        local_38 = pCVar4;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperBinary,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize,_tlgWrapperPtrSize>
                  ((_tlgProvider_t *)0x2,&DAT_14000bb5d,p_Var3 + 0x70,p_Var3,
                   (_tlgWrapperByVal<8> *)&local_res20,(_tlgWrapperByVal<4> *)local_res18,
                   (_tlgWrapperBinary *)&local_18,(_tlgWrapperByVal<2> *)local_res8,
                   (_tlgWrapperByVal<4> *)local_res10,(_tlgWrapperPtrSize *)&local_28,
                   (_tlgWrapperPtrSize *)&local_38,(_tlgWrapperPtrSize *)&local_48,
                   (_tlgWrapperPtrSize *)&local_58,(_tlgWrapperPtrSize *)&local_68);
      }
      return;
    }
    if (*(int *)(*(longlong *)(this + 0x58) + 0xc + (ulonglong)uVar2 * 0x10) < 0) break;
    uVar2 = uVar2 + 1;
  }
  return;
}



===== TrimLowPriorityPaths @ 140017d0c =====

void TrimLowPriorityPaths(uint param_1,longlong param_2,uint *param_3,longlong param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  int *piVar6;
  
  if (param_3 != (uint *)0x0) {
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = 0;
    if (param_1 != 0) {
      piVar6 = (int *)(param_2 + 0x1c);
      do {
        uVar4 = (uint)uVar5;
        if ((*(ulonglong *)(piVar6 + -7) >> 0x38 & 1) != 0) {
          for (uVar1 = 0; (uint)uVar1 < uVar3; uVar1 = (ulonglong)((uint)uVar1 + 1)) {
            lVar2 = uVar1 * 0x128;
            if (((*piVar6 == *(int *)(lVar2 + 0x1c + param_2)) &&
                (piVar6[-3] == *(int *)(lVar2 + 0x10 + param_2))) &&
               (piVar6[-2] == *(int *)(lVar2 + 0x14 + param_2))) goto LAB_140017daf;
          }
          if ((param_4 != 0) && (uVar4 < *param_3)) {
            CopyDisplayScenarioPathModalityDescriptor
                      ((ulonglong)uVar3 * 0x128 + param_2,1,uVar5 * 0xd8 + param_4);
          }
          uVar5 = (ulonglong)(uVar4 + 1);
        }
LAB_140017daf:
        uVar4 = (uint)uVar5;
        uVar3 = uVar3 + 1;
        piVar6 = piVar6 + 0x4a;
      } while (uVar3 < param_1);
    }
    if (param_4 == 0) {
      *param_3 = uVar4;
    }
  }
  return;
}



===== CopyDisplayScenarioSetTimingPathInfo @ 140017de8 =====

void CopyDisplayScenarioSetTimingPathInfo
               (undefined8 param_1,undefined4 param_2,longlong param_3,uint param_4,longlong param_5
               )

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  
  if (param_4 != 0) {
    uVar3 = (ulonglong)param_4;
    puVar1 = (undefined4 *)(param_5 + 8);
    puVar2 = (undefined4 *)(param_3 + 8);
    do {
      *(undefined8 *)(puVar1 + -2) = param_1;
      puVar1[0xc] = param_2;
      *puVar1 = puVar2[-2];
      puVar1[1] = puVar2[-1];
      puVar1[2] = *puVar2;
      puVar1[3] = puVar2[1];
      *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(puVar2 + 4);
      puVar1[6] = puVar2[6] & 0xffffff;
      puVar1[7] = *(byte *)((longlong)puVar2 + 0x1b) & 0xf;
      puVar1[8] = puVar2[7];
      puVar1[9] = puVar2[8];
      puVar1[10] = puVar2[2];
      puVar1[0xb] = puVar2[10];
      uVar3 = uVar3 - 1;
      puVar1 = puVar1 + 0xf;
      puVar2 = puVar2 + 0xe;
    } while (uVar3 != 0);
  }
  return;
}



===== WdDbgReportQueryInfo @ 140017e80 =====

ulonglong WdDbgReportQueryInfo(longlong param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
                    /* 0x17e80  68  WdDbgReportQueryInfo */
  uVar2 = KeGetCurrentIrql();
  if (((((char)uVar2 == '\0') && (param_1 != 0)) && (param_2 != (uint *)0x0)) && (0xb < *param_2)) {
    *param_2 = 0xc;
    param_2[1] = *(uint *)(param_1 + 8);
    uVar1 = *(uint *)(param_1 + 0x34);
    param_2[2] = uVar1;
    uVar2 = CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
  }
  else {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== JournalSetResult @ 140017edc =====

/* public: void __cdecl CDisplayRestoreVidPnJournal::JournalSetResult(struct _LUID,unsigned int,enum
   _RESTORE_VIDPN_STAGE,long) __ptr64 */

void __thiscall
CDisplayRestoreVidPnJournal::JournalSetResult
          (CDisplayRestoreVidPnJournal *this,undefined8 param_2,__uint64 param_3,undefined4 param_4,
          int param_5)

{
  undefined1 auVar1 [16];
  __uint64 _Var2;
  void *_Dst;
  CDisplayRestoreVidPnJournal *pCVar3;
  uint uVar4;
  
  if (param_5 < 0) {
    *(int *)(this + 0x20) = (int)param_3;
    *(undefined8 *)(this + 0x30) = param_2;
    *(int *)(this + 0x24) = param_5;
    *(undefined4 *)(this + 0x28) = param_4;
  }
  uVar4 = *(uint *)(this + 0x4c);
  if (uVar4 <= *(ushort *)(this + 0x50)) {
    if (uVar4 == 0) {
      uVar4 = 8;
    }
    else {
      uVar4 = uVar4 * 2;
      if (0x20 < uVar4) {
        return;
      }
    }
    auVar1 = ZEXT816(0x10) * ZEXT416(uVar4);
    _Var2 = auVar1._0_8_;
    if (auVar1._8_8_ != 0) {
      _Var2 = 0xffffffffffffffff;
    }
    _Dst = operator_new(_Var2,auVar1._8_4_,param_3);
    if (_Dst == (void *)0x0) {
      return;
    }
    if (*(void **)(this + 0x58) != (void *)0x0) {
      memcpy(_Dst,*(void **)(this + 0x58),(ulonglong)*(uint *)(this + 0x4c) << 4);
      operator_delete__(*(void **)(this + 0x58));
    }
    *(uint *)(this + 0x4c) = uVar4;
    *(void **)(this + 0x58) = _Dst;
  }
  pCVar3 = this + 0x50;
  *(undefined8 *)(*(longlong *)(this + 0x58) + (ulonglong)*(ushort *)(this + 0x50) * 0x10) = param_2
  ;
  *(int *)(*(longlong *)(this + 0x58) + 8 + (ulonglong)*(ushort *)pCVar3 * 0x10) = (int)param_3;
  *(int *)(*(longlong *)(this + 0x58) + 0xc + (ulonglong)*(ushort *)pCVar3 * 0x10) = param_5;
  *(ushort *)pCVar3 = *(ushort *)pCVar3 + 1;
  return;
}



===== SMgrSessionOpen @ 140017ff0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SMgrSessionOpen(longlong param_1)

{
  longlong *plVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  _LIST_ENTRY *p_Var6;
  undefined1 *puVar7;
  undefined8 uVar8;
  longlong *plVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar8 = 0;
  iVar3 = PsGetCurrentProcessSessionId();
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&SessionDataListLock,0);
  puVar7 = auStack_28;
  plVar5 = _CsrProcessList;
  do {
    plVar9 = (longlong *)0x0;
    if ((longlong *)*plVar5 == _CsrProcessList) {
LAB_14001809a:
      plVar5 = (longlong *)ExAllocatePool2(0x100,0x40,0x676f6457);
      if (plVar5 == (longlong *)0x0) {
        uVar8 = 0xc000009a;
        puVar7 = auStack_28;
      }
      else {
        plVar5[4] = 0;
        plVar5[3] = 0;
        *(undefined4 *)(plVar5 + 2) = 1;
        lVar4 = PsGetCurrentProcess();
        plVar5[6] = param_1;
        p_Var6 = &CsrProcessList;
        plVar5[5] = lVar4;
        *(int *)(plVar5 + 7) = iVar3;
        *(undefined1 *)((longlong)plVar5 + 0x3c) = 0;
        if ((_LIST_ENTRY *)_CsrProcessList[1] != &CsrProcessList) {
LAB_140018105:
          p_Var6 = (_LIST_ENTRY *)0x3;
          pcVar2 = (code *)swi(0x29);
          _CsrProcessList = (longlong *)(*pcVar2)();
          puVar7 = auStack_20;
        }
        *plVar5 = (longlong)_CsrProcessList;
        plVar5[1] = (longlong)p_Var6;
        _CsrProcessList[1] = (longlong)plVar5;
        LOCK();
        CsrProcessCount = CsrProcessCount + 1;
        UNLOCK();
        _CsrProcessList = plVar5;
      }
      *(undefined8 *)(puVar7 + -8) = 0x140018135;
      ExReleasePushLockExclusiveEx(&SessionDataListLock,0);
      *(undefined8 *)(puVar7 + -8) = 0x140018141;
      KeLeaveCriticalRegion();
      if (plVar9 != (longlong *)0x0) {
        *(undefined8 *)(puVar7 + -8) = 0x140018152;
        KeEnterCriticalRegion();
        *(undefined8 *)(puVar7 + -8) = 0x140018164;
        ExAcquirePushLockExclusiveEx(plVar9 + 4,0);
        plVar9[3] = 0;
        *(undefined1 *)((longlong)plVar9 + 0x3c) = 1;
        *(undefined8 *)(puVar7 + -8) = 0x14001817f;
        ExReleasePushLockExclusiveEx(plVar9 + 4,0);
        *(undefined8 *)(puVar7 + -8) = 0x14001818b;
        KeLeaveCriticalRegion();
        *(undefined8 *)(puVar7 + -8) = 0x140018198;
        SMgrReleaseCsrProcessData((longlong)plVar9);
      }
      return uVar8;
    }
    if ((int)plVar5[7] == iVar3) {
      lVar4 = PsGetCurrentProcess();
      if (plVar5[5] != lVar4) {
        lVar4 = *plVar5;
        uVar8 = 0x40000000;
        plVar9 = plVar5;
        if ((*(longlong **)(lVar4 + 8) != plVar5) ||
           (plVar1 = (longlong *)plVar5[1], (longlong *)*plVar1 != plVar5)) goto LAB_140018105;
        *plVar1 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar1;
        LOCK();
        CsrProcessCount = CsrProcessCount - 1;
        UNLOCK();
        goto LAB_14001809a;
      }
    }
    plVar5 = (longlong *)*plVar5;
  } while( true );
}



===== DisplayRestoreVidPnJournalFinalize @ 1400181c0 =====

void DisplayRestoreVidPnJournalFinalize(_GUID *param_1,_WD_MUTEX *param_2)

{
  CDisplayScenarioContext *this;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x181c0  31  DisplayRestoreVidPnJournalFinalize */
  if (param_1 != (_GUID *)0x0) {
    AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
    this = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromActivityId(param_1);
    if (this != (CDisplayScenarioContext *)0x0) {
      CDisplayScenarioContext::JournalFinalize(this);
    }
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== WdDbgReportSecondaryData @ 140018230 =====

bool WdDbgReportSecondaryData(longlong param_1,undefined8 *param_2,uint param_3)

{
  uint uVar1;
  char cVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 *puVar5;
  
                    /* 0x18230  70  WdDbgReportSecondaryData */
  cVar2 = KeGetCurrentIrql();
  if ((((cVar2 != '\0') || (param_1 == 0)) || (param_2 == (undefined8 *)0x0)) || (param_3 == 0)) {
    return false;
  }
  uVar1 = *(uint *)(param_1 + 8);
  if (((((uVar1 == 0x116) || (uVar1 == 0x117)) ||
       ((uVar1 == 0x141 || ((uVar1 == 0x142 || (uVar1 == 0x187)))))) || (uVar1 == 0x193)) ||
     (((uVar1 == 0x1a8 || (uVar1 == 0x1b0)) || (uVar4 = 0x7ffd0, uVar1 == 0x1b8)))) {
    uVar4 = 0x105ffd0;
  }
  if (uVar4 < param_3) {
    return false;
  }
  if (uVar1 < 0x188) {
    if (uVar1 != 0x187) {
      if (uVar1 == 0xea) {
LAB_1400182ff:
        puVar5 = (undefined4 *)&WdDbgReportSecondaryDataGUID;
        goto LAB_140018318;
      }
      if (((uVar1 != 0x116) && (uVar1 != 0x117)) && ((uVar1 != 0x141 && (uVar1 != 0x142)))) {
        return false;
      }
    }
  }
  else if (uVar1 != 0x193) {
    if (uVar1 == 0x1a8) {
      puVar5 = (undefined4 *)&WdDxgkBlackScreenBlobGUID;
      goto LAB_140018318;
    }
    if ((uVar1 != 0x1b0) && (uVar1 != 0x1b8)) {
      if (uVar1 != 0x400000ad) {
        return false;
      }
      goto LAB_1400182ff;
    }
  }
  puVar5 = (undefined4 *)&WdDxgkSecondaryDataGUID;
LAB_140018318:
  lVar3 = WdpAppendSecondaryDumpData(param_1,puVar5,param_2,param_3);
  return lVar3 != 0;
}



===== DisplayScenarioJournalSetSpecializedData @ 140018340 =====

void DisplayScenarioJournalSetSpecializedData
               (_DISPLAY_SCENARIO_SPECIALIZED_DATA_HEADER *param_1,_WD_MUTEX *param_2)

{
  CDisplayScenarioContext *pCVar1;
  undefined8 *local_18;
  char local_10;
  
                    /* 0x18340  47  DisplayScenarioJournalSetSpecializedData */
  if ((param_1 != (_DISPLAY_SCENARIO_SPECIALIZED_DATA_HEADER *)0x0) && (*(int *)(param_1 + 4) != 0))
  {
    AutoMutex::AutoMutex((AutoMutex *)&local_18,param_2);
    pCVar1 = CDisplayContextBase<CDisplayScenarioContext>::FindContextFromCurrrentThread();
    if ((pCVar1 != (CDisplayScenarioContext *)0x0) &&
       (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8) != (CDisplayScenarioJournal *)0x0)) {
      CDisplayScenarioJournal::SetSpecializedData
                (*(CDisplayScenarioJournal **)(pCVar1 + 0xa8),param_1);
    }
    if (local_10 != '\0') {
      *local_18 = 0;
      ExReleasePushLockExclusiveEx(local_18 + 1,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== DMgrInitialize @ 1400183b8 =====

/* WARNING: Removing unreachable block (ram,0x00014001840f) */
/* WARNING: Removing unreachable block (ram,0x000140018440) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DMgrInitialize(void)

{
  longlong lVar1;
  ulong **ppuVar2;
  bool bVar3;
  
  if (IsDMgrInitialized == '\0') {
    do {
      LOCK();
      bVar3 = CodeCriticalSectionLock == (void *)0x0;
      if (bVar3) {
        CodeCriticalSectionLock = SystemReserved1[0xf];
      }
      UNLOCK();
    } while (!bVar3);
    _DAT_14000e688 = 0;
    _GdiViewIdDataMutex = 0;
    ppuVar2 = &UsedGdiViewList;
    for (lVar1 = 0x80; lVar1 != 0; lVar1 = lVar1 + -1) {
      *ppuVar2 = (ulong *)0xffffffffffffffff;
      ppuVar2 = ppuVar2 + 1;
    }
    IsDMgrInitialized = '\x01';
    LOCK();
    CodeCriticalSectionLock = (void *)0x0;
    UNLOCK();
  }
  return 0;
}



===== SetDPIInfo @ 140018470 =====

/* public: void __cdecl CDisplayScenarioJournal::SetDPIInfo(struct _LUID const * __ptr64,unsigned
   int,struct _DPI_INFORMATION * __ptr64,unsigned int) __ptr64 */

void __thiscall
CDisplayScenarioJournal::SetDPIInfo
          (CDisplayScenarioJournal *this,_LUID *param_1,uint param_2,_DPI_INFORMATION *param_3,
          uint param_4)

{
  int iVar1;
  longlong lVar2;
  
  if (*(longlong *)(this + 0xd0) != 0) {
    iVar1 = GetOrAssignDisplayStateIndex(this,*(undefined8 *)param_1);
    if (-1 < iVar1) {
      lVar2 = (longlong)iVar1 * 0x4c + *(longlong *)(this + 0xd0);
      *(uint *)(lVar2 + 0x44) = param_4;
      *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_3 + 8);
      *(undefined4 *)(lVar2 + 0x20) = *(undefined4 *)(param_3 + 0x40);
      *(undefined4 *)(lVar2 + 0x24) = *(undefined4 *)(param_3 + 0x50);
      *(undefined4 *)(lVar2 + 0x28) = *(undefined4 *)(param_3 + 0x58);
      *(undefined4 *)(lVar2 + 0x2c) = *(undefined4 *)(param_3 + 0x54);
      *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_3 + 0x5c);
      *(undefined4 *)(lVar2 + 0x30) = *(undefined4 *)(param_3 + 0x38);
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_3 + 0x3c);
      *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(param_3 + 0x28);
      *(undefined4 *)(lVar2 + 0x40) = *(undefined4 *)(param_3 + 0x2c);
    }
  }
  return;
}



===== WdDiagInit @ 140018500 =====

undefined4 WdDiagInit(longlong *param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  bool bVar4;
  
                    /* 0x18500  74  WdDiagInit */
  uVar2 = 0;
  if (param_1 != (longlong *)0x0) {
    if (*param_1 != 0) {
      lVar3 = RtlCompareMemory(*param_1,&WdDiagEtwControlGuid,0x10);
      if (lVar3 != 0x10) goto LAB_140018561;
    }
    if (param_1[1] != 0) {
      lVar3 = RtlCompareMemory(param_1[1],&DAT_14000e1a8,0x10);
      if (lVar3 != 0x10) {
LAB_140018561:
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc0000025);
      }
    }
  }
  LOCK();
  iVar1 = DAT_14000ea8c + 1;
  UNLOCK();
  bVar4 = DAT_14000ea8c == 0;
  DAT_14000ea8c = iVar1;
  if (bVar4) {
    uVar2 = EtwRegister(&WdDiagEtwControlGuid,0,0,&DAT_14000ea90);
  }
  return uVar2;
}



===== WdpDbgGetDriverFileName @ 1400185bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WdpDbgGetDriverFileName(longlong param_1,ushort *param_2,undefined8 param_3,ushort *param_4)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ushort *puVar5;
  int iVar6;
  __uint64 _Var7;
  uint uVar8;
  uint uVar9;
  size_t _Size;
  longlong lVar10;
  undefined1 auStack_188 [32];
  undefined8 local_168;
  undefined8 local_158;
  short *local_150;
  undefined8 local_148;
  undefined4 local_140;
  wchar_t *local_138;
  undefined8 *local_130;
  undefined4 local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  wchar_t local_d8 [16];
  ushort local_b8 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_188;
  if (param_1 == 0) {
    iVar6 = -0x3ffffff3;
  }
  else {
    if (param_2 != (ushort *)0x0) {
      memset(param_2,0,0x208);
    }
    if (param_4 != (ushort *)0x0) {
      memset(param_4,0,0x40);
    }
    lVar10 = *(longlong *)(param_1 + 8);
    memset(local_b8,0,0x80);
    uVar1 = *(ushort *)(lVar10 + 0x38);
    if ((uVar1 != 0) && (lVar10 = *(longlong *)(lVar10 + 0x40), lVar10 != 0)) {
      uVar2 = uVar1 >> 1;
      iVar6 = uVar2 - 1;
      if (-1 < iVar6) {
        lVar3 = (ulonglong)(uint)uVar2 - 1;
        do {
          if (*(short *)(lVar10 + lVar3 * 2) == 0x5c) break;
          iVar6 = iVar6 + -1;
          lVar3 = lVar3 + -1;
        } while (-1 < lVar3);
      }
      iVar6 = iVar6 + 1;
      if (iVar6 < (int)(uint)uVar2) {
        uVar4 = (ulonglong)uVar1 + (longlong)iVar6 * -2;
        _Size = 0x7e;
        if (uVar4 < 0x7e) {
          _Size = uVar4;
        }
        memcpy(local_b8,(void *)((longlong)iVar6 * 2 + lVar10),_Size);
      }
    }
    if (param_4 != (ushort *)0x0) {
      RtlStringCbCopyW(param_4,0x40,local_b8);
    }
    if (param_2 != (ushort *)0x0) {
      local_158 = 0;
      local_150 = (short *)0x0;
      local_148 = 0;
      local_138 = L"ImagePath";
      local_130 = &local_158;
      local_140 = 0x124;
      local_128 = 0x2000000;
      local_120 = 0;
      local_118 = 0;
      local_110 = 0;
      local_108 = 0;
      local_100 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      local_168 = 0;
      local_e8 = 0;
      uStack_e0 = 0;
      iVar6 = RtlQueryRegistryValuesEx(1,local_b8,&local_148);
      if (iVar6 < 0) {
        if (local_150 == (short *)0x0) {
          return iVar6;
        }
        ExFreePoolWithTag(local_150,0);
        return iVar6;
      }
      if (local_150 != (short *)0x0) {
        if (((ushort)local_158 != 0) && (*local_150 != 0)) {
          uVar8 = 0;
          uVar9 = 0;
          builtin_wcsncpy(local_d8,L"SystemRoot\\",0xc);
          for (; (ulonglong)uVar9 + 0xc < (ulonglong)((ushort)local_158 >> 1); uVar9 = uVar9 + 1) {
            iVar6 = _wcsnicmp(local_150 + uVar9,local_d8,0xb);
            if (iVar6 == 0) {
              uVar8 = uVar9 + 0xb;
              break;
            }
          }
          if (local_150[uVar8] != 0) {
            puVar5 = (ushort *)RtlGetNtSystemRoot();
            RtlStringCbCopyW(param_2,0x208,puVar5);
            _Var7 = 0x104;
            lVar10 = 0x104;
            puVar5 = param_2;
            do {
              if (*puVar5 == 0) break;
              puVar5 = puVar5 + 1;
              lVar10 = lVar10 + -1;
            } while (lVar10 != 0);
            uVar4 = -(ulonglong)(lVar10 != 0) & 0x104U - lVar10;
            if (lVar10 != 0) {
              _Var7 = 0x104 - uVar4;
              RtlStringCopyWorkerW((short *)(param_2 + uVar4),_Var7,lVar10,0x14000b4ec);
            }
            RtlStringCbCatW(param_2,_Var7,(ushort *)(local_150 + uVar8));
          }
        }
        ExFreePoolWithTag(local_150,0);
      }
    }
    iVar6 = 0;
  }
  return iVar6;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14001888c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
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
  local_28 = *(undefined4 *)(PTR_DAT_14000e050 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14000e050 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14000e050 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14000e050 + -4);
  if (DAT_14000e068 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_14000e070 = 0;
  uRam000000014000e078 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1400188ef;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_14000e048,&DAT_14000e068);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000e050;
    *(undefined8 *)(puVar4 + -8) = 0x140018916;
    EtwSetInformation(DAT_14000e068,2,PTR_DAT_14000e050,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14001892a;
  return iVar3;
}



===== DMgrIsSetupRunning @ 140018940 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool DMgrIsSetupRunning(void)

{
  bool bVar1;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  undefined4 local_108;
  int local_104;
  int local_100;
  int local_fc;
  undefined8 local_f8;
  undefined4 local_f0;
  wchar_t *local_e8;
  int *local_e0;
  undefined4 local_d8;
  undefined4 *local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  wchar_t *local_b0;
  int *local_a8;
  undefined4 local_a0;
  undefined4 *local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  wchar_t *local_78;
  int *local_70;
  undefined4 local_68;
  undefined4 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x18940  26  DMgrIsSetupRunning */
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_e8 = L"SystemSetupInProgress";
  local_f0 = 0x120;
  local_d8 = 0x4000004;
  local_b8 = 0x120;
  local_e0 = &local_100;
  local_c8 = 4;
  local_d0 = &local_108;
  local_a0 = 0x4000004;
  local_b0 = L"UpgradeInProgress";
  local_a8 = &local_104;
  local_98 = &local_108;
  local_78 = L"MiniSetupInProgress";
  local_70 = &local_fc;
  local_60 = &local_108;
  local_90 = 4;
  local_80 = 0x120;
  local_68 = 0x4000004;
  local_58 = 4;
  local_108 = 0;
  local_104 = 0;
  local_100 = 0;
  local_fc = 0;
  local_f8 = 0;
  local_c0 = 0;
  local_88 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_118 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlQueryRegistryValuesEx(0,L"\\Registry\\Machine\\System\\Setup",&local_f8,0);
  if (local_104 == 0) {
    if (local_100 == 0) {
      bVar1 = false;
    }
    else {
      bVar1 = local_fc == 0;
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}



===== WdpWerCreateReport @ 140018a80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WdpWerCreateReport(undefined8 *param_1)

{
  int iVar1;
  
  iVar1 = WerLiveKernelCreateReport((longlong)param_1 + 0xc,param_1 + 1,param_1);
  if (iVar1 < 0) {
    WdLogSingleEntry1(2,(longlong)iVar1);
    *param_1 = 0;
    _WdLogGlobalForLineNumber = 0x93;
  }
  return iVar1;
}



===== DMgrWriteDeviceCountToRegistry @ 140018ae0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DMgrWriteDeviceCountToRegistry(void)

{
  int iVar1;
  int local_res8 [8];
  
                    /* 0x18ae0  28  DMgrWriteDeviceCountToRegistry */
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_14000e688,0);
  _GdiViewIdDataMutex = SystemReserved1[0xf];
  local_res8[0] = NextGdiViewId - 1;
  iVar1 = RtlWriteRegistryValue(4,L"VIDEO",L"MaxObjectNumber",4,local_res8,4);
  if (-1 < iVar1) {
    iVar1 = RtlWriteRegistryValue
                      (4,L"VIDEO",L"ObjectNumberList",3,&UsedGdiViewList,NumUsedGdiViews << 2);
  }
  _GdiViewIdDataMutex = (void *)0x0;
  ExReleasePushLockExclusiveEx(&DAT_14000e688,0);
  KeLeaveCriticalRegion();
  return iVar1;
}



===== CopyDisplayScenarioPathInfo @ 140018bd8 =====

void CopyDisplayScenarioPathInfo(longlong param_1,uint param_2,longlong param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  if (param_2 != 0) {
    uVar4 = (ulonglong)param_2;
    puVar2 = (undefined8 *)(param_1 + 0x10);
    puVar3 = (undefined8 *)(param_3 + 0x10);
    do {
      puVar3[-2] = puVar2[-2];
      puVar3[-1] = puVar2[-1];
      *puVar3 = *puVar2;
      *(undefined4 *)(puVar3 + 1) = *(undefined4 *)(puVar2 + 1);
      *(undefined4 *)((longlong)puVar3 + 0xc) = *(undefined4 *)((longlong)puVar2 + 0xc);
      *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(puVar2 + 7);
      *(undefined8 *)((longlong)puVar3 + 0x14) = puVar2[6];
      *(undefined8 *)((longlong)puVar3 + 0x1c) = puVar2[5];
      *(undefined8 *)((longlong)puVar3 + 0x24) = puVar2[4];
      *(undefined8 *)((longlong)puVar3 + 0x2c) = *(undefined8 *)((longlong)puVar2 + 0xb4);
      *(undefined8 *)((longlong)puVar3 + 0x34) = *(undefined8 *)((longlong)puVar2 + 0xbc);
      *(undefined4 *)((longlong)puVar3 + 0x44) = *(undefined4 *)(puVar2 + 2);
      *(undefined4 *)(puVar3 + 9) = *(undefined4 *)((longlong)puVar2 + 0xc4);
      *(undefined4 *)((longlong)puVar3 + 0x4c) = *(undefined4 *)((longlong)puVar2 + 0x3c);
      *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(puVar2 + 8);
      *(undefined4 *)((longlong)puVar3 + 0x54) = *(undefined4 *)((longlong)puVar2 + 0x44);
      *(undefined4 *)(puVar3 + 0xb) = *(undefined4 *)(puVar2 + 9);
      *(undefined4 *)((longlong)puVar3 + 0x5c) = *(undefined4 *)((longlong)puVar2 + 0x4c);
      *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(puVar2 + 10);
      *(uint *)((longlong)puVar3 + 100) = (uint)*(byte *)((longlong)puVar2 + 0x54);
      *(uint *)(puVar3 + 0xd) = (uint)*(byte *)((longlong)puVar2 + 0x55);
      *(undefined4 *)((longlong)puVar3 + 0x6c) = *(undefined4 *)(puVar2 + 0xb);
      *(undefined4 *)(puVar3 + 0xe) = *(undefined4 *)((longlong)puVar2 + 0x5c);
      *(undefined4 *)((longlong)puVar3 + 0x74) = *(undefined4 *)(puVar2 + 0xc);
      puVar3[0xf] = *(undefined8 *)((longlong)puVar2 + 100);
      puVar3[0x10] = *(undefined8 *)((longlong)puVar2 + 0x6c);
      uVar1 = *(undefined8 *)((longlong)puVar2 + 0x84);
      puVar3[0x11] = *(undefined8 *)((longlong)puVar2 + 0x7c);
      puVar3[0x12] = uVar1;
      *(undefined4 *)(puVar3 + 0x13) = *(undefined4 *)((longlong)puVar2 + 0x8c);
      *(undefined4 *)((longlong)puVar3 + 0x9c) = *(undefined4 *)(puVar2 + 0x12);
      *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)((longlong)puVar2 + 0x94);
      *(undefined4 *)((longlong)puVar3 + 0xa4) = *(undefined4 *)(puVar2 + 0x14);
      *(undefined4 *)(puVar3 + 0x15) = *(undefined4 *)((longlong)puVar2 + 0xa4);
      *(undefined4 *)((longlong)puVar3 + 0xac) = *(undefined4 *)(puVar2 + 0x15);
      *(undefined4 *)(puVar3 + 0x16) = *(undefined4 *)(puVar2 + 0x16);
      *(undefined4 *)((longlong)puVar3 + 0xb4) = *(undefined4 *)((longlong)puVar2 + 0xac);
      uVar4 = uVar4 - 1;
      puVar2 = puVar2 + 0x1b;
      puVar3 = puVar3 + 0x19;
    } while (uVar4 != 0);
  }
  return;
}



===== entry @ 14001b010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 14001b044 =====

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



===== DriverEntry @ 14001b078 =====

undefined8 DriverEntry(void)

{
  wil_InitializeFeatureStaging();
  return 0;
}



===== wil_InitializeFeatureStaging @ 14001b090 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    ppuVar4 = &Feature_TVSDumpBugFix__private_descriptor;
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
          _g_wil_details_featureChangeNotification = 0;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001b180 =====

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
  ppuVar3 = &Feature_TVSDumpBugFix__private_descriptor;
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


