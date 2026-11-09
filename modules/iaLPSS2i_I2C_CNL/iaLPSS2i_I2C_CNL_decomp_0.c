
===== OnDeviceAdd @ 140001000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OnDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl OnDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  uint uVar1;
  int iVar2;
  PBC_DEVICE *pPVar3;
  undefined *puVar4;
  uint uVar5;
  undefined1 auStackY_1e8 [32];
  WDFDEVICE_INIT *local_198;
  WDFDEVICE__ *local_190;
  undefined4 local_188;
  undefined4 local_184;
  code *local_180;
  code *local_178;
  code *local_170;
  code *local_168;
  code *local_160;
  code *local_158;
  code *local_150;
  code *local_148;
  code *local_140;
  undefined4 local_12c;
  code *local_118;
  code *local_f8;
  undefined4 local_f0 [6];
  undefined4 local_d8;
  undefined4 local_d4;
  undefined *local_c0;
  undefined4 local_b8 [6];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined *local_50;
  undefined4 local_48;
  ushort uStack_44;
  undefined2 uStack_42;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1e8;
  uVar5 = 0xff;
  local_198 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_bf0487c9480e392d62240d692a4b9b13_Traceguids,0xff);
  }
  EtwActivityIdControl(3,&local_48);
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDeviceAdd_Start,&local_48);
  }
  iVar2 = (*SpbFunctions)(SpbDriverGlobals);
  if (iVar2 < 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDeviceSpbDeviceInitConfig_Error,
                    0,iVar2);
    }
    goto LAB_140001b0c;
  }
  memset(&local_188,0,0x90);
  local_160 = OnPrepareHardware;
  local_158 = OnReleaseHardware;
  local_180 = OnD0Entry;
  local_170 = OnD0Exit;
  local_140 = OnSelfManagedIoInit;
  local_150 = OnSelfManagedIoCleanup;
  local_118 = OnQueryStop;
  local_188 = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_198,&local_188);
  (**(code **)(WdfFunctions_01015 + 0x230))(WdfDriverGlobals,local_198,0x80,1);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x220))(WdfDriverGlobals);
  if (iVar2 < 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140001b0c;
    puVar4 = &EvtDeviceWdfDeviceInitAssignSDDLString_Error;
  }
  else {
    memset(local_f0,0,0x38);
    local_c0 = PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0;
    local_f0[0] = 0x38;
    local_d8 = 1;
    local_d4 = 1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_198,local_f0,&local_190)
    ;
    if (iVar2 < 0) {
      if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140001b0c;
      puVar4 = &EvtDeviceCreate_Error;
    }
    else {
      pPVar3 = (PBC_DEVICE *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_190,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
      *(WDFDEVICE__ **)pPVar3 = local_190;
      iVar2 = CheckSupportedHardware(local_190);
      if (iVar2 < 0) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
          McTemplateK0qqqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDeviceHw_Error,&local_48,
                           *(undefined4 *)(pPVar3 + 0x40),(char)*(undefined4 *)(pPVar3 + 0x44),
                           (char)*(undefined4 *)(pPVar3 + 0x48),(char)*(undefined4 *)(pPVar3 + 0x4c)
                          );
        }
        goto LAB_140001b0c;
      }
      uStack_44 = *(ushort *)(pPVar3 + 0x40) | 0x8000;
      uVar5 = *(uint *)(pPVar3 + 0x40);
      *(ulonglong *)(pPVar3 + 8) =
           CONCAT26(uStack_42,CONCAT24(*(ushort *)(pPVar3 + 0x40),local_48)) | 0x800000000000;
      *(undefined8 *)(pPVar3 + 0x10) = uStack_40;
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0qqqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDeviceHw_Info,&local_48,
                         uVar5,(char)*(undefined4 *)(pPVar3 + 0x44),
                         (char)*(undefined4 *)(pPVar3 + 0x48),(char)*(undefined4 *)(pPVar3 + 0x4c));
      }
      GetDefaultSettings(pPVar3);
      OverrideDefaultsForHardware(pPVar3);
      GetAcpiSettings(pPVar3);
      GetRegistrySettings(pPVar3);
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
             (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
               (((uVar1 & 0x8000) != 0 && (uVar5 == 4)))) ||
              ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))))) {
          WPP_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                        &WPP_bf0487c9480e392d62240d692a4b9b13_Traceguids,uVar5,
                        (char)*(undefined4 *)(pPVar3 + 0xa0),(char)*(undefined4 *)(pPVar3 + 0xa4),
                        (char)*(undefined4 *)(pPVar3 + 0xa8),(char)*(undefined4 *)(pPVar3 + 0xac),
                        (char)*(undefined4 *)(pPVar3 + 0xb0));
        }
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
          if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
               ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))))) ||
              (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                (((uVar1 & 0x8000) != 0 && (uVar5 == 4)))) ||
               ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))) {
            WPP_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                          &WPP_bf0487c9480e392d62240d692a4b9b13_Traceguids,uVar5,
                          (char)*(undefined4 *)(pPVar3 + 0xb4),(char)*(undefined4 *)(pPVar3 + 0xb8),
                          (char)*(undefined4 *)(pPVar3 + 0xbc),(char)*(undefined4 *)(pPVar3 + 0xc0),
                          (char)*(undefined4 *)(pPVar3 + 0xc4));
          }
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
            if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
                (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
                  (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
                 (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                   (((uVar1 & 0x8000) != 0 && (uVar5 == 4)))) ||
                  ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))))) {
              WPP_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                            &WPP_bf0487c9480e392d62240d692a4b9b13_Traceguids,uVar5,
                            (char)*(undefined4 *)(pPVar3 + 200),(char)*(undefined4 *)(pPVar3 + 0xcc)
                            ,(char)*(undefined4 *)(pPVar3 + 0xd0),
                            (char)*(undefined4 *)(pPVar3 + 0xd4),
                            (char)*(undefined4 *)(pPVar3 + 0xd8));
            }
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
                    (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
                   (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
                 ((((uVar1 & 0x8000) != 0 && (uVar5 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))) || (5 < uVar5)))) {
              WPP_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                            &WPP_bf0487c9480e392d62240d692a4b9b13_Traceguids,uVar5,
                            (char)*(undefined4 *)(pPVar3 + 0xdc),
                            (char)*(undefined4 *)(pPVar3 + 0xe0),
                            (char)*(undefined4 *)(pPVar3 + 0xe4),
                            (char)*(undefined4 *)(pPVar3 + 0xe8),
                            (char)*(undefined4 *)(pPVar3 + 0xec));
            }
          }
        }
      }
      local_70 = 0;
      local_80 = 0x1c;
      local_7c = 2;
      local_78 = (code *)0x200000002;
      local_6c = 2;
      local_68 = 2;
      (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,*(undefined8 *)pPVar3,&local_80);
      local_178 = OnTargetConnect;
      local_170 = OnTargetDisconnect;
      local_158 = OnRead;
      local_150 = OnWrite;
      local_148 = OnSequence;
      local_168 = OnControllerLock;
      local_160 = OnControllerUnlock;
      local_188 = 0x48;
      local_184 = 1;
      local_180 = (code *)0x1;
      iVar2 = (*DAT_1400224e8)(SpbDriverGlobals,*(undefined8 *)pPVar3);
      if (iVar2 < 0) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140001b0c;
        puVar4 = &EvtDeviceSpbDeviceInitialize_Error;
      }
      else {
        (*DAT_1400224f0)(SpbDriverGlobals,*(undefined8 *)pPVar3,OnOther,OnOtherInCallerContext);
        memset(&local_80,0,0x38);
        local_50 = PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8;
        local_80 = 0x38;
        local_68 = 1;
        local_64 = 1;
        (*DAT_140022500)(SpbDriverGlobals,*(undefined8 *)pPVar3,&local_80);
        memset(&local_80,0,0x38);
        local_50 = (undefined *)DAT_140022100;
        local_80 = 0x38;
        local_68 = 1;
        local_64 = 1;
        (*DAT_1400224f8)(SpbDriverGlobals,*(undefined8 *)pPVar3,&local_80);
        memset(&local_80,0,0x38);
        local_60 = *(undefined8 *)pPVar3;
        local_80 = 0x38;
        local_68 = 1;
        local_64 = 1;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals);
        if (iVar2 < 0) {
LAB_140001855:
          if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140001b0c;
          puVar4 = &EvtDeviceWdfSpinLockCreate_Error;
        }
        else {
          memset(&local_188,0,0x68);
          local_170 = OnInterruptIsr;
          local_188 = 0x68;
          local_168 = OnInterruptDpc;
          local_180 = local_f8;
          local_178 = (code *)CONCAT44(local_178._4_4_,2);
          local_12c = 1;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x468))
                            (WdfDriverGlobals,*(undefined8 *)pPVar3,&local_188,0);
          if (iVar2 < 0) {
            if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140001b0c;
            puVar4 = &EvtDeviceWdfInterruptCreate_Error;
          }
          else {
            memset(&local_80,0,0x28);
            local_70 = 0;
            local_68 = 0;
            local_80 = 0x28;
            local_78 = OnDelayTimerExpired;
            local_6c = CONCAT31(local_6c._1_3_,1);
            memset(&local_188,0,0x38);
            local_168 = *(code **)pPVar3;
            local_188 = 0x38;
            local_170 = (code *)0x100000001;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                              (WdfDriverGlobals,&local_80,&local_188,pPVar3 + 0x80);
            if (-1 < iVar2) {
              memset(&local_80,0,0x28);
              local_70 = 0;
              local_68 = 0;
              local_80 = 0x28;
              local_78 = OnCancelTimerExpired;
              local_6c = CONCAT31(local_6c._1_3_,1);
              memset(&local_188,0,0x38);
              local_168 = *(code **)pPVar3;
              local_188 = 0x38;
              local_170 = (code *)0x100000001;
              iVar2 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                                (WdfDriverGlobals,&local_80,&local_188,pPVar3 + 0x88);
              if (-1 < iVar2) {
                memset(local_b8,0,0x38);
                local_b8[0] = 0x38;
                local_a0 = 1;
                local_9c = 1;
                local_98 = *(undefined8 *)pPVar3;
                iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,local_b8);
                if (iVar2 < 0) goto LAB_140001855;
                local_80 = 0x24;
                local_68 = 2;
                local_60 = CONCAT44(local_60._4_4_,2);
                local_7c = 1;
                local_78 = (code *)CONCAT44(*(undefined4 *)(pPVar3 + 0xf4),4);
                local_70 = 1;
                local_6c = 1;
                local_64 = 2;
                iVar2 = (**(code **)(WdfFunctions_01015 + 0x170))
                                  (WdfDriverGlobals,*(undefined8 *)pPVar3);
                if ((-1 < iVar2) || ((Intel_iaLPSS2_I2CEnableBits & 1) == 0)) goto LAB_140001b0c;
                puVar4 = &EvtDeviceWdfDeviceAssignS0IdleSettings_Error;
                goto LAB_140001af7;
              }
            }
            if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140001b0c;
            puVar4 = &EvtDeviceWdfTimerCreate_Error;
          }
        }
      }
    }
  }
LAB_140001af7:
  McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar4,0,iVar2);
LAB_140001b0c:
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDeviceAdd_End,&local_48);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_bf0487c9480e392d62240d692a4b9b13_Traceguids,uVar5);
  }
  return iVar2;
}



===== OnDriverCleanup @ 140001be0 =====

/* void __cdecl OnDriverCleanup(void * __ptr64) */

void __cdecl OnDriverCleanup(void *param_1)

{
  WppCleanupKm();
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDriverCleanup_Info,0);
  }
  McGenEventUnregister((longlong *)&iaLPSS2_I2C_PROVIDER_Context);
  return;
}



===== DriverEntry @ 140001c1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_res18 [16];
  undefined8 local_78;
  code *local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58 [2];
  code *local_50;
  undefined4 local_40;
  undefined4 local_3c;
  
  _DAT_140022268 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140022248 = &WPP_ThisDir_CTLGUID_iaLPSS_I2CTraceGuid;
  DAT_140022250 = 0;
  _DAT_140022260 = 0;
  WppLoadTracingSupport();
  _DAT_140022260 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_bf0487c9480e392d62240d692a4b9b13_Traceguids,0xff);
  }
  McGenEventRegister();
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDriverEntry_Start,0);
  }
  local_78 = 0x20;
  local_68 = 0;
  local_60 = 0;
  local_70 = OnDeviceAdd;
  local_5c = 0x43324949;
  memset(local_58,0,0x38);
  local_58[0] = 0x38;
  local_50 = OnDriverCleanup;
  local_40 = 1;
  local_3c = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,local_58,&local_78,local_res18);
  if ((iVar1 < 0) && ((Intel_iaLPSS2_I2CEnableBits & 1) != 0)) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDriverCreate_Error,0,iVar1);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDriverEntry_End,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_bf0487c9480e392d62240d692a4b9b13_Traceguids,0xff);
  }
  if (iVar1 < 0) {
    McGenEventUnregister((longlong *)&iaLPSS2_I2C_PROVIDER_Context);
    WppCleanupKm();
  }
  return iVar1;
}



===== McGenControlCallbackV2 @ 140001e30 =====

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



===== McGenEventRegister @ 140001f38 =====

void McGenEventRegister(void)

{
  longlong *in_R9;
  
  if (*in_R9 == 0) {
    EtwRegister();
  }
  return;
}



===== McGenEventUnregister @ 140001f50 =====

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



===== McGenEventWrite @ 140001f78 =====

void McGenEventWrite(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = (ushort *)param_1[1];
  uVar2 = 0;
  if (puVar1 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = puVar1;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(*param_1,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0 @ 140001fc8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite(param_1,param_2,param_3,1,local_28);
  return;
}



===== McTemplateK0q @ 140002004 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

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
  McGenEventWrite(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateK0qqqq @ 140002058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
  McGenEventWrite(param_1,param_2,param_3,5,local_68);
  return;
}



===== WPP_SF_d @ 1400020e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_dDDDDD @ 140002120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
             &param_9,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400021a0 =====

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



===== DumpAllRegisters @ 1400021d0 =====

/* void __cdecl DumpAllRegisters(struct PBC_DEVICE * __ptr64) */

void __cdecl DumpAllRegisters(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar4 >> 10 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar4 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar2 == 1))))
         || ((((uVar4 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
             ((((uVar4 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
              (((uVar4 >> 0xf & 1) != 0 && (uVar2 == 4)))))))) ||
        ((((uVar4 >> 0x10 & 1) != 0 && (uVar2 == 5)) || (5 < uVar2)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar4 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar2 == 1))))
         || (((uVar4 >> 0xd & 1) != 0 && (uVar2 == 2)))) ||
        ((((uVar4 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
         (((((uVar4 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
           (((uVar4 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
    }
  }
  uVar4 = 0;
  lVar3 = 0;
  do {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)))
           ))) || (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))
          ) || (5 < uVar2)))))) {
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2,(char)uVar4,
                 (char)*(undefined4 *)(*(longlong *)(param_1 + 0x20) + lVar3));
    }
    uVar4 = uVar4 + 4;
    lVar3 = lVar3 + 4;
  } while (uVar4 < 0x49);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 1) != 0)) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar4 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar2 == 1))))
       || (((uVar4 >> 0xd & 1) != 0 && (uVar2 == 2)))) ||
      ((((uVar4 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
       (((((uVar4 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar4 >> 0x10 & 1) != 0 && (uVar2 == 5))))
        || (5 < uVar2)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  uVar4 = 0x200;
  lVar3 = 0x200;
  do {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))))) {
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2,(char)uVar4,
                 (char)*(undefined4 *)(*(longlong *)(param_1 + 0x20) + lVar3));
    }
    uVar4 = uVar4 + 4;
    lVar3 = lVar3 + 4;
  } while (uVar4 < 0x2fd);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 1) != 0)) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar4 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
      (((((uVar4 >> 0xc & 1) != 0 && (uVar2 == 1)) ||
        ((((uVar4 >> 0xd & 1) != 0 && (uVar2 == 2)) || (((uVar4 >> 0xe & 1) != 0 && (uVar2 == 3)))))
        ) || (((((uVar4 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
               (((uVar4 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  uVar4 = 0x800;
  lVar3 = 0x800;
  do {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || (((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))))) {
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2,(char)uVar4,
                 (char)*(undefined4 *)(*(longlong *)(param_1 + 0x20) + lVar3));
    }
    uVar4 = uVar4 + 4;
    lVar3 = lVar3 + 4;
  } while (uVar4 < 0x855);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 1) != 0)) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar4 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
      (((((((uVar4 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar4 >> 0xd & 1) != 0 && (uVar2 == 2))))
         || (((uVar4 >> 0xe & 1) != 0 && (uVar2 == 3)))) ||
        ((((uVar4 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar4 >> 0x10 & 1) != 0 && (uVar2 == 5))))
        )) || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x83,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  uVar4 = 0x858;
  lVar3 = 0x858;
  do {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || (((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))))) {
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2,(char)uVar4,
                 (char)*(undefined4 *)(*(longlong *)(param_1 + 0x20) + lVar3));
    }
    uVar4 = uVar4 + 4;
    lVar3 = lVar3 + 4;
  } while (uVar4 < 0x8ad);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 1) != 0)) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar4 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar2 == 1))))
       || (((uVar4 >> 0xd & 1) != 0 && (uVar2 == 2)))) ||
      ((((uVar4 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
       (((((uVar4 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar4 >> 0x10 & 1) != 0 && (uVar2 == 5))))
        || (5 < uVar2)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x85,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  uVar4 = 0xac0;
  lVar3 = 0xac0;
  do {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)))
           ))) || (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))
          ) || (5 < uVar2)))))) {
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x86,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2,(char)uVar4,
                 (char)*(undefined4 *)(*(longlong *)(param_1 + 0x20) + lVar3));
    }
    uVar4 = uVar4 + 4;
    lVar3 = lVar3 + 4;
  } while (uVar4 < 0xc19);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       ((((uVar4 >> 0xc & 1) != 0 && (uVar2 == 1)) ||
        ((((uVar4 >> 0xd & 1) != 0 && (uVar2 == 2)) || (((uVar4 >> 0xe & 1) != 0 && (uVar2 == 3)))))
        ))) || (((((uVar4 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
                 (((uVar4 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  return;
}



===== OnCancel @ 140002920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnCancel(struct WDFREQUEST__ * __ptr64) */

void __cdecl OnCancel(WDFREQUEST__ *param_1)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  PBC_REQUEST *pPVar7;
  undefined *puVar8;
  uint uVar9;
  
  uVar4 = (*DAT_140022520)(SpbDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar5 == 0) {
    uVar9 = 0xf0;
  }
  else {
    uVar4 = (*DAT_140022520)(SpbDriverGlobals,param_1);
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar9 = *(uint *)(lVar5 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
       || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  uVar4 = (*DAT_140022520)(SpbDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  uVar4 = (*DAT_140022518)(SpbDriverGlobals,param_1);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8);
  pPVar7 = (PBC_REQUEST *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1,DAT_140022100);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))))
      || (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  if (lVar6 == *(longlong *)(lVar5 + 0x58)) {
    if (pPVar7 == *(PBC_REQUEST **)(lVar6 + 0x18)) {
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        uVar2 = (*DAT_140022518)(SpbDriverGlobals,param_1);
        uVar4 = (*DAT_140022520)(SpbDriverGlobals,param_1);
        McTemplateK0ppp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        &EvtCancelWithOutstandingRequest_Info,lVar5 + 8,uVar4,uVar2,(char)param_1);
      }
      cVar3 = (**(code **)(WdfFunctions_01015 + 0xa00))
                        (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x80),0);
      if (((((cVar3 != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
          ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
      }
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x60));
      *(uint *)(lVar5 + 0x70) = *(uint *)(lVar5 + 0x70) | 0x80000000;
      cVar3 = (**(code **)(WdfFunctions_01015 + 0x470))
                        (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x60));
      if (((((cVar3 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
      }
      (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x60));
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
             ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x78));
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
            (((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)))) ||
           ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
      }
      goto LAB_140003089;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
      puVar8 = &EvtCancelWithoutRequest_Warn;
      goto LAB_140002c42;
    }
  }
  else if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
    puVar8 = &EvtCancelWithoutTarget_Warn;
LAB_140002c42:
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar8,lVar5 + 8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))
       ) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
      ((((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  PbcRequestComplete(pPVar7,"OnCancel");
LAB_140003089:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
       || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  return;
}



===== OnCancelTimerExpired @ 140003120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnCancelTimerExpired(struct WDFTIMER__ * __ptr64) */

void __cdecl OnCancelTimerExpired(WDFTIMER__ *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  char cVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar6 == 0) {
    uVar7 = 0xf0;
  }
  else {
    uVar5 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar7 = *(uint *)(lVar6 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
       ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar7 == 1)))) ||
      ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
       (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ))) || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  if (*(longlong *)(lVar6 + 0x58) == 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtCancelTimerWithoutTarget_Warn,
                   lVar6 + 8);
    }
  }
  else {
    puVar2 = *(undefined8 **)(*(longlong *)(lVar6 + 0x58) + 0x18);
    if (puVar2 == (undefined8 *)0x0) {
      if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
        McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtCancelTimerWithoutRequest_Warn,
                     lVar6 + 8);
      }
    }
    else {
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        uVar3 = (*DAT_140022518)(SpbDriverGlobals,*puVar2);
        uVar5 = (*DAT_140022520)(SpbDriverGlobals,*puVar2);
        McTemplateK0ppp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        &EvtCancelTimerWithOutstandingRequest_Info,lVar6 + 8,uVar5,uVar3,
                        (char)*puVar2);
      }
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x60));
      *(uint *)(lVar6 + 0x70) = *(uint *)(lVar6 + 0x70) | 0x40000000;
      cVar4 = (**(code **)(WdfFunctions_01015 + 0x470))
                        (WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x60));
      if (((((cVar4 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
      }
      (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x60));
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x78));
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x100) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar1 & 0x1000) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))))
        || (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
             (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
            ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar7 == 1))))
           || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
          (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ))) || (5 < uVar7)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
  }
  return;
}



===== OnControllerLock @ 140003720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnControllerLock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerLock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar4 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar4 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0ppp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtSpbDDI_EvtSpbControllerLock_Info
                    ,lVar2 + 8,param_1,(char)param_2,(char)param_3);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  *(longlong *)(lVar2 + 0x58) = lVar3;
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0h((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerLock_Info,lVar2 + 8,
                  *(undefined2 *)(lVar3 + 0xc));
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
       ((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))
          ) || (5 < uVar4)))))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))))
        ) || ((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))))) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  (*DAT_140022538)(SpbDriverGlobals,param_3,0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
      (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))
        ) || (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  return;
}



===== OnControllerUnlock @ 140003bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnControllerUnlock(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64) */

void __cdecl OnControllerUnlock(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3)

{
  uint uVar1;
  longlong lVar2;
  PBC_DEVICE *pPVar3;
  uint uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar4 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar4 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  pPVar3 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0ppp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                    &EvtSpbDDI_EvtSpbControllerUnlock_Info,pPVar3 + 8,param_1,(char)param_2,
                    (char)param_3);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar3 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  ControllerFinishTransfer(pPVar3);
  *(undefined8 *)(pPVar3 + 0x58) = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
      ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
       ((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))
          ) || (5 < uVar4)))))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar3 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))))
        ) || ((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))))) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0h((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerUnlock_Info,pPVar3 + 8,
                  *(undefined2 *)(lVar2 + 0xc));
  }
  (*DAT_140022538)(SpbDriverGlobals,param_3,0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
      (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))
        ) || (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  return;
}



===== OnD0Entry @ 140004040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl OnD0Entry(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Entry(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  uint uVar1;
  long lVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  uint uVar5;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar5 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))
       ) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar5);
  }
  pPVar4 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtD0Entry_Start,pPVar4 + 8,param_2);
  }
  *(undefined8 *)(pPVar4 + 0x58) = 0;
  lVar2 = ControllerInitialize(pPVar4);
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtD0Entry_End,pPVar4 + 8,lVar2);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar5);
  }
  return lVar2;
}



===== OnD0Exit @ 140004250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl OnD0Exit(struct WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl OnD0Exit(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  uint uVar1;
  longlong lVar2;
  PBC_DEVICE *pPVar3;
  uint uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar4 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar4 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  pPVar3 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtD0Exit_Start,pPVar3 + 8,param_2);
  }
  ControllerUninitialize(pPVar3);
  *(undefined8 *)(pPVar3 + 0x58) = 0;
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtD0Exit_End,pPVar3 + 8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  return 0;
}



===== OnDelayTimerExpired @ 140004460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnDelayTimerExpired(struct WDFTIMER__ * __ptr64) */

void __cdecl OnDelayTimerExpired(WDFTIMER__ *param_1)

{
  uint uVar1;
  PBC_REQUEST *pPVar2;
  long lVar3;
  undefined8 uVar4;
  longlong lVar5;
  PBC_DEVICE *pPVar6;
  undefined *puVar7;
  uint uVar8;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar5 == 0) {
    uVar8 = 0xf0;
  }
  else {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar8 = *(uint *)(lVar5 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5))))
       || (5 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  pPVar6 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar4,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)))))
        ))) || (((((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
  }
  lVar5 = *(longlong *)(pPVar6 + 0x58);
  if (lVar5 == 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
      puVar7 = &EvtTimerWithoutTarget_Warn;
LAB_140004718:
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar7,pPVar6 + 8);
    }
  }
  else {
    pPVar2 = *(PBC_REQUEST **)(lVar5 + 0x18);
    if (pPVar2 == (PBC_REQUEST *)0x0) {
      if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
        puVar7 = &EvtTimerWithoutRequest_Warn;
        goto LAB_140004718;
      }
    }
    else {
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtTransferDelayExpired_Info,
                        pPVar6 + 8,*(undefined2 *)(lVar5 + 0xc),(char)*(undefined4 *)(pPVar2 + 0x10)
                        ,(char)*(undefined4 *)(pPVar2 + 0xc));
      }
      lVar3 = ControllerConfigureForTransfer(pPVar6,pPVar2);
      if (lVar3 < 0) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
          McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtRequestFailToConfigure_Error
                        ,pPVar6 + 8,lVar3);
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
              (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
             ((((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)))))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
        }
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
              ((((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2)))))) ||
             ((((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5)))))))) || (5 < uVar8)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
        }
        PbcRequestComplete(pPVar2,"OnDelayTimerExpired");
        goto LAB_1400049f9;
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5))))
        || (5 < uVar8)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar6 + 0x78));
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
  if ((((uVar1 & 0x100) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2))))))
      || (((((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)) || (((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)))
           ) || ((((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5)) || (5 < uVar8)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
  }
LAB_1400049f9:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar8 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar8 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar8 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar8 == 5))))
       || (5 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
  }
  return;
}



===== OnInterruptDpc @ 140004a90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnInterruptDpc(struct WDFINTERRUPT__ * __ptr64,void * __ptr64) */

void __cdecl OnInterruptDpc(WDFINTERRUPT__ *param_1,void *param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  PBC_REQUEST *pPVar4;
  ulong uVar5;
  longlong lVar6;
  PBC_DEVICE *pPVar7;
  undefined *puVar8;
  uint uVar9;
  bool bVar10;
  
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar6 == 0) {
    uVar9 = 0xf0;
  }
  else {
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar9 = *(uint *)(lVar6 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar9 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar9 == 1)))) ||
      (((((uVar1 & 0x2000) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  pPVar7 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 & 0x800) != 0 && (uVar9 == 0)) ||
      ((((((uVar1 & 0x1000) != 0 && (uVar9 == 1)) || (((uVar1 & 0x2000) != 0 && (uVar9 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar7 + 0x78));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 & 0x800) != 0 && (uVar9 == 0)) || (((uVar1 & 0x1000) != 0 && (uVar9 == 1)))) ||
        (((uVar1 & 0x2000) != 0 && (uVar9 == 2)))) ||
       ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        )))) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  if (*(longlong *)(pPVar7 + 0x58) == 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
      puVar8 = &EvtDpcWithoutTarget_Warn;
LAB_140004ceb:
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar8,pPVar7 + 8);
    }
  }
  else {
    pPVar4 = *(PBC_REQUEST **)(*(longlong *)(pPVar7 + 0x58) + 0x18);
    if (pPVar4 == (PBC_REQUEST *)0x0) {
      if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
        puVar8 = &EvtDpcWithoutRequest_Warn;
        goto LAB_140004ceb;
      }
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,param_1);
      uVar5 = *(ulong *)(pPVar7 + 0x6c);
      uVar2 = *(ulong *)(pPVar7 + 0x70);
      *(undefined4 *)(pPVar7 + 0x6c) = 0;
      *(undefined4 *)(pPVar7 + 0x70) = 0;
      if (pPVar7[0x74] == (PBC_DEVICE)0x0) {
        ControllerDisableInterrupts(pPVar7);
      }
      (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,param_1);
      if ((uVar5 != 0) || (uVar2 != 0)) {
        if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
          McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtInterruptDPCStatus_Info,
                         pPVar7 + 8,uVar5,(char)uVar2);
        }
        iVar3 = *(int *)(pPVar4 + 0x10);
        ControllerAcknowledgeInterrupts(pPVar7,uVar5);
        ControllerProcessInterrupts(pPVar7,pPVar4,uVar5,uVar2);
        (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,param_1);
        uVar5 = *(ulong *)(pPVar7 + 0x68);
        do {
          LOCK();
          uVar2 = *(ulong *)(pPVar7 + 0x68);
          bVar10 = uVar5 == uVar2;
          if (bVar10) {
            *(ulong *)(pPVar7 + 0x68) = uVar5;
          }
          else {
            uVar5 = uVar2;
          }
          UNLOCK();
        } while (!bVar10);
        if ((uVar5 != 0) && (iVar3 == *(int *)(pPVar4 + 0x10))) {
          if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
            McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtInterruptDPCReenable_Info,
                          pPVar7 + 8,uVar5);
          }
          ControllerEnableInterrupts(pPVar7,uVar5);
        }
        (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,param_1);
        if (pPVar4[0x24] != (PBC_REQUEST)0x0) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                  (((uVar1 & 0x1000) != 0 && (uVar9 == 1)))) ||
                 (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
               ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                     &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
          }
          (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar7 + 0x78))
          ;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
               (((uVar1 & 0x1000) != 0 && (uVar9 == 1)))) ||
              (((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
               (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
                     &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
          }
          PbcRequestComplete(pPVar4,"OnInterruptDpc");
          goto LAB_1400050a3;
        }
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 & 0x800) != 0 && (uVar9 == 0)) ||
        ((((uVar1 & 0x1000) != 0 && (uVar9 == 1)) || (((uVar1 & 0x2000) != 0 && (uVar9 == 2)))))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
       || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar7 + 0x78));
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
  if ((((uVar1 & 0x100) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 & 0x800) != 0 && (uVar9 == 0)) ||
       ((((uVar1 & 0x1000) != 0 && (uVar9 == 1)) || (((uVar1 & 0x2000) != 0 && (uVar9 == 2)))))) ||
      (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) || (((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4))))
       || ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
LAB_1400050a3:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
       || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  return;
}



===== OnInterruptIsr @ 140005140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl OnInterruptIsr(struct WDFINTERRUPT__ * __ptr64,unsigned long) */

uchar __cdecl OnInterruptIsr(WDFINTERRUPT__ *param_1,ulong param_2)

{
  ulong uVar1;
  uint uVar2;
  char cVar3;
  ulong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  PBC_DEVICE *pPVar7;
  uint uVar8;
  uchar uVar9;
  bool bVar10;
  
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x4b8))(WdfDriverGlobals,param_1);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar6 == 0) {
    uVar8 = 0xf0;
  }
  else {
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x4b8))(WdfDriverGlobals,param_1);
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar8 = *(uint *)(lVar6 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1))))
        || ((((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3)))))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5)))))
       ) || (5 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
  }
  uVar9 = '\0';
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x4b8))(WdfDriverGlobals,param_1);
  pPVar7 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar5,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  uVar4 = *(ulong *)(pPVar7 + 0x68);
  do {
    LOCK();
    uVar1 = *(ulong *)(pPVar7 + 0x68);
    bVar10 = uVar4 == uVar1;
    if (bVar10) {
      *(ulong *)(pPVar7 + 0x68) = uVar4;
    }
    else {
      uVar4 = uVar1;
    }
    UNLOCK();
  } while (!bVar10);
  uVar4 = ControllerGetInterruptStatus(pPVar7,uVar4);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtInterruptISRStatus_Info,pPVar7 + 8
                  ,uVar4);
  }
  if (uVar4 != 0) {
    *(uint *)(pPVar7 + 0x6c) = *(uint *)(pPVar7 + 0x6c) | uVar4;
    uVar9 = '\x01';
    ControllerDisableInterrupts(pPVar7);
    cVar3 = (**(code **)(WdfFunctions_01015 + 0x470))(WdfDriverGlobals,param_1);
    if (cVar3 == '\0') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return '\x01';
      }
      uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar2 & 8) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))
           ) || ((((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2)) ||
                 (((((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
                   (((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)))) ||
                  ((((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5)) || (5 < uVar8)))))))))) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                  &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8,(char)uVar4);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1))))
         || (((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2)))) ||
        (((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3)))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5)))))
       ) || (5 < uVar8)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar8);
  }
  return uVar9;
}



===== OnMonitorPowerSettingCallback @ 140005450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl OnMonitorPowerSettingCallback(struct _GUID const * __ptr64,void * __ptr64,unsigned
   long,void * __ptr64) */

long __cdecl OnMonitorPowerSettingCallback(_GUID *param_1,void *param_2,ulong param_3,void *param_4)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_88 [32];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  iVar1 = 0;
  uVar3 = 0xff;
  if (param_4 == (void *)0x0) {
    iVar1 = -0x3ffffff3;
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtPowerCallbackInvalidContext_Error
                   ,0);
    }
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_4,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar3 = 0xf0;
    if (lVar2 != 0) {
      uVar3 = *(uint *)(lVar2 + 0x40);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar4 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar3 == 1))))
         || (((uVar4 >> 0xd & 1) != 0 && (uVar3 == 2)))) ||
        ((((uVar4 >> 0xe & 1) != 0 && (uVar3 == 3)) ||
         (((((uVar4 >> 0xf & 1) != 0 && (uVar3 == 4)) ||
           (((uVar4 >> 0x10 & 1) != 0 && (uVar3 == 5)))) || (5 < uVar3)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
    }
    if ((*(longlong *)param_1 == 0x4526451002731015) &&
       (*(longlong *)(param_1 + 8) == -0x15e542815e1a1967)) {
      local_58 = 0x24;
      local_48 = 2;
      local_44 = 2;
      local_40 = 2;
      local_38 = 2;
      local_54 = 1;
      local_50 = 4;
      local_3c = 2;
      if (*(int *)param_2 != 0) {
        local_4c = *(undefined4 *)(lVar2 + 0xf4);
      }
      else {
        local_4c = *(undefined4 *)(lVar2 + 0xf8);
      }
      uVar4 = (uint)(*(int *)param_2 != 0);
      *(uint *)(lVar2 + 0x98) = uVar4;
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtPowerCallback_Info,lVar2 + 8,
                       uVar4,(char)local_4c);
      }
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x170))(WdfDriverGlobals,param_4,&local_58);
      if ((iVar1 < 0) && ((Intel_iaLPSS2_I2CEnableBits & 1) != 0)) {
        McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                      &EvtPowerWdfDeviceAssignS0IdleSettings_Error,lVar2 + 8,iVar1);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar4 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar3 == 1))))
       || ((((uVar4 >> 0xd & 1) != 0 && (uVar3 == 2)) || (((uVar4 >> 0xe & 1) != 0 && (uVar3 == 3)))
           ))) ||
      (((((uVar4 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar4 >> 0x10 & 1) != 0 && (uVar3 == 5))))
       || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  return iVar1;
}



===== OnOther @ 140005710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnOther(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
OnOther(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4,
       __uint64 param_5,ulong param_6)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar3 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar3 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))))
       ) || (5 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pppxxq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtSpbDDI_EvtSpbOther_Info,
                       lVar2 + 8,param_1,(char)param_2,(char)param_3,(char)param_4,(char)param_5,
                       (char)param_6);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
    McTemplateK0ppqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     &EvtRequestCompleteSynchronously_Error,lVar2 + 8,param_1,(char)param_3,8,0xbb);
  }
  (*DAT_140022538)(SpbDriverGlobals,param_3,0xc00000bb);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
       || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  return;
}



===== OnOtherInCallerContext @ 140005970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnOtherInCallerContext(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl OnOtherInCallerContext(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined *puVar3;
  uint uVar4;
  undefined1 auStack_78 [32];
  undefined2 local_48 [2];
  int local_44;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar4 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar4 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                   &EvtSpbDDI_EvtSpbOtherInCallerContext_Info,lVar2 + 8,param_1,(char)param_2);
  }
  memset(local_48,0,0x28);
  local_48[0] = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,local_48);
  if (local_44 - 0xeU < 2) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140005b39;
    puVar3 = &EvtRequestUnsupportedIoControlCode_Error;
  }
  else {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140005b39;
    puVar3 = &EvtRequestUnsupportedType_Error;
  }
  McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar3,lVar2 + 8,0xc00000bb);
LAB_140005b39:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  return;
}



