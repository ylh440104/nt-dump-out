
===== _tlgWriteTransfer_EtwWriteTransfer @ 1c0001008 =====

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



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_> @ 1c00010ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByRef<16>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperBinary,struct _tlgWrapperByVal<4>,struct _tlgWrapperByVal<1> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<1> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperBinary const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperByVal<1> *param_8,_tlgWrapperByRef<16> *param_9,_tlgWrapperBinary *param_10,
          _tlgWrapperByVal<8> *param_11,_tlgWrapperByVal<1> *param_12,_tlgWrapperBinary *param_13,
          _tlgWrapperByVal<8> *param_14,_tlgWrapperByVal<1> *param_15,_tlgWrapperBinary *param_16,
          _tlgWrapperByVal<8> *param_17,_tlgWrapperByVal<1> *param_18,_tlgWrapperBinary *param_19,
          _tlgWrapperByVal<8> *param_20,_tlgWrapperByVal<1> *param_21,_tlgWrapperBinary *param_22,
          _tlgWrapperByVal<8> *param_23,_tlgWrapperByVal<1> *param_24,_tlgWrapperBinary *param_25,
          _tlgWrapperByVal<8> *param_26,_tlgWrapperByVal<1> *param_27,_tlgWrapperBinary *param_28,
          _tlgWrapperByVal<8> *param_29,_tlgWrapperByVal<1> *param_30,_tlgWrapperBinary *param_31,
          _tlgWrapperByVal<8> *param_32,_tlgWrapperByVal<1> *param_33,_tlgWrapperBinary *param_34,
          _tlgWrapperByVal<4> *param_35,_tlgWrapperByVal<1> *param_36)

{
  long lVar1;
  undefined1 auStackY_2f8 [32];
  undefined8 local_2c8 [4];
  _tlgWrapperByVal<8> *local_2a8;
  undefined8 local_2a0;
  _tlgWrapperByVal<4> *local_298;
  undefined8 local_290;
  _tlgWrapperByVal<4> *local_288;
  undefined8 local_280;
  _tlgWrapperByVal<1> *local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined8 local_260;
  uint *local_258;
  undefined8 local_250;
  undefined8 local_248;
  uint local_240 [2];
  _tlgWrapperByVal<8> *local_238;
  undefined8 local_230;
  _tlgWrapperByVal<1> *local_228;
  undefined8 local_220;
  uint *local_218;
  undefined8 local_210;
  undefined8 local_208;
  uint local_200 [2];
  _tlgWrapperByVal<8> *local_1f8;
  undefined8 local_1f0;
  _tlgWrapperByVal<1> *local_1e8;
  undefined8 local_1e0;
  uint *local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  uint local_1c0 [2];
  _tlgWrapperByVal<8> *local_1b8;
  undefined8 local_1b0;
  _tlgWrapperByVal<1> *local_1a8;
  undefined8 local_1a0;
  uint *local_198;
  undefined8 local_190;
  undefined8 local_188;
  uint local_180 [2];
  _tlgWrapperByVal<8> *local_178;
  undefined8 local_170;
  _tlgWrapperByVal<1> *local_168;
  undefined8 local_160;
  uint *local_158;
  undefined8 local_150;
  undefined8 local_148;
  uint local_140 [2];
  _tlgWrapperByVal<8> *local_138;
  undefined8 local_130;
  _tlgWrapperByVal<1> *local_128;
  undefined8 local_120;
  uint *local_118;
  undefined8 local_110;
  undefined8 local_108;
  uint local_100 [2];
  _tlgWrapperByVal<8> *local_f8;
  undefined8 local_f0;
  _tlgWrapperByVal<1> *local_e8;
  undefined8 local_e0;
  uint *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  uint local_c0 [2];
  _tlgWrapperByVal<8> *local_b8;
  undefined8 local_b0;
  _tlgWrapperByVal<1> *local_a8;
  undefined8 local_a0;
  uint *local_98;
  undefined8 local_90;
  undefined8 local_88;
  uint local_80 [2];
  _tlgWrapperByVal<8> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<1> *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<1> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_2f8;
  local_28 = param_36;
  local_38 = param_35;
  local_58 = local_40;
  local_48 = *(undefined8 *)param_34;
  local_40[0] = (uint)*(ushort *)(param_34 + 8);
  local_68 = param_33;
  local_78 = param_32;
  local_98 = local_80;
  local_88 = *(undefined8 *)param_31;
  local_80[0] = (uint)*(ushort *)(param_31 + 8);
  local_a8 = param_30;
  local_b8 = param_29;
  local_d8 = local_c0;
  local_c8 = *(undefined8 *)param_28;
  local_c0[0] = (uint)*(ushort *)(param_28 + 8);
  local_e8 = param_27;
  local_f8 = param_26;
  local_118 = local_100;
  local_108 = *(undefined8 *)param_25;
  local_100[0] = (uint)*(ushort *)(param_25 + 8);
  local_128 = param_24;
  local_138 = param_23;
  local_158 = local_140;
  local_148 = *(undefined8 *)param_22;
  local_140[0] = (uint)*(ushort *)(param_22 + 8);
  local_168 = param_21;
  local_178 = param_20;
  local_20 = 1;
  local_30 = 4;
  local_50 = 2;
  local_40[1] = 0;
  local_60 = 1;
  local_70 = 8;
  local_90 = 2;
  local_80[1] = 0;
  local_a0 = 1;
  local_b0 = 8;
  local_d0 = 2;
  local_c0[1] = 0;
  local_e0 = 1;
  local_f0 = 8;
  local_110 = 2;
  local_100[1] = 0;
  local_120 = 1;
  local_130 = 8;
  local_150 = 2;
  local_140[1] = 0;
  local_160 = 1;
  local_198 = local_180;
  local_170 = 8;
  local_190 = 2;
  local_188 = *(undefined8 *)param_19;
  local_180[0] = (uint)*(ushort *)(param_19 + 8);
  local_1a8 = param_18;
  local_1b8 = param_17;
  local_1d8 = local_1c0;
  local_1c8 = *(undefined8 *)param_16;
  local_1c0[0] = (uint)*(ushort *)(param_16 + 8);
  local_1e8 = param_15;
  local_1f8 = param_14;
  local_218 = local_200;
  local_208 = *(undefined8 *)param_13;
  local_200[0] = (uint)*(ushort *)(param_13 + 8);
  local_228 = param_12;
  local_238 = param_11;
  local_258 = local_240;
  local_248 = *(undefined8 *)param_10;
  local_240[0] = (uint)*(ushort *)(param_10 + 8);
  local_180[1] = 0;
  local_1a0 = 1;
  local_1b0 = 8;
  local_268 = *(undefined8 *)param_9;
  local_278 = param_8;
  local_288 = param_7;
  local_298 = param_6;
  local_2a8 = param_5;
  local_1d0 = 2;
  local_1c0[1] = 0;
  local_1e0 = 1;
  local_1f0 = 8;
  local_210 = 2;
  local_200[1] = 0;
  local_220 = 1;
  local_230 = 8;
  local_250 = 2;
  local_240[1] = 0;
  local_260 = 0x10;
  local_270 = 1;
  local_280 = 4;
  local_290 = 4;
  local_2a0 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c000c0f0,param_2,0,0,0x2b,local_2c8);
  return lVar1;
}



===== __report_gsfailure @ 1c0001500 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== CheckForTestCombos @ 1c0001510 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckForTestCombos(longlong param_1,uint param_2)

{
  int iVar1;
  
  if (g_TestCombosEnabled != '\0') {
    if ((param_2 & 0xc) == 0xc) {
      iVar1 = *(int *)(param_1 + 0x110);
      if (iVar1 == 0) {
        *(longlong *)(param_1 + 0x118) = _DAT_fffff78000000014;
        *(undefined4 *)(param_1 + 0x110) = 1;
      }
      else {
        if (iVar1 == 2) {
          *(undefined4 *)(param_1 + 0x110) = 4;
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0xe2,0,0,0,0);
        }
        if (iVar1 == 3) {
          *(undefined4 *)(param_1 + 0x110) = 4;
        }
      }
    }
    else {
      if ((param_2 & 0xc) != 0) {
        if (*(int *)(param_1 + 0x110) != 1) {
          return;
        }
        if (30000000 < _DAT_fffff78000000014 - *(longlong *)(param_1 + 0x118)) {
          *(uint *)(param_1 + 0x110) = (param_2 & 4 | 8) >> 2;
          return;
        }
      }
      *(undefined4 *)(param_1 + 0x110) = 0;
    }
  }
  return;
}



===== ChildHidReadReport @ 1c00015e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ChildHidReadReport(longlong param_1,undefined8 param_2,char *param_3)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined1 auStackY_b8 [32];
  undefined8 in_stack_ffffffffffffff68;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  iVar3 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x7a);
  }
  *param_3 = '\0';
  puVar5 = &local_68;
  local_48 = 0;
  uStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2);
  if (uStack_60 < *(uint *)(param_1 + 0x40)) {
    iVar3 = -0x3fffffdd;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffdd;
    }
    WPP_RECORDER_SF_qqLLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x48));
    if (*(uint *)(param_1 + 0x84) != *(uint *)(param_1 + 0x88)) {
      puVar5 = (undefined8 *)(ulonglong)*(uint *)(param_1 + 0x40);
      uVar4 = *(uint *)(param_1 + 0x84) % 10;
      uVar6 = (ulonglong)uVar4;
      lVar1 = param_1 + (ulonglong)uVar4 * 4;
      iVar3 = RequestCopyFromBuffer(param_2,lVar1 + 0x50 + uVar6,(longlong)puVar5);
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x7d,
                             in_stack_ffffffffffffff68,(char)*(undefined8 *)(param_1 + 8),
                             (char)iVar3);
        }
      }
      else {
        *param_3 = '\x01';
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          bVar2 = *(byte *)(uVar6 * 5 + 0x50 + param_1);
          WPP_RECORDER_SF_qdDd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar2,puVar5,0x7c,
                     in_stack_ffffffffffffff68,(char)*(undefined8 *)(param_1 + 8),bVar2,
                     (char)*(undefined4 *)(uVar6 + 0x51 + lVar1),
                     (char)*(undefined4 *)(param_1 + 0x84));
        }
        *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x48));
    if (*param_3 == '\0') {
      puVar5 = *(undefined8 **)(param_1 + 0x18);
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x7e,
                             in_stack_ffffffffffffff68,(char)*(undefined8 *)(param_1 + 8),
                             (char)iVar3);
        }
        *param_3 = '\x01';
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar5,0x7f);
  }
  return iVar3;
}



===== EnqueueInputReport @ 1c0001890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EnqueueInputReport(undefined4 *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined8 in_stack_ffffffffffffffd8;
  
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_2 + 0x48));
  uVar3 = *(uint *)(param_2 + 0x88);
  uVar4 = *(uint *)(param_2 + 0x84) % 10;
  if (uVar4 == (uVar3 + 1) % 10) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      lVar1 = param_2 + (ulonglong)uVar4 * 4;
      WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar1,(ulonglong)uVar4,0x75,
                          in_stack_ffffffffffffffd8,(char)*(undefined8 *)(param_2 + 8),
                          *(undefined1 *)((ulonglong)uVar4 * 5 + 0x50 + param_2),
                          (char)*(undefined4 *)((ulonglong)uVar4 + 0x51 + lVar1));
      uVar3 = *(uint *)(param_2 + 0x88);
    }
    *(int *)(param_2 + 0x84) = *(int *)(param_2 + 0x84) + 1;
  }
  lVar2 = (ulonglong)(uVar3 % 10) + 0x10;
  lVar1 = param_2 + lVar2 * 4;
  *(undefined4 *)(lVar2 + lVar1) = *param_1;
  *(undefined1 *)((ulonglong)(uVar3 % 10) + 0x14 + lVar1) = *(undefined1 *)(param_1 + 1);
  *(int *)(param_2 + 0x88) = *(int *)(param_2 + 0x88) + 1;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_2 + 0x48));
  return;
}



===== EvtChildHidDeviceIoInternalDeviceControl @ 1c00019c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtChildHidDeviceIoInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               uint param_5)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 *puVar4;
  char cVar5;
  ulonglong uVar6;
  char local_18 [16];
  
  local_18[0] = '\x01';
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x49);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_CHILD_HID_DEVICE_CONTEXT_TYPE_INFO_1c000c068);
  if (param_5 < 0xb0028) {
    if (param_5 == 0xb0027) {
      puVar4 = (undefined1 *)(lVar3 + 0x20);
      uVar6 = 0x20;
    }
    else if (param_5 == 0xb0003) {
      uVar6 = (ulonglong)g_HidDescriptor;
      puVar4 = &g_HidDescriptor;
    }
    else {
      if (param_5 != 0xb0007) {
        if (param_5 != 0xb000b) goto LAB_1c0001a87;
        uVar1 = ChildHidReadReport(lVar3,param_2,local_18);
        uVar6 = (ulonglong)uVar1;
        cVar5 = local_18[0];
        goto LAB_1c0001a8d;
      }
      puVar4 = &g_ReportDescriptorMobile;
      uVar6 = (ulonglong)DAT_1c000c1c7;
      if (g_UseMobileButtonsMapping == '\0') {
        puVar4 = &g_ReportDescriptorDesktop;
      }
    }
    uVar1 = RequestCopyFromBuffer(param_2,puVar4,uVar6);
    uVar6 = (ulonglong)uVar1;
  }
  else {
LAB_1c0001a87:
    uVar6 = 0xc0000002;
    cVar5 = '\x01';
LAB_1c0001a8d:
    if (cVar5 == '\0') goto LAB_1c0001aaf;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2);
LAB_1c0001aaf:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar6,0x4a);
  }
  return;
}



===== EvtChildRawDeviceIoDeviceControl @ 1c0001b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EvtChildRawDeviceIoDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined1 auStackY_108 [32];
  undefined8 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  uint local_a8 [2];
  undefined8 local_a0;
  uint *local_98;
  uint *local_90;
  uint *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  wchar_t local_70 [24];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  builtin_wcsncpy(local_70 + 0x10,L"InCS",5);
  local_78 = local_70;
  builtin_wcsncpy(local_70,L"ButtonsToDisable",0x10);
  bVar1 = false;
  uVar11 = 0;
  local_98 = (uint *)0x0;
  local_90 = (uint *)0x0;
  local_88 = (uint *)0x0;
  local_a8[0] = 0;
  local_a0 = 0;
  local_80 = 0x2a0028;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x51);
  }
  uVar8 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar8,PTR__WDF_CHILD_RAW_DEVICE_CONTEXT_TYPE_INFO_1c000c040);
  puVar5 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(lVar4 + 8),
                      PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018);
  uVar14 = (undefined1)param_2;
  if (param_5 == 0xb02a8) {
    uVar8 = 8;
    uVar12 = 0;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_98);
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001ca7;
      uVar10 = 0x52;
LAB_1c0001dd1:
      uVar13 = (undefined1)*puVar5;
LAB_1c0001d71:
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar8,uVar10,uVar12,uVar13,
                          uVar14,(char)uVar2);
      goto LAB_1c0001ca7;
    }
    puVar6 = local_a8;
    uVar7 = (ulonglong)*local_98;
    uVar8 = GPIOButtonTypeToBtnconvButtonID(*local_98,puVar6);
    uVar2 = (uint)uVar8;
    if (-1 < (int)uVar2) {
      if ((local_a8[0] < 0xc) && (local_a8[0] != 1)) {
        if (local_a8[0] < 0xc) {
          uVar2 = 1 << ((byte)local_a8[0] & 0x1f);
        }
        else {
          if ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) {
            RtlAssert("FALSE",
                      "onecore\\drivers\\input\\hid\\miniports\\buttonconverter\\src\\btnconv.c",
                      0xb04,0);
          }
          uVar2 = 0;
        }
        uVar8 = 0;
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar5[0x24]);
        if (*(char *)(puVar5 + 0x28) == '\0') {
          if ((char)local_98[1] == '\0') {
            uVar11 = *(uint *)((longlong)puVar5 + 300) | uVar2;
          }
          else {
            uVar11 = ~uVar2 & *(uint *)((longlong)puVar5 + 300);
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qqLLdDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          if (uVar11 != *(uint *)((longlong)puVar5 + 300)) {
            *(uint *)((longlong)puVar5 + 300) = uVar11;
            bVar1 = true;
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar8,0x55,uVar12,
                              (char)*puVar5,uVar14,1);
        }
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar5[0x24]);
        uVar2 = 0;
        if (bVar1) {
          uVar8 = 1;
          uVar12 = 0;
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x180))(WdfDriverGlobals,*puVar5,1,0x2001f);
          if (iVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar8,0x57,uVar12,
                                  (char)*puVar5,uVar14,(char)iVar3);
            }
          }
          else {
            puVar9 = &local_80;
            iVar3 = (**(code **)(WdfFunctions_01015 + 0x7b0))
                              (WdfDriverGlobals,local_a0,puVar9,uVar11);
            if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
               ) {
              WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar9,0x58,uVar12,
                                  (char)*puVar5,uVar14,(char)iVar3);
            }
            (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_a0);
            local_a0 = 0;
          }
        }
      }
      else {
        uVar2 = 0xc0000010;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqLd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,uVar7,0x54,uVar12,
                     (char)*puVar5,uVar14,(byte)local_a8[0],0x10);
        }
      }
      goto LAB_1c0001ca7;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001ca7;
    uVar10 = 0x53;
  }
  else {
    if (param_5 != 0xb02ac) {
      uVar2 = 0xc0000002;
      goto LAB_1c0001ca7;
    }
    uVar8 = 4;
    uVar12 = 0;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,&local_90);
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001ca7;
      uVar13 = (undefined1)*puVar5;
      uVar10 = 0x59;
      goto LAB_1c0001d71;
    }
    uVar8 = 4;
    uVar12 = 0;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,4,&local_88);
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001ca7;
      uVar10 = 0x5a;
      goto LAB_1c0001dd1;
    }
    puVar6 = local_a8;
    uVar7 = (ulonglong)*local_90;
    uVar8 = GPIOButtonTypeToBtnconvButtonID(*local_90,puVar6);
    uVar2 = (uint)uVar8;
    if (-1 < (int)uVar2) {
      uVar2 = GetButtonEnabled((longlong)puVar5,local_a8[0],local_88);
      if (-1 < (int)uVar2) {
        (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,4);
      }
      goto LAB_1c0001ca7;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001ca7;
    uVar10 = 0x5b;
  }
  WPP_RECORDER_SF_qqLd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,uVar7,uVar10,uVar12,(char)*puVar5,
             uVar14,(char)uVar7,(char)uVar2);
