
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== memcpy_s @ 1c0001020 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_1c000103d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_1c000107f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_1c000103d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_1c000107f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== _guard_check_icall @ 1c00010c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 1c00010e0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000114a) */
/* WARNING: Removing unreachable block (ram,0x0001c00010f9) */
/* WARNING: Removing unreachable block (ram,0x0001c00010ea) */

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



===== WPP_RECORDER_SF_ @ 1c00011a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,5,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c000126c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids,0x13,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids,0x13,
                  &uStack0000000000000030,4,0);
  return;
}



===== WPP_RECORDER_SF_l @ 1c0001318 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_l(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids,0x14,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids,0x14,
                  &uStack0000000000000030,4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 1c00013c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 1c00014c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c00015f0 =====

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



===== wil_details_RecordCachedUsage @ 1c000164c =====

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



===== wil_details_RecordFeatureUsageReporting @ 1c00017a0 =====

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



===== Fdo @ 1c0001824 =====

/* private: __cdecl UcmUcsiAcpiClient::Fdo::Fdo(struct WDFDEVICE__ * __ptr64) __ptr64 */

Fdo * __thiscall UcmUcsiAcpiClient::Fdo::Fdo(Fdo *this,WDFDEVICE__ *param_1)

{
  undefined1 uVar1;
  undefined7 uVar2;
  
  uVar2 = (undefined7)((ulonglong)param_1 >> 8);
  *(WDFDEVICE__ **)this = param_1;
  *(undefined8 **)(this + 0x80) = &utl::_FuncEmpty<void,unsigned_long>::_vftable_;
  *(undefined8 *)(this + 8) = 0;
  this[0x10] = (Fdo)0x0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0xe,
                       &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar1 = 4;
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xf,
                        &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,(char)*(undefined8 *)this);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(uVar2,uVar1),2,0x10,
                         &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
      }
    }
  }
  return this;
}



===== ~Fdo @ 1c0001924 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: __cdecl UcmUcsiAcpiClient::Fdo::~Fdo(void) __ptr64 */

void __thiscall UcmUcsiAcpiClient::Fdo::~Fdo(Fdo *this)

{
  undefined1 in_DL;
  undefined1 uVar1;
  undefined7 in_register_00000011;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT71(in_register_00000011,in_DL),2,0x11,
                       &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar1 = 4;
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x12,
                        &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,(char)*(undefined8 *)this);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                         CONCAT71(in_register_00000011,uVar1),2,0x13,
                         &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
      }
    }
  }
  (*(code *)**(undefined8 **)(this + 0x80))();
  return;
}



===== EvtDeviceD0EntryThunk @ 1c0001a10 =====

/* private: static long __cdecl UcmUcsiAcpiClient::Fdo::EvtDeviceD0EntryThunk(struct WDFDEVICE__ *
   __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl
UcmUcsiAcpiClient::Fdo::EvtDeviceD0EntryThunk(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  Fdo *pFVar1;
  _WDF_POWER_DEVICE_STATE _Var2;
  undefined4 in_register_00000014;
  
  _Var2 = param_2;
  pFVar1 = GetContextFromObject(param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT44(in_register_00000014,_Var2),2,0x27,
                       &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      _Var2 = CONCAT31((int3)(_Var2 >> 8),4);
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x28,
                         &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,
                         (char)*(undefined8 *)pFVar1,(char)param_2);
    }
  }
  Ppm::TurnOnPpmNotification(*(Ppm **)(pFVar1 + 0xb0));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_register_00000014,_Var2)
                     ,2,0x29,&WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  return 0;
}



===== EvtDeviceD0ExitThunk @ 1c0001b00 =====

/* private: static long __cdecl UcmUcsiAcpiClient::Fdo::EvtDeviceD0ExitThunk(struct WDFDEVICE__ *
   __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl
UcmUcsiAcpiClient::Fdo::EvtDeviceD0ExitThunk(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  Fdo *pFVar1;
  _WDF_POWER_DEVICE_STATE _Var2;
  undefined4 in_register_00000014;
  
  _Var2 = param_2;
  pFVar1 = GetContextFromObject(param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT44(in_register_00000014,_Var2),2,0x2a,
                       &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      _Var2 = CONCAT31((int3)(_Var2 >> 8),4);
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x2b,
                         &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,
                         (char)*(undefined8 *)pFVar1,(char)param_2);
    }
  }
  Ppm::TurnOffPpmNotification(*(Ppm **)(pFVar1 + 0xb0));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_register_00000014,_Var2)
                     ,2,0x2c,&WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  return 0;
}



===== EvtObjectContextCleanup @ 1c0001bec =====

/* private: void __cdecl UcmUcsiAcpiClient::Fdo::EvtObjectContextCleanup(void) __ptr64 */

void __thiscall UcmUcsiAcpiClient::Fdo::EvtObjectContextCleanup(Fdo *this)

{
  undefined1 in_DL;
  undefined1 uVar1;
  undefined7 in_register_00000011;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT71(in_register_00000011,in_DL),2,0x14,
                       &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar1 = 4;
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x15,
                        &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,(char)*(undefined8 *)this);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                         CONCAT71(in_register_00000011,uVar1),2,0x16,
                         &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
      }
    }
  }
  return;
}



===== EvtObjectContextCleanupThunk @ 1c0001cc0 =====

/* private: static void __cdecl WdfCpp::ObjectContext<struct WDFDEVICE__ * __ptr64,class
   UcmUcsiAcpiClient::Fdo>::EvtObjectContextCleanupThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,UcmUcsiAcpiClient::Fdo>::EvtObjectContextCleanupThunk
          (void *param_1)

{
  Fdo *this;
  
  this = UcmUcsiAcpiClient::Fdo::GetContextFromObject(param_1);
  UcmUcsiAcpiClient::Fdo::EvtObjectContextCleanup(this);
  return;
}



===== EvtObjectContextDestroyThunk @ 1c0001ce0 =====

/* private: static void __cdecl WdfCpp::ObjectContext<struct WDFDEVICE__ * __ptr64,class
   UcmUcsiAcpiClient::Fdo>::EvtObjectContextDestroyThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,UcmUcsiAcpiClient::Fdo>::EvtObjectContextDestroyThunk
          (void *param_1)

{
  Fdo *this;
  
  this = UcmUcsiAcpiClient::Fdo::GetContextFromObject(param_1);
  if (this != (Fdo *)0x0) {
    UcmUcsiAcpiClient::Fdo::~Fdo(this);
  }
  return;
}



===== GetAcpiObject @ 1c0001d04 =====

/* public: class UcmUcsiAcpiClient::Acpi * __ptr64 __cdecl
   UcmUcsiAcpiClient::Fdo::GetAcpiObject(void) __ptr64 */

Acpi * __thiscall UcmUcsiAcpiClient::Fdo::GetAcpiObject(Fdo *this)

{
  return (Acpi *)(this + 8);
}



===== GetContextFromObject @ 1c0001d10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class UcmUcsiAcpiClient::Fdo * __ptr64 __cdecl
   UcmUcsiAcpiClient::Fdo::GetContextFromObject(struct WDFDEVICE__ * __ptr64) */

Fdo * __cdecl UcmUcsiAcpiClient::Fdo::GetContextFromObject(WDFDEVICE__ *param_1)

{
  Fdo *pFVar1;
  
  pFVar1 = (Fdo *)(**(code **)(WdfFunctions_01023 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_Fdo_TYPE_INFO_1c0007018);
  return pFVar1;
}



===== _CopyInto @ 1c0001d50 =====

/* public: virtual bool __cdecl utl::_FuncEmpty<void,unsigned long>::_CopyInto(void * __ptr64)const
   __ptr64 */

bool __thiscall
utl::_FuncEmpty<void,unsigned_long>::_CopyInto(_FuncEmpty<void,unsigned_long> *this,void *param_1)

{
  *(undefined8 **)param_1 = &_vftable_;
  return true;
}



===== _Destroy @ 1c0001d70 =====

/* public: virtual void __cdecl utl::_FuncEmpty<void,unsigned long>::_Destroy(void) __ptr64 */

void __thiscall utl::_FuncEmpty<void,unsigned_long>::_Destroy(_FuncEmpty<void,unsigned_long> *this)

{
  *(undefined8 **)this = &_vftable_;
  return;
}



===== _Invoke @ 1c0001d90 =====

/* public: virtual void __cdecl utl::_FuncEmpty<void,unsigned long>::_Invoke(unsigned long &&
   __ptr64) __ptr64 */

void __thiscall
utl::_FuncEmpty<void,unsigned_long>::_Invoke(_FuncEmpty<void,unsigned_long> *this,ulong *param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _IsValid @ 1c0001da0 =====

/* public: virtual bool __cdecl utl::_FuncEmpty<void,unsigned long>::_IsValid(void)const __ptr64 */

bool __thiscall utl::_FuncEmpty<void,unsigned_long>::_IsValid(_FuncEmpty<void,unsigned_long> *this)

{
  return false;
}



===== _MoveIntoAndDestroy @ 1c0001db0 =====

/* public: virtual void __cdecl utl::_FuncEmpty<void,unsigned long>::_MoveIntoAndDestroy(void *
   __ptr64) __ptr64 */

void __thiscall
utl::_FuncEmpty<void,unsigned_long>::_MoveIntoAndDestroy
          (_FuncEmpty<void,unsigned_long> *this,void *param_1)

{
  *(undefined8 **)param_1 = &_vftable_;
  *(undefined8 **)this = &_vftable_;
  return;
}



===== WPP_RECORDER_SF_qi @ 1c0001dc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qi(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,0x1d,&uStack0000000000000030,8,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_95a0449cb3803ad94b451a460355499b_Traceguids,0x1d,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1c0001e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,0x2e,&uStack0000000000000030,8,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_95a0449cb3803ad94b451a460355499b_Traceguids,0x2e,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,0);
  return;
}



===== Ppm @ 1c0001f68 =====

/* private: __cdecl UcmUcsiAcpiClient::Ppm::Ppm(struct UCMUCSIPPM__ * __ptr64) __ptr64 */

Ppm * __thiscall UcmUcsiAcpiClient::Ppm::Ppm(Ppm *this,UCMUCSIPPM__ *param_1)

{
  *(UCMUCSIPPM__ **)this = param_1;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  this[0x20] = (Ppm)0x0;
  return this;
}



===== EvtIoDeviceControlThunk @ 1c0001f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl UcmUcsiAcpiClient::Ppm::EvtIoDeviceControlThunk(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
UcmUcsiAcpiClient::Ppm::EvtIoDeviceControlThunk
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  int iVar1;
  Ppm *this;
  WDFREQUEST__ *pWVar2;
  undefined8 *local_18 [2];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x25,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x4e8))(WdfDriverGlobals,param_1);
  local_18[0] = (undefined8 *)0x0;
  pWVar2 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x868))(WdfDriverGlobals,param_2,8,local_18,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    param_2 = pWVar2;
  }
  else {
    this = (Ppm *)(**(code **)(WdfFunctions_01023 + 0x650))
                            (WdfDriverGlobals,*local_18[0],PTR__WDF_Ppm_TYPE_INFO_1c0007040);
    EvtIoDeviceControl(this,param_2,param_5);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x27,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return;
}



===== EvtObjectContextDestroyThunk @ 1c0002100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl WdfCpp::ObjectContext<struct UCMUCSIPPM__ * __ptr64,class
   UcmUcsiAcpiClient::Ppm>::EvtObjectContextDestroyThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<UCMUCSIPPM__*___ptr64,UcmUcsiAcpiClient::Ppm>::EvtObjectContextDestroyThunk
          (void *param_1)