===== OnPrepareHardware @ 140005c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl OnPrepareHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnPrepareHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  PBC_DEVICE *pPVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  PBC_DEVICE *pPVar5;
  char *pcVar6;
  longlong lVar7;
  undefined *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar7 == 0) {
    uVar9 = 0xf0;
  }
  else {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar9 = *(uint *)(lVar7 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || (((uVar3 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
      ((((uVar3 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
       (((((uVar3 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  pPVar5 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  pPVar1 = pPVar5 + 8;
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtPrepareHardware_Start,pPVar1);
  }
  lVar4 = 0;
  iVar12 = 0;
  iVar10 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_3);
  uVar11 = 0;
  if (uVar3 != 0) {
    do {
      pcVar6 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar11);
      cVar2 = *pcVar6;
      if (cVar2 == '\x03') {
        if (iVar12 == 0) {
          lVar7 = MmMapIoSpaceEx(*(undefined8 *)(pcVar6 + 4),*(undefined4 *)(pcVar6 + 0xc),0x204);
          if (lVar7 == 0) {
            lVar4 = -0x3fffff66;
            if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
              McTemplateK0qxqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                               &EvtPrepareHardware_MmioMap_Error,pPVar1,0,
                               (char)*(undefined8 *)(pcVar6 + 4),(char)*(undefined4 *)(pcVar6 + 0xc)
                               ,0x9a);
            }
            goto LAB_140005fd5;
          }
          *(longlong *)(pPVar5 + 0x20) = lVar7;
          *(undefined8 *)(pPVar5 + 0x18) = *(undefined8 *)(pcVar6 + 4);
          *(undefined4 *)(pPVar5 + 0x28) = *(undefined4 *)(pcVar6 + 0xc);
          *(longlong *)(pPVar5 + 0x38) = lVar7 + 0x200;
          *(longlong *)(pPVar5 + 0x110) = lVar7 + 0x800;
          *(longlong *)(pPVar5 + 0x30) = lVar7;
          if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
            McTemplateK0qxqp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                             &EvtPrepareHardware_MmioMapped_Info,pPVar1,0,
                             (char)*(undefined8 *)(pcVar6 + 4),(char)*(undefined4 *)(pcVar6 + 0xc),
                             (char)lVar7);
          }
        }
        else if ((Intel_iaLPSS2_I2CEnableBits & 8) != 0) {
          McTemplateK0qxq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                          &EvtPrepareHardware_MmioRes_Warn,pPVar1,iVar12,
                          (char)*(undefined8 *)(pcVar6 + 4),(char)*(undefined4 *)(pcVar6 + 0xc));
        }
        cVar2 = *pcVar6;
        iVar12 = iVar12 + 1;
      }
      if (cVar2 == '\x02') {
        if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
          McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        &EvtPrepareHardware_IntVector_Info,pPVar1,*(undefined4 *)(pcVar6 + 8));
        }
        iVar10 = iVar10 + 1;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar3);
    if ((iVar12 - 1U < 2) && (iVar10 == 1)) {
      pPVar5[0x118] = (PBC_DEVICE)0x0;
      pPVar5[0x108] = (PBC_DEVICE)0x0;
      if (*(int *)(pPVar5 + 0xfc) == 1) {
        lVar4 = DmaInitSw(pPVar5);
        if (-1 < lVar4) {
          if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
            McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                         &EvtPrepareHardware_DmaSwInit_Info,pPVar1);
          }
          pPVar5[0x108] = (PBC_DEVICE)0x1;
          goto LAB_140005fd5;
        }
        lVar4 = -0x3ffffb7d;
        if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140005fd5;
        puVar8 = &EvtPrepareHardware_DmaSwInit_Error;
      }
      else {
        if ((Intel_iaLPSS2_I2CEnableBits & 2) == 0) goto LAB_140005fd5;
        puVar8 = &EvtPrepareHardware_DmaSwDisabled_Info;
      }
      McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar8,pPVar1);
      goto LAB_140005fd5;
    }
  }
  lVar4 = -0x3fffff66;
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0qqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                    &EvtPrepareHardware_ResourceCnt_Error,pPVar1,iVar12,(char)iVar10,0x9a);
  }
LAB_140005fd5:
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtPrepareHardware_End,pPVar1);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || ((((uVar3 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar3 >> 0xe & 1) != 0 && (uVar9 == 3)))
           ))) ||
      (((((uVar3 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar9 == 5))))
       || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar9);
  }
  return lVar4;
}



===== OnQueryStop @ 140006090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl OnQueryStop(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnQueryStop(WDFDEVICE__ *param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar3 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar3 = *(uint *)(lVar2 + 0x40);
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 >> 10 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)) || (5 < uVar3)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || (((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))) || (5 < uVar3)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
    }
  }
  return -0x3fffffff;
}



===== OnRead @ 140006210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnRead(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct SPBREQUEST__
   * __ptr64,unsigned __int64) */

void __cdecl
OnRead(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar3 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar3 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))))
       ) || (5 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pppx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtSpbDDI_EvtSpbIoRead_Info,
                     lVar2 + 8,param_1,(char)param_2,(char)param_3,(char)param_4);
  }
  PbcRequestConfigureForNonSequence(param_1,param_2,param_3,param_4);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
       || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  return;
}



===== OnReleaseHardware @ 140006420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl OnReleaseHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl OnReleaseHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  uint uVar1;
  longlong lVar2;
  PBC_DEVICE *pPVar3;
  uint uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar4 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar4 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  pPVar3 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtReleaseHardware_Start,pPVar3 + 8);
  }
  lVar2 = *(longlong *)(pPVar3 + 0x20);
  if (lVar2 != 0) {
    if (pPVar3[0x108] != (PBC_DEVICE)0x0) {
      DmaReleaseSw(pPVar3);
      lVar2 = *(longlong *)(pPVar3 + 0x20);
      pPVar3[0x108] = (PBC_DEVICE)0x0;
    }
    MmUnmapIoSpace(lVar2,*(undefined4 *)(pPVar3 + 0x28));
    *(undefined8 *)(pPVar3 + 0x20) = 0;
    *(undefined4 *)(pPVar3 + 0x28) = 0;
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 4) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtReleaseHardware_End,pPVar3 + 8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  return 0;
}



===== OnSelfManagedIoCleanup @ 140006640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnSelfManagedIoCleanup(struct WDFDEVICE__ * __ptr64) */

void __cdecl OnSelfManagedIoCleanup(WDFDEVICE__ *param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar3 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar3 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))))
       ) || (5 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (*(longlong *)(lVar2 + 0x90) != 0) {
    PoUnregisterPowerSettingCallback();
    *(undefined8 *)(lVar2 + 0x90) = 0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
       || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  return;
}



===== OnSelfManagedIoInit @ 140006800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl OnSelfManagedIoInit(struct WDFDEVICE__ * __ptr64) */

long __cdecl OnSelfManagedIoInit(WDFDEVICE__ *param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar3 == 0) {
    uVar6 = 0xf0;
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar6 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5))))
        || (5 < uVar6)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar6);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*puVar4);
  iVar2 = PoRegisterPowerSettingCallback
                    (uVar5,&GUID_MONITOR_POWER_ON,OnMonitorPowerSettingCallback,*puVar4,
                     puVar4 + 0x12);
  if ((iVar2 < 0) && ((Intel_iaLPSS2_I2CEnableBits & 1) != 0)) {
    McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                  &EvtPowerPoRegisterPowerSettingCallback_Error,puVar4 + 1,iVar2);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5))))
       || (5 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar6);
  }
  return iVar2;
}



===== OnSequence @ 140006a20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned long) */

void __cdecl
OnSequence(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,ulong param_4)

{
  uint uVar1;
  long lVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  PBC_TARGET *pPVar5;
  PBC_REQUEST *pPVar6;
  uint uVar7;
  undefined1 auStackY_a8 [32];
  undefined2 local_68 [2];
  undefined4 local_64;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar3 == 0) {
    uVar7 = 0xf0;
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar7 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  pPVar4 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  pPVar5 = (PBC_TARGET *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8);
  pPVar6 = (PBC_REQUEST *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_3,DAT_140022100);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pppq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtSpbDDI_EvtSpbIoSequence_Info,
                     pPVar4 + 8,param_1,(char)param_2,(char)param_3,(char)param_4);
  }
  memset(local_68,0,0x20);
  local_68[0] = 0x20;
  (*DAT_140022528)(SpbDriverGlobals,param_3,local_68);
  *(SPBREQUEST__ **)pPVar6 = param_3;
  *(undefined4 *)(pPVar6 + 8) = local_64;
  *(undefined8 *)(pPVar6 + 0x18) = 0;
  *(ulong *)(pPVar6 + 0xc) = param_4;
  *(undefined4 *)(pPVar6 + 0x10) = 0;
  pPVar6[0x24] = (PBC_REQUEST)0x0;
  lVar2 = PbcRequestValidate(pPVar4,pPVar6,pPVar5);
  if ((-1 < lVar2) && (lVar2 = PbcRequestConfigureForIndex(pPVar6,0), -1 < lVar2)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0 &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
         ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
    lVar2 = (**(code **)(WdfFunctions_01015 + 0xc48))
                      (WdfDriverGlobals,*(undefined8 *)pPVar6,OnCancel);
    if (-1 < lVar2) {
      *(PBC_TARGET **)(pPVar4 + 0x58) = pPVar5;
      *(PBC_REQUEST **)(pPVar5 + 0x18) = pPVar6;
      PbcRequestDoTransfer(pPVar4,pPVar6);
      if (pPVar6[0x24] == (PBC_REQUEST)0x0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
               ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
             ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
        }
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
        }
      }
      else {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
               (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
             ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
        }
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
            (((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
        }
        PbcRequestComplete(pPVar6,"OnSequence");
      }
      goto LAB_140006f21;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtRequestFailMarkCancelable_Error,
                    pPVar4 + 8,lVar2);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
         ((((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
    McTemplateK0ppqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     &EvtRequestCompleteSynchronously_Error,pPVar4 + 8,param_1,(char)param_3,3,
                     (char)lVar2);
  }
  (*DAT_140022538)(SpbDriverGlobals,param_3,lVar2);
LAB_140006f21:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
      (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
       || ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  return;
}



===== OnTargetConnect @ 140007240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl OnTargetConnect(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64) */

long __cdecl OnTargetConnect(WDFDEVICE__ *param_1,SPBTARGET__ *param_2)

{
  PBC_DEVICE *pPVar1;
  uint uVar2;
  long lVar3;
  longlong lVar4;
  PBC_DEVICE *pPVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar4 == 0) {
    uVar7 = 0xf0;
  }
  else {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar7 = *(uint *)(lVar4 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1))))
        || ((((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  pPVar5 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8);
  pPVar1 = pPVar5 + 8;
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtSpbDDI_EvtSpbTargetConnect_Info,
                   pPVar1,param_1,(char)param_2);
  }
  local_30 = 0;
  local_28 = (void *)0x0;
  local_38 = 0x18;
  (*DAT_140022508)(SpbDriverGlobals,param_2,&local_38);
  lVar3 = PbcTargetGetSettings(pPVar5,local_28,(PBC_TARGET_SETTINGS *)(puVar6 + 1));
  if (lVar3 < 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerConnect_Error,pPVar1,
                    lVar3);
    }
  }
  else {
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      McTemplateK0hqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerConnect_Info,pPVar1,
                      *(undefined2 *)((longlong)puVar6 + 0xc),(char)*(undefined4 *)(puVar6 + 1),
                      (char)*(undefined4 *)(puVar6 + 2));
    }
    puVar6[3] = 0;
    *puVar6 = param_2;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
       (((((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2))))
        || (((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
      (((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  return lVar3;
}



===== OnTargetDisconnect @ 140007510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnTargetDisconnect(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64) */

void __cdecl OnTargetDisconnect(WDFDEVICE__ *param_1,SPBTARGET__ *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar4 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar4 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
        || (5 < uVar4)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pp((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                   &EvtSpbDDI_EvtSpbTargetDisconnect_Info,lVar2 + 8,param_1,(char)param_2);
  }
  if ((lVar3 != 0) && ((Intel_iaLPSS2_I2CEnableBits & 2) != 0)) {
    McTemplateK0h((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerDisconnect_Info,
                  lVar2 + 8,*(undefined2 *)(lVar3 + 0xc));
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  return;
}



===== OnWrite @ 140007740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl OnWrite(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ * __ptr64,struct
   SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
OnWrite(WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar2 == 0) {
    uVar3 = 0xf0;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar3 = *(uint *)(lVar2 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))))
       ) || (5 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0pppx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtSpbDDI_EvtSpbIoWrite_Info,
                     lVar2 + 8,param_1,(char)param_2,(char)param_3,(char)param_4);
  }
  PbcRequestConfigureForNonSequence(param_1,param_2,param_3,param_4);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
       || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  return;
}



===== PbcFailDevice @ 140007944 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PbcFailDevice(struct PBC_DEVICE * __ptr64) */

void __cdecl PbcFailDevice(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined8 local_34;
  undefined8 uStack_2c;
  undefined4 local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))))
       ) || (5 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
    McTemplateK0((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtDeviceFail_Error,param_1 + 8);
  }
  DumpAllRegisters(param_1);
  local_38 = 0x1c;
  local_34 = 0x200000002;
  uStack_2c = 0x200000002;
  local_24 = 2;
  local_20 = 2;
  (**(code **)(WdfFunctions_01015 + 0xe0))(WdfDriverGlobals,*(undefined8 *)param_1,&local_38);
  uStack_2c = CONCAT44(uStack_2c._4_4_,1);
  (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,*(undefined8 *)param_1,&local_38);
  (**(code **)(WdfFunctions_01015 + 0x2b8))(WdfDriverGlobals,*(undefined8 *)param_1,2);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5))))
       || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  return;
}



===== PbcRequestComplete @ 140007b48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl PbcRequestComplete(struct PBC_REQUEST * __ptr64,char * __ptr64 const) */

void __cdecl PbcRequestComplete(PBC_REQUEST *param_1,char *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined *puVar5;
  uint uVar6;
  
  uVar3 = (*DAT_140022520)(SpbDriverGlobals,*(undefined8 *)param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar4 == 0) {
    uVar6 = 0xf0;
  }
  else {
    uVar3 = (*DAT_140022520)(SpbDriverGlobals,*(undefined8 *)param_1);
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar6 = *(uint *)(lVar4 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))))
       ) || (5 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar6);
  }
  uVar3 = (*DAT_140022520)(SpbDriverGlobals,*(undefined8 *)param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (*(int *)(param_1 + 0x20) < 0) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) == 0) goto LAB_140007d2e;
    uVar2 = (*DAT_140022520)(SpbDriverGlobals,*(undefined8 *)param_1);
    puVar5 = &EvtRequestComplete_Error;
  }
  else {
    if ((Intel_iaLPSS2_I2CEnableBits & 2) == 0) goto LAB_140007d2e;
    uVar2 = (*DAT_140022520)(SpbDriverGlobals,*(undefined8 *)param_1);
    puVar5 = &EvtRequestComplete_Info;
  }
  McTemplateK0sppxq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar5,lVar4 + 8,param_2,uVar2,
                    (char)*(undefined8 *)param_1,(char)*(undefined8 *)(param_1 + 0x18),
                    (char)*(undefined4 *)(param_1 + 0x20));
LAB_140007d2e:
  (**(code **)(WdfFunctions_01015 + 0x898))
            (WdfDriverGlobals,*(undefined8 *)param_1,*(undefined8 *)(param_1 + 0x18));
  (*DAT_140022538)(SpbDriverGlobals,*(undefined8 *)param_1,*(undefined4 *)(param_1 + 0x20));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5))))
       || (5 < uVar6)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar6);
  }
  return;
}



===== PbcRequestConfigureForIndex @ 140007e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestConfigureForIndex(struct PBC_REQUEST * __ptr64,unsigned long) */

long __cdecl PbcRequestConfigureForIndex(PBC_REQUEST *param_1,ulong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  long lVar6;
  undefined1 auStackY_a8 [32];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar2 = (*DAT_140022520)(SpbDriverGlobals,*(undefined8 *)param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar3 == 0) {
    uVar5 = 0xf0;
  }
  else {
    uVar2 = (*DAT_140022520)(SpbDriverGlobals,*(undefined8 *)param_1);
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar5 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))
       ) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar5);
  }
  lVar6 = 0;
  uVar2 = (*DAT_140022520)(SpbDriverGlobals,*(undefined8 *)param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  uVar2 = (*DAT_140022518)(SpbDriverGlobals,*(undefined8 *)param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8);
  local_48 = 0;
  local_40 = 0;
  local_50 = 0x18;
  (*DAT_140022530)(SpbDriverGlobals,*(undefined8 *)param_1,param_2,&local_50);
  if (local_50._4_4_ == 1) {
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x58) = local_58;
    *(undefined8 *)(param_1 + 0x30) = local_48;
  }
  else {
    if (local_50._4_4_ != 2) {
      if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
        McTemplateK0hqqqqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtRequestConfigured_Error,
                           lVar3 + 8,*(undefined2 *)(lVar4 + 0xc),(char)param_2,
                           (char)*(undefined4 *)(param_1 + 0xc),(char)*(undefined4 *)(param_1 + 100)
                           ,(char)*(undefined4 *)(param_1 + 8),(char)local_48);
      }
      lVar6 = -0x3ffffff3;
      goto LAB_14000811b;
    }
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x50) = local_58;
    *(undefined8 *)(param_1 + 0x28) = local_48;
  }
  *(undefined8 *)(param_1 + 0x38) = local_48;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(int *)(param_1 + 100) = local_50._4_4_;
  *(undefined4 *)(param_1 + 0x68) = (undefined4)local_40;
  if (*(int *)(param_1 + 8) == 3) {
    if (*(int *)(param_1 + 0xc) == 1) {
      *(undefined4 *)(param_1 + 0x60) = 1;
    }
    else if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x60) = 2;
    }
    else {
      *(uint *)(param_1 + 0x60) = 4 - (uint)(param_2 != *(int *)(param_1 + 0xc) - 1U);
    }
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0hqqqqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtRequestConfigured_Info,
                       lVar3 + 8,*(undefined2 *)(lVar4 + 0xc),(char)param_2,
                       (char)*(undefined4 *)(param_1 + 0xc),(char)((ulonglong)local_50 >> 0x20),
                       (char)*(int *)(param_1 + 8),(char)local_48);
  }
LAB_14000811b:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar5);
  }
  return lVar6;
}



===== PbcRequestConfigureForNonSequence @ 1400081c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl PbcRequestConfigureForNonSequence(struct WDFDEVICE__ * __ptr64,struct SPBTARGET__ *
   __ptr64,struct SPBREQUEST__ * __ptr64,unsigned __int64) */

void __cdecl
PbcRequestConfigureForNonSequence
          (WDFDEVICE__ *param_1,SPBTARGET__ *param_2,SPBREQUEST__ *param_3,__uint64 param_4)

{
  uint uVar1;
  long lVar2;
  longlong lVar3;
  PBC_DEVICE *pPVar4;
  PBC_TARGET *pPVar5;
  PBC_REQUEST *pPVar6;
  uint uVar7;
  undefined1 auStackY_a8 [32];
  undefined2 local_68 [2];
  undefined4 local_64;
  undefined4 local_60;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar3 == 0) {
    uVar7 = 0xf0;
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar7 = *(uint *)(lVar3 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  pPVar4 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  pPVar5 = (PBC_TARGET *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_PBC_TARGET_TYPE_INFO_1400220d8);
  pPVar6 = (PBC_REQUEST *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_3,DAT_140022100);
  memset(local_68,0,0x20);
  local_68[0] = 0x20;
  (*DAT_140022528)(SpbDriverGlobals,param_3,local_68);
  *(SPBREQUEST__ **)pPVar6 = param_3;
  *(undefined4 *)(pPVar6 + 8) = local_64;
  *(undefined4 *)(pPVar6 + 0x60) = local_60;
  *(undefined8 *)(pPVar6 + 0x18) = 0;
  pPVar6[0x24] = (PBC_REQUEST)0x0;
  *(undefined8 *)(pPVar6 + 0xc) = 1;
  lVar2 = PbcRequestValidate(pPVar4,pPVar6,pPVar5);
  if ((-1 < lVar2) &&
     (lVar2 = PbcRequestConfigureForIndex(pPVar6,*(ulong *)(pPVar6 + 0x10)), -1 < lVar2)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0 &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
         ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x100) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
    lVar2 = (**(code **)(WdfFunctions_01015 + 0xc48))
                      (WdfDriverGlobals,*(undefined8 *)pPVar6,OnCancel);
    if (-1 < lVar2) {
      if (*(int *)(pPVar6 + 0x60) == 1) {
        *(PBC_TARGET **)(pPVar4 + 0x58) = pPVar5;
      }
      *(PBC_REQUEST **)(pPVar5 + 0x18) = pPVar6;
      PbcRequestDoTransfer(pPVar4,pPVar6);
      if (pPVar6[0x24] == (PBC_REQUEST)0x0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
               ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
             ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
        }
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
        }
      }
      else {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
               (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
             ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
        }
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
            (((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                   &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
        }
        PbcRequestComplete(pPVar6,"PbcRequestConfigureForNonSequence");
      }
      goto LAB_1400086a6;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtRequestFailMarkCancelable_Error,
                    pPVar4 + 8,lVar2);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar4 + 0x78));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 8 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
         ((((((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
    }
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
    McTemplateK0ppqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     &EvtRequestCompleteSynchronously_Error,pPVar4 + 8,param_1,(char)param_3,
                     (char)*(undefined4 *)(pPVar6 + 8),(char)lVar2);
  }
  (*DAT_140022538)(SpbDriverGlobals,param_3,lVar2);
LAB_1400086a6:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
      (((((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2))))
       || ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar7);
  }
  return;
}



===== PbcRequestDoTransfer @ 1400089c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl PbcRequestDoTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

void __cdecl PbcRequestDoTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  uVar1 = *(uint *)(param_2 + 0x68);
  if (uVar1 == 0) {
    lVar3 = ControllerConfigureForTransfer(param_1,param_2);
    if ((lVar3 < 0) && ((Intel_iaLPSS2_I2CEnableBits & 1) != 0)) {
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtRequestFailToConfigure_Error,
                    param_1 + 8,lVar3);
    }
  }
  else {
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      McTemplateK0hqqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtTransferDelay_Info,
                       param_1 + 8,*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                       (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc),
                       (char)uVar1);
      uVar1 = *(uint *)(param_2 + 0x68);
    }
    cVar2 = (**(code **)(WdfFunctions_01015 + 0x9f8))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x80),(ulonglong)uVar1 * -10);
    if (cVar2 == '\x01') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))
           ) || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
                 (((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
                   (((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)))) ||
                  ((((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)) || (5 < uVar4)))))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                 &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar4);
  }
  return;
}



===== PbcRequestValidate @ 140008c34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PbcRequestValidate(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64,struct
   PBC_TARGET * __ptr64) */

long __cdecl PbcRequestValidate(PBC_DEVICE *param_1,PBC_REQUEST *param_2,PBC_TARGET *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined1 auStackY_98 [32];
  undefined8 local_58;
  longlong local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))))
       ) || (5 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  uVar1 = *(uint *)(param_2 + 0xc);
  lVar4 = 0;
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      local_50 = 0;
      local_48 = 0;
      local_58 = 0x18;
      (*DAT_140022530)(SpbDriverGlobals,*(undefined8 *)param_2,uVar3,&local_58);
      if (0xffff < local_50 - 1U) {
        if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
          McTemplateK0hqqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtTransferLength_Error,
                           param_1 + 8,*(undefined2 *)(param_3 + 0xc),(char)uVar3,(char)uVar1,
                           (char)local_50);
        }
        lVar4 = -0x3ffffff3;
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5))))
       || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar2);
  }
  return lVar4;
}



===== PbcTargetGetSettings @ 140008e28 =====

/* long __cdecl PbcTargetGetSettings(struct PBC_DEVICE * __ptr64,void * __ptr64,struct
   PBC_TARGET_SETTINGS * __ptr64) */

long __cdecl PbcTargetGetSettings(PBC_DEVICE *param_1,void *param_2,PBC_TARGET_SETTINGS *param_3)

{
  undefined2 uVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar5 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar3 == 1)))) ||
      (((((uVar5 >> 0xd & 1) != 0 && (uVar3 == 2)) || (((uVar5 >> 0xe & 1) != 0 && (uVar3 == 3))))
       || (((((uVar5 >> 0xf & 1) != 0 && (uVar3 == 4)) ||
            (((uVar5 >> 0x10 & 1) != 0 && (uVar3 == 5)))) || (5 < uVar3)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  lVar4 = 0;
  if (*(uint *)((longlong)param_2 + 4) < 0xc) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                     &EvtTargetInvalidPropertiesLenght_Error,param_1 + 8,
                     *(uint *)((longlong)param_2 + 4),0xc);
    }
  }
  else {
    if (*(byte *)((longlong)param_2 + 0xd) == 1) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 & 4) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar5 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
           ((((uVar5 >> 0xc & 1) != 0 && (uVar3 == 1)) ||
            (((uVar5 >> 0xd & 1) != 0 && (uVar3 == 2)))))) ||
          ((((uVar5 >> 0xe & 1) != 0 && (uVar3 == 3)) ||
           (((((uVar5 >> 0xf & 1) != 0 && (uVar3 == 4)) ||
             (((uVar5 >> 0x10 & 1) != 0 && (uVar3 == 5)))) || (5 < uVar3)))))))) {
        WPP_SF_dqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
                    &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3,(char)param_2 + '\b',
                    (char)*(undefined4 *)((longlong)param_2 + 0x14),
                    (char)*(undefined2 *)((longlong)param_2 + 0x18));
      }
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)((longlong)param_2 + 0x18);
      *(uint *)param_3 = *(ushort *)((longlong)param_2 + 0xf) & 1;
      uVar5 = *(uint *)((longlong)param_2 + 0x14);
      *(uint *)(param_3 + 8) = uVar5;
      if (uVar5 == 100000) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar5 & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
           (((((uVar5 >> 0xb & 1) == 0 || (uVar3 != 0)) &&
             ((((uVar5 >> 0xc & 1) == 0 || (uVar3 != 1)) &&
              (((uVar5 >> 0xd & 1) == 0 || (uVar3 != 2)))))) &&
            (((((uVar5 >> 0xe & 1) == 0 || (uVar3 != 3)) &&
              (((uVar5 >> 0xf & 1) == 0 || (uVar3 != 4)))) &&
             ((((uVar5 >> 0x10 & 1) == 0 || (uVar3 != 5)) && (uVar3 < 6)))))))) goto LAB_140009263;
        uVar1 = 0x5a;
      }
      else if (uVar5 == 400000) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar5 & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
           (((((uVar5 >> 0xb & 1) == 0 || (uVar3 != 0)) &&
             ((((uVar5 >> 0xc & 1) == 0 || (uVar3 != 1)) &&
              (((uVar5 >> 0xd & 1) == 0 || (uVar3 != 2)))))) &&
            (((((uVar5 >> 0xe & 1) == 0 || (uVar3 != 3)) &&
              (((uVar5 >> 0xf & 1) == 0 || (uVar3 != 4)))) &&
             ((((uVar5 >> 0x10 & 1) == 0 || (uVar3 != 5)) && (uVar3 < 6)))))))) goto LAB_140009263;
        uVar1 = 0x5b;
      }
      else if (uVar5 == 1000000) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar5 & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
           (((((((uVar5 >> 0xb & 1) == 0 || (uVar3 != 0)) &&
               (((uVar5 >> 0xc & 1) == 0 || (uVar3 != 1)))) &&
              (((uVar5 >> 0xd & 1) == 0 || (uVar3 != 2)))) &&
             ((((uVar5 >> 0xe & 1) == 0 || (uVar3 != 3)) &&
              (((uVar5 >> 0xf & 1) == 0 || (uVar3 != 4)))))) &&
            ((((uVar5 >> 0x10 & 1) == 0 || (uVar3 != 5)) && (uVar3 < 6)))))) goto LAB_140009263;
        uVar1 = 0x5c;
      }
      else {
        if ((uVar5 != 1400000) && (uVar5 != 3400000)) {
          if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
            puVar2 = &EvtTargetInvalidConnectionSpeed_Error;
            goto LAB_140008f4d;
          }
          goto LAB_140008f20;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar5 & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
           (((((uVar5 >> 0xb & 1) == 0 || (uVar3 != 0)) &&
             ((((uVar5 >> 0xc & 1) == 0 || (uVar3 != 1)) &&
              (((uVar5 >> 0xd & 1) == 0 || (uVar3 != 2)))))) &&
            (((((uVar5 >> 0xe & 1) == 0 || (uVar3 != 3)) &&
              (((uVar5 >> 0xf & 1) == 0 || (uVar3 != 4)))) &&
             ((((uVar5 >> 0x10 & 1) == 0 || (uVar3 != 5)) && (uVar3 < 6)))))))) goto LAB_140009263;
        uVar1 = 0x5d;
      }
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
               &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
      goto LAB_140009263;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      uVar5 = (uint)*(byte *)((longlong)param_2 + 0xd);
      puVar2 = &EvtTargetInvalidBusType_Error;
LAB_140008f4d:
      McTemplateK0q((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar2,param_1 + 8,uVar5);
    }
  }
LAB_140008f20:
  lVar4 = -0x3ffffff3;
LAB_140009263:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
     ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
      ((((((((uVar5 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar3 == 1)))
           ) || (((uVar5 >> 0xd & 1) != 0 && (uVar3 == 2)))) ||
         (((uVar5 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
        ((((uVar5 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar3 == 5))))
        )) || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
             &WPP_1513627b166f3d882c95a6a1e3daa1a0_Traceguids,uVar3);
  }
  return lVar4;
}



===== McTemplateK0h @ 140009300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0h(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined2 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_20 = 2;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateK0hqq @ 140009354 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined2 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 2;
  local_48 = local_res20;
  local_30 = 4;
  local_38 = &param_5;
  local_28 = &param_6;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0hqqq @ 1400093c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined2 *local_58;
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
  local_50 = 2;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0hqqqqx @ 140009450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqqqx(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                       ,undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                       undefined1 param_9)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined2 *local_78;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = local_res20;
  local_70 = 2;
  local_68 = &param_5;
  local_60 = 4;
  local_58 = &param_6;
  local_48 = &param_7;
  local_38 = &param_8;
  local_28 = &param_9;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,7,local_88);
  return;
}



===== McTemplateK0hqqx @ 1400094fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqx(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined2 *local_58;
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
  local_50 = 2;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0hqx @ 140009588 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqx(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined2 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_40 = 2;
  local_38 = &param_5;
  local_30 = 4;
  local_28 = &param_6;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0pp @ 1400095fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pp(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_28 = &param_5;
  local_30 = 8;
  local_2c = 0;
  local_20 = 8;
  local_1c = 0;
  local_res20 = param_4;
  McGenEventWrite(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0ppp @ 140009664 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppp(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 8;
  local_28 = &param_6;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0pppq @ 1400096dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 8;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0pppx @ 140009768 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppx(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 8;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0pppxxq @ 1400097f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppxxq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                       ,undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                       undefined1 param_9)

{
  undefined8 local_res20;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined8 *local_78;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = &local_res20;
  local_70 = 8;
  local_68 = &param_5;
  local_60 = 8;
  local_58 = &param_6;
  local_48 = &param_7;
  local_38 = &param_8;
  local_28 = &param_9;
  local_50 = 8;
  local_40 = 8;
  local_30 = 8;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite(param_1,param_2,param_3,7,local_88);
  return;
}



===== McTemplateK0ppqq @ 1400098a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ppqq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0qq @ 14000992c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                   undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_28 = &param_5;
  local_30 = 4;
  local_2c = 0;
  local_20 = 4;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0qqq @ 140009994 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &param_5;
  local_28 = &param_6;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0qxq @ 140009a00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qxq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_30 = 8;
  local_48 = local_res20;
  local_40 = 4;
  local_38 = &param_5;
  local_28 = &param_6;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0qxqp @ 140009a70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qxqp(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
  McGenEventWrite(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0qxqq @ 140009afc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qxqq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
  McGenEventWrite(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0sppxq @ 140009b88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sppxq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                      undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  char *local_68;
  int local_60;
  undefined4 local_5c;
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
  if (param_4 == (char *)0x0) {
    local_60 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_60 = (int)lVar1 + 1;
  }
  local_5c = 0;
  local_68 = "NULL";
  if (param_4 != (char *)0x0) {
    local_68 = param_4;
  }
  local_50 = 8;
  local_58 = &param_5;
  local_40 = 8;
  local_48 = &param_6;
  local_30 = 8;
  local_38 = &param_7;
  local_28 = &param_8;
  local_20 = 4;
  McGenEventWrite(param_1,param_2,param_3,6,local_78);
  return;
}



===== WPP_SF_ddd @ 140009c4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dD @ 140009ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_dqDD @ 140009ce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== ControllerAcknowledgeInterrupts @ 140009d4c =====

/* void __cdecl ControllerAcknowledgeInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ControllerAcknowledgeInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  undefined2 uVar4;
  uint uVar5;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
       ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3))))))
      || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
  }
  if (param_2 == 0xffffffff) {
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x40));
    if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 5)) ||
       (((((uVar1 & 0x800) == 0 || (uVar5 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)))) &&
        ((((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)) &&
         ((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
          (((((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)) &&
            (((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)))) && (uVar5 < 6))))))))))
    goto LAB_14000a67b;
    uVar4 = 0x67;
  }
  else {
    if ((((((param_2 & 1) != 0) &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x44)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
        ((((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 & 2) != 0) &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x48)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
          || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
         ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
          ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))))) || (5 < uVar5)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 & 4) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
         ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 & 8) != 0) &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x4c)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))))) ||
          (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))
          ))) || (5 < uVar5)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 & 0x10) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
        (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                    (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 & 0x20) != 0) &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x50)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
         (((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ) || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((param_2 & 0x40) != 0) {
      uVar3 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x80));
      *(ulong *)(param_1 + 0x9c) = uVar3;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
           ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))))) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))) || (5 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                 &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
      }
    }
    if ((((((char)param_2 < '\0') &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x58)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
        (((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3))))
         || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 >> 8 & 1) != 0) &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x5c)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
         ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3))))
         )) || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 >> 9 & 1) != 0) &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x60)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 >> 10 & 1) != 0) &&
          (HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 100))
          , (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
        ((((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
          ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 & 0x800) != 0) &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x68)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
        (((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3))))
         || (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 >> 0xc & 1) != 0) &&
          (HWREG<unsigned_long>::Read
                     ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0xa8)),
          (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
         (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))
          ) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
    if ((((((param_2 >> 0xd & 1) == 0) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control))
         || (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 5)) ||
       (((((((uVar1 & 0x800) == 0 || (uVar5 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1))))
          && (((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)))) &&
         (((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)))) &&
        (((((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)) && (((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)))
          ) && (uVar5 < 6)))))) goto LAB_14000a67b;
    uVar4 = 0x75;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
LAB_14000a67b:
  if ((param_2 >> 0x10 & 1) != 0) {
    lVar2 = *(longlong *)(param_1 + 0x38);
    uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 8));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 8),uVar3 & 0xffffffef);
    HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x24));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
    }
  }
  if (param_1[0x118] != (PBC_DEVICE)0x0) {
    DmaAcknowledgeInterrupts(param_1,param_2);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 & 0x800) != 0 && (uVar5 == 0)) ||
      ((((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
         ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3))))
         )) || ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))) || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar5);
  }
  return;
}



===== ControllerCompleteTransfer @ 14000a7e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ControllerCompleteTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned char) */

void __cdecl ControllerCompleteTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2,uchar param_3)

{
  uint uVar1;
  char cVar2;
  uchar uVar3;
  long lVar4;
  undefined2 uVar5;
  uint uVar6;
  PBC_REQUEST PVar8;
  PBC_REQUEST PVar7;
  int iVar9;
  
  uVar6 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5))))
        || (5 < uVar6)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar6);
  }
  cVar2 = (**(code **)(WdfFunctions_01015 + 0xa00))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x88),0);
  if (((((cVar2 != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2))))
         )) || (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))))
       ) || (5 < uVar6)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar6);
  }
  if (param_1[0x119] != (PBC_DEVICE)0x0) {
    uVar3 = DmaCheckBusy(param_1,1);
    if (uVar3 == '\x01') {
      uVar3 = DmaTxComplete(param_1,param_2,3);
      if (uVar3 == '\0') {
        *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))))) ||
            (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                   &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar6);
        }
      }
    }
    uVar3 = DmaCheckBusy(param_1,0);
    if (uVar3 == '\x01') {
      uVar3 = DmaRxComplete(param_1,param_2,3);
      if (uVar3 == '\0') {
        *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
            (((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
                   &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar6);
        }
      }
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x88),0);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0hqqxq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerProcessingEnd_Info,
                      param_1 + 8,*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                      (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc),
                      (char)*(undefined8 *)(param_2 + 0x70),(char)*(undefined4 *)(param_2 + 0x20));
  }
  *(longlong *)(param_2 + 0x18) = *(longlong *)(param_2 + 0x18) + *(longlong *)(param_2 + 0x70);
  *(undefined8 *)(param_2 + 0x70) = 0;
  LOCK();
  *(undefined4 *)(param_1 + 0x68) = 0;
  UNLOCK();
  if ((param_3 == '\0') && (*(int *)(param_2 + 0x20) != -0x3ffffee0)) {
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    if (*(uint *)(param_2 + 0x10) < *(uint *)(param_2 + 0xc)) {
      lVar4 = PbcRequestConfigureForIndex(param_2,*(uint *)(param_2 + 0x10));
      *(long *)(param_2 + 0x20) = lVar4;
      if (-1 < lVar4) {
        PbcRequestDoTransfer(param_1,param_2);
        goto LAB_14000ae19;
      }
    }
  }
  PVar8 = (PBC_REQUEST)0x1;
  PVar7 = (PBC_REQUEST)0x1;
  if (*(int *)(param_2 + 0x20) == -0x3ffffee0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
         || ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))
          ) || (5 < uVar6)))))) {
      uVar5 = 0x5a;
      iVar9 = -0x3ffffee0;
LAB_14000ad8d:
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar6,(char)iVar9);
    }
  }
  else {
    iVar9 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,*(undefined8 *)param_2);
    if (iVar9 < 0) {
      if (iVar9 == -0x3ffffee0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
              (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                   &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar6);
        }
        PVar7 = (PBC_REQUEST)0x0;
      }
      else {
        PVar7 = PVar8;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
             ((((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                    &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar6,(char)iVar9);
        }
      }
      *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
    }
    else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
            ((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) ||
               (((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) ||
                 (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))))) || (5 < uVar6)))) {
      uVar5 = 0x59;
      goto LAB_14000ad8d;
    }
  }
  if (*(int *)(param_2 + 0x20) == -0x3ffffee0) {
    ControllerDisableInterrupts(param_1);
    *(undefined8 *)(param_2 + 0x70) = 0;
    *(undefined8 *)(param_2 + 0x18) = 0;
    ControllerFinishTransfer(param_1);
    *(undefined8 *)(*(longlong *)(param_1 + 0x58) + 0x18) = 0;
    if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x60) == 1)) {
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
    *(undefined4 *)(param_1 + 0x104) = 0;
    param_2[0x24] = PVar7;
  }
  else {
    if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x60) == 1)) {
      ControllerFinishTransfer(param_1);
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x58) + 0x18) = 0;
    if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x60) == 1)) {
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
    param_2[0x24] = (PBC_REQUEST)0x1;
  }