LAB_1c0001ca7:
  uVar7 = (ulonglong)uVar2;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar7,0x5c);
  }
  return;
}



===== EvtDeviceButtonReadCompletion @ 1c00021d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EvtDeviceButtonReadCompletion
               (undefined *param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  short *psVar6;
  short *psVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 uVar14;
  undefined1 uVar15;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar16;
  undefined8 local_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  local_38 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x68);
  }
  puVar11 = PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018;
  puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_4);
  uVar15 = SUB81(param_1,0);
  if (*(int *)(param_3 + 8) < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,0x69,
                          in_stack_ffffffffffffffa8,(char)*puVar4,uVar15,(char)*(int *)(param_3 + 8)
                         );
    }
    if ((*(int *)(param_3 + 8) == -0x3ffffee0) || (*(int *)(param_3 + 8) == -0x3fffff63))
    goto LAB_1c0002654;
  }
  else if (*(longlong *)(param_3 + 0x20) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x610))
                      (WdfDriverGlobals,*(undefined8 *)(param_3 + 0x18),0);
    if (lVar5 != 0) {
      puVar1 = (uint *)(puVar4 + 0x19);
      puVar11 = (undefined *)puVar4[0x18];
      *puVar1 = *(uint *)(puVar4 + 0xc);
      uVar14 = puVar4[3];
      iVar3 = HidP_GetUsagesEx(0,0,puVar11,puVar1,uVar14,lVar5,
                               CONCAT44(uVar16,(uint)*(ushort *)((longlong)puVar4 + 0x24)));
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,0x6b,uVar14,
                              (char)*puVar4,uVar15,(char)iVar3);
        }
      }
      else {
        uVar9 = 0;
        psVar7 = (short *)puVar4[0x18];
        if (*puVar1 != 0) {
          uVar13 = (ulonglong)*puVar1;
          do {
            psVar6 = &g_ButtonUsages;
            puVar11 = (undefined *)0x0;
            do {
              if ((psVar6[1] == psVar7[1]) && (*psVar6 == *psVar7)) {
                uVar9 = uVar9 | 1 << ((byte)puVar11 & 0x1f);
                break;
              }
              uVar10 = (int)puVar11 + 1;
              puVar11 = (undefined *)(ulonglong)uVar10;
              psVar6 = psVar6 + 2;
            } while (uVar10 < 0xc);
            psVar7 = psVar7 + 2;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
        }
        uVar8 = puVar4[0x1a];
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
        if ((uVar9 & 2) == 0) {
          if (*(char *)(puVar4 + 0x2b) != '\0') {
            *(undefined1 *)(puVar4 + 0x2b) = 0;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qI(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,puVar11,0x6d,
                                 uVar14,(char)*puVar4,(char)_DAT_fffff78000000008);
            }
            uVar14 = 0;
            goto LAB_1c00024b9;
          }
        }
        else if (*(char *)(puVar4 + 0x2b) == '\0') {
          *(undefined1 *)(puVar4 + 0x2b) = 1;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qI(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,puVar11,0x6c,uVar14,
                               (char)*puVar4,(char)_DAT_fffff78000000008);
          }
          if (*(char *)((longlong)puVar4 + 0x179) == '\0') {
            *(undefined1 *)((longlong)puVar4 + 0x179) = 1;
            TraceLoggingFirstPowerButtonPress((longlong)puVar4);
          }
          uVar14 = 1;
LAB_1c00024b9:
          PoSetPowerButtonHoldState(uVar14);
        }
        uVar14 = ProcessButtonDowns(puVar4,uVar9);
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar4[0x1a]);
        if ((char)uVar14 != '\0') {
          puVar11 = PTR__WDF_CHILD_HID_DEVICE_CONTEXT_TYPE_INFO_1c000c068;
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,puVar4[1]);
          RundownInputReportQueue(lVar5);
        }
        if (uVar9 != 0) {
          TraceAggregateLoggingAnyButtonPress((longlong)puVar4,uVar9,(ulonglong)puVar11);
        }
      }
    }
  }
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  local_38 = 0x18;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,param_1,&local_38);
  uVar14 = 0;
  puVar11 = param_1;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x5b8))
                    (WdfDriverGlobals,puVar4[0xe],param_1,puVar4[0x11],0,0);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar12 = 0x6e;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,param_1,EvtDeviceButtonReadCompletion,param_4);
    puVar11 = (undefined *)puVar4[0xe];
    cVar2 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_1,puVar11,0);
    if (cVar2 != '\0') goto LAB_1c0002654;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar12 = 0x6f;
  }
  WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,uVar12,uVar14,
                      (char)*puVar4,uVar15,(char)iVar3);
LAB_1c0002654:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar11,0x70);
  }
  return;
}



===== EvtDevicePrepareHardware @ 1c00026b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EvtDevicePrepareHardware(undefined8 param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined *puVar11;
  undefined8 *puVar12;
  undefined2 uVar13;
  undefined2 *puVar14;
  bool bVar15;
  undefined1 auStackY_148 [32];
  code *pcVar16;
  code *pcVar17;
  undefined1 *puVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined8 local_f8;
  undefined *puStack_f0;
  undefined8 local_e8;
  ulonglong local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 *local_c0;
  undefined8 uStack_b8;
  code *local_b0;
  code *pcStack_a8;
  longlong local_a0;
  undefined8 local_98 [2];
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_e0 = 0;
  local_d8 = 0;
  local_98[0] = 0;
  uVar6 = 0x48;
  local_a0 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = (undefined8 *)0x0;
  uStack_b8 = 0;
  local_b0 = (code *)0x0;
  pcStack_a8 = (code *)0x0;
  memset(local_88,0,0x48);
  local_e8 = (ulonglong)local_e8._4_4_ << 0x20;
  local_f8 = 0;
  puStack_f0 = (undefined *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar6,0x32);
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018);
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  *(undefined1 *)(lVar5 + 0x158) = 0;
  *(undefined1 *)(lVar5 + 0xa0) = 0;
  *(undefined8 *)(lVar5 + 0xa8) = 0;
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x138))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,uVar7);
  puVar11 = &GUID_DEVINTERFACE_HID;
  pcVar16 = PnpEventHandler;
  iVar2 = IoRegisterPlugPlayNotification(2,1);
  uVar19 = (undefined1)param_1;
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002eb5;
    uVar13 = 0x33;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x98));
    bVar15 = *(char *)(lVar5 + 0xa0) == '\0';
    if (bVar15) {
      *(undefined8 *)(lVar5 + 0xa8) = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x98));
    if ((!bVar15) &&
       (uVar1 = IoUnregisterPlugPlayNotificationEx(0),
       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar11,0x35,pcVar16,uVar19,0
                          ,uVar1);
    }
    pcVar17 = (code *)&local_e0;
    puVar11 = (undefined *)0x0;
    iVar2 = SendHidIoctlSynchronously(uVar6,0xb01a8,0,0,(longlong)pcVar17,0xc);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002eb5;
      uVar13 = 0x36;
      pcVar16 = pcVar17;
    }
    else {
      uVar10 = local_e0 & 0xffffffff;
      puVar11 = (undefined *)0x434e5442;
      pcVar16 = (code *)ExAllocatePool2(0x40);
      *(code **)(lVar5 + 0x18) = pcVar16;
      if (pcVar16 == (code *)0x0) {
        iVar2 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002eb5;
        uVar13 = 0x37;
        iVar2 = (int)local_e0;
        pcVar16 = pcVar17;
LAB_1c00029d6:
        uVar1 = (undefined1)iVar2;
        iVar2 = -0x3fffff66;
        uVar20 = 0x9a;
LAB_1c00029da:
        WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,puVar11,uVar13,pcVar16
                            ,uVar19,uVar1,uVar20);
        goto LAB_1c0002eb5;
      }
      puVar11 = (undefined *)0x0;
      iVar2 = SendHidIoctlSynchronously(uVar6,0xb0193,0,0,(longlong)pcVar16,(int)local_e0);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002eb5;
        uVar13 = 0x38;
      }
      else {
        iVar2 = HidP_GetCaps(*(undefined8 *)(lVar5 + 0x18),lVar5 + 0x20);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0002eb5;
          uVar13 = 0x39;
        }
        else {
          uVar3 = HidP_MaxUsageListLength(0,0,*(undefined8 *)(lVar5 + 0x18));
          *(uint *)(lVar5 + 0x60) = uVar3;
          uVar10 = (ulonglong)uVar3 << 2;
          puVar11 = (undefined *)0x434e5442;
          lVar8 = ExAllocatePool2(0x40);
          *(longlong *)(lVar5 + 0xc0) = lVar8;
          if (lVar8 == 0) {
            iVar2 = -0x3fffff66;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0002eb5;
            uVar13 = 0x3a;
            iVar2 = *(int *)(lVar5 + 0x60) << 2;
            goto LAB_1c00029d6;
          }
          pcVar16 = (code *)(ulonglong)*(ushort *)(lVar5 + 0x24);
          puVar11 = (undefined *)0x200;
          uVar10 = 0;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,0,0x200,0x434e5442);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0002eb5;
            uVar1 = (undefined1)*(undefined2 *)(lVar5 + 0x24);
            uVar13 = 0x3b;
LAB_1c0002b2c:
            uVar20 = (undefined1)iVar2;
            goto LAB_1c00029da;
          }
          if (*(ushort *)(lVar5 + 0x28) != 0) {
            pcVar16 = (code *)(ulonglong)*(ushort *)(lVar5 + 0x28);
            puVar11 = (undefined *)0x200;
            uVar10 = 0;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,0,0x200,0x434e5442);
            if (iVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c0002eb5;
              uVar1 = (undefined1)*(undefined2 *)(lVar5 + 0x28);
              uVar13 = 0x3c;
              goto LAB_1c0002b2c;
            }
          }
          *(undefined4 *)(lVar5 + 100) = 0;
          puVar14 = &DAT_1c000c192;
          uVar3 = 0;
          do {
            uVar6 = 0;
            puVar18 = local_88;
            iVar2 = HidP_GetSpecificButtonCaps(0,*puVar14,0,puVar14[-1]);
            if (-1 < iVar2) {
              uVar9 = 1 << ((byte)uVar3 & 0x1f);
              *(uint *)(lVar5 + 100) = *(uint *)(lVar5 + 100) | uVar9;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar9,uVar6
                                   ,0x3d,puVar18,uVar19,(byte)uVar3);
              }
            }
            uVar3 = uVar3 + 1;
            puVar14 = puVar14 + 2;
          } while (uVar3 < 0xc);
          puVar12 = &local_f8;
          local_f8 = 0x18;
          local_e8 = 0;
          uVar7 = CONCAT44((int)((ulonglong)puVar18 >> 0x20),1);
          puStack_f0 = &DEVPKEY_ButtonConverter_SASSupport;
          uVar6 = param_1;
          iVar4 = (**(code **)(WdfFunctions_01015 + 0xd98))(WdfDriverGlobals,param_1,puVar12,0x11);
          if ((iVar4 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),2);
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,0x3e,uVar7,
                               uVar19,(char)iVar2);
          }
          uVar3 = *(uint *)(lVar5 + 100) & *(uint *)(lVar5 + 300);
          *(uint *)(lVar5 + 300) = uVar3;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,puVar12,0x3f,uVar7,
                                uVar19,(char)*(uint *)(lVar5 + 100),(char)uVar3);
          }
          puVar11 = (undefined *)0x0;
          pcVar16 = (code *)local_88;
          iVar4 = HidP_GetSpecificButtonCaps(2,1,0,0xcb);
          iVar2 = 0;
          *(bool *)(lVar5 + 0x68) = iVar4 != -0x3feefffc;
          if (iVar4 == -0x3feefffc) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar11,0x43,pcVar16,
                                uVar19);
            }
            goto LAB_1c0002eb5;
          }
          iVar2 = 0;
          if (((g_UseMobileButtonsMapping == '\0') || (*(longlong *)(lVar5 + 0x10) != 0)) ||
             (iVar2 = CreateChildRawDevice(param_1), -1 < iVar2)) {
            *(undefined8 *)(lVar5 + 0x138) = 0;
            *(undefined8 *)(lVar5 + 0x140) = 0;
            *(undefined8 *)(lVar5 + 0x148) = 0;
            *(undefined8 *)(lVar5 + 0x150) = 0;
            local_c0 = (undefined8 *)&WNF_SEB_SYSTEM_LPE;
            pcStack_a8 = WnfEventStopCallback;
            uStack_b8 = 0;
            uStack_c8 = 0x100000000;
            local_b0 = WnfEventStartCallback;
            local_a0 = lVar5;
            iVar4 = EACreateAggregateEvent(&local_d0);
            if (iVar4 == 0) {
              if (g_UseMobileButtonsMapping != '\0') goto LAB_1c0002eb5;
              local_98[0] = 0x41840b3ea3bdb075;
              local_c0 = local_98;
              local_d0 = 0;
              pcStack_a8 = WnfEventStopCallback;
              uStack_b8 = 1;
              uStack_c8 = 0x100000000;
              local_b0 = WnfEventStartCallback;
              local_a0 = lVar5;
              iVar4 = EACreateAggregateEvent(&local_d0,lVar5 + 0x148);
              if (iVar4 == 0) goto LAB_1c0002eb5;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar13 = 0x42;
                goto LAB_1c0002df6;
              }
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar13 = 0x41;
LAB_1c0002df6:
              WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,uVar13,pcVar16
                                 ,uVar19,(char)iVar4);
            }
            iVar2 = -0x3fffffff;
            goto LAB_1c0002eb5;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0002eb5;
          uVar13 = 0x40;
        }
      }
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,uVar13,pcVar16,uVar19,
                     (char)iVar2);
LAB_1c0002eb5:
  TraceLoggingDeviceConfig(lVar5,iVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar11,0x44);
  }
  return iVar2;
}



===== EvtDeviceReleaseHardware @ 1c0002f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EvtDeviceReleaseHardware(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  longlong *plVar6;
  undefined *puVar7;
  undefined8 in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x45);
  }
  puVar7 = PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar5 = 0;
  plVar6 = (longlong *)(lVar4 + 0x138);
  do {
    if (*plVar6 != 0) {
      iVar3 = EADeleteAggregateEvent();
      if ((iVar3 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar7,0x46,
                            in_stack_ffffffffffffffc8,(char)param_1,(char)uVar5,(char)iVar3);
      }
      *plVar6 = 0;
      *(undefined1 *)(plVar6 + 1) = 0;
    }
    uVar5 = uVar5 + 1;
    plVar6 = plVar6 + 2;
  } while (uVar5 < 2);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x98));
  lVar1 = *(longlong *)(lVar4 + 0xa8);
  *(undefined8 *)(lVar4 + 0xa8) = 0;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x98));
  if (lVar1 != 0) {
    uVar2 = IoUnregisterPlugPlayNotificationEx(lVar1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar7,0x47,
                          in_stack_ffffffffffffffc8,(char)param_1,(char)lVar1,uVar2);
    }
  }
  if (*(longlong *)(lVar4 + 0x80) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x80));
    *(undefined8 *)(lVar4 + 0x80) = 0;
  }
  if (*(longlong *)(lVar4 + 0x88) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(lVar4 + 0x88) = 0;
  }
  if (*(longlong *)(lVar4 + 0x90) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(lVar4 + 0x90) = 0;
  }
  if (*(longlong *)(lVar4 + 0x70) != 0) {
    *(undefined1 *)(lVar4 + 0x78) = 0;
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x70));
    *(undefined8 *)(lVar4 + 0x70) = 0;
  }
  if (*(longlong *)(lVar4 + 0xc0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar4 + 0xc0),0);
    *(undefined8 *)(lVar4 + 0xc0) = 0;
  }
  if (*(longlong *)(lVar4 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar4 + 0x18),0);
    *(undefined8 *)(lVar4 + 0x18) = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0x48);
  }
  return 0;
}



===== EvtPowerButtonHoldTimerFunc @ 1c0003200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtPowerButtonHoldTimerFunc(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  bool bVar3;
  undefined1 local_res10;
  undefined4 local_res11;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x4b);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x4c,
                        in_stack_ffffffffffffffd8,(char)*param_2);
    }
  }
  puVar2 = PTR__WDF_CHILD_HID_DEVICE_CONTEXT_TYPE_INFO_1c000c068;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2[1]);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_2[0x1a]);
  bVar3 = *(int *)((longlong)param_2 + 0xdc) == 1;
  if (bVar3) {
    *(undefined4 *)((longlong)param_2 + 0xdc) = 2;
    local_res10 = 1;
    local_res11 = 0x14;
    EnqueueInputReport((undefined4 *)&local_res10,lVar1);
    local_res11 = 0;
    EnqueueInputReport((undefined4 *)&local_res10,lVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_2[0x1a]);
  if (bVar3) {
    RundownInputReportQueue(lVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0x4d);
  }
  return;
}