{
  (**(code **)(WdfFunctions_01023 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_Ppm_TYPE_INFO_1c0007040);
  return;
}



===== _CopyInto @ 1c0002140 =====

undefined8
utl::_FuncSmall<<lambda_60707b82e2567a5e0051585e164696ac>,void,unsigned_long>::_CopyInto
          (longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  *param_2 = &PTR__Destroy_1c0005028;
  uVar1 = *(undefined8 *)(param_1 + 8);
  param_2[1] = uVar1;
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== _Destroy @ 1c0002160 =====

void utl::_FuncSmall<<lambda_60707b82e2567a5e0051585e164696ac>,void,unsigned_long>::_Destroy
               (undefined8 *param_1)

{
  *param_1 = &PTR__Destroy_1c0005028;
  return;
}



===== _Invoke @ 1c0002180 =====

void utl::_FuncSmall<<lambda_60707b82e2567a5e0051585e164696ac>,void,unsigned_long>::_Invoke
               (longlong param_1,ulong *param_2)

{
  UcmUcsiAcpiClient::Ppm::PpmNotificationCallback(*(Ppm **)(param_1 + 8),*param_2);
  return;
}



===== _IsValid @ 1c00021a0 =====

undefined1
utl::_FuncSmall<<lambda_60707b82e2567a5e0051585e164696ac>,void,unsigned_long>::_IsValid(void)

{
  return 1;
}



===== _MoveIntoAndDestroy @ 1c00021b0 =====

void utl::_FuncSmall<<lambda_60707b82e2567a5e0051585e164696ac>,void,unsigned_long>::
     _MoveIntoAndDestroy(undefined8 *param_1,undefined8 *param_2)

{
  *param_2 = &PTR__Destroy_1c0005028;
  param_2[1] = param_1[1];
  *param_1 = &PTR__Destroy_1c0005028;
  return;
}



===== WPP_RECORDER_SF_qDDPd @ 1c00021d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDPd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,0x37,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,8,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,0x37,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qLd @ 1c000230c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,0x26,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,0x26,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qsi @ 1c0002404 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsi(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,0x1b,&uStack0000000000000030,8,
               pcVar3,lVar2,&uStack0000000000000040,8,0);
  }
  lVar2 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000038[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,4,3,&WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,0x1b,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,&uStack0000000000000040,8,0);
  return;
}



===== operator==<void,unsigned_long> @ 1c0002574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* bool __cdecl utl::operator==<void,unsigned long>(class utl::function<void __cdecl(unsigned long)>
   const & __ptr64,std::nullptr_t) */

bool __cdecl utl::operator==<void,unsigned_long>(longlong *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x20))();
  return cVar1 == '\0';
}



===== RtlStringCchPrintfA @ 1c0002598 =====

undefined8 RtlStringCchPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar2;
}



===== WPP_RECORDER_SF_qD @ 1c000260c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,4,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,
                  &param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDD @ 1c00026ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,0xf,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,0xf,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDd @ 1c0002800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined4 local_18 [2];
  undefined4 local_10 [2];
  
  local_18[0] = 0xc000009a;
  local_10[0] = 0x210;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,0x11,&uStack0000000000000030,8,
               &uStack0000000000000038,4,local_10,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,0x11,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,local_10,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qP @ 1c0002924 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qPd @ 1c00029f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qPd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_ql @ 1c0002aec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ql(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,
                  &param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qs @ 1c0002c14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qs(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,0x26,&uStack0000000000000030,8,
               pcVar3,lVar2,0);
  }
  lVar2 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000038[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,2,4,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,0x26,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,0);
  return;
}



===== WPP_RECORDER_SF_qsPP @ 1c0002d5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsPP(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000048;
  undefined8 local_28 [2];
  
  local_28[0] = 0x10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,0x28,&uStack0000000000000030,8,
               pcVar3,lVar2,local_28,8,&uStack0000000000000048,8,0);
  }
  lVar2 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000038[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,2,4,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,0x28,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,local_28,8,
                  &uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_qsd @ 1c0002ef8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,char *param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = param_7;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_7[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,&param_6,8,pcVar3,lVar2,
               &param_8,4,0);
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
  WppAutoLogTrace(param_1,2,4,&WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,param_4,&param_6,8,
                  pcVar4,lVar1,&param_8,4,0);
  return;
}



===== operator_new[] @ 1c0003070 =====

/* void * __ptr64 __cdecl operator new[](unsigned __int64) */

void * __cdecl operator_new__(__uint64 param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,0x14,0x63416355);
  return pvVar1;
}



===== operator_delete[] @ 1c000309c =====

/* void __cdecl operator delete[](void * __ptr64) */

void __cdecl operator_delete__(void *param_1)

{
  ExFreePoolWithTag(param_1,0x63416355);
  return;
}



===== FxStubDriverUnloadCommon @ 1c00030c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = &_UcmUcsiCx_BIND_INFO;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c00071a8 != &__KMDF_CLASS_BIND_START) {
    puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_1c00071a8 + 0x50);
    while( true ) {
      for (; (puVar1 + 2 <= puVar2 && (*(longlong *)puVar1 == 0)); puVar1 = puVar1 + 2) {
      }
      if (puVar1 < puVar2) break;
      puVar1 = puVar2;
LAB_1c0003119:
      if (puVar1 == (uint *)0x0) goto LAB_1c000316f;
      if (puVar2 <= puVar1) goto LAB_1c0003187;
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      puVar1 = (uint *)((longlong)puVar1 + (ulonglong)*puVar1);
    }
    if ((puVar1 + 0x14 <= puVar2) && (*puVar1 == 0x50)) goto LAB_1c0003119;
LAB_1c000316f:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0003187:
  WdfVersionUnbind(&DAT_1c00072b0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c00031c0 =====

void entry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c00031f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FxDriverEntryWorker(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  int iVar2;
  _DRIVER_OBJECT *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_DRIVER_OBJECT *)0x0) {
    lVar1 = UcmUcsiAcpiClient::Driver::CreateAndInitialize((_DRIVER_OBJECT *)0x0,param_2);
  }
  else {
    _DAT_1c00072b0 = 0x2080000;
    _DAT_1c00072b8 = &DAT_1c0007300;
    RtlCopyUnicodeString(&DAT_1c00072b0);
    p_Var3 = param_1;
    lVar1 = WdfVersionBind(param_1,&DAT_1c00072b0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < lVar1) {
      lVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var3);
      if ((-1 < lVar1) && (lVar1 = FxStubInitTypes(), -1 < lVar1)) {
        lVar1 = UcmUcsiAcpiClient::Driver::CreateAndInitialize(param_1,param_2);
        if (-1 < lVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c0007508 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",lVar1,&DAT_1c00072b0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c00071a8 != &__KMDF_CLASS_BIND_START) {
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
  return lVar1;
}



===== FxStubDriverUnload @ 1c0003380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c0007508 != (code *)0x0) && (DAT_1c0007508 != FxStubDriverUnload)) {
    (*DAT_1c0007508)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c00033b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00033d9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  puVar2 = &_UcmUcsiCx_BIND_INFO;
  while( true ) {
    for (; (puVar2 + 2 < (uint *)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*(longlong *)puVar2 == 0)); puVar2 = puVar2 + 2) {
    }
    if ((uint *)0x1c000719f < puVar2) break;
    if (((&__KMDF_CLASS_BIND_END < puVar2 + 0x14) || (*puVar2 != 0x50)) || (puVar2 == (uint *)0x0))
    {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c00071a8 = (undefined *)puVar2;
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



===== FxStubInitTypes @ 1c000353c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0003559) */
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
    if ((void **)0x1c00071bf < ppvVar2) break;
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



===== __GSHandlerCheck @ 1c0003608 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000362c =====

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



===== __security_check_cookie @ 1c00036a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00036e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003710 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003740 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00037c0 =====

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



===== memset @ 1c0003ac0 =====

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



===== __memset_repmovs @ 1c0003c00 =====

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



===== __memset_query @ 1c0003c80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0003d00 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003e40 =====

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



===== __memset_spec_plain @ 1c0003ec0 =====

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



===== CheckTestSigning @ 1c000a008 =====

/* private: static bool __cdecl UcmUcsiAcpiClient::Driver::CheckTestSigning(void) */

bool __cdecl UcmUcsiAcpiClient::Driver::CheckTestSigning(void)

{
  int iVar1;
  bool bVar2;
  undefined8 local_res8;
  
  bVar2 = false;
  local_res8 = 8;
  iVar1 = ZwQuerySystemInformation(0x67,&local_res8,8,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return false;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  else {
    bVar2 = (bool)(local_res8._4_1_ >> 1 & 1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return bVar2;
}



===== EvtDriverDeviceAddThunk @ 1c000a0a0 =====

/* private: static long __cdecl UcmUcsiAcpiClient::Driver::EvtDriverDeviceAddThunk(struct
   WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl
UcmUcsiAcpiClient::Driver::EvtDriverDeviceAddThunk(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  long lVar1;
  WDFDEVICE_INIT *pWVar2;
  
  pWVar2 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x11,
                     &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids);
  }
  lVar1 = Fdo::CreateAndInitialize(param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,1,0x12,
                     &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids);
  }
  return lVar1;
}



===== EvtDriverUnloadThunk @ 1c000a150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl UcmUcsiAcpiClient::Driver::EvtDriverUnloadThunk(struct WDFDRIVER__ *
   __ptr64) */

void __cdecl UcmUcsiAcpiClient::Driver::EvtDriverUnloadThunk(WDFDRIVER__ *param_1)

{
  undefined8 uVar1;
  undefined8 in_RDX;
  WDFDRIVER__ *pWVar2;
  undefined8 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,1,0xe,
                     &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids);
  }
  pWVar2 = param_1;
  uVar1 = (**(code **)(WdfFunctions_01023 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar3 = CONCAT71((int7)((ulonglong)pWVar2 >> 8),4);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xf,
                      &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids,(char)param_1);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,1,0x10,
                       &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids);
    }
  }
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  WppCleanupKm(uVar1);
  return;
}



===== WppCleanupKm @ 1c000a294 =====

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



===== WppInitKm @ 1c000a344 =====

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



===== WppLoadTracingSupport @ 1c000a420 =====

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



===== WppTraceCallback @ 1c000a570 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1c000a7f8 =====

/* WARNING: Removing unreachable block (ram,0x0001c000a820) */
/* WARNING: Removing unreachable block (ram,0x0001c000a830) */
/* WARNING: Removing unreachable block (ram,0x0001c000a835) */
/* WARNING: Removing unreachable block (ram,0x0001c000a83a) */
/* WARNING: Removing unreachable block (ram,0x0001c000a845) */
/* WARNING: Removing unreachable block (ram,0x0001c000a85a) */
/* WARNING: Removing unreachable block (ram,0x0001c000a850) */
/* WARNING: Removing unreachable block (ram,0x0001c000a86a) */
/* WARNING: Removing unreachable block (ram,0x0001c000a887) */
/* WARNING: Removing unreachable block (ram,0x0001c000a896) */
/* WARNING: Removing unreachable block (ram,0x0001c000a89b) */
/* WARNING: Removing unreachable block (ram,0x0001c000a88d) */
/* WARNING: Removing unreachable block (ram,0x0001c000a89d) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8a2) */
/* WARNING: Removing unreachable block (ram,0x0001c000a892) */
/* WARNING: Removing unreachable block (ram,0x0001c000a825) */
/* WARNING: Removing unreachable block (ram,0x0001c000a82e) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8ad) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8b2) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8a4) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8d5) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8b4) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8ce) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8d3) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8c5) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8ca) */
/* WARNING: Removing unreachable block (ram,0x0001c000a8a9) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c000a8e8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1c000a984;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1c000a984;
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
LAB_1c000a984:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c000a9f0 =====

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
      for (plVar2 = &wil_details_featureDescriptors_z; plVar2 < &wil_details_featureDescriptors_z;
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
              if (&UNK_1c0006137 < plVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 1c000aa70 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c000aa90 =====

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
  for (plVar3 = &wil_details_featureDescriptors_z; plVar3 < &wil_details_featureDescriptors_z;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_1c000ab8d;
  }
LAB_1c000ab96:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1c000ab8d:
  if (plVar3 == (longlong *)0x0) goto LAB_1c000ab96;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1c000ab5e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1c000ab5e;
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
    if (&UNK_1c0006137 < plVar3) goto LAB_1c000ab96;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1c000ab8d;
}



===== CreateAndInitialize @ 1c000abbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiAcpiClient::Fdo::CreateAndInitialize(struct WDFDEVICE_INIT *
   __ptr64) */