LAB_14000ae19:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar6);
  }
  return;
}



===== ControllerConfigureForTransfer @ 14000aeb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ControllerConfigureForTransfer(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64) */

long __cdecl ControllerConfigureForTransfer(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  uchar uVar4;
  byte bVar5;
  PBC_REQUEST PVar6;
  undefined1 uVar7;
  char cVar8;
  ulong uVar9;
  char *pcVar10;
  HWREG<unsigned_long> *this;
  undefined2 uVar11;
  undefined *puVar12;
  uint uVar13;
  uint uVar14;
  char *pcVar15;
  long lVar16;
  
  uVar14 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar14 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar13 >> 0xb & 1) != 0 && (uVar14 == 0)) || (((uVar13 & 0x1000) != 0 && (uVar14 == 1)))
         ) || (((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)))) ||
       (((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)))) ||
      (((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
        (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14);
  }
  lVar16 = 0;
  *(undefined4 *)(param_2 + 0x20) = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar13 >> 0xb & 1) != 0 && (uVar14 == 0)) ||
        ((((uVar13 & 0x1000) != 0 && (uVar14 == 1)) || (((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)))
         ))) || ((((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)) ||
                 ((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
                  (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))))))) || (5 < uVar14)))) {
    iVar2 = *(int *)(param_2 + 0x60);
    pcVar10 = "UNKNOWN";
    if (iVar2 == 0) {
      pcVar15 = "Invalid ";
    }
    else if (iVar2 == 1) {
      pcVar15 = "Single";
    }
    else if (iVar2 == 2) {
      pcVar15 = "First";
    }
    else if (iVar2 == 3) {
      pcVar15 = "Continue";
    }
    else if (iVar2 == 4) {
      pcVar15 = "Last";
    }
    else {
      pcVar15 = "UNKNOWN";
      if (iVar2 == 5) {
        pcVar15 = "Max";
      }
    }
    iVar2 = *(int *)(param_2 + 8);
    if (iVar2 == 0) {
      pcVar10 = "Undefined ";
    }
    else if (iVar2 == 1) {
      pcVar10 = "Read";
    }
    else if (iVar2 == 2) {
      pcVar10 = "Write";
    }
    else if (iVar2 == 3) {
      pcVar10 = "Sequence";
    }
    else if (iVar2 == 4) {
      pcVar10 = "LockCtrl";
    }
    else if (iVar2 == 5) {
      pcVar10 = "UnlockCtrl";
    }
    else if (iVar2 == 6) {
      pcVar10 = "LockConn";
    }
    else if (iVar2 == 7) {
      pcVar10 = "UnlockConn";
    }
    else if (iVar2 == 8) {
      pcVar10 = "Other";
    }
    else if (iVar2 == 9) {
      pcVar10 = "Max";
    }
    WPP_SF_dss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14,pcVar10,pcVar15);
  }
  uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x58) + 0xc);
  if ((*(int *)(param_2 + 0x60) - 1U < 2) || (*(int *)(param_1 + 0x104) == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) != 0 &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar13 >> 0xb & 1) != 0 && (uVar14 == 0)) ||
         ((((((uVar13 & 0x1000) != 0 && (uVar14 == 1)) ||
            (((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)))) ||
           (((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)))) ||
          (((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)))))) ||
        ((((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)) || (5 < uVar14)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14);
    }
    uVar4 = IsI2CBusFree(param_1,"I2C Status before first transfer");
    if (uVar4 != '\0') {
      LOCK();
      UNLOCK();
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c),0);
      uVar9 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
      uVar13 = 0;
      bVar5 = (byte)uVar9 & 1;
      if ((uVar9 & 1) != 0) {
        do {
          if (9 < uVar13) break;
          KeStallExecutionProcessor(0x19);
          uVar9 = HWREG<unsigned_long>::Read
                            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
          uVar13 = uVar13 + 1;
          bVar5 = (byte)uVar9 & 1;
        } while ((uVar9 & 1) != 0);
        if (bVar5 != 0) {
          *(undefined4 *)(param_2 + 0x20) = 0xc000036b;
          if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
            puVar12 = &EvtControllerTimeoutDisabling_Error;
            goto LAB_14000b1b6;
          }
          goto LAB_14000b1e4;
        }
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x3c),0);
      uVar13 = uVar1 | 0x1000;
      if (*(int *)(*(longlong *)(param_1 + 0x58) + 8) != 1) {
        uVar13 = (uint)uVar1;
      }
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 4),uVar13);
      iVar2 = *(int *)(*(longlong *)(param_1 + 0x58) + 0x10);
      if (iVar2 == 100000) {
        HWREG<unsigned_long>::Write(*(HWREG<unsigned_long> **)(param_1 + 0x30),99);
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x14),
                   *(ulong *)(param_1 + 0xa0));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x18),
                   *(ulong *)(param_1 + 0xa4));
        HWREG<unsigned_long>::Write
                  ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x7c),
                   *(int *)(param_1 + 0xac) << 0x10 | *(uint *)(param_1 + 0xa8));
        uVar9 = *(ulong *)(param_1 + 0xb0);
LAB_14000b5fe:
        this = (HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0xa0);
LAB_14000b609:
        HWREG<unsigned_long>::Write(this,uVar9);
      }
      else {
        if (iVar2 == 400000) {
          HWREG<unsigned_long>::Write(*(HWREG<unsigned_long> **)(param_1 + 0x30),0x65);
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x1c),
                     *(ulong *)(param_1 + 0xb4));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x20),
                     *(ulong *)(param_1 + 0xb8));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x7c),
                     *(int *)(param_1 + 0xc0) << 0x10 | *(uint *)(param_1 + 0xbc));
          uVar9 = *(ulong *)(param_1 + 0xc4);
          goto LAB_14000b5fe;
        }
        if (iVar2 == 1000000) {
          HWREG<unsigned_long>::Write(*(HWREG<unsigned_long> **)(param_1 + 0x30),0x65);
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x1c),
                     *(ulong *)(param_1 + 200));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x20),
                     *(ulong *)(param_1 + 0xcc));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x7c),
                     *(int *)(param_1 + 0xd4) << 0x10 | *(uint *)(param_1 + 0xd0));
          uVar9 = *(ulong *)(param_1 + 0xd8);
          goto LAB_14000b5fe;
        }
        if ((iVar2 == 1400000) || (iVar2 == 3400000)) {
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0xc),1);
          HWREG<unsigned_long>::Write(*(HWREG<unsigned_long> **)(param_1 + 0x30),0x67);
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x1c),
                     *(ulong *)(param_1 + 0xb4));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x20),
                     *(ulong *)(param_1 + 0xb8));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x24),
                     *(ulong *)(param_1 + 0xdc));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x28),
                     *(ulong *)(param_1 + 0xe0));
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x7c),
                     *(int *)(param_1 + 0xe8) << 0x10 | *(uint *)(param_1 + 0xe4));
          uVar9 = *(ulong *)(param_1 + 0xec);
          this = (HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0xa4);
          goto LAB_14000b609;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 4) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar13 >> 0xb & 1) != 0 && (uVar14 == 0)) ||
             (((uVar13 >> 0xc & 1) != 0 && (uVar14 == 1)))) ||
            (((((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)) ||
              (((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)))) ||
             (((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
               (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                    &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14,(char)iVar2);
        }
      }
      LOCK();
      UNLOCK();
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c),1);
      uVar9 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
      bVar5 = (byte)uVar9 & 1;
      uVar13 = 0;
      if ((uVar9 & 1) == 0) {
        do {
          if (9 < uVar13) break;
          KeStallExecutionProcessor(0x19);
          uVar9 = HWREG<unsigned_long>::Read
                            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
          uVar13 = uVar13 + 1;
          bVar5 = (byte)uVar9 & 1;
        } while ((uVar9 & 1) == 0);
        if (bVar5 == 0) {
          if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
            McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                            &EvtControllerTimeoutEnabling_Error,param_1 + 8,
                            *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                            (char)*(undefined4 *)(param_2 + 0x10),
                            (char)*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0x20) = 0xc000036b;
          goto LAB_14000b1e4;
        }
      }
      *(undefined4 *)(param_1 + 0x104) = 1;
      goto LAB_14000b6b3;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      puVar12 = &EvtControllerBusBusy_Error;
LAB_14000b1b6:
      McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar12,param_1 + 8,
                      *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                      (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
    }
LAB_14000b1e4:
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0hqqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerConfiguration_Error
                       ,param_1 + 8,*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                       (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc),1)
      ;
    }
    ControllerCompleteTransfer(param_1,param_2,'\x01');
    lVar16 = -0x3fffffff;
    goto LAB_14000b237;
  }
LAB_14000b6b3:
  uVar9 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x54))
  ;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar13 & 0x800) != 0 && (uVar14 == 0)) ||
       ((((uVar13 & 0x1000) != 0 && (uVar14 == 1)) || (((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2))))
       )) || ((((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)) ||
              (((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
                (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))))) {
    WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14,(char)uVar9,
               (char)*(undefined4 *)(param_1 + 0x9c));
  }
  *(undefined4 *)(param_1 + 0x9c) = 0;
  if ((*(int *)(param_2 + 0x60) == 4) || (*(int *)(param_2 + 0x60) == 1)) {
    PVar6 = (PBC_REQUEST)0x1;
  }
  else {
    PVar6 = (PBC_REQUEST)0x0;
  }
  param_2[0x78] = PVar6;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar13 & 0x800) != 0 && (uVar14 == 0)) || (((uVar13 & 0x1000) != 0 && (uVar14 == 1))))
        || ((((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)) ||
            (((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)))))) ||
       ((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
        (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))))) || (5 < uVar14)))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14,
              param_2[0x78] != (PBC_REQUEST)0x0);
  }
  lVar3 = *(longlong *)(param_1 + 0x38);
  uVar9 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar3 + 8));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar3 + 8),uVar9 & 0xffffffef);
  HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x24));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar13 & 0x800) != 0 && (uVar14 == 0)) ||
      (((((uVar13 >> 0xc & 1) != 0 && (uVar14 == 1)) ||
        ((((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)) ||
         (((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)))))) ||
       (((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
         (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14);
  }
  uVar9 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18))
  ;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar13 & 0x800) != 0 && (uVar14 == 0)) ||
      ((((uVar13 >> 0xc & 1) != 0 && (uVar14 == 1)) ||
       (((((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)) ||
         (((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)))) ||
        (((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
          (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))))))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14,(char)uVar9);
  }
  if (*(int *)(param_2 + 100) == 2) {
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      uVar7 = (undefined1)*(undefined8 *)(param_2 + 0x28);
      puVar12 = &EvtControllerConfiguredWrite_Info;
LAB_14000b965:
      McTemplateK0hqqx((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,puVar12,param_1 + 8,
                       *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                       (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc),
                       uVar7);
    }
  }
  else {
    if (*(int *)(param_2 + 100) != 1) {
      if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
        McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,
                        &EvtControllerConfiguredOther_Error,param_1 + 8,
                        *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                        (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
      goto LAB_14000b1e4;
    }
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      uVar7 = (undefined1)*(undefined8 *)(param_2 + 0x30);
      puVar12 = &EvtControllerConfiguredRead_Info;
      goto LAB_14000b965;
    }
  }
  CheckTransferForDmaOperation(param_1,param_2);
  if (*(int *)(param_2 + 100) == 2) {
    if (param_1[0x119] == (PBC_DEVICE)0x0) {
LAB_14000bc78:
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerPioProcessing_Info
                        ,param_1 + 8,*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                        (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x88),0);
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals);
      ControllerDisableInterrupts(param_1);
      ControllerAcknowledgeInterrupts(param_1,0xffffffff);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      LOCK();
      *(undefined4 *)(param_1 + 0x68) = 0x242;
      UNLOCK();
      *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 0x100;
      cVar8 = (**(code **)(WdfFunctions_01015 + 0x470))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
      if (((((cVar8 != '\0') || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
           (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) == 0)) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 3)) ||
         (((((uVar13 & 0x800) == 0 || (uVar14 != 0)) &&
           ((((uVar13 >> 0xc & 1) == 0 || (uVar14 != 1)) &&
            (((uVar13 >> 0xd & 1) == 0 || (uVar14 != 2)))))) &&
          ((((uVar13 >> 0xe & 1) == 0 || (uVar14 != 3)) &&
           (((((uVar13 >> 0xf & 1) == 0 || (uVar14 != 4)) &&
             (((uVar13 >> 0x10 & 1) == 0 || (uVar14 != 5)))) && (uVar14 < 6))))))))
      goto LAB_14000baed;
      uVar11 = 0x1b;
    }
    else {
      if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
        McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerDmaProcessing_Info
                        ,param_1 + 8,*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                        (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
      }
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x88),2);
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x8c),0);
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals);
      ControllerDisableInterrupts(param_1);
      ControllerAcknowledgeInterrupts(param_1,0xffffffff);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      LOCK();
      *(undefined4 *)(param_1 + 0x68) = 0x1010242;
      UNLOCK();
      *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 1;
      cVar8 = (**(code **)(WdfFunctions_01015 + 0x470))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
      if (((((cVar8 != '\0') || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
           (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) == 0)) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 3)) ||
         (((((((uVar13 & 0x800) == 0 || (uVar14 != 0)) &&
             (((uVar13 >> 0xc & 1) == 0 || (uVar14 != 1)))) &&
            (((uVar13 >> 0xd & 1) == 0 || (uVar14 != 2)))) &&
           (((uVar13 >> 0xe & 1) == 0 || (uVar14 != 3)))) &&
          (((((uVar13 >> 0xf & 1) == 0 || (uVar14 != 4)) &&
            (((uVar13 >> 0x10 & 1) == 0 || (uVar14 != 5)))) && (uVar14 < 6)))))) goto LAB_14000baed;
      uVar11 = 0x19;
    }
LAB_14000bada:
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14);
  }
  else {
    if ((*(int *)(param_2 + 100) != 1) || (param_1[0x119] == (PBC_DEVICE)0x0)) goto LAB_14000bc78;
    if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
      McTemplateK0hqq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerDmaProcessing_Info,
                      param_1 + 8,*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),
                      (char)*(undefined4 *)(param_2 + 0x10),(char)*(undefined4 *)(param_2 + 0xc));
    }
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x88),3);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x8c),0);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x90),0);
    (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals);
    ControllerDisableInterrupts(param_1);
    ControllerAcknowledgeInterrupts(param_1,0xffffffff);
    *(undefined4 *)(param_1 + 0x6c) = 0;
    LOCK();
    *(undefined4 *)(param_1 + 0x68) = 0x5000042;
    UNLOCK();
    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 0x11;
    cVar8 = (**(code **)(WdfFunctions_01015 + 0x470))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
    if (((((cVar8 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 & 8) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar13 & 0x800) != 0 && (uVar14 == 0)) || (((uVar13 >> 0xc & 1) != 0 && (uVar14 == 1)))
          ) || ((((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)) ||
                (((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)))))) ||
        (((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
          (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))) {
      uVar11 = 0x1a;
      goto LAB_14000bada;
    }
  }
LAB_14000baed:
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
LAB_14000b237:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar13 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar13 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar13 >> 0xb & 1) != 0 && (uVar14 == 0)) ||
        (((uVar13 >> 0xc & 1) != 0 && (uVar14 == 1)))) ||
       (((uVar13 >> 0xd & 1) != 0 && (uVar14 == 2)))) ||
      ((((uVar13 >> 0xe & 1) != 0 && (uVar14 == 3)) ||
       (((((uVar13 >> 0xf & 1) != 0 && (uVar14 == 4)) ||
         (((uVar13 >> 0x10 & 1) != 0 && (uVar14 == 5)))) || (5 < uVar14)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar14);
  }
  return lVar16;
}



===== ControllerDisableInterrupts @ 14000bde8 =====

/* void __cdecl ControllerDisableInterrupts(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerDisableInterrupts(PBC_DEVICE *param_1)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x30),0);
  lVar2 = *(longlong *)(param_1 + 0x38);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x20));
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x20),uVar3 | 2);
  if (param_1[0x118] != (PBC_DEVICE)0x0) {
    DmaDisableInterrupts(param_1);
  }
  param_1[0x74] = (PBC_DEVICE)0x1;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
  }
  return;
}



===== ControllerDoRead @ 14000bf5c =====

/* long __cdecl ControllerDoRead(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl ControllerDoRead(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulong uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  uint uVar8;
  long lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong in_stack_ffffffffffffffb8;
  
  uVar8 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar8 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar2 & 0x800) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
       (((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2)))) ||
      ((((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
       (((((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5))))
        || (5 < uVar8)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar8);
  }
  lVar9 = 0;
  uVar3 = *(ulonglong *)(param_2 + 0x38);
  uVar10 = *(ulonglong *)(param_2 + 0x48);
  uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x78))
  ;
  uVar11 = (ulonglong)uVar4;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 & 0x800) != 0 && (uVar8 == 0)) ||
       ((((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2))))))
      || ((((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3)) ||
          (((((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))))) {
    uVar7 = uVar3 - uVar10;
    in_stack_ffffffffffffffb8 = uVar11;
    if (uVar7 < uVar11) {
      in_stack_ffffffffffffffb8 = uVar7;
    }
    WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar8,
               (char)in_stack_ffffffffffffffb8,(char)uVar10);
  }
  for (; (uVar10 < uVar3 && ((int)uVar11 != 0)); uVar11 = (ulonglong)((int)uVar11 - 1)) {
    uVar4 = HWREG<unsigned_long>::Read
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x10));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (char)uVar2 < '\0' &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar2 >> 0xb & 1) != 0 && (uVar8 == 0)) ||
          (((((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)) ||
            (((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2)))) ||
           (((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3)))))) ||
         (((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)))) ||
        ((((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5)) || (5 < uVar8)))))) {
      in_stack_ffffffffffffffb8 = uVar10;
      WPP_SF_dqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                  &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar8,(char)uVar10,
                  (char)*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),(char)uVar4);
    }
    puVar6 = *(undefined8 **)(param_2 + 0x58);
    lVar9 = -0x3ffffffc;
    uVar7 = uVar10;
    if (uVar10 < *(ulonglong *)(param_2 + 0x30)) {
      for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
        puVar1 = (uint *)(puVar6 + 5);
        if (uVar7 < *puVar1) {
          if ((*(byte *)((longlong)puVar6 + 10) & 5) == 0) {
            in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
            lVar5 = MmMapLockedPagesSpecifyCache(puVar6,0,1,0,in_stack_ffffffffffffffb8,0x40000010);
          }
          else {
            lVar5 = puVar6[3];
          }
          if (lVar5 != 0) {
            *(char *)(lVar5 + uVar7) = (char)uVar4;
            lVar9 = 0;
          }
          break;
        }
        uVar7 = uVar7 - *puVar1;
      }
    }
    if (lVar9 < 0) break;
    *(longlong *)(param_2 + 0x70) = *(longlong *)(param_2 + 0x70) + 1;
    uVar10 = uVar10 + 1;
  }
  *(ulonglong *)(param_2 + 0x48) = uVar10;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 & 0x800) != 0 && (uVar8 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
        (((uVar2 >> 0xd & 1) != 0 && (uVar8 == 2)))) || (((uVar2 >> 0xe & 1) != 0 && (uVar8 == 3))))
      || (((((uVar2 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
           (((uVar2 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar8);
  }
  return lVar9;
}



===== ControllerDoReadPrepare @ 14000c2a4 =====

/* long __cdecl ControllerDoReadPrepare(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned long * __ptr64) */

long __cdecl ControllerDoReadPrepare(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  char *pcVar10;
  
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar8 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar8 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar8 & 0x800) != 0 && (uVar7 == 0)) || (((uVar8 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
      (((((uVar8 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar8 >> 0xe & 1) != 0 && (uVar7 == 3))))
       || (((((uVar8 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar8 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar7);
  }
  uVar1 = *(ulonglong *)(param_2 + 0x40);
  uVar2 = *(ulonglong *)(param_2 + 0x38);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x78))
  ;
  uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x74))
  ;
  uVar8 = 0x3f - uVar3;
  if (0x40 - uVar4 < 0x3f - uVar3) {
    uVar8 = 0x40 - uVar4;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar6 & 0x800) != 0 && (uVar7 == 0)) ||
      ((((((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2))))
        || (((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
       (((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5))))
        || (5 < uVar7)))))))) {
    uVar9 = (ulonglong)uVar8;
    if (uVar2 - uVar1 < (ulonglong)uVar8) {
      uVar9 = uVar2 - uVar1;
    }
    WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar7,(char)uVar9,(char)uVar1);
  }
  uVar9 = uVar1;
  if (uVar1 < uVar2) {
    do {
      if (uVar8 == 0) break;
      uVar6 = (-(uint)(uVar9 != 0) & 0xfffffc00) + 0x500;
      if ((param_2[0x78] != (PBC_REQUEST)0x0) && (uVar2 - uVar9 == 1)) {
        uVar6 = uVar6 | 0x200;
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (char)uVar5 < '\0')) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar5 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar7 == 1)))
           ) || (((((uVar5 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
                  (((uVar5 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
                 (((((uVar5 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                   (((uVar5 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
        pcVar10 = " ";
        uVar5 = uVar6 & 0x600;
        if (uVar5 == 0x200) {
          pcVar10 = "| STOP";
        }
        if (uVar5 == 0x400) {
          pcVar10 = "| RESTART";
        }
        if (uVar5 == 0x600) {
          pcVar10 = "| RESTART | STOP";
        }
        WPP_SF_dPDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                    &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar7,(char)uVar9,
                    (char)*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),pcVar10);
      }
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x10),uVar6);
      uVar8 = uVar8 - 1;
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar2);
  }
  *(ulonglong *)(param_2 + 0x40) = uVar9;
  *param_3 = (int)uVar9 - (int)uVar1;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar8 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar8 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar8 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
       ((((uVar8 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
        ((((uVar8 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar8 >> 0xe & 1) != 0 && (uVar7 == 3)))))
        ))) || (((((uVar8 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                 (((uVar8 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar7);
  }
  return 0;
}



===== ControllerDoWrite @ 14000c620 =====

/* long __cdecl ControllerDoWrite(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl ControllerDoWrite(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint *puVar1;
  ulonglong uVar2;
  ulong uVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  char *pcVar14;
  byte bVar15;
  long local_res8;
  ulonglong in_stack_ffffffffffffffb8;
  
  uVar8 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar8 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar9 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar9 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar9 & 0x800) != 0 && (uVar8 == 0)) || (((uVar9 >> 0xc & 1) != 0 && (uVar8 == 1)))) ||
      (((((uVar9 >> 0xd & 1) != 0 && (uVar8 == 2)) || (((uVar9 >> 0xe & 1) != 0 && (uVar8 == 3))))
       || (((((uVar9 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
            (((uVar9 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar8);
  }
  uVar13 = *(ulonglong *)(param_2 + 0x40);
  uVar2 = *(ulonglong *)(param_2 + 0x38);
  local_res8 = 0;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x74))
  ;
  uVar9 = 0x40 - uVar3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar10 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar10 & 8) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar10 & 0x800) != 0 && (uVar8 == 0)) ||
      ((((((uVar10 >> 0xc & 1) != 0 && (uVar8 == 1)) || (((uVar10 >> 0xd & 1) != 0 && (uVar8 == 2)))
         ) || (((uVar10 >> 0xe & 1) != 0 && (uVar8 == 3)))) ||
       (((((uVar10 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
         (((uVar10 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))))) {
    in_stack_ffffffffffffffb8 = (ulonglong)uVar9;
    if (uVar2 - uVar13 < (ulonglong)uVar9) {
      in_stack_ffffffffffffffb8 = uVar2 - uVar13;
    }
    WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar8,
               (char)in_stack_ffffffffffffffb8,(char)uVar13);
  }
  lVar11 = 0;
  if (uVar13 < uVar2) {
    local_res8._0_1_ = 0;
    bVar15 = (byte)local_res8;
    do {
      if (uVar9 == 0) break;
      iVar7 = -0x3ffffffc;
      puVar6 = *(undefined8 **)(param_2 + 0x50);
      local_res8 = -0x3ffffffc;
      uVar12 = uVar13;
      if (uVar13 < *(ulonglong *)(param_2 + 0x28)) {
        for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
          puVar1 = (uint *)(puVar6 + 5);
          if (uVar12 < *puVar1) {
            if ((*(byte *)((longlong)puVar6 + 10) & 5) == 0) {
              in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
              lVar5 = MmMapLockedPagesSpecifyCache
                                (puVar6,0,1,0,in_stack_ffffffffffffffb8,0x40000010);
            }
            else {
              lVar5 = puVar6[3];
            }
            iVar7 = -0x3ffffffc;
            if (lVar5 != 0) {
              bVar15 = *(byte *)(lVar5 + uVar12);
              iVar7 = 0;
              local_res8 = 0;
            }
            break;
          }
          uVar12 = uVar12 - *puVar1;
        }
      }
      if (iVar7 < 0) break;
      uVar10 = bVar15 | 0x400;
      if (uVar13 != 0) {
        uVar10 = (uint)bVar15;
      }
      if ((param_2[0x78] != (PBC_REQUEST)0x0) && (uVar2 - uVar13 == 1)) {
        uVar10 = uVar10 | 0x200;
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (char)uVar4 < '\0')) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar4 >> 0xb & 1) != 0 && (uVar8 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar8 == 1)))
           ) || (((((uVar4 >> 0xd & 1) != 0 && (uVar8 == 2)) ||
                  (((uVar4 >> 0xe & 1) != 0 && (uVar8 == 3)))) ||
                 (((((uVar4 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
                   (((uVar4 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))))) {
        pcVar14 = " ";
        uVar4 = uVar10 & 0x600;
        if (uVar4 == 0x200) {
          pcVar14 = "| STOP";
        }
        if (uVar4 == 0x400) {
          pcVar14 = "| RESTART";
        }
        if (uVar4 == 0x600) {
          pcVar14 = "| RESTART | STOP";
        }
        in_stack_ffffffffffffffb8 = uVar13;
        WPP_SF_dPDDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                     &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar8,(char)uVar13,
                     (char)*(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0xc),(char)uVar10,pcVar14
                    );
      }
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x10),uVar10);
      uVar9 = uVar9 - 1;
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar2);
    lVar11 = local_res8;
  }
  *(ulonglong *)(param_2 + 0x40) = uVar13;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar9 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar9 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar9 & 0x800) != 0 && (uVar8 == 0)) ||
       ((((uVar9 >> 0xc & 1) != 0 && (uVar8 == 1)) ||
        ((((uVar9 >> 0xd & 1) != 0 && (uVar8 == 2)) || (((uVar9 >> 0xe & 1) != 0 && (uVar8 == 3)))))
        ))) || (((((uVar9 >> 0xf & 1) != 0 && (uVar8 == 4)) ||
                 (((uVar9 >> 0x10 & 1) != 0 && (uVar8 == 5)))) || (5 < uVar8)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar8);
  }
  return lVar11;
}



===== ControllerEnableInterrupts @ 14000c9f4 =====

/* void __cdecl ControllerEnableInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl ControllerEnableInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulong uVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 & 0x10000) != 0 && (uVar4 == 5)))) ||
       (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
  }
  if (((((param_1[0x74] == (PBC_DEVICE)0x0) &&
        ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))))
      || (((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 & 0x10000) != 0 && (uVar4 == 5)))
            ))) || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
  }
  param_1[0x74] = (PBC_DEVICE)0x0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
      (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))
        ) || (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
               (((uVar1 & 0x10000) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
              &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4,(char)param_2);
  }
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x30),param_2 & 0xffff);
  lVar2 = *(longlong *)(param_1 + 0x38);
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x20));
  if ((param_2 >> 0x10 & 1) == 0) {
    uVar3 = uVar3 | 2;
  }
  else {
    uVar3 = uVar3 & 0xfffffffd;
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x20),uVar3);
  if (param_1[0x118] != (PBC_DEVICE)0x0) {
    DmaSetInterruptMask(param_1,param_2 & 0xff000000);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) ||
         ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3))))
         )))) || ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
  }
  return;
}



===== ControllerGetInterruptStatus @ 14000cc80 =====

/* unsigned long __cdecl ControllerGetInterruptStatus(struct PBC_DEVICE * __ptr64,unsigned long) */

ulong __cdecl ControllerGetInterruptStatus(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 & 0x800) != 0 && (uVar4 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
       ((((uVar5 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar5 >> 0xe & 1) != 0 && (uVar4 == 3))))))
      || (((((uVar5 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
           (((uVar5 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
  }
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x34))
  ;
  uVar3 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x20))
  ;
  uVar5 = uVar2 & 0xffff | (uVar3 & 1) << 0x10;
  if (param_1[0x118] != (PBC_DEVICE)0x0) {
    uVar2 = DmaGetInterruptStatus(param_1);
    uVar5 = uVar5 | uVar2 & 0xff000000;
  }
  uVar2 = uVar5 & param_2;
  if (param_1[0x74] == (PBC_DEVICE)0x0) {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 8) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 & 0x800) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
           || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
            (((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)))) ||
           ((((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)) || (5 < uVar4)))))))) {
        WPP_SF_dDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                    &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4,(char)uVar5,(char)param_2
                    ,(char)uVar2);
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar5 & 0x800) != 0 && (uVar4 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar4 == 1))))
          || ((((uVar5 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
              ((((uVar5 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
               (((((uVar5 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
                 (((uVar5 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                 &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
      }
    }
  }
  else {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 & 0x800) != 0 && (uVar4 == 0)) ||
        ((((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
          ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))) || (5 < uVar4)))))) {
      WPP_SF_dDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                  &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4,(char)uVar5,(char)param_2,
                  (char)uVar2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== ControllerInitialize @ 14000cf2c =====

/* long __cdecl ControllerInitialize(struct PBC_DEVICE * __ptr64) */

long __cdecl ControllerInitialize(PBC_DEVICE *param_1)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
  }
  lVar3 = 0;
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4));
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4),uVar2 & 0xfffffffc);
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4),uVar2 | 3)
  ;
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x38),
             -(uint)(*(int *)(param_1 + 0xf0) != 1) & 0xf);
  ControllerDisableInterrupts(param_1);
  *(undefined4 *)(param_1 + 0x104) = 0;
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x40),
             *(ulong *)(param_1 + 0x18));
  HWREG<unsigned_long>::Write
            ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x44),
             *(ulong *)(param_1 + 0x1c));
  uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0xfc))
  ;
  *(ulong *)(param_1 + 0x50) = uVar2;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 4) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4,(char)uVar2);
  }
  uVar1 = *(uint *)(param_1 + 0x50);
  if (((uVar1 & 0xf0) != 0) || (uVar1 == 0xffffffff)) {
    if ((Intel_iaLPSS2_I2CEnableBits & 1) != 0) {
      McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerCapability_Error,
                     param_1 + 8,uVar1 & 0xf0,(char)uVar1);
    }
    lVar3 = -0x3ffffb7d;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffb7d;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))
           ))) || ((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
                   (((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)))))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)) || (5 < uVar4)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))
       ) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar4);
  }
  return lVar3;
}



===== ControllerProcessInterrupts @ 14000d234 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ControllerProcessInterrupts(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST *
   __ptr64,unsigned long,unsigned long) */

void __cdecl
ControllerProcessInterrupts(PBC_DEVICE *param_1,PBC_REQUEST *param_2,ulong param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uchar uVar4;
  ulong uVar5;
  long lVar6;
  __uint64 _Var7;
  undefined2 uVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 uVar11;
  ulonglong uVar12;
  ulong local_res20 [2];
  
  uVar9 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar9 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5))))
       || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
  }
  if ((Intel_iaLPSS2_I2CEnableBits & 2) != 0) {
    McTemplateK0qq((undefined8 *)&iaLPSS2_I2C_PROVIDER_Context,&EvtControllerProcesInterrupts_Info,
                   param_1 + 8,param_3,(char)param_4);
  }
  if ((int)param_4 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2))))
         )) || (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                 ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
    }
    *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
    uVar5 = HWREG<unsigned_long>::Read
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
    if ((uVar5 & 1) != 0) {
      lVar10 = *(longlong *)(param_1 + 0x30);
      uVar5 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar10 + 0x6c));
      HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar10 + 0x6c),uVar5 | 2);
      cVar3 = (**(code **)(WdfFunctions_01015 + 0x9f8))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x88),0xfffffffffd050f80);
      if (cVar3 == '\x01') {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           ((((uVar1 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
            (((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) &&
              (((uVar1 >> 0xd & 1) == 0 || (uVar9 != 2)))) &&
             (((((uVar1 >> 0xe & 1) == 0 || (uVar9 != 3)) &&
               (((uVar1 >> 0xf & 1) == 0 || (uVar9 != 4)))) &&
              ((((uVar1 >> 0x10 & 1) == 0 || (uVar9 != 5)) && (uVar9 < 6))))))))))
        goto LAB_14000ecd2;
        uVar8 = 0x1f;
      }
      else {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
           (((((uVar1 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
             ((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) &&
              (((uVar1 >> 0xd & 1) == 0 || (uVar9 != 2)))))) &&
            (((((uVar1 >> 0xe & 1) == 0 || (uVar9 != 3)) &&
              (((uVar1 >> 0xf & 1) == 0 || (uVar9 != 4)))) &&
             ((((uVar1 >> 0x10 & 1) == 0 || (uVar9 != 5)) && (uVar9 < 6)))))))) goto LAB_14000ecd2;
        uVar8 = 0x20;
      }
LAB_14000de62:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
      goto LAB_14000ecd2;
    }