===== EvtPowerButtonLongHoldTimerFunc @ 1c0003370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtPowerButtonLongHoldTimerFunc(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  bool bVar3;
  undefined1 local_res10;
  undefined4 local_res11;
  undefined8 in_stack_ffffffffffffffd8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x4e);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x4f,
                        in_stack_ffffffffffffffd8,(char)*param_2);
    }
  }
  puVar2 = PTR__WDF_CHILD_HID_DEVICE_CONTEXT_TYPE_INFO_1c000c068;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2[1]);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_2[0x1a]);
  bVar3 = *(int *)((longlong)param_2 + 0xdc) != 0;
  if (bVar3) {
    *(undefined4 *)((longlong)param_2 + 0xdc) = 2;
    local_res10 = 1;
    local_res11 = 0x18;
    EnqueueInputReport((undefined4 *)&local_res10,lVar1);
    local_res11 = 0;
    EnqueueInputReport((undefined4 *)&local_res10,lVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_2[0x1a]);
  if (bVar3) {
    RundownInputReportQueue(lVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0x50);
  }
  return;
}



===== FillInputReportForDesktop @ 1c00034d8 =====

void FillInputReportForDesktop(undefined1 *param_1,int param_2,int param_3)

{
  *(undefined4 *)(param_1 + 1) = 0;
  if (param_3 == 0) {
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (param_2 != 0)) {
      RtlAssert("ComboType == BTNCONV_COMBO_OF_NONE",
                "onecore\\drivers\\input\\hid\\miniports\\buttonconverter\\src\\btnconv.c",0xf58,0);
    }
    *(uint *)(param_1 + 1) = *(uint *)(param_1 + 1) | 0x10;
  }
  else {
    if (param_3 == 1) {
      if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (param_2 != 0)) {
        RtlAssert("ComboType == BTNCONV_COMBO_OF_NONE",
                  "onecore\\drivers\\input\\hid\\miniports\\buttonconverter\\src\\btnconv.c",0xf52,0
                 );
      }
      *(uint *)(param_1 + 1) = *(uint *)(param_1 + 1) | 1;
      *param_1 = 3;
      return;
    }
    if (param_3 == 2) {
      if (param_2 != 0) {
        if (param_2 == 1) {
          *param_1 = 1;
          *(undefined4 *)(param_1 + 1) = 0x91;
          return;
        }
        if (param_2 == 2) {
LAB_1c0003571:
          *param_1 = 1;
          *(undefined4 *)(param_1 + 1) = 0x12;
          return;
        }
      }
      *param_1 = 2;
      *(undefined4 *)(param_1 + 1) = 1;
      return;
    }
    if (param_3 == 3) {
      if (param_2 != 0) {
        if (param_2 == 1) goto LAB_1c0003571;
        if (param_2 == 2) {
          *param_1 = 1;
          *(undefined4 *)(param_1 + 1) = 0xe0;
          return;
        }
      }
      *param_1 = 2;
      *(undefined4 *)(param_1 + 1) = 2;
      return;
    }
    if (param_3 != 4) {
      *param_1 = 0;
      return;
    }
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (param_2 != 0)) {
      RtlAssert("ComboType == BTNCONV_COMBO_OF_NONE",
                "onecore\\drivers\\input\\hid\\miniports\\buttonconverter\\src\\btnconv.c",0xf94,0);
    }
    *(uint *)(param_1 + 1) = *(uint *)(param_1 + 1) | 0x11;
  }
  *param_1 = 1;
  return;
}



===== GPIOButtonTypeToBtnconvButtonID @ 1c0003644 =====

undefined8 GPIOButtonTypeToBtnconvButtonID(int param_1,undefined4 *param_2)

{
  if (param_1 < 6) {
    if (param_1 == 5) {
      *param_2 = 5;
    }
    else if (param_1 == 0) {
      *param_2 = 1;
    }
    else if (param_1 == 1) {
      *param_2 = 0;
    }
    else if (param_1 == 2) {
      *param_2 = 2;
    }
    else if (param_1 == 3) {
      *param_2 = 3;
    }
    else {
      if (param_1 != 4) {
        return 0xc00000bb;
      }
      *param_2 = 4;
    }
  }
  else if (param_1 == 6) {
    *param_2 = 6;
  }
  else if (param_1 == 7) {
    *param_2 = 7;
  }
  else if (param_1 == 8) {
    *param_2 = 8;
  }
  else {
    if (param_1 != 10) {
      return 0xc00000bb;
    }
    *param_2 = 9;
  }
  return 0;
}



===== GetButtonEnabled @ 1c00036d4 =====

undefined4 GetButtonEnabled(longlong param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar2 = 0;
  puVar3 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x8f);
  }
  if ((int)param_2 < 0xc) {
    if (param_2 < 0xc) {
      uVar1 = 1 << ((byte)param_2 & 0x1f);
    }
    else {
      if ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) {
        puVar3 = (uint *)0xb04;
        RtlAssert("FALSE","onecore\\drivers\\input\\hid\\miniports\\buttonconverter\\src\\btnconv.c"
                  ,0xb04,0);
      }
      uVar1 = 0;
    }
    *param_3 = (uint)((*(uint *)(param_1 + 300) & uVar1) == 0);
  }
  else {
    uVar2 = 0xc0000010;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x90);
  }
  return uVar2;
}



===== PnpEventHandler @ 1c00037e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PnpEventHandler(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined4 *puVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  byte bVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  undefined2 uVar13;
  short *local_res8;
  undefined8 in_stack_fffffffffffffed8;
  undefined8 local_108;
  wchar_t *pwStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  ulonglong local_c8;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_6c;
  undefined4 local_68;
  
  local_c8 = local_c8 & 0xffffffff00000000;
  uVar11 = 0x88;
  iVar7 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  memset(&local_b8,0,0x88);
  local_res8 = (short *)0x0;
  local_108 = 0;
  pwStack_100 = (wchar_t *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar11,0x5d);
  }
  puVar12 = (undefined4 *)PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018;
  puVar9 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
  if ((*(longlong *)(param_1 + 4) != 0x11d046f0cb3a4004) ||
     (*(longlong *)(param_1 + 0xc) != 0x3f05139760008fb0)) goto LAB_1c0003cad;
  uVar11 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_2);
  uVar11 = (**(code **)(WdfFunctions_01015 + 0x598))(WdfDriverGlobals,uVar11);
  puVar12 = (undefined4 *)0x0;
  iVar7 = IoGetDeviceInterfaces(&GUID_DEVINTERFACE_HID,uVar11,0,&local_res8);
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003cad;
    uVar6 = (undefined1)*puVar9;
    uVar13 = 0x5e;
    bVar10 = 3;
LAB_1c0003938:
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar10,puVar12,uVar13,
                       in_stack_fffffffffffffed8,uVar6,(char)iVar7);
  }
  else {
    if (*local_res8 != 0) {
      RtlInitUnicodeString(&local_108,local_res8);
      uVar11 = *(undefined8 *)(param_1 + 0x28);
      puVar12 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar12 >> 8),1);
      iVar8 = RtlCompareUnicodeString(&local_108);
      if (iVar8 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar11,puVar12,0x5f,
                             in_stack_fffffffffffffed8,(char)param_2,pwStack_100);
        }
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar9[0x13]);
        lVar3 = puVar9[0x15];
        puVar9[0x15] = 0;
        *(undefined1 *)(puVar9 + 0x14) = 1;
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar9[0x13]);
        if (lVar3 != 0) {
          IoUnregisterPlugPlayNotificationEx(lVar3);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar12,0x60,
                                in_stack_fffffffffffffed8,(char)param_2,(char)lVar3,(char)iVar7);
          }
        }
        plVar1 = puVar9 + 0xe;
        puVar12 = (undefined4 *)0x0;
        iVar7 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_2,0,plVar1);
        if (iVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0003cad;
          uVar13 = 0x61;
        }
        else {
          puVar4 = *(undefined4 **)(param_1 + 0x28);
          puVar12 = &local_b8;
          local_b8 = 0x88;
          local_b4 = 2;
          local_88 = *puVar4;
          uStack_84 = puVar4[1];
          uStack_80 = puVar4[2];
          uStack_7c = puVar4[3];
          local_78 = 1;
          local_68 = 0x40;
          local_6c = 1;
          local_74 = 3;
          iVar7 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,*plVar1);
          if (iVar7 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0003cad;
            uVar13 = 0x62;
          }
          else {
            *(undefined1 *)(puVar9 + 0xf) = 1;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar12,99,
                                in_stack_fffffffffffffed8,(char)*puVar9);
            }
            local_e8 = 0;
            local_c8 = 0;
            uStack_e0 = 0x100000001;
            plVar2 = puVar9 + 0x10;
            uStack_f0 = 0;
            local_f8 = 0x38;
            uStack_d0 = 0;
            puVar12 = (undefined4 *)*plVar1;
            local_d8 = param_2;
            iVar7 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                              (WdfDriverGlobals,&local_f8,puVar12,plVar2);
            if (iVar7 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c0003cad;
              uVar13 = 100;
            }
            else {
              puVar12 = (undefined4 *)*plVar2;
              in_stack_fffffffffffffed8 = 0;
              iVar7 = (**(code **)(WdfFunctions_01015 + 0x5b8))
                                (WdfDriverGlobals,*plVar1,puVar12,puVar9[0x11],0,0);
              if (-1 < iVar7) {
                (**(code **)(WdfFunctions_01015 + 0x820))
                          (WdfDriverGlobals,*plVar2,EvtDeviceButtonReadCompletion,param_2);
                puVar12 = (undefined4 *)*plVar1;
                cVar5 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                                  (WdfDriverGlobals,*plVar2,puVar12,0);
                if (cVar5 != '\0') goto LAB_1c0003cad;
                uVar6 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,*plVar2);
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,0x66,
                                     in_stack_fffffffffffffed8,(char)*puVar9,uVar6);
                }
                goto LAB_1c0003ca8;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c0003cad;
              uVar13 = 0x65;
            }
          }
        }
        bVar10 = 2;
        uVar6 = (undefined1)*puVar9;
        goto LAB_1c0003938;
      }
    }
LAB_1c0003ca8:
    iVar7 = -0x3fffffff;
  }
LAB_1c0003cad:
  if (local_res8 != (short *)0x0) {
    ExFreePoolWithTag(local_res8,0);
    local_res8 = (short *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar12,0x67);
  }
  return iVar7;
}



===== ProcessButtonDowns @ 1c0003d1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ProcessButtonDowns(undefined8 *param_1,uint param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  uint *puVar3;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 uVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined *puVar8;
  undefined1 local_res8;
  uint local_res9;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar6 = param_1[1];
  puVar8 = PTR__WDF_CHILD_HID_DEVICE_CONTEXT_TYPE_INFO_1c000c068;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,puVar8,0x80,
                        in_stack_ffffffffffffffd8,(char)*param_1,(char)param_2,
                        (char)*(uint *)(param_1 + 0x25));
  }
  uVar7 = param_2 & ~*(uint *)(param_1 + 0x25);
  if (g_UseMobileButtonsMapping == '\0') {
    uVar1 = ProcessButtonsForDesktop((longlong)param_1,lVar2,(ulonglong)uVar7);
    uVar4 = extraout_var_00;
  }
  else {
    CheckForTestCombos((longlong)param_1,uVar7);
    uVar5 = 0;
    uVar1 = 1;
    local_res8 = 1;
    local_res9 = 0;
    if (uVar7 != 0) {
      puVar3 = &DAT_1c000c151;
      do {
        if (0x1c000c18c < (longlong)puVar3) break;
        if ((uVar7 & 1) != 0) {
          uVar5 = uVar5 | *puVar3;
        }
        puVar3 = (uint *)((longlong)puVar3 + 5);
        uVar7 = uVar7 >> 1;
      } while (uVar7 != 0);
      local_res9 = uVar5;
    }
    EnqueueInputReport((undefined4 *)&local_res8,lVar2);
    uVar4 = extraout_var;
  }
  return CONCAT71(uVar4,uVar1);
}



===== ProcessButtonsForDesktop @ 1c0003e2c =====

undefined1 ProcessButtonsForDesktop(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_res8;
  undefined1 local_resc;
  
  uVar5 = (uint)param_3;
  local_res8 = 0;
  uVar4 = 0;
  local_resc = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x91);
  }
  uVar3 = *(uint *)(param_1 + 0x10c);
  uVar7 = (uVar3 ^ uVar5) & uVar3;
  uVar3 = ~uVar3 & uVar5;
  uVar6 = 0;
LAB_1c0003ea4:
  while (*(char *)(param_1 + 0x108) == '\0') {
    if (*(char *)(param_1 + 0x109) != '\0') {
      *(undefined1 *)(param_1 + 0x109) = 0;
      local_res8._0_1_ = 3;
      goto LAB_1c0003f2f;
    }
    if (uVar7 != 0) goto LAB_1c0003ede;
    if (uVar3 == 0) {
      *(uint *)(param_1 + 0x10c) = uVar5;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x92);
      }
      return uVar4;
    }
    uVar2 = 0xffffffff;
    if ((uVar3 & 1) != 0) {
      uVar2 = uVar6;
    }
    uVar3 = uVar3 >> 1;
    uVar6 = uVar6 + 1;
    if (uVar2 != 0xffffffff) {
      param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
      goto LAB_1c0003f05;
    }
  }
  *(undefined1 *)(param_1 + 0x108) = 0;
  local_res8._0_1_ = 1;
LAB_1c0003f2f:
  local_res8 = (uint)(byte)local_res8;
  local_resc = 0;
  goto LAB_1c0003f33;
LAB_1c0003ede:
  uVar2 = 0xffffffff;
  if ((uVar7 & 1) != 0) {
    uVar2 = uVar6;
  }
  uVar7 = uVar7 >> 1;
  uVar6 = -(uint)(uVar7 != 0) & uVar6 + 1;
  if (uVar2 != 0xffffffff) {
    param_3 = 0;
LAB_1c0003f05:
    uVar1 = ProcessOneButtonEventForDesktop(param_1,uVar2,(char)param_3,(char *)&local_res8);
    if ((char)uVar1 != '\0') {
LAB_1c0003f33:
      EnqueueInputReport(&local_res8,param_2);
      uVar4 = 1;
    }
  }
  goto LAB_1c0003ea4;
}



===== ProcessOneButtonEventForDesktop @ 1c0003fa4 =====

undefined8 ProcessOneButtonEventForDesktop(longlong param_1,uint param_2,char param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  ulonglong uVar5;
  undefined1 uStack0000000000000000;
  
  uVar5 = (ulonglong)param_2;
  if (param_3 == '\0') {
    iVar2 = *(int *)(param_1 + 0xd8 + uVar5 * 4);
    if (iVar2 == 1) {
      *(undefined4 *)(param_1 + 0xd8 + uVar5 * 4) = 0;
    }
    else {
      if (iVar2 == 2) {
        *(undefined4 *)(param_1 + 0xd8 + uVar5 * 4) = 0;
        cVar1 = *(char *)(param_1 + 0x10a);
        register0x00000020 =
             (BADSPACEBASE *)CONCAT71((int7)((ulonglong)&uStack0000000000000000 >> 8),cVar1);
        if (cVar1 == '\0') goto LAB_1c0003fdf;
        param_4[1] = '\0';
        param_4[2] = '\0';
        param_4[3] = '\0';
        param_4[4] = '\0';
        *param_4 = cVar1;
        *(undefined1 *)(param_1 + 0x10a) = 0;
        goto LAB_1c00041c8;
      }
      if (iVar2 != 0) goto LAB_1c0004008;
    }
LAB_1c00040a7:
    uVar3 = 0;
    if (param_2 == 1) {
      if (*(int *)(param_1 + 0xdc) == 0) {
        ExCancelTimer(*(undefined8 *)(param_1 + 0xb0),0);
        ExCancelTimer(*(undefined8 *)(param_1 + 0xb8),0);
      }
      else if (*(int *)(param_1 + 0xdc) == 1) {
        ExSetTimer(*(undefined8 *)(param_1 + 0xb0),0xfffffffffeced300,0,0);
        register0x00000020 =
             (BADSPACEBASE *)ExSetTimer(*(undefined8 *)(param_1 + 0xb8),0xfffffffffd9da600,0,0);
LAB_1c0003fdf:
        return (ulonglong)register0x00000020 & 0xffffffffffffff00;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xd8 + uVar5 * 4) = 1;
    if (param_2 == 0) goto LAB_1c0003fdf;
LAB_1c0004008:
    if (((*(int *)(param_1 + 0xdc) == 0) && (*(int *)(param_1 + 0xd8) == 0)) ||
       (piVar4 = (int *)(param_1 + 0xd8), param_2 < 2)) goto LAB_1c00040a7;
    uVar3 = 0;
    do {
      if (((1 < uVar3) && (uVar3 != param_2)) && (*piVar4 == 1)) {
        uVar3 = 0;
        goto LAB_1c000412b;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < 0xc);
    if (*(int *)(param_1 + 0xd8) == 0) {
      uVar3 = -(uint)(*(int *)(param_1 + 0xdc) != 0) & 2;
    }
    else {
      uVar3 = 1;
    }
  }
LAB_1c000412b:
  register0x00000020 = (BADSPACEBASE *)FillInputReportForDesktop(param_4,uVar3,param_2);
  if (uVar3 == 1) {
    cVar1 = *param_4;
    register0x00000020 = (BADSPACEBASE *)CONCAT71((int7)((ulonglong)register0x00000020 >> 8),cVar1);
    *(undefined4 *)(param_1 + 0xd8) = 2;
    *(undefined4 *)(param_1 + 0xd8 + uVar5 * 4) = 2;
    *(char *)(param_1 + 0x10a) = cVar1;
  }
  else if (uVar3 == 2) {
    cVar1 = *param_4;
    *(undefined4 *)(param_1 + 0xdc) = 2;
    *(undefined4 *)(param_1 + 0xd8 + uVar5 * 4) = 2;
    *(char *)(param_1 + 0x10a) = cVar1;
    ExCancelTimer(*(undefined8 *)(param_1 + 0xb0),0);
    register0x00000020 = (BADSPACEBASE *)ExCancelTimer(*(undefined8 *)(param_1 + 0xb8),0);
  }
  if (*(int *)(param_1 + 0xd8 + uVar5 * 4) == 0) {
    if (param_2 == 0) {
      *(undefined1 *)(param_1 + 0x108) = 1;
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_1 + 0x109) = 1;
    }
    else {
      param_4[1] = '\0';
      param_4[2] = '\0';
      param_4[3] = '\0';
      param_4[4] = '\0';
    }
  }
LAB_1c00041c8:
  return CONCAT71((int7)((ulonglong)register0x00000020 >> 8),1);
}



===== RequestCopyFromBuffer @ 1c00041ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RequestCopyFromBuffer(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined8 local_res20;
  longlong in_stack_ffffffffffffffc8;
  
  local_res20 = 0;
  puVar3 = &local_res20;
  uVar2 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0x77;
    param_3 = in_stack_ffffffffffffffc8;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res20);
    if (param_3 != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      return -0x3fffffdd;
    }
    puVar3 = (undefined8 *)0x0;
    uVar2 = local_res20;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x628))(WdfDriverGlobals,local_res20,0,param_2);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_1,0);
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0x79;
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,puVar3,uVar4,param_3,
                     (char)param_1,(char)iVar1);
  return iVar1;
}



