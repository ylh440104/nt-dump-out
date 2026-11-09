
===== GetAcpiHardwareInstance @ 140001000 =====

/* long __cdecl GetAcpiHardwareInstance(struct WDFDEVICE__ * __ptr64,unsigned long * __ptr64) */

long __cdecl GetAcpiHardwareInstance(WDFDEVICE__ *param_1,ulong *param_2)

{
  long lVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids);
  }
  lVar1 = GetAcpiValue(param_1,0x4449555f,0xff,param_2);
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids,lVar1);
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids,*param_2);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids);
  }
  return lVar1;
}



===== GetAcpiValue @ 140001110 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetAcpiValue(struct WDFDEVICE__ * __ptr64,unsigned long,unsigned long,unsigned long
   * __ptr64) */

long __cdecl GetAcpiValue(WDFDEVICE__ *param_1,ulong param_2,ulong param_3,ulong *param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  __uint64 _Var4;
  ulonglong uVar5;
  long lVar6;
  undefined1 auStackY_2c8 [32];
  undefined4 local_288;
  ulong local_284;
  undefined8 local_280;
  int *local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined4 *local_260;
  undefined8 local_258;
  longlong local_250;
  int local_248 [2];
  int local_240;
  short local_23c;
  ulong local_238;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2c8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids);
  }
  *param_4 = param_3;
  local_260 = &local_288;
  local_288 = 0x42696541;
  _Var4 = 0;
  local_268 = 1;
  local_258 = 8;
  local_284 = param_2;
  memset(local_248,0,0x200);
  local_278 = local_248;
  local_280 = 1;
  local_270 = 0x200;
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x150);
  __empty_global_delete(pcVar1,_Var4);
  uVar3 = (*pcVar1)(WdfDriverGlobals);
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x5d0);
  __empty_global_delete(pcVar1,(__uint64)param_1);
  iVar2 = (*pcVar1)(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_250 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids,param_2,(char)iVar2);
    }
    lVar6 = 0;
    goto LAB_14000139d;
  }
  lVar6 = -0x3febfff1;
  if (local_248[0] == 0x426f6541) {
    if (local_240 == 1) {
      if (local_23c == 0) {
        lVar6 = 0;
        *param_4 = local_238;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                     &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids,param_2,(char)local_238,
                     (char)local_238);
        }
        goto LAB_14000139d;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_14000139d;
      uVar5 = 0x1e;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_14000139d;
      uVar5 = 0x1d;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000139d;
    uVar5 = 0x1c;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids,param_2);
LAB_14000139d:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
            &WPP_29cf47e22975324b73e8ea93d26d0c31_Traceguids);
  }
  return lVar6;
}



===== WPP_SF_ @ 1400013ec =====

void WPP_SF_(undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  code *pcVar1;
  
  pcVar1 = pfnWppTraceMessage;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,0);
  return;
}



===== WPP_SF_D @ 140001444 =====

void WPP_SF_D(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,0);
  return;
}



===== WPP_SF_dD @ 1400014b4 =====