LAB_14000d599:
    uVar4 = '\x01';
  }
  else {
    if (((byte)(param_4 >> 0x1e) & 1) != 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                 &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
      }
      *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
      goto LAB_14000d599;
    }
    if ((param_3 >> 6 & 1) != 0) {
      LOCK();
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xffffffbf;
      UNLOCK();
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar1 & 0x800) != 0 && (uVar9 == 0)) ||
           (((((uVar1 & 0x1000) != 0 && (uVar9 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))
             ) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
        WPP_SF_dPD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                   &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,
                   (char)*(undefined8 *)(param_2 + 0x70),(char)*(undefined4 *)(param_1 + 0x9c));
      }
      uVar1 = *(uint *)(param_1 + 0x9c);
      if ((uVar1 & 0x10000) == 0) {
        if (*(int *)(param_2 + 0x20) == -0x3ffffee0) {
          *(undefined8 *)(param_2 + 0x70) = 0;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((uVar1 & 0x800) != 0 && (uVar9 == 0)) ||
              (((((uVar1 & 0x1000) != 0 && (uVar9 == 1)) ||
                ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                 (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
               (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                 (((uVar1 & 0x10000) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                      &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,
                      (char)*(undefined4 *)(param_1 + 0x9c));
          }
        }
        else if ((uVar1 & 7) == 0) {
          if ((uVar1 & 8) == 0) {
            if ((uVar1 & 0x1000) == 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((((uVar2 & 0x800) != 0 && (uVar9 == 0)) ||
                    (((uVar2 & 0x1000) != 0 && (uVar9 == 1)))) ||
                   (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                  ((((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                   (((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                     (((uVar2 & 0x10000) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
                uVar8 = 0x28;
                goto LAB_14000d9d1;
              }
            }
            else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 8) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                    ((((((((uVar2 & 0x800) != 0 && (uVar9 == 0)) ||
                         (((uVar2 & 0x1000) != 0 && (uVar9 == 1)))) ||
                        (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                       (((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
                      ((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                       (((uVar2 & 0x10000) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))) {
              uVar8 = 0x27;
LAB_14000d9d1:
              WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                        &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,(char)uVar1);
            }
LAB_14000da7c:
            *(undefined8 *)(param_2 + 0x70) = 0;
            *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
          }
          else {
            *(undefined4 *)(param_2 + 0x20) = 0;
            uVar5 = HWREG<unsigned_long>::Read
                              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18));
            *(ulonglong *)(param_2 + 0x70) = (ulonglong)(uVar5 & 0xffffff);
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar9 == 0)) ||
                 ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                  (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
                ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                 (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                   (((uVar1 & 0x10000) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
              WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                        &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,
                        (char)(uVar5 & 0xffffff));
            }
          }
        }
        else {
          *(undefined8 *)(param_2 + 0x70) = 0;
          *(undefined4 *)(param_2 + 0x20) = 0xc000000e;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((((((uVar1 & 0x800) != 0 && (uVar9 == 0)) ||
                ((((uVar1 & 0x1000) != 0 && (uVar9 == 1)) ||
                 ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))))) ||
               ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                (((uVar1 & 0x10000) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))) {
            uVar8 = 0x25;
            goto LAB_14000e819;
          }
        }
      }
      else {
        *(undefined8 *)(param_2 + 0x70) = 0;
        *(undefined4 *)(param_2 + 0x20) = 0xc0000120;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 & 0x800) != 0 && (uVar9 == 0)) ||
             ((((uVar1 & 0x1000) != 0 && (uVar9 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 & 0x10000) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          uVar8 = 0x23;
LAB_14000e819:
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                   &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
        }
      }
      goto LAB_14000d599;
    }
    if ((param_3 >> 1 & 1) != 0) {
      LOCK();
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffffffd;
      UNLOCK();
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
           ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))))) || (5 < uVar9)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                 &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
      }
      goto LAB_14000da7c;
    }
    if (((param_3 >> 2 & 1) == 0) || (*(int *)(param_2 + 100) != 1)) {
      if (((param_4 & 0x100) != 0) && (*(int *)(param_2 + 100) == 1)) {
LAB_14000dd38:
        local_res20[0] = 0;
        lVar6 = ControllerDoReadPrepare(param_1,param_2,local_res20);
        if (-1 < lVar6) {
          if (*(longlong *)(param_2 + 0x38) == *(longlong *)(param_2 + 0x40)) {
            if (param_2[0x78] == (PBC_REQUEST)0x1) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return;
              }
              uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
              if ((((uVar1 & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
                 ((((((uVar1 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
                    ((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) &&
                     (((uVar1 >> 0xd & 1) == 0 || (uVar9 != 2)))))) &&
                   ((((uVar1 >> 0xe & 1) == 0 || (uVar9 != 3)) &&
                    (((uVar1 >> 0xf & 1) == 0 || (uVar9 != 4)))))) &&
                  ((((uVar1 >> 0x10 & 1) == 0 || (uVar9 != 5)) && (uVar9 < 6))))))
              goto LAB_14000ecd2;
              uVar8 = 0x2f;
              goto LAB_14000de62;
            }
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                  (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
                 ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
              uVar8 = 0x30;
              goto LAB_14000dedf;
            }
          }
          else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                  ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                     ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                      (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
                    (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
                   (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                     (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
            uVar8 = 0x31;
LAB_14000dedf:
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                     &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
          }
          HWREG<unsigned_long>::Write
                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x38),
                     local_res20[0] - 1);
          LOCK();
          *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 4;
          UNLOCK();
          goto LAB_14000ecd2;
        }
        *(long *)(param_2 + 0x20) = lVar6;
        if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
            ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           ((((uVar1 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
            ((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) &&
             (((((uVar1 >> 0xd & 1) == 0 || (uVar9 != 2)) &&
               (((uVar1 >> 0xe & 1) == 0 || (uVar9 != 3)))) &&
              (((((uVar1 >> 0xf & 1) == 0 || (uVar9 != 4)) &&
                (((uVar1 >> 0x10 & 1) == 0 || (uVar9 != 5)))) && (uVar9 < 6))))))))))
        goto LAB_14000d599;
        uVar8 = 0x2e;
LAB_14000e98b:
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                  &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,(char)lVar6);
        goto LAB_14000d599;
      }
      if (((param_3 & 0x10000) != 0) && (*(int *)(param_2 + 100) == 2)) {
        LOCK();
        *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffeffff;
        UNLOCK();
        uVar5 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18));
        uVar12 = (ulonglong)(uVar5 & 0xffffff);
        *(ulonglong *)(param_2 + 0x70) = uVar12;
        lVar10 = *(longlong *)(param_2 + 0x38) - uVar12;
        if (lVar10 != 0) {
          if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
              ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
             (((((uVar1 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
               (((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) &&
                 (((uVar1 >> 0xd & 1) == 0 || (uVar9 != 2)))) &&
                (((uVar1 >> 0xe & 1) == 0 || (uVar9 != 3)))))) &&
              (((((uVar1 >> 0xf & 1) == 0 || (uVar9 != 4)) &&
                (((uVar1 >> 0x10 & 1) == 0 || (uVar9 != 5)))) && (uVar9 < 6))))))
          goto LAB_14000ec3a;
          uVar8 = 0x32;
LAB_14000ec1d:
          WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                     &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,(char)uVar12,
                     (char)lVar10);
          goto LAB_14000ec3a;
        }
        if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
            ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
           ((((((uVar1 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
              (((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)))) &&
             ((((uVar1 >> 0xd & 1) == 0 || (uVar9 != 2)) &&
              (((uVar1 >> 0xe & 1) == 0 || (uVar9 != 3)))))) &&
            (((((uVar1 >> 0xf & 1) == 0 || (uVar9 != 4)) &&
              (((uVar1 >> 0x10 & 1) == 0 || (uVar9 != 5)))) && (uVar9 < 6)))))) goto LAB_14000ecc4;
        uVar8 = 0x33;
LAB_14000ecac:
        uVar11 = (undefined1)uVar12;
        goto LAB_14000ecb1;
      }
      if ((((param_4 & 0x100) == 0) && ((param_3 >> 0xd & 1) == 0)) ||
         (*(int *)(param_2 + 100) != 2)) {
        if (((param_4 >> 4 & 1) == 0) || (lVar6 = DmaRxStart(param_1,param_2), -1 < lVar6)) {
          if (((param_4 & 1) == 0) || (lVar6 = DmaTxStart(param_1,param_2), -1 < lVar6)) {
            if ((((param_3 & 0x1000000) == 0) && ((param_4 >> 1 & 1) == 0)) ||
               (uVar4 = DmaTxComplete(param_1,param_2,0), uVar4 != '\x01')) {
LAB_14000e6ac:
              if (((((byte)(param_3 >> 0x1a) & 1) == 0) && ((param_4 >> 5 & 1) == 0)) ||
                 (uVar4 = DmaRxComplete(param_1,param_2,0), uVar4 != '\x01')) {
                if ((param_3 >> 9 & 1) == 0) goto LAB_14000ecd2;
                if (*(int *)(param_2 + 100) == 1) {
                  if (param_1[0x119] != (PBC_DEVICE)0x0) goto LAB_14000ecd2;
                  uVar12 = *(ulonglong *)(param_2 + 0x70);
                  if (*(longlong *)(param_2 + 0x38) - uVar12 != 0) {
                    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                       ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                        (((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                          ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                           (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
                         (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                           (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
                      WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                                 &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,(char)uVar12
                                 ,(char)(*(longlong *)(param_2 + 0x38) - uVar12));
                    }
                    lVar6 = ControllerDoRead(param_1,param_2);
                    if (lVar6 < 0) {
                      *(long *)(param_2 + 0x20) = lVar6;
                      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                         ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                          ((((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                             (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                            (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
                           (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                             (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
                        uVar8 = 0x40;
                        goto LAB_14000e98b;
                      }
                      goto LAB_14000d599;
                    }
                    uVar12 = *(ulonglong *)(param_2 + 0x70);
                    lVar10 = *(longlong *)(param_2 + 0x38) - uVar12;
                    if (lVar10 != 0) {
                      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                         ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                            (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
                           (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                          ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                           (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                             (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
                        uVar8 = 0x41;
                        goto LAB_14000ec1d;
                      }
                      goto LAB_14000ec3a;
                    }
                  }
                  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                        (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
                       (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                      (((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                        ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                         (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))))) {
                    uVar8 = 0x42;
                    goto LAB_14000ecac;
                  }
                  goto LAB_14000ecc4;
                }
                if (*(int *)(param_2 + 100) != 2) goto LAB_14000ecd2;
                if ((param_1[0x119] == (PBC_DEVICE)0x1) &&
                   (uVar4 = DmaCheckBusy(param_1,1), uVar4 == '\x01')) {
                  uVar4 = DmaTxComplete(param_1,param_2,3);
                  if (uVar4 == '\x01') {
                    _Var7 = DmaDataTransferred(param_1,1);
                    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
                       ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                          (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
                         (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                        ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                         (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                           (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
                      WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                                &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,(char)_Var7);
                    }
                    goto LAB_14000eb90;
                  }
                }
                else {
LAB_14000eb90:
                  uVar5 = HWREG<unsigned_long>::Read
                                    ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18))
                  ;
                  uVar12 = (ulonglong)(uVar5 & 0xffffff);
                  *(ulonglong *)(param_2 + 0x70) = uVar12;
                  lVar10 = *(longlong *)(param_2 + 0x38) - uVar12;
                  if (lVar10 == 0) {
                    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                          (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
                        ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                         (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                           (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
                      uVar8 = 0x45;
                      goto LAB_14000ecac;
                    }
                    goto LAB_14000ecc4;
                  }
                  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                       ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                        ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                         (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))))) ||
                      (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                        (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
                    uVar8 = 0x44;
                    goto LAB_14000ec1d;
                  }
                }
LAB_14000ec3a:
                *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
                goto LAB_14000d599;
              }
              _Var7 = DmaDataTransferred(param_1,0);
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                 ((4 < (byte)WPP_GLOBAL_Control[0x29] &&
                  (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                      (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
                     ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                      (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
                    ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                     (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))))) {
                WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                          &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,(char)_Var7);
              }
              *(__uint64 *)(param_2 + 0x70) = *(longlong *)(param_2 + 0x70) + _Var7;
              uVar4 = DmaCheckBusy(param_1,1);
              if ((uVar4 != '\0') && (uVar4 = DmaTxComplete(param_1,param_2,3), uVar4 != '\x01')) {
                *(undefined4 *)(param_2 + 0x20) = 0xc0000001;
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
                   ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                    (((((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                        (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                       (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
                      (((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)))) ||
                     ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
                  uVar8 = 0x3e;
                  goto LAB_14000e819;
                }
                goto LAB_14000d599;
              }
            }
            else {
              _Var7 = DmaDataTransferred(param_1,1);
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                  (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                   ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                    (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
                  ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                   (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                     (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
                WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                          &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,(char)_Var7);
              }
              *(__uint64 *)(param_2 + 0x70) = *(longlong *)(param_2 + 0x70) + _Var7;
              uVar4 = DmaCheckBusy(param_1,0);
              if (uVar4 != '\0') goto LAB_14000e6ac;
            }
            LOCK();
            *(undefined4 *)(param_1 + 0x68) = 0;
            UNLOCK();
            goto LAB_14000ecc4;
          }
          *(long *)(param_2 + 0x20) = lVar6;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
             ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                 (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
              ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
            uVar8 = 0x3b;
            goto LAB_14000e98b;
          }
        }
        else {
          *(long *)(param_2 + 0x20) = lVar6;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0 &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
             ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
              (((((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                  (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
                 (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
                (((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)))) ||
               ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
            uVar8 = 0x3a;
            goto LAB_14000e98b;
          }
        }
        goto LAB_14000d599;
      }
      LOCK();
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xffffdfff;
      UNLOCK();
      if (*(longlong *)(param_2 + 0x38) != *(longlong *)(param_2 + 0x40)) {
        lVar6 = ControllerDoWrite(param_1,param_2);
        if (lVar6 < 0) {
          *(long *)(param_2 + 0x20) = lVar6;
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
               (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
               ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))))) {
            uVar8 = 0x36;
            goto LAB_14000e98b;
          }
          goto LAB_14000d599;
        }
        if (*(longlong *)(param_2 + 0x38) == *(longlong *)(param_2 + 0x40)) {
          if (param_2[0x78] != (PBC_REQUEST)0x0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return;
            }
            uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
            if ((((uVar1 & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
               ((((uVar1 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
                (((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) &&
                  (((uVar1 >> 0xd & 1) == 0 || (uVar9 != 2)))) &&
                 (((((uVar1 >> 0xe & 1) == 0 || (uVar9 != 3)) &&
                   (((uVar1 >> 0xf & 1) == 0 || (uVar9 != 4)))) &&
                  ((((uVar1 >> 0x10 & 1) == 0 || (uVar9 != 5)) && (uVar9 < 6))))))))))
            goto LAB_14000ecd2;
            uVar8 = 0x37;
            goto LAB_14000de62;
          }
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                 (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
                (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
            uVar8 = 0x38;
            goto LAB_14000e45a;
          }
        }
        else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                 ((((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                    ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                     (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
                   ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                    (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))))) {
          uVar8 = 0x39;
LAB_14000e45a:
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                   &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
        }
        LOCK();
        *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 0x2000;
        UNLOCK();
        goto LAB_14000ecd2;
      }
      uVar5 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x18));
      uVar12 = (ulonglong)(uVar5 & 0xffffff);
      *(ulonglong *)(param_2 + 0x70) = uVar12;
      lVar10 = *(longlong *)(param_2 + 0x38) - uVar12;
      if (lVar10 != 0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          uVar8 = 0x34;
          goto LAB_14000ec1d;
        }
        goto LAB_14000ec3a;
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))) || (5 < uVar9)))) {
        uVar8 = 0x35;
        goto LAB_14000ecac;
      }
    }
    else {
      LOCK();
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffffffb;
      UNLOCK();
      lVar6 = ControllerDoRead(param_1,param_2);
      if (lVar6 < 0) {
        *(long *)(param_2 + 0x20) = lVar6;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          uVar8 = 0x2a;
          goto LAB_14000e98b;
        }
        goto LAB_14000d599;
      }
      if (*(longlong *)(param_2 + 0x38) != *(longlong *)(param_2 + 0x48)) {
        if (*(longlong *)(param_2 + 0x38) == *(longlong *)(param_2 + 0x40)) {
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
               (((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                 ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
                ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))))) || (5 < uVar9)))) {
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                     &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
          }
          goto LAB_14000ec3a;
        }
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
             (((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                   &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
        }
        goto LAB_14000dd38;
      }
      if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) == 0)) ||
          ((byte)WPP_GLOBAL_Control[0x29] < 4)) ||
         (((((uVar1 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
           ((((((uVar1 >> 0xc & 1) == 0 || (uVar9 != 1)) &&
              (((uVar1 >> 0xd & 1) == 0 || (uVar9 != 2)))) &&
             (((uVar1 >> 0xe & 1) == 0 || (uVar9 != 3)))) &&
            ((((uVar1 >> 0xf & 1) == 0 || (uVar9 != 4)) &&
             (((uVar1 >> 0x10 & 1) == 0 || (uVar9 != 5)))))))) && (uVar9 < 6)))) goto LAB_14000ecc4;
      uVar11 = (undefined1)*(undefined8 *)(param_2 + 0x70);
      uVar8 = 0x2b;
LAB_14000ecb1:
      WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9,uVar11);
    }
LAB_14000ecc4:
    uVar4 = '\0';
  }
  ControllerCompleteTransfer(param_1,param_2,uVar4);
LAB_14000ecd2:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
      (((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3))))
       || (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar9);
  }
  return;
}



===== ControllerUninitialize @ 14000ed70 =====

/* void __cdecl ControllerUninitialize(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerUninitialize(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))))
       ) || (5 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar2);
  }
  ControllerDisableInterrupts(param_1);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)) || (5 < uVar2)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar2);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)))) ||
          (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))
          ))) || (5 < uVar2)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_26c958b42dfb3dd3780c68ff776f3da4_Traceguids,uVar2);
    }
  }
  return;
}



===== McTemplateK0hqqxq @ 14000ef1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hqqxq(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined2 *local_68;
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
  local_60 = 2;
  local_58 = &param_5;
  local_50 = 4;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_40 = 4;
  local_30 = 8;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite(param_1,param_2,param_3,6,local_78);
  return;
}



===== WPP_SF_dDDD @ 14000efb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dP @ 14000f018 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_dPD @ 14000f064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dPD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_dPDDs @ 14000f0bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dPDDs(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,char *param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  
  if (param_8 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_8[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar1 = "NULL";
  if (param_8 != (char *)0x0) {
    pcVar1 = param_8;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,&param_7,4,pcVar1,
             lVar3,0);
  return;
}



===== WPP_SF_dPDs @ 14000f17c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dPDs(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,char *param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  
  if (param_7 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_7[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar1 = "NULL";
  if (param_7 != (char *)0x0) {
    pcVar1 = param_7;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,pcVar1,lVar3,0);
  return;
}



===== WPP_SF_dPP @ 14000f224 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dPP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_dss @ 14000f27c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dss(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               char *param_5,char *param_6)

{
  char *pcVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 local_res20 [2];
  
  if (param_6 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_6[lVar4] != '\0');
    lVar5 = lVar5 + 2;
  }
  lVar4 = -1;
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar4;
      lVar4 = lVar3 + 1;
    } while (param_5[lVar4] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar1 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar1 = param_6;
  }
  pcVar2 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar2 = param_5;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,pcVar2,lVar3,pcVar1,lVar5,0);
  return;
}



===== Read @ 14000f348 =====

/* public: unsigned long __cdecl HWREG<unsigned long>::Read(void) __ptr64 */

ulong __thiscall HWREG<unsigned_long>::Read(HWREG<unsigned_long> *this)

{
  return *(ulong *)this;
}



===== Write @ 14000f34c =====

/* public: unsigned long __cdecl HWREG<unsigned long>::Write(unsigned long) __ptr64 */

ulong __thiscall HWREG<unsigned_long>::Write(HWREG<unsigned_long> *this,ulong param_1)

{
  *(ulong *)this = param_1;
  LOCK();
  UNLOCK();
  return param_1;
}



===== GetDefaultSettings @ 14000f358 =====

/* void __cdecl GetDefaultSettings(struct PBC_DEVICE * __ptr64) */

void __cdecl GetDefaultSettings(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))))
       ) || (5 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar2);
  }
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),0x210
                     );
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),0x280)
  ;
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8),
                      0x1c);
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac),
                      0x1c);
  SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),1);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4),0x80);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8),0xa0);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),0x1c);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),0x1c);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),6);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200),0x1e);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc),0x50);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0),
                      0x28);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4),
                      0x28);
  SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),6);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc),0xf);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x28);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),0x14);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),0x14);
  SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),2);
  SetDefaultParameter(param_1,(ushort *)L"DynamicClockGating",(ulong *)(param_1 + 0xf0),1);
  SetDefaultParameter(param_1,(ushort *)L"MonitorOnIdleTimeout",(ulong *)(param_1 + 0xf4),2000);
  SetDefaultParameter(param_1,(ushort *)L"MonitorOffIdleTimeout",(ulong *)(param_1 + 0xf8),200);
  SetDefaultParameter(param_1,(ushort *)L"DmaInit",(ulong *)(param_1 + 0xfc),1);
  SetDefaultParameter(param_1,(ushort *)L"DmaThreshold",(ulong *)(param_1 + 0x100),0x20);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5))))
       || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar2);
  }
  return;
}



===== GetRegistrySettings @ 14000f724 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl GetRegistrySettings(struct PBC_DEVICE * __ptr64) */

void __cdecl GetRegistrySettings(PBC_DEVICE *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  WDFKEY__ *local_res8;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))))
       ) || (5 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar3);
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                    (WdfDriverGlobals,*WdfDriverGlobals,0x1f0000,0,&local_res8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)) || (5 < uVar3)))))))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar3,(char)iVar2);
    }
  }
  else {
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8)
              );
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac)
              );
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0)
              );
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4)
              );
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"DynamicClockGating",(ulong *)(param_1 + 0xf0));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"MonitorOnIdleTimeout",(ulong *)(param_1 + 0xf4));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"MonitorOffIdleTimeout",(ulong *)(param_1 + 0xf8));
    ReadRegistryKeyForController(param_1,local_res8,(ushort *)L"DmaInit",(ulong *)(param_1 + 0xfc));
    ReadRegistryKeyForController
              (param_1,local_res8,(ushort *)L"DmaThreshold",(ulong *)(param_1 + 0x100));
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals,local_res8);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))))
       ) || (5 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar3);
  }
  return;
}



===== OverrideDefaultsForHardware @ 14000fbd0 =====

/* void __cdecl OverrideDefaultsForHardware(struct PBC_DEVICE * __ptr64) */

void __cdecl OverrideDefaultsForHardware(PBC_DEVICE *param_1)

{
  uint uVar1;
  int iVar2;
  PBC_DEVICE *pPVar3;
  PBC_DEVICE *pPVar4;
  uint uVar5;
  PBC_DEVICE *pPVar6;
  PBC_DEVICE *pPVar7;
  PBC_DEVICE *pPVar8;
  PBC_DEVICE *pPVar9;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))
       ) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
  }
  iVar2 = *(int *)(param_1 + 0x44);
  if (((iVar2 == 2) && (3 < *(uint *)(param_1 + 0x40))) ||
     (((iVar2 == 5 && (3 < *(uint *)(param_1 + 0x40))) ||
      ((iVar2 == 0xd && (3 < *(uint *)(param_1 + 0x40))))))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
        (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) || (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4))))
         || ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"DmaInit",(ulong *)(param_1 + 0xfc),0);
  }
  if (((*(int *)(param_1 + 0x44) == 5) && (3 < *(uint *)(param_1 + 0x40))) ||
     ((*(int *)(param_1 + 0x44) == 0xd && (3 < *(uint *)(param_1 + 0x40))))) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"DynamicClockGating",(ulong *)(param_1 + 0xf0),0);
  }
  if ((*(int *)(param_1 + 0x44) == 2) && (0xef < *(uint *)(param_1 + 0x48))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),
                        0xc0);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),200)
    ;
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8),6
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac),6
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4),0x2a);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8),0x32);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200),0xc)
    ;
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc),0x14
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0),3
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4),3
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc),0xc);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x14);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),1);
  }
  iVar2 = *(int *)(param_1 + 0x44);
  if ((((iVar2 == 5) && (0xef < *(uint *)(param_1 + 0x48))) ||
      ((iVar2 == 0xd && (0xef < *(uint *)(param_1 + 0x48))))) ||
     ((iVar2 == 0xe && (0xef < *(uint *)(param_1 + 0x48))))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ))) || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                   (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),
                        0xc0);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),200)
    ;
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8),6
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac),6
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4),0x2a);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8),0x32);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200),0xc)
    ;
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc),0x14
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0),3
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4),3
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc),0xc);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x14);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),1);
  }
  iVar2 = *(int *)(param_1 + 0x44);
  if (((iVar2 == 4) && (*(uint *)(param_1 + 0x48) < 0xf0)) || (iVar2 == 8)) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        ((((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),
                        0x244);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),
                        0x2d0);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8),
                        0x2a);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac),
                        0x2a);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4),100);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8),0xd2);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),0x2a)
    ;
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),0x2a)
    ;
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200),0x23
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc),0x47
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0),
                        0x10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4),
                        0x10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),6);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc),6);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x1c);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),6);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),6);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),2);
    iVar2 = *(int *)(param_1 + 0x44);
  }
  pPVar9 = param_1 + 200;
  pPVar8 = param_1 + 0xb8;
  pPVar7 = param_1 + 0xdc;
  pPVar6 = param_1 + 0xcc;
  pPVar4 = param_1 + 0xa4;
  pPVar3 = param_1 + 0xb4;
  if (((iVar2 == 5) && (*(uint *)(param_1 + 0x48) < 0xf0)) ||
     ((iVar2 == 0xd && (*(uint *)(param_1 + 0x48) < 0xf0)))) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))
           ) || (((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
                  (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
                 (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))))) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),
                        1000);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),
                        0x44c);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8),
                        0x32);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac),
                        0x32);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4),0xfa);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8),0xfa);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),0x32)
    ;
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),0x32)
    ;
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200),0x46
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc),0x68
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0),
                        10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4),
                        10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),6);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc),0x1c);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x48);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),10);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),10);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),2);
  }
  if (((*(int *)(param_1 + 0x44) == 6) && (*(uint *)(param_1 + 0x48) < 0xf0)) ||
     ((*(int *)(param_1 + 0x44) == 0xe && (*(uint *)(param_1 + 0x48) < 0xf0)))) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
         || ((((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))) || (5 < uVar5)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),
                        0x3fc);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)pPVar4,0x460);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8),
                        0x32);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac),
                        0x32);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)pPVar3,0x101);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)pPVar8,0x101);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),0x32)
    ;
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),0x32)
    ;
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)pPVar9,0x5b);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)pPVar6,0x68);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0),
                        10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4),
                        10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),6);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)pPVar7,0x10);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x28);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),10);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),10);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),2);
  }
  if ((*(int *)(param_1 + 0x44) == 4) && (0xef < *(uint *)(param_1 + 0x48))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
         )) || (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                 (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
                ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"DynamicClockGating",(ulong *)(param_1 + 0xf0),0);
  }
  iVar2 = *(int *)(param_1 + 0x44);
  if ((((iVar2 == 9) && (*(uint *)(param_1 + 0x48) < 0xf0)) ||
      ((iVar2 == 10 && (*(uint *)(param_1 + 0x48) < 0xf0)))) ||
     (((iVar2 == 0xc && (*(uint *)(param_1 + 0x48) < 0xf0)) ||
      ((iVar2 == 0xb && (*(uint *)(param_1 + 0x48) < 0xf0)))))) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),
                        0x214);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)pPVar4,0x281);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)pPVar3,0x84);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)pPVar8,0xa1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)pPVar9,0x22);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)pPVar6,0x51);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)pPVar7,0x13);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x29);
  }
  if (((*(int *)(param_1 + 0x44) == 9) && (0xef < *(uint *)(param_1 + 0x48))) ||
     ((*(int *)(param_1 + 0x44) == 0xb && (0xef < *(uint *)(param_1 + 0x48))))) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
         || (((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
             (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),
                        0xc4);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)pPVar4,0xc9);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8),6
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac),6
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)pPVar3,0x2e);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)pPVar8,0x33);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)pPVar9,0x10);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)pPVar6,0x15);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0),3
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4),3
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)pPVar7,0x10);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),0x15);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),1);
  }
  if ((*(int *)(param_1 + 0x44) == 10) && (0xef < *(uint *)(param_1 + 0x48))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
         ((((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
          (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
    }
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xa0),
                        0x3e);
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xa4),0x43
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xa8),6
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xac),6
                       );
    SetDefaultParameter(param_1,(ushort *)L"StandardSpeed_SPK_Cnt",(ulong *)(param_1 + 0xb0),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xb4),0xe);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xb8),0xe);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xbc),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xc0),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeed_SPK_Cnt",(ulong *)(param_1 + 0xc4),1);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_HighCnt",(ulong *)(param_1 + 200),3);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SCL_LowCnt",(ulong *)(param_1 + 0xcc),6);
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_WrHoldCnt",(ulong *)(param_1 + 0xd0),3
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SDA_RdHoldCnt",(ulong *)(param_1 + 0xd4),3
                       );
    SetDefaultParameter(param_1,(ushort *)L"FastSpeedPlus_SPK_Cnt",(ulong *)(param_1 + 0xd8),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_HighCnt",(ulong *)(param_1 + 0xdc),3);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SCL_LowCnt",(ulong *)(param_1 + 0xe0),6);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_WrHoldCnt",(ulong *)(param_1 + 0xe4),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SDA_RdHoldCnt",(ulong *)(param_1 + 0xe8),1);
    SetDefaultParameter(param_1,(ushort *)L"HighSpeed_SPK_Cnt",(ulong *)(param_1 + 0xec),1);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar5);
  }
  return;
}



===== ReadRegistryKeyForController @ 1400113f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ReadRegistryKeyForController(struct PBC_DEVICE * __ptr64,struct WDFKEY__ *
   __ptr64,unsigned short * __ptr64,unsigned long * __ptr64) */

void __cdecl
ReadRegistryKeyForController(PBC_DEVICE *param_1,WDFKEY__ *param_2,ushort *param_3,ulong *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStackY_2a8 [32];
  ulong local_268 [2];
  undefined4 local_260 [2];
  undefined1 *local_258;
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2a8;
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x40);
  }
  local_258 = local_248;
  local_268[0] = 0;
  local_260[0] = 0x2000000;
  iVar2 = RtlUnicodeStringPrintf((_UNICODE_STRING *)local_260,(ushort *)&u__ws__u);
  if (iVar2 < 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)))
           ) || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
                 (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
         ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))
          ))) || (5 < uVar3)))) {
      WPP_SF_dSd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar3,(undefined *)param_3,
                 (char)iVar2);
    }
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,param_2,local_260,local_268);
  }
  if (-1 < iVar2) {
    *param_4 = local_268[0];
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
         (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))
           ) || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))
          ) || (5 < uVar3)))))) {
      WPP_SF_dSdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar3,(undefined *)param_3,
                  (char)local_268[0],(char)local_268[0]);
    }
  }
  return;
}



===== RtlUnicodeStringPrintf @ 1400115d0 =====

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



===== SetDefaultParameter @ 14001167c =====

/* void __cdecl SetDefaultParameter(struct PBC_DEVICE * __ptr64,unsigned short * __ptr64,unsigned
   long * __ptr64,unsigned long) */

void __cdecl SetDefaultParameter(PBC_DEVICE *param_1,ushort *param_2,ulong *param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  *param_3 = param_4;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5))))
       || (5 < uVar2)))))) {
    WPP_SF_dSdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_b4fd8a7a2fb53f9e7ff4c3343db01142_Traceguids,uVar2,(undefined *)param_2,
                (char)param_4,(char)param_4);
  }
  return;
}



===== WPP_SF_dSd @ 140011730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dSd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined *param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined *puVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (undefined *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_5 + lVar1 * 2) != 0);
    lVar1 = lVar1 * 2 + 2;
  }
  puVar2 = &u_NULL;
  if (param_5 != (undefined *)0x0) {
    puVar2 = param_5;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,puVar2,lVar1,&param_6,4,0);
  return;
}



===== WPP_SF_dSdD @ 1400117d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dSdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined *param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  undefined *puVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (undefined *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_5 + lVar1 * 2) != 0);
    lVar1 = lVar1 * 2 + 2;
  }
  puVar2 = &u_NULL;
  if (param_5 != (undefined *)0x0) {
    puVar2 = param_5;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,puVar2,lVar1,&param_6,4,&param_7,4,0);
  return;
}



===== ControllerFinishTransfer @ 140011884 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ControllerFinishTransfer(struct PBC_DEVICE * __ptr64) */

void __cdecl ControllerFinishTransfer(PBC_DEVICE *param_1)

{
  uint uVar1;
  longlong lVar2;
  uchar uVar3;
  ulong uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar6 & 0x800) != 0 && (uVar7 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
        ((((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)))))
        ) || ((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
              (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
  }
  uVar3 = IsI2CBusFree(param_1,"I2C Status (ControllerFinishTransfer)");
  if (((((uVar3 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) != 0)) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar6 & 0x800) != 0 && (uVar7 == 0)) ||
       (((((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2))))
        || (((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
      (((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5))))
       || (5 < uVar7)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
  }
  uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x70))
  ;
  if ((uVar4 & 1) != 0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar6 & 0x800) != 0 && (uVar7 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
        ((((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
         ((((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
          (((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
    }
    lVar2 = *(longlong *)(param_1 + 0x30);
    uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(lVar2 + 0x6c));
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(lVar2 + 0x6c),uVar4 | 2);
    uVar4 = HWREG<unsigned_long>::Read
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c));
    uVar6 = 0;
    uVar8 = uVar4 & 2;
    if (uVar8 != 0) {
      do {
        if (0x7f < uVar6) break;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
              (((uVar1 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
          WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                     &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7,(char)uVar6,(char)uVar8)
          ;
        }
        KeStallExecutionProcessor(100);
        uVar4 = HWREG<unsigned_long>::Read
                          ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c));
        uVar6 = uVar6 + 1;
        uVar8 = uVar4 & 2;
      } while (uVar8 != 0);
      if (((((uVar8 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
           ((((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
            (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
          ((((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
           (((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
             (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
      }
    }
    KeStallExecutionProcessor(100);
    uVar4 = HWREG<unsigned_long>::Read
                      ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x70));
    if ((((((uVar4 & 1) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
        ((((((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
           ((((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
          ((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
           (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))))) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
    }
    uVar3 = IsI2CBusFree(param_1,"I2C Status after USER_ABORT");
    if (((((uVar3 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
          ((((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)))
           ))))) ||
        (((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
    }
    (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
    uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4),uVar4 & 0xfffffffc);
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 4),uVar4 | 3);
    ControllerDisableInterrupts(param_1);
    (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
    uVar3 = IsI2CBusFree(param_1,"I2C Status after CONTROLLER_RESET");
    if (((((uVar3 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
          ((((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)))
           ))) || (((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
        (((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ) || (5 < uVar7)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
    }
  }
  HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x6c),0);
  uVar4 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c))
  ;
  uVar8 = 0;
  uVar6 = uVar4 & 1;
  if (uVar6 == 0) {
LAB_140011ec6:
    if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 5)) ||
       ((((((uVar6 >> 0xb & 1) == 0 || (uVar7 != 0)) && (((uVar6 >> 0xc & 1) == 0 || (uVar7 != 1))))
         && (((uVar6 >> 0xd & 1) == 0 || (uVar7 != 2)))) &&
        (((((uVar6 >> 0xe & 1) == 0 || (uVar7 != 3)) &&
          ((((uVar6 >> 0xf & 1) == 0 || (uVar7 != 4)) &&
           (((uVar6 >> 0x10 & 1) == 0 || (uVar7 != 5)))))) && (uVar7 < 6)))))) goto LAB_140011f42;
    uVar5 = 0x14;
  }
  else {
    do {
      if (9 < uVar8) break;
      KeStallExecutionProcessor(0x19);
      uVar4 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x30) + 0x9c));
      uVar8 = uVar8 + 1;
      uVar6 = uVar4 & 1;
    } while (uVar6 != 0);
    if (uVar6 == 0) goto LAB_140011ec6;
    if (((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 & 8) == 0)) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((((uVar6 >> 0xb & 1) == 0 || (uVar7 != 0)) && (((uVar6 >> 0xc & 1) == 0 || (uVar7 != 1))))
         && (((uVar6 >> 0xd & 1) == 0 || (uVar7 != 2)))) &&
        (((((uVar6 >> 0xe & 1) == 0 || (uVar7 != 3)) &&
          ((((uVar6 >> 0xf & 1) == 0 || (uVar7 != 4)) &&
           (((uVar6 >> 0x10 & 1) == 0 || (uVar7 != 5)))))) && (uVar7 < 6)))))) goto LAB_140011f42;
    uVar5 = 0x13;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
LAB_140011f42:
  *(undefined4 *)(param_1 + 0x104) = 0;
  uVar3 = IsI2CBusFree(param_1,"I2C Status after DISABLE");
  if (uVar3 == '\0') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar6 & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
        (((((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)) || (((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4))))
         || ((((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
        (((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
       ((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar7);
  }
  return;
}



===== DebugI2CLineState @ 14001206c =====

/* void __cdecl DebugI2CLineState(struct PBC_DEVICE * __ptr64,unsigned long,char * __ptr64) */

void __cdecl DebugI2CLineState(PBC_DEVICE *param_1,ulong param_2,char *param_3)

{
  uint uVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  
  uVar6 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x40);
  }
  bVar2 = (byte)(param_2 >> 0x18);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5))))
       || (5 < uVar6)))))) {
    pcVar4 = "SW1";
    pcVar3 = "SW1";
    if ((bVar2 >> 6 & 1) != 0) {
      pcVar3 = "SW0";
    }
    pcVar7 = "HW1";
    pcVar5 = "HW1";
    if ((bVar2 >> 3 & 1) != 0) {
      pcVar5 = "HW0";
    }
    if ((int)param_2 < 0) {
      pcVar5 = pcVar3;
    }
    if ((bVar2 >> 4 & 1) != 0) {
      pcVar4 = "SW0";
    }
    if ((bVar2 >> 1 & 1) != 0) {
      pcVar7 = "HW0";
    }
    if ((bVar2 >> 5 & 1) != 0) {
      pcVar7 = pcVar4;
    }
    WPP_SF_dsddss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                  &WPP_c7467980fc2234caaa904599566c545c_Traceguids,uVar6,param_3,bVar2 & 1,
                  bVar2 >> 2 & 1,pcVar7,pcVar5);
  }
  return;
}



===== IsI2CBusFree @ 140012204 =====

/* unsigned char __cdecl IsI2CBusFree(struct PBC_DEVICE * __ptr64,char * __ptr64) */

uchar __cdecl IsI2CBusFree(PBC_DEVICE *param_1,char *param_2)

{
  ulong uVar1;
  
  uVar1 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 8));
  DebugI2CLineState(param_1,uVar1,param_2);
  return (uVar1 & 0x5000000) == 0x5000000;
}



===== WPP_SF_dsddss @ 140012254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dsddss(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                  char *param_5,undefined1 param_6,undefined1 param_7,char *param_8,char *param_9)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 local_res20 [2];
  
  if (param_9 == (char *)0x0) {
    lVar7 = 5;
  }
  else {
    lVar6 = -1;
    do {
      lVar7 = lVar6;
      lVar6 = lVar7 + 1;
    } while (param_9[lVar6] != '\0');
    lVar7 = lVar7 + 2;
  }
  if (param_8 == (char *)0x0) {
    lVar6 = 5;
  }
  else {
    lVar4 = -1;
    do {
      lVar6 = lVar4;
      lVar4 = lVar6 + 1;
    } while (param_8[lVar4] != '\0');
    lVar6 = lVar6 + 2;
  }
  lVar4 = -1;
  if (param_5 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (param_5[lVar4] != '\0');
    lVar5 = lVar5 + 2;
  }
  pcVar2 = "NULL";
  if (param_9 != (char *)0x0) {
    pcVar2 = param_9;
  }
  pcVar1 = "NULL";
  if (param_8 != (char *)0x0) {
    pcVar1 = param_8;
  }
  pcVar3 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar3 = param_5;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,pcVar3,lVar5,&param_6,4,&param_7,4,pcVar1,
             lVar6,pcVar2,lVar7,0);
  return;
}



===== GetAcpiHardwareInstance @ 14001239c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetAcpiHardwareInstance(struct PBC_DEVICE * __ptr64,unsigned long * __ptr64) */

long __cdecl GetAcpiHardwareInstance(PBC_DEVICE *param_1,ulong *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  uint uVar5;
  long lVar6;
  undefined1 auStack_2c8 [32];
  undefined4 local_278;
  undefined4 local_274;
  longlong local_270;
  undefined8 local_268;
  int *local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined4 *local_248;
  undefined8 local_240;
  int local_238 [2];
  int local_230;
  short local_22c;
  ulong local_228;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2c8;
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5);
  }
  local_248 = &local_278;
  local_278 = 0x42696541;
  local_274 = 0x4449555f;
  local_250 = 1;
  local_240 = 8;
  memset(local_238,0,0x200);
  *param_2 = 0xff;
  local_260 = local_238;
  local_268 = 1;
  local_258 = 0x200;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)param_1);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_270 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5,(char)iVar2);
    }
    lVar6 = 0;
    goto LAB_140012823;
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
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 0x40) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
             (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
               (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
              ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                    &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5,(char)local_228);
        }
        goto LAB_140012823;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         ((((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
            ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) &&
             (((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)))))) &&
           ((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
            (((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)))))) &&
          ((((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)) && (uVar5 < 6)))))) goto LAB_140012823;
      uVar4 = 0x15;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         (((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
           ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) &&
            (((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)))))) &&
          (((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
            (((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)))) &&
           ((((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)) && (uVar5 < 6)))))))) goto LAB_140012823;
      uVar4 = 0x14;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       (((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1))))
        && ((((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)) &&
            (((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
              (((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)))) &&
             ((((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)) && (uVar5 < 6))))))))))
    goto LAB_140012823;
    uVar4 = 0x13;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5);
LAB_140012823:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
        || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5);
  }
  return lVar6;
}