===== RundownInputReportQueue @ 1c0004360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RundownInputReportQueue(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 local_res8;
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res8 = 0;
  while( true ) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),&local_res8);
    if (iVar2 < 0) {
      return;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x48));
    if (*(uint *)(param_1 + 0x84) == *(uint *)(param_1 + 0x88)) break;
    uVar6 = (ulonglong)*(uint *)(param_1 + 0x40);
    uVar3 = *(uint *)(param_1 + 0x84) % 10;
    uVar5 = (ulonglong)uVar3;
    lVar1 = param_1 + (ulonglong)uVar3 * 4;
    iVar2 = RequestCopyFromBuffer(local_res8,lVar1 + 0x50 + uVar5,uVar6);
    pcVar4 = (char *)(ulonglong)*(uint *)(WdfDriverGlobals + 8);
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (iVar2 < 0)) {
      pcVar4 = "onecore\\drivers\\input\\hid\\miniports\\buttonconverter\\src\\btnconv.c";
      uVar6 = 0xc71;
      RtlAssert("NT_SUCCESS(status)",
                "onecore\\drivers\\input\\hid\\miniports\\buttonconverter\\src\\btnconv.c",0xc71,0);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdDd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar4,uVar6,0x76,
                 in_stack_ffffffffffffffc8,(char)*(undefined8 *)(param_1 + 8),
                 *(undefined1 *)(uVar5 * 5 + 0x50 + param_1),
                 (char)*(undefined4 *)(uVar5 + 0x51 + lVar1),(char)*(undefined4 *)(param_1 + 0x84));
    }
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x48));
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,local_res8,iVar2);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x48));
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x8d8))(WdfDriverGlobals,local_res8);
  if (iVar2 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res8,iVar2);
    return;
  }
  return;
}



===== SendHidIoctlSynchronously @ 1c0004558 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SendHidIoctlSynchronously
               (undefined8 param_1,undefined4 param_2,longlong param_3,undefined4 param_4,
               longlong param_5,undefined4 param_6)

{
  ulonglong local_38;
  longlong lStack_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  longlong lStack_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_28 = 0;
  lStack_18 = 0;
  lStack_30 = 0;
  if (param_3 != 0) {
    local_c = 0;
    lStack_18 = param_3;
    local_10 = param_4;
  }
  local_20 = (ulonglong)(param_3 != 0);
  if (param_5 != 0) {
    local_24 = 0;
    local_28 = param_6;
    lStack_30 = param_5;
  }
  local_38 = (ulonglong)(param_5 != 0);
  (**(code **)(WdfFunctions_01015 + 0x5d0))
            (WdfDriverGlobals,param_1,0,param_2,-(ulonglong)(param_3 != 0) & (ulonglong)&local_20,
             -(ulonglong)(param_5 != 0) & (ulonglong)&local_38,0,0);
  return;
}



===== SetButtonEnabled @ 1c000461c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SetButtonEnabled(undefined8 *param_1,uint param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  longlong lVar5;
  byte bVar6;
  char *pcVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined2 uVar11;
  undefined1 auStackY_f8 [32];
  undefined8 in_stack_ffffffffffffff28;
  undefined1 *puVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  char local_a8;
  undefined2 local_a0 [2];
  undefined4 local_9c;
  undefined1 local_98 [2];
  undefined1 local_96;
  ushort local_92;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar14 = 0;
  puVar4 = (undefined4 *)0x48;
  memset(local_98,0,0x48);
  local_a0[0] = 0xcb;
  local_a8 = '\0';
  local_9c = 1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      uVar14 = CONCAT71((int7)((ulonglong)uVar14 >> 8),5);
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x81);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  if ((0xb < param_2) || (param_2 == 1)) {
    iVar2 = -0x3ffffff0;
    goto LAB_1c0004bee;
  }
  bVar6 = (byte)param_2;
  uVar9 = 1 << (bVar6 & 0x1f);
  if ((*(uint *)((longlong)param_1 + 100) & uVar9) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar14,puVar4,0x83,
                         in_stack_ffffffffffffff28,(char)*param_1,bVar6);
    }
LAB_1c0004727:
    iVar2 = 0;
    goto LAB_1c0004bee;
  }
  uVar3 = *(uint *)(param_1 + 0x25);
  if (param_3 == '\0') {
    if ((uVar9 & uVar3) != 0) goto LAB_1c00047a4;
  }
  else if ((uVar9 & uVar3) == 0) {
LAB_1c00047a4:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar7 = "disabled";
      if ((uVar9 & uVar3) == 0) {
        pcVar7 = "enabled";
      }
      WPP_RECORDER_SF_qLsD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x84,in_stack_ffffffffffffff28,
                 (char)*param_1,bVar6,pcVar7,(char)uVar3);
    }
    goto LAB_1c0004727;
  }
  if (*(char *)(param_1 + 0xf) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar7 = "disabled";
      if ((uVar9 & uVar3) == 0) {
        pcVar7 = "enabled";
      }
      WPP_RECORDER_SF_qLsD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0x85,in_stack_ffffffffffffff28,
                 (char)*param_1,bVar6,pcVar7,(char)uVar3);
    }
    iVar2 = -0x3fffff5d;
    goto LAB_1c0004bee;
  }
  puVar4 = (undefined4 *)0x0;
  iVar2 = HidP_GetSpecificButtonCaps
                    (0,(&DAT_1c000c192)[(longlong)(int)param_2 * 2],0,
                     (&g_ButtonUsages)[(longlong)(int)param_2 * 2]);
  if ((iVar2 < 0) || (puVar4 = (undefined4 *)(ulonglong)local_92, local_92 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    WPP_RECORDER_SF_qddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    goto LAB_1c0004bee;
  }
  puVar12 = local_98;
  iVar2 = HidP_GetSpecificButtonCaps(2,1,puVar4,0xcb);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x87,puVar12,
                        (char)*param_1,(char)local_92,(char)iVar2);
    goto LAB_1c0004bee;
  }
  puVar4 = (undefined4 *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_1[0x12],0)
  ;
  puVar10 = (undefined4 *)param_1[3];
  puVar13 = (undefined4 *)CONCAT44((int)((ulonglong)puVar12 >> 0x20),(uint)*(ushort *)(param_1 + 5))
  ;
  iVar2 = HidP_InitializeReportForID(2,local_96);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar11 = 0x88;
    puVar4 = puVar10;
  }
  else {
    puVar10 = (undefined4 *)0x0;
    puVar13 = puVar4;
    iVar2 = SendHidIoctlSynchronously
                      (param_1[0xe],0xb0192,0,0,(longlong)puVar4,(uint)*(ushort *)(param_1 + 5));
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar11 = 0x89;
      puVar4 = puVar10;
    }
    else {
      puVar10 = (undefined4 *)(ulonglong)local_92;
      puVar13 = &local_9c;
      if (param_3 == '\0') {
        iVar2 = HidP_UnsetUsages(2,1,puVar10,local_a0);
      }
      else {
        iVar2 = HidP_SetUsages();
      }
      if (-1 < iVar2) {
        uVar14 = 0;
        iVar2 = SendHidIoctlSynchronously
                          (param_1[0xe],0xb0191,(longlong)puVar4,(uint)*(ushort *)(param_1 + 5),0,0)
        ;
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar2;
          }
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x8b,uVar14,
                             (char)*param_1,(char)iVar2);
          goto LAB_1c0004bee;
        }
        if (param_3 == '\0') {
          uVar3 = *(uint *)(param_1 + 0x25) | uVar9;
        }
        else {
          uVar3 = ~uVar9 & *(uint *)(param_1 + 0x25);
        }
        *(uint *)(param_1 + 0x25) = uVar3;
        uVar8 = param_1[0x1a];
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
        if (param_3 == '\0') {
          uVar3 = *(uint *)((longlong)param_1 + 0x10c);
          uVar1 = *(uint *)(param_1 + 0x26);
          uVar8 = (ulonglong)uVar1;
          if ((uVar9 & uVar3) != 0) {
            *(uint *)(param_1 + 0x26) = uVar3 | uVar1;
            uVar9 = uVar9 ^ uVar3;
            goto LAB_1c0004b0a;
          }
          *(uint *)(param_1 + 0x26) = uVar1 & ~uVar9;
        }
        else if ((*(uint *)(param_1 + 0x26) & uVar9) != 0) {
          uVar9 = uVar9 | *(uint *)((longlong)param_1 + 0x10c);
LAB_1c0004b0a:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,puVar4,0x8c,uVar14,
                               (char)*param_1,(char)uVar9);
          }
          uVar14 = ProcessButtonDowns(param_1,uVar9);
          local_a8 = (char)uVar14;
        }
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_1[0x1a]);
        if (local_a8 != '\0') {
          puVar4 = (undefined4 *)PTR__WDF_CHILD_HID_DEVICE_CONTEXT_TYPE_INFO_1c000c068;
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1[1]);
          RundownInputReportQueue(lVar5);
        }
        goto LAB_1c0004bee;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar11 = 0x8a;
      puVar4 = puVar10;
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,uVar11,puVar13,
                     (char)*param_1,(char)iVar2);
LAB_1c0004bee:
  if ((((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
      (WPP_RECORDER_SF_qLdDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40)),
      (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x8e);
  }
  return iVar2;
}



===== TraceAggregateLoggingAnyButtonPress @ 1c0004c90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TraceAggregateLoggingAnyButtonPress(longlong param_1,undefined4 param_2,ulonglong param_3)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  longlong lVar4;
  ulonglong uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined7 uVar8;
  byte bVar9;
  undefined1 auStack_d8 [32];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined *local_78;
  uint local_70;
  undefined4 local_6c;
  undefined *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  if (5 < DAT_1c000c078) {
    if (((_DAT_1c000c088 & 0x400000000000) == 0) ||
       (bVar3 = true, (DAT_1c000c090 & 0x400000000000) != DAT_1c000c090)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_58 = *(wchar_t **)(param_1 + 0x160);
      if (local_58 == (wchar_t *)0x0) {
        local_58 = L"";
        local_50 = 2;
      }
      else {
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_58[lVar4] != L'\0');
        local_50 = (int)lVar4 * 2 + 2;
      }
      local_48 = &local_a8;
      local_38 = &local_90;
      local_28 = local_88;
      local_78 = PTR_DAT_1c000c080;
      local_9c = 5;
      local_4c = 0;
      local_40 = 4;
      local_90 = 1;
      local_30 = 8;
      local_88[0] = 0x1000000;
      local_20 = 8;
      local_a0 = 0xb000000;
      local_98 = 0x400000000000;
      local_70 = (uint)*(ushort *)PTR_DAT_1c000c080;
      local_68 = &DAT_1c000acbc;
      local_6c = 2;
      local_60 = 0x4c;
      local_5c = 1;
      local_a4 = 0x420;
      if (DAT_1c000c0a0 == TlgAggregateInternalRegisteredProviderEtwCallback) {
        bVar9 = 0;
        pcVar6 = &DAT_1c000acbe;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 < '\0');
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        while (pcVar6 < "\x06\v\x05") {
          do {
            pcVar7 = pcVar6;
            pcVar6 = pcVar7 + 1;
          } while (*pcVar7 != '\0');
          cVar1 = pcVar7[1];
          uVar8 = (undefined7)(param_3 >> 8);
          param_3 = CONCAT71(uVar8,cVar1);
          pcVar6 = pcVar7 + 2;
          if (-1 < cVar1) break;
          cVar2 = *pcVar6;
          param_3 = CONCAT71(uVar8,cVar1) & 0xffffffffffffff7f;
          pcVar6 = pcVar7 + 3;
          if (-1 < cVar2) break;
          for (; cVar1 = *pcVar6, cVar1 < '\0'; pcVar6 = pcVar6 + 1) {
            if (cVar1 != -0x80) goto LAB_1c0004e57;
          }
          if (((char)param_3 != '\t') || (2 < (byte)(cVar1 + 0x8fU))) break;
          uVar5 = (ulonglong)bVar9;
          bVar9 = bVar9 + 1;
          *(char *)((longlong)&local_4c + uVar5 * 0x10 + 1) = cVar1;
        }
LAB_1c0004e57:
        local_a8 = param_2;
        if (bVar9 == 0) {
          EtwWriteTransfer(DAT_1c000c098,&local_a0,0,0);
        }
        else {
          InsertEventEntryInLookUpTable
                    (pcVar6,(undefined8 *)&local_a0,param_3,(longlong)&local_78,bVar9);
        }
      }
    }
  }
  return;
}



===== TraceLoggingDeviceConfig @ 1c0004ec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TraceLoggingDeviceConfig(longlong param_1,undefined4 param_2)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_118 [32];
  undefined1 local_e8;
  undefined1 local_e7;
  byte local_e6 [2];
  uint local_e4;
  undefined4 local_e0 [2];
  undefined8 local_d8 [2];
  undefined8 local_c8 [4];
  wchar_t *local_a8;
  int local_a0;
  undefined4 local_9c;
  wchar_t *local_98;
  int local_90;
  undefined4 local_8c;
  wchar_t *local_88;
  int local_80;
  undefined4 local_7c;
  undefined1 *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  byte *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  if (5 < DAT_1c000c078) {
    if (((_DAT_1c000c088 & 0x400000000000) == 0) ||
       (bVar1 = true, (DAT_1c000c090 & 0x400000000000) != DAT_1c000c090)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_a8 = *(wchar_t **)(param_1 + 0x160);
      lVar2 = -1;
      local_80 = 2;
      if (local_a8 == (wchar_t *)0x0) {
        local_a8 = L"";
        local_a0 = 2;
      }
      else {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (local_a8[lVar3] != L'\0');
        local_a0 = (int)lVar3 * 2 + 2;
      }
      local_98 = *(wchar_t **)(param_1 + 0x168);
      local_9c = 0;
      if (local_98 == (wchar_t *)0x0) {
        local_98 = L"";
        local_90 = 2;
      }
      else {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (local_98[lVar3] != L'\0');
        local_90 = (int)lVar3 * 2 + 2;
      }
      local_88 = *(wchar_t **)(param_1 + 0x170);
      local_8c = 0;
      if (local_88 == (wchar_t *)0x0) {
        local_88 = L"";
      }
      else {
        do {
          lVar2 = lVar2 + 1;
        } while (local_88[lVar2] != L'\0');
        local_80 = (int)lVar2 * 2 + 2;
      }
      local_e8 = *(undefined1 *)(param_1 + 0x178);
      local_78 = &local_e8;
      local_68 = &local_e4;
      local_e7 = g_UseMobileButtonsMapping;
      local_58 = &local_e7;
      local_48 = local_e6;
      local_e4 = *(uint *)(param_1 + 100);
      local_38 = local_e0;
      local_28 = local_d8;
      local_e6[0] = (byte)(local_e4 >> 1) & 1;
      local_7c = 0;
      local_70 = 1;
      local_60 = 4;
      local_50 = 1;
      local_40 = 1;
      local_30 = 4;
      local_d8[0] = 0x800;
      local_20 = 8;
      local_e0[0] = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x1c000c078,&DAT_1c000ab11,0,0,0xb,local_c8);
    }
  }
  return;
}



===== TraceLoggingFirstPowerButtonPress @ 1c00050b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TraceLoggingFirstPowerButtonPress(longlong param_1)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_e8 [32];
  undefined1 local_b8;
  undefined1 local_b7 [3];
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [4];
  wchar_t *local_88;
  int local_80;
  undefined4 local_7c;
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (5 < DAT_1c000c078) {
    if (((_DAT_1c000c088 & 0x400000000000) == 0) ||
       (bVar1 = true, (DAT_1c000c090 & 0x400000000000) != DAT_1c000c090)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_88 = *(wchar_t **)(param_1 + 0x160);
      lVar2 = -1;
      local_60 = 2;
      if (local_88 == (wchar_t *)0x0) {
        local_88 = L"";
        local_80 = 2;
      }
      else {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (local_88[lVar3] != L'\0');
        local_80 = (int)lVar3 * 2 + 2;
      }
      local_78 = *(wchar_t **)(param_1 + 0x168);
      local_7c = 0;
      if (local_78 == (wchar_t *)0x0) {
        local_78 = L"";
        local_70 = 2;
      }
      else {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (local_78[lVar3] != L'\0');
        local_70 = (int)lVar3 * 2 + 2;
      }
      local_68 = *(wchar_t **)(param_1 + 0x170);
      local_6c = 0;
      if (local_68 == (wchar_t *)0x0) {
        local_68 = L"";
      }
      else {
        do {
          lVar2 = lVar2 + 1;
        } while (local_68[lVar2] != L'\0');
        local_60 = (int)lVar2 * 2 + 2;
      }
      local_b8 = *(undefined1 *)(param_1 + 0x178);
      local_58 = &local_b8;
      local_b4 = *(undefined4 *)(param_1 + 100);
      local_48 = &local_b4;
      local_b7[0] = g_UseMobileButtonsMapping;
      local_38 = local_b7;
      local_28 = &local_b0;
      local_5c = 0;
      local_50 = 1;
      local_40 = 4;
      local_30 = 1;
      local_b0 = 0x1000000;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x1c000c078,&DAT_1c000abf3,0,0,9,local_a8);
    }
  }
  return;
}



