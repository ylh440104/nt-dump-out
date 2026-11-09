
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
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140006080,param_2,0,0,0x2b,local_2c8);
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



===== TlDefaultRequestQueryDispatchEndpoint @ 140001510 =====

void TlDefaultRequestQueryDispatchEndpoint(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlDefaultRequestQueryDispatchEndpoint();
  return;
}



===== TlDefaultRequestResume @ 140001530 =====

void TlDefaultRequestResume(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlDefaultRequestResume();
  return;
}



===== TlDefaultRequestMessage @ 140001550 =====

void TlDefaultRequestMessage(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlDefaultRequestMessage();
  return;
}



===== TlDefaultRequestQueryDispatch @ 140001570 =====

void TlDefaultRequestQueryDispatch(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001570. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlDefaultRequestQueryDispatch();
  return;
}



===== AfUnixTlConnectEndpointSend @ 140001590 =====

int AfUnixTlConnectEndpointSend
              (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 **param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar1,0,0);
  }
  if ((*(uint *)(param_2 + 3) & 1) == 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 8,0);
    if ((*(int *)(param_1 + 0x100) == 4) || (*(int *)(param_1 + 0x100) == 7)) {
      iVar2 = 0;
    }
    else if ((*(uint *)(param_1 + 0x104) & 4) == 0) {
      iVar2 = (-(uint)((*(uint *)(param_1 + 0x104) & 8) != 0) & 0xbd) + 0xc0000184;
    }
    else {
      iVar2 = -0x3ffffdf3;
    }
    ExReleasePushLockExclusiveEx(param_1 + 8,0);
    KeLeaveCriticalRegion();
    if (iVar2 < 0) {
      pcVar4 = "[0x%08x] Endpoint cannot process request\n";
      uVar3 = 0x581;
    }
    else {
      iVar2 = AfUnixDeliverEndpointSend(param_1,param_2,param_3,param_4);
      if (-1 < iVar2) {
        return iVar2;
      }
      pcVar4 = "[0x%08x] AfUnixDeliverEndpointSend\n";
      uVar3 = 0x58b;
    }
    AfUnixTraceLogging(2,"AfUnixTlConnectEndpointSend",uVar3,pcVar4,(char)iVar2);
  }
  else {
    iVar2 = -0x3ffffff3;
    AfUnixTraceLogging(2,"AfUnixTlConnectEndpointSend",0x55c,"[0x%08x] Invalid send flag: 0x%x\n",
                       '\r');
  }
  return iVar2;
}



===== AfUnixDeliverCancelPendingIo @ 1400016ec =====

void AfUnixDeliverCancelPendingIo(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  
  if ((*(uint *)(param_1 + 0x1c0) & 2) == 0) {
    puVar1 = *(undefined8 **)(param_1 + 400);
    if (puVar1 != (undefined8 *)0x0) {
      *(uint *)(param_1 + 0x1c0) = *(uint *)(param_1 + 0x1c0) | 2;
      do {
        *(undefined8 *)(param_1 + 400) = 0;
        *(undefined8 *)(param_1 + 0x198) = 0;
        ExReleasePushLockExclusiveEx(param_1 + 8,0);
        KeLeaveCriticalRegion();
        AfUnixDeliverCompleteReceiveRequests(puVar1,param_2);
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(param_1 + 8);
        puVar1 = *(undefined8 **)(param_1 + 400);
      } while (puVar1 != (undefined8 *)0x0);
      *(uint *)(param_1 + 0x1c0) = *(uint *)(param_1 + 0x1c0) & 0xfffffffd;
    }
  }
  else {
    *(uint *)(param_1 + 0x1c4) = *(uint *)(param_1 + 0x1c4) | 4;
    *(undefined4 *)(param_1 + 0x1d0) = param_2;
  }
  return;
}



===== wil_details_RecordCachedUsage @ 1400017b8 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001910 =====

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



===== _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv @ 140001994 =====

void _tlgDefineProvider_annotation__TlgTlgAggregateInternalProviderProv(void)

{
  return;
}



===== CreateNewEventEntry @ 1400019a0 =====

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
  } while (bVar11 < 5);
  if ((ulonglong)(lVar3 + lVar6) < 0x10000) {
    _Size = lVar6 + 0x7e;
    if ((_Size == 0) ||
       (puVar5 = (undefined8 *)
                 ExAllocatePoolWithTag
                           ((-(uint)(param_1 != '\0') & 0xfffffe01) + 0x200,_Size,0x47417254),
       puVar5 == (undefined8 *)0x0)) {
      uVar4 = 0xc0000017;
    }
    else {
      memset(puVar5,0,_Size);
      if (_Size < 0x50) {
        puVar14 = (undefined8 *)0x0;
        puVar7 = puVar5;
      }
      else {
        _Size = lVar6 + 0x2e;
        puVar7 = puVar5 + 10;
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
      *(undefined1 *)((longlong)puVar8 + 0x2c) = 5;
      *(undefined4 *)(puVar8 + 5) = param_6;
      *puVar8 = uVar4;
      puVar8[1] = uVar2;
      if (bVar11 < 5) {
        lVar6 = -param_4;
        uVar13 = (ulonglong)(byte)(5 - bVar11);
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



===== DestroyEventEntry @ 140001bf0 =====

void DestroyEventEntry(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0);
  }
  return;
}



===== EnableFlushTimer @ 140001c18 =====

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



===== FinishHash @ 140001c74 =====

void FinishHash(int *param_1)

{
  *param_1 = ((uint)(*param_1 * 9) >> 0xb ^ *param_1 * 9) * 0x8001;
  return;
}



===== FlushLookUpTableBucket @ 140001c90 =====

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



===== InsertEventEntryInLookUpTable @ 140001da4 =====

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
  
  lVar8 = DAT_140006078;
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
  if ((byte)uVar16 < 5) {
    plVar14 = (longlong *)((ulonglong)(uVar16 & 0xff) * 0x10 + param_4);
    uVar19 = (ulonglong)(byte)(5 - (byte)uVar16);
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
      goto LAB_140001f6f;
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
LAB_140001f6f:
  plVar14 = (longlong *)(lVar8 + (ulonglong)(uVar12 & 0x1f) * 8);
  do {
    if (*plVar14 == 0) {
      if (0x3ff < *(uint *)(lVar8 + 0x100)) {
        *(int *)(lVar8 + 0x13c) = *(int *)(lVar8 + 0x13c) + 1;
        local_res8 = 0xc0000023;
        goto LAB_1400021a2;
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
          goto LAB_1400021a2;
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
        goto LAB_1400021a2;
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
          if (4 < uVar16) {
            lVar13 = *plVar14;
            goto LAB_14000206c;
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
LAB_14000206c:
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
LAB_1400021a2:
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



===== RunningHash @ 14000221c =====

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



===== TlgAggregateInternalFlushTimerCallbackKernelMode @ 140002250 =====

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



===== _tlgWriteAgg @ 140002294 =====

ulonglong _tlgWriteAgg(undefined8 param_1,byte *param_2,ulonglong param_3,undefined8 param_4,
                      undefined8 *param_5)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined7 uVar7;
  byte bVar8;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_5 = PTR_DAT_140006050;
  *(uint *)(param_5 + 1) = (uint)*(ushort *)PTR_DAT_140006050;
  *(undefined4 *)((longlong)param_5 + 0xc) = 2;
  param_5[2] = param_2 + 0xb;
  *(uint *)(param_5 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_5 + 0x1c) = 1;
  uVar4 = 0xc000000d;
  if (DAT_140006070 == TlgAggregateInternalRegisteredProviderEtwCallback) {
    lVar3 = param_5[2];
    bVar8 = 0;
    uVar2 = *(uint *)(param_5 + 3);
    pcVar5 = (char *)(lVar3 + 2);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 < '\0');
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    while (pcVar5 < (char *)((ulonglong)uVar2 + lVar3)) {
      do {
        pcVar6 = pcVar5;
        pcVar5 = pcVar6 + 1;
      } while (*pcVar6 != '\0');
      cVar1 = *pcVar5;
      uVar7 = (undefined7)(param_3 >> 8);
      param_3 = CONCAT71(uVar7,cVar1);
      if (-1 < cVar1) break;
      param_3 = CONCAT71(uVar7,cVar1) & 0xffffffffffffff7f;
      pcVar5 = pcVar6 + 3;
      if (-1 < pcVar6[2]) break;
      for (; cVar1 = *pcVar5, cVar1 < '\0'; pcVar5 = pcVar5 + 1) {
        if (cVar1 != -0x80) goto LAB_14000239c;
      }
      if (((char)param_3 != '\t') || (2 < (byte)(cVar1 + 0x8fU))) break;
      uVar4 = (ulonglong)bVar8;
      bVar8 = bVar8 + 1;
      *(char *)((longlong)param_5 + uVar4 * 0x10 + 0x2d) = cVar1;
    }
LAB_14000239c:
    if (bVar8 == 0) {
      uVar4 = EtwWriteTransfer(DAT_140006068,&local_18,0,0,5,param_5);
    }
    else {
      uVar4 = InsertEventEntryInLookUpTable
                        (pcVar5,(undefined8 *)&local_18,param_3,(longlong)param_5,bVar8);
    }
  }
  return uVar4;
}



===== _guard_check_icall @ 1400023f0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002408 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000242c =====

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



===== __cpu_features_init @ 1400024a0 =====

/* WARNING: Removing unreachable block (ram,0x00014000250a) */
/* WARNING: Removing unreachable block (ram,0x0001400024b9) */
/* WARNING: Removing unreachable block (ram,0x0001400024aa) */

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



===== __security_check_cookie @ 140002570 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400025b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400025e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400025e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002610 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140002660 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1400026a3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140002714;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140002710:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140002714;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000270c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140002710;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000270c;
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
LAB_140002714:
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
LAB_1400026a3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140002780 =====

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



===== memset @ 140002a80 =====

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



===== __memset_repmovs @ 140002bc0 =====

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



===== __memset_query @ 140002c40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002cc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002e00 =====

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



===== __memset_spec_plain @ 140002e80 =====

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



===== AfUnixAddressCompare @ 140009008 =====

ulonglong AfUnixAddressCompare(ulonglong param_1,longlong param_2)

{
  if (param_1 < *(ulonglong *)(param_2 + 0x18)) {
    return 0xffffffff;
  }
  return (ulonglong)(param_1 != *(ulonglong *)(param_2 + 0x18));
}



===== AfUnixAddressCreateFile @ 140009028 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AfUnixAddressCreateFile
              (longlong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined4 param_5,longlong *param_6,longlong *param_7)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  short sVar5;
  longlong lVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined1 auStackY_158 [32];
  longlong *plVar9;
  undefined1 local_108 [8];
  undefined2 *local_100;
  longlong local_f8;
  longlong local_f0;
  longlong local_e8 [7];
  undefined8 local_b0;
  longlong *local_a8;
  undefined8 uStack_a0;
  longlong local_98;
  undefined8 local_90;
  longlong lStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_158;
  local_a8 = param_7;
  local_e8[5] = local_e8[5] & 0xffffffffffff0000;
  local_80 = 0;
  uStack_78 = 0;
  local_100 = (undefined2 *)0x0;
  bVar2 = false;
  local_70 = 0;
  uStack_68 = 0;
  local_f0 = 0;
  puVar4 = (undefined4 *)0x0;
  local_60 = 0;
  uStack_58 = 0;
  local_f8 = 0;
  local_e8[1] = 0;
  local_e8[2] = 0;
  local_e8[0] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_90 = 0;
  lStack_88 = 0;
  local_e8[6] = param_4;
  local_b0 = param_3;
  local_98 = PsGetCurrentProcess();
  if (param_1 != local_98) {
    KeStackAttachProcess(param_1,&local_80);
  }
  sVar5 = (*param_2 >> 1) - 1;
  lVar6 = 0;
  if (-1 < sVar5) {
    do {
      sVar1 = *(short *)(*(longlong *)(param_2 + 4) + (longlong)sVar5 * 2);
      if (sVar1 == 0x3a) {
        iVar3 = -0x3ffffebf;
        goto LAB_140009333;
      }
    } while ((sVar1 != 0x5c) && (sVar5 = sVar5 + -1, -1 < sVar5));
  }
  puVar4 = (undefined4 *)ExAllocatePool2(0x100,0x18,0x69706e57);
  if (puVar4 == (undefined4 *)0x0) {
    iVar3 = -0x3fffffe9;
LAB_140009333:
    bVar2 = false;
  }
  else {
    *puVar4 = 0x80000023;
    *(undefined2 *)(puVar4 + 1) = 0;
    iVar3 = FsRtlAllocateExtraCreateParameterList(0,&local_f0);
    if (iVar3 < 0) {
      pcVar8 = "[0x%08x] FsRtlAllocateExtraCreateParameterList\n";
      uVar7 = 0xdc;
    }
    else {
      iVar3 = FsRtlAllocateExtraCreateParameter(&GUID_ECP_ATOMIC_CREATE,0x58,0);
      if (iVar3 < 0) {
        pcVar8 = "[0x%08x] FsRtlAllocateExtraCreateParameter\n";
        uVar7 = 0xe9;
      }
      else {
        bVar2 = true;
        memset(local_100,0,0x58);
        *local_100 = 0x58;
        local_100[1] = 2;
        *(undefined4 **)(local_100 + 4) = puVar4;
        local_100[3] = 0x18;
        iVar3 = FsRtlInsertExtraCreateParameter(local_f0,local_100);
        if (-1 < iVar3) {
          local_e8[2] = local_f0;
          local_e8[1] = 0x28;
          bVar2 = false;
          local_e8[5] = 1;
          plVar9 = local_e8 + 1;
          local_e8[3] = 0;
          local_e8[4] = 0;
          iVar3 = AfUnixAddressOpenFileInternal
                            (param_2,local_b0,0x10002,2,(longlong)plVar9,local_e8[6],param_5,
                             &local_f8,local_e8,&local_90);
          if (iVar3 < 0) {
            AfUnixTraceLogging(2,"AfUnixAddressCreateFile",0x10d,
                               "[0x%08x] AfUnixAddressOpenFileInternal\n",(char)iVar3);
            lVar6 = local_e8[0];
            goto LAB_140009339;
          }
          if ((*(byte *)(local_100 + 2) & 2) == 0) {
            AfUnixTraceLogging(3,"AfUnixAddressCreateFile",0x11b,
                               "IO_REPARSE_TAG_AF_UNIX reparse point not set\n",(char)plVar9);
          }
          *param_6 = local_f8;
          local_f8 = 0;
          *local_a8 = local_e8[0];
          goto LAB_140009333;
        }
        pcVar8 = "[0x%08x] FsRtlInsertExtraCreateParameter\n";
        uVar7 = 0xf5;
      }
    }
    AfUnixTraceLogging(2,"AfUnixAddressCreateFile",uVar7,pcVar8,(char)iVar3);
  }
LAB_140009339:
  if (local_f0 != 0) {
    FsRtlFreeExtraCreateParameterList();
  }
  if (bVar2) {
    FsRtlFreeExtraCreateParameter(&local_100);
  }
  if (local_f8 != 0) {
    if ((iVar3 < 0) && (lStack_88 == 2)) {
      local_108[0] = 1;
      local_a8 = (longlong *)0x0;
      uStack_a0 = 0;
      ZwSetInformationFile(local_f8,&local_a8,local_108,1);
    }
    ZwClose(local_f8);
  }
  if (lVar6 != 0) {
    ObfDereferenceObject(lVar6);
  }
  if (puVar4 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar4,0);
  }
  if (param_1 != local_98) {
    KeUnstackDetachProcess(&local_80);
  }
  return iVar3;
}



===== AfUnixAddressGetSize @ 140009424 =====

longlong AfUnixAddressGetSize(longlong param_1)

{
  char *pcVar1;
  longlong lVar2;
  
  pcVar1 = (char *)(param_1 + 2);
  if ((*pcVar1 != '\0') && (pcVar1 != (char *)0x0)) {
    lVar2 = 0x6c;
    do {
      if (*pcVar1 == '\0') break;
      pcVar1 = pcVar1 + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
    if (lVar2 != 0) {
      return (-(ulonglong)(lVar2 != 0) & 0x6cU - lVar2) + 3;
    }
  }
  return 0x6e;
}



===== AfUnixAddressInsert @ 140009470 =====

undefined8 AfUnixAddressInsert(longlong param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  
  uVar3 = *(ulonglong *)(param_3 + 0x28);
  if (uVar3 == 0) {
    uVar3 = *(ulonglong *)(param_3 + 0x18);
  }
  plVar4 = *(longlong **)(param_1 + 0x18);
  uVar5 = 0;
  if (plVar4 != (longlong *)0x0) {
    do {
      uVar1 = AfUnixAddressCompare(uVar3,(longlong)plVar4);
      if ((int)uVar1 < 1) {
        if (-1 < (int)uVar1) {
          AfUnixTraceLogging(2,"AfUnixAddressInsert",0x1fd,"[0x%08x] Address already exists\n",'\n')
          ;
          return 0xc000020a;
        }
        plVar2 = (longlong *)*plVar4;
        if (plVar2 == (longlong *)0x0) {
          uVar5 = 0;
          break;
        }
      }
      else {
        plVar2 = (longlong *)plVar4[1];
        if (plVar2 == (longlong *)0x0) goto code_r0x0001400094c2;
      }
      plVar4 = plVar2;
    } while( true );
  }
LAB_1400094c5:
  RtlRbInsertNodeEx(param_1 + 0x18,plVar4,uVar5,param_2 + 0xb0);
  *(ulonglong *)(param_2 + 200) = uVar3;
  return 0;
code_r0x0001400094c2:
  uVar5 = 1;
  goto LAB_1400094c5;
}



===== AfUnixAddressOpenFile @ 140009548 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AfUnixAddressOpenFile
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              longlong *param_5)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_d8 [32];
  longlong local_88;
  longlong local_80 [11];
  
  local_80[9] = __security_cookie ^ (ulonglong)auStackY_d8;
  local_80[0] = 0;
  local_88 = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[7] = 0;
  local_80[8] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  lVar2 = PsGetCurrentProcess();
  if (param_1 != lVar2) {
    KeStackAttachProcess(param_1,local_80 + 3);
  }
  iVar1 = AfUnixAddressOpenFileInternal(param_2,param_3,2,1,0,0,0,local_80,&local_88,local_80 + 1);
  if (iVar1 < 0) {
    AfUnixTraceLogging(2,"AfUnixAddressOpenFile",0x2f8,"[0x%08x] AfUnixAddressOpenFileInternal\n",
                       (char)iVar1);
    lVar3 = local_88;
  }
  else {
    *param_5 = local_88;
    lVar3 = 0;
  }
  if (local_80[0] != 0) {
    ZwClose();
  }
  if (lVar3 != 0) {
    ObfDereferenceObject(lVar3);
  }
  if (param_1 != lVar2) {
    KeUnstackDetachProcess(local_80 + 3);
  }
  return iVar1;
}



===== AfUnixAddressOpenFileInternal @ 1400096a4 =====

int AfUnixAddressOpenFileInternal
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
              longlong param_5,undefined8 param_6,undefined4 param_7,undefined8 *param_8,
              undefined8 *param_9,undefined8 *param_10)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  ulonglong in_stack_ffffffffffffff70;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  puVar3 = param_10;
  puVar1 = param_8;
  local_1c = 0;
  local_38 = 0x30;
  local_20 = (-(uint)(param_5 != 0) & 0xfffffc00) + 0x600;
  *param_10 = 0;
  param_10[1] = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_2;
  local_28 = param_1;
  iVar4 = IoCreateFileEx(param_8,param_3,&local_38,param_10,0,
                         in_stack_ffffffffffffff70 & 0xffffffff00000000,7,param_4,0x204040,param_6,
                         param_7,0,0,0x101,param_5);
  puVar2 = param_9;
  if (iVar4 < 0) {
    if (iVar4 == -0x3fffffcb) {
      iVar4 = -0x3ffffdf6;
    }
    if (puVar3[1] == 5) {
      iVar4 = -0x3fffffcc;
    }
    AfUnixTraceLogging(2,"AfUnixAddressOpenFileInternal",0x394,"[0x%08x] IoCreateFileEx\n",
                       (char)iVar4);
  }
  else if (param_9 != (undefined8 *)0x0) {
    param_5 = 0;
    ObReferenceObjectByHandle(*puVar1,0,*(undefined8 *)IoFileObjectType_exref,0,&param_5,0);
    *puVar2 = param_5;
  }
  return iVar4;
}