===== GetAcpiHardwareRevision @ 1400128c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetAcpiHardwareRevision(struct PBC_DEVICE * __ptr64,unsigned long * __ptr64) */

long __cdecl GetAcpiHardwareRevision(PBC_DEVICE *param_1,ulong *param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  uint uVar5;
  long lVar6;
  undefined1 auStack_2c8 [32];
  undefined4 local_278;
  undefined4 local_274;
  longlong local_270;
  undefined8 local_268;
  int *local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined4 *local_248;
  undefined8 local_240;
  int local_238 [2];
  int local_230;
  short local_22c;
  ulong local_228;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2c8;
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5);
  }
  local_248 = &local_278;
  local_278 = 0x42696541;
  local_274 = 0x5652485f;
  local_250 = 1;
  local_240 = 8;
  memset(local_238,0,0x200);
  local_260 = local_238;
  local_268 = 1;
  local_258 = 0x200;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)param_1);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_270 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5,(char)iVar2);
    }
    lVar6 = 0;
    *param_2 = 0;
    goto LAB_140012d53;
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
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar1 & 0x40) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
             (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
            ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
             (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
               (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
              ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5,(char)local_228);
        }
        goto LAB_140012d53;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         ((((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
            ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) &&
             (((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)))))) &&
           ((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
            (((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)))))) &&
          ((((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)) && (uVar5 < 6)))))) goto LAB_140012d53;
      uVar4 = 0xe;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3febfff1;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         (((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) &&
           ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) &&
            (((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)))))) &&
          (((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
            (((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)))) &&
           ((((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)) && (uVar5 < 6)))))))) goto LAB_140012d53;
      uVar4 = 0xd;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3febfff1;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       (((((uVar1 >> 0xb & 1) == 0 || (uVar5 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1))))
        && ((((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)) &&
            (((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
              (((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)))) &&
             ((((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)) && (uVar5 < 6))))))))))
    goto LAB_140012d53;
    uVar4 = 0xc;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5);
LAB_140012d53:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
        || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5);
  }
  return lVar6;
}



===== GetAcpiSettings @ 140012dfc =====

/* void __cdecl GetAcpiSettings(struct PBC_DEVICE * __ptr64) */

void __cdecl GetAcpiSettings(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))))
       ) || (5 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar2);
  }
  ReadAcpiClockSettings
            (param_1,"SSCN",(ulong *)(param_1 + 0xa0),(ulong *)(param_1 + 0xa4),
             (ulong *)(param_1 + 0xa8),(ulong *)(param_1 + 0xac),(ulong *)(param_1 + 0xb0));
  ReadAcpiClockSettings
            (param_1,"FMCN",(ulong *)(param_1 + 0xb4),(ulong *)(param_1 + 0xb8),
             (ulong *)(param_1 + 0xbc),(ulong *)(param_1 + 0xc0),(ulong *)(param_1 + 0xc4));
  ReadAcpiClockSettings
            (param_1,"FPCN",(ulong *)(param_1 + 200),(ulong *)(param_1 + 0xcc),
             (ulong *)(param_1 + 0xd0),(ulong *)(param_1 + 0xd4),(ulong *)(param_1 + 0xd8));
  ReadAcpiClockSettings
            (param_1,"HSCN",(ulong *)(param_1 + 0xdc),(ulong *)(param_1 + 0xe0),
             (ulong *)(param_1 + 0xe4),(ulong *)(param_1 + 0xe8),(ulong *)(param_1 + 0xec));
  ReadAcpiParameter(param_1,"M0D3",(ulong *)(param_1 + 0xf8));
  ReadAcpiParameter(param_1,"M1D3",(ulong *)(param_1 + 0xf4));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5))))
       || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar2);
  }
  return;
}



===== ReadAcpiClockSettings @ 140013054 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ReadAcpiClockSettings(struct PBC_DEVICE * __ptr64,char * __ptr64,unsigned long *
   __ptr64,unsigned long * __ptr64,unsigned long * __ptr64,unsigned long * __ptr64,unsigned long *
   __ptr64) */

long __cdecl
ReadAcpiClockSettings
          (PBC_DEVICE *param_1,char *param_2,ulong *param_3,ulong *param_4,ulong *param_5,
          ulong *param_6,ulong *param_7)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined1 uVar7;
  ulong uVar8;
  undefined1 auStackY_338 [32];
  ulong local_2d8;
  short *local_2d0;
  uint local_2c8;
  undefined4 local_2c0;
  char local_2bc;
  char local_2bb;
  char local_2ba;
  char local_2b9;
  uint local_2b8;
  ulong *local_2b0;
  ulong *local_2a8;
  longlong local_2a0;
  ulong *local_298;
  ulong *local_290;
  ulong *local_288;
  undefined8 local_280;
  int *local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined4 *local_260;
  undefined8 local_258;
  int local_248 [2];
  uint local_240;
  short local_23c [250];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_338;
  local_2a8 = param_5;
  local_2b0 = param_6;
  uVar6 = 0xf0;
  local_298 = param_7;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x40);
  }
  local_2bc = *param_2;
  local_2bb = param_2[1];
  local_2ba = param_2[2];
  local_2b9 = param_2[3];
  local_260 = &local_2c0;
  local_2c0 = 0x42696541;
  local_268 = 1;
  local_258 = 8;
  local_290 = param_3;
  local_288 = param_4;
  memset(local_248,0,0x200);
  local_278 = local_248;
  local_280 = 1;
  local_270 = 0x200;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)param_1);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_2a0 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)) || (5 < uVar6)))))) {
      WPP_SF_dsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                 &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar6,param_2,(char)iVar2);
    }
    iVar2 = 0;
  }
  else if (local_248[0] == 0x426f6541) {
    local_2b8 = local_240;
    if (local_240 - 2 < 4) {
      local_2d8 = 0;
      local_2d0 = local_23c;
      local_2c8 = 0;
      if (local_240 != 0) {
        do {
          if (*local_2d0 != 0) {
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar6 == 1)) ||
                  (((uVar1 & 0x2000) != 0 && (uVar6 == 2)))))) ||
                ((((uVar1 & 0x4000) != 0 && (uVar6 == 3)) ||
                 (((((uVar1 & 0x8000) != 0 && (uVar6 == 4)) ||
                   (((uVar1 & 0x10000) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
              uVar5 = 0x1b;
              goto LAB_1400137f0;
            }
            break;
          }
          if (local_2c8 == 0) {
            local_2d8 = *(ulong *)(local_2d0 + 2);
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar6 == 1)) ||
                  ((((uVar1 & 0x2000) != 0 && (uVar6 == 2)) ||
                   (((uVar1 & 0x4000) != 0 && (uVar6 == 3)))))))) ||
                (((((uVar1 & 0x8000) != 0 && (uVar6 == 4)) ||
                  (((uVar1 & 0x10000) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))) {
              WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                          &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar6,param_2,
                          (char)local_2d8,(char)local_2d8);
            }
            if (local_2d8 == 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                  (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
                  (((((uVar1 & 0x1000) != 0 && (uVar6 == 1)) ||
                    ((((uVar1 & 0x2000) != 0 && (uVar6 == 2)) ||
                     (((uVar1 & 0x4000) != 0 && (uVar6 == 3)))))) ||
                   (((((uVar1 & 0x8000) != 0 && (uVar6 == 4)) ||
                     (((uVar1 & 0x10000) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
                uVar5 = 0x1d;
                goto LAB_140013231;
              }
              break;
            }
          }
          else if (local_2c8 == 1) {
            uVar8 = *(ulong *)(local_2d0 + 2);
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar6 == 1)) ||
                  (((uVar1 & 0x2000) != 0 && (uVar6 == 2)))))) ||
                ((((uVar1 & 0x4000) != 0 && (uVar6 == 3)) ||
                 (((((uVar1 & 0x8000) != 0 && (uVar6 == 4)) ||
                   (((uVar1 & 0x10000) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
              WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                          &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar6,param_2,(char)uVar8
                          ,(char)uVar8);
            }
            if (uVar8 == 0) {
              if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                  (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((((((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
                      (((uVar1 & 0x1000) != 0 && (uVar6 == 1)))) ||
                     (((uVar1 & 0x2000) != 0 && (uVar6 == 2)))) ||
                    (((uVar1 & 0x4000) != 0 && (uVar6 == 3)))) ||
                   ((((uVar1 & 0x8000) != 0 && (uVar6 == 4)) ||
                    (((uVar1 & 0x10000) != 0 && (uVar6 == 5)))))) || (5 < uVar6)))) {
                uVar5 = 0x1f;
                goto LAB_140013231;
              }
              break;
            }
            *local_290 = local_2d8;
            *local_288 = uVar8;
          }
          else if (local_2c8 == 2) {
            *local_2a8 = *(ulong *)(local_2d0 + 2);
            *local_2b0 = *(ulong *)(local_2d0 + 2);
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((((((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
                    (((uVar1 & 0x1000) != 0 && (uVar6 == 1)))) ||
                   (((uVar1 & 0x2000) != 0 && (uVar6 == 2)))) ||
                  (((uVar1 & 0x4000) != 0 && (uVar6 == 3)))) ||
                 ((((uVar1 & 0x8000) != 0 && (uVar6 == 4)) ||
                  (((uVar1 & 0x10000) != 0 && (uVar6 == 5)))))) || (5 < uVar6)))) {
              uVar5 = 0x20;
              uVar7 = (undefined1)*local_2a8;
LAB_1400134aa:
              WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                          &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar6,param_2,uVar7,uVar7
                         );
            }
          }
          else if (local_2c8 == 3) {
            uVar8 = *(ulong *)(local_2d0 + 2);
            *local_2b0 = uVar8;
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar6 == 1)) ||
                  (((uVar1 & 0x2000) != 0 && (uVar6 == 2)))))) ||
                ((((uVar1 & 0x4000) != 0 && (uVar6 == 3)) ||
                 (((((uVar1 & 0x8000) != 0 && (uVar6 == 4)) ||
                   (((uVar1 & 0x10000) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))))) {
              uVar5 = 0x21;
LAB_140013400:
              uVar7 = (undefined1)uVar8;
              goto LAB_1400134aa;
            }
          }
          else if (local_2c8 == 4) {
            uVar8 = *(ulong *)(local_2d0 + 2);
            *local_298 = uVar8;
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
                 ((((uVar1 & 0x1000) != 0 && (uVar6 == 1)) ||
                  ((((uVar1 & 0x2000) != 0 && (uVar6 == 2)) ||
                   (((uVar1 & 0x4000) != 0 && (uVar6 == 3)))))))) ||
                (((((uVar1 & 0x8000) != 0 && (uVar6 == 4)) ||
                  (((uVar1 & 0x10000) != 0 && (uVar6 == 5)))) || (5 < uVar6)))))) {
              uVar5 = 0x22;
              goto LAB_140013400;
            }
          }
          if ((ushort)local_2d0[1] < 4) {
            uVar4 = 4;
          }
          else {
            uVar4 = (ulonglong)(ushort)local_2d0[1];
          }
          local_2d0 = (short *)((longlong)local_2d0 + uVar4 + 4);
          local_2c8 = local_2c8 + 1;
        } while (local_2c8 < local_2b8);
      }
    }
    else if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
            ((((uVar1 & 0x800) != 0 && (uVar6 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)) ||
              ((((((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)) ||
                 (((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)))) ||
                ((((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)))))) || (5 < uVar6)))))))) {
      uVar5 = 0x1a;
      local_2c8 = local_240;
LAB_1400137f0:
      WPP_SF_dsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                 &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar6,param_2,(char)local_2c8);
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 & 0x800) != 0 && (uVar6 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar6 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar6 == 2)))) ||
        (((((uVar1 >> 0xe & 1) != 0 && (uVar6 == 3)) || (((uVar1 >> 0xf & 1) != 0 && (uVar6 == 4))))
         || ((((uVar1 >> 0x10 & 1) != 0 && (uVar6 == 5)) || (5 < uVar6)))))))) {
      uVar5 = 0x19;
LAB_140013231:
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar6,param_2);
    }
  }
  return iVar2;
}



===== ReadAcpiParameter @ 140013940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ReadAcpiParameter(struct PBC_DEVICE * __ptr64,char * __ptr64,unsigned long *
   __ptr64) */

long __cdecl ReadAcpiParameter(PBC_DEVICE *param_1,char *param_2,ulong *param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined1 auStackY_2c8 [32];
  undefined4 local_278;
  char local_274;
  char local_273;
  char local_272;
  char local_271;
  longlong local_270;
  undefined8 local_268;
  int *local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined4 *local_248;
  undefined8 local_240;
  int local_238 [2];
  int local_230;
  short local_22c;
  ulong local_228;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2c8;
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x40);
  }
  local_274 = *param_2;
  local_273 = param_2[1];
  local_272 = param_2[2];
  local_271 = param_2[3];
  local_248 = &local_278;
  local_278 = 0x42696541;
  local_250 = 1;
  local_240 = 8;
  memset(local_238,0,0x200);
  local_260 = local_238;
  local_268 = 1;
  local_258 = 0x200;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)param_1);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar3,0,0x32c004);
  if ((iVar2 < 0) || (local_270 == 0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_dsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                 &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5,param_2,(char)iVar2);
    }
    return 0;
  }
  if (local_238[0] == 0x426f6541) {
    if (local_230 == 1) {
      if (local_22c == 0) {
        *param_3 = local_228;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar2;
        }
        uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((uVar1 & 0x40) == 0) {
          return iVar2;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
          return iVar2;
        }
        if (((((((uVar1 >> 0xb & 1) == 0) || (uVar5 != 0)) &&
              (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)))) &&
             ((((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)) &&
              (((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)))))) &&
            ((((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)) &&
             (((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)))))) && (uVar5 < 6)) {
          return iVar2;
        }
        WPP_SF_dsdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                    &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5,param_2,(char)local_228,
                    (char)local_228);
        return iVar2;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((uVar1 & 0x40) == 0) {
        return iVar2;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar2;
      }
      if (((((uVar1 >> 0xb & 1) == 0) || (uVar5 != 0)) &&
          ((((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)) && (((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)))
           ))) && ((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
                   (((((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)) &&
                     (((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)))) && (uVar5 < 6)))))) {
        return iVar2;
      }
      uVar4 = 0x26;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((uVar1 & 0x40) == 0) {
        return iVar2;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar2;
      }
      if ((((((uVar1 >> 0xb & 1) == 0) || (uVar5 != 0)) &&
           (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1)))) &&
          ((((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)) && (((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)))
           ))) && (((((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)) &&
                    (((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)))) && (uVar5 < 6)))) {
        return iVar2;
      }
      uVar4 = 0x25;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((uVar1 & 0x40) == 0) {
      return iVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return iVar2;
    }
    if (((((uVar1 >> 0xb & 1) == 0) || (uVar5 != 0)) && (((uVar1 >> 0xc & 1) == 0 || (uVar5 != 1))))
       && ((((uVar1 >> 0xd & 1) == 0 || (uVar5 != 2)) &&
           (((((uVar1 >> 0xe & 1) == 0 || (uVar5 != 3)) &&
             ((((uVar1 >> 0xf & 1) == 0 || (uVar5 != 4)) &&
              (((uVar1 >> 0x10 & 1) == 0 || (uVar5 != 5)))))) && (uVar5 < 6)))))) {
      return iVar2;
    }
    uVar4 = 0x24;
  }
  WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
            &WPP_2300356acfa130bc7ae941ff71514f08_Traceguids,uVar5,param_2);
  return iVar2;
}



===== WPP_SF_ds @ 140013d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ds(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              char *param_5)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar1 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar1 = param_5;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,pcVar1,lVar3,0);
  return;
}



===== WPP_SF_dsd @ 140013e14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dsd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               char *param_5,undefined1 param_6)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar1 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar1 = param_5;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,pcVar1,lVar3,&param_6,4,0);
  return;
}



===== WPP_SF_dsdD @ 140013eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dsdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                char *param_5,undefined1 param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar1 = "NULL";
  if (param_5 != (char *)0x0) {
    pcVar1 = param_5;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,pcVar1,lVar3,&param_6,4,&param_7,4,0);
  return;
}



===== CheckSupportedHardware @ 140013f5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CheckSupportedHardware(struct WDFDEVICE__ * __ptr64) */

long __cdecl CheckSupportedHardware(WDFDEVICE__ *param_1)

{
  int iVar1;
  long lVar2;
  longlong lVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined1 auStackY_78 [32];
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_78;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  local_44 = 0xff;
  local_40 = 0xff;
  local_48 = 0xff;
  local_3c = 0xff;
  lVar2 = GetHardwareVersion(param_1,(HW_PARAMETERS *)&local_48);
  if (lVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400147d9;
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar6 = 0xf;
  }
  else {
    if (local_40 != 0xff) {
LAB_1400140db:
      if (local_48 == 0xff) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                   &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff);
        }
        lVar2 = GetHardwareInstance(param_1,(HW_PARAMETERS *)&local_48);
        if (lVar2 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar2;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400147d9;
          uVar6 = 0x13;
          goto LAB_1400140d2;
        }
      }
      *(undefined4 *)(lVar3 + 0x44) = local_44;
      iVar1 = *(int *)(lVar3 + 0x44);
      *(int *)(lVar3 + 0x48) = local_40;
      *(int *)(lVar3 + 0x40) = local_48;
      *(int *)(lVar3 + 0x4c) = local_3c;
      if (iVar1 == 2) {
        if (*(uint *)(lVar3 + 0x48) < 0xf0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar2;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
          pcVar4 = "PCI";
          if (local_3c == 0) {
            pcVar4 = "ACPI";
          }
          uVar6 = 0x15;
        }
        else {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar2;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
          pcVar4 = "PCI";
          if (local_3c == 0) {
            pcVar4 = "ACPI";
          }
          uVar6 = 0x14;
        }
      }
      else if (iVar1 == 3) {
        if (0xef < *(uint *)(lVar3 + 0x48)) goto LAB_1400147d3;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar2;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
        pcVar4 = "PCI";
        if (local_3c == 0) {
          pcVar4 = "ACPI";
        }
        uVar6 = 0x16;
      }
      else if (iVar1 == 4) {
        if (*(uint *)(lVar3 + 0x48) < 0xf0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar2;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
          pcVar4 = "PCI";
          if (local_3c == 0) {
            pcVar4 = "ACPI";
          }
          uVar6 = 0x17;
        }
        else {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar2;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
          pcVar4 = "PCI";
          if (local_3c == 0) {
            pcVar4 = "ACPI";
          }
          uVar6 = 0x18;
        }
      }
      else if (iVar1 == 5) {
        if (*(uint *)(lVar3 + 0x48) < 0xf0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar2;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
          pcVar4 = "PCI";
          if (local_3c == 0) {
            pcVar4 = "ACPI";
          }
          uVar6 = 0x19;
        }
        else {
LAB_1400143b2:
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar2;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
          pcVar4 = "PCI";
          if (local_3c == 0) {
            pcVar4 = "ACPI";
          }
          uVar6 = 0x1b;
        }
      }
      else if (iVar1 == 6) {
        if (0xef < *(uint *)(lVar3 + 0x48)) {
LAB_1400147d3:
          lVar2 = -0x3ffffda0;
          goto LAB_1400147d9;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar2;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
        pcVar4 = "PCI";
        if (local_3c == 0) {
          pcVar4 = "ACPI";
        }
        uVar6 = 0x1a;
      }
      else {
        if (iVar1 == 5) {
          if (0xef < *(uint *)(lVar3 + 0x48)) goto LAB_1400143b2;
          goto LAB_1400147d3;
        }
        if (iVar1 == 0xd) {
          if (*(uint *)(lVar3 + 0x48) < 0xf0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return lVar2;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
            pcVar4 = "PCI";
            if (local_3c == 0) {
              pcVar4 = "ACPI";
            }
            uVar6 = 0x1c;
          }
          else {
LAB_1400144a8:
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return lVar2;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
            pcVar4 = "PCI";
            if (local_3c == 0) {
              pcVar4 = "ACPI";
            }
            uVar6 = 0x1e;
          }
        }
        else {
          if (iVar1 != 0xe) {
            if (iVar1 == 0xd) {
              if (0xef < *(uint *)(lVar3 + 0x48)) goto LAB_1400144a8;
            }
            else {
              if (iVar1 != 0xe) {
                if (iVar1 == 7) {
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                    return lVar2;
                  }
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                  pcVar4 = "PCI";
                  if (local_3c == 0) {
                    pcVar4 = "ACPI";
                  }
                  uVar6 = 0x20;
                }
                else if (iVar1 == 8) {
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                    return lVar2;
                  }
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                  pcVar4 = "PCI";
                  if (local_3c == 0) {
                    pcVar4 = "ACPI";
                  }
                  uVar6 = 0x21;
                }
                else if (iVar1 == 9) {
                  if (*(uint *)(lVar3 + 0x48) < 0xf0) {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return lVar2;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                    pcVar4 = "PCI";
                    if (local_3c == 0) {
                      pcVar4 = "ACPI";
                    }
                    uVar6 = 0x22;
                  }
                  else {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return lVar2;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                    pcVar4 = "PCI";
                    if (local_3c == 0) {
                      pcVar4 = "ACPI";
                    }
                    uVar6 = 0x23;
                  }
                }
                else if (iVar1 == 10) {
                  if (*(uint *)(lVar3 + 0x48) < 0xf0) {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return lVar2;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                    pcVar4 = "PCI";
                    if (local_3c == 0) {
                      pcVar4 = "ACPI";
                    }
                    uVar6 = 0x24;
                  }
                  else {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return lVar2;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                    pcVar4 = "PCI";
                    if (local_3c == 0) {
                      pcVar4 = "ACPI";
                    }
                    uVar6 = 0x25;
                  }
                }
                else if (iVar1 == 0xb) {
                  if (*(uint *)(lVar3 + 0x48) < 0xf0) {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return lVar2;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                    pcVar4 = "PCI";
                    if (local_3c == 0) {
                      pcVar4 = "ACPI";
                    }
                    uVar6 = 0x27;
                  }
                  else {
                    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                      return lVar2;
                    }
                    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                    pcVar4 = "PCI";
                    if (local_3c == 0) {
                      pcVar4 = "ACPI";
                    }
                    uVar6 = 0x26;
                  }
                }
                else {
                  if ((iVar1 != 0xc) || (0xef < *(uint *)(lVar3 + 0x48))) goto LAB_1400147d3;
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                    return lVar2;
                  }
                  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
                  pcVar4 = "PCI";
                  if (local_3c == 0) {
                    pcVar4 = "ACPI";
                  }
                  uVar6 = 0x28;
                }
                goto LAB_1400147bd;
              }
              if (0xef < *(uint *)(lVar3 + 0x48)) goto LAB_1400144fa;
            }
            goto LAB_1400147d3;
          }
          if (*(uint *)(lVar3 + 0x48) < 0xf0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return lVar2;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
            pcVar4 = "PCI";
            if (local_3c == 0) {
              pcVar4 = "ACPI";
            }
            uVar6 = 0x1d;
          }
          else {
LAB_1400144fa:
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return lVar2;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400147d9;
            pcVar4 = "PCI";
            if (local_3c == 0) {
              pcVar4 = "ACPI";
            }
            uVar6 = 0x1f;
          }
        }
      }
LAB_1400147bd:
      WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff,pcVar4);
      goto LAB_1400147d9;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff);
    }
    lVar2 = GetHardwareRevision(param_1,(HW_PARAMETERS *)&local_48);
    if (-1 < lVar2) goto LAB_1400140db;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400147d9;
    uVar6 = 0x11;
LAB_1400140d2:
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  WPP_SF_d(uVar5,uVar6,&WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff);
LAB_1400147d9:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff);
  }
  return lVar2;
}