===== WPP_RECORDER_SF_ @ 1c0005264 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,0);
  return;
}



===== WPP_RECORDER_SF_S @ 1c00052f8 =====

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
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0xe,pwVar2,lVar1,0);
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
  WppAutoLogTrace(param_1,3,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0xe,in_stack_00000030
                  ,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 1c0005420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0xd,pwVar2,lVar1,
               &uStack0000000000000038,4,0);
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
  WppAutoLogTrace(param_1,2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0xd,in_stack_00000030
                  ,lVar3,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c0005574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,4,0)
  ;
  return;
}



===== WPP_RECORDER_SF_q @ 1c0005620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,
                  &param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 1c00056d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qDD @ 1c00057a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qDd @ 1c000589c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qI @ 1c0005994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 1c0005a64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x78,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x78,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qLdD @ 1c0005b58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLdD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x82,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x82,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qLdDd @ 1c0005c6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLdDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x8d,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x8d,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qLsD @ 1c0005da8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLsD
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,char *param_8,
               undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = param_8;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_8 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_8[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_8;
    if (param_8 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,4,pcVar3
               ,lVar2,&param_9,4,0);
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
  WppAutoLogTrace(param_1,param_2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,
                  &param_6,8,&param_7,4,pcVar4,lVar1,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qS @ 1c0005f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,wchar_t *param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  pwVar3 = param_7;
  lVar5 = -1;
  lVar4 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_7[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_7;
    if (param_7 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,pwVar2,lVar1,0);
  }
  if (pwVar3 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (pwVar3[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,
                  pwVar3,lVar4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 1c0006094 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,
                  &param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qdD @ 1c0006174 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qdDd @ 1c000626c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdDd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qdd @ 1c0006380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,
                  &param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qddd @ 1c0006480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x86,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x86,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qdq @ 1c0006598 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x34,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x34,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1c000668c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x6a,&uStack0000000000000030,8,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x6a,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_qqLLd @ 1c000675c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000023;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x7b,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x7b,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLLdDD @ 1c00068a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLLdDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x56,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,0x56,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLd @ 1c0006a18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 1c0006b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_ee320c48c3be399917f979ca85c7e499_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WStringListToWString @ 1c0006c30 =====

void WStringListToWString(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  if (param_2 != 1) {
    do {
      if (*(short *)(param_1 + uVar1 * 2) == 0) {
        *(undefined2 *)(param_1 + uVar1 * 2) = 0x20;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2 - 1U);
  }
  return;
}



===== WppClassicProviderCallback @ 1c0006c60 =====

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



===== _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv @ 1c0006cbc =====

void _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv(void)

{
  return;
}



===== FxStubDriverUnloadCommon @ 1c0006cc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c000c2d8 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c000c2d8 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c0006d21:
      if (ppvVar1 == (void **)0x0) goto LAB_1c0006d77;
      if (ppvVar2 <= ppvVar1) goto LAB_1c0006d8f;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c0006d21;
LAB_1c0006d77:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0006d8f:
  WdfVersionUnbind(&DAT_1c000c570,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0006dd0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 *param_2,undefined8 param_3)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3);
  return;
}



===== FxDriverEntryWorker @ 1c0006e04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 *param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined8 *puVar4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2,param_3);
  }
  else {
    _DAT_1c000c570 = 0x2080000;
    _DAT_1c000c578 = &DAT_1c000c350;
    RtlCopyUnicodeString(&DAT_1c000c570);
    puVar4 = &WdfBindInfo;
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c000c570,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2,puVar4);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c000c558 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c000c570);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c000c2d8 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0006f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c000c558 != (code *)0x0) && (DAT_1c000c558 != FxStubDriverUnload)) {
    (*DAT_1c000c558)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0006fc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0006fe9) */
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
    if ((void **)0x1c000c2cf < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c000c2d8 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c000714c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0007169) */
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
    if ((void **)0x1c000c2ef < ppvVar2) break;
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



===== CreateNewEventEntry @ 1c0007214 =====

undefined8
CreateNewEventEntry(char param_1,undefined8 *param_2,undefined8 param_3,longlong param_4,
                   byte param_5,undefined4 param_6,undefined8 *param_7)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulonglong _Size;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  ulonglong uVar10;
  byte bVar11;
  uint *puVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  
  lVar6 = 0;
  *param_7 = 0;
  puVar12 = (uint *)(param_4 + 8);
  bVar11 = 0;
  lVar9 = 0;
  do {
    uVar1 = *puVar12;
    puVar12 = puVar12 + 4;
    if (1 < bVar11) {
      lVar6 = (ulonglong)uVar1 + lVar6;
    }
    lVar3 = (ulonglong)uVar1 + lVar9;
    if (1 < bVar11) {
      lVar3 = lVar9;
    }
    bVar11 = bVar11 + 1;
    lVar9 = lVar3;
  } while (bVar11 < 6);
  if ((ulonglong)(lVar3 + lVar6) < 0x10000) {
    _Size = lVar6 + 0x8e;
    if ((_Size == 0) ||
       (puVar5 = (undefined8 *)
                 ExAllocatePoolWithTag
                           ((-(uint)(param_1 != '\0') & 0xfffffe01) + 0x200,_Size,0x47417254),
       puVar5 == (undefined8 *)0x0)) {
      uVar4 = 0xc0000017;
    }
    else {
      memset(puVar5,0,_Size);
      if (_Size < 0x60) {
        puVar14 = (undefined8 *)0x0;
        puVar7 = puVar5;
      }
      else {
        _Size = lVar6 + 0x2e;
        puVar7 = puVar5 + 0xc;
        puVar14 = puVar5;
      }
      uVar13 = 0;
      if (param_5 != 0xfffffffe) {
        do {
          if ((byte)uVar13 < 2) {
            puVar5 = (undefined8 *)(param_4 + uVar13 * 0x10);
            uVar4 = puVar5[1];
            puVar14[uVar13 * 2] = *puVar5;
            (puVar14 + uVar13 * 2)[1] = uVar4;
          }
          else {
            uVar10 = (ulonglong)*(uint *)(param_4 + 8 + uVar13 * 0x10);
            if ((uVar10 == 0) || (_Size < uVar10)) {
              puVar5 = (undefined8 *)0x0;
            }
            else {
              _Size = _Size - uVar10;
              puVar5 = puVar7;
              puVar7 = (undefined8 *)((longlong)puVar7 + uVar10);
            }
            memcpy(puVar5,*(void **)(param_4 + uVar13 * 0x10),uVar10);
            puVar14[uVar13 * 2] = puVar5;
            *(undefined4 *)((longlong)puVar14 + uVar13 * 0x10 + 0xc) =
                 *(undefined4 *)(param_4 + 0xc + uVar13 * 0x10);
            *(undefined4 *)(puVar14 + uVar13 * 2 + 1) = *(undefined4 *)(param_4 + 8 + uVar13 * 0x10)
            ;
          }
          bVar11 = (byte)uVar13 + 1;
          uVar13 = (ulonglong)bVar11;
        } while ((uint)bVar11 < param_5 + 2);
      }
      if (_Size < 0x2e) {
        puVar8 = (undefined8 *)0x0;
        puVar5 = puVar7;
      }
      else {
        _Size = _Size - 0x2e;
        puVar5 = (undefined8 *)((longlong)puVar7 + 0x2e);
        puVar8 = puVar7;
      }
      puVar8[2] = puVar14;
      uVar4 = *param_2;
      uVar2 = param_2[1];
      *(byte *)((longlong)puVar8 + 0x2d) = param_5;
      bVar11 = param_5 + 2;
      *(undefined1 *)((longlong)puVar8 + 0x2c) = 6;
      *(undefined4 *)(puVar8 + 5) = param_6;
      *puVar8 = uVar4;
      puVar8[1] = uVar2;
      if (bVar11 < 6) {
        lVar6 = -param_4;
        uVar13 = (ulonglong)(byte)(6 - bVar11);
        puVar12 = (uint *)((ulonglong)bVar11 * 0x10 + 8 + param_4);
        do {
          uVar10 = (ulonglong)*puVar12;
          if ((uVar10 == 0) || (_Size < uVar10)) {
            puVar7 = (undefined8 *)0x0;
          }
          else {
            _Size = _Size - uVar10;
            puVar7 = puVar5;
            puVar5 = (undefined8 *)((longlong)puVar5 + uVar10);
          }
          memcpy(puVar7,*(void **)(puVar12 + -2),uVar10);
          *(undefined8 **)((longlong)puVar12 + puVar8[2] + lVar6 + -8) = puVar7;
          *(uint *)((longlong)puVar12 + puVar8[2] + lVar6 + 4) = puVar12[1];
          *(uint *)((longlong)puVar12 + puVar8[2] + lVar6) = *puVar12;
          uVar13 = uVar13 - 1;
          puVar12 = puVar12 + 4;
        } while (uVar13 != 0);
      }
      *param_7 = puVar8;
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xc0000095;
  }
  return uVar4;
}



===== DestroyEventEntry @ 1c0007468 =====

void DestroyEventEntry(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0);
  }
  return;
}



===== EnableFlushTimer @ 1c0007490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EnableFlushTimer(longlong param_1,ulonglong param_2)

{
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  if (param_1 != 0) {
    local_18 = __security_cookie ^ (ulonglong)auStack_48;
    local_28 = 0;
    local_20 = 0xffffffffffffffff;
    ExSetTimer(param_1,(param_2 & 0xffffffff) * -10000,0,&local_28);
  }
  return;
}



===== FinishHash @ 1c00074ec =====

void FinishHash(int *param_1)

{
  *param_1 = ((uint)(*param_1 * 9) >> 0xb ^ *param_1 * 9) * 0x8001;
  return;
}



===== FlushLookUpTableBucket @ 1c0007508 =====

int FlushLookUpTableBucket(longlong param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  longlong local_res8;
  
  uVar8 = (ulonglong)param_2;
  if (*(longlong *)(param_1 + uVar8 * 8) == 0) {
    iVar7 = 0;
  }
  else {
    uVar3 = 0;
    ExAcquirePushLockExclusiveEx(param_1 + 0x110,0);
    if (*(char *)(param_1 + 0x175) == '\0') {
      uVar3 = ExAcquireSpinLockExclusive(param_1 + 0x118);
    }
    lVar1 = *(longlong *)(param_1 + uVar8 * 8);
    plVar5 = &local_res8;
    *(undefined8 *)(param_1 + uVar8 * 8) = 0;
    iVar7 = 0;
    local_res8 = lVar1;
    if (lVar1 != 0) {
      lVar6 = lVar1;
      do {
        lVar2 = *(longlong *)(lVar6 + 0x20);
        *(undefined8 *)(lVar6 + 0x20) = 0;
        plVar5 = (longlong *)(*plVar5 + 0x18);
        lVar6 = *plVar5;
        plVar4 = plVar5;
        while (lVar6 != 0) {
          plVar4 = (longlong *)(lVar6 + 0x20);
          lVar6 = *plVar4;
        }
        *plVar4 = lVar2;
        iVar7 = iVar7 + 1;
        lVar6 = *plVar5;
      } while (lVar6 != 0);
    }
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) - iVar7;
    if (*(char *)(param_1 + 0x175) == '\0') {
      ExReleaseSpinLockExclusive(param_1 + 0x118,uVar3);
    }
    ExReleasePushLockExclusiveEx(param_1 + 0x110,0);
    FlushEventEntryList(*(undefined8 *)(*(longlong *)(param_1 + 0x158) + 0x20),lVar1);
  }
  return iVar7;
}



===== InsertEventEntryInLookUpTable @ 1c000761c =====

ulonglong InsertEventEntryInLookUpTable
                    (undefined8 param_1,undefined8 *param_2,undefined8 param_3,longlong param_4,
                    byte param_5)

{
  int *piVar1;
  byte *pbVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  longlong lVar6;
  bool bVar7;
  longlong lVar8;
  byte bVar9;
  undefined1 uVar10;
  int iVar11;
  uint uVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong lVar15;
  uint uVar16;
  ulonglong uVar17;
  byte bVar18;
  ulonglong uVar19;
  ulonglong local_res8;
  longlong local_58;
  void *local_50;
  
  lVar8 = DAT_1c000c0a8;
  bVar7 = false;
  local_58 = 0;
  lVar15 = 0;
  local_50 = (void *)(param_4 + 0x10);
  local_res8 = 0;
  uVar12 = 0;
  uVar17 = 0;
  do {
    pbVar2 = (byte *)((longlong)local_50 + uVar17);
    uVar17 = uVar17 + 1;
    uVar12 = (*pbVar2 + uVar12) * 0x401;
    uVar12 = uVar12 ^ uVar12 >> 6;
  } while (uVar17 < 8);
  uVar16 = param_5 + 2;
  uVar17 = (ulonglong)uVar16;
  if ((byte)uVar16 < 6) {
    plVar14 = (longlong *)((ulonglong)(uVar16 & 0xff) * 0x10 + param_4);
    uVar19 = (ulonglong)(byte)(6 - (byte)uVar16);
    do {
      uVar17 = 0;
      if ((ulonglong)*(uint *)(plVar14 + 1) != 0) {
        do {
          pbVar2 = (byte *)(uVar17 + *plVar14);
          uVar17 = uVar17 + 1;
          uVar12 = (*pbVar2 + uVar12) * 0x401;
          uVar12 = uVar12 ^ uVar12 >> 6;
        } while (uVar17 < *(uint *)(plVar14 + 1));
      }
      plVar14 = plVar14 + 2;
      uVar19 = uVar19 - 1;
    } while (uVar19 != 0);
  }
  uVar12 = (uVar12 * 9 >> 0xb ^ uVar12 * 9) * 0x8001;
  bVar9 = KeGetCurrentIrql();
  if (bVar9 < 2) {
    iVar11 = KeIsExecutingDpc();
    if (iVar11 == 0) {
      ExAcquirePushLockSharedEx(lVar8 + 0x110,0);
      goto LAB_1c00077e7;
    }
    if (*(char *)(lVar8 + 0x175) != '\0') {
      uVar10 = KeGetCurrentIrql();
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xd1,lVar8 + 0x118,uVar10,1,0);
    }
    ExAcquireSpinLockShared(lVar8 + 0x118);
  }
  else {
    if (*(char *)(lVar8 + 0x175) != '\0') {
      uVar10 = KeGetCurrentIrql();
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xd1,lVar8 + 0x118,uVar10,1,0);
    }
    ExAcquireSpinLockSharedAtDpcLevel(lVar8 + 0x118);
  }
  bVar7 = true;
