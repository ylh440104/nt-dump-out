
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

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



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>,_tlgWrapperByRef<16>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<8>,_tlgWrapperByVal<1>,_tlgWrapperBinary,_tlgWrapperByVal<4>,_tlgWrapperByVal<1>_> @ 1400010ac =====

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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14002a040,param_2,0,0,0x2b,local_2c8);
  return lVar1;
}



===== __report_gsfailure @ 140001500 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000150d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000150d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== FseCreateIoDeviceObject @ 140001520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FseCreateIoDeviceObject(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined1 auStackY_c8 [32];
  uint local_88 [2];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  RtlInitUnicodeString(&local_80,L"\\Device\\FseIoDevice");
  uVar3 = IoCreateDevice(param_1,0);
  bVar1 = true;
  if (uVar3 == 0) {
    uVar3 = FseSetDeviceDacl(FseGlobalContext);
    if (uVar3 == 0) {
      puVar5 = (undefined8 *)(param_1 + 0x70);
      for (lVar4 = 0x1b; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar5 = FseDriverDispatch;
        puVar5 = puVar5 + 1;
      }
      *(code **)(param_1 + 0x70) = FseDriverDispatchCleanup;
      *(code **)(param_1 + 0x80) = FseDriverDispatchClose;
      *(code **)(param_1 + 0xe0) = FseDriverDispatchDevControl;
      *(code **)(param_1 + 0x100) = FseDriverDispatchCleanup;
      RtlInitUnicodeString(&local_70,L"\\GLOBAL??\\FseIoDevice");
      IoCreateSymbolicLink(&local_70,&local_80);
      return 0;
    }
  }
  else {
    if (DAT_14002a000 < 3) {
      return uVar3;
    }
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "L\"IoCreateDevice\" failed.";
      local_28 = local_88;
      local_30 = 0x1a;
      local_20 = 4;
      local_88[0] = uVar3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023ac7,0,0,4,local_58);
    }
  }
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseCreateIoDeviceObject returned error";
      local_28 = local_88;
      local_30 = 0x27;
      local_20 = 4;
      local_88[0] = uVar3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023a91,0,0,4,local_58);
    }
  }
  return uVar3;
}



===== FseDriverAddHostVnicIoctl @ 140001778 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NET_IFINDEX FseDriverAddHostVnicIoctl(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  NET_IFINDEX NVar3;
  NET_IFINDEX NVar4;
  byte *pbVar5;
  undefined1 auStackY_98 [32];
  NET_IFINDEX local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  NET_IFINDEX *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar1 = true;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 8) {
    NVar3 = 0xc000000d;
    if (DAT_14002a000 < 3) {
      return 0xc000000d;
    }
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) goto LAB_1400018ad;
    local_38 = "L\"FseDriverAddHostVnicIoctl\" failed.";
    local_30 = 0x25;
    pbVar5 = &DAT_140024188;
  }
  else {
    NVar3 = (*(NET_IFINDEX **)(param_1 + 0x18))[1];
    NVar4 = 1;
    if (NVar3 != 0) {
      NVar4 = NVar3;
    }
    NVar3 = FseIpsClientSetHostVnic(**(NET_IFINDEX **)(param_1 + 0x18),NVar4);
    if (NVar3 == 0) {
      return 0;
    }
    if (DAT_14002a000 < 3) goto LAB_1400018ad;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) goto LAB_1400018ad;
    local_38 = "L\"FseIpsClientSetHostVnic\" failed.";
    local_30 = 0x23;
    pbVar5 = &DAT_140024156;
  }
  local_2c = 0;
  local_1c = 0;
  local_28 = local_68;
  local_20 = 4;
  local_68[0] = NVar3;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar5,0,0,4,local_58);
LAB_1400018ad:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseDriverAddHostVnicIoctl returned error";
      local_28 = local_68;
      local_30 = 0x29;
      local_20 = 4;
      local_68[0] = NVar3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024120,0,0,4,local_58);
    }
  }
  return NVar3;
}



===== FseDriverConfigurePortPolicy @ 140001950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseDriverConfigurePortPolicy(longlong param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined1 auStackY_98 [32];
  int local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar2 = true;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10);
  if (uVar1 < 2) {
    iVar4 = -0x3ffffff3;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_2c = 0;
        local_1c = 0;
        local_38 = "FseDriverConfigurePortPolicyInvalid Input Buffer";
        local_28 = local_68;
        local_30 = 0x31;
        local_68[0] = -0x3ffffff3;
        local_20 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400248b4,0,0,4,local_58);
      }
    }
  }
  else {
    iVar4 = FsePortPolicyConfigure(uVar1,*(ushort **)(param_1 + 0x18));
    if (-1 < iVar4) goto LAB_140001a3c;
  }
  FseDiagnosticsLogFailure(5,iVar4);
LAB_140001a3c:
  if ((iVar4 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseDriverConfigurePortPolicy returned error";
      local_28 = local_68;
      local_30 = 0x2c;
      local_20 = 4;
      local_68[0] = iVar4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002487e,0,0,4,local_58);
    }
  }
  return iVar4;
}



===== FseDriverCreateNicPairIoctl @ 140001af4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FseDriverCreateNicPairIoctl(longlong param_1)

{
  NET_IFINDEX *pNVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  undefined8 uVar6;
  byte *pbVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined1 auStackY_f8 [32];
  uint local_c8 [2];
  undefined8 *local_c0;
  undefined8 *local_b8;
  longlong local_b0;
  undefined8 *local_a8;
  undefined8 *local_a0;
  longlong local_98;
  undefined8 *local_90;
  undefined8 local_88;
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  puVar8 = (undefined8 *)0x0;
  local_88 = 0;
  puVar9 = (undefined8 *)0x0;
  bVar3 = false;
  local_c0 = (undefined8 *)0x0;
  local_b8 = (undefined8 *)0x0;
  bVar2 = true;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x40) {
    uVar5 = 0xc000000d;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_4c = 0;
        local_3c = 0;
        local_58 = "L\"FseDriverCreateNicPairIoctl\" failed.";
        local_48 = local_c8;
        local_50 = 0x27;
        local_c8[0] = 0xc000000d;
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024450,0,0,4,local_78);
      }
    }
  }
  else {
    pNVar1 = *(NET_IFINDEX **)(param_1 + 0x18);
    uVar5 = FseIpsClientAddPhysicalInterface(*pNVar1);
    if (uVar5 == 0) {
      bVar3 = true;
      uVar6 = FseAllocMemory(0x28,0x43447346,&local_c0);
      puVar9 = local_c0;
      uVar5 = (uint)uVar6;
      if (uVar5 != 0) goto LAB_140001ccb;
      uVar6 = *(undefined8 *)(pNVar1 + 6);
      *local_c0 = *(undefined8 *)(pNVar1 + 4);
      local_c0[1] = uVar6;
      uVar6 = *(undefined8 *)(pNVar1 + 10);
      local_c0[2] = *(undefined8 *)(pNVar1 + 8);
      local_c0[3] = uVar6;
      local_c0[4] = *(undefined8 *)(pNVar1 + 0xc);
      uVar5 = ConvertInterfaceIndexToLuid(*pNVar1,(PNET_LUID)(local_c0 + 4));
      if (uVar5 != 0) {
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          if (bVar4) {
            local_58 = "L\"ConvertInterfaceIndexToLuid\" failed.";
            pbVar7 = &DAT_14002441e;
            local_50 = 0x27;
LAB_140001c92:
            local_3c = 0;
            local_4c = 0;
            local_48 = local_c8;
            local_40 = 4;
            local_c8[0] = uVar5;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar7,0,0,4,local_78);
          }
        }
        goto LAB_140001ccb;
      }
      local_b0 = *(longlong *)pNVar1;
      local_a8 = puVar9;
      local_a0 = puVar9;
      uVar6 = FseAllocMemory(0x28,0x43447346,&local_b8);
      puVar8 = local_b8;
      uVar5 = (uint)uVar6;
      if (uVar5 != 0) goto LAB_140001ccb;
      uVar6 = *(undefined8 *)(pNVar1 + 6);
      local_90 = local_b8;
      *local_b8 = *(undefined8 *)(pNVar1 + 4);
      local_b8[1] = uVar6;
      uVar6 = *(undefined8 *)(pNVar1 + 10);
      local_b8[2] = *(undefined8 *)(pNVar1 + 8);
      local_b8[3] = uVar6;
      local_b8[4] = *(undefined8 *)(pNVar1 + 0xc);
      local_98 = *(longlong *)(pNVar1 + 2);
      uVar5 = FseCoreConfigurePhysicalToVirtualNicPairing
                        (DAT_14002a7a8,&local_98,&local_b0,
                         (ulonglong)*(uint *)((longlong)local_b8 + 0x1c),
                         (undefined4 *)((longlong)local_b8 + 0xc));
      if (uVar5 != 0) {
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          if (bVar4) {
            local_58 = "L\"FseCoreConfigurePhysicalToVirtualNicPairing\" failed.";
            pbVar7 = &DAT_1400243ec;
            local_50 = 0x37;
            goto LAB_140001c92;
          }
        }
        goto LAB_140001ccb;
      }
      puVar9 = (undefined8 *)0x0;
      puVar8 = (undefined8 *)0x0;
      local_c0 = (undefined8 *)0x0;
      local_b8 = (undefined8 *)0x0;
    }
    else {
LAB_140001ccb:
      if (((int)uVar5 < 0) && (bVar3)) {
        FseIpsClientRemovePhysicalInterface(*pNVar1);
      }
    }
    if (puVar9 != (undefined8 *)0x0) {
      FseFreeMemory((longlong *)&local_c0);
    }
    if (puVar8 != (undefined8 *)0x0) {
      FseFreeMemory((longlong *)&local_b8);
    }
    if (-1 < (int)uVar5) goto LAB_140001d0a;
  }
  FseDiagnosticsLogFailure(3,uVar5);
LAB_140001d0a:
  if ((uVar5 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_4c = 0;
      local_3c = 0;
      local_58 = "FseDriverCreateNicPairIoctl returned error";
      local_48 = local_c8;
      local_50 = 0x2b;
      local_40 = 4;
      local_c8[0] = uVar5;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400243b6,0,0,4,local_78);
    }
  }
  return uVar5;
}



===== FseDriverCreatePartitionIoctl @ 140001eb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseDriverCreatePartitionIoctl
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  byte *pbVar7;
  int iVar8;
  ulonglong uVar9;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [4];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar2 = true;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x18) {
    uVar9 = 0xc000000d;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_3c = 0;
        local_2c = 0;
        local_48 = "L\"FseDriverCreatePartitionIoctl\" failed.";
        local_38 = local_78;
        local_40 = 0x29;
        local_78[0] = 0xc000000d;
        local_30 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400247e4,0,0,4,local_68);
      }
    }
  }
  else {
    plVar1 = *(longlong **)(param_1 + 0x18);
    uVar4 = FseAllocatorNotifyCreatePartition(plVar1);
    uVar9 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      uVar9 = (ulonglong)*(uint *)(plVar1 + 2);
      uVar5 = FsePortTrackerSetPartitionData(plVar1,uVar9,param_3);
      if ((int)uVar5 != 0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      if (*(char *)((longlong)plVar1 + 0x14) != '\0') {
        uVar6 = PtServerStartPartition(plVar1,uVar9,param_3,param_4);
        uVar9 = uVar6 & 0xffffffff;
        if ((int)uVar6 != 0) {
          FseAllocatorNotifyDestroyPartition(plVar1);
          if (2 < DAT_14002a000) {
            if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
              bVar3 = false;
            }
            else {
              bVar3 = true;
            }
            if (bVar3) {
              local_48 = "L\"PtServerStartPartition\" failed.";
              local_40 = 0x22;
              pbVar7 = &DAT_140024780;
              goto LAB_140001fe7;
            }
          }
          goto LAB_1400020ab;
        }
      }
      uVar9 = FsePortPolicyApplyForPartition(plVar1);
      uVar9 = uVar9 & 0xffffffff;
    }
    else if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_48 = "L\"FseAllocatorNotifyCreatePartition\" failed.";
        local_40 = 0x2d;
        pbVar7 = &DAT_1400247b2;
LAB_140001fe7:
        local_3c = 0;
        local_2c = 0;
        local_38 = local_78;
        local_30 = 4;
        local_78[0] = (undefined4)uVar9;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar7,0,0,4,local_68);
      }
    }
LAB_1400020ab:
    iVar8 = (int)uVar9;
    if (-1 < iVar8) goto LAB_1400020ba;
  }
  iVar8 = (int)uVar9;
  FseDiagnosticsLogFailure(0,iVar8);
LAB_1400020ba:
  local_78[0] = (undefined4)uVar9;
  if ((iVar8 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_3c = 0;
      local_2c = 0;
      local_48 = "FseDriverCreatePartitionIoctl returned error";
      local_38 = local_78;
      local_40 = 0x2d;
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002474a,0,0,4,local_68);
    }
  }
  return uVar9;
}



===== FseDriverDeleteNicPairIoctl @ 140002168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseDriverDeleteNicPairIoctl(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  byte *pbVar7;
  undefined1 auStackY_a8 [32];
  longlong local_78;
  longlong local_70;
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_78 = 0;
  bVar3 = true;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x40) {
    iVar5 = -0x3ffffff3;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if (bVar4) {
        local_3c = 0;
        local_2c = 0;
        local_48 = "L\"FseDriverDeleteNicPairIoctl\" failed.";
        local_38 = &local_78;
        local_40 = 0x27;
        local_78 = 0xc000000d;
        local_30 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024384,0,0,4,local_68);
      }
    }
  }
  else {
    plVar1 = *(longlong **)(param_1 + 0x18);
    FseIpsClientRemovePhysicalInterface((int)*plVar1);
    iVar5 = FseCoreFindNicPairEntryByVirtualNicId(DAT_14002a7a8,plVar1[1],&local_78);
    lVar2 = local_78;
    if (iVar5 == 0) {
      if (local_78 == 0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      local_78 = *(longlong *)(lVar2 + 0x18);
      if (local_78 == 0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      lVar2 = *(longlong *)(lVar2 + 0x30);
      local_70 = lVar2;
      if (lVar2 == 0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      uVar6 = FseCoreRemovePhysicalToVirtualNicPairing
                        (DAT_14002a7a8,plVar1[1],*plVar1,(ulonglong)*(uint *)(lVar2 + 0x1c));
      iVar5 = (int)uVar6;
      if (iVar5 == 0) {
        FseFreeMemory(&local_78);
        FseFreeMemory(&local_70);
        return 0;
      }
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar4 = false;
        }
        else {
          bVar4 = true;
        }
        if (bVar4) {
          local_48 = "L\"FseCoreRemovePhysicalToVirtualNicPairing\" failed.";
          local_40 = 0x34;
          pbVar7 = &DAT_140024320;
          goto LAB_14000234e;
        }
      }
    }
    else if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if (bVar4) {
        local_48 = "L\"FseCoreFindNicPairEntryByVirtualNicId\" failed.";
        local_40 = 0x31;
        pbVar7 = &DAT_140024352;
LAB_14000234e:
        local_3c = 0;
        local_2c = 0;
        local_38 = &local_78;
        local_78 = CONCAT44(local_78._4_4_,iVar5);
        local_30 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar7,0,0,4,local_68);
      }
    }
    if (-1 < iVar5) goto LAB_1400023ad;
  }
  FseDiagnosticsLogFailure(4,iVar5);
  if (iVar5 == 0) {
    return 0;
  }
LAB_1400023ad:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_3c = 0;
      local_2c = 0;
      local_48 = "FseDriverDeleteNicPairIoctl returned error";
      local_38 = &local_78;
      local_40 = 0x2b;
      local_78 = CONCAT44(local_78._4_4_,iVar5);
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400242ea,0,0,4,local_68);
    }
  }
  return iVar5;
}



===== FseDriverDeletePartitionIoctl @ 14000246c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseDriverDeletePartitionIoctl
              (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  byte *pbVar5;
  undefined1 auStackY_b8 [32];
  int local_88 [4];
  undefined8 local_78 [4];
  char *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  bVar2 = true;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x18) {
    iVar3 = -0x3ffffff3;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_50 = 0x29;
        local_58 = "L\"FseDriverDeletePartitionIoctl\" failed.";
        local_48 = local_88;
        local_88[0] = -0x3ffffff3;
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024718,0,0,4,local_78);
      }
    }
  }
  else {
    pbVar5 = *(byte **)(param_1 + 0x18);
    if ((pbVar5[0x14] == 0) ||
       (iVar3 = PtServerStopPartition(pbVar5,param_2,param_3,param_4), iVar3 == 0)) {
      uVar4 = FsePortTrackerReleasePartitionPorts((longlong *)pbVar5);
      iVar3 = (int)uVar4;
      if (iVar3 == 0) {
        uVar4 = FsePortTrackerReleasePartitionPorts((longlong *)pbVar5);
        iVar3 = (int)uVar4;
        if (iVar3 == 0) {
          FsePortPolicyRemoveForPartition((longlong *)pbVar5);
          uVar4 = FseAllocatorNotifyDestroyPartition((longlong *)pbVar5);
          iVar3 = (int)uVar4;
          if (iVar3 == 0) {
            return 0;
          }
          if (2 < DAT_14002a000) {
            if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018))
            {
              bVar1 = false;
            }
            if (bVar1) {
              local_58 = "L\"FseAllocatorNotifyDestroyPartition\" failed.";
              local_50 = 0x2e;
              pbVar5 = &DAT_140024650;
              goto LAB_1400026c4;
            }
          }
        }
        else if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar1 = false;
          }
          if (bVar1) {
            local_58 = "L\"FsePortTrackerReleasePartitionPorts\" failed.";
            local_50 = 0x2f;
            pbVar5 = &DAT_140024682;
LAB_1400026c4:
            local_48 = local_88;
            local_40 = 4;
            local_88[0] = iVar3;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar5,0,0,4,local_78);
          }
        }
      }
      else if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar1 = false;
        }
        if (bVar1) {
          local_58 = "L\"FsePortTrackerReleasePartitionPorts\" failed.";
          local_50 = 0x2f;
          pbVar5 = &DAT_1400246b4;
          goto LAB_1400026c4;
        }
      }
    }
    else if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_58 = "L\"PtServerStopPartition\" failed.";
        local_50 = 0x21;
        pbVar5 = &DAT_1400246e6;
        goto LAB_1400026c4;
      }
    }
    if (-1 < iVar3) goto LAB_140002710;
  }
  FseDiagnosticsLogFailure(1,iVar3);
LAB_140002710:
  if ((iVar3 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_50 = 0x2d;
      local_58 = "FseDriverDeletePartitionIoctl returned error";
      local_48 = local_88;
      local_40 = 4;
      local_88[0] = iVar3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002461a,0,0,4,local_78);
    }
  }
  return iVar3;
}



===== FseDriverDispatch @ 1400027b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FseDriverDispatch(undefined8 param_1,longlong param_2)

{
  bool bVar1;
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000002;
  IofCompleteRequest(param_2,0);
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_2c = 0;
      local_28 = local_68;
      local_1c = 0;
      local_38 = "FseDriverDispatch returned error";
      local_30 = 0x21;
      local_68[0] = 0xc0000002;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023c6b,0,0,4,local_58);
    }
  }
  return 0xc0000002;
}



===== FseDriverDispatchCleanup @ 1400028a0 =====

undefined8 FseDriverDispatchCleanup(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== FseDriverDispatchClose @ 1400028d0 =====

undefined8 FseDriverDispatchClose(undefined8 param_1,undefined8 param_2)

{
  IofCompleteRequest(param_2,0);
  return 0;
}



===== FseDriverDispatchDevControl @ 140002900 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FseDriverDispatchDevControl
               (undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined1 auStackY_a8 [32];
  uint local_78 [4];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  *(undefined8 *)(param_2 + 0x38) = 0;
  lVar7 = param_2;
  cVar3 = ExAcquireRundownProtection(&DAT_14002a7d0);
  bVar1 = true;
  if (cVar3 == '\0') {
    uVar4 = 0xc00000a3;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000a3;
    IofCompleteRequest(param_2,0);
    if (DAT_14002a000 < 3) {
      return 0xc00000a3;
    }
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_3c = 0;
      local_2c = 0;
      local_48 = "FSE Driver not ready";
      local_38 = local_78;
      local_40 = 0x15;
      local_78[0] = 0xc00000a3;
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023b97,0,0,4,local_68);
      uVar4 = 0xc00000a3;
    }
    goto LAB_140002b49;
  }
  uVar4 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (uVar4 < 0x12c00d) {
    if (uVar4 == 0x12c00c) {
      uVar4 = FseDriverCreateNicPairIoctl(param_2);
    }
    else if (uVar4 == 0x124008) {
      uVar4 = FseDriverQueryPartitionsIoctl(param_2);
    }
    else if (uVar4 == 0x124014) {
      uVar4 = FseDriverQueryNicPairsIoctl(param_2);
    }
    else if (uVar4 == 0x124024) {
      uVar4 = FseDriverQueryAppliedPortPolicy(param_2);
    }
    else if (uVar4 == 0x124030) {
      uVar5 = FseReleasePortIoctl(param_2,lVar7,param_3);
      uVar4 = (uint)uVar5;
    }
    else if (uVar4 == 0x124034) {
      uVar6 = FseEnumeratePortAllocations(param_2);
      uVar4 = (uint)uVar6;
    }
    else if (uVar4 == 0x12c000) {
      uVar5 = FseDriverCreatePartitionIoctl(param_2,lVar7,param_3,param_4);
      uVar4 = (uint)uVar5;
    }
    else {
      if (uVar4 != 0x12c004) goto LAB_140002acb;
      uVar4 = FseDriverDeletePartitionIoctl(param_2,lVar7,param_3,param_4);
    }
  }
  else if (uVar4 == 0x12c010) {
    uVar4 = FseDriverDeleteNicPairIoctl(param_2);
  }
  else if (uVar4 == 0x12c018) {
    uVar4 = FseDriverAddHostVnicIoctl(param_2);
  }
  else if (uVar4 == 0x12c01c) {
    FseIpsClientRemoveHostVnic();
    uVar4 = 0;
  }
  else if (uVar4 == 0x12c020) {
    uVar4 = FseDriverConfigurePortPolicy(param_2);
  }
  else if (uVar4 == 0x12c028) {
    uVar5 = FseDriverResumePartitionIoctl(param_2);
    uVar4 = (uint)uVar5;
  }
  else if (uVar4 == 0x12c02c) {
    uVar4 = FseReservePortIoctl(param_2);
  }
  else if (uVar4 == 0x12c038) {
    uVar4 = FseSetPartitionLoopbackAllowedIoctl(param_2);
  }
  else {
LAB_140002acb:
    uVar4 = 0xc00000bb;
  }
  *(uint *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  ExReleaseRundownProtection(&DAT_14002a7d0);
  if (uVar4 == 0) {
    return 0;
  }
LAB_140002b49:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_3c = 0;
      local_2c = 0;
      local_48 = "FseDriverDispatchDevControl returned error";
      local_38 = local_78;
      local_40 = 0x2b;
      local_30 = 4;
      local_78[0] = uVar4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023b61,0,0,4,local_68);
    }
  }
  return uVar4;
}



===== FseDriverQueryAppliedPortPolicy @ 140002bec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseDriverQueryAppliedPortPolicy(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined2 *_Dst;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined1 auStackY_a8 [32];
  ulonglong local_78 [2];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  bVar3 = true;
  uVar1 = *(uint *)(lVar2 + 8);
  if (uVar1 < 2) {
    iVar5 = -0x3ffffff3;
    if (DAT_14002a000 < 3) {
      return -0x3ffffff3;
    }
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (bVar4) {
      local_3c = 0;
      local_2c = 0;
      local_48 = "FseDriverQueryAppliedPortPolicyInsufficient Output Buffer";
      local_38 = local_78;
      local_40 = 0x3a;
      local_78[0] = CONCAT44(local_78[0]._4_4_,0xc000000d);
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002484c,0,0,4,local_68);
    }
  }
  else {
    _Dst = *(undefined2 **)(param_1 + 0x18);
    memset(_Dst,0,(ulonglong)uVar1);
    local_78[0] = (ulonglong)(*(int *)(lVar2 + 8) - 2);
    iVar5 = FsePortPolicyEnum(_Dst,local_78,_Dst + 1);
    if (iVar5 == 0) {
      *(ulonglong *)(param_1 + 0x38) = local_78[0] + 2;
      return 0;
    }
    if (iVar5 == -0x7ffffffb) {
      *(undefined8 *)(param_1 + 0x38) = 2;
    }
  }
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_3c = 0;
      local_2c = 0;
      local_48 = "FseDriverQueryAppliedPortPolicy returned error";
      local_38 = local_78;
      local_40 = 0x2f;
      local_78[0] = CONCAT44(local_78[0]._4_4_,iVar5);
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024816,0,0,4,local_68);
    }
  }
  return iVar5;
}



===== FseDriverQueryNicPairsIoctl @ 140002dcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseDriverQueryNicPairsIoctl(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ushort *puVar3;
  bool bVar4;
  bool bVar5;
  void *pvVar6;
  ushort uVar7;
  int iVar8;
  undefined8 uVar9;
  byte *pbVar10;
  ushort uVar11;
  ulonglong uVar12;
  undefined1 auStackY_b8 [32];
  ulonglong local_88;
  void *local_80;
  undefined8 local_78 [4];
  char *local_58;
  undefined8 local_50;
  ulonglong *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  local_80 = (void *)0x0;
  local_88 = 0;
  bVar5 = true;
  uVar1 = *(uint *)(lVar2 + 8);
  if (uVar1 < 8) {
    iVar8 = -0x3ffffff3;
    if (DAT_14002a000 < 3) {
      return -0x3ffffff3;
    }
    if (((DAT_14002a010 & 4) == 0) || (bVar4 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar4 = false;
    }
    if (!bVar4) goto LAB_14000314c;
    local_58 = "L\"FseDriverQueryNicPairsIoctl\" failed.";
    local_50 = 0x27;
    pbVar10 = &DAT_1400242b8;
LAB_140002e7a:
    local_88 = CONCAT44(local_88._4_4_,iVar8);
  }
  else {
    memset(*(void **)(param_1 + 0x18),0,(ulonglong)uVar1);
    puVar3 = *(ushort **)(param_1 + 0x18);
    iVar8 = FseCoreListAllNicPairEntries(DAT_14002a7a8,puVar3,&local_88,(void *)0x0);
    if ((iVar8 != -0x7ffffffb) && (iVar8 != 0)) {
      if (DAT_14002a000 < 3) {
        return iVar8;
      }
      if (((DAT_14002a010 & 4) == 0) || (bVar4 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar4 = false;
      }
      if (!bVar4) goto LAB_14000314c;
      local_58 = "L\"FseCoreListAllNicPairEntries\" failed.";
      local_50 = 0x28;
      pbVar10 = &DAT_140024286;
      goto LAB_140002e7a;
    }
    if (*puVar3 == 0) {
      *(undefined8 *)(param_1 + 0x38) = 8;
      return 0;
    }
    if ((uint)*puVar3 * 0x40 + 8 <= *(uint *)(lVar2 + 8)) {
      uVar9 = FseAllocMemory(local_88,0x43447346,&local_80);
      pvVar6 = local_80;
      iVar8 = (int)uVar9;
      if (iVar8 == 0) {
        iVar8 = FseCoreListAllNicPairEntries(DAT_14002a7a8,puVar3,&local_88,local_80);
        if (iVar8 == 0) {
          uVar7 = 0;
          uVar12 = 0;
          if (*puVar3 != 0) {
            do {
              uVar11 = (short)uVar12 + 1;
              lVar2 = *(longlong *)((longlong)pvVar6 + uVar12 * 0x48 + 0x20);
              *(undefined8 *)(puVar3 + uVar12 * 0x20 + 4) =
                   *(undefined8 *)((longlong)pvVar6 + uVar12 * 0x48);
              *(undefined8 *)(puVar3 + uVar12 * 0x20 + 8) =
                   *(undefined8 *)((longlong)pvVar6 + uVar12 * 0x48 + 0x18);
              *(undefined4 *)(puVar3 + uVar12 * 0x20 + 0x1a) =
                   *(undefined4 *)((longlong)pvVar6 + uVar12 * 0x48 + 0x30);
              uVar9 = *(undefined8 *)(lVar2 + 0x14);
              *(undefined8 *)(puVar3 + uVar12 * 0x20 + 0x12) = *(undefined8 *)(lVar2 + 0xc);
              *(undefined8 *)(puVar3 + uVar12 * 0x20 + 0x12 + 4) = uVar9;
              uVar7 = *puVar3;
              uVar12 = (ulonglong)uVar11;
            } while (uVar11 < uVar7);
          }
          *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar7 * 0x40 + 8;
        }
        else if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || (bVar4 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar4 = false;
          }
          if (bVar4) {
            local_58 = "L\"FseCoreListAllNicPairEntries\" failed.";
            local_50 = 0x28;
            pbVar10 = &DAT_1400241f0;
            goto LAB_140003034;
          }
        }
      }
      else if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || (bVar4 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar4 = false;
        }
        if (bVar4) {
          local_58 = "L\"FseAllocMemory\" failed.";
          local_50 = 0x1a;
          pbVar10 = &DAT_140024222;
LAB_140003034:
          local_48 = &local_88;
          local_40 = 4;
          local_88 = CONCAT44(local_88._4_4_,iVar8);
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar10,0,0,4,local_78);
        }
      }
      if (pvVar6 != (void *)0x0) {
        FseFreeMemory((longlong *)&local_80);
      }
      if (iVar8 == 0) {
        return 0;
      }
      goto LAB_14000314c;
    }
    *(undefined8 *)(param_1 + 0x38) = 8;
    iVar8 = -0x7ffffffb;
    if (DAT_14002a000 < 3) {
      return -0x7ffffffb;
    }
    if (((DAT_14002a010 & 4) == 0) || (bVar4 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar4 = false;
    }
    if (!bVar4) goto LAB_14000314c;
    local_88 = CONCAT44(local_88._4_4_,0x80000005);
    local_58 = "L\"FseDriverQueryNicPairsIoctl\" failed.";
    pbVar10 = &DAT_140024254;
    local_50 = 0x27;
  }
  local_48 = &local_88;
  local_40 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar10,0,0,4,local_78);
LAB_14000314c:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar5 = false;
    }
    if (bVar5) {
      local_50 = 0x2b;
      local_58 = "FseDriverQueryNicPairsIoctl returned error";
      local_48 = &local_88;
      local_88 = CONCAT44(local_88._4_4_,iVar8);
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400241ba,0,0,4,local_78);
    }
  }
  return iVar8;
}



===== FseDriverQueryPartitionsIoctl @ 1400031f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseDriverQueryPartitionsIoctl(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined2 *puVar3;
  undefined8 uVar4;
  bool bVar5;
  bool bVar6;
  ulonglong uVar7;
  int iVar8;
  undefined8 uVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined2 uVar12;
  size_t _Size;
  ulonglong uVar13;
  undefined8 *_Dst;
  undefined1 auStackY_b8 [32];
  ulonglong local_88;
  byte *local_80;
  undefined8 local_78 [4];
  char *local_58;
  undefined8 local_50;
  ulonglong *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  local_80 = (byte *)0x0;
  local_88 = 0;
  uVar1 = *(uint *)(lVar2 + 8);
  bVar6 = true;
  if (uVar1 < 8) {
    iVar8 = -0x3ffffff3;
    if (DAT_14002a000 < 3) {
      return -0x3ffffff3;
    }
    if (((DAT_14002a010 & 4) == 0) || (bVar5 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar5 = false;
    }
    if (!bVar5) goto LAB_14000355e;
    local_88 = 0xc000000d;
    pbVar10 = &DAT_14002454e;
  }
  else {
    memset(*(void **)(param_1 + 0x18),0,(ulonglong)uVar1);
    puVar3 = *(undefined2 **)(param_1 + 0x18);
    puVar3[1] = 0x40;
    FseAllocatorQueryPartitions(0,0,&local_88);
    uVar13 = local_88;
    if (local_88 == 0) {
      *puVar3 = 0;
      *(undefined8 *)(param_1 + 0x38) = 8;
      return 0;
    }
    if (local_88 * 0x40 + 8 <= (ulonglong)*(uint *)(lVar2 + 8)) {
      _Size = local_88 << 4;
      uVar9 = FseAllocMemory(_Size,0x43447346,&local_80);
      pbVar10 = local_80;
      iVar8 = (int)uVar9;
      if (iVar8 == 0) {
        memset(local_80,0,_Size);
        FseAllocatorQueryPartitions(uVar13,(longlong)pbVar10,&local_88);
        uVar7 = local_88;
        uVar12 = (undefined2)local_88;
        if (uVar13 < local_88) {
          *puVar3 = uVar12;
          *(undefined8 *)(param_1 + 0x38) = 8;
          iVar8 = -0x7ffffffb;
          if (2 < DAT_14002a000) {
            if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
              bVar5 = false;
            }
            else {
              bVar5 = true;
            }
            if (bVar5) {
              local_58 = "L\"FseDriverQueryPartitionIoctl\" failed.";
              local_50 = 0x28;
              local_88 = CONCAT44(local_88._4_4_,0x80000005);
              pbVar11 = &DAT_1400244b8;
              goto LAB_140003409;
            }
          }
        }
        else {
          if ((int)local_88 != 0) {
            _Dst = (undefined8 *)(puVar3 + 4);
            uVar13 = local_88 & 0xffffffff;
            do {
              uVar9 = PtServerGetStatisticsForPartition(pbVar10,(undefined4 *)_Dst);
              local_88 = CONCAT44(local_88._4_4_,(int)uVar9);
              if ((int)uVar9 != 0) {
                memset(_Dst,0,0x40);
                uVar9 = *(undefined8 *)pbVar10;
                uVar4 = *(undefined8 *)(pbVar10 + 8);
                *(undefined4 *)(_Dst + 2) = 5;
                *_Dst = uVar9;
                _Dst[1] = uVar4;
                *(undefined4 *)((longlong)_Dst + 0x14) = (undefined4)local_88;
              }
              pbVar10 = pbVar10 + 0x10;
              _Dst = _Dst + 8;
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
            pbVar10 = local_80;
          }
          *puVar3 = uVar12;
          *(ulonglong *)(param_1 + 0x38) = uVar7 * 0x40 + 8;
          iVar8 = 0;
        }
      }
      else if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar5 = false;
        }
        else {
          bVar5 = true;
        }
        if (bVar5) {
          local_58 = "L\"FseAllocMemory\" failed.";
          local_50 = 0x1a;
          local_88 = CONCAT44(local_88._4_4_,iVar8);
          pbVar11 = &DAT_1400244ea;
LAB_140003409:
          local_48 = &local_88;
          local_40 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar11,0,0,4,local_78);
        }
      }
      if (pbVar10 != (byte *)0x0) {
        FseFreeMemory((longlong *)&local_80);
      }
      if (iVar8 == 0) {
        return 0;
      }
      goto LAB_14000355e;
    }
    *puVar3 = (short)local_88;
    *(undefined8 *)(param_1 + 0x38) = 8;
    iVar8 = -0x7ffffffb;
    if (DAT_14002a000 < 3) {
      return -0x7ffffffb;
    }
    if (((DAT_14002a010 & 4) == 0) || (bVar5 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar5 = false;
    }
    if (!bVar5) goto LAB_14000355e;
    local_88 = CONCAT44(local_88._4_4_,0x80000005);
    pbVar10 = &DAT_14002451c;
  }
  local_40 = 4;
  local_58 = "L\"FseDriverQueryPartitionIoctl\" failed.";
  local_48 = &local_88;
  local_50 = 0x28;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar10,0,0,4,local_78);
LAB_14000355e:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar6 = false;
    }
    if (bVar6) {
      local_50 = 0x2d;
      local_58 = "FseDriverQueryPartitionsIoctl returned error";
      local_48 = &local_88;
      local_88 = CONCAT44(local_88._4_4_,iVar8);
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024482,0,0,4,local_78);
    }
  }
  return iVar8;
}



===== FseDriverResumePartitionIoctl @ 140003614 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseDriverResumePartitionIoctl(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStackY_98 [32];
  int local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar1 = true;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x18) {
    uVar4 = 0xc000000d;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_2c = 0;
        local_1c = 0;
        local_38 = "L\"FseDriverResumePartitionIoctl\" failed.";
        local_28 = local_68;
        local_30 = 0x29;
        local_68[0] = -0x3ffffff3;
        local_20 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400245e8,0,0,4,local_58);
      }
    }
  }
  else {
    uVar4 = PtServerResumePartition(*(byte **)(param_1 + 0x18));
    iVar3 = (int)uVar4;
    uVar4 = uVar4 & 0xffffffff;
    if (iVar3 == 0) {
      return uVar4;
    }
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_2c = 0;
        local_1c = 0;
        local_38 = "L\"FseDriverResumePartitionIoctl: PtServerResumePartition\" failed.";
        local_28 = local_68;
        local_30 = 0x42;
        local_20 = 4;
        local_68[0] = iVar3;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400245b6,0,0,4,local_58);
      }
    }
    if (-1 < iVar3) goto LAB_14000379d;
  }
  FseDiagnosticsLogFailure(2,(int)uVar4);
  if ((int)uVar4 == 0) {
    return uVar4;
  }
LAB_14000379d:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseDriverResumePartitionIoctl returned error";
      local_28 = local_68;
      local_30 = 0x2d;
      local_68[0] = (int)uVar4;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024580,0,0,4,local_58);
    }
  }
  return uVar4;
}



===== FseEnumeratePortAllocations @ 140003840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FseEnumeratePortAllocations(longlong param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  ulonglong uVar5;
  ulonglong _Size;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined4 *local_98;
  undefined8 uStack_90;
  undefined8 local_88 [4];
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  *(undefined8 *)(param_1 + 0x38) = 0;
  local_98 = (undefined4 *)0x0;
  uStack_90 = 0;
  bVar2 = true;
  if (*(int *)(*(longlong *)(param_1 + 0xb8) + 0x10) == 4) {
    uVar1 = **(uint **)(param_1 + 0x18);
    if (uVar1 == 0) {
      uVar5 = 0x48;
    }
    else {
      uVar5 = (ulonglong)uVar1 * 0x40 + 8;
    }
    _Size = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
    if (uVar5 <= _Size) {
      memset(*(uint **)(param_1 + 0x18),0,_Size);
      local_98 = *(undefined4 **)(param_1 + 0x18);
      local_98[1] = uVar1;
      uStack_90._0_4_ = 6;
      FsePortPoolEnumReservations(g_TcpPool,FseAllocatorSerializeEnumeratePortAllocations,&local_98)
      ;
      uStack_90._0_4_ = 0x11;
      FsePortPoolEnumReservations(g_UdpPool,FseAllocatorSerializeEnumeratePortAllocations,&local_98)
      ;
      if (4 < DAT_14002a000) {
        local_a8 = *local_98;
        local_5c = 0;
        local_68 = (char *)&local_a8;
        local_60 = 4;
        local_a4 = local_98[1];
        local_4c = 0;
        local_3c = 0;
        local_58 = &local_a4;
        local_a0[0] = uStack_90._4_4_;
        local_48 = local_a0;
        local_50 = 4;
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023d71,0,0,5,local_88);
      }
      *(ulonglong *)(param_1 + 0x38) = uVar5;
      return 0;
    }
    if (DAT_14002a000 < 3) goto LAB_14000399f;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (!bVar3) goto LAB_14000399f;
    local_68 = "L\"FseEnumeratePortAllocations [OutputBufferLength]\" failed.";
    local_60 = 0x3c;
    pbVar4 = &DAT_140023dde;
  }
  else {
    if (DAT_14002a000 < 3) goto LAB_14000399f;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (!bVar3) goto LAB_14000399f;
    local_68 = "L\"FseEnumeratePortAllocations [InputBufferLength]\" failed.";
    local_60 = 0x3b;
    pbVar4 = &DAT_140023e10;
  }
  local_5c = 0;
  local_4c = 0;
  local_58 = &local_a8;
  local_a8 = 0xc000000d;
  local_50 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar4,0,0,4,local_88);
LAB_14000399f:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_5c = 0;
      local_4c = 0;
      local_68 = "FseEnumeratePortAllocations returned error";
      local_58 = &local_a8;
      local_60 = 0x2b;
      local_a8 = 0xc000000d;
      local_50 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023d3b,0,0,4,local_88);
    }
  }
  return 0xc000000d;
}



===== FseReleasePortIoctl @ 140003b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseReleasePortIoctl(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  bool bVar2;
  ulonglong uVar3;
  byte *pbVar4;
  undefined1 auStackY_98 [32];
  int local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar1 = true;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x18) {
    uVar3 = 0xc000000d;
    if (DAT_14002a000 < 3) goto LAB_140003cb4;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) goto LAB_140003cb4;
    local_38 = "L\"FseReleasePortIoctl [InputBufferLength]\" failed.";
    local_30 = 0x33;
    local_68[0] = -0x3ffffff3;
    pbVar4 = &DAT_140023edc;
  }
  else {
    uVar3 = (*(longlong **)(param_1 + 0x18))[2];
    if (uVar3 == 0) {
      uVar3 = 0xc000000d;
      if (DAT_14002a000 < 3) goto LAB_140003cb4;
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) goto LAB_140003cb4;
      local_38 = "L\"FseReleasePortIoctl [Token]\" failed.";
      local_30 = 0x27;
      local_68[0] = -0x3ffffff3;
      pbVar4 = &DAT_140023eaa;
    }
    else {
      uVar3 = FsePortTrackerReleasePortRange(*(longlong **)(param_1 + 0x18),uVar3,param_3);
      local_68[0] = (int)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (local_68[0] == 0) {
        return uVar3;
      }
      if (DAT_14002a000 < 3) goto LAB_140003cb4;
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) goto LAB_140003cb4;
      local_38 = "L\"FseReleasePortIoctl [FsePortTrackerReleasePortRange]\" failed.";
      local_30 = 0x40;
      pbVar4 = &DAT_140023e78;
    }
  }
  local_2c = 0;
  local_1c = 0;
  local_28 = local_68;
  local_20 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar4,0,0,4,local_58);
LAB_140003cb4:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseReleasePortIoctl returned error";
      local_28 = local_68;
      local_30 = 0x23;
      local_68[0] = (int)uVar3;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023e42,0,0,4,local_58);
    }
  }
  return uVar3;
}



===== FseReservePortIoctl @ 140003d58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseReservePortIoctl(longlong param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  ulonglong uVar4;
  byte *pbVar5;
  int iVar6;
  longlong *plVar7;
  undefined1 auStackY_198 [32];
  int local_168;
  int local_164;
  undefined2 local_160 [2];
  uint local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150 [2];
  ulonglong local_148;
  uint local_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined8 uStack_128;
  undefined4 local_120;
  undefined8 local_118 [4];
  char *local_f8;
  undefined8 local_f0;
  int *local_e8;
  undefined8 local_e0;
  undefined8 local_d8 [4];
  uint *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined2 *local_88;
  undefined8 local_80;
  int *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_198;
  local_148 = 0;
  local_120 = 0;
  local_140 = 0;
  uStack_13c = 0;
  uStack_138 = 0;
  uStack_134 = 0;
  bVar3 = true;
  local_130 = 0;
  uStack_12c = 0;
  uStack_128 = 0;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x1c) {
    iVar6 = -0x3ffffff3;
    if (DAT_14002a000 < 3) goto LAB_1400041cf;
    if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (!bVar2) goto LAB_1400041cf;
    local_168 = -0x3ffffff3;
    local_f8 = "L\"FseReservePortIoctl [InputBufferLength]\" failed.";
    pbVar5 = &DAT_1400240ee;
    local_e8 = &local_168;
    local_f0 = 0x33;
    iVar6 = -0x3ffffff3;
  }
  else if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 8) < 8) {
    iVar6 = -0x3ffffff3;
    if (DAT_14002a000 < 3) goto LAB_1400041cf;
    if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (!bVar2) goto LAB_1400041cf;
    local_168 = -0x3ffffff3;
    local_f8 = "L\"FseReservePortIoctl [OutputBufferLength]\" failed.";
    pbVar5 = &DAT_1400240bc;
    local_e8 = &local_168;
    local_f0 = 0x34;
    iVar6 = -0x3ffffff3;
  }
  else {
    plVar7 = *(longlong **)(param_1 + 0x18);
    if (((int)plVar7[2] == 6) || ((int)plVar7[2] == 0x11)) {
      uVar1 = *(uint *)((longlong)plVar7 + 0x14);
      if ((uVar1 - 4 & 0xfffffffb) == 0) {
        if (*(ushort *)((longlong)plVar7 + 0x1a) < *(ushort *)(plVar7 + 3)) {
          iVar6 = -0x3ffffff3;
          if (DAT_14002a000 < 3) goto LAB_1400041cf;
          if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar2 = false;
          }
          if (!bVar2) goto LAB_1400041cf;
          local_168 = -0x3ffffff3;
          local_f8 = "L\"FseReservePortIoctl [Port]\" failed.";
          pbVar5 = &DAT_140024026;
          local_e8 = &local_168;
          local_f0 = 0x26;
          iVar6 = -0x3ffffff3;
        }
        else {
          uStack_13c = (undefined4)*plVar7;
          uStack_138 = (undefined4)((ulonglong)*plVar7 >> 0x20);
          uStack_134 = (undefined4)plVar7[1];
          local_130 = (undefined4)((ulonglong)plVar7[1] >> 0x20);
          uStack_12c = (undefined4)plVar7[2];
          uStack_128 = CONCAT44(1,(int)plVar7[3]);
          local_140 = uVar1;
          local_120 = FsePortTrackerGetDefaultSharingFlags(uVar1);
          uVar4 = FsePortTrackerAcquirePorts(plVar7,&local_140,1,plVar7,&local_148,(ushort *)0x0);
          iVar6 = (int)uVar4;
          if (5 < DAT_14002a000) {
            if (((DAT_14002a010 & 2) == 0) ||
               (bVar2 = true, ((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
              bVar2 = false;
            }
            if (bVar2) {
              local_15c = local_140;
              local_b8 = &local_15c;
              local_b0 = 4;
              local_a8 = &uStack_13c;
              local_a0 = 0x10;
              local_158 = uStack_12c;
              local_98 = &local_158;
              local_160[0] = (undefined2)uStack_128;
              local_88 = local_160;
              local_168 = CONCAT22(local_168._2_2_,uStack_128._2_2_);
              local_78 = &local_168;
              local_154 = uStack_128._4_4_;
              local_68 = &local_154;
              local_150[0] = local_120;
              local_58 = local_150;
              local_48 = &local_164;
              local_90 = 4;
              local_80 = 2;
              local_70 = 2;
              local_60 = 4;
              local_50 = 4;
              local_40 = 4;
              local_164 = iVar6;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023f76,0,0,10,local_d8);
            }
          }
          if ((iVar6 == 0) || (DAT_14002a000 < 3)) goto LAB_1400041cf;
          if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar2 = false;
          }
          if (!bVar2) goto LAB_1400041cf;
          local_f0 = 0x3c;
          local_f8 = "L\"FseReservePortIoctl [FsePortTrackerAcquirePorts]\" failed.";
          pbVar5 = &DAT_140023f44;
          local_e8 = &local_164;
          local_164 = iVar6;
        }
      }
      else {
        iVar6 = -0x3ffffff3;
        if (DAT_14002a000 < 3) goto LAB_1400041cf;
        if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar2 = false;
        }
        if (!bVar2) goto LAB_1400041cf;
        local_168 = -0x3ffffff3;
        local_f8 = "L\"FseReservePortIoctl [Access]\" failed.";
        pbVar5 = &DAT_140024058;
        local_e8 = &local_168;
        local_f0 = 0x28;
        iVar6 = -0x3ffffff3;
      }
    }
    else {
      iVar6 = -0x3ffffff3;
      if (DAT_14002a000 < 3) goto LAB_1400041cf;
      if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      if (!bVar2) goto LAB_1400041cf;
      local_168 = -0x3ffffff3;
      local_f8 = "L\"FseReservePortIoctl [IpProto]\" failed.";
      pbVar5 = &DAT_14002408a;
      local_e8 = &local_168;
      local_f0 = 0x29;
      iVar6 = -0x3ffffff3;
    }
  }
  local_e0 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar5,0,0,4,local_118);
LAB_1400041cf:
  **(ulonglong **)(param_1 + 0x18) = local_148;
  *(undefined8 *)(param_1 + 0x38) = 8;
  if ((iVar6 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_f0 = 0x23;
      local_f8 = "FseReservePortIoctl returned error";
      local_e8 = &local_164;
      local_e0 = 4;
      local_164 = iVar6;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023f0e,0,0,4,local_118);
    }
  }
  return iVar6;
}



===== FseSetDeviceDacl @ 14000428c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseSetDeviceDacl(undefined8 param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStackY_148 [32];
  int local_118 [4];
  undefined8 local_108 [4];
  char *local_e8;
  undefined8 local_e0;
  int *local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_148;
  local_c8 = 0x90040001;
  local_c4 = 0x84;
  bVar2 = true;
  local_c0 = 0x94;
  local_b8 = 0x14;
  local_b4 = 0x700002;
  local_b0 = 3;
  local_ac = 0x280000;
  local_a8 = 0x12019f;
  local_a4 = 0x601;
  local_a0 = 0x5000000;
  local_9c = 0x50;
  local_98 = 0x3b1c6430;
  local_94 = 0x314956c8;
  local_90 = 0xb891681;
  local_8c = 0x4fbd810;
  local_88 = 0xd3ed4e8;
  local_84 = 0x180000;
  local_80 = 0x12019f;
  local_7c = 0x201;
  local_78 = 0x5000000;
  local_74 = 0x20;
  local_70 = 0x220;
  local_6c = 0x280000;
  local_68 = 0x12019f;
  local_64 = 0x601;
  local_60 = 0x5000000;
  local_5c = 0x50;
  local_58 = 0xb81041f1;
  local_54 = 0x574dfc36;
  local_50 = 0x700baea8;
  local_4c = 0x42042125;
  local_48 = 0x31114f84;
  local_44 = 0x201;
  local_40 = 0x5000000;
  local_3c = 0x20;
  local_38 = 0x220;
  local_34 = 0x101;
  local_30 = 0x5000000;
  local_2c = 0x12;
  iVar3 = ObSetSecurityObjectByPointer(param_1,4,&local_c8);
  if (iVar3 != 0) {
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_e0 = 0x28;
        local_e8 = "L\"ObSetSecurityObjectByPointer\" failed.";
        local_d8 = local_118;
        local_d0 = 4;
        local_118[0] = iVar3;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023b2f,0,0,4,local_108);
      }
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar2 = false;
        }
        if (bVar2) {
          local_e0 = 0x20;
          local_e8 = "FseSetDeviceDacl returned error";
          local_d8 = local_118;
          local_d0 = 4;
          local_118[0] = iVar3;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023af9,0,0,4,local_108);
        }
      }
    }
  }
  return iVar3;
}



===== FseSetPartitionLoopbackAllowedIoctl @ 14000451c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseSetPartitionLoopbackAllowedIoctl(longlong param_1)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  int iVar7;
  undefined1 auStackY_a8 [32];
  int local_78 [4];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar2 = true;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10) < 0x14) {
    iVar7 = -0x3ffffff3;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_3c = 0;
        local_2c = 0;
        local_48 = "L\"FseDriverCreatePartitionIoctl\" failed.";
        local_38 = local_78;
        local_40 = 0x29;
        local_78[0] = -0x3ffffff3;
        local_30 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023d09,0,0,4,local_68);
      }
    }
  }
  else {
    plVar1 = *(longlong **)(param_1 + 0x18);
    iVar7 = -0x3ffffddb;
    lVar4 = plVar1[2];
    uVar5 = ExAcquireSpinLockExclusive(&DAT_14002a6a0);
    for (puVar6 = DAT_14002a610; (undefined8 **)puVar6 != &DAT_14002a610;
        puVar6 = (undefined8 *)*puVar6) {
      if ((puVar6[2] == *plVar1) && (puVar6[3] == plVar1[1])) {
        iVar7 = 0;
        *(char *)(puVar6 + 6) = (char)lVar4;
        break;
      }
    }
    ExReleaseSpinLockExclusive(&DAT_14002a6a0,uVar5);
    if (iVar7 == 0) {
      return 0;
    }
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_3c = 0;
        local_2c = 0;
        local_48 = "L\"FseSetPartitionLoopbackAllowed [FsePartitionSetIsLoopbackAllowed]\" failed.";
        local_38 = local_78;
        local_40 = 0x4d;
        local_30 = 4;
        local_78[0] = iVar7;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023cd7,0,0,4,local_68);
      }
    }
    if (-1 < iVar7) goto LAB_140004706;
  }
  FseDiagnosticsLogFailure(0xf,iVar7);
  if (iVar7 == 0) {
    return 0;
  }
LAB_140004706:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_3c = 0;
      local_2c = 0;
      local_48 = "FseSetPartitionLoopbackAllowedIoctl returned error";
      local_38 = local_78;
      local_40 = 0x33;
      local_30 = 4;
      local_78[0] = iVar7;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140023ca1,0,0,4,local_68);
    }
  }
  return iVar7;
}



===== DriverEntry @ 1400047b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint DriverEntry(undefined8 *param_1,undefined8 param_2,undefined8 *param_3,ulonglong param_4)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  code *pcVar8;
  undefined1 auStackY_138 [32];
  uint local_108;
  uint local_104;
  int local_100 [2];
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 *puStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8 [4];
  char *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  undefined8 local_78 [4];
  char *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  param_1[0xd] = FseDrvUnload;
  local_e8 = 0;
  puStack_e0 = (undefined8 *)0x0;
  local_f8 = 0;
  uStack_f0 = 0;
  LOCK();
  UNLOCK();
  bVar2 = true;
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_f8,0);
    iVar4 = IoQueryFullDriverPath(param_1,&local_f8);
    if (-1 < iVar4) {
      param_3 = (undefined8 *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
      iVar4 = RtlUnicodeStringToAnsiString(&local_e8,&local_f8);
      ExFreePoolWithTag(uStack_f0,0);
      if (-1 < iVar4) {
        uVar5 = (uint)(ushort)local_e8;
        do {
          uVar3 = uVar5;
          uVar5 = uVar3 - 1;
          if (uVar5 == 0) goto LAB_1400048cf;
          param_3 = puStack_e0;
        } while (*(char *)((ulonglong)uVar5 + (longlong)puStack_e0) != '\\');
        if (uVar5 != (ushort)local_e8) {
          local_d8 = 0;
          uStack_d0 = 0;
          RtlInitAnsiString(&local_d8,(undefined *)((ulonglong)uVar3 + (longlong)puStack_e0));
          local_c8 = local_d8;
          uStack_c0 = uStack_d0;
          InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_c8);
        }
LAB_1400048cf:
        RtlFreeAnsiString(&local_e8);
      }
    }
  }
  wil_InitializeFeatureStaging();
  local_104 = 0;
  iVar4 = FseReadInitializationFromRegistry
                    (L"\\Registry\\Machine\\Devices\\Networking\\Fse\\",&local_104);
  if (iVar4 < 0) {
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) ||
         (bVar1 = true, (code *)((ulonglong)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_58 = "Failed to read state-separated FSE Params Regkey";
        local_48 = local_100;
        local_50 = 0x31;
        param_4 = 0;
        local_40 = 4;
        local_100[0] = iVar4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002491c,0,0,4,local_78);
      }
    }
    uVar5 = FseReadInitializationFromRegistry
                      (L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Services\\fse\\Parameters\\"
                       ,&local_104);
    param_3 = (undefined8 *)(ulonglong)uVar5;
    if (((int)uVar5 < 0) && (2 < DAT_14002a000)) {
      if (((DAT_14002a010 & 4) == 0) ||
         (bVar1 = true, (code *)((ulonglong)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_98 = "Failed to read FSE Params Regkey";
        local_88 = &local_108;
        local_90 = 0x21;
        param_4 = 0;
        local_80 = 4;
        param_3 = (undefined8 *)0x0;
        local_108 = uVar5;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400248e6,0,0,4,local_b8);
      }
    }
  }
  puVar7 = (undefined8 *)(ulonglong)local_104;
  if ((local_104 & 1) == 0) {
    if (DAT_14002a000 < 5) {
      return 0;
    }
    if (((DAT_14002a010 & 2) == 0) ||
       ((code *)(ulonglong)((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_50 = 0x28;
      local_58 = "Not initializing FSE based on registry.";
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024b1c,0,0,3,local_78);
      return 0;
    }
    return 0;
  }
  pcVar8 = DAT_14002a018;
  uVar5 = FseInitGlobal(local_104);
  if ((uVar5 == 0) && (uVar5 = FseDiagnosticsContextInitialize(), uVar5 == 0)) {
    KeInitializeDpc(&DAT_14002a408,DpcTimerWorkerTcp);
    KeInitializeTimer(&DAT_14002a3c8);
    param_3 = (undefined8 *)0x0;
    pcVar8 = DpcTimerWorkerUdp;
    KeInitializeDpc(&DAT_14002a2d8);
    puVar7 = (undefined8 *)&DAT_14002a298;
    KeInitializeTimer();
    uVar6 = FseInitPortTracker(puVar7,pcVar8,param_3);
    uVar5 = (uint)uVar6;
    if (uVar5 == 0) {
      puVar7 = &DAT_14002a7a8;
      uVar5 = FseCoreInitialize(&DAT_14002a7a8);
      if (uVar5 == 0) {
        uVar6 = FsePortPolicyInitialize();
        uVar5 = (uint)uVar6;
        if (uVar5 == 0) {
          uVar5 = FseCreateIoDeviceObject((longlong)param_1);
          puVar7 = param_1;
          if ((uVar5 != 0) || (uVar5 = FseIpsClientInitialize(), puVar7 = param_1, uVar5 != 0))
          goto LAB_140004ba3;
          uVar6 = FseInitializeShims();
          uVar5 = (uint)uVar6;
          puVar7 = param_1;
          if (uVar5 != 0) goto LAB_140004ba3;
          ExInitializeRundownProtection(&DAT_14002a608);
          param_3 = &DAT_14002a1e0;
          pcVar8 = (code *)0x0;
          uVar5 = NmrRegisterProvider(&DAT_140020080);
          if (uVar5 == 0) {
            ExReInitializeRundownProtection(&DAT_14002a7c8);
            ExReInitializeRundownProtection(&DAT_14002a7d0);
            return 0;
          }
          puVar7 = (undefined8 *)WPP_GLOBAL_Control;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar7 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
            param_3 = (undefined8 *)&WPP_8046676e6fcd31b2fa8ceead8ac97718_Traceguids;
            pcVar8 = (code *)0xa;
            param_4 = (ulonglong)uVar5;
            WPP_SF_D(puVar7,10,&WPP_8046676e6fcd31b2fa8ceead8ac97718_Traceguids,uVar5);
          }
          if (DAT_14002a000 < 3) goto LAB_140004ba3;
          if (((DAT_14002a010 & 4) == 0) ||
             ((code *)((ulonglong)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar2 = false;
          }
          if (!bVar2) goto LAB_140004ba3;
          local_98 = "L\"FseLocalServerInitialize\" failed.";
          local_90 = 0x24;
          pcVar8 = (code *)&DAT_140024a86;
        }
        else {
          if (DAT_14002a000 < 3) goto LAB_140004ba3;
          if (((DAT_14002a010 & 4) == 0) ||
             ((code *)((ulonglong)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar2 = false;
          }
          if (!bVar2) goto LAB_140004ba3;
          local_98 = "L\"FsePortPolicyInitialize\" failed.";
          local_90 = 0x23;
          pcVar8 = (code *)&DAT_140024ab8;
        }
      }
      else {
        if (DAT_14002a000 < 3) goto LAB_140004ba3;
        if (((DAT_14002a010 & 4) == 0) || ((code *)((ulonglong)DAT_14002a018 & 4) != DAT_14002a018))
        {
          bVar2 = false;
        }
        if (!bVar2) goto LAB_140004ba3;
        local_98 = "L\"FseCoreInitialize\" failed.";
        local_90 = 0x1d;
        pcVar8 = (code *)&DAT_140024aea;
      }
      param_4 = 0;
      local_88 = &local_108;
      param_3 = (undefined8 *)0x0;
      local_80 = 4;
      puVar7 = (undefined8 *)&DAT_14002a000;
      local_108 = uVar5;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,(byte *)pcVar8,0,0,4,local_b8);
    }
  }
LAB_140004ba3:
  FseDrvUninitialize(puVar7,(wchar_t *)pcVar8,param_3,param_4);
  return uVar5;
}



===== FseCleanupPortTracker @ 140004d44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FseCleanupPortTracker
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  byte local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28[0] = 0x97;
  local_28[1] = 0x61;
  local_28[2] = 0xe1;
  local_28[3] = 0xe0;
  local_28[4] = 0x56;
  local_28[5] = 0xdd;
  local_28[6] = 0x10;
  local_28[7] = 0x4a;
  local_28[8] = 0x91;
  local_28[9] = 0x95;
  local_28[10] = 0x5e;
  local_28[0xb] = 0xe7;
  local_28[0xc] = 0xa1;
  local_28[0xd] = 0x55;
  local_28[0xe] = 0xa8;
  local_28[0xf] = 0x38;
  PtServerStopPartition(local_28,param_2,param_3,param_4);
  FsePortTrackerReleasePartitionPorts((longlong *)local_28);
  FseAllocatorNotifyDestroyPartition((longlong *)local_28);
  if (gIsServerInitialized != '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_427921e54f083bfd95ea087b74de8122_Traceguids);
    }
    FseWskDeregister();
    CleanupGlobals();
    if (gFseMidlObject != 0) {
      MesHandleFree();
    }
    gFseMidlObject = 0;
    gIsServerInitialized = '\0';
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140004e4d;
    if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_427921e54f083bfd95ea087b74de8122_Traceguids);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids);
  }
LAB_140004e4d:
  if (g_UdpPool != (uint *)0x0) {
    FsePortPoolFree(g_UdpPool);
    g_UdpPool = (uint *)0x0;
  }
  if (g_TcpPool != (uint *)0x0) {
    FsePortPoolFree(g_TcpPool);
    g_TcpPool = (uint *)0x0;
  }
  do {
    puVar7 = auStack_48;
    uVar6 = ExAcquireSpinLockExclusive(&DAT_14002a6a0);
    if ((longlong **)DAT_14002a610 == &DAT_14002a610) {
LAB_140004f00:
      *(undefined8 *)(puVar7 + -8) = 0x140004f11;
      ExReleaseSpinLockExclusive(&DAT_14002a6a0,uVar6);
      if (DAT_14002a6a8 != 0) {
        *(undefined8 *)(puVar7 + -8) = 0x140004f2e;
        ExFreePoolWithTag(DAT_14002a6a8,0x57657346);
        DAT_14002a6a8 = 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar7 + -8) = 0x140004f62;
        WPP_SF_(uVar4,0xf,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids);
      }
      *(undefined8 *)(puVar7 + -8) = 0x140004f6f;
      return;
    }
    puVar1 = (uint *)(DAT_14002a610 + -1);
    lVar2 = *DAT_14002a610;
    if ((*(longlong **)(lVar2 + 8) != DAT_14002a610) ||
       (plVar3 = (longlong *)DAT_14002a610[1], (longlong *)*plVar3 != DAT_14002a610)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar7 = auStack_40;
      goto LAB_140004f00;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExReleaseSpinLockExclusive(&DAT_14002a6a0,uVar6);
    *puVar1 = *puVar1 | 0x80;
    ExFreePoolWithTag(puVar1,0x56657346);
  } while( true );
}



===== FseDrvUninitialize @ 140004f84 =====

void FseDrvUninitialize(undefined8 param_1,wchar_t *param_2,undefined8 param_3,longlong param_4)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if ((DAT_14002a7d8 & 1) != 0) {
    ExWaitForRundownProtectionRelease(&DAT_14002a7d0);
    ExWaitForRundownProtectionRelease(&DAT_14002a608);
    if (DAT_14002a1e0 != 0) {
      iVar2 = NmrDeregisterProvider();
      if (iVar2 == 0x103) {
        NmrWaitForProviderDeregisterComplete(DAT_14002a1e0);
      }
      DAT_14002a1e0 = 0;
    }
    if (DAT_14002a7b0 != (longlong *)0x0) {
      FseIpsClientUninitialize(DAT_14002a7b0);
      FseFreeMemory((longlong *)&DAT_14002a7b0);
    }
    if (FseGlobalContext != 0) {
      param_2 = L"\\GLOBAL??\\FseIoDevice";
      local_18 = 0;
      uStack_10 = 0;
      RtlInitUnicodeString(&local_18);
      IoDeleteSymbolicLink(&local_18);
      IoDeleteDevice(FseGlobalContext);
      FseGlobalContext = 0;
    }
    if (DAT_14002a7b8 != 0) {
      FsePortPolicyUninitialize(DAT_14002a7b8);
      FseFreeMemory(&DAT_14002a7b8);
    }
    ExWaitForRundownProtectionRelease(&DAT_14002a7c8);
    lVar3 = DAT_14002a7a8;
    if (DAT_14002a7a8 != 0) {
      FseCoreUninitialize(DAT_14002a7a8);
    }
    FseCleanupPortTracker(lVar3,param_2,param_3,param_4);
    lVar3 = DAT_14002a7c0;
    if (DAT_14002a7c0 != 0) {
      if (*(longlong *)(DAT_14002a7c0 + 0x10) != 0) {
        FseFreeMemory((longlong *)(DAT_14002a7c0 + 0x10));
      }
      if (*(longlong *)(lVar3 + 0x30) != 0) {
        FseFreeMemory((longlong *)(lVar3 + 0x30));
      }
    }
    if (DAT_14002a7c0 != 0) {
      FseFreeMemory(&DAT_14002a7c0);
    }
    ExDeleteNPagedLookasideList(&g_FseCoreNblChainNduAttribDataLookasideList);
    ExDeleteNPagedLookasideList(&g_FseCoreNblChainSendContextLookasideList);
    ExDeleteNPagedLookasideList(&g_FseCoreNblChainIndicationContextLookasideList);
    if (g_FseNdisGenericObject != 0) {
      NdisFreeGenericObject();
      g_FseNdisGenericObject = 0;
    }
    uVar1 = DAT_14002a020;
    DAT_14002a020 = 0;
    DAT_14002a000 = 0;
    EtwUnregister(uVar1);
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
    UninitializeTelemetryAssertsKM();
  }
  return;
}



===== FseDrvUnload @ 1400051d0 =====

void FseDrvUnload(undefined8 param_1,wchar_t *param_2,undefined8 param_3,longlong param_4)

{
  FseDrvUninitialize(param_1,param_2,param_3,param_4);
  WppCleanupKm();
  return;
}



===== FseInitGlobal @ 1400051ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FseInitGlobal(undefined4 param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStackY_a8 [32];
  int local_78 [4];
  undefined8 local_68 [4];
  char *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  memset(&FseGlobalContext,0,0xb0);
  DAT_14002a7d8 = param_1;
  ExInitializeRundownProtection(&DAT_14002a7d0);
  ExWaitForRundownProtectionRelease(&DAT_14002a7d0);
  ExInitializeRundownProtection(&DAT_14002a7c8);
  ExWaitForRundownProtectionRelease(&DAT_14002a7c8);
  _DAT_14002a768 = 1;
  _WPP_MAIN_CB = 0;
  DAT_14002a748 = &WPP_ThisDir_CTLGUID_FseWpp;
  bVar2 = true;
  DAT_14002a750 = 0;
  _DAT_14002a760 = 0;
  WppLoadTracingSupport();
  _DAT_14002a760 = 0;
  WppInitKm();
  iVar3 = 0;
  TlgRegisterAggregateProviderEx();
  g_FseNdisGenericObject = NdisAllocateGenericObject(0,0x6f677346);
  if ((g_FseNdisGenericObject == 0) && (iVar3 = -0x3fffffe9, 2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_40 = 0x30;
      local_48 = "\"NdisAllocateGenericObject\" allocation failure.";
      local_38 = local_78;
      local_78[0] = -0x3fffffe9;
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026e81,0,0,4,local_68);
    }
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_40 = 0x24;
        local_48 = "FseBaseLibInitGlobal returned error";
        local_38 = local_78;
        local_78[0] = -0x3fffffe9;
        local_30 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026d37,0,0,4,local_68);
        iVar3 = -0x3fffffe9;
        goto LAB_140005400;
      }
    }
  }
  if (iVar3 == 0) {
    FseCreateLookasideList(0x14002a580,0x18,0x69627346);
    FseCreateLookasideList(0x14002a480,8,0x734e7346);
    FseCreateLookasideList(0x14002a500,0x28,0x614e7346);
    return 0;
  }
LAB_140005400:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_40 = 0x1d;
      local_48 = "FseInitGlobal returned error";
      local_38 = local_78;
      local_30 = 4;
      local_78[0] = iVar3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024a50,0,0,4,local_68);
    }
  }
  return iVar3;
}



===== FseInitPortTracker @ 1400054f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseInitPortTracker(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [2];
  longlong local_70 [3];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_70[0] = 0x4a10dd56e0e16197;
  local_70[1] = 0x38a855a1e75e9591;
  uVar4 = FseAllocatorInitialize2();
  uVar6 = uVar4 & 0xffffffff;
  bVar1 = true;
  if ((int)uVar4 == 0) {
    uVar4 = PtServerInitialize();
    uVar6 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      uVar3 = FseAllocatorNotifyCreatePartition(local_70);
      uVar6 = (ulonglong)uVar3;
      if (uVar3 == 0) {
        uVar4 = FsePortTrackerSetPartitionData(local_70,0,param_3);
        uVar6 = uVar4 & 0xffffffff;
        if ((int)uVar4 == 0) {
          return uVar6;
        }
        if (DAT_14002a000 < 3) goto LAB_1400056e5;
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (!bVar2) goto LAB_1400056e5;
        local_38 = "\"FsePortTrackerSetPartitionData\" failed.";
        local_30 = 0x29;
        pbVar5 = &DAT_140024988;
      }
      else {
        if (DAT_14002a000 < 3) goto LAB_1400056e5;
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (!bVar2) goto LAB_1400056e5;
        local_38 = "\"FseAllocatorNotifyCreatePartition\" failed.";
        local_30 = 0x2c;
        pbVar5 = &DAT_1400249ba;
      }
    }
    else {
      if (DAT_14002a000 < 3) goto LAB_1400056e5;
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) goto LAB_1400056e5;
      local_38 = "\"PtServerInitialize\" failed.";
      local_30 = 0x1d;
      pbVar5 = &DAT_1400249ec;
    }
  }
  else {
    if (DAT_14002a000 < 3) goto LAB_1400056e5;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) goto LAB_1400056e5;
    local_38 = "\"FseAllocatorInitialize2\" failed.";
    local_30 = 0x22;
    pbVar5 = &DAT_140024a1e;
  }
  local_2c = 0;
  local_1c = 0;
  local_28 = local_78;
  local_78[0] = (undefined4)uVar6;
  local_20 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar5,0,0,4,local_58);
LAB_1400056e5:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseInitPortTracker returned error";
      local_28 = local_78;
      local_30 = 0x22;
      local_78[0] = (undefined4)uVar6;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024952,0,0,4,local_58);
    }
  }
  return uVar6;
}



===== FseReadInitializationFromRegistry @ 140005788 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseReadInitializationFromRegistry(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 *local_c0;
  undefined4 local_b8 [2];
  longlong local_b0 [2];
  wchar_t *local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  wchar_t local_40 [20];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  *param_2 = 0;
  local_6c = 0;
  local_b8[0] = 0;
  local_b0[0] = 0;
  local_84 = 0;
  local_98 = 0;
  uStack_90 = 0;
  RtlInitUnicodeString(&local_98,param_1);
  local_80 = 0;
  local_78 = &local_98;
  local_88 = 0x30;
  local_70 = 0x240;
  local_68 = 0;
  uStack_60 = 0;
  iVar1 = ZwOpenKey(local_b0,0x20019,&local_88);
  if (-1 < iVar1) {
    local_a0 = local_40;
    local_b0[1] = 0x280026;
    builtin_wcsncpy(local_40,L"FlowSteeringEnab",0x10);
    local_48 = 0;
    builtin_wcsncpy(local_40 + 0x10,L"led",4);
    local_c0 = local_b8;
    local_b8[0] = 0x14;
    local_c8 = 0x14;
    local_58 = 0;
    uStack_50 = 0;
    iVar1 = ZwQueryValueKey(local_b0[0],local_b0 + 1,2,&local_58);
    if ((-1 < iVar1) && (local_58._4_4_ == 4)) {
      *param_2 = uStack_50._4_4_;
    }
  }
  if (local_b0[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== WppClassicProviderCallback @ 1400058e0 =====

void WppClassicProviderCallback(undefined8 param_1,byte param_2,ulonglong *param_3,longlong param_4)

{
  byte bVar1;
  ulonglong uVar2;
  uint uVar3;
  
  if (param_2 < 2) {
    uVar2 = 0;
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      bVar1 = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)((longlong)param_3 + 4);
      *(uint *)(param_4 + 0x2c) = uVar3;
      bVar1 = *(byte *)((longlong)param_3 + 2);
      *(byte *)(param_4 + 0x29) = bVar1;
      uVar2 = *param_3;
    }
    *(ulonglong *)(param_4 + 0x18) = uVar2;
    FseTraceEnableCallback
              (*(undefined8 *)(param_4 + 8),uVar2,CONCAT71((int7)((ulonglong)param_3 >> 8),param_2),
               (ulonglong)uVar3,bVar1);
  }
  return;
}



===== _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv @ 140005938 =====

void _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 140005944 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  longlong lVar6;
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
  lVar6 = (longlong)puVar5 - (longlong)&local_48 >> 3;
  if (0 < lVar6) {
    RtlRecordFeatureUsage(&local_48,lVar6);
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140005aa0 =====

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



===== FseIpsClientAddPhysicalInterface @ 140005b24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FseIpsClientAddPhysicalInterface(NET_IFINDEX param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  longlong lVar6;
  char cVar7;
  byte bVar8;
  uint uVar9;
  NTSTATUS NVar10;
  undefined8 uVar11;
  byte *pbVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  longlong lVar16;
  undefined1 auStackY_188 [8];
  undefined1 auStackY_180 [24];
  uint local_158;
  uint local_154;
  NET_IFINDEX local_150;
  NET_LUID local_148;
  longlong *local_140;
  _MIB_IPINTERFACE_ROW local_138;
  undefined4 local_a0;
  undefined8 local_88 [4];
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
  local_148.Value = 0;
  local_140 = (longlong *)0x0;
  local_138._2_4_ = 0;
  local_138._6_2_ = 0;
  uVar9 = 0;
  lVar16 = 0;
  local_150 = param_1;
  memset(&local_138,0,0xa2);
  cVar7 = KeGetCurrentIrql();
  if (cVar7 != '\0') {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar6 = DAT_14002a7b0;
  puVar15 = auStackY_188;
  if (DAT_14002a7b0 == 0) {
    puVar15 = auStackY_188;
    if (DAT_14002a000 < 3) goto LAB_140006041;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    puVar15 = auStackY_188;
    if (!bVar4) goto LAB_140006041;
    pbVar12 = &DAT_1400255b4;
    local_68 = "FseIpsClientAddPhysicalInterface: IpsClient not found.";
    local_58 = &local_158;
    local_60 = 0x37;
    local_158 = 0xc0000225;
    puVar15 = auStackY_188;
  }
  else {
    bVar4 = true;
    if ((*(byte *)(DAT_14002a7b0 + 0xc0) & 1) != 0) goto LAB_140006041;
    uVar9 = ConvertInterfaceIndexToLuid(param_1,&local_148);
    if (uVar9 == 0) {
      memset(&local_138,0xff,0xa8);
      local_138.InterfaceIndex = 0;
      local_138.BaseReachableTime = 0;
      local_138.RetransmitTime = 0;
      local_138.PathMtuDiscoveryTimeout = 0;
      local_a0 = 0;
      local_138.Family = 2;
      local_138.InterfaceLuid.Value = local_148.Value;
      uVar9 = GetIpInterfaceEntry(&local_138);
      local_158 = (uint)(byte)((byte)(uVar9 >> 0x1f) ^ 1);
      memset(&local_138,0xff,0xa8);
      local_138.InterfaceIndex = 0;
      local_138.BaseReachableTime = 0;
      local_138.RetransmitTime = 0;
      local_138.PathMtuDiscoveryTimeout = 0;
      local_a0 = 0;
      local_138.Family = 0x17;
      local_138.InterfaceLuid.Value = local_148.Value;
      NVar10 = GetIpInterfaceEntry(&local_138);
      bVar8 = (byte)((uint)NVar10 >> 0x1f) ^ 1;
      local_154 = (uint)bVar8;
      if ((((char)local_158 == '\0') && (bVar8 == 0)) && (uVar9 != 0)) {
        puVar15 = auStackY_188;
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar5 = false;
          }
          else {
            bVar5 = true;
          }
          puVar15 = auStackY_188;
          if (bVar5) {
            local_68 = "L\"GetIpInterfaceEntry\" failed.";
            local_60 = 0x1f;
            pbVar12 = &DAT_140025550;
            goto LAB_140005c96;
          }
        }
      }
      else {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(lVar6,0);
        puVar14 = auStackY_188;
        plVar1 = (longlong *)(lVar6 + 0xb0);
        for (plVar13 = (longlong *)*plVar1; plVar13 != plVar1; plVar13 = (longlong *)*plVar13) {
          if (local_150 == *(NET_IFINDEX *)(plVar13 + 3)) goto LAB_140005e64;
        }
        uVar11 = FseAllocMemory(0x28,0x66497346,&local_140);
        plVar13 = local_140;
        puVar15 = auStackY_188;
        uVar9 = (uint)uVar11;
        if (uVar9 == 0) {
          *(NET_IFINDEX *)(local_140 + 3) = local_150;
          local_140[4] = local_148.Value;
          *(char *)((longlong)local_140 + 0x16) = (char)local_158;
          *(char *)((longlong)local_140 + 0x17) = (char)local_154;
          *(undefined4 *)(local_140 + 2) = 1;
          plVar2 = *(longlong **)(lVar6 + 0xb8);
          if ((longlong *)*plVar2 == plVar1) {
            *local_140 = (longlong)plVar1;
            local_140[1] = (longlong)plVar2;
            *plVar2 = (longlong)local_140;
            *(longlong **)(lVar6 + 0xb8) = local_140;
            *(short *)(lVar6 + 0xa8) = *(short *)(lVar6 + 0xa8) + 1;
            local_140 = (longlong *)0x0;
            puVar15 = auStackY_188;
          }
          else {
            pcVar3 = (code *)swi(0x29);
            (*pcVar3)(3);
            puVar14 = auStackY_180;
LAB_140005e64:
            if (*(longlong *)(puVar14 + 0x40) != plVar13[4]) {
              *(undefined8 *)(puVar14 + -8) = 0x140005e74;
              MicrosoftTelemetryAssertTriggeredNoArgsKM();
            }
            *(int *)(plVar13 + 2) = (int)plVar13[2] + 1;
            puVar15 = puVar14;
          }
          if (plVar13 == (longlong *)0x0) {
            *(undefined8 *)(puVar15 + -8) = 0x140005ea0;
            MicrosoftTelemetryAssertTriggeredNoArgsKM();
          }
          *(undefined8 *)(puVar15 + -8) = 0x140005eab;
          uVar9 = FseIpsClientAttachInterfaceToIpsProviders(lVar6,(longlong)plVar13);
          if ((int)uVar9 < 0) {
            *(undefined8 *)(puVar15 + -8) = 0x140005ebd;
            FseDiagnosticsLogFailure(8,uVar9);
          }
        }
        *(undefined8 *)(puVar15 + -8) = 0x140005ec9;
        ExReleasePushLockExclusiveEx(lVar6,0);
        *(undefined8 *)(puVar15 + -8) = 0x140005ed5;
        KeLeaveCriticalRegion();
        lVar16 = *(longlong *)(puVar15 + 0x48);
      }
    }
    else {
      puVar15 = auStackY_188;
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar5 = false;
        }
        else {
          bVar5 = true;
        }
        puVar15 = auStackY_188;
        if (bVar5) {
          local_68 = "L\"ConvertInterfaceIndexToLuid\" failed.";
          local_60 = 0x27;
          pbVar12 = &DAT_140025582;
LAB_140005c96:
          local_5c = 0;
          local_4c = 0;
          local_58 = &local_158;
          local_50 = 4;
          local_158 = uVar9;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar12,0,0,4,local_88);
          puVar15 = auStackY_188;
        }
      }
    }
    if (((int)uVar9 < 0) && (2 < DAT_14002a000)) {
      if (((CONCAT71(uRam000000014002a011,DAT_14002a010) & 0x400000000004) == 0) ||
         ((DAT_14002a018 & 0x400000000004) != DAT_14002a018)) {
        bVar5 = false;
      }
      else {
        bVar5 = true;
      }
      if (bVar5) {
        local_5c = 0;
        local_68 = puVar15 + 0x34;
        local_4c = 0;
        local_3c = 0;
        *(undefined4 *)(puVar15 + 0x30) = *(undefined4 *)(puVar15 + 0x38);
        local_58 = (uint *)(puVar15 + 0x30);
        local_48 = puVar15 + 0x38;
        *(undefined8 **)(puVar15 + 0x28) = local_88;
        *(undefined4 *)(puVar15 + 0x20) = 5;
        *(uint *)(puVar15 + 0x34) = uVar9;
        local_60 = 4;
        local_50 = 4;
        *(undefined8 *)(puVar15 + 0x38) = 0x1000000;
        local_40 = 8;
        *(undefined8 *)(puVar15 + -8) = 0x140005f98;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x14002a000,&DAT_140025500,0,0,*(undefined4 *)(puVar15 + 0x20),
                   *(undefined8 **)(puVar15 + 0x28));
      }
    }
    if (lVar16 != 0) {
      if (-1 < (int)uVar9) {
        *(undefined8 *)(puVar15 + -8) = 0x140005fa6;
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      *(undefined8 *)(puVar15 + -8) = 0x140005fb0;
      FseFreeMemory((longlong *)(puVar15 + 0x48));
    }
    if ((int)uVar9 < 0) {
      *(undefined8 *)(puVar15 + -8) = 0x140005fc0;
      FseDiagnosticsLogFailure(10,uVar9);
    }
    else if (uVar9 == 0) goto LAB_140006041;
    if (DAT_14002a000 < 3) goto LAB_140006041;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar4 = false;
    }
    if (!bVar4) goto LAB_140006041;
    pbVar12 = &DAT_1400254ca;
    local_68 = "FseIpsClientAddPhysicalInterface returned error";
    local_58 = (uint *)(puVar15 + 0x34);
    local_60 = 0x30;
    *(uint *)(puVar15 + 0x34) = uVar9;
  }
  local_50 = 4;
  local_4c = 0;
  local_5c = 0;
  *(undefined8 **)(puVar15 + 0x28) = local_88;
  *(undefined4 *)(puVar15 + 0x20) = 4;
  *(undefined8 *)(puVar15 + -8) = 0x140006041;
  _tlgWriteTransfer_EtwWriteTransfer
            (0x14002a000,pbVar12,0,0,*(undefined4 *)(puVar15 + 0x20),
             *(undefined8 **)(puVar15 + 0x28));
LAB_140006041:
  *(undefined8 *)(puVar15 + -8) = 0x14000604f;
  return uVar9;
}



===== FseIpsClientAttachInterfaceToIpsProviders @ 140006074 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FseIpsClientAttachInterfaceToIpsProviders(longlong param_1,longlong param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  byte *pbVar4;
  ulonglong uVar5;
  longlong *plVar6;
  char *pcVar7;
  ushort uVar8;
  longlong lVar9;
  undefined1 auStackY_118 [32];
  undefined2 local_e8 [2];
  int local_e4;
  undefined1 local_e0;
  char local_df;
  undefined1 local_de [2];
  int local_dc;
  undefined8 local_d8 [2];
  undefined8 local_c8 [4];
  int *local_a8;
  undefined8 local_a0;
  int *local_98;
  undefined8 local_90;
  char *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar8 = 0;
  bVar2 = true;
  do {
    uVar5 = (ulonglong)uVar8;
    if (*(char *)(param_1 + 10 + uVar5 * 0x28) == '\0') {
      if (4 < DAT_14002a000) {
        local_e8[0] = *(undefined2 *)(param_1 + 8 + uVar5 * 0x28);
        pbVar4 = &DAT_1400259fa;
        local_e4 = *(int *)(param_2 + 0x18);
        local_88 = 
        "Skipped attaching interface to IPSNPI Provider as it is not attached to FSE IPSNPI client yet"
        ;
        local_80 = 0x5e;
LAB_140006263:
        local_98 = &local_e4;
        local_a8 = (int *)local_e8;
        local_a0 = 2;
        local_90 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar4,0,0,5,local_c8);
      }
    }
    else if (*(char *)(param_2 + 0x16 + uVar5) == '\0') {
      if (4 < DAT_14002a000) {
        local_e8[0] = *(undefined2 *)(param_1 + 8 + uVar5 * 0x28);
        pbVar4 = &DAT_140025b28;
        local_e4 = *(int *)(param_2 + 0x18);
        local_88 = 
        "Skipped attaching to provider since the bindings for this IP version are not enabled for this interface"
        ;
        local_80 = 0x68;
        goto LAB_140006263;
      }
    }
    else if (*(char *)(param_2 + 0x14 + uVar5) == '\x01') {
      if (4 < DAT_14002a000) {
        local_e8[0] = *(undefined2 *)(param_1 + 8 + uVar5 * 0x28);
        pbVar4 = &DAT_140025acf;
        local_e4 = *(int *)(param_2 + 0x18);
        local_88 = "Provider is already attached";
        local_80 = 0x1d;
        goto LAB_140006263;
      }
    }
    else {
      iVar3 = (**(code **)(*(longlong *)(param_1 + 0x18 + uVar5 * 0x28) + 8))();
      local_dc = iVar3;
      if (iVar3 != 0) {
        lVar9 = 2;
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) ||
             (bVar1 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar1 = false;
          }
          if (bVar1) {
            local_a0 = 0x2a;
            local_a8 = (int *)0x140021628;
            local_98 = &local_e4;
            local_90 = 4;
            local_e4 = iVar3;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025a9d,0,0,4,local_c8);
          }
        }
        if (iVar3 < 0) {
          if (2 < DAT_14002a000) {
            if (((CONCAT71(uRam000000014002a011,DAT_14002a010) & 0x400000000004) == 0) ||
               (bVar1 = true, (DAT_14002a018 & 0x400000000004) != DAT_14002a018)) {
              bVar1 = false;
            }
            if (bVar1) {
              local_a8 = &local_e4;
              local_e0 = *(undefined1 *)(param_2 + 0x14);
              local_98 = (int *)&local_e0;
              local_50 = 8;
              local_df = *(char *)(param_2 + 0x15);
              local_88 = &local_df;
              local_de[0] = *(undefined1 *)(param_1 + 10);
              local_78 = (undefined8 *)local_de;
              local_e8[0] = CONCAT11(local_e8[0]._1_1_,*(undefined1 *)(param_1 + 0x32));
              local_68 = (int *)local_e8;
              local_58 = local_d8;
              local_a0 = 4;
              local_90 = 1;
              local_80 = 1;
              local_70 = 1;
              local_60 = 1;
              local_d8[0] = 0x1000000;
              local_e4 = iVar3;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025942,0,0,8,local_c8);
            }
          }
          if (4 < DAT_14002a000) {
            if (((DAT_14002a010 & 2) == 0) || (bVar1 = true, (DAT_14002a018 & 2) != DAT_14002a018))
            {
              bVar1 = false;
            }
            if (bVar1) {
              local_a0 = 0x21;
              local_a8 = (int *)0x1400216d0;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025917,0,0,3,local_c8);
            }
          }
          plVar6 = (longlong *)(param_1 + 0x18);
          pcVar7 = (char *)(param_2 + 0x14);
          do {
            if ((*(char *)((longlong)plVar6 + -0xe) != '\0') && (*pcVar7 != '\0')) {
              iVar3 = (**(code **)(*plVar6 + 0x10))(plVar6[-1],*(undefined8 *)(param_2 + 0x20));
              if (((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x3ffffddb)) {
                if (2 < DAT_14002a000) {
                  local_e8[0] = (undefined2)plVar6[-2];
                  local_a8 = (int *)local_e8;
                  local_e4 = *(int *)(param_2 + 0x18);
                  local_98 = &local_e4;
                  local_88 = "Failed to detach interface from IPSNPI Provider";
                  local_78 = local_d8;
                  local_d8[0] = CONCAT44(local_d8[0]._4_4_,iVar3);
                  local_a0 = 2;
                  local_90 = 4;
                  local_80 = 0x30;
                  local_70 = 4;
                  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400258bc,0,0,6,local_c8);
                }
              }
              else {
                *pcVar7 = '\0';
              }
            }
            plVar6 = plVar6 + 5;
            pcVar7 = pcVar7 + 1;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
          iVar3 = local_dc;
        }
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar2 = false;
          }
          if (bVar2) {
            local_a0 = 0x39;
            local_a8 = (int *)0x140021728;
            local_98 = &local_dc;
            local_90 = 4;
            local_dc = iVar3;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025886,0,0,4,local_c8);
          }
        }
        return iVar3;
      }
      if (4 < DAT_14002a000) {
        local_e8[0] = *(undefined2 *)(param_1 + 8 + uVar5 * 0x28);
        local_a8 = (int *)local_e8;
        local_e4 = *(int *)(param_2 + 0x18);
        local_98 = &local_e4;
        local_a0 = 2;
        local_88 = "Succeeded";
        local_90 = 4;
        local_80 = 10;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025a4e,0,0,5,local_c8);
      }
      *(undefined1 *)(param_2 + 0x14 + uVar5) = 1;
    }
    uVar8 = uVar8 + 1;
    if (1 < uVar8) {
      return 0;
    }
  } while( true );
}



===== FseIpsClientCloneNbl @ 140006640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140006714) */
/* WARNING: Removing unreachable block (ram,0x000140006738) */
/* WARNING: Removing unreachable block (ram,0x00014000672f) */
/* WARNING: Removing unreachable block (ram,0x00014000673a) */
/* WARNING: Removing unreachable block (ram,0x000140006763) */
/* WARNING: Removing unreachable block (ram,0x000140006767) */
/* WARNING: Removing unreachable block (ram,0x000140006778) */
/* WARNING: Removing unreachable block (ram,0x000140006786) */
/* WARNING: Removing unreachable block (ram,0x00014000679d) */
/* WARNING: Removing unreachable block (ram,0x000140006799) */
/* WARNING: Removing unreachable block (ram,0x00014000679f) */
/* WARNING: Removing unreachable block (ram,0x0001400067a7) */
/* WARNING: Removing unreachable block (ram,0x0001400067db) */
/* WARNING: Removing unreachable block (ram,0x0001400067df) */
/* WARNING: Removing unreachable block (ram,0x0001400067e3) */
/* WARNING: Removing unreachable block (ram,0x0001400067ed) */
/* WARNING: Removing unreachable block (ram,0x000140006859) */
/* WARNING: Removing unreachable block (ram,0x00014000685e) */
/* WARNING: Removing unreachable block (ram,0x000140006863) */
/* WARNING: Removing unreachable block (ram,0x000140006868) */
/* WARNING: Removing unreachable block (ram,0x00014000688b) */
/* WARNING: Removing unreachable block (ram,0x0001400068bd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FseIpsClientCloneNbl(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  (**(code **)(*(longlong *)(*param_1 + 0x10) + 0x38))
            (*(undefined8 *)(*param_1 + 8),param_1[1],param_2);
  return 0;
}



===== FseIpsClientDropNblChain @ 1400068f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseIpsClientDropNblChain(longlong *param_1,longlong param_2,uint param_3)

{
  bool bVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auStackY_d8 [32];
  uint local_a8 [2];
  longlong local_a0;
  undefined8 local_98 [4];
  char *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar3 = *param_1;
  if (*(longlong *)(param_2 + 8) == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *(undefined8 *)(*(longlong *)(param_2 + 8) + 0x70) = 0;
  (**(code **)(*(longlong *)(lVar3 + 0x10) + 0x20))(*(undefined8 *)(lVar3 + 8),param_1[1],param_2);
  plVar2 = &DAT_14002a7f0;
  if ((int)param_1[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
    plVar2 = &DAT_14002a828;
  }
  LOCK();
  *plVar2 = *plVar2 + (ulonglong)param_3;
  UNLOCK();
  if (2 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x10000) == 0) || ((DAT_14002a018 & 0x10000) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_6c = 0;
      local_78 = "Packets Dropped";
      local_68 = "Outbound";
      local_70 = 0x10;
      if ((int)param_1[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
        local_68 = "Inbound";
      }
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (local_68[lVar3] != '\0');
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_60 = (int)lVar3 + 1;
      local_58 = local_a8;
      local_a0 = param_1[1];
      local_48 = &local_a0;
      local_50 = 4;
      local_40 = 8;
      local_a8[0] = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024d77,0,0,6,local_98);
    }
  }
  return;
}



===== FseIpsClientForwardNblChain @ 140006a8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseIpsClientForwardNblChain(longlong *param_1,longlong param_2,uint param_3,int param_4)

{
  bool bVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auStackY_f8 [32];
  uint local_c8 [2];
  longlong local_c0;
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [4];
  char *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b0 = 0;
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar3 = *param_1;
  local_b8 = 1;
  if (*(int *)(DAT_14002a7b0 + 0x88) == param_4) {
    local_b8 = *(undefined4 *)(DAT_14002a7b0 + 0x98);
  }
  local_b4 = param_4;
  if (*(longlong *)(param_2 + 8) == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *(undefined8 *)(*(longlong *)(param_2 + 8) + 0x70) = 0;
  (**(code **)(*(longlong *)(lVar3 + 0x10) + 0x98))(*(undefined8 *)(lVar3 + 8),param_1[1],param_2,0)
  ;
  plVar2 = &DAT_14002a808;
  if ((int)param_1[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
    plVar2 = &DAT_14002a840;
  }
  LOCK();
  *plVar2 = *plVar2 + (ulonglong)param_3;
  UNLOCK();
  if (5 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x1000) == 0) || ((DAT_14002a018 & 0x1000) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_7c = 0;
      local_88 = "Packets Forwarded";
      local_78 = "Outbound";
      local_80 = 0x12;
      if ((int)param_1[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
        local_78 = "Inbound";
      }
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (local_78[lVar3] != '\0');
      local_6c = 0;
      local_5c = 0;
      local_4c = 0;
      local_70 = (int)lVar3 + 1;
      local_68 = local_c8;
      local_c0 = param_1[1];
      local_58 = &local_c0;
      local_60 = 4;
      local_50 = 8;
      local_c8[0] = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024e3d,0,0,6,local_a8);
    }
  }
  return;
}



===== FseIpsClientIndicateNdResponse @ 140006c64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint FseIpsClientIndicateNdResponse(undefined8 *param_1,longlong param_2,longlong param_3)

{
  short *psVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  uint uVar5;
  byte *pbVar6;
  undefined1 auStackY_188 [32];
  uint local_128 [2];
  longlong local_120;
  undefined8 local_118;
  undefined1 local_110;
  undefined4 local_10f;
  undefined2 local_10b;
  undefined1 local_109;
  longlong local_108;
  longlong lStack_100;
  undefined1 local_f8 [8];
  undefined8 local_f0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88 [4];
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  lVar4 = DAT_14002a7b0;
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  local_10f = 0;
  local_120 = 0;
  local_110 = 0;
  local_10b = 0;
  local_109 = 0;
  local_108 = 0;
  lStack_100 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if (param_1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  psVar1 = (short *)*param_1;
  if (lVar4 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (psVar1 == (short *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar2 = true;
  if (*psVar1 == 2) {
    if (param_1 == (undefined8 *)0xffffffffffffffe0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    uVar5 = NetioPhCreateArpPacket(2);
    if (uVar5 == 0) {
LAB_140006f46:
      *(uint *)(local_120 + 0xb0) =
           (*(uint *)(local_120 + 0xb0) ^ *(uint *)(param_2 + 0xb0)) & 0xfff0 ^
           *(uint *)(local_120 + 0xb0);
      local_108 = local_120;
      lStack_100 = local_120;
      if (local_120 == 0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      *(undefined8 *)(local_108 + 0x70) = 0;
      local_98 = CONCAT44(*(undefined4 *)(lVar4 + 0x88),*(undefined4 *)(lVar4 + 0x98));
      (**(code **)(*(longlong *)(psVar1 + 8) + 0x98))(*(undefined8 *)(psVar1 + 4),param_1[1]);
      if (uVar5 == 0) {
        return 0;
      }
      goto LAB_140006fd5;
    }
    if (DAT_14002a000 < 3) goto LAB_140006fd5;
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (!bVar3) goto LAB_140006fd5;
    local_68 = "\"NetioPhCreateArpPacket\" failed.";
    pbVar6 = &DAT_140024fdc;
LAB_140006d9b:
    local_60 = 0x21;
  }
  else {
    if (param_3 == 0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    memset(local_f8,0,0x58);
    local_118 = 0;
    uVar5 = NetioParseIpv6NdFields(*(undefined8 *)(param_2 + 8),6);
    if (uVar5 != 0) {
      if (DAT_14002a000 < 3) goto LAB_140006fd5;
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (!bVar3) goto LAB_140006fd5;
      local_68 = "\"NetioParseIpv6NdFields\" failed.";
      pbVar6 = &DAT_140024faa;
      goto LAB_140006d9b;
    }
    (**(code **)(*(longlong *)(psVar1 + 8) + 0x78))(*(undefined8 *)(psVar1 + 4),0,0,local_f0);
    uVar5 = NetioPhCreateFullNaPacket(0xe);
    if (uVar5 == 0) goto LAB_140006f46;
    if (DAT_14002a000 < 3) goto LAB_140006fd5;
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (!bVar3) goto LAB_140006fd5;
    local_68 = "\"NetioPhCreateFullNaPacket\" failed.";
    local_60 = 0x24;
    pbVar6 = &DAT_140024f78;
  }
  local_5c = 0;
  local_4c = 0;
  local_58 = local_128;
  local_50 = 4;
  local_128[0] = uVar5;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar6,0,0,4,local_88);
LAB_140006fd5:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_5c = 0;
      local_4c = 0;
      local_68 = "FseIpsClientIndicateNdResponse returned error";
      local_58 = local_128;
      local_60 = 0x2e;
      local_50 = 4;
      local_128[0] = uVar5;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024f42,0,0,4,local_88);
    }
  }
  return uVar5;
}



===== _guard_check_icall @ 140007090 =====

void _guard_check_icall(void)

{
  return;
}



===== FseIpsClientParseNbl @ 14000709c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FseIpsClientParseNbl(undefined8 *param_1,longlong param_2)

{
  undefined2 *puVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  undefined1 auStackY_a8 [32];
  uint local_78 [4];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (param_1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar1 = (undefined2 *)*param_1;
  if (param_2 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar2 = *(longlong *)(param_2 + 8);
  if (lVar2 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  uVar5 = NetioParseAllFieldsFromNetBuffer(lVar2,*puVar1);
  if (uVar5 != 0) {
    bVar3 = true;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if (bVar4) {
        local_3c = 0;
        local_2c = 0;
        local_48 = "NetioParseAllFieldsFromNetBuffer failed.";
        local_38 = local_78;
        local_40 = 0x29;
        local_30 = 4;
        local_78[0] = uVar5;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400250de,0,0,4,local_68);
      }
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar3 = false;
        }
        if (bVar3) {
          local_3c = 0;
          local_2c = 0;
          local_48 = "FseIpsClientParseNbl returned error";
          local_38 = local_78;
          local_40 = 0x24;
          local_30 = 4;
          local_78[0] = uVar5;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400250a8,0,0,4,local_68);
        }
      }
    }
  }
  return uVar5;
}



===== FseIpsClientReceiveArpPackets @ 140007240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseIpsClientReceiveArpPackets
               (longlong param_1,undefined8 param_2,undefined4 param_3,int param_4,
               undefined8 param_5,longlong param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9,undefined4 param_10)

{
  bool bVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStackY_128 [32];
  uint local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  longlong local_e8;
  undefined8 local_e0;
  int local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8 [4];
  char *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_ac = 0;
  local_d0 = 1;
  uVar5 = 0;
  puVar2 = *(undefined8 **)(param_6 + 8);
  local_c8 = param_7;
  local_c0 = param_8;
  local_b8 = param_9;
  local_b0 = param_10;
  for (; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2) {
    uVar5 = uVar5 + 1;
  }
  plVar3 = &DAT_14002a7e0;
  if (param_4 != *(int *)(DAT_14002a7b0 + 0x88)) {
    plVar3 = &DAT_14002a818;
  }
  LOCK();
  *plVar3 = *plVar3 + (ulonglong)uVar5;
  UNLOCK();
  local_e8 = param_1;
  local_e0 = param_2;
  local_d8 = param_4;
  local_d4 = param_3;
  if (5 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x1000) == 0) || ((DAT_14002a018 & 0x1000) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_7c = 0;
      local_88 = "ARP Packets Indicated";
      local_78 = "Outbound";
      local_80 = 0x16;
      if (param_4 != *(int *)(DAT_14002a7b0 + 0x88)) {
        local_78 = "Inbound";
      }
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (local_78[lVar4] != '\0');
      local_6c = 0;
      local_70 = (int)lVar4 + 1;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_68 = &local_f8;
      local_58 = &local_f4;
      local_48 = &local_f0;
      local_60 = 4;
      local_50 = 4;
      local_f4 = param_10;
      local_40 = 8;
      local_f8 = uVar5;
      local_f0 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025178,0,0,7,local_a8);
    }
  }
  if (param_4 == *(int *)(DAT_14002a7b0 + 0x88)) {
    FseUpperShimProcessOutboundNblChain((longlong)&local_e8,param_6);
  }
  else if (((byte)param_10 & 0x11) == 1) {
    FseIpsClientReturnNblChain(&local_e8,param_6,uVar5);
  }
  else {
    FseShimsProcessFloodNblChain(&local_e8,param_6,uVar5);
  }
  return;
}



===== FseIpsClientReceivePackets @ 140007450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseIpsClientReceivePackets
               (longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               int param_5,undefined8 param_6,longlong param_7,undefined4 param_8)

{
  bool bVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStackY_128 [32];
  uint local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  longlong local_e8;
  undefined8 local_e0;
  int local_d8;
  undefined4 local_d4;
  undefined4 local_b0;
  undefined8 local_a8 [4];
  char *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  memset(&local_e8,0,0x40);
  puVar2 = *(undefined8 **)(param_7 + 8);
  uVar5 = 0;
  local_d8 = param_5;
  local_b0 = param_8;
  for (; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2) {
    uVar5 = uVar5 + 1;
  }
  plVar3 = &DAT_14002a7e0;
  if (param_5 != *(int *)(DAT_14002a7b0 + 0x88)) {
    plVar3 = &DAT_14002a818;
  }
  LOCK();
  *plVar3 = *plVar3 + (ulonglong)uVar5;
  UNLOCK();
  local_e8 = param_1;
  local_e0 = param_2;
  local_d4 = param_3;
  if (5 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x1000) == 0) ||
       (bVar1 = true, (DAT_14002a018 & 0x1000) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_80 = 0x12;
      local_88 = "Packets Indicated";
      local_78 = "Outbound";
      if (param_5 != *(int *)(DAT_14002a7b0 + 0x88)) {
        local_78 = "Inbound";
      }
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (local_78[lVar4] != '\0');
      local_70 = (int)lVar4 + 1;
      local_68 = &local_f8;
      local_58 = &local_f4;
      local_f4 = param_8;
      local_48 = &local_f0;
      local_6c = 0;
      local_60 = 4;
      local_50 = 4;
      local_40 = 8;
      local_f8 = uVar5;
      local_f0 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400251f3,0,0,7,local_a8);
    }
  }
  if (param_5 == *(int *)(DAT_14002a7b0 + 0x88)) {
    FseUpperShimProcessOutboundNblChain((longlong)&local_e8,param_7);
  }
  else {
    FseDemuxShimProcessInboundNblChain(&local_e8,param_7);
  }
  return;
}



===== FseIpsClientReleaseNblChain @ 140007624 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseIpsClientReleaseNblChain(longlong *param_1,longlong param_2,uint param_3)

{
  bool bVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auStackY_d8 [32];
  uint local_a8 [2];
  longlong local_a0;
  undefined8 local_98 [4];
  char *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar3 = *param_1;
  if (*(longlong *)(param_2 + 8) == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *(undefined8 *)(*(longlong *)(param_2 + 8) + 0x70) = 0;
  (**(code **)(*(longlong *)(lVar3 + 0x10) + 0x40))(*(undefined8 *)(lVar3 + 8),param_2);
  plVar2 = &DAT_14002a7f8;
  if ((int)param_1[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
    plVar2 = &DAT_14002a830;
  }
  LOCK();
  *plVar2 = *plVar2 + (ulonglong)param_3;
  UNLOCK();
  if (5 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x1000) == 0) || ((DAT_14002a018 & 0x1000) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_6c = 0;
      local_78 = "Packets Released";
      local_68 = "Outbound";
      local_70 = 0x11;
      if ((int)param_1[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
        local_68 = "Inbound";
      }
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (local_68[lVar3] != '\0');
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_60 = (int)lVar3 + 1;
      local_58 = local_a8;
      local_a0 = param_1[1];
      local_48 = &local_a0;
      local_50 = 4;
      local_40 = 8;
      local_a8[0] = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024dd9,0,0,6,local_98);
    }
  }
  return;
}



===== FseIpsClientRemoveHostVnic @ 1400077bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseIpsClientRemoveHostVnic(void)

{
  bool bVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  longlong *plVar5;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8 [2];
  longlong local_a0;
  undefined4 local_98;
  int local_94 [3];
  undefined8 local_88 [4];
  char *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  lVar2 = DAT_14002a7b0;
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (DAT_14002a7b0 == 0) {
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_60 = 0x31;
        local_68 = "FseIpsClientRemoveHostVnic: IpsClient not found.";
        local_58 = (char *)local_a8;
        local_a8[0] = 0xc0000225;
        local_50 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400256b2,0,0,4,local_88);
      }
    }
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar2);
    if (*(char *)(lVar2 + 0x68) == '\0') {
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_60 = 0x5a;
          local_68 = 
          "FseIpsClientRemoveHostVnic: Ignoring Remove Host VNIC call as no Host VNIC is configured."
          ;
          local_58 = (char *)local_a8;
          local_a8[0] = 0xc0000225;
          local_50 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025680,0,0,4,local_88);
        }
      }
    }
    else {
      if (4 < DAT_14002a000) {
        local_a8[0] = *(undefined4 *)(lVar2 + 0x88);
        local_68 = (char *)local_a8;
        local_60 = 4;
        local_50 = 0x29;
        local_58 = "Detaching host vNIC from IPSNPI Provider";
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025647,0,0,4,local_88);
      }
      local_a0 = 2;
      plVar5 = (longlong *)(lVar2 + 0x18);
      pcVar4 = (char *)(lVar2 + 0x84);
      do {
        if ((((*(char *)((longlong)plVar5 + -0xe) == '\x01') && (*pcVar4 == '\x01')) &&
            (iVar3 = (**(code **)(*plVar5 + 0x10))(plVar5[-1],*(undefined8 *)(lVar2 + 0x90)),
            (iVar3 + 0x80000000U & 0x80000000) == 0)) &&
           ((iVar3 != -0x3ffffddb && (FseDiagnosticsLogFailure(0xc,iVar3), 2 < DAT_14002a000)))) {
          local_a8[0] = CONCAT22(local_a8[0]._2_2_,(short)plVar5[-2]);
          local_68 = (char *)local_a8;
          local_60 = 2;
          local_98 = *(undefined4 *)(lVar2 + 0x88);
          local_58 = (char *)&local_98;
          local_48 = "Failed to detach Host VNIC from IPSNPI Provider";
          local_38 = local_94;
          local_50 = 4;
          local_40 = 0x30;
          local_30 = 4;
          local_94[0] = iVar3;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400255e6,0,0,6,local_88);
        }
        plVar5 = plVar5 + 5;
        pcVar4 = pcVar4 + 1;
        local_a0 = local_a0 + -1;
      } while (local_a0 != 0);
      memset((void *)(lVar2 + 0x68),0,0x40);
    }
    ExReleasePushLockExclusiveEx(lVar2,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== FseIpsClientRemovePhysicalInterface @ 140007b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseIpsClientRemovePhysicalInterface(int param_1)

{
  longlong lVar1;
  code *pcVar2;
  bool bVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  char *pcVar9;
  longlong *plVar10;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  int local_b8;
  int iStack_b4;
  longlong local_b0;
  undefined4 local_a8 [2];
  longlong *local_a0;
  undefined8 local_98 [4];
  int *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  cVar5 = KeGetCurrentIrql();
  if (cVar5 != '\0') {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar4 = DAT_14002a7b0;
  puVar8 = auStackY_e8;
  if (DAT_14002a7b0 == 0) {
    puVar8 = auStackY_e8;
    if (2 < DAT_14002a000) {
      local_60 = 4;
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      puVar8 = auStackY_e8;
      if (bVar3) {
        local_70 = 0x3a;
        local_78 = (int *)0x1400219b8;
        local_68 = &local_b8;
        local_b8 = -0x3ffffddb;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025498,0,0,4,local_98);
        puVar8 = auStackY_e8;
      }
    }
  }
  else if ((*(byte *)(DAT_14002a7b0 + 0xc0) & 1) == 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar4,0);
    puVar8 = auStackY_e8;
    plVar7 = *(longlong **)(lVar4 + 0xb0);
    while( true ) {
      if (plVar7 == (longlong *)(lVar4 + 0xb0)) goto LAB_140007e64;
      iVar6 = (int)plVar7[3];
      local_a0 = plVar7;
      if (param_1 == iVar6) break;
      plVar7 = (longlong *)*plVar7;
    }
    plVar10 = plVar7 + 2;
    *(int *)plVar10 = (int)*plVar10 + -1;
    puVar8 = auStackY_e8;
    if ((int)*plVar10 == 0) {
      lVar1 = *plVar7;
      if ((*(longlong **)(lVar1 + 8) == plVar7) &&
         (plVar10 = (longlong *)plVar7[1], (longlong *)*plVar10 == plVar7)) {
        *plVar10 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar10;
        *(short *)(lVar4 + 0xa8) = *(short *)(lVar4 + 0xa8) + -1;
        if (4 < DAT_14002a000) {
          local_b8 = (int)plVar7[3];
          local_78 = &local_b8;
          local_70 = 4;
          local_60 = 0x29;
          local_68 = (int *)0x140021a28;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025426,0,0,4,local_98);
        }
        puVar8 = auStackY_e8;
        pcVar9 = (char *)((longlong)plVar7 + 0x14);
        local_b0 = 2;
        plVar10 = (longlong *)(lVar4 + 0x18);
        do {
          if ((((*(char *)((longlong)plVar10 + -0xe) == '\x01') && (*pcVar9 == '\x01')) &&
              (iVar6 = (**(code **)(*plVar10 + 0x10))(plVar10[-1],plVar7[4]),
              (iVar6 + 0x80000000U & 0x80000000) == 0)) &&
             ((iVar6 != -0x3ffffddb && (FseDiagnosticsLogFailure(9,iVar6), 2 < DAT_14002a000)))) {
            local_b8 = CONCAT22(local_b8._2_2_,(short)plVar10[-2]);
            local_78 = &local_b8;
            local_70 = 2;
            local_a8[0] = (undefined4)plVar7[3];
            local_68 = local_a8;
            local_58 = "Failed to detach interface from IPSNPI Provider";
            local_48 = &iStack_b4;
            local_60 = 4;
            local_50 = 0x30;
            local_40 = 4;
            iStack_b4 = iVar6;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400253c5,0,0,6,local_98);
          }
          plVar10 = plVar10 + 5;
          pcVar9 = pcVar9 + 1;
          local_b0 = local_b0 + -1;
        } while (local_b0 != 0);
        FseFreeMemory((longlong *)&local_a0);
LAB_140007e64:
        *(undefined8 *)(puVar8 + -8) = 0x140007e70;
        ExReleasePushLockExclusiveEx(lVar4,0);
        *(undefined8 *)(puVar8 + -8) = 0x140007e7c;
        KeLeaveCriticalRegion();
        goto LAB_140007e81;
      }
      iVar6 = 3;
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)();
      puVar8 = auStackY_e0;
    }
    if (4 < DAT_14002a000) {
      local_78 = &iStack_b4;
      iStack_b4 = iVar6;
      local_70 = 4;
      local_68 = (int *)0x1400219f8;
      local_60 = 0x2a;
      *(undefined8 **)(puVar8 + 0x28) = local_98;
      *(undefined4 *)(puVar8 + 0x20) = 4;
      *(undefined8 *)(puVar8 + -8) = 0x140007e64;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x14002a000,&DAT_14002545f,0,0,*(undefined4 *)(puVar8 + 0x20),
                 *(undefined8 **)(puVar8 + 0x28));
    }
    goto LAB_140007e64;
  }
LAB_140007e81:
  *(undefined8 *)(puVar8 + -8) = 0x140007e8d;
  return;
}



===== FseIpsClientReturnNblChain @ 140007eb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseIpsClientReturnNblChain(longlong *param_1,longlong param_2,uint param_3)

{
  bool bVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auStackY_d8 [32];
  uint local_a8 [2];
  longlong local_a0;
  undefined8 local_98 [4];
  char *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  char *local_68;
  int local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar3 = *param_1;
  if (*(longlong *)(param_2 + 8) == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *(undefined8 *)(*(longlong *)(param_2 + 8) + 0x70) = 0;
  (**(code **)(*(longlong *)(lVar3 + 0x10) + 0x28))(*(undefined8 *)(lVar3 + 8),param_1[1],param_2);
  plVar2 = &DAT_14002a7e8;
  if ((int)param_1[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
    plVar2 = &DAT_14002a820;
  }
  LOCK();
  *plVar2 = *plVar2 + (ulonglong)param_3;
  UNLOCK();
  if (5 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x1000) == 0) || ((DAT_14002a018 & 0x1000) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_6c = 0;
      local_78 = "Packets Returned";
      local_68 = "Outbound";
      local_70 = 0x11;
      if ((int)param_1[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
        local_68 = "Inbound";
      }
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (local_68[lVar3] != '\0');
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_60 = (int)lVar3 + 1;
      local_58 = local_a8;
      local_a0 = param_1[1];
      local_48 = &local_a0;
      local_50 = 4;
      local_40 = 8;
      local_a8[0] = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024d13,0,0,6,local_98);
    }
  }
  return;
}



===== FseIpsClientRundownHelper @ 140008054 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FseIpsClientRundownHelper(void)

{
  bool bVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  byte *pbVar6;
  longlong lVar7;
  undefined8 *puVar8;
  ushort uVar9;
  undefined1 auStackY_188 [32];
  undefined4 uVar10;
  undefined1 local_158;
  undefined1 local_157;
  undefined1 local_156;
  undefined1 local_155;
  byte local_154 [4];
  ushort local_150 [2];
  undefined1 local_14c;
  undefined1 uStack_14b;
  undefined2 uStack_14a;
  undefined2 local_148;
  longlong local_140;
  undefined4 local_138 [4];
  undefined8 local_128 [4];
  undefined1 *local_108;
  undefined8 local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  longlong local_a8;
  undefined8 local_a0;
  ushort *local_98;
  undefined8 local_90;
  longlong local_88;
  undefined4 local_80;
  undefined4 local_7c;
  byte *local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  lVar2 = DAT_14002a7b0;
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
  local_140 = 0;
  local_14c = 0;
  uStack_14b = 0;
  uStack_14a = 0;
  lVar7 = 0;
  local_148 = 0;
  uVar9 = 0;
  if (DAT_14002a7b0 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar2,0);
  local_158 = *(undefined1 *)(lVar2 + 10);
  local_157 = *(undefined1 *)(lVar2 + 0x32);
  local_150[0] = *(ushort *)(lVar2 + 0xa8);
  uVar3 = (ulonglong)local_150[0];
  if (local_150[0] == 0) {
    if (DAT_14002a000 < 6) goto LAB_140008329;
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) goto LAB_140008329;
    local_40 = 0x22;
    local_48 = "No physical interfaces to Rundown";
    pbVar6 = &DAT_140024c84;
    puVar8 = local_68;
    uVar10 = 3;
  }
  else {
    uVar4 = FseAllocMemory(uVar3 * 6,0x66497346,&local_140);
    lVar7 = local_140;
    if ((int)uVar4 != 0) goto LAB_140008329;
    if (local_140 == 0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    for (puVar8 = *(undefined8 **)(lVar2 + 0xb0); puVar8 != (undefined8 *)(lVar2 + 0xb0);
        puVar8 = (undefined8 *)*puVar8) {
      if (local_150[0] <= uVar9) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      uVar5 = (ulonglong)uVar9;
      uVar9 = uVar9 + 1;
      *(undefined1 *)(lVar7 + uVar5 * 6) = *(undefined1 *)((longlong)puVar8 + 0x14);
      *(undefined1 *)(lVar7 + 1 + uVar5 * 6) = *(undefined1 *)((longlong)puVar8 + 0x15);
      *(undefined4 *)(lVar7 + 2 + uVar5 * 6) = *(undefined4 *)(puVar8 + 3);
    }
    local_14c = *(undefined1 *)(lVar2 + 0x84);
    uStack_14b = *(undefined1 *)(lVar2 + 0x85);
    uStack_14a = (undefined2)*(undefined4 *)(lVar2 + 0x88);
    local_148 = (undefined2)((uint)*(undefined4 *)(lVar2 + 0x88) >> 0x10);
    if (DAT_14002a000 < 5) goto LAB_140008329;
    if (((uRam000000014002a011 & 0x800) == 0) || ((DAT_14002a018 & 0x80000) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) goto LAB_140008329;
    pbVar6 = &DAT_140024b47;
    local_108 = &local_158;
    local_f8 = &local_157;
    local_156 = *(undefined1 *)(lVar2 + 0x58);
    local_e8 = &local_156;
    local_d8 = &local_14c;
    local_155 = *(undefined1 *)(lVar2 + 0x68);
    local_c8 = &local_155;
    local_138[0] = *(undefined4 *)(lVar2 + 0x98);
    local_b8 = local_138;
    local_a8 = lVar2 + 0x9c;
    local_98 = local_150;
    local_154[0] = *(byte *)(lVar2 + 0xc0) & 1;
    local_100 = 1;
    local_78 = local_154;
    puVar8 = local_128;
    uVar10 = 0xc;
    local_f0 = 1;
    local_e0 = 1;
    local_d0 = 6;
    local_c0 = 1;
    local_b0 = 4;
    local_a0 = 6;
    local_90 = 2;
    local_88 = lVar7;
    local_80 = (undefined4)(uVar3 * 6);
    local_7c = 0;
    local_70 = 1;
  }
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar6,0,0,uVar10,puVar8);
LAB_140008329:
  ExReleasePushLockSharedEx(lVar2,0);
  KeLeaveCriticalRegion();
  if (lVar7 != 0) {
    FseFreeMemory(&local_140);
  }
  return;
}



===== FseIpsClientSetHostVnic @ 14000838c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NET_IFINDEX FseIpsClientSetHostVnic(NET_IFINDEX param_1,NET_IFINDEX param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  NET_IFINDEX NVar4;
  NET_LUID *_Dst;
  undefined8 uVar5;
  byte *pbVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStackY_648 [32];
  NET_IFINDEX local_618;
  byte local_614 [4];
  NET_IFINDEX local_610;
  NET_IFINDEX local_60c;
  NET_LUID local_608;
  undefined8 local_600;
  NET_LUID local_5f8;
  NET_IFINDEX local_5f0;
  int local_1d8;
  undefined4 local_1d4;
  undefined2 local_1d0;
  undefined8 local_a8 [4];
  NET_IFINDEX *local_88;
  undefined8 local_80;
  NET_IFINDEX *local_78;
  undefined8 local_70;
  NET_IFINDEX *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  byte *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_648;
  uVar5 = 0;
  _Dst = &local_5f8;
  lVar7 = 0;
  memset(_Dst,0,0x548);
  local_608.Value = 0;
  cVar3 = KeGetCurrentIrql();
  if (cVar3 != '\0') {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar2 = true;
  lVar8 = lVar7;
  if (DAT_14002a7b0 == 0) {
    NVar4 = 0xc0000225;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_88 = (NET_IFINDEX *)0x140021768;
        local_78 = &local_618;
        local_80 = 0x2e;
        local_618 = 0xc0000225;
        local_70 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025854,0,0,4,local_a8);
      }
LAB_1400087bd:
      if (2 < DAT_14002a000) {
        if (((CONCAT71(uRam000000014002a011,DAT_14002a010) & 0x400000000004) == 0) ||
           ((DAT_14002a018 & 0x400000000004) != DAT_14002a018)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_88 = &local_618;
          local_5c = 0;
          local_4c = 0;
          local_3c = 0;
          local_78 = &local_60c;
          local_68 = &local_610;
          local_614[0] = *(byte *)(lVar8 + 0xc0) & 1;
          local_58 = local_614;
          local_48 = &local_600;
          local_80 = 4;
          local_70 = 4;
          local_60 = 4;
          local_50 = 1;
          local_600 = 0x1000000;
          local_40 = 8;
          local_618 = NVar4;
          local_610 = param_2;
          local_60c = param_1;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002571a,0,0,7,local_a8);
        }
      }
    }
    FseDiagnosticsLogFailure(0xd,NVar4);
  }
  else {
    local_5f0 = param_1;
    NVar4 = InternalGetIfEntry2Ex(_Dst,uVar5,&local_5f8);
    if (NVar4 == 0) {
      if (local_1d8 != 6) {
        if (DAT_14002a000 < 3) {
          return 0;
        }
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar2 = false;
        }
        if (!bVar2) {
          return 0;
        }
        local_80 = 0x39;
        local_88 = (NET_IFINDEX *)0x1400217b0;
        pbVar6 = &DAT_1400257f0;
        local_78 = &local_618;
        local_618 = 0xc000000d;
        goto LAB_140008947;
      }
      NVar4 = ConvertInterfaceIndexToLuid(param_1,&local_608);
      lVar8 = DAT_14002a7b0;
      if (NVar4 == 0) {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(lVar8);
        if (*(char *)(lVar8 + 0x68) == '\0') {
          *(NET_IFINDEX *)(lVar8 + 0x88) = param_1;
          *(ULONG64 *)(lVar8 + 0x90) = local_608.Value;
          *(NET_IFINDEX *)(lVar8 + 0x98) = param_2;
          *(undefined4 *)(lVar8 + 0x9c) = local_1d4;
          *(undefined2 *)(lVar8 + 0xa0) = local_1d0;
          *(undefined2 *)(lVar8 + 0x86) = 0x101;
          if ((*(byte *)(lVar8 + 0xc0) & 1) == 0) {
            NVar4 = FseIpsClientAttachInterfaceToIpsProviders(lVar8,lVar8 + 0x70);
            if ((int)NVar4 < 0) {
              FseDiagnosticsLogFailure(0xb,NVar4);
            }
            else if (NVar4 == 0) goto LAB_14000878d;
          }
          else {
LAB_14000878d:
            *(undefined1 *)(lVar8 + 0x68) = 1;
          }
        }
        else {
          NVar4 = 0x40000000;
          if (2 < DAT_14002a000) {
            if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018))
            {
              bVar1 = false;
            }
            if (bVar1) {
              local_80 = 0x1e;
              local_88 = (NET_IFINDEX *)0x1400217f0;
              local_78 = &local_618;
              local_618 = 0x40000000;
              local_70 = 4;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002578c,0,0,4,local_a8);
            }
          }
        }
        ExReleasePushLockExclusiveEx(lVar8,0);
        KeLeaveCriticalRegion();
      }
      else {
        lVar8 = lVar7;
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            local_88 = (NET_IFINDEX *)0x140020a88;
            pbVar6 = &DAT_1400257be;
            local_80 = 0x27;
            goto LAB_140008530;
          }
        }
      }
    }
    else if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_88 = (NET_IFINDEX *)0x140021798;
        local_80 = 0x14;
        pbVar6 = &DAT_140025822;
LAB_140008530:
        local_70 = 4;
        local_78 = &local_618;
        local_618 = NVar4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar6,0,0,4,local_a8);
        lVar8 = lVar7;
      }
    }
    if ((int)NVar4 < 0) goto LAB_1400087bd;
  }
  if (NVar4 == 0) {
    return 0;
  }
  if (DAT_14002a000 < 3) {
    return NVar4;
  }
  if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
    bVar2 = false;
  }
  if (!bVar2) {
    return NVar4;
  }
  pbVar6 = &DAT_1400256e4;
  local_88 = (NET_IFINDEX *)0x140021810;
  local_78 = &local_610;
  local_80 = 0x27;
  local_610 = NVar4;
LAB_140008947:
  local_70 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar6,0,0,4,local_a8);
  return NVar4;
}



===== FseIpsPrependEthernetHeader @ 1400089a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseIpsPrependEthernetHeader
              (longlong param_1,short param_2,undefined4 *param_3,undefined4 *param_4)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  ushort uVar7;
  undefined1 auStackY_b8 [32];
  undefined4 *local_88 [2];
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 **local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar1 = *(longlong *)(param_1 + 8);
  uVar7 = 0x800;
  if (param_2 != 2) {
    uVar7 = 0x86dd;
  }
  local_88[0] = param_3;
  if (*(uint *)(lVar1 + 0x28) < 0xe) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar2 = true;
  if (*(uint *)(lVar1 + 0x10) < 0xe) {
    iVar4 = NdisRetreatNetBufferDataStart(lVar1,0xe);
    if (iVar4 != 0) {
      if (DAT_14002a000 < 3) {
        return iVar4;
      }
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_4c = 0;
        local_3c = 0;
        local_58 = "NetioRetreatNetBuffer failed.";
        local_48 = local_88;
        local_50 = 0x1e;
        local_88[0] = (undefined4 *)CONCAT44(local_88[0]._4_4_,iVar4);
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025076,0,0,4,local_78);
      }
      goto LAB_140008bfd;
    }
  }
  else {
    *(int *)(lVar1 + 0x28) = *(int *)(lVar1 + 0x28) + -0xe;
    *(int *)(lVar1 + 0x18) = *(int *)(lVar1 + 0x18) + 0xe;
    *(uint *)(lVar1 + 0x10) = *(uint *)(lVar1 + 0x10) - 0xe;
    iVar4 = 0;
  }
  puVar5 = (undefined4 *)NetioGetDataBufferIfSafe(lVar1);
  if (puVar5 == (undefined4 *)0x0) {
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_4c = 0;
        local_3c = 0;
        local_58 = "FseIpsPrependEthernetHeader: NetioGetDataBufferIfSafe failed";
        local_48 = local_88;
        local_50 = 0x3d;
        local_88[0] = (undefined4 *)CONCAT44(local_88[0]._4_4_,0xc000021b);
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025044,0,0,4,local_78);
      }
    }
  }
  else {
    *(undefined4 *)((longlong)puVar5 + 6) = *local_88[0];
    *(undefined2 *)((longlong)puVar5 + 10) = *(undefined2 *)(local_88[0] + 1);
    *puVar5 = *param_4;
    *(undefined2 *)(puVar5 + 1) = *(undefined2 *)(param_4 + 1);
    *(ushort *)(puVar5 + 3) = uVar7 >> 8 | uVar7 << 8;
  }
  if (*(longlong *)(lVar1 + 8) == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  uVar6 = *(int *)(lVar1 + 0x10) + 0xe;
  if (uVar6 < *(uint *)(*(longlong *)(lVar1 + 8) + 0x28)) {
    *(int *)(lVar1 + 0x28) = *(int *)(lVar1 + 0x28) + 0xe;
    *(int *)(lVar1 + 0x18) = *(int *)(lVar1 + 0x18) + -0xe;
    *(uint *)(lVar1 + 0x10) = uVar6;
    return iVar4;
  }
  NdisAdvanceNetBufferDataStart(lVar1,0xe);
  if (iVar4 == 0) {
    return 0;
  }
LAB_140008bfd:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_4c = 0;
      local_3c = 0;
      local_58 = "FseIpsPrependEthernetHeader returned error";
      local_48 = local_88;
      local_50 = 0x2b;
      local_88[0] = (undefined4 *)CONCAT44(local_88[0]._4_4_,iVar4);
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002500e,0,0,4,local_78);
    }
  }
  return iVar4;
}



===== FseNpiClientNotifyAttachProvider @ 140008cb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140008e43) */
/* WARNING: Removing unreachable block (ram,0x000140008d6a) */
/* WARNING: Removing unreachable block (ram,0x000140008d6e) */
/* WARNING: Removing unreachable block (ram,0x000140008e4b) */

int FseNpiClientNotifyAttachProvider(undefined8 param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  byte *pbVar6;
  longlong lVar7;
  undefined2 *puVar8;
  undefined8 *puVar9;
  undefined1 auStackY_d8 [32];
  int local_a8;
  int local_a4;
  undefined8 local_a0;
  undefined8 local_98 [4];
  int *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar7 = *(longlong *)(param_3 + 0x10);
  puVar8 = (undefined2 *)0x0;
  if (param_2 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  cVar4 = KeGetCurrentIrql();
  if (cVar4 != '\0') {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar3 = true;
  if (*(longlong *)(param_3 + 0x20) == 0) {
LAB_1400090cd:
    iVar5 = -0x3ffffd47;
    if (DAT_14002a000 < 3) goto LAB_14000920f;
    if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    iVar5 = -0x3ffffd47;
    if (bVar2) {
      local_70 = 0x49;
      local_78 = (int *)0x140021a60;
      local_68 = &local_a8;
      local_a8 = -0x3ffffd47;
      local_60 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025393,0,0,4,local_98);
    }
  }
  else {
    sVar1 = *(short *)(*(longlong *)(param_3 + 0x20) + 4);
    if (sVar1 == 2) {
      if ((((*(int *)(lVar7 + 4) != 1) || (*(int *)(lVar7 + 8) != -0x14ffb600)) ||
          (*(int *)(lVar7 + 0xc) != 0x11d49b1a)) ||
         ((*(int *)(lVar7 + 0x10) != 0x50002391 || (*(int *)(lVar7 + 0x14) != -0x43a688fc))))
      goto LAB_140008d7b;
LAB_140008d85:
      lVar7 = 0;
    }
    else {
      if ((((sVar1 != 0x17) || ((*(int *)(lVar7 + 4) != 1 || (*(int *)(lVar7 + 8) != -0x14ffb5ff))))
          || (*(int *)(lVar7 + 0xc) != 0x11d49b1a)) ||
         ((*(int *)(lVar7 + 0x10) != 0x50002391 || (*(int *)(lVar7 + 0x14) != -0x43a688fc)))) {
LAB_140008d7b:
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
        goto LAB_140008d85;
      }
      lVar7 = 1;
    }
    puVar8 = (undefined2 *)(param_2 + (lVar7 * 5 + 1) * 8);
    if (puVar8 == (undefined2 *)0x0) goto LAB_1400090cd;
    if (*(char *)(puVar8 + 1) != '\0') {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    *(undefined8 *)(puVar8 + 0xc) = param_1;
    iVar5 = NmrClientAttachProvider(param_1,puVar8);
    if (iVar5 < 0) {
      FseDiagnosticsLogFailure(7,iVar5);
LAB_140008e6c:
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)
           ) {
          bVar2 = false;
        }
        if (bVar2) {
          local_70 = 0x20;
          local_78 = (int *)0x140021ab0;
          local_68 = &local_a8;
          local_60 = 4;
          local_a8 = iVar5;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025361,0,0,4,local_98);
        }
      }
    }
    else {
      if (iVar5 != 0) goto LAB_140008e6c;
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(param_2,0);
      *(undefined1 *)(puVar8 + 1) = 1;
      if ((*(byte *)(param_2 + 0xc0) & 1) == 0) {
        for (puVar9 = *(undefined8 **)(param_2 + 0xb0); puVar9 != (undefined8 *)(param_2 + 0xb0);
            puVar9 = (undefined8 *)*puVar9) {
          if (*(char *)(lVar7 + 0x16 + (longlong)puVar9) != '\0') {
            iVar5 = (**(code **)(*(longlong *)(puVar8 + 8) + 8))
                              (*(undefined8 *)(puVar8 + 4),puVar9[4]);
            if (iVar5 != 0) {
              if (DAT_14002a000 < 3) goto LAB_140009097;
              if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
                bVar2 = false;
              }
              else {
                bVar2 = true;
              }
              if (!bVar2) goto LAB_140009097;
              pbVar6 = &DAT_14002532f;
              goto LAB_14000903f;
            }
            *(undefined1 *)(lVar7 + 0x14 + (longlong)puVar9) = 1;
          }
        }
        if (*(int *)(param_2 + 0x88) != 0) {
          iVar5 = (**(code **)(*(longlong *)(puVar8 + 8) + 8))
                            (*(undefined8 *)(puVar8 + 4),*(undefined8 *)(param_2 + 0x90));
          if (iVar5 == 0) {
            *(undefined1 *)(lVar7 + 0x84 + param_2) = 1;
          }
          else if (2 < DAT_14002a000) {
            if (((DAT_14002a010 & 4) == 0) ||
               (bVar2 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
              bVar2 = false;
            }
            if (bVar2) {
              pbVar6 = &DAT_1400252fd;
LAB_14000903f:
              local_60 = 4;
              local_78 = (int *)0x140021628;
              local_68 = &local_a8;
              local_70 = 0x2a;
              local_a8 = iVar5;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar6,0,0,4,local_98);
            }
          }
        }
      }
LAB_140009097:
      ExReleasePushLockExclusiveEx(param_2,0);
      KeLeaveCriticalRegion();
    }
    if (-1 < iVar5) goto LAB_14000920f;
  }
  if (2 < DAT_14002a000) {
    if (((CONCAT71(uRam000000014002a011,DAT_14002a010) & 0x400000000004) == 0) ||
       (bVar2 = true, (DAT_14002a018 & 0x400000000004) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_78 = &local_a4;
      local_a8 = CONCAT22(local_a8._2_2_,*puVar8);
      local_68 = &local_a8;
      local_70 = 4;
      local_58 = &local_a0;
      local_60 = 2;
      local_a0 = 0x1000000;
      local_50 = 8;
      local_a4 = iVar5;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002529d,0,0,5,local_98);
    }
  }
LAB_14000920f:
  if ((iVar5 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_70 = 0x30;
      local_78 = (int *)0x140021ad0;
      local_68 = &local_a4;
      local_60 = 4;
      local_a4 = iVar5;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025267,0,0,4,local_98);
    }
  }
  return iVar5;
}



===== FseNpiClientNotifyDetachProvider @ 1400092c0 =====

undefined8 FseNpiClientNotifyDetachProvider(longlong param_1)

{
  IoQueueWorkItem(*(undefined8 *)(param_1 + 0x20),FseNpiClientDetachProviderCompleteWorkerRoutine,1,
                  param_1);
  return 0x103;
}



===== NetioGetDataBufferIfSafe @ 1400092f8 =====

ulonglong NetioGetDataBufferIfSafe(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if ((uint)(*(int *)(lVar1 + 0x28) - *(int *)(param_1 + 0x10)) < 0xe) {
    uVar2 = 0;
  }
  else {
    if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      lVar1 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000000);
    }
    else {
      lVar1 = *(longlong *)(lVar1 + 0x18);
    }
    if (lVar1 == 0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    uVar3 = (ulonglong)*(uint *)(param_1 + 0x10) + lVar1;
    uVar2 = 0;
    if ((uVar3 & 1) == 0) {
      uVar2 = uVar3;
    }
  }
  return uVar2;
}



===== FseLocalServerAcquirePorts @ 140009380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseLocalServerAcquirePorts
                    (longlong param_1,uint param_2,undefined4 param_3,undefined4 *param_4,
                    ulonglong *param_5)

{
  bool bVar1;
  char cVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined1 auStackY_e8 [32];
  int local_b8 [2];
  uint local_b0;
  longlong local_ac;
  undefined8 uStack_a4;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined8 local_88 [4];
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  cVar2 = ExAcquireRundownProtection(&DAT_14002a608);
  if (cVar2 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_8046676e6fcd31b2fa8ceead8ac97718_Traceguids);
    }
    uVar3 = 0xc0000189;
  }
  else {
    local_98 = *param_4;
    plVar4 = (longlong *)(param_1 + 4);
    local_ac = *plVar4;
    uStack_a4 = *(undefined8 *)(param_1 + 0xc);
    bVar1 = true;
    if ((param_2 == 1) ||
       ((((param_2 != 2 && (param_2 != 4)) && (param_2 != 8)) &&
        ((param_2 != 0x10 && (param_2 != 0x20)))))) {
      local_94 = 0;
    }
    else {
      local_94 = 1;
    }
    local_b0 = param_2;
    local_9c = param_3;
    local_90 = FsePortTrackerGetDefaultSharingFlags(param_2);
    uVar3 = FsePortTrackerAcquirePorts(plVar4,&local_b0,1,plVar4,param_5,(ushort *)0x0);
    local_b8[0] = (int)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if ((local_b8[0] != 0) && (ExReleaseRundownProtection(&DAT_14002a608), 2 < DAT_14002a000)) {
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_5c = 0;
        local_4c = 0;
        local_68 = "FseLocalServerAcquirePorts returned error";
        local_58 = local_b8;
        local_60 = 0x2a;
        local_50 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025d09,0,0,4,local_88);
      }
    }
  }
  return uVar3;
}



===== FseLocalServerAcquirePortsEx @ 140009530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseLocalServerAcquirePortsEx
                    (longlong param_1,uint *param_2,byte param_3,ulonglong *param_4,ushort *param_5)

{
  bool bVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  undefined1 auStackY_b8 [32];
  int local_88 [4];
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar4 = param_4;
  cVar2 = ExAcquireRundownProtection(&DAT_14002a608);
  if (cVar2 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_8046676e6fcd31b2fa8ceead8ac97718_Traceguids);
    }
    uVar3 = 0xc0000189;
  }
  else {
    uVar3 = FsePortTrackerAcquirePorts
                      ((longlong *)(param_1 + 4),param_2,param_3,puVar4,param_4,param_5);
    local_88[0] = (int)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if ((local_88[0] != 0) && (ExReleaseRundownProtection(&DAT_14002a608), 2 < DAT_14002a000)) {
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_4c = 0;
        local_3c = 0;
        local_58 = "FseLocalServerAcquirePortsEx returned error";
        local_48 = local_88;
        local_50 = 0x2c;
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025cd3,0,0,4,local_78);
      }
    }
  }
  return uVar3;
}



===== FseLocalServerAttachClient @ 1400096b0 =====

undefined8
FseLocalServerAttachClient
          (undefined8 param_1,undefined8 param_2,short *param_3,undefined8 param_4,longlong param_5,
          undefined8 *param_6,undefined8 *param_7)

{
  uint *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  
  *param_6 = 0;
  *param_7 = 0;
  if (*param_3 == 1) {
    if (((param_5 == 0) && (puVar1 = *(uint **)(param_3 + 0x10), puVar1 != (uint *)0x0)) &&
       (0x13 < *puVar1)) {
      puVar4 = (undefined4 *)ExAllocatePool2(0x40,0x20,0x534c7346);
      if (puVar4 == (undefined4 *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                  &WPP_8046676e6fcd31b2fa8ceead8ac97718_Traceguids);
        }
        uVar3 = 0xc0000017;
      }
      else {
        *puVar4 = 0x43437346;
        uVar3 = *(undefined8 *)(puVar1 + 1);
        uVar2 = *(undefined8 *)(puVar1 + 3);
        *(undefined8 *)(puVar4 + 6) = param_4;
        *(undefined8 *)(puVar4 + 1) = uVar3;
        *(undefined8 *)(puVar4 + 3) = uVar2;
        *param_6 = puVar4;
        *param_7 = &PTR_FseLocalServerAcquirePorts_140020068;
        uVar3 = 0;
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_8046676e6fcd31b2fa8ceead8ac97718_Traceguids);
      }
      uVar3 = 0xc000000d;
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_8046676e6fcd31b2fa8ceead8ac97718_Traceguids);
    }
    uVar3 = 0xc0000058;
  }
  return uVar3;
}



===== FseLocalServerDetachClient @ 140009800 =====

undefined8 FseLocalServerDetachClient(uint *param_1)

{
  *param_1 = *param_1 | 0x80;
  ExFreePoolWithTag(param_1,0x534c7346);
  return 0;
}



===== FseLocalServerReleasePorts @ 140009830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseLocalServerReleasePorts(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  bool bVar1;
  ulonglong uVar2;
  undefined1 auStackY_98 [32];
  int local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar2 = FsePortTrackerReleasePortRange((longlong *)(param_1 + 4),param_2,param_3);
  local_68[0] = (int)uVar2;
  if (local_68[0] == 0) {
    ExReleaseRundownProtection(&DAT_14002a608);
  }
  else if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseLocalServerReleasePorts returned error";
      local_28 = local_68;
      local_30 = 0x2a;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025c9d,0,0,4,local_58);
    }
  }
  return uVar2 & 0xffffffff;
}



===== WPP_SF_ @ 140009928 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140009954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== FsePortPolicyApplyForPartition @ 140009998 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FsePortPolicyApplyForPartition(longlong *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  bool bVar6;
  longlong lVar7;
  longlong lVar8;
  uint *puVar9;
  longlong *plVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ushort *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  ulonglong uVar16;
  ushort uVar17;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  ushort local_a8 [2];
  undefined4 local_a4;
  ushort local_a0;
  ushort local_9e;
  uint *local_98;
  longlong *local_90;
  undefined8 local_88 [4];
  char *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  ushort *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  lVar8 = DAT_14002a7b8;
  puVar14 = auStackY_e8;
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = (uint *)0x0;
  uVar16 = 0;
  puVar15 = auStackY_e8;
  if (((DAT_14002a7b8 != 0) &&
      (puVar13 = *(ushort **)(DAT_14002a7b8 + 8), puVar15 = auStackY_e8, puVar13 != (ushort *)0x0))
     && (uVar17 = 0, puVar15 = auStackY_e8, *puVar13 != 0)) {
    bVar6 = true;
    uVar12 = DAT_14002a018;
    do {
      uVar11 = (ulonglong)uVar17;
      if (*(int *)(puVar13 + uVar11 * 5 + 1) == 1) {
        local_90 = (longlong *)0x0;
        if (4 < DAT_14002a000) {
          if (((uRam000000014002a011 & 0x400) == 0) ||
             (bVar5 = true, ((uint)uVar12 & 0x40000) != uVar12)) {
            bVar5 = false;
          }
          if (bVar5) {
            local_60 = 0x2f;
            local_68 = "Attempting creation of a Deliver-To-Root patch";
            local_a4 = *(undefined4 *)(puVar13 + uVar11 * 5 + 3);
            local_58 = &local_a4;
            local_50 = 4;
            local_a8[0] = puVar13[uVar11 * 5 + 5];
            local_48 = local_a8;
            local_40 = 2;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025e76,0,0,5,local_88);
          }
        }
        local_a0 = puVar13[uVar11 * 5 + 5];
        local_9e = local_a0;
        uVar12 = FseAllocatorCreatePatch
                           (param_1,0,(ulonglong)*(uint *)(puVar13 + uVar11 * 5 + 3),&local_a0,0,0,
                            &local_98);
        puVar9 = local_98;
        uVar16 = uVar12 & 0xffffffff;
        puVar15 = auStackY_e8;
        if ((int)uVar12 == 0) {
          if (local_98 == (uint *)0x0) {
            MicrosoftTelemetryAssertTriggeredNoArgsKM();
          }
          uVar12 = FseAllocMemory(0x30,0x70507346,&local_90);
          plVar10 = local_90;
          uVar16 = uVar12 & 0xffffffff;
          if ((int)uVar12 == 0) {
            local_98 = (uint *)0x0;
            local_90[2] = (longlong)puVar9;
            *(ushort *)(local_90 + 3) = uVar17;
            uVar3 = *(undefined4 *)((longlong)param_1 + 4);
            lVar7 = param_1[1];
            uVar4 = *(undefined4 *)((longlong)param_1 + 0xc);
            *(int *)((longlong)local_90 + 0x1c) = (int)*param_1;
            *(undefined4 *)(local_90 + 4) = uVar3;
            *(int *)((longlong)local_90 + 0x24) = (int)lVar7;
            *(undefined4 *)(local_90 + 5) = uVar4;
            KeAcquireSpinLockRaiseToDpc(lVar8);
            plVar1 = *(longlong **)(lVar8 + 0x20);
            if (*plVar1 == lVar8 + 0x18) {
              *plVar10 = lVar8 + 0x18;
              plVar10[1] = (longlong)plVar1;
              *plVar1 = (longlong)plVar10;
              *(longlong **)(lVar8 + 0x20) = plVar10;
              *(short *)(lVar8 + 0x10) = *(short *)(lVar8 + 0x10) + 1;
              KeReleaseSpinLock(lVar8);
              uVar12 = DAT_14002a018;
              if (5 < DAT_14002a000) {
                if (((uRam000000014002a011 & 0x400) == 0) ||
                   (((uint)DAT_14002a018 & 0x40000) != DAT_14002a018)) {
                  bVar5 = false;
                }
                else {
                  bVar5 = true;
                }
                if (bVar5) {
                  local_60 = 0x2d;
                  local_68 = "Successfully created a Deliver-To-Root patch";
                  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025e16,0,0,3,local_88);
                  uVar12 = DAT_14002a018;
                }
              }
              goto LAB_140009c05;
            }
            pcVar2 = (code *)swi(0x29);
            (*pcVar2)(3);
            puVar15 = auStackY_e0;
            goto LAB_140009c23;
          }
        }
        else {
LAB_140009c23:
          puVar14 = puVar15;
          if (2 < DAT_14002a000) {
            if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
              bVar6 = false;
            }
            if (bVar6) {
              local_68 = "L\"FseAllocatorCreatePatch\" failed.";
              local_58 = &local_a4;
              local_60 = 0x23;
              local_a4 = (undefined4)uVar16;
              *(undefined8 **)(puVar14 + 0x28) = local_88;
              *(undefined4 *)(puVar14 + 0x20) = 4;
              local_50 = 4;
              *(undefined8 *)(puVar14 + -8) = 0x140009ca6;
              _tlgWriteTransfer_EtwWriteTransfer
                        (0x14002a000,&DAT_140025e44,0,0,*(undefined4 *)(puVar14 + 0x20),
                         *(undefined8 **)(puVar14 + 0x28));
            }
          }
        }
        puVar15 = puVar14;
        if (puVar9 != (uint *)0x0) {
          *(undefined8 *)(puVar14 + -8) = 0x140009cb3;
          FseAllocatorDestroyPatch(puVar9);
        }
        break;
      }
LAB_140009c05:
      puVar13 = *(ushort **)(lVar8 + 8);
      uVar17 = uVar17 + 1;
      puVar15 = auStackY_e8;
    } while (uVar17 < *puVar13);
  }
  *(undefined8 *)(puVar15 + -8) = 0x140009cc1;
  return uVar16;
}



===== FsePortPolicyConfigure @ 140009cec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FsePortPolicyConfigure(uint param_1,ushort *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined1 uVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong lVar13;
  byte *pbVar14;
  undefined8 uVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  uint *puVar19;
  ushort *puVar20;
  ushort uVar21;
  undefined1 auStackY_f8 [8];
  undefined1 auStackY_f0 [24];
  ushort *local_b8;
  ushort local_b0 [4];
  undefined8 local_a8;
  uint *local_a0;
  longlong *local_98 [2];
  undefined8 local_88 [4];
  char *local_68;
  undefined8 local_60;
  ushort **local_58;
  undefined8 local_50;
  ushort *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  lVar5 = DAT_14002a7b8;
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b8 = (ushort *)0x0;
  iVar9 = 0;
  local_a0 = (uint *)0x0;
  local_98[0] = (longlong *)0x0;
  if (param_2 == (ushort *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (lVar5 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar17 = auStackY_f8;
  uVar21 = *param_2;
  puVar18 = auStackY_f8;
  if (uVar21 == 0) goto LAB_14000a437;
  local_a8 = (ushort *)0x0;
  bVar4 = true;
  uVar10 = SUB168(ZEXT216(uVar21) * ZEXT816(10),0);
  uVar8 = (uint)DAT_14002a018;
  if (SUB168(ZEXT216(uVar21) * ZEXT816(10),8) == 0) {
    uVar12 = uVar10 + 2;
    if (uVar12 < uVar10) {
      iVar9 = -0x3fffff6b;
      puVar18 = auStackY_f8;
      if (DAT_14002a000 < 3) goto LAB_14000a437;
      if (((DAT_14002a010 & 4) == 0) || (bVar3 = true, (uVar8 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      puVar17 = auStackY_f8;
      if (bVar3) {
        local_68 = "L\"RtlSizeTAdd\" failed.";
        local_60 = 0x17;
        pbVar14 = &DAT_14002601e;
        goto LAB_14000a380;
      }
    }
    else if (param_1 == uVar12) {
      uVar11 = FseAllocMemory((ulonglong)uVar21 * 10 + 2,0x70507346,&local_b8);
      puVar20 = local_b8;
      iVar9 = (int)uVar11;
      if (iVar9 == 0) {
        *local_b8 = *param_2;
        memmove(local_b8 + 1,param_2 + 1,(ulonglong)*param_2 * 10);
        uVar7 = KeAcquireSpinLockRaiseToDpc(lVar5);
        if (*(longlong *)(lVar5 + 8) == 0) {
          *(ushort **)(lVar5 + 8) = puVar20;
          KeReleaseSpinLock(lVar5,uVar7);
          puVar16 = auStackY_f8;
          puVar17 = auStackY_f8;
          puVar20 = *(ushort **)(lVar5 + 8);
          uVar21 = 0;
          puVar18 = auStackY_f8;
          if (*puVar20 != 0) {
            uVar10 = DAT_14002a018;
            do {
              uVar12 = (ulonglong)uVar21;
              if (*(int *)(puVar20 + uVar12 * 5 + 1) == 0) {
                if (4 < DAT_14002a000) {
                  if (((uRam000000014002a011 & 0x400) == 0) ||
                     (bVar3 = true, ((uint)uVar10 & 0x40000) != uVar10)) {
                    bVar3 = false;
                  }
                  if (bVar3) {
                    local_60 = 0x3c;
                    local_68 = "Attempting creation of a Allow-Bind-in-all-Partitions patch";
                    local_b8 = (ushort *)
                               CONCAT44(local_b8._4_4_,*(undefined4 *)(puVar20 + uVar12 * 5 + 3));
                    local_58 = &local_b8;
                    local_50 = 4;
                    local_b0[0] = puVar20[uVar12 * 5 + 5];
                    local_48 = local_b0;
                    local_40 = 2;
                    _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025f7c,0,0,5,local_88);
                  }
                }
                uVar15 = 0x70507346;
                uVar11 = FseAllocMemory(0x30,0x70507346,local_98);
                iVar9 = (int)uVar11;
                if (iVar9 != 0) goto LAB_140009f0a;
                local_a8._0_4_ = CONCAT22(puVar20[uVar12 * 5 + 5],puVar20[uVar12 * 5 + 5]);
                uVar11 = FseAllocatorCreatePatch
                                   ((longlong *)0x0,uVar15,
                                    (ulonglong)*(uint *)(puVar20 + uVar12 * 5 + 3),
                                    (ushort *)&local_a8,2,4,&local_a0);
                puVar19 = local_a0;
                iVar9 = (int)uVar11;
                if (iVar9 == 0) {
                  if (local_a0 == (uint *)0x0) {
                    MicrosoftTelemetryAssertTriggeredNoArgsKM();
                  }
                  lVar13 = FseAllocatorGetPool(puVar19[9]);
                  puVar18 = auStackY_f8;
                  if (lVar13 != 0) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                               &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,puVar19);
                    }
                    FsePortPoolEnumReservations(lVar13,FseAllocatorApplyPatchToAcquisition,puVar19);
                    FsePortPoolSetCacheDirty(lVar13);
                    plVar6 = local_98[0];
                    iVar9 = 0;
                    local_a0 = (uint *)0x0;
                    local_98[0][2] = (longlong)puVar19;
                    *(ushort *)(local_98[0] + 3) = uVar21;
                    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar5);
                    plVar1 = *(longlong **)(lVar5 + 0x20);
                    if (*plVar1 == lVar5 + 0x18) {
                      *plVar6 = lVar5 + 0x18;
                      plVar6[1] = (longlong)plVar1;
                      *plVar1 = (longlong)plVar6;
                      *(longlong **)(lVar5 + 0x20) = plVar6;
                      *(short *)(lVar5 + 0x10) = *(short *)(lVar5 + 0x10) + 1;
                      local_98[0] = (longlong *)0x0;
                      KeReleaseSpinLock(lVar5,CONCAT71((int7)((ulonglong)plVar1 >> 8),uVar7));
                      uVar10 = DAT_14002a018;
                      if (5 < DAT_14002a000) {
                        if (((uRam000000014002a011 & 0x400) == 0) ||
                           (bVar3 = true, ((uint)DAT_14002a018 & 0x40000) != DAT_14002a018)) {
                          bVar3 = false;
                        }
                        if (bVar3) {
                          local_60 = 0x3a;
                          local_68 = "Successfully created a Allow-Bind-in-all-Partitions patch";
                          _tlgWriteTransfer_EtwWriteTransfer
                                    (0x14002a000,&DAT_140025eea,0,0,3,local_88);
                          uVar10 = DAT_14002a018;
                        }
                      }
                      goto LAB_14000a1a1;
                    }
                    pcVar2 = (code *)swi(0x29);
                    (*pcVar2)(3);
                    puVar18 = auStackY_f0;
                  }
                  puVar16 = puVar18;
                  iVar9 = -0x3ffffff3;
                  if (2 < DAT_14002a000) {
                    if (((DAT_14002a010 & 4) == 0) ||
                       (bVar3 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
                      bVar3 = false;
                    }
                    if (bVar3) {
                      local_b8 = (ushort *)CONCAT44(local_b8._4_4_,0xc000000d);
                      local_68 = "L\"FseAllocatorApplyPatchRetroactively\" failed.";
                      local_58 = &local_b8;
                      local_60 = 0x2f;
                      local_50 = 4;
                      *(undefined8 **)(puVar16 + 0x28) = local_88;
                      *(undefined4 *)(puVar16 + 0x20) = 4;
                      *(undefined8 *)(puVar16 + -8) = 0x14000a24d;
                      _tlgWriteTransfer_EtwWriteTransfer
                                (0x14002a000,&DAT_140025f18,0,0,*(undefined4 *)(puVar16 + 0x20),
                                 *(undefined8 **)(puVar16 + 0x28));
                    }
                  }
                }
                else {
                  if (2 < DAT_14002a000) {
                    if (((DAT_14002a010 & 4) == 0) ||
                       (bVar3 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
                      bVar3 = false;
                    }
                    if (bVar3) {
                      local_60 = 0x23;
                      local_68 = "L\"FseAllocatorCreatePatch\" failed.";
                      local_58 = &local_b8;
                      local_b8 = (ushort *)CONCAT44(local_b8._4_4_,iVar9);
                      local_50 = 4;
                      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025f4a,0,0,4,local_88);
                    }
                  }
                  puVar19 = local_a0;
                }
                goto LAB_140009efd;
              }
LAB_14000a1a1:
              puVar20 = *(ushort **)(lVar5 + 8);
              uVar21 = uVar21 + 1;
              puVar18 = auStackY_f8;
            } while (uVar21 < *puVar20);
          }
          goto LAB_14000a437;
        }
        KeReleaseSpinLock();
        iVar9 = 0x40000000;
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) ||
             (bVar3 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar3 = false;
          }
          if (bVar3) {
            local_60 = 0x40;
            local_68 = "FsePortPolicyConfigurePort Policy Configuration already exists.";
            local_58 = (ushort **)&local_a8;
            local_a8 = (ushort *)CONCAT44(local_a8._4_4_,0x40000000);
            local_50 = 4;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025fba,0,0,4,local_88);
          }
        }
      }
      puVar17 = auStackY_f8;
      if (puVar20 != (ushort *)0x0) {
        FseFreeMemory((longlong *)&local_b8);
        puVar16 = auStackY_f8;
        puVar19 = (uint *)0x0;
LAB_140009efd:
        puVar17 = puVar16;
        if (puVar19 != (uint *)0x0) {
          *(undefined8 *)(puVar16 + -8) = 0x140009f0a;
          FseAllocatorDestroyPatch(puVar19);
        }
LAB_140009f0a:
        if (local_98[0] != (longlong *)0x0) {
          *(undefined8 *)(puVar17 + -8) = 0x140009f19;
          FseFreeMemory((longlong *)local_98);
        }
        puVar18 = puVar17;
        if (iVar9 == 0) goto LAB_14000a437;
      }
    }
    else {
      iVar9 = -0x3ffffff3;
      puVar18 = auStackY_f8;
      if (DAT_14002a000 < 3) goto LAB_14000a437;
      if (((DAT_14002a010 & 4) == 0) || (bVar3 = true, (uVar8 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      puVar17 = auStackY_f8;
      if (bVar3) {
        local_a8 = (ushort *)0xc000000d;
        local_68 = "FsePortPolicyConfigureInvalid buffer length in Port Policy Configuration";
        pbVar14 = &DAT_140025fec;
        local_58 = (ushort **)&local_a8;
        local_60 = 0x49;
        goto LAB_14000a38b;
      }
    }
  }
  else {
    iVar9 = -0x3fffff6b;
    puVar18 = auStackY_f8;
    if (DAT_14002a000 < 3) goto LAB_14000a437;
    if (((DAT_14002a010 & 4) == 0) || (bVar3 = true, (uVar8 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_68 = "L\"RtlSizeTMult\" failed.";
      local_60 = 0x18;
      pbVar14 = &DAT_140026050;
LAB_14000a380:
      iVar9 = -0x3fffff6b;
      local_58 = &local_b8;
      local_b8 = (ushort *)CONCAT44(local_b8._4_4_,0xc0000095);
LAB_14000a38b:
      local_50 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar14,0,0,4,local_88);
      puVar17 = auStackY_f8;
    }
  }
  puVar18 = puVar17;
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar4 = false;
    }
    if (bVar4) {
      local_60 = 0x26;
      local_68 = "FsePortPolicyConfigure returned error";
      local_58 = &local_b8;
      local_b8 = (ushort *)CONCAT44(local_b8._4_4_,iVar9);
      local_50 = 4;
      *(undefined8 **)(puVar17 + 0x28) = local_88;
      *(undefined4 *)(puVar17 + 0x20) = 4;
      *(undefined8 *)(puVar17 + -8) = 0x14000a437;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x14002a000,&DAT_140025eb4,0,0,*(undefined4 *)(puVar17 + 0x20),
                 *(undefined8 **)(puVar17 + 0x28));
    }
  }
LAB_14000a437:
  *(undefined8 *)(puVar18 + -8) = 0x14000a445;
  return iVar9;
}



===== FsePortPolicyEnum @ 14000a470 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FsePortPolicyEnum(undefined2 *param_1,ulonglong *param_2,void *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  ushort uVar3;
  longlong lVar4;
  undefined8 uVar5;
  bool bVar6;
  bool bVar7;
  longlong lVar8;
  void *pvVar9;
  longlong *plVar10;
  int iVar11;
  ushort uVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined1 auStackY_c8 [32];
  int local_94;
  void *local_90;
  undefined8 local_88 [4];
  char *local_68;
  undefined8 local_60;
  int *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  lVar8 = DAT_14002a7b8;
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_94 = 0;
  uVar12 = 0;
  local_90 = param_3;
  KeAcquireSpinLockRaiseToDpc(DAT_14002a7b8);
  bVar7 = true;
  uVar13 = (ulonglong)*(ushort *)(lVar8 + 0x10) * 0x1a;
  if ((local_90 == (void *)0x0) || (*param_2 < uVar13)) {
    *param_2 = uVar13;
    iVar11 = -0x7ffffffb;
    *param_1 = *(undefined2 *)(lVar8 + 0x10);
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (bVar6 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018))
      {
        bVar6 = false;
      }
      if (bVar6) {
        local_60 = 0x41;
        local_68 = "FsePortPolicyEnum: Output buffer provided by caller is too small";
        local_58 = &local_94;
        local_94 = -0x7ffffffb;
        local_50 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025de4,0,0,4,local_88);
      }
    }
  }
  else {
    memset(local_90,0,*param_2);
    pvVar9 = local_90;
    *param_2 = uVar13;
    *param_1 = *(undefined2 *)(lVar8 + 0x10);
    plVar1 = (longlong *)(lVar8 + 0x18);
    plVar10 = (longlong *)*plVar1;
    iVar11 = 0;
    if (plVar10 != plVar1) {
      do {
        uVar5 = *(undefined8 *)((longlong)plVar10 + 0x24);
        lVar14 = (ulonglong)uVar12 * 0x1a;
        puVar2 = (undefined8 *)(lVar14 + 10 + (longlong)pvVar9);
        *puVar2 = *(undefined8 *)((longlong)plVar10 + 0x1c);
        puVar2[1] = uVar5;
        if (*(longlong *)(lVar8 + 8) == 0) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        if (**(ushort **)(lVar8 + 8) <= *(ushort *)(plVar10 + 3)) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        uVar3 = *(ushort *)(plVar10 + 3);
        uVar12 = uVar12 + 1;
        lVar4 = *(longlong *)(lVar8 + 8);
        *(undefined8 *)(lVar14 + (longlong)pvVar9) =
             *(undefined8 *)(lVar4 + 2 + (ulonglong)uVar3 * 10);
        *(undefined2 *)(lVar14 + 8 + (longlong)pvVar9) =
             *(undefined2 *)(lVar4 + 10 + (ulonglong)uVar3 * 10);
        plVar10 = (longlong *)*plVar10;
      } while (plVar10 != plVar1);
      iVar11 = local_94;
    }
  }
  KeReleaseSpinLock(lVar8);
  if ((iVar11 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar7 = false;
    }
    if (bVar7) {
      local_60 = 0x21;
      local_68 = "FsePortPolicyEnum returned error";
      local_58 = &local_94;
      local_50 = 4;
      local_94 = iVar11;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025dae,0,0,4,local_88);
    }
  }
  return iVar11;
}



===== FsePortPolicyInitialize @ 14000a6d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FsePortPolicyInitialize(void)

{
  longlong lVar1;
  bool bVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  undefined1 auStackY_98 [32];
  longlong local_68 [2];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_68[0] = 0;
  uVar5 = FseAllocMemory(0x28,0x70507346,local_68);
  lVar3 = local_68[0];
  iVar4 = (int)uVar5;
  if (iVar4 == 0) {
    KeInitializeSpinLock(local_68[0]);
    lVar1 = lVar3 + 0x18;
    *(longlong *)(lVar3 + 0x20) = lVar1;
    *(longlong *)lVar1 = lVar1;
    local_68[0] = 0;
    DAT_14002a7b8 = lVar3;
  }
  if (local_68[0] != 0) {
    FsePortPolicyUninitialize(local_68[0]);
    FseFreeMemory(local_68);
  }
  if ((iVar4 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FsePortPolicyInitialize returned error";
      local_28 = local_68;
      local_30 = 0x27;
      local_68[0] = CONCAT44(local_68[0]._4_4_,iVar4);
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026082,0,0,4,local_58);
    }
  }
  return uVar5 & 0xffffffff;
}



===== FsePortPolicyRemoveForPartition @ 14000a818 =====

void FsePortPolicyRemoveForPartition(longlong *param_1)

{
  undefined8 ******ppppppuVar1;
  undefined8 ******ppppppuVar2;
  undefined8 *****pppppuVar3;
  code *pcVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined8 ******local_res10;
  undefined8 ******local_18;
  undefined8 ******local_10;
  
  lVar5 = DAT_14002a7b8;
  local_10 = &local_18;
  local_18 = &local_18;
  uVar6 = KeAcquireSpinLockRaiseToDpc(DAT_14002a7b8);
  ppppppuVar2 = *(undefined8 *******)(lVar5 + 0x18);
  while (ppppppuVar1 = ppppppuVar2, ppppppuVar1 != (undefined8 ******)(lVar5 + 0x18)) {
    ppppppuVar2 = (undefined8 ******)*ppppppuVar1;
    if ((*param_1 == *(longlong *)((longlong)ppppppuVar1 + 0x1c)) &&
       (param_1[1] == *(longlong *)((longlong)ppppppuVar1 + 0x24))) {
      if (((undefined8 ******)ppppppuVar2[1] != ppppppuVar1) ||
         (pppppuVar3 = ppppppuVar1[1], (undefined8 ******)*pppppuVar3 != ppppppuVar1))
      goto LAB_14000a923;
      *pppppuVar3 = ppppppuVar2;
      ppppppuVar2[1] = pppppuVar3;
      *(short *)(lVar5 + 0x10) = *(short *)(lVar5 + 0x10) + -1;
      if ((undefined8 *******)local_18[1] != &local_18) goto LAB_14000a923;
      *ppppppuVar1 = local_18;
      ppppppuVar1[1] = &local_18;
      local_18[1] = ppppppuVar1;
      local_18 = ppppppuVar1;
    }
  }
  KeReleaseSpinLock(lVar5,CONCAT71((int7)((ulonglong)ppppppuVar1 >> 8),uVar6));
  while( true ) {
    if ((undefined8 *******)local_18 == &local_18) {
      return;
    }
    if (((undefined8 *******)local_18[1] != &local_18) ||
       (ppppppuVar2 = (undefined8 ******)*local_18, (undefined8 ******)ppppppuVar2[1] != local_18))
    break;
    ppppppuVar2[1] = &local_18;
    ppppppuVar1 = local_18 + 2;
    local_res10 = local_18;
    local_18 = ppppppuVar2;
    if (*ppppppuVar1 != (undefined8 *****)0x0) {
      FseAllocatorDestroyPatch((uint *)*ppppppuVar1);
    }
    FseFreeMemory((longlong *)&local_res10);
  }
LAB_14000a923:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== FsePortPolicyRundownHelper @ 14000a944 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FsePortPolicyRundownHelper(void)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStackY_a8 [32];
  short local_78 [4];
  ulonglong local_70;
  void *local_68 [2];
  undefined8 local_58 [4];
  short *local_38;
  undefined8 local_30;
  void *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_78[0] = 0;
  local_70 = 0;
  local_68[0] = (void *)0x0;
  iVar3 = FsePortPolicyEnum(local_78,&local_70,(void *)0x0);
  if (iVar3 != -0x7ffffffb) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if ((local_70 != 0) && (local_78[0] != 0)) {
    uVar4 = FseAllocMemory(local_70,0x70507346,local_68);
    pvVar2 = local_68[0];
    if ((int)uVar4 == 0) {
      iVar3 = FsePortPolicyEnum(local_78,&local_70,local_68[0]);
      if ((iVar3 == 0) && (4 < DAT_14002a000)) {
        if (((_DAT_14002a010 & 0x80000) == 0) ||
           (bVar1 = true, (DAT_14002a018 & 0x80000) != DAT_14002a018)) {
          bVar1 = false;
        }
        if (bVar1) {
          local_38 = local_78;
          local_30 = 2;
          local_20 = (undefined4)local_70;
          local_28 = pvVar2;
          local_1c = 0;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025d3f,0,0,4,local_58);
        }
      }
    }
    if (pvVar2 != (void *)0x0) {
      FseFreeMemory((longlong *)local_68);
    }
  }
  return;
}



===== FsePortPolicyUninitialize @ 14000aa88 =====

void FsePortPolicyUninitialize(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 *puVar5;
  longlong local_res8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar5 = auStack_28;
  plVar1 = (longlong *)(param_1 + 0x18);
  do {
    plVar2 = (longlong *)*plVar1;
    if (plVar2 == plVar1) {
LAB_14000aae7:
      plVar1 = (longlong *)(param_1 + 8);
      if (*plVar1 != 0) {
        *(undefined8 *)(puVar5 + -8) = 0x14000aaf9;
        FseFreeMemory(plVar1);
        *plVar1 = 0;
      }
      return;
    }
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar5 = auStack_20;
      goto LAB_14000aae7;
    }
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    local_res8 = (longlong)plVar2;
    if ((uint *)plVar2[2] != (uint *)0x0) {
      FseAllocatorDestroyPatch((uint *)plVar2[2]);
    }
    FseFreeMemory(&local_res8);
  } while( true );
}



===== FseDemuxShimProcessInboundNblChain @ 14000ab10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FseDemuxShimProcessInboundNblChain(longlong *param_1,longlong param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  short sVar6;
  ushort uVar7;
  ushort uVar8;
  undefined1 auStackY_1f8 [32];
  ushort local_1c8;
  ushort local_1c6;
  short local_1c4 [2];
  uint local_1c0 [2];
  longlong *local_1b8;
  undefined1 local_1b0;
  undefined4 local_1af;
  undefined2 local_1ab;
  undefined1 local_1a9;
  undefined8 local_1a8;
  undefined8 *local_1a0;
  undefined1 local_198;
  undefined4 local_197;
  undefined2 local_193;
  undefined1 local_191;
  undefined8 local_190;
  undefined8 *local_188;
  undefined1 local_180;
  undefined4 local_17f;
  undefined2 local_17b;
  undefined1 local_179;
  undefined8 local_178;
  undefined8 *local_170;
  undefined8 *local_168 [2];
  longlong *local_158 [6];
  undefined8 local_128;
  undefined8 uStack_120;
  undefined1 local_108 [21];
  byte local_f3;
  int local_d8;
  char local_c4;
  byte local_bc;
  undefined8 local_98 [4];
  char *local_78;
  undefined8 local_70;
  undefined8 **local_68;
  undefined8 local_60;
  undefined8 **local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_1af = 0;
  local_1ab = 0;
  local_1b0 = 0;
  local_180 = 0;
  uVar8 = 0;
  local_198 = 0;
  sVar6 = 0;
  local_1c4[0] = 0;
  local_1c6 = 0;
  uVar7 = 0;
  local_1c8 = 0;
  local_1a9 = 0;
  local_17f = 0;
  local_17b = 0;
  local_179 = 0;
  local_197 = 0;
  local_193 = 0;
  local_191 = 0;
  local_1b8 = param_1;
  memset(local_158,0,0x50);
  if (param_2 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar5 = *(undefined8 **)(param_2 + 8);
  if (puVar5 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  local_1a0 = &local_1a8;
  local_170 = &local_178;
  local_188 = &local_190;
  local_128 = 0x4a10dd56e0e16197;
  uStack_120 = 0x38a855a1e75e9591;
  local_1a8 = 0;
  local_178 = 0;
  local_190 = 0;
  local_158[0] = param_1;
  do {
    if (puVar5 == (undefined8 *)0x0) {
      if ((uint)local_1c8 != (uint)local_1c6 + (uint)uVar8 + (uint)uVar7) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      if (uVar8 != 0) {
        FseShimsProcessFloodNblChain(param_1,(longlong)&local_1b0,(uint)uVar8);
      }
      if (sVar6 != 0) {
        FseShimsProcessSteerNblChain((longlong)&local_180,sVar6);
      }
      if (uVar7 != 0) {
        FseIpsClientReturnNblChain(param_1,(longlong)&local_198,(uint)uVar7);
      }
      return;
    }
    memset(local_108,0,0x68);
    puVar4 = (undefined8 *)*puVar5;
    local_1c8 = local_1c8 + 1;
    *puVar5 = 0;
    uVar2 = FseIpsClientParseNbl(param_1,(longlong)puVar5);
    if (uVar2 == 0) {
      iVar3 = 0;
      if (local_d8 == 2) {
LAB_14000adc8:
        iVar3 = 2;
      }
      else if (local_d8 == 0x3a) {
        if ((((local_bc & 1) == 0) && (local_c4 != -0x80)) && (1 < (byte)(local_c4 + 0x7bU)))
        goto LAB_14000adc8;
      }
      else if (local_d8 == 1) {
        if (local_c4 != '\b') goto LAB_14000adc8;
      }
      else if ((local_d8 == 6) || (local_d8 == 0x11)) {
        iVar3 = 1;
      }
      if (iVar3 == 0) goto LAB_14000ad09;
      if (iVar3 == 1) {
        FseShimsUpdateAndProcessSteerChain
                  ((longlong)puVar5,(longlong)local_108,local_158,(longlong)&local_180,local_1c4);
        local_1c6 = local_1c6 + 1;
        sVar6 = local_1c4[0];
      }
      else if (iVar3 == 2) {
        uVar8 = uVar8 + 1;
        *local_1a0 = puVar5;
        local_1a0 = puVar5;
      }
      else {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
    }
    else {
      if (2 < DAT_14002a000) {
        if (((uRam000000014002a011 & 0x200) == 0) || ((DAT_14002a018 & 0x20000) != DAT_14002a018)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_70 = 0x22;
          local_78 = "Parsing Failed for Inbound Packet";
          local_68 = local_168;
          local_58 = (undefined8 **)local_1c0;
          local_60 = 8;
          local_50 = 4;
          local_1c0[0] = uVar2;
          local_168[0] = puVar5;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026305,0,0,5,local_98);
        }
      }
      iVar3 = 0;
LAB_14000ad09:
      uVar7 = uVar7 + 1;
      *local_188 = puVar5;
      local_188 = puVar5;
    }
    if (local_f3 == 1) {
      do {
        if (puVar4 == (undefined8 *)0x0) goto LAB_14000aff7;
        puVar5 = (undefined8 *)*puVar4;
        *puVar4 = 0;
        if (local_1b8 == (longlong *)0x0) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        if (puVar4[1] == 0) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        uVar2 = NetioParseIpFieldsFromNetBuffer(puVar4[1]);
        if ((uVar2 != 0) && (2 < DAT_14002a000)) {
          if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            local_70 = 0x28;
            local_78 = "NetioParseIpFieldsFromNetBuffer failed.";
            local_68 = (undefined8 **)local_1c0;
            local_60 = 4;
            local_1c0[0] = uVar2;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025146,0,0,4,local_98);
          }
          if (2 < DAT_14002a000) {
            if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              local_70 = 0x30;
              local_78 = "FseIpsClientParseIpFieldsFromNbl returned error";
              local_68 = (undefined8 **)local_1c0;
              local_60 = 4;
              local_1c0[0] = uVar2;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025110,0,0,4,local_98);
            }
          }
        }
        if (((int)uVar2 < 0) || (local_f3 == 0)) {
          *puVar4 = puVar5;
          goto LAB_14000aff7;
        }
        local_1c8 = local_1c8 + 1;
        if (1 < (byte)(local_f3 - 1)) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        if (iVar3 == 0) {
          uVar7 = uVar7 + 1;
          *local_188 = puVar4;
          local_188 = puVar4;
        }
        else if (iVar3 == 1) {
          sVar6 = sVar6 + 1;
          local_1c6 = local_1c6 + 1;
          *local_170 = puVar4;
          local_1c4[0] = sVar6;
          local_170 = puVar4;
        }
        else if (iVar3 == 2) {
          uVar8 = uVar8 + 1;
          *local_1a0 = puVar4;
          local_1a0 = puVar4;
        }
        puVar4 = puVar5;
      } while (local_f3 == 1);
LAB_14000affc:
      puVar4 = puVar5;
      if ((local_f3 & 0xfd) != 0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
    }
    else {
LAB_14000aff7:
      puVar5 = puVar4;
      if (-1 < (int)uVar2) goto LAB_14000affc;
    }
    puVar5 = puVar4;
    param_1 = local_1b8;
  } while( true );
}



===== FseDemuxShimReturnNBLChain @ 14000b0c0 =====

void FseDemuxShimReturnNBLChain(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  
  if (param_2 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar1 = param_2[0xe];
  if (lVar1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if ((*(byte *)(lVar1 + 0x48) & 1) == 0) {
    FseShimReleaseOrDropNblChain(param_2,0);
  }
  return;
}



===== FseInitializeShims @ 14000b10c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseInitializeShims(void)

{
  bool bVar1;
  bool bVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte *pbVar6;
  ulonglong uVar7;
  undefined1 auStackY_c8 [32];
  code *local_98;
  code *local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  code *local_78;
  code *pcStack_70;
  char *local_58;
  undefined8 local_50;
  code **local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  lVar4 = DAT_14002a7b0;
  plVar3 = DAT_14002a7a8;
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_78 = FseUpperShimRecvNBLChain;
  pcStack_70 = FseUpperShimSendCompleteNBLChain;
  local_88 = 0;
  uStack_80 = 0;
  if (DAT_14002a7a8 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar2 = true;
  if (lVar4 == 0) {
    uVar7 = 0xc000000d;
    if (DAT_14002a000 < 3) {
      return 0xc000000d;
    }
    if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_50 = 0x44;
      local_58 = "FseCoreRegisterUpperShim: One or more input parameters are invalid.";
      local_48 = &local_98;
      local_98 = (code *)CONCAT44(local_98._4_4_,0xc000000d);
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400279c5,0,0,4,&local_78);
    }
    if (DAT_14002a000 < 3) {
      return 0xc000000d;
    }
    if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_50 = 0x28;
      local_58 = "FseCoreRegisterUpperShim returned error";
      local_48 = &local_98;
      local_98 = (code *)CONCAT44(local_98._4_4_,0xc000000d);
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002762a,0,0,4,&local_78);
    }
    if (DAT_14002a000 < 3) {
      return 0xc000000d;
    }
    if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (!bVar1) goto LAB_14000b40c;
    local_58 = "L\"FseCoreRegisterUpperShim\" failed.";
    local_98 = (code *)CONCAT44(local_98._4_4_,0xc000000d);
    pbVar6 = &DAT_140026152;
LAB_14000b3d1:
    local_50 = 0x24;
  }
  else {
    *plVar3 = lVar4;
    local_90 = FseLowerShimSendNBLChain;
    plVar3[1] = (longlong)local_78;
    plVar3[2] = (longlong)pcStack_70;
    plVar3[3] = 0;
    plVar3[4] = 0;
    uVar5 = FseCoreRegisterLowerShim((longlong)DAT_14002a7a8,DAT_14002a7b0,(longlong *)&local_90);
    uVar7 = uVar5 & 0xffffffff;
    if ((int)uVar5 != 0) {
      if (DAT_14002a000 < 3) {
        return uVar7;
      }
      if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (!bVar1) goto LAB_14000b40c;
      local_58 = "L\"FseCoreRegisterLowerShim\" failed.";
      local_98 = (code *)CONCAT44(local_98._4_4_,(int)uVar5);
      pbVar6 = &DAT_140026120;
      goto LAB_14000b3d1;
    }
    local_98 = FseDemuxShimReturnNBLChain;
    uVar5 = FseCoreRegisterInboundDemux((longlong)DAT_14002a7a8,DAT_14002a7b0,(longlong *)&local_98)
    ;
    uVar7 = uVar5 & 0xffffffff;
    if ((int)uVar5 == 0) {
      return uVar7;
    }
    if (DAT_14002a000 < 3) {
      return uVar7;
    }
    if (((DAT_14002a010 & 4) == 0) || (bVar1 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (!bVar1) goto LAB_14000b40c;
    local_58 = "L\"FseCoreRegisterInboundDemux\" failed.";
    local_50 = 0x27;
    local_98 = (code *)CONCAT44(local_98._4_4_,(int)uVar5);
    pbVar6 = &DAT_1400260ee;
  }
  local_48 = &local_98;
  local_40 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar6,0,0,4,&local_78);
LAB_14000b40c:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_50 = 0x22;
      local_58 = "FseInitializeShims returned error";
      local_48 = &local_98;
      local_98 = (code *)CONCAT44(local_98._4_4_,(int)uVar7);
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400260b8,0,0,4,&local_78);
    }
  }
  return uVar7;
}



===== FseLowerShimSendNBLChain @ 14000b4c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseLowerShimSendNBLChain
               (undefined8 param_1,longlong *param_2,undefined8 *param_3,int *param_4,
               undefined8 param_5,undefined8 *param_6)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  short *psVar4;
  longlong *plVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  byte bVar13;
  bool bVar14;
  undefined1 auStackY_258 [32];
  ushort local_1f8;
  uint local_1f4;
  short local_1f0;
  short local_1ec [2];
  uint local_1e8;
  longlong *local_1e0;
  undefined1 local_1d8;
  undefined4 local_1d7;
  undefined2 local_1d3;
  undefined1 local_1d1;
  longlong local_1d0;
  longlong *local_1c8;
  undefined4 local_1c0;
  longlong *local_1b8;
  undefined1 local_1b0;
  undefined4 local_1af;
  undefined2 local_1ab;
  undefined1 local_1a9;
  longlong local_1a8;
  longlong *local_1a0;
  int *local_198;
  undefined1 local_190;
  undefined4 local_18f;
  undefined2 local_18b;
  undefined1 local_189;
  undefined8 local_188;
  undefined8 *local_180;
  undefined8 local_178;
  undefined8 *local_170;
  undefined8 *local_168;
  longlong *local_158 [6];
  undefined8 local_128;
  undefined8 uStack_120;
  int *local_118;
  byte local_110;
  undefined1 local_108 [48];
  int local_d8;
  uint local_bc;
  undefined8 local_98 [4];
  longlong **local_78;
  undefined8 local_70;
  longlong **local_68;
  undefined8 local_60;
  longlong **local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_258;
  local_168 = param_6;
  local_1b0 = 0;
  local_1e8 = CONCAT31(local_1e8._1_3_,1);
  local_1af = 0;
  local_1ab = 0;
  local_1a9 = 0;
  local_1a8 = 0;
  local_1f8 = 0;
  local_1d8 = 0;
  local_1d7 = 0;
  local_1d3 = 0;
  local_1d1 = 0;
  local_1d0 = 0;
  local_190 = 0;
  local_18f = 0;
  local_18b = 0;
  local_189 = 0;
  local_188 = 0;
  local_1ec[0] = 0;
  local_198 = param_4;
  memset(local_158,0,0x50);
  if (param_2 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar1 = (undefined8 *)param_2[0xe];
  local_170 = puVar1;
  if (puVar1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  plVar2 = (longlong *)*puVar1;
  if (plVar2 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar3 = *(longlong *)(param_4 + 2);
  if (lVar3 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  iVar10 = *(int *)(lVar3 + 8);
  if (((iVar10 - 0xf3U < 2) || (iVar10 == 0x17)) || (bVar7 = false, iVar10 == 0x35)) {
    bVar7 = true;
  }
  if (plVar2 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  psVar4 = (short *)*plVar2;
  if (psVar4 == (short *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  local_1f0 = *psVar4;
  local_1a0 = &local_1a8;
  local_128 = *param_3;
  uStack_120 = param_3[1];
  local_180 = &local_188;
  local_1c8 = &local_1d0;
  local_110 = local_110 | 2;
  local_158[0] = plVar2;
  local_118 = param_4;
  do {
    cVar8 = '\0';
    memset(local_108,0,0x68);
    bVar14 = false;
    plVar5 = (longlong *)*param_2;
    bVar13 = 0;
    *param_2 = 0;
    if ((!bVar7) || ((char)local_1e8 == '\0')) {
LAB_14000b871:
      if ((*(uint *)(param_2 + 0x18) & 1) != 0) {
        bVar13 = 1;
LAB_14000b898:
        if ((!bVar14) && (uVar9 = FseIpsClientParseNbl(plVar2,(longlong)param_2), (int)uVar9 < 0)) {
          if (2 < DAT_14002a000) {
            if (((_DAT_14002a010 & 0x20000) == 0) || ((DAT_14002a018 & 0x20000) != DAT_14002a018)) {
              bVar14 = false;
            }
            else {
              bVar14 = true;
            }
            if (bVar14) {
              local_78 = (longlong **)0x140022378;
              local_68 = &local_1e0;
              local_70 = 0x2c;
              local_58 = (longlong **)&local_1f4;
              local_60 = 8;
              local_50 = 4;
              local_1f4 = uVar9;
              local_1e0 = param_2;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400261c5,0,0,5,local_98);
            }
          }
          *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc000021b;
          goto LAB_14000b7bf;
        }
        if (cVar8 != '\0') {
          lVar3 = *plVar2;
          local_178 = 0;
          local_1f4 = 0;
          local_1c0 = 0;
          if (lVar3 == 0) {
            MicrosoftTelemetryAssertTriggeredNoArgsKM();
          }
          iVar10 = (**(code **)(*(longlong *)(lVar3 + 0x10) + 0x58))
                             (*(undefined8 *)(lVar3 + 8),plVar2[1]);
          if ((((iVar10 + 0x80000000U & 0x80000000) == 0) && (iVar10 != -0x3ffffddb)) &&
             (2 < DAT_14002a000)) {
            if (((_DAT_14002a010 & 0x400000000000) == 0) ||
               (bVar14 = true, (DAT_14002a018 & 0x400000000000) != DAT_14002a018)) {
              bVar14 = false;
            }
            if (bVar14) {
              local_1e0 = (longlong *)CONCAT44(local_1e0._4_4_,iVar10);
              local_78 = &local_1e0;
              local_70 = 4;
              local_68 = &local_1b8;
              local_1b8 = (longlong *)0x1000000;
              local_60 = 8;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024f03,0,0,4,local_98);
            }
          }
          bVar13 = (byte)local_1f4 & 1;
        }
        if (bVar13 == 0) goto LAB_14000bb12;
        FseShimsUpdateAndProcessSteerChain
                  ((longlong)param_2,(longlong)local_108,local_158,(longlong)&local_190,local_1ec);
        goto LAB_14000b7ca;
      }
      cVar8 = FseShimsCheckNblLoopbackDestinationMac((longlong)param_2);
      if (cVar8 != '\0') goto LAB_14000b898;
LAB_14000bb12:
      *local_1c8 = (longlong)param_2;
      local_1c8 = param_2;
      plVar11 = (longlong *)FseIpsClientCloneNbl(plVar2,(longlong)param_2,(undefined4 *)0x0);
      if (plVar11 == (longlong *)0x0) {
        *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc000009a;
        if (2 < DAT_14002a000) {
          if (((_DAT_14002a010 & 0x20000) == 0) || ((DAT_14002a018 & 0x20000) != DAT_14002a018)) {
            bVar14 = false;
          }
          else {
            bVar14 = true;
          }
          if (bVar14) {
            local_1e0 = (longlong *)CONCAT44(local_1e0._4_4_,0xc000009a);
            local_78 = (longlong **)0x1400223a8;
            local_68 = &local_1b8;
            local_70 = 0x23;
            local_58 = &local_1e0;
            local_60 = 8;
            local_50 = 4;
            local_1b8 = param_2;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026184,0,0,5,local_98);
          }
        }
        goto LAB_14000b7ca;
      }
      plVar11[0x16] = param_2[0x16];
      *(uint *)(plVar11 + 0x16) = *(uint *)(plVar11 + 0x16) & 0xffff000f;
      local_1f8 = local_1f8 + 1;
      *local_1a0 = (longlong)plVar11;
      local_1a0 = plVar11;
    }
    else {
      bVar14 = false;
      psVar4 = (short *)*plVar2;
      if (psVar4 == (short *)0x0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      if (*psVar4 != 2) {
        uVar9 = FseIpsClientParseNbl(plVar2,(longlong)param_2);
        if ((int)uVar9 < 0) {
          if (2 < DAT_14002a000) {
            if (((_DAT_14002a010 & 0x20000) == 0) ||
               (bVar6 = true, (DAT_14002a018 & 0x20000) != DAT_14002a018)) {
              bVar6 = false;
            }
            if (bVar6) {
              local_78 = (longlong **)0x140022150;
              local_68 = &local_1e0;
              local_70 = 0x43;
              local_58 = (longlong **)&local_1f4;
              local_60 = 8;
              local_50 = 4;
              local_1f4 = uVar9;
              local_1e0 = param_2;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400264ff,0,0,5,local_98);
            }
          }
        }
        else if (((uVar9 == 0) && (bVar14 = true, local_d8 == 0x3a)) && (local_bc != 0)) {
          if ((local_bc & 1) != 0) {
            bVar14 = (local_bc & 8) == 0;
            goto LAB_14000b796;
          }
          goto LAB_14000b7b5;
        }
LAB_14000b859:
        local_1e8 = local_1e8 & 0xff;
        if (local_1f0 == 2) {
          local_1e8 = 0;
        }
        goto LAB_14000b871;
      }
      if ((*(byte *)(plVar2 + 3) & 1) == 0) goto LAB_14000b859;
      bVar14 = ((byte)plVar2[7] & 0x19) == 1;
LAB_14000b796:
      if (bVar14) {
        puVar12 = local_108;
        if (local_1f0 == 2) {
          puVar12 = (undefined1 *)0x0;
        }
        FseIpsClientIndicateNdResponse(plVar2,(longlong)param_2,(longlong)puVar12);
      }
LAB_14000b7b5:
      *(undefined4 *)((longlong)param_2 + 0x8c) = 0x80;
LAB_14000b7bf:
      *local_1c8 = (longlong)param_2;
      local_1c8 = param_2;
LAB_14000b7ca:
    }
    param_2 = plVar5;
    if (plVar5 == (longlong *)0x0) {
      if (local_1ec[0] != 0) {
        FseShimsProcessSteerNblChain((longlong)&local_190,local_1ec[0]);
      }
      if (local_1f8 != 0) {
        FseIpsClientForwardNblChain(plVar2,(longlong)&local_1b0,(uint)local_1f8,*local_198);
      }
      if (local_1d0 != 0) {
        *(undefined8 **)(local_1d0 + 0x70) = local_170;
        FseCoreSendNetBufferListsComplete(DAT_14002a7a8,local_1d0,local_168);
      }
      return;
    }
  } while( true );
}



===== FseShimReleaseOrDropNblChain @ 14000bc40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseShimReleaseOrDropNblChain(undefined8 *param_1,undefined1 param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  bool bVar6;
  char *pcVar7;
  char *pcVar8;
  ushort uVar9;
  undefined7 uVar11;
  ulonglong uVar10;
  byte bVar12;
  ulonglong uVar13;
  ushort uVar14;
  undefined1 auStack_128 [32];
  undefined1 local_f8 [4];
  int local_f4 [3];
  undefined1 local_e8;
  undefined4 local_e7;
  undefined2 local_e3;
  undefined1 local_e1;
  undefined8 local_e0;
  undefined8 *local_d8;
  undefined1 local_d0;
  undefined4 local_cf;
  undefined2 local_cb;
  undefined1 local_c9;
  undefined8 local_c8;
  undefined8 *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined *local_98;
  uint local_90;
  undefined4 local_8c;
  undefined *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_128;
  local_e8 = 0;
  local_e7 = 0;
  local_e3 = 0;
  uVar14 = 0;
  local_e1 = 0;
  uVar9 = 0;
  local_d0 = 0;
  local_cf = 0;
  local_cb = 0;
  local_c9 = 0;
  if (param_1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar4 = (undefined8 *)param_1[0xe];
  if (puVar4 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  plVar5 = (longlong *)*puVar4;
  if (plVar5 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  local_d8 = &local_e0;
  local_e0 = 0;
  local_c0 = &local_c8;
  local_c8 = 0;
  do {
    uVar10 = 0x400000000000;
    puVar4 = (undefined8 *)*param_1;
    iVar3 = *(int *)((longlong)param_1 + 0x8c);
    *param_1 = 0;
    if (iVar3 < 0) {
      if (5 < DAT_14002a000) {
        if (((_DAT_14002a010 & 0x400000000000) == 0) ||
           (bVar6 = true, (DAT_14002a018 & 0x400000000000) != DAT_14002a018)) {
          bVar6 = false;
        }
        if (bVar6) {
          local_78 = &local_a8;
          local_a8 = 1;
          local_68 = local_f4;
          local_70 = 8;
          local_58 = local_f8;
          local_48 = &local_a0;
          local_b4 = 5;
          local_98 = PTR_DAT_14002a008;
          local_60 = 4;
          local_50 = 1;
          local_a0 = 0x800;
          local_40 = 8;
          local_b8 = 0xb000000;
          local_b0 = 0x400000000000;
          local_90 = (uint)*(ushort *)PTR_DAT_14002a008;
          local_88 = &DAT_14002654b;
          local_8c = 2;
          local_80 = 0x47;
          local_7c = 1;
          local_f4[1] = 0x42f9;
          local_f8[0] = param_2;
          local_f4[0] = iVar3;
          if (DAT_14002a028 == TlgAggregateInternalRegisteredProviderEtwCallback) {
            uVar13 = 0;
            pcVar7 = &DAT_14002654d;
            do {
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 < '\0');
            do {
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 != '\0');
            while( true ) {
              bVar12 = (byte)uVar13;
              if ("\x06\v\x04" <= pcVar7) break;
              do {
                pcVar8 = pcVar7;
                pcVar7 = pcVar8 + 1;
              } while (*pcVar8 != '\0');
              cVar1 = pcVar8[1];
              uVar11 = (undefined7)(uVar10 >> 8);
              uVar10 = CONCAT71(uVar11,cVar1);
              pcVar7 = pcVar8 + 2;
              if (-1 < cVar1) break;
              cVar2 = *pcVar7;
              uVar10 = CONCAT71(uVar11,cVar1) & 0xffffffffffffff7f;
              pcVar7 = pcVar8 + 3;
              if (-1 < cVar2) break;
              for (; cVar1 = *pcVar7, cVar1 < '\0'; pcVar7 = pcVar7 + 1) {
                if (cVar1 != -0x80) goto LAB_14000be9a;
              }
              if (((char)uVar10 != '\t') || (2 < (byte)(cVar1 + 0x8fU))) break;
              *(char *)((longlong)&local_70 + uVar13 * 0x10 + 5) = cVar1;
              uVar13 = (ulonglong)(byte)(bVar12 + 1);
            }
LAB_14000be9a:
            if (bVar12 == 0) {
              EtwWriteTransfer(DAT_14002a020,&local_b8,0,0);
            }
            else {
              InsertEventEntryInLookUpTable
                        (pcVar7,(undefined8 *)&local_b8,uVar10,(longlong)&local_98,bVar12);
            }
          }
        }
      }
      if (*(int *)((longlong)param_1 + 0x8c) < 0) {
        FseDiagnosticsLogFailure(0xe,*(int *)((longlong)param_1 + 0x8c));
      }
      uVar9 = uVar9 + 1;
      *local_c0 = param_1;
      local_c0 = param_1;
    }
    else {
      uVar14 = uVar14 + 1;
      *local_d8 = param_1;
      local_d8 = param_1;
    }
    param_1 = puVar4;
    if (puVar4 == (undefined8 *)0x0) {
      if (uVar14 != 0) {
        FseIpsClientReleaseNblChain(plVar5,(longlong)&local_e8,(uint)uVar14);
      }
      if (uVar9 != 0) {
        FseIpsClientDropNblChain(plVar5,(longlong)&local_d0,(uint)uVar9);
      }
      return;
    }
  } while( true );
}



===== FseShimsCheckNblLoopbackDestinationMac @ 14000bf88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FseShimsCheckNblLoopbackDestinationMac(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined1 auStackY_98 [32];
  int local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = *(longlong *)(param_1 + 8);
  uVar7 = 0;
  local_18 = 0x33221100;
  local_14 = 0x5544;
  if (*(uint *)(lVar1 + 0x10) < 0xe) {
    iVar3 = NdisRetreatNetBufferDataStart(lVar1,0xe);
    if (iVar3 != 0) {
      if (DAT_14002a000 < 3) {
        return 0;
      }
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_2c = 0;
        local_1c = 0;
        local_28 = local_68;
        local_38 = "NetioRetreatNetBuffer failed.";
        local_30 = 0x1e;
        local_20 = 4;
        local_68[0] = iVar3;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026469,0,0,4,local_58);
        return 0;
      }
      return 0;
    }
  }
  else {
    *(int *)(lVar1 + 0x28) = *(int *)(lVar1 + 0x28) + -0xe;
    *(int *)(lVar1 + 0x18) = *(int *)(lVar1 + 0x18) + 0xe;
    *(uint *)(lVar1 + 0x10) = *(uint *)(lVar1 + 0x10) - 0xe;
  }
  uVar4 = NetioGetDataBufferIfSafe(lVar1);
  if (uVar4 == 0) {
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_2c = 0;
        local_1c = 0;
        local_38 = "FseShimsCheckNblLoopbackDestinationMac: NetioGetDataBufferIfSafe failed";
        local_28 = local_68;
        local_30 = 0x48;
        local_68[0] = -0x3ffffde5;
        local_20 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026437,0,0,4,local_58);
      }
    }
  }
  else {
    lVar5 = RtlCompareMemory(&local_18,uVar4,6);
    uVar7 = 0;
    if (lVar5 == 6) {
      uVar7 = 1;
    }
  }
  if (*(longlong *)(lVar1 + 8) == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  uVar6 = *(int *)(lVar1 + 0x10) + 0xe;
  if (uVar6 < *(uint *)(*(longlong *)(lVar1 + 8) + 0x28)) {
    *(int *)(lVar1 + 0x28) = *(int *)(lVar1 + 0x28) + 0xe;
    *(int *)(lVar1 + 0x18) = *(int *)(lVar1 + 0x18) + -0xe;
    *(uint *)(lVar1 + 0x10) = uVar6;
  }
  else {
    NdisAdvanceNetBufferDataStart(lVar1,0xe,0);
  }
  return uVar7;
}



===== FseShimsProcessFloodNblChain @ 14000c1d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

void FseShimsProcessFloodNblChain(longlong *param_1,longlong param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  longlong *plVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  undefined8 *puVar12;
  undefined1 auStackY_598 [32];
  uint local_568;
  ushort local_564 [2];
  undefined1 *local_560;
  longlong *local_558;
  uint local_550;
  undefined1 local_548;
  undefined4 local_547;
  undefined2 local_543;
  undefined1 local_541;
  longlong local_540;
  longlong *plStack_538;
  longlong local_530;
  ulonglong local_528;
  undefined8 local_518 [4];
  char *local_4f8;
  undefined8 local_4f0;
  longlong **local_4e8;
  undefined8 local_4e0;
  undefined8 *local_4d8;
  undefined8 local_4d0;
  undefined1 local_4c8 [1152];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_598;
  local_564[0] = 0;
  iVar7 = 0;
  local_550 = param_3;
  local_530 = param_2;
  memset(local_4c8,0,0x480);
  local_560 = (undefined1 *)0x0;
  local_548 = 0;
  local_547 = 0;
  puVar6 = (undefined1 *)0x0;
  local_543 = 0;
  uVar5 = 0;
  local_541 = 0;
  local_568 = 0;
  local_540 = 0;
  plStack_538 = (longlong *)0x0;
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  uVar9 = (ulonglong)*(uint *)(param_1 + 2);
  puVar11 = local_4c8;
  local_558 = (longlong *)0x480;
  while( true ) {
    plVar8 = local_558;
    if (iVar7 == -0x7ffffffb) {
      if (puVar6 != (undefined1 *)0x0) {
        FseFreeMemory((longlong *)&local_560);
        local_560 = (undefined1 *)0x0;
      }
      uVar3 = FseAllocMemory((size_t)plVar8,0x53657346,&local_560);
      puVar6 = local_560;
      if ((int)uVar3 != 0) goto LAB_14000c4df;
      puVar11 = local_560;
    }
    uVar2 = FseCoreListAllNicPairEntries(DAT_14002a7a8,local_564,(ulonglong *)&local_558,puVar11);
    if (uVar2 != 0x80000005) break;
    iVar7 = -0x7ffffffb;
  }
  if (uVar2 == 0) {
    plStack_538 = &local_540;
    if (local_564[0] != 0) {
      uVar10 = (ulonglong)local_564[0];
      puVar12 = (undefined8 *)(puVar11 + 0x20);
      uVar5 = 0;
      local_528 = uVar9;
      do {
        if ((uVar9 == puVar12[-4]) &&
           (plVar8 = *(longlong **)(local_530 + 8), plVar8 != (longlong *)0x0)) {
          do {
            plVar4 = (longlong *)
                     FseIpsClientCloneNbl(param_1,(longlong)plVar8,(undefined4 *)*puVar12);
            if (plVar4 == (longlong *)0x0) {
              if (2 < DAT_14002a000) {
                if (((uRam000000014002a011 & 0x200) == 0) ||
                   (bVar1 = true, ((uint)DAT_14002a018 & 0x20000) != DAT_14002a018)) {
                  bVar1 = false;
                }
                if (bVar1) {
                  local_4f0 = 0x23;
                  local_4f8 = "Cloning Failed for Flooding Packet";
                  local_4e8 = &local_558;
                  local_4d8 = (undefined8 *)&local_568;
                  local_4e0 = 8;
                  local_568 = 0xc000009a;
                  local_4d0 = 4;
                  local_558 = plVar8;
                  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400263c4,0,0,5,local_518);
                }
              }
            }
            else {
              *(uint *)(plVar4 + 0x16) =
                   (*(int *)(puVar12 + -1) << 4 ^ *(uint *)(plVar4 + 0x16)) & 0xfff0 ^
                   *(uint *)(plVar4 + 0x16);
              uVar5 = uVar5 + 1;
              *plStack_538 = (longlong)plVar4;
              plStack_538 = plVar4;
            }
            plVar8 = (longlong *)*plVar8;
          } while (plVar8 != (longlong *)0x0);
          uVar9 = local_528;
          local_568 = uVar5;
        }
        puVar12 = puVar12 + 9;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
      puVar6 = local_560;
      uVar5 = local_568;
    }
  }
  else if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_4f0 = 0x28;
      local_4f8 = "L\"FseCoreListAllNicPairEntries\" failed.";
      local_4e8 = (longlong **)&local_568;
      local_4e0 = 4;
      local_568 = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026405,0,0,4,local_518);
    }
  }
LAB_14000c4df:
  FseIpsClientReturnNblChain(param_1,local_530,local_550);
  if (uVar5 != 0) {
    FseIpsClientForwardNblChain(param_1,(longlong)&local_548,uVar5,*(int *)(DAT_14002a7b0 + 0x88));
  }
  if (puVar6 != (undefined1 *)0x0) {
    FseFreeMemory((longlong *)&local_560);
  }
  return;
}



===== FseShimsProcessSteerNblChain @ 14000c554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseShimsProcessSteerNblChain(longlong param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  short *psVar4;
  longlong lVar5;
  code *pcVar6;
  ushort uVar7;
  bool bVar8;
  ushort uVar9;
  char cVar10;
  char cVar11;
  undefined8 uVar12;
  longlong lVar13;
  undefined8 *puVar14;
  longlong *plVar15;
  byte bVar16;
  uint uVar17;
  ulonglong uVar18;
  byte *pbVar19;
  uint uVar20;
  longlong *plVar21;
  ulonglong uVar22;
  ushort uVar23;
  longlong *plVar24;
  undefined1 auStackY_178 [32];
  uint local_134;
  char local_130 [2];
  ushort local_12e;
  uint local_12c [3];
  longlong local_120;
  longlong *local_118;
  longlong *local_110;
  undefined *local_108;
  longlong *local_100;
  undefined8 local_f8 [4];
  char *local_d8;
  undefined8 local_d0;
  longlong **local_c8;
  ulonglong local_c0;
  uint *local_b8;
  undefined8 local_b0;
  longlong *local_a8;
  undefined8 local_a0;
  ushort *local_98;
  undefined8 local_90;
  longlong local_88 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  local_134 = CONCAT22(local_134._2_2_,param_2);
  local_120 = param_1;
  memset(local_88,0,0x40);
  local_118 = (longlong *)0x0;
  bVar8 = false;
  uVar23 = 0;
  local_110 = (longlong *)0x0;
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar3 = *(undefined **)(param_1 + 8);
  local_108 = puVar3;
  if (puVar3 == (undefined *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  plVar15 = *(longlong **)(puVar3 + 0x70);
  if (plVar15 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  iVar1 = (int)plVar15[3];
  if ((iVar1 != 6) && (iVar1 != 0x11)) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  plVar21 = local_88;
  uVar17 = 8;
  local_12e = *(ushort *)((longlong)plVar15 + 0x1c) >> 8 |
              *(ushort *)((longlong)plVar15 + 0x1c) << 8;
  uVar20 = 8;
  local_12c[0] = 8;
  plVar24 = (longlong *)0x0;
  do {
    if (uVar17 < uVar20) {
      if (plVar24 != (longlong *)0x0) {
        FseFreeMemory((longlong *)&local_118);
        local_118 = (longlong *)0x0;
      }
      uVar12 = FseAllocMemory((ulonglong)uVar20 << 3,0x53657346,&local_118);
      if ((int)uVar12 != 0) goto LAB_14000c78c;
      plVar21 = local_118;
      uVar17 = uVar20;
    }
    uVar9 = local_12e;
    local_12c[0] = 0;
    if ((local_12e == g_FseDebugPort) && (g_FseDebugPort != 0)) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    lVar13 = FseAllocatorGetPool(iVar1);
    if (lVar13 == 0) {
      uVar20 = local_12c[0];
    }
    else {
      FsePortPoolGetPartitionsForPort(lVar13,uVar9,uVar17,local_12c,plVar21);
      uVar20 = local_12c[0];
      if (local_12c[0] <= uVar17) break;
      memset(plVar21,0,(ulonglong)uVar17 << 3);
    }
    if (uVar20 <= uVar17) break;
    plVar24 = local_118;
  } while( true );
  uVar17 = 0;
  if (uVar20 != 0) {
    do {
      if (plVar21[uVar17] == 0) {
        bVar8 = true;
        goto LAB_14000c6f9;
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 < uVar20);
  }
  if (((*(byte *)(plVar15 + 9) & 2) == 0) || (uVar20 != 0)) {
    bVar16 = 0;
  }
  else {
LAB_14000c6f9:
    bVar16 = 1;
  }
  pbVar19 = (byte *)(plVar15 + 9);
  *pbVar19 = *pbVar19 & 0xfe | bVar16;
  if (uVar20 == 0) {
    plVar21 = (longlong *)*plVar15;
    local_108 = (undefined *)0x0;
    if (plVar21 == (longlong *)0x0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    (**(code **)(*(longlong *)(*plVar21 + 0x10) + 0x78))
              (*(undefined8 *)(*plVar21 + 8),*(undefined4 *)((longlong)plVar21 + 0x14));
    if ((int)local_108 == 1) {
      puVar14 = (undefined8 *)*plVar15;
      if (puVar14 == (undefined8 *)0x0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      psVar4 = (short *)*puVar14;
      if (psVar4 == (short *)0x0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      if ((*psVar4 != 2) || (local_12c[1] = 0xfffffea9, (int)plVar15[1] != -0x157)) {
        lVar13 = *plVar15;
        if (lVar13 == 0) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        uVar7 = (ushort)local_134;
        FseDiagnosticsLogPktsWithNoMatchingPartitions
                  ((int)plVar15[3],*(undefined4 *)(lVar13 + 0x10),uVar9,(ushort)local_134);
        goto LAB_14000c8ee;
      }
    }
    uVar7 = (ushort)local_134;
LAB_14000c8ee:
    uVar22 = (ulonglong)uVar7;
    if (!bVar8) {
LAB_14000c8f8:
      if (uVar23 != 0) goto LAB_14000cbb5;
    }
  }
  else {
    uVar23 = (ushort)uVar20;
    if (!bVar8) {
      plVar24 = plVar21;
      if (uVar23 != 0) goto LAB_14000c7f0;
      uVar22 = (ulonglong)(ushort)local_134;
      goto LAB_14000c8f8;
    }
    uVar23 = uVar23 - 1;
    if ((uVar23 != 0) &&
       (uVar12 = FseAllocMemory((ulonglong)uVar23 << 3,0x53657346,&local_110), (int)uVar12 == 0)) {
      uVar17 = 0;
      plVar24 = local_110;
      if (uVar20 != 0) {
        uVar22 = (ulonglong)uVar20;
        do {
          if (*plVar21 != 0) {
            uVar18 = (ulonglong)uVar17;
            uVar17 = uVar17 + 1;
            local_110[uVar18] = *plVar21;
          }
          plVar21 = plVar21 + 1;
          uVar22 = uVar22 - 1;
        } while (uVar22 != 0);
      }
LAB_14000c7f0:
      if ((*pbVar19 & 2) == 0) {
        lVar13 = *plVar15;
        if (lVar13 == 0) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        uVar22 = (ulonglong)*(uint *)(lVar13 + 0x10);
      }
      else {
        uVar22 = *(ulonglong *)plVar15[8];
      }
      uVar7 = (ushort)local_134;
      FseCoreIndicateReceiveNetBufferLists
                (DAT_14002a7a8,local_108,local_134 & 0xffff,uVar22,uVar23,plVar24);
      goto LAB_14000c8ee;
    }
LAB_14000c78c:
    uVar22 = (ulonglong)(ushort)local_134;
  }
  uVar20 = (uint)uVar22;
  if ((*(byte *)(plVar15 + 9) & 2) == 0) {
    FseIpsClientReturnNblChain((longlong *)*plVar15,local_120,uVar20);
  }
  else {
    if (plVar15[8] == 0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    cVar10 = FseIsInterpartitionLoopbackAllowed((longlong *)&HV_GUID_LOOPBACK);
    cVar11 = FseIsInterpartitionLoopbackAllowed(plVar15 + 6);
    lVar13 = local_120;
    if ((cVar11 == '\0') || (cVar10 == '\0')) {
      plVar21 = *(longlong **)(local_120 + 8);
      if (plVar21 != (longlong *)0x0) {
        do {
          *(undefined4 *)((longlong)plVar21 + 0x8c) = 0xc0000022;
          if (2 < DAT_14002a000) {
            if (((_DAT_14002a010 & 0x20000) == 0) ||
               (bVar8 = true, ((uint)DAT_14002a018 & 0x20000) != DAT_14002a018)) {
              bVar8 = false;
            }
            if (bVar8) {
              local_d0 = 0x53;
              local_d8 = 
              "Dropping interpartition loopback destined to root partition due to firewall policy";
              local_c8 = &local_100;
              local_b8 = (uint *)&local_120;
              local_c0 = 8;
              local_a8 = (longlong *)local_130;
              local_120 = CONCAT44(local_120._4_4_,0xc0000022);
              local_98 = &local_12e;
              local_b0 = 4;
              local_a0 = 1;
              local_12e = CONCAT11(local_12e._1_1_,cVar10);
              local_90 = 1;
              local_130[0] = cVar11;
              local_100 = plVar21;
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026346,0,0,7,local_f8);
            }
          }
          plVar21 = (longlong *)*plVar21;
        } while (plVar21 != (longlong *)0x0);
        uVar20 = local_134 & 0xffff;
      }
      FseIpsClientDropNblChain((longlong *)*plVar15,lVar13,uVar20);
    }
    else {
      for (puVar14 = *(undefined8 **)(local_120 + 8); puVar14 != (undefined8 *)0x0;
          puVar14 = (undefined8 *)*puVar14) {
        *(uint *)(puVar14 + 0x16) = *(uint *)(puVar14 + 0x16) & 0xffff000f;
      }
      plVar21 = (longlong *)*plVar15;
      uVar2 = *(undefined4 *)plVar15[8];
      if (plVar21 == (longlong *)0x0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      lVar5 = *plVar21;
      if (*(longlong *)(lVar13 + 8) == 0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      *(undefined8 *)(*(longlong *)(lVar13 + 8) + 0x70) = 0;
      (**(code **)(*(longlong *)(lVar5 + 0x10) + 0xa0))
                (*(undefined8 *)(lVar5 + 8),plVar21[1],1,uVar2);
      plVar15 = &DAT_14002a810;
      if ((int)plVar21[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
        plVar15 = &DAT_14002a848;
      }
      LOCK();
      *plVar15 = *plVar15 + uVar22;
      UNLOCK();
      if (5 < DAT_14002a000) {
        if (((_DAT_14002a010 & 0x1000) == 0) ||
           (bVar8 = true, (DAT_14002a018 & 0x1000) != DAT_14002a018)) {
          bVar8 = false;
        }
        if (bVar8) {
          local_d0 = 0x11;
          local_d8 = "Packets Injected";
          local_c8 = (longlong **)0x140021b18;
          if ((int)plVar21[2] != *(int *)(DAT_14002a7b0 + 0x88)) {
            local_c8 = (longlong **)0x140021b28;
          }
          lVar13 = -1;
          do {
            lVar13 = lVar13 + 1;
          } while (*(char *)((longlong)local_c8 + lVar13) != '\0');
          local_b8 = &local_134;
          local_c0 = (ulonglong)((int)lVar13 + 1);
          local_120 = plVar21[1];
          local_a8 = &local_120;
          local_b0 = 4;
          local_a0 = 8;
          local_134 = uVar20;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140024caf,0,0,6,local_f8);
        }
      }
    }
  }
LAB_14000cbb5:
  if (local_118 != (longlong *)0x0) {
    FseFreeMemory((longlong *)&local_118);
  }
  if (local_110 != (longlong *)0x0) {
    FseFreeMemory((longlong *)&local_110);
  }
  return;
}



===== FseShimsSwapNblMacAddresses @ 14000cc08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FseShimsSwapNblMacAddresses(longlong param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined1 auStackY_98 [32];
  int local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar3 = *(longlong *)(param_1 + 8);
  if (*(uint *)(lVar3 + 0x28) < 0xe) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (*(uint *)(lVar3 + 0x10) < 0xe) {
    iVar5 = NdisRetreatNetBufferDataStart(lVar3,0xe);
    if (iVar5 != 0) {
      if (DAT_14002a000 < 3) {
        return;
      }
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if (bVar4) {
        local_2c = 0;
        local_1c = 0;
        local_38 = "NetioRetreatNetBuffer failed.";
        local_28 = local_68;
        local_30 = 0x1e;
        local_20 = 4;
        local_68[0] = iVar5;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400264cd,0,0,4,local_58);
        return;
      }
      return;
    }
  }
  else {
    *(int *)(lVar3 + 0x28) = *(int *)(lVar3 + 0x28) + -0xe;
    *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + 0xe;
    *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) - 0xe;
  }
  puVar6 = (undefined4 *)NetioGetDataBufferIfSafe(lVar3);
  if (puVar6 == (undefined4 *)0x0) {
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if (bVar4) {
        local_2c = 0;
        local_1c = 0;
        local_38 = "FseShimsSwapNblMacAddresses: NetioGetDataBufferIfSafe failed";
        local_28 = local_68;
        local_30 = 0x3d;
        local_68[0] = -0x3ffffde5;
        local_20 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002649b,0,0,4,local_58);
      }
    }
  }
  else {
    uVar2 = *(undefined4 *)((longlong)puVar6 + 6);
    uVar1 = *(undefined2 *)((longlong)puVar6 + 10);
    *(undefined4 *)((longlong)puVar6 + 6) = *puVar6;
    *puVar6 = uVar2;
    *(undefined2 *)((longlong)puVar6 + 10) = *(undefined2 *)(puVar6 + 1);
    *(undefined2 *)(puVar6 + 1) = uVar1;
  }
  if (*(longlong *)(lVar3 + 8) == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  uVar7 = *(int *)(lVar3 + 0x10) + 0xe;
  if (uVar7 < *(uint *)(*(longlong *)(lVar3 + 8) + 0x28)) {
    *(int *)(lVar3 + 0x28) = *(int *)(lVar3 + 0x28) + 0xe;
    *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + -0xe;
    *(uint *)(lVar3 + 0x10) = uVar7;
  }
  else {
    NdisAdvanceNetBufferDataStart(lVar3,0xe,0);
  }
  return;
}



===== FseShimsUpdateAndProcessSteerChain @ 14000ce38 =====

void FseShimsUpdateAndProcessSteerChain
               (longlong param_1,longlong param_2,undefined8 *param_3,longlong param_4,
               short *param_5)

{
  short sVar1;
  undefined8 *puVar2;
  short *psVar3;
  longlong *plVar4;
  bool bVar5;
  
  puVar2 = (undefined8 *)*param_3;
  if (puVar2 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  psVar3 = (short *)*puVar2;
  if (psVar3 == (short *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  sVar1 = *psVar3;
  if (*param_5 != 0) {
    plVar4 = *(longlong **)(param_2 + 0x28);
    if (sVar1 == 0x17) {
      if (plVar4[1] == param_3[2]) {
        bVar5 = *plVar4 == param_3[1];
        goto LAB_14000cebc;
      }
    }
    else {
      if (sVar1 != 2) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      bVar5 = (int)*plVar4 == *(int *)(param_3 + 1);
LAB_14000cebc:
      if (((bVar5) && (*(int *)(param_2 + 0x30) == *(int *)(param_3 + 3))) &&
         (*(short *)(param_2 + 0x46) == *(short *)((longlong)param_3 + 0x1c))) goto LAB_14000cefc;
    }
    FseShimsProcessSteerNblChain(param_4,*param_5);
    *param_5 = 0;
    *(undefined8 *)(param_4 + 8) = 0;
    *(undefined8 **)(param_4 + 0x10) = (undefined8 *)(param_4 + 8);
  }
  FseShimsUpdateNblSteerContext(sVar1,param_1,param_2,(longlong)param_3);
LAB_14000cefc:
  plVar4 = *(longlong **)(param_4 + 0x10);
  *param_5 = *param_5 + 1;
  *plVar4 = param_1;
  *(longlong *)(param_4 + 0x10) = param_1;
  return;
}



===== FseShimsUpdateNblSteerContext @ 14000cf30 =====

void FseShimsUpdateNblSteerContext(short param_1,longlong param_2,longlong param_3,longlong param_4)

{
  size_t _Size;
  
  _Size = 0x10;
  if (param_1 != 0x17) {
    _Size = 4;
  }
  memmove((void *)(param_4 + 8),*(void **)(param_3 + 0x28),_Size);
  *(undefined4 *)(param_4 + 0x18) = *(undefined4 *)(param_3 + 0x30);
  *(undefined2 *)(param_4 + 0x1c) = *(undefined2 *)(param_3 + 0x46);
  if (param_2 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *(longlong *)(param_2 + 0x70) = param_4;
  return;
}



===== FseUpperShimProcessOutboundNblChain @ 14000cf9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FseUpperShimProcessOutboundNblChain(longlong param_1,longlong param_2)

{
  longlong **pplVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  longlong **pplVar5;
  undefined1 auStack_b8 [32];
  undefined1 local_98;
  undefined4 local_97;
  undefined2 local_93;
  undefined1 local_91;
  longlong *local_90;
  longlong **local_88;
  longlong local_78 [10];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  local_98 = 0;
  local_97 = 0;
  local_93 = 0;
  local_91 = 0;
  sVar4 = 0;
  memset(local_78,0,0x50);
  if (param_2 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  pplVar1 = *(longlong ***)(param_2 + 8);
  local_78[0] = param_1;
  if (pplVar1 == (longlong **)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  pplVar1[0xe] = local_78;
  uVar2 = *(uint *)(pplVar1 + 0x16) >> 4 & 0xfff;
  local_90 = (longlong *)0x0;
  local_88 = &local_90;
  do {
    pplVar5 = pplVar1;
    pplVar1 = (longlong **)*pplVar5;
    uVar3 = *(uint *)(pplVar5 + 0x16) >> 4 & 0xfff;
    *pplVar5 = (longlong *)0x0;
    if (uVar2 != uVar3) {
      if (sVar4 != 0) {
        FseCoreSendNetBufferLists(DAT_14002a7a8,local_90,(longlong *)(ulonglong)uVar3);
      }
      local_88 = &local_90;
      local_90 = (longlong *)0x0;
      sVar4 = 0;
      pplVar5[0xe] = local_78;
      uVar2 = uVar3;
    }
    sVar4 = sVar4 + 1;
    *local_88 = (longlong *)pplVar5;
    local_88 = pplVar5;
  } while (pplVar1 != (longlong **)0x0);
  if (sVar4 != 0) {
    FseCoreSendNetBufferLists(DAT_14002a7a8,local_90,(longlong *)(ulonglong)uVar3);
  }
  return;
}



===== FseUpperShimRecvNBLChain @ 14000d0f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseUpperShimRecvNBLChain
               (undefined8 param_1,int *param_2,undefined8 param_3,undefined8 param_4,
               longlong *param_5,longlong *param_6,int *param_7)

{
  undefined8 *puVar1;
  longlong *plVar2;
  bool bVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  byte *pbVar11;
  ushort uVar12;
  undefined1 auStackY_188 [32];
  ushort local_158;
  char local_156 [2];
  undefined4 local_154;
  longlong *local_150;
  undefined4 local_148 [2];
  undefined1 local_140;
  undefined4 local_13f;
  undefined2 local_13b;
  undefined1 local_139;
  longlong local_138;
  longlong *plStack_130;
  longlong local_128;
  longlong *local_120;
  longlong *local_118;
  longlong *local_110;
  int *local_108;
  undefined8 local_f8 [4];
  char *local_d8;
  undefined8 local_d0;
  longlong **local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  char *local_a8;
  undefined8 local_a0;
  ushort *local_98;
  undefined8 local_90;
  undefined8 local_88 [4];
  char *local_68;
  undefined8 local_60;
  longlong **local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
  local_150 = (longlong *)param_7;
  local_120 = param_5;
  local_140 = 0;
  local_13f = 0;
  local_13b = 0;
  local_139 = 0;
  local_158 = 0;
  local_138 = 0;
  plStack_130 = (longlong *)0x0;
  local_108 = param_2;
  if (param_2 == (int *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar1 = *(undefined8 **)(param_2 + 0x1c);
  if (puVar1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  plVar2 = (longlong *)*puVar1;
  if (plVar2 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (((*(byte *)(puVar1 + 9) & 2) != 0) && ((puVar1[6] != *param_6 || (puVar1[7] != param_6[1]))))
  {
    cVar6 = FseIsInterpartitionLoopbackAllowed(puVar1 + 6);
    cVar7 = FseIsInterpartitionLoopbackAllowed(param_6);
    if ((cVar6 == '\0') || (cVar7 == '\0')) {
      do {
        *(int *)((longlong)param_2 + 0x8c) = -0x3fffffde;
        if (2 < DAT_14002a000) {
          if (((_DAT_14002a010 & 0x20000) == 0) ||
             (bVar3 = true, (DAT_14002a018 & 0x20000) != DAT_14002a018)) {
            bVar3 = false;
          }
          if (bVar3) {
            local_d0 = 0x49;
            local_d8 = "Dropping interpartition loopback destined to guest due to firwall policy";
            local_c8 = &local_150;
            local_b8 = &local_154;
            local_c0 = 8;
            local_a8 = local_156;
            local_154 = 0xc0000022;
            local_98 = &local_158;
            local_b0 = 4;
            local_a0 = 1;
            local_158 = CONCAT11(local_158._1_1_,cVar7);
            local_90 = 1;
            local_156[0] = cVar6;
            local_150 = (longlong *)param_2;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026288,0,0,7,local_f8);
          }
        }
        param_2 = *(int **)param_2;
      } while ((longlong *)param_2 != (longlong *)0x0);
      plVar10 = local_120;
      goto LAB_14000d55d;
    }
  }
  plStack_130 = &local_138;
  uVar12 = local_158;
  do {
    if (plVar2 == (longlong *)0x0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    if (((*(byte *)(plVar2 + 3) & 1) == 0) && ((*(uint *)(plVar2 + 7) & 1) != 0)) {
      local_128 = 0;
      iVar8 = FwpsNetBufferListRetrieveContext0(param_2);
      if ((iVar8 < 0) || (local_128 == 0)) goto LAB_14000d400;
      *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc0000022;
      if (2 < DAT_14002a000) {
        if (((_DAT_14002a010 & 0x20000) == 0) ||
           (bVar3 = true, (DAT_14002a018 & 0x20000) != DAT_14002a018)) {
          bVar3 = false;
        }
        if (!bVar3) goto LAB_14000d520;
        local_60 = 0x2e;
        local_68 = "Dropping Inbound AppContainer Loopback Packet";
        pbVar11 = &DAT_140026247;
        local_58 = &local_118;
        local_48 = &local_154;
        local_50 = 8;
        local_154 = 0xc0000022;
        local_40 = 4;
        puVar9 = local_88;
        local_118 = (longlong *)param_2;
LAB_14000d3da:
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar11,0,0,5,puVar9);
      }
    }
    else {
LAB_14000d400:
      plVar10 = (longlong *)
                FseIpsClientCloneNbl(plVar2,(longlong)param_2,(undefined4 *)local_150[1]);
      if (plVar10 == (longlong *)0x0) {
        if ((*(byte *)(puVar1 + 9) & 1) == 0) {
          *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc000009a;
        }
        if (2 < DAT_14002a000) {
          if (((_DAT_14002a010 & 0x20000) == 0) ||
             (bVar3 = true, (DAT_14002a018 & 0x20000) != DAT_14002a018)) {
            bVar3 = false;
          }
          if (bVar3) {
            local_d0 = 0x22;
            local_d8 = "Cloning Failed for Inbound Packet";
            pbVar11 = &DAT_140026206;
            local_c8 = &local_110;
            local_b8 = local_148;
            puVar9 = local_f8;
            local_c0 = 8;
            local_148[0] = 0xc000009a;
            local_b0 = 4;
            local_110 = (longlong *)param_2;
            goto LAB_14000d3da;
          }
        }
      }
      else {
        *(uint *)(plVar10 + 0x16) =
             ((int)*local_150 << 4 ^ *(uint *)(plVar10 + 0x16)) & 0xfff0 ^ *(uint *)(plVar10 + 0x16)
        ;
        if ((((*(byte *)(puVar1 + 9) & 2) != 0) &&
            (FseShimsSwapNblMacAddresses((longlong)plVar10), (*(byte *)(puVar1 + 9) & 2) != 0)) ||
           (((*(byte *)(plVar2 + 3) & 1) == 0 && ((*(uint *)(plVar2 + 7) & 1) != 0)))) {
          plVar10[0x18] = 1;
          *(longlong *)((longlong)param_2 + 0xc0) = 1;
        }
        uVar12 = uVar12 + 1;
        *plStack_130 = (longlong)plVar10;
        plStack_130 = plVar10;
      }
    }
LAB_14000d520:
    plVar10 = local_120;
    param_2 = *(int **)param_2;
  } while (param_2 != (int *)0x0);
  local_158 = uVar12;
  if (uVar12 != 0) {
    FseIpsClientForwardNblChain
              (plVar2,(longlong)&local_140,(uint)uVar12,*(int *)(DAT_14002a7b0 + 0x88));
  }
LAB_14000d55d:
  lVar5 = DAT_14002a7a8;
  if (DAT_14002a7a8 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (plVar10 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  FseCoreInvokeNduNpiProvider(lVar5,(longlong)local_108,0,plVar10);
  plVar2 = plVar10 + 2;
  if (*plVar2 != 0) {
    FseFreeToLookasideList(0x14002a500,plVar2);
    *plVar2 = 0;
  }
  LOCK();
  plVar2 = plVar10 + 1;
  lVar4 = *plVar2;
  *(int *)plVar2 = (int)*plVar2 + -1;
  UNLOCK();
  if ((int)lVar4 == 1) {
    FseCoreReturnNblsAndCleanupIndicationContext(lVar5,*plVar10,(longlong)plVar10);
  }
  return;
}



===== FseUpperShimSendCompleteNBLChain @ 14000d600 =====

void FseUpperShimSendCompleteNBLChain(undefined8 param_1,undefined8 *param_2)

{
  FseShimReleaseOrDropNblChain(param_2,1);
  return;
}



===== FseDiagnosticsContextInitialize @ 14000d61c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseDiagnosticsContextInitialize(void)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 auStackY_98 [32];
  longlong local_68 [2];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_68[0] = 0;
  uVar3 = FseAllocMemory(0x40,0x64657346,local_68);
  lVar5 = local_68[0];
  iVar2 = (int)uVar3;
  if (iVar2 == 0) {
    uVar4 = FseDiagnosticsInitializeEventsList(local_68[0],0x10,(short)uVar3 + 0x80);
    iVar2 = (int)uVar4;
    if (iVar2 == 0) {
      uVar4 = FseDiagnosticsInitializeEventsList(lVar5 + 0x20,0x14,(short)uVar4 + 0x20);
      iVar2 = (int)uVar4;
      if (iVar2 == 0) {
        DAT_14002a7c0 = lVar5;
        lVar5 = 0;
        local_68[0] = 0;
      }
    }
  }
  if (lVar5 != 0) {
    if (-1 < iVar2) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    if (*(longlong *)(lVar5 + 0x10) != 0) {
      FseFreeMemory((longlong *)(lVar5 + 0x10));
    }
    if (*(longlong *)(lVar5 + 0x30) != 0) {
      FseFreeMemory((longlong *)(lVar5 + 0x30));
    }
    FseFreeMemory(local_68);
  }
  if ((iVar2 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseDiagnosticsContextInitialize returned error";
      local_28 = local_68;
      local_30 = 0x2f;
      local_68[0] = CONCAT44(local_68[0]._4_4_,iVar2);
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026931,0,0,4,local_58);
    }
  }
  return iVar2;
}



===== FseDiagnosticsInitializeEventsList @ 14000d788 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseDiagnosticsInitializeEventsList(longlong param_1,int param_2,ushort param_3)

{
  bool bVar1;
  ulonglong uVar2;
  undefined1 auStackY_98 [32];
  int local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  *(int *)(param_1 + 8) = param_2;
  *(ushort *)(param_1 + 0xc) = param_3;
  uVar2 = FseAllocMemory((ulonglong)((uint)param_3 * param_2),0x64657346,
                         (undefined8 *)(param_1 + 0x10));
  local_68[0] = (int)uVar2;
  if (local_68[0] == 0) {
    KeInitializeSpinLock(param_1);
  }
  else if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseDiagnosticsInitializeEventsList returned error";
      local_28 = local_68;
      local_30 = 0x32;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026967,0,0,4,local_58);
    }
  }
  return uVar2 & 0xffffffff;
}



===== FseDiagnosticsInsertRecord @ 14000d8a0 =====

longlong FseDiagnosticsInsertRecord(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar1 = *(ushort *)(param_1 + 0xc);
  uVar2 = *(ushort *)(param_1 + 0x1a);
  uVar3 = *(ushort *)(param_1 + 0x18);
  if (uVar2 < uVar1) {
    uVar4 = (uint)uVar3 + (uint)uVar2;
  }
  else {
    uVar4 = (uint)uVar3;
    *(short *)(param_1 + 0x18) = (short)((uVar3 + 1) % (uint)uVar1);
  }
  if (uVar2 < uVar1) {
    *(ushort *)(param_1 + 0x1a) = uVar2 + 1;
  }
  return (ulonglong)((uVar4 & 0xffff) * *(int *)(param_1 + 8)) + *(longlong *)(param_1 + 0x10);
}



===== FseDiagnosticsLogFailure @ 14000d8fc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseDiagnosticsLogFailure(undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = 0;
  local_res20 = _DAT_fffff78000000014;
  ExSystemTimeToLocalTime(&local_res20,&local_res18);
  if (DAT_14002a7c0 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar1 = DAT_14002a7c0;
  KeAcquireSpinLockRaiseToDpc(DAT_14002a7c0);
  puVar2 = (undefined4 *)FseDiagnosticsInsertRecord(lVar1);
  *puVar2 = param_1;
  puVar2[1] = param_2;
  puVar2[2] = (undefined4)local_res18;
  puVar2[3] = local_res18._4_4_;
  KeReleaseSpinLock();
  return;
}



===== FseDiagnosticsLogPktsWithNoMatchingPartitions @ 14000d9a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseDiagnosticsLogPktsWithNoMatchingPartitions
               (undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined1 auStackY_98 [32];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58 [4];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  local_68 = 0;
  local_60 = _DAT_fffff78000000014;
  ExSystemTimeToLocalTime(&local_60,&local_68);
  if (DAT_14002a7c0 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar3 = DAT_14002a7c0 + 0x20;
  KeAcquireSpinLockRaiseToDpc(lVar3);
  puVar2 = (undefined4 *)FseDiagnosticsInsertRecord(lVar3);
  *puVar2 = param_1;
  puVar2[1] = param_2;
  *(undefined2 *)(puVar2 + 2) = param_3;
  *(undefined2 *)((longlong)puVar2 + 10) = param_4;
  puVar2[3] = (undefined4)local_68;
  puVar2[4] = local_68._4_4_;
  KeReleaseSpinLock();
  if (2 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x20000) == 0) || ((DAT_14002a018 & 0x20000) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_2c = 0;
      local_30 = 0x14;
      local_38 = puVar2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002681c,0,0,3,local_58);
    }
  }
  return;
}



===== FseDiagnosticsRundownFailures @ 14000db0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FseDiagnosticsRundownFailures(void)

{
  char *_Src;
  bool bVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  ushort uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  longlong lVar11;
  size_t sVar12;
  size_t _Size;
  undefined1 auStackY_108 [32];
  ushort local_d8 [2];
  undefined1 local_d4;
  int *local_d0;
  longlong local_c8;
  char *local_b8 [4];
  ushort *local_98;
  char *local_90;
  int *local_88;
  char *local_80;
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  char *local_58;
  char *local_50;
  char *local_48;
  char *local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  piVar8 = (int *)0x0;
  local_b8[0] = "IOCTL_CREATE_PARTITION";
  uVar10 = 0;
  local_d0 = (int *)0x0;
  local_b8[1] = "IOCTL_DELETE_PARTITION";
  local_b8[2] = "IOCTL_RESUME_PARTITION";
  local_b8[3] = "IOCTL_CREATE_NIC_PAIR";
  local_98 = (ushort *)0x140022538;
  local_90 = "IOCTL_CONFIG_PORT_POLICY";
  local_88 = (int *)0x140022570;
  local_80 = "IPS_CLIENT_PROVIDER_ATTACH";
  local_78 = "IPS_CLIENT_INTERFACE_ATTACH";
  local_70 = "IPS_CLIENT_INTERFACE_DETACH";
  local_68 = "IPS_CLIENT_PHYSICAL_IF_ADD";
  local_60 = "IPS_CLIENT_HOST_VNIC_ATTACH";
  local_58 = "IPS_CLIENT_HOST_VNIC_DETACH";
  local_50 = "IPS_CLIENT_SET_HOST_VNIC";
  local_48 = "SHIM_PACKET_DROP";
  local_40 = "IOCTL_INTERPARTITION_LOOPBACK";
  local_d8[0] = 0;
  if (DAT_14002a7c0 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar2 = DAT_14002a7c0;
  lVar11 = *(longlong *)(DAT_14002a7c0 + 0x10);
  local_c8 = lVar11;
  uVar3 = KeAcquireSpinLockRaiseToDpc(DAT_14002a7c0);
  local_d4 = uVar3;
  if (*(short *)(lVar2 + 0x1a) == 0) {
    if (5 < DAT_14002a000) {
      if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_90 = (char *)0x17;
        local_98 = (ushort *)0x1400226a0;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026906,0,0,3,local_b8);
      }
    }
  }
  else {
    uVar6 = *(ushort *)(lVar2 + 0x18);
    bVar1 = true;
    local_d8[0] = 0;
    if (*(short *)(lVar2 + 0x1a) != 0) {
      local_d8[0] = 0;
      do {
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (local_b8[*(int *)(lVar11 + (ulonglong)uVar6 * 0x10)][lVar4] != '\0');
        local_d8[0] = local_d8[0] + 1;
        uVar10 = uVar10 + 0xe + (int)lVar4;
        uVar6 = uVar6 + 1 & 0x7f;
      } while (local_d8[0] < *(ushort *)(lVar2 + 0x1a));
    }
    uVar5 = FseAllocMemory((ulonglong)uVar10,0x64657346,&local_d0);
    piVar8 = local_d0;
    if ((int)uVar5 == 0) {
      uVar6 = *(ushort *)(lVar2 + 0x18);
      local_d8[0] = 0;
      piVar9 = local_d0;
      if (*(short *)(lVar2 + 0x1a) != 0) {
        do {
          piVar7 = (int *)((ulonglong)uVar6 * 0x10 + lVar11);
          _Src = local_b8[*piVar7];
          _Size = 0xffffffffffffffff;
          do {
            sVar12 = _Size;
            _Size = sVar12 + 1;
          } while (_Src[_Size] != '\0');
          *piVar9 = piVar7[1];
          *(undefined8 *)(piVar9 + 1) = *(undefined8 *)(piVar7 + 2);
          *(short *)(piVar9 + 3) = (short)_Size;
          memmove((void *)((longlong)piVar9 + 0xe),_Src,_Size);
          local_d8[0] = local_d8[0] + 1;
          piVar9 = (int *)((longlong)piVar9 + sVar12 + 0xf);
          uVar6 = uVar6 + 1 & 0x7f;
          lVar11 = local_c8;
        } while (local_d8[0] < *(ushort *)(lVar2 + 0x1a));
      }
      if (4 < DAT_14002a000) {
        if (((uRam000000014002a011 & 0x800) == 0) || ((DAT_14002a018 & 0x80000) != DAT_14002a018)) {
          bVar1 = false;
        }
        if (bVar1) {
          local_98 = local_d8;
          local_90 = (char *)0x2;
          local_88 = piVar8;
          local_80 = (char *)(ulonglong)uVar10;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400268b3,0,0,4,local_b8);
        }
      }
      uVar3 = local_d4;
    }
  }
  KeReleaseSpinLock(lVar2,uVar3);
  if (piVar8 != (int *)0x0) {
    FseFreeMemory((longlong *)&local_d0);
  }
  return;
}



===== FseDiagnosticsRundownNicPairs @ 14000de80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FseDiagnosticsRundownNicPairs(void)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  byte *pbVar5;
  void *pvVar6;
  longlong lVar7;
  ushort uVar8;
  ulonglong uVar9;
  undefined1 auStackY_a8 [32];
  undefined4 uVar10;
  ushort local_78 [4];
  void *local_70;
  longlong local_68;
  ulonglong local_60;
  undefined8 local_58 [4];
  ushort *local_38;
  undefined8 local_30;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  pvVar6 = (void *)0x0;
  local_78[0] = 0;
  local_70 = (void *)0x0;
  local_60 = 0;
  lVar7 = 0;
  local_68 = 0;
  iVar2 = FseCoreListAllNicPairEntries(DAT_14002a7a8,local_78,&local_60,(void *)0x0);
  if (iVar2 != -0x7ffffffb) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if ((local_78[0] == 0) || (local_60 == 0)) {
    if (DAT_14002a000 < 5) {
      return;
    }
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return;
    }
    local_30 = 0x37;
    local_38 = (ushort *)0x1400226f0;
    pbVar5 = &DAT_140026727;
    uVar10 = 3;
  }
  else {
    uVar3 = FseAllocMemory(local_60,0x64657346,&local_70);
    if ((int)uVar3 != 0) {
      pvVar6 = local_70;
      goto LAB_14000e096;
    }
    uVar4 = (ulonglong)local_78[0];
    uVar3 = FseAllocMemory(uVar4 * 0x18,0x64657346,&local_68);
    pvVar6 = local_70;
    if ((int)uVar3 != 0) {
      lVar7 = local_68;
      goto LAB_14000e096;
    }
    iVar2 = FseCoreListAllNicPairEntries(DAT_14002a7a8,local_78,&local_60,local_70);
    lVar7 = local_68;
    if (iVar2 != 0) goto LAB_14000e096;
    bVar1 = true;
    uVar9 = 0;
    if (local_78[0] != 0) {
      do {
        uVar8 = (short)uVar9 + 1;
        *(undefined8 *)(local_68 + uVar9 * 0x18) =
             *(undefined8 *)((longlong)pvVar6 + uVar9 * 0x48 + 0x18);
        *(undefined8 *)(local_68 + 8 + uVar9 * 0x18) =
             *(undefined8 *)((longlong)pvVar6 + uVar9 * 0x48);
        *(undefined8 *)(local_68 + 0x10 + uVar9 * 0x18) =
             *(undefined8 *)((longlong)pvVar6 + uVar9 * 0x48 + 0x30);
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 < local_78[0]);
    }
    if (DAT_14002a000 < 5) goto LAB_14000e096;
    if (((uRam000000014002a011 & 0x800) == 0) || ((DAT_14002a018 & 0x80000) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (!bVar1) goto LAB_14000e096;
    local_38 = local_78;
    local_30 = 2;
    pbVar5 = &DAT_1400266c2;
    local_28 = local_68;
    uVar10 = 4;
    local_20 = (undefined4)(uVar4 * 0x18);
    local_1c = 0;
  }
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar5,0,0,uVar10,local_58);
LAB_14000e096:
  if (pvVar6 != (void *)0x0) {
    FseFreeMemory((longlong *)&local_70);
  }
  if (lVar7 != 0) {
    FseFreeMemory(&local_68);
  }
  return;
}



===== FseDiagnosticsRundownPktsWithNoMatchingPartitions @ 14000e0e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FseDiagnosticsRundownPktsWithNoMatchingPartitions(void)

{
  ushort *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  bool bVar5;
  longlong lVar6;
  undefined1 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  byte *pbVar10;
  longlong lVar11;
  ulonglong uVar12;
  ushort uVar13;
  uint uVar14;
  undefined1 auStackY_b8 [32];
  undefined4 uVar15;
  longlong local_88 [2];
  undefined8 local_78 [4];
  ushort *local_58;
  undefined8 local_50;
  longlong local_48;
  uint local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar11 = 0;
  local_88[0] = 0;
  if (DAT_14002a7c0 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar6 = DAT_14002a7c0;
  lVar4 = *(longlong *)(DAT_14002a7c0 + 0x30);
  uVar7 = KeAcquireSpinLockRaiseToDpc(DAT_14002a7c0 + 0x20);
  puVar1 = (ushort *)(lVar6 + 0x3a);
  if (*puVar1 == 0) {
    if (DAT_14002a000 < 6) goto LAB_14000e2a6;
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (!bVar5) goto LAB_14000e2a6;
    local_50 = 0x32;
    local_58 = (ushort *)0x1400226b8;
    pbVar10 = &DAT_1400267f1;
    uVar15 = 3;
  }
  else {
    uVar14 = (uint)*puVar1 * 0x14;
    uVar8 = FseAllocMemory((ulonglong)uVar14,0x64657346,local_88);
    lVar11 = local_88[0];
    if ((int)uVar8 != 0) goto LAB_14000e2a6;
    uVar13 = 0;
    bVar5 = true;
    uVar12 = (ulonglong)*(ushort *)(lVar6 + 0x38);
    if (*puVar1 != 0) {
      do {
        uVar9 = (ulonglong)uVar13;
        puVar2 = (undefined8 *)(lVar4 + uVar12 * 0x14);
        uVar8 = puVar2[1];
        uVar13 = uVar13 + 1;
        puVar3 = (undefined8 *)(local_88[0] + uVar9 * 0x14);
        *puVar3 = *puVar2;
        puVar3[1] = uVar8;
        *(undefined4 *)(local_88[0] + 0x10 + uVar9 * 0x14) =
             *(undefined4 *)(lVar4 + 0x10 + uVar12 * 0x14);
        uVar12 = (ulonglong)(ushort)((short)uVar12 + 1) & 0xffffffffffff001f;
      } while (uVar13 < *puVar1);
    }
    if (DAT_14002a000 < 5) goto LAB_14000e2a6;
    if (((uRam000000014002a011 & 0x800) == 0) || ((DAT_14002a018 & 0x80000) != DAT_14002a018)) {
      bVar5 = false;
    }
    if (!bVar5) goto LAB_14000e2a6;
    pbVar10 = &DAT_140026752;
    uVar15 = 4;
    local_50 = 2;
    local_48 = local_88[0];
    local_3c = 0;
    local_58 = puVar1;
    local_40 = uVar14;
  }
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar10,0,0,uVar15,local_78);
LAB_14000e2a6:
  KeReleaseSpinLock(lVar6 + 0x20,uVar7);
  if (lVar11 != 0) {
    FseFreeMemory(local_88);
  }
  return;
}



===== FseDiagnosticsTlgCallback @ 14000e300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FseDiagnosticsTlgCallback(undefined8 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  undefined1 auStackY_f8 [32];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98 [4];
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  cVar3 = ExAcquireRundownProtection(&DAT_14002a7c8);
  if ((cVar3 != '\0') && (bVar2 = true, param_2 - 1U < 2)) {
    FseIpsClientRundownHelper();
    FsePortPolicyRundownHelper();
    FseDiagnosticsRundownNicPairs();
    FseDiagnosticsRundownFailures();
    FseDiagnosticsRundownPktsWithNoMatchingPartitions();
    if (4 < DAT_14002a000) {
      if (((_DAT_14002a010 & 0x80000) == 0) ||
         (bVar1 = true, (DAT_14002a018 & 0x80000) != DAT_14002a018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_c8 = DAT_14002a818;
        local_78 = &local_c8;
        local_70 = 8;
        local_c0 = DAT_14002a820;
        local_68 = &local_c0;
        local_b8 = DAT_14002a830;
        local_58 = &local_b8;
        local_b0 = DAT_14002a828;
        local_48 = &local_b0;
        local_a8 = DAT_14002a838;
        local_38 = &local_a8;
        local_a0 = DAT_14002a840;
        local_28 = &local_a0;
        local_60 = 8;
        local_50 = 8;
        local_40 = 8;
        local_30 = 8;
        local_20 = 8;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002662b,0,0,8,local_98);
      }
      if (4 < DAT_14002a000) {
        if (((_DAT_14002a010 & 0x80000) == 0) || ((DAT_14002a018 & 0x80000) != DAT_14002a018)) {
          bVar2 = false;
        }
        if (bVar2) {
          local_a0 = DAT_14002a7e0;
          local_78 = &local_a0;
          local_70 = 8;
          local_a8 = DAT_14002a7e8;
          local_68 = &local_a8;
          local_b0 = DAT_14002a7f8;
          local_58 = &local_b0;
          local_b8 = DAT_14002a7f0;
          local_48 = &local_b8;
          local_c0 = DAT_14002a800;
          local_38 = &local_c0;
          local_c8 = DAT_14002a808;
          local_28 = &local_c8;
          local_60 = 8;
          local_50 = 8;
          local_40 = 8;
          local_30 = 8;
          local_20 = 8;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026593,0,0,8,local_98);
        }
      }
    }
  }
  return 0;
}



===== FseTraceEnableCallback @ 14000e580 =====

void FseTraceEnableCallback
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,ulonglong param_4,
               byte param_5)

{
  ulonglong uVar1;
  char cVar2;
  byte *pbVar3;
  undefined8 uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  undefined *puVar7;
  ulonglong local_res10;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  if ((((param_4 & 9) != 0) && (3 < param_5)) &&
     (local_res10 = param_2, cVar2 = ExAcquireRundownProtection(&DAT_14002a7c8), cVar2 != '\0')) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids);
    }
    puVar7 = (undefined *)0x40;
    memset(&local_68,0,0x40);
    FseAllocatorQueryStatistics(&local_68);
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
        puVar7 = &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids);
      }
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,puVar7,local_68);
        }
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,puVar7,local_64);
          }
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
              WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,puVar7,local_60);
            }
            if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
              if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,puVar7,local_5c);
              }
              if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,puVar7,local_58);
                }
                if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                  if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,puVar7,local_54);
                  }
                  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,puVar7,local_50);
                    }
                    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                      if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,puVar7,uStack_4c);
                      }
                      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                        if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,puVar7,local_48);
                        }
                        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                          if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,puVar7,
                                     uStack_44);
                          }
                          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                            if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                              puVar7 = &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids;
                              WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                                       &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,
                                       CONCAT44(uStack_3c,local_40));
                            }
                            if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                              if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                                puVar7 = &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids;
                                WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                                         &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,local_38);
                              }
                              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,puVar7,
                                         local_30);
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
    local_res10 = 0;
    pbVar3 = (byte *)0x0;
    FseAllocatorQueryPartitions(0,0,&local_res10);
    if (local_res10 != 0) {
      do {
        uVar1 = local_res10;
        if (pbVar3 != (byte *)0x0) {
          ExFreePoolWithTag(pbVar3,0x64657346);
        }
        pbVar3 = (byte *)ExAllocatePool2(0x40,uVar1 << 4,0x64657346);
        if (pbVar3 == (byte *)0x0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                    &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids);
          }
          uVar6 = 0;
          break;
        }
        FseAllocatorQueryPartitions(uVar1,(longlong)pbVar3,&local_res10);
        uVar6 = local_res10;
      } while (uVar1 < local_res10);
      if (uVar6 != 0) {
        pbVar5 = pbVar3;
        do {
          puVar7 = (undefined *)0x40;
          memset(&local_68,0,0x40);
          uVar4 = PtServerGetStatisticsForPartition(pbVar5,&local_68);
          if ((int)uVar4 == 0) {
            if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
              if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                puVar7 = &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids;
                WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                              &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,pbVar5);
              }
              if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,puVar7,local_58);
                }
                if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                  if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                    puVar7 = &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids;
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                             &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,local_54);
                  }
                  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                      puVar7 = &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids;
                      WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                               &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,
                               CONCAT44(uStack_4c,local_50));
                    }
                    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                      if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                        puVar7 = &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids;
                        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                                 &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,
                                 CONCAT44(uStack_44,local_48));
                      }
                      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                        if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,puVar7,local_40);
                        }
                        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                          if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
                            WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                                     &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,local_38);
                          }
                          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                            WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                                     &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,
                                     CONCAT44(uStack_2c,local_30));
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                           &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,pbVar5,(char)uVar4);
          }
          pbVar5 = pbVar5 + 0x10;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
    }
    if (pbVar3 != (byte *)0x0) {
      ExFreePoolWithTag(pbVar3,0x64657346);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids);
    }
    ExReleaseRundownProtection(&DAT_14002a7c8);
  }
  return;
}



===== WPP_SF_I @ 14000eb08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_I(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_L @ 14000eb4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8c43b4af8ba236cb63841b373b9e762e_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF__guid_ @ 14000eb94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,0x10,0);
  return;
}



===== WPP_SF__guid_d @ 14000ebd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,0x10,&param_5,4,0);
  return;
}



===== DpcTimerWorkerTcp @ 14000ec20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DpcTimerWorkerTcp(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [4];
  char *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  bVar1 = true;
  if (5 < DAT_14002a000) {
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_1c = 0;
      local_28 = "DpcTimerWorkerTcp called, building cache start";
      local_20 = 0x2f;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026a1e,0,0,3,local_48);
    }
  }
  LOCK();
  DAT_14002a448 = 0;
  UNLOCK();
  FseAllocatorRebuildDatapathCache(6);
  if (5 < DAT_14002a000) {
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_1c = 0;
      local_28 = "DpcTimerWorkerTcp called, building cache end";
      local_20 = 0x2d;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400269f3,0,0,3,local_48);
    }
  }
  return;
}



===== DpcTimerWorkerUdp @ 14000ed50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DpcTimerWorkerUdp(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [4];
  char *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  bVar1 = true;
  if (5 < DAT_14002a000) {
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_1c = 0;
      local_28 = "DpcTimerWorkerUdp called, building cache start";
      local_20 = 0x2f;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400269c8,0,0,3,local_48);
    }
  }
  LOCK();
  DAT_14002a318 = 0;
  UNLOCK();
  FseAllocatorRebuildDatapathCache(0x11);
  if (5 < DAT_14002a000) {
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_1c = 0;
      local_28 = "DpcTimerWorkerUdp called, building cache end";
      local_20 = 0x2d;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002699d,0,0,3,local_48);
    }
  }
  return;
}



===== FseAllocatorBeginActiveRequest @ 14000ee80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FseAllocatorBeginActiveRequest(int param_1)

{
  ulonglong *_Src;
  bool bVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong *_Dst;
  int *piVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  size_t _Size;
  int *piVar9;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 *local_38;
  uint local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  piVar9 = (int *)&DAT_14002a320;
  if (param_1 != 6) {
    piVar9 = (int *)&DAT_14002a1f0;
  }
  uVar2 = ExAcquireSpinLockExclusive(piVar9);
  local_78[0] = 0;
  _Src = (ulonglong *)(piVar9 + 2);
  uVar3 = KeQueryInterruptTimePrecise(local_78);
  uVar4 = *_Src;
  uVar3 = uVar3 / 1000000;
  if (uVar3 == uVar4) {
    piVar9[4] = piVar9[4] + 1;
  }
  else {
    if (uVar3 < uVar4 + 10) {
      if (uVar3 < uVar4) {
        if (uVar4 < uVar3 + 10) {
          uVar4 = (ulonglong)(uint)((int)*_Src - (int)uVar3);
          piVar9[uVar4 * 4 + 4] = piVar9[uVar4 * 4 + 4] + 1;
          _Src[uVar4 * 2] = uVar3;
        }
        goto LAB_14000ef96;
      }
      uVar8 = (int)uVar3 - (int)*_Src;
      _Size = (ulonglong)uVar8 * 0x10;
      memmove(_Src + (ulonglong)uVar8 * 2,_Src,(ulonglong)(10 - uVar8) << 4);
      _Dst = _Src;
    }
    else {
      _Size = 0x98;
      _Dst = (ulonglong *)(piVar9 + 4);
    }
    memset(_Dst,0,_Size);
    *_Src = uVar3;
    piVar9[4] = 1;
  }
LAB_14000ef96:
  bVar1 = true;
  uVar8 = 0;
  lVar7 = 10;
  piVar5 = piVar9;
  do {
    lVar6 = lVar7;
    piVar5 = piVar5 + 4;
    uVar8 = uVar8 + *piVar5;
    lVar7 = lVar6 + -1;
  } while (lVar7 != 0);
  ExReleaseSpinLockExclusive(piVar9,uVar2);
  local_30 = (int)lVar6 + 3;
  if (local_30 < DAT_14002a000) {
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_3c = 0;
      local_2c = 0;
      local_48 = "FseAllocatorBeginActiveRequest: aboveThreshold=";
      local_38 = local_78;
      local_40 = 0x30;
      local_78[0] = CONCAT44(local_78[0]._4_4_,(uint)(0x32 < uVar8));
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026a49,0,0,local_30,local_68);
    }
  }
  return 0x32 < uVar8;
}



===== FseAllocatorEndActiveRequest @ 14000f080 =====

void FseAllocatorEndActiveRequest(int param_1,char param_2)

{
  undefined *puVar1;
  
  if (param_2 != '\0') {
    puVar1 = &DAT_14002a320;
    if (param_1 != 6) {
      puVar1 = &DAT_14002a1f0;
    }
    ScheduleCacheRebuildTimer((longlong)puVar1);
  }
  return;
}



===== ScheduleCacheRebuildTimer @ 14000f0b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ScheduleCacheRebuildTimer(longlong param_1)

{
  int *piVar1;
  bool bVar2;
  undefined1 auStackY_98 [32];
  int local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar2 = true;
  LOCK();
  piVar1 = (int *)(param_1 + 0x128);
  local_68[0] = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  local_68[0] = local_68[0] + 1;
  if (local_68[0] < 2) {
    if (5 < DAT_14002a000) {
      if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
        bVar2 = false;
      }
      if (bVar2) {
        local_2c = 0;
        local_38 = "Timer not running, queuing now.";
        local_30 = 0x20;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026a7b,0,0,3,local_58);
      }
    }
    KeSetTimerEx(param_1 + 0xa8,0xffffffffffb3b4c0,0,param_1 + 0xe8);
  }
  else if (5 < DAT_14002a000) {
    if (((DAT_14002a010 & 2) == 0) || (((uint)DAT_14002a018 & 2) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "Timer already queued, pendingCacheRebuildRequests";
      local_28 = local_68;
      local_20 = 4;
      local_30 = 0x32;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026aa6,0,0,4,local_58);
    }
  }
  return;
}



===== ConvertInterfaceGuidToLuid @ 14000f230 =====

NTSTATUS __stdcall ConvertInterfaceGuidToLuid(GUID *InterfaceGuid,PNET_LUID InterfaceLuid)

{
  int iVar1;
  int iVar2;
  ULONG64 UVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  uint local_res8 [2];
  longlong local_res18;
  longlong local_res20;
  
  uVar6 = 0;
  local_res18 = 0;
  local_res20 = 0;
  local_res8[0] = 0;
  if ((InterfaceGuid == (GUID *)0x0) || (InterfaceLuid == (PNET_LUID)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar2 = NsiAllocateAndGetTable
                      (1,&NPI_MS_NDIS_MODULEID,1,&local_res18,8,0,0,0,0,&local_res20,0x238,
                       local_res8,0);
    if (iVar2 < 0) {
      InterfaceLuid->Value = 0;
    }
    else {
      if (local_res8[0] != 0) {
        do {
          lVar4 = uVar6 * 0x238;
          if ((((*(ulong *)(lVar4 + 0x218 + local_res20) == InterfaceGuid->Data1) &&
               (iVar1._0_2_ = InterfaceGuid->Data2, iVar1._2_2_ = InterfaceGuid->Data3,
               *(int *)(lVar4 + 0x21c + local_res20) == iVar1)) &&
              (*(int *)(lVar4 + 0x220 + local_res20) == *(int *)InterfaceGuid->Data4)) &&
             (*(int *)(lVar4 + 0x224 + local_res20) == *(int *)(InterfaceGuid->Data4 + 4))) {
            UVar3 = *(ULONG64 *)(local_res18 + uVar6 * 8);
            goto LAB_14000f334;
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < local_res8[0]);
      }
      UVar3 = 0;
      iVar2 = -0x3ffffff3;
LAB_14000f334:
      InterfaceLuid->Value = UVar3;
      NsiFreeTable(local_res18,0,0);
    }
  }
  return iVar2;
}



===== ConvertInterfaceIndexToLuid @ 14000f374 =====

NTSTATUS __stdcall ConvertInterfaceIndexToLuid(NET_IFINDEX InterfaceIndex,PNET_LUID InterfaceLuid)

{
  int iVar1;
  NET_IFINDEX local_res8 [8];
  
  if (InterfaceLuid == (PNET_LUID)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    local_res8[0] = InterfaceIndex;
    iVar1 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,2,local_res8,4,2,InterfaceLuid,8,0);
    if (iVar1 < 0) {
      InterfaceLuid->Value = 0;
    }
  }
  return iVar1;
}



===== ConvertInterfaceLuidToIndex @ 14000f3e4 =====

NTSTATUS __stdcall ConvertInterfaceLuidToIndex(NET_LUID *InterfaceLuid,PNET_IFINDEX InterfaceIndex)

{
  int iVar1;
  ULONG64 local_res8 [4];
  
  if ((InterfaceLuid == (NET_LUID *)0x0) || (InterfaceIndex == (PNET_IFINDEX)0x0)) {
    iVar1 = 0x57;
  }
  else {
    local_res8[0] = InterfaceLuid->Value;
    iVar1 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,0,local_res8,8,2,InterfaceIndex,4,0);
    if (iVar1 < 0) {
      *InterfaceIndex = 0;
    }
  }
  return iVar1;
}



===== FillIfEntryWithInterfaceInfo @ 14000f45c =====

void FillIfEntryWithInterfaceInfo
               (longlong param_1,undefined8 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  size_t sVar8;
  
  *(undefined4 *)(param_1 + 8) = *param_4;
  uVar1 = *(undefined8 *)(param_4 + 0x88);
  *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_4 + 0x86);
  *(undefined8 *)(param_1 + 0x14) = uVar1;
  memset((void *)(param_1 + 0x1c),0,0x202);
  sVar8 = (size_t)*(ushort *)((longlong)param_2 + 0x14);
  if (0x1ff < sVar8) {
    sVar8 = 0x200;
  }
  memmove((void *)(param_1 + 0x1c),(void *)((longlong)param_2 + 0x16),sVar8);
  memset((void *)(param_1 + 0x21e),0,0x202);
  sVar8 = (size_t)*(ushort *)(param_4 + 1);
  if (0x1ff < sVar8) {
    sVar8 = 0x200;
  }
  memmove((void *)(param_1 + 0x21e),(void *)((longlong)param_4 + 6),sVar8);
  *(uint *)(param_1 + 0x420) = (uint)*(ushort *)(param_2 + 0x43);
  memmove((void *)(param_1 + 0x424),(void *)((longlong)param_2 + 0x21a),
          (ulonglong)*(ushort *)(param_2 + 0x43));
  memmove((void *)(param_1 + 0x444),param_4 + 0x8b,(ulonglong)*(ushort *)(param_2 + 0x43));
  lVar4 = 0;
  if (*(longlong *)(param_3 + 6) != -1) {
    lVar4 = *(longlong *)(param_3 + 6);
  }
  *(longlong *)(param_1 + 0x4a8) = lVar4;
  lVar4 = 0;
  if (*(longlong *)(param_3 + 8) != -1) {
    lVar4 = *(longlong *)(param_3 + 8);
  }
  *(longlong *)(param_1 + 0x4b0) = lVar4;
  uVar1 = param_2[1];
  *(undefined8 *)(param_1 + 0x490) = *param_2;
  *(undefined8 *)(param_1 + 0x498) = uVar1;
  *(undefined4 *)(param_1 + 0x4a0) = param_4[0x85];
  *(undefined4 *)(param_1 + 0x484) = *param_3;
  *(uint *)(param_1 + 0x468) = (uint)*(ushort *)(param_4 + 0x82);
  *(undefined4 *)(param_1 + 0x464) = param_3[4];
  *(undefined4 *)(param_1 + 0x488) = *(undefined4 *)(param_2 + 2);
  *(undefined4 *)(param_1 + 0x48c) = param_3[2];
  *(undefined4 *)(param_1 + 0x470) = param_4[0x94];
  *(undefined4 *)(param_1 + 0x474) = param_4[0x95];
  *(undefined4 *)(param_1 + 0x478) = param_4[0x83];
  *(undefined4 *)(param_1 + 0x47c) = param_4[0x84];
  *(undefined8 *)(param_1 + 0x4b8) = *(undefined8 *)(param_3 + 0x14);
  *(undefined8 *)(param_1 + 0x4c0) = *(undefined8 *)(param_3 + 0x16);
  *(longlong *)(param_1 + 0x4c8) = *(longlong *)(param_3 + 0x1a) + *(longlong *)(param_3 + 0x18);
  *(undefined8 *)(param_1 + 0x4d0) = *(undefined8 *)(param_3 + 0x10);
  bVar2 = *(byte *)(param_1 + 0x480);
  *(undefined8 *)(param_1 + 0x4d8) = *(undefined8 *)(param_3 + 0x12);
  *(undefined8 *)(param_1 + 0x4e0) = *(undefined8 *)(param_3 + 0xe);
  *(undefined8 *)(param_1 + 0x500) = *(undefined8 *)(param_3 + 0x1c);
  *(undefined8 *)(param_1 + 0x508) = *(undefined8 *)(param_3 + 0x1e);
  *(longlong *)(param_1 + 0x510) = *(longlong *)(param_3 + 0x22) + *(longlong *)(param_3 + 0x20);
  *(undefined8 *)(param_1 + 0x518) = *(undefined8 *)(param_3 + 0x26);
  uVar1 = *(undefined8 *)(param_3 + 0x24);
  *(undefined8 *)(param_1 + 0x540) = 0;
  *(undefined8 *)(param_1 + 0x520) = uVar1;
  *(undefined8 *)(param_1 + 0x4e8) = *(undefined8 *)(param_3 + 0x28);
  *(undefined8 *)(param_1 + 0x4f8) = *(undefined8 *)(param_3 + 0x2c);
  *(undefined8 *)(param_1 + 0x4f0) = *(undefined8 *)(param_3 + 0x2a);
  *(undefined8 *)(param_1 + 0x528) = *(undefined8 *)(param_3 + 0x2e);
  *(undefined8 *)(param_1 + 0x538) = *(undefined8 *)(param_3 + 0x32);
  *(undefined8 *)(param_1 + 0x530) = *(undefined8 *)(param_3 + 0x30);
  bVar3 = *(byte *)(param_4 + 0x93);
  *(byte *)(param_1 + 0x480) = bVar2 & 0xfe | bVar3 & 1;
  bVar7 = bVar2 & 0xfc | bVar3 & 1 | *(byte *)(param_4 + 0x93) & 2;
  *(byte *)(param_1 + 0x480) = bVar7;
  bVar7 = (*(char *)(param_4 + 0x8a) << 2 ^ bVar7) & 4 ^ bVar7;
  *(byte *)(param_1 + 0x480) = bVar7;
  bVar2 = (*(byte *)(param_3 + 1) & 1) << 3;
  *(byte *)(param_1 + 0x480) = bVar2 | bVar7 & 0xf7;
  bVar5 = (*(byte *)(param_3 + 1) & 2) << 3;
  *(byte *)(param_1 + 0x480) = bVar5 | bVar2 | bVar7 & 0xe7;
  bVar3 = (*(byte *)(param_3 + 1) & 4) << 3;
  *(byte *)(param_1 + 0x480) = bVar3 | bVar5 | bVar2 | bVar7 & 199;
  bVar6 = (*(byte *)(param_3 + 1) & 8) << 3;
  *(byte *)(param_1 + 0x480) = bVar6 | bVar3 | bVar5 | bVar2 | bVar7 & 0x87;
  *(byte *)(param_1 + 0x480) =
       (*(byte *)(param_4 + 0x93) & 0xc0) * '\x02' | bVar6 | bVar3 | bVar5 | bVar2 | bVar7 & 7;
  return;
}



===== FillIpInterfaceRow @ 14000f78c =====

void FillIpInterfaceRow(undefined2 param_1,undefined2 *param_2,ULONG64 *param_3,undefined1 *param_4,
                       longlong param_5,undefined1 *param_6)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  *param_2 = param_1;
  ((NET_LUID *)(param_2 + 4))->Value = *param_3;
  ConvertInterfaceLuidToIndex((NET_LUID *)(param_2 + 4),(PNET_IFINDEX)(param_2 + 8));
  *(undefined4 *)(param_2 + 0x10) = 200;
  puVar1 = (undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_2 + 0x12) = 600;
  *(undefined4 *)(param_2 + 10) = 0;
  *(undefined8 *)(param_2 + 0xc) = 0;
  *(undefined1 *)(param_2 + 0x14) = *param_4;
  lVar2 = 0x10;
  *(undefined1 *)((longlong)param_2 + 0x29) = param_4[1];
  *(undefined1 *)(param_2 + 0x15) = param_4[3];
  *(undefined1 *)((longlong)param_2 + 0x2b) = param_4[4];
  *(undefined1 *)(param_2 + 0x16) = param_4[6];
  *(undefined1 *)((longlong)param_2 + 0x2d) = param_4[5];
  *(undefined1 *)(param_2 + 0x17) = param_4[10];
  *(undefined1 *)((longlong)param_2 + 0x2f) = param_4[0xb];
  *(undefined1 *)(param_2 + 0x18) = param_4[0xc];
  *(undefined4 *)(param_2 + 0x1a) = *(undefined4 *)(param_4 + 0x14);
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_4 + 0x2c);
  *(undefined4 *)(param_2 + 0x1e) = *(undefined4 *)(param_4 + 0x20);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_4 + 0x24);
  *(undefined4 *)(param_2 + 0x22) = *(undefined4 *)(param_4 + 0x28);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_4 + 0x30);
  *(undefined4 *)(param_2 + 0x26) = *(undefined4 *)(param_4 + 0x34);
  do {
    *puVar1 = *(undefined4 *)(param_4 + (-0x18 - (longlong)param_2) + (longlong)puVar1);
    puVar1 = puVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(param_4 + 0x7c);
  *(undefined4 *)(param_2 + 0x4a) = *(undefined4 *)(param_4 + 0x1c);
  *(undefined4 *)(param_2 + 0x4c) = *(undefined4 *)(param_4 + 0x78);
  *(undefined1 *)(param_2 + 0x53) = param_4[0x98];
  *(bool *)(param_2 + 0x4e) = *(int *)(param_5 + 0x10) != 0;
  *(undefined1 *)((longlong)param_2 + 0x9d) = *(undefined1 *)(param_5 + 8);
  *(undefined1 *)(param_2 + 0x4f) = *param_6;
  *(undefined1 *)((longlong)param_2 + 0x9f) = param_6[1];
  *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_5 + 0xc);
  *(undefined1 *)(param_2 + 0x52) = *(undefined1 *)(param_5 + 0x20);
  *(undefined1 *)((longlong)param_2 + 0xa5) = *(undefined1 *)(param_5 + 0x21);
  return;
}



===== GetIpInterfaceEntry @ 14000f8d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS __stdcall GetIpInterfaceEntry(PMIB_IPINTERFACE_ROW Row)

{
  ADDRESS_FAMILY AVar1;
  NET_IF_COMPARTMENT_ID NVar2;
  NTSTATUS NVar3;
  int iVar4;
  undefined *puVar5;
  undefined1 auStackY_208 [32];
  NET_LUID local_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined1 local_178 [4];
  NET_IF_COMPARTMENT_ID local_174;
  undefined1 local_118 [240];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_208;
  NVar2 = GetCurrentThreadCompartmentId();
  local_1a8.Value = 0;
  memset(local_118,0,0xf0);
  memset(local_178,0,0x58);
  local_1a0 = 0;
  uStack_198 = 0;
  local_190 = 0;
  uStack_188 = 0;
  if (Row == (PMIB_IPINTERFACE_ROW)0x0) {
LAB_14000f941:
    iVar4 = -0x3ffffff3;
  }
  else {
    AVar1 = Row->Family;
    if (AVar1 == 2) {
      puVar5 = &NPI_MS_IPV4_MODULEID;
    }
    else {
      if (AVar1 != 0x17) goto LAB_14000f941;
      puVar5 = &NPI_MS_IPV6_MODULEID;
    }
    if ((Row->InterfaceLuid).Value == 0) {
      if (Row->InterfaceIndex == 0) goto LAB_14000f941;
      NVar3 = ConvertInterfaceIndexToLuid(Row->InterfaceIndex,&local_1a8);
      if (NVar3 < 0) {
        return NVar3;
      }
    }
    else {
      local_1a8.Value = (Row->InterfaceLuid).Value;
    }
    iVar4 = NsiGetAllParameters(1,puVar5,7,&local_1a8);
    if (-1 < iVar4) {
      if (local_174 == NVar2) {
        FillIpInterfaceRow(AVar1,&Row->Family,&local_1a8.Value,local_118,(longlong)local_178,
                           (undefined1 *)&local_1a0);
        iVar4 = 0;
      }
      else {
        iVar4 = -0x3ffffddb;
      }
    }
  }
  return iVar4;
}



===== InternalGetIfEntry2Ex @ 14000fa54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int InternalGetIfEntry2Ex(undefined8 param_1,undefined8 param_2,PNET_LUID param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  longlong lVar4;
  short *psVar5;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined8 *local_80;
  undefined4 local_78;
  undefined8 *local_70;
  undefined4 local_68;
  ULONG64 *local_60;
  undefined4 local_58;
  ULONG64 local_48 [2];
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_48[1] = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  if (param_3 == (PNET_LUID)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    if (param_3->Value == 0) {
      if ((NET_IFINDEX)param_3[1].Value == 0) {
        iVar1 = ConvertInterfaceGuidToLuid((GUID *)((longlong)param_3 + 0xc),param_3);
      }
      else {
        iVar1 = ConvertInterfaceIndexToLuid((NET_IFINDEX)param_3[1].Value,param_3);
      }
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x930,0x70614c4e);
    if (puVar2 == (undefined8 *)0x0) {
      iVar1 = -0x3fffffe9;
    }
    else {
      GetCurrentThreadCompartmentId();
      local_48[0] = param_3->Value;
      local_58 = 600;
      local_68 = 0xd8;
      local_78 = 0x444;
      local_88 = 8;
      local_80 = puVar2;
      local_70 = puVar2 + 0x89;
      local_60 = puVar2 + 0xdb;
      iVar1 = NsiGetAllParameters(1,&NPI_MS_NDIS_MODULEID,0,local_48);
      if (-1 < iVar1) {
        FillIfEntryWithInterfaceInfo
                  ((longlong)param_3,puVar2,(undefined4 *)(puVar2 + 0x89),
                   (undefined4 *)(puVar2 + 0xdb));
        if ((int)param_3[0x8d].Value == 0x83) {
          psVar5 = &FamilyTable;
          lVar4 = 2;
          do {
            if (*psVar5 == 2) {
              puVar3 = &NPI_MS_IPV4_MODULEID;
            }
            else {
              puVar3 = &NPI_MS_IPV6_MODULEID;
              if (*psVar5 != 0x17) {
                puVar3 = (undefined *)0x0;
              }
            }
            local_58 = 0x20;
            local_60 = local_48 + 1;
            local_68 = 0;
            local_70 = (undefined8 *)0x0;
            local_78 = 0;
            local_80 = (undefined8 *)0x0;
            local_88 = 8;
            iVar1 = NsiGetAllParameters(1,puVar3,7,param_3);
            if (-1 < iVar1) {
              *(undefined4 *)((longlong)param_3 + 0x46c) = (undefined4)uStack_38;
            }
            psVar5 = psVar5 + 1;
            lVar4 = lVar4 + -1;
          } while (lVar4 != 0);
        }
        iVar1 = 0;
      }
      ExFreePoolWithTag(puVar2,0x70614c4e);
    }
  }
  return iVar1;
}



===== WPP_SF_Dq @ 14000fc6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,0x2c,local_res20,4,
             &param_5,8,0);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000fcc8 =====

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
LAB_14000fed1:
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar6 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar6 = uVar3 | uVar6 & 0xffffbfff;
      }
      uVar5 = uVar6 >> 5 & 0x1ff;
      uVar3 = uVar5 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 5 ^ uVar6) & 0x3fe0 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_14000fda3:
        uVar6 = 0;
        if (param_3 == 2) {
          uVar6 = 2;
        }
        else if (param_3 == 3) {
          uVar6 = 8;
        }
        else if (param_3 == 6) {
          uVar6 = 4;
        }
        else if (param_3 == 7) {
          uVar6 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar6 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar5 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar5 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar5;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar5 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_14000fed1;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar6 = param_3 - 0x140;
          if ((int)uVar6 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar6)) {
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
                param_2[1] = (uVar6 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
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
        goto LAB_14000fda3;
      }
    }
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar6 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar6 = uVar3 | uVar6 & 0xffbfffff;
      }
      uVar5 = uVar6 >> 0xf & 0x7f;
      uVar3 = uVar5 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 0xf ^ uVar6) & 0x3f8000 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 14000ffbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_14001008d;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_14001008d;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_14001008d;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_14001008d;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_14001008d;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_14001008d;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_14001008d;
    }
  }
  uVar3 = 0xff;
LAB_14001008d:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar3);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400100e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400101d4 =====

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
LAB_140010287:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_1400102b5;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140010287;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_1400102b5:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140010440 =====

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



===== wil_details_IsEnabledFallback @ 1400104a4 =====

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



===== GetCurrentThreadCompartmentId @ 140010538 =====

NET_IF_COMPARTMENT_ID __stdcall GetCurrentThreadCompartmentId(void)

{
  int iVar1;
  NET_IF_COMPARTMENT_ID NVar2;
  NET_IF_COMPARTMENT_ID local_res8 [8];
  
  local_res8[0] = 0;
  iVar1 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,8,0,0,0,local_res8,4,0);
  NVar2 = 1;
  if (-1 < iVar1) {
    NVar2 = local_res8[0];
  }
  return NVar2;
}



===== CreateNewEventEntry @ 140010598 =====

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
            memmove(puVar5,*(void **)(param_4 + uVar13 * 0x10),uVar10);
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
          memmove(puVar7,*(void **)(puVar12 + -2),uVar10);
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



===== DestroyEventEntry @ 1400107ec =====

void DestroyEventEntry(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0);
  }
  return;
}



===== EnableFlushTimer @ 140010814 =====

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



===== FinishHash @ 140010870 =====

void FinishHash(int *param_1)

{
  *param_1 = ((uint)(*param_1 * 9) >> 0xb ^ *param_1 * 9) * 0x8001;
  return;
}



===== FlushLookUpTableBucket @ 14001088c =====

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



===== InsertEventEntryInLookUpTable @ 1400109a0 =====

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
  
  lVar8 = DAT_14002a030;
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
      goto LAB_140010b6b;
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
LAB_140010b6b:
  plVar14 = (longlong *)(lVar8 + (ulonglong)(uVar12 & 0x1f) * 8);
  do {
    if (*plVar14 == 0) {
      if (0x3ff < *(uint *)(lVar8 + 0x100)) {
        *(int *)(lVar8 + 0x13c) = *(int *)(lVar8 + 0x13c) + 1;
        local_res8 = 0xc0000023;
        goto LAB_140010d9e;
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
          goto LAB_140010d9e;
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
        goto LAB_140010d9e;
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
            goto LAB_140010c68;
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
LAB_140010c68:
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
LAB_140010d9e:
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



===== RunningHash @ 140010e18 =====

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



===== TlgAggregateInternalFlushTimerCallbackKernelMode @ 140010e50 =====

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



===== InitializeTelemetryAssertsKMWorkerInternal @ 140010e94 =====

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
    _DAT_14002a718 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14002f040,0,0);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14002f008,0,0);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14002f078,0,0);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredNoArgsKM @ 140010f58 =====

void MicrosoftTelemetryAssertTriggeredNoArgsKM(void)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140010f88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140011138) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker(IMAGE_DOS_HEADER *param_1)

{
  code *pcVar1;
  bool bVar2;
  longlong lVar3;
  undefined1 uVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong lVar13;
  undefined1 *puVar14;
  int iVar15;
  undefined1 auStack_168 [8];
  undefined1 auStack_160 [120];
  undefined1 local_e8 [32];
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  char *local_88;
  int local_80;
  undefined4 local_7c;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  char *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  puVar14 = auStack_168;
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  iVar15 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_1400114f1;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar14 = auStack_168;
  for (plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar10 = (longlong *)*plVar10) {
    plVar9 = plVar10 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar9 == param_1) goto LAB_1400110bf;
  }
  plVar9 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar13 = _DAT_fffff78000000320;
  puVar14 = auStack_168;
  if (plVar9 != (longlong *)0x0) {
    *plVar9 = (longlong)param_1;
    uVar7 = KeQueryTimeIncrement();
    puVar14 = auStack_168;
    plVar9[2] = 0;
    *(undefined4 *)(plVar9 + 3) = 0;
    plVar9[1] = (longlong)((ulonglong)uVar7 * lVar13) / 10000 + -0xea61;
    plVar10 = plVar9 + 4;
    plVar12 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar12 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar10 = (longlong *)(*pcVar1)();
      puVar14 = auStack_160;
    }
    *plVar10 = (longlong)plVar12;
    plVar10[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
    plVar12[1] = (longlong)plVar10;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar10;
LAB_1400110bf:
    *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
    *(int *)((longlong)plVar9 + 0x14) = *(int *)((longlong)plVar9 + 0x14) + 1;
    lVar13 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar14 + -8) = 0x1400110cf;
    uVar7 = KeQueryTimeIncrement();
    lVar13 = (longlong)((ulonglong)uVar7 * lVar13) / 10000;
    if (60000 < (ulonglong)(lVar13 - plVar9[1])) {
      if (((IMAGE_DOS_HEADER *)0x13fffffff < param_1) && (param_1 < (IMAGE_DOS_HEADER *)0x140036001)
         ) {
        iVar15 = (int)param_1 + -0x40000000;
      }
      plVar9[1] = lVar13;
      *(int *)(puVar14 + 0x6c) = (int)plVar9[2];
      lVar3 = plVar9[3];
      *(undefined4 *)(puVar14 + 0x70) = *(undefined4 *)((longlong)plVar9 + 0x14);
      *(undefined8 *)(puVar14 + -8) = 0x14001117f;
      KeReleaseSpinLock(&g_AssertSpinLock,CONCAT71((int7)((ulonglong)lVar13 >> 8),uVar4));
      lVar13 = -1;
      if (5 < DAT_14002f040) {
        if (((_DAT_14002f050 & 0x400000000000) == 0) ||
           ((DAT_14002f058 & 0x400000000000) != DAT_14002f058)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_c8 = puVar14 + 0x50;
          local_b8 = puVar14 + 0x54;
          local_a8 = puVar14 + 0x58;
          local_98 = puVar14 + 0x5c;
          *(undefined4 *)(puVar14 + 0x50) = 10;
          local_c0 = 4;
          *(int *)(puVar14 + 0x54) = iVar15;
          local_b0 = 4;
          *(dword *)(puVar14 + 0x58) = 0xc0fb4f83;
          local_a0 = 4;
          *(dword *)(puVar14 + 0x5c) = 0x36000;
          local_90 = 4;
          local_88 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_88 = "<unknown>";
          }
          lVar11 = -1;
          do {
            lVar11 = lVar11 + 1;
          } while (local_88[lVar11] != '\0');
          local_80 = (int)lVar11 + 1;
          *(undefined4 *)(puVar14 + 0x60) = *(undefined4 *)(puVar14 + 0x6c);
          local_78 = puVar14 + 0x60;
          *(undefined4 *)(puVar14 + 100) = *(undefined4 *)(puVar14 + 0x70);
          local_68 = puVar14 + 100;
          local_7c = 0;
          local_70 = 4;
          local_60 = 4;
          *(undefined8 *)(puVar14 + -8) = 0x140011295;
          bVar5 = KeGetCurrentIrql();
          local_50 = 4;
          *(uint *)(puVar14 + 0x68) = (uint)bVar5;
          local_58 = puVar14 + 0x68;
          local_40 = 10;
          local_48 = "<unknown>";
          *(undefined1 **)(puVar14 + 0x28) = local_e8;
          *(undefined4 *)(puVar14 + 0x20) = 0xb;
          *(undefined8 *)(puVar14 + -8) = 0x1400112ef;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x14002f040,&DAT_140026c28,0,0,*(undefined4 *)(puVar14 + 0x20),
                     *(undefined8 **)(puVar14 + 0x28));
        }
      }
      if ((DAT_14002f078 == 0) || ((int)lVar3 != 0)) goto LAB_1400114f1;
      *(undefined8 *)(puVar14 + -8) = 0x14001130c;
      cVar6 = KeGetCurrentIrql();
      if (cVar6 != '\0') goto LAB_1400114f1;
      *(undefined4 *)(puVar14 + 0x40) = 0;
      *(undefined8 *)(puVar14 + 0x38) = 0;
      *(undefined8 *)(puVar14 + 0x30) = 0;
      *(undefined8 *)(puVar14 + 0x28) = 0x36000;
      *(undefined8 *)(puVar14 + 0x20) = 0xc0fb4f83;
      *(undefined8 *)(puVar14 + -8) = 0x140011356;
      iVar8 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1,iVar15);
      if (5 < DAT_14002f040) {
        if (((_DAT_14002f050 & 0x400000000000) == 0) ||
           ((DAT_14002f058 & 0x400000000000) != DAT_14002f058)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_c8 = puVar14 + 0x68;
          local_c0 = 4;
          local_b8 = puVar14 + 100;
          *(undefined4 *)(puVar14 + 0x68) = 10;
          local_a8 = puVar14 + 0x60;
          local_98 = puVar14 + 0x5c;
          *(int *)(puVar14 + 100) = iVar15;
          local_b0 = 4;
          *(dword *)(puVar14 + 0x60) = 0xc0fb4f83;
          local_a0 = 4;
          *(dword *)(puVar14 + 0x5c) = 0x36000;
          local_90 = 4;
          local_88 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_88 = "<unknown>";
          }
          do {
            lVar13 = lVar13 + 1;
          } while (local_88[lVar13] != '\0');
          *(undefined4 *)(puVar14 + 0x58) = *(undefined4 *)(puVar14 + 0x6c);
          local_80 = (int)lVar13 + 1;
          local_78 = puVar14 + 0x58;
          local_7c = 0;
          *(undefined4 *)(puVar14 + 0x54) = *(undefined4 *)(puVar14 + 0x70);
          local_68 = puVar14 + 0x54;
          local_58 = puVar14 + 0x50;
          *(undefined1 **)(puVar14 + 0x28) = local_e8;
          *(undefined4 *)(puVar14 + 0x20) = 10;
          local_70 = 4;
          local_60 = 4;
          *(int *)(puVar14 + 0x50) = iVar8;
          local_50 = 4;
          *(undefined8 *)(puVar14 + -8) = 0x140011498;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x14002f040,&DAT_140026c95,0,0,*(undefined4 *)(puVar14 + 0x20),
                     *(undefined8 **)(puVar14 + 0x28));
        }
      }
      if (iVar8 != 0) goto LAB_1400114f1;
      *(undefined8 *)(puVar14 + -8) = 0x1400114aa;
      uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar10[-4] == param_1) {
            *(int *)(plVar10 + -1) = (int)plVar10[-1] + 1;
            break;
          }
          plVar10 = (longlong *)*plVar10;
        } while ((longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar14 + -8) = 0x1400114ec;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
LAB_1400114f1:
  *(undefined8 *)(puVar14 + -8) = 0x1400114fd;
  return;
}



===== UninitializeTelemetryAssertsKM @ 140011528 =====

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
    *(undefined8 *)(puVar6 + -8) = 0x1400115bb;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x1400115d8;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_14002f098;
    DAT_14002f098 = 0;
    DAT_14002f078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140011602;
    EtwUnregister(uVar3);
    uVar3 = DAT_14002f028;
    DAT_14002f028 = 0;
    _DAT_14002f008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140011624;
    EtwUnregister(uVar3);
    uVar3 = DAT_14002f060;
    DAT_14002f060 = 0;
    DAT_14002f040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140011646;
    EtwUnregister(uVar3);
  }
  return;
}



===== FseAcquireReadLock @ 140011660 =====

void FseAcquireReadLock(undefined8 *param_1,undefined8 param_2)

{
  if (param_1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  NdisAcquireRWLockRead(*param_1,param_2,0);
  return;
}



===== FseAllocFromLookasideList @ 1400116a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FseAllocFromLookasideList(longlong param_1,longlong *param_2)

{
  bool bVar1;
  bool bVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [4];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar4 = 0;
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (param_2 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar3 = ExAllocateFromNPagedLookasideList(param_1);
  *param_2 = lVar3;
  if (lVar3 == 0) {
    uVar4 = 0xc0000017;
    bVar1 = true;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_3c = 0;
        local_2c = 0;
        local_48 = "__FUNCTION__ allocation failure.";
        local_38 = local_78;
        local_40 = 0x21;
        local_78[0] = 0xc0000017;
        local_30 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026e48,0,0,4,local_68);
      }
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar1 = false;
        }
        if (bVar1) {
          local_3c = 0;
          local_2c = 0;
          local_48 = "FseAllocFromLookasideList returned error";
          local_38 = local_78;
          local_40 = 0x29;
          local_78[0] = 0xc0000017;
          local_30 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026da6,0,0,4,local_68);
        }
      }
    }
  }
  return uVar4;
}



===== FseAllocMemory @ 14001182c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FseAllocMemory(size_t param_1,undefined8 param_2,undefined8 *param_3)

{
  bool bVar1;
  bool bVar2;
  void *_Dst;
  undefined8 uVar3;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar3 = 0;
  if (param_3 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  _Dst = (void *)ExAllocatePool2(0x40);
  *param_3 = _Dst;
  if (_Dst == (void *)0x0) {
    uVar3 = 0xc0000017;
    bVar1 = true;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_4c = 0;
        local_3c = 0;
        local_58 = "__FUNCTION__ allocation failure.";
        local_48 = local_88;
        local_50 = 0x21;
        local_88[0] = 0xc0000017;
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026cfe,0,0,4,local_78);
      }
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar1 = false;
        }
        if (bVar1) {
          local_4c = 0;
          local_3c = 0;
          local_58 = "FseAllocMemory returned error";
          local_48 = local_88;
          local_50 = 0x1e;
          local_88[0] = 0xc0000017;
          local_40 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026e12,0,0,4,local_78);
        }
      }
    }
  }
  else {
    memset(_Dst,0,param_1);
  }
  return uVar3;
}



===== FseCreateLookasideList @ 1400119c0 =====

void FseCreateLookasideList(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  ExInitializeNPagedLookasideList(param_1,0,0,0x200,param_2,param_3,0);
  return;
}



===== FseFreeMemory @ 140011a30 =====

void FseFreeMemory(longlong *param_1)

{
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (*param_1 == -0x4524520545245206) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (*param_1 != 0) {
    ExFreePool();
  }
  *param_1 = -0x4524520545245206;
  return;
}



===== FseFreeToLookasideList @ 140011a84 =====

void FseFreeToLookasideList(longlong param_1,longlong *param_2)

{
  if (param_2 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (*param_2 == -0x4524520545245206) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  ExFreeToNPagedLookasideList(param_1,*param_2);
  *param_2 = -0x4524520545245206;
  return;
}



===== FseCoreConfigurePhysicalToVirtualNicPairing @ 140011af0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FseCoreConfigurePhysicalToVirtualNicPairing
              (undefined8 *param_1,longlong *param_2,longlong *param_3,longlong param_4,
              undefined4 *param_5)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  longlong lVar8;
  longlong *plVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  longlong *plVar14;
  byte *pbVar15;
  undefined1 *puVar16;
  longlong local_res20;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  undefined8 local_b8;
  undefined2 local_b0;
  undefined1 local_ae;
  longlong *local_a8;
  code *local_a0;
  undefined8 local_98 [4];
  char *local_78;
  ulonglong local_70;
  undefined8 *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_e8;
  pcVar2 = (code *)param_1[9];
  local_b0 = 0;
  local_ae = 0;
  local_a0 = (code *)param_1[3];
  local_b8 = 0;
  local_a8 = (longlong *)0x0;
  local_res20 = param_4;
  uVar12 = FseAllocMemory(0x58,0x65707346,&local_a8);
  puVar16 = auStackY_e8;
  iVar11 = (int)uVar12;
  bVar7 = true;
  if (iVar11 != 0) goto LAB_140011db3;
  puVar1 = param_1 + 0xb;
  if (puVar1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  NdisAcquireRWLockWrite(*puVar1,&local_b0);
  iVar10 = FseCoreFindNicPairEntryUnderLock
                     ((longlong)puVar1,param_2,(longlong *)0x0,(longlong *)0x0,&local_b8);
  if (iVar10 == 0) {
LAB_140011bb9:
    if (local_b8 == 0) {
      iVar11 = FseCoreFindNicPairEntryUnderLock
                         ((longlong)puVar1,(longlong *)0x0,param_3,&local_res20,&local_b8);
      if (iVar11 != 0) {
        iVar10 = 0;
        if (iVar11 != -0x3ffffddb) {
          iVar10 = iVar11;
        }
        iVar11 = iVar10;
        puVar16 = auStackY_e8;
        if (iVar11 != 0) goto LAB_140011d93;
      }
      if (local_b8 == 0) {
        if (pcVar2 != (code *)0x0) {
          (*pcVar2)(param_1[7],param_3[1]);
        }
        plVar9 = local_a8;
        uVar3 = *(undefined4 *)((longlong)param_3 + 4);
        lVar8 = param_3[1];
        uVar4 = *(undefined4 *)((longlong)param_3 + 0xc);
        *(int *)(local_a8 + 2) = (int)*param_3;
        *(undefined4 *)((longlong)local_a8 + 0x14) = uVar3;
        *(int *)(local_a8 + 3) = (int)lVar8;
        *(undefined4 *)((longlong)local_a8 + 0x1c) = uVar4;
        local_a8[4] = param_3[2];
        if (local_a0 != (code *)0x0) {
          (*local_a0)(*param_1,param_2[1]);
        }
        puVar16 = auStackY_e8;
        uVar3 = *(undefined4 *)((longlong)param_2 + 4);
        lVar8 = param_2[1];
        uVar4 = *(undefined4 *)((longlong)param_2 + 0xc);
        *(int *)(plVar9 + 5) = (int)*param_2;
        *(undefined4 *)((longlong)plVar9 + 0x2c) = uVar3;
        *(int *)(plVar9 + 6) = (int)lVar8;
        *(undefined4 *)((longlong)plVar9 + 0x34) = uVar4;
        plVar9[7] = param_2[2];
        plVar9[8] = local_res20;
        if (param_5 != (undefined4 *)0x0) {
          uVar3 = param_5[1];
          uVar4 = param_5[2];
          uVar5 = param_5[3];
          *(undefined4 *)(plVar9 + 9) = *param_5;
          *(undefined4 *)((longlong)plVar9 + 0x4c) = uVar3;
          *(undefined4 *)(plVar9 + 10) = uVar4;
          *(undefined4 *)((longlong)plVar9 + 0x54) = uVar5;
        }
        puVar13 = param_1 + 0xd;
        plVar14 = (longlong *)param_1[0xe];
        if ((undefined8 *)*plVar14 != puVar13) {
          plVar14 = (longlong *)0x3;
          pcVar2 = (code *)swi(0x29);
          puVar13 = (undefined8 *)(*pcVar2)();
          puVar16 = auStackY_e0;
        }
        *plVar9 = (longlong)puVar13;
        plVar9[1] = (longlong)plVar14;
        *plVar14 = (longlong)plVar9;
        puVar13[1] = plVar9;
        *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
        local_a8 = (longlong *)0x0;
      }
      else {
        iVar11 = 0x40000000;
        puVar16 = auStackY_e8;
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar6 = false;
          }
          else {
            bVar6 = true;
          }
          puVar16 = auStackY_e8;
          if (bVar6) {
            local_78 = "Another Nic Pair Entry exists with Physical NIC Id and Partition Id";
            pbVar15 = &DAT_140026f58;
            local_70._0_4_ = 0x44;
            goto LAB_140011c1b;
          }
        }
      }
    }
    else {
      iVar11 = 0x40000000;
      puVar16 = auStackY_e8;
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar6 = false;
        }
        else {
          bVar6 = true;
        }
        puVar16 = auStackY_e8;
        if (bVar6) {
          local_78 = "Another Nic Pair Entry exists with virtual NIC Id";
          pbVar15 = &DAT_140026f8a;
          local_70._0_4_ = 0x32;
LAB_140011c1b:
          local_b8 = CONCAT44(local_b8._4_4_,0x40000000);
          iVar11 = 0x40000000;
          local_70 = (ulonglong)(uint)local_70;
          local_68 = &local_b8;
          local_60 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar15,0,0,4,local_98);
          puVar16 = auStackY_e8;
        }
      }
    }
  }
  else {
    iVar11 = 0;
    if (iVar10 != -0x3ffffddb) {
      iVar11 = iVar10;
    }
    puVar16 = auStackY_e8;
    if (iVar11 == 0) goto LAB_140011bb9;
  }
LAB_140011d93:
  if (puVar1 == (undefined8 *)0x0) {
    *(undefined8 *)(puVar16 + -8) = 0x140011d9d;
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  uVar12 = *puVar1;
  *(undefined8 *)(puVar16 + -8) = 0x140011dab;
  NdisReleaseRWLock(uVar12,&local_b0);
LAB_140011db3:
  if (local_a8 != (longlong *)0x0) {
    *(undefined8 *)(puVar16 + -8) = 0x140011dc2;
    FseFreeMemory((longlong *)&local_a8);
  }
  if ((iVar11 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar7 = false;
    }
    if (bVar7) {
      local_70 = 0x3b;
      local_78 = "FseCoreConfigurePhysicalToVirtualNicPairing returned error";
      local_68 = &local_b8;
      local_b8 = CONCAT44(local_b8._4_4_,iVar11);
      local_60 = 4;
      *(undefined8 **)(puVar16 + 0x28) = local_98;
      *(undefined4 *)(puVar16 + 0x20) = 4;
      *(undefined8 *)(puVar16 + -8) = 0x140011e43;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x14002a000,&DAT_140027052,0,0,*(undefined4 *)(puVar16 + 0x20),
                 *(undefined8 **)(puVar16 + 0x28));
    }
  }
  *(undefined8 *)(puVar16 + -8) = 0x140011e51;
  return iVar11;
}



===== FseCoreFindNicPairEntryByVirtualNicId @ 140011e6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseCoreFindNicPairEntryByVirtualNicId(undefined8 *param_1,longlong param_2,longlong *param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  longlong local_res10 [3];
  undefined1 auStackY_c8 [32];
  undefined2 local_98;
  undefined1 local_96;
  int local_94 [3];
  undefined8 local_88 [4];
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_98 = 0;
  local_96 = 0;
  local_res10[0] = param_2;
  if (param_1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  pcVar2 = (code *)param_1[9];
  puVar1 = param_1 + 0xb;
  pcVar3 = (code *)param_1[3];
  FseAcquireReadLock(puVar1,&local_98);
  iVar5 = FseCoreFindNicPairEntryUnderLock
                    ((longlong)puVar1,local_res10,(longlong *)0x0,(longlong *)0x0,param_3);
  if (iVar5 == 0) {
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(param_1[7],*(undefined8 *)(*param_3 + 0x18));
    }
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(*param_1,*(undefined8 *)(*param_3 + 0x30));
    }
  }
  if (puVar1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  NdisReleaseRWLock(*puVar1,&local_98);
  if ((iVar5 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (bVar4) {
      local_5c = 0;
      local_4c = 0;
      local_68 = "FseCoreFindNicPairEntryByVirtualNicId returned error";
      local_58 = local_94;
      local_60 = 0x35;
      local_50 = 4;
      local_94[0] = iVar5;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027088,0,0,4,local_88);
    }
  }
  return iVar5;
}



===== FseCoreFindNicPairEntryUnderLock @ 140011fe4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FseCoreFindNicPairEntryUnderLock
          (longlong param_1,longlong *param_2,longlong *param_3,longlong *param_4,
          undefined8 *param_5)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  longlong *plVar4;
  byte *pbVar5;
  undefined4 uVar6;
  longlong *plVar7;
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  plVar7 = (longlong *)0x0;
  bVar2 = true;
  *param_5 = 0;
  if (param_2 == (longlong *)0x0) {
    if (param_3 == (longlong *)0x0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
      uVar6 = 0xc000000d;
      if (DAT_14002a000 < 3) goto LAB_1400121cf;
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (!bVar3) goto LAB_1400121cf;
      local_68[0] = 0xc000000d;
      local_38 = 
      "FseCoreFindNicPairEntryUnderLock: Neither Virtual NIC ID or Physical NID ID specified";
      pbVar5 = &DAT_140027020;
      local_30 = 0x56;
    }
    else {
LAB_140012096:
      if (param_4 != (longlong *)0x0) goto LAB_1400120fb;
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
      uVar6 = 0xc000000d;
      if (DAT_14002a000 < 3) goto LAB_1400121cf;
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (!bVar3) goto LAB_1400121cf;
      local_68[0] = 0xc000000d;
      local_38 = 
      "FseCoreFindNicPairEntryUnderLock: Physical NIC ID specified but Partition ID is not specified"
      ;
      pbVar5 = &DAT_140026fee;
      local_30 = 0x5e;
    }
  }
  else {
    if (param_3 != (longlong *)0x0) goto LAB_140012096;
LAB_1400120fb:
    plVar1 = (longlong *)(param_1 + 0x10);
    plVar4 = (longlong *)*plVar1;
    if (plVar4 != plVar1) {
      do {
        if (((param_3 == (longlong *)0x0) || ((*param_3 == plVar4[2] && (*param_4 == plVar4[8]))))
           && ((param_2 == (longlong *)0x0 || (*param_2 == plVar4[5])))) {
          plVar7 = plVar4;
        }
        plVar4 = (longlong *)*plVar4;
      } while (plVar4 != plVar1);
      if (plVar7 != (longlong *)0x0) {
        *param_5 = plVar7;
        return 0;
      }
    }
    uVar6 = 0xc0000225;
    if (DAT_14002a000 < 3) goto LAB_1400121cf;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (!bVar3) goto LAB_1400121cf;
    local_38 = "No Matching NIC Pair Entry Found";
    local_30 = 0x21;
    local_68[0] = 0xc0000225;
    pbVar5 = &DAT_140026eba;
  }
  local_2c = 0;
  local_1c = 0;
  local_28 = local_68;
  local_20 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar5,0,0,4,local_58);
LAB_1400121cf:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseCoreFindNicPairEntryUnderLock returned error";
      local_28 = local_68;
      local_30 = 0x30;
      local_20 = 4;
      local_68[0] = uVar6;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026eec,0,0,4,local_58);
    }
  }
  return uVar6;
}



===== FseCoreInitializeNicPairList @ 140012278 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FseCoreInitializeNicPairList(longlong *param_1)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  lVar4 = NdisAllocateRWLock(g_FseNdisGenericObject);
  if (lVar4 == 0) {
    uVar6 = 4;
    uVar5 = 0xc0000017;
    bVar2 = true;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_2c = 0;
        local_1c = 0;
        local_38 = "\"NdisAllocateRWLock\" allocation failure.";
        local_28 = local_68;
        local_30 = 0x29;
        local_68[0] = 0xc0000017;
        local_20 = uVar6;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026d6d,0,0,4,local_58);
      }
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        if (bVar3) {
          local_2c = 0;
          local_1c = 0;
          local_38 = "FseInitRWLock returned error";
          local_28 = local_68;
          local_30 = 0x1d;
          local_68[0] = 0xc0000017;
          local_20 = uVar6;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026ddc,0,0,4,local_58);
        }
        if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar2 = false;
          }
          if (bVar2) {
            local_2c = 0;
            local_1c = 0;
            local_38 = "FseCoreInitializeNicPairList returned error";
            local_28 = local_68;
            local_30 = 0x2c;
            local_68[0] = 0xc0000017;
            local_20 = uVar6;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027126,0,0,4,local_58);
          }
        }
      }
    }
  }
  else {
    *param_1 = lVar4;
    plVar1 = param_1 + 2;
    param_1[3] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    uVar5 = 0;
  }
  return uVar5;
}



===== FseCoreListAllNicPairEntries @ 1400124a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseCoreListAllNicPairEntries
              (longlong param_1,undefined2 *param_2,ulonglong *param_3,void *param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  longlong *plVar6;
  int iVar7;
  ulonglong uVar8;
  undefined1 auStackY_d8 [32];
  int local_a8;
  undefined2 local_a4;
  undefined1 local_a2;
  undefined8 local_98 [4];
  char *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_a4 = 0;
  local_a2 = 0;
  iVar7 = 0;
  bVar5 = true;
  if ((param_2 == (undefined2 *)0x0) || (param_3 == (ulonglong *)0x0)) {
    iVar7 = -0x3ffffff3;
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (bVar4 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018))
      {
        bVar4 = false;
      }
      if (bVar4) {
        local_70 = 0x48;
        local_78 = "FseCoreListAllNicPairEntries: One or more input parameters are invalid.";
        local_68 = &local_a8;
        local_a8 = -0x3ffffff3;
        local_60 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026fbc,0,0,4,local_98);
      }
    }
  }
  else {
    FseAcquireReadLock((undefined8 *)(param_1 + 0x58),&local_a4);
    uVar8 = (ulonglong)*(ushort *)(param_1 + 0x60) * 0x48;
    if ((param_4 == (void *)0x0) || (*param_3 < uVar8)) {
      *param_3 = uVar8;
      iVar7 = -0x7ffffffb;
      *param_2 = *(undefined2 *)(param_1 + 0x60);
      if (2 < DAT_14002a000) {
        if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar4 = false;
        }
        else {
          bVar4 = true;
        }
        if (bVar4) {
          local_78 = "FseCoreListAllNicPairEntries: Output buffer provided by caller is too small";
          local_68 = &local_a8;
          local_70 = 0x4c;
          local_a8 = -0x7ffffffb;
          local_60 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400270f4,0,0,4,local_98);
        }
      }
    }
    else {
      memset(param_4,0,*param_3);
      *param_3 = uVar8;
      plVar1 = (longlong *)(param_1 + 0x68);
      *param_2 = *(undefined2 *)(param_1 + 0x60);
      plVar6 = (longlong *)*plVar1;
      if (plVar6 != plVar1) {
        uVar8 = 0;
        do {
          lVar3 = plVar6[3];
          plVar2 = (longlong *)((longlong)param_4 + uVar8 * 0x48);
          *plVar2 = plVar6[2];
          plVar2[1] = lVar3;
          lVar3 = plVar6[5];
          plVar2 = (longlong *)((longlong)param_4 + uVar8 * 0x48 + 0x10);
          *plVar2 = plVar6[4];
          plVar2[1] = lVar3;
          lVar3 = plVar6[7];
          plVar2 = (longlong *)((longlong)param_4 + uVar8 * 0x48 + 0x20);
          *plVar2 = plVar6[6];
          plVar2[1] = lVar3;
          lVar3 = plVar6[9];
          plVar2 = (longlong *)((longlong)param_4 + uVar8 * 0x48 + 0x30);
          *plVar2 = plVar6[8];
          plVar2[1] = lVar3;
          *(longlong *)((longlong)param_4 + uVar8 * 0x48 + 0x40) = plVar6[10];
          plVar6 = (longlong *)*plVar6;
          uVar8 = (ulonglong)(ushort)((short)uVar8 + 1);
        } while (plVar6 != plVar1);
      }
    }
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x58));
    if (iVar7 == 0) {
      return 0;
    }
  }
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar5 = false;
    }
    if (bVar5) {
      local_70 = 0x2c;
      local_78 = "FseCoreListAllNicPairEntries returned error";
      local_68 = &local_a8;
      local_60 = 4;
      local_a8 = iVar7;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140026f22,0,0,4,local_98);
    }
  }
  return iVar7;
}



===== FseCoreRemovePhysicalToVirtualNicPairing @ 140012778 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong FseCoreRemovePhysicalToVirtualNicPairing
                    (undefined8 *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  code *pcVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined2 local_res8;
  undefined1 local_resa;
  longlong local_res10;
  longlong local_res18;
  longlong local_res20;
  longlong *local_48 [2];
  
  pcVar2 = (code *)param_1[10];
  puVar1 = param_1 + 0xb;
  pcVar3 = (code *)param_1[4];
  local_48[0] = (longlong *)0x0;
  local_res8 = 0;
  local_resa = 0;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  if (puVar1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  NdisAcquireRWLockWrite(*puVar1,&local_res8,0);
  uVar7 = FseCoreFindNicPairEntryUnderLock
                    ((longlong)puVar1,&local_res10,&local_res18,&local_res20,local_48);
  plVar6 = local_48[0];
  if (uVar7 == 0) {
    if (local_48[0] == (longlong *)0x0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    lVar4 = *plVar6;
    if ((*(longlong **)(lVar4 + 8) != plVar6) ||
       (plVar5 = (longlong *)plVar6[1], (longlong *)*plVar5 != plVar6)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      uVar8 = (*pcVar2)();
      return uVar8;
    }
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + -1;
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(param_1[7],plVar6[3]);
    }
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(*param_1,plVar6[6]);
    }
  }
  if (puVar1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  NdisReleaseRWLock(*puVar1,&local_res8);
  if (plVar6 != (longlong *)0x0) {
    FseFreeMemory((longlong *)local_48);
  }
  return (ulonglong)uVar7;
}



===== FseCoreInitialize @ 1400128a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseCoreInitialize(longlong *param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStackY_98 [32];
  longlong local_68 [2];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_68[0] = 0;
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *param_1 = 0;
  uVar3 = FseAllocMemory(0x80,0x6f677346,local_68);
  lVar4 = local_68[0];
  iVar2 = (int)uVar3;
  if (iVar2 == 0) {
    uVar3 = FseCoreInitializeNicPairList((longlong *)(local_68[0] + 0x58));
    iVar2 = (int)uVar3;
    if (iVar2 == 0) {
      iVar2 = FseNpiNduClientInitialize((longlong *)(lVar4 + 0x78));
      if (iVar2 == 0) {
        *param_1 = lVar4;
        lVar4 = 0;
      }
    }
  }
  if (lVar4 != 0) {
    FseCoreUninitialize(lVar4);
  }
  if ((iVar2 != 0) && (2 < DAT_14002a000)) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_2c = 0;
      local_1c = 0;
      local_38 = "FseCoreInitialize returned error";
      local_28 = local_68;
      local_30 = 0x21;
      local_68[0] = CONCAT44(local_68[0]._4_4_,iVar2);
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027192,0,0,4,local_58);
    }
  }
  return iVar2;
}



===== FseCoreUninitialize @ 1400129e8 =====

void FseCoreUninitialize(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  longlong local_res8;
  longlong local_res10;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (param_1 != 0) {
    puVar1 = (undefined8 *)(param_1 + 0x58);
    local_res10 = param_1;
    if (puVar1 == (undefined8 *)0x0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    NdisFreeRWLock(*puVar1);
    puVar6 = auStack_28;
    *puVar1 = 0;
    plVar5 = (longlong *)(param_1 + 0x68);
    while (plVar2 = (longlong *)*plVar5, plVar2 != plVar5) {
      if (((longlong *)plVar2[1] != plVar5) ||
         (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStack_20;
        break;
      }
      *plVar5 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar5;
      local_res8 = (longlong)plVar2;
      FseFreeMemory(&local_res8);
    }
    *(longlong **)(param_1 + 0x70) = plVar5;
    *plVar5 = (longlong)plVar5;
    lVar3 = *(longlong *)(param_1 + 0x78);
    *(undefined8 *)(puVar6 + -8) = 0x140012a6e;
    FseNpiNduClientUninitialize(lVar3);
    *(undefined8 *)(puVar6 + -8) = 0x140012a78;
    FseFreeMemory((longlong *)(puVar6 + 0x38));
  }
  return;
}



===== FseAllocateAndPopulateNduAttributionData @ 140012a8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 *
FseAllocateAndPopulateNduAttributionData
          (undefined4 param_1,undefined8 *param_2,undefined8 *param_3,undefined2 *param_4)

{
  bool bVar1;
  undefined8 uVar2;
  byte *pbVar3;
  undefined1 auStackY_98 [32];
  int local_68 [2];
  undefined4 *local_60;
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_60 = (undefined4 *)0x0;
  uVar2 = FseAllocFromLookasideList(0x14002a500,(longlong *)&local_60);
  if ((int)uVar2 == 0) {
    if (param_2 != (undefined8 *)0x0) {
      *local_60 = param_1;
      if (param_3 != (undefined8 *)0x0) {
        *(undefined8 *)(local_60 + 6) = *param_3;
      }
      if (param_4 != (undefined2 *)0x0) {
        *(undefined2 *)(local_60 + 8) = *param_4;
      }
      uVar2 = param_2[1];
      *(undefined8 *)(local_60 + 1) = *param_2;
      *(undefined8 *)(local_60 + 3) = uVar2;
      return local_60;
    }
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
    if (DAT_14002a000 < 3) goto LAB_140012bce;
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) goto LAB_140012bce;
    local_38 = "FseAllocateAndPopulateNduAttributionData: PartitionGuid is NULL!.";
    local_30 = 0x42;
    local_68[0] = -0x3ffffff3;
    pbVar3 = &DAT_1400275c6;
  }
  else {
    if (DAT_14002a000 < 3) goto LAB_140012bce;
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) goto LAB_140012bce;
    local_38 = 
    "FseAllocateAndPopulateNduAttributionData: failed to allocate memory on NduAttributionData";
    local_30 = 0x5a;
    pbVar3 = &DAT_140027660;
    local_68[0] = (int)uVar2;
  }
  local_2c = 0;
  local_1c = 0;
  local_28 = local_68;
  local_20 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar3,0,0,4,local_58);
LAB_140012bce:
  if (local_60 != (undefined4 *)0x0) {
    FseFreeToLookasideList(0x14002a500,(longlong *)&local_60);
  }
  return (undefined4 *)0x0;
}



===== FseAllocateAndPopulateSendContext @ 140012c44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 *
FseAllocateAndPopulateSendContext
          (undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined2 *param_4)

{
  bool bVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  undefined1 auStackY_98 [32];
  int local_68 [2];
  undefined8 *local_60;
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_60 = (undefined8 *)0x0;
  uVar2 = FseAllocFromLookasideList(0x14002a480,(longlong *)&local_60);
  if ((int)uVar2 == 0) {
    bVar1 = true;
    puVar3 = FseAllocateAndPopulateNduAttributionData(1,param_2,param_3,param_4);
    if (puVar3 != (undefined4 *)0x0) {
      *local_60 = puVar3;
      return local_60;
    }
    if (DAT_14002a000 < 3) goto LAB_140012d8d;
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (!bVar1) goto LAB_140012d8d;
    local_30 = 0x66;
    local_38 = 
    "FseAllocateAndPopulateSendContext: NduAttribData failed to be created or input parameter is invalid!."
    ;
    pbVar4 = &DAT_140027705;
    local_68[0] = -0x3fffff1b;
  }
  else {
    if (DAT_14002a000 < 3) goto LAB_140012d8d;
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) goto LAB_140012d8d;
    local_30 = 0x4c;
    local_38 = "FseAllocateAndPopulateSendContext: failed to allocate memory on SendContext";
    pbVar4 = &DAT_140027273;
    local_68[0] = (int)uVar2;
  }
  local_2c = 0;
  local_28 = local_68;
  local_1c = 0;
  local_20 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar4,0,0,4,local_58);
LAB_140012d8d:
  if (local_60 != (undefined8 *)0x0) {
    FseFreeToLookasideList(0x14002a480,(longlong *)&local_60);
  }
  return (undefined8 *)0x0;
}



===== FseCoreIndicateReceiveNetBufferLists @ 140012de0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseCoreIndicateReceiveNetBufferLists
               (undefined8 *param_1,undefined *param_2,int param_3,longlong param_4,ushort param_5,
               longlong *param_6)

{
  int *piVar1;
  code *pcVar2;
  code *pcVar3;
  longlong lVar4;
  bool bVar5;
  undefined8 *puVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined8 *puVar12;
  undefined2 *puVar13;
  undefined1 auStackY_2e8 [32];
  ushort local_298;
  undefined2 local_294;
  undefined1 local_292;
  int local_290 [2];
  undefined8 *local_288;
  code *local_280;
  int local_278;
  int local_274;
  int local_270 [2];
  longlong local_268;
  undefined *local_260;
  longlong local_258;
  longlong local_250;
  longlong local_248;
  longlong local_240;
  undefined *local_238;
  code *local_230;
  undefined *local_228;
  undefined8 local_220;
  longlong local_218;
  longlong local_210;
  undefined8 local_208 [4];
  code **local_1e8;
  undefined8 local_1e0;
  char *local_1d8;
  undefined8 local_1d0;
  int *local_1c8;
  undefined8 local_1c0;
  char *local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8 [4];
  undefined **local_188;
  undefined8 local_180;
  longlong *local_178;
  undefined8 local_170;
  longlong *local_168;
  undefined8 local_160;
  char *local_158;
  undefined8 local_150;
  undefined8 local_148 [4];
  undefined **local_128;
  undefined8 local_120;
  char *local_118;
  undefined8 local_110;
  int *local_108;
  undefined8 local_100;
  char *local_f8;
  undefined8 local_f0;
  undefined8 local_e8 [4];
  undefined **local_c8;
  undefined8 local_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  longlong *local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined8 local_90;
  undefined8 local_88 [4];
  char *local_68;
  undefined8 local_60;
  int *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2e8;
  local_288 = (undefined8 *)0x0;
  local_290[0] = param_3;
  local_210 = param_4;
  if (param_1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  uVar9 = FseAllocFromLookasideList(0x14002a580,(longlong *)&local_288);
  puVar6 = local_288;
  if ((int)uVar9 == 0) {
    if (local_288 == (undefined8 *)0x0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    *puVar6 = param_2;
    puVar6[1] = 1;
    puVar6[2] = 0;
    local_230 = (code *)param_1[10];
    local_280 = (code *)param_1[1];
    local_298 = 0;
    if (param_5 != 0) {
      local_240 = param_4;
      do {
        local_268 = 0;
        if (5 < DAT_14002a000) {
          if (((uRam000000014002a011 & 2) == 0) ||
             (bVar5 = true, ((uint)DAT_14002a018 & 0x200) != DAT_14002a018)) {
            bVar5 = false;
          }
          if (bVar5) {
            local_188 = &local_260;
            local_158 = "Inbound NBL Chain indicated from Lower Shim (Demux) to FSE Core";
            local_178 = &local_258;
            local_180 = 8;
            local_170 = 8;
            local_250 = *param_6;
            local_168 = &local_250;
            local_160 = 8;
            local_150 = 0x40;
            local_260 = param_2;
            local_258 = param_4;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027350,0,0,6,local_1a8);
          }
        }
        local_248 = *param_6;
        pcVar2 = (code *)param_1[9];
        pcVar3 = (code *)param_1[3];
        local_294 = 0;
        local_292 = 0;
        FseAcquireReadLock(param_1 + 0xb,&local_294);
        local_278 = FseCoreFindNicPairEntryUnderLock
                              ((longlong)(param_1 + 0xb),(longlong *)0x0,&local_240,&local_248,
                               &local_268);
        lVar4 = local_268;
        if (local_278 == 0) {
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)(param_1[7],*(undefined8 *)(local_268 + 0x18));
          }
          if (pcVar3 != (code *)0x0) {
            (*pcVar3)(*param_1,*(undefined8 *)(lVar4 + 0x30));
          }
        }
        if (param_1 + 0xb == (undefined8 *)0x0) {
          MicrosoftTelemetryAssertTriggeredNoArgsKM();
        }
        NdisReleaseRWLock(param_1[0xb],&local_294);
        iVar7 = local_278;
        if (local_278 == 0) {
          if (lVar4 == 0) {
            MicrosoftTelemetryAssertTriggeredNoArgsKM();
          }
          if (local_230 != (code *)0x0) {
            (*local_230)(param_1[7],*(undefined8 *)(lVar4 + 0x18));
          }
          LOCK();
          *(int *)(puVar6 + 1) = *(int *)(puVar6 + 1) + 1;
          UNLOCK();
          if (1 < param_5) {
            MicrosoftTelemetryAssertTriggeredNoArgsKM();
          }
          lVar8 = local_268;
          lVar4 = *(longlong *)(local_268 + 0x20);
          puVar13 = (undefined2 *)(lVar4 + 8);
          puVar12 = (undefined8 *)(lVar4 + 0x20);
          if (lVar4 == 0) {
            puVar13 = (undefined2 *)0x0;
            puVar12 = (undefined8 *)0x0;
          }
          puVar10 = FseAllocateAndPopulateNduAttributionData
                              (0,(undefined8 *)(local_268 + 0x48),puVar12,puVar13);
          puVar6[2] = puVar10;
          if (local_280 == (code *)0x0) {
            MicrosoftTelemetryAssertTriggeredNoArgsKM();
          }
          (*local_280)(*param_1,param_2);
          if (puVar6[2] != 0) {
            MicrosoftTelemetryAssertTriggeredNoArgsKM();
          }
          if (5 < DAT_14002a000) {
            if (((uRam000000014002a011 & 2) == 0) ||
               (bVar5 = true, (DAT_14002a018 & 0x200) != DAT_14002a018)) {
              bVar5 = false;
            }
            if (bVar5) {
              local_c8 = &local_228;
              pbVar11 = &DAT_14002741d;
              local_c0 = 8;
              local_220 = *(undefined8 *)(lVar8 + 0x28);
              local_b8 = &local_220;
              local_b0 = 8;
              local_a0 = 8;
              local_90 = 0x37;
              local_218 = *param_6;
              local_a8 = &local_218;
              local_98 = "Successfully indicated Inbound NBL Chain to Upper Shim";
              puVar12 = local_e8;
              local_228 = param_2;
LAB_1400133ad:
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar11,0,0,6,puVar12);
            }
          }
        }
        else if (2 < DAT_14002a000) {
          if (((DAT_14002a010 & 4) == 0) ||
             (bVar5 = true, ((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
            bVar5 = false;
          }
          if (bVar5) {
            local_60 = 0x44;
            local_68 = "FseCoreFindNicPairEntryByPhysicalNicIdAndPartitionId returned error";
            local_58 = &local_274;
            local_274 = local_278;
            local_50 = 4;
            _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400270be,0,0,4,local_88);
          }
          if (2 < DAT_14002a000) {
            if (((uRam000000014002a011 & 4) == 0) ||
               (bVar5 = true, ((uint)DAT_14002a018 & 0x400) != DAT_14002a018)) {
              bVar5 = false;
            }
            if (bVar5) {
              local_128 = &local_238;
              pbVar11 = &DAT_1400277de;
              local_120 = 8;
              local_118 = "Indication of Inbound NBL Chain to upper shim";
              local_108 = local_270;
              local_f8 = "Matching destination Virtual NIC not found";
              puVar12 = local_148;
              local_110 = 0x2e;
              local_270[0] = iVar7;
              local_100 = 4;
              local_f0 = 0x2b;
              local_238 = param_2;
              goto LAB_1400133ad;
            }
          }
        }
        local_298 = local_298 + 1;
        param_6 = param_6 + 1;
        param_4 = local_210;
      } while (local_298 < param_5);
    }
    LOCK();
    piVar1 = (int *)(puVar6 + 1);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) {
      param_2 = (undefined *)0x0;
    }
  }
  else if (2 < DAT_14002a000) {
    if (((uRam000000014002a011 & 4) == 0) || ((DAT_14002a018 & 0x400) != DAT_14002a018)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (bVar5) {
      local_1e8 = &local_280;
      local_1c8 = local_290;
      local_1d8 = "Inbound NBL Chain indicated from Lower Shim (Demux) to FSE Core";
      local_1b8 = "Failed to allocate NBL Chain Indication Context";
      local_1e0 = 8;
      local_1d0 = 0x40;
      local_1c0 = 4;
      local_1b0 = 0x30;
      local_290[0] = (int)uVar9;
      local_280 = (code *)param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400272d7,0,0,6,local_208);
    }
  }
  FseCoreReturnNblsAndCleanupIndicationContext
            ((longlong)param_1,(longlong)param_2,(longlong)local_288);
  return;
}



===== FseCoreInvokeNduNpiProvider @ 140013458 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseCoreInvokeNduNpiProvider(longlong param_1,longlong param_2,int param_3,undefined8 *param_4)

{
  char *pcVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [4];
  char *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (param_2 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  pcVar1 = *(char **)(param_1 + 0x78);
  if (pcVar1 == (char *)0x0) {
    if (DAT_14002a000 < 3) {
      return;
    }
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      return;
    }
    local_58 = "FseCoreInvokeNduNpiProvider: NduNpiClient is not initialized.";
    local_50 = 0x3e;
    pbVar4 = &DAT_1400274e1;
  }
  else {
    if (*pcVar1 == '\0') {
      if (DAT_14002a000 < 3) {
        return;
      }
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        return;
      }
      local_58 = 
      "FseCoreInvokeNduNpiProvider: Warning - NduNpiProvider is not supported on the platform.";
      local_50 = 0x58;
      local_88[0] = 0xc00000bb;
      pbVar4 = &DAT_1400274af;
      goto LAB_140013504;
    }
    if ((*(longlong *)(pcVar1 + 0x10) == 0) &&
       (MicrosoftTelemetryAssertTriggeredNoArgsKM(), *(longlong *)(pcVar1 + 0x10) == 0)) {
      if (DAT_14002a000 < 3) {
        return;
      }
      if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        return;
      }
      local_58 = "FseCoreInvokeNduNpiProvider: NduNpiProvider dispatch function is not initialized."
      ;
      local_50 = 0x52;
      pbVar4 = &DAT_1400273eb;
    }
    else {
      uVar3 = (uint)DAT_14002a018;
      if (param_4 == (undefined8 *)0x0) {
        if (DAT_14002a000 < 3) {
          return;
        }
        if (((DAT_14002a010 & 4) == 0) || ((uVar3 & 4) != DAT_14002a018)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (!bVar2) {
          return;
        }
        local_58 = "FseCoreInvokeNduNpiProvider: SendOrRecvContext is NULL.";
        local_50 = 0x38;
        pbVar4 = &DAT_1400272a5;
      }
      else {
        bVar2 = true;
        if (param_3 == 1) {
          puVar5 = (undefined4 *)*param_4;
        }
        else {
          puVar5 = (undefined4 *)param_4[2];
        }
        if (puVar5 != (undefined4 *)0x0) {
          if (5 < DAT_14002a000) {
            if (((DAT_14002a010 & 2) == 0) || ((uVar3 & 2) != DAT_14002a018)) {
              bVar2 = false;
            }
            if (bVar2) {
              local_50 = 0x43;
              local_58 = "FSE Core (NPI client) invokes NDU (NPI provider) dispatch function";
              _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027884,0,0,3,local_78);
            }
          }
          (**(code **)(*(longlong *)(pcVar1 + 0x10) + 8))(puVar5 + 1,param_2,*puVar5,puVar5 + 6);
          return;
        }
        if (DAT_14002a000 < 3) {
          return;
        }
        if (((DAT_14002a010 & 4) == 0) || ((uVar3 & 4) != DAT_14002a018)) {
          bVar2 = false;
        }
        if (!bVar2) {
          return;
        }
        local_58 = "FseCoreInvokeNduNpiProvider: NduAttribData is NULL.";
        local_50 = 0x34;
        pbVar4 = &DAT_1400278af;
      }
    }
  }
  local_88[0] = 0xc0000008;
LAB_140013504:
  local_48 = local_88;
  local_40 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar4,0,0,4,local_78);
  return;
}



===== FseCoreRegisterInboundDemux @ 140013780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FseCoreRegisterInboundDemux(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar2 = true;
  if ((param_2 == 0) || (param_3 == (longlong *)0x0)) {
    if (DAT_14002a000 < 3) goto LAB_1400138ce;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (!bVar3) goto LAB_1400138ce;
    local_58 = "FseCoreRegisterInboundDemux: One or more input parameters are invalid.";
    local_50 = 0x47;
    pbVar4 = &DAT_140027241;
  }
  else {
    lVar1 = *param_3;
    if (lVar1 != 0) {
      *(longlong *)(param_1 + 0x28) = param_2;
      *(longlong *)(param_1 + 0x30) = lVar1;
      return 0;
    }
    if (DAT_14002a000 < 3) goto LAB_1400138ce;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (!bVar3) goto LAB_1400138ce;
    local_58 = 
    "FseCoreRegisterInboundDemux: One or more function pointers in demux shim dispatch table are NULL pointers"
    ;
    local_50 = 0x6a;
    pbVar4 = &DAT_1400277ac;
  }
  local_4c = 0;
  local_3c = 0;
  local_48 = local_88;
  local_88[0] = 0xc000000d;
  local_40 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar4,0,0,4,local_78);
LAB_1400138ce:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_4c = 0;
      local_3c = 0;
      local_58 = "FseCoreRegisterInboundDemux returned error";
      local_48 = local_88;
      local_50 = 0x2b;
      local_88[0] = 0xc000000d;
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_14002798f,0,0,4,local_78);
    }
  }
  return 0xc000000d;
}



===== FseCoreRegisterLowerShim @ 140013978 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FseCoreRegisterLowerShim(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  byte *pbVar6;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar2 = true;
  if ((param_2 == 0) || (param_3 == (longlong *)0x0)) {
    if (DAT_14002a000 < 3) goto LAB_140013ad0;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (!bVar5) goto LAB_140013ad0;
    local_58 = "FseCoreRegisterLowerShim: One or more input parameters are invalid.";
    local_50 = 0x44;
    pbVar6 = &DAT_140027852;
  }
  else {
    if (*param_3 != 0) {
      lVar3 = *param_3;
      lVar4 = param_3[1];
      *(longlong *)(param_1 + 0x38) = param_2;
      lVar1 = param_3[2];
      *(longlong *)(param_1 + 0x40) = lVar3;
      *(longlong *)(param_1 + 0x48) = lVar4;
      *(longlong *)(param_1 + 0x50) = lVar1;
      return 0;
    }
    if (DAT_14002a000 < 3) goto LAB_140013ad0;
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (!bVar5) goto LAB_140013ad0;
    local_58 = 
    "FseCoreRegisterLowerShim: One or more function pointers in lower shim dispatch table are NULL pointers"
    ;
    local_50 = 0x67;
    pbVar6 = &DAT_1400275f8;
  }
  local_4c = 0;
  local_3c = 0;
  local_48 = local_88;
  local_88[0] = 0xc000000d;
  local_40 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar6,0,0,4,local_78);
LAB_140013ad0:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_4c = 0;
      local_3c = 0;
      local_58 = "FseCoreRegisterLowerShim returned error";
      local_48 = local_88;
      local_50 = 0x28;
      local_88[0] = 0xc000000d;
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027959,0,0,4,local_78);
    }
  }
  return 0xc000000d;
}



===== FseCoreReturnNblsAndCleanupIndicationContext @ 140013b78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseCoreReturnNblsAndCleanupIndicationContext
               (longlong param_1,longlong param_2,longlong param_3)

{
  bool bVar1;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8 [2];
  longlong local_a0;
  longlong local_98 [2];
  undefined8 local_88 [4];
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98[0] = param_3;
  if (param_2 != 0) {
    (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x28));
    if (5 < DAT_14002a000) {
      if (((_DAT_14002a010 & 0x200) == 0) || ((DAT_14002a018 & 0x200) != DAT_14002a018)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_5c = 0;
        local_68 = &local_a0;
        local_4c = 0;
        local_a8[0] = 0;
        local_3c = 0;
        local_2c = 0;
        local_58 = "ReturnNetBufferLists";
        local_48 = local_a8;
        local_38 = "Return Inbound NBL Chain to Lower Shim (Demux)";
        local_60 = 8;
        local_50 = 0x15;
        local_40 = 4;
        local_30 = 0x2f;
        local_a0 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400278e1,0,0,6,local_88);
      }
    }
  }
  if (*(longlong *)(param_3 + 0x10) != 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  FseFreeToLookasideList(0x14002a580,local_98);
  return;
}



===== FseCoreSendNetBufferLists @ 140013cb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseCoreSendNetBufferLists(undefined8 *param_1,longlong *param_2,longlong *param_3)

{
  code *pcVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  longlong lVar5;
  int iVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined2 *puVar10;
  undefined1 auStackY_108 [32];
  longlong *local_c8;
  longlong local_c0;
  longlong *local_b8 [2];
  undefined8 local_a8 [4];
  longlong **local_88;
  undefined8 local_80;
  longlong **local_78;
  undefined8 local_70;
  longlong *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  local_c0 = 0;
  if (param_1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar4 = true;
  if (5 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x200) == 0) || (bVar3 = true, (DAT_14002a018 & 0x200) != DAT_14002a018))
    {
      bVar3 = false;
    }
    if (bVar3) {
      local_88 = local_b8;
      local_78 = &local_c8;
      local_80 = 8;
      local_68 = (longlong *)0x140022fb8;
      local_70 = 8;
      local_60 = 0x31;
      local_c8 = param_3;
      local_b8[0] = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400271c8,0,0,5,local_a8);
    }
  }
  puVar8 = param_1;
  iVar6 = FseCoreFindNicPairEntryByVirtualNicId(param_1,(longlong)param_3,&local_c0);
  lVar5 = local_c0;
  if (iVar6 == 0) {
    if (local_c0 == 0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    if ((code *)param_1[4] != (code *)0x0) {
      puVar8 = (undefined8 *)*param_1;
      (*(code *)param_1[4])(puVar8,*(undefined8 *)(lVar5 + 0x30));
    }
    lVar2 = *(longlong *)(lVar5 + 0x20);
    puVar10 = (undefined2 *)(lVar2 + 8);
    puVar9 = (undefined8 *)(lVar2 + 0x20);
    if (lVar2 == 0) {
      puVar10 = (undefined2 *)0x0;
      puVar9 = (undefined8 *)0x0;
    }
    plVar7 = FseAllocateAndPopulateSendContext(puVar8,(undefined8 *)(lVar5 + 0x48),puVar9,puVar10);
    pcVar1 = (code *)param_1[8];
    local_c8 = plVar7;
    if (pcVar1 == (code *)0x0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    (*pcVar1)(param_1[7],param_2);
    if (plVar7 != (longlong *)0x0) {
      if (*plVar7 != 0) {
        FseFreeToLookasideList(0x14002a500,plVar7);
        *plVar7 = 0;
      }
      FseFreeToLookasideList(0x14002a480,(longlong *)&local_c8);
    }
    if (5 < DAT_14002a000) {
      if (((_DAT_14002a010 & 0x200) == 0) || ((DAT_14002a018 & 0x200) != DAT_14002a018)) {
        bVar4 = false;
      }
      if (bVar4) {
        local_88 = &local_c8;
        local_80 = 8;
        local_b8[0] = *(longlong **)(lVar5 + 0x10);
        local_78 = local_b8;
        local_70 = 8;
        local_68 = (longlong *)0x1400230f8;
        local_60 = 0x33;
        local_c8 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027545,0,0,5,local_a8);
      }
    }
  }
  else {
    if (2 < DAT_14002a000) {
      if (((_DAT_14002a010 & 0x400) == 0) || ((DAT_14002a018 & 0x400) != DAT_14002a018)) {
        bVar4 = false;
      }
      if (bVar4) {
        local_c0 = CONCAT44(local_c0._4_4_,iVar6);
        local_88 = &local_c8;
        local_68 = &local_c0;
        local_78 = (longlong **)0x140023088;
        local_58 = "Matching destination physical NIC not found";
        local_80 = 8;
        local_70 = 0x29;
        local_60 = 4;
        local_50 = 0x2c;
        local_c8 = param_2;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027737,0,0,6,local_a8);
      }
    }
    if (param_2 != (longlong *)0x0) {
      pcVar1 = (code *)param_1[2];
      plVar7 = param_2;
      do {
        *(undefined4 *)((longlong)plVar7 + 0x8c) = 0xc0000001;
        plVar7 = (longlong *)*plVar7;
      } while (plVar7 != (longlong *)0x0);
      (*pcVar1)(param_1[7],param_2,0);
    }
  }
  return;
}



===== FseCoreSendNetBufferListsComplete @ 140014004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FseCoreSendNetBufferListsComplete(undefined8 *param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  bool bVar2;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8 [2];
  longlong local_a0;
  undefined8 local_98 [4];
  longlong *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (param_1 == (undefined8 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  pcVar1 = (code *)param_1[2];
  if (pcVar1 == (code *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar2 = true;
  FseCoreInvokeNduNpiProvider((longlong)param_1,param_2,1,param_3);
  (*pcVar1)(*param_1,param_2);
  if (5 < DAT_14002a000) {
    if (((_DAT_14002a010 & 0x200) == 0) || ((DAT_14002a018 & 0x200) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_6c = 0;
      local_78 = &local_a0;
      local_5c = 0;
      local_a8[0] = 0;
      local_4c = 0;
      local_3c = 0;
      local_68 = "NetBufferListsComplete";
      local_58 = local_a8;
      local_48 = "Complete Outbound NBL Chain to Upper Shim";
      local_70 = 8;
      local_60 = 0x17;
      local_50 = 4;
      local_40 = 0x2a;
      local_a0 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027692,0,0,6,local_98);
    }
  }
  return;
}



===== FseNpiNduClientAttachProvider @ 140014150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FseNpiNduClientAttachProvider(undefined8 param_1,char *param_2,short *param_3)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  undefined1 auStackY_a8 [32];
  uint local_78 [4];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  cVar3 = KeGetCurrentIrql();
  if (cVar3 != '\0') {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  bVar1 = true;
  if (*param_3 == 1) {
    if (param_2 == (char *)0x0) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    if (*param_2 != '\0') {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    *(undefined8 *)(param_2 + 0x18) = param_1;
    uVar4 = NmrClientAttachProvider(param_1,param_2);
    if (uVar4 == 0) {
      *param_2 = '\x01';
      return 0;
    }
    if (-1 < (int)uVar4) goto LAB_140014292;
  }
  else {
    uVar4 = 0xc0000058;
  }
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_3c = 0;
      local_38 = local_78;
      local_2c = 0;
      local_48 = "FseNpiNduClientAttachProvider returned error";
      local_40 = 0x2d;
      local_30 = 4;
      local_78[0] = uVar4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027a63,0,0,4,local_68);
    }
  }
  if (uVar4 == 0) {
    return 0;
  }
LAB_140014292:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || (((uint)DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_3c = 0;
      local_38 = local_78;
      local_2c = 0;
      local_48 = "FseNpiNduClientAttachProvider returned error";
      local_40 = 0x2d;
      local_30 = 4;
      local_78[0] = uVar4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027a99,0,0,4,local_68);
    }
  }
  return uVar4;
}



===== FseNpiNduClientDetachProvider @ 140014340 =====

undefined8 FseNpiNduClientDetachProvider(longlong param_1)

{
  ExQueueWorkItem(param_1 + 0x20,3);
  return 0x103;
}



===== CleanupGlobals @ 14001436c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CleanupGlobals(void)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong in_R9;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  FseWskStopWorkQueue((longlong)(gPtServerGlobals + 6));
  lVar3 = *gPtServerGlobals;
  if (lVar3 != 0) {
    local_38 = 0;
    uStack_30 = 0;
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    RtlInitEnumerationHashTable(lVar3,&local_38);
    while( true ) {
      lVar4 = RtlEnumerateEntryHashTable(lVar3,&local_38);
      if (lVar4 == 0) break;
      uVar6 = 0;
      lVar5 = lVar4;
      RtlRemoveEntryHashTable(lVar3);
      LOCK();
      *(int *)(lVar3 + 0x2c) = *(int *)(lVar3 + 0x2c) + -1;
      UNLOCK();
      CloseSocketForPartition(lVar4,lVar5,uVar6,in_R9);
      LOCK();
      piVar1 = (int *)(lVar4 + 0x58);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(lVar4 + 0x60))(lVar4 + 0x58);
      }
      LOCK();
      piVar1 = (int *)(lVar4 + 0x58);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(lVar4 + 0x60))(lVar4 + 0x58);
      }
    }
    RtlEndEnumerationHashTable(lVar3,&local_38);
    RtlDeleteHashTable(lVar3);
    ExFreePoolWithTag(lVar3,0x6c477346);
  }
  ExFreePoolWithTag(gPtServerGlobals,0x6c477346);
  return;
}



===== InitializeGlobals @ 140014494 =====

ulonglong InitializeGlobals(void)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  plVar1 = (longlong *)ExAllocatePool2(0x40,0x80,0x6c477346);
  gPtServerGlobals = plVar1;
  if (plVar1 == (longlong *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    memset(plVar1,0,0x80);
    uVar2 = InitalizePartitionTable((longlong)plVar1);
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar2 = FseWskStartWorkQueue((PSLIST_HEADER)(gPtServerGlobals + 6));
      uVar3 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        return uVar3;
      }
    }
  }
  if (gPtServerGlobals != (longlong *)0x0) {
    plVar1 = gPtServerGlobals;
    if (*gPtServerGlobals != 0) {
      ExFreePoolWithTag(*gPtServerGlobals,0x6c477346);
      plVar1 = gPtServerGlobals;
      *gPtServerGlobals = 0;
    }
    ExFreePoolWithTag(plVar1,0x6c477346);
    gPtServerGlobals = (longlong *)0x0;
  }
  return uVar3;
}



===== PtServerGetStatisticsForPartition @ 140014554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PtServerGetStatisticsForPartition(byte *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  longlong local_res10;
  
  local_res10 = 0;
  if ((param_2 == (undefined4 *)0x0) ||
     (FindPartitionById(param_1,&local_res10), lVar7 = local_res10, local_res10 == 0)) {
    return 0xc000000d;
  }
  lVar3 = *(longlong *)(local_res10 + 0x68);
  ExAcquireSpinLockShared(local_res10 + 0x50);
  ExAcquireSpinLockSharedAtDpcLevel(lVar3 + 0x50);
  uVar4 = *(undefined4 *)(lVar7 + 0x1c);
  uVar5 = *(undefined4 *)(lVar7 + 0x20);
  uVar6 = *(undefined4 *)(lVar7 + 0x24);
  *param_2 = *(undefined4 *)(lVar7 + 0x18);
  param_2[1] = uVar4;
  param_2[2] = uVar5;
  param_2[3] = uVar6;
  param_2[4] = *(undefined4 *)(lVar3 + 0x2c);
  param_2[5] = *(undefined4 *)(lVar3 + 0xf0);
  *(undefined8 *)(param_2 + 6) = *(undefined8 *)(lVar3 + 0xf8);
  *(undefined8 *)(param_2 + 8) = *(undefined8 *)(lVar3 + 0x100);
  param_2[10] = *(undefined4 *)(lVar3 + 200);
  *(undefined8 *)(param_2 + 0xc) = *(undefined8 *)(local_res10 + 0x78);
  *(undefined8 *)(param_2 + 0xe) = *(undefined8 *)(local_res10 + 0x80);
  ExReleaseSpinLockSharedFromDpcLevel(lVar3 + 0x50);
  lVar7 = local_res10;
  ExReleaseSpinLockShared(local_res10 + 0x50);
  piVar1 = (int *)(lVar7 + 0x58);
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(lVar7 + 0x60))();
    return 0;
  }
  return 0;
}



===== PtServerInitialize @ 14001467c =====

ulonglong PtServerInitialize(void)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_427921e54f083bfd95ea087b74de8122_Traceguids);
  }
  if (gIsServerInitialized != '\0') {
    return 0;
  }
  uVar3 = InitializeGlobals();
  uVar5 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar5;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_427921e54f083bfd95ea087b74de8122_Traceguids,(int)uVar3);
    return uVar5;
  }
  iVar1 = MesEncodeDynBufferHandleCreate(&DAT_14002a6b0,&DAT_14002a6c0,&gFseMidlObject);
  if (iVar1 == 0) {
    uVar2 = FseWskRegister((undefined8 *)(gPtServerGlobals + 0x20),gPtServerGlobals + 8);
    uVar3 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      gIsServerInitialized = 1;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        gIsServerInitialized = 1;
        return uVar3;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
        gIsServerInitialized = 1;
        return uVar3;
      }
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_427921e54f083bfd95ea087b74de8122_Traceguids);
      return uVar3;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400147b0;
    uVar4 = 0xd;
  }
  else {
    uVar3 = 0xc000009a;
    if (gFseMidlObject != 0) {
      MesHandleFree();
    }
    gFseMidlObject = 0;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400147b0;
    uVar4 = 0xc;
    uVar2 = 0xc000009a;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_427921e54f083bfd95ea087b74de8122_Traceguids,uVar2);
LAB_1400147b0:
  CleanupGlobals();
  return uVar3;
}



===== PtServerResumePartition @ 1400147fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PtServerResumePartition(byte *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong local_res8;
  
  lVar5 = 0;
  local_res8 = 0;
  if ((param_1 == (byte *)0x0) || ((*(longlong *)param_1 == 0 && (*(longlong *)(param_1 + 8) == 0)))
     ) {
    uVar4 = 0xc000000d;
  }
  else {
    uVar3 = ExAcquireSpinLockExclusive(gPtServerGlobals + 0x70);
    FindPartitionById(param_1,&local_res8);
    lVar5 = local_res8;
    if (local_res8 == 0) {
      uVar4 = 0xc000000d;
      ExReleaseSpinLockExclusive();
      goto LAB_1400148c8;
    }
    ExReleaseSpinLockExclusive(gPtServerGlobals + 0x70,uVar3);
    uVar4 = ResumePartition(lVar5);
    uVar4 = uVar4 & 0xffffffff;
  }
  if (lVar5 != 0) {
    piVar1 = (int *)(lVar5 + 0x58);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(lVar5 + 0x60))();
    }
  }
LAB_1400148c8:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_427921e54f083bfd95ea087b74de8122_Traceguids,param_1,(char)uVar4);
  }
  return uVar4;
}



===== PtServerStartPartition @ 14001491c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PtServerStartPartition
                    (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 auStackY_78 [32];
  longlong local_48 [2];
  longlong local_38;
  longlong local_30;
  longlong lStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar8 = 0;
  bVar3 = false;
  uVar4 = 0;
  local_48[0] = 0;
  local_30 = 0;
  lStack_28 = 0;
  if ((param_1 == (longlong *)0x0) || ((*param_1 == 0 && (param_1[1] == 0)))) {
    uVar7 = 0xc000000d;
  }
  else {
    local_30 = *param_1;
    lStack_28 = param_1[1];
    uVar4 = ExAcquireSpinLockExclusive(gPtServerGlobals + 0x70);
    bVar3 = true;
    FindPartitionById((byte *)&local_30,local_48);
    if (local_48[0] == 0) {
      lVar6 = gPtServerGlobals + 0x30;
      uVar5 = CreateAndAddPartition((byte *)&local_30,lVar6,local_48);
      lVar8 = local_48[0];
      uVar7 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        local_38 = 0;
        if (*(longlong *)(local_48[0] + 0x68) == 0) {
          uVar7 = 0xc000000d;
        }
        else {
          uVar5 = FseAllocateSocketOpContext
                            (*(longlong *)(local_48[0] + 0x68),lVar6,0,param_4,&local_38);
          uVar7 = uVar5 & 0xffffffff;
          if (-1 < (int)uVar5) {
            FseWskEnqueueOp(local_38,FseWskOpStartConnection);
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (4 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                             &WPP_427921e54f083bfd95ea087b74de8122_Traceguids,&local_30,(char)uVar5)
              ;
            }
            goto LAB_140014ab7;
          }
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_427921e54f083bfd95ea087b74de8122_Traceguids,(int)uVar7);
        }
        if (-1 < (int)uVar7) goto LAB_140014ab7;
        RemovePartitionFromTable((byte *)&local_30);
        piVar1 = (int *)(lVar8 + 0x58);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (**(code **)(lVar8 + 0x60))();
        }
      }
      lVar8 = local_48[0];
    }
    else {
      uVar7 = 0x40000000;
      lVar8 = local_48[0];
    }
  }
LAB_140014ab7:
  if (lVar8 != 0) {
    piVar1 = (int *)(lVar8 + 0x58);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(lVar8 + 0x60))();
    }
  }
  if (bVar3) {
    ExReleaseSpinLockExclusive(gPtServerGlobals + 0x70,uVar4);
  }
  return uVar7;
}



===== PtServerStopPartition @ 140014b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
PtServerStopPartition(byte *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  longlong local_res8 [2];
  
  uVar7 = 0;
  local_res8[0] = 0;
  if ((param_1 == (byte *)0x0) || ((*(longlong *)param_1 == 0 && (*(longlong *)(param_1 + 8) == 0)))
     ) {
    uVar7 = 0xc000000d;
  }
  else {
    uVar4 = ExAcquireSpinLockExclusive(gPtServerGlobals + 0x70);
    plVar5 = local_res8;
    FindPartitionById(param_1,plVar5);
    lVar3 = local_res8[0];
    if (local_res8[0] == 0) {
      uVar7 = 0xc000000d;
      ExReleaseSpinLockExclusive(gPtServerGlobals + 0x70,uVar4);
      goto LAB_140014c1d;
    }
    RemovePartitionFromTable(param_1);
    uVar6 = CONCAT71((int7)((ulonglong)plVar5 >> 8),uVar4);
    ExReleaseSpinLockExclusive(gPtServerGlobals + 0x70);
    CloseSocketForPartition(lVar3,uVar6,param_3,param_4);
    piVar1 = (int *)(lVar3 + 0x58);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(lVar3 + 0x60))();
    }
  }
  if (local_res8[0] != 0) {
    piVar1 = (int *)(local_res8[0] + 0x58);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(local_res8[0] + 0x60))();
    }
  }
LAB_140014c1d:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                   &WPP_427921e54f083bfd95ea087b74de8122_Traceguids,param_1,(char)uVar7);
  }
  return uVar7;
}



===== CreateAndAddPartition @ 140014c68 =====

ulonglong CreateAndAddPartition(byte *param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  byte bVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  void *_Dst;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  ulonglong uVar10;
  
  plVar1 = gPtServerGlobals;
  lVar9 = 0;
  *param_3 = 0;
  lVar3 = *plVar1;
  _Dst = (void *)ExAllocatePool2(0x40,0x490,0x64507346);
  if (_Dst == (void *)0x0) {
    uVar10 = 0xc000009a;
  }
  else {
    uVar8 = 0;
    memset(_Dst,0,0x490);
    uVar4 = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)((longlong)_Dst + 0x18) = *(undefined8 *)param_1;
    *(undefined8 *)((longlong)_Dst + 0x20) = uVar4;
    *(undefined8 *)((longlong)_Dst + 0x30) = 0;
    *(code **)((longlong)_Dst + 0x60) = CleanupPartition;
    *(undefined4 *)((longlong)_Dst + 0x58) = 0;
    LOCK();
    *(int *)((longlong)_Dst + 0x58) = *(int *)((longlong)_Dst + 0x58) + 1;
    UNLOCK();
    *(undefined4 *)((longlong)_Dst + 0x70) = 1;
    plVar1 = (longlong *)((longlong)_Dst + 0x68);
    *(undefined4 *)((longlong)_Dst + 0x50) = 0;
    *(undefined8 *)((longlong)_Dst + 0x40) = 0;
    *(undefined8 *)((longlong)_Dst + 0x48) = 0;
    uVar6 = CreateConnectionSocketContext((longlong)_Dst,uVar8,param_2,plVar1);
    lVar7 = *plVar1;
    uVar10 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) {
      if (lVar7 != 0) {
        CleanupConnectionSocketContext(lVar7 + 8);
        *plVar1 = 0;
      }
      ExFreePoolWithTag(_Dst,0x64507346);
    }
    else {
      LOCK();
      *(int *)(lVar7 + 8) = *(int *)(lVar7 + 8) + 1;
      UNLOCK();
      lVar7 = 0x10;
      do {
        bVar2 = *param_1;
        param_1 = param_1 + 1;
        lVar9 = lVar9 * 0x25 + (ulonglong)bVar2;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      uVar5 = ExAcquireSpinLockExclusive(lVar3 + 0x28);
      RtlInsertEntryHashTable(lVar3,_Dst,lVar9,0);
      LOCK();
      *(int *)(lVar3 + 0x2c) = *(int *)(lVar3 + 0x2c) + 1;
      UNLOCK();
      LOCK();
      *(int *)((longlong)_Dst + 0x58) = *(int *)((longlong)_Dst + 0x58) + 1;
      UNLOCK();
      *(undefined4 *)((longlong)_Dst + 0x70) = 1;
      *param_3 = _Dst;
      LOCK();
      *(int *)((longlong)_Dst + 0x58) = *(int *)((longlong)_Dst + 0x58) + 1;
      UNLOCK();
      ExReleaseSpinLockExclusive(lVar3 + 0x28,uVar5);
    }
  }
  return uVar10;
}



===== FindPartitionById @ 140014de8 =====

void FindPartitionById(byte *param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  
  plVar1 = gPtServerGlobals;
  *param_2 = 0;
  uVar2 = ExAcquireSpinLockShared(*plVar1 + 0x28);
  FindPartitionByIdInternal(param_1,param_2);
  ExReleaseSpinLockShared(*gPtServerGlobals + 0x28,uVar2);
  return;
}



===== FindPartitionByIdInternal @ 140014e5c =====

void FindPartitionByIdInternal(byte *param_1,longlong *param_2)

{
  byte bVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  byte *pbVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar4 = 0;
  local_18 = 0;
  *param_2 = 0;
  lVar3 = 0x10;
  pbVar5 = param_1;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    lVar4 = lVar4 * 0x25 + (ulonglong)bVar1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = *gPtServerGlobals;
  lVar3 = RtlLookupEntryHashTable(uVar2,lVar4,&local_28);
  while( true ) {
    if (lVar3 == 0) {
      return;
    }
    if ((*(longlong *)(lVar3 + 0x18) == *(longlong *)param_1) &&
       (*(longlong *)(lVar3 + 0x20) == *(longlong *)(param_1 + 8))) break;
    lVar3 = RtlGetNextEntryHashTable(uVar2,&local_28);
  }
  LOCK();
  *(int *)(lVar3 + 0x58) = *(int *)(lVar3 + 0x58) + 1;
  UNLOCK();
  *param_2 = lVar3;
  return;
}



===== InitalizePartitionTable @ 140014f0c =====

undefined8 InitalizePartitionTable(longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong local_res8;
  
  plVar1 = gPtServerGlobals;
  uVar3 = 0;
  if (gPtServerGlobals == (longlong *)0x0) {
    uVar3 = 0xc000000d;
  }
  else {
    *gPtServerGlobals = 0;
    local_res8 = param_1;
    lVar4 = ExAllocatePool2(0x40,0x30,0x6c477346);
    if (lVar4 == 0) {
      uVar3 = 0xc000009a;
    }
    else {
      *(undefined4 *)(lVar4 + 0x28) = 0;
      local_res8 = lVar4;
      cVar2 = RtlCreateHashTable(&local_res8,0,0);
      if (cVar2 == '\0') {
        uVar3 = 0xc000009a;
        ExFreePoolWithTag(lVar4,0x6c477346);
      }
      else {
        *(undefined4 *)(lVar4 + 0x2c) = 0;
        *plVar1 = lVar4;
      }
    }
  }
  return uVar3;
}



===== RemovePartitionFromTable @ 140014fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RemovePartitionFromTable(byte *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong *local_res18;
  
  local_res18 = (longlong *)0x0;
  lVar2 = *gPtServerGlobals;
  uVar4 = ExAcquireSpinLockExclusive(lVar2 + 0x28);
  FindPartitionByIdInternal(param_1,(longlong *)&local_res18);
  plVar5 = local_res18;
  if (local_res18 == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                    &WPP_e4b0f862661a34bf87a65b0bb2dcec12_Traceguids,param_1);
    }
  }
  else {
    RtlRemoveEntryHashTable(lVar2,local_res18,0);
    LOCK();
    *(int *)(lVar2 + 0x2c) = *(int *)(lVar2 + 0x2c) + -1;
    UNLOCK();
    plVar5 = local_res18 + 0xb;
    LOCK();
    lVar3 = *plVar5;
    *(int *)plVar5 = (int)*plVar5 + -1;
    UNLOCK();
    if ((int)lVar3 == 1) {
      (*(code *)local_res18[0xc])();
    }
    plVar5 = local_res18;
  }
  ExReleaseSpinLockExclusive(lVar2 + 0x28,uVar4);
  if (plVar5 != (longlong *)0x0) {
    plVar1 = plVar5 + 0xb;
    LOCK();
    lVar2 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar2 == 1) {
      (*(code *)plVar5[0xc])();
    }
  }
  return;
}



===== FseWskOpStartConnection @ 1400150d0 =====

void FseWskOpStartConnection(longlong param_1)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = WskCaptureProviderNPI(gPtServerGlobals + 8,0xffffffff,&local_18);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_14e54eb5fde531897c926e1c81999b52_Traceguids,iVar1);
    }
    FseFreeSocketOpContext(param_1);
  }
  else {
    FseWskSetupConnectionSocket(&local_18,param_1);
    WskReleaseProviderNPI(gPtServerGlobals + 8);
  }
  return;
}



===== FseWskReconnectSocket @ 140015170 =====

void FseWskReconnectSocket(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint in_stack_ffffffffffffffb8;
  undefined8 local_28;
  longlong local_20;
  
  lVar2 = *(longlong *)(param_1 + 0x20);
  uVar4 = ExAcquireSpinLockExclusive(lVar2 + 0x50);
  if (*(char *)(lVar2 + 0x40) == '\0') {
    puVar1 = (uint *)(lVar2 + 200);
    uVar5 = *(int *)(lVar2 + 0xcc) + 1;
    *(uint *)(lVar2 + 0xcc) = uVar5;
    if (0x32 < uVar5) {
      uVar5 = *puVar1;
      *puVar1 = uVar5 * 2;
      if (10000 < (int)(uVar5 * 2)) {
        *puVar1 = 10000;
      }
      *(undefined4 *)(lVar2 + 0xcc) = 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      in_stack_ffffffffffffffb8 = *puVar1;
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                     &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,
                     *(longlong *)(lVar2 + 0xa8) + 0x18,(char)in_stack_ffffffffffffffb8);
    }
    uVar3 = *(undefined8 *)(lVar2 + 0xd0);
    ExSetTimer(uVar3,(longlong)(int)*puVar1 * -10000,0,0);
    ExReleaseSpinLockExclusive(lVar2 + 0x50,uVar4);
    local_20 = lVar2 + 0xd8;
    local_28 = uVar3;
    uVar5 = KeWaitForMultipleObjects(2,&local_28,1,0,in_stack_ffffffffffffffb8 & 0xffffff00,0,0,0);
    if (((1 < uVar5) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                     &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,
                     *(longlong *)(lVar2 + 0xa8) + 0x18,(char)uVar5);
    }
  }
  else {
    ExReleaseSpinLockExclusive(lVar2 + 0x50,uVar4);
  }
  FseWskEnqueueOp(param_1,FseWskOpStartConnection);
  return;
}



===== FseAllocatorApplyPatchToAcquisition @ 140015320 =====

undefined8 FseAllocatorApplyPatchToAcquisition(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined **ppuVar4;
  undefined2 uVar5;
  ushort uVar6;
  uint uVar7;
  ushort uVar8;
  
  ppuVar4 = *(undefined ***)(param_1 + 0x18);
  if (((ppuVar4 == (undefined **)0x0) || (ppuVar4 == *(undefined ***)(param_2 + 0x30))) &&
     (ppuVar4 = (undefined **)(ulonglong)*(uint *)(param_2 + 0x40),
     (*(uint *)(param_1 + 0x20) & *(uint *)(param_2 + 0x40)) != 0)) {
    uVar8 = *(ushort *)(param_1 + 0x28);
    if (*(ushort *)(param_1 + 0x28) <= *(ushort *)(param_2 + 0x50)) {
      uVar8 = *(ushort *)(param_2 + 0x50);
    }
    uVar1 = *(ushort *)(param_2 + 0x52);
    ppuVar4 = (undefined **)(ulonglong)uVar1;
    uVar6 = *(ushort *)(param_1 + 0x2a);
    if (uVar1 <= *(ushort *)(param_1 + 0x2a)) {
      uVar6 = uVar1;
    }
    if ((uVar8 <= uVar6) && ((ushort)(uVar6 - uVar8) != -1)) {
      iVar2 = *(int *)(param_1 + 0x2c);
      if (iVar2 == 0) {
        if (*(int *)(param_2 + 0x54) != 0) {
          *(undefined4 *)(param_2 + 0x54) = 0;
          ppuVar4 = &WPP_GLOBAL_Control;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            ppuVar4 = (undefined **)
                      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                              &WPP_0a4162c06d633298bdd78402b86e5e2f_Traceguids);
          }
        }
      }
      else {
        if (iVar2 == 2) {
          uVar3 = *(uint *)(param_1 + 0x30);
          uVar7 = uVar3 & *(uint *)(param_2 + 0x44);
          ppuVar4 = (undefined **)(ulonglong)uVar7;
          if (uVar3 == uVar7) goto LAB_14001546d;
          *(uint *)(param_2 + 0x44) = uVar3 | *(uint *)(param_2 + 0x44);
          ppuVar4 = &WPP_GLOBAL_Control;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_14001546d;
          uVar5 = 0x13;
        }
        else {
          if (iVar2 != 3) goto LAB_14001546d;
          uVar3 = *(uint *)(param_1 + 0x30);
          ppuVar4 = (undefined **)(ulonglong)uVar3;
          uVar7 = ~uVar3 & *(uint *)(param_2 + 0x44);
          if ((uVar7 & uVar3) == 0) goto LAB_14001546d;
          *(uint *)(param_2 + 0x44) = uVar7;
          ppuVar4 = &WPP_GLOBAL_Control;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_14001546d;
          uVar5 = 0x14;
        }
        ppuVar4 = (undefined **)
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                           &WPP_0a4162c06d633298bdd78402b86e5e2f_Traceguids,
                           *(undefined4 *)(param_1 + 0x30));
      }
    }
  }
LAB_14001546d:
  return CONCAT71((int7)((ulonglong)ppuVar4 >> 8),1);
}



===== FseAllocatorCountPartitionReferences @ 140015480 =====

undefined1 FseAllocatorCountPartitionReferences(longlong *param_1,longlong param_2)

{
  if (*param_1 == *(longlong *)(param_2 + 0x28)) {
    *(int *)(param_1 + 1) = (int)param_1[1] + 1;
  }
  if (*param_1 == *(longlong *)(param_2 + 0x30)) {
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
  }
  return 1;
}



===== FseAllocatorCreatePatch @ 1400154a0 =====

undefined8
FseAllocatorCreatePatch
          (longlong *param_1,undefined8 param_2,undefined8 param_3,ushort *param_4,uint param_5,
          uint param_6,undefined8 *param_7)

{
  ushort *puVar1;
  ushort uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined4 in_stack_ffffffffffffffc8;
  undefined4 in_stack_ffffffffffffffcc;
  
  uVar2 = g_FseDebugPort;
  puVar1 = param_4 + 1;
  uVar7 = (uint)param_3;
  *param_7 = 0;
  if (((*param_4 <= uVar2) && (uVar2 <= *puVar1)) && (g_FseDebugPort != 0)) {
    pcVar3 = (code *)swi(3);
    uVar4 = (*pcVar3)();
    return uVar4;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_DDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*param_4,param_3,param_1
                      ,CONCAT44(in_stack_ffffffffffffffcc,in_stack_ffffffffffffffc8),(char)param_3,
                      (char)*param_4,(char)*puVar1);
  }
  uVar2 = *param_4;
  if ((uVar2 == 0) || (*puVar1 < uVar2)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,param_3,(uint)uVar2,(char)*puVar1);
    return 0xc000000d;
  }
  if ((uVar7 == 6) || (uVar7 == 0x11)) {
    puVar6 = (undefined8 *)0x0;
    if ((param_1 != (longlong *)0x0) &&
       (puVar6 = FsePartitionFindById(param_1), puVar6 == (undefined8 *)0x0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                      &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
      }
      return 0xc0000034;
    }
    if (param_5 == 0) {
      if (param_6 != 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000000d;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc000000d;
        }
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids);
        return 0xc000000d;
      }
LAB_14001574d:
      uVar4 = FsePatchAllocate(puVar6,puVar6,uVar7,(undefined4 *)param_4,param_5,param_6,param_7);
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar4 + 0x3c,
                 &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,*param_7);
      }
      return 0;
    }
    if (param_5 == 1) {
      if ((param_6 & 0xc0000000) == 0xc0000000) goto LAB_14001574d;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      uVar5 = 0x37;
    }
    else if ((param_5 == 2) || (param_5 == 3)) {
      if ((param_6 & 0xffffffc0) == 0) goto LAB_14001574d;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      uVar5 = 0x38;
    }
    else if ((param_5 == 4) || (param_5 == 5)) {
      if ((param_6 & 0xfffffffc) == 0) goto LAB_14001574d;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      uVar5 = 0x39;
    }
    else {
      if (param_5 != 6) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000000d;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc000000d;
        }
        uVar5 = 0x3b;
        goto LAB_1400156fa;
      }
      if (param_6 != 0) goto LAB_14001574d;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      uVar5 = 0x3a;
    }
    param_5 = param_6;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    uVar5 = 0x33;
    param_5 = uVar7;
  }
LAB_1400156fa:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_5);
  return 0xc000000d;
}



===== FseAllocatorDestroyPatch @ 1400157f0 =====

void FseAllocatorDestroyPatch(uint *param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
             &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_14002a630);
  puVar1 = param_1 + 2;
  lVar2 = *(longlong *)puVar1;
  if ((*(uint **)(lVar2 + 8) == puVar1) &&
     (plVar3 = *(longlong **)(param_1 + 4), (uint *)*plVar3 == puVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLock(&DAT_14002a630,CONCAT71((int7)((ulonglong)puVar1 >> 8),uVar5));
    *param_1 = *param_1 | 0x80;
    ExFreePoolWithTag(param_1,0x54657346);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== FseAllocatorGetPool @ 14001589c =====

undefined8 FseAllocatorGetPool(int param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 6) {
    uVar1 = g_TcpPool;
  }
  else if (param_1 == 0x11) {
    uVar1 = g_UdpPool;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== FseAllocatorInitialize2 @ 1400158fc =====

ulonglong FseAllocatorInitialize2(void)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids);
  }
  DAT_14002a670 = 0;
  DAT_14002a674 = 0;
  DAT_14002a668 = 0;
  DAT_14002a66c = 0;
  DAT_14002a660 = 0;
  DAT_14002a664 = 0;
  DAT_14002a650 = 0;
  DAT_14002a658 = 0;
  DAT_14002a618 = &DAT_14002a610;
  DAT_14002a610 = &DAT_14002a610;
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x48,0x57657346);
  DAT_14002a6a8 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    DAT_14002a628 = &DAT_14002a620;
    DAT_14002a620 = &DAT_14002a620;
    KeInitializeSpinLock(&DAT_14002a630);
    uVar2 = FsePortPoolAllocate(&g_TcpPool);
    if ((int)uVar2 == 0) {
      uVar3 = FsePortPoolAllocate(&g_UdpPool);
      uVar2 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0) {
        FsePortPoolSetOptions((longlong)g_TcpPool);
        FsePortPoolSetOptions(g_UdpPool);
        g_FseAllocatorBeginRequestCallback = FseAllocatorBeginActiveRequest;
        g_FseAllocatorEndRequestCallback = FseAllocatorEndActiveRequest;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                  &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids);
        }
        uVar2 = 0;
      }
      else {
        FsePortPoolFree(g_TcpPool);
        g_TcpPool = (uint *)0x0;
      }
    }
  }
  return uVar2;
}



===== FseAllocatorNotifyCreatePartition @ 140015a8c =====

void FseAllocatorNotifyCreatePartition(longlong *param_1)

{
  undefined8 local_res10 [3];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
  }
  local_res10[0] = 0;
  FsePartitionAllocate(param_1,local_res10);
  return;
}



===== FseAllocatorNotifyDestroyPartition @ 140015ae8 =====

undefined8 FseAllocatorNotifyDestroyPartition(longlong *param_1)

{
  longlong *plVar1;
  uint uVar2;
  undefined1 uVar3;
  uint *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  uint *local_18;
  uint local_10;
  int local_c;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
  }
  puVar4 = (uint *)FsePartitionFindById(param_1);
  if (puVar4 == (uint *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                    &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
    }
    uVar5 = 0xc0000034;
  }
  else {
    local_10 = 0;
    local_c = 0;
    local_18 = puVar4;
    FsePortPoolEnumReservations(g_TcpPool,FseAllocatorCountPartitionReferences,&local_18);
    pcVar6 = FseAllocatorCountPartitionReferences;
    FsePortPoolEnumReservations(g_UdpPool,FseAllocatorCountPartitionReferences,&local_18);
    uVar8 = (ulonglong)local_10;
    if ((local_10 == 0) && (local_c == 0)) {
      uVar7 = 0;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_14002a630);
      puVar9 = DAT_14002a620;
      while ((undefined8 **)puVar9 != &DAT_14002a620) {
        plVar1 = puVar9 + 2;
        puVar9 = (undefined8 *)*puVar9;
        uVar2 = uVar7 + 1;
        if ((uint *)*plVar1 != puVar4) {
          uVar2 = uVar7;
        }
        uVar7 = uVar2;
        uVar8 = (ulonglong)uVar7;
      }
      uVar5 = CONCAT71((int7)((ulonglong)pcVar6 >> 8),uVar3);
      KeReleaseSpinLock(&DAT_14002a630);
      if (uVar7 == 0) {
        FsePartitionFree(puVar4);
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF__guid_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,uVar8,param_1,(char)uVar7);
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                      &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1,(char)local_10,
                      (char)local_c);
    }
    uVar5 = 0xc0000708;
  }
  return uVar5;
}



===== FseAllocatorQueryPartitions @ 140015ca0 =====

void FseAllocatorQueryPartitions(ulonglong param_1,longlong param_2,ulonglong *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  
  *param_3 = 0;
  uVar5 = ExAcquireSpinLockShared(&DAT_14002a6a0);
  uVar7 = 0;
  for (puVar8 = DAT_14002a610; (undefined8 **)puVar8 != &DAT_14002a610;
      puVar8 = (undefined8 *)*puVar8) {
    uVar6 = (ulonglong)((int)uVar7 + 1);
    if (uVar6 <= param_1) {
      uVar2 = *(undefined4 *)((longlong)puVar8 + 0x14);
      uVar3 = *(undefined4 *)(puVar8 + 3);
      uVar4 = *(undefined4 *)((longlong)puVar8 + 0x1c);
      puVar1 = (undefined4 *)(param_2 + uVar7 * 0x10);
      *puVar1 = *(undefined4 *)(puVar8 + 2);
      puVar1[1] = uVar2;
      puVar1[2] = uVar3;
      puVar1[3] = uVar4;
    }
    uVar7 = uVar6;
  }
  ExReleaseSpinLockShared(&DAT_14002a6a0,uVar5);
  *param_3 = uVar7;
  return;
}



===== FseAllocatorQueryStatistics @ 140015d44 =====

void FseAllocatorQueryStatistics(undefined4 *param_1)

{
  int local_res8 [2];
  int local_res10 [6];
  
  memset(param_1,0,0x40);
  local_res8[0] = 0;
  param_1[4] = DAT_14002a670;
  param_1[5] = DAT_14002a674;
  param_1[6] = DAT_14002a668;
  param_1[7] = DAT_14002a66c;
  param_1[8] = DAT_14002a660;
  param_1[9] = DAT_14002a664;
  *(undefined8 *)(param_1 + 10) = DAT_14002a650;
  *(undefined8 *)(param_1 + 0xc) = DAT_14002a658;
  FsePortPoolQueryDiagnosticStatistics(g_TcpPool,param_1,param_1 + 2,local_res8);
  local_res10[0] = 0;
  FsePortPoolQueryDiagnosticStatistics(g_UdpPool,param_1 + 1,param_1 + 3,local_res10);
  param_1[0xe] = local_res8[0] + local_res10[0];
  return;
}



===== FseAllocatorRebuildDatapathCache @ 140015df8 =====

void FseAllocatorRebuildDatapathCache(int param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  
  lVar2 = FseAllocatorGetPool(param_1);
  uVar1 = ExAcquireSpinLockExclusive(lVar2 + 0x18);
  FsePortPoolRebuildCacheUnderLock(lVar2);
  ExReleaseSpinLockExclusive(lVar2 + 0x18,uVar1);
  return;
}



===== FseAllocatorSerializeEnumeratePortAllocations @ 140015e60 =====

undefined8 FseAllocatorSerializeEnumeratePortAllocations(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  *(int *)*param_1 = *(int *)*param_1 + 1;
  lVar3 = *param_1;
  uVar2 = *(uint *)((longlong)param_1 + 0xc);
  uVar5 = (ulonglong)uVar2;
  if (uVar2 < *(uint *)(lVar3 + 4)) {
    lVar6 = (ulonglong)uVar2 * 0x40;
    *(undefined2 *)(lVar6 + 0x40 + lVar3) = *(undefined2 *)(param_2 + 0x50);
    *(undefined2 *)(lVar6 + 0x42 + lVar3) = *(undefined2 *)(param_2 + 0x52);
    *(int *)(lVar6 + 0x30 + lVar3) = (int)param_1[1];
    uVar5 = *(ulonglong *)(param_2 + 0x48);
    *(ulonglong *)(lVar6 + 0x28 + lVar3) = uVar5;
    *(undefined4 *)(lVar6 + 0x34 + lVar3) = *(undefined4 *)(param_2 + 0x40);
    *(undefined4 *)(lVar6 + 0x38 + lVar3) = *(undefined4 *)(param_2 + 0x44);
    *(undefined4 *)(lVar6 + 0x3c + lVar3) = *(undefined4 *)(param_2 + 0x54);
    uVar4 = *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 0x20);
    puVar1 = (undefined8 *)(lVar6 + 0x18 + lVar3);
    *puVar1 = *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 0x18);
    puVar1[1] = uVar4;
    uVar4 = *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x20);
    puVar1 = (undefined8 *)(lVar6 + 8 + lVar3);
    *puVar1 = *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x18);
    puVar1[1] = uVar4;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
  }
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== FseIsInterpartitionLoopbackAllowed @ 140015ee4 =====

undefined1 FseIsInterpartitionLoopbackAllowed(longlong *param_1)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  uVar1 = ExAcquireSpinLockShared(&DAT_14002a6a0);
  puVar2 = DAT_14002a610;
  do {
    if ((undefined8 **)puVar2 == &DAT_14002a610) {
LAB_140015f38:
      ExReleaseSpinLockShared(&DAT_14002a6a0,uVar1);
      return uVar3;
    }
    if ((puVar2[2] == *param_1) && (puVar2[3] == param_1[1])) {
      uVar3 = *(undefined1 *)(puVar2 + 6);
      goto LAB_140015f38;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== FsePortTrackerAcquirePorts @ 140015f64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong FsePortTrackerAcquirePorts
                    (longlong *param_1,uint *param_2,byte param_3,undefined8 param_4,
                    ulonglong *param_5,ushort *param_6)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  int *piVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined4 extraout_var;
  ulonglong uVar9;
  int *piVar10;
  undefined1 auStackY_118 [32];
  byte local_b8 [8];
  byte local_b0;
  uint local_a8 [4];
  longlong local_98 [2];
  undefined8 *local_88;
  undefined8 local_80;
  longlong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  ulonglong local_60;
  undefined8 uStack_58;
  uint local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  local_a8[0] = 0;
  local_98[0] = 0;
  local_b0 = 0;
  local_b8[0] = param_3;
  if ((((ushort)param_2[6] <= g_FseDebugPort) &&
      (g_FseDebugPort <= *(ushort *)((longlong)param_2 + 0x1a))) && (g_FseDebugPort != 0)) {
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DDDDDDD_guid__guid_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
               (ulonglong)*(ushort *)((longlong)param_2 + 0x1a),(ulonglong)(ushort)param_2[6],
               param_2[5],(char)param_2[6],(char)*(ushort *)((longlong)param_2 + 0x1a),param_3,
               (char)*param_2,(char)param_2[7],0,param_2 + 1,param_1);
  }
  local_98[1] = 0;
  local_78 = KeQueryInterruptTimePrecise(local_98 + 1);
  uVar3 = *param_2;
  if ((uVar3 != 1) && (uVar3 != 2)) {
    if ((uVar3 == 4) || (uVar3 == 8)) {
      piVar10 = &DAT_14002a66c;
      piVar5 = &DAT_14002a670;
      goto LAB_140016098;
    }
    if ((uVar3 == 0x10) || (uVar3 == 0x20)) {
      piVar10 = &DAT_14002a660;
      piVar5 = &DAT_14002a674;
      goto LAB_140016098;
    }
  }
  piVar10 = &DAT_14002a664;
  piVar5 = &DAT_14002a668;
LAB_140016098:
  LOCK();
  *piVar5 = *piVar5 + 1;
  UNLOCK();
  *param_5 = 0;
  if (param_6 != (ushort *)0x0) {
    param_6[3] = 0;
  }
  uVar4 = FsePortTrackerValidateAcquisitionParameters(param_2,local_b8[0],local_a8[0],param_6);
  if ((int)uVar4 == 0) {
    puVar6 = FsePartitionFindById(param_1);
    local_88 = puVar6;
    puVar7 = FsePartitionFindById((longlong *)(param_2 + 1));
    if ((puVar6 == (undefined8 *)0x0) || (puVar7 == (undefined8 *)0x0)) {
      uVar4 = 0xc0000034;
    }
    else {
      lVar8 = FseAllocatorGetPool(param_2[5]);
      if (lVar8 == 0) {
        uVar4 = 0xc000000d;
      }
      else {
        local_70 = *(undefined8 *)param_2;
        uStack_68 = *(undefined8 *)(param_2 + 2);
        local_50 = param_2[8];
        local_60 = *(ulonglong *)(param_2 + 4);
        uStack_58 = *(undefined8 *)(param_2 + 6);
        iVar2 = FsePatchModifyAcquisitionRequest((uint *)&local_70,local_b8,local_a8);
        uVar4 = CONCAT44(extraout_var,iVar2);
        if (iVar2 == 0) {
          uVar3 = param_2[5];
          if (g_FseAllocatorBeginRequestCallback != (code *)0x0) {
            local_b0 = (*g_FseAllocatorBeginRequestCallback)(uVar3);
          }
          uVar4 = FsePortPoolCreateReservation2
                            (lVar8,(longlong)local_88,puVar7,(uint)local_70,local_50,uStack_58._4_4_
                             ,local_b8[0],(undefined4 *)&uStack_58,(byte)local_a8[0],(uint)local_b0,
                             local_98);
          uVar9 = uVar4 & 0xffffffff;
          if (g_FseAllocatorEndRequestCallback != (code *)0x0) {
            (*g_FseAllocatorEndRequestCallback)(uVar3,local_b0);
          }
          if ((int)uVar4 == 0) {
            local_80 = 0;
            *param_5 = (local_60 >> 0x20) << 0x38 | *(ulonglong *)(local_98[0] + 0x38);
            lVar8 = KeQueryInterruptTimePrecise(&local_80);
            uVar4 = (lVar8 - local_78) * 100;
            if (DAT_14002a658 < uVar4) {
              DAT_14002a658 = uVar4;
            }
            LOCK();
            DAT_14002a650 = DAT_14002a650 + uVar4;
            UNLOCK();
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                       &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,*param_5);
            }
            return 0;
          }
          if (((int)uVar4 == -0x3ffff8f8) && (param_6 != (ushort *)0x0)) {
            uVar3 = FsePortPoolGetSuggestedFreePort
                              (lVar8,puVar7,(uint)local_70,local_b8[0],
                               ((uint)uStack_58._2_2_ - (uint)(ushort)uStack_58) + 1,param_6[2],
                               param_6);
            param_6[3] = (ushort)uVar3;
            if ((ushort)uVar3 == 0) {
              uVar9 = 0xc0000209;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                        &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids);
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                       &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,uVar3 & 0xffff);
            }
          }
          LOCK();
          *piVar10 = *piVar10 + 1;
          UNLOCK();
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                     &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,(int)uVar9);
          }
          return uVar9;
        }
      }
    }
  }
  LOCK();
  *piVar10 = *piVar10 + 1;
  UNLOCK();
  return uVar4;
}



===== FsePortTrackerGetDefaultSharingFlags @ 140016368 =====

undefined4 FsePortTrackerGetDefaultSharingFlags(int param_1)

{
  if (param_1 == 1) {
    return 0xd;
  }
  if (param_1 != 2) {
    if (param_1 == 4) {
      return 0x29;
    }
    if (param_1 == 8) {
      return 0x3d;
    }
    if (param_1 == 0x10) {
      return 8;
    }
    if (param_1 == 0x20) {
      return 0x2c;
    }
  }
  return 0;
}



===== FsePortTrackerReleasePartitionPorts @ 1400163b0 =====

undefined8 FsePortTrackerReleasePartitionPorts(longlong *param_1)

{
  longlong ***ppplVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                  &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
  }
  ppplVar1 = (longlong ***)FsePartitionFindById(param_1);
  if (ppplVar1 == (longlong ***)0x0) {
    uVar2 = 0xc0000034;
  }
  else {
    FsePortPoolDeleteAllReservationsByPartition(g_TcpPool,ppplVar1);
    FsePortPoolDeleteAllReservationsByPartition(g_UdpPool,ppplVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== FsePortTrackerReleasePortRange @ 140016430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong FsePortTrackerReleasePortRange(longlong *param_1,ulonglong param_2,undefined8 param_3)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  bVar1 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,(char)param_2)
    ;
  }
  lVar2 = FseAllocatorGetPool((uint)(byte)(param_2 >> 0x38));
  if (lVar2 == 0) {
    uVar3 = 0xc0000465;
  }
  else {
    puVar4 = FsePartitionFindById(param_1);
    if (puVar4 == (undefined8 *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                      &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
      }
      uVar3 = 0xc0000034;
    }
    else {
      if (g_FseAllocatorBeginRequestCallback != (code *)0x0) {
        bVar1 = (*g_FseAllocatorBeginRequestCallback)(param_2 >> 0x38);
      }
      uVar3 = FsePortPoolDeleteReservationByToken2
                        (lVar2,(longlong)puVar4,(uint)bVar1,param_2 & 0xffffffffffffff);
      uVar3 = uVar3 & 0xffffffff;
      if (g_FseAllocatorEndRequestCallback != (code *)0x0) {
        (*g_FseAllocatorEndRequestCallback)(param_2 >> 0x38,bVar1);
      }
    }
  }
  return uVar3;
}



===== FsePortTrackerSetPartitionData @ 140016554 =====

undefined8 FsePortTrackerSetPartitionData(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_2,param_1);
  }
  puVar1 = FsePartitionFindById(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                    &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_1);
    }
    uVar2 = 0xc0000034;
  }
  else {
    puVar1[6] = param_2;
    FsePortPoolSetCacheDirty(g_TcpPool);
    FsePortPoolSetCacheDirty(g_UdpPool);
    uVar2 = 0;
  }
  return uVar2;
}



===== FsePortTrackerValidateAcquisitionParameters @ 140016604 =====

undefined8
FsePortTrackerValidateAcquisitionParameters(uint *param_1,char param_2,uint param_3,ushort *param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  
  if ((param_3 & 0xfffffffc) == 0) {
    if (param_2 == '\0') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      uVar5 = 0x18;
      param_3 = 0;
    }
    else {
      param_3 = param_1[8];
      if ((param_3 & 0xffffffc0) == 0) {
        param_3 = *param_1;
        if (((((param_3 == 1) || (param_3 == 2)) || (param_3 == 4)) ||
            ((param_3 == 8 || (param_3 == 0x10)))) || (param_3 == 0x20)) {
          param_3 = param_1[7];
          uVar6 = (ulonglong)param_3;
          if ((param_3 == 0) || (param_3 == 1)) {
            uVar2 = (ushort)param_1[6];
            if ((uVar2 == 0) || (*(ushort *)((longlong)param_1 + 0x1a) < uVar2)) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return 0xc000000d;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                return 0xc000000d;
              }
              uVar1 = (undefined1)*(undefined2 *)((longlong)param_1 + 0x1a);
              uVar5 = 0x1c;
            }
            else {
              if (param_4 == (ushort *)0x0) {
                return 0;
              }
              uVar2 = *param_4;
              if (uVar2 != 0) {
                uVar3 = param_4[1];
                if (uVar2 <= uVar3) {
                  uVar4 = param_4[2];
                  if ((uVar4 < uVar2) || (uVar3 < uVar4)) {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return 0xc000000d;
                    }
                    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                      return 0xc000000d;
                    }
                    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar2,
                               (ulonglong)uVar3,(uint)uVar4,(char)uVar2,(char)uVar3);
                    return 0xc000000d;
                  }
                  uVar4 = *(ushort *)((longlong)param_1 + 0x1a);
                  if ((ushort)((uVar4 - (ushort)param_1[6]) + 1) <= (ushort)((uVar3 - uVar2) + 1)) {
                    return 0;
                  }
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                    return 0xc000000d;
                  }
                  if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                    return 0xc000000d;
                  }
                  WPP_SF_DDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar2,
                              (ulonglong)uVar4,(uint)(ushort)param_1[6],(char)uVar4,(char)uVar2,
                              (char)uVar3);
                  return 0xc000000d;
                }
              }
              uVar6 = 2;
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return 0xc000000d;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                return 0xc000000d;
              }
              uVar1 = (undefined1)param_4[1];
              uVar5 = 0x1d;
            }
            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,uVar6,(uint)uVar2,uVar1);
            return 0xc000000d;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0xc000000d;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return 0xc000000d;
          }
          uVar5 = 0x1b;
        }
        else {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0xc000000d;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return 0xc000000d;
          }
          uVar5 = 0x1a;
        }
      }
      else {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000000d;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc000000d;
        }
        uVar5 = 0x19;
      }
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    uVar5 = 0x17;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_3);
  return 0xc000000d;
}



===== WPP_SF_DD @ 14001689c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 1400168f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,0x1e,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_DDDD @ 140016958 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,0x1f,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_DDDDDDD_guid__guid_ @ 1400169c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDDDDD_guid__guid_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined8 param_11,undefined8 param_12)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,0x20,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,param_11,0x10,
             param_12,0x10,0);
  return;
}



===== WPP_SF__guid_D @ 140016a88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_D(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,0x16,param_4,0x10,
             &param_5,4,0);
  return;
}



===== WPP_SF__guid_DD @ 140016adc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,0x10,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF__guid_DDDD @ 140016b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_DDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_18 [6];
  
  local_18[0] = 4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,0x31,param_4,0x10,
             local_18,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF__guid_i @ 140016bc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_i(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,0x25,param_4,0x10,
             &param_5,8,0);
  return;
}



===== WPP_SF_q_guid_ @ 140016c18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q_guid_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80a53128cc9a392a0e219317779e5bd2_Traceguids,0x2b,&local_res20,8,
             param_5,0x10,0);
  return;
}



===== FsePortPoolAddAllowedReservations @ 140016c80 =====

undefined8 FsePortPoolAddAllowedReservations(uint *param_1,longlong param_2)

{
  uint uVar1;
  longlong in_RAX;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint *puVar7;
  
  puVar7 = *(uint **)(param_1 + 4);
  uVar4 = 0;
  uVar1 = *(uint *)(param_2 + 0x44);
  uVar6 = 0;
  uVar2 = *puVar7;
  if (uVar2 != 0) {
    do {
      uVar5 = (uint)uVar6;
      in_RAX = uVar6 * 2;
      if (*(longlong *)(puVar7 + uVar6 * 4 + 2) == *(longlong *)(param_2 + 0x30)) {
        if (((puVar7[uVar6 * 4 + 4] & *(uint *)(param_2 + 0x40)) != 0) && (uVar5 < uVar2)) {
          uVar2 = 0;
          do {
            if (uVar2 != uVar5) {
              in_RAX = ((ulonglong)uVar2 + 1) * 2;
              puVar7[((ulonglong)uVar2 + 1) * 4] = puVar7[((ulonglong)uVar2 + 1) * 4] & uVar1;
            }
            puVar7 = *(uint **)(param_1 + 4);
            uVar2 = uVar2 + 1;
          } while (uVar2 < *puVar7);
          if (*(int *)(param_2 + 0x54) == 1) {
            in_RAX = *(longlong *)(param_2 + 0x30);
            uVar1 = param_1[1];
            uVar2 = *param_1;
            uVar5 = uVar1;
            if (uVar2 <= uVar1) {
              uVar5 = uVar2;
            }
            if (uVar5 != 0) {
              do {
                if (*(longlong *)(*(longlong *)(param_1 + 2) + uVar4 * 8) ==
                    *(longlong *)(in_RAX + 0x30)) goto LAB_140016d3b;
                uVar3 = (int)uVar4 + 1;
                uVar4 = (ulonglong)uVar3;
              } while (uVar3 < uVar5);
            }
            if (uVar1 < uVar2) {
              *(longlong *)(*(longlong *)(param_1 + 2) + (ulonglong)uVar1 * 8) =
                   *(longlong *)(in_RAX + 0x30);
            }
            param_1[1] = param_1[1] + 1;
          }
        }
        break;
      }
      uVar6 = (ulonglong)(uVar5 + 1);
    } while (uVar5 + 1 < uVar2);
  }
LAB_140016d3b:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== FsePortPoolAllocate @ 140016d54 =====

undefined8 FsePortPoolAllocate(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *param_1 = 0;
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x40,0x50657346);
  if (puVar1 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_25345b743fb235cde790eb9353532ee8_Traceguids);
    }
  }
  else {
    *(undefined8 *)(puVar1 + 0xe) = 0;
    puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x43657346);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0x43657346;
      *(undefined2 *)(puVar2 + 1) = 0;
      *(undefined8 *)(puVar2 + 2) = 0;
      *(undefined8 *)(puVar2 + 4) = 0;
      *(undefined8 *)(puVar2 + 6) = 0;
      *(undefined8 *)(puVar2 + 8) = 0;
      *(undefined4 **)(puVar1 + 0xe) = puVar2;
      puVar2 = puVar1 + 2;
      *puVar1 = 0x50657346;
      *(undefined4 **)(puVar1 + 4) = puVar2;
      *(undefined4 **)puVar2 = puVar2;
      puVar1[6] = 0;
      *(undefined8 *)(puVar1 + 8) = 0;
      *(undefined8 *)(puVar1 + 10) = 0;
      puVar1[0xc] = 0;
      *(undefined1 *)(puVar1 + 0xd) = 0;
      *param_1 = puVar1;
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_fcb5691f4a82371c55542fa3f3b1d979_Traceguids);
    }
    ExFreePoolWithTag(puVar1,0x50657346);
  }
  return 0xc0000017;
}



===== FsePortPoolCreateReservation2 @ 140016e98 =====

ulonglong FsePortPoolCreateReservation2
                    (longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,byte param_7,undefined4 *param_8,
                    byte param_9,int param_10,longlong *param_11)

{
  longlong *plVar1;
  longlong lVar2;
  uint *puVar3;
  undefined1 uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint uVar8;
  uint *local_res8;
  undefined8 in_stack_ffffffffffffffd0;
  
  local_res8 = (uint *)0x0;
  *param_11 = 0;
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x20);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  uVar6 = FsePortReservationAllocate
                    (param_2,param_3,param_4,param_5,param_6,
                     (ulonglong)param_7 << 0x38 | ~(lVar2 + 1U) & 0xffffffffffffff,param_8,
                     in_stack_ffffffffffffffd0,&local_res8);
  if ((int)uVar6 != 0) {
    return uVar6;
  }
  lVar2 = param_1 + 0x18;
  uVar4 = ExAcquireSpinLockExclusive(lVar2);
  puVar3 = local_res8;
  uVar7 = FsePortPoolInsertReservationInner(param_1,(longlong)local_res8,param_9,param_11);
  uVar5 = (uint)uVar7;
  if (uVar5 != 0) {
    uVar8 = 0;
    if (uVar5 != 0xff) {
      uVar8 = uVar5;
    }
    ExReleaseSpinLockExclusive(lVar2,uVar4);
    *puVar3 = *puVar3 | 0x80;
    ExFreePoolWithTag(puVar3,0x52657346);
    return (ulonglong)uVar8;
  }
  if (param_10 == 0) {
    if (((*(int *)(param_1 + 0x30) != 0) || (*(char *)(param_1 + 0x34) == '\0')) ||
       (uVar6 = FsePortCacheFastUpdateInsertReservation
                          (*(longlong *)(param_1 + 0x38),param_1,(longlong)puVar3),
       (char)uVar6 == '\0')) {
      FsePortPoolRebuildCacheUnderLock(param_1);
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x34) = 0;
  }
  ExReleaseSpinLockExclusive(lVar2,uVar4);
  *param_11 = (longlong)puVar3;
  return 0;
}



===== FsePortPoolDeleteAllReservationsByPartition @ 140017018 =====

void FsePortPoolDeleteAllReservationsByPartition(longlong param_1,longlong ***param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  longlong *****ppppplVar3;
  int iVar4;
  longlong *****ppppplVar5;
  longlong *****ppppplVar6;
  longlong *****local_18;
  longlong *****local_10;
  
  local_10 = (longlong *****)&local_18;
  local_18 = (longlong *****)&local_18;
  uVar2 = ExAcquireSpinLockExclusive(param_1 + 0x18);
  ppppplVar3 = (longlong *****)(param_1 + 8);
  ppppplVar5 = (longlong *****)*ppppplVar3;
  if (ppppplVar5 != ppppplVar3) {
    do {
      ppppplVar6 = (longlong *****)*ppppplVar5;
      if ((longlong ****)param_2 == ppppplVar5[4]) {
        FsePortPoolRemoveReservation(param_1,(longlong)(ppppplVar5 + -1));
        if ((longlong ******)*local_10 != &local_18) {
          pcVar1 = (code *)swi(0x29);
          (*pcVar1)(3);
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        ppppplVar5[1] = (longlong ****)local_10;
        *ppppplVar5 = (longlong ****)&local_18;
        *local_10 = (longlong ****)ppppplVar5;
        local_10 = ppppplVar5;
      }
      ppppplVar5 = ppppplVar6;
    } while (ppppplVar5 != ppppplVar3);
  }
  if ((longlong ******)local_18 != &local_18) {
    FsePortPoolRebuildCacheUnderLock(param_1);
  }
  ExReleaseSpinLockExclusive(param_1 + 0x18,uVar2);
  iVar4 = 0;
  ppppplVar3 = local_18;
  if ((longlong ******)local_18 != &local_18) {
    do {
      ppppplVar5 = (longlong *****)*ppppplVar3;
      ppppplVar3 = ppppplVar3 + -1;
      *(uint *)ppppplVar3 = *(uint *)ppppplVar3 | 0x80;
      ExFreePoolWithTag(ppppplVar3,0x52657346);
      iVar4 = iVar4 + 1;
      ppppplVar3 = ppppplVar5;
    } while ((longlong ******)ppppplVar5 != &local_18);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_25345b743fb235cde790eb9353532ee8_Traceguids,iVar4);
  }
  return;
}



===== FsePortPoolDeleteReservationByToken2 @ 140017160 =====

undefined8
FsePortPoolDeleteReservationByToken2(longlong param_1,longlong param_2,int param_3,longlong param_4)

{
  longlong lVar1;
  uint *puVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  
  lVar1 = param_1 + 0x18;
  uVar3 = ExAcquireSpinLockExclusive(lVar1);
  puVar4 = *(undefined8 **)(param_1 + 8);
  do {
    if (puVar4 == (undefined8 *)(param_1 + 8)) {
LAB_1400171c0:
      ExReleaseSpinLockExclusive(lVar1,uVar3);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_25345b743fb235cde790eb9353532ee8_Traceguids,param_4);
      }
      return 0xc0000465;
    }
    puVar2 = (uint *)(puVar4 + -1);
    if ((param_2 == puVar4[4]) && (param_4 == puVar4[6])) {
      if (puVar2 != (uint *)0x0) {
        FsePortPoolRemoveReservation(param_1,(longlong)puVar2);
        if (param_3 == 0) {
          FsePortPoolRebuildCacheUnderLock(param_1);
        }
        else {
          *(undefined1 *)(param_1 + 0x34) = 0;
        }
        ExReleaseSpinLockExclusive(lVar1,uVar3);
        *puVar2 = *puVar2 | 0x80;
        ExFreePoolWithTag(puVar2,0x52657346);
        return 0;
      }
      goto LAB_1400171c0;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== FsePortPoolEnumReservations @ 140017280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FsePortPoolEnumReservations(longlong param_1,undefined *param_2,undefined8 param_3)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 *puVar3;
  
  uVar1 = ExAcquireSpinLockShared(param_1 + 0x18);
  for (puVar3 = *(undefined8 **)(param_1 + 8); puVar3 != (undefined8 *)(param_1 + 8);
      puVar3 = (undefined8 *)*puVar3) {
    cVar2 = (*(code *)param_2)(param_3,puVar3 + -1);
    if (cVar2 == '\0') break;
  }
  ExReleaseSpinLockShared(param_1 + 0x18,uVar1);
  return;
}



===== FsePortPoolFindConflictingReservations @ 140017310 =====

longlong FsePortPoolFindConflictingReservations(ulonglong *param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = *(ulonglong *)(param_2 + 0x30);
  if ((*param_1 != uVar2) && (uVar2 = *(ulonglong *)(param_2 + 0x48), param_1[1] <= uVar2)) {
    uVar1 = *(uint *)(param_2 + 0x44);
    uVar2 = (ulonglong)uVar1;
    if (((uint)param_1[2] & uVar1) == 0) {
      *(undefined1 *)((longlong)param_1 + 0x14) = 0;
      return (ulonglong)(uint3)(uVar1 >> 8) << 8;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== FsePortPoolForEachReservationThatContainsPort @ 140017340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FsePortPoolForEachReservationThatContainsPort
               (longlong *param_1,uint param_2,undefined *param_3,undefined8 param_4)

{
  longlong *plVar1;
  undefined8 *puVar2;
  ushort uVar3;
  longlong lVar4;
  longlong *plVar5;
  uint *puVar6;
  code *pcVar7;
  char cVar8;
  uint uVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  uint uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar14 = auStack_38;
  puVar13 = auStack_38;
  plVar1 = param_1 + 1;
  lVar4 = *param_1;
  uVar12 = 0x10000;
  plVar10 = (longlong *)*plVar1;
  while (plVar10 != plVar1) {
    uVar3 = *(ushort *)((longlong)plVar10 + 0x3a);
    plVar5 = (longlong *)*plVar10;
    if (uVar3 < param_2) {
      if (((longlong *)plVar5[1] != plVar10) ||
         (puVar11 = (undefined8 *)plVar10[1], (longlong *)*puVar11 != plVar10)) goto LAB_14001742c;
      *puVar11 = plVar5;
      plVar5[1] = (longlong)puVar11;
      plVar10 = plVar5;
    }
    else {
      plVar10 = plVar5;
      if (uVar3 < uVar12) {
        uVar12 = uVar3 + 1;
      }
    }
  }
  for (puVar11 = (undefined8 *)param_1[3]; puVar11 != (undefined8 *)(lVar4 + 8);
      puVar11 = (undefined8 *)*puVar11) {
    if (param_2 < *(ushort *)(puVar11 + 9)) goto LAB_1400173d9;
    if (param_2 <= *(ushort *)((longlong)puVar11 + 0x4a)) break;
  }
  do {
    if (puVar11 == (undefined8 *)(lVar4 + 8)) goto LAB_14001743a;
LAB_1400173d9:
    uVar9 = (uint)*(ushort *)(puVar11 + 9);
    if (param_2 < *(ushort *)(puVar11 + 9)) goto LAB_140017433;
    plVar10 = (longlong *)*plVar1;
    uVar9 = *(ushort *)((longlong)puVar11 + 0x4a) + 1;
    if (uVar12 <= *(ushort *)((longlong)puVar11 + 0x4a)) {
      uVar9 = uVar12;
    }
    uVar12 = uVar9;
    for (; (plVar10 != plVar1 && ((ulonglong)puVar11[8] <= (ulonglong)plVar10[6]));
        plVar10 = (longlong *)*plVar10) {
    }
    plVar5 = (longlong *)plVar10[1];
    puVar2 = puVar11 + 2;
    if ((longlong *)*plVar5 != plVar10) break;
    *puVar2 = plVar10;
    puVar11[3] = plVar5;
    *plVar5 = (longlong)puVar2;
    plVar10[1] = (longlong)puVar2;
    puVar11 = (undefined8 *)*puVar11;
  } while( true );
LAB_14001742c:
  puVar11 = (undefined8 *)0x3;
  pcVar7 = (code *)swi(0x29);
  uVar9 = (*pcVar7)();
  puVar13 = auStack_30;
LAB_140017433:
  if (uVar12 <= uVar9) {
    uVar9 = uVar12;
  }
  uVar12 = uVar9;
  puVar14 = puVar13;
LAB_14001743a:
  plVar10 = (longlong *)*plVar1;
  puVar6 = *(uint **)(puVar14 + 0x60);
  param_1[3] = (longlong)puVar11;
  do {
    if (plVar10 == plVar1) {
      if (puVar6 != (uint *)0x0) {
        *puVar6 = uVar12;
      }
      return;
    }
    uVar9 = *(ushort *)((longlong)plVar10 + 0x3a) + 1;
    if (uVar12 <= *(ushort *)((longlong)plVar10 + 0x3a)) {
      uVar9 = uVar12;
    }
    uVar12 = uVar9;
    if ((code *)param_3 != (code *)0x0) {
      *(undefined8 *)(puVar14 + -8) = 0x14001746a;
      cVar8 = (*(code *)param_3)(param_4);
      if ((cVar8 == '\0') && (param_3 = (code *)0x0, puVar6 == (uint *)0x0)) {
        return;
      }
    }
    plVar10 = (longlong *)*plVar10;
  } while( true );
}



===== FsePortPoolFree @ 1400174a4 =====

void FsePortPoolFree(uint *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  uint *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar5 = auStack_28;
  do {
    puVar4 = *(uint **)(param_1 + 2);
    if (puVar4 == param_1 + 2) {
LAB_1400174f8:
      puVar4 = *(uint **)(param_1 + 0xe);
      *(undefined8 *)(puVar5 + -8) = 0x140017505;
      FseExpandableBufferFree((longlong)(puVar4 + 2));
      *(undefined8 *)(puVar5 + -8) = 0x14001750e;
      FseExpandableBufferFree((longlong)(puVar4 + 6));
      *puVar4 = *puVar4 | 0x80;
      *(undefined8 *)(puVar5 + -8) = 0x140017521;
      ExFreePoolWithTag(puVar4,0x43657346);
      *param_1 = *param_1 | 0x80;
      *(undefined8 *)(puVar5 + -8) = 0x140017539;
      ExFreePoolWithTag(param_1,0x50657346);
      return;
    }
    lVar1 = *(longlong *)puVar4;
    if ((*(uint **)(lVar1 + 8) != puVar4) ||
       (plVar2 = *(longlong **)(puVar4 + 2), (uint *)*plVar2 != puVar4)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar5 = auStack_20;
      goto LAB_1400174f8;
    }
    *plVar2 = lVar1;
    puVar4 = puVar4 + -2;
    *(longlong **)(lVar1 + 8) = plVar2;
    *puVar4 = *puVar4 | 0x80;
    ExFreePoolWithTag(puVar4,0x52657346);
  } while( true );
}



===== FsePortPoolGetPartitionsForPort @ 140017550 =====

void FsePortPoolGetPartitionsForPort
               (longlong param_1,ushort param_2,uint param_3,uint *param_4,void *param_5)

{
  undefined1 uVar1;
  longlong local_38;
  undefined8 ****local_30;
  undefined8 ****local_28;
  undefined8 local_20;
  
  uVar1 = ExAcquireSpinLockShared(param_1 + 0x18);
  if (*(char *)(param_1 + 0x34) == '\0') {
    local_28 = &local_30;
    local_30 = &local_30;
    local_20 = *(undefined8 *)(param_1 + 8);
    local_38 = param_1;
    FsePortPoolGetPartitionsForPortUncached(&local_38,(uint)param_2,param_3,param_4,param_5);
  }
  else {
    FsePortCacheGetPartitionsForPort(*(longlong *)(param_1 + 0x38),param_2,param_3,param_4,param_5);
  }
  ExReleaseSpinLockShared(param_1 + 0x18,uVar1);
  return;
}



===== FsePortPoolGetPartitionsForPortUncached @ 140017624 =====

void FsePortPoolGetPartitionsForPortUncached
               (longlong *param_1,uint param_2,undefined4 param_3,undefined4 *param_4,
               undefined8 param_5)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  uint *local_18;
  
  local_24 = 0;
  local_20 = param_5;
  local_28 = param_3;
  ExAcquireSpinLockExclusiveAtDpcLevel(&DAT_14002a6a0);
  puVar1 = DAT_14002a6a8;
  local_18 = DAT_14002a6a8;
  uVar3 = 0;
  if (*DAT_14002a6a8 != 0) {
    do {
      uVar2 = (int)uVar3 + 1;
      puVar1[(uVar3 + 1) * 4] = 0x3f;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *puVar1);
  }
  FsePortPoolForEachReservationThatContainsPort
            (param_1,param_2 & 0xffff,FsePortPoolAddAllowedReservations,&local_28);
  *param_4 = local_24;
  ExReleaseSpinLockExclusiveFromDpcLevel(&DAT_14002a6a0);
  return;
}



===== FsePortPoolGetSuggestedFreePort @ 1400176f0 =====

uint FsePortPoolGetSuggestedFreePort
               (longlong param_1,undefined8 param_2,undefined4 param_3,byte param_4,uint param_5,
               ushort param_6,ushort *param_7)

{
  undefined1 uVar1;
  uint uVar2;
  ushort local_res8;
  ushort local_resa;
  
  uVar1 = ExAcquireSpinLockShared(param_1 + 0x18);
  local_res8 = param_6;
  local_resa = param_7[1];
  uVar2 = FsePortPoolGetSuggestedFreePortUncached
                    (param_1,param_2,param_3,param_4,param_5,&local_res8);
  if ((short)uVar2 == 0) {
    local_resa = param_6;
    local_res8 = *param_7;
    uVar2 = FsePortPoolGetSuggestedFreePortUncached
                      (param_1,param_2,param_3,param_4,param_5,&local_res8);
  }
  ExReleaseSpinLockShared(param_1 + 0x18,uVar1);
  return uVar2 & 0xffff;
}



===== FsePortPoolGetSuggestedFreePortUncached @ 1400177f8 =====

uint FsePortPoolGetSuggestedFreePortUncached
               (longlong param_1,undefined8 param_2,undefined4 param_3,byte param_4,uint param_5,
               ushort *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_res20;
  undefined8 local_58;
  longlong local_50;
  undefined4 local_48;
  char local_44;
  undefined2 local_43;
  undefined1 local_41;
  longlong local_40;
  undefined8 *******local_38;
  undefined8 *******local_30;
  undefined8 local_28;
  
  uVar3 = 0;
  local_50 = (ulonglong)param_4 << 0x38;
  uVar4 = 0;
  local_30 = &local_38;
  local_38 = &local_38;
  local_28 = *(undefined8 *)(param_1 + 8);
  local_43 = 0;
  local_41 = 0;
  uVar2 = (uint)*param_6;
  local_58 = param_2;
  local_48 = param_3;
  local_40 = param_1;
  if (param_6[1] < *param_6) {
    return 0;
  }
  do {
    local_res20 = 0;
    local_44 = '\x01';
    FsePortPoolForEachReservationThatContainsPort
              (&local_40,uVar2,FsePortPoolFindConflictingReservations,&local_58);
    if (local_44 == '\0') {
      uVar3 = 0;
      uVar4 = 0;
    }
    else {
      uVar1 = uVar2;
      if (uVar4 != 0) {
        uVar1 = uVar4;
      }
      uVar4 = uVar1;
      uVar3 = uVar3 - uVar2;
      if (param_5 <= uVar3) {
        return uVar4;
      }
    }
    uVar2 = local_res20;
  } while( true );
}



===== FsePortPoolInsertReservationInner @ 1400178f0 =====

undefined8
FsePortPoolInsertReservationInner(longlong param_1,longlong param_2,byte param_3,longlong *param_4)

{
  longlong *plVar1;
  undefined8 *puVar2;
  ushort uVar3;
  ushort uVar4;
  ulonglong uVar5;
  code *pcVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  longlong *unaff_RBX;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  
  *param_4 = 0;
  plVar1 = (longlong *)(param_1 + 8);
  plVar13 = (longlong *)*plVar1;
  uVar5 = *(ulonglong *)(param_2 + 0x48);
  if (plVar13 != plVar1) {
    uVar3 = *(ushort *)(param_2 + 0x50);
    do {
      unaff_RBX = plVar13 + -1;
      uVar4 = *(ushort *)(plVar13 + 9);
      if (uVar3 < uVar4) break;
      if (((((((param_3 & 2) != 0) && (uVar3 == uVar4)) &&
            (*(short *)(param_2 + 0x52) == *(short *)((longlong)plVar13 + 0x4a))) &&
           ((((plVar13[8] ^ uVar5) & 0xff00000000000000) == 0 &&
            (*(int *)(param_2 + 0x40) == (int)plVar13[7])))) &&
          ((*(int *)(param_2 + 0x54) == *(int *)((longlong)plVar13 + 0x4c) &&
           ((*(int *)(param_2 + 0x44) == *(int *)((longlong)plVar13 + 0x3c) &&
            (*(longlong *)(param_2 + 0x28) == plVar13[4])))))) &&
         (*(longlong *)(param_2 + 0x30) == plVar13[5])) goto LAB_140017a61;
      plVar12 = plVar13;
      if ((ulonglong)plVar13[8] < uVar5) {
        if (uVar3 <= uVar4) break;
      }
      else if (((param_3 & 1) == 0) &&
              (uVar8 = FsePortReservationsHaveConflict(param_2,(longlong)unaff_RBX),
              (char)uVar8 != '\0')) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000708;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          return 0xc0000708;
        }
        lVar11 = plVar13[6];
        uVar10 = 0xc;
        goto LAB_140017a8d;
      }
      plVar13 = (longlong *)*plVar12;
    } while (plVar13 != plVar1);
  }
  if (((param_3 & 1) == 0) && (unaff_RBX = plVar13, plVar13 != plVar1)) {
    uVar3 = *(ushort *)(param_2 + 0x52);
    do {
      if (uVar3 < *(ushort *)(unaff_RBX + 9)) break;
      if ((uVar5 <= (ulonglong)unaff_RBX[8]) &&
         (uVar8 = FsePortReservationsHaveConflict(param_2,(longlong)(unaff_RBX + -1)),
         (char)uVar8 != '\0')) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          lVar11 = unaff_RBX[6];
          uVar10 = 0xb;
LAB_140017a8d:
          WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                   &WPP_25345b743fb235cde790eb9353532ee8_Traceguids,lVar11);
        }
        return 0xc0000708;
      }
      unaff_RBX = (longlong *)*unaff_RBX;
    } while (unaff_RBX != plVar1);
  }
  uVar7 = *(int *)(param_1 + 0x28) + 1;
  *(uint *)(param_1 + 0x28) = uVar7;
  if (*(uint *)(param_1 + 0x2c) < uVar7) {
    *(uint *)(param_1 + 0x2c) = uVar7;
  }
  plVar1 = (longlong *)plVar13[1];
  puVar2 = (undefined8 *)(param_2 + 8);
  if ((longlong *)*plVar1 == plVar13) {
    *puVar2 = plVar13;
    *(longlong **)(param_2 + 0x10) = plVar1;
    *plVar1 = (longlong)puVar2;
    plVar13[1] = (longlong)puVar2;
    uVar9 = 0;
  }
  else {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
LAB_140017a61:
    *param_4 = (longlong)unaff_RBX;
    uVar9 = 0xff;
  }
  return uVar9;
}



===== FsePortPoolQueryDiagnosticStatistics @ 140017ad8 =====

void FsePortPoolQueryDiagnosticStatistics
               (longlong param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = ExAcquireSpinLockShared(param_1 + 0x18);
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  *param_3 = *(undefined4 *)(param_1 + 0x2c);
  iVar2 = *(int *)(*(longlong *)(param_1 + 0x38) + 0x1c) +
          *(int *)(*(longlong *)(param_1 + 0x38) + 0xc);
  *param_4 = iVar2;
  ExReleaseSpinLockShared(param_1 + 0x18,CONCAT31((int3)((uint)iVar2 >> 8),uVar1));
  return;
}



===== FsePortPoolRebuildCacheUnderLock @ 140017b60 =====

void FsePortPoolRebuildCacheUnderLock(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  byte bVar4;
  
  if ((*(int *)(param_1 + 0x30) == 0) && (*(char *)(param_1 + 0x34) == '\0')) {
    lVar1 = *(longlong *)(param_1 + 0x38);
    if (*(int *)(lVar1 + 8) == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      uVar3 = FsePortCacheRebuild2(lVar1,param_1);
      iVar2 = (int)uVar3;
      if (iVar2 != 0) {
        FseExpandableBufferFree(lVar1 + 8);
        FseExpandableBufferFree(lVar1 + 0x18);
      }
    }
    bVar4 = (byte)((uint)iVar2 >> 0x1f) ^ 1;
  }
  else {
    bVar4 = 0;
  }
  *(byte *)(param_1 + 0x34) = bVar4;
  return;
}



===== FsePortPoolRemoveReservation @ 140017be0 =====

void FsePortPoolRemoveReservation(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_2 + 8);
  if (((*(ushort *)(param_2 + 0x50) <= g_FseDebugPort) &&
      (g_FseDebugPort <= *(ushort *)(param_2 + 0x52))) && (g_FseDebugPort != 0)) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0x10), (longlong *)*plVar3 == plVar1)) {
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



===== FsePortPoolSetCacheDirty @ 140017c30 =====

void FsePortPoolSetCacheDirty(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = ExAcquireSpinLockExclusive(param_1 + 0x18);
  FsePortPoolRebuildCacheUnderLock(param_1);
  ExReleaseSpinLockExclusive(param_1 + 0x18,uVar1);
  return;
}



===== FsePortPoolSetOptions @ 140017c88 =====

void FsePortPoolSetOptions(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  uVar2 = ExAcquireSpinLockExclusive(param_1 + 0x18);
  lVar1 = *(longlong *)(param_1 + 0x38);
  *(undefined4 *)(lVar1 + 8) = 0x19000;
  *(undefined4 *)(lVar1 + 0x18) = 0x19000;
  FsePortPoolRebuildCacheUnderLock(param_1);
  ExReleaseSpinLockExclusive(param_1 + 0x18,uVar2);
  return;
}



===== FsePartitionAllocate @ 140017cec =====

undefined8 FsePartitionAllocate(longlong *param_1,undefined8 *param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint *_Dst;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined2 uVar13;
  undefined1 *puVar14;
  undefined8 *puVar15;
  uint uVar16;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  *param_2 = 0;
  puVar9 = (undefined4 *)ExAllocatePool2(0x40,0x40,0x56657346);
  if (puVar9 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar13 = 10;
LAB_140017e50:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
              &WPP_dbd67b98d69b38ea1b5e73b74084d343_Traceguids);
    }
LAB_140017e60:
    uVar10 = 0xc0000017;
  }
  else {
    *puVar9 = 0x56657346;
    lVar5 = *param_1;
    uVar3 = *(undefined4 *)((longlong)param_1 + 4);
    lVar6 = param_1[1];
    uVar4 = *(undefined4 *)((longlong)param_1 + 0xc);
    *(undefined8 *)(puVar9 + 0xc) = 0;
    *(undefined8 *)(puVar9 + 10) = 0;
    puVar9[6] = (int)lVar5;
    puVar9[7] = uVar3;
    puVar9[8] = (int)lVar6;
    puVar9[9] = uVar4;
    *(undefined1 *)(puVar9 + 0xe) = 1;
    uVar7 = ExAcquireSpinLockExclusive(&DAT_14002a6a0);
    for (puVar11 = DAT_14002a610; (undefined8 **)puVar11 != &DAT_14002a610;
        puVar11 = (undefined8 *)*puVar11) {
      if ((puVar11[2] == *param_1) && (puVar11[3] == param_1[1])) {
        if (puVar11 != (undefined8 *)0x8) {
          ExReleaseSpinLockExclusive(&DAT_14002a6a0,uVar7);
          ExFreePoolWithTag(puVar9,0x56657346);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                          &WPP_dbd67b98d69b38ea1b5e73b74084d343_Traceguids,param_1);
          }
          return 0xc000022a;
        }
        break;
      }
    }
    uVar1 = *DAT_14002a6a8;
    uVar16 = uVar1 + 1;
    _Dst = DAT_14002a6a8;
    if (DAT_14002a6a8[1] < uVar16) {
      uVar8 = uVar16 * 0x10 + 8;
      _Dst = (uint *)ExAllocatePool2(0x40,uVar8,0x57657346);
      if (_Dst == (uint *)0x0) {
        ExReleaseSpinLockExclusive(&DAT_14002a6a0,uVar7);
        ExFreePoolWithTag(puVar9,0x56657346);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar13 = 0xc;
          goto LAB_140017e50;
        }
        goto LAB_140017e60;
      }
      memmove(_Dst,DAT_14002a6a8,(ulonglong)uVar8 - 0x10);
      ExFreePoolWithTag(DAT_14002a6a8,0x57657346);
      DAT_14002a6a8 = _Dst;
      _Dst[1] = uVar16;
    }
    puVar14 = auStack_38;
    puVar15 = &DAT_14002a610;
    *_Dst = *_Dst + 1;
    *(undefined4 **)(_Dst + (ulonglong)uVar1 * 4 + 2) = puVar9;
    puVar11 = (undefined8 *)(puVar9 + 2);
    puVar12 = DAT_14002a618;
    if ((undefined8 **)*DAT_14002a618 != &DAT_14002a610) {
      puVar12 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      puVar11 = (undefined8 *)(*pcVar2)();
      puVar14 = auStack_30;
    }
    puVar11[1] = puVar12;
    *puVar11 = puVar15;
    *puVar12 = puVar11;
    *(undefined8 *)(puVar14 + -8) = 0x140017f58;
    DAT_14002a618 = puVar11;
    ExReleaseSpinLockExclusive(&DAT_14002a6a0,uVar7);
    uVar10 = 0;
    *param_2 = puVar9;
  }
  return uVar10;
}



===== FsePartitionFindById @ 140017f8c =====

undefined8 * FsePartitionFindById(longlong *param_1)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  uVar1 = ExAcquireSpinLockShared(&DAT_14002a6a0);
  for (puVar2 = DAT_14002a610; (undefined8 **)puVar2 != &DAT_14002a610;
      puVar2 = (undefined8 *)*puVar2) {
    puVar3 = puVar2 + -1;
    if ((puVar2[2] == *param_1) && (puVar2[3] == param_1[1])) goto LAB_140017fe0;
  }
  puVar3 = (undefined8 *)0x0;
LAB_140017fe0:
  ExReleaseSpinLockShared(&DAT_14002a6a0,uVar1);
  return puVar3;
}



===== FsePartitionFree @ 14001800c =====

void FsePartitionFree(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  uint *puVar7;
  undefined1 uVar8;
  uint uVar9;
  
  uVar8 = ExAcquireSpinLockExclusive(&DAT_14002a6a0);
  puVar7 = DAT_14002a6a8;
  puVar2 = param_1 + 2;
  lVar4 = *(longlong *)puVar2;
  if ((*(uint **)(lVar4 + 8) != puVar2) ||
     (plVar5 = *(longlong **)(param_1 + 4), (uint *)*plVar5 != puVar2)) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  uVar3 = *puVar7;
  uVar9 = 0;
  if (uVar3 != 0) {
    do {
      uVar1 = uVar9 + 1;
      if (*(uint **)(puVar7 + (ulonglong)uVar9 * 4 + 2) == param_1) {
        memmove(puVar7 + ((ulonglong)uVar9 * 2 + 1) * 2,puVar7 + (ulonglong)uVar1 * 4 + 2,
                (ulonglong)((uVar3 - uVar9) - 1) << 4);
        break;
      }
      uVar9 = uVar1;
    } while (uVar1 < uVar3);
  }
  *puVar7 = *puVar7 - 1;
  ExReleaseSpinLockExclusive(&DAT_14002a6a0,uVar8);
  *param_1 = *param_1 | 0x80;
  ExFreePoolWithTag(param_1,0x56657346);
  return;
}



===== FsePatchAllocate @ 1400180f4 =====

undefined8
FsePatchAllocate(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 param_5,undefined4 param_6,undefined8 *param_7)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  *param_7 = 0;
  puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x38,0x54657346);
  if (puVar3 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_0a4162c06d633298bdd78402b86e5e2f_Traceguids);
    }
    uVar4 = 0xc0000017;
  }
  else {
    *puVar3 = 0x54657346;
    *(undefined8 *)(puVar3 + 6) = param_1;
    puVar3[8] = 4;
    puVar3[9] = param_3;
    puVar3[10] = *param_4;
    puVar3[0xb] = param_5;
    puVar3[0xc] = param_6;
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_14002a630);
    puVar6 = auStack_28;
    puVar7 = &DAT_14002a620;
    puVar5 = (undefined8 *)(puVar3 + 2);
    if ((undefined8 *)*DAT_14002a628 != &DAT_14002a620) {
      puVar5 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      uVar2 = (*pcVar1)();
      puVar6 = auStack_20;
    }
    puVar5[1] = DAT_14002a628;
    *puVar5 = puVar7;
    *DAT_14002a628 = puVar5;
    *(undefined8 *)(puVar6 + -8) = 0x1400181f0;
    DAT_14002a628 = puVar5;
    KeReleaseSpinLock(&DAT_14002a630,uVar2);
    uVar4 = 0;
    *param_7 = puVar3;
  }
  return uVar4;
}



===== FsePatchModifyAcquisitionRequest @ 14001821c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FsePatchModifyAcquisitionRequest(uint *param_1,byte *param_2,uint *param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined8 *puVar8;
  undefined4 uVar9;
  undefined1 auStack_78 [32];
  undefined1 local_58;
  longlong local_50;
  longlong lStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_78;
  uVar9 = 0;
  local_58 = KeAcquireSpinLockRaiseToDpc(&DAT_14002a630);
  puVar8 = DAT_14002a620;
  if ((undefined8 **)DAT_14002a620 != &DAT_14002a620) {
    do {
      lVar5 = puVar8[2];
      if (lVar5 == 0) {
LAB_1400182b7:
        if (((*param_1 & *(uint *)(puVar8 + 3)) != 0) &&
           (*(uint *)((longlong)puVar8 + 0x1c) == param_1[5])) {
          uVar2 = *(ushort *)(puVar8 + 4);
          if (*(ushort *)(puVar8 + 4) <= (ushort)param_1[6]) {
            uVar2 = (ushort)param_1[6];
          }
          uVar6 = *(ushort *)((longlong)puVar8 + 0x22);
          if (*(ushort *)((longlong)param_1 + 0x1a) <= *(ushort *)((longlong)puVar8 + 0x22)) {
            uVar6 = *(ushort *)((longlong)param_1 + 0x1a);
          }
          if ((uVar2 <= uVar6) && ((ushort)(uVar6 - uVar2) != -1)) {
            iVar3 = *(int *)((longlong)puVar8 + 0x24);
            if (iVar3 == 0) {
              if (((param_1[7] != 0) &&
                  (param_1[7] = 0, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                        &WPP_0a4162c06d633298bdd78402b86e5e2f_Traceguids);
              }
            }
            else if (iVar3 == 1) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                         &WPP_0a4162c06d633298bdd78402b86e5e2f_Traceguids,
                         *(undefined4 *)(puVar8 + 5));
              }
              uVar9 = *(undefined4 *)(puVar8 + 5);
            }
            else if (iVar3 == 2) {
              uVar4 = *(uint *)(puVar8 + 5);
              if (((uVar4 != (uVar4 & param_1[8])) &&
                  (param_1[8] = uVar4 | param_1[8],
                  (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar7 = 0xd;
                goto LAB_140018377;
              }
            }
            else if (iVar3 == 3) {
              if ((((param_1[8] & *(uint *)(puVar8 + 5)) != 0) &&
                  (param_1[8] = ~*(uint *)(puVar8 + 5) & param_1[8],
                  (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar7 = 0xe;
                goto LAB_140018377;
              }
            }
            else if (iVar3 == 4) {
              uVar4 = *(uint *)(puVar8 + 5);
              if (((uVar4 != (uVar4 & *param_3)) &&
                  (*param_3 = uVar4 | *param_3,
                  (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar7 = 0xf;
                goto LAB_140018377;
              }
            }
            else if (iVar3 == 5) {
              if ((((*param_3 & *(uint *)(puVar8 + 5)) != 0) &&
                  (*param_3 = ~*(uint *)(puVar8 + 5) & *param_3,
                  (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar7 = 0x10;
                goto LAB_140018377;
              }
            }
            else if ((((iVar3 == 6) &&
                      (bVar1 = *(byte *)(puVar8 + 5), *param_2 = bVar1,
                      (uint)bVar1 != *(uint *)(puVar8 + 5))) &&
                     (*param_2 = *(byte *)(puVar8 + 5),
                     (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar7 = 0x11;
LAB_140018377:
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                       &WPP_0a4162c06d633298bdd78402b86e5e2f_Traceguids,*(undefined4 *)(puVar8 + 5))
              ;
            }
          }
        }
      }
      else {
        local_50 = *(longlong *)(lVar5 + 0x18);
        lStack_48 = *(longlong *)(lVar5 + 0x20);
        if ((local_50 == *(longlong *)(param_1 + 1)) && (lStack_48 == *(longlong *)(param_1 + 3)))
        goto LAB_1400182b7;
      }
      puVar8 = (undefined8 *)*puVar8;
    } while ((undefined8 **)puVar8 != &DAT_14002a620);
  }
  KeReleaseSpinLock(&DAT_14002a630,local_58);
  return uVar9;
}



===== FsePortReservationAllocate @ 140018508 =====

undefined8
FsePortReservationAllocate
          (longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined4 *param_7,undefined8 param_8,
          undefined8 *param_9)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  
  *param_9 = 0;
  puVar4 = (undefined4 *)ExAllocatePool2(0x40,0x58,0x52657346);
  if (puVar4 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_ccbffb92659a3c0c564b46c9e862410e_Traceguids);
    }
    uVar5 = 0xc0000017;
  }
  else {
    *puVar4 = 0x52657346;
    *(longlong *)(puVar4 + 10) = param_1;
    *(undefined8 *)(puVar4 + 0xc) = param_2;
    puVar4[0x10] = param_3;
    puVar4[0x11] = param_4;
    *(undefined8 *)(puVar4 + 0x12) = param_6;
    uVar3 = *param_7;
    puVar4[0x15] = param_5;
    puVar4[0x14] = uVar3;
    LOCK();
    plVar1 = (longlong *)(param_1 + 0x28);
    lVar2 = *plVar1;
    *plVar1 = *plVar1 + 1;
    UNLOCK();
    *param_9 = puVar4;
    *(longlong *)(puVar4 + 0xe) = lVar2 + 1;
    uVar5 = 0;
  }
  return uVar5;
}



===== FsePortReservationsHaveConflict @ 1400185f8 =====

ulonglong FsePortReservationsHaveConflict(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar4 = *(ushort *)(param_1 + 0x50);
  if (*(ushort *)(param_1 + 0x50) <= *(ushort *)(param_2 + 0x50)) {
    uVar4 = *(ushort *)(param_2 + 0x50);
  }
  uVar1 = *(ushort *)(param_2 + 0x52);
  uVar3 = (ulonglong)uVar1;
  uVar5 = *(ushort *)(param_1 + 0x52);
  if (uVar1 <= *(ushort *)(param_1 + 0x52)) {
    uVar5 = uVar1;
  }
  if (((uVar5 < uVar4) || (uVar3 = 0, (ushort)(uVar5 - uVar4) == -1)) ||
     (uVar3 = *(ulonglong *)(param_2 + 0x30), *(ulonglong *)(param_1 + 0x30) == uVar3)) {
    return uVar3 & 0xffffffffffffff00;
  }
  uVar2 = *(uint *)(param_1 + 0x44) & *(uint *)(param_2 + 0x40);
  if (uVar2 == *(uint *)(param_2 + 0x40)) {
    uVar2 = *(uint *)(param_2 + 0x44) & *(uint *)(param_1 + 0x40);
    return (ulonglong)CONCAT31((int3)(uVar2 >> 8),uVar2 != *(uint *)(param_1 + 0x40));
  }
  return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
}



===== FsePortCacheAddZone @ 140018668 =====

undefined8
FsePortCacheAddZone(longlong param_1,longlong *param_2,ushort param_3,undefined8 param_4,
                   uint param_5,uint *param_6)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  ushort *puVar4;
  uint *puVar5;
  undefined2 uVar6;
  uint *puVar7;
  uint uVar8;
  
  puVar4 = (ushort *)FseExpandableBufferGetData((uint *)(param_1 + 8),param_5 << 2,4,'\x01');
  puVar2 = param_6;
  if (puVar4 == (ushort *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000009a;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000009a;
    }
    uVar6 = 0xb;
  }
  else {
    param_5 = 0;
    puVar5 = (uint *)FseExpandableBufferGetData((uint *)(param_1 + 0x18),*param_6,0x10,'\x01');
    while (puVar5 != (uint *)0x0) {
      uVar8 = (*(int *)(param_1 + 0x1c) - *puVar2) - 8 >> 3;
      FsePortPoolGetPartitionsForPortUncached(param_2,(uint)param_3,uVar8,&param_5,puVar5 + 2);
      uVar1 = param_5;
      if (0xffff < param_5) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000009a;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc000009a;
        }
        uVar6 = 0xd;
        goto LAB_14001879a;
      }
      if (param_5 <= uVar8) {
        *puVar4 = param_3;
        qsort(puVar5 + 2,(ulonglong)param_5,8,FsePortCachePointerComparitor);
        *puVar5 = uVar1 & 0xffff;
        puVar7 = *(uint **)(param_1 + 0x20);
        while( true ) {
          if (puVar7 == puVar5) {
            puVar4[1] = (ushort)((uint)((int)puVar5 - *(int *)(param_1 + 0x20)) >> 3);
            *puVar2 = ((*puVar5 * 8 + 8) - *(int *)(param_1 + 0x20)) + (int)puVar5;
            return 0;
          }
          uVar8 = *puVar7;
          if ((uVar8 == (uVar1 & 0xffff)) &&
             (iVar3 = memcmp(puVar7 + 2,puVar5 + 2,(ulonglong)uVar8 * 8), iVar3 == 0)) break;
          puVar7 = puVar7 + (ulonglong)uVar8 * 2 + 2;
        }
        puVar4[1] = (ushort)((uint)((int)puVar7 - *(int *)(param_1 + 0x20)) >> 3);
        return 0;
      }
      puVar5 = (uint *)FseExpandableBufferGetData
                                 ((uint *)(param_1 + 0x18),*puVar2,param_5 * 8 + 0x10,'\x01');
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000009a;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000009a;
    }
    uVar6 = 0xc;
  }
LAB_14001879a:
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
          &WPP_fcb5691f4a82371c55542fa3f3b1d979_Traceguids);
  return 0xc000009a;
}



===== FsePortCacheFastUpdateInsertReservation @ 14001888c =====

ulonglong FsePortCacheFastUpdateInsertReservation
                    (longlong param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ulonglong in_RAX;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 extraout_var;
  longlong lVar6;
  int *piVar7;
  uint uVar8;
  ulonglong local_68 [2];
  undefined4 local_58;
  longlong local_50;
  undefined8 ******local_48;
  undefined8 ******local_40;
  undefined8 local_38;
  
  if ((1 < *(ushort *)(param_3 + 0x50)) && (in_RAX = 0xffff, *(short *)(param_3 + 0x52) != -1)) {
    in_RAX = 0;
    uVar8 = 1;
    if (1 < *(ushort *)(param_1 + 4)) {
      do {
        puVar4 = (ushort *)FseExpandableBufferGetData((uint *)(param_1 + 8),uVar8 * 4,4,'\x01');
        uVar1 = *puVar4;
        in_RAX = (ulonglong)uVar1;
        if (uVar1 == *(ushort *)(param_3 + 0x50)) {
          if (uVar8 + 1 < (uint)*(ushort *)(param_1 + 4)) {
            puVar5 = (ushort *)
                     FseExpandableBufferGetData((uint *)(param_1 + 8),uVar8 * 4 + 4,4,'\x01');
            in_RAX = (ulonglong)*puVar5;
            if ((uint)*puVar5 == *(ushort *)(param_3 + 0x52) + 1) break;
          }
          local_58 = 0;
          local_40 = &local_48;
          local_48 = &local_48;
          local_38 = *(undefined8 *)(param_2 + 8);
          local_68[0] = 0;
          local_68[1] = 0;
          local_50 = param_2;
          in_RAX = FsePortPoolGetPartitionsForPortUncached
                             (&local_50,(uint)*(ushort *)(param_3 + 0x50),4,(undefined4 *)local_68,
                              local_68 + 1);
          if (((uint)local_68[0] < 5) &&
             (uVar2 = *(ushort *)(param_3 + 0x52) + 1, in_RAX = (ulonglong)uVar2, uVar2 == 0)) {
            qsort(local_68 + 1,local_68[0] & 0xffffffff,8,FsePortCachePointerComparitor);
            in_RAX = FseExpandableBufferGetData((uint *)(param_1 + 8),uVar8 * 4 - 4,4,'\x01');
            lVar6 = (ulonglong)*(ushort *)(in_RAX + 2) * 8;
            if (*(uint *)(param_1 + 0x1c) < (uint)lVar6) {
              piVar7 = (int *)0x0;
            }
            else {
              piVar7 = (int *)(lVar6 + *(longlong *)(param_1 + 0x20));
            }
            if ((uint)local_68[0] == *piVar7) {
              iVar3 = memcmp(local_68 + 1,piVar7 + 2,(local_68[0] & 0xffffffff) << 3);
              in_RAX = CONCAT44(extraout_var,iVar3);
              if (iVar3 == 0) {
                *puVar4 = *(short *)(param_3 + 0x52) + 1;
                return CONCAT71((int7)(in_RAX >> 8),1);
              }
            }
          }
          break;
        }
        if (*(ushort *)(param_3 + 0x50) < uVar1) break;
        uVar8 = uVar8 + 1;
        in_RAX = 0;
      } while (uVar8 < *(ushort *)(param_1 + 4));
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== FsePortCacheGetPartitionsForPort @ 140018a68 =====

void FsePortCacheGetPartitionsForPort
               (longlong param_1,ushort param_2,uint param_3,uint *param_4,void *param_5)

{
  ushort *puVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 1;
  if (1 < *(ushort *)(param_1 + 4)) {
    do {
      puVar1 = (ushort *)FseExpandableBufferGetData((uint *)(param_1 + 8),uVar4 * 4,4,'\x01');
      if (param_2 < *puVar1) break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(ushort *)(param_1 + 4));
  }
  lVar2 = FseExpandableBufferGetData((uint *)(param_1 + 8),uVar4 * 4 - 4,4,'\x01');
  lVar2 = (ulonglong)*(ushort *)(lVar2 + 2) * 8;
  if (*(uint *)(param_1 + 0x1c) < (uint)lVar2) {
    puVar3 = (uint *)0x0;
  }
  else {
    puVar3 = (uint *)(lVar2 + *(longlong *)(param_1 + 0x20));
  }
  uVar4 = *puVar3;
  *param_4 = uVar4;
  if (uVar4 <= param_3) {
    memmove(param_5,puVar3 + 2,(ulonglong)uVar4 << 3);
  }
  return;
}



===== FsePortCachePointerComparitor @ 140018b40 =====

ulonglong FsePortCachePointerComparitor(ulonglong param_1,ulonglong param_2)

{
  if (param_1 < param_2) {
    return 0xffffffff;
  }
  return (ulonglong)(param_1 != param_2);
}



===== FsePortCacheRebuild2 @ 140018b5c =====

undefined8 FsePortCacheRebuild2(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  int local_res10 [2];
  uint local_res18 [4];
  longlong local_48;
  undefined8 ****local_40;
  undefined8 ****local_38;
  undefined8 local_30;
  
  local_res18[0] = 0;
  local_38 = &local_40;
  uVar4 = 0;
  local_40 = &local_40;
  local_30 = *(undefined8 *)(param_2 + 8);
  local_res10[0] = 0;
  uVar5 = 0;
  local_48 = param_2;
  do {
    uVar1 = FsePortCacheAddZone(param_1,&local_48,(ushort)local_res10[0],local_res10,uVar4,
                                local_res18);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    if (uVar4 == 0) {
LAB_140018bfa:
      uVar4 = uVar4 + 1;
      uVar5 = uVar5 + 4;
    }
    else {
      lVar2 = FseExpandableBufferGetData((uint *)(param_1 + 8),uVar5,4,'\x01');
      lVar3 = FseExpandableBufferGetData((uint *)(param_1 + 8),uVar5 - 4,4,'\x01');
      if (*(short *)(lVar2 + 2) != *(short *)(lVar3 + 2)) goto LAB_140018bfa;
    }
    if (local_res10[0] == 0x10000) {
      *(short *)(param_1 + 4) = (short)uVar4;
      return 0;
    }
  } while( true );
}



===== FseExpandableBufferFree @ 140018c2c =====

void FseExpandableBufferFree(longlong param_1)

{
  if (*(longlong *)(param_1 + 8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 8),0x42657346);
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



===== FseExpandableBufferGetData @ 140018c68 =====

longlong FseExpandableBufferGetData(uint *param_1,uint param_2,int param_3,char param_4)

{
  uint uVar1;
  void *_Dst;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_2 + param_3;
  if (param_1[1] < uVar3) {
    if ((param_4 != '\0') && (uVar4 = *param_1, uVar3 <= uVar4)) {
      uVar1 = param_1[1] * 2;
      if (uVar3 <= uVar1) {
        uVar3 = uVar1;
      }
      if (uVar3 < uVar4) {
        uVar4 = uVar3;
      }
      _Dst = (void *)ExAllocatePool2(0x40,uVar4,0x42657346);
      if (_Dst != (void *)0x0) {
        if (*(void **)(param_1 + 2) != (void *)0x0) {
          memmove(_Dst,*(void **)(param_1 + 2),(ulonglong)param_1[1]);
          ExFreePoolWithTag(*(undefined8 *)(param_1 + 2),0x42657346);
        }
        *(void **)(param_1 + 2) = _Dst;
        param_1[1] = uVar4;
        goto LAB_140018cfb;
      }
    }
    lVar2 = 0;
  }
  else {
LAB_140018cfb:
    lVar2 = (ulonglong)param_2 + *(longlong *)(param_1 + 2);
  }
  return lVar2;
}



===== Feature_3923932473__private_IsEnabledDeviceUsageNoInline @ 140018d24 =====

ulonglong Feature_3923932473__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_3923932473__private_featureState;
  if (((uint)Feature_3923932473__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3923932473__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_3923932473__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3923932473__private_IsEnabledFallback @ 140018d5c =====

void Feature_3923932473__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3923932473__private_descriptor);
  return;
}



===== FseCreateInitResponseMessage @ 140018d78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseCreateInitResponseMessage
              (int param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined8 *param_5,uint *param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  void *pvVar4;
  undefined1 auStackY_b8 [32];
  uint local_88;
  uint local_84;
  void *local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = 0;
  pvVar4 = (void *)0x0;
  local_88 = 0;
  local_84 = 0;
  local_80 = (void *)0x0;
  puVar3 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_(puVar3,0x1d,&WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids);
  }
  *param_5 = 0;
  if (param_1 == 1) {
    local_6c = 0;
    local_50 = 0;
    local_68 = 0;
    local_70 = 0x1101;
    local_60 = 0;
    uStack_58 = 0;
    local_64 = param_4;
    iVar1 = FseMidlObjectEncode((ulonglong)puVar3,&local_70,(longlong *)&local_80,&local_88);
    pvVar4 = local_80;
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                 &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
      }
      pvVar4 = local_80;
    }
    else {
      uVar2 = FseGetCompleteMessage(1,param_2,local_80,local_88,&local_78,&local_84);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                   &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
        }
      }
      else {
        *param_5 = local_78;
        *param_6 = local_84;
      }
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,0xc000000d);
  }
  if (pvVar4 != (void *)0x0) {
    ExFreePoolWithTag(pvVar4,0x6c4d7346);
  }
  return iVar1;
}



===== FseCreateInvalidVersionMessage @ 140018f50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseCreateInvalidVersionMessage
              (int param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined8 *param_5,uint *param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  void *pvVar4;
  undefined1 auStackY_b8 [32];
  uint local_88;
  uint local_84;
  void *local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = 0;
  pvVar4 = (void *)0x0;
  local_88 = 0;
  local_84 = 0;
  local_80 = (void *)0x0;
  puVar3 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_(puVar3,0x21,&WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids);
  }
  *param_5 = 0;
  if (param_1 == 1) {
    local_6c = 0;
    local_50 = 0;
    local_70 = 0x1001;
    local_68 = 0xc00000bb;
    local_60 = 0;
    uStack_58 = 0;
    local_64 = param_4;
    iVar1 = FseMidlObjectEncode((ulonglong)puVar3,&local_70,(longlong *)&local_80,&local_88);
    pvVar4 = local_80;
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
      }
      pvVar4 = local_80;
    }
    else {
      uVar2 = FseGetCompleteMessage(1,param_2,local_80,local_88,&local_78,&local_84);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                   &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
        }
      }
      else {
        *param_5 = local_78;
        *param_6 = local_84;
      }
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
             &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,0xc000000d);
  }
  if (pvVar4 != (void *)0x0) {
    ExFreePoolWithTag(pvVar4,0x6c4d7346);
  }
  return iVar1;
}



===== FseCreatePortReleaseResponseMessage @ 14001912c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseCreatePortReleaseResponseMessage
              (int param_1,undefined8 param_2,uint param_3,undefined8 *param_4,uint *param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  void *pvVar4;
  undefined1 auStackY_b8 [32];
  uint local_88;
  uint local_84;
  void *local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = 0;
  pvVar4 = (void *)0x0;
  local_88 = 0;
  local_84 = 0;
  local_80 = (void *)0x0;
  puVar3 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_(puVar3,0x19,&WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids);
  }
  *param_4 = 0;
  if (param_1 == 1) {
    local_70 = 0x2003;
    uStack_68 = (ulonglong)param_3;
    local_50 = 0;
    local_60 = 0;
    uStack_58 = 0;
    iVar1 = FseMidlObjectEncode((ulonglong)puVar3,&local_70,(longlong *)&local_80,&local_88);
    pvVar4 = local_80;
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                 &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
      }
      pvVar4 = local_80;
    }
    else {
      uVar2 = FseGetCompleteMessage(1,param_2,local_80,local_88,&local_78,&local_84);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                   &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
        }
      }
      else {
        *param_4 = local_78;
        *param_5 = local_84;
      }
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,0xc000000d);
  }
  if (pvVar4 != (void *)0x0) {
    ExFreePoolWithTag(pvVar4,0x6c4d7346);
  }
  return iVar1;
}



===== FseCreatePortReserveResponseMessage @ 140019300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseCreatePortReserveResponseMessage
              (ulonglong param_1,undefined8 param_2,uint param_3,undefined8 param_4,ushort param_5,
              undefined8 *param_6,uint *param_7)

{
  int iVar1;
  undefined8 uVar2;
  void *pvVar3;
  undefined1 auStackY_b8 [32];
  uint local_88;
  uint local_84;
  void *local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  pvVar3 = (void *)0x0;
  local_78 = 0;
  local_88 = 0;
  local_84 = 0;
  *param_6 = 0;
  local_80 = (void *)0x0;
  if ((int)param_1 == 1) {
    local_50 = 0;
    uStack_68 = (ulonglong)param_3;
    uStack_58 = (ulonglong)param_5;
    local_70 = 0x2001;
    local_60 = param_4;
    iVar1 = FseMidlObjectEncode(param_1,&local_70,(longlong *)&local_80,&local_88);
    pvVar3 = local_80;
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                 &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
      }
      pvVar3 = local_80;
    }
    else {
      uVar2 = FseGetCompleteMessage(1,param_2,local_80,local_88,&local_78,&local_84);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                   &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
        }
      }
      else {
        *param_6 = local_78;
        *param_7 = local_84;
      }
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,0xc000000d);
  }
  if (pvVar3 != (void *)0x0) {
    ExFreePoolWithTag(pvVar3,0x6c4d7346);
  }
  return iVar1;
}



===== FseGetCompleteMessage @ 1400194ac =====

undefined8
FseGetCompleteMessage
          (uint param_1,undefined8 param_2,void *param_3,uint param_4,undefined8 *param_5,
          uint *param_6)

{
  uint *_Dst;
  undefined8 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  *param_5 = 0;
  *param_6 = 0;
  uVar2 = param_4 + 0x20;
  _Dst = (uint *)ExAllocatePool2(0x40,uVar2,0x744d7346);
  if (_Dst == (uint *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    memset(_Dst,0,(ulonglong)uVar2);
    _Dst[1] = param_1;
    *(undefined8 *)(_Dst + 2) = param_2;
    *_Dst = uVar2;
    memmove(_Dst + 8,param_3,(ulonglong)param_4);
    *param_5 = _Dst;
    *param_6 = uVar2;
  }
  return uVar1;
}



===== FseMidlObjectDecode @ 140019568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140019702) */
/* WARNING: Removing unreachable block (ram,0x000140019713) */
/* WARNING: Removing unreachable block (ram,0x000140019719) */

undefined8 FseMidlObjectDecode(undefined *param_1,void *param_2,uint param_3,longlong *param_4)

{
  bool bVar1;
  int iVar2;
  void *_Dst;
  undefined8 uVar3;
  longlong local_50;
  void *local_48;
  longlong local_40;
  
  uVar3 = 0;
  local_40 = 0;
  local_50 = 0;
  bVar1 = false;
  *param_4 = 0;
  if (((ulonglong)param_2 & 7) == 0) {
    _Dst = param_2;
    local_48 = param_2;
    bVar1 = false;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
              &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids);
    }
    _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)param_3,0x6c4d7346);
    local_48 = _Dst;
    if (_Dst == (void *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids);
      }
      uVar3 = 0xc0000017;
      goto LAB_14001975c;
    }
    bVar1 = true;
    memmove(_Dst,param_2,(ulonglong)param_3);
  }
  iVar2 = MesDecodeBufferHandleCreate(_Dst,param_3,&local_50);
  if (iVar2 == 0) {
    (*(code *)param_1)(local_50,&local_40);
    if (local_40 == 0) {
      uVar3 = 0xc0000017;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids);
      }
    }
    else {
      *param_4 = local_40;
    }
  }
  else {
    uVar3 = 0xc0000001;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar3 = 0xc0000001;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
               &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar2);
    }
  }
LAB_14001975c:
  if (local_50 != 0) {
    MesHandleFree();
  }
  if (bVar1) {
    ExFreePoolWithTag(_Dst,0x6c4d7346);
  }
  return uVar3;
}



===== FseMidlObjectEncode @ 1400197a4 =====

/* WARNING: Removing unreachable block (ram,0x000140019893) */
/* WARNING: Removing unreachable block (ram,0x0001400198ab) */
/* WARNING: Removing unreachable block (ram,0x0001400198b1) */

int FseMidlObjectEncode(ulonglong param_1,undefined8 param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined **ppuVar4;
  ulonglong local_res8;
  undefined8 local_res10;
  longlong *local_res18;
  undefined4 *local_res20;
  ulonglong in_stack_ffffffffffffffa8;
  undefined4 uVar5;
  longlong local_40;
  longlong local_38 [3];
  
  iVar3 = 0;
  uVar5 = 0;
  local_40 = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  local_38[0] = 0;
  *param_3 = 0;
  *param_4 = 0;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  iVar1 = MesEncodeDynBufferHandleCreate(&local_40,&local_res8,local_38);
  if (iVar1 == 0) {
    ppuVar4 = &PTR_PTR_140020428;
    puVar2 = &DAT_1400237f8;
    NdrMesTypeEncode3(local_38[0],&DAT_1400237f8,&PTR_PTR_140020428,&PTR_DAT_14002a078,
                      in_stack_ffffffffffffffa8 & 0xffffffff00000000,&local_res10,uVar5);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar2,ppuVar4,(undefined4)local_res8,
                (char)local_40);
    }
    *param_3 = local_40;
    *param_4 = (undefined4)local_res8;
  }
  else {
    iVar3 = -0x3fffffff;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      iVar3 = -0x3fffffff;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
               &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
    }
  }
  if ((iVar3 < 0) && (local_40 != 0)) {
    ExFreePoolWithTag(local_40,0x6c4d7346);
  }
  if (local_38[0] != 0) {
    MesHandleFree();
  }
  return iVar3;
}



===== PORT_TRACKER_MESSAGE0_MARSHAL_Decode @ 140019950 =====

void PORT_TRACKER_MESSAGE0_MARSHAL_Decode(undefined8 param_1,undefined8 param_2)

{
  NdrMesTypeDecode3(param_1,&DAT_1400237f8,&PTR_PTR_140020428,&PTR_DAT_14002a078,0,param_2);
  return;
}



===== FlowSteeringEngineSocketDispatchThread @ 140019990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FlowSteeringEngineSocketDispatchThread(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  while( true ) {
    while (plVar1 = (longlong *)ExpInterlockedFlushSList(param_1), plVar1 != (longlong *)0x0) {
      plVar2 = (longlong *)0x0;
      do {
        plVar3 = plVar1;
        plVar1 = (longlong *)*plVar3;
        *plVar3 = (longlong)plVar2;
        plVar2 = plVar3;
      } while (plVar1 != (longlong *)0x0);
      while (plVar3 != (longlong *)0x0) {
        plVar1 = (longlong *)*plVar3;
        (*(code *)plVar3[3])();
        plVar3 = plVar1;
      }
    }
    if (*(char *)(param_1 + 0x28) != '\0') break;
    KeWaitForSingleObject(param_1 + 0x10,0,0,0,0);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_cdc6e5f3bb5133d0071e80d41a5344cf_Traceguids);
  }
  return;
}



===== FseWskStartWorkQueue @ 140019a44 =====

ulonglong FseWskStartWorkQueue(PSLIST_HEADER param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  InitializeSListHead(param_1);
  KeInitializeEvent(param_1 + 1,1);
  *(undefined1 *)((longlong)param_1 + 0x28) = 0;
  uVar2 = PsCreateSystemThread
                    (local_res8,0x1fffff,0,0,0,FlowSteeringEngineSocketDispatchThread,param_1);
  if (-1 < (int)uVar2) {
    uVar1 = ObReferenceObjectByHandle(local_res8[0],0x1fffff,0,0,param_1 + 3,0);
    uVar2 = (ulonglong)uVar1;
    ZwClose(local_res8[0]);
  }
  return uVar2;
}



===== FseWskStopWorkQueue @ 140019b00 =====

void FseWskStopWorkQueue(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x28) = 1;
  KeSetEvent(param_1 + 0x10,0,0);
  KeWaitForSingleObject(*(undefined8 *)(param_1 + 0x30),0,0,0,0);
  ObfDereferenceObject(*(undefined8 *)(param_1 + 0x30));
  return;
}



===== CleanupConnectionSocketContext @ 140019b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CleanupConnectionSocketContext(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  
  ExDeleteTimer(*(undefined8 *)(param_1 + 200),1,1,0);
  lVar2 = *(longlong *)(param_1 + 0xa0);
  *(undefined8 *)(param_1 + 0xa0) = 0;
  piVar3 = (int *)(lVar2 + 0x58);
  LOCK();
  iVar1 = *piVar3;
  *piVar3 = *piVar3 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    (**(code **)(lVar2 + 0x60))();
  }
  ExFreePoolWithTag(param_1 + -8,0x63537346);
  return;
}



===== CreateConnectionSocketContext @ 140019bd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
CreateConnectionSocketContext
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  *param_4 = 0;
  puVar3 = (undefined1 *)ExAllocatePool2(0x40,0x1b0,0x63537346);
  if (puVar3 == (undefined1 *)0x0) {
    uVar5 = 0xc000009a;
  }
  else {
    memset(puVar3 + 1,0,0x1af);
    *(undefined4 *)(puVar3 + 0x2c) = 0;
    *(undefined4 *)(puVar3 + 0xf0) = 0;
    *puVar3 = 0;
    puVar3[0x28] = 0;
    *(undefined4 *)(puVar3 + 200) = 0x32;
    *(undefined8 *)(puVar3 + 0xf8) = 0;
    ExInitializeRundownProtection(puVar3 + 0x48);
    ExWaitForRundownProtectionRelease(puVar3 + 0x48);
    lVar4 = ExAllocateTimer(0,0,8);
    *(longlong *)(puVar3 + 0xd0) = lVar4;
    if (lVar4 == 0) {
      uVar5 = 0xc000009a;
      if (*(longlong *)(puVar3 + 0xa8) != 0) {
        piVar1 = (int *)(param_1 + 0x58);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (**(code **)(param_1 + 0x60))();
        }
      }
      if (*(longlong *)(puVar3 + 0xd0) != 0) {
        ExDeleteTimer(*(longlong *)(puVar3 + 0xd0),1,1,0);
      }
      ExFreePoolWithTag(puVar3,0x63537346);
    }
    else {
      KeInitializeEvent(puVar3 + 0xb0,0,0);
      KeInitializeEvent(puVar3 + 0xd8,1);
      *(code **)(puVar3 + 0x10) = CleanupConnectionSocketContext;
      *(undefined4 *)(puVar3 + 8) = 0;
      LOCK();
      *(int *)(puVar3 + 8) = *(int *)(puVar3 + 8) + 1;
      UNLOCK();
      LOCK();
      *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
      UNLOCK();
      *(longlong *)(puVar3 + 0xa8) = param_1;
      *(undefined8 *)(puVar3 + 0xa0) = param_3;
      *(undefined4 *)(puVar3 + 0x50) = 0;
      *param_4 = puVar3;
    }
  }
  return uVar5;
}



===== Feature_Servicing_FseUseAfterFreeFix__private_IsEnabledDeviceUsageNoInline @ 140019d70 =====

ulonglong Feature_Servicing_FseUseAfterFreeFix__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_FseUseAfterFreeFix__private_featureState;
  if ((Feature_Servicing_FseUseAfterFreeFix__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_FseUseAfterFreeFix__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_FseUseAfterFreeFix__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_FseUseAfterFreeFix__private_IsEnabledFallback @ 140019da8 =====

void Feature_Servicing_FseUseAfterFreeFix__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_FseUseAfterFreeFix__private_descriptor);
  return;
}



===== FseAllocateSocketOpContext @ 140019dc4 =====

ulonglong FseAllocateSocketOpContext
                    (longlong param_1,undefined8 param_2,uint param_3,undefined8 param_4,
                    undefined8 *param_5)

{
  ulonglong uVar1;
  void *pvVar2;
  ulonglong uVar3;
  
  if (param_5 == (undefined8 *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    *param_5 = 0;
    pvVar2 = (void *)ExAllocatePool2(0x40,0x50,0x74537346);
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      uVar3 = FseInitializeSocketOpContext(param_1,0,param_3,param_4,pvVar2);
      uVar1 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        ExFreePoolWithTag(pvVar2,0x74537346);
      }
      else {
        *param_5 = pvVar2;
      }
    }
  }
  return uVar1;
}



===== FseCleanupSocketOpContext @ 140019e6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseCleanupSocketOpContext(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x28) != 0) {
      IoFreeIrp();
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
    if (*(longlong *)(param_1 + 0x38) != 0) {
      IoFreeMdl();
      *(undefined8 *)(param_1 + 0x38) = 0;
    }
    if (*(longlong *)(param_1 + 0x30) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0x74537346);
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
    if (*(char *)(param_1 + 0x10) == '\0') {
      lVar2 = *(longlong *)(param_1 + 0x20);
      piVar3 = (int *)(lVar2 + 8);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if (iVar1 == 1) {
        (**(code **)(lVar2 + 0x10))();
      }
    }
  }
  return;
}



===== FseCloseConnectionSocket @ 140019f00 =====

ulonglong FseCloseConnectionSocket
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  code *pcVar3;
  longlong local_res8;
  
  local_res8 = 0;
  lVar1 = *(longlong *)(param_1 + 0xa8);
  uVar2 = FseAllocateSocketOpContext(param_1,param_2,0,param_4,&local_res8);
  if ((int)uVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                     &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar1 + 0x18,(char)uVar2);
    }
  }
  else {
    if (*(int *)(param_1 + 0x2c) == 4) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                      &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar1 + 0x18);
      }
      pcVar3 = FseWskOpDisconnect;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                      &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar1 + 0x18);
      }
      pcVar3 = FseWskOpCloseConnectionSocket;
    }
    FseWskEnqueueOp(local_res8,pcVar3);
  }
  return uVar2 & 0xffffffff;
}



===== FseFreeSocketOpContext @ 14001a018 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseFreeSocketOpContext(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x10) == '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,param_1);
      }
      FseCleanupSocketOpContext(param_1);
      ExFreePoolWithTag(param_1,0x74537346);
    }
    else {
      lVar2 = *(longlong *)(param_1 + 0x20);
      piVar3 = (int *)(lVar2 + 8);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if (iVar1 == 1) {
        (**(code **)(lVar2 + 0x10))();
      }
    }
  }
  return;
}



===== FseInitializeSocketOpContext @ 14001a0a4 =====

undefined8
FseInitializeSocketOpContext
          (longlong param_1,longlong param_2,uint param_3,undefined8 param_4,void *param_5)

{
  bool bVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)param_3;
  bVar1 = false;
  memset(param_5,0,0x50);
  *(longlong *)((longlong)param_5 + 0x20) = param_1;
  LOCK();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  UNLOCK();
  lVar2 = IoAllocateIrp(1,0);
  *(longlong *)((longlong)param_5 + 0x28) = lVar2;
  if (lVar2 != 0) {
    if (param_3 == 0) {
      return 0;
    }
    if (param_2 == 0) {
      param_2 = ExAllocatePool2(0x40,uVar3,0x74537346);
      *(longlong *)((longlong)param_5 + 0x30) = param_2;
      if (param_2 == 0) goto LAB_14001a170;
      bVar1 = true;
    }
    else {
      *(longlong *)((longlong)param_5 + 0x30) = param_2;
      *(ulonglong *)((longlong)param_5 + 0x48) = uVar3;
      bVar1 = false;
    }
    lVar2 = IoAllocateMdl(param_2,uVar3,0,0,0);
    *(longlong *)((longlong)param_5 + 0x38) = lVar2;
    if (lVar2 != 0) {
      MmBuildMdlForNonPagedPool(lVar2);
      *(ulonglong *)((longlong)param_5 + 0x40) = uVar3;
      return 0;
    }
  }
LAB_14001a170:
  if (*(longlong *)((longlong)param_5 + 0x28) != 0) {
    IoFreeIrp();
    *(undefined8 *)((longlong)param_5 + 0x28) = 0;
  }
  if (*(longlong *)((longlong)param_5 + 0x38) != 0) {
    IoFreeMdl();
    *(undefined8 *)((longlong)param_5 + 0x38) = 0;
  }
  lVar2 = *(longlong *)((longlong)param_5 + 0x30);
  if (lVar2 != 0) {
    if (bVar1) {
      ExFreePoolWithTag(lVar2,0x74537346);
    }
    *(longlong *)((longlong)param_5 + 0x30) = 0;
  }
  return 0xc000009a;
}



===== FseWskCloseIrpCompletionRoutine @ 14001a210 =====

undefined8 FseWskCloseIrpCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  OnCloseSocketComplete(param_3,param_2);
  return 0xc0000016;
}



===== FseWskConnectIrpCompletionRoutine @ 14001a230 =====

undefined8
FseWskConnectIrpCompletionRoutine
          (undefined8 param_1,longlong param_2,longlong param_3,longlong param_4)

{
  int *piVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  code *pcVar8;
  undefined8 uVar9;
  int iVar10;
  longlong local_res10;
  
  lVar4 = *(longlong *)(param_3 + 0x20);
  piVar1 = (int *)(param_2 + 0x30);
  lVar5 = *(longlong *)(lVar4 + 0xa8);
  if (*piVar1 < 0) {
    uVar6 = ExAcquireSpinLockExclusive(lVar4 + 0x50);
    uVar3 = *(undefined4 *)(param_2 + 0x30);
    *(longlong *)(lVar4 + 0x100) = *(longlong *)(lVar4 + 0x100) + 1;
    *(undefined4 *)(lVar4 + 0xf0) = uVar3;
    ExReleaseSpinLockExclusive(lVar4 + 0x50,CONCAT31((int3)((uint)uVar3 >> 8),uVar6));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                     &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar5 + 0x18,
                     (char)*(undefined4 *)(param_2 + 0x30));
    }
    pcVar8 = FseWskOpCloseConnectionSocket;
LAB_14001a455:
    FseWskEnqueueOp(param_3,pcVar8);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_4 = lVar5 + 0x18;
      param_2 = 0;
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                     &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,param_4,(char)*piVar1);
    }
    lVar2 = lVar4 + 0x50;
    uVar6 = ExAcquireSpinLockExclusive(lVar2);
    *(undefined4 *)(lVar4 + 0xf0) = 0;
    *(longlong *)(lVar4 + 0x38) = *(longlong *)(lVar4 + 0x38) + 1;
    *(undefined4 *)(lVar4 + 0xcc) = 0;
    *(undefined4 *)(lVar4 + 0x2c) = 4;
    *(undefined4 *)(lVar4 + 200) = 0x32;
    if (*(char *)(lVar4 + 0x40) == '\0') {
      uVar9 = CONCAT71((int7)((ulonglong)param_2 >> 8),uVar6);
      ExReleaseSpinLockExclusive(lVar2,uVar9);
      uVar6 = ExAcquireSpinLockExclusive(lVar5 + 0x50);
      *(undefined4 *)(lVar5 + 0x488) = 0;
      pcVar8 = (code *)CONCAT71((int7)((ulonglong)uVar9 >> 8),uVar6);
      ExReleaseSpinLockExclusive(lVar5 + 0x50);
      local_res10 = 0;
      iVar10 = 0;
      do {
        uVar7 = FseAllocateSocketOpContext
                          (*(longlong *)(param_3 + 0x20),pcVar8,0x800,param_4,&local_res10);
        if ((int)uVar7 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                    &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids);
          }
          pcVar8 = FseWskOpDisconnect;
          goto LAB_14001a455;
        }
        pcVar8 = FseWskOpReceive;
        FseWskEnqueueOp(local_res10,FseWskOpReceive);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_4 = lVar5 + 0x18;
          pcVar8 = (code *)0x1d;
          WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                         &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,param_4,(char)iVar10);
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < 5);
      FseFreeSocketOpContext(param_3);
    }
    else {
      FseWskEnqueueOp(param_3,FseWskOpDisconnect);
      ExReleaseSpinLockExclusive(lVar2,uVar6);
    }
  }
  return 0xc0000016;
}



===== FseWskDeregister @ 14001a484 =====

void FseWskDeregister(void)

{
  WskDeregister();
  g_WskRegistered = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids);
  }
  return;
}



===== FseWskDisconnectIrpCompletionRoutine @ 14001a4e0 =====

undefined8
FseWskDisconnectIrpCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_3 + 0x20);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
               &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar1 + 0x20,(char)param_3,
               (char)*(undefined4 *)(param_2 + 0x30));
  }
  uVar2 = ExAcquireSpinLockExclusive(lVar1 + 0x50);
  *(uint *)(lVar1 + 0x30) = *(uint *)(lVar1 + 0x30) | 4;
  ExReleaseSpinLockExclusive(lVar1 + 0x50,uVar2);
  FseWskEnqueueOp(param_3,FseWskOpCloseConnectionSocket);
  return 0xc0000016;
}



===== FseWskEnqueueOp @ 14001a588 =====

void FseWskEnqueueOp(longlong param_1,undefined8 param_2)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  pcVar1 = *(char **)(param_1 + 0x20);
  if (*pcVar1 == '\0') {
    lVar3 = *(longlong *)(pcVar1 + 0xa0);
  }
  else {
    lVar3 = *(longlong *)(pcVar1 + 0x30);
  }
  *(undefined8 *)(param_1 + 0x18) = param_2;
  lVar2 = ExpInterlockedPushEntrySList(lVar3,param_1);
  if (lVar2 == 0) {
    KeSetEvent(lVar3 + 0x10,0,0);
  }
  return;
}



===== FseWskOpCloseConnectionSocket @ 14001a5f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseWskOpCloseConnectionSocket(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x20);
  lVar3 = *(longlong *)(lVar2 + 0xa8);
  lVar1 = lVar2 + 0x50;
  uVar4 = ExAcquireSpinLockExclusive(lVar1);
  if (*(uint *)(lVar2 + 0x2c) < 2) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                    &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar3 + 0x18);
    }
    ExReleaseSpinLockExclusive(lVar1,uVar4);
    FseFreeSocketOpContext(param_1);
  }
  else {
    *(uint *)(lVar2 + 0x30) = *(uint *)(lVar2 + 0x30) | 8;
    *(undefined4 *)(lVar2 + 0x2c) = 1;
    ExReleaseSpinLockExclusive(lVar1,uVar4);
    ExWaitForRundownProtectionRelease(lVar2 + 0x48);
    lVar1 = **(longlong **)(lVar2 + 0x20);
    IoReuseIrp(*(undefined8 *)(param_1 + 0x28),0xc0000001);
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xb8);
    *(code **)(lVar3 + -0x10) = FseWskCloseIrpCompletionRoutine;
    *(longlong *)(lVar3 + -8) = param_1;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,param_3,lVar2 + 0x20,(char)param_1);
    }
    (**(code **)(lVar1 + 8))(*(undefined8 *)(lVar2 + 0x20),*(undefined8 *)(param_1 + 0x28));
  }
  return;
}



===== FseWskOpDisconnect @ 14001a750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseWskOpDisconnect(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x20);
  lVar1 = lVar2 + 0x50;
  uVar4 = ExAcquireSpinLockExclusive(lVar1);
  if (*(uint *)(lVar2 + 0x2c) < 3) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,param_3,lVar2 + 0x20,(char)param_1);
    }
    ExReleaseSpinLockExclusive(lVar1,uVar4);
    FseFreeSocketOpContext(param_1);
  }
  else {
    lVar3 = **(longlong **)(lVar2 + 0x20);
    *(uint *)(lVar2 + 0x30) = *(uint *)(lVar2 + 0x30) | 2;
    *(undefined4 *)(lVar2 + 0x2c) = 2;
    ExReleaseSpinLockExclusive
              (lVar1,CONCAT71((int7)((ulonglong)*(longlong **)(lVar2 + 0x20) >> 8),uVar4));
    IoReuseIrp(*(undefined8 *)(param_1 + 0x28),0xc0000001);
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xb8);
    *(code **)(lVar1 + -0x10) = FseWskDisconnectIrpCompletionRoutine;
    *(longlong *)(lVar1 + -8) = param_1;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,param_3,lVar2 + 0x20,(char)param_1);
    }
    (**(code **)(lVar3 + 0x40))(*(undefined8 *)(lVar2 + 0x20),0,1,*(undefined8 *)(param_1 + 0x28));
  }
  return;
}



===== FseWskOpReceive @ 14001a8a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseWskOpReceive(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  ulonglong uVar6;
  undefined7 uVar7;
  bool bVar8;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  
  lVar2 = *(longlong *)(param_1 + 0x20);
  bVar8 = false;
  lVar3 = *(longlong *)(lVar2 + 0xa8);
  lVar1 = lVar2 + 0x50;
  uVar4 = ExAcquireSpinLockShared(lVar1);
  uVar7 = (undefined7)((ulonglong)param_2 >> 8);
  if ((*(char *)(lVar2 + 0x40) == '\0') && (*(int *)(lVar2 + 0x2c) == 4)) {
    cVar5 = ExAcquireRundownProtection(lVar2 + 0x48);
    if (cVar5 != '\0') {
      ExReleaseSpinLockShared(lVar1,CONCAT71(uVar7,uVar4));
      local_2c = 0;
      lVar1 = **(longlong **)(lVar2 + 0x20);
      local_28 = *(undefined8 *)(param_1 + 0x40);
      local_30 = 0;
      local_38 = *(undefined8 *)(param_1 + 0x38);
      IoReuseIrp(*(undefined8 *)(param_1 + 0x28),0xc0000001);
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xb8);
      *(code **)(lVar3 + -0x10) = FseWskReceiveIrpCompletionRoutine;
      *(longlong *)(lVar3 + -8) = param_1;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      (**(code **)(lVar1 + 0x38))
                (*(undefined8 *)(lVar2 + 0x20),&local_38,0,*(undefined8 *)(param_1 + 0x28));
      ExReleaseRundownProtection(lVar2 + 0x48);
      goto LAB_14001aa34;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar7 = 0;
      WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar2 + 0x20);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar7 = 0;
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                  &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar3 + 0x18);
  }
  uVar6 = Feature_Servicing_FseUseAfterFreeFix__private_IsEnabledDeviceUsageNoInline();
  bVar8 = (int)uVar6 == 0;
  if (bVar8) {
    FseFreeSocketOpContext(param_1);
  }
  bVar8 = !bVar8;
  ExReleaseSpinLockShared(lVar1,CONCAT71(uVar7,uVar4));
LAB_14001aa34:
  uVar6 = Feature_Servicing_FseUseAfterFreeFix__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar6 != 0) && (bVar8)) {
    FseFreeSocketOpContext(param_1);
  }
  return;
}



===== FseWskOpSend @ 14001aa70 =====

void FseWskOpSend(longlong param_1,undefined8 param_2,undefined *param_3)

{
  FseWskOpSendCommon(param_1,param_2,param_3);
  return;
}



===== FseWskOpSendCommon @ 14001aa88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseWskOpSendCommon(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  undefined1 uVar5;
  char cVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  
  lVar4 = *(longlong *)(param_1 + 0x20);
  lVar8 = *(longlong *)(lVar4 + 0xa8) + 0x50;
  uVar5 = ExAcquireSpinLockExclusive(lVar8);
  lVar1 = lVar4 + 0x50;
  ExAcquireSpinLockSharedAtDpcLevel(lVar1);
  if ((*(char *)(lVar4 + 0x40) == '\0') && (*(int *)(lVar4 + 0x2c) == 4)) {
    cVar6 = ExAcquireRundownProtection(lVar4 + 0x48);
    if (cVar6 != '\0') {
      ExReleaseSpinLockSharedFromDpcLevel(lVar1);
      ExReleaseSpinLockExclusive(lVar8,uVar5);
      local_2c = 0;
      uVar7 = 0xc0000001;
      lVar1 = **(longlong **)(lVar4 + 0x20);
      local_28 = *(undefined8 *)(param_1 + 0x48);
      local_30 = 0;
      local_38 = *(undefined8 *)(param_1 + 0x38);
      IoReuseIrp(*(undefined8 *)(param_1 + 0x28));
      lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xb8);
      *(code **)(lVar8 + -0x10) = FseWskSendIrpCompletionRoutine;
      *(longlong *)(lVar8 + -8) = param_1;
      *(undefined1 *)(lVar8 + -0x45) = 0xe0;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qqP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,param_3,lVar4 + 0x20,
                   (char)param_1,(char)local_28);
      }
      (**(code **)(lVar1 + 0x30))
                (*(undefined8 *)(lVar4 + 0x20),&local_38,0,*(undefined8 *)(param_1 + 0x28));
      ExReleaseRundownProtection(lVar4 + 0x48);
      return;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_2 = 0x25;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,param_3,lVar4 + 0x20,(char)param_1);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids;
    param_2 = 0x24;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids);
  }
  HandleMessageSendFailure((undefined8 *)(param_1 + -0x70),param_2,param_3);
  piVar2 = (int *)(param_1 + -0x30);
  LOCK();
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    (**(code **)(param_1 + -0x28))();
  }
  ExReleaseSpinLockSharedFromDpcLevel(lVar1);
  ExReleaseSpinLockExclusive(lVar8,uVar5);
  return;
}



===== FseWskReceiveIrpCompletionRoutine @ 14001acb0 =====

undefined8 FseWskReceiveIrpCompletionRoutine(undefined8 param_1,longlong param_2,undefined *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined *puVar5;
  
  puVar5 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqdP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
                *(longlong *)(param_3 + 0x20) + 0x20,(char)param_3,
                (char)*(undefined4 *)(param_2 + 0x30),(char)*(undefined8 *)(param_2 + 0x38));
  }
  lVar1 = *(longlong *)(param_3 + 0x20);
  if (*(int *)(param_2 + 0x30) < 0) {
    uVar2 = ExAcquireSpinLockExclusive(lVar1 + 0x50);
    *(uint *)(lVar1 + 0x30) = *(uint *)(lVar1 + 0x30) | 0x40;
    ExReleaseSpinLockExclusive(lVar1 + 0x50,uVar2);
    pcVar4 = FseWskOpCloseConnectionSocket;
  }
  else {
    if (*(longlong *)(param_2 + 0x38) == 0) {
      uVar2 = ExAcquireSpinLockExclusive(lVar1 + 0x50);
      *(uint *)(lVar1 + 0x30) = *(uint *)(lVar1 + 0x30) | 0x80;
    }
    else {
      uVar3 = FseProcessIncomingMessages((longlong)param_3,param_2,puVar5);
      if ((char)uVar3 != '\0') {
        *(undefined8 *)(param_3 + 0x48) = 0;
        pcVar4 = FseWskOpReceive;
        goto LAB_14001ada5;
      }
      uVar2 = ExAcquireSpinLockExclusive(lVar1 + 0x50);
      *(uint *)(lVar1 + 0x30) = *(uint *)(lVar1 + 0x30) | 0x100;
    }
    ExReleaseSpinLockExclusive(lVar1 + 0x50,uVar2);
    pcVar4 = FseWskOpDisconnect;
  }
LAB_14001ada5:
  FseWskEnqueueOp((longlong)param_3,pcVar4);
  return 0xc0000016;
}



===== FseWskRegister @ 14001adcc =====

int FseWskRegister(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  
  *param_1 = 0;
  param_1[1] = &gWskClientDispatch;
  iVar1 = WskRegister();
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,iVar1);
    }
    if (g_WskRegistered != '\0') {
      WskDeregister(param_2);
    }
  }
  else {
    g_WskRegistered = '\x01';
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids);
    }
  }
  return iVar1;
}



===== FseWskSendIrpCompletionRoutine @ 14001ae90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
FseWskSendIrpCompletionRoutine
          (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined **ppuVar10;
  code *pcVar11;
  undefined *puVar12;
  longlong local_res10;
  
  if (*(int *)(param_2 + 0x30) < 0) {
    lVar4 = *(longlong *)(param_3 + 0x20);
    local_res10 = 0;
    lVar5 = *(longlong *)(lVar4 + 0xa8);
    lVar1 = lVar4 + 0x50;
    lVar8 = param_2;
    uVar6 = ExAcquireSpinLockExclusive(lVar1);
    *(uint *)(lVar4 + 0x30) = *(uint *)(lVar4 + 0x30) | 0x20;
    uVar9 = CONCAT71((int7)((ulonglong)lVar8 >> 8),uVar6);
    ExReleaseSpinLockExclusive(lVar1);
    puVar12 = (undefined *)0x0;
    uVar7 = FseAllocateSocketOpContext(lVar4,uVar9,0,param_4,&local_res10);
    if ((int)uVar7 < 0) {
      ppuVar10 = &WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        ppuVar10 = (undefined **)0x14;
        puVar12 = &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids;
        WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                       &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,lVar5 + 0x18,(char)uVar7);
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar12 = &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids;
        WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                       &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,lVar5 + 0x18,
                       (char)*(undefined4 *)(param_2 + 0x30));
      }
      pcVar11 = FseWskOpCloseConnectionSocket;
      FseWskEnqueueOp(local_res10,FseWskOpCloseConnectionSocket);
      ppuVar10 = (undefined **)pcVar11;
    }
    uVar6 = ExAcquireSpinLockExclusive(lVar5 + 0x50);
    ExAcquireSpinLockSharedAtDpcLevel(lVar1);
    HandleMessageSendFailure((undefined8 *)(param_3 + -0x70),ppuVar10,puVar12);
    ExReleaseSpinLockSharedFromDpcLevel(lVar1);
    ExReleaseSpinLockExclusive(lVar5 + 0x50,uVar6);
  }
  piVar2 = (int *)(param_3 + -0x30);
  LOCK();
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    (**(code **)(param_3 + -0x28))();
  }
  return 0xc0000016;
}



===== FseWskSetupConnectionSocket @ 14001b00c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseWskSetupConnectionSocket(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 auStackY_118 [32];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  longlong local_a0;
  undefined2 local_98;
  undefined2 local_96;
  undefined4 uStack_94;
  undefined2 uStack_90;
  undefined2 uStack_8e;
  undefined4 uStack_8c;
  undefined2 uStack_88;
  undefined2 local_86;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar2 = *(longlong *)(param_2 + 0x20);
  lVar3 = *(longlong *)(param_2 + 0x28);
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  lVar4 = *(longlong *)(lVar2 + 0xa8);
  lVar1 = lVar2 + 0x50;
  uVar8 = ExAcquireSpinLockExclusive(lVar1);
  if (*(char *)(lVar2 + 0x40) == '\0') {
    *(undefined4 *)(lVar2 + 0x2c) = 3;
    *(longlong *)(lVar2 + 0xf8) = *(longlong *)(lVar2 + 0xf8) + 1;
    ExReleaseSpinLockExclusive(lVar1,uVar8);
    KeInitializeEvent(&local_b8,1);
    lVar5 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar5 + -0x10) = FseWskSyncIrpCompletionRoutine;
    *(undefined8 **)(lVar5 + -8) = &local_b8;
    *(undefined1 *)(lVar5 + -0x45) = 0xe0;
    (**(code **)(param_1[1] + 8))(*param_1,0x22,1,1);
    KeWaitForSingleObject(&local_b8,0,0,0);
    if (*(int *)(lVar3 + 0x30) < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,*(int *)(lVar3 + 0x30));
      }
    }
    else {
      plVar6 = *(longlong **)(lVar3 + 0x38);
      lVar5 = *plVar6;
      local_a0 = lVar5;
      IoReuseIrp(lVar3,0xc0000001);
      lVar7 = *(longlong *)(lVar3 + 0xb8);
      *(code **)(lVar7 + -0x10) = FseWskSyncIrpCompletionRoutine;
      *(undefined8 **)(lVar7 + -8) = &local_b8;
      *(undefined1 *)(lVar7 + -0x45) = 0xe0;
      local_70 = 0x22;
      local_5c = 0xb0412ccb;
      uStack_58 = 0x401dd167;
      uStack_54 = 0xcdb18094;
      uStack_50 = 0xb82a3294;
      local_6c = 0xe0e16197;
      uStack_68 = 0x4a10dd56;
      uStack_64 = 0xe75e9591;
      uStack_60 = 0x38a855a1;
      (**(code **)(lVar5 + 0x10))(plVar6,&local_70,0,lVar3);
      uVar10 = 0;
      KeWaitForSingleObject(&local_b8,0,0,0);
      if (-1 < *(int *)(lVar3 + 0x30)) {
        uVar8 = ExAcquireSpinLockExclusive(lVar1);
        *(longlong *)(lVar2 + 0x20) = (longlong)plVar6;
        if (*(char *)(lVar2 + 0x40) != '\0') {
          ExReleaseSpinLockExclusive(lVar1,uVar8);
          FseWskEnqueueOp(param_2,FseWskOpCloseConnectionSocket);
          return;
        }
        ExReInitializeRundownProtection(lVar2 + 0x48);
        uVar9 = 0xc0000001;
        IoReuseIrp(lVar3,0xc0000001);
        lVar5 = *(longlong *)(lVar3 + 0xb8);
        uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),uVar8);
        *(code **)(lVar5 + -0x10) = FseWskConnectIrpCompletionRoutine;
        *(longlong *)(lVar5 + -8) = param_2;
        *(undefined1 *)(lVar5 + -0x45) = 0xe0;
        local_96 = 0;
        local_98 = 0x22;
        uStack_94 = *(undefined4 *)(lVar4 + 0x18);
        uStack_8c = *(undefined4 *)(lVar4 + 0x20);
        local_84 = 0xb0412ccb;
        uStack_80 = 0x401dd167;
        uStack_7c = 0xcdb18094;
        uStack_78 = 0xb82a3294;
        uStack_90 = (undefined2)*(undefined4 *)(lVar4 + 0x1c);
        uStack_8e = (undefined2)((uint)*(undefined4 *)(lVar4 + 0x1c) >> 0x10);
        uStack_88 = (undefined2)*(undefined4 *)(lVar4 + 0x24);
        local_86 = (undefined2)((uint)*(undefined4 *)(lVar4 + 0x24) >> 0x10);
        ExReleaseSpinLockExclusive(lVar1);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF__guid_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,uVar10,lVar4 + 0x18,
                          (char)(longlong *)(lVar2 + 0x20),(char)param_2);
        }
        (**(code **)(local_a0 + 0x18))(plVar6,&local_98,0,lVar3);
        return;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,*(int *)(lVar3 + 0x30));
      }
      if (plVar6 != (longlong *)0x0) {
        uVar8 = ExAcquireSpinLockExclusive(lVar1);
        *(undefined4 *)(lVar2 + 0x2c) = 1;
        ExReleaseSpinLockExclusive(lVar1,uVar8);
        IoReuseIrp(lVar3,0xc0000001);
        lVar1 = *(longlong *)(lVar3 + 0xb8);
        *(code **)(lVar1 + -0x10) = FseWskSyncIrpCompletionRoutine;
        *(undefined8 **)(lVar1 + -8) = &local_b8;
        *(undefined1 *)(lVar1 + -0x45) = 0xe0;
        (**(code **)(lVar5 + 8))(plVar6,lVar3);
        KeWaitForSingleObject(&local_b8,0,0,0);
      }
    }
    FseWskReconnectSocket(param_2);
  }
  else {
    ExReleaseSpinLockExclusive();
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                    &WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,lVar4 + 0x18);
    }
    FseFreeSocketOpContext(param_2);
  }
  return;
}



===== FseWskSyncIrpCompletionRoutine @ 14001b470 =====

undefined8 FseWskSyncIrpCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,2);
  return 0xc0000016;
}



===== WPP_SF__guid_qq @ 14001b49c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_qq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,0x16,param_4,0x10,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qq @ 14001b4fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqP @ 14001b554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,0x26,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qqd @ 14001b5b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qqdP @ 14001b618 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_088921ce39d93cff3233e9e0998f669e_Traceguids,0x19,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,8,0);
  return;
}



===== CleanupPartition @ 14001b690 =====

void CleanupPartition(longlong param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_c72b246faf363cca7bec32a3e5733161_Traceguids,param_1 + -0x40);
  }
  ExFreePoolWithTag(param_1 + -0x58,0x64507346);
  return;
}



===== CloseSocketForPartition @ 14001b6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CloseSocketForPartition
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  int *piVar6;
  undefined8 uVar7;
  undefined *puVar8;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_4 = param_1 + 0x18;
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                  &WPP_c72b246faf363cca7bec32a3e5733161_Traceguids,param_4);
  }
  lVar3 = *(longlong *)(param_1 + 0x68);
  lVar1 = param_1 + 0x50;
  uVar5 = ExAcquireSpinLockExclusive(lVar1);
  iVar2 = *(int *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x70) = 2;
  ExAcquireSpinLockExclusiveAtDpcLevel(lVar3 + 0x50);
  *(undefined1 *)(lVar3 + 0x40) = 1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_4 = param_1 + 0x18;
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_c72b246faf363cca7bec32a3e5733161_Traceguids,param_4);
  }
  puVar8 = (undefined *)0x0;
  uVar7 = 0;
  KeSetEvent(lVar3 + 0xd8,0);
  lVar4 = *(longlong *)(lVar3 + 0x20);
  ExReleaseSpinLockExclusiveFromDpcLevel(lVar3 + 0x50);
  uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),uVar5);
  ExReleaseSpinLockExclusive(lVar1);
  if (lVar4 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                    &WPP_c72b246faf363cca7bec32a3e5733161_Traceguids,param_1 + 0x18);
    }
  }
  else {
    if (iVar2 != 2) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_4 = param_1 + 0x18;
        uVar7 = 0xc;
        puVar8 = &WPP_c72b246faf363cca7bec32a3e5733161_Traceguids;
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                      &WPP_c72b246faf363cca7bec32a3e5733161_Traceguids,param_4);
      }
      FseCloseConnectionSocket(*(longlong *)(param_1 + 0x68),uVar7,puVar8,param_4);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                    &WPP_c72b246faf363cca7bec32a3e5733161_Traceguids,param_1 + 0x18);
    }
    KeWaitForSingleObject(lVar3 + 0xb0,0,0,0,0);
  }
  lVar3 = *(longlong *)(param_1 + 0x68);
  piVar6 = (int *)(lVar3 + 8);
  LOCK();
  iVar2 = *piVar6;
  *piVar6 = *piVar6 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(lVar3 + 0x10))();
  }
  lVar3 = *(longlong *)(param_1 + 0x68);
  piVar6 = (int *)(lVar3 + 8);
  LOCK();
  iVar2 = *piVar6;
  *piVar6 = *piVar6 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(lVar3 + 0x10))();
  }
  uVar5 = ExAcquireSpinLockExclusive(lVar1);
  *(undefined8 *)(param_1 + 0x68) = 0;
  ExReleaseSpinLockExclusive(lVar1,uVar5);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                  &WPP_c72b246faf363cca7bec32a3e5733161_Traceguids,param_1 + 0x18);
  }
  return;
}



===== FseRemoveMessageContextFromPartitionQueueCommon @ 14001b958 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
FseRemoveMessageContextFromPartitionQueueCommon
          (longlong param_1,longlong param_2,undefined8 param_3,undefined8 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  *param_4 = 0;
  puVar5 = (undefined8 *)(param_1 + 0x40);
  puVar6 = *(undefined8 **)(param_1 + 0x40);
  while (puVar4 = puVar6, puVar3 = puVar5, puVar4 != (undefined8 *)0x0) {
    puVar5 = puVar4;
    puVar6 = (undefined8 *)*puVar4;
    if (puVar4[2] == param_2) {
      *puVar3 = (undefined8 *)*puVar4;
      piVar1 = (int *)(puVar4 + 8);
      *puVar4 = 0;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (*(code *)puVar4[9])();
      }
      *param_4 = puVar4;
      return 1;
    }
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return 0;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
    return 0;
  }
  WPP_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_2);
  return 0;
}



===== ResumePartition @ 14001b9f8 =====

undefined8 ResumePartition(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x68);
  lVar1 = param_1 + 0x50;
  uVar4 = 0;
  uVar3 = ExAcquireSpinLockExclusive(lVar1);
  ExAcquireSpinLockExclusiveAtDpcLevel(lVar2 + 0x50);
  if (*(char *)(lVar2 + 0x40) == '\0') {
    *(undefined8 *)(lVar2 + 200) = 0x32;
    ExReleaseSpinLockExclusiveFromDpcLevel(lVar2 + 0x50);
    ExReleaseSpinLockExclusive(lVar1,uVar3);
    KeSetEvent(lVar2 + 0xd8,2);
  }
  else {
    uVar4 = 0xc0000189;
    ExReleaseSpinLockExclusiveFromDpcLevel();
    ExReleaseSpinLockExclusive(lVar1,uVar3);
  }
  return uVar4;
}



===== WPP_SF_id @ 14001bad8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_id(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 1;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c72b246faf363cca7bec32a3e5733161_Traceguids,0x11,&local_res20,8,
             local_18,4,0);
  return;
}



===== CleanupMessageContext @ 14001bb40 =====

void CleanupMessageContext(longlong param_1)

{
  FseCleanupSocketOpContext(param_1 + 0x30);
  ExFreePoolWithTag(param_1 + -0x40,0x74537346);
  return;
}



===== CreateMessageContext @ 14001bb74 =====

ulonglong CreateMessageContext
                    (longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                    undefined4 param_5,longlong param_6,uint param_7,undefined8 param_8,
                    undefined8 *param_9)

{
  ulonglong uVar1;
  void *_Dst;
  ulonglong uVar2;
  
  if (param_9 == (undefined8 *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    *param_9 = 0;
    _Dst = (void *)ExAllocatePool2(0x40,0xc0,0x74537346);
    if (_Dst == (void *)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      memset(_Dst,0,0xc0);
      *(undefined8 *)((longlong)_Dst + 0x60) = 0;
      *(undefined4 *)((longlong)_Dst + 0x50) = param_5;
      *(undefined8 *)((longlong)_Dst + 0x10) = param_2;
      *(undefined4 *)((longlong)_Dst + 0x54) = param_3;
      *(undefined1 *)((longlong)_Dst + 0x58) = 1;
      *(undefined4 *)((longlong)_Dst + 8) = 0;
      KeInitializeEvent((longlong)_Dst + 0x28,0,0);
      *(code **)((longlong)_Dst + 0x48) = CleanupMessageContext;
      *(undefined4 *)((longlong)_Dst + 0x40) = 0;
      LOCK();
      *(int *)((longlong)_Dst + 0x40) = *(int *)((longlong)_Dst + 0x40) + 1;
      UNLOCK();
      uVar2 = FseInitializeSocketOpContext
                        (param_1,param_6,param_7,param_4,(void *)((longlong)_Dst + 0x70));
      uVar1 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        ExFreePoolWithTag(_Dst,0x74537346);
      }
      else {
        *param_9 = _Dst;
      }
    }
  }
  return uVar1;
}



===== Feature_3856917819__private_IsEnabledDeviceUsageNoInline @ 14001bc94 =====

ulonglong Feature_3856917819__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3856917819__private_featureState;
  if ((Feature_3856917819__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3856917819__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3856917819__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3856917819__private_IsEnabledFallback @ 14001bccc =====

void Feature_3856917819__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3856917819__private_descriptor);
  return;
}



===== FseProcessIncomingMessage @ 14001bce8 =====

ulonglong FseProcessIncomingMessage(ulonglong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong uVar2;
  int *piVar3;
  code *pcVar4;
  ulonglong uVar5;
  uint uVar6;
  int *local_res8;
  
  uVar6 = (int)param_3 - 0x20;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_dDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1 + 0x18,
                     (char)uVar6,(char)*(undefined4 *)(param_2 + 4),
                     (char)*(undefined8 *)(param_2 + 8));
  }
  iVar1 = *(int *)(param_2 + 4);
  local_res8 = (int *)0x0;
  pcVar4 = PORT_TRACKER_MESSAGE0_MARSHAL_Decode;
  if (iVar1 != 1) {
    pcVar4 = (code *)0x0;
  }
  uVar2 = Feature_3923932473__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 == 0) || (pcVar4 != (code *)0x0)) {
    uVar2 = FseMidlObjectDecode(pcVar4,(void *)(param_2 + 0x20),uVar6,(longlong *)&local_res8);
    piVar3 = local_res8;
    uVar5 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      if (*(uint *)(param_2 + 4) == 1) {
        uVar6 = FseProcessDecodedMessage(param_1,param_2,local_res8);
        uVar5 = (ulonglong)uVar6;
      }
      else {
        SendInvalidVersionResponse
                  (param_1,*(undefined8 *)(param_2 + 8),(ulonglong)*(uint *)(param_2 + 4));
      }
      goto LAB_14001be3a;
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
               &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
    }
    uVar5 = 0xc000000d;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return uVar5;
  }
  piVar3 = (int *)0x0;
  if (1 < (byte)WPP_GLOBAL_Control[0x29]) {
    WPP_SF__guid_Di(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                    &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,param_1 + 0x18,
                    (char)*(undefined4 *)(param_2 + 4),(char)*(undefined8 *)(param_2 + 8));
  }
LAB_14001be3a:
  if (piVar3 != (int *)0x0) {
    ExFreePoolWithTag(piVar3,0x6c4d7346);
  }
  return uVar5;
}



===== FseProcessIncomingMessages @ 14001be7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FseProcessIncomingMessages(longlong param_1,longlong param_2,undefined *param_3)

{
  ulonglong uVar1;
  void *pvVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  size_t _Size;
  uint uVar8;
  uint *_Src;
  undefined1 auStackY_98 [32];
  uint local_50 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  pvVar2 = *(void **)(param_1 + 0x20);
  _Src = *(uint **)(param_1 + 0x30);
  uVar7 = *(uint *)(param_2 + 0x38);
  _Size = (size_t)uVar7;
  uVar1 = *(ulonglong *)((longlong)pvVar2 + 0xa8);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids;
    pvVar2 = (void *)WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                                    &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,uVar1 + 0x18,
                                    (char)uVar7);
  }
  if (*(int *)(uVar1 + 0x488) == 0) {
LAB_14001c20a:
    if ((int)_Size != 0) {
LAB_14001c212:
      uVar7 = (uint)_Size;
      if (uVar7 < 0x21) {
        Feature_3856917819__private_IsEnabledDeviceUsageNoInline();
      }
      else {
        if (*_Src <= uVar7) {
          FseProcessIncomingMessage(uVar1,(longlong)_Src,(ulonglong)*_Src);
          uVar6 = *_Src;
          pvVar2 = (void *)(ulonglong)uVar6;
          _Src = (uint *)((longlong)_Src + (longlong)pvVar2);
          uVar7 = uVar7 - uVar6;
          _Size = (size_t)uVar7;
          if (uVar7 == 0) goto LAB_14001c2ca;
          goto LAB_14001c212;
        }
        uVar4 = Feature_3856917819__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 != 0) {
          uVar8 = *_Src;
          uVar4 = (ulonglong)uVar8;
          if ((uVar8 < 0x401) && (uVar7 < 0x401)) goto LAB_14001c2b2;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001c2a9;
          uVar5 = 0x32;
          goto LAB_14001c295;
        }
      }
LAB_14001c2b2:
      pvVar2 = memmove((void *)(uVar1 + 0x88),_Src,_Size);
      *(uint *)(uVar1 + 0x488) = uVar7;
    }
LAB_14001c2ca:
    uVar4 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids;
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                    &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,uVar1 + 0x18);
    }
    uVar6 = *(uint *)(uVar1 + 0x488);
    if (uVar6 < 4) {
      if (uVar7 < 0x20 - uVar6) {
        uVar4 = Feature_3856917819__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 != 0) {
          uVar6 = *(uint *)(uVar1 + 0x488);
          uVar4 = (ulonglong)uVar6;
          uVar8 = uVar6 + uVar7;
          if ((uVar8 < uVar6) || (0x400 < uVar8)) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001c2a9;
            uVar5 = 0x2b;
LAB_14001c295:
            uVar4 = WPP_SF__guid_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                                    &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,uVar1 + 0x18,
                                    (char)uVar8,0);
            goto LAB_14001c2a9;
          }
        }
        pvVar2 = memmove((void *)((ulonglong)*(uint *)(uVar1 + 0x488) + 0x88 + uVar1),_Src,_Size);
        *(int *)(uVar1 + 0x488) = *(int *)(uVar1 + 0x488) + uVar7;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x2c;
LAB_14001c1ba:
          pvVar2 = (void *)WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                                   &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids);
        }
        goto LAB_14001c2ca;
      }
      local_50[0] = 0;
      local_50[1] = 0;
      local_50[2] = 0;
      local_50[3] = 0;
      memmove(local_50,(void *)(uVar1 + 0x88),(ulonglong)uVar6);
      param_3 = (undefined *)(ulonglong)(0x20 - uVar6);
      memmove((void *)((longlong)local_50 + (ulonglong)uVar6),_Src,(size_t)param_3);
      uVar3 = Feature_3856917819__private_IsEnabledDeviceUsageNoInline();
      uVar6 = local_50[0] - 0x21;
      uVar4 = (ulonglong)uVar6;
      uVar8 = local_50[0];
      if ((int)uVar3 == 0) {
        if (uVar6 < 0x3e0) goto LAB_14001c121;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x2e;
          goto LAB_14001c100;
        }
      }
      else {
        if (uVar6 < 0x3e0) {
LAB_14001c121:
          uVar6 = local_50[0] - *(uint *)(uVar1 + 0x488);
          if (uVar7 < uVar6) {
            uVar4 = Feature_3856917819__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar4 != 0) {
              uVar6 = *(uint *)(uVar1 + 0x488);
              uVar4 = (ulonglong)uVar6;
              uVar8 = uVar6 + uVar7;
              if ((uVar8 < uVar6) || (0x400 < uVar8)) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar5 = 0x2f;
                  goto LAB_14001c295;
                }
                goto LAB_14001c2a9;
              }
            }
            pvVar2 = memmove((void *)((ulonglong)*(uint *)(uVar1 + 0x488) + 0x88 + uVar1),_Src,_Size
                            );
            *(int *)(uVar1 + 0x488) = *(int *)(uVar1 + 0x488) + uVar7;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (4 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar5 = 0x30;
              goto LAB_14001c1ba;
            }
            goto LAB_14001c2ca;
          }
          pvVar2 = (void *)((ulonglong)*(uint *)(uVar1 + 0x488) + 0x88 + uVar1);
          goto LAB_14001c1dc;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x2d;
          goto LAB_14001c100;
        }
      }
    }
    else {
      uVar8 = *(uint *)(uVar1 + 0x88);
      uVar3 = Feature_3856917819__private_IsEnabledDeviceUsageNoInline();
      uVar6 = uVar8 - 0x21;
      uVar4 = (ulonglong)uVar6;
      if ((int)uVar3 == 0) {
        if (uVar6 < 0x3e0) goto LAB_14001bf78;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x29;
          goto LAB_14001c100;
        }
      }
      else {
        if (uVar6 < 0x3e0) {
LAB_14001bf78:
          pvVar2 = (void *)(uVar1 + 0x88 + (ulonglong)*(uint *)(uVar1 + 0x488));
          uVar6 = uVar8 - *(uint *)(uVar1 + 0x488);
          if (uVar6 <= uVar7) {
LAB_14001c1dc:
            memmove(pvVar2,_Src,(ulonglong)uVar6);
            _Size = (size_t)(uVar7 + (*(int *)(uVar1 + 0x488) - uVar8));
            _Src = (uint *)((longlong)_Src + (ulonglong)(uVar8 - *(int *)(uVar1 + 0x488)));
            pvVar2 = (void *)FseProcessIncomingMessage(uVar1,uVar1 + 0x88,(ulonglong)uVar8);
            *(undefined4 *)(uVar1 + 0x488) = 0;
            goto LAB_14001c20a;
          }
          pvVar2 = memmove(pvVar2,_Src,_Size);
          *(int *)(uVar1 + 0x488) = *(int *)(uVar1 + 0x488) + uVar7;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x2a;
            goto LAB_14001c1ba;
          }
          goto LAB_14001c2ca;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x28;
LAB_14001c100:
          uVar4 = WPP_SF__guid_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,param_3,
                                   uVar1 + 0x18,(char)uVar8);
        }
      }
    }
LAB_14001c2a9:
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  return uVar4;
}



===== FseSendResponseMessage @ 14001c2fc =====

void FseSendResponseMessage
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               longlong param_5,uint param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffffe0;
  
  local_res8 = 0;
  uVar1 = CreateMessageContext
                    (*(longlong *)(param_1 + 0x68),param_2,(int)param_3,param_4,(int)param_4,param_5
                     ,param_6,in_stack_ffffffffffffffe0,&local_res8);
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,param_3,
                      param_1 + 0x18,(char)uVar1,(char)param_4);
    }
  }
  else {
    lVar2 = local_res8 + 0x70;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_iq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,param_3,
                      param_1 + 0x18,(char)param_2,(char)lVar2);
    }
    FseWskEnqueueOp(lVar2,FseWskOpSend);
  }
  return;
}



===== HandleMessageSendFailure @ 14001c3dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleMessageSendFailure(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  int *piVar4;
  undefined2 uVar5;
  longlong local_res10;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_did(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
               *(undefined4 *)(param_1 + 10),(char)param_1[2],*(undefined1 *)(param_1 + 0xb));
  }
  iVar1 = *(int *)(param_1 + 10);
  lVar2 = *(longlong *)(param_1[0x12] + 0xa8);
  if (((iVar1 != 0x1100) && (iVar1 != 0x2000)) && (iVar1 != 0x2002)) {
    return;
  }
  local_res10 = 0;
  cVar3 = FseRemoveMessageContextFromPartitionQueueCommon(lVar2,param_1[2],param_3,&local_res10);
  if (cVar3 == '\0') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar5 = 0x12;
  }
  else {
    piVar4 = (int *)(local_res10 + 0x40);
    LOCK();
    iVar1 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      (**(code **)(local_res10 + 0x48))();
    }
    if (*(char *)(param_1 + 4) == '\0') {
      if (*(char *)(param_1 + 0xb) == '\0') {
        *param_1 = *(undefined8 *)(lVar2 + 0x48);
        *(undefined8 **)(lVar2 + 0x48) = param_1;
        LOCK();
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        UNLOCK();
        return;
      }
      return;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar5 = 0x13;
  }
  WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,param_1[2]);
  return;
}



===== OnCloseSocketComplete @ 14001c500 =====

void OnCloseSocketComplete(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  char cVar2;
  longlong lVar3;
  bool bVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 local_res8;
  
  bVar4 = false;
  local_res8 = 0;
  cVar2 = **(char **)(param_1 + 0x20);
  pcVar7 = *(char **)(param_1 + 0x20) + 0x20;
  pcVar8 = (char *)0x0;
  if (cVar2 == '\0') {
    pcVar8 = pcVar7;
  }
  pcVar7 = (char *)(-(ulonglong)(cVar2 != '\0') & (ulonglong)pcVar7);
  plVar1 = (longlong *)(pcVar8 + 0x88);
  pcVar9 = pcVar7 + 0xc;
  if (cVar2 == '\0') {
    local_res8 = ExAcquireSpinLockExclusive(*plVar1 + 0x50);
    pcVar9 = pcVar8 + 0x30;
  }
  uVar5 = ExAcquireSpinLockExclusive(pcVar9);
  if (cVar2 == '\0') {
    *(uint *)(pcVar8 + 0x10) = *(uint *)(pcVar8 + 0x10) | 0x10;
    lVar3 = *plVar1;
    pcVar8[0] = '\0';
    pcVar8[1] = '\0';
    pcVar8[2] = '\0';
    pcVar8[3] = '\0';
    pcVar8[4] = '\0';
    pcVar8[5] = '\0';
    pcVar8[6] = '\0';
    pcVar8[7] = '\0';
    pcVar8[0xc] = '\0';
    pcVar8[0xd] = '\0';
    pcVar8[0xe] = '\0';
    pcVar8[0xf] = '\0';
    pcVar8[0x14] = '\0';
    pcVar8[0x15] = '\0';
    pcVar8[0x16] = '\0';
    pcVar8[0x17] = '\0';
    if (pcVar8[0x20] == '\0') {
      bVar4 = false;
      if (pcVar8[8] == '\0') {
        bVar4 = true;
      }
    }
    else {
      KeSetEvent(pcVar8 + 0x90,0);
    }
    *(undefined4 *)(lVar3 + 0x488) = 0;
    *(undefined4 *)(lVar3 + 0x3c) = 0;
  }
  else {
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7[2] = '\0';
    pcVar7[3] = '\0';
    pcVar7[4] = '\0';
    pcVar7[5] = '\0';
    pcVar7[6] = '\0';
    pcVar7[7] = '\0';
    pcVar7[8] = '\0';
    if (pcVar7[9] != '\0') {
      ExReleaseSpinLockExclusive(pcVar9,uVar5);
      uVar6 = Feature_Servicing_FseUseAfterFreeFix__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar6 == 0) {
        FseFreeSocketOpContext(param_1);
        param_1 = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,*(undefined4 *)(param_2 + 0x30))
          ;
        }
        KeSetEvent(pcVar7 + 0x18,0,0);
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,*(undefined4 *)(param_2 + 0x30))
          ;
        }
        KeSetEvent(pcVar7 + 0x18,0,0);
        FseFreeSocketOpContext(param_1);
        param_1 = 0;
      }
      goto LAB_14001c701;
    }
  }
  ExReleaseSpinLockExclusive(pcVar9,uVar5);
  if (cVar2 == '\0') {
    ExReleaseSpinLockExclusive(*plVar1 + 0x50,local_res8);
  }
LAB_14001c701:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (cVar2 != '\0') {
      pcVar8 = pcVar7;
    }
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,pcVar8,(char)param_1,
               (char)*(undefined4 *)(param_2 + 0x30));
  }
  if (bVar4) {
    FseWskReconnectSocket(param_1);
  }
  else if (param_1 != 0) {
    FseFreeSocketOpContext(param_1);
  }
  return;
}



===== SendInvalidMessageTypeResponse @ 14001c77c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SendInvalidMessageTypeResponse
               (ulonglong param_1,uint param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  void *pvVar4;
  longlong lVar5;
  undefined1 auStackY_c8 [32];
  uint local_98;
  uint local_94;
  void *local_90;
  longlong local_88 [2];
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88[0] = 0;
  local_90 = (void *)0x0;
  local_98 = 0;
  uVar3 = 0;
  local_94 = 0;
  pvVar4 = (void *)0x0;
  lVar5 = 0;
  if (param_2 == 1) {
    local_88[1] = 0x1000;
    local_60 = 0;
    local_78 = 0xc00000bb;
    local_70 = 0;
    uStack_68 = 0;
    local_74 = param_4;
    iVar1 = FseMidlObjectEncode(param_1,local_88 + 1,(longlong *)&local_90,&local_98);
    pvVar4 = local_90;
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                 &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
      }
      pvVar4 = local_90;
    }
    else {
      uVar2 = FseGetCompleteMessage(1,param_3,local_90,local_98,local_88,&local_94);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                   &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,iVar1);
        }
      }
      else {
        lVar5 = local_88[0];
        uVar3 = local_94;
      }
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001c924;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_3a5f3f098c093d2b029563ca2977dda7_Traceguids,0xc000000d);
  }
  if (pvVar4 != (void *)0x0) {
    ExFreePoolWithTag(pvVar4,0x6c4d7346);
  }
  if (-1 < iVar1) {
    FseSendResponseMessage(param_1,param_3,(ulonglong)param_2,0x1000,lVar5,uVar3);
    return;
  }
LAB_14001c924:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,iVar1);
  }
  return;
}



===== SendInvalidVersionResponse @ 14001c978 =====

void SendInvalidVersionResponse(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  uint local_res8 [2];
  longlong local_res20;
  
  local_res20 = 0;
  local_res8[0] = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                    &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,param_1 + 0x18);
    }
  }
  else {
    iVar1 = FseCreateInvalidVersionMessage
                      (*(int *)(param_1 + 0x28),param_2,param_3,(int)param_3,&local_res20,local_res8
                      );
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,iVar1);
      }
    }
    else {
      FseSendResponseMessage
                (param_1,param_2,(ulonglong)*(uint *)(param_1 + 0x28),0x1001,local_res20,
                 local_res8[0]);
    }
  }
  return;
}



===== WPP_SF__guid_DDD @ 14001ca64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5)

{
  undefined4 local_18 [2];
  undefined4 local_10 [4];
  
  local_18[0] = 0x20;
  local_10[0] = 0x400;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,param_2,param_4,0x10,
             &param_5,4,local_10,4,local_18,4,0);
  return;
}



===== WPP_SF__guid_Di @ 14001cae4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_Di(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,0x10,&param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF__guid_dD @ 14001cb40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_dD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,0x16,param_4,0x10,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF__guid_dDi @ 14001cba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_dDi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,0x33,param_4,0x10,
             &param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF__guid_iq @ 14001cc10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_iq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,0x17,param_4,0x10,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_did @ 14001cc70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_did(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4bb1603e2f8e3099d0d01551e318f38a_Traceguids,0x11,local_res20,4,
             &param_5,8,&param_6,4,0);
  return;
}



===== MIDL_user_allocate @ 14001cce0 =====

void * __stdcall MIDL_user_allocate(size_t size)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,size,0x6c4d7346);
  if (((pvVar1 == (void *)0x0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_900a6ffcc86e3ff27f11ff41bfe144cb_Traceguids);
  }
  return pvVar1;
}



===== MIDL_user_free @ 14001cd50 =====

void __stdcall MIDL_user_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0x6c4d7346);
  }
  return;
}



===== FseProcessDecodedMessage @ 14001cd78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseProcessDecodedMessage(ulonglong param_1,longlong param_2,int *param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined8 uVar10;
  longlong *plVar11;
  int iVar12;
  undefined1 auStackY_e8 [32];
  undefined1 uVar13;
  uint local_88 [2];
  undefined8 local_80;
  ulonglong local_78;
  ulonglong local_70;
  uint local_68;
  longlong local_64;
  undefined8 uStack_5c;
  int local_54;
  uint local_50;
  int local_4c;
  uint local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_80 = *(ulonglong *)(param_1 + 0x68);
  local_70 = 0;
  local_88[0] = 0;
  iVar12 = 0;
  if (*(int *)(param_2 + 4) != 1) {
    return 0;
  }
  iVar4 = *param_3;
  uVar2 = *(undefined8 *)(param_2 + 8);
  uVar13 = (undefined1)uVar2;
  if (iVar4 == 0x1000) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0;
    }
    uVar7 = 0x13;
LAB_14001d25d:
    WPP_SF__guid_Di(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                    &WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,param_1 + 0x18,1,uVar13);
    return 0;
  }
  if (iVar4 == 0x1001) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0;
    }
    uVar7 = 0x14;
    goto LAB_14001d25d;
  }
  puVar8 = (undefined *)0x1;
  if (iVar4 == 0x1100) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar8 = &WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids;
      WPP_SF__guid_Di(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                      &WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,param_1 + 0x18,1,uVar13);
    }
    local_78 = 0;
    local_88[0] = 0;
    uVar3 = ExAcquireSpinLockExclusive(param_1 + 0x50);
    iVar4 = param_3[2];
    *(int *)(param_1 + 0x3c) = iVar4;
    *(int *)(param_1 + 0x28) = iVar4;
    *(uint *)(local_80 + 0x34) = *(uint *)(local_80 + 0x34) | 1;
    ExReleaseSpinLockExclusive(param_1 + 0x50,CONCAT31((int3)((uint)iVar4 >> 8),uVar3));
    iVar4 = FseCreateInitResponseMessage
                      (*(int *)(param_2 + 4),uVar2,puVar8,*(undefined4 *)(param_1 + 0x38),&local_78,
                       local_88);
    if (-1 < iVar4) {
      uVar10 = 0x2003;
      uVar6 = local_78;
      goto LAB_14001d12a;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0;
    }
    uVar7 = 0x12;
    goto LAB_14001d102;
  }
  if (iVar4 == 0x2000) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_Di(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                      &WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,param_1 + 0x18,1,uVar13);
    }
    uVar10 = 1;
    LOCK();
    *(longlong *)(param_1 + 0x78) = *(longlong *)(param_1 + 0x78) + 1;
    UNLOCK();
    local_54 = param_3[7];
    local_68 = param_3[6];
    uVar6 = (ulonglong)local_68;
    local_50 = param_3[8];
    local_78 = 0;
    plVar1 = (longlong *)(param_1 + 0x18);
    local_64 = *plVar1;
    uStack_5c = *(undefined8 *)(param_1 + 0x20);
    local_48 = FsePortTrackerGetDefaultSharingFlags(local_68);
    local_4c = (int)uVar10;
    plVar11 = (longlong *)(ulonglong)local_48;
    if ((int)uVar6 == local_4c) {
      local_4c = 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      plVar11 = plVar1;
      WPP_SF__guid_iddDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                         (ulonglong)*(ushort *)(param_3 + 8),uVar6,plVar1,
                         (char)*(undefined8 *)(param_2 + 8),(char)*(ushort *)(param_3 + 8),
                         (char)*(undefined2 *)((longlong)param_3 + 0x22),(char)uVar6,(char)local_48)
      ;
      uVar10 = 1;
    }
    local_80 = CONCAT44(local_50 >> 0x10,0xffff0001);
    uVar6 = FsePortTrackerAcquirePorts
                      (plVar1,&local_68,(byte)uVar10,plVar11,&local_78,(ushort *)&local_80);
    puVar9 = (undefined *)(uVar6 & 0xffffffff);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_DDDidiD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),local_80 >> 0x30,
                 (ulonglong)*(ushort *)((longlong)param_3 + 0x22),plVar1,(char)param_3[7],
                 (char)param_3[8],(char)*(ushort *)((longlong)param_3 + 0x22),
                 (char)*(undefined8 *)(param_2 + 8),(char)uVar6,(char)local_78,
                 (char)(local_80 >> 0x30));
    }
    iVar4 = FseCreatePortReserveResponseMessage
                      ((ulonglong)*(uint *)(param_2 + 4),uVar2,(uint)uVar6,local_78,local_80._6_2_,
                       &local_70,local_88);
    if (-1 < iVar4) {
      uVar10 = 0x2001;
      goto LAB_14001d11f;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar4;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar4;
    }
    uVar7 = 0xd;
  }
  else {
    if (iVar4 != 0x2002) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF__guid_Di(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                        &WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,param_1 + 0x18,1,uVar13);
      }
      SendInvalidMessageTypeResponse
                (param_1,*(uint *)(param_2 + 4),*(undefined8 *)(param_2 + 8),*param_3);
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar8 = &WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids;
      WPP_SF__guid_Di(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                      &WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,param_1 + 0x18,1,uVar13);
    }
    LOCK();
    *(longlong *)(param_1 + 0x80) = *(longlong *)(param_1 + 0x80) + 1;
    UNLOCK();
    uVar6 = *(ulonglong *)(param_3 + 6);
    uVar5 = FsePortTrackerReleasePortRange((longlong *)(param_1 + 0x18),uVar6,puVar8);
    puVar9 = (undefined *)(uVar5 & 0xffffffff);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_iid(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,puVar8,
                       (longlong *)(param_1 + 0x18),(char)*(undefined8 *)(param_2 + 8),
                       (char)*(undefined8 *)(param_3 + 6),(char)uVar5);
    }
    iVar4 = FseCreatePortReleaseResponseMessage
                      (*(int *)(param_2 + 4),uVar2,(uint)uVar5,&local_70,local_88);
    if (-1 < iVar4) {
      uVar10 = 0x2003;
LAB_14001d11f:
      uVar6 = local_70;
      iVar12 = iVar4;
LAB_14001d12a:
      FseSendResponseMessage
                (param_1,uVar2,(ulonglong)*(uint *)(param_2 + 4),uVar10,uVar6,local_88[0]);
      return iVar12;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar4;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar4;
    }
    uVar7 = 0x10;
  }
  puVar8 = puVar9;
  iVar12 = iVar4;
LAB_14001d102:
  WPP_SF__guid_di(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,puVar8,param_1 + 0x18,(char)iVar4
                  ,uVar13);
  return iVar12;
}



===== WPP_SF__guid_DDDidiD @ 14001d2ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_DDDidiD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,0xc,param_4,0x10,&param_5
             ,4,&param_6,4,&param_7,4,&param_8,8,&param_9,4,&param_10,8,&param_11,4,0);
  return;
}



===== WPP_SF__guid_di @ 14001d38c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_di(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,param_2,param_4,0x10,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF__guid_iddDD @ 14001d3ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_iddDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                       undefined1 param_9)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,0xb,param_4,0x10,&param_5
             ,8,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_SF__guid_iid @ 14001d47c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_iid(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_01777fb5b4f83990cc55290a4a7a6748_Traceguids,0xf,param_4,0x10,&param_5
             ,8,&param_6,8,&param_7,4,0);
  return;
}



===== __GSHandlerCheck @ 14001d4f8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001d51c =====

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



===== __cpu_features_init @ 14001d590 =====

/* WARNING: Removing unreachable block (ram,0x00014001d5fa) */
/* WARNING: Removing unreachable block (ram,0x00014001d5a9) */
/* WARNING: Removing unreachable block (ram,0x00014001d59a) */

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



===== __security_check_cookie @ 14001d660 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14001d6a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14001d6d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001d6d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14001d700 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 14001d760 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14001d7a3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14001d814;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14001d810:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001d814;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001d80c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001d810;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001d80c;
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
LAB_14001d814:
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
LAB_14001d7a3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 14001d880 =====

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



===== memset @ 14001db80 =====

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



===== __memset_repmovs @ 14001dcc0 =====

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



===== __memset_query @ 14001dd40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14001ddc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 14001df00 =====

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



===== __memset_spec_plain @ 14001df80 =====

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



===== FseMidlObjectDecode$filt$0 @ 14001e07d =====

void FseMidlObjectDecode_filt_0(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== FseMidlObjectEncode$filt$0 @ 14001e0a5 =====

void FseMidlObjectEncode_filt_0(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== WppCleanupKm @ 140030008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

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
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppInitKm @ 140030088 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
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
  }
  return;
}



===== WppLoadTracingSupport @ 140030118 =====

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



===== WppTraceCallback @ 140030260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,ulonglong param_3,uint *param_4,longlong param_5,
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
  uint uVar13;
  bool bVar14;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar1 = param_6;
  uVar6 = 0;
  *param_6 = 0;
  uVar11 = (uint)param_3;
  if (param_1 < 6) {
    if ((param_1 == 5) ||
       ((((param_1 != 0 && (param_1 != 1)) && (param_1 != 2)) && ((param_1 != 3 && (param_1 == 4))))
       )) {
      local_res8[0] = 0;
      param_6._0_4_ = 0;
      if (param_5 != 0) {
        if (uVar11 < 0x30) {
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
            *(undefined1 *)(param_5 + 0x29) = 0;
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
          }
          else {
            bVar14 = WPPTraceSuite == 2;
            uVar2 = *(undefined8 *)(param_4 + 2);
            *(undefined8 *)(param_5 + 0x18) = uVar2;
            if (bVar14) {
              iVar5 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
              if (iVar5 == 0) {
                *(undefined1 *)(param_5 + 0x29) = (undefined1)local_res8[0];
              }
              param_3 = 0;
              uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
            }
            else {
              uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
              *(undefined4 *)(param_5 + 0x2c) = uStack_34;
              uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
              *(undefined1 *)(param_5 + 0x29) = uStack_36;
            }
          }
          FseTraceEnableCallback
                    (*(undefined8 *)(param_5 + 8),*(ulonglong *)(param_5 + 0x18),
                     CONCAT71((int7)(param_3 >> 8),param_1 != 5),
                     (ulonglong)*(uint *)(param_5 + 0x2c),*(byte *)(param_5 + 0x29));
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
      uVar12 = uVar10 * 0x20 + 0x18;
      if (puVar3 == (ushort *)0x0) {
        uVar13 = uVar12;
        uVar12 = 0;
      }
      else {
        uVar13 = *puVar3 + 2 + uVar12;
      }
      if (uVar11 < uVar13) {
        if (uVar11 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar13;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,param_3 & 0xffffffff);
      *param_4 = uVar13;
      param_4[2] = uVar12;
      param_4[4] = uVar10;
      if (puVar3 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar12 + (longlong)param_4) = *puVar3;
        memmove((ushort *)((ulonglong)uVar12 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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
      *puVar1 = uVar13;
      return 0;
    }
  }
  return 0xc0000010;
}



===== wil_details_EvaluateFeatureDependencies @ 140030514 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014003054f;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_1400305c9:
  while( true ) {
    if (&UNK_1400297d7 < ppuVar3) {
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
      if (&UNK_1400297d7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014003054f:
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
      if (&UNK_1400297d7 < ppuVar2) goto LAB_1400305c9;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_1400305c9;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140030604 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14003069c;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14003069c;
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
LAB_14003069c:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400306f0 =====

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
              if (&UNK_1400297d7 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140030770 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14003086d;
  }
LAB_140030876:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14003086d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140030876;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14003083e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14003083e;
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
    if (&UNK_1400297d7 < ppuVar3) goto LAB_140030876;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14003086d;
}



===== FseIpsClientInitialize @ 14003089c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FseIpsClientInitialize(void)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  byte bVar7;
  byte *pbVar8;
  longlong *plVar9;
  ushort uVar10;
  undefined1 auStackY_b8 [32];
  byte local_88 [4];
  int local_84;
  longlong *local_80;
  undefined8 local_78 [4];
  byte *local_58;
  undefined8 local_50;
  longlong **local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_80 = (longlong *)0x0;
  uVar5 = FseAllocMemory(200,0x50497346,&local_80);
  plVar9 = local_80;
  iVar4 = (int)uVar5;
  bVar3 = true;
  if (iVar4 == 0) {
    *local_80 = 0;
    bVar7 = (byte)(DAT_14002a7d8 >> 1);
    *(byte *)(local_80 + 0x18) = bVar7 & 1 | *(byte *)(local_80 + 0x18) & 0xfe;
    if (5 < DAT_14002a000) {
      local_88[0] = bVar7 & 1;
      local_50 = 1;
      local_58 = local_88;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025c5c,0,0,3,local_78);
    }
    plVar1 = plVar9 + 0x16;
    uVar10 = 0;
    plVar9[0x17] = (longlong)plVar1;
    *plVar1 = (longlong)plVar1;
    do {
      lVar6 = IoAllocateWorkItem(FseGlobalContext);
      plVar9[((ulonglong)uVar10 + 1) * 5] = lVar6;
      if (lVar6 == 0) {
        iVar4 = -0x3fffff66;
        if (DAT_14002a000 < 3) goto LAB_140030aef;
        if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
          bVar2 = false;
        }
        if (!bVar2) goto LAB_140030aef;
        local_58 = (byte *)0x140021520;
        local_50 = 0x32;
        pbVar8 = &DAT_140025c2a;
        iVar4 = -0x3fffff66;
        goto LAB_140030ac0;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < 2);
    *(undefined2 *)(plVar9 + 1) = 2;
    *(undefined2 *)(plVar9 + 6) = 0x17;
    *(undefined4 *)(plVar9 + 0x10) = 1;
    *(undefined4 *)(plVar9 + 0x11) = 0;
    *(undefined4 *)(plVar9 + 0x13) = 1;
    DAT_14002a7b0 = plVar9;
    if ((*(byte *)(plVar9 + 0x18) & 1) != 0) {
      _DAT_14002a0f8 = &FseIpsClientTicket;
    }
    iVar4 = NmrRegisterClient(&FseNpiClientCharacteristics,plVar9);
    if (iVar4 < 0) {
      FseDiagnosticsLogFailure(6,iVar4);
    }
    else if (iVar4 == 0) {
      *(undefined1 *)(plVar9 + 0xb) = 1;
      plVar9 = (longlong *)0x0;
      local_80 = (longlong *)0x0;
      goto LAB_140030aef;
    }
    if (2 < DAT_14002a000) {
      if (((DAT_14002a010 & 4) == 0) || (bVar2 = true, (DAT_14002a018 & 4) != DAT_14002a018)) {
        bVar2 = false;
      }
      if (bVar2) {
        local_58 = (byte *)0x140021558;
        local_50 = 0x1a;
        pbVar8 = &DAT_140025bf8;
LAB_140030ac0:
        local_48 = (longlong **)&local_84;
        local_40 = 4;
        local_84 = iVar4;
        _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,pbVar8,0,0,4,local_78);
      }
    }
  }
LAB_140030aef:
  if (plVar9 != (longlong *)0x0) {
    FseIpsClientUninitialize(plVar9);
    FseFreeMemory((longlong *)&local_80);
  }
  if (iVar4 < 0) {
    if (DAT_14002a000 < 3) {
      return iVar4;
    }
    if (((CONCAT71(uRam000000014002a011,DAT_14002a010) & 0x400000000004) == 0) ||
       (bVar2 = true, (DAT_14002a018 & 0x400000000004) != DAT_14002a018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_58 = (byte *)&local_84;
      local_48 = &local_80;
      local_50 = 4;
      local_80 = (longlong *)0x1000000;
      local_40 = 8;
      local_84 = iVar4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025bb7,0,0,4,local_78);
    }
  }
  else if (iVar4 == 0) {
    return 0;
  }
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_50 = 0x26;
      local_58 = (byte *)0x140021578;
      local_48 = (longlong **)&local_84;
      local_40 = 4;
      local_84 = iVar4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140025b81,0,0,4,local_78);
    }
  }
  return iVar4;
}



===== FseIpsClientUninitialize @ 140030c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FseIpsClientUninitialize(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  int iVar7;
  undefined1 *puVar8;
  longlong lVar9;
  longlong *plVar10;
  char *pcVar11;
  longlong lVar12;
  longlong local_res8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  puVar8 = auStack_48;
  lVar9 = 2;
  if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
    plVar1 = param_1 + 0x16;
    while( true ) {
      plVar10 = param_1 + 3;
      plVar2 = (longlong *)*plVar1;
      puVar8 = auStack_48;
      if (plVar2 == plVar1) break;
      if (((longlong *)plVar2[1] != plVar1) ||
         (lVar12 = *plVar2, (longlong *)*(longlong *)(lVar12 + 8) != plVar2)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar8 = auStack_40;
        break;
      }
      plVar10 = param_1 + 3;
      *plVar1 = lVar12;
      *(longlong **)(lVar12 + 8) = plVar1;
      pcVar11 = (char *)((longlong)plVar2 + 0x14);
      lVar12 = 2;
      local_res8 = (longlong)plVar2;
      do {
        if ((*(char *)((longlong)plVar10 + -0xe) == '\x01') && (*pcVar11 == '\x01')) {
          (**(code **)(*plVar10 + 0x10))(plVar10[-1],plVar2[4],*(undefined4 *)(plVar2 + 3));
        }
        plVar10 = plVar10 + 5;
        pcVar11 = pcVar11 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      FseFreeMemory(&local_res8);
    }
    lVar12 = 2;
    pcVar11 = (char *)((longlong)param_1 + 0x84);
    do {
      if ((*(char *)((longlong)plVar10 + -0xe) == '\x01') && (*pcVar11 == '\x01')) {
        lVar6 = param_1[0x11];
        lVar3 = param_1[0x12];
        lVar4 = plVar10[-1];
        pcVar5 = *(code **)(*plVar10 + 0x10);
        *(undefined8 *)(puVar8 + -8) = 0x140030d30;
        (*pcVar5)(lVar4,lVar3,(int)lVar6);
      }
      plVar10 = plVar10 + 5;
      pcVar11 = pcVar11 + 1;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
  }
  if ((char)param_1[0xb] != '\0') {
    lVar12 = param_1[0xc];
    *(undefined8 *)(puVar8 + -8) = 0x140030d4e;
    iVar7 = NmrDeregisterClient(lVar12);
    if (iVar7 != 0x103) {
      *(undefined8 *)(puVar8 + -8) = 0x140030d5f;
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    lVar12 = param_1[0xc];
    *(undefined8 *)(puVar8 + -8) = 0x140030d6a;
    iVar7 = NmrWaitForClientDeregisterComplete(lVar12);
    if (iVar7 != 0) {
      *(undefined8 *)(puVar8 + -8) = 0x140030d78;
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
  }
  do {
    param_1 = param_1 + 5;
    if (*param_1 != 0) {
      *(undefined8 *)(puVar8 + -8) = 0x140030d8b;
      IoFreeWorkItem();
      *param_1 = 0;
    }
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  return;
}



===== FseNpiClientDetachProviderCompleteWorkerRoutine @ 140030dd0 =====

void FseNpiClientDetachProviderCompleteWorkerRoutine(undefined8 param_1,longlong param_2)

{
  if (param_2 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *(undefined1 *)(param_2 + 2) = 0;
  NmrClientDetachProviderComplete(*(undefined8 *)(param_2 + 0x18));
  return;
}



===== CancelTimerCallbacksAndDeleteTimer @ 140030e04 =====

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



===== CreateTlgAggregateSession @ 140030e94 =====

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



===== DestroyAggregateSession @ 140030fec =====

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



===== FlushEventEntryList @ 140031038 =====

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



===== LookUpTableFlushComplete @ 1400310d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

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
      if (((5 < DAT_14002a040) && ((DAT_14002a050 & 0x200000000000) != 0)) &&
         ((DAT_14002a058 & 0x200000000000) == DAT_14002a058)) {
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
                  (p_Var5,&DAT_140027acf,(_GUID *)(ulonglong)uVar4,(_GUID *)(ulonglong)uVar3,
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



===== LookUpTableFlushPartial @ 1400314c0 =====

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



===== TlgAggregateInternalFlushWorkItemRoutineKernelMode @ 140031570 =====

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



===== TlgAggregateInternalProviderCallback @ 140031600 =====

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
     (cVar1 = ExTryAcquirePushLockExclusiveEx(&DAT_14002a458,0), cVar1 != '\0')) {
    for (lVar2 = DAT_14002a460; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x160)) {
      LookUpTableFlushComplete(lVar2);
    }
    ExReleasePushLockExclusiveEx(&DAT_14002a458,0);
  }
  return;
}



===== TlgAggregateInternalRegisteredProviderEtwCallback @ 140031670 =====

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



===== TlgRegisterAggregateProviderEx @ 1400316ec =====

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
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                      (0x14002a000,FseDiagnosticsTlgCallback,0);
  }
  else {
    *(undefined8 *)((longlong)pvVar2 + 0x150) = 0;
    local_38[0] = 0;
    *(code **)((longlong)pvVar2 + 0x148) = FseDiagnosticsTlgCallback;
    *(undefined4 **)((longlong)pvVar2 + 0x158) = &DAT_14002a000;
    *(undefined1 *)((longlong)pvVar2 + 0x175) = 0;
    local_28 = *(undefined8 *)(PTR_DAT_14002a008 + -0x10);
    uStack_20 = *(undefined8 *)(PTR_DAT_14002a008 + -8);
    local_30 = (ulonglong)pvVar2 >> 4;
    RunningHash(local_38,(longlong)&local_28,0x10);
    RunningHash(local_38,(longlong)&local_30,8);
    FinishHash((int *)local_38);
    *(uint *)((longlong)pvVar2 + 0x170) = local_38[0] % 600000 + 600000;
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                      (0x14002a000,TlgAggregateInternalRegisteredProviderEtwCallback,pvVar2);
    if (iVar1 < 0) {
      DAT_14002a028 = 0;
      DestroyAggregateSession((longlong)pvVar2);
    }
    else {
      ExAcquirePushLockExclusiveEx(&DAT_14002a458,0);
      if (DAT_14002a460 == 0) {
        TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                  (0x14002a040,TlgAggregateInternalProviderCallback,0);
      }
      plVar4 = &DAT_14002a460;
      lVar3 = DAT_14002a460;
      while (lVar3 != 0) {
        if (*(undefined4 **)(lVar3 + 0x158) == &DAT_14002a000) goto LAB_140031853;
        plVar4 = (longlong *)(lVar3 + 0x160);
        lVar3 = *plVar4;
      }
      *plVar4 = (longlong)pvVar2;
LAB_140031853:
      ExReleasePushLockExclusiveEx(&DAT_14002a458,0);
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1400318a4 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x140031905;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140031925;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140031939;
  return iVar6;
}



===== _tlgEnableCallback @ 140031950 =====

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



===== FseNpiNduClientDetachProviderCompleteWorkerRoutine @ 1400319d0 =====

void FseNpiNduClientDetachProviderCompleteWorkerRoutine(undefined1 *param_1)

{
  if (param_1 == (undefined1 *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  if (*(longlong *)(param_1 + 0x18) == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *param_1 = 0;
  NmrClientDetachProviderComplete(*(undefined8 *)(param_1 + 0x18));
  return;
}



===== FseNpiNduClientInitialize @ 140031a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FseNpiNduClientInitialize(longlong *param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 auStackY_a8 [32];
  longlong local_78 [2];
  undefined8 local_68 [4];
  char *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (param_1 == (longlong *)0x0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  *param_1 = 0;
  local_78[0] = 0;
  uVar4 = FseAllocMemory(0x70,0x644e7346,local_78);
  lVar5 = local_78[0];
  iVar3 = (int)uVar4;
  bVar1 = true;
  if (iVar3 == 0) {
    *(undefined8 *)(local_78[0] + 0x20) = 0;
    *(code **)(local_78[0] + 0x30) = FseNpiNduClientDetachProviderCompleteWorkerRoutine;
    *(longlong *)(local_78[0] + 0x38) = local_78[0];
    iVar3 = NmrRegisterClient(&g_FseNpiClientNmrCharacteristics,local_78[0]);
    if (iVar3 == 0) {
      *(undefined1 *)(lVar5 + 0x40) = 1;
      *param_1 = lVar5;
      lVar5 = 0;
      local_78[0] = 0;
    }
  }
  if (lVar5 != 0) {
    FseNpiNduClientUninitialize(lVar5);
    FseFreeMemory(local_78);
  }
  if (iVar3 < 0) {
    if (DAT_14002a000 < 3) {
      return iVar3;
    }
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) goto LAB_140031b59;
    local_3c = 0;
    local_38 = local_78;
    local_2c = 0;
    local_48 = "FseNpiNduClientInitialize returned error";
    local_40 = 0x29;
    local_78[0] = CONCAT44(local_78[0]._4_4_,iVar3);
    local_30 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_1400279f7,0,0,4,local_68);
  }
  else if (iVar3 == 0) {
    return 0;
  }
LAB_140031b59:
  if (2 < DAT_14002a000) {
    if (((DAT_14002a010 & 4) == 0) || ((DAT_14002a018 & 4) != DAT_14002a018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_3c = 0;
      local_38 = local_78;
      local_2c = 0;
      local_48 = "FseNpiNduClientInitialize returned error";
      local_40 = 0x29;
      local_78[0] = CONCAT44(local_78[0]._4_4_,iVar3);
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x14002a000,&DAT_140027a2d,0,0,4,local_68);
    }
  }
  return iVar3;
}



===== FseNpiNduClientUninitialize @ 140031bf4 =====

void FseNpiNduClientUninitialize(longlong param_1)

{
  int iVar1;
  longlong local_res8 [4];
  
  if (param_1 == 0) {
    MicrosoftTelemetryAssertTriggeredNoArgsKM();
  }
  else {
    local_res8[0] = param_1;
    if (*(char *)(param_1 + 0x40) != '\0') {
      iVar1 = NmrDeregisterClient(*(undefined8 *)(param_1 + 0x48));
      if (iVar1 != 0x103) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      iVar1 = NmrWaitForClientDeregisterComplete(*(undefined8 *)(param_1 + 0x48));
      if (iVar1 != 0) {
        MicrosoftTelemetryAssertTriggeredNoArgsKM();
      }
      *(undefined1 *)(param_1 + 0x40) = 0;
    }
    FseFreeMemory(local_res8);
  }
  return;
}



===== entry @ 140032010 =====

void entry(undefined8 *param_1,undefined8 param_2,undefined8 *param_3,ulonglong param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 140032044 =====

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



===== wil_InitializeFeatureStaging @ 140032078 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400320ff;
    }
LAB_140032139:
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
LAB_1400320ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140032139;
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
    goto LAB_140032139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400297d7 < ppuVar3) goto LAB_140032139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400320ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14003218c =====

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
            if (&UNK_1400297d7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140032276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140032276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140032276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400297d7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