void WPP_SF_dD(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 140001534 =====

void WPP_SF_DDD(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== CHTController @ 1400015cc =====

/* public: __cdecl CHTController::CHTController(unsigned long,void * __ptr64,unsigned long) __ptr64
    */

CHTController * __thiscall
CHTController::CHTController(CHTController *this,ulong param_1,void *param_2,ulong param_3)

{
  code *pcVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  ushort uVar8;
  
  *(ulong *)(this + 0x20) = param_1;
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0x18) = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  *(void **)(this + 0x9a8) = param_2;
  *(longlong *)(this + 0x9b0) = (longlong)param_2 + 0x380;
  *(longlong *)(this + 0x9b8) = (longlong)param_2 + 0x300;
  if (param_1 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
    *(undefined4 *)(this + 0xc) = 0x62;
    puVar4 = &DAT_140008330;
  }
  else if (param_1 == 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
    *(undefined4 *)(this + 0xc) = 0x49;
    puVar4 = &DAT_140008030;
  }
  else if (param_1 == 3) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
    *(undefined4 *)(this + 0xc) = 0x1b;
    puVar4 = &DAT_140008160;
  }
  else {
    if (param_1 != 4) {
      if (param_1 != 5) {
        return this;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
      }
      *(undefined4 *)(this + 0xc) = 8;
      *(undefined4 *)(this + 0x10) = 8;
      puVar4 = &DAT_1400084b8;
      goto LAB_1400017b8;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
    *(undefined4 *)(this + 0xc) = 0x56;
    puVar4 = &DAT_1400081d0;
  }
  *(undefined4 *)(this + 0x10) = 0x10;
LAB_1400017b8:
  *(undefined **)(this + 0x18) = puVar4;
  uVar6 = *(uint *)(this + 0x10);
  uVar3 = (uVar6 - 1) + *(int *)(this + 0xc);
  uVar7 = (ulonglong)uVar3 % (ulonglong)uVar6;
  *(uint *)(this + 0x14) = uVar3 / uVar6;
  uVar6 = 0;
  if (*(int *)(this + 0xc) != 0) {
    do {
      uVar3 = uVar6 + 1;
      uVar7 = (ulonglong)*(uint *)(*(longlong *)(this + 0x18) + (ulonglong)uVar6 * 4) +
              (longlong)param_2;
      *(ulonglong *)
       (this + (((ulonglong)uVar6 / (ulonglong)*(uint *)(this + 0x10)) * 0x10 +
               (ulonglong)uVar6 % (ulonglong)*(uint *)(this + 0x10)) * 8 + 0x28) = uVar7;
      uVar6 = uVar3;
    } while (uVar3 < *(uint *)(this + 0xc));
  }
  puVar2 = WdfDriverGlobals;
  puVar4 = PTR__WDF_GPIO_DRIVER_CTX_TYPE_INFO_140008020;
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
  uVar5 = *WdfDriverGlobals;
  __empty_global_delete(pcVar1,uVar7);
  uVar5 = (*pcVar1)(puVar2,uVar5,puVar4);
  uVar8 = 0;
  *(undefined8 *)(this + 0x9c0) = uVar5;
  if (*(int *)(this + 0x14) != 0) {
    do {
      IController::ClearBankStatus((IController *)this,uVar8);
      uVar7 = (ulonglong)uVar8;
      uVar8 = uVar8 + 1;
      this[uVar7 + 0x9c8] = (CHTController)0x0;
    } while ((uint)uVar8 < *(uint *)(this + 0x14));
  }
  uVar6 = 0;
  if (*(int *)(this + 0xc) != 0) {
    do {
      uVar7 = (ulonglong)uVar6;
      uVar6 = uVar6 + 1;
      *(undefined4 *)(this + uVar7 * 4 + 0x9d0) = 0;
    } while (uVar6 < *(uint *)(this + 0xc));
  }
  memset(this + 0xb58,0,0x310);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return this;
}



===== ~CHTController @ 1400018f0 =====

/* public: virtual __cdecl CHTController::~CHTController(void) __ptr64 */

void __thiscall CHTController::~CHTController(CHTController *this)

{
  *(undefined ***)this = &IController::_vftable_;
  return;
}



===== `scalar_deleting_destructor' @ 140001900 =====

/* public: virtual void * __ptr64 __cdecl CHTController::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CHTController::_scalar_deleting_destructor_(CHTController *this,uint param_1)

{
  *(undefined ***)this = &IController::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0xe70);
    }
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140001940 =====

/* public: virtual void * __ptr64 __cdecl IController::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall IController::_scalar_deleting_destructor_(IController *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x18);
    }
  }
  return this;
}



===== ClearBankStatus @ 140001980 =====

/* public: virtual void __cdecl IController::ClearBankStatus(unsigned short) __ptr64 */

void __thiscall IController::ClearBankStatus(IController *this,ushort param_1)

{
  code *pcVar1;
  char cVar2;
  undefined6 in_register_00000012;
  __uint64 _Var3;
  ushort uVar4;
  
  _Var3 = CONCAT62(in_register_00000012,param_1);
  uVar4 = 0;
  if (*(int *)(this + 0x10) != 0) {
    do {
      pcVar1 = *(code **)(*(longlong *)this + 0x10);
      __empty_global_delete(pcVar1,_Var3);
      _Var3 = (__uint64)param_1;
      cVar2 = (*pcVar1)(this,_Var3,uVar4);
      if (cVar2 != '\0') {
        pcVar1 = *(code **)(*(longlong *)this + 0x88);
        __empty_global_delete(pcVar1,_Var3);
        _Var3 = (__uint64)param_1;
        (*pcVar1)(this,_Var3,uVar4);
      }
      uVar4 = uVar4 + 1;
    } while ((uint)uVar4 < *(uint *)(this + 0x10));
  }
  return;
}



===== ClearPinStatus @ 140001a20 =====

/* public: virtual void __cdecl CHTController::ClearPinStatus(unsigned short,unsigned short) __ptr64
    */

void __thiscall CHTController::ClearPinStatus(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  char cVar2;
  ulong uVar3;
  uint uVar4;
  byte bVar5;
  undefined6 in_register_00000012;
  __uint64 _Var6;
  
  _Var6 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var6 = 0x2b;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x10);
  __empty_global_delete(pcVar1,_Var6);
  cVar2 = (*pcVar1)(this,param_1,param_2);
  if (cVar2 != '\0') {
    _Var6 = (__uint64)param_1;
    uVar3 = GetInterruptSelectLineNumber(this,param_1,param_2);
    pcVar1 = *(code **)(*(longlong *)this + 0x98);
    __empty_global_delete(pcVar1,_Var6);
    _Var6 = *(__uint64 *)(this + 0x9b8);
    uVar4 = (*pcVar1)(this,_Var6,1);
    bVar5 = (byte)uVar3;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      _Var6 = 0x2c;
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                  &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2,bVar5
                  ,(byte)(1 << (bVar5 & 0x1f)) & (byte)uVar4);
    }
    uVar4 = 1 << (bVar5 & 0x1f) & uVar4;
    if (uVar4 != 0) {
      pcVar1 = *(code **)(*(longlong *)this + 0xa0);
      __empty_global_delete(pcVar1,_Var6);
      (*pcVar1)(this,*(undefined8 *)(this + 0x9b8),uVar4,1);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== ConfigureInterrupt @ 140001bf0 =====

/* public: virtual void __cdecl CHTController::ConfigureInterrupt(unsigned short,unsigned short,enum
   _KINTERRUPT_POLARITY,enum _KINTERRUPT_MODE) __ptr64 */

void __thiscall
CHTController::ConfigureInterrupt
          (CHTController *this,ushort param_1,ushort param_2,_KINTERRUPT_POLARITY param_3,
          _KINTERRUPT_MODE param_4)

{
  code *pcVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined6 in_register_00000012;
  __uint64 _Var6;
  uint uVar7;
  longlong lVar8;
  
  _Var6 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var6 = 0x1f;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x10);
  __empty_global_delete(pcVar1,_Var6);
  _Var6 = (__uint64)param_1;
  cVar3 = (*pcVar1)(this,_Var6,param_2);
  if (cVar3 != '\0') {
    lVar8 = (ulonglong)param_1 * 0x10 + (ulonglong)param_2;
    pcVar1 = *(code **)(*(longlong *)this + 0x98);
    lVar2 = *(longlong *)(this + lVar8 * 8 + 0x28);
    __empty_global_delete(pcVar1,_Var6);
    _Var6 = lVar2 + 4;
    uVar4 = (*pcVar1)(this,_Var6,1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (_Var6 = (__uint64)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      _Var6 = 0x20;
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                  &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2,
                  (char)param_3,(char)param_4);
    }
    if (param_4 == 0) {
      uVar7 = uVar4 & 0xfffffffc | 4;
      if (param_3 == 1) {
        if ((uVar4 & 0x40) != 0) {
          uVar7 = uVar4 & 0xffffffbc | 4;
        }
      }
      else if ((param_3 == 2) && ((uVar4 & 0x40) == 0)) {
        uVar7 = uVar4 & 0xfffffffc | 0x44;
      }
    }
    else {
      uVar7 = uVar4;
      if (param_4 == 1) {
        uVar7 = uVar4 & 0xfffffff8;
        if (param_3 == 1) {
          uVar7 = uVar7 | 2;
        }
        else if (param_3 == 2) {
          uVar7 = uVar7 | 1;
        }
        else if (param_3 == 3) {
          uVar7 = uVar7 | 3;
        }
      }
    }
    lVar2 = *(longlong *)(this + lVar8 * 8 + 0x28);
    pcVar1 = *(code **)(*(longlong *)this + 0xa0);
    __empty_global_delete(pcVar1,_Var6);
    _Var6 = lVar2 + 4;
    (*pcVar1)(this,_Var6,uVar7,1);
    uVar5 = (ulonglong)((uint)param_1 * 0x10 + (uint)param_2);
    *(uint *)(this + uVar5 * 8 + 0xb5c) = uVar7;
    *(uint *)(this + uVar5 * 4 + 0x9d0) = *(uint *)(this + uVar5 * 4 + 0x9d0) | 2;
    pcVar1 = *(code **)(*(longlong *)this + 0x40);
    __empty_global_delete(pcVar1,_Var6);
    (*pcVar1)(this,param_1,param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== DisableBank @ 140001e00 =====

/* public: virtual void __cdecl IController::DisableBank(unsigned short) __ptr64 */

void __thiscall IController::DisableBank(IController *this,ushort param_1)

{
  code *pcVar1;
  char cVar2;
  undefined6 in_register_00000012;
  __uint64 _Var3;
  ushort uVar4;
  
  _Var3 = CONCAT62(in_register_00000012,param_1);
  uVar4 = 0;
  if (*(int *)(this + 0x10) != 0) {
    do {
      pcVar1 = *(code **)(*(longlong *)this + 0x10);
      __empty_global_delete(pcVar1,_Var3);
      _Var3 = (__uint64)param_1;
      cVar2 = (*pcVar1)(this,_Var3,uVar4);
      if (cVar2 != '\0') {
        pcVar1 = *(code **)(*(longlong *)this + 0x30);
        __empty_global_delete(pcVar1,_Var3);
        _Var3 = (__uint64)param_1;
        (*pcVar1)(this,_Var3,uVar4);
      }
      uVar4 = uVar4 + 1;
    } while ((uint)uVar4 < *(uint *)(this + 0x10));
  }
  return;
}



===== DisablePin @ 140001e90 =====

/* public: virtual void __cdecl CHTController::DisablePin(unsigned short,unsigned short) __ptr64 */

void __thiscall CHTController::DisablePin(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined6 in_register_00000012;
  __uint64 _Var6;
  longlong lVar7;
  
  _Var6 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var6 = 0x1d;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  lVar7 = (ulonglong)param_1 * 0x10 + (ulonglong)param_2;
  pcVar1 = *(code **)(*(longlong *)this + 0x98);
  __empty_global_delete(pcVar1,_Var6);
  _Var6 = *(__uint64 *)(this + lVar7 * 8 + 0x28);
  uVar3 = (*pcVar1)(this,_Var6,1);
  lVar2 = *(longlong *)(this + lVar7 * 8 + 0x28);
  pcVar1 = *(code **)(*(longlong *)this + 0x98);
  __empty_global_delete(pcVar1,_Var6);
  _Var6 = lVar2 + 4;
  uVar4 = (*pcVar1)(this,_Var6,1);
  if ((uVar3 >> 0xf & 1) != 0) {
    if ((uVar4 & 7) != 0) {
      uVar4 = uVar4 & 0xfffffff8;
    }
    lVar2 = *(longlong *)(this + lVar7 * 8 + 0x28);
    pcVar1 = *(code **)(*(longlong *)this + 0xa0);
    __empty_global_delete(pcVar1,_Var6);
    (*pcVar1)(this,lVar2 + 4,uVar4,1);
    uVar5 = (ulonglong)((uint)param_1 * 0x10 + (uint)param_2);
    *(uint *)(this + uVar5 * 8 + 0xb5c) = uVar4;
    *(uint *)(this + uVar5 * 4 + 0x9d0) = *(uint *)(this + uVar5 * 4 + 0x9d0) | 2;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== GetInterruptSelectLineNumber @ 140001fec =====

/* public: unsigned long __cdecl CHTController::GetInterruptSelectLineNumber(unsigned short,unsigned
   short) __ptr64 */

ulong __thiscall
CHTController::GetInterruptSelectLineNumber(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined6 in_register_00000012;
  __uint64 _Var3;
  
  _Var3 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var3 = 0x3d;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x98);
  __empty_global_delete(pcVar1,_Var3);
  uVar2 = (*pcVar1)(this,*(undefined8 *)
                          (this + ((ulonglong)param_1 * 0x10 + (ulonglong)param_2) * 8 + 0x28),1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return uVar2 >> 0x1c;
}



===== GpioReadULONG @ 1400020c0 =====

/* public: virtual unsigned long __cdecl CHTController::GpioReadULONG(unsigned long volatile *
   __ptr64,unsigned char) __ptr64 */

ulong __thiscall CHTController::GpioReadULONG(CHTController *this,ulong *param_1,uchar param_2)

{
  ulong uVar1;
  undefined1 in_CR8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  if (param_2 != '\0') {
    in_CR8 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(this + 0x9c0));
  }
  uVar1 = *param_1;
  if (param_2 != '\0') {
    KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(this + 0x9c0));
    KeLowerIrql(in_CR8);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return uVar1;
}



===== GpioWriteULONG @ 1400021b0 =====

/* public: virtual void __cdecl CHTController::GpioWriteULONG(unsigned long volatile *
   __ptr64,unsigned long,unsigned char) __ptr64 */

void __thiscall
CHTController::GpioWriteULONG(CHTController *this,ulong *param_1,ulong param_2,uchar param_3)

{
  undefined1 in_CR8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  if (param_3 != '\0') {
    in_CR8 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(this + 0x9c0));
  }
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  if (param_3 != '\0') {
    KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(this + 0x9c0));
    KeLowerIrql(in_CR8);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== IsMemoryMappedController @ 1400022a0 =====

/* public: virtual unsigned char __cdecl IController::IsMemoryMappedController(void) __ptr64 */

uchar __thiscall IController::IsMemoryMappedController(IController *this)

{
  return '\x01';
}



===== IsPinNumberReserved @ 1400022b0 =====

/* public: virtual unsigned char __cdecl IController::IsPinNumberReserved(unsigned short,unsigned
   short) __ptr64 */

uchar __thiscall IController::IsPinNumberReserved(IController *this,ushort param_1,ushort param_2)

{
  return '\0';
}



===== IsPinNumberWithinBounds @ 1400022c0 =====

/* public: virtual unsigned char __cdecl CHTController::IsPinNumberWithinBounds(unsigned
   short,unsigned short) __ptr64 */

uchar __thiscall
CHTController::IsPinNumberWithinBounds(CHTController *this,ushort param_1,ushort param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  undefined1 uVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  uVar3 = (undefined1)param_2;
  if (*(longlong *)(this + 0x18) != 0) {
    if (*(int *)(*(longlong *)(this + 0x18) +
                (ulonglong)(*(uint *)(this + 0x10) * (uint)param_1 + (uint)param_2) * 4) != 0) {
      if ((uint)param_2 < *(uint *)(this + 0x10)) {
        uVar2 = param_1 * 0x10 + param_2;
        if (*(uint *)(this + 0xc) <= (uint)uVar2) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return '\0';
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
            return '\0';
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return '\0';
          }
          WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                      &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,uVar3,
                      (char)uVar2,(char)*(uint *)(this + 0xc));
          return '\0';
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                    &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,uVar3);
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return '\x01';
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
          return '\x01';
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
          return '\x01';
        }
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
        return '\x01';
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return '\0';
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return '\0';
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return '\0';
      }
      uVar1 = 0x13;
      goto LAB_14000244b;
    }
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return '\0';
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
    return '\0';
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
    return '\0';
  }
  uVar1 = 0x12;
LAB_14000244b:
  WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,uVar3);
  return '\0';
}



===== MaskEdgePin @ 140002480 =====

/* public: virtual void __cdecl IController::MaskEdgePin(unsigned short,unsigned short) __ptr64 */

void __thiscall IController::MaskEdgePin(IController *this,ushort param_1,ushort param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined6 in_register_00000012;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)this + 0x38);
  __empty_global_delete(UNRECOVERED_JUMPTABLE,CONCAT62(in_register_00000012,param_1));
                    /* WARNING: Could not recover jumptable at 0x0001400024d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(this,param_1,param_2);
  return;
}



===== MaskInterrupt @ 1400024e0 =====

/* public: virtual void __cdecl CHTController::MaskInterrupt(unsigned short,unsigned short) __ptr64
    */

void __thiscall CHTController::MaskInterrupt(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  char cVar2;
  undefined1 uVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  undefined6 in_register_00000012;
  __uint64 _Var7;
  
  _Var7 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var7 = 0x32;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x10);
  __empty_global_delete(pcVar1,_Var7);
  cVar2 = (*pcVar1)(this,param_1,param_2);
  if (cVar2 != '\0') {
    _Var7 = (__uint64)param_1;
    uVar4 = GetInterruptSelectLineNumber(this,param_1,param_2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (_Var7 = (__uint64)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      _Var7 = 0x33;
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                 &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2,
                 (byte)uVar4);
    }
    uVar3 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(this + 0x9c0));
    pcVar1 = *(code **)(*(longlong *)this + 0x98);
    __empty_global_delete(pcVar1,_Var7);
    uVar5 = (*pcVar1)(this,*(undefined8 *)(this + 0x9b0),0);
    uVar6 = ~(1 << ((byte)uVar4 & 0x1f));
    uVar5 = uVar5 & uVar6;
    pcVar1 = *(code **)(*(longlong *)this + 0xa0);
    __empty_global_delete(pcVar1,(ulonglong)uVar6);
    (*pcVar1)(this,*(undefined8 *)(this + 0x9b0),uVar5,0);
    KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(this + 0x9c0));
    KeLowerIrql(uVar3);
    *(uint *)(this + 0xe6c) = uVar5;
    this[0xe68] = (CHTController)0x1;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== ReadBankStatus @ 1400026a0 =====

/* public: virtual unsigned long __cdecl CHTController::ReadBankStatus(unsigned short,unsigned long)
   __ptr64 */

ulong __thiscall CHTController::ReadBankStatus(CHTController *this,ushort param_1,ulong param_2)

{
  code *pcVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined6 in_register_00000012;
  __uint64 _Var6;
  uint uVar7;
  ushort uVar8;
  ulong uVar9;
  
  _Var6 = CONCAT62(in_register_00000012,param_1);
  uVar9 = 0;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      _Var6 = 0x2f;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      _Var6 = 0x30;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
               &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1);
    }
  }
  uVar8 = 0;
  if (*(int *)(this + 0x10) != 0) {
    uVar7 = 0;
    do {
      pcVar1 = *(code **)(*(longlong *)this + 0x10);
      __empty_global_delete(pcVar1,_Var6);
      _Var6 = (__uint64)param_1;
      cVar3 = (*pcVar1)(this,_Var6,uVar8);
      if ((cVar3 != '\0') && (uVar7 = 1 << ((byte)uVar7 & 0x1f), (param_2 & uVar7) != 0)) {
        pcVar1 = *(code **)(*(longlong *)this + 0x98);
        lVar2 = *(longlong *)(this + ((ulonglong)param_1 * 0x10 + (ulonglong)uVar8) * 8 + 0x28);
        __empty_global_delete(pcVar1,_Var6);
        _Var6 = lVar2 + 4;
        uVar4 = (*pcVar1)(this,_Var6,1);
        if ((uVar4 & 7) - 1 < 4) {
          pcVar1 = *(code **)(*(longlong *)this + 0x80);
          __empty_global_delete(pcVar1,_Var6);
          _Var6 = (__uint64)param_1;
          iVar5 = (*pcVar1)(this,_Var6,uVar8);
          if (iVar5 != 0) {
            uVar9 = uVar9 | uVar7;
          }
        }
      }
      uVar8 = uVar8 + 1;
      uVar7 = (uint)uVar8;
    } while (uVar7 < *(uint *)(this + 0x10));
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return uVar9;
}



===== ReadPinStatus @ 140002840 =====

/* public: virtual unsigned long __cdecl CHTController::ReadPinStatus(unsigned short,unsigned short)
   __ptr64 */

ulong __thiscall CHTController::ReadPinStatus(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  ulong uVar2;
  uint uVar3;
  byte bVar4;
  __uint64 _Var5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  _Var5 = (__uint64)param_1;
  uVar2 = GetInterruptSelectLineNumber(this,param_1,param_2);
  pcVar1 = *(code **)(*(longlong *)this + 0x98);
  __empty_global_delete(pcVar1,_Var5);
  uVar3 = (*pcVar1)(this,*(undefined8 *)(this + 0x9b8),1);
  bVar4 = (byte)uVar2;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                  &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2,bVar4
                  ,(byte)(1 << (bVar4 & 0x1f)) & (byte)uVar3);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
  }
  return (ulong)((uVar3 & 1 << (bVar4 & 0x1f)) != 0);
}



===== ReadPinValue @ 140002980 =====

/* public: virtual unsigned long __cdecl CHTController::ReadPinValue(unsigned short,unsigned short)
   __ptr64 */

ulong __thiscall CHTController::ReadPinValue(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined6 in_register_00000012;
  __uint64 _Var3;
  
  _Var3 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var3 = 0x22;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x98);
  __empty_global_delete(pcVar1,_Var3);
  uVar2 = (*pcVar1)(this,*(undefined8 *)
                          (this + ((ulonglong)param_1 * 0x10 + (ulonglong)param_2) * 8 + 0x28),1);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                 &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2,
                 (byte)uVar2 & 1);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
  }
  return uVar2 & 1;
}



===== RestoreGPIOBankContext @ 140002aa4 =====

/* public: void __cdecl CHTController::RestoreGPIOBankContext(unsigned short) __ptr64 */

void __thiscall CHTController::RestoreGPIOBankContext(CHTController *this,ushort param_1)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  undefined6 in_register_00000012;
  __uint64 _Var5;
  ulonglong uVar6;
  longlong lVar7;
  ushort uVar8;
  
  _Var5 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var5 = 0x4a;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  if (*(uint *)(this + 0x14) <= (uint)param_1) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return;
    }
    uVar6 = 0x4b;
    goto LAB_140002ead;
  }
  if (this[(ulonglong)param_1 + 0x9c8] == (CHTController)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      _Var5 = 0x50;
      goto LAB_140002dd5;
    }
  }
  else {
    uVar8 = 0;
    do {
      pcVar2 = *(code **)(*(longlong *)this + 0x10);
      __empty_global_delete(pcVar2,_Var5);
      uVar6 = (ulonglong)param_1;
      _Var5 = uVar6;
      cVar3 = (*pcVar2)(this,uVar6,uVar8);
      if (cVar3 != '\0') {
        lVar7 = uVar6 * 0x10 + (ulonglong)uVar8;
        pcVar2 = *(code **)(*(longlong *)this + 0x98);
        __empty_global_delete(pcVar2,_Var5);
        _Var5 = *(__uint64 *)(this + lVar7 * 8 + 0x28);
        uVar6 = (*pcVar2)(this,_Var5,1);
        if ((uVar6 & 0xf0004) == 0) {
          uVar4 = (uint)uVar8 + (uint)param_1 * 0x10;
          uVar6 = (ulonglong)uVar4;
          iVar1 = *(int *)(this + (ulonglong)uVar4 * 8 + 0xb58);
          if (iVar1 != 0) {
            pcVar2 = *(code **)(*(longlong *)this + 0xa0);
            __empty_global_delete(pcVar2,_Var5);
            _Var5 = *(__uint64 *)(this + lVar7 * 8 + 0x28);
            (*pcVar2)(this,_Var5,iVar1,1);
            *(uint *)(this + uVar6 * 4 + 0x9d0) = *(uint *)(this + uVar6 * 4 + 0x9d0) & 0xfffffffe;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              _Var5 = 0x4d;
              WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                          &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,
                          *(undefined4 *)(this + 0x20),(char)uVar4,
                          (char)*(undefined4 *)(this + uVar6 * 8 + 0xb58),
                          (char)*(undefined4 *)(this + uVar6 * 8 + 0xb5c));
            }
          }
          iVar1 = *(int *)(this + uVar6 * 8 + 0xb5c);
          if (iVar1 != 0) {
            lVar7 = *(longlong *)(this + lVar7 * 8 + 0x28);
            pcVar2 = *(code **)(*(longlong *)this + 0xa0);
            __empty_global_delete(pcVar2,_Var5);
            _Var5 = lVar7 + 4;
            (*pcVar2)(this,_Var5,iVar1,1);
            *(uint *)(this + uVar6 * 4 + 0x9d0) = *(uint *)(this + uVar6 * 4 + 0x9d0) & 0xfffffffd;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              _Var5 = 0x4e;
              WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                          &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,
                          *(undefined4 *)(this + 0x20),(char)uVar4,
                          (char)*(undefined4 *)(this + uVar6 * 8 + 0xb58),
                          (char)*(undefined4 *)(this + uVar6 * 8 + 0xb5c));
            }
          }
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          _Var5 = 0x4c;
          uVar4 = (uint)param_1 * 0x10 + (uint)uVar8;
          WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                      &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,*(undefined4 *)(this + 0x20),
                      (char)uVar4,(char)*(undefined4 *)(this + (ulonglong)uVar4 * 8 + 0xb58),
                      (char)*(undefined4 *)(this + (ulonglong)uVar4 * 8 + 0xb5c));
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x10);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      _Var5 = 0x4f;
LAB_140002dd5:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),_Var5,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
  }
  this[(ulonglong)param_1 + 0x9c8] = (CHTController)0x0;
  if (this[0xe68] != (CHTController)0x0) {
    pcVar2 = *(code **)(*(longlong *)this + 0xa0);
    __empty_global_delete(pcVar2,_Var5);
    (*pcVar2)(this,*(undefined8 *)(this + 0x9b0),*(undefined4 *)(this + 0xe6c),1);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,*(undefined4 *)(this + 0x20),
                (char)*(undefined4 *)(this + 0xe6c));
    }
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
    return;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
    return;
  }
  uVar6 = 0x53;
LAB_140002ead:
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
          &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  return;
}



===== SaveGPIOBankContext @ 140002ed8 =====

/* public: void __cdecl CHTController::SaveGPIOBankContext(unsigned short) __ptr64 */

void __thiscall CHTController::SaveGPIOBankContext(CHTController *this,ushort param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined6 in_register_00000012;
  __uint64 _Var3;
  ulonglong uVar4;
  
  _Var3 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var3 = 0x45;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  if ((uint)param_1 < *(uint *)(this + 0x14)) {
    if (((this[(ulonglong)param_1 + 0x9c8] != (CHTController)0x0) &&
        ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      _Var3 = 0x47;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
    pcVar1 = *(code **)(*(longlong *)this + 0x98);
    __empty_global_delete(pcVar1,_Var3);
    uVar2 = (*pcVar1)(this,*(undefined8 *)(this + 0x9b0),1);
    *(undefined4 *)(this + 0xe6c) = uVar2;
    this[0xe68] = (CHTController)0x1;
    this[(ulonglong)param_1 + 0x9c8] = (CHTController)0x1;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
              &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
      return;
    }
    uVar4 = 0x49;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return;
    }
    uVar4 = 0x46;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
          &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  return;
}



===== SetPinDirectionInput @ 140003050 =====

/* public: virtual void __cdecl CHTController::SetPinDirectionInput(unsigned short,unsigned short)
   __ptr64 */

void __thiscall
CHTController::SetPinDirectionInput(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined6 in_register_00000012;
  __uint64 _Var5;
  longlong lVar6;
  
  _Var5 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var5 = 0x17;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x10);
  __empty_global_delete(pcVar1,_Var5);
  _Var5 = (__uint64)param_1;
  cVar2 = (*pcVar1)(this,_Var5,param_2);
  if (cVar2 != '\0') {
    lVar6 = (ulonglong)param_1 * 0x10 + (ulonglong)param_2;
    pcVar1 = *(code **)(*(longlong *)this + 0x98);
    __empty_global_delete(pcVar1,_Var5);
    _Var5 = *(__uint64 *)(this + lVar6 * 8 + 0x28);
    uVar3 = (*pcVar1)(this,_Var5,1);
    if ((uVar3 & 0x700) != 0x200) {
      uVar3 = uVar3 & 0xfffff8ff;
      if (((*(int *)(this + 0x20) != 5) || (param_1 != 0)) || (param_2 < 5)) {
        uVar3 = uVar3 | 0x200;
      }
      pcVar1 = *(code **)(*(longlong *)this + 0xa0);
      __empty_global_delete(pcVar1,_Var5);
      (*pcVar1)(this,*(undefined8 *)(this + lVar6 * 8 + 0x28),uVar3,1);
      uVar4 = (ulonglong)((uint)param_1 * 0x10 + (uint)param_2);
      *(uint *)(this + uVar4 * 8 + 0xb58) = uVar3;
      *(uint *)(this + uVar4 * 4 + 0x9d0) = *(uint *)(this + uVar4 * 4 + 0x9d0) | 1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== SetPinDirectionOutput @ 140003210 =====

/* public: virtual void __cdecl CHTController::SetPinDirectionOutput(unsigned short,unsigned short)
   __ptr64 */

void __thiscall
CHTController::SetPinDirectionOutput(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined6 in_register_00000012;
  __uint64 _Var5;
  longlong lVar6;
  
  _Var5 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var5 = 0x1a;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x10);
  __empty_global_delete(pcVar1,_Var5);
  _Var5 = (__uint64)param_1;
  cVar2 = (*pcVar1)(this,_Var5,param_2);
  if (cVar2 != '\0') {
    lVar6 = (ulonglong)param_1 * 0x10 + (ulonglong)param_2;
    pcVar1 = *(code **)(*(longlong *)this + 0x98);
    __empty_global_delete(pcVar1,_Var5);
    _Var5 = *(__uint64 *)(this + lVar6 * 8 + 0x28);
    uVar3 = (*pcVar1)(this,_Var5,1);
    if ((uVar3 & 0x700) != 0x100) {
      uVar3 = uVar3 & 0xfffff9ff | 0x100;
      pcVar1 = *(code **)(*(longlong *)this + 0xa0);
      __empty_global_delete(pcVar1,_Var5);
      (*pcVar1)(this,*(undefined8 *)(this + lVar6 * 8 + 0x28),uVar3,1);
      uVar4 = (ulonglong)((uint)param_1 * 0x10 + (uint)param_2);
      *(uint *)(this + uVar4 * 8 + 0xb58) = uVar3;
      *(uint *)(this + uVar4 * 4 + 0x9d0) = *(uint *)(this + uVar4 * 4 + 0x9d0) | 1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== UnMaskEdgePin @ 1400033b0 =====

/* public: virtual void __cdecl IController::UnMaskEdgePin(unsigned short,unsigned short,enum
   _KINTERRUPT_POLARITY) __ptr64 */

void __thiscall
IController::UnMaskEdgePin
          (IController *this,ushort param_1,ushort param_2,_KINTERRUPT_POLARITY param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined6 in_register_00000012;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)this + 0x40);
  __empty_global_delete(UNRECOVERED_JUMPTABLE,CONCAT62(in_register_00000012,param_1));
                    /* WARNING: Could not recover jumptable at 0x000140003401. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(this,param_1,param_2);
  return;
}



===== UnMaskInterrupt @ 140003410 =====

/* public: virtual void __cdecl CHTController::UnMaskInterrupt(unsigned short,unsigned short)
   __ptr64 */

void __thiscall CHTController::UnMaskInterrupt(CHTController *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  char cVar2;
  undefined1 uVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  undefined6 in_register_00000012;
  __uint64 _Var7;
  
  _Var7 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var7 = 0x35;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x10);
  __empty_global_delete(pcVar1,_Var7);
  cVar2 = (*pcVar1)(this,param_1,param_2);
  if (cVar2 != '\0') {
    _Var7 = (__uint64)param_1;
    uVar4 = GetInterruptSelectLineNumber(this,param_1,param_2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (_Var7 = (__uint64)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      _Var7 = 0x36;
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                 &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2,
                 (byte)uVar4);
    }
    uVar3 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(this + 0x9c0));
    pcVar1 = *(code **)(*(longlong *)this + 0x98);
    __empty_global_delete(pcVar1,_Var7);
    uVar5 = (*pcVar1)(this,*(undefined8 *)(this + 0x9b0),0);
    uVar6 = 1 << ((byte)uVar4 & 0x1f);
    uVar5 = uVar5 | uVar6;
    pcVar1 = *(code **)(*(longlong *)this + 0xa0);
    __empty_global_delete(pcVar1,(ulonglong)uVar6);
    (*pcVar1)(this,*(undefined8 *)(this + 0x9b0),uVar5,0);
    KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(this + 0x9c0));
    KeLowerIrql(uVar3);
    *(uint *)(this + 0xe6c) = uVar5;
    this[0xe68] = (CHTController)0x1;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== WritePinValue @ 1400035d0 =====

/* public: virtual void __cdecl CHTController::WritePinValue(unsigned short,unsigned short,unsigned
   long) __ptr64 */

void __thiscall
CHTController::WritePinValue(CHTController *this,ushort param_1,ushort param_2,ulong param_3)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined6 in_register_00000012;
  __uint64 _Var5;
  longlong lVar6;
  uint uVar7;
  
  _Var5 = CONCAT62(in_register_00000012,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var5 = 0x25;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  pcVar1 = *(code **)(*(longlong *)this + 0x10);
  __empty_global_delete(pcVar1,_Var5);
  _Var5 = (__uint64)param_1;
  cVar2 = (*pcVar1)(this,_Var5,param_2);
  if (cVar2 != '\0') {
    lVar6 = (ulonglong)param_1 * 0x10 + (ulonglong)param_2;
    pcVar1 = *(code **)(*(longlong *)this + 0x98);
    __empty_global_delete(pcVar1,_Var5);
    _Var5 = *(__uint64 *)(this + lVar6 * 8 + 0x28);
    uVar3 = (*pcVar1)(this,_Var5,1);
    uVar7 = uVar3 | 2;
    if (param_3 == 0) {
      uVar7 = uVar3 & 0xfffffffd;
    }
    pcVar1 = *(code **)(*(longlong *)this + 0xa0);
    __empty_global_delete(pcVar1,_Var5);
    (*pcVar1)(this,*(undefined8 *)(this + lVar6 * 8 + 0x28),uVar7,1);
    uVar4 = (ulonglong)((uint)param_1 * 0x10 + (uint)param_2);
    *(uint *)(this + uVar4 * 8 + 0xb58) = uVar7;
    *(uint *)(this + uVar4 * 4 + 0x9d0) = *(uint *)(this + uVar4 * 4 + 0x9d0) | 1;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                 &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids,(uint)param_1,(char)param_2,
                 (char)param_3);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
            &WPP_32ad8d4426db348713f9cf23ff119a36_Traceguids);
  }
  return;
}



===== __empty_global_delete @ 140003770 =====

/* void __cdecl __empty_global_delete(void * __ptr64,unsigned __int64) */

void __cdecl __empty_global_delete(void *param_1,__uint64 param_2)

{
  return;
}



===== WPP_SF_dddd @ 140003774 =====

void WPP_SF_dddd(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== DriverEntry @ 14000381c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(__uint64 param_1,__uint64 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  __uint64 _Var4;
  __uint64 local_res18 [2];
  undefined4 local_168 [2];
  code *local_160;
  code *local_158;
  undefined4 local_148 [6];
  undefined4 local_130;
  undefined4 local_12c;
  undefined *local_118;
  undefined4 local_108 [56];
  
  memset(local_108,0,0xd8);
  _DAT_140008888 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140008868 = &WPP_ThisDir_CTLGUID_GpioTraceGuid;
  DAT_140008870 = 0;
  _DAT_140008880 = 0;
  WppLoadTracingSupport();
  _DAT_140008880 = 0;
  WppInitKm(param_1,param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
  }
  memset(local_168,0,0x20);
  local_168[0] = 0x20;
  local_160 = GPIOEvtDeviceAdd;
  local_158 = GPIOEvtDriverUnload;
  _Var4 = 0;
  memset(local_148,0,0x38);
  local_118 = PTR__WDF_GPIO_DRIVER_CTX_TYPE_INFO_140008020;
  local_148[0] = 0x38;
  local_130 = 1;
  local_12c = 1;
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x3a0);
  __empty_global_delete(pcVar1,_Var4);
  iVar2 = (*pcVar1)(WdfDriverGlobals,param_1,param_2,local_148,local_168,local_res18);
  if (iVar2 < 0) {
    WppCleanupKm(0,param_1);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_1 = 0xb;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
    }
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
    __empty_global_delete(pcVar1,param_1);
    _Var4 = local_res18[0];
    uVar3 = (*pcVar1)(WdfDriverGlobals,local_res18[0],PTR__WDF_GPIO_DRIVER_CTX_TYPE_INFO_140008020);
    KeInitializeSpinLock(uVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      _Var4 = 0xc;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
    }
    PrepareGpioRegistrationPacket(local_108);
    pcVar1 = GpioClxExportedInterfaces;
    __empty_global_delete(GpioClxExportedInterfaces,_Var4);
    iVar2 = (*pcVar1)(local_res18[0],local_108,param_2);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids,iVar2);
      }
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
  }
  return iVar2;
}



===== GPIOEvtDeviceAdd @ 140003af0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GPIOEvtDeviceAdd(undefined8 param_1,__uint64 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  __uint64 _Var4;
  __uint64 _Var5;
  ulonglong uVar6;
  __uint64 *p_Var7;
  undefined1 auStack_b8 [32];
  __uint64 local_98;
  __uint64 local_90;
  undefined1 local_88 [56];
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_b8;
  _Var4 = param_2;
  local_90 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var4 = 0x10;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
  }
  _Var5 = local_90;
  pcVar1 = DAT_1400088b0;
  __empty_global_delete(DAT_1400088b0,_Var4);
  iVar2 = (*pcVar1)(param_1,_Var5,local_88);
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140003d23;
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar6 = 0x11;
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 600);
    __empty_global_delete(pcVar1,_Var5);
    p_Var7 = &local_90;
    iVar2 = (*pcVar1)(WdfDriverGlobals,p_Var7,local_88,&local_98);
    pcVar1 = DAT_1400088b8;
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_140003d23;
      uVar6 = 0x12;
    }
    else {
      __empty_global_delete(DAT_1400088b8,(__uint64)p_Var7);
      _Var4 = local_98;
      iVar2 = (*pcVar1)(param_1);
      if (-1 < iVar2) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          _Var4 = 0x14;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                  &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
        }
        uStack_3c = 2;
        local_50 = 0x20000001c;
        local_48 = 0x200000002;
        local_38 = 2;
        local_40 = 1;
        pcVar1 = *(code **)(WdfFunctions_01015 + 0xe8);
        __empty_global_delete(pcVar1,_Var4);
        _Var4 = local_98;
        (*pcVar1)(WdfDriverGlobals,local_98,&local_50);
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x260);
        __empty_global_delete(pcVar1,_Var4);
        (*pcVar1)(WdfDriverGlobals,local_98,0);
        goto LAB_140003d23;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_140003d23;
      uVar6 = 0x13;
    }
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  WPP_SF_D(uVar3,uVar6,&WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids,iVar2);
LAB_140003d23:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
  }
  return iVar2;
}



===== GPIOEvtDriverUnload @ 140003d80 =====

void GPIOEvtDriverUnload(undefined8 param_1,__uint64 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined **ppuVar3;
  
  pcVar1 = DAT_1400088a8;
  __empty_global_delete(DAT_1400088a8,param_2);
  iVar2 = (*pcVar1)(param_1);
  if (iVar2 < 0) {
    ppuVar3 = &WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (ppuVar3 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      ppuVar3 = (undefined **)0x16;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids,iVar2);
    }
  }
  else {
    ppuVar3 = &WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      ppuVar3 = (undefined **)0x17;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_a56992bd0041328c0275b3f3755b9ac7_Traceguids);
    }
  }
  WppCleanupKm(0,(__uint64)ppuVar3);
  return;
}



===== WppClassicProviderCallback @ 140003e30 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0;
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
    }
    *(undefined8 *)(param_4 + 0x18) = uVar1;
  }
  return;
}



===== operator_new @ 140003e60 =====

/* public: static void * __ptr64 __cdecl ControllerLibrary<class CHTController>::operator
   new(unsigned __int64,enum _POOL_TYPE,unsigned long) */

void * __cdecl
ControllerLibrary<CHTController>::operator_new(__uint64 param_1,_POOL_TYPE param_2,ulong param_3)

{
  void *_Dst;
  undefined4 in_register_00000084;
  
  _Dst = (void *)ExAllocatePoolWithTag(param_2,param_1,CONCAT44(in_register_00000084,param_3));
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



===== `scalar_deleting_destructor' @ 140003ea0 =====

/* public: virtual void * __ptr64 __cdecl ControllerLibrary<class CHTController>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
ControllerLibrary<CHTController>::_scalar_deleting_destructor_
          (ControllerLibrary<CHTController> *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  CHTController::~CHTController((CHTController *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0xe70);
    }
  }
  return this;
}



===== AcpiMmioOpRegionHandler @ 140003ef0 =====

/* long __cdecl AcpiMmioOpRegionHandler(unsigned long,void * __ptr64,unsigned long,unsigned
   long,unsigned long * __ptr64,unsigned __int64,void (__cdecl*)(void * __ptr64),void * __ptr64) */

long __cdecl
AcpiMmioOpRegionHandler
          (ulong param_1,void *param_2,ulong param_3,ulong param_4,ulong *param_5,__uint64 param_6,
          _func_void_void_ptr *param_7,void *param_8)

{
  longlong *plVar1;
  code *pcVar2;
  __uint64 *p_Var3;
  __uint64 _Var4;
  ulong uVar5;
  longlong lVar6;
  long lVar7;
  
  lVar7 = 0;
  lVar6 = (ulonglong)param_3 + *(longlong *)(param_6 + 0x10);
  if (param_1 == 0) {
    p_Var3 = *(__uint64 **)param_6;
    _Var4 = *p_Var3;
    pcVar2 = *(code **)(_Var4 + 0x98);
    __empty_global_delete(pcVar2,_Var4);
    uVar5 = (*pcVar2)(p_Var3,lVar6,1);
    *param_5 = uVar5;
  }
  else if (param_1 == 1) {
    plVar1 = *(longlong **)param_6;
    pcVar2 = *(code **)(*plVar1 + 0xa0);
    __empty_global_delete(pcVar2,(__uint64)param_2);
    (*pcVar2)(plVar1,lVar6,*param_5,1);
  }
  else {
    lVar7 = -0x3ffffff0;
  }
  return lVar7;
}



===== ClearMultiplePinStatus @ 140003f8c =====

/* public: void __cdecl ControllerLibrary<class CHTController>::ClearMultiplePinStatus(unsigned
   short,unsigned long) __ptr64 */

void __thiscall
ControllerLibrary<CHTController>::ClearMultiplePinStatus
          (ControllerLibrary<CHTController> *this,ushort param_1,ulong param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined6 in_register_00000012;
  __uint64 _Var3;
  ushort uVar4;
  
  _Var3 = CONCAT62(in_register_00000012,param_1);
  uVar4 = 0;
  if (*(int *)(this + 0x10) != 0) {
    uVar2 = 0;
    do {
      if ((param_2 >> (uVar2 & 0x1f) & 1) != 0) {
        pcVar1 = *(code **)(*(longlong *)this + 0x88);
        __empty_global_delete(pcVar1,_Var3);
        _Var3 = (__uint64)param_1;
        (*pcVar1)(this,_Var3,uVar4);
      }
      uVar4 = uVar4 + 1;
      uVar2 = (uint)uVar4;
    } while (uVar2 < *(uint *)(this + 0x10));
  }
  return;
}



===== ClearSinglePinStatus @ 140004004 =====

/* public: void __cdecl ControllerLibrary<class CHTController>::ClearSinglePinStatus(unsigned
   short,unsigned short) __ptr64 */

void __thiscall
ControllerLibrary<CHTController>::ClearSinglePinStatus
          (ControllerLibrary<CHTController> *this,ushort param_1,ushort param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined6 in_register_00000012;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)this + 0x88);
  __empty_global_delete(UNRECOVERED_JUMPTABLE,CONCAT62(in_register_00000012,param_1));
                    /* WARNING: Could not recover jumptable at 0x000140004058. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(this,param_1,param_2);
  return;
}



===== ConfigurePinDirection @ 14000405c =====

/* public: void __cdecl ControllerLibrary<class CHTController>::ConfigurePinDirection(unsigned
   short,unsigned short,enum _GPIO_CONNECT_IO_PINS_MODE) __ptr64 */