===== GetHardwareInstance @ 140014838 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl GetHardwareInstance(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareInstance(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  long lVar1;
  PBC_DEVICE *pPVar2;
  
  pPVar2 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (*(int *)(param_2 + 0xc) == 0) {
    lVar1 = GetAcpiHardwareInstance(pPVar2,(ulong *)param_2);
  }
  else {
    lVar1 = 0;
    if (*(int *)(param_2 + 0xc) == 1) {
      lVar1 = -0x3fffffff;
    }
  }
  return lVar1;
}



===== GetHardwareRevision @ 14001489c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl GetHardwareRevision(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareRevision(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  long lVar1;
  PBC_DEVICE *pPVar2;
  
  pPVar2 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (*(int *)(param_2 + 0xc) == 0) {
    lVar1 = GetAcpiHardwareRevision(pPVar2,(ulong *)(param_2 + 8));
  }
  else {
    if (*(int *)(param_2 + 0xc) != 1) {
      return 0;
    }
    lVar1 = GetPciHardwareRevision(pPVar2,(ulong *)(param_2 + 8));
  }
  return lVar1;
}



===== GetHardwareVersion @ 140014908 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl GetHardwareVersion(struct WDFDEVICE__ * __ptr64,struct HW_PARAMETERS * __ptr64) */

long __cdecl GetHardwareVersion(WDFDEVICE__ *param_1,HW_PARAMETERS *param_2)

{
  wchar_t *pwVar1;
  wchar_t *_Str2;
  int iVar2;
  int iVar3;
  wchar_t *_Src;
  size_t sVar4;
  ulonglong uVar5;
  uint uVar6;
  size_t _MaxCount;
  undefined **ppuVar7;
  undefined1 auStackY_d98 [32];
  undefined8 local_d58;
  ulonglong local_d50;
  WDFDEVICE__ *local_d48;
  undefined4 local_d40 [6];
  undefined4 local_d28;
  undefined4 local_d24;
  WDFDEVICE__ *local_d20;
  undefined4 local_d08 [2];
  undefined *local_d00;
  undefined8 local_cf8;
  undefined4 local_cf0 [4];
  undefined1 *local_ce0;
  undefined4 local_cd8;
  undefined8 local_cd4;
  undefined4 local_cc8;
  undefined1 *local_cc0;
  undefined4 local_cb8;
  undefined8 local_cb4;
  undefined4 local_ca8;
  undefined1 *local_ca0;
  undefined4 local_c98;
  undefined8 local_c94;
  undefined4 local_c88;
  undefined1 *local_c80;
  undefined4 local_c78;
  undefined8 local_c74;
  undefined4 local_c68;
  wchar_t *local_c60;
  undefined4 local_c58;
  undefined8 local_c54;
  undefined4 local_c48;
  undefined1 *local_c40;
  undefined8 local_c38;
  undefined4 local_c30;
  undefined4 local_c28;
  undefined1 *local_c20;
  undefined4 local_c18;
  undefined4 local_c14;
  undefined4 local_c10;
  undefined4 local_c08;
  undefined1 *local_c00;
  undefined4 local_bf8;
  undefined4 local_bf4;
  undefined4 local_bf0;
  undefined4 local_be8;
  undefined1 *local_be0;
  undefined4 local_bd8;
  undefined4 local_bd4;
  undefined4 local_bd0;
  undefined4 local_bc8;
  undefined1 *local_bc0;
  undefined4 local_bb8;
  undefined4 local_bb4;
  undefined4 local_bb0;
  undefined4 local_ba8;
  undefined1 *local_ba0;
  undefined4 local_b98;
  undefined4 local_b94;
  undefined4 local_b90;
  undefined4 local_b88;
  undefined1 *local_b80;
  undefined8 local_b78;
  undefined4 local_b70;
  undefined4 local_b68;
  undefined1 *local_b60;
  undefined4 local_b58;
  undefined4 local_b54;
  undefined4 local_b50;
  undefined4 local_b48;
  undefined1 *local_b40;
  undefined4 local_b38;
  undefined4 local_b34;
  undefined4 local_b30;
  undefined4 local_b28;
  undefined1 *local_b20;
  undefined4 local_b18;
  undefined4 local_b14;
  undefined4 local_b10;
  undefined4 local_b08;
  undefined1 *local_b00;
  undefined4 local_af8;
  undefined4 local_af4;
  undefined4 local_af0;
  undefined4 local_ae8;
  undefined1 *local_ae0;
  undefined4 local_ad8;
  undefined4 local_ad4;
  undefined4 local_ad0;
  undefined4 local_ac8;
  undefined1 *local_ac0;
  undefined4 local_ab8;
  undefined4 local_ab4;
  undefined4 local_ab0;
  undefined4 local_aa8;
  undefined1 *local_aa0;
  undefined4 local_a98;
  undefined4 local_a94;
  undefined4 local_a90;
  undefined4 local_a88;
  undefined1 *local_a80;
  undefined8 local_a78;
  undefined4 local_a70;
  undefined4 local_a68;
  undefined1 *local_a60;
  undefined4 local_a58;
  undefined4 local_a54;
  undefined4 local_a50;
  undefined4 local_a48;
  undefined1 *local_a40;
  undefined4 local_a38;
  undefined4 local_a34;
  undefined4 local_a30;
  undefined4 local_a28;
  undefined1 *local_a20;
  undefined4 local_a18;
  undefined4 local_a14;
  undefined4 local_a10;
  undefined4 local_a08;
  undefined1 *local_a00;
  undefined4 local_9f8;
  undefined4 local_9f4;
  undefined4 local_9f0;
  undefined4 local_9e8;
  undefined1 *local_9e0;
  undefined4 local_9d8;
  undefined4 local_9d4;
  undefined4 local_9d0;
  undefined4 local_9c8;
  undefined1 *local_9c0;
  undefined4 local_9b8;
  undefined4 local_9b4;
  undefined4 local_9b0;
  undefined4 local_9a8;
  undefined1 *local_9a0;
  undefined4 local_998;
  undefined4 local_994;
  undefined4 local_990;
  undefined4 local_988;
  undefined1 *local_980;
  undefined8 local_978;
  undefined4 local_970;
  undefined4 local_968;
  undefined1 *local_960;
  undefined4 local_958;
  undefined4 local_954;
  undefined4 local_950;
  undefined4 local_948;
  undefined1 *local_940;
  undefined4 local_938;
  undefined4 local_934;
  undefined4 local_930;
  undefined4 local_928;
  undefined1 *local_920;
  undefined4 local_918;
  undefined4 local_914;
  undefined4 local_910;
  undefined4 local_908;
  undefined1 *local_900;
  undefined4 local_8f8;
  undefined4 local_8f4;
  undefined4 local_8f0;
  undefined4 local_8e8;
  undefined1 *local_8e0;
  undefined4 local_8d8;
  undefined4 local_8d4;
  undefined4 local_8d0;
  undefined4 local_8c8;
  undefined1 *local_8c0;
  undefined4 local_8b8;
  undefined4 local_8b4;
  undefined4 local_8b0;
  undefined4 local_8a8;
  undefined1 *local_8a0;
  undefined4 local_898;
  undefined4 local_894;
  undefined4 local_890;
  undefined4 local_888;
  undefined1 *local_880;
  undefined8 local_878;
  undefined4 local_870;
  undefined4 local_868;
  undefined1 *local_860;
  undefined4 local_858;
  undefined8 local_854;
  undefined4 local_848;
  undefined1 *local_840;
  undefined4 local_838;
  undefined8 local_834;
  undefined4 local_828;
  undefined1 *local_820;
  undefined4 local_818;
  undefined8 local_814;
  undefined4 local_808;
  undefined1 *local_800;
  undefined8 local_7f8;
  undefined4 local_7f0;
  undefined4 local_7e8;
  undefined1 *local_7e0;
  undefined4 local_7d8;
  undefined4 local_7d4;
  undefined4 local_7d0;
  undefined4 local_7c8;
  undefined1 *local_7c0;
  undefined4 local_7b8;
  undefined4 local_7b4;
  undefined4 local_7b0;
  undefined4 local_7a8;
  undefined1 *local_7a0;
  undefined4 local_798;
  undefined4 local_794;
  undefined4 local_790;
  undefined4 local_788;
  undefined1 *local_780;
  undefined8 local_778;
  undefined4 local_770;
  undefined4 local_768;
  undefined1 *local_760;
  undefined4 local_758;
  undefined4 local_754;
  undefined4 local_750;
  undefined4 local_748;
  undefined1 *local_740;
  undefined4 local_738;
  undefined4 local_734;
  undefined4 local_730;
  undefined4 local_728;
  undefined1 *local_720;
  undefined4 local_718;
  undefined4 local_714;
  undefined4 local_710;
  undefined4 local_708;
  undefined1 *local_700;
  undefined4 local_6f8;
  undefined4 local_6f4;
  undefined4 local_6f0;
  undefined4 local_6e8;
  undefined1 *local_6e0;
  undefined4 local_6d8;
  undefined4 local_6d4;
  undefined4 local_6d0;
  undefined4 local_6c8;
  undefined1 *local_6c0;
  undefined8 local_6b8;
  undefined4 local_6b0;
  undefined4 local_6a8;
  undefined1 *local_6a0;
  undefined4 local_698;
  undefined4 local_694;
  undefined4 local_690;
  undefined4 local_688;
  undefined1 *local_680;
  undefined4 local_678;
  undefined4 local_674;
  undefined4 local_670;
  undefined4 local_668;
  undefined1 *local_660;
  undefined4 local_658;
  undefined4 local_654;
  undefined4 local_650;
  undefined4 local_648;
  undefined1 *local_640;
  undefined8 local_638;
  undefined4 local_630;
  undefined4 local_628;
  undefined1 *local_620;
  undefined4 local_618;
  undefined4 local_614;
  undefined4 local_610;
  undefined4 local_608;
  undefined1 *local_600;
  undefined4 local_5f8;
  undefined4 local_5f4;
  undefined4 local_5f0;
  undefined4 local_5e8;
  undefined1 *local_5e0;
  undefined4 local_5d8;
  undefined4 local_5d4;
  undefined4 local_5d0;
  undefined4 local_5c8;
  undefined1 *local_5c0;
  undefined4 local_5b8;
  undefined4 local_5b4;
  undefined4 local_5b0;
  undefined4 local_5a8;
  undefined1 *local_5a0;
  undefined4 local_598;
  undefined4 local_594;
  undefined4 local_590;
  undefined4 local_588;
  undefined1 *local_580;
  undefined8 local_578;
  undefined4 local_570;
  undefined4 local_568;
  undefined1 *local_560;
  undefined4 local_558;
  undefined4 local_554;
  undefined4 local_550;
  undefined4 local_548;
  undefined1 *local_540;
  undefined4 local_538;
  undefined4 local_534;
  undefined4 local_530;
  undefined4 local_528;
  undefined1 *local_520;
  undefined4 local_518;
  undefined4 local_514;
  undefined4 local_510;
  undefined4 local_508;
  undefined1 *local_500;
  undefined8 local_4f8;
  undefined4 local_4f0;
  undefined4 local_4e8;
  undefined1 *local_4e0;
  undefined4 local_4d8;
  undefined4 local_4d4;
  undefined4 local_4d0;
  undefined4 local_4c8;
  undefined1 *local_4c0;
  undefined4 local_4b8;
  undefined4 local_4b4;
  undefined4 local_4b0;
  undefined4 local_4a8;
  undefined1 *local_4a0;
  undefined4 local_498;
  undefined4 local_494;
  undefined4 local_490;
  undefined4 local_488;
  undefined1 *local_480;
  undefined8 local_478;
  undefined4 local_470;
  undefined4 local_468;
  undefined1 *local_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined4 local_448;
  undefined1 *local_440;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_428;
  undefined1 *local_420;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_408;
  undefined1 *local_400;
  undefined4 local_3f8;
  undefined4 local_3f4;
  undefined4 local_3f0;
  undefined4 local_3e8;
  undefined1 *local_3e0;
  undefined4 local_3d8;
  undefined4 local_3d4;
  undefined4 local_3d0;
  undefined4 local_3c8;
  undefined1 *local_3c0;
  undefined4 local_3b8;
  undefined4 local_3b4;
  undefined4 local_3b0;
  undefined4 local_3a8;
  undefined1 *local_3a0;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined4 local_388;
  undefined1 *local_380;
  undefined8 local_378;
  undefined4 local_370;
  undefined4 local_368;
  undefined1 *local_360;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_348;
  undefined1 *local_340;
  undefined4 local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined4 local_328;
  undefined1 *local_320;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_308;
  undefined1 *local_300;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  undefined4 local_2e8;
  undefined1 *local_2e0;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2c8;
  undefined1 *local_2c0;
  undefined8 local_2b8;
  undefined4 local_2b0;
  undefined4 local_2a8;
  undefined1 *local_2a0;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_288;
  undefined1 *local_280;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270;
  undefined4 local_268;
  undefined1 *local_260;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_248;
  undefined1 *local_240;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_228;
  undefined1 *local_220;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_208;
  undefined1 *local_200;
  undefined8 local_1f8;
  undefined4 local_1f0;
  undefined4 local_1e8;
  undefined1 *local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1c8;
  undefined1 *local_1c0;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1a8;
  undefined1 *local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_188;
  undefined1 *local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_168;
  undefined1 *local_160;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_148;
  undefined1 *local_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_128;
  undefined1 *local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_108;
  undefined1 *local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined1 *local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined1 *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined1 *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_88;
  undefined1 *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_68;
  undefined1 *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d98;
  local_d48 = param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff);
  }
  local_c54 = 5;
  local_d08[0] = 1;
  local_d00 = &u_ACPI_INT3442;
  uVar6 = 0;
  local_cf0[0] = 0;
  local_ce0 = &u_ACPI_INT3443;
  local_cf8 = 2;
  local_cf0[2] = 1;
  local_cc0 = &u_ACPI_INT3444;
  local_cd8 = 2;
  local_ca0 = &u_ACPI_INT3445;
  local_c80 = &u_ACPI_INT3446;
  local_c60 = L"ACPI\\INT3447";
  local_c40 = &u_PCI_VEN_8086_DE;
  local_c20 = &u_PCI_VEN_8086_DE;
  local_c00 = &u_PCI_VEN_8086_DE;
  local_be0 = &u_PCI_VEN_8086_DE;
  local_bc0 = &u_PCI_VEN_8086_DE;
  local_ba0 = &u_PCI_VEN_8086_DE;
  local_b80 = &u_PCI_VEN_8086_DE;
  local_b60 = &u_PCI_VEN_8086_DE;
  local_cd4 = 1;
  local_cc8 = 1;
  local_cb8 = 2;
  local_cb4 = 2;
  local_ca8 = 1;
  local_c98 = 2;
  local_c94 = 3;
  local_c88 = 1;
  local_c78 = 2;
  local_c74 = 4;
  local_c68 = 1;
  local_c58 = 2;
  local_c48 = 1;
  local_c38 = 2;
  local_c30 = 1;
  local_c28 = 1;
  local_c18 = 2;
  local_c14 = 1;
  local_c10 = 1;
  local_c08 = 1;
  local_bf8 = 2;
  local_bf4 = 2;
  local_bf0 = 1;
  local_be8 = 1;
  local_bd8 = 2;
  local_bd4 = 3;
  local_bd0 = 1;
  local_bc8 = 1;
  local_bb8 = 2;
  local_bb4 = 4;
  local_bb0 = 1;
  local_ba8 = 1;
  local_b98 = 2;
  local_b94 = 5;
  local_b90 = 1;
  local_b88 = 1;
  local_b78 = 4;
  local_b70 = 1;
  local_b68 = 1;
  local_b58 = 4;
  local_b54 = 1;
  local_b50 = 1;
  local_b48 = 1;
  local_b40 = &u_PCI_VEN_8086_DE;
  local_b38 = 4;
  local_b20 = &u_PCI_VEN_8086_DE;
  local_b34 = 2;
  local_b00 = &u_PCI_VEN_8086_DE;
  local_ae0 = &u_PCI_VEN_8086_DE;
  local_ac0 = &u_PCI_VEN_8086_DE;
  local_aa0 = &u_PCI_VEN_8086_DE;
  local_a80 = &u_PCI_VEN_8086_DE;
  local_a60 = &u_PCI_VEN_8086_DE;
  local_a40 = &u_PCI_VEN_8086_DE;
  local_a20 = &u_PCI_VEN_8086_DE;
  local_a00 = &u_PCI_VEN_8086_DE;
  local_9e0 = &u_PCI_VEN_8086_DE;
  local_9c0 = &u_PCI_VEN_8086_DE;
  local_b30 = 1;
  local_b28 = 1;
  local_b18 = 4;
  local_b14 = 3;
  local_b10 = 1;
  local_b08 = 1;
  local_af8 = 4;
  local_af4 = 4;
  local_af0 = 1;
  local_ae8 = 1;
  local_ad8 = 4;
  local_ad4 = 5;
  local_ad0 = 1;
  local_ac8 = 1;
  local_ab8 = 4;
  local_ab4 = 6;
  local_ab0 = 1;
  local_aa8 = 1;
  local_a98 = 4;
  local_a94 = 7;
  local_a90 = 1;
  local_a88 = 1;
  local_a78 = 4;
  local_a70 = 1;
  local_a68 = 1;
  local_a58 = 4;
  local_a54 = 1;
  local_a50 = 1;
  local_a48 = 1;
  local_a38 = 4;
  local_a34 = 2;
  local_a30 = 1;
  local_a28 = 1;
  local_a18 = 4;
  local_a14 = 3;
  local_a10 = 1;
  local_a08 = 1;
  local_9f8 = 4;
  local_9f4 = 4;
  local_9f0 = 1;
  local_9e8 = 1;
  local_9d8 = 4;
  local_9d4 = 5;
  local_9d0 = 1;
  local_9c8 = 1;
  local_9b8 = 4;
  local_9b4 = 6;
  local_9b0 = 1;
  local_9a8 = 1;
  local_9a0 = &u_PCI_VEN_8086_DE;
  local_980 = &u_PCI_VEN_8086_DE;
  local_960 = &u_PCI_VEN_8086_DE;
  local_940 = &u_PCI_VEN_8086_DE;
  local_920 = &u_PCI_VEN_8086_DE;
  local_900 = &u_PCI_VEN_8086_DE;
  local_8e0 = &u_PCI_VEN_8086_DE;
  local_8c0 = &u_PCI_VEN_8086_DE;
  local_8a0 = &u_PCI_VEN_8086_DE;
  local_880 = &u_ACPI_INT3456;
  local_860 = &u_ACPI_INT3457;
  local_840 = &u_ACPI_INT3458;
  local_820 = &u_ACPI_INT3459;
  local_800 = &u_PCI_VEN_8086_DE;
  local_7e0 = &u_PCI_VEN_8086_DE;
  local_998 = 4;
  local_994 = 7;
  local_990 = 1;
  local_988 = 1;
  local_978 = 4;
  local_970 = 1;
  local_968 = 1;
  local_958 = 4;
  local_954 = 1;
  local_950 = 1;
  local_948 = 1;
  local_938 = 4;
  local_934 = 2;
  local_930 = 1;
  local_928 = 1;
  local_918 = 4;
  local_914 = 3;
  local_910 = 1;
  local_908 = 1;
  local_8f8 = 4;
  local_8f4 = 4;
  local_8f0 = 1;
  local_8e8 = 1;
  local_8d8 = 4;
  local_8d4 = 5;
  local_8d0 = 1;
  local_8c8 = 1;
  local_8b8 = 4;
  local_8b4 = 6;
  local_8b0 = 1;
  local_8a8 = 1;
  local_898 = 4;
  local_894 = 7;
  local_890 = 1;
  local_888 = 1;
  local_878 = 3;
  local_870 = 0;
  local_868 = 1;
  local_858 = 3;
  local_854 = 1;
  local_848 = 1;
  local_838 = 3;
  local_834 = 2;
  local_828 = 1;
  local_818 = 3;
  local_814 = 3;
  local_808 = 1;
  local_7f8 = 3;
  local_7f0 = 1;
  local_7e8 = 1;
  local_7d8 = 3;
  local_7d4 = 1;
  local_7d0 = 1;
  local_7c0 = &u_PCI_VEN_8086_DE;
  local_7c8 = 1;
  local_7a0 = &u_PCI_VEN_8086_DE;
  local_780 = &u_PCI_VEN_8086_DE;
  local_760 = &u_PCI_VEN_8086_DE;
  local_740 = &u_PCI_VEN_8086_DE;
  local_720 = &u_PCI_VEN_8086_DE;
  local_700 = &u_PCI_VEN_8086_DE;
  local_6e0 = &u_PCI_VEN_8086_DE;
  local_6c0 = &u_PCI_VEN_8086_DE;
  local_6a0 = &u_PCI_VEN_8086_DE;
  local_680 = &u_PCI_VEN_8086_DE;
  local_660 = &u_PCI_VEN_8086_DE;
  local_640 = &u_PCI_VEN_8086_DE;
  local_620 = &u_PCI_VEN_8086_DE;
  local_7b8 = 3;
  local_7b4 = 2;
  local_7b0 = 1;
  local_7a8 = 1;
  local_798 = 3;
  local_794 = 3;
  local_790 = 1;
  local_788 = 1;
  local_778 = 5;
  local_770 = 1;
  local_768 = 1;
  local_758 = 5;
  local_754 = 1;
  local_750 = 1;
  local_748 = 1;
  local_738 = 5;
  local_734 = 2;
  local_730 = 1;
  local_728 = 1;
  local_718 = 5;
  local_714 = 3;
  local_710 = 1;
  local_708 = 1;
  local_6f8 = 5;
  local_6f4 = 4;
  local_6f0 = 1;
  local_6e8 = 1;
  local_6d8 = 5;
  local_6d4 = 5;
  local_6d0 = 1;
  local_6c8 = 1;
  local_6b8 = 6;
  local_6b0 = 1;
  local_6a8 = 1;
  local_698 = 6;
  local_694 = 1;
  local_690 = 1;
  local_688 = 1;
  local_678 = 6;
  local_674 = 2;
  local_670 = 1;
  local_668 = 1;
  local_658 = 6;
  local_654 = 3;
  local_650 = 1;
  local_648 = 1;
  local_638 = 0xd;
  local_630 = 1;
  local_628 = 1;
  local_618 = 0xd;
  local_5f8 = 0xd;
  local_600 = &u_PCI_VEN_8086_DE;
  local_5e0 = &u_PCI_VEN_8086_DE;
  local_5c0 = &u_PCI_VEN_8086_DE;
  local_5a0 = &u_PCI_VEN_8086_DE;
  local_580 = &u_PCI_VEN_8086_DE;
  local_560 = &u_PCI_VEN_8086_DE;
  local_540 = &u_PCI_VEN_8086_DE;
  local_520 = &u_PCI_VEN_8086_DE;
  local_500 = &u_PCI_VEN_8086_DE;
  local_4e0 = &u_PCI_VEN_8086_DE;
  local_4c0 = &u_PCI_VEN_8086_DE;
  local_5d8 = 0xd;
  local_5b8 = 0xd;
  local_598 = 0xd;
  local_4a0 = &u_PCI_VEN_8086_DE;
  local_578 = 0xe;
  local_558 = 0xe;
  local_538 = 0xe;
  local_518 = 0xe;
  local_480 = &u_PCI_VEN_8086_DE;
  local_614 = 1;
  local_610 = 1;
  local_608 = 1;
  local_5f4 = 2;
  local_5f0 = 1;
  local_5e8 = 1;
  local_5d4 = 3;
  local_5d0 = 1;
  local_5c8 = 1;
  local_5b4 = 4;
  local_5b0 = 1;
  local_5a8 = 1;
  local_594 = 5;
  local_590 = 1;
  local_588 = 1;
  local_570 = 1;
  local_568 = 1;
  local_554 = 1;
  local_550 = 1;
  local_548 = 1;
  local_534 = 2;
  local_530 = 1;
  local_528 = 1;
  local_514 = 3;
  local_510 = 1;
  local_508 = 1;
  local_4f8 = 7;
  local_4f0 = 1;
  local_4e8 = 1;
  local_4d8 = 7;
  local_4d4 = 1;
  local_4d0 = 1;
  local_4c8 = 1;
  local_4b8 = 7;
  local_4b4 = 2;
  local_4b0 = 1;
  local_4a8 = 1;
  local_498 = 7;
  local_494 = 3;
  local_490 = 1;
  local_488 = 1;
  local_478 = 8;
  local_470 = 1;
  local_468 = 1;
  local_460 = &u_PCI_VEN_8086_DE;
  local_440 = &u_PCI_VEN_8086_DE;
  local_420 = &u_PCI_VEN_8086_DE;
  local_400 = &u_PCI_VEN_8086_DE;
  local_3e0 = &u_PCI_VEN_8086_DE;
  local_3c0 = &u_PCI_VEN_8086_DE;
  local_3a0 = &u_PCI_VEN_8086_DE;
  local_380 = &u_PCI_VEN_8086_DE;
  local_360 = &u_PCI_VEN_8086_DE;
  local_340 = &u_PCI_VEN_8086_DE;
  local_320 = &u_PCI_VEN_8086_DE;
  local_300 = &u_PCI_VEN_8086_DE;
  local_2e0 = &u_PCI_VEN_8086_DE;
  local_458 = 8;
  local_438 = 8;
  local_418 = 8;
  local_3f8 = 8;
  local_3d8 = 8;
  local_3b8 = 8;
  local_398 = 8;
  local_2c0 = &u_PCI_VEN_8086_DE;
  local_454 = 1;
  local_450 = 1;
  local_448 = 1;
  local_434 = 2;
  local_430 = 1;
  local_428 = 1;
  local_414 = 3;
  local_410 = 1;
  local_408 = 1;
  local_3f4 = 4;
  local_3f0 = 1;
  local_3e8 = 1;
  local_3d4 = 5;
  local_3d0 = 1;
  local_3c8 = 1;
  local_3b4 = 6;
  local_3b0 = 1;
  local_3a8 = 1;
  local_394 = 7;
  local_390 = 1;
  local_388 = 1;
  local_378 = 9;
  local_370 = 1;
  local_368 = 1;
  local_358 = 9;
  local_354 = 1;
  local_350 = 1;
  local_348 = 1;
  local_338 = 9;
  local_334 = 2;
  local_330 = 1;
  local_328 = 1;
  local_318 = 9;
  local_314 = 3;
  local_310 = 1;
  local_308 = 1;
  local_2f8 = 9;
  local_2f4 = 4;
  local_2f0 = 1;
  local_2e8 = 1;
  local_2d8 = 9;
  local_2d4 = 5;
  local_2d0 = 1;
  local_2c8 = 1;
  local_2b8 = 10;
  local_2b0 = 1;
  local_2a8 = 1;
  local_298 = 10;
  local_2a0 = &u_PCI_VEN_8086_DE;
  local_280 = &u_PCI_VEN_8086_DE;
  local_260 = &u_PCI_VEN_8086_DE;
  local_240 = &u_PCI_VEN_8086_DE;
  local_220 = &u_PCI_VEN_8086_DE;
  local_200 = &u_PCI_VEN_8086_DE;
  local_1e0 = &u_PCI_VEN_8086_DE;
  local_1c0 = &u_PCI_VEN_8086_DE;
  local_1a0 = &u_PCI_VEN_8086_DE;
  local_180 = &u_PCI_VEN_8086_DE;
  local_160 = &u_PCI_VEN_8086_DE;
  local_140 = &u_PCI_VEN_8086_DE;
  local_120 = &u_PCI_VEN_8086_DE;
  local_100 = &u_PCI_VEN_8086_DE;
  local_294 = 1;
  local_290 = 1;
  local_288 = 1;
  local_278 = 10;
  local_274 = 2;
  local_270 = 1;
  local_268 = 1;
  local_258 = 10;
  local_254 = 3;
  local_250 = 1;
  local_248 = 1;
  local_238 = 10;
  local_234 = 4;
  local_230 = 1;
  local_228 = 1;
  local_218 = 10;
  local_214 = 5;
  local_210 = 1;
  local_208 = 1;
  local_1f8 = 0xb;
  local_1f0 = 1;
  local_1e8 = 1;
  local_1d8 = 0xb;
  local_1d4 = 1;
  local_1d0 = 1;
  local_1c8 = 1;
  local_1b8 = 0xb;
  local_1b4 = 2;
  local_1b0 = 1;
  local_1a8 = 1;
  local_198 = 0xb;
  local_194 = 3;
  local_190 = 1;
  local_188 = 1;
  local_178 = 0xb;
  local_174 = 4;
  local_170 = 1;
  local_168 = 1;
  local_158 = 0xb;
  local_154 = 5;
  local_150 = 1;
  local_148 = 1;
  local_138 = 0xb;
  local_134 = 6;
  local_130 = 1;
  local_128 = 1;
  local_118 = 0xb;
  local_114 = 7;
  local_110 = 1;
  local_108 = 1;
  local_f0 = 1;
  local_f8 = 0xc;
  local_e0 = &u_PCI_VEN_8086_DE;
  ppuVar7 = &local_d00;
  local_e8 = 1;
  local_c0 = &u_PCI_VEN_8086_DE;
  local_a0 = &u_PCI_VEN_8086_DE;
  local_80 = &u_PCI_VEN_8086_DE;
  local_60 = &u_PCI_VEN_8086_DE;
  local_d8 = 0xc;
  local_d4 = 1;
  local_d0 = 1;
  local_c8 = 1;
  local_b8 = 0xc;
  local_b4 = 2;
  local_b0 = 1;
  local_a8 = 1;
  local_98 = 0xc;
  local_94 = 3;
  local_90 = 1;
  local_88 = 1;
  local_78 = 0xc;
  local_74 = 4;
  local_70 = 1;
  local_68 = 1;
  local_58 = 0xc;
  local_54 = 5;
  local_50 = 1;
  do {
    memset(local_d40,0,0x38);
    local_d40[0] = 0x38;
    local_d28 = 1;
    local_d24 = 1;
    local_d20 = param_1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x290))
                      (WdfDriverGlobals,param_1,*(undefined4 *)(ppuVar7 + -1));
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff,(char)uVar6,(char)iVar2);
      }
    }
    else {
      _Src = (wchar_t *)
             (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_d58,&local_d50);
      pwVar1 = (wchar_t *)((longlong)_Src + (local_d50 & 0xfffffffffffffffe));
      for (; _Src < pwVar1; _Src = _Src + sVar4 + 1) {
        _MaxCount = (longlong)pwVar1 - (longlong)_Src >> 1;
        sVar4 = wcsnlen(_Src,_MaxCount);
        if (sVar4 == 0) break;
        _Str2 = (wchar_t *)*ppuVar7;
        uVar5 = 0xffffffffffffffff;
        sVar4 = _MaxCount & 0xffffffff;
        do {
          uVar5 = uVar5 + 1;
        } while (_Str2[uVar5] != L'\0');
        if (uVar5 < sVar4) {
          sVar4 = 0xffffffffffffffff;
          do {
            sVar4 = sVar4 + 1;
          } while (_Str2[sVar4] != L'\0');
        }
        iVar3 = wcsncmp(_Src,_Str2,sVar4);
        if (iVar3 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_dS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                      &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff,(undefined *)_Src);
          }
          uVar5 = (ulonglong)uVar6;
          *(undefined4 *)(param_2 + 4) = local_cf0[uVar5 * 8 + -2];
          *(undefined4 *)param_2 = local_cf0[uVar5 * 8 + -1];
          *(undefined4 *)(param_2 + 0xc) = local_cf0[uVar5 * 8];
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_d58);
          goto LAB_140015a18;
        }
        sVar4 = wcsnlen(_Src,_MaxCount);
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      param_1 = local_d48;
    }
    uVar6 = uVar6 + 1;
    ppuVar7 = ppuVar7 + 4;
    if (0x65 < uVar6) {
      iVar2 = -0x3ffffda0;
LAB_140015a18:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_bf0a3794df1c3963920e5550acf7475d_Traceguids,0xff);
      }
      return iVar2;
    }
  } while( true );
}



===== WPP_SF_dS @ 140015b08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined *param_5)

{
  longlong lVar1;
  undefined *puVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (undefined *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_5 + lVar1 * 2) != 0);
    lVar1 = lVar1 * 2 + 2;
  }
  puVar2 = &u_NULL;
  if (param_5 != (undefined *)0x0) {
    puVar2 = param_5;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,puVar2,lVar1,0);
  return;
}



===== CheckTransferForDmaOperation @ 140015b94 =====

/* unsigned char __cdecl CheckTransferForDmaOperation(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST
   * __ptr64) */

uchar __cdecl CheckTransferForDmaOperation(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  uint uVar1;
  PBC_DEVICE PVar2;
  uint uVar3;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
       || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)))) ||
      ((((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
        || (5 < uVar3)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar3);
  }
  if (((param_1[0x118] == (PBC_DEVICE)0x0) || (*(int *)(param_1 + 0xfc) != 1)) ||
     (*(ulonglong *)(param_2 + 0x38) < (ulonglong)*(uint *)(param_1 + 0x100))) {
    PVar2 = (PBC_DEVICE)0x0;
  }
  else {
    PVar2 = (PBC_DEVICE)0x1;
  }
  param_1[0x119] = PVar2;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
       || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar3);
  }
  return (uchar)param_1[0x119];
}



===== DmaCheckBusy @ 140015cfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl DmaCheckBusy(struct PBC_DEVICE * __ptr64,enum _WDF_DMA_DIRECTION) */

uchar __cdecl DmaCheckBusy(PBC_DEVICE *param_1,_WDF_DMA_DIRECTION param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (param_2 == 1) {
    uVar2 = *(undefined8 *)(param_1 + 0x128);
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x130);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
  return *(uchar *)(lVar1 + 100);
}



===== DmaDataTransferred @ 140015d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned __int64 __cdecl DmaDataTransferred(struct PBC_DEVICE * __ptr64,enum _WDF_DMA_DIRECTION)
    */

__uint64 __cdecl DmaDataTransferred(PBC_DEVICE *param_1,_WDF_DMA_DIRECTION param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  if (param_2 == 1) {
    uVar3 = *(undefined8 *)(param_1 + 0x128);
  }
  else {
    uVar3 = *(undefined8 *)(param_1 + 0x130);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
  uVar2 = *(ulonglong *)(lVar1 + 0x40);
  if (*(ulonglong *)(lVar1 + 0x48) <= *(ulonglong *)(lVar1 + 0x40)) {
    uVar2 = *(ulonglong *)(lVar1 + 0x48);
  }
  return uVar2;
}



===== DmaInitSw @ 140015d94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl DmaInitSw(struct PBC_DEVICE * __ptr64) */

long __cdecl DmaInitSw(PBC_DEVICE *param_1)

{
  PBC_DEVICE *pPVar1;
  PBC_DEVICE *pPVar2;
  PBC_DEVICE *pPVar3;
  uint uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined4 local_b8 [6];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined *local_88;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  code *local_58;
  code *local_50;
  undefined4 local_34;
  
  uVar11 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar11 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar4 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar11 == 1))))
       || (((uVar4 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
      ((((uVar4 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
       (((((uVar4 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
         (((uVar4 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
  }
  pPVar1 = param_1 + 0x120;
  *(undefined8 *)pPVar1 = 0;
  *(undefined8 *)(param_1 + 0x128) = 0;
  pPVar2 = param_1 + 0x130;
  *(undefined8 *)pPVar2 = 0;
  pPVar3 = param_1 + 0x140;
  *(WDFCOMMONBUFFER__ **)pPVar3 = (WDFCOMMONBUFFER__ *)0x0;
  param_1[0x119] = (PBC_DEVICE)0x0;
  *(undefined8 *)(param_1 + 0x138) = 0;
  (**(code **)(WdfFunctions_01015 + 0x1a8))(WdfDriverGlobals,*(undefined8 *)param_1,0x3f);
  memset(&local_78,0,0x50);
  local_78 = 0x50;
  local_58 = EvtDmaD0Exit;
  local_74 = 6;
  local_50 = EvtDmaD0Entry;
  local_70 = 0x10000;
  local_34 = 3;
  memset(local_b8,0,0x38);
  local_a0 = 1;
  local_9c = 1;
  local_88 = PTR__WDF_DMA_ENABLER_CONTEXT_TYPE_INFO_140022088;
  local_b8[0] = 0x38;
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x2f0))
                    (WdfDriverGlobals,*(undefined8 *)param_1,&local_78,local_b8,pPVar1);
  if (iVar5 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar5;
    }
    uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       (((((uVar4 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
         ((((uVar4 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
          (((uVar4 >> 0xd & 1) == 0 || (uVar11 != 2)))))) &&
        (((((uVar4 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
          (((uVar4 >> 0xf & 1) == 0 || (uVar11 != 4)))) &&
         ((((uVar4 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6)))))))) goto LAB_140016749;
    uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar10 = 0xe;
  }
  else {
    puVar6 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)pPVar1,
                        PTR__WDF_DMA_ENABLER_CONTEXT_TYPE_INFO_140022088);
    *puVar6 = *(undefined8 *)param_1;
    memset(local_b8,0,0x38);
    local_a0 = 1;
    local_9c = 1;
    local_88 = PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060;
    local_b8[0] = 0x38;
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x310))
                      (WdfDriverGlobals,*(undefined8 *)pPVar1,local_b8,pPVar2);
    if (iVar5 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar5;
      }
      uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
         (((((uVar4 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
           ((((uVar4 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
            (((uVar4 >> 0xd & 1) == 0 || (uVar11 != 2)))))) &&
          (((((uVar4 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
            (((uVar4 >> 0xf & 1) == 0 || (uVar11 != 4)))) &&
           ((((uVar4 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6)))))))) goto LAB_140016749;
      uVar10 = 0xf;
    }
    else {
      puVar7 = (undefined4 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,*(undefined8 *)pPVar2,
                          PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
      *puVar7 = 0;
      puVar7[0x18] = 0;
      *(undefined1 *)(puVar7 + 0xe) = 0;
      *(undefined1 *)(puVar7 + 0x19) = 0;
      memset(local_b8,0,0x38);
      local_a0 = 1;
      local_9c = 1;
      local_88 = PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060;
      local_b8[0] = 0x38;
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x310))
                        (WdfDriverGlobals,*(undefined8 *)pPVar1,local_b8);
      if (iVar5 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar5;
        }
        uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           ((((((uVar4 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
              (((uVar4 >> 0xc & 1) == 0 || (uVar11 != 1)))) &&
             (((uVar4 >> 0xd & 1) == 0 || (uVar11 != 2)))) &&
            (((((uVar4 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
              (((uVar4 >> 0xf & 1) == 0 || (uVar11 != 4)))) &&
             ((((uVar4 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))))
        goto LAB_140016749;
        uVar10 = 0x10;
      }
      else {
        puVar7 = (undefined4 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128),
                            PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
        puVar7[0x18] = 0;
        *puVar7 = 1;
        *(undefined1 *)(puVar7 + 0xe) = 0;
        *(undefined1 *)(puVar7 + 0x19) = 0;
        lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*(undefined8 *)pPVar2,
                           PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
        *(undefined8 *)(lVar8 + 0x20) = 0xfc0;
        iVar5 = LpssCommonBufferCreate
                          (param_1,*(WDFDMAENABLER__ **)pPVar1,0xfc0,(_WDF_OBJECT_ATTRIBUTES *)0x0,
                           (WDFCOMMONBUFFER__ **)pPVar3);
        if (iVar5 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar5;
          }
          uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
          if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
             (((((uVar4 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
               ((((uVar4 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
                (((uVar4 >> 0xd & 1) == 0 || (uVar11 != 2)))))) &&
              (((((uVar4 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
                (((uVar4 >> 0xf & 1) == 0 || (uVar11 != 4)))) &&
               ((((uVar4 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))))
          goto LAB_140016749;
          uVar10 = 0x11;
        }
        else {
          uVar9 = (**(code **)(WdfFunctions_01015 + 0xb0))
                            (WdfDriverGlobals,*(WDFCOMMONBUFFER__ **)pPVar3);
          *(undefined8 *)(lVar8 + 0x28) = uVar9;
          uVar9 = (**(code **)(WdfFunctions_01015 + 0xb8))(WdfDriverGlobals);
          *(undefined8 *)(lVar8 + 0x30) = uVar9;
          memset(*(void **)(lVar8 + 0x28),0,*(size_t *)(lVar8 + 0x20));
          if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 0x200) != 0)) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             (((((uVar4 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
               ((((uVar4 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                (((uVar4 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
              (((((uVar4 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
                ((((uVar4 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                 (((uVar4 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))))) {
            WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                       &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11,
                       (char)*(undefined8 *)(lVar8 + 0x30),(char)*(undefined8 *)(lVar8 + 0x20));
          }
          lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128),
                             PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
          *(undefined8 *)(lVar8 + 0x20) = 0xfc0;
          iVar5 = LpssCommonBufferCreate
                            (param_1,*(WDFDMAENABLER__ **)pPVar1,0xfc0,(_WDF_OBJECT_ATTRIBUTES *)0x0
                             ,(WDFCOMMONBUFFER__ **)(param_1 + 0x138));
          if (iVar5 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar5;
            }
            uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
            if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
               (((((uVar4 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
                 ((((uVar4 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
                  (((uVar4 >> 0xd & 1) == 0 || (uVar11 != 2)))))) &&
                (((((uVar4 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
                  (((uVar4 >> 0xf & 1) == 0 || (uVar11 != 4)))) &&
                 ((((uVar4 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))))
            goto LAB_140016749;
            uVar10 = 0x13;
          }
          else {
            uVar9 = (**(code **)(WdfFunctions_01015 + 0xb0))
                              (WdfDriverGlobals,*(WDFCOMMONBUFFER__ **)(param_1 + 0x138));
            *(undefined8 *)(lVar8 + 0x28) = uVar9;
            uVar9 = (**(code **)(WdfFunctions_01015 + 0xb8))(WdfDriverGlobals);
            *(undefined8 *)(lVar8 + 0x30) = uVar9;
            memset(*(void **)(lVar8 + 0x28),0,*(size_t *)(lVar8 + 0x20));
            if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 & 0x200) != 0)) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
               (((((uVar4 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
                 ((((uVar4 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
                  ((((uVar4 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                   (((uVar4 >> 0xe & 1) != 0 && (uVar11 == 3)))))))) ||
                (((((uVar4 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                  (((uVar4 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
              WPP_SF_dPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                         &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11,
                         (char)*(undefined8 *)(lVar8 + 0x30),(char)*(undefined8 *)(lVar8 + 0x20));
            }
            memset(local_b8,0,0x38);
            local_98 = *(undefined8 *)param_1;
            local_b8[0] = 0x38;
            local_a0 = 1;
            local_9c = 1;
            iVar5 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                              (WdfDriverGlobals,local_b8,param_1 + 0x148);
            if (iVar5 < 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar5;
              }
              uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
              if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
                 (((((uVar4 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
                   (((uVar4 >> 0xc & 1) == 0 || (uVar11 != 1)))) &&
                  ((((uVar4 >> 0xd & 1) == 0 || (uVar11 != 2)) &&
                   (((((uVar4 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
                     (((uVar4 >> 0xf & 1) == 0 || (uVar11 != 4)))) &&
                    ((((uVar4 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))))))
              goto LAB_140016749;
              uVar10 = 0x15;
            }
            else {
              memset(local_b8,0,0x38);
              local_98 = *(undefined8 *)param_1;
              local_b8[0] = 0x38;
              local_a0 = 1;
              local_9c = 1;
              iVar5 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                                (WdfDriverGlobals,local_b8,param_1 + 0x150);
              if (-1 < iVar5) goto LAB_140016749;
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar5;
              }
              uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
              if ((((uVar4 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
                 ((((uVar4 >> 0xb & 1) == 0 || (uVar11 != 0)) &&
                  ((((((uVar4 >> 0xc & 1) == 0 || (uVar11 != 1)) &&
                     (((uVar4 >> 0xd & 1) == 0 || (uVar11 != 2)))) &&
                    ((((uVar4 >> 0xe & 1) == 0 || (uVar11 != 3)) &&
                     (((uVar4 >> 0xf & 1) == 0 || (uVar11 != 4)))))) &&
                   ((((uVar4 >> 0x10 & 1) == 0 || (uVar11 != 5)) && (uVar11 < 6))))))))
              goto LAB_140016749;
              uVar10 = 0x16;
            }
          }
        }
      }
    }
    uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  WPP_SF_dD(uVar9,uVar10,&WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11,(char)iVar5);
LAB_140016749:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar11 == 1))))
      || (((((uVar4 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
           (((uVar4 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
          (((((uVar4 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
            (((uVar4 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
  }
  return iVar5;
}



===== DmaReleaseSw @ 1400167ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl DmaReleaseSw(struct PBC_DEVICE * __ptr64) */

long __cdecl DmaReleaseSw(PBC_DEVICE *param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  uVar3 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5)))))
       ) || (5 < uVar3)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar3);
  }
  if (*(longlong *)(param_1 + 0x128) != 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(param_1 + 0x128),
                       PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
    *(undefined1 *)(lVar2 + 0x38) = 0;
    *(undefined1 *)(lVar2 + 100) = 0;
    *(undefined8 *)(param_1 + 0x128) = 0;
  }
  if (*(longlong *)(param_1 + 0x130) != 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(longlong *)(param_1 + 0x130),
                       PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
    *(undefined1 *)(lVar2 + 0x38) = 0;
    *(undefined1 *)(lVar2 + 100) = 0;
    *(undefined8 *)(param_1 + 0x130) = 0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar3 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar3 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar3 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar3 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar3 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar3 == 5))))
       || (5 < uVar3)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar3);
  }
  return 0;
}



===== DmaRxComplete @ 140016994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl DmaRxComplete(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64,enum
   DMA_COMPLETION_STATUS) */

uchar __cdecl DmaRxComplete(PBC_DEVICE *param_1,PBC_REQUEST *param_2,DMA_COMPLETION_STATUS param_3)

{
  uint uVar1;
  char cVar2;
  uchar uVar3;
  uchar uVar4;
  _DMA_TRANSACTION_CONTEXT *p_Var5;
  __uint64 _Var6;
  code *pcVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  uint uVar10;
  longlong lVar11;
  int local_res18 [2];
  
  uVar10 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar10 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))
         ) || ((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ))) || (5 < uVar10)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10);
  }
  uVar3 = '\0';
  local_res18[0] = 0;
  p_Var5 = (_DMA_TRANSACTION_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130),
                      PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
  *(DMA_COMPLETION_STATUS *)(p_Var5 + 4) = param_3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
      ((((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))
         ) || (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
       (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
    WPP_SF_ddDDP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                 &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10,(char)param_3,p_Var5[100],
                 p_Var5[0x38],(char)*(undefined8 *)(p_Var5 + 0x10));
  }
  if (p_Var5[100] == (_DMA_TRANSACTION_CONTEXT)0x0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
          (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10);
    }
    uVar3 = '\x01';
    goto LAB_140017230;
  }
  if (param_3 != 0) {
    cVar2 = (**(code **)(WdfFunctions_01015 + 0xcf0))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130));
    if (cVar2 == '\x01') {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
             ((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))))))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))))) || (5 < uVar10)))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                 &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10);
      }
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
          ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                 &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10);
      }
      uVar4 = SuspendDmaChannel(param_1,2,'\x01');
      if (uVar4 == '\0') {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                   &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10);
        }
        PbcFailDevice(param_1);
        goto LAB_140017230;
      }
    }
  }
  if (*(longlong *)(p_Var5 + 0x10) == 0) {
    lVar11 = *(longlong *)(p_Var5 + 0x58);
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        (((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))))) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
      uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar9 = 0x3c;
LAB_140016eca:
      WPP_SF_dP(uVar8,uVar9,&WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10,(char)lVar11);
    }
  }
  else {
    if (p_Var5[0x38] == (_DMA_TRANSACTION_CONTEXT)0x0) goto LAB_140017230;
    lVar11 = (**(code **)(WdfFunctions_01015 + 0x368))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
      uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar9 = 0x3b;
      goto LAB_140016eca;
    }
  }
  _Var6 = GetCurrentDmaTransferLeft(param_1,p_Var5);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
          (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ))) || (5 < uVar10)))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
              &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10,(char)_Var6);
  }
  lVar11 = lVar11 - _Var6;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1))))
      || ((((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)) ||
          (((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))))) || (5 < uVar10)))))))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
              &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10,(char)lVar11);
  }
  *(longlong *)(p_Var5 + 0x40) = *(longlong *)(p_Var5 + 0x40) + lVar11;
  if (*(longlong *)(p_Var5 + 0x10) == 0) goto LAB_140017230;
  if (param_3 == 0) {
    pcVar7 = *(code **)(WdfFunctions_01015 + 0x340);
  }
  else {
    pcVar7 = *(code **)(WdfFunctions_01015 + 0x348);
  }
  uVar3 = (*pcVar7)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130),lVar11,local_res18);
  if (uVar3 == '\0') goto LAB_140017230;
  uVar4 = DisableDmaChannel(param_1,2);
  if (uVar4 == '\0') {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10);
    }
    PbcFailDevice(param_1);
    uVar3 = '\0';
    goto LAB_140017230;
  }
  if ((local_res18[0] == 0) && (param_3 == 0)) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
          (((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)))) ||
         (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))) || (5 < uVar10)))))))) {
      uVar9 = 0x41;
LAB_1400171f3:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0 &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
          ((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
           (((((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
             (((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)))) ||
            ((((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)) || (5 < uVar10)))))))) {
    uVar9 = 0x40;
    goto LAB_1400171f3;
  }
  (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130));
  p_Var5[0x38] = (_DMA_TRANSACTION_CONTEXT)0x0;
  p_Var5[100] = (_DMA_TRANSACTION_CONTEXT)0x0;
LAB_140017230:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar10 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar10 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar10 == 2)))
         ))) || (((uVar1 >> 0xe & 1) != 0 && (uVar10 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar10 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar10 == 5)))
        ) || (5 < uVar10)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar10);
  }
  return uVar3;
}



===== DmaRxStart @ 1400172d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl DmaRxStart(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl DmaRxStart(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_REQUEST PVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1))))
        || ((((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5)))))
       ) || (5 < uVar7)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar7);
  }
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130),
                     PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
  *(int *)(lVar6 + 0x60) = *(int *)(lVar6 + 0x60) + 1;
  *(undefined8 *)(lVar6 + 0x40) = 0;
  *(undefined8 *)(lVar6 + 0x48) = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(lVar6 + 0x50) = *(undefined8 *)(param_2 + 0x38);
  PVar1 = param_2[0x78];
  *(undefined4 *)(lVar6 + 4) = 0;
  *(PBC_REQUEST *)(lVar6 + 8) = PVar1;
  *(undefined1 *)(lVar6 + 0x38) = 0;
  *(undefined1 *)(lVar6 + 100) = 0;
  lVar3 = *(longlong *)(param_2 + 0x58);
  *(longlong *)(lVar6 + 0x10) = lVar3;
  uVar4 = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(lVar6 + 0x18) = uVar4;
  if (lVar3 == 0) {
    iVar5 = -0x3fffffff;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2))))
         )) || ((((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                (((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                  (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar7);
    }
  }
  else {
    iVar5 = (**(code **)(WdfFunctions_01015 + 0xcb0))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130),EvtProgramDmaRx,0,lVar3,0,
                       uVar4);
    if (iVar5 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
            (((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
           ((((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
          (((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                  &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar7,(char)iVar5);
      }
      (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130));
      goto LAB_14001764c;
    }
    *(undefined1 *)(lVar6 + 0x38) = 1;
    *(undefined1 *)(lVar6 + 100) = 1;
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x328))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130),lVar6);
    if (-1 < iVar5) goto LAB_14001764c;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || ((((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
             (((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)))))) ||
        (((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5)))
          ) || (5 < uVar7)))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar7,(char)iVar5);
    }
    (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x130));
    *(undefined1 *)(lVar6 + 0x38) = 0;
  }
  *(undefined1 *)(lVar6 + 100) = 0;
LAB_14001764c:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
       ((((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2))))))
      || ((((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
          (((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar7);
  }
  return iVar5;
}



===== DmaTxComplete @ 1400176e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl DmaTxComplete(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64,enum
   DMA_COMPLETION_STATUS) */

uchar __cdecl DmaTxComplete(PBC_DEVICE *param_1,PBC_REQUEST *param_2,DMA_COMPLETION_STATUS param_3)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  uchar uVar4;
  uchar uVar5;
  _DMA_TRANSACTION_CONTEXT *p_Var6;
  __uint64 _Var7;
  code *pcVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  uint uVar11;
  longlong lVar12;
  undefined1 auStackY_a8 [32];
  uint local_68 [2];
  undefined4 local_60 [4];
  int local_50;
  undefined4 local_4c;
  int local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar11 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar11 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))
         ) || ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))
        ))) || (5 < uVar11)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
  }
  uVar4 = '\0';
  local_68[0] = 0;
  p_Var6 = (_DMA_TRANSACTION_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128),
                      PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
  *(DMA_COMPLETION_STATUS *)(p_Var6 + 4) = param_3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2))))
       )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
              (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
    WPP_SF_ddDDP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11,(char)param_3,p_Var6[100],
                 p_Var6[0x38],(char)*(undefined8 *)(p_Var6 + 0x10));
  }
  if (p_Var6[100] == (_DMA_TRANSACTION_CONTEXT)0x0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
           (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
         (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
          (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
    }
    uVar4 = '\x01';
    goto LAB_140018095;
  }
  if (param_3 != 0) {
    if ((p_Var6[0x38] != (_DMA_TRANSACTION_CONTEXT)0x0) &&
       (cVar3 = (**(code **)(WdfFunctions_01015 + 0xcf0))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128)), cVar3 == '\x01')) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0 &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
         (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
           (((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
             (((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)))))))) ||
          ((((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)) || (5 < uVar11)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                 &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
      }
      goto LAB_1400179e2;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
        ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
    }
    uVar5 = DisableDmaChannel(param_1,1);
    if (uVar5 != '\0') goto LAB_1400179e2;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
          (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
      uVar10 = 0x26;
LAB_140017ba0:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
    }