long __cdecl UcmUcsiAcpiClient::Fdo::CreateAndInitialize(WDFDEVICE_INIT *param_1)

{
  int iVar1;
  Fdo *pFVar2;
  undefined8 in_RDX;
  WDFDEVICE_INIT *pWVar3;
  WDFDEVICE__ *pWVar4;
  undefined2 uVar5;
  WDFDEVICE_INIT *local_res8;
  WDFDEVICE__ *local_res10;
  undefined8 local_e8;
  code *pcStack_e0;
  code *local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  undefined4 local_a8 [2];
  code *local_a0;
  code *local_90;
  code *local_80;
  code *local_78;
  
  local_res8 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,2,10,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  pWVar3 = local_res8;
  local_res10 = (WDFDEVICE__ *)0x0;
  local_b8 = (undefined *)0x0;
  local_e8 = 0;
  pcStack_e0 = (code *)0x0;
  local_d8 = (code *)0x0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  memset(local_a8,0,0x90);
  local_80 = EvtDevicePrepareHardwareThunk;
  local_a8[0] = 0x90;
  local_78 = EvtDeviceReleaseHardwareThunk;
  local_a0 = EvtDeviceD0EntryThunk;
  local_90 = EvtDeviceD0ExitThunk;
  (**(code **)(WdfFunctions_01023 + 0x1b8))(WdfDriverGlobals,pWVar3,local_a8);
  pWVar3 = local_res8;
  iVar1 = (*UcmucsiFunctions)(UcmucsiDriverGlobals,local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar5 = 0xb;
  }
  else {
    local_e8 = 0x38;
    uStack_d0 = 0x100000001;
    pWVar3 = (WDFDEVICE_INIT *)&local_res8;
    local_b8 = PTR__WDF_Fdo_TYPE_INFO_1c0007018;
    pcStack_e0 = WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,UcmUcsiAcpiClient::Fdo>::
                 EvtObjectContextCleanupThunk;
    local_d8 = WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,UcmUcsiAcpiClient::Fdo>::
               EvtObjectContextDestroyThunk;
    local_c8 = 0;
    uStack_c0 = 0;
    iVar1 = (**(code **)(WdfFunctions_01023 + 600))(WdfDriverGlobals,pWVar3,&local_e8,&local_res10);
    if (-1 < iVar1) {
      pWVar4 = local_res10;
      pFVar2 = (Fdo *)(**(code **)(WdfFunctions_01023 + 0x650))
                                (WdfDriverGlobals,local_res10,PTR__WDF_Fdo_TYPE_INFO_1c0007018);
      if (pFVar2 == (Fdo *)0x0) {
        pFVar2 = (Fdo *)0x0;
      }
      else {
        pWVar4 = local_res10;
        pFVar2 = (Fdo *)Fdo(pFVar2,local_res10);
      }
      iVar1 = Initialize(pFVar2);
      goto LAB_1c000adda;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar5 = 0xc;
  }
  pWVar4 = (WDFDEVICE__ *)CONCAT71((int7)((ulonglong)pWVar3 >> 8),2);
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar5,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,(char)local_res8,(char)iVar1);
LAB_1c000adda:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,2,0xd,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  return iVar1;
}



===== DestroyPpmObject @ 1c000ae2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiAcpiClient::Fdo::DestroyPpmObject(void) __ptr64 */

void __thiscall UcmUcsiAcpiClient::Fdo::DestroyPpmObject(Fdo *this)

{
  undefined8 in_RDX;
  undefined8 uVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,2,0x2d,
                       &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  uVar1 = **(undefined8 **)(this + 0xb0);
  (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
  *(undefined8 *)(this + 0xb0) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,2,0x2f,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  return;
}



===== EvtDevicePrepareHardware @ 1c000af28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl UcmUcsiAcpiClient::Fdo::EvtDevicePrepareHardware(struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Fdo::EvtDevicePrepareHardware
          (Fdo *this,WDFCMRESLIST__ *param_1,WDFCMRESLIST__ *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  char *pcVar4;
  longlong lVar5;
  WDFCMRESLIST__ *pWVar6;
  _CONFIG *p_Var7;
  Fdo *pFVar8;
  undefined8 uVar9;
  undefined7 uVar10;
  uint uVar11;
  undefined2 uVar12;
  undefined1 uVar13;
  undefined8 local_38;
  undefined8 uStack_30;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0x1c,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  uVar9 = *(undefined8 *)this;
  local_38 = 0;
  uStack_30 = 0;
  pWVar6 = param_2;
  uVar2 = (**(code **)(WdfFunctions_01023 + 0x980))(WdfDriverGlobals,param_2);
  uVar11 = 0;
  do {
    uVar13 = (undefined1)uVar9;
    if (uVar2 <= uVar11) {
      lVar3 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_1 = (WDFCMRESLIST__ *)CONCAT71((int7)((ulonglong)pWVar6 >> 8),2);
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x20,
                          &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,uVar13);
LAB_1c000b259:
        lVar3 = -0x3fffff66;
LAB_1c000b25b:
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0x23,
                           &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
        }
      }
      return lVar3;
    }
    pWVar6 = param_2;
    pcVar4 = (char *)(**(code **)(WdfFunctions_01023 + 0x988))(WdfDriverGlobals,param_2,uVar11);
    if (*pcVar4 == '\x03') {
      lVar5 = (**(code **)(WdfFunctions_01023 + 0x988))(WdfDriverGlobals,param_1,uVar11);
      if (*(int *)(lVar5 + 8) == 0) {
        uVar2 = *(uint *)(lVar5 + 4);
        param_1 = (WDFCMRESLIST__ *)(ulonglong)uVar2;
        if (uVar2 <= *(int *)(lVar5 + 0xc) + uVar2) {
          local_38 = *(undefined8 *)(pcVar4 + 4);
          p_Var7 = (_CONFIG *)&local_38;
          uStack_30 = CONCAT44(uStack_30._4_4_,*(undefined4 *)(pcVar4 + 0xc));
          lVar3 = Acpi::PrepareHardware((Acpi *)(this + 8),p_Var7);
          if (lVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return lVar3;
            }
            uVar12 = 0x1e;
            param_1 = (WDFCMRESLIST__ *)CONCAT71((int7)((ulonglong)p_Var7 >> 8),2);
            uVar2 = 3;
LAB_1c000b1c1:
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(byte)param_1,uVar2,uVar12,
                              &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,uVar13);
          }
          else {
            pFVar8 = this + 0xb0;
            lVar3 = Ppm::CreateAndInitialize(this,(Ppm **)pFVar8);
            if (lVar3 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return lVar3;
              }
              uVar12 = 0x1f;
              param_1 = (WDFCMRESLIST__ *)CONCAT71((int7)((ulonglong)pFVar8 >> 8),4);
              uVar2 = 2;
            }
            else {
              puVar1 = *(undefined8 **)(this + 0xb0);
              if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
                 (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pFVar8,3,0x11,
                                 &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
              }
              uVar9 = *puVar1;
              lVar3 = (*DAT_1c0007210)(UcmucsiDriverGlobals);
              if (lVar3 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),2);
                  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x12,
                                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,
                                     (char)*(undefined8 *)puVar1[1],(char)lVar3);
                  goto LAB_1c000b0f7;
                }
              }
              else {
LAB_1c000b0f7:
                if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
                   (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,3,0x13,
                                   &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
                }
              }
              uVar10 = (undefined7)((ulonglong)uVar9 >> 8);
              if (-1 < lVar3) {
                lVar3 = 0;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return 0;
                }
                uVar12 = 0x22;
                param_1 = (WDFCMRESLIST__ *)CONCAT71(uVar10,4);
                uVar2 = 2;
                goto LAB_1c000b1c1;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return lVar3;
              }
              uVar12 = 0x21;
              param_1 = (WDFCMRESLIST__ *)CONCAT71(uVar10,2);
              uVar2 = 3;
            }
            WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(byte)param_1,uVar2,uVar12
                               ,&WPP_95a0449cb3803ad94b451a460355499b_Traceguids,uVar13,(char)lVar3)
            ;
          }
          goto LAB_1c000b25b;
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff66;
      }
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      goto LAB_1c000b259;
    }
    uVar11 = uVar11 + 1;
  } while( true );
}



===== EvtDevicePrepareHardwareThunk @ 1c000b2b0 =====

/* private: static long __cdecl UcmUcsiAcpiClient::Fdo::EvtDevicePrepareHardwareThunk(struct
   WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
UcmUcsiAcpiClient::Fdo::EvtDevicePrepareHardwareThunk
          (WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  long lVar1;
  Fdo *this;
  
  this = GetContextFromObject(param_1);
  lVar1 = EvtDevicePrepareHardware(this,param_2,param_3);
  return lVar1;
}



===== EvtDeviceReleaseHardware @ 1c000b2e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl UcmUcsiAcpiClient::Fdo::EvtDeviceReleaseHardware(struct WDFCMRESLIST__ *
   __ptr64) __ptr64 */

long __thiscall UcmUcsiAcpiClient::Fdo::EvtDeviceReleaseHardware(Fdo *this,WDFCMRESLIST__ *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0x24,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  uVar1 = *(undefined8 *)this;
  if (*(Ppm **)(this + 0xb0) != (Ppm *)0x0) {
    Ppm::ReleaseHardware(*(Ppm **)(this + 0xb0));
    DestroyPpmObject(this);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x16,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  if (*(longlong *)(this + 0xa0) != 0) {
    param_1 = (WDFCMRESLIST__ *)(ulonglong)*(uint *)(this + 0xa8);
    MmUnmapIoSpace();
    *(undefined8 *)(this + 0xa0) = 0;
    *(undefined4 *)(this + 0xa8) = 0;
  }
  if (this[0x10] != (Fdo)0x0) {
    (**(code **)(this + 0x30))(*(undefined8 *)(this + 0x20));
    uVar2 = 0;
    memset(this + 0x18,0,0x58);
    this[0x10] = (Fdo)0x0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    param_1 = (WDFCMRESLIST__ *)CONCAT71((int7)((ulonglong)uVar2 >> 8),4);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x17,
                      &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,
                      (char)*(undefined8 *)(this + 8));
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x18,
                       &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = CONCAT71((int7)((ulonglong)param_1 >> 8),4);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x25,
                        &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,(char)uVar1);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,2,0x26,
                         &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
      }
    }
  }
  return 0;
}



===== EvtDeviceReleaseHardwareThunk @ 1c000b4d0 =====

/* private: static long __cdecl UcmUcsiAcpiClient::Fdo::EvtDeviceReleaseHardwareThunk(struct
   WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
UcmUcsiAcpiClient::Fdo::EvtDeviceReleaseHardwareThunk(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  long lVar1;
  Fdo *this;
  
  this = GetContextFromObject(param_1);
  lVar1 = EvtDeviceReleaseHardware(this,param_2);
  return lVar1;
}



===== Initialize @ 1c000b4f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl UcmUcsiAcpiClient::Fdo::Initialize(void) __ptr64 */