===== AfUnixAddressReferenceEndpoint @ 140009818 =====

ulonglong * AfUnixAddressReferenceEndpoint(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  code *pcVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 unaff_RDI;
  ulonglong *puVar6;
  bool bVar7;
  char cVar8;
  
  uVar3 = *(ulonglong *)(param_2 + 0x28);
  puVar6 = (ulonglong *)0x0;
  if (uVar3 == 0) {
    uVar3 = *(ulonglong *)(param_2 + 0x18);
  }
  puVar5 = *(undefined8 **)(param_1 + 0x18);
  while (cVar8 = (char)unaff_RDI, puVar5 != (undefined8 *)0x0) {
    uVar4 = AfUnixAddressCompare(uVar3,(longlong)puVar5);
    cVar8 = (char)unaff_RDI;
    if ((int)uVar4 < 0) {
      puVar5 = (undefined8 *)*puVar5;
    }
    else {
      if ((int)uVar4 < 1) break;
      puVar5 = (undefined8 *)puVar5[1];
    }
  }
  if (puVar5 == (undefined8 *)0x0) {
    AfUnixTraceLogging(2,"AfUnixAddressReferenceEndpoint",0x23d,"RtlTreeFindNode\n",cVar8);
  }
  else {
    puVar6 = puVar5 + -0x16;
    uVar3 = *puVar6;
    do {
      uVar4 = uVar3 + 1;
      if (uVar4 < 2) {
        if (uVar4 != 1) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(0xe);
        }
        return (ulonglong *)0x0;
      }
      LOCK();
      uVar1 = *puVar6;
      bVar7 = uVar3 == uVar1;
      if (bVar7) {
        *puVar6 = uVar4;
      }
      else {
        uVar3 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return puVar6;
}



===== AfUnixBaseEndpointDisassociateAndAssociateOther @ 1400098cc =====

void AfUnixBaseEndpointDisassociateAndAssociateOther
               (longlong param_1,longlong param_2,longlong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_2 + 8,0);
  uVar1 = *(undefined4 *)(param_2 + 0x2c);
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  uVar3 = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_3 + 0x2c) = uVar1;
  *(undefined4 *)(param_3 + 0x30) = uVar2;
  *(undefined4 *)(param_3 + 0x34) = uVar3;
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined8 *)(param_2 + 0x30) = 0;
  *(undefined2 *)(param_2 + 0x2a) = 0;
  *(undefined8 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_3 + 0xa8) = *(undefined8 *)(param_2 + 0xa8);
  *(undefined8 *)(param_2 + 0xa8) = 0;
  *(undefined8 *)(param_3 + 0x20) = *(undefined8 *)(param_2 + 0x20);
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined1 *)(param_3 + 0xe0) = 1;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  *(undefined1 *)(param_2 + 0xe0) = 0;
  if (*(longlong *)(param_3 + 0xa8) != 0) {
    RtlRbReplaceNode(param_1 + 0x18,param_2 + 0xb0,param_3 + 0xb0);
    *(undefined8 *)(param_3 + 200) = *(undefined8 *)(param_2 + 200);
    *(undefined8 *)(param_2 + 200) = 0;
  }
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  KeLeaveCriticalRegion();
  ExReleasePushLockExclusiveEx(param_2 + 8,0);
  KeLeaveCriticalRegion();
  return;
}



===== AfUnixConnectEndpointAbort @ 140009a0c =====

undefined8
AfUnixConnectEndpointAbort
          (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  if (((*(uint *)(param_1 + 0x104) & 1) == 0) && (uVar1 = 0, *(longlong *)(param_1 + 0x1d8) == 0)) {
    *(undefined8 *)(param_1 + 0x1d8) = *param_2;
    *(undefined8 *)(param_1 + 0x1e0) = param_2[1];
    AfUnixConnectEndpointShutdown(param_1,0xc0000241,0,param_4);
  }
  else {
    uVar1 = 0xc0000184;
    AfUnixTraceLogging(2,"AfUnixConnectEndpointAbort",0xd6,"[0x%08x] Endpoint has been shutdown.\n",
                       -0x7c);
  }
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== AfUnixConnectEndpointCompleteDisconnectRequest @ 140009ae8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AfUnixConnectEndpointCompleteDisconnectRequest
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  pcVar1 = *(code **)(param_1 + 0x1e8);
  uVar2 = *(undefined8 *)(param_1 + 0x1f0);
  uVar3 = *(undefined8 *)(param_1 + 0x220);
  if (pcVar1 != (code *)0x0) {
    memset((undefined8 *)(param_1 + 0x1e8),0,0x40);
    ExReleasePushLockExclusiveEx(param_1 + 8,0);
    KeLeaveCriticalRegion();
    (*pcVar1)(uVar2,param_2,uVar3);
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  }
  return;
}



===== AfUnixConnectEndpointDestruct @ 140009b90 =====

void AfUnixConnectEndpointDestruct(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x228) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0x228) = 0;
  }
  return;
}



===== AfUnixConnectEndpointGracefulDisconnect @ 140009bc8 =====

int AfUnixConnectEndpointGracefulDisconnect
              (longlong param_1,undefined8 *param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  char in_stack_ffffffffffffffe8;
  
  KeEnterCriticalRegion();
  lVar1 = param_1 + 8;
  ExAcquirePushLockExclusiveEx(lVar1);
  if (*(longlong *)(param_1 + 0x1e8) == 0) {
    if (*(int *)(param_1 + 0x100) == 4) {
      uVar2 = 5;
    }
    else {
      if (*(int *)(param_1 + 0x100) != 7) {
        if ((*(uint *)(param_1 + 0x104) & 4) == 0) {
          iVar3 = (-(uint)((*(uint *)(param_1 + 0x104) & 8) != 0) & 0xbd) + 0xc0000184;
        }
        else {
          iVar3 = -0x3ffffdf3;
        }
        AfUnixTraceLogging(2,"AfUnixConnectEndpointGracefulDisconnect",0x279,
                           "[0x%08x] Endpoint invalid state\n",(char)iVar3);
        goto LAB_140009d29;
      }
      uVar2 = 9;
    }
    *(undefined4 *)(param_1 + 0x100) = uVar2;
    *(undefined8 *)(param_1 + 0x1e8) = *param_2;
    *(undefined8 *)(param_1 + 0x1f0) = param_2[1];
    if (param_2[5] != 0) {
      param_4 = "Graceful disconnect and send unimplemented\n";
      param_3 = 0x28f;
      AfUnixTraceLogging(2,"AfUnixConnectEndpointGracefulDisconnect",0x28f,
                         "Graceful disconnect and send unimplemented\n",in_stack_ffffffffffffffe8);
    }
    ExReleasePushLockExclusiveEx(lVar1);
    KeLeaveCriticalRegion();
    iVar3 = AfUnixDeliverEndpointSend(param_1,(undefined8 *)0x0,param_3,(undefined8 **)param_4);
    if (iVar3 < 0) {
      AfUnixTraceLogging(2,"AfUnixConnectEndpointGracefulDisconnect",0x29e,
                         "[0x%08x] AfUnixDeliverEndpointSend\n",(char)iVar3);
    }
    iVar3 = 0x103;
  }
  else {
    AfUnixTraceLogging(2,"AfUnixConnectEndpointGracefulDisconnect",0x263,
                       "Shutdown request already queued.\n",in_stack_ffffffffffffffe8);
    iVar3 = -0x3ffffe7c;
LAB_140009d29:
    ExReleasePushLockExclusiveEx(lVar1,0);
    KeLeaveCriticalRegion();
  }
  return iVar3;
}



===== AfUnixConnectEndpointShutdown @ 140009d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AfUnixConnectEndpointShutdown
               (longlong param_1,uint param_2,ulonglong param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  
  lVar11 = 0;
  uVar9 = (ulonglong)param_2;
  if ((*(uint *)(param_1 + 0x1c0) & 2) == 0) {
    uVar1 = *(uint *)(param_1 + 0x104);
    *(uint *)(param_1 + 0x104) = uVar1 | 1;
    *(uint *)(param_1 + 0x1c4) = *(uint *)(param_1 + 0x1c4) & 0xfffffffc;
    iVar2 = *(int *)(param_1 + 0x100);
    *(undefined4 *)(param_1 + 0x100) = 0;
    plVar3 = *(longlong **)(param_1 + 0x188);
    puVar8 = auStack_68;
    if (((((uVar1 & 2) == 0) && (puVar8 = auStack_68, 3 < iVar2)) &&
        (puVar8 = auStack_68, (param_2 + 0x80000000 & 0x80000000) == 0)) &&
       (puVar8 = auStack_68, param_2 != 0xc000020d)) {
      *(uint *)(param_1 + 0x104) = uVar1 | 3;
      LOCK();
      lVar11 = *plVar3;
      *plVar3 = *plVar3 + 1;
      UNLOCK();
      puVar8 = auStack_68;
      if (lVar11 + 1 < 2) {
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(0xe);
        puVar8 = auStack_60;
      }
      *(undefined8 *)(puVar8 + -8) = 0x140009e48;
      ExReleasePushLockExclusiveEx(param_1 + 8);
      *(undefined8 *)(puVar8 + -8) = 0x140009e54;
      KeLeaveCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x140009e60;
      KeEnterCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x140009e72;
      ExAcquirePushLockExclusiveEx(plVar3 + 1);
      uVar1 = *(uint *)((longlong)plVar3 + 0x104);
      if ((uVar1 & 1) == 0) {
        *(uint *)((longlong)plVar3 + 0x104) = uVar1 | 4;
        if ((*(uint *)(plVar3 + 0x38) & 2) == 0) {
          if ((uVar1 & 1) == 0) {
            param_3 = 1;
            *(undefined8 *)(puVar8 + -8) = 0x140009ecc;
            AfUnixConnectEndpointShutdown((longlong)plVar3,0xc000020d,1,param_4);
          }
        }
        else if ((*(uint *)((longlong)plVar3 + 0x1c4) & 2) == 0) {
          *(undefined4 *)((longlong)plVar3 + 0x1cc) = 0xc000020d;
          *(uint *)((longlong)plVar3 + 0x1c4) = *(uint *)((longlong)plVar3 + 0x1c4) | 2;
        }
      }
      *(undefined8 *)(puVar8 + -8) = 0x140009ed9;
      ExReleasePushLockExclusiveEx(plVar3 + 1);
      *(undefined8 *)(puVar8 + -8) = 0x140009ee5;
      KeLeaveCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x140009ef2;
      AfUnixEndpointDereference(plVar3);
      *(undefined8 *)(puVar8 + -8) = 0x140009ef9;
      KeEnterCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x140009f0b;
      ExAcquirePushLockExclusiveEx(param_1 + 8);
      lVar11 = *(longlong *)(puVar8 + 0x88);
    }
    if ((puVar8[0x80] & 1) != 0) {
      *(undefined8 *)(puVar8 + -8) = 0x140009f2f;
      ExReleasePushLockExclusiveEx(param_1 + 8,0);
      *(undefined8 *)(puVar8 + -8) = 0x140009f3b;
      KeLeaveCriticalRegion();
      lVar4 = *(longlong *)(param_1 + 0x178);
      uVar7 = *(undefined8 *)(param_1 + 0x180);
      *(undefined4 *)(puVar8 + 0x70) = 3;
      pcVar6 = *(code **)(lVar4 + 8);
      *(undefined8 *)(puVar8 + -8) = 0x140009f64;
      (*pcVar6)(uVar7);
      *(undefined8 *)(puVar8 + -8) = 0x140009f6b;
      KeEnterCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x140009f7d;
      ExAcquirePushLockExclusiveEx(param_1 + 8);
    }
    lVar4 = *(longlong *)(param_1 + 0x1b0);
    if (lVar4 != 0) {
      *(undefined8 *)(param_1 + 0x1b0) = 0;
      *(undefined8 *)(param_1 + 0x1b8) = 0;
      *(longlong *)(puVar8 + 0x88) = lVar4;
      lVar11 = lVar4;
    }
    puVar5 = *(undefined8 **)(param_1 + 400);
    puVar10 = (undefined8 *)0x0;
    if (puVar5 != (undefined8 *)0x0) {
      *(undefined8 *)(param_1 + 400) = 0;
      *(undefined8 *)(param_1 + 0x198) = 0;
      puVar10 = puVar5;
    }
    if ((lVar11 != 0) || (puVar10 != (undefined8 *)0x0)) {
      uVar7 = 0;
      *(undefined8 *)(puVar8 + -8) = 0x140009fdd;
      ExReleasePushLockExclusiveEx(param_1 + 8);
      *(undefined8 *)(puVar8 + -8) = 0x140009fe9;
      KeLeaveCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x140009ffe;
      AfUnixDeliverCompleteSendRequests((undefined8 *)(puVar8 + 0x88),uVar7,param_2);
      *(undefined8 *)(puVar8 + -8) = 0x14000a009;
      AfUnixDeliverCompleteReceiveRequests(puVar10,param_2);
      *(undefined8 *)(puVar8 + -8) = 0x14000a010;
      KeEnterCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x14000a022;
      ExAcquirePushLockExclusiveEx(param_1 + 8,0);
      param_3 = uVar9;
    }
    if ((iVar2 - 5U < 2) || (iVar2 - 8U < 2)) {
      *(undefined8 *)(puVar8 + -8) = 0x14000a044;
      AfUnixConnectEndpointCompleteDisconnectRequest(param_1,param_2,param_3,param_4);
    }
    if (*(longlong *)(param_1 + 0x1d8) != 0) {
      pcVar6 = *(code **)(param_1 + 0x1d8);
      uVar7 = *(undefined8 *)(param_1 + 0x1e0);
      *(undefined8 *)(param_1 + 0x1d8) = 0;
      *(undefined8 *)(param_1 + 0x1e0) = 0;
      *(undefined8 *)(puVar8 + -8) = 0x14000a06c;
      ExReleasePushLockExclusiveEx(param_1 + 8,0);
      *(undefined8 *)(puVar8 + -8) = 0x14000a078;
      KeLeaveCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x14000a096;
      (*pcVar6)(uVar7,0,0);
      *(undefined8 *)(puVar8 + -8) = 0x14000a09d;
      KeEnterCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x14000a0af;
      ExAcquirePushLockExclusiveEx(param_1 + 8,0);
    }
    *(undefined8 *)(puVar8 + -8) = 0x14000a0bc;
    AfUnixEndpointDereference(plVar3);
    *(undefined8 *)(param_1 + 0x188) = 0;
  }
  else if ((*(uint *)(param_1 + 0x1c4) & 1) == 0) {
    *(uint *)(param_1 + 0x1c8) = param_2;
    *(uint *)(param_1 + 0x1c4) = *(uint *)(param_1 + 0x1c4) | 1;
  }
  return;
}