LAB_140017bb3:
    PbcFailDevice(param_1);
    goto LAB_140018095;
  }
LAB_1400179e2:
  if (*(longlong *)(p_Var6 + 0x10) == 0) {
    lVar12 = *(longlong *)(p_Var6 + 0x58);
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))
         ) || (((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
               (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
                 (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
      uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar10 = 0x28;
LAB_140017c2e:
      WPP_SF_dP(uVar9,uVar10,&WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11,(char)lVar12);
    }
  }
  else {
    if (p_Var6[0x38] == (_DMA_TRANSACTION_CONTEXT)0x0) goto LAB_140018095;
    lVar12 = (**(code **)(WdfFunctions_01015 + 0x368))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128));
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
        ((((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
          (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
         (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))) {
      uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar10 = 0x27;
      goto LAB_140017c2e;
    }
  }
  _Var7 = GetCurrentDmaTransferLeft(param_1,p_Var6);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))
         ) || (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
       ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
        ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
         (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))))) || (5 < uVar11)))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
              &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11,(char)_Var7);
  }
  lVar12 = lVar12 - _Var7;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1))))
      || ((((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)) ||
          ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))))))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
              &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11,(char)lVar12);
  }
  lVar2 = *(longlong *)(p_Var6 + 0x40);
  *(longlong *)(p_Var6 + 0x40) = lVar2 + lVar12;
  if (*(longlong *)(p_Var6 + 0x10) == 0) {
    if ((lVar2 + lVar12 != *(longlong *)(p_Var6 + 0x50)) && (param_3 == 0)) {
      local_4c = *(undefined4 *)(param_1 + 0x1c);
      local_48 = *(int *)(p_Var6 + 0x50) - *(int *)(p_Var6 + 0x40);
      local_50 = *(int *)(param_1 + 0x18) + 0x228;
      local_60[0] = 1;
      uVar5 = EvtProgramDmaTx(*(WDFDMATRANSACTION__ **)(param_1 + 0x128),*(WDFDEVICE__ **)param_1,
                              p_Var6,1,(_SCATTER_GATHER_LIST *)local_60);
      if (uVar5 != '\0') goto LAB_140018095;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
              (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
           ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))) || (5 < uVar11)))) {
        uVar10 = 0x2b;
        goto LAB_140017ba0;
      }
      goto LAB_140017bb3;
    }
    uVar4 = '\x01';
    local_68[0] = -(uint)(param_3 != 0) & 0xc0000120;
  }
  else {
    if (param_3 == 0) {
      pcVar8 = *(code **)(WdfFunctions_01015 + 0x340);
    }
    else {
      pcVar8 = *(code **)(WdfFunctions_01015 + 0x348);
    }
    uVar4 = (*pcVar8)(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128),lVar12,local_68);
  }
  if (uVar4 == '\0') goto LAB_140018095;
  uVar5 = CheckDmaChannelDisabled(param_1,1);
  if (uVar5 == '\0') {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
          ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))))) ||
         ((((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)) ||
          ((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))))))) || (5 < uVar11)))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
    }
    PbcFailDevice(param_1);
    uVar4 = '\0';
    goto LAB_140018095;
  }
  if ((local_68[0] == 0) && (param_3 == 0)) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
           (((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)))) ||
          (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
         (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) ||
          (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))) || (5 < uVar11)))))) {
      uVar10 = 0x2e;
LAB_140018052:
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
               &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0 &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])))) &&
          ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
             (((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))) ||
              (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))))) ||
            (((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)))) ||
           ((((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)) || (5 < uVar11)))))) {
    uVar10 = 0x2d;
    goto LAB_140018052;
  }
  if (*(longlong *)(p_Var6 + 0x10) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128));
    p_Var6[0x38] = (_DMA_TRANSACTION_CONTEXT)0x0;
  }
  p_Var6[100] = (_DMA_TRANSACTION_CONTEXT)0x0;
LAB_140018095:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar11 == 0)) ||
        ((((uVar1 >> 0xc & 1) != 0 && (uVar11 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar11 == 2)))
         ))) || (((uVar1 >> 0xe & 1) != 0 && (uVar11 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar11 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar11 == 5)))
        ) || (5 < uVar11)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar11);
  }
  return uVar4;
}



===== DmaTxStart @ 140018148 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl DmaTxStart(struct PBC_DEVICE * __ptr64,struct PBC_REQUEST * __ptr64) */

long __cdecl DmaTxStart(PBC_DEVICE *param_1,PBC_REQUEST *param_2)

{
  PBC_REQUEST PVar1;
  uint uVar2;
  uchar uVar3;
  void *pvVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined2 uVar7;
  ulong uVar8;
  uint uVar9;
  byte bVar10;
  ulonglong uVar11;
  int iVar12;
  undefined1 auStackY_a8 [32];
  undefined4 local_68 [4];
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar9 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar9 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1))))
        || (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
       ((((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
        ((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        )))) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar9);
  }
  iVar12 = 0;
  pvVar4 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128),
                              PTR__WDF_DMA_TRANSACTION_CONTEXT_TYPE_INFO_140022060);
  *(int *)((longlong)pvVar4 + 0x60) = *(int *)((longlong)pvVar4 + 0x60) + 1;
  *(undefined8 *)((longlong)pvVar4 + 0x40) = 0;
  *(undefined8 *)((longlong)pvVar4 + 0x48) = *(undefined8 *)(param_2 + 0x28);
  *(undefined8 *)((longlong)pvVar4 + 0x50) = *(undefined8 *)(param_2 + 0x38);
  PVar1 = param_2[0x78];
  *(undefined4 *)((longlong)pvVar4 + 4) = 0;
  *(PBC_REQUEST *)((longlong)pvVar4 + 8) = PVar1;
  *(undefined1 *)((longlong)pvVar4 + 0x38) = 0;
  *(undefined1 *)((longlong)pvVar4 + 100) = 0;
  lVar5 = *(longlong *)(param_2 + 0x50);
  *(longlong *)((longlong)pvVar4 + 0x10) = lVar5;
  *(undefined8 *)((longlong)pvVar4 + 0x18) = *(undefined8 *)(param_2 + 0x28);
  if (lVar5 == 0) {
    uVar8 = 0x500;
    if ((*(longlong *)(param_2 + 0x38) == 1) && (uVar8 = 0x500, param_2[0x78] == (PBC_REQUEST)0x1))
    {
      uVar8 = 0x700;
    }
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x28),uVar8);
    uVar11 = *(ulonglong *)(param_2 + 0x38);
    if (((1 < uVar11) && (param_2[0x78] == (PBC_REQUEST)0x0)) ||
       ((2 < uVar11 && (param_2[0x78] == (PBC_REQUEST)0x1)))) {
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x2c),0x100);
      uVar11 = *(ulonglong *)(param_2 + 0x38);
    }
    if ((1 < uVar11) && (param_2[0x78] == (PBC_REQUEST)0x1)) {
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x30),0x300);
    }
    local_54 = *(undefined4 *)(param_1 + 0x1c);
    local_58 = *(int *)(param_1 + 0x18) + 0x230;
    *(undefined1 *)((longlong)pvVar4 + 100) = 1;
    local_50 = *(undefined4 *)((longlong)pvVar4 + 0x50);
    local_68[0] = 1;
    uVar3 = EvtProgramDmaTx(*(WDFDMATRANSACTION__ **)(param_1 + 0x128),*(WDFDEVICE__ **)param_1,
                            pvVar4,1,(_SCATTER_GATHER_LIST *)local_68);
    if (uVar3 == '\0') {
      iVar12 = -0x3fffffff;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 0x200) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
            (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
           (((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
          (((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar9);
      }
      *(undefined1 *)((longlong)pvVar4 + 100) = 0;
    }
    goto LAB_140018827;
  }
  puVar6 = *(undefined8 **)(param_2 + 0x50);
  bVar10 = 0;
  uVar11 = 0;
  iVar12 = -0x3ffffffc;
  if (*(longlong *)(param_2 + 0x28) != 0) {
    for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
      if (uVar11 < *(uint *)(puVar6 + 5)) {
        if ((*(byte *)((longlong)puVar6 + 10) & 5) == 0) {
          lVar5 = MmMapLockedPagesSpecifyCache(puVar6,0,1);
        }
        else {
          lVar5 = puVar6[3];
        }
        if (lVar5 != 0) {
          bVar10 = *(byte *)(lVar5 + uVar11);
          iVar12 = 0;
        }
        break;
      }
      uVar11 = uVar11 - *(uint *)(puVar6 + 5);
    }
  }
  if (iVar12 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar12;
    }
    uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar2 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
       ((((uVar2 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
        (((((uVar2 >> 0xc & 1) == 0 || (uVar9 != 1)) && (((uVar2 >> 0xd & 1) == 0 || (uVar9 != 2))))
         && (((((uVar2 >> 0xe & 1) == 0 || (uVar9 != 3)) &&
              (((uVar2 >> 0xf & 1) == 0 || (uVar9 != 4)))) &&
             ((((uVar2 >> 0x10 & 1) == 0 || (uVar9 != 5)) && (uVar9 < 6))))))))))
    goto LAB_140018827;
    uVar7 = 0x1b;
LAB_14001835f:
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
              &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar9,(char)iVar12);
  }
  else {
    uVar8 = bVar10 | 0x400;
    if ((*(longlong *)(param_2 + 0x38) == 1) && (param_2[0x78] == (PBC_REQUEST)0x1)) {
      uVar8 = bVar10 | 0x600;
    }
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x28),uVar8);
    if ((1 < *(ulonglong *)(param_2 + 0x38)) && (param_2[0x78] == (PBC_REQUEST)0x1)) {
      puVar6 = *(undefined8 **)(param_2 + 0x50);
      bVar10 = 0;
      uVar11 = *(ulonglong *)(param_2 + 0x38) - 1;
      iVar12 = -0x3ffffffc;
      if (uVar11 < *(ulonglong *)(param_2 + 0x28)) {
        for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
          if (uVar11 < *(uint *)(puVar6 + 5)) {
            if ((*(byte *)((longlong)puVar6 + 10) & 5) == 0) {
              lVar5 = MmMapLockedPagesSpecifyCache(puVar6,0,1);
            }
            else {
              lVar5 = puVar6[3];
            }
            if (lVar5 != 0) {
              bVar10 = *(byte *)(lVar5 + uVar11);
              iVar12 = 0;
            }
            break;
          }
          uVar11 = uVar11 - *(uint *)(puVar6 + 5);
        }
      }
      if (iVar12 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar12;
        }
        uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar2 & 0x200) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) ||
           (((((((uVar2 >> 0xb & 1) == 0 || (uVar9 != 0)) &&
               (((uVar2 >> 0xc & 1) == 0 || (uVar9 != 1)))) &&
              (((uVar2 >> 0xd & 1) == 0 || (uVar9 != 2)))) &&
             ((((uVar2 >> 0xe & 1) == 0 || (uVar9 != 3)) &&
              (((uVar2 >> 0xf & 1) == 0 || (uVar9 != 4)))))) &&
            ((((uVar2 >> 0x10 & 1) == 0 || (uVar9 != 5)) && (uVar9 < 6)))))) goto LAB_140018827;
        uVar7 = 0x1c;
        goto LAB_14001835f;
      }
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x30),bVar10 | 0x200);
    }
    if (param_2[0x78] == (PBC_REQUEST)0x0) {
      uVar8 = HWREG<unsigned_long>::Read
                        ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 8));
      HWREG<unsigned_long>::Write
                ((HWREG<unsigned_long> *)(*(longlong *)(param_1 + 0x38) + 0x30),uVar8 | 0x10);
    }
    iVar12 = (**(code **)(WdfFunctions_01015 + 0xcb0))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128),EvtProgramDmaTx,1);
    if (iVar12 < 0) {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 0x200) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
           ((((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
            (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
          ((((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
           (((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
             (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                  &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar9,(char)iVar12);
      }
      (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128));
    }
    else {
      *(undefined1 *)((longlong)pvVar4 + 0x38) = 1;
      *(undefined1 *)((longlong)pvVar4 + 100) = 1;
      iVar12 = (**(code **)(WdfFunctions_01015 + 0x328))
                         (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128),pvVar4);
      if (iVar12 < 0) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 & 0x200) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
              (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
             (((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
            ((((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
             (((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                    &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar9,(char)iVar12);
        }
        (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x128))
        ;
        *(undefined1 *)((longlong)pvVar4 + 0x38) = 0;
        *(undefined1 *)((longlong)pvVar4 + 100) = 0;
      }
    }
  }
LAB_140018827:
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar2 >> 0xb & 1) != 0 && (uVar9 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar9 == 1))))
       || (((((uVar2 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
           ((((uVar2 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar2 >> 0x10 & 1) != 0 && (uVar9 == 5)))))))) || (5 < uVar9)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar9);
  }
  return iVar12;
}



===== LpssCommonBufferCreate @ 1400188c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl LpssCommonBufferCreate(struct PBC_DEVICE * __ptr64,struct WDFDMAENABLER__ *
   __ptr64,unsigned __int64,struct _WDF_OBJECT_ATTRIBUTES * __ptr64,struct WDFCOMMONBUFFER__ *
   __ptr64 * __ptr64) */

long __cdecl
LpssCommonBufferCreate
          (PBC_DEVICE *param_1,WDFDMAENABLER__ *param_2,__uint64 param_3,
          _WDF_OBJECT_ATTRIBUTES *param_4,WDFCOMMONBUFFER__ **param_5)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  iVar5 = 0;
  while( true ) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xa8))
                      (WdfDriverGlobals,param_2,param_3,param_4,param_5);
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar3 = (**(code **)(WdfFunctions_01015 + 0xb8))(WdfDriverGlobals,*param_5);
    if (0x1f < iVar5) break;
    if ((int)param_3 - 1U < (uint)((int)param_3 + -1 + (int)uVar3)) {
      return 0;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar1 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))
           ) || (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
         (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))
          ) || (5 < uVar4)))))) {
      WPP_SF_dDDPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_f6e03ecebb123c37451ad117b22270d2_Traceguids,uVar4,
                   (char)((ulonglong)uVar3 >> 0x20),(char)uVar3,(char)param_3,(char)iVar5);
    }
    iVar5 = iVar5 + 1;
  }
  return 0;
}



===== WPP_SF_dDDPd @ 140018a38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDPd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,8,&param_8,4,
             0);
  return;
}



===== WPP_SF_ddDDP @ 140018ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddDDP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,8,
             0);
  return;
}



===== CheckDmaChannelDisabled @ 140018b28 =====

/* unsigned char __cdecl CheckDmaChannelDisabled(struct PBC_DEVICE * __ptr64,unsigned long) */

uchar __cdecl CheckDmaChannelDisabled(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 1 | 2;
  if ((param_2 & 2) == 0) {
    uVar1 = param_2 & 1;
  }
  uVar1 = uVar1 & *(uint *)(*(longlong *)(param_1 + 0x110) + 0x3a0);
  if (uVar1 != 0) {
    DumpAllRegisters(param_1);
  }
  return uVar1 == 0;
}



===== DisableDmaChannel @ 140018b60 =====

/* unsigned char __cdecl DisableDmaChannel(struct PBC_DEVICE * __ptr64,unsigned long) */

uchar __cdecl DisableDmaChannel(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar1 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar2 >> 0xb & 1) != 0 && (uVar1 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar1 == 1))))
        || ((((uVar2 >> 0xd & 1) != 0 && (uVar1 == 2)) ||
            (((uVar2 >> 0xe & 1) != 0 && (uVar1 == 3)))))) ||
       ((((uVar2 >> 0xf & 1) != 0 && (uVar1 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar1 == 5)))))
       ) || (5 < uVar1)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar1);
  }
  uVar2 = param_2 & 1 | 2;
  if ((param_2 & 2) == 0) {
    uVar2 = param_2 & 1;
  }
  uVar3 = 0;
  if ((uVar2 & *(uint *)(*(longlong *)(param_1 + 0x110) + 0x3a0)) != 0) {
    iVar4 = 0;
    *(uint *)(*(longlong *)(param_1 + 0x110) + 0x3a0) = uVar2 << 8;
    uVar3 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x3a0) & uVar2;
    if (uVar3 != 0) {
      do {
        if (999 < iVar4) break;
        KeStallExecutionProcessor(0x28);
        iVar4 = iVar4 + 1;
        uVar3 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x3a0) & uVar2;
      } while (uVar3 != 0);
      if (uVar3 != 0) {
        DumpAllRegisters(param_1);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar2 >> 0xb & 1) != 0 && (uVar1 == 0)) ||
       (((((uVar2 >> 0xc & 1) != 0 && (uVar1 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar1 == 2))))
        || (((uVar2 >> 0xe & 1) != 0 && (uVar1 == 3)))))) ||
      (((((uVar2 >> 0xf & 1) != 0 && (uVar1 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar1 == 5))))
       || (5 < uVar1)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar1);
  }
  return uVar3 == 0;
}



===== DisableDmaController @ 140018d1c =====

/* unsigned char __cdecl DisableDmaController(struct PBC_DEVICE * __ptr64) */

uchar __cdecl DisableDmaController(PBC_DEVICE *param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  uVar1 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar1 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar4 >> 0xb & 1) != 0 && (uVar1 == 0)) || (((uVar4 >> 0xc & 1) != 0 && (uVar1 == 1))))
        || ((((uVar4 >> 0xd & 1) != 0 && (uVar1 == 2)) ||
            (((uVar4 >> 0xe & 1) != 0 && (uVar1 == 3)))))) ||
       ((((uVar4 >> 0xf & 1) != 0 && (uVar1 == 4)) || (((uVar4 >> 0x10 & 1) != 0 && (uVar1 == 5)))))
       ) || (5 < uVar1)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar1);
  }
  bVar3 = 0;
  if ((*(uint *)(*(longlong *)(param_1 + 0x110) + 0x398) & 1) != 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x398) = 0;
    iVar2 = 0;
    uVar4 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x398) & 1;
    bVar3 = (byte)uVar4;
    if (uVar4 != 0) {
      do {
        if (999 < iVar2) break;
        KeStallExecutionProcessor(0x28);
        iVar2 = iVar2 + 1;
        uVar4 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x398) & 1;
      } while (uVar4 != 0);
      bVar3 = (byte)uVar4;
      if (uVar4 != 0) {
        DumpAllRegisters(param_1);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar4 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar4 >> 0xb & 1) != 0 && (uVar1 == 0)) ||
       (((((uVar4 >> 0xc & 1) != 0 && (uVar1 == 1)) || (((uVar4 >> 0xd & 1) != 0 && (uVar1 == 2))))
        || (((uVar4 >> 0xe & 1) != 0 && (uVar1 == 3)))))) ||
      (((((uVar4 >> 0xf & 1) != 0 && (uVar1 == 4)) || (((uVar4 >> 0x10 & 1) != 0 && (uVar1 == 5))))
       || (5 < uVar1)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar1);
  }
  return bVar3 ^ 1;
}



===== DmaAcknowledgeInterrupts @ 140018ec4 =====

/* void __cdecl DmaAcknowledgeInterrupts(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl DmaAcknowledgeInterrupts(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar2 == 1))))
       || ((((uVar3 >> 0xd & 1) != 0 && (uVar2 == 2)) || (((uVar3 >> 0xe & 1) != 0 && (uVar2 == 3)))
           ))) ||
      (((((uVar3 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar2 == 5))))
       || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  uVar3 = 0;
  if ((((((param_2 >> 0x19 & 1) != 0) &&
        (uVar3 = 1, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  if ((((((param_2 >> 0x1b & 1) != 0) &&
        (uVar3 = uVar3 | 2, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))))
       ) || (5 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  if (uVar3 != 0) {
    *(uint *)(*(longlong *)(param_1 + 0x110) + 0x358) = uVar3;
  }
  uVar3 = 0;
  if ((((((param_2 >> 0x18 & 1) != 0) &&
        (uVar3 = 1, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)))) ||
      ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
       ((((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))
          ) || (5 < uVar2)))))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  if ((((((param_2 >> 0x1a & 1) != 0) &&
        (uVar3 = uVar3 | 2, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 8) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  if (uVar3 != 0) {
    *(uint *)(*(longlong *)(param_1 + 0x110) + 0x338) = uVar3;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar3 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
      (((((uVar3 >> 0xc & 1) != 0 && (uVar2 == 1)) ||
        ((((uVar3 >> 0xd & 1) != 0 && (uVar2 == 2)) || (((uVar3 >> 0xe & 1) != 0 && (uVar2 == 3)))))
        ) || (((((uVar3 >> 0xf & 1) != 0 && (uVar2 == 4)) ||
               (((uVar3 >> 0x10 & 1) != 0 && (uVar2 == 5)))) || (5 < uVar2)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  return;
}



===== DmaDisableInterrupts @ 14001925c =====

/* void __cdecl DmaDisableInterrupts(struct PBC_DEVICE * __ptr64) */

void __cdecl DmaDisableInterrupts(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))))
       ) || (5 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x310) = 0x300;
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x318) = 0x300;
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 800) = 0x300;
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x328) = 0x300;
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x330) = 0x300;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5))))
       || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  return;
}



===== DmaGetInterruptStatus @ 1400193cc =====

/* unsigned long __cdecl DmaGetInterruptStatus(struct PBC_DEVICE * __ptr64) */

