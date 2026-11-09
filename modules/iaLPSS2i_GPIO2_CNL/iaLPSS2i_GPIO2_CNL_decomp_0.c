
===== GpioEvtDeviceAdd @ 140001000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GpioEvtDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl GpioEvtDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  code *pcVar1;
  int iVar2;
  _GPIO_DRIVER_CONTEXT *p_Var3;
  undefined *puVar4;
  WDFDEVICE_INIT *pWVar5;
  uint *puVar6;
  WDFDEVICE_INIT **ppWVar7;
  __uint64 _Var8;
  undefined1 auStack_c8 [32];
  __uint64 local_a8;
  WDFDEVICE_INIT *local_a0;
  undefined1 local_98 [56];
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined local_40 [16];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a0 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_65c69ccb7a023e5cc889e325d9af8907_Traceguids);
  }
  puVar4 = local_40;
  EtwActivityIdControl(3);
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    puVar4 = &EvtDeviceAdd_Start;
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtDeviceAdd_Start,local_40)
    ;
  }
  pcVar1 = DAT_140016470;
  __empty_global_delete(DAT_140016470,(__uint64)puVar4);
  pWVar5 = local_a0;
  iVar2 = (*pcVar1)(param_1,local_a0,local_98);
  if (iVar2 < 0) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) == 0) goto LAB_140001236;
    puVar6 = (uint *)&EvtDeviceGpioProcessAddPre_Error;
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 600);
    __empty_global_delete(pcVar1,(__uint64)pWVar5);
    ppWVar7 = &local_a0;
    iVar2 = (*pcVar1)(WdfDriverGlobals,ppWVar7,local_98,&local_a8);
    pcVar1 = DAT_140016478;
    if (iVar2 < 0) {
      if ((Intel_iaLPSS2_GPIO2EnableBits & 1) == 0) goto LAB_140001236;
      puVar6 = (uint *)&EvtDeviceCreate_Error;
    }
    else {
      __empty_global_delete(DAT_140016478,(__uint64)ppWVar7);
      _Var8 = local_a8;
      iVar2 = (*pcVar1)(param_1);
      if (-1 < iVar2) {
        local_50 = 0;
        local_58 = 0x200000002;
        uStack_4c = 2;
        local_48 = 2;
        local_60 = 0x20000001c;
        pcVar1 = *(code **)(WdfFunctions_01015 + 0xe8);
        __empty_global_delete(pcVar1,_Var8);
        _Var8 = local_a8;
        (*pcVar1)(WdfDriverGlobals,local_a8,&local_60);
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x260);
        __empty_global_delete(pcVar1,_Var8);
        _Var8 = local_a8;
        (*pcVar1)(WdfDriverGlobals,local_a8,0);
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
        __empty_global_delete(pcVar1,_Var8);
        p_Var3 = (_GPIO_DRIVER_CONTEXT *)
                 (*pcVar1)(WdfDriverGlobals,param_1,PTR__WDF_GPIO_DRIVER_CONTEXT_TYPE_INFO_140016060
                          );
        *(__uint64 *)(p_Var3 + 0x10) = local_a8;
        SetDefaultSettings(p_Var3);
        GetRegistrySettings(p_Var3);
        goto LAB_140001236;
      }
      if ((Intel_iaLPSS2_GPIO2EnableBits & 1) == 0) goto LAB_140001236;
      puVar6 = (uint *)&EvtDeviceGpioProcessAddPost_Error;
    }
  }
  McTemplateK0q((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,puVar6,local_40,iVar2);
LAB_140001236:
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtDeviceAdd_End,local_40);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_65c69ccb7a023e5cc889e325d9af8907_Traceguids,iVar2);
  }
  return iVar2;
}



===== GpioEvtDriverUnload @ 1400012b0 =====

/* void __cdecl GpioEvtDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl GpioEvtDriverUnload(WDFDRIVER__ *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined *in_RDX;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_RDX = (undefined *)0xc;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_65c69ccb7a023e5cc889e325d9af8907_Traceguids);
  }
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    in_RDX = &EvtDriverUnload_Start;
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtDriverUnload_Start,0);
  }
  pcVar1 = DAT_140016468;
  __empty_global_delete(DAT_140016468,(__uint64)in_RDX);
  iVar2 = (*pcVar1)(param_1);
  if ((iVar2 < 0) && ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0)) {
    in_RDX = &EvtDriverGpioClxUnregister_Error;
    McTemplateK0q((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                  (uint *)&EvtDriverGpioClxUnregister_Error,0,iVar2);
  }
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    in_RDX = &EvtDriverUnload_End;
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtDriverUnload_End,0);
  }
  McGenEventUnregister((longlong *)&iaLPSS2_GPIO2_PROVIDER_Context);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_RDX = (undefined *)0xd;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_65c69ccb7a023e5cc889e325d9af8907_Traceguids,iVar2);
  }
  WppCleanupKm(param_1,(__uint64)in_RDX);
  return;
}



===== DriverEntry @ 1400013cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined4 *param_1,__uint64 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  __uint64 _Var4;
  undefined4 *puVar5;
  undefined8 local_res18 [2];
  undefined4 local_168 [2];
  code *local_160;
  code *local_158;
  undefined4 local_148 [2];
  undefined4 local_140;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_98;
  code *local_90;
  code *local_88;
  undefined4 local_68 [6];
  undefined4 local_50;
  undefined4 local_4c;
  undefined *local_38;
  
  _DAT_1400161e8 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1400161c8 = &WPP_ThisDir_CTLGUID_iaLPSS_GPIOTraceGuid;
  DAT_1400161d0 = 0;
  _DAT_1400161e0 = 0;
  WppLoadTracingSupport();
  _DAT_1400161e0 = 0;
  WppInitKm(param_1,param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_65c69ccb7a023e5cc889e325d9af8907_Traceguids);
  }
  McGenEventRegister();
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtDriverEntry_Start,0);
  }
  memset(local_168,0,0x20);
  local_168[0] = 0x20;
  local_160 = GpioEvtDeviceAdd;
  local_158 = GpioEvtDriverUnload;
  _Var4 = 0;
  memset(local_68,0,0x38);
  local_38 = PTR__WDF_GPIO_DRIVER_CONTEXT_TYPE_INFO_140016060;
  local_68[0] = 0x38;
  local_50 = 1;
  local_4c = 1;
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x3a0);
  __empty_global_delete(pcVar1,_Var4);
  puVar5 = param_1;
  iVar2 = (*pcVar1)(WdfDriverGlobals,param_1,param_2,local_68,local_168,local_res18);
  if (iVar2 < 0) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      puVar5 = (undefined4 *)&EvtDriverCreate_Error;
      McTemplateK0q((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtDriverCreate_Error,0,
                    iVar2);
    }
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x650);
    __empty_global_delete(pcVar1,(__uint64)puVar5);
    uVar3 = (*pcVar1)(WdfDriverGlobals,local_res18[0],
                      PTR__WDF_GPIO_DRIVER_CONTEXT_TYPE_INFO_140016060);
    KeInitializeSpinLock(uVar3);
    _Var4 = 0;
    memset(local_148,0,0xd8);
    pcVar1 = GpioClxExportedInterfaces;
    local_130 = GpioPrepareController;
    local_148[0] = 0xd80003;
    local_110 = GpioQueryControllerBasicInformation;
    local_120 = GpioStartController;
    local_118 = GpioStopController;
    local_128 = GpioReleaseController;
    local_98 = GpioControllerSpecificFunction;
    local_f8 = GpioDisableInterrupt;
    local_100 = GpioEnableInterrupt;
    local_e8 = GpioMaskInterrupts;
    local_f0 = GpioUnmaskInterrupt;
    local_d8 = GpioClearActiveInterrupts;
    local_e0 = GpioQueryActiveInterrupts;
    local_88 = GpioQueryEnabledInterrupts;
    local_90 = GpioReconfigureInterrupt;
    local_d0 = GpioConnectIoPins;
    local_c8 = GpioDisconnectIoPins;
    local_c0 = GpioReadGpioPins;
    local_b8 = GpioWriteGpioPins;
    local_b0 = GpioSaveBankHardwareContext;
    local_a8 = GpioRestoreBankHardwareContext;
    local_140 = 0x38;
    __empty_global_delete(GpioClxExportedInterfaces,_Var4);
    puVar5 = local_148;
    iVar2 = (*pcVar1)(local_res18[0]);
    if ((iVar2 < 0) && ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0)) {
      puVar5 = (undefined4 *)&EvtDriverGpioClxRegister_Error;
      McTemplateK0q((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                    (uint *)&EvtDriverGpioClxRegister_Error,0,iVar2);
    }
  }
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    puVar5 = (undefined4 *)&EvtDriverEntry_End;
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtDriverEntry_End,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar5 = (undefined4 *)0xb;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_65c69ccb7a023e5cc889e325d9af8907_Traceguids,iVar2);
  }
  if (iVar2 < 0) {
    McGenEventUnregister((longlong *)&iaLPSS2_GPIO2_PROVIDER_Context);
    WppCleanupKm(param_1,(__uint64)puVar5);
  }
  return iVar2;
}



===== McGenControlCallbackV2 @ 140001780 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar5 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          if (((*(byte *)(param_7 + 0x28) <
                *(byte *)((ulonglong)uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar3 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + (ulonglong)uVar7 * 8),
              uVar3 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar3) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar3) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          uVar6 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (ulonglong)(uVar7 >> 5) * 4);
          uVar2 = *puVar1;
          if (bVar4) {
            uVar6 = uVar6 | uVar2;
          }
          else {
            uVar6 = ~uVar6 & uVar2;
          }
          *puVar1 = uVar6;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(param_7 + 0x2a));
        return;
      }
    }
  }
  return;
}



===== McGenEventRegister @ 140001888 =====

undefined8 McGenEventRegister(void)

{
  undefined8 uVar1;
  longlong *in_R9;
  
  if (*in_R9 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000140001891. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = EtwRegister();
    return uVar1;
  }
  return 0;
}



===== McGenEventUnregister @ 140001898 =====

undefined8 McGenEventUnregister(longlong *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    *param_1 = 0;
  }
  return uVar1;
}



===== McGenEventWriteKM @ 1400018c0 =====

void McGenEventWriteKM(undefined8 *param_1,uint *param_2,undefined8 param_3,ulonglong param_4,
                      undefined8 *param_5)

{
  ushort *puVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
  puVar1 = (ushort *)param_1[1];
  cVar3 = '\0';
  if (puVar1 == (ushort *)0x0) {
    uVar4 = (int)param_4 - 1;
    param_4 = (ulonglong)uVar4;
    cVar3 = '\f';
    param_5 = (undefined8 *)(-(ulonglong)(uVar4 != 0) & (ulonglong)(param_5 + 2));
  }
  else {
    *param_5 = puVar1;
    *(uint *)(param_5 + 1) = (uint)*puVar1;
    *(undefined4 *)((longlong)param_5 + 0xc) = 2;
  }
  if (*(char *)((longlong)param_2 + 3) == cVar3) {
    uVar2 = *(undefined8 *)param_2;
    uStack_10 = *(undefined8 *)(param_2 + 2);
    param_2 = (uint *)&local_18;
    local_18._4_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
    local_18._0_3_ = (undefined3)uVar2;
    local_18 = CONCAT44(local_18._4_4_,CONCAT13(-(puVar1 != (ushort *)0x0),(undefined3)local_18)) &
               0xffffffff0cffffff;
  }
  EtwWrite(*param_1,param_2,param_3,param_4,param_5);
  return;
}



===== McTemplateK0 @ 140001948 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0(undefined8 *param_1,uint *param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWriteKM(param_1,param_2,param_3,1,local_28);
  return;
}



===== McTemplateK0q @ 140001984 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWriteKM(param_1,param_2,param_3,2,local_38);
  return;
}



===== WPP_SF_ @ 1400019d8 =====

void WPP_SF_(undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  code *pcVar1;
  
  pcVar1 = pfnWppTraceMessage;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,0);
  return;
}



===== WPP_SF_D @ 140001a30 =====

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



===== WppClassicProviderCallback @ 140001aa0 =====

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



===== CheckSupportedHardware @ 140001ad0 =====

/* long __cdecl CheckSupportedHardware(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64)
    */

long __cdecl CheckSupportedHardware(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  HW_PARAMETERS *pHVar1;
  long lVar2;
  int iVar3;
  ulonglong uVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_87a99f410be63a0c389337ae59f59430_Traceguids);
  }
  pHVar1 = param_2 + 8;
  *(undefined4 *)(param_2 + 4) = 0xff;
  *(ulong *)pHVar1 = 0xff;
  *(undefined4 *)param_2 = 0xff;
  *(undefined4 *)(param_2 + 0xc) = 0xff;
  lVar2 = GetHardwareVersion(param_1,param_2);
  if (lVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140001ccf;
    uVar4 = 0xf;
  }
  else {
    iVar3 = *(int *)(param_2 + 0xc);
    if (iVar3 == 0xff) {
      lVar2 = -0x3ffffda0;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffda0;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_140001ccf;
      uVar4 = 0x10;
    }
    else {
      if (*(ulong *)pHVar1 == 0xff) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_87a99f410be63a0c389337ae59f59430_Traceguids);
          iVar3 = *(int *)(param_2 + 0xc);
        }
        lVar2 = 0;
        if (iVar3 == 0) {
          lVar2 = GetAcpiHardwareRevision(param_1,(ulong *)pHVar1);
        }
        else if (iVar3 == 1) {
          lVar2 = -0x3fffffff;
        }
        if (lVar2 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar2;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140001ccf;
          uVar4 = 0x12;
          goto LAB_140001cc3;
        }
      }
      if (*(int *)param_2 != 0xff) goto LAB_140001ccf;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_87a99f410be63a0c389337ae59f59430_Traceguids);
      }
      lVar2 = 0;
      if (*(int *)(param_2 + 0xc) == 0) {
        lVar2 = GetAcpiHardwareInstance(param_1,(ulong *)param_2);
      }
      else if (*(int *)(param_2 + 0xc) == 1) {
        lVar2 = -0x3fffffff;
      }
      if (-1 < lVar2) goto LAB_140001ccf;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return lVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_140001ccf;
      uVar4 = 0x14;
    }
  }
LAB_140001cc3:
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
          &WPP_87a99f410be63a0c389337ae59f59430_Traceguids);
LAB_140001ccf:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_87a99f410be63a0c389337ae59f59430_Traceguids,lVar2);
  }
  return lVar2;
}



===== GetHardwareVersion @ 140001d20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetHardwareVersion(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareVersion(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  wchar_t *pwVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  wchar_t *_Src;
  size_t sVar5;
  ulonglong uVar6;
  __uint64 _Var7;
  WDFDEVICE__ *pWVar8;
  wchar_t *_Str2;
  uint uVar9;
  __uint64 _MaxCount;
  undefined **ppuVar10;
  undefined1 auStack_268 [32];
  __uint64 local_238;
  ulonglong local_228;
  undefined4 local_220 [6];
  undefined4 local_208;
  undefined4 local_204;
  WDFDEVICE__ *local_200;
  undefined4 local_1e8 [2];
  undefined *local_1e0;
  undefined8 local_1d8;
  undefined4 local_1d0 [4];
  undefined1 *local_1c0;
  undefined8 local_1b8;
  undefined4 local_1b0;
  undefined4 local_1a8;
  undefined1 *local_1a0;
  undefined4 local_198;
  undefined8 local_194;
  undefined4 local_188;
  undefined1 *local_180;
  undefined4 local_178;
  undefined8 local_174;
  undefined4 local_168;
  undefined1 *local_160;
  undefined4 local_158;
  undefined8 local_154;
  undefined4 local_148;
  undefined1 *local_140;
  undefined4 local_138;
  undefined8 local_134;
  undefined4 local_128;
  undefined1 *local_120;
  undefined4 local_118;
  undefined8 local_114;
  undefined4 local_108;
  undefined1 *local_100;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined4 local_e8;
  undefined1 *local_e0;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  undefined1 *local_c0;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined4 local_a8;
  undefined1 *local_a0;
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_88;
  undefined1 *local_80;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_68;
  undefined1 *local_60;
  undefined4 local_58;
  undefined8 local_54;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_268;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_87a99f410be63a0c389337ae59f59430_Traceguids);
  }
  local_d8 = 10;
  local_1e0 = &u_ACPI_INT344B;
  ppuVar10 = &local_1e0;
  local_1e8[0] = 1;
  local_1c0 = &u_ACPI_INT345D;
  local_1d8 = 2;
  local_1a0 = &u_ACPI_INT34BB;
  uVar9 = 0;
  local_1d0[0] = 0;
  local_180 = &u_ACPI_INT3451;
  local_160 = &u_ACPI_INT34D1;
  local_140 = &u_ACPI_INT3452;
  local_120 = &u_ACPI_INT3453;
  local_100 = &u_ACPI_INT3455;
  local_e0 = &u_ACPI_INT3450;
  local_c0 = &u_ACPI_INT34C3;
  local_a0 = &u_ACPI_INT34C4;
  local_80 = &u_ACPI_INT3456;
  local_60 = &u_ACPI_INT34C5;
  local_1d0[2] = 1;
  local_1b8 = 3;
  local_1b0 = 0;
  local_1a8 = 1;
  local_198 = 5;
  local_194 = 0xff;
  local_188 = 1;
  local_178 = 7;
  local_174 = 0xff;
  local_168 = 1;
  local_158 = 4;
  local_154 = 0xff;
  local_148 = 1;
  local_138 = 6;
  local_134 = 0xff;
  local_128 = 1;
  local_118 = 8;
  local_114 = 0xff;
  local_108 = 1;
  local_f8 = 9;
  local_f4 = 0xff;
  local_e8 = 1;
  local_d4 = 0xff;
  local_c8 = 1;
  local_b8 = 0xb;
  local_b4 = 0xff;
  local_a8 = 1;
  local_98 = 0xc;
  local_94 = 0xff;
  local_88 = 1;
  local_78 = 0xd;
  local_74 = 0xff;
  local_68 = 1;
  local_58 = 0xe;
  local_54 = 0xff;
  do {
    _Var7 = 0;
    memset(local_220,0,0x38);
    local_220[0] = 0x38;
    local_208 = 1;
    local_204 = 1;
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x290);
    local_200 = param_1;
    __empty_global_delete(pcVar2,_Var7);
    pWVar8 = param_1;
    iVar3 = (*pcVar2)(WdfDriverGlobals,param_1,*(undefined4 *)(ppuVar10 + -1));
    if (iVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_87a99f410be63a0c389337ae59f59430_Traceguids,uVar9,(char)iVar3);
      }
    }
    else {
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x610);
      __empty_global_delete(pcVar2,(__uint64)pWVar8);
      _Var7 = local_238;
      _Src = (wchar_t *)(*pcVar2)(WdfDriverGlobals,local_238,&local_228);
      pwVar1 = (wchar_t *)((longlong)_Src + (local_228 & 0xfffffffffffffffe));
      for (; _Src < pwVar1; _Src = _Src + sVar5 + 1) {
        _MaxCount = (longlong)pwVar1 - (longlong)_Src >> 1;
        _Var7 = _MaxCount;
        sVar5 = wcsnlen(_Src,_MaxCount);
        if (sVar5 == 0) break;
        _Str2 = (wchar_t *)*ppuVar10;
        uVar6 = 0xffffffffffffffff;
        sVar5 = _MaxCount & 0xffffffff;
        do {
          uVar6 = uVar6 + 1;
        } while (_Str2[uVar6] != L'\0');
        if (uVar6 < sVar5) {
          sVar5 = 0xffffffffffffffff;
          do {
            sVar5 = sVar5 + 1;
          } while (_Str2[sVar5] != L'\0');
        }
        iVar4 = wcsncmp(_Src,_Str2,sVar5);
        if (iVar4 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            _Str2 = (wchar_t *)0xc;
            WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                     &WPP_87a99f410be63a0c389337ae59f59430_Traceguids,(undefined1 *)_Src);
          }
          uVar6 = (ulonglong)uVar9;
          *(undefined4 *)(param_2 + 4) = local_1d0[uVar6 * 8 + -2];
          *(undefined4 *)param_2 = local_1d0[uVar6 * 8 + -1];
          *(undefined4 *)(param_2 + 0xc) = local_1d0[uVar6 * 8];
          pcVar2 = *(code **)(WdfFunctions_01015 + 0x680);
          __empty_global_delete(pcVar2,(__uint64)_Str2);
          (*pcVar2)(WdfDriverGlobals,local_238);
          goto LAB_1400020f6;
        }
        sVar5 = wcsnlen(_Src,_MaxCount);
        _Var7 = _MaxCount;
      }
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x680);
      __empty_global_delete(pcVar2,_Var7);
      (*pcVar2)(WdfDriverGlobals);
    }
    ppuVar10 = ppuVar10 + 4;
    uVar9 = uVar9 + 1;
    if (0xc < uVar9) {
      iVar3 = -0x3ffffda0;
LAB_1400020f6:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_87a99f410be63a0c389337ae59f59430_Traceguids);
      }
      return iVar3;
    }
  } while( true );
}



===== WPP_SF_S @ 1400021e0 =====

void WPP_SF_S(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined1 *param_4)

{
  code *pcVar1;
  longlong lVar2;
  undefined1 *puVar3;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (undefined1 *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_4 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  puVar3 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    puVar3 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,puVar3,lVar2,0);
  return;
}



===== WPP_SF_dd @ 14000228c =====

void WPP_SF_dd(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
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



===== GetAcpiHardwareInstance @ 14000230c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetAcpiHardwareInstance(struct WDFDEVICE__ * __ptr64,unsigned long * __ptr64) */

long __cdecl GetAcpiHardwareInstance(WDFDEVICE__ *param_1,ulong *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  __uint64 _Var4;
  ulonglong uVar5;
  long lVar6;
  undefined1 auStack_2b8 [32];
  undefined8 *local_298;
  undefined8 *local_290;
  undefined8 local_288;
  longlong *local_280;
  undefined4 local_278;
  undefined4 local_274;
  undefined8 local_270;
  int *local_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined4 *local_250;
  undefined8 local_248;
  longlong local_240;
  int local_238 [2];
  int local_230;
  short local_22c;
  ulong local_228;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2b8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids);
  }
  local_278 = 0x42696541;
  local_250 = &local_278;
  local_274 = 0x4449555f;
  _Var4 = 0;
  local_258 = 1;
  local_248 = 8;
  memset(local_238,0,0x200);
  *param_2 = 0xff;
  local_268 = local_238;
  local_270 = 1;
  local_260 = 0x200;
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x150);
  __empty_global_delete(pcVar1,_Var4);
  uVar3 = (*pcVar1)(WdfDriverGlobals);
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x5d0);
  __empty_global_delete(pcVar1,(__uint64)param_1);
  local_280 = &local_240;
  local_290 = &local_270;
  local_288 = 0;
  local_298 = &local_258;
  iVar2 = (*pcVar1)(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_240 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids,iVar2);
    }
    lVar6 = 0;
    goto LAB_140002586;
  }
  lVar6 = -0x3febfff1;
  if (local_238[0] == 0x426f6541) {
    if (local_230 == 1) {
      if (local_22c == 0) {
        lVar6 = 0;
        *param_2 = local_228;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids,local_228);
        }
        goto LAB_140002586;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_140002586;
      uVar5 = 0x15;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_140002586;
      uVar5 = 0x14;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140002586;
    uVar5 = 0x13;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
          &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids);
LAB_140002586:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids);
  }
  return lVar6;
}



===== GetAcpiHardwareRevision @ 1400025e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetAcpiHardwareRevision(struct WDFDEVICE__ * __ptr64,unsigned long * __ptr64) */

long __cdecl GetAcpiHardwareRevision(WDFDEVICE__ *param_1,ulong *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  __uint64 _Var4;
  ulonglong uVar5;
  long lVar6;
  undefined1 auStack_2b8 [32];
  undefined8 *local_298;
  undefined8 *local_290;
  undefined8 local_288;
  longlong *local_280;
  undefined4 local_278;
  undefined4 local_274;
  undefined8 local_270;
  int *local_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined4 *local_250;
  undefined8 local_248;
  longlong local_240;
  int local_238 [2];
  int local_230;
  short local_22c;
  ulong local_228;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2b8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids);
  }
  local_278 = 0x42696541;
  local_250 = &local_278;
  local_274 = 0x5652485f;
  _Var4 = 0;
  local_258 = 1;
  local_248 = 8;
  memset(local_238,0,0x200);
  local_268 = local_238;
  local_270 = 1;
  local_260 = 0x200;
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x150);
  __empty_global_delete(pcVar1,_Var4);
  uVar3 = (*pcVar1)(WdfDriverGlobals);
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x5d0);
  __empty_global_delete(pcVar1,(__uint64)param_1);
  local_280 = &local_240;
  local_290 = &local_270;
  local_288 = 0;
  local_298 = &local_258;
  iVar2 = (*pcVar1)(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_240 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids,iVar2);
    }
    lVar6 = 0;
    *param_2 = 0;
    goto LAB_14000285d;
  }
  lVar6 = -0x3febfff1;
  *param_2 = 0xff;
  if (local_238[0] == 0x426f6541) {
    if (local_230 == 1) {
      if (local_22c == 0) {
        lVar6 = 0;
        *param_2 = local_228;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids,local_228);
        }
        goto LAB_14000285d;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_14000285d;
      uVar5 = 0xe;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_14000285d;
      uVar5 = 0xd;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000285d;
    uVar5 = 0xc;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
          &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids);
LAB_14000285d:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_ab0e11a10c1c35245afbdd935b583a69_Traceguids);
  }
  return lVar6;
}