long __thiscall UcmUcsiAcpiClient::Fdo::Initialize(Fdo *this)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  undefined8 in_RDX;
  WDFDEVICE__ *pWVar3;
  undefined2 uVar4;
  undefined1 auStackY_98 [32];
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,2,0x17,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  pWVar1 = *(WDFDEVICE__ **)this;
  uStack_40 = 0;
  uStack_3c = 0;
  local_38 = 0;
  local_50 = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  local_58[0] = 4;
  pWVar3 = pWVar1;
  iVar2 = (*DAT_1c00071e8)(UcmucsiDriverGlobals,pWVar1,local_58);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0x18;
  }
  else {
    local_50 = 0x20000001c;
    uStack_48 = 2;
    uStack_44 = 2;
    uStack_40 = 0;
    uStack_3c = 2;
    local_38 = 2;
    (**(code **)(WdfFunctions_01023 + 0xe8))(WdfDriverGlobals,pWVar1,&local_50);
    pWVar3 = *(WDFDEVICE__ **)this;
    iVar2 = Acpi::Initialize((Acpi *)(this + 8),pWVar3);
    if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pWVar3 = (WDFDEVICE__ *)CONCAT71((int7)((ulonglong)pWVar3 >> 8),4);
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1a,
                          &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,(char)pWVar1);
      }
      iVar2 = 0;
      goto LAB_1c000b66b;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0x19;
  }
  pWVar3 = (WDFDEVICE__ *)CONCAT71((int7)((ulonglong)pWVar3 >> 8),2);
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar4,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids,(char)pWVar1,(char)iVar2);
LAB_1c000b66b:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,2,0x1b,
                     &WPP_95a0449cb3803ad94b451a460355499b_Traceguids);
  }
  return iVar2;
}



===== RegisterNotificationCallback<<lambda_60707b82e2567a5e0051585e164696ac>_> @ 1c000b6cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UcmUcsiAcpiClient::Acpi::
    RegisterNotificationCallback<<lambda_60707b82e2567a5e0051585e164696ac>_>
              (undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 **ppuVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined1 auStackY_b8 [32];
  undefined8 *local_78 [4];
  undefined **local_58;
  undefined8 local_50;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_58 = (undefined **)&utl::_FuncEmpty<void,unsigned_long>::_vftable_;
  utl::_FuncEmpty<void,unsigned_long>::_Destroy((_FuncEmpty<void,unsigned_long> *)&local_58);
  local_58 = &PTR__Destroy_1c0005028;
  ppuVar2 = local_78;
  local_50 = *param_2;
  utl::_FuncSmall<<lambda_60707b82e2567a5e0051585e164696ac>,void,unsigned_long>::_MoveIntoAndDestroy
            (&local_58,ppuVar2);
  local_58 = (undefined **)&utl::_FuncEmpty<void,unsigned_long>::_vftable_;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),ppuVar2,4,0x60,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  pcVar3 = NotificationCallback;
  iVar1 = (*(code *)param_1[0xb])(param_1[3],NotificationCallback,param_1);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000b86c;
    uVar4 = CONCAT71((int7)((ulonglong)pcVar3 >> 8),2);
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x61,
                       &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*param_1,(char)iVar1);
  }
  else {
    (**(code **)(WdfFunctions_01023 + 0x9c8))(WdfDriverGlobals,param_1[0xe],0);
    ppuVar2 = (undefined8 **)(param_1 + 0xf);
    if (ppuVar2 != local_78) {
      (*(code *)**ppuVar2)(ppuVar2);
      (*(code *)local_78[0][1])(local_78,ppuVar2);
      local_78[0] = &utl::_FuncEmpty<void,unsigned_long>::_vftable_;
    }
    uVar4 = param_1[0xe];
    (**(code **)(WdfFunctions_01023 + 0x9d0))(WdfDriverGlobals);
    iVar1 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,4,0x62,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
LAB_1c000b86c:
  (*(code *)*local_78[0])(local_78);
  (*(code *)*local_58)(&local_58);
  return iVar1;
}



===== CreateAndInitialize @ 1c000b8c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiAcpiClient::Ppm::CreateAndInitialize(class
   UcmUcsiAcpiClient::Fdo * __ptr64,class UcmUcsiAcpiClient::Ppm * __ptr64 * __ptr64) */

long __cdecl UcmUcsiAcpiClient::Ppm::CreateAndInitialize(Fdo *param_1,Ppm **param_2)

{
  long lVar1;
  Acpi *pAVar2;
  Ppm *pPVar3;
  Fdo *pFVar4;
  Ppm **ppPVar5;
  UCMUCSI_CONNECTOR_COLLECTION__ **ppUVar6;
  undefined2 uVar7;
  UCMUCSIPPM__ *local_res8;
  UCMUCSI_CONNECTOR_COLLECTION__ *local_res18 [2];
  undefined8 uVar8;
  undefined8 local_98;
  UCMUCSI_CONNECTOR_COLLECTION__ *pUStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_6c;
  code *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined *local_48;
  
  ppPVar5 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,10,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  uVar8 = *(undefined8 *)param_1;
  local_98 = 0;
  pUStack_90 = (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0;
  local_res8 = (UCMUCSIPPM__ *)0x0;
  local_88 = 0;
  uStack_80 = 0;
  local_74 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_6c = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),ppPVar5,3,0xf,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  local_res18[0] = (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0;
  pFVar4 = param_1;
  pAVar2 = Fdo::GetAcpiObject(param_1);
  ppUVar6 = local_res18;
  lVar1 = QueryConnectorsAndInitCollection(pFVar4,ppUVar6);
  if (-1 < lVar1) {
    ppUVar6 = *(UCMUCSI_CONNECTOR_COLLECTION__ ***)(pAVar2 + 0x98);
    pUStack_90 = local_res18[0];
    local_88 = CONCAT62(local_88._2_6_,*(undefined2 *)ppUVar6);
    local_98._0_5_ = CONCAT14(pAVar2[0x68],0x20);
    if (pAVar2[0x69] != (Acpi)0x0) {
      local_88 = CONCAT44(1,(undefined4)local_88);
      if (1 < (byte)pAVar2[0x6b]) goto LAB_1c000b9cf;
    }
    local_88 = local_88 & 0xffffffff;
  }
LAB_1c000b9cf:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),ppUVar6,3,0x10,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar8 = *(undefined8 *)param_1;
    uVar7 = 0xb;
  }
  else {
    local_48 = PTR__WDF_Ppm_TYPE_INFO_1c0007040;
    local_68 = WdfCpp::ObjectContext<UCMUCSIPPM__*___ptr64,UcmUcsiAcpiClient::Ppm>::
               EvtObjectContextDestroyThunk;
    local_74 = 0;
    local_6c = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_78 = 0x38;
    local_60 = 1;
    local_5c = 1;
    lVar1 = (*DAT_1c0007200)(UcmucsiDriverGlobals,uVar8,&local_98,&local_78,&local_res8);
    if (-1 < lVar1) {
      pPVar3 = (Ppm *)(**(code **)(WdfFunctions_01023 + 0x650))
                                (WdfDriverGlobals,local_res8,PTR__WDF_Ppm_TYPE_INFO_1c0007040);
      if (pPVar3 == (Ppm *)0x0) {
        pPVar3 = (Ppm *)0x0;
      }
      else {
        pPVar3 = (Ppm *)Ppm(pPVar3,local_res8);
      }
      lVar1 = Initialize(pPVar3,param_1);
      if (lVar1 < 0) {
        return lVar1;
      }
      *param_2 = pPVar3;
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar7 = 0xc;
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar7,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,(char)uVar8,(char)lVar1);
  return lVar1;
}



===== EvtIoDeviceControl @ 1c000bb48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiAcpiClient::Ppm::EvtIoDeviceControl(struct WDFREQUEST__ *
   __ptr64,unsigned long) __ptr64 */

void __thiscall
UcmUcsiAcpiClient::Ppm::EvtIoDeviceControl(Ppm *this,WDFREQUEST__ *param_1,ulong param_2)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x28,
                       &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x29,
                         &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,
                         (char)**(undefined8 **)(this + 8),(char)param_2);
    }
  }
  if (param_2 == 0x5d4004) {
    EvtReceiveData(this,param_1);
  }
  else if (param_2 == 0x5d400c) {
    EvtReceiveDataEx(this,param_1);
  }
  else if (param_2 == 0x5d8000) {
    EvtSendData(this,param_1);
  }
  else if (param_2 == 0x5d8008) {
    EvtSendDataEx(this,param_1);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x2a,
                         &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,
                         (char)**(undefined8 **)(this + 8),(char)param_2);
    }
    (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,param_1,0xc00000bb);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x2b,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return;
}



===== EvtReceiveData @ 1c000bce4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiAcpiClient::Ppm::EvtReceiveData(struct WDFREQUEST__ * __ptr64)
   __ptr64 */

void __thiscall UcmUcsiAcpiClient::Ppm::EvtReceiveData(Ppm *this,WDFREQUEST__ *param_1)

{
  int iVar1;
  undefined2 uVar2;
  _UCSI_DATA_BLOCK *local_res18;
  undefined8 local_res20;
  undefined1 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x30,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  local_res20 = 0;
  local_res18 = (_UCSI_DATA_BLOCK *)0x0;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x868))(WdfDriverGlobals,param_1,8,&local_res20,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000be69;
    uVar2 = 0x31;
    uVar3 = (undefined1)**(undefined8 **)(this + 8);
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x870))(WdfDriverGlobals,param_1,0x30,&local_res18,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000be69;
      uVar2 = 0x32;
    }
    else {
      iVar1 = Acpi::ReceiveData(*(Acpi **)(this + 0x18),local_res18);
      if (-1 < iVar1) {
        (**(code **)(WdfFunctions_01023 + 0x898))(WdfDriverGlobals,param_1,0x30);
        goto LAB_1c000be69;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000be69;
      uVar2 = 0x33;
    }
    uVar3 = (undefined1)**(undefined8 **)(this + 8);
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar2,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,uVar3,(char)iVar1);
LAB_1c000be69:
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x34,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return;
}



===== EvtReceiveDataEx @ 1c000bed4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiAcpiClient::Ppm::EvtReceiveDataEx(struct WDFREQUEST__ * __ptr64)
   __ptr64 */

void __thiscall UcmUcsiAcpiClient::Ppm::EvtReceiveDataEx(Ppm *this,WDFREQUEST__ *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined2 uVar3;
  _UCSI_DATA_BLOCK_HEADER **pp_Var4;
  _UCSI_DATA_BLOCK_HEADER *local_res18;
  undefined8 local_res20;
  undefined1 uVar5;
  undefined8 local_38 [2];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x3a,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  local_res20 = 0;
  local_res18 = (_UCSI_DATA_BLOCK_HEADER *)0x0;
  local_38[0] = 0;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x868))(WdfDriverGlobals,param_1,8,&local_res20,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000c063;
    uVar3 = 0x3b;
    uVar5 = (undefined1)**(undefined8 **)(this + 8);
  }
  else {
    pp_Var4 = &local_res18;
    pvVar2 = (void *)0x10f;
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x870))
                      (WdfDriverGlobals,param_1,0x10f,pp_Var4,local_38);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000c063;
      uVar3 = 0x3c;
    }
    else {
      iVar1 = Acpi::ReceiveDataEx(*(Acpi **)(this + 0x18),local_res18,pvVar2,(ulong)pp_Var4);
      if (-1 < iVar1) {
        (**(code **)(WdfFunctions_01023 + 0x898))(WdfDriverGlobals,param_1,8);
        goto LAB_1c000c063;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000c063;
      uVar3 = 0x3d;
    }
    uVar5 = (undefined1)**(undefined8 **)(this + 8);
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar3,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,uVar5,(char)iVar1);
LAB_1c000c063:
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x3e,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return;
}



