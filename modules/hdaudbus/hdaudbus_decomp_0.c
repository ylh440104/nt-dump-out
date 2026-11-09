
===== Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_> @ 140001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapSz<unsigned short>,struct
   _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID
   const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct
   _tlgWrapSz<unsigned short> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapSz<unsigned_short> *param_6,
          _tlgWrapperByVal<4> *param_7)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [4];
  _tlgWrapperByVal<8> *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_28 = param_7;
  local_20 = 4;
  local_38 = *(wchar_t **)param_6;
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
  local_48 = param_5;
  local_2c = 0;
  local_40 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14001d0d8,param_2,0,0,5,local_68);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>_> @ 1400010d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapSz<unsigned short>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapBuffer<struct _UNICODE_STRING> >(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct
   _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapSz<unsigned short> const & __ptr64,struct
   _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapBuffer<struct _UNICODE_STRING> const &
   __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapSz<unsigned_short> *param_6,
          _tlgWrapperByVal<4> *param_7,_tlgWrapBuffer<_UNICODE_STRING> *param_8)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [4];
  _tlgWrapperByVal<8> *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  undefined8 local_28;
  uint local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_38 = local_20;
  local_50 = 2;
  local_30 = 2;
  local_28 = *(undefined8 *)(*(ushort **)param_8 + 4);
  local_48 = param_7;
  local_20[0] = (uint)**(ushort **)param_8;
  local_20[1] = 0;
  local_40 = 4;
  local_58 = *(wchar_t **)param_6;
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
  local_68 = param_5;
  local_4c = 0;
  local_60 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14001d0d8,param_2,0,0,7,local_88);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapperByVal<4>_> @ 1400011b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapSz<unsigned short>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapBuffer<struct _UNICODE_STRING>,struct _tlgWrapperByVal<4>
   >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct
   _GUID const * __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapSz<unsigned
   short> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapBuffer<struct
   _UNICODE_STRING> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapSz<unsigned_short> *param_6,
          _tlgWrapperByVal<4> *param_7,_tlgWrapBuffer<_UNICODE_STRING> *param_8,
          _tlgWrapperByVal<4> *param_9)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [4];
  _tlgWrapperByVal<8> *local_78;
  undefined8 local_70;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30 [2];
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_28 = param_9;
  local_48 = local_30;
  local_20 = 4;
  local_60 = 2;
  local_40 = 2;
  local_38 = *(undefined8 *)(*(ushort **)param_8 + 4);
  local_58 = param_7;
  local_30[0] = (uint)**(ushort **)param_8;
  local_30[1] = 0;
  local_50 = 4;
  local_68 = *(wchar_t **)param_6;
  if (local_68 == (wchar_t *)0x0) {
    local_68 = L"";
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_68[lVar2] != L'\0');
    local_60 = (int)lVar2 * 2 + 2;
  }
  local_78 = param_5;
  local_70 = 8;
  local_5c = 0;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14001d0d8,param_2,0,0,8,local_98);
  return lVar1;
}



===== _tlgKeywordOn @ 1400012a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _tlgKeywordOn(void)

{
  if (((_DAT_14001d0e8 & 0x400000000003) == 0) ||
     ((DAT_14001d0f0 & 0x400000000003) != DAT_14001d0f0)) {
    return 0;
  }
  return CONCAT71((int7)((DAT_14001d0f0 & 0x400000000003) >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1400012d4 =====

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



===== MsiIsr @ 140001380 =====

/* private: static unsigned char __cdecl HdaController::MsiIsr(struct _KINTERRUPT * __ptr64,void *
   __ptr64,unsigned long) */

uchar __cdecl HdaController::MsiIsr(_KINTERRUPT *param_1,void *param_2,ulong param_3)

{
  uchar uVar1;
  int iVar2;
  uchar uVar3;
  
  uVar3 = '\0';
  iVar2 = 0;
  do {
    uVar1 = Isr(param_1,param_2);
    if (uVar1 == '\0') {
      return uVar3;
    }
    iVar2 = iVar2 + 1;
    uVar3 = '\x01';
  } while (iVar2 < 0x20);
  return '\x01';
}



===== Isr @ 1400013e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static unsigned char __cdecl HdaController::Isr(struct _KINTERRUPT * __ptr64,void *
   __ptr64) */

uchar __cdecl HdaController::Isr(_KINTERRUPT *param_1,void *param_2)

{
  int *piVar1;
  ushort uVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  char cVar8;
  ulonglong uVar9;
  uchar uVar10;
  uint uVar11;
  undefined1 local_1c8 [32];
  uint in_stack_fffffffffffffe58;
  undefined4 in_stack_fffffffffffffe5c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 local_128;
  undefined2 local_124;
  undefined2 uStack_122;
  undefined8 uStack_120;
  undefined4 uStack_118;
  undefined8 local_114;
  undefined8 uStack_10c;
  undefined8 local_104;
  undefined4 uStack_fc;
  undefined4 *puStack_f8;
  undefined4 uStack_f0;
  undefined4 local_ec;
  undefined8 local_e8;
  uint uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined2 local_b4;
  undefined2 uStack_b2;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined8 local_a4;
  undefined8 uStack_9c;
  undefined8 local_94;
  undefined4 uStack_8c;
  undefined8 uStack_88;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined2 local_74;
  undefined2 uStack_72;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined8 local_54;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_1c8;
  uStack_f0 = 0;
  local_ec = 0;
  uStack_138 = 0;
  uVar10 = '\0';
  local_128 = 0;
  local_124 = 0;
  uStack_122 = 0;
  uStack_118 = 0;
  local_114 = 0;
  uStack_10c = 0;
  local_104 = 0;
  uStack_fc = 0;
  local_148 = 0;
  uStack_144 = 0;
  uStack_140 = 0;
  uStack_13c = 0;
  uStack_120 = 0;
  puStack_f8 = (undefined4 *)0x0;
  if ((HDAudBusWmiLoggerEnableFlags & 4) != 0) {
    uStack_120 = 0;
    puStack_f8 = (undefined4 *)0x0;
    if (4 < HDAudBusWmiLoggerEnableLevel) {
      puStack_f8 = &local_148;
      local_148 = 4;
      uStack_144 = 2;
      uStack_140 = 0;
      uStack_13c = 0;
      uStack_138 = 0;
      uStack_f0 = 0x14;
      local_128 = 0x40;
      uStack_fc = 0x120000;
      local_124 = 0x504;
      local_114 = 0xe7ad130f00000000;
      uStack_10c = 0x787d89ab4969d1e6;
      local_104 = 0xfea3e3bc;
      uStack_120 = HDAudBusWmiLoggerHandle;
      iVar6 = IoWMIWriteEvent(&local_128);
      if (iVar6 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar8 = '\0';
        }
        else {
          cVar8 = '\x01';
        }
        if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffe5c,in_stack_fffffffffffffe58),4,10,
                     &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
        }
      }
    }
  }
  if (((*(int *)((longlong)param_2 + 0x40) != 2) ||
      (uStack_48 = (undefined8 *)CONCAT44(uStack_48._4_4_,(undefined4)uStack_48),
      *(short *)((longlong)param_2 + 0x94a6) ==
      CONCAT11(*(undefined1 *)(*(longlong *)((longlong)param_2 + 0x58) + 3),
               *(undefined1 *)(*(longlong *)((longlong)param_2 + 0x58) + 2)))) &&
     (uStack_48 = (undefined8 *)CONCAT44(uStack_48._4_4_,(undefined4)uStack_48),
     *(int *)(*(longlong *)((longlong)param_2 + 0x58) + 0x24) < 0)) {
    if ((*(uint *)(*(longlong *)((longlong)param_2 + 0x58) + 0x24) >> 0x1e & 1) != 0) {
      bVar4 = *(byte *)(*(longlong *)((longlong)param_2 + 0x58) + 0x5d);
      if (bVar4 != 0) {
        if ((bVar4 & 4) != 0) {
          LOCK();
          if (*(int *)((longlong)param_2 + 0x949c) == 0) {
            *(int *)((longlong)param_2 + 0x949c) = 1;
          }
          UNLOCK();
          *(int *)((longlong)param_2 + 0x94fc) = *(int *)((longlong)param_2 + 0x94fc) + 1;
        }
        *(undefined1 *)(*(longlong *)((longlong)param_2 + 0x58) + 0x5d) = 5;
        LOCK();
        UNLOCK();
        uVar11 = KeInsertQueueDpc((longlong)param_2 + 0x93d8,0,0);
        local_b8 = 0;
        uStack_80 = 0;
        local_7c = 0;
        uStack_d8 = 0;
        local_b4 = 0;
        uStack_b2 = 0;
        uStack_b0 = 0;
        uStack_ac = 0;
        uStack_a8 = 0;
        local_a4 = 0;
        uStack_9c = 0;
        local_94 = 0;
        uStack_8c = 0;
        local_e8 = 0;
        uStack_e0 = 0;
        uStack_dc = 0;
        uStack_88 = (undefined8 *)0x0;
        if (((HDAudBusWmiLoggerEnableFlags & 4) != 0) &&
           (uStack_88 = (undefined8 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
          uStack_88 = &local_e8;
          local_b8 = 0x40;
          uStack_b0 = (undefined4)HDAudBusWmiLoggerHandle;
          uStack_ac = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
          local_e8 = CONCAT44(uVar11 & 0xff,5);
          uStack_e0 = (uint)bVar4;
          uStack_dc = 0;
          uStack_d8 = 0;
          uStack_80 = 0x14;
          uStack_8c = 0x120000;
          local_b4 = 0x505;
          local_a4 = 0xe7ad130f00000000;
          uStack_9c = 0x787d89ab4969d1e6;
          local_94 = 0xfea3e3bc;
          iVar6 = IoWMIWriteEvent(&local_b8);
          if (iVar6 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar8 = '\0';
            }
            else {
              cVar8 = '\x01';
            }
            if ((cVar8 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_d
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                         CONCAT44(in_stack_fffffffffffffe5c,in_stack_fffffffffffffe58),4,10,
                         &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
            }
          }
        }
      }
      bVar4 = *(byte *)(*(longlong *)((longlong)param_2 + 0x58) + 0x4d);
      if (bVar4 != 0) {
        if ((bVar4 & 1) != 0) {
          *(int *)((longlong)param_2 + 0x94f8) = *(int *)((longlong)param_2 + 0x94f8) + 1;
        }
        *(undefined1 *)(*(longlong *)((longlong)param_2 + 0x58) + 0x4d) = 1;
        LOCK();
        UNLOCK();
      }
      uVar2 = *(ushort *)(*(longlong *)((longlong)param_2 + 0x58) + 0xe);
      uVar11 = uVar2 & 0x7fff;
      if ((uVar2 & 0x7fff) != 0) {
        *(uint *)((longlong)param_2 + 0x94ac) = uVar11;
        LOCK();
        *(uint *)((longlong)param_2 + 0x94b0) = *(uint *)((longlong)param_2 + 0x94b0) | uVar11;
        UNLOCK();
        bVar4 = KeInsertQueueDpc((longlong)param_2 + 0x94b8,0,0);
        in_stack_fffffffffffffe58 = (uint)bVar4;
        HDABusWmiLogETW(1,4,'\x04','\x06',in_stack_fffffffffffffe58,0,0,0);
        *(undefined2 *)(*(longlong *)((longlong)param_2 + 0x58) + 0xe) = 0x7fff;
        LOCK();
        UNLOCK();
      }
    }
    uVar11 = *(uint *)(*(longlong *)((longlong)param_2 + 0x58) + 0x24) & 0x3fffffff;
    if (uVar11 != 0) {
      uVar9 = 0;
      do {
        if ((uVar11 & 1) != 0) {
          bVar4 = *(byte *)(uVar9 * 0x20 + 0x83 + *(longlong *)((longlong)param_2 + 0x58));
          *(undefined1 *)(uVar9 * 0x20 + 0x83 + *(longlong *)((longlong)param_2 + 0x58)) = 0x1c;
          LOCK();
          UNLOCK();
          if ((bVar4 & 0x10) != 0) {
            piVar1 = (int *)((longlong)param_2 + uVar9 * 8 + 0x9504);
            *piVar1 = *piVar1 + 1;
          }
          if ((bVar4 & 8) != 0) {
            piVar1 = (int *)((longlong)param_2 + uVar9 * 8 + 0x9508);
            *piVar1 = *piVar1 + 1;
          }
          if (*(char *)((longlong)param_2 + uVar9 * 0xd8 + 0x26c) != '\0') {
            pcVar3 = *(code **)((longlong)param_2 + uVar9 * 0xd8 + 0x298);
            if (pcVar3 == (code *)0x0) {
              if ((*(longlong *)((longlong)param_2 + uVar9 * 0xd8 + 0x2a0) != 0) &&
                 ((bVar4 & 4) != 0)) {
                uVar5 = KeInsertQueueDpc((longlong)param_2 + 0x9458,param_2,
                                         (longlong)param_2 + uVar9 * 0xd8 + 0x200);
                local_78 = 0;
                uStack_40 = 0;
                local_3c = 0;
                local_c0 = 0;
                local_74 = 0;
                uStack_72 = 0;
                uStack_70 = 0;
                uStack_6c = 0;
                uStack_68 = 0;
                local_64 = 0;
                uStack_5c = 0;
                local_54 = 0;
                uStack_4c = 0;
                local_d0 = 0;
                uStack_c8 = 0;
                uStack_48 = (undefined8 *)0x0;
                if (((HDAudBusWmiLoggerEnableFlags & 8) != 0) &&
                   (uStack_48 = (undefined8 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
                  uStack_c8 = CONCAT44(*(undefined4 *)((longlong)param_2 + uVar9 * 0xd8 + 0x208),
                                       (uint)*(byte *)((longlong)param_2 + uVar9 * 0xd8 + 0x215));
                  local_c0 = *(undefined4 *)((longlong)param_2 + uVar9 * 0xd8 + 600);
                  uStack_48 = &local_d0;
                  local_78 = 0x40;
                  uStack_70 = (undefined4)HDAudBusWmiLoggerHandle;
                  uStack_6c = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
                  local_d0 = CONCAT44(uVar5 & 0xff,1);
                  uStack_40 = 0x14;
                  uStack_4c = 0x120000;
                  local_74 = 0x501;
                  local_64 = 0xaef818d800000000;
                  uStack_5c = 0x685376a74fb20878;
                  local_54 = 0xa17ab383;
                  iVar6 = IoWMIWriteEvent(&local_78);
                  if (iVar6 < 0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                      cVar8 = '\0';
                    }
                    else {
                      cVar8 = '\x01';
                    }
                    if ((cVar8 != '\0') ||
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      WPP_RECORDER_AND_TRACE_SF_d
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED
                                 ,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                 CONCAT44(in_stack_fffffffffffffe5c,in_stack_fffffffffffffe58),4,10,
                                 &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
                    }
                  }
                }
                *(undefined1 *)(uVar9 * 0xd8 + 0x2c0 + (longlong)param_2) = 1;
                uVar7 = KeQueryPerformanceCounter(0);
                *(undefined8 *)(uVar9 * 0xd8 + 0x2c8 + (longlong)param_2) = uVar7;
              }
            }
            else {
              (*pcVar3)(*(undefined8 *)((longlong)param_2 + uVar9 * 0xd8 + 0x2a0));
            }
          }
        }
        uVar9 = (ulonglong)(byte)((char)uVar9 + 1);
        uVar11 = uVar11 >> 1;
      } while (uVar11 != 0);
    }
    uVar10 = '\x01';
  }
  local_ec = 0;
  uStack_122 = 0;
  uStack_118 = 0;
  if (((HDAudBusWmiLoggerEnableFlags & 4) != 0) && (4 < HDAudBusWmiLoggerEnableLevel)) {
    puStack_f8 = &local_148;
    local_148 = 4;
    uStack_120._0_4_ = (undefined4)HDAudBusWmiLoggerHandle;
    uStack_120._4_4_ = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
    uStack_144 = 2;
    uStack_140 = 0xff;
    uStack_13c = 0;
    uStack_138 = 0;
    uStack_f0 = 0x14;
    local_128 = 0x40;
    uStack_fc = 0x120000;
    local_124 = 0x504;
    local_114 = 0xe7ad130f00000000;
    uStack_10c = 0x787d89ab4969d1e6;
    local_104 = 0xfea3e3bc;
    iVar6 = IoWMIWriteEvent(&local_128);
    if (iVar6 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar8 = '\0';
      }
      else {
        cVar8 = '\x01';
      }
      if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_fffffffffffffe5c,in_stack_fffffffffffffe58),4,10,
                   &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
      }
    }
  }
  return uVar10;
}



===== RtlUnicodeStringPrintf @ 140001b84 =====

/* long __cdecl RtlUnicodeStringPrintf(struct _UNICODE_STRING * __ptr64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlUnicodeStringPrintf(_UNICODE_STRING *param_1,ushort *param_2,...)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  _UNICODE_STRING *p_Var4;
  wchar_t *_Dest;
  ulonglong _Count;
  long lVar5;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  
  p_Var4 = param_1;
  local_res18 = in_R8;
  local_res20 = in_R9;
  uVar2 = RtlUnicodeStringValidateWorker((ushort *)param_1);
  iVar1 = (int)uVar2;
  if ((iVar1 < 0) || (p_Var4 == (_UNICODE_STRING *)0x0)) {
    _Dest = (wchar_t *)0x0;
    _Count = 0;
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    _Dest = *(wchar_t **)(p_Var4 + 8);
    _Count = (ulonglong)(*(ushort *)(param_1 + 2) >> 1);
  }
  lVar5 = 0;
  iVar1 = _vsnwprintf(_Dest,_Count,(wchar_t *)param_2,(va_list)&local_res18);
  if ((iVar1 < 0) || (uVar3 = (longlong)iVar1, _Count < (ulonglong)(longlong)iVar1)) {
    lVar5 = -0x7ffffffb;
    uVar3 = _Count;
  }
  *(short *)param_1 = (short)uVar3 * 2;
  return lVar5;
}



===== RtlUnicodeStringValidateWorker @ 140001c08 =====

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



===== IsEnumWorkaroundForCodecId @ 140001c50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl IsEnumWorkaroundForCodecId(struct _HDAudioDeviceExtension *
   __ptr64,unsigned char,unsigned short,unsigned short) */

uchar __cdecl
IsEnumWorkaroundForCodecId
          (_HDAudioDeviceExtension *param_1,uchar param_2,ushort param_3,ushort param_4)

{
  long lVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uchar uVar5;
  uint uVar6;
  undefined1 auStackY_1f8 [32];
  undefined8 in_stack_fffffffffffffe28;
  int local_1a8 [2];
  undefined8 local_1a0;
  undefined8 local_198;
  undefined1 *local_190;
  undefined8 local_188;
  wchar_t *local_180;
  undefined8 local_178;
  wchar_t local_170 [20];
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1f8;
  uVar5 = '\0';
  (**(code **)(WdfFunctions_01025 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x120),0);
  uVar4 = (uint)param_2;
  uVar6 = 1 << (param_2 & 0x1f);
  if ((uVar6 & *(ushort *)(param_1 + 0x11a)) != 0) {
    local_190 = local_148;
    local_1a8[0] = 0;
    builtin_wcsncpy(local_170,L"EnumWorkaround",0xf);
    local_180 = local_170;
    local_178 = 0;
    local_1a0 = 0;
    local_198 = 0x1000000;
    local_188 = 0x1e001c;
    lVar1 = RtlUnicodeStringPrintf
                      ((_UNICODE_STRING *)&local_198,(ushort *)L"CodecSettings\\%04X%04X",
                       (ulonglong)param_3,(ulonglong)param_4);
    if (lVar1 < 0) goto LAB_140002014;
    iVar2 = (**(code **)(WdfFunctions_01025 + 0x180))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 8),2,0x20000);
    if (iVar2 < 0) goto LAB_140002014;
    in_stack_fffffffffffffe28 = 0;
    iVar2 = (**(code **)(WdfFunctions_01025 + 0x728))(WdfDriverGlobals,local_178,&local_198,0x20000)
    ;
    (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,local_178);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(WdfFunctions_01025 + 0x780))
                        (WdfDriverGlobals,local_1a0,&local_188,local_1a8);
      (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,local_1a0);
      if (-1 < iVar2) {
        if (local_1a8[0] != 0) {
          *(ushort *)(param_1 + 0x118) =
               *(ushort *)(param_1 + 0x118) | (ushort)(1 << (uVar4 & 0x1f));
        }
        *(ushort *)(param_1 + 0x11a) = *(ushort *)(param_1 + 0x11a) & ~(ushort)(1 << (uVar4 & 0x1f))
        ;
      }
    }
  }
  if ((uVar6 & *(ushort *)(param_1 + 0x11a)) != 0) {
    local_190 = local_148;
    local_1a8[0] = 0;
    builtin_wcsncpy(local_170,L"EnumWorkaround",0xf);
    local_180 = local_170;
    local_1a0 = 0;
    local_198 = 0x1000000;
    local_188 = 0x1e001c;
    lVar1 = RtlUnicodeStringPrintf
                      ((_UNICODE_STRING *)&local_198,
                       (ushort *)
                       L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Audio\\HDAudioFlags\\%04X%04X"
                       ,(ulonglong)param_3,(ulonglong)param_4);
    if (lVar1 < 0) goto LAB_140002014;
    in_stack_fffffffffffffe28 = 0;
    iVar2 = (**(code **)(WdfFunctions_01025 + 0x728))(WdfDriverGlobals,0,&local_198,0x20000);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(WdfFunctions_01025 + 0x780))
                        (WdfDriverGlobals,local_1a0,&local_188,local_1a8);
      (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,local_1a0);
      if ((-1 < iVar2) && (local_1a8[0] != 0)) {
        *(ushort *)(param_1 + 0x118) = *(ushort *)(param_1 + 0x118) | (ushort)(1 << (uVar4 & 0x1f));
      }
    }
    *(ushort *)(param_1 + 0x11a) = *(ushort *)(param_1 + 0x11a) & ~(ushort)(1 << (uVar4 & 0x1f));
  }
  if ((uVar6 & *(ushort *)(param_1 + 0x118)) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffe28,4,10,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,param_2);
    }
    uVar5 = '\x01';
  }
LAB_140002014:
  (**(code **)(WdfFunctions_01025 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x120));
  return uVar5;
}



===== GetDescriptionFromCodecAddress @ 14000206c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HdaController::GetDescriptionFromCodecAddress(unsigned long,struct
   _ChildIdentificationDescription * __ptr64) __ptr64 */

long __thiscall
HdaController::GetDescriptionFromCodecAddress
          (HdaController *this,ulong param_1,_ChildIdentificationDescription *param_2)

{
  int iVar1;
  undefined8 uVar2;
  char cVar3;
  long lVar4;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  lVar4 = -0x3fffffff;
  uVar2 = (**(code **)(WdfFunctions_01025 + 0x420))(WdfDriverGlobals);
  local_res8 = 0;
  if (param_2 == (_ChildIdentificationDescription *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,4,0x4e,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar4 = -0x3ffffff3;
  }
  else {
    local_38 = 0x28;
    local_30 = 0;
    uStack_28 = 0;
    local_34 = 3;
    local_20 = 0;
    uStack_18 = 0;
    (**(code **)(WdfFunctions_01025 + 0x30))(WdfDriverGlobals,uVar2,&local_38);
    do {
      do {
        iVar1 = (**(code **)(WdfFunctions_01025 + 0x38))
                          (WdfDriverGlobals,uVar2,&local_38,&local_res8,0);
        if (iVar1 < 0) goto LAB_14000212f;
      } while (local_res8 == 0);
      *(undefined4 *)param_2 = 0x18;
      iVar1 = (**(code **)(WdfFunctions_01025 + 0x6f0))(WdfDriverGlobals,local_res8,param_2);
    } while ((iVar1 < 0) || (param_1 != (byte)param_2[0x12]));
    lVar4 = 0;
LAB_14000212f:
    (**(code **)(WdfFunctions_01025 + 0x40))(WdfDriverGlobals,uVar2,&local_38);
  }
  return lVar4;
}



===== IsEnumWorkaroundCodec @ 140002228 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl IsEnumWorkaroundCodec(struct _HDAudioDeviceExtension * __ptr64,unsigned
   char) */

uchar __cdecl IsEnumWorkaroundCodec(_HDAudioDeviceExtension *param_1,uchar param_2)

{
  uchar uVar1;
  long lVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = '\0';
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (*(HdaController **)(param_1 + 0x10) != (HdaController *)0x0) {
    lVar2 = HdaController::GetDescriptionFromCodecAddress
                      (*(HdaController **)(param_1 + 0x10),(uint)param_2,
                       (_ChildIdentificationDescription *)&local_28);
    if (-1 < lVar2) {
      uVar1 = IsEnumWorkaroundForCodecId(param_1,param_2,local_28._6_2_,(ushort)uStack_20);
    }
  }
  return uVar1;
}



===== MarkCodecsPresent @ 1400022b4 =====

/* public: void __cdecl HdaController::MarkCodecsPresent(unsigned short) __ptr64 */

void __thiscall HdaController::MarkCodecsPresent(HdaController *this,ushort param_1)

{
  undefined8 *puVar1;
  
  KeWaitForSingleObject(this + 0x9678,0,0,0,0);
  for (puVar1 = (undefined8 *)FirstEntrySList(this + 0x9660); puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
    HdaLinkInstance::ReportCodecsPresent((HdaLinkInstance *)puVar1[2],param_1);
  }
  KeReleaseMutex(this + 0x9678,0);
  return;
}



===== GetDeviceInformation @ 140002348 =====

/* public: long __cdecl HdaController::GetDeviceInformation(struct _HDAUDIO_DEVICE_INFORMATION *
   __ptr64) __ptr64 */

long __thiscall
HdaController::GetDeviceInformation(HdaController *this,_HDAUDIO_DEVICE_INFORMATION *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  long lVar5;
  undefined2 uVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffc8;
  
  uVar6 = 10;
  if (*(ushort *)param_1 < 10) {
    bVar7 = true;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xa7,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar5 = -0x3fffffdd;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar7 = false;
    }
    if ((bVar7) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xa8,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x23);
    }
  }
  else {
    uVar2 = *(ushort *)(*(longlong *)(this + 0x58) + 0xe);
    uVar3 = *(ushort *)(this + 0x94a4);
    do {
      LOCK();
      uVar1 = *(ushort *)(this + 0x94a4);
      bVar7 = uVar3 == uVar1;
      if (bVar7) {
        *(ushort *)(this + 0x94a4) = uVar3 | uVar2 & 0x7fff;
      }
      else {
        uVar3 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
    *(ushort *)(param_1 + 6) = uVar3;
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(this + 0x94a6);
    *(undefined2 *)(param_1 + 4) = 0x100;
    *(HdaController *)(param_1 + 8) = this[0x81];
    if (0xd < *(ushort *)param_1) {
      uVar6 = 0xe;
      *(short *)(param_1 + 10) = (short)((ulonglong)*(undefined8 *)(this + 0x78) >> 0x18);
      *(short *)(param_1 + 0xc) = (short)((uint)*(undefined4 *)(this + 0x78) >> 8);
      *(HdaController *)(param_1 + 9) = this[0x78];
    }
    *(undefined2 *)param_1 = uVar6;
    lVar5 = 0;
  }
  return lVar5;
}



===== SetNonSnoop @ 1400024f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SetNonSnoop(struct WDFDEVICE__ * __ptr64) */

long __cdecl SetNonSnoop(WDFDEVICE__ *param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  bool bVar5;
  byte local_res10 [8];
  undefined2 uVar6;
  undefined2 in_stack_ffffffffffffff6a;
  undefined4 in_stack_ffffffffffffff6c;
  undefined4 in_stack_ffffffffffffff70;
  undefined2 uVar7;
  undefined1 local_68 [8];
  undefined8 local_60;
  code *local_50;
  code *local_38;
  code *local_30;
  
  uVar7 = (undefined2)((uint)in_stack_ffffffffffffff70 >> 0x10);
  memset(local_68,0,0x40);
  local_res10[0] = 0;
  lVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  bVar1 = true;
  uVar6 = 0x40;
  iVar2 = (**(code **)(WdfFunctions_01025 + 0x418))
                    (WdfDriverGlobals,param_1,&GUID_BUS_INTERFACE_STANDARD,local_68,0x40,
                     CONCAT22(uVar7,1),0);
  if (iVar2 < 0) goto LAB_140002745;
  if (local_30 == (code *)0x0) {
    iVar2 = -0x3fffff45;
    goto LAB_140002745;
  }
  uVar6 = 1;
  in_stack_ffffffffffffff6a = 0;
  iVar2 = (*local_30)(local_60,0,local_res10,0x79);
  if (iVar2 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_ffffffffffffff6c,CONCAT22(in_stack_ffffffffffffff6a,uVar6)),4,
                 0x21,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,local_res10[0]);
    }
    if (*(char *)(lVar3 + 0xc1) == '\0') {
      if ((local_res10[0] & 8) != 0) {
LAB_140002629:
        (*local_50)(local_60);
        return 0;
      }
      local_res10[0] = local_res10[0] | 8;
      uVar6 = 1;
      in_stack_ffffffffffffff6a = 0;
      iVar2 = (*local_38)(local_60,0,local_res10,0x79);
      if (iVar2 == 1) goto LAB_140002629;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar4 != '\0') || (bVar5)) {
        uVar7 = 0x23;
        goto LAB_1400027f2;
      }
    }
    else {
      if ((local_res10[0] & 8) == 0) goto LAB_140002629;
      local_res10[0] = local_res10[0] & 0xf7;
      uVar6 = 1;
      in_stack_ffffffffffffff6a = 0;
      iVar2 = (*local_38)(local_60,0,local_res10,0x79);
      if (iVar2 == 1) goto LAB_140002629;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar4 != '\0') || (bVar5)) {
        uVar7 = 0x22;
        goto LAB_1400027f2;
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 != '\0') || (bVar5)) {
      uVar7 = 0x20;
LAB_1400027f2:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar5,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_ffffffffffffff6c,CONCAT22(in_stack_ffffffffffffff6a,uVar6)),4,
                 uVar7,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
  }
  iVar2 = -0x3ffffff0;
LAB_140002745:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffff6c,CONCAT22(in_stack_ffffffffffffff6a,uVar6)),4,0x24,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar2);
  }
  return iVar2;
}



===== HdAudBusEnumerateBus @ 1400028c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl HdAudBusEnumerateBus(struct WDFCHILDLIST__ * __ptr64) */

void __cdecl HdAudBusEnumerateBus(WDFCHILDLIST__ *param_1)

{
  HdaController *this;
  uint3 uVar1;
  uint3 uVar2;
  uint3 uVar3;
  uint3 uVar4;
  ulong uVar5;
  WDFCHILDLIST__ *pWVar6;
  uchar uVar7;
  uchar uVar8;
  int iVar9;
  uint uVar10;
  long lVar11;
  undefined8 uVar12;
  _HDAudioDeviceExtension *p_Var13;
  undefined8 *puVar14;
  undefined8 uVar15;
  char cVar16;
  uint uVar17;
  byte bVar18;
  uint uVar19;
  char cVar20;
  char cVar21;
  ushort uVar22;
  byte bVar23;
  bool bVar24;
  undefined1 auStackY_168 [32];
  undefined2 in_stack_fffffffffffffeb8;
  ushort uVar25;
  undefined2 in_stack_fffffffffffffeba;
  undefined2 uVar26;
  undefined4 in_stack_fffffffffffffebc;
  undefined2 uVar27;
  uint local_118;
  ulong local_114;
  uint local_110;
  WDFCHILDLIST__ *local_108;
  ulonglong local_100;
  _HDAudioDeviceExtension *local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined2 local_d8;
  undefined8 local_d6;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  uint local_b0 [2];
  ulong local_a8;
  uint local_a0;
  undefined4 local_98;
  undefined4 local_90;
  uint local_88;
  uint local_78 [4];
  uint local_68;
  uint local_58;
  uint local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  local_e0 = 0;
  local_114 = 0;
  local_118 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar16 = '\0';
  }
  local_108 = param_1;
  if ((cVar16 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_fffffffffffffebc,
                        CONCAT22(in_stack_fffffffffffffeba,in_stack_fffffffffffffeb8)),0xd,0x57,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  uVar25 = 1;
  uVar26 = 0;
  HDABusWmiLogETW(1,1,'\x04','\x01',1,0,0,0);
  uVar12 = (**(code **)(WdfFunctions_01025 + 8))(WdfDriverGlobals,param_1);
  p_Var13 = (_HDAudioDeviceExtension *)
            (**(code **)(WdfFunctions_01025 + 0x650))
                      (WdfDriverGlobals,uVar12,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  this = *(HdaController **)(p_Var13 + 0x10);
  local_f8 = p_Var13;
  if (this != (HdaController *)0x0) {
    for (puVar14 = (undefined8 *)FirstEntrySList(this + 0x9660); puVar14 != (undefined8 *)0x0;
        puVar14 = (undefined8 *)*puVar14) {
      HdaLinkInstance::TurnOn((HdaLinkInstance *)puVar14[2]);
    }
    local_d6 = 0;
    local_d8 = 10;
    HdaController::GetDeviceInformation(this,(_HDAUDIO_DEVICE_INFORMATION *)&local_d8);
    (**(code **)(WdfFunctions_01025 + 0x20))(WdfDriverGlobals,param_1);
    bVar23 = 0;
    do {
      local_e0 = 0;
      uStack_e8 = 0;
      local_f0 = 0x18;
      if ((*(uint *)(p_Var13 + 0x1e0) == (uint)bVar23) &&
         (HdaController::WaitForSgpcLink(this), p_Var13[0x1d0] != (_HDAudioDeviceExtension)0x0)) {
        if (p_Var13[0x1e6] == (_HDAudioDeviceExtension)0x0) {
          local_e0._0_5_ = CONCAT14(1,(undefined4)local_e0);
          goto LAB_140002a73;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
           (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
          cVar16 = '\0';
        }
        if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
           (cVar20 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
          cVar20 = '\0';
        }
        if ((cVar16 != '\0') || (cVar20 != '\0')) {
          uVar27 = 0x58;
LAB_140003179:
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,cVar20,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,uVar27,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,bVar23);
        }
      }
      else {
LAB_140002a73:
        uVar17 = 1 << (bVar23 & 0x1f);
        if ((uVar17 & local_d6._4_2_) != 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
            cVar16 = '\0';
          }
          else {
            cVar16 = '\x01';
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
             (cVar20 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
            cVar20 = '\0';
          }
          if ((cVar16 != '\0') || (cVar20 != '\0')) {
            WPP_RECORDER_AND_TRACE_SF_d
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,cVar20,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,0x59,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,bVar23);
          }
          local_110 = (uint)bVar23 << 0x1c;
          local_b0[0] = local_a0 & 0xf0000 | local_110 | 0xf0000;
          uVar1 = (uint3)(local_110 >> 8);
          uVar19 = (uint)local_90 >> 8;
          local_a0._1_3_ = (uint3)(local_a0 >> 8) & 0xf00 | uVar1 | 0xf00;
          local_a0 = CONCAT31(local_a0._1_3_,2);
          local_90 = CONCAT31((uint3)uVar19 & 0xf00 | uVar1 | 0xf00,4);
          lVar11 = SendVerbs(this,3,(_HDAUDIO_CODEC_TRANSFER *)local_b0);
          if (lVar11 < 0) {
            uVar8 = IsEnumWorkaroundCodec(p_Var13,bVar23);
            if ((uVar8 == '\x01') && ((uVar17 & *(ushort *)(this + 0x9604)) != 0)) {
              local_b8 = 0;
              local_c8 = 0;
              uStack_c0 = 0;
              uVar8 = SearchForDescriptionFromDeviceList
                                (param_1,(ushort)bVar23,(_ChildIdentificationDescription *)&local_c8
                                );
              if ((uVar8 != '\0') &&
                 (lVar11 = (**(code **)(WdfFunctions_01025 + 0x48))
                                     (WdfDriverGlobals,param_1,&local_c8,0), lVar11 < 0)) {
                if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                   (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0 ||
                    (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)))) {
                  cVar16 = '\0';
                }
                bVar24 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                if ((cVar16 != '\0') || (bVar24)) {
                  uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
                  uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                  uVar27 = 0x5a;
                  goto LAB_140003210;
                }
              }
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0 ||
                  ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
                cVar16 = '\0';
              }
              else {
                cVar16 = '\x01';
              }
              bVar24 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((cVar16 != '\0') || (bVar24)) {
                uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
                uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                uVar27 = 0x5b;
LAB_140003210:
                WPP_RECORDER_AND_TRACE_SF_d
                          (uVar15,cVar16,bVar24,uVar12,
                           CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,uVar27,
                           &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)lVar11);
              }
            }
          }
          else {
            uVar22 = (ushort)(local_a8 >> 0x10);
            local_f0 = CONCAT26(uVar22,(undefined6)local_f0);
            uStack_e8 = CONCAT62(uStack_e8._2_6_,(ushort)local_a8);
            local_e0 = CONCAT62(local_e0._2_6_,(short)((uint)local_98 >> 8));
            if (((*(uint *)(p_Var13 + 0x1e0) == (uint)bVar23) &&
                (uVar8 = IsEnumWorkaroundForCodecId(p_Var13,bVar23,uVar22,(ushort)local_a8),
                uVar8 == '\0')) && (p_Var13[0x1e6] != (_HDAudioDeviceExtension)0x0)) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
                cVar16 = '\0';
              }
              if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                 (cVar20 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
                cVar20 = '\0';
              }
              if ((cVar16 != '\0') || (cVar20 != '\0')) {
                uVar27 = 0x5c;
                goto LAB_140003179;
              }
            }
            else {
              uVar19 = local_88;
              uVar17 = local_88 >> 0x10;
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
                cVar16 = '\0';
              }
              if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                 (cVar20 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
                cVar20 = '\0';
              }
              bVar18 = (byte)local_88;
              if ((cVar16 != '\0') || (param_1 = local_108, cVar20 != '\0')) {
                WPP_RECORDER_AND_TRACE_SF_dd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,cVar20,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                           CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,0x5d,
                           &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)(local_88 >> 0x10)
                           ,bVar18);
                param_1 = local_108;
              }
              while (pWVar6 = local_108, local_108 = param_1, bVar18 != 0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                   (cVar16 = '\x01', *(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 5)) {
                  cVar16 = '\0';
                }
                if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                   (cVar20 = '\x01', *(short *)((longlong)WPP_GLOBAL_Control + 0x48) == 0)) {
                  cVar20 = '\0';
                }
                uVar8 = (uchar)uVar17;
                if ((cVar16 != '\0') || (cVar20 != '\0')) {
                  WPP_RECORDER_AND_TRACE_SF_d
                            (*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),cVar16,cVar20,
                             *(undefined **)((longlong)WPP_GLOBAL_Control + 0x40),
                             CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,0x5e,
                             &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar8);
                }
                uVar10 = local_b0[0] >> 8;
                uVar1 = (uint3)(((uVar17 & 0xff) << 0x14) >> 8);
                local_b0[0] = CONCAT31((uint3)uVar10 & 0xf00f00 | uVar1 | 0xf00,1);
                local_a0._1_3_ = (uint3)(local_a0 >> 8) & 0xf00f00 | uVar1 | 0xf00;
                local_a0 = CONCAT31(local_a0._1_3_,5);
                lVar11 = SendVerbs(this,2,(_HDAUDIO_CODEC_TRANSFER *)local_b0);
                if (lVar11 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                     (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    cVar16 = '\0';
                  }
                  if ((cVar16 != '\0') ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    WPP_RECORDER_AND_TRACE_SF_dd
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,
                               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                               CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,0x5f,
                               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar8,(char)lVar11);
                  }
                }
                else {
                  if (local_a8 == 0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                       (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
                      cVar16 = '\0';
                    }
                    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                       (cVar20 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
                      cVar20 = '\0';
                    }
                    if ((cVar16 != '\0') || (cVar20 != '\0')) {
                      WPP_RECORDER_AND_TRACE_SF_
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,cVar20,
                                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                 CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,
                                 0x60,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
                    }
                    local_b0[0] = local_b0[0] & 0xffff2000 | 0xf2000;
                    lVar11 = SendVerbs(this,1,(_HDAUDIO_CODEC_TRANSFER *)local_b0);
                    if (lVar11 < 0) goto LAB_140002ed1;
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                       (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
                      cVar16 = '\0';
                    }
                    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                       (cVar20 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
                      cVar20 = '\0';
                    }
                    if ((cVar16 != '\0') || (cVar20 != '\0')) {
                      WPP_RECORDER_AND_TRACE_SF_D
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,cVar20,
                                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                 CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,
                                 0x61,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,
                                 (char)local_a8);
                    }
                  }
                  if (local_a8 == 0xffffffff) {
                    local_100 = 0;
                    uVar10 = KeQueryTimeIncrement();
                    if (uVar10 < 70000) {
                      local_100 = 0xfffffffffffeee90;
                    }
                    else {
                      uVar10 = KeQueryTimeIncrement();
                      local_100 = ~(ulonglong)uVar10;
                    }
                    KeDelayExecutionThread(0,0,&local_100);
                    lVar11 = SendVerbs(this,1,(_HDAUDIO_CODEC_TRANSFER *)local_b0);
                    if (lVar11 < 0) {
                      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                         (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                        cVar16 = '\0';
                      }
                      if ((cVar16 != '\0') ||
                         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                        WPP_RECORDER_AND_TRACE_SF_d
                                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,
                                   (undefined **)WPP_RECORDER_INITIALIZED !=
                                   &WPP_RECORDER_INITIALIZED,
                                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                   CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,
                                   0x62,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,
                                   (char)lVar11);
                      }
                      goto LAB_140002ed1;
                    }
                  }
                  uVar25 = (ushort)local_e0;
                  uVar7 = SearchForSubsystemIDFromDeviceList
                                    (pWVar6,(ushort)bVar23,local_f0._6_2_,(ushort)uStack_e8,
                                     (ushort)local_e0,uVar8,&local_114);
                  uVar5 = local_114;
                  if (uVar7 == '\0') {
                    uStack_e8 = CONCAT44(local_a8,(undefined4)uStack_e8);
                  }
                  else {
                    uStack_e8 = CONCAT44(local_114,(undefined4)uStack_e8);
                    if (local_a8 != local_114) {
                      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                        cVar16 = '\0';
                      }
                      else {
                        cVar16 = '\x01';
                      }
                      if ((cVar16 != '\0') ||
                         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                        WPP_RECORDER_AND_TRACE_SF_
                                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,
                                   (undefined **)WPP_RECORDER_INITIALIZED !=
                                   &WPP_RECORDER_INITIALIZED,
                                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                   CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,
                                   99,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
                      }
                      uVar4 = (uint3)(local_110 >> 8);
                      uVar2 = uVar4 & 0xf00000;
                      uVar3 = (uint3)(local_68 >> 8);
                      uVar1 = (uint3)(((uVar17 & 0xff) << 0x14) >> 8);
                      local_78[0] = CONCAT31(uVar3 & 0x720 | uVar2 | uVar1,(char)uVar5) | 0x72000;
                      local_68 = CONCAT31(uVar3 & 0x721 | uVar2 | uVar1,(char)(uVar5 >> 8)) |
                                 0x72100;
                      local_58 = CONCAT31((uint3)(local_58 >> 8) & 0x722 | uVar2 | uVar1,
                                          (char)(uVar5 >> 0x10)) | 0x72200;
                      local_48 = CONCAT31(((uint3)(local_48 >> 8) & 0xfffff | uVar4) & 0xf00723 |
                                          uVar1,(char)(uVar5 >> 0x18)) | 0x72300;
                      SendVerbs(this,4,(_HDAUDIO_CODEC_TRANSFER *)local_78);
                    }
                  }
                  uVar12 = local_e0;
                  local_f0._0_5_ = CONCAT14((undefined1)local_98,(undefined4)local_f0);
                  local_e0._4_4_ = SUB84(uVar12,4);
                  local_e0._0_4_ = CONCAT13(uVar8,CONCAT12(bVar23,(ushort)local_e0));
                  iVar9 = (**(code **)(WdfFunctions_01025 + 0x48))
                                    (WdfDriverGlobals,pWVar6,&local_f0,0);
                  if (iVar9 < 0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                       (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                      cVar16 = '\0';
                    }
                    if ((cVar16 != '\0') ||
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      WPP_RECORDER_AND_TRACE_SF_d
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,
                                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED
                                 ,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                 CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),0xd,100
                                 ,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar9);
                    }
                  }
                  local_118 = local_118 & 0xffff | 1 << (bVar23 & 0x1f);
                }
LAB_140002ed1:
                uVar17 = (uint)(byte)(uVar8 + 1);
                bVar18 = (char)uVar19 - 1;
                uVar19 = (uint)bVar18;
                p_Var13 = local_f8;
                param_1 = local_108;
                local_108 = pWVar6;
              }
            }
          }
        }
      }
      bVar23 = bVar23 + 1;
    } while (bVar23 < 0x10);
    HdaController::MarkCodecsPresent(this,(ushort)local_118);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar16 = '\0';
    }
    if ((cVar16 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),1,0x65,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)local_118);
    }
    (**(code **)(WdfFunctions_01025 + 0x28))(WdfDriverGlobals,param_1);
    if ((ushort)local_118 != 0) goto LAB_140002b34;
  }
  cVar16 = '\0';
  if (p_Var13[0xbe] != (_HDAudioDeviceExtension)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar20 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar20 = cVar16;
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (cVar21 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar21 = cVar16;
    }
    if ((cVar20 != '\0') || (cVar21 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar20,cVar21,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),2,0x66,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)this);
    }
    lVar11 = HdAudBusUpdateS0IdleSettings(*(WDFDEVICE__ **)(p_Var13 + 8),'\x01');
    if (lVar11 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
         (cVar20 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar20 = cVar16;
      }
      if ((cVar20 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar20,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_fffffffffffffebc,CONCAT22(uVar26,uVar25)),2,0x67,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)this);
      }
    }
  }
LAB_140002b34:
  HDABusWmiLogETW(1,1,'\x04','\x01',1,0xff,0,0);
  return;
}



===== SearchForSubsystemIDFromDeviceList @ 1400037dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl SearchForSubsystemIDFromDeviceList(struct WDFCHILDLIST__ * __ptr64,unsigned
   short,unsigned short,unsigned short,unsigned short,unsigned char,unsigned long * __ptr64) */

uchar __cdecl
SearchForSubsystemIDFromDeviceList
          (WDFCHILDLIST__ *param_1,ushort param_2,ushort param_3,ushort param_4,ushort param_5,
          uchar param_6,ulong *param_7)

{
  int iVar1;
  char cVar2;
  char cVar3;
  uchar uVar4;
  undefined1 auStackY_f8 [32];
  undefined4 *puVar5;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_a0 = 0;
  local_98 = 0x28;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  cVar3 = '\x01';
  uVar4 = '\0';
  local_94 = 1;
  (**(code **)(WdfFunctions_01025 + 0x30))(WdfDriverGlobals,param_1,&local_98);
  do {
    local_6c = 0;
    local_68 = &local_48;
    local_50 = 0;
    puVar5 = &local_70;
    local_70 = 0x28;
    local_38 = 0;
    uStack_40 = 0;
    local_48 = 0x18;
    local_60 = 0;
    uStack_58 = 0;
    iVar1 = (**(code **)(WdfFunctions_01025 + 0x38))(WdfDriverGlobals,param_1,&local_98,&local_a0);
    if (iVar1 < 0) goto LAB_140003902;
  } while ((((param_2 != local_38._2_1_) || (param_3 != local_48._6_2_)) ||
           (param_4 != (ushort)uStack_40)) ||
          ((param_5 != (ushort)local_38 || (param_6 != local_38._3_1_))));
  uVar4 = '\x01';
  *param_7 = uStack_40._4_4_;
LAB_140003902:
  (**(code **)(WdfFunctions_01025 + 0x40))(WdfDriverGlobals,param_1);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,0xd,0x53,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar4);
  }
  return uVar4;
}



===== HdAudBusSelfManagedIoSuspend @ 1400039f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HdAudBusSelfManagedIoSuspend(struct WDFDEVICE__ * __ptr64) */

long __cdecl HdAudBusSelfManagedIoSuspend(WDFDEVICE__ *param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffb8;
  
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
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,1,0x6e,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  (**(code **)(WdfFunctions_01025 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x80),0);
  cVar2 = *(char *)(lVar1 + 0x7c);
  *(undefined1 *)(lVar1 + 0x7d) = 1;
  (**(code **)(WdfFunctions_01025 + 0x9d0))(WdfDriverGlobals);
  if (cVar2 != '\0') {
    in_stack_ffffffffffffffb8 = 0;
    KeWaitForSingleObject(lVar1 + 0x88,0,0,0);
  }
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
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,1,0x6f,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  return 0;
}



===== WPP_RECORDER_AND_TRACE_SF_qd @ 140003bb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,param_6,param_8,param_7,&param_9,8,&param_10,4,0);
  }
  return;
}



===== HdAudBusPowerUp @ 140003ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HdAudBusPowerUp(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl HdAudBusPowerUp(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  bool bVar1;
  long lVar2;
  longlong lVar3;
  char cVar4;
  undefined8 in_stack_ffffffffffffffb8;
  
  lVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,2,0x68,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1,(char)param_2 + -1);
  }
  if (*(HdaController **)(lVar3 + 0x10) == (HdaController *)0x0) {
    lVar2 = -0x3ffffff0;
  }
  else {
    lVar2 = HdaController::PowerUp(*(HdaController **)(lVar3 + 0x10));
    if (-1 < lVar2) {
      *(undefined4 *)(lVar3 + 0xa0) = 1;
      *(undefined1 *)(lVar3 + 0x7d) = 0;
      lVar2 = SetNonSnoop(param_1);
      if (lVar2 < 0) {
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
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,2,0x69,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)lVar2);
        }
        lVar2 = 0;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     ((int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((lVar2 >> 0x1f & 0xfffffffeU) + 4))) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,2,0x6a,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1,(char)lVar2);
  }
  return lVar2;
}



===== SendVerbs @ 140003ed0 =====

/* long __cdecl SendVerbs(class HdaController * __ptr64,unsigned long,struct _HDAUDIO_CODEC_TRANSFER
   * __ptr64) */

long __cdecl SendVerbs(HdaController *param_1,ulong param_2,_HDAUDIO_CODEC_TRANSFER *param_3)

{
  bool bVar1;
  long lVar2;
  uint uVar3;
  char cVar4;
  _HDAUDIO_CODEC_TRANSFER *p_Var5;
  ulonglong uVar6;
  undefined8 uVar7;
  _ChildDeviceExtension local_68 [80];
  
  memset(local_68,0,0x48);
  bVar1 = true;
  HDABusWmiLogETW(1,4,'\x05','\x03',10,param_2,0,0);
  if (param_2 != 0) {
    uVar6 = (ulonglong)param_2;
    p_Var5 = param_3;
    do {
      HDABusWmiLogETW(1,4,'\x05','\x03',10,*(ulong *)p_Var5,0,0);
      p_Var5 = p_Var5 + 0x10;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  uVar7 = 0;
  lVar2 = HdaController::TransferCodecVerbs
                    (param_1,local_68,param_2,param_3,
                     (_func_void__HDAUDIO_CODEC_TRANSFER_ptr_void_ptr *)0x0,(void *)0x0);
  if (lVar2 < 0) {
LAB_140004013:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,0xd,0x26,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)lVar2);
    }
  }
  else {
    for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + 1) {
      if (-1 < *(int *)(param_3 + (ulonglong)uVar3 * 0x10 + 0xc)) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar4 = '\0';
        }
        else {
          cVar4 = '\x01';
        }
        if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,0xd,0x25,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
        }
        lVar2 = -0x3fffffff;
        goto LAB_140004013;
      }
    }
    lVar2 = 0;
  }
  return lVar2;
}



===== HdAudBusChildPowerUp @ 1400040c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl HdAudBusChildPowerUp(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl HdAudBusChildPowerUp(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  longlong lVar1;
  HdaController *this;
  bool bVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  WDFDEVICE__ *pWVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char cVar9;
  undefined4 in_register_00000014;
  undefined1 auStackY_128 [32];
  undefined4 in_stack_fffffffffffffef8;
  undefined4 in_stack_fffffffffffffefc;
  undefined4 in_stack_ffffffffffffff00;
  undefined4 in_stack_ffffffffffffff04;
  undefined *in_stack_ffffffffffffff10;
  undefined1 uVar10;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined8 local_94;
  undefined2 local_88;
  undefined2 local_86;
  undefined2 local_84;
  undefined2 uStack_82;
  undefined8 uStack_80;
  undefined4 uStack_78;
  undefined8 local_74;
  undefined8 uStack_6c;
  undefined8 local_64;
  undefined4 uStack_5c;
  undefined4 *puStack_58;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_128;
  local_38 = 0;
  uStack_50 = 0;
  local_4c = 0;
  local_86 = 0;
  bVar2 = true;
  local_48 = 0;
  uStack_40 = 0;
  local_84 = 0;
  uStack_82 = 0;
  uStack_78 = 0;
  local_74 = 0;
  uStack_6c = 0;
  local_64 = 0;
  uStack_5c = 0;
  uStack_80 = 0;
  puStack_58 = (undefined4 *)0x0;
  if ((HDAudBusWmiLoggerEnableFlags & 4) != 0) {
    uStack_80 = 0;
    puStack_58 = (undefined4 *)0x0;
    if (3 < HDAudBusWmiLoggerEnableLevel) {
      puStack_58 = &local_a0;
      local_88 = 0x40;
      local_a0 = 2;
      local_9c = 4;
      local_94 = 0;
      uStack_50 = 0x14;
      uStack_5c = 0x120000;
      local_84 = 0x402;
      local_74 = 0xe7ad130f00000000;
      uStack_6c = 0x787d89ab4969d1e6;
      local_64 = 0xfea3e3bc;
      local_98 = (int)param_1;
      uStack_80 = HDAudBusWmiLoggerHandle;
      iVar3 = IoWMIWriteEvent(&local_88,CONCAT44(in_register_00000014,param_2));
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar9 = '\0';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          in_stack_ffffffffffffff10 = &WPP_479594a964603c08568526b79db93239_Traceguids;
          in_stack_ffffffffffffff00 = 4;
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffefc,in_stack_fffffffffffffef8),4,10,
                     &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar3);
        }
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar9 = '\0';
  }
  uVar10 = SUB81(param_1,0);
  if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffff10 = &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids;
    in_stack_ffffffffffffff00 = 2;
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_fffffffffffffefc,in_stack_fffffffffffffef8),2,0x28,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar10);
  }
  lVar5 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
  if (lVar5 == 0) {
    iVar3 = -0x3ffffff3;
    goto LAB_140004428;
  }
  lVar1 = *(longlong *)(lVar5 + 0x28);
  if (lVar1 == 0) {
    iVar3 = -0x3ffffff3;
    goto LAB_140004428;
  }
  this = *(HdaController **)(lVar5 + 0x30);
  if (this == (HdaController *)0x0) {
    iVar3 = -0x3ffffff3;
    goto LAB_140004428;
  }
  local_48 = CONCAT44(local_48._4_4_,0x18);
  (**(code **)(WdfFunctions_01025 + 0x6f0))(WdfDriverGlobals,param_1,&local_48);
  in_stack_fffffffffffffef8 = 0x20;
  *(ushort *)(this + 0x9604) = *(ushort *)(this + 0x9604) & ~(ushort)(1 << (local_38._2_1_ & 0x1f));
  iVar3 = IoAcquireRemoveLockEx(this + 8,param_1,"",1);
  if (iVar3 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar9 = '\0';
    }
    if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_fffffffffffffefc,in_stack_fffffffffffffef8),
                 CONCAT44(in_stack_ffffffffffffff04,in_stack_ffffffffffffff00),0x29,
                 in_stack_ffffffffffffff10,uVar10,(char)this,(char)iVar3);
    }
    goto LAB_140004428;
  }
  if ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) == 0) {
    local_86 = 0;
    uStack_50 = 0;
    local_4c = 0;
    local_84 = 0;
    uStack_82 = 0;
    uStack_80._0_4_ = 0;
    uStack_80._4_4_ = 0;
    uStack_78 = 0;
    local_74 = 0;
    uStack_6c = 0;
    local_64 = 0;
    uStack_5c = 0;
    puStack_58 = (undefined4 *)0x0;
    if (((HDAudBusWmiLoggerEnableFlags & 4) != 0) &&
       (puStack_58 = (undefined4 *)0x0, 3 < HDAudBusWmiLoggerEnableLevel)) {
      puStack_58 = &local_a0;
      local_a0 = 2;
      local_9c = 4;
      local_88 = 0x40;
      uStack_80._0_4_ = (undefined4)HDAudBusWmiLoggerHandle;
      uStack_80._4_4_ = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
      local_94 = 0x100000001;
      uStack_50 = 0x14;
      uStack_5c = 0x120000;
      local_84 = 0x402;
      local_74 = 0xe7ad130f00000000;
      uStack_6c = 0x787d89ab4969d1e6;
      local_64 = 0xfea3e3bc;
      local_98 = (int)param_1;
      iVar3 = IoWMIWriteEvent(&local_88);
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar9 = '\0';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffefc,in_stack_fffffffffffffef8),4,10,
                     &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar3);
        }
      }
    }
    iVar3 = HdaController::PowerUp(this);
    if (-1 < iVar3) goto LAB_140004263;
  }
  else {
LAB_140004263:
    *(undefined1 *)(lVar5 + 0x43) = 0;
    HdaController::MarkCodecsPresent(this,1 << (local_38._2_1_ & 0x1f));
    if (*(char *)(lVar1 + 0xbe) != '\0') {
      pWVar6 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01025 + 0x6e8))(WdfDriverGlobals);
      iVar3 = HdAudBusUpdateS0IdleSettings(pWVar6,'\0');
      if (iVar3 < 0) goto LAB_140004408;
    }
    uVar7 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
    uVar8 = (**(code **)(WdfFunctions_01025 + 0x6e8))(WdfDriverGlobals,param_1);
    local_c0 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,uVar8);
    local_c8 = 0x28;
    local_b8 = 2;
    local_a8 = 0;
    local_b0 = 0;
    iVar4 = PcAddStreamResource(uVar7,0,&local_c8,lVar5 + 0x38);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
         (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar9 = '\0';
      }
      if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_fffffffffffffefc,in_stack_fffffffffffffef8),0xd,0x2a,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar4);
      }
    }
  }
LAB_140004408:
  IoReleaseRemoveLockEx(this + 8,param_1,0x20);
LAB_140004428:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     ((int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((iVar3 >> 0x1f & 0xfffffffeU) + 4))) {
    bVar2 = false;
  }
  if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_fffffffffffffefc,in_stack_fffffffffffffef8),2,0x2b,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar10,(char)iVar3);
  }
  return iVar3;
}



===== PowerUp @ 140004774 =====

/* public: long __cdecl HdaController::PowerUp(void) __ptr64 */

long __thiscall HdaController::PowerUp(HdaController *this)

{
  undefined1 uVar1;
  ushort uVar2;
  long lVar3;
  char cVar4;
  ulong uVar5;
  HdaController *pHVar6;
  longlong lVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 in_stack_ffffffffffffffac;
  
  uVar9 = 1;
  HDABusWmiLogETW(1,2,'\x04','\x02',1,0,0,0);
  if ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) == 0) {
    uVar8 = *(ushort *)(*(longlong *)(this + 0x58) + 0xe) & 0x7fff;
    *(uint *)(this + 0x94ac) = uVar8;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_ffffffffffffffac,uVar9),2,0x51,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)uVar8);
    }
  }
  else {
    *(undefined4 *)(this + 0x94ac) = 0;
  }
  uVar9 = 1;
  HDABusWmiLogETW(1,2,'\x04','\x02',1,0,1,0);
  lVar3 = ResetController(this);
  if (lVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_ffffffffffffffac,uVar9),2,0x52,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
LAB_140004a66:
    uVar5 = 0xc0000001;
  }
  else {
    uVar9 = 1;
    HDABusWmiLogETW(1,2,'\x04','\x02',1,0,2,0);
    lVar3 = RestoreRegisters(this);
    if (lVar3 < 0) goto LAB_140004a66;
    LOCK();
    *(undefined4 *)(this + 0x120) = 0;
    UNLOCK();
    uVar1 = KfRaiseIrql(2);
    for (uVar8 = 0;
        uVar8 < (uint)(*(int *)(this + 0x16c) + *(int *)(this + 0x170) + *(int *)(this + 0x168));
        uVar8 = uVar8 + 1) {
      lVar7 = (ulonglong)uVar8 * 0xd8;
      pHVar6 = this + lVar7 + 0x200;
      KeAcquireSpinLockAtDpcLevel(pHVar6);
      if (this[lVar7 + 0x20c] != (HdaController)0x0) {
        uVar2 = ProbeForFifoSize(this,uVar8);
        if (uVar2 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
             (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar4 = '\0';
          }
          if ((cVar4 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT44(in_stack_ffffffffffffffac,uVar9),2,0x53,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
             (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar4 = '\0';
          }
          if ((cVar4 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT44(in_stack_ffffffffffffffac,uVar9),2,0x54,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
          KeReleaseSpinLockFromDpcLevel(pHVar6);
          uVar5 = 0xc0000001;
          goto LAB_140004963;
        }
        if (*(int *)(this + lVar7 + 0x268) == 1) {
          ProgramDmaEngine(this,uVar8);
        }
        if (*(int *)(this + lVar7 + 0x268) == 2) {
          ProgramDmaEngine(this,uVar8);
          SetDmaEngineState(this,uVar8,'\x01');
        }
      }
      KeReleaseSpinLockFromDpcLevel(pHVar6);
    }
    uVar5 = 0;
LAB_140004963:
    KeLowerIrql(uVar1);
    if (-1 < (int)uVar5) goto LAB_14000497a;
  }
  LOCK();
  *(int *)(this + 0x120) = *(int *)(this + 0x120) + 1;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_stack_ffffffffffffffac,uVar9),
               2,0x55,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)uVar5);
  }
LAB_14000497a:
  HDABusWmiLogETW(1,2,'\x04','\x02',1,0xff,0,uVar5);
  return uVar5;
}



===== WPP_RECORDER_AND_TRACE_SF_q @ 140004bc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_q
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,param_6,param_8,param_7,&param_9,8,0);
  }
  return;
}



===== HDABusWmiLogETW @ 140004c80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl HDABusWmiLogETW(unsigned long,unsigned long,unsigned char,unsigned char,unsigned
   long,unsigned long,unsigned long,unsigned long) */

long __cdecl
HDABusWmiLogETW(ulong param_1,ulong param_2,uchar param_3,uchar param_4,ulong param_5,ulong param_6,
               ulong param_7,ulong param_8)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 auStackY_c8 [32];
  undefined8 in_stack_ffffffffffffff58;
  undefined8 local_78;
  undefined8 uStack_70;
  ulong local_68;
  undefined4 local_58;
  uchar local_54;
  uchar uStack_53;
  undefined2 uStack_52;
  __uint64 _Stack_50;
  undefined4 uStack_48;
  longlong local_44;
  undefined8 uStack_3c;
  ulonglong local_34;
  undefined4 uStack_2c;
  undefined8 *puStack_28;
  undefined4 uStack_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  uStack_20 = 0;
  local_58 = 0;
  local_54 = '\0';
  uStack_53 = '\0';
  uStack_52 = 0;
  _Stack_50 = 0;
  uStack_48 = 0;
  local_1c = 0;
  local_44 = 0;
  uStack_3c = 0;
  local_68 = 0;
  local_34 = 0;
  uStack_2c = 0;
  puStack_28 = (undefined8 *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  if ((HDAudBusWmiLoggerEnableFlags & param_2) == 0) {
    return 0;
  }
  if (HDAudBusWmiLoggerEnableLevel < param_3) {
    return 0;
  }
  if (param_1 == 1) {
    uVar3 = 0xe7ad130f;
    uVar4 = 0x4969d1e6;
    uVar5 = 0x787d89ab;
    uVar6 = 0xfea3e3bc;
  }
  else {
    if (param_1 != 2) {
      iVar1 = -0x3ffffff3;
      goto LAB_140004d80;
    }
    uVar3 = 0xaef818d8;
    uVar4 = 0x4fb20878;
    uVar5 = 0x685376a7;
    uVar6 = 0xa17ab383;
  }
  local_78 = CONCAT44(param_5,(uint)param_4);
  uStack_70 = CONCAT44(param_7,param_6);
  local_68 = param_8;
  puStack_28 = &local_78;
  local_58 = 0x40;
  uStack_20 = 0x14;
  uStack_2c = 0x120000;
  local_44 = (ulonglong)uVar3 << 0x20;
  uStack_3c = CONCAT44(uVar5,uVar4);
  local_34 = (ulonglong)uVar6;
  local_54 = param_4;
  uStack_53 = param_3;
  _Stack_50 = HDAudBusWmiLoggerHandle;
  iVar1 = IoWMIWriteEvent(&local_58);
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_140004d80:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,4,10,
               &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== ResetController @ 140004e08 =====

/* private: long __cdecl HdaController::ResetController(void) __ptr64 */

long __thiscall HdaController::ResetController(HdaController *this)

{
  ulonglong uVar1;
  char cVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 uVar7;
  undefined4 in_stack_ffffffffffffffcc;
  undefined2 uVar8;
  undefined1 uVar9;
  
  iVar4 = 400;
  uVar7 = 1;
  iVar5 = 400;
  HDABusWmiLogETW(1,4,'\x04','\x04',1,0,0,0);
  uVar1 = Feature_Servicing_HdAudBusResetTimeout__private_IsEnabledDeviceUsageNoInline();
  *(uint *)(*(longlong *)(this + 0x58) + 8) = *(uint *)(*(longlong *)(this + 0x58) + 8) & 0xfffffffe
  ;
  if ((int)uVar1 == 0) {
    LOCK();
    UNLOCK();
    while ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) != 0) {
      if (iVar5 == 0) goto LAB_14000508a;
      KeStallExecutionProcessor(1);
      iVar5 = iVar5 + -1;
    }
    *(uint *)(*(longlong *)(this + 0x58) + 8) = *(uint *)(*(longlong *)(this + 0x58) + 8) | 1;
    LOCK();
    UNLOCK();
    while ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) == 0) {
      if (iVar4 == 0) goto LAB_14000508a;
      KeStallExecutionProcessor(1);
      iVar4 = iVar4 + -1;
    }
  }
  else {
    LOCK();
    UNLOCK();
    while ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) != 0) {
      if (iVar5 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\x01';
        }
        bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar2 == '\0') && (!bVar6)) goto LAB_14000508a;
        uVar9 = 0x90;
        uVar8 = 0x13;
        goto LAB_140004f1c;
      }
      KeStallExecutionProcessor(1);
      iVar5 = iVar5 + -1;
    }
    *(uint *)(*(longlong *)(this + 0x58) + 8) = *(uint *)(*(longlong *)(this + 0x58) + 8) | 1;
    LOCK();
    UNLOCK();
    while ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) == 0) {
      if (iVar4 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\x01';
        }
        bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar2 != '\0') || (bVar6)) {
          uVar9 = 0x10;
          uVar8 = 0x14;
LAB_140004f1c:
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar6,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_ffffffffffffffcc,uVar7),0xd,uVar8,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)this,uVar9);
        }
LAB_14000508a:
        uVar3 = 0xc00000b5;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\x01';
        }
        if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_ffffffffffffffcc,uVar7),0xd,0x15,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xb5);
        }
        goto LAB_140004f64;
      }
      KeStallExecutionProcessor(0x19);
      iVar4 = iVar4 + -1;
    }
  }
  uVar3 = 0;
LAB_140004f64:
  HDABusWmiLogETW(1,4,'\x04','\x04',1,0xff,0,uVar3);
  return uVar3;
}



===== CodecDpc @ 140005100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static void __cdecl HdaController::CodecDpc(struct _KDPC * __ptr64,void * __ptr64,void *
   __ptr64,void * __ptr64) */

void __cdecl HdaController::CodecDpc(_KDPC *param_1,void *param_2,void *param_3,void *param_4)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  undefined1 auStackY_d8 [32];
  undefined8 in_stack_ffffffffffffff48;
  undefined4 local_78;
  undefined8 local_74;
  undefined8 local_6c;
  undefined2 local_58;
  undefined2 local_56;
  undefined2 local_54;
  undefined2 uStack_52;
  __uint64 _Stack_50;
  undefined4 uStack_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined8 local_34;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  uStack_20 = 0;
  local_1c = 0;
  local_56 = 0;
  local_54 = 0;
  uStack_52 = 0;
  uStack_48 = 0;
  local_44 = 0;
  uStack_3c = 0;
  local_34 = 0;
  uStack_2c = 0;
  _Stack_50 = 0;
  puStack_28 = (undefined4 *)0x0;
  if (((HDAudBusWmiLoggerEnableFlags & 4) != 0) &&
     (_Stack_50 = 0, puStack_28 = (undefined4 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
    puStack_28 = &local_78;
    local_78 = 3;
    local_74 = 5;
    local_58 = 0x40;
    local_6c = 0;
    uStack_20 = 0x14;
    uStack_2c = 0x120000;
    local_54 = 0x503;
    local_44 = 0xe7ad130f00000000;
    uStack_3c = 0x787d89ab4969d1e6;
    local_34 = 0xfea3e3bc;
    _Stack_50 = HDAudBusWmiLoggerHandle;
    iVar1 = IoWMIWriteEvent(&local_58);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar2 = '\0';
      }
      else {
        cVar2 = '\x01';
      }
      if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff48,4,10,
                   &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar1);
      }
    }
  }
  LOCK();
  bVar3 = *(int *)((longlong)param_2 + 0x949c) == 0;
  if (bVar3) {
    *(int *)((longlong)param_2 + 0x949c) = 0;
  }
  UNLOCK();
  if (bVar3) {
    ProcessCodecResponses(param_2);
  }
  else {
    if ((uint)*(byte *)(*(longlong *)((longlong)param_2 + 0x58) + 0x4a) !=
        *(byte *)((longlong)param_2 + 200) - 1) {
      return;
    }
    LOCK();
    if (*(int *)((longlong)param_2 + 0x949c) == 1) {
      *(int *)((longlong)param_2 + 0x949c) = 0;
    }
    UNLOCK();
    HandleRirbFifoOverrun(param_2);
  }
  ProcessCodecTransferList(param_2);
  return;
}



===== TransferCodecVerbs @ 1400052f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl HdaBusInterface::TransferCodecVerbs(void * __ptr64,unsigned
   long,struct _HDAUDIO_CODEC_TRANSFER * __ptr64,void (__cdecl*)(struct _HDAUDIO_CODEC_TRANSFER *
   __ptr64,void * __ptr64),void * __ptr64) */

long __cdecl
HdaBusInterface::TransferCodecVerbs
          (void *param_1,ulong param_2,_HDAUDIO_CODEC_TRANSFER *param_3,
          _func_void__HDAUDIO_CODEC_TRANSFER_ptr_void_ptr *param_4,void *param_5)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  _ChildDeviceExtension *p_Var4;
  char cVar5;
  ulonglong uVar6;
  HdaController *this;
  undefined1 auStackY_a8 [32];
  _func_void__HDAUDIO_CODEC_TRANSFER_ptr_void_ptr *in_stack_ffffffffffffff78;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  this = (HdaController *)0x0;
  if (param_1 == (void *)0x0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    if ((((*(longlong *)((longlong)param_1 + 0x888) != 0) &&
         (*(longlong *)(*(longlong *)((longlong)param_1 + 0x888) + 0x10) != 0)) &&
        (*(longlong *)((longlong)param_1 + 0x880) != 0)) &&
       (lVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                          (WdfDriverGlobals,*(longlong *)((longlong)param_1 + 0x880),
                           PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070), lVar3 != 0)) {
      lVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),
                         PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
      KeAcquireSpinLockRaiseToDpc(lVar3);
      this = *(HdaController **)(lVar3 + 0x30);
      if (this != (HdaController *)0x0) {
        LOCK();
        *(int *)this = *(int *)this + 1;
        UNLOCK();
        KeReleaseSpinLock();
        LOCK();
        *(int *)this = *(int *)this + 1;
        UNLOCK();
        LOCK();
        iVar2 = *(int *)this;
        *(int *)this = *(int *)this + -1;
        UNLOCK();
        if (iVar2 == 1) {
          HdaController::~HdaController(this);
          ExFreePoolWithTag(this,0);
        }
        local_38 = 0;
        uStack_40 = 0;
        local_48 = 0x18;
        (**(code **)(WdfFunctions_01025 + 0x6f0))
                  (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),&local_48);
        for (uVar6 = 0; (uint)uVar6 < param_2; uVar6 = (ulonglong)((uint)uVar6 + 1)) {
          if ((byte)((uint)*(undefined4 *)(param_3 + uVar6 * 0x10) >> 0x1c) != local_38._2_1_) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar5 = '\0';
            }
            else {
              cVar5 = '\x01';
            }
            if ((cVar5 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,4,0xe,
                         &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids);
            }
            iVar2 = -0x3ffffebf;
            goto LAB_14000552e;
          }
        }
        p_Var4 = (_ChildDeviceExtension *)
                 (**(code **)(WdfFunctions_01025 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),
                            PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
        in_stack_ffffffffffffff78 =
             (_func_void__HDAUDIO_CODEC_TRANSFER_ptr_void_ptr *)
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffff78 >> 0x20),0x20);
        iVar2 = IoAcquireRemoveLockEx(this + 8,param_1,"",1);
        if (iVar2 == 0) {
          iVar2 = HdaController::TransferCodecVerbs(this,p_Var4,param_2,param_3,param_4,param_5);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
          in_stack_ffffffffffffff78 = param_4;
        }
        if (-1 < iVar2) goto LAB_140005561;
        goto LAB_14000552e;
      }
      KeReleaseSpinLock(lVar3);
    }
    iVar2 = -0x3ffffff0;
  }
LAB_14000552e:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,4,0xf,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar2);
  }
  if (this == (HdaController *)0x0) {
    return iVar2;
  }
LAB_140005561:
  LOCK();
  iVar1 = *(int *)this;
  *(int *)this = *(int *)this + -1;
  UNLOCK();
  if (iVar1 == 1) {
    HdaController::~HdaController(this);
    ExFreePoolWithTag(this,0);
  }
  return iVar2;
}



===== TransferCodecVerbs @ 1400056d0 =====

/* public: long __cdecl HdaController::TransferCodecVerbs(struct _ChildDeviceExtension *
   __ptr64,unsigned long,struct _HDAUDIO_CODEC_TRANSFER * __ptr64,void (__cdecl*)(struct
   _HDAUDIO_CODEC_TRANSFER * __ptr64,void * __ptr64),void * __ptr64) __ptr64 */

long __thiscall
HdaController::TransferCodecVerbs
          (HdaController *this,_ChildDeviceExtension *param_1,ulong param_2,
          _HDAUDIO_CODEC_TRANSFER *param_3,_func_void__HDAUDIO_CODEC_TRANSFER_ptr_void_ptr *param_4,
          void *param_5)

{
  int iVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  undefined8 *puVar5;
  HdaController *pHVar6;
  char cVar7;
  uchar local_res8 [8];
  undefined8 in_stack_ffffffffffffff88;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_res8[0] = '\0';
  LOCK();
  *(int *)(this + 0x124) = *(int *)(this + 0x124) + 1;
  UNLOCK();
  pHVar6 = this;
  if ((param_4 == (_func_void__HDAUDIO_CODEC_TRANSFER_ptr_void_ptr *)0x0) &&
     (bVar2 = KeGetCurrentIrql(), 1 < bVar2)) {
LAB_1400059f3:
    lVar3 = -0x3ffffff3;
  }
  else {
    in_stack_ffffffffffffff88 =
         CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),param_2);
    lVar3 = IsCommandProcessingDisabled
                      (pHVar6,*(WDFDEVICE__ **)(this + 0x70),param_1,param_3,param_2,local_res8);
    if (-1 < lVar3) {
      lVar3 = 0;
      iVar4 = 0;
      LOCK();
      iVar1 = *(int *)(this + 0x120);
      if (iVar1 == 0) {
        *(int *)(this + 0x120) = 0;
      }
      else {
        iVar4 = iVar1;
      }
      UNLOCK();
      if ((iVar4 < 1) && (local_res8[0] == '\0')) {
        if (param_2 == 0) goto LAB_1400059f3;
        puVar5 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x50,0x44427a41);
        if (puVar5 != (undefined8 *)0x0) {
          *puVar5 = 0;
          puVar5[1] = 0;
          *(undefined4 *)((longlong)puVar5 + 0x24) = 0;
          puVar5[9] = 0;
          puVar5[2] = param_1;
          puVar5[3] = 0;
          puVar5[5] = param_3;
          *(ulong *)(puVar5 + 4) = param_2;
          puVar5[6] = &local_48;
          puVar5[8] = param_5;
          puVar5[7] = param_4;
          KeInitializeEvent(&local_48,0,0);
          ExpInterlockedPushEntrySList(this + 0xd0,puVar5);
          LOCK();
          pHVar6 = this + 0xe8;
          iVar1 = *(int *)pHVar6;
          *(int *)pHVar6 = *(int *)pHVar6 + 1;
          UNLOCK();
          if (iVar1 == 0) {
            ProcessCodecTransferList(this);
          }
          if (param_4 == (_func_void__HDAUDIO_CODEC_TRANSFER_ptr_void_ptr *)0x0) {
            KeWaitForSingleObject(&local_48,0,0,0,0);
          }
          goto LAB_1400058bb;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
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
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xd,0x8c,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        lVar3 = -0x3fffffe9;
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0 ||
            ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
          cVar7 = '\0';
        }
        else {
          cVar7 = '\x01';
        }
        if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_dd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xd,0x8b,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,
                     (char)*(undefined4 *)(this + 0x120),local_res8[0]);
        }
        lVar3 = -0x3ffffff0;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xd,0x8d,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar3);
  }
LAB_1400058bb:
  LOCK();
  *(int *)(this + 0x124) = *(int *)(this + 0x124) + -1;
  UNLOCK();
  return lVar3;
}



===== IsCommandProcessingDisabled @ 140005a20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HdaController::IsCommandProcessingDisabled(struct WDFDEVICE__ *
   __ptr64,struct _ChildDeviceExtension * __ptr64,struct _HDAUDIO_CODEC_TRANSFER * __ptr64,unsigned
   long,unsigned char * __ptr64) __ptr64 */

long __thiscall
HdaController::IsCommandProcessingDisabled
          (HdaController *this,WDFDEVICE__ *param_1,_ChildDeviceExtension *param_2,
          _HDAUDIO_CODEC_TRANSFER *param_3,ulong param_4,uchar *param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined8 in_stack_ffffffffffffffc8;
  
  uVar1 = WdfDriverGlobals;
  lVar2 = WdfFunctions_01025;
  if ((((param_1 == (WDFDEVICE__ *)0x0) || (param_3 == (_HDAUDIO_CODEC_TRANSFER *)0x0)) ||
      (param_4 == 0)) || (param_5 == (uchar *)0x0)) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0xe3,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,0xd,0xe4,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xd);
    }
    return -0x3ffffff3;
  }
  *param_5 = '\0';
  lVar2 = (**(code **)(lVar2 + 0x650))(uVar1);
  if ((uint)(byte)param_2[0x40] == *(uint *)(lVar2 + 0x1e0)) {
    if (*(char *)(lVar2 + 0x1d0) == '\0') {
      if (param_2[0x41] == (_ChildDeviceExtension)0x0) goto LAB_140005a9e;
    }
    else if (param_2[0x41] != (_ChildDeviceExtension)0x0) goto LAB_140005a9e;
LAB_140005af6:
    *param_5 = '\x01';
  }
  else {
LAB_140005a9e:
    if ((*(char *)(lVar2 + 0x1d0) != '\0') && (*(char *)(lVar2 + 0x1e6) != '\0')) {
      for (uVar4 = 0; uVar4 < param_4; uVar4 = uVar4 + 1) {
        if (*(uint *)(param_3 + (ulonglong)uVar4 * 0x10) >> 0x1c == *(uint *)(lVar2 + 0x1e0))
        goto LAB_140005af6;
      }
    }
  }
  return 0;
}



===== ProcessCodecTransferList @ 140005be0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl HdaController::ProcessCodecTransferList(void) __ptr64 */

void __thiscall HdaController::ProcessCodecTransferList(HdaController *this)

{
  HdaController HVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined8 *puVar7;
  uint uVar8;
  char cVar9;
  longlong *plVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined1 local_1d8 [32];
  undefined4 in_stack_fffffffffffffe48;
  undefined4 in_stack_fffffffffffffe4c;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  uint local_138;
  undefined2 local_134;
  undefined2 uStack_132;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined8 local_124;
  undefined8 uStack_11c;
  undefined8 local_114;
  undefined4 uStack_10c;
  undefined8 uStack_108;
  undefined4 uStack_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_d0;
  _SLIST_HEADER local_c8;
  undefined4 local_b8;
  undefined2 local_b4;
  undefined2 uStack_b2;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined8 local_a4;
  undefined8 uStack_9c;
  undefined8 local_94;
  undefined4 uStack_8c;
  undefined8 uStack_88;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined2 local_74;
  undefined2 uStack_72;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined8 local_54;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_1d8;
  uVar4 = KeAcquireSpinLockRaiseToDpc(this + 0xf0);
  HVar1 = this[200];
  puVar7 = (undefined8 *)ExpInterlockedFlushSList(this + 0xd0);
  local_c8.s.Alignment = 0;
  local_c8.s.Region = 0;
  InitializeSListHead(&local_c8);
  while (puVar7 != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)*puVar7;
    ExpInterlockedPushEntrySList(&local_c8,puVar7);
    puVar7 = puVar3;
  }
  puVar7 = (undefined8 *)ExpInterlockedFlushSList(&local_c8);
  while (puVar7 != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)*puVar7;
    *puVar7 = 0;
    **(undefined8 **)(this + 0x110) = puVar7;
    *(undefined8 **)(this + 0x110) = puVar7;
    puVar7 = puVar3;
  }
  for (puVar7 = *(undefined8 **)(this + 0x100); puVar7 != (undefined8 *)0x0;
      puVar7 = (undefined8 *)*puVar7) {
    *(undefined4 *)(puVar7[2] + 0x44) = 0;
  }
  plVar10 = *(longlong **)(this + 0x100);
  uVar8 = 0;
  uVar11 = 0;
  uVar12 = 0x80;
  if (plVar10 != (longlong *)0x0) {
    do {
      if (*(uint *)(plVar10 + 3) < *(uint *)(plVar10 + 4)) {
        if (*(int *)(plVar10[2] + 0x44) == 0) {
          *(undefined4 *)(plVar10[2] + 0x44) = 0x80;
          uVar8 = uVar8 + 1;
        }
        uVar11 = uVar11 + ((int)plVar10[4] - (int)plVar10[3]);
      }
      plVar10 = (longlong *)*plVar10;
    } while (plVar10 != (longlong *)0x0);
    if (0x80 < uVar11) {
      puVar7 = *(undefined8 **)(this + 0x100);
      iVar5 = (int)(0x80 / (ulonglong)uVar8);
      iVar6 = 1;
      if (iVar5 != 0) {
        iVar6 = iVar5;
      }
      for (; puVar7 != (undefined8 *)0x0; puVar7 = (undefined8 *)*puVar7) {
        *(int *)(puVar7[2] + 0x44) = iVar6;
      }
    }
  }
  puVar7 = *(undefined8 **)(this + 0x100);
  while ((puVar7 != (undefined8 *)0x0 && (uVar12 != 0))) {
    lVar2 = puVar7[2];
    uVar11 = *(uint *)(lVar2 + 0x44);
    if (uVar11 != 0) {
      if (*(uint *)(puVar7 + 3) < *(uint *)(puVar7 + 4)) {
        if (*(char *)((longlong)puVar7 + 0x24) == '\x01') {
          *(undefined4 *)(lVar2 + 0x44) = 0;
        }
        else {
          uVar8 = *(uint *)(puVar7 + 4) - *(uint *)(puVar7 + 3);
          if (uVar12 < uVar8) {
            uVar8 = uVar12;
          }
          if (uVar11 <= uVar8) {
            uVar8 = uVar11;
          }
          uVar12 = uVar12 - uVar8;
          *(uint *)(lVar2 + 0x44) = uVar11 - uVar8;
          *(HdaController *)((longlong)puVar7 + 0x25) = this[200];
          if (uVar8 != 0) {
            uVar13 = (ulonglong)uVar8;
            do {
              *(undefined4 *)(*(longlong *)(this + 0xb8) + (ulonglong)(byte)this[200] * 4) =
                   *(undefined4 *)(puVar7[5] + (ulonglong)*(uint *)(puVar7 + 3) * 0x10);
              this[200] = (HdaController)((char)this[200] + '\x01');
              *(int *)(puVar7 + 3) = *(int *)(puVar7 + 3) + 1;
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
          *(HdaController *)((longlong)puVar7 + 0x26) = this[200];
          *(undefined1 *)((longlong)puVar7 + 0x24) = 1;
        }
      }
    }
    puVar7 = (undefined8 *)*puVar7;
  }
  uStack_108 = (undefined4 *)CONCAT44(uStack_108._4_4_,(undefined4)uStack_108);
  if (HVar1 != this[200]) {
    uStack_80 = 0;
    local_7c = 0;
    uStack_e8 = 0;
    local_b8 = 0;
    local_b4 = 0;
    uStack_b2 = 0;
    uStack_b0 = 0;
    uStack_ac = 0;
    uStack_a8 = 0;
    local_a4 = 0;
    uStack_9c = 0;
    local_94 = 0;
    uStack_8c = 0;
    local_f8 = 0;
    uStack_f4 = 0;
    uStack_f0 = 0;
    uStack_ec = 0;
    uStack_88 = (undefined4 *)0x0;
    if (((HDAudBusWmiLoggerEnableFlags & 4) != 0) &&
       (uStack_88 = (undefined4 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
      uStack_88 = &local_f8;
      local_f8 = 3;
      uStack_b0 = (undefined4)HDAudBusWmiLoggerHandle;
      uStack_ac = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
      uStack_f4 = 9;
      uStack_f0 = 0;
      uStack_ec = 0;
      uStack_e8 = 0;
      uStack_80 = 0x14;
      local_b8 = 0x40;
      uStack_8c = 0x120000;
      local_b4 = 0x503;
      local_a4 = 0xe7ad130f00000000;
      uStack_9c = 0x787d89ab4969d1e6;
      local_94 = 0xfea3e3bc;
      iVar6 = IoWMIWriteEvent(&local_b8);
      if (iVar6 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar9 = '\0';
        }
        else {
          cVar9 = '\x01';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffe4c,in_stack_fffffffffffffe48),4,10,
                     &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
        }
      }
    }
    KeSetTimer(this + 0x128,(ulonglong)*(uint *)(this + 0x9498) * -10,this + 0x9418);
    local_78 = 0;
    uStack_40 = 0;
    local_3c = 0;
    local_d0 = 0;
    local_74 = 0;
    uStack_72 = 0;
    uStack_70 = 0;
    uStack_6c = 0;
    uStack_68 = 0;
    local_64 = 0;
    uStack_5c = 0;
    local_54 = 0;
    uStack_4c = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    uStack_48 = (undefined8 *)0x0;
    if (((HDAudBusWmiLoggerEnableFlags & 4) != 0) &&
       (uStack_48 = (undefined8 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
      uStack_48 = &local_e0;
      uStack_70 = (undefined4)HDAudBusWmiLoggerHandle;
      uStack_6c = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
      local_e0 = 0x900000003;
      uStack_d8 = 0xff;
      local_d0 = 0;
      uStack_40 = 0x14;
      local_78 = 0x40;
      uStack_4c = 0x120000;
      local_74 = 0x503;
      local_64 = 0xe7ad130f00000000;
      uStack_5c = 0x787d89ab4969d1e6;
      local_54 = 0xfea3e3bc;
      iVar6 = IoWMIWriteEvent(&local_78);
      if (iVar6 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar9 = '\0';
        }
        else {
          cVar9 = '\x01';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffe4c,in_stack_fffffffffffffe48),4,10,
                     &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
        }
      }
    }
    local_138 = 0;
    uStack_100 = 0;
    local_fc = 0;
    uStack_148 = 0;
    local_134 = 0;
    uStack_132 = 0;
    uStack_130 = 0;
    uStack_12c = 0;
    uStack_128 = 0;
    local_124 = 0;
    uStack_11c = 0;
    local_114 = 0;
    uStack_10c = 0;
    local_158 = 0;
    uStack_154 = 0;
    uStack_150 = 0;
    uStack_14c = 0;
    uStack_108 = (undefined4 *)0x0;
    if (((HDAudBusWmiLoggerEnableFlags & 2) != 0) &&
       (uStack_108 = (undefined4 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
      uStack_108 = &local_158;
      local_158 = 3;
      uStack_130 = (undefined4)HDAudBusWmiLoggerHandle;
      uStack_12c = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
      uStack_154 = 8;
      uStack_150 = 0;
      uStack_14c = 0;
      uStack_148 = 0;
      uStack_100 = 0x14;
      local_138 = 0x40;
      uStack_10c = 0x120000;
      local_134 = 0x503;
      local_124 = 0xe7ad130f00000000;
      uStack_11c = 0x787d89ab4969d1e6;
      local_114 = 0xfea3e3bc;
      iVar6 = IoWMIWriteEvent(&local_138);
      if (iVar6 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar9 = '\0';
        }
        else {
          cVar9 = '\x01';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffe4c,in_stack_fffffffffffffe48),4,10,
                     &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
        }
      }
    }
    *(char *)(*(longlong *)(this + 0x58) + 0x48) = (char)this[200] + -1;
    LOCK();
    UNLOCK();
    *(byte *)(*(longlong *)(this + 0x58) + 0x4c) = *(byte *)(*(longlong *)(this + 0x58) + 0x4c) | 2;
    LOCK();
    UNLOCK();
    iVar6 = 0x28;
    while ((*(byte *)(*(longlong *)(this + 0x58) + 0x4c) & 2) == 0) {
      if (iVar6 == 0) {
        in_stack_fffffffffffffe48 = 6;
        HDABusWmiLogETW(1,4,'\x04','\x03',6,0,0,0);
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar9 = '\0';
        }
        else {
          cVar9 = '\x01';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffe4c,in_stack_fffffffffffffe48),0xd,0x22,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xb5);
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar9 = '\0';
        }
        else {
          cVar9 = '\x01';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffe4c,in_stack_fffffffffffffe48),0xd,0x24,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        break;
      }
      KeStallExecutionProcessor();
      iVar6 = iVar6 + -1;
    }
    local_138 = local_138 & 0xffff;
    uStack_100 = 0;
    local_fc = 0;
    local_134 = 0;
    uStack_132 = 0;
    uStack_130 = 0;
    uStack_12c = 0;
    uStack_128 = 0;
    local_124 = 0;
    uStack_11c = 0;
    local_114 = 0;
    uStack_10c = 0;
    uStack_108 = (undefined4 *)0x0;
    if (((HDAudBusWmiLoggerEnableFlags & 2) != 0) &&
       (uStack_108 = (undefined4 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
      uStack_108 = &local_158;
      local_158 = 3;
      uStack_154 = 8;
      local_138 = 0x40;
      uStack_130 = (undefined4)HDAudBusWmiLoggerHandle;
      uStack_12c = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
      uStack_150 = 0xff;
      uStack_14c = 0;
      uStack_148 = 0;
      uStack_100 = 0x14;
      uStack_10c = 0x120000;
      local_134 = 0x503;
      local_124 = 0xe7ad130f00000000;
      uStack_11c = 0x787d89ab4969d1e6;
      local_114 = 0xfea3e3bc;
      iVar6 = IoWMIWriteEvent(&local_138);
      if (iVar6 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar9 = '\0';
        }
        else {
          cVar9 = '\x01';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_fffffffffffffe4c,in_stack_fffffffffffffe48),4,10,
                     &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
        }
      }
    }
  }
  KeReleaseSpinLock(this + 0xf0,uVar4);
  return;
}



===== HdAudBusSelfManagedIoInitAndRestart @ 140006490 =====

/* long __cdecl HdAudBusSelfManagedIoInitAndRestart(struct WDFDEVICE__ * __ptr64) */

long __cdecl HdAudBusSelfManagedIoInitAndRestart(WDFDEVICE__ *param_1)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x6d,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  return 0;
}



===== WPP_RECORDER_AND_TRACE_SF_D @ 140006514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_D
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,param_6,param_8,param_7,&param_9,4,0);
  }
  return;
}



===== CancelCorbEntries @ 1400065d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl HdaController::CancelCorbEntries(void) __ptr64 */

void __thiscall HdaController::CancelCorbEntries(HdaController *this)

{
  undefined1 uVar1;
  _SLIST_ENTRY *p_Var2;
  char cVar3;
  undefined8 *puVar4;
  FifoQueue *this_00;
  char cVar5;
  undefined4 uVar6;
  undefined4 in_stack_ffffffffffffffac;
  
  uVar6 = 2;
  HDABusWmiLogETW(1,2,'\x04','\x03',2,0,0,0);
  uVar1 = KeAcquireSpinLockRaiseToDpc(this + 0xf0);
  if (this[0xca] != this[200]) {
    do {
      for (puVar4 = *(undefined8 **)(this + 0x100); puVar4 != (undefined8 *)0x0;
          puVar4 = (undefined8 *)*puVar4) {
        while (*(char *)((longlong)puVar4 + 0x24) == '\x01') {
          if (*(char *)((longlong)puVar4 + 0x25) != *(char *)((longlong)puVar4 + 0x26)) {
            do {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 0x1000)) {
                cVar3 = '\0';
              }
              if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                 (cVar5 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
                cVar5 = '\0';
              }
              if ((cVar3 != '\0') || (cVar5 != '\0')) {
                WPP_RECORDER_AND_TRACE_SF_D
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar5,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                           CONCAT44(in_stack_ffffffffffffffac,uVar6),0xd,0x29,
                           &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,
                           (char)*(undefined4 *)
                                  (puVar4[5] + (ulonglong)*(uint *)((longlong)puVar4 + 0x1c) * 0x10)
                          );
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 0x1000)) {
                cVar3 = '\0';
              }
              if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                 (cVar5 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
                cVar5 = '\0';
              }
              if ((cVar3 != '\0') || (cVar5 != '\0')) {
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar5,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                           CONCAT44(in_stack_ffffffffffffffac,uVar6),0xd,0x2a,
                           &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
              }
              *(undefined8 *)(puVar4[5] + 8 + (ulonglong)*(uint *)((longlong)puVar4 + 0x1c) * 0x10)
                   = 0;
              *(int *)((longlong)puVar4 + 0x1c) = *(int *)((longlong)puVar4 + 0x1c) + 1;
              this[0xca] = (HdaController)((char)this[0xca] + '\x01');
              *(char *)((longlong)puVar4 + 0x25) = *(char *)((longlong)puVar4 + 0x25) + '\x01';
            } while (*(char *)((longlong)puVar4 + 0x25) != *(char *)((longlong)puVar4 + 0x26));
          }
          this_00 = (FifoQueue *)(this + 0x100);
          *(undefined2 *)((longlong)puVar4 + 0x24) = 0;
          if ((*(int *)(puVar4 + 3) != *(int *)(puVar4 + 4)) ||
             (*(int *)(puVar4 + 3) != *(int *)((longlong)puVar4 + 0x1c))) break;
          if ((code *)puVar4[7] == (code *)0x0) {
            KeSetEvent(puVar4[6],0,0);
          }
          else {
            (*(code *)puVar4[7])(puVar4[5],puVar4[8]);
          }
          LOCK();
          *(int *)(this + 0xe8) = *(int *)(this + 0xe8) + -1;
          UNLOCK();
          if (puVar4 != *(undefined8 **)this_00) break;
          do {
            p_Var2 = FifoQueue::Pop(this_00);
            operator_delete(p_Var2);
            puVar4 = *(undefined8 **)this_00;
            if (puVar4 == (undefined8 *)0x0) goto LAB_14000679f;
          } while ((*(int *)(puVar4 + 3) == *(int *)(puVar4 + 4)) &&
                  (*(int *)(puVar4 + 3) == *(int *)((longlong)puVar4 + 0x1c)));
        }
      }
LAB_14000679f:
    } while (this[0xca] != this[200]);
  }
  KeReleaseSpinLock(this + 0xf0,uVar1);
  return;
}



===== operator_delete @ 140006900 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== Pop @ 140006930 =====

/* public: struct _SLIST_ENTRY * __ptr64 __cdecl FifoQueue::Pop(void) __ptr64 */

_SLIST_ENTRY * __thiscall FifoQueue::Pop(FifoQueue *this)

{
  _SLIST_ENTRY *p_Var1;
  
  p_Var1 = *(_SLIST_ENTRY **)this;
  if (p_Var1 != (_SLIST_ENTRY *)0x0) {
    *(undefined8 *)this = *(undefined8 *)p_Var1;
  }
  if (*(_SLIST_ENTRY **)(this + 0x10) == p_Var1) {
    *(FifoQueue **)(this + 0x10) = this;
  }
  return p_Var1;
}



===== ProgramDmaEngine @ 140006950 =====

/* private: void __cdecl HdaController::ProgramDmaEngine(int) __ptr64 */

void __thiscall HdaController::ProgramDmaEngine(HdaController *this,int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 extraout_var;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar5 = (longlong)param_1 * 0xd8;
  cVar1 = (char)(*(longlong *)(this + lVar5 + 0x238) + 0xfffU >> 0xc);
  cVar3 = '\x02';
  if (cVar1 != '\x01') {
    cVar3 = cVar1;
  }
  lVar6 = ((ulonglong)(byte)param_1 + 4) * 0x20;
  *(byte *)(lVar6 + *(longlong *)(this + 0x58)) = *(byte *)(lVar6 + *(longlong *)(this + 0x58)) | 8;
  LOCK();
  UNLOCK();
  *(byte *)(lVar6 + *(longlong *)(this + 0x58)) =
       *(byte *)(lVar6 + *(longlong *)(this + 0x58)) | 0x10;
  LOCK();
  UNLOCK();
  *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
       1 << ((byte)param_1 & 0x1f) & 0x3fffffffU | *(uint *)(*(longlong *)(this + 0x58) + 0x20);
  LOCK();
  UNLOCK();
  lVar4 = (longlong)param_1 * 0x20;
  *(undefined4 *)(*(longlong *)(this + 0x58) + 0x88 + lVar4) = *(undefined4 *)(this + lVar5 + 0x238)
  ;
  LOCK();
  UNLOCK();
  if (this[0x9606] == (HdaController)0x0) {
    MmGetPhysicalAddress(*(undefined8 *)(this + lVar5 + 0x248));
    *(undefined4 *)(lVar4 + 0x9c + *(longlong *)(this + 0x58)) = extraout_var;
    LOCK();
    UNLOCK();
    uVar2 = MmGetPhysicalAddress(*(undefined8 *)(this + lVar5 + 0x248));
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x98 + lVar4) = uVar2;
  }
  else {
    *(undefined4 *)(lVar4 + 0x9c + *(longlong *)(this + 0x58)) =
         *(undefined4 *)(this + lVar5 + 0x254);
    LOCK();
    UNLOCK();
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x98 + lVar4) =
         *(undefined4 *)(this + lVar5 + 0x250);
  }
  LOCK();
  UNLOCK();
  if (this[lVar5 + 0x26c] == (HdaController)0x0) {
    *(char *)(*(longlong *)(this + 0x58) + 0x8c + lVar4) = cVar3 + -1;
  }
  else {
    *(HdaController *)(*(longlong *)(this + 0x58) + 0x8c + lVar4) = this[lVar5 + 0x26e];
    LOCK();
    UNLOCK();
    if ((*(longlong *)(this + lVar5 + 0x298) == 0) && (*(longlong *)(this + lVar5 + 0x2a0) == 0))
    goto LAB_140006afb;
    *(byte *)(lVar6 + *(longlong *)(this + 0x58)) =
         *(byte *)(lVar6 + *(longlong *)(this + 0x58)) | 4;
  }
  LOCK();
  UNLOCK();
LAB_140006afb:
  this[lVar5 + 0x20d] = (HdaController)0x1;
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_d @ 140006b24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_d
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,param_6,param_8,param_7,&param_9,4,0);
  }
  return;
}



===== GetLinkPositionRegister @ 140006bd4 =====

/* public: long __cdecl HdaController::GetLinkPositionRegister(struct WDFDEVICE__ *
   __ptr64,long,unsigned long * __ptr64 * __ptr64) __ptr64 */

long __thiscall
HdaController::GetLinkPositionRegister
          (HdaController *this,WDFDEVICE__ *param_1,long param_2,ulong **param_3)

{
  bool bVar1;
  char cVar2;
  long lVar3;
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((uint)param_2 < 0x1e) {
    *param_3 = (ulong *)(*(longlong *)(this + 0x60) + 0x84 + (longlong)(param_2 << 5));
    lVar3 = 0;
  }
  else {
    bVar1 = true;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,0xe,0x86,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar3 = -0x3ffffff8;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,0xe,0x87,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,8);
    }
  }
  return lVar3;
}



===== AllocateCaptureDmaEngine @ 140006d00 =====

/* public: static long __cdecl HdaBusInterface::AllocateCaptureDmaEngine(void * __ptr64,unsigned
   char,struct _HDAUDIO_STREAM_FORMAT * __ptr64,void * __ptr64 * __ptr64,struct
   _HDAUDIO_CONVERTER_FORMAT * __ptr64) */

long __cdecl
HdaBusInterface::AllocateCaptureDmaEngine
          (void *param_1,uchar param_2,_HDAUDIO_STREAM_FORMAT *param_3,void **param_4,
          _HDAUDIO_CONVERTER_FORMAT *param_5)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  void *pvVar4;
  long local_res8 [2];
  long *in_stack_ffffffffffffff98;
  HdaController *local_38 [2];
  
  local_res8[0] = -1;
  local_38[0] = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)local_38);
    this = local_38[0];
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      in_stack_ffffffffffffff98 =
           (long *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff98 >> 0x20),0x20);
      iVar3 = IoAcquireRemoveLockEx(local_38[0] + 8,param_1,"",1);
      if (iVar3 == 0) {
        in_stack_ffffffffffffff98 = local_res8;
        iVar3 = HdaController::AllocateCaptureDmaEngine
                          (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),param_2,param_3,
                           in_stack_ffffffffffffff98,param_5);
        IoReleaseRemoveLockEx(this + 8,param_1,0x20);
      }
      if (-1 < iVar3) {
        pvVar4 = CreateHandleFromLong(param_1,local_res8[0]);
        *param_4 = pvVar4;
        goto LAB_140006e3e;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,0x10,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_140006e3e:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)local_38);
  return iVar3;
}



===== AllocateCaptureDmaEngine @ 140006e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HdaController::AllocateCaptureDmaEngine(struct WDFDEVICE__ *
   __ptr64,unsigned char,struct _HDAUDIO_STREAM_FORMAT * __ptr64,long * __ptr64,struct
   _HDAUDIO_CONVERTER_FORMAT * __ptr64) __ptr64 */

long __thiscall
HdaController::AllocateCaptureDmaEngine
          (HdaController *this,WDFDEVICE__ *param_1,uchar param_2,_HDAUDIO_STREAM_FORMAT *param_3,
          long *param_4,_HDAUDIO_CONVERTER_FORMAT *param_5)

{
  bool bVar1;
  byte bVar2;
  uchar uVar3;
  undefined1 uVar4;
  HdaController HVar5;
  ushort uVar6;
  long lVar7;
  int iVar8;
  InputLinkBandwidth *this_00;
  HdaController *pHVar9;
  char cVar10;
  longlong lVar11;
  uint uVar12;
  uint uVar13;
  HdaController *pHVar14;
  bool bVar15;
  undefined2 in_stack_ffffffffffffff88;
  undefined6 in_stack_ffffffffffffff8a;
  uint in_stack_ffffffffffffff90;
  undefined2 uVar16;
  long local_44;
  HdaController *local_40;
  
  local_44 = 0;
  bVar2 = 0;
  bVar1 = true;
  if (param_2 < 0xf) {
    if (((param_3 == (_HDAUDIO_STREAM_FORMAT *)0x0) || (param_5 == (_HDAUDIO_CONVERTER_FORMAT *)0x0)
        ) || (param_4 == (long *)0x0)) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar10 = '\0';
      }
      else {
        cVar10 = '\x01';
      }
      bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar10 != '\0') || (bVar15)) {
        uVar16 = 0x57;
        goto LAB_140006f2a;
      }
    }
    else {
      lVar7 = BuildHDAudioConverterFormat(this,param_3,param_5);
      if (-1 < lVar7) {
        this_00 = GetInputLinkBandwidth(this,param_2);
        if (this_00 == (InputLinkBandwidth *)0x0) {
          iVar8 = -0x3ffffff2;
        }
        else {
          in_stack_ffffffffffffff88 = *(undefined2 *)(param_3 + 4);
          iVar8 = (*(code *)**(undefined8 **)this_00)
                            (this_00,&local_44,(byte)param_5[1] & 0x7f,*(undefined2 *)(param_3 + 8),
                             in_stack_ffffffffffffff88,in_stack_ffffffffffffff90 & 0xffffff00);
          if (-1 < iVar8) {
            uVar3 = LinkBandwidth::CommitBandwidth((LinkBandwidth *)this_00,local_44);
            if (uVar3 == '\0') {
              iVar8 = -0x3fffff66;
            }
            else {
              uVar4 = KfRaiseIrql(2);
              LOCK();
              pHVar14 = this + 0x1b50;
              iVar8 = *(int *)pHVar14;
              *(int *)pHVar14 = *(int *)pHVar14 + 1;
              UNLOCK();
              if (iVar8 + 1 < 0x10) {
                for (uVar12 = 0; uVar12 < *(uint *)(this + 0x168); uVar12 = uVar12 + 1) {
                  lVar11 = (ulonglong)uVar12 * 0xd8;
                  pHVar14 = this + lVar11 + 0x200;
                  KeAcquireSpinLockAtDpcLevel(pHVar14);
                  if (this[lVar11 + 0x20c] == (HdaController)0x0) {
                    pHVar9 = this + 0x1f8;
                    local_40 = pHVar9;
                    KeAcquireSpinLockAtDpcLevel();
                    *(long *)(this + lVar11 + 0x210) = local_44;
                    this[lVar11 + 0x214] = (HdaController)param_2;
                    this[lVar11 + 0x20c] = (HdaController)0x1;
                    this[lVar11 + 0x20f] = (HdaController)0x0;
                    HVar5 = (HdaController)FindStreamId(pHVar9,(long *)(this + 0x1b54));
                    this[lVar11 + 0x215] = HVar5;
                    *(undefined8 *)(this + lVar11 + 600) = *(undefined8 *)param_3;
                    *(undefined4 *)(this + lVar11 + 0x260) = *(undefined4 *)(param_3 + 8);
                    uVar16 = *(undefined2 *)param_5;
                    *(undefined4 *)(this + lVar11 + 0x268) = 0;
                    *(undefined2 *)(this + lVar11 + 0x264) = uVar16;
                    *(WDFDEVICE__ **)(this + lVar11 + 0x2d0) = param_1;
                    ResetDmaEngine(this,uVar12);
                    uVar6 = ProbeForFifoSize(this,uVar12);
                    iVar8 = ((*(ushort *)param_5 >> 0xb & 7) + 1) * (uint)*(ushort *)(param_3 + 6) *
                            (uint)*(ushort *)(param_3 + 8);
                    if (iVar8 / 8 <= (int)(uint)uVar6) {
                      *param_4 = uVar12;
                      KeReleaseSpinLockFromDpcLevel(local_40,(longlong)iVar8 % 8 & 0xffffffff);
                      goto LAB_140007299;
                    }
                    pHVar9 = this;
                    ResetDmaEngine(this,uVar12);
                    FreeStreamId(pHVar9,(long *)(this + 0x1b54),(uchar)this[lVar11 + 0x215]);
                    *(undefined4 *)(this + lVar11 + 0x210) = 0;
                    this[lVar11 + 0x215] = (HdaController)0x0;
                    *(undefined8 *)(this + lVar11 + 0x2d0) = 0;
                    this[lVar11 + 0x20c] = (HdaController)0x0;
                    KeReleaseSpinLockFromDpcLevel(this + 0x1f8);
                    KeReleaseSpinLockFromDpcLevel(pHVar14);
                    bVar2 = 1;
                  }
                  else {
                    KeReleaseSpinLockFromDpcLevel(pHVar14);
                  }
                }
                for (uVar12 = 0; uVar12 < *(uint *)(this + 0x170); uVar12 = uVar12 + 1) {
                  uVar13 = *(int *)(this + 0x16c) + *(int *)(this + 0x168) + uVar12;
                  lVar11 = (ulonglong)uVar13 * 0xd8;
                  pHVar14 = this + lVar11 + 0x200;
                  KeAcquireSpinLockAtDpcLevel(pHVar14);
                  if (this[lVar11 + 0x20c] == (HdaController)0x0) {
                    pHVar9 = this + 0x1f8;
                    local_40 = pHVar9;
                    KeAcquireSpinLockAtDpcLevel();
                    *(long *)(this + lVar11 + 0x210) = local_44;
                    this[lVar11 + 0x214] = (HdaController)param_2;
                    *(undefined4 *)(this + lVar11 + 0x208) = 3;
                    this[lVar11 + 0x20c] = (HdaController)0x1;
                    this[lVar11 + 0x20f] = (HdaController)0x0;
                    HVar5 = (HdaController)FindStreamId(pHVar9,(long *)(this + 0x1b54));
                    this[lVar11 + 0x215] = HVar5;
                    *(undefined8 *)(this + lVar11 + 600) = *(undefined8 *)param_3;
                    *(undefined4 *)(this + lVar11 + 0x260) = *(undefined4 *)(param_3 + 8);
                    uVar16 = *(undefined2 *)param_5;
                    *(undefined4 *)(this + lVar11 + 0x268) = 0;
                    *(undefined2 *)(this + lVar11 + 0x264) = uVar16;
                    *(WDFDEVICE__ **)(this + lVar11 + 0x2d0) = param_1;
                    ResetDmaEngine(this,uVar13);
                    uVar6 = ProbeForFifoSize(this,uVar12);
                    iVar8 = ((*(ushort *)param_5 >> 0xb & 7) + 1) * (uint)*(ushort *)(param_3 + 6) *
                            (uint)*(ushort *)(param_3 + 8);
                    if ((int)(uint)uVar6 < iVar8 / 8) {
                      pHVar9 = this;
                      ResetDmaEngine(this,uVar13);
                      FreeStreamId(pHVar9,(long *)(this + 0x1b54),(uchar)this[lVar11 + 0x215]);
                      *(undefined4 *)(this + lVar11 + 0x210) = 0;
                      *(undefined8 *)(this + lVar11 + 0x2d0) = 0;
                      this[lVar11 + 0x215] = (HdaController)0x0;
                      *(undefined4 *)(this + lVar11 + 0x208) = 2;
                      this[lVar11 + 0x20c] = (HdaController)0x0;
                      KeReleaseSpinLockFromDpcLevel(this + 0x1f8);
                      KeReleaseSpinLockFromDpcLevel(pHVar14);
                      bVar2 = 1;
                      goto LAB_140007470;
                    }
                    *param_4 = uVar13;
                    KeReleaseSpinLockFromDpcLevel(local_40,(longlong)iVar8 % 8 & 0xffffffff);
LAB_140007299:
                    KeReleaseSpinLockFromDpcLevel(pHVar14);
                    iVar8 = 0;
                    goto LAB_1400074cc;
                  }
                  KeReleaseSpinLockFromDpcLevel(pHVar14);
LAB_140007470:
                }
                LinkBandwidth::FreeBandwidth((LinkBandwidth *)this_00,local_44);
                LOCK();
                *(int *)(this + 0x1b50) = *(int *)(this + 0x1b50) + -1;
                UNLOCK();
                iVar8 = (-(uint)bVar2 & 0xffffff89) + 0xc000009a;
              }
              else {
                LOCK();
                *(int *)(this + 0x1b50) = *(int *)(this + 0x1b50) + -1;
                UNLOCK();
                iVar8 = -0x3fffff66;
              }
LAB_1400074cc:
              KeLowerIrql(uVar4);
              if (-1 < iVar8) {
                return iVar8;
              }
            }
          }
        }
        goto LAB_140006fea;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar10 = '\0';
      }
      else {
        cVar10 = '\x01';
      }
      bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar10 != '\0') || (bVar15)) {
        uVar16 = 0x58;
        goto LAB_140006f2a;
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    else {
      cVar10 = '\x01';
    }
    bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar10 != '\0') || (bVar15)) {
      uVar16 = 0x56;
LAB_140006f2a:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,bVar15,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT62(in_stack_ffffffffffffff8a,in_stack_ffffffffffffff88),0xe,uVar16,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
  }
  iVar8 = -0x3ffffff3;
LAB_140006fea:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT62(in_stack_ffffffffffffff8a,in_stack_ffffffffffffff88),0xe,0x59,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar8);
  }
  return iVar8;
}



===== GetInputLinkBandwidth @ 14000753c =====

/* private: class InputLinkBandwidth * __ptr64 __cdecl HdaController::GetInputLinkBandwidth(unsigned
   char) __ptr64 */

InputLinkBandwidth * __thiscall
HdaController::GetInputLinkBandwidth(HdaController *this,uchar param_1)

{
  HdaLinkInstance *pHVar1;
  InputLinkBandwidth *pIVar2;
  
  pHVar1 = GetLinkInstanceCapability(this,param_1);
  pIVar2 = (InputLinkBandwidth *)0x0;
  if (pHVar1 == (HdaLinkInstance *)0x0) {
    pIVar2 = *(InputLinkBandwidth **)(this + (ulonglong)param_1 * 8 + 0x180);
  }
  else if (param_1 < 0xf) {
    pIVar2 = *(InputLinkBandwidth **)(pHVar1 + (ulonglong)param_1 * 8 + 0x10);
  }
  return pIVar2;
}



===== GetLinkPositionRegister @ 140007590 =====

/* public: static long __cdecl HdaBusInterface::GetLinkPositionRegister(void * __ptr64,void *
   __ptr64,unsigned long * __ptr64 * __ptr64) */

long __cdecl HdaBusInterface::GetLinkPositionRegister(void *param_1,void *param_2,ulong **param_3)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  WDFDEVICE__ *pWVar4;
  long local_res8 [2];
  HdaController *local_res20;
  undefined4 in_stack_ffffffffffffffa8;
  undefined4 in_stack_ffffffffffffffac;
  
  local_res8[0] = -1;
  local_res20 = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_res20);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar2 = ConvertHandleToLong(param_1,param_2,local_res8);
      this = local_res20;
      if (uVar2 == '\0') {
        iVar3 = -0x3ffffff8;
      }
      else {
        in_stack_ffffffffffffffa8 = 0x20;
        pWVar4 = param_1;
        iVar3 = IoAcquireRemoveLockEx(local_res20 + 8,param_1,"",1);
        if (iVar3 == 0) {
          iVar3 = HdaController::GetLinkPositionRegister(this,pWVar4,local_res8[0],param_3);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
        }
        if (-1 < iVar3) goto LAB_140007651;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffffac,in_stack_ffffffffffffffa8),4,0x17,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_140007651:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_res20);
  return iVar3;
}



===== FindStreamId @ 140007704 =====

/* private: unsigned char __cdecl HdaController::FindStreamId(long * __ptr64) __ptr64 */

uchar __thiscall HdaController::FindStreamId(HdaController *this,long *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  bool bVar5;
  
  uVar2 = 0;
  bVar4 = 0;
  uVar3 = 0;
  do {
    LOCK();
    uVar1 = *param_1;
    bVar5 = uVar2 == uVar1;
    if (bVar5) {
      *param_1 = uVar2 | 1 << (uVar3 & 0x1f);
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
    if (bVar5) {
      return (char)uVar3 + '\x01';
    }
    while ((uVar2 >> (uVar3 & 0x1f) & 1) != 0) {
      if (0xe < bVar4) {
        return '\0';
      }
      bVar4 = bVar4 + 1;
      uVar3 = (uint)bVar4;
    }
  } while (bVar4 < 0xf);
  return '\0';
}



===== UnregisterNotificationHandler @ 140007744 =====

/* private: long __cdecl HdaController::UnregisterNotificationHandler(long,struct _KEVENT *
   __ptr64,void (__cdecl*)(void * __ptr64,union _LARGE_INTEGER),void * __ptr64) __ptr64 */

long __thiscall
HdaController::UnregisterNotificationHandler
          (HdaController *this,long param_1,_KEVENT *param_2,
          _func_void_void_ptr__LARGE_INTEGER *param_3,void *param_4)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  bool bVar5;
  char cVar6;
  undefined1 uVar7;
  HdaController *pHVar8;
  undefined **ppuVar9;
  long lVar10;
  longlong lVar11;
  HdaController *pHVar12;
  undefined1 *puVar13;
  byte bVar14;
  HdaController *pHVar15;
  undefined **ppuVar16;
  undefined4 uVar17;
  undefined *puVar18;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  undefined8 in_stack_ffffffffffffffb8;
  
  cVar6 = KeGetCurrentIrql();
  puVar13 = auStackY_68;
  ppuVar9 = &WPP_GLOBAL_Control;
  pHVar15 = (HdaController *)0x8;
  bVar14 = 8;
  ppuVar16 = &WPP_RECORDER_INITIALIZED;
  bVar5 = true;
  puVar18 = &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids;
  uVar17 = 4;
  if (cVar6 == '\0') {
    if ((uint)param_1 < 0x1e) {
      if ((param_2 == (_KEVENT *)0x0) && (param_3 == (_func_void_void_ptr__LARGE_INTEGER *)0x0)) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar6 = '\0';
        }
        else {
          cVar6 = '\x01';
        }
        if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,0xca,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        puVar13 = auStackY_68;
        lVar10 = -0x3ffffff3;
      }
      else {
        lVar11 = (longlong)param_1 * 0xd8;
        if ((this[lVar11 + 0x20e] == (HdaController)0x0) ||
           ((this[lVar11 + 0x26c] != (HdaController)0x0 &&
            (*(longlong *)(this + lVar11 + 0x298) == 0)))) {
          pHVar15 = this + lVar11 + 0x2a8;
          uVar17 = 4;
          uVar7 = KeAcquireSpinLockRaiseToDpc(pHVar15);
          ppuVar16 = (undefined **)CONCAT71((int7)((ulonglong)ppuVar16 >> 8),uVar7);
          pHVar8 = this + lVar11 + 0x2b0;
          if (*(HdaController **)pHVar8 != pHVar8) {
            for (pHVar12 = *(HdaController **)pHVar8; pHVar12 != pHVar8;
                pHVar12 = *(HdaController **)pHVar12) {
              if (((*(_KEVENT **)(pHVar12 + 0x10) == param_2) &&
                  (*(_func_void_void_ptr__LARGE_INTEGER **)(pHVar12 + 0x20) == param_3)) &&
                 (*(void **)(pHVar12 + 0x28) == param_4)) {
                ppuVar9 = *(undefined ***)pHVar12;
                if (((HdaController *)ppuVar9[1] == pHVar12) &&
                   (plVar1 = *(longlong **)(pHVar12 + 8), (HdaController *)*plVar1 == pHVar12)) {
                  *plVar1 = (longlong)ppuVar9;
                  ppuVar9[1] = (undefined *)plVar1;
                  KeReleaseSpinLock(pHVar15,CONCAT71((int7)((ulonglong)ppuVar9 >> 8),uVar7));
                  if (param_3 != (_func_void_void_ptr__LARGE_INTEGER *)0x0) {
                    ObfDereferenceObjectWithTag(*(longlong *)(pHVar12 + 0x18),0x4e427a41);
                  }
                  ExFreePoolWithTag(pHVar12,0x4e427a41);
                  return 0;
                }
                pcVar4 = (code *)swi(0x29);
                (*pcVar4)(3);
                puVar13 = auStackY_60;
                goto LAB_1400079fd;
              }
            }
          }
          KeReleaseSpinLock(pHVar15,uVar7);
          puVar13 = auStackY_68;
          lVar10 = -0x3ffffddb;
          bVar14 = 8;
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar6 = '\0';
          }
          else {
            cVar6 = '\x01';
          }
          if ((cVar6 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,0xcb,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
          puVar13 = auStackY_68;
          lVar10 = -0x3ffffff0;
        }
      }
    }
    else {
LAB_1400079fd:
      bVar14 = (byte)pHVar15;
      if ((((undefined **)WPP_GLOBAL_Control == ppuVar9) ||
          ((bVar14 & (byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != ppuVar16)) {
        *(undefined **)(puVar13 + 0x38) = puVar18;
        *(undefined2 *)(puVar13 + 0x30) = 0xc9;
        *(undefined4 *)(puVar13 + 0x28) = uVar17;
        uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar13 + -8) = 0x140007a50;
        WPP_RECORDER_AND_TRACE_SF_
                  (uVar3,cVar6,(undefined **)WPP_RECORDER_INITIALIZED != ppuVar16,uVar2,
                   *(undefined8 *)(puVar13 + 0x20),*(undefined4 *)(puVar13 + 0x28),
                   *(undefined2 *)(puVar13 + 0x30),*(undefined8 *)(puVar13 + 0x38));
      }
      lVar10 = -0x3ffffff8;
    }
  }
  else {
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,200,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    puVar13 = auStackY_68;
    lVar10 = -0x3fffffff;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((bVar14 & (byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar5 = false;
  }
  if ((bVar5) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(long *)(puVar13 + 0x40) = lVar10;
    *(undefined **)(puVar13 + 0x38) = &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids;
    *(undefined2 *)(puVar13 + 0x30) = 0xcc;
    *(undefined4 *)(puVar13 + 0x28) = 4;
    *(undefined8 *)(puVar13 + -8) = 0x140007ac8;
    WPP_RECORDER_AND_TRACE_SF_d
              (uVar3,bVar5,(undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,uVar2
               ,*(undefined8 *)(puVar13 + 0x20),*(undefined4 *)(puVar13 + 0x28),
               *(undefined2 *)(puVar13 + 0x30),*(undefined8 *)(puVar13 + 0x38),puVar13[0x40]);
  }
  return lVar10;
}



===== CommitBandwidth @ 140007ad4 =====

/* public: unsigned char __cdecl LinkBandwidth::CommitBandwidth(long) __ptr64 */

uchar __thiscall LinkBandwidth::CommitBandwidth(LinkBandwidth *this,long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffb8;
  
  cVar6 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar5 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,0xe,0xc,
               &WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,(char)param_1);
  }
  iVar2 = 0;
  iVar3 = param_1;
  while( true ) {
    LOCK();
    iVar1 = *(int *)(this + 0xc);
    bVar7 = iVar2 == iVar1;
    if (bVar7) {
      *(int *)(this + 0xc) = iVar3;
    }
    else {
      iVar2 = iVar1;
    }
    UNLOCK();
    if (bVar7) break;
    iVar3 = iVar2 + param_1;
    if (*(int *)(this + 8) < iVar3) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar6 = '\0';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_D
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,0xe,0xd,
                   &WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,0);
      }
      return '\0';
    }
  }
  return '\x01';
}



===== CreateHandleFromLong @ 140007c2c =====

/* protected: void * __ptr64 __cdecl HdaBusInterface::CreateHandleFromLong(long) __ptr64 */

void * __thiscall HdaBusInterface::CreateHandleFromLong(HdaBusInterface *this,long param_1)

{
  undefined1 uVar1;
  void *pvVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(this + 8);
  LOCK();
  UNLOCK();
  pvVar2 = (void *)(handleId + 1);
  handleId = handleId + 1;
  *(void **)(this + (longlong)param_1 * 8 + 0x10) = pvVar2;
  KeReleaseSpinLock(this + 8,uVar1);
  return pvVar2;
}



===== AllocateRenderDmaEngine @ 140007ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HdaController::AllocateRenderDmaEngine(struct WDFDEVICE__ * __ptr64,unsigned
   char,struct _HDAUDIO_STREAM_FORMAT * __ptr64,unsigned char,long * __ptr64,struct
   _HDAUDIO_CONVERTER_FORMAT * __ptr64) __ptr64 */

long __thiscall
HdaController::AllocateRenderDmaEngine
          (HdaController *this,WDFDEVICE__ *param_1,uchar param_2,_HDAUDIO_STREAM_FORMAT *param_3,
          uchar param_4,long *param_5,_HDAUDIO_CONVERTER_FORMAT *param_6)

{
  undefined2 uVar1;
  bool bVar2;
  byte bVar3;
  undefined1 uVar4;
  uchar uVar5;
  HdaController HVar6;
  ushort uVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  OutputLinkBandwidth *this_00;
  HdaController *pHVar11;
  char cVar12;
  uint uVar13;
  HdaController *pHVar14;
  longlong lVar15;
  uint uVar16;
  undefined2 in_stack_ffffffffffffff78;
  undefined6 in_stack_ffffffffffffff7a;
  long local_54;
  uint local_50;
  HdaController *local_48;
  
  local_54 = 0;
  bVar3 = 0;
  iVar9 = -0x3fffffff;
  bVar2 = true;
  if (((param_3 == (_HDAUDIO_STREAM_FORMAT *)0x0) || (param_6 == (_HDAUDIO_CONVERTER_FORMAT *)0x0))
     || (param_5 == (long *)0x0)) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar12 = '\0';
    }
    else {
      cVar12 = '\x01';
    }
    if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT62(in_stack_ffffffffffffff7a,in_stack_ffffffffffffff78),0xe,0x5a,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    iVar10 = -0x3ffffff3;
LAB_140007f87:
  }
  else {
    lVar8 = BuildHDAudioConverterFormat(this,param_3,param_6);
    if (lVar8 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar12 = '\0';
      }
      else {
        cVar12 = '\x01';
      }
      if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT62(in_stack_ffffffffffffff7a,in_stack_ffffffffffffff78),0xe,0x5b,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      iVar9 = -0x3ffffff3;
      goto LAB_140007f95;
    }
    this_00 = GetOutputLinkBandwidth(this,param_2);
    if (this_00 != (OutputLinkBandwidth *)0x0) {
      in_stack_ffffffffffffff78 = *(undefined2 *)(param_3 + 4);
      iVar10 = (*(code *)**(undefined8 **)this_00)
                         (this_00,&local_54,(byte)param_6[1] & 0x7f,*(undefined2 *)(param_3 + 8),
                          in_stack_ffffffffffffff78,param_4);
      if (-1 < iVar10) {
        uVar4 = KfRaiseIrql(2);
        LOCK();
        pHVar14 = this + 7000;
        iVar9 = *(int *)pHVar14;
        *(int *)pHVar14 = *(int *)pHVar14 + 1;
        UNLOCK();
        if ((iVar9 + 1 < 0x10) &&
           (uVar5 = LinkBandwidth::CommitBandwidth((LinkBandwidth *)this_00,local_54), uVar5 != '\0'
           )) {
          local_48 = this + 0x168;
          for (uVar16 = 0; uVar16 < *(uint *)(this + 0x16c); uVar16 = uVar16 + 1) {
            local_48 = this + 0x168;
            local_50 = *(int *)local_48 + uVar16;
            lVar15 = (ulonglong)local_50 * 0xd8;
            pHVar14 = this + lVar15 + 0x200;
            KeAcquireSpinLockAtDpcLevel(pHVar14);
            if (this[lVar15 + 0x20c] == (HdaController)0x0) {
              pHVar11 = this + 0x1f8;
              KeAcquireSpinLockAtDpcLevel();
              this[lVar15 + 0x20f] = (HdaController)param_4;
              *(long *)(this + lVar15 + 0x210) = local_54;
              this[lVar15 + 0x214] = (HdaController)param_2;
              this[lVar15 + 0x20c] = (HdaController)0x1;
              HVar6 = (HdaController)FindStreamId(pHVar11,(long *)(this + 0x1b5c));
              this[lVar15 + 0x215] = HVar6;
              *(undefined8 *)(this + lVar15 + 600) = *(undefined8 *)param_3;
              *(undefined4 *)(this + lVar15 + 0x260) = *(undefined4 *)(param_3 + 8);
              uVar1 = *(undefined2 *)param_6;
              *(undefined4 *)(this + lVar15 + 0x268) = 0;
              *(undefined2 *)(this + lVar15 + 0x264) = uVar1;
              *(WDFDEVICE__ **)(this + lVar15 + 0x2d0) = param_1;
              ResetDmaEngine(this,local_50);
              uVar7 = ProbeForFifoSize(this,local_50);
              iVar9 = ((*(ushort *)param_6 >> 0xb & 7) + 1) * (uint)*(ushort *)(param_3 + 6) *
                      (uint)*(ushort *)(param_3 + 8);
              if (iVar9 / 8 <= (int)(uint)uVar7) {
                *param_5 = local_50;
                KeReleaseSpinLockFromDpcLevel(this + 0x1f8,(longlong)iVar9 % 8 & 0xffffffff);
                KeReleaseSpinLockFromDpcLevel(pHVar14);
                iVar10 = 0;
                goto LAB_140007f40;
              }
              pHVar11 = this;
              ResetDmaEngine(this,local_50);
              FreeStreamId(pHVar11,(long *)(this + 0x1b5c),(uchar)this[lVar15 + 0x215]);
              *(undefined4 *)(this + lVar15 + 0x210) = 0;
              *(undefined2 *)(this + lVar15 + 0x214) = 0;
              this[lVar15 + 0x20f] = (HdaController)0x0;
              *(undefined8 *)(this + lVar15 + 0x2d0) = 0;
              this[lVar15 + 0x20c] = (HdaController)0x0;
              KeReleaseSpinLockFromDpcLevel(this + 0x1f8);
              KeReleaseSpinLockFromDpcLevel(pHVar14);
              bVar3 = 1;
            }
            else {
              KeReleaseSpinLockFromDpcLevel(pHVar14);
            }
          }
          pHVar14 = local_48;
          for (uVar16 = 0; uVar16 < *(uint *)(this + 0x170); uVar16 = uVar16 + 1) {
            uVar13 = *(int *)(this + 0x16c) + *(int *)pHVar14 + uVar16;
            lVar15 = (ulonglong)uVar13 * 0xd8;
            pHVar14 = this + lVar15 + 0x200;
            KeAcquireSpinLockAtDpcLevel(pHVar14);
            if (this[lVar15 + 0x20c] == (HdaController)0x0) {
              pHVar11 = this + 0x1f8;
              KeAcquireSpinLockAtDpcLevel();
              this[lVar15 + 0x20f] = (HdaController)param_4;
              *(long *)(this + lVar15 + 0x210) = local_54;
              this[lVar15 + 0x214] = (HdaController)param_2;
              *(undefined4 *)(this + lVar15 + 0x208) = 4;
              this[lVar15 + 0x20c] = (HdaController)0x1;
              HVar6 = (HdaController)FindStreamId(pHVar11,(long *)(this + 0x1b5c));
              this[lVar15 + 0x215] = HVar6;
              *(undefined8 *)(this + lVar15 + 600) = *(undefined8 *)param_3;
              *(undefined4 *)(this + lVar15 + 0x260) = *(undefined4 *)(param_3 + 8);
              uVar1 = *(undefined2 *)param_6;
              *(undefined4 *)(this + lVar15 + 0x268) = 0;
              *(undefined2 *)(this + lVar15 + 0x264) = uVar1;
              *(WDFDEVICE__ **)(this + lVar15 + 0x2d0) = param_1;
              ResetDmaEngine(this,uVar13);
              uVar7 = ProbeForFifoSize(this,uVar13);
              iVar9 = ((*(ushort *)param_6 >> 0xb & 7) + 1) * (uint)*(ushort *)(param_3 + 6) *
                      (uint)*(ushort *)(param_3 + 8);
              if (iVar9 / 8 <= (int)(uint)uVar7) {
                *param_5 = uVar13;
                KeReleaseSpinLockFromDpcLevel(this + 0x1f8,(longlong)iVar9 % 8 & 0xffffffff);
                KeReleaseSpinLockFromDpcLevel(pHVar14);
                iVar10 = 0;
                goto LAB_140007f40;
              }
              pHVar11 = this;
              ResetDmaEngine(this,uVar13);
              FreeStreamId(pHVar11,(long *)(this + 0x1b5c),(uchar)this[lVar15 + 0x215]);
              *(undefined4 *)(this + lVar15 + 0x210) = 0;
              *(undefined2 *)(this + lVar15 + 0x214) = 0;
              *(undefined8 *)(this + lVar15 + 0x2d0) = 0;
              *(undefined4 *)(this + lVar15 + 0x208) = 2;
              this[lVar15 + 0x20f] = (HdaController)0x0;
              this[lVar15 + 0x20c] = (HdaController)0x0;
              KeReleaseSpinLockFromDpcLevel(this + 0x1f8);
              KeReleaseSpinLockFromDpcLevel(pHVar14);
              bVar3 = 1;
            }
            else {
              KeReleaseSpinLockFromDpcLevel(pHVar14);
            }
            pHVar14 = this + 0x168;
          }
          LinkBandwidth::FreeBandwidth((LinkBandwidth *)this_00,local_54);
          LOCK();
          *(int *)(this + 7000) = *(int *)(this + 7000) + -1;
          UNLOCK();
          iVar10 = (-(uint)bVar3 & 0xffffff89) + 0xc000009a;
        }
        else {
          LOCK();
          *(int *)(this + 7000) = *(int *)(this + 7000) + -1;
          UNLOCK();
          iVar10 = -0x3fffff66;
        }
LAB_140007f40:
        KeLowerIrql(uVar4);
        if (-1 < iVar10) {
          if (1 < *(ushort *)(this + 0x9670)) {
            iVar10 = MapActiveStreamId(this,param_2,(uchar)this[(longlong)*param_5 * 0xd8 + 0x215]);
          }
          if (-1 < iVar10) {
            return iVar10;
          }
        }
      }
      goto LAB_140007f87;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar12 = '\0';
    }
    else {
      cVar12 = '\x01';
    }
    if ((cVar12 != '\0') ||
       (iVar10 = -0x3fffffff, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
    {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT62(in_stack_ffffffffffffff7a,in_stack_ffffffffffffff78),0xe,0x5c,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,1);
      goto LAB_140007f95;
    }
  }
  iVar9 = iVar10;
LAB_140007f95:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar2 = false;
  }
  if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT62(in_stack_ffffffffffffff7a,in_stack_ffffffffffffff78),0xe,0x5d,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar9);
  }
  return iVar9;
}



===== GetOutputLinkBandwidth @ 140008450 =====

/* private: class OutputLinkBandwidth * __ptr64 __cdecl
   HdaController::GetOutputLinkBandwidth(unsigned char) __ptr64 */

OutputLinkBandwidth * __thiscall
HdaController::GetOutputLinkBandwidth(HdaController *this,uchar param_1)

{
  HdaLinkInstance *pHVar1;
  OutputLinkBandwidth *pOVar2;
  
  pHVar1 = GetLinkInstanceCapability(this,param_1);
  if (pHVar1 == (HdaLinkInstance *)0x0) {
    pOVar2 = *(OutputLinkBandwidth **)(this + 0x178);
  }
  else {
    pOVar2 = *(OutputLinkBandwidth **)(pHVar1 + 0x88);
  }
  return pOVar2;
}



===== GetLinkInstanceCapability @ 140008480 =====

/* private: class HdaLinkInstance * __ptr64 __cdecl
   HdaController::GetLinkInstanceCapability(unsigned char) __ptr64 */

HdaLinkInstance * __thiscall
HdaController::GetLinkInstanceCapability(HdaController *this,uchar param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FirstEntrySList(this + 0x9660);
  while( true ) {
    if (puVar1 == (undefined8 *)0x0) {
      return (HdaLinkInstance *)0x0;
    }
    if ((*(ushort *)((HdaLinkInstance *)puVar1[2] + 8) >> (param_1 & 0x1f) & 1) != 0) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return (HdaLinkInstance *)puVar1[2];
}



===== AllocateRenderDmaEngine @ 1400084d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl HdaBusInterface::AllocateRenderDmaEngine(void * __ptr64,struct
   _HDAUDIO_STREAM_FORMAT * __ptr64,unsigned char,void * __ptr64 * __ptr64,struct
   _HDAUDIO_CONVERTER_FORMAT * __ptr64) */

long __cdecl
HdaBusInterface::AllocateRenderDmaEngine
          (void *param_1,_HDAUDIO_STREAM_FORMAT *param_2,uchar param_3,void **param_4,
          _HDAUDIO_CONVERTER_FORMAT *param_5)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  void *pvVar4;
  undefined1 auStackY_d8 [32];
  undefined4 in_stack_ffffffffffffff48;
  undefined4 in_stack_ffffffffffffff4c;
  long local_88 [2];
  HdaController *local_80;
  _HDAUDIO_CONVERTER_FORMAT *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_88[0] = -1;
  local_80 = (HdaController *)0x0;
  local_78 = param_5;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_80);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      local_60 = 0;
      uStack_68 = 0;
      local_70 = 0x18;
      (**(code **)(WdfFunctions_01025 + 0x6f0))
                (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),&local_70);
      this = local_80;
      in_stack_ffffffffffffff48 = 0x20;
      iVar3 = IoAcquireRemoveLockEx(local_80 + 8,param_1,"",1);
      if (iVar3 == 0) {
        in_stack_ffffffffffffff48 = CONCAT31((int3)((uint)in_stack_ffffffffffffff48 >> 8),param_3);
        iVar3 = HdaController::AllocateRenderDmaEngine
                          (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),local_60._2_1_,param_2,
                           param_3,local_88,local_78);
        IoReleaseRemoveLockEx(this + 8,param_1,0x20);
      }
      if (-1 < iVar3) {
        pvVar4 = CreateHandleFromLong(param_1,local_88[0]);
        *param_4 = pvVar4;
        goto LAB_1400085f4;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffff4c,in_stack_ffffffffffffff48),4,0x11,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_1400085f4:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_80);
  return iVar3;
}



===== AllocateDmaBufferWithNotification @ 1400086b0 =====

/* public: static long __cdecl HdaBusInterface2::AllocateDmaBufferWithNotification(void *
   __ptr64,void * __ptr64,unsigned long,unsigned __int64,struct _MDL * __ptr64 * __ptr64,unsigned
   __int64 * __ptr64,unsigned __int64 * __ptr64,unsigned char * __ptr64,unsigned long * __ptr64) */

long __cdecl
HdaBusInterface2::AllocateDmaBufferWithNotification
          (void *param_1,void *param_2,ulong param_3,__uint64 param_4,_MDL **param_5,
          __uint64 *param_6,__uint64 *param_7,uchar *param_8,ulong *param_9)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  long local_res8 [2];
  __uint64 in_stack_ffffffffffffff58;
  undefined8 in_stack_ffffffffffffff70;
  undefined4 uVar6;
  undefined8 local_58;
  HdaController *local_50;
  void *local_48;
  DmaAdapterTracker *local_40;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff70 >> 0x20);
  local_res8[0] = -1;
  local_50 = (HdaController *)0x0;
  local_40 = (DmaAdapterTracker *)0x0;
  local_48 = (void *)0x0;
  local_58 = 0;
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar5 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    uVar6 = 1;
    WPP_RECORDER_AND_TRACE_SF_dd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,4,0x1b,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)param_3,(char)param_4);
  }
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = HdaBusInterface::GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_50);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar2 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res8);
      this = local_50;
      if (uVar2 == '\0') {
        iVar3 = -0x3ffffff8;
      }
      else {
        in_stack_ffffffffffffff58 = CONCAT44((int)(in_stack_ffffffffffffff58 >> 0x20),0x20);
        iVar3 = IoAcquireRemoveLockEx(local_50 + 8,param_1,"",1);
        if (iVar3 == 0) {
          iVar3 = HdaController::AllocateDmaBufferWithNotification
                            (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),local_res8[0],param_3
                             ,param_4,param_5,param_6,param_7,&local_40,&local_48,
                             (_LARGE_INTEGER *)&local_58,param_8,param_9);
          uVar6 = (undefined4)((ulonglong)param_7 >> 0x20);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
          in_stack_ffffffffffffff58 = param_4;
        }
        if (-1 < iVar3) {
          HdaBusInterface::StoreAudioBufferInfo
                    (param_1,param_2,*param_5,local_40,local_48,local_58,*param_6,CONCAT44(uVar6,1))
          ;
          goto LAB_14000886a;
        }
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,4,0x1c,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14000886a:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_50);
  return iVar3;
}



===== UnregisterNotificationEvent @ 140008980 =====

/* public: static long __cdecl HdaBusInterface2::UnregisterNotificationEvent(void * __ptr64,void *
   __ptr64,struct _KEVENT * __ptr64) */

long __cdecl
HdaBusInterface2::UnregisterNotificationEvent(void *param_1,void *param_2,_KEVENT *param_3)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  long local_res8 [2];
  HdaController *local_res20;
  undefined8 in_stack_ffffffffffffffa8;
  
  local_res8[0] = -1;
  local_res20 = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = HdaBusInterface::GetController
                      (param_1,(SmartPtrT<HdaController*___ptr64> *)&local_res20);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar2 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res8);
      this = local_res20;
      if (uVar2 == '\0') {
        iVar3 = -0x3ffffff8;
      }
      else {
        in_stack_ffffffffffffffa8 =
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20),0x20);
        iVar3 = IoAcquireRemoveLockEx(local_res20 + 8,param_1,"");
        if (iVar3 == 0) {
          in_stack_ffffffffffffffa8 = 0;
          iVar3 = HdaController::UnregisterNotificationHandler
                            (this,local_res8[0],param_3,(_func_void_void_ptr__LARGE_INTEGER *)0x0,
                             (void *)0x0);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
        }
        if (-1 < iVar3) goto LAB_140008a49;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,4,0x1f,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_140008a49:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_res20);
  return iVar3;
}



===== FreeDmaEngine @ 140008b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl HdaBusInterface::FreeDmaEngine(void * __ptr64,void * __ptr64) */

long __cdecl HdaBusInterface::FreeDmaEngine(void *param_1,void *param_2)

{
  HdaController *pHVar1;
  bool bVar2;
  HdaController *this;
  uchar uVar3;
  int iVar4;
  undefined1 auStackY_a8 [32];
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar6;
  _HdaBufferType *p_Var5;
  long local_58 [2];
  HdaController *local_50;
  __uint64 local_48;
  void *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_50 = (HdaController *)0x0;
  bVar2 = true;
  local_58[0] = 1;
  if (param_1 == (void *)0x0) {
    iVar4 = -0x3ffffff3;
  }
  else {
    uVar3 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_50);
    if (uVar3 == '\0') {
      iVar4 = -0x3ffffff0;
    }
    else {
      uVar3 = ConvertHandleToLong(param_1,param_2,local_58);
      this = local_50;
      if (uVar3 == '\0') {
        iVar4 = -0x3ffffff8;
      }
      else {
        local_40 = (void *)0x0;
        local_48 = 0;
        local_58[1] = 3;
        pHVar1 = local_50 + 8;
        uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
        iVar4 = IoAcquireRemoveLockEx(pHVar1,param_1,"",1);
        if (iVar4 == 0) {
          p_Var5 = (_HdaBufferType *)(local_58 + 1);
          HdaController::DetachAudioBuffer(this,local_58[0],&local_40,&local_48,p_Var5);
          uVar6 = (undefined4)((ulonglong)p_Var5 >> 0x20);
          IoReleaseRemoveLockEx(pHVar1,param_1,0x20);
        }
        local_28 = 0;
        uStack_30 = 0;
        local_38 = 0x18;
        (**(code **)(WdfFunctions_01025 + 0x6f0))
                  (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),&local_38);
        in_stack_ffffffffffffff78 = CONCAT44(uVar6,0x20);
        iVar4 = IoAcquireRemoveLockEx(pHVar1,param_1,"",1);
        if (iVar4 == 0) {
          iVar4 = HdaController::FreeDmaEngine
                            (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),local_58[0],
                             local_28._2_1_);
          IoReleaseRemoveLockEx(pHVar1,param_1,0x20);
        }
        *(undefined8 *)((longlong)param_1 + (longlong)local_58[0] * 8 + 0x10) = 0;
        if (-1 < iVar4) goto LAB_140008c83;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar2 = false;
  }
  if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,4,0x15,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar4);
  }
LAB_140008c83:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_50);
  return iVar4;
}



===== RegisterNotificationEvent @ 140008d50 =====

/* public: static long __cdecl HdaBusInterface2::RegisterNotificationEvent(void * __ptr64,void *
   __ptr64,struct _KEVENT * __ptr64) */

long __cdecl
HdaBusInterface2::RegisterNotificationEvent(void *param_1,void *param_2,_KEVENT *param_3)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  long local_res8 [2];
  HdaController *local_res20;
  undefined8 in_stack_ffffffffffffffa8;
  
  local_res8[0] = -1;
  local_res20 = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = HdaBusInterface::GetController
                      (param_1,(SmartPtrT<HdaController*___ptr64> *)&local_res20);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar2 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res8);
      this = local_res20;
      if (uVar2 == '\0') {
        iVar3 = -0x3ffffff8;
      }
      else {
        in_stack_ffffffffffffffa8 =
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20),0x20);
        iVar3 = IoAcquireRemoveLockEx(local_res20 + 8,param_1,"",1);
        if (iVar3 == 0) {
          in_stack_ffffffffffffffa8 = 0;
          iVar3 = HdaController::RegisterNotificationHandler
                            (this,(_DEVICE_OBJECT *)0x0,local_res8[0],param_3,
                             (_func_void_void_ptr__LARGE_INTEGER *)0x0,(void *)0x0);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
        }
        if (-1 < iVar3) goto LAB_140008e1f;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,4,0x1e,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_140008e1f:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_res20);
  return iVar3;
}



===== FreeDmaBufferWithNotification @ 140008ed0 =====

/* public: static long __cdecl HdaBusInterface2::FreeDmaBufferWithNotification(void * __ptr64,void *
   __ptr64,struct _MDL * __ptr64,unsigned __int64) */

long __cdecl
HdaBusInterface2::FreeDmaBufferWithNotification
          (void *param_1,void *param_2,_MDL *param_3,__uint64 param_4)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  _HdaBufferType local_res8 [2];
  long local_res18 [2];
  DmaAdapterTracker **local_res20;
  DmaAdapterTracker **in_stack_ffffffffffffff68;
  undefined4 uVar4;
  DmaAdapterTracker **local_68;
  void *local_60;
  DmaAdapterTracker *local_58;
  __uint64 local_50;
  _MDL *local_48;
  HdaController *local_40;
  
  local_res18[0] = -1;
  local_50 = 0;
  local_res8[0] = 3;
  local_40 = (HdaController *)0x0;
  bVar1 = true;
  local_58 = (DmaAdapterTracker *)0x0;
  local_60 = (void *)0x0;
  local_68 = (DmaAdapterTracker **)0x0;
  local_res20 = (DmaAdapterTracker **)param_4;
  local_48 = param_3;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = HdaBusInterface::GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_40);
    uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
    if (uVar2 == '\0') {
LAB_1400090b3:
      in_stack_ffffffffffffff68 = &local_58;
      iVar3 = HdaBusInterface::RetrieveAudioBufferInfo
                        (param_1,param_2,&local_48,&local_50,in_stack_ffffffffffffff68,&local_60,
                         (_LARGE_INTEGER *)&local_68,local_res8);
      if (iVar3 < 0) goto LAB_140009040;
      in_stack_ffffffffffffff68 = local_68;
      iVar3 = HdaController::FreeDetachedAudioBuffer
                        (local_48,local_50,local_58,local_60,local_68,local_res8[0]);
    }
    else {
      uVar2 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res18);
      this = local_40;
      if (uVar2 == '\0') goto LAB_1400090b3;
      in_stack_ffffffffffffff68 = (DmaAdapterTracker **)CONCAT44(uVar4,0x20);
      iVar3 = IoAcquireRemoveLockEx(local_40 + 8,param_1,"",1);
      if (iVar3 == 0) {
        in_stack_ffffffffffffff68 = local_res20;
        iVar3 = HdaController::FreeDmaBufferWithNotification
                          (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),local_res18[0],param_3,
                           (__uint64)local_res20);
        IoReleaseRemoveLockEx(this + 8,param_1,0x20);
      }
      if (-1 < iVar3) {
        HdaBusInterface::RetrieveAudioBufferInfo
                  (param_1,param_2,&local_48,&local_50,&local_58,&local_60,
                   (_LARGE_INTEGER *)&local_68,local_res8);
        goto LAB_140009014;
      }
      if ((iVar3 == -0x3ffffff8) || (iVar3 == -0x3fffffaa)) goto LAB_1400090b3;
    }
    if (-1 < iVar3) goto LAB_140009014;
  }
LAB_140009040:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,4,0x1d,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_140009014:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_40);
  return iVar3;
}



===== SetDmaEngineState @ 140009130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl HdaBusInterface::SetDmaEngineState(void * __ptr64,enum
   _HDAUDIO_STREAM_STATE,unsigned long,void * __ptr64 * __ptr64 const) */

long __cdecl
HdaBusInterface::SetDmaEngineState
          (void *param_1,_HDAUDIO_STREAM_STATE param_2,ulong param_3,void **param_4)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  ulong uVar4;
  void **ppvVar5;
  undefined1 auStackY_128 [32];
  long *in_stack_fffffffffffffef8;
  HdaController *local_d8 [2];
  long local_c8 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d8[0] = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 != (void *)0x0) {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)local_d8);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
      goto LAB_140009277;
    }
    if (param_3 - 1 < 0x1d) {
      ppvVar5 = param_4 + (int)param_3;
      uVar4 = param_3;
      do {
        this = local_d8[0];
        if (uVar4 == 0) {
          in_stack_fffffffffffffef8 =
               (long *)CONCAT44((int)((ulonglong)in_stack_fffffffffffffef8 >> 0x20),0x20);
          iVar3 = IoAcquireRemoveLockEx(local_d8[0] + 8,param_1,"",1);
          if (iVar3 == 0) {
            in_stack_fffffffffffffef8 = local_c8;
            iVar3 = HdaController::SetDmaEngineState
                              (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),param_2,param_3,
                               in_stack_fffffffffffffef8);
            IoReleaseRemoveLockEx(this + 8,param_1,0x20);
          }
          if (-1 < iVar3) goto LAB_140009210;
          goto LAB_140009277;
        }
        uVar4 = uVar4 - 1;
        ppvVar5 = ppvVar5 + -1;
        uVar2 = ConvertHandleToLong(param_1,*ppvVar5,local_c8 + (int)uVar4);
      } while (uVar2 != '\0');
      iVar3 = -0x3ffffff8;
      goto LAB_140009277;
    }
  }
  iVar3 = -0x3ffffff3;
LAB_140009277:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffef8,4,0x16,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_140009210:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)local_d8);
  return iVar3;
}



===== Remove @ 140009300 =====

/* private: void __cdecl SmartPtrT<class HdaController * __ptr64>::Remove(void) __ptr64 */

void __thiscall SmartPtrT<HdaController*___ptr64>::Remove(SmartPtrT<HdaController*___ptr64> *this)

{
  int iVar1;
  HdaController *this_00;
  
  this_00 = *(HdaController **)this;
  if (this_00 != (HdaController *)0x0) {
    LOCK();
    iVar1 = *(int *)this_00;
    *(int *)this_00 = *(int *)this_00 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      HdaController::~HdaController(this_00);
      ExFreePoolWithTag(this_00,0);
      *(undefined8 *)this = 0;
      return;
    }
  }
  *(undefined8 *)this = 0;
  return;
}



===== GetController @ 140009360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: unsigned char __cdecl HdaBusInterface::GetController(class SmartPtrT<class HdaController
   * __ptr64> & __ptr64) __ptr64 */

uchar __thiscall
HdaBusInterface::GetController(HdaBusInterface *this,SmartPtrT<HdaController*___ptr64> *param_1)

{
  int iVar1;
  int *piVar2;
  HdaController *pHVar3;
  undefined1 uVar4;
  uchar uVar5;
  longlong lVar6;
  
  if (((*(longlong *)(this + 0x888) != 0) &&
      (*(longlong *)(*(longlong *)(this + 0x888) + 0x10) != 0)) &&
     (*(longlong *)(this + 0x880) != 0)) {
    lVar6 = (**(code **)(WdfFunctions_01025 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(this + 0x880),
                       PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
    if (lVar6 != 0) {
      lVar6 = (**(code **)(WdfFunctions_01025 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0x880),
                         PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar6);
      piVar2 = *(int **)(lVar6 + 0x30);
      if (piVar2 != (int *)0x0) {
        LOCK();
        *piVar2 = *piVar2 + 1;
        UNLOCK();
      }
      KeReleaseSpinLock(lVar6,uVar4);
      pHVar3 = *(HdaController **)param_1;
      if (pHVar3 != (HdaController *)0x0) {
        LOCK();
        iVar1 = *(int *)pHVar3;
        *(int *)pHVar3 = *(int *)pHVar3 + -1;
        UNLOCK();
        if (iVar1 == 1) {
          HdaController::~HdaController(pHVar3);
          ExFreePoolWithTag(pHVar3,0);
        }
      }
      *(int **)param_1 = piVar2;
      if (piVar2 != (int *)0x0) {
        LOCK();
        *piVar2 = *piVar2 + 1;
        UNLOCK();
      }
      pHVar3 = *(HdaController **)param_1;
      if (pHVar3 == (HdaController *)0x0) {
        uVar5 = '\0';
      }
      else {
        LOCK();
        iVar1 = *(int *)pHVar3;
        *(int *)pHVar3 = *(int *)pHVar3 + -1;
        UNLOCK();
        if (iVar1 == 1) {
          HdaController::~HdaController(pHVar3);
          ExFreePoolWithTag(pHVar3,0);
        }
        uVar5 = '\x01';
      }
      return uVar5;
    }
  }
  return '\0';
}



===== ConvertHandleToLong @ 1400094c4 =====

/* protected: unsigned char __cdecl HdaBusInterface::ConvertHandleToLong(void * __ptr64,long &
   __ptr64) __ptr64 */

uchar __thiscall
HdaBusInterface::ConvertHandleToLong(HdaBusInterface *this,void *param_1,long *param_2)

{
  bool bVar1;
  undefined1 uVar2;
  HdaBusInterface *pHVar3;
  longlong lVar4;
  int iVar5;
  undefined8 in_stack_ffffffffffffffb8;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(this + 8);
  bVar1 = true;
  if (param_1 != (void *)0x0) {
    iVar5 = 0;
    pHVar3 = this + 0x10;
    for (lVar4 = 0; lVar4 < 0x1e; lVar4 = lVar4 + 1) {
      if (*(void **)pHVar3 == param_1) {
        *param_2 = iVar5;
        goto LAB_140009526;
      }
      iVar5 = iVar5 + 1;
      pHVar3 = pHVar3 + 8;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,0xd,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,0);
  }
  bVar1 = false;
LAB_140009526:
  KeReleaseSpinLock(this + 8,uVar2);
  return bVar1;
}



===== SetDmaEngineState @ 1400095d0 =====

/* public: long __cdecl HdaController::SetDmaEngineState(struct WDFDEVICE__ * __ptr64,enum
   _HDAUDIO_STREAM_STATE,unsigned long,long * __ptr64 const) __ptr64 */

long __thiscall
HdaController::SetDmaEngineState
          (HdaController *this,WDFDEVICE__ *param_1,_HDAUDIO_STREAM_STATE param_2,ulong param_3,
          long *param_4)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ulonglong uVar12;
  long *plVar13;
  undefined8 in_stack_ffffffffffffff78;
  longlong local_50;
  ulonglong local_48;
  
  uVar9 = 0;
  local_48 = (ulonglong)param_3;
  bVar1 = true;
  if ((param_4 == (long *)0x0) || (param_3 == 0)) {
    iVar8 = -0x3ffffff3;
    goto LAB_140009a2a;
  }
  bVar2 = KeGetCurrentIrql();
  if (2 < bVar2) {
    iVar8 = -0x3fffffff;
    goto LAB_140009a2a;
  }
  uVar3 = KfRaiseIrql(2);
  for (uVar12 = 0; (uint)uVar12 < param_3; uVar12 = (ulonglong)((uint)uVar12 + 1)) {
    if (0x1d < (uint)param_4[uVar12]) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar5 = '\0';
      }
      if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x80,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      iVar8 = -0x3ffffff8;
      goto LAB_14000991a;
    }
  }
  for (uVar11 = 0; iVar8 = 0, uVar11 < param_3; uVar11 = uVar11 + 1) {
    KeAcquireSpinLockAtDpcLevel(this + (longlong)param_4[uVar11] * 0xd8 + 0x200);
    lVar6 = (longlong)param_4[uVar11];
    lVar7 = lVar6 * 0xd8;
    if ((this[lVar7 + 0x20c] == (HdaController)0x0) ||
       ((param_1 != (WDFDEVICE__ *)0x0 && (*(WDFDEVICE__ **)(this + lVar7 + 0x2d0) != param_1)))) {
      uVar12 = (ulonglong)(uVar11 + 1);
      do {
        KeReleaseSpinLockFromDpcLevel(this + (longlong)*param_4 * 0xd8 + 0x200);
        param_4 = param_4 + 1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
      iVar8 = -0x3ffffff8;
      goto LAB_14000991a;
    }
    if (param_2 == 0) {
      if (*(int *)(this + lVar7 + 0x268) == 2) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar5 = '\0';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x81,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        uVar12 = (ulonglong)(uVar11 + 1);
        do {
          KeReleaseSpinLockFromDpcLevel(this + (longlong)*param_4 * 0xd8 + 0x200);
          param_4 = param_4 + 1;
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
        goto LAB_1400097f7;
      }
    }
    else if ((param_2 == 2) &&
            ((this[lVar6 * 0xd8 + 0x20e] == (HdaController)0x0 ||
             ((this[lVar6 * 0xd8 + 0x26c] != (HdaController)0x0 &&
              (this[lVar6 * 0xd8 + 0x26d] == (HdaController)0x0)))))) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0 ||
          (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)))) {
        cVar5 = '\0';
      }
      if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x82,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      uVar12 = (ulonglong)(uVar11 + 1);
      do {
        KeReleaseSpinLockFromDpcLevel(this + (longlong)*param_4 * 0xd8 + 0x200);
        param_4 = param_4 + 1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
LAB_1400097f7:
      iVar8 = -0x3ffffff3;
      goto LAB_14000991a;
    }
    uVar9 = uVar9 | 1 << (param_4[uVar11] & 0x1fU);
  }
  if (param_3 == 1) {
    if (param_2 == 0) {
      *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
           ~(1 << ((byte)*param_4 & 0x1f) & 0x3fffffffU) &
           *(uint *)(*(longlong *)(this + 0x58) + 0x20);
      LOCK();
      UNLOCK();
      KeAcquireSpinLockAtDpcLevel(this + 0x1f8);
      ResetDmaEngine(this,*param_4);
      uVar4 = ProbeForFifoSize(this,*param_4);
      lVar7 = (longlong)*param_4 * 0xd8;
      if ((int)(uint)uVar4 <
          (int)(((*(ushort *)(this + lVar7 + 0x264) >> 0xb & 7) + 1) *
                (uint)*(ushort *)(this + lVar7 + 0x260) * (uint)*(ushort *)(this + lVar7 + 0x25e)) /
          8) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x83,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        iVar8 = -0x3ffffe7e;
      }
      KeReleaseSpinLockFromDpcLevel(this + 0x1f8);
    }
    else {
      if ((1 < *(ushort *)(this + 0x9670)) && (param_2 == 2)) {
        lVar7 = (longlong)*param_4 * 0xd8;
        if ((*(int *)(this + lVar7 + 0x208) == 1) || (*(int *)(this + lVar7 + 0x208) == 4)) {
          MapActiveStreamId(this,(uchar)this[lVar7 + 0x214],(uchar)this[lVar7 + 0x215]);
        }
      }
      ProgramDmaEngine(this,*param_4);
      SetDmaEngineState(this,*param_4,param_2 == 2);
    }
LAB_1400096ac:
    uVar12 = (ulonglong)param_3;
    do {
      *(_HDAUDIO_STREAM_STATE *)(this + (longlong)*param_4 * 0xd8 + 0x268) = param_2;
      KeReleaseSpinLockFromDpcLevel(this + (longlong)*param_4 * 0xd8 + 0x200);
      param_4 = param_4 + 1;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  else {
    if (param_2 != 0) {
      *(uint *)(*(longlong *)(this + 0x58) + 0x38) =
           (*(uint *)(*(longlong *)(this + 0x58) + 0x38) ^ uVar9) & 0x3fffffff ^
           *(uint *)(*(longlong *)(this + 0x58) + 0x38);
      LOCK();
      UNLOCK();
    }
    if (param_3 != 0) {
      local_50 = 0;
      plVar13 = param_4;
      do {
        if (param_2 == 0) {
          *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
               ~(1 << ((byte)*plVar13 & 0x1f) & 0x3fffffffU) &
               *(uint *)(*(longlong *)(this + 0x58) + 0x20);
          LOCK();
          UNLOCK();
          KeAcquireSpinLockAtDpcLevel(this + 0x1f8);
          ResetDmaEngine(this,*plVar13);
          uVar4 = ProbeForFifoSize(this,*plVar13);
          lVar7 = (longlong)*plVar13 * 0xd8;
          if ((int)(uint)uVar4 <
              (int)(((*(ushort *)(this + lVar7 + 0x264) >> 0xb & 7) + 1) *
                    (uint)*(ushort *)(this + lVar7 + 0x260) *
                   (uint)*(ushort *)(this + lVar7 + 0x25e)) / 8) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar5 = '\0';
            }
            else {
              cVar5 = '\x01';
            }
            if ((cVar5 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,
                         0x84,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
            }
            iVar8 = -0x3ffffe7e;
          }
          KeReleaseSpinLockFromDpcLevel(this + 0x1f8);
        }
        else {
          if ((1 < *(ushort *)(this + 0x9670)) && (param_2 == 2)) {
            lVar7 = (longlong)*plVar13 * 0xd8;
            if ((*(int *)(this + lVar7 + 0x208) == 1) || (*(int *)(this + lVar7 + 0x208) == 4)) {
              MapActiveStreamId(this,(uchar)this[lVar7 + 0x214],(uchar)this[lVar7 + 0x215]);
            }
          }
          ProgramDmaEngine(this,*plVar13);
          SetDmaEngineState(this,*plVar13,param_2 == 2);
          if (param_2 == 2) {
            for (iVar10 = 200;
                ((*(byte *)(local_50 + 0x83 + *(longlong *)(this + 0x58)) & 0x20) == 0 &&
                (iVar10 != 0)); iVar10 = iVar10 + -1) {
              KeStallExecutionProcessor(1);
            }
          }
        }
        local_50 = local_50 + 0x20;
        plVar13 = plVar13 + 1;
        local_48 = local_48 - 1;
      } while (local_48 != 0);
    }
    if (param_2 != 0) {
      *(uint *)(*(longlong *)(this + 0x58) + 0x38) =
           *(uint *)(*(longlong *)(this + 0x58) + 0x38) & 0xc0000000;
      LOCK();
      UNLOCK();
    }
    if (param_3 != 0) goto LAB_1400096ac;
  }
LAB_14000991a:
  KeLowerIrql(uVar3);
  if (-1 < iVar8) {
    return iVar8;
  }
LAB_140009a2a:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x85,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar8);
  }
  return iVar8;
}



===== ProbeForFifoSize @ 140009e50 =====

/* private: unsigned short __cdecl HdaController::ProbeForFifoSize(int) __ptr64 */

ushort __thiscall HdaController::ProbeForFifoSize(HdaController *this,int param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = (longlong)param_1;
  if (*(int *)(this + lVar1 * 0xd8 + 0x208) == 3) {
    *(byte *)(lVar1 * 0x20 + 0x82 + *(longlong *)(this + 0x58)) =
         *(byte *)(lVar1 * 0x20 + 0x82 + *(longlong *)(this + 0x58)) & 0xf7;
    LOCK();
    UNLOCK();
  }
  lVar2 = lVar1 * 0x20;
  if (*(int *)(this + lVar1 * 0xd8 + 0x208) == 4) {
    *(byte *)(*(longlong *)(this + 0x58) + 0x82 + lVar2) =
         *(byte *)(*(longlong *)(this + 0x58) + 0x82 + lVar2) | 8;
    LOCK();
    UNLOCK();
  }
  *(byte *)(*(longlong *)(this + 0x58) + 0x82 + lVar2) =
       this[lVar1 * 0xd8 + 0x20f] != (HdaController)0x0 |
       *(byte *)(*(longlong *)(this + 0x58) + 0x82 + lVar2) & 0xfe;
  LOCK();
  UNLOCK();
  *(byte *)(lVar2 + 0x82 + *(longlong *)(this + 0x58)) =
       (char)this[lVar1 * 0xd8 + 0x215] << 4 |
       *(byte *)(lVar2 + 0x82 + *(longlong *)(this + 0x58)) & 0xf;
  LOCK();
  UNLOCK();
  *(undefined2 *)(lVar2 + 0x92 + *(longlong *)(this + 0x58)) =
       *(undefined2 *)(this + lVar1 * 0xd8 + 0x264);
  LOCK();
  UNLOCK();
  KeStallExecutionProcessor(1);
  return *(short *)(lVar2 + 0x90 + *(longlong *)(this + 0x58)) + 1;
}



===== ResetDmaEngine @ 140009f8c =====

/* private: long __cdecl HdaController::ResetDmaEngine(int) __ptr64 */

long __thiscall HdaController::ResetDmaEngine(HdaController *this,int param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  undefined8 in_stack_ffffffffffffffc8;
  
  iVar2 = 0x28;
  lVar3 = ((longlong)param_1 + 4) * 0x20;
  iVar4 = 0x28;
  this[(longlong)param_1 * 0xd8 + 0x20d] = (HdaController)0x0;
  bVar1 = true;
  *(byte *)(lVar3 + *(longlong *)(this + 0x58)) = *(byte *)(lVar3 + *(longlong *)(this + 0x58)) | 1;
  LOCK();
  UNLOCK();
  while ((*(byte *)(lVar3 + *(longlong *)(this + 0x58)) & 1) == 0) {
    if (iVar4 == 0) goto LAB_14000a060;
    KeStallExecutionProcessor(1);
    iVar4 = iVar4 + -1;
  }
  *(byte *)(lVar3 + *(longlong *)(this + 0x58)) =
       *(byte *)(lVar3 + *(longlong *)(this + 0x58)) & 0xfe;
  LOCK();
  UNLOCK();
  while( true ) {
    if ((*(byte *)(lVar3 + *(longlong *)(this + 0x58)) & 1) == 0) {
      return 0;
    }
    if (iVar2 == 0) break;
    KeStallExecutionProcessor(1);
    iVar2 = iVar2 + -1;
  }
LAB_14000a060:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,0xd,0xd,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xb5);
    return -0x3fffff4b;
  }
  return -0x3fffff4b;
}



===== RegisterNotificationHandler @ 14000a0e0 =====

/* private: long __cdecl HdaController::RegisterNotificationHandler(struct _DEVICE_OBJECT *
   __ptr64,long,struct _KEVENT * __ptr64,void (__cdecl*)(void * __ptr64,union _LARGE_INTEGER),void *
   __ptr64) __ptr64 */

long __thiscall
HdaController::RegisterNotificationHandler
          (HdaController *this,_DEVICE_OBJECT *param_1,long param_2,_KEVENT *param_3,
          _func_void_void_ptr__LARGE_INTEGER *param_4,void *param_5)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  bool bVar4;
  undefined1 *puVar5;
  char cVar6;
  undefined1 uVar7;
  undefined8 *puVar8;
  HdaController *pHVar9;
  HdaController *pHVar10;
  long lVar11;
  undefined1 *puVar12;
  longlong lVar13;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined8 in_stack_ffffffffffffff98;
  undefined2 uVar14;
  
  cVar6 = KeGetCurrentIrql();
  bVar4 = true;
  if (cVar6 != '\0') {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,0xc1,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
LAB_14000a30b:
    lVar11 = -0x3fffffff;
    goto LAB_14000a532;
  }
  if (0x1d < (uint)param_2) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,0xc2,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar11 = -0x3ffffff8;
    goto LAB_14000a532;
  }
  if (param_3 == (_KEVENT *)0x0) {
    if (param_4 != (_func_void_void_ptr__LARGE_INTEGER *)0x0) goto LAB_14000a382;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar14 = 0xc3;
LAB_14000a367:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,uVar14,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
LAB_14000a378:
    lVar11 = -0x3ffffff3;
LAB_14000a532:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar4 = false;
    }
    if ((bVar4) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,199,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar11);
    }
    return lVar11;
  }
  if (param_4 != (_func_void_void_ptr__LARGE_INTEGER *)0x0) {
LAB_14000a382:
    if (param_1 == (_DEVICE_OBJECT *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
         (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar6 = '\0';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar14 = 0xc4;
        goto LAB_14000a367;
      }
      goto LAB_14000a378;
    }
  }
  lVar13 = (longlong)param_2 * 0xd8;
  if ((this[lVar13 + 0x20e] != (HdaController)0x0) &&
     ((this[lVar13 + 0x26c] == (HdaController)0x0 || (*(longlong *)(this + lVar13 + 0x298) != 0))))
  {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,0xc5,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar11 = -0x3ffffff0;
    goto LAB_14000a532;
  }
  puVar8 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x4e427a41);
  if (puVar8 == (undefined8 *)0x0) {
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,0xc6,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar11 = -0x3fffff66;
    goto LAB_14000a532;
  }
  puVar8[2] = param_3;
  puVar8[3] = param_1;
  puVar8[4] = param_4;
  puVar8[5] = param_5;
  uVar7 = KeAcquireSpinLockRaiseToDpc(this + lVar13 + 0x2a8);
  puVar12 = auStackY_88;
  pHVar9 = this + lVar13 + 0x2b0;
  if (*(HdaController **)pHVar9 != pHVar9) {
    for (pHVar10 = *(HdaController **)pHVar9; pHVar10 != pHVar9;
        pHVar10 = *(HdaController **)pHVar10) {
      if (((*(_KEVENT **)(pHVar10 + 0x10) == param_3) &&
          (*(_func_void_void_ptr__LARGE_INTEGER **)(pHVar10 + 0x20) == param_4)) &&
         (*(void **)(pHVar10 + 0x28) == param_5)) {
        KeReleaseSpinLock(this + lVar13 + 0x2a8,CONCAT71((int7)((ulonglong)pHVar10 >> 8),uVar7));
        ExFreePoolWithTag(puVar8,0x4e427a41);
        goto LAB_14000a30b;
      }
    }
  }
  puVar1 = *(undefined8 **)(pHVar9 + 8);
  if ((HdaController *)*puVar1 == pHVar9) {
    *puVar8 = pHVar9;
    puVar8[1] = puVar1;
    *puVar1 = puVar8;
    *(undefined8 **)(pHVar9 + 8) = puVar8;
    puVar5 = auStackY_88;
    if (param_4 == (_func_void_void_ptr__LARGE_INTEGER *)0x0) goto LAB_14000a224;
  }
  else {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar5 = auStackY_80;
  }
  puVar12 = puVar5;
  uVar2 = puVar8[3];
  *(undefined8 *)(puVar12 + -8) = 0x14000a4be;
  ObfReferenceObjectWithTag(uVar2,0x4e427a41);
LAB_14000a224:
  *(undefined8 *)(puVar12 + -8) = 0x14000a23f;
  KeReleaseSpinLock(this + (longlong)param_2 * 0xd8 + 0x2a8,uVar7);
  return 0;
}



===== DetachAudioBuffer @ 14000a59c =====

/* public: long __cdecl HdaController::DetachAudioBuffer(long,void * __ptr64 * __ptr64,unsigned
   __int64 * __ptr64,enum _HdaBufferType * __ptr64) __ptr64 */

long __thiscall
HdaController::DetachAudioBuffer
          (HdaController *this,long param_1,void **param_2,__uint64 *param_3,_HdaBufferType *param_4
          )

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  longlong lVar4;
  void *pvVar5;
  long lVar6;
  longlong lVar7;
  char cVar8;
  longlong lVar9;
  _HdaBufferType _Var10;
  undefined8 in_stack_ffffffffffffff78;
  void *local_58;
  __uint64 local_50;
  undefined8 local_48;
  
  local_48 = 0;
  local_58 = (void *)0x0;
  pvVar5 = (void *)0x0;
  local_50 = 0;
  _Var10 = 3;
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar8 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar8 = '\0';
  }
  if ((cVar3 != '\0') || (cVar8 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0xe5,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(byte)param_1);
  }
  if ((uint)param_1 < 0x1e) {
    lVar9 = (longlong)param_1;
    lVar7 = lVar9 * 0xd8;
    *param_2 = (void *)0x0;
    *param_3 = 0;
    *param_4 = 3;
    if ((this[lVar7 + 0x20e] == (HdaController)0x0) ||
       ((this[lVar7 + 0x26c] != (HdaController)0x0 && (*(longlong *)(this + lVar7 + 0x298) == 0))))
    {
      uVar2 = KeAcquireSpinLockRaiseToDpc(this + lVar7 + 0x200);
      if (this[lVar7 + 0x20c] == (HdaController)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar3 = '\0';
        }
        if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0xe8,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        lVar6 = -0x3ffffff8;
      }
      else if (*(int *)(this + lVar7 + 0x268) == 0) {
        *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
             ~(1 << ((byte)param_1 & 0x1f) & 0x3fffffffU) &
             *(uint *)(*(longlong *)(this + 0x58) + 0x20);
        LOCK();
        UNLOCK();
        lVar4 = ((ulonglong)(param_1 & 0xff) + 4) * 0x20;
        *(byte *)(lVar4 + *(longlong *)(this + 0x58)) =
             *(byte *)(lVar4 + *(longlong *)(this + 0x58)) & 0xf7;
        LOCK();
        UNLOCK();
        *(byte *)(lVar4 + *(longlong *)(this + 0x58)) =
             *(byte *)(lVar4 + *(longlong *)(this + 0x58)) & 0xef;
        LOCK();
        UNLOCK();
        *(byte *)(lVar4 + *(longlong *)(this + 0x58)) =
             *(byte *)(lVar4 + *(longlong *)(this + 0x58)) & 0xfb;
        LOCK();
        UNLOCK();
        if (this[lVar7 + 0x20e] != (HdaController)0x0) {
          _Var10 = *(_HdaBufferType *)(this + lVar7 + 0x240);
          if (_Var10 == 0) {
            local_58 = *(void **)(this + lVar7 + 0x218);
            local_50 = *(__uint64 *)(this + lVar7 + 0x238);
          }
          else if ((_Var10 == 1) || (_Var10 == 2)) {
            local_58 = *(void **)(this + lVar7 + 0x270);
            local_50 = *(__uint64 *)(this + lVar7 + 0x290);
          }
          local_48 = *(undefined8 *)(this + lVar7 + 0x250);
          pvVar5 = *(void **)(this + lVar7 + 0x248);
          *(undefined8 *)(this + lVar7 + 0x270) = 0;
          *(undefined8 *)(this + lVar7 + 0x290) = 0;
          *(undefined8 *)(this + lVar7 + 0x218) = 0;
          *(undefined8 *)(this + lVar7 + 0x238) = 0;
          this[lVar9 * 0xd8 + 0x26d] = (HdaController)0x0;
          *(undefined8 *)(this + lVar7 + 0x248) = 0;
          *(undefined8 *)(this + lVar7 + 0x250) = 0;
          this[lVar7 + 0x20e] = (HdaController)0x0;
          this[lVar7 + 0x26c] = (HdaController)0x0;
          *(undefined8 *)(this + lVar9 * 0xd8 + 0x298) = 0;
          *(undefined8 *)(this + lVar9 * 0xd8 + 0x2a0) = 0;
          this[lVar9 * 0xd8 + 0x26e] = (HdaController)0x0;
        }
        lVar6 = 0;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar3 = '\0';
        }
        if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0xe9,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        lVar6 = -0x3ffffff0;
      }
      KeReleaseSpinLock(this + lVar7 + 0x200,uVar2);
      if (local_58 != (void *)0x0) {
        *param_2 = local_58;
        *param_3 = local_50;
        *param_4 = _Var10;
      }
      if (pvVar5 != (void *)0x0) {
        if (this[0x9606] == (HdaController)0x0) {
          FreeContiguousBuffer(pvVar5,0x1000,0);
        }
        else {
          FreeBufferHal(*(undefined8 *)(this + 0x9650),0x1000,pvVar5,local_48);
        }
      }
      if (-1 < lVar6) {
        return lVar6;
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar3 = '\0';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0xe7,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      lVar6 = -0x3ffffff0;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0xe6,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar6 = -0x3ffffff8;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0xea,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar6);
  }
  return lVar6;
}



===== FreeDmaEngine @ 14000ab5c =====

/* public: long __cdecl HdaController::FreeDmaEngine(struct WDFDEVICE__ * __ptr64,long,unsigned
   char) __ptr64 */

long __thiscall
HdaController::FreeDmaEngine(HdaController *this,WDFDEVICE__ *param_1,long param_2,uchar param_3)

{
  bool bVar1;
  undefined1 uVar2;
  LinkBandwidth *this_00;
  HdaController *pHVar3;
  char cVar4;
  longlong lVar5;
  long lVar6;
  longlong lVar7;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 in_stack_ffffffffffffff90;
  undefined4 in_stack_ffffffffffffff94;
  undefined2 uVar8;
  undefined8 in_stack_ffffffffffffffa0;
  
  if (0x1d < (uint)param_2) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x7a,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar6 = -0x3ffffff8;
    goto LAB_14000af6e;
  }
  lVar7 = (longlong)param_2 * 0xd8;
  uVar2 = KeAcquireSpinLockRaiseToDpc(this + lVar7 + 0x200);
  if (this[lVar7 + 0x20c] == (HdaController)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x7b,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
LAB_14000ac35:
    lVar6 = -0x3ffffff8;
  }
  else {
    if ((param_1 != (WDFDEVICE__ *)0x0) && (*(WDFDEVICE__ **)(this + lVar7 + 0x2d0) != param_1)) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0 ||
          (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)))) {
        cVar4 = '\0';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_qdq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,
                   CONCAT44(in_stack_ffffffffffffff94,in_stack_ffffffffffffff90),0x7c,
                   in_stack_ffffffffffffffa0,(char)param_1,(char)param_2,
                   (char)*(WDFDEVICE__ **)(this + lVar7 + 0x2d0));
      }
      goto LAB_14000ac35;
    }
    if (*(int *)(this + lVar7 + 0x268) == 0) {
      if (this[lVar7 + 0x20e] != (HdaController)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           (bVar1 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
          bVar1 = false;
        }
        if ((bVar1 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar8 = 0x7e;
          goto LAB_14000ad04;
        }
        goto LAB_14000ad19;
      }
      if ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) != 0) {
        ResetDmaEngine(this,param_2);
      }
      pHVar3 = this;
      if ((*(int *)(this + lVar7 + 0x208) == 1) || (*(int *)(this + lVar7 + 0x208) == 4)) {
        this_00 = (LinkBandwidth *)GetOutputLinkBandwidth(this,param_3);
      }
      else {
        this_00 = (LinkBandwidth *)GetInputLinkBandwidth(this,param_3);
      }
      if (this_00 != (LinkBandwidth *)0x0) {
        LinkBandwidth::FreeBandwidth(this_00,*(long *)(this + lVar7 + 0x210));
        pHVar3 = (HdaController *)this_00;
      }
      if (((*(int *)(this + lVar7 + 0x208) == 1) || (*(int *)(this + lVar7 + 0x208) == 4)) &&
         (1 < *(ushort *)(this + 0x9670))) {
        pHVar3 = this;
        UnmapActiveStreamId(this,param_3,(uchar)this[lVar7 + 0x215]);
      }
      if ((*(int *)(this + lVar7 + 0x208) == 1) || (*(int *)(this + lVar7 + 0x208) == 4)) {
        FreeStreamId(pHVar3,(long *)(this + 0x1b5c),(uchar)this[lVar7 + 0x215]);
        lVar5 = 7000;
      }
      else {
        FreeStreamId(pHVar3,(long *)(this + 0x1b54),(uchar)this[lVar7 + 0x215]);
        lVar5 = 0x1b50;
      }
      LOCK();
      *(int *)(this + lVar5) = *(int *)(this + lVar5) + -1;
      UNLOCK();
      *(undefined2 *)(this + lVar7 + 0x214) = 0;
      *(undefined4 *)(this + lVar7 + 0x210) = 0;
      this[lVar7 + 0x20f] = (HdaController)0x0;
      if (*(int *)(this + lVar7 + 0x208) - 3U < 2) {
        *(undefined4 *)(this + lVar7 + 0x208) = 2;
      }
      if (this[lVar7 + 0x26c] != (HdaController)0x0) {
        *(undefined8 *)(this + lVar7 + 0x298) = 0;
        *(undefined8 *)(this + lVar7 + 0x2a0) = 0;
        this[lVar7 + 0x26e] = (HdaController)0x0;
        this[lVar7 + 0x26c] = (HdaController)0x0;
        KeRemoveQueueDpc(this + 0x9458);
      }
      this[lVar7 + 0x20c] = (HdaController)0x0;
      *(undefined8 *)(this + lVar7 + 0x2d0) = 0;
      lVar6 = 0;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (bVar1 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar8 = 0x7d;
LAB_14000ad04:
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,uVar8,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
LAB_14000ad19:
      lVar6 = -0x3ffffff0;
    }
  }
  KeReleaseSpinLock(this + lVar7 + 0x200,uVar2);
  UnregisterNotificationHandlers(this,param_2);
  if (-1 < lVar6) {
    return lVar6;
  }
LAB_14000af6e:
  cVar4 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x7f,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar6);
  }
  return lVar6;
}



===== FreeDmaBufferWithNotification @ 14000aff0 =====

/* public: long __cdecl HdaController::FreeDmaBufferWithNotification(struct WDFDEVICE__ *
   __ptr64,long,struct _MDL * __ptr64,unsigned __int64) __ptr64 */

long __thiscall
HdaController::FreeDmaBufferWithNotification
          (HdaController *this,WDFDEVICE__ *param_1,long param_2,_MDL *param_3,__uint64 param_4)

{
  undefined1 uVar1;
  char cVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  _MDL *local_res8;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 in_stack_ffffffffffffff60;
  undefined4 in_stack_ffffffffffffff64;
  undefined8 in_stack_ffffffffffffff70;
  longlong local_60;
  undefined8 local_58;
  
  local_60 = 0;
  local_58 = 0;
  uVar4 = 0;
  local_res8 = (_MDL *)0x0;
  uVar7 = 0;
  param_4 = 0;
  if (0x1d < (uint)param_2) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,0xe,0xbb,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    iVar5 = -0x3ffffff8;
    goto LAB_14000b48c;
  }
  lVar6 = (longlong)param_2 * 0xd8;
  if ((this[lVar6 + 0x20e] != (HdaController)0x0) &&
     ((this[lVar6 + 0x26c] == (HdaController)0x0 || (*(longlong *)(this + lVar6 + 0x298) != 0)))) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0 ||
        (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)))) {
      cVar2 = '\0';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,0xe,0xbc,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    iVar5 = -0x3ffffff0;
    goto LAB_14000b48c;
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(this + lVar6 + 0x200);
  if (this[lVar6 + 0x20c] == (HdaController)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,0xe,0xbd,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
LAB_14000b1b0:
    iVar5 = -0x3ffffff8;
  }
  else {
    if (*(WDFDEVICE__ **)(this + lVar6 + 0x2d0) != param_1) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar2 = '\0';
      }
      if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_qdq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,
                   CONCAT44(in_stack_ffffffffffffff64,in_stack_ffffffffffffff60),0xbe,
                   in_stack_ffffffffffffff70,(char)param_1,(byte)param_2,
                   (char)*(WDFDEVICE__ **)(this + lVar6 + 0x2d0));
      }
      goto LAB_14000b1b0;
    }
    if (*(int *)(this + lVar6 + 0x268) == 0) {
      *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
           ~(1 << ((byte)param_2 & 0x1f) & 0x3fffffffU) &
           *(uint *)(*(longlong *)(this + 0x58) + 0x20);
      LOCK();
      UNLOCK();
      uVar8 = (ulonglong)param_2;
      lVar3 = ((uVar8 & 0xff) + 4) * 0x20;
      *(byte *)(lVar3 + *(longlong *)(this + 0x58)) =
           *(byte *)(lVar3 + *(longlong *)(this + 0x58)) & 0xf7;
      LOCK();
      UNLOCK();
      *(byte *)(lVar3 + *(longlong *)(this + 0x58)) =
           *(byte *)(lVar3 + *(longlong *)(this + 0x58)) & 0xef;
      LOCK();
      UNLOCK();
      *(byte *)(lVar3 + *(longlong *)(this + 0x58)) =
           *(byte *)(lVar3 + *(longlong *)(this + 0x58)) & 0xfb;
      LOCK();
      UNLOCK();
      if (this[lVar6 + 0x20e] != (HdaController)0x0) {
        local_60 = *(longlong *)(this + lVar6 + 0x278);
        uVar4 = *(undefined8 *)(this + lVar6 + 0x280);
        uVar7 = *(undefined8 *)(this + lVar6 + 0x250);
        *(undefined8 *)(this + lVar6 + 0x230) = 0;
        *(undefined8 *)(this + lVar6 + 0x290) = 0;
        this[lVar6 + 0x20e] = (HdaController)0x0;
        this[lVar6 + 0x26d] = (HdaController)0x0;
        local_58 = *(undefined8 *)(this + (uVar8 + 3) * 0xd8);
        param_4 = *(__uint64 *)(this + lVar6 + 0x248);
        local_res8 = *(_MDL **)(this + lVar6 + 0x270);
        *(undefined8 *)(this + lVar6 + 0x270) = 0;
        *(undefined8 *)(this + lVar6 + 0x248) = 0;
        this[lVar6 + 0x26c] = (HdaController)0x0;
        *(undefined8 *)(this + uVar8 * 0xd8 + 0x298) = 0;
        *(undefined8 *)(this + uVar8 * 0xd8 + 0x2a0) = 0;
        this[uVar8 * 0xd8 + 0x26e] = (HdaController)0x0;
      }
      iVar5 = 0;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
        cVar2 = '\0';
      }
      if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,0xe,0xbf,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      iVar5 = -0x3ffffff0;
    }
  }
  KeReleaseSpinLock(this + lVar6 + 0x200,uVar1);
LAB_14000b48c:
  cVar2 = '\x01';
  if (this[0x9606] == (HdaController)0x0) {
    if (local_res8 != (_MDL *)0x0) {
      FreeBuffer(local_res8);
    }
    if (param_4 != 0) {
      FreeContiguousBuffer((void *)param_4,0x1000,0);
    }
  }
  else {
    if (local_res8 != (_MDL *)0x0) {
      FreeBufferMdl(local_res8);
    }
    if (local_60 != 0) {
      FreeBufferHal(*(undefined8 *)(this + 0x9650),local_58,local_60,uVar4);
    }
    if (param_4 != 0) {
      FreeBufferHal(*(undefined8 *)(this + 0x9650),0x1000,param_4,uVar7);
    }
  }
  if (iVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,0xe,0xc0,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar5);
    }
  }
  return iVar5;
}



===== SetDmaEngineState @ 14000b59c =====

/* private: long __cdecl HdaController::SetDmaEngineState(int,unsigned char) __ptr64 */

long __thiscall HdaController::SetDmaEngineState(HdaController *this,int param_1,uchar param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = ((longlong)param_1 + 4) * 0x20;
  if ((*(byte *)(lVar2 + *(longlong *)(this + 0x58)) >> 1 & 1) != param_2) {
    *(byte *)(lVar2 + *(longlong *)(this + 0x58)) =
         -(param_2 != '\0') & 2U | *(byte *)(lVar2 + *(longlong *)(this + 0x58)) & 0xfd;
    LOCK();
    UNLOCK();
    iVar1 = (-(uint)(param_2 != '\0') & 0xfffffe98) + 400;
    while ((*(byte *)(lVar2 + *(longlong *)(this + 0x58)) >> 1 & 1) != param_2) {
      if (iVar1 == 0) {
        return -0x3fffff4b;
      }
      KeStallExecutionProcessor(1);
      iVar1 = iVar1 + -1;
    }
  }
  return 0;
}



===== FreeStreamId @ 14000b65c =====

/* private: unsigned char __cdecl HdaController::FreeStreamId(long * __ptr64,unsigned char) __ptr64
    */

uchar __thiscall HdaController::FreeStreamId(HdaController *this,long *param_1,uchar param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    uVar3 = uVar1 & ~(1 << ((byte)(param_2 - 1) & 0x1f));
    LOCK();
    if (uVar1 == *param_1) {
      *param_1 = uVar3;
      uVar2 = uVar1;
    }
    else {
      uVar2 = *param_1;
    }
    UNLOCK();
  } while (uVar2 != uVar1);
  return uVar3 != uVar1;
}



===== UnregisterNotificationHandlers @ 14000b68c =====

/* private: long __cdecl HdaController::UnregisterNotificationHandlers(long) __ptr64 */

long __thiscall HdaController::UnregisterNotificationHandlers(HdaController *this,long param_1)

{
  HdaController *pHVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  long lVar8;
  longlong lVar9;
  undefined1 *puVar10;
  HdaController *pHVar11;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  undefined8 in_stack_ffffffffffffffc8;
  
  pHVar11 = (HdaController *)(longlong)param_1;
  cVar7 = KeGetCurrentIrql();
  puVar10 = auStackY_58;
  if (cVar7 == '\0') {
    if ((uint)param_1 < 0x1e) {
      lVar9 = (longlong)pHVar11 * 0xd8;
      pHVar11 = this + lVar9 + 0x2a8;
      KeAcquireSpinLockRaiseToDpc(pHVar11);
      while( true ) {
        pHVar1 = *(HdaController **)(this + lVar9 + 0x2b0);
        if (pHVar1 == this + lVar9 + 0x2b0) break;
        lVar2 = *(longlong *)pHVar1;
        if ((*(HdaController **)(lVar2 + 8) != pHVar1) ||
           (plVar3 = *(longlong **)(pHVar1 + 8), (HdaController *)*plVar3 != pHVar1)) {
          pcVar6 = (code *)swi(0x29);
          (*pcVar6)(3);
          puVar10 = auStackY_50;
          goto LAB_14000b808;
        }
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        KeReleaseSpinLock(pHVar11);
        if ((*(longlong *)(pHVar1 + 0x20) != 0) && (*(longlong *)(pHVar1 + 0x18) != 0)) {
          ObfDereferenceObjectWithTag(*(longlong *)(pHVar1 + 0x18),0x4e427a41);
        }
        ExFreePoolWithTag(pHVar1,0x4e427a41);
        KeAcquireSpinLockRaiseToDpc(pHVar11);
      }
      KeReleaseSpinLock(pHVar11);
      lVar8 = 0;
    }
    else {
LAB_14000b808:
      lVar8 = -0x3ffffff8;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined4 *)(puVar10 + 0x48) = 0xc0000008;
        *(int *)(puVar10 + 0x40) = (int)pHVar11;
        *(undefined **)(puVar10 + 0x38) = &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids;
        *(undefined2 *)(puVar10 + 0x30) = 0xce;
        *(undefined4 *)(puVar10 + 0x28) = 4;
        *(undefined8 *)(puVar10 + -8) = 0x14000b882;
        WPP_RECORDER_AND_TRACE_SF_dd
                  (uVar5,cVar7,(undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   uVar4,*(undefined8 *)(puVar10 + 0x20),*(undefined4 *)(puVar10 + 0x28),
                   *(undefined2 *)(puVar10 + 0x30),*(undefined8 *)(puVar10 + 0x38),puVar10[0x40],
                   puVar10[0x48]);
      }
    }
  }
  else {
    lVar8 = -0x3fffffff;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xcd,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,1);
    }
  }
  return lVar8;
}



===== FreeBandwidth @ 14000b890 =====

/* public: void __cdecl LinkBandwidth::FreeBandwidth(long) __ptr64 */

void __thiscall LinkBandwidth::FreeBandwidth(LinkBandwidth *this,long param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffc8;
  
  cVar4 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,0xe,0xe,
               &WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,(char)param_1);
  }
  LOCK();
  iVar2 = *(int *)(this + 0xc);
  if (param_1 == iVar2) {
    *(int *)(this + 0xc) = 0;
    iVar1 = param_1;
  }
  else {
    iVar1 = iVar2;
  }
  UNLOCK();
  if (param_1 != iVar2) {
    do {
      LOCK();
      iVar2 = *(int *)(this + 0xc);
      if (iVar1 == iVar2) {
        *(int *)(this + 0xc) = iVar1 - param_1;
        iVar2 = iVar1;
      }
      else {
      }
      UNLOCK();
      bVar5 = iVar2 != iVar1;
      iVar1 = iVar2;
    } while (bVar5);
  }
  return;
}



===== PowerDown @ 14000b958 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl HdaController::PowerDown(unsigned char) __ptr64 */

long __thiscall HdaController::PowerDown(HdaController *this,uchar param_1)

{
  HdaController *pHVar1;
  bool bVar2;
  undefined1 uVar3;
  char cVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  long lVar9;
  bool bVar10;
  undefined1 local_108 [32];
  undefined8 in_stack_ffffffffffffff18;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  long lStack_88;
  undefined4 local_78;
  undefined2 local_74;
  undefined2 uStack_72;
  undefined8 uStack_70;
  undefined4 uStack_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined8 local_54;
  undefined4 uStack_4c;
  undefined4 *puStack_48;
  undefined4 uStack_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_108;
  uStack_40 = 0;
  local_3c = 0;
  lStack_88 = 0;
  bVar2 = true;
  local_78 = 0;
  local_74 = 0;
  uStack_72 = 0;
  uStack_68 = 0;
  local_64 = 0;
  uStack_5c = 0;
  local_54 = 0;
  uStack_4c = 0;
  local_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  uStack_8c = 0;
  uStack_70 = 0;
  puStack_48 = (undefined4 *)0x0;
  if (((HDAudBusWmiLoggerEnableFlags & 2) != 0) &&
     (uStack_70 = 0, puStack_48 = (undefined4 *)0x0, 3 < HDAudBusWmiLoggerEnableLevel)) {
    puStack_48 = &local_98;
    local_78 = 0x40;
    local_a8 = 0xe7ad130f;
    uStack_a4 = 0x4969d1e6;
    uStack_a0 = 0x787d89ab;
    uStack_9c = 0xfea3e3bc;
    local_98 = 2;
    uStack_94 = 2;
    uStack_90 = 0;
    uStack_8c = 0;
    lStack_88 = 0;
    uStack_40 = 0x14;
    uStack_4c = 0x120000;
    local_74 = 0x402;
    local_64 = 0xe7ad130f00000000;
    uStack_5c = 0x787d89ab4969d1e6;
    local_54 = 0xfea3e3bc;
    uStack_70 = HDAudBusWmiLoggerHandle;
    iVar6 = IoWMIWriteEvent(&local_78);
    if (iVar6 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar4 = '\0';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff18,4,10,
                   &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
      }
    }
  }
  if (*(int *)(this + 0xe8) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff18,2,0x4f,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
  }
  LOCK();
  *(int *)(this + 0x120) = *(int *)(this + 0x120) + 1;
  UNLOCK();
  do {
    LOCK();
    bVar10 = *(int *)(this + 0xe8) == 0;
    if (bVar10) {
      *(int *)(this + 0xe8) = 0;
    }
    UNLOCK();
    if (bVar10) {
      LOCK();
      bVar10 = *(int *)(this + 0x124) == 0;
      if (bVar10) {
        *(int *)(this + 0x124) = 0;
      }
      UNLOCK();
      if (bVar10) break;
    }
    local_b0 = 0xffffffffffff3cb0;
    KeDelayExecutionThread(0,0,&local_b0);
  } while( true );
  SetCorbDmaState(this,'\0');
  SetRirbDmaState(this,'\0');
  uVar3 = KfRaiseIrql(2);
  uVar8 = 0;
  if (*(int *)(this + 0x168) + *(int *)(this + 0x16c) + *(int *)(this + 0x170) != 0) {
    do {
      lVar5 = uVar8 * 0xd8;
      KeAcquireSpinLockAtDpcLevel(this + lVar5 + 0x200);
      if ((this[lVar5 + 0x20c] != (HdaController)0x0) && (*(int *)(this + lVar5 + 0x268) == 2)) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 3)
            ))) {
          cVar4 = '\0';
        }
        else {
          cVar4 = '\x01';
        }
        if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff18,2,0x50,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)uVar8);
        }
        SetDmaEngineState(this,(int)uVar8,'\0');
      }
      KeReleaseSpinLockFromDpcLevel(this + lVar5 + 0x200);
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < (uint)(*(int *)(this + 0x170) + *(int *)(this + 0x168) + *(int *)(this + 0x16c)
                           ));
  }
  lVar9 = 0;
  iVar6 = 400;
  KeLowerIrql(uVar3);
  *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
       *(uint *)(*(longlong *)(this + 0x58) + 0x20) & 0x7fffffff;
  LOCK();
  UNLOCK();
  if (*(longlong *)(this + 0x50) != 0) {
    PcRemoveStreamResource();
    *(undefined8 *)(this + 0x50) = 0;
  }
  pHVar1 = this + 0x40;
  if (*(int *)pHVar1 != 0) {
    IoDisconnectInterruptEx(pHVar1);
    *(undefined8 *)pHVar1 = 0;
    *(undefined8 *)(this + 0x48) = 0;
  }
  *(uint *)(*(longlong *)(this + 0x58) + 8) = *(uint *)(*(longlong *)(this + 0x58) + 8) & 0xfffffffe
  ;
  LOCK();
  UNLOCK();
  do {
    if ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) == 0) {
LAB_14000baf5:
      local_3c = 0;
      uStack_72 = 0;
      uStack_68 = 0;
      if (((HDAudBusWmiLoggerEnableFlags & 2) != 0) && (3 < HDAudBusWmiLoggerEnableLevel)) {
        puStack_48 = &local_98;
        local_98 = 2;
        uStack_94 = 2;
        local_78 = 0x40;
        uStack_70._0_4_ = (undefined4)HDAudBusWmiLoggerHandle;
        uStack_70._4_4_ = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
        uStack_90 = 0xff;
        uStack_8c = 0;
        uStack_40 = 0x14;
        uStack_4c = 0x120000;
        local_74 = 0x402;
        local_64 = 0xe7ad130f00000000;
        uStack_5c = 0x787d89ab4969d1e6;
        local_54 = 0xfea3e3bc;
        lStack_88 = lVar9;
        iVar6 = IoWMIWriteEvent(&local_78);
        if (iVar6 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            bVar2 = false;
          }
          if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_d
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff18,4,10,
                       &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar6);
          }
        }
      }
      return lVar9;
    }
    if (iVar6 == 0) {
      lVar9 = -0x3fffff4b;
      goto LAB_14000baf5;
    }
    KeStallExecutionProcessor(1);
    iVar6 = iVar6 + -1;
  } while( true );
}



===== SetRirbDmaState @ 14000bec8 =====

/* private: long __cdecl HdaController::SetRirbDmaState(unsigned char) __ptr64 */

long __thiscall HdaController::SetRirbDmaState(HdaController *this,uchar param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 in_stack_ffffffffffffffcc;
  
  *(byte *)(*(longlong *)(this + 0x58) + 0x5c) =
       -(param_1 != '\0') & 2U | *(byte *)(*(longlong *)(this + 0x58) + 0x5c) & 0xfd;
  LOCK();
  UNLOCK();
  bVar1 = true;
  iVar2 = (-(uint)(param_1 != '\0') & 0xfffffe98) + 400;
  do {
    if ((*(byte *)(*(longlong *)(this + 0x58) + 0x5c) >> 1 & 1) == param_1) {
      iVar2 = 0;
LAB_14000bf35:
      if (param_1 == '\0') {
        if (iVar2 < 0) {
          LOCK();
          *(uint *)(this + 0x94a0) = *(uint *)(this + 0x94a0) | 2;
          UNLOCK();
        }
        else {
          LOCK();
          *(uint *)(this + 0x94a0) = *(uint *)(this + 0x94a0) & 0xfffffffd;
          UNLOCK();
        }
      }
      return iVar2;
    }
    if (iVar2 == 0) {
      uVar3 = 4;
      HDABusWmiLogETW(1,2,'\x05','\x03',4,0,0,0);
      iVar2 = -0x3fffff4b;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffffcc,uVar3),0xd,0x23,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xb5);
      }
      goto LAB_14000bf35;
    }
    KeStallExecutionProcessor();
    iVar2 = iVar2 + -1;
  } while( true );
}



===== SetCorbDmaState @ 14000c030 =====

/* private: long __cdecl HdaController::SetCorbDmaState(unsigned char) __ptr64 */

long __thiscall HdaController::SetCorbDmaState(HdaController *this,uchar param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 in_stack_ffffffffffffffcc;
  
  *(byte *)(*(longlong *)(this + 0x58) + 0x4c) =
       -(param_1 != '\0') & 2U | *(byte *)(*(longlong *)(this + 0x58) + 0x4c) & 0xfd;
  LOCK();
  UNLOCK();
  iVar2 = 0x28;
  if (param_1 == '\0') {
    iVar2 = 400;
  }
  do {
    if ((*(byte *)(*(longlong *)(this + 0x58) + 0x4c) >> 1 & 1) == param_1) {
      iVar2 = 0;
LAB_14000c08f:
      if (param_1 == '\0') {
        if (-1 < iVar2) {
          LOCK();
          *(uint *)(this + 0x94a0) = *(uint *)(this + 0x94a0) & 0xfffffffe;
          UNLOCK();
          return iVar2;
        }
        LOCK();
        *(uint *)(this + 0x94a0) = *(uint *)(this + 0x94a0) | 1;
        UNLOCK();
      }
      return iVar2;
    }
    if (iVar2 == 0) {
      uVar3 = 6;
      HDABusWmiLogETW(1,4,'\x04','\x03',6,0,0,0);
      iVar2 = -0x3fffff4b;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar1 = '\0';
      }
      else {
        cVar1 = '\x01';
      }
      if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffffcc,uVar3),0xd,0x22,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xb5);
      }
      goto LAB_14000c08f;
    }
    KeStallExecutionProcessor();
    iVar2 = iVar2 + -1;
  } while( true );
}



===== NotificationDpc @ 14000c1a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl HdaController::NotificationDpc(struct _KDPC * __ptr64,void *
   __ptr64,void * __ptr64,void * __ptr64) */

void __cdecl
HdaController::NotificationDpc(_KDPC *param_1,void *param_2,void *param_3,void *param_4)

{
  undefined8 *puVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 auStackY_e8 [32];
  undefined8 in_stack_ffffffffffffff38;
  undefined4 local_90;
  undefined4 uStack_8c;
  int iStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  uint local_78;
  undefined2 local_74;
  undefined2 uStack_72;
  undefined8 uStack_70;
  undefined4 uStack_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined8 local_54;
  undefined4 uStack_4c;
  undefined4 *puStack_48;
  undefined4 uStack_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  uStack_40 = 0;
  local_3c = 0;
  local_78 = (uint)(ushort)local_78;
  local_74 = 0;
  uStack_72 = 0;
  uStack_68 = 0;
  local_64 = 0;
  uStack_5c = 0;
  local_54 = 0;
  uStack_4c = 0;
  uStack_70 = 0;
  puStack_48 = (undefined4 *)0x0;
  if (((HDAudBusWmiLoggerEnableFlags & 4) != 0) &&
     (uStack_70 = 0, puStack_48 = (undefined4 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
    puStack_48 = &local_90;
    local_78 = 0x40;
    local_90 = 3;
    uStack_8c = 0;
    iStack_88 = 0;
    uStack_84 = 0;
    uStack_80 = 0;
    uStack_40 = 0x14;
    uStack_4c = 0x120000;
    local_74 = 0x503;
    local_64 = 0xaef818d800000000;
    uStack_5c = 0x685376a74fb20878;
    local_54 = 0xa17ab383;
    uStack_70 = HDAudBusWmiLoggerHandle;
    iVar5 = IoWMIWriteEvent(&local_78);
    if (iVar5 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,4,10,
                   &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar5);
      }
    }
  }
  iVar5 = 0;
  puVar4 = (undefined4 *)((longlong)param_3 + 600);
  do {
    if ((*(char *)((longlong)puVar4 + -0x4b) != '\0') && (*(char *)(puVar4 + 0x1a) != '\0')) {
      KeAcquireSpinLockRaiseToDpc(puVar4 + 0x14);
      for (puVar1 = *(undefined8 **)(puVar4 + 0x16); puVar1 != (undefined8 *)(puVar4 + 0x16);
          puVar1 = (undefined8 *)*puVar1) {
        if (puVar1[2] == 0) {
          (*(code *)puVar1[4])(puVar1[5]);
        }
        else {
          local_78 = 0;
          uStack_40 = 0;
          local_3c = 0;
          uStack_80 = 0;
          local_74 = 0;
          uStack_72 = 0;
          uStack_70._0_4_ = 0;
          uStack_70._4_4_ = 0;
          uStack_68 = 0;
          local_64 = 0;
          uStack_5c = 0;
          local_54 = 0;
          uStack_4c = 0;
          local_90 = 0;
          uStack_8c = 0;
          iStack_88 = 0;
          uStack_84 = 0;
          puStack_48 = (undefined4 *)0x0;
          if (((HDAudBusWmiLoggerEnableFlags & 8) != 0) &&
             (puStack_48 = (undefined4 *)0x0, 4 < HDAudBusWmiLoggerEnableLevel)) {
            uStack_84 = puVar4[-0x14];
            uStack_80 = *puVar4;
            puStack_48 = &local_90;
            local_78 = 0x40;
            uStack_70._0_4_ = (undefined4)HDAudBusWmiLoggerHandle;
            uStack_70._4_4_ = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
            local_90 = 2;
            uStack_8c = 0;
            uStack_40 = 0x14;
            uStack_4c = 0x120000;
            local_74 = 0x502;
            local_64 = 0xaef818d800000000;
            uStack_5c = 0x685376a74fb20878;
            local_54 = 0xa17ab383;
            iStack_88 = iVar5;
            iVar2 = IoWMIWriteEvent(&local_78);
            if (iVar2 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                cVar3 = '\0';
              }
              else {
                cVar3 = '\x01';
              }
              if ((cVar3 != '\0') ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_AND_TRACE_SF_d
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,4,10
                           ,&WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar2);
              }
            }
          }
          KeSetEvent(puVar1[2],0,0);
        }
      }
      *(undefined1 *)(puVar4 + 0x1a) = 0;
      KeReleaseSpinLock(puVar4 + 0x14);
    }
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 0x36;
  } while (iVar5 < 0x1e);
  local_3c = 0;
  uStack_72 = 0;
  uStack_68 = 0;
  if (((HDAudBusWmiLoggerEnableFlags & 8) != 0) && (4 < HDAudBusWmiLoggerEnableLevel)) {
    puStack_48 = &local_90;
    local_90 = 3;
    uStack_8c = 0xff;
    iStack_88 = 0;
    local_78 = 0x40;
    uStack_70._0_4_ = (undefined4)HDAudBusWmiLoggerHandle;
    uStack_70._4_4_ = (undefined4)(HDAudBusWmiLoggerHandle >> 0x20);
    uStack_84 = 0;
    uStack_80 = 0;
    uStack_40 = 0x14;
    uStack_4c = 0x120000;
    local_74 = 0x503;
    local_64 = 0xaef818d800000000;
    uStack_5c = 0x685376a74fb20878;
    local_54 = 0xa17ab383;
    iVar5 = IoWMIWriteEvent(&local_78);
    if (iVar5 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,4,10,
                   &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar5);
      }
    }
  }
  return;
}



===== operator_new @ 14000c610 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64,enum _POOL_TYPE,unsigned long) */

void * __cdecl operator_new(__uint64 param_1,_POOL_TYPE param_2,ulong param_3)

{
  void *_Dst;
  undefined4 in_register_00000084;
  
  _Dst = (void *)ExAllocatePoolWithTag(param_2,param_1,CONCAT44(in_register_00000084,param_3));
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



===== Release @ 14000c660 =====

/* public: unsigned long __cdecl HdaController::Release(void) __ptr64 */

ulong __thiscall HdaController::Release(HdaController *this)

{
  int iVar1;
  
  LOCK();
  iVar1 = *(int *)this;
  *(int *)this = *(int *)this + -1;
  UNLOCK();
  if ((iVar1 - 1U == 0) && (this != (HdaController *)0x0)) {
    ~HdaController(this);
    ExFreePoolWithTag(this,0);
  }
  return iVar1 - 1U;
}



===== HdAudBusGraphicsPowerNotificationCallback @ 14000c6b0 =====

/* void __cdecl HdAudBusGraphicsPowerNotificationCallback(void * __ptr64,enum
   _DEVICE_POWER_STATE,unsigned char,void * __ptr64) */

void __cdecl
HdAudBusGraphicsPowerNotificationCallback
          (void *param_1,_DEVICE_POWER_STATE param_2,uchar param_3,void *param_4)

{
  char cVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qqdd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqdd @ 14000c73c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqdd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0x7d,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,0xd,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0x7d,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== CalculateBandwidth @ 14000c880 =====

/* public: virtual long __cdecl OutputLinkBandwidth::CalculateBandwidth(long * __ptr64,unsigned
   short,unsigned short,unsigned short,unsigned char) __ptr64 */

long __thiscall
OutputLinkBandwidth::CalculateBandwidth
          (OutputLinkBandwidth *this,long *param_1,ushort param_2,ushort param_3,ushort param_4,
          uchar param_5)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  char cVar6;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 in_stack_ffffffffffffffa0;
  undefined4 in_stack_ffffffffffffffa4;
  undefined8 in_stack_ffffffffffffffb0;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  if ((cVar3 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_DDDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,
               CONCAT44(in_stack_ffffffffffffffa4,in_stack_ffffffffffffffa0),0x11,
               in_stack_ffffffffffffffb0,(char)*param_1,(char)param_2,(char)param_3,(char)param_4,
               param_5);
  }
  iVar4 = ((param_2 >> 3 & 7) + 1) * (uint)param_3 * (uint)param_4;
  iVar2 = iVar4 * 6000 + *(int *)(this + 0x10);
  if (param_5 != '\0') {
    if (iVar4 < 0x10) {
      lVar5 = -0x3ffffff3;
      goto LAB_14000c9ea;
    }
    iVar2 = iVar2 / 2;
  }
  if (iVar2 <= *(int *)(this + 8)) {
    *param_1 = iVar2;
    return 0;
  }
  lVar5 = -0x3fffff66;
LAB_14000c9ea:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,0xe,0x12,
               &WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,(char)lVar5);
  }
  return lVar5;
}



===== HdAudBusUpdateS0IdleSettings @ 14000ca64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl HdAudBusUpdateS0IdleSettings(struct WDFDEVICE__ * __ptr64,unsigned char) */

long __cdecl HdAudBusUpdateS0IdleSettings(WDFDEVICE__ *param_1,uchar param_2)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined1 auStack_b8 [64];
  WDFDEVICE__ *local_78;
  uint local_70;
  undefined4 local_68;
  uint local_60;
  int local_58;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  local_44 = *(int *)(lVar2 + 0xb8);
  local_40 = 0;
  local_48 = 0x24;
  local_38 = 2;
  local_30 = 2;
  if (local_44 == 1) {
    local_40 = 4;
  }
  else if ((local_44 == 2) || (local_44 == 3)) {
    local_40 = 5;
  }
  local_3c = 1000;
  local_2c = 2;
  local_34 = (uint)(param_2 != '\0');
  local_28 = (uint)(*(char *)(lVar2 + 0xc0) == '\0');
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x170))(WdfDriverGlobals,param_1,&local_48);
  iVar4 = 0;
  if (iVar1 < 0) {
    iVar4 = iVar1;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     ((int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((iVar4 >> 0x1f & 0xfffffffeU) + 4))) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    local_60 = (uint)*(byte *)(lVar2 + 0xc0);
    local_68 = *(undefined4 *)(lVar2 + 0xb8);
    local_70 = (uint)param_2;
    local_78 = param_1;
    local_58 = iVar4;
    WPP_RECORDER_AND_TRACE_SF_qdddd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return iVar4;
}



===== WPP_RECORDER_AND_TRACE_SF_qdddd @ 14000cc1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qdddd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0x27,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,2,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0x27,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  return;
}



===== CalculateBandwidth @ 14000cd80 =====

/* public: virtual long __cdecl InputLinkBandwidth::CalculateBandwidth(long * __ptr64,unsigned
   short,unsigned short,unsigned short,unsigned char) __ptr64 */

long __thiscall
InputLinkBandwidth::CalculateBandwidth
          (InputLinkBandwidth *this,long *param_1,ushort param_2,ushort param_3,ushort param_4,
          uchar param_5)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  char cVar5;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 in_stack_ffffffffffffff90;
  undefined4 in_stack_ffffffffffffff94;
  undefined8 in_stack_ffffffffffffffa0;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar5 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  if ((cVar2 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_DDDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,
               CONCAT44(in_stack_ffffffffffffff94,in_stack_ffffffffffffff90),0xf,
               in_stack_ffffffffffffffa0,(char)*param_1,(char)param_2,(char)param_3,(char)param_4,
               param_5);
  }
  iVar3 = *(int *)(this + 0x10) + 0x23280 +
          (int)(((param_2 >> 3 & 7) + 1) * (uint)param_3 * (uint)param_4 * 48000) / 8;
  if (*(int *)(this + 8) < iVar3) {
    lVar4 = -0x3fffff66;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x10,
                 &WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,0x9a);
    }
  }
  else {
    *param_1 = iVar3;
    lVar4 = 0;
  }
  return lVar4;
}



===== WaitForSgpcLink @ 14000cf44 =====

/* public: long __cdecl HdaController::WaitForSgpcLink(void) __ptr64 */

long __thiscall HdaController::WaitForSgpcLink(HdaController *this)

{
  char cVar1;
  long lVar2;
  ushort uVar3;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar2 = 0;
  if ((*(longlong *)(this + 0x96b0) != 0) &&
     ((*(uint *)(*(longlong *)(this + 0x96b0) + 4) >> 0x17 & 1) == 0)) {
    uVar3 = 0;
    do {
      if ((*(uint *)(*(longlong *)(this + 0x96b0) + 4) >> 0x17 & 1) != 0) {
        return 0;
      }
      KeStallExecutionProcessor(1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 100);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar1 = '\0';
    }
    if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0xe2,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar2 = -0x3fffff4b;
  }
  return lVar2;
}



===== WPP_RECORDER_AND_TRACE_SF_ @ 14000d02c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,param_6,param_8,param_7,0);
  }
  return;
}



===== GetChildID @ 14000d0b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GetChildID(undefined4 *param_1,undefined8 param_2)

{
  *param_1 = 0x18;
  (**(code **)(WdfFunctions_01025 + 0x6f0))(WdfDriverGlobals,param_2,param_1);
  return;
}



===== SearchForDescriptionFromDeviceList @ 14000d0e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl SearchForDescriptionFromDeviceList(struct WDFCHILDLIST__ * __ptr64,unsigned
   short,struct _ChildIdentificationDescription * __ptr64) */

uchar __cdecl
SearchForDescriptionFromDeviceList
          (WDFCHILDLIST__ *param_1,ushort param_2,_ChildIdentificationDescription *param_3)

{
  int iVar1;
  char cVar2;
  char cVar3;
  uchar uVar4;
  undefined8 local_res18 [2];
  undefined8 in_stack_ffffffffffffff58;
  undefined8 *puVar5;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  _ChildIdentificationDescription *local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_78 = 0x28;
  local_res18[0] = 0;
  local_74 = 7;
  uVar4 = '\0';
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (param_3 == (_ChildIdentificationDescription *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,4,0x54,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
    uVar4 = '\0';
  }
  else {
    (**(code **)(WdfFunctions_01025 + 0x30))(WdfDriverGlobals,param_1,&local_78);
    do {
      local_50 = 0x28;
      local_30 = 0;
      *(undefined8 *)param_3 = 0;
      *(undefined8 *)(param_3 + 8) = 0;
      *(undefined8 *)(param_3 + 0x10) = 0;
      puVar5 = &local_50;
      *(undefined4 *)param_3 = 0x18;
      local_40 = 0;
      uStack_38 = 0;
      local_48 = param_3;
      iVar1 = (**(code **)(WdfFunctions_01025 + 0x38))
                        (WdfDriverGlobals,param_1,&local_78,local_res18);
      cVar3 = '\x01';
      if (iVar1 < 0) goto LAB_14000d22d;
    } while (param_2 != (byte)param_3[0x12]);
    uVar4 = '\x01';
LAB_14000d22d:
    (**(code **)(WdfFunctions_01025 + 0x40))(WdfDriverGlobals,param_1,&local_78);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
       (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar2 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar3 = '\0';
    }
    if ((cVar2 != '\0') || (cVar3 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_D
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,0xd,0x55,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar4);
    }
  }
  return uVar4;
}



===== FreeDmaBuffer @ 14000d2f0 =====

/* public: static long __cdecl HdaBusInterface::FreeDmaBuffer(void * __ptr64,void * __ptr64) */

long __cdecl HdaBusInterface::FreeDmaBuffer(void *param_1,void *param_2)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  _HdaBufferType local_res8 [4];
  long local_res18 [2];
  undefined4 local_res20;
  undefined4 uStackX_24;
  DmaAdapterTracker **in_stack_ffffffffffffff68;
  undefined4 uVar4;
  void *local_68;
  DmaAdapterTracker *local_60;
  __uint64 local_58;
  void *local_50;
  HdaController *local_48 [2];
  
  local_res18[0] = -1;
  local_50 = (void *)0x0;
  local_58 = 0;
  local_48[0] = (HdaController *)0x0;
  local_60 = (DmaAdapterTracker *)0x0;
  bVar1 = true;
  local_68 = (void *)0x0;
  local_res20 = 0;
  local_res8[0] = 3;
  uStackX_24 = 0;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)local_48);
    uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
    if (uVar2 == '\0') {
LAB_14000d420:
      in_stack_ffffffffffffff68 = &local_60;
      iVar3 = RetrieveAudioBufferInfo
                        (param_1,param_2,&local_50,&local_58,in_stack_ffffffffffffff68,&local_68,
                         (_LARGE_INTEGER *)&local_res20,local_res8);
      if (iVar3 < 0) goto LAB_14000d488;
      in_stack_ffffffffffffff68 = (DmaAdapterTracker **)CONCAT44(uStackX_24,local_res20);
      iVar3 = HdaController::FreeDetachedAudioBuffer
                        (local_50,local_58,local_60,local_68,in_stack_ffffffffffffff68,local_res8[0]
                        );
    }
    else {
      uVar2 = ConvertHandleToLong(param_1,param_2,local_res18);
      this = local_48[0];
      if (uVar2 == '\0') goto LAB_14000d420;
      in_stack_ffffffffffffff68 = (DmaAdapterTracker **)CONCAT44(uVar4,0x20);
      iVar3 = IoAcquireRemoveLockEx(local_48[0] + 8,param_1,"",1);
      if (iVar3 == 0) {
        iVar3 = HdaController::FreeDmaBuffer
                          (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),local_res18[0]);
        IoReleaseRemoveLockEx(this + 8,param_1,0x20);
      }
      if (-1 < iVar3) {
        RetrieveAudioBufferInfo
                  (param_1,param_2,&local_50,&local_58,&local_60,&local_68,
                   (_LARGE_INTEGER *)&local_res20,local_res8);
        goto LAB_14000d4f6;
      }
      if ((iVar3 == -0x3ffffff8) || (iVar3 == -0x3fffffaa)) goto LAB_14000d420;
    }
    if (-1 < iVar3) goto LAB_14000d4f6;
  }
LAB_14000d488:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,4,0x14,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14000d4f6:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)local_48);
  return iVar3;
}



===== FreeDmaBuffer @ 14000d51c =====

/* public: long __cdecl HdaController::FreeDmaBuffer(struct WDFDEVICE__ * __ptr64,long) __ptr64 */

long __thiscall HdaController::FreeDmaBuffer(HdaController *this,WDFDEVICE__ *param_1,long param_2)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  _MDL *p_Var8;
  void *local_res8;
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff80;
  undefined4 in_stack_ffffffffffffff84;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 local_48;
  
  local_48 = 0;
  p_Var8 = (_MDL *)0x0;
  uVar4 = 0;
  local_res20 = 0;
  uVar7 = 0;
  local_res8 = (void *)0x0;
  if (0x1d < (uint)param_2) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x75,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    iVar5 = -0x3ffffff8;
    goto LAB_14000d7f3;
  }
  lVar6 = (longlong)param_2 * 0xd8;
  uVar2 = KeAcquireSpinLockRaiseToDpc(this + lVar6 + 0x200);
  if (this[lVar6 + 0x20c] == (HdaController)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xd & 1) == 0)) ||
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x76,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
LAB_14000d608:
    iVar5 = -0x3ffffff8;
  }
  else {
    if (*(WDFDEVICE__ **)(this + lVar6 + 0x2d0) != param_1) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xd & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_qdq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,
                   CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80),0x77,
                   in_stack_ffffffffffffff90,(char)param_1,(char)param_2,
                   (char)*(WDFDEVICE__ **)(this + lVar6 + 0x2d0));
      }
      goto LAB_14000d608;
    }
    if (*(int *)(this + lVar6 + 0x268) == 0) {
      if (this[lVar6 + 0x20e] != (HdaController)0x0) {
        local_res20 = *(longlong *)(this + lVar6 + 0x220);
        p_Var8 = *(_MDL **)(this + lVar6 + 0x218);
        uVar4 = *(undefined8 *)(this + lVar6 + 0x228);
        uVar7 = *(undefined8 *)(this + lVar6 + 0x250);
        local_48 = *(undefined8 *)(this + lVar6 + 0x230);
        local_res8 = *(void **)(this + lVar6 + 0x248);
        *(undefined8 *)(this + lVar6 + 0x230) = 0;
        *(undefined8 *)(this + lVar6 + 0x218) = 0;
        *(undefined8 *)(this + lVar6 + 0x238) = 0;
        *(undefined8 *)(this + lVar6 + 0x248) = 0;
      }
      this[lVar6 + 0x20e] = (HdaController)0x0;
      iVar5 = 0;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xd & 1) == 0)) ||
         (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
        cVar3 = '\0';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x78,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      iVar5 = -0x3ffffff0;
    }
  }
  KeReleaseSpinLock(this + lVar6 + 0x200,uVar2);
LAB_14000d7f3:
  bVar1 = true;
  if (this[0x9606] == (HdaController)0x0) {
    if (p_Var8 != (_MDL *)0x0) {
      FreeBuffer(p_Var8);
    }
    if (local_res8 != (void *)0x0) {
      FreeContiguousBuffer(local_res8,0x1000,0);
    }
  }
  else {
    if (p_Var8 != (_MDL *)0x0) {
      FreeBufferMdl(p_Var8);
    }
    if (local_res20 != 0) {
      FreeBufferHal(*(undefined8 *)(this + 0x9650),local_48,local_res20,uVar4);
    }
    if (local_res8 != (void *)0x0) {
      FreeBufferHal(*(undefined8 *)(this + 0x9650),0x1000,local_res8,uVar7);
    }
  }
  if (iVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,0xe,0x79,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar5);
    }
  }
  return iVar5;
}



===== FreeCodecResponseTag @ 14000d904 =====

/* private: unsigned char __cdecl HdaController::FreeCodecResponseTag(long * __ptr64 const,unsigned
   char) __ptr64 */

uchar __thiscall
HdaController::FreeCodecResponseTag(HdaController *this,long *param_1,uchar param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    uVar3 = uVar1 & ~(1 << (param_2 & 0x1f));
    LOCK();
    uVar2 = param_1[param_2 >> 5];
    if (uVar1 == uVar2) {
      param_1[param_2 >> 5] = uVar3;
      uVar2 = uVar1;
    }
    else {
    }
    UNLOCK();
  } while (uVar2 != uVar1);
  return uVar3 != uVar1;
}



===== UnregisterNotificationCallback @ 14000d940 =====

/* public: static long __cdecl HdaBusInterface3::UnregisterNotificationCallback(void * __ptr64,void
   * __ptr64,void (__cdecl*)(void * __ptr64,union _LARGE_INTEGER),void * __ptr64) */

long __cdecl
HdaBusInterface3::UnregisterNotificationCallback
          (void *param_1,void *param_2,_func_void_void_ptr__LARGE_INTEGER *param_3,void *param_4)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  long local_res8 [2];
  void *in_stack_ffffffffffffff98;
  HdaController *local_38 [2];
  
  local_res8[0] = -1;
  local_38[0] = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = HdaBusInterface::GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)local_38);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar2 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res8);
      this = local_38[0];
      if (uVar2 == '\0') {
        iVar3 = -0x3ffffff8;
      }
      else {
        in_stack_ffffffffffffff98 =
             (void *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff98 >> 0x20),0x20);
        iVar3 = IoAcquireRemoveLockEx(local_38[0] + 8,param_1,"",1);
        if (iVar3 == 0) {
          iVar3 = HdaController::UnregisterNotificationHandler
                            (this,local_res8[0],(_KEVENT *)0x0,param_3,param_4);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
          in_stack_ffffffffffffff98 = param_4;
        }
        if (-1 < iVar3) goto LAB_14000da8d;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,0x21,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14000da8d:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)local_38);
  return iVar3;
}



===== RegisterEventCallback @ 14000dac0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl HdaBusInterface::RegisterEventCallback(void * __ptr64,void
   (__cdecl*)(struct _HDAUDIO_CODEC_RESPONSE,void * __ptr64),void * __ptr64,unsigned char * __ptr64)
    */

long __cdecl
HdaBusInterface::RegisterEventCallback
          (void *param_1,_func_void__HDAUDIO_CODEC_RESPONSE_void_ptr *param_2,void *param_3,
          uchar *param_4)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  undefined1 auStackY_b8 [32];
  void *in_stack_ffffffffffffff68;
  HdaController *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68 = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_68);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      local_50 = 0;
      uStack_58 = 0;
      local_60 = 0x18;
      (**(code **)(WdfFunctions_01025 + 0x6f0))
                (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),&local_60);
      this = local_68;
      in_stack_ffffffffffffff68 =
           (void *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff68 >> 0x20),0x20);
      iVar3 = IoAcquireRemoveLockEx(local_68 + 8,param_1,"",1);
      if (iVar3 == 0) {
        iVar3 = HdaController::RegisterEventCallback
                          (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),local_50._2_1_,param_2,
                           param_3,param_4);
        IoReleaseRemoveLockEx(this + 8,param_1,0x20);
        in_stack_ffffffffffffff68 = param_3;
      }
      if (-1 < iVar3) goto LAB_14000dc41;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,4,0x18,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14000dc41:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_68);
  return iVar3;
}



===== WPP_RECORDER_AND_TRACE_SF_dd @ 14000dc7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_dd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,param_6,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  return;
}



===== UnregisterEventCallback @ 14000dd50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl HdaBusInterface::UnregisterEventCallback(void * __ptr64,unsigned
   char) */

long __cdecl HdaBusInterface::UnregisterEventCallback(void *param_1,uchar param_2)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  undefined1 auStackY_a8 [32];
  undefined4 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  HdaController *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_58);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      local_40 = 0;
      uStack_48 = 0;
      local_50 = 0x18;
      (**(code **)(WdfFunctions_01025 + 0x6f0))
                (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),&local_50);
      this = local_58;
      in_stack_ffffffffffffff78 = 0x20;
      iVar3 = IoAcquireRemoveLockEx(local_58 + 8,param_1,"",1);
      if (iVar3 == 0) {
        iVar3 = HdaController::UnregisterEventCallback(this,local_40._2_1_,param_2);
        IoReleaseRemoveLockEx(this + 8,param_1,0x20);
      }
      if (-1 < iVar3) goto LAB_14000deb3;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),4,0x19,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14000deb3:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_58);
  return iVar3;
}



===== StatusChangeDpc @ 14000def0 =====

/* private: static void __cdecl HdaController::StatusChangeDpc(struct _KDPC * __ptr64,void *
   __ptr64,void * __ptr64,void * __ptr64) */

void __cdecl
HdaController::StatusChangeDpc(_KDPC *param_1,void *param_2,void *param_3,void *param_4)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,4,0xb,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
  }
  CompleteWaitWakeRequests(param_2);
  return;
}



===== CompleteWaitWakeRequests @ 14000df78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl HdaController::CompleteWaitWakeRequests(void) __ptr64 */

void __thiscall HdaController::CompleteWaitWakeRequests(HdaController *this)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  if (*(int *)(this + 0x94ac) != 0) {
    lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0x70),
                       PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
    if (*(int *)(lVar2 + 0x18) != 0) {
      uVar3 = (**(code **)(WdfFunctions_01025 + 0x420))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0x70));
      local_58 = 0;
      local_50 = 0x28;
      local_4c = 1;
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      uStack_30 = 0;
      (**(code **)(WdfFunctions_01025 + 0x30))(WdfDriverGlobals,uVar3,&local_50);
      while( true ) {
        local_68 = 0;
        iVar1 = (**(code **)(WdfFunctions_01025 + 0x38))(WdfDriverGlobals,uVar3,&local_50,&local_58)
        ;
        if (iVar1 < 0) break;
        lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                          (WdfDriverGlobals,local_58,
                           PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
        uStack_20 = 0;
        local_18 = 0;
        local_28 = 0x18;
        (**(code **)(WdfFunctions_01025 + 0x6f0))(WdfDriverGlobals,local_58,&local_28);
        if ((*(char *)(lVar2 + 0x42) != '\0') &&
           ((*(uint *)(this + 0x94ac) >> (local_18._2_1_ & 0x1f) & 1) != 0)) {
          *(undefined1 *)(lVar2 + 0x42) = 0;
          (**(code **)(WdfFunctions_01025 + 0x2b0))(WdfDriverGlobals,local_58,0);
        }
      }
      (**(code **)(WdfFunctions_01025 + 0x40))(WdfDriverGlobals,uVar3,&local_50);
    }
  }
  return;
}



===== AllocateDmaBuffer @ 14000e160 =====

/* public: static long __cdecl HdaBusInterface::AllocateDmaBuffer(void * __ptr64,void *
   __ptr64,unsigned __int64,struct _MDL * __ptr64 * __ptr64,unsigned __int64 * __ptr64,unsigned char
   * __ptr64,unsigned long * __ptr64) */

long __cdecl
HdaBusInterface::AllocateDmaBuffer
          (void *param_1,void *param_2,__uint64 param_3,_MDL **param_4,__uint64 *param_5,
          uchar *param_6,ulong *param_7)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  long local_res8 [2];
  _MDL **in_stack_ffffffffffffff68;
  void **in_stack_ffffffffffffff80;
  undefined8 local_58;
  HdaController *local_50;
  void *local_48;
  DmaAdapterTracker *local_40;
  
  local_res8[0] = -1;
  local_50 = (HdaController *)0x0;
  local_40 = (DmaAdapterTracker *)0x0;
  local_48 = (void *)0x0;
  local_58 = 0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_50);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar2 = ConvertHandleToLong(param_1,param_2,local_res8);
      this = local_50;
      if (uVar2 == '\0') {
        iVar3 = -0x3ffffff8;
      }
      else {
        in_stack_ffffffffffffff68 =
             (_MDL **)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff68 >> 0x20),0x20);
        iVar3 = IoAcquireRemoveLockEx(local_50 + 8,param_1,"",1);
        if (iVar3 == 0) {
          in_stack_ffffffffffffff80 = &local_48;
          in_stack_ffffffffffffff68 = param_4;
          iVar3 = HdaController::AllocateDmaBuffer
                            (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),local_res8[0],param_3
                             ,param_4,param_5,&local_40,in_stack_ffffffffffffff80,
                             (_LARGE_INTEGER *)&local_58,param_6,param_7);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
        }
        if (-1 < iVar3) {
          StoreAudioBufferInfo
                    (param_1,param_2,*param_4,local_40,local_48,local_58,*param_5,
                     (ulonglong)in_stack_ffffffffffffff80 & 0xffffffff00000000);
          goto LAB_14000e328;
        }
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,4,0x13,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14000e328:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_50);
  return iVar3;
}



===== GetWallClockRegister @ 14000e360 =====

/* public: static void __cdecl HdaBusInterface::GetWallClockRegister(void * __ptr64,unsigned long *
   __ptr64 * __ptr64) */

void __cdecl HdaBusInterface::GetWallClockRegister(void *param_1,ulong **param_2)

{
  longlong lVar1;
  uchar uVar2;
  int iVar3;
  longlong local_res8;
  
  local_res8 = 0;
  if (param_1 != (void *)0x0) {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_res8);
    lVar1 = local_res8;
    if (uVar2 != '\0') {
      iVar3 = IoAcquireRemoveLockEx(local_res8 + 8,param_1,"",1,0x20);
      if (iVar3 == 0) {
        *param_2 = (ulong *)(*(longlong *)(lVar1 + 0x60) + 0x30);
        IoReleaseRemoveLockEx(lVar1 + 8,param_1,0x20);
      }
    }
  }
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_res8);
  return;
}



===== SetCodecInD3 @ 14000e40c =====

/* public: void __cdecl HdaController::SetCodecInD3(unsigned short) __ptr64 */

void __thiscall HdaController::SetCodecInD3(HdaController *this,ushort param_1)

{
  *(ushort *)(this + 0x9604) = param_1;
  return;
}



===== FindCodecResponseTag @ 14000e41c =====

/* private: unsigned char __cdecl HdaController::FindCodecResponseTag(long * __ptr64 const) __ptr64
    */

uchar __thiscall HdaController::FindCodecResponseTag(HdaController *this,long *param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  uVar2 = 0;
  bVar3 = 0;
  bVar4 = 0;
  do {
    LOCK();
    uVar1 = param_1[bVar3 >> 5];
    bVar5 = uVar2 == uVar1;
    if (bVar5) {
      param_1[bVar3 >> 5] = uVar2 | 1 << bVar4;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
    if (bVar5) {
      return bVar3;
    }
    do {
      if ((uVar2 >> bVar4 & 1) == 0) goto LAB_14000e456;
      if (0x3f < bVar3) {
        return 0xff;
      }
      bVar3 = bVar3 + 1;
      bVar4 = bVar3 & 0x1f;
    } while ((bVar3 & 0x1f) != 0);
    uVar2 = 0;
LAB_14000e456:
    if (0x3f < bVar3) {
      return 0xff;
    }
  } while( true );
}



===== TurnSgpcLinkOn @ 14000e46c =====

/* public: void __cdecl HdaController::TurnSgpcLinkOn(void) __ptr64 */

void __thiscall HdaController::TurnSgpcLinkOn(HdaController *this)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if (*(longlong *)(this + 0x96b0) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0xe0,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    *(uint *)(*(longlong *)(this + 0x96b0) + 4) =
         *(uint *)(*(longlong *)(this + 0x96b0) + 4) | 0x10000;
  }
  return;
}



===== CleanupDeviceReferences @ 14000e514 =====

/* public: void __cdecl HdaController::CleanupDeviceReferences(struct WDFDEVICE__ * __ptr64) __ptr64
    */

void __thiscall HdaController::CleanupDeviceReferences(HdaController *this,WDFDEVICE__ *param_1)

{
  CleanupDeviceDmaEngines(this,param_1);
  CleanupDeviceCallbacks(this,param_1);
  return;
}



===== CleanupDeviceCallbacks @ 14000e548 =====

/* public: void __cdecl HdaController::CleanupDeviceCallbacks(struct WDFDEVICE__ * __ptr64) __ptr64
    */

void __thiscall HdaController::CleanupDeviceCallbacks(HdaController *this,WDFDEVICE__ *param_1)

{
  HdaController *pHVar1;
  uint uVar2;
  uint uVar3;
  
  pHVar1 = this + 0x1bf0;
  uVar2 = 0;
  do {
    uVar3 = 0;
    do {
      if (*(WDFDEVICE__ **)pHVar1 == param_1) {
        UnregisterEventCallback(this,(uchar)uVar2,(uchar)uVar3);
      }
      uVar3 = uVar3 + 1;
      pHVar1 = pHVar1 + 0x20;
    } while (uVar3 < 0x40);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xf);
  return;
}



===== CleanupDeviceDmaEngines @ 14000e5bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl HdaController::CleanupDeviceDmaEngines(struct WDFDEVICE__ * __ptr64) __ptr64
    */

void __thiscall HdaController::CleanupDeviceDmaEngines(HdaController *this,WDFDEVICE__ *param_1)

{
  HdaController HVar1;
  undefined8 uVar2;
  long lVar3;
  byte bVar4;
  char cVar5;
  longlong lVar6;
  uint uVar7;
  HdaController *pHVar8;
  void *pvVar9;
  void *pvVar10;
  undefined1 local_138 [32];
  uint *in_stack_fffffffffffffee8;
  undefined4 in_stack_fffffffffffffef0;
  undefined4 in_stack_fffffffffffffef4;
  undefined *in_stack_ffffffffffffff00;
  undefined8 local_d8;
  uint local_c8 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_138;
  memset(local_c8,0,0x78);
  local_d8 = 0;
  uVar7 = 0;
  do {
    pvVar9 = (void *)0x0;
    pHVar8 = this + (ulonglong)uVar7 * 0xd8 + 0x200;
    if ((*(longlong *)(pHVar8 + 0xb0) != 0) &&
       ((param_1 == (WDFDEVICE__ *)0x0 || (*(WDFDEVICE__ **)(pHVar8 + 0xd0) == param_1)))) {
      lVar6 = *(longlong *)(pHVar8 + 0xd0);
      bVar4 = (byte)uVar7;
      if (lVar6 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          in_stack_ffffffffffffff00 = &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids;
          in_stack_fffffffffffffef0 = 0xe;
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffee8,0xe,0x88,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar6,bVar4);
        }
      }
      if ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) != 0) {
        local_c8[0] = uVar7;
        do {
          if (*(int *)(pHVar8 + 0x68) < 1) break;
          in_stack_fffffffffffffee8 = local_c8;
          lVar3 = SetDmaEngineState(this,param_1,*(int *)(pHVar8 + 0x68) - 1,1,
                                    (long *)in_stack_fffffffffffffee8);
        } while (-1 < lVar3);
      }
      KeAcquireSpinLockRaiseToDpc(pHVar8);
      if (param_1 == (WDFDEVICE__ *)0x0) {
        *(undefined4 *)(pHVar8 + 0x68) = 0;
      }
      if ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) != 0) {
        *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
             ~(1 << (bVar4 & 0x1f) & 0x3fffffffU) & *(uint *)(*(longlong *)(this + 0x58) + 0x20);
        LOCK();
        UNLOCK();
        lVar6 = ((ulonglong)(uVar7 & 0xff) + 4) * 0x20;
        *(byte *)(lVar6 + *(longlong *)(this + 0x58)) =
             *(byte *)(lVar6 + *(longlong *)(this + 0x58)) & 0xf7;
        LOCK();
        UNLOCK();
        *(byte *)(lVar6 + *(longlong *)(this + 0x58)) =
             *(byte *)(lVar6 + *(longlong *)(this + 0x58)) & 0xef;
        LOCK();
        UNLOCK();
        *(byte *)(lVar6 + *(longlong *)(this + 0x58)) =
             *(byte *)(lVar6 + *(longlong *)(this + 0x58)) & 0xfb;
        LOCK();
        UNLOCK();
      }
      if (pHVar8[0xe] == (HdaController)0x0) {
        pvVar10 = pvVar9;
      }
      else {
        pvVar10 = *(void **)(pHVar8 + 0x18);
        if (pvVar10 == (void *)0x0) {
          pvVar10 = *(void **)(pHVar8 + 0x70);
        }
        local_d8 = *(undefined8 *)(pHVar8 + 0x50);
        pvVar9 = *(void **)(pHVar8 + 0x48);
        *(undefined8 *)(pHVar8 + 0x18) = 0;
        *(undefined8 *)(pHVar8 + 0x38) = 0;
        *(undefined8 *)(pHVar8 + 0x70) = 0;
        *(undefined8 *)(pHVar8 + 0x90) = 0;
        pHVar8[0x6d] = (HdaController)0x0;
        *(undefined8 *)(pHVar8 + 0x48) = 0;
        *(undefined8 *)(pHVar8 + 0x50) = 0;
        pHVar8[0xe] = (HdaController)0x0;
      }
      uVar2 = *(undefined8 *)(pHVar8 + 0xd0);
      HVar1 = this[(ulonglong)uVar7 * 0xd8 + 0x20c];
      *(undefined8 *)(pHVar8 + 0xd0) = 0;
      KeReleaseSpinLock(pHVar8);
      if (HVar1 != (HdaController)0x0) {
        FreeDmaEngine(this,(WDFDEVICE__ *)0x0,uVar7,(uchar)pHVar8[0x14]);
      }
      if (pvVar9 != (void *)0x0) {
        if (this[0x9606] == (HdaController)0x0) {
          FreeContiguousBuffer(pvVar9,0x1000,0);
        }
        else {
          FreeBufferHal(*(undefined8 *)(this + 0x9650),0x1000,pvVar9,local_d8);
        }
        local_d8 = 0;
      }
      if (pvVar10 != (void *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar5 = '\0';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_qdq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffee8,
                     CONCAT44(in_stack_fffffffffffffef4,in_stack_fffffffffffffef0),0x89,
                     in_stack_ffffffffffffff00,(char)uVar2,bVar4,(char)pvVar10);
        }
      }
      UnregisterNotificationHandlers(this,uVar7);
    }
    uVar7 = uVar7 + 1;
    if (0x1d < uVar7) {
      return;
    }
  } while( true );
}



===== GetResourceInformation @ 14000e930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static void __cdecl HdaBusInterface::GetResourceInformation(void * __ptr64,unsigned char
   * __ptr64,unsigned char * __ptr64) */

void __cdecl HdaBusInterface::GetResourceInformation(void *param_1,uchar *param_2,uchar *param_3)

{
  uchar uVar1;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  if (param_1 != (void *)0x0) {
    uVar1 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_48);
    if (uVar1 != '\0') {
      local_30 = 0;
      uStack_38 = 0;
      local_40 = 0x18;
      (**(code **)(WdfFunctions_01025 + 0x6f0))
                (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),&local_40);
      *param_3 = local_30._3_1_;
      *param_2 = local_30._2_1_;
    }
  }
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_48);
  return;
}



===== TurnSgpcLinkOff @ 14000e9d8 =====

/* public: void __cdecl HdaController::TurnSgpcLinkOff(void) __ptr64 */

void __thiscall HdaController::TurnSgpcLinkOff(HdaController *this)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if (*(longlong *)(this + 0x96b0) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0xe1,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    *(uint *)(*(longlong *)(this + 0x96b0) + 4) =
         *(uint *)(*(longlong *)(this + 0x96b0) + 4) & 0xfffeffff;
  }
  return;
}



===== StopDmaEngines @ 14000ea80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl HdaController::StopDmaEngines(struct WDFDEVICE__ * __ptr64) __ptr64 */

void __thiscall HdaController::StopDmaEngines(HdaController *this,WDFDEVICE__ *param_1)

{
  long lVar1;
  char cVar2;
  HdaController *pHVar3;
  uint uVar4;
  undefined1 auStackY_108 [32];
  uint local_a8 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  memset(local_a8,0,0x78);
  uVar4 = 0;
  pHVar3 = this + 0x2d0;
  do {
    if ((*(longlong *)(pHVar3 + -0x20) != 0) &&
       ((param_1 == (WDFDEVICE__ *)0x0 || (*(WDFDEVICE__ **)pHVar3 == param_1)))) {
      if ((*(longlong *)pHVar3 != 0) && (0 < *(int *)(pHVar3 + -0x68))) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\x01';
        }
        if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_qdd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      local_a8[0] = uVar4;
      do {
        if (*(int *)(pHVar3 + -0x68) < 1) break;
        lVar1 = SetDmaEngineState(this,param_1,*(int *)(pHVar3 + -0x68) - 1,1,(long *)local_a8);
      } while (-1 < lVar1);
    }
    uVar4 = uVar4 + 1;
    pHVar3 = pHVar3 + 0xd8;
    if (0x1d < uVar4) {
      return;
    }
  } while( true );
}



===== ~HdaBusInterface @ 14000ebb4 =====

/* public: __cdecl HdaBusInterface::~HdaBusInterface(void) __ptr64 */

void __thiscall HdaBusInterface::~HdaBusInterface(HdaBusInterface *this)

{
  HdaBusInterface *pHVar1;
  longlong lVar2;
  HdaBusInterface *pHVar3;
  
  pHVar1 = this + 0x130;
  lVar2 = 0x1e;
  pHVar3 = this + 0x120;
  do {
    if (*(longlong *)(pHVar1 + -0x30) != 0) {
      if (*(longlong *)(pHVar1 + -0x28) != 0) {
        HdaController::FreeDetachedAudioBuffer
                  (*(longlong *)(pHVar1 + -0x28),*(undefined8 *)(pHVar1 + -8),
                   *(undefined8 *)(pHVar1 + -0x20),*(undefined8 *)(pHVar1 + -0x18),
                   *(undefined8 *)pHVar3,*(undefined4 *)pHVar1);
      }
      *(undefined8 *)(pHVar1 + -0x30) = 0;
    }
    pHVar3 = pHVar3 + 0x40;
    pHVar1 = pHVar1 + 0x40;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== GetDeviceInformation @ 14000ec30 =====

/* public: static long __cdecl HdaBusInterface::GetDeviceInformation(void * __ptr64,struct
   _HDAUDIO_DEVICE_INFORMATION * __ptr64) */

long __cdecl
HdaBusInterface::GetDeviceInformation(void *param_1,_HDAUDIO_DEVICE_INFORMATION *param_2)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  HdaController *local_res8;
  undefined4 in_stack_ffffffffffffffb8;
  undefined4 in_stack_ffffffffffffffbc;
  
  local_res8 = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_res8);
    this = local_res8;
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      in_stack_ffffffffffffffb8 = 0x20;
      iVar3 = IoAcquireRemoveLockEx(local_res8 + 8,param_1,"",1);
      if (iVar3 == 0) {
        iVar3 = HdaController::GetDeviceInformation(this,param_2);
        IoReleaseRemoveLockEx(this + 8,param_1,0x20);
      }
      if (-1 < iVar3) goto LAB_14000ed41;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),4,0x1a,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14000ed41:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_res8);
  return iVar3;
}



===== GetCodecInD3 @ 14000ed70 =====

/* public: unsigned short __cdecl HdaController::GetCodecInD3(void) __ptr64 */

ushort __thiscall HdaController::GetCodecInD3(HdaController *this)

{
  return *(ushort *)(this + 0x9604);
}



===== WPP_RECORDER_AND_TRACE_SF_s @ 14000ed80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_s
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,char *param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (param_2 != '\0') {
    if (param_9 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_9[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_9;
    if (param_9 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,pcVar3,lVar2,0);
  }
  if (param_3 != '\0') {
    lVar2 = -1;
    if (param_9 == (char *)0x0) {
      lVar1 = 5;
    }
    else {
      do {
        lVar1 = lVar2;
        lVar2 = lVar1 + 1;
      } while (param_9[lVar2] != '\0');
      lVar1 = lVar1 + 2;
    }
    if (param_9 == (char *)0x0) {
      param_9 = "NULL";
    }
    WppAutoLogTrace(param_4,0,1,param_8,param_7,param_9,lVar1,0);
  }
  return;
}



===== InterfaceReference @ 14000ee90 =====

/* public: static void __cdecl HdaBusInterface::InterfaceReference(void * __ptr64) */

void __cdecl HdaBusInterface::InterfaceReference(void *param_1)

{
  LOCK();
  *(int *)param_1 = *(int *)param_1 + 1;
  UNLOCK();
  return;
}



===== HdAudGetDeviceFlags @ 14000ee9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl HdAudGetDeviceFlags(unsigned short,unsigned short,unsigned char,union
   _KSE_HDAUDIO_DEVICE_FLAGS * __ptr64) */

void __cdecl
HdAudGetDeviceFlags(ushort param_1,ushort param_2,uchar param_3,_KSE_HDAUDIO_DEVICE_FLAGS *param_4)

{
  long lVar1;
  undefined1 auStack_b8 [32];
  uint local_98;
  uint local_90;
  ulonglong local_88;
  ulonglong local_80;
  ushort local_78 [40];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  *(undefined8 *)param_4 = 0;
  local_80 = 0;
  local_88 = 0;
  local_90 = (uint)param_3;
  local_98 = (uint)param_2;
  lVar1 = RtlStringCbPrintfW(local_78,0x50,(ushort *)L"HDAUD:PCI\\VEN_%04X&DEV_%04X&REV_%02X",
                             (ulonglong)(uint)param_1);
  if (-1 < lVar1) {
    KseQueryDeviceFlags(local_78,L"HDAUD",&local_80);
    local_98 = (uint)param_2;
    lVar1 = RtlStringCbPrintfW(local_78,0x50,(ushort *)L"HDAUD:PCI\\VEN_%04X&DEV_%04X",
                               (ulonglong)(uint)param_1);
    if (-1 < lVar1) {
      KseQueryDeviceFlags(local_78,L"HDAUD",&local_88);
      *(ulonglong *)param_4 = local_88 | local_80;
    }
  }
  return;
}



===== HdaBusInterface @ 14000ef88 =====

/* public: __cdecl HdaBusInterface::HdaBusInterface(struct _HDAudioDeviceExtension * __ptr64,struct
   WDFDEVICE__ * __ptr64) __ptr64 */

HdaBusInterface * __thiscall
HdaBusInterface::HdaBusInterface
          (HdaBusInterface *this,_HDAudioDeviceExtension *param_1,WDFDEVICE__ *param_2)

{
  *(undefined4 *)this = 0;
  *(WDFDEVICE__ **)(this + 0x880) = param_2;
  *(_HDAudioDeviceExtension **)(this + 0x888) = param_1;
  memset(this + 0x10,0,0xf0);
  *(undefined8 *)(this + 8) = 0;
  memset(this + 0x100,0,0x780);
  return this;
}



===== ReleaseHardwareResources @ 14000efdc =====

/* public: void __cdecl HdaController::ReleaseHardwareResources(void) __ptr64 */

void __thiscall HdaController::ReleaseHardwareResources(HdaController *this)

{
  DmaAdapterTracker *pDVar1;
  DmaAdapterTracker *this_00;
  bool bVar2;
  int iVar3;
  void *pvVar4;
  char cVar5;
  undefined8 uVar6;
  HdaController *pHVar7;
  longlong lVar8;
  undefined4 uVar9;
  undefined4 in_stack_ffffffffffffffbc;
  undefined2 uVar10;
  undefined1 uVar11;
  
  uVar9 = 0x20;
  bVar2 = true;
  iVar3 = IoAcquireRemoveLockEx(this + 8,this,"",1);
  uVar11 = SUB81(this,0);
  if (iVar3 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      bVar2 = false;
    }
    if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_ffffffffffffffbc,uVar9),2,0x2f,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,uVar11,(char)iVar3);
      return;
    }
    return;
  }
  IoReleaseRemoveLockAndWaitEx(this + 8,this,0x20);
  KeCancelTimer(this + 0x128);
  pHVar7 = this + 0x40;
  if (*(int *)pHVar7 != 0) {
    if (*(longlong *)(this + 0x50) != 0) {
      PcRemoveStreamResource();
      *(undefined8 *)(this + 0x50) = 0;
    }
    IoDisconnectInterruptEx(pHVar7);
    *(undefined8 *)pHVar7 = 0;
    *(undefined8 *)(this + 0x48) = 0;
  }
  uVar6 = 0;
  CleanupDeviceDmaEngines(this,(WDFDEVICE__ *)0x0);
  while (pvVar4 = (void *)ExpInterlockedPopEntrySList(this + 0x9660), pvVar4 != (void *)0x0) {
    if (*(HdaLinkInstance **)((longlong)pvVar4 + 0x10) != (HdaLinkInstance *)0x0) {
      HdaLinkInstance::_scalar_deleting_destructor_
                (*(HdaLinkInstance **)((longlong)pvVar4 + 0x10),(uint)uVar6);
      *(undefined8 *)((longlong)pvVar4 + 0x10) = 0;
    }
    operator_delete(pvVar4);
  }
  if (this[0x9606] == (HdaController)0x0) {
    if (*(longlong *)(this + 0x90) != 0) {
      MmUnmapLockedPages(*(longlong *)(this + 0x90),*(undefined8 *)(this + 0x88));
    }
    if (*(_MDL **)(this + 0x88) != (_MDL *)0x0) {
      if ((*(longlong *)(this + 0xa0) == 0) && ((*(uint *)(this + 0x94a0) & 2) != 0)) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          uVar10 = 0x33;
LAB_14000f44b:
          WPP_RECORDER_AND_TRACE_SF_q
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_ffffffffffffffbc,uVar9),1,uVar10,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,uVar11);
        }
      }
      else if ((*(uint *)(this + 0x94a0) & 1) == 0) {
        FreeBuffer(*(_MDL **)(this + 0x88));
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          uVar10 = 0x34;
          goto LAB_14000f44b;
        }
      }
    }
    if (*(longlong *)(this + 0xa8) != 0) {
      MmUnmapLockedPages(*(longlong *)(this + 0xa8),*(undefined8 *)(this + 0xa0));
    }
    if (*(_MDL **)(this + 0xa0) != (_MDL *)0x0) {
      if ((*(uint *)(this + 0x94a0) & 2) == 0) {
        FreeBuffer(*(_MDL **)(this + 0xa0));
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_q
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_ffffffffffffffbc,uVar9),1,0x35,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,uVar11);
        }
      }
    }
    goto LAB_14000f4f5;
  }
  if (*(_MDL **)(this + 0x88) != (_MDL *)0x0) {
    if ((*(longlong *)(this + 0xa0) == 0) && ((*(uint *)(this + 0x94a0) & 2) != 0)) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar5 = '\0';
      }
      if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar10 = 0x30;
LAB_14000f22e:
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffffbc,uVar9),1,uVar10,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,uVar11);
      }
    }
    else if ((*(uint *)(this + 0x94a0) & 1) == 0) {
      FreeBufferMdl(*(_MDL **)(this + 0x88));
      *(undefined8 *)(this + 0x88) = 0;
      if (*(longlong *)(this + 0x90) != 0) {
        FreeBufferHal(*(undefined8 *)(this + 0x9650),0x1000,*(longlong *)(this + 0x90),
                      *(undefined8 *)(this + 0x98));
        *(undefined8 *)(this + 0x90) = 0;
        *(undefined8 *)(this + 0x98) = 0;
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar5 = '\0';
      }
      if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar10 = 0x31;
        goto LAB_14000f22e;
      }
    }
  }
  if (*(_MDL **)(this + 0xa0) != (_MDL *)0x0) {
    if ((*(uint *)(this + 0x94a0) & 2) == 0) {
      FreeBufferMdl(*(_MDL **)(this + 0xa0));
      *(undefined8 *)(this + 0xa0) = 0;
      if (*(longlong *)(this + 0xa8) != 0) {
        FreeBufferHal(*(undefined8 *)(this + 0x9650),0x1000,*(longlong *)(this + 0xa8),
                      *(undefined8 *)(this + 0xb0));
        *(undefined8 *)(this + 0xa8) = 0;
        *(undefined8 *)(this + 0xb0) = 0;
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar5 = '\0';
      }
      if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffffbc,uVar9),1,0x32,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,uVar11);
      }
    }
  }
  if ((*(uint *)(this + 0x94a0) & 3) == 0) {
    this_00 = *(DmaAdapterTracker **)(this + 0x9650);
    LOCK();
    pDVar1 = this_00 + 8;
    iVar3 = *(int *)pDVar1;
    *(int *)pDVar1 = *(int *)pDVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      DmaAdapterTracker::CleanUpDmaAdapter(this_00);
    }
    *(undefined8 *)(this + 0x9650) = 0;
  }
LAB_14000f4f5:
  if (*(longlong *)(this + 0x58) != 0) {
    MmUnmapIoSpace(*(longlong *)(this + 0x58),0x1000);
  }
  if (*(longlong *)(this + 0x60) != 0) {
    MmUnmapIoSpace(*(longlong *)(this + 0x60),*(int *)(this + 0x68) + -0x2000);
  }
  if (*(void **)(this + 0x178) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x178));
    *(undefined8 *)(this + 0x178) = 0;
  }
  pHVar7 = this + 0x180;
  lVar8 = 0xf;
  do {
    if (*(void **)pHVar7 != (void *)0x0) {
      operator_delete(*(void **)pHVar7);
      *(undefined8 *)pHVar7 = 0;
    }
    pHVar7 = pHVar7 + 8;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  return;
}



===== ProcessCodecResponses @ 14000f590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: bool __cdecl HdaController::ProcessCodecResponses(void) __ptr64 */

bool __thiscall HdaController::ProcessCodecResponses(HdaController *this)

{
  uint *puVar1;
  HdaController HVar2;
  HdaController HVar3;
  uint uVar4;
  undefined1 uVar5;
  byte bVar6;
  longlong lVar7;
  _SLIST_ENTRY *p_Var8;
  char cVar9;
  longlong lVar10;
  bool bVar11;
  undefined8 *puVar12;
  char cVar13;
  ulonglong uVar14;
  undefined8 in_stack_ffffffffffffffa8;
  
  bVar11 = false;
  uVar5 = KeAcquireSpinLockRaiseToDpc(this + 0xf0);
  HVar2 = *(HdaController *)(*(longlong *)(this + 0x58) + 0x58);
  HVar3 = this[0xc9];
joined_r0x00014000f5e1:
  if (HVar3 == HVar2) {
    KeReleaseSpinLock(this + 0xf0,uVar5);
    return bVar11;
  }
  lVar7 = *(longlong *)(this + 0xc0);
  uVar14 = (ulonglong)(byte)((char)HVar3 + 1U);
  this[0xc9] = (HdaController)((char)HVar3 + 1U);
  uVar4 = *(uint *)(lVar7 + 4 + uVar14 * 8);
  if ((uVar4 & 0x10) == 0) {
    for (puVar12 = *(undefined8 **)(this + 0x100); puVar12 != (undefined8 *)0x0;
        puVar12 = (undefined8 *)*puVar12) {
      if ((*(HdaController *)((longlong)puVar12 + 0x25) == this[0xca]) &&
         (*(char *)((longlong)puVar12 + 0x24) == '\x01')) {
        *(undefined8 *)(puVar12[5] + 8 + (ulonglong)*(uint *)((longlong)puVar12 + 0x1c) * 0x10) =
             *(undefined8 *)(lVar7 + uVar14 * 8);
        puVar1 = (uint *)(puVar12[5] + 0xc + (ulonglong)*(uint *)((longlong)puVar12 + 0x1c) * 0x10);
        *puVar1 = *puVar1 | 0x80000000;
        uVar14 = _DAT_fffff78000000008;
        *(undefined4 *)(this + (ulonglong)*(uint *)(this + 0x96b8) * 0xc + 0x96bc) =
             *(undefined4 *)(puVar12[5] + (ulonglong)*(uint *)((longlong)puVar12 + 0x1c) * 0x10);
        *(undefined4 *)(this + ((ulonglong)*(uint *)(this + 0x96b8) + 0xc90) * 0xc) =
             *(undefined4 *)(puVar12[5] + 8 + (ulonglong)*(uint *)((longlong)puVar12 + 0x1c) * 0x10)
        ;
        *(int *)(this + (ulonglong)*(uint *)(this + 0x96b8) * 0xc + 0x96c4) = (int)(uVar14 / 10000);
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0 ||
            (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)))) {
          cVar9 = '\0';
        }
        if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
           (cVar13 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
          cVar13 = '\0';
        }
        if ((cVar9 != '\0') || (cVar13 != '\0')) {
          WPP_RECORDER_AND_TRACE_SF_dd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,cVar13,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,0x26,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,
                     (char)*(undefined4 *)
                            (this + (ulonglong)*(uint *)(this + 0x96b8) * 0xc + 0x96bc),
                     (char)*(undefined4 *)
                            (this + (ulonglong)*(uint *)(this + 0x96b8) * 0xc + 0x96c0));
        }
        *(int *)(this + 0x96b8) = *(int *)(this + 0x96b8) + 1;
        if (0x3ff < *(uint *)(this + 0x96b8)) {
          *(undefined4 *)(this + 0x96b8) = 0;
        }
        if (((byte)*(undefined4 *)(*(longlong *)(this + 0xc0) + 4 + (ulonglong)(byte)this[0xc9] * 8)
            & 0xf) != (byte)((uint)*(undefined4 *)
                                    (puVar12[5] +
                                    (ulonglong)*(uint *)((longlong)puVar12 + 0x1c) * 0x10) >> 0x1c))
        {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
             (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          if ((cVar9 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,0x27
                       ,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
          puVar1 = (uint *)(puVar12[5] + 0xc + (ulonglong)*(uint *)((longlong)puVar12 + 0x1c) * 0x10
                           );
          *puVar1 = *puVar1 & 0x7fffffff;
          this[0xc9] = (HdaController)((char)this[0xc9] + -1);
        }
        if (-1 < *(int *)(puVar12[5] + 0xc + (ulonglong)*(uint *)((longlong)puVar12 + 0x1c) * 0x10))
        {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
             (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          if ((cVar9 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,0x28
                       ,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
        }
        *(int *)((longlong)puVar12 + 0x1c) = *(int *)((longlong)puVar12 + 0x1c) + 1;
        this[0xca] = (HdaController)((char)this[0xca] + '\x01');
        *(char *)((longlong)puVar12 + 0x25) = *(char *)((longlong)puVar12 + 0x25) + '\x01';
        if (this[0xca] == this[200]) {
          KeCancelTimer(this + 0x128);
          bVar11 = true;
        }
        if (*(char *)((longlong)puVar12 + 0x25) == *(char *)((longlong)puVar12 + 0x26)) {
          *(undefined2 *)((longlong)puVar12 + 0x24) = 0;
        }
        if ((*(int *)(puVar12 + 3) != *(int *)(puVar12 + 4)) ||
           (*(int *)(puVar12 + 3) != *(int *)((longlong)puVar12 + 0x1c))) goto LAB_14000fa25;
        if ((code *)puVar12[7] == (code *)0x0) {
          KeSetEvent(puVar12[6],0,0);
        }
        else {
          (*(code *)puVar12[7])(puVar12[5],puVar12[8]);
        }
        LOCK();
        *(int *)(this + 0xe8) = *(int *)(this + 0xe8) + -1;
        UNLOCK();
        if (puVar12 != *(undefined8 **)(this + 0x100)) goto LAB_14000fa25;
        goto LAB_14000f99d;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
       (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar9 = '\0';
    }
    if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,0x25,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
  }
  else {
    bVar6 = (byte)uVar4 & 0xf;
    if (bVar6 < 0xf) {
      lVar10 = (ulonglong)(*(uint *)(lVar7 + uVar14 * 8) >> 0x1a) + (ulonglong)bVar6 * 0x40;
      lVar7 = lVar10 * 0x20;
      if (this[lVar7 + 0x1be8] != (HdaController)0x0) {
        LOCK();
        *(int *)(this + 0xe8) = *(int *)(this + 0xe8) + 1;
        UNLOCK();
        (**(code **)(this + lVar7 + 0x1bd8))
                  (*(undefined8 *)(*(longlong *)(this + 0xc0) + (ulonglong)(byte)this[0xc9] * 8),
                   *(undefined8 *)(this + (lVar10 + 0xdf) * 0x20));
        LOCK();
        *(int *)(this + 0xe8) = *(int *)(this + 0xe8) + -1;
        UNLOCK();
      }
    }
  }
  goto LAB_14000fa25;
  while (*(int *)(lVar7 + 0x18) == *(int *)(lVar7 + 0x1c)) {
LAB_14000f99d:
    p_Var8 = FifoQueue::Pop((FifoQueue *)(this + 0x100));
    operator_delete(p_Var8);
    lVar7 = *(longlong *)(this + 0x100);
    if ((lVar7 == 0) || (*(int *)(lVar7 + 0x18) != *(int *)(lVar7 + 0x20))) break;
  }
LAB_14000fa25:
  HVar3 = this[0xc9];
  goto joined_r0x00014000f5e1;
}



===== RtlStringCbPrintfW @ 14000fa78 =====

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



===== HdAudBusChildPrepareHardware @ 14000fb00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HdAudBusChildPrepareHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
HdAudBusChildPrepareHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
  HdaSetChildController(param_1,*(HdaController **)(*(longlong *)(lVar1 + 0x28) + 0x10));
  return 0;
}



===== HdaSetChildController @ 14000fb4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdaSetChildController(struct WDFDEVICE__ * __ptr64,class HdaController * __ptr64) */

void __cdecl HdaSetChildController(WDFDEVICE__ *param_1,HdaController *param_2)

{
  HdaController *this;
  undefined1 uVar1;
  longlong lVar2;
  
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
  if (param_2 != (HdaController *)0x0) {
    LOCK();
    *(int *)param_2 = *(int *)param_2 + 1;
    UNLOCK();
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(lVar2);
  this = *(HdaController **)(lVar2 + 0x30);
  *(HdaController **)(lVar2 + 0x30) = param_2;
  KeReleaseSpinLock(lVar2,uVar1);
  if (this != (HdaController *)0x0) {
    HdaController::Release(this);
  }
  return;
}



===== MapBuffer @ 14000fbdc =====

/* private: void * __ptr64 __cdecl HdaController::MapBuffer(struct _MDL * __ptr64,enum
   _MEMORY_CACHING_TYPE) __ptr64 */

void * __thiscall
HdaController::MapBuffer(HdaController *this,_MDL *param_1,_MEMORY_CACHING_TYPE param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)MmMapLockedPagesSpecifyCache(param_1,0,0,0,0,0x40000010);
  return pvVar1;
}



===== __report_gsfailure @ 14000fc20 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ChangeBandwidth @ 14000fc30 =====

/* public: unsigned char __cdecl LinkBandwidth::ChangeBandwidth(long,long) __ptr64 */

uchar __thiscall LinkBandwidth::ChangeBandwidth(LinkBandwidth *this,long param_1,long param_2)

{
  int iVar1;
  char cVar2;
  long lVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffa8;
  
  cVar4 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar5 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  iVar6 = param_1;
  lVar3 = param_2;
  if ((cVar2 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_dd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xe,10,
               &WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,(char)param_1,(char)param_2);
  }
  while( true ) {
    LOCK();
    iVar1 = *(int *)(this + 0xc);
    bVar7 = iVar6 == iVar1;
    if (bVar7) {
      *(long *)(this + 0xc) = lVar3;
    }
    else {
      iVar6 = iVar1;
    }
    UNLOCK();
    if (bVar7) break;
    lVar3 = (iVar6 - param_1) + param_2;
    if (*(int *)(this + 8) < lVar3) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar4 = '\0';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_D
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xe,0xb,
                   &WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,0);
      }
      return '\0';
    }
  }
  return '\x01';
}



===== WPP_RECORDER_AND_TRACE_SF_DDDDD @ 14000fd90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DDDDD
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11,undefined1 param_12,undefined1 param_13)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,param_7,&param_9,4,
               &param_10,4,&param_11,4,&param_12,4,&param_13,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,0xe,&WPP_cf21945f0bb533f993d6b0823bddd6df_Traceguids,param_7,&param_9,
                    4,&param_10,4,&param_11,4,&param_12,4,&param_13,4,0);
  }
  return;
}



===== `scalar_deleting_destructor' @ 14000fec4 =====

/* public: void * __ptr64 __cdecl HdaBusInterface::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall HdaBusInterface::_scalar_deleting_destructor_(HdaBusInterface *this,uint param_1)

{
  ~HdaBusInterface(this);
  operator_delete(this);
  return this;
}



===== `scalar_deleting_destructor' @ 14000feec =====

/* public: void * __ptr64 __cdecl HdaController::`scalar deleting destructor'(unsigned int) __ptr64
    */

void * __thiscall HdaController::_scalar_deleting_destructor_(HdaController *this,uint param_1)

{
  ~HdaController(this);
  operator_delete(this);
  return this;
}



===== HdAudBusGraphicsHandlePostF0Notification @ 14000ff14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusGraphicsHandlePostF0Notification(struct WDFDEVICE__ * __ptr64) */

void __cdecl HdAudBusGraphicsHandlePostF0Notification(WDFDEVICE__ *param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffc8;
  
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
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x82,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  *(undefined1 *)(lVar1 + 0x1e6) = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x83,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)*(undefined4 *)(lVar1 + 0x1e0)
              );
  }
  if (*(int *)(lVar1 + 0x1dc) != 2) {
    *(undefined4 *)(lVar1 + 0x1dc) = 2;
    if (*(HdaController **)(lVar1 + 0x10) != (HdaController *)0x0) {
      HdaController::TurnSgpcLinkOn(*(HdaController **)(lVar1 + 0x10));
    }
    (**(code **)(WdfFunctions_01025 + 0x9f8))
              (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x68),0xffffffffffb3b4c0);
  }
  return;
}



===== HdAudBusGraphicsHandlePostFxNotification @ 14001008c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusGraphicsHandlePostFxNotification(struct WDFDEVICE__ * __ptr64) */

void __cdecl HdAudBusGraphicsHandlePostFxNotification(WDFDEVICE__ *param_1)

{
  char cVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x85,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  *(undefined1 *)(lVar2 + 0x1e6) = 1;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x86,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)*(undefined4 *)(lVar2 + 0x1e0)
              );
  }
  if (*(int *)(lVar2 + 0x1dc) != 4) {
    *(undefined4 *)(lVar2 + 0x1dc) = 4;
    if (*(HdaController **)(lVar2 + 0x10) != (HdaController *)0x0) {
      HdaController::TurnSgpcLinkOff(*(HdaController **)(lVar2 + 0x10));
    }
    cVar1 = (**(code **)(WdfFunctions_01025 + 0xa00))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x68),0);
    if (cVar1 != '\0') {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar1 = '\0';
      }
      else {
        cVar1 = '\x01';
      }
      if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x87,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,
                   (char)*(undefined8 *)(lVar2 + 0x68));
      }
    }
    (**(code **)(WdfFunctions_01025 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x70));
  }
  return;
}



===== HdAudBusGraphicsHandlePreF0Notification @ 140010284 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusGraphicsHandlePreF0Notification(struct WDFDEVICE__ * __ptr64) */

void __cdecl HdAudBusGraphicsHandlePreF0Notification(WDFDEVICE__ *param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffc8;
  
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
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x81,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  if (*(int *)(lVar1 + 0x1dc) == 3) {
    HdAudBusGraphicsHandlePostF0Notification(param_1);
  }
  else {
    *(undefined4 *)(lVar1 + 0x1dc) = 1;
  }
  return;
}



===== HdAudBusGraphicsHandlePreFxNotification @ 14001034c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusGraphicsHandlePreFxNotification(struct WDFDEVICE__ * __ptr64) */

void __cdecl HdAudBusGraphicsHandlePreFxNotification(WDFDEVICE__ *param_1)

{
  char cVar1;
  longlong lVar2;
  undefined8 local_res10 [3];
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x84,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  *(undefined4 *)(lVar2 + 0x1dc) = 3;
  *(undefined1 *)(lVar2 + 0x1e6) = 1;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    local_res10[0] = 0xfffffffffffe7960;
    KeDelayExecutionThread(0,0,local_res10);
  }
  return;
}



===== HdAudBusGraphicsPowerFStateNotificationCallback @ 140010440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusGraphicsPowerFStateNotificationCallback(void * __ptr64,unsigned
   long,unsigned int,unsigned char,void * __ptr64) */

void __cdecl
HdAudBusGraphicsPowerFStateNotificationCallback
          (void *param_1,ulong param_2,uint param_3,uchar param_4,void *param_5)

{
  longlong lVar1;
  char cVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qddd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_5,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  if (*(ulong *)(lVar1 + 0x1d8) == param_2) {
    if (param_3 == 0) {
      if (param_4 == '\0') {
        HdAudBusGraphicsHandlePostF0Notification(param_5);
      }
      else {
        HdAudBusGraphicsHandlePreF0Notification(param_5);
      }
    }
    else if (param_3 == 1) {
      if (param_4 == '\0') {
        HdAudBusGraphicsHandlePostFxNotification(param_5);
      }
      else {
        HdAudBusGraphicsHandlePreFxNotification(param_5);
      }
    }
  }
  return;
}



===== HdAudBusGraphicsPowerInitialComponentStateCallback @ 140010540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusGraphicsPowerInitialComponentStateCallback(void * __ptr64,void *
   __ptr64,unsigned long,unsigned char,unsigned int,struct _GUID,unsigned int) */

void __cdecl
HdAudBusGraphicsPowerInitialComponentStateCallback
          (undefined8 param_1,WDFDEVICE__ *param_2,undefined4 param_3,undefined8 param_4,int param_5
          ,undefined8 param_6,undefined4 param_7)

{
  longlong lVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffb8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_dd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,1,0x8b,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_3,(char)param_5);
  }
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  if (((short)((uint)param_7 >> 0x10) == 0) && ((short)param_7 == 0)) {
    *(undefined4 *)(lVar1 + 0x1d8) = param_3;
    *(undefined4 *)(lVar1 + 0x1d4) = 0;
    *(undefined1 *)(lVar1 + 0x1d0) = 1;
    if (param_5 == 0) {
      HdAudBusGraphicsHandlePostF0Notification(param_2);
    }
    else {
      HdAudBusGraphicsHandlePostFxNotification(param_2);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
        (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)))) {
      cVar2 = '\0';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,1,0x8c,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
  }
  return;
}



===== HdAudBusGraphicsPowerInterfaceCallback @ 1400106c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl HdAudBusGraphicsPowerInterfaceCallback(void * __ptr64,void * __ptr64) */

long __cdecl HdAudBusGraphicsPowerInterfaceCallback(void *param_1,void *param_2)

{
  longlong *plVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  _DEVICE_OBJECT *p_Var6;
  longlong lVar7;
  char cVar8;
  _GUID *p_Var9;
  _GUID *in_R9;
  undefined **ppuVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStackY_1b8 [32];
  undefined8 ***in_stack_fffffffffffffe68;
  undefined2 uVar14;
  int local_168 [2];
  longlong local_160;
  undefined8 local_158;
  undefined8 local_150;
  _tlgProvider_t *local_148;
  undefined8 local_140;
  undefined8 **local_138;
  undefined8 ***local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  longlong local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_88;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_160 = 0;
  memset(&local_d8,0,0x88);
  local_158 = 0;
  local_130 = (undefined8 ***)0x0;
  local_138 = (undefined8 **)0x0;
  local_e8 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_48 = 0;
  uStack_40 = 0;
  bVar13 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_R9 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,in_R9,
               in_stack_fffffffffffffe68,0xd,0x71,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,
               (char)param_2);
  }
  uVar11 = 0x1000;
  ppuVar10 = &WPP_GLOBAL_Control;
  if ((param_2 == (void *)0x0) || (param_1 == (void *)0x0)) {
    iVar3 = -0x3ffffff3;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0 ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
      bVar13 = false;
    }
    bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar13 == false) && (!bVar12)) goto LAB_140011065;
    uVar14 = 0x72;
  }
  else {
    uVar4 = RtlUnicodeStringValidateWorker(*(ushort **)((longlong)param_1 + 0x28));
    if (-1 < (int)uVar4) {
      lVar5 = (**(code **)(WdfFunctions_01025 + 0x650))
                        (WdfDriverGlobals,param_2,
                         PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
      p_Var9 = (_GUID *)(*(longlong *)((longlong)param_1 + 4) + -0x11d046f0cb3a4004);
      if (p_Var9 == (_GUID *)0x0) {
        p_Var9 = (_GUID *)(*(longlong *)((longlong)param_1 + 0xc) + -0x3f05139760008fb0);
      }
      if (p_Var9 == (_GUID *)0x0) {
        plVar1 = (longlong *)(lVar5 + 0x1a8);
        if (*plVar1 != 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
            bVar13 = false;
          }
          bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          p_Var9 = (_GUID *)CONCAT71(0x14001d0,bVar12);
          if ((bVar13) || (bVar12)) {
            in_R9 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
            WPP_RECORDER_AND_TRACE_SF_q
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar13,bVar12,in_R9,
                       in_stack_fffffffffffffe68,0xd,0x74,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,
                       (char)*(undefined8 *)(lVar5 + 0x1c8));
          }
          goto LAB_140010eae;
        }
        in_R9 = (_GUID *)&local_160;
        iVar3 = (**(code **)(WdfFunctions_01025 + 0x538))(WdfDriverGlobals,param_2,0);
        if (iVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            bVar13 = false;
          }
          p_Var9 = (_GUID *)CONCAT71(0x14001d0,
                                     (undefined **)WPP_RECORDER_INITIALIZED !=
                                     &WPP_RECORDER_INITIALIZED);
          if ((bVar13 != false) ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
            in_R9 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
            uVar14 = 0x75;
LAB_140010993:
            WPP_RECORDER_AND_TRACE_SF_d
                      (uVar4,bVar13,(char)p_Var9,in_R9,in_stack_fffffffffffffe68,0xd,uVar14,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar3);
          }
        }
        else {
          puVar2 = *(undefined4 **)((longlong)param_1 + 0x28);
          local_d8 = 0x88;
          local_d4 = 2;
          local_a8 = *puVar2;
          uStack_a4 = puVar2[1];
          uStack_a0 = puVar2[2];
          uStack_9c = puVar2[3];
          local_98 = 0x1f0000;
          local_88 = 0x40;
          iVar3 = (**(code **)(WdfFunctions_01025 + 0x540))(WdfDriverGlobals,local_160,&local_d8);
          if (iVar3 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar13 = false;
            }
            p_Var9 = (_GUID *)CONCAT71(0x14001d0,
                                       (undefined **)WPP_RECORDER_INITIALIZED !=
                                       &WPP_RECORDER_INITIALIZED);
            if ((bVar13 != false) ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar14 = 0x76;
LAB_140010a60:
              in_R9 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
              uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              goto LAB_140010993;
            }
          }
          else {
            in_R9 = (_GUID *)&local_158;
            local_118 = CONCAT44(local_118._4_4_,0x38);
            uStack_100 = 0x100000001;
            local_f8 = local_160;
            iVar3 = (**(code **)(WdfFunctions_01025 + 0x7b8))(WdfDriverGlobals,&local_118);
            if (iVar3 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                bVar13 = false;
              }
              p_Var9 = (_GUID *)CONCAT71(0x14001d0,
                                         (undefined **)WPP_RECORDER_INITIALIZED !=
                                         &WPP_RECORDER_INITIALIZED);
              if ((bVar13 != false) ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                uVar14 = 0x77;
                goto LAB_140010a60;
              }
            }
            else {
              in_stack_fffffffffffffe68 = &local_130;
              in_R9 = (_GUID *)0x30;
              iVar3 = (**(code **)(WdfFunctions_01025 + 0x608))
                                (WdfDriverGlobals,&local_118,lVar5 + 0x178);
              if (iVar3 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  bVar13 = false;
                }
                p_Var9 = (_GUID *)CONCAT71(0x14001d0,
                                           (undefined **)WPP_RECORDER_INITIALIZED !=
                                           &WPP_RECORDER_INITIALIZED);
                if ((bVar13 != false) ||
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  uVar14 = 0x78;
                  goto LAB_140010a60;
                }
              }
              else {
                in_stack_fffffffffffffe68 = &local_138;
                in_R9 = (_GUID *)0x20;
                iVar3 = (**(code **)(WdfFunctions_01025 + 0x608))
                                  (WdfDriverGlobals,&local_118,plVar1);
                if (iVar3 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    bVar13 = false;
                  }
                  p_Var9 = (_GUID *)CONCAT71(0x14001d0,
                                             (undefined **)WPP_RECORDER_INITIALIZED !=
                                             &WPP_RECORDER_INITIALIZED);
                  if ((bVar13 != false) ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    uVar14 = 0x79;
                    goto LAB_140010a60;
                  }
                }
                else {
                  in_R9 = (_GUID *)0x232807;
                  in_stack_fffffffffffffe68 = local_130;
                  iVar3 = (**(code **)(WdfFunctions_01025 + 0x5e8))
                                    (WdfDriverGlobals,local_160,local_158);
                  if (iVar3 < 0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                      bVar13 = false;
                    }
                    p_Var9 = (_GUID *)CONCAT71(0x14001d0,
                                               (undefined **)WPP_RECORDER_INITIALIZED !=
                                               &WPP_RECORDER_INITIALIZED);
                    if ((bVar13 != false) ||
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      uVar14 = 0x7a;
                      goto LAB_140010a60;
                    }
                  }
                  else {
                    in_R9 = (_GUID *)&local_48;
                    local_48 = 0x300000010;
                    uStack_40 = 0xfffffffffd050f80;
                    (**(code **)(WdfFunctions_01025 + 0x7e8))(WdfDriverGlobals,local_158,local_160);
                    iVar3 = (**(code **)(WdfFunctions_01025 + 0x7f0))(WdfDriverGlobals,local_158);
                    if (-1 < iVar3) {
                      p_Var9 = (_GUID *)&local_128;
                      local_128 = 0xffffffffff676980;
                      iVar3 = (**(code **)(WdfFunctions_01025 + 0x9c8))(WdfDriverGlobals);
                      if (iVar3 == 0) {
                        if ((*plVar1 != 0) &&
                           (p_Var6 = (_DEVICE_OBJECT *)
                                     (**(code **)(WdfFunctions_01025 + 0x598))
                                               (WdfDriverGlobals,local_160),
                           p_Var6 != (_DEVICE_OBJECT *)0x0)) {
                          AddS0PowerRelation(param_2,p_Var6);
                        }
                        (**(code **)(WdfFunctions_01025 + 0x9d0))
                                  (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x168));
                      }
                      else {
                        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                          cVar8 = '\0';
                        }
                        else {
                          cVar8 = '\x01';
                        }
                        bVar13 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED
                        ;
                        p_Var9 = (_GUID *)CONCAT71(0x14001d0,bVar13);
                        if ((cVar8 != '\0') || (bVar13)) {
                          in_R9 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
                          WPP_RECORDER_AND_TRACE_SF_d
                                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,bVar13,in_R9,
                                     in_stack_fffffffffffffe68,1,0x7c,
                                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar3);
                        }
                      }
                      goto LAB_140010eae;
                    }
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                      bVar13 = false;
                    }
                    p_Var9 = (_GUID *)CONCAT71(0x14001d0,
                                               (undefined **)WPP_RECORDER_INITIALIZED !=
                                               &WPP_RECORDER_INITIALIZED);
                    if ((bVar13 != false) ||
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      uVar14 = 0x7b;
                      goto LAB_140010a60;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
LAB_140010eae:
        iVar3 = 0;
      }
      if (lVar5 != 0) {
        lVar7 = *(longlong *)((longlong)param_1 + 4) + -0x11d046f0cb3a4004;
        if (lVar7 == 0) {
          lVar7 = *(longlong *)((longlong)param_1 + 0xc) + -0x3f05139760008fb0;
        }
        if (lVar7 == 0) {
          if ((4 < DAT_14001d0d8) && (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
            local_168[0] = *(int *)(lVar5 + 0x1b0);
            local_140 = *(undefined8 *)((longlong)param_1 + 0x28);
            local_150 = CONCAT44(local_150._4_4_,iVar3);
            local_120 = 0x800;
            local_148 = (_tlgProvider_t *)L"Unknown";
            if (*(_tlgProvider_t **)(lVar5 + 0x1e8) != (_tlgProvider_t *)0x0) {
              local_148 = *(_tlgProvider_t **)(lVar5 + 0x1e8);
            }
            _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
            ::
            Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>,_tlgWrapperByVal<4>_>
                      (local_148,&DAT_14001b369,p_Var9,in_R9,(_tlgWrapperByVal<8> *)&local_120,
                       (_tlgWrapSz<unsigned_short> *)&local_148,(_tlgWrapperByVal<4> *)&local_150,
                       (_tlgWrapBuffer<_UNICODE_STRING> *)&local_140,
                       (_tlgWrapperByVal<4> *)local_168);
          }
        }
        else {
          lVar7 = *(longlong *)((longlong)param_1 + 4) + -0x11d046f0cb3a4005;
          if (lVar7 == 0) {
            lVar7 = *(longlong *)((longlong)param_1 + 0xc) + -0x3f05139760008fb0;
          }
          if (((lVar7 == 0) && (4 < DAT_14001d0d8)) &&
             (uVar4 = _tlgKeywordOn(), (char)uVar4 != '\0')) {
            local_150 = *(undefined8 *)((longlong)param_1 + 0x28);
            local_140 = 0x800;
            local_148 = (_tlgProvider_t *)L"Unknown";
            if (*(_tlgProvider_t **)(lVar5 + 0x1e8) != (_tlgProvider_t *)0x0) {
              local_148 = *(_tlgProvider_t **)(lVar5 + 0x1e8);
            }
            local_168[0] = iVar3;
            _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
            ::
            Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapBuffer<_UNICODE_STRING>_>
                      (local_148,&DAT_14001b3f3,p_Var9,in_R9,(_tlgWrapperByVal<8> *)&local_140,
                       (_tlgWrapSz<unsigned_short> *)&local_148,(_tlgWrapperByVal<4> *)local_168,
                       (_tlgWrapBuffer<_UNICODE_STRING> *)&local_150);
          }
        }
      }
      goto LAB_140011065;
    }
    iVar3 = -0x3ffffff3;
    if ((((undefined **)WPP_GLOBAL_Control == ppuVar10) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & uVar11) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      bVar13 = false;
    }
    bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar13 == false) && (!bVar12)) goto LAB_140011065;
    uVar14 = 0x73;
  }
  iVar3 = -0x3ffffff3;
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar13,bVar12,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffe68,0xd,uVar14,
             &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0xd);
LAB_140011065:
  if (local_160 != 0) {
    (**(code **)(WdfFunctions_01025 + 0x680))(WdfDriverGlobals);
  }
  return iVar3;
}



===== HdAudBusGraphicsRemovalNotificationCallback @ 1400110c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusGraphicsRemovalNotificationCallback(void * __ptr64,void * __ptr64) */

void __cdecl HdAudBusGraphicsRemovalNotificationCallback(void *param_1,void *param_2)

{
  int iVar1;
  _HDAudioDeviceExtension *p_Var2;
  char cVar3;
  undefined8 local_res10;
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x88,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_2);
  }
  p_Var2 = (_HDAudioDeviceExtension *)
           (**(code **)(WdfFunctions_01025 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  local_res10 = 0xffffffffff676980;
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x9c8))
                    (WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x168),&local_res10);
  if (iVar1 == 0) {
    *(undefined4 *)(p_Var2 + 0x1dc) = 0;
    p_Var2[0x1e6] = (_HDAudioDeviceExtension)0x1;
    (**(code **)(WdfFunctions_01025 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x70));
    HdAudBusSharedResourceCleanup(p_Var2);
    (**(code **)(WdfFunctions_01025 + 0x9d0))(WdfDriverGlobals);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x8a,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x89,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar1);
    }
  }
  return;
}



===== HdAudBusProfileChangeCallback @ 1400112d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HdAudBusProfileChangeCallback(void * __ptr64,void * __ptr64) */

long __cdecl HdAudBusProfileChangeCallback(void *param_1,void *param_2)

{
  longlong lVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffc8;
  
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
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x70,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_2);
  }
  lVar1 = *(longlong *)((longlong)param_1 + 4) + -0x11d046f0cb3a4003;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)((longlong)param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if ((lVar1 == 0) && (param_2 != (void *)0x0)) {
    lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098)
    ;
    if (lVar1 != 0) {
      (**(code **)(WdfFunctions_01025 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x70));
    }
  }
  return 0;
}



===== HdAudBusSharedResourceCleanup @ 1400113d0 =====

/* void __cdecl HdAudBusSharedResourceCleanup(struct _HDAudioDeviceExtension * __ptr64) */

void __cdecl HdAudBusSharedResourceCleanup(_HDAudioDeviceExtension *param_1)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0x8d,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
  }
  *(undefined8 *)(param_1 + 0x1a8) = 0;
  *(undefined8 *)(param_1 + 0x1b8) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  param_1[0x1d0] = (_HDAudioDeviceExtension)0x0;
  *(undefined4 *)(param_1 + 0x1b0) = 4;
  RemoveS0PowerRelation(*(WDFDEVICE__ **)(param_1 + 8));
  return;
}



===== TimerRoutineHandleSgpcHdAudBus @ 140011490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TimerRoutineHandleSgpcHdAudBus(struct WDFTIMER__ * __ptr64) */

void __cdecl TimerRoutineHandleSgpcHdAudBus(WDFTIMER__ *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x7f,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01025 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_BUS_SGPC_TIMER_CONTEXT_TYPE_INFO_14001d0c8);
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  (**(code **)(WdfFunctions_01025 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x70));
  return;
}



===== WorkItemRoutineEnumerateHdAudBus @ 140011580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl WorkItemRoutineEnumerateHdAudBus(struct WDFWORKITEM__ * __ptr64) */

void __cdecl WorkItemRoutineEnumerateHdAudBus(WDFWORKITEM__ *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  WDFCHILDLIST__ *pWVar6;
  char cVar7;
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x80,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01025 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_BUS_ENUMERATE_WORK_ITEM_CONTEXT_TYPE_INFO_14001d048);
  uVar2 = *puVar4;
  lVar5 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  LOCK();
  piVar1 = (int *)(lVar5 + 0x78);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar3 + 1 < 2) {
    do {
      LOCK();
      *(undefined4 *)(lVar5 + 0x78) = 1;
      UNLOCK();
      iVar3 = (**(code **)(WdfFunctions_01025 + 0xdb0))
                        (WdfDriverGlobals,uVar2,1,0,0x1000,
                         "onecoreuap\\drivers\\wdm\\audio\\backpln\\adapters\\hdaudio\\hdaudbus\\busdrv.cpp"
                        );
      if (-1 < iVar3) {
        (**(code **)(WdfFunctions_01025 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x80),0);
        if (*(char *)(lVar5 + 0x7d) == '\0') {
          *(undefined1 *)(lVar5 + 0x7c) = 1;
          KeClearEvent(lVar5 + 0x88);
        }
        (**(code **)(WdfFunctions_01025 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x80));
        if (*(char *)(lVar5 + 0x7c) != '\0') {
          pWVar6 = (WDFCHILDLIST__ *)
                   (**(code **)(WdfFunctions_01025 + 0x420))(WdfDriverGlobals,uVar2);
          HdAudBusEnumerateBus(pWVar6);
          (**(code **)(WdfFunctions_01025 + 0x9c8))
                    (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x80),0);
          *(undefined1 *)(lVar5 + 0x7c) = 0;
          KeSetEvent(lVar5 + 0x88,0,0);
          (**(code **)(WdfFunctions_01025 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x80));
        }
        (**(code **)(WdfFunctions_01025 + 0xdb8))
                  (WdfDriverGlobals,uVar2,0,0x101e,
                   "onecoreuap\\drivers\\wdm\\audio\\backpln\\adapters\\hdaudio\\hdaudbus\\busdrv.cpp"
                  );
      }
      LOCK();
      piVar1 = (int *)(lVar5 + 0x78);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    } while (1 < iVar3);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_DDD @ 1400117f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DDD(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0x1e,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,4,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0x1e,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_Dd @ 1400118dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_Dd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,param_7,&param_9,4,
               &param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,1,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,param_7,&param_9,4,
                    &param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qddd @ 1400119ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qddd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0x7e,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,1,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0x7e,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qddds @ 140011abc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qddds
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  char *in_stack_00000068;
  
  if (param_2 != '\0') {
    if (in_stack_00000068 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000068[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000068;
    if (in_stack_00000068 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0xb7,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,pcVar1,lVar3,0);
  }
  if (param_3 != '\0') {
    lVar3 = -1;
    if (in_stack_00000068 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      do {
        lVar2 = lVar3;
        lVar3 = lVar2 + 1;
      } while (in_stack_00000068[lVar3] != '\0');
      lVar2 = lVar2 + 2;
    }
    if (in_stack_00000068 == (char *)0x0) {
      in_stack_00000068 = "NULL";
    }
    WppAutoLogTrace(param_4,0,2,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,0xb7,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,in_stack_00000068,lVar2,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qq @ 140011c80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,param_6,param_8,param_7,&param_9,8,&param_10,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqd @ 140011d54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,param_7,&param_9,8,
               &param_10,8,&param_11,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,2,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,param_7,&param_9,8,
                    &param_10,8,&param_11,4,0);
  }
  return;
}



===== WppClassicProviderCallback @ 140011e50 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140011eac =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14001cf07 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140011ed4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140012020 =====

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



===== `scalar_deleting_destructor' @ 1400120a4 =====

/* public: void * __ptr64 __cdecl HdaLinkInstance::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall HdaLinkInstance::_scalar_deleting_destructor_(HdaLinkInstance *this,uint param_1)

{
  ~HdaLinkInstance(this);
  operator_delete(this);
  return this;
}



===== AllocateBuffer @ 1400120cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl DmaAdapterTracker::AllocateBuffer(unsigned long,enum
   _MEMORY_CACHING_TYPE,union _LARGE_INTEGER * __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
DmaAdapterTracker::AllocateBuffer
          (DmaAdapterTracker *this,ulong param_1,_MEMORY_CACHING_TYPE param_2,
          _LARGE_INTEGER *param_3,void **param_4)

{
  int iVar1;
  _MEMORY_CACHING_TYPE local_res18 [4];
  
  local_res18[0] = param_2;
  iVar1 = (**(code **)(*(longlong *)(*(longlong *)this + 8) + 0xe8))
                    (*(longlong *)this,0,0,param_1,0,local_res18,0x80000000,param_3,param_4);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(this + 8) = *(int *)(this + 8) + 1;
    UNLOCK();
  }
  return iVar1;
}



===== AllocateBufferHal @ 140012130 =====

/* private: void * __ptr64 __cdecl HdaController::AllocateBufferHal(unsigned __int64,union
   _LARGE_INTEGER * __ptr64,unsigned char) __ptr64 */

void * __thiscall
HdaController::AllocateBufferHal
          (HdaController *this,__uint64 param_1,_LARGE_INTEGER *param_2,uchar param_3)

{
  char cVar1;
  uint uVar2;
  void *local_res10 [3];
  undefined8 in_stack_ffffffffffffffb8;
  
  if ((param_1 < 0x100000000) && ((uint)param_1 < 0xfffff000)) {
    local_res10[0] = (void *)0x0;
    uVar2 = (uint)param_1 + 0xfff & 0xfffff000;
    DmaAdapterTracker::AllocateBuffer
              (*(DmaAdapterTracker **)(this + 0x9650),uVar2,0,param_2,local_res10);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qid
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    memset(local_res10[0],0,(ulonglong)uVar2);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0 ||
        ((byte)WPP_GLOBAL_Control[0x29] < 3)))) {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,0xe,0x16,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    local_res10[0] = (void *)0x0;
  }
  return local_res10[0];
}



===== AllocateBufferMdl @ 140012288 =====

/* private: struct _MDL * __ptr64 __cdecl HdaController::AllocateBufferMdl(void * __ptr64,unsigned
   __int64) __ptr64 */

_MDL * __thiscall
HdaController::AllocateBufferMdl(HdaController *this,void *param_1,__uint64 param_2)

{
  _MDL *p_Var1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((param_2 < 0x100000000) && ((uint)param_2 < 0xfffff000)) {
    p_Var1 = (_MDL *)IoAllocateMdl(param_1,(uint)param_2 + 0xfff & 0xfffff000,0,0,0);
    if (p_Var1 != (_MDL *)0x0) {
      MmBuildMdlForNonPagedPool(p_Var1);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,0xe,0x21,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    p_Var1 = (_MDL *)0x0;
  }
  return p_Var1;
}



===== AllocateContiguousDmaBuffer @ 140012364 =====

/* public: long __cdecl HdaController::AllocateContiguousDmaBuffer(long,unsigned __int64,void *
   __ptr64 * __ptr64,struct _HDAUDIO_BUFFER_DESCRIPTOR * __ptr64 * __ptr64) __ptr64 */

long __thiscall
HdaController::AllocateContiguousDmaBuffer
          (HdaController *this,long param_1,__uint64 param_2,void **param_3,
          _HDAUDIO_BUFFER_DESCRIPTOR **param_4)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  void *pvVar4;
  _HDAUDIO_BUFFER_DESCRIPTOR *p_Var5;
  long lVar6;
  longlong lVar7;
  undefined8 in_stack_ffffffffffffff68;
  undefined2 uVar8;
  _HDAUDIO_BUFFER_DESCRIPTOR *local_58;
  void *local_50;
  
  cVar2 = KeGetCurrentIrql();
  if (cVar2 != '\0') {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,0xe,0x8e,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar6 = -0x3fffffff;
    goto LAB_14001291b;
  }
  if (((param_2 == 0) || (param_3 == (void **)0x0)) ||
     (param_4 == (_HDAUDIO_BUFFER_DESCRIPTOR **)0x0)) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar8 = 0x8f;
LAB_140012901:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,0xe,uVar8,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
  }
  else {
    if (0x1d < (uint)param_1) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar2 = '\0';
      }
      else {
        cVar2 = '\x01';
      }
      if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,0xe,0x90,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      lVar6 = -0x3ffffff8;
      goto LAB_14001291b;
    }
    if (param_2 < 0x100001) {
      pvVar4 = AllocateContiguousBuffer(this,param_2,2);
      if (pvVar4 == (void *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\x01';
        }
        if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,0xe,0x92,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
      }
      else {
        p_Var5 = AllocateContiguousBuffer(this,0x1000,0);
        if (p_Var5 != (_HDAUDIO_BUFFER_DESCRIPTOR *)0x0) {
          lVar7 = (longlong)param_1 * 0xd8;
          uVar3 = KeAcquireSpinLockRaiseToDpc(this + lVar7 + 0x200);
          local_58 = p_Var5;
          local_50 = pvVar4;
          if (this[lVar7 + 0x20c] == (HdaController)0x0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar2 = '\0';
            }
            else {
              cVar2 = '\x01';
            }
            if ((cVar2 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,0xe,
                         0x94,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
            }
            lVar6 = -0x3ffffff8;
          }
          else {
            if (*(int *)(this + lVar7 + 0x268) == 0) {
              if (this[lVar7 + 0x20e] == (HdaController)0x0) {
                local_50 = (void *)0x0;
                local_58 = (_HDAUDIO_BUFFER_DESCRIPTOR *)0x0;
                *(__uint64 *)(this + lVar7 + 0x290) = param_2;
                this[lVar7 + 0x20e] = (HdaController)0x1;
                *(undefined2 *)(this + lVar7 + 0x26c) = 1;
                *(void **)(this + lVar7 + 0x270) = pvVar4;
                *(_HDAUDIO_BUFFER_DESCRIPTOR **)(this + lVar7 + 0x248) = p_Var5;
                *(undefined4 *)(this + lVar7 + 0x240) = 2;
                lVar6 = 0;
                *param_3 = pvVar4;
                *param_4 = p_Var5;
                goto LAB_1400127d4;
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
                bVar1 = false;
              }
              else {
                bVar1 = true;
              }
              if ((bVar1 != false) ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                uVar8 = 0x96;
                goto LAB_1400126fa;
              }
            }
            else {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
                bVar1 = false;
              }
              else {
                bVar1 = true;
              }
              if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
              {
                uVar8 = 0x95;
LAB_1400126fa:
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,0xe,
                           uVar8,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
              }
            }
            lVar6 = -0x3ffffff0;
          }
LAB_1400127d4:
          KeReleaseSpinLock(this + lVar7 + 0x200,uVar3);
          if (local_50 != (void *)0x0) {
            FreeContiguousBuffer(pvVar4,param_2,2);
          }
          if (local_58 != (_HDAUDIO_BUFFER_DESCRIPTOR *)0x0) {
            FreeContiguousBuffer(local_58,0x1000,0);
          }
          if (-1 < lVar6) {
            return lVar6;
          }
          goto LAB_14001291b;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\x01';
        }
        if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,0xe,0x93,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        FreeContiguousBuffer(pvVar4,param_2,2);
      }
      lVar6 = -0x3fffff66;
      goto LAB_14001291b;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar8 = 0x91;
      goto LAB_140012901;
    }
  }
  lVar6 = -0x3ffffff3;
LAB_14001291b:
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,0xe,0x97,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar6);
  }
  return lVar6;
}



===== AllocateDmaBuffer @ 140012998 =====

/* public: long __cdecl HdaController::AllocateDmaBuffer(struct WDFDEVICE__ * __ptr64,long,unsigned
   __int64,struct _MDL * __ptr64 * __ptr64,unsigned __int64 * __ptr64,class DmaAdapterTracker *
   __ptr64 * __ptr64,void * __ptr64 * __ptr64,union _LARGE_INTEGER * __ptr64,unsigned char *
   __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
HdaController::AllocateDmaBuffer
          (HdaController *this,WDFDEVICE__ *param_1,long param_2,__uint64 param_3,_MDL **param_4,
          __uint64 *param_5,DmaAdapterTracker **param_6,void **param_7,_LARGE_INTEGER *param_8,
          uchar *param_9,ulong *param_10)

{
  void *pvVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  _MDL *p_Var6;
  HdaController *this_00;
  longlong *plVar7;
  ulonglong uVar8;
  int iVar9;
  __uint64 _Var10;
  ulonglong uVar11;
  longlong lVar12;
  uchar uVar13;
  longlong *plVar14;
  bool bVar15;
  ulonglong local_res8;
  undefined8 in_stack_ffffffffffffff38;
  undefined4 in_stack_ffffffffffffff40;
  undefined4 in_stack_ffffffffffffff44;
  undefined2 uVar16;
  undefined8 in_stack_ffffffffffffff50;
  longlong local_88;
  ulonglong local_80;
  _MDL *local_78;
  _MDL *local_70;
  void *local_68;
  void *local_60;
  undefined8 local_58;
  void *local_50;
  longlong local_48;
  void *local_40;
  
  pvVar5 = (void *)0x0;
  local_60 = (void *)0x0;
  local_70 = (_MDL *)0x0;
  local_68 = (void *)0x0;
  _Var10 = param_3;
  cVar2 = KeGetCurrentIrql();
  uVar13 = (uchar)_Var10;
  if (cVar2 == '\0') {
    if ((((param_5 == (__uint64 *)0x0) || (param_4 == (_MDL **)0x0)) || (param_9 == (uchar *)0x0))
       || (param_10 == (ulong *)0x0)) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar2 = '\0';
      }
      if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,0xe,0x69,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      iVar9 = -0x3ffffff3;
    }
    else {
      if ((uint)param_2 < 0x1e) {
        local_80 = 0;
        local_88 = 0;
        local_58 = 0;
        _Var10 = 0x100000;
        if (param_3 < 0x100001) {
          _Var10 = param_3;
        }
        if (_Var10 < 0x100) {
          _Var10 = 0x100;
        }
        if (this[0x9606] == (HdaController)0x0) {
          p_Var6 = AllocateBuffer(this,_Var10,1);
          local_78 = p_Var6;
          if (p_Var6 == (_MDL *)0x0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar2 = '\0';
            }
            bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar2 != '\0') || (bVar15)) {
              uVar16 = 0x6e;
              goto LAB_140012b43;
            }
          }
          else {
            if (*(uint *)(p_Var6 + 0x28) < _Var10) {
              _Var10 = (ulonglong)*(uint *)(p_Var6 + 0x28);
            }
            local_50 = AllocateContiguousBuffer(this,0x1000,0);
            if (local_50 != (void *)0x0) {
LAB_140012c27:
              pvVar1 = local_50;
              local_48 = (longlong)param_2 * 0xd8;
              local_40 = pvVar5;
              uVar3 = KeAcquireSpinLockRaiseToDpc(this + local_48 + 0x200);
              local_70 = p_Var6;
              local_68 = pvVar1;
              if (this[local_48 + 0x20c] == (HdaController)0x0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar2 = '\0';
                }
                else {
                  cVar2 = '\x01';
                }
                if ((cVar2 != '\0') ||
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_AND_TRACE_SF_
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,
                             0xe,0x70,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
                }
LAB_140012e87:
                iVar9 = -0x3ffffff8;
              }
              else {
                if (*(WDFDEVICE__ **)(this + local_48 + 0x2d0) != param_1) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    cVar2 = '\0';
                  }
                  else {
                    cVar2 = '\x01';
                  }
                  if ((cVar2 != '\0') ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    WPP_RECORDER_AND_TRACE_SF_qdq
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,
                               CONCAT44(in_stack_ffffffffffffff44,in_stack_ffffffffffffff40),0x71,
                               in_stack_ffffffffffffff50,(char)param_1,(char)param_2,
                               (char)*(WDFDEVICE__ **)(this + local_48 + 0x2d0));
                  }
                  goto LAB_140012e87;
                }
                if (*(int *)(this + local_48 + 0x268) == 0) {
                  if (this[local_48 + 0x20e] != (HdaController)0x0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                       (bVar15 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
                      bVar15 = false;
                    }
                    if ((bVar15 != false) ||
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      uVar16 = 0x73;
                      goto LAB_140012f45;
                    }
                    goto LAB_140012f5a;
                  }
                  uVar8 = (ulonglong)
                          ((uint)(*(ushort *)(this + local_48 + 0x25e) >> 3) *
                          (uint)*(ushort *)(this + local_48 + 0x260));
                  this[local_48 + 0x20e] = (HdaController)0x1;
                  *(undefined4 *)(this + local_48 + 0x240) = 0;
                  local_70 = (_MDL *)0x0;
                  local_60 = (void *)0x0;
                  uVar11 = _Var10 - _Var10 % uVar8;
                  *(_MDL **)(this + local_48 + 0x218) = local_78;
                  *(void **)(this + local_48 + 0x248) = local_50;
                  local_68 = (void *)0x0;
                  uVar8 = uVar11 - uVar8;
                  if ((uVar11 & 1) == 0) {
                    uVar8 = uVar11;
                  }
                  *(ulonglong *)(this + local_48 + 0x238) = uVar8;
                  if (this[0x9606] != (HdaController)0x0) {
                    *(void **)(this + local_48 + 0x220) = local_40;
                    *(longlong *)(this + local_48 + 0x228) = local_88;
                    *(ulonglong *)(this + local_48 + 0x230) = local_80;
                    *(undefined8 *)(this + local_48 + 0x250) = local_58;
                  }
                  uVar11 = uVar8 + 0xfff >> 0xc;
                  plVar7 = *(longlong **)(this + local_48 + 0x248);
                  plVar14 = (longlong *)(*(longlong *)(this + local_48 + 0x218) + 0x30);
                  uVar8 = *(ulonglong *)(this + local_48 + 0x238);
                  if (uVar11 == 1) {
                    if (uVar8 < 0x101) {
                      uVar11 = 0x80;
                    }
                    else {
                      uVar11 = uVar8 >> 1 & 0x7fffffffffffff80;
                    }
                    if (this[0x9606] == (HdaController)0x0) {
                      lVar12 = *plVar14 << 0xc;
                    }
                    else {
                      lVar12 = local_88;
                    }
                    *plVar7 = lVar12;
                    *(undefined4 *)((longlong)plVar7 + 0xc) = 0;
                    *(int *)(plVar7 + 1) = (int)uVar11;
                    lVar12 = *plVar14;
                    *(undefined4 *)((longlong)plVar7 + 0x1c) = 0;
                    plVar7[2] = lVar12 * 0x1000 + uVar11;
                    *(int *)(plVar7 + 3) = (int)uVar8 - (int)uVar11;
                  }
                  else {
                    iVar9 = 0;
                    for (; uVar11 != 0; uVar11 = uVar11 - 1) {
                      if (this[0x9606] == (HdaController)0x0) {
                        lVar12 = *plVar14 << 0xc;
                      }
                      else {
                        lVar12 = (ulonglong)(uint)(iVar9 << 0xc) + local_88;
                        iVar9 = iVar9 + 1;
                      }
                      *plVar7 = lVar12;
                      uVar4 = 0x1000;
                      *(undefined4 *)((longlong)plVar7 + 0xc) = 0;
                      if (uVar8 < 0x1000) {
                        uVar4 = (undefined4)uVar8;
                        uVar8 = 0;
                      }
                      else {
                        uVar8 = uVar8 - 0x1000;
                      }
                      *(undefined4 *)(plVar7 + 1) = uVar4;
                      plVar14 = plVar14 + 1;
                      plVar7 = plVar7 + 2;
                    }
                  }
                  lVar12 = (longlong)param_2;
                  *param_5 = *(__uint64 *)(this + local_48 + 0x238);
                  *param_4 = *(_MDL **)(this + local_48 + 0x218);
                  *param_6 = *(DmaAdapterTracker **)(this + 0x9650);
                  *param_7 = *(void **)(this + local_48 + 0x220);
                  *(undefined8 *)param_8 = *(undefined8 *)(this + lVar12 * 0xd8 + 0x228);
                  ProgramDmaEngine(this,param_2);
                  *param_9 = (uchar)this[lVar12 * 0xd8 + 0x215];
                  iVar9 = 0;
                  *param_10 = *(ushort *)(lVar12 * 0x20 + 0x90 + *(longlong *)(this + 0x58)) + 1;
                }
                else {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                     (bVar15 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
                    bVar15 = false;
                  }
                  if ((bVar15) ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    uVar16 = 0x72;
LAB_140012f45:
                    WPP_RECORDER_AND_TRACE_SF_
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar15,
                               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,
                               0xe,uVar16,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
                  }
LAB_140012f5a:
                  iVar9 = -0x3ffffff0;
                }
              }
              KeReleaseSpinLock(this + (longlong)param_2 * 0xd8 + 0x200,uVar3);
              goto LAB_1400132ee;
            }
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar2 = '\0';
            }
            else {
              cVar2 = '\x01';
            }
            if ((cVar2 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,0xe,
                         0x6f,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
            }
            FreeBuffer(local_78);
          }
        }
        else {
          this_00 = this;
          pvVar5 = AllocateBufferHal(this,_Var10,(_LARGE_INTEGER *)&local_88,uVar13);
          if (pvVar5 == (void *)0x0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar2 = '\0';
            }
            bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar2 != '\0') || (bVar15)) {
              uVar16 = 0x6b;
LAB_140012b43:
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar15,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,0xe,
                         uVar16,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
            }
          }
          else {
            p_Var6 = AllocateBufferMdl(this_00,pvVar5,_Var10);
            local_78 = p_Var6;
            if (p_Var6 == (_MDL *)0x0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                 (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                cVar2 = '\0';
              }
              if ((cVar2 != '\0') ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,0xe,
                           0x6c,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
              }
            }
            else {
              if (*(uint *)(p_Var6 + 0x28) < _Var10) {
                _Var10 = (ulonglong)*(uint *)(p_Var6 + 0x28);
              }
              local_50 = AllocateBufferHal(this,0x1000,(_LARGE_INTEGER *)&local_58,uVar13);
              if (local_50 != (void *)0x0) {
                local_80 = _Var10;
                local_60 = pvVar5;
                goto LAB_140012c27;
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
                cVar2 = '\0';
              }
              else {
                cVar2 = '\x01';
              }
              if ((cVar2 != '\0') ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,0xe,
                           0x6d,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
              }
              FreeBufferMdl(local_78);
            }
            FreeBufferHal(*(undefined8 *)(this + 0x9650),_Var10,pvVar5,local_88);
          }
        }
        iVar9 = -0x3fffff66;
        goto LAB_1400132ee;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar2 = '\0';
      }
      if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,0xe,0x6a,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      iVar9 = -0x3ffffff8;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,0xe,0x68,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    iVar9 = -0x3fffffff;
  }
  local_80 = local_res8;
LAB_1400132ee:
  cVar2 = '\x01';
  if (this[0x9606] == (HdaController)0x0) {
    if (local_70 != (_MDL *)0x0) {
      FreeBuffer(local_70);
    }
    if (local_68 != (void *)0x0) {
      FreeContiguousBuffer(local_68,0x1000,0);
    }
  }
  else {
    if (local_70 != (_MDL *)0x0) {
      FreeBufferMdl(local_70);
    }
    if (local_60 != (void *)0x0) {
      FreeBufferHal(*(undefined8 *)(this + 0x9650),local_80,local_60,local_88);
    }
    if (local_68 != (void *)0x0) {
      FreeBufferHal(*(undefined8 *)(this + 0x9650),0x1000,local_68,local_58);
    }
  }
  if (iVar9 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,0xe,0x74,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar9);
    }
  }
  return iVar9;
}



===== AllocateDmaBufferWithNotification @ 1400133f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HdaController::AllocateDmaBufferWithNotification(struct WDFDEVICE__ *
   __ptr64,long,unsigned long,unsigned __int64,struct _MDL * __ptr64 * __ptr64,unsigned __int64 *
   __ptr64,unsigned __int64 * __ptr64,class DmaAdapterTracker * __ptr64 * __ptr64,void * __ptr64 *
   __ptr64,union _LARGE_INTEGER * __ptr64,unsigned char * __ptr64,unsigned long * __ptr64) __ptr64
    */

long __thiscall
HdaController::AllocateDmaBufferWithNotification
          (HdaController *this,WDFDEVICE__ *param_1,long param_2,ulong param_3,__uint64 param_4,
          _MDL **param_5,__uint64 *param_6,__uint64 *param_7,DmaAdapterTracker **param_8,
          void **param_9,_LARGE_INTEGER *param_10,uchar *param_11,ulong *param_12)

{
  bool bVar1;
  longlong *plVar2;
  uchar uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  ulonglong uVar7;
  _MDL *p_Var8;
  undefined8 uVar9;
  longlong lVar10;
  longlong *plVar11;
  char cVar12;
  HdaController *pHVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  int iVar16;
  ulonglong uVar17;
  HdaController *pHVar18;
  bool bVar19;
  undefined8 in_stack_ffffffffffffff28;
  undefined4 in_stack_ffffffffffffff30;
  undefined4 in_stack_ffffffffffffff34;
  undefined2 uVar20;
  undefined8 in_stack_ffffffffffffff40;
  _MDL *local_98;
  longlong local_88;
  _MDL *local_80;
  undefined8 local_78;
  _MDL *local_70;
  longlong *local_68;
  _MDL *local_60;
  longlong *local_58;
  
  p_Var8 = (_MDL *)0x0;
  local_88 = 0;
  local_78 = 0;
  local_60 = (_MDL *)0x0;
  local_70 = (_MDL *)0x0;
  local_68 = (longlong *)0x0;
  local_98 = (_MDL *)0x0;
  uVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x70),
                     PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar12 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar12 = '\0';
  }
  if ((cVar4 != '\0') || (cVar12 != '\0')) {
    uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_AND_TRACE_SF_DSDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar12,uVar14);
    uVar3 = (uchar)uVar14;
  }
  cVar4 = KeGetCurrentIrql();
  if (cVar4 == '\0') {
    if (((((param_4 == 0) || (param_5 == (_MDL **)0x0)) || (param_6 == (__uint64 *)0x0)) ||
        ((param_7 == (__uint64 *)0x0 || (param_11 == (uchar *)0x0)))) || (param_12 == (ulong *)0x0))
    {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar4 = '\0';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar20 = 0xab;
LAB_140013fa4:
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,0xe,uVar20,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
    }
    else {
      if (param_3 - 1 < 2) {
        if (0x1d < (uint)param_2) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
             (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar4 = '\0';
          }
          if ((cVar4 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,0xe,0xad
                       ,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
          iVar16 = -0x3ffffff8;
          goto LAB_140013fbe;
        }
        if (0x100000 < param_4) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
             (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
            cVar4 = '\0';
          }
          if ((cVar4 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar20 = 0xae;
            goto LAB_140013fa4;
          }
          goto LAB_140013fb9;
        }
        uVar7 = Feature_4246965561__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar7 != 0) && (param_4 < param_3)) {
          param_4 = param_4 * param_3;
        }
        if ((param_3 == 2) && ((param_4 & 0xfe) != 0)) {
          param_4 = (param_4 & 0xffffffffffffff00) + 0x100;
        }
        uVar7 = param_4;
        if ((param_4 & 0x1fff) != 0) {
          uVar7 = (param_4 - ((uint)param_4 & 0x1fff)) + 0x2000;
        }
        pHVar18 = (HdaController *)(uVar7 + param_4 >> 1);
        uVar7 = uVar7 - param_4 >> 1;
        if (this[0x9606] == (HdaController)0x0) {
          p_Var8 = AllocateBuffer(this,(__uint64)pHVar18,1);
          local_80 = p_Var8;
          if (p_Var8 == (_MDL *)0x0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar4 = '\0';
            }
            else {
              cVar4 = '\x01';
            }
            bVar19 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar4 != '\0') || (bVar19)) {
              uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
              uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              uVar20 = 0xb3;
              goto LAB_14001376e;
            }
            goto LAB_14001377b;
          }
          if ((HdaController *)(ulonglong)*(uint *)(p_Var8 + 0x28) < pHVar18) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar4 = '\0';
            }
            else {
              cVar4 = '\x01';
            }
            bVar19 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar4 != '\0') || (bVar19)) {
              uVar20 = 0xb4;
LAB_140013a21:
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar19,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,0xe,
                         uVar20,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
            }
          }
          else {
            local_58 = AllocateContiguousBuffer(this,0x1000,0);
            if (local_58 != (longlong *)0x0) {
LAB_140013abb:
              plVar2 = local_58;
              p_Var8 = local_80 + 0x30;
              iVar16 = 0;
              uVar17 = (ulonglong)(pHVar18 + 0xfff) >> 0xc;
              pHVar13 = pHVar18;
              plVar11 = local_58;
              for (uVar15 = uVar17; uVar15 != 0; uVar15 = uVar15 - 1) {
                *(undefined4 *)((longlong)plVar11 + 0xc) = 0;
                if (this[0x9606] == (HdaController)0x0) {
                  lVar10 = *(longlong *)p_Var8 << 0xc;
                }
                else {
                  lVar10 = (ulonglong)(uint)(iVar16 << 0xc) + local_88;
                  iVar16 = iVar16 + 1;
                }
                *plVar11 = lVar10;
                if (uVar17 == uVar15) {
                  *plVar11 = lVar10 + uVar7;
                  pHVar13 = pHVar13 + -0x1000;
                  iVar6 = 0x1000 - (int)uVar7;
                }
                else if (pHVar13 < (HdaController *)0x1000) {
                  iVar6 = (int)pHVar13;
                }
                else {
                  pHVar13 = pHVar13 + -0x1000;
                  iVar6 = 0x1000;
                }
                *(int *)(plVar11 + 1) = iVar6;
                p_Var8 = p_Var8 + 8;
                plVar11 = plVar11 + 2;
              }
              *(undefined4 *)((longlong)local_58 + uVar17 * 0x10 + -4) = 1;
              if (param_3 == 2) {
                *(undefined4 *)
                 ((longlong)local_58 + ((ulonglong)(pHVar18 + 0xfff) >> 0xd) * 0x10 + -4) = 1;
              }
              lVar10 = (longlong)param_2 * 0xd8;
              uVar5 = KeAcquireSpinLockRaiseToDpc(this + lVar10 + 0x200);
              local_60 = local_98;
              local_70 = local_80;
              local_68 = plVar2;
              if (this[lVar10 + 0x20c] == (HdaController)0x0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar4 = '\0';
                }
                else {
                  cVar4 = '\x01';
                }
                if ((cVar4 != '\0') ||
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_AND_TRACE_SF_
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,
                             0xe,0xb6,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
                }
LAB_140013c1e:
                iVar16 = -0x3ffffff8;
              }
              else {
                if (*(WDFDEVICE__ **)(this + lVar10 + 0x2d0) != param_1) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    cVar4 = '\0';
                  }
                  else {
                    cVar4 = '\x01';
                  }
                  if ((cVar4 != '\0') ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    WPP_RECORDER_AND_TRACE_SF_qdq
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,
                               CONCAT44(in_stack_ffffffffffffff34,in_stack_ffffffffffffff30),0xb7,
                               in_stack_ffffffffffffff40,(char)param_1,(char)param_2,
                               (char)*(WDFDEVICE__ **)(this + lVar10 + 0x2d0));
                  }
                  goto LAB_140013c1e;
                }
                if (*(int *)(this + lVar10 + 0x268) == 0) {
                  if (this[lVar10 + 0x20e] != (HdaController)0x0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                       (bVar19 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
                      bVar19 = false;
                    }
                    if ((bVar19 != false) ||
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      uVar20 = 0xb9;
                      goto LAB_140013d07;
                    }
                    goto LAB_140013d20;
                  }
                  *(_MDL **)(this + lVar10 + 0x278) = local_98;
                  *(undefined8 *)(this + lVar10 + 0x298) = 0;
                  *(HdaController **)(this + lVar10 + 0x2a0) = this + lVar10 + 0x200;
                  this[lVar10 + 0x26e] = (HdaController)((char)uVar17 + -1);
                  *(longlong *)(this + lVar10 + 0x280) = local_88;
                  this[lVar10 + 0x20e] = (HdaController)0x1;
                  *(undefined2 *)(this + lVar10 + 0x26c) = 0x101;
                  *(_MDL **)(this + lVar10 + 0x270) = local_80;
                  *(__uint64 *)(this + lVar10 + 0x290) = param_4;
                  *(__uint64 *)(this + lVar10 + 0x238) = param_4;
                  *(undefined4 *)(this + lVar10 + 0x240) = 1;
                  local_60 = (_MDL *)0x0;
                  local_70 = (_MDL *)0x0;
                  local_68 = (longlong *)0x0;
                  *(longlong **)(this + lVar10 + 0x248) = local_58;
                  *(undefined8 *)(this + lVar10 + 0x250) = local_78;
                  *(HdaController **)(this + ((longlong)param_2 + 3) * 0xd8) = pHVar18;
                  *param_5 = local_80;
                  *param_7 = uVar7;
                  *param_8 = *(DmaAdapterTracker **)(this + 0x9650);
                  *param_9 = local_98;
                  *(longlong *)param_10 = local_88;
                  *param_6 = param_4;
                  ProgramDmaEngine(this,param_2);
                  *param_11 = (uchar)this[lVar10 + 0x215];
                  iVar16 = 0;
                  *param_12 = *(ushort *)
                               (*(longlong *)(this + 0x58) + 0x90 + (longlong)param_2 * 0x20) + 1;
                }
                else {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                     (bVar19 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
                    bVar19 = false;
                  }
                  if ((bVar19) ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    uVar20 = 0xb8;
LAB_140013d07:
                    WPP_RECORDER_AND_TRACE_SF_
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar19,
                               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,
                               0xe,uVar20,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
                  }
LAB_140013d20:
                  iVar16 = -0x3ffffff0;
                }
              }
              KeReleaseSpinLock(this + (longlong)param_2 * 0xd8 + 0x200,uVar5);
              p_Var8 = local_80;
              goto LAB_140013fc5;
            }
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar4 = '\0';
            }
            else {
              cVar4 = '\x01';
            }
            bVar19 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar4 != '\0') || (bVar19)) {
              uVar20 = 0xb5;
              goto LAB_140013a21;
            }
          }
          FreeBuffer(p_Var8);
        }
        else {
          pHVar13 = this;
          local_98 = AllocateBufferHal(this,(__uint64)pHVar18,(_LARGE_INTEGER *)&local_88,uVar3);
          if (local_98 != (_MDL *)0x0) {
            p_Var8 = AllocateBufferMdl(pHVar13,local_98,(__uint64)pHVar18);
            local_80 = p_Var8;
            if (p_Var8 == (_MDL *)0x0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
                cVar4 = '\0';
              }
              else {
                cVar4 = '\x01';
              }
              if ((cVar4 != '\0') ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,0xe,
                           0xb0,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
              }
LAB_14001380e:
              pHVar13 = pHVar18;
            }
            else {
              if (pHVar18 <= (HdaController *)(ulonglong)*(uint *)(p_Var8 + 0x28)) {
                local_58 = AllocateBufferHal(this,0x1000,(_LARGE_INTEGER *)&local_78,uVar3);
                if (local_58 != (longlong *)0x0) goto LAB_140013abb;
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
                  cVar4 = '\0';
                }
                else {
                  cVar4 = '\x01';
                }
                if ((cVar4 != '\0') ||
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_AND_TRACE_SF_
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,
                             0xe,0xb2,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
                }
                FreeBufferMdl(p_Var8);
                goto LAB_14001380e;
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
                cVar4 = '\0';
              }
              else {
                cVar4 = '\x01';
              }
              if ((cVar4 != '\0') ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,0xe,
                           0xb1,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
              }
              FreeBufferMdl(p_Var8);
              pHVar13 = (HdaController *)(ulonglong)*(uint *)(p_Var8 + 0x28);
            }
            FreeBufferHal(*(undefined8 *)(this + 0x9650),pHVar13,local_98,local_88);
            iVar16 = -0x3fffff66;
            goto LAB_140013fc5;
          }
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar4 = '\0';
          }
          else {
            cVar4 = '\x01';
          }
          bVar19 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar4 != '\0') || (bVar19)) {
            uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
            uVar20 = 0xaf;
LAB_14001376e:
            WPP_RECORDER_AND_TRACE_SF_
                      (uVar9,cVar4,bVar19,uVar14,in_stack_ffffffffffffff28,0xe,uVar20,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
        }
LAB_14001377b:
        iVar16 = -0x3fffff66;
        goto LAB_140013fc5;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar4 = '\0';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar20 = 0xac;
        goto LAB_140013fa4;
      }
    }
LAB_140013fb9:
    iVar16 = -0x3ffffff3;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,0xe,0xaa,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    iVar16 = -0x3fffffff;
  }
LAB_140013fbe:
  local_98 = p_Var8;
  pHVar18 = this;
LAB_140013fc5:
  if (this[0x9606] == (HdaController)0x0) {
    if (local_70 != (_MDL *)0x0) {
      FreeBuffer(p_Var8);
    }
    if (local_68 != (longlong *)0x0) {
      FreeContiguousBuffer(local_68,0x1000,0);
    }
  }
  else {
    if (local_70 != (_MDL *)0x0) {
      FreeBufferMdl(p_Var8);
    }
    if (local_60 != (_MDL *)0x0) {
      FreeBufferHal(*(undefined8 *)(this + 0x9650),pHVar18,local_98,local_88);
    }
    if (local_68 != (longlong *)0x0) {
      FreeBufferHal(*(undefined8 *)(this + 0x9650),0x1000,local_68,local_78);
    }
  }
  if (iVar16 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,0xe,0xba,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar16);
    }
  }
  return iVar16;
}



===== ChangeBandwidthAllocation @ 1400140d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HdaController::ChangeBandwidthAllocation(struct WDFDEVICE__ *
   __ptr64,long,unsigned char,struct _HDAUDIO_STREAM_FORMAT * __ptr64,struct
   _HDAUDIO_CONVERTER_FORMAT * __ptr64) __ptr64 */

long __thiscall
HdaController::ChangeBandwidthAllocation
          (HdaController *this,WDFDEVICE__ *param_1,long param_2,uchar param_3,
          _HDAUDIO_STREAM_FORMAT *param_4,_HDAUDIO_CONVERTER_FORMAT *param_5)

{
  undefined1 uVar1;
  uchar uVar2;
  ushort uVar3;
  long lVar4;
  int iVar5;
  OutputLinkBandwidth *this_00;
  LinkBandwidth *pLVar6;
  char cVar7;
  longlong lVar8;
  bool bVar9;
  undefined2 in_stack_ffffffffffffff58;
  undefined6 in_stack_ffffffffffffff5a;
  uint in_stack_ffffffffffffff60;
  undefined4 in_stack_ffffffffffffff64;
  undefined2 uVar10;
  undefined8 in_stack_ffffffffffffff70;
  long local_64;
  LinkBandwidth *local_60;
  longlong local_58;
  OutputLinkBandwidth *local_50;
  longlong local_48;
  
  local_64 = 0;
  if ((uint)param_2 < 0x1e) {
    if ((param_4 == (_HDAUDIO_STREAM_FORMAT *)0x0) || (param_5 == (_HDAUDIO_CONVERTER_FORMAT *)0x0))
    {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0 ||
          ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      bVar9 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar7 != '\0') || (bVar9)) {
        uVar10 = 0x5f;
        goto LAB_1400149b1;
      }
    }
    else {
      lVar4 = BuildHDAudioConverterFormat(this,param_4,param_5);
      if (-1 < lVar4) {
        lVar8 = (longlong)param_2 * 0xd8;
        uVar1 = KeAcquireSpinLockRaiseToDpc(this + lVar8 + 0x200);
        if (this[lVar8 + 0x20c] == (HdaController)0x0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
             (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar7 = '\0';
          }
          if ((cVar7 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT62(in_stack_ffffffffffffff5a,in_stack_ffffffffffffff58),0xe,0x61,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
LAB_140014246:
          iVar5 = -0x3ffffff8;
        }
        else {
          if (*(WDFDEVICE__ **)(this + lVar8 + 0x2d0) != param_1) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar7 = '\0';
            }
            if ((cVar7 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_qdq
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                         CONCAT62(in_stack_ffffffffffffff5a,in_stack_ffffffffffffff58),
                         CONCAT44(in_stack_ffffffffffffff64,in_stack_ffffffffffffff60),0x62,
                         in_stack_ffffffffffffff70,(char)param_1,(char)param_2,
                         (char)*(WDFDEVICE__ **)(this + lVar8 + 0x2d0));
            }
            goto LAB_140014246;
          }
          if (*(int *)(this + lVar8 + 0x268) == 0) {
            if (this[lVar8 + 0x20e] != (HdaController)0x0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                 (bVar9 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
                bVar9 = false;
              }
              if ((bVar9 != false) ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                uVar10 = 100;
                goto LAB_14001430c;
              }
              goto LAB_140014321;
            }
            if ((*(int *)(this + lVar8 + 0x208) == 0) || (*(int *)(this + lVar8 + 0x208) == 3)) {
              local_50 = (OutputLinkBandwidth *)GetInputLinkBandwidth(this,param_3);
              if (local_50 == (OutputLinkBandwidth *)0x0) {
LAB_14001465e:
                iVar5 = -0x3ffffff2;
              }
              else {
                in_stack_ffffffffffffff58 = *(undefined2 *)(param_4 + 4);
                iVar5 = (*(code *)**(undefined8 **)local_50)
                                  (local_50,&local_64,(byte)param_5[1] & 0x7f,
                                   *(undefined2 *)(param_4 + 8),in_stack_ffffffffffffff58,
                                   in_stack_ffffffffffffff60 & 0xffffff00);
                if (-1 < iVar5) {
                  local_48 = (longlong)param_2 * 0xd8;
                  uVar2 = LinkBandwidth::ChangeBandwidth
                                    ((LinkBandwidth *)local_50,*(long *)(this + local_48 + 0x210),
                                     local_64);
                  if (uVar2 == '\0') {
LAB_1400146dc:
                    iVar5 = -0x3fffff66;
                  }
                  else {
                    KeAcquireSpinLockAtDpcLevel(this + 0x1f8);
                    local_58 = (longlong)param_2 * 0xd8;
                    uVar10 = *(undefined2 *)(this + local_58 + 0x264);
                    *(undefined2 *)(this + local_58 + 0x264) = *(undefined2 *)param_5;
                    ResetDmaEngine(this,param_2);
                    uVar3 = ProbeForFifoSize(this,param_2);
                    lVar8 = local_58;
                    local_60 = (LinkBandwidth *)((longlong)param_2 * 0xd8);
                    iVar5 = ((*(ushort *)param_5 >> 0xb & 7) + 1) * (uint)*(ushort *)(param_4 + 6) *
                            (uint)*(ushort *)(param_4 + 8);
                    if ((int)(uint)uVar3 < iVar5 / 8) {
                      *(undefined2 *)(this + local_58 + 0x264) = uVar10;
                      ResetDmaEngine(this,param_2);
                      uVar3 = ProbeForFifoSize(this,param_2);
                      if ((int)(uint)uVar3 <
                          (int)(((*(ushort *)(this + lVar8 + 0x264) >> 0xb & 7) + 1) *
                                (uint)*(ushort *)(this + (longlong)param_2 * 0xd8 + 0x25e) *
                               (uint)*(ushort *)
                                      ((OutputLinkBandwidth *)(local_60 + 0x260) + (longlong)this))
                          / 8) {
                        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                          cVar7 = '\0';
                        }
                        else {
                          cVar7 = '\x01';
                        }
                        if ((cVar7 != '\0') ||
                           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                          WPP_RECORDER_AND_TRACE_SF_
                                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                                     (undefined **)WPP_RECORDER_INITIALIZED !=
                                     &WPP_RECORDER_INITIALIZED,
                                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                     CONCAT62(in_stack_ffffffffffffff5a,in_stack_ffffffffffffff58),
                                     0xe,0x65,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
                        }
                      }
                      this_00 = local_50;
                      goto LAB_1400145d5;
                    }
                    KeReleaseSpinLockFromDpcLevel(this + 0x1f8,(longlong)iVar5 % 8 & 0xffffffff);
                    *(long *)(this + local_48 + 0x210) = local_64;
                    uVar10 = *(undefined2 *)param_5;
                    pLVar6 = local_60;
LAB_14001488c:
                    *(undefined2 *)(this + local_58 + 0x264) = uVar10;
                    iVar5 = 0;
                    *(undefined8 *)((OutputLinkBandwidth *)(pLVar6 + 600) + (longlong)this) =
                         *(undefined8 *)param_4;
                    *(undefined4 *)((OutputLinkBandwidth *)(pLVar6 + 0x260) + (longlong)this) =
                         *(undefined4 *)(param_4 + 8);
                  }
                }
              }
            }
            else if ((this[lVar8 + 0x20f] == (HdaController)0x0) ||
                    (0xf < (int)(((*(ushort *)param_5 >> 0xb & 7) + 1) *
                                 (uint)*(ushort *)(param_4 + 4) * (uint)*(ushort *)(param_4 + 8))))
            {
              local_60 = (LinkBandwidth *)GetOutputLinkBandwidth(this,param_3);
              if (local_60 == (LinkBandwidth *)0x0) goto LAB_14001465e;
              in_stack_ffffffffffffff58 = *(undefined2 *)(param_4 + 4);
              iVar5 = (*(code *)**(undefined8 **)local_60)
                                (local_60,&local_64,(byte)param_5[1] & 0x7f,
                                 *(undefined2 *)(param_4 + 8),in_stack_ffffffffffffff58,
                                 this[lVar8 + 0x20f]);
              if (-1 < iVar5) {
                local_48 = (longlong)param_2 * 0xd8;
                uVar2 = LinkBandwidth::ChangeBandwidth
                                  (local_60,*(long *)(this + local_48 + 0x210),local_64);
                if (uVar2 == '\0') goto LAB_1400146dc;
                KeAcquireSpinLockAtDpcLevel(this + 0x1f8);
                local_58 = (longlong)param_2 * 0xd8;
                uVar10 = *(undefined2 *)(this + local_58 + 0x264);
                *(undefined2 *)(this + local_58 + 0x264) = *(undefined2 *)param_5;
                ResetDmaEngine(this,param_2);
                uVar3 = ProbeForFifoSize(this,param_2);
                lVar8 = local_58;
                local_50 = (OutputLinkBandwidth *)((longlong)param_2 * 0xd8);
                iVar5 = ((*(ushort *)param_5 >> 0xb & 7) + 1) * (uint)*(ushort *)(param_4 + 6) *
                        (uint)*(ushort *)(param_4 + 8);
                if (iVar5 / 8 <= (int)(uint)uVar3) {
                  KeReleaseSpinLockFromDpcLevel(this + 0x1f8,(longlong)iVar5 % 8 & 0xffffffff);
                  *(long *)(this + local_48 + 0x210) = local_64;
                  uVar10 = *(undefined2 *)param_5;
                  pLVar6 = (LinkBandwidth *)local_50;
                  goto LAB_14001488c;
                }
                *(undefined2 *)(this + local_58 + 0x264) = uVar10;
                ResetDmaEngine(this,param_2);
                uVar3 = ProbeForFifoSize(this,param_2);
                if ((int)(uint)uVar3 <
                    (int)(((*(ushort *)(this + lVar8 + 0x264) >> 0xb & 7) + 1) *
                          (uint)*(ushort *)(this + (longlong)param_2 * 0xd8 + 0x25e) *
                         (uint)*(ushort *)(local_50 + 0x260 + (longlong)this)) / 8) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    cVar7 = '\0';
                  }
                  else {
                    cVar7 = '\x01';
                  }
                  if ((cVar7 != '\0') ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    WPP_RECORDER_AND_TRACE_SF_
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                               CONCAT62(in_stack_ffffffffffffff5a,in_stack_ffffffffffffff58),0xe,
                               0x66,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
                  }
                }
                this_00 = (OutputLinkBandwidth *)local_60;
LAB_1400145d5:
                LinkBandwidth::ChangeBandwidth
                          ((LinkBandwidth *)this_00,local_64,
                           *(long *)(this + (longlong)param_2 * 0xd8 + 0x210));
                KeReleaseSpinLockFromDpcLevel(this + 0x1f8);
                iVar5 = -0x3fffffdd;
              }
            }
            else {
              iVar5 = -0x3ffffff3;
            }
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
               (bVar9 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
              bVar9 = false;
            }
            if ((bVar9) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar10 = 99;
LAB_14001430c:
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar9,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                         CONCAT62(in_stack_ffffffffffffff5a,in_stack_ffffffffffffff58),0xe,uVar10,
                         &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
            }
LAB_140014321:
            iVar5 = -0x3ffffff0;
          }
        }
        KeReleaseSpinLock(this + (longlong)param_2 * 0xd8 + 0x200,uVar1);
        if (-1 < iVar5) {
          return iVar5;
        }
        goto LAB_1400149cb;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      bVar9 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar7 != '\0') || (bVar9)) {
        uVar10 = 0x60;
        goto LAB_1400149b1;
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    bVar9 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar7 != '\0') || (bVar9)) {
      uVar10 = 0x5e;
LAB_1400149b1:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar9,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT62(in_stack_ffffffffffffff5a,in_stack_ffffffffffffff58),0xe,uVar10,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
  }
  iVar5 = -0x3ffffff8;
LAB_1400149cb:
  bVar9 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar9 = false;
  }
  if ((bVar9) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar9,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT62(in_stack_ffffffffffffff5a,in_stack_ffffffffffffff58),0xe,0x67,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar5);
  }
  return iVar5;
}



===== CleanUpDmaAdapter @ 140014a48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl DmaAdapterTracker::CleanUpDmaAdapter(void) __ptr64 */

void __thiscall DmaAdapterTracker::CleanUpDmaAdapter(DmaAdapterTracker *this)

{
  undefined1 uVar1;
  
  uVar1 = KfRaiseIrql(2);
  (**(code **)(*(longlong *)(*(longlong *)this + 8) + 8))();
  KeLowerIrql(uVar1);
  *(undefined8 *)this = 0;
  *(undefined4 *)(this + 8) = 0;
  operator_delete(this);
  return;
}



===== FreeBufferHal @ 140014aa8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl HdaController::FreeBufferHal(class DmaAdapterTracker *
   __ptr64,unsigned __int64,void * __ptr64,union _LARGE_INTEGER,unsigned char) */

void __cdecl
HdaController::FreeBufferHal
          (DmaAdapterTracker *param_1,ulonglong param_2,longlong param_3,undefined8 param_4)

{
  DmaAdapterTracker *pDVar1;
  int iVar2;
  char cVar3;
  undefined1 in_stack_ffffffffffffffc8;
  undefined7 in_stack_ffffffffffffffc9;
  
  if (param_3 != 0) {
    if ((param_2 < 0x100000000) && ((uint)param_2 < 0xfffff000)) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_qi
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      (**(code **)(*(longlong *)(*(longlong *)param_1 + 8) + 0x18))
                (*(longlong *)param_1,(uint)param_2 + 0xfff & 0xfffff000,param_4,param_3,0);
      LOCK();
      pDVar1 = param_1 + 8;
      iVar2 = *(int *)pDVar1;
      *(int *)pDVar1 = *(int *)pDVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        DmaAdapterTracker::CleanUpDmaAdapter(param_1);
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0 ||
          ((byte)WPP_GLOBAL_Control[0x29] < 3)))) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT71(in_stack_ffffffffffffffc9,in_stack_ffffffffffffffc8),0xe,0x18,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
    }
  }
  return;
}



===== FreeBufferMdl @ 140014c0c =====

/* private: static void __cdecl HdaController::FreeBufferMdl(struct _MDL * __ptr64) */

void __cdecl HdaController::FreeBufferMdl(_MDL *param_1)

{
  if (param_1 != (_MDL *)0x0) {
    IoFreeMdl();
  }
  return;
}



===== FreeContiguousDmaBuffer @ 140014c30 =====

/* public: long __cdecl HdaController::FreeContiguousDmaBuffer(long) __ptr64 */

long __thiscall HdaController::FreeContiguousDmaBuffer(HdaController *this,long param_1)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  long lVar4;
  longlong lVar5;
  void *pvVar6;
  void *local_res20;
  undefined8 in_stack_ffffffffffffff88;
  undefined2 uVar7;
  __uint64 local_48;
  
  pvVar6 = (void *)0x0;
  local_48 = 0;
  local_res20 = (void *)0x0;
  if (0x1d < (uint)param_1) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x98,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar4 = -0x3ffffff8;
    goto LAB_140014f22;
  }
  lVar5 = (longlong)param_1 * 0xd8;
  uVar2 = KeAcquireSpinLockRaiseToDpc(this + lVar5 + 0x200);
  if (this[lVar5 + 0x20c] == (HdaController)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x99,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar4 = -0x3ffffff8;
  }
  else if (*(int *)(this + lVar5 + 0x268) == 0) {
    if (this[lVar5 + 0x26c] == (HdaController)0x0) {
      if (this[lVar5 + 0x20e] != (HdaController)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           (bVar1 = true, (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar1 = false;
        }
        if ((bVar1 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar7 = 0x9b;
          goto LAB_140014d5f;
        }
        goto LAB_140014d7c;
      }
    }
    else if (this[lVar5 + 0x20e] != (HdaController)0x0) {
      local_res20 = *(void **)(this + lVar5 + 0x270);
      local_48 = *(__uint64 *)(this + lVar5 + 0x290);
      pvVar6 = *(void **)(this + lVar5 + 0x248);
      *(undefined8 *)(this + lVar5 + 0x270) = 0;
      *(undefined8 *)(this + lVar5 + 0x290) = 0;
      *(undefined8 *)(this + lVar5 + 0x238) = 0;
      *(undefined8 *)(this + lVar5 + 0x248) = 0;
    }
    this[lVar5 + 0x26c] = (HdaController)0x0;
    this[lVar5 + 0x20e] = (HdaController)0x0;
    lVar4 = 0;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       (bVar1 = true, (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar7 = 0x9a;
LAB_140014d5f:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,uVar7,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
LAB_140014d7c:
    lVar4 = -0x3ffffff0;
  }
  KeReleaseSpinLock(this + (longlong)param_1 * 0xd8 + 0x200,uVar2);
  if (local_res20 != (void *)0x0) {
    FreeContiguousBuffer(local_res20,local_48,2);
  }
  if (pvVar6 != (void *)0x0) {
    FreeContiguousBuffer(pvVar6,0x1000,0);
  }
  if (-1 < lVar4) {
    return lVar4;
  }
LAB_140014f22:
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x9c,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar4);
  }
  return lVar4;
}



===== FreeDetachedAudioBuffer @ 140014f94 =====

/* public: static long __cdecl HdaController::FreeDetachedAudioBuffer(void * __ptr64,unsigned
   __int64,class DmaAdapterTracker * __ptr64,void * __ptr64,union _LARGE_INTEGER,enum
   _HdaBufferType) */

long __cdecl
HdaController::FreeDetachedAudioBuffer
          (_MDL *param_1,__uint64 param_2,longlong param_3,undefined8 param_4,longlong param_5,
          int param_6)

{
  char cVar1;
  long lVar2;
  char cVar3;
  
  lVar2 = 0;
  cVar3 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar1 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  if ((cVar1 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qPd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if ((param_1 == (_MDL *)0x0) || (2 < param_6)) {
    lVar2 = -0x3ffffff3;
  }
  else if ((param_3 == 0) || (param_5 == 0)) {
    if ((param_6 == 0) || (param_6 == 1)) {
      FreeBuffer(param_1);
    }
    else if (param_6 == 2) {
      FreeContiguousBuffer(param_1,param_2,2);
    }
  }
  else {
    FreeBufferMdl(param_1);
    FreeBufferHal(param_3,param_2,param_4,param_5);
  }
  return lVar2;
}



===== GetDmaAdapter @ 1400150b4 =====

/* public: static long __cdecl DmaAdapterTracker::GetDmaAdapter(struct _DEVICE_OBJECT *
   __ptr64,struct _DEVICE_DESCRIPTION * __ptr64,class DmaAdapterTracker * __ptr64 * __ptr64,unsigned
   long * __ptr64) */

long __cdecl
DmaAdapterTracker::GetDmaAdapter
          (_DEVICE_OBJECT *param_1,_DEVICE_DESCRIPTION *param_2,DmaAdapterTracker **param_3,
          ulong *param_4)

{
  DmaAdapterTracker *pDVar1;
  longlong lVar2;
  
  pDVar1 = operator_new(0x10,0x200,0x44427a41);
  if (pDVar1 != (DmaAdapterTracker *)0x0) {
    *(longlong *)(pDVar1 + 8) = 0;
    *(longlong *)pDVar1 = 0;
    lVar2 = IoGetDmaAdapter(param_1,param_2,param_4);
    *(longlong *)pDVar1 = lVar2;
    if (lVar2 != 0) {
      LOCK();
      *(int *)(pDVar1 + 8) = *(int *)(pDVar1 + 8) + 1;
      UNLOCK();
      *param_3 = pDVar1;
      return 0;
    }
    operator_delete(pDVar1);
  }
  return -0x3fffff66;
}



===== HandleRirbFifoOverrun @ 140015154 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl HdaController::HandleRirbFifoOverrun(void) __ptr64 */

void __thiscall HdaController::HandleRirbFifoOverrun(HdaController *this)

{
  uint *puVar1;
  HdaController HVar2;
  uint uVar3;
  undefined1 uVar4;
  HdaController HVar5;
  byte bVar6;
  _SLIST_ENTRY *p_Var7;
  longlong lVar8;
  char cVar9;
  longlong lVar10;
  undefined8 *puVar11;
  FifoQueue *this_00;
  char cVar12;
  undefined8 in_stack_ffffffffffffffa8;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(this + 0xf0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
     (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
    cVar9 = '\0';
  }
  if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,0x2b,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
  }
  if (this[0xca] != this[200]) {
    do {
      for (puVar11 = *(undefined8 **)(this + 0x100); puVar11 != (undefined8 *)0x0;
          puVar11 = (undefined8 *)*puVar11) {
        while (*(char *)((longlong)puVar11 + 0x24) == '\x01') {
          if (*(char *)((longlong)puVar11 + 0x25) != *(char *)((longlong)puVar11 + 0x26)) {
            do {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
                 (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
                cVar9 = '\0';
              }
              if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                 (cVar12 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
                cVar12 = '\0';
              }
              if ((cVar9 != '\0') || (cVar12 != '\0')) {
                WPP_RECORDER_AND_TRACE_SF_D
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,cVar12,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,
                           0x2c,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,
                           (char)*(undefined4 *)
                                  (puVar11[5] +
                                  (ulonglong)*(uint *)((longlong)puVar11 + 0x1c) * 0x10));
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
                 (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
                cVar9 = '\0';
              }
              if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
                 (cVar12 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
                cVar12 = '\0';
              }
              if ((cVar9 != '\0') || (cVar12 != '\0')) {
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,cVar12,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,
                           0x2d,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
              }
              *(undefined8 *)
               (puVar11[5] + 8 + (ulonglong)*(uint *)((longlong)puVar11 + 0x1c) * 0x10) = 0;
              puVar1 = (uint *)(puVar11[5] + 0xc +
                               (ulonglong)*(uint *)((longlong)puVar11 + 0x1c) * 0x10);
              *puVar1 = *puVar1 | 0x40000000;
              *(int *)((longlong)puVar11 + 0x1c) = *(int *)((longlong)puVar11 + 0x1c) + 1;
              this[0xca] = (HdaController)((char)this[0xca] + '\x01');
              *(char *)((longlong)puVar11 + 0x25) = *(char *)((longlong)puVar11 + 0x25) + '\x01';
            } while (*(char *)((longlong)puVar11 + 0x25) != *(char *)((longlong)puVar11 + 0x26));
          }
          this_00 = (FifoQueue *)(this + 0x100);
          *(undefined2 *)((longlong)puVar11 + 0x24) = 0;
          if ((*(int *)(puVar11 + 3) != *(int *)(puVar11 + 4)) ||
             (*(int *)(puVar11 + 3) != *(int *)((longlong)puVar11 + 0x1c))) break;
          if ((code *)puVar11[7] == (code *)0x0) {
            KeSetEvent(puVar11[6],0,0);
          }
          else {
            (*(code *)puVar11[7])(puVar11[5]);
          }
          LOCK();
          *(int *)(this + 0xe8) = *(int *)(this + 0xe8) + -1;
          UNLOCK();
          if (puVar11 != *(undefined8 **)this_00) break;
          do {
            p_Var7 = FifoQueue::Pop(this_00);
            operator_delete(p_Var7);
            puVar11 = *(undefined8 **)this_00;
            if (puVar11 == (undefined8 *)0x0) goto LAB_1400153fa;
          } while ((*(int *)(puVar11 + 3) == *(int *)(puVar11 + 4)) &&
                  (*(int *)(puVar11 + 3) == *(int *)((longlong)puVar11 + 0x1c)));
        }
      }
LAB_1400153fa:
    } while (this[0xca] != this[200]);
  }
  HVar2 = *(HdaController *)(*(longlong *)(this + 0x58) + 0x58);
  while (this[0xc9] != HVar2) {
    HVar5 = (HdaController)((char)this[0xc9] + 1);
    this[0xc9] = HVar5;
    uVar3 = *(uint *)(*(longlong *)(this + 0xc0) + 4 + (ulonglong)(byte)HVar5 * 8);
    if ((uVar3 & 0x10) != 0) {
      bVar6 = (byte)uVar3 & 0xf;
      if (bVar6 < 0xf) {
        lVar10 = (ulonglong)
                 (*(uint *)(*(longlong *)(this + 0xc0) + (ulonglong)(byte)HVar5 * 8) >> 0x1a) +
                 (ulonglong)bVar6 * 0x40;
        lVar8 = lVar10 * 0x20;
        if (this[lVar8 + 0x1be8] != (HdaController)0x0) {
          LOCK();
          *(int *)(this + 0xe8) = *(int *)(this + 0xe8) + 1;
          UNLOCK();
          (**(code **)(this + lVar8 + 0x1bd8))
                    (*(undefined8 *)(*(longlong *)(this + 0xc0) + (ulonglong)(byte)this[0xc9] * 8),
                     *(undefined8 *)(this + (lVar10 + 0xdf) * 0x20));
          LOCK();
          *(int *)(this + 0xe8) = *(int *)(this + 0xe8) + -1;
          UNLOCK();
        }
      }
    }
  }
  KeReleaseSpinLock(this + 0xf0,uVar4);
  return;
}



===== MapActiveStreamId @ 1400154ec =====

/* public: long __cdecl HdaController::MapActiveStreamId(unsigned char,unsigned char) __ptr64 */

long __thiscall HdaController::MapActiveStreamId(HdaController *this,uchar param_1,uchar param_2)

{
  longlong *plVar1;
  bool bVar2;
  undefined8 *puVar3;
  int iVar4;
  ushort uVar5;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  
  iVar4 = -0x3fffff45;
  puVar3 = (undefined8 *)FirstEntrySList(this + 0x9660);
  do {
    bVar2 = true;
    if (puVar3 == (undefined8 *)0x0) {
LAB_140015577:
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar2 = false;
        }
        if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_ddd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,
                     in_stack_ffffffffffffffc0,0xcf,in_stack_ffffffffffffffd0,param_2,param_1,
                     (char)iVar4);
        }
      }
      return iVar4;
    }
    plVar1 = (longlong *)puVar3[2];
    iVar4 = -0x3ffffff2;
    if ((*(ushort *)(plVar1 + 1) >> (param_1 & 0x1f) & 1) != 0) {
      iVar4 = 0;
      if ((param_2 < 0x10) &&
         (uVar5 = 1 << (param_2 & 0x1f), (uVar5 & *(ushort *)(*plVar1 + 8)) == 0)) {
        *(ushort *)(*plVar1 + 8) = *(ushort *)(*plVar1 + 8) | uVar5;
      }
      else {
        iVar4 = -0x3ffffff3;
      }
      goto LAB_140015577;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== ReportCodecsPresent @ 1400155f8 =====

/* public: long __cdecl HdaLinkInstance::ReportCodecsPresent(unsigned short) __ptr64 */

long __thiscall HdaLinkInstance::ReportCodecsPresent(HdaLinkInstance *this,ushort param_1)

{
  char cVar1;
  uint uVar2;
  undefined8 in_stack_ffffffffffffffb8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,1,0xd9,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)param_1);
  }
  *(ushort *)(this + 8) = *(ushort *)(this + 8) | *(ushort *)(*(longlong *)this + 0xc) & param_1;
  uVar2 = *(uint *)(*(longlong *)this + 4) & 0x800000;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,1,0xda,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)*(undefined2 *)(this + 8));
  }
  if (*(short *)(this + 8) == 0) {
    if (uVar2 != 0) {
      TurnOff(this);
    }
  }
  else if (uVar2 == 0) {
    TurnOn(this);
  }
  return 0;
}



===== SetupDmaEngineWithBdl @ 140015740 =====

/* public: long __cdecl HdaController::SetupDmaEngineWithBdl(long,unsigned long,unsigned long,void
   (__cdecl*)(void * __ptr64,unsigned long),void * __ptr64,unsigned char * __ptr64,unsigned long *
   __ptr64) __ptr64 */

long __thiscall
HdaController::SetupDmaEngineWithBdl
          (HdaController *this,long param_1,ulong param_2,ulong param_3,
          _func_void_void_ptr_ulong *param_4,void *param_5,uchar *param_6,ulong *param_7)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  long lVar4;
  longlong lVar5;
  undefined8 in_stack_ffffffffffffff88;
  undefined2 uVar6;
  
  cVar2 = KeGetCurrentIrql();
  if (cVar2 != '\0') {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x9d,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar4 = -0x3fffffff;
    goto LAB_140015bac;
  }
  if (0x1d < (uint)param_1) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0x9e,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    lVar4 = -0x3ffffff8;
    goto LAB_140015bac;
  }
  if ((param_7 == (ulong *)0x0) || (param_6 == (uchar *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0 ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar6 = 0x9f;
LAB_140015ab7:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,uVar6,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
  }
  else {
    if ((param_3 != 0) && (param_2 != 0)) {
      lVar5 = (longlong)param_1 * 0xd8;
      uVar3 = KeAcquireSpinLockRaiseToDpc(this + lVar5 + 0x200);
      if (this[lVar5 + 0x20c] == (HdaController)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\x01';
        }
        if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0xa1,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
        }
        lVar4 = -0x3ffffff8;
      }
      else {
        if ((this[lVar5 + 0x26c] == (HdaController)0x0) ||
           (this[lVar5 + 0x20e] == (HdaController)0x0)) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0 ||
              ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if ((bVar1 != false) ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar6 = 0xa2;
LAB_140015a1e:
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,
                       uVar6,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
        }
        else {
          if (*(int *)(this + lVar5 + 0x268) == 0) {
            *(ulonglong *)(this + lVar5 + 0x238) = (ulonglong)param_2;
            this[lVar5 + 0x26e] = SUB41(param_3,0);
            *(_func_void_void_ptr_ulong **)(this + lVar5 + 0x298) = param_4;
            *(void **)(this + lVar5 + 0x2a0) = param_5;
            this[lVar5 + 0x26d] = (HdaController)0x1;
            ProgramDmaEngine(this,param_1);
            *param_6 = (uchar)this[lVar5 + 0x215];
            lVar4 = 0;
            *param_7 = *(ushort *)((longlong)param_1 * 0x20 + 0x90 + *(longlong *)(this + 0x58)) + 1
            ;
            goto LAB_140015a38;
          }
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar6 = 0xa3;
            goto LAB_140015a1e;
          }
        }
        lVar4 = -0x3ffffff0;
      }
LAB_140015a38:
      KeReleaseSpinLock(this + lVar5 + 0x200,uVar3);
      if (-1 < lVar4) {
        return lVar4;
      }
      goto LAB_140015bac;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar6 = 0xa0;
      goto LAB_140015ab7;
    }
  }
  lVar4 = -0x3ffffff3;
LAB_140015bac:
  cVar2 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar2 = '\0';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff88,0xe,0xa4,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar4);
  }
  return lVar4;
}



===== TimeoutDpc @ 140015c30 =====

/* private: static void __cdecl HdaController::TimeoutDpc(struct _KDPC * __ptr64,void * __ptr64,void
   * __ptr64,void * __ptr64) */

void __cdecl HdaController::TimeoutDpc(_KDPC *param_1,void *param_2,void *param_3,void *param_4)

{
  char cVar1;
  bool bVar2;
  undefined4 in_stack_ffffffffffffffd8;
  undefined4 in_stack_ffffffffffffffdc;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffffdc,in_stack_ffffffffffffffd8),4,10,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
  }
  HDABusWmiLogETW(1,4,'\x03','\x03',1,0,0,0);
  LOCK();
  bVar2 = *(int *)((longlong)param_2 + 0x949c) == 0;
  if (bVar2) {
    *(int *)((longlong)param_2 + 0x949c) = 0;
  }
  UNLOCK();
  if ((!bVar2) || (bVar2 = ProcessCodecResponses(param_2), !bVar2)) {
    CancelCorbEntries(param_2);
  }
  ProcessCodecTransferList(param_2);
  return;
}



===== TurnOff @ 140015d08 =====

/* public: long __cdecl HdaLinkInstance::TurnOff(void) __ptr64 */

long __thiscall HdaLinkInstance::TurnOff(HdaLinkInstance *this)

{
  char cVar1;
  long lVar2;
  ushort uVar3;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0xd7,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
  }
  if ((*(uint *)(*(longlong *)this + 4) >> 0x17 & 1) != 0) {
    uVar3 = 0;
    *(uint *)(*(longlong *)this + 4) = *(uint *)(*(longlong *)this + 4) & 0xfffeffff;
    do {
      if ((*(uint *)(*(longlong *)this + 4) >> 0x17 & 1) == 0) {
        return 0;
      }
      KeStallExecutionProcessor(1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 100);
    lVar2 = -0x3fffff4b;
  }
  return lVar2;
}



===== TurnOn @ 140015df0 =====

/* public: long __cdecl HdaLinkInstance::TurnOn(void) __ptr64 */

long __thiscall HdaLinkInstance::TurnOn(HdaLinkInstance *this)

{
  char cVar1;
  long lVar2;
  ushort uVar3;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0xd8,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
  }
  if ((*(uint *)(*(longlong *)this + 4) >> 0x17 & 1) == 0) {
    uVar3 = 0;
    *(uint *)(*(longlong *)this + 4) = *(uint *)(*(longlong *)this + 4) | 0x10000;
    do {
      if ((*(uint *)(*(longlong *)this + 4) >> 0x17 & 1) != 0) {
        return 0;
      }
      KeStallExecutionProcessor(1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 100);
    lVar2 = -0x3fffff4b;
  }
  return lVar2;
}



===== UnmapActiveStreamId @ 140015ed8 =====

/* public: long __cdecl HdaController::UnmapActiveStreamId(unsigned char,unsigned char) __ptr64 */

long __thiscall HdaController::UnmapActiveStreamId(HdaController *this,uchar param_1,uchar param_2)

{
  longlong *plVar1;
  bool bVar2;
  undefined8 *puVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  
  iVar5 = -0x3fffff45;
  puVar3 = (undefined8 *)FirstEntrySList(this + 0x9660);
  bVar2 = true;
  do {
    if (puVar3 == (undefined8 *)0x0) {
LAB_140015f7d:
      if (iVar5 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar2 = false;
        }
        if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_ddd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,
                     in_stack_ffffffffffffffc0,0xd0,in_stack_ffffffffffffffd0,param_2,param_1,
                     (char)iVar5);
        }
      }
      return iVar5;
    }
    iVar5 = -0x3ffffff2;
    plVar1 = (longlong *)puVar3[2];
    uVar6 = 1 << (param_1 & 0x1f);
    if (((uVar6 & *(ushort *)(plVar1 + 1)) != 0) ||
       ((uVar6 & *(ushort *)(*(longlong *)puVar3[2] + 0xc)) != 0)) {
      iVar5 = 0;
      if (param_2 < 0x10) {
        uVar4 = 1 << (param_2 & 0x1f);
        if ((uVar4 & *(ushort *)(*plVar1 + 8)) != 0) {
          *(ushort *)(*plVar1 + 8) = ~uVar4 & *(ushort *)(*plVar1 + 8);
        }
      }
      else {
        iVar5 = -0x3ffffff3;
      }
      goto LAB_140015f7d;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== Feature_2795140408__private_IsEnabledDeviceUsageNoInline @ 140016000 =====

ulonglong Feature_2795140408__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2795140408__private_featureState;
  if ((Feature_2795140408__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2795140408__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2795140408__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2795140408__private_IsEnabledFallback @ 140016038 =====

void Feature_2795140408__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2795140408__private_descriptor);
  return;
}



===== Feature_4246965561__private_IsEnabledDeviceUsageNoInline @ 140016054 =====

ulonglong Feature_4246965561__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_4246965561__private_featureState;
  if ((Feature_4246965561__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4246965561__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4246965561__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4246965561__private_IsEnabledFallback @ 14001608c =====

void Feature_4246965561__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4246965561__private_descriptor);
  return;
}



===== Feature_Audio_Drivers_HdAudBus_DmaAdapter__private_ReportDeviceUsage @ 1400160a8 =====

void Feature_Audio_Drivers_HdAudBus_DmaAdapter__private_ReportDeviceUsage(void)

{
  uint uVar1;
  ulonglong local_res8;
  
  if ((Feature_Audio_Drivers_HdAudBus_DmaAdapter__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Audio_Drivers_HdAudBus_DmaAdapter__private_featureState | 1;
    local_res8 = (ulonglong)uVar1;
    wil_details_FeatureReporting_ReportUsageToService(0x14001cdb8,local_res8,3);
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
              (uVar1,3,&wil_details_featureDescriptors_a);
  }
  return;
}



===== Feature_Servicing_HdAudBusResetTimeout__private_IsEnabledDeviceUsageNoInline @ 14001610c =====

ulonglong Feature_Servicing_HdAudBusResetTimeout__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_HdAudBusResetTimeout__private_featureState;
  if ((Feature_Servicing_HdAudBusResetTimeout__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_HdAudBusResetTimeout__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_HdAudBusResetTimeout__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_HdAudBusResetTimeout__private_IsEnabledFallback @ 140016144 =====

void Feature_Servicing_HdAudBusResetTimeout__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_HdAudBusResetTimeout__private_descriptor);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_DSDi @ 140016160 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DSDi(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000048;
  wchar_t *in_stack_00000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  lVar4 = -1;
  lVar3 = 10;
  if (param_2 != '\0') {
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
              (param_1,0x2b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xa9,
               &uStack0000000000000048,4,pwVar2,lVar1,&uStack0000000000000058,4,
               &uStack0000000000000060,8,0);
  }
  if (param_3 != '\0') {
    if (in_stack_00000050 != (wchar_t *)0x0) {
      do {
        lVar4 = lVar4 + 1;
      } while (in_stack_00000050[lVar4] != L'\0');
      lVar3 = lVar4 * 2 + 2;
    }
    if (in_stack_00000050 == (wchar_t *)0x0) {
      in_stack_00000050 = L"NULL";
    }
    WppAutoLogTrace(param_4,0,0xe,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xa9,
                    &uStack0000000000000048,4,in_stack_00000050,lVar3,&uStack0000000000000058,4,
                    &uStack0000000000000060,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_ddd @ 140016308 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_ddd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,param_7,&param_9,4,
               &param_10,4,&param_11,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,0xe,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,param_7,&param_9,
                    4,&param_10,4,&param_11,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_dddd @ 1400163f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_dddd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000182;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x41,
               &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
               local_18,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,1,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x41,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    local_18,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qPd @ 140016504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qPd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xeb,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,0xe,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xeb,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qdd @ 1400165f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qdd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x8a,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,0xe,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x8a,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qdq @ 1400166ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qdq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,param_7,&param_9,8,
               &param_10,4,&param_11,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,0xe,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,param_7,&param_9,
                    8,&param_10,4,&param_11,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qi @ 1400167e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qi(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x19,
               &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,0xe,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x19,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qid @ 1400168a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qid(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x17,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,0xe,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0x17,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14001699c =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140016a80 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140016b70 =====

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
LAB_140016ccc:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140016cbc:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140016ccc;
      if (uVar5 == 5) goto LAB_140016cbc;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140016cf4 =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140016d78 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140016e68 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140016f78 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140016fdc =====

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



===== wil_details_IsEnabledFallback @ 14001713c =====

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



===== wil_details_MapReportingKind @ 1400171d0 =====

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



===== ChangeBandwidthAllocation @ 140017270 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl HdaBusInterface::ChangeBandwidthAllocation(void * __ptr64,void *
   __ptr64,struct _HDAUDIO_STREAM_FORMAT * __ptr64,struct _HDAUDIO_CONVERTER_FORMAT * __ptr64) */

long __cdecl
HdaBusInterface::ChangeBandwidthAllocation
          (void *param_1,void *param_2,_HDAUDIO_STREAM_FORMAT *param_3,
          _HDAUDIO_CONVERTER_FORMAT *param_4)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  undefined1 auStackY_b8 [32];
  _HDAUDIO_STREAM_FORMAT *in_stack_ffffffffffffff68;
  long local_68 [2];
  HdaController *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68[0] = -1;
  local_60 = (HdaController *)0x0;
  bVar1 = true;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)&local_60);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar2 = ConvertHandleToLong(param_1,param_2,local_68);
      if (uVar2 == '\0') {
        iVar3 = -0x3ffffff8;
      }
      else {
        local_48 = 0;
        uStack_50 = 0;
        local_58 = 0x18;
        (**(code **)(WdfFunctions_01025 + 0x6f0))
                  (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x880),&local_58);
        this = local_60;
        in_stack_ffffffffffffff68 =
             (_HDAUDIO_STREAM_FORMAT *)
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffff68 >> 0x20),0x20);
        iVar3 = IoAcquireRemoveLockEx(local_60 + 8,param_1,"",1);
        if (iVar3 == 0) {
          iVar3 = HdaController::ChangeBandwidthAllocation
                            (this,*(WDFDEVICE__ **)((longlong)param_1 + 0x880),local_68[0],
                             local_48._2_1_,param_3,param_4);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
          in_stack_ffffffffffffff68 = param_3;
        }
        if (-1 < iVar3) goto LAB_14001740d;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,4,0x12,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14001740d:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)&local_60);
  return iVar3;
}



===== InterfaceDereference @ 140017450 =====

/* public: static void __cdecl HdaBusInterface::InterfaceDereference(void * __ptr64) */

void __cdecl HdaBusInterface::InterfaceDereference(void *param_1)

{
  int iVar1;
  uint in_EDX;
  
  LOCK();
  iVar1 = *(int *)param_1;
  *(int *)param_1 = *(int *)param_1 + -1;
  UNLOCK();
  if ((iVar1 == 1) && (param_1 != (void *)0x0)) {
    _scalar_deleting_destructor_(param_1,in_EDX);
  }
  return;
}



===== InvalidateHandles @ 140017478 =====

/* public: void __cdecl HdaBusInterface::InvalidateHandles(void) __ptr64 */

void __thiscall HdaBusInterface::InvalidateHandles(HdaBusInterface *this)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(this + 8);
  memset(this + 0x10,0,0xf0);
  KeReleaseSpinLock(this + 8,uVar1);
  return;
}



===== RegisterNotificationCallback @ 1400174e0 =====

/* public: static long __cdecl HdaBusInterface3::RegisterNotificationCallback(void * __ptr64,void *
   __ptr64,struct _DEVICE_OBJECT * __ptr64,void (__cdecl*)(void * __ptr64,union _LARGE_INTEGER),void
   * __ptr64) */

long __cdecl
HdaBusInterface3::RegisterNotificationCallback
          (void *param_1,void *param_2,_DEVICE_OBJECT *param_3,
          _func_void_void_ptr__LARGE_INTEGER *param_4,void *param_5)

{
  bool bVar1;
  HdaController *this;
  uchar uVar2;
  int iVar3;
  long local_res8 [2];
  _func_void_void_ptr__LARGE_INTEGER *in_stack_ffffffffffffff98;
  HdaController *local_38 [2];
  
  local_res8[0] = -1;
  bVar1 = true;
  local_38[0] = (HdaController *)0x0;
  if (param_1 == (void *)0x0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar2 = HdaBusInterface::GetController(param_1,(SmartPtrT<HdaController*___ptr64> *)local_38);
    if (uVar2 == '\0') {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar2 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res8);
      this = local_38[0];
      if (uVar2 == '\0') {
        iVar3 = -0x3ffffff8;
      }
      else {
        in_stack_ffffffffffffff98 =
             (_func_void_void_ptr__LARGE_INTEGER *)
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffff98 >> 0x20),0x20);
        iVar3 = IoAcquireRemoveLockEx(local_38[0] + 8,param_1,"");
        if (iVar3 == 0) {
          iVar3 = HdaController::RegisterNotificationHandler
                            (this,param_3,local_res8[0],(_KEVENT *)0x0,param_4,param_5);
          IoReleaseRemoveLockEx(this + 8,param_1,0x20);
          in_stack_ffffffffffffff98 = param_4;
        }
        if (-1 < iVar3) goto LAB_14001763d;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,0x20,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)iVar3);
  }
LAB_14001763d:
  SmartPtrT<HdaController*___ptr64>::Remove((SmartPtrT<HdaController*___ptr64> *)local_38);
  return iVar3;
}



===== RetrieveAudioBufferInfo @ 140017670 =====

/* protected: long __cdecl HdaBusInterface::RetrieveAudioBufferInfo(void * __ptr64,void * __ptr64 *
   __ptr64,unsigned __int64 * __ptr64,class DmaAdapterTracker * __ptr64 * __ptr64,void * __ptr64 *
   __ptr64,union _LARGE_INTEGER * __ptr64,enum _HdaBufferType * __ptr64) __ptr64 */

long __thiscall
HdaBusInterface::RetrieveAudioBufferInfo
          (HdaBusInterface *this,void *param_1,void **param_2,__uint64 *param_3,
          DmaAdapterTracker **param_4,void **param_5,_LARGE_INTEGER *param_6,_HdaBufferType *param_7
          )

{
  DmaAdapterTracker *pDVar1;
  undefined1 uVar2;
  HdaBusInterface *_Dst;
  char cVar3;
  long lVar4;
  longlong lVar5;
  undefined8 in_stack_ffffffffffffffb8;
  
  *param_3 = 0;
  lVar4 = -0x3fffffff;
  *param_7 = 3;
  uVar2 = KeAcquireSpinLockRaiseToDpc(this + 8);
  cVar3 = '\x01';
  if (param_1 != (void *)0x0) {
    lVar5 = 0;
    _Dst = this + 0x100;
    do {
      if ((*(void **)_Dst == param_1) &&
         ((*param_2 == (void *)0x0 || (*(void **)(_Dst + 8) == *param_2)))) {
        pDVar1 = *(DmaAdapterTracker **)(_Dst + 0x10);
        *param_2 = *(void **)(_Dst + 8);
        *param_4 = pDVar1;
        *param_5 = *(void **)(_Dst + 0x18);
        *(longlong *)param_6 = *(longlong *)(_Dst + 0x20);
        *param_3 = *(__uint64 *)(_Dst + 0x28);
        *param_7 = *(_HdaBufferType *)(_Dst + 0x30);
        memset(_Dst,0,0x40);
        lVar4 = 0;
        goto LAB_140017772;
      }
      lVar5 = lVar5 + 1;
      _Dst = _Dst + 0x40;
    } while (lVar5 < 0x1e);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar3 = '\0';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,0xc,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)param_1,(char)*param_2);
  }
LAB_140017772:
  KeReleaseSpinLock(this + 8,uVar2);
  return lVar4;
}



===== StoreAudioBufferInfo @ 140017800 =====

/* protected: void __cdecl HdaBusInterface::StoreAudioBufferInfo(void * __ptr64,void * __ptr64,class
   DmaAdapterTracker * __ptr64,void * __ptr64,union _LARGE_INTEGER,unsigned __int64,enum
   _HdaBufferType) __ptr64 */

void __thiscall
HdaBusInterface::StoreAudioBufferInfo
          (HdaBusInterface *this,longlong param_1,longlong param_2,longlong param_3,longlong param_4
          ,longlong param_6,longlong param_7,undefined4 param_8)

{
  ulonglong uVar1;
  undefined1 uVar2;
  int iVar3;
  char cVar4;
  HdaBusInterface *pHVar5;
  HdaBusInterface *pHVar6;
  char cVar7;
  HdaBusInterface *pHVar8;
  longlong lVar9;
  undefined8 in_stack_ffffffffffffff98;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  iVar3 = 0;
  pHVar5 = this + 0x100;
  lVar9 = 0;
  cVar7 = '\x01';
  pHVar8 = pHVar5;
  do {
    if (*(longlong *)pHVar8 == 0) {
      pHVar8 = this + ((longlong)iVar3 + 4) * 0x40;
      if (pHVar8 != (HdaBusInterface *)0x0) goto LAB_140017999;
      break;
    }
    iVar3 = iVar3 + 1;
    lVar9 = lVar9 + 1;
    pHVar8 = pHVar8 + 0x40;
  } while (lVar9 < 0x1e);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,4,10,
               &WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,(char)*(undefined8 *)(this + 0x880),
               (char)this);
  }
  pHVar8 = this + 0x178;
  pHVar6 = this + 0x140;
  lVar9 = 0x1d;
  do {
    uVar1 = *(ulonglong *)pHVar8;
    pHVar8 = pHVar8 + 0x40;
    if (uVar1 < *(ulonglong *)(pHVar5 + 0x38)) {
      pHVar5 = pHVar6;
    }
    pHVar6 = pHVar6 + 0x40;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
    cVar7 = '\0';
  }
  pHVar8 = pHVar5;
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qPdi
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
LAB_140017999:
  *(longlong *)(pHVar8 + 0x18) = param_4;
  *(longlong *)(pHVar8 + 0x20) = param_6;
  *(longlong *)(pHVar8 + 0x28) = param_7;
  *(undefined4 *)(pHVar8 + 0x30) = param_8;
  *(longlong *)pHVar8 = param_1;
  *(longlong *)(pHVar8 + 8) = param_2;
  *(longlong *)(pHVar8 + 0x10) = param_3;
  lVar9 = KeQueryPerformanceCounter(0);
  *(longlong *)(pHVar8 + 0x38) = lVar9;
  KeReleaseSpinLock(this + 8,uVar2);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qPdi @ 140017a20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qPdi(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,0xb,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,0,4,&WPP_eb50ea50693a340a42fabf3083ba6674_Traceguids,0xb,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                    &uStack0000000000000060,8,0);
  }
  return;
}



===== AllocateContiguousDmaBuffer @ 140017b30 =====

/* public: static long __cdecl HdaBusInterfaceBdl::AllocateContiguousDmaBuffer(void * __ptr64,void *
   __ptr64,unsigned long,void * __ptr64 * __ptr64,struct _HDAUDIO_BUFFER_DESCRIPTOR * __ptr64 *
   __ptr64) */

long __cdecl
HdaBusInterfaceBdl::AllocateContiguousDmaBuffer
          (void *param_1,void *param_2,ulong param_3,void **param_4,
          _HDAUDIO_BUFFER_DESCRIPTOR **param_5)

{
  uchar uVar1;
  long lVar2;
  char cVar3;
  long local_res8 [2];
  _HDAUDIO_BUFFER_DESCRIPTOR **in_stack_ffffffffffffffc8;
  
  local_res8[0] = 0;
  if (param_1 == (void *)0x0) {
    lVar2 = -0x3ffffff3;
  }
  else if ((*(longlong *)((longlong)param_1 + 0x888) == 0) ||
          (*(longlong *)(*(longlong *)((longlong)param_1 + 0x888) + 0x10) == 0)) {
    lVar2 = -0x3ffffff0;
  }
  else {
    uVar1 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res8);
    if (uVar1 == '\0') {
      lVar2 = -0x3ffffff8;
    }
    else {
      lVar2 = HdaController::AllocateContiguousDmaBuffer
                        (*(HdaController **)(*(longlong *)((longlong)param_1 + 0x888) + 0x10),
                         local_res8[0],(ulonglong)param_3,param_4,param_5);
      in_stack_ffffffffffffffc8 = param_5;
      if (-1 < lVar2) {
        return lVar2;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xb,
               &WPP_ad18b78388e837ba55bb3bad8082b8d5_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== FreeContiguousDmaBuffer @ 140017c40 =====

/* public: static long __cdecl HdaBusInterfaceBdl::FreeContiguousDmaBuffer(void * __ptr64,void *
   __ptr64) */

long __cdecl HdaBusInterfaceBdl::FreeContiguousDmaBuffer(void *param_1,void *param_2)

{
  uchar uVar1;
  long lVar2;
  char cVar3;
  long local_res8 [8];
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res8[0] = 0;
  if (param_1 == (void *)0x0) {
    lVar2 = -0x3ffffff3;
  }
  else if ((*(longlong *)((longlong)param_1 + 0x888) == 0) ||
          (*(longlong *)(*(longlong *)((longlong)param_1 + 0x888) + 0x10) == 0)) {
    lVar2 = -0x3ffffff0;
  }
  else {
    uVar1 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res8);
    if (uVar1 == '\0') {
      lVar2 = -0x3ffffff8;
    }
    else {
      lVar2 = HdaController::FreeContiguousDmaBuffer
                        (*(HdaController **)(*(longlong *)((longlong)param_1 + 0x888) + 0x10),
                         local_res8[0]);
      if (-1 < lVar2) {
        return lVar2;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xc,
               &WPP_ad18b78388e837ba55bb3bad8082b8d5_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== SetupDmaEngineWithBdl @ 140017d20 =====

/* public: static long __cdecl HdaBusInterfaceBdl::SetupDmaEngineWithBdl(void * __ptr64,void *
   __ptr64,unsigned long,unsigned long,void (__cdecl*)(void * __ptr64,unsigned long),void *
   __ptr64,unsigned char * __ptr64,unsigned long * __ptr64) */

long __cdecl
HdaBusInterfaceBdl::SetupDmaEngineWithBdl
          (void *param_1,void *param_2,ulong param_3,ulong param_4,
          _func_void_void_ptr_ulong *param_5,void *param_6,uchar *param_7,ulong *param_8)

{
  uchar uVar1;
  long lVar2;
  char cVar3;
  long local_res8 [2];
  _func_void_void_ptr_ulong *in_stack_ffffffffffffffc8;
  
  local_res8[0] = 0;
  if (param_1 == (void *)0x0) {
    lVar2 = -0x3ffffff3;
  }
  else if ((*(longlong *)((longlong)param_1 + 0x888) == 0) ||
          (*(longlong *)(*(longlong *)((longlong)param_1 + 0x888) + 0x10) == 0)) {
    lVar2 = -0x3ffffff0;
  }
  else {
    uVar1 = HdaBusInterface::ConvertHandleToLong(param_1,param_2,local_res8);
    if (uVar1 == '\0') {
      lVar2 = -0x3ffffff8;
    }
    else {
      lVar2 = HdaController::SetupDmaEngineWithBdl
                        (*(HdaController **)(*(longlong *)((longlong)param_1 + 0x888) + 0x10),
                         local_res8[0],param_3,param_4,param_5,param_6,param_7,param_8);
      in_stack_ffffffffffffffc8 = param_5;
      if (-1 < lVar2) {
        return lVar2;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,10,
               &WPP_ad18b78388e837ba55bb3bad8082b8d5_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== FxStubDriverUnloadCommon @ 140017e58 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_14001d3b0,&DAT_14001d140,WdfDriverGlobals);
  return;
}



===== entry @ 140017e90 =====

void entry(_WDF_BIND_INFO *param_1,ushort *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140017ec4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(_WDF_BIND_INFO *param_1,ushort *param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  _WDF_BIND_INFO *p_Var4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    uVar3 = DriverEntry(0,param_2);
  }
  else {
    _DAT_14001d3b0 = 0x2080000;
    _DAT_14001d3b8 = &DAT_14001d440;
    RtlCopyUnicodeString(&DAT_14001d3b0);
    p_Var4 = param_1;
    uVar3 = WdfVersionBind(param_1,&DAT_14001d3b0,&DAT_14001d140,&WdfDriverGlobals);
    if (-1 < (int)uVar3) {
      uVar1 = FxStubBindClasses(p_Var4);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar3 = DriverEntry((longlong)param_1,param_2);
        uVar1 = (uint)uVar3;
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14001d648 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar3 & 0xffffffff,
                   &DAT_14001d3b0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001d2d8 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&DAT_14001d140,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
      uVar3 = (ulonglong)uVar1;
    }
  }
  return uVar3;
}



===== FxStubDriverUnload @ 140018050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14001d648 != (code *)0x0) && (DAT_14001d648 != FxStubDriverUnload)) {
    (*DAT_14001d648)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140018084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400180a9) */
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
    if ((uint *)0x14001d2cf < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_14001d2d8 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&DAT_14001d140,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&DAT_14001d140,WdfDriverGlobals,puVar2);
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



===== FxStubUnbindClasses @ 1400181e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  void **ppvVar2;
  uint *puVar3;
  
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001d2d8 != &__KMDF_CLASS_BIND_START) {
    puVar3 = (uint *)(PTR___KMDF_CLASS_BIND_START_14001d2d8 + 0x50);
    if (*(int *)PTR___KMDF_CLASS_BIND_START_14001d2d8 == 0x78) {
      puVar3 = (uint *)(PTR___KMDF_CLASS_BIND_START_14001d2d8 + 0x78);
    }
    while (puVar1 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar2,(longlong *)puVar3),
          puVar1 != (uint *)0x0) {
      if (puVar3 <= puVar1) {
        return;
      }
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&DAT_14001d140,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))
                  (WdfVersionUnbindClass_exref,&DAT_14001d140,WdfDriverGlobals,puVar1);
      }
      ppvVar2 = (void **)((longlong)puVar1 + (ulonglong)*puVar1);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== FxGetNextClassBindInfo @ 1400182a8 =====

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
  if ((param_1 + 10 <= param_2) && ((int)*param_1 == 0x50)) {
    return param_1;
  }
  if (param_2 < param_1 + 0xf) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x78) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== FxStubInitTypes @ 140018304 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140018321) */
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
    if ((void **)0x14001d2ef < ppvVar2) break;
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



===== _guard_check_icall @ 1400183e0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400183f8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001841c =====

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



===== __cpu_features_init @ 140018490 =====

/* WARNING: Removing unreachable block (ram,0x0001400184fa) */
/* WARNING: Removing unreachable block (ram,0x0001400184a9) */
/* WARNING: Removing unreachable block (ram,0x00014001849a) */

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



===== __security_check_cookie @ 140018560 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400185a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400185d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400185d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140018600 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140018680 =====

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



===== memset @ 140018980 =====

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



===== __memset_repmovs @ 140018ac0 =====

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



===== __memset_query @ 140018b40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140018bc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140018d00 =====

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



===== __memset_spec_plain @ 140018d80 =====

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



===== QueryForD3ColdInterface @ 140021008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl QueryForD3ColdInterface(struct WDFDEVICE__ * __ptr64) */

long __cdecl QueryForD3ColdInterface(WDFDEVICE__ *param_1)

{
  void *_Dst;
  int iVar1;
  longlong lVar2;
  char cVar3;
  undefined2 uVar4;
  undefined6 in_stack_ffffffffffffffda;
  undefined4 in_stack_ffffffffffffffe0;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((uint)in_stack_ffffffffffffffe0 >> 0x10);
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  _Dst = (void *)(lVar2 + 0xd0);
  memset(_Dst,0,0x48);
  uVar4 = 0x48;
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x418))
                    (WdfDriverGlobals,param_1,&GUID_D3COLD_SUPPORT_INTERFACE,_Dst,0x48,
                     CONCAT22(uVar5,1),0);
  if (iVar1 < 0) {
    memset(_Dst,0,0x48);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT62(in_stack_ffffffffffffffda,uVar4),1,0x18,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
  }
  return iVar1;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140021134 =====

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
  local_28 = *(undefined4 *)(PTR_DAT_14001d0e0 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14001d0e0 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14001d0e0 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14001d0e0 + -4);
  if (DAT_14001d0f8 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_14001d100 = 0;
  uRam000000014001d108 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x140021197;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_14001d0d8,&DAT_14001d0f8);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14001d0e0;
    *(undefined8 *)(puVar4 + -8) = 0x1400211be;
    EtwSetInformation(DAT_14001d0f8,2,PTR_DAT_14001d0e0,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1400211d2;
  return iVar3;
}



===== DupUnicodeString @ 1400211e0 =====

undefined8 DupUnicodeString(undefined8 param_1,ushort *param_2)

{
  undefined1 auVar1 [16];
  _UNICODE_STRING *p_Var2;
  __uint64 _Var3;
  void *_Dst;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (param_2 == (ushort *)0x0) {
    g_RegistryPath = (_UNICODE_STRING *)0x0;
  }
  else {
    p_Var2 = operator_new(0x10,1,0x30324448);
    if (p_Var2 == (_UNICODE_STRING *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      *(ushort *)p_Var2 = *param_2;
      *(ushort *)(p_Var2 + 2) = param_2[1];
      if (*(longlong *)(param_2 + 4) == 0) {
        *(undefined8 *)(p_Var2 + 8) = 0;
      }
      else {
        auVar1 = ZEXT816(2) * ZEXT216(param_2[1] >> 1);
        _Var3 = auVar1._0_8_;
        if (auVar1._8_8_ != 0) {
          _Var3 = 0xffffffffffffffff;
        }
        _Dst = operator_new(_Var3,1,0x31304448);
        *(void **)(p_Var2 + 8) = _Dst;
        if (_Dst == (void *)0x0) {
          operator_delete(p_Var2);
          return 0xc000009a;
        }
        memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)*param_2);
      }
      g_RegistryPath = p_Var2;
    }
  }
  return uVar4;
}



===== WppInitKm @ 1400212b0 =====

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



===== AddS0PowerRelation @ 14002138c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl AddS0PowerRelation(struct WDFDEVICE__ * __ptr64,struct _DEVICE_OBJECT * __ptr64) */

void __cdecl AddS0PowerRelation(WDFDEVICE__ *param_1,_DEVICE_OBJECT *param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffc8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar4 != '\0') || (bVar5)) {
    uVar1 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
    WPP_RECORDER_AND_TRACE_SF_qq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,2,0xbb,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar1,(char)param_2);
  }
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  ObfReferenceObject(param_2);
  LOCK();
  *(_DEVICE_OBJECT **)(lVar2 + 0x1c8) = param_2;
  UNLOCK();
  uVar3 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
  IoInvalidateDeviceRelations(uVar3,2);
  return;
}



===== DropD3ColdInterface @ 1400214d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl DropD3ColdInterface(struct _HDAudioDeviceExtension * __ptr64) */

void __cdecl DropD3ColdInterface(_HDAudioDeviceExtension *param_1)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffd8;
  
  if (*(code **)(param_1 + 0xe8) != (code *)0x0) {
    (**(code **)(param_1 + 0xe8))(*(undefined8 *)(param_1 + 0xd8));
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0x19,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
  }
  memset(param_1 + 0xd0,0,0x48);
  return;
}



===== GetGraphicsPowerInterfaceSettings @ 140021574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl GetGraphicsPowerInterfaceSettings(struct WDFDEVICE__ * __ptr64,struct
   _HDAudioDeviceExtension * __ptr64) */

void __cdecl
GetGraphicsPowerInterfaceSettings(WDFDEVICE__ *param_1,_HDAudioDeviceExtension *param_2)

{
  int iVar1;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined8 *local_b0;
  uint local_98 [2];
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  wchar_t *local_78;
  undefined8 local_70;
  wchar_t *local_68;
  wchar_t local_60 [12];
  wchar_t local_48 [24];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_88 = 0;
  local_90 = 0;
  local_98[0] = 0;
  builtin_wcsncpy(local_60,L"Settings",9);
  local_78 = local_60;
  local_48[0x14] = L's';
  local_48[0x15] = L'\0';
  local_68 = local_48;
  local_80 = 0x120010;
  builtin_wcsncpy(local_48,L"GfxShare",8);
  local_70 = 0x2c002a;
  *(undefined4 *)(param_2 + 0x1e0) = 0xffffffff;
  param_2[0xc2] = (_HDAudioDeviceExtension)0x0;
  local_b0 = &local_90;
  local_b8 = 0;
  builtin_wcsncpy(local_48 + 8,L"dCodecAddres",0xc);
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x180))(WdfDriverGlobals,param_1,2,0x20000);
  if (-1 < iVar1) {
    local_b0 = &local_88;
    local_b8 = 0;
    iVar1 = (**(code **)(WdfFunctions_01025 + 0x728))(WdfDriverGlobals,local_90,&local_80,0x20000);
    (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,local_90);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(WdfFunctions_01025 + 0x780))
                        (WdfDriverGlobals,local_88,&local_70,local_98);
      (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,local_88);
      if ((-1 < iVar1) && (local_98[0] < 0xf)) {
        param_2[0xc2] = (_HDAudioDeviceExtension)0x1;
        *(short *)(param_2 + 0x1e4) = 1 << ((byte)local_98[0] & 0x1f);
        *(uint *)(param_2 + 0x1e0) = local_98[0];
        param_2[0x1e6] = (_HDAudioDeviceExtension)0x1;
      }
    }
  }
  return;
}



===== HDAusBusEvtDriverContextCleanup @ 140021760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HDAusBusEvtDriverContextCleanup(struct WDFDRIVER__ * __ptr64) */

void __cdecl HDAusBusEvtDriverContextCleanup(WDFDRIVER__ *param_1)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01025 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar1);
  uVar1 = DAT_14001d0f8;
  DAT_14001d0f8 = 0;
  DAT_14001d0d8 = 0;
  EtwUnregister(uVar1);
  wil_UninitializeFeatureStaging();
  if (g_RegistryPath != (_UNICODE_STRING *)0x0) {
    if (*(void **)(g_RegistryPath + 8) != (void *)0x0) {
      operator_delete(*(void **)(g_RegistryPath + 8));
      *(undefined8 *)(g_RegistryPath + 8) = 0;
    }
    operator_delete(g_RegistryPath);
    g_RegistryPath = (_UNICODE_STRING *)0x0;
  }
  return;
}



===== HandleQdrForPowerRelations @ 1400217f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HandleQdrForPowerRelations(struct WDFDEVICE__ * __ptr64,struct _IRP * __ptr64) */

long __cdecl HandleQdrForPowerRelations(WDFDEVICE__ *param_1,_IRP *param_2)

{
  longlong lVar1;
  uint *_Src;
  undefined1 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint *_Dst;
  uint uVar6;
  ulonglong uVar7;
  long lVar8;
  char cVar9;
  char cVar10;
  bool bVar11;
  undefined8 in_stack_ffffffffffffff98;
  
  uVar7 = 0;
  _Dst = (uint *)0x0;
  lVar8 = 0;
  lVar4 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  lVar5 = 0;
  LOCK();
  lVar1 = *(longlong *)(lVar4 + 0x1c8);
  if (lVar1 == 0) {
    *(longlong *)(lVar4 + 0x1c8) = 0;
  }
  else {
    lVar5 = lVar1;
  }
  UNLOCK();
  if (lVar1 == 0) {
    cVar10 = '\x01';
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar9 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar10 = '\0';
    }
    if ((cVar9 != '\0') || (cVar10 != '\0')) {
      uVar2 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,cVar10,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,2,0xbe,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar2);
    }
    return 0;
  }
  _Src = *(uint **)(param_2 + 0x38);
  iVar3 = 1;
  if ((_Src == (uint *)0x0) || (iVar3 = *_Src + 1, iVar3 != 0)) {
    _Dst = (uint *)ExAllocatePool2(0x100,(ulonglong)(iVar3 - 1) * 8 + 0x10,0x44427a41);
    if (_Dst == (uint *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
         (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar10 = '\0';
      }
      bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar10 != '\0') || (bVar11)) {
        uVar2 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,bVar11,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,2,0xc0,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar2,0x9a);
      }
      lVar8 = -0x3fffff66;
      if (_Src == (uint *)0x0) goto LAB_140021b01;
      goto LAB_140021acb;
    }
    if ((_Src != (uint *)0x0) && (*_Src != 0)) {
      memmove(_Dst,_Src,(ulonglong)(*_Src - 1) * 8 + 0x10);
    }
    *(longlong *)(_Dst + (ulonglong)*_Dst * 2 + 2) = lVar5;
    ObfReferenceObject(lVar5);
    *_Dst = *_Dst + 1;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar10 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (cVar9 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar9 = '\0';
    }
    if ((cVar10 != '\0') || (cVar9 != '\0')) {
      uVar2 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,cVar9,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,2,0xc1,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar2,(char)lVar5);
    }
    if (_Src == (uint *)0x0) goto LAB_140021b01;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar10 != '\0') || (bVar11)) {
      uVar2 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,bVar11,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff98,2,0xbf,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar2,0x9a);
    }
LAB_140021acb:
    lVar8 = -0x3fffff66;
    if (*_Src != 0) {
      do {
        ObfDereferenceObject(*(undefined8 *)(_Src + uVar7 * 2 + 2));
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < *_Src);
    }
  }
  ExFreePoolWithTag(_Src,0);
LAB_140021b01:
  *(long *)(param_2 + 0x30) = lVar8;
  *(uint **)(param_2 + 0x38) = _Dst;
  return lVar8;
}



===== HdAudBusChildReleaseHardware @ 140021c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HdAudBusChildReleaseHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64) */

long __cdecl HdAudBusChildReleaseHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  HdaController *this;
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
  this = *(HdaController **)(lVar1 + 0x30);
  if (this != (HdaController *)0x0) {
    HdaController::StopDmaEngines(this,param_1);
  }
  if (*(HdaBusInterface **)(lVar1 + 8) != (HdaBusInterface *)0x0) {
    HdaBusInterface::InvalidateHandles(*(HdaBusInterface **)(lVar1 + 8));
  }
  if (*(HdaBusInterface **)(lVar1 + 0x10) != (HdaBusInterface *)0x0) {
    HdaBusInterface::InvalidateHandles(*(HdaBusInterface **)(lVar1 + 0x10));
  }
  if (*(HdaBusInterface **)(lVar1 + 0x18) != (HdaBusInterface *)0x0) {
    HdaBusInterface::InvalidateHandles(*(HdaBusInterface **)(lVar1 + 0x18));
  }
  if (this != (HdaController *)0x0) {
    LOCK();
    *(int *)this = *(int *)this + 1;
    UNLOCK();
    HdaSetChildController(param_1,(HdaController *)0x0);
    HdaController::CleanupDeviceReferences(this,param_1);
    HdaController::Release(this);
  }
  return 0;
}



===== HdAudBusCleanupChildDevice @ 140021cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusCleanupChildDevice(void * __ptr64) */

void __cdecl HdAudBusCleanupChildDevice(void *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
  uVar2 = (uint)param_1;
  if (*(HdaBusInterface **)(lVar1 + 8) != (HdaBusInterface *)0x0) {
    HdaBusInterface::_scalar_deleting_destructor_(*(HdaBusInterface **)(lVar1 + 8),uVar2);
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  if (*(HdaBusInterface **)(lVar1 + 0x20) != (HdaBusInterface *)0x0) {
    HdaBusInterface::_scalar_deleting_destructor_(*(HdaBusInterface **)(lVar1 + 0x20),uVar2);
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  if (*(HdaBusInterface **)(lVar1 + 0x10) != (HdaBusInterface *)0x0) {
    HdaBusInterface::_scalar_deleting_destructor_(*(HdaBusInterface **)(lVar1 + 0x10),uVar2);
    *(undefined8 *)(lVar1 + 0x10) = 0;
  }
  if (*(HdaBusInterface **)(lVar1 + 0x18) != (HdaBusInterface *)0x0) {
    HdaBusInterface::_scalar_deleting_destructor_(*(HdaBusInterface **)(lVar1 + 0x18),uVar2);
    *(undefined8 *)(lVar1 + 0x18) = 0;
  }
  return;
}



===== HdAudBusEvtDeviceCleanupCallback @ 140021d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusEvtDeviceCleanupCallback(void * __ptr64) */

void __cdecl HdAudBusEvtDeviceCleanupCallback(void *param_1)

{
  _HDAudioDeviceExtension *p_Var1;
  
  p_Var1 = (_HDAudioDeviceExtension *)
           (**(code **)(WdfFunctions_01025 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  if (*(longlong *)(p_Var1 + 0xb0) != 0) {
    PoUnregisterPowerSettingCallback();
    *(undefined8 *)(p_Var1 + 0xb0) = 0;
  }
  if (p_Var1[0xc0] != (_HDAudioDeviceExtension)0x0) {
    DropD3ColdInterface(p_Var1);
  }
  return;
}



===== HdAudBusRemoveDevice @ 140021df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HdAudBusRemoveDevice(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64)
    */

long __cdecl HdAudBusRemoveDevice(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  long lVar1;
  int iVar2;
  _HDAudioDeviceExtension *p_Var3;
  char cVar4;
  undefined8 local_res18 [2];
  undefined8 in_stack_ffffffffffffffa8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,1,0xa3,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  p_Var3 = (_HDAudioDeviceExtension *)
           (**(code **)(WdfFunctions_01025 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  lVar1 = HDAudUnregisterWmiProvider(param_1);
  if (-1 < lVar1) {
    StopHdAudioFlagsRegistryNotification(p_Var3);
    if (*(longlong *)(p_Var3 + 0x60) != 0) {
      iVar2 = IoUnregisterPlugPlayNotification();
      if (iVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar4 = '\0';
        }
        else {
          cVar4 = '\x01';
        }
        if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,0xa4,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
        }
      }
      *(undefined8 *)(p_Var3 + 0x60) = 0;
    }
    if (*(longlong *)(p_Var3 + 0x170) != 0) {
      iVar2 = IoUnregisterPlugPlayNotification();
      if (iVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar4 = '\0';
        }
        else {
          cVar4 = '\x01';
        }
        if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,0xd,0xa5,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
        }
      }
      *(undefined8 *)(p_Var3 + 0x170) = 0;
      local_res18[0] = 0xffffffffff676980;
      lVar1 = (**(code **)(WdfFunctions_01025 + 0x9c8))
                        (WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x168),local_res18);
      if (lVar1 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar4 = '\0';
        }
        else {
          cVar4 = '\x01';
        }
        if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,1,0xa6,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)lVar1);
        }
        goto LAB_14002224a;
      }
      if ((*(code **)(p_Var3 + 0x1c0) != (code *)0x0) &&
         (iVar2 = (**(code **)(p_Var3 + 0x1c0))(*(undefined8 *)(p_Var3 + 0x1a8)), iVar2 < 0)) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2)
            ))) {
          cVar4 = '\0';
        }
        else {
          cVar4 = '\x01';
        }
        if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,1,0xa7,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar2);
        }
      }
      HdAudBusSharedResourceCleanup(p_Var3);
      (**(code **)(WdfFunctions_01025 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x168));
    }
    if (*(HdaController **)(p_Var3 + 0x10) != (HdaController *)0x0) {
      HdaController::ReleaseHardwareResources(*(HdaController **)(p_Var3 + 0x10));
      HdaController::Release(*(HdaController **)(p_Var3 + 0x10));
      *(undefined8 *)(p_Var3 + 0x10) = 0;
    }
    if (*(longlong *)(p_Var3 + 0x68) != 0) {
      (**(code **)(WdfFunctions_01025 + 0xa00))(WdfDriverGlobals,*(longlong *)(p_Var3 + 0x68),1);
      (**(code **)(WdfFunctions_01025 + 0x680))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x68));
      *(undefined8 *)(p_Var3 + 0x68) = 0;
    }
    if (*(longlong *)(p_Var3 + 0x70) != 0) {
      (**(code **)(WdfFunctions_01025 + 0xbf0))(WdfDriverGlobals);
      (**(code **)(WdfFunctions_01025 + 0x680))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x70));
      *(undefined8 *)(p_Var3 + 0x70) = 0;
    }
    if (*(longlong *)(p_Var3 + 0x80) != 0) {
      (**(code **)(WdfFunctions_01025 + 0x680))(WdfDriverGlobals);
      *(undefined8 *)(p_Var3 + 0x80) = 0;
    }
    if (*(longlong *)(p_Var3 + 0x168) != 0) {
      (**(code **)(WdfFunctions_01025 + 0x680))(WdfDriverGlobals);
      *(undefined8 *)(p_Var3 + 0x168) = 0;
    }
    if (*(longlong *)(p_Var3 + 0x120) != 0) {
      (**(code **)(WdfFunctions_01025 + 0x680))(WdfDriverGlobals);
      *(undefined8 *)(p_Var3 + 0x120) = 0;
    }
    lVar1 = 0;
  }
LAB_14002224a:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((lVar1 >> 0x1f & 0xfffffffeU) + 4))) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,1,0xa8,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1,(char)lVar1);
  }
  return lVar1;
}



===== HdAudioFlagsNotifyChanges @ 1400222e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudioFlagsNotifyChanges(void * __ptr64) */

void __cdecl HdAudioFlagsNotifyChanges(void *param_1)

{
  bool bVar1;
  
  (**(code **)(WdfFunctions_01025 + 0x9c8))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x120),0);
  bVar1 = *(longlong *)((longlong)param_1 + 0x160) == 0;
  if (bVar1) {
    *(undefined2 *)((longlong)param_1 + 0x11a) = 0xffff;
    *(undefined2 *)((longlong)param_1 + 0x118) = 0;
    (**(code **)(WdfFunctions_01025 + 0xbe0))
              (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x70));
    ArmHdAudioFlagsRegistryNotification(param_1);
  }
  (**(code **)(WdfFunctions_01025 + 0x9d0))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x120));
  if (!bVar1) {
    KeSetEvent(*(undefined8 *)((longlong)param_1 + 0x160),0,0);
  }
  return;
}



===== RemoveS0PowerRelation @ 1400223b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RemoveS0PowerRelation(struct WDFDEVICE__ * __ptr64) */

void __cdecl RemoveS0PowerRelation(WDFDEVICE__ *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  LOCK();
  lVar1 = *(longlong *)(lVar3 + 0x1c8);
  *(longlong *)(lVar3 + 0x1c8) = 0;
  UNLOCK();
  if (lVar1 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 != '\0') || (bVar6)) {
      uVar2 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,2,0xbc,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar2,(char)lVar1);
    }
    ObfDereferenceObject(lVar1);
    uVar4 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
    IoInvalidateDeviceRelations(uVar4,2);
  }
  return;
}



===== StartHdAudioFlagsRegistryNotification @ 1400224fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400227be) */
/* long __cdecl StartHdAudioFlagsRegistryNotification(struct _HDAudioDeviceExtension * __ptr64) */

long __cdecl StartHdAudioFlagsRegistryNotification(_HDAudioDeviceExtension *param_1)

{
  int iVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  undefined1 auStackY_138 [32];
  undefined4 uVar5;
  undefined4 in_stack_fffffffffffffeec;
  undefined2 uVar6;
  undefined8 local_e0;
  wchar_t *local_d8;
  undefined8 local_d0;
  wchar_t *local_c8;
  wchar_t local_c0 [20];
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_138;
  builtin_wcsncpy(local_98,L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Contr",0x30);
  builtin_wcsncpy(local_98 + 0x30,L"ol\\Audio",9);
  local_d8 = local_98;
  uVar5 = 0;
  builtin_wcsncpy(local_c0,L"HDAudioFlags",0xd);
  local_c8 = local_c0;
  local_e0 = 0x720070;
  local_d0 = 0x1a0018;
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x730))(WdfDriverGlobals,0,&local_e0,0x20006);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 == '\0') && (!bVar4)) {
      return 0;
    }
    uVar6 = 0xc;
  }
  else {
    uVar5 = 0;
    iVar1 = (**(code **)(WdfFunctions_01025 + 0x730))(WdfDriverGlobals,0,&local_d0,0x20019);
    if (-1 < iVar1) {
      lVar2 = ArmHdAudioFlagsRegistryNotification(param_1);
      if (lVar2 < 0) {
        return lVar2;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      if ((cVar3 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
      {
        return lVar2;
      }
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_fffffffffffffeec,uVar5),4,0xe,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
      return lVar2;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 == '\0') && (!bVar4)) {
      return 0;
    }
    uVar6 = 0xd;
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_stack_fffffffffffffeec,uVar5),4,
             uVar6,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar1);
  return 0;
}



===== WppCleanupKm @ 140022800 =====

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



===== WppTraceCallback @ 1400228b0 =====

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



===== _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv @ 140022b38 =====

void _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv(void)

{
  return;
}



===== wil_UninitializeFeatureStaging @ 140022b44 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140022b9c =====

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
      goto LAB_140022bf9;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140022bf9;
    }
  }
  uVar1 = 0x206;
LAB_140022bf9:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140022c04 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
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
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140022cbc =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140022cf4 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140022d76;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140022d76;
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
LAB_140022d76:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140022dc0 =====

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
      ppuVar3 = &wil_details_featureDescriptors_a;
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



===== wil_details_RecordFeatureUsageCallback @ 140022e14 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140022e30 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140022e4c =====

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
  ppuVar3 = &wil_details_featureDescriptors_a;
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



===== ~HdaController @ 140022f00 =====

/* public: __cdecl HdaController::~HdaController(void) __ptr64 */

void __thiscall HdaController::~HdaController(HdaController *this)

{
  char cVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffc8;
  
  cVar2 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar2 = '\0';
  }
  if ((cVar1 != '\0') || (cVar2 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,cVar2,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,3,0x2e,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)this);
  }
  ReleaseHardwareResources(this);
  return;
}



===== ~HdaLinkInstance @ 140022f98 =====

/* public: __cdecl HdaLinkInstance::~HdaLinkInstance(void) __ptr64 */

void __thiscall HdaLinkInstance::~HdaLinkInstance(HdaLinkInstance *this)

{
  HdaLinkInstance *pHVar1;
  longlong lVar2;
  
  pHVar1 = this + 0x10;
  lVar2 = 0xf;
  do {
    if (*(void **)pHVar1 != (void *)0x0) {
      operator_delete(*(void **)pHVar1);
      *(undefined8 *)pHVar1 = 0;
    }
    pHVar1 = pHVar1 + 8;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (*(void **)(this + 0x88) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x88));
    *(undefined8 *)(this + 0x88) = 0;
  }
  return;
}



===== GetUseHalDMA @ 140023000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetUseHalDMA(struct WDFDEVICE__ * __ptr64,unsigned long * __ptr64) */

long __cdecl GetUseHalDMA(WDFDEVICE__ *param_1,ulong *param_2)

{
  int iVar1;
  char cVar2;
  undefined1 auStackY_b8 [32];
  undefined8 in_stack_ffffffffffffff68;
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 local_58;
  wchar_t *local_50;
  wchar_t local_48 [12];
  wchar_t local_30 [12];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  builtin_wcsncpy(local_48,L"Settings",9);
  local_60 = local_48;
  builtin_wcsncpy(local_30,L"UseHalDMA",10);
  local_50 = local_30;
  local_68 = 0x120010;
  local_58 = 0x140012;
  Feature_Audio_Drivers_HdAudBus_DmaAdapter__private_ReportDeviceUsage();
  if ((param_1 == (WDFDEVICE__ *)0x0) || (param_2 == (ulong *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2))))
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff68,1,0x37,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    iVar1 = -0x3ffffff3;
  }
  else {
    *param_2 = 0;
    iVar1 = (**(code **)(WdfFunctions_01025 + 0x180))(WdfDriverGlobals,param_1,2,0x20000);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(WdfFunctions_01025 + 0x728))(WdfDriverGlobals,0,&local_68,0x20000);
      (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,0);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(WdfFunctions_01025 + 0x780))(WdfDriverGlobals,0,&local_58,param_2);
        (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,0);
      }
    }
  }
  return iVar1;
}



===== InitializeSgpcLinkCtrl @ 14002321c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl HdaController::InitializeSgpcLinkCtrl(void * __ptr64,unsigned long) __ptr64
    */

long __thiscall
HdaController::InitializeSgpcLinkCtrl(HdaController *this,void *param_1,ulong param_2)

{
  longlong lVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  long lVar5;
  void *pvVar6;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar5 = 0;
  if (param_1 == (void *)0x0) {
    lVar5 = -0x3ffffff3;
  }
  else {
    lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0x70),
                       PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
    if ((*(uint *)param_1 & 0xf0000000) < 0x20000000) {
      uVar2 = ((ushort)*(undefined4 *)((longlong)param_1 + 4) & 0xf) + 1;
      if (1 < uVar2) {
        if (param_2 < (uVar2 + 1) * 0x40) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar3 = '\0';
          }
          if ((cVar3 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0xde,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
          lVar5 = -0x3fffffff;
        }
        else {
          for (uVar4 = 0; uVar4 < uVar2; uVar4 = uVar4 + 1) {
            pvVar6 = (void *)(((ulonglong)uVar4 + 1) * 0x40 + (longlong)param_1);
            if ((*(ushort *)(lVar1 + 0x1e4) & *(ushort *)((longlong)pvVar6 + 0xc)) != 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                cVar3 = '\0';
              }
              if ((cVar3 != '\0') ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_AND_TRACE_SF_
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,
                           0xdf,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
              }
              *(void **)(this + 0x96b0) = pvVar6;
              return 0;
            }
          }
        }
      }
    }
    else {
      lVar5 = -0x3fffff45;
    }
  }
  return lVar5;
}



===== ReportCodecsMissing @ 1400233dc =====

/* public: long __cdecl HdaLinkInstance::ReportCodecsMissing(unsigned short) __ptr64 */

long __thiscall HdaLinkInstance::ReportCodecsMissing(HdaLinkInstance *this,ushort param_1)

{
  uint uVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffb8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,1,0xdb,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)param_1);
  }
  *(ushort *)(this + 8) = *(ushort *)(this + 8) & ~(*(ushort *)(*(longlong *)this + 0xc) & param_1);
  uVar1 = *(uint *)(*(longlong *)this + 4);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,1,0xdc,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)*(undefined2 *)(this + 8));
  }
  if ((*(short *)(this + 8) == 0) && ((uVar1 & 0x800000) != 0)) {
    TurnOff(this);
  }
  return 0;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140023518 =====

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



===== HDAudBusWmiFunctionControl @ 1400235f0 =====

/* long __cdecl HDAudBusWmiFunctionControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,unsigned long,enum _WMIENABLEDISABLECONTROL,unsigned char) */

long __cdecl
HDAudBusWmiFunctionControl
          (_DEVICE_OBJECT *param_1,_IRP *param_2,ulong param_3,_WMIENABLEDISABLECONTROL param_4,
          uchar param_5)

{
  byte bVar1;
  long lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18) < 0x30) {
    uVar3 = 0xc0000023;
  }
  else if (param_4 == 0) {
    if (param_3 == 0) {
      if (param_5 == '\0') {
        LOCK();
        HDAudBusWmiLogEnable = 0;
        UNLOCK();
        HDAudBusWmiLoggerHandle = 0;
        HDAudBusWmiLoggerEnableLevel = 0;
        HDAudBusWmiLoggerEnableFlags = 0;
      }
      else {
        LOCK();
        HDAudBusWmiLogEnable = 1;
        UNLOCK();
        HDAudBusWmiLoggerHandle =
             *(__uint64 *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x20) + 8);
        bVar1 = (byte)(HDAudBusWmiLoggerHandle >> 0x10);
        HDAudBusWmiLoggerEnableLevel = (ulong)bVar1;
        HDAudBusWmiLoggerEnableFlags = (ulong)(HDAudBusWmiLoggerHandle >> 0x20);
        if (bVar1 == 0) {
          HDAudBusWmiLoggerEnableLevel = 0xffffffff;
        }
        if (HDAudBusWmiLoggerEnableFlags == 0) {
          HDAudBusWmiLoggerEnableFlags = 5;
        }
      }
    }
    else {
      uVar3 = 0xc0000295;
    }
  }
  else {
    uVar3 = 0xc0000010;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  lVar2 = WmiCompleteRequest(param_1,param_2,uVar3,0,0);
  return lVar2;
}



===== HDAudUnregisterWmiProvider @ 1400236d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HDAudUnregisterWmiProvider(struct WDFDEVICE__ * __ptr64) */

long __cdecl HDAudUnregisterWmiProvider(WDFDEVICE__ *param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  undefined8 in_stack_ffffffffffffffc8;
  
  uVar2 = (**(code **)(WdfFunctions_01025 + 0xf8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  if ((lVar3 == 0) || (*(longlong *)(lVar3 + 0xa8) == 0)) {
    iVar1 = -0x3ffffff0;
  }
  else {
    ExFreePoolWithTag(*(longlong *)(lVar3 + 0xa8),0);
    *(undefined8 *)(lVar3 + 0xa8) = 0;
    iVar1 = IoWMIRegistrationControl(uVar2);
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xd,
               &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== HDAudWmiQueryRegInfo @ 140023800 =====

/* long __cdecl HDAudWmiQueryRegInfo(struct _DEVICE_OBJECT * __ptr64,unsigned long * __ptr64,struct
   _UNICODE_STRING * __ptr64,struct _UNICODE_STRING * __ptr64 * __ptr64,struct _UNICODE_STRING *
   __ptr64,struct _DEVICE_OBJECT * __ptr64 * __ptr64) */

long __cdecl
HDAudWmiQueryRegInfo
          (_DEVICE_OBJECT *param_1,ulong *param_2,_UNICODE_STRING *param_3,_UNICODE_STRING **param_4
          ,_UNICODE_STRING *param_5,_DEVICE_OBJECT **param_6)

{
  short sVar1;
  longlong lVar2;
  void *_Dst;
  long lVar3;
  
  lVar3 = 0;
  *param_2 = 8;
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (HDAudBusBaseInstanceName[lVar2] != L'\0');
  sVar1 = (short)lVar2 * 2;
  *(short *)param_3 = sVar1;
  sVar1 = sVar1 + 2;
  *(short *)(param_3 + 2) = sVar1;
  _Dst = (void *)ExAllocatePool2(0x100,sVar1,0x30334448);
  *(void **)(param_3 + 8) = _Dst;
  if (_Dst == (void *)0x0) {
    lVar3 = -0x3fffff66;
  }
  else {
    memmove(_Dst,HDAudBusBaseInstanceName,(ulonglong)*(ushort *)param_3);
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(*(ushort *)param_3 >> 1) * 2) = 0;
    *param_4 = g_RegistryPath;
    RtlInitUnicodeString(param_5,L"HDAudioMofName");
  }
  return lVar3;
}



===== HdAudBusChildPowerDown @ 1400238d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl HdAudBusChildPowerDown(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl HdAudBusChildPowerDown(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  _HDAudioDeviceExtension *p_Var1;
  HdaController *this;
  ushort uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  longlong lVar6;
  WDFDEVICE__ *pWVar7;
  char cVar8;
  char cVar9;
  undefined1 auStackY_c8 [32];
  undefined4 uVar10;
  undefined4 in_stack_ffffffffffffff5c;
  undefined4 uVar11;
  undefined4 in_stack_ffffffffffffff64;
  ulonglong in_stack_ffffffffffffff70;
  undefined *puVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  uchar local_68 [4];
  int local_64;
  undefined2 local_60;
  undefined8 local_5e;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  puVar12 = (undefined *)(in_stack_ffffffffffffff70 & 0xffffffff00000000);
  uVar11 = 0;
  local_40 = 0;
  local_64 = 0;
  local_68[0] = '\0';
  uVar10 = 5;
  uVar5 = 0;
  local_50 = 0;
  uStack_48 = 0;
  HDABusWmiLogETW(1,1,'\x04','\x02',5,0,0,0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar8 = '\0';
  }
  uVar13 = SUB81(param_1,0);
  if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    puVar12 = &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids;
    uVar11 = 2;
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_stack_ffffffffffffff5c,uVar10)
               ,2,0x2c,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar13);
  }
  lVar6 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
  if (lVar6 == 0) goto LAB_140023b79;
  if (*(longlong *)(lVar6 + 0x38) != 0) {
    iVar3 = PcRemoveStreamResource();
    if (iVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
         (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar8 = '\0';
      }
      if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        puVar12 = &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids;
        uVar11 = 0xd;
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffff5c,uVar10),0xd,0x2d,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar3);
      }
    }
    *(undefined8 *)(lVar6 + 0x38) = 0;
  }
  if ((((int)param_2 < 4) ||
      (p_Var1 = *(_HDAudioDeviceExtension **)(lVar6 + 0x28),
      p_Var1 == (_HDAudioDeviceExtension *)0x0)) ||
     (this = *(HdaController **)(lVar6 + 0x30), this == (HdaController *)0x0)) goto LAB_140023b79;
  uVar10 = 0x20;
  iVar3 = IoAcquireRemoveLockEx(this + 8,param_1,"",1);
  uVar14 = SUB81(this,0);
  if (iVar3 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar8 = '\0';
    }
    if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_ffffffffffffff5c,uVar10),
                 CONCAT44(in_stack_ffffffffffffff64,uVar11),0x2e,puVar12,uVar13,uVar14,(char)iVar3);
    }
    goto LAB_140023b79;
  }
  local_60 = 10;
  local_5e = 0;
  HdaController::GetDeviceInformation(this,(_HDAUDIO_DEVICE_INFORMATION *)&local_60);
  uVar2 = HdaController::GetCodecInD3(this);
  GetChildID((undefined4 *)&local_50,param_1);
  HdaController::SetCodecInD3(this,uVar2 | (ushort)(1 << (local_40._2_1_ & 0x1f)));
  lVar4 = CheckCodecPowerState(p_Var1,local_40._2_1_,&local_64);
  if ((lVar4 < 0) || (local_64 == 0)) {
LAB_140023f27:
    uVar5 = 0;
  }
  else {
    HdaController::ClearCodecsPresent(this,1 << (local_40._2_1_ & 0x1f));
    *(undefined1 *)(lVar6 + 0x43) = 1;
    pWVar7 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01025 + 0x6e8))(WdfDriverGlobals,param_1);
    uVar5 = CanControllerPowerDown(pWVar7,local_68);
    if (((int)uVar5 < 0) || (local_68[0] == '\0')) goto LAB_140023f27;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
      cVar8 = '\0';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (cVar9 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar9 = '\0';
    }
    if ((cVar8 != '\0') || (cVar9 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,cVar9,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_ffffffffffffff5c,uVar10),2,0x2f,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar14,uVar13);
    }
    uVar10 = 5;
    HDABusWmiLogETW(1,1,'\x04','\x02',5,3,*(ulong *)(p_Var1 + 0x48),*(ulong *)(p_Var1 + 0x4c));
    if (((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) != 0) &&
       (p_Var1[0xbe] != (_HDAudioDeviceExtension)0x0)) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0 ||
          (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)))) {
        cVar8 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar9 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar9 = '\0';
      }
      if ((cVar8 != '\0') || (cVar9 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_qq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,cVar9,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffff5c,uVar10),2,0x30,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar14,uVar13);
      }
      pWVar7 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01025 + 0x6e8))(WdfDriverGlobals,param_1);
      uVar5 = HdAudBusUpdateS0IdleSettings(pWVar7,'\x01');
      uVar10 = 5;
      HDABusWmiLogETW(1,1,'\x04','\x02',5,4,1000,uVar5);
    }
  }
  IoReleaseRemoveLockEx(this + 8,param_1,0x20);
LAB_140023b79:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     (cVar8 = '\x01',
     (int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)(((int)uVar5 >> 0x1f & 0xfffffffeU) + 4))) {
    cVar8 = '\0';
  }
  if ((cVar8 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_stack_ffffffffffffff5c,uVar10)
               ,2,0x31,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar13,(char)uVar5);
  }
  HDABusWmiLogETW(1,1,'\x04','\x02',5,0xff,uVar5,0);
  return uVar5;
}



===== ClearCodecsPresent @ 140023f44 =====

/* public: void __cdecl HdaController::ClearCodecsPresent(unsigned short) __ptr64 */

void __thiscall HdaController::ClearCodecsPresent(HdaController *this,ushort param_1)

{
  undefined8 *puVar1;
  
  KeWaitForSingleObject(this + 0x9678,0,0,0,0);
  for (puVar1 = (undefined8 *)FirstEntrySList(this + 0x9660); puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
    HdaLinkInstance::ReportCodecsMissing((HdaLinkInstance *)puVar1[2],param_1);
  }
  KeReleaseMutex(this + 0x9678,0);
  return;
}



===== CheckCodecPowerState @ 140023fd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CheckCodecPowerState(struct _HDAudioDeviceExtension * __ptr64,unsigned char,int *
   __ptr64) */

long __cdecl CheckCodecPowerState(_HDAudioDeviceExtension *param_1,uchar param_2,int *param_3)

{
  HdaController *pHVar1;
  ushort uVar2;
  ulonglong uVar3;
  uchar uVar4;
  long lVar5;
  char cVar6;
  uint uVar7;
  long lVar8;
  char cVar9;
  uint uVar10;
  undefined1 auStackY_d8 [32];
  undefined4 in_stack_ffffffffffffff48;
  undefined4 in_stack_ffffffffffffff4c;
  undefined8 local_50;
  ulonglong uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar8 = 0;
  *param_3 = 0;
  pHVar1 = *(HdaController **)(param_1 + 0x10);
  if (pHVar1 == (HdaController *)0x0) {
    lVar8 = -0x3ffffff3;
  }
  else {
    if (((param_1[0x1d0] == (_HDAudioDeviceExtension)0x0) ||
        (*(uint *)(param_1 + 0x1e0) != (uint)param_2)) ||
       (param_1[0x1e6] == (_HDAudioDeviceExtension)0x0)) {
      uStack_48 = 0;
      local_50 = (ulonglong)((uint)param_2 << 0x1c | 0xf0004);
      lVar5 = SendVerbs(pHVar1,1,(_HDAUDIO_CODEC_TRANSFER *)&local_50);
      if (lVar5 < 0) {
        uVar4 = IsEnumWorkaroundCodec(param_1,param_2);
        if (uVar4 == '\0') {
          return 0;
        }
      }
      else {
        uVar7 = (uint)uStack_48 >> 0x10;
        for (uVar10 = (uint)uStack_48; (char)uVar10 != '\0'; uVar10 = (uint)(byte)((char)uVar10 - 1)
            ) {
          local_50 = CONCAT44(local_50._4_4_,(uVar7 & 0xff) << 0x14 | (uint)local_50 & 0xf00f0500) |
                     0xf0500;
          lVar5 = SendVerbs(pHVar1,1,(_HDAUDIO_CODEC_TRANSFER *)&local_50);
          uVar3 = uStack_48;
          if (lVar5 < 0) {
            return 0;
          }
          uVar2 = (ushort)uStack_48;
          HDABusWmiLogETW(1,1,'\x04','\x02',5,1,(uint)param_2,(uint)(ushort)uStack_48);
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
             (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
            cVar6 = '\0';
          }
          if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
             (cVar9 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
            cVar9 = '\0';
          }
          if ((cVar6 != '\0') || (cVar9 != '\0')) {
            WPP_RECORDER_AND_TRACE_SF_qddds
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar9,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          if ((uVar2 & 0xf0) < 0x30) {
            return 0;
          }
          if ((uVar3 & 0x200) == 0) {
            return 0;
          }
          uVar7 = (uint)(byte)((char)uVar7 + 1);
        }
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
         (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar6 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar9 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar9 = '\0';
      }
      if ((cVar6 != '\0') || (cVar9 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar9,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffff4c,in_stack_ffffffffffffff48),0xd,0xb6,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,param_2);
      }
    }
    *param_3 = 1;
  }
  return lVar8;
}



===== CanControllerPowerDown @ 1400242d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CanControllerPowerDown(struct WDFDEVICE__ * __ptr64,unsigned char * __ptr64) */

long __cdecl CanControllerPowerDown(WDFDEVICE__ *param_1,uchar *param_2)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  long lVar6;
  longlong local_res10;
  undefined8 in_stack_ffffffffffffff78;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  lVar3 = WdfFunctions_01025;
  local_res10 = 0;
  *param_2 = '\0';
  lVar3 = (**(code **)(lVar3 + 0x420))(WdfDriverGlobals,param_1);
  uVar8 = SUB81(param_1,0);
  if (lVar3 == 0) {
    lVar6 = -0x3ffffe7c;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff78,2,0xb8,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar8,0x84);
    }
  }
  else {
    local_58 = 0x28;
    local_50 = 0;
    uStack_48 = 0;
    local_54 = 5;
    local_40 = 0;
    uStack_38 = 0;
    (**(code **)(WdfFunctions_01025 + 0x30))(WdfDriverGlobals,lVar3,&local_58);
    bVar1 = true;
    do {
      while( true ) {
        do {
          uVar7 = 0;
          iVar2 = (**(code **)(WdfFunctions_01025 + 0x38))
                            (WdfDriverGlobals,lVar3,&local_58,&local_res10);
          if (iVar2 == -0x7fffffe6) {
            *param_2 = '\x01';
            goto LAB_140024406;
          }
          if (iVar2 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar1 = false;
            }
            if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_qd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,2,0xb9,
                         &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar8,(char)iVar2);
            }
            goto LAB_140024406;
          }
        } while (local_res10 == 0);
        lVar4 = (**(code **)(WdfFunctions_01025 + 0x650))
                          (WdfDriverGlobals,local_res10,
                           PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
        if (lVar4 != 0) break;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,2,0xba,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar8,0x84);
        }
      }
    } while (*(char *)(lVar4 + 0x43) != '\0');
LAB_140024406:
    (**(code **)(WdfFunctions_01025 + 0x40))(WdfDriverGlobals,lVar3,&local_58);
    lVar6 = 0;
  }
  return lVar6;
}



===== HdAudBusEnableWakeForChildDevice @ 1400245b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl HdAudBusEnableWakeForChildDevice(struct WDFDEVICE__ * __ptr64,enum
   _SYSTEM_POWER_STATE) */

long __cdecl HdAudBusEnableWakeForChildDevice(WDFDEVICE__ *param_1,_SYSTEM_POWER_STATE param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  char cVar7;
  undefined1 auStackY_a8 [32];
  undefined4 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  undefined4 in_stack_ffffffffffffff80;
  undefined4 in_stack_ffffffffffffff84;
  undefined *in_stack_ffffffffffffff90;
  undefined1 uVar8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  iVar5 = 0;
  lVar6 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
  lVar2 = *(longlong *)(lVar6 + 0x28);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  bVar4 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  uVar8 = SUB81(param_1,0);
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffff90 = &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids;
    in_stack_ffffffffffffff80 = 2;
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),2,0x35,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar8,(char)param_2 + -1);
  }
  lVar3 = *(longlong *)(lVar6 + 0x30);
  if (lVar3 != 0) {
    in_stack_ffffffffffffff78 = 0x20;
    iVar5 = IoAcquireRemoveLockEx(lVar3 + 8,param_1,"",1);
    if (iVar5 == 0) {
      GetChildID((undefined4 *)&local_48,param_1);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_D
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),2,0x37,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,local_38._3_1_);
      }
      *(undefined1 *)(lVar6 + 0x42) = 1;
      LOCK();
      piVar1 = (int *)(lVar2 + 0x18);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      HdaController::UpdateWaitWake(*(HdaController **)(lVar2 + 0x10));
      IoReleaseRemoveLockEx(lVar3 + 8,param_1,0x20);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_qqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),
                   CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80),0x36,
                   in_stack_ffffffffffffff90,uVar8,(char)lVar3,(char)iVar5);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     ((int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((iVar5 >> 0x1f & 0xfffffffeU) + 4))) {
    bVar4 = false;
  }
  if ((bVar4) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),2,0x38,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar8,(char)iVar5);
  }
  return iVar5;
}



===== HdAudBusDisableWakeForChildDevice @ 1400248f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl HdAudBusDisableWakeForChildDevice(struct WDFDEVICE__ * __ptr64) */

void __cdecl HdAudBusDisableWakeForChildDevice(WDFDEVICE__ *param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  char cVar7;
  char cVar8;
  undefined1 auStackY_a8 [32];
  undefined4 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  undefined4 in_stack_ffffffffffffff80;
  undefined4 in_stack_ffffffffffffff84;
  undefined *in_stack_ffffffffffffff90;
  undefined1 uVar9;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar6 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
  lVar2 = *(longlong *)(lVar6 + 0x28);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  bVar4 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  uVar9 = SUB81(param_1,0);
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffff90 = &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids;
    in_stack_ffffffffffffff80 = 2;
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),2,0x39,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar9);
  }
  lVar3 = *(longlong *)(lVar6 + 0x30);
  if (lVar3 != 0) {
    in_stack_ffffffffffffff78 = 0x20;
    iVar5 = IoAcquireRemoveLockEx(lVar3 + 8,param_1,"",1);
    if (iVar5 == 0) {
      GetChildID((undefined4 *)&local_48,param_1);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar7 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar8 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar8 = '\0';
      }
      if ((cVar7 != '\0') || (cVar8 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_D
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar8,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),2,0x3b,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,local_38._3_1_);
      }
      *(undefined1 *)(lVar6 + 0x42) = 0;
      LOCK();
      piVar1 = (int *)(lVar2 + 0x18);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      HdaController::UpdateWaitWake(*(HdaController **)(lVar2 + 0x10));
      IoReleaseRemoveLockEx(lVar3 + 8,param_1,0x20);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar7 = '\0';
      }
      if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_qqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),
                   CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80),0x3a,
                   in_stack_ffffffffffffff90,uVar9,(char)lVar3,(char)iVar5);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar4 = false;
  }
  if ((bVar4) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),2,0x3c,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,uVar9,0);
  }
  return;
}



===== UpdateWaitWake @ 140024c2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl HdaController::UpdateWaitWake(void) __ptr64 */

void __thiscall HdaController::UpdateWaitWake(HdaController *this)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 local_98 [32];
  undefined8 local_78;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)local_98;
  *(undefined2 *)(this + 0x94a8) = 0;
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x70),
                     PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  if (*(int *)(lVar2 + 0x18) != 0) {
    uVar3 = (**(code **)(WdfFunctions_01025 + 0x420))(WdfDriverGlobals,*(undefined8 *)(this + 0x70))
    ;
    local_68 = 0;
    local_60 = 0x28;
    local_5c = 1;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    (**(code **)(WdfFunctions_01025 + 0x30))(WdfDriverGlobals,uVar3,&local_60);
    while( true ) {
      local_78 = 0;
      iVar1 = (**(code **)(WdfFunctions_01025 + 0x38))(WdfDriverGlobals,uVar3,&local_60,&local_68);
      if (iVar1 < 0) break;
      lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                        (WdfDriverGlobals,local_68,PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070
                        );
      local_28 = 0;
      local_38 = 0;
      uStack_30 = 0;
      GetChildID((undefined4 *)&local_38,local_68);
      if (*(char *)(lVar2 + 0x42) != '\0') {
        *(ushort *)(this + 0x94a8) =
             *(ushort *)(this + 0x94a8) | (ushort)(1 << (local_28._2_1_ & 0x1f));
      }
    }
    (**(code **)(WdfFunctions_01025 + 0x40))(WdfDriverGlobals,uVar3,&local_60);
  }
  *(ushort *)(*(longlong *)(this + 0x58) + 0xc) =
       (*(ushort *)(*(longlong *)(this + 0x58) + 0xc) ^ *(ushort *)(this + 0x94a8)) & 0x7fff ^
       *(ushort *)(*(longlong *)(this + 0x58) + 0xc);
  LOCK();
  UNLOCK();
  return;
}



===== BuildHDAudioConverterFormat @ 140024de8 =====

/* private: long __cdecl HdaController::BuildHDAudioConverterFormat(struct _HDAUDIO_STREAM_FORMAT *
   __ptr64,struct _HDAUDIO_CONVERTER_FORMAT * __ptr64) __ptr64 */

long __thiscall
HdaController::BuildHDAudioConverterFormat
          (HdaController *this,_HDAUDIO_STREAM_FORMAT *param_1,_HDAUDIO_CONVERTER_FORMAT *param_2)

{
  bool bVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  ushort uVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffb8;
  undefined2 uVar7;
  
  *(undefined2 *)param_2 = 0;
  sVar2 = *(short *)(param_1 + 4);
  bVar1 = true;
  if (sVar2 == 8) {
    bVar6 = *(short *)(param_1 + 6) == 8;
LAB_140024e59:
    if (!bVar6) goto LAB_140024f76;
    for (uVar3 = 0; uVar3 < 0xf; uVar3 = uVar3 + 1) {
      if (*(int *)param_1 == *(int *)(&frequencyConversionTable + uVar3)) {
        uVar5 = (ushort)(*(byte *)((longlong)&frequencyConversionTable + (ulonglong)uVar3 * 8 + 4) &
                        0x7f) << 8 | *(ushort *)param_2 & 0x80ff;
        *(ushort *)param_2 = uVar5;
        if ((ushort)(*(short *)(param_1 + 8) - 1U) < 0x10) {
          *(ushort *)param_2 = (*(short *)(param_1 + 8) - 1U ^ uVar5) & 0xf ^ uVar5;
          return 0;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
           (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar4 = '\0';
        }
        bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar4 == '\0') && (!bVar6)) goto LAB_14002509a;
        uVar7 = 0x11;
        goto LAB_140025085;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar4 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 == '\0') && (!bVar6)) goto LAB_14002509a;
    uVar7 = 0x10;
  }
  else {
    if (sVar2 == 0x10) {
      bVar6 = *(short *)(param_1 + 6) == 0x10;
      *(undefined2 *)param_2 = 0x10;
      goto LAB_140024e59;
    }
    if (sVar2 == 0x18) {
      sVar2 = *(short *)(param_1 + 6);
      *(undefined2 *)param_2 = 0x30;
LAB_140024e56:
      bVar6 = sVar2 == 0x20;
      goto LAB_140024e59;
    }
    if (sVar2 == 0x14) {
      sVar2 = *(short *)(param_1 + 6);
      *(undefined2 *)param_2 = 0x20;
      goto LAB_140024e56;
    }
    if (sVar2 == 0x20) {
      sVar2 = *(short *)(param_1 + 6);
      *(undefined2 *)param_2 = 0x40;
      goto LAB_140024e56;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,0xd,0xe,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
LAB_140024f76:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar4 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 == '\0') && (!bVar6)) goto LAB_14002509a;
    uVar7 = 0xf;
  }
LAB_140025085:
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar6,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,0xd,uVar7,
             &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
LAB_14002509a:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,0xd,0x12,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0xd);
  }
  return -0x3ffffff3;
}



===== HdAudBusPowerDown @ 140025110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HdAudBusPowerDown(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl HdAudBusPowerDown(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  bool bVar1;
  long lVar2;
  longlong lVar3;
  uchar uVar4;
  undefined8 in_stack_ffffffffffffffb8;
  
  lVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    uVar4 = '\0';
  }
  else {
    uVar4 = '\x01';
  }
  if ((uVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,2,0x6b,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1,(char)param_2 + -1);
  }
  if (*(HdaController **)(lVar3 + 0x10) == (HdaController *)0x0) {
    lVar2 = -0x3ffffff0;
  }
  else {
    lVar2 = HdaController::PowerDown(*(HdaController **)(lVar3 + 0x10),uVar4);
    if (-1 < lVar2) {
      *(_WDF_POWER_DEVICE_STATE *)(lVar3 + 0xa0) = param_2;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     ((int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((lVar2 >> 0x1f & 0xfffffffeU) + 4))) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,2,0x6c,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1,(char)lVar2);
  }
  return lVar2;
}



===== HdAudBusAddDevice @ 1400252c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl HdAudBusAddDevice(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl HdAudBusAddDevice(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  _HDAudioDeviceExtension _Var1;
  uchar uVar2;
  int iVar3;
  long lVar4;
  _HDAudioDeviceExtension *p_Var5;
  undefined8 uVar6;
  _DEVICE_OBJECT *p_Var7;
  undefined4 uVar8;
  undefined8 uVar9;
  char cVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  undefined1 auStackY_2a8 [32];
  undefined8 in_stack_fffffffffffffd78;
  _HDAudioDeviceExtension *p_Var14;
  undefined8 *puVar15;
  undefined2 uVar16;
  _HDAudioDeviceExtension local_258 [8];
  WDFDEVICE__ *local_250;
  WDFDEVICE_INIT *local_248;
  int local_240;
  undefined8 local_238;
  ulonglong local_230;
  code *local_228;
  undefined8 local_220;
  undefined4 local_218;
  undefined4 local_214;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined *local_200;
  undefined8 local_1f8;
  undefined *local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  WDFDEVICE__ *local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined4 local_1a8 [6];
  code *local_190;
  code *local_178;
  undefined4 local_168 [2];
  code *local_160;
  code *local_150;
  code *local_140;
  code *local_138;
  code *local_120;
  code *local_118;
  code *local_110;
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_c8;
  code *local_c0;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2a8;
  local_230 = (ulonglong)(uint)local_230;
  local_68 = 0;
  local_220 = 0;
  local_250 = (WDFDEVICE__ *)0x0;
  local_210 = 0;
  uStack_208 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar10 = '\0';
  }
  local_248 = param_2;
  if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffd78,1,0xa9,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  (**(code **)(WdfFunctions_01025 + 0x210))(WdfDriverGlobals,local_248,0x2a);
  memset(local_168,0,0x90);
  local_140 = HdAudBusStartDevice;
  local_138 = HdAudBusRemoveDevice;
  local_160 = HdAudBusPowerUp;
  local_150 = HdAudBusPowerDown;
  local_120 = HdAudBusSelfManagedIoInitAndRestart;
  local_110 = HdAudBusSelfManagedIoInitAndRestart;
  local_118 = HdAudBusSelfManagedIoSuspend;
  local_168[0] = 0x90;
  (**(code **)(WdfFunctions_01025 + 0x1b8))(WdfDriverGlobals,local_248,local_168);
  memset(local_1a8,0,0x40);
  local_190 = HdAudBusWakeTriggered;
  local_178 = HdAudBusWakeTriggered;
  local_1a8[0] = 0x40;
  (**(code **)(WdfFunctions_01025 + 0x1c0))(WdfDriverGlobals,local_248,local_1a8);
  (**(code **)(WdfFunctions_01025 + 0xd70))(WdfDriverGlobals,local_248,2);
  p_Var14 = local_258;
  local_258[0] = (_HDAudioDeviceExtension)0x7;
  iVar3 = (**(code **)(WdfFunctions_01025 + 0x248))
                    (WdfDriverGlobals,local_248,EvtIrpPreprocessQueryDevRelations,0x1b);
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var14,1,0xaa,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar3);
    }
  }
  memset(&local_d8,0,0x60);
  local_c8 = HdAudBusCreateChildDevice;
  local_d8 = 0x60;
  local_c0 = HdAudBusEnumerateBus;
  local_d4 = 0x18;
  (**(code **)(WdfFunctions_01025 + 0x410))(WdfDriverGlobals,local_248,&local_d8,0);
  local_200 = PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098;
  local_230 = 0x38;
  local_228 = HdAudBusEvtDeviceCleanupCallback;
  local_220 = 0;
  local_210 = 0;
  uStack_208 = 0;
  local_218 = 1;
  local_214 = 1;
  iVar3 = (**(code **)(WdfFunctions_01025 + 600))(WdfDriverGlobals,&local_248,&local_230,&local_250)
  ;
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    bVar13 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar10 == '\0') && (!bVar13)) goto LAB_140025d54;
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar16 = 0xab;
  }
  else {
    p_Var5 = (_HDAudioDeviceExtension *)
             (**(code **)(WdfFunctions_01025 + 0x650))
                       (WdfDriverGlobals,local_250,
                        PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
    *(WDFDEVICE__ **)(p_Var5 + 8) = local_250;
    puVar15 = &local_238;
    local_1f0 = &DEVPKEY_Device_InstanceId;
    p_Var14 = (_HDAudioDeviceExtension *)&local_1e0;
    local_1d0 = 0;
    local_1b0 = 0;
    uStack_1d8 = 0;
    local_1f8 = 0x18;
    uStack_1b8 = 0;
    local_1e8 = 0;
    local_1e0 = 0x38;
    uStack_1c8 = 0x100000001;
    local_1c0 = local_250;
    local_240 = 0;
    local_238 = 0;
    iVar3 = (**(code **)(WdfFunctions_01025 + 0xd90))(WdfDriverGlobals,local_250,&local_1f8,0x200);
    if ((-1 < iVar3) && (local_240 == 0x12)) {
      uVar6 = (**(code **)(WdfFunctions_01025 + 0x610))(WdfDriverGlobals,local_238,0);
      *(undefined8 *)(p_Var5 + 0x1e8) = uVar6;
    }
    *(undefined2 *)(p_Var5 + 0x11a) = 0xffff;
    *(undefined2 *)(p_Var5 + 0x118) = 0;
    *(undefined8 *)(p_Var5 + 0x120) = 0;
    *(undefined8 *)(p_Var5 + 0x128) = 0;
    *(undefined8 *)(p_Var5 + 0x160) = 0;
    *(undefined8 *)(p_Var5 + 0x150) = 0;
    *(undefined8 *)(p_Var5 + 0x158) = 0;
    *(undefined4 *)(p_Var5 + 0x1e0) = 0xffffffff;
    *(undefined8 *)(p_Var5 + 0x60) = 0;
    *(undefined8 *)(p_Var5 + 0xb0) = 0;
    p_Var5[0xc2] = (_HDAudioDeviceExtension)0x0;
    *(undefined2 *)(p_Var5 + 0x1e4) = 0;
    *(undefined8 *)(p_Var5 + 0x170) = 0;
    *(undefined8 *)(p_Var5 + 0x1c8) = 0;
    p_Var5[0x1d0] = (_HDAudioDeviceExtension)0x0;
    memset(p_Var5 + 0xd0,0,0x48);
    ReadPciDeviceId(local_250,(__uint64 *)p_Var5);
    HdAudGetDeviceFlags((ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18),
                        (ushort)((ulonglong)*(undefined8 *)p_Var5 >> 8),(uchar)*p_Var5,
                        (_KSE_HDAUDIO_DEVICE_FLAGS *)(p_Var5 + 200));
    p_Var7 = (_DEVICE_OBJECT *)(**(code **)(WdfFunctions_01025 + 0xf8))(WdfDriverGlobals,local_250);
    iVar3 = GetDeviceCapabilities(p_Var7,(_DEVICE_CAPABILITIES *)(p_Var5 + 0x1c));
    if (-1 < iVar3) {
      p_Var5[0xbc] = (_HDAudioDeviceExtension)0x0;
      *(undefined2 *)(p_Var5 + 0xbf) = 0;
      if ((short)((ulonglong)*(undefined8 *)p_Var5 >> 0x18) == 0x10de) {
        p_Var5[0xc0] = (_HDAudioDeviceExtension)0x1;
      }
      GetConfigRegistrySettings(local_250);
      if ((*(int *)(p_Var5 + 0x48) == 0) || (*(uint *)(p_Var5 + 0x4c) < 2)) {
        _Var1 = (_HDAudioDeviceExtension)0x0;
        uVar8 = 1;
      }
      else {
        _Var1 = (_HDAudioDeviceExtension)0x1;
        uVar8 = 2;
      }
      *(undefined4 *)(p_Var5 + 0xb8) = uVar8;
      p_Var5[0xbe] = _Var1;
      lVar4 = QueryForD3ColdInterface(local_250);
      if (-1 < lVar4) {
        local_258[0] = (_HDAudioDeviceExtension)0x0;
        lVar4 = IsS0IdleWakeCapable(p_Var5,(uchar *)local_258);
        if (-1 < lVar4) {
          if (local_258[0] == (_HDAudioDeviceExtension)0x0) {
            *(undefined4 *)(p_Var5 + 0xb8) = 1;
            p_Var5[0xbe] = (_HDAudioDeviceExtension)0x0;
          }
          else {
            *(undefined4 *)(p_Var5 + 0xb8) = 2;
            p_Var5[0xbe] = (_HDAudioDeviceExtension)0x1;
          }
        }
        uVar2 = IsD3ColdCapable(p_Var5);
        if (uVar2 == '\0') {
          p_Var5[0xc0] = (_HDAudioDeviceExtension)0x0;
        }
      }
      if (((((short)((ulonglong)*(undefined8 *)p_Var5 >> 0x18) == 0x10de) &&
           (p_Var5[0xbc] == (_HDAudioDeviceExtension)0x0)) &&
          (p_Var5[0xbe] == (_HDAudioDeviceExtension)0x0)) &&
         (p_Var5[0xc0] != (_HDAudioDeviceExtension)0x0)) {
        p_Var5[0xbf] = (_HDAudioDeviceExtension)0x1;
      }
      if ((p_Var5[0xbf] != (_HDAudioDeviceExtension)0x0) &&
         (p_Var5[0xbe] == (_HDAudioDeviceExtension)0x0)) {
        *(undefined4 *)(p_Var5 + 0xb8) = 1;
        p_Var5[0xbe] = (_HDAudioDeviceExtension)0x1;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar10 = '\0';
      }
      pcVar11 = " ";
      if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        pcVar12 = " ";
        if (p_Var5[0xbe] == (_HDAudioDeviceExtension)0x0) {
          pcVar12 = " NOT ";
        }
        WPP_RECORDER_AND_TRACE_SF_s
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var14,puVar15,0xad,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,pcVar12);
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar10 = '\0';
      }
      if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        pcVar12 = " ";
        if (p_Var5[0xbc] == (_HDAudioDeviceExtension)0x0) {
          pcVar12 = " NOT ";
        }
        WPP_RECORDER_AND_TRACE_SF_s
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var14,puVar15,0xae,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,pcVar12);
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar10 = '\0';
      }
      if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        pcVar12 = " ";
        if (p_Var5[0xc0] == (_HDAudioDeviceExtension)0x0) {
          pcVar12 = " NOT ";
        }
        WPP_RECORDER_AND_TRACE_SF_s
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var14,puVar15,0xaf,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,pcVar12);
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar10 = '\0';
      }
      if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        if (p_Var5[0xbf] == (_HDAudioDeviceExtension)0x0) {
          pcVar11 = " NOT ";
        }
        WPP_RECORDER_AND_TRACE_SF_s
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var14,puVar15,0xb0,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,pcVar11);
      }
      if ((*(int *)(p_Var5 + 0x48) != 0) && (1 < *(uint *)(p_Var5 + 0x4c))) {
        local_78 = 0x500000014;
        uStack_70 = 1;
        local_68 = 1;
        iVar3 = (**(code **)(WdfFunctions_01025 + 0x178))(WdfDriverGlobals,local_250,&local_78);
        if (iVar3 < 0) goto LAB_140025d54;
      }
      if (((p_Var5[0xbc] != (_HDAudioDeviceExtension)0x0) ||
          (p_Var5[0xbe] != (_HDAudioDeviceExtension)0x0)) &&
         (lVar4 = HdAudBusUpdateS0IdleSettings(local_250,'\0'), lVar4 < 0)) {
        *(undefined4 *)(p_Var5 + 0xb8) = 1;
        if (p_Var5[0xbe] != (_HDAudioDeviceExtension)0x0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar10 = '\0';
          }
          if ((cVar10 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var14,1,0xb1,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
          }
          p_Var5[0xbe] = (_HDAudioDeviceExtension)0x0;
        }
        if (p_Var5[0xbc] != (_HDAudioDeviceExtension)0x0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar10 = '\0';
          }
          if ((cVar10 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var14,1,0xb2,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
          }
          p_Var5[0xbc] = (_HDAudioDeviceExtension)0x0;
        }
      }
      p_Var5[0xbd] = (_HDAudioDeviceExtension)0x0;
      p_Var14 = p_Var5 + 0xb0;
      iVar3 = PoRegisterPowerSettingCallback
                        (0,&GUID_LOW_POWER_EPOCH,HDAudBusLowPowerCallback,local_250);
      if (-1 < iVar3) {
        local_60 = 0xbbd1a745;
        uStack_5c = 0x4575add6;
        uStack_58 = 0x429b2e9c;
        uStack_54 = 0x66321c8d;
        local_50 = 5;
        (**(code **)(WdfFunctions_01025 + 0x2a8))(WdfDriverGlobals,local_250,&local_60);
      }
      goto LAB_140025d54;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    bVar13 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar10 == '\0') && (!bVar13)) goto LAB_140025d54;
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar16 = 0xac;
  }
  WPP_RECORDER_AND_TRACE_SF_D
            (uVar9,cVar10,bVar13,uVar6,p_Var14,1,uVar16,
             &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar3);
LAB_140025d54:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar10 = '\x01',
     (int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((iVar3 >> 0x1f & 0xfffffffeU) + 4))) {
    cVar10 = '\0';
  }
  if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var14,1,0xb3,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1,(char)iVar3);
  }
  return iVar3;
}



===== ReadPciDeviceId @ 140025df4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ReadPciDeviceId(struct WDFDEVICE__ * __ptr64,unsigned __int64 * __ptr64) */

long __cdecl ReadPciDeviceId(WDFDEVICE__ *param_1,__uint64 *param_2)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined1 auStackY_1d8 [32];
  undefined2 uVar4;
  undefined2 in_stack_fffffffffffffe4a;
  undefined4 in_stack_fffffffffffffe4c;
  undefined1 local_178 [8];
  undefined8 local_170;
  code *local_160;
  code *local_140;
  undefined2 local_138;
  undefined2 local_136;
  undefined1 local_130;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1d8;
  memset(local_178,0,0x40);
  memset(&local_138,0,0x100);
  bVar1 = true;
  uVar4 = 0x40;
  iVar2 = (**(code **)(WdfFunctions_01025 + 0x418))
                    (WdfDriverGlobals,param_1,&GUID_BUS_INTERFACE_STANDARD,local_178);
  if (-1 < iVar2) {
    uVar4 = 0x100;
    in_stack_fffffffffffffe4a = 0;
    iVar2 = (*local_140)(local_170,0,&local_138,0);
    if (iVar2 == 0x100) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        bVar1 = false;
      }
      if ((bVar1 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_DDD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      *param_2 = (ulonglong)CONCAT41(CONCAT22(local_138,local_136),local_130);
      (*local_160)(local_170);
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_fffffffffffffe4c,CONCAT22(in_stack_fffffffffffffe4a,uVar4)),4,
                 0x1d,&WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
    iVar2 = -0x3ffffff0;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_fffffffffffffe4c,CONCAT22(in_stack_fffffffffffffe4a,uVar4)),4,0x1f,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar2);
  }
  return iVar2;
}



===== GetDeviceCapabilities @ 14002605c =====

/* long __cdecl GetDeviceCapabilities(struct _DEVICE_OBJECT * __ptr64,struct _DEVICE_CAPABILITIES *
   __ptr64) */

long __cdecl GetDeviceCapabilities(_DEVICE_OBJECT *param_1,_DEVICE_CAPABILITIES *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  char cVar5;
  undefined2 *_Dst;
  undefined8 uVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  memset(param_2,0,0x40);
  *(undefined4 *)param_2 = 0x10040;
  *(undefined4 *)(param_2 + 8) = 0xffffffff;
  *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
  KeInitializeEvent(&local_28,0,0);
  uVar3 = IoGetAttachedDeviceReference(param_1);
  uVar6 = 0;
  lVar4 = IoBuildSynchronousFsdRequest(0x1b,uVar3,0,0,0,&local_28,&local_38);
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    _Dst = (undefined2 *)(lVar1 + -0x48);
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    memset(_Dst,0,0x48);
    *_Dst = 0x91b;
    *(_DEVICE_CAPABILITIES **)(lVar1 + -0x40) = param_2;
    iVar2 = IofCallDriver(uVar3);
    if (iVar2 == 0x103) {
      uVar6 = 0;
      KeWaitForSingleObject(&local_28,0,0,0);
      iVar2 = (int)local_38;
    }
  }
  ObfDereferenceObject(uVar3);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,1,0x8e,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar2);
    }
  }
  return iVar2;
}



===== IsS0IdleWakeCapable @ 140026230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl IsS0IdleWakeCapable(struct _HDAudioDeviceExtension * __ptr64,unsigned char *
   __ptr64) */

long __cdecl IsS0IdleWakeCapable(_HDAudioDeviceExtension *param_1,uchar *param_2)

{
  code *pcVar1;
  int iVar2;
  char cVar3;
  uint local_res8 [2];
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res8[0] = 0;
  pcVar1 = *(code **)(param_1 + 0xf8);
  iVar2 = -0x3fffff45;
  *param_2 = '\0';
  if (pcVar1 != (code *)0x0) {
    iVar2 = (*pcVar1)(*(undefined8 *)(param_1 + 0xd8),1,local_res8);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0x1c,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar2);
    }
    if ((-1 < iVar2) && (1 < local_res8[0])) {
      *param_2 = '\x01';
    }
  }
  return iVar2;
}



===== GetConfigRegistrySettings @ 140026304 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl GetConfigRegistrySettings(struct WDFDEVICE__ * __ptr64) */

void __cdecl GetConfigRegistrySettings(WDFDEVICE__ *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined8 uVar7;
  bool bVar8;
  undefined1 auStackY_1e8 [32];
  undefined8 uVar9;
  undefined2 uVar10;
  int local_198 [2];
  undefined8 local_190;
  undefined8 local_188;
  undefined1 *local_180;
  undefined8 local_178;
  undefined8 local_170;
  wchar_t *local_168;
  wchar_t local_160 [20];
  undefined1 local_138 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_180 = local_138;
  builtin_wcsncpy(local_160,L"PowerSettings",0xe);
  local_168 = local_160;
  local_178 = 0;
  local_190 = 0;
  local_188 = 0x1000000;
  local_170 = 0x1c001a;
  lVar2 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  uVar9 = 0;
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x180))(WdfDriverGlobals,param_1,2,0x20000);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
       (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 == '\0') && (!bVar8)) {
      return;
    }
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar10 = 0x10;
LAB_140026458:
    WPP_RECORDER_AND_TRACE_SF_d
              (uVar3,cVar5,bVar8,uVar7,uVar9,0xd,uVar10,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar1);
    return;
  }
  uVar9 = 0;
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x728))(WdfDriverGlobals,local_178,&local_170,0x20000);
  (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,local_178);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
       (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar5 = '\0';
    }
    bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 == '\0') && (!bVar8)) {
      return;
    }
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar10 = 0x11;
    goto LAB_140026458;
  }
  local_198[0] = 0;
  RtlUnicodeStringPrintf((_UNICODE_STRING *)&local_188,(ushort *)L"EnableS0Standby");
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x780))(WdfDriverGlobals,local_190,&local_188);
  cVar5 = '\x01';
  if (-1 < iVar1) {
    if (local_198[0] == 0) {
      *(undefined1 *)(lVar2 + 0xbc) = 0;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar4 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar6 = '\0';
      }
      if ((cVar4 != '\0') || (cVar6 != '\0')) {
        uVar10 = 0x13;
        goto LAB_140026642;
      }
    }
    else {
      *(undefined1 *)(lVar2 + 0xbc) = 1;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar4 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar6 = '\0';
      }
      if ((cVar4 != '\0') || (cVar6 != '\0')) {
        uVar10 = 0x12;
LAB_140026642:
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar6,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0xd,uVar10,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
      }
    }
  }
  local_198[0] = 0;
  RtlUnicodeStringPrintf((_UNICODE_STRING *)&local_188,(ushort *)L"EnableD3Cold");
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x780))(WdfDriverGlobals,local_190,&local_188);
  if (-1 < iVar1) {
    if (local_198[0] == 0) {
      *(undefined1 *)(lVar2 + 0xc0) = 0;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar4 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar6 = '\0';
      }
      if ((cVar4 != '\0') || (cVar6 != '\0')) {
        uVar10 = 0x15;
        goto LAB_140026748;
      }
    }
    else {
      *(undefined1 *)(lVar2 + 0xc0) = 1;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar4 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar6 = '\0';
      }
      if ((cVar4 != '\0') || (cVar6 != '\0')) {
        uVar10 = 0x14;
LAB_140026748:
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar6,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0xd,uVar10,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
      }
    }
  }
  local_198[0] = 0;
  RtlUnicodeStringPrintf((_UNICODE_STRING *)&local_188,(ushort *)L"EnableNoWakeIdleTimeout");
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x780))(WdfDriverGlobals,local_190,&local_188,local_198)
  ;
  if (-1 < iVar1) {
    if (local_198[0] == 0) {
      *(undefined1 *)(lVar2 + 0xbf) = 0;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar4 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar5 = '\0';
      }
      if ((cVar4 == '\0') && (cVar5 == '\0')) goto LAB_14002685b;
      uVar10 = 0x17;
    }
    else {
      *(undefined1 *)(lVar2 + 0xbf) = 1;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar4 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar5 = '\0';
      }
      if ((cVar4 == '\0') && (cVar5 == '\0')) goto LAB_14002685b;
      uVar10 = 0x16;
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0xd,uVar10,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
  }
LAB_14002685b:
  (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,local_190);
  return;
}



===== IsD3ColdCapable @ 1400268b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl IsD3ColdCapable(struct _HDAudioDeviceExtension * __ptr64) */

uchar __cdecl IsD3ColdCapable(_HDAudioDeviceExtension *param_1)

{
  int iVar1;
  char cVar2;
  uchar uVar3;
  uchar local_res8 [8];
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar3 = '\0';
  local_res8[0] = '\0';
  if ((*(longlong *)(param_1 + 0xf0) != 0) && (*(code **)(param_1 + 0x100) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 0x100))(*(undefined8 *)(param_1 + 0xd8),local_res8);
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
        (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
      cVar2 = '\0';
    }
    if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,1,0x1b,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
    if (-1 < iVar1) {
      uVar3 = local_res8[0];
    }
  }
  return uVar3;
}



===== AllocateBuffer @ 140026978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: struct _MDL * __ptr64 __cdecl HdaController::AllocateBuffer(unsigned __int64,int)
   __ptr64 */

_MDL * __thiscall HdaController::AllocateBuffer(HdaController *this,__uint64 param_1,int param_2)

{
  longlong lVar1;
  _MDL *p_Var2;
  undefined8 uVar3;
  
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x70),
                     PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  if (this[0x80] == (HdaController)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0xffffffffffffffff;
  }
  if ((param_2 == 0) || (5 < *(int *)(lVar1 + 0xc4))) {
    p_Var2 = (_MDL *)MmAllocatePagesForMdl(0,uVar3,0,param_1);
  }
  else {
    p_Var2 = (_MDL *)MmAllocatePagesForMdlEx(0,uVar3,0,param_1,*(int *)(lVar1 + 0xc4),0);
  }
  return p_Var2;
}



===== HdAudBusCreateChildDevice @ 140026a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl HdAudBusCreateChildDevice(struct WDFCHILDLIST__ * __ptr64,struct
   _WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl
HdAudBusCreateChildDevice
          (WDFCHILDLIST__ *param_1,_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER *param_2,
          WDFDEVICE_INIT *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  _HDAudioDeviceExtension *p_Var5;
  undefined8 *_Dst;
  HdaBusInterface *pHVar6;
  char cVar7;
  WDFDEVICE_INIT *pWVar8;
  WDFDEVICE__ *pWVar9;
  _HDAudioDeviceExtension *p_Var10;
  uint uVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  bool bVar14;
  undefined1 auStackY_6a8 [32];
  undefined8 in_stack_fffffffffffff978;
  undefined8 uVar15;
  undefined4 uVar16;
  undefined2 uVar17;
  WDFDEVICE_INIT *local_658;
  undefined8 local_650;
  undefined1 *local_648;
  WDFDEVICE__ *local_640;
  undefined8 local_638;
  undefined8 local_630;
  undefined8 *puStack_628;
  undefined *local_620;
  undefined8 uStack_618;
  undefined8 local_610;
  undefined8 uStack_608;
  longlong local_600;
  longlong local_5f8 [2];
  wchar_t *local_5e8;
  undefined8 local_5e0;
  wchar_t *local_5d8;
  undefined8 local_5d0;
  code *pcStack_5c8;
  undefined8 local_5c0;
  undefined8 uStack_5b8;
  undefined8 local_5b0;
  undefined8 uStack_5a8;
  undefined *local_5a0;
  undefined8 local_598;
  undefined8 uStack_590;
  undefined8 local_588;
  undefined8 uStack_580;
  undefined4 local_578;
  undefined4 local_574;
  undefined4 uStack_570;
  undefined4 local_56c;
  code *local_568;
  code *local_560;
  code *local_558;
  code *local_550;
  code *local_548;
  code *local_540;
  code *local_538;
  code *local_530;
  code *local_528;
  code *local_520;
  code *local_518;
  code *local_510;
  code *local_508;
  code *local_500;
  code *local_4f8;
  code *local_4f0;
  code *local_4e8;
  undefined4 local_4d8;
  undefined4 local_4d4;
  undefined4 uStack_4d0;
  undefined4 local_4cc;
  code *local_4c8;
  code *local_4c0;
  code *local_4b8;
  code *local_4b0;
  code *local_4a8;
  code *local_4a0;
  code *local_498;
  code *local_490;
  code *local_488;
  code *local_480;
  code *local_478;
  code *local_470;
  code *local_468;
  code *local_460;
  code *local_458;
  code *local_450;
  code *local_448;
  code *local_440;
  code *local_438;
  code *local_430;
  undefined8 local_428;
  void *local_420;
  code *local_418;
  code *local_410;
  code *local_408;
  code *local_400;
  code *local_3f8;
  code *local_3f0;
  code *local_3e8;
  code *local_3e0;
  code *local_3d8;
  code *local_3d0;
  code *local_3c8;
  code *local_3c0;
  code *local_3b8;
  code *local_3b0;
  code *local_3a8;
  code *local_3a0;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 uStack_390;
  undefined4 local_38c;
  code *local_388;
  code *local_380;
  code *local_378;
  code *local_370;
  code *local_368;
  code *local_360;
  code *local_358;
  code *local_350;
  code *local_348;
  code *local_340;
  code *local_338;
  code *local_330;
  code *local_328;
  code *local_320;
  code *local_318;
  code *local_310;
  code *local_308;
  code *local_300;
  code *local_2f8;
  code *local_2f0;
  code *local_2e8;
  code *local_2e0;
  undefined4 local_2d8 [10];
  code *local_2b0;
  code *local_2a8;
  undefined4 local_298 [2];
  code *local_290;
  code *local_280;
  code *local_270;
  code *local_268;
  undefined4 local_208;
  undefined8 local_204;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined8 local_1f0;
  undefined8 local_1e8;
  uint local_1e0;
  uint local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined8 local_1bc;
  undefined8 uStack_1b4;
  undefined8 local_1ac;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  wchar_t local_188 [12];
  wchar_t local_170 [20];
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_6a8;
  local_5a0 = (undefined *)0x0;
  local_650 = 0x1000000;
  local_5d0 = 0;
  pcStack_5c8 = (code *)0x0;
  local_648 = local_148;
  builtin_wcsncpy(local_188,L"Settings",9);
  local_5c0 = 0;
  uStack_5b8 = 0;
  local_5e8 = local_188;
  local_5b0 = 0;
  uStack_5a8 = 0;
  builtin_wcsncpy(local_170,L"DeviceLocation",0xf);
  _Dst = (undefined8 *)0x0;
  local_5d8 = local_170;
  local_640 = (WDFDEVICE__ *)0x0;
  local_5f8[1] = 0x120010;
  local_5e0 = 0x1e001c;
  uVar15 = CONCAT44((int)((ulonglong)in_stack_fffffffffffff978 >> 0x20),2);
  local_658 = param_3;
  HDABusWmiLogETW(1,1,'\x04','\x01',2,0,0,0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,0x3e,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
  }
  uVar4 = (**(code **)(WdfFunctions_01025 + 8))(WdfDriverGlobals,param_1);
  p_Var5 = (_HDAudioDeviceExtension *)
           (**(code **)(WdfFunctions_01025 + 0x650))
                     (WdfDriverGlobals,uVar4,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  (**(code **)(WdfFunctions_01025 + 0x210))(WdfDriverGlobals,local_658,0x22);
  (**(code **)(WdfFunctions_01025 + 0x230))(WdfDriverGlobals,local_658,0x180,0);
  (**(code **)(WdfFunctions_01025 + 0x1f0))(WdfDriverGlobals,local_658,0);
  uVar11 = (**(code **)(WdfFunctions_01025 + 0x220))
                     (WdfDriverGlobals,local_658,&SDDL_DEVOBJ_KERNEL_ONLY);
  if ((int)uVar11 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
       (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar7 = '\0';
    }
    bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar7 == '\0') && (!bVar14)) goto LAB_14002874d;
    uVar17 = 0x3f;
  }
  else {
    pwVar13 = L"SGPC_";
    pwVar12 = L"SGPC_";
    if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
      pwVar12 = L"";
    }
    uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),(uint)*(ushort *)(param_2 + 6));
    RtlUnicodeStringPrintf
              ((_UNICODE_STRING *)&local_650,
               (ushort *)L"HDAUDIO\\%sFUNC_%02X&VEN_%04X&DEV_%04X&SUBSYS_%08X&REV_%04X",pwVar12,
               (ulonglong)(byte)param_2[4]);
    uVar11 = (**(code **)(WdfFunctions_01025 + 0x6a0))(WdfDriverGlobals,local_658,&local_650);
    if ((int)uVar11 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar7 = '\0';
      }
      bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar7 == '\0') && (!bVar14)) goto LAB_14002874d;
      uVar17 = 0x40;
    }
    else {
      uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b0))(WdfDriverGlobals,local_658,&local_650);
      pwVar12 = L"SGPC_";
      if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
        pwVar12 = L"";
      }
      uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),(uint)*(ushort *)(param_2 + 6));
      RtlUnicodeStringPrintf
                ((_UNICODE_STRING *)&local_650,
                 (ushort *)L"HDAUDIO\\%sFUNC_%02X&VEN_%04X&DEV_%04X&SUBSYS_%08X",pwVar12,
                 (ulonglong)(byte)param_2[4]);
      uVar1 = (**(code **)(WdfFunctions_01025 + 0x6b0))(WdfDriverGlobals,local_658,&local_650);
      uVar11 = uVar11 | uVar1;
      if (-1 < (int)uVar11) {
        pwVar12 = L"SGPC_";
        if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
          pwVar12 = L"";
        }
        uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                          (uint)(ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18));
        RtlUnicodeStringPrintf
                  ((_UNICODE_STRING *)&local_650,
                   (ushort *)
                   L"HDAUDIO\\%sFUNC_%02X&CTLR_VEN_%04X&CTLR_DEV_%04X&VEN_%04X&DEV_%04X&REV_%04X",
                   pwVar12,(ulonglong)(byte)param_2[4]);
        pWVar8 = local_658;
        uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
        uVar1 = (uint)pWVar8;
        if ((int)uVar11 < 0) {
LAB_14002881d:
          if (-1 < (int)uVar11) goto LAB_14002874d;
        }
        else {
          pwVar12 = L"SGPC_";
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                            (uint)(ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&CTLR_VEN_%04X&VEN_%04X&DEV_%04X&REV_%04X",
                     pwVar12,(ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),(uint)*(ushort *)(param_2 + 6));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&VEN_%04X&DEV_%04X&REV_%04X",pwVar12,
                     (ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                            (uint)(ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&CTLR_VEN_%04X&CTLR_DEV_%04X&VEN_%04X&DEV_%04X"
                     ,pwVar12,(ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                            (uint)(ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&CTLR_VEN_%04X&VEN_%04X&DEV_%04X",pwVar12,
                     (ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),(uint)*(ushort *)(param_2 + 6));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&VEN_%04X&DEV_%04X",pwVar12,
                     (ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar2 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          uVar11 = uVar11 | uVar2;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                            (uint)(ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&CTLR_VEN_%04X&CTLR_DEV_%04X&VEN_%04X",pwVar12,
                     (ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                            (uint)(ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&CTLR_VEN_%04X&VEN_%04X",pwVar12,
                     (ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),(uint)*(ushort *)(param_2 + 6));
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,(ushort *)L"HDAUDIO\\%sFUNC_%02X&VEN_%04X",
                     pwVar12,(ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar2 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          uVar11 = uVar11 | uVar2;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                            (uint)(ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&CTLR_VEN_%04X&CTLR_DEV_%04X",pwVar12,
                     (ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          pwVar12 = L"SGPC_";
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),
                            (uint)(ushort)((ulonglong)*(undefined8 *)p_Var5 >> 0x18));
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar12 = L"";
          }
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,(ushort *)L"HDAUDIO\\%sFUNC_%02X&CTLR_VEN_%04X",
                     pwVar12,(ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          if (param_2[0x14] == (_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER)0x0) {
            pwVar13 = L"";
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar15 >> 0x20),(uint)*(ushort *)(param_2 + 6));
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,
                     (ushort *)L"HDAUDIO\\%sFUNC_%02X&GF&VEN_%04X&DEV_%04X&SUBSYS_%08X&REV_%04X",
                     pwVar13,(ulonglong)(byte)param_2[4]);
          pWVar8 = local_658;
          uVar2 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          uVar1 = (uint)pWVar8;
          uVar11 = uVar11 | uVar2;
          if ((int)uVar11 < 0) goto LAB_14002881d;
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,(ushort *)L"HDAUDIO\\FUNC_%02X",
                     (ulonglong)(byte)param_2[4]);
          uVar1 = (**(code **)(WdfFunctions_01025 + 0x6b8))(WdfDriverGlobals,local_658,&local_650);
          if ((int)(uVar1 | uVar11) < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
               (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar7 = '\0';
            }
            bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar7 != '\0') || (bVar14)) {
              uVar17 = 0x42;
LAB_1400274c3:
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar14,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,uVar17,
                         &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
            }
LAB_1400274e1:
            uVar11 = 0xc000009a;
            goto LAB_14002874d;
          }
          RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_650,(ushort *)L"%04X",
                     (ulonglong)CONCAT11(param_2[0x12],param_2[0x13]));
          iVar3 = (**(code **)(WdfFunctions_01025 + 0x6a8))(WdfDriverGlobals,local_658,&local_650);
          if (iVar3 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
               (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar7 = '\0';
            }
            bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar7 != '\0') || (bVar14)) {
              uVar17 = 0x43;
              goto LAB_1400274c3;
            }
            goto LAB_1400274e1;
          }
          local_638 = 0;
          uVar15 = 0;
          iVar3 = (**(code **)(WdfFunctions_01025 + 0x180))(WdfDriverGlobals,uVar4,2,0x20000);
          uVar4 = local_638;
          if (iVar3 < 0) {
LAB_140027b47:
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
               (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar7 = '\0';
            }
            if ((cVar7 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_D
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,0x47,
                         &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar3);
            }
          }
          else {
            uVar15 = 0;
            iVar3 = (**(code **)(WdfFunctions_01025 + 0x728))
                              (WdfDriverGlobals,local_638,local_5f8 + 1,0x20000);
            (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,uVar4);
            if (iVar3 < 0) goto LAB_140027b47;
            local_600 = 0;
            local_5f8[0] = 0;
            local_588 = 0;
            uStack_580 = 0;
            local_598 = 0;
            uStack_590 = 0;
            uVar11 = (**(code **)(WdfFunctions_01025 + 0x9a0))(WdfDriverGlobals,0,0,&local_600);
            uVar1 = (**(code **)(WdfFunctions_01025 + 0x9a0))(WdfDriverGlobals,0,0,local_5f8);
            if (-1 < (int)(uVar1 | uVar11)) {
              RtlUnicodeStringPrintf
                        ((_UNICODE_STRING *)&local_650,(ushort *)L"DeviceDescription_FUNC_%02X",
                         (ulonglong)(byte)param_2[4]);
              iVar3 = (**(code **)(WdfFunctions_01025 + 0x778))
                                (WdfDriverGlobals,local_638,&local_650,local_600);
              if (iVar3 < 0) {
                RtlUnicodeStringPrintf
                          ((_UNICODE_STRING *)&local_650,(ushort *)L"DeviceDescription_Default");
                iVar3 = (**(code **)(WdfFunctions_01025 + 0x778))
                                  (WdfDriverGlobals,local_638,&local_650,local_600);
                if (-1 < iVar3) goto LAB_140027786;
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                   (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar7 = '\0';
                }
                bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                if ((cVar7 != '\0') || (bVar14)) {
                  uVar17 = 0x46;
                  goto LAB_140027914;
                }
              }
              else {
LAB_140027786:
                iVar3 = (**(code **)(WdfFunctions_01025 + 0x778))
                                  (WdfDriverGlobals,local_638,&local_5e0,local_5f8[0]);
                if (iVar3 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    cVar7 = '\0';
                  }
                  if ((cVar7 != '\0') ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    WPP_RECORDER_AND_TRACE_SF_D
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,0x44,
                               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar3);
                  }
                }
                uVar16 = (undefined4)((ulonglong)uVar15 >> 0x20);
                (**(code **)(WdfFunctions_01025 + 0x9a8))(WdfDriverGlobals,local_600,&local_588);
                (**(code **)(WdfFunctions_01025 + 0x9a8))(WdfDriverGlobals,local_5f8[0],&local_598);
                (**(code **)(WdfFunctions_01025 + 0x6c8))(WdfDriverGlobals,local_658,0x800);
                uVar15 = CONCAT44(uVar16,0x800);
                iVar3 = (**(code **)(WdfFunctions_01025 + 0x6c0))
                                  (WdfDriverGlobals,local_658,&local_588,&local_598);
                if (iVar3 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    cVar7 = '\0';
                  }
                  bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                  if ((cVar7 != '\0') || (bVar14)) {
                    uVar17 = 0x45;
LAB_140027914:
                    WPP_RECORDER_AND_TRACE_SF_D
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar14,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,uVar17,
                               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar3);
                  }
                }
              }
              (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,local_638);
            }
            if (local_600 != 0) {
              (**(code **)(WdfFunctions_01025 + 0x680))(WdfDriverGlobals);
            }
            if (local_5f8[0] != 0) {
              (**(code **)(WdfFunctions_01025 + 0x680))(WdfDriverGlobals);
            }
          }
          memset(local_298,0,0x90);
          local_290 = HdAudBusChildPowerUp;
          local_280 = HdAudBusChildPowerDown;
          local_270 = HdAudBusChildPrepareHardware;
          local_268 = HdAudBusChildReleaseHardware;
          local_298[0] = 0x90;
          (**(code **)(WdfFunctions_01025 + 0x1b8))(WdfDriverGlobals,local_658,local_298);
          memset(local_2d8,0,0x40);
          local_2b0 = HdAudBusEnableWakeForChildDevice;
          local_2a8 = HdAudBusDisableWakeForChildDevice;
          local_2d8[0] = 0x40;
          (**(code **)(WdfFunctions_01025 + 0x698))(WdfDriverGlobals,local_658,local_2d8);
          local_5a0 = PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070;
          local_5d0 = 0x38;
          pcStack_5c8 = HdAudBusCleanupChildDevice;
          local_5c0 = 0;
          local_5b0 = 0;
          uStack_5a8 = 0;
          uStack_5b8 = 0x100000001;
          uVar11 = (**(code **)(WdfFunctions_01025 + 600))
                             (WdfDriverGlobals,&local_658,&local_5d0,&local_640);
          if ((int)uVar11 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
               (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar7 = '\0';
            }
            if ((cVar7 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_D
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,0x48,
                         &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)uVar11);
            }
            goto LAB_14002874d;
          }
          local_1dc = (uint)(byte)param_2[0x12];
          local_1e0 = (uint)CONCAT11(param_2[0x12],param_2[0x13]);
          local_208 = 0x30;
          local_204 = 2;
          local_1f8 = 2;
          local_1f0 = 2;
          local_1fc = 0;
          local_1f4 = 0;
          local_1e8 = 0;
          (**(code **)(WdfFunctions_01025 + 0x298))(WdfDriverGlobals,local_640,&local_208);
          memset(&local_1d8,0,0x50);
          local_198 = 0xffffffff;
          local_194 = 0xffffffff;
          local_190 = 0xffffffff;
          local_18c = 5;
          local_1bc = 0x500000005;
          uStack_1b4 = 0x500000005;
          local_1d8 = 0x50;
          local_1ac = 0x500000005;
          local_1a4 = 5;
          local_1d4 = 2;
          local_1d0 = 2;
          local_1cc = 2;
          local_1c8 = 2;
          local_1c4 = 2;
          local_1c0 = 2;
          local_1a0 = *(undefined4 *)(p_Var5 + 0x4c);
          local_19c = *(undefined4 *)(p_Var5 + 0x48);
          (**(code **)(WdfFunctions_01025 + 0x2a0))(WdfDriverGlobals,local_640,&local_1d8);
          _Dst = (undefined8 *)
                 (**(code **)(WdfFunctions_01025 + 0x650))
                           (WdfDriverGlobals,local_640,
                            PTR__WDF_ChildDeviceExtension_TYPE_INFO_14001d070);
          memset(_Dst,0,0x48);
          _Dst[5] = p_Var5;
          *(undefined1 *)((longlong)_Dst + 0x43) = 1;
          *(_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER *)(_Dst + 8) = param_2[0x12];
          *(_WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER *)((longlong)_Dst + 0x41) = param_2[0x14];
          *_Dst = 0;
          local_630 = 0x30;
          puStack_628 = (undefined8 *)0x0;
          local_620 = &GUID_BUS_INTERFACE_STANDARD;
          uStack_608 = 0;
          local_610 = 0;
          uStack_618 = 1;
          pWVar9 = local_640;
          uVar11 = (**(code **)(WdfFunctions_01025 + 0x720))(WdfDriverGlobals,local_640,&local_630);
          uVar1 = (uint)pWVar9;
          if ((int)uVar11 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
               (uVar1 = (uint)CONCAT71((int7)((ulonglong)pWVar9 >> 8),1),
               (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              uVar1 = uVar1 & 0xffffff00;
            }
            bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if (((char)uVar1 != '\0') || (bVar14)) {
              uVar17 = 0x49;
              goto LAB_140027e13;
            }
            goto LAB_14002883b;
          }
          local_428 = 0x1000090;
          local_418 = HdaBusInterface::InterfaceReference;
          local_3f0 = HdaBusInterface::ChangeBandwidthAllocation;
          local_410 = HdaBusInterface::InterfaceDereference;
          local_3d8 = HdaBusInterface::FreeDmaEngine;
          local_408 = HdaBusInterface::TransferCodecVerbs;
          local_3d0 = HdaBusInterface::SetDmaEngineState;
          local_400 = HdaBusInterface::AllocateCaptureDmaEngine;
          local_3e8 = HdaBusInterface::AllocateDmaBuffer;
          local_3f8 = HdaBusInterface::AllocateRenderDmaEngine;
          local_3e0 = HdaBusInterface::FreeDmaBuffer;
          local_574 = 0;
          uStack_570 = 0;
          local_56c = 0;
          local_3c8 = HdaBusInterface::GetWallClockRegister;
          local_568 = HdaBusInterface::InterfaceReference;
          local_3c0 = HdaBusInterface::GetLinkPositionRegister;
          local_560 = HdaBusInterface::InterfaceDereference;
          local_3b8 = HdaBusInterface::RegisterEventCallback;
          local_558 = HdaBusInterface::TransferCodecVerbs;
          local_3b0 = HdaBusInterface::UnregisterEventCallback;
          local_550 = HdaBusInterface::AllocateCaptureDmaEngine;
          local_3a8 = HdaBusInterface::GetDeviceInformation;
          local_548 = HdaBusInterface::AllocateRenderDmaEngine;
          local_538 = HdaBusInterfaceBdl::AllocateContiguousDmaBuffer;
          local_530 = HdaBusInterfaceBdl::SetupDmaEngineWithBdl;
          local_528 = HdaBusInterfaceBdl::FreeContiguousDmaBuffer;
          local_4d4 = 0;
          uStack_4d0 = 0;
          local_4cc = 0;
          local_4c8 = HdaBusInterface::InterfaceReference;
          local_4c0 = HdaBusInterface::InterfaceDereference;
          local_4b8 = HdaBusInterface::TransferCodecVerbs;
          local_4b0 = HdaBusInterface::AllocateCaptureDmaEngine;
          local_4a8 = HdaBusInterface::AllocateRenderDmaEngine;
          local_3a0 = HdaBusInterface::GetResourceInformation;
          local_578 = 0x1000098;
          local_540 = HdaBusInterface::ChangeBandwidthAllocation;
          local_520 = HdaBusInterface::FreeDmaEngine;
          local_518 = HdaBusInterface::SetDmaEngineState;
          local_510 = HdaBusInterface::GetWallClockRegister;
          local_508 = HdaBusInterface::GetLinkPositionRegister;
          local_500 = HdaBusInterface::RegisterEventCallback;
          local_4f8 = HdaBusInterface::UnregisterEventCallback;
          local_4f0 = HdaBusInterface::GetDeviceInformation;
          local_4e8 = HdaBusInterface::GetResourceInformation;
          local_4d8 = 0x10000b0;
          local_4a0 = HdaBusInterface::ChangeBandwidthAllocation;
          local_498 = HdaBusInterface::AllocateDmaBuffer;
          local_490 = HdaBusInterface::FreeDmaBuffer;
          local_488 = HdaBusInterface::FreeDmaEngine;
          local_480 = HdaBusInterface::SetDmaEngineState;
          local_478 = HdaBusInterface::GetWallClockRegister;
          local_394 = 0;
          uStack_390 = 0;
          local_38c = 0;
          local_470 = HdaBusInterface::GetLinkPositionRegister;
          local_340 = HdaBusInterface::SetDmaEngineState;
          local_338 = HdaBusInterface::GetWallClockRegister;
          local_388 = HdaBusInterface::InterfaceReference;
          local_330 = HdaBusInterface::GetLinkPositionRegister;
          local_380 = HdaBusInterface::InterfaceDereference;
          local_440 = HdaBusInterface2::FreeDmaBufferWithNotification;
          local_378 = HdaBusInterface::TransferCodecVerbs;
          local_438 = HdaBusInterface2::RegisterNotificationEvent;
          local_370 = HdaBusInterface::AllocateCaptureDmaEngine;
          local_368 = HdaBusInterface::AllocateRenderDmaEngine;
          local_360 = HdaBusInterface::ChangeBandwidthAllocation;
          local_358 = HdaBusInterface::AllocateDmaBuffer;
          local_350 = HdaBusInterface::FreeDmaBuffer;
          local_348 = HdaBusInterface::FreeDmaEngine;
          local_2e8 = HdaBusInterface3::RegisterNotificationCallback;
          local_430 = HdaBusInterface2::UnregisterNotificationEvent;
          local_300 = HdaBusInterface2::FreeDmaBufferWithNotification;
          local_2f8 = HdaBusInterface2::RegisterNotificationEvent;
          p_Var10 = (_HDAudioDeviceExtension *)0x200;
          local_2f0 = HdaBusInterface2::UnregisterNotificationEvent;
          local_2e0 = HdaBusInterface3::UnregisterNotificationCallback;
          local_468 = HdaBusInterface::RegisterEventCallback;
          local_460 = HdaBusInterface::UnregisterEventCallback;
          local_458 = HdaBusInterface::GetDeviceInformation;
          local_450 = HdaBusInterface::GetResourceInformation;
          local_448 = HdaBusInterface2::AllocateDmaBufferWithNotification;
          local_398 = 0x10000c0;
          local_328 = HdaBusInterface::RegisterEventCallback;
          local_320 = HdaBusInterface::UnregisterEventCallback;
          local_318 = HdaBusInterface::GetDeviceInformation;
          local_310 = HdaBusInterface::GetResourceInformation;
          local_308 = HdaBusInterface2::AllocateDmaBufferWithNotification;
          pHVar6 = operator_new(0x890,0x200,0x44427a41);
          if (pHVar6 == (HdaBusInterface *)0x0) {
            local_420 = (void *)0x0;
          }
          else {
            p_Var10 = p_Var5;
            local_420 = (void *)HdaBusInterface::HdaBusInterface(pHVar6,p_Var5,local_640);
          }
          uVar1 = (uint)p_Var10;
          _Dst[1] = local_420;
          if (_Dst[1] == 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
               (uVar1 = (uint)CONCAT71((int7)((ulonglong)p_Var10 >> 8),1),
               (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              uVar1 = uVar1 & 0xffffff00;
            }
            bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if (((char)uVar1 != '\0') || (bVar14)) {
              uVar17 = 0x4a;
LAB_140028244:
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)uVar1,bVar14,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,uVar17,
                         &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
            }
LAB_140028262:
            uVar11 = 0xc000009a;
          }
          else {
            p_Var10 = (_HDAudioDeviceExtension *)0x200;
            pHVar6 = operator_new(0x890,0x200,0x44427a41);
            if (pHVar6 == (HdaBusInterface *)0x0) {
              pHVar6 = (HdaBusInterface *)0x0;
            }
            else {
              p_Var10 = p_Var5;
              HdaBusInterface::HdaBusInterface(pHVar6,p_Var5,local_640);
            }
            uVar1 = (uint)p_Var10;
            _Dst[4] = pHVar6;
            uStack_570 = SUB84(pHVar6,0);
            local_56c = (undefined4)((ulonglong)pHVar6 >> 0x20);
            if (_Dst[4] == 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 (uVar1 = (uint)CONCAT71((int7)((ulonglong)p_Var10 >> 8),1),
                 (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                uVar1 = uVar1 & 0xffffff00;
              }
              bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if (((char)uVar1 != '\0') || (bVar14)) {
                uVar17 = 0x4b;
                goto LAB_140028244;
              }
              goto LAB_140028262;
            }
            p_Var10 = (_HDAudioDeviceExtension *)0x200;
            pHVar6 = operator_new(0x890,0x200,0x44427a41);
            if (pHVar6 == (HdaBusInterface *)0x0) {
              pHVar6 = (HdaBusInterface *)0x0;
            }
            else {
              p_Var10 = p_Var5;
              HdaBusInterface::HdaBusInterface(pHVar6,p_Var5,local_640);
            }
            uVar1 = (uint)p_Var10;
            _Dst[2] = pHVar6;
            uStack_4d0 = SUB84(pHVar6,0);
            local_4cc = (undefined4)((ulonglong)pHVar6 >> 0x20);
            if (_Dst[2] == 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 (uVar1 = (uint)CONCAT71((int7)((ulonglong)p_Var10 >> 8),1),
                 (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                uVar1 = uVar1 & 0xffffff00;
              }
              bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if (((char)uVar1 != '\0') || (bVar14)) {
                uVar17 = 0x4c;
                goto LAB_140028244;
              }
              goto LAB_140028262;
            }
            p_Var10 = (_HDAudioDeviceExtension *)0x200;
            pHVar6 = operator_new(0x890,0x200,0x44427a41);
            if (pHVar6 == (HdaBusInterface *)0x0) {
              pHVar6 = (HdaBusInterface *)0x0;
            }
            else {
              HdaBusInterface::HdaBusInterface(pHVar6,p_Var5,local_640);
              p_Var10 = p_Var5;
            }
            uVar1 = (uint)p_Var10;
            _Dst[3] = pHVar6;
            uStack_390 = SUB84(pHVar6,0);
            local_38c = (undefined4)((ulonglong)pHVar6 >> 0x20);
            if (_Dst[3] == 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 (uVar1 = (uint)CONCAT71((int7)((ulonglong)p_Var10 >> 8),1),
                 (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                uVar1 = uVar1 & 0xffffff00;
              }
              bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if (((char)uVar1 != '\0') || (bVar14)) {
                uVar17 = 0x4d;
                goto LAB_140028244;
              }
              goto LAB_140028262;
            }
            puStack_628 = &local_428;
            local_620 = &GUID_HDAUDIO_BUS_INTERFACE;
            local_630 = 0x30;
            uStack_618 = 0;
            uStack_608 = 0;
            local_610 = 0;
            pWVar9 = local_640;
            uVar11 = (**(code **)(WdfFunctions_01025 + 0x720))
                               (WdfDriverGlobals,local_640,&local_630);
            uVar1 = (uint)pWVar9;
            if ((int)uVar11 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                 (uVar1 = (uint)CONCAT71((int7)((ulonglong)pWVar9 >> 8),1),
                 (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                uVar1 = uVar1 & 0xffffff00;
              }
              bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if (((char)uVar1 != '\0') || (bVar14)) {
                uVar17 = 0x4e;
LAB_140027e13:
                WPP_RECORDER_AND_TRACE_SF_D
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)uVar1,bVar14,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,uVar17,
                           &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)uVar11);
              }
            }
            else {
              puStack_628 = (undefined8 *)&local_578;
              local_620 = &GUID_HDAUDIO_BUS_INTERFACE_BDL;
              local_630 = 0x30;
              uStack_618 = 0;
              uStack_608 = 0;
              local_610 = 0;
              pWVar9 = local_640;
              uVar11 = (**(code **)(WdfFunctions_01025 + 0x720))
                                 (WdfDriverGlobals,local_640,&local_630);
              uVar1 = (uint)pWVar9;
              if ((int)uVar11 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                   (uVar1 = (uint)CONCAT71((int7)((ulonglong)pWVar9 >> 8),1),
                   (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  uVar1 = uVar1 & 0xffffff00;
                }
                bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                if (((char)uVar1 != '\0') || (bVar14)) {
                  uVar17 = 0x4f;
                  goto LAB_140027e13;
                }
              }
              else {
                puStack_628 = (undefined8 *)&local_4d8;
                local_620 = &GUID_HDAUDIO_BUS_INTERFACE_V2;
                local_630 = 0x30;
                uStack_618 = 0;
                uStack_608 = 0;
                local_610 = 0;
                pWVar9 = local_640;
                uVar11 = (**(code **)(WdfFunctions_01025 + 0x720))
                                   (WdfDriverGlobals,local_640,&local_630);
                uVar1 = (uint)pWVar9;
                if ((int)uVar11 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                     (uVar1 = (uint)CONCAT71((int7)((ulonglong)pWVar9 >> 8),1),
                     (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    uVar1 = uVar1 & 0xffffff00;
                  }
                  bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                  if (((char)uVar1 != '\0') || (bVar14)) {
                    uVar17 = 0x50;
                    goto LAB_140027e13;
                  }
                }
                else {
                  puStack_628 = (undefined8 *)&local_398;
                  local_620 = &GUID_HDAUDIO_BUS_INTERFACE_V3;
                  local_630 = 0x30;
                  uStack_618 = 0;
                  uStack_608 = 0;
                  local_610 = 0;
                  pWVar9 = local_640;
                  uVar11 = (**(code **)(WdfFunctions_01025 + 0x720))
                                     (WdfDriverGlobals,local_640,&local_630);
                  uVar1 = (uint)pWVar9;
                  if (-1 < (int)uVar11) {
                    HdaBusInterface::InterfaceReference(local_420);
                    HdaBusInterface::InterfaceReference((void *)CONCAT44(local_56c,uStack_570));
                    HdaBusInterface::InterfaceReference((void *)CONCAT44(local_4cc,uStack_4d0));
                    HdaBusInterface::InterfaceReference((void *)CONCAT44(local_38c,uStack_390));
                    uVar11 = 0;
                    goto LAB_14002874d;
                  }
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
                     (uVar1 = (uint)CONCAT71((int7)((ulonglong)pWVar9 >> 8),1),
                     (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    uVar1 = uVar1 & 0xffffff00;
                  }
                  bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                  if (((char)uVar1 != '\0') || (bVar14)) {
                    uVar17 = 0x51;
                    goto LAB_140027e13;
                  }
                }
              }
            }
          }
        }
LAB_14002883b:
        if (_Dst != (undefined8 *)0x0) {
          if ((HdaBusInterface *)_Dst[1] != (HdaBusInterface *)0x0) {
            HdaBusInterface::_scalar_deleting_destructor_((HdaBusInterface *)_Dst[1],uVar1);
            _Dst[1] = 0;
          }
          if ((HdaBusInterface *)_Dst[4] != (HdaBusInterface *)0x0) {
            HdaBusInterface::_scalar_deleting_destructor_((HdaBusInterface *)_Dst[4],uVar1);
            _Dst[4] = 0;
          }
          if ((HdaBusInterface *)_Dst[2] != (HdaBusInterface *)0x0) {
            HdaBusInterface::_scalar_deleting_destructor_((HdaBusInterface *)_Dst[2],uVar1);
            _Dst[2] = 0;
          }
          if ((HdaBusInterface *)_Dst[3] != (HdaBusInterface *)0x0) {
            HdaBusInterface::_scalar_deleting_destructor_((HdaBusInterface *)_Dst[3],uVar1);
            _Dst[3] = 0;
          }
        }
        goto LAB_14002874d;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
         (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar7 = '\0';
      }
      bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar7 == '\0') && (!bVar14)) goto LAB_14002874d;
      uVar17 = 0x41;
    }
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar14,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,uVar17,
             &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
LAB_14002874d:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     (cVar7 = '\x01',
     (int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)(((int)uVar11 >> 0x1f & 0xfffffffeU) + 4))) {
    cVar7 = '\0';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0xd,0x52,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)local_640,(char)uVar11);
  }
  HDABusWmiLogETW(1,1,'\x04','\x01',2,0xff,0,uVar11);
  return uVar11;
}



===== _tlgEnableCallback @ 1400288a0 =====

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



===== HDAudBusLowPowerCallback @ 140028920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HDAudBusLowPowerCallback(struct _GUID const * __ptr64,void * __ptr64,unsigned
   long,void * __ptr64) */

long __cdecl HDAudBusLowPowerCallback(_GUID *param_1,void *param_2,ulong param_3,void *param_4)

{
  uchar uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  longlong lVar5;
  longlong lVar6;
  char cVar7;
  undefined4 in_stack_ffffffffffffffb8;
  undefined4 in_stack_ffffffffffffffbc;
  
  lVar4 = 0;
  bVar2 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),2,0x32,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_4);
  }
  if (((param_2 == (void *)0x0) || (param_3 != 4)) || (param_4 == (void *)0x0)) {
    lVar4 = -0x3ffffff3;
  }
  else {
    lVar5 = (**(code **)(WdfFunctions_01025 + 0x650))
                      (WdfDriverGlobals,param_4,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098)
    ;
    if ((lVar5 != 0) && (lVar5 = *(longlong *)(lVar5 + 0x10), lVar5 != 0)) {
      in_stack_ffffffffffffffb8 = 0x20;
      iVar3 = IoAcquireRemoveLockEx(lVar5 + 8,param_4,"",1);
      if (iVar3 == 0) {
        lVar4 = 0;
        if (((*(int *)param_1 == -0x1edcc66d) && (*(int *)(param_1 + 4) == 0x470feaa4)) &&
           ((*(int *)(param_1 + 8) == 0x51a3e79d &&
            ((*(int *)(param_1 + 0xc) == 0x71fbb6c1 &&
             (lVar6 = (**(code **)(WdfFunctions_01025 + 0x650))
                                (WdfDriverGlobals,param_4,
                                 PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098), lVar6 != 0)))
            ))) {
          uVar1 = *(uchar *)param_2;
          *(uchar *)(lVar6 + 0xbd) = uVar1;
          if (*(char *)(lVar6 + 0xbc) != '\0') {
            lVar4 = HdAudBusUpdateS0IdleSettings(param_4,uVar1);
          }
        }
        IoReleaseRemoveLockEx(lVar5 + 8,param_4,0x20);
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
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),2,0x33,
                     &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)lVar5,(char)iVar3);
        }
        lVar4 = 0;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     ((int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((lVar4 >> 0x1f & 0xfffffffeU) + 4))) {
    bVar2 = false;
  }
  if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),2,0x34,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_4,(char)lVar4);
  }
  return 0;
}



===== FreeBuffer @ 140028c3c =====

/* private: static void __cdecl HdaController::FreeBuffer(struct _MDL * __ptr64) */

void __cdecl HdaController::FreeBuffer(_MDL *param_1)

{
  MmFreePagesFromMdlEx(param_1,1);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== AllocateContiguousBuffer @ 140028c74 =====

/* private: void * __ptr64 __cdecl HdaController::AllocateContiguousBuffer(unsigned __int64,enum
   _MEMORY_CACHING_TYPE) __ptr64 */

void * __thiscall
HdaController::AllocateContiguousBuffer
          (HdaController *this,__uint64 param_1,_MEMORY_CACHING_TYPE param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    uVar1 = 0x204;
  }
  else {
    if (param_2 != 2) {
      return (void *)0x0;
    }
    uVar1 = 0x404;
  }
  if (this[0x80] == (HdaController)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0xffffffffffffffff;
  }
  pvVar2 = (void *)MmAllocateContiguousNodeMemory(param_1,0x1000000,uVar3,0,uVar1,0x80000000);
  return pvVar2;
}



===== EvtIrpPreprocessQueryDevRelations @ 140028cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong EvtIrpPreprocessQueryDevRelations(WDFDEVICE__ *param_1,_IRP *param_2)

{
  char *pcVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  char cVar5;
  char cVar6;
  undefined8 in_stack_ffffffffffffffd8;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  if ((*pcVar1 == '\x1b') && (pcVar1[1] == '\a')) {
    if (*(int *)(pcVar1 + 8) == 2) {
      cVar6 = '\x01';
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
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
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,2,0xbd,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
      }
      uVar3 = HandleQdrForPowerRelations(param_1,param_2);
      if ((int)uVar3 < 0) goto LAB_140028d1d;
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
    uVar4 = (**(code **)(WdfFunctions_01025 + 0x110))(WdfDriverGlobals,param_1,param_2);
  }
  else {
    uVar3 = 0xc0000010;
LAB_140028d1d:
    *(uint *)(param_2 + 0x30) = uVar3;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = (ulonglong)uVar3;
  }
  return uVar4;
}



===== RegisterEventCallback @ 140028e3c =====

/* public: long __cdecl HdaController::RegisterEventCallback(struct WDFDEVICE__ * __ptr64,unsigned
   char,void (__cdecl*)(struct _HDAUDIO_CODEC_RESPONSE,void * __ptr64),void * __ptr64,unsigned char
   * __ptr64) __ptr64 */

long __thiscall
HdaController::RegisterEventCallback
          (HdaController *this,WDFDEVICE__ *param_1,uchar param_2,
          _func_void__HDAUDIO_CODEC_RESPONSE_void_ptr *param_3,void *param_4,uchar *param_5)

{
  byte bVar1;
  char cVar2;
  long lVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 in_stack_ffffffffffffffc8;
  
  uVar4 = (ulonglong)param_2;
  bVar1 = FindCodecResponseTag(this,(long *)(this + uVar4 * 8 + 0x1b60));
  *param_5 = bVar1;
  if (bVar1 == 0xff) {
    lVar3 = -0x3fffff66;
  }
  else {
    if ((bVar1 < 0x40) && (param_2 < 0xf)) {
      lVar5 = uVar4 * 0x40;
      *(_func_void__HDAUDIO_CODEC_RESPONSE_void_ptr **)
       (this + ((ulonglong)bVar1 + lVar5) * 0x20 + 0x1bd8) = param_3;
      *(void **)(this + ((ulonglong)*param_5 + 0xdf + lVar5) * 0x20) = param_4;
      this[((ulonglong)*param_5 + lVar5) * 0x20 + 0x1be8] = (HdaController)0x1;
      *(WDFDEVICE__ **)(this + ((ulonglong)*param_5 + lVar5) * 0x20 + 0x1bf0) = param_1;
      return 0;
    }
    lVar3 = -0x3fffffff;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xa5,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar3);
  }
  return lVar3;
}



===== HdAudBusWakeTriggered @ 140028f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl HdAudBusWakeTriggered(struct WDFDEVICE__ * __ptr64) */

void __cdecl HdAudBusWakeTriggered(WDFDEVICE__ *param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,2,0x3d,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  if (*(HdaController **)(lVar1 + 0x10) != (HdaController *)0x0) {
    HdaController::CompleteWaitWakeRequests(*(HdaController **)(lVar1 + 0x10));
  }
  return;
}



===== FreeContiguousBuffer @ 140029048 =====

/* private: static void __cdecl HdaController::FreeContiguousBuffer(void * __ptr64,unsigned
   __int64,enum _MEMORY_CACHING_TYPE) */

void __cdecl
HdaController::FreeContiguousBuffer(void *param_1,__uint64 param_2,_MEMORY_CACHING_TYPE param_3)

{
  MmFreeContiguousMemorySpecifyCache();
  return;
}



===== UnregisterEventCallback @ 140029064 =====

/* public: long __cdecl HdaController::UnregisterEventCallback(unsigned char,unsigned char) __ptr64
    */

long __thiscall
HdaController::UnregisterEventCallback(HdaController *this,uchar param_1,uchar param_2)

{
  uchar uVar1;
  char cVar2;
  long lVar3;
  undefined8 in_stack_ffffffffffffffc8;
  
  uVar1 = FreeCodecResponseTag(this,(long *)(this + (ulonglong)param_1 * 8 + 0x1b60),param_2);
  if (uVar1 == '\0') {
    lVar3 = -0x3ffffff3;
  }
  else {
    if ((param_2 < 0x40) && (param_1 < 0xf)) {
      this[((ulonglong)param_1 * 0x40 + (ulonglong)param_2) * 0x20 + 0x1be8] = (HdaController)0x0;
      return 0;
    }
    lVar3 = -0x3fffffff;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xa6,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar3);
  }
  return lVar3;
}



===== StopHdAudioFlagsRegistryNotification @ 140029158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl StopHdAudioFlagsRegistryNotification(struct _HDAudioDeviceExtension * __ptr64) */

void __cdecl StopHdAudioFlagsRegistryNotification(_HDAudioDeviceExtension *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  bVar1 = true;
  LOCK();
  bVar2 = *(longlong *)(param_1 + 0x128) == 0;
  if (bVar2) {
    *(longlong *)(param_1 + 0x128) = 0;
  }
  UNLOCK();
  if (!bVar2) {
    KeInitializeEvent(&local_28,1,0);
    (**(code **)(WdfFunctions_01025 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x120),0);
    *(undefined8 *)(param_1 + 0x160) = 0;
    if (*(longlong *)(param_1 + 0x128) != 0) {
      (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals);
      *(undefined8 *)(param_1 + 0x128) = 0;
      *(undefined8 **)(param_1 + 0x160) = &local_28;
    }
    (**(code **)(WdfFunctions_01025 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x120));
    if (*(longlong *)(param_1 + 0x160) != 0) {
      in_stack_ffffffffffffffb8 = 0;
      KeWaitForSingleObject(&local_28,0,0,0);
      *(undefined8 *)(param_1 + 0x160) = 0;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,4,0xf,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
  }
  return;
}



===== DriverEntry @ 1400292d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,ushort *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  char cVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  code *local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined *local_18;
  
  _DAT_14001d388 = 1;
  _WPP_MAIN_CB = 0;
  DAT_14001d368 = &WPP_ThisDir_CTLGUID_HDAudio;
  DAT_14001d370 = 0;
  _DAT_14001d380 = 0;
  _DAT_14001d3a0 = 0;
  _DAT_14001d3a8 = 0;
  WppLoadTracingSupport();
  _DAT_14001d380 = 0;
  WppInitKm(param_1,param_2);
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  wil_InitializeFeatureStaging();
  puVar6 = &local_68;
  local_18 = PTR__WDF_DRIVER_CONTEXT_TYPE_INFO_14001d018;
  local_48 = 0x38;
  local_38 = 0;
  local_40 = HDAusBusEvtDriverContextCleanup;
  local_30 = 1;
  local_60 = HdAudBusAddDevice;
  local_28 = 0;
  uStack_20 = 0;
  local_2c = 1;
  local_68 = 0x20;
  local_58 = 0;
  uStack_50 = 0;
  uVar3 = WdfDriverGlobals;
  uVar1 = (**(code **)(WdfFunctions_01025 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,&local_48,puVar6,0);
  uVar5 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,1,0xb4,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)uVar1);
    }
    WppCleanupKm(param_1);
    uVar3 = DAT_14001d0f8;
    DAT_14001d0f8 = 0;
    DAT_14001d0d8 = 0;
    EtwUnregister(uVar3);
    wil_UninitializeFeatureStaging();
  }
  else {
    *(code **)(param_1 + 0x128) = HDAudBusWmiSystemControl;
    uVar2 = DupUnicodeString(uVar3,param_2);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar4 = '\0';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,1,0xb5,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)uVar2);
      }
    }
  }
  return uVar5;
}



===== WppLoadTracingSupport @ 14002953c =====

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



===== ArmHdAudioFlagsRegistryNotification @ 140029680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ArmHdAudioFlagsRegistryNotification(struct _HDAudioDeviceExtension * __ptr64) */

long __cdecl ArmHdAudioFlagsRegistryNotification(_HDAudioDeviceExtension *param_1)

{
  int iVar1;
  undefined8 uVar2;
  char cVar3;
  _HDAudioDeviceExtension *p_Var4;
  undefined2 in_stack_ffffffffffffffd8;
  undefined1 uVar5;
  
  uVar5 = (undefined1)((ushort)in_stack_ffffffffffffffd8 >> 8);
  *(_HDAudioDeviceExtension **)(param_1 + 0x148) = param_1;
  *(code **)(param_1 + 0x140) = HdAudioFlagsNotifyChanges;
  *(undefined8 *)(param_1 + 0x130) = 0;
  uVar2 = (**(code **)(WdfFunctions_01025 + 0x740))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128));
  p_Var4 = param_1 + 0x150;
  iVar1 = ZwNotifyChangeKey(uVar2,0,param_1 + 0x130,1,p_Var4,4,CONCAT11(uVar5,1),0,0,1);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var4,1,0xb,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar1);
    }
    (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128));
    LOCK();
    *(undefined8 *)(param_1 + 0x128) = 0;
    UNLOCK();
  }
  else if (iVar1 == 0x103) {
    iVar1 = 0;
  }
  return iVar1;
}



===== HDAudBusWmiSystemControl @ 1400297d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HDAudBusWmiSystemControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl HDAudBusWmiSystemControl(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  int local_res8 [4];
  undefined8 in_stack_ffffffffffffffa8;
  
  local_res8[0] = 0;
  iVar2 = *(int *)(param_2 + 0x30);
  bVar1 = true;
  if (param_1 == (_DEVICE_OBJECT *)0x0) {
LAB_14002988b:
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
    uVar3 = (**(code **)(WdfFunctions_01025 + 0xf0))(WdfDriverGlobals,param_1);
    lVar4 = *(longlong *)(param_2 + 0xb8);
    if ((*(byte *)(lVar4 + 1) < 10) || (*(byte *)(lVar4 + 1) == 0xb)) {
      lVar4 = (**(code **)(WdfFunctions_01025 + 0x650))
                        (WdfDriverGlobals,uVar3,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098)
      ;
      if ((lVar4 == 0) || (*(longlong *)(lVar4 + 0xa8) == 0)) goto LAB_14002988b;
      iVar2 = WmiSystemControl(*(longlong *)(lVar4 + 0xa8),param_1,param_2,local_res8);
      if (iVar2 < 0) {
        IofCompleteRequest(param_2,0);
        goto LAB_1400298a3;
      }
      if (local_res8[0] == 0) {
        return iVar2;
      }
      if (local_res8[0] == 1) {
        *(int *)(param_2 + 0x30) = iVar2;
        IofCompleteRequest(param_2,0);
        return iVar2;
      }
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar3 = (**(code **)(WdfFunctions_01025 + 0x100))(WdfDriverGlobals,uVar3);
      iVar2 = IofCallDriver(uVar3,param_2);
    }
    else {
      if (*(_DEVICE_OBJECT **)(lVar4 + 8) == param_1) goto LAB_14002988b;
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = lVar4 + 0x48;
      uVar3 = (**(code **)(WdfFunctions_01025 + 0x100))(WdfDriverGlobals,uVar3);
      iVar2 = IofCallDriver(uVar3,param_2);
    }
  }
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_1400298a3:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,4,0xf,
               &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar2);
  }
  return iVar2;
}



===== GetCodecTimeoutOverride @ 140029a14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetCodecTimeoutOverride(struct WDFDEVICE__ * __ptr64,unsigned long * __ptr64) */

long __cdecl GetCodecTimeoutOverride(WDFDEVICE__ *param_1,ulong *param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  undefined1 auStackY_f8 [32];
  undefined8 uVar4;
  uint local_a8 [2];
  longlong local_a0;
  longlong local_98;
  undefined8 local_90;
  wchar_t *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  wchar_t local_70 [12];
  wchar_t local_58 [28];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_f8;
  builtin_wcsncpy(local_70,L"Settings",9);
  local_88 = local_70;
  local_98 = 0;
  local_58[0x18] = 0;
  local_78 = local_58;
  builtin_wcsncpy(local_58,L"CodecTim",8);
  *param_2 = 500000;
  local_a0 = 0;
  local_a8[0] = 0;
  local_90 = 0x120010;
  builtin_wcsncpy(local_58 + 8,L"eoutOverrideMsec",0x10);
  local_80 = 0x320030;
  iVar1 = (**(code **)(WdfFunctions_01025 + 0x180))(WdfDriverGlobals,param_1,2,0x20000);
  if (-1 < iVar1) {
    uVar4 = 0;
    iVar1 = (**(code **)(WdfFunctions_01025 + 0x728))(WdfDriverGlobals,local_a0,&local_90,0x20000);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(WdfFunctions_01025 + 0x780))
                        (WdfDriverGlobals,local_98,&local_80,local_a8);
      if (-1 < iVar1) {
        if (local_a8[0] < 500) {
          local_a8[0] = 500;
        }
        if (10000 < local_a8[0]) {
          local_a8[0] = 10000;
        }
        *param_2 = local_a8[0] * 1000;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
          cVar2 = '\0';
        }
        if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
           (cVar3 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
          cVar3 = '\0';
        }
        if ((cVar2 != '\0') || (cVar3 != '\0')) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,1,0x38,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)local_a8[0]);
        }
        iVar1 = 0;
      }
    }
  }
  if (local_a0 != 0) {
    (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals);
    local_a0 = 0;
  }
  if (local_98 != 0) {
    (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals);
  }
  return iVar1;
}



===== HDAudRegisterWmiProvider @ 140029c74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HDAudRegisterWmiProvider(struct WDFDEVICE__ * __ptr64) */

long __cdecl HDAudRegisterWmiProvider(WDFDEVICE__ *param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar3 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  uVar4 = (**(code **)(WdfFunctions_01025 + 0xf8))(WdfDriverGlobals,param_1);
  bVar1 = true;
  if (lVar3 == 0) {
    iVar2 = -0x3ffffff0;
  }
  else {
    puVar5 = (undefined4 *)ExAllocatePool2(0x40,0x40,0x4d576448);
    *(undefined4 **)(lVar3 + 0xa8) = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      iVar2 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(puVar5 + 6) = 0;
      *(undefined8 *)(puVar5 + 8) = 0;
      *(undefined8 *)(puVar5 + 10) = 0;
      *(undefined8 *)(puVar5 + 0xc) = 0;
      *(undefined ***)(puVar5 + 2) = &HDAudBusWmiGuidList;
      *(code **)(puVar5 + 4) = HDAudWmiQueryRegInfo;
      *(code **)(puVar5 + 0xe) = HDAudBusWmiFunctionControl;
      *puVar5 = 3;
      iVar2 = IoWMIRegistrationControl(uVar4,1);
      if (-1 < iVar2) {
        return iVar2;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,4,0xe,
               &WPP_479594a964603c08568526b79db93239_Traceguids,(char)iVar2);
  }
  return iVar2;
}



===== HdaController @ 140029de8 =====

/* public: __cdecl HdaController::HdaController(void) __ptr64 */

HdaController * __thiscall HdaController::HdaController(HdaController *this)

{
  *(HdaController **)(this + 0x110) = this + 0x100;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined4 *)this = 1;
  IoInitializeRemoveLockEx(this + 8,0x44427a41,0,0,0x20);
  this[0x82] = (HdaController)0x0;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  memset(this + 0x200,0,0x1950);
  *(undefined4 *)(this + 0x94a0) = 0;
  *(undefined4 *)(this + 0x96b8) = 0;
  memset(this + 0x96bc,0,0x3000);
  *(undefined8 *)(this + 0x178) = 0;
  memset(this + 0x180,0,0x78);
  KeInitializeTimer(this + 0x128);
  *(undefined8 *)(this + 0x96b0) = 0;
  *(undefined8 *)(this + 0x9650) = 0;
  *(undefined4 *)(this + 0x9498) = 500000;
  *(undefined2 *)(this + 0x9670) = 1;
  return this;
}



===== HdAudBusStartDevice @ 140029f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl HdAudBusStartDevice(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
HdAudBusStartDevice(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  _HDAudioDeviceExtension *p_Var4;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var5;
  HdaController *pHVar6;
  undefined8 *puVar7;
  _GUID *p_Var8;
  undefined8 uVar9;
  char cVar10;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var11;
  _GUID *p_Var12;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var13;
  bool bVar14;
  char local_res20 [8];
  code *in_stack_fffffffffffffed8;
  undefined8 uVar15;
  undefined4 uVar16;
  char *pcVar17;
  undefined4 uVar20;
  undefined8 uVar18;
  undefined4 *puVar19;
  undefined2 uVar21;
  int *piVar22;
  undefined4 local_f8;
  int local_f4 [2];
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined8 uStack_d0;
  WDFDEVICE__ *local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  _tlgProvider_t *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  code *pcStack_98;
  undefined8 local_90;
  undefined8 local_88;
  code *pcStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  WDFDEVICE__ *local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  p_Var4 = (_HDAudioDeviceExtension *)
           (**(code **)(WdfFunctions_01025 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  local_f8 = 2;
  local_f4[0] = 0;
  local_f4[1] = 0;
  local_res20[0] = '\0';
  local_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  p_Var11 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)0x0;
  local_b8 = (undefined *)0x0;
  p_Var13 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)0x0;
  local_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  local_c8 = (WDFDEVICE__ *)0x0;
  uStack_c0 = 0;
  p_Var4[0x1d0] = (_HDAudioDeviceExtension)0x0;
  p_Var4[0x1e6] = (_HDAudioDeviceExtension)0x1;
  *(undefined4 *)(p_Var4 + 0x1dc) = 0;
  *(undefined8 *)(p_Var4 + 0x120) = 0;
  *(undefined8 *)(p_Var4 + 0x128) = 0;
  *(undefined8 *)(p_Var4 + 0x160) = 0;
  *(undefined8 *)(p_Var4 + 0x150) = 0;
  *(undefined8 *)(p_Var4 + 0x158) = 0;
  local_30 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = (WDFDEVICE__ *)0x0;
  uStack_38 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar10 = '\0';
  }
  if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,1,0x8f,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1);
  }
  iVar1 = HDAudRegisterWmiProvider(param_1);
  if (iVar1 < 0) goto LAB_14002ae5e;
  if ((param_2 == (WDFCMRESLIST__ *)0x0) || (param_3 == (WDFCMRESLIST__ *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
        (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
      cVar10 = '\0';
    }
    bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar10 != '\0') || (bVar14)) {
      uVar21 = 0x90;
      goto LAB_14002adc8;
    }
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01025 + 0x980))(WdfDriverGlobals,param_3);
    if (uVar2 < 2) {
      iVar1 = -0x3fffff66;
      goto LAB_14002ae5e;
    }
    iVar1 = (**(code **)(WdfFunctions_01025 + 0x980))(WdfDriverGlobals,param_3);
    if (iVar1 != 0) {
      do {
        iVar1 = iVar1 + -1;
        p_Var5 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)
                 (**(code **)(WdfFunctions_01025 + 0x988))(WdfDriverGlobals,param_3,iVar1);
        if (*p_Var5 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x3) {
          if (*(uint *)(p_Var5 + 0xc) < 0x20a7) {
            return -0x3fffff66;
          }
          p_Var11 = p_Var5;
        }
        else if (*p_Var5 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x2) {
          p_Var13 = p_Var5;
        }
      } while (iVar1 != 0);
      if ((p_Var11 != (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)0x0) &&
         (p_Var13 != (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)0x0)) {
        uVar9 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
        piVar22 = local_f4;
        pcVar17 = local_res20;
        uVar15 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffed8 >> 0x20),1);
        iVar1 = IoGetDevicePropertyData
                          (uVar9,&DEVPKEY_HdAudBus_DisableNonSnoop,0,0,uVar15,pcVar17,local_f4 + 1);
        if ((iVar1 < 0) || (local_f4[0] != 0x11)) {
          local_res20[0] = '\0';
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
            cVar10 = '\0';
          }
          if ((cVar10 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_Dd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,pcVar17,0x92,piVar22,0,
                       (char)iVar1);
          }
          uVar16 = (undefined4)((ulonglong)uVar15 >> 0x20);
          uVar20 = (undefined4)((ulonglong)pcVar17 >> 0x20);
          uVar9 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
          uVar18 = CONCAT44(uVar20,1);
          uVar15 = CONCAT44(uVar16,0x11);
          iVar1 = IoSetDevicePropertyData
                            (uVar9,&DEVPKEY_HdAudBus_DisableNonSnoop,0,1,uVar15,uVar18,local_res20);
          if (iVar1 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar10 = '\0';
            }
            if ((cVar10 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_Dd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,uVar18,0x93,piVar22,
                         local_res20[0],(char)iVar1);
            }
          }
        }
        if ((local_res20[0] == '\0') && (((byte)p_Var4[200] & 2) != 0)) {
          local_res20[0] = -1;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
              (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
            cVar10 = '\0';
          }
          if ((cVar10 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,1,0x94,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
          }
        }
        uVar16 = (undefined4)((ulonglong)uVar15 >> 0x20);
        uVar9 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
        piVar22 = local_f4;
        puVar19 = &local_f8;
        in_stack_fffffffffffffed8 = (code *)CONCAT44(uVar16,4);
        iVar1 = IoGetDevicePropertyData
                          (uVar9,&DEVPKEY_HdAudBus_ForcedCacheType,0,0,in_stack_fffffffffffffed8,
                           puVar19,local_f4 + 1);
        if ((iVar1 < 0) || (local_f4[0] != 7)) {
          local_f8 = 2;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
              (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)))) {
            cVar10 = '\0';
          }
          if ((cVar10 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_Dd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,puVar19,
                       0x95,piVar22,2,(char)iVar1);
          }
          uVar16 = (undefined4)((ulonglong)in_stack_fffffffffffffed8 >> 0x20);
          uVar20 = (undefined4)((ulonglong)puVar19 >> 0x20);
          uVar9 = (**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals,param_1);
          uVar15 = CONCAT44(uVar20,4);
          in_stack_fffffffffffffed8 = (code *)CONCAT44(uVar16,7);
          iVar1 = IoSetDevicePropertyData
                            (uVar9,&DEVPKEY_HdAudBus_ForcedCacheType,0,1,in_stack_fffffffffffffed8,
                             uVar15,&local_f8);
          if (iVar1 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
              cVar10 = '\0';
            }
            if ((cVar10 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_Dd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,uVar15
                         ,0x96,piVar22,(char)local_f8,(char)iVar1);
            }
          }
        }
        p_Var4[0xc1] = (_HDAudioDeviceExtension)(local_res20[0] != '\0');
        *(undefined4 *)(p_Var4 + 0xc4) = local_f8;
        lVar3 = SetNonSnoop(param_1);
        if (lVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar10 = '\0';
          }
          if ((cVar10 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_d
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,1,0x97,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)lVar3);
          }
        }
        GetGraphicsPowerInterfaceSettings(param_1,p_Var4);
        pHVar6 = operator_new(0xc6c0,0x200,0x44427a41);
        if ((pHVar6 == (HdaController *)0x0) ||
           (pHVar6 = (HdaController *)HdaController::HdaController(pHVar6),
           pHVar6 == (HdaController *)0x0)) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
              (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)))) {
            cVar10 = '\0';
          }
          if ((cVar10 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,1,0x98,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
          }
          iVar1 = -0x3fffffff;
          goto LAB_14002ae5e;
        }
        lVar3 = HdaController::Init(pHVar6,p_Var11,p_Var13,param_1);
        uVar2 = (uint)p_Var11;
        if (lVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (uVar2 = (uint)CONCAT71((int7)((ulonglong)p_Var11 >> 8),1),
             (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            uVar2 = uVar2 & 0xffffff00;
          }
          if (((char)uVar2 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)uVar2,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,1,0x99,
                       &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
          }
          HdaController::_scalar_deleting_destructor_(pHVar6,uVar2);
          iVar1 = -0x3fffffff;
          goto LAB_14002ae5e;
        }
        local_60 = CONCAT44(local_60._4_4_,0x38);
        uStack_48 = 0x100000001;
        local_40 = param_1;
        iVar1 = (**(code **)(WdfFunctions_01025 + 0x9c0))(WdfDriverGlobals,&local_60,p_Var4 + 0x168)
        ;
        if (iVar1 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar10 = '\0';
          }
          bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar10 == '\0') && (!bVar14)) goto LAB_14002ae5e;
          uVar21 = 0x9a;
        }
        else {
          iVar1 = (**(code **)(WdfFunctions_01025 + 0x9c0))
                            (WdfDriverGlobals,&local_60,p_Var4 + 0x120);
          if (iVar1 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar10 = '\0';
            }
            bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar10 == '\0') && (!bVar14)) goto LAB_14002ae5e;
            uVar21 = 0x9b;
          }
          else {
            *(HdaController **)(p_Var4 + 0x10) = pHVar6;
            uStack_d4 = 0;
            local_68 = 0;
            uStack_c0 = 0;
            pcStack_80 = TimerRoutineHandleSgpcHdAudBus;
            local_b8 = PTR__WDF_BUS_SGPC_TIMER_CONTEXT_TYPE_INFO_14001d0c8;
            local_88 = 0x28;
            local_78 = 0x100000000;
            uStack_70 = 0;
            uStack_e4 = 0;
            uStack_e0 = 0;
            uStack_dc = 0;
            local_d8 = 0;
            local_e8 = 0x38;
            uStack_d0 = 0x100000001;
            local_c8 = param_1;
            iVar1 = (**(code **)(WdfFunctions_01025 + 0x9f0))
                              (WdfDriverGlobals,&local_88,&local_e8,p_Var4 + 0x68);
            if (iVar1 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                cVar10 = '\0';
              }
              bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((cVar10 == '\0') && (!bVar14)) goto LAB_14002ae5e;
              uVar21 = 0x9c;
            }
            else {
              puVar7 = (undefined8 *)
                       (**(code **)(WdfFunctions_01025 + 0x650))
                                 (WdfDriverGlobals,*(undefined8 *)(p_Var4 + 0x68),
                                  PTR__WDF_BUS_SGPC_TIMER_CONTEXT_TYPE_INFO_14001d0c8);
              *puVar7 = param_1;
              pcStack_98 = WorkItemRoutineEnumerateHdAudBus;
              local_b8 = PTR__WDF_BUS_ENUMERATE_WORK_ITEM_CONTEXT_TYPE_INFO_14001d048;
              local_a0 = 0x18;
              local_90 = 1;
              uStack_e4 = 0;
              uStack_e0 = 0;
              uStack_dc = 0;
              local_d8 = 0;
              uStack_d4 = 0;
              uStack_c0 = 0;
              local_e8 = 0x38;
              uStack_d0 = 0x100000001;
              local_c8 = param_1;
              iVar1 = (**(code **)(WdfFunctions_01025 + 0xbd8))
                                (WdfDriverGlobals,&local_a0,&local_e8,p_Var4 + 0x70);
              if (iVar1 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                   (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar10 = '\0';
                }
                bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                if ((cVar10 == '\0') && (!bVar14)) goto LAB_14002ae5e;
                uVar21 = 0x9d;
              }
              else {
                puVar7 = (undefined8 *)
                         (**(code **)(WdfFunctions_01025 + 0x650))
                                   (WdfDriverGlobals,*(undefined8 *)(p_Var4 + 0x70),
                                    PTR__WDF_BUS_ENUMERATE_WORK_ITEM_CONTEXT_TYPE_INFO_14001d048);
                *puVar7 = param_1;
                *(undefined4 *)(p_Var4 + 0x78) = 0;
                iVar1 = (**(code **)(WdfFunctions_01025 + 0x9c0))
                                  (WdfDriverGlobals,&local_60,p_Var4 + 0x80);
                if (-1 < iVar1) {
                  *(undefined2 *)(p_Var4 + 0x7c) = 0;
                  KeInitializeEvent(p_Var4 + 0x88,0,1);
                  uVar9 = (**(code **)(WdfFunctions_01025 + 0x138))(WdfDriverGlobals,param_1);
                  p_Var8 = (_GUID *)(**(code **)(WdfFunctions_01025 + 0x3b0))
                                              (WdfDriverGlobals,uVar9);
                  uVar9 = 0;
                  in_stack_fffffffffffffed8 = HdAudBusProfileChangeCallback;
                  iVar1 = IoRegisterPlugPlayNotification
                                    (1,0,0,p_Var8,HdAudBusProfileChangeCallback,param_1,
                                     p_Var4 + 0x60);
                  if (p_Var4[0xc2] == (_HDAudioDeviceExtension)0x0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                      cVar10 = '\0';
                    }
                    if ((cVar10 != '\0') ||
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      WPP_RECORDER_AND_TRACE_SF_
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED
                                 ,*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                 in_stack_fffffffffffffed8,1,0xa1,
                                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
                    }
                  }
                  else {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                      cVar10 = '\0';
                    }
                    bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                    p_Var12 = (_GUID *)CONCAT71((int7)((ulonglong)uVar9 >> 8),bVar14);
                    if ((cVar10 != '\0') || (bVar14)) {
                      p_Var8 = *(_GUID **)(WPP_GLOBAL_Control + 0x40);
                      WPP_RECORDER_AND_TRACE_SF_d
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,bVar14,p_Var8,
                                 in_stack_fffffffffffffed8,1,0x9f,
                                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,
                                 (char)*(undefined4 *)(p_Var4 + 0x1e0));
                    }
                    LOCK();
                    *(ushort *)(pHVar6 + 0x94a4) =
                         *(ushort *)(pHVar6 + 0x94a4) | *(ushort *)(p_Var4 + 0x1e4);
                    UNLOCK();
                    if ((4 < DAT_14001d0d8) && (uVar9 = _tlgKeywordOn(), (char)uVar9 != '\0')) {
                      local_ec = *(undefined4 *)(p_Var4 + 0x1e0);
                      local_a8 = 0x800;
                      local_b0 = (_tlgProvider_t *)L"Unknown";
                      if (*(_tlgProvider_t **)(p_Var4 + 0x1e8) != (_tlgProvider_t *)0x0) {
                        local_b0 = *(_tlgProvider_t **)(p_Var4 + 0x1e8);
                      }
                      _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
                      ::Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>_>
                                (local_b0,&DAT_14001b311,p_Var12,p_Var8,
                                 (_tlgWrapperByVal<8> *)&local_a8,
                                 (_tlgWrapSz<unsigned_short> *)&local_b0,
                                 (_tlgWrapperByVal<4> *)&local_ec);
                    }
                    *(undefined4 *)(p_Var4 + 0x178) = 0x1002;
                    *(code **)(p_Var4 + 0x188) = HdAudBusGraphicsPowerNotificationCallback;
                    *(WDFDEVICE__ **)(p_Var4 + 0x180) = param_1;
                    *(code **)(p_Var4 + 400) = HdAudBusGraphicsRemovalNotificationCallback;
                    *(code **)(p_Var4 + 0x1a0) = HdAudBusGraphicsPowerInitialComponentStateCallback;
                    *(code **)(p_Var4 + 0x198) = HdAudBusGraphicsPowerFStateNotificationCallback;
                    uVar9 = (**(code **)(WdfFunctions_01025 + 0x138))(WdfDriverGlobals,param_1);
                    uVar9 = (**(code **)(WdfFunctions_01025 + 0x3b0))(WdfDriverGlobals,uVar9);
                    in_stack_fffffffffffffed8 = HdAudBusGraphicsPowerInterfaceCallback;
                    iVar1 = IoRegisterPlugPlayNotification
                                      (2,1,&_GUID_ea5c6870_e93c_4588_bef1_fec42fc9429a,uVar9,
                                       HdAudBusGraphicsPowerInterfaceCallback,param_1,p_Var4 + 0x170
                                      );
                    if (iVar1 < 0) {
                      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                         (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                        cVar10 = '\0';
                      }
                      bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                      if ((cVar10 == '\0') && (!bVar14)) goto LAB_14002ae5e;
                      uVar21 = 0xa0;
                      goto LAB_14002a686;
                    }
                  }
                  StartHdAudioFlagsRegistryNotification(p_Var4);
                  goto LAB_14002ae5e;
                }
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                   (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  cVar10 = '\0';
                }
                bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                if ((cVar10 == '\0') && (!bVar14)) goto LAB_14002ae5e;
                uVar21 = 0x9e;
              }
            }
          }
        }
LAB_14002a686:
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,bVar14,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,1,uVar21,
                   &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)iVar1);
        goto LAB_14002ae5e;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar10 != '\0') || (bVar14)) {
      uVar21 = 0x91;
LAB_14002adc8:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,bVar14,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,1,uVar21,
                 &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids);
    }
  }
  iVar1 = -0x3fffff66;
LAB_14002ae5e:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar10 = '\x01',
     (int)(uint)(byte)WPP_GLOBAL_Control[0x29] < (int)((iVar1 >> 0x1f & 0xfffffffeU) + 4))) {
    cVar10 = '\0';
  }
  if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_fffffffffffffed8,1,0xa2,
               &WPP_c49fd15bc7363e00bc8ba9bdfe334daf_Traceguids,(char)param_1,(char)iVar1);
  }
  return iVar1;
}



===== EnumerateCapabilities @ 14002aefc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl HdaController::EnumerateCapabilities(unsigned long) __ptr64 */

long __thiscall HdaController::EnumerateCapabilities(HdaController *this,ulong param_1)

{
  longlong lVar1;
  char cVar2;
  uint *puVar3;
  ulonglong uVar4;
  undefined8 in_stack_ffffffffffffffc8;
  
  uVar4 = (ulonglong)*(ushort *)(*(longlong *)(this + 0x58) + 0x14);
  lVar1 = (**(code **)(WdfFunctions_01025 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x70),
                     PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098);
  while( true ) {
    if ((short)uVar4 == 0) {
      return 0;
    }
    if ((ulonglong)param_1 < (uVar4 & 0xffff) + 4) break;
    puVar3 = (uint *)(*(longlong *)(this + 0x58) + (uVar4 & 0xffff));
    if (((*puVar3 & 0xfff0000) == 0x20000) && (*(char *)(lVar1 + 0xc2) != '\0')) {
      InitializeSgpcLinkCtrl(this,puVar3,param_1 - ((uint)uVar4 & 0xffff));
    }
    uVar4 = (ulonglong)*puVar3;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar2 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar2 = '\0';
  }
  if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffc8,1,0xd1,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
  }
  return -0x3fffffff;
}



===== GetMemoryMapOverrideSize @ 14002b030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetMemoryMapOverrideSize(struct WDFDEVICE__ * __ptr64,unsigned long * __ptr64) */

long __cdecl GetMemoryMapOverrideSize(WDFDEVICE__ *param_1,ulong *param_2)

{
  int iVar1;
  char cVar2;
  undefined1 auStackY_c8 [32];
  undefined8 in_stack_ffffffffffffff58;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  wchar_t *local_60;
  wchar_t local_58 [12];
  wchar_t local_40 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_c8;
  builtin_wcsncpy(local_58,L"Settings",9);
  local_70 = local_58;
  builtin_wcsncpy(local_40,L"MemoryMapSizeOverride",0x16);
  local_60 = local_40;
  local_78 = 0x120010;
  local_68 = 0x2c002a;
  if ((param_1 == (WDFDEVICE__ *)0x0) || (param_2 == (ulong *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2))))
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
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff58,1,0x36,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
    iVar1 = -0x3ffffff3;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01025 + 0x180))(WdfDriverGlobals,param_1,2,0x20000);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(WdfFunctions_01025 + 0x728))(WdfDriverGlobals,0,&local_78,0x20000);
      (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,0);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(WdfFunctions_01025 + 0x780))(WdfDriverGlobals,0,&local_68,param_2);
        (**(code **)(WdfFunctions_01025 + 0x738))(WdfDriverGlobals,0);
      }
    }
  }
  return iVar1;
}



===== Init @ 14002b258 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl HdaController::Init(struct _CM_PARTIAL_RESOURCE_DESCRIPTOR * __ptr64,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR * __ptr64,struct WDFDEVICE__ * __ptr64) __ptr64 */

long __thiscall
HdaController::Init(HdaController *this,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_1,
                   _CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,WDFDEVICE__ *param_3)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char *pcVar6;
  _DEVICE_OBJECT *p_Var7;
  void *pvVar8;
  _MDL *p_Var9;
  HdaController *pHVar10;
  undefined8 *puVar11;
  char cVar12;
  ushort uVar13;
  byte bVar14;
  int iVar15;
  _MEMORY_CACHING_TYPE _Var16;
  uchar uVar17;
  uint uVar18;
  HdaController *pHVar19;
  bool bVar20;
  undefined1 auStackY_f8 [32];
  undefined8 in_stack_ffffffffffffff28;
  undefined4 in_stack_ffffffffffffff30;
  undefined4 in_stack_ffffffffffffff34;
  undefined2 uVar21;
  ulong local_98;
  ulong local_94 [3];
  undefined4 local_88;
  undefined2 local_84;
  undefined1 local_80;
  bool local_7d;
  undefined4 local_74;
  uint local_68;
  undefined4 local_60;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  puVar11 = (undefined8 *)
            (**(code **)(WdfFunctions_01025 + 0x650))
                      (WdfDriverGlobals,param_3,PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098)
  ;
  *(undefined8 *)(this + 0x78) = *puVar11;
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0xc);
  local_98 = 0x1000;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar12 = '\0';
  }
  if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffff30 = 1;
    WPP_RECORDER_AND_TRACE_SF_D
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,0x3d,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,0);
  }
  lVar1 = GetMemoryMapOverrideSize(param_3,&local_98);
  if (lVar1 == 0) {
    if ((local_98 == 0) || (*(uint *)(this + 0x68) < local_98)) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
          (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
        cVar12 = '\0';
      }
      if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        in_stack_ffffffffffffff30 = 1;
        WPP_RECORDER_AND_TRACE_SF_D
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,0x3e,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)local_98);
      }
      local_98 = 0x1000;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar12 = '\0';
      }
      if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        uVar21 = 0x3f;
LAB_14002b49b:
        in_stack_ffffffffffffff30 = 1;
        WPP_RECORDER_AND_TRACE_SF_D
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,uVar21,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)local_98);
      }
    }
  }
  else if ((short)((ulonglong)*(undefined8 *)(this + 0x78) >> 0x18) == -0x7f7a) {
    local_98 = *(ulong *)(this + 0x68);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar12 = '\0';
    }
    if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar21 = 0x40;
      goto LAB_14002b49b;
    }
  }
  uVar3 = MmMapIoSpaceEx(*(undefined8 *)(param_1 + 4),local_98,0x204);
  *(undefined8 *)(this + 0x58) = uVar3;
  lVar4 = MmMapIoSpaceEx(*(longlong *)(param_1 + 4) + 0x2000);
  *(longlong *)(this + 0x60) = lVar4;
  if ((*(longlong *)(this + 0x58) != 0) && (lVar4 != 0)) {
    uVar3 = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(this + 0x28) = *(undefined8 *)param_2;
    *(undefined8 *)(this + 0x30) = uVar3;
    *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_2 + 0x10);
    *(undefined8 *)(this + 0x50) = 0;
    *(WDFDEVICE__ **)(this + 0x70) = param_3;
    uVar5 = Feature_2795140408__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      *(uint *)(this + 0x168) = **(ushort **)(this + 0x58) >> 8 & 0xf;
      *(uint *)(this + 0x16c) = (uint)(**(ushort **)(this + 0x58) >> 0xc);
      uVar18 = **(ushort **)(this + 0x58) >> 3 & 0x1f;
      *(uint *)(this + 0x170) = uVar18;
      if (((0xf < *(uint *)(this + 0x168)) || (0xf < *(uint *)(this + 0x16c))) ||
         (0x1e < *(uint *)(this + 0x16c) + uVar18 + *(uint *)(this + 0x168))) {
        lVar1 = -0x3ffffe7e;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar12 = '\0';
        }
        if ((cVar12 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_dddd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        goto LAB_14002c1f1;
      }
    }
    if ((*(uint *)(*(longlong *)(this + 0x58) + 8) & 1) == 0) goto LAB_14002b83e;
    uVar5 = Feature_2795140408__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar15 = (**(ushort **)(this + 0x58) >> 8 & 0xf) + (**(ushort **)(this + 0x58) >> 3 & 0x1f) +
               (uint)(**(ushort **)(this + 0x58) >> 0xc);
      do {
        if (iVar15 == 0) goto LAB_14002b662;
        iVar15 = iVar15 + -1;
        lVar1 = SetDmaEngineState(this,iVar15,'\0');
      } while (-1 < lVar1);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar12 = '\0';
      }
      bVar20 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar12 != '\0') || (bVar20)) {
        uVar21 = 0x43;
LAB_14002b728:
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,bVar20,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,uVar21,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
    }
    else {
      iVar15 = *(int *)(this + 0x170) + *(int *)(this + 0x16c) + *(int *)(this + 0x168);
      do {
        if (iVar15 == 0) goto LAB_14002b662;
        iVar15 = iVar15 + -1;
        lVar1 = SetDmaEngineState(this,iVar15,'\0');
      } while (-1 < lVar1);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar12 = '\0';
      }
      bVar20 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar12 != '\0') || (bVar20)) {
        uVar21 = 0x42;
        goto LAB_14002b728;
      }
    }
  }
LAB_14002c1ec:
  lVar1 = -0x3fffffff;
LAB_14002c1f1:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar12 = '\0';
  }
  if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,0x4d,
               &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)lVar1);
  }
  return lVar1;
LAB_14002b662:
  lVar1 = SetCorbDmaState(this,'\0');
  if (lVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar12 = '\0';
    }
    bVar20 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar12 != '\0') || (bVar20)) {
      uVar21 = 0x44;
      goto LAB_14002b728;
    }
  }
  else {
    lVar1 = SetRirbDmaState(this,'\0');
    if (lVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar12 = '\0';
      }
      bVar20 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar12 != '\0') || (bVar20)) {
        uVar21 = 0x45;
        goto LAB_14002b728;
      }
    }
    else {
LAB_14002b83e:
      lVar1 = ResetController(this);
      if (lVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar12 = '\0';
        }
        bVar20 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar12 != '\0') || (bVar20)) {
          uVar21 = 0x46;
          goto LAB_14002b728;
        }
      }
      else {
        uVar13 = **(ushort **)(this + 0x58);
        this[0x80] = (HdaController)((byte)uVar13 & 1);
        if (((uVar13 & 1) != 0) &&
           (lVar4 = (**(code **)(WdfFunctions_01025 + 0x650))
                              (WdfDriverGlobals,param_3,
                               PTR__WDF_HDAudioDeviceExtension_TYPE_INFO_14001d098),
           (*(byte *)(lVar4 + 200) & 1) != 0)) {
          this[0x80] = (HdaController)0x0;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
              (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
            cVar12 = '\0';
          }
          if ((cVar12 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            in_stack_ffffffffffffff30 = 1;
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,0x47,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
        }
        if ((short)((ulonglong)*(undefined8 *)(this + 0x78) >> 0x18) == 0x1022) {
          this[0x82] = (HdaController)0x1;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar12 = '\0';
          }
          if ((cVar12 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            in_stack_ffffffffffffff30 = 1;
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,0x48,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
        }
        *(undefined8 *)(this + 0x94ac) = 0;
        *(undefined2 *)(this + 0x94a8) = 0;
        *(undefined2 *)(this + 0x9604) = 0;
        uVar13 = CONCAT11(*(undefined1 *)(*(longlong *)(this + 0x58) + 3),
                          *(undefined1 *)(*(longlong *)(this + 0x58) + 2));
        *(ushort *)(this + 0x94a6) = uVar13;
        if (0x100 < uVar13) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
            cVar12 = '\0';
          }
          if ((cVar12 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            in_stack_ffffffffffffff30 = 1;
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,0x49,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
        }
        local_94[0] = 1;
        GetUseHalDMA(param_3,local_94);
        this[0x9606] = (HdaController)(local_94[0] != 0);
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar12 = '\0';
        }
        if ((cVar12 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          pcVar6 = "is";
          if (local_94[0] == 0) {
            pcVar6 = "is NOT";
          }
          WPP_RECORDER_AND_TRACE_SF_s
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,
                     CONCAT44(in_stack_ffffffffffffff34,in_stack_ffffffffffffff30),0x4a,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,pcVar6);
        }
        if (this[0x9606] == (HdaController)0x0) {
          _Var16 = 0;
          pHVar10 = this;
          p_Var9 = AllocateBuffer(this,0x1000,0);
          *(_MDL **)(this + 0x88) = p_Var9;
          if (p_Var9 != (_MDL *)0x0) {
            pvVar8 = MapBuffer(pHVar10,p_Var9,_Var16);
            *(void **)(this + 0x90) = pvVar8;
            if (pvVar8 != (void *)0x0) {
              if (this[0x82] == (HdaController)0x0) {
LAB_14002bc64:
                *(longlong *)(this + 0xb8) = *(longlong *)(this + 0x90);
                if (this[0x82] == (HdaController)0x0) {
                  lVar4 = *(longlong *)(this + 0x90) + 0x800;
                }
                else {
                  lVar4 = *(longlong *)(this + 0xa8);
                }
                *(longlong *)(this + 0xc0) = lVar4;
                memset(this + 0x1bd8,0,0x7800);
                LOCK();
                *(undefined4 *)(this + 0x120) = 0;
                UNLOCK();
                LOCK();
                *(undefined4 *)(this + 0x124) = 0;
                UNLOCK();
                InitializeSListHead((PSLIST_HEADER)(this + 0xd0));
                InitializeSListHead((PSLIST_HEADER)(this + 0x9660));
                KeInitializeMutex(this + 0x9678);
                *(undefined8 *)(this + 0xe0) = 0;
                *(undefined8 *)(this + 0xf0) = 0;
                memset(this + 0x1b60,0,0x78);
                uVar5 = Feature_2795140408__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar5 == 0) {
                  *(uint *)(this + 0x168) = **(ushort **)(this + 0x58) >> 8 & 0xf;
                  *(uint *)(this + 0x16c) = (uint)(**(ushort **)(this + 0x58) >> 0xc);
                  *(uint *)(this + 0x170) = **(ushort **)(this + 0x58) >> 3 & 0x1f;
                }
                uVar18 = 0;
                *(undefined8 *)(this + 7000) = 0;
                *(undefined8 *)(this + 0x1b50) = 0;
                if (*(int *)(this + 0x168) != 0) {
                  do {
                    uVar5 = (ulonglong)uVar18;
                    uVar18 = uVar18 + 1;
                    lVar4 = uVar5 * 0xd8;
                    pHVar10 = this + lVar4 + 0x2b0;
                    *(undefined4 *)(this + lVar4 + 0x208) = 0;
                    this[lVar4 + 0x20c] = (HdaController)0x0;
                    this[lVar4 + 0x20e] = (HdaController)0x0;
                    this[lVar4 + 0x2c0] = (HdaController)0x0;
                    *(undefined8 *)(this + lVar4 + 0x200) = 0;
                    *(undefined8 *)(this + lVar4 + 0x2a8) = 0;
                    *(HdaController **)(pHVar10 + 8) = pHVar10;
                    *(HdaController **)pHVar10 = pHVar10;
                  } while (uVar18 < *(uint *)(this + 0x168));
                }
                uVar18 = 0;
                if (*(int *)(this + 0x16c) != 0) {
                  do {
                    uVar2 = *(int *)(this + 0x168) + uVar18;
                    uVar18 = uVar18 + 1;
                    lVar4 = (ulonglong)uVar2 * 0xd8;
                    pHVar10 = this + lVar4 + 0x2b0;
                    *(undefined4 *)(this + lVar4 + 0x208) = 1;
                    this[lVar4 + 0x20c] = (HdaController)0x0;
                    this[lVar4 + 0x20e] = (HdaController)0x0;
                    this[lVar4 + 0x2c0] = (HdaController)0x0;
                    *(undefined8 *)(this + lVar4 + 0x200) = 0;
                    *(undefined8 *)(this + lVar4 + 0x2a8) = 0;
                    *(HdaController **)(pHVar10 + 8) = pHVar10;
                    *(HdaController **)pHVar10 = pHVar10;
                  } while (uVar18 < *(uint *)(this + 0x16c));
                }
                uVar18 = 0;
                if (*(int *)(this + 0x170) != 0) {
                  do {
                    uVar2 = *(int *)(this + 0x16c) + *(int *)(this + 0x168) + uVar18;
                    if (0x1d < uVar2) break;
                    lVar4 = (ulonglong)uVar2 * 0xd8;
                    uVar18 = uVar18 + 1;
                    pHVar10 = this + lVar4 + 0x2b0;
                    *(undefined4 *)(this + lVar4 + 0x208) = 2;
                    this[lVar4 + 0x20c] = (HdaController)0x0;
                    this[lVar4 + 0x20e] = (HdaController)0x0;
                    this[lVar4 + 0x2c0] = (HdaController)0x0;
                    *(undefined8 *)(this + lVar4 + 0x200) = 0;
                    *(undefined8 *)(this + lVar4 + 0x2a8) = 0;
                    *(HdaController **)(pHVar10 + 8) = pHVar10;
                    *(HdaController **)pHVar10 = pHVar10;
                  } while (uVar18 < *(uint *)(this + 0x170));
                }
                *(undefined8 *)(this + 0x1f8) = 0;
                KeInitializeDpc(this + 0x93d8,CodecDpc,this);
                KeInitializeDpc(this + 0x9418,TimeoutDpc,this);
                KeInitializeDpc(this + 0x94b8,StatusChangeDpc,this);
                KeInitializeDpc(this + 0x9458,NotificationDpc,this);
                KeSetImportanceDpc(this + 0x9458,2);
                lVar1 = GetCodecTimeoutOverride(param_3,(ulong *)(this + 0x9498));
                if (lVar1 < 0) {
                  *(ulong *)(this + 0x9498) = 500000;
                }
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                   (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                  cVar12 = '\0';
                }
                if ((cVar12 != '\0') ||
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_AND_TRACE_SF_d
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,1,
                             0x4b,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,
                             (char)*(undefined4 *)(this + 0x9498));
                }
                memset(this + 0x94f8,0,0x10c);
                *(int *)(this + 0x9500) =
                     *(int *)(this + 0x170) + *(int *)(this + 0x16c) + *(int *)(this + 0x168);
                if ((((short)((ulonglong)*(undefined8 *)(this + 0x78) >> 0x18) == -0x7f7a) &&
                    (*(short *)(*(longlong *)(this + 0x58) + 0x14) != 0)) &&
                   (lVar1 = EnumerateCapabilities(this,local_98), lVar1 < 0)) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                     (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
                    cVar12 = '\0';
                  }
                  if ((cVar12 != '\0') ||
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    WPP_RECORDER_AND_TRACE_SF_q
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
                               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,
                               1,0x4c,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)param_3
                              );
                  }
                  *(undefined2 *)(this + 0x9670) = 1;
                }
                this[0x81] = (HdaController)((byte)**(undefined2 **)(this + 0x58) >> 1 & 1);
                if (*(short *)(this + 0x9670) == 1) {
                  puVar11 = operator_new(0x18,0x200,0x44427a41);
                  if (puVar11 == (undefined8 *)0x0) {
                    puVar11 = (undefined8 *)0x0;
                  }
                  else {
                    uVar13 = *(ushort *)(*(longlong *)(this + 0x58) + 4);
                    *(undefined8 *)((longlong)puVar11 + 0xc) = 0;
                    *(uint *)(puVar11 + 1) = (uint)uVar13 * 96000;
                    *puVar11 = &OutputLinkBandwidth::_vftable_;
                  }
                  *(undefined8 **)(this + 0x178) = puVar11;
                  if (puVar11 == (undefined8 *)0x0) {
LAB_14002c16a:
                    lVar1 = -0x3fffff66;
                    goto LAB_14002c1f1;
                  }
                  bVar14 = 0;
                  do {
                    puVar11 = operator_new(0x18,0x200,0x44427a41);
                    if (puVar11 == (undefined8 *)0x0) {
                      puVar11 = (undefined8 *)0x0;
                    }
                    else {
                      uVar13 = *(ushort *)(*(longlong *)(this + 0x58) + 6);
                      *(undefined8 *)((longlong)puVar11 + 0xc) = 0;
                      *(uint *)(puVar11 + 1) = (uint)uVar13 * 96000;
                      *puVar11 = &InputLinkBandwidth::_vftable_;
                    }
                    *(undefined8 **)(this + (ulonglong)bVar14 * 8 + 0x180) = puVar11;
                    if (puVar11 == (undefined8 *)0x0) goto LAB_14002c16a;
                    bVar14 = bVar14 + 1;
                  } while (bVar14 < 0xf);
                }
                lVar1 = RestoreRegisters(this);
                if (-1 < lVar1) {
                  return lVar1;
                }
                goto LAB_14002c1f1;
              }
              _Var16 = 0;
              pHVar10 = this;
              p_Var9 = AllocateBuffer(this,0x1000,0);
              *(_MDL **)(this + 0xa0) = p_Var9;
              if (p_Var9 != (_MDL *)0x0) {
                p_Var9 = MapBuffer(pHVar10,p_Var9,_Var16);
                *(_MDL **)(this + 0xa8) = p_Var9;
LAB_14002bc5b:
                if (p_Var9 != (_MDL *)0x0) goto LAB_14002bc64;
              }
            }
          }
        }
        else {
          p_Var7 = (_DEVICE_OBJECT *)(**(code **)(WdfFunctions_01025 + 0x108))(WdfDriverGlobals);
          memset(&local_88,0,0x40);
          local_68 = 0xffffffff;
          local_88 = 3;
          local_84 = 0x101;
          local_74 = 5;
          local_80 = this[0x80] == (HdaController)0x0;
          if ((bool)local_80) {
            local_60 = 0x20;
          }
          else {
            local_60 = 0x40;
          }
          local_7d = !(bool)local_80;
          pHVar10 = this + 0x9648;
          pHVar19 = pHVar10;
          lVar1 = DmaAdapterTracker::GetDmaAdapter
                            (p_Var7,(_DEVICE_DESCRIPTION *)&local_88,
                             (DmaAdapterTracker **)(this + 0x9650),(ulong *)pHVar10);
          uVar17 = (uchar)pHVar19;
          if (lVar1 < 0) goto LAB_14002c1f1;
          uVar18 = *(uint *)pHVar10;
          if (uVar18 == 0) {
            lVar1 = -0x3fffff66;
            goto LAB_14002c1f1;
          }
          if ((ulonglong)uVar18 << 0xc < (ulonglong)local_68) {
            *(uint *)(this + 0x964c) = uVar18 << 0xc;
          }
          else {
            *(uint *)(this + 0x964c) = local_68;
          }
          pHVar10 = this;
          pvVar8 = AllocateBufferHal(this,0x1000,(_LARGE_INTEGER *)(this + 0x98),uVar17);
          *(void **)(this + 0x90) = pvVar8;
          if (pvVar8 != (void *)0x0) {
            p_Var9 = AllocateBufferMdl(pHVar10,pvVar8,0x1000);
            *(_MDL **)(this + 0x88) = p_Var9;
            if (p_Var9 != (_MDL *)0x0) {
              if (this[0x82] == (HdaController)0x0) goto LAB_14002bc64;
              pHVar10 = this;
              pvVar8 = AllocateBufferHal(this,0x1000,(_LARGE_INTEGER *)(this + 0xb0),uVar17);
              *(void **)(this + 0xa8) = pvVar8;
              if (pvVar8 != (void *)0x0) {
                p_Var9 = AllocateBufferMdl(pHVar10,pvVar8,0x1000);
                *(_MDL **)(this + 0xa0) = p_Var9;
                goto LAB_14002bc5b;
              }
            }
          }
        }
      }
    }
  }
  goto LAB_14002c1ec;
}



===== RestoreRegisters @ 14002c288 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl HdaController::RestoreRegisters(void) __ptr64 */

long __thiscall HdaController::RestoreRegisters(HdaController *this)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined8 *puVar7;
  ulonglong uVar8;
  char cVar9;
  longlong lVar10;
  bool bVar11;
  longlong local_res8;
  undefined4 uVar12;
  undefined4 in_stack_ffffffffffffff2c;
  undefined2 uVar13;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 local_78 [2];
  undefined8 local_70;
  HdaController *local_68;
  code *local_60;
  HdaController *local_58;
  undefined8 local_50;
  HdaController local_48;
  undefined1 local_47;
  code *local_40;
  
  bVar1 = true;
  uVar12 = 6;
  HDABusWmiLogETW(1,2,'\x04','\x04',6,0,0,0);
  *(undefined2 *)(this + 200) = 1;
  this[0xca] = (HdaController)0x1;
  *(undefined4 *)(this + 0xe8) = 0;
  if (this[0x9606] == (HdaController)0x0) {
    MmGetPhysicalAddress(*(undefined8 *)(this + 0xb8));
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x44) = extraout_var;
    LOCK();
    UNLOCK();
    uVar2 = MmGetPhysicalAddress(*(undefined8 *)(this + 0xb8));
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x40) = uVar2;
    LOCK();
    UNLOCK();
    MmGetPhysicalAddress(*(undefined8 *)(this + 0xc0));
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x54) = extraout_var_00;
    LOCK();
    UNLOCK();
    lVar10 = MmGetPhysicalAddress(*(undefined8 *)(this + 0xc0));
LAB_14002c3e2:
    *(int *)(*(longlong *)(this + 0x58) + 0x50) = (int)lVar10;
  }
  else {
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x44) = *(undefined4 *)(this + 0x9c);
    LOCK();
    UNLOCK();
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x40) = *(undefined4 *)(this + 0x98);
    LOCK();
    UNLOCK();
    if (this[0x82] == (HdaController)0x0) {
      lVar10 = *(longlong *)(this + 0x98) + 0x800;
      *(int *)(*(longlong *)(this + 0x58) + 0x54) = (int)((ulonglong)lVar10 >> 0x20);
      LOCK();
      UNLOCK();
      goto LAB_14002c3e2;
    }
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x54) = *(undefined4 *)(this + 0xb4);
    LOCK();
    UNLOCK();
    *(undefined4 *)(*(longlong *)(this + 0x58) + 0x50) = *(undefined4 *)(this + 0xb0);
  }
  LOCK();
  UNLOCK();
  if ((*(byte *)(*(longlong *)(this + 0x58) + 0x4e) & 0x40) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
       (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar9 = '\0';
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar9 != '\0') || (bVar11)) {
      uVar13 = 0x1a;
LAB_14002c9bd:
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,bVar11,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                 CONCAT44(in_stack_ffffffffffffff2c,uVar12),0xd,uVar13,
                 &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
    }
  }
  else {
    *(byte *)(*(longlong *)(this + 0x58) + 0x4e) =
         *(byte *)(*(longlong *)(this + 0x58) + 0x4e) & 0xfe | 2;
    LOCK();
    UNLOCK();
    if ((*(byte *)(*(longlong *)(this + 0x58) + 0x5e) & 0x40) != 0) {
      *(byte *)(*(longlong *)(this + 0x58) + 0x5e) =
           *(byte *)(*(longlong *)(this + 0x58) + 0x5e) & 0xfe | 2;
      LOCK();
      UNLOCK();
      if (1 < *(ushort *)(this + 0x9670)) {
        for (puVar7 = (undefined8 *)FirstEntrySList(this + 0x9660); puVar7 != (undefined8 *)0x0;
            puVar7 = (undefined8 *)*puVar7) {
          *(undefined2 *)(*(longlong *)puVar7[2] + 8) = 0;
        }
      }
      uVar3 = KeQueryTimeIncrement();
      if (uVar3 < 0x145a) {
        uVar8 = 0x145a;
      }
      else {
        uVar8 = (ulonglong)(uVar3 + 1);
      }
      local_res8 = -uVar8;
      HDABusWmiLogETW(1,2,'\x04','\x04',6,0,1,0);
      KeDelayExecutionThread(0,0,&local_res8);
      uVar12 = 6;
      HDABusWmiLogETW(1,2,'\x04','\x04',6,0,2,0);
      LOCK();
      *(ushort *)(this + 0x94a4) =
           *(ushort *)(this + 0x94a4) | *(ushort *)(*(longlong *)(this + 0x58) + 0xe) & 0x7fff;
      UNLOCK();
      *(undefined2 *)(*(longlong *)(this + 0x58) + 0xe) = 0x7fff;
      LOCK();
      UNLOCK();
      if (*(int *)(this + 0x40) == 0) {
        memset(local_78,0,0x50);
        local_78[0] = 3;
        local_70 = (**(code **)(WdfFunctions_01025 + 0x108))
                             (WdfDriverGlobals,*(undefined8 *)(this + 0x70));
        local_60 = MsiIsr;
        local_48 = this[0x2c];
        local_40 = Isr;
        local_50 = 0;
        local_47 = 0;
        local_68 = this + 0x48;
        local_58 = this;
        iVar4 = IoConnectInterruptEx(local_78);
        if (iVar4 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          if ((cVar9 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT44(in_stack_ffffffffffffff2c,uVar12),1,0x1c,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
          }
          goto LAB_14002ca3e;
        }
        *(undefined4 *)(this + 0x40) = local_78[0];
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar9 = '\0';
        }
        if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_D
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_stack_ffffffffffffff2c,uVar12),1,0x1d,
                     &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)local_78[0]);
        }
        local_a0 = (**(code **)(WdfFunctions_01025 + 0x108))
                             (WdfDriverGlobals,*(undefined8 *)(this + 0x70));
        local_90 = *(undefined4 *)(this + 0x40);
        local_88 = *(undefined8 *)(this + 0x48);
        local_a8 = 0x28;
        local_98 = 0;
        local_8c = 0;
        iVar4 = PcAddStreamResource(local_a0,0,&local_a8,this + 0x50);
        if (iVar4 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
             (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          if ((cVar9 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_d
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT44(in_stack_ffffffffffffff2c,uVar12),0xd,0x1e,
                       &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar4);
          }
        }
      }
      if (1 < *(ushort *)(this + 0x9670)) {
        uVar3 = 0;
        if (*(int *)(this + 0x16c) != 0) {
          do {
            lVar10 = (ulonglong)(*(int *)(this + 0x168) + uVar3) * 0xd8;
            if (this[lVar10 + 0x20c] != (HdaController)0x0) {
              MapActiveStreamId(this,(uchar)this[lVar10 + 0x214],(uchar)this[lVar10 + 0x215]);
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(this + 0x16c));
        }
        uVar3 = 0;
        if (*(int *)(this + 0x170) != 0) {
          do {
            uVar5 = *(int *)(this + 0x16c) + uVar3 + *(int *)(this + 0x168);
            if (0x1d < uVar5) break;
            lVar10 = (ulonglong)uVar5 * 0xd8;
            if ((this[lVar10 + 0x20c] != (HdaController)0x0) &&
               (*(int *)(this + lVar10 + 0x208) == 4)) {
              MapActiveStreamId(this,(uchar)this[lVar10 + 0x214],(uchar)this[lVar10 + 0x215]);
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(this + 0x170));
        }
      }
      *(uint *)(*(longlong *)(this + 0x58) + 8) = *(uint *)(*(longlong *)(this + 0x58) + 8) | 0x100;
      LOCK();
      UNLOCK();
      *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
           *(uint *)(*(longlong *)(this + 0x58) + 0x20) | 0x40000000;
      LOCK();
      UNLOCK();
      *(uint *)(*(longlong *)(this + 0x58) + 0x20) =
           *(uint *)(*(longlong *)(this + 0x58) + 0x20) | 0x80000000;
      LOCK();
      UNLOCK();
      *(undefined1 *)(*(longlong *)(this + 0x58) + 0x5a) = 0xc0;
      LOCK();
      UNLOCK();
      *(byte *)(*(longlong *)(this + 0x58) + 0x5c) =
           *(byte *)(*(longlong *)(this + 0x58) + 0x5c) | 1;
      LOCK();
      UNLOCK();
      *(byte *)(*(longlong *)(this + 0x58) + 0x5c) =
           *(byte *)(*(longlong *)(this + 0x58) + 0x5c) | 4;
      LOCK();
      UNLOCK();
      lVar6 = SetRirbDmaState(this,'\x01');
      if (-1 < lVar6) {
        *(byte *)(*(longlong *)(this + 0x58) + 0x4c) =
             *(byte *)(*(longlong *)(this + 0x58) + 0x4c) | 1;
        LOCK();
        UNLOCK();
        *(ushort *)(*(longlong *)(this + 0x58) + 0xc) =
             (*(ushort *)(*(longlong *)(this + 0x58) + 0xc) ^ *(ushort *)(this + 0x94a8)) & 0x7fff ^
             *(ushort *)(*(longlong *)(this + 0x58) + 0xc);
        LOCK();
        UNLOCK();
        return 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
         (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar9 = '\0';
      }
      if ((cVar9 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   CONCAT44(in_stack_ffffffffffffff2c,uVar12),0xd,0x1f,
                   &WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids);
      }
      iVar4 = -0x3fffffff;
      goto LAB_14002ca3e;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
       (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar9 = '\0';
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar9 != '\0') || (bVar11)) {
      uVar13 = 0x1b;
      goto LAB_14002c9bd;
    }
  }
  iVar4 = -0x3fffffff;
LAB_14002ca3e:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    bVar1 = false;
  }
  if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_stack_ffffffffffffff2c,uVar12)
               ,0xd,0x20,&WPP_f173a9499c9f3c2a52d6b3d0522f71a6_Traceguids,(char)iVar4);
  }
  return iVar4;
}



===== __security_init_cookie @ 14002d008 =====

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



===== wil_InitializeFeatureStaging @ 14002d03c =====

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
    ppuVar4 = &wil_details_featureDescriptors_a;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002d12c =====

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
  ppuVar3 = &wil_details_featureDescriptors_a;
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