LAB_1c00077e7:
  plVar14 = (longlong *)(lVar8 + (ulonglong)(uVar12 & 0x1f) * 8);
  do {
    if (*plVar14 == 0) {
      if (0x3ff < *(uint *)(lVar8 + 0x100)) {
        *(int *)(lVar8 + 0x13c) = *(int *)(lVar8 + 0x13c) + 1;
        local_res8 = 0xc0000023;
        goto LAB_1c0007a1a;
      }
      if (lVar15 == 0) {
        uVar19 = CreateNewEventEntry(*(char *)(lVar8 + 0x175),param_2,uVar17,param_4,param_5,uVar12,
                                     &local_58);
        local_res8 = uVar19 & 0xffffffff;
        lVar15 = local_58;
        if (local_58 == 0) {
          local_res8 = uVar19 & 0xffffffff;
          if ((int)uVar19 == -0x3fffffe9) {
            *(int *)(lVar8 + 0x140) = *(int *)(lVar8 + 0x140) + 1;
          }
          else {
            *(int *)(lVar8 + 0x144) = *(int *)(lVar8 + 0x144) + 1;
          }
          goto LAB_1c0007a1a;
        }
      }
      LOCK();
      lVar13 = *plVar14;
      if (lVar13 == 0) {
        *plVar14 = lVar15;
      }
      UNLOCK();
      if (lVar13 == 0) {
        local_58 = 0;
        LOCK();
        piVar1 = (int *)(lVar8 + 0x100);
        iVar11 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        if (iVar11 == 0) {
          EnableFlushTimer(*(longlong *)(lVar8 + 0x168),(ulonglong)*(uint *)(lVar8 + 0x170));
        }
        lVar15 = local_58;
        if (*(uint *)(lVar8 + 0x130) < *(uint *)(lVar8 + 0x100)) {
          *(uint *)(lVar8 + 0x130) = *(uint *)(lVar8 + 0x100);
        }
        goto LAB_1c0007a1a;
      }
      lVar15 = local_58;
    }
    lVar13 = *plVar14;
    if (uVar12 == *(uint *)(lVar13 + 0x28)) {
      lVar6 = *(longlong *)(lVar13 + 0x10);
      uVar17 = 8;
      iVar11 = memcmp(local_50,(void *)(lVar6 + 0x10),8);
      if (iVar11 == 0) {
        uVar16 = *(byte *)(lVar13 + 0x2d) + 2;
        while( true ) {
          if (5 < uVar16) {
            lVar13 = *plVar14;
            goto LAB_1c00078e4;
          }
          lVar13 = (ulonglong)uVar16 * 0x10;
          uVar5 = *(uint *)(lVar13 + 8 + param_4);
          iVar11 = uVar5 - *(int *)(lVar13 + 8 + lVar6);
          if (iVar11 != 0) break;
          uVar17 = (ulonglong)uVar5;
          iVar11 = memcmp(*(void **)(lVar13 + param_4),*(void **)(lVar13 + lVar6),uVar17);
          if (iVar11 != 0) break;
          uVar16 = uVar16 + 1;
        }
        lVar13 = *plVar14;
      }
    }
    else {
      iVar11 = uVar12 - *(uint *)(lVar13 + 0x28);
      if (iVar11 == 0) {
LAB_1c00078e4:
        if (lVar13 != 0) {
          uVar17 = 2;
          if (2 < param_5 + 2) {
            do {
              lVar15 = **(longlong **)(param_4 + uVar17 * 0x10);
              cVar4 = *(char *)(*(longlong *)(lVar13 + 0x10) + 0xd + uVar17 * 0x10);
              plVar14 = *(longlong **)(*(longlong *)(lVar13 + 0x10) + uVar17 * 0x10);
              if (cVar4 == 'q') {
                LOCK();
                *plVar14 = *plVar14 + lVar15;
                UNLOCK();
              }
              else if ((cVar4 == 'r') || (cVar4 == 's')) {
                do {
                  lVar6 = *plVar14;
                  if (cVar4 == 'r') {
                    if (lVar6 <= lVar15) break;
                  }
                  else if (lVar15 <= lVar6) break;
                  LOCK();
                  lVar3 = *plVar14;
                  if (lVar6 == lVar3) {
                    *plVar14 = lVar15;
                  }
                  UNLOCK();
                } while (lVar6 != lVar3);
              }
              bVar18 = (char)uVar17 + 1;
              uVar17 = (ulonglong)bVar18;
            } while ((uint)bVar18 < param_5 + 2);
            lVar15 = local_58;
          }
        }
LAB_1c0007a1a:
        if (bVar7) {
          if (bVar9 < 2) {
            ExReleaseSpinLockShared();
          }
          else {
            ExReleaseSpinLockSharedFromDpcLevel(lVar8 + 0x118);
          }
        }
        else {
          ExReleasePushLockSharedEx(lVar8 + 0x110,0);
        }
        if (lVar15 != 0) {
          ExFreePoolWithTag(*(undefined8 *)(lVar15 + 0x10),0);
        }
        return local_res8;
      }
    }
    plVar14 = (longlong *)(lVar13 + 0x20 + ((longlong)iVar11 >> 0x3f & 0xfffffffffffffff8U));
  } while( true );
}



===== RunningHash @ 1c0007a94 =====

void RunningHash(uint *param_1,longlong param_2,ulonglong param_3)

{
  byte *pbVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      pbVar1 = (byte *)(uVar3 + param_2);
      uVar3 = uVar3 + 1;
      uVar2 = ((uint)*pbVar1 + *param_1) * 0x401;
      *param_1 = uVar2 >> 6 ^ uVar2;
    } while (uVar3 < param_3);
  }
  return;
}



===== TlgAggregateInternalFlushTimerCallbackKernelMode @ 1c0007ad0 =====

/* void __cdecl TlgAggregateInternalFlushTimerCallbackKernelMode(struct _EX_TIMER * __ptr64,void *
   __ptr64) */

void __cdecl TlgAggregateInternalFlushTimerCallbackKernelMode(_EX_TIMER *param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  
  sVar2 = 0;
  LOCK();
  sVar1 = *(short *)((longlong)param_2 + 0x38);
  if (sVar1 == 0) {
    *(short *)((longlong)param_2 + 0x38) = 1;
  }
  else {
    sVar2 = sVar1;
  }
  UNLOCK();
  if (sVar2 == 0) {
    ExQueueWorkItem(param_2);
  }
  else if (sVar2 == 1) {
    EnableFlushTimer((longlong)param_1,15000);
  }
  return;
}



===== _guard_check_icall @ 1c0007b20 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0007b38 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0007b5c =====

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



===== __cpu_features_init @ 1c0007bd0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0007c3a) */
/* WARNING: Removing unreachable block (ram,0x0001c0007be9) */
/* WARNING: Removing unreachable block (ram,0x0001c0007bda) */

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



===== __security_check_cookie @ 1c0007ca0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0007ce0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0007d10 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0007d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0007d40 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c0007da0 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    for (; ((ulonglong)_Buf1 & 7) != 0; _Buf1 = (void *)((longlong)_Buf1 + 1)) {
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c0007de3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0007e54;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0007e50:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0007e54;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c0007e4c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0007e50;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0007e4c;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_1c0007e54:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_1c0007de3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c0007ec0 =====

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



===== memset @ 1c00081c0 =====

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



===== __memset_repmovs @ 1c0008300 =====

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



===== __memset_query @ 1c0008380 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0008400 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0008540 =====

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



===== __memset_spec_plain @ 1c00085c0 =====

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



===== CreateChildHidDevice @ 1c000f008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CreateChildHidDevice(longlong *param_1)

{
  char cVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined2 uVar6;
  undefined1 auStackY_1a8 [32];
  longlong *in_stack_fffffffffffffe78;
  longlong *plVar7;
  longlong *plVar8;
  longlong *local_168;
  longlong local_160 [5];
  longlong *local_138;
  undefined8 uStack_130;
  undefined *local_128;
  longlong local_120;
  wchar_t *local_118;
  longlong local_110;
  undefined4 *local_108;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined1 local_ec;
  undefined1 local_eb;
  code *local_c8;
  undefined4 local_98;
  undefined2 local_94;
  wchar_t local_88 [40];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_128 = (undefined *)((ulonglong)local_128 & 0xffffffff00000000);
  local_168 = (longlong *)0x0;
  plVar5 = (longlong *)0x60;
  iVar2 = -0x3fffffff;
  local_160[1] = 0;
  local_160[2] = 0;
  local_160[3] = 0;
  local_160[4] = 0;
  local_138 = (longlong *)0x0;
  uStack_130 = 0;
  memset(&local_f8,0,0x60);
  local_88[0x20] = 0;
  local_118 = local_88;
  local_98 = 0x30;
  local_94 = 0;
  local_108 = &local_98;
  builtin_wcsncpy(local_88,L"ButtonConverter\\ConvertedDevice",0x20);
  local_120 = 0x420040;
  local_110 = 0x60004;
  local_160[0] = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals,param_1);
  if (local_160[0] == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000f4e8;
    uVar6 = 0x1f;
    plVar8 = in_stack_fffffffffffffe78;
  }
  else {
    plVar5 = &local_120;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_160[0]);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000f4e8;
      uVar6 = 0x20;
      plVar8 = in_stack_fffffffffffffe78;
    }
    else {
      plVar5 = &local_120;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_160[0]);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000f4e8;
        uVar6 = 0x21;
        plVar8 = in_stack_fffffffffffffe78;
      }
      else {
        plVar5 = &local_110;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_160[0]);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000f4e8;
          uVar6 = 0x22;
          plVar8 = in_stack_fffffffffffffe78;
        }
        else {
          plVar5 = local_160 + 1;
          local_128 = PTR__WDF_CHILD_HID_DEVICE_CONTEXT_TYPE_INFO_1c000c068;
          local_160[3] = 0;
          local_160[2] = 0;
          local_160[1] = 0x38;
          local_138 = (longlong *)0x0;
          uStack_130 = 0;
          local_160[4] = 0x100000001;
          iVar2 = (**(code **)(WdfFunctions_01015 + 600))
                            (WdfDriverGlobals,local_160,plVar5,&local_168);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c000f4e8;
            uVar6 = 0x23;
            plVar8 = in_stack_fffffffffffffe78;
          }
          else {
            plVar3 = (longlong *)
                     (**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_168,
                                PTR__WDF_CHILD_HID_DEVICE_CONTEXT_TYPE_INFO_1c000c068);
            *plVar3 = (longlong)local_168;
            plVar3[1] = (longlong)param_1;
            lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018)
            ;
            plVar7 = plVar3 + 2;
            plVar8 = plVar3 + 3;
            plVar5 = plVar3 + 9;
            *(longlong **)(lVar4 + 8) = local_168;
            cVar1 = g_UseMobileButtonsMapping;
            *plVar7 = 0;
            *plVar8 = 0;
            *(undefined4 *)(plVar3 + 4) = 0x20;
            *(undefined4 *)((longlong)plVar3 + 0x24) = 0x45e;
            *(undefined2 *)(plVar3 + 5) = 0;
            *(undefined8 *)((longlong)plVar3 + 0x84) = 0;
            *(uint *)(plVar3 + 8) = (cVar1 != '\0') + 2;
            plVar3[10] = 0;
            plVar3[0xb] = 0;
            plVar3[0xc] = 0;
            plVar3[0xd] = 0;
            plVar3[0xe] = 0;
            plVar3[0xf] = 0;
            *(undefined2 *)(plVar3 + 0x10) = 0;
            local_128 = (undefined *)0x0;
            local_160[3] = 0;
            uStack_130 = 0;
            local_138 = local_168;
            local_160[2] = 0;
            local_160[1] = 0x38;
            local_160[4] = 0x100000001;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,local_160 + 1);
            if (iVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c000f4e8;
              uVar6 = 0x24;
              plVar8 = in_stack_fffffffffffffe78;
            }
            else {
              plVar5 = (longlong *)&local_f8;
              local_c8 = EvtChildHidDeviceIoInternalDeviceControl;
              local_f8 = 0x60;
              local_f0 = 2;
              local_eb = 1;
              local_f4 = 1;
              iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_168,plVar5,0)
              ;
              if (iVar2 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_1c000f4e8;
                uVar6 = 0x25;
                plVar8 = plVar7;
              }
              else {
                memset(&local_ec,0,0x54);
                plVar5 = (longlong *)&local_f8;
                local_f8 = 0x60;
                local_f0 = 2;
                local_f4 = 3;
                iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                  (WdfDriverGlobals,local_168,plVar5,0);
                if (iVar2 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_1c000f4e8;
                  uVar6 = 0x26;
                }
                else {
                  plVar5 = local_168;
                  iVar2 = (**(code **)(WdfFunctions_01015 + 0x428))(WdfDriverGlobals,param_1);
                  if (-1 < iVar2) {
                    return iVar2;
                  }
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_1c000f4e8;
                  uVar6 = 0x27;
                  param_1 = local_168;
                }
              }
            }
          }
        }
      }
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,plVar5,uVar6,plVar8,(char)param_1,
                     (char)iVar2);
LAB_1c000f4e8:
  if (local_160[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
    local_160[0] = 0;
  }
  if (local_168 != (longlong *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar2;
}



===== CreateChildRawDevice @ 1c000f568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CreateChildRawDevice(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined1 auStackY_178 [32];
  undefined8 *in_stack_fffffffffffffea8;
  longlong local_138;
  undefined8 *local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined *local_f8;
  undefined8 local_f0;
  wchar_t *local_e8;
  undefined8 local_e0;
  undefined4 *local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 local_ab;
  code *local_90;
  undefined4 local_58;
  undefined2 local_54;
  wchar_t local_50 [28];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_178;
  local_130 = (undefined8 *)0x0;
  local_f8 = (undefined *)((ulonglong)local_f8 & 0xffffffff00000000);
  iVar1 = -0x3fffffff;
  puVar3 = (undefined8 *)0x60;
  local_128 = 0;
  uStack_120 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  memset(&local_b8,0,0x60);
  builtin_wcsncpy(local_50,L"ButtonConverter\\RawDevice",0x1a);
  local_50[0x1a] = 0;
  local_e8 = local_50;
  local_58 = 0x30;
  local_54 = 0;
  local_d8 = &local_58;
  local_d0 = 0;
  uStack_c8 = 0;
  local_f0 = 0x360034;
  local_e0 = 0x60004;
  local_138 = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals,param_1);
  if (local_138 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000fa28;
    uVar4 = 0x28;
    iVar1 = -0x3fffffff;
  }
  else {
    RtlInitUnicodeString(&local_d0,&u_D_P_A__GA___SY_);
    puVar3 = &local_d0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x220))(WdfDriverGlobals,local_138);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000fa28;
      uVar4 = 0x29;
    }
    else {
      puVar3 = (undefined8 *)&GUID_DEVCLASS_KEYBOARD;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x6d0))(WdfDriverGlobals,local_138);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000fa28;
        uVar4 = 0x2a;
      }
      else {
        puVar3 = &local_f0;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_138);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000fa28;
          uVar4 = 0x2b;
        }
        else {
          puVar3 = &local_f0;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_138);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c000fa28;
            uVar4 = 0x2c;
          }
          else {
            puVar3 = &local_e0;
            iVar1 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_138);
            if (iVar1 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c000fa28;
              uVar4 = 0x2d;
            }
            else {
              puVar3 = &local_128;
              local_f8 = PTR__WDF_CHILD_RAW_DEVICE_CONTEXT_TYPE_INFO_1c000c040;
              local_118 = 0;
              uStack_120 = 0;
              local_128 = 0x38;
              local_108 = 0;
              uStack_100 = 0;
              uStack_110 = 0x100000001;
              iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                                (WdfDriverGlobals,&local_138,puVar3,&local_130);
              if (iVar1 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_1c000fa28;
                uVar4 = 0x2e;
              }
              else {
                puVar3 = (undefined8 *)
                         (**(code **)(WdfFunctions_01015 + 0x650))
                                   (WdfDriverGlobals,local_130,
                                    PTR__WDF_CHILD_RAW_DEVICE_CONTEXT_TYPE_INFO_1c000c040);
                *puVar3 = local_130;
                in_stack_fffffffffffffea8 = puVar3 + 2;
                *in_stack_fffffffffffffea8 = 0;
                puVar3[1] = param_1;
                lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                                  (WdfDriverGlobals,param_1,
                                   PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018);
                puVar3 = (undefined8 *)&local_b8;
                *(undefined8 **)(lVar2 + 0x10) = local_130;
                local_90 = EvtChildRawDeviceIoDeviceControl;
                local_118 = 0;
                local_f8 = (undefined *)0x0;
                uStack_120 = 0;
                local_b8 = 0x60;
                local_b0 = 2;
                local_ab = 1;
                local_b4 = 1;
                local_108 = 0;
                uStack_100 = 0;
                local_128 = 0x38;
                uStack_110 = 0x100000002;
                iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                  (WdfDriverGlobals,local_130,puVar3,&local_128);
                if (iVar1 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_1c000fa28;
                  uVar4 = 0x2f;
                }
                else {
                  puVar3 = (undefined8 *)&GUID_GPIOBUTTONS_NOTIFY_INTERFACE;
                  iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                                    (WdfDriverGlobals,local_130,&GUID_GPIOBUTTONS_NOTIFY_INTERFACE,0
                                    );
                  if (iVar1 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_1c000fa28;
                    uVar4 = 0x30;
                  }
                  else {
                    puVar3 = local_130;
                    iVar1 = (**(code **)(WdfFunctions_01015 + 0x428))(WdfDriverGlobals,param_1);
                    if (-1 < iVar1) {
                      return iVar1;
                    }
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_1c000fa28;
                    uVar4 = 0x31;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,uVar4,
                     in_stack_fffffffffffffea8,(char)param_1,(char)iVar1);
LAB_1c000fa28:
  if (local_138 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
    local_138 = 0;
  }
  if (local_130 != (undefined8 *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== DriverUnload @ 1c000faa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 in_stack_ffffffffffffffe8;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x12,
                      in_stack_ffffffffffffffe8,(char)uVar1);
  }
  TlgUnregisterAggregateProvider();
  WppCleanupKm(uVar1);
  return;
}



===== EvtDeviceAdd @ 1c000fb10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EvtDeviceAdd(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong *puVar5;
  undefined2 uVar6;
  undefined1 auStackY_198 [32];
  undefined8 in_stack_fffffffffffffe88;
  longlong *local_158;
  undefined4 local_150;
  undefined4 local_14c;
  undefined8 local_148;
  undefined8 local_140;
  ulonglong local_138;
  code *pcStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  longlong *local_118;
  undefined8 uStack_110;
  undefined *local_108;
  ulonglong local_100;
  wchar_t *local_f8;
  undefined4 local_e8;
  undefined4 local_e4;
  code *local_c0;
  code *local_b8;
  wchar_t local_58 [24];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_198;
  local_e4 = 0;
  local_118 = (longlong *)0x0;
  uStack_110 = 0;
  builtin_wcsncpy(local_58 + 0x10,L"InCS",5);
  local_f8 = local_58;
  local_138 = (ulonglong)(uint)local_138;
  local_128 = 0;
  builtin_wcsncpy(local_58,L"ButtonsToDisable",0x10);
  local_158 = (longlong *)0x0;
  local_150 = 0;
  local_140 = 0;
  local_14c = 0;
  local_100 = 0x2a0028;
  local_148 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x13);
  }
  (**(code **)(WdfFunctions_01015 + 0x408))(WdfDriverGlobals,local_148);
  (**(code **)(WdfFunctions_01015 + 0x1c8))(WdfDriverGlobals,local_148,0);
  memset(&local_e8,0,0x90);
  local_c0 = EvtDevicePrepareHardware;
  local_b8 = EvtDeviceReleaseHardware;
  local_e8 = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_148,&local_e8);
  puVar5 = &local_138;
  local_108 = PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018;
  puVar2 = &local_148;
  local_138 = 0x38;
  pcStack_130 = EvtDeviceCleanupCallback;
  local_128 = 0;
  local_118 = (longlong *)0x0;
  uStack_110 = 0;
  uStack_120 = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,puVar2,puVar5,&local_158);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,puVar5,0x14,
                      in_stack_fffffffffffffe88,(char)iVar1);
    goto LAB_1c00100be;
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,local_158,PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018);
  *puVar2 = local_158;
  *(undefined4 *)((longlong)puVar2 + 300) = 0xc7c;
  *(undefined4 *)(puVar2 + 0x22) = 0;
  puVar5 = puVar2 + 0x1a;
  puVar2[0x1b] = 0;
  puVar2[0x1c] = 0;
  puVar2[0x1d] = 0;
  puVar2[0x1e] = 0;
  puVar2[0x1f] = 0;
  puVar2[0x20] = 0;
  local_108 = (undefined *)0x0;
  local_128 = 0;
  uStack_110 = 0;
  local_118 = local_158;
  pcStack_130 = (code *)0x0;
  local_138 = 0x38;
  uStack_120 = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_138);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar6 = 0x15;
  }
  else {
    puVar5 = puVar2 + 0x13;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_138);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar6 = 0x16;
    }
    else {
      puVar5 = puVar2 + 0x24;
      local_108 = (undefined *)0x0;
      local_128 = 0;
      uStack_110 = 0;
      local_118 = local_158;
      pcStack_130 = (code *)0x0;
      local_138 = 0x38;
      uStack_120 = 0x100000001;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_138);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar6 = 0x17;
      }
      else if (g_UseMobileButtonsMapping == '\0') {
        local_150 = 0xc;
        puVar5 = (ulonglong *)&local_150;
        lVar3 = Ordinal_4(EvtPowerButtonHoldTimerFunc,puVar2,puVar5,2);
        puVar2[0x16] = lVar3;
        if (lVar3 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar6 = 0x18;
        }
        else {
          puVar5 = (ulonglong *)&local_150;
          lVar3 = Ordinal_4(EvtPowerButtonLongHoldTimerFunc,puVar2,puVar5,2);
          puVar2[0x17] = lVar3;
          if (lVar3 != 0) goto LAB_1c000fec2;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar6 = 0x19;
        }
      }
      else {
        puVar2[0x16] = 0;
        puVar2[0x17] = 0;
LAB_1c000fec2:
        if (g_UseMobileButtonsMapping != '\0') {
          puVar5 = (ulonglong *)0x1;
          in_stack_fffffffffffffe88 = 0;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x180))(WdfDriverGlobals,local_158,1,0x20019);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x1a,
                                 in_stack_fffffffffffffe88,(char)local_158,(char)iVar1);
            }
          }
          else {
            puVar5 = &local_100;
            uVar4 = local_140;
            iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                              (WdfDriverGlobals,local_140,puVar5,&local_14c);
            if (iVar1 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar5,0x1c,
                                   in_stack_fffffffffffffe88,(char)local_158,(char)iVar1);
              }
            }
            else {
              *(undefined4 *)((longlong)puVar2 + 300) = local_14c;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,puVar5,0x1b,
                                   in_stack_fffffffffffffe88,(char)local_158,(char)local_14c);
              }
            }
            (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_140);
            local_140 = 0;
          }
        }
        iVar1 = CreateChildHidDevice(local_158);
        if (-1 < iVar1) {
          QueryDeviceConfigurationForTelemetry(local_158);
          goto LAB_1c00100be;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar6 = 0x1d;
      }
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,uVar6,
                     in_stack_fffffffffffffe88,(char)local_158,(char)iVar1);