===== EvtSendData @ 1c000c0d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiAcpiClient::Ppm::EvtSendData(struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall UcmUcsiAcpiClient::Ppm::EvtSendData(Ppm *this,WDFREQUEST__ *param_1)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res18;
  undefined1 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x2c,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  local_res18 = 0;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x868))(WdfDriverGlobals,param_1,0x38,&local_res18,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000c1d6;
    uVar2 = 0x2d;
    uVar3 = (undefined1)**(undefined8 **)(this + 8);
  }
  else {
    iVar1 = Acpi::SendData(*(Acpi **)(this + 0x18),(_UCSI_DATA_BLOCK *)(local_res18 + 8));
    if ((-1 < iVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_1c000c1d6;
    uVar2 = 0x2e;
    uVar3 = (undefined1)**(undefined8 **)(this + 8);
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar2,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,uVar3,(char)iVar1);
LAB_1c000c1d6:
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x2f,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return;
}



===== EvtSendDataEx @ 1c000c244 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiAcpiClient::Ppm::EvtSendDataEx(struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall UcmUcsiAcpiClient::Ppm::EvtSendDataEx(Ppm *this,WDFREQUEST__ *param_1)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res18;
  ulonglong local_res20;
  undefined1 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x35,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  local_res18 = 0;
  local_res20 = 0;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x868))
                    (WdfDriverGlobals,param_1,0x18,&local_res18,&local_res20);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000c3be;
    uVar2 = 0x36;
    uVar3 = (undefined1)**(undefined8 **)(this + 8);
  }
  else {
    if (local_res20 < *(byte *)(local_res18 + 0x11) + 0x18) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDDPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      goto LAB_1c000c3be;
    }
    iVar1 = Acpi::SendDataEx(*(Acpi **)(this + 0x18),(_UCSI_DATA_BLOCK_HEADER *)(local_res18 + 8),
                             (void *)(local_res18 + 0x18));
    if ((-1 < iVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_1c000c3be;
    uVar2 = 0x38;
    uVar3 = (undefined1)**(undefined8 **)(this + 8);
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar2,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,uVar3,(char)iVar1);
LAB_1c000c3be:
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0x39,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return;
}



===== Initialize @ 1c000c428 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl UcmUcsiAcpiClient::Ppm::Initialize(class UcmUcsiAcpiClient::Fdo * __ptr64)
   __ptr64 */

long __thiscall UcmUcsiAcpiClient::Ppm::Initialize(Ppm *this,Fdo *param_1)

{
  undefined8 uVar1;
  int iVar2;
  Acpi *pAVar3;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  code *local_50;
  undefined4 local_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,3,0xd,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  uVar1 = *(undefined8 *)param_1;
  *(Fdo **)(this + 8) = param_1;
  pAVar3 = Fdo::GetAcpiObject(param_1);
  *(Acpi **)(this + 0x18) = pAVar3;
  local_a8 = 0;
  local_88 = 0;
  local_98 = *(undefined8 *)this;
  uStack_b0 = 0;
  local_b8 = 0x38;
  uStack_90 = 0;
  uStack_a0 = 0x100000002;
  memset(&local_78,0,0x60);
  local_28 = 0xffffffff;
  local_50 = EvtIoDeviceControlThunk;
  local_78 = 0x60;
  local_74 = 2;
  local_70 = 1;
  iVar2 = (**(code **)(WdfFunctions_01023 + 0x4c0))
                    (WdfDriverGlobals,uVar1,&local_78,&local_b8,this + 0x10);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0xe,
                         &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,
                         (char)**(undefined8 **)(this + 8),(char)iVar2);
    }
  }
  else {
    (*DAT_1c0007208)(UcmucsiDriverGlobals,*(undefined8 *)this,*(undefined8 *)(this + 0x10));
    iVar2 = 0;
  }
  return iVar2;
}



===== PpmNotificationCallback @ 1c000c5bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiAcpiClient::Ppm::PpmNotificationCallback(unsigned long) __ptr64 */

void __thiscall UcmUcsiAcpiClient::Ppm::PpmNotificationCallback(Ppm *this,ulong param_1)

{
  longlong lVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  if (param_1 == 0x80) {
    lVar1 = *(longlong *)(this + 0x18);
    if ((*(char *)(lVar1 + 0x69) == '\0') || (*(byte *)(lVar1 + 0x6b) < 2)) {
      uVar3 = *(undefined8 *)this;
      (*DAT_1c0007220)(UcmucsiDriverGlobals,uVar3,*(undefined8 *)(lVar1 + 0x98));
    }
    else {
      uVar3 = *(undefined8 *)this;
      (*DAT_1c0007228)(UcmucsiDriverGlobals,uVar3,*(longlong *)(lVar1 + 0x98),
                       *(longlong *)(lVar1 + 0x98) + 0x10);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    pcVar2 = (char *)(ulonglong)*(uint *)(WdfDriverGlobals + 8);
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (*(longlong *)(this + 8) == 0)) {
      pcVar2 = "onecore\\drivers\\wdm\\usb\\ucmucsi\\clients\\ucmucsiacpiclient\\src\\Ppm.h";
      RtlAssert("m_Device",
                "onecore\\drivers\\wdm\\usb\\ucmucsi\\clients\\ucmucsiacpiclient\\src\\Ppm.h",0x9d,0
               );
    }
    uVar3 = CONCAT71((int7)((ulonglong)pcVar2 >> 8),3);
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x23,
                       &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,
                       (char)**(undefined8 **)(this + 8),(char)param_1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,3,0x24,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return;
}



===== QueryConnectorsAndInitCollection @ 1c000c710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static long __cdecl UcmUcsiAcpiClient::Ppm::QueryConnectorsAndInitCollection(class
   UcmUcsiAcpiClient::Fdo * __ptr64,struct UCMUCSI_CONNECTOR_COLLECTION__ * __ptr64 * __ptr64) */

long __cdecl
UcmUcsiAcpiClient::Ppm::QueryConnectorsAndInitCollection
          (Fdo *param_1,UCMUCSI_CONNECTOR_COLLECTION__ **param_2)

{
  undefined8 uVar1;
  int iVar2;
  Acpi *this;
  UCMUCSI_CONNECTOR_COLLECTION__ *pUVar3;
  char cVar4;
  byte *pbVar5;
  uint uVar6;
  undefined1 auStackY_c8 [32];
  undefined1 uVar7;
  WDFMEMORY__ *local_80;
  Acpi *local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,3,0x16,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  uVar1 = *(undefined8 *)param_1;
  cVar4 = '\0';
  local_80 = (WDFMEMORY__ *)0x0;
  this = Fdo::GetAcpiObject(param_1);
  local_78 = this;
  iVar2 = (*DAT_1c00071f0)(UcmucsiDriverGlobals,uVar1,0,param_2);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x17,
                         &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,(char)this,(char)iVar2);
    }
  }
  else {
    iVar2 = Acpi::EnumChildren(this,&local_80);
    if (-1 < iVar2) {
      local_70 = (**(code **)(WdfFunctions_01023 + 0x610))(WdfDriverGlobals,local_80,0);
      uVar7 = (undefined1)uVar1;
      if (*(uint *)(local_70 + 4) == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x18,
                            &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,uVar7);
        }
        local_58 = 0x10;
        uStack_50 = 0;
        iVar2 = (*DAT_1c00071f8)(UcmucsiDriverGlobals,*param_2,&local_58);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x19,
                               &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,
                               (char)*(undefined8 *)param_1,(char)iVar2);
          }
          goto LAB_1c000ca85;
        }
      }
      else {
        pbVar5 = (byte *)(local_70 + 8);
        uVar6 = 1;
        cVar4 = '\0';
        if (1 < *(uint *)(local_70 + 4)) {
          do {
            pbVar5 = pbVar5 + (ulonglong)*(uint *)(pbVar5 + 4) + 8;
            if ((*pbVar5 & 1) != 0) {
              iVar2 = Acpi::EvaluatePld(this,(char *)(pbVar5 + 8),(_ACPI_PLD_BUFFER *)&local_68);
              if (-1 < iVar2) {
                local_58 = 0x10;
                uStack_50 = (ulonglong)
                            (((uint)uStack_60 >> 0x10 & 0x7f80 | (uint)uStack_60 & 0x7f8000) >> 7);
                iVar2 = (*DAT_1c00071f8)(UcmucsiDriverGlobals,*param_2,&local_58);
                if (iVar2 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x1a,
                                       &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,
                                       (char)*(undefined8 *)param_1,(char)iVar2);
                  }
                  goto LAB_1c000ca85;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qsi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                }
                cVar4 = cVar4 + '\x01';
                this = local_78;
              }
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(local_70 + 4));
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x1c,
                           &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,uVar7,cVar4);
      }
    }
LAB_1c000ca85:
    pUVar3 = (UCMUCSI_CONNECTOR_COLLECTION__ *)local_80;
    if (local_80 != (WDFMEMORY__ *)0x0) {
      (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
    }
    if (-1 < iVar2) goto LAB_1c000cada;
  }
  pUVar3 = *param_2;
  if (pUVar3 != (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
    *param_2 = (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0;
  }
LAB_1c000cada:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pUVar3,3,0x1d,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return iVar2;
}



===== ReleaseHardware @ 1c000cb3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiAcpiClient::Ppm::ReleaseHardware(void) __ptr64 */

void __thiscall UcmUcsiAcpiClient::Ppm::ReleaseHardware(Ppm *this)

{
  undefined8 in_RDX;
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,3,0x14,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  uVar1 = *(undefined8 *)this;
  (*DAT_1c0007218)(UcmucsiDriverGlobals);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,3,0x15,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return;
}



===== TurnOffPpmNotification @ 1c000cbe8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiAcpiClient::Ppm::TurnOffPpmNotification(void) __ptr64 */

void __thiscall UcmUcsiAcpiClient::Ppm::TurnOffPpmNotification(Ppm *this)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  undefined8 in_RDX;
  undefined8 uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,3,0x21,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  puVar2 = *(undefined8 **)(this + 0x18);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,4,99,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x9c8))(WdfDriverGlobals,puVar2[0xe],0);
  puVar1 = puVar2 + 0xf;
  bVar3 = utl::operator==<void,unsigned_long>(puVar1);
  if (bVar3) {
    uVar4 = puVar2[0xe];
    (**(code **)(WdfFunctions_01023 + 0x9d0))(WdfDriverGlobals);
  }
  else {
    (**(code **)*puVar1)(puVar1);
    *puVar1 = &utl::_FuncEmpty<void,unsigned_long>::_vftable_;
    uVar4 = puVar2[0xe];
    (**(code **)(WdfFunctions_01023 + 0x9d0))(WdfDriverGlobals,uVar4);
    (*(code *)puVar2[0xc])(puVar2[3]);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),4);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,100,
                      &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*puVar2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,4,0x65,
                       &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,3,0x22,
                       &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
    }
  }
  return;
}



===== TurnOnPpmNotification @ 1c000cdc8 =====

/* public: long __cdecl UcmUcsiAcpiClient::Ppm::TurnOnPpmNotification(void) __ptr64 */

long __thiscall UcmUcsiAcpiClient::Ppm::TurnOnPpmNotification(Ppm *this)