===== `scalar_deleting_destructor' @ 1400028c0 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER::_scalar_deleting_destructor_(_GPIO_CONTROLLER *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x28);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002900 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_GLK_NORTH::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_GLK_NORTH::_vector_deleting_destructor_
          (_GPIO_CONTROLLER_GLK_NORTH *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0xc0);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002940 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_BXT_WEST::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_BXT_WEST::_vector_deleting_destructor_
          (_GPIO_CONTROLLER_BXT_WEST *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0xa0);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002980 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_BXT_SOUTH_WEST::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_BXT_SOUTH_WEST::_vector_deleting_destructor_
          (_GPIO_CONTROLLER_BXT_SOUTH_WEST *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x80);
    }
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1400029c0 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_CNL_H::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_CNL_H::_scalar_deleting_destructor_(_GPIO_CONTROLLER_CNL_H *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x228);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002a00 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_CNL_LP::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_CNL_LP::_vector_deleting_destructor_(_GPIO_CONTROLLER_CNL_LP *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x1d0);
    }
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140002a40 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_GLK_NORTH_WEST::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_GLK_NORTH_WEST::_scalar_deleting_destructor_
          (_GPIO_CONTROLLER_GLK_NORTH_WEST *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0xe0);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002a80 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_ICL_N::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_ICL_N::_vector_deleting_destructor_(_GPIO_CONTROLLER_ICL_N *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x280);
    }
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140002ac0 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_ICL_LP::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_ICL_LP::_scalar_deleting_destructor_(_GPIO_CONTROLLER_ICL_LP *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x208);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002b00 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_LKF::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_LKF::_vector_deleting_destructor_(_GPIO_CONTROLLER_LKF *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x1c8);
    }
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140002b40 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_LKF_FPGA::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_LKF_FPGA::_scalar_deleting_destructor_
          (_GPIO_CONTROLLER_LKF_FPGA *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x150);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002b80 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_SKL_H::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_SKL_H::_vector_deleting_destructor_(_GPIO_CONTROLLER_SKL_H *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x1b0);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002bc0 =====

/* public: virtual void * __ptr64 __cdecl _GPIO_CONTROLLER_SKL_LP::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
_GPIO_CONTROLLER_SKL_LP::_vector_deleting_destructor_(_GPIO_CONTROLLER_SKL_LP *this,uint param_1)

{
  *(undefined ***)this = &_GPIO_CONTROLLER::_vftable_;
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      ExFreePoolWithTag(this,0);
    }
    else {
      __empty_global_delete(this,0x170);
    }
  }
  return this;
}



===== GpioClearActiveInterrupts @ 140002c00 =====

/* long __cdecl GpioClearActiveInterrupts(void * __ptr64,struct
   _GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS * __ptr64) */

long __cdecl
GpioClearActiveInterrupts(void *param_1,_GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioClearActiveInterrupts");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x60);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioConnectIoPins @ 140002c80 =====

/* long __cdecl GpioConnectIoPins(void * __ptr64,struct _GPIO_CONNECT_IO_PINS_PARAMETERS * __ptr64)
    */

long __cdecl GpioConnectIoPins(void *param_1,_GPIO_CONNECT_IO_PINS_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_CONNECT_IO_PINS_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_CONNECT_IO_PINS_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioConnectIoPins");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x70);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioControllerSpecificFunction @ 140002d00 =====

/* long __cdecl GpioControllerSpecificFunction(void * __ptr64,struct
   _GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS * __ptr64) */

long __cdecl
GpioControllerSpecificFunction
          (void *param_1,_GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioControllerSpecificFunction");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x90);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioControllerValidateContext @ 140002d84 =====

/* long __cdecl GpioControllerValidateContext(struct _GPIO_DEVICE_CONTEXT * __ptr64) */

long __cdecl GpioControllerValidateContext(_GPIO_DEVICE_CONTEXT *param_1)

{
  long lVar1;
  
  if (param_1 == (_GPIO_DEVICE_CONTEXT *)0x0) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDIContext_Error,0)
      ;
    }
    lVar1 = -0x3ffff8e7;
  }
  else if (*(longlong *)(param_1 + 0x20) == 0) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDIController_Error
                   ,param_1);
    }
    lVar1 = -0x3fffff00;
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}



===== GpioDisableInterrupt @ 140002df0 =====

/* long __cdecl GpioDisableInterrupt(void * __ptr64,struct _GPIO_DISABLE_INTERRUPT_PARAMETERS *
   __ptr64) */

long __cdecl GpioDisableInterrupt(void *param_1,_GPIO_DISABLE_INTERRUPT_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_DISABLE_INTERRUPT_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_DISABLE_INTERRUPT_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioDisableInterrupt");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x38);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioDisconnectIoPins @ 140002e70 =====

/* long __cdecl GpioDisconnectIoPins(void * __ptr64,struct _GPIO_DISCONNECT_IO_PINS_PARAMETERS *
   __ptr64) */

long __cdecl GpioDisconnectIoPins(void *param_1,_GPIO_DISCONNECT_IO_PINS_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_DISCONNECT_IO_PINS_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_DISCONNECT_IO_PINS_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioDisconnectIoPins");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x78);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioEnableInterrupt @ 140002ef0 =====

/* long __cdecl GpioEnableInterrupt(void * __ptr64,struct _GPIO_ENABLE_INTERRUPT_PARAMETERS *
   __ptr64) */

long __cdecl GpioEnableInterrupt(void *param_1,_GPIO_ENABLE_INTERRUPT_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_ENABLE_INTERRUPT_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_ENABLE_INTERRUPT_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioEnableInterrupt");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x30);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioMaskInterrupts @ 140002f70 =====

/* long __cdecl GpioMaskInterrupts(void * __ptr64,struct _GPIO_MASK_INTERRUPT_PARAMETERS * __ptr64)
    */

long __cdecl GpioMaskInterrupts(void *param_1,_GPIO_MASK_INTERRUPT_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_MASK_INTERRUPT_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_MASK_INTERRUPT_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioMaskInterrupts");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x40);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioPrepareController @ 140002ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GpioPrepareController(struct WDFDEVICE__ * __ptr64,void * __ptr64,struct
   WDFCMRESLIST__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
GpioPrepareController
          (WDFDEVICE__ *param_1,void *param_2,WDFCMRESLIST__ *param_3,WDFCMRESLIST__ *param_4)

{
  HW_PARAMETERS *pHVar1;
  code *pcVar2;
  longlong lVar3;
  longlong *plVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined **ppuVar9;
  ulonglong uVar10;
  __uint64 _Var11;
  undefined8 *puVar12;
  WDFDEVICE__ *pWVar13;
  undefined1 auStackY_a8 [32];
  undefined4 local_60;
  ushort uStack_5c;
  undefined2 uStack_5a;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_a8;
  EtwActivityIdControl(3);
  if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
    McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,&local_60,
                  "GpioPrepareController");
  }
  if (param_2 == (void *)0x0) {
    lVar5 = -0x3ffff8e7;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDIContext_Error,
                   &local_60);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffff8e7;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
      return -0x3ffff8e7;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffff8e7;
    }
    uVar10 = 10;
    goto LAB_1400030bf;
  }
  _Var11 = 0;
  memset(param_2,0,0x38);
  puVar12 = WdfDriverGlobals;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  uVar7 = *WdfDriverGlobals;
  __empty_global_delete(pcVar2,_Var11);
  uVar7 = (*pcVar2)(puVar12,uVar7,PTR__WDF_GPIO_DRIVER_CONTEXT_TYPE_INFO_140016060);
  pHVar1 = (HW_PARAMETERS *)((longlong)param_2 + 0x10);
  *(undefined8 *)((longlong)param_2 + 0x28) = uVar7;
  lVar5 = CheckSupportedHardware(param_1,pHVar1);
  if (lVar5 < 0) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0qqqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                       (uint *)&EvtGpioDDIControllerHw_Error,&local_60,*(undefined4 *)pHVar1,
                       (char)*(undefined4 *)((longlong)param_2 + 0x14),
                       (char)*(undefined4 *)((longlong)param_2 + 0x18),
                       (char)*(undefined4 *)((longlong)param_2 + 0x1c));
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar5;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
      return lVar5;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return lVar5;
    }
    WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_55fa190174d53f1b2dc0bba95ab60413_Traceguids,"GpioPrepareController",
                (char)*(undefined4 *)((longlong)param_2 + 0x14),
                (char)*(undefined4 *)((longlong)param_2 + 0x18),
                (char)*(undefined4 *)((longlong)param_2 + 0x1c));
    return lVar5;
  }
  uStack_5c = *(ushort *)pHVar1 | 0x8000;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
    McTemplateK0qqqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                     (uint *)&EvtGpioDDIControllerHw_Info,&local_60,*(undefined4 *)pHVar1,
                     (char)*(undefined4 *)((longlong)param_2 + 0x14),
                     (char)*(undefined4 *)((longlong)param_2 + 0x18),
                     (char)*(undefined4 *)((longlong)param_2 + 0x1c));
  }
  iVar6 = *(int *)((longlong)param_2 + 0x14);
  if (iVar6 == 2) {
    puVar12 = (undefined8 *)0x170;
    puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x170,0x49504749);
    if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
    memset(puVar8,0,0x170);
    puVar8[1] = 0;
    *puVar8 = &_GPIO_CONTROLLER::_vftable_;
    puVar12 = puVar8 + 2;
    puVar8[4] = 0;
    EtwActivityIdControl(3);
    ppuVar9 = &_GPIO_CONTROLLER_SKL_LP::_vftable_;
    goto LAB_140003cce;
  }
  if (iVar6 == 3) {
LAB_140003297:
    puVar12 = (undefined8 *)0x1b0;
    puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x1b0,0x49504749);
    if (puVar8 != (undefined8 *)0x0) {
      memset(puVar8,0,0x1b0);
      *puVar8 = &_GPIO_CONTROLLER::_vftable_;
      puVar12 = puVar8 + 2;
      puVar8[1] = 0;
      puVar8[4] = 0;
      EtwActivityIdControl(3);
      ppuVar9 = &_GPIO_CONTROLLER_SKL_H::_vftable_;
      goto LAB_140003cce;
    }
LAB_14000354a:
    puVar8 = (undefined8 *)0x0;
LAB_14000354d:
    *(undefined8 **)((longlong)param_2 + 0x20) = puVar8;
  }
  else {
    if (iVar6 == 5) {
      puVar12 = (undefined8 *)0x1d0;
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x1d0,0x49504749);
      if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
      memset(puVar8,0,0x1d0);
      puVar8[1] = 0;
      *puVar8 = &_GPIO_CONTROLLER::_vftable_;
      puVar12 = puVar8 + 2;
      puVar8[4] = 0;
      EtwActivityIdControl(3);
      ppuVar9 = &_GPIO_CONTROLLER_CNL_LP::_vftable_;
LAB_140003cce:
      puVar8[8] = 0;
      puVar8[7] = 0;
      *(undefined4 *)((longlong)puVar8 + 0x2e) = 0;
      *(undefined1 *)((longlong)puVar8 + 0x2c) = 0;
      *(undefined4 *)(puVar8 + 5) = 0;
      *puVar8 = ppuVar9;
      goto LAB_14000354d;
    }
    if (iVar6 == 10) {
      puVar12 = (undefined8 *)0x228;
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x228,0x49504749);
      if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
      memset(puVar8,0,0x228);
      *puVar8 = &_GPIO_CONTROLLER::_vftable_;
      puVar12 = puVar8 + 2;
      puVar8[1] = 0;
      puVar8[4] = 0;
      EtwActivityIdControl(3);
      ppuVar9 = &_GPIO_CONTROLLER_CNL_H::_vftable_;
      goto LAB_140003cce;
    }
    if (iVar6 == 7) goto LAB_140003297;
    if (iVar6 == 9) {
      puVar12 = (undefined8 *)0x208;
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x208,0x49504749);
      if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
      memset(puVar8,0,0x208);
      puVar8[1] = 0;
      *puVar8 = &_GPIO_CONTROLLER::_vftable_;
      puVar12 = puVar8 + 2;
      puVar8[4] = 0;
      EtwActivityIdControl(3);
      ppuVar9 = &_GPIO_CONTROLLER_ICL_LP::_vftable_;
      goto LAB_140003cce;
    }
    if (iVar6 == 0xb) {
      puVar12 = (undefined8 *)0x280;
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x280,0x49504749);
      if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
      memset(puVar8,0,0x280);
      *puVar8 = &_GPIO_CONTROLLER::_vftable_;
      puVar12 = puVar8 + 2;
      puVar8[1] = 0;
      puVar8[4] = 0;
      EtwActivityIdControl(3);
      ppuVar9 = &_GPIO_CONTROLLER_ICL_N::_vftable_;
      goto LAB_140003cce;
    }
    puVar12 = (undefined8 *)0xd;
    if (iVar6 == 0xd) {
      puVar12 = (undefined8 *)0x280;
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x280,0x49504749);
      if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
      memset(puVar8,0,0x280);
      *puVar8 = &_GPIO_CONTROLLER::_vftable_;
      puVar12 = puVar8 + 2;
      puVar8[1] = 0;
      puVar8[4] = 0;
      EtwActivityIdControl(3);
      ppuVar9 = &_GPIO_CONTROLLER_ICL_H::_vftable_;
      goto LAB_140003cce;
    }
    if (iVar6 == 0xe) {
      puVar12 = (undefined8 *)0x228;
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x228,0x49504749);
      if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
      memset(puVar8,0,0x228);
      *puVar8 = &_GPIO_CONTROLLER::_vftable_;
      puVar12 = puVar8 + 2;
      puVar8[1] = 0;
      puVar8[4] = 0;
      EtwActivityIdControl(3);
      ppuVar9 = &_GPIO_CONTROLLER_TGL_LP::_vftable_;
      goto LAB_140003cce;
    }
    if (iVar6 == 4) {
      iVar6 = *(int *)pHVar1;
      if (iVar6 == 1) {
        puVar12 = (undefined8 *)0xc0;
        puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xc0,0x49504749);
        if (puVar8 != (undefined8 *)0x0) {
          memset(puVar8,0,0xc0);
          *puVar8 = &_GPIO_CONTROLLER::_vftable_;
          puVar12 = puVar8 + 2;
          puVar8[1] = 0;
          puVar8[4] = 0;
          EtwActivityIdControl(3);
          ppuVar9 = &_GPIO_CONTROLLER_BXT_NORTH::_vftable_;
          goto LAB_1400039c4;
        }
LAB_1400039da:
        puVar8 = (undefined8 *)0x0;
      }
      else {
        if (iVar6 != 2) {
          if (iVar6 == 3) {
            puVar12 = (undefined8 *)0xa0;
            puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xa0,0x49504749);
            if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
            memset(puVar8,0,0xa0);
            *puVar8 = &_GPIO_CONTROLLER::_vftable_;
            puVar12 = puVar8 + 2;
            puVar8[1] = 0;
            puVar8[4] = 0;
            EtwActivityIdControl(3);
            ppuVar9 = &_GPIO_CONTROLLER_BXT_WEST::_vftable_;
          }
          else if (iVar6 == 4) {
            puVar12 = (undefined8 *)0x80;
            puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x80,0x49504749);
            if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
            memset(puVar8,0,0x80);
            *puVar8 = &_GPIO_CONTROLLER::_vftable_;
            puVar12 = puVar8 + 2;
            puVar8[1] = 0;
            puVar8[4] = 0;
            EtwActivityIdControl(3);
            ppuVar9 = &_GPIO_CONTROLLER_BXT_SOUTH_WEST::_vftable_;
          }
          else {
            if (iVar6 != 5) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                puVar12 = (undefined8 *)0xc;
                goto LAB_140003c63;
              }
              goto LAB_140003551;
            }
            puVar12 = (undefined8 *)0x80;
            puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x80,0x49504749);
            if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
            memset(puVar8,0,0x80);
            *puVar8 = &_GPIO_CONTROLLER::_vftable_;
            puVar12 = puVar8 + 2;
            puVar8[1] = 0;
            puVar8[4] = 0;
            EtwActivityIdControl(3);
            ppuVar9 = &_GPIO_CONTROLLER_BXT_SOUTH::_vftable_;
          }
          goto LAB_140003cce;
        }
        puVar12 = (undefined8 *)0xc0;
        puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xc0,0x49504749);
        if (puVar8 == (undefined8 *)0x0) goto LAB_1400039da;
        memset(puVar8,0,0xc0);
        *puVar8 = &_GPIO_CONTROLLER::_vftable_;
        puVar12 = puVar8 + 2;
        puVar8[1] = 0;
        puVar8[4] = 0;
        EtwActivityIdControl(3);
        ppuVar9 = &_GPIO_CONTROLLER_BXT_NORTH_WEST::_vftable_;
LAB_1400039c4:
        puVar8[8] = 0;
        puVar8[7] = 0;
        *(undefined4 *)((longlong)puVar8 + 0x2e) = 0;
        *(undefined1 *)((longlong)puVar8 + 0x2c) = 0;
        *(undefined4 *)(puVar8 + 5) = 0;
        *puVar8 = ppuVar9;
      }
      *(undefined8 **)((longlong)param_2 + 0x20) = puVar8;
    }
    else {
      if (iVar6 == 6) {
        iVar6 = *(int *)pHVar1;
        if (iVar6 == 1) {
          puVar12 = (undefined8 *)0xc0;
          puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xc0,0x49504749);
          if (puVar8 == (undefined8 *)0x0) goto LAB_1400039da;
          memset(puVar8,0,0xc0);
          *puVar8 = &_GPIO_CONTROLLER::_vftable_;
          puVar12 = puVar8 + 2;
          puVar8[1] = 0;
          puVar8[4] = 0;
          EtwActivityIdControl(3);
          ppuVar9 = &_GPIO_CONTROLLER_BXT_P_NORTH::_vftable_;
        }
        else {
          if (iVar6 != 2) {
            if (iVar6 == 3) {
              puVar12 = (undefined8 *)0xa0;
              puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xa0,0x49504749);
              if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
              memset(puVar8,0,0xa0);
              *puVar8 = &_GPIO_CONTROLLER::_vftable_;
              puVar12 = puVar8 + 2;
              puVar8[1] = 0;
              puVar8[4] = 0;
              EtwActivityIdControl(3);
              ppuVar9 = &_GPIO_CONTROLLER_BXT_P_WEST::_vftable_;
            }
            else {
              if (iVar6 != 4) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) goto LAB_140003c63;
                goto LAB_140003551;
              }
              puVar12 = (undefined8 *)0xa0;
              puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xa0,0x49504749);
              if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
              memset(puVar8,0,0xa0);
              *puVar8 = &_GPIO_CONTROLLER::_vftable_;
              puVar12 = puVar8 + 2;
              puVar8[1] = 0;
              puVar8[4] = 0;
              EtwActivityIdControl(3);
              ppuVar9 = &_GPIO_CONTROLLER_BXT_P_SOUTH_WEST::_vftable_;
            }
            goto LAB_140003cce;
          }
          puVar12 = (undefined8 *)0xc0;
          puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xc0,0x49504749);
          if (puVar8 == (undefined8 *)0x0) goto LAB_1400039da;
          memset(puVar8,0,0xc0);
          *puVar8 = &_GPIO_CONTROLLER::_vftable_;
          puVar12 = puVar8 + 2;
          puVar8[1] = 0;
          puVar8[4] = 0;
          EtwActivityIdControl(3);
          ppuVar9 = &_GPIO_CONTROLLER_BXT_P_NORTH_WEST::_vftable_;
        }
        goto LAB_1400039c4;
      }
      if (iVar6 == 8) {
        iVar6 = *(int *)pHVar1;
        if (iVar6 == 1) {
          puVar12 = (undefined8 *)0xe0;
          puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xe0,0x49504749);
          if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
          memset(puVar8,0,0xe0);
          puVar8[1] = 0;
          *puVar8 = &_GPIO_CONTROLLER::_vftable_;
          puVar12 = puVar8 + 2;
          puVar8[4] = 0;
          EtwActivityIdControl(3);
          ppuVar9 = &_GPIO_CONTROLLER_GLK_NORTH_WEST::_vftable_;
        }
        else {
          if (iVar6 == 2) {
            puVar12 = (undefined8 *)0xc0;
            puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xc0,0x49504749);
            if (puVar8 == (undefined8 *)0x0) goto LAB_1400039da;
            memset(puVar8,0,0xc0);
            *puVar8 = &_GPIO_CONTROLLER::_vftable_;
            puVar12 = puVar8 + 2;
            puVar8[1] = 0;
            puVar8[4] = 0;
            EtwActivityIdControl(3);
            ppuVar9 = &_GPIO_CONTROLLER_GLK_NORTH::_vftable_;
            goto LAB_1400039c4;
          }
          if (iVar6 == 3) {
            puVar12 = (undefined8 *)0x80;
            puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x80,0x49504749);
            if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
            memset(puVar8,0,0x80);
            *puVar8 = &_GPIO_CONTROLLER::_vftable_;
            puVar12 = puVar8 + 2;
            puVar8[1] = 0;
            puVar8[4] = 0;
            EtwActivityIdControl(3);
            ppuVar9 = &_GPIO_CONTROLLER_GLK_AUDIO::_vftable_;
          }
          else {
            if (iVar6 != 4) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                puVar12 = (undefined8 *)0xe;
                goto LAB_140003c63;
              }
              goto LAB_140003551;
            }
            puVar12 = (undefined8 *)0xa0;
            puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0xa0,0x49504749);
            if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
            memset(puVar8,0,0xa0);
            *puVar8 = &_GPIO_CONTROLLER::_vftable_;
            puVar12 = puVar8 + 2;
            puVar8[1] = 0;
            puVar8[4] = 0;
            EtwActivityIdControl(3);
            ppuVar9 = &_GPIO_CONTROLLER_GLK_SCC::_vftable_;
          }
        }
        goto LAB_140003cce;
      }
      if (iVar6 == 0xc) {
        if (*(uint *)((longlong)param_2 + 0x18) < 0xf0) {
          puVar12 = (undefined8 *)0x1c8;
          puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x1c8,0x49504749);
          if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
          memset(puVar8,0,0x1c8);
          puVar8[1] = 0;
          *puVar8 = &_GPIO_CONTROLLER::_vftable_;
          puVar12 = puVar8 + 2;
          puVar8[4] = 0;
          EtwActivityIdControl(3);
          ppuVar9 = &_GPIO_CONTROLLER_LKF::_vftable_;
        }
        else {
          iVar6 = *(int *)pHVar1;
          if (iVar6 != 1) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              puVar12 = (undefined8 *)0xf;
LAB_140003c63:
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)puVar12,
                       &WPP_55fa190174d53f1b2dc0bba95ab60413_Traceguids,iVar6);
            }
            goto LAB_140003551;
          }
          puVar12 = (undefined8 *)0x150;
          puVar8 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x150,0x49504749);
          if (puVar8 == (undefined8 *)0x0) goto LAB_14000354a;
          memset(puVar8,0,0x150);
          puVar8[1] = 0;
          *puVar8 = &_GPIO_CONTROLLER::_vftable_;
          puVar12 = puVar8 + 2;
          puVar8[4] = 0;
          EtwActivityIdControl(3);
          ppuVar9 = &_GPIO_CONTROLLER_LKF_FPGA::_vftable_;
        }
        goto LAB_140003cce;
      }
    }
  }
LAB_140003551:
  if (*(longlong *)((longlong)param_2 + 0x20) != 0) {
    *(WDFDEVICE__ **)(*(longlong *)((longlong)param_2 + 0x20) + 0x20) = param_1;
    uVar7 = CONCAT26(uStack_5a,CONCAT24(uStack_5c,local_60));
    lVar3 = *(longlong *)((longlong)param_2 + 0x20);
    *(undefined8 *)param_2 = uVar7;
    *(undefined8 *)((longlong)param_2 + 8) = uStack_58;
    *(undefined8 *)(lVar3 + 0x10) = uVar7;
    *(undefined8 *)(lVar3 + 0x18) = uStack_58;
    plVar4 = *(longlong **)((longlong)param_2 + 0x20);
    pcVar2 = *(code **)(*plVar4 + 8);
    __empty_global_delete(pcVar2,(__uint64)puVar12);
    pWVar13 = param_1;
    iVar6 = (*pcVar2)(plVar4,param_1,param_2,param_3);
    if (-1 < iVar6) {
      return iVar6;
    }
    plVar4 = *(longlong **)((longlong)param_2 + 0x20);
    if (plVar4 == (longlong *)0x0) {
      return iVar6;
    }
    pcVar2 = *(code **)(*plVar4 + 0x10);
    __empty_global_delete(pcVar2,(__uint64)pWVar13);
    lVar5 = (*pcVar2)(plVar4,param_1,param_2);
    puVar12 = *(undefined8 **)((longlong)param_2 + 0x20);
    if (puVar12 != (undefined8 *)0x0) {
      pcVar2 = *(code **)*puVar12;
      __empty_global_delete(pcVar2,(__uint64)param_1);
      (*pcVar2)(puVar12,1);
    }
    *(undefined8 *)((longlong)param_2 + 0x20) = 0;
    return lVar5;
  }
  lVar5 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtGpioDDIControllerAllocate_Error,&local_60);
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return -0x3fffff66;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
    return -0x3fffff66;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
    return -0x3fffff66;
  }
  uVar10 = 0x10;
LAB_1400030bf:
  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
           &WPP_55fa190174d53f1b2dc0bba95ab60413_Traceguids,"GpioPrepareController");
  return lVar5;
}



===== GpioQueryActiveInterrupts @ 140003da0 =====

/* long __cdecl GpioQueryActiveInterrupts(void * __ptr64,struct
   _GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS * __ptr64) */

long __cdecl
GpioQueryActiveInterrupts(void *param_1,_GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioQueryActiveInterrupts");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x50);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioQueryControllerBasicInformation @ 140003e20 =====

/* long __cdecl GpioQueryControllerBasicInformation(void * __ptr64,struct
   _CLIENT_CONTROLLER_BASIC_INFORMATION * __ptr64) */

long __cdecl
GpioQueryControllerBasicInformation(void *param_1,_CLIENT_CONTROLLER_BASIC_INFORMATION *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _CLIENT_CONTROLLER_BASIC_INFORMATION *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_CLIENT_CONTROLLER_BASIC_INFORMATION *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioQueryControllerBasicInformation");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x18);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioQueryEnabledInterrupts @ 140003ea0 =====

/* long __cdecl GpioQueryEnabledInterrupts(void * __ptr64,struct
   _GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS * __ptr64) */

long __cdecl
GpioQueryEnabledInterrupts(void *param_1,_GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioQueryEnabledInterrupts");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x58);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioReadGpioPins @ 140003f20 =====

/* long __cdecl GpioReadGpioPins(void * __ptr64,struct _GPIO_READ_PINS_PARAMETERS * __ptr64) */

long __cdecl GpioReadGpioPins(void *param_1,_GPIO_READ_PINS_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_READ_PINS_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_READ_PINS_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioReadGpioPins");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x80);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioReconfigureInterrupt @ 140003fb0 =====

/* long __cdecl GpioReconfigureInterrupt(void * __ptr64,struct
   _GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS * __ptr64) */

long __cdecl
GpioReconfigureInterrupt(void *param_1,_GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioReconfigureInterrupt");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x68);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioReleaseController @ 140004030 =====

/* long __cdecl GpioReleaseController(struct WDFDEVICE__ * __ptr64,void * __ptr64) */

long __cdecl GpioReleaseController(WDFDEVICE__ *param_1,void *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined *puVar5;
  
  puVar5 = param_2;
  lVar4 = GpioControllerValidateContext(param_2);
  if (-1 < lVar4) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      puVar5 = &EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_2,
                    "GpioReleaseController");
    }
    plVar1 = *(longlong **)((longlong)param_2 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x10);
    __empty_global_delete(pcVar2,(__uint64)puVar5);
    lVar4 = (*pcVar2)(plVar1,param_1,param_2);
    puVar3 = *(undefined8 **)((longlong)param_2 + 0x20);
    if (puVar3 != (undefined8 *)0x0) {
      pcVar2 = *(code **)*puVar3;
      __empty_global_delete(pcVar2,(__uint64)param_1);
      (*pcVar2)(puVar3,1);
    }
    *(undefined8 *)((longlong)param_2 + 0x20) = 0;
  }
  return lVar4;
}



===== GpioRestoreBankHardwareContext @ 1400040f0 =====

/* void __cdecl GpioRestoreBankHardwareContext(void * __ptr64,struct
   _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS * __ptr64) */

void __cdecl
GpioRestoreBankHardwareContext
          (void *param_1,_GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioRestoreBankHardwareContext");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x98);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    (*pcVar2)(plVar1,param_1,param_2);
  }
  return;
}



===== GpioSaveBankHardwareContext @ 140004180 =====

/* void __cdecl GpioSaveBankHardwareContext(void * __ptr64,struct
   _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS * __ptr64) */

void __cdecl
GpioSaveBankHardwareContext
          (void *param_1,_GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioSaveBankHardwareContext");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0xa0);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    (*pcVar2)(plVar1,param_1,param_2);
  }
  return;
}



===== GpioStartController @ 140004210 =====

/* long __cdecl GpioStartController(void * __ptr64,unsigned char,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl GpioStartController(void *param_1,uchar param_2,_WDF_POWER_DEVICE_STATE param_3)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  undefined7 in_register_00000011;
  undefined *puVar4;
  
  puVar4 = (undefined *)CONCAT71(in_register_00000011,param_2);
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      puVar4 = &EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioStartController");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x20);
    __empty_global_delete(pcVar2,(__uint64)puVar4);
    (*pcVar2)(plVar1,param_1,param_2,param_3);
  }
  return lVar3;
}



===== GpioStopController @ 1400042b0 =====

/* long __cdecl GpioStopController(void * __ptr64,unsigned char,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl GpioStopController(void *param_1,uchar param_2,_WDF_POWER_DEVICE_STATE param_3)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  undefined7 in_register_00000011;
  undefined *puVar4;
  
  puVar4 = (undefined *)CONCAT71(in_register_00000011,param_2);
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      puVar4 = &EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioStopController");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x28);
    __empty_global_delete(pcVar2,(__uint64)puVar4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2,param_3);
  }
  return lVar3;
}



===== GpioUnmaskInterrupt @ 140004340 =====

/* long __cdecl GpioUnmaskInterrupt(void * __ptr64,struct _GPIO_ENABLE_INTERRUPT_PARAMETERS *
   __ptr64) */

long __cdecl GpioUnmaskInterrupt(void *param_1,_GPIO_ENABLE_INTERRUPT_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_ENABLE_INTERRUPT_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_ENABLE_INTERRUPT_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioUnmaskInterrupt");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x48);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== GpioWriteGpioPins @ 1400043c0 =====

/* long __cdecl GpioWriteGpioPins(void * __ptr64,struct _GPIO_WRITE_PINS_PARAMETERS * __ptr64) */

long __cdecl GpioWriteGpioPins(void *param_1,_GPIO_WRITE_PINS_PARAMETERS *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  _GPIO_WRITE_PINS_PARAMETERS *p_Var4;
  
  p_Var4 = param_2;
  lVar3 = GpioControllerValidateContext(param_1);
  if (-1 < lVar3) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      p_Var4 = (_GPIO_WRITE_PINS_PARAMETERS *)&EvtGpioDDI_Info;
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtGpioDDI_Info,param_1,
                    "GpioWriteGpioPins");
    }
    plVar1 = *(longlong **)((longlong)param_1 + 0x20);
    pcVar2 = *(code **)(*plVar1 + 0x88);
    __empty_global_delete(pcVar2,(__uint64)p_Var4);
    lVar3 = (*pcVar2)(plVar1,param_1,param_2);
  }
  return lVar3;
}



===== __empty_global_delete @ 140004450 =====

/* void __cdecl __empty_global_delete(void * __ptr64,unsigned __int64) */

void __cdecl __empty_global_delete(void *param_1,__uint64 param_2)

{
  return;
}



===== McTemplateK0qqqq @ 140004454 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined4 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0s @ 1400044e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0s(undefined8 *param_1,uint *param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_4 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  local_28 = "NULL";
  if (param_4 != (char *)0x0) {
    local_28 = param_4;
  }
  local_1c = 0;
  McGenEventWriteKM(param_1,param_2,param_3,2,local_38);
  return;
}



===== WPP_SF_s @ 140004558 =====

void WPP_SF_s(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar2,lVar4,0);
  return;
}



===== WPP_SF_sDDD @ 1400045f0 =====

void WPP_SF_sDDD(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar2,lVar4,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== GetGpioIeRegAddress @ 1400046c4 =====

/* protected: unsigned long * __ptr64 __cdecl
   _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress(unsigned short) __ptr64 */

ulong * __thiscall
_GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress(_GPIO_CONTROLLER_CHASSIS3 *this,ushort param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  
  lVar2 = (ulonglong)param_1 * 0x20 + *(longlong *)(this + 0x40);
  uVar1 = (ulonglong)*(ushort *)(lVar2 + 2);
  return (ulong *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar1 * 0x18) +
                   (ulonglong)*(ushort *)(lVar2 + 4) * 4 +
                  *(longlong *)(*(longlong *)(this + 0x38) + uVar1 * 0x18));
}



===== GetGpioOwnRegAddress @ 1400046f4 =====

/* protected: unsigned long * __ptr64 __cdecl
   _GPIO_CONTROLLER_CHASSIS3::GetGpioOwnRegAddress(unsigned short) __ptr64 */

ulong * __thiscall
_GPIO_CONTROLLER_CHASSIS3::GetGpioOwnRegAddress(_GPIO_CONTROLLER_CHASSIS3 *this,ushort param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  
  lVar2 = (ulonglong)param_1 * 0x20 + *(longlong *)(this + 0x40);
  uVar1 = (ulonglong)*(ushort *)(lVar2 + 2);
  return (ulong *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xc + uVar1 * 0x18) +
                   (ulonglong)*(ushort *)(lVar2 + 4) * 4 +
                  *(longlong *)(*(longlong *)(this + 0x38) + uVar1 * 0x18));
}



===== GetGpioPadRegAddress @ 140004724 =====

/* protected: unsigned long * __ptr64 __cdecl
   _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress(unsigned short,unsigned short) __ptr64 */

ulong * __thiscall
_GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
          (_GPIO_CONTROLLER_CHASSIS3 *this,ushort param_1,ushort param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  
  lVar2 = (ulonglong)param_1 * 0x20 + *(longlong *)(this + 0x40);
  uVar1 = (ulonglong)*(ushort *)(lVar2 + 2);
  return (ulong *)((longlong)(int)((uint)param_2 * (uint)*(ushort *)(this + 0x30)) +
                   (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar1 * 0x18) +
                   (ulonglong)*(ushort *)(lVar2 + 6) +
                  *(longlong *)(*(longlong *)(this + 0x38) + uVar1 * 0x18));
}



===== GpioClearActiveInterrupts @ 140004760 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioClearActiveInterrupts(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS * __ptr64) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioClearActiveInterrupts
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  longlong lVar5;
  long lVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  uVar4 = *(uint *)(param_2 + 8);
  *(ulonglong *)(param_2 + 0x10) = (ulonglong)uVar4;
  lVar6 = GpioValidateBankRange(this,uVar1);
  if (lVar6 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioClearActiveInterrupts");
    }
  }
  else {
    lVar8 = (ulonglong)uVar1 * 0x20;
    uVar7 = (ulonglong)*(ushort *)(lVar8 + 2 + *(longlong *)(this + 0x40));
    uVar2 = *(ushort *)(lVar8 + 4 + *(longlong *)(this + 0x40));
    uVar3 = *(ushort *)(*(longlong *)(this + 0x38) + 0xe + uVar7 * 0x18);
    lVar5 = *(longlong *)(*(longlong *)(this + 0x38) + uVar7 * 0x18);
    *(undefined8 *)(param_2 + 0x10) = 0;
    *(uint *)((ulonglong)uVar3 + (ulonglong)uVar2 * 4 + lVar5) = uVar4;
    LOCK();
    UNLOCK();
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0sqqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                       (uint *)&EvtInterruptClearStatus_Info,this + 0x10,
                       *(char **)(*(longlong *)(this + 0x40) + 8 + lVar8),(char)uVar4,
                       (char)*(undefined4 *)(param_2 + 8),(char)*(undefined4 *)(param_2 + 0x10));
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_sDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
                   &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                   "_GPIO_CONTROLLER_CHASSIS3::GpioClearActiveInterrupts",(char)uVar1,(char)uVar4,
                   (char)*(undefined4 *)(param_2 + 8),(char)*(undefined4 *)(param_2 + 0x10));
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  return 0;
}



===== GpioConfigurePinForInterrupt @ 140004924 =====

/* protected: long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioConfigurePinForInterrupt(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,unsigned short,unsigned short,enum _KINTERRUPT_MODE,enum
   _KINTERRUPT_POLARITY,unsigned char,unsigned char) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioConfigurePinForInterrupt
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,ushort param_2,
          ushort param_3,_KINTERRUPT_MODE param_4,_KINTERRUPT_POLARITY param_5,uchar param_6,
          uchar param_7)

{
  ulong uVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  longlong lVar10;
  long local_res10;
  undefined1 uVar11;
  undefined1 uVar12;
  
  local_res10 = 0;
  lVar10 = (ulonglong)param_2 * 0x20;
  uVar3 = (ulonglong)*(ushort *)(lVar10 + 2 + *(longlong *)(this + 0x40));
  puVar8 = (uint *)((longlong)(int)((uint)*(ushort *)(this + 0x30) * (uint)param_3) +
                    (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar3 * 0x18) +
                    (ulonglong)*(ushort *)(lVar10 + 6 + *(longlong *)(this + 0x40)) +
                   *(longlong *)(*(longlong *)(this + 0x38) + uVar3 * 0x18));
  uVar2 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(this + 8));
  uVar6 = *puVar8;
  uVar7 = puVar8[1];
  uVar3 = (ulonglong)*(ushort *)(lVar10 + 2 + *(longlong *)(this + 0x40));
  uVar1 = *(ulong *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xc + uVar3 * 0x18) +
                     (ulonglong)*(ushort *)(lVar10 + 4 + *(longlong *)(this + 0x40)) * 4 +
                    *(longlong *)(*(longlong *)(this + 0x38) + uVar3 * 0x18));
  bVar5 = (byte)param_3;
  if (*(int *)(*(longlong *)(param_1 + 0x28) + 8) == 0) {
    local_res10 = GpioValidatePinOwnership(this,param_2,param_3,uVar1,uVar6);
    if (local_res10 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                 &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                 "_GPIO_CONTROLLER_CHASSIS3::GpioConfigurePinForInterrupt");
      }
      goto LAB_140004e77;
    }
  }
  else {
    uVar3 = (ulonglong)param_3;
    *(uint *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar10) + 0x18 + uVar3 * 0x24) =
         uVar6;
    *(uint *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar10) + 0x1c + uVar3 * 0x24) =
         uVar7;
    *(undefined1 *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar10) + 0x15 + uVar3 * 0x24)
         = 1;
    uVar9 = 1 << (bVar5 & 0x1f);
    if ((uVar9 & uVar1) != 1) {
      uVar4 = (ulonglong)*(ushort *)(lVar10 + 2 + *(longlong *)(this + 0x40));
      *(uint *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xc + uVar4 * 0x18) +
                (ulonglong)*(ushort *)(lVar10 + 4 + *(longlong *)(this + 0x40)) * 4 +
               *(longlong *)(*(longlong *)(this + 0x38) + uVar4 * 0x18)) = uVar9 | uVar1;
      LOCK();
      UNLOCK();
      *(undefined1 *)
       (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar10) + 0x20 + uVar3 * 0x24) = 1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                   &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                   "_GPIO_CONTROLLER_CHASSIS3::GpioConfigurePinForInterrupt",(char)param_2,bVar5);
      }
    }
    if ((((uVar6 & 0x3c00) != 0) &&
        (uVar6 = uVar6 & 0xffffc3ff, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                  &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                  "_GPIO_CONTROLLER_CHASSIS3::GpioConfigurePinForInterrupt",(char)param_2,bVar5,0);
    }
  }
  uVar11 = (undefined1)param_4;
  uVar12 = (undefined1)param_5;
  if (param_4 == 0) {
    if (param_5 == 2) {
      uVar6 = uVar6 & 0xf9ffffff | 0x800000;
    }
    else {
      if (param_5 != 1) goto LAB_140004df6;
      uVar6 = uVar6 & 0xf97fffff;
    }
  }
  else {
    if (param_4 != 1) {
LAB_140004df6:
      if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
        McTemplateK0sqqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                         (uint *)&EvtInterruptConfigure_Error,this + 0x10,
                         *(char **)(*(longlong *)(this + 0x40) + 8 + lVar10),bVar5,uVar11,uVar12);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                 &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                 "_GPIO_CONTROLLER_CHASSIS3::GpioConfigurePinForInterrupt");
      }
      local_res10 = -0x3ffffff3;
      goto LAB_140004e77;
    }
    if (param_5 == 2) {
      uVar6 = uVar6 & 0xfbffffff | 0x2800000;
    }
    else if (param_5 == 1) {
      uVar6 = uVar6 & 0xfb7fffff | 0x2000000;
    }
    else {
      if (param_5 != 3) goto LAB_140004df6;
      uVar6 = uVar6 & 0xff7fffff | 0x6000000;
    }
  }
  if (param_6 != '\0') {
    if (param_6 == '\x01') {
      uVar7 = uVar7 & 0xfffff3ff | 0x3000;
    }
    else if (param_6 == '\x02') {
      uVar7 = uVar7 & 0xffffd3ff | 0x1000;
    }
    else if (param_6 == '\x03') {
      uVar7 = uVar7 & 0xffffc3ff;
    }
    else if ((Intel_iaLPSS2_GPIO2EnableBits & 8) != 0) {
      McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtPullConfigure_Warning,this + 0x10,
                      *(char **)(*(longlong *)(this + 0x40) + 8 + lVar10),bVar5,param_6);
    }
  }
  puVar8[1] = uVar7;
  LOCK();
  UNLOCK();
  *puVar8 = uVar6 & 0xef8ffdff | 0x100;
  LOCK();
  UNLOCK();
  if (param_7 == '\x01') {
    uVar6 = 1 << (bVar5 & 0x1f);
    uVar3 = (ulonglong)*(ushort *)(lVar10 + 2 + *(longlong *)(this + 0x40));
    *(uint *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xe + uVar3 * 0x18) +
              (ulonglong)*(ushort *)(lVar10 + 4 + *(longlong *)(this + 0x40)) * 4 +
             *(longlong *)(*(longlong *)(this + 0x38) + uVar3 * 0x18)) = uVar6;
    LOCK();
    UNLOCK();
  }
  else {
    uVar6 = 1 << (bVar5 & 0x1f);
  }
  uVar3 = (ulonglong)*(ushort *)(lVar10 + 2 + *(longlong *)(this + 0x40));
  puVar8 = (uint *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar3 * 0x18) +
                    (ulonglong)*(ushort *)(lVar10 + 4 + *(longlong *)(this + 0x40)) * 4 +
                   *(longlong *)(*(longlong *)(this + 0x38) + uVar3 * 0x18));
  *puVar8 = uVar6 | *puVar8;
  LOCK();
  UNLOCK();
  if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
    McTemplateK0sqqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                     (uint *)&EvtInterruptConfigure_Info,this + 0x10,
                     *(char **)(*(longlong *)(this + 0x40) + 8 + lVar10),bVar5,uVar11,uVar12);
  }
  if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
    McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtPullConfigure_Info,
                    this + 0x10,*(char **)(*(longlong *)(this + 0x40) + 8 + lVar10),bVar5,param_6);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                "_GPIO_CONTROLLER_CHASSIS3::GpioConfigurePinForInterrupt",bVar5,uVar11,uVar12);
  }
LAB_140004e77:
  KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(this + 8));
  KeLowerIrql(uVar2);
  return local_res10;
}



===== GpioConnectIoPins @ 140004eb0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_CONNECT_IO_PINS_PARAMETERS * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_CONNECT_IO_PINS_PARAMETERS *param_2)

{
  _GPIO_CONNECT_IO_PINS_PARAMETERS _Var1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  uint *puVar13;
  longlong lVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  long local_68;
  ushort local_60;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  iVar5 = *(int *)(param_2 + 0x14);
  uVar2 = *(ushort *)param_2;
  lVar7 = *(longlong *)(param_2 + 8);
  uVar3 = *(ushort *)(param_2 + 0x10);
  _Var1 = param_2[0x18];
  local_68 = GpioValidateBankRange(this,uVar2);
  if (local_68 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return local_68;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins");
    }
  }
  else {
    local_60 = 0;
    if (uVar3 != 0) {
      do {
        uVar4 = *(ushort *)(lVar7 + (ulonglong)local_60 * 2);
        local_68 = GpioValidatePinRange(this,uVar2,uVar4);
        uVar15 = (undefined1)uVar2;
        uVar16 = (undefined1)uVar4;
        if (local_68 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return local_68;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                       &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                       "_GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins",uVar15,uVar16);
          }
          break;
        }
        lVar14 = (ulonglong)uVar2 * 0x20;
        uVar8 = (ulonglong)*(ushort *)(lVar14 + 2 + *(longlong *)(this + 0x40));
        puVar13 = (uint *)((longlong)(int)((uint)*(ushort *)(this + 0x30) * (uint)uVar4) +
                           (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar8 * 0x18)
                           + (ulonglong)*(ushort *)(lVar14 + 6 + *(longlong *)(this + 0x40)) +
                          *(longlong *)(*(longlong *)(this + 0x38) + uVar8 * 0x18));
        uVar10 = *puVar13;
        uVar11 = puVar13[1];
        lVar12 = *(longlong *)(this + 0x40);
        if (*(int *)(*(longlong *)(param_1 + 0x28) + 8) == 0) {
          uVar8 = (ulonglong)*(ushort *)(lVar14 + 2 + lVar12);
          local_68 = GpioValidatePinMode(this,uVar2,uVar4,
                                         *(ulong *)((ulonglong)
                                                    *(ushort *)
                                                     (*(longlong *)(this + 0x38) + 0xc +
                                                     uVar8 * 0x18) +
                                                    (ulonglong)*(ushort *)(lVar14 + 4 + lVar12) * 4
                                                   + *(longlong *)
                                                      (*(longlong *)(this + 0x38) + uVar8 * 0x18)),
                                         uVar10);
          if (local_68 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return local_68;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                        &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                        "_GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins",uVar16);
            }
            break;
          }
        }
        else {
          uVar8 = (ulonglong)uVar4;
          *(uint *)(*(longlong *)(lVar14 + 0x10 + lVar12) + 0x18 + uVar8 * 0x24) = uVar10;
          *(uint *)(*(longlong *)(lVar14 + 0x10 + *(longlong *)(this + 0x40)) + 0x1c + uVar8 * 0x24)
               = uVar11;
          *(undefined1 *)
           (*(longlong *)(lVar14 + 0x10 + *(longlong *)(this + 0x40)) + 0x15 + uVar8 * 0x24) = 1;
          if (((((uVar10 & 0x3c00) != 0) &&
               (uVar10 = uVar10 & 0xffffc3ff,
               (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                       &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                       "_GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins",uVar15,uVar16);
          }
        }
        lVar12 = *(longlong *)(this + 0x40);
        uVar8 = (ulonglong)uVar4;
        iVar6 = *(int *)(*(longlong *)(lVar12 + 0x10 + lVar14) + uVar8 * 0x24);
        if (iVar6 != 0) {
          uVar17 = (undefined1)iVar6;
          if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
            McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                            (uint *)&EvtIoPinAlreadyConnected_Error,this + 0x10,
                            *(char **)((ulonglong)uVar2 * 0x20 + 8 + lVar12),uVar16,uVar17);
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                        &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                        "_GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins",uVar15,uVar16,uVar17);
          }
          local_68 = -0x3ffffff3;
          break;
        }
        if (_Var1 != (_GPIO_CONNECT_IO_PINS_PARAMETERS)0x0) {
          if (_Var1 == (_GPIO_CONNECT_IO_PINS_PARAMETERS)0x1) {
            uVar11 = uVar11 & 0xfffff3ff | 0x3000;
          }
          else if (_Var1 == (_GPIO_CONNECT_IO_PINS_PARAMETERS)0x2) {
            uVar11 = uVar11 & 0xffffd3ff | 0x1000;
          }
          else if (_Var1 == (_GPIO_CONNECT_IO_PINS_PARAMETERS)0x3) {
            uVar11 = uVar11 & 0xffffc3ff;
          }
          else if ((Intel_iaLPSS2_GPIO2EnableBits & 8) != 0) {
            McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                            (uint *)&EvtPullConfigure_Warning,this + 0x10,
                            *(char **)(lVar12 + 8 + lVar14),uVar16,_Var1);
            lVar12 = *(longlong *)(this + 0x40);
          }
        }
        uVar17 = (undefined1)iVar5;
        if (iVar5 == 1) {
          uVar10 = uVar10 & 0xfffffdff | 0x100;
        }
        else if (iVar5 == 2) {
          uVar9 = *(byte *)(*(longlong *)(lVar12 + 0x10 + lVar14) + 6 + uVar8 * 0x24) & 1;
          uVar10 = uVar9 | uVar10 & 0xfffffefe | 0x200;
          if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
            McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                            (uint *)&EvtIoPinOutputSet_Info,this + 0x10,
                            *(char **)(lVar12 + 8 + lVar14),uVar16,(char)uVar9);
          }
        }
        else {
          if ((Intel_iaLPSS2_GPIO2EnableBits & 8) != 0) {
            McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                            (uint *)&EvtIoUnknownConnectMode_Warning,this + 0x10,
                            *(char **)(lVar12 + 8 + lVar14),uVar16,uVar17);
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
                     &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                     "_GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins");
          }
        }
        puVar13[1] = uVar11;
        LOCK();
        UNLOCK();
        *puVar13 = uVar10;
        LOCK();
        UNLOCK();
        *(int *)(*(longlong *)(lVar14 + 0x10 + *(longlong *)(this + 0x40)) + uVar8 * 0x24) = iVar5;
        *(undefined1 *)
         (*(longlong *)(lVar14 + 0x10 + *(longlong *)(this + 0x40)) + 5 + uVar8 * 0x24) = 1;
        if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
          McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtIoConnect_Info,
                          this + 0x10,*(char **)(lVar14 + 8 + *(longlong *)(this + 0x40)),uVar16,
                          uVar17);
        }
        if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
          McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                          (uint *)&EvtPullConfigure_Info,this + 0x10,
                          *(char **)(lVar14 + 8 + *(longlong *)(this + 0x40)),uVar16,_Var1);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_sDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                       &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                       "_GPIO_CONTROLLER_CHASSIS3::GpioConnectIoPins",uVar15,uVar16,uVar17,_Var1);
        }
        local_60 = local_60 + 1;
      } while (local_60 < uVar3);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,local_68);
  }
  return local_68;
}



===== GpioControllerSpecificFunction @ 140005580 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioControllerSpecificFunction(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS *
   __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioControllerSpecificFunction
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS *param_2)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
              &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,0xc0000002);
    }
  }
  return -0x3ffffffe;
}



===== GpioDisableInterrupt @ 140005600 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioDisableInterrupt(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_DISABLE_INTERRUPT_PARAMETERS * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioDisableInterrupt
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_DISABLE_INTERRUPT_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ulong uVar3;
  longlong lVar4;
  code *pcVar5;
  long lVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  byte bVar10;
  _GPIO_DEVICE_CONTEXT *p_Var11;
  undefined *puVar12;
  longlong lVar13;
  undefined4 *puVar14;
  uint *puVar15;
  
  p_Var11 = param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    p_Var11 = (_GPIO_DEVICE_CONTEXT *)0x2c;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  pcVar5 = DAT_140016480;
  uVar1 = *(ushort *)param_2;
  uVar2 = *(ushort *)(param_2 + 2);
  __empty_global_delete(DAT_140016480,(__uint64)p_Var11);
  (*pcVar5)(param_1,uVar1);
  puVar12 = (undefined *)(ulonglong)uVar1;
  lVar6 = GpioValidateBankRange(this,uVar1);
  if (lVar6 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (puVar12 = (undefined *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_1400058c2;
    puVar12 = (undefined *)0x2d;
  }
  else {
    puVar12 = (undefined *)(ulonglong)uVar1;
    lVar6 = GpioValidatePinRange(this,uVar1,uVar2);
    if (-1 < lVar6) {
      lVar13 = (ulonglong)uVar1 * 0x20;
      uVar7 = (ulonglong)*(ushort *)(lVar13 + 2 + *(longlong *)(this + 0x40));
      uVar3 = *(ulong *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xc + uVar7 * 0x18) +
                         (ulonglong)*(ushort *)(lVar13 + 4 + *(longlong *)(this + 0x40)) * 4 +
                        *(longlong *)(*(longlong *)(this + 0x38) + uVar7 * 0x18));
      lVar8 = *(longlong *)(this + 0x40);
      bVar10 = (byte)uVar2;
      if (*(int *)(*(longlong *)(param_1 + 0x28) + 8) == 0) {
        uVar7 = (ulonglong)*(ushort *)(lVar13 + 2 + lVar8);
        puVar12 = (undefined *)(ulonglong)uVar1;
        lVar6 = GpioValidatePinOwnership
                          (this,uVar1,uVar2,uVar3,
                           *(ulong *)((longlong)(int)((uint)*(ushort *)(this + 0x30) * (uint)uVar2)
                                      + (ulonglong)
                                        *(ushort *)
                                         (*(longlong *)(this + 0x38) + 0x12 + uVar7 * 0x18) +
                                      (ulonglong)*(ushort *)(lVar13 + 6 + lVar8) +
                                     *(longlong *)(*(longlong *)(this + 0x38) + uVar7 * 0x18)));
        if (lVar6 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400058c2;
          puVar12 = (undefined *)0x2f;
          goto LAB_1400056bd;
        }
      }
      else {
        lVar4 = *(longlong *)(lVar13 + 0x10 + lVar8);
        uVar7 = (ulonglong)uVar2;
        if (*(char *)(lVar4 + 0x15 + uVar7 * 0x24) != '\0') {
          uVar9 = (ulonglong)*(ushort *)(lVar13 + 2 + lVar8);
          puVar14 = (undefined4 *)
                    ((longlong)(int)((uint)*(ushort *)(this + 0x30) * (uint)uVar2) +
                     (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar9 * 0x18) +
                     (ulonglong)*(ushort *)(lVar13 + 6 + lVar8) +
                    *(longlong *)(*(longlong *)(this + 0x38) + uVar9 * 0x18));
          puVar14[1] = *(undefined4 *)(lVar4 + 0x1c + uVar7 * 0x24);
          LOCK();
          UNLOCK();
          *puVar14 = *(undefined4 *)
                      (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar13) + 0x18 +
                      uVar7 * 0x24);
          LOCK();
          UNLOCK();
          *(undefined1 *)
           (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar13) + 0x15 + uVar7 * 0x24) = 0;
          lVar8 = *(longlong *)(this + 0x40);
          if (*(char *)(*(longlong *)(lVar8 + 0x10 + lVar13) + 0x20 + uVar7 * 0x24) != '\0') {
            uVar9 = (ulonglong)*(ushort *)(lVar8 + 2 + lVar13);
            *(ulong *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xc + uVar9 * 0x18) +
                       (ulonglong)*(ushort *)(lVar8 + 4 + lVar13) * 4 +
                      *(longlong *)(*(longlong *)(this + 0x38) + uVar9 * 0x18)) =
                 ~(1 << (bVar10 & 0x1f)) & uVar3;
            LOCK();
            UNLOCK();
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar13) + 0x20 + uVar7 * 0x24) = 0;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                       &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                       "_GPIO_CONTROLLER_CHASSIS3::GpioDisableInterrupt",(char)uVar1,bVar10);
          }
        }
      }
      uVar9 = (ulonglong)uVar2;
      uVar7 = (ulonglong)*(ushort *)(lVar13 + 2 + *(longlong *)(this + 0x40));
      puVar15 = (uint *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar7 * 0x18) +
                         (ulonglong)*(ushort *)(lVar13 + 4 + *(longlong *)(this + 0x40)) * 4 +
                        *(longlong *)(*(longlong *)(this + 0x38) + uVar7 * 0x18));
      *puVar15 = ~(1 << (bVar10 & 0x1f)) & *puVar15;
      LOCK();
      UNLOCK();
      lVar8 = *(longlong *)(this + 0x40);
      puVar12 = *(undefined **)(lVar8 + 0x10 + lVar13);
      if (puVar12[uVar9 * 0x24 + 5] == '\0') {
        *(undefined4 *)(puVar12 + uVar9 * 0x24) = 0;
        lVar8 = *(longlong *)(this + 0x40);
      }
      *(undefined1 *)(*(longlong *)(lVar8 + 0x10 + lVar13) + 4 + uVar9 * 0x24) = 0;
      if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
        puVar12 = &EvtInterruptDisable_Info;
        McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                       (uint *)&EvtInterruptDisable_Info,this + 0x10,
                       *(char **)(*(longlong *)(this + 0x40) + 8 + lVar13),bVar10);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar12 = (undefined *)0x31;
        WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                  &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                  "_GPIO_CONTROLLER_CHASSIS3::GpioDisableInterrupt",bVar10);
      }
      goto LAB_1400058c2;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400058c2;
    puVar12 = (undefined *)0x2e;
  }
LAB_1400056bd:
  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)puVar12,
           &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
           "_GPIO_CONTROLLER_CHASSIS3::GpioDisableInterrupt");
LAB_1400058c2:
  pcVar5 = DAT_140016488;
  __empty_global_delete(DAT_140016488,(__uint64)puVar12);
  (*pcVar5)(param_1,uVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar6);
  }
  return lVar6;
}



===== GpioDisconnectIoPins @ 140005a60 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioDisconnectIoPins(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_DISCONNECT_IO_PINS_PARAMETERS * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioDisconnectIoPins
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_DISCONNECT_IO_PINS_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  long lVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  longlong lVar14;
  ushort local_res20;
  undefined1 uVar15;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar6 = *(longlong *)(param_2 + 8);
  uVar3 = *(uint *)(param_2 + 0x10);
  uVar4 = *(uint *)(param_2 + 0x18);
  lVar8 = GpioValidateBankRange(this,uVar1);
  if (lVar8 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar8;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioDisconnectIoPins");
    }
  }
  else {
    local_res20 = 0;
    if (uVar3 != 0) {
      do {
        uVar2 = *(ushort *)(lVar6 + (ulonglong)local_res20 * 2);
        lVar8 = GpioValidatePinRange(this,uVar1,uVar2);
        if (lVar8 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar8;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                     &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                     "_GPIO_CONTROLLER_CHASSIS3::GpioDisconnectIoPins");
          }
          break;
        }
        lVar14 = (ulonglong)uVar1 * 0x20;
        uVar9 = (ulonglong)*(ushort *)(lVar14 + 2 + *(longlong *)(this + 0x40));
        puVar13 = (uint *)((longlong)(int)((uint)*(ushort *)(this + 0x30) * (uint)uVar2) +
                           (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar9 * 0x18)
                           + (ulonglong)*(ushort *)(lVar14 + 6 + *(longlong *)(this + 0x40)) +
                          *(longlong *)(*(longlong *)(this + 0x38) + uVar9 * 0x18));
        uVar12 = *puVar13;
        lVar10 = *(longlong *)(this + 0x40);
        uVar15 = (undefined1)uVar2;
        if (*(int *)(*(longlong *)(param_1 + 0x28) + 8) == 0) {
          uVar9 = (ulonglong)*(ushort *)(lVar10 + 2 + lVar14);
          lVar8 = GpioValidatePinMode(this,uVar1,uVar2,
                                      *(ulong *)((ulonglong)
                                                 *(ushort *)
                                                  (*(longlong *)(this + 0x38) + 0xc + uVar9 * 0x18)
                                                 + (ulonglong)*(ushort *)(lVar10 + 4 + lVar14) * 4 +
                                                *(longlong *)
                                                 (*(longlong *)(this + 0x38) + uVar9 * 0x18)),uVar12
                                     );
          if (lVar8 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return lVar8;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                         &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                         "_GPIO_CONTROLLER_CHASSIS3::GpioDisconnectIoPins",(char)uVar1,uVar15);
            }
            break;
          }
        }
        else {
          lVar10 = *(longlong *)(lVar10 + 0x10 + lVar14);
          uVar9 = (ulonglong)uVar2;
          if (*(char *)(lVar10 + 0x15 + uVar9 * 0x24) != '\0') {
            puVar13[1] = *(uint *)(lVar10 + 0x1c + uVar9 * 0x24);
            LOCK();
            UNLOCK();
            *puVar13 = *(uint *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar14) + 0x18 +
                                uVar9 * 0x24);
            LOCK();
            UNLOCK();
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar14) + 0x15 + uVar9 * 0x24) = 0;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
                         &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                         "_GPIO_CONTROLLER_CHASSIS3::GpioDisconnectIoPins",(char)uVar1,uVar15);
            }
          }
        }
        uVar9 = (ulonglong)uVar2;
        iVar5 = *(int *)(param_2 + 0x14);
        if (iVar5 == 1) {
          if ((((uVar4 & 1) == 0) &&
              (lVar10 = *(longlong *)(this + 0x40),
              *(char *)(*(longlong *)(lVar10 + 0x10 + lVar14) + 4 + uVar9 * 0x24) == '\0')) &&
             ((uVar12 >> 0x14 & 1) == 0)) {
            uVar12 = uVar12 | 0x200;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
              puVar11 = (uint *)&EvtIoInputBufferDisabled_Info;
LAB_140005d90:
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,puVar11,this + 0x10,
                             *(char **)(lVar10 + 8 + lVar14),uVar15);
            }
          }
          else if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
            puVar11 = (uint *)&EvtIoInputBufferLeftEnabled_Info;
            goto LAB_140005d8c;
          }
        }
        else if (iVar5 == 2) {
          if ((uVar4 & 1) == 0) {
            uVar12 = uVar12 | 0x100;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
              puVar11 = (uint *)&EvtIoOutputBufferDisabled_Info;
LAB_140005d8c:
              lVar10 = *(longlong *)(this + 0x40);
              goto LAB_140005d90;
            }
          }
          else if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
            puVar11 = (uint *)&EvtIoOutputBufferLeftEnabled_Info;
            goto LAB_140005d8c;
          }
        }
        else {
          uVar12 = uVar12 | 0x300;
          if ((Intel_iaLPSS2_GPIO2EnableBits & 8) != 0) {
            McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                            (uint *)&EvtIoUnknownDisconnectMode_Warning,this + 0x10,
                            *(char **)(*(longlong *)(this + 0x40) + 8 + lVar14),uVar15,(char)iVar5);
          }
        }
        *puVar13 = uVar12;
        LOCK();
        UNLOCK();
        lVar10 = *(longlong *)(this + 0x40);
        lVar7 = *(longlong *)(lVar10 + 0x10 + lVar14);
        if (*(char *)(lVar7 + 4 + uVar9 * 0x24) == '\0') {
          *(undefined4 *)(lVar7 + uVar9 * 0x24) = 0;
          lVar10 = *(longlong *)(this + 0x40);
        }
        *(undefined1 *)(*(longlong *)(lVar14 + 0x10 + lVar10) + 5 + uVar9 * 0x24) = 0;
        local_res20 = local_res20 + 1;
      } while (local_res20 < uVar3);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar8);
  }
  return lVar8;
}



===== GpioEnableInterrupt @ 140005f00 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioEnableInterrupt(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_ENABLE_INTERRUPT_PARAMETERS * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioEnableInterrupt
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_ENABLE_INTERRUPT_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  long lVar4;
  ulonglong uVar5;
  _GPIO_DEVICE_CONTEXT *p_Var6;
  longlong lVar7;
  
  p_Var6 = param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    p_Var6 = (_GPIO_DEVICE_CONTEXT *)0x26;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  pcVar3 = DAT_140016480;
  uVar1 = *(ushort *)param_2;
  uVar2 = *(ushort *)(param_2 + 2);
  __empty_global_delete(DAT_140016480,(__uint64)p_Var6);
  (*pcVar3)(param_1,uVar1);
  p_Var6 = (_GPIO_DEVICE_CONTEXT *)(ulonglong)uVar1;
  lVar4 = GpioValidateBankRange(this,uVar1);
  if (lVar4 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (p_Var6 = (_GPIO_DEVICE_CONTEXT *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_140006116;
    p_Var6 = (_GPIO_DEVICE_CONTEXT *)0x27;
  }
  else {
    p_Var6 = (_GPIO_DEVICE_CONTEXT *)(ulonglong)uVar1;
    lVar4 = GpioValidatePinRange(this,uVar1,uVar2);
    if (lVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140006116;
      p_Var6 = (_GPIO_DEVICE_CONTEXT *)0x28;
    }
    else {
      p_Var6 = param_1;
      lVar4 = GpioConfigurePinForInterrupt
                        (this,param_1,uVar1,uVar2,*(_KINTERRUPT_MODE *)(param_2 + 8),
                         *(_KINTERRUPT_POLARITY *)(param_2 + 0xc),(uchar)param_2[0x10],'\x01');
      if (-1 < lVar4) {
        uVar5 = (ulonglong)uVar2;
        lVar7 = (ulonglong)uVar1 * 0x20;
        p_Var6 = (_GPIO_DEVICE_CONTEXT *)(uVar5 * 9);
        *(undefined4 *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar7) + uVar5 * 0x24) = 1
        ;
        *(undefined1 *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar7) + 4 + uVar5 * 0x24)
             = 1;
        if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
          p_Var6 = (_GPIO_DEVICE_CONTEXT *)&EvtInterruptEnable_Info;
          McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                         (uint *)&EvtInterruptEnable_Info,this + 0x10,
                         *(char **)(*(longlong *)(this + 0x40) + 8 + lVar7),(char)uVar2);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          p_Var6 = (_GPIO_DEVICE_CONTEXT *)0x2a;
          WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                    &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                    "_GPIO_CONTROLLER_CHASSIS3::GpioEnableInterrupt",(char)uVar2);
        }
        goto LAB_140006116;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140006116;
      p_Var6 = (_GPIO_DEVICE_CONTEXT *)0x29;
    }
  }
  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)p_Var6,
           &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
           "_GPIO_CONTROLLER_CHASSIS3::GpioEnableInterrupt");
LAB_140006116:
  pcVar3 = DAT_140016488;
  __empty_global_delete(DAT_140016488,(__uint64)p_Var6);
  (*pcVar3)(param_1,uVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar4);
  }
  return lVar4;
}



===== GpioEvalDsmMethod @ 140006180 =====

/* protected: long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod(unsigned long,unsigned
   long,unsigned long,struct _ACPI_EVAL_OUTPUT_BUFFER_V1 __unaligned * __ptr64 * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod
          (_GPIO_CONTROLLER_CHASSIS3 *this,ulong param_1,ulong param_2,ulong param_3,
          _ACPI_EVAL_OUTPUT_BUFFER_V1 **param_4)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  undefined4 *_Dst;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *_Dst_00;
  undefined4 in_register_00000014;
  __uint64 _Var5;
  __uint64 _Var6;
  ulonglong uVar7;
  longlong local_78;
  undefined8 local_70;
  undefined8 local_68;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *local_60;
  ulonglong local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  
  _Var5 = CONCAT44(in_register_00000014,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    _Var5 = 0x87;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  local_78 = 0;
  _Dst = (undefined4 *)0x0;
  _Dst_00 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
  if (param_4 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 **)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x88,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod");
    }
    iVar3 = -0x3ffffff3;
    goto LAB_140006720;
  }
  *param_4 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
  _Var6 = *(__uint64 *)(this + 0x20);
  if (_Var6 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x89,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod");
    }
    iVar3 = -0x3ffffe7c;
    goto LAB_140006746;
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x150);
  __empty_global_delete(pcVar2,_Var5);
  lVar4 = (*pcVar2)(WdfDriverGlobals);
  if (lVar4 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8a,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod");
    }
    iVar3 = -0x3ffffff0;
    goto LAB_140006746;
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x7b8);
  __empty_global_delete(pcVar2,_Var6);
  iVar3 = (*pcVar2)(WdfDriverGlobals,0,lVar4,&local_70);
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8b,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod");
    }
    goto LAB_140006746;
  }
  _Dst = (undefined4 *)ExAllocatePoolWithTag(0x200,0x3c,0x49504749);
  if (_Dst == (undefined4 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8c,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod");
    }
    iVar3 = -0x3fffff66;
    goto LAB_140006746;
  }
  memset(_Dst,0,0x3c);
  *_Dst = 0x43696541;
  _Dst[1] = 0x4d53445f;
  _Dst[3] = 4;
  _Dst[4] = 0x100002;
  memcpy_s(_Dst + 5,0x10,&GUID_GPIO_MINIPORT_MMAP_DSM,0x10);
  if (*(ushort *)((longlong)_Dst + 0x12) < 4) {
    uVar7 = 4;
  }
  else {
    uVar7 = (ulonglong)*(ushort *)((longlong)_Dst + 0x12);
  }
  *(ulong *)((longlong)_Dst + uVar7 + 0x18) = param_1;
  *(undefined4 *)((longlong)_Dst + uVar7 + 0x14) = 0x40000;
  *(ulong *)((longlong)_Dst + uVar7 + 0x20) = param_2;
  *(undefined4 *)((longlong)_Dst + uVar7 + 0x1c) = 0x40000;
  *(ulong *)((longlong)_Dst + uVar7 + 0x28) = param_3;
  *(undefined4 *)((longlong)_Dst + uVar7 + 0x24) = 0x40000;
  _Dst[2] = 0x3c;
  local_50 = 1;
  local_40 = 0x3c;
  local_48 = _Dst;
  _Dst_00 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)ExAllocatePoolWithTag(0x200,0x200,0x49504749);
  if (_Dst_00 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar7 = 0x8d;
LAB_1400064aa:
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod");
    }
LAB_1400064c1:
    iVar3 = -0x3fffff66;
  }
  else {
    _Var5 = 0;
    local_68 = 1;
    local_58 = 0x200;
    local_60 = _Dst_00;
    memset(_Dst_00,0,0x200);
    *(undefined4 *)_Dst_00 = 0x426f6541;
    *(undefined8 *)(_Dst_00 + 4) = 0x200;
    *(undefined8 *)(_Dst_00 + 0xc) = 0x40003;
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x5d0);
    __empty_global_delete(pcVar2,_Var5);
    iVar3 = (*pcVar2)(WdfDriverGlobals,lVar4,local_70,0x32c004,&local_50,&local_68,0,&local_78);
    if (iVar3 == -0x7ffffffb) {
      uVar1 = *(uint *)(_Dst_00 + 4);
      ExFreePoolWithTag(_Dst_00,0x49504749);
      _Dst_00 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)
                ExAllocatePoolWithTag(0x200,(ulonglong)uVar1,0x49504749);
      if (_Dst_00 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar7 = 0x8e;
          goto LAB_1400064aa;
        }
        goto LAB_1400064c1;
      }
      _Var5 = 0;
      local_68 = 1;
      local_58 = (ulonglong)uVar1;
      local_60 = _Dst_00;
      memset(_Dst_00,0,(ulonglong)uVar1);
      *(undefined4 *)(_Dst_00 + 8) = 0;
      *(undefined4 *)_Dst_00 = 0x426f6541;
      *(uint *)(_Dst_00 + 4) = uVar1;
      *(undefined4 *)(_Dst_00 + 0x10) = 0;
      *(undefined4 *)(_Dst_00 + 0xc) = 0x40003;
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x5d0);
      __empty_global_delete(pcVar2,_Var5);
      iVar3 = (*pcVar2)(WdfDriverGlobals,lVar4,local_70,0x32c004,&local_50,&local_68,0,&local_78);
      if (-1 < iVar3) goto LAB_1400066c8;
      DbgPrintEx(0x65,3,"_DSM method returned failure with status = 0x%x\n",iVar3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8f,
                  &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                  "_GPIO_CONTROLLER_CHASSIS3::GpioEvalDsmMethod",(char)iVar3);
      }
    }
    else if (-1 < iVar3) {
LAB_1400066c8:
      if (local_78 != 0) {
        *param_4 = _Dst_00;
        _Dst_00 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
      }
    }
  }
LAB_140006720:
  if (_Dst != (undefined4 *)0x0) {
    ExFreePoolWithTag(_Dst,0x49504749);
  }
  if (_Dst_00 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    ExFreePoolWithTag(_Dst_00,0x49504749);
  }
LAB_140006746:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x90,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,iVar3);
  }
  return iVar3;
}



===== GpioGetSkippedPinPackage @ 140006794 =====

/* protected: long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioGetSkippedPinPackage(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_CHASSIS3::GpioGetSkippedPinPackage(_GPIO_CONTROLLER_CHASSIS3 *this)

{
  uint uVar1;
  ushort uVar2;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *p_Var3;
  long lVar4;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *p_Var5;
  ulonglong uVar6;
  ushort uVar7;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *local_res10;
  uint local_res18;
  uint local_res20;
  
  local_res18 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  local_res10 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
  lVar4 = GpioEvalDsmMethod(this,0,0,0,&local_res10);
  p_Var3 = local_res10;
  if ((lVar4 < 0) || (local_res10 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_sdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
                 &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                 "_GPIO_CONTROLLER_CHASSIS3::GpioGetSkippedPinPackage",(char)lVar4,(char)local_res10
                );
    }
  }
  else {
    p_Var5 = local_res10 + 0xc;
    if (*(int *)(local_res10 + 8) != 0) {
      while (*(short *)p_Var5 == 3) {
        if (*(short *)(p_Var5 + 4) != 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = 0x81;
            goto LAB_140006a97;
          }
          goto LAB_140006aaa;
        }
        uVar7 = *(ushort *)(p_Var5 + 8);
        local_res20 = (uint)uVar7;
        uVar1 = (uint)uVar7 / (uint)(byte)this[0x2c];
        uVar2 = (ushort)uVar1;
        local_res10 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)CONCAT44(local_res10._4_4_,uVar1);
        uVar7 = uVar7 - (byte)this[0x2c] * uVar2;
        lVar4 = GpioValidateBankRange(this,uVar2);
        if (lVar4 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = 0x82;
LAB_140006a33:
            WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                     &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                     "_GPIO_CONTROLLER_CHASSIS3::GpioGetSkippedPinPackage");
          }
          goto LAB_140006af2;
        }
        lVar4 = GpioValidatePinRange(this,(ushort)local_res10,uVar7);
        if (lVar4 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = 0x83;
            goto LAB_140006a33;
          }
          goto LAB_140006af2;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
                      &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                      "_GPIO_CONTROLLER_CHASSIS3::GpioGetSkippedPinPackage",(char)local_res20,
                      (char)local_res10,(char)uVar7);
        }
        *(undefined1 *)
         (*(longlong *)
           (((ulonglong)local_res10 & 0xffff) * 0x20 + 0x10 + *(longlong *)(this + 0x40)) + 0x14 +
         (ulonglong)uVar7 * 0x24) = 1;
        if (*(ushort *)(p_Var5 + 6) < 4) {
          uVar6 = 4;
        }
        else {
          uVar6 = (ulonglong)*(ushort *)(p_Var5 + 6);
        }
        p_Var5 = p_Var5 + 4 + uVar6 + 4;
        if (*(short *)p_Var5 != 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = 0x85;
            goto LAB_140006a97;
          }
          goto LAB_140006aaa;
        }
        if (*(ushort *)(p_Var5 + 2) < 4) {
          uVar6 = 4;
        }
        else {
          uVar6 = (ulonglong)*(ushort *)(p_Var5 + 2);
        }
        local_res18 = local_res18 + 1;
        p_Var5 = p_Var5 + uVar6 + 4;
        if (*(uint *)(p_Var3 + 8) <= local_res18) goto LAB_140006af2;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x80;
LAB_140006a97:
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                 &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                 "_GPIO_CONTROLLER_CHASSIS3::GpioGetSkippedPinPackage");
      }
LAB_140006aaa:
      lVar4 = -0x3febfff1;
    }
  }
LAB_140006af2:
  if (p_Var3 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    ExFreePoolWithTag(p_Var3,0x49504749);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x86,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar4);
  }
  return lVar4;
}



===== GpioMaskInterrupts @ 140006b50 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioMaskInterrupts(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_MASK_INTERRUPT_PARAMETERS * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioMaskInterrupts
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_MASK_INTERRUPT_PARAMETERS *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  long lVar5;
  ulonglong uVar6;
  uint *puVar7;
  longlong lVar8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  uVar2 = *(uint *)(param_2 + 8);
  *(ulonglong *)(param_2 + 0x10) = (ulonglong)uVar2;
  lVar5 = GpioValidateBankRange(this,uVar1);
  if (lVar5 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioMaskInterrupts");
    }
  }
  else {
    uVar4 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(*(undefined8 *)(this + 8));
    lVar8 = (ulonglong)uVar1 * 0x20;
    uVar6 = (ulonglong)*(ushort *)(lVar8 + 2 + *(longlong *)(this + 0x40));
    puVar7 = (uint *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar6 * 0x18) +
                      (ulonglong)*(ushort *)(lVar8 + 4 + *(longlong *)(this + 0x40)) * 4 +
                     *(longlong *)(*(longlong *)(this + 0x38) + uVar6 * 0x18));
    uVar3 = *puVar7;
    *(undefined8 *)(param_2 + 0x10) = 0;
    *puVar7 = ~uVar2 & uVar3;
    LOCK();
    UNLOCK();
    KeReleaseSpinLockFromDpcLevel(*(undefined8 *)(this + 8));
    KeLowerIrql(uVar4);
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0sqqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtInterruptMask_Info,
                       this + 0x10,*(char **)(*(longlong *)(this + 0x40) + 8 + lVar8),(char)uVar2,
                       (char)*(undefined4 *)(param_2 + 8),(char)*(undefined4 *)(param_2 + 0x10));
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                "_GPIO_CONTROLLER_CHASSIS3::GpioMaskInterrupts",(char)uVar2);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  return 0;
}



===== GpioPrepareController @ 140006d30 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioPrepareController(struct WDFDEVICE__
   * __ptr64,struct _GPIO_DEVICE_CONTEXT * __ptr64,struct WDFCMRESLIST__ * __ptr64,struct
   WDFCMRESLIST__ * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioPrepareController
          (_GPIO_CONTROLLER_CHASSIS3 *this,WDFDEVICE__ *param_1,_GPIO_DEVICE_CONTEXT *param_2,
          WDFCMRESLIST__ *param_3,WDFCMRESLIST__ *param_4)

{
  _GPIO_CONTROLLER_CHASSIS3 *p_Var1;
  code *pcVar2;
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  char *pcVar7;
  __uint64 _Var8;
  ulonglong uVar9;
  WDFCMRESLIST__ *pWVar10;
  uint uVar11;
  ushort uVar12;
  longlong lVar13;
  ushort uVar14;
  int iVar15;
  uint local_res8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_1 = (WDFDEVICE__ *)0xf;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  p_Var1 = this + 0x10;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    param_1 = (WDFDEVICE__ *)&EvtPrepareController_Start;
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtPrepareController_Start,
                 p_Var1);
  }
  puVar3 = WdfDriverGlobals;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  _Var8 = *WdfDriverGlobals;
  __empty_global_delete(pcVar2,(__uint64)param_1);
  uVar6 = (*pcVar2)(puVar3,_Var8,PTR__WDF_GPIO_DRIVER_CONTEXT_TYPE_INFO_140016060);
  *(undefined8 *)(this + 8) = uVar6;
  pcVar2 = *(code **)(*(longlong *)this + 0xa8);
  __empty_global_delete(pcVar2,_Var8);
  iVar4 = (*pcVar2)(this);
  if (iVar4 < 0) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                    (uint *)&EvtPrepareController_Layout_Error,p_Var1,iVar4);
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007229;
    uVar9 = 0x10;
  }
  else {
    uVar12 = 0;
    if (*(short *)(this + 0x28) != 0) {
      do {
        uVar14 = 0;
        lVar13 = (ulonglong)uVar12 * 0x20;
        if (*(short *)(lVar13 + *(longlong *)(this + 0x40)) != 0) {
          do {
            _Var8 = *(__uint64 *)(this + 0x40);
            uVar9 = (ulonglong)uVar14;
            uVar14 = uVar14 + 1;
            *(undefined1 *)(*(longlong *)(lVar13 + 0x10 + _Var8) + 0x14 + uVar9 * 0x24) = 0;
          } while (uVar14 < *(ushort *)(lVar13 + *(longlong *)(this + 0x40)));
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < *(ushort *)(this + 0x28));
    }
    GpioGetSkippedPinPackage(this);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x980);
    __empty_global_delete(pcVar2,_Var8);
    pWVar10 = param_4;
    uVar5 = (*pcVar2)(WdfDriverGlobals);
    local_res8 = 0;
    iVar15 = 0;
    uVar11 = 0;
    if (uVar5 != 0) {
      do {
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x988);
        __empty_global_delete(pcVar2,(__uint64)pWVar10);
        pWVar10 = param_4;
        pcVar7 = (char *)(*pcVar2)(WdfDriverGlobals,param_4,local_res8);
        if (*pcVar7 == '\x02') {
          if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
            pWVar10 = (WDFCMRESLIST__ *)&EvtPrepareController_IntVector_Info;
            McTemplateK0q((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                          (uint *)&EvtPrepareController_IntVector_Info,p_Var1,
                          *(undefined4 *)(pcVar7 + 8));
          }
          iVar15 = iVar15 + 1;
        }
        else if (*pcVar7 == '\x03') {
          if (*(ushort *)(this + 0x2a) <= uVar11) {
            iVar4 = -0x3fffff66;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
              McTemplateK0qxqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                               (uint *)&EvtPrepareController_MmioRes_Error,p_Var1,uVar11,
                               (char)*(undefined8 *)(pcVar7 + 4),(char)*(undefined4 *)(pcVar7 + 0xc)
                               ,0x9a);
            }
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007229;
            uVar9 = 0x14;
            iVar4 = -0x3fffff66;
            goto LAB_140006e58;
          }
          lVar13 = MmMapIoSpaceEx(*(undefined8 *)(pcVar7 + 4),*(undefined4 *)(pcVar7 + 0xc),0x204);
          if (lVar13 == 0) {
            iVar4 = -0x3fffff66;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
              McTemplateK0qxqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                               (uint *)&EvtPrepareController_MmioMap_Error,p_Var1,uVar11,
                               (char)*(undefined8 *)(pcVar7 + 4),(char)*(undefined4 *)(pcVar7 + 0xc)
                               ,0x9a);
            }
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007229;
            uVar9 = 0x11;
            iVar4 = -0x3fffff66;
            goto LAB_140006e58;
          }
          if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
            McTemplateK0qxqp((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPrepareController_MmioMapped_Info,p_Var1,uVar11,
                             (char)*(undefined8 *)(pcVar7 + 4),(char)*(undefined4 *)(pcVar7 + 0xc),
                             (char)lVar13);
          }
          uVar9 = (ulonglong)uVar11;
          pWVar10 = (WDFCMRESLIST__ *)(uVar9 * 3);
          *(longlong *)(*(longlong *)(this + 0x38) + uVar9 * 0x18) = lVar13;
          *(undefined4 *)(*(longlong *)(this + 0x38) + 8 + uVar9 * 0x18) =
               *(undefined4 *)(pcVar7 + 0xc);
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              pWVar10 = (WDFCMRESLIST__ *)0x12;
              WPP_SF_dDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                         &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,uVar11,
                         (char)*(undefined4 *)(pcVar7 + 4),(char)*(undefined4 *)(pcVar7 + 0xc));
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              pWVar10 = (WDFCMRESLIST__ *)0x13;
              WPP_SF_sdqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                          &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                          "_GPIO_CONTROLLER_CHASSIS3::GpioPrepareController",(char)uVar11,
                          (char)lVar13,(char)*(undefined4 *)(pcVar7 + 0xc));
            }
          }
          uVar11 = uVar11 + 1;
        }
        local_res8 = local_res8 + 1;
      } while (local_res8 < uVar5);
    }
    if ((uVar11 == *(ushort *)(this + 0x2a)) && (iVar15 == 1)) goto LAB_140007229;
    iVar4 = -0x3ffffda0;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0qqqqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                        (uint *)&EvtPrepareController_ResourceCnt_Error,p_Var1,uVar11,
                        (char)*(ushort *)(this + 0x2a),(char)iVar15,1,0x60);
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007229;
    uVar9 = 0x15;
    iVar4 = -0x3ffffda0;
  }
LAB_140006e58:
  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
           &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
           "_GPIO_CONTROLLER_CHASSIS3::GpioPrepareController");
LAB_140007229:
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtPrepareController_End,
                 p_Var1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,iVar4);
  }
  return iVar4;
}



===== GpioQueryActiveInterrupts @ 1400072a0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioQueryActiveInterrupts(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS * __ptr64) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioQueryActiveInterrupts
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  uVar2 = *(uint *)(param_2 + 8);
  lVar4 = GpioValidateBankRange(this,uVar1);
  if (lVar4 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar4;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioQueryActiveInterrupts");
    }
  }
  else {
    lVar7 = (ulonglong)uVar1 * 0x20;
    uVar5 = (ulonglong)*(ushort *)(lVar7 + 2 + *(longlong *)(this + 0x40));
    uVar3 = *(uint *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xe + uVar5 * 0x18) +
                      (ulonglong)*(ushort *)(lVar7 + 4 + *(longlong *)(this + 0x40)) * 4 +
                     *(longlong *)(*(longlong *)(this + 0x38) + uVar5 * 0x18));
    uVar6 = uVar3 & uVar2;
    uVar8 = (undefined1)uVar6;
    uVar9 = (undefined1)uVar3;
    uVar10 = (undefined1)uVar2;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0sqqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                       (uint *)&EvtInterruptQueryActive_Info,this + 0x10,
                       *(char **)(lVar7 + 8 + *(longlong *)(this + 0x40)),uVar8,uVar9,uVar10);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                  &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                  "_GPIO_CONTROLLER_CHASSIS3::GpioQueryActiveInterrupts",uVar8,uVar9,uVar10);
    }
    *(ulonglong *)(param_2 + 0x10) = (ulonglong)uVar6;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar4);
  }
  return lVar4;
}



===== GpioQueryControllerBasicInformation @ 140007470 =====

/* public: virtual long __cdecl
   _GPIO_CONTROLLER_CHASSIS3::GpioQueryControllerBasicInformation(struct _GPIO_DEVICE_CONTEXT *
   __ptr64,struct _CLIENT_CONTROLLER_BASIC_INFORMATION * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioQueryControllerBasicInformation
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _CLIENT_CONTROLLER_BASIC_INFORMATION *param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  *(undefined4 *)param_2 = 0x100001;
  *(undefined2 *)(param_2 + 4) = *(undefined2 *)(this + 0x2e);
  *(_GPIO_CONTROLLER_CHASSIS3 *)(param_2 + 6) = this[0x2c];
  *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xffffffe1 | 0x61;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtQueryController_Info,
                 this + 0x10);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  return 0;
}



===== GpioQueryEnabledInterrupts @ 140007550 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioQueryEnabledInterrupts(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS * __ptr64)
   __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioQueryEnabledInterrupts
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS *param_2)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 uVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar3 = GpioValidateBankRange(this,uVar1);
  if (lVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioQueryEnabledInterrupts");
    }
  }
  else {
    lVar5 = (ulonglong)uVar1 * 0x20;
    uVar4 = (ulonglong)*(ushort *)(lVar5 + 2 + *(longlong *)(this + 0x40));
    uVar2 = *(uint *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar4 * 0x18) +
                      (ulonglong)*(ushort *)(lVar5 + 4 + *(longlong *)(this + 0x40)) * 4 +
                     *(longlong *)(*(longlong *)(this + 0x38) + uVar4 * 0x18));
    uVar6 = (undefined1)uVar2;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                     (uint *)&EvtInterruptQueryEnabled_Info,this + 0x10,
                     *(char **)(lVar5 + 8 + *(longlong *)(this + 0x40)),uVar6);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                 &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                 "_GPIO_CONTROLLER_CHASSIS3::GpioQueryEnabledInterrupts",(char)uVar1,uVar6);
    }
    *(ulonglong *)(param_2 + 8) = (ulonglong)uVar2;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar3);
  }
  return lVar3;
}



===== GpioReadGpioPins @ 1400076f0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioReadGpioPins(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,void * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioReadGpioPins
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,void *param_2)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  long lVar9;
  byte *pbVar10;
  byte bVar11;
  ulonglong uVar12;
  uint *puVar13;
  longlong lVar14;
  int iVar15;
  bool bVar16;
  ushort local_res18;
  undefined1 uVar17;
  undefined1 uVar18;
  byte bVar19;
  byte *local_50;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar2 = *(ushort *)param_2;
  lVar7 = *(longlong *)((longlong)param_2 + 8);
  local_50 = *(byte **)((longlong)param_2 + 0x18);
  uVar4 = *(uint *)((longlong)param_2 + 0x10);
  lVar9 = GpioValidateBankRange(this,uVar2);
  uVar17 = (undefined1)uVar2;
  if (lVar9 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                "_GPIO_CONTROLLER_CHASSIS3::GpioReadGpioPins",uVar17);
    }
  }
  else {
    iVar15 = 0;
    local_res18 = 0;
    if (uVar4 != 0) {
      do {
        uVar3 = *(ushort *)(lVar7 + (ulonglong)local_res18 * 2);
        lVar9 = GpioValidatePinRange(this,uVar2,uVar3);
        uVar18 = (undefined1)uVar3;
        if (lVar9 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar12 = 0x5d;
LAB_140007aee:
            WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                       &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                       "_GPIO_CONTROLLER_CHASSIS3::GpioReadGpioPins",uVar17,uVar18);
          }
          break;
        }
        lVar14 = (ulonglong)uVar2 * 0x20;
        uVar12 = (ulonglong)*(ushort *)(lVar14 + 2 + *(longlong *)(this + 0x40));
        uVar5 = *(ulong *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xc + uVar12 * 0x18)
                           + (ulonglong)*(ushort *)(lVar14 + 4 + *(longlong *)(this + 0x40)) * 4 +
                          *(longlong *)(*(longlong *)(this + 0x38) + uVar12 * 0x18));
        uVar12 = (ulonglong)*(ushort *)(lVar14 + 2 + *(longlong *)(this + 0x40));
        puVar13 = (uint *)((longlong)(int)((uint)*(ushort *)(this + 0x30) * (uint)uVar3) +
                           (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar12 * 0x18)
                           + (ulonglong)*(ushort *)(lVar14 + 6 + *(longlong *)(this + 0x40)) +
                          *(longlong *)(*(longlong *)(this + 0x38) + uVar12 * 0x18));
        uVar6 = *puVar13;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
                   &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,puVar13);
        }
        lVar9 = GpioValidatePinMode(this,uVar2,uVar3,uVar5,uVar6);
        if (lVar9 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar12 = 0x5f;
            goto LAB_140007aee;
          }
          break;
        }
        lVar8 = *(longlong *)(lVar14 + 0x10 + *(longlong *)(this + 0x40));
        if ((*(char *)(lVar8 + 5 + (ulonglong)uVar3 * 0x24) == '\0') ||
           (*(int *)(lVar8 + (ulonglong)uVar3 * 0x24) == 0)) {
          if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
            McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                           (uint *)&EvtIoPinNotConnected_Error,this + 0x10,
                           *(char **)((ulonglong)uVar2 * 0x20 + 8 + *(longlong *)(this + 0x40)),
                           uVar18);
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar12 = 0x60;
            goto LAB_140007aee;
          }
          break;
        }
        if (iVar15 == 0) {
          *local_50 = 0;
          bVar11 = 0;
        }
        else {
          bVar11 = *local_50;
        }
        bVar19 = (byte)(uVar6 >> 1);
        bVar16 = iVar15 != 7;
        *local_50 = (bVar19 & 1) << ((byte)iVar15 & 0x1f) | bVar11;
        iVar1 = iVar15 + 1;
        pbVar10 = local_50 + 1;
        iVar15 = 0;
        if (bVar16) {
          pbVar10 = local_50;
          iVar15 = iVar1;
        }
        bVar19 = bVar19 & 1;
        if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
          McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                          (uint *)&EvtIoPinInputGet_Info,this + 0x10,
                          *(char **)(lVar14 + 8 + *(longlong *)(this + 0x40)),uVar18,bVar19);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
                      &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                      "_GPIO_CONTROLLER_CHASSIS3::GpioReadGpioPins",uVar17,uVar18,bVar19);
        }
        local_res18 = local_res18 + 1;
        local_50 = pbVar10;
      } while (local_res18 < uVar4);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,0);
  }
  return 0;
}



===== GpioReconfigureInterrupt @ 140007b60 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioReconfigureInterrupt(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS * __ptr64) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioReconfigureInterrupt
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS *param_2)

{
  long lVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  lVar1 = GpioConfigurePinForInterrupt
                    (this,param_1,*(ushort *)param_2,*(ushort *)(param_2 + 2),
                     *(_KINTERRUPT_MODE *)(param_2 + 4),*(_KINTERRUPT_POLARITY *)(param_2 + 8),'\0',
                     '\x01');
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar1);
  }
  return lVar1;
}



===== GpioReleaseController @ 140007c30 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioReleaseController(struct WDFDEVICE__
   * __ptr64,struct _GPIO_DEVICE_CONTEXT * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioReleaseController
          (_GPIO_CONTROLLER_CHASSIS3 *this,WDFDEVICE__ *param_1,_GPIO_DEVICE_CONTEXT *param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  ulonglong uVar4;
  uint uVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_1 = (WDFDEVICE__ *)0x17;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    param_1 = (WDFDEVICE__ *)&EvtReleaseController_Start;
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtReleaseController_Start,
                 this + 0x10);
  }
  if ((*(longlong *)(this + 0x38) != 0) && (uVar5 = 0, *(short *)(this + 0x2a) != 0)) {
    do {
      uVar4 = (ulonglong)uVar5;
      param_1 = (WDFDEVICE__ *)(uVar4 * 3);
      if ((*(longlong *)(*(longlong *)(this + 0x38) + uVar4 * 0x18) != 0) &&
         (uVar1 = *(uint *)(*(longlong *)(this + 0x38) + 8 + uVar4 * 0x18), uVar1 != 0)) {
        param_1 = (WDFDEVICE__ *)(ulonglong)uVar1;
        MmUnmapIoSpace();
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(ushort *)(this + 0x2a));
  }
  pcVar2 = *(code **)(*(longlong *)this + 0xb0);
  __empty_global_delete(pcVar2,(__uint64)param_1);
  lVar3 = (*pcVar2)(this);
  if ((Intel_iaLPSS2_GPIO2EnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtReleaseController_End,
                 this + 0x10);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar3);
  }
  return lVar3;
}



===== GpioRestoreBankHardwareContext @ 140007d60 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioRestoreBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioRestoreBankHardwareContext
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  longlong lVar2;
  long lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ushort uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar3 = GpioValidateBankRange(this,uVar1);
  if (lVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_140007f88;
    uVar5 = 0x75;
  }
  else {
    lVar9 = *(longlong *)(this + 0x40);
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(char *)(lVar6 + 0x18 + lVar9) != '\x01') goto LAB_140007f88;
    uVar7 = 0;
    if (*(short *)(lVar6 + lVar9) != 0) {
      do {
        lVar2 = *(longlong *)(lVar6 + 0x10 + lVar9);
        uVar5 = (ulonglong)uVar7;
        if (*(char *)(lVar2 + 7 + uVar5 * 0x24) == '\x01') {
          uVar4 = (ulonglong)*(ushort *)(lVar6 + 2 + lVar9);
          puVar8 = (undefined4 *)
                   ((longlong)(int)((uint)*(ushort *)(this + 0x30) * (uint)uVar7) +
                    (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar4 * 0x18) +
                    (ulonglong)*(ushort *)(lVar6 + 6 + lVar9) +
                   *(longlong *)(*(longlong *)(this + 0x38) + uVar4 * 0x18));
          puVar8[1] = *(undefined4 *)(lVar2 + 0xc + uVar5 * 0x24);
          LOCK();
          UNLOCK();
          *puVar8 = *(undefined4 *)
                     (*(longlong *)(lVar6 + 0x10 + *(longlong *)(this + 0x40)) + 8 + uVar5 * 0x24);
          LOCK();
          UNLOCK();
          *(undefined1 *)
           (*(longlong *)(lVar6 + 0x10 + *(longlong *)(this + 0x40)) + 7 + uVar5 * 0x24) = 0;
          if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
            McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                           (uint *)&EvtPinContextRestored_Verbose,this + 0x10,
                           *(char **)(lVar6 + 8 + *(longlong *)(this + 0x40)),(char)uVar7);
          }
        }
        lVar9 = *(longlong *)(this + 0x40);
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(lVar6 + lVar9));
    }
    uVar5 = (ulonglong)*(ushort *)(lVar6 + 2 + lVar9);
    *(undefined4 *)
     ((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar5 * 0x18) +
      (ulonglong)*(ushort *)(lVar6 + 4 + lVar9) * 4 +
     *(longlong *)(*(longlong *)(this + 0x38) + uVar5 * 0x18)) =
         *(undefined4 *)(lVar6 + 0x1c + lVar9);
    LOCK();
    UNLOCK();
    *(undefined1 *)(lVar6 + 0x18 + *(longlong *)(this + 0x40)) = 0;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                    (uint *)&EvtBankContextRestored_Info,this + 0x10,
                    *(char **)(lVar6 + 8 + *(longlong *)(this + 0x40)));
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
       ) goto LAB_140007f88;
    uVar5 = 0x76;
  }
  WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
            "_GPIO_CONTROLLER_CHASSIS3::GpioRestoreBankHardwareContext",(char)uVar1);
LAB_140007f88:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar3);
  }
  return;
}



===== GpioSaveBankHardwareContext @ 140007fe0 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioSaveBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioSaveBankHardwareContext
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  long lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ushort uVar7;
  longlong lVar8;
  uint *puVar9;
  longlong lVar10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar4 = GpioValidateBankRange(this,uVar1);
  if (lVar4 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_14000827f;
    uVar6 = 0x79;
  }
  else {
    lVar10 = *(longlong *)(this + 0x40);
    uVar6 = 0;
    lVar8 = (ulonglong)uVar1 * 0x20;
    if (*(short *)(lVar8 + lVar10) != 0) {
      do {
        lVar3 = *(longlong *)(lVar8 + 0x10 + lVar10);
        if (*(char *)(lVar3 + 0x14 + uVar6 * 0x24) == '\x01') {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x7a;
LAB_1400080dc:
            WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                       &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                       "_GPIO_CONTROLLER_CHASSIS3::GpioSaveBankHardwareContext",(char)uVar1,
                       (char)uVar6);
          }
        }
        else if (*(int *)(lVar3 + uVar6 * 0x24) == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x7b;
            goto LAB_1400080dc;
          }
        }
        else {
          uVar5 = (ulonglong)*(ushort *)(lVar8 + 2 + lVar10);
          puVar9 = (uint *)((longlong)(int)((uint)*(ushort *)(this + 0x30) * (int)uVar6) +
                            (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar5 * 0x18)
                            + (ulonglong)*(ushort *)(lVar8 + 6 + lVar10) +
                           *(longlong *)(*(longlong *)(this + 0x38) + uVar5 * 0x18));
          uVar2 = *puVar9;
          if ((uVar2 & 0x3c00) == 0) {
            *(uint *)(*(longlong *)(lVar8 + 0x10 + *(longlong *)(this + 0x40)) + 8 + uVar6 * 0x24) =
                 uVar2;
            *(uint *)(*(longlong *)(lVar8 + 0x10 + *(longlong *)(this + 0x40)) + 0xc + uVar6 * 0x24)
                 = puVar9[1];
            *(undefined1 *)
             (*(longlong *)(lVar8 + 0x10 + *(longlong *)(this + 0x40)) + 7 + uVar6 * 0x24) = 1;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextSaved_Verbose,this + 0x10,
                             *(char **)(lVar8 + 8 + *(longlong *)(this + 0x40)),(char)uVar6);
            }
          }
        }
        lVar10 = *(longlong *)(this + 0x40);
        uVar7 = (short)uVar6 + 1;
        uVar6 = (ulonglong)uVar7;
      } while (uVar7 < *(ushort *)(lVar8 + lVar10));
    }
    uVar6 = (ulonglong)*(ushort *)(lVar8 + 2 + lVar10);
    *(undefined4 *)(lVar8 + 0x1c + *(longlong *)(this + 0x40)) =
         *(undefined4 *)
          ((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar6 * 0x18) +
           (ulonglong)*(ushort *)(lVar8 + 4 + lVar10) * 4 +
          *(longlong *)(*(longlong *)(this + 0x38) + uVar6 * 0x18));
    *(undefined1 *)(lVar8 + 0x18 + *(longlong *)(this + 0x40)) = 1;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtBankContextSaved_Info,
                    this + 0x10,*(char **)(lVar8 + 8 + *(longlong *)(this + 0x40)));
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
       ) goto LAB_14000827f;
    uVar6 = 0x7c;
  }
  WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
            "_GPIO_CONTROLLER_CHASSIS3::GpioSaveBankHardwareContext",(char)uVar1);
LAB_14000827f:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar4);
  }
  return;
}



===== GpioStartController @ 1400082d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioStartController(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,unsigned char,enum _WDF_POWER_DEVICE_STATE) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioStartController
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,uchar param_2,
          _WDF_POWER_DEVICE_STATE param_3)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  ulonglong uVar4;
  longlong lVar5;
  _GPIO_DEVICE_CONTEXT *p_Var6;
  ushort uVar7;
  ushort uVar8;
  longlong lVar9;
  undefined1 local_68 [32];
  ushort local_48 [8];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_68;
  p_Var6 = param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    p_Var6 = (_GPIO_DEVICE_CONTEXT *)0x1b;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar7 = 0;
  if (param_1 == (_GPIO_DEVICE_CONTEXT *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioStartController");
    }
    lVar3 = -0x3ffffff3;
  }
  else {
    if (param_2 == '\0') {
      uVar7 = 0;
      if (*(short *)(this + 0x28) != 0) {
        do {
          lVar9 = (ulonglong)uVar7 * 0x20;
          uVar4 = (ulonglong)*(ushort *)(lVar9 + 2 + *(longlong *)(this + 0x40));
          *(undefined4 *)
           ((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar4 * 0x18) +
            (ulonglong)*(ushort *)(lVar9 + 4 + *(longlong *)(this + 0x40)) * 4 +
           *(longlong *)(*(longlong *)(this + 0x38) + uVar4 * 0x18)) = 0;
          LOCK();
          UNLOCK();
          uVar4 = (ulonglong)*(ushort *)(lVar9 + 2 + *(longlong *)(this + 0x40));
          *(undefined4 *)
           ((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xe + uVar4 * 0x18) +
            (ulonglong)*(ushort *)(lVar9 + 4 + *(longlong *)(this + 0x40)) * 4 +
           *(longlong *)(*(longlong *)(this + 0x38) + uVar4 * 0x18)) = 0xffffffff;
          LOCK();
          UNLOCK();
          lVar5 = *(longlong *)(this + 0x40);
          uVar8 = 0;
          if (*(short *)(lVar9 + lVar5) != 0) {
            do {
              uVar4 = (ulonglong)uVar8;
              uVar8 = uVar8 + 1;
              *(undefined4 *)(*(longlong *)(lVar9 + 0x10 + lVar5) + uVar4 * 0x24) = 0;
              *(undefined1 *)
               (*(longlong *)(lVar9 + 0x10 + *(longlong *)(this + 0x40)) + 5 + uVar4 * 0x24) = 0;
              *(undefined1 *)
               (*(longlong *)(lVar9 + 0x10 + *(longlong *)(this + 0x40)) + 4 + uVar4 * 0x24) = 0;
              *(undefined1 *)
               (*(longlong *)(lVar9 + 0x10 + *(longlong *)(this + 0x40)) + 6 + uVar4 * 0x24) = 0;
              *(undefined1 *)
               (*(longlong *)(lVar9 + 0x10 + *(longlong *)(this + 0x40)) + 7 + uVar4 * 0x24) = 0;
              *(undefined1 *)
               (*(longlong *)(lVar9 + 0x10 + *(longlong *)(this + 0x40)) + 0x15 + uVar4 * 0x24) = 0;
              *(undefined1 *)
               (*(longlong *)(lVar9 + 0x10 + *(longlong *)(this + 0x40)) + 0x20 + uVar4 * 0x24) = 0;
              lVar5 = *(longlong *)(this + 0x40);
            } while (uVar8 < *(ushort *)(lVar9 + lVar5));
          }
          uVar7 = uVar7 + 1;
          *(undefined1 *)(lVar9 + 0x18 + lVar5) = 0;
        } while (uVar7 < *(ushort *)(this + 0x28));
      }
    }
    else if (*(short *)(this + 0x28) != 0) {
      do {
        plVar1 = *(longlong **)(param_1 + 0x20);
        pcVar2 = *(code **)(*plVar1 + 0x98);
        local_48[0] = uVar7;
        __empty_global_delete(pcVar2,(__uint64)p_Var6);
        p_Var6 = param_1;
        (*pcVar2)(plVar1,param_1,local_48);
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(this + 0x28));
    }
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtStartController_Info,
                   this + 0x10);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== GpioStopController @ 140008540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioStopController(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,unsigned char,enum _WDF_POWER_DEVICE_STATE) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioStopController
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,uchar param_2,
          _WDF_POWER_DEVICE_STATE param_3)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  ulonglong uVar4;
  _GPIO_DEVICE_CONTEXT *p_Var5;
  ushort uVar6;
  longlong lVar7;
  undefined1 local_68 [32];
  ushort local_48 [8];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_68;
  p_Var5 = param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    p_Var5 = (_GPIO_DEVICE_CONTEXT *)0x1e;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar6 = 0;
  if (param_1 == (_GPIO_DEVICE_CONTEXT *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
               &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
               "_GPIO_CONTROLLER_CHASSIS3::GpioStopController");
    }
    lVar3 = -0x3ffffff3;
  }
  else {
    if (param_2 == '\0') {
      uVar6 = 0;
      if (*(short *)(this + 0x28) != 0) {
        do {
          lVar7 = (ulonglong)uVar6 * 0x20;
          uVar4 = (ulonglong)*(ushort *)(lVar7 + 2 + *(longlong *)(this + 0x40));
          *(undefined4 *)
           ((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x10 + uVar4 * 0x18) +
            (ulonglong)*(ushort *)(lVar7 + 4 + *(longlong *)(this + 0x40)) * 4 +
           *(longlong *)(*(longlong *)(this + 0x38) + uVar4 * 0x18)) = 0;
          LOCK();
          UNLOCK();
          uVar4 = (ulonglong)*(ushort *)(lVar7 + 2 + *(longlong *)(this + 0x40));
          *(undefined4 *)
           ((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xe + uVar4 * 0x18) +
            (ulonglong)*(ushort *)(lVar7 + 4 + *(longlong *)(this + 0x40)) * 4 +
           *(longlong *)(*(longlong *)(this + 0x38) + uVar4 * 0x18)) = 0xffffffff;
          LOCK();
          UNLOCK();
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(ushort *)(this + 0x28));
      }
    }
    else if (*(short *)(this + 0x28) != 0) {
      do {
        plVar1 = *(longlong **)(param_1 + 0x20);
        pcVar2 = *(code **)(*plVar1 + 0xa0);
        local_48[0] = uVar6;
        __empty_global_delete(pcVar2,(__uint64)p_Var5);
        p_Var5 = param_1;
        (*pcVar2)(plVar1,param_1,local_48);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(ushort *)(this + 0x28));
    }
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtStopController_Info,
                   this + 0x10);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
              &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== GpioUnmaskInterrupt @ 140008720 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioUnmaskInterrupt(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_ENABLE_INTERRUPT_PARAMETERS * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioUnmaskInterrupt
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_ENABLE_INTERRUPT_PARAMETERS *param_2)

{
  ushort uVar1;
  ushort uVar2;
  long lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  uVar2 = *(ushort *)(param_2 + 2);
  lVar3 = GpioValidateBankRange(this,uVar1);
  if (lVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar3;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
       ) goto LAB_140008916;
    uVar4 = 0x39;
  }
  else {
    lVar3 = GpioValidatePinRange(this,uVar1,uVar2);
    if (lVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return lVar3;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140008916;
      uVar4 = 0x3a;
    }
    else {
      lVar3 = GpioConfigurePinForInterrupt
                        (this,param_1,uVar1,uVar2,*(_KINTERRUPT_MODE *)(param_2 + 8),
                         *(_KINTERRUPT_POLARITY *)(param_2 + 0xc),(uchar)param_2[0x10],'\0');
      if (-1 < lVar3) {
        lVar5 = (ulonglong)uVar1 * 0x20;
        *(undefined4 *)
         (*(longlong *)(lVar5 + 0x10 + *(longlong *)(this + 0x40)) + (ulonglong)uVar2 * 0x24) = 1;
        *(undefined1 *)
         (*(longlong *)(lVar5 + 0x10 + *(longlong *)(this + 0x40)) + 4 + (ulonglong)uVar2 * 0x24) =
             1;
        if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
          McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                         (uint *)&EvtInterruptUnmask_Info,this + 0x10,
                         *(char **)(lVar5 + 8 + *(longlong *)(this + 0x40)),(char)uVar2);
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar3;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                    &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                    "_GPIO_CONTROLLER_CHASSIS3::GpioUnmaskInterrupt",(char)uVar2);
        }
        goto LAB_140008916;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return lVar3;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140008916;
      uVar4 = 0x3b;
    }
  }
  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
           "_GPIO_CONTROLLER_CHASSIS3::GpioUnmaskInterrupt");
LAB_140008916:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,lVar3);
  }
  return lVar3;
}



===== GpioValidateBankRange @ 140008964 =====

/* protected: long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange(unsigned short) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange(_GPIO_CONTROLLER_CHASSIS3 *this,ushort param_1)

{
  long lVar1;
  
  if (param_1 < *(ushort *)(this + 0x28)) {
    lVar1 = 0;
  }
  else {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                    (uint *)&EvtChassis3_InvalidBankNumber_Error,this + 0x10,(uint)param_1);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                "_GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange",(char)param_1);
    }
    lVar1 = -0x3ffffff3;
  }
  return lVar1;
}



===== GpioValidatePinMode @ 1400089ec =====

/* protected: long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioValidatePinMode(unsigned short,unsigned
   short,unsigned long,unsigned long) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioValidatePinMode
          (_GPIO_CONTROLLER_CHASSIS3 *this,ushort param_1,ushort param_2,ulong param_3,ulong param_4
          )

{
  long lVar1;
  uint uVar2;
  undefined1 uVar3;
  
  uVar2 = param_4 >> 10 & 0xf;
  if (uVar2 == 0) {
    lVar1 = 0;
  }
  else {
    uVar3 = (undefined1)uVar2;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtChassis3_InvalidPinMode_Error,this + 0x10,
                      *(char **)((ulonglong)param_1 * 0x20 + 8 + *(longlong *)(this + 0x40)),
                      (char)param_2,uVar3);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                "_GPIO_CONTROLLER_CHASSIS3::GpioValidatePinMode",uVar3);
    }
    lVar1 = -0x3ffffff3;
  }
  return lVar1;
}



===== GpioValidatePinOwnership @ 140008a90 =====

/* protected: long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioValidatePinOwnership(unsigned
   short,unsigned short,unsigned long,unsigned long) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioValidatePinOwnership
          (_GPIO_CONTROLLER_CHASSIS3 *this,ushort param_1,ushort param_2,ulong param_3,ulong param_4
          )

{
  byte bVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  uint uVar4;
  
  bVar1 = (byte)param_2;
  if ((param_3 >> (bVar1 & 0x1f) & 1) == 0) {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtChassis3_InvalidPinOwnership_Error,this + 0x10,
                      *(char **)((ulonglong)param_1 * 0x20 + 8 + *(longlong *)(this + 0x40)),bVar1,0
                     );
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    uVar2 = 0xc;
    uVar3 = 0;
  }
  else {
    uVar4 = param_4 >> 10 & 0xf;
    uVar3 = (undefined1)uVar4;
    if (uVar4 == 0) {
      return 0;
    }
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtChassis3_InvalidPinMode_Error,this + 0x10,
                      *(char **)((ulonglong)param_1 * 0x20 + 8 + *(longlong *)(this + 0x40)),bVar1,
                      uVar3);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    uVar2 = 0xd;
  }
  WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
              &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
              "_GPIO_CONTROLLER_CHASSIS3::GpioValidatePinOwnership",(char)param_1,bVar1,uVar3);
  return -0x3ffffff3;
}



===== GpioValidatePinRange @ 140008bc8 =====

/* protected: long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioValidatePinRange(unsigned short,unsigned
   short) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioValidatePinRange
          (_GPIO_CONTROLLER_CHASSIS3 *this,ushort param_1,ushort param_2)

{
  long lVar1;
  
  if (param_2 < *(ushort *)((ulonglong)param_1 * 0x20 + *(longlong *)(this + 0x40))) {
    lVar1 = 0;
  }
  else {
    if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
      McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                     (uint *)&EvtChassis3_InvalidPinNumber_Error,this + 0x10,
                     *(char **)((ulonglong)param_1 * 0x20 + 8 + *(longlong *)(this + 0x40)),
                     (char)param_2);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                "_GPIO_CONTROLLER_CHASSIS3::GpioValidatePinRange",(char)param_2);
    }
    lVar1 = -0x3ffffff3;
  }
  return lVar1;
}



===== GpioWriteGpioPins @ 140008c70 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CHASSIS3::GpioWriteGpioPins(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,void * __ptr64) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_CHASSIS3::GpioWriteGpioPins
          (_GPIO_CONTROLLER_CHASSIS3 *this,_GPIO_DEVICE_CONTEXT *param_1,void *param_2)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  ulong uVar5;
  longlong lVar6;
  longlong lVar7;
  long lVar8;
  ulonglong uVar9;
  byte *pbVar10;
  uint *puVar11;
  longlong lVar12;
  ushort uVar13;
  longlong lVar14;
  byte bVar15;
  uint uVar16;
  bool bVar17;
  int local_res20;
  undefined1 uVar18;
  undefined1 uVar19;
  byte *local_50;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
            &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids);
  }
  uVar2 = *(ushort *)param_2;
  lVar6 = *(longlong *)((longlong)param_2 + 8);
  local_50 = *(byte **)((longlong)param_2 + 0x18);
  uVar4 = *(uint *)((longlong)param_2 + 0x10);
  lVar8 = GpioValidateBankRange(this,uVar2);
  uVar18 = (undefined1)uVar2;
  if (lVar8 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                "_GPIO_CONTROLLER_CHASSIS3::GpioWriteGpioPins",uVar18);
    }
  }
  else {
    local_res20 = 0;
    uVar13 = 0;
    if (uVar4 != 0) {
      do {
        uVar3 = *(ushort *)(lVar6 + (ulonglong)uVar13 * 2);
        lVar8 = GpioValidatePinRange(this,uVar2,uVar3);
        if (lVar8 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                      &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                      "_GPIO_CONTROLLER_CHASSIS3::GpioWriteGpioPins",uVar18);
          }
          break;
        }
        lVar14 = (ulonglong)uVar2 * 0x20;
        uVar9 = (ulonglong)*(ushort *)(*(longlong *)(this + 0x40) + 2 + lVar14);
        uVar5 = *(ulong *)((ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0xc + uVar9 * 0x18) +
                           (ulonglong)*(ushort *)(*(longlong *)(this + 0x40) + 4 + lVar14) * 4 +
                          *(longlong *)(*(longlong *)(this + 0x38) + uVar9 * 0x18));
        uVar9 = (ulonglong)*(ushort *)(*(longlong *)(this + 0x40) + 2 + lVar14);
        puVar11 = (uint *)((longlong)(int)((uint)*(ushort *)(this + 0x30) * (uint)uVar3) +
                           (ulonglong)*(ushort *)(*(longlong *)(this + 0x38) + 0x12 + uVar9 * 0x18)
                           + (ulonglong)*(ushort *)(*(longlong *)(this + 0x40) + 6 + lVar14) +
                          *(longlong *)(*(longlong *)(this + 0x38) + uVar9 * 0x18));
        uVar16 = *puVar11;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                   &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,puVar11);
        }
        lVar8 = GpioValidatePinMode(this,uVar2,uVar3,uVar5,uVar16);
        uVar19 = (undefined1)uVar3;
        if (lVar8 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                       &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                       "_GPIO_CONTROLLER_CHASSIS3::GpioWriteGpioPins",uVar18,uVar19);
          }
          break;
        }
        iVar1 = local_res20 + 1;
        uVar16 = (*local_50 >> ((byte)local_res20 & 0x1f) ^ uVar16) & 1 ^ uVar16;
        bVar17 = local_res20 != 7;
        bVar15 = (byte)uVar16;
        pbVar10 = local_50 + 1;
        local_res20 = 0;
        if (bVar17) {
          pbVar10 = local_50;
          local_res20 = iVar1;
        }
        uVar9 = (ulonglong)uVar3;
        *(byte *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar14) + 6 + uVar9 * 0x24) =
             bVar15 & 1;
        lVar12 = *(longlong *)(this + 0x40);
        lVar7 = *(longlong *)(lVar12 + 0x10 + lVar14);
        if ((*(char *)(lVar7 + 5 + uVar9 * 0x24) == '\0') || (*(int *)(lVar7 + uVar9 * 0x24) != 2))
        {
          if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
            puVar11 = (uint *)&EvtIoPinOutputPreSet_Info;
            goto LAB_140008eea;
          }
        }
        else {
          *puVar11 = uVar16;
          LOCK();
          UNLOCK();
          if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
            lVar12 = *(longlong *)(this + 0x40);
            puVar11 = (uint *)&EvtIoPinOutputSet_Info;
LAB_140008eea:
            McTemplateK0sqq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,puVar11,this + 0x10,
                            *(char **)(lVar12 + 8 + lVar14),uVar19,bVar15 & 1);
          }
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                      &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,
                      "_GPIO_CONTROLLER_CHASSIS3::GpioWriteGpioPins",uVar18,uVar19,bVar15 & 1);
        }
        uVar13 = uVar13 + 1;
        local_50 = pbVar10;
      } while (uVar13 < uVar4);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
             &WPP_864dacb3a7823ff2c00196fd7da2ec08_Traceguids,0);
  }
  return 0;
}



===== McTemplateK0qqqqq @ 1400090a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqqq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined4 param_4,
                      undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = local_res20;
  local_60 = 4;
  local_58 = &param_5;
  local_50 = 4;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWriteKM(param_1,param_2,param_3,6,local_78);
  return;
}



===== McTemplateK0qxqp @ 14000913c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qxqp(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined4 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0qxqq @ 1400091c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qxqq(undefined8 *param_1,uint *param_2,undefined8 param_3,undefined4 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0sq @ 140009254 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sq(undefined8 *param_1,uint *param_2,undefined8 param_3,char *param_4,
                   undefined1 param_5)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  char *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_4 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_30 = (int)lVar1 + 1;
  }
  local_2c = 0;
  local_38 = "NULL";
  if (param_4 != (char *)0x0) {
    local_38 = param_4;
  }
  local_20 = 4;
  local_28 = &param_5;
  McGenEventWriteKM(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0sqq @ 1400092e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sqq(undefined8 *param_1,uint *param_2,undefined8 param_3,char *param_4,
                    undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  char *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (param_4 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_40 = (int)lVar1 + 1;
  }
  local_3c = 0;
  local_48 = "NULL";
  if (param_4 != (char *)0x0) {
    local_48 = param_4;
  }
  local_38 = &param_5;
  local_30 = 4;
  local_28 = &param_6;
  local_20 = 4;
  McGenEventWriteKM(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0sqqq @ 14000937c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sqqq(undefined8 *param_1,uint *param_2,undefined8 param_3,char *param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  char *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (param_4 == (char *)0x0) {
    local_50 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_50 = (int)lVar1 + 1;
  }
  local_4c = 0;
  local_58 = "NULL";
  if (param_4 != (char *)0x0) {
    local_58 = param_4;
  }
  local_40 = 4;
  local_48 = &param_5;
  local_30 = 4;
  local_38 = &param_6;
  local_20 = 4;
  local_28 = &param_7;
  McGenEventWriteKM(param_1,param_2,param_3,5,local_68);
  return;
}



===== WPP_SF_dDD @ 140009430 =====

void WPP_SF_dDD(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined4 param_4,
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



===== WPP_SF_q @ 1400094c8 =====

void WPP_SF_q(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined8 local_res20;
  
  pcVar1 = pfnWppTraceMessage;
  local_res20 = param_4;
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,&local_res20,8,0);
  return;
}



===== WPP_SF_sD @ 140009538 =====

void WPP_SF_sD(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4,
              undefined1 param_5)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar2,lVar4,&param_5,4,0);
  return;
}



===== WPP_SF_sdd @ 1400095e8 =====

void WPP_SF_sdd(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar2,lVar4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_sDDDD @ 1400096a8 =====

void WPP_SF_sDDDD(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar2,lVar4,&param_5,4,&param_6,4,&param_7,4,
            &param_8,4,0);
  return;
}



===== WPP_SF_sdq @ 140009794 =====

void WPP_SF_sdq(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar2,lVar4,&param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_sdqD @ 140009858 =====

void WPP_SF_sdqD(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_4[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  pcVar2 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar2 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar2,lVar4,&param_5,4,&param_6,8,&param_7,4,0);
  return;
}



===== GpioLayout_Allocate @ 140009930 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_SKL_LP::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_SKL_LP::GpioLayout_Allocate(_GPIO_CONTROLLER_SKL_LP *this)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  size_t _Size;
  void *_Dst;
  long lVar5;
  byte bVar6;
  ulonglong uVar7;
  undefined8 local_38;
  uint uStack_30;
  
  lVar5 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_e79129e1f77e3dfa2abc3ff1558c57fc_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x4000120);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000d000000000;
  local_38 = CONCAT44(local_38._4_4_,0x4000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x58) = uVar3;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x10000d000000000;
  local_38 = CONCAT44(local_38._4_4_,0x4000120);
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x10000d000000000;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x70) = uVar4;
  *(undefined8 *)(this + 0x88) = local_38;
  uVar1 = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_SKL_LP **)(this + 0x38) = this + 0x48;
  *(undefined2 *)(this + 0x2a) = 3;
  *(undefined8 *)(this + 0x90) = 0x18;
  *(undefined1 **)(this + 0x98) = &s_GPP_A;
  *(undefined8 *)(this + 0xa0) = 0;
  *(ulonglong *)(this + 0xa8) = uVar1;
  uVar1 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xb0) = 0xc0000100000018;
  *(undefined1 **)(this + 0xb8) = &s_GPP_B;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xc0) = 0;
  *(ulonglong *)(this + 200) = uVar1;
  uVar1 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xd0) = 0x10018;
  *(undefined1 **)(this + 0xd8) = &s_GPP_C;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xe0) = 0;
  *(ulonglong *)(this + 0xe8) = uVar1;
  *(undefined8 *)(this + 0xf0) = 0xc0000100010018;
  *(undefined1 **)(this + 0xf8) = &s_GPP_D;
  *(undefined8 *)(this + 0x100) = 0;
  *(ulonglong *)(this + 0x108) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  uVar1 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x110) = 0x180000200010018;
  *(undefined1 **)(this + 0x118) = &s_GPP_E;
  uVar7 = 0;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x120) = 0;
  *(ulonglong *)(this + 0x128) = uVar1;
  *(undefined8 *)(this + 0x130) = 0x20018;
  *(undefined1 **)(this + 0x138) = &s_GPP_F;
  *(undefined8 *)(this + 0x140) = 0;
  *(ulonglong *)(this + 0x148) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_SKL_LP **)(this + 0x40) = this + 0x90;
  *(undefined8 *)(this + 0x150) = 0xc0000100020008;
  *(undefined1 **)(this + 0x158) = &s_GPP_G;
  *(undefined2 *)(this + 0x28) = 7;
  *(undefined8 *)(this + 0x160) = 0;
  *(ulonglong *)(this + 0x168) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + uVar7 * 0x20 + 0x90)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + uVar7 * 0x20 + 0x90)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + (uVar7 + 5) * 0x20) = _Dst;
    if (*(longlong *)(uVar7 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar6 = (char)uVar7 + 1;
    uVar7 = (ulonglong)bVar6;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar6) {
      this[0x2c] = (_GPIO_CONTROLLER_SKL_LP)0x18;
      *(ushort *)(this + 0x2e) =
           *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                     *(longlong *)(this + 0x40)) + *(ushort *)(this + 0x28) * 0x18 + -0x18;
      *(undefined2 *)(this + 0x30) = 8;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_e79129e1f77e3dfa2abc3ff1558c57fc_Traceguids);
        }
LAB_140009cc3:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_e79129e1f77e3dfa2abc3ff1558c57fc_Traceguids,lVar5);
        }
      }
      return lVar5;
    }
  }
  lVar5 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_140009cc3;
}



===== GpioLayout_Release @ 140009d20 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CNL_LP::GpioLayout_Release(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_CNL_LP::GpioLayout_Release(_GPIO_CONTROLLER_CNL_LP *this)

{
  longlong lVar1;
  byte bVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(short *)(this + 0x28) != 0) {
    do {
      lVar1 = (uVar3 + 5) * 0x20;
      if (*(longlong *)(this + lVar1) != 0) {
        ExFreePoolWithTag(*(longlong *)(this + lVar1),0);
        *(undefined8 *)(this + lVar1) = 0;
      }
      bVar2 = (char)uVar3 + 1;
      uVar3 = (ulonglong)bVar2;
    } while ((ushort)bVar2 < *(ushort *)(this + 0x28));
  }
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  this[0x2c] = (_GPIO_CONTROLLER_CNL_LP)0x0;
  *(undefined4 *)(this + 0x2e) = 0;
  return 0;
}



===== GpioLayout_Allocate @ 140009da0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_SKL_H::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_SKL_H::GpioLayout_Allocate(_GPIO_CONTROLLER_SKL_H *this)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  size_t _Size;
  void *_Dst;
  long lVar5;
  byte bVar6;
  ulonglong uVar7;
  undefined8 local_38;
  uint uStack_30;
  
  lVar5 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_0572a3ed6030320dec1675faf6fbf49d_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x4000120);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000d000000000;
  local_38 = CONCAT44(local_38._4_4_,0x4000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x58) = uVar3;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x10000d000000000;
  local_38 = CONCAT44(local_38._4_4_,0x4000120);
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x10000d000000000;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x70) = uVar4;
  *(undefined8 *)(this + 0x88) = local_38;
  uVar1 = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_SKL_H **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x90) = 0x18;
  *(undefined1 **)(this + 0x98) = &s_GPP_A;
  *(undefined8 *)(this + 0xa0) = 0;
  *(ulonglong *)(this + 0xa8) = uVar1;
  *(undefined2 *)(this + 0x2a) = 3;
  uVar1 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xb0) = 0xc0000100000018;
  *(undefined1 **)(this + 0xb8) = &s_GPP_B;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xc0) = 0;
  *(ulonglong *)(this + 200) = uVar1;
  uVar1 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xd0) = 0x10018;
  *(undefined1 **)(this + 0xd8) = &s_GPP_C;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xe0) = 0;
  *(ulonglong *)(this + 0xe8) = uVar1;
  *(undefined8 *)(this + 0xf0) = 0xc0000100010018;
  *(undefined1 **)(this + 0xf8) = &s_GPP_D;
  *(undefined8 *)(this + 0x100) = 0;
  *(ulonglong *)(this + 0x108) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  uVar1 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x110) = 0x18000020001000d;
  *(undefined1 **)(this + 0x118) = &s_GPP_E;
  uVar7 = 0;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x120) = 0;
  *(ulonglong *)(this + 0x128) = uVar1;
  uVar1 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x130) = 0x1e8000300010018;
  *(undefined1 **)(this + 0x138) = &s_GPP_F;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x140) = 0;
  *(ulonglong *)(this + 0x148) = uVar1;
  uVar1 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x150) = 0x2a8000400010018;
  *(undefined1 **)(this + 0x158) = &s_GPP_G;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x160) = 0;
  *(ulonglong *)(this + 0x168) = uVar1;
  *(undefined8 *)(this + 0x170) = 0x368000500010018;
  *(undefined1 **)(this + 0x178) = &s_GPP_H;
  *(undefined8 *)(this + 0x180) = 0;
  *(ulonglong *)(this + 0x188) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_SKL_H **)(this + 0x40) = this + 0x90;
  *(undefined8 *)(this + 400) = 0x10002000b;
  *(undefined1 **)(this + 0x198) = &s_GPP_I;
  *(undefined2 *)(this + 0x28) = 9;
  *(undefined8 *)(this + 0x1a0) = 0;
  *(ulonglong *)(this + 0x1a8) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + uVar7 * 0x20 + 0x90)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + uVar7 * 0x20 + 0x90)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + (uVar7 + 5) * 0x20) = _Dst;
    if (*(longlong *)(uVar7 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar6 = (char)uVar7 + 1;
    uVar7 = (ulonglong)bVar6;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar6) {
      this[0x2c] = (_GPIO_CONTROLLER_SKL_H)0x18;
      *(ushort *)(this + 0x2e) =
           *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                     *(longlong *)(this + 0x40)) + *(ushort *)(this + 0x28) * 0x18 + -0x18;
      *(undefined2 *)(this + 0x30) = 8;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_0572a3ed6030320dec1675faf6fbf49d_Traceguids);
        }
LAB_14000a1ae:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_0572a3ed6030320dec1675faf6fbf49d_Traceguids,lVar5);
        }
      }
      return lVar5;
    }
  }
  lVar5 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000a1ae;
}



===== GpioLayout_Allocate @ 14000a200 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CNL_LP::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_CNL_LP::GpioLayout_Allocate(_GPIO_CONTROLLER_CNL_LP *this)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  size_t _Size;
  void *_Dst;
  long lVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined8 local_38;
  uint uStack_30;
  
  lVar6 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_49a96e7181da389a1be20fe6558223c5_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000b000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar5 = local_38;
  *(undefined8 *)(this + 0x58) = uVar4;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x10000b000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x10000b000000000;
  uVar3 = uStack_30 >> 8;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x70) = uVar5;
  *(undefined8 *)(this + 0x88) = local_38;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(_GPIO_CONTROLLER_CNL_LP **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x90) = 0x19;
  *(undefined1 **)(this + 0x98) = &s_GPP_A;
  *(undefined2 *)(this + 0x2a) = 3;
  *(undefined8 *)(this + 0xa0) = 0;
  *(ulonglong *)(this + 0xa8) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xb0) = 0x19000010000001a;
  *(undefined1 **)(this + 0xb8) = &s_GPP_B;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xc0) = 0;
  *(ulonglong *)(this + 200) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xd0) = 0x330000200000008;
  *(undefined1 **)(this + 0xd8) = &s_GPP_G;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xe0) = 0;
  *(ulonglong *)(this + 0xe8) = uVar2;
  *(undefined8 *)(this + 0xf0) = 0x10019;
  *(undefined1 **)(this + 0xf8) = &s_GPP_D;
  *(undefined8 *)(this + 0x100) = 0;
  *(ulonglong *)(this + 0x108) = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x110) = 0x190000100010018;
  *(undefined1 **)(this + 0x118) = &s_GPP_F;
  uVar8 = 0;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x120) = 0;
  *(ulonglong *)(this + 0x128) = uVar2;
  *(_GPIO_CONTROLLER_CNL_LP **)(this + 0x40) = this + 0x90;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x130) = 0x310000200010018;
  *(undefined1 **)(this + 0x138) = &s_GPP_H;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x140) = 0;
  *(ulonglong *)(this + 0x148) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x150) = 0x490000300010020;
  *(undefined1 **)(this + 0x158) = &s_GPP_V;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x160) = 0;
  *(ulonglong *)(this + 0x168) = uVar2;
  *(undefined2 *)(this + 0x28) = 10;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x170) = 0x690000400010008;
  *(undefined1 **)(this + 0x178) = &s_GPP_U;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x180) = 0;
  *(ulonglong *)(this + 0x188) = uVar2;
  *(undefined8 *)(this + 400) = 0x20018;
  *(undefined1 **)(this + 0x198) = &s_GPP_C;
  *(undefined8 *)(this + 0x1a0) = 0;
  *(ulonglong *)(this + 0x1a8) = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x1b0) = 0x180000100020018;
  *(undefined1 **)(this + 0x1b8) = &s_GPP_E;
  *(undefined8 *)(this + 0x1c0) = 0;
  *(ulonglong *)(this + 0x1c8) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + uVar8 * 0x20 + 0x90)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + uVar8 * 0x20 + 0x90)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + (uVar8 + 5) * 0x20) = _Dst;
    if (*(longlong *)(uVar8 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar7 = (char)uVar8 + 1;
    uVar8 = (ulonglong)bVar7;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar7) {
      this[0x2c] = (_GPIO_CONTROLLER_CNL_LP)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_49a96e7181da389a1be20fe6558223c5_Traceguids);
        }
LAB_14000a635:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_49a96e7181da389a1be20fe6558223c5_Traceguids,lVar6);
        }
      }
      return lVar6;
    }
  }
  lVar6 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000a635;
}



===== GpioRestoreBankHardwareContext @ 14000a690 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_CNL_LP::GpioRestoreBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_CNL_LP::GpioRestoreBankHardwareContext
          (_GPIO_CONTROLLER_CNL_LP *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  long lVar2;
  ulonglong uVar3;
  ulong *puVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_49a96e7181da389a1be20fe6558223c5_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar2 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  if (-1 < lVar2) {
    lVar5 = *(longlong *)(this + 0x40);
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(char *)(lVar6 + 0x18 + lVar5) == '\x01') {
      uVar7 = 0;
      if (*(short *)(lVar6 + lVar5) != 0) {
        do {
          uVar3 = (ulonglong)uVar7;
          if (*(char *)(*(longlong *)(lVar6 + 0x10 + lVar5) + 7 + uVar3 * 0x24) == '\x01') {
            puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                               ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
            *puVar4 = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 +
                                uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[1] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[2] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar3 * 0x24) = 0;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextRestored_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(char)uVar7);
            }
          }
          lVar5 = *(longlong *)(this + 0x40);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(lVar6 + lVar5));
      }
      puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress
                         ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
      *puVar4 = *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6);
      LOCK();
      UNLOCK();
      *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 0;
      if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
        McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtBankContextRestored_Info,this + 0x10,
                      *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_49a96e7181da389a1be20fe6558223c5_Traceguids,lVar2);
  }
  return;
}



===== GpioSaveBankHardwareContext @ 14000a890 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_CNL_LP::GpioSaveBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_CNL_LP::GpioSaveBankHardwareContext
          (_GPIO_CONTROLLER_CNL_LP *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  long lVar2;
  ulong *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  longlong lVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_49a96e7181da389a1be20fe6558223c5_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar2 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  if (-1 < lVar2) {
    lVar4 = *(longlong *)(this + 0x40);
    uVar6 = 0;
    lVar7 = (ulonglong)uVar1 * 0x20;
    if (*(short *)(lVar7 + lVar4) != 0) {
      do {
        uVar5 = (ulonglong)uVar6;
        lVar4 = *(longlong *)(lVar7 + 0x10 + lVar4);
        if (*(char *)(lVar4 + 0x14 + uVar5 * 0x24) == '\x01') {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x10;
LAB_14000a960:
            WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                       &WPP_49a96e7181da389a1be20fe6558223c5_Traceguids,
                       "_GPIO_CONTROLLER_CNL_LP::GpioSaveBankHardwareContext",(char)uVar1,
                       (char)uVar6);
          }
        }
        else if (*(int *)(lVar4 + uVar5 * 0x24) == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x11;
            goto LAB_14000a960;
          }
        }
        else {
          puVar3 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                             ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar6);
          if ((*puVar3 & 0x3c00) == 0) {
            *(ulong *)(*(longlong *)(lVar7 + 0x10 + *(longlong *)(this + 0x40)) + 8 + uVar5 * 0x24)
                 = *puVar3;
            *(ulong *)(*(longlong *)(lVar7 + 0x10 + *(longlong *)(this + 0x40)) + 0xc + uVar5 * 0x24
                      ) = puVar3[1];
            *(ulong *)(*(longlong *)(lVar7 + 0x10 + *(longlong *)(this + 0x40)) + 0x10 +
                      uVar5 * 0x24) = puVar3[2];
            *(undefined1 *)
             (*(longlong *)(lVar7 + 0x10 + *(longlong *)(this + 0x40)) + 7 + uVar5 * 0x24) = 1;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextSaved_Verbose,this + 0x10,
                             *(char **)(lVar7 + 8 + *(longlong *)(this + 0x40)),(char)uVar6);
            }
          }
        }
        lVar4 = *(longlong *)(this + 0x40);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(ushort *)(lVar7 + lVar4));
    }
    puVar3 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1)
    ;
    *(ulong *)(lVar7 + 0x1c + *(longlong *)(this + 0x40)) = *puVar3;
    *(undefined1 *)(lVar7 + 0x18 + *(longlong *)(this + 0x40)) = 1;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtBankContextSaved_Info,
                    this + 0x10,*(char **)(lVar7 + 8 + *(longlong *)(this + 0x40)));
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_49a96e7181da389a1be20fe6558223c5_Traceguids,lVar2);
  }
  return;
}



===== GpioLayout_Allocate @ 14000ab00 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_ICL_LP::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_ICL_LP::GpioLayout_Allocate(_GPIO_CONTROLLER_ICL_LP *this)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  size_t _Size;
  void *_Dst;
  longlong lVar6;
  long lVar7;
  byte bVar8;
  ulonglong uVar9;
  undefined8 local_38;
  uint uStack_30;
  
  lVar7 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_28bdcb05c5ad326f7d8fa40282be7b70_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000b000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar5 = local_38;
  *(undefined8 *)(this + 0x58) = uVar4;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x10000b000000000;
  *(undefined8 *)(this + 0x70) = uVar5;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x10000b000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  *(undefined8 *)(this + 0x88) = uVar4;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0x10000b000000000;
  uVar3 = uStack_30 >> 8;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xa0) = local_38;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(_GPIO_CONTROLLER_ICL_LP **)(this + 0x38) = this + 0x48;
  *(undefined2 *)(this + 0x2a) = 4;
  *(undefined8 *)(this + 0xa8) = 8;
  *(undefined1 **)(this + 0xb0) = &s_GPP_G;
  *(undefined8 *)(this + 0xb8) = 0;
  *(ulonglong *)(this + 0xc0) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 200) = 0x8000010000001a;
  *(undefined1 **)(this + 0xd0) = &s_GPP_B;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xd8) = 0;
  *(ulonglong *)(this + 0xe0) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xe8) = 0x220000200000019;
  *(undefined1 **)(this + 0xf0) = &s_GPP_A;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xf8) = 0;
  *(ulonglong *)(this + 0x100) = uVar2;
  *(undefined8 *)(this + 0x108) = 0x10018;
  *(undefined1 **)(this + 0x110) = &s_GPP_H;
  *(undefined8 *)(this + 0x118) = 0;
  *(ulonglong *)(this + 0x120) = (ulonglong)uStack_30;
  uVar9 = 0;
  uStack_30 = uVar3 << 8;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x128) = 0x180000100010015;
  *(undefined1 **)(this + 0x130) = &s_GPP_D;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x138) = 0;
  *(ulonglong *)(this + 0x140) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x148) = 0x2d0000200010014;
  *(undefined1 **)(this + 0x150) = &s_GPP_F;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x158) = 0;
  *(ulonglong *)(this + 0x160) = uVar2;
  *(_GPIO_CONTROLLER_ICL_LP **)(this + 0x40) = this + 0xa8;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x168) = 0x41000030001001d;
  *(undefined1 **)(this + 0x170) = &s_GPP_V;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x178) = 0;
  *(ulonglong *)(this + 0x180) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x188) = 0x20018;
  *(undefined1 **)(this + 400) = &s_GPP_C;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x198) = 0;
  *(ulonglong *)(this + 0x1a0) = uVar2;
  *(undefined2 *)(this + 0x28) = 0xb;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1a8) = 0x1e0000200020018;
  *(undefined1 **)(this + 0x1b0) = &s_GPP_E;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x1b8) = 0;
  *(ulonglong *)(this + 0x1c0) = uVar2;
  *(undefined8 *)(this + 0x1c8) = 0x30008;
  *(undefined1 **)(this + 0x1d0) = &s_GPP_R;
  *(undefined8 *)(this + 0x1d8) = 0;
  *(ulonglong *)(this + 0x1e0) = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x1e8) = 0x80000100030008;
  *(undefined1 **)(this + 0x1f0) = &s_GPP_S;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(ulonglong *)(this + 0x200) = (ulonglong)uStack_30;
  while( true ) {
    lVar6 = uVar9 * 0x20;
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + lVar6 + 0xa8)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + lVar6 + 0xa8)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + lVar6 + 0xb8) = _Dst;
    if (*(longlong *)(lVar6 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar8 = (char)uVar9 + 1;
    uVar9 = (ulonglong)bVar8;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar8) {
      this[0x2c] = (_GPIO_CONTROLLER_ICL_LP)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_28bdcb05c5ad326f7d8fa40282be7b70_Traceguids);
        }
LAB_14000af8a:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_28bdcb05c5ad326f7d8fa40282be7b70_Traceguids,lVar7);
        }
      }
      return lVar7;
    }
  }
  lVar7 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000af8a;
}



===== GpioLayout_Release @ 14000afe0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_ICL_LP::GpioLayout_Release(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_ICL_LP::GpioLayout_Release(_GPIO_CONTROLLER_ICL_LP *this)

{
  byte bVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (*(short *)(this + 0x28) != 0) {
    do {
      if (*(longlong *)(this + uVar2 * 0x20 + 0xb8) != 0) {
        ExFreePoolWithTag(*(longlong *)(this + uVar2 * 0x20 + 0xb8),0);
        *(undefined8 *)(this + uVar2 * 0x20 + 0xb8) = 0;
      }
      bVar1 = (char)uVar2 + 1;
      uVar2 = (ulonglong)bVar1;
    } while ((ushort)bVar1 < *(ushort *)(this + 0x28));
  }
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  this[0x2c] = (_GPIO_CONTROLLER_ICL_LP)0x0;
  *(undefined4 *)(this + 0x2e) = 0;
  return 0;
}



===== GpioRestoreBankHardwareContext @ 14000b060 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_ICL_LP::GpioRestoreBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_ICL_LP::GpioRestoreBankHardwareContext
          (_GPIO_CONTROLLER_ICL_LP *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  long lVar2;
  ulonglong uVar3;
  ulong *puVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_28bdcb05c5ad326f7d8fa40282be7b70_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar2 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  if (-1 < lVar2) {
    lVar5 = *(longlong *)(this + 0x40);
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(char *)(lVar6 + 0x18 + lVar5) == '\x01') {
      uVar7 = 0;
      if (*(short *)(lVar6 + lVar5) != 0) {
        do {
          uVar3 = (ulonglong)uVar7;
          if (*(char *)(*(longlong *)(lVar6 + 0x10 + lVar5) + 7 + uVar3 * 0x24) == '\x01') {
            puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                               ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
            *puVar4 = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 +
                                uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[1] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[2] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar3 * 0x24) = 0;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextRestored_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(char)uVar7);
            }
          }
          lVar5 = *(longlong *)(this + 0x40);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(lVar6 + lVar5));
      }
      puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress
                         ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
      *puVar4 = *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6);
      LOCK();
      UNLOCK();
      *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 0;
      if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
        McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtBankContextRestored_Info,this + 0x10,
                      *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_28bdcb05c5ad326f7d8fa40282be7b70_Traceguids,lVar2);
  }
  return;
}



===== GpioSaveBankHardwareContext @ 14000b260 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_ICL_LP::GpioSaveBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_ICL_LP::GpioSaveBankHardwareContext
          (_GPIO_CONTROLLER_ICL_LP *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  ulong *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_28bdcb05c5ad326f7d8fa40282be7b70_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar3 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  uVar7 = 0;
  if (-1 < lVar3) {
    puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioOwnRegAddress
                       ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
    uVar2 = *puVar4;
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(short *)(lVar6 + *(longlong *)(this + 0x40)) != 0) {
      do {
        if ((uVar2 >> ((byte)uVar7 & 0x1f) & 1) != 0) {
          puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                             ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
          if ((*puVar4 & 0x3c00) == 0) {
            uVar5 = (ulonglong)uVar7;
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 + uVar5 * 0x24)
                 = *puVar4;
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc + uVar5 * 0x24
                      ) = puVar4[1];
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                      uVar5 * 0x24) = puVar4[2];
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar5 * 0x24) = 1;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextSaved_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(byte)uVar7);
            }
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(lVar6 + *(longlong *)(this + 0x40)));
    }
    puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1)
    ;
    *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6) = *puVar4;
    *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 1;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtBankContextSaved_Info,
                    this + 0x10,*(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_28bdcb05c5ad326f7d8fa40282be7b70_Traceguids,lVar3);
  }
  return;
}



===== GpioLayout_Allocate @ 14000b450 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_ICL_N::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_ICL_N::GpioLayout_Allocate(_GPIO_CONTROLLER_ICL_N *this)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  size_t _Size;
  void *_Dst;
  long lVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined8 local_38;
  uint uStack_30;
  
  lVar6 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_4ecd6807907337ec2f0cfc70fb19272c_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000b000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar5 = local_38;
  *(undefined8 *)(this + 0x58) = uVar4;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x10000b000000000;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x10000b000000000;
  *(undefined8 *)(this + 0x70) = uVar5;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar5 = local_38;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0x10000b000000000;
  *(undefined8 *)(this + 0x88) = uVar4;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  *(undefined8 *)(this + 0xa0) = uVar5;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0x10000b000000000;
  uVar3 = uStack_30 >> 8;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xb8) = local_38;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(_GPIO_CONTROLLER_ICL_N **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0xc0) = 0x9000010000001a;
  *(undefined1 **)(this + 200) = &s_GPP_B;
  *(undefined8 *)(this + 0xd0) = 0;
  *(ulonglong *)(this + 0xd8) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xe0) = 0x230000200000015;
  *(undefined1 **)(this + 0xe8) = &s_GPP_A;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xf0) = 0;
  *(ulonglong *)(this + 0xf8) = uVar2;
  *(undefined2 *)(this + 0x2a) = 5;
  *(undefined8 *)(this + 0x100) = 0x380000300000008;
  *(undefined1 **)(this + 0x108) = &s_GPP_S;
  *(undefined8 *)(this + 0x110) = 0;
  *(ulonglong *)(this + 0x118) = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x120) = 0x400000400000008;
  *(undefined1 **)(this + 0x128) = &s_GPP_R;
  uStack_30 = uVar3 << 8;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x140) = 0x10018;
  *(undefined1 **)(this + 0x148) = &s_GPP_H;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x130) = 0;
  *(ulonglong *)(this + 0x138) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x160) = 0x18000010001001a;
  *(undefined1 **)(this + 0x168) = &s_GPP_D;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x150) = 0;
  *(ulonglong *)(this + 0x158) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x180) = 0x32000020001001d;
  *(undefined1 **)(this + 0x188) = &s_GPP_V0;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x170) = 0;
  *(ulonglong *)(this + 0x178) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1a0) = 0x4f0000300010018;
  *(undefined1 **)(this + 0x1a8) = &s_GPP_C;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 400) = 0;
  *(ulonglong *)(this + 0x198) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1c0) = 0xf0000100020020;
  *(undefined1 **)(this + 0x1c8) = &s_GPP_V1;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x1b0) = 0;
  *(ulonglong *)(this + 0x1b8) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1e0) = 0x2f0000200020020;
  *(undefined1 **)(this + 0x1e8) = &s_GPP_V2;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x1d0) = 0;
  *(ulonglong *)(this + 0x1d8) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x1f0) = 0;
  *(ulonglong *)(this + 0x1f8) = uVar2;
  *(undefined8 *)(this + 0x200) = 0x4f000030002001e;
  *(undefined1 **)(this + 0x208) = &s_GPP_V3;
  uVar2 = (ulonglong)uStack_30;
  uVar8 = 0;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x210) = 0;
  *(ulonglong *)(this + 0x218) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x220) = 0x60000100030018;
  *(undefined1 **)(this + 0x228) = &s_GPP_E;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x230) = 0;
  *(ulonglong *)(this + 0x238) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x240) = 0x270000300030004;
  *(undefined1 **)(this + 0x248) = &s_GPP_V4;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x250) = 0;
  *(ulonglong *)(this + 600) = uVar2;
  *(_GPIO_CONTROLLER_ICL_N **)(this + 0x40) = this + 0xc0;
  *(undefined8 *)(this + 0x260) = 0x40008;
  *(undefined1 **)(this + 0x268) = &s_GPP_G;
  *(undefined2 *)(this + 0x28) = 0xe;
  *(undefined8 *)(this + 0x270) = 0;
  *(ulonglong *)(this + 0x278) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar8 + 6) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar8 + 6) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar8 * 0x20 + 0xd0) = _Dst;
    if (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + uVar8 * 0x20) == 0) break;
    bVar7 = (char)uVar8 + 1;
    uVar8 = (ulonglong)bVar7;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar7) {
      this[0x2c] = (_GPIO_CONTROLLER_ICL_N)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_4ecd6807907337ec2f0cfc70fb19272c_Traceguids);
        }
LAB_14000b9c7:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_4ecd6807907337ec2f0cfc70fb19272c_Traceguids,lVar6);
        }
      }
      return lVar6;
    }
  }
  lVar6 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000b9c7;
}



===== GpioLayout_Release @ 14000ba20 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_ICL_H::GpioLayout_Release(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_ICL_H::GpioLayout_Release(_GPIO_CONTROLLER_ICL_H *this)

{
  byte bVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (*(short *)(this + 0x28) != 0) {
    do {
      if (*(longlong *)(this + uVar2 * 0x20 + 0xd0) != 0) {
        ExFreePoolWithTag(*(longlong *)(this + uVar2 * 0x20 + 0xd0),0);
        *(undefined8 *)(this + uVar2 * 0x20 + 0xd0) = 0;
      }
      bVar1 = (char)uVar2 + 1;
      uVar2 = (ulonglong)bVar1;
    } while ((ushort)bVar1 < *(ushort *)(this + 0x28));
  }
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  this[0x2c] = (_GPIO_CONTROLLER_ICL_H)0x0;
  *(undefined4 *)(this + 0x2e) = 0;
  return 0;
}



===== GpioRestoreBankHardwareContext @ 14000baa0 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_ICL_N::GpioRestoreBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_ICL_N::GpioRestoreBankHardwareContext
          (_GPIO_CONTROLLER_ICL_N *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  long lVar2;
  ulonglong uVar3;
  ulong *puVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_4ecd6807907337ec2f0cfc70fb19272c_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar2 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  if (-1 < lVar2) {
    lVar5 = *(longlong *)(this + 0x40);
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(char *)(lVar6 + 0x18 + lVar5) == '\x01') {
      uVar7 = 0;
      if (*(short *)(lVar6 + lVar5) != 0) {
        do {
          uVar3 = (ulonglong)uVar7;
          if (*(char *)(*(longlong *)(lVar6 + 0x10 + lVar5) + 7 + uVar3 * 0x24) == '\x01') {
            puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                               ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
            *puVar4 = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 +
                                uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[1] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[2] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar3 * 0x24) = 0;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextRestored_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(char)uVar7);
            }
          }
          lVar5 = *(longlong *)(this + 0x40);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(lVar6 + lVar5));
      }
      puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress
                         ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
      *puVar4 = *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6);
      LOCK();
      UNLOCK();
      *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 0;
      if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
        McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtBankContextRestored_Info,this + 0x10,
                      *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_4ecd6807907337ec2f0cfc70fb19272c_Traceguids,lVar2);
  }
  return;
}



===== GpioSaveBankHardwareContext @ 14000bca0 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_ICL_N::GpioSaveBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_ICL_N::GpioSaveBankHardwareContext
          (_GPIO_CONTROLLER_ICL_N *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  ulong *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_4ecd6807907337ec2f0cfc70fb19272c_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar3 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  uVar7 = 0;
  if (-1 < lVar3) {
    puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioOwnRegAddress
                       ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
    uVar2 = *puVar4;
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(short *)(lVar6 + *(longlong *)(this + 0x40)) != 0) {
      do {
        if ((uVar2 >> ((byte)uVar7 & 0x1f) & 1) != 0) {
          puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                             ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
          if ((*puVar4 & 0x3c00) == 0) {
            uVar5 = (ulonglong)uVar7;
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 + uVar5 * 0x24)
                 = *puVar4;
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc + uVar5 * 0x24
                      ) = puVar4[1];
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                      uVar5 * 0x24) = puVar4[2];
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar5 * 0x24) = 1;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextSaved_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(byte)uVar7);
            }
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(lVar6 + *(longlong *)(this + 0x40)));
    }
    puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1)
    ;
    *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6) = *puVar4;
    *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 1;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtBankContextSaved_Info,
                    this + 0x10,*(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_4ecd6807907337ec2f0cfc70fb19272c_Traceguids,lVar3);
  }
  return;
}



===== GpioLayout_Allocate @ 14000be90 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_NORTH::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_BXT_NORTH::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_NORTH *this)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  size_t _Size;
  void *_Dst;
  long lVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined8 local_38;
  uint uStack_30;
  
  lVar4 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_ca9dcf5dc1b5397750a7d4409a20f388_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x4000110);
  uVar6 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  uVar3 = uStack_30 >> 8;
  uStack_30 = uVar3 << 8;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(_GPIO_CONTROLLER_BXT_NORTH **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(char **)(this + 0x68) = "NORTH0+";
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x80) = 0x100000100000020;
  *(char **)(this + 0x88) = "NORTH32+";
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x90) = 0;
  *(ulonglong *)(this + 0x98) = uVar2;
  *(undefined4 *)(this + 0x28) = 0x10003;
  *(undefined8 *)(this + 0xa0) = 0x200000200000013;
  *(char **)(this + 0xa8) = "NORTH64+";
  *(_GPIO_CONTROLLER_BXT_NORTH **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0xb0) = 0;
  *(ulonglong *)(this + 0xb8) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar6 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar6 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar6 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar6 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar5 = (char)uVar6 + 1;
    uVar6 = (ulonglong)bVar5;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar5) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_NORTH)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 8;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_ca9dcf5dc1b5397750a7d4409a20f388_Traceguids);
        }
LAB_14000c0df:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_ca9dcf5dc1b5397750a7d4409a20f388_Traceguids,lVar4);
        }
      }
      return lVar4;
    }
  }
  lVar4 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000c0df;
}



===== GpioLayout_Release @ 14000c140 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_SOUTH::GpioLayout_Release(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_BXT_SOUTH::GpioLayout_Release(_GPIO_CONTROLLER_BXT_SOUTH *this)

{
  byte bVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (*(short *)(this + 0x28) != 0) {
    do {
      if (*(longlong *)(this + uVar2 * 0x20 + 0x70) != 0) {
        ExFreePoolWithTag(*(longlong *)(this + uVar2 * 0x20 + 0x70),0);
        *(undefined8 *)(this + uVar2 * 0x20 + 0x70) = 0;
      }
      bVar1 = (char)uVar2 + 1;
      uVar2 = (ulonglong)bVar1;
    } while ((ushort)bVar1 < *(ushort *)(this + 0x28));
  }
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  this[0x2c] = (_GPIO_CONTROLLER_BXT_SOUTH)0x0;
  *(undefined4 *)(this + 0x2e) = 0;
  return 0;
}



===== GpioLayout_Allocate @ 14000c1c0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_NORTH_WEST::GpioLayout_Allocate(void) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_BXT_NORTH_WEST::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_NORTH_WEST *this)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  size_t _Size;
  void *_Dst;
  long lVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined8 local_38;
  uint uStack_30;
  
  lVar4 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_39806a84b8bd3a32d1c3e06100e74fbc_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x4000110);
  uVar6 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  uVar3 = uStack_30 >> 8;
  uStack_30 = uVar3 << 8;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(_GPIO_CONTROLLER_BXT_NORTH_WEST **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(char **)(this + 0x68) = "NORTHWEST0+";
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x80) = 0x100000100000020;
  *(char **)(this + 0x88) = "NORTHWEST32+";
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x90) = 0;
  *(ulonglong *)(this + 0x98) = uVar2;
  *(undefined4 *)(this + 0x28) = 0x10003;
  *(undefined8 *)(this + 0xa0) = 0x200000200000008;
  *(char **)(this + 0xa8) = "NORTHWEST64+";
  *(_GPIO_CONTROLLER_BXT_NORTH_WEST **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0xb0) = 0;
  *(ulonglong *)(this + 0xb8) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar6 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar6 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar6 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar6 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar5 = (char)uVar6 + 1;
    uVar6 = (ulonglong)bVar5;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar5) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_NORTH_WEST)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 8;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_39806a84b8bd3a32d1c3e06100e74fbc_Traceguids);
        }
LAB_14000c40f:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_39806a84b8bd3a32d1c3e06100e74fbc_Traceguids,lVar4);
        }
      }
      return lVar4;
    }
  }
  lVar4 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000c40f;
}



===== GpioLayout_Allocate @ 14000c470 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_SOUTH::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_BXT_SOUTH::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_SOUTH *this)

{
  size_t _Size;
  void *_Dst;
  long lVar1;
  byte bVar2;
  ulonglong uVar3;
  undefined8 local_38;
  uint uStack_30;
  
  lVar1 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_f4cf4c0e7be93a075c44450e75cc7833_Traceguids);
  }
  uVar3 = 0;
  local_38 = CONCAT44(local_38._4_4_,0x4000110);
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(_GPIO_CONTROLLER_BXT_SOUTH **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x58) = local_38;
  uStack_30 = uStack_30 & 0xffffff00;
  *(undefined4 *)(this + 0x28) = 0x10001;
  *(undefined8 *)(this + 0x60) = 0x14;
  *(undefined1 **)(this + 0x68) = &s_SOUTH0_;
  *(_GPIO_CONTROLLER_BXT_SOUTH **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar3 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar3 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar3 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar3 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar2 = (char)uVar3 + 1;
    uVar3 = (ulonglong)bVar2;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar2) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_SOUTH)0x14;
      *(ushort *)(this + 0x2e) =
           *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                     *(longlong *)(this + 0x40)) + *(ushort *)(this + 0x28) * 0x14 + -0x14;
      *(undefined2 *)(this + 0x30) = 8;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_f4cf4c0e7be93a075c44450e75cc7833_Traceguids);
        }
LAB_14000c650:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_f4cf4c0e7be93a075c44450e75cc7833_Traceguids,lVar1);
        }
      }
      return lVar1;
    }
  }
  lVar1 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000c650;
}



===== GpioLayout_Allocate @ 14000c6b0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_SOUTH_WEST::GpioLayout_Allocate(void) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_BXT_SOUTH_WEST::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_SOUTH_WEST *this)

{
  size_t _Size;
  void *_Dst;
  long lVar1;
  byte bVar2;
  ulonglong uVar3;
  undefined8 local_38;
  uint uStack_30;
  
  lVar1 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_87f34f42a00f3e3f153dccb48cfc552a_Traceguids);
  }
  uVar3 = 0;
  local_38 = CONCAT44(local_38._4_4_,0x4000110);
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(_GPIO_CONTROLLER_BXT_SOUTH_WEST **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x58) = local_38;
  uStack_30 = uStack_30 & 0xffffff00;
  *(undefined4 *)(this + 0x28) = 0x10001;
  *(undefined8 *)(this + 0x60) = 0x1f;
  *(undefined1 **)(this + 0x68) = &s_SOUTHWEST0_;
  *(_GPIO_CONTROLLER_BXT_SOUTH_WEST **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar3 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar3 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar3 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar3 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar2 = (char)uVar3 + 1;
    uVar3 = (ulonglong)bVar2;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar2) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_SOUTH_WEST)0x1f;
      *(ushort *)(this + 0x2e) =
           *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                     *(longlong *)(this + 0x40)) + *(ushort *)(this + 0x28) * 0x1f + -0x1f;
      *(undefined2 *)(this + 0x30) = 8;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_87f34f42a00f3e3f153dccb48cfc552a_Traceguids);
        }
LAB_14000c881:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_87f34f42a00f3e3f153dccb48cfc552a_Traceguids,lVar1);
        }
      }
      return lVar1;
    }
  }
  lVar1 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000c881;
}



===== GpioLayout_Allocate @ 14000c8e0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_WEST::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_BXT_WEST::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_WEST *this)

{
  short sVar1;
  uint uVar2;
  size_t _Size;
  void *_Dst;
  long lVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined8 local_38;
  uint uStack_30;
  
  lVar3 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_39510542dbaf37513abf6a69b78236bd_Traceguids);
  }
  uVar5 = 0;
  local_38 = CONCAT44(local_38._4_4_,0x4000110);
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_BXT_WEST **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(undefined1 **)(this + 0x68) = &s_WEST0_;
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(undefined4 *)(this + 0x28) = 0x10002;
  *(undefined8 *)(this + 0x80) = 0x10000010000000a;
  *(undefined1 **)(this + 0x88) = &s_WEST32_;
  *(_GPIO_CONTROLLER_BXT_WEST **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0x90) = 0;
  *(ulonglong *)(this + 0x98) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar5 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar5 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar5 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar5 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar4 = (char)uVar5 + 1;
    uVar5 = (ulonglong)bVar4;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar4) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_WEST)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 8;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_39510542dbaf37513abf6a69b78236bd_Traceguids);
        }
LAB_14000cae9:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_39510542dbaf37513abf6a69b78236bd_Traceguids,lVar3);
        }
      }
      return lVar3;
    }
  }
  lVar3 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000cae9;
}



===== GpioLayout_Allocate @ 14000cb40 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_P_NORTH::GpioLayout_Allocate(void) __ptr64 */

long __thiscall
_GPIO_CONTROLLER_BXT_P_NORTH::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_P_NORTH *this)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  size_t _Size;
  void *_Dst;
  long lVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined8 local_38;
  uint uStack_30;
  
  lVar4 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_ab770d37078f30f6bf9bbcabdaf11a0e_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x5000110);
  uVar6 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  uVar3 = uStack_30 >> 8;
  uStack_30 = uVar3 << 8;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(_GPIO_CONTROLLER_BXT_P_NORTH **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(char **)(this + 0x68) = "NORTH0+";
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x80) = 0x100000100000020;
  *(char **)(this + 0x88) = "NORTH32+";
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x90) = 0;
  *(ulonglong *)(this + 0x98) = uVar2;
  *(undefined4 *)(this + 0x28) = 0x10003;
  *(undefined8 *)(this + 0xa0) = 0x20000020000000e;
  *(char **)(this + 0xa8) = "NORTH64+";
  *(_GPIO_CONTROLLER_BXT_P_NORTH **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0xb0) = 0;
  *(ulonglong *)(this + 0xb8) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar6 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar6 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar6 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar6 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar5 = (char)uVar6 + 1;
    uVar6 = (ulonglong)bVar5;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar5) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_P_NORTH)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 8;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_ab770d37078f30f6bf9bbcabdaf11a0e_Traceguids);
        }
LAB_14000cd8f:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_ab770d37078f30f6bf9bbcabdaf11a0e_Traceguids,lVar4);
        }
      }
      return lVar4;
    }
  }
  lVar4 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000cd8f;
}



===== GpioLayout_Allocate @ 14000cdf0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_P_NORTH_WEST::GpioLayout_Allocate(void) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_BXT_P_NORTH_WEST::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_P_NORTH_WEST *this)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  size_t _Size;
  void *_Dst;
  long lVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined8 local_38;
  uint uStack_30;
  
  lVar4 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_b662788007bc3c5ec8e94bb802a2ac1f_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x5000110);
  uVar6 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  uVar3 = uStack_30 >> 8;
  uStack_30 = uVar3 << 8;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(_GPIO_CONTROLLER_BXT_P_NORTH_WEST **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(char **)(this + 0x68) = "NORTHWEST0+";
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x80) = 0x100000100000020;
  *(char **)(this + 0x88) = "NORTHWEST32+";
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x90) = 0;
  *(ulonglong *)(this + 0x98) = uVar2;
  *(undefined4 *)(this + 0x28) = 0x10003;
  *(undefined8 *)(this + 0xa0) = 0x20000020000000d;
  *(char **)(this + 0xa8) = "NORTHWEST64+";
  *(_GPIO_CONTROLLER_BXT_P_NORTH_WEST **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0xb0) = 0;
  *(ulonglong *)(this + 0xb8) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar6 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar6 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar6 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar6 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar5 = (char)uVar6 + 1;
    uVar6 = (ulonglong)bVar5;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar5) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_P_NORTH_WEST)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 8;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_b662788007bc3c5ec8e94bb802a2ac1f_Traceguids);
        }
LAB_14000d03f:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_b662788007bc3c5ec8e94bb802a2ac1f_Traceguids,lVar4);
        }
      }
      return lVar4;
    }
  }
  lVar4 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000d03f;
}



===== GpioLayout_Allocate @ 14000d0a0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_P_SOUTH_WEST::GpioLayout_Allocate(void) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_BXT_P_SOUTH_WEST::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_P_SOUTH_WEST *this)

{
  short sVar1;
  uint uVar2;
  size_t _Size;
  void *_Dst;
  long lVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined8 local_38;
  uint uStack_30;
  
  lVar3 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_838f5e241a6930837d2cd143bc36fbea_Traceguids);
  }
  uVar5 = 0;
  local_38 = CONCAT44(local_38._4_4_,0x5000110);
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_BXT_P_SOUTH_WEST **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(undefined1 **)(this + 0x68) = &s_SOUTHWEST0_;
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(undefined4 *)(this + 0x28) = 0x10002;
  *(undefined8 *)(this + 0x80) = 0x10000010000000b;
  *(undefined1 **)(this + 0x88) = &s_SOUTHWEST32_;
  *(_GPIO_CONTROLLER_BXT_P_SOUTH_WEST **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0x90) = 0;
  *(ulonglong *)(this + 0x98) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar5 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar5 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar5 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar5 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar4 = (char)uVar5 + 1;
    uVar5 = (ulonglong)bVar4;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar4) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_P_SOUTH_WEST)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 8;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_838f5e241a6930837d2cd143bc36fbea_Traceguids);
        }
LAB_14000d2ab:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_838f5e241a6930837d2cd143bc36fbea_Traceguids,lVar3);
        }
      }
      return lVar3;
    }
  }
  lVar3 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000d2ab;
}



===== GpioLayout_Allocate @ 14000d300 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_BXT_P_WEST::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_BXT_P_WEST::GpioLayout_Allocate(_GPIO_CONTROLLER_BXT_P_WEST *this)

{
  short sVar1;
  uint uVar2;
  size_t _Size;
  void *_Dst;
  long lVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined8 local_38;
  uint uStack_30;
  
  lVar3 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_798aaca615893d34bef3e957657241dd_Traceguids);
  }
  uVar5 = 0;
  local_38 = CONCAT44(local_38._4_4_,0x5000110);
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_BXT_P_WEST **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(undefined1 **)(this + 0x68) = &s_WEST0_;
  *(undefined8 *)(this + 0x70) = 0;
  *(ulonglong *)(this + 0x78) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(undefined4 *)(this + 0x28) = 0x10002;
  *(undefined8 *)(this + 0x80) = 0x10000010000000f;
  *(undefined1 **)(this + 0x88) = &s_WEST32_;
  *(_GPIO_CONTROLLER_BXT_P_WEST **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0x90) = 0;
  *(ulonglong *)(this + 0x98) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar5 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar5 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar5 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar5 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar4 = (char)uVar5 + 1;
    uVar5 = (ulonglong)bVar4;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar4) {
      this[0x2c] = (_GPIO_CONTROLLER_BXT_P_WEST)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 8;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_798aaca615893d34bef3e957657241dd_Traceguids);
        }
LAB_14000d50b:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_798aaca615893d34bef3e957657241dd_Traceguids,lVar3);
        }
      }
      return lVar3;
    }
  }
  lVar3 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000d50b;
}



===== GpioLayout_Allocate @ 14000d560 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_CNL_H::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_CNL_H::GpioLayout_Allocate(_GPIO_CONTROLLER_CNL_H *this)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  size_t _Size;
  void *_Dst;
  longlong lVar5;
  long lVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined8 local_38;
  uint uStack_30;
  
  lVar6 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_c1faf6d1713c3dbc7f768ced3470aaa4_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000c000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x58) = uVar3;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x10000c000000000;
  *(undefined8 *)(this + 0x70) = uVar4;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x10000c000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000120);
  *(undefined8 *)(this + 0x88) = uVar3;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0x10000c000000000;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xa0) = local_38;
  uVar8 = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_CNL_H **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0xa8) = 0x19;
  *(undefined1 **)(this + 0xb0) = &s_GPP_A;
  *(undefined8 *)(this + 0xb8) = 0;
  *(ulonglong *)(this + 0xc0) = uVar8;
  *(undefined2 *)(this + 0x2a) = 4;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 200) = 0x19000010000001a;
  *(undefined1 **)(this + 0xd0) = &s_GPP_B;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xd8) = 0;
  *(ulonglong *)(this + 0xe0) = uVar8;
  *(undefined8 *)(this + 0xe8) = 0x10018;
  *(undefined1 **)(this + 0xf0) = &s_GPP_C;
  *(undefined8 *)(this + 0xf8) = 0;
  *(ulonglong *)(this + 0x100) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x108) = 0x180000100010018;
  *(undefined1 **)(this + 0x110) = &s_GPP_D;
  *(undefined8 *)(this + 0x118) = 0;
  *(ulonglong *)(this + 0x120) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x128) = 0x300000200010008;
  *(undefined1 **)(this + 0x130) = &s_GPP_G;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x138) = 0;
  *(ulonglong *)(this + 0x140) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x148) = 0x400000400010020;
  *(undefined1 **)(this + 0x150) = &s_GPP_V;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x158) = 0;
  *(ulonglong *)(this + 0x160) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x168) = 0x20018;
  *(undefined1 **)(this + 0x170) = &s_GPP_K;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x178) = 0;
  *(ulonglong *)(this + 0x180) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x188) = 0x180000100020018;
  *(undefined1 **)(this + 400) = &s_GPP_H;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x198) = 0;
  *(ulonglong *)(this + 0x1a0) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1a8) = 0x30000020002000d;
  *(undefined1 **)(this + 0x1b0) = &s_GPP_E;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x1b8) = 0;
  *(ulonglong *)(this + 0x1c0) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1c8) = 0x3d0000300020018;
  *(undefined1 **)(this + 0x1d0) = &s_GPP_F;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x1d8) = 0;
  *(ulonglong *)(this + 0x1e0) = uVar8;
  *(undefined8 *)(this + 0x1e8) = 0x140000200030012;
  *(undefined1 **)(this + 0x1f0) = &s_GPP_I;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(ulonglong *)(this + 0x200) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  uVar8 = 0;
  *(_GPIO_CONTROLLER_CNL_H **)(this + 0x40) = this + 0xa8;
  *(undefined8 *)(this + 0x208) = 0x26000030003000c;
  *(undefined1 **)(this + 0x210) = &s_GPP_J;
  *(undefined2 *)(this + 0x28) = 0xc;
  *(undefined8 *)(this + 0x218) = 0;
  *(ulonglong *)(this + 0x220) = (ulonglong)uStack_30;
  while( true ) {
    lVar5 = uVar8 * 0x20;
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + lVar5 + 0xa8)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + lVar5 + 0xa8)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + lVar5 + 0xb8) = _Dst;
    if (*(longlong *)(lVar5 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar7 = (char)uVar8 + 1;
    uVar8 = (ulonglong)bVar7;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar7) {
      this[0x2c] = (_GPIO_CONTROLLER_CNL_H)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_c1faf6d1713c3dbc7f768ced3470aaa4_Traceguids);
        }
LAB_14000da30:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_c1faf6d1713c3dbc7f768ced3470aaa4_Traceguids,lVar6);
        }
      }
      return lVar6;
    }
  }
  lVar6 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000da30;
}



===== GpioRestoreBankHardwareContext @ 14000da90 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_CNL_H::GpioRestoreBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_CNL_H::GpioRestoreBankHardwareContext
          (_GPIO_CONTROLLER_CNL_H *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  long lVar2;
  ulonglong uVar3;
  ulong *puVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_c1faf6d1713c3dbc7f768ced3470aaa4_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar2 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  if (-1 < lVar2) {
    lVar5 = *(longlong *)(this + 0x40);
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(char *)(lVar6 + 0x18 + lVar5) == '\x01') {
      uVar7 = 0;
      if (*(short *)(lVar6 + lVar5) != 0) {
        do {
          uVar3 = (ulonglong)uVar7;
          if (*(char *)(*(longlong *)(lVar6 + 0x10 + lVar5) + 7 + uVar3 * 0x24) == '\x01') {
            puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                               ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
            *puVar4 = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 +
                                uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[1] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[2] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar3 * 0x24) = 0;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextRestored_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(char)uVar7);
            }
          }
          lVar5 = *(longlong *)(this + 0x40);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(lVar6 + lVar5));
      }
      puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress
                         ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
      *puVar4 = *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6);
      LOCK();
      UNLOCK();
      *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 0;
      if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
        McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtBankContextRestored_Info,this + 0x10,
                      *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_c1faf6d1713c3dbc7f768ced3470aaa4_Traceguids,lVar2);
  }
  return;
}



===== GpioSaveBankHardwareContext @ 14000dc90 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_CNL_H::GpioSaveBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_CNL_H::GpioSaveBankHardwareContext
          (_GPIO_CONTROLLER_CNL_H *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  long lVar2;
  ulong *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  longlong lVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_c1faf6d1713c3dbc7f768ced3470aaa4_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar2 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  if (-1 < lVar2) {
    lVar4 = *(longlong *)(this + 0x40);
    uVar6 = 0;
    lVar7 = (ulonglong)uVar1 * 0x20;
    if (*(short *)(lVar7 + lVar4) != 0) {
      do {
        uVar5 = (ulonglong)uVar6;
        lVar4 = *(longlong *)(lVar7 + 0x10 + lVar4);
        if (*(char *)(lVar4 + 0x14 + uVar5 * 0x24) == '\x01') {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x10;
LAB_14000dd60:
            WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                       &WPP_c1faf6d1713c3dbc7f768ced3470aaa4_Traceguids,
                       "_GPIO_CONTROLLER_CNL_H::GpioSaveBankHardwareContext",(char)uVar1,(char)uVar6
                      );
          }
        }
        else if (*(int *)(lVar4 + uVar5 * 0x24) == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x11;
            goto LAB_14000dd60;
          }
        }
        else {
          puVar3 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                             ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar6);
          if ((*puVar3 & 0x3c00) == 0) {
            *(ulong *)(*(longlong *)(lVar7 + 0x10 + *(longlong *)(this + 0x40)) + 8 + uVar5 * 0x24)
                 = *puVar3;
            *(ulong *)(*(longlong *)(lVar7 + 0x10 + *(longlong *)(this + 0x40)) + 0xc + uVar5 * 0x24
                      ) = puVar3[1];
            *(ulong *)(*(longlong *)(lVar7 + 0x10 + *(longlong *)(this + 0x40)) + 0x10 +
                      uVar5 * 0x24) = puVar3[2];
            *(undefined1 *)
             (*(longlong *)(lVar7 + 0x10 + *(longlong *)(this + 0x40)) + 7 + uVar5 * 0x24) = 1;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextSaved_Verbose,this + 0x10,
                             *(char **)(lVar7 + 8 + *(longlong *)(this + 0x40)),(char)uVar6);
            }
          }
        }
        lVar4 = *(longlong *)(this + 0x40);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(ushort *)(lVar7 + lVar4));
    }
    puVar3 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1)
    ;
    *(ulong *)(lVar7 + 0x1c + *(longlong *)(this + 0x40)) = *puVar3;
    *(undefined1 *)(lVar7 + 0x18 + *(longlong *)(this + 0x40)) = 1;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtBankContextSaved_Info,
                    this + 0x10,*(char **)(lVar7 + 8 + *(longlong *)(this + 0x40)));
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_c1faf6d1713c3dbc7f768ced3470aaa4_Traceguids,lVar2);
  }
  return;
}



===== GpioLayout_Allocate @ 14000df00 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_GLK_AUDIO::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_GLK_AUDIO::GpioLayout_Allocate(_GPIO_CONTROLLER_GLK_AUDIO *this)

{
  size_t _Size;
  void *_Dst;
  long lVar1;
  byte bVar2;
  ulonglong uVar3;
  undefined8 local_38;
  
  lVar1 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_4b50a7ccb232370cf22240e33f98ddcf_Traceguids);
  }
  uVar3 = 0;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000b000000000;
  *(_GPIO_CONTROLLER_GLK_AUDIO **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x58) = local_38;
  *(undefined4 *)(this + 0x28) = 0x10001;
  *(_GPIO_CONTROLLER_GLK_AUDIO **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0x60) = 0x1c;
  *(char **)(this + 0x68) = "AUDIO0+";
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar3 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar3 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar3 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar3 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar2 = (char)uVar3 + 1;
    uVar3 = (ulonglong)bVar2;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar2) {
      this[0x2c] = (_GPIO_CONTROLLER_GLK_AUDIO)0x1c;
      *(ushort *)(this + 0x2e) =
           *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                     *(longlong *)(this + 0x40)) + *(ushort *)(this + 0x28) * 0x1c + -0x1c;
      *(undefined2 *)(this + 0x30) = 0x10;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_4b50a7ccb232370cf22240e33f98ddcf_Traceguids);
        }
LAB_14000e0d0:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_4b50a7ccb232370cf22240e33f98ddcf_Traceguids,lVar1);
        }
      }
      return lVar1;
    }
  }
  lVar1 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000e0d0;
}



===== GpioLayout_Allocate @ 14000e130 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_GLK_NORTH::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_GLK_NORTH::GpioLayout_Allocate(_GPIO_CONTROLLER_GLK_NORTH *this)

{
  short sVar1;
  size_t _Size;
  void *_Dst;
  long lVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined8 local_38;
  
  lVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_5ff76a6a211d3366d895a38745ca9b1b_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar4 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000b000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  *(_GPIO_CONTROLLER_GLK_NORTH **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(char **)(this + 0x68) = "NORTH0+";
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x200000100000020;
  *(char **)(this + 0x88) = "NORTH32+";
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x28) = 0x10003;
  *(_GPIO_CONTROLLER_GLK_NORTH **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0xa0) = 0x400000200000010;
  *(char **)(this + 0xa8) = "NORTH64+";
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar4 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar4 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar4 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar4 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar3 = (char)uVar4 + 1;
    uVar4 = (ulonglong)bVar3;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar3) {
      this[0x2c] = (_GPIO_CONTROLLER_GLK_NORTH)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_5ff76a6a211d3366d895a38745ca9b1b_Traceguids);
        }
LAB_14000e37c:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_5ff76a6a211d3366d895a38745ca9b1b_Traceguids,lVar2);
        }
      }
      return lVar2;
    }
  }
  lVar2 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000e37c;
}



===== GpioLayout_Allocate @ 14000e3d0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_GLK_NORTH_WEST::GpioLayout_Allocate(void) __ptr64
    */

long __thiscall
_GPIO_CONTROLLER_GLK_NORTH_WEST::GpioLayout_Allocate(_GPIO_CONTROLLER_GLK_NORTH_WEST *this)

{
  short sVar1;
  size_t _Size;
  void *_Dst;
  long lVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined8 local_38;
  
  lVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_843ceb56a7763994c7d789ad21fea9f6_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar4 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000b000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  *(_GPIO_CONTROLLER_GLK_NORTH_WEST **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(char **)(this + 0x68) = "NORTHWEST0+";
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x200000100000020;
  *(char **)(this + 0x88) = "NORTHWEST32+";
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0x400000200000020;
  *(char **)(this + 0xa8) = "NORTHWEST64+";
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0x28) = 0x10004;
  *(_GPIO_CONTROLLER_GLK_NORTH_WEST **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0xc0) = 0x60000030000000f;
  *(undefined **)(this + 200) = &s_NORTHWEST96_;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar4 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar4 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar4 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar4 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar3 = (char)uVar4 + 1;
    uVar4 = (ulonglong)bVar3;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar3) {
      this[0x2c] = (_GPIO_CONTROLLER_GLK_NORTH_WEST)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_843ceb56a7763994c7d789ad21fea9f6_Traceguids);
        }
LAB_14000e655:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_843ceb56a7763994c7d789ad21fea9f6_Traceguids,lVar2);
        }
      }
      return lVar2;
    }
  }
  lVar2 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000e655;
}



===== GpioLayout_Allocate @ 14000e6b0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_GLK_SCC::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_GLK_SCC::GpioLayout_Allocate(_GPIO_CONTROLLER_GLK_SCC *this)

{
  short sVar1;
  size_t _Size;
  void *_Dst;
  long lVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined8 local_38;
  
  lVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_6812ccfae89a32cebc1c8c7e0738e4a5_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar4 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000b000000000;
  *(undefined8 *)(this + 0x58) = local_38;
  *(_GPIO_CONTROLLER_GLK_SCC **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0x60) = 0x20;
  *(char **)(this + 0x68) = "SCC0+";
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x28) = 0x10002;
  *(undefined8 *)(this + 0x80) = 0x200000100000003;
  *(char **)(this + 0x88) = "SCC32+";
  *(_GPIO_CONTROLLER_GLK_SCC **)(this + 0x40) = this + 0x60;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar4 + 3) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar4 + 3) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar4 * 0x20 + 0x70) = _Dst;
    if (*(longlong *)(uVar4 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar3 = (char)uVar4 + 1;
    uVar4 = (ulonglong)bVar3;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar3) {
      this[0x2c] = (_GPIO_CONTROLLER_GLK_SCC)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_6812ccfae89a32cebc1c8c7e0738e4a5_Traceguids);
        }
LAB_14000e8c3:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_6812ccfae89a32cebc1c8c7e0738e4a5_Traceguids,lVar2);
        }
      }
      return lVar2;
    }
  }
  lVar2 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000e8c3;
}



===== GpioLayout_Allocate @ 14000e920 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_ICL_H::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_ICL_H::GpioLayout_Allocate(_GPIO_CONTROLLER_ICL_H *this)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  size_t _Size;
  void *_Dst;
  long lVar5;
  byte bVar6;
  ulonglong uVar7;
  undefined8 local_38;
  uint uStack_30;
  
  lVar5 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_0d9e093f1c753b309916d4cb166ac47c_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000c000000000;
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x58) = uVar3;
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x10000c000000000;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x10000c000000000;
  *(undefined8 *)(this + 0x70) = uVar4;
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0x10000c000000000;
  *(undefined8 *)(this + 0x88) = uVar3;
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  *(undefined8 *)(this + 0xa0) = uVar4;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0x10000c000000000;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xb8) = local_38;
  uVar7 = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_ICL_H **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0xc0) = 0x90000100000019;
  *(undefined1 **)(this + 200) = &s_GPP_A;
  *(undefined8 *)(this + 0xd0) = 0;
  *(ulonglong *)(this + 0xd8) = uVar7;
  *(undefined2 *)(this + 0x2a) = 5;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xe0) = 0x22000020000001a;
  *(undefined1 **)(this + 0xe8) = &s_GPP_B;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xf0) = 0;
  *(ulonglong *)(this + 0xf8) = uVar7;
  *(undefined8 *)(this + 0x100) = 0x10018;
  *(undefined1 **)(this + 0x108) = &s_GPP_C;
  *(undefined8 *)(this + 0x110) = 0;
  *(ulonglong *)(this + 0x118) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x120) = 0x180000100010012;
  *(undefined1 **)(this + 0x128) = &s_GPP_D;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x130) = 0;
  *(ulonglong *)(this + 0x138) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x140) = 0x2a0000200010008;
  *(undefined1 **)(this + 0x148) = &s_GPP_R;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x150) = 0;
  *(ulonglong *)(this + 0x158) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x160) = 0x320000300010008;
  *(undefined1 **)(this + 0x168) = &s_GPP_S;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x170) = 0;
  *(ulonglong *)(this + 0x178) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x180) = 0x3a0000400010010;
  *(undefined1 **)(this + 0x188) = &s_GPP_G;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 400) = 0;
  *(ulonglong *)(this + 0x198) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1a0) = 0x4a000050001001d;
  *(undefined1 **)(this + 0x1a8) = &s_GPP_V;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x1b0) = 0;
  *(ulonglong *)(this + 0x1b8) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1c0) = 0x2000d;
  *(undefined1 **)(this + 0x1c8) = &s_GPP_E;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x1d0) = 0;
  *(ulonglong *)(this + 0x1d8) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1e0) = 0xd0000100020018;
  *(undefined1 **)(this + 0x1e8) = &s_GPP_F;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x1f0) = 0;
  *(ulonglong *)(this + 0x1f8) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x200) = 0x30018;
  *(undefined1 **)(this + 0x208) = &s_GPP_H;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x210) = 0;
  *(ulonglong *)(this + 0x218) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x220) = 0x18000010003000c;
  *(undefined1 **)(this + 0x228) = &s_GPP_K;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x230) = 0;
  *(ulonglong *)(this + 0x238) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x240) = 0x24000020003000a;
  *(undefined1 **)(this + 0x248) = &s_GPP_J;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x250) = 0;
  *(ulonglong *)(this + 600) = uVar7;
  *(_GPIO_CONTROLLER_ICL_H **)(this + 0x40) = this + 0xc0;
  *(undefined8 *)(this + 0x260) = 0x40012;
  *(undefined1 **)(this + 0x268) = &s_GPP_I;
  *(undefined2 *)(this + 0x28) = 0xe;
  uVar7 = 0;
  *(undefined8 *)(this + 0x270) = 0;
  *(ulonglong *)(this + 0x278) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar7 + 6) * 0x20)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + (uVar7 + 6) * 0x20)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + uVar7 * 0x20 + 0xd0) = _Dst;
    if (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + uVar7 * 0x20) == 0) break;
    bVar6 = (char)uVar7 + 1;
    uVar7 = (ulonglong)bVar6;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar6) {
      this[0x2c] = (_GPIO_CONTROLLER_ICL_H)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_0d9e093f1c753b309916d4cb166ac47c_Traceguids);
        }
LAB_14000ee90:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_0d9e093f1c753b309916d4cb166ac47c_Traceguids,lVar5);
        }
      }
      return lVar5;
    }
  }
  lVar5 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000ee90;
}



===== GpioRestoreBankHardwareContext @ 14000eef0 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_ICL_H::GpioRestoreBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_ICL_H::GpioRestoreBankHardwareContext
          (_GPIO_CONTROLLER_ICL_H *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  long lVar2;
  ulonglong uVar3;
  ulong *puVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_0d9e093f1c753b309916d4cb166ac47c_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar2 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  if (-1 < lVar2) {
    lVar5 = *(longlong *)(this + 0x40);
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(char *)(lVar6 + 0x18 + lVar5) == '\x01') {
      uVar7 = 0;
      if (*(short *)(lVar6 + lVar5) != 0) {
        do {
          uVar3 = (ulonglong)uVar7;
          if (*(char *)(*(longlong *)(lVar6 + 0x10 + lVar5) + 7 + uVar3 * 0x24) == '\x01') {
            puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                               ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
            *puVar4 = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 +
                                uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[1] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[2] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar3 * 0x24) = 0;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextRestored_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(char)uVar7);
            }
          }
          lVar5 = *(longlong *)(this + 0x40);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(lVar6 + lVar5));
      }
      puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress
                         ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
      *puVar4 = *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6);
      LOCK();
      UNLOCK();
      *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 0;
      if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
        McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtBankContextRestored_Info,this + 0x10,
                      *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_0d9e093f1c753b309916d4cb166ac47c_Traceguids,lVar2);
  }
  return;
}



===== GpioSaveBankHardwareContext @ 14000f0f0 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_ICL_H::GpioSaveBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_ICL_H::GpioSaveBankHardwareContext
          (_GPIO_CONTROLLER_ICL_H *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  ulong *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_0d9e093f1c753b309916d4cb166ac47c_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar3 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  uVar7 = 0;
  if (-1 < lVar3) {
    puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioOwnRegAddress
                       ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
    uVar2 = *puVar4;
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(short *)(lVar6 + *(longlong *)(this + 0x40)) != 0) {
      do {
        if ((uVar2 >> ((byte)uVar7 & 0x1f) & 1) != 0) {
          puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                             ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
          if ((*puVar4 & 0x3c00) == 0) {
            uVar5 = (ulonglong)uVar7;
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 + uVar5 * 0x24)
                 = *puVar4;
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc + uVar5 * 0x24
                      ) = puVar4[1];
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                      uVar5 * 0x24) = puVar4[2];
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar5 * 0x24) = 1;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextSaved_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(byte)uVar7);
            }
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(lVar6 + *(longlong *)(this + 0x40)));
    }
    puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1)
    ;
    *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6) = *puVar4;
    *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 1;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtBankContextSaved_Info,
                    this + 0x10,*(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_0d9e093f1c753b309916d4cb166ac47c_Traceguids,lVar3);
  }
  return;
}



===== GpioLayout_Allocate @ 14000f2e0 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_LKF::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_LKF::GpioLayout_Allocate(_GPIO_CONTROLLER_LKF *this)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  size_t _Size;
  void *_Dst;
  longlong lVar6;
  long lVar7;
  byte bVar8;
  ulonglong uVar9;
  undefined8 local_38;
  uint uStack_30;
  
  lVar7 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_8d82b202e90f3d34ab239b5fbcde9be2_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100009000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar5 = local_38;
  *(undefined8 *)(this + 0x58) = uVar4;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x100009000000000;
  *(undefined8 *)(this + 0x70) = uVar5;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x100009000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  *(undefined8 *)(this + 0x88) = uVar4;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0x100009000000000;
  uVar3 = uStack_30 >> 8;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xa0) = local_38;
  uVar2 = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(_GPIO_CONTROLLER_LKF **)(this + 0x38) = this + 0x48;
  *(undefined2 *)(this + 0x2a) = 4;
  *(undefined8 *)(this + 0xa8) = 0x20;
  *(char **)(this + 0xb0) = "EAST0+";
  *(undefined8 *)(this + 0xb8) = 0;
  *(ulonglong *)(this + 0xc0) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 200) = 0x20000010000001c;
  *(char **)(this + 0xd0) = "EAST32+";
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0xd8) = 0;
  *(ulonglong *)(this + 0xe0) = uVar2;
  *(undefined8 *)(this + 0xe8) = 0x10020;
  *(char **)(this + 0xf0) = "NORTHWEST0+";
  *(undefined8 *)(this + 0xf8) = 0;
  *(ulonglong *)(this + 0x100) = (ulonglong)uStack_30;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x108) = 0x200000100010020;
  *(char **)(this + 0x110) = "NORTHWEST32+";
  *(undefined8 *)(this + 0x118) = 0;
  *(ulonglong *)(this + 0x120) = (ulonglong)uStack_30;
  uVar9 = 0;
  uStack_30 = uVar3 << 8;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x128) = 0x400000200010019;
  *(char **)(this + 0x130) = "NORTHWEST64+";
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x138) = 0;
  *(ulonglong *)(this + 0x140) = uVar2;
  *(_GPIO_CONTROLLER_LKF **)(this + 0x40) = this + 0xa8;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x148) = 0x20020;
  *(undefined1 **)(this + 0x150) = &s_WEST0_;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x158) = 0;
  *(ulonglong *)(this + 0x160) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x168) = 0x200000100020020;
  *(undefined1 **)(this + 0x170) = &s_WEST32_;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x178) = 0;
  *(ulonglong *)(this + 0x180) = uVar2;
  uVar2 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x188) = 0x400000200020019;
  *(undefined1 **)(this + 400) = &s_WEST64_;
  uStack_30 = uVar3 << 8;
  *(undefined8 *)(this + 0x198) = 0;
  *(ulonglong *)(this + 0x1a0) = uVar2;
  *(undefined2 *)(this + 0x28) = 9;
  *(undefined8 *)(this + 0x1a8) = 0x3001d;
  *(char **)(this + 0x1b0) = "SOUTHEAST0+";
  *(undefined8 *)(this + 0x1b8) = 0;
  *(ulonglong *)(this + 0x1c0) = (ulonglong)uStack_30;
  while( true ) {
    lVar6 = uVar9 * 0x20;
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + lVar6 + 0xa8)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + lVar6 + 0xa8)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + lVar6 + 0xb8) = _Dst;
    if (*(longlong *)(lVar6 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar8 = (char)uVar9 + 1;
    uVar9 = (ulonglong)bVar8;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar8) {
      this[0x2c] = (_GPIO_CONTROLLER_LKF)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_8d82b202e90f3d34ab239b5fbcde9be2_Traceguids);
        }
LAB_14000f704:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_8d82b202e90f3d34ab239b5fbcde9be2_Traceguids,lVar7);
        }
      }
      return lVar7;
    }
  }
  lVar7 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000f704;
}



===== GpioLayout_Allocate @ 14000f760 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_LKF_FPGA::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_LKF_FPGA::GpioLayout_Allocate(_GPIO_CONTROLLER_LKF_FPGA *this)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  size_t _Size;
  void *_Dst;
  long lVar5;
  byte bVar6;
  ulonglong uVar7;
  undefined8 local_38;
  uint uStack_30;
  
  lVar5 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_1e75b64896b333cbb71e64c0035b0293_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x100008000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x58) = uVar3;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x100008000000000;
  local_38 = CONCAT44(local_38._4_4_,0x6000110);
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x100008000000000;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x70) = uVar4;
  *(undefined8 *)(this + 0x88) = local_38;
  uVar7 = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_LKF_FPGA **)(this + 0x38) = this + 0x48;
  *(undefined2 *)(this + 0x2a) = 3;
  *(undefined8 *)(this + 0x90) = 0x20;
  *(char **)(this + 0x98) = "GPP_GB";
  *(undefined8 *)(this + 0xa0) = 0;
  *(ulonglong *)(this + 0xa8) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xb0) = 0x20000010000001a;
  *(char **)(this + 0xb8) = "GPP_BA";
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xc0) = 0;
  *(ulonglong *)(this + 200) = uVar7;
  uVar7 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xd0) = 0x10019;
  *(undefined1 **)(this + 0xd8) = &s_GPP_A;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xe0) = 0;
  *(ulonglong *)(this + 0xe8) = uVar7;
  *(undefined8 *)(this + 0xf0) = 0x20020;
  *(undefined1 **)(this + 0xf8) = &s_GPP_H;
  *(undefined8 *)(this + 0x100) = 0;
  *(ulonglong *)(this + 0x108) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x110) = 0x200000100020020;
  *(char **)(this + 0x118) = "GPP_DF";
  uVar7 = 0;
  *(undefined8 *)(this + 0x120) = 0;
  *(ulonglong *)(this + 0x128) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_LKF_FPGA **)(this + 0x40) = this + 0x90;
  *(undefined8 *)(this + 0x130) = 0x400000200020011;
  *(undefined1 **)(this + 0x138) = &s_GPP_FV;
  *(undefined2 *)(this + 0x28) = 6;
  *(undefined8 *)(this + 0x140) = 0;
  *(ulonglong *)(this + 0x148) = (ulonglong)uStack_30;
  while( true ) {
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + uVar7 * 0x20 + 0x90)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + uVar7 * 0x20 + 0x90)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + (uVar7 + 5) * 0x20) = _Dst;
    if (*(longlong *)(uVar7 * 0x20 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar6 = (char)uVar7 + 1;
    uVar7 = (ulonglong)bVar6;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar6) {
      this[0x2c] = (_GPIO_CONTROLLER_LKF_FPGA)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_1e75b64896b333cbb71e64c0035b0293_Traceguids);
        }
LAB_14000fab5:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_1e75b64896b333cbb71e64c0035b0293_Traceguids,lVar5);
        }
      }
      return lVar5;
    }
  }
  lVar5 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000fab5;
}



===== GpioLayout_Allocate @ 14000fb10 =====

/* public: virtual long __cdecl _GPIO_CONTROLLER_TGL_LP::GpioLayout_Allocate(void) __ptr64 */

long __thiscall _GPIO_CONTROLLER_TGL_LP::GpioLayout_Allocate(_GPIO_CONTROLLER_TGL_LP *this)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  size_t _Size;
  void *_Dst;
  longlong lVar5;
  long lVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined8 local_38;
  uint uStack_30;
  
  lVar6 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_55bb5cbe5570319d18c50ef3ac692512_Traceguids);
  }
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0x10000b000000000;
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  uVar4 = local_38;
  *(undefined8 *)(this + 0x58) = uVar3;
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  uVar3 = local_38;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0x10000b000000000;
  *(undefined8 *)(this + 0x70) = uVar4;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x10000b000000000;
  local_38 = CONCAT44(local_38._4_4_,0x7000120);
  *(undefined8 *)(this + 0x88) = uVar3;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0x10000b000000000;
  uVar2 = uStack_30 >> 8;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xa0) = local_38;
  uVar8 = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_TGL_LP **)(this + 0x38) = this + 0x48;
  *(undefined8 *)(this + 0xa8) = 0x1a;
  *(undefined1 **)(this + 0xb0) = &s_GPP_B;
  *(undefined2 *)(this + 0x2a) = 4;
  *(undefined8 *)(this + 0xb8) = 0;
  *(ulonglong *)(this + 0xc0) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 200) = 0x1a0000100000010;
  *(undefined1 **)(this + 0xd0) = &s_GPP_T;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xd8) = 0;
  *(ulonglong *)(this + 0xe0) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0xe8) = 0x2a0000200000019;
  *(undefined1 **)(this + 0xf0) = &s_GPP_A;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0xf8) = 0;
  *(ulonglong *)(this + 0x100) = uVar8;
  *(undefined8 *)(this + 0x108) = 0x10008;
  *(undefined1 **)(this + 0x110) = &s_GPP_S;
  *(undefined8 *)(this + 0x118) = 0;
  *(ulonglong *)(this + 0x120) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x128) = 0x80000100010018;
  *(undefined1 **)(this + 0x130) = &s_GPP_H;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x138) = 0;
  *(ulonglong *)(this + 0x140) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x148) = 0x200000200010015;
  *(undefined1 **)(this + 0x150) = &s_GPP_D;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x158) = 0;
  *(ulonglong *)(this + 0x160) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x168) = 0x350000300010018;
  *(undefined1 **)(this + 0x170) = &s_GPP_U;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x178) = 0;
  *(ulonglong *)(this + 0x180) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x188) = 0x4d000040001001b;
  *(undefined1 **)(this + 400) = &s_GPP_V;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x198) = 0;
  *(ulonglong *)(this + 0x1a0) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1a8) = 0x20019;
  *(undefined1 **)(this + 0x1b0) = &s_GPP_F;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x1b8) = 0;
  *(ulonglong *)(this + 0x1c0) = uVar8;
  uVar8 = (ulonglong)uStack_30;
  *(undefined8 *)(this + 0x1c8) = 0x190000100020018;
  *(undefined1 **)(this + 0x1d0) = &s_GPP_C;
  uStack_30 = uVar2 << 8;
  *(undefined8 *)(this + 0x1d8) = 0;
  *(ulonglong *)(this + 0x1e0) = uVar8;
  *(undefined8 *)(this + 0x1e8) = 0x370000300020019;
  *(undefined1 **)(this + 0x1f0) = &s_GPP_E;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(ulonglong *)(this + 0x200) = (ulonglong)uStack_30;
  uStack_30 = uVar2 << 8;
  *(_GPIO_CONTROLLER_TGL_LP **)(this + 0x40) = this + 0xa8;
  *(undefined2 *)(this + 0x28) = 0xc;
  uVar8 = 0;
  *(undefined8 *)(this + 0x208) = 0x30008;
  *(undefined1 **)(this + 0x210) = &s_GPP_R;
  *(undefined8 *)(this + 0x218) = 0;
  *(ulonglong *)(this + 0x220) = (ulonglong)uStack_30;
  while( true ) {
    lVar5 = uVar8 * 0x20;
    _Size = SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + lVar5 + 0xa8)),0);
    if (SUB168(ZEXT816(0x24) * ZEXT216(*(ushort *)(this + lVar5 + 0xa8)),8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,_Size,0x49504749);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
    }
    *(void **)(this + lVar5 + 0xb8) = _Dst;
    if (*(longlong *)(lVar5 + 0x10 + *(longlong *)(this + 0x40)) == 0) break;
    bVar7 = (char)uVar8 + 1;
    uVar8 = (ulonglong)bVar7;
    if (*(ushort *)(this + 0x28) <= (ushort)bVar7) {
      this[0x2c] = (_GPIO_CONTROLLER_TGL_LP)0x20;
      sVar1 = *(short *)((ulonglong)*(ushort *)(this + 0x28) * 0x20 + -0x20 +
                        *(longlong *)(this + 0x40));
      *(undefined2 *)(this + 0x30) = 0x10;
      *(ushort *)(this + 0x2e) = sVar1 + *(ushort *)(this + 0x28) * 0x20 + -0x20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_55bb5cbe5570319d18c50ef3ac692512_Traceguids);
        }
LAB_14000ffdc:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_55bb5cbe5570319d18c50ef3ac692512_Traceguids,lVar6);
        }
      }
      return lVar6;
    }
  }
  lVar6 = -0x3fffff66;
  if ((Intel_iaLPSS2_GPIO2EnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                 (uint *)&EvtPrepareController_LayoutPinTable_Error,this + 0x10);
  }
  goto LAB_14000ffdc;
}



===== GpioRestoreBankHardwareContext @ 140010030 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_TGL_LP::GpioRestoreBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_TGL_LP::GpioRestoreBankHardwareContext
          (_GPIO_CONTROLLER_TGL_LP *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  long lVar2;
  ulonglong uVar3;
  ulong *puVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_55bb5cbe5570319d18c50ef3ac692512_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar2 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  if (-1 < lVar2) {
    lVar5 = *(longlong *)(this + 0x40);
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(char *)(lVar6 + 0x18 + lVar5) == '\x01') {
      uVar7 = 0;
      if (*(short *)(lVar6 + lVar5) != 0) {
        do {
          uVar3 = (ulonglong)uVar7;
          if (*(char *)(*(longlong *)(lVar6 + 0x10 + lVar5) + 7 + uVar3 * 0x24) == '\x01') {
            puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                               ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
            *puVar4 = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 +
                                uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[1] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            puVar4[2] = *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                                  uVar3 * 0x24);
            LOCK();
            UNLOCK();
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar3 * 0x24) = 0;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextRestored_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(char)uVar7);
            }
          }
          lVar5 = *(longlong *)(this + 0x40);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(lVar6 + lVar5));
      }
      puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress
                         ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
      *puVar4 = *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6);
      LOCK();
      UNLOCK();
      *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 0;
      if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
        McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                      (uint *)&EvtBankContextRestored_Info,this + 0x10,
                      *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_55bb5cbe5570319d18c50ef3ac692512_Traceguids,lVar2);
  }
  return;
}



===== GpioSaveBankHardwareContext @ 140010230 =====

/* public: virtual void __cdecl _GPIO_CONTROLLER_TGL_LP::GpioSaveBankHardwareContext(struct
   _GPIO_DEVICE_CONTEXT * __ptr64,struct _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *
   __ptr64) __ptr64 */

void __thiscall
_GPIO_CONTROLLER_TGL_LP::GpioSaveBankHardwareContext
          (_GPIO_CONTROLLER_TGL_LP *this,_GPIO_DEVICE_CONTEXT *param_1,
          _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS *param_2)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  ulong *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  ushort uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_55bb5cbe5570319d18c50ef3ac692512_Traceguids);
  }
  uVar1 = *(ushort *)param_2;
  lVar3 = _GPIO_CONTROLLER_CHASSIS3::GpioValidateBankRange((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
  uVar7 = 0;
  if (-1 < lVar3) {
    puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioOwnRegAddress
                       ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1);
    uVar2 = *puVar4;
    lVar6 = (ulonglong)uVar1 * 0x20;
    if (*(short *)(lVar6 + *(longlong *)(this + 0x40)) != 0) {
      do {
        if ((uVar2 >> ((byte)uVar7 & 0x1f) & 1) != 0) {
          puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioPadRegAddress
                             ((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1,uVar7);
          if ((*puVar4 & 0x3c00) == 0) {
            uVar5 = (ulonglong)uVar7;
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 8 + uVar5 * 0x24)
                 = *puVar4;
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0xc + uVar5 * 0x24
                      ) = puVar4[1];
            *(ulong *)(*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 0x10 +
                      uVar5 * 0x24) = puVar4[2];
            *(undefined1 *)
             (*(longlong *)(*(longlong *)(this + 0x40) + 0x10 + lVar6) + 7 + uVar5 * 0x24) = 1;
            if ((Intel_iaLPSS2_GPIO2EnableBits & 0x10) != 0) {
              McTemplateK0sq((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,
                             (uint *)&EvtPinContextSaved_Verbose,this + 0x10,
                             *(char **)(*(longlong *)(this + 0x40) + 8 + lVar6),(byte)uVar7);
            }
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(lVar6 + *(longlong *)(this + 0x40)));
    }
    puVar4 = _GPIO_CONTROLLER_CHASSIS3::GetGpioIeRegAddress((_GPIO_CONTROLLER_CHASSIS3 *)this,uVar1)
    ;
    *(ulong *)(*(longlong *)(this + 0x40) + 0x1c + lVar6) = *puVar4;
    *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18 + lVar6) = 1;
    if ((Intel_iaLPSS2_GPIO2EnableBits & 2) != 0) {
      McTemplateK0s((undefined8 *)&iaLPSS2_GPIO2_PROVIDER_Context,(uint *)&EvtBankContextSaved_Info,
                    this + 0x10,*(char **)(*(longlong *)(this + 0x40) + 8 + lVar6));
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_55bb5cbe5570319d18c50ef3ac692512_Traceguids,lVar3);
  }
  return;
}



===== GetRegistrySettings @ 14001041c =====

/* void __cdecl GetRegistrySettings(struct _GPIO_DRIVER_CONTEXT * __ptr64) */

void __cdecl GetRegistrySettings(_GPIO_DRIVER_CONTEXT *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int iVar4;
  __uint64 in_RDX;
  WDFKEY__ *pWVar5;
  WDFKEY__ *local_res10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_RDX = 0xf;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids);
  }
  puVar3 = WdfDriverGlobals;
  pcVar1 = *(code **)(WdfFunctions_01015 + 0x3b8);
  uVar2 = *WdfDriverGlobals;
  __empty_global_delete(pcVar1,in_RDX);
  iVar4 = (*pcVar1)(puVar3,uVar2,0x1f0000,0,&local_res10);
  if (iVar4 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids,iVar4);
    }
  }
  else {
    pWVar5 = local_res10;
    ReadRegistryKeyForController(param_1,local_res10,(ushort *)L"PinMux",(ulong *)(param_1 + 8));
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x738);
    __empty_global_delete(pcVar1,(__uint64)pWVar5);
    (*pcVar1)(WdfDriverGlobals,local_res10);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids);
    }
  }
  return;
}



===== ReadRegistryKeyForController @ 140010564 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ReadRegistryKeyForController(struct _GPIO_DRIVER_CONTEXT * __ptr64,struct WDFKEY__ *
   __ptr64,unsigned short * __ptr64,unsigned long * __ptr64) */

void __cdecl
ReadRegistryKeyForController
          (_GPIO_DRIVER_CONTEXT *param_1,WDFKEY__ *param_2,ushort *param_3,ulong *param_4)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStackY_298 [32];
  ulong local_268 [2];
  undefined4 local_260 [2];
  undefined1 *local_258;
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_298;
  local_268[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids);
  }
  local_258 = local_248;
  local_260[0] = 0x2000000;
  puVar4 = &u__ws;
  lVar2 = RtlUnicodeStringPrintf((_UNICODE_STRING *)local_260,(ushort *)&u__ws,param_3);
  if (lVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids,(undefined1 *)param_3,(char)lVar2);
    }
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x780);
    __empty_global_delete(pcVar1,(__uint64)puVar4);
    iVar3 = (*pcVar1)(WdfDriverGlobals,param_2,local_260,local_268);
    if (iVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids,"ReadRegistryKeyForController",
                  (undefined1 *)param_3);
      }
    }
    else {
      *param_4 = local_268[0];
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_SdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids,(undefined1 *)param_3,
                   (char)local_268[0],(char)local_268[0]);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids);
  }
  return;
}



===== RtlUnicodeStringPrintf @ 14001073c =====

/* long __cdecl RtlUnicodeStringPrintf(struct _UNICODE_STRING * __ptr64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlUnicodeStringPrintf(_UNICODE_STRING *param_1,ushort *param_2,...)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  long lVar5;
  size_t _Count;
  undefined8 in_R8;
  undefined8 in_R9;
  wchar_t *_Dest;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *(ushort *)param_1;
  _Count = 0;
  lVar5 = 0;
  if (((((uVar1 & 1) == 0) && (uVar2 = *(ushort *)(param_1 + 2), (uVar2 & 1) == 0)) &&
      (uVar1 <= uVar2)) && (uVar2 != 0xffff)) {
    _Dest = *(wchar_t **)(param_1 + 8);
    if ((_Dest == (wchar_t *)0x0) && ((uVar1 != 0 || (uVar2 != 0)))) {
      lVar5 = -0x3ffffff3;
      _Dest = (wchar_t *)0x0;
    }
    else {
      _Count = (size_t)(uVar2 >> 1);
    }
    if (-1 < lVar5) {
      lVar5 = 0;
      local_res18 = in_R8;
      local_res20 = in_R9;
      iVar3 = _vsnwprintf(_Dest,_Count,(wchar_t *)param_2,(va_list)&local_res18);
      if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
        lVar5 = -0x7ffffffb;
        uVar4 = _Count;
      }
      *(short *)param_1 = (short)uVar4 * 2;
    }
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== SetDefaultParameter @ 1400107e8 =====

/* void __cdecl SetDefaultParameter(struct _GPIO_DRIVER_CONTEXT * __ptr64,unsigned short *
   __ptr64,unsigned long * __ptr64,unsigned long) */

void __cdecl
SetDefaultParameter(_GPIO_DRIVER_CONTEXT *param_1,ushort *param_2,ulong *param_3,ulong param_4)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids);
  }
  *param_3 = param_4;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_sSdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids,"SetDefaultParameter",
                  (undefined1 *)param_2,(char)param_4,(char)param_4);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_4e776af3b46c3ef0c0f8f67e161558ac_Traceguids);
    }
  }
  return;
}



===== SetDefaultSettings @ 1400108c4 =====

/* void __cdecl SetDefaultSettings(struct _GPIO_DRIVER_CONTEXT * __ptr64) */

void __cdecl SetDefaultSettings(_GPIO_DRIVER_CONTEXT *param_1)

{
  SetDefaultParameter(param_1,(ushort *)L"PinMux",(ulong *)(param_1 + 8),0);
  return;
}



===== WPP_SF_Sd @ 1400108d8 =====

void WPP_SF_Sd(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined1 *param_4,
              undefined1 param_5)

{
  code *pcVar1;
  longlong lVar2;
  undefined1 *puVar3;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (undefined1 *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_4 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  puVar3 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    puVar3 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,puVar3,lVar2,&param_5,4,0);
  return;
}



===== WPP_SF_SdD @ 140010998 =====

void WPP_SF_SdD(undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined1 *param_4,
               undefined1 param_5,undefined1 param_6)

{
  code *pcVar1;
  longlong lVar2;
  undefined1 *puVar3;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_4 == (undefined1 *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_4 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  puVar3 = &u_NULL;
  if (param_4 != (undefined1 *)0x0) {
    puVar3 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,puVar3,lVar2,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_sS @ 140010a68 =====

void WPP_SF_sS(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4,
              undefined1 *param_5)

{
  code *pcVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 *puVar6;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_5 == (undefined1 *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_5 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  lVar4 = -1;
  if (param_4 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_4[lVar4] != '\0');
    lVar5 = lVar5 + 2;
  }
  puVar6 = &u_NULL;
  if (param_5 != (undefined1 *)0x0) {
    puVar6 = param_5;
  }
  pcVar3 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar3 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar3,lVar5,puVar6,lVar2,0);
  return;
}



===== WPP_SF_sSdD @ 140010b4c =====

void WPP_SF_sSdD(undefined8 param_1,ulonglong param_2,undefined8 param_3,char *param_4,
                undefined1 *param_5,undefined1 param_6,undefined1 param_7)

{
  code *pcVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 *puVar6;
  
  pcVar1 = pfnWppTraceMessage;
  if (param_5 == (undefined1 *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_5 + lVar2 * 2) != 0);
    lVar2 = lVar2 * 2 + 2;
  }
  lVar4 = -1;
  if (param_4 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_4[lVar4] != '\0');
    lVar5 = lVar5 + 2;
  }
  puVar6 = &u_NULL;
  if (param_5 != (undefined1 *)0x0) {
    puVar6 = param_5;
  }
  pcVar3 = "NULL";
  if (param_4 != (char *)0x0) {
    pcVar3 = param_4;
  }
  __empty_global_delete(pfnWppTraceMessage,param_2);
  (*pcVar1)(param_1,0x2b,param_3,param_2 & 0xffff,pcVar3,lVar5,puVar6,lVar2,&param_6,4,&param_7,4,0)
  ;
  return;
}



===== __security_check_cookie @ 140010c70 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 140010c90 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 140010ca0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140010cc0 =====

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



===== wcsnlen @ 140010d20 =====

size_t __cdecl wcsnlen(wchar_t *_Src,size_t _MaxCount)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140010d20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = wcsnlen(_Src,_MaxCount);
  return sVar1;
}



===== wcsncmp @ 140010d26 =====

int __cdecl wcsncmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140010d26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcsncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== _purecall @ 140010d30 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140010d30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== memcpy_s @ 140010d36 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140010d36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  eVar1 = memcpy_s(_Dst,_DstSize,_Src,_MaxCount);
  return eVar1;
}



===== _vsnwprintf @ 140010d3c =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140010d3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _vsnwprintf(_Dest,_Count,_Format,_Args);
  return iVar1;
}



===== FxStubDriverUnloadCommon @ 140010d44 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140016090);
  WdfVersionUnbind(&DAT_140016208,&DAT_140016090,WdfDriverGlobals);
  return;
}



===== entry @ 140010d80 =====

void entry(undefined4 *param_1,__uint64 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140010dac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(undefined4 *param_1,__uint64 param_2)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = DriverEntry((undefined4 *)0x0,param_2);
  }
  else {
    _DAT_140016210 = &DAT_140016240;
    _DAT_140016208 = 0x2080000;
    _DAT_140016230 = param_1;
    RtlCopyUnicodeString(&DAT_140016208);
    iVar1 = WdfVersionBind(param_1,&DAT_140016208,&DAT_140016090,&WdfDriverGlobals);
    if (-1 < iVar1) {
      _WdfDriverMiniportUnloadOverride = *(code **)(WdfFunctions_01015 + 0x648);
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&DAT_140016090);
      if (((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) &&
         (iVar1 = DriverEntry(param_1,param_2), -1 < iVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _WdfDriverMiniportUnloadOverride = FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x1a) != 0) {
            DAT_140016218 = *(longlong *)(param_1 + 0x1a);
          }
          *(code **)(param_1 + 0x1a) = FxStubDriverUnload;
        }
        return 0;
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverMiniportUnload @ 140010ee0 =====

void __cdecl FxStubDriverMiniportUnload(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&DAT_140016090);
  WdfVersionUnbind(&DAT_140016208,&DAT_140016090,WdfDriverGlobals);
  return;
}



===== FxStubDriverUnload @ 140010ef0 =====

void FxStubDriverUnload(undefined8 param_1,__uint64 param_2)

{
  code *pcVar1;
  
  pcVar1 = DAT_140016218;
  if ((DAT_140016218 != (code *)0x0) && (DAT_140016218 != FxStubDriverUnload)) {
    __empty_global_delete(DAT_140016218,param_2);
    (*pcVar1)(param_1);
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 140010f34 =====

/* WARNING: Removing unreachable block (ram,0x000140010f69) */
/* WARNING: Removing unreachable block (ram,0x000140010f70) */
/* WARNING: Removing unreachable block (ram,0x000140010fac) */
/* WARNING: Removing unreachable block (ram,0x000140010f76) */
/* WARNING: Removing unreachable block (ram,0x000140010f7e) */
/* WARNING: Removing unreachable block (ram,0x000140010f8d) */
/* WARNING: Removing unreachable block (ram,0x000140010f56) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  return 0;
}



===== FxStubBindClasses @ 140010fb4 =====

/* WARNING: Removing unreachable block (ram,0x000140010fe0) */
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
    if ((int *)0x14001611f < piVar3) {
      return iVar2;
    }
    if (*piVar3 != 0x50) break;
    pcVar1 = *(code **)(piVar3 + 0xe);
    PTR___KMDF_CLASS_BIND_START_140016128 = (undefined *)piVar3;
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



===== FxStubUnbindClasses @ 140011060 =====

/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  code *pcVar1;
  _WDF_BIND_INFO *in_RDX;
  undefined4 *puVar2;
  
  puVar2 = &_GPIOClx_BIND_INFO;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140016128 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x1400160cf < PTR___KMDF_CLASS_BIND_START_140016128)) {
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
    } while (puVar2 <= PTR___KMDF_CLASS_BIND_START_140016128);
  }
  return;
}



===== WdfVersionBind @ 1400110ea =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400110ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 1400110f0 =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400110f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 140011100 =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140011100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 140011110 =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140011110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== _guard_dispatch_icall @ 140011130 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140011130. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 140011140 =====

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
        if (uVar12 == 0) goto LAB_1400112f7;
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
LAB_1400112f7:
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
      if (uVar12 == 0) goto LAB_140011152;
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
LAB_140011152:
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



===== memset @ 140011480 =====

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



===== WppCleanupKm @ 140018000 =====

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



===== WppInitKm @ 14001808c =====

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



===== WppLoadTracingSupport @ 140018128 =====

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



===== WppTraceCallback @ 140018230 =====

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



===== __security_init_cookie @ 140019000 =====

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
  __security_cookie_complement = ~__security_cookie;
  return;
}