LAB_1c00100be:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar5,0x1e);
  }
  return iVar1;
}



===== EvtDeviceCleanupCallback @ 1c0010120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtDeviceCleanupCallback(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018);
  if (*(longlong *)(lVar1 + 0xb0) != 0) {
    ExDeleteTimer(*(longlong *)(lVar1 + 0xb0),1,1,0);
    *(undefined8 *)(lVar1 + 0xb0) = 0;
  }
  if (*(longlong *)(lVar1 + 0xb8) != 0) {
    ExDeleteTimer(*(longlong *)(lVar1 + 0xb8),1,1,0);
    *(undefined8 *)(lVar1 + 0xb8) = 0;
  }
  return;
}



===== QueryDeviceConfigurationForTelemetry @ 1c00101ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QueryDeviceConfigurationForTelemetry(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  char *pcVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  undefined8 uVar10;
  int local_res8 [2];
  undefined8 local_res10;
  ulonglong local_res18;
  ulonglong *puVar11;
  undefined1 uVar12;
  ulonglong local_78;
  undefined *local_70;
  undefined8 local_68;
  ulonglong local_60 [5];
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_78 = (ulonglong)(uint)local_78;
  local_60[0] = (ulonglong)(uint)local_60[0];
  local_res8[0] = 0;
  local_res18 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_CONTEXT_TYPE_INFO_1c000c018);
  local_78 = 0x18;
  local_68 = 0;
  local_30 = 0;
  local_res10 = 0;
  local_60[2] = 0;
  local_60[3] = 0x100000001;
  puVar9 = &local_78;
  local_70 = &DEVPKEY_Device_InstanceId;
  puVar11 = local_60;
  local_60[1] = 0;
  local_60[0] = 0x38;
  uStack_38 = 0;
  uVar7 = param_1;
  local_60[4] = param_1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,puVar9,0x200,puVar11,&local_res10,local_res8);
  uVar12 = (undefined1)param_1;
  if ((iVar2 < 0) || (local_res8[0] != 0x12)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar9,0x93,puVar11,
                          uVar12,(char)iVar2,(char)local_res8[0]);
    }
    if (-1 < iVar2) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
    }
  }
  else {
    uVar10 = 0;
    uVar7 = local_res10;
    pwVar4 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals);
    *(wchar_t **)(lVar3 + 0x160) = pwVar4;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,uVar10,0x94,puVar11,uVar12
                         ,pwVar4);
    }
  }
  local_78 = 0x18;
  local_70 = &DEVPKEY_Device_HardwareIds;
  puVar9 = &local_78;
  puVar11 = local_60;
  local_68 = 0;
  local_res10 = 0;
  uVar7 = param_1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,puVar9,0x200,puVar11,&local_res10,local_res8);
  if ((iVar2 < 0) || (local_res8[0] != 0x2012)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar9,0x95,puVar11,
                          uVar12,(char)iVar2,(char)local_res8[0]);
    }
    if (-1 < iVar2) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
    }
  }
  else {
    puVar9 = &local_res18;
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res10);
    *(longlong *)(lVar3 + 0x168) = lVar5;
    uVar8 = local_res18 >> 1;
    WStringListToWString(lVar5,uVar8);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,puVar9,0x96,puVar11,uVar12
                         ,*(wchar_t **)(lVar3 + 0x168));
    }
  }
  local_78 = 0x18;
  local_70 = &DEVPKEY_Device_LowerFilters;
  puVar9 = &local_78;
  puVar11 = local_60;
  local_68 = 0;
  local_res10 = 0;
  uVar7 = param_1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,puVar9,0x200,puVar11,&local_res10,local_res8);
  if ((iVar2 < 0) || (local_res8[0] != 0x2012)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar9,0x97,puVar11,
                          uVar12,(char)iVar2,(char)local_res8[0]);
    }
    if (-1 < iVar2) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
      local_res10 = 0;
    }
  }
  else {
    puVar9 = &local_res18;
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res10);
    *(longlong *)(lVar3 + 0x170) = lVar5;
    uVar8 = local_res18 >> 1;
    WStringListToWString(lVar5,uVar8);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,puVar9,0x98,puVar11,uVar12
                         ,*(wchar_t **)(lVar3 + 0x170));
    }
  }
  local_78 = 0x18;
  local_70 = &DEVPKEY_Device_InLocalMachineContainer;
  puVar9 = &local_78;
  puVar11 = local_60;
  local_68 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,puVar9,0x200,puVar11,&local_res10,local_res8);
  if ((iVar2 < 0) || (local_res8[0] != 0x11)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,puVar9,0x99,puVar11,
                          uVar12,(char)iVar2,(char)local_res8[0]);
    }
    if (iVar2 < 0) {
      return;
    }
  }
  else {
    uVar7 = 0;
    pcVar6 = (char *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res10);
    cVar1 = *pcVar6;
    *(bool *)(lVar3 + 0x178) = cVar1 == -1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar7,0x9a,puVar11,uVar12,
                         cVar1 == -1);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
  return;
}



===== WnfEventHandler @ 1c00106d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WnfEventHandler(longlong param_1,undefined8 *param_2,char param_3)

{
  char cVar1;
  char cVar2;
  longlong *plVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined8 in_stack_ffffffffffffffe8;
  
  plVar3 = param_2 + 0x27;
  uVar4 = 0;
  do {
    if (param_1 == *plVar3) {
      if (param_2 + (ulonglong)uVar4 * 2 + 0x27 != (undefined8 *)0x0) {
        uVar5 = 0;
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_2[0x24]);
        *(char *)(param_2 + (ulonglong)uVar4 * 2 + 0x27 + 1) = param_3;
        if (uVar4 == 0) {
          if (param_3 == '\0') {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0010813;
            uVar6 = 0x72;
          }
          else {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0010813;
            uVar6 = 0x71;
          }
        }
        else {
          if (uVar4 != 1) goto LAB_1c0010813;
          if (param_3 == '\0') {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0010813;
            uVar6 = 0x74;
          }
          else {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0010813;
            uVar6 = 0x73;
          }
        }
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar5,uVar6,
                          in_stack_ffffffffffffffe8,(char)*param_2);
LAB_1c0010813:
        cVar1 = *(char *)(param_2 + 0x28);
        cVar2 = *(char *)(param_2 + 0x2a);
        if (g_UseMobileButtonsMapping == '\0') {
          SetButtonEnabled(param_2,4,cVar1 == '\0');
          SetButtonEnabled(param_2,2,cVar1 == '\0' || cVar2 != '\0');
          SetButtonEnabled(param_2,3,cVar1 == '\0' || cVar2 != '\0');
        }
        else {
          uVar4 = 0;
          do {
            if ((uVar4 != 1) &&
               ((1 << ((byte)uVar4 & 0x1f) &
                *(uint *)((longlong)param_2 + 300) & *(uint *)((longlong)param_2 + 100)) != 0)) {
              SetButtonEnabled(param_2,uVar4,cVar1 == '\0');
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < 0xc);
        }
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_2[0x24]);
        return;
      }
      break;
    }
    uVar4 = uVar4 + 1;
    plVar3 = plVar3 + 2;
  } while (uVar4 < 2);
  if ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) {
    RtlAssert("FALSE","onecore\\drivers\\input\\hid\\miniports\\buttonconverter\\src\\btnconv.c",
              0xa81,0);
  }
  return;
}



===== WnfEventStartCallback @ 1c0010900 =====

void WnfEventStartCallback(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  WnfEventHandler(param_1,param_3,'\x01');
  return;
}



===== WnfEventStopCallback @ 1c0010920 =====

void WnfEventStopCallback(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  WnfEventHandler(param_1,param_3,'\0');
  return;
}



===== WppCleanupKm @ 1c001093c =====

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



===== WppInitKm @ 1c00109ec =====

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



===== WppLoadTracingSupport @ 1c0010ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  _pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite = 2;
  if (_pfnWppGetVersion != (code *)0x0) {
    (*_pfnWppGetVersion)(local_res8,0,0,0);
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



===== WppTraceCallback @ 1c0010c10 =====

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



===== CancelTimerCallbacksAndDeleteTimer @ 1c0010e98 =====

void CancelTimerCallbacksAndDeleteTimer(longlong param_1)

{
  short *psVar1;
  short sVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (*(longlong *)(param_1 + 0x168) != 0) {
    LOCK();
    psVar1 = (short *)(*(longlong *)(param_1 + 0x108) + 0x38);
    sVar2 = *psVar1;
    *psVar1 = 2;
    UNLOCK();
    if (sVar2 == 1) {
      KeWaitForSingleObject(*(longlong *)(param_1 + 0x108) + 0x20,0,0,0,0);
    }
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    ExDeleteTimer(*(undefined8 *)(param_1 + 0x168),1,1,&local_28);
    *(undefined8 *)(param_1 + 0x168) = 0;
  }
  return;
}



===== CreateTlgAggregateSession @ 1c0010f28 =====

void * CreateTlgAggregateSession(char param_1,char param_2)

{
  undefined8 *puVar1;
  void *_Dst;
  void *_Dst_00;
  longlong lVar2;
  
  _Dst = (void *)ExAllocatePoolWithTag
                           ((-(uint)(param_1 != '\0') & 0xfffffe01) + 0x200,0x178,0x47417254);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x178);
    *(undefined8 *)((longlong)_Dst + 0x110) = 0;
    if ((param_2 == '\0') && (param_1 != '\0')) {
      return _Dst;
    }
    _Dst_00 = (void *)ExAllocatePoolWithTag(0x200,0x40,0x47417254);
    if (_Dst_00 != (void *)0x0) {
      memset(_Dst_00,0,0x40);
    }
    *(void **)((longlong)_Dst + 0x108) = _Dst_00;
    if (_Dst_00 != (void *)0x0) {
      KeInitializeEvent((longlong)_Dst_00 + 0x20,0,0);
      puVar1 = *(undefined8 **)((longlong)_Dst + 0x108);
      puVar1[2] = TlgAggregateInternalFlushWorkItemRoutineKernelMode;
      puVar1[3] = _Dst;
      *puVar1 = 0;
      *(undefined2 *)(*(longlong *)((longlong)_Dst + 0x108) + 0x38) = 0;
      if (param_2 == '\0') {
        return _Dst;
      }
      lVar2 = ExAllocateTimer(TlgAggregateInternalFlushTimerCallbackKernelMode,
                              *(undefined8 *)((longlong)_Dst + 0x108),8);
      *(longlong *)((longlong)_Dst + 0x168) = lVar2;
      if (lVar2 != 0) {
        return _Dst;
      }
    }
  }
  DestroyAggregateSession((longlong)_Dst);
  return (void *)0x0;
}



===== DestroyAggregateSession @ 1c0011080 =====

void DestroyAggregateSession(longlong param_1)