void __thiscall
ControllerLibrary<CHTController>::ConfigurePinDirection
          (ControllerLibrary<CHTController> *this,ushort param_1,ushort param_2,
          _GPIO_CONNECT_IO_PINS_MODE param_3)

{
  undefined6 in_register_00000012;
  code *pcVar1;
  
  if (param_3 == 1) {
    pcVar1 = *(code **)(*(longlong *)this + 0x20);
  }
  else {
    if (param_3 != 2) {
      return;
    }
    pcVar1 = *(code **)(*(longlong *)this + 0x28);
  }
  __empty_global_delete(pcVar1,CONCAT62(in_register_00000012,param_1));
  (*pcVar1)(this,param_1,param_2);
  return;
}



===== DisableEdgeorLevelPin @ 1400040c0 =====

/* public: void __cdecl ControllerLibrary<class CHTController>::DisableEdgeorLevelPin(unsigned
   short,unsigned short) __ptr64 */

void __thiscall
ControllerLibrary<CHTController>::DisableEdgeorLevelPin
          (ControllerLibrary<CHTController> *this,ushort param_1,ushort param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined6 in_register_00000012;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)this + 0x30);
  __empty_global_delete(UNRECOVERED_JUMPTABLE,CONCAT62(in_register_00000012,param_1));
                    /* WARNING: Could not recover jumptable at 0x000140004111. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(this,param_1,param_2);
  return;
}



===== EnableEdgeorLevelPin @ 140004114 =====

/* public: void __cdecl ControllerLibrary<class CHTController>::EnableEdgeorLevelPin(unsigned
   short,unsigned short,enum _KINTERRUPT_POLARITY,enum _KINTERRUPT_MODE) __ptr64 */