===== AfUnixTlConnectEndpointClose @ 14000a0e0 =====

undefined8
AfUnixTlConnectEndpointClose
          (longlong *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  byte bVar2;
  
  bVar2 = KeGetCurrentIrql();
  if (1 < bVar2) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar2,0,0);
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 1);
  if ((*(uint *)((longlong)param_1 + 0x104) & 1) == 0) {
    AfUnixConnectEndpointShutdown
              ((longlong)param_1,-(uint)((int)param_1[0x20] != 10) & 0xc0000241,0,param_4);
  }
  ExReleasePushLockExclusiveEx(param_1 + 1,0);
  KeLeaveCriticalRegion();
  lVar1 = param_2[1];
  param_1[0x1e] = *param_2;
  param_1[0x1f] = lVar1;
  AfUnixEndpointDereference(param_1);
  return 0x103;
}



===== AfUnixTlConnectEndpointDisconnect @ 14000a1c0 =====

int AfUnixTlConnectEndpointDisconnect
              (longlong param_1,undefined8 *param_2,undefined8 param_3,char *param_4)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar1,0,0);
  }
  if ((*(uint *)(param_2 + 2) & 1) == 0) {
    iVar2 = AfUnixConnectEndpointGracefulDisconnect(param_1,param_2,param_3,param_4);
  }
  else {
    uVar3 = AfUnixConnectEndpointAbort(param_1,param_2,param_3,param_4);
    iVar2 = (int)uVar3;
  }
  if (-1 < iVar2) {
    iVar2 = 0x103;
  }
  return iVar2;
}



===== AfUnixTlConnectEndpointIoControl @ 14000a240 =====

int AfUnixTlConnectEndpointIoControl(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar1,0,0);
  }
  iVar3 = *(int *)(param_2 + 0x10);
  if (iVar3 == 0) {
    iVar3 = AfUnixEndpointIoctl(param_1,param_2);
    return iVar3;
  }
  if (iVar3 == 1) {
    pcVar4 = "TlSetSockOptIoControlType option{%lu} unimplemented\n";
    uVar2 = 0x4d8;
  }
  else {
    if (iVar3 != 2) {
      if (iVar3 != 3) {
        return -0x3fffff45;
      }
      iVar3 = *(int *)(param_2 + 0x18);
      if (iVar3 == 0x58000100) {
        if (*(ulonglong *)(param_2 + 0x38) < 4) {
          AfUnixTraceLogging(2,"AfUnixConnectEndpointGetPeerPid",0x48f,
                             "[0x%08x] GETPEERPID with insufficient buffer\n",'\r');
          return -0x3ffffff3;
        }
        uVar2 = 0;
        if (*(longlong *)(param_1 + 0x228) != 0) {
          uVar2 = PsGetProcessId();
        }
        **(undefined4 **)(param_2 + 0x30) = uVar2;
        return 0;
      }
      pcVar4 = "TlSocketIoControlType option{%lu} unimplemented\n";
      uVar2 = 0x4e7;
      goto LAB_14000a327;
    }
    pcVar4 = "TlGetSockOptIoControlType option{%lu} unimplemented\n";
    uVar2 = 0x4cd;
  }
  iVar3 = *(int *)(param_2 + 0x18);
LAB_14000a327:
  AfUnixTraceLogging(2,"AfUnixTlConnectEndpointIoControl",uVar2,pcVar4,(char)iVar3);
  return -0x3fffff45;
}



===== AfUnixTlConnectEndpointReceive @ 14000a380 =====

undefined4
AfUnixTlConnectEndpointReceive
          (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 **param_4)

{
  uint uVar1;
  byte bVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  bVar2 = KeGetCurrentIrql();
  if (1 < bVar2) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar2,0,0);
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  uVar1 = *(uint *)(param_1 + 0x104);
  if ((uVar1 & 1) == 0) {
    uVar5 = 0x69706e57;
    puVar3 = (undefined8 *)ExAllocatePool2(0x40);
    if (puVar3 == (undefined8 *)0x0) {
      uVar4 = 0xc0000017;
    }
    else {
      puVar3[10] = 0;
      puVar3[3] = param_2[3];
      *(undefined4 *)(puVar3 + 4) = *(undefined4 *)(param_2 + 4);
      puVar3[5] = param_2[5];
      *puVar3 = *param_2;
      puVar3[1] = param_2[1];
      puVar3[7] = param_2[7];
      if (*(longlong *)(param_1 + 400) == 0) {
        *(undefined8 **)(param_1 + 400) = puVar3;
      }
      else {
        *(undefined8 **)(*(longlong *)(param_1 + 0x198) + 0x50) = puVar3;
      }
      *(undefined8 **)(param_1 + 0x198) = puVar3;
      AfUnixDeliverDataToClient(param_1,puVar3,uVar5,param_4);
      uVar4 = 0x103;
    }
  }
  else {
    if ((uVar1 & 4) == 0) {
      if (((uVar1 & 8) == 0) && ((uVar1 & 0x40) != 0)) {
        uVar4 = 0;
        param_2[6] = 0;
      }
      else {
        uVar4 = 0xc0000241;
      }
    }
    else {
      uVar4 = 0xc000020d;
    }
    AfUnixTraceLogging(2,"AfUnixDeliverEndpointQueueReceiveRequest",0x371,
                       "[0x%08x] Cannot process request\n",(char)uVar4);
  }
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  KeLeaveCriticalRegion();
  return uVar4;
}



===== RtlCopyMdlToMdl @ 14000a504 =====

undefined8
RtlCopyMdlToMdl(undefined8 *param_1,ulonglong param_2,undefined8 *param_3,ulonglong param_4,
               ulonglong param_5,ulonglong *param_6)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  void *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  void *_Src;
  ulonglong _Size;
  
  uVar4 = param_5;
  for (; (param_1 != (undefined8 *)0x0 && (*(uint *)(param_1 + 5) <= param_2));
      param_1 = (undefined8 *)*param_1) {
    param_2 = param_2 - *(uint *)(param_1 + 5);
  }
  for (; (param_3 != (undefined8 *)0x0 && (*(uint *)(param_3 + 5) <= param_4));
      param_3 = (undefined8 *)*param_3) {
    param_4 = param_4 - *(uint *)(param_3 + 5);
  }
  if (((param_5 == 0) || (param_1 == (undefined8 *)0x0)) || (param_3 == (undefined8 *)0x0)) {
    *param_6 = 0;
LAB_14000a73c:
    uVar3 = 0;
  }
  else {
    uVar5 = *(uint *)(param_1 + 5) - param_2;
    if (param_5 < *(uint *)(param_1 + 5) - param_2) {
      uVar5 = param_5;
    }
    if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
      lVar2 = MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000000);
    }
    else {
      lVar2 = param_1[3];
    }
    if (lVar2 != 0) {
      _Src = (void *)(lVar2 + param_2);
      uVar6 = *(uint *)(param_3 + 5) - param_4;
      if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) {
        lVar2 = MmMapLockedPagesSpecifyCache(param_3,0,1,0,0,0x40000000);
      }
      else {
        lVar2 = param_3[3];
      }
      if (lVar2 != 0) {
        _Dst = (void *)(lVar2 + param_4);
LAB_14000a619:
        do {
          _Size = uVar6;
          if (uVar5 <= uVar6) {
            _Size = uVar5;
          }
          memmove(_Dst,_Src,_Size);
          if (param_5 == _Size) goto LAB_14000a723;
          param_5 = param_5 - _Size;
          if (uVar6 == _Size) {
            do {
              param_3 = (undefined8 *)*param_3;
              if (param_3 == (undefined8 *)0x0) goto LAB_14000a720;
              uVar6 = (ulonglong)*(uint *)(param_3 + 5);
            } while (uVar6 == 0);
            if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) {
              _Dst = (void *)MmMapLockedPagesSpecifyCache(param_3,0,1,0,0,0x40000000);
            }
            else {
              _Dst = (void *)param_3[3];
            }
            if (_Dst == (void *)0x0) break;
          }
          else {
            _Dst = (void *)((longlong)_Dst + _Size);
            uVar6 = uVar6 - _Size;
          }
          if (uVar5 == _Size) goto LAB_14000a6bd;
          _Src = (void *)((longlong)_Src + _Size);
          uVar5 = uVar5 - _Size;
        } while( true );
      }
    }
LAB_14000a6a8:
    uVar3 = 0xc000009a;
  }
  return uVar3;
LAB_14000a6bd:
  do {
    param_1 = (undefined8 *)*param_1;
    if (param_1 == (undefined8 *)0x0) goto LAB_14000a720;
    uVar1 = *(uint *)(param_1 + 5);
  } while (uVar1 == 0);
  uVar5 = param_5;
  if (uVar1 <= param_5) {
    uVar5 = (ulonglong)uVar1;
  }
  if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
    _Src = (void *)MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000000);
  }
  else {
    _Src = (void *)param_1[3];
  }
  if (_Src == (void *)0x0) goto LAB_14000a6a8;
  goto LAB_14000a619;
LAB_14000a720:
  uVar4 = uVar4 - param_5;
LAB_14000a723:
  *param_6 = uVar4;
  goto LAB_14000a73c;
}



===== TcpSatisfyReceiveRequests @ 14000a764 =====

longlong TcpSatisfyReceiveRequests
                   (longlong param_1,longlong *param_2,undefined8 *param_3,longlong *param_4,
                   longlong *param_5)

{
  ulonglong uVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 *puVar11;
  ulonglong local_48 [2];
  
  lVar5 = *param_2;
  puVar8 = (undefined8 *)*param_3;
  local_48[0] = 0;
  lVar10 = 0;
  puVar11 = (undefined8 *)0x0;
  lVar9 = 0;
  puVar7 = puVar8;
  if (lVar5 != 0) {
    do {
      puVar8 = puVar7;
      if (puVar7 == (undefined8 *)0x0) break;
      uVar1 = puVar7[3];
      if ((*(uint *)(lVar5 + 0x10) & 4) == 0) {
        lVar4 = *(longlong *)(lVar5 + 0x28);
        lVar3 = *(longlong *)(lVar5 + 0x30);
        uVar6 = uVar1;
        if ((ulonglong)(lVar4 - lVar3) <= uVar1) {
          uVar6 = lVar4 - lVar3;
        }
        if (uVar6 == 0xffffffffffffffff) goto LAB_14000a7e9;
        if (uVar6 != 0) {
          RtlCopyMdlToMdl((undefined8 *)puVar7[1],(ulonglong)*(uint *)(puVar7 + 2),
                          *(undefined8 **)(lVar5 + 0x18),(ulonglong)*(uint *)(lVar5 + 0x20),uVar6,
                          local_48);
          lVar9 = lVar9 + local_48[0];
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) - local_48[0];
          *(longlong *)(lVar5 + 0x30) = *(longlong *)(lVar5 + 0x30) + local_48[0];
          *(int *)(lVar5 + 0x20) = *(int *)(lVar5 + 0x20) + (int)local_48[0];
          puVar7[3] = puVar7[3] - local_48[0];
          *(int *)(puVar7 + 2) = *(int *)(puVar7 + 2) + (int)local_48[0];
          lVar3 = *(longlong *)(lVar5 + 0x30);
          lVar4 = *(longlong *)(lVar5 + 0x28);
        }
        if (lVar3 != lVar4) goto LAB_14000a7ec;
        bVar2 = true;
        if (*param_4 == 0) {
          *param_4 = lVar5;
        }
        else {
          *(longlong *)(lVar10 + 0x50) = lVar5;
        }
        lVar4 = *(longlong *)(lVar5 + 0x50);
        *(longlong *)(lVar5 + 0x50) = 0;
        lVar10 = lVar5;
      }
      else {
        uVar6 = 0xffffffffffffffff;
LAB_14000a7e9:
        lVar9 = lVar9 + uVar1;
LAB_14000a7ec:
        bVar2 = false;
        lVar4 = lVar5;
      }
      lVar5 = lVar4;
      if (puVar7[3] == 0) {
LAB_14000a802:
        *(undefined4 *)(puVar7 + 7) = 0;
        if (*param_5 == 0) {
          *param_5 = (longlong)puVar7;
        }
        else {
          *puVar11 = puVar7;
        }
        puVar8 = (undefined8 *)*puVar7;
        *puVar7 = 0;
        puVar11 = puVar7;
        if (((puVar8 == (undefined8 *)0x0) && (!bVar2)) && ((*(uint *)(lVar4 + 0x10) & 6) == 0)) {
          if (*param_4 == 0) {
            *param_4 = lVar4;
          }
          else {
            *(longlong *)(lVar10 + 0x50) = lVar4;
          }
          lVar5 = *(longlong *)(lVar4 + 0x50);
          *(longlong *)(lVar4 + 0x50) = 0;
          lVar10 = lVar4;
        }
      }
      else if (uVar6 == 0xffffffffffffffff) goto LAB_14000a802;
      puVar7 = puVar8;
    } while (lVar5 != 0);
  }
  *param_2 = lVar5;
  *param_3 = puVar8;
  return lVar9;
}



===== AfUnixDeliverCompleteReceiveRequests @ 14000a920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AfUnixDeliverCompleteReceiveRequests(undefined8 *param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    do {
      (*(code *)*param_1)(param_1[1],param_2,param_1[6],param_1[7]);
      puVar1 = (undefined8 *)param_1[10];
      ExFreePoolWithTag(param_1,0);
      param_1 = puVar1;
    } while (puVar1 != (undefined8 *)0x0);
  }
  return;
}