{
  int iVar1;
  undefined8 in_RDX;
  char *pcVar2;
  Ppm **ppPVar3;
  Ppm *local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,3,0x1e,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  ppPVar3 = &local_res8;
  local_res8 = this;
  iVar1 = Acpi::RegisterNotificationCallback<<lambda_60707b82e2567a5e0051585e164696ac>_>
                    (*(undefined8 **)(this + 0x18),ppPVar3);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    pcVar2 = (char *)(ulonglong)*(uint *)(WdfDriverGlobals + 8);
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (*(longlong *)(this + 8) == 0)) {
      pcVar2 = "onecore\\drivers\\wdm\\usb\\ucmucsi\\clients\\ucmucsiacpiclient\\src\\Ppm.h";
      RtlAssert("m_Device",
                "onecore\\drivers\\wdm\\usb\\ucmucsi\\clients\\ucmucsiacpiclient\\src\\Ppm.h",0x9d,0
               );
    }
    ppPVar3 = (Ppm **)CONCAT71((int7)((ulonglong)pcVar2 >> 8),2);
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x1f,
                       &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids,
                       (char)**(undefined8 **)(this + 8),(char)iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),ppPVar3,3,0x20,
                     &WPP_dbd99c2504eb31d4d46d408917bcd495_Traceguids);
  }
  return iVar1;
}



===== EnumChildren @ 1c000cef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl UcmUcsiAcpiClient::Acpi::EnumChildren(struct WDFMEMORY__ * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall UcmUcsiAcpiClient::Acpi::EnumChildren(Acpi *this,WDFMEMORY__ **param_1)

{
  int iVar1;
  undefined8 *puVar2;
  WDFMEMORY__ *pWVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  WDFMEMORY__ *local_res8;
  undefined8 *local_res18;
  int *local_res20;
  undefined8 uVar7;
  ulonglong uVar8;
  WDFMEMORY__ *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  WDFMEMORY__ *pWStack_60;
  undefined8 local_58;
  undefined8 local_50;
  WDFMEMORY__ *pWStack_48;
  undefined8 local_40;
  
  local_res18 = (undefined8 *)0x0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  pWStack_48 = (WDFMEMORY__ *)0x0;
  local_res20 = (int *)0x0;
  local_68 = 0;
  pWStack_60 = (WDFMEMORY__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x19,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  local_a8 = (WDFMEMORY__ *)0x0;
  local_70 = 0;
  puVar2 = &local_a0;
  local_res8 = (WDFMEMORY__ *)0x0;
  local_90 = 0;
  uStack_88 = 0x100000001;
  uVar5 = 0x200;
  local_80 = *(undefined8 *)this;
  uStack_78 = 0;
  uStack_98 = 0;
  local_a0 = 0x38;
  uVar7 = 0x10;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x600))
                    (WdfDriverGlobals,puVar2,0x200,0,0x10,&local_a8,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,uVar5,0x1a,uVar7,
                         (char)*(undefined8 *)this,0x10);
    }
  }
  else {
    uVar4 = 0x14;
    *local_res18 = 0;
    local_res18[1] = 0;
    *(undefined4 *)local_res18 = 0x48696541;
    *(undefined4 *)((longlong)local_res18 + 4) = 1;
    pWStack_48 = local_a8;
    local_50 = 3;
    local_40 = 0;
    while( true ) {
      puVar2 = &local_a0;
      local_70 = 0;
      local_80 = *(undefined8 *)this;
      local_90 = 0;
      uVar5 = 0x200;
      uStack_78 = 0;
      uStack_98 = 0;
      local_a0 = 0x38;
      uStack_88 = 0x100000001;
      uVar8 = uVar4;
      iVar1 = (**(code **)(WdfFunctions_01023 + 0x600))
                        (WdfDriverGlobals,puVar2,0x200,0,uVar4,&local_res8,&local_res20);
      if (iVar1 < 0) break;
      pWStack_60 = local_res8;
      local_68 = 3;
      local_58 = 0;
      uVar5 = (**(code **)(WdfFunctions_01023 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
      iVar1 = (**(code **)(WdfFunctions_01023 + 0x5d0))
                        (WdfDriverGlobals,uVar5,0,0x32c020,&local_50,&local_68,0,0);
      if (-1 < iVar1) {
        if (*local_res20 == 0x47696541) {
          if (local_res20[1] != 0) {
            *param_1 = local_res8;
            goto LAB_1c000d2ad;
          }
          iVar1 = -0x3febfff1;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000d2ad;
          uVar6 = 0x1d;
        }
        else {
          iVar1 = -0x3febfff1;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000d2ad;
          uVar6 = 0x1c;
        }
LAB_1c000d22a:
        iVar1 = -0x3febfff1;
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar6,
                          &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*(undefined8 *)this
                         );
        goto LAB_1c000d2ad;
      }
      if (iVar1 != -0x7ffffffb) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x1e,
                             &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,
                             (char)*(undefined8 *)this,(char)iVar1);
        }
        goto LAB_1c000d2ad;
      }
      if (*local_res20 != 0x47696541) {
        iVar1 = -0x3febfff1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x1f;
          goto LAB_1c000d22a;
        }
        goto LAB_1c000d2ad;
      }
      uVar4 = (ulonglong)(uint)local_res20[1];
      (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals,local_res8);
      local_res8 = (WDFMEMORY__ *)0x0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,uVar5,0x1b,uVar8,
                         (char)*(undefined8 *)this,(char)uVar4);
    }
  }
LAB_1c000d2ad:
  pWVar3 = local_a8;
  if (local_a8 != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
  }
  if ((iVar1 < 0) && (pWVar3 = local_res8, local_res8 != (WDFMEMORY__ *)0x0)) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,4,0x20,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return iVar1;
}



===== EvaluatePld @ 1c000d34c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000d706) */
/* public: long __cdecl UcmUcsiAcpiClient::Acpi::EvaluatePld(char const * __ptr64,struct
   _ACPI_PLD_BUFFER * __ptr64) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Acpi::EvaluatePld(Acpi *this,char *param_1,_ACPI_PLD_BUFFER *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined1 auStackY_228 [32];
  undefined8 uVar8;
  undefined8 local_1c8;
  undefined4 *puStack_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined4 local_158;
  char local_154 [268];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_228;
  local_1b8 = 0;
  local_1a0 = 0;
  local_168 = 0;
  local_1c8 = 0;
  puStack_1c0 = (undefined4 *)0x0;
  local_1b0 = 0;
  uStack_1a8 = 0;
  local_198 = 0;
  uStack_190 = 0;
  local_188 = 0;
  uStack_180 = 0;
  local_178 = 0;
  uStack_170 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x21,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  memset(local_154,0,0x100);
  local_158 = 0x41696541;
  uVar3 = RtlStringCchPrintfA(local_154,0x100,"%s._PLD",param_1);
  uVar2 = (uint)uVar3;
  if ((int)uVar2 < 0) {
    uVar1 = uVar2;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x22,
                         &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*(undefined8 *)this,
                         (char)uVar3);
      goto LAB_1c000d6fc;
    }
  }
  else {
    local_178 = *(undefined8 *)this;
    puVar5 = &local_198;
    uVar3 = 0x200;
    local_198 = CONCAT44(local_198._4_4_,0x38);
    uStack_180 = 0x100000001;
    uVar8 = 0x40c;
    uVar1 = (**(code **)(WdfFunctions_01023 + 0x600))(WdfDriverGlobals,puVar5,0x200,0);
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,uVar3,0x23,uVar8,
                            (char)*(undefined8 *)this,0xc,(char)uVar1);
      }
    }
    else {
      memset((void *)0x0,0,0x40c);
      puStack_1c0 = &local_158;
      uStack_1a8 = 0;
      local_1c8 = 1;
      local_1b8 = 0x104;
      local_1b0 = 3;
      local_1a0 = 0;
      uVar8 = (**(code **)(WdfFunctions_01023 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
      uVar6 = 0;
      puVar5 = &local_1c8;
      uVar2 = (**(code **)(WdfFunctions_01023 + 0x5e0))(WdfDriverGlobals,uVar8,0,0x32c018);
      uVar3 = uRam0000000000000018;
      uVar1 = uVar2;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0x24;
          uVar4 = uVar2;
LAB_1c000d5d3:
          WPP_RECORDER_SF_qsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,uVar6,uVar7,puVar5,
                              (char)*(undefined8 *)this,local_154,(char)uVar4);
          uVar1 = uVar2;
        }
      }
      else if (iRam0000000000000000 == 0x426f6541) {
        if (iRam0000000000000008 == 0) {
          uVar1 = 0xc014000f;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
        else {
          uVar4 = (uint)uRam000000000000000c;
          if (uVar4 == 2) {
            if (uRam000000000000000e < 0x10) {
              uVar1 = 0xc014000f;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qsPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
              }
            }
            else {
              *(undefined8 *)param_2 = uRam0000000000000010;
              *(undefined8 *)(param_2 + 8) = uVar3;
            }
          }
          else {
            uVar2 = 0xc014000f;
            uVar1 = 0xc014000f;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar7 = 0x27;
              goto LAB_1c000d5d3;
            }
          }
        }
      }
      else {
        uVar2 = 0xc014000f;
        uVar1 = 0xc014000f;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x25,
                            &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,
                            (char)*(undefined8 *)this);
          goto LAB_1c000d6fc;
        }
      }
    }
  }
  uVar2 = uVar1;
LAB_1c000d6fc:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,4,0x29,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return uVar2;
}



===== EvaluateUcsiDsm @ 1c000d77c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000db10) */
/* private: long __cdecl UcmUcsiAcpiClient::Acpi::EvaluateUcsiDsm(unsigned long,struct
   _ACPI_EVAL_OUTPUT_BUFFER_V1 __unaligned * __ptr64 * __ptr64) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Acpi::EvaluateUcsiDsm
          (Acpi *this,ulong param_1,_ACPI_EVAL_OUTPUT_BUFFER_V1 **param_2)

{
  int iVar1;
  ulonglong uVar2;
  __uint64 _Var3;
  undefined8 *puVar4;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *p_Var5;
  undefined8 uVar6;
  undefined *puVar7;
  undefined1 auStackY_118 [32];
  undefined8 uVar8;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  local_50 = 0;
  uStack_48 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,4,0x35,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  local_58 = 0;
  puVar4 = &local_88;
  local_78 = 0;
  uVar6 = 0x200;
  uStack_70 = 0x100000001;
  p_Var5 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
  local_68 = *(undefined8 *)this;
  uStack_60 = 0;
  uStack_80 = 0;
  local_88 = 0x38;
  uVar8 = 0x3c;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x600))(WdfDriverGlobals,puVar4,0x200,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,uVar6,0x36,uVar8,
                          (char)*(undefined8 *)this,0x3c,(char)iVar1);
    }
  }
  else {
    puVar7 = &GUID_UCSI_DSM;
    uRam0000000000000018 = 0;
    uRam0000000000000020 = 0;
    uRam0000000000000028 = 0;
    uRam0000000000000030 = 0;
    uRam0000000000000038 = 0;
    uRam0000000000000008 = 0x40000002c;
    uRam0000000000000000 = 0x4d53445f43696541;
    uVar6 = 0x10;
    _Var3 = 0x14;
    _uRam0000000000000010 = 0x100002;
    memcpy_s((void *)0x14,0x10,&GUID_UCSI_DSM,0x10);
    uVar2 = (ulonglong)uRam0000000000000010._2_2_;
    if (uRam0000000000000010._2_2_ < 4) {
      uVar2 = 4;
    }
    *(undefined8 *)(uVar2 + 0x14) = 0x40000;
    *(undefined4 *)(uVar2 + 0x1c) = 0x40000;
    *(ulong *)(uVar2 + 0x20) = param_1;
    *(undefined4 *)(uVar2 + 0x24) = 4;
    p_Var5 = operator_new__(_Var3);
    if (p_Var5 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
      iVar1 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,puVar7,0x37,uVar8,
                           (char)*(undefined8 *)this,0x14);
      }
    }
    else {
      local_50 = 0x300000010;
      uStack_48 = 0xfffffffffe363c80;
      uVar6 = (**(code **)(WdfFunctions_01023 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
      iVar1 = (**(code **)(WdfFunctions_01023 + 0x5e0))(WdfDriverGlobals,uVar6,0,0x32c004);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x38,
                             &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,
                             (char)*(undefined8 *)this,(char)iVar1);
        }
      }
      else if (*(int *)p_Var5 != 0x426f6541) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x39,
                            &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,
                            (char)*(undefined8 *)this);
        }
        iVar1 = -0x3febfff1;
      }
    }
  }
  uVar6 = 0;
  if ((iVar1 < 0) || (param_2 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 **)0x0)) {
    if (p_Var5 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
      operator_delete__(p_Var5);
    }
  }
  else {
    *param_2 = p_Var5;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,4,0x3a,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return iVar1;
}



===== Initialize @ 1c000dba4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl UcmUcsiAcpiClient::Acpi::Initialize(struct WDFDEVICE__ * __ptr64) __ptr64 */