{
  if (param_1 != 0) {
    CancelTimerCallbacksAndDeleteTimer(param_1);
    if (*(longlong *)(param_1 + 0x108) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x108),0);
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== FlushEventEntryList @ 1c00110cc =====

void FlushEventEntryList(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  if (param_2 != 0) {
    do {
      iVar2 = 2;
      if (2 < *(byte *)(param_2 + 0x2d) + 2) {
        lVar1 = 0x20;
        do {
          lVar1 = lVar1 + 0x10;
          iVar2 = iVar2 + 1;
          *(undefined1 *)(*(longlong *)(param_2 + 0x10) + -3 + lVar1) = 0;
        } while (iVar2 < (int)(*(byte *)(param_2 + 0x2d) + 2));
      }
      EtwWriteTransfer(param_1,param_2,0,0,*(undefined1 *)(param_2 + 0x2c),
                       *(undefined8 *)(param_2 + 0x10));
      lVar1 = *(longlong *)(param_2 + 0x18);
      DestroyEventEntry(param_2);
      param_2 = lVar1;
    } while (lVar1 != 0);
  }
  return;
}



===== LookUpTableFlushComplete @ 1c001116c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LookUpTableFlushComplete(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  _tlgProvider_t *p_Var5;
  longlong lVar6;
  uint uVar7;
  undefined1 auStackY_268 [32];
  _tlgWrapperByVal<1> local_148;
  _tlgWrapperByVal<1> local_147;
  _tlgWrapperByVal<1> local_146;
  _tlgWrapperByVal<1> local_145;
  _tlgWrapperByVal<1> local_144;
  _tlgWrapperByVal<1> local_143;
  _tlgWrapperByVal<1> local_142;
  _tlgWrapperByVal<1> local_141;
  _tlgWrapperByVal<1> local_140;
  _tlgWrapperByVal<1> local_13f [3];
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  ulonglong local_130;
  ulonglong local_128;
  ulonglong local_120;
  _GUID *local_118;
  _GUID *local_110;
  undefined8 local_108;
  ulonglong local_100;
  longlong local_f8;
  undefined8 *local_f0;
  undefined8 local_e8;
  wchar_t *local_e0;
  undefined2 local_d8;
  wchar_t *local_d0;
  undefined2 local_c8;
  wchar_t *local_c0;
  undefined2 local_b8;
  wchar_t *local_b0;
  undefined2 local_a8;
  wchar_t *local_a0;
  undefined2 local_98;
  wchar_t *local_90;
  undefined2 local_88;
  wchar_t *local_80;
  undefined2 local_78;
  wchar_t *local_70;
  undefined2 local_68;
  wchar_t *local_60;
  undefined2 local_58;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_268;
  uVar2 = *(uint *)(param_1 + 0x100);
  uVar7 = 0;
  if (uVar2 != 0) {
    if ((uVar2 < *(uint *)(param_1 + 0x138)) ||
       (lVar6 = *(longlong *)(param_1 + 0x128), uVar3 = *(uint *)(param_1 + 0x138), lVar6 == 0)) {
      lVar6 = *(longlong *)(param_1 + 0x128);
      *(uint *)(param_1 + 0x138) = uVar2;
      uVar3 = uVar2;
    }
    uVar4 = *(uint *)(param_1 + 0x134);
    if (*(uint *)(param_1 + 0x134) < uVar2) {
      *(uint *)(param_1 + 0x134) = uVar2;
      uVar4 = uVar2;
    }
    plVar1 = (longlong *)(param_1 + 0x120);
    *plVar1 = *plVar1 + (ulonglong)uVar2;
    *(longlong *)(param_1 + 0x128) = lVar6 + 1;
    if (*plVar1 != 0) {
      if (((5 < (uint)DAT_1c000c0f0) && ((_DAT_1c000c100 & 0x200000000000) != 0)) &&
         ((DAT_1c000c108 & 0x200000000000) == DAT_1c000c108)) {
        local_148 = (_tlgWrapperByVal<1>)0x4;
        local_e0 = L"SummaryCount";
        local_d8 = 0x18;
        local_130 = (ulonglong)*(uint *)(param_1 + 0x144);
        local_d0 = L"NumLargeEventFailures";
        local_128 = (ulonglong)*(uint *)(param_1 + 0x140);
        local_c0 = L"NumAllocationFailures";
        local_120 = (ulonglong)*(uint *)(param_1 + 0x13c);
        local_b0 = L"NumBucketLimitReached";
        local_a0 = L"MinEntriesFlushed";
        local_90 = L"MaxEntriesFlushed";
        local_80 = L"TotalEntriesFlushed";
        local_78 = 0x26;
        local_100 = (ulonglong)*(uint *)(param_1 + 0x130);
        local_70 = L"MaxEntriesStored";
        local_60 = L"NumFlushes";
        local_58 = 0x14;
        local_c8 = 0x2a;
        local_b8 = 0x2a;
        local_a8 = 0x2a;
        local_13c = 1;
        local_147 = (_tlgWrapperByVal<1>)0x4;
        local_146 = (_tlgWrapperByVal<1>)0x4;
        local_145 = (_tlgWrapperByVal<1>)0x4;
        local_144 = (_tlgWrapperByVal<1>)0x4;
        local_143 = (_tlgWrapperByVal<1>)0x4;
        local_142 = (_tlgWrapperByVal<1>)0x4;
        local_141 = (_tlgWrapperByVal<1>)0x4;
        local_140 = (_tlgWrapperByVal<1>)0x4;
        local_98 = 0x22;
        local_88 = 0x22;
        p_Var5 = *(_tlgProvider_t **)(*(longlong *)(param_1 + 0x158) + 8);
        local_f0 = &local_28;
        local_28 = *(undefined8 *)(p_Var5 + -0x10);
        uStack_20 = *(undefined8 *)(p_Var5 + -8);
        local_138 = 0xffffffff;
        local_68 = 0x20;
        local_13f[0] = (_tlgWrapperByVal<1>)0x0;
        local_134 = 300;
        local_e8 = 0x1000000;
        local_118 = (_GUID *)(ulonglong)uVar3;
        local_110 = (_GUID *)(ulonglong)uVar4;
        local_108 = *(undefined8 *)(param_1 + 0x120);
        local_f8 = lVar6 + 1;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_>
                  (p_Var5,&DAT_1c000ad09,(_GUID *)(ulonglong)uVar4,(_GUID *)(ulonglong)uVar3,
                   (_tlgWrapperByVal<8> *)&local_e8,(_tlgWrapperByVal<4> *)&local_134,
                   (_tlgWrapperByVal<4> *)&local_138,local_13f,(_tlgWrapperByRef<16> *)&local_f0,
                   (_tlgWrapperBinary *)&local_60,(_tlgWrapperByVal<8> *)&local_f8,&local_140,
                   (_tlgWrapperBinary *)&local_70,(_tlgWrapperByVal<8> *)&local_100,&local_141,
                   (_tlgWrapperBinary *)&local_80,(_tlgWrapperByVal<8> *)&local_108,&local_142,
                   (_tlgWrapperBinary *)&local_90,(_tlgWrapperByVal<8> *)&local_110,&local_143,
                   (_tlgWrapperBinary *)&local_a0,(_tlgWrapperByVal<8> *)&local_118,&local_144,
                   (_tlgWrapperBinary *)&local_b0,(_tlgWrapperByVal<8> *)&local_120,&local_145,
                   (_tlgWrapperBinary *)&local_c0,(_tlgWrapperByVal<8> *)&local_128,&local_146,
                   (_tlgWrapperBinary *)&local_d0,(_tlgWrapperByVal<8> *)&local_130,&local_147,
                   (_tlgWrapperBinary *)&local_e0,(_tlgWrapperByVal<4> *)&local_13c,&local_148);
      }
      *(undefined8 *)(param_1 + 0x120) = 0;
      *(undefined8 *)(param_1 + 0x128) = 0;
      local_30 = 0;
      *(undefined8 *)(param_1 + 0x130) = 0;
      *(undefined8 *)(param_1 + 0x138) = 0;
      *(undefined8 *)(param_1 + 0x140) = 0;
    }
    do {
      FlushLookUpTableBucket(param_1,uVar7);
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x20);
  }
  return;
}



===== LookUpTableFlushPartial @ 1c0011554 =====

void LookUpTableFlushPartial(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 0x100) != 0) {
    uVar2 = *(uint *)(param_1 + 0x104);
    uVar4 = uVar2;
    do {
      if (*(longlong *)(param_1 + (ulonglong)uVar4 * 8) != 0) {
        iVar3 = FlushLookUpTableBucket(param_1,uVar4);
        uVar5 = uVar5 + iVar3;
      }
      uVar4 = uVar4 + 1 & 0x1f;
    } while ((uVar4 != uVar2) && (uVar5 < 0x10));
    *(uint *)(param_1 + 0x104) = uVar4;
    if (uVar5 != 0) {
      plVar1 = (longlong *)(param_1 + 0x128);
      if ((uVar5 < *(uint *)(param_1 + 0x138)) || (*plVar1 == 0)) {
        *(uint *)(param_1 + 0x138) = uVar5;
      }
      if (*(uint *)(param_1 + 0x134) < uVar5) {
        *(uint *)(param_1 + 0x134) = uVar5;
      }
      *plVar1 = *plVar1 + 1;
      *(longlong *)(param_1 + 0x120) = *(longlong *)(param_1 + 0x120) + (ulonglong)uVar5;
    }
  }
  return;
}



===== TlgAggregateInternalFlushWorkItemRoutineKernelMode @ 1c0011600 =====

/* void __cdecl TlgAggregateInternalFlushWorkItemRoutineKernelMode(void * __ptr64) */

void __cdecl TlgAggregateInternalFlushWorkItemRoutineKernelMode(void *param_1)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  
  if (*(char *)((longlong)param_1 + 0x174) == '\0') {
    LookUpTableFlushPartial((longlong)param_1);
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x174) = 0;
    LookUpTableFlushComplete((longlong)param_1);
  }
  if (*(int *)((longlong)param_1 + 0x100) != 0) {
    EnableFlushTimer(*(longlong *)((longlong)param_1 + 0x168),
                     (ulonglong)*(uint *)((longlong)param_1 + 0x170));
  }
  sVar3 = 1;
  psVar1 = (short *)(*(longlong *)((longlong)param_1 + 0x108) + 0x38);
  LOCK();
  sVar2 = *psVar1;
  if (sVar2 == 1) {
    *psVar1 = 0;
  }
  else {
    sVar3 = sVar2;
  }
  UNLOCK();
  if (sVar3 == 2) {
    KeSetEvent(*(longlong *)((longlong)param_1 + 0x108) + 0x20,0,0);
  }
  return;
}



===== TlgAggregateInternalProviderCallback @ 1c0011690 =====

/* void __cdecl TlgAggregateInternalProviderCallback(struct _GUID const * __ptr64,unsigned
   long,unsigned char,unsigned __int64,unsigned __int64,struct _EVENT_FILTER_DESCRIPTOR *
   __ptr64,void * __ptr64) */

void __cdecl
TlgAggregateInternalProviderCallback
          (_GUID *param_1,ulong param_2,uchar param_3,__uint64 param_4,__uint64 param_5,
          _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  char cVar1;
  longlong lVar2;
  
  if (((param_2 == 2) && (param_4 == 0x20)) &&
     (cVar1 = ExTryAcquirePushLockExclusiveEx(&DAT_1c000c560,0), cVar1 != '\0')) {
    for (lVar2 = DAT_1c000c568; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x160)) {
      LookUpTableFlushComplete(lVar2);
    }
    ExReleasePushLockExclusiveEx(&DAT_1c000c560,0);
  }
  return;
}



===== TlgAggregateInternalRegisteredProviderEtwCallback @ 1c0011700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl TlgAggregateInternalRegisteredProviderEtwCallback(struct _GUID const *
   __ptr64,unsigned long,unsigned char,unsigned __int64,unsigned __int64,struct
   _EVENT_FILTER_DESCRIPTOR * __ptr64,void * __ptr64) */

void __cdecl
TlgAggregateInternalRegisteredProviderEtwCallback
          (_GUID *param_1,ulong param_2,uchar param_3,__uint64 param_4,__uint64 param_5,
          _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  if (*(code **)((longlong)param_7 + 0x148) != (code *)0x0) {
    (**(code **)((longlong)param_7 + 0x148))
              (param_1,param_2,param_3,param_4,param_5,param_6,
               *(undefined8 *)((longlong)param_7 + 0x150));
  }
  if (param_2 == 1) {
    LookUpTableFlushComplete((longlong)param_7);
  }
  else if (param_2 == 2) {
    LookUpTableFlushPartial((longlong)param_7);
  }
  return;
}



===== TlgRegisterAggregateProvider @ 1c001177c =====

void TlgRegisterAggregateProvider(void)

{
  TlgRegisterAggregateProviderEx();
  return;
}



===== TlgRegisterAggregateProviderEx @ 1c0011794 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TlgRegisterAggregateProviderEx(void)

{
  int iVar1;
  void *pvVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  ulonglong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  pvVar2 = CreateTlgAggregateSession('\0','\x01');
  if (pvVar2 == (void *)0x0) {
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x1c000c078,0,0);
  }
  else {
    *(undefined8 *)((longlong)pvVar2 + 0x148) = 0;
    *(undefined8 *)((longlong)pvVar2 + 0x150) = 0;
    local_38[0] = 0;
    *(undefined4 **)((longlong)pvVar2 + 0x158) = &DAT_1c000c078;
    *(undefined1 *)((longlong)pvVar2 + 0x175) = 0;
    local_28 = *(undefined8 *)(PTR_DAT_1c000c080 + -0x10);
    uStack_20 = *(undefined8 *)(PTR_DAT_1c000c080 + -8);
    local_30 = (ulonglong)pvVar2 >> 4;
    RunningHash(local_38,(longlong)&local_28,0x10);
    RunningHash(local_38,(longlong)&local_30,8);
    FinishHash((int *)local_38);
    *(uint *)((longlong)pvVar2 + 0x170) = local_38[0] % 600000 + 600000;
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                      (0x1c000c078,TlgAggregateInternalRegisteredProviderEtwCallback,pvVar2);
    if (iVar1 < 0) {
      DAT_1c000c0a0 = 0;
      DestroyAggregateSession((longlong)pvVar2);
    }
    else {
      ExAcquirePushLockExclusiveEx(&DAT_1c000c560,0);
      if (DAT_1c000c568 == 0) {
        TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                  (0x1c000c0f0,TlgAggregateInternalProviderCallback,0);
      }
      plVar4 = &DAT_1c000c568;
      lVar3 = DAT_1c000c568;
      while (lVar3 != 0) {
        if (*(undefined4 **)(lVar3 + 0x158) == &DAT_1c000c078) goto LAB_1c00118f0;
        plVar4 = (longlong *)(lVar3 + 0x160);
        lVar3 = *plVar4;
      }
      *plVar4 = (longlong)pvVar2;
LAB_1c00118f0:
      ExReleasePushLockExclusiveEx(&DAT_1c000c560,0);
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== TlgUnregisterAggregateProvider @ 1c0011940 =====

void TlgUnregisterAggregateProvider(void)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  
  uVar2 = DAT_1c000c098;
  if (DAT_1c000c0a0 == TlgAggregateInternalRegisteredProviderEtwCallback) {
    lVar5 = 0;
    ExAcquirePushLockExclusiveEx(&DAT_1c000c560,0);
    lVar3 = DAT_1c000c568;
    plVar4 = &DAT_1c000c568;
    while (lVar3 != 0) {
      plVar1 = (longlong *)(lVar3 + 0x160);
      if (*(undefined4 **)(lVar3 + 0x158) == &DAT_1c000c078) {
        *plVar4 = *plVar1;
        LookUpTableFlushComplete(lVar3);
        uVar2 = DAT_1c000c110;
        lVar5 = lVar3;
        if (DAT_1c000c568 == 0) {
          DAT_1c000c110 = 0;
          DAT_1c000c0f0._0_4_ = 0;
          EtwUnregister(uVar2);
        }
        break;
      }
      plVar4 = plVar1;
      lVar3 = *plVar1;
    }
    ExReleasePushLockExclusiveEx(&DAT_1c000c560,0);
    if (lVar5 != 0) {
      CancelTimerCallbacksAndDeleteTimer(lVar5);
    }
    uVar2 = DAT_1c000c098;
    DAT_1c000c098 = 0;
    DAT_1c000c078 = 0;
    EtwUnregister(uVar2);
    DAT_1c000c0a0 = (code *)0x0;
    DestroyAggregateSession(lVar5);
  }
  else {
    DAT_1c000c098 = 0;
    DAT_1c000c078 = 0;
    EtwUnregister(uVar2);
  }
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1c0011a64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
              (longlong param_1,undefined8 param_2,undefined8 param_3)

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
  *(undefined8 *)(param_1 + 0x28) = param_2;
  *(undefined8 *)(param_1 + 0x30) = param_3;
  *(undefined8 *)(puVar7 + -8) = 0x1c0011ac5;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x1c0011ae5;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x1c0011af9;
  return iVar6;
}



===== _tlgEnableCallback @ 1c0011b10 =====

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



===== __security_init_cookie @ 1c0012008 =====

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



===== DriverEntry @ 1c001203c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  char cVar3;
  undefined2 uVar4;
  undefined1 auStackY_188 [32];
  undefined8 in_stack_fffffffffffffe98;
  ulonglong *puVar5;
  ulonglong local_148;
  int local_140 [2];
  undefined8 local_138;
  wchar_t *local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 *local_118;
  undefined8 local_110;
  wchar_t *local_108;
  ulonglong local_100;
  code *local_f8;
  code *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  wchar_t local_e0 [20];
  wchar_t local_b8 [24];
  undefined8 local_88;
  wchar_t awStack_80 [36];
  ulonglong local_38;
  
  local_118 = &local_88;
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
  local_100 = (ulonglong)(uint)local_100;
  builtin_wcsncpy(local_b8,L"UseMobileButtonsMapping",0x18);
  local_130 = local_b8;
  cVar3 = '\x01';
  local_128 = 0;
  local_88._0_2_ = L'\\';
  local_88._2_2_ = L'R';
  local_88._4_2_ = L'e';
  local_88._6_2_ = L'g';
  builtin_wcsncpy(awStack_80,L"istry\\Machine\\SYSTEM\\Input\\F",0x1c);
  builtin_wcsncpy(local_e0,L"EnableTestFeatures",0x13);
  local_108 = local_e0;
  builtin_wcsncpy(awStack_80 + 0x1c,L"ingerKB",8);
  local_148 = 0;
  local_140[0] = 0;
  local_138 = 0x30002e;
  local_120 = 0x50004e;
  local_110 = 0x260024;
  _WPP_MAIN_CB = 0;
  DAT_1c000c588 = &WPP_ThisDir_CTLGUID_BTNCONV;
  DAT_1c000c590 = 0;
  _DAT_1c000c5a0 = 0;
  _DAT_1c000c5a8 = 1;
  _DAT_1c000c5c0 = 0;
  _DAT_1c000c5c8 = 0;
  WppLoadTracingSupport();
  _DAT_1c000c5a0 = 0;
  WppInitKm(param_1,param_2);
  TlgRegisterAggregateProvider();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,10,
                      in_stack_fffffffffffffe98,(char)param_1);
  }
  local_100 = 0x20;
  local_f8 = EvtDeviceAdd;
  local_f0 = DriverUnload;
  puVar5 = &local_100;
  local_e8 = 0;
  local_e4 = 0x434e5442;
  uVar2 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0012466;
    uVar4 = 0xb;
  }
  else {
    puVar5 = &local_148;
    param_2 = (undefined8 *)0x20019;
    uVar2 = local_128;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))(WdfDriverGlobals,local_128,0x20019,0);
    if (-1 < iVar1) {
      param_2 = &local_138;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                        (WdfDriverGlobals,local_148,param_2,local_140);
      if (iVar1 < 0) {
        if (iVar1 != -0x3fffffcc) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          goto LAB_1c0012466;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
LAB_1c001232c:
        cVar3 = '\0';
      }
      else if (local_140[0] == 0) goto LAB_1c001232c;
      g_UseMobileButtonsMapping = cVar3;
      (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_148);
      local_148 = 0;
      if (g_UseMobileButtonsMapping == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_2,0x10);
        }
        DAT_1c000c1c7 = 0x5c;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_2,0xf);
        }
        DAT_1c000c1c7 = 0x2b;
      }
      g_TestCombosEnabled = 0;
      if (g_UseMobileButtonsMapping != '\0') {
        param_2 = &local_120;
        puVar5 = (ulonglong *)0x0;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))(WdfDriverGlobals,0,param_2,0x20019);
        if (-1 < iVar1) {
          param_2 = &local_110;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                            (WdfDriverGlobals,local_148,param_2,local_140);
          if (-1 < iVar1) {
            g_TestCombosEnabled = local_140[0] != 0;
          }
          (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_148);
          local_148 = 0;
        }
      }
      iVar1 = 0;
      goto LAB_1c0012466;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0012466;
    uVar4 = 0xc;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,param_2,uVar4,puVar5,
                    (char)iVar1);
LAB_1c0012466:
  if (local_148 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
    local_148 = 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_2,0x11,puVar5,
                       (char)param_1,(char)iVar1);
  }
  if (iVar1 < 0) {
    TlgUnregisterAggregateProvider();
    WppCleanupKm(param_1);
  }
  return iVar1;
}