===== AfUnixDeliverCompleteSendRequests @ 14000a978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AfUnixDeliverCompleteSendRequests(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  while (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar1 + 7) = param_3;
    (*(code *)puVar1[4])(puVar1[5],param_3,puVar1[8]);
    *param_1 = *puVar1;
    ExFreePoolWithTag(puVar1,0);
    puVar1 = (undefined8 *)*param_1;
  }
  return;
}



===== AfUnixDeliverDataToClient @ 14000a9e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AfUnixDeliverDataToClient
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 **param_4)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 **ppuVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 **ppuVar8;
  longlong lVar9;
  undefined8 **ppuVar10;
  longlong lVar11;
  undefined8 **ppuVar12;
  undefined8 **local_res10;
  undefined8 **local_res18;
  undefined8 *local_res20;
  longlong local_a8;
  longlong local_a0;
  longlong *local_98;
  longlong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 **local_78;
  undefined8 *puStack_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  
  plVar1 = (longlong *)(param_1 + 400);
  local_res20 = (undefined8 *)0x0;
  local_58 = local_58 & 0xffffffff00000000;
  local_res10 = (undefined8 **)0x0;
  ppuVar12 = (undefined8 **)0x0;
  ppuVar10 = (undefined8 **)0x0;
  lVar9 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = (undefined8 **)0x0;
  puStack_70 = (undefined8 *)0x0;
  local_68 = (undefined8 *)0x0;
  uStack_60 = 0;
  if (((*(uint *)(param_1 + 0x1c0) & 2) == 0) &&
     (ppuVar5 = *(undefined8 ***)(param_1 + 0x1b0), ppuVar5 != (undefined8 **)0x0)) {
    lVar11 = *plVar1;
    local_a0 = *(longlong *)(param_1 + 0x198);
    lVar6 = param_1 + 8;
    local_98 = *(longlong **)(param_1 + 0x1b8);
    *(uint *)(param_1 + 0x1c0) = *(uint *)(param_1 + 0x1c0) | 2;
    *plVar1 = 0;
    *(undefined8 *)(param_1 + 0x198) = 0;
    *(undefined8 *)(param_1 + 0x1b0) = 0;
    *(undefined8 *)(param_1 + 0x1b8) = 0;
    local_res18 = ppuVar5;
    local_a8 = lVar11;
    local_90 = lVar6;
    do {
      if (lVar11 == 0) {
        ExReleasePushLockExclusiveEx(lVar6,0);
        KeLeaveCriticalRegion();
        goto LAB_14000ab0c;
      }
      do {
        *(uint *)(param_1 + 0x1c0) = *(uint *)(param_1 + 0x1c0) & 0xfffffffe;
        param_4 = &local_res20;
        TcpSatisfyReceiveRequests
                  ((longlong)plVar1,&local_a8,&local_res18,(longlong *)param_4,
                   (longlong *)&local_res10);
        ExReleasePushLockExclusiveEx(lVar6);
        KeLeaveCriticalRegion();
        uVar3 = 0;
        AfUnixDeliverCompleteReceiveRequests(local_res20,0);
        local_res20 = (undefined8 *)0x0;
        AfUnixDeliverCompleteSendRequests(&local_res10,uVar3,0);
        ppuVar12 = (undefined8 **)0x0;
        local_res10 = (undefined8 **)0x0;
        ppuVar5 = local_res18;
        lVar11 = local_a8;
LAB_14000ab0c:
        if (ppuVar5 != (undefined8 **)0x0) {
          if ((*(uint *)(param_1 + 0x1c0) & 1) == 0) {
            local_68 = (undefined8 *)0xffffffffffffffff;
            uStack_80 = 0;
            local_88 = 2;
            puVar7 = (undefined8 *)0x0;
            uStack_60 = 0;
            local_58 = 0;
            ppuVar8 = ppuVar5;
            do {
              puVar7 = (undefined8 *)((longlong)puVar7 + (longlong)ppuVar8[3]);
              ppuVar8 = (undefined8 **)*ppuVar8;
            } while (ppuVar8 != (undefined8 **)0x0);
            puVar4 = &local_88;
            local_78 = ppuVar5;
            puStack_70 = puVar7;
            iVar2 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x10))
                              (*(undefined8 *)(param_1 + 0x180));
            param_4 = (undefined8 **)0x0;
            for (ppuVar5 = local_78; ppuVar5 != (undefined8 **)0x0;
                ppuVar5 = (undefined8 **)*ppuVar5) {
              param_4 = (undefined8 **)((longlong)param_4 + (longlong)ppuVar5[3]);
            }
            if (iVar2 == -0x3ffffde5) {
              *(uint *)(param_1 + 0x1c0) = *(uint *)(param_1 + 0x1c0) | 1;
              ppuVar5 = local_78;
            }
            else {
              if (local_68 == (undefined8 *)0xffffffffffffffff) {
                lVar9 = lVar9 + (longlong)puVar7;
              }
              else {
                lVar9 = lVar9 + (longlong)local_68;
                if (local_68 != puVar7) {
                  *(uint *)(param_1 + 0x1c0) = *(uint *)(param_1 + 0x1c0) | 1;
                  local_res10 = (undefined8 **)0x0;
                  ppuVar8 = (undefined8 **)0x0;
                  puVar4 = (undefined8 *)
                           (((longlong)local_68 - (longlong)puVar7) + (longlong)param_4);
                  ppuVar12 = local_78;
                  while( true ) {
                    ppuVar5 = ppuVar12;
                    if (puVar4 == (undefined8 *)0x0) break;
                    puVar7 = ppuVar5[3];
                    ppuVar12 = (undefined8 **)*ppuVar5;
                    param_4 = ppuVar5;
                    if (puVar4 < puVar7) {
                      ppuVar5[3] = (undefined8 *)((longlong)puVar7 - (longlong)puVar4);
                      *(int *)(ppuVar5 + 2) = *(int *)(ppuVar5 + 2) + (int)puVar4;
                      break;
                    }
                    ppuVar5[3] = (undefined8 *)0x0;
                    puVar4 = (undefined8 *)((longlong)puVar4 - (longlong)puVar7);
                    *(int *)(ppuVar5 + 2) = *(int *)(ppuVar5 + 2) + (int)puVar7;
                    if (ppuVar8 == (undefined8 **)0x0) {
                      ppuVar8 = ppuVar5;
                      local_res10 = ppuVar5;
                    }
                    else {
                      *ppuVar10 = ppuVar5;
                    }
                    *ppuVar5 = (undefined8 *)0x0;
                    ppuVar10 = ppuVar5;
                  }
                  goto LAB_14000ac5c;
                }
              }
              ppuVar5 = local_78;
              ppuVar8 = ppuVar10;
              if (local_78 != (undefined8 **)0x0) {
                do {
                  ppuVar10 = ppuVar5;
                  *(int *)(ppuVar10 + 2) = *(int *)(ppuVar10 + 2) + *(int *)(ppuVar10 + 3);
                  ppuVar10[3] = (undefined8 *)0x0;
                  if (ppuVar12 == (undefined8 **)0x0) {
                    ppuVar12 = ppuVar10;
                  }
                  else {
                    *ppuVar8 = ppuVar10;
                  }
                  ppuVar5 = (undefined8 **)*ppuVar10;
                  *ppuVar10 = (undefined8 *)0x0;
                  ppuVar8 = ppuVar10;
                } while (ppuVar5 != (undefined8 **)0x0);
                local_res10 = ppuVar12;
              }
              ppuVar5 = (undefined8 **)0x0;
              puVar4 = local_68;
            }
LAB_14000ac5c:
            AfUnixDeliverCompleteSendRequests(&local_res10,puVar4,0);
            lVar6 = local_90;
            ppuVar12 = local_res10;
            local_res18 = ppuVar5;
          }
        }
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(lVar6,0);
        if (lVar11 == 0) {
          lVar11 = *plVar1;
          local_a0 = *(longlong *)(param_1 + 0x198);
          *plVar1 = 0;
          *(undefined8 *)(param_1 + 0x198) = 0;
          local_a8 = lVar11;
        }
        if (ppuVar5 == (undefined8 **)0x0) {
          ppuVar5 = *(undefined8 ***)(param_1 + 0x1b0);
          local_98 = *(longlong **)(param_1 + 0x1b8);
          *(undefined8 *)(param_1 + 0x1b0) = 0;
          *(undefined8 *)(param_1 + 0x1b8) = 0;
          local_res18 = ppuVar5;
          if (ppuVar5 == (undefined8 **)0x0) goto LAB_14000acf1;
        }
      } while (lVar11 != 0);
    } while ((*(uint *)(param_1 + 0x1c0) & 1) == 0);
LAB_14000acf1:
    *(longlong *)(param_1 + 0x1a0) = *(longlong *)(param_1 + 0x1a0) - lVar9;
    if (lVar11 != 0) {
      if (*plVar1 == 0) {
        *(longlong *)(param_1 + 0x198) = local_a0;
      }
      *(longlong *)(local_a0 + 0x50) = *plVar1;
      *plVar1 = lVar11;
    }
    if (ppuVar5 != (undefined8 **)0x0) {
      if (*(longlong *)(param_1 + 0x1b0) == 0) {
        *(longlong **)(param_1 + 0x1b8) = local_98;
      }
      *local_98 = *(longlong *)(param_1 + 0x1b0);
      *(undefined8 ***)(param_1 + 0x1b0) = ppuVar5;
    }
    *(uint *)(param_1 + 0x1c0) = *(uint *)(param_1 + 0x1c0) & 0xfffffffd;
    AfUnixDeliverPostIoProcess(param_1,local_a0,0,(ulonglong)param_4);
  }
  return;
}



===== AfUnixDeliverEndpointQueueSendRequest @ 14000ad50 =====

undefined8 AfUnixDeliverEndpointQueueSendRequest(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)ExAllocatePool2(0x40,0x48,0x69706e57);
  uVar2 = 0;
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = param_2[4];
    *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(param_2 + 5);
    puVar1[3] = param_2[6];
    puVar1[4] = *param_2;
    puVar1[5] = param_2[2];
    *(undefined4 *)(puVar1 + 7) = 0;
    puVar1[8] = param_2[6];
    puVar1[6] = param_2[7];
    if (*(longlong *)(param_1 + 0x1b0) == 0) {
      *(undefined8 **)(param_1 + 0x1b0) = puVar1;
    }
    else {
      **(undefined8 **)(param_1 + 0x1b8) = puVar1;
    }
    *(undefined8 **)(param_1 + 0x1b8) = puVar1;
    *(longlong *)(param_1 + 0x1a0) = *(longlong *)(param_1 + 0x1a0) + puVar1[8];
  }
  return uVar2;
}



===== AfUnixDeliverEndpointSend @ 14000ae0c =====

int AfUnixDeliverEndpointSend
              (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 **param_4)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  int iVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  plVar8 = (longlong *)0x0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  puVar7 = auStack_48;
  bVar1 = (&AfUnixThFlags)[*(int *)(param_1 + 0x100)];
  if ((*(uint *)(param_1 + 0x104) & 1) == 0) {
    plVar8 = *(longlong **)(param_1 + 0x188);
    LOCK();
    lVar3 = *plVar8;
    *plVar8 = *plVar8 + 1;
    UNLOCK();
    if (lVar3 + 1 < 2) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(0xe);
      puVar7 = auStack_40;
    }
    iVar6 = 0;
  }
  else {
    iVar6 = -0x3ffffe7c;
    puVar7 = auStack_48;
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000ae9d;
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  *(undefined8 *)(puVar7 + -8) = 0x14000aea9;
  KeLeaveCriticalRegion();
  if (iVar6 < 0) {
    *(int *)(puVar7 + 0x20) = iVar6;
    *(undefined8 *)(puVar7 + -8) = 0x14000aed4;
    AfUnixTraceLogging(2,"AfUnixDeliverEndpointSend",0x3f3,
                       "[0x%08x] Send:: cannot process request\n",puVar7[0x20]);
    goto LAB_14000b0c1;
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000aee0;
  KeEnterCriticalRegion();
  *(undefined8 *)(puVar7 + -8) = 0x14000aef2;
  ExAcquirePushLockExclusiveEx(plVar8 + 1,0);
  uVar2 = *(uint *)((longlong)plVar8 + 0x104);
  if ((uVar2 & 1) == 0) {
    if (param_2 != (undefined8 *)0x0) {
      if (param_2[6] == 0) {
        iVar6 = 0;
        goto LAB_14000af74;
      }
      *(undefined8 *)(puVar7 + -8) = 0x14000af4c;
      uVar5 = AfUnixDeliverEndpointQueueSendRequest((longlong)plVar8,param_2);
      iVar6 = (int)uVar5;
      if (iVar6 < 0) {
        *(int *)(puVar7 + 0x20) = iVar6;
        pcVar10 = "[0x%08x] AfUnixDeliverEndpointQueueSendRequest\n";
        uVar9 = 0x42a;
        goto LAB_14000af63;
      }
    }
    lVar3 = plVar8[0x34];
    if ((bVar1 & 1) != 0) {
      *(uint *)((longlong)plVar8 + 0x104) = *(uint *)((longlong)plVar8 + 0x104) | 0x30;
      iVar6 = (int)plVar8[0x20];
      if (iVar6 == 4) {
        *(undefined4 *)(plVar8 + 0x20) = 7;
      }
      else if (iVar6 == 5) {
        *(undefined4 *)(plVar8 + 0x20) = 8;
      }
      else if (iVar6 == 6) {
        *(undefined4 *)(plVar8 + 0x20) = 10;
      }
    }
    if (lVar3 == 0) {
      *(undefined8 *)(puVar7 + -8) = 0x14000aff7;
      AfUnixDeliverFin((longlong)plVar8,0,param_3,param_4);
    }
    else {
      *(undefined8 *)(puVar7 + -8) = 0x14000aff0;
      AfUnixDeliverDataToClient((longlong)plVar8,lVar3,param_3,param_4);
    }
    *(undefined8 *)(puVar7 + -8) = 0x14000b004;
    ExReleasePushLockExclusiveEx(plVar8 + 1);
    *(undefined8 *)(puVar7 + -8) = 0x14000b010;
    KeLeaveCriticalRegion();
    *(undefined8 *)(puVar7 + -8) = 0x14000b01c;
    KeEnterCriticalRegion();
    *(undefined8 *)(puVar7 + -8) = 0x14000b02e;
    ExAcquirePushLockExclusiveEx(param_1 + 8);
    if ((bVar1 & 1) != 0) {
      iVar6 = *(int *)(param_1 + 0x100);
      if (iVar6 == 5) {
        *(undefined4 *)(param_1 + 0x100) = 6;
      }
      else if (iVar6 == 8) {
        *(undefined4 *)(param_1 + 0x100) = 10;
      }
      else if (iVar6 == 9) {
        *(undefined4 *)(param_1 + 0x100) = 0;
      }
      *(undefined8 *)(puVar7 + -8) = 0x14000b072;
      AfUnixConnectEndpointCompleteDisconnectRequest(param_1,0,param_3,param_4);
      if (((*(int *)(param_1 + 0x100) == 10) || (*(int *)(param_1 + 0x100) == 0)) &&
         ((*(uint *)(param_1 + 0x104) & 1) == 0)) {
        *(undefined8 *)(puVar7 + -8) = 0x14000b097;
        AfUnixConnectEndpointShutdown(param_1,0,0,param_4);
        *(undefined4 *)(param_1 + 0x100) = 0;
      }
    }
    *(undefined8 *)(puVar7 + -8) = 0x14000b0ab;
    ExReleasePushLockExclusiveEx(param_1 + 8,0);
    *(undefined8 *)(puVar7 + -8) = 0x14000b0b7;
    KeLeaveCriticalRegion();
    iVar6 = 0x103;
  }
  else {
    if ((uVar2 & 2) == 0) {
      iVar6 = (-(uint)((uVar2 & 8) != 0) & 0xbd) + 0xc0000184;
    }
    else {
      iVar6 = -0x3ffffdf3;
    }
    *(int *)(puVar7 + 0x20) = iVar6;
    pcVar10 = "[0x%08x] Send: Endpoint is shutdown\n";
    uVar9 = 0x415;
LAB_14000af63:
    *(undefined8 *)(puVar7 + -8) = 0x14000af74;
    AfUnixTraceLogging(2,"AfUnixDeliverEndpointSend",uVar9,pcVar10,puVar7[0x20]);
LAB_14000af74:
    *(undefined8 *)(puVar7 + -8) = 0x14000af81;
    ExReleasePushLockExclusiveEx(plVar8 + 1,0);
    *(undefined8 *)(puVar7 + -8) = 0x14000af8d;
    KeLeaveCriticalRegion();
  }
LAB_14000b0c1:
  if (plVar8 != (longlong *)0x0) {
    *(undefined8 *)(puVar7 + -8) = 0x14000b0ce;
    AfUnixEndpointDereference(plVar8);
  }
  return iVar6;
}



===== AfUnixDeliverFin @ 14000b0f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AfUnixDeliverFin(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 400);
  lVar1 = param_1 + 8;
  do {
    *(undefined8 *)(param_1 + 400) = 0;
    *(undefined8 *)(param_1 + 0x198) = 0;
    ExReleasePushLockExclusiveEx(lVar1);
    KeLeaveCriticalRegion();
    AfUnixDeliverCompleteReceiveRequests(puVar3,0);
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar1);
    puVar3 = *(undefined8 **)(param_1 + 400);
  } while (puVar3 != (undefined8 *)0x0);
  *(uint *)(param_1 + 0x104) = *(uint *)(param_1 + 0x104) | 0x40;
  ExReleasePushLockExclusiveEx(lVar1,0);
  KeLeaveCriticalRegion();
  (**(code **)(*(longlong *)(param_1 + 0x178) + 8))(*(undefined8 *)(param_1 + 0x180));
  KeEnterCriticalRegion();
  uVar2 = 0;
  ExAcquirePushLockExclusiveEx(lVar1);
  AfUnixDeliverPostIoProcess(param_1,uVar2,param_3,param_4);
  if (((*(int *)(param_1 + 0x100) == 10) || (*(int *)(param_1 + 0x100) == 0)) &&
     ((*(uint *)(param_1 + 0x104) & 1) == 0)) {
    AfUnixConnectEndpointShutdown(param_1,0,0,param_4);
    *(undefined4 *)(param_1 + 0x100) = 0;
  }
  return;
}