long __thiscall UcmUcsiAcpiClient::Acpi::Initialize(Acpi *this,WDFDEVICE__ *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  Acpi *pAVar3;
  Acpi local_res8 [8];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  WDFDEVICE__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res8[0] = (Acpi)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,10,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  *(WDFDEVICE__ **)this = param_1;
  local_38 = 0;
  puVar2 = &local_68;
  local_58 = 0;
  uStack_50 = 0x100000001;
  uStack_60 = 0;
  local_68 = 0x38;
  uStack_40 = 0;
  local_48 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x9c0))(WdfDriverGlobals,puVar2,this + 0x70);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    pAVar3 = (Acpi *)CONCAT71((int7)((ulonglong)puVar2 >> 8),2);
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xb,
                       &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)param_1,(char)iVar1);
  }
  else {
    pAVar3 = local_res8;
    iVar1 = QueryUcsiDsmForSupportedFunctions(this,(uchar *)pAVar3);
    if (-1 < iVar1) {
      pAVar3 = (Acpi *)CONCAT71((int7)((ulonglong)pAVar3 >> 8),local_res8[0]);
      iVar1 = QueryUcsiDsmForUsbDeviceControllerEnabled
                        (this,(uchar)local_res8[0],(bool *)(this + 0x68));
      if (-1 < iVar1) {
        pAVar3 = (Acpi *)CONCAT71((int7)((ulonglong)pAVar3 >> 8),local_res8[0]);
        iVar1 = QueryUcsiDsmForUsePpmReportedUcsiVersion
                          (this,(uchar)local_res8[0],(bool *)(this + 0x69));
        if (-1 < iVar1) {
          if (Driver::m_TestSigning != false) {
            pAVar3 = this + 0x69;
            QueryRegistryForUsePpmReportedUcsiVersion(this,(bool *)pAVar3);
          }
          iVar1 = 0;
        }
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pAVar3,4,0xc,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return iVar1;
}



===== NotificationCallback @ 1c000dd40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl UcmUcsiAcpiClient::Acpi::NotificationCallback(void * __ptr64,unsigned
   long) */

void __cdecl UcmUcsiAcpiClient::Acpi::NotificationCallback(void *param_1,ulong param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  undefined4 in_register_00000014;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_register_00000014,param_2),4,0x5e,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x9c8))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x70),0);
  plVar1 = (longlong *)((longlong)param_1 + 0x78);
  cVar4 = (**(code **)(*plVar1 + 0x20))(plVar1);
  puVar6 = auStackY_48;
  if (cVar4 != '\0') {
    cVar4 = (**(code **)(*plVar1 + 0x20))(plVar1);
    puVar6 = auStackY_48;
    if (cVar4 == '\0') {
      pcVar3 = (code *)swi(0x2c);
      (*pcVar3)();
      puVar6 = auStackY_40;
    }
    pcVar3 = *(code **)(*plVar1 + 0x18);
    *(undefined8 *)(puVar6 + -8) = 0x1c000ddfa;
    (*pcVar3)(plVar1,puVar6 + 0x50);
  }
  uVar5 = *(undefined8 *)((longlong)param_1 + 0x70);
  pcVar3 = *(code **)(WdfFunctions_01023 + 0x9d0);
  *(undefined8 *)(puVar6 + -8) = 0x1c000de18;
  (*pcVar3)(WdfDriverGlobals);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined **)(puVar6 + 0x20) = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
    *(undefined8 *)(puVar6 + -8) = 0x1c000de47;
    WPP_RECORDER_SF_(uVar2,uVar5,4,0x5f,*(undefined8 *)(puVar6 + 0x20));
  }
  return;
}



===== PrepareHardware @ 1c000de64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl UcmUcsiAcpiClient::Acpi::PrepareHardware(struct
   UcmUcsiAcpiClient::Acpi::_CONFIG * __ptr64) __ptr64 */

long __thiscall UcmUcsiAcpiClient::Acpi::PrepareHardware(Acpi *this,_CONFIG *param_1)

{
  Acpi AVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0xd,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  uVar5 = (ulonglong)*(uint *)(param_1 + 8);
  puVar4 = (ushort *)MmMapIoSpaceEx(*(undefined8 *)param_1,uVar5,0x204);
  if (puVar4 == (ushort *)0x0) {
    iVar3 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff66;
    }
    uVar7 = 0xe;
    uVar5 = CONCAT71((int7)(uVar5 >> 8),2);
    uVar6 = 3;
  }
  else {
    *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 8);
    *(ushort **)(this + 0x98) = puVar4;
    uVar2 = *puVar4;
    *(ushort *)(this + 0x6a) = uVar2;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = (ulonglong)(uVar2 >> 4 & 0xf);
      WPP_RECORDER_SF_qDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if (this[0x69] != (Acpi)0x0) {
      AVar1 = this[0x6b];
      if ((AVar1 != (Acpi)0x0) &&
         ((AVar1 != (Acpi)0x1 || (uVar5 = 0xf0, (*(ushort *)(this + 0x6a) & 0xf0) < 0x21)))) {
        if ((1 < (byte)AVar1) && (*(uint *)(this + 0xa0) < 0x210)) {
          iVar3 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return -0x3fffff66;
          }
          WPP_RECORDER_SF_qDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          goto LAB_1c000e0ce;
        }
        goto LAB_1c000e016;
      }
      iVar3 = -0x3ffffe7e;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffe7e;
      }
      uVar8 = (undefined1)*(undefined8 *)this;
      uVar7 = 0x10;
      uVar9 = 0x82;
LAB_1c000dff7:
      uVar5 = CONCAT71((int7)(uVar5 >> 8),2);
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar7,
                         &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,uVar8,uVar9);
      goto LAB_1c000e0ce;
    }
LAB_1c000e016:
    if (this[8] == (Acpi)0x0) {
      uVar5 = *(ulonglong *)this;
      iVar3 = (**(code **)(WdfFunctions_01023 + 0x418))
                        (WdfDriverGlobals,uVar5,&GUID_ACPI_INTERFACE_STANDARD2,this + 0x10,0x58,1,0)
      ;
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar3;
        }
        uVar8 = (undefined1)*(undefined8 *)this;
        uVar7 = 0x13;
        uVar9 = (undefined1)iVar3;
        goto LAB_1c000dff7;
      }
      this[8] = (Acpi)0x1;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar3;
      }
      uVar7 = 0x14;
      uVar5 = CONCAT71((int7)(uVar5 >> 8),4);
    }
    else {
      iVar3 = -0x3ffffe7c;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffe7c;
      }
      uVar7 = 0x12;
      uVar5 = CONCAT71((int7)(uVar5 >> 8),2);
    }
    uVar6 = 4;
  }
  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(byte)uVar5,uVar6,uVar7,
                    &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*(undefined8 *)this);
LAB_1c000e0ce:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,4,0x15,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return iVar3;
}



===== QueryRegistryForUsePpmReportedUcsiVersion @ 1c000e124 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl UcmUcsiAcpiClient::Acpi::QueryRegistryForUsePpmReportedUcsiVersion(bool &
   __ptr64) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Acpi::QueryRegistryForUsePpmReportedUcsiVersion(Acpi *this,bool *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  int local_res8 [2];
  longlong local_res18;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x51,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  local_res18 = 0;
  local_res8[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_38,L"UsePpmReportedUcsiVersion");
  uVar4 = 0;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x180))
                    (WdfDriverGlobals,*(undefined8 *)this,1,0x20019,0,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000e2c5;
    uVar5 = (undefined1)*(undefined8 *)this;
    uVar3 = 0x52;
  }
  else {
    lVar2 = local_res18;
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x780))
                      (WdfDriverGlobals,local_res18,&local_38,local_res8);
    if (-1 < iVar1) {
      iVar1 = 0;
      *param_1 = local_res8[0] != 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_ql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar2,4,0x54,uVar4,
                           (char)*(undefined8 *)this,local_res8[0] != 0);
      }
      goto LAB_1c000e2c5;
    }
    if ((iVar1 == -0x3fffffcc) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_1c000e2c5;
    uVar3 = 0x53;
    uVar5 = (undefined1)*(undefined8 *)this;
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,uVar3,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,uVar5,(char)iVar1);
LAB_1c000e2c5:
  lVar2 = local_res18;
  if (local_res18 != 0) {
    (**(code **)(WdfFunctions_01023 + 0x738))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar2,4,0x55,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return iVar1;
}



===== QueryUcsiDsmForSupportedFunctions @ 1c000e33c =====