void __thiscall
ControllerLibrary<CHTController>::EnableEdgeorLevelPin
          (ControllerLibrary<CHTController> *this,ushort param_1,ushort param_2,
          _KINTERRUPT_POLARITY param_3,_KINTERRUPT_MODE param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined6 in_register_00000012;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(longlong *)this + 0x48);
  __empty_global_delete(UNRECOVERED_JUMPTABLE,CONCAT62(in_register_00000012,param_1));
                    /* WARNING: Could not recover jumptable at 0x000140004174. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(this,param_1,param_2,param_3);
  return;
}



===== GpioClearActiveInterrupts @ 140004180 =====

/* long __cdecl GpioClearActiveInterrupts(void * __ptr64,struct
   _GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS * __ptr64) */

long __cdecl
GpioClearActiveInterrupts(void *param_1,_GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS *param_2)

{
  ushort uVar1;
  ulong uVar2;
  long lVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar3 = -0x3ffffff3;
  }
  else {
    uVar1 = *(ushort *)param_2;
    uVar2 = *(ulong *)(param_2 + 8);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Dxx(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                 &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                 *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2);
    }
    ControllerLibrary<CHTController>::ClearMultiplePinStatus
              (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
    *(undefined8 *)(param_2 + 0x10) = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== GpioConnectIoPins @ 1400042c0 =====

/* long __cdecl GpioConnectIoPins(void * __ptr64,struct _GPIO_CONNECT_IO_PINS_PARAMETERS * __ptr64)
    */

long __cdecl GpioConnectIoPins(void *param_1,_GPIO_CONNECT_IO_PINS_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  _GPIO_CONNECT_IO_PINS_MODE _Var3;
  ulonglong uVar4;
  long lVar5;
  ushort *puVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar5 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_CONNECT_IO_PINS_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar5 = -0x3ffffff3;
  }
  else {
    uVar1 = *(ushort *)param_2;
    puVar6 = *(ushort **)(param_2 + 8);
    uVar2 = *(ushort *)(param_2 + 0x10);
    _Var3 = *(_GPIO_CONNECT_IO_PINS_MODE *)(param_2 + 0x14);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Dxxx(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                  &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                  *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2,(char)_Var3);
    }
    if (uVar2 != 0) {
      uVar4 = (ulonglong)uVar2;
      do {
        uVar2 = *puVar6;
        ControllerLibrary<CHTController>::IsValidPinNumber
                  (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
        ControllerLibrary<CHTController>::ConfigurePinDirection
                  (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,_Var3);
        puVar6 = puVar6 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar5;
}



===== GpioDisableInterrupt @ 140004440 =====

/* long __cdecl GpioDisableInterrupt(void * __ptr64,struct _GPIO_DISABLE_INTERRUPT_PARAMETERS *
   __ptr64) */

long __cdecl GpioDisableInterrupt(void *param_1,_GPIO_DISABLE_INTERRUPT_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  uchar uVar4;
  __uint64 _Var5;
  long lVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar6 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_DISABLE_INTERRUPT_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar6 = -0x3ffffff3;
  }
  else {
    uVar1 = *(ushort *)param_2;
    uVar2 = *(ushort *)(param_2 + 2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DDx(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                 &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                 *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2);
    }
    _Var5 = (__uint64)uVar1;
    uVar4 = ControllerLibrary<CHTController>::IsValidPinNumber
                      (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
    pcVar3 = DAT_1400088c0;
    if (uVar4 != '\0') {
      __empty_global_delete(DAT_1400088c0,_Var5);
      (*pcVar3)(param_1,uVar1);
      ControllerLibrary<CHTController>::ConfigurePinDirection
                (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,1);
      ControllerLibrary<CHTController>::DisableEdgeorLevelPin
                (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
      _Var5 = (__uint64)uVar1;
      ControllerLibrary<CHTController>::ClearSinglePinStatus
                (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
      pcVar3 = DAT_1400088c8;
      __empty_global_delete(DAT_1400088c8,_Var5);
      (*pcVar3)(param_1,uVar1);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar6;
}



===== GpioDisconnectIoPins @ 1400045f0 =====

/* long __cdecl GpioDisconnectIoPins(void * __ptr64,struct _GPIO_DISCONNECT_IO_PINS_PARAMETERS *
   __ptr64) */

long __cdecl GpioDisconnectIoPins(void *param_1,_GPIO_DISCONNECT_IO_PINS_PARAMETERS *param_2)

{
  _GPIO_DISCONNECT_IO_PINS_PARAMETERS _Var1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  longlong lVar5;
  ushort uVar6;
  long lVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar7 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_DISCONNECT_IO_PINS_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar7 = -0x3ffffff3;
  }
  else {
    uVar2 = *(ushort *)param_2;
    lVar5 = *(longlong *)(param_2 + 8);
    uVar4 = *(uint *)(param_2 + 0x10);
    _Var1 = param_2[0x18];
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Dxxd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                  &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                  *(undefined4 *)((longlong)param_1 + 8),(char)uVar2,(char)uVar4,(byte)_Var1 & 1);
    }
    if ((((byte)_Var1 & 1) == 0) && (uVar6 = 0, uVar4 != 0)) {
      do {
        uVar3 = *(ushort *)(lVar5 + (ulonglong)uVar6 * 2);
        ControllerLibrary<CHTController>::IsValidPinNumber
                  (*(ControllerLibrary<CHTController> **)param_1,uVar2,uVar3);
        ControllerLibrary<CHTController>::ConfigurePinDirection
                  (*(ControllerLibrary<CHTController> **)param_1,uVar2,uVar3,1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar7;
}



===== GpioEnableInterrupt @ 1400047a0 =====

/* long __cdecl GpioEnableInterrupt(void * __ptr64,struct _GPIO_ENABLE_INTERRUPT_PARAMETERS *
   __ptr64) */

long __cdecl GpioEnableInterrupt(void *param_1,_GPIO_ENABLE_INTERRUPT_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  _KINTERRUPT_POLARITY _Var3;
  _KINTERRUPT_MODE _Var4;
  code *pcVar5;
  uchar uVar6;
  __uint64 _Var7;
  ulonglong uVar8;
  long lVar9;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar9 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_ENABLE_INTERRUPT_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      uVar8 = 0x27;
LAB_140004945:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
  }
  else {
    _Var3 = *(_KINTERRUPT_POLARITY *)(param_2 + 0xc);
    uVar1 = *(ushort *)param_2;
    uVar2 = *(ushort *)(param_2 + 2);
    _Var4 = *(_KINTERRUPT_MODE *)(param_2 + 8);
    if (_Var3 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DDxDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                     &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                     *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2,(char)_Var4,
                     (char)_Var3);
      }
      _Var7 = (__uint64)uVar1;
      uVar6 = ControllerLibrary<CHTController>::IsValidPinNumber
                        (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
      pcVar5 = DAT_1400088c0;
      if (uVar6 != '\0') {
        __empty_global_delete(DAT_1400088c0,_Var7);
        (*pcVar5)(param_1,uVar1);
        ControllerLibrary<CHTController>::ConfigurePinDirection
                  (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,1);
        ControllerLibrary<CHTController>::ClearSinglePinStatus
                  (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
        _Var7 = (__uint64)uVar1;
        ControllerLibrary<CHTController>::EnableEdgeorLevelPin
                  (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,_Var3,_Var4);
        pcVar5 = DAT_1400088c8;
        __empty_global_delete(DAT_1400088c8,_Var7);
        (*pcVar5)(param_1,uVar1);
      }
      goto LAB_14000495a;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar8 = 0x28;
      goto LAB_140004945;
    }
  }
  lVar9 = -0x3ffffff3;
LAB_14000495a:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar9;
}



===== GpioMaskInterrupts @ 1400049c0 =====

/* long __cdecl GpioMaskInterrupts(void * __ptr64,struct _GPIO_MASK_INTERRUPT_PARAMETERS * __ptr64)
    */

long __cdecl GpioMaskInterrupts(void *param_1,_GPIO_MASK_INTERRUPT_PARAMETERS *param_2)

{
  ushort uVar1;
  ulong uVar2;
  long lVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar3 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_MASK_INTERRUPT_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar3 = -0x3ffffff3;
  }
  else {
    uVar1 = *(ushort *)param_2;
    uVar2 = *(ulong *)(param_2 + 8);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                 &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                 *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2);
    }
    ControllerLibrary<CHTController>::MaskEdgeorLevelPins
              (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
    ControllerLibrary<CHTController>::ClearMultiplePinStatus
              (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
    *(undefined8 *)(param_2 + 0x10) = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar3;
}



===== GpioPrepareController @ 140004b10 =====

/* long __cdecl GpioPrepareController(struct WDFDEVICE__ * __ptr64,void * __ptr64,struct
   WDFCMRESLIST__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
GpioPrepareController
          (WDFDEVICE__ *param_1,void *param_2,WDFCMRESLIST__ *param_3,WDFCMRESLIST__ *param_4)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  char *pcVar4;
  undefined8 uVar5;
  CHTController *this;
  void *pvVar6;
  WDFCMRESLIST__ *pWVar7;
  __uint64 _Var8;
  uint uVar9;
  uint local_res10 [2];
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar10;
  
  pvVar6 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pvVar6 = (void *)0xa;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar3 = 0;
  local_res10[0] = 0;
  if (param_2 == (void *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar3 = -0x3ffffff3;
  }
  else {
    *(undefined8 *)param_2 = 0;
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x980);
    __empty_global_delete(pcVar1,(__uint64)pvVar6);
    pWVar7 = param_4;
    uVar2 = (*pcVar1)(WdfDriverGlobals);
    uVar9 = 0;
    if (uVar2 != 0) {
      do {
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x988);
        __empty_global_delete(pcVar1,(__uint64)pWVar7);
        pWVar7 = param_4;
        pcVar4 = (char *)(*pcVar1)(WdfDriverGlobals,param_4,uVar9);
        if (pcVar4 == (char *)0x0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                    &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
          }
          lVar3 = -0x3ffffe7e;
          goto LAB_140004dfe;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          pWVar7 = (WDFCMRESLIST__ *)0xd;
          in_stack_ffffffffffffffb8 =
               CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),uVar9);
          WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                      &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,uVar2,(char)uVar9,*pcVar4,
                      (char)*(undefined2 *)(pcVar4 + 2));
        }
        uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
        if (*pcVar4 == '\x03') {
          uVar5 = MmMapIoSpaceEx(*(undefined8 *)(pcVar4 + 4),*(undefined4 *)(pcVar4 + 0xc),0x204);
          *(undefined8 *)((longlong)param_2 + 0x10) = uVar5;
          *(undefined4 *)((longlong)param_2 + 0x18) = *(undefined4 *)(pcVar4 + 0xc);
          in_stack_ffffffffffffffb8 = CONCAT44(uVar10,*(undefined4 *)(pcVar4 + 0xc));
          DbgPrintEx(0x4d,1,
                     "%!FUNC! ResourceMemory: QuadPart=0x%x, Length=0x%x(%d), MappedMemory: StartAddr=0x%llx \n"
                     ,*(undefined4 *)(pcVar4 + 4),in_stack_ffffffffffffffb8,
                     *(undefined4 *)(pcVar4 + 0xc),uVar5);
          if ((*(int *)((longlong)param_2 + 0x18) != 0) &&
             (*(longlong *)((longlong)param_2 + 0x10) != 0)) {
            pWVar7 = (WDFCMRESLIST__ *)local_res10;
            lVar3 = GetAcpiHardwareInstance(param_1,(ulong *)pWVar7);
            if (-1 < lVar3) goto LAB_140004cce;
          }
          lVar3 = -0x3fffffff;
          goto LAB_140004dfe;
        }
LAB_140004cce:
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar2);
    }
    _Var8 = 0x200;
    *(uint *)((longlong)param_2 + 8) = local_res10[0];
    this = ControllerLibrary<CHTController>::operator_new(0xe70,0x200,0x43434854);
    if (this == (CHTController *)0x0) {
      this = (CHTController *)0x0;
    }
    else {
      _Var8 = (__uint64)local_res10[0];
      CHTController::CHTController
                (this,local_res10[0],*(void **)((longlong)param_2 + 0x10),
                 *(ulong *)((longlong)param_2 + 0x18));
      *(undefined ***)this = &ControllerLibrary<CHTController>::_vftable_;
    }
    *(CHTController **)param_2 = this;
    if (this == (CHTController *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        _Var8 = 0xe;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
      }
      lVar3 = -0x3fffffe9;
    }
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x108);
    __empty_global_delete(pcVar1,_Var8);
    uVar5 = (*pcVar1)(WdfDriverGlobals,param_1);
    RegisterOpRegionHandler
              (uVar5,2,local_res10[0] + 0x90,AcpiMmioOpRegionHandler,param_2,0,
               (longlong)param_2 + 0x20);
  }
LAB_140004dfe:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar3;
}



===== GpioQueryActiveInterrupts @ 140004e50 =====

/* long __cdecl GpioQueryActiveInterrupts(void * __ptr64,struct
   _GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS * __ptr64) */

long __cdecl
GpioQueryActiveInterrupts(void *param_1,_GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS *param_2)

{
  ushort uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  ulonglong uVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  uVar5 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar4 = -0x3ffffff3;
  }
  else {
    uVar2 = *(ulong *)(param_2 + 8);
    uVar1 = *(ushort *)param_2;
    if (uVar2 != 0) {
      uVar3 = ControllerLibrary<CHTController>::ReadMultiplePinStatus
                        (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
      uVar5 = (ulonglong)uVar3;
    }
    *(ulonglong *)(param_2 + 0x10) = uVar5;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_DDxD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                    &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                    *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2,(char)uVar5);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
      }
    }
    lVar4 = 0;
  }
  return lVar4;
}



===== GpioQueryControllerInformation @ 140004fa0 =====

/* long __cdecl GpioQueryControllerInformation(void * __ptr64,struct
   _CLIENT_CONTROLLER_BASIC_INFORMATION * __ptr64) */

long __cdecl
GpioQueryControllerInformation(void *param_1,_CLIENT_CONTROLLER_BASIC_INFORMATION *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  _CLIENT_CONTROLLER_BASIC_INFORMATION *p_Var5;
  
  p_Var5 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    p_Var5 = (_CLIENT_CONTROLLER_BASIC_INFORMATION *)0x14;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  if (param_2 == (_CLIENT_CONTROLLER_BASIC_INFORMATION *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar3 = -0x3ffffff3;
  }
  else {
    *(undefined4 *)param_2 = 0x100001;
    *(undefined2 *)(param_2 + 4) = *(undefined2 *)(*(longlong *)param_1 + 0xc);
    param_2[6] = *(_CLIENT_CONTROLLER_BASIC_INFORMATION *)(*(longlong *)param_1 + 0x10);
    plVar1 = *(longlong **)param_1;
    pcVar2 = *(code **)(*plVar1 + 8);
    __empty_global_delete(pcVar2,(__uint64)p_Var5);
    uVar4 = (*pcVar2)(plVar1);
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xffffffe0 | uVar4 & 1 | 0x60;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== GpioReadGpioPins @ 1400050c0 =====

/* long __cdecl GpioReadGpioPins(void * __ptr64,struct _GPIO_READ_PINS_PARAMETERS * __ptr64) */

long __cdecl GpioReadGpioPins(void *param_1,_GPIO_READ_PINS_PARAMETERS *param_2)

{
  ushort uVar1;
  ulong uVar2;
  ushort *puVar3;
  byte bVar4;
  ulong uVar5;
  uint uVar6;
  byte bVar7;
  longlong lVar8;
  long lVar9;
  ulonglong uVar10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar9 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_READ_PINS_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar9 = -0x3ffffff3;
  }
  else {
    uVar1 = *(ushort *)param_2;
    puVar3 = *(ushort **)(param_2 + 8);
    uVar2 = *(ulong *)(param_2 + 0x10);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Dxxx(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                  &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                  *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2,0);
    }
    uVar5 = ControllerLibrary<CHTController>::ReadPins
                      (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,puVar3);
    lVar8 = *(longlong *)(param_2 + 0x18);
    uVar6 = uVar2 + 7 >> 3;
    if (uVar6 != 0) {
      bVar7 = 0;
      uVar10 = (ulonglong)uVar6;
      do {
        bVar4 = bVar7 & 0x1f;
        bVar7 = bVar7 + 8;
        *(bool *)lVar8 = uVar5 >> bVar4 != 0;
        lVar8 = lVar8 + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar9;
}



===== GpioReconfigureInterrupt @ 140005240 =====

/* long __cdecl GpioReconfigureInterrupt(void * __ptr64,struct
   _GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS * __ptr64) */

long __cdecl
GpioReconfigureInterrupt(void *param_1,_GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  _KINTERRUPT_MODE _Var3;
  _KINTERRUPT_POLARITY _Var4;
  uchar uVar5;
  ulonglong uVar6;
  long lVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar7 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      uVar6 = 0x2c;
LAB_1400053a7:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
  }
  else {
    uVar1 = *(ushort *)param_2;
    uVar2 = *(ushort *)(param_2 + 2);
    _Var3 = *(_KINTERRUPT_MODE *)(param_2 + 4);
    _Var4 = *(_KINTERRUPT_POLARITY *)(param_2 + 8);
    if (_Var4 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DDxDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                     &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                     *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2,(char)_Var3,
                     (char)_Var4);
      }
      uVar5 = ControllerLibrary<CHTController>::IsValidPinNumber
                        (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
      if (uVar5 != '\0') {
        ControllerLibrary<CHTController>::ConfigurePinDirection
                  (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,1);
        ControllerLibrary<CHTController>::ClearSinglePinStatus
                  (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
        ControllerLibrary<CHTController>::EnableEdgeorLevelPin
                  (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,_Var4,_Var3);
      }
      goto LAB_1400053bc;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar6 = 0x2d;
      goto LAB_1400053a7;
    }
  }
  lVar7 = -0x3ffffff3;
LAB_1400053bc:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar7;
}



===== GpioReleaseController @ 140005410 =====

/* long __cdecl GpioReleaseController(struct WDFDEVICE__ * __ptr64,void * __ptr64) */

long __cdecl GpioReleaseController(WDFDEVICE__ *param_1,void *param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  void *pvVar6;
  __uint64 _Var7;
  
  pvVar6 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pvVar6 = (void *)0x10;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  if (param_2 == (void *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar4 = -0x3ffffff3;
  }
  else {
    if (*(longlong *)((longlong)param_2 + 0x20) != 0) {
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x108);
      __empty_global_delete(pcVar2,(__uint64)pvVar6);
      uVar5 = (*pcVar2)(WdfDriverGlobals,param_1);
      DeRegisterOpRegionHandler(uVar5,*(undefined8 *)((longlong)param_2 + 0x20));
      *(undefined8 *)((longlong)param_2 + 0x20) = 0;
    }
    uVar1 = *(uint *)((longlong)param_2 + 0x18);
    _Var7 = (__uint64)uVar1;
    if (uVar1 != 0) {
      _Var7 = (__uint64)uVar1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
        _Var7 = (__uint64)*(uint *)((longlong)param_2 + 0x18);
      }
      MmUnmapIoSpace(*(undefined8 *)((longlong)param_2 + 0x10));
      *(undefined8 *)((longlong)param_2 + 0x10) = 0;
      *(undefined4 *)((longlong)param_2 + 0x18) = 0;
    }
    puVar3 = *(undefined8 **)param_2;
    if (puVar3 != (undefined8 *)0x0) {
      pcVar2 = *(code **)*puVar3;
      __empty_global_delete(pcVar2,_Var7);
      (*pcVar2)(puVar3,1);
      *(undefined8 *)param_2 = 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar4 = 0;
  }
  return lVar4;
}



===== GpioRestoreBankHardwareContext @ 1400055a0 =====

/* void __cdecl GpioRestoreBankHardwareContext(void * __ptr64,struct
   _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS * __ptr64) */

void __cdecl
GpioRestoreBankHardwareContext
          (void *param_1,_GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  if ((param_1 == (void *)0x0) ||
     (param_2 == (_GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *)0x0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar2 = 0x1b;
  }
  else {
    uVar1 = *(ushort *)param_2;
    CHTController::RestoreGPIOBankContext(*(CHTController **)param_1,uVar1);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                *(undefined4 *)((longlong)param_1 + 8),(char)uVar1);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
      return;
    }
    uVar2 = 0x1d;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
          &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  return;
}



===== GpioSaveBankHardwareContext @ 1400056a0 =====

/* void __cdecl GpioSaveBankHardwareContext(void * __ptr64,struct
   _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS * __ptr64) */

void __cdecl
GpioSaveBankHardwareContext
          (void *param_1,_GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ulonglong uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  if ((param_1 == (void *)0x0) ||
     (param_2 == (_GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *)0x0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar1 = 0x18;
  }
  else {
    CHTController::SaveGPIOBankContext(*(CHTController **)param_1,*(ushort *)param_2);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
      return;
    }
    uVar1 = 0x19;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
          &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  return;
}



===== GpioStartController @ 140005760 =====

/* long __cdecl GpioStartController(void * __ptr64,unsigned char,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl GpioStartController(void *param_1,uchar param_2,_WDF_POWER_DEVICE_STATE param_3)

{
  ushort uVar1;
  long lVar2;
  ushort uVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  uVar3 = 0;
  if (param_1 == (void *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar2 = -0x3ffffff3;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                *(undefined4 *)((longlong)param_1 + 8),param_2);
    }
    if (param_2 != '\0') {
      uVar1 = *(ushort *)(*(longlong *)param_1 + 0x14);
      for (; uVar3 < uVar1; uVar3 = uVar3 + 1) {
        CHTController::RestoreGPIOBankContext(*(CHTController **)param_1,uVar3);
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar2 = 0;
  }
  return lVar2;
}



===== GpioStopController @ 140005890 =====

/* long __cdecl GpioStopController(void * __ptr64,unsigned char,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl GpioStopController(void *param_1,uchar param_2,_WDF_POWER_DEVICE_STATE param_3)

{
  ushort uVar1;
  long lVar2;
  ushort uVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  uVar3 = 0;
  if (param_1 == (void *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar2 = -0x3ffffff3;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                *(undefined4 *)((longlong)param_1 + 8),param_2);
    }
    if (param_2 != '\0') {
      uVar1 = *(ushort *)(*(longlong *)param_1 + 0x14);
      for (; uVar3 < uVar1; uVar3 = uVar3 + 1) {
        CHTController::SaveGPIOBankContext(*(CHTController **)param_1,uVar3);
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar2 = 0;
  }
  return lVar2;
}



===== GpioUnmaskInterrupt @ 1400059c0 =====

/* long __cdecl GpioUnmaskInterrupt(void * __ptr64,struct _GPIO_ENABLE_INTERRUPT_PARAMETERS *
   __ptr64) */

long __cdecl GpioUnmaskInterrupt(void *param_1,_GPIO_ENABLE_INTERRUPT_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  _KINTERRUPT_MODE _Var3;
  _KINTERRUPT_POLARITY _Var4;
  long lVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar5 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_ENABLE_INTERRUPT_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar5 = -0x3ffffff3;
  }
  else {
    uVar1 = *(ushort *)param_2;
    uVar2 = *(ushort *)(param_2 + 2);
    _Var3 = *(_KINTERRUPT_MODE *)(param_2 + 8);
    _Var4 = *(_KINTERRUPT_POLARITY *)(param_2 + 0xc);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DDxDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                   &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                   *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2,(char)_Var3,
                   (char)_Var4);
    }
    ControllerLibrary<CHTController>::IsValidPinNumber
              (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
    ControllerLibrary<CHTController>::UnmaskEdgeorLevelPin
              (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,_Var4,_Var3);
    ControllerLibrary<CHTController>::ClearSinglePinStatus
              (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar5;
}



===== GpioWriteGpioPins @ 140005b40 =====

/* long __cdecl GpioWriteGpioPins(void * __ptr64,struct _GPIO_WRITE_PINS_PARAMETERS * __ptr64) */

long __cdecl GpioWriteGpioPins(void *param_1,_GPIO_WRITE_PINS_PARAMETERS *param_2)

{
  ushort uVar1;
  ulong uVar2;
  ushort *puVar3;
  ulong *puVar4;
  long lVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  lVar5 = 0;
  if ((param_1 == (void *)0x0) || (param_2 == (_GPIO_WRITE_PINS_PARAMETERS *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
              &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
    }
    lVar5 = -0x3ffffff3;
  }
  else {
    uVar1 = *(ushort *)param_2;
    puVar3 = *(ushort **)(param_2 + 8);
    uVar2 = *(ulong *)(param_2 + 0x10);
    puVar4 = *(ulong **)(param_2 + 0x18);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Dxxx(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
                  &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids,
                  *(undefined4 *)((longlong)param_1 + 8),(char)uVar1,(char)uVar2,(char)*puVar4);
    }
    ControllerLibrary<CHTController>::WritePins
              (*(ControllerLibrary<CHTController> **)param_1,uVar1,uVar2,puVar3,puVar4);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  return lVar5;
}



===== IsValidPinNumber @ 140005c94 =====

/* public: unsigned char __cdecl ControllerLibrary<class CHTController>::IsValidPinNumber(unsigned
   short,unsigned short) __ptr64 */

uchar __thiscall
ControllerLibrary<CHTController>::IsValidPinNumber
          (ControllerLibrary<CHTController> *this,ushort param_1,ushort param_2)

{
  code *pcVar1;
  char cVar2;
  undefined6 in_register_00000012;
  __uint64 _Var3;
  
  pcVar1 = *(code **)(*(longlong *)this + 0x10);
  __empty_global_delete(pcVar1,CONCAT62(in_register_00000012,param_1));
  _Var3 = (__uint64)param_1;
  cVar2 = (*pcVar1)(this,_Var3,param_2);
  if (cVar2 != '\0') {
    pcVar1 = *(code **)(*(longlong *)this + 0x18);
    __empty_global_delete(pcVar1,_Var3);
    cVar2 = (*pcVar1)(this,param_1,param_2);
    if (cVar2 == '\0') {
      return '\x01';
    }
  }
  return '\0';
}



===== MaskEdgeorLevelPins @ 140005d10 =====

/* public: void __cdecl ControllerLibrary<class CHTController>::MaskEdgeorLevelPins(unsigned
   short,unsigned long) __ptr64 */

void __thiscall
ControllerLibrary<CHTController>::MaskEdgeorLevelPins
          (ControllerLibrary<CHTController> *this,ushort param_1,ulong param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined6 in_register_00000012;
  __uint64 _Var3;
  ushort uVar4;
  
  _Var3 = CONCAT62(in_register_00000012,param_1);
  uVar4 = 0;
  if (*(int *)(this + 0x10) != 0) {
    uVar2 = 0;
    do {
      if ((param_2 >> (uVar2 & 0x1f) & 1) != 0) {
        pcVar1 = *(code **)(*(longlong *)this + 0x50);
        __empty_global_delete(pcVar1,_Var3);
        _Var3 = (__uint64)param_1;
        (*pcVar1)(this,_Var3,uVar4);
        pcVar1 = *(code **)(*(longlong *)this + 0x60);
        __empty_global_delete(pcVar1,_Var3);
        _Var3 = (__uint64)param_1;
        (*pcVar1)(this,_Var3,uVar4);
      }
      uVar4 = uVar4 + 1;
      uVar2 = (uint)uVar4;
    } while (uVar2 < *(uint *)(this + 0x10));
  }
  return;
}



===== ReadMultiplePinStatus @ 140005da4 =====

/* public: unsigned long __cdecl ControllerLibrary<class
   CHTController>::ReadMultiplePinStatus(unsigned short,unsigned long) __ptr64 */

ulong __thiscall
ControllerLibrary<CHTController>::ReadMultiplePinStatus
          (ControllerLibrary<CHTController> *this,ushort param_1,ulong param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined6 in_register_00000012;
  
  pcVar1 = *(code **)(*(longlong *)this + 0x90);
  __empty_global_delete(pcVar1,CONCAT62(in_register_00000012,param_1));
  uVar2 = (*pcVar1)(this,param_1,param_2);
  return uVar2 & param_2;
}



===== ReadPins @ 140005df8 =====

/* public: unsigned long __cdecl ControllerLibrary<class CHTController>::ReadPins(unsigned
   short,unsigned long,unsigned short * __ptr64) __ptr64 */

ulong __thiscall
ControllerLibrary<CHTController>::ReadPins
          (ControllerLibrary<CHTController> *this,ushort param_1,ulong param_2,ushort *param_3)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  __uint64 _Var4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  
  uVar6 = 0;
  uVar7 = 0;
  if (param_2 != 0) {
    uVar5 = 0;
    do {
      _Var4 = (__uint64)param_1;
      uVar1 = param_3[uVar7];
      IsValidPinNumber(this,param_1,uVar1);
      uVar5 = 1 << ((byte)uVar5 & 0x1f);
      pcVar2 = *(code **)(*(longlong *)this + 0x70);
      __empty_global_delete(pcVar2,_Var4);
      iVar3 = (*pcVar2)(this,param_1,uVar1);
      if (iVar3 == 0) {
        uVar6 = uVar6 & ~uVar5;
      }
      else {
        uVar6 = uVar6 | uVar5;
      }
      uVar7 = uVar7 + 1;
      uVar5 = (uint)uVar7;
    } while (uVar5 < param_2);
  }
  return uVar6;
}



===== UnmaskEdgeorLevelPin @ 140005eb4 =====

/* public: void __cdecl ControllerLibrary<class CHTController>::UnmaskEdgeorLevelPin(unsigned
   short,unsigned short,enum _KINTERRUPT_POLARITY,enum _KINTERRUPT_MODE) __ptr64 */

void __thiscall
ControllerLibrary<CHTController>::UnmaskEdgeorLevelPin
          (ControllerLibrary<CHTController> *this,ushort param_1,ushort param_2,
          _KINTERRUPT_POLARITY param_3,_KINTERRUPT_MODE param_4)

{
  undefined6 in_register_00000012;
  code *pcVar1;
  
  if (param_4 == 0) {
    pcVar1 = *(code **)(*(longlong *)this + 0x58);
  }
  else {
    if (param_4 != 1) {
      return;
    }
    pcVar1 = *(code **)(*(longlong *)this + 0x68);
  }
  __empty_global_delete(pcVar1,CONCAT62(in_register_00000012,param_1));
  (*pcVar1)(this,param_1,param_2,param_3);
  return;
}



===== WritePins @ 140005f30 =====

/* public: void __cdecl ControllerLibrary<class CHTController>::WritePins(unsigned short,unsigned
   long,unsigned short * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
ControllerLibrary<CHTController>::WritePins
          (ControllerLibrary<CHTController> *this,ushort param_1,ulong param_2,ushort *param_3,
          ulong *param_4)

{
  uint uVar1;
  code *pcVar2;
  __uint64 _Var3;
  uint uVar4;
  ushort uVar5;
  ulonglong uVar6;
  
  if (param_2 != 0) {
    uVar6 = 0;
    uVar4 = 0;
    do {
      _Var3 = (__uint64)param_1;
      uVar5 = param_3[uVar6];
      IsValidPinNumber(this,param_1,uVar5);
      uVar1 = *param_4;
      pcVar2 = *(code **)(*(longlong *)this + 0x78);
      __empty_global_delete(pcVar2,_Var3);
      (*pcVar2)(this,param_1,uVar5,1 << ((byte)uVar4 & 0x1f) & uVar1);
      uVar5 = (short)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
      uVar4 = (uint)uVar5;
    } while (uVar4 < param_2);
  }
  return;
}



===== PrepareGpioRegistrationPacket @ 140005fe4 =====

void PrepareGpioRegistrationPacket(undefined4 *param_1)

{
  ulonglong uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
            &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  }
  if (param_1 == (undefined4 *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar1 = 0x59;
  }
  else {
    memset(param_1,0,0xd8);
    *param_1 = 0xd80003;
    *(code **)(param_1 + 6) = GpioPrepareController;
    *(code **)(param_1 + 0xe) = GpioQueryControllerInformation;
    *(code **)(param_1 + 10) = GpioStartController;
    *(code **)(param_1 + 0xc) = GpioStopController;
    *(code **)(param_1 + 8) = GpioReleaseController;
    *(code **)(param_1 + 0x26) = GpioSaveBankHardwareContext;
    *(code **)(param_1 + 0x28) = GpioRestoreBankHardwareContext;
    *(code **)(param_1 + 0x14) = GpioDisableInterrupt;
    *(code **)(param_1 + 0x12) = GpioEnableInterrupt;
    *(code **)(param_1 + 0x18) = GpioMaskInterrupts;
    *(code **)(param_1 + 0x16) = GpioUnmaskInterrupt;
    *(code **)(param_1 + 0x1c) = GpioClearActiveInterrupts;
    *(code **)(param_1 + 0x1a) = GpioQueryActiveInterrupts;
    *(code **)(param_1 + 0x2e) = GpioReconfigureInterrupt;
    *(code **)(param_1 + 0x1e) = GpioConnectIoPins;
    *(code **)(param_1 + 0x20) = GpioDisconnectIoPins;
    *(code **)(param_1 + 0x22) = GpioReadGpioPins;
    *(code **)(param_1 + 0x24) = GpioWriteGpioPins;
    param_1[2] = 0x28;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
      return;
    }
    uVar1 = 0x5a;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
          &WPP_ca7dc9d8619736c45bc802ca73f1b918_Traceguids);
  return;
}



===== WPP_SF_DDx @ 140006194 =====

void WPP_SF_DDx(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_DDxD @ 140006230 =====

void WPP_SF_DDxD(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_DDxDD @ 1400062dc =====

void WPP_SF_DDxDD(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,4,&param_6,8,&param_7,4,
            &param_8,4,0);
  return;
}



===== WPP_SF_Dxx @ 1400063a0 =====

void WPP_SF_Dxx(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_Dxxd @ 14000643c =====

void WPP_SF_Dxxd(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_Dxxx @ 1400064e8 =====

void WPP_SF_Dxxx(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  undefined4 local_res20 [2];
  
  pcVar1 = pfnWppTraceMessage;
  local_res20[0] = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,local_res20,4,&param_5,8,&param_6,8,&param_7,8,0);
  return;
}



===== __security_check_cookie @ 1400065b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 1400065d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 1400065e0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140006600 =====

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



===== _purecall @ 140006660 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140006660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== FxStubDriverUnloadCommon @ 140006670 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140008510);
  WdfVersionUnbind(&DAT_140008618,&DAT_140008510,WdfDriverGlobals);
  return;
}



===== entry @ 1400066a0 =====

void entry(__uint64 param_1,__uint64 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1400066cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(__uint64 param_1,__uint64 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_140008620 = &DAT_140008650;
    _DAT_140008618 = 0x2080000;
    _DAT_140008640 = param_1;
    RtlCopyUnicodeString(&DAT_140008618);
    iVar1 = WdfVersionBind(param_1,&DAT_140008618,&DAT_140008510,&WdfDriverGlobals);
    if (-1 < iVar1) {
      _WdfDriverMiniportUnloadOverride = *(code **)(WdfFunctions_01015 + 0x648);
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_140008510);
      if (((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) &&
         (iVar1 = DriverEntry(param_1,param_2), -1 < iVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _WdfDriverMiniportUnloadOverride = FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_140008628 = *(longlong *)(param_1 + 0x68);
          }
          *(code **)(param_1 + 0x68) = FxStubDriverUnload;
        }
        return 0;
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverMiniportUnload @ 140006800 =====

void __cdecl FxStubDriverMiniportUnload(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140008510);
  WdfVersionUnbind(&DAT_140008618,&DAT_140008510,WdfDriverGlobals);
  return;
}



===== FxStubDriverUnload @ 140006810 =====

void FxStubDriverUnload(undefined8 param_1,__uint64 param_2)

{
  code *pcVar1;
  
  pcVar1 = DAT_140008628;
  if ((DAT_140008628 != (code *)0x0) && (DAT_140008628 != FxStubDriverUnload)) {
    __empty_global_delete(DAT_140008628,param_2);
    (*pcVar1)(param_1);
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 140006854 =====

/* WARNING: Removing unreachable block (ram,0x000140006889) */
/* WARNING: Removing unreachable block (ram,0x000140006890) */
/* WARNING: Removing unreachable block (ram,0x0001400068cc) */
/* WARNING: Removing unreachable block (ram,0x000140006896) */
/* WARNING: Removing unreachable block (ram,0x00014000689e) */
/* WARNING: Removing unreachable block (ram,0x0001400068ad) */
/* WARNING: Removing unreachable block (ram,0x000140006876) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  return 0;
}



===== FxStubBindClasses @ 1400068d4 =====

/* WARNING: Removing unreachable block (ram,0x000140006900) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  code *pcVar1;
  int iVar2;
  _WDF_BIND_INFO *in_RDX;
  int *piVar3;
  
  iVar2 = 0;
  piVar3 = &_GPIOClx_BIND_INFO;
  while( true ) {
    if ((int *)0x14000859f < piVar3) {
      return iVar2;
    }
    if (*piVar3 != 0x50) break;
    pcVar1 = *(code **)(piVar3 + 0xe);
    PTR___KMDF_CLASS_BIND_START_1400085a8 = (undefined *)piVar3;
    if (pcVar1 == (code *)0x0) {
      in_RDX = WdfDriverGlobals;
      iVar2 = WdfVersionBindClass(param_1,WdfDriverGlobals,piVar3);
    }
    else {
      __empty_global_delete(pcVar1,(__uint64)in_RDX);
      in_RDX = param_1;
      iVar2 = (*pcVar1)(WdfVersionBindClass,param_1,WdfDriverGlobals,piVar3);
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    piVar3 = piVar3 + 0x14;
  }
  return -0x3ffffffc;
}



===== FxStubUnbindClasses @ 140006980 =====

/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  code *pcVar1;
  _WDF_BIND_INFO *in_RDX;
  undefined4 *puVar2;
  
  puVar2 = &_GPIOClx_BIND_INFO;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400085a8 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x14000854f < PTR___KMDF_CLASS_BIND_START_1400085a8)) {
    do {
      pcVar1 = *(code **)(puVar2 + 0x10);
      if (pcVar1 == (code *)0x0) {
        in_RDX = WdfDriverGlobals;
        WdfVersionUnbindClass(param_1,WdfDriverGlobals,puVar2);
      }
      else {
        __empty_global_delete(pcVar1,(__uint64)in_RDX);
        in_RDX = param_1;
        (*pcVar1)(WdfVersionUnbindClass,param_1,WdfDriverGlobals,puVar2);
      }
      puVar2 = puVar2 + 0x14;
    } while (puVar2 <= PTR___KMDF_CLASS_BIND_START_1400085a8);
  }
  return;
}



===== RegisterOpRegionHandler @ 140006a0a =====

void RegisterOpRegionHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140006a0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RegisterOpRegionHandler();
  return;
}



===== DeRegisterOpRegionHandler @ 140006a10 =====

void DeRegisterOpRegionHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140006a10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DeRegisterOpRegionHandler();
  return;
}



===== WdfVersionBind @ 140006a16 =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140006a16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 140006a1c =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140006a1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 140006a30 =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140006a30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 140006a40 =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140006a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== _guard_dispatch_icall @ 140006a60 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140006a60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memset @ 140006a80 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (_Size < 8) {
    for (uVar4 = _Size & 7; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)((longlong)_Dst + (uVar4 - 1)) = (char)_Val;
    }
    return _Dst;
  }
  lVar3 = ((ulonglong)(uint)_Val & 0xff) * 0x101010101010101;
  if (_Size < 0x4f) {
    uVar4 = _Size & 0xfffffffffffffff8;
    do {
      *(longlong *)((longlong)_Dst + (uVar4 - 8)) = lVar3;
      uVar4 = uVar4 - 8;
    } while (uVar4 != 0);
    if ((_Size & 7) != 0) {
      *(longlong *)((longlong)_Dst + (_Size & 7) + ((_Size & 0xfffffffffffffff8) - 8)) = lVar3;
    }
    return _Dst;
  }
  *(longlong *)_Dst = lVar3;
  *(longlong *)((longlong)_Dst + 8) = lVar3;
  plVar1 = (longlong *)((longlong)_Dst + 0x10U & 0xfffffffffffffff0);
  uVar4 = (longlong)_Dst + (_Size - (longlong)plVar1);
  uVar5 = uVar4 >> 7;
  plVar2 = plVar1;
  if (uVar5 != 0) {
    do {
      *plVar2 = lVar3;
      plVar2[1] = lVar3;
      plVar2[2] = lVar3;
      plVar2[3] = lVar3;
      plVar1 = plVar2 + 0x10;
      plVar2[4] = lVar3;
      plVar2[5] = lVar3;
      plVar2[6] = lVar3;
      plVar2[7] = lVar3;
      uVar5 = uVar5 - 1;
      plVar2[8] = lVar3;
      plVar2[9] = lVar3;
      plVar2[10] = lVar3;
      plVar2[0xb] = lVar3;
      plVar2[0xc] = lVar3;
      plVar2[0xd] = lVar3;
      plVar2[0xe] = lVar3;
      plVar2[0xf] = lVar3;
      plVar2 = plVar1;
    } while (uVar5 != 0);
    uVar4 = uVar4 & 0x7f;
  }
  for (uVar5 = uVar4 >> 4; uVar5 != 0; uVar5 = uVar5 - 1) {
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
    plVar1 = plVar1 + 2;
  }
  if ((uVar4 & 0xf) != 0) {
    plVar1 = (longlong *)((longlong)plVar1 + ((uVar4 & 0xf) - 0x10));
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
  }
  return _Dst;
}



===== memmove @ 140006b80 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar11 = (longlong)_Src - (longlong)_Dst;
  if (_Src < _Dst) {
    puVar9 = (undefined8 *)((longlong)_Dst + _Size);
    if (0x4e < _Size) {
      if (uVar11 < 0xfffffffffffffff1) {
        uVar12 = (ulonglong)((uint)puVar9 & 0xf);
        if (((ulonglong)puVar9 & 0xf) != 0) {
          _Size = _Size - uVar12;
          uVar12 = -uVar12;
          puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 0x10));
          uVar4 = puVar10[1];
          puVar9[-2] = *puVar10;
          puVar9[-1] = uVar4;
        }
        puVar9 = (undefined8 *)(uVar12 + (longlong)puVar9);
      }
      else {
        while (((ulonglong)puVar9 & 0xf) != 0) {
          puVar9 = (undefined8 *)((longlong)puVar9 + -1);
          _Size = _Size - 1;
          *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
        }
      }
      uVar12 = _Size >> 5;
      if ((0x2000 < uVar12) && (uVar11 < 0xfffffffffffffe01)) {
        do {
          iVar7 = 4;
          do {
            puVar10 = puVar9;
            iVar7 = iVar7 + -1;
            puVar9 = puVar10 + -0x10;
          } while (iVar7 != 0);
          iVar7 = 8;
          puVar10 = puVar10 + 0x30;
          do {
            puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x30));
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)((longlong)puVar9 + uVar11);
            uVar6 = ((undefined8 *)((longlong)puVar9 + uVar11))[1];
            puVar10[-6] = *puVar1;
            puVar10[-5] = uVar4;
            *puVar9 = uVar5;
            puVar10[-7] = uVar6;
            iVar7 = iVar7 + -1;
            puVar10 = puVar9;
          } while (iVar7 != 0);
          _Size = _Size - 0x200;
        } while (0x1ff < _Size);
        LOCK();
        UNLOCK();
        uVar12 = _Size >> 5;
        if (uVar12 == 0) goto LAB_140006d37;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = puVar10 + -4;
        puVar10[-2] = *puVar1;
        puVar10[-1] = uVar4;
        *puVar9 = uVar5;
        puVar10[-3] = uVar6;
        uVar12 = uVar12 - 1;
        puVar10 = puVar9;
      } while (uVar12 != 0);
    }
LAB_140006d37:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 8));
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((longlong)puVar9 + (uVar11 - 1));
      puVar9 = (undefined8 *)((longlong)puVar9 + -1);
      *(undefined1 *)puVar9 = *puVar3;
    }
    return _Dst;
  }
  puVar9 = _Dst;
  if (0x4e < _Size) {
    if (uVar11 < 0x10) {
      for (; ((ulonglong)puVar9 & 0xf) != 0; puVar9 = (undefined8 *)((longlong)puVar9 + 1)) {
        _Size = _Size - 1;
        *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)((longlong)_Dst + uVar11))[1];
        *(undefined8 *)_Dst = *(undefined8 *)((longlong)_Dst + uVar11);
        *(undefined8 *)((longlong)_Dst + 8) = uVar4;
      }
      puVar9 = (undefined8 *)((ulonglong)uVar8 + (longlong)_Dst);
    }
    uVar12 = _Size >> 5;
    if ((0x2000 < uVar12) && (0x1ff < uVar11)) {
      do {
        iVar7 = 4;
        do {
          puVar10 = puVar9;
          iVar7 = iVar7 + -1;
          puVar9 = puVar10 + 0x10;
        } while (iVar7 != 0);
        iVar7 = 8;
        puVar10 = puVar10 + -0x30;
        do {
          uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
          puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x20);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x30);
          uVar5 = *puVar2;
          uVar6 = puVar2[1];
          puVar10[4] = *puVar1;
          puVar10[5] = uVar4;
          puVar10[6] = uVar5;
          puVar10[7] = uVar6;
          iVar7 = iVar7 + -1;
          puVar10 = puVar9;
        } while (iVar7 != 0);
        _Size = _Size - 0x200;
      } while (0x1ff < _Size);
      LOCK();
      UNLOCK();
      uVar12 = _Size >> 5;
      if (uVar12 == 0) goto LAB_140006b92;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
      puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_140006b92:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)((longlong)puVar9 + uVar11);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== WppCleanupKm @ 14000a000 =====

void WppCleanupKm(undefined8 param_1,__uint64 param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined *puVar3;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar3 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; pcVar2 = pfnEtwUnregister, puVar3 != (undefined *)0x0;
          puVar3 = *(undefined **)(puVar3 + 0x10)) {
        lVar1 = *(longlong *)(puVar3 + 0x38);
        if (lVar1 != 0) {
          __empty_global_delete(pfnEtwUnregister,param_2);
          (*pcVar2)(lVar1);
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



===== WppInitKm @ 14000a08c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,__uint64 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      do {
        *(undefined8 *)(puVar2 + 0x38) = 0;
        pcVar1 = pfnEtwRegisterClassicProvider;
        __empty_global_delete(pfnEtwRegisterClassicProvider,param_2);
        param_2 = 0;
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



===== WppLoadTracingSupport @ 14000a128 =====

void WppLoadTracingSupport(void)

{
  code *pcVar1;
  wchar_t *pwVar2;
  uint local_res8 [2];
  undefined1 local_18 [16];
  
  local_res8[0] = 0;
  RtlInitUnicodeString(local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(local_18);
  pwVar2 = L"WmiQueryTraceInformation";
  RtlInitUnicodeString(local_18);
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(local_18);
  pcVar1 = pfnWppGetVersion;
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    __empty_global_delete(pfnWppGetVersion,(__uint64)pwVar2);
    (*pcVar1)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 14000a230 =====

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  undefined1 local_res8 [8];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar9 = param_6;
  *param_6 = 0;
  if (3 < param_1) {
    if (param_1 < 6) {
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar9 = param_4 + 6;
          lVar7 = RtlCompareMemory(*(undefined8 *)(param_5 + 8),puVar9,0x10);
          if (lVar7 == 0x10) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined1 *)(param_5 + 0x29) = 0;
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            return 0;
          }
          uVar2 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar2;
          pcVar4 = pfnWppQueryTraceInformation;
          if (WPPTraceSuite != 2) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          __empty_global_delete(pfnWppQueryTraceInformation,(__uint64)puVar9);
          puVar10 = local_res8;
          iVar5 = (*pcVar4)(3,puVar10,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = local_res8[0];
          }
          pcVar4 = pfnWppQueryTraceInformation;
          __empty_global_delete(pfnWppQueryTraceInformation,(__uint64)puVar10);
          uVar6 = (*pcVar4)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
    if (param_1 < 8) {
      return 0;
    }
    if (param_1 == 8) {
      uVar11 = 0;
      puVar1 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar11 = uVar11 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar11) {
        return 0xc000000d;
      }
      uVar12 = uVar11 * 0x20 + 0x18;
      if (puVar1 == (ushort *)0x0) {
        uVar13 = uVar12;
        uVar12 = 0;
      }
      else {
        uVar13 = *puVar1 + 2 + uVar12;
      }
      if (param_3 < uVar13) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar13;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar13;
      param_4[2] = uVar12;
      param_4[4] = uVar11;
      if (puVar1 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar12 + (longlong)param_4) = *puVar1;
        memmove((ushort *)((ulonglong)uVar12 + (longlong)param_4) + 1,*(void **)(puVar1 + 4),
                (ulonglong)*puVar1);
      }
      if (uVar11 != 0) {
        uVar8 = (ulonglong)uVar11;
        puVar14 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar14 = 0x81000;
          *(undefined8 *)(puVar14 + -4) = uVar2;
          *(undefined8 *)(puVar14 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar14 = puVar14 + 8;
        } while (uVar8 != 0);
      }
      *puVar9 = uVar13;
      return 0;
    }
  }
  return 0xc0000010;
}



===== __security_init_cookie @ 14000b000 =====

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