===== AfUnixDeliverPostIoProcess @ 14000b220 =====

void AfUnixDeliverPostIoProcess
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x104);
  if ((((uVar1 & 0x10) == 0) || ((uVar1 & 0x40) != 0)) || (*(longlong *)(param_1 + 0x1a0) != 0)) {
    uVar2 = *(uint *)(param_1 + 0x1c4);
    if (uVar2 != 0) {
      if ((uVar2 & 2) == 0) {
        if ((uVar2 & 1) == 0) {
          if ((uVar2 & 4) == 0) {
            return;
          }
          AfUnixDeliverCancelPendingIo(param_1,*(undefined4 *)(param_1 + 0x1d0));
          return;
        }
        uVar2 = *(uint *)(param_1 + 0x1c8);
        uVar3 = 0;
      }
      else {
        uVar2 = *(uint *)(param_1 + 0x1cc);
        param_4 = (ulonglong)uVar2;
        if ((*(uint *)(param_1 + 0x1c0) & 2) != 0) {
          return;
        }
        if ((uVar1 & 1) != 0) {
          return;
        }
        uVar3 = 1;
      }
      AfUnixConnectEndpointShutdown(param_1,uVar2,uVar3,param_4);
    }
  }
  else {
    AfUnixDeliverFin(param_1,(ulonglong)uVar1,param_3,param_4);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000b2a4 =====

/* WARNING: Removing unreachable block (ram,0x00014000b2cc) */
/* WARNING: Removing unreachable block (ram,0x00014000b2dc) */
/* WARNING: Removing unreachable block (ram,0x00014000b2e1) */
/* WARNING: Removing unreachable block (ram,0x00014000b2e6) */
/* WARNING: Removing unreachable block (ram,0x00014000b2f1) */
/* WARNING: Removing unreachable block (ram,0x00014000b306) */
/* WARNING: Removing unreachable block (ram,0x00014000b2fc) */
/* WARNING: Removing unreachable block (ram,0x00014000b316) */
/* WARNING: Removing unreachable block (ram,0x00014000b333) */
/* WARNING: Removing unreachable block (ram,0x00014000b342) */
/* WARNING: Removing unreachable block (ram,0x00014000b347) */
/* WARNING: Removing unreachable block (ram,0x00014000b339) */
/* WARNING: Removing unreachable block (ram,0x00014000b349) */
/* WARNING: Removing unreachable block (ram,0x00014000b34e) */
/* WARNING: Removing unreachable block (ram,0x00014000b33e) */
/* WARNING: Removing unreachable block (ram,0x00014000b2d1) */
/* WARNING: Removing unreachable block (ram,0x00014000b2da) */
/* WARNING: Removing unreachable block (ram,0x00014000b359) */
/* WARNING: Removing unreachable block (ram,0x00014000b35e) */
/* WARNING: Removing unreachable block (ram,0x00014000b350) */
/* WARNING: Removing unreachable block (ram,0x00014000b381) */
/* WARNING: Removing unreachable block (ram,0x00014000b360) */
/* WARNING: Removing unreachable block (ram,0x00014000b37a) */
/* WARNING: Removing unreachable block (ram,0x00014000b37f) */
/* WARNING: Removing unreachable block (ram,0x00014000b371) */
/* WARNING: Removing unreachable block (ram,0x00014000b376) */
/* WARNING: Removing unreachable block (ram,0x00014000b355) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000b394 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000b42c;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000b42c;
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
LAB_14000b42c:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000b480 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (plVar2 = &wil_details_featureDescriptors_a; plVar2 < &wil_details_featureDescriptors_a;
          plVar2 = plVar2 + 1) {
        if (*plVar2 != 0) {
          do {
            if (plVar2 == (longlong *)0x0) {
              return;
            }
            if ((*(uint *)plVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
            }
            plVar2 = plVar2 + 7;
            while( true ) {
              if (&UNK_140005c47 < plVar2) {
                return;
              }
              if (*plVar2 != 0) break;
              plVar2 = plVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000b500 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_14000b5fd;
  }
LAB_14000b606:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000b5fd:
  if (plVar3 == (longlong *)0x0) goto LAB_14000b606;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000b5ce:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000b5ce;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*plVar3 = *(uint *)*plVar3 ^ (*(uint *)*plVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_140005c47 < plVar3) goto LAB_14000b606;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14000b5fd;
}



===== AfUnixEndpointCreate @ 14000b62c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int AfUnixEndpointCreate
              (longlong *param_1,longlong param_2,int param_3,char *param_4,undefined8 *param_5)

{
  longlong lVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  char *pcVar10;
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [24];
  int local_a8 [2];
  undefined8 local_a0;
  undefined1 local_98 [32];
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  int *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  if (param_3 == 1) {
    uVar8 = 0x100;
  }
  else if (param_3 == 2) {
    uVar8 = 0x230;
  }
  else {
    uVar8 = 0x118;
  }
  pcVar10 = param_4;
  if ((param_2 == 0) || (iVar4 = PsChargeProcessPoolQuota(param_2,1,uVar8), -1 < iVar4)) {
    uVar9 = 0x69706e57;
    lVar6 = 0x100;
    puVar5 = (undefined8 *)ExAllocatePool2(0x100,uVar8);
    puVar7 = auStack_d8;
    if (puVar5 == (undefined8 *)0x0) {
      iVar4 = -0x3fffffe9;
    }
    else {
      puVar5[1] = 0;
      *(int *)((longlong)puVar5 + 0xdc) = param_3;
      *puVar5 = 1;
      LOCK();
      lVar1 = *param_1;
      *param_1 = *param_1 + 1;
      UNLOCK();
      puVar7 = auStack_d8;
      if (lVar1 + 1 < 2) {
        lVar6 = 0xe;
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)();
        puVar7 = auStack_d0;
      }
      puVar5[2] = param_1;
      if (param_2 != 0) {
        *(undefined8 *)(puVar7 + -8) = 0x14000b740;
        lVar6 = param_2;
        ObfReferenceObject();
      }
      puVar5[3] = param_2;
      puVar5[0x1d] = param_4;
      *(undefined2 *)(puVar5 + 7) = 1;
      *param_5 = puVar5;
      iVar4 = 0;
    }
  }
  else {
    pcVar10 = "[0x%08x] Memory pool quota exceeded.\n";
    uVar9 = 0x8b;
    lVar6 = 2;
    AfUnixTraceLogging(2,"AfUnixEndpointCreate",0x8b,"[0x%08x] Memory pool quota exceeded.\n",
                       (char)iVar4);
    puVar7 = auStack_d8;
  }
  if (2 < DAT_140006048) {
    if (((_DAT_140006058 & 0x400000000000) == 0) ||
       ((DAT_140006060 & 0x400000000000) != DAT_140006060)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (bVar3) {
      local_6c = 0;
      local_78 = &local_a0;
      local_5c = 0;
      local_4c = 0;
      local_68 = local_a8;
      *(undefined1 **)(puVar7 + 0x20) = local_98;
      local_a0 = 1;
      local_70 = 8;
      local_60 = 4;
      local_58 = "AfUnixEndpointCreate";
      local_50 = 0x15;
      *(undefined8 *)(puVar7 + -8) = 0x14000b7f0;
      local_a8[0] = iVar4;
      _tlgWriteAgg(lVar6,&DAT_14000516f,uVar9,pcVar10,*(undefined8 **)(puVar7 + 0x20));
    }
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000b7fe;
  return iVar4;
}



===== AfUnixEndpointDereference @ 14000b820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AfUnixEndpointDereference(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  LOCK();
  lVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (1 < lVar1) {
    return;
  }
  if (lVar1 == 1) {
    plVar2 = (longlong *)param_1[2];
    if ((char)param_1[0x1c] != '\0') {
      if (param_1[0x15] != 0) {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(plVar2 + 1,0);
        RtlRbRemoveNode(plVar2 + 3,param_1 + 0x16);
        param_1[0x19] = 0;
        ObfDereferenceObject(param_1[0x15]);
        param_1[0x15] = 0;
        ExReleasePushLockExclusiveEx(plVar2 + 1,0);
        KeLeaveCriticalRegion();
      }
      *(undefined1 *)(param_1 + 0x1c) = 0;
    }
    if ((code *)param_1[0x1d] != (code *)0x0) {
      (*(code *)param_1[0x1d])(param_1);
    }
    if (param_1[3] != 0) {
      if (*(int *)((longlong)param_1 + 0xdc) == 1) {
        uVar4 = 0x100;
      }
      else if (*(int *)((longlong)param_1 + 0xdc) == 2) {
        uVar4 = 0x230;
      }
      else {
        uVar4 = 0x118;
      }
      PsReturnPoolQuota(param_1[3],1,uVar4);
      ObfDereferenceObject(param_1[3]);
      param_1[3] = 0;
    }
    if (param_1[0x1a] != 0) {
      ExFreePoolWithTag(param_1[0x1a],0);
      param_1[0x1a] = 0;
    }
    if (param_1[4] != 0) {
      ZwClose();
      param_1[4] = 0;
    }
    if (param_1[6] != 0) {
      ExFreePoolWithTag(param_1[6],0);
      param_1[5] = 0;
      param_1[6] = 0;
      *(undefined2 *)((longlong)param_1 + 0x2a) = 0;
      param_1[6] = 0;
    }
    if ((code *)param_1[0x1e] != (code *)0x0) {
      (*(code *)param_1[0x1e])(param_1[0x1f],0);
    }
    ExFreePoolWithTag(param_1,0);
    LOCK();
    lVar1 = *plVar2;
    *plVar2 = *plVar2 + -1;
    UNLOCK();
    if (1 < lVar1) {
      return;
    }
    if (lVar1 == 1) {
      ExFreePoolWithTag(plVar2,0);
      return;
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(0xe);
  return;
}



===== AfUnixEndpointGetFileProperties @ 14000ba2c =====

undefined8
AfUnixEndpointGetFileProperties
          (longlong param_1,undefined8 *param_2,undefined4 *param_3,undefined8 *param_4,
          undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  char unaff_R15B;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  uVar4 = 0;
  if (*(longlong *)(param_1 + 0x30) == 0) {
    uVar4 = 0xc000000d;
    AfUnixTraceLogging(2,"AfUnixEndpointGetFileProperties",400,
                       "file path socket option not set prior to operation\n",unaff_R15B);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x2c);
    uVar2 = *(undefined4 *)(param_1 + 0x30);
    uVar3 = *(undefined4 *)(param_1 + 0x34);
    *param_3 = *(undefined4 *)(param_1 + 0x28);
    param_3[1] = uVar1;
    param_3[2] = uVar2;
    param_3[3] = uVar3;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined2 *)(param_1 + 0x2a) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *param_2 = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x20) = 0;
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = *(undefined8 *)(param_1 + 0xd0);
      *(undefined8 *)(param_1 + 0xd0) = 0;
      *param_5 = *(undefined4 *)(param_1 + 0xd8);
      *(undefined4 *)(param_1 + 0xd8) = 0;
    }
  }
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  KeLeaveCriticalRegion();
  return uVar4;
}



===== AfUnixEndpointSetEaBuffer @ 14000bb2c =====

undefined8 AfUnixEndpointSetEaBuffer(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  void *_Dst;
  undefined4 uVar3;
  char *pcVar4;
  
  if (*(ulonglong *)(param_2 + 0x28) < 0x100000000) {
    uVar1 = *(uint *)(param_2 + 0x28);
    lVar2 = PsGetCurrentProcess();
    if (*(longlong *)(lVar2 + 0x640) != 0) {
      _Dst = (void *)ExAllocatePool2(0x102,(ulonglong)uVar1,0x69706e57);
      if (_Dst == (void *)0x0) {
        return 0xc0000017;
      }
      memmove(_Dst,*(void **)(param_2 + 0x20),(ulonglong)uVar1);
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(param_1 + 8,0);
      lVar2 = *(longlong *)(param_1 + 0xd0);
      *(void **)(param_1 + 0xd0) = _Dst;
      *(uint *)(param_1 + 0xd8) = uVar1;
      ExReleasePushLockExclusiveEx(param_1 + 8,0);
      KeLeaveCriticalRegion();
      if (lVar2 == 0) {
        return 0;
      }
      ExFreePoolWithTag(lVar2,0);
      return 0;
    }
    pcVar4 = "[0x%08x] Non-pico provider.\n";
    uVar3 = 0x2ca;
  }
  else {
    pcVar4 = "[0x%08x] EA length > ULONG_MAX\n";
    uVar3 = 0x2b8;
  }
  AfUnixTraceLogging(2,"AfUnixEndpointSetEaBuffer",uVar3,pcVar4,'\"');
  return 0xc0000022;
}



===== AfUnixEndpointSetFilePathOption @ 14000bc70 =====

int AfUnixEndpointSetFilePathOption(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  ulonglong _Size;
  undefined4 uVar8;
  char *pcVar9;
  longlong lVar10;
  longlong local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  longlong lStack_20;
  
  local_res10 = 0;
  lVar10 = 0;
  local_38 = 0;
  uStack_30 = (void *)0x0;
  local_28 = 0;
  lStack_20 = 0;
  RtlInitUnicodeString(&local_38,0);
  RtlInitUnicodeString(&local_28,0);
  if (*(ulonglong *)(param_2 + 0x28) < 10) {
    pcVar9 = "[0x%08x] Invalid input length\n";
    uVar8 = 0x322;
LAB_14000bce2:
    iVar6 = -0x3ffffff3;
  }
  else {
    plVar1 = *(longlong **)(param_2 + 0x20);
    _Size = *(ulonglong *)(param_2 + 0x28) - 8;
    if (0x7fff < _Size) {
      pcVar9 = "[0x%08x] Invalid path length\n";
      uVar8 = 0x330;
      goto LAB_14000bce2;
    }
    if (*plVar1 == 0) {
LAB_14000bdb0:
      uStack_30 = (void *)ExAllocatePool2(0x102,_Size,0x69706e57);
      if (uStack_30 == (void *)0x0) {
        iVar6 = -0x3fffffe9;
        uStack_30 = (void *)0x0;
      }
      else {
        memmove(uStack_30,plVar1 + 1,_Size);
        local_38._0_4_ = CONCAT22((short)_Size,(short)_Size);
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(param_1 + 8,0);
        uVar2 = local_38._4_4_;
        uVar8 = (undefined4)local_38;
        lVar7 = local_res10;
        local_28 = *(undefined8 *)(param_1 + 0x28);
        lStack_20 = *(longlong *)(param_1 + 0x30);
        lVar10 = *(longlong *)(param_1 + 0x20);
        local_res10 = 0;
        *(longlong *)(param_1 + 0x20) = lVar7;
        uVar3 = (undefined4)uStack_30;
        uVar4 = uStack_30._4_4_;
        local_38 = 0;
        uStack_30 = (void *)0x0;
        *(undefined4 *)(param_1 + 0x28) = uVar8;
        *(undefined4 *)(param_1 + 0x2c) = uVar2;
        *(undefined4 *)(param_1 + 0x30) = uVar3;
        *(undefined4 *)(param_1 + 0x34) = uVar4;
        ExReleasePushLockExclusiveEx(param_1 + 8,0);
        KeLeaveCriticalRegion();
        iVar6 = 0;
      }
      goto LAB_14000be5e;
    }
    lVar7 = PsGetCurrentProcess();
    if (*(longlong *)(lVar7 + 0x640) == 0) {
      pcVar9 = "[0x%08x] Non-pico provider.\n";
      uVar8 = 0x342;
      goto LAB_14000bce2;
    }
    lVar7 = *plVar1;
    cVar5 = ObIsKernelHandle(lVar7);
    if (cVar5 == '\0') {
      pcVar9 = "[0x%08x] Invalid handle.\n";
      uVar8 = 0x358;
      goto LAB_14000bce2;
    }
    iVar6 = IoConvertFileHandleToKernelHandle(lVar7,0,0,0,&local_res10);
    if (-1 < iVar6) goto LAB_14000bdb0;
    pcVar9 = "[0x%08x] IoConvertFileHandleToKernelHandle\n";
    uVar8 = 0x364;
  }
  AfUnixTraceLogging(2,"AfUnixEndpointSetFilePathOption",uVar8,pcVar9,(char)iVar6);
LAB_14000be5e:
  if (uStack_30 != (void *)0x0) {
    ExFreePoolWithTag(uStack_30,0);
  }
  if (lStack_20 != 0) {
    ExFreePoolWithTag(lStack_20,0);
  }
  if (local_res10 != 0) {
    ZwClose();
  }
  if (lVar10 != 0) {
    ZwClose(lVar10);
  }
  return iVar6;
}



===== AfUnixEndpointSetSocketOption @ 14000bed8 =====

int AfUnixEndpointSetSocketOption(longlong param_1,int param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_2 == 0xfffc) || (param_2 == 0xffff)) {
    if (*(int *)(param_3 + 0x18) == -0x68000000) {
      iVar1 = AfUnixEndpointSetFilePathOption(param_1,param_3);
    }
    else {
      if (*(int *)(param_3 + 0x18) != -0x67ffffff) {
        AfUnixTraceLogging(2,"AfUnixEndpointSetSocketOption",0x3dc,
                           "[0x%08x] Invalid socket option{%d}\n",-0x45);
        return -0x3fffff45;
      }
      uVar2 = AfUnixEndpointSetEaBuffer(param_1,param_3);
      iVar1 = (int)uVar2;
    }
  }
  else {
    iVar1 = -0x3fffff45;
    AfUnixTraceLogging(2,"AfUnixEndpointSetSocketOption",0x3c8,
                       "[0x%08x] Invalid level{%d}, option{%d} for socket option\n",-0x45);
  }
  return iVar1;
}



===== AfUnixTlEndpointClose @ 14000bf90 =====

undefined8 AfUnixTlEndpointClose(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = param_2[1];
  param_1[0x1e] = *param_2;
  param_1[0x1f] = lVar1;
  AfUnixEndpointDereference(param_1);
  return 0x103;
}



===== AfUnixTlEndpointIoControl @ 14000bfc0 =====

int AfUnixTlEndpointIoControl(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x10);
  if (iVar1 == 0) {
    iVar1 = AfUnixEndpointIoctl(param_1,param_2);
  }
  else {
    if (iVar1 == 1) {
      iVar1 = *(int *)(param_2 + 0x14);
    }
    else {
      if (iVar1 == 2) {
        AfUnixTraceLogging(2,"AfUnixTlEndpointIoControl",0x271,
                           "[0x%08x] TlGetSockOptIoControlType unsupported\n",-0x45);
        return -0x3fffff45;
      }
      if (iVar1 != 3) {
        AfUnixTraceLogging(2,"AfUnixTlEndpointIoControl",0x28a,
                           "[0x%08x] invalid io control type{%d}\n",-0x45);
        return -0x3fffff45;
      }
      iVar1 = 0xfffc;
    }
    iVar1 = AfUnixEndpointSetSocketOption(param_1,iVar1,param_2);
  }
  return iVar1;
}



===== AfUnixEndpointIoctl @ 14000c070 =====

int AfUnixEndpointIoctl(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  char in_stack_ffffffffffffffe8;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == 4) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 8,0);
    if (*(int *)(param_1 + 0xdc) == 2) {
      if ((*(uint *)(param_1 + 0x104) & 1) == 0) {
        AfUnixDeliverCancelPendingIo(param_1,0xc0000120);
      }
      iVar1 = 0;
    }
    else {
      iVar1 = -0x3ffffec0;
      AfUnixTraceLogging(2,"AfUnixEndpointIoctlCancelIo",0x14c,
                         "[0x%08x] Cancel I/O request on invalid endpoint\n",'@');
    }
    ExReleasePushLockExclusiveEx(param_1 + 8,0);
    KeLeaveCriticalRegion();
  }
  else if (iVar1 == 8) {
    iVar1 = AfUnixEndpointIoctlBind(param_1,param_2);
  }
  else {
    if (iVar1 == 0xc) {
      AfUnixTraceLogging(2,"AfUnixEndpointIoctlUnbind",0x202,"unbind unimplemented\n",
                         in_stack_ffffffffffffffe8);
      return -0x3ffffff3;
    }
    if (iVar1 == 0x10) {
      uVar2 = AfUnixEndpointIoctlQueryLocalAddress(param_1,param_2);
      iVar1 = (int)uVar2;
    }
    else {
      if (iVar1 != 0x14) {
        return -0x3ffffff0;
      }
      iVar1 = AfUnixEndpointIoctlQueryRemoteAddress(param_1,param_2);
    }
  }
  return iVar1;
}



===== AfUnixEndpointIoctlBind @ 14000c184 =====

int AfUnixEndpointIoctlBind(longlong param_1,longlong param_2)

{
  short sVar1;
  short *psVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  char *pcVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong local_res18;
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar13;
  ulonglong *puVar12;
  longlong local_68;
  longlong local_60;
  longlong local_58 [2];
  ushort local_48 [4];
  longlong lStack_40;
  
  local_res18 = local_res18 & 0xffffffff00000000;
  lVar10 = 0;
  lVar11 = 0;
  lVar9 = 0;
  local_res20 = 0;
  local_60 = 0;
  local_68 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  lStack_40 = 0;
  local_58[0] = 0;
  bVar3 = KeGetCurrentIrql();
  if (1 < bVar3) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar3,0,0);
  }
  if (*(ulonglong *)(param_2 + 0x28) < 0x6e) {
    pcVar8 = "[0x%08x] Invalid input buffer length.\n";
    uVar7 = 0xab;
  }
  else {
    psVar2 = *(short **)(param_2 + 0x20);
    if (*psVar2 == 1) {
      lVar6 = 0;
      if ((char)psVar2[1] == '\0') {
LAB_14000c313:
        KeEnterCriticalRegion();
        local_res18 = param_1 + 8;
        ExAcquirePushLockExclusiveEx(local_res18,0);
        if (*(char *)(param_1 + 0xe0) == '\0') {
          if (lVar6 == 0) {
            iVar4 = 0;
          }
          else {
            KeEnterCriticalRegion();
            ExAcquirePushLockExclusiveEx(*(longlong *)(param_1 + 0x10) + 8,0);
            uVar5 = AfUnixAddressInsert(*(longlong *)(param_1 + 0x10),param_1,lVar6);
            iVar4 = (int)uVar5;
            ExReleasePushLockExclusiveEx(*(longlong *)(param_1 + 0x10) + 8,0);
            KeLeaveCriticalRegion();
            if (iVar4 != 0) {
              uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
              AfUnixTraceLogging(2,"AfUnixEndpointIoctlBind",0xfd,"[0x%08x] Insert address\n",
                                 (char)uVar5);
              goto LAB_14000c459;
            }
          }
          uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
          uVar5 = *(undefined8 *)(psVar2 + 4);
          *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)psVar2;
          *(undefined8 *)(param_1 + 0x40) = uVar5;
          uVar5 = *(undefined8 *)(psVar2 + 0xc);
          *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(psVar2 + 8);
          *(undefined8 *)(param_1 + 0x50) = uVar5;
          uVar5 = *(undefined8 *)(psVar2 + 0x14);
          *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(psVar2 + 0x10);
          *(undefined8 *)(param_1 + 0x60) = uVar5;
          uVar5 = *(undefined8 *)(psVar2 + 0x1c);
          *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)(psVar2 + 0x18);
          *(undefined8 *)(param_1 + 0x70) = uVar5;
          uVar5 = *(undefined8 *)(psVar2 + 0x24);
          *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(psVar2 + 0x20);
          *(undefined8 *)(param_1 + 0x80) = uVar5;
          uVar5 = *(undefined8 *)(psVar2 + 0x2c);
          *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(psVar2 + 0x28);
          *(undefined8 *)(param_1 + 0x90) = uVar5;
          *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(psVar2 + 0x30);
          *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(psVar2 + 0x34);
          sVar1 = psVar2[0x36];
          *(longlong *)(param_1 + 0xa8) = lVar6;
          lVar6 = 0;
          *(short *)(param_1 + 0xa4) = sVar1;
          *(undefined1 *)(param_1 + 0xe0) = 1;
        }
        else {
          AfUnixTraceLogging(2,"AfUnixEndpointIoctlBind",0xdc,"Socket already bound\n",
                             (char)in_stack_ffffffffffffff78);
          uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
          iVar4 = -0x3ffffdc8;
        }
LAB_14000c459:
        ExReleasePushLockExclusiveEx(local_res18,0);
        KeLeaveCriticalRegion();
      }
      else {
        puVar12 = &local_res18;
        uVar5 = AfUnixEndpointGetFileProperties
                          (param_1,&local_68,(undefined4 *)local_48,&local_res20,
                           (undefined4 *)puVar12);
        lVar9 = local_68;
        lVar10 = local_res20;
        iVar4 = (int)uVar5;
        uVar13 = (undefined4)((ulonglong)puVar12 >> 0x20);
        if (iVar4 < 0) {
          AfUnixTraceLogging(2,"AfUnixEndpointIoctlBind",200,
                             "[0x%08x] AfUnixEndpointGetFileProperties\n",(char)uVar5);
          lVar9 = local_68;
          lVar10 = local_res20;
        }
        else {
          in_stack_ffffffffffffff78 = CONCAT44(uVar13,(undefined4)local_res18);
          iVar4 = AfUnixAddressCreateFile
                            (*(longlong *)(param_1 + 0x18),local_48,local_68,local_res20,
                             (undefined4)local_res18,&local_60,local_58);
          if (-1 < iVar4) {
            lVar6 = local_58[0];
            lVar11 = local_60;
            goto LAB_14000c313;
          }
          uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
          AfUnixTraceLogging(2,"AfUnixEndpointIoctlBind",0xd5,"[0x%08x] AfUnixAddressCreateFile\n",
                             (char)iVar4);
          lVar6 = local_58[0];
          lVar11 = local_60;
        }
      }
      if (lVar10 != 0) {
        ExFreePoolWithTag(lVar10,0);
      }
      if (lVar6 != 0) {
        ObfDereferenceObject(lVar6);
      }
      if (lVar9 != 0) {
        ZwClose(lVar9);
      }
      goto LAB_14000c4b5;
    }
    pcVar8 = "[0x%08x] AfUnixAddressValidate\n";
    uVar7 = 0xb2;
  }
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  iVar4 = -0x3ffffff3;
  AfUnixTraceLogging(2,"AfUnixEndpointIoctlBind",uVar7,pcVar8,'\r');
LAB_14000c4b5:
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0);
  }
  if (lVar11 != 0) {
    if (iVar4 < 0) {
      local_res18 = CONCAT71(local_res18._1_7_,1);
      local_58[0] = 0;
      local_58[1] = 0;
      ZwSetInformationFile(lVar11,local_58,&local_res18,1,CONCAT44(uVar13,0xd));
    }
    ZwClose(lVar11);
  }
  return iVar4;
}



===== AfUnixEndpointIoctlQueryLocalAddress @ 14000c538 =====

undefined8 AfUnixEndpointIoctlQueryLocalAddress(longlong param_1,longlong param_2)

{
  size_t _Size;
  undefined8 uVar1;
  void *_Dst;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  if (*(ulonglong *)(param_2 + 0x38) < 0x6e) {
    uVar1 = 0xc0000206;
    AfUnixTraceLogging(2,"AfUnixEndpointIoctlQueryLocalAddress",0x18a,
                       "[0x%08x] Incorrect buffer length\n",'\x06');
  }
  else {
    _Dst = *(void **)(param_2 + 0x30);
    uVar1 = 0;
    if (*(char *)(param_1 + 0xe0) == '\0') {
      _Size = 2;
    }
    else {
      _Size = AfUnixAddressGetSize(param_1 + 0x38);
    }
    *(size_t *)(param_2 + 0x48) = _Size;
    memmove(_Dst,(void *)(param_1 + 0x38),_Size);
  }
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== AfUnixEndpointIoctlQueryRemoteAddress @ 14000c60c =====

undefined4 AfUnixEndpointIoctlQueryRemoteAddress(longlong param_1,longlong param_2)

{
  size_t _Size;
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  void *_Src;
  void *_Dst;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 8,0);
  if (*(ulonglong *)(param_2 + 0x38) < 0x6e) {
    uVar1 = 0xc0000206;
    pcVar3 = "[0x%08x] Incorrect buffer length\n";
    uVar2 = 0x1ca;
  }
  else {
    if (*(int *)(param_1 + 0xdc) == 2) {
      _Dst = *(void **)(param_2 + 0x30);
      _Src = (void *)(param_1 + 0x108);
      _Size = AfUnixAddressGetSize((longlong)_Src);
      *(size_t *)(param_2 + 0x48) = _Size;
      memmove(_Dst,_Src,_Size);
      uVar1 = 0;
      goto LAB_14000c6b6;
    }
    uVar1 = 0xc0000140;
    pcVar3 = "[0x%08x] getpeername on invalid endpoint\n";
    uVar2 = 0x1d4;
  }
  AfUnixTraceLogging(2,"AfUnixEndpointIoctlQueryRemoteAddress",uVar2,pcVar3,(char)uVar1);
LAB_14000c6b6:
  ExReleasePushLockExclusiveEx(param_1 + 8,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== AfUnixTlListenEndpointIoControl @ 14000c6f0 =====

int AfUnixTlListenEndpointIoControl(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x10) == 0) {
    iVar1 = AfUnixEndpointIoctl(param_1,param_2);
  }
  else {
    iVar1 = -0x3fffff45;
  }
  return iVar1;
}



===== AfUnixTlCancel @ 14000c720 =====

undefined8 AfUnixTlCancel(void)

{
  char in_stack_fffffffffffffff8;
  
  AfUnixTraceLogging(2,"AfUnixTlCancel",0x7d,"AfUnixTlCancel unimplemented.\n",
                     in_stack_fffffffffffffff8);
  return 0;
}



===== AfUnixTlConnect @ 14000c750 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AfUnixTlConnect(longlong *param_1,undefined8 *param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  byte bVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  ulonglong uVar12;
  undefined4 uVar13;
  char *pcVar14;
  undefined8 uVar15;
  longlong *plVar16;
  undefined8 uStackY_110;
  undefined1 auStackY_108 [8];
  undefined1 auStackY_100 [24];
  longlong *local_d8;
  longlong *local_d0;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8;
  longlong *local_b0;
  longlong local_a8;
  longlong *local_a0;
  undefined8 local_98;
  longlong lStack_90;
  undefined1 local_88 [16];
  ulonglong *local_78;
  longlong *local_70;
  longlong *local_68;
  undefined **local_60;
  longlong local_50;
  longlong local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b0 = param_1;
  memset(local_88,0,0x50);
  bVar5 = KeGetCurrentIrql();
  if (1 < bVar5) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar5,0);
  }
  local_a0 = (longlong *)param_2[0xb];
  plVar11 = (longlong *)0x0;
  local_c0 = 0;
  plVar16 = (longlong *)0x0;
  local_c8 = 0;
  local_a8 = param_2[3];
  local_d0 = (longlong *)0x0;
  local_98 = 0;
  lStack_90 = 0;
  local_d8 = (longlong *)0x0;
  if ((short)*local_a0 == 1) {
    if (*(char *)((longlong)local_a0 + 2) != '\0') {
      lVar2 = *(longlong *)(local_a8 + 0x18);
      uVar15 = 0;
      local_b8 = lVar2;
      uVar7 = AfUnixEndpointGetFileProperties
                        (local_a8,&local_c0,(undefined4 *)&local_98,(undefined8 *)0x0,
                         (undefined4 *)0x0);
      uVar12 = uVar7 & 0xffffffff;
      if ((int)uVar7 < 0) {
        AfUnixTraceLogging(2,"AfUnixTlConnect",0xea,"[0x%08x] AfUnixEndpointGetFileProperties\n",
                           (char)uVar7);
        puVar10 = auStackY_108;
      }
      else {
        uVar6 = AfUnixAddressOpenFile(lVar2,&local_98,local_c0,uVar15,&local_c8);
        uVar12 = (ulonglong)uVar6;
        if ((int)uVar6 < 0) {
          AfUnixTraceLogging(2,"AfUnixTlConnect",0xf9,"[0x%08x] AfUnixAddressOpenFile\n",(char)uVar6
                            );
          puVar10 = auStackY_108;
          if (uVar6 == 0xc0000034) {
            uVar12 = 0xc0000236;
            puVar10 = auStackY_108;
          }
        }
        else {
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(param_1 + 1,0);
          puVar8 = AfUnixAddressReferenceEndpoint((longlong)param_1,local_c8);
          ExReleasePushLockExclusiveEx(param_1 + 1,0);
          KeLeaveCriticalRegion();
          plVar3 = local_b0;
          if ((puVar8 == (ulonglong *)0x0) || (*(int *)((longlong)puVar8 + 0xdc) != 3)) {
            uVar12 = 0xc0000236;
            AfUnixTraceLogging(2,"AfUnixTlConnect",0x110,"[0x%08x] Connecting to invalid endpoint\n"
                               ,'6');
            puVar9 = auStackY_108;
            puVar10 = auStackY_108;
            if (puVar8 != (ulonglong *)0x0) goto LAB_14000cd6f;
          }
          else {
            uVar6 = AfUnixEndpointCreate
                              (local_b0,local_b8,2,(char *)AfUnixConnectEndpointDestruct,&local_d0);
            plVar16 = local_d0;
            puVar9 = auStackY_108;
            uVar12 = (ulonglong)uVar6;
            if ((int)uVar6 < 0) {
              pcVar14 = "[0x%08x] AfUnixConnectEndpointCreate\n";
              uVar13 = 0x123;
LAB_14000c98c:
              *(undefined8 *)(puVar9 + -8) = 0x14000c998;
              AfUnixTraceLogging(2,"AfUnixTlConnect",uVar13,pcVar14,puVar9[0x20]);
              plVar16 = local_d0;
            }
            else {
              local_d0[2] = (longlong)plVar3;
              lVar2 = *(longlong *)(local_a8 + 0x40);
              local_d0[7] = *(longlong *)(local_a8 + 0x38);
              local_d0[8] = lVar2;
              lVar2 = *(longlong *)(local_a8 + 0x50);
              local_d0[9] = *(longlong *)(local_a8 + 0x48);
              local_d0[10] = lVar2;
              lVar2 = *(longlong *)(local_a8 + 0x60);
              local_d0[0xb] = *(longlong *)(local_a8 + 0x58);
              local_d0[0xc] = lVar2;
              lVar2 = *(longlong *)(local_a8 + 0x70);
              local_d0[0xd] = *(longlong *)(local_a8 + 0x68);
              local_d0[0xe] = lVar2;
              lVar2 = *(longlong *)(local_a8 + 0x80);
              local_d0[0xf] = *(longlong *)(local_a8 + 0x78);
              local_d0[0x10] = lVar2;
              lVar2 = *(longlong *)(local_a8 + 0x90);
              local_d0[0x11] = *(longlong *)(local_a8 + 0x88);
              local_d0[0x12] = lVar2;
              local_d0[0x13] = *(longlong *)(local_a8 + 0x98);
              *(undefined4 *)(local_d0 + 0x14) = *(undefined4 *)(local_a8 + 0xa0);
              *(undefined2 *)((longlong)local_d0 + 0xa4) = *(undefined2 *)(local_a8 + 0xa4);
              lVar2 = local_a0[1];
              local_d0[0x21] = *local_a0;
              local_d0[0x22] = lVar2;
              lVar2 = local_a0[3];
              local_d0[0x23] = local_a0[2];
              local_d0[0x24] = lVar2;
              lVar2 = local_a0[5];
              local_d0[0x25] = local_a0[4];
              local_d0[0x26] = lVar2;
              lVar2 = local_a0[7];
              local_d0[0x27] = local_a0[6];
              local_d0[0x28] = lVar2;
              lVar2 = local_a0[9];
              local_d0[0x29] = local_a0[8];
              local_d0[0x2a] = lVar2;
              lVar2 = local_a0[0xb];
              local_d0[0x2b] = local_a0[10];
              local_d0[0x2c] = lVar2;
              local_d0[0x2d] = local_a0[0xc];
              *(int *)(local_d0 + 0x2e) = (int)local_a0[0xd];
              *(undefined2 *)((longlong)local_d0 + 0x174) =
                   *(undefined2 *)((longlong)local_a0 + 0x6c);
              local_d0[0x2f] = param_2[0xe];
              local_d0[0x30] = param_2[9];
              AfUnixBaseEndpointDisassociateAndAssociateOther
                        ((longlong)plVar3,local_a8,(longlong)local_d0);
              uVar6 = AfUnixEndpointCreate
                                (plVar3,puVar8[3],2,(char *)AfUnixConnectEndpointDestruct,&local_d8)
              ;
              plVar11 = local_d8;
              uVar12 = (ulonglong)uVar6;
              if ((int)uVar6 < 0) {
                AfUnixTraceLogging(2,"AfUnixTlConnect",0x14f,
                                   "[0x%08x] AfUnixConnectEndpointCreate\n",(char)uVar6);
                puVar9 = auStackY_108;
                plVar11 = local_d8;
              }
              else {
                local_d8[2] = puVar8[2];
                puVar1 = (ulonglong *)(local_d8 + 7);
                uVar7 = puVar8[8];
                plVar3 = local_d8 + 0x21;
                *puVar1 = puVar8[7];
                local_d8[8] = uVar7;
                uVar7 = puVar8[10];
                local_d8[9] = puVar8[9];
                local_d8[10] = uVar7;
                uVar7 = puVar8[0xc];
                local_d8[0xb] = puVar8[0xb];
                local_d8[0xc] = uVar7;
                uVar7 = puVar8[0xe];
                local_d8[0xd] = puVar8[0xd];
                local_d8[0xe] = uVar7;
                uVar7 = puVar8[0x10];
                local_d8[0xf] = puVar8[0xf];
                local_d8[0x10] = uVar7;
                uVar7 = puVar8[0x12];
                local_d8[0x11] = puVar8[0x11];
                local_d8[0x12] = uVar7;
                local_d8[0x13] = puVar8[0x13];
                *(int *)(local_d8 + 0x14) = (int)puVar8[0x14];
                *(undefined2 *)((longlong)local_d8 + 0xa4) =
                     *(undefined2 *)((longlong)puVar8 + 0xa4);
                *(char *)(local_d8 + 0x1c) = (char)puVar8[0x1c];
                lVar2 = plVar16[8];
                *plVar3 = plVar16[7];
                local_d8[0x22] = lVar2;
                lVar2 = plVar16[10];
                local_d8[0x23] = plVar16[9];
                local_d8[0x24] = lVar2;
                lVar2 = plVar16[0xc];
                local_d8[0x25] = plVar16[0xb];
                local_d8[0x26] = lVar2;
                lVar2 = plVar16[0xe];
                local_d8[0x27] = plVar16[0xd];
                local_d8[0x28] = lVar2;
                lVar2 = plVar16[0x10];
                local_d8[0x29] = plVar16[0xf];
                local_d8[0x2a] = lVar2;
                lVar2 = plVar16[0x12];
                local_d8[0x2b] = plVar16[0x11];
                local_d8[0x2c] = lVar2;
                local_d8[0x2d] = plVar16[0x13];
                *(int *)(local_d8 + 0x2e) = (int)plVar16[0x14];
                *(undefined2 *)((longlong)local_d8 + 0x174) =
                     *(undefined2 *)((longlong)plVar16 + 0xa4);
                memset(local_88,0,0x50);
                puVar9 = auStackY_108;
                local_68 = plVar11;
                local_60 = &AfUnixTlConnectEndpointProviderDispatch;
                LOCK();
                lVar2 = *plVar16;
                *plVar16 = *plVar16 + 1;
                UNLOCK();
                local_78 = puVar1;
                local_70 = plVar3;
                if (lVar2 + 1 < 2) {
                  pcVar4 = (code *)swi(0x29);
                  (*pcVar4)(0xe);
                  puVar9 = auStackY_100;
                }
                local_d8[0x31] = (longlong)local_d0;
                LOCK();
                lVar2 = *local_d8;
                *local_d8 = *local_d8 + 1;
                UNLOCK();
                if (lVar2 + 1 < 2) {
                  pcVar4 = (code *)swi(0x29);
                  (*pcVar4)(0xe);
                  puVar9 = puVar9 + 8;
                }
                plVar16 = local_d0;
                plVar11 = local_d8;
                local_d0[0x31] = (longlong)local_d8;
                if (local_d8[3] != 0) {
                  *(undefined8 *)(puVar9 + -8) = 0x14000cc5c;
                  ObfReferenceObject();
                  plVar16[0x45] = plVar11[3];
                }
                if (plVar16[3] != 0) {
                  *(undefined8 *)(puVar9 + -8) = 0x14000cc7c;
                  ObfReferenceObject();
                  plVar11[0x45] = plVar16[3];
                }
                *(undefined4 *)(plVar16 + 0x20) = 4;
                *(undefined4 *)(plVar11 + 0x20) = 4;
                LOCK();
                lVar2 = *plVar11;
                *plVar11 = *plVar11 + 1;
                UNLOCK();
                if (lVar2 + 1 < 2) {
                  pcVar4 = (code *)swi(0x29);
                  (*pcVar4)(0xe);
                  puVar9 = puVar9 + 8;
                }
                uVar7 = puVar8[0x22];
                pcVar4 = *(code **)(puVar8[0x21] + 8);
                *(undefined8 *)(puVar9 + -8) = 0x14000cccd;
                uVar6 = (*pcVar4)(uVar7,local_88);
                plVar11 = local_d8;
                uVar12 = (ulonglong)uVar6;
                if ((int)uVar6 < 0) {
                  *(undefined8 *)(puVar9 + -8) = 0x14000ccdf;
                  AfUnixEndpointDereference(local_d8);
                  pcVar14 = "[0x%08x] ConnectEvent callback failed.\n";
                  *(uint *)(puVar9 + 0x20) = uVar6;
                  uVar13 = 0x1ad;
                  goto LAB_14000c98c;
                }
                local_d8[0x30] = local_50;
                local_d8[0x2f] = local_48;
                pcVar4 = (code *)*param_2;
                uVar15 = param_2[1];
                *(undefined8 *)(puVar9 + -8) = 0x14000cd2f;
                (*pcVar4)(uVar15,uVar12,local_d0,&AfUnixTlConnectEndpointProviderDispatch);
                *(undefined8 *)(puVar9 + -8) = 0x14000cd37;
                AfUnixEndpointDereference(plVar11);
                plVar11 = (longlong *)0x0;
                uVar12 = 0x103;
                plVar16 = (longlong *)0x0;
              }
            }
LAB_14000cd6f:
            *(undefined8 *)(puVar9 + -8) = 0x14000cd77;
            AfUnixEndpointDereference((longlong *)puVar8);
            puVar10 = puVar9;
          }
          if (plVar16 != (longlong *)0x0) {
            plVar3 = (longlong *)plVar16[0x31];
            if (plVar3 != (longlong *)0x0) {
              *(undefined8 *)(puVar10 + -8) = 0x14000cd8d;
              AfUnixEndpointDereference(plVar3);
              plVar16[0x31] = 0;
            }
            *(undefined8 *)(puVar10 + -8) = 0x14000cd9d;
            AfUnixEndpointDereference(plVar16);
          }
          if (plVar11 != (longlong *)0x0) {
            plVar16 = (longlong *)plVar11[0x31];
            if (plVar16 != (longlong *)0x0) {
              *(undefined8 *)(puVar10 + -8) = 0x14000cdb3;
              AfUnixEndpointDereference(plVar16);
              plVar11[0x31] = 0;
            }
            *(undefined8 *)(puVar10 + -8) = 0x14000cdc3;
            AfUnixEndpointDereference(plVar11);
          }
        }
        if (local_c8 != 0) {
          *(undefined8 *)(puVar10 + -8) = 0x14000cdd3;
          ObfDereferenceObject();
        }
      }
      if (local_c0 != 0) {
        *(undefined8 *)(puVar10 + -8) = 0x14000cde8;
        ZwClose();
      }
      goto LAB_14000cded;
    }
    pcVar14 = "[0x%08x] connect to abstract address\n";
    uVar13 = 0xda;
  }
  else {
    pcVar14 = "[0x%08x] AfUnixAddressValidate\n";
    uVar13 = 0xcd;
  }
  uVar12 = 0xc000000d;
  AfUnixTraceLogging(2,"AfUnixTlConnect",uVar13,pcVar14,'\r');
  puVar10 = auStackY_108;
LAB_14000cded:
  if (lStack_90 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x14000cdff;
    ExFreePoolWithTag(lStack_90,0);
  }
  *(undefined8 *)(puVar10 + -8) = 0x14000ce12;
  return uVar12;
}



===== AfUnixTlConnectAndSend @ 14000ce40 =====

undefined8 AfUnixTlConnectAndSend(void)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar1,0,0);
  }
  return 0xc000022d;
}



===== AfUnixTlEndpointCreate @ 14000ce90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AfUnixTlEndpointCreate(longlong *param_1,undefined8 *param_2)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *local_res18 [2];
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar1,0,0);
  }
  local_res18[0] = (longlong *)0x0;
  lVar3 = param_2[5];
  if (lVar3 == 0) {
    lVar3 = PsGetCurrentProcess();
  }
  iVar2 = AfUnixEndpointCreate(param_1,lVar3,1,(char *)0x0,local_res18);
  if (iVar2 < 0) {
    AfUnixTraceLogging(2,"AfUnixTlEndpointCreate",0x26f,"[0x%08x] AfUnixBaseEndpointCreate\n",
                       (char)iVar2);
    plVar4 = local_res18[0];
  }
  else {
    (*(code *)*param_2)(param_2[1],0,local_res18[0],&AfUnixTlEndpointProviderDispatch);
    plVar4 = (longlong *)0x0;
    iVar2 = 0x103;
  }
  if (plVar4 != (longlong *)0x0) {
    AfUnixEndpointDereference(plVar4);
  }
  return iVar2;
}



===== AfUnixTlIoControl @ 14000cf80 =====

undefined8 AfUnixTlIoControl(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar1,0,0);
  }
  AfUnixTraceLogging(2,"AfUnixTlIoControl",0x2b5,"AfUnixTlIoControl unimplemented. Code: 0x%x\n",
                     (char)*(undefined4 *)(param_2 + 0x10));
  return 0;
}



===== AfUnixTlListen @ 14000cff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AfUnixTlListen(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  longlong *plVar5;
  longlong *local_res18;
  
  bVar3 = KeGetCurrentIrql();
  if (1 < bVar3) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar3,0,0);
  }
  local_res18 = (longlong *)0x0;
  if (*(int *)(param_2 + 2) < 0) {
    lVar1 = param_2[3];
    iVar4 = AfUnixEndpointCreate(param_1,*(longlong *)(lVar1 + 0x18),3,(char *)0x0,&local_res18);
    plVar5 = local_res18;
    if (iVar4 < 0) {
      AfUnixTraceLogging(2,"AfUnixTlListen",0x308,"[0x%08x] AfUnixListenEndpointCreate\n",
                         (char)iVar4);
      plVar5 = local_res18;
    }
    else {
      lVar2 = *(longlong *)(lVar1 + 0x40);
      local_res18[7] = *(longlong *)(lVar1 + 0x38);
      local_res18[8] = lVar2;
      lVar2 = *(longlong *)(lVar1 + 0x50);
      local_res18[9] = *(longlong *)(lVar1 + 0x48);
      local_res18[10] = lVar2;
      lVar2 = *(longlong *)(lVar1 + 0x60);
      local_res18[0xb] = *(longlong *)(lVar1 + 0x58);
      local_res18[0xc] = lVar2;
      lVar2 = *(longlong *)(lVar1 + 0x70);
      local_res18[0xd] = *(longlong *)(lVar1 + 0x68);
      local_res18[0xe] = lVar2;
      lVar2 = *(longlong *)(lVar1 + 0x80);
      local_res18[0xf] = *(longlong *)(lVar1 + 0x78);
      local_res18[0x10] = lVar2;
      lVar2 = *(longlong *)(lVar1 + 0x90);
      local_res18[0x11] = *(longlong *)(lVar1 + 0x88);
      local_res18[0x12] = lVar2;
      local_res18[0x13] = *(longlong *)(lVar1 + 0x98);
      *(undefined4 *)(local_res18 + 0x14) = *(undefined4 *)(lVar1 + 0xa0);
      *(undefined2 *)((longlong)local_res18 + 0xa4) = *(undefined2 *)(lVar1 + 0xa4);
      local_res18[0x21] = param_2[0xb];
      local_res18[0x22] = param_2[9];
      AfUnixBaseEndpointDisassociateAndAssociateOther((longlong)param_1,lVar1,(longlong)local_res18)
      ;
      *(undefined4 *)(plVar5 + 0x20) = 1;
      (*(code *)*param_2)(param_2[1],0,plVar5,&AfUnixTlListenEndpointProviderDispatch);
      plVar5 = (longlong *)0x0;
      iVar4 = 0x103;
    }
    if (plVar5 != (longlong *)0x0) {
      AfUnixEndpointDereference(plVar5);
    }
  }
  else {
    iVar4 = -0x3ffffff0;
    AfUnixTraceLogging(2,"AfUnixTlListen",0x2ef,"[0x%08x] Invalid flag: 0x%x\n",'\x10');
  }
  return iVar4;
}



===== AfUnixTlReleaseIndicationList @ 14000d1b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AfUnixTlReleaseIndicationList(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  byte bVar2;
  undefined8 *puVar3;
  
  bVar2 = KeGetCurrentIrql();
  if (1 < bVar2) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(10,0,bVar2,0,0);
  }
  puVar3 = *(undefined8 **)(param_2 + 0x10);
  while (puVar3 != (undefined8 *)0x0) {
    (*(code *)puVar3[4])(puVar3[5],*(undefined4 *)(puVar3 + 7),puVar3[8]);
    puVar1 = (undefined8 *)*puVar3;
    ExFreePoolWithTag(puVar3,0);
    puVar3 = puVar1;
  }
  return 0;
}



===== AfUnixTraceLogging @ 14000d22c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AfUnixTraceLogging(byte param_1,char *param_2,undefined4 param_3,char *param_4,char param_5)

{
  bool bVar1;
  int iVar2;
  char *_DstBuf;
  undefined8 uVar3;
  longlong lVar4;
  byte *pbVar5;
  longlong lVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 auStackY_138 [32];
  undefined8 local_108 [2];
  undefined8 local_f8 [4];
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  undefined8 *local_c8;
  undefined8 local_c0;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  char local_a8 [80];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_138;
  local_108[0] = 0;
  _DstBuf = (char *)0x0;
  if ((AfUnixTraceloggingLevel < param_1) || (DAT_140006048 <= param_1)) {
    if (param_1 == 0) {
      return;
    }
    if (AfUnixKdBreakPointErrorLevel < param_1) {
      return;
    }
  }
  lVar6 = -1;
  pcVar8 = local_a8;
  iVar2 = _vsnprintf_s(local_a8,0x4b,0xffffffffffffffff,param_4,&param_5);
  if ((iVar2 == -1) && (_DstBuf = (char *)ExAllocatePool2(0x100,0x200), _DstBuf != (char *)0x0)) {
    local_108[0] = 0;
    _vsnprintf_s(_DstBuf,0x200,0xffffffffffffffff,param_4,&param_5);
    pcVar8 = _DstBuf;
  }
  if ((AfUnixTraceloggingLevel < param_1) || (uVar7 = (uint)param_1, DAT_140006048 <= uVar7))
  goto LAB_14000d5c9;
  if (uVar7 == 1) {
    if (DAT_140006048 < 2) goto LAB_14000d5c9;
    if (((_DAT_140006058 & 0x400000000000) == 0) ||
       (bVar1 = true, (DAT_140006060 & 0x400000000000) != DAT_140006060)) {
      bVar1 = false;
    }
    if (!bVar1) goto LAB_14000d5c9;
    local_b8 = "";
    if (param_2 == (char *)0x0) {
      param_2 = "";
      local_d0 = 1;
    }
    else {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (param_2[lVar4] != '\0');
      local_d0 = (int)lVar4 + 1;
    }
    if (pcVar8 == (char *)0x0) {
      local_b0 = 1;
    }
    else {
      do {
        lVar6 = lVar6 + 1;
      } while (pcVar8[lVar6] != '\0');
      local_b0 = (int)lVar6 + 1;
      local_b8 = pcVar8;
    }
    pbVar5 = &DAT_140005140;
    local_d8 = param_2;
  }
  else if (uVar7 == 2) {
    if (DAT_140006048 < 3) goto LAB_14000d5c9;
    if (((_DAT_140006058 & 0x400000000000) == 0) ||
       (bVar1 = true, (DAT_140006060 & 0x400000000000) != DAT_140006060)) {
      bVar1 = false;
    }
    if (!bVar1) goto LAB_14000d5c9;
    local_b8 = "";
    if (param_2 == (char *)0x0) {
      param_2 = "";
      local_d0 = 1;
    }
    else {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (param_2[lVar4] != '\0');
      local_d0 = (int)lVar4 + 1;
    }
    if (pcVar8 == (char *)0x0) {
      local_b0 = 1;
    }
    else {
      do {
        lVar6 = lVar6 + 1;
      } while (pcVar8[lVar6] != '\0');
      local_b0 = (int)lVar6 + 1;
      local_b8 = pcVar8;
    }
    pbVar5 = &DAT_140005111;
    local_d8 = param_2;
  }
  else if (uVar7 == 3) {
    if (DAT_140006048 < 4) goto LAB_14000d5c9;
    local_b8 = "";
    if (param_2 == (char *)0x0) {
      param_2 = "";
      local_d0 = 1;
    }
    else {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (param_2[lVar4] != '\0');
      local_d0 = (int)lVar4 + 1;
    }
    if (pcVar8 == (char *)0x0) {
      local_b0 = 1;
    }
    else {
      do {
        lVar6 = lVar6 + 1;
      } while (pcVar8[lVar6] != '\0');
      local_b0 = (int)lVar6 + 1;
      local_b8 = pcVar8;
    }
    pbVar5 = &DAT_1400051a8;
    local_d8 = param_2;
  }
  else {
    if ((uVar7 != 4) || (DAT_140006048 < 5)) goto LAB_14000d5c9;
    local_b8 = "";
    if (param_2 == (char *)0x0) {
      param_2 = "";
      local_d0 = 1;
    }
    else {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (param_2[lVar4] != '\0');
      local_d0 = (int)lVar4 + 1;
    }
    if (pcVar8 == (char *)0x0) {
      local_b0 = 1;
    }
    else {
      do {
        lVar6 = lVar6 + 1;
      } while (pcVar8[lVar6] != '\0');
      local_b0 = (int)lVar6 + 1;
      local_b8 = pcVar8;
    }
    pbVar5 = &DAT_1400051d9;
    local_d8 = param_2;
  }
  local_108[0] = CONCAT44(local_108[0]._4_4_,param_3);
  local_c0 = 4;
  local_c8 = local_108;
  local_cc = 0;
  local_ac = 0;
  _tlgWriteTransfer_EtwWriteTransfer(0x140006048,pbVar5,0,0,5,local_f8);
LAB_14000d5c9:
  if ((param_1 != 0) && (param_1 <= AfUnixKdBreakPointErrorLevel)) {
    uVar3 = PsGetCurrentProcess();
    DbgPrintEx(0,0,"AF_UNIX: (%p, %p) %s\n",uVar3);
  }
  if (_DstBuf != (char *)0x0) {
    ExFreePoolWithTag(_DstBuf,0);
  }
  return;
}



===== AfUnixTraceLoggingEnableCallback @ 14000d650 =====

void AfUnixTraceLoggingEnableCallback(void)

{
  return;
}



===== AfUnixTraceLoggingInitialize @ 14000d65c =====

void AfUnixTraceLoggingInitialize(void)

{
  int iVar1;
  
  iVar1 = TlgRegisterAggregateProviderEx();
  if (iVar1 < 0) {
    AfUnixTraceLogging(2,"AfUnixTraceLoggingInitialize",0x168,
                       "[0x%08x] AF_UNIX trace log provider registration failed.\n",(char)iVar1);
  }
  return;
}



===== AfUnixTransportNotifyAttachClient @ 14000d6a0 =====

undefined8 AfUnixTransportNotifyAttachClient(undefined8 param_1,undefined8 param_2)

{
  undefined8 *in_stack_00000030;
  undefined8 *in_stack_00000038;
  
  *in_stack_00000030 = param_2;
  *in_stack_00000038 = &AfUnixTlProviderDispatch;
  return 0;
}



===== AfUnixTransportNotifyDetachClient @ 14000d6d0 =====

undefined8 AfUnixTransportNotifyDetachClient(void)

{
  return 0;
}



===== AfUnixTransportStart @ 14000d6dc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int AfUnixTransportStart(void)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)ExAllocatePool2(0x100,0x28,0x69706e57);
  if (plVar4 == (longlong *)0x0) {
    iVar3 = -0x3fffffe9;
  }
  else {
    plVar4[1] = 0;
    *plVar4 = 1;
    plVar4[3] = 0;
    plVar4[4] = 0;
    _DAT_140006030 = &NPI_MS_UNIX_MODULEID;
    _DAT_140006040 = &AfUnixTlProviderCharacteristics;
    iVar3 = NmrRegisterProvider(&DAT_140006000,plVar4,plVar4 + 2);
    if (iVar3 < 0) {
      AfUnixTraceLogging(2,"AfUnixTransportStart",0x175,"[0x%08x] NmrRegisterProvider\n",(char)iVar3
                        );
      LOCK();
      lVar1 = *plVar4;
      *plVar4 = *plVar4 + -1;
      UNLOCK();
      if (lVar1 < 2) {
        if (lVar1 == 1) {
          ExFreePoolWithTag(plVar4,0);
        }
        else {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(0xe);
        }
      }
    }
  }
  return iVar3;
}



===== CancelTimerCallbacksAndDeleteTimer @ 14000d7cc =====

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



===== CreateTlgAggregateSession @ 14000d85c =====

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



===== DestroyAggregateSession @ 14000d9b4 =====

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



===== FlushEventEntryList @ 14000da00 =====

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



===== LookUpTableFlushComplete @ 14000daa0 =====

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
      if (((5 < DAT_140006080) && ((_DAT_140006090 & 0x200000000000) != 0)) &&
         ((DAT_140006098 & 0x200000000000) == DAT_140006098)) {
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
                  (p_Var5,&DAT_14000520e,(_GUID *)(ulonglong)uVar4,(_GUID *)(ulonglong)uVar3,
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



===== LookUpTableFlushPartial @ 14000de88 =====

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



===== TlgAggregateInternalFlushWorkItemRoutineKernelMode @ 14000df30 =====

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



===== TlgAggregateInternalProviderCallback @ 14000dfc0 =====

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
     (cVar1 = ExTryAcquirePushLockExclusiveEx(&DAT_140006158,0), cVar1 != '\0')) {
    for (lVar2 = DAT_140006160; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x160)) {
      LookUpTableFlushComplete(lVar2);
    }
    ExReleasePushLockExclusiveEx(&DAT_140006158,0);
  }
  return;
}



===== TlgAggregateInternalRegisteredProviderEtwCallback @ 14000e030 =====

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



===== TlgRegisterAggregateProviderEx @ 14000e0ac =====

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
                      (0x140006048,AfUnixTraceLoggingEnableCallback,0);
  }
  else {
    *(undefined8 *)((longlong)pvVar2 + 0x150) = 0;
    local_38[0] = 0;
    *(code **)((longlong)pvVar2 + 0x148) = AfUnixTraceLoggingEnableCallback;
    *(undefined4 **)((longlong)pvVar2 + 0x158) = &DAT_140006048;
    *(undefined1 *)((longlong)pvVar2 + 0x175) = 0;
    local_28 = *(undefined8 *)(PTR_DAT_140006050 + -0x10);
    uStack_20 = *(undefined8 *)(PTR_DAT_140006050 + -8);
    local_30 = (ulonglong)pvVar2 >> 4;
    RunningHash(local_38,(longlong)&local_28,0x10);
    RunningHash(local_38,(longlong)&local_30,8);
    FinishHash((int *)local_38);
    *(uint *)((longlong)pvVar2 + 0x170) = local_38[0] % 600000 + 600000;
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                      (0x140006048,TlgAggregateInternalRegisteredProviderEtwCallback,pvVar2);
    if (iVar1 < 0) {
      DAT_140006070 = 0;
      DestroyAggregateSession((longlong)pvVar2);
    }
    else {
      ExAcquirePushLockExclusiveEx(&DAT_140006158,0);
      if (DAT_140006160 == 0) {
        TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                  (0x140006080,TlgAggregateInternalProviderCallback,0);
      }
      plVar4 = &DAT_140006160;
      lVar3 = DAT_140006160;
      while (lVar3 != 0) {
        if (*(undefined4 **)(lVar3 + 0x158) == &DAT_140006048) goto LAB_14000e213;
        plVar4 = (longlong *)(lVar3 + 0x160);
        lVar3 = *plVar4;
      }
      *plVar4 = (longlong)pvVar2;
LAB_14000e213:
      ExReleasePushLockExclusiveEx(&DAT_140006158,0);
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14000e264 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x14000e2c5;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14000e2e5;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000e2f9;
  return iVar6;
}



===== _tlgEnableCallback @ 14000e310 =====

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



===== entry @ 140011010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140011044 =====

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



===== DriverEntry @ 140011078 =====

void DriverEntry(void)

{
  wil_InitializeFeatureStaging();
  AfUnixTraceLoggingInitialize();
  AfUnixTransportStart();
  return;
}



===== wil_InitializeFeatureStaging @ 140011098 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_14001111f;
    }
LAB_140011159:
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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
LAB_14001111f:
  if (plVar3 == (longlong *)0x0) goto LAB_140011159;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      _g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_140011159;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_140005c47 < plVar3) goto LAB_140011159;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14001111f;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400111ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  plVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_a <= plVar4) {
      return;
    }
    if (*plVar4 != 0) break;
    plVar4 = plVar4 + 1;
  }
  do {
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)plVar4 + 0x1d) == '\0') && (*(char *)((longlong)plVar4 + 0x1e) == '\0')
       ) {
      iVar3 = RtlQueryFeatureConfiguration
                        ((int)plVar4[3],1 < (byte)(*(char *)((longlong)plVar4 + 0x1c) - 2U),
                         &local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*plVar4;
          plVar4 = plVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_140005c47 < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140011296;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140011296;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140011296:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140005c47 < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