/* private: long __cdecl UcmUcsiAcpiClient::Acpi::QueryUcsiDsmForSupportedFunctions(unsigned char &
   __ptr64) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Acpi::QueryUcsiDsmForSupportedFunctions(Acpi *this,uchar *param_1)

{
  _ACPI_EVAL_OUTPUT_BUFFER_V1 _Var1;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *p_Var2;
  uint uVar3;
  uint uVar4;
  undefined7 uVar6;
  undefined8 uVar5;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 **pp_Var7;
  undefined2 uVar8;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *local_res10;
  undefined *in_stack_ffffffffffffffb8;
  undefined1 uVar9;
  
  local_res10 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x3b,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  pp_Var7 = &local_res10;
  *param_1 = '\0';
  uVar5 = 0;
  uVar3 = EvaluateUcsiDsm(this,0,pp_Var7);
  p_Var2 = local_res10;
  uVar6 = (undefined7)((ulonglong)uVar5 >> 8);
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000e4a8;
    uVar9 = (undefined1)*(undefined8 *)this;
    uVar8 = 0x3c;
    uVar4 = uVar3;
  }
  else {
    if (*(int *)(local_res10 + 8) != 1) {
      uVar3 = 0xc014000f;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = CONCAT71(uVar6,2);
        WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x3d,
                           &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,
                           (char)*(undefined8 *)this,(char)*(int *)(local_res10 + 8));
      }
      goto LAB_1c000e4a8;
    }
    uVar4 = (uint)*(ushort *)(local_res10 + 0xc);
    if (uVar4 == 2) {
      _Var1 = local_res10[0x10];
      *param_1 = (uchar)_Var1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = CONCAT71(uVar6,4);
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pp_Var7,0x3f,
                           in_stack_ffffffffffffffb8,(char)*(undefined8 *)this,_Var1);
      }
      uVar3 = 0;
      goto LAB_1c000e4a8;
    }
    uVar3 = 0xc014000f;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000e4a8;
    uVar8 = 0x3e;
    uVar9 = (undefined1)*(undefined8 *)this;
  }
  uVar5 = CONCAT71(uVar6,2);
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar8,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,uVar9,(char)uVar4);
LAB_1c000e4a8:
  if (p_Var2 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    operator_delete__(p_Var2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,4,0x40,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return uVar3;
}



===== QueryUcsiDsmForUsbDeviceControllerEnabled @ 1c000e50c =====

/* private: long __cdecl UcmUcsiAcpiClient::Acpi::QueryUcsiDsmForUsbDeviceControllerEnabled(unsigned
   char,bool & __ptr64) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Acpi::QueryUcsiDsmForUsbDeviceControllerEnabled
          (Acpi *this,uchar param_1,bool *param_2)

{
  long lVar1;
  int iVar2;
  undefined7 in_register_00000011;
  undefined8 uVar3;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *p_Var4;
  undefined2 uVar5;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *local_res18;
  undefined *in_stack_ffffffffffffffb8;
  undefined1 uVar6;
  
  uVar3 = CONCAT71(in_register_00000011,param_1);
  local_res18 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x41,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  *param_2 = false;
  if ((param_1 & 0x10) == 0) {
LAB_1c000e69d:
    if ((param_1 & 8) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),4);
        in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x45,
                          &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*(undefined8 *)this
                         );
      }
      lVar1 = 0;
      *param_2 = true;
      goto LAB_1c000e778;
    }
    uVar3 = 3;
    lVar1 = EvaluateUcsiDsm(this,3,&local_res18);
    p_Var4 = local_res18;
    if (lVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 0x46;
        uVar6 = (undefined1)*(undefined8 *)this;
        goto LAB_1c000e5b6;
      }
    }
    else {
      iVar2 = *(int *)(local_res18 + 8);
      if (iVar2 == 1) {
        lVar1 = 0;
        *param_2 = *(int *)(local_res18 + 0x10) != 0;
      }
      else {
        lVar1 = -0x3febfff1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar5 = 0x47;
          goto LAB_1c000e60c;
        }
      }
    }
  }
  else {
    uVar3 = 4;
    lVar1 = EvaluateUcsiDsm(this,4,&local_res18);
    p_Var4 = local_res18;
    if (lVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = (undefined1)*(undefined8 *)this;
        uVar5 = 0x42;
LAB_1c000e5b6:
        uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),2);
        in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
        WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar5,
                           &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,uVar6,(char)lVar1);
        p_Var4 = local_res18;
      }
    }
    else {
      iVar2 = *(int *)(local_res18 + 8);
      if (iVar2 == 1) {
        if (*(int *)(local_res18 + 0x10) == 0) {
          operator_delete__(local_res18);
          local_res18 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
          goto LAB_1c000e69d;
        }
        lVar1 = 0;
        *param_2 = true;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),4);
          in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x44,
                            &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,
                            (char)*(undefined8 *)this);
        }
      }
      else {
        lVar1 = -0x3febfff1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar5 = 0x43;
LAB_1c000e60c:
          p_Var4 = local_res18;
          lVar1 = -0x3febfff1;
          uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),2);
          in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
          WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar5,
                             &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,
                             (char)*(undefined8 *)this,(char)iVar2);
        }
      }
    }
  }
  if (p_Var4 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    operator_delete__(p_Var4);
  }
LAB_1c000e778:
  if ((((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
      (WPP_RECORDER_SF_ql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,3,0x48,
                          in_stack_ffffffffffffffb8,(char)*(undefined8 *)this,*param_2),
      (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x49,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return lVar1;
}



===== QueryUcsiDsmForUsePpmReportedUcsiVersion @ 1c000e800 =====

/* private: long __cdecl UcmUcsiAcpiClient::Acpi::QueryUcsiDsmForUsePpmReportedUcsiVersion(unsigned
   char,bool & __ptr64) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Acpi::QueryUcsiDsmForUsePpmReportedUcsiVersion
          (Acpi *this,uchar param_1,bool *param_2)

{
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *p_Var1;
  long lVar2;
  undefined7 in_register_00000011;
  undefined8 uVar3;
  undefined7 uVar4;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 **pp_Var5;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *local_res18;
  undefined *in_stack_ffffffffffffffb8;
  
  uVar3 = CONCAT71(in_register_00000011,param_1);
  local_res18 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x4a,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  *param_2 = false;
  if ((param_1 & 0x20) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),4);
      in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x4b,
                        &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*(undefined8 *)this);
    }
    lVar2 = 0;
    goto LAB_1c000e99c;
  }
  pp_Var5 = &local_res18;
  uVar3 = 5;
  lVar2 = EvaluateUcsiDsm(this,5,pp_Var5);
  p_Var1 = local_res18;
  uVar4 = (undefined7)((ulonglong)uVar3 >> 8);
  if (lVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = CONCAT71(uVar4,2);
      in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x4c,
                         &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*(undefined8 *)this,
                         (char)lVar2);
    }
  }
  else {
    if (*(int *)(local_res18 + 8) == 1) {
      if (*(short *)(local_res18 + 0xc) == 2) {
        lVar2 = 0;
        *param_2 = *(int *)(local_res18 + 0x10) != 0;
        goto LAB_1c000e98f;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = CONCAT71(uVar4,2);
        WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var5,0x4e,
                           in_stack_ffffffffffffffb8,(char)*(undefined8 *)this,
                           (char)*(short *)(local_res18 + 0xc));
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = CONCAT71(uVar4,2);
      in_stack_ffffffffffffffb8 = &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids;
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x4d,
                         &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids,(char)*(undefined8 *)this,
                         (char)*(int *)(local_res18 + 8));
    }
    lVar2 = -0x3febfff1;
  }
LAB_1c000e98f:
  if (p_Var1 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    operator_delete__(p_Var1);
  }
LAB_1c000e99c:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_ql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x4f,
                       in_stack_ffffffffffffffb8,(char)*(undefined8 *)this,*param_2);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x50,
                       &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
    }
  }
  return lVar2;
}



===== ReceiveData @ 1c000ea24 =====

/* public: long __cdecl UcmUcsiAcpiClient::Acpi::ReceiveData(struct _UCSI_DATA_BLOCK * __ptr64)
   __ptr64 */

long __thiscall UcmUcsiAcpiClient::Acpi::ReceiveData(Acpi *this,_UCSI_DATA_BLOCK *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x58,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  uVar2 = 2;
  lVar1 = EvaluateUcsiDsm(this,2,(_ACPI_EVAL_OUTPUT_BUFFER_V1 **)0x0);
  if (-1 < lVar1) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*(longlong *)(this + 0x98) + 4);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,4,0x59,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return lVar1;
}



===== ReceiveDataEx @ 1c000eaf0 =====

/* public: long __cdecl UcmUcsiAcpiClient::Acpi::ReceiveDataEx(struct _UCSI_DATA_BLOCK_HEADER *
   __ptr64,void * __ptr64,unsigned long) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Acpi::ReceiveDataEx
          (Acpi *this,_UCSI_DATA_BLOCK_HEADER *param_1,void *param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x5c,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  uVar2 = 2;
  lVar1 = EvaluateUcsiDsm(this,2,(_ACPI_EVAL_OUTPUT_BUFFER_V1 **)0x0);
  if (-1 < lVar1) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*(longlong *)(this + 0x98) + 4);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,4,0x5d,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return lVar1;
}



===== SendData @ 1c000ebbc =====

/* public: long __cdecl UcmUcsiAcpiClient::Acpi::SendData(struct _UCSI_DATA_BLOCK * __ptr64 const)
   __ptr64 */

long __thiscall UcmUcsiAcpiClient::Acpi::SendData(Acpi *this,_UCSI_DATA_BLOCK *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x56,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  *(undefined8 *)(*(longlong *)(this + 0x98) + 8) = *(undefined8 *)(param_1 + 8);
  LOCK();
  UNLOCK();
  uVar2 = 1;
  lVar1 = EvaluateUcsiDsm(this,1,(_ACPI_EVAL_OUTPUT_BUFFER_V1 **)0x0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,4,0x57,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return lVar1;
}



===== SendDataEx @ 1c000ec8c =====

/* public: long __cdecl UcmUcsiAcpiClient::Acpi::SendDataEx(struct _UCSI_DATA_BLOCK_HEADER * __ptr64
   const,void * __ptr64 const) __ptr64 */

long __thiscall
UcmUcsiAcpiClient::Acpi::SendDataEx(Acpi *this,_UCSI_DATA_BLOCK_HEADER *param_1,void *param_2)

{
  long lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x5a,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  *(undefined8 *)(*(longlong *)(this + 0x98) + 8) = *(undefined8 *)(param_1 + 8);
  LOCK();
  UNLOCK();
  if (param_1[9] != (_UCSI_DATA_BLOCK_HEADER)0x0) {
    puVar4 = (undefined8 *)(*(longlong *)(this + 0x98) + 0x110);
    for (uVar2 = (ulonglong)(byte)param_1[9] + 7 >> 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *(undefined8 *)param_2;
      param_2 = (undefined8 *)((longlong)param_2 + 8);
      puVar4 = puVar4 + 1;
    }
    LOCK();
    UNLOCK();
  }
  uVar3 = 1;
  lVar1 = EvaluateUcsiDsm(this,1,(_ACPI_EVAL_OUTPUT_BUFFER_V1 **)0x0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x5b,
                     &WPP_786c52910ae43c8330a1a1f646072d04_Traceguids);
  }
  return lVar1;
}



===== __security_init_cookie @ 1c000f008 =====

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



===== CreateAndInitialize @ 1c000f03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: static long __cdecl UcmUcsiAcpiClient::Driver::CreateAndInitialize(struct _DRIVER_OBJECT
   * __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl
UcmUcsiAcpiClient::Driver::CreateAndInitialize(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  _DRIVER_OBJECT *p_Var3;
  undefined7 uVar5;
  undefined8 uVar4;
  undefined1 auStackY_a8 [32];
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  _WPP_MAIN_CB = 0;
  DAT_1c0007268 = &WPP_ThisDir_CTLGUID_UcmUcsiAcpiClient;
  DAT_1c0007270 = 0;
  _DAT_1c0007280 = 0;
  _DAT_1c0007288 = 1;
  local_40 = 0;
  uStack_38 = 0;
  _DAT_1c00072a0 = 0;
  _DAT_1c00072a8 = 0;
  WppLoadTracingSupport();
  _DAT_1c0007280 = 0;
  WppInitKm(param_1,param_2);
  puVar2 = &local_40;
  local_40 = CONCAT35(local_40._5_3_,0x100000010);
  uStack_38 = 0x200000001;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,1,10,
                     &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids);
  }
  wil_InitializeFeatureStaging();
  m_TestSigning = CheckTestSigning();
  p_Var3 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
  uVar5 = (undefined7)((ulonglong)p_Var3 >> 8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000f243;
    uVar4 = CONCAT71(uVar5,2);
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb,
                       &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids,(char)param_1,(char)iVar1);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = CONCAT71(uVar5,4);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc,
                      &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids,0);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,1,0xd,
                     &WPP_7efd311afde9347c1eeb7d333b3ae6ea_Traceguids);
  }
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_1c000f243:
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  WppCleanupKm(param_1);
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1c000f2c0 =====

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
    for (plVar3 = &wil_details_featureDescriptors_z; plVar3 < &wil_details_featureDescriptors_z;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_1c000f347;
    }
LAB_1c000f381:
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
LAB_1c000f347:
  if (plVar3 == (longlong *)0x0) goto LAB_1c000f381;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_1c000f381;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_1c0006137 < plVar3) goto LAB_1c000f381;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1c000f347;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c000f3d4 =====

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
  plVar4 = &wil_details_featureDescriptors_z;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= plVar4) {
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
            if (&UNK_1c0006137 < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1c000f4be;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1c000f4be;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1c000f4be:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1c0006137 < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