ulong __cdecl DmaGetInterruptStatus(PBC_DEVICE *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulong uVar4;
  uint uVar5;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
       (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  lVar3 = *(longlong *)(param_1 + 0x110);
  uVar4 = 0;
  uVar1 = *(uint *)(lVar3 + 0x360);
  if (uVar1 != 0) {
    if ((uVar1 & 0x10) != 0) {
      uVar4 = ((*(uint *)(lVar3 + 0x308) & 2) * 2 | *(uint *)(lVar3 + 0x308) & 1) << 0x19;
    }
    if ((uVar1 & 1) != 0) {
      uVar4 = uVar4 | ((*(uint *)(lVar3 + 0x2e8) & 2) * 2 | *(uint *)(lVar3 + 0x2e8) & 1) << 0x18;
    }
    if ((((((uVar1 & 2) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar2 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          ((((uVar2 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ))) || ((((uVar2 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                   ((((uVar2 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                    (((uVar2 >> 0x10 & 1) != 0 && (uVar5 == 5)))))))) || (5 < uVar5)))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5,
                (char)*(undefined4 *)(lVar3 + 0x2f0));
    }
    if ((((((uVar1 & 4) != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((uVar2 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
        (((((uVar2 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
          ((((uVar2 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar2 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) || (((((uVar2 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                    (((uVar2 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5,
                (char)*(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x2f8));
    }
    if ((uVar1 & 8) != 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar4;
      }
      uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar1 >> 9 & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
             (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))))) ||
           ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
            (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))))) ||
          ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                  &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5,
                  (char)*(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x300));
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  return uVar4;
}



===== DmaSetInterruptMask @ 140019724 =====

/* void __cdecl DmaSetInterruptMask(struct PBC_DEVICE * __ptr64,unsigned long) */

void __cdecl DmaSetInterruptMask(PBC_DEVICE *param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5)))))
       ) || (5 < uVar2)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  *(ulong *)(*(longlong *)(param_1 + 0x110) + 0x330) =
       (param_2 >> 1 & 0x4000000 | param_2 & 0x2000000) >> 0x19 | 0x300;
  *(ulong *)(*(longlong *)(param_1 + 0x110) + 0x310) =
       (param_2 >> 1 & 0x2000000 | param_2 & 0x1000000) >> 0x18 | 0x300;
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x318) = 0x300;
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x328) = 0x300;
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 800) = 0x300;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar2 == 0)) ||
       (((((uVar1 >> 0xc & 1) != 0 && (uVar2 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar2 == 2))))
        || (((uVar1 >> 0xe & 1) != 0 && (uVar2 == 3)))))) ||
      (((((uVar1 >> 0xf & 1) != 0 && (uVar2 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar2 == 5))))
       || (5 < uVar2)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar2);
  }
  return;
}



===== EvtDmaD0Entry @ 1400198d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtDmaD0Entry(struct WDFDMAENABLER__ * __ptr64) */

long __cdecl EvtDmaD0Entry(WDFDMAENABLER__ *param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  uint uVar5;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DMA_ENABLER_CONTEXT_TYPE_INFO_140022088);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  uVar5 = 0xf0;
  if (lVar4 != 0) {
    uVar5 = *(uint *)(lVar4 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))
       ) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  if ((*(uint *)(lVar4 + 0x50) & 0x100) == 0) {
    uVar2 = HWREG<unsigned_long>::Read((HWREG<unsigned_long> *)(*(longlong *)(lVar4 + 0x38) + 4));
    HWREG<unsigned_long>::Write
              ((HWREG<unsigned_long> *)(*(longlong *)(lVar4 + 0x38) + 4),uVar2 & 0xfffffffb);
    HWREG<unsigned_long>::Write((HWREG<unsigned_long> *)(*(longlong *)(lVar4 + 0x38) + 4),uVar2 | 4)
    ;
    *(undefined4 *)(*(longlong *)(lVar4 + 0x110) + 0x398) = 1;
    *(undefined1 *)(lVar4 + 0x118) = 1;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 >> 9 & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
              (((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)))) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
         || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
        (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))
       ) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  return 0;
}



===== EvtDmaD0Exit @ 140019b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtDmaD0Exit(struct WDFDMAENABLER__ * __ptr64) */

long __cdecl EvtDmaD0Exit(WDFDMAENABLER__ *param_1)

{
  uint uVar1;
  uchar uVar2;
  undefined8 *puVar3;
  PBC_DEVICE *pPVar4;
  uint uVar5;
  long lVar6;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DMA_ENABLER_CONTEXT_TYPE_INFO_140022088);
  pPVar4 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar3,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  uVar5 = 0xf0;
  if (pPVar4 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(pPVar4 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1))))
        || ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
       ((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))))
       ) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  lVar6 = 0;
  if (pPVar4[0x118] != (PBC_DEVICE)0x0) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))
         )) || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                  (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
    }
    uVar2 = DisableDmaChannel(pPVar4,3);
    if (uVar2 == '\0') {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
      }
      lVar6 = -0x3fffffff;
    }
    uVar2 = DisableDmaController(pPVar4);
    if (uVar2 == '\0') {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
           ((((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
      }
      lVar6 = -0x3fffffff;
    }
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x310) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x318) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 800) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x328) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x330) = 0x300;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x338) = 3;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x340) = 3;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x348) = 3;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x350) = 3;
    *(undefined4 *)(*(longlong *)(pPVar4 + 0x110) + 0x358) = 3;
    pPVar4[0x118] = (PBC_DEVICE)0x0;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar1 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       ((((uVar1 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar1 >> 0xd & 1) != 0 && (uVar5 == 2))))))
      || ((((uVar1 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
          (((((uVar1 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar1 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  return lVar6;
}



===== EvtProgramDmaRx @ 140019f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl EvtProgramDmaRx(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,struct _SCATTER_GATHER_LIST * __ptr64) */

uchar __cdecl
EvtProgramDmaRx(WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
               _WDF_DMA_DIRECTION param_4,_SCATTER_GATHER_LIST *param_5)

{
  uchar uVar1;
  PBC_DEVICE *pPVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  byte bVar7;
  byte bVar6;
  longlong lVar8;
  undefined1 local_res18 [8];
  
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar8 == 0) {
    uVar5 = 0xf0;
  }
  else {
    lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar5 = *(uint *)(lVar8 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) ||
      (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  pPVar2 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  bVar7 = 0;
  bVar6 = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
      ((((((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2))))
        || (((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
       (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5))))
        || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x148));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
           ((((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
            ((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
             (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)))))))))) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  if (*(int *)((longlong)param_3 + 4) == 0) {
    uVar1 = CheckDmaChannelDisabled(pPVar2,2);
    if (uVar1 == '\x01') {
      *(undefined8 *)((longlong)param_3 + 0x58) = 0;
      if (*(int *)param_5 != 0) {
        lVar8 = 0;
        uVar4 = 0;
        do {
          uVar3 = (int)uVar4 + 1;
          lVar8 = lVar8 + (ulonglong)*(uint *)(param_5 + uVar4 * 0x18 + 0x18);
          *(longlong *)((longlong)param_3 + 0x58) = lVar8;
          uVar4 = (ulonglong)uVar3;
        } while (uVar3 < *(uint *)param_5);
      }
      FillDmaRxLliBuffer(pPVar2,param_3,param_5);
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x60));
      ProgramDmaAndExecute(pPVar2,param_3);
      (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x60));
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001a3e6;
      uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar3 >> 9 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
           ((((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            ((((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
             (((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)))))))) ||
          ((((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                 &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
      }
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
             (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
            (((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
           (((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
          (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                 &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
      }
      if (*(char *)((longlong)param_3 + 0x38) == '\x01') {
        (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,param_1,0,local_res18);
        (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,param_1);
        *(undefined1 *)((longlong)param_3 + 0x38) = 0;
      }
      PbcFailDevice(pPVar2);
      bVar7 = 1;
    }
  }
  bVar6 = bVar7;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || (((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
      ((((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
       (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5))))
        || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
LAB_14001a3e6:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x148));
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar3 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          ((((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ))) || ((((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                   (((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)))))) ||
        ((((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1))))
         || ((((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
             (((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
        (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)))
          ) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
    }
  }
  return bVar6 ^ 1;
}



===== EvtProgramDmaTx @ 14001a520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl EvtProgramDmaTx(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,struct _SCATTER_GATHER_LIST * __ptr64) */

uchar __cdecl
EvtProgramDmaTx(WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
               _WDF_DMA_DIRECTION param_4,_SCATTER_GATHER_LIST *param_5)

{
  uchar uVar1;
  PBC_DEVICE *pPVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  byte bVar6;
  longlong lVar7;
  undefined1 local_res18 [16];
  
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  if (lVar7 == 0) {
    uVar5 = 0xf0;
  }
  else {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
    uVar5 = *(uint *)(lVar7 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) ||
      (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  pPVar2 = (PBC_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_PBC_DEVICE_TYPE_INFO_1400220b0);
  bVar6 = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
      ((((((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2))))
        || (((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
       (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5))))
        || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x150));
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
           ((((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
            ((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
             (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)))))))))) || (5 < uVar5)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  if (*(int *)((longlong)param_3 + 4) == 0) {
    uVar1 = CheckDmaChannelDisabled(pPVar2,1);
    if (uVar1 == '\x01') {
      *(undefined8 *)((longlong)param_3 + 0x58) = 0;
      if (*(int *)param_5 != 0) {
        lVar7 = 0;
        uVar4 = 0;
        do {
          uVar3 = (int)uVar4 + 1;
          lVar7 = lVar7 + (ulonglong)*(uint *)(param_5 + uVar4 * 0x18 + 0x18);
          *(longlong *)((longlong)param_3 + 0x58) = lVar7;
          uVar4 = (ulonglong)uVar3;
        } while (uVar3 < *(uint *)param_5);
      }
      FillDmaTxLliBuffer(pPVar2,param_3,param_5);
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x60));
      ProgramDmaAndExecute(pPVar2,param_3);
      (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x60));
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001a9fb;
      uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
      if ((((uVar3 >> 9 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
           ((((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            ((((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
             (((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)))))))) ||
          ((((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                 &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
      }
    }
    else {
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 9 & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
             (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
            (((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
           (((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)))) ||
          (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                 &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
      }
      if (*(char *)((longlong)param_3 + 0x38) == '\x01') {
        (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,param_1,0,local_res18);
        (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,param_1);
        *(undefined1 *)((longlong)param_3 + 0x38) = 0;
      }
      PbcFailDevice(pPVar2);
      bVar6 = 1;
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 8 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || (((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
      ((((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
       (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5))))
        || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
LAB_14001a9fb:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(pPVar2 + 0x150));
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar3 >> 8 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          ((((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ))) || ((((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                   (((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)))))) ||
        ((((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar3 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar3 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar3 >> 0xc & 1) != 0 && (uVar5 == 1))))
         || ((((uVar3 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
             (((uVar3 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
        (((((uVar3 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar3 >> 0x10 & 1) != 0 && (uVar5 == 5)))
          ) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
    }
  }
  return bVar6 ^ 1;
}



===== FillDmaRxLliBuffer @ 14001ab30 =====

/* void __cdecl FillDmaRxLliBuffer(struct PBC_DEVICE * __ptr64,struct _DMA_TRANSACTION_CONTEXT *
   __ptr64,struct _SCATTER_GATHER_LIST * __ptr64) */

void __cdecl
FillDmaRxLliBuffer(PBC_DEVICE *param_1,_DMA_TRANSACTION_CONTEXT *param_2,
                  _SCATTER_GATHER_LIST *param_3)

{
  undefined2 uVar1;
  longlong lVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint local_res20;
  uint local_78;
  ulonglong local_70;
  longlong local_68;
  undefined8 local_60;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar6 & 0x800) != 0 && (uVar5 == 0)) || (((uVar6 & 0x1000) != 0 && (uVar5 == 1)))) ||
       ((((uVar6 & 0x2000) != 0 && (uVar5 == 2)) || (((uVar6 >> 0xe & 1) != 0 && (uVar5 == 3))))))
      || (((((uVar6 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar6 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  local_70 = *(ulonglong *)(param_2 + 0x40);
  local_res20 = 0;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar6 & 0x800) != 0 && (uVar5 == 0)) ||
       (((((uVar6 & 0x1000) != 0 && (uVar5 == 1)) || (((uVar6 & 0x2000) != 0 && (uVar5 == 2)))) ||
        (((uVar6 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
      (((((uVar6 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
              &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5,(char)local_70);
  }
  local_78 = *(uint *)param_3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar6 & 0x800) != 0 && (uVar5 == 0)) || (((uVar6 & 0x1000) != 0 && (uVar5 == 1)))) ||
      ((((uVar6 & 0x2000) != 0 && (uVar5 == 2)) ||
       (((((uVar6 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
         ((((uVar6 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar5 == 5)))
          ))) || (5 < uVar5)))))))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
              &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5,(char)local_78);
  }
  if (0x3e < local_78) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((((uVar6 & 0x800) != 0 && (uVar5 == 0)) || (((uVar6 & 0x1000) != 0 && (uVar5 == 1)))) ||
          (((uVar6 & 0x2000) != 0 && (uVar5 == 2)))) || (((uVar6 >> 0xe & 1) != 0 && (uVar5 == 3))))
        || (((((uVar6 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
             (((uVar6 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
    }
    local_78 = 0x3e;
  }
  local_68 = *(longlong *)(param_2 + 0x30);
  uVar6 = 0;
  piVar3 = *(int **)(param_2 + 0x28);
  uVar8 = 0;
  local_60 = 0;
  while (local_68 = local_68 + 0x40, local_70 < *(ulonglong *)(param_2 + 0x48)) {
    if (uVar6 == 0) {
      local_60 = *(longlong *)(param_3 + uVar8 * 0x18 + 0x10);
      uVar6 = *(uint *)(param_3 + uVar8 * 0x18 + 0x18);
    }
    uVar9 = 0x1ffff;
    if (uVar6 < 0x1ffff) {
      uVar9 = uVar6;
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 0x200) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar7 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
          ((((uVar7 >> 0xc & 1) != 0 && (uVar5 == 1)) || (((uVar7 >> 0xd & 1) != 0 && (uVar5 == 2)))
           ))) || ((((uVar7 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
                   ((((uVar7 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                    (((uVar7 >> 0x10 & 1) != 0 && (uVar5 == 5)))))))) || (5 < uVar5)))) {
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                 &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5,(char)local_res20,
                 (char)uVar9);
    }
    local_res20 = local_res20 + 1;
    *piVar3 = *(int *)(param_1 + 0x18) + 0x10;
    piVar3[1] = *(int *)(param_1 + 0x1c);
    piVar3[3] = local_60._4_4_;
    piVar3[2] = (int)local_60;
    piVar3[7] = uVar9 & 0x1ffff;
    local_70 = local_70 + uVar9;
    piVar3[6] = 0x18202404;
    if (local_70 == *(ulonglong *)(param_2 + 0x48)) {
      piVar3[4] = 0;
      piVar3[5] = 0;
      piVar3[6] = 0x18202405;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 0x200) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar7 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            ((((uVar7 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
             (((uVar7 >> 0xd & 1) != 0 && (uVar5 == 2)))))) ||
           ((((uVar7 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
            ((((uVar7 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
             (((uVar7 >> 0x10 & 1) != 0 && (uVar5 == 5)))))))) || (5 < uVar5)))) {
        uVar1 = 0x47;
        goto LAB_14001b0c2;
      }
    }
    else if ((local_70 < *(ulonglong *)(param_2 + 0x48)) && (local_res20 == 0x3e)) {
      piVar3[4] = 0;
      piVar3[5] = 0;
      piVar3[6] = 0x18202405;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 0x200) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar7 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
            (((uVar7 >> 0xc & 1) != 0 && (uVar5 == 1)))) ||
           ((((uVar7 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
            (((uVar7 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
          (((((uVar7 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
            (((uVar7 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
        uVar1 = 0x48;
LAB_14001b0c2:
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
                 &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
      }
    }
    else {
      *(longlong *)(piVar3 + 4) = local_68;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 & 0x200) != 0 &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
         (((((uVar7 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
           (((((uVar7 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
             (((uVar7 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
            (((uVar7 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
          ((((uVar7 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           ((((uVar7 >> 0x10 & 1) != 0 && (uVar5 == 5)) || (5 < uVar5)))))))) {
        uVar1 = 0x49;
        goto LAB_14001b0c2;
      }
    }
    piVar3[0xf] = (piVar3[6] & 1U) * 2 | 1;
    piVar3 = piVar3 + 0x10;
    uVar6 = uVar6 - uVar9;
    if (((uVar6 == 0) && (uVar7 = (int)uVar8 + 1, uVar8 = (ulonglong)uVar7, uVar7 == local_78)) ||
       (local_60 = local_60 + (ulonglong)uVar9, 0x3d < local_res20)) break;
  }
  puVar4 = *(undefined4 **)(param_2 + 0x28);
  lVar2 = *(longlong *)(param_2 + 0x30);
  for (; local_res20 != 0; local_res20 = local_res20 - 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar6 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
       ((4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29) &&
        ((((((uVar6 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar5 == 1)))
           ) || ((((uVar6 >> 0xd & 1) != 0 && (uVar5 == 2)) ||
                 (((uVar6 >> 0xe & 1) != 0 && (uVar5 == 3)))))) ||
         (((((uVar6 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
           (((uVar6 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))))) {
      WPP_SF_dDDDDDDDDDDD(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x4a,
                          &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5,
                          (char)((ulonglong)lVar2 >> 0x20),(char)lVar2,(char)puVar4[1],(char)*puVar4
                          ,(char)puVar4[3],(char)puVar4[2],(char)puVar4[5],(char)puVar4[4],
                          (char)puVar4[7],(char)puVar4[6],(char)puVar4[0xf]);
    }
    puVar4 = puVar4 + 0x10;
    lVar2 = lVar2 + 0x40;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) &&
     (((((uVar6 >> 0xb & 1) != 0 && (uVar5 == 0)) ||
       ((((uVar6 >> 0xc & 1) != 0 && (uVar5 == 1)) ||
        ((((uVar6 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar6 >> 0xe & 1) != 0 && (uVar5 == 3)))))
        ))) || (((((uVar6 >> 0xf & 1) != 0 && (uVar5 == 4)) ||
                 (((uVar6 >> 0x10 & 1) != 0 && (uVar5 == 5)))) || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x4b,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  return;
}



===== FillDmaTxLliBuffer @ 14001b2d4 =====

/* void __cdecl FillDmaTxLliBuffer(struct PBC_DEVICE * __ptr64,struct _DMA_TRANSACTION_CONTEXT *
   __ptr64,struct _SCATTER_GATHER_LIST * __ptr64) */

void __cdecl
FillDmaTxLliBuffer(PBC_DEVICE *param_1,_DMA_TRANSACTION_CONTEXT *param_2,
                  _SCATTER_GATHER_LIST *param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  char *pcVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  int *piVar13;
  uint local_res10;
  uint local_res20;
  undefined1 uVar14;
  uint local_78;
  uint local_74;
  longlong local_70;
  undefined8 local_68;
  
  uVar9 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar9 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar6 & 0x800) != 0 && (uVar9 == 0)) || (((uVar6 & 0x1000) != 0 && (uVar9 == 1)))) ||
       ((((uVar6 & 0x2000) != 0 && (uVar9 == 2)) || (((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3))))))
      || (((((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
           (((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9);
  }
  local_res10 = 0;
  uVar12 = *(ulonglong *)(param_2 + 0x40);
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar6 & 0x800) != 0 && (uVar9 == 0)) ||
       ((((uVar6 & 0x1000) != 0 && (uVar9 == 1)) || (((uVar6 & 0x2000) != 0 && (uVar9 == 2)))))) ||
      ((((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
       (((((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        || (5 < uVar9)))))))) {
    WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
              &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,(char)uVar12);
  }
  local_74 = *(uint *)param_3;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar6 & 0x800) != 0 && (uVar9 == 0)) || (((uVar6 & 0x1000) != 0 && (uVar9 == 1)))) ||
        (((uVar6 & 0x2000) != 0 && (uVar9 == 2)))) ||
       ((((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
        ((((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5))))
        )))) || (5 < uVar9)))) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,(char)local_74);
  }
  if (0x3e < local_74) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar6 & 0x800) != 0 && (uVar9 == 0)) || (((uVar6 & 0x1000) != 0 && (uVar9 == 1)))) ||
        ((((uVar6 & 0x2000) != 0 && (uVar9 == 2)) ||
         ((((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
          (((((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9);
    }
    local_74 = 0x3e;
  }
  local_70 = *(longlong *)(param_2 + 0x30);
  piVar13 = *(int **)(param_2 + 0x28);
  uVar11 = 0;
  local_res20 = 0;
  lVar5 = 0;
  local_78 = 0;
  local_68 = 0;
  do {
    local_70 = local_70 + 0x40;
    uVar3 = *(ulonglong *)(param_2 + 0x50);
    if (uVar3 <= uVar12) break;
    if (local_78 == 0) {
      lVar5 = *(longlong *)(param_3 + uVar11 * 0x18 + 0x10);
      local_78 = *(uint *)(param_3 + uVar11 * 0x18 + 0x18);
      local_68 = lVar5;
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
             (((uVar6 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
           (((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
          (((((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
            (((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
        WPP_SF_ddDDP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                     &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,(char)uVar11,
                     (char)((ulonglong)lVar5 >> 0x20),(char)lVar5,(char)local_78);
        uVar3 = *(ulonglong *)(param_2 + 0x50);
      }
    }
    uVar6 = 0x1ffff;
    if (local_78 < 0x1ffff) {
      uVar6 = local_78;
    }
    uVar14 = (undefined1)local_res10;
    if (uVar12 == 0) {
      if ((uVar3 == 1) && (param_2[8] == (_DMA_TRANSACTION_CONTEXT)0x1)) {
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              (((uVar6 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
            ((((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
             (((((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          uVar4 = 0x2e;
LAB_14001b77a:
          pcVar10 = "RDREQ";
          if (*(longlong *)(param_2 + 0x48) != 0) {
            pcVar10 = "WRITE";
          }
          WPP_SF_dds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                     &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,uVar14,pcVar10);
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0 &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
              ((((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
                 ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                  (((uVar6 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
                ((((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                 (((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)))))) ||
               ((((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))) {
        uVar4 = 0x2f;
        goto LAB_14001b77a;
      }
      iVar2 = *(int *)(param_1 + 0x18) + 0x228;
LAB_14001b890:
      uVar6 = 1;
      *piVar13 = iVar2;
      piVar13[1] = *(int *)(param_1 + 0x1c);
      uVar7 = 2;
    }
    else {
      if ((uVar12 == uVar3 - 1) && (param_2[8] == (_DMA_TRANSACTION_CONTEXT)0x1)) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0 &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
           ((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
                (((uVar6 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
               (((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
              (((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)))) ||
             ((((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
          pcVar10 = "RDREQ";
          if (uVar12 < *(ulonglong *)(param_2 + 0x48)) {
            pcVar10 = "WRITE";
          }
          WPP_SF_dds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                     &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,uVar14,pcVar10);
        }
        iVar2 = *(int *)(param_1 + 0x18) + 0x230;
        goto LAB_14001b890;
      }
      if (uVar12 < *(ulonglong *)(param_2 + 0x48)) {
        uVar7 = 0;
        *piVar13 = (int)lVar5;
        iVar2 = local_68._4_4_;
      }
      else {
        uVar7 = 2;
        uVar1 = 0x7fff;
        if (uVar6 < 0x7fff) {
          uVar1 = uVar6;
        }
        uVar6 = uVar1;
        *piVar13 = *(int *)(param_1 + 0x18) + 0x22c;
        iVar2 = *(int *)(param_1 + 0x1c);
      }
      piVar13[1] = iVar2;
      if ((uVar6 + uVar12 == *(longlong *)(param_2 + 0x50)) &&
         (param_2[8] == (_DMA_TRANSACTION_CONTEXT)0x1)) {
        uVar6 = uVar6 - 1;
      }
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 9 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)))) ||
           (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
          ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
           (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
             (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
        pcVar10 = "RDREQ";
        if (uVar12 < *(ulonglong *)(param_2 + 0x48)) {
          pcVar10 = "WRITE";
        }
        WPP_SF_ddsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                    &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,uVar14,pcVar10,
                    (char)uVar6);
      }
    }
    piVar13[2] = *(int *)(param_1 + 0x18) + 0x10;
    piVar13[3] = *(int *)(param_1 + 0x1c);
    piVar13[7] = uVar6 << (sbyte)uVar7 & 0x1ffff;
    local_res10 = local_res10 + 1;
    piVar13[6] = (uVar7 | 0xc086090) * 2 | -(uint)(uVar7 != 0) & 0x400;
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
          ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))
           ))))) ||
        (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) || (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))
          ) || (5 < uVar9)))))) {
      WPP_SF_dPPPPPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                     &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,(char)uVar12,
                     (char)*(undefined8 *)(param_2 + 0x50),(char)*(undefined8 *)(param_2 + 0x48),
                     (char)uVar6,(char)uVar6 + (char)uVar12,param_2[8]);
    }
    uVar12 = uVar12 + uVar6;
    if (uVar12 == *(ulonglong *)(param_2 + 0x50)) {
      if (param_2[8] == (_DMA_TRANSACTION_CONTEXT)0x1) {
        piVar13[6] = piVar13[6] & 0xfffffffe;
        piVar13[4] = 0;
        piVar13[5] = 0;
        piVar13[0xf] = 3;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              (((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
                (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
               ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))))))))) || (5 < uVar9)))) {
          uVar4 = 0x33;
          goto LAB_14001bd4b;
        }
      }
      else {
        if (*(longlong *)(param_2 + 0x48) != 0) goto LAB_14001bc2a;
        piVar13[6] = piVar13[6] & 0xfffffffe;
        piVar13[4] = 0;
        piVar13[5] = 0;
        piVar13[0xf] = 3;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
            (((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              ((((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)) ||
               (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))))) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          uVar4 = 0x34;
          goto LAB_14001bd4b;
        }
      }
    }
    else {
LAB_14001bc2a:
      if ((uVar12 < *(ulonglong *)(param_2 + 0x50)) && (local_res10 == 0x3e)) {
        piVar13[6] = piVar13[6] | 1;
        piVar13[4] = 0;
        piVar13[5] = 0;
        piVar13[0xf] = 3;
        if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0)) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           (((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
             ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
              (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
            ((((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
             (((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
               (((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
          uVar4 = 0x35;
LAB_14001bd4b:
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                   &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9);
        }
      }
      else {
        piVar13[6] = piVar13[6] & 0xfffffffe;
        *(longlong *)(piVar13 + 4) = local_70;
        piVar13[0xf] = 1;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x200) != 0 &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
           ((((((uVar1 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
              ((((uVar1 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
               (((uVar1 >> 0xd & 1) != 0 && (uVar9 == 2)))))) ||
             (((uVar1 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
            ((((uVar1 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
             ((((uVar1 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))))) {
          uVar4 = 0x36;
          goto LAB_14001bd4b;
        }
      }
    }
    uVar11 = (ulonglong)local_res20;
    piVar13 = piVar13 + 0x10;
    local_78 = local_78 - uVar6;
    if (local_78 == 0) {
      local_res20 = local_res20 + 1;
      uVar11 = (ulonglong)local_res20;
      if (local_res20 == local_74) break;
    }
    else if (uVar12 < *(ulonglong *)(param_2 + 0x48)) {
      lVar5 = lVar5 + (ulonglong)uVar6;
      local_68 = lVar5;
    }
  } while (local_res10 < 0x3e);
  if ((uVar12 == *(ulonglong *)(param_2 + 0x48)) && (param_2[8] == (_DMA_TRANSACTION_CONTEXT)0x0)) {
    local_res10 = local_res10 + 1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0 &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
            (((uVar6 >> 0xd & 1) != 0 && (uVar9 == 2)))) ||
           (((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)))) ||
          (((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)))))) ||
        ((((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)) || (5 < uVar9)))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,(char)local_res10);
    }
    piVar13[0xf] = 2;
    *piVar13 = *(int *)(param_1 + 0x18) + 0x230;
    piVar13[1] = *(int *)(param_1 + 0x1c);
    piVar13[2] = *(int *)(param_1 + 0x18) + 0x208;
    iVar2 = *(int *)(param_1 + 0x1c);
    piVar13[4] = 0;
    piVar13[5] = 0;
    piVar13[3] = iVar2;
    piVar13[7] = 4;
    piVar13[6] = 0x18100524;
  }
  puVar8 = *(undefined4 **)(param_2 + 0x28);
  lVar5 = *(longlong *)(param_2 + 0x30);
  for (; local_res10 != 0; local_res10 = local_res10 - 1) {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar6 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c), (uVar6 >> 9 & 1) != 0)) &&
        (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) &&
       (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
         ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) || (((uVar6 >> 0xd & 1) != 0 && (uVar9 == 2))))
         )) || ((((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)) ||
                (((((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                  (((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))))) {
      WPP_SF_dDDDDDDDDDDD(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x38,
                          &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9,
                          (char)((ulonglong)lVar5 >> 0x20),(char)lVar5,(char)puVar8[1],(char)*puVar8
                          ,(char)puVar8[3],(char)puVar8[2],(char)puVar8[5],(char)puVar8[4],
                          (char)puVar8[7],(char)puVar8[6],(char)puVar8[0xf]);
    }
    puVar8 = puVar8 + 0x10;
    lVar5 = lVar5 + 0x40;
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) &&
     (((((uVar6 >> 0xb & 1) != 0 && (uVar9 == 0)) ||
       ((((uVar6 >> 0xc & 1) != 0 && (uVar9 == 1)) ||
        ((((uVar6 >> 0xd & 1) != 0 && (uVar9 == 2)) || (((uVar6 >> 0xe & 1) != 0 && (uVar9 == 3)))))
        ))) || (((((uVar6 >> 0xf & 1) != 0 && (uVar9 == 4)) ||
                 (((uVar6 >> 0x10 & 1) != 0 && (uVar9 == 5)))) || (5 < uVar9)))))) {
    WPP_SF_d(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x39,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar9);
  }
  return;
}



===== GetCurrentDmaTransferLeft @ 14001c078 =====

/* unsigned __int64 __cdecl GetCurrentDmaTransferLeft(struct PBC_DEVICE * __ptr64,struct
   _DMA_TRANSACTION_CONTEXT * __ptr64) */

__uint64 __cdecl GetCurrentDmaTransferLeft(PBC_DEVICE *param_1,_DMA_TRANSACTION_CONTEXT *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  undefined4 *puVar9;
  longlong local_res8;
  undefined8 local_res18;
  
  uVar7 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar7 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)))) ||
      (((((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)) || (((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3))))
       || (((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
            (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar7);
  }
  iVar1 = *(int *)param_2;
  uVar6 = 0;
  puVar9 = *(undefined4 **)(param_2 + 0x28);
  lVar8 = 0;
  local_res18 = *(longlong *)(param_2 + 0x30);
  local_res8 = 0;
  do {
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
         ((((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1)) || (((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2))))
         )) || ((((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
                (((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                  (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
      WPP_SF_dDDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                          &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar7,
                          (char)((ulonglong)local_res18 >> 0x20),(char)local_res18,(char)puVar9[1],
                          (char)*puVar9,(char)puVar9[3],(char)puVar9[2],(char)puVar9[5],
                          (char)puVar9[4],(char)puVar9[7],(char)puVar9[6],(char)puVar9[0xf]);
    }
    uVar2 = puVar9[6];
    bVar5 = (byte)(uVar2 >> 1);
    if ((uVar2 & 0x300000) != 0x100000) {
      bVar5 = (byte)(uVar2 >> 4);
    }
    if (((uint)puVar9[7] >> 0x11 & 1) == 0) {
      lVar8 = *(longlong *)(param_1 + 0x110);
      uVar4 = (ulonglong)(-(uint)(iVar1 != 1) & 0x58);
      iVar1 = *(int *)(uVar4 + 0x14 + lVar8);
      iVar3 = *(int *)(uVar4 + 0x10 + lVar8);
      uVar6 = *(uint *)(uVar4 + 0x1c + lVar8);
      if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 9 & 1) != 0)) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
         (((((uVar2 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar7 == 1)))
           ) || (((((uVar2 >> 0xd & 1) != 0 && (uVar7 == 2)) ||
                  (((uVar2 >> 0xe & 1) != 0 && (uVar7 == 3)))) ||
                 (((((uVar2 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
                   (((uVar2 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
        WPP_SF_dDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
                         &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar7,
                         (char)*(undefined4 *)(uVar4 + 4 + lVar8),
                         (char)*(undefined4 *)(uVar4 + lVar8),
                         (char)*(undefined4 *)(uVar4 + 0xc + lVar8),
                         (char)*(undefined4 *)(uVar4 + 8 + lVar8),(char)iVar1,(char)iVar3,
                         (char)uVar6,(char)*(undefined4 *)(uVar4 + 0x18 + lVar8));
      }
      if ((iVar3 == (int)local_res18) && (iVar1 == local_res18._4_4_)) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001c532;
        uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
        if ((((uVar6 >> 9 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) ||
              ((((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1)) ||
               (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)))))) ||
             ((((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
              (((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)))))) ||
            ((((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                   &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar7);
        }
      }
      else if ((puVar9[0xf] & 1) != 0) {
        lVar8 = local_res8 + (ulonglong)((uVar6 & 0x1ffff) >> (bVar5 & 7));
        local_res8 = lVar8;
        break;
      }
      lVar8 = local_res8;
      break;
    }
    if ((puVar9[0xf] & 1) != 0) {
      lVar8 = lVar8 + (ulonglong)((puVar9[7] & 0x1ffff) >> (bVar5 & 7));
      local_res8 = lVar8;
    }
    if ((puVar9[0xf] & 2) != 0) break;
    local_res18 = local_res18 + 0x40;
    uVar6 = uVar6 + 1;
    puVar9 = puVar9 + 0x10;
  } while (uVar6 < 0x3f);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar6 >> 9 & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
        (((((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)) || (((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4))))
         || ((((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)) || (5 < uVar7)))))))) {
      WPP_SF_dP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar7,(char)lVar8);
    }
    if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (uVar6 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar6 >> 10 & 1) != 0)) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((((((uVar6 >> 0xb & 1) != 0 && (uVar7 == 0)) || (((uVar6 >> 0xc & 1) != 0 && (uVar7 == 1))))
         || (((uVar6 >> 0xd & 1) != 0 && (uVar7 == 2)))) ||
        ((((uVar6 >> 0xe & 1) != 0 && (uVar7 == 3)) ||
         (((((uVar6 >> 0xf & 1) != 0 && (uVar7 == 4)) ||
           (((uVar6 >> 0x10 & 1) != 0 && (uVar7 == 5)))) || (5 < uVar7)))))))) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
               &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar7);
    }
  }
LAB_14001c532:
  return *(longlong *)(param_2 + 0x58) - local_res8;
}



===== ProgramDmaAndExecute @ 14001c594 =====

/* void __cdecl ProgramDmaAndExecute(struct PBC_DEVICE * __ptr64,struct _DMA_TRANSACTION_CONTEXT *
   __ptr64) */

void __cdecl ProgramDmaAndExecute(PBC_DEVICE *param_1,_DMA_TRANSACTION_CONTEXT *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  uVar5 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar5 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar7 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar7 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || (((uVar7 >> 0xd & 1) != 0 && (uVar5 == 2)))) ||
      ((((uVar7 >> 0xe & 1) != 0 && (uVar5 == 3)) ||
       (((((uVar7 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar7 >> 0x10 & 1) != 0 && (uVar5 == 5))))
        || (5 < uVar5)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  iVar1 = *(int *)param_2;
  uVar7 = (iVar1 != 1) + 1;
  *(uint *)(*(longlong *)(param_1 + 0x110) + 0x340) = uVar7;
  uVar6 = (ulonglong)(-(uint)(iVar1 != 1) & 0x58);
  *(uint *)(*(longlong *)(param_1 + 0x110) + 0x338) = uVar7;
  *(uint *)(*(longlong *)(param_1 + 0x110) + 0x358) = uVar7;
  *(uint *)(*(longlong *)(param_1 + 0x110) + 0x350) = uVar7;
  *(uint *)(*(longlong *)(param_1 + 0x110) + 0x348) = uVar7;
  puVar2 = *(undefined4 **)(param_2 + 0x28);
  iVar1 = *(int *)param_2;
  uVar3 = *(undefined8 *)(param_2 + 0x30);
  *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x44 + uVar6) = 1;
  uVar4 = 0x200028;
  if (iVar1 != 1) {
    uVar4 = 0x100028;
  }
  *(undefined4 *)(uVar6 + 0x40 + *(longlong *)(param_1 + 0x110)) = uVar4;
  if ((puVar2[5] == 0) && (puVar2[4] == 0)) {
    puVar2[6] = puVar2[6] & 0xe7ffffff;
  }
  *(undefined4 *)(uVar6 + 0x18 + *(longlong *)(param_1 + 0x110)) = puVar2[6];
  *(undefined4 *)(uVar6 + 0x1c + *(longlong *)(param_1 + 0x110)) = puVar2[7];
  if ((puVar2[6] & 0x10000000) == 0) {
    *(undefined4 *)(uVar6 + *(longlong *)(param_1 + 0x110)) = *puVar2;
    *(undefined4 *)(uVar6 + 4 + *(longlong *)(param_1 + 0x110)) = puVar2[1];
  }
  else {
    *(undefined4 *)(uVar6 + *(longlong *)(param_1 + 0x110)) = 0;
    *(undefined4 *)(uVar6 + 4 + *(longlong *)(param_1 + 0x110)) = 0;
  }
  if ((puVar2[6] & 0x8000000) == 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 8 + uVar6) = puVar2[2];
    *(undefined4 *)(uVar6 + 0xc + *(longlong *)(param_1 + 0x110)) = puVar2[3];
  }
  else {
    *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 8 + uVar6) = 0;
    *(undefined4 *)(uVar6 + 0xc + *(longlong *)(param_1 + 0x110)) = 0;
  }
  if ((puVar2[6] & 0x18000000) == 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x110) + 0x10 + uVar6) = 0;
    *(undefined4 *)(uVar6 + 0x14 + *(longlong *)(param_1 + 0x110)) = 0;
  }
  else {
    *(int *)(*(longlong *)(param_1 + 0x110) + 0x10 + uVar6) = (int)uVar3;
    *(int *)(uVar6 + 0x14 + *(longlong *)(param_1 + 0x110)) = (int)((ulonglong)uVar3 >> 0x20);
  }
  *(uint *)(*(longlong *)(param_1 + 0x110) + 0x3a0) = uVar7 * 0x100 | uVar7;
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar7 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar7 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar7 >> 0xb & 1) != 0 && (uVar5 == 0)) || (((uVar7 >> 0xc & 1) != 0 && (uVar5 == 1))))
       || ((((uVar7 >> 0xd & 1) != 0 && (uVar5 == 2)) || (((uVar7 >> 0xe & 1) != 0 && (uVar5 == 3)))
           ))) ||
      (((((uVar7 >> 0xf & 1) != 0 && (uVar5 == 4)) || (((uVar7 >> 0x10 & 1) != 0 && (uVar5 == 5))))
       || (5 < uVar5)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar5);
  }
  return;
}



===== SuspendDmaChannel @ 14001c860 =====

/* unsigned char __cdecl SuspendDmaChannel(struct PBC_DEVICE * __ptr64,unsigned long,unsigned char)
    */

uchar __cdecl SuspendDmaChannel(PBC_DEVICE *param_1,ulong param_2,uchar param_3)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uchar uVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  uVar6 = '\x01';
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar5 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar5 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar5 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar5 >> 0xc & 1) != 0 && (uVar4 == 1))))
       || (((uVar5 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
      ((((uVar5 >> 0xe & 1) != 0 && (uVar4 == 3)) ||
       (((((uVar5 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar5 >> 0x10 & 1) != 0 && (uVar4 == 5))))
        || (5 < uVar4)))))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar4);
  }
  uVar8 = 1;
  uVar5 = 1;
  if ((param_2 & 1) != 0) {
    if (param_3 == '\0') {
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x110) + 0x40);
      *puVar1 = *puVar1 | 0x100;
    }
    else {
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x110) + 0x98);
      *puVar1 = *puVar1 | 0x500;
      uVar8 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x98);
      for (iVar7 = 0; (uVar8 = uVar8 >> 9 & 1, uVar8 == 0 && (iVar7 < 1000)); iVar7 = iVar7 + 1) {
        KeStallExecutionProcessor(0x28);
        uVar8 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x40);
      }
    }
  }
  if ((param_2 & 2) != 0) {
    lVar3 = *(longlong *)(param_1 + 0x110);
    if (param_3 == '\0') {
      *(uint *)(lVar3 + 0x98) = *(uint *)(lVar3 + 0x98) | 0x100;
    }
    else {
      *(uint *)(lVar3 + 0x98) = *(uint *)(lVar3 + 0x98) | 0x500;
      uVar5 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x98);
      for (iVar7 = 0; (uVar5 = uVar5 >> 9 & 1, uVar5 == 0 && (iVar7 < 1000)); iVar7 = iVar7 + 1) {
        KeStallExecutionProcessor(0x28);
        uVar5 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x98);
      }
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar2 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar2 >> 0xb & 1) != 0 && (uVar4 == 0)) || (((uVar2 >> 0xc & 1) != 0 && (uVar4 == 1))))
       || ((((uVar2 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar2 >> 0xe & 1) != 0 && (uVar4 == 3)))
           ))) ||
      (((((uVar2 >> 0xf & 1) != 0 && (uVar4 == 4)) || (((uVar2 >> 0x10 & 1) != 0 && (uVar4 == 5))))
       || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_56a4a994cb7a38a3929f2c724df8ace9_Traceguids,uVar4);
  }
  if (((*(int *)(param_1 + 0x44) != 10) || (*(uint *)(param_1 + 0x48) < 0xf0)) &&
     ((uVar5 == 0 || (uVar8 == 0)))) {
    uVar6 = '\0';
  }
  return uVar6;
}



===== WPP_SF_dDDDDDDDD @ 14001cab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDDDDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                     undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
             &param_9,4,&param_10,4,&param_11,4,&param_12,4,0);
  return;
}



===== WPP_SF_dDDDDDDDDDDD @ 14001cb58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDDDDDDDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4
                        ,undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        ,undefined1 param_9,undefined1 param_10,undefined1 param_11,
                        undefined1 param_12,undefined1 param_13,undefined1 param_14,
                        undefined1 param_15)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
             &param_9,4,&param_10,4,&param_11,4,&param_12,4,&param_13,4,&param_14,4,&param_15,4,0);
  return;
}



===== WPP_SF_dPPPPPd @ 14001cc34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dPPPPPd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,8,&param_7,8,&param_8,8,
             &param_9,8,&param_10,4,0);
  return;
}



===== WPP_SF_dds @ 14001ccf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dds(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,char *param_6)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar1 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar1 = param_6;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,pcVar1,lVar3,0);
  return;
}



===== WPP_SF_ddsd @ 14001cd8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddsd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar1 = "NULL";
  if (param_6 != (char *)0x0) {
    pcVar1 = param_6;
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,pcVar1,lVar3,&param_7,4,0);
  return;
}



===== GetPciHardwareRevision @ 14001ce38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl GetPciHardwareRevision(struct PBC_DEVICE * __ptr64,unsigned long * __ptr64) */

long __cdecl GetPciHardwareRevision(PBC_DEVICE *param_1,ulong *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  byte local_res8 [8];
  undefined4 in_stack_ffffffffffffff78;
  undefined2 uVar6;
  undefined1 local_68 [8];
  undefined8 local_60;
  code *local_30;
  
  uVar6 = (undefined2)((uint)in_stack_ffffffffffffff78 >> 0x10);
  uVar4 = 0xf0;
  if (param_1 != (PBC_DEVICE *)0x0) {
    uVar4 = *(uint *)(param_1 + 0x40);
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (((((((uVar1 & 0x800) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))
        ) || ((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
              (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))))) || (5 < uVar4)))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_821e27ff03ab367c9010b36abcc1b347_Traceguids,uVar4);
  }
  local_res8[0] = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x418))
                    (WdfDriverGlobals,*(undefined8 *)param_1,&GUID_BUS_INTERFACE_STANDARD,local_68,
                     CONCAT22(uVar6,0x40),1,0);
  if ((iVar2 < 0) || (iVar3 = (*local_30)(local_60,0,local_res8,8,1), iVar3 != 1)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 & 0x40) != 0 &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])))) &&
       ((((((uVar1 & 0x800) != 0 && (uVar4 == 0)) ||
          (((((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)) ||
            (((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)))) ||
           (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)))))) ||
         (((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)))) ||
        ((((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)) || (5 < uVar4)))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_821e27ff03ab367c9010b36abcc1b347_Traceguids,uVar4,(char)iVar2);
    }
    lVar5 = -0x3fffffff;
    *param_2 = 0xff;
  }
  else {
    lVar5 = 0;
    *param_2 = (uint)local_res8[0];
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((((uVar1 & 0x40) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
       (((((uVar1 & 0x800) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
        ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) ||
         (((((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3)) || (((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)))
           ) || ((((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)) || (5 < uVar4)))))))))) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_821e27ff03ab367c9010b36abcc1b347_Traceguids,uVar4,local_res8[0]);
    }
  }
  if (((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar1 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar1 >> 10 & 1) != 0)) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     ((((((uVar1 & 0x800) != 0 && (uVar4 == 0)) || (((uVar1 >> 0xc & 1) != 0 && (uVar4 == 1)))) ||
       ((((uVar1 >> 0xd & 1) != 0 && (uVar4 == 2)) || (((uVar1 >> 0xe & 1) != 0 && (uVar4 == 3))))))
      || (((((uVar1 >> 0xf & 1) != 0 && (uVar4 == 4)) ||
           (((uVar1 >> 0x10 & 1) != 0 && (uVar4 == 5)))) || (5 < uVar4)))))) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_821e27ff03ab367c9010b36abcc1b347_Traceguids,uVar4);
  }
  return lVar5;
}



===== __security_check_cookie @ 14001d140 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 14001d160 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 14001d170 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 14001d180 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001d1a0 =====

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



===== _vsnwprintf @ 14001d200 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001d200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _vsnwprintf(_Dest,_Count,_Format,_Args);
  return iVar1;
}



===== wcsnlen @ 14001d206 =====

size_t __cdecl wcsnlen(wchar_t *_Src,size_t _MaxCount)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001d206. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = wcsnlen(_Src,_MaxCount);
  return sVar1;
}



===== wcsncmp @ 14001d20c =====

int __cdecl wcsncmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001d20c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcsncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== FxStubDriverUnloadCommon @ 14001d214 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  FxStubUnbindClasses((_WDF_BIND_INFO *)&WdfBindInfo);
  WdfVersionUnbind(&DAT_140022498,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 14001d250 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14001d27c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(longlong param_1,undefined8 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1400224a0 = &DAT_140022280;
    _DAT_140022498 = 0x2080000;
    _DAT_1400224b8 = param_1;
    RtlCopyUnicodeString(&DAT_140022498);
    iVar1 = WdfVersionBind(param_1,&DAT_140022498,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      _WdfDriverMiniportUnloadOverride = *(code **)(WdfFunctions_01015 + 0x648);
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)&WdfBindInfo);
      if (((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) &&
         (iVar1 = DriverEntry(param_1,param_2), -1 < iVar1)) {
        if (*(char *)(WdfDriverGlobals + 0x30) == '\0') {
          if ((*(uint *)(WdfDriverGlobals + 8) & 2) != 0) {
            _WdfDriverMiniportUnloadOverride = FxStubDriverMiniportUnload;
          }
        }
        else {
          if (*(longlong *)(param_1 + 0x68) != 0) {
            DAT_1400224c0 = *(longlong *)(param_1 + 0x68);
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



===== FxStubDriverMiniportUnload @ 14001d3b0 =====

void FxStubDriverMiniportUnload(void)

{
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubDriverUnload @ 14001d3c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1400224c0 != (code *)0x0) && (DAT_1400224c0 != FxStubDriverUnload)) {
    (*DAT_1400224c0)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubInitTypes @ 14001d3ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014001d409) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    if ((void **)0x1400221ef < ppvVar2) {
      return 0;
    }
    if (*(int *)ppvVar2 != 0x28) break;
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = ppvVar2 + 5;
  }
  return -0x3ffffffc;
}



===== FxStubBindClasses @ 14001d450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  void **ppvVar1;
  int iVar2;
  void **ppvVar3;
  bool bVar4;
  
  iVar2 = 0;
  bVar4 = true;
  ppvVar3 = (void **)&_SPBCx_BIND_INFO;
  while( true ) {
    if (!bVar4) {
      return iVar2;
    }
    if (&__KMDF_CLASS_BIND_END < (void **)((longlong)ppvVar3 + 4)) {
      return -0x3fffff85;
    }
    if (*(int *)ppvVar3 != 0x50) {
      return -0x3ffffffc;
    }
    ppvVar1 = ppvVar3 + 10;
    if (&__KMDF_CLASS_BIND_END < ppvVar1) break;
    PTR___KMDF_CLASS_BIND_START_1400221d8 = (undefined *)ppvVar3;
    if (ppvVar3[7] == (code *)0x0) {
      iVar2 = WdfVersionBindClass(param_1,WdfDriverGlobals);
    }
    else {
      iVar2 = (*ppvVar3[7])(WdfVersionBindClass,param_1,WdfDriverGlobals,ppvVar3);
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    bVar4 = ppvVar1 < &__KMDF_CLASS_BIND_END;
    ppvVar3 = ppvVar1;
  }
  return -0x3fffff85;
}



===== FxStubUnbindClasses @ 14001d500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = &_SPBCx_BIND_INFO;
  if (((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400221d8 != &__KMDF_CLASS_BIND_START) &&
     ((undefined *)0x14002217f < PTR___KMDF_CLASS_BIND_START_1400221d8)) {
    do {
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(param_1,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))(WdfVersionUnbindClass,param_1,WdfDriverGlobals,puVar1);
      }
      puVar1 = puVar1 + 0x14;
    } while (puVar1 <= PTR___KMDF_CLASS_BIND_START_1400221d8);
  }
  return;
}



===== WdfVersionBind @ 14001d57b =====

void WdfVersionBind(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001d57b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBind();
  return;
}



===== WdfVersionUnbind @ 14001d581 =====

void WdfVersionUnbind(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001d581. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbind();
  return;
}



===== WdfVersionBindClass @ 14001d590 =====

void WdfVersionBindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001d590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionBindClass();
  return;
}



===== WdfVersionUnbindClass @ 14001d5a0 =====

void WdfVersionUnbindClass(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001d5a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WdfVersionUnbindClass();
  return;
}



===== _guard_dispatch_icall @ 14001d5c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001d5c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 14001d600 =====

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
        if (uVar12 == 0) goto LAB_14001d7b7;
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
LAB_14001d7b7:
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
      if (uVar12 == 0) goto LAB_14001d612;
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
LAB_14001d612:
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



===== memset @ 14001d940 =====

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



===== WppCleanupKm @ 140024000 =====

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



===== WppInitKm @ 140024074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  undefined *puVar1;
  
  puVar1 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      do {
        *(undefined8 *)(puVar1 + 0x38) = 0;
        (*pfnEtwRegisterClassicProvider)
                  (*(undefined8 *)(puVar1 + 8),0,WppClassicProviderCallback,puVar1,puVar1 + 0x38);
        puVar1 = *(undefined **)(puVar1 + 0x10);
      } while (puVar1 != (undefined *)0x0);
      return;
    }
    if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
  }
  return;
}



===== WppLoadTracingSupport @ 1400240fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined1 local_18 [16];
  
  local_res8[0] = 0;
  RtlInitUnicodeString(local_18,L"PsGetVersion");
  pfnWppGetVersion = MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != 0) {
    (*(code *)pfnWppGetVersion)(local_res8,0,0,0);
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



===== WppTraceCallback @ 140024200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  ushort *puVar1;
  uint *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 local_res8 [8];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar2 = param_6;
  *param_6 = 0;
  if (3 < param_1) {
    if (param_1 < 6) {
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar2 = *(uint **)(param_5 + 8);
          if ((((*puVar2 == param_4[6]) && (puVar2[1] == param_4[7])) && (puVar2[2] == param_4[8]))
             && (puVar2[3] == param_4[9])) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined1 *)(param_5 + 0x29) = 0;
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            return 0;
          }
          uVar3 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar3;
          if (WPPTraceSuite != 2) {
            uStack_34 = (undefined4)((ulonglong)uVar3 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar3 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          iVar5 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = local_res8[0];
          }
          uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
    if (param_1 < 8) {
      return 0;
    }
    if (param_1 == 8) {
      uVar10 = 0;
      puVar1 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      uVar11 = uVar10 * 0x20 + 0x18;
      if (puVar1 == (ushort *)0x0) {
        uVar12 = uVar11;
        uVar11 = 0;
      }
      else {
        uVar12 = *puVar1 + 2 + uVar11;
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
      if (puVar1 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar1;
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar1 + 4),
                (ulonglong)*puVar1);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = param_4 + 10;
        do {
          uVar3 = **(undefined8 **)(param_5 + 8);
          uVar4 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar3;
          *(undefined8 *)(puVar9 + -2) = uVar4;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar2 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== __security_init_cookie @ 140025000 =====

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


